#include "global.h"
#include "option_menu.h"
#include "option_plus_menu.h"
#include "main.h"
#include "menu.h"
#include "scanline_effect.h"
#include "palette.h"
#include "sprite.h"
#include "sound.h"
#include "string_util.h"
#include "task.h"
#include "malloc.h"
#include "bg.h"
#include "gpu_regs.h"
#include "window.h"
#include "text.h"
#include "text_window.h"
#include "overworld.h"
#include "international_string_util.h"
#include "strings.h"
#include "gba/m4a_internal.h"
#include "constants/rgb.h"

#define useOptionPlusMenu TRUE

#define Y_DIFF 16 // Difference in pixels between items.


// Menu items page 1
enum
{
    MENUITEM_TEXTSPEED,
    MENUITEM_BATTLESCENE,
    MENUITEM_BATTLESTYLE,
	MENUITEM_MUSIC,
    MENUITEM_SOUND,
    MENUITEM_TITLE_SCREEN,
    MENUITEM_FRAMETYPE,
    MENUITEM_HP_BAR,
    MENUITEM_EXP_BAR,
    MENUITEM_TRANSITION,
	MENUITEM_SHOW_DAMAGE,
	MENUITEM_CAP_COLOR_R,
	MENUITEM_CAP_COLOR_G,
	MENUITEM_CAP_COLOR_B,
	MENUITEM_AUTOMATIC_FOLLOWER,
	MENUITEM_GENERIC_CRY,
	MENUITEM_BIKE_TYPE,
	//MENUITEM_MGBA_MODE,
    MENUITEM_CANCEL,
    MENUITEM_COUNT,
};

// Window Ids
enum
{
    WIN_TEXT_OPTION,
    WIN_OPTIONS
};

struct OptionMenu
{
    u8 sel[MENUITEM_COUNT];
    int menuCursor;
    int visibleCursor;
};

// this file's functions
static void Task_OptionMenuFadeIn(u8 taskId);
static void Task_OptionMenuProcessInput(u8 taskId);
static void Task_OptionMenuSave(u8 taskId);
static void Task_OptionMenuFadeOut(u8 taskId);
static void HighlightOptionMenuItem(int cursor);
static void TextSpeed_DrawChoices(int selection, int y, u8 textSpeed);
static void BattleScene_DrawChoices(int selection, int y, u8 textSpeed);
static void BikeTypes_DrawChoices(int selection, int y, u8 textSpeed);
static void MgbaMode_DrawChoices(int selection, int y, u8 textSpeed);
static void BattleStyle_DrawChoices(int selection, int y, u8 textSpeed);
static void Music_DrawChoices(int selection, int y, u8 textSpeed);//Music Expansion
static void HpBar_DrawChoices(int selection, int y, u8 textSpeed);
static void RGB_DrawChoices(int selection, int y, u8 textSpeed);
static void CapColor_DrawChoices(int selection, int y, u8 textSpeed);
static void HairColor_DrawChoices(int selection, int y, u8 textSpeed);
static void Transition_DrawChoices(int selection, int y, u8 textSpeed);
static void UnitSystem_DrawChoices(int selection, int y, u8 textSpeed);
static void TitleScreen_DrawChoices(int selection, int y, u8 textSpeed);
static void Sound_DrawChoices(int selection, int y, u8 textSpeed);
static void FrameType_DrawChoices(int selection, int y, u8 textSpeed);
static void ButtonMode_DrawChoices(int selection, int y, u8 textSpeed);
static int FrameType_ProcessInput(int selection);
static int Music_ProcessInput(int selection);//Music Expansion
static int FourOptions_ProcessInput(int selection);
static int ThreeOptions_ProcessInput(int selection);
static int TwoOptions_ProcessInput(int selection);
static int BattleStyle_ProcessInput(int selection);
static int ElevenOptions_ProcessInput(int selection);
static int ColorOptions_ProcessInput(int selection);
static int Sound_ProcessInput(int selection);
static void DrawTextOption(void);
static void DrawOptionMenuTexts(void);
static void sub_80BB154(void);

struct
{
    void (*drawChoices)(int selection, int y, u8 textSpeed);
    int (*processInput)(int selection);
} static const sItemFunctions[MENUITEM_COUNT] =
{
    [MENUITEM_TEXTSPEED] 		    = {TextSpeed_DrawChoices, FourOptions_ProcessInput},
    [MENUITEM_BATTLESCENE] 		    = {BattleScene_DrawChoices, TwoOptions_ProcessInput},
    [MENUITEM_BATTLESTYLE] 		    = {BattleStyle_DrawChoices, BattleStyle_ProcessInput},
    [MENUITEM_MUSIC] 			    = {Music_DrawChoices, Music_ProcessInput},
    [MENUITEM_SOUND] 			    = {Sound_DrawChoices, Sound_ProcessInput},
    [MENUITEM_TITLE_SCREEN] 	    = {TitleScreen_DrawChoices, ThreeOptions_ProcessInput},
    [MENUITEM_FRAMETYPE] 		    = {FrameType_DrawChoices, FrameType_ProcessInput},
    [MENUITEM_HP_BAR] 			    = {HpBar_DrawChoices, ElevenOptions_ProcessInput},
    [MENUITEM_EXP_BAR] 			    = {HpBar_DrawChoices, ElevenOptions_ProcessInput},
    [MENUITEM_TRANSITION] 		    = {Transition_DrawChoices, TwoOptions_ProcessInput},
	[MENUITEM_SHOW_DAMAGE] 	        = {BattleScene_DrawChoices, TwoOptions_ProcessInput},
	[MENUITEM_CAP_COLOR_R]   	    = {RGB_DrawChoices, ColorOptions_ProcessInput},
	[MENUITEM_CAP_COLOR_G]  	    = {RGB_DrawChoices, ColorOptions_ProcessInput},
	[MENUITEM_CAP_COLOR_B] 		    = {RGB_DrawChoices, ColorOptions_ProcessInput},
	[MENUITEM_AUTOMATIC_FOLLOWER] 	= {BattleScene_DrawChoices, TwoOptions_ProcessInput},
	[MENUITEM_GENERIC_CRY] 	        = {BattleScene_DrawChoices, TwoOptions_ProcessInput},
	[MENUITEM_BIKE_TYPE] 	        = {BikeTypes_DrawChoices, TwoOptions_ProcessInput},
	//[MENUITEM_MGBA_MODE] 	        = {MgbaMode_DrawChoices, TwoOptions_ProcessInput},
    [MENUITEM_CANCEL] = {NULL, NULL},
};

// EWRAM vars
EWRAM_DATA static struct OptionMenu *sOptions = NULL;

// const rom data
static const u16 sUnknown_0855C604[] = INCBIN_U16("graphics/misc/option_menu_text.gbapal");
// note: this is only used in the Japanese release
static const u8 sEqualSignGfx[] = INCBIN_U8("graphics/misc/option_menu_equals_sign.4bpp");
static const u8 sText_HpBar[] = _("Hp Bar Speed");
static const u8 sText_ExpBar[] = _("Exp Bar Speed");
static const u8 sText_Transition[] = _("Transition");
static const u8 sText_Custom_Cap_Color[] = _("Cap Color");
static const u8 sText_UnitSystem[] = _("Unit System");
static const u8 sText_Cap_Color_Red[]   = _("Red Color");
static const u8 sText_Cap_Color_Green[] = _("Green Color");
static const u8 sText_Cap_Color_Blue[]  = _("Blue Color");
static const u8 sText_Automatic_Follower[]  = _("Auto Follower");
static const u8 sText_Show_Damage_Done[] = _("Show Damage Done");
static const u8 sText_Use_Generic_Cry[] = _("Use a Generic Cry");
static const u8 sText_Bike_Type[] = _("Bike Type");
static const u8 sText_Mgba_Mode[] = _("Mgba Mode");

static const u8 *const sOptionMenuItemsNames[MENUITEM_COUNT] =
{
    [MENUITEM_TEXTSPEED]           = gText_TextSpeed,
    [MENUITEM_BATTLESCENE]         = gText_BattleScene,
    [MENUITEM_BATTLESTYLE]         = gText_BattleStyle,
    [MENUITEM_MUSIC]               = gText_Region_BGM,
    [MENUITEM_SOUND]               = gText_Sound,
    [MENUITEM_TITLE_SCREEN]        = gText_ButtonMode,
    [MENUITEM_FRAMETYPE]           = gText_Frame,
    [MENUITEM_HP_BAR]              = sText_HpBar,
    [MENUITEM_EXP_BAR]             = sText_ExpBar,
    [MENUITEM_TRANSITION]          = sText_Transition,
	[MENUITEM_SHOW_DAMAGE]         = sText_Show_Damage_Done,
	[MENUITEM_CAP_COLOR_R]  	   = sText_Cap_Color_Red,
	[MENUITEM_CAP_COLOR_G]  	   = sText_Cap_Color_Green,
	[MENUITEM_CAP_COLOR_B]  	   = sText_Cap_Color_Blue,
	[MENUITEM_AUTOMATIC_FOLLOWER]  = sText_Automatic_Follower,
	[MENUITEM_GENERIC_CRY]         = sText_Use_Generic_Cry,
	[MENUITEM_BIKE_TYPE]           = sText_Bike_Type,
	//[MENUITEM_MGBA_MODE]           = sText_Mgba_Mode,
    [MENUITEM_CANCEL]              = gText_OptionMenuCancel,
};

static const u8 sText_Instant[] = _("{COLOR GREEN}{SHADOW LIGHT_GREEN}INSTANT");

static const u8 *const sTextSpeedStrings[] = {gText_TextSpeedSlow, gText_TextSpeedMid, gText_TextSpeedFast, sText_Instant};

static const struct WindowTemplate sOptionMenuWinTemplates[] =
{
    {
        .bg = 1,
        .tilemapLeft = 2,
        .tilemapTop = 1,
        .width = 26,
        .height = 2,
        .paletteNum = 1,
        .baseBlock = 2
    },
    {
        .bg = 0,
        .tilemapLeft = 2,
        .tilemapTop = 5,
        .width = 26,
        .height = 14,
        .paletteNum = 1,
        .baseBlock = 0x36
    },
    DUMMY_WIN_TEMPLATE
};

static const struct BgTemplate sOptionMenuBgTemplates[] =
{
   {
       .bg = 1,
       .charBaseIndex = 1,
       .mapBaseIndex = 30,
       .screenSize = 0,
       .paletteMode = 0,
       .priority = 0,
       .baseTile = 0
   },
   {
       .bg = 0,
       .charBaseIndex = 1,
       .mapBaseIndex = 31,
       .screenSize = 0,
       .paletteMode = 0,
       .priority = 1,
       .baseTile = 0
   }
};

static const u16 sUnknown_0855C6A0[] = {0x7E51};

// code
static void MainCB2(void)
{
    RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    UpdatePaletteFade();
}

static void VBlankCB(void)
{
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
}

static void DrawChoices(u32 id, int y, u8 textSpeed)
{
    if (sItemFunctions[id].drawChoices != NULL)
        sItemFunctions[id].drawChoices(sOptions->sel[id], y, textSpeed);
}

void CB2_InitOptionMenu(void)
{
    u32 i, taskId;

    if (useOptionPlusMenu)
    {
        CB2_InitOptionPlusMenu();
        return;
    }

    switch (gMain.state)
    {
    default:
    case 0:
        SetVBlankCallback(NULL);
        gMain.state++;
        break;
    case 1:
        DmaClearLarge16(3, (void*)(VRAM), VRAM_SIZE, 0x1000);
        DmaClear32(3, OAM, OAM_SIZE);
        DmaClear16(3, PLTT, PLTT_SIZE);
        SetGpuReg(REG_OFFSET_DISPCNT, 0);
        ResetBgsAndClearDma3BusyFlags(0);
        InitBgsFromTemplates(0, sOptionMenuBgTemplates, ARRAY_COUNT(sOptionMenuBgTemplates));
        ResetBgPositions();
        InitWindows(sOptionMenuWinTemplates);
        DeactivateAllTextPrinters();
        SetGpuReg(REG_OFFSET_WIN0H, 0);
        SetGpuReg(REG_OFFSET_WIN0V, 0);
        SetGpuReg(REG_OFFSET_WININ, 1);
        SetGpuReg(REG_OFFSET_WINOUT, 35);
        SetGpuReg(REG_OFFSET_BLDCNT, 193);
        SetGpuReg(REG_OFFSET_BLDALPHA, 0);
        SetGpuReg(REG_OFFSET_BLDY, 4);
        SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_WIN0_ON | DISPCNT_OBJ_ON | DISPCNT_OBJ_1D_MAP);
        ShowBg(0);
        ShowBg(1);
        gMain.state++;
        break;
    case 2:
        ResetPaletteFade();
        ScanlineEffect_Stop();
        ResetTasks();
        ResetSpriteData();
        gMain.state++;
        break;
    case 3:
        LoadBgTiles(1, GetWindowFrameTilesPal(gSaveBlock2Ptr->optionsWindowFrameType)->tiles, 0x120, 0x1A2);
        gMain.state++;
        break;
    case 4:
        LoadPalette(sUnknown_0855C6A0, 0, sizeof(sUnknown_0855C6A0));
        LoadPalette(GetWindowFrameTilesPal(gSaveBlock2Ptr->optionsWindowFrameType)->pal, 0x70, 0x20);
        gMain.state++;
        break;
    case 5:
        LoadPalette(sUnknown_0855C604, 0x10, sizeof(sUnknown_0855C604));
        gMain.state++;
        break;
    case 6:
        PutWindowTilemap(0);
        DrawTextOption();
        gMain.state++;
        break;
    case 7:
        gMain.state++;
        break;
    case 8:
        PutWindowTilemap(1);
        DrawOptionMenuTexts();
        gMain.state++;
    case 9:
        sub_80BB154();
        gMain.state++;
        break;
    case 10:
        taskId = CreateTask(Task_OptionMenuFadeIn, 0);

        sOptions = AllocZeroed(sizeof(*sOptions));
        sOptions->sel[MENUITEM_TEXTSPEED] = gSaveBlock2Ptr->optionsTextSpeed;
        sOptions->sel[MENUITEM_BATTLESCENE] = gSaveBlock2Ptr->optionsBattleSceneOff;
        sOptions->sel[MENUITEM_BATTLESTYLE] = gSaveBlock2Ptr->optionsBattleStyle;
        sOptions->sel[MENUITEM_MUSIC] = gSaveBlock2Ptr->optionsDifficulty;//ToDo
        sOptions->sel[MENUITEM_SOUND] = gSaveBlock2Ptr->optionsSound;
        sOptions->sel[MENUITEM_TITLE_SCREEN] = gSaveBlock2Ptr->titleScreen;//Title Screen
        sOptions->sel[MENUITEM_FRAMETYPE] = gSaveBlock2Ptr->optionsWindowFrameType;
        sOptions->sel[MENUITEM_HP_BAR] = gSaveBlock2Ptr->optionsHpBarSpeed;
        sOptions->sel[MENUITEM_EXP_BAR] = gSaveBlock2Ptr->optionsExpBarSpeed;
        sOptions->sel[MENUITEM_TRANSITION] = gSaveBlock2Ptr->optionsTransitionSpeed;
		sOptions->sel[MENUITEM_SHOW_DAMAGE] = gSaveBlock2Ptr->optionsDamageDoneMessageEnabled;
		sOptions->sel[MENUITEM_CAP_COLOR_R] = gSaveBlock2Ptr->playerRGB[0];
		sOptions->sel[MENUITEM_CAP_COLOR_G] = gSaveBlock2Ptr->playerRGB[1];
		sOptions->sel[MENUITEM_CAP_COLOR_B] = gSaveBlock2Ptr->playerRGB[2];
		sOptions->sel[MENUITEM_AUTOMATIC_FOLLOWER] = gSaveBlock2Ptr->optionsAutomaticFollower;
		sOptions->sel[MENUITEM_GENERIC_CRY] = gSaveBlock2Ptr->optionsGenericCry;
		sOptions->sel[MENUITEM_BIKE_TYPE] = gSaveBlock2Ptr->optionsBikeType;
		//sOptions->sel[MENUITEM_MGBA_MODE] = gSaveBlock2Ptr->optionsMgbaMode;


        for (i = 0; i < 7; i++)
            DrawChoices(i, i * Y_DIFF, 0xFF);

        HighlightOptionMenuItem(sOptions->menuCursor);

        CopyWindowToVram(WIN_OPTIONS, 3);
        gMain.state++;
        break;
    case 11:
        BeginNormalPaletteFade(0xFFFFFFFF, 0, 0x10, 0, RGB_BLACK);
        SetVBlankCallback(VBlankCB);
        SetMainCallback2(MainCB2);
        return;
    }
}

static void Task_OptionMenuFadeIn(u8 taskId)
{
    if (!gPaletteFade.active)
        gTasks[taskId].func = Task_OptionMenuProcessInput;
}

static void ScrollMenu(int direction)
{
    int menuItem, pos;
    if (direction == 0) // scroll down
        menuItem = sOptions->menuCursor + 3, pos = 6;
    else
        menuItem = sOptions->menuCursor - 3, pos = 0;

    // Hide one
    ScrollWindow(WIN_OPTIONS, direction, Y_DIFF, PIXEL_FILL(0));
    // Show one
    FillWindowPixelRect(WIN_OPTIONS, PIXEL_FILL(1), 0, Y_DIFF * pos, 26 * 8, Y_DIFF);
    // Print
    DrawChoices(menuItem, pos * Y_DIFF, 0xFF);
    AddTextPrinterParameterized(WIN_OPTIONS, 1, sOptionMenuItemsNames[menuItem], 8, (pos * Y_DIFF) + 1, 0xFF, NULL);
    CopyWindowToVram(WIN_OPTIONS, 2);
}

static void ScrollAll(int direction) // to bottom or top
{
    int i, y, menuItem, pos;
    int scrollCount = MENUITEM_COUNT - 7;
    // Move items up/down
    ScrollWindow(WIN_OPTIONS, direction, Y_DIFF * scrollCount, PIXEL_FILL(0));

    // Clear moved items
    if (direction == 0)
    {
        y = 7 - scrollCount;
        if (y < 0)
            y = 7;
        y *= Y_DIFF;
    }
    else
    {
        y = 0;
    }

    FillWindowPixelRect(WIN_OPTIONS, PIXEL_FILL(1), 0, y, 26 * 8, Y_DIFF * scrollCount);
    // Print new texts
    for (i = 0; i < scrollCount; i++)
    {
        if (direction == 0) // From top to bottom
            menuItem = MENUITEM_COUNT - 1 - i, pos = 6 - i;
        else // From bottom to top
            menuItem = i, pos = i;
        DrawChoices(menuItem, pos * Y_DIFF, 0xFF);
        AddTextPrinterParameterized(WIN_OPTIONS, 1, sOptionMenuItemsNames[menuItem], 8, (pos * Y_DIFF) + 1, 0xFF, NULL);
    }
    CopyWindowToVram(WIN_OPTIONS, 2);
}

static void Task_OptionMenuProcessInput(u8 taskId)
{
    int i, scrollCount = 0, itemsToRedraw;
    if (JOY_NEW(A_BUTTON))
    {
        if (sOptions->menuCursor == MENUITEM_CANCEL)
            gTasks[taskId].func = Task_OptionMenuSave;
    }
    else if (gMain.newKeys & B_BUTTON)
    {
        gTasks[taskId].func = Task_OptionMenuSave;
    }
    else if (JOY_NEW(DPAD_UP))
    {
        if (sOptions->visibleCursor == 3) // don't advance visible cursor until scrolled to the bottom
        {
            if (--sOptions->menuCursor == sOptions->visibleCursor - 1)
                sOptions->visibleCursor--;
            else
                ScrollMenu(1);
        }
        else
        {
            if (!(--sOptions->menuCursor < 0)) // Scroll all the way to the bottom.
                sOptions->visibleCursor--;
            else if (--sOptions->menuCursor < 0) // Scroll all the way to the bottom.
            {
                sOptions->visibleCursor = sOptions->menuCursor = 3;
                ScrollAll(0);
                sOptions->visibleCursor = 6;
                sOptions->menuCursor = MENUITEM_COUNT - 1;
            }
            else
            {
                sOptions->visibleCursor--;
            }
        }
        HighlightOptionMenuItem(sOptions->visibleCursor);
    }
    else if (JOY_NEW(DPAD_DOWN))
    {
        if (sOptions->visibleCursor == 3) // don't advance visible cursor until scrolled to the bottom
        {
            if (++sOptions->menuCursor == MENUITEM_COUNT - 3)
                sOptions->visibleCursor++;
            else
                ScrollMenu(0);
        }
        else
        {
            if (++sOptions->menuCursor >= MENUITEM_COUNT) // Scroll all the way to the tom.
            {
                sOptions->visibleCursor = 3;
                sOptions->menuCursor = MENUITEM_COUNT - 4;
                ScrollAll(1);
                sOptions->visibleCursor = sOptions->menuCursor = 0;
            }
            else
            {
                sOptions->visibleCursor++;
            }
        }
        HighlightOptionMenuItem(sOptions->visibleCursor);
    }
    else if (gMain.newKeys & (DPAD_LEFT | DPAD_RIGHT))
    {
        int cursor = sOptions->menuCursor;
        u8 previousOption = sOptions->sel[cursor];
        if (sItemFunctions[cursor].processInput != NULL)
            sOptions->sel[cursor] = sItemFunctions[cursor].processInput(previousOption);

        if (previousOption != sOptions->sel[cursor])
            DrawChoices(cursor, sOptions->visibleCursor * Y_DIFF, 0);
    }
}

static void Task_OptionMenuSave(u8 taskId)
{
    gSaveBlock2Ptr->optionsTextSpeed = sOptions->sel[MENUITEM_TEXTSPEED];
    gSaveBlock2Ptr->optionsBattleSceneOff = sOptions->sel[MENUITEM_BATTLESCENE];
    gSaveBlock2Ptr->optionsBattleStyle = sOptions->sel[MENUITEM_BATTLESTYLE];
	gSaveBlock2Ptr->optionsDifficulty = sOptions->sel[MENUITEM_MUSIC];
    gSaveBlock2Ptr->optionsSound = sOptions->sel[MENUITEM_SOUND];
    gSaveBlock2Ptr->titleScreen = sOptions->sel[MENUITEM_TITLE_SCREEN];
    gSaveBlock2Ptr->optionsWindowFrameType = sOptions->sel[MENUITEM_FRAMETYPE];
    gSaveBlock2Ptr->optionsHpBarSpeed = sOptions->sel[MENUITEM_HP_BAR];
    gSaveBlock2Ptr->optionsExpBarSpeed = sOptions->sel[MENUITEM_EXP_BAR];
    gSaveBlock2Ptr->optionsTransitionSpeed = sOptions->sel[MENUITEM_TRANSITION];
	gSaveBlock2Ptr->optionsDamageDoneMessageEnabled = sOptions->sel[MENUITEM_SHOW_DAMAGE];
	gSaveBlock2Ptr->playerRGB[0] = sOptions->sel[MENUITEM_CAP_COLOR_R];
	gSaveBlock2Ptr->playerRGB[1] = sOptions->sel[MENUITEM_CAP_COLOR_G];
	gSaveBlock2Ptr->playerRGB[2] = sOptions->sel[MENUITEM_CAP_COLOR_B];
	gSaveBlock2Ptr->optionsAutomaticFollower = sOptions->sel[MENUITEM_AUTOMATIC_FOLLOWER];
	gSaveBlock2Ptr->optionsGenericCry = sOptions->sel[MENUITEM_GENERIC_CRY];
	gSaveBlock2Ptr->optionsBikeType = sOptions->sel[MENUITEM_BIKE_TYPE];
	//gSaveBlock2Ptr->optionsMgbaMode = sOptions->sel[MENUITEM_MGBA_MODE];

    BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 0x10, RGB_BLACK);
    gTasks[taskId].func = Task_OptionMenuFadeOut;
}

static void Task_OptionMenuFadeOut(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        DestroyTask(taskId);
        FreeAllWindowBuffers();
        FREE_AND_SET_NULL(sOptions);
        SetMainCallback2(gMain.savedCallback);
    }
}

static void HighlightOptionMenuItem(int cursor)
{
    SetGpuReg(REG_OFFSET_WIN0H, WIN_RANGE(Y_DIFF, 224));
    SetGpuReg(REG_OFFSET_WIN0V, WIN_RANGE(cursor * Y_DIFF + 40, cursor * Y_DIFF + 56));
}

// Process Input functions
static int XOptions_ProcessInput(int x, int selection)
{
    if (gMain.newKeys & DPAD_RIGHT)
    {
        if (++selection > (x - 1))
            selection = 0;
    }
    if (gMain.newKeys & DPAD_LEFT)
    {
        if (--selection < 0)
            selection = (x - 1);
    }
    return selection;
}

static int ThreeOptions_ProcessInput(int selection)
{
    return XOptions_ProcessInput(3, selection);
}

static int FourOptions_ProcessInput(int selection)
{
    return XOptions_ProcessInput(4, selection);
}

static int ElevenOptions_ProcessInput(int selection)
{
    return XOptions_ProcessInput(11, selection);
}

static int ColorOptions_ProcessInput(int selection)
{
    return XOptions_ProcessInput(10, selection);
}

static int TwoOptions_ProcessInput(int selection)
{
    if (gMain.newKeys & (DPAD_LEFT | DPAD_RIGHT))
        selection ^= 1;

    return selection;
}

static int BattleStyle_ProcessInput(int selection)
{
    if (gMain.newKeys & (DPAD_LEFT | DPAD_RIGHT))
        selection ^= 1;

    return selection;
}

static int Sound_ProcessInput(int selection)
{
    int previous = selection;

    //selection = ThreeOptions_ProcessInput(selection);
	selection = XOptions_ProcessInput(2, selection);
    gDisableMusic = FALSE;
    SetPokemonCryStereo(selection);

    return selection;
}

static int FrameType_ProcessInput(int selection)
{
    if (gMain.newKeys & DPAD_RIGHT)
    {
        if (selection < WINDOW_FRAMES_COUNT - 1)
            selection++;
        else
            selection = 0;

        LoadBgTiles(1, GetWindowFrameTilesPal(selection)->tiles, 0x120, 0x1A2);
        LoadPalette(GetWindowFrameTilesPal(selection)->pal, 0x70, 0x20);
    }
    if (gMain.newKeys & DPAD_LEFT)
    {
        if (selection != 0)
            selection--;
        else
            selection = WINDOW_FRAMES_COUNT - 1;

        LoadBgTiles(1, GetWindowFrameTilesPal(selection)->tiles, 0x120, 0x1A2);
        LoadPalette(GetWindowFrameTilesPal(selection)->pal, 0x70, 0x20);
    }
    return selection;
}

static int GetMiddleX(const u8 *txt1, const u8 *txt2, const u8 *txt3)
{
    int xMid;
    int widthLeft = GetStringWidth(1, txt1, 0);
    int widthMid = GetStringWidth(1, txt2, 0);
    int widthRight = GetStringWidth(1, txt3, 0);

    widthMid -= (198 - 104);
    xMid = (widthLeft - widthMid - widthRight) / 2 + 104;
    return xMid;
}

// Draw Choices functions
static void DrawOptionMenuChoice(const u8 *text, u8 x, u8 y, u8 style, u8 textSpeed)
{
    u8 dst[16];
    u32 i;

    for (i = 0; *text != EOS && i <= 14; i++)
        dst[i] = *(text++);

    if (style != 0)
    {
        dst[2] = 4;
        dst[5] = 5;
    }

    dst[i] = EOS;
    AddTextPrinterParameterized(WIN_OPTIONS, 1, dst, x, y + 1, textSpeed, NULL);
}

static void HpBar_DrawChoices(int selection, int y, u8 textSpeed)
{
    if (selection < 10)
    {
        u8 textPlus[] = _("{COLOR GREEN}{SHADOW LIGHT_GREEN}+1{0x77}{0x77}{0x77}{0x77}{0x77}"); // 0x77 is to clear INSTANT text
        textPlus[7] = CHAR_0 + selection;
        DrawOptionMenuChoice(textPlus, 104, y, 1, textSpeed);
    }
    else
    {
        DrawOptionMenuChoice(sText_Instant, 104, y, 1, textSpeed);
    }
}

static void RGB_DrawChoices(int selection, int y, u8 textSpeed)
{
	u8 textPlus[] = _("{COLOR GREEN}{SHADOW LIGHT_GREEN}{0x77}{0x77}{0x77}{0x77}{0x77}"); // 0x77 is to clear INSTANT text
    textPlus[7] = CHAR_0 + selection;
    DrawOptionMenuChoice(textPlus, 104, y, 1, textSpeed);
}

static void TitleScreen_DrawChoices(int selection, int y, u8 textSpeed)
{
	switch(selection){
	case 0:
        DrawOptionMenuChoice(gText_TitleScreen_Rayquaza, 	104, y, 1, textSpeed);
		break;
    case 1:
        DrawOptionMenuChoice(gText_TitleScreen_Groudon, 	104, y, 1, textSpeed);
		break;
	case 2:
        DrawOptionMenuChoice(gText_TitleScreen_Kyogre, 		104, y, 1, textSpeed);
		break;
	default:
		DrawOptionMenuChoice(gText_TitleScreen_Kyogre, 		104, y, 1, textSpeed);
		break;
	}
}

static void CapColor_DrawChoices(int selection, int y, u8 textSpeed)
{
	//Default, Red, Green, Blue, Yellow, Purple, Brown, Gray, White, Black
	//const u8 gText_ColorRed
	switch(selection){
	case 0:
        DrawOptionMenuChoice(gText_Default, 		104, y, 1, textSpeed);
		break;
    case 1:
        DrawOptionMenuChoice(gText_ColorRed, 		104, y, 1, textSpeed);
		break;
	case 2:
        DrawOptionMenuChoice(gText_ColorGreen, 		104, y, 1, textSpeed);
		break;
	case 3:
        DrawOptionMenuChoice(gText_CapColorBlue, 	104, y, 1, textSpeed);
		break;
	case 4:
        DrawOptionMenuChoice(gText_ColorYellow, 	104, y, 1, textSpeed);
		break;
	case 5:
        DrawOptionMenuChoice(gText_ColorPurple, 	104, y, 1, textSpeed);
		break;
	case 6:
        DrawOptionMenuChoice(gText_ColorBrown, 		104, y, 1, textSpeed);
		break;
	case 7:
        DrawOptionMenuChoice(gText_ColorGray, 		104, y, 1, textSpeed);
		break;
	case 8:
        DrawOptionMenuChoice(gText_ColorWhite, 		104, y, 1, textSpeed);
		break;
	case 9:
        DrawOptionMenuChoice(gText_ColorBlack, 		104, y, 1, textSpeed);
		break;
	}
}

//0 default, 1 blonde, 2 honey, 3 orange, 4 brown, 5 black, 6 white, 7 red, 8 blue, 9 purple
static const u8 sText_Hair_Color_Blonde[]   = _("{COLOR GREEN}{SHADOW LIGHT_GREEN}Blonde");
static const u8 sText_Hair_Color_Honey[]    = _("{COLOR GREEN}{SHADOW LIGHT_GREEN}Honey");
static const u8 sText_Hair_Color_Orange[]   = _("{COLOR GREEN}{SHADOW LIGHT_GREEN}Orange");

static void HairColor_DrawChoices(int selection, int y, u8 textSpeed)
{
	//0 default, 1 blonde, 2 honey, 3 orange, 4 brown, 5 black, 6 white, 7 red, 8 blue, 9 purple
	switch(selection){
	case 0:
        DrawOptionMenuChoice(gText_Default, 			104, y, 1, textSpeed);
		break;
    case 1:
        DrawOptionMenuChoice(sText_Hair_Color_Blonde, 	104, y, 1, textSpeed);
		break;
	case 2:
        DrawOptionMenuChoice(sText_Hair_Color_Honey, 	104, y, 1, textSpeed);
		break;
	case 3:
        DrawOptionMenuChoice(sText_Hair_Color_Orange, 	104, y, 1, textSpeed);
		break;
	case 4:
        DrawOptionMenuChoice(gText_ColorBrown, 			104, y, 1, textSpeed);
		break;
	case 5:
        DrawOptionMenuChoice(gText_ColorBlack, 			104, y, 1, textSpeed);
		break;
	case 6:
        DrawOptionMenuChoice(gText_ColorWhite, 			104, y, 1, textSpeed);
		break;
	case 7:
        DrawOptionMenuChoice(gText_ColorRed, 			104, y, 1, textSpeed);
		break;
	case 8:
        DrawOptionMenuChoice(gText_CapColorBlue, 		104, y, 1, textSpeed);
		break;
	case 9:
        DrawOptionMenuChoice(gText_ColorPurple, 		104, y, 1, textSpeed);
		break;
	}
}

//Music Expansion
static int Music_ProcessInput(int selection)
{
    if (gMain.newKeys & DPAD_RIGHT)
    {
        if (selection < 4)
            selection++;
        else
            selection = 0;
    }
    if (gMain.newKeys & DPAD_LEFT)
    {
        if (selection != 0)
            selection--;
        else
            selection = 3;
    }
    return selection;
}

static void Music_DrawChoices(int selection, int y, u8 textSpeed)
{
	switch(selection){
	case 0:
        DrawOptionMenuChoice(gText_Region_Kanto, 104, y, 1, textSpeed);
		break;
    case 1:
        DrawOptionMenuChoice(gText_Region_Jotho, 104, y, 1, textSpeed);
		break;
	case 2:
        DrawOptionMenuChoice(gText_Region_Hoenn, 104, y, 1, textSpeed);
		break;
	case 3:
        DrawOptionMenuChoice(gText_Region_Sinnoh, 104, y, 1, textSpeed);
		break;
	}
}

static void BattleScene_DrawChoices(int selection, int y, u8 textSpeed)
{
    u8 styles[2] = {0};

    styles[selection] = 1;
    DrawOptionMenuChoice(gText_BattleSceneOn, 104, y, styles[0], textSpeed);
    DrawOptionMenuChoice(gText_BattleSceneOff, GetStringRightAlignXOffset(1, gText_BattleSceneOff, 198), y, styles[1], textSpeed);
}

static void BattleStyle_DrawChoices(int selection, int y, u8 textSpeed)
{
    u8 styles[2] = {0, 0};

    styles[selection] = 1;
    DrawOptionMenuChoice(gText_BattleStyleShift, 104, y, styles[0], textSpeed);
    DrawOptionMenuChoice(gText_BattleStyleSet, GetStringRightAlignXOffset(1, gText_BattleStyleSet, 198), y, styles[1], textSpeed);
}

static void Transition_DrawChoices(int selection, int y, u8 textSpeed)
{
    u8 styles[2] = {0, 0};

    styles[selection] = 1;
    DrawOptionMenuChoice(gText_TransitionStyleNormal, 104, y, styles[0], textSpeed);
    DrawOptionMenuChoice(gText_TransitionStyleInstant, GetStringRightAlignXOffset(1, gText_TransitionStyleInstant, 198), y, styles[1], textSpeed);
}

static void UnitSystem_DrawChoices(int selection, int y, u8 textSpeed)
{
    u8 styles[2] = {0, 0};

    styles[selection] = 1;
    DrawOptionMenuChoice(gText_UnitSystemMetric, 104, y, styles[0], textSpeed);
    DrawOptionMenuChoice(gText_UnitSystemImperial, GetStringRightAlignXOffset(1, gText_TransitionStyleInstant, 198), y, styles[1], textSpeed);
}

static void BikeTypes_DrawChoices(int selection, int y, u8 textSpeed)
{
    u8 styles[2] = {0, 0};

    styles[selection] = 1;
    DrawOptionMenuChoice(gText_Options_MachBike, 104, y, styles[0], textSpeed);
    DrawOptionMenuChoice(gText_Options_AcroBike, GetStringRightAlignXOffset(1, gText_Options_AcroBike, 198), y, styles[1], textSpeed);
}

static void MgbaMode_DrawChoices(int selection, int y, u8 textSpeed)
{
    u8 styles[2] = {0, 0};

    styles[selection] = 1;
    DrawOptionMenuChoice(gText_BattleSceneOff, 104, y, styles[0], textSpeed);
    DrawOptionMenuChoice(gText_BattleSceneOn, GetStringRightAlignXOffset(1, gText_BattleSceneOn, 198), y, styles[1], textSpeed);
}

static void FourOptions_DrawChoices(const u8 *const *const strings, int selection, int y, u8 textSpeed)
{
    static const u8 choiceOrders[][3] =
    {
        {0, 1, 2},
        {0, 1, 2},
        {1, 2, 3},
        {1, 2, 3},
    };
    u8 styles[4] = {0};
    int xMid;
    const u8 *order = choiceOrders[selection];

    styles[selection] = 1;
    xMid = GetMiddleX(strings[order[0]], strings[order[1]], strings[order[2]]);

    FillWindowPixelRect(WIN_OPTIONS, PIXEL_FILL(1), 104, y, 26 * 8 - 104, Y_DIFF);
    CopyWindowToVram(WIN_OPTIONS, 2);

    DrawOptionMenuChoice(strings[order[0]], 104, y, styles[order[0]], textSpeed);
    DrawOptionMenuChoice(strings[order[1]], xMid, y, styles[order[1]], textSpeed);
    DrawOptionMenuChoice(strings[order[2]], GetStringRightAlignXOffset(1, strings[order[2]], 198), y, styles[order[2]], textSpeed);
}

static void TextSpeed_DrawChoices(int selection, int y, u8 textSpeed)
{
    FourOptions_DrawChoices(sTextSpeedStrings, selection, y, textSpeed);
}


static void Sound_DrawChoices(int selection, int y, u8 textSpeed)
{
	u8 styles[2] = {0};

    styles[selection] = 1;
    DrawOptionMenuChoice(gText_SoundMono, 104, y, styles[0], textSpeed);
    DrawOptionMenuChoice(gText_SoundStereo, GetStringRightAlignXOffset(1, gText_SoundStereo, 198), y, styles[1], textSpeed);

}

static void FrameType_DrawChoices(int selection, int y, u8 textSpeed)
{
    u8 text[16];
    u32 n = selection + 1;
    u32 i;

    for (i = 0; gText_FrameTypeNumber[i] != EOS && i <= 5; i++)
        text[i] = gText_FrameTypeNumber[i];

    // Convert a number to decimal string
    if (n / 10 != 0)
    {
        text[i] = n / 10 + CHAR_0;
        i++;
        text[i] = n % 10 + CHAR_0;
        i++;
    }
    else
    {
        text[i] = n % 10 + CHAR_0;
        i++;
        text[i] = 0x77;
        i++;
    }

    text[i] = EOS;

    DrawOptionMenuChoice(gText_FrameType, 104, y, 0, textSpeed);
    DrawOptionMenuChoice(text, 128, y, 1, textSpeed);
}

static void ButtonMode_DrawChoices(int selection, int y, u8 textSpeed)
{
    u8 styles[3] = {0};
    int xMid = GetMiddleX(gText_ExpandedPlaceholder_Emerald, gText_ExpandedPlaceholder_Ruby, gText_ExpandedPlaceholder_Sapphire);

    styles[selection] = 1;
    DrawOptionMenuChoice(gText_ExpandedPlaceholder_Emerald, 104, y, styles[0], textSpeed);
    DrawOptionMenuChoice(gText_ExpandedPlaceholder_Ruby, xMid, y, styles[1], textSpeed);
    DrawOptionMenuChoice(gText_ExpandedPlaceholder_Sapphire, GetStringRightAlignXOffset(1, gText_ExpandedPlaceholder_Sapphire, 198), y, styles[2], textSpeed);
}

static void DrawTextOption(void)
{
    FillWindowPixelBuffer(WIN_TEXT_OPTION, PIXEL_FILL(1));
    AddTextPrinterParameterized(WIN_TEXT_OPTION, 1, gText_Option, 8, 1, 0, NULL);
    CopyWindowToVram(WIN_TEXT_OPTION, 3);
}

static void DrawOptionMenuTexts(void)
{
    u32 i;

    FillWindowPixelBuffer(WIN_OPTIONS, PIXEL_FILL(1));
    for (i = 0; i < 7; i++)
        AddTextPrinterParameterized(WIN_OPTIONS, 1, sOptionMenuItemsNames[i], 8, (i * Y_DIFF) + 1, 0, NULL);

    CopyWindowToVram(WIN_OPTIONS, 3);
}

static void sub_80BB154(void)
{
    //                   bg, tileNum, x,    y,    width, height,  pal
    FillBgTilemapBufferRect(1, 0x1A2, 1,    0,      1,      1,      7);
    FillBgTilemapBufferRect(1, 0x1A3, 2,    0,      0x1B,   1,      7);
    FillBgTilemapBufferRect(1, 0x1A4, 28,   0,      1,      1,      7);
    FillBgTilemapBufferRect(1, 0x1A5, 1,    1,      1,      2,      7);
    FillBgTilemapBufferRect(1, 0x1A7, 28,   1,      1,      2,      7);
    FillBgTilemapBufferRect(1, 0x1A8, 1,    3,      1,      1,      7);
    FillBgTilemapBufferRect(1, 0x1A9, 2,    3,      0x1B,   1,      7);
    FillBgTilemapBufferRect(1, 0x1AA, 28,   3,      1,      1,      7);
    FillBgTilemapBufferRect(1, 0x1A2, 1,    4,      1,      1,      7);
    FillBgTilemapBufferRect(1, 0x1A3, 2,    4,      0x1A,   1,      7);
    FillBgTilemapBufferRect(1, 0x1A4, 28,   4,      1,      1,      7);
    FillBgTilemapBufferRect(1, 0x1A5, 1,    5,      1,      0x12,   7);
    FillBgTilemapBufferRect(1, 0x1A7, 28,   5,      1,      0x12,   7);
    FillBgTilemapBufferRect(1, 0x1A8, 1,    19,     1,      1,      7);
    FillBgTilemapBufferRect(1, 0x1A9, 2,    19,     0x1A,   1,      7);
    FillBgTilemapBufferRect(1, 0x1AA, 28,   19,     1,      1,      7);

    CopyBgTilemapBufferToVram(1);
}