#include "global.h"
#include "ui_start_menu.h"
#include "strings.h"
#include "bg.h"
#include "random.h"
#include "bike.h"
#include "data.h"
#include "decompress.h"
#include "dexnav.h"
#include "event_data.h"
#include "event_object_lock.h"
#include "field_weather.h"
#include "fieldmap.h"
#include "frontier_pass.h"
#include "gpu_regs.h"
#include "graphics.h"
#include "item.h"
#include "item_menu.h"
#include "item_menu_icons.h"
#include "list_menu.h"
#include "link.h"
#include "item_icon.h"
#include "item_use.h"
#include "field_screen_effect.h"
#include "international_string_util.h"
#include "main.h"
#include "main_menu.h"
#include "malloc.h"
#include "menu.h"
#include "metatile_behavior.h"
#include "menu_helpers.h"
#include "palette.h"
#include "party_menu.h"
#include "pokedex.h"
#include "pokemon_icon.h"
#include "rtc.h"
#include "scanline_effect.h"
#include "script.h"
#include "sound.h"
#include "start_menu.h"
#include "string_util.h"
#include "strings.h"
#include "task.h"
#include "quests.h"
#include "debug.h"
#include "trainer_card.h"
#include "text_window.h"
#include "overworld.h"
#include "event_data.h"
#include "field_player_avatar.h"
#include "tx_pokemon_follower.h"
#include "script_pokemon_util.h"
#include "pokenav.h"
#include "day_night.h"
#include "option_menu.h"
#include "level_scaling.h"
#include "wallclock.h"
#include "constants/map_groups.h"
#include "constants/maps.h"
#include "constants/items.h"
#include "constants/field_weather.h"
#include "constants/songs.h"
#include "constants/rgb.h"
#include "naming_screen.h"
#include "printf.h"
#include "mgba.h"

/*
 * 
 */
enum{
	//START_MENU_BG_TEXT,
	//START_MENU_BG_UNUSED,
	START_MENU_BG_NORMAL,
	START_MENU_BG_SCROLLING,
	NUM_BACKGROUNDS,
};

//==========DEFINES==========//
struct MenuResources
{
    MainCallback savedCallback;     // determines callback to run when we exit. e.g. where do we want to go after closing the menu
    u8 gfxLoadState;
	u8 cursorRowX;
	u8 cursorRowY;
	u8 KonamiCodeState;
    u8 PartyPokemonIcon_0;
    u8 PartyPokemonIcon_1;
    u8 PartyPokemonIcon_2;
    u8 PartyPokemonIcon_3;
    u8 PartyPokemonIcon_4;
    u8 PartyPokemonIcon_5;
    u8 PartyPokemonIcon_6;
	u8 CurrentMessage;
	u16 bgTilemapBuffers[NUM_BACKGROUNDS][0x400];
};

enum WindowIds
{
    WINDOW_1,
};

enum MessagesIds
{
    MESSAGE_HELP_BAR,
	MESSAGE_CANT_USE_BIKE,
	MESSAGE_CANT_USE_DEXNAV,
	MESSAGE_CANT_SAVE,
	MESSAGE_CANT_CHANGE_TIME,
	MESSAGE_STEPS_RESET,
	NUM_MESSAGES,
};

//==========EWRAM==========//
static EWRAM_DATA struct MenuResources *sMenuDataPtr = NULL;

// IWRAM common
bool8 (*gMenuCallback)(void);

//==========STATIC=DEFINES==========//
static void Menu_RunSetup(void);
static bool8 Menu_DoGfxSetup(void);
static bool8 Menu_Start_InitBgs(void);
static void setScrollingBackground(void);
static void setNormalBackground(void);
static void Menu_FadeAndBail(void);
static bool8 Menu_LoadGraphics(void);
static void Menu_Start_InitWindows(void);
static void PrintToWindow(u8 windowId, u8 colorIdx);
static void Task_MenuWaitFadeIn(u8 taskId);
static void Task_MenuMain(u8 taskId);

void Task_OpenPokemonPartyFromStartMenu(u8 taskId);
void Task_OpenPokedexFromStartMenu(u8 taskId);
static u8 ShowSpeciesIcon(u8 slot, u8 x, u8 y);

extern u8 PlayersHouse_2F_EventScript_SetWallClock[];

//==========CONST=DATA==========//
static const struct BgTemplate sMenuBgTemplates[] =
{
    {
        .bg = 0,    // windows, etc
        .charBaseIndex = 0,
        .mapBaseIndex = 31,
        .priority = 1
    }, 
    {
        .bg = 1,    // this bg loads the UI tilemap
        .charBaseIndex = 3,
        .mapBaseIndex = 30,
        .priority = 2
    },
    {
		//Scrolling Backgrond
        .bg = 2,
        .charBaseIndex = 3,
        .mapBaseIndex = 28,
        .priority = 3,
    },
};

static const struct WindowTemplate sMenuWindowTemplates[] = 
{
    [WINDOW_1] = 
    {
        .bg = 0,            // which bg to print text on
        .tilemapLeft = 0,   // position from left (per 8 pixels)
        .tilemapTop = 0,    // position from top (per 8 pixels)
        .width = 30,        // width (per 8 pixels)
        .height = 20,       // height (per 8 pixels)
        .paletteNum = 0,    // palette index to use for text
        .baseBlock = 1,     // tile start in VRAM
    },
};

static const u32 sMenuTiles[] 			= INCBIN_U32("graphics/ui_menu/start_menu/tiles.4bpp.lz");
static const u32 sMenuTilemap[] 		= INCBIN_U32("graphics/ui_menu/start_menu/tilemap_bw.bin.lz");
static const u16 sMenuPalette[] 		= INCBIN_U16("graphics/ui_menu/start_menu/palette.gbapal");
static const u8 sStartMenuCursor_Gfx[]  = INCBIN_U8("graphics/ui_menu/start_menu/menu_cursor.4bpp");
static const u8 sAutoRunOn_Gfx[] 		= INCBIN_U8("graphics/ui_menu/start_menu/On.4bpp");
static const u8 sMachIcon_Gfx[] 		= INCBIN_U8("graphics/ui_menu/start_menu/Mach.4bpp");
static const u8 sAcroIcon_Gfx[] 		= INCBIN_U8("graphics/ui_menu/start_menu/Acro.4bpp");

const u32 sStartMenuScrollingBGTilemap[] = INCBIN_U32("graphics/ui_menu/start_menu/scrolling_bg.bin.lz");

#define  NUM_ROWS_Y   	 		 4
#define  NUM_ROWS_X   	 		 2
#define  NUM_MODES  	 		 9
#define  NUM_STARTERS  	 		 10
#define  NUM_DIFFICULTY_OPTIONS  3
#define  NUM_STARTING_AREAS  	 14
#define  NUM_MAX_POKE   	 	 6

//EWRAM_DATA static u8 sStartMenuCursorSprite  = 0;

enum Colors
{
    FONT_BLACK,
    FONT_WHITE,
    FONT_RED,
    FONT_BLUE,
};
static const u8 sMenuWindowFontColors[][3] = 
{
    [FONT_BLACK]  = {TEXT_COLOR_TRANSPARENT,  7,  4},
    [FONT_WHITE]  = {TEXT_COLOR_TRANSPARENT,  1,  5},
    [FONT_RED]   = {TEXT_COLOR_TRANSPARENT,  11, 12},
    [FONT_BLUE]  = {TEXT_COLOR_TRANSPARENT,  13, 14},
};

// Menu actions
enum
{
    MENU_ACTION_POKEDEX,
	MENU_ACTION_PLAYER,
    MENU_ACTION_POKEMON,
	MENU_ACTION_SAVE,
    MENU_ACTION_BAG,
	MENU_ACTION_OPTION,
    MENU_ACTION_POKENAV,
    MENU_ACTION_DEXNAV,
    MENU_ACTION_EXIT,
};

//==========FUNCTIONS==========//
// UI loader template
void Task_OpenStartMenuFromStartMenu(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    if (!gPaletteFade.active)
    {
        CleanupOverworldWindowsAndTilemaps();
        Menu_Start_Init(CB2_ReturnToField);
        DestroyTask(taskId);
    }
}

// This is our main initialization function if you want to call the menu from elsewhere
void Menu_Start_Init(MainCallback callback)
{
	if ((sMenuDataPtr = AllocZeroed(sizeof(struct MenuResources))) == NULL)
    {
        SetMainCallback2(callback);
        return;
    }

    // initialize stuff
    sMenuDataPtr->gfxLoadState = 0;
    sMenuDataPtr->savedCallback = callback;
	
	sMenuDataPtr->cursorRowX = VarGet(VAR_START_MENU_CURSOR_X);
	sMenuDataPtr->cursorRowY = VarGet(VAR_START_MENU_CURSOR_Y);
	sMenuDataPtr->KonamiCodeState = 0;
    sMenuDataPtr->PartyPokemonIcon_0 = 0;
    sMenuDataPtr->PartyPokemonIcon_1 = 0;
    sMenuDataPtr->PartyPokemonIcon_2 = 0;
    sMenuDataPtr->PartyPokemonIcon_3 = 0;
    sMenuDataPtr->PartyPokemonIcon_4 = 0;
    sMenuDataPtr->PartyPokemonIcon_5 = 0;
    sMenuDataPtr->PartyPokemonIcon_6 = 0;

    SetMainCallback2(Menu_RunSetup);
}

static void Menu_RunSetup(void)
{
	while (1)
    {
        if (Menu_DoGfxSetup() == TRUE)
            break;
    }
}

static void Menu_MainCB(void)
{
    RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    DoScheduledBgTilemapCopiesToVram();
    UpdatePaletteFade();
}

static void Menu_VBlankCB(void)
{
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
}

#define ICON_STARTING_X 176
#define ICON_STARTING_Y 32
#define X_DIFFERENCE_BETWEEN_SPECIES 40
#define Y_DIFFERENCE_BETWEEN_SPECIES 40

static bool8 Menu_DoGfxSetup(void)
{
    u8 taskId;
	u8 x, y, i;

    switch (gMain.state)
    {
    case 0:
        DmaClearLarge16(3, (void *)VRAM, VRAM_SIZE, 0x1000)
        SetVBlankHBlankCallbacksToNull();
        ClearScheduledBgCopiesToVram();
        gMain.state++;
        break;
    case 1:
        ScanlineEffect_Stop();
        FreeAllSpritePalettes();
        ResetPaletteFade();
        ResetSpriteData();
        ResetTasks();
        gMain.state++;
        break;
    case 2:
        if (Menu_Start_InitBgs())
        {
            sMenuDataPtr->gfxLoadState = 0;
            gMain.state++;
        }
        else
        {
            Menu_FadeAndBail();
            return TRUE;
        }
        break;
    case 3:
        if (Menu_LoadGraphics() == TRUE)
            gMain.state++;
        break;
    case 4:
        LoadMessageBoxAndBorderGfx();
        Menu_Start_InitWindows();
        gMain.state++;
        break;
    case 5:
        PrintToWindow(WINDOW_1, FONT_BLACK);
        taskId = CreateTask(Task_MenuWaitFadeIn, 0);
        BlendPalettes(0xFFFFFFFF, 16, RGB_BLACK);

		// Pokemon Icons --------------------------------------------------------------------------------------------------------------------
        x = ICON_STARTING_X;
		y = ICON_STARTING_Y;

        for(i = 0; i < PARTY_SIZE; i++){
            if(GetMonData(&gPlayerParty[i], MON_DATA_SPECIES) != SPECIES_NONE)
                ShowSpeciesIcon(i, x, y);

			if(i % 2 == 0){
				x = x + X_DIFFERENCE_BETWEEN_SPECIES;
			}
			else{
				x = ICON_STARTING_X;
				y = y + Y_DIFFERENCE_BETWEEN_SPECIES;
			}
        }
		
        gMain.state++;
        break;
    case 6:
        BeginNormalPaletteFade(0xFFFFFFFF, 0, 16, 0, RGB_BLACK);
        gMain.state++;
        break;
    default:
        SetVBlankCallback(Menu_VBlankCB);
        SetMainCallback2(Menu_MainCB);
        return TRUE;
    }
    return FALSE;
}

#define try_free(ptr) ({        \
    void ** ptr__ = (void **)&(ptr);   \
    if (*ptr__ != NULL)                \
        Free(*ptr__);                  \
})

static void Menu_FreeResources(void)
{
    try_free(sMenuDataPtr);
    FreeAllWindowBuffers();
}


static void Task_MenuWaitFadeAndBail(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        SetMainCallback2(sMenuDataPtr->savedCallback);
        Menu_FreeResources();
        DestroyTask(taskId);
    }
}

static void Menu_FadeAndBail(void)
{
    BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 16, RGB_BLACK);
    CreateTask(Task_MenuWaitFadeAndBail, 0);
    SetVBlankCallback(Menu_VBlankCB);
    SetMainCallback2(Menu_MainCB);
}

static bool8 Menu_Start_InitBgs(void)
{
	ResetBgsAndClearDma3BusyFlags(0);
    //Background 1
    setNormalBackground();

    //Background 3 - Scroll
    setScrollingBackground();
    return TRUE;
}

#define NORMAL_BACKGROUND_NUM 1
static void setNormalBackground(){
    SetBgAttribute(NORMAL_BACKGROUND_NUM, BG_ATTR_PRIORITY, NORMAL_BACKGROUND_NUM);
    InitBgsFromTemplates(0, sMenuBgTemplates, ARRAY_COUNT(sMenuBgTemplates));
    SetBgTilemapBuffer(NORMAL_BACKGROUND_NUM, sMenuDataPtr->bgTilemapBuffers[START_MENU_BG_NORMAL]);
    ScheduleBgCopyTilemapToVram(NORMAL_BACKGROUND_NUM);
    SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_OBJ_ON | DISPCNT_OBJ_1D_MAP);
    SetGpuReg(REG_OFFSET_BLDCNT, 0);
    ShowBg(0);
    ShowBg(NORMAL_BACKGROUND_NUM);
	ChangeBgX(NORMAL_BACKGROUND_NUM, 0, 1);
	ChangeBgY(NORMAL_BACKGROUND_NUM, 0, 1);
}

#define SCROLLING_BACKGROUND_NUM 2
static void setScrollingBackground(){
	SetBgTilemapBuffer(SCROLLING_BACKGROUND_NUM, sMenuDataPtr->bgTilemapBuffers[START_MENU_BG_SCROLLING]);
    ScheduleBgCopyTilemapToVram(SCROLLING_BACKGROUND_NUM);
    SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_OBJ_ON | DISPCNT_OBJ_1D_MAP);
    SetGpuReg(REG_OFFSET_BLDCNT, 0);
    ShowBg(SCROLLING_BACKGROUND_NUM);
	ChangeBgX(SCROLLING_BACKGROUND_NUM, 0, 1);
	ChangeBgY(SCROLLING_BACKGROUND_NUM, 0, 1);
}

static bool8 Menu_LoadGraphics(void)
{
	
	//mgba_printf(MGBA_LOG_WARN, "Menu_LoadGraphics Step %d Completed", sMenuDataPtr->gfxLoadState);
    switch (sMenuDataPtr->gfxLoadState)
    {
    case 0:
        ResetTempTileDataBuffers();
        DecompressAndCopyTileDataToVram(1, sMenuTiles, 0, 0, 0);
        sMenuDataPtr->gfxLoadState++;
        break;
    case 1:
        if (FreeTempTileDataBuffersIfPossible() != TRUE)
        {
			LZDecompressWram(sMenuTilemap, sMenuDataPtr->bgTilemapBuffers[START_MENU_BG_NORMAL]);
            sMenuDataPtr->gfxLoadState++;
        }
		break;
	case 2:
		//Load Background
		LZDecompressWram(sStartMenuScrollingBGTilemap, sMenuDataPtr->bgTilemapBuffers[START_MENU_BG_SCROLLING]);
        sMenuDataPtr->gfxLoadState++;
        break;
    case 3:
        LoadPalette(sMenuPalette, 0, 32);
        sMenuDataPtr->gfxLoadState++;
        break;
    default:
        sMenuDataPtr->gfxLoadState = 0;
        return TRUE;
    }
    return FALSE;
}

static void Menu_Start_InitWindows(void)
{
    u32 i;

    InitWindows(sMenuWindowTemplates);
    DeactivateAllTextPrinters();
    ScheduleBgCopyTilemapToVram(0);

    FillWindowPixelBuffer(WINDOW_1, 0);
    LoadUserWindowBorderGfx(WINDOW_1, 720, 14 * 16);
    PutWindowTilemap(WINDOW_1);
    CopyWindowToVram(WINDOW_1, 3);

    //ScheduleBgCopyTilemapToVram(2);
}

//HP Bar
//static const u8 sStartMenu_HPBar_Gfx[]              = INCBIN_U8("graphics/ui_menu/start_menu/hpbar/hp_bar.4bpp");
static const u8 sStartMenu_HPBar_Full_Gfx[]         = INCBIN_U8("graphics/ui_menu/start_menu/hpbar/hp_bar_full.4bpp");
static const u8 sStartMenu_HPBar_90_Percent_Gfx[]   = INCBIN_U8("graphics/ui_menu/start_menu/hpbar/hp_bar_90_percent.4bpp");
static const u8 sStartMenu_HPBar_80_Percent_Gfx[]   = INCBIN_U8("graphics/ui_menu/start_menu/hpbar/hp_bar_80_percent.4bpp");
static const u8 sStartMenu_HPBar_70_Percent_Gfx[]   = INCBIN_U8("graphics/ui_menu/start_menu/hpbar/hp_bar_70_percent.4bpp");
static const u8 sStartMenu_HPBar_60_Percent_Gfx[]   = INCBIN_U8("graphics/ui_menu/start_menu/hpbar/hp_bar_60_percent.4bpp");
static const u8 sStartMenu_HPBar_50_Percent_Gfx[]   = INCBIN_U8("graphics/ui_menu/start_menu/hpbar/hp_bar_50_percent.4bpp");
static const u8 sStartMenu_HPBar_40_Percent_Gfx[]   = INCBIN_U8("graphics/ui_menu/start_menu/hpbar/hp_bar_40_percent.4bpp");
static const u8 sStartMenu_HPBar_30_Percent_Gfx[]   = INCBIN_U8("graphics/ui_menu/start_menu/hpbar/hp_bar_30_percent.4bpp");
static const u8 sStartMenu_HPBar_20_Percent_Gfx[]   = INCBIN_U8("graphics/ui_menu/start_menu/hpbar/hp_bar_20_percent.4bpp");
static const u8 sStartMenu_HPBar_10_Percent_Gfx[]   = INCBIN_U8("graphics/ui_menu/start_menu/hpbar/hp_bar_10_percent.4bpp");
static const u8 sStartMenu_HPBar_Fainted_Gfx[]      = INCBIN_U8("graphics/ui_menu/start_menu/hpbar/hp_bar_fainted.4bpp");

static const u8 sText_Difficulty[] 				= _("Difficulty");
static const u8 sText_Difficulty_Easy[] 		= _("Easy");
static const u8 sText_Difficulty_Normal[] 		= _("Normal");
static const u8 sText_Difficulty_Hard[] 		= _("Hard");
static const u8 sText_Starter[] 				= _("Starter");
static const u8 sText_Starting_Area[] 			= _("Starting Area");
static const u8 sText_IVs_Mode[] 				= _("Perfect IVs");
static const u8 sText_StarterChose_Surprise[] 	= _("Surprise Me");
static const u8 sText_Mode_Enabled[] 			= _("Enabled    ");
static const u8 sText_Mode_Disabled[] 			= _("Disabled    ");

static const u8 gText_Littleroot[] 	 = _("Littleroot");
static const u8 gText_Oldale[] 		 = _("Oldale");
static const u8 gText_Petalburg[] 	 = _("Petalburg");
static const u8 gText_Rustboro[] 	 = _("Rustboro");
static const u8 gText_Dewford[] 	 = _("Dewford");
static const u8 gText_Slateport[]    = _("Slateport");
static const u8 gText_Mauville[]   	 = _("Mauville");
static const u8 gText_Fallarbor[]    = _("Fallarbor");
static const u8 gText_Fortree[]   	 = _("Fortree");
static const u8 gText_Lilycove[]   	 = _("Lilycove");
static const u8 gText_Mossdeep[]   	 = _("Mossdeep");
static const u8 gText_Sootopolis[]   = _("Sootopolis");
static const u8 gText_Pacifidlog[]   = _("Pacifidlog");

static const u8 sText_Menu_Text_Option_0[] 			= _("Pokedex");
static const u8 sText_Menu_Text_Option_1[] 			= _("Player");
static const u8 sText_Menu_Text_Option_2[] 			= _("Pokemon");
static const u8 sText_Menu_Text_Option_3[] 			= _("Feats");
static const u8 sText_Menu_Text_Option_4[] 			= _("Bag");
static const u8 sText_Menu_Text_Option_5[] 			= _("Options");
static const u8 sText_Menu_Text_Option_6[] 			= _("PokeNav");
static const u8 sText_Menu_Text_Option_7[] 			= _("DexNav");

static const u8 sText_Menu_Weekday_0[] 				= _("Sunday");
static const u8 sText_Menu_Weekday_1[] 				= _("Monday");
static const u8 sText_Menu_Weekday_2[] 				= _("Tuesday");
static const u8 sText_Menu_Weekday_3[] 				= _("Wednesday");
static const u8 sText_Menu_Weekday_4[] 				= _("Thursday");
static const u8 sText_Menu_Weekday_5[] 				= _("Friday");
static const u8 sText_Menu_Weekday_6[] 				= _("Saturday");
static const u8 sText_Menu_Weekday_7[] 				= _("Unknown");

static const u8 Time[]  =  _("{STR_VAR_1} - {STR_VAR_2}: {STR_VAR_3}$");
static const u8 Time2[] =  _("{STR_VAR_1} - {STR_VAR_2}: 0{STR_VAR_3}$");
static const u8 Steps[] =  _("{STR_VAR_1} - You have walked {STR_VAR_2} steps$");
static const u8 sText_Help_Bar_Enable[] = _("Enable");
static const u8 sText_Help_Bar_Disable[] = _("Disable");
static const u8 sText_Help_Bar_Use[] = _("Use");
static const u8 sText_Help_Bar_Unmount[] = _("Unmount");
static const u8 sText_Help_Bar[] = _("{R_BUTTON} {STR_VAR_1} Auto Run {L_BUTTON} {STR_VAR_2} Bike {SELECT_BUTTON} Save");
static const u8 sText_Auto_Run[] = _("Unknown");

static const u8 sText_Message_Cant_Save[] = _("You can't save here!.");
static const u8 sText_Message_Cant_Use_Dexnav[] = _("There are no Pokémon in this area.");
static const u8 sText_Message_Cant_Use_Bike[] = _("You can't use your bike here.");
static const u8 sText_Message_Steps_Reset[] = _("Your steps were reset.");
static const u8 sText_Message_Cant_Change_Time[] = _("You can't change the time again today.");

static void PrintToWindow(u8 windowId, u8 colorIdx)
{
	const u8 *SelectedOption;
	const u8 *SelectedOption2;
	const u8 *Weekday;
	u8 hours = gLocalTime.hours;
	u8 minutes = gLocalTime.minutes;
	bool8 gender;
	u16 steps = VarGet(VAR_FARAWAY_ISLAND_STEP_COUNTER);
	u8 x2, y2;
	u8 font = 8;
	
	u8 strArray[16];
	u8 i;
    u8 x = 0;
    u8 y = 0;
	FillWindowPixelBuffer(windowId, PIXEL_FILL(TEXT_COLOR_TRANSPARENT));
	
	if(gSaveBlock2Ptr->playerGender > 1) // 0 Male, 1 Female
        gender = gSaveBlock2Ptr->playerGender;
	
	StringCopy(&strArray[0], gSaveBlock2Ptr->playerName);
	LoadPalette(sMenuPalette, 0, 32);

	x = (sMenuDataPtr->cursorRowX * 10) + 2;
	y = (sMenuDataPtr->cursorRowY * 4) + 2;
	
	//Selection Sprite
	BlitBitmapToWindow(windowId, sStartMenuCursor_Gfx, (x*8), (y*8), 64, 24);

	//Pokedex
    x = 5;
    y = 2;
	x2 = 0;
	y2 = 4;
	//x2 = GetStringCenterAlignXOffset(font, sText_Menu_Text_Option_0, 40) + 4;
	AddTextPrinterParameterized4(windowId, font, (x*8) + x2, (y*8) + y2, 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, sText_Menu_Text_Option_0);
	
	//Trainer Name
    x = 15;
    y = 2;
	x2 = 0;
	y2 = 4;
	SelectedOption = &strArray[0];
	//x2 = GetStringCenterAlignXOffset(font, SelectedOption, 40) + 4;
	AddTextPrinterParameterized4(windowId, font, (x*8) + x2, (y*8) + y2, 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, SelectedOption);
	
	//Pokemon
    x = 5;
    y = 6;
	x2 = 0;
	y2 = 4;
	//x2 = GetStringCenterAlignXOffset(font, sText_Menu_Text_Option_0, 40) + 4;
	AddTextPrinterParameterized4(windowId, font, (x*8) + x2, (y*8) + y2, 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, sText_Menu_Text_Option_2);
	
	//Save
    x = 15;
    y = 6;
	x2 = 0;
	y2 = 4;
	//x2 = GetStringCenterAlignXOffset(font, sText_Menu_Text_Option_3, 40) + 4;
	AddTextPrinterParameterized4(windowId, font, (x*8) + x2, (y*8) + y2, 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, sText_Menu_Text_Option_3);
	
	//Bag
    x = 5;
    y = 10;
	x2 = 0;
	y2 = 4;
	//x2 = GetStringCenterAlignXOffset(font, sText_Menu_Text_Option_0, 40) + 4;
	AddTextPrinterParameterized4(windowId, font, (x*8) + x2, (y*8) + y2, 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, sText_Menu_Text_Option_4);
	
	//Options
    x = 15;
    y = 10;
	x2 = 0;
	y2 = 4;
	//x2 = GetStringCenterAlignXOffset(font, sText_Menu_Text_Option_3, 40) + 4;
	AddTextPrinterParameterized4(windowId, font, (x*8) + x2, (y*8) + y2, 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, sText_Menu_Text_Option_5);
	
	//Pokenav
    x = 5;
    y = 14;
	x2 = 0;
	y2 = 4;
	//x2 = GetStringCenterAlignXOffset(font, sText_Menu_Text_Option_0, 40) + 4;
	AddTextPrinterParameterized4(windowId, font, (x*8) + x2, (y*8) + y2, 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, sText_Menu_Text_Option_6);
	
	//Dexnav
    x = 15;
    y = 14;
	x2 = 0;
	y2 = 4;
	//x2 = GetStringCenterAlignXOffset(font, sText_Menu_Text_Option_3, 40) + 4;
	AddTextPrinterParameterized4(windowId, font, (x*8) + x2, (y*8) + y2, 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, sText_Menu_Text_Option_7);
	
	if(gLocalTime.dayOfWeek > 6)
		RtcSetDayOfWeek(0);
	
	switch(gLocalTime.dayOfWeek){
	case 0:		
		Weekday  = sText_Menu_Weekday_0;
	break;
    case 1:		
		Weekday  = sText_Menu_Weekday_1;
	break;
	case 2:		
		Weekday  = sText_Menu_Weekday_2;
	break;
	case 3:		
		Weekday  = sText_Menu_Weekday_3;	
	break;
	case 4:		
		Weekday  = sText_Menu_Weekday_4;	
	break;
	case 5:		
		Weekday  = sText_Menu_Weekday_5;	
	break;
	case 6:		
		Weekday  = sText_Menu_Weekday_6;	
	break;
	default:
		Weekday  = sText_Menu_Weekday_7;
	break;
	}
	
	//Help Bar
	x = 0;
    y = 18;
	switch(sMenuDataPtr->CurrentMessage){
		case MESSAGE_HELP_BAR:
			ConvertIntToDecimalStringN(gStringVar2, hours, STR_CONV_MODE_RIGHT_ALIGN, 2);
			ConvertIntToDecimalStringN(gStringVar3, minutes, STR_CONV_MODE_LEFT_ALIGN, 2);
			if(!FlagGet(FLAG_SYS_AUTO_RUN))
				StringCopy(gStringVar1, sText_Help_Bar_Enable);
			else
				StringCopy(gStringVar1, sText_Help_Bar_Disable);

			if((gPlayerAvatar.flags & PLAYER_AVATAR_FLAG_MACH_BIKE) || (gPlayerAvatar.flags & PLAYER_AVATAR_FLAG_ACRO_BIKE))
				StringCopy(gStringVar2, sText_Help_Bar_Unmount);
			else
				StringCopy(gStringVar2, sText_Help_Bar_Use);

			StringExpandPlaceholders(gStringVar4, sText_Help_Bar);

			AddTextPrinterParameterized4(windowId, font, (x*8)+4, (y*8), 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, gStringVar4);
		break;
		case MESSAGE_CANT_SAVE:
			AddTextPrinterParameterized4(windowId, font, (x*8)+4, (y*8), 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, sText_Message_Cant_Save);
		break;
		case MESSAGE_CANT_USE_BIKE:
			AddTextPrinterParameterized4(windowId, font, (x*8)+4, (y*8), 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, sText_Message_Cant_Use_Bike);
		break;
		case MESSAGE_CANT_USE_DEXNAV:
			AddTextPrinterParameterized4(windowId, font, (x*8)+4, (y*8), 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, sText_Message_Cant_Use_Dexnav);
		break;
		case MESSAGE_CANT_CHANGE_TIME:
			AddTextPrinterParameterized4(windowId, font, (x*8)+4, (y*8), 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, sText_Message_Cant_Change_Time);
		break;
		case MESSAGE_STEPS_RESET:
			AddTextPrinterParameterized4(windowId, font, (x*8)+4, (y*8), 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, sText_Message_Steps_Reset);
		break;
	}

	//Time
	x = 0;
    y = 0;
	x2 = 4;
	StringCopy(gStringVar1, Weekday);
	ConvertIntToDecimalStringN(gStringVar2, hours, STR_CONV_MODE_RIGHT_ALIGN, 2);
	ConvertIntToDecimalStringN(gStringVar3, minutes, STR_CONV_MODE_LEFT_ALIGN, 2);

	if(minutes >= 10)
		StringExpandPlaceholders(gStringVar4, Time);
	else
		StringExpandPlaceholders(gStringVar4, Time2);

	//StringCopy(gStringVar1, gStringVar4);
	//ConvertIntToDecimalStringN(gStringVar2, steps, STR_CONV_MODE_RIGHT_ALIGN, 4);
	//StringExpandPlaceholders(gStringVar4, Steps);

	AddTextPrinterParameterized4(windowId, font, (x*8) + x2, (y*8), 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, gStringVar4);

	// HP Bars --------------------------------------------------------------------------------------------------------
    x = ICON_STARTING_X - 8;
	x2 = 0;
    y = ICON_STARTING_Y + 16;
	y2 = 0;

    for(i = 0; i < PARTY_SIZE; i++){
        if(GetMonData(&gPlayerParty[i], MON_DATA_SPECIES) != SPECIES_NONE){
            u16 maxHP = GetMonData(&gPlayerParty[i], MON_DATA_MAX_HP);
            u16 currentHP = GetMonData(&gPlayerParty[i], MON_DATA_HP);

            if(maxHP == currentHP)
                BlitBitmapToWindow(windowId, sStartMenu_HPBar_Full_Gfx,       (x + x2), (y + y2), 24, 8);
            else if((maxHP * 0.9) < currentHP && currentHP < maxHP)
                BlitBitmapToWindow(windowId, sStartMenu_HPBar_90_Percent_Gfx, (x + x2), (y + y2), 24, 8);
            else if((maxHP * 0.8) < currentHP && currentHP < (maxHP * 0.9))
                BlitBitmapToWindow(windowId, sStartMenu_HPBar_80_Percent_Gfx, (x + x2), (y + y2), 24, 8);
            else if((maxHP * 0.7) < currentHP && currentHP < (maxHP * 0.8))
                BlitBitmapToWindow(windowId, sStartMenu_HPBar_70_Percent_Gfx, (x + x2), (y + y2), 24, 8);
            else if((maxHP * 0.6) < currentHP && currentHP < (maxHP * 0.7))
                BlitBitmapToWindow(windowId, sStartMenu_HPBar_60_Percent_Gfx, (x + x2), (y + y2), 24, 8);
            else if((maxHP * 0.5) < currentHP && currentHP < (maxHP * 0.6))
                BlitBitmapToWindow(windowId, sStartMenu_HPBar_50_Percent_Gfx, (x + x2), (y + y2), 24, 8);
            else if((maxHP * 0.4) < currentHP && currentHP < (maxHP * 0.5))
                BlitBitmapToWindow(windowId, sStartMenu_HPBar_40_Percent_Gfx, (x + x2), (y + y2), 24, 8);
            else if((maxHP * 0.3) < currentHP && currentHP < (maxHP * 0.4))
                BlitBitmapToWindow(windowId, sStartMenu_HPBar_30_Percent_Gfx, (x + x2), (y + y2), 24, 8);
            else if((maxHP * 0.2) < currentHP && currentHP < (maxHP * 0.3))
                BlitBitmapToWindow(windowId, sStartMenu_HPBar_20_Percent_Gfx, (x + x2), (y + y2), 24, 8);
            else if(currentHP != 0)
                BlitBitmapToWindow(windowId, sStartMenu_HPBar_10_Percent_Gfx, (x + x2), (y + y2), 24, 8);
            else
                BlitBitmapToWindow(windowId, sStartMenu_HPBar_Fainted_Gfx,    (x + x2), (y + y2), 24, 8);
        }
        //y = y + 3;
		if(i % 2 == 0){
			x2 = X_DIFFERENCE_BETWEEN_SPECIES;
		}
		else{
			x2 = 0;
			y2 = y2 + Y_DIFFERENCE_BETWEEN_SPECIES;
		}
    }
	
    CopyWindowToVram(windowId, 3);
	PutWindowTilemap(windowId);
}

static u8 ShowSpeciesIcon(u8 slot, u8 x, u8 y)
{
	u16 species = GetMonData(&gPlayerParty[slot], MON_DATA_SPECIES);
	u16 formID = GetMonData(&gPlayerParty[slot], MON_DATA_FORM_ID);
	u16 speciesID = GetFormSpeciesId(species, formID);
	u32 personality = GetMonData(&gPlayerParty[slot], MON_DATA_PERSONALITY);
	if (SpeciesHasGenderDifference[species] && GetGenderFromSpeciesAndPersonality(species, personality) == MON_FEMALE)
		LoadFemaleMonIconPalette(speciesID);
	else
		LoadMonIconPalette(speciesID);

    switch(slot){
        case 0:
            sMenuDataPtr->PartyPokemonIcon_0 = CreateMonIcon(GetMonData(&gPlayerParty[slot], MON_DATA_SPECIES), SpriteCB_MonIcon, x, y, 0, personality, formID);
            
			gSprites[sMenuDataPtr->PartyPokemonIcon_0].invisible = FALSE;
            return sMenuDataPtr->PartyPokemonIcon_0;
        break;
        case 1:
            sMenuDataPtr->PartyPokemonIcon_1 = CreateMonIcon(GetMonData(&gPlayerParty[slot], MON_DATA_SPECIES), SpriteCB_MonIcon, x, y, 0, personality, formID);

            gSprites[sMenuDataPtr->PartyPokemonIcon_1].invisible = FALSE;
            return sMenuDataPtr->PartyPokemonIcon_1;
        break;
        case 2:
            sMenuDataPtr->PartyPokemonIcon_2 = CreateMonIcon(GetMonData(&gPlayerParty[slot], MON_DATA_SPECIES), SpriteCB_MonIcon, x, y, 0, personality, formID);

            gSprites[sMenuDataPtr->PartyPokemonIcon_2].invisible = FALSE;
            return sMenuDataPtr->PartyPokemonIcon_2;
        break;
        case 3:
            sMenuDataPtr->PartyPokemonIcon_3 = CreateMonIcon(GetMonData(&gPlayerParty[slot], MON_DATA_SPECIES), SpriteCB_MonIcon, x, y, 0, personality, formID);

            gSprites[sMenuDataPtr->PartyPokemonIcon_3].invisible = FALSE;
            return sMenuDataPtr->PartyPokemonIcon_3;
        break;
        case 4:
            sMenuDataPtr->PartyPokemonIcon_4 = CreateMonIcon(GetMonData(&gPlayerParty[slot], MON_DATA_SPECIES), SpriteCB_MonIcon, x, y, 0, personality, formID);

            gSprites[sMenuDataPtr->PartyPokemonIcon_4].invisible = FALSE;
            return sMenuDataPtr->PartyPokemonIcon_4;
        break;
        case 5:
            sMenuDataPtr->PartyPokemonIcon_5 = CreateMonIcon(GetMonData(&gPlayerParty[slot], MON_DATA_SPECIES), SpriteCB_MonIcon, x, y, 0, personality, formID);

            gSprites[sMenuDataPtr->PartyPokemonIcon_5].invisible = FALSE;
            return sMenuDataPtr->PartyPokemonIcon_5;
        break;
    }
}

static void Task_MenuWaitFadeIn(u8 taskId)
{
    if (!gPaletteFade.active)
        gTasks[taskId].func = Task_MenuMain;
}

static void Task_MenuTurnOff(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    if (!gPaletteFade.active)
    {
        SetMainCallback2(sMenuDataPtr->savedCallback);
        Menu_FreeResources();
        DestroyTask(taskId);
    }
}

void Task_OpenPokedexFromStartMenu(u8 taskId)
{
    if (!gPaletteFade.active)
    {
		Menu_FreeResources();
		IncrementGameStat(GAME_STAT_CHECKED_POKEDEX);
		PlayRainStoppingSoundEffect();
		CleanupOverworldWindowsAndTilemaps();
		SetMainCallback2(CB2_OpenPokedex);
		DestroyTask(taskId);
    }
}

void Task_OpenPokemonPartyFromStartMenu(u8 taskId)
{
    if (!gPaletteFade.active)
    {
		Menu_FreeResources();
		PlayRainStoppingSoundEffect();
		CleanupOverworldWindowsAndTilemaps();
		SetMainCallback2(CB2_PartyMenuFromStartMenu); // Display party menu
    }
}

void Task_OpenTrainerCardFromStartMenu(u8 taskId)
{
	if (!gPaletteFade.active)
    {
		Menu_FreeResources();
		PlayRainStoppingSoundEffect();
		CleanupOverworldWindowsAndTilemaps();
		
		if (InUnionRoom())
			ShowPlayerTrainerCard(CB2_ReturnToUIMenu); // Display trainer card
		else if (FlagGet(FLAG_SYS_FRONTIER_PASS))
			ShowFrontierPass(CB2_ReturnToUIMenu); // Display frontier pass
		else
			ShowPlayerTrainerCard(CB2_ReturnToUIMenu); // Display trainer card
    }
}

void Task_OpenBagFromStartMenu(u8 taskId)
{
    if (!gPaletteFade.active)
    {
		Menu_FreeResources();
		PlayRainStoppingSoundEffect();
		CleanupOverworldWindowsAndTilemaps();
		SetMainCallback2(CB2_BagMenuFromStartMenu); // Display bag menu
    }
}

void Task_OpenOptionsMenuStartMenu(u8 taskId)
{
    if (!gPaletteFade.active)
    {
		Menu_FreeResources();
		PlayRainStoppingSoundEffect();
        CleanupOverworldWindowsAndTilemaps();
        SetMainCallback2(CB2_InitOptionMenu); // Display option menu
        gMain.savedCallback = CB2_ReturnToField;
    }
}

void Task_OpenPokenavStartMenu(u8 taskId)
{
    if (!gPaletteFade.active)
    {
		Menu_FreeResources();
		PlayRainStoppingSoundEffect();
		CleanupOverworldWindowsAndTilemaps();
		SetMainCallback2(CB2_InitPokeNav);  // Display PokeNav
    }
}  

void Task_OpenSaveMenuStartMenu(u8 taskId)
{
    if (!gPaletteFade.active)
    {
		//PlayRainStoppingSoundEffect();
		//CleanupOverworldWindowsAndTilemaps();
		Menu_FreeResources();
		SetMainCallback2(CB2_ReturnToFieldWithOpenMenu);
    }
}

void Task_ChangeTrainerName(u8 taskId)
{
	Menu_FreeResources();
    if (!gPaletteFade.active)
    {
		NewGameBirchSpeech_SetDefaultPlayerName(Random() % 20);
		DoNamingScreen(0, gSaveBlock2Ptr->playerName, gSaveBlock2Ptr->playerGender, 0, 0, CB2_ReturnToField, 0);
    }
}

void Task_ChangeTime(u8 taskId)
{
	Menu_FreeResources();
    if (!gPaletteFade.active)
    {
		SetMainCallback2(CB2_StartWallClock);
		gMain.savedCallback = CB2_ReturnToField;

		//NewGameBirchSpeech_SetDefaultPlayerName(Random() % 20);
		//DoNamingScreen(0, gSaveBlock2Ptr->playerName, gSaveBlock2Ptr->playerGender, 0, 0, CB2_ReturnToField, 0);
    }
}

static bool8 QuestMenuCallback(void)
{
    CreateTask(Task_OpenQuestMenuFromStartMenu, 0);
    return TRUE;
}

/* This is the meat of the UI. This is where you wait for player inputs and can branch to other tasks accordingly */
static void Task_MenuMain(u8 taskId)
{
	
	u8 sStartMenuCursorPos = ((sMenuDataPtr->cursorRowY)*(sMenuDataPtr->cursorRowX+1))-1;
	bool8 DisableSave = FALSE;
	sMenuDataPtr->CurrentMessage = MESSAGE_HELP_BAR;

	VarSet(VAR_START_MENU_CURSOR_Y, sMenuDataPtr->cursorRowY);
	VarSet(VAR_START_MENU_CURSOR_X, sMenuDataPtr->cursorRowX);

	SetOutBreakPokemonFromCompanion();
	SetRoamerPokemonFromCompanion();
	
	if ((JOY_HELD(START_BUTTON)) && JOY_NEW(R_BUTTON))
    {
		//Change Player's Time
		if(!FlagGet(FLAG_CHANGED_TIME)){
			FlagSet(FLAG_CHANGED_TIME);
			PlaySE(SE_SELECT);
			BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 16, RGB_BLACK);
			gTasks[taskId].func = Task_ChangeTime;
		}
		else{
			sMenuDataPtr->CurrentMessage = MESSAGE_CANT_CHANGE_TIME;
			PlaySE(SE_BOO);
			PrintToWindow(WINDOW_1, FONT_BLACK);
		}
    }

	if ((JOY_HELD(START_BUTTON)) && JOY_NEW(L_BUTTON))
    {
		//Reset Steps
		/*PlaySE(SE_SELECT);
		VarSet(VAR_FARAWAY_ISLAND_STEP_COUNTER, 0);
		sMenuDataPtr->CurrentMessage = MESSAGE_STEPS_RESET;
		PrintToWindow(WINDOW_1, FONT_BLACK);*/

		//Change Player Name
		PlaySE(SE_SELECT);
		BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 16, RGB_BLACK);
		gTasks[taskId].func = Task_ChangeTrainerName;
    }
	
	if (JOY_NEW(B_BUTTON))
    {
		//Konami Code
		if(sMenuDataPtr->KonamiCodeState == 8){
			sMenuDataPtr->KonamiCodeState++;
		}
		else{
			sMenuDataPtr->KonamiCodeState = 0;
			PlaySE(SE_PC_OFF);
			BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 16, RGB_BLACK);
			gTasks[taskId].func = Task_MenuTurnOff;
		}
		PrintToWindow(WINDOW_1, FONT_BLACK);
    }
	
	if (JOY_NEW(A_BUTTON))
    {
		//Konami Code
		if(sMenuDataPtr->KonamiCodeState == 9){
			sMenuDataPtr->KonamiCodeState++;
			sMenuDataPtr->KonamiCodeState = 0;
			//Change Player Name
			PlaySE(SE_SELECT);
			BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 16, RGB_BLACK);
			gTasks[taskId].func = Task_ChangeTrainerName;
		}
		else{
		switch(sMenuDataPtr->cursorRowY)
		{
			case 0:
			if(sMenuDataPtr->cursorRowX == 0){
				//Pokedex
				PlaySE(SE_SELECT);
				BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 16, RGB_BLACK);
				gTasks[taskId].func = Task_OpenPokedexFromStartMenu;
			}
			else{
				//Player Info
                PlaySE(SE_SELECT);
                BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 16, RGB_BLACK);
                gTasks[taskId].func = Task_OpenTrainerCardFromStartMenu;
			}
			break;
			case 1:
			if(sMenuDataPtr->cursorRowX == 0){
				//Pokemon
				PlaySE(SE_SELECT);
				BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 16, RGB_BLACK);
				gTasks[taskId].func = Task_OpenPokemonPartyFromStartMenu;
			}
			else{
				//Achievements
				PlaySE(SE_SELECT);
				BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 16, RGB_BLACK);
				gTasks[taskId].func = Task_OpenQuestMenuFromStartMenu;
			}
			break;
			case 2:
			if(sMenuDataPtr->cursorRowX == 0){
				//Bag
				PlaySE(SE_SELECT);
				BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 16, RGB_BLACK);
				gTasks[taskId].func = Task_OpenBagFromStartMenu;
			}
			else{
				//Options
				PlaySE(SE_SELECT);
				BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 16, RGB_BLACK);
				gTasks[taskId].func = Task_OpenOptionsMenuStartMenu;
			}
			break;
			case 3:
			if(sMenuDataPtr->cursorRowX == 0){
				//Pokenav
				PlaySE(SE_SELECT);
				BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 16, RGB_BLACK);
				gTasks[taskId].func = Task_OpenPokenavStartMenu;
			}
			else
				if(HasMapMons()){
					PlaySE(SE_SELECT);
					BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 16, RGB_BLACK);
					gTasks[taskId].func = Task_OpenDexNavFromStartMenu;
				}
				else{
					PlaySE(SE_BOO);
					sMenuDataPtr->CurrentMessage = MESSAGE_CANT_USE_DEXNAV;
				}
			break;
		}
		
		if (sMenuDataPtr->cursorRowX != 1 && sMenuDataPtr->cursorRowY != 1)
        {
           FadeScreen(FADE_TO_BLACK, 0);
        }
		}
		PrintToWindow(WINDOW_1, FONT_BLACK);
	}
	
	if (!(JOY_HELD(START_BUTTON)) && JOY_NEW(R_BUTTON)){
		
		if (FlagGet(FLAG_SYS_AUTO_RUN)){
			FlagClear(FLAG_SYS_AUTO_RUN);
			PlaySE(SE_BOO);
		}
		else{
			FlagSet(FLAG_SYS_AUTO_RUN);
			PlaySE(SE_SELECT);
		}
		PrintToWindow(WINDOW_1, FONT_BLACK);
	}
	
	if (JOY_NEW(SELECT_BUTTON)){
		switch(gSaveBlock1Ptr->location.mapNum){
			case MAP_NUM(EVER_GRANDE_CITY_SIDNEYS_ROOM):
				if(gSaveBlock1Ptr->location.mapGroup == MAP_GROUP(EVER_GRANDE_CITY_SIDNEYS_ROOM))
					DisableSave = TRUE;
			break;
			case MAP_NUM(EVER_GRANDE_CITY_PHOEBES_ROOM):
				if(gSaveBlock1Ptr->location.mapGroup == MAP_GROUP(EVER_GRANDE_CITY_PHOEBES_ROOM))
					DisableSave = TRUE;
			break;
			case MAP_NUM(EVER_GRANDE_CITY_GLACIAS_ROOM):
				if(gSaveBlock1Ptr->location.mapGroup == MAP_GROUP(EVER_GRANDE_CITY_GLACIAS_ROOM))
					DisableSave = TRUE;
			break;
			case MAP_NUM(EVER_GRANDE_CITY_DRAKES_ROOM):
				if(gSaveBlock1Ptr->location.mapGroup == MAP_GROUP(EVER_GRANDE_CITY_DRAKES_ROOM))
					DisableSave = TRUE;
			break;
			case MAP_NUM(EVER_GRANDE_CITY_CHAMPIONS_ROOM):
				if(gSaveBlock1Ptr->location.mapGroup == MAP_GROUP(EVER_GRANDE_CITY_CHAMPIONS_ROOM))
					DisableSave = TRUE;
			break;
			case MAP_NUM(EVER_GRANDE_CITY_HALL1):
				if(gSaveBlock1Ptr->location.mapGroup == MAP_GROUP(EVER_GRANDE_CITY_HALL1))
					DisableSave = TRUE;
			break;
			case MAP_NUM(EVER_GRANDE_CITY_HALL2):
				if(gSaveBlock1Ptr->location.mapGroup == MAP_GROUP(EVER_GRANDE_CITY_HALL2))
					DisableSave = TRUE;
			break;
			case MAP_NUM(EVER_GRANDE_CITY_HALL3):
				if(gSaveBlock1Ptr->location.mapGroup == MAP_GROUP(EVER_GRANDE_CITY_HALL3))
					DisableSave = TRUE;
			break;
			case MAP_NUM(EVER_GRANDE_CITY_HALL4):
				if(gSaveBlock1Ptr->location.mapGroup == MAP_GROUP(EVER_GRANDE_CITY_HALL4))
					DisableSave = TRUE;
			break;
			case MAP_NUM(EVER_GRANDE_CITY_HALL5):
				if(gSaveBlock1Ptr->location.mapGroup == MAP_GROUP(EVER_GRANDE_CITY_HALL5))
					DisableSave = TRUE;
			break;
			}
				
			if((!DisableSave || !FlagGet(FLAG_HARD_MODE)) && !FlagGet(FLAG_BUG_TESTER)){
				PlaySE(SE_SELECT);
				BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 16, RGB_BLACK);
				gTasks[taskId].func = Task_OpenSaveMenuStartMenu;
			}
			else{
				PlaySE(SE_BOO);
				sMenuDataPtr->CurrentMessage = MESSAGE_CANT_SAVE;
			}
				
	}
	
	if (!(JOY_HELD(START_BUTTON)) && JOY_NEW(L_BUTTON)){
		s16 coordsY;
		s16 coordsX;
		u8 behavior;
		PlayerGetDestCoords(&coordsX, &coordsY);
		behavior = MapGridGetMetatileBehaviorAt(coordsX, coordsY);
		if (FlagGet(FLAG_SYS_CYCLING_ROAD) == TRUE || MetatileBehavior_IsVerticalRail(behavior) == TRUE || MetatileBehavior_IsHorizontalRail(behavior) == TRUE || MetatileBehavior_IsIsolatedVerticalRail(behavior) == TRUE || MetatileBehavior_IsIsolatedHorizontalRail(behavior) == TRUE){
			PlaySE(SE_BOO);
			sMenuDataPtr->CurrentMessage = MESSAGE_CANT_USE_BIKE;
		}
		else if(!IsBikingDisallowedByPlayer()){
			BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 16, RGB_BLACK);

			if (gSaveBlock2Ptr->optionsBikeType == 0)
				GetOnOffBike(PLAYER_AVATAR_FLAG_MACH_BIKE);
			else
				GetOnOffBike(PLAYER_AVATAR_FLAG_ACRO_BIKE);
			POF_FollowMe_HandleBike(); //tx_pokemon_follower
			ScriptUnfreezeObjectEvents();
			ScriptContext2_Disable();
			gTasks[taskId].func = Task_MenuTurnOff;
		}
		else{
			PlaySE(SE_BOO);
			sMenuDataPtr->CurrentMessage = MESSAGE_CANT_USE_BIKE;
		}
		PrintToWindow(WINDOW_1, FONT_BLACK);
	}
	
	if (JOY_NEW(DPAD_DOWN)){
		//Konami Code
		if(sMenuDataPtr->KonamiCodeState == 2 || sMenuDataPtr->KonamiCodeState == 3)
			sMenuDataPtr->KonamiCodeState++;
		else
			sMenuDataPtr->KonamiCodeState = 0;
		//-----------------------------
		if(sMenuDataPtr->cursorRowY < NUM_ROWS_Y-1)
			sMenuDataPtr->cursorRowY++;
		else
			sMenuDataPtr->cursorRowY = 0;
		//-----------------------------
		PlaySE(SE_SELECT);
		PrintToWindow(WINDOW_1, FONT_BLACK);
	}
	
	if (JOY_NEW(DPAD_UP)){
		//Konami Code
		if(sMenuDataPtr->KonamiCodeState == 0 || sMenuDataPtr->KonamiCodeState == 1){
			sMenuDataPtr->KonamiCodeState++;
		}
		else
			sMenuDataPtr->KonamiCodeState = 0;
		
		//-----------------------------
		if(sMenuDataPtr->cursorRowY > 0)
			sMenuDataPtr->cursorRowY--;
		else
			sMenuDataPtr->cursorRowY = NUM_ROWS_Y-1;
		//-----------------------------
		PlaySE(SE_SELECT);	
		PrintToWindow(WINDOW_1, FONT_BLACK);
	}
	
	if(JOY_NEW(DPAD_RIGHT))
	{
		//Konami Code
		if(sMenuDataPtr->KonamiCodeState == 5 || sMenuDataPtr->KonamiCodeState == 7){
			sMenuDataPtr->KonamiCodeState++;
		}
		else
			sMenuDataPtr->KonamiCodeState = 0;
		if(sMenuDataPtr->cursorRowX < NUM_ROWS_X-1)
			sMenuDataPtr->cursorRowX++;
		else
			sMenuDataPtr->cursorRowX = 0;
		//-----------------------------
		PlaySE(SE_SELECT);
		PrintToWindow(WINDOW_1, FONT_BLACK);
	}
	
	if(JOY_NEW(DPAD_LEFT))
	{
		//Konami Code
		if(sMenuDataPtr->KonamiCodeState == 4 || sMenuDataPtr->KonamiCodeState == 6){
			sMenuDataPtr->KonamiCodeState++;
		}
		else
			sMenuDataPtr->KonamiCodeState = 0;
		
		//-----------------------------
		if(sMenuDataPtr->cursorRowX > 0)
			sMenuDataPtr->cursorRowX--;
		else
			sMenuDataPtr->cursorRowX = NUM_ROWS_X-1;
		//-----------------------------
		PlaySE(SE_SELECT);
		PrintToWindow(WINDOW_1, FONT_BLACK);
	}

	//Scroll Background
	ChangeBgX(SCROLLING_BACKGROUND_NUM, 128, 1);
    ChangeBgY(SCROLLING_BACKGROUND_NUM, 128, 2);
}