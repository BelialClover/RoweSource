#include "global.h"
#include "main.h"
#include "text.h"
#include "task.h"
#include "malloc.h"
#include "gpu_regs.h"
#include "scanline_effect.h"
#include "text_window.h"
#include "bg.h"
#include "window.h"
#include "strings.h"
#include "text_window.h"
#include "menu.h"
#include "level_scaling.h"
#include "random.h"
#include "palette.h"
#include "constants/songs.h"
#include "sound.h"
#include "mystery_gift.h"
#include "union_room.h"
#include "title_screen.h"
#include "ereader_screen.h"
#include "international_string_util.h"
#include "list_menu.h"
#include "string_util.h"
#include "mevent.h"
#include "mystery_gift_view.h"
#include "save.h"
#include "link.h"
#include "mevent_client.h"
#include "event_data.h"
#include "link_rfu.h"
#include "pokedex.h"
#include "mevent_news.h"
#include "mevent_server.h"
#include "constants/cable_club.h"
#include "constants/flags.h"
#include "constants/species.h"
#include "constants/abilities.h"
#include "constants/items.h"
#include "constants/moves.h"

void LoadMysteryGiftTextboxBorder(u8 bgId);
void CreateMysteryGiftTask(void);
void Task_MysteryGift(u8 taskId);
static bool8 MysteryGift_GiveMysteryGiftMon(void);
static bool32 GiveMysteryGiftMonAndPrintMSG(u8 * state, const u8 * arg1, u16 * arg2);

EWRAM_DATA u8 sDownArrowCounterAndYCoordIdx[8] = {};
EWRAM_DATA bool8 gGiftIsFromEReader = FALSE;

static const u16 sTextboxBorder_Pal[] = INCBIN_U16("graphics/interface/unk_textbox_border.gbapal");
static const u32 sTextboxBorder_Gfx[] = INCBIN_U32("graphics/interface/unk_textbox_border.4bpp.lz");

enum {
    CARD_TEST,
    CARD_VIVILLON_1,
    CARD_GRENINJA,
    CARD_PICHU,
	CARD_VIVILLON_2,
	CARD_COSPLAY_PIKACHU,
	CARD_PIKACHU_POP_STAR,
	CARD_AZ_FLOETTE,
	CARD_SHINY_BELDUM,
	CARD_DIANCIE,
	CARD_SHINY_EEVEE,
	CARD_BEE_ALTARIA,
    CARD_CHRISTMASS_DELIBIRD,
	CARD_COSPLAY_PIKACHU_LIBRE,
	CARD_SHINY_AXEW,
	CARD_MANAPHY,
    CARD_HALLOWEEN_GOURGEIST,
};

struct MysteryGiftTaskData
{
    u16 var; // Multipurpose
    u16 unused1;
    u16 unused2;
    u16 unused3;
    u8 state;
    u8 textState;
    u8 unused4;
    u8 unused5;
    u8 isWonderNews;
    u8 sourceIsFriend;
    u8 msgId;
    u8 * clientMsg;
};



static const struct BgTemplate sBGTemplates[] = {
    {
        .bg = 0,
        .charBaseIndex = 2,
        .mapBaseIndex = 15,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 0,
        .baseTile = 0x000
    }, {
        .bg = 1,
        .charBaseIndex = 0,
        .mapBaseIndex = 14,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 1,
        .baseTile = 0x000
    }, {
        .bg = 2,
        .charBaseIndex = 0,
        .mapBaseIndex = 13,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 2,
        .baseTile = 0x000
    }, {
        .bg = 3,
        .charBaseIndex = 0,
        .mapBaseIndex = 12,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 3,
        .baseTile = 0x000
    }
};

static const struct WindowTemplate sMainWindows[] = {
    {
        .bg = 0x00,
        .tilemapLeft = 0x00,
        .tilemapTop = 0x00,
        .width = 0x1e,
        .height = 0x02,
        .paletteNum = 0x0c,
        .baseBlock = 0x0013
    }, {
        .bg = 0x00,
        .tilemapLeft = 0x01,
        .tilemapTop = 0x0f,
        .width = 0x1c,
        .height = 0x04,
        .paletteNum = 0x0c,
        .baseBlock = 0x004f
    }, {
        .bg = 0x00,
        .tilemapLeft = 0x00,
        .tilemapTop = 0x0f,
        .width = 0x1e,
        .height = 0x05,
        .paletteNum = 0x0d,
        .baseBlock = 0x004f
    }, {
        0xFF
    }
};

static const struct WindowTemplate sWindowTemplate_YesNoMsg_Wide = {
    .bg = 0,
    .tilemapLeft = 1,
    .tilemapTop = 15,
    .width = 28,
    .height = 4,
    .paletteNum = 12,
    .baseBlock = 0x00e5
};

static const struct WindowTemplate sWindowTemplate_YesNoMsg = {
    .bg = 0,
    .tilemapLeft = 1,
    .tilemapTop = 15,
    .width = 20,
    .height = 4,
    .paletteNum = 12,
    .baseBlock = 0x00e5
};

static const struct WindowTemplate sWindowTemplate_GiftSelect = {
    .bg = 0,
    .tilemapLeft = 1,
    .tilemapTop = 15,
    .width = 19,
    .height = 4,
    .paletteNum = 12,
    .baseBlock = 0x00e5
};

static const struct WindowTemplate sWindowTemplate_ThreeOptions = {
    .bg = 0,
    .tilemapLeft = 8,
    .tilemapTop = 6,
    .width = 14,
    .height = 6,
    .paletteNum = 12,
    .baseBlock = 0x0155
};

static const struct WindowTemplate sWindowTemplate_YesNoBox = {
    .bg = 0,
    .tilemapLeft = 23,
    .tilemapTop = 15,
    .width = 6,
    .height = 4,
    .paletteNum = 12,
    .baseBlock = 0x0155
};

static const struct WindowTemplate sWindowTemplate_GiftSelect_3Options = {
    .bg = 0,
    .tilemapLeft = 22,
    .tilemapTop = 11,
    .width = 7,
    .height = 8,
    .paletteNum = 12,
    .baseBlock = 0x0155
};

static const struct WindowTemplate sWindowTemplate_GiftSelect_2Options = {
    .bg = 0,
    .tilemapLeft = 22,
    .tilemapTop = 13,
    .width = 7,
    .height = 6,
    .paletteNum = 12,
    .baseBlock = 0x0155
};

static const struct WindowTemplate sWindowTemplate_GiftSelect_1Option = {
    .bg = 0,
    .tilemapLeft = 22,
    .tilemapTop = 15,
    .width = 7,
    .height = 4,
    .paletteNum = 12,
    .baseBlock = 0x0155
};


static const u8 gReceiveGift[] 			=  _("Receive Gift");
static const u8 gCheckCard[]   			=  _("Check Card");
static const u8 gText_AlreadyHaveCard[] =  _("You already have this Mystery Gift.");
static const u8 gText_NoMysterGift[] 	=  _("You haven't received this version\nMystery Gift yet.");

static const struct ListMenuItem sListMenuItems_CardsOrNews[] = {
    { gReceiveGift,  	  0 },
    { gCheckCard,   	  1 },
    { gText_Exit3,       -2 }
};

static const struct ListMenuItem sListMenuItems_WirelessOrFriend[] = {
    { gText_WirelessCommunication,  0 },
    { gText_Friend2,                1 },
    { gText_Cancel2,               -2 }
};

static const struct ListMenuTemplate sListMenuTemplate_ThreeOptions = {
    .items = NULL,
    .moveCursorFunc = ListMenuDefaultCursorMoveFunc,
    .itemPrintFunc = NULL,
    .totalItems = 3,
    .maxShowed = 3,
    .windowId = 0,
    .header_X = 0,
    .item_X = 8,
    .cursor_X = 0,
    .upText_Y = 1,
    .cursorPal = 2,
    .fillValue = 1,
    .cursorShadowPal = 3,
    .lettersSpacing = 0,
    .itemVerticalPadding = 0,
    .scrollMultiple = 0,
    .fontId = 1,
    .cursorKind = 0
};

static const struct ListMenuItem sListMenuItems_ReceiveSendToss[] = {
    { gText_Receive,  0 },
    { gText_Send,     1 },
    { gText_Toss,     2 },
    { gText_Cancel2, -2 }
};

static const struct ListMenuItem sListMenuItems_ReceiveToss[] = {
    { gText_Receive,  0 },
    { gText_Toss,     2 },
    { gText_Cancel2, -2 }
};

static const struct ListMenuItem sListMenuItems_ReceiveSend[] = {
    { gText_Receive,  0 },
    { gText_Send,     1 },
    { gText_Cancel2, -2 }
};

static const struct ListMenuItem sListMenuItems_Receive[] = {
    { gText_Receive,  0 },
    { gText_Cancel2, -2 }
};

static const struct ListMenuTemplate sListMenu_ReceiveSendToss = {
    .items = sListMenuItems_ReceiveSendToss,
    .moveCursorFunc = ListMenuDefaultCursorMoveFunc,
    .itemPrintFunc = NULL,
    .totalItems = 4,
    .maxShowed = 4,
    .windowId = 0,
    .header_X = 0,
    .item_X = 8,
    .cursor_X = 0,
    .upText_Y = 1,
    .cursorPal = 2,
    .fillValue = 1,
    .cursorShadowPal = 3,
    .lettersSpacing = 0,
    .itemVerticalPadding = 0,
    .scrollMultiple = 0,
    .fontId = 1,
    .cursorKind = 0
};

static const struct ListMenuTemplate sListMenu_ReceiveToss = {
    .items = sListMenuItems_ReceiveToss,
    .moveCursorFunc = ListMenuDefaultCursorMoveFunc,
    .itemPrintFunc = NULL,
    .totalItems = 3,
    .maxShowed = 3,
    .windowId = 0,
    .header_X = 0,
    .item_X = 8,
    .cursor_X = 0,
    .upText_Y = 1,
    .cursorPal = 2,
    .fillValue = 1,
    .cursorShadowPal = 3,
    .lettersSpacing = 0,
    .itemVerticalPadding = 0,
    .scrollMultiple = 0,
    .fontId = 1,
    .cursorKind = 0
};

static const struct ListMenuTemplate sListMenu_ReceiveSend = {
    .items = sListMenuItems_ReceiveSend,
    .moveCursorFunc = ListMenuDefaultCursorMoveFunc,
    .itemPrintFunc = NULL,
    .totalItems = 3,
    .maxShowed = 3,
    .windowId = 0,
    .header_X = 0,
    .item_X = 8,
    .cursor_X = 0,
    .upText_Y = 1,
    .cursorPal = 2,
    .fillValue = 1,
    .cursorShadowPal = 3,
    .lettersSpacing = 0,
    .itemVerticalPadding = 0,
    .scrollMultiple = 0,
    .fontId = 1,
    .cursorKind = 0
};

static const struct ListMenuTemplate sListMenu_Receive = {
    .items = sListMenuItems_Receive,
    .moveCursorFunc = ListMenuDefaultCursorMoveFunc,
    .itemPrintFunc = NULL,
    .totalItems = 2,
    .maxShowed = 2,
    .windowId = 0,
    .header_X = 0,
    .item_X = 8,
    .cursor_X = 0,
    .upText_Y = 1,
    .cursorPal = 2,
    .fillValue = 1,
    .cursorShadowPal = 3,
    .lettersSpacing = 0,
    .itemVerticalPadding = 0,
    .scrollMultiple = 0,
    .fontId = 1,
    .cursorKind = 0
};

static const u8 *const Unref_082F0710[] = {
    gText_VarietyOfEventsImportedWireless,
    gText_WonderCardsInPossession,
    gText_ReadNewsThatArrived,
    gText_ReturnToTitle
};

ALIGNED(2) const u8 sMG_Ereader_TextColor_1[]      = { 0, 1, 2 };
ALIGNED(2) const u8 sMG_Ereader_TextColor_1_Copy[] = { 0, 1, 2 };
ALIGNED(2) const u8 sMG_Ereader_TextColor_2[]      = { 1, 2, 3 };

void vblankcb_mystery_gift_e_reader_run(void)
{
    ProcessSpriteCopyRequests();
    LoadOam();
    TransferPlttBuffer();
}

void CB2_MysteryGiftEReader(void)
{
    RunTasks();
    RunTextPrinters();
    AnimateSprites();
    BuildOamBuffer();
}

bool32 HandleMysteryGiftOrEReaderSetup(s32 mg_or_ereader)
{
    switch (gMain.state)
    {
    case 0:
        SetVBlankCallback(NULL);
        ResetPaletteFade();
        ResetSpriteData();
        FreeAllSpritePalettes();
        ResetTasks();
        ScanlineEffect_Stop();
        ResetBgsAndClearDma3BusyFlags(0);

        InitBgsFromTemplates(0, sBGTemplates, ARRAY_COUNT(sBGTemplates));
        ChangeBgX(0, 0, 0);
        ChangeBgY(0, 0, 0);
        ChangeBgX(1, 0, 0);
        ChangeBgY(1, 0, 0);
        ChangeBgX(2, 0, 0);
        ChangeBgY(2, 0, 0);
        ChangeBgX(3, 0, 0);
        ChangeBgY(3, 0, 0);

        SetBgTilemapBuffer(3, Alloc(0x800));
        SetBgTilemapBuffer(2, Alloc(0x800));
        SetBgTilemapBuffer(1, Alloc(0x800));
        SetBgTilemapBuffer(0, Alloc(0x800));

        LoadMysteryGiftTextboxBorder(3);
        InitWindows(sMainWindows);
        DeactivateAllTextPrinters();
        ClearGpuRegBits(REG_OFFSET_DISPCNT, DISPCNT_WIN0_ON | DISPCNT_WIN1_ON);
        SetGpuReg(REG_OFFSET_BLDCNT, 0);
        SetGpuReg(REG_OFFSET_BLDALPHA, 0);
        SetGpuReg(REG_OFFSET_BLDY, 0);
        gMain.state++;
        break;
    case 1:
        LoadPalette(sTextboxBorder_Pal, 0, 0x20);
        LoadPalette(GetTextWindowPalette(2), 0xd0, 0x20);
        Menu_LoadStdPalAt(0xC0);
        LoadUserWindowBorderGfx(0, 0xA, 0xE0);
        LoadUserWindowBorderGfx_(0, 0x1, 0xF0);
        FillBgTilemapBufferRect(0, 0x000, 0, 0, 32, 32, 0x11);
        FillBgTilemapBufferRect(1, 0x000, 0, 0, 32, 32, 0x11);
        FillBgTilemapBufferRect(2, 0x000, 0, 0, 32, 32, 0x11);
        MG_DrawCheckerboardPattern(3);
        PrintMysteryGiftOrEReaderTopMenu(mg_or_ereader, 0);
        gMain.state++;
        break;
    case 2:
        CopyBgTilemapBufferToVram(3);
        CopyBgTilemapBufferToVram(2);
        CopyBgTilemapBufferToVram(1);
        CopyBgTilemapBufferToVram(0);
        gMain.state++;
        break;
    case 3:
        ShowBg(0);
        ShowBg(3);
        PlayBGM(MUS_RG_MYSTERY_GIFT);
        SetVBlankCallback(vblankcb_mystery_gift_e_reader_run);
        EnableInterrupts(INTR_FLAG_VBLANK | INTR_FLAG_VCOUNT | INTR_FLAG_TIMER3 | INTR_FLAG_SERIAL);
        return TRUE;
    }

    return FALSE;
}

void CB2_InitMysteryGift(void)
{
    if (HandleMysteryGiftOrEReaderSetup(0))
    {
        SetMainCallback2(CB2_MysteryGiftEReader);
        gGiftIsFromEReader = FALSE;
        CreateMysteryGiftTask();
    }
    RunTasks();
}

void c2_ereader(void)
{
    if (HandleMysteryGiftOrEReaderSetup(1))
    {
        SetMainCallback2(CB2_MysteryGiftEReader);
        gGiftIsFromEReader = TRUE;
        task_add_00_ereader();
    }
}

void MainCB_FreeAllBuffersAndReturnToInitTitleScreen(void)
{
    gGiftIsFromEReader = FALSE;
    FreeAllWindowBuffers();
    Free(GetBgTilemapBuffer(0));
    Free(GetBgTilemapBuffer(1));
    Free(GetBgTilemapBuffer(2));
    Free(GetBgTilemapBuffer(3));
    SetMainCallback2(CB2_InitTitleScreen);
}

void PrintMysteryGiftOrEReaderTopMenu(bool8 mg_or_ereader, bool32 usePickOkCancel)
{
    const u8 * header;
    const u8 * options;
    FillWindowPixelBuffer(0, 0);
    if (mg_or_ereader == 0)
    {
        header = gText_MysteryGift;
        options = !usePickOkCancel ? gText_PickOKExit : gText_PickOKCancel;
    }
    else
    {
        header = gJPText_MysteryGift;
        options = gJPText_DecideStop;
    }

    AddTextPrinterParameterized4(0, 1, 4, 1, 0, 0, sMG_Ereader_TextColor_1, -1, header);
    AddTextPrinterParameterized4(0, 0, GetStringRightAlignXOffset(0, options, 0xDE), 1, 0, 0, sMG_Ereader_TextColor_1, -1, options);
    CopyWindowToVram(0, 2);
    PutWindowTilemap(0);
}

void MG_DrawTextBorder(u8 windowId)
{
    DrawTextBorderOuter(windowId, 0x01, 0xF);
}

void MG_DrawCheckerboardPattern(u32 bg)
{
    s32 i = 0, j;

    FillBgTilemapBufferRect(bg, 0x003, 0, 0, 32, 2, 0x11);

    for (i = 0; i < 18; i++)
    {
        for (j = 0; j < 32; j++)
        {
            if ((i & 1) != (j & 1))
            {
                FillBgTilemapBufferRect(bg, 1, j, i + 2, 1, 1, 0x11);
            }
            else
            {
                FillBgTilemapBufferRect(bg, 2, j, i + 2, 1, 1, 0x11);
            }
        }
    }
}

void ClearScreenInBg0(bool32 ignoreTopTwoRows)
{
    switch (ignoreTopTwoRows)
    {
    case 0:
        FillBgTilemapBufferRect(0, 0, 0, 0, 32, 32, 0x11);
        break;
    case 1:
        FillBgTilemapBufferRect(0, 0, 0, 2, 32, 30, 0x11);
        break;
    }
    CopyBgTilemapBufferToVram(0);
}

void AddTextPrinterToWindow1(const u8 *str)
{
    StringExpandPlaceholders(gStringVar4, str);
    FillWindowPixelBuffer(1, 0x11);
    AddTextPrinterParameterized4(1, 1, 0, 1, 0, 0, sMG_Ereader_TextColor_2, 0, gStringVar4);
    DrawTextBorderOuter(1, 0x001, 0xF);
    PutWindowTilemap(1);
    CopyWindowToVram(1, 3);
}

static void ClearTextWindow(void)
{
    rbox_fill_rectangle(1);
    ClearWindowTilemap(1);
    CopyWindowToVram(1, 1);
}

bool32 MG_PrintTextOnWindow1AndWaitButton(u8 *textState, const u8 *str)
{
    switch (*textState)
    {
    case 0:
        AddTextPrinterToWindow1(str);
        goto inc;
    case 1:
        DrawDownArrow(1, 0xD0, 0x14, 1, FALSE, &sDownArrowCounterAndYCoordIdx[0], &sDownArrowCounterAndYCoordIdx[1]);
        if (({JOY_NEW(A_BUTTON | B_BUTTON);}))
        {
        inc:
            (*textState)++;
        }
        break;
    case 2:
        DrawDownArrow(1, 0xD0, 0x14, 1, TRUE, &sDownArrowCounterAndYCoordIdx[0], &sDownArrowCounterAndYCoordIdx[1]);
        *textState = 0;
        ClearTextWindow();
        return TRUE;
    case 0xFF:
        *textState = 2;
        break;
    }
    return FALSE;
}

static void HideDownArrow(void)
{
    DrawDownArrow(1, 0xD0, 0x14, 1, FALSE, &sDownArrowCounterAndYCoordIdx[0], &sDownArrowCounterAndYCoordIdx[1]);
}

static void ShowDownArrow(void)
{
    DrawDownArrow(1, 0xD0, 0x14, 1, TRUE, &sDownArrowCounterAndYCoordIdx[0], &sDownArrowCounterAndYCoordIdx[1]);
}

bool32 unref_HideDownArrowAndWaitButton(u8 * textState)
{
    switch (*textState)
    {
    case 0:
        HideDownArrow();
        if (({JOY_NEW(A_BUTTON | B_BUTTON);}))
        {
            (*textState)++;
        }
        break;
    case 1:
        ShowDownArrow();
        *textState = 0;
        return TRUE;
    }
    return FALSE;
}

static bool32 PrintStringAndWait2Seconds(u8 * counter, const u8 * str)
{
    if (*counter == 0)
    {
        AddTextPrinterToWindow1(str);
    }
    if (++(*counter) > 120)
    {
        *counter = 0;
        ClearTextWindow();
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

static u32 MysteryGift_HandleThreeOptionMenu(u8 * unused0, u16 * unused1, u8 whichMenu)
{
    struct ListMenuTemplate listMenuTemplate = sListMenuTemplate_ThreeOptions;
    struct WindowTemplate windowTemplate = sWindowTemplate_ThreeOptions;
    s32 width;
    s32 response;

    if (whichMenu == 0)
    {
        listMenuTemplate.items = sListMenuItems_CardsOrNews;
    }
    else
    {
        listMenuTemplate.items = sListMenuItems_WirelessOrFriend;
    }
    width = Intl_GetListMenuWidth(&listMenuTemplate);
    if (width & 1)
    {
        width++;
    }
    windowTemplate.width = width;
    if (width < 30)
    {
        windowTemplate.tilemapLeft = (30 - width) / 2;
    }
    else
    {
        windowTemplate.tilemapLeft = 0;
    }
    response = DoMysteryGiftListMenu(&windowTemplate, &listMenuTemplate, 1, 0x00A, 0xE0);
    if (response != -1)
    {
        ClearWindowTilemap(2);
        CopyWindowToVram(2, 1);
    }
    return response;
}

s8 mevent_message_print_and_prompt_yes_no(u8 * textState, u16 * windowId, bool8 yesNoBoxPlacement, const u8 * str)
{
    struct WindowTemplate windowTemplate;
    s8 input;

    switch (*textState)
    {
    case 0:
        StringExpandPlaceholders(gStringVar4, str);
        if (yesNoBoxPlacement == 0)
        {
            *windowId = AddWindow(&sWindowTemplate_YesNoMsg_Wide);
        }
        else
        {
            *windowId = AddWindow(&sWindowTemplate_YesNoMsg);
        }
        FillWindowPixelBuffer(*windowId, 0x11);
        AddTextPrinterParameterized4(*windowId, 1, 0, 1, 0, 0, sMG_Ereader_TextColor_2, 0, gStringVar4);
        DrawTextBorderOuter(*windowId, 0x001, 0x0F);
        CopyWindowToVram(*windowId, 2);
        PutWindowTilemap(*windowId);
        (*textState)++;
        break;
    case 1:
        windowTemplate = sWindowTemplate_YesNoBox;
        if (yesNoBoxPlacement == 0)
        {
            windowTemplate.tilemapTop = 9;
        }
        else
        {
            windowTemplate.tilemapTop = 15;
        }
        CreateYesNoMenu(&windowTemplate, 10, 14, 0);
        (*textState)++;
        break;
    case 2:
        input = Menu_ProcessInputNoWrapClearOnChoose();
        if (input == -1 || input == 0 || input == 1)
        {
            *textState = 0;
            rbox_fill_rectangle(*windowId);
            ClearWindowTilemap(*windowId);
            CopyWindowToVram(*windowId, 1);
            RemoveWindow(*windowId);
            return input;
        }
        break;
    case 0xFF:
        *textState = 0;
        rbox_fill_rectangle(*windowId);
        ClearWindowTilemap(*windowId);
        CopyWindowToVram(*windowId, 1);
        RemoveWindow(*windowId);
        return -1;
    }

    return -2;
}

static s32 HandleMysteryGiftListMenu(u8 * textState, u16 * windowId, bool32 cannotToss, bool32 cannotSend)
{
    struct WindowTemplate windowTemplate;
    s32 input;

    switch (*textState)
    {
    case 0:
        if (cannotToss == 0)
        {
            StringExpandPlaceholders(gStringVar4, gText_WhatToDoWithCards);
        }
        else
        {
            StringExpandPlaceholders(gStringVar4, gText_WhatToDoWithNews);
        }
        *windowId = AddWindow(&sWindowTemplate_GiftSelect);
        FillWindowPixelBuffer(*windowId, 0x11);
        AddTextPrinterParameterized4(*windowId, 1, 0, 1, 0, 0, sMG_Ereader_TextColor_2, 0, gStringVar4);
        DrawTextBorderOuter(*windowId, 0x001, 0x0F);
        CopyWindowToVram(*windowId, 2);
        PutWindowTilemap(*windowId);
        (*textState)++;
        break;
    case 1:
        windowTemplate = sWindowTemplate_YesNoBox;
        if (cannotSend)
        {
            if (cannotToss == 0)
            {
                input = DoMysteryGiftListMenu(&sWindowTemplate_GiftSelect_2Options, &sListMenu_ReceiveToss, 1, 0x00A, 0xE0);
            }
            else
            {
                input = DoMysteryGiftListMenu(&sWindowTemplate_GiftSelect_1Option, &sListMenu_Receive, 1, 0x00A, 0xE0);
            }
        }
        else
        {
            if (cannotToss == 0)
            {
                input = DoMysteryGiftListMenu(&sWindowTemplate_GiftSelect_3Options, &sListMenu_ReceiveSendToss, 1, 0x00A, 0xE0);
            }
            else
            {
                input = DoMysteryGiftListMenu(&sWindowTemplate_GiftSelect_2Options, &sListMenu_ReceiveSend, 1, 0x00A, 0xE0);
            }
        }
        if (input != -1)
        {
            *textState = 0;
            rbox_fill_rectangle(*windowId);
            ClearWindowTilemap(*windowId);
            CopyWindowToVram(*windowId, 1);
            RemoveWindow(*windowId);
            return input;
        }
        break;
    case 0xFF:
        *textState = 0;
        rbox_fill_rectangle(*windowId);
        ClearWindowTilemap(*windowId);
        CopyWindowToVram(*windowId, 1);
        RemoveWindow(*windowId);
        return -2;
    }

    return -1;
}

static bool32 ValidateCardOrNews(bool32 cardOrNews)
{
    if (cardOrNews == 0)
    {
        return ValidateReceivedWonderCard();
    }
    else
    {
        return ValidateReceivedWonderNews();
    }
}

static bool32 HandleLoadWonderCardOrNews(u8 * state, bool32 isWonderNews)
{
    s32 v0;

    switch (*state)
    {
    case 0:
        if (isWonderNews == 0)
        {
            InitWonderCardResources(GetSavedWonderCard(), GetSavedWonderCardMetadata());
        }
        else
        {
            InitWonderNewsResources(GetSavedWonderNews());
        }
        (*state)++;
        break;
    case 1:
        if (isWonderNews == 0)
        {
            v0 = FadeToWonderCardMenu();
        check:
            if (v0 != 0)
            {
                goto done;
            }
            break;
        }
        else
        {
            v0 = FadeToWonderNewsMenu();
            goto check;
        }
    done:
        *state = 0;
        return TRUE;
    }

    return FALSE;
}

static bool32 DestroyNewsOrCard(bool32 cardOrNews)
{
    if (cardOrNews == 0)
    {
        DestroyWonderCard();
    }
    else
    {
        DestroyWonderNews();
    }
    return TRUE;
}

static bool32 TearDownCardOrNews_ReturnToTopMenu(bool32 cardOrNews, bool32 arg1)
{
    if (cardOrNews == 0)
    {
        if (FadeOutFromWonderCard(arg1) != 0)
        {
            DestroyWonderCardResources();
            return TRUE;
        }
        else
        {
            return FALSE;
        }
    }
    else
    {
        if (FadeOutFromWonderNews(arg1) != 0)
        {
            DestroyWonderNewsResources();
            return TRUE;
        }
        else
        {
            return FALSE;
        }
    }
}

static s32 mevent_message_prompt_discard(u8 * textState, u16 * windowId, bool32 cardOrNews)
{
    if (cardOrNews == 0)
    {
        return mevent_message_print_and_prompt_yes_no(textState, windowId, TRUE, gText_IfThrowAwayCardEventWontHappen);
    }
    else
    {
        return mevent_message_print_and_prompt_yes_no(textState, windowId, TRUE, gText_OkayToDiscardNews);
    }
}

static bool32 PrintThrownAway(u8 * textState, bool32 cardOrNews)
{
    if (cardOrNews == 0)
    {
        return MG_PrintTextOnWindow1AndWaitButton(textState, gText_WonderCardThrownAway);
    }
    else
    {
        return MG_PrintTextOnWindow1AndWaitButton(textState, gText_WonderNewsThrownAway);
    }
}

static bool32 SaveOnMysteryGiftMenu(u8 * state)
{
    switch (*state)
    {
    case 0:
        AddTextPrinterToWindow1(gText_DataWillBeSaved);
        (*state)++;
        break;
    case 1:
        TrySavingData(SAVE_NORMAL);
        (*state)++;
        break;
    case 2:
        AddTextPrinterToWindow1(gText_SaveCompletedPressA);
        (*state)++;
        break;
    case 3:
        if (({JOY_NEW(A_BUTTON | B_BUTTON);}))
        {
            (*state)++;
        }
        break;
    case 4:
        *state = 0;
        ClearTextWindow();
        return TRUE;
    }

    return FALSE;
}

static const u8 * GetClientResultMessage(u32 * a0, u8 a1, u8 cardOrNews, u32 msgId)
{
    const u8 * msg = NULL;
    //*a0 = 0;
	
	msg = gText_WonderCardReceived;

    /*/switch (msgId)
    {
    case 0:
        *a0 = 0;
        msg = gText_NothingSentOver;
        break;
    case 1:
        *a0 = 0;
        msg = gText_RecordUploadedViaWireless;
        break;
    case 2:
        *a0 = 1;
        msg = cardOrNews == 0 ? gText_WonderCardReceived : gText_WonderCardReceivedFrom;
        break;
    case 3:
        *a0 = 1;
        msg = cardOrNews == 0 ? gText_WonderNewsReceived : gText_WonderNewsReceivedFrom;
        break;
    case 4:
        *a0 = 1;
        msg = gText_NewStampReceived;
        break;
    case 5:
        *a0 = 0;
        msg = gText_AlreadyHadCard;
        break;
    case 6:
        *a0 = 0;
        msg = gText_AlreadyHadStamp;
        break;
    case 7:
        *a0 = 0;
        msg = gText_AlreadyHadNews;
        break;
    case 8:
        *a0 = 0;
        msg = gText_NoMoreRoomForStamps;
        break;
    case 9:
        *a0 = 0;
        msg = gText_CommunicationCanceled;
        break;
    case 10:
        *a0 = 0;
        msg = a1 == 0 ? gText_CantAcceptCardFromTrainer : gText_CantAcceptNewsFromTrainer;
        break;
    case 11:
        *a0 = 0;
        msg = gText_CommunicationError;
        break;
    case 12:
        *a0 = 1;
        msg = gText_NewTrainerReceived;
        break;
    case 13:
        *a0 = 1;
        break;
    case 14:
        *a0 = 0;
        break;
    }/*/

    return msg;
}

static bool32 PrintMGSuccessMessage(u8 * state, const u8 * arg1, u16 * arg2)
{
	switch (*state)
    {
    case 0:
		if (arg1 != NULL)
		{
			AddTextPrinterToWindow1(arg1);
		}
			
		PlayFanfare(MUS_OBTAIN_ITEM);
        *arg2 = 0;
        *state = 2;
        break;
    case 1:
        if (++(*arg2) > 0xF0)
        {
            (*state)++;
        }
        break;
    case 2:
        if (IsFanfareTaskInactive())
        {
            *state = 0;
            ClearTextWindow();
            return TRUE;
        }
        break;
    }
    return FALSE;
}

static const u8 * mevent_message_stamp_card_etc_send_status(u32 * a0, u8 unused, u32 msgId)
{
    const u8 * result = gText_CommunicationError;
	
	return result;
}

static bool32 PrintMGSendStatus(u8 * state, u16 * arg1, u8 arg2, u32 msgId)
{
    //u32 flag;
	//const u8 * str = mevent_message_stamp_card_etc_send_status(&flag, arg2, msgId);
	static const u8 gText_MysteryGiftSaved[] =  _("Your Mystery Gift has been received, look\nin your party or boxes for your Gift!$");
	const u8 * str = gText_MysteryGiftSaved;
	
    return GiveMysteryGiftMonAndPrintMSG(state, str, arg1);
}

struct MysteryGiftMonStructure
{
    u16 species;
    u16 helditem;
	u8 abilityNum;
    u8 level;
	u8 nature;
	u8 pokeball;
	u16 moves[MAX_MON_MOVES];
    bool8 isShiny;
	u16 ivs[NUM_STATS];
	u16 evs[NUM_STATS];
	bool8 exioliteBoost;
    u8 neededBadge;
	bool8 areYouOT;
	const u8 otName[11];
	u16 otGender:1;
	u32 trainerIDNo;
	u8 language;
	bool8 isNicknamed;
	const u8 nickname[POKEMON_NAME_LENGTH * 2];
};

struct MysteryGiftMonStructure gMysteryGiftMons[] =
{
	[CARD_TEST] =
    {
		.species 			= SPECIES_BULBASAUR,
		.helditem 			= ITEM_NONE,
		.abilityNum 		= 0,
		.level 				= 5,
		.nature				= NATURE_TIMID,
		.pokeball 			= ITEM_CHERISH_BALL,
		.moves				= {MOVE_TACKLE, MOVE_NONE, MOVE_NONE, MOVE_NONE},
		.isShiny 			= FALSE,
		.ivs 				= {31, 31, 31, 31, 31, 31},
		.evs 				= {0, 0, 0, 0, 0, 0},
		.exioliteBoost 		= FALSE,
		.neededBadge 		= 0,
		.areYouOT		    = TRUE,
		.otName 			= _("You"),
		.otGender 			= 0,
		.trainerIDNo	    = 0,
		.language           = LANGUAGE_ENGLISH,
		.nickname 			= _("No Nickname"),
		.isNicknamed		= FALSE,
	},
	[CARD_VIVILLON_1] =
    {
		.species 			= SPECIES_VIVILLON_POKE_BALL,
		.helditem 			= ITEM_POKE_BALL_SEAL,
		.abilityNum 		= 0,
		.level 				= 0,
		.nature				= NATURE_TIMID,
		.pokeball 			= ITEM_CHERISH_BALL,
		.moves				= {MOVE_STUN_SPORE, MOVE_GUST, MOVE_LIGHT_SCREEN, MOVE_STRUGGLE_BUG},
		.isShiny 			= FALSE,
		.ivs 				= {31, 31, 31, 31, 31, 31},
		.evs 				= {0, 0, 0, 0, 0, 0},
		.exioliteBoost 		= FALSE,
		.neededBadge 		= 0,
		.areYouOT		    = TRUE,
		.otName 			= _("You"),
		.otGender 			= 0,
		.trainerIDNo	    = 0,
		.language           = LANGUAGE_ENGLISH,
		.nickname 			= _("No Nickname"),
		.isNicknamed		= FALSE,
	},
	[CARD_GRENINJA] =
    {
		.species 			= SPECIES_GRENINJA_BATTLE_BOND,
		.helditem 			= ITEM_SMOKE_BALL,
		.abilityNum 		= 0,
		.level 				= 37,
		.nature				= NATURE_TIMID,
		.pokeball 			= ITEM_CHERISH_BALL,
		.moves				= {MOVE_WATER_SHURIKEN, MOVE_AERIAL_ACE, MOVE_DOUBLE_TEAM, MOVE_NIGHT_SLASH},
		.isShiny 			= FALSE,
		.ivs 				= {31, 31, 31, 31, 31, 31},
		.evs 				= {0, 0, 0, 0, 0, 0},
		.exioliteBoost 		= FALSE,
		.neededBadge 		= 6,
		.areYouOT		    = TRUE,
		.otName 			= _("You"),
		.otGender 			= 0,
		.trainerIDNo	    = 0,
		.language           = LANGUAGE_ENGLISH,
		.nickname 			= _("No Nickname"),
		.isNicknamed		= FALSE,
	},
	[CARD_PICHU] =
    {
		.species 			= SPECIES_PICHU_SPIKY_EARED,
		.helditem 			= ITEM_WHITE_HERB,
		.abilityNum 		= 0,
		.level 				= 0,
		.nature				= NATURE_NAUGHTY,
		.pokeball 			= ITEM_CHERISH_BALL,
		.moves				= {MOVE_VOLT_TACKLE, MOVE_HELPING_HAND, MOVE_SWAGGER, MOVE_PAIN_SPLIT},
		.isShiny 			= FALSE,
		.ivs 				= {31, 31, 31, 31, 31, 31},
		.evs 				= {0, 0, 0, 0, 0, 0},
		.exioliteBoost 		= TRUE,
		.neededBadge 		= 0,
		.areYouOT		    = FALSE,
		.otName 			= _("Shouko"),
		.otGender 			= GENDER_FEMALE,
		.trainerIDNo	    = 1985,
		.language           = LANGUAGE_ENGLISH,
		.nickname 			= _("Pichu"),
		.isNicknamed		= TRUE,
	},
	[CARD_COSPLAY_PIKACHU] =
    {
		.species 			= SPECIES_PIKACHU_COSPLAY,
		.helditem 			= ITEM_LIGHT_BALL,
		.abilityNum 		= 0,
		.level 				= 12,
		.nature				= NATURE_TIMID,
		.pokeball 			= ITEM_CHERISH_BALL,
		.moves				= {MOVE_HOLD_HANDS, MOVE_THUNDERBOLT, MOVE_LIGHT_SCREEN, MOVE_CELEBRATE},
		.isShiny 			= FALSE,
		.ivs 				= {31, 31, 31, 31, 31, 31},
		.evs 				= {0, 0, 0, 0, 0, 0},
		.exioliteBoost 		= FALSE,
		.neededBadge 		= 0,
		.areYouOT		    = TRUE,
		.otName 			= _("You"),
		.otGender 			= 0,
		.trainerIDNo	    = 0,
		.language           = LANGUAGE_ENGLISH,
		.nickname 			= _("No Nickname"),
		.isNicknamed		= FALSE,
	},
	[CARD_PIKACHU_POP_STAR] =
    {
		.species 			= SPECIES_PIKACHU_POP_STAR,
		.helditem 			= ITEM_LIGHT_BALL,
		.abilityNum 		= 0,
		.level 				= 12,
		.nature				= NATURE_TIMID,
		.pokeball 			= ITEM_CHERISH_BALL,
		.moves				= {MOVE_HOLD_HANDS, MOVE_THUNDERBOLT, MOVE_LIGHT_SCREEN, MOVE_CELEBRATE},
		.isShiny 			= FALSE,
		.ivs 				= {31, 31, 31, 31, 31, 31},
		.evs 				= {0, 0, 0, 0, 0, 0},
		.exioliteBoost 		= FALSE,
		.neededBadge 		= 0,
		.areYouOT		    = TRUE,
		.otName 			= _("You"),
		.otGender 			= 0,
		.trainerIDNo	    = 0,
		.language           = LANGUAGE_ENGLISH,
		.nickname 			= _("No Nickname"),
		.isNicknamed		= FALSE,
	},
	[CARD_VIVILLON_2] =
    {
		.species 			= SPECIES_VIVILLON_FANCY,
		.helditem 			= ITEM_MICLE_BERRY,
		.abilityNum 		= 0,
		.level 				= 12,
		.nature				= NATURE_TIMID,
		.pokeball 			= ITEM_CHERISH_BALL,
		.moves				= {MOVE_HOLD_HANDS, MOVE_GUST, MOVE_LIGHT_SCREEN, MOVE_STRUGGLE_BUG},
		.isShiny 			= FALSE,
		.ivs 				= {31, 31, 31, 31, 31, 31},
		.evs 				= {0, 0, 0, 0, 0, 0},
		.exioliteBoost 		= FALSE,
		.neededBadge 		= 0,
		.areYouOT		    = TRUE,
		.otName 			= _("You"),
		.otGender 			= 0,
		.trainerIDNo	    = 0,
		.language           = LANGUAGE_ENGLISH,
		.nickname 			= _("No Nickname"),
		.isNicknamed		= FALSE,
	},
	[CARD_AZ_FLOETTE] =
    {
		.species 			= SPECIES_FLOETTE_ETERNAL_FLOWER,
		.helditem 			= ITEM_ROSELI_BERRY,
		.abilityNum 		= 0,
		.level 				= 50,
		.nature				= NATURE_TIMID,
		.pokeball 			= ITEM_CHERISH_BALL,
		.moves				= {MOVE_LIGHT_OF_RUIN, MOVE_WISH, MOVE_HEAL_BELL, MOVE_MISTY_TERRAIN},
		.isShiny 			= FALSE,
		.ivs 				= {31, 31, 31, 31, 31, 31},
		.evs 				= {0, 0, 0, 0, 0, 0},
		.exioliteBoost 		= FALSE,
		.neededBadge 		= 8,
		.areYouOT		    = TRUE,
		.otName 			= _("You"),
		.otGender 			= 0,
		.trainerIDNo	    = 0,
		.language           = LANGUAGE_ENGLISH,
		.nickname 			= _("No Nickname"),
		.isNicknamed		= FALSE,
	},
	[CARD_SHINY_BELDUM] =
    {
		.species 			= SPECIES_BELDUM,
		.helditem 			= ITEM_METAGROSSITE,
		.abilityNum 		= 0,
		.level 				= 5,
		.nature				= NATURE_JOLLY,
		.pokeball 			= ITEM_CHERISH_BALL,
		.moves				= {MOVE_HOLD_BACK, MOVE_IRON_HEAD, MOVE_ZEN_HEADBUTT, MOVE_IRON_DEFENSE},
		.isShiny 			= TRUE,
		.ivs 				= {31, 31, 31, 31, 31, 31},
		.evs 				= {0, 0, 0, 0, 0, 0},
		.exioliteBoost 		= FALSE,
		.neededBadge 		= 0,
		.areYouOT		    = TRUE,
		.otName 			= _("You"),
		.otGender 			= 0,
		.trainerIDNo	    = 0,
		.language           = LANGUAGE_ENGLISH,
		.nickname 			= _("No Nickname"),
		.isNicknamed		= FALSE,
	},
	[CARD_DIANCIE] =
    {
		.species 			= SPECIES_DIANCIE,
		.helditem 			= ITEM_DIANCITE,
		.abilityNum 		= 0,
		.level 				= 70,
		.nature				= NATURE_MODEST,
		.pokeball 			= ITEM_CHERISH_BALL,
		.moves				= {MOVE_DIAMOND_STORM, MOVE_MOONBLAST, MOVE_DAZZLING_GLEAM, MOVE_PROTECT},
		.isShiny 			= FALSE,
		.ivs 				= {31, 31, 31, 31, 31, 31},
		.evs 				= {0, 0, 0, 0, 0, 0},
		.exioliteBoost 		= FALSE,
		.neededBadge 		= 10,
		.areYouOT		    = TRUE,
		.otName 			= _("You"),
		.otGender 			= 0,
		.trainerIDNo	    = 0,
		.language           = LANGUAGE_ENGLISH,
		.nickname 			= _("No Nickname"),
		.isNicknamed		= FALSE,
	},
	[CARD_SHINY_EEVEE] =
    {
		.species 			= SPECIES_EEVEE,
		.helditem 			= ITEM_EXIOLITE,
		.abilityNum 		= 0,
		.level 				= 10,
		.nature				= NATURE_MODEST,
		.pokeball 			= ITEM_CHERISH_BALL,
		.moves				= {MOVE_CELEBRATE, MOVE_RETURN, MOVE_WISH, MOVE_HOLD_BACK},
		.isShiny 			= TRUE,
		.ivs 				= {31, 31, 31, 31, 31, 31},
		.evs 				= {0, 0, 0, 0, 0, 0},
		.exioliteBoost 		= FALSE,
		.neededBadge 		= 0,
		.areYouOT		    = TRUE,
		.otName 			= _("You"),
		.otGender 			= 0,
		.trainerIDNo	    = 0,
		.language           = LANGUAGE_ENGLISH,
		.nickname 			= _("No Nickname"),
		.isNicknamed		= FALSE,
	},
	[CARD_BEE_ALTARIA] =
    {
		.species 			= SPECIES_ALTARIA,
		.helditem 			= ITEM_ALTARIANITE,
		.abilityNum 		= 2,
		.level 				= 0,
		.nature				= NATURE_MODEST,
		.pokeball 			= ITEM_CHERISH_BALL,
		.moves				= {MOVE_CELEBRATE, MOVE_HELPING_HAND, MOVE_WISH, MOVE_SAFEGUARD},
		.isShiny 			= TRUE,
		.ivs 				= {31, 31, 31, 31, 31, 31},
		.evs 				= {6, 0, 0, 252, 252, 0},
		.exioliteBoost 		= TRUE,
		.neededBadge 		= 4,
		.areYouOT		    = FALSE,
		.otName 			= _("Bee"),
		.otGender 			= 0,
		.trainerIDNo	    = 2093,
		.language           = LANGUAGE_JAPANESE,
		.nickname 			= _("チルタリス"),
		.isNicknamed		= TRUE,
	},
	[CARD_CHRISTMASS_DELIBIRD] =
    {
		.species 			= SPECIES_DELIBIRD,
		.helditem 			= ITEM_CHERISH_BALL_SEAL,
		.abilityNum 		= 0,
		.level 				= 0,
		.nature				= NATURE_TIMID,
		.pokeball 			= ITEM_CHERISH_BALL,
		.moves				= {MOVE_PRESENT, MOVE_HYDRO_PUMP, MOVE_BLIZZARD, MOVE_CELEBRATE},
		.isShiny 			= TRUE,
		.ivs 				= {31, 31, 31, 31, 31, 31},
		.evs 				= {0, 0, 0, 0, 0, 0},
		.exioliteBoost 		= FALSE,
		.neededBadge 		= 0,
		.areYouOT		    = TRUE,
		.otName 			= _("You"),
		.otGender 			= 0,
		.trainerIDNo	    = 0,
		.language           = LANGUAGE_ENGLISH,
		.nickname 			= _("No Nickname"),
		.isNicknamed		= FALSE,
	},
	[CARD_COSPLAY_PIKACHU_LIBRE] =
    {
		.species 			= SPECIES_PIKACHU_LIBRE,
		.helditem 			= ITEM_LIGHT_BALL,
		.abilityNum 		= 0,
		.level 				= 0,
		.nature				= NATURE_ADAMANT,
		.pokeball 			= ITEM_CHERISH_BALL,
		.moves				= {MOVE_FLYING_PRESS, MOVE_VOLT_TACKLE, MOVE_PLAY_ROUGH, MOVE_FAKE_OUT},
		.isShiny 			= FALSE,
		.ivs 				= {31, 31, 31, 31, 31, 31},
		.evs 				= {0, 0, 0, 0, 0, 0},
		.exioliteBoost 		= FALSE,
		.neededBadge 		= 0,
		.areYouOT		    = TRUE,
		.otName 			= _("You"),
		.otGender 			= 0,
		.trainerIDNo	    = 0,
		.language           = LANGUAGE_ENGLISH,
		.nickname 			= _("No Nickname"),
		.isNicknamed		= FALSE,
	},
	[CARD_SHINY_AXEW] =
    {
		.species 			= SPECIES_AXEW,
		.helditem 			= ITEM_SOOTHE_BELL,
		.abilityNum 		= 1,
		.level 				= 0,
		.nature				= NATURE_JOLLY,
		.pokeball 			= ITEM_CHERISH_BALL,
		.moves				= {MOVE_SCRATCH, MOVE_LUNGE, MOVE_DRACO_METEOR, MOVE_DRAGON_RAGE},
		.isShiny 			= TRUE,
		.ivs 				= {31, 31, 31, 31, 31, 31},
		.evs 				= {0, 0, 0, 0, 0, 0},
		.exioliteBoost 		= FALSE,
		.neededBadge 		= 0,
		.areYouOT		    = TRUE,
		.otName 			= _("You"),
		.otGender 			= 0,
		.trainerIDNo	    = 0,
		.language           = LANGUAGE_ENGLISH,
		.nickname 			= _("No Nickname"),
		.isNicknamed		= FALSE,
	},
	[CARD_MANAPHY] =
    {
		.species 			= SPECIES_MANAPHY,
		.helditem 			= ITEM_KINGS_ROCK,
		.abilityNum 		= 0,
		.level 				= 70,
		.nature				= NATURE_TIMID,
		.pokeball 			= ITEM_CHERISH_BALL,
		.moves				= {MOVE_TAIL_GLOW, MOVE_HEART_SWAP, MOVE_WHIRLPOOL, MOVE_ACID_ARMOR},
		.isShiny 			= FALSE,
		.ivs 				= {31, 31, 31, 31, 31, 31},
		.evs 				= {0, 0, 0, 0, 0, 0},
		.exioliteBoost 		= FALSE,
		.neededBadge 		= 10,
		.areYouOT		    = TRUE,
		.otName 			= _("You"),
		.otGender 			= 0,
		.trainerIDNo	    = 0,
		.language           = LANGUAGE_ENGLISH,
		.nickname 			= _("No Nickname"),
		.isNicknamed		= FALSE,
	},
    [CARD_HALLOWEEN_GOURGEIST] =
    {
		.species 			= SPECIES_GOURGEIST_SUPER,
		.helditem 			= ITEM_RARE_CANDY,
		.abilityNum 		= 2,
		.level 				= 0,
		.nature				= NATURE_TIMID,
		.pokeball 			= ITEM_CHERISH_BALL,
		.moves				= {MOVE_WILL_O_WISP, MOVE_CELEBRATE, MOVE_TRICK_OR_TREAT, MOVE_PHANTOM_FORCE},
		.isShiny 			= TRUE,
		.ivs 				= {31, 31, 31, 31, 31, 31},
		.evs 				= {0, 0, 0, 0, 0, 0},
		.exioliteBoost 		= FALSE,
		.neededBadge 		= 0,
		.areYouOT		    = TRUE,
		.otName 			= _("You"),
		.otGender 			= 0,
		.trainerIDNo	    = 0,
		.language           = LANGUAGE_ENGLISH,
		.nickname 			= _("No Nickname"),
		.isNicknamed		= FALSE,
	},
};

static bool8 MysteryGift_GiveMysteryGiftMon(void){
	
    int sentToPc;
	struct Pokemon mon;
	struct WonderCard SavedWonderCard = *GetSavedWonderCard();
	struct MysteryGiftMonStructure SavedMysteryGiftMons = gMysteryGiftMons[SavedWonderCard.idNumber];
	bool8 isShiny 		= SavedMysteryGiftMons.isShiny;
	bool8 areYouOT 		= SavedMysteryGiftMons.areYouOT;
	bool8 isNicknamed   = SavedMysteryGiftMons.isNicknamed;
	bool8 exioliteBoost = SavedMysteryGiftMons.exioliteBoost;
	u16 speciesID 		= SavedMysteryGiftMons.species;
	u8 metLocation 	    = METLOC_FATEFUL_ENCOUNTER;
	u8 nature       	= Random() % NUM_NATURES;
	u8 pokeball     	= SavedMysteryGiftMons.pokeball;
	u8 neededBadges 	= SavedMysteryGiftMons.neededBadge;
	u8 level 			= SavedMysteryGiftMons.level;
	u16 species 		= SpeciesToPokedexNum(speciesID);
	u8 formId  			= GetFormIdFromFormSpeciesId(speciesID);
	u8 abilityNum		= SavedMysteryGiftMons.abilityNum;
	u8 otGender         = SavedMysteryGiftMons.otGender;
	u32 trainerIDNo		= SavedMysteryGiftMons.trainerIDNo;
	u8 language			= SavedMysteryGiftMons.language;
	u8 i;
	u16 nationalDexNum;
    u32 personality = Random32();
    u32 otid = gSaveBlock2Ptr->playerTrainerId[0]
            | (gSaveBlock2Ptr->playerTrainerId[1] << 8)
            | (gSaveBlock2Ptr->playerTrainerId[2] << 16)
            | (gSaveBlock2Ptr->playerTrainerId[3] << 24);
	
	//If its level 0 it scales to your number of badges
	if(level == 0)
		level = getGymLeaderMinLevel();

    if(!areYouOT)
		otid = trainerIDNo;

	//Shinyness
    if (isShiny == 1)
    {
        do
        {
            personality = Random32();
            personality = ((((Random() % 8) ^ (HIHALF(otid) ^ LOHALF(otid))) ^ LOHALF(personality)) << 16) | LOHALF(personality);
        } while (nature != GetNatureFromPersonality(personality));
    }

    CreateMon(&mon, speciesID, level, 32, 1, personality, OT_ID_PRESET, otid, formId);
	
	SetMonData(&mon, MON_DATA_POKEBALL, &pokeball);
	
	SetMonData(&mon, MON_DATA_MET_LOCATION, &metLocation);
	
	//Original Trainer
	if(areYouOT){
		SetMonData(&mon, MON_DATA_OT_NAME, gSaveBlock2Ptr->playerName);
		SetMonData(&mon, MON_DATA_OT_GENDER, &gSaveBlock2Ptr->playerGender);
	}
	else{
		SetMonData(&mon, MON_DATA_OT_NAME, &SavedMysteryGiftMons.otName);
		SetMonData(&mon, MON_DATA_OT_GENDER, &otGender);
		SetMonData(&mon, MON_DATA_OT_ID, &trainerIDNo);
	}
	
	if(isNicknamed)
		SetMonData(&mon, MON_DATA_NICKNAME, &SavedMysteryGiftMons.nickname);
	
	SetMonData(&mon, MON_DATA_MET_LOCATION, &metLocation);
	SetMonData(&mon, MON_DATA_LANGUAGE, &language);
	
	//Exiolite Boost
	if(exioliteBoost)
		SetMonData(&mon, MON_DATA_EXIOLITE_ENABLED, &exioliteBoost);
	
	//EVs/IVs
    for (i = 0; i < NUM_STATS; i++)
    {
        if (SavedMysteryGiftMons.ivs[i] != 32 && SavedMysteryGiftMons.ivs[i] != 0xFF)
            SetMonData(&mon, MON_DATA_HP_IV + i, &SavedMysteryGiftMons.ivs[i]);
		
		SetMonData(&mon, MON_DATA_HP_EV + i, &SavedMysteryGiftMons.evs[i]);
    }
    CalculateMonStats(&mon);
	
	//Held Item
	SetMonData(&mon, MON_DATA_HELD_ITEM, &SavedMysteryGiftMons.helditem);
	
	//Hidden Nature
	SetMonData(&mon, MON_DATA_HIDDEN_NATURE, &SavedMysteryGiftMons.nature);
	
	//Moves
    for (i = 0; i < MAX_MON_MOVES; i++)
    {
        if (SavedMysteryGiftMons.moves[i] == 0 || SavedMysteryGiftMons.moves[i] == 0xFF || SavedMysteryGiftMons.moves[i] > MOVES_COUNT)
            continue;

        SetMonMoveSlot(&mon, SavedMysteryGiftMons.moves[i], i);
    }

	//Ability Num
    SetMonData(&mon, MON_DATA_ABILITY_NUM, &abilityNum);
	
    for (i = 0; i < PARTY_SIZE; i++)
    {
        if (GetMonData(&gPlayerParty[i], MON_DATA_SPECIES, NULL) == SPECIES_NONE)
            break;
    }
	
	if(GetNumBadges() >= neededBadges){
		if (i >= PARTY_SIZE)
			sentToPc = SendMonToPC(&mon);
		else
		{
			sentToPc = MON_GIVEN_TO_PARTY;
			CopyMon(&gPlayerParty[i], &mon, sizeof(mon));
			gPlayerPartyCount = i + 1;
		}
	}
	else
		sentToPc = MON_CANT_GIVE;
	
	//Pokedex entry
    nationalDexNum = SpeciesToNationalPokedexNum(species); 
    switch(sentToPc)
    {
    case MON_GIVEN_TO_PARTY:
    case MON_GIVEN_TO_PC:
        GetSetPokedexFlag(nationalDexNum, FLAG_SET_SEEN);
        GetSetPokedexFlag(nationalDexNum, FLAG_SET_CAUGHT);
		FlagSet(SavedWonderCard.flagId);
        break;
    case MON_CANT_GIVE:
		return FALSE;
        break;
    }
	
	return TRUE;
}

static bool32 GiveMysteryGiftMonAndPrintMSG(u8 * state, const u8 * arg1, u16 * arg2)
{
	static const u8 gText_MysteryDenied[] =  _("You are too early in the game for\nthis gift, please advance a little further!$");
	
	switch (*state)
    {
    case 0:
		if(MysteryGift_GiveMysteryGiftMon()){
			if (arg1 != NULL)
			{
				AddTextPrinterToWindow1(arg1);
			}
			
			PlayFanfare(MUS_OBTAIN_ITEM);
		}
		else{
			if (arg1 != NULL)
			{
				AddTextPrinterToWindow1(gText_MysteryDenied);
			}
			PlayFanfare(SE_BOO);
		}
        *arg2 = 0;
        (*state)++;
        break;
    case 1:
        if (++(*arg2) > 0xF0)
        {
            (*state)++;
        }
        break;
    case 2:
        if (IsFanfareTaskInactive())
        {
            *state = 0;
            ClearTextWindow();
            return TRUE;
        }
        break;
    }
    return FALSE;
}

void CreateMysteryGiftTask(void)
{
    u8 taskId = CreateTask(Task_MysteryGift, 0);
    struct MysteryGiftTaskData * data = (void *)gTasks[taskId].data;
    data->state 			= 0;
    data->textState 		= 0;
    data->unused4 			= 0;
    data->unused5 			= 0;
    data->isWonderNews 		= 0;
    data->sourceIsFriend 	= 0;
    data->var 				= 0;
    data->unused1 			= 0;
    data->unused2 			= 0;
    data->unused3 			= 0;
    data->msgId 			= 0;
    data->clientMsg = AllocZeroed(0x40);
}

void Task_MysteryGift(u8 taskId)
{
    struct MysteryGiftTaskData *data = (void *)gTasks[taskId].data;
	struct WonderCard SavedWonderCard = *GetSavedWonderCard();
	//struct MysteryGiftTaskData *data = &SavedMysteryGiftTaskData[CARD_TEST];
    u32 sp0, flag;
    const u8 *r1;

    switch (data->state)
    {
    case  0:
        data->state = 1;
        break;
    case  1:
        switch (MysteryGift_HandleThreeOptionMenu(&data->textState, &data->var, FALSE))
        {
        case 0:
            data->isWonderNews = 0;
            data->state = 13;
            break;
        case 1:
            data->isWonderNews = 1;
			if(FlagGet(SavedWonderCard.flagId))
			{
                data->state = 18;
            }
			else
			{
                data->state = 2;
            }
            break;
        case -2u:
            data->state = 37;
            break;
        }
        break;
    case  2:
    {
        if (MG_PrintTextOnWindow1AndWaitButton(&data->textState, gText_NoMysterGift))
        {
            data->state = 0;
        }
        break;
    }
    case  3:
        if (MG_PrintTextOnWindow1AndWaitButton(&data->textState, gText_AlreadyHaveCard))
        {
            data->state = 0;
        }
        break;
    case  4:
        switch (MysteryGift_HandleThreeOptionMenu(&data->textState, &data->var, TRUE))
        {
        case 0:
            ClearTextWindow();
            data->state = 5;
            data->sourceIsFriend = 0;
            break;
        case 1:
            ClearTextWindow();
            data->state = 5;
            data->sourceIsFriend = 1;
            break;
        case -2u:
            ClearTextWindow();
            if (ValidateCardOrNews(data->isWonderNews))
            {
                data->state = 18;
            }
            else
            {
                data->state = 0;
                PrintMysteryGiftOrEReaderTopMenu(0, 0);
            }
            break;
        }
        break;
    case  5:
        *gStringVar1 = EOS;
        *gStringVar2 = EOS;
        *gStringVar3 = EOS;

        switch (data->isWonderNews)
        {
        case 0:
            if (data->sourceIsFriend == 1)
            {
                MEvent_CreateTask_CardOrNewsWithFriend(ACTIVITY_WONDER_CARD2);
            }
            else if (data->sourceIsFriend == 0)
            {
                MEvent_CreateTask_CardOrNewsOverWireless(ACTIVITY_WONDER_CARD2);
            }
            break;
        case 1:
            if (data->sourceIsFriend == 1)
            {
                MEvent_CreateTask_CardOrNewsWithFriend(ACTIVITY_WONDER_NEWS2);
            }
            else if (data->sourceIsFriend == 0)
            {
                MEvent_CreateTask_CardOrNewsOverWireless(ACTIVITY_WONDER_NEWS2);
            }
            break;
        }
        data->state = 6;
        break;
    case  6:
        if (gReceivedRemoteLinkPlayers != 0)
        {
            ClearScreenInBg0(TRUE);
            data->state = 7;
            mevent_client_do_init(data->isWonderNews);
        }
        else if (gSpecialVar_Result == LINKUP_FAILED)
        {
            ClearScreenInBg0(TRUE);
            data->state = 3;
        }
        break;
    case  7:
        AddTextPrinterToWindow1(gText_Communicating);
        data->state = 8;
        break;
    case  8:
        switch (mevent_client_do_exec(&data->var))
        {
        case 6:
            Rfu_SetCloseLinkCallback();
            data->msgId = data->var;
            data->state = 13;
            break;
        case 5:
            memcpy(data->clientMsg, MysteryGiftClient_GetMsg(), 0x40);
            mevent_client_inc_flag();
            break;
        case 3:
            data->state = 10;
            break;
        case 2:
            data->state = 9;
            break;
        case 4:
            data->state = 11;
            StringCopy(gStringVar1, gLinkPlayers[0].name);
            break;
        }
        break;
    case  9:
        flag = mevent_message_print_and_prompt_yes_no(&data->textState, &data->var, FALSE, MysteryGiftClient_GetMsg());
        switch (flag)
        {
        case 0:// Yes
            mevent_client_set_param(0);
            mevent_client_inc_flag();
            data->state = 7;
            break;
        case 1: // No
            mevent_client_set_param(1);
            mevent_client_inc_flag();
            data->state = 7;
            break;
        case -1u:
            mevent_client_set_param(1);
            mevent_client_inc_flag();
            data->state = 7;
            break;
        }
        break;
    case 10:
        if (MG_PrintTextOnWindow1AndWaitButton(&data->textState, MysteryGiftClient_GetMsg()))
        {
            mevent_client_inc_flag();
            data->state = 7;
        }
        break;
    case 11:
        flag = mevent_message_print_and_prompt_yes_no(&data->textState, &data->var, FALSE, gText_ThrowAwayWonderCard);
        switch (flag)
        {
        case 0:
            if (CheckReceivedGiftFromWonderCard() == TRUE)
            {
                data->state = 12;
            }
            else
            {
                mevent_client_set_param(0);
                mevent_client_inc_flag();
                data->state = 7;
            }
            break;
        case 1:
            mevent_client_set_param(1);
            mevent_client_inc_flag();
            data->state = 7;
            break;
        case -1u:
            mevent_client_set_param(1);
            mevent_client_inc_flag();
            data->state = 7;
            break;
        }
        break;
    case 12:
        flag = mevent_message_print_and_prompt_yes_no(&data->textState, &data->var, FALSE, gText_HaventReceivedCardsGift);
        switch (flag)
        {
        case 0:
            mevent_client_set_param(0);
            mevent_client_inc_flag();
            data->state = 7;
            break;
        case 1:
            mevent_client_set_param(1);
            mevent_client_inc_flag();
            data->state = 7;
            break;
        case -1u:
            mevent_client_set_param(1);
            mevent_client_inc_flag();
            data->state = 7;
            break;
        }
        break;
    case 13://MG_STATE_CLIENT_COMMUNICATING
		if (PrintStringAndWait2Seconds(&data->textState, gText_Communicating))
        {
            DestroyWirelessStatusIndicatorSprite();
			data->state = 14;
        }
        break;
    case 14:
        if (PrintStringAndWait2Seconds(&data->textState, gText_CommunicationCompleted))
        {
            if (data->sourceIsFriend == 1)
            {
                StringCopy(gStringVar1, gLinkPlayers[0].name);
            }
			
			if(!FlagGet(SavedWonderCard.flagId))
				data->state = 15;
			else
				data->state = 3;
        }
        break;
    case 15:
        r1 = GetClientResultMessage(&sp0, data->isWonderNews, data->sourceIsFriend, data->msgId);
        if (r1 == NULL)
        {
            r1 = data->clientMsg;
        }
        if (sp0)
        {
            flag = PrintMGSuccessMessage(&data->textState, r1, &data->var);
        }
        else
        {
            flag = MG_PrintTextOnWindow1AndWaitButton(&data->textState, r1);
        }
        if (flag)
        {
            if (data->msgId == 3)
            {
                if (data->sourceIsFriend == 1)
                {
                    GenerateRandomNews(1);
                }
                else
                {
                    GenerateRandomNews(2);
                }
            }
            if (!sp0)
            {
                data->state = 0;
                PrintMysteryGiftOrEReaderTopMenu(0, 0);
            }
            else
            {
                data->state = 17;
            }
        }
        break;
    case 16:
        if (MG_PrintTextOnWindow1AndWaitButton(&data->textState, gText_CommunicationError))
        {
            data->state = 0;
            PrintMysteryGiftOrEReaderTopMenu(0, 0);
        }
        break;
    case 17:
        if (SaveOnMysteryGiftMenu(&data->textState))
        {
            data->state = 18;
        }
        break;
    case 18:
        if (HandleLoadWonderCardOrNews(&data->textState, 0))
        {
			data->isWonderNews = 0;
            data->state = 20;
        }
        break;
    case 20:
        if (!FlagGet(SavedWonderCard.flagId))
        {
            if (({JOY_NEW(A_BUTTON);}))
            {
                data->state = 21;
            }
            if (({JOY_NEW(B_BUTTON);}))
            {
                data->state = 27;
            }
        }
        else
        {
            if (({JOY_NEW(A_BUTTON);}))
            {
                data->state = 27;
            }
            if (({JOY_NEW(B_BUTTON);}))
            {
                data->state = 27;
            }
        }
        break;
    case 21:
    {
		//MG_STATE_HANDLE_GIFT_SELECT:
		// A Wonder Card/News has been selected, handle its menu
        u32 result = HandleMysteryGiftListMenu(&data->textState, &data->var, data->isWonderNews, TRUE);
        switch (result)
        {
        case 0: // Receive
            data->state = 28;
            break;
        case 1: // Send
            data->state = 29;
            break;
        case 2: // Toss
            data->state = 22;
            break;
        case -2u:
            if (data->isWonderNews == 1)
            {
                MENews_AddScrollIndicatorArrowPair();
            }
            data->state = 20;
            break;
        }
        break;
    }
    case 22:
		//MG_STATE_ASK_TOSS:
        switch (mevent_message_prompt_discard(&data->textState, &data->var, data->isWonderNews))
        {
        case 0:
            if (data->isWonderNews == 0 && CheckReceivedGiftFromWonderCard() == TRUE)
            {
                data->state = 23;
            }
            else
            {
                data->state = 24;
            }
            break;
        case 1:
            data->state = 21;
            break;
        case -1:
            data->state = 21;
            break;
        }
        break;
    case 23:
		//MG_STATE_ASK_TOSS_UNRECEIVED:
        // Player has selected to toss a Wonder Card that they haven't received the gift for.
        // Ask for confirmation again.
        switch ((u32)mevent_message_print_and_prompt_yes_no(&data->textState, &data->var, TRUE, gText_HaventReceivedGiftOkayToDiscard))
        {
        case 0:
            data->state = 24;
            break;
        case 1:
            data->state = 21;
            break;
        case -1u:
            data->state = 21;
            break;
        }
        break;
    case 24:
		//MG_STATE_TOSS:
        if (TearDownCardOrNews_ReturnToTopMenu(data->isWonderNews, 1))
        {
            DestroyNewsOrCard(data->isWonderNews);
            data->state = 25;
        }
        break;
    case 25:
		//MG_STATE_TOSS_SAVE:
        if (SaveOnMysteryGiftMenu(&data->textState))
        {
            data->state = 26;
        }
        break;
    case 26:
		//MG_STATE_TOSSED:
        if (PrintThrownAway(&data->textState, data->isWonderNews))
        {
            data->state = 0;
            PrintMysteryGiftOrEReaderTopMenu(0, 0);
			FlagSet(SavedWonderCard.flagId);
        }
        break;
    case 27:
		//MG_STATE_GIFT_INPUT_EXIT:
        if (TearDownCardOrNews_ReturnToTopMenu(data->isWonderNews, 0))
        {
            data->state = 0;
        }
        break;
    case 28:
		//MG_STATE_RECEIVE:
        if (TearDownCardOrNews_ReturnToTopMenu(data->isWonderNews, 1))
        {
            //data->state = 3;
			data->state = 35;
        }
        break;
    case 29:
		//MG_STATE_SEND:
        if (TearDownCardOrNews_ReturnToTopMenu(data->isWonderNews, 1))
        {
            switch (data->isWonderNews)
            {
            case 0:
                MEvent_CreateTask_Leader(ACTIVITY_WONDER_CARD2);
                break;
            case 1:
                MEvent_CreateTask_Leader(ACTIVITY_WONDER_NEWS2);
                break;
            }
            data->sourceIsFriend = 1;
            data->state = 30;
        }
        break;
    case 30:
		//MG_STATE_SERVER_LINK_WAIT:
        if (gReceivedRemoteLinkPlayers != 0)
        {
            ClearScreenInBg0(1);
            data->state = 31;
        }
        else if (gSpecialVar_Result == LINKUP_FAILED)
        {
            ClearScreenInBg0(1);
            data->state = 18;
        }
        break;
    case 31:
		//MG_STATE_SERVER_LINK_START:
        *gStringVar1 = EOS;
        *gStringVar2 = EOS;
        *gStringVar3 = EOS;

        if (data->isWonderNews == 0)
        {
            AddTextPrinterToWindow1(gText_SendingWonderCard);
            mevent_srv_new_wcard();
        }
        else
        {
            AddTextPrinterToWindow1(gText_SendingWonderNews);
            mevent_srv_init_wnews();
        }
        data->state = 32;
        break;
    case 32:
		//MG_STATE_SERVER_LINK:
        if (mevent_srv_common_do_exec(&data->var) == 3)
        {
            data->msgId = data->var;
            data->state = 33;
        }
        break;
    case 33:
		//MG_STATE_SERVER_LINK_END:
        Rfu_SetCloseLinkCallback();
        StringCopy(gStringVar1, gLinkPlayers[1].name);
        data->state = 34;
        break;
    case 34:
		//MG_STATE_SERVER_LINK_END_WAIT:
        if (gReceivedRemoteLinkPlayers == 0)
        {
            DestroyWirelessStatusIndicatorSprite();
            data->state = 35;
        }
        break;
    case 35:
		//MG_STATE_SERVER_RESULT_MSG:
        if (PrintMGSendStatus(&data->textState, &data->var, data->sourceIsFriend, data->msgId))
        {
            if (data->sourceIsFriend == 1 && data->msgId == 3)
            {
                GenerateRandomNews(3);
                data->state = 17;
            }
            else
            {
                data->state = 0;
                PrintMysteryGiftOrEReaderTopMenu(0, 0);
            }
        }
        break;
    case 36:
			//case MG_STATE_CLIENT_ERROR:
			//case MG_STATE_SERVER_ERROR:
        if (MG_PrintTextOnWindow1AndWaitButton(&data->textState, gText_CommunicationError))
        {
            data->state = 0;
            PrintMysteryGiftOrEReaderTopMenu(0, 0);
        }
        break;
    case 37:
		//case MG_STATE_EXIT:
        CloseLink();
        Free(data->clientMsg);
        DestroyTask(taskId);
        SetMainCallback2(MainCB_FreeAllBuffersAndReturnToInitTitleScreen);
        break;
    }
}

u16 GetMysteryGiftBaseBlock(void)
{
    return 0x1A9;
}

void LoadMysteryGiftTextboxBorder(u8 bgId)
{
    DecompressAndLoadBgGfxUsingHeap(bgId, sTextboxBorder_Gfx, 0x100, 0, 0);
}
