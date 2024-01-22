#include "global.h"
#include "bg.h"
#include "gpu_regs.h"
#include "palette.h"
#include "decompress.h"
#include "malloc.h"
#include "menu.h"
#include "pokemon_icon.h"
#include "union_room.h"
#include "list_menu.h"
#include "text_window.h"
#include "string_util.h"
#include "link_rfu.h"
#include "mevent.h"
#include "sound.h"
#include "mystery_gift.h"
#include "constants/rgb.h"

struct WonderGraphics
{
    u8 titleTextPal:4;
    u8 bodyTextPal:4;
    u8 footerTextPal:4; // Card only
    u8 stampShadowPal:4; // Card only
    const u32 * tiles;
    const u32 * map;
    const u16 * pal;
};

//======================
//    Wonder Cards
//======================

enum {
    CARD_WIN_HEADER,
    CARD_WIN_BODY,
    CARD_WIN_FOOTER,
    CARD_WIN_COUNT
};

struct CardStatTextData
{
    u8 width;
    u8 statText[WONDER_CARD_TEXT_LENGTH + 1];
    u8 statNumberText[4];
};

struct WonderCardData
{
    /*0000*/ struct WonderCard card;
    /*014c*/ struct WonderCardMetadata cardMetadata;
    /*0170*/ const struct WonderGraphics * gfx;
    /*0174*/ u8 enterExitState;
    /*0175*/ u8 statFooterWidth;
    /*0176*/ u16 windowIds[CARD_WIN_COUNT];
    /*017C*/ u8 monIconSpriteId;
    /*017D*/ u8 stampSpriteIds[MAX_STAMP_CARD_STAMPS][2]; // 2 sprites each, 1 for the shadow and 1 for the Pokémon
    /*018B*/ u8 titleText[WONDER_CARD_TEXT_LENGTH + 1];
    /*01B4*/ u8 subtitleText[WONDER_CARD_TEXT_LENGTH + 1];
    /*01DD*/ u8 idNumberText[7];
    /*01E4*/ u8 bodyText[WONDER_CARD_BODY_TEXT_LINES][WONDER_CARD_TEXT_LENGTH + 1];
    /*0288*/ u8 footerLine1Text[WONDER_CARD_TEXT_LENGTH + 1];
    /*02B1*/ u8 giftText[WONDER_CARD_TEXT_LENGTH + 1];
   /*02DC*/ struct CardStatTextData statTextData[8];
    /*045C*/ u8 bgTilemapBuffer[0x1000];
};

EWRAM_DATA static struct WonderCardData * sWonderCardData = NULL;

void BufferCardText(void);
void DrawCardWindow(u8 whichWindow);
void CreateCardSprites(void);
void DestroyCardSprites(void);

extern const struct OamData gOamData_AffineOff_ObjNormal_32x16;

const u8 sCard_TextColorTable[][3] = {
    {TEXT_COLOR_TRANSPARENT, TEXT_COLOR_DARK_GREY, TEXT_COLOR_LIGHT_GREY},
    {TEXT_COLOR_TRANSPARENT, TEXT_COLOR_WHITE, TEXT_COLOR_DARK_GREY}
};

static const u8 ALIGNED(4) sCard_FooterTextOffsets[CARD_TYPE_COUNT] =
{
    [CARD_TYPE_GIFT] = 7,
    [CARD_TYPE_STAMP] = 4,
    [CARD_TYPE_LINK_STAT] = 7
};

static const struct WindowTemplate sCard_WindowTemplates[] = {
    [CARD_WIN_HEADER] = {
        .bg = 1,
        .tilemapLeft = 1,
        .tilemapTop = 1,
        .width = 25,
        .height = 4,
        .paletteNum = 2,
        .baseBlock = 0x029c
    },
    [CARD_WIN_BODY] = {
        .bg = 1,
        .tilemapLeft = 1,
        .tilemapTop = 6,
        .width = 28,
        .height = 8,
        .paletteNum = 2,
        .baseBlock = 0x01bc
    },
    [CARD_WIN_FOOTER] = {
        .bg = 1,
        .tilemapLeft = 1,
        .tilemapTop = 14,
        .width = 28,
        .height = 5,
        .paletteNum = 2,
        .baseBlock = 0x0130
    }
};

const u16 gWonderCardBgPal1[] = INCBIN_U16("graphics/wonder_transfers/wonder_card_1.gbapal");
const u16 gWonderCardBgPal2[] = INCBIN_U16("graphics/wonder_transfers/wonder_card_2.gbapal");
const u16 gWonderCardBgPal3[] = INCBIN_U16("graphics/wonder_transfers/wonder_card_3.gbapal");
const u16 gWonderCardBgPal4[] = INCBIN_U16("graphics/wonder_transfers/wonder_card_4.gbapal");
const u16 gWonderCardBgPal5[] = INCBIN_U16("graphics/wonder_transfers/wonder_card_5.gbapal");
const u16 gWonderCardBgPal6[] = INCBIN_U16("graphics/wonder_transfers/wonder_card_6.gbapal");
const u16 gWonderCardBgPal7[] = INCBIN_U16("graphics/wonder_transfers/wonder_card_7.gbapal");
const u16 gWonderCardBgPal8[] = INCBIN_U16("graphics/wonder_transfers/wonder_card_8.gbapal");
const u32 gWonderCardBgGfx1[] = INCBIN_U32("graphics/wonder_transfers/wonder_card_1.4bpp.lz");
const u32 gWonderCardBgTilemap1[] = INCBIN_U32("graphics/wonder_transfers/wonder_card_1.bin.lz");
const u32 gWonderCardBgGfx2[] = INCBIN_U32("graphics/wonder_transfers/wonder_card_2.4bpp.lz");
const u32 gWonderCardBgTilemap2[] = INCBIN_U32("graphics/wonder_transfers/wonder_card_2.bin.lz");
const u32 gWonderCardBgGfx3[] = INCBIN_U32("graphics/wonder_transfers/wonder_card_3.4bpp.lz");
const u32 gWonderCardBgTilemap3[] = INCBIN_U32("graphics/wonder_transfers/wonder_card_3.bin.lz");
const u32 gWonderCardBgGfx7[] = INCBIN_U32("graphics/wonder_transfers/wonder_card_7.4bpp.lz");
const u32 gWonderCardBgTilemap7[] = INCBIN_U32("graphics/wonder_transfers/wonder_card_7.bin.lz");
const u32 gWonderCardBgGfx8[] = INCBIN_U32("graphics/wonder_transfers/wonder_card_8.4bpp.lz");
const u32 gWonderCardBgTilemap8[] = INCBIN_U32("graphics/wonder_transfers/wonder_card_8.bin.lz");
const u16 gWonderCardShadowPal1[] = INCBIN_U16("graphics/wonder_transfers/wonder_card_shadow_1.gbapal");
const u16 gWonderCardShadowPal2[] = INCBIN_U16("graphics/wonder_transfers/wonder_card_shadow_2.gbapal");
const u16 gWonderCardShadowPal3[] = INCBIN_U16("graphics/wonder_transfers/wonder_card_shadow_3.gbapal");
const u16 gWonderCardShadowPal4[] = INCBIN_U16("graphics/wonder_transfers/wonder_card_shadow_4.gbapal");
const u16 gWonderCardShadowPal5[] = INCBIN_U16("graphics/wonder_transfers/wonder_card_shadow_5.gbapal");
const u16 gWonderCardShadowPal6[] = INCBIN_U16("graphics/wonder_transfers/wonder_card_shadow_6.gbapal");
const u16 gWonderCardShadowPal7[] = INCBIN_U16("graphics/wonder_transfers/wonder_card_shadow_7.gbapal");
const u16 gWonderCardShadowPal8[] = INCBIN_U16("graphics/wonder_transfers/wonder_card_shadow_8.gbapal");
const u32 gWonderCardShadowGfx[] = INCBIN_U32("graphics/wonder_transfers/wonder_card_shadow.4bpp.lz");

const struct CompressedSpriteSheet sSpriteSheet_StampShadow = {
    gWonderCardShadowGfx, 0x100, 0x8000
};
const struct SpritePalette sSpritePalettes_StampShadow[] = {
    {gWonderCardShadowPal1, 0x8000},
    {gWonderCardShadowPal2, 0x8000},
    {gWonderCardShadowPal3, 0x8000},
    {gWonderCardShadowPal4, 0x8000},
    {gWonderCardShadowPal5, 0x8000},
    {gWonderCardShadowPal6, 0x8000},
    {gWonderCardShadowPal7, 0x8000},
    {gWonderCardShadowPal8, 0x8000}
};
const struct SpriteTemplate sSpriteTemplate_StampShadow = {
    0x8000, 0x8000, &gOamData_AffineOff_ObjNormal_32x16, gDummySpriteAnimTable, NULL, gDummySpriteAffineAnimTable, SpriteCallbackDummy
};
const struct WonderGraphics sCardGraphics[NUM_WONDER_BGS] = {
    {1, 0, 0, 0, gWonderCardBgGfx1, gWonderCardBgTilemap1, gWonderCardBgPal1},
    {1, 0, 0, 1, gWonderCardBgGfx2, gWonderCardBgTilemap2, gWonderCardBgPal2},
    {1, 0, 0, 2, gWonderCardBgGfx3, gWonderCardBgTilemap3, gWonderCardBgPal3},
    {1, 0, 0, 3, gWonderCardBgGfx3, gWonderCardBgTilemap3, gWonderCardBgPal4},
    {1, 0, 0, 4, gWonderCardBgGfx3, gWonderCardBgTilemap3, gWonderCardBgPal5},
    {1, 0, 0, 5, gWonderCardBgGfx3, gWonderCardBgTilemap3, gWonderCardBgPal6},
    {1, 0, 0, 6, gWonderCardBgGfx7, gWonderCardBgTilemap7, gWonderCardBgPal7},
    {1, 0, 0, 7, gWonderCardBgGfx8, gWonderCardBgTilemap8, gWonderCardBgPal8}
};

//     WonderCard_Init(struct WonderCard * card, struct WonderCardMetadata * metadata)
bool32 InitWonderCardResources(struct WonderCard * card, struct WonderCardMetadata * metadata)
{
    //if (card == NULL || metadata == NULL)
    //    return FALSE;
    sWonderCardData = AllocZeroed(sizeof(*sWonderCardData));
    //if (sWonderCardData == NULL)
    //    return FALSE;
    sWonderCardData->card = *card;
    sWonderCardData->cardMetadata = *metadata;
    if (sWonderCardData->card.bgType >= NUM_WONDER_BGS)
        sWonderCardData->card.bgType = 0;
    if (sWonderCardData->card.type >= CARD_TYPE_COUNT)
        sWonderCardData->card.type = 0;
    if (sWonderCardData->card.maxStamps > MAX_STAMP_CARD_STAMPS)
        sWonderCardData->card.maxStamps = 0;
    sWonderCardData->gfx = &sCardGraphics[sWonderCardData->card.bgType];
    return TRUE;
}

void DestroyWonderCardResources(void)
{
    if (sWonderCardData != NULL)
    {
        *sWonderCardData = (struct WonderCardData){};
        Free(sWonderCardData);
        sWonderCardData = NULL;
    }
}

s32 FadeToWonderCardMenu(void)
{
    //if (sWonderCardData == NULL)
    //    return -1;
    switch(sWonderCardData->enterExitState)
    {
        case 0:
            BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 16, RGB_BLACK);
            break;
        case 1:
            if (UpdatePaletteFade())
                return 0;
            break;
        case 2:
            FillBgTilemapBufferRect_Palette0(0, 0x000, 0, 0, 30, 20);
            FillBgTilemapBufferRect_Palette0(1, 0x000, 0, 0, 30, 20);
            FillBgTilemapBufferRect_Palette0(2, 0x000, 0, 0, 30, 20);
            CopyBgTilemapBufferToVram(0);
            CopyBgTilemapBufferToVram(1);
            CopyBgTilemapBufferToVram(2);
            DecompressAndCopyTileDataToVram(2, sWonderCardData->gfx->tiles, 0, 0x008, 0);
			sWonderCardData->windowIds[CARD_WIN_HEADER] = AddWindow(&sCard_WindowTemplates[CARD_WIN_HEADER]);
			sWonderCardData->windowIds[CARD_WIN_BODY] = AddWindow(&sCard_WindowTemplates[CARD_WIN_BODY]);
			sWonderCardData->windowIds[CARD_WIN_FOOTER] = AddWindow(&sCard_WindowTemplates[CARD_WIN_FOOTER]);
            break;
        case 3:
            if (FreeTempTileDataBuffersIfPossible())
                return 0;
            LoadPalette(GetTextWindowPalette(1), 0x20, 0x20);
            gPaletteFade.bufferTransferDisabled = TRUE;
            LoadPalette(sWonderCardData->gfx->pal, 0x10, 0x20);
			LZ77UnCompWram(sWonderCardData->gfx->map, sWonderCardData->bgTilemapBuffer);
            CopyRectToBgTilemapBufferRect(2, sWonderCardData->bgTilemapBuffer, 0, 0, 30, 20, 0, 0, 30, 20, 1, 0x008, 0);
			CopyBgTilemapBufferToVram(2);
            break;
        case 4:
            BufferCardText();	//BufferCardText();
            break;
        case 5:
            DrawCardWindow(0);
            DrawCardWindow(1);
            DrawCardWindow(2);
            CopyBgTilemapBufferToVram(1);
            break;
        case 6:
            LoadMonIconPalettes();
            break;
        case 7:
            ShowBg(1);
            ShowBg(2);
            gPaletteFade.bufferTransferDisabled = FALSE;
            CreateCardSprites();
            BeginNormalPaletteFade(0xFFFFFFFF, 0, 16, 0, RGB_BLACK);
            UpdatePaletteFade();
            break;
        default:
            if (UpdatePaletteFade())
                return 0;
            sWonderCardData->enterExitState = 0;
			return 1;
    }
    sWonderCardData->enterExitState++;
    return 0;
}

s32 FadeOutFromWonderCard(bool32 flag)
{
    if (sWonderCardData == NULL)
        return -1;
    switch (sWonderCardData->enterExitState)
    {
        case 0:
            BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 16, RGB_BLACK);
            break;
        case 1:
            if (UpdatePaletteFade())
                return 0;
            break;
        case 2:
            FillBgTilemapBufferRect_Palette0(0, 0x000, 0, 0, 30, 20);
            FillBgTilemapBufferRect_Palette0(1, 0x000, 0, 0, 30, 20);
            FillBgTilemapBufferRect_Palette0(2, 0x000, 0, 0, 30, 20);
            CopyBgTilemapBufferToVram(0);
            CopyBgTilemapBufferToVram(1);
            CopyBgTilemapBufferToVram(2);
            break;
        case 3:
            HideBg(1);
            HideBg(2);
			RemoveWindow(sWonderCardData->windowIds[CARD_WIN_FOOTER]);
			RemoveWindow(sWonderCardData->windowIds[CARD_WIN_BODY]);
			RemoveWindow(sWonderCardData->windowIds[CARD_WIN_HEADER]);
            break;
        case 4:
            DestroyCardSprites();
            FreeMonIconPalettes();
            break;
        case 5:
            PrintMysteryGiftOrEReaderTopMenu(gGiftIsFromEReader, flag);
            CopyBgTilemapBufferToVram(0);
            BeginNormalPaletteFade(0xFFFFFFFF, 0, 16, 0, RGB_BLACK);
            break;
        default:
            if (UpdatePaletteFade())
                return 0;
            sWonderCardData->enterExitState = 0;
            return 1;
    }
    ++sWonderCardData->enterExitState;
    return 0;
}

void BufferCardText(void)
{
    u16 i = 0;
    u16 charsUntilStat;
    u16 stats[3] = {0, 0, 0};

    // Copy title/subtitle text
    memcpy(sWonderCardData->titleText, sWonderCardData->card.titleText, WONDER_CARD_TEXT_LENGTH);
    sWonderCardData->titleText[WONDER_CARD_TEXT_LENGTH] = EOS;
    memcpy(sWonderCardData->subtitleText, sWonderCardData->card.subtitleText, WONDER_CARD_TEXT_LENGTH);
    sWonderCardData->subtitleText[WONDER_CARD_TEXT_LENGTH] = EOS;
	
    // Copy card id number
    if (sWonderCardData->card.idNumber > 999999)
        sWonderCardData->card.idNumber = 999999;
	
    ConvertIntToDecimalStringN(sWonderCardData->idNumberText, sWonderCardData->card.idNumber, STR_CONV_MODE_LEFT_ALIGN, 6);
	
	
    // Copy body text
    for (i = 0; i < 4; i++)
    {
        memcpy(sWonderCardData->bodyText[i], sWonderCardData->card.bodyText[i], WONDER_CARD_TEXT_LENGTH);
        sWonderCardData->bodyText[i][WONDER_CARD_TEXT_LENGTH] = EOS;
    }
    
	 // Copy footer line 1
    memcpy(sWonderCardData->footerLine1Text, sWonderCardData->card.footerLine1Text, WONDER_CARD_TEXT_LENGTH);
    sWonderCardData->footerLine1Text[WONDER_CARD_TEXT_LENGTH] = EOS;
	
    switch (sWonderCardData->card.type)
    {
		case CARD_TYPE_GIFT:
			memcpy(sWonderCardData->giftText, sWonderCardData->card.footerLine2Text, WONDER_CARD_TEXT_LENGTH);
			sWonderCardData->giftText[WONDER_CARD_TEXT_LENGTH] = EOS;
            break;
		case CARD_TYPE_STAMP:
			sWonderCardData->giftText[0] = EOS;
			break;
	    case CARD_TYPE_LINK_STAT:
            sWonderCardData->giftText[0] = EOS;
        
			// Load stats
			stats[0] = sWonderCardData->cardMetadata.battlesWon < MAX_WONDER_CARD_STAT ? sWonderCardData->cardMetadata.battlesWon : MAX_WONDER_CARD_STAT;
			stats[1] = sWonderCardData->cardMetadata.battlesLost < MAX_WONDER_CARD_STAT ? sWonderCardData->cardMetadata.battlesLost : MAX_WONDER_CARD_STAT;
			stats[2] = sWonderCardData->cardMetadata.numTrades < MAX_WONDER_CARD_STAT ? sWonderCardData->cardMetadata.numTrades : MAX_WONDER_CARD_STAT;
			
			// Init stat text arrays
			for (i = 0; i < ARRAY_COUNT(sWonderCardData->statTextData); i++)
			{
				memset(sWonderCardData->statTextData[i].statNumberText, EOS, sizeof(sWonderCardData->statTextData[i].statNumberText));
				memset(sWonderCardData->statTextData[i].statText,       EOS, sizeof(sWonderCardData->statTextData[i].statText));
			}

			// Copy stat texts
			for (i = 0, charsUntilStat = 0; i < WONDER_CARD_TEXT_LENGTH; i++)
			{
				if (sWonderCardData->card.footerLine2Text[i] != CHAR_DYNAMIC)
				{
					// Regular text, just copy as is
					sWonderCardData->statTextData[sWonderCardData->statFooterWidth].statText[charsUntilStat] = sWonderCardData->card.footerLine2Text[i];
					charsUntilStat++;
				}
				else
				{
					// Dynamic char encountered
					// These are used to give the id of which stat to print
					u8 id = sWonderCardData->card.footerLine2Text[i + 1];
					if (id >= ARRAY_COUNT(stats))
					{
						// Invalid stat id, skip ahead
						i += 2;
					}
					else
					{
						// Copy stat number
						ConvertIntToDecimalStringN(sWonderCardData->statTextData[sWonderCardData->statFooterWidth].statNumberText, stats[id], STR_CONV_MODE_LEADING_ZEROS, 3);
						sWonderCardData->statTextData[sWonderCardData->statFooterWidth].width = sWonderCardData->card.footerLine2Text[i + 2];
						sWonderCardData->statFooterWidth++;
						if (sWonderCardData->statFooterWidth >= ARRAY_COUNT(sWonderCardData->statTextData))
							break;
						charsUntilStat = 0;
						i += 2;
                }
            }
        }
    }
}

void DrawCardWindow(u8 whichWindow)
{
    s8 i = 0;
    s32 windowId = sWonderCardData->windowIds[whichWindow];
    PutWindowTilemap(windowId);
    FillWindowPixelBuffer(windowId, 0);
    switch (whichWindow)
    {
    case CARD_WIN_HEADER:
    {
        // Print card title/subtitle
        s32 x;
        AddTextPrinterParameterized3(windowId, 3, 0, 1, sCard_TextColorTable[sWonderCardData->gfx->titleTextPal], 0, sWonderCardData->titleText);
        x = 160 - GetStringWidth(3, sWonderCardData->subtitleText, GetFontAttribute(3, 2));
        if (x < 0)
            x = 0;
        AddTextPrinterParameterized3(windowId, 3, x, 17, sCard_TextColorTable[sWonderCardData->gfx->titleTextPal], 0, sWonderCardData->subtitleText);

        // Print id number
        //if (sWonderCardData->card.idNumber != 0)
        //    AddTextPrinterParameterized3(windowId, 1, 174, 17, sCard_TextColorTable[sWonderCardData->gfx->titleTextPal], 0, sWonderCardData->idNumberText);
        break;
    }
    case CARD_WIN_BODY: //footerLine1Text
        // Print body text
        for (; i < WONDER_CARD_BODY_TEXT_LINES; i++)
            AddTextPrinterParameterized3(windowId, 3, 0, 16 * i + 2, sCard_TextColorTable[sWonderCardData->gfx->bodyTextPal], 0, sWonderCardData->bodyText[i]);
        break;
    case CARD_WIN_FOOTER:
        // Print footer line 1
        AddTextPrinterParameterized3(windowId, 3, 0,
                                     sCard_FooterTextOffsets[sWonderCardData->card.type],
                                     sCard_TextColorTable[sWonderCardData->gfx->footerTextPal],
                                     0, sWonderCardData->footerLine1Text);
        
        // Print footer line 2
        if (sWonderCardData->card.type != CARD_TYPE_LINK_STAT)
        {
            // Print gift text
            // Odd that CARD_TYPE_STAMP is not ignored, it has empty text for this
            AddTextPrinterParameterized3(windowId, 3, 0,
                                         16 + sCard_FooterTextOffsets[sWonderCardData->card.type],
                                         sCard_TextColorTable[sWonderCardData->gfx->footerTextPal],
                                         0, sWonderCardData->giftText);
        }
        else
        {
            s32 x = 0;
            s32 y = sCard_FooterTextOffsets[sWonderCardData->card.type] + 16;
            s32 spacing = GetFontAttribute(3, 2);
            for (; i < sWonderCardData->statFooterWidth; i++)
            {
                // Print stat text
                AddTextPrinterParameterized3(windowId, 3, x, y, sCard_TextColorTable[sWonderCardData->gfx->footerTextPal], 0, sWonderCardData->statTextData[i].statText);
                if (sWonderCardData->statTextData[i].statNumberText[0] != EOS)
                {
                    // Print stat number
                    x += GetStringWidth(3, sWonderCardData->statTextData[i].statText, spacing);
                    AddTextPrinterParameterized3(windowId, 3, x, y,
                                                 sCard_TextColorTable[sWonderCardData->gfx->footerTextPal],
                                                 0, sWonderCardData->statTextData[i].statNumberText);
                    x += GetStringWidth(3, sWonderCardData->statTextData[i].statNumberText, spacing) + sWonderCardData->statTextData[i].width;
                }
            }
        }
        break;
    }
    CopyWindowToVram(windowId, 3);
}

#define SPRITE_NONE 0xFF
#define TAG_STAMP_SHADOW 0x8000
#define TASK_NONE 0xFF
#define FONT_SHORT_COPY_1 3
#define COPYWIN_FULL 3
#define BG_COORD_ADD 1
#define BG_COORD_SUB 2

void CreateCardSprites(void)
{
    u8 i = 0;
	struct WonderCard SavedWonderCard = *GetSavedWonderCard();
	u16 speciesID = SPECIES_NONE;
	u16 species = 0;
	u8 formId = 0;
    sWonderCardData->monIconSpriteId = SPRITE_NONE;
	
    
    // Create icon sprite
    if (SavedWonderCard.iconSpecies != SPECIES_NONE)
    {
		speciesID = SavedWonderCard.iconSpecies;
		species = SpeciesToPokedexNum(speciesID);
		formId  = GetFormIdFromFormSpeciesId(speciesID);
		sWonderCardData->monIconSpriteId = CreateMonIcon(species, SpriteCallbackDummy, 220, 20, 0, 0, formId);
        gSprites[sWonderCardData->monIconSpriteId].oam.priority = 2;
    }

    // Create stamp sprites
    if (sWonderCardData->card.maxStamps != 0 && sWonderCardData->card.type == CARD_TYPE_STAMP)
    {
        LoadCompressedSpriteSheetUsingHeap(&sSpriteSheet_StampShadow);
        LoadSpritePalette(&sSpritePalettes_StampShadow[sWonderCardData->gfx->stampShadowPal]);
        for (; i < sWonderCardData->card.maxStamps; i++)
        {
            sWonderCardData->stampSpriteIds[i][0] = SPRITE_NONE;
            sWonderCardData->stampSpriteIds[i][1] = SPRITE_NONE;
            sWonderCardData->stampSpriteIds[i][0] = CreateSprite(&sSpriteTemplate_StampShadow, 216 - 32 * i, 144, 8);
            if (sWonderCardData->cardMetadata.stampData[STAMP_SPECIES][i] != SPECIES_NONE)
                //sWonderCardData->stampSpriteIds[i][1] = CreateMonIconNoPersonality(GetIconSpeciesNoPersonality(sWonderCardData->cardMetadata.stampData[STAMP_SPECIES][i]), 
                sWonderCardData->stampSpriteIds[i][1] = sub_80D2D78(sub_80D2E84(sWonderCardData->cardMetadata.stampData[STAMP_SPECIES][i]), 
                                                                               SpriteCallbackDummy,
                                                                               216 - 32 * i,
                                                                               136, 0);
        }
    }
	
	PlayCry3(species, 0, 0);	
}

void DestroyCardSprites(void)
{
    u8 i = 0;

    // Destroy icon sprite
    if (sWonderCardData->monIconSpriteId != SPRITE_NONE)
        FreeAndDestroyMonIconSprite(&gSprites[sWonderCardData->monIconSpriteId]);
    
    // Destroy stamp sprites
    if (sWonderCardData->card.maxStamps != 0 && sWonderCardData->card.type == CARD_TYPE_STAMP)
    {
        for (; i < sWonderCardData->card.maxStamps; i++)
        {
            if (sWonderCardData->stampSpriteIds[i][0] != SPRITE_NONE)
                DestroySprite(&gSprites[sWonderCardData->stampSpriteIds[i][0]]);
            if (sWonderCardData->stampSpriteIds[i][1] != SPRITE_NONE)
                FreeAndDestroyMonIconSprite(&gSprites[sWonderCardData->stampSpriteIds[i][1]]);
        }
        FreeSpriteTilesByTag(TAG_STAMP_SHADOW);
        FreeSpritePaletteByTag(TAG_STAMP_SHADOW);
    }
}

//======================
//    Wonder News
//======================

enum {
    NEWS_WIN_TITLE,
    NEWS_WIN_BODY,
    NEWS_WIN_COUNT
};

#define TAG_ARROWS 0x1000

struct WonderNewsData
{
    /*0000*/ struct WonderNews news;
    /*01bc*/ const struct WonderGraphics * gfx;
    /*01c0*/ u8 arrowsRemoved:1;
             u8 enterExitState:7;
    /*01c1*/ u8 arrowTaskId;
    /*01c2*/ bool8 scrolling:1;
             u8 scrollIncrement:7;
    /*01c3*/ bool8 scrollingDown:1;
             u8 scrollTotal:7;
    /*01c4*/ u16 scrollEnd;
    /*01c6*/ u16 scrollOffset;
    /*01c8*/ u16 windowIds[NEWS_WIN_COUNT];
    /*01cc*/ u8 unused[2];
    /*01ce*/ u8 titleText[WONDER_NEWS_TEXT_LENGTH + 1];
    /*01f7*/ u8 bodyText[WONDER_NEWS_BODY_TEXT_LINES][WONDER_NEWS_TEXT_LENGTH + 1];
    /*0394*/ struct ScrollArrowsTemplate arrowsTemplate;
    /*03a4*/ u8 bgTilemapBuffer[0x1000];
};

EWRAM_DATA struct WonderNewsData * sWonderNewsData = NULL;

void BufferNewsText(void);
void DrawNewsWindows(void);
void UpdateNewsScroll(void);

static const u8 sNews_TextColorTable[][3] = {
    {0, 2, 3},
    {0, 1, 2}
};

const struct WindowTemplate sNews_WindowTemplates[] = {
    [NEWS_WIN_TITLE] = {
        .bg = 0,
        .tilemapLeft = 1,
        .tilemapTop = 0,
        .width = 28,
        .height = 3,
        .paletteNum = 2,
        .baseBlock = 0x2AC
    },
    [NEWS_WIN_BODY] = {
        .bg = 2,
        .tilemapLeft = 1,
        .tilemapTop = 3,
        .width = 28,
        .height = 20,
        .paletteNum = 2,
        .baseBlock = 0x07C
    }
};

const struct ScrollArrowsTemplate sNews_ArrowsTemplate = {
    .firstArrowType = SCROLL_ARROW_UP,
    .firstX = 232,
    .firstY = 24,
    .secondArrowType = SCROLL_ARROW_DOWN,
    .secondX = 232,
    .secondY = 152,
    .fullyUpThreshold = 0,
    .fullyDownThreshold = 2,
    .tileTag = TAG_ARROWS,
    .palTag = TAG_ARROWS,
    .palNum = 0
};

const u16 gWonderNewsPal1[] = INCBIN_U16("graphics/wonder_transfers/wonder_news_1.gbapal");
const u16 gWonderNewsPal7[] = INCBIN_U16("graphics/wonder_transfers/wonder_news_7.gbapal");
const u16 gWonderNewsPal8[] = INCBIN_U16("graphics/wonder_transfers/wonder_news_8.gbapal");
const u32 gWonderNewsGfx1[] = INCBIN_U32("graphics/wonder_transfers/wonder_news_1.4bpp.lz");
const u32 gWonderNewsTilemap1[] = INCBIN_U32("graphics/wonder_transfers/wonder_news_1.bin.lz");
const u32 gWonderNewsGfx2[] = INCBIN_U32("graphics/wonder_transfers/wonder_news_2.4bpp.lz");
const u32 gWonderNewsTilemap2[] = INCBIN_U32("graphics/wonder_transfers/wonder_news_2.bin.lz");
const u32 gWonderNewsGfx3[] = INCBIN_U32("graphics/wonder_transfers/wonder_news_3.4bpp.lz");
const u32 gWonderNewsTilemap3[] = INCBIN_U32("graphics/wonder_transfers/wonder_news_3.bin.lz");
const u32 gWonderNewsGfx7[] = INCBIN_U32("graphics/wonder_transfers/wonder_news_7.4bpp.lz");
const u32 gWonderNewsTilemap7[] = INCBIN_U32("graphics/wonder_transfers/wonder_news_7.bin.lz");
const u32 gWonderNewsGfx8[] = INCBIN_U32("graphics/wonder_transfers/wonder_news_8.4bpp.lz");
const u32 gWonderNewsTilemap8[] = INCBIN_U32("graphics/wonder_transfers/wonder_news_8.bin.lz");

const struct WonderGraphics sNewsGraphics[] = {
    {1, 0, 0, 0, gWonderNewsGfx1, gWonderNewsTilemap1, gWonderNewsPal1},
    {1, 0, 0, 0, gWonderNewsGfx2, gWonderNewsTilemap2, gWonderCardBgPal2},
    {1, 0, 0, 0, gWonderNewsGfx3, gWonderNewsTilemap3, gWonderCardBgPal3},
    {1, 0, 0, 0, gWonderNewsGfx3, gWonderNewsTilemap3, gWonderCardBgPal4},
    {1, 0, 0, 0, gWonderNewsGfx3, gWonderNewsTilemap3, gWonderCardBgPal5},
    {1, 0, 0, 0, gWonderNewsGfx3, gWonderNewsTilemap3, gWonderCardBgPal6},
    {1, 0, 0, 0, gWonderNewsGfx7, gWonderNewsTilemap7, gWonderNewsPal7},
    {1, 0, 0, 0, gWonderNewsGfx8, gWonderNewsTilemap8, gWonderNewsPal8}
};

bool32 InitWonderNewsResources(const struct WonderNews * news)
{
    if (news == NULL)
        return FALSE;
    sWonderNewsData = AllocZeroed(sizeof(*sWonderNewsData));
    if (sWonderNewsData == NULL)
        return FALSE;
    sWonderNewsData->news = *news;
    if (sWonderNewsData->news.bgType >= NUM_WONDER_BGS)
        sWonderNewsData->news.bgType = 0;
    sWonderNewsData->gfx = &sNewsGraphics[sWonderNewsData->news.bgType];
    sWonderNewsData->arrowTaskId = TASK_NONE;
    return TRUE;
}

void DestroyWonderNewsResources(void)
{
    if (sWonderNewsData != NULL)
    {
        *sWonderNewsData = (struct WonderNewsData){};
        Free(sWonderNewsData);
        sWonderNewsData = NULL;
    }
}

s32 FadeToWonderNewsMenu(void)
{
    if (sWonderNewsData == NULL)
        return -1;

    switch (sWonderNewsData->enterExitState)
    {
        case 0:
            BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 16, RGB_BLACK);
            break;
        case 1:
            if (UpdatePaletteFade())
                return 0;
            ChangeBgY(0, 0, 0);
            ChangeBgY(1, 0, 0);
            ChangeBgY(2, 0, 0);
            ChangeBgY(3, 0, 0);
            SetGpuReg(REG_OFFSET_WIN0H, 0xF0);
            SetGpuReg(REG_OFFSET_WIN0V, 0x1A98);
            SetGpuReg(REG_OFFSET_WININ, 0x1F);
            SetGpuReg(REG_OFFSET_WINOUT, 0x1B);
            SetGpuRegBits(REG_OFFSET_DISPCNT, DISPCNT_WIN0_ON);
            break;
        case 2:
            FillBgTilemapBufferRect_Palette0(0, 0x000, 0, 0, 30, 20);
            FillBgTilemapBufferRect_Palette0(1, 0x000, 0, 0, 30, 20);
            FillBgTilemapBufferRect_Palette0(2, 0x000, 0, 0, 30, 20);
            FillBgTilemapBufferRect_Palette0(3, 0x000, 0, 0, 30, 20);
            CopyBgTilemapBufferToVram(0);
            CopyBgTilemapBufferToVram(1);
            CopyBgTilemapBufferToVram(2);
            CopyBgTilemapBufferToVram(3);
            DecompressAndCopyTileDataToVram(3, sWonderNewsData->gfx->tiles, 0, 8, 0);
            sWonderNewsData->windowIds[0] = AddWindow(&sNews_WindowTemplates[0]);
            sWonderNewsData->windowIds[1] = AddWindow(&sNews_WindowTemplates[1]);
            break;
        case 3:
            if (FreeTempTileDataBuffersIfPossible())
                return 0;
            LoadPalette(GetTextWindowPalette(1), 0x20, 0x20);
            gPaletteFade.bufferTransferDisabled = TRUE;
            LoadPalette(sWonderNewsData->gfx->pal, 0x10, 0x20);
            LZ77UnCompWram(sWonderNewsData->gfx->map, sWonderNewsData->bgTilemapBuffer);
            CopyRectToBgTilemapBufferRect(1, sWonderNewsData->bgTilemapBuffer, 0, 0, 30, 3, 0, 0, 30, 3, 1, 8, 0);
            CopyRectToBgTilemapBufferRect(3, sWonderNewsData->bgTilemapBuffer, 0, 3, 30, 23, 0, 3, 30, 23, 1, 8, 0);
            CopyBgTilemapBufferToVram(1);
            CopyBgTilemapBufferToVram(3);
            break;
        case 4:
            BufferNewsText();
            break;
        case 5:
            DrawNewsWindows();
            CopyBgTilemapBufferToVram(0);
            CopyBgTilemapBufferToVram(2);
            break;
        case 6:
            ShowBg(1);
            ShowBg(2);
            ShowBg(3);
            gPaletteFade.bufferTransferDisabled = FALSE;
            sWonderNewsData->arrowTaskId = AddScrollIndicatorArrowPair(&sWonderNewsData->arrowsTemplate, &sWonderNewsData->scrollOffset);
            BeginNormalPaletteFade(0xFFFFFFFF, 0, 16, 0, RGB_BLACK);
            UpdatePaletteFade();
            break;
        default:
            if (UpdatePaletteFade())
                return 0;
            sWonderNewsData->enterExitState = 0;
            return 1;
    }

    ++sWonderNewsData->enterExitState;
    return 0;
}

s32 FadeOutFromWonderNews(bool32 flag)
{
    if (sWonderNewsData == NULL)
        return -1;
    switch (sWonderNewsData->enterExitState)
    {
        case 0:
            BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 16, RGB_BLACK);
            break;
        case 1:
            if (UpdatePaletteFade())
                return 0;
            ChangeBgY(2, 0, 0);
            SetGpuReg(REG_OFFSET_WIN0H, 0);
            SetGpuReg(REG_OFFSET_WIN0V, 0);
            SetGpuReg(REG_OFFSET_WININ, 0);
            SetGpuReg(REG_OFFSET_WINOUT, 0);
            ClearGpuRegBits(REG_OFFSET_DISPCNT, DISPCNT_WIN0_ON);
            break;
        case 2:
            FillBgTilemapBufferRect_Palette0(0, 0x000, 0, 0, 30, 20);
            FillBgTilemapBufferRect_Palette0(1, 0x000, 0, 0, 30, 20);
            FillBgTilemapBufferRect_Palette0(2, 0x000, 0, 0, 30, 24);
            FillBgTilemapBufferRect_Palette0(3, 0x000, 0, 0, 30, 24);
            CopyBgTilemapBufferToVram(0);
            CopyBgTilemapBufferToVram(1);
            CopyBgTilemapBufferToVram(2);
            CopyBgTilemapBufferToVram(3);
            break;
        case 3:
            HideBg(1);
            HideBg(2);
            RemoveWindow(sWonderNewsData->windowIds[1]);
            RemoveWindow(sWonderNewsData->windowIds[0]);
            break;
        case 4:
            ChangeBgY(2, 0, 0);
            ChangeBgY(3, 0, 0);
            if (sWonderNewsData->arrowTaskId != 0xFF)
            {
                RemoveScrollIndicatorArrowPair(sWonderNewsData->arrowTaskId);
                sWonderNewsData->arrowTaskId = 0xFF;
            }
            break;
        case 5:
            PrintMysteryGiftOrEReaderTopMenu(gGiftIsFromEReader, flag);
            MG_DrawCheckerboardPattern(3);
            CopyBgTilemapBufferToVram(0);
            CopyBgTilemapBufferToVram(3);
            BeginNormalPaletteFade(0xFFFFFFFF, 0, 16, 0, RGB_BLACK);
            break;
        default:
            if (UpdatePaletteFade())
                return 0;
            sWonderNewsData->enterExitState = 0;
            return 1;
    }
    ++sWonderNewsData->enterExitState;
    return 0;
}

void MENews_RemoveScrollIndicatorArrowPair(void)
{
    if (!sWonderNewsData->arrowsRemoved && sWonderNewsData->arrowTaskId != 0xFF)
    {
        RemoveScrollIndicatorArrowPair(sWonderNewsData->arrowTaskId);
        sWonderNewsData->arrowTaskId = 0xFF;
        sWonderNewsData->arrowsRemoved = TRUE;
    }
}


void MENews_AddScrollIndicatorArrowPair(void)
{
    if (sWonderNewsData->arrowsRemoved)
    {
        sWonderNewsData->arrowTaskId = AddScrollIndicatorArrowPair(&sWonderNewsData->arrowsTemplate, &sWonderNewsData->scrollOffset);
        sWonderNewsData->arrowsRemoved = FALSE;
    }
}

u32 MENews_GetInput(u16 input)
{
    if (sWonderNewsData->scrolling)
    {
        UpdateNewsScroll();
        return 0xFF;
    }
    switch (input)
    {
        case A_BUTTON:
            return 0;
        case B_BUTTON:
            return 1;
        case DPAD_UP:
            if (sWonderNewsData->scrollOffset == 0)
                return 0xFF;
            if (sWonderNewsData->arrowsRemoved)
                return 0xFF;
            sWonderNewsData->scrollingDown = FALSE;
            break;
        case DPAD_DOWN:
            if (sWonderNewsData->scrollOffset == sWonderNewsData->scrollEnd)
                return 0xFF;
            if (sWonderNewsData->arrowsRemoved)
                return 0xFF;
            sWonderNewsData->scrollingDown = TRUE;
            break;
        default:
            return 0xFF;
    }
    sWonderNewsData->scrolling = TRUE;
    sWonderNewsData->scrollIncrement = 2;
    sWonderNewsData->scrollTotal = 0;
    if (sWonderNewsData->scrollingDown == FALSE)
        return 2;
    else
        return 3;
}

void BufferNewsText(void)
{
     u8 i = 0;
    
    // Copy title text
    memcpy(sWonderNewsData->titleText, sWonderNewsData->news.titleText, WONDER_NEWS_TEXT_LENGTH);
    sWonderNewsData->titleText[WONDER_NEWS_TEXT_LENGTH] = EOS;

    // Copy body text
    for (; i < WONDER_NEWS_BODY_TEXT_LINES; i++)
    {
        memcpy(sWonderNewsData->bodyText[i], sWonderNewsData->news.bodyText[i], WONDER_NEWS_TEXT_LENGTH);
        sWonderNewsData->bodyText[i][WONDER_NEWS_TEXT_LENGTH] = EOS;
        if (i > 7 && sWonderNewsData->bodyText[i][0] != EOS)
            sWonderNewsData->scrollEnd++;
    }
    sWonderNewsData->arrowsTemplate = sNews_ArrowsTemplate;
    sWonderNewsData->arrowsTemplate.fullyDownThreshold = sWonderNewsData->scrollEnd;
}

void DrawNewsWindows(void)
{
    u8 i = 0;
    s32 x;
    PutWindowTilemap(sWonderNewsData->windowIds[NEWS_WIN_TITLE]);
    PutWindowTilemap(sWonderNewsData->windowIds[NEWS_WIN_BODY]);
    FillWindowPixelBuffer(sWonderNewsData->windowIds[NEWS_WIN_TITLE], 0);
    FillWindowPixelBuffer(sWonderNewsData->windowIds[NEWS_WIN_BODY], 0);

    // Print title text
    x = (224 - GetStringWidth(FONT_SHORT_COPY_1, sWonderNewsData->titleText, GetFontAttribute(FONT_SHORT_COPY_1, FONTATTR_LETTER_SPACING))) / 2;
    if (x < 0)
        x = 0;
    AddTextPrinterParameterized3(sWonderNewsData->windowIds[NEWS_WIN_TITLE], FONT_SHORT_COPY_1, x, 6, sNews_TextColorTable[sWonderNewsData->gfx->titleTextPal], 0, sWonderNewsData->titleText);
    
    // Print body text
    for (; i < WONDER_NEWS_BODY_TEXT_LINES; i++)
        AddTextPrinterParameterized3(sWonderNewsData->windowIds[NEWS_WIN_BODY], FONT_SHORT_COPY_1, 0,
                                     16 * i + 2,
                                     sNews_TextColorTable[sWonderNewsData->gfx->bodyTextPal],
                                     0, sWonderNewsData->bodyText[i]);

    CopyWindowToVram(sWonderNewsData->windowIds[NEWS_WIN_TITLE], COPYWIN_FULL);
    CopyWindowToVram(sWonderNewsData->windowIds[NEWS_WIN_BODY], COPYWIN_FULL);
}


void UpdateNewsScroll(void)
{
    u16 bgMove = sWonderNewsData->scrollIncrement;
    bgMove *= 256;
    if (sWonderNewsData->scrollingDown)
    {
        ChangeBgY(2, bgMove, BG_COORD_ADD);
        ChangeBgY(3, bgMove, BG_COORD_ADD);
    }
    else
    {
        ChangeBgY(2, bgMove, BG_COORD_SUB);
        ChangeBgY(3, bgMove, BG_COORD_SUB);
    }
    sWonderNewsData->scrollTotal += sWonderNewsData->scrollIncrement;
    if (sWonderNewsData->scrollTotal > 15)
    {
        if (sWonderNewsData->scrollingDown)
            sWonderNewsData->scrollOffset++;
        else
            sWonderNewsData->scrollOffset--;
        sWonderNewsData->scrolling = FALSE;
        sWonderNewsData->scrollTotal = 0;
    }
}
