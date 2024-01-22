#include "global.h"
#include "constants/songs.h"
#include "constants/flags.h"
#include "constants/heal_locations.h"
#include "decompress.h"
#include "event_object_movement.h"
#include "event_data.h"
#include "field_effect.h"
#include "item_menu.h"
#include "load_save.h"
#include "main.h"
#include "menu.h"
#include "overworld.h"
#include "palette.h"
#include "region_map.h"
#include "constants/region_map_sections.h"
#include "constants/rgb.h"
#include "scanline_effect.h"
#include "script.h"
#include "script_menu.h"
#include "soar.h"
#include "sound.h"
#include "sprite.h"
#include "string_util.h"
#include "task.h"
#include "text_window.h"
#include "trig.h"
#include "window.h"

#define NOCASH_BREAKPOINT asm("mov r11, r11")

// VRAM memory layout
// Contains 256 8x8 tiles with 8-bit color (0x4000 bytes)
#define BG2_IMAGE_OFFSET 0
// 128x128 map with 1 byte per entry (0x4000 bytes)
#define BG2_TILEMAP_OFFSET 0xB000

// Not sure how much space this takes
#define BG0_IMAGE_OFFSET 0x4000
// 32x32 map with 2 bytes per entry (0x800 bytes)
#define BG0_TILEMAP_OFFSET 0xB800

static void CB2_LoadSoarGraphics(void);
static void DoSoarFieldEffectsCB2(void);
static void SoarVBlankCallback(void);
static void SoarHBlankCallback(void);
static void CB2_HandleInput(void);
static void PromptLandCB2(void);
static void ProcessYesNoCB2(void);
static void WarpCB2(void);
static void FadeOutVBlankCallback(void);
static void CB2_FadeOut(void);
static u8 windid;
static u8 windid2;

extern const u8 sMapHealLocations[][3];

static const struct WindowTemplate sPopupWindowTemplate =
{
	0, // BG number
	1, // tilemap left coordinate
	1, // tilemap top coordinate
	12, // width
	2, // height
	15, // palette number
	BG0_TILEMAP_OFFSET / 0x800, // BG screen base block
};

// For now, just use the region map graphics
static const u16 sRegionMapBg_Pal[] = INCBIN_U16("graphics/soar/region_map.gbapal");
static const u32 sRegionMapBg_GfxLZ[] = INCBIN_U32("graphics/soar/region_map.8bpp.lz");
static const u32 sRegionMapBg_TilemapLZ[] = INCBIN_U32("graphics/soar/region_map_map.bin.lz");

//
// Eon sprite data
//

#define GFX_TAG_EON 9999

static const u32 sEonBrendanSpriteTiles[] = INCBIN_U32("graphics/soar/latias_brendan.4bpp.lz");
static const u32 sEonBrendanSpritePaletteData[] = INCBIN_U32("graphics/soar/latias_brendan.gbapal.lz");
static const u32 sEonMaySpriteTiles[] = INCBIN_U32("graphics/soar/latias_may.4bpp.lz");
static const u32 sEonMaySpritePaletteData[] = INCBIN_U32("graphics/soar/latias_may.gbapal.lz");

static const u32 sEonBrendanSpriteTiles2[] = INCBIN_U32("graphics/soar/latios_brendan.4bpp.lz");
static const u32 sEonBrendanSpritePaletteData2[] = INCBIN_U32("graphics/soar/latios_brendan.gbapal.lz");
static const u32 sEonMaySpriteTiles2[] = INCBIN_U32("graphics/soar/latios_may.4bpp.lz");
static const u32 sEonMaySpritePaletteData2[] = INCBIN_U32("graphics/soar/latios_may.gbapal.lz");

static const struct OamData sEonSpriteOamData =
{
	.y = 0,
	.affineMode = 3,
	.objMode = 0,
	.mosaic = 0,
	.bpp = 0,
	.shape = 1,
	.x = 0,
	.matrixNum = 0,
	.size = 3,
	.tileNum = 0,
	.priority = 0,
	.paletteNum = 0,
	.affineParam = 0,
};

static const struct SpriteTemplate sEonSpriteTemplate =
{
	.tileTag = GFX_TAG_EON,
	.paletteTag = GFX_TAG_EON,
	.oam = &sEonSpriteOamData,
	.anims = gDummySpriteAnimTable,
	.images = NULL,
	.affineAnims = NULL,
	.callback = SpriteCallbackDummy,
};

//
// Shadow sprite data
//

#define GFX_TAG_SHADOW 9998

static const u32 sShadowSpriteTiles[] = INCBIN_U32("graphics/soar/shadow.4bpp.lz");
static const struct CompressedSpriteSheet sShadowSpriteSheet = {
	.data = sShadowSpriteTiles,
	.size = 1024,
	.tag = GFX_TAG_SHADOW
};

static const struct OamData sShadowSpriteOamData =
{
	.y = 0,
	.affineMode = 0,
	.objMode = 2,
	.mosaic = 0,
	.bpp = 0,
	.shape = 1,
	.x = 0,
	.matrixNum = 0,
	.size = 3,
	.tileNum = 16,
	.priority = 0,
	.paletteNum = 0,
	.affineParam = 0,
};

static const struct SpriteTemplate sShadowSpriteTemplate =
{
	.tileTag = GFX_TAG_SHADOW,
	.paletteTag = GFX_TAG_SHADOW,
	.oam = &sShadowSpriteOamData,
	.anims = gDummySpriteAnimTable,
	.images = NULL,
	.affineAnims = NULL,
	.callback = SpriteCallbackDummy,
};

static const struct { u8 left; u8 top; u8 right; u8 bottom; } sPopupWindowRect = { 0, 0, 15, 3 };

static s32 sPlayerPosX;
static s32 sPlayerPosY;
static s32 sPlayerPosZ;
static u8 sPlayerYaw;
static u8 sPlayerPitch;
static u16 sPrevMapSection;

static u8 sEonSpriteId;
static u8 sShadowSpriteId;

#define Q_8_7(iPart, fPart) (((iPart) << 8) | (fPart))
#define IPART(n) ((n) >> 8)
#define FPART(n) ((n) & 0xFFFF)

static const u8 sEonFluteUseMessage[] = _("{PLAYER} used the EON FLUTE.{PAUSE_UNTIL_PRESS}");

void CB2_InitSoar(void)
{
	switch (gMain.state)
	{
	case 0:
		StringExpandPlaceholders(gStringVar4, sEonFluteUseMessage);

		DrawDialogueFrame(0, 0);
		AddTextPrinterParameterized(0, 1, gStringVar4, 0, 0, GetPlayerTextSpeed(), NULL);
		CopyWindowToVram(0, 3);

		gMain.state++;
		break;
	case 1:
		if (RunTextPrintersAndIsPrinter0Active() != 1)
		{
			BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 16, 0);
			gMain.state++;
		}
		break;
	case 2:
		if (!UpdatePaletteFade())
		{
			u16 cursorX, cursorY;
			bool8 inCave;
			ClearDialogWindowAndFrame(0, 1);
			RegionMap_GetSectionCoordsFromCurrFieldPos(&sPrevMapSection, &cursorX, &cursorY, &inCave);
			sPrevMapSection = 0xD5;

			sPlayerPosX = Q_8_7(cursorX * 8, 0);
			sPlayerPosY = Q_8_7(cursorY * 8, 0);
			sPlayerPosZ = Q_8_7(8, 0);
			sPlayerYaw = 0;
			sPlayerPitch = 0;

			// some of these may not be necessary, but I'm just being safe
			ScanlineEffect_Stop();
			ResetTasks();
			ResetSpriteData();
			ResetPaletteFade();
			FreeAllSpritePalettes();

			SetMainCallback2(CB2_LoadSoarGraphics);
		}
		break;
	}
}

void ItemUseOnFieldCB_EonFlute(u8 taskId)
{
	ScriptContext2_Enable();
	FreezeObjectEvents();
	SetMainCallback2(CB2_InitSoar);
}

static void LoadEonGraphics(void)
{
	struct CompressedSpriteSheet sEonSpriteSheet = { .size = 1024,.tag = GFX_TAG_EON };
	struct CompressedSpritePalette sEonSpritePalette = { .tag = GFX_TAG_EON };

	if (FlagGet(FLAG_EON_LATI)) {
		sEonSpriteSheet.data = sEonBrendanSpriteTiles;
		sEonSpritePalette.data = sEonBrendanSpritePaletteData;

		if (gSaveBlock2Ptr->playerGender != MALE)
		{
			sEonSpriteSheet.data = sEonMaySpriteTiles;
			sEonSpritePalette.data = sEonMaySpritePaletteData;
		}
	}
	else {
		sEonSpriteSheet.data = sEonBrendanSpriteTiles2;
		sEonSpritePalette.data = sEonBrendanSpritePaletteData2;

		if (gSaveBlock2Ptr->playerGender != MALE)
		{
			sEonSpriteSheet.data = sEonMaySpriteTiles2;
			sEonSpritePalette.data = sEonMaySpritePaletteData2;
		}
	}

	LoadCompressedSpriteSheet(&sEonSpriteSheet);
	LoadCompressedSpritePalette(&sEonSpritePalette);
	sEonSpriteId = CreateSprite(&sEonSpriteTemplate, DISPLAY_WIDTH / 2, DISPLAY_HEIGHT / 2, 0);
	gSprites[sEonSpriteId].data[0] = 0;
	gSprites[sEonSpriteId].data[1] = 0;
	gSprites[sEonSpriteId].data[2] = 0;
}

static void CB2_LoadSoarGraphics(void)
{
	unsigned int i;
	u8 *src;
	u8 *dest;

	switch (gMain.state)
	{
	case 0:
		REG_DISPCNT = 0;

		DmaClearLarge32(3, (void *)(VRAM), VRAM_SIZE, 0x1000);

		SetVBlankCallback(SoarVBlankCallback);
		SetHBlankCallback(SoarHBlankCallback);

		// Load image data
		LZ77UnCompVram(sRegionMapBg_GfxLZ, (void *)(VRAM + BG2_IMAGE_OFFSET));

		// Load tilemap
		LZ77UnCompVram(sRegionMapBg_TilemapLZ, gDecompressionBuffer);
		src = gDecompressionBuffer;
		dest = (void *)(VRAM + BG2_TILEMAP_OFFSET);
		// Copy each row to VRAM
		for (i = 0; i < 64; i++)
		{
			DmaCopy32(3, src, dest, 64);
			src += 64;
			dest += 128;
		}

		// load palette
		LoadPalette(sRegionMapBg_Pal, 0x70, 64);

		// Create sprites
		LoadEonGraphics();
		gPlttBufferUnfaded[0] = RGB(8, 8, 20);

		gMain.state++;
		break;
	case 1:
		LoadUserWindowBorderGfx(0, 1, 14);
		LoadPalette(GetWindowFrameTilesPal(gSaveBlock2Ptr->optionsWindowFrameType)->pal, 0xE0, 0x20);
		windid = InitWindows(&sPopupWindowTemplate);
		LoadMessageBoxGfx(0, 10, 15);
		windid2 = CreateWindowFromRect(1, 14, 27, 4);

		gMain.state++;
		break;
	case 2:
		// Enable hblank and vblank interrupts
		REG_IME = 0;
		REG_IE |= INTR_FLAG_VBLANK | INTR_FLAG_HBLANK;
		REG_IME = 1;
		REG_DISPSTAT |= DISPSTAT_VBLANK_INTR | DISPSTAT_HBLANK_INTR;

		// Set up video regs
		REG_DISPCNT = DISPCNT_MODE_1 | DISPCNT_BG2_ON | DISPCNT_OBJ_ON | DISPCNT_OBJ_1D_MAP;
		REG_BG2CNT = BGCNT_PRIORITY(0)
			| BGCNT_256COLOR
			| BGCNT_CHARBASE(BG2_IMAGE_OFFSET / 0x4000)
			| BGCNT_SCREENBASE(BG2_TILEMAP_OFFSET / 0x800)
			| BGCNT_AFF1024x1024
			| BGCNT_WRAP;

		// Start palette fade
		BeginNormalPaletteFade(0xFFFFFFFF, 0, 16, 0, 0);
		gMain.state++;
		break;
	case 3:
		// Wait for fade to finish palette fade
		if (!gPaletteFade.active)
		{
			SetMainCallback2(CB2_HandleInput);
		}
		break;
	}
	BuildOamBuffer();
}

static void SoarVBlankCallback(void)
{
	LoadOam();
	UpdatePaletteFade();

	REG_BG2X = 0;
	REG_BG2Y = 0;
	REG_BG2PA = 0;
	REG_BG2PB = 0;
	REG_BG2PC = 0;
	REG_BG2PD = 0;

	// Turn off BG for first scanline
	REG_DISPCNT &= ~DISPCNT_BG2_ON;

	TransferPlttBuffer();
}

#define M7_D 128

static void SoarHBlankCallback(void)
{
	const unsigned int bldcntFog = BLDCNT_EFFECT_LIGHTEN | BLDCNT_TGT1_BD | BLDCNT_TGT1_BG2;
	const unsigned int bldcntShadow = BLDCNT_EFFECT_DARKEN | BLDCNT_TGT1_BG2;
	int sinYaw = gSineTable[sPlayerYaw];
	int cosYaw = gSineTable[sPlayerYaw + 64];

	int lam, lcf, lsf, lxr, lyr;
	u32 currScanline = REG_VCOUNT - 1;

	if (currScanline > 159)  // We're in vblank. Nothing to do.
		return;
	if (currScanline < 32)  // draw gradient for sky
	{
		REG_DISPCNT &= ~DISPCNT_BG2_ON;
		REG_BLDCNT = bldcntFog;
		REG_BLDY = currScanline / 2;
		return;
	}

	if (currScanline == 32)
		REG_DISPCNT |= DISPCNT_BG2_ON;

	if (currScanline <= 16 * 6)
	{
		REG_BLDCNT = bldcntFog;
		REG_BLDY = 16 - (currScanline / 6);
	}
	else
	{
		REG_BLDCNT = 0;
	}

	lam = sPlayerPosZ * ((1 << 16) / (currScanline - 32)) >> 12;  // .8*.16 /.12 = 20.12
	lcf = lam * cosYaw >> 8;                     // .12*.8 /.8 = .12
	lsf = lam * sinYaw >> 8;                     // .12*.8 /.8 = .12

	REG_BG2PA = lcf >> 4;
	REG_BG2PC = lsf >> 4;

	// Offsets
	// Note that the lxr shifts down first! 

	// horizontal offset
	lxr = 120 * (lcf >> 4);
	lyr = (M7_D*lsf) >> 4;
	REG_BG2X = sPlayerPosX - lxr + lyr;

	// vertical offset
	lxr = 120 * (lsf >> 4);
	lyr = (M7_D*lcf) >> 4;
	REG_BG2Y = sPlayerPosY - lxr - lyr;
}

#define spTiltAngle data[0]
#define spBarrelRollDir data[1]
#define spDestAngle data[2]
#define spFlipped data[3]

#define TILT_MAX 0x1000
#define TILT_MIN -0x1000
#define TILT_STEP 0x100
#define ROLL_TILT_STEP (TILT_STEP * 8)

static void UpdateEonSpriteRotation(struct Sprite *sprite)
{
	switch (sprite->spBarrelRollDir)
	{
	case 0:  // no barrel roll
		if (sprite->spTiltAngle < sprite->spDestAngle)
			sprite->spTiltAngle += TILT_STEP;
		else if (sprite->spTiltAngle > sprite->spDestAngle)
			sprite->spTiltAngle -= TILT_STEP;
		break;
	case 1:  // increase angle
		if (sprite->spTiltAngle < TILT_MIN)  // rotation is past 180 degrees
		{
			sprite->spTiltAngle += ROLL_TILT_STEP;
			if (sprite->spTiltAngle >= TILT_MIN)
				sprite->spBarrelRollDir = 0;
			break;
		}
		sprite->spTiltAngle += ROLL_TILT_STEP;
		break;
	case -1:  // decrease angle
		if (sprite->spTiltAngle > TILT_MAX)  // rotation is past 180 degrees
		{
			sprite->spTiltAngle -= ROLL_TILT_STEP;
			if (sprite->spTiltAngle <= TILT_MAX)
				sprite->spBarrelRollDir = 0;
			break;
		}
		sprite->spTiltAngle -= ROLL_TILT_STEP;
		break;
	}

	SetOamMatrixRotationScaling(sprite->oam.matrixNum, 1 << 8, 1 << 8, -sprite->spTiltAngle);
}

static void StartBarrelRoll(void)
{
	struct Sprite *sprite = &gSprites[sEonSpriteId];

	if (sprite->spBarrelRollDir == 0)
	{
		sprite->spFlipped = 0;
		if (sprite->spDestAngle >= 0)
			sprite->spBarrelRollDir = 1;
		else
			sprite->spBarrelRollDir = -1;
	}
}

static void UpdateMapSectionPopup(void)
{
	unsigned int mapSection = GetRegionMapSecIdAt(IPART(sPlayerPosX) / 8, IPART(sPlayerPosY) / 8);

	if (mapSection != sPrevMapSection)
	{
		if (mapSection == MAPSEC_NONE)
		{
			REG_DISPCNT &= ~DISPCNT_BG0_ON;
		}
		else
		{
			GetMapName(gStringVar4, mapSection, 50);
			DrawStdFrameWithCustomTileAndPalette(windid, 0, 1, 14);
			AddTextPrinterParameterized(windid, 1, gStringVar4, 4, 0, TEXT_SPEED_FF, NULL);

			CopyWindowToVram(windid, 3);
			REG_DISPCNT |= DISPCNT_BG0_ON;
		}
		sPrevMapSection = mapSection;
	}
}

static const u8 sText_LandHere[] = _("Would you like to land here?");

static void ExitSoar(void)
{
	PlaySE(SE_PC_OFF);
	BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 16, 0);
	SetMainCallback2(CB2_FadeOut);
}

// movement limits
#define MIN_Z Q_8_7(4, 0)
#define MAX_Z Q_8_7(50, 0)
#define MIN_X Q_8_7(0, 0)
#define MAX_X Q_8_7(30*8, 0)
#define MIN_Y Q_8_7(0, 0)
#define MAX_Y Q_8_7(20*8, 0)

static void CB2_HandleInput(void)
{
	int sinYaw;
	int cosYaw;

	if ((gMain.newKeys & A_BUTTON) && sPrevMapSection != MAPSEC_NONE && sPrevMapSection != MAPSEC_ROUTE_126 && sPrevMapSection != MAPSEC_ROUTE_128 && sPrevMapSection != MAPSEC_ROUTE_129 && sPrevMapSection != MAPSEC_ROUTE_130 && sPrevMapSection != MAPSEC_ROUTE_131 && (GetMapsecType(sPrevMapSection) == MAPSECTYPE_CITY_CANFLY || GetMapsecType(sPrevMapSection) == MAPSECTYPE_BATTLE_FRONTIER))
	{
		PlaySE(SE_SELECT);

		DrawDialogFrameWithCustomTileAndPalette(windid2, 0, 10, 15);
		AddTextPrinterParameterized(windid2, 1, sText_LandHere, 0, 0, TEXT_SPEED_FF, NULL);
		CopyWindowToVram(windid2, 3);

		SetMainCallback2(PromptLandCB2);
		return;
	}

	if (gMain.newKeys & START_BUTTON)
	{
		ExitSoar();
		return;
	}

	if (gMain.newKeys & R_BUTTON)
		StartBarrelRoll();

	gSprites[sEonSpriteId].spDestAngle = 0;

	if (gMain.heldKeys & DPAD_LEFT)
	{
		sPlayerYaw--;
		gSprites[sEonSpriteId].spDestAngle = TILT_MIN;
	}
	if (gMain.heldKeys & DPAD_RIGHT)
	{
		sPlayerYaw++;
		gSprites[sEonSpriteId].spDestAngle = TILT_MAX;
	}
	if (gMain.heldKeys & DPAD_UP)
	{
		sPlayerPosZ += 0x10;
		if (sPlayerPosZ > MAX_Z)
			sPlayerPosZ = MAX_Z;
	}
	if (gMain.heldKeys & DPAD_DOWN)
	{
		sPlayerPosZ -= 0x10;
		if (sPlayerPosZ < MIN_Z)
			sPlayerPosZ = MIN_Z;
	}

	UpdateEonSpriteRotation(&gSprites[sEonSpriteId]);

	sinYaw = gSineTable[sPlayerYaw];
	cosYaw = gSineTable[sPlayerYaw + 64];

	sPlayerPosX += sinYaw / 8;
	sPlayerPosY -= cosYaw / 8;

	if (gMain.heldKeys & L_BUTTON)
	{
		sPlayerPosX += sinYaw / 8;
		sPlayerPosY -= cosYaw / 8;
	}

	if (sPlayerPosX < MIN_X)
		sPlayerPosX = MIN_X;
	else if (sPlayerPosX > MAX_X)
		sPlayerPosX = MAX_X;

	if (sPlayerPosY < MIN_Y)
		sPlayerPosY = MIN_Y;
	else if (sPlayerPosY > MAX_Y)
		sPlayerPosY = MAX_Y;

	UpdateMapSectionPopup();

	BuildOamBuffer();
}

static const struct WindowTemplate sYesNo_WindowTemplates =
{
	.bg = 0,
	.tilemapLeft = 21,
	.tilemapTop = 9,
	.width = 5,
	.height = 4,
	.paletteNum = 15,
	.baseBlock = 0x125
};

static void PromptLandCB2(void)
{
	if (!IsTextPrinterActive(0))
	{
		CreateYesNoMenu(&sYesNo_WindowTemplates, 1, 14, 0);
		SetMainCallback2(ProcessYesNoCB2);
	}
	UpdateEonSpriteRotation(&gSprites[sEonSpriteId]);
	BuildOamBuffer();
}

static void ProcessYesNoCB2(void)
{
	switch (Menu_ProcessInputNoWrapClearOnChoose())
	{
	case 0:
		BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 16, 0);
		ClearDialogWindowAndFrame(windid2, 1);
		SetMainCallback2(WarpCB2);
		break;
	case -1:
	case 1:
		ClearDialogWindowAndFrame(windid2, 1);
		SetMainCallback2(CB2_HandleInput);
		break;
	}
	BuildOamBuffer();
}

static void WarpCB2(void)
{
	switch (sPrevMapSection) {
	case MAPSEC_SOUTHERN_ISLAND:
		SetWarpDestinationToHealLocation(HEAL_LOCATION_SOUTHERN_ISLAND_EXTERIOR);
		break;
	case MAPSEC_BATTLE_FRONTIER:
		SetWarpDestinationToHealLocation(HEAL_LOCATION_BATTLE_FRONTIER_OUTSIDE_EAST);
		break;
	case MAPSEC_LITTLEROOT_TOWN:
		SetWarpDestinationToHealLocation(gSaveBlock2Ptr->playerGender == MALE ? HEAL_LOCATION_LITTLEROOT_TOWN_BRENDANS_HOUSE : HEAL_LOCATION_LITTLEROOT_TOWN_MAYS_HOUSE);
		break;
	case MAPSEC_EVER_GRANDE_CITY:
		SetWarpDestinationToHealLocation(FlagGet(FLAG_LANDMARK_POKEMON_LEAGUE) && (IPART(sPlayerPosY) / 8) == 10 ? HEAL_LOCATION_EVER_GRANDE_CITY_POKEMON_LEAGUE : HEAL_LOCATION_EVER_GRANDE_CITY);
		break;
	case MAPSEC_MT_CHIMNEY:
		SetWarpDestinationToHealLocation(HEAL_LOCATION_MT_CHIMNEY);
		break;
	default:
		SetWarpDestinationToHealLocation(sMapHealLocations[sPrevMapSection][2]);

	}

	if (!gPaletteFade.active)
	{
		Fldeff_FlyLand();
	}
}

static void CB2_FadeOut(void)
{
	if (!gPaletteFade.active)
	{
		REG_IME = 0;
		REG_IE &= ~(INTR_FLAG_HBLANK);
		REG_IME = 1;
		REG_DISPSTAT &= ~(DISPSTAT_HBLANK_INTR);

		SetHBlankCallback(NULL);
		SetMainCallback2(CB2_ReturnToUIMenu); //CB2_ReturnToFieldWithOpenMenu
	}
}