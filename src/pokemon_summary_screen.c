#include "global.h"
#include "main.h"
#include "battle.h"
#include "battle_anim.h"
#include "frontier_util.h"
#include "battle_message.h"
#include "battle_tent.h"
#include "battle_factory.h"
#include "bg.h"
#include "contest.h"
#include "contest_effect.h"
#include "data.h"
#include "daycare.h"
#include "decompress.h"
#include "dynamic_placeholder_text_util.h"
#include "event_data.h"
#include "gpu_regs.h"
#include "graphics.h"
#include "international_string_util.h"
#include "item.h"
#include "link.h"
#include "m4a.h"
#include "malloc.h"
#include "menu.h"
#include "menu_helpers.h"
#include "mon_markings.h"
#include "party_menu.h"
#include "palette.h"
#include "pokeball.h"
#include "pokemon.h"
#include "pokedex.h"
#include "pokemon_storage_system.h"
#include "pokemon_summary_screen.h"
#include "region_map.h"
#include "scanline_effect.h"
#include "sound.h"
#include "sprite.h"
#include "string_util.h"
#include "strings.h"
#include "task.h"
#include "text.h"
#include "text_window.h"
#include "tv.h"
#include "window.h"
#include "constants/abilities.h"
#include "constants/items.h"
#include "constants/moves.h"
#include "constants/party_menu.h"
#include "constants/region_map_sections.h"
#include "constants/rgb.h"
#include "constants/songs.h"
#include "constants/battle_config.h"
#include "printf.h"
#include "mgba.h"

// Screen titles (upper left)
#define PSS_WINDOW_TOP 0
#define PSS_WINDOW_MIDDLE_RIGHT 1
#define PSS_WINDOW_MIDDLE_LEFT 2
#define PSS_WINDOW_BOTTOM 3

// Button control text (upper right)
#define PSS_LABEL_WINDOW_PROMPT_SWITCH 6
#define PSS_LABEL_WINDOW_HELD_ITEM 7

// Info screen
#define PSS_LABEL_WINDOW_POKEMON_INFO_RENTAL 8

// Skills screen
#define PSS_LABEL_WINDOW_POKEMON_SKILLS_STATS_LEFT 10 // HP, Attack, Defense
#define PSS_LABEL_WINDOW_POKEMON_SKILLS_STATS_RIGHT 11 // Sp. Attack, Sp. Defense, Speed
#define PSS_LABEL_WINDOW_POKEMON_SKILLS_EXP 12 // EXP, Next Level
#define PSS_LABEL_WINDOW_POKEMON_SKILLS_STATUS 13

// Moves screen
#define PSS_LABEL_WINDOW_MOVES_POWER_ACC 14 // Also contains the power and accuracy values
#define PSS_LABEL_WINDOW_MOVES_APPEAL_JAM 15
#define PSS_LABEL_WINDOW_UNUSED2 16

// Above/below the pokemon's portrait (left)
#define PSS_LABEL_WINDOW_PORTRAIT_DEX_NUMBER 17
#define PSS_LABEL_WINDOW_PORTRAIT_NICKNAME 18 // The upper name
#define PSS_LABEL_WINDOW_PORTRAIT_SPECIES 19 // The lower name
#define PSS_LABEL_WINDOW_END 20

// Dynamic fields for the Pokemon Info page
#define PSS_DATA_WINDOW_INFO_ID 1
#define PSS_DATA_WINDOW_INFO_ABILITY 2
#define PSS_DATA_WINDOW_INFO_MEMO 3

// Dynamic fields for the Pokemon Skills page
#define PSS_DATA_WINDOW_SKILLS_HELD_ITEM 0
#define PSS_DATA_WINDOW_SKILLS_RIBBON_COUNT 1
#define PSS_DATA_WINDOW_SKILLS_STATS_LEFT 2 // HP, Attack, Defense
#define PSS_DATA_WINDOW_SKILLS_STATS_RIGHT 3 // Sp. Attack, Sp. Defense, Speed
#define PSS_DATA_WINDOW_EXP 4 // Exp, next level

// Dynamic fields for the Battle Moves and Contest Moves pages.
#define PSS_DATA_WINDOW_MOVE_NAMES 0
#define PSS_DATA_WINDOW_MOVE_PP 1
#define PSS_DATA_WINDOW_MOVE_DESCRIPTION 2

#define MOVE_SELECTOR_SPRITES_COUNT 10
// for the spriteIds field in PokemonSummaryScreenData
enum
{
    SPRITE_ARR_ID_MON,
    SPRITE_ARR_ID_BALL,
    SPRITE_ARR_ID_STATUS,
    SPRITE_ARR_ID_TYPE, // 2 for mon types, 5 for move types(4 moves and 1 to learn), used interchangeably, because mon types and move types aren't shown on the same screen
    SPRITE_ARR_ID_MOVE_SELECTOR1 = SPRITE_ARR_ID_TYPE + 5, // 10 sprites that make up the selector
    SPRITE_ARR_ID_MOVE_SELECTOR2 = SPRITE_ARR_ID_MOVE_SELECTOR1 + MOVE_SELECTOR_SPRITES_COUNT,
    SPRITE_ARR_ID_COUNT = SPRITE_ARR_ID_MOVE_SELECTOR2 + MOVE_SELECTOR_SPRITES_COUNT
};

static EWRAM_DATA struct PokemonSummaryScreenData
{
    /*0x00*/ union {
        struct Pokemon *mons;
        struct BoxPokemon *boxMons;
    } monList;
    /*0x04*/ MainCallback callback;
    /*0x08*/ struct Sprite *markingsSprite;
    /*0x0C*/ struct Pokemon currentMon;
    /*0x70*/ struct PokeSummary
    {
        u16 species:11; // 0x0
        u16 formId:5; // 0x1
        u16 species2; // 0x2
        u8 isEgg; // 0x4
        u8 level; // 0x5
        u8 ribbonCount; // 0x6
        u8 ailment; // 0x7
        u8 abilityNum; // 0x8
        u8 metLocation; // 0x9
        u8 metLevel; // 0xA
        u8 metGame; // 0xB
        u32 pid; // 0xC
        u32 exp; // 0x10
        u16 moves[MAX_MON_MOVES]; // 0x14
        u8 pp[MAX_MON_MOVES]; // 0x1C
        u16 currentHP; // 0x20
        u16 maxHP; // 0x22
        u16 atk; // 0x24
        u16 def; // 0x26
        u16 spatk; // 0x28
        u16 spdef; // 0x2A
        u16 speed; // 0x2C
        u16 item; // 0x2E
        u16 friendship; // 0x30
        u8 OTGender; // 0x32
        u8 nature; // 0x33
        u8 ppBonuses; // 0x34
        u8 sanity; // 0x35
        u8 OTName[17]; // 0x36
		u8 hidden_nature;
        u32 OTID; // 0x48
    } summary;
    u16 bgTilemapBuffers[PSS_PAGE_COUNT][2][0x400];
    u8 mode;
    bool8 isBoxMon;
    u8 curMonIndex;
    u8 maxMonIndex;
    u8 currPageIndex;
    u8 minPageIndex;
    u8 maxPageIndex;
    bool8 lockMonFlag; // This is used to prevent the player from changing pokemon in the move deleter select, etc, but it is not needed because the input is handled differently there
    u16 newMove;
    u8 firstMoveIndex;
    u8 secondMoveIndex;
    bool8 lockMovesFlag; // This is used to prevent the player from changing position of moves in a battle or when trading.
    u8 bgDisplayOrder; // Determines the order page backgrounds are loaded while scrolling between them
    u8 windowIds[8];
    u8 spriteIds[SPRITE_ARR_ID_COUNT];
    bool8 unk40EF;
    bool8 disableTransparency;
    s16 switchCounter; // Used for various switch statement cases that decompress/load graphics or pokemon data
    u8 splitIconSpriteId;
    bool8 ModifyStatMode;
    u8 gCurrentStattoModify;
} *sMonSummaryScreen = NULL;

EWRAM_DATA u8 gLastViewedMonIndex = 0;
static EWRAM_DATA u8 sMoveSlotToReplace = 0;
ALIGNED(4) static EWRAM_DATA u8 sUnknownTaskId = 0;

// forward declarations
static bool8 LoadGraphics(void);
static void CB2_InitSummaryScreen(void);
static void InitBGs(void);
static bool8 DecompressGraphics(void);
static void CopyMonToSummaryStruct(struct Pokemon* a);
static bool8 ExtractMonDataToSummaryStruct(struct Pokemon* a);
static void SetDefaultTilemaps(void);
static void CloseSummaryScreen(u8 taskId);
static void Task_HandleInput(u8 taskId);
static void ChangeSummaryPokemon(u8 taskId, s8 a);
static void Task_ChangeSummaryMon(u8 taskId);
static s8 AdvanceMonIndex(s8 delta);
static s8 AdvanceMultiBattleMonIndex(s8 delta);
static bool8 IsValidToViewInMulti(struct Pokemon* mon);
static void ChangePage(u8 taskId, s8 a);
static void PssScrollRight(u8 taskId);
static void PssScrollRightEnd(u8 taskId);
static void PssScrollLeft(u8 taskId);
static void PssScrollLeftEnd(u8 taskId);
static void TryDrawExperienceProgressBar(void);
static void SwitchToMoveSelection(u8 taskId);
static void Task_HandleInput_MoveSelect(u8 taskId);
static bool8 HasMoreThanOneMove(void);
static void ChangeSelectedMove(s16 *taskData, s8 direction, u8 *moveIndexPtr);
static void CloseMoveSelectMode(u8 taskId);
static void SwitchToMovePositionSwitchMode(u8 a);
static void Task_HandleInput_MovePositionSwitch(u8 taskId);
static void ExitMovePositionSwitchMode(u8 taskId, bool8 swapMoves);
static void SwapMonMoves(struct Pokemon *mon, u8 moveIndex1, u8 moveIndex2);
static void SwapBoxMonMoves(struct BoxPokemon *mon, u8 moveIndex1, u8 moveIndex2);
static void Task_SetHandleReplaceMoveInput(u8 taskId);
static void Task_HandleReplaceMoveInput(u8 taskId);
static bool8 CanReplaceMove(void);
static void ShowCantForgetHMsWindow(u8 taskId);
static void Task_HandleInputCantForgetHMsMoves(u8 taskId);
static void DrawPagination(void);
static void HandlePowerAccTilemap(u16 a, s16 b);
static void Task_ShowPowerAccWindow(u8 taskId);
static void HandleAppealJamTilemap(u16 a, s16 b, u16 c);
static void Task_ShowAppealJamWindow(u8 taskId);
static void HandleStatusTilemap(u16 a, s16 b);
static void Task_ShowStatusWindow(u8 taskId);
static void TilemapFiveMovesDisplay(u16 *dst, u16 palette, bool8 remove);
static void DrawPokerusCuredSymbol(struct Pokemon* mon);
static void DrawExperienceProgressBar(struct Pokemon* mon);
static void DrawContestMoveHearts(u16 move);
static void LimitEggSummaryPageDisplay(void);
static void ResetWindows(void);
static void PrintMonInfo(void);
static void PrintMiddleLeftPart(void);
static void PrintEggInfo(void);
static void PrintGenderSymbol(struct Pokemon *mon, u16 a);
static void PrintPageNamesAndStats(void);
static void PutPageWindowTilemaps(u8 a);
static void ClearPageWindowTilemaps(u8 a);
static void RemoveWindowByIndex(u8 a);
static void PrintPageSpecificText(u8 a);
static void CreateTextPrinterTask(u8 a);
static void PrintInfoPageText(void);
static void Task_PrintInfoPage(u8 taskId);
static void PrintInfoPage_Midde(void);
static void PrintInfoPage_Bottom(void);
static void BufferNatureString(void);
static void GetMetLevelString(u8 *a);
static bool8 DoesMonOTMatchOwner(void);
static bool8 DidMonComeFromGBAGames(void);
static bool8 IsInGamePartnerMon(void);
static void Task_PrintSkillsPage(u8 taskId);
static void PrintStatPage_Bottom(void);
static void PrintSkillsPageText(void);
static void PrintBattleMoves(void);
static void Task_PrintBattleMoves(u8 taskId);
static void PrintMoveNameAndPP(u8 a);
static void PrintContestMoves(void);
static void Task_PrintContestMoves(u8 taskId);
static void PrintContestMoveDescription(u8 a);
static void PrintMoveDetails(u16 a);
static void PrintNewMoveDetailsOrCancelText(void);
static void AddAndFillMoveNamesWindow(void);
static void SwapMovesNamesPP(u8 moveIndex1, u8 moveIndex2);
static void PrintHMMovesCantBeForgotten(void);
static void ResetSpriteIds(void);
static void SetSpriteInvisibility(u8 spriteArrayId, bool8 invisible);
static void HidePageSpecificSprites(void);
static void SetTypeIcons(void);
static void CreateMoveTypeIcons(void);
static void SetMonTypeIcons(void);
static void SetMoveTypeIcons(void);
static void SetContestMoveTypeIcons(void);
static void SetNewMoveTypeIcon(void);
static void SwapMovesTypeSprites(u8 moveIndex1, u8 moveIndex2);
static u8 LoadMonGfxAndSprite(struct Pokemon *a, s16 *b);
static u8 CreateMonSprite(struct Pokemon *unused);
static void SpriteCB_Pokemon(struct Sprite *);
static void StopPokemonAnimations(void);
static void CreateMonMarkingsSprite(struct Pokemon *mon);
static void RemoveAndCreateMonMarkingsSprite(struct Pokemon *mon);
static void CreateCaughtBallSprite(struct Pokemon *mon);
static void CreateSetStatusSprite(void);
static void CreateMoveSelectorSprites(u8 idArrayStart);
static void SpriteCb_MoveSelector(struct Sprite *sprite);
static void DestroyMoveSelectorSprites(u8 firstArrayId);
static void SetMainMoveSelectorColor(u8 whichColor);
static void KeepMoveSelectorVisible(u8 firstSpriteId);
static void BufferStat(u8 *dst, s8 natureMod, u32 stat, u32 strId, u32 n);
static void PrintStatPage_Midde();
static void PrintMiddleRightPart(u8 page);
static void setTransparentBackground(void);
static void removeTransparentBackground(void);
static void setScrollingBackground(void);
static void setNormalBackground(void);
static void ScrollBackground(void);
static void CleanScreens(void);
// const rom data
#include "data/text/move_descriptions.h"
#include "data/text/nature_names.h"

static const struct BgTemplate sBgTemplates[] =
{
    {
        .bg = 0,
        .charBaseIndex = 0,
        .mapBaseIndex = 31,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 0,
        .baseTile = 0,
    },
    {
        .bg = 1,
        .charBaseIndex = 2,
        .mapBaseIndex = 27,
        .screenSize = 1,
        .paletteMode = 0,
        .priority = 1,
        .baseTile = 0,
    },
    {
        .bg = 2,
        .charBaseIndex = 2,
        .mapBaseIndex = 25,
        .screenSize = 1,
        .paletteMode = 0,
        .priority = 2,
        .baseTile = 0,
    },
    {
        .bg = 3,
        .charBaseIndex = 2,
        .mapBaseIndex = 29,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 3,
        .baseTile = 0,
    },
};

struct TilemapCtrl
{
    const u16 *gfx;
    u16 field_4;
    u8 field_6;
    u8 field_7;
    u8 field_8;
    u8 field_9;
};

static const u16 sStatusTilemap[] = INCBIN_U16("graphics/interface/status_tilemap.bin");
static const struct TilemapCtrl sStatusTilemapCtrl1 =
{
    sStatusTilemap, 1, 10, 2, 0, 18
};
static const struct TilemapCtrl sStatusTilemapCtrl2 =
{
    sStatusTilemap, 1, 10, 2, 0, 50
};
static const struct TilemapCtrl sBattleMoveTilemapCtrl =
{
    gSummaryScreenPowAcc_Tilemap, 0, 10, 7, 0, 45
};
static const struct TilemapCtrl sContestMoveTilemapCtrl =
{
    gSummaryScreenAppealJam_Tilemap, 0, 10, 7, 0, 45
};
static const s8 sMultiBattleOrder[] = {0, 2, 3, 1, 4, 5};

static const struct WindowTemplate sNewSummaryTemplate[] = {
    [PSS_WINDOW_TOP] = {
        .bg = 0,
        .tilemapLeft = 0,
        .tilemapTop = 0,
        .width = 30,
        .height = 2,
        .paletteNum = 6,
        .baseBlock = 1,
    },
    [PSS_WINDOW_MIDDLE_RIGHT] = {
        .bg = 0,
        .tilemapLeft = 9,
        .tilemapTop = 2,
        .width = 21,
        .height = 12,
        .paletteNum = 6,
        .baseBlock = 100,
    },
    [PSS_WINDOW_MIDDLE_LEFT] = {
        .bg = 0,
        .tilemapLeft = 0,
        .tilemapTop = 2,
        .width = 9,
        .height = 12,
        .paletteNum = 6,
        .baseBlock = 395,
    },
    [PSS_WINDOW_BOTTOM] = {
        .bg = 0,
        .tilemapLeft = 1,
        .tilemapTop = 14,
        .width = 30,
        .height = 6,
        .paletteNum = 6,
        .baseBlock = 557,
    },
    [PSS_LABEL_WINDOW_END] = DUMMY_WIN_TEMPLATE
};

static const struct WindowTemplate sSummaryTemplate[] =
{
    [PSS_LABEL_WINDOW_PROMPT_SWITCH] = {
        .bg = 0,
        .tilemapLeft = 22,
        .tilemapTop = 0,
        .width = 8,
        .height = 2,
        .paletteNum = 7,
        .baseBlock = 121,
    },
    [PSS_LABEL_WINDOW_HELD_ITEM] = {
        .bg = 0,
        .tilemapLeft = 1,
        .tilemapTop = 14,
        .width = 20,
        .height = 6,
        .paletteNum = 6,
        .baseBlock = 137,
    },
    [PSS_LABEL_WINDOW_POKEMON_INFO_RENTAL] = {
        .bg = 0,
        .tilemapLeft = 11,
        .tilemapTop = 4,
        .width = 18,
        .height = 2,
        .paletteNum = 6,
        .baseBlock = 137,
    },
    [PSS_LABEL_WINDOW_POKEMON_SKILLS_STATS_LEFT] = {
        .bg = 0,
        .tilemapLeft = 12,
        .tilemapTop = 2,
        .width = 19,
        .height = 12,
        .paletteNum = 6,
        .baseBlock = 690,
    },
    [PSS_LABEL_WINDOW_POKEMON_SKILLS_STATS_RIGHT] = {
        .bg = 0,
        .tilemapLeft = 22,
        .tilemapTop = 7,
        .width = 5,
        .height = 6,
        .paletteNum = 6,
        .baseBlock = 245,
    },
    [PSS_LABEL_WINDOW_POKEMON_SKILLS_EXP] = {
        .bg = 0,
        .tilemapLeft = 10,
        .tilemapTop = 14,
        .width = 11,
        .height = 4,
        .paletteNum = 6,
        .baseBlock = 275,
    },
    [PSS_LABEL_WINDOW_POKEMON_SKILLS_STATUS] = {
        .bg = 0,
        .tilemapLeft = 0,
        .tilemapTop = 13,
        .width = 6,
        .height = 2,
        .paletteNum = 6,
        .baseBlock = 319,
    },
    [PSS_LABEL_WINDOW_MOVES_POWER_ACC] = {
        .bg = 0,
        .tilemapLeft = 1,
        .tilemapTop = 15,
        .width = 9,
        .height = 4,
        .paletteNum = 6,
        .baseBlock = 331,
    },
    [PSS_LABEL_WINDOW_MOVES_APPEAL_JAM] = {
        .bg = 0,
        .tilemapLeft = 1,
        .tilemapTop = 15,
        .width = 5,
        .height = 4,
        .paletteNum = 6,
        .baseBlock = 367,
    },
    [PSS_LABEL_WINDOW_UNUSED2] = {//Item
        .bg = 0,
        .tilemapLeft = 20,
        .tilemapTop = 12,
        .width = 9,
        .height = 4,
        .paletteNum = 6,
        .baseBlock = 485,
    },
    [PSS_LABEL_WINDOW_PORTRAIT_DEX_NUMBER] = {
        .bg = 0,
        .tilemapLeft = 20,
        .tilemapTop = 2,
        .width = 4,
        .height = 2,
        .paletteNum = 7,
        .baseBlock = 387,
    },
    [PSS_LABEL_WINDOW_PORTRAIT_NICKNAME] = {
        .bg = 0,
        .tilemapLeft = 1,
        .tilemapTop = 2,
        .width = 12,
        .height = 4,
        .paletteNum = 6,
        .baseBlock = 395,
    },
    [PSS_LABEL_WINDOW_PORTRAIT_SPECIES] = {
        .bg = 0,
        .tilemapLeft = 20,//21
        .tilemapTop = 4, //5
        .width = 9,
        .height = 4,
        .paletteNum = 6,
        .baseBlock = 413,
    },
    [PSS_LABEL_WINDOW_END] = DUMMY_WIN_TEMPLATE
};

static const struct WindowTemplate sPageInfoTemplate[] =
{
    [PSS_DATA_WINDOW_INFO_ID] = {
        .bg = 0,
        .tilemapLeft = 1,
        .tilemapTop = 15,
        .width = 8,
        .height = 2,
        .paletteNum = 6,
        .baseBlock = 471,
    },
    [PSS_DATA_WINDOW_INFO_ABILITY] = {
        .bg = 0,
        .tilemapLeft = 1,
        .tilemapTop = 15,
        .width = 1,
        .height = 2,
        .paletteNum = 6,
        .baseBlock = 485,
    },
    [PSS_DATA_WINDOW_INFO_MEMO] = {
        .bg = 0,
        .tilemapLeft = 1,
        .tilemapTop = 14,
        .width = 30,//20
        .height = 6,
        .paletteNum = 6,
        .baseBlock = 557,
    },
};

static const struct WindowTemplate sPageSkillsTemplate[] =
{
    [PSS_DATA_WINDOW_SKILLS_HELD_ITEM] = {
        .bg = 0,
        .tilemapLeft = 1,
        .tilemapTop = 14,
        .width = 30,
        .height = 6,
        .paletteNum = 6,
        .baseBlock = 449,
    },
    [PSS_DATA_WINDOW_SKILLS_RIBBON_COUNT] = {
        .bg = 0,
        .tilemapLeft = 20,
        .tilemapTop = 4,
        .width = 10,
        .height = 2,
        .paletteNum = 6,
        .baseBlock = 469,
    },
    [PSS_DATA_WINDOW_SKILLS_STATS_LEFT] = {
        .bg = 0,
        .tilemapLeft = 16,
        .tilemapTop = 7,
        .width = 6,
        .height = 6,
        .paletteNum = 6,
        .baseBlock = 489,
    },
    [PSS_DATA_WINDOW_SKILLS_STATS_RIGHT] = {
        .bg = 0,
        .tilemapLeft = 27,
        .tilemapTop = 7,
        .width = 3,
        .height = 6,
        .paletteNum = 6,
        .baseBlock = 525,
    },
    [PSS_DATA_WINDOW_EXP] = {
        .bg = 0,
        .tilemapLeft = 24,
        .tilemapTop = 14,
        .width = 6,
        .height = 4,
        .paletteNum = 6,
        .baseBlock = 543,
    },
};
static const struct WindowTemplate sPageMovesTemplate[] = // This is used for both battle and contest moves
{
    [PSS_DATA_WINDOW_MOVE_NAMES] = {
        .bg = 0,
        .tilemapLeft = 15,
        .tilemapTop = 4,
        .width = 10,
        .height = 10,
        .paletteNum = 6,
        .baseBlock = 449,
    },
    [PSS_DATA_WINDOW_MOVE_PP] = {
        .bg = 0,
        .tilemapLeft = 25,
        .tilemapTop = 4,
        .width = 5,
        .height = 10,
        .paletteNum = 6,
        .baseBlock = 549,
    },
    [PSS_DATA_WINDOW_MOVE_DESCRIPTION] = {
        .bg = 0,
        .tilemapLeft = 10,
        .tilemapTop = 15,
        .width = 20,
        .height = 4,
        .paletteNum = 6,
        .baseBlock = 599,
    },
};

enum{
    SUMMARY_FONT_COLOR_BLACK,
    SUMMARY_FONT_COLOR_WHITE,
    SUMMARY_FONT_COLOR_RED,
    SUMMARY_FONT_COLOR_BLUE,
    SUMMARY_FONT_COLOR_GREEN,
    SUMMARY_FONT_COLOR_RED_2,
    SUMMARY_FONT_COLOR_BLUE_2,
    SUMMARY_FONT_COLOR_BLACK_2,
    SUMMARY_FONT_COLOR_UNUSED,
    SUMMARY_FONT_COLOR_UNUSED_2,
    SUMMARY_FONT_COLOR_UNUSED_3,
    SUMMARY_FONT_COLOR_UNUSED_4,
    SUMMARY_FONT_COLOR_UNUSED_5,
};

static const u8 sTextColors[][3] =
{
	[SUMMARY_FONT_COLOR_BLACK]    = {0, 10, 8},
    [SUMMARY_FONT_COLOR_WHITE]    = {0,  1, 5},
    [SUMMARY_FONT_COLOR_BLUE]     = {0, 11, 12},
    [SUMMARY_FONT_COLOR_RED]      = {0, 13, 14},
    [SUMMARY_FONT_COLOR_GREEN]    = {0, 15, 2},
    [SUMMARY_FONT_COLOR_BLUE_2]   = {0,  1, 11},
    [SUMMARY_FONT_COLOR_RED_2]    = {0,  1, 13},
    [SUMMARY_FONT_COLOR_BLACK_2]  = {0, 7, 4},
    [SUMMARY_FONT_COLOR_UNUSED]   = {0, 13, 14},
    [SUMMARY_FONT_COLOR_UNUSED_2] = {0, 13, 14},
    [SUMMARY_FONT_COLOR_UNUSED_3] = {0, 13, 14},
    [SUMMARY_FONT_COLOR_UNUSED_4] = {0, 13, 14},
    [SUMMARY_FONT_COLOR_UNUSED_5] = {0, 13, 14},
};

static const u8 sSummaryAButtonBitmap[] = INCBIN_U8("graphics/ui_menu/summary_screen/summary_a_button.4bpp");
static const u8 sSummaryBButtonBitmap[] = INCBIN_U8("graphics/ui_menu/summary_screen/summary_b_button.4bpp");
static const u8 sSummaryShinyIcon[]     = INCBIN_U8("graphics/ui_menu/summary_screen/summary_shiny_icon.4bpp");
static const u8 sSummaryEVIcon[]        = INCBIN_U8("graphics/ui_menu/summary_screen/summary_EVs_icon.4bpp");
static const u8 sSummaryExioliteIcon[]  = INCBIN_U8("graphics/ui_menu/summary_screen/summary_exiolite_icon.4bpp");
static const u8 sSummaryHeartIcon[]     = INCBIN_U8("graphics/ui_menu/summary_screen/summary_happiness_icon.4bpp");

static void (*const sTextPrinterFunctions[])(void) =
{
    [PSS_PAGE_INFO] = PrintInfoPageText,
    [PSS_PAGE_SKILLS] = PrintSkillsPageText,
    [PSS_PAGE_BATTLE_MOVES] = PrintBattleMoves,
    [PSS_PAGE_CONTEST_MOVES] = PrintContestMoves
};

static void (*const sTextPrinterTasks[])(u8 taskId) =
{
    [PSS_PAGE_INFO] = Task_PrintInfoPage,
    [PSS_PAGE_SKILLS] = Task_PrintSkillsPage,
    [PSS_PAGE_BATTLE_MOVES] = Task_PrintBattleMoves,
    [PSS_PAGE_CONTEST_MOVES] = Task_PrintContestMoves
};

static const u8 sMemoNatureTextColor[] = _("{COLOR 14}{SHADOW 13}");	//red
static const u8 sMemohidden_natureTextColor[] = _("({COLOR 12}{SHADOW 11}"); //blue
static const u8 sText_EndParentheses[] = _("{COLOR 07}{SHADOW 04})");
static const u8 sMemoMiscTextColor[] = _("{COLOR 07}{SHADOW 04}");
static const u8 sStatsLeftColumnLayout[] = _("{DYNAMIC 0x00}/{DYNAMIC 0x01}\n{DYNAMIC 0x02}\n{DYNAMIC 0x03}");
static const u8 sStatsLeftColumnLayoutIVEV[] = _("{DYNAMIC 0}\n{DYNAMIC 1}\n{DYNAMIC 2}");
static const u8 sStatsRightColumnLayout[] = _("{DYNAMIC 0x00}\n{DYNAMIC 0x01}\n{DYNAMIC 0x02}");
static const u8 sMovesPPLayout[] = _("{PP}{DYNAMIC 0x00}/{DYNAMIC 0x01}");

#define TAG_MOVE_SELECTOR 30000
#define TAG_MON_STATUS 30001
#define TAG_MOVE_TYPES 30002
#define TAG_MON_MARKINGS 30003
#define TAG_SPLIT_ICONS 30004

static const u16 sSplitIcons_Pal[] = INCBIN_U16("graphics/interface/split_icons.gbapal");
static const u32 sSplitIcons_Gfx[] = INCBIN_U32("graphics/interface/split_icons.4bpp.lz");

static const struct OamData sOamData_SplitIcons =
{
    .size = SPRITE_SIZE(16x16),
    .shape = SPRITE_SHAPE(16x16),
    .priority = 0,
};

static const struct CompressedSpriteSheet sSpriteSheet_SplitIcons =
{
    .data = sSplitIcons_Gfx,
    .size = 16*16*3/2,
    .tag = TAG_SPLIT_ICONS,
};

static const struct SpritePalette sSpritePal_SplitIcons =
{
    .data = sSplitIcons_Pal,
    .tag = TAG_SPLIT_ICONS
};

static const union AnimCmd sSpriteAnim_SplitIcon0[] =
{
    ANIMCMD_FRAME(0, 0),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_SplitIcon1[] =
{
    ANIMCMD_FRAME(4, 0),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_SplitIcon2[] =
{
    ANIMCMD_FRAME(8, 0),
    ANIMCMD_END
};

static const union AnimCmd *const sSpriteAnimTable_SplitIcons[] =
{
    sSpriteAnim_SplitIcon0,
    sSpriteAnim_SplitIcon1,
    sSpriteAnim_SplitIcon2,
};

static const struct SpriteTemplate sSpriteTemplate_SplitIcons =
{
    .tileTag = TAG_SPLIT_ICONS,
    .paletteTag = TAG_SPLIT_ICONS,
    .oam = &sOamData_SplitIcons,
    .anims = sSpriteAnimTable_SplitIcons,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy
};

static const struct OamData sOamData_MoveTypes =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = 0,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(32x16),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(32x16),
    .tileNum = 0,
    .priority = 1,
    .paletteNum = 0,
    .affineParam = 0,
};
static const union AnimCmd sSpriteAnim_TypeNormal[] = {
    ANIMCMD_FRAME(TYPE_NORMAL * 8, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd sSpriteAnim_TypeFighting[] = {
    ANIMCMD_FRAME(TYPE_FIGHTING * 8, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd sSpriteAnim_TypeFlying[] = {
    ANIMCMD_FRAME(TYPE_FLYING * 8, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd sSpriteAnim_TypePoison[] = {
    ANIMCMD_FRAME(TYPE_POISON * 8, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd sSpriteAnim_TypeGround[] = {
    ANIMCMD_FRAME(TYPE_GROUND * 8, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd sSpriteAnim_TypeRock[] = {
    ANIMCMD_FRAME(TYPE_ROCK * 8, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd sSpriteAnim_TypeBug[] = {
    ANIMCMD_FRAME(TYPE_BUG * 8, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd sSpriteAnim_TypeGhost[] = {
    ANIMCMD_FRAME(TYPE_GHOST * 8, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd sSpriteAnim_TypeSteel[] = {
    ANIMCMD_FRAME(TYPE_STEEL * 8, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd sSpriteAnim_TypeMystery[] = {
    ANIMCMD_FRAME(TYPE_MYSTERY * 8, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd sSpriteAnim_TypeFire[] = {
    ANIMCMD_FRAME(TYPE_FIRE * 8, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd sSpriteAnim_TypeWater[] = {
    ANIMCMD_FRAME(TYPE_WATER * 8, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd sSpriteAnim_TypeGrass[] = {
    ANIMCMD_FRAME(TYPE_GRASS * 8, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd sSpriteAnim_TypeElectric[] = {
    ANIMCMD_FRAME(TYPE_ELECTRIC * 8, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd sSpriteAnim_TypePsychic[] = {
    ANIMCMD_FRAME(TYPE_PSYCHIC * 8, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd sSpriteAnim_TypeIce[] = {
    ANIMCMD_FRAME(TYPE_ICE * 8, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd sSpriteAnim_TypeDragon[] = {
    ANIMCMD_FRAME(TYPE_DRAGON * 8, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd sSpriteAnim_TypeDark[] = {
    ANIMCMD_FRAME(TYPE_DARK * 8, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd sSpriteAnim_TypeFairy[] = {
    ANIMCMD_FRAME(TYPE_FAIRY * 8, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd sSpriteAnim_CategoryCool[] = {
    ANIMCMD_FRAME((CONTEST_CATEGORY_COOL + NUMBER_OF_MON_TYPES) * 8, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd sSpriteAnim_CategoryBeauty[] = {
    ANIMCMD_FRAME((CONTEST_CATEGORY_BEAUTY + NUMBER_OF_MON_TYPES) * 8, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd sSpriteAnim_CategoryCute[] = {
    ANIMCMD_FRAME((CONTEST_CATEGORY_CUTE + NUMBER_OF_MON_TYPES) * 8, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd sSpriteAnim_CategorySmart[] = {
    ANIMCMD_FRAME((CONTEST_CATEGORY_SMART + NUMBER_OF_MON_TYPES) * 8, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd sSpriteAnim_CategoryTough[] = {
    ANIMCMD_FRAME((CONTEST_CATEGORY_TOUGH + NUMBER_OF_MON_TYPES) * 8, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd *const sSpriteAnimTable_MoveTypes[NUMBER_OF_MON_TYPES + CONTEST_CATEGORIES_COUNT] = {
    sSpriteAnim_TypeNormal,
    sSpriteAnim_TypeFighting,
    sSpriteAnim_TypeFlying,
    sSpriteAnim_TypePoison,
    sSpriteAnim_TypeGround,
    sSpriteAnim_TypeRock,
    sSpriteAnim_TypeBug,
    sSpriteAnim_TypeGhost,
    sSpriteAnim_TypeSteel,
    sSpriteAnim_TypeMystery,
    sSpriteAnim_TypeFire,
    sSpriteAnim_TypeWater,
    sSpriteAnim_TypeGrass,
    sSpriteAnim_TypeElectric,
    sSpriteAnim_TypePsychic,
    sSpriteAnim_TypeIce,
    sSpriteAnim_TypeDragon,
    sSpriteAnim_TypeDark,
    sSpriteAnim_TypeFairy,
    sSpriteAnim_CategoryCool,
    sSpriteAnim_CategoryBeauty,
    sSpriteAnim_CategoryCute,
    sSpriteAnim_CategorySmart,
    sSpriteAnim_CategoryTough,
};

const struct CompressedSpriteSheet gSpriteSheet_MoveTypes =
{
    .data = gMoveTypes_Gfx,
    .size = (NUMBER_OF_MON_TYPES + CONTEST_CATEGORIES_COUNT) * 0x100,
    .tag = TAG_MOVE_TYPES
};
const struct SpriteTemplate gSpriteTemplate_MoveTypes =
{
    .tileTag = TAG_MOVE_TYPES,
    .paletteTag = TAG_MOVE_TYPES,
    .oam = &sOamData_MoveTypes,
    .anims = sSpriteAnimTable_MoveTypes,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy
};
static const u8 sMoveTypeToOamPaletteNum[NUMBER_OF_MON_TYPES + CONTEST_CATEGORIES_COUNT] =
{
    [TYPE_NORMAL] = 13,
    [TYPE_FIGHTING] = 13,
    [TYPE_FLYING] = 14,
    [TYPE_POISON] = 14,
    [TYPE_GROUND] = 13,
    [TYPE_ROCK] = 13,
    [TYPE_BUG] = 15,
    [TYPE_GHOST] = 14,
    [TYPE_STEEL] = 13,
    [TYPE_MYSTERY] = 15,
    [TYPE_FIRE] = 13,
    [TYPE_WATER] = 14,
    [TYPE_GRASS] = 15,
    [TYPE_ELECTRIC] = 13,
    [TYPE_PSYCHIC] = 14,
    [TYPE_ICE] = 14,
    [TYPE_DRAGON] = 15,
    [TYPE_DARK] = 13,
    [TYPE_FAIRY] = 14,
    [NUMBER_OF_MON_TYPES + CONTEST_CATEGORY_COOL] = 13,
    [NUMBER_OF_MON_TYPES + CONTEST_CATEGORY_BEAUTY] = 14,
    [NUMBER_OF_MON_TYPES + CONTEST_CATEGORY_CUTE] = 14,
    [NUMBER_OF_MON_TYPES + CONTEST_CATEGORY_SMART] = 15,
    [NUMBER_OF_MON_TYPES + CONTEST_CATEGORY_TOUGH] = 13,
};
static const struct OamData sOamData_MoveSelector =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = 0,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(16x16),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(16x16),
    .tileNum = 0,
    .priority = 1,
    .paletteNum = 0,
    .affineParam = 0,
};
static const union AnimCmd sSpriteAnim_MoveSelector0[] = {
    ANIMCMD_FRAME(0, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd sSpriteAnim_MoveSelector1[] = {
    ANIMCMD_FRAME(4, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd sSpriteAnim_MoveSelector2[] = {
    ANIMCMD_FRAME(8, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd sSpriteAnim_MoveSelector3[] = {
    ANIMCMD_FRAME(12, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd sSpriteAnim_MoveSelectorLeft[] = {
    ANIMCMD_FRAME(16, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd sSpriteAnim_MoveSelectorRight[] = {
    ANIMCMD_FRAME(16, 0, TRUE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd sSpriteAnim_MoveSelectorMiddle[] = {
    ANIMCMD_FRAME(20, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd sSpriteAnim_MoveSelector7[] = {
    ANIMCMD_FRAME(24, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd sSpriteAnim_MoveSelector8[] = {
    ANIMCMD_FRAME(24, 0, TRUE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd sSpriteAnim_MoveSelector9[] = {
    ANIMCMD_FRAME(28, 0, FALSE, FALSE),
    ANIMCMD_END
};
// All except left, middle and right are unused
static const union AnimCmd *const sSpriteAnimTable_MoveSelector[] = {
    sSpriteAnim_MoveSelector0,
    sSpriteAnim_MoveSelector1,
    sSpriteAnim_MoveSelector2,
    sSpriteAnim_MoveSelector3,
    sSpriteAnim_MoveSelectorLeft,
    sSpriteAnim_MoveSelectorRight,
    sSpriteAnim_MoveSelectorMiddle,
    sSpriteAnim_MoveSelector7,
    sSpriteAnim_MoveSelector8,
    sSpriteAnim_MoveSelector9,
};
static const struct CompressedSpriteSheet sMoveSelectorSpriteSheet =
{
    .data = gSummaryMoveSelect_Gfx,
    .size = 0x400,
    .tag = TAG_MOVE_SELECTOR
};
static const struct CompressedSpritePalette sMoveSelectorSpritePal =
{
    .data = gSummaryMoveSelect_Pal,
    .tag = TAG_MOVE_SELECTOR
};
static const struct SpriteTemplate sMoveSelectorSpriteTemplate =
{
    .tileTag = TAG_MOVE_SELECTOR,
    .paletteTag = TAG_MOVE_SELECTOR,
    .oam = &sOamData_MoveSelector,
    .anims = sSpriteAnimTable_MoveSelector,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy
};
static const struct OamData sOamData_StatusCondition =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = 0,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(32x8),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(32x8),
    .tileNum = 0,
    .priority = 3,
    .paletteNum = 0,
    .affineParam = 0,
};
static const union AnimCmd sSpriteAnim_StatusPoison[] = {
    ANIMCMD_FRAME(0, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd sSpriteAnim_StatusParalyzed[] = {
    ANIMCMD_FRAME(4, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd sSpriteAnim_StatusSleep[] = {
    ANIMCMD_FRAME(8, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd sSpriteAnim_StatusFrozen[] = {
    ANIMCMD_FRAME(12, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd sSpriteAnim_StatusBurn[] = {
    ANIMCMD_FRAME(16, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd sSpriteAnim_StatusPokerus[] = {
    ANIMCMD_FRAME(20, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd sSpriteAnim_StatusFaint[] = {
    ANIMCMD_FRAME(24, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd *const sSpriteAnimTable_StatusCondition[] = {
    sSpriteAnim_StatusPoison,
    sSpriteAnim_StatusParalyzed,
    sSpriteAnim_StatusSleep,
    sSpriteAnim_StatusFrozen,
    sSpriteAnim_StatusBurn,
    sSpriteAnim_StatusPokerus,
    sSpriteAnim_StatusFaint,
};
static const struct CompressedSpriteSheet sStatusIconsSpriteSheet =
{
    .data = gStatusGfx_Icons,
    .size = 0x380,
    .tag = TAG_MON_STATUS
};
static const struct CompressedSpritePalette sStatusIconsSpritePalette =
{
    .data = gStatusPal_Icons,
    .tag = TAG_MON_STATUS
};
static const struct SpriteTemplate sSpriteTemplate_StatusCondition =
{
    .tileTag = TAG_MON_STATUS,
    .paletteTag = TAG_MON_STATUS,
    .oam = &sOamData_StatusCondition,
    .anims = sSpriteAnimTable_StatusCondition,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy
};
static const u16 sSummaryMarkingsPalette[] = INCBIN_U16("graphics/interface/summary_markings.gbapal");

// code
static u8 ShowSplitIcon(u32 split)
{
    if (sMonSummaryScreen->splitIconSpriteId == 0xFF)
        sMonSummaryScreen->splitIconSpriteId = CreateSprite(&sSpriteTemplate_SplitIcons, 48, 129, 0);

    gSprites[sMonSummaryScreen->splitIconSpriteId].invisible = FALSE;
    StartSpriteAnim(&gSprites[sMonSummaryScreen->splitIconSpriteId], split);
    return sMonSummaryScreen->splitIconSpriteId;
}

static void DestroySplitIcon(void)
{
    if (sMonSummaryScreen->splitIconSpriteId != 0xFF)
        DestroySprite(&gSprites[sMonSummaryScreen->splitIconSpriteId]);
    sMonSummaryScreen->splitIconSpriteId = 0xFF;
}

void ShowPokemonSummaryScreen(u8 mode, void *mons, u8 monIndex, u8 maxMonIndex, void (*callback)(void))
{
    sMonSummaryScreen = AllocZeroed(sizeof(*sMonSummaryScreen));
    sMonSummaryScreen->mode = mode;
    sMonSummaryScreen->monList.mons = mons;
    sMonSummaryScreen->curMonIndex = monIndex;
    sMonSummaryScreen->maxMonIndex = maxMonIndex;
    sMonSummaryScreen->callback = callback;

    if (mode == PSS_MODE_BOX)
        sMonSummaryScreen->isBoxMon = TRUE;
    else
        sMonSummaryScreen->isBoxMon = FALSE;

    switch (mode)
    {
    case PSS_MODE_NORMAL:
    case PSS_MODE_BOX:
        sMonSummaryScreen->minPageIndex = 0;
        sMonSummaryScreen->maxPageIndex = PSS_PAGE_COUNT - 2; // It was -1
        break;
    case PSS_MODE_LOCK_MOVES:
        sMonSummaryScreen->minPageIndex = 0;
        sMonSummaryScreen->maxPageIndex = PSS_PAGE_COUNT - 2; // It was -1
        sMonSummaryScreen->lockMovesFlag = TRUE;
        break;
    case PSS_MODE_SELECT_MOVE:
        sMonSummaryScreen->minPageIndex = PSS_PAGE_BATTLE_MOVES;
        sMonSummaryScreen->maxPageIndex = PSS_PAGE_COUNT - 2; // It was -1
        sMonSummaryScreen->lockMonFlag = TRUE;
        break;
    }

    sMonSummaryScreen->currPageIndex = sMonSummaryScreen->minPageIndex;
    sMonSummaryScreen->splitIconSpriteId = 0xFF;
    SummaryScreen_SetUnknownTaskId(0xFF);

    if (gMonSpritesGfxPtr == NULL)
        sub_806F2AC(0, 0);

    SetMainCallback2(CB2_InitSummaryScreen);
}

void ShowSelectMovePokemonSummaryScreen(struct Pokemon *mons, u8 monIndex, u8 maxMonIndex, void (*callback)(void), u16 newMove)
{
    ShowPokemonSummaryScreen(PSS_MODE_SELECT_MOVE, mons, monIndex, maxMonIndex, callback);
    sMonSummaryScreen->newMove = newMove;
}

void ShowPokemonSummaryScreenSet40EF(u8 mode, struct BoxPokemon *mons, u8 monIndex, u8 maxMonIndex, void (*callback)(void))
{
    ShowPokemonSummaryScreen(mode, mons, monIndex, maxMonIndex, callback);
    sMonSummaryScreen->unk40EF = TRUE;
}

static void MainCB2(void)
{
    RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    DoScheduledBgTilemapCopiesToVram();
    UpdatePaletteFade();
}

static void VBlank(void)
{
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
}

static void CB2_InitSummaryScreen(void)
{
    while (MenuHelpers_CallLinkSomething() != TRUE && LoadGraphics() != TRUE && MenuHelpers_LinkSomething() != TRUE);
}

static bool8 LoadGraphics(void)
{
	sMonSummaryScreen->ModifyStatMode = FALSE;
    /*if (gSaveBlock2Ptr->optionsMgbaMode == FALSE)
	    sMonSummaryScreen->disableTransparency = TRUE;
    else*/
	sMonSummaryScreen->disableTransparency = FALSE;
	sMonSummaryScreen->gCurrentStattoModify = 0;

    switch (gMain.state)
    {
    case 0:
        SetVBlankHBlankCallbacksToNull();
        ResetVramOamAndBgCntRegs();
        ClearScheduledBgCopiesToVram();
        gMain.state++;
        break;
    case 1:
        ScanlineEffect_Stop();
        gMain.state++;
        break;
    case 2:
        ResetPaletteFade();
        gPaletteFade.bufferTransferDisabled = 1;
        gMain.state++;
        break;
    case 3:
        ResetSpriteData();
        gMain.state++;
        break;
    case 4:
        FreeAllSpritePalettes();
        gMain.state++;
        break;
    case 5:
        InitBGs();
        sMonSummaryScreen->switchCounter = 0;
        gMain.state++;
        break;
    case 6:
        if (DecompressGraphics() != FALSE)
            gMain.state++;
        break;
    case 7:
        ResetWindows();
        gMain.state++;
        break;
    case 8:
        DrawPagination();
        gMain.state++;
        break;
    case 9:
        CopyMonToSummaryStruct(&sMonSummaryScreen->currentMon);
        sMonSummaryScreen->switchCounter = 0;
        gMain.state++;
        break;
    case 10:
        if (ExtractMonDataToSummaryStruct(&sMonSummaryScreen->currentMon) != 0)
            gMain.state++;
        break;
    case 11:
        PrintMonInfo();
        gMain.state++;
        break;
    case 12:
        PrintPageNamesAndStats();
        gMain.state++;
        break;
    case 13:
        PrintPageSpecificText(sMonSummaryScreen->currPageIndex);
        gMain.state++;
        break;
    case 14:
        SetDefaultTilemaps();
        gMain.state++;
        break;
    case 15:
        PutPageWindowTilemaps(sMonSummaryScreen->currPageIndex);
        gMain.state++;
        break;
    case 16:
        ResetSpriteIds();
        CreateMoveTypeIcons();
        sMonSummaryScreen->switchCounter = 0;
        gMain.state++;
        break;
    case 17:
        sMonSummaryScreen->spriteIds[SPRITE_ARR_ID_MON] = LoadMonGfxAndSprite(&sMonSummaryScreen->currentMon, &sMonSummaryScreen->switchCounter);
        if (sMonSummaryScreen->spriteIds[SPRITE_ARR_ID_MON] != 0xFF)
        {
            sMonSummaryScreen->switchCounter = 0;
            gMain.state++;
        }
        break;
    case 18:
        CreateMonMarkingsSprite(&sMonSummaryScreen->currentMon);
        gMain.state++;
        break;
    case 19:
        CreateCaughtBallSprite(&sMonSummaryScreen->currentMon);
        gMain.state++;
        break;
    case 20:
        CreateSetStatusSprite();
        gMain.state++;
        break;
    case 21:
        SetTypeIcons();
        gMain.state++;
        break;
    case 22:
        if (sMonSummaryScreen->mode != PSS_MODE_SELECT_MOVE)
            CreateTask(Task_HandleInput, 0);
        else
            CreateTask(Task_SetHandleReplaceMoveInput, 0);
        gMain.state++;
        break;
    case 23:
        BlendPalettes(0xFFFFFFFF, 16, 0);
        gMain.state++;
        break;
    case 24:
        BeginNormalPaletteFade(0xFFFFFFFF, 0, 16, 0, RGB_BLACK);
        gPaletteFade.bufferTransferDisabled = 0;
        gMain.state++;
        break;
    default:
        SetVBlankCallback(VBlank);
        SetMainCallback2(MainCB2);
        return TRUE;
    }
    return FALSE;
}

//Background Stuff
static void InitBGs(void)
{
    if(!sMonSummaryScreen->disableTransparency){
        ResetBgsAndClearDma3BusyFlags(0);
        ResetAllBgsCoordinates();
        //Background 3
        setNormalBackground();

        //Background 2 - Scroll
        setScrollingBackground();

        //Background 1 - Transparent
        setTransparentBackground();
    }
    else{
        ResetBgsAndClearDma3BusyFlags(0);
        ResetAllBgsCoordinates();
        //Background 3
        setNormalBackground();

        //Background 2 - Scroll
        setScrollingBackground();
    }
}

#define SCROLLING_BACKGROUND_NUM 3
static void setScrollingBackground(){
    SetBgTilemapBuffer(SCROLLING_BACKGROUND_NUM, sMonSummaryScreen->bgTilemapBuffers[PSS_PAGE_BATTLE_MOVES][0]);
    ScheduleBgCopyTilemapToVram(SCROLLING_BACKGROUND_NUM);
    SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_OBJ_ON | DISPCNT_OBJ_1D_MAP);
    SetGpuReg(REG_OFFSET_BLDCNT, 0);
    ShowBg(SCROLLING_BACKGROUND_NUM);
}

#define NORMAL_BACKGROUND_NUM 2
static void setNormalBackground(){
    SetBgAttribute(NORMAL_BACKGROUND_NUM, BG_ATTR_PRIORITY, NORMAL_BACKGROUND_NUM);
    InitBgsFromTemplates(0, sBgTemplates, ARRAY_COUNT(sBgTemplates));
    SetBgTilemapBuffer(NORMAL_BACKGROUND_NUM, sMonSummaryScreen->bgTilemapBuffers[PSS_PAGE_INFO][0]);
    ScheduleBgCopyTilemapToVram(NORMAL_BACKGROUND_NUM);
    SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_OBJ_ON | DISPCNT_OBJ_1D_MAP);
    SetGpuReg(REG_OFFSET_BLDCNT, 0);
    ShowBg(0);
    ShowBg(NORMAL_BACKGROUND_NUM);
}

#define CURRENT_BACKGROUND_NUM 1
static void setTransparentBackground(){
    SetBgAttribute(CURRENT_BACKGROUND_NUM, BG_ATTR_PRIORITY, 1);
    ScheduleBgCopyTilemapToVram(CURRENT_BACKGROUND_NUM);

    SetBgTilemapBuffer(CURRENT_BACKGROUND_NUM, sMonSummaryScreen->bgTilemapBuffers[PSS_PAGE_SKILLS][0]);

    //Transparency
    if(!sMonSummaryScreen->disableTransparency){
        SetGpuReg(REG_OFFSET_BLDCNT, BLDCNT_EFFECT_BLEND | BLDCNT_TGT2_ALL | BLDCNT_TGT1_BG1); //Blend Background over the rest
        SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(6, 6));
        SetGpuRegBits(REG_OFFSET_WININ, WININ_WIN0_CLR);
    }

    ScheduleBgCopyTilemapToVram(CURRENT_BACKGROUND_NUM);

    ChangeBgX(CURRENT_BACKGROUND_NUM, 0x10000, 1);
    ShowBg(CURRENT_BACKGROUND_NUM);
}

static void removeTransparentBackground(){
    SetBgAttribute(CURRENT_BACKGROUND_NUM, BG_ATTR_PRIORITY, CURRENT_BACKGROUND_NUM);
    InitBgsFromTemplates(0, sBgTemplates, ARRAY_COUNT(sBgTemplates));
    SetBgTilemapBuffer(CURRENT_BACKGROUND_NUM, sMonSummaryScreen->bgTilemapBuffers[PSS_PAGE_INFO][0]);
    ScheduleBgCopyTilemapToVram(CURRENT_BACKGROUND_NUM);
    SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_OBJ_ON | DISPCNT_OBJ_1D_MAP);
    SetGpuReg(REG_OFFSET_BLDCNT, 0);
    ShowBg(0);
    ShowBg(CURRENT_BACKGROUND_NUM);
}

const u32 gScrollingBGTilemap[] = INCBIN_U32("graphics/ui_menu/summary_screen/scrolling_bg.bin.lz");

static bool8 DecompressGraphics(void)
{
    switch (sMonSummaryScreen->switchCounter)
    {
    case 0:
        ResetTempTileDataBuffers();
        DecompressAndCopyTileDataToVram(1, &gStatusScreenBitmap, 0, 0, 0);
        sMonSummaryScreen->switchCounter++;
        break;
    case 1:
        if (FreeTempTileDataBuffersIfPossible() != 1)
        {
            LZDecompressWram(gPageInfoTilemap, sMonSummaryScreen->bgTilemapBuffers[PSS_PAGE_INFO][0]);
            sMonSummaryScreen->switchCounter++;
        }
        break;
    case 2:
        LZDecompressWram(gSummaryPage_InfoEgg_Tilemap, sMonSummaryScreen->bgTilemapBuffers[PSS_PAGE_INFO][1]);
        sMonSummaryScreen->switchCounter++;
        break;
    case 3:
        LZDecompressWram(gPageSkillsTilemap, sMonSummaryScreen->bgTilemapBuffers[PSS_PAGE_SKILLS][1]);
        sMonSummaryScreen->switchCounter++;
        break;
    case 4:
        LZDecompressWram(gScrollingBGTilemap, sMonSummaryScreen->bgTilemapBuffers[PSS_PAGE_BATTLE_MOVES][0]);
        sMonSummaryScreen->switchCounter++;
        break;
    case 5:
        LZDecompressWram(gPageContestMovesTilemap, sMonSummaryScreen->bgTilemapBuffers[PSS_PAGE_CONTEST_MOVES][1]);
        sMonSummaryScreen->switchCounter++;
        break;
    case 6:
        LoadCompressedPalette(gStatusScreenPalette, 0, 0x100);
        LoadPalette(&gUnknown_08D85620, 0x81, 0x1E);
        sMonSummaryScreen->switchCounter++;
        break;
    case 7:
        LoadCompressedSpriteSheet(&gSpriteSheet_MoveTypes);
        sMonSummaryScreen->switchCounter++;
        break;
    case 8:
        LoadCompressedSpriteSheet(&sMoveSelectorSpriteSheet);
        sMonSummaryScreen->switchCounter++;
        break;
    case 9:
        LoadCompressedSpriteSheet(&sStatusIconsSpriteSheet);
        sMonSummaryScreen->switchCounter++;
        break;
    case 10:
        LoadCompressedSpritePalette(&sStatusIconsSpritePalette);
        sMonSummaryScreen->switchCounter++;
        break;
    case 11:
        LoadCompressedSpritePalette(&sMoveSelectorSpritePal);
        sMonSummaryScreen->switchCounter++;
        break;
    case 12:
        LoadCompressedPalette(gMoveTypes_Pal, 0x1D0, 0x60);
        LoadCompressedSpriteSheet(&sSpriteSheet_SplitIcons);
        LoadSpritePalette(&sSpritePal_SplitIcons);
        sMonSummaryScreen->switchCounter = 0;
        return TRUE;
    }
    return FALSE;
}

static void CopyMonToSummaryStruct(struct Pokemon *mon)
{
    if (!sMonSummaryScreen->isBoxMon)
    {
        struct Pokemon *partyMon = sMonSummaryScreen->monList.mons;
        *mon = partyMon[sMonSummaryScreen->curMonIndex];
    }
    else
    {
        struct BoxPokemon *boxMon = sMonSummaryScreen->monList.boxMons;
        BoxMonToMon(&boxMon[sMonSummaryScreen->curMonIndex], mon);
    }
}

static bool8 ExtractMonDataToSummaryStruct(struct Pokemon *mon)
{
    u32 i;
    struct PokeSummary *sum = &sMonSummaryScreen->summary;
    // Spread the data extraction over multiple frames.
    switch (sMonSummaryScreen->switchCounter)
    {
    case 0:
        sum->species = GetMonData(mon, MON_DATA_SPECIES);
        sum->formId = GetMonData(mon, MON_DATA_FORM_ID);
        sum->species2 = GetMonData(mon, MON_DATA_SPECIES2);
        sum->exp = GetMonData(mon, MON_DATA_EXP);
        sum->level = GetMonData(mon, MON_DATA_LEVEL);
        sum->abilityNum = GetMonData(mon, MON_DATA_ABILITY_NUM);
        sum->item = GetMonData(mon, MON_DATA_HELD_ITEM);
        sum->pid = GetMonData(mon, MON_DATA_PERSONALITY);
        sum->sanity = GetMonData(mon, MON_DATA_SANITY_IS_BAD_EGG);

        if (sum->sanity)
            sum->isEgg = GetMonData(mon, MON_DATA_IS_EGG);
        else
            sum->isEgg = GetMonData(mon, MON_DATA_IS_EGG);

        break;
    case 1:
        for (i = 0; i < MAX_MON_MOVES; i++)
        {
            sum->moves[i] = GetMonData(mon, MON_DATA_MOVE1+i);
            sum->pp[i] = GetMonData(mon, MON_DATA_PP1+i);
        }
        sum->ppBonuses = GetMonData(mon, MON_DATA_PP_BONUSES);
        break;
    case 2:
        if (sMonSummaryScreen->monList.mons == gPlayerParty || sMonSummaryScreen->mode == PSS_MODE_BOX || sMonSummaryScreen->unk40EF == TRUE)
        {
            //sum->nature = GetNature(mon);
			sum->nature = GetNature(mon, FALSE);
            sum->hidden_nature = GetMonData(mon, MON_DATA_HIDDEN_NATURE);
            sum->currentHP = GetMonData(mon, MON_DATA_HP);
            sum->maxHP = GetMonData(mon, MON_DATA_MAX_HP);
            sum->atk = GetMonData(mon, MON_DATA_ATK);
            sum->def = GetMonData(mon, MON_DATA_DEF);
            sum->spatk = GetMonData(mon, MON_DATA_SPATK);
            sum->spdef = GetMonData(mon, MON_DATA_SPDEF);
            sum->speed = GetMonData(mon, MON_DATA_SPEED);
        }
        else
        {
            //sum->nature = GetNature(mon);
			sum->nature = GetNature(mon, FALSE);
            sum->hidden_nature = GetMonData(mon, MON_DATA_HIDDEN_NATURE);
            sum->currentHP = GetMonData(mon, MON_DATA_HP);
            sum->maxHP = GetMonData(mon, MON_DATA_MAX_HP);
            sum->atk = GetMonData(mon, MON_DATA_ATK2);
            sum->def = GetMonData(mon, MON_DATA_DEF2);
            sum->spatk = GetMonData(mon, MON_DATA_SPATK2);
            sum->spdef = GetMonData(mon, MON_DATA_SPDEF2);
            sum->speed = GetMonData(mon, MON_DATA_SPEED2);
        }
        break;
    case 3:
        GetMonData(mon, MON_DATA_OT_NAME, sum->OTName);
        ConvertInternationalString(sum->OTName, GetMonData(mon, MON_DATA_LANGUAGE));
        sum->ailment = GetMonAilment(mon);
        sum->OTGender = GetMonData(mon, MON_DATA_OT_GENDER);
        sum->OTID = GetMonData(mon, MON_DATA_OT_ID);
        sum->metLocation = GetMonData(mon, MON_DATA_MET_LOCATION);
        sum->metLevel = GetMonData(mon, MON_DATA_MET_LEVEL);
        sum->metGame = GetMonData(mon, MON_DATA_MET_GAME);
        sum->friendship = GetMonData(mon, MON_DATA_FRIENDSHIP);
        break;
    default:
        sum->ribbonCount = GetMonData(mon, MON_DATA_RIBBON_COUNT);
        return TRUE;
    }
    sMonSummaryScreen->switchCounter++;
    return FALSE;
}

static void SetDefaultTilemaps(void)
{
    /*if (sMonSummaryScreen->currPageIndex == PSS_PAGE_BATTLE_MOVES || sMonSummaryScreen->currPageIndex == PSS_PAGE_CONTEST_MOVES)
    {
        SetBgTilemapBuffer(1, sMonSummaryScreen->bgTilemapBuffers[PSS_PAGE_CONTEST_MOVES][0]);
        //SetBgTilemapBuffer(2, sMonSummaryScreen->bgTilemapBuffers[PSS_PAGE_BATTLE_MOVES][0]);
        ChangeBgX(2, 0x10000, 1);
        ClearWindowTilemap(PSS_LABEL_WINDOW_PORTRAIT_SPECIES);
        ClearWindowTilemap(PSS_LABEL_WINDOW_POKEMON_SKILLS_STATUS);
    }*/

    if (sMonSummaryScreen->summary.ailment == AILMENT_NONE)
        HandleStatusTilemap(0, 0xFF);

    LimitEggSummaryPageDisplay();
}

static void FreeSummaryScreen(void)
{
    FreeAllWindowBuffers();
    Free(sMonSummaryScreen);
}

static void BeginCloseSummaryScreen(u8 taskId)
{
    BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 16, RGB_BLACK);
    gTasks[taskId].func = CloseSummaryScreen;
}

static void CloseSummaryScreen(u8 taskId)
{
    if (MenuHelpers_CallLinkSomething() != TRUE && !gPaletteFade.active)
    {
        if(!sMonSummaryScreen->disableTransparency){
            removeTransparentBackground();
        }
        SetMainCallback2(sMonSummaryScreen->callback);
        gLastViewedMonIndex = sMonSummaryScreen->curMonIndex;
        SummaryScreen_DestroyUnknownTask();
        ResetSpriteData();
        FreeAllSpritePalettes();
        StopCryAndClearCrySongs();
        m4aMPlayVolumeControl(&gMPlayInfo_BGM, 0xFFFF, 0x100);
        if (gMonSpritesGfxPtr == NULL)
            sub_806F47C(0);
        FreeSummaryScreen();
        DestroyTask(taskId);
    }
}

static void Task_HandleInput(u8 taskId)
{
	u8 i;
	u8  CurrentEv = 0;
	u16 TotalEvs = 0;
	u16 RemainingEvs = 0;
	
	switch(sMonSummaryScreen->gCurrentStattoModify){
		case 0:
			if (!sMonSummaryScreen->isBoxMon)
				CurrentEv = GetMonData(&gPlayerParty[sMonSummaryScreen->curMonIndex], MON_DATA_HP_EV);
		break;
		case 1:
			if (!sMonSummaryScreen->isBoxMon)
				CurrentEv = GetMonData(&gPlayerParty[sMonSummaryScreen->curMonIndex], MON_DATA_ATK_EV);
		break;
		case 2:
			if (!sMonSummaryScreen->isBoxMon)
				CurrentEv = GetMonData(&gPlayerParty[sMonSummaryScreen->curMonIndex], MON_DATA_DEF_EV);
		break;
		case 3:
			if (!sMonSummaryScreen->isBoxMon)
				CurrentEv = GetMonData(&gPlayerParty[sMonSummaryScreen->curMonIndex], MON_DATA_SPATK_EV);
		break;
		case 4:
			if (!sMonSummaryScreen->isBoxMon)
				CurrentEv = GetMonData(&gPlayerParty[sMonSummaryScreen->curMonIndex], MON_DATA_SPDEF_EV);
		break;
		case 5:
			if (!sMonSummaryScreen->isBoxMon)
				CurrentEv = GetMonData(&gPlayerParty[sMonSummaryScreen->curMonIndex], MON_DATA_SPEED_EV);
		break;
	}
	
	for(i = 0; i < 6; i++)
		TotalEvs = TotalEvs + GetMonData(&gPlayerParty[sMonSummaryScreen->curMonIndex], MON_DATA_HP_EV + i);
	
	RemainingEvs = 510 - TotalEvs;
	
    if (MenuHelpers_CallLinkSomething() != TRUE && !gPaletteFade.active)
    {
        if (JOY_NEW(DPAD_UP))
        {
			if(!sMonSummaryScreen->ModifyStatMode)
				ChangeSummaryPokemon(taskId, -1);
			else{
				if(sMonSummaryScreen->gCurrentStattoModify != 0)
					sMonSummaryScreen->gCurrentStattoModify--;
				else
					sMonSummaryScreen->gCurrentStattoModify = 5;
				
				CalculateMonStats(&gPlayerParty[sMonSummaryScreen->curMonIndex]);
				CalculateMonStats(&sMonSummaryScreen->currentMon);
                FillWindowPixelBuffer(PSS_WINDOW_MIDDLE_RIGHT, PIXEL_FILL(TEXT_COLOR_TRANSPARENT));
				PrintStatPage_Midde();
			}
			
        }
        else if (JOY_NEW(DPAD_DOWN))
        {
			if(!sMonSummaryScreen->ModifyStatMode)
				ChangeSummaryPokemon(taskId, 1);
			else{
				if(sMonSummaryScreen->gCurrentStattoModify != 5)
					sMonSummaryScreen->gCurrentStattoModify++;
				else
					sMonSummaryScreen->gCurrentStattoModify = 0;
				
				CalculateMonStats(&gPlayerParty[sMonSummaryScreen->curMonIndex]);
				CalculateMonStats(&sMonSummaryScreen->currentMon);
                FillWindowPixelBuffer(PSS_WINDOW_MIDDLE_RIGHT, PIXEL_FILL(TEXT_COLOR_TRANSPARENT));
				PrintStatPage_Midde();
			}
        }
        else if ((JOY_NEW(DPAD_LEFT)) || GetLRKeysPressed() == MENU_L_PRESSED)
        {
            if(!sMonSummaryScreen->ModifyStatMode)
				ChangePage(taskId, -1);
			else {
				if(CurrentEv != 0){
					CurrentEv--;
					switch(sMonSummaryScreen->gCurrentStattoModify){
					case 0:
						if (!sMonSummaryScreen->isBoxMon){
							SetMonData(&gPlayerParty[sMonSummaryScreen->curMonIndex], MON_DATA_HP_EV, &CurrentEv);
							SetMonData(&sMonSummaryScreen->currentMon, MON_DATA_HP_EV, &CurrentEv);
						}
					break;
					case 1:
						if (!sMonSummaryScreen->isBoxMon){
							SetMonData(&gPlayerParty[sMonSummaryScreen->curMonIndex], MON_DATA_ATK_EV, &CurrentEv);
							SetMonData(&sMonSummaryScreen->currentMon, MON_DATA_ATK_EV, &CurrentEv);
						}
					break;
					case 2:
						if (!sMonSummaryScreen->isBoxMon){
							SetMonData(&gPlayerParty[sMonSummaryScreen->curMonIndex], MON_DATA_DEF_EV, &CurrentEv);
							SetMonData(&sMonSummaryScreen->currentMon, MON_DATA_DEF_EV, &CurrentEv);
						}
					break;
					case 3:
						if (!sMonSummaryScreen->isBoxMon){
							SetMonData(&gPlayerParty[sMonSummaryScreen->curMonIndex], MON_DATA_SPATK_EV, &CurrentEv);
							SetMonData(&sMonSummaryScreen->currentMon, MON_DATA_SPATK_EV, &CurrentEv);
						}
					break;
					case 4:
						if (!sMonSummaryScreen->isBoxMon){
							SetMonData(&gPlayerParty[sMonSummaryScreen->curMonIndex], MON_DATA_SPDEF_EV, &CurrentEv);
							SetMonData(&sMonSummaryScreen->currentMon, MON_DATA_SPDEF_EV, &CurrentEv);
						}
					break;
					case 5:
						if (!sMonSummaryScreen->isBoxMon){
							SetMonData(&gPlayerParty[sMonSummaryScreen->curMonIndex], MON_DATA_SPEED_EV, &CurrentEv);
							SetMonData(&sMonSummaryScreen->currentMon, MON_DATA_SPEED_EV, &CurrentEv);
						}
					break;
					}
				}
				CalculateMonStats(&gPlayerParty[sMonSummaryScreen->curMonIndex]);
				CalculateMonStats(&sMonSummaryScreen->currentMon);
                FillWindowPixelBuffer(PSS_WINDOW_MIDDLE_RIGHT, PIXEL_FILL(TEXT_COLOR_TRANSPARENT));
				PrintStatPage_Midde();
			}
        }
        else if ((JOY_NEW(DPAD_RIGHT)) || GetLRKeysPressed() == MENU_R_PRESSED)
        {
            if(!sMonSummaryScreen->ModifyStatMode)
				ChangePage(taskId, 1);
			else {
				if(CurrentEv != 252 && TotalEvs != 510){
					CurrentEv++;
					switch(sMonSummaryScreen->gCurrentStattoModify){
					case 0:
						if (!sMonSummaryScreen->isBoxMon){
							SetMonData(&gPlayerParty[sMonSummaryScreen->curMonIndex], MON_DATA_HP_EV, &CurrentEv);
							SetMonData(&sMonSummaryScreen->currentMon, MON_DATA_HP_EV, &CurrentEv);
						}
					break;
					case 1:
						if (!sMonSummaryScreen->isBoxMon){
							SetMonData(&gPlayerParty[sMonSummaryScreen->curMonIndex], MON_DATA_ATK_EV, &CurrentEv);
							SetMonData(&sMonSummaryScreen->currentMon, MON_DATA_ATK_EV, &CurrentEv);
						}
					break;
					case 2:
						if (!sMonSummaryScreen->isBoxMon){
							SetMonData(&gPlayerParty[sMonSummaryScreen->curMonIndex], MON_DATA_DEF_EV, &CurrentEv);
							SetMonData(&sMonSummaryScreen->currentMon, MON_DATA_DEF_EV, &CurrentEv);
						}
					break;
					case 3:
						if (!sMonSummaryScreen->isBoxMon){
							SetMonData(&gPlayerParty[sMonSummaryScreen->curMonIndex], MON_DATA_SPATK_EV, &CurrentEv);
							SetMonData(&sMonSummaryScreen->currentMon, MON_DATA_SPATK_EV, &CurrentEv);
						}
					break;
					case 4:
						if (!sMonSummaryScreen->isBoxMon){
							SetMonData(&gPlayerParty[sMonSummaryScreen->curMonIndex], MON_DATA_SPDEF_EV, &CurrentEv);
							SetMonData(&sMonSummaryScreen->currentMon, MON_DATA_SPDEF_EV, &CurrentEv);
						}
					break;
					case 5:
						if (!sMonSummaryScreen->isBoxMon){
							SetMonData(&gPlayerParty[sMonSummaryScreen->curMonIndex], MON_DATA_SPEED_EV, &CurrentEv);
							SetMonData(&sMonSummaryScreen->currentMon, MON_DATA_SPEED_EV, &CurrentEv);
						}
					break;
					}
				}
				CalculateMonStats(&gPlayerParty[sMonSummaryScreen->curMonIndex]);
				CalculateMonStats(&sMonSummaryScreen->currentMon);
                FillWindowPixelBuffer(PSS_WINDOW_MIDDLE_RIGHT, PIXEL_FILL(TEXT_COLOR_TRANSPARENT));
				PrintStatPage_Midde();
			}
        }
        else if (JOY_NEW(A_BUTTON))
        {
            if (sMonSummaryScreen->currPageIndex != PSS_PAGE_SKILLS)
            {
                if (sMonSummaryScreen->currPageIndex == PSS_PAGE_INFO)
                {
                    StopPokemonAnimations();
                    PlaySE(SE_SELECT);
                    BeginCloseSummaryScreen(taskId);
                }
                else // Contest or Battle Moves
                {
                    PlaySE(SE_SELECT);
                    SwitchToMoveSelection(taskId);
                }
            }
			else if (sMonSummaryScreen->currPageIndex == PSS_PAGE_SKILLS &&
					 !sMonSummaryScreen->isBoxMon &&
					 !sMonSummaryScreen->lockMovesFlag &&
					 !FlagGet(FLAG_NO_EVS_MODE) &&
					 (GetMonData(&gPlayerParty[sMonSummaryScreen->curMonIndex], MON_DATA_LEVEL) >= 90 || FlagGet(FLAG_ENABLE_EV_CHANGES)))
			{
				sMonSummaryScreen->ModifyStatMode = !sMonSummaryScreen->ModifyStatMode;
				CalculateMonStats(&gPlayerParty[sMonSummaryScreen->curMonIndex]);
				CalculateMonStats(&sMonSummaryScreen->currentMon);
				
                FillWindowPixelBuffer(PSS_WINDOW_MIDDLE_RIGHT, PIXEL_FILL(TEXT_COLOR_TRANSPARENT));
				PrintStatPage_Midde();
			}
        }
        else if (JOY_NEW(B_BUTTON))
        {
            if(!sMonSummaryScreen->ModifyStatMode){
                StopPokemonAnimations();
                PlaySE(SE_SELECT);
                BeginCloseSummaryScreen(taskId);
            }
            else{
                sMonSummaryScreen->ModifyStatMode = !sMonSummaryScreen->ModifyStatMode;
				CalculateMonStats(&gPlayerParty[sMonSummaryScreen->curMonIndex]);
				CalculateMonStats(&sMonSummaryScreen->currentMon);
				
                FillWindowPixelBuffer(PSS_WINDOW_MIDDLE_RIGHT, PIXEL_FILL(TEXT_COLOR_TRANSPARENT));
				PrintStatPage_Midde();
            }
        }// show IVs/EVs/stats on button presses
		else if (gMain.newKeys & R_BUTTON)
		{
			if(!sMonSummaryScreen->ModifyStatMode)
				ChangePage(taskId, 1);
			else {
				if(CurrentEv != 252 && TotalEvs != 510){
					if(RemainingEvs + CurrentEv <= 252)
						CurrentEv = RemainingEvs + CurrentEv;
					else
						CurrentEv = 252;
						
					switch(sMonSummaryScreen->gCurrentStattoModify){
					case 0:
						if (!sMonSummaryScreen->isBoxMon){
							SetMonData(&gPlayerParty[sMonSummaryScreen->curMonIndex], MON_DATA_HP_EV, &CurrentEv);
							SetMonData(&sMonSummaryScreen->currentMon, MON_DATA_HP_EV, &CurrentEv);
						}
					break;
					case 1:
						if (!sMonSummaryScreen->isBoxMon){
							SetMonData(&gPlayerParty[sMonSummaryScreen->curMonIndex], MON_DATA_ATK_EV, &CurrentEv);
							SetMonData(&sMonSummaryScreen->currentMon, MON_DATA_ATK_EV, &CurrentEv);
						}
					break;
					case 2:
						if (!sMonSummaryScreen->isBoxMon){
							SetMonData(&gPlayerParty[sMonSummaryScreen->curMonIndex], MON_DATA_DEF_EV, &CurrentEv);
							SetMonData(&sMonSummaryScreen->currentMon, MON_DATA_DEF_EV, &CurrentEv);
						}
					break;
					case 3:
						if (!sMonSummaryScreen->isBoxMon){
							SetMonData(&gPlayerParty[sMonSummaryScreen->curMonIndex], MON_DATA_SPATK_EV, &CurrentEv);
							SetMonData(&sMonSummaryScreen->currentMon, MON_DATA_SPATK_EV, &CurrentEv);
						}
					break;
					case 4:
						if (!sMonSummaryScreen->isBoxMon){
							SetMonData(&gPlayerParty[sMonSummaryScreen->curMonIndex], MON_DATA_SPDEF_EV, &CurrentEv);
							SetMonData(&sMonSummaryScreen->currentMon, MON_DATA_SPDEF_EV, &CurrentEv);
						}
					break;
					case 5:
						if (!sMonSummaryScreen->isBoxMon){
							SetMonData(&gPlayerParty[sMonSummaryScreen->curMonIndex], MON_DATA_SPEED_EV, &CurrentEv);
							SetMonData(&sMonSummaryScreen->currentMon, MON_DATA_SPEED_EV, &CurrentEv);
						}
					break;
					}
				}
				CalculateMonStats(&gPlayerParty[sMonSummaryScreen->curMonIndex]);
				CalculateMonStats(&sMonSummaryScreen->currentMon);
                FillWindowPixelBuffer(PSS_WINDOW_MIDDLE_RIGHT, PIXEL_FILL(TEXT_COLOR_TRANSPARENT));
				PrintStatPage_Midde();
			}
		}
		else if (gMain.newKeys & L_BUTTON)
		{
			if(!sMonSummaryScreen->ModifyStatMode)
				ChangePage(taskId, -1);
			else {
				if(CurrentEv != 0){
					CurrentEv = 0;
						
					switch(sMonSummaryScreen->gCurrentStattoModify){
					case 0:
						if (!sMonSummaryScreen->isBoxMon){
							SetMonData(&gPlayerParty[sMonSummaryScreen->curMonIndex], MON_DATA_HP_EV, &CurrentEv);
							SetMonData(&sMonSummaryScreen->currentMon, MON_DATA_HP_EV, &CurrentEv);
						}
					break;
					case 1:
						if (!sMonSummaryScreen->isBoxMon){
							SetMonData(&gPlayerParty[sMonSummaryScreen->curMonIndex], MON_DATA_ATK_EV, &CurrentEv);
							SetMonData(&sMonSummaryScreen->currentMon, MON_DATA_ATK_EV, &CurrentEv);
						}
					break;
					case 2:
						if (!sMonSummaryScreen->isBoxMon){
							SetMonData(&gPlayerParty[sMonSummaryScreen->curMonIndex], MON_DATA_DEF_EV, &CurrentEv);
							SetMonData(&sMonSummaryScreen->currentMon, MON_DATA_DEF_EV, &CurrentEv);
						}
					break;
					case 3:
						if (!sMonSummaryScreen->isBoxMon){
							SetMonData(&gPlayerParty[sMonSummaryScreen->curMonIndex], MON_DATA_SPATK_EV, &CurrentEv);
							SetMonData(&sMonSummaryScreen->currentMon, MON_DATA_SPATK_EV, &CurrentEv);
						}
					break;
					case 4:
						if (!sMonSummaryScreen->isBoxMon){
							SetMonData(&gPlayerParty[sMonSummaryScreen->curMonIndex], MON_DATA_SPDEF_EV, &CurrentEv);
							SetMonData(&sMonSummaryScreen->currentMon, MON_DATA_SPDEF_EV, &CurrentEv);
						}
					break;
					case 5:
						if (!sMonSummaryScreen->isBoxMon){
							SetMonData(&gPlayerParty[sMonSummaryScreen->curMonIndex], MON_DATA_SPEED_EV, &CurrentEv);
							SetMonData(&sMonSummaryScreen->currentMon, MON_DATA_SPEED_EV, &CurrentEv);
						}
					break;
					}
				}
				CalculateMonStats(&gPlayerParty[sMonSummaryScreen->curMonIndex]);
				CalculateMonStats(&sMonSummaryScreen->currentMon);
                FillWindowPixelBuffer(PSS_WINDOW_MIDDLE_RIGHT, PIXEL_FILL(TEXT_COLOR_TRANSPARENT));
				PrintStatPage_Midde();
			}
		}
		else if (gMain.newKeys & START_BUTTON)
		{
			if (sMonSummaryScreen->currPageIndex == PSS_PAGE_SKILLS)
			{
				PrintStatPage_Midde();
			}
		}
        else if (gMain.newKeys & SELECT_BUTTON)
		{
			if (sMonSummaryScreen->currPageIndex == PSS_PAGE_SKILLS &&
				!sMonSummaryScreen->isBoxMon &&
				!sMonSummaryScreen->lockMovesFlag &&
				!FlagGet(FLAG_NO_EVS_MODE))
			{
                CurrentEv = 0;
				
                for (i = 0; i < NUM_STATS; i++)
                {
					SetMonData(&gPlayerParty[sMonSummaryScreen->curMonIndex], MON_DATA_HP_EV + i, &CurrentEv);
					SetMonData(&sMonSummaryScreen->currentMon, MON_DATA_HP_EV + i, &CurrentEv);
                }
                
				CalculateMonStats(&gPlayerParty[sMonSummaryScreen->curMonIndex]);
				CalculateMonStats(&sMonSummaryScreen->currentMon);
                FillWindowPixelBuffer(PSS_WINDOW_MIDDLE_RIGHT, PIXEL_FILL(TEXT_COLOR_TRANSPARENT));
				PrintStatPage_Midde();
			}
		}
    }

    //Background Scrolling
    ScrollBackground();
}

static void ScrollBackground(void)
{
    ChangeBgX(SCROLLING_BACKGROUND_NUM, 128, 1);
    ChangeBgY(SCROLLING_BACKGROUND_NUM, 128, 2);
}

static void ChangeSummaryPokemon(u8 taskId, s8 delta)
{
    s8 monId;

    if (!sMonSummaryScreen->lockMonFlag)
    {
        if (sMonSummaryScreen->isBoxMon == TRUE)
        {
            if (sMonSummaryScreen->currPageIndex != PSS_PAGE_INFO)
            {
                if (delta == 1)
                    delta = 0;
                else
                    delta = 2;
            }
            else
            {
                if (delta == 1)
                    delta = 1;
                else
                    delta = 3;
            }
            monId = sub_80D214C(sMonSummaryScreen->monList.boxMons, sMonSummaryScreen->curMonIndex, sMonSummaryScreen->maxMonIndex, delta);
        }
        else if (IsMultiBattle() == TRUE)
        {
            monId = AdvanceMultiBattleMonIndex(delta);
        }
        else
        {
            monId = AdvanceMonIndex(delta);
        }

        if (monId != -1)
        {
            PlaySE(SE_SELECT);
            if (sMonSummaryScreen->summary.ailment != AILMENT_NONE)
            {
                SetSpriteInvisibility(SPRITE_ARR_ID_STATUS, TRUE);
                ClearWindowTilemap(PSS_LABEL_WINDOW_POKEMON_SKILLS_STATUS);
                ScheduleBgCopyTilemapToVram(0);
                HandleStatusTilemap(0, 2);
            }
            sMonSummaryScreen->curMonIndex = monId;
            gTasks[taskId].data[0] = 0;
            gTasks[taskId].func = Task_ChangeSummaryMon;
        }
    }
}

static void Task_ChangeSummaryMon(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    switch (data[0])
    {
    case 0:
        StopCryAndClearCrySongs();
        break;
    case 1:
        SummaryScreen_DestroyUnknownTask();
        DestroySpriteAndFreeResources(&gSprites[sMonSummaryScreen->spriteIds[SPRITE_ARR_ID_MON]]);
        break;
    case 2:
        DestroySpriteAndFreeResources(&gSprites[sMonSummaryScreen->spriteIds[SPRITE_ARR_ID_BALL]]);
        break;
    case 3:
        CopyMonToSummaryStruct(&sMonSummaryScreen->currentMon);
        sMonSummaryScreen->switchCounter = 0;
        break;
    case 4:
        if (ExtractMonDataToSummaryStruct(&sMonSummaryScreen->currentMon) == FALSE)
            return;
        break;
    case 5:
        RemoveAndCreateMonMarkingsSprite(&sMonSummaryScreen->currentMon);
        break;
    case 6:
        CreateCaughtBallSprite(&sMonSummaryScreen->currentMon);
		CreateSetStatusSprite();
        PrintMiddleRightPart(sMonSummaryScreen->currPageIndex);
        break;
    case 7:
        //if (sMonSummaryScreen->summary.ailment != AILMENT_NONE)
        //    HandleStatusTilemap(10, -2);
        //DrawPokerusCuredSymbol(&sMonSummaryScreen->currentMon);
        data[1] = 0;
        break;
    case 8:
        sMonSummaryScreen->spriteIds[SPRITE_ARR_ID_MON] = LoadMonGfxAndSprite(&sMonSummaryScreen->currentMon, &data[1]);
        if (sMonSummaryScreen->spriteIds[SPRITE_ARR_ID_MON] == 0xFF)
            return;
        gSprites[sMonSummaryScreen->spriteIds[SPRITE_ARR_ID_MON]].data[2] = 1;
        TryDrawExperienceProgressBar();
        data[1] = 0;
        break;
    case 9:
        SetTypeIcons();
        break;
    case 10:
        PrintMonInfo();
        break;
    case 11:
        PrintPageSpecificText(sMonSummaryScreen->currPageIndex);
        LimitEggSummaryPageDisplay();
        break;
    case 12:
        gSprites[sMonSummaryScreen->spriteIds[SPRITE_ARR_ID_MON]].data[2] = 0;
        break;
    default:
        if (MenuHelpers_CallLinkSomething() == 0 && FuncIsActiveTask(Task_ShowStatusWindow) == 0)
        {
            data[0] = 0;
            gTasks[taskId].func = Task_HandleInput;
        }
        return;
    }
    data[0]++;
}

static s8 AdvanceMonIndex(s8 delta)
{
    struct Pokemon *mon = sMonSummaryScreen->monList.mons;
    u8 index = sMonSummaryScreen->curMonIndex;
    u8 numMons = sMonSummaryScreen->maxMonIndex + 1;
    delta += numMons;

    index = (index + delta) % numMons;

    // skip over any Eggs unless on the Info Page
    if (sMonSummaryScreen->currPageIndex != PSS_PAGE_INFO)
        while (GetMonData(&mon[index], MON_DATA_IS_EGG))
            index = (index + delta) % numMons;

    // to avoid "scrolling" to the same Pokemon
    if (index == sMonSummaryScreen->curMonIndex)
        return -1;
    else
        return index;
}

static s8 AdvanceMultiBattleMonIndex(s8 delta)
{
    struct Pokemon *mons = sMonSummaryScreen->monList.mons;
    s8 index, arrId = 0;
    u8 i;

    for (i = 0; i < PARTY_SIZE; i++)
    {
        if (sMultiBattleOrder[i] == sMonSummaryScreen->curMonIndex)
        {
            arrId = i;
            break;
        }
    }

    while (TRUE)
    {
        const s8 *order = sMultiBattleOrder;

        arrId += delta;
        if (arrId < 0 || arrId >= PARTY_SIZE)
            return -1;
        index = order[arrId];
        if (IsValidToViewInMulti(&mons[index]) == TRUE)
            return index;
    }
}

static bool8 IsValidToViewInMulti(struct Pokemon* mon)
{
    if (GetMonData(mon, MON_DATA_SPECIES) == SPECIES_NONE)
        return FALSE;
    else if (sMonSummaryScreen->curMonIndex != 0 || !GetMonData(mon, MON_DATA_IS_EGG))
        return TRUE;
    else
        return FALSE;
}

//Custom Functions -----------------------------------------------------------------------------------------------------------

static void PrintTextOnWindow(u8 windowId, const u8 *string, u8 x, u8 y, u8 lineSpacing, u8 colorId)
{
    AddTextPrinterParameterized4(windowId, 1, x, y, 0, lineSpacing, sTextColors[colorId], 0, string);
}

static void PrintNarrowTextOnWindow(u8 windowId, const u8 *string, u8 x, u8 y, u8 lineSpacing, u8 colorId)
{
    AddTextPrinterParameterized4(windowId, 7, x, y, 0, lineSpacing, sTextColors[colorId], 0, string);
}

static void PrintSmallTextOnWindow(u8 windowId, const u8 *string, u8 x, u8 y, u8 lineSpacing, u8 colorId)
{
    AddTextPrinterParameterized4(windowId, 8, x, y, 0, lineSpacing, sTextColors[colorId], 0, string);
}

enum{
    HELP_BAR_A_CANCEL,
    HELP_BAR_A_INFO,
    HELP_BAR_A_SWITCH,
    HELP_BAR_A_RESET_EVS,
};

static const u8 sText_Help_Bar_Cancel[]    = _("{A_BUTTON} Cancel");
static const u8 sText_Help_Bar_Switch[]    = _("{A_BUTTON} Switch");
static const u8 sText_Help_Bar_Info[]      = _("{A_BUTTON} Info");
static const u8 sText_Help_Bar_Reset_Evs[] = _("{SELECT_BUTTON} Reset Evs");

static void ChangePage(u8 taskId, s8 delta)
{
    struct PokeSummary *summary = &sMonSummaryScreen->summary;
    s16 *data = gTasks[taskId].data;

    if (summary->isEgg)
        return;
    else if (delta == -1 && sMonSummaryScreen->currPageIndex == sMonSummaryScreen->minPageIndex)
        return;
    else if (delta == 1 && sMonSummaryScreen->currPageIndex == sMonSummaryScreen->maxPageIndex)
        return;

    PlaySE(SE_SELECT);
    PrintMiddleRightPart(sMonSummaryScreen->currPageIndex);
    ClearPageWindowTilemaps(sMonSummaryScreen->currPageIndex);
    sMonSummaryScreen->currPageIndex += delta;
    data[0] = 0;
    if (delta == 1)
        SetTaskFuncWithFollowupFunc(taskId, PssScrollRightEnd, gTasks[taskId].func);
    else
        SetTaskFuncWithFollowupFunc(taskId, PssScrollLeftEnd, gTasks[taskId].func);
    HidePageSpecificSprites();
}

u8 getWhiteFontColor(){
    if(!sMonSummaryScreen->disableTransparency)
        return SUMMARY_FONT_COLOR_WHITE;
    else
        return SUMMARY_FONT_COLOR_BLACK_2;
}

u8 getBlueFontColor(){
    if(!sMonSummaryScreen->disableTransparency)
        return SUMMARY_FONT_COLOR_BLUE_2;
    else
        return SUMMARY_FONT_COLOR_BLUE;
}

u8 getRedFontColor(){
    if(!sMonSummaryScreen->disableTransparency)
        return SUMMARY_FONT_COLOR_RED_2;
    else
        return SUMMARY_FONT_COLOR_RED;
}

static void PrintTitile(u8 page, u8 helpBar){
    u8 posX = 2;
    u8 posY = 2;
    FillWindowPixelBuffer(PSS_WINDOW_TOP, PIXEL_FILL(TEXT_COLOR_TRANSPARENT));

    switch(page){
        case PSS_PAGE_INFO:
            PrintTextOnWindow(PSS_WINDOW_TOP, gText_PkmnInfo, posX, posY, 0, SUMMARY_FONT_COLOR_WHITE);
        break;
        case PSS_PAGE_SKILLS:
            PrintTextOnWindow(PSS_WINDOW_TOP, gText_PkmnSkills, posX, posY, 0, SUMMARY_FONT_COLOR_WHITE);
        break;
        case PSS_PAGE_BATTLE_MOVES:
            PrintTextOnWindow(PSS_WINDOW_TOP, gText_BattleMoves, posX, posY, 0, SUMMARY_FONT_COLOR_WHITE);
        break;
        case PSS_PAGE_CONTEST_MOVES:
            PrintTextOnWindow(PSS_WINDOW_TOP, gText_ContestMoves, posX, posY, 0, SUMMARY_FONT_COLOR_WHITE);
        break;
    }

    switch(helpBar){
        case HELP_BAR_A_CANCEL:
            posX = 188;
            PrintTextOnWindow(PSS_WINDOW_TOP, sText_Help_Bar_Cancel, posX, posY, 0, SUMMARY_FONT_COLOR_WHITE);
        break;
        case HELP_BAR_A_INFO:
            posX = 188;
            PrintTextOnWindow(PSS_WINDOW_TOP, sText_Help_Bar_Info, posX, posY, 0, SUMMARY_FONT_COLOR_WHITE);
        break;
        case HELP_BAR_A_SWITCH:
            posX = 188;
            PrintTextOnWindow(PSS_WINDOW_TOP, sText_Help_Bar_Switch, posX, posY, 0, SUMMARY_FONT_COLOR_WHITE);
        break;
        case HELP_BAR_A_RESET_EVS:
            posX = 160;
            PrintTextOnWindow(PSS_WINDOW_TOP, sText_Help_Bar_Reset_Evs, posX, posY, 0, SUMMARY_FONT_COLOR_WHITE);
        break;
    }
    CopyWindowToVram(PSS_WINDOW_TOP, 3);
	PutWindowTilemap(PSS_WINDOW_TOP);
}

static void CleanScreens(void){
    FillWindowPixelBuffer(PSS_WINDOW_MIDDLE_RIGHT, PIXEL_FILL(TEXT_COLOR_TRANSPARENT));
    FillWindowPixelBuffer(PSS_WINDOW_MIDDLE_LEFT, PIXEL_FILL(TEXT_COLOR_TRANSPARENT));
    FillWindowPixelBuffer(PSS_WINDOW_BOTTOM, PIXEL_FILL(TEXT_COLOR_TRANSPARENT));
}

static void PrintMiddleRightPart(u8 page){
    u8 posX = 2;
    u8 posY = 2;
    
    CleanScreens();
    PrintMiddleLeftPart();

    switch(page){
        case PSS_PAGE_INFO:
            PrintInfoPage_Midde();
            PrintInfoPage_Bottom();
        break;
        case PSS_PAGE_SKILLS:
            PrintStatPage_Midde();
            PrintStatPage_Bottom();
        break;
        case PSS_PAGE_BATTLE_MOVES:
            PrintMoveNameAndPP(0);
            PrintMoveNameAndPP(1);
            PrintMoveNameAndPP(2);
            PrintMoveNameAndPP(3);
            if(sMonSummaryScreen->newMove != MOVE_NONE){
                PrintMoveNameAndPP(4);
                PrintContestMoveDescription(0);
            }
        break;
        case PSS_PAGE_CONTEST_MOVES:
            PrintTextOnWindow(PSS_WINDOW_MIDDLE_RIGHT, gText_ContestMoves, posX, posY, 0, getWhiteFontColor());
        break;
    }
    CopyWindowToVram(PSS_WINDOW_MIDDLE_RIGHT, 3);
	PutWindowTilemap(PSS_WINDOW_MIDDLE_RIGHT);

    CopyWindowToVram(PSS_WINDOW_MIDDLE_LEFT, 3);
	PutWindowTilemap(PSS_WINDOW_MIDDLE_LEFT);
    
    CopyWindowToVram(PSS_WINDOW_BOTTOM, 3);
	PutWindowTilemap(PSS_WINDOW_BOTTOM);
}

// Every Screen
static const u8 PkmnNickname[]  =  _("{STR_VAR_1}\n{LV}{STR_VAR_3}");
static const u8 gText_Empty[]  =  _("");

static void PrintMiddleLeftPart(void)
{
    //Prints everything present on all the pages
    u8 windowId = PSS_WINDOW_MIDDLE_LEFT;
	u8 i;
	u8 strArray[16];
    struct Pokemon *mon = &sMonSummaryScreen->currentMon;
    struct PokeSummary *summary = &sMonSummaryScreen->summary;
	bool8 exioliteStatus = GetMonData(mon, MON_DATA_EXIOLITE_ENABLED, NULL);
    u16 dexNum = SpeciesToPokedexNum(summary->species);
	int PosX = 1;
	int PosY = 0;
	
	//Clean
	FillWindowPixelBuffer(windowId, PIXEL_FILL(TEXT_COLOR_TRANSPARENT));
	
	//Pokemon Nickname
	GetMonNickname(mon, gStringVar1);
	
	//Pokemon Gender
	if (summary->species2 != SPECIES_NIDORAN_M && summary->species2 != SPECIES_NIDORAN_F)
    {
        switch (GetMonGender(mon))
        {
        case MON_MALE:
            PrintNarrowTextOnWindow(windowId, gText_MaleSymbol, ((PosX + 6) * 8) + 4, (PosY * 8), 0, SUMMARY_FONT_COLOR_BLUE);
            break;
        case MON_FEMALE:
            PrintNarrowTextOnWindow(windowId, gText_FemaleSymbol, ((PosX + 6) * 8) + 4, (PosY * 8), 0, SUMMARY_FONT_COLOR_RED);
            break;
        }
    }
	
	//Pokemon Level
    ConvertIntToDecimalStringN(gStringVar3, (u16)summary->level, STR_CONV_MODE_LEFT_ALIGN, 5);

    StringExpandPlaceholders(gStringVar4, PkmnNickname);
    PrintNarrowTextOnWindow(windowId, gStringVar4, (PosX * 8), (PosY * 8), 0, SUMMARY_FONT_COLOR_BLACK_2);
	
	//Shiny Icon
	PosY = PosY + 2;
	PosX = PosX + 3;
	if (IsMonShiny(mon))
		BlitBitmapToWindow(windowId, sSummaryShinyIcon, (PosX * 8), (PosY * 8) + 6, 8, 8);
	if(exioliteStatus == TRUE)
		BlitBitmapToWindow(windowId, sSummaryExioliteIcon, ((PosX + 1) * 8), (PosY * 8) + 6, 8, 8);
	
	PutWindowTilemap(windowId);
}

//First Screen
#define FIRST_SCREEN_ROW_X   3
#define FIRST_SCREEN_ROW_X_2 8 + FIRST_SCREEN_ROW_X

static const u8 sText_Pkmn_Species[] = _("Species");
static const u8 sText_Pkmn_OT[]      = _("OT");
static const u8 sText_Pkmn_Type[]    = _("Type");
static const u8 sText_Pkmn_IDNo[]    = _("ID No");
static const u8 sText_Pkmn_Item[]    = _("Item");
static const u8 sText_Pkmn_Experience[] = _("Experience");
static const u8 sText_Pkmn_Nature[] = _("Nature");

static const u8 sText_Pkmn_Species_Number[] = _("{STR_VAR_1} {NO}{STR_VAR_2}");
static const u8 sText_Pkmn_Original_Trainer[] = _("{STR_VAR_1}({STR_VAR_2})");
static const u8 sText_Pkmn_Current_Experience[] = _("{STR_VAR_1}/{STR_VAR_2}");

static void PrintInfoPage_Midde(void)
{
	//Prints Everything on the first page
	int windowId = PSS_WINDOW_MIDDLE_RIGHT;
	u8 strArray[16];
    struct Pokemon *mon = &sMonSummaryScreen->currentMon;
    struct PokeSummary *summary = &sMonSummaryScreen->summary;
    u16 formSpeciesId = GetFormSpeciesId(summary->species, summary->formId);
    u16 dexNum = SpeciesToPokedexNum(summary->species);
    u8 Friendship = GetMonData(mon, MON_DATA_FRIENDSHIP);
	int posX = 0;
	int PosY = 0;
	u8 gText_RentalPkmnOT[] = _("Rental");
	u8 exioliteStatus = GetMonData(mon, MON_DATA_EXIOLITE_ENABLED, NULL);
	u16 exioliteSpecies = GetExioliteSpecies(summary->species, summary->level);
	u16 exiolitedexNum = SpeciesToPokedexNum(exioliteSpecies);
	static const u8 PokedexNumber[]         =  _("{STR_VAR_3}$");
	static const u8 PokedexNumberExiolite[] =  _("{STR_VAR_3} - ({STR_VAR_2})$");
    bool8 HiddenNature = FALSE;
	
	//Exiolite number
	ConvertIntToDecimalStringN(gStringVar3, dexNum, STR_CONV_MODE_LEADING_ZEROS, 3);
	
	switch(summary->species){
		case SPECIES_EEVEE:
			if(exioliteStatus == 1 && summary->level >= 25){
				exiolitedexNum  = SpeciesToPokedexNum(summary->species);
				exioliteSpecies = SPECIES_JOLTEON;
			}
			else
				exioliteSpecies = summary->species;
		break;
	}

	//Pokemon Species and Number
    posX = FIRST_SCREEN_ROW_X_2;
    PrintNarrowTextOnWindow(windowId, sText_Pkmn_Species, ( FIRST_SCREEN_ROW_X * 8), (PosY*8), 0, getWhiteFontColor());

    StringCopy(gStringVar1, &gSpeciesNames[summary->species2][0]);
    ConvertIntToDecimalStringN(gStringVar2, dexNum, STR_CONV_MODE_LEADING_ZEROS, 3);
    StringExpandPlaceholders(gStringVar4, sText_Pkmn_Species_Number);
    PrintNarrowTextOnWindow(windowId, gStringVar4, (posX*8), (PosY*8), 0, getWhiteFontColor());

    //Original Trainer Data
	PosY = PosY + 2;
    PrintNarrowTextOnWindow(windowId, sText_Pkmn_OT, ( FIRST_SCREEN_ROW_X * 8), (PosY*8), 0, getWhiteFontColor());

    StringCopy(gStringVar1, sMonSummaryScreen->summary.OTName);
    ConvertIntToDecimalStringN(gStringVar2, (u16)sMonSummaryScreen->summary.OTID, STR_CONV_MODE_LEADING_ZEROS, 5);
    StringExpandPlaceholders(gStringVar4, sText_Pkmn_Original_Trainer);

    if (!InBattleFactory() && !InSlateportBattleTent())
    {
        //Original Trainer Name
        if (sMonSummaryScreen->summary.OTGender == 0)
            PrintNarrowTextOnWindow(windowId, gStringVar4, (posX*8), (PosY*8), 0, getBlueFontColor());
        else
            PrintNarrowTextOnWindow(windowId, gStringVar4, (posX*8), (PosY*8), 0, getRedFontColor());
    }else{
		//Rental
        PrintNarrowTextOnWindow(windowId, gStringVar4, (posX*8), (PosY*8), 0, getWhiteFontColor());
	}

    //Pokemon Type
    PosY = PosY + 2;
    PrintNarrowTextOnWindow(windowId, sText_Pkmn_Type, ( FIRST_SCREEN_ROW_X * 8), (PosY*8), 0, getWhiteFontColor());
	
	//Pokemon Item
	PosY = PosY + 2;
    PrintNarrowTextOnWindow(windowId, sText_Pkmn_Item, ( FIRST_SCREEN_ROW_X * 8), (PosY*8), 0, getWhiteFontColor());
	if (sMonSummaryScreen->summary.item == ITEM_NONE)
        StringCopy(gStringVar1, gText_None);
    else
        CopyItemName(sMonSummaryScreen->summary.item, gStringVar1);
	PrintNarrowTextOnWindow(windowId, gStringVar1, (posX*8), (PosY*8), 0, getWhiteFontColor());

    //Pokemon Experience
	PosY = PosY + 2;
    PrintNarrowTextOnWindow(windowId, sText_Pkmn_Experience, ( FIRST_SCREEN_ROW_X * 8), (PosY*8), 0, getWhiteFontColor());
    //Exp Bar Icon
    if (summary->level < MAX_LEVEL)
    {
        u32 currentExperience = summary->exp;
        u32 nextLevelExp = gExperienceTables[gBaseStats[formSpeciesId].growthRate][summary->level + 1];

        ConvertIntToDecimalStringN(gStringVar1, currentExperience, STR_CONV_MODE_LEFT_ALIGN, 7);
        ConvertIntToDecimalStringN(gStringVar2, nextLevelExp, STR_CONV_MODE_LEFT_ALIGN, 7);

        StringExpandPlaceholders(gStringVar4, sText_Pkmn_Current_Experience);
        
        PrintNarrowTextOnWindow(windowId, gStringVar4, (posX*8), (PosY*8), 0, getWhiteFontColor());
    }
    else
    {
        u32 currentExperience = summary->exp;
        ConvertIntToDecimalStringN(gStringVar1, currentExperience, STR_CONV_MODE_LEFT_ALIGN, 8);
        PrintNarrowTextOnWindow(windowId, gStringVar1, (posX*8), (PosY*8), 0, getWhiteFontColor());
    }

    //Pokemon Nature
	PosY = PosY + 2;
    PrintNarrowTextOnWindow(windowId, sText_Pkmn_Nature, ( FIRST_SCREEN_ROW_X * 8), (PosY*8), 0, getWhiteFontColor());
    
    if (summary->hidden_nature != HIDDEN_NATURE_NONE && summary->hidden_nature != NATURE_HARDY){
        StringCopy(gStringVar1, gNatureNamePointers[summary->hidden_nature]);
        HiddenNature = TRUE;
    }
    else
        StringCopy(gStringVar1, gNatureNamePointers[summary->nature]);
    
    if(HiddenNature)
        PrintNarrowTextOnWindow(windowId, gStringVar1, (posX*8), (PosY*8), 0, getBlueFontColor());
    else
        PrintNarrowTextOnWindow(windowId, gStringVar1, (posX*8), (PosY*8), 0, getWhiteFontColor());
}

const u8 gText_NatureMetAt[] = _("{STR_VAR_1} nature, met at {LV} {STR_VAR_2}.");

static void PrintInfoPage_Bottom(void)
{
	int windowId = PSS_WINDOW_BOTTOM;
	const u8 *text;
    struct Pokemon *mon = &sMonSummaryScreen->currentMon;
    struct PokeSummary *summary = &sMonSummaryScreen->summary;
	int PosX = 0;
	int PosY = 4;
	u8 i;
    const u8 gText_Ability[] = _("Pokémon Ability");
	u8 Friendship = GetMonData(mon, MON_DATA_FRIENDSHIP)/50;
    u16 formSpeciesId = GetFormSpeciesId(summary->species, summary->formId);
    u16 abilityNum, ability;

    //Title
    PrintSmallTextOnWindow(windowId, gText_Ability, PosX, PosY, 0, SUMMARY_FONT_COLOR_WHITE);

    //Pokemon Ability Name
	PosY = PosY + 12;
	abilityNum = sMonSummaryScreen->summary.abilityNum;
	ability = RandomizePokemonAbility(GetAbilityBySpecies(sMonSummaryScreen->summary.species, sMonSummaryScreen->summary.abilityNum, sMonSummaryScreen->summary.formId), sMonSummaryScreen->summary.pid);
    
    StringCopy(gStringVar1, gAbilityNames[ability]);
    //StringExpandPlaceholders(gStringVar4, gText_Ability);

	if(abilityNum != 2)
		PrintSmallTextOnWindow(windowId, gStringVar1, PosX, PosY, 0, SUMMARY_FONT_COLOR_WHITE);
	else
		PrintSmallTextOnWindow(windowId, gStringVar1, PosX, PosY, 0, SUMMARY_FONT_COLOR_RED_2);
	
	//Pokemon Ability Description
	PosY = PosY + 12;
	PrintSmallTextOnWindow(windowId, gAbilityDescriptionPointers[ability], PosX, PosY, 0, SUMMARY_FONT_COLOR_WHITE);

    /*/Nature
    if (summary->hidden_nature != HIDDEN_NATURE_NONE && summary->hidden_nature != NATURE_HARDY)
        StringCopy(gStringVar1, gNatureNamePointers[summary->nature]);
    else
        StringCopy(gStringVar1, gNatureNamePointers[summary->hidden_nature]);

    //Met Level
    ConvertIntToDecimalStringN(gStringVar2, summary->metLevel, STR_CONV_MODE_LEFT_ALIGN, 3);

    StringExpandPlaceholders(gStringVar4, gText_NatureMetAt);
	
	PrintNarrowTextOnWindow(windowId, gStringVar4, PosX, PosY, 0, SUMMARY_FONT_COLOR_WHITE);*/
}

//Second Screen
#define FIRST_ROW_X  24
#define SECOND_ROW_X 56 + FIRST_ROW_X
#define SPACE_BETWEEN_STATS 8 + 4

static void PrintStatPage_Midde(void)
{
    int windowId = PSS_WINDOW_MIDDLE_RIGHT;
    const u8 gText_UpSymbol[] = _("{UP_ARROW}");
    const u8 gText_DownSymbol[] = _("{DOWN_ARROW}");
    const u8 gText_Stat_Line_1[] = _("Stat");
    const u8 gText_Stat_Line_2[] = _("Stats");
    const u8 gText_Stat_Line_3[] = _("Ivs");
    const u8 gText_Stat_Line_4[] = _("Evs");
    u16 hp, hp2, atk, def, spA, spD, spe;
	u16 hpIV, atkIV, defIV, spAIV, spDIV, speIV;
	u16 hpEV, atkEV, defEV, spAEV, spDEV, speEV;
    u8 *currHPString = Alloc(20);
	u8 *txtPtr;
	u8 i, j;
	static const u8 CurrentHP[] =  _("{STR_VAR_1}/{STR_VAR_2}$");
	int statsXPos = 64;
	int statsYPos = 0;
	u8 statcolor[5];
	s8 natureMod[5];
    const s8 *natureModifier = gNatureStatTable[
      (sMonSummaryScreen->summary.hidden_nature == HIDDEN_NATURE_NONE || sMonSummaryScreen->summary.hidden_nature == NATURE_HARDY) ? sMonSummaryScreen->summary.nature : sMonSummaryScreen->summary.hidden_nature];
		
    if(sMonSummaryScreen->ModifyStatMode)
        FillWindowPixelBuffer(PSS_WINDOW_MIDDLE_RIGHT, PIXEL_FILL(TEXT_COLOR_TRANSPARENT));

    CalculateMonStats(&sMonSummaryScreen->currentMon);
	
    //Nature Mod //-----------------------------------------------------------------------
		natureMod[0] = natureModifier[STAT_ATK - 1];
		natureMod[1] = natureModifier[STAT_DEF - 1];
		natureMod[2] = natureModifier[STAT_SPATK - 1];
		natureMod[3] = natureModifier[STAT_SPDEF - 1];
		natureMod[4] = natureModifier[STAT_SPEED - 1];
		//Stats //-----------------------------------------------------------------------
        hp = sMonSummaryScreen->summary.currentHP;
        hp2 = sMonSummaryScreen->summary.maxHP;
        atk = sMonSummaryScreen->summary.atk;
        def = sMonSummaryScreen->summary.def;
        spA = sMonSummaryScreen->summary.spatk;
        spD = sMonSummaryScreen->summary.spdef;
        spe = sMonSummaryScreen->summary.speed;
		//Evs //------------------------------------------------------------------------
		 hpEV = GetMonData(&sMonSummaryScreen->currentMon, MON_DATA_HP_EV);
        atkEV = GetMonData(&sMonSummaryScreen->currentMon, MON_DATA_ATK_EV);
        defEV = GetMonData(&sMonSummaryScreen->currentMon, MON_DATA_DEF_EV);
        spAEV = GetMonData(&sMonSummaryScreen->currentMon, MON_DATA_SPATK_EV);
        spDEV = GetMonData(&sMonSummaryScreen->currentMon, MON_DATA_SPDEF_EV);
        speEV = GetMonData(&sMonSummaryScreen->currentMon, MON_DATA_SPEED_EV);
		//Ivs //------------------------------------------------------------------------
         hpIV = GetMonData(&sMonSummaryScreen->currentMon, MON_DATA_HP_IV);
        atkIV = GetMonData(&sMonSummaryScreen->currentMon, MON_DATA_ATK_IV);
        defIV = GetMonData(&sMonSummaryScreen->currentMon, MON_DATA_DEF_IV);
        spAIV = GetMonData(&sMonSummaryScreen->currentMon, MON_DATA_SPATK_IV);
        spDIV = GetMonData(&sMonSummaryScreen->currentMon, MON_DATA_SPDEF_IV);
        speIV = GetMonData(&sMonSummaryScreen->currentMon, MON_DATA_SPEED_IV);
		//------------------------------------------------------------------------------
	
	for(i = 0; i < 5; i++){
		if (natureMod[i] == 0)
			statcolor[i] = getWhiteFontColor();
		else if (natureMod[i] > 0)
			statcolor[i] = getRedFontColor();
		else
			statcolor[i] = getBlueFontColor();
	}
	
	//Check if the Perfect IVs mode is enabled
	if(FlagGet(FLAG_PERFECT_IVS_MODE)){
		hpIV = 31;
		atkIV = 31;
		defIV = 31;
		spAIV = 31;
		spDIV = 31;
		speIV = 31;
	}
    //Stat names //-------------------------------------------------------------------------------
    statsYPos = 0;
	statsXPos = FIRST_ROW_X;
    statsYPos = statsYPos + SPACE_BETWEEN_STATS;
    PrintSmallTextOnWindow(windowId, gText_MaxHP, statsXPos, statsYPos, 0, getWhiteFontColor());
    statsYPos = statsYPos + SPACE_BETWEEN_STATS;
    PrintSmallTextOnWindow(windowId, gText_Attack, statsXPos, statsYPos, 0, getWhiteFontColor());
    statsYPos = statsYPos + SPACE_BETWEEN_STATS;
    PrintSmallTextOnWindow(windowId, gText_Defense, statsXPos, statsYPos, 0, getWhiteFontColor());
    statsYPos = statsYPos + SPACE_BETWEEN_STATS;
    PrintSmallTextOnWindow(windowId, gText_SpAtk, statsXPos, statsYPos, 0, getWhiteFontColor());
    statsYPos = statsYPos + SPACE_BETWEEN_STATS;
    PrintSmallTextOnWindow(windowId, gText_SpDef, statsXPos, statsYPos, 0, getWhiteFontColor());
    statsYPos = statsYPos + SPACE_BETWEEN_STATS;
    PrintSmallTextOnWindow(windowId, gText_Speed, statsXPos, statsYPos, 0, getWhiteFontColor());
	//Stats //-------------------------------------------------------------------------------
	statsYPos = 0;
	statsXPos = 3 + SECOND_ROW_X;
    //Stat Name
    PrintSmallTextOnWindow(windowId, gText_Stat_Line_2, statsXPos, statsYPos, 0, getWhiteFontColor());
    statsYPos = statsYPos + SPACE_BETWEEN_STATS;
	//Max HP
	ConvertIntToDecimalStringN(gStringVar1, hp, STR_CONV_MODE_LEFT_ALIGN, 7);
	ConvertIntToDecimalStringN(gStringVar2, hp2, STR_CONV_MODE_LEFT_ALIGN, 7);
	StringExpandPlaceholders(gStringVar3, CurrentHP);
	PrintSmallTextOnWindow(windowId, gStringVar3, statsXPos, statsYPos, 0, getWhiteFontColor());
	statsYPos = statsYPos + SPACE_BETWEEN_STATS;
	//Attack
    switch(statcolor[0]){
        case SUMMARY_FONT_COLOR_BLUE:
        case SUMMARY_FONT_COLOR_BLUE_2:
            StringCopy(ConvertIntToDecimalStringN(gStringVar1, atk, STR_CONV_MODE_LEFT_ALIGN, 7), gText_DownSymbol);
        break;
        case SUMMARY_FONT_COLOR_RED:
        case SUMMARY_FONT_COLOR_RED_2:
            StringCopy(ConvertIntToDecimalStringN(gStringVar1, atk, STR_CONV_MODE_LEFT_ALIGN, 7), gText_UpSymbol);
        break;
        default:
            ConvertIntToDecimalStringN(gStringVar1, atk, STR_CONV_MODE_LEFT_ALIGN, 7);
        break;
    }
	PrintSmallTextOnWindow(windowId, gStringVar1, statsXPos, statsYPos, 0, statcolor[0]);
	statsYPos = statsYPos + SPACE_BETWEEN_STATS;
	//Defense
    switch(statcolor[1]){
        case SUMMARY_FONT_COLOR_BLUE:
        case SUMMARY_FONT_COLOR_BLUE_2:
            StringCopy(ConvertIntToDecimalStringN(gStringVar1, def, STR_CONV_MODE_LEFT_ALIGN, 7), gText_DownSymbol);
        break;
        case SUMMARY_FONT_COLOR_RED:
        case SUMMARY_FONT_COLOR_RED_2:
            StringCopy(ConvertIntToDecimalStringN(gStringVar1, def, STR_CONV_MODE_LEFT_ALIGN, 7), gText_UpSymbol);
        break;
        default:
            ConvertIntToDecimalStringN(gStringVar1, def, STR_CONV_MODE_LEFT_ALIGN, 7);
        break;
    }
	PrintSmallTextOnWindow(windowId, gStringVar1, statsXPos, statsYPos, 0, statcolor[1]);
	statsYPos = statsYPos + SPACE_BETWEEN_STATS;
	//Special Attack
    switch(statcolor[2]){
        case SUMMARY_FONT_COLOR_BLUE:
        case SUMMARY_FONT_COLOR_BLUE_2:
            StringCopy(ConvertIntToDecimalStringN(gStringVar1, spA, STR_CONV_MODE_LEFT_ALIGN, 7), gText_DownSymbol);
        break;
        case SUMMARY_FONT_COLOR_RED:
        case SUMMARY_FONT_COLOR_RED_2:
            StringCopy(ConvertIntToDecimalStringN(gStringVar1, spA, STR_CONV_MODE_LEFT_ALIGN, 7), gText_UpSymbol);
        break;
        default:
            ConvertIntToDecimalStringN(gStringVar1, spA, STR_CONV_MODE_LEFT_ALIGN, 7);
        break;
    }
	PrintSmallTextOnWindow(windowId, gStringVar1, statsXPos, statsYPos, 0, statcolor[2]);
	statsYPos = statsYPos + SPACE_BETWEEN_STATS;
	//Special Defense
    switch(statcolor[3]){
        case SUMMARY_FONT_COLOR_BLUE:
        case SUMMARY_FONT_COLOR_BLUE_2:
            StringCopy(ConvertIntToDecimalStringN(gStringVar1, spD, STR_CONV_MODE_LEFT_ALIGN, 7), gText_DownSymbol);
        break;
        case SUMMARY_FONT_COLOR_RED:
        case SUMMARY_FONT_COLOR_RED_2:
            StringCopy(ConvertIntToDecimalStringN(gStringVar1, spD, STR_CONV_MODE_LEFT_ALIGN, 7), gText_UpSymbol);
        break;
        default:
            ConvertIntToDecimalStringN(gStringVar1, spD, STR_CONV_MODE_LEFT_ALIGN, 7);
        break;
    }
	PrintSmallTextOnWindow(windowId, gStringVar1, statsXPos, statsYPos, 0, statcolor[3]);
	statsYPos = statsYPos + SPACE_BETWEEN_STATS;
	//Speed
    switch(statcolor[4]){
        case SUMMARY_FONT_COLOR_BLUE:
        case SUMMARY_FONT_COLOR_BLUE_2:
            StringCopy(ConvertIntToDecimalStringN(gStringVar1, spe, STR_CONV_MODE_LEFT_ALIGN, 7), gText_DownSymbol);
        break;
        case SUMMARY_FONT_COLOR_RED:
        case SUMMARY_FONT_COLOR_RED_2:
            StringCopy(ConvertIntToDecimalStringN(gStringVar1, spe, STR_CONV_MODE_LEFT_ALIGN, 7), gText_UpSymbol);
        break;
        default:
            ConvertIntToDecimalStringN(gStringVar1, spe, STR_CONV_MODE_LEFT_ALIGN, 7);
        break;
    }
	PrintSmallTextOnWindow(windowId, gStringVar1, statsXPos, statsYPos, 0, statcolor[4]);
	statsYPos = statsYPos + SPACE_BETWEEN_STATS;
    //---------------------------------------------------------------------------------------   
	//IVS
	statsYPos = 0;
	statsXPos = statsXPos + 40;
    //Stat Name
    PrintSmallTextOnWindow(windowId, gText_Stat_Line_3, statsXPos, statsYPos, 0, getWhiteFontColor());
    statsYPos = statsYPos + SPACE_BETWEEN_STATS;
	//HP IV
	ConvertIntToDecimalStringN(StringCopy(gStringVar1, gText_ExpandedPlaceholder_Empty), hpIV, STR_CONV_MODE_LEFT_ALIGN, 7);
	PrintSmallTextOnWindow(windowId, gStringVar1, statsXPos, statsYPos, 0, getWhiteFontColor());
	statsYPos = statsYPos + SPACE_BETWEEN_STATS;
	//Attack
	ConvertIntToDecimalStringN(StringCopy(gStringVar1, gText_ExpandedPlaceholder_Empty), atkIV, STR_CONV_MODE_LEFT_ALIGN, 7);
	PrintSmallTextOnWindow(windowId, gStringVar1, statsXPos, statsYPos, 0, statcolor[0]);
	statsYPos = statsYPos + SPACE_BETWEEN_STATS;
	//Defense
	ConvertIntToDecimalStringN(StringCopy(gStringVar1, gText_ExpandedPlaceholder_Empty), defIV, STR_CONV_MODE_LEFT_ALIGN, 7);
	PrintSmallTextOnWindow(windowId, gStringVar1, statsXPos, statsYPos, 0, statcolor[1]);
	statsYPos = statsYPos + SPACE_BETWEEN_STATS;
	//Special Attack
    ConvertIntToDecimalStringN(StringCopy(gStringVar1, gText_ExpandedPlaceholder_Empty), spAIV, STR_CONV_MODE_LEFT_ALIGN, 7);
	PrintSmallTextOnWindow(windowId, gStringVar1, statsXPos, statsYPos, 0, statcolor[2]);
	statsYPos = statsYPos + SPACE_BETWEEN_STATS;
	//Special Defense
    ConvertIntToDecimalStringN(StringCopy(gStringVar1, gText_ExpandedPlaceholder_Empty), spDIV, STR_CONV_MODE_LEFT_ALIGN, 7);
	PrintSmallTextOnWindow(windowId, gStringVar1, statsXPos, statsYPos, 0, statcolor[3]);
	statsYPos = statsYPos + SPACE_BETWEEN_STATS;
	//Speed
    ConvertIntToDecimalStringN(StringCopy(gStringVar1, gText_ExpandedPlaceholder_Empty), speIV, STR_CONV_MODE_LEFT_ALIGN, 7);
	PrintSmallTextOnWindow(windowId, gStringVar1, statsXPos, statsYPos, 0, statcolor[4]);
	statsYPos = statsYPos + SPACE_BETWEEN_STATS;
    //---------------------------------------------------------------------------------------   
	//Evs
	statsYPos = 0;
	statsXPos = statsXPos + 24;
    //Stat Name
    PrintSmallTextOnWindow(windowId, gText_Stat_Line_4, statsXPos, statsYPos, 0, getWhiteFontColor());
    statsYPos = statsYPos + SPACE_BETWEEN_STATS;
	//HP EV
	ConvertIntToDecimalStringN(StringCopy(gStringVar1, gText_ExpandedPlaceholder_Empty), hpEV, STR_CONV_MODE_LEFT_ALIGN, 7);
	PrintSmallTextOnWindow(windowId, gStringVar1, statsXPos, statsYPos, 0, getWhiteFontColor());
	statsYPos = statsYPos + SPACE_BETWEEN_STATS;
	//Attack
	ConvertIntToDecimalStringN(StringCopy(gStringVar1, gText_ExpandedPlaceholder_Empty), atkEV, STR_CONV_MODE_LEFT_ALIGN, 7);
	PrintSmallTextOnWindow(windowId, gStringVar1, statsXPos, statsYPos, 0, statcolor[0]);
	statsYPos = statsYPos + SPACE_BETWEEN_STATS;
	//Defense
	ConvertIntToDecimalStringN(StringCopy(gStringVar1, gText_ExpandedPlaceholder_Empty), defEV, STR_CONV_MODE_LEFT_ALIGN, 7);
	PrintSmallTextOnWindow(windowId, gStringVar1, statsXPos, statsYPos, 0, statcolor[1]);
	statsYPos = statsYPos + SPACE_BETWEEN_STATS;
	//Special Attack
    ConvertIntToDecimalStringN(StringCopy(gStringVar1, gText_ExpandedPlaceholder_Empty), spAEV, STR_CONV_MODE_LEFT_ALIGN, 7);
	PrintSmallTextOnWindow(windowId, gStringVar1, statsXPos, statsYPos, 0, statcolor[2]);
	statsYPos = statsYPos + SPACE_BETWEEN_STATS;
	//Special Defense
    ConvertIntToDecimalStringN(StringCopy(gStringVar1, gText_ExpandedPlaceholder_Empty), spDEV, STR_CONV_MODE_LEFT_ALIGN, 7);
	PrintSmallTextOnWindow(windowId, gStringVar1, statsXPos, statsYPos, 0, statcolor[3]);
	statsYPos = statsYPos + SPACE_BETWEEN_STATS;
	//Speed
    ConvertIntToDecimalStringN(StringCopy(gStringVar1, gText_ExpandedPlaceholder_Empty), speEV, STR_CONV_MODE_LEFT_ALIGN, 7);
	PrintSmallTextOnWindow(windowId, gStringVar1, statsXPos, statsYPos, 0, statcolor[4]);
	statsYPos = statsYPos + SPACE_BETWEEN_STATS;

    //Ev Modifier
    statsYPos = SPACE_BETWEEN_STATS + 4;
    statsXPos = statsXPos - 4;
	for(j = 0; j < NUM_STATS; j++){
		if (j == sMonSummaryScreen->gCurrentStattoModify && sMonSummaryScreen->ModifyStatMode)
			BlitBitmapToWindow(windowId, sSummaryEVIcon, statsXPos, statsYPos, 24, 8);
		
		statsYPos = statsYPos + SPACE_BETWEEN_STATS;
	}
}

static void PrintStatPage_Bottom(void)
{
	//Prints Ability Related Text
	int windowId = PSS_WINDOW_BOTTOM;
	const u8 *text;
    struct Pokemon *mon = &sMonSummaryScreen->currentMon;
    struct PokeSummary *summary = &sMonSummaryScreen->summary;
    u16 formSpeciesId = GetFormSpeciesId(summary->species, summary->formId);
    u8 type1 = RandomizePokemonType(gVanillaBaseStats[formSpeciesId].type1, summary->pid, FALSE);
    u8 type2 = RandomizePokemonType(gVanillaBaseStats[formSpeciesId].type2, summary->pid, TRUE);
    const u8 gText_Other_Info[]   = _("Other Info:");
    const u8 gText_Hidden_Power[] = _("HP Type: {STR_VAR_1}");
    const u8 gText_Friendship[]   = _("Friendship: {STR_VAR_1}%");
    const u8 gText_ExtraType[]    = _("Extra Type: {STR_VAR_1}");
    u8 typeBits, type;
	u16 PosX = 0; //(9 * 8) + 14;
    u16 PosY = 4;
	u8 i;
	u16 ability;
	u8 abilityNum;
	u8 friendship = ((sMonSummaryScreen->summary.friendship - 5 ) * 4) / 10;
	
    //Friendship
    ConvertIntToDecimalStringN(gStringVar1, friendship, STR_CONV_MODE_LEFT_ALIGN, 4);
    StringExpandPlaceholders(gStringVar4, gText_Friendship);
    PrintSmallTextOnWindow(windowId, gStringVar4, PosX, PosY, 0, SUMMARY_FONT_COLOR_WHITE);

    //Extra Type
    if(FlagGet(FLAG_THIRD_TYPE_MODE)){
        PosY = PosY + 16;
        StringCopy(gStringVar1, gTypeNames[GetThirdTypeFromPersonality(summary->pid, type1, type2)]);
        StringExpandPlaceholders(gStringVar4, gText_ExtraType);
        PrintSmallTextOnWindow(windowId, gStringVar4, PosX, PosY, 0, SUMMARY_FONT_COLOR_WHITE);
    }

    //Hidden Power
    PosX = 140; 
    PosY = 4;

	typeBits  = ((GetMonData(mon, MON_DATA_HP_IV) & 1) << 0)
              | ((GetMonData(mon, MON_DATA_ATK_IV) & 1) << 1)
              | ((GetMonData(mon, MON_DATA_DEF_IV) & 1) << 2)
              | ((GetMonData(mon, MON_DATA_SPEED_IV) & 1) << 3)
              | ((GetMonData(mon, MON_DATA_SPATK_IV) & 1) << 4)
              | ((GetMonData(mon, MON_DATA_SPDEF_IV) & 1) << 5);

    type = (15 * typeBits) / 63 + 1;
    if (type >= TYPE_MYSTERY)
        type++;
    type |= 0xC0;
    StringCopy(gStringVar1, gTypeNames[type & 0x3F]);
    StringExpandPlaceholders(gStringVar4, gText_Hidden_Power);
    PrintSmallTextOnWindow(windowId, gStringVar4, PosX, PosY, 0, SUMMARY_FONT_COLOR_WHITE);
}

//Third Screen
static void PrintMoveNameAndPP(u8 moveIndex)
{
    u8 pp;
    int ppState, x;
    const u8 *text;
    struct PokeSummary *summary = &sMonSummaryScreen->summary;
    int windowId = PSS_WINDOW_MIDDLE_RIGHT;
    u16 move = summary->moves[moveIndex];
    u16 speciesId = GetFormSpeciesId(summary->species, summary->formId);
    u8 PosX = 7 * 8;
    u8 PosY = (moveIndex * 16 + 1) + 16;
    bool8 isNewMove = FALSE;

    if(moveIndex == 4)
        isNewMove = TRUE;

    if(isNewMove)
        move = sMonSummaryScreen->newMove;

    if (move != MOVE_NONE)
    {
        pp = CalculatePPWithBonus(move, summary->ppBonuses, moveIndex);

        if(gSignatureMoveList[speciesId].move == move)
            PrintNarrowTextOnWindow(windowId, gMoveNames[move], PosX, PosY, 0, getBlueFontColor());
        else if(!isNewMove)
            PrintNarrowTextOnWindow(windowId, gMoveNames[move], PosX, PosY, 0, getWhiteFontColor());
        else
            PrintNarrowTextOnWindow(windowId, gMoveNames[move], PosX, PosY, 0, SUMMARY_FONT_COLOR_RED);
        
        ConvertIntToDecimalStringN(gStringVar1, summary->pp[moveIndex], STR_CONV_MODE_RIGHT_ALIGN, 2);
        ConvertIntToDecimalStringN(gStringVar2, pp, STR_CONV_MODE_RIGHT_ALIGN, 2);
        DynamicPlaceholderTextUtil_Reset();
        DynamicPlaceholderTextUtil_SetPlaceholderPtr(0, gStringVar1);
        DynamicPlaceholderTextUtil_SetPlaceholderPtr(1, gStringVar2);
        DynamicPlaceholderTextUtil_ExpandPlaceholders(gStringVar4, sMovesPPLayout);
        text = gStringVar4;
        ppState = GetCurrentPpToMaxPpState(summary->pp[moveIndex], pp) + 9;
        x = GetStringRightAlignXOffset(7, text, 48);
    }
    else
    {
        if(!isNewMove)
            PrintNarrowTextOnWindow(windowId, gText_OneDash, PosX, PosY, 0, getWhiteFontColor());
        else
            PrintNarrowTextOnWindow(windowId, gText_Cancel, PosX, PosY, 0, getWhiteFontColor());
    }

    if(move != MOVE_NONE && !isNewMove){
        PosX = PosX + (8 * 8) + (x - 2);

        PrintSmallTextOnWindow(windowId, text, PosX, PosY, 0, getWhiteFontColor());
    }
}

// ------------------------------------------------------------------------------------------------------------------
//Scrolling
static void PssScrollRight(u8 taskId) // Scroll right
{
    s16 *data = gTasks[taskId].data;
    if (data[0] == 0)
    {
        if (sMonSummaryScreen->bgDisplayOrder == 0)
        {
            data[1] = 1;
            SetBgAttribute(1, BG_ATTR_PRIORITY, 1);
            SetBgAttribute(2, BG_ATTR_PRIORITY, 2);
            ScheduleBgCopyTilemapToVram(1);
        }
        else
        {
            data[1] = 2;
            SetBgAttribute(2, BG_ATTR_PRIORITY, 1);
            SetBgAttribute(1, BG_ATTR_PRIORITY, 2);
            ScheduleBgCopyTilemapToVram(2);
        }
        ChangeBgX(data[1], 0, 0);
        SetBgTilemapBuffer(data[1], sMonSummaryScreen->bgTilemapBuffers[sMonSummaryScreen->currPageIndex][0]);
        ShowBg(1);
        ShowBg(2);
    }
    ChangeBgX(data[1], 0x2000, 1);
    data[0] += 32;
    if (data[0] > 0xFF)
        gTasks[taskId].func = PssScrollRightEnd;
}

static void PssScrollRightEnd(u8 taskId) // display right
{
    s16 *data = gTasks[taskId].data;
    sMonSummaryScreen->bgDisplayOrder ^= 1;
    data[1] = 0;
    data[0] = 0;
    DrawPagination();
    PutPageWindowTilemaps(sMonSummaryScreen->currPageIndex);
    SetTypeIcons();
    TryDrawExperienceProgressBar();
    SwitchTaskToFollowupFunc(taskId);
}

static void PssScrollLeft(u8 taskId) // Scroll left
{
    s16 *data = gTasks[taskId].data;
    if (data[0] == 0)
    {
        if (sMonSummaryScreen->bgDisplayOrder == 0)
            data[1] = 2;
        else
            data[1] = 1;
        ChangeBgX(data[1], 0x10000, 0);
    }
    ChangeBgX(data[1], 0x2000, 2);
    data[0] += 32;
    if (data[0] > 0xFF)
        gTasks[taskId].func = PssScrollLeftEnd;
}

static void PssScrollLeftEnd(u8 taskId) // display left
{
    s16 *data = gTasks[taskId].data;
    if (sMonSummaryScreen->bgDisplayOrder == 0)
    {
        SetBgAttribute(1, BG_ATTR_PRIORITY, 1);
        SetBgAttribute(2, BG_ATTR_PRIORITY, 2);
        ScheduleBgCopyTilemapToVram(2);
    }
    else
    {
        SetBgAttribute(2, BG_ATTR_PRIORITY, 1);
        SetBgAttribute(1, BG_ATTR_PRIORITY, 2);
        ScheduleBgCopyTilemapToVram(1);
    }
    if (sMonSummaryScreen->currPageIndex > 1)
    {
        SetBgTilemapBuffer(data[1], sMonSummaryScreen->bgTilemapBuffers[sMonSummaryScreen->currPageIndex - 1][0]);
        ChangeBgX(data[1], 0x10000, 0);
    }
    ShowBg(1);
    ShowBg(2);
    sMonSummaryScreen->bgDisplayOrder ^= 1;
    data[1] = 0;
    data[0] = 0;
    DrawPagination();
    PutPageWindowTilemaps(sMonSummaryScreen->currPageIndex);
    SetTypeIcons();
    TryDrawExperienceProgressBar();
    SwitchTaskToFollowupFunc(taskId);
}

static void TryDrawExperienceProgressBar(void)
{
    if (sMonSummaryScreen->currPageIndex == PSS_PAGE_SKILLS)
        DrawExperienceProgressBar(&sMonSummaryScreen->currentMon);
}

static void SwitchToMoveSelection(u8 taskId)
{
    u16 move;
    u8 windowId = PSS_WINDOW_MIDDLE_RIGHT;

    sMonSummaryScreen->firstMoveIndex = 0;
    move = sMonSummaryScreen->summary.moves[sMonSummaryScreen->firstMoveIndex];
    if (!gSprites[sMonSummaryScreen->spriteIds[SPRITE_ARR_ID_STATUS]].invisible)
        ClearWindowTilemap(windowId);
    HandlePowerAccTilemap(9, -3);
    HandleAppealJamTilemap(9, -3, move);
    if (!sMonSummaryScreen->lockMovesFlag)
    {
        PutWindowTilemap(windowId);
    }
    PrintMoveDetails(move);
    PrintNewMoveDetailsOrCancelText();
    SetNewMoveTypeIcon();
    CreateMoveSelectorSprites(SPRITE_ARR_ID_MOVE_SELECTOR1);
    gTasks[taskId].func = Task_HandleInput_MoveSelect;
}

static void Task_HandleInput_MoveSelect(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    if (MenuHelpers_CallLinkSomething() != 1)
    {
        if (JOY_NEW(DPAD_UP))
        {
            data[0] = 4;
            ChangeSelectedMove(data, -1, &sMonSummaryScreen->firstMoveIndex);
        }
        else if (JOY_NEW(DPAD_DOWN))
        {
            data[0] = 4;
            ChangeSelectedMove(data, 1, &sMonSummaryScreen->firstMoveIndex);
        }
        else if (JOY_NEW(A_BUTTON))
        {
            if (sMonSummaryScreen->lockMovesFlag == TRUE
             || (sMonSummaryScreen->newMove == MOVE_NONE && sMonSummaryScreen->firstMoveIndex == MAX_MON_MOVES))
            {
                PlaySE(SE_SELECT);
                CloseMoveSelectMode(taskId);
            }
            else if (HasMoreThanOneMove() == TRUE)
            {
                PlaySE(SE_SELECT);
                SwitchToMovePositionSwitchMode(taskId);
            }
            else
            {
                PlaySE(SE_FAILURE);
            }
        }
        else if (JOY_NEW(B_BUTTON))
        {
            PlaySE(SE_SELECT);
            CloseMoveSelectMode(taskId);
        }
    }
    ScrollBackground();
}

static bool8 HasMoreThanOneMove(void)
{
    u8 i;
    for (i = 1; i < MAX_MON_MOVES; i++)
    {
        if (sMonSummaryScreen->summary.moves[i] != 0)
            return TRUE;
    }
    return FALSE;
}

static void ChangeSelectedMove(s16 *taskData, s8 direction, u8 *moveIndexPtr)
{
    s8 i, newMoveIndex;
    u16 move;

    PlaySE(SE_SELECT);
    newMoveIndex = *moveIndexPtr;
    for (i = 0; i < MAX_MON_MOVES; i++)
    {
        newMoveIndex += direction;
        if (newMoveIndex > taskData[0])
            newMoveIndex = 0;
        else if (newMoveIndex < 0)
            newMoveIndex = taskData[0];

        if (newMoveIndex == MAX_MON_MOVES)
        {
            move = sMonSummaryScreen->newMove;
            break;
        }
        move = sMonSummaryScreen->summary.moves[newMoveIndex];
        if (move != 0)
            break;
    }
    if ((*moveIndexPtr == MAX_MON_MOVES && sMonSummaryScreen->newMove == MOVE_NONE)
        || taskData[1] == 1)
    {
        if (!gSprites[sMonSummaryScreen->spriteIds[SPRITE_ARR_ID_STATUS]].invisible)
            ClearWindowTilemap(PSS_LABEL_WINDOW_POKEMON_SKILLS_STATUS);
        HandlePowerAccTilemap(9, -3);
        HandleAppealJamTilemap(9, -3, move);
    }
    if (*moveIndexPtr != MAX_MON_MOVES
        && newMoveIndex == MAX_MON_MOVES
        && sMonSummaryScreen->newMove == MOVE_NONE)
    {
        ClearWindowTilemap(PSS_LABEL_WINDOW_MOVES_POWER_ACC);
        ClearWindowTilemap(PSS_LABEL_WINDOW_MOVES_APPEAL_JAM);
        DestroySplitIcon();
    }

    *moveIndexPtr = newMoveIndex;
    // Get rid of the 'flicker' effect(while idle) when scrolling.
    if (moveIndexPtr == &sMonSummaryScreen->firstMoveIndex)
        KeepMoveSelectorVisible(SPRITE_ARR_ID_MOVE_SELECTOR1);
    else
        KeepMoveSelectorVisible(SPRITE_ARR_ID_MOVE_SELECTOR2);

    FillWindowPixelBuffer(PSS_WINDOW_MIDDLE_RIGHT, PIXEL_FILL(TEXT_COLOR_TRANSPARENT));
    PrintBattleMoves();
    PrintMoveDetails(move);
}

static void CloseMoveSelectMode(u8 taskId)
{
    DestroyMoveSelectorSprites(SPRITE_ARR_ID_MOVE_SELECTOR1);
    PrintMoveDetails(0);
    AddAndFillMoveNamesWindow(); // This function seems to have no effect.
    if (sMonSummaryScreen->firstMoveIndex != MAX_MON_MOVES)
    {
        ClearWindowTilemap(PSS_LABEL_WINDOW_MOVES_POWER_ACC);
        ClearWindowTilemap(PSS_LABEL_WINDOW_MOVES_APPEAL_JAM);
        DestroySplitIcon();
    }
    gTasks[taskId].func = Task_HandleInput;
}

static void SwitchToMovePositionSwitchMode(u8 taskId)
{
    sMonSummaryScreen->secondMoveIndex = sMonSummaryScreen->firstMoveIndex;
    SetMainMoveSelectorColor(1);
    CreateMoveSelectorSprites(SPRITE_ARR_ID_MOVE_SELECTOR2);
    gTasks[taskId].func = Task_HandleInput_MovePositionSwitch;
}

static void Task_HandleInput_MovePositionSwitch(u8 taskId)
{
    s16* data = gTasks[taskId].data;

    if (MenuHelpers_CallLinkSomething() != TRUE)
    {
        if (JOY_NEW(DPAD_UP))
        {
            data[0] = 3;
            ChangeSelectedMove(&data[0], -1, &sMonSummaryScreen->secondMoveIndex);
        }
        else if (JOY_NEW(DPAD_DOWN))
        {
            data[0] = 3;
            ChangeSelectedMove(&data[0], 1, &sMonSummaryScreen->secondMoveIndex);
        }
        else if (JOY_NEW(A_BUTTON))
        {
            if (sMonSummaryScreen->firstMoveIndex == sMonSummaryScreen->secondMoveIndex)
                ExitMovePositionSwitchMode(taskId, FALSE);
            else
                ExitMovePositionSwitchMode(taskId, TRUE);
        }
        else if (JOY_NEW(B_BUTTON))
        {
            ExitMovePositionSwitchMode(taskId, FALSE);
        }
    }
    ScrollBackground();
}

static void ExitMovePositionSwitchMode(u8 taskId, bool8 swapMoves)
{
    u16 move;

    PlaySE(SE_SELECT);
    SetMainMoveSelectorColor(0);
    DestroyMoveSelectorSprites(SPRITE_ARR_ID_MOVE_SELECTOR2);

    if (swapMoves == TRUE)
    {
        if (!sMonSummaryScreen->isBoxMon)
        {
            struct Pokemon *mon = sMonSummaryScreen->monList.mons;
            SwapMonMoves(&mon[sMonSummaryScreen->curMonIndex], sMonSummaryScreen->firstMoveIndex, sMonSummaryScreen->secondMoveIndex);
        }
        else
        {
            struct BoxPokemon *boxMon = sMonSummaryScreen->monList.boxMons;
            SwapBoxMonMoves(&boxMon[sMonSummaryScreen->curMonIndex], sMonSummaryScreen->firstMoveIndex, sMonSummaryScreen->secondMoveIndex);
        }
        CopyMonToSummaryStruct(&sMonSummaryScreen->currentMon);
        SwapMovesNamesPP(sMonSummaryScreen->firstMoveIndex, sMonSummaryScreen->secondMoveIndex);
        SwapMovesTypeSprites(sMonSummaryScreen->firstMoveIndex, sMonSummaryScreen->secondMoveIndex);
        sMonSummaryScreen->firstMoveIndex = sMonSummaryScreen->secondMoveIndex;
    }

    move = sMonSummaryScreen->summary.moves[sMonSummaryScreen->firstMoveIndex];

    FillWindowPixelBuffer(PSS_WINDOW_MIDDLE_RIGHT, PIXEL_FILL(TEXT_COLOR_TRANSPARENT));
    PrintBattleMoves();
    PrintMoveDetails(move);  

    gTasks[taskId].func = Task_HandleInput_MoveSelect;
}

static void SwapMonMoves(struct Pokemon *mon, u8 moveIndex1, u8 moveIndex2)
{
    struct PokeSummary* summary = &sMonSummaryScreen->summary;

    u16 move1 = summary->moves[moveIndex1];
    u16 move2 = summary->moves[moveIndex2];
    u8 move1pp = summary->pp[moveIndex1];
    u8 move2pp = summary->pp[moveIndex2];
    u8 ppBonuses = summary->ppBonuses;

    // Calculate PP bonuses
    u8 ppUpMask1 = gPPUpGetMask[moveIndex1];
    u8 ppBonusMove1 = (ppBonuses & ppUpMask1) >> (moveIndex1 * 2);
    u8 ppUpMask2 = gPPUpGetMask[moveIndex2];
    u8 ppBonusMove2 = (ppBonuses & ppUpMask2) >> (moveIndex2 * 2);
    ppBonuses &= ~ppUpMask1;
    ppBonuses &= ~ppUpMask2;
    ppBonuses |= (ppBonusMove1 << (moveIndex2 * 2)) + (ppBonusMove2 << (moveIndex1 * 2));

    // Swap the moves
    SetMonData(mon, MON_DATA_MOVE1 + moveIndex1, &move2);
    SetMonData(mon, MON_DATA_MOVE1 + moveIndex2, &move1);
    SetMonData(mon, MON_DATA_PP1 + moveIndex1, &move2pp);
    SetMonData(mon, MON_DATA_PP1 + moveIndex2, &move1pp);
    SetMonData(mon, MON_DATA_PP_BONUSES, &ppBonuses);

    summary->moves[moveIndex1] = move2;
    summary->moves[moveIndex2] = move1;

    summary->pp[moveIndex1] = move2pp;
    summary->pp[moveIndex2] = move1pp;

    summary->ppBonuses = ppBonuses;
}

static void SwapBoxMonMoves(struct BoxPokemon *mon, u8 moveIndex1, u8 moveIndex2)
{
    struct PokeSummary* summary = &sMonSummaryScreen->summary;

    u16 move1 = summary->moves[moveIndex1];
    u16 move2 = summary->moves[moveIndex2];
    u8 move1pp = summary->pp[moveIndex1];
    u8 move2pp = summary->pp[moveIndex2];
    u8 ppBonuses = summary->ppBonuses;

    // Calculate PP bonuses
    u8 ppUpMask1 = gPPUpGetMask[moveIndex1];
    u8 ppBonusMove1 = (ppBonuses & ppUpMask1) >> (moveIndex1 * 2);
    u8 ppUpMask2 = gPPUpGetMask[moveIndex2];
    u8 ppBonusMove2 = (ppBonuses & ppUpMask2) >> (moveIndex2 * 2);
    ppBonuses &= ~ppUpMask1;
    ppBonuses &= ~ppUpMask2;
    ppBonuses |= (ppBonusMove1 << (moveIndex2 * 2)) + (ppBonusMove2 << (moveIndex1 * 2));

    // Swap the moves
    SetBoxMonData(mon, MON_DATA_MOVE1 + moveIndex1, &move2);
    SetBoxMonData(mon, MON_DATA_MOVE1 + moveIndex2, &move1);
    SetBoxMonData(mon, MON_DATA_PP1 + moveIndex1, &move2pp);
    SetBoxMonData(mon, MON_DATA_PP1 + moveIndex2, &move1pp);
    SetBoxMonData(mon, MON_DATA_PP_BONUSES, &ppBonuses);

    summary->moves[moveIndex1] = move2;
    summary->moves[moveIndex2] = move1;

    summary->pp[moveIndex1] = move2pp;
    summary->pp[moveIndex2] = move1pp;

    summary->ppBonuses = ppBonuses;
}

static void Task_SetHandleReplaceMoveInput(u8 taskId)
{
    SetNewMoveTypeIcon();
    CreateMoveSelectorSprites(SPRITE_ARR_ID_MOVE_SELECTOR1);
    gTasks[taskId].func = Task_HandleReplaceMoveInput;
}

static void Task_HandleReplaceMoveInput(u8 taskId)
{
    s16* data = gTasks[taskId].data;

    if (MenuHelpers_CallLinkSomething() != TRUE)
    {
        if (gPaletteFade.active != TRUE)
        {
            if (JOY_NEW(DPAD_UP))
            {
                data[0] = 4;
                ChangeSelectedMove(data, -1, &sMonSummaryScreen->firstMoveIndex);
            }
            else if (JOY_NEW(DPAD_DOWN))
            {
                data[0] = 4;
                ChangeSelectedMove(data, 1, &sMonSummaryScreen->firstMoveIndex);
            }
            else if (JOY_NEW(DPAD_LEFT) || GetLRKeysPressed() == MENU_L_PRESSED)
            {
                ChangePage(taskId, -1);
            }
            else if (JOY_NEW(DPAD_RIGHT) || GetLRKeysPressed() == MENU_R_PRESSED)
            {
                ChangePage(taskId, 1);
            }
            else if (JOY_NEW(A_BUTTON))
            {
                if (CanReplaceMove() == TRUE)
                {
                    StopPokemonAnimations();
                    PlaySE(SE_SELECT);
                    sMoveSlotToReplace = sMonSummaryScreen->firstMoveIndex;
                    gSpecialVar_0x8005 = sMoveSlotToReplace;
                    BeginCloseSummaryScreen(taskId);
                }
                else
                {
                    PlaySE(SE_FAILURE);
                    ShowCantForgetHMsWindow(taskId);
                }
            }
            else if (JOY_NEW(B_BUTTON))
            {
                StopPokemonAnimations();
                PlaySE(SE_SELECT);
                sMoveSlotToReplace = MAX_MON_MOVES;
                gSpecialVar_0x8005 = MAX_MON_MOVES;
                BeginCloseSummaryScreen(taskId);
            }
        }
    }
    ScrollBackground();
}

static bool8 CanReplaceMove(void)
{
    if (sMonSummaryScreen->firstMoveIndex == MAX_MON_MOVES
        || sMonSummaryScreen->newMove == MOVE_NONE
        || IsMoveHm(sMonSummaryScreen->summary.moves[sMonSummaryScreen->firstMoveIndex]) != TRUE)
        return TRUE;
    else
        return FALSE;
}

static void ShowCantForgetHMsWindow(u8 taskId)
{
    ClearWindowTilemap(PSS_LABEL_WINDOW_MOVES_POWER_ACC);
    ClearWindowTilemap(PSS_LABEL_WINDOW_MOVES_APPEAL_JAM);
    gSprites[sMonSummaryScreen->splitIconSpriteId].invisible = TRUE;
    ScheduleBgCopyTilemapToVram(0);
    //HandlePowerAccTilemap(0, 3);
    HandleAppealJamTilemap(0, 3, 0);
    PrintHMMovesCantBeForgotten();
    gTasks[taskId].func = Task_HandleInputCantForgetHMsMoves;
}

// This redraws the power/accuracy window when the player scrolls out of the "HM Moves can't be forgotten" message
static void Task_HandleInputCantForgetHMsMoves(u8 taskId)
{
    s16* data = gTasks[taskId].data;
    u16 move;
    if (FuncIsActiveTask(Task_ShowPowerAccWindow) != 1)
    {
        if (JOY_NEW(DPAD_UP))
        {
            data[1] = 1;
            data[0] = 4;
            ChangeSelectedMove(&data[0], -1, &sMonSummaryScreen->firstMoveIndex);
            data[1] = 0;
            gTasks[taskId].func = Task_HandleReplaceMoveInput;
        }
        else if (JOY_NEW(DPAD_DOWN))
        {
            data[1] = 1;
            data[0] = 4;
            ChangeSelectedMove(&data[0], 1, &sMonSummaryScreen->firstMoveIndex);
            data[1] = 0;
            gTasks[taskId].func = Task_HandleReplaceMoveInput;
        }
        else if (JOY_NEW(DPAD_LEFT) || GetLRKeysPressed() == MENU_L_PRESSED)
        {
            if (sMonSummaryScreen->currPageIndex != PSS_PAGE_BATTLE_MOVES)
            {
                ClearWindowTilemap(PSS_LABEL_WINDOW_PORTRAIT_SPECIES);
                if (!gSprites[sMonSummaryScreen->spriteIds[SPRITE_ARR_ID_STATUS]].invisible)
                    ClearWindowTilemap(PSS_LABEL_WINDOW_POKEMON_SKILLS_STATUS);
                move = sMonSummaryScreen->summary.moves[sMonSummaryScreen->firstMoveIndex];
                gTasks[taskId].func = Task_HandleReplaceMoveInput;
                ChangePage(taskId, -1);
                //HandlePowerAccTilemap(9, -2);
                HandleAppealJamTilemap(9, -2, move);
            }
        }
        else if (JOY_NEW(DPAD_RIGHT) || GetLRKeysPressed() == MENU_R_PRESSED)
        {
            if (sMonSummaryScreen->currPageIndex != PSS_PAGE_CONTEST_MOVES)
            {
                ClearWindowTilemap(PSS_LABEL_WINDOW_PORTRAIT_SPECIES);
                if (!gSprites[sMonSummaryScreen->spriteIds[SPRITE_ARR_ID_STATUS]].invisible)
                    ClearWindowTilemap(PSS_LABEL_WINDOW_POKEMON_SKILLS_STATUS);
                move = sMonSummaryScreen->summary.moves[sMonSummaryScreen->firstMoveIndex];
                gTasks[taskId].func = Task_HandleReplaceMoveInput;
                ChangePage(taskId, 1);
                //HandlePowerAccTilemap(9, -2);
                HandleAppealJamTilemap(9, -2, move);
            }
        }
        else if (JOY_NEW(A_BUTTON | B_BUTTON))
        {
            ClearWindowTilemap(PSS_LABEL_WINDOW_PORTRAIT_SPECIES);
            if (!gSprites[sMonSummaryScreen->spriteIds[SPRITE_ARR_ID_STATUS]].invisible)
                ClearWindowTilemap(PSS_LABEL_WINDOW_POKEMON_SKILLS_STATUS);
            move = sMonSummaryScreen->summary.moves[sMonSummaryScreen->firstMoveIndex];
            PrintMoveDetails(move);
            ScheduleBgCopyTilemapToVram(0);
            //HandlePowerAccTilemap(9, -3);
            HandleAppealJamTilemap(9, -3, move);
            gTasks[taskId].func = Task_HandleReplaceMoveInput;
        }
    }
}

u8 GetMoveSlotToReplace(void)
{
    return sMoveSlotToReplace;
}

static void DrawPagination(void) // Updates the pagination dots at the top of the summary screen
{
    /*/u16 *alloced = Alloc(32);
    u8 i;

    for (i = 0; i < 4; i++)
    {
        u8 j = i * 2;

        if (i < sMonSummaryScreen->minPageIndex)
        {
            alloced[j + 0] = 0x40;
            alloced[j + 1] = 0x40;
            alloced[j + 8] = 0x50;
            alloced[j + 9] = 0x50;
        }
        else if (i > sMonSummaryScreen->maxPageIndex)
        {
            alloced[j + 0] = 0x4A;
            alloced[j + 1] = 0x4A;
            alloced[j + 8] = 0x5A;
            alloced[j + 9] = 0x5A;
        }
        else if (i < sMonSummaryScreen->currPageIndex)
        {
            alloced[j + 0] = 0x46;
            alloced[j + 1] = 0x47;
            alloced[j + 8] = 0x56;
            alloced[j + 9] = 0x57;
        }
        else if (i == sMonSummaryScreen->currPageIndex)
        {
            if (i != sMonSummaryScreen->maxPageIndex)
            {
                alloced[j + 0] = 0x41;
                alloced[j + 1] = 0x42;
                alloced[j + 8] = 0x51;
                alloced[j + 9] = 0x52;
            }
            else
            {
                alloced[j + 0] = 0x4B;
                alloced[j + 1] = 0x4C;
                alloced[j + 8] = 0x5B;
                alloced[j + 9] = 0x5C;
            }
        }
        else if (i != sMonSummaryScreen->maxPageIndex)
        {
            alloced[j + 0] = 0x43;
            alloced[j + 1] = 0x44;
            alloced[j + 8] = 0x53;
            alloced[j + 9] = 0x54;
        }
        else
        {
            alloced[j + 0] = 0x48;
            alloced[j + 1] = 0x49;
            alloced[j + 8] = 0x58;
            alloced[j + 9] = 0x59;
        }
    }
    CopyToBgTilemapBufferRect_ChangePalette(3, alloced, 11, 0, 8, 2, 16);
    ScheduleBgCopyTilemapToVram(3);
    Free(alloced);/*/
}

static void ChangeTilemap(const struct TilemapCtrl *unkStruct, u16 *dest, u8 c, bool8 d)
{
    u16 i;
    u16 *alloced = Alloc(unkStruct->field_6 * 2 * unkStruct->field_7);
    CpuFill16(unkStruct->field_4, alloced, unkStruct->field_6 * 2 * unkStruct->field_7);
    if (unkStruct->field_6 != c)
    {
        if (!d)
        {
            for (i = 0; i < unkStruct->field_7; i++)
                CpuCopy16(&unkStruct->gfx[c + unkStruct->field_6 * i], &alloced[unkStruct->field_6 * i], (unkStruct->field_6 - c) * 2);
        }
        else
        {
            for (i = 0; i < unkStruct->field_7; i++)
                CpuCopy16(&unkStruct->gfx[unkStruct->field_6 * i], &alloced[c + unkStruct->field_6 * i], (unkStruct->field_6 - c) * 2);
        }
    }

    for (i = 0; i < unkStruct->field_7; i++)
        CpuCopy16(&alloced[unkStruct->field_6 * i], &dest[(unkStruct->field_9 + i) * 32 + unkStruct->field_8], unkStruct->field_6 * 2);

    Free(alloced);
}

static void HandlePowerAccTilemap(u16 a, s16 b)
{
    if (b > sBattleMoveTilemapCtrl.field_6)
        b = sBattleMoveTilemapCtrl.field_6;
    if (b == 0 || b == sBattleMoveTilemapCtrl.field_6)
    {
        //ChangeTilemap(&sBattleMoveTilemapCtrl, sMonSummaryScreen->bgTilemapBuffers[PSS_PAGE_BATTLE_MOVES][0], b, TRUE);
    }
    else
    {
        u8 taskId = FindTaskIdByFunc(Task_ShowPowerAccWindow);
        if (taskId == 0xFF)
            taskId = CreateTask(Task_ShowPowerAccWindow, 8);
        gTasks[taskId].data[0] = b;
        gTasks[taskId].data[1] = a;
    }
}

static void Task_ShowPowerAccWindow(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    data[1] += data[0];
    if (data[1] < 0)
    {
        data[1] = 0;
    }
    else if (data[1] > sBattleMoveTilemapCtrl.field_6)
    {
        data[1] = sBattleMoveTilemapCtrl.field_6;
    }
    //ChangeTilemap(&sBattleMoveTilemapCtrl, sMonSummaryScreen->bgTilemapBuffers[PSS_PAGE_BATTLE_MOVES][0], data[1], TRUE);
    if (data[1] <= 0 || data[1] >= sBattleMoveTilemapCtrl.field_6)
    {
        if (data[0] < 0)
        {
            if (sMonSummaryScreen->currPageIndex == 2)
                PutWindowTilemap(PSS_LABEL_WINDOW_MOVES_POWER_ACC);
        }
        else
        {
            if (!gSprites[sMonSummaryScreen->spriteIds[SPRITE_ARR_ID_STATUS]].invisible)
                PutWindowTilemap(PSS_LABEL_WINDOW_POKEMON_SKILLS_STATUS);
            PutWindowTilemap(PSS_LABEL_WINDOW_PORTRAIT_SPECIES);
        }
        ScheduleBgCopyTilemapToVram(0);
        DestroyTask(taskId);
    }
    ScheduleBgCopyTilemapToVram(1);
    ScheduleBgCopyTilemapToVram(2);
}

static void HandleAppealJamTilemap(u16 a, s16 b, u16 move)
{
    if (b > sContestMoveTilemapCtrl.field_6)
        b = sContestMoveTilemapCtrl.field_6;

    if (b == 0 || b == sContestMoveTilemapCtrl.field_6)
    {
        ChangeTilemap(&sContestMoveTilemapCtrl, sMonSummaryScreen->bgTilemapBuffers[PSS_PAGE_CONTEST_MOVES][0], b, TRUE);
    }
    else
    {
        u8 taskId = FindTaskIdByFunc(Task_ShowAppealJamWindow);
        if (taskId == 0xFF)
            taskId = CreateTask(Task_ShowAppealJamWindow, 8);
        gTasks[taskId].data[0] = b;
        gTasks[taskId].data[1] = a;
        gTasks[taskId].data[2] = move;
    }
}

static void Task_ShowAppealJamWindow(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    data[1] += data[0];
    if (data[1] < 0)
    {
        data[1] = 0;
    }
    else if (data[1] > sContestMoveTilemapCtrl.field_6)
    {
        data[1] = sContestMoveTilemapCtrl.field_6;
    }
    ChangeTilemap(&sContestMoveTilemapCtrl, sMonSummaryScreen->bgTilemapBuffers[PSS_PAGE_CONTEST_MOVES][0], data[1], TRUE);
    if (data[1] <= 0 || data[1] >= sContestMoveTilemapCtrl.field_6)
    {
        if (data[0] < 0)
        {
            if (sMonSummaryScreen->currPageIndex == 3 && FuncIsActiveTask(PssScrollRight) == 0)
                PutWindowTilemap(PSS_LABEL_WINDOW_MOVES_APPEAL_JAM);
            DrawContestMoveHearts(data[2]);
        }
        else
        {
            if (!gSprites[sMonSummaryScreen->spriteIds[SPRITE_ARR_ID_STATUS]].invisible)
            {
                PutWindowTilemap(PSS_LABEL_WINDOW_POKEMON_SKILLS_STATUS);
            }
            PutWindowTilemap(PSS_LABEL_WINDOW_PORTRAIT_SPECIES);
        }
        ScheduleBgCopyTilemapToVram(0);
        DestroyTask(taskId);
    }
    ScheduleBgCopyTilemapToVram(1);
    ScheduleBgCopyTilemapToVram(2);
}

static void HandleStatusTilemap(u16 a, s16 b)
{
    /*/if (b > sStatusTilemapCtrl1.field_6)
        b = sStatusTilemapCtrl1.field_6;
    if (b == 0 || b == sStatusTilemapCtrl1.field_6)
    {
        ChangeTilemap(&sStatusTilemapCtrl1, sMonSummaryScreen->bgTilemapBuffers[PSS_PAGE_INFO][0], b, FALSE);
        ChangeTilemap(&sStatusTilemapCtrl2, sMonSummaryScreen->bgTilemapBuffers[PSS_PAGE_INFO][0], b, FALSE);
    }
    else
    {
        u8 taskId = CreateTask(Task_ShowStatusWindow, 8);
        gTasks[taskId].data[0] = b;
        gTasks[taskId].data[1] = a;
    }/*/
}

static void Task_ShowStatusWindow(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    data[1] += data[0];
    if (data[1] < 0)
        data[1] = 0;
    else if (data[1] > sStatusTilemapCtrl1.field_6)
        data[1] = sStatusTilemapCtrl1.field_6;
    ChangeTilemap(&sStatusTilemapCtrl1, sMonSummaryScreen->bgTilemapBuffers[PSS_PAGE_INFO][0], data[1], FALSE);
    ChangeTilemap(&sStatusTilemapCtrl2, sMonSummaryScreen->bgTilemapBuffers[PSS_PAGE_INFO][0], data[1], FALSE);
    ScheduleBgCopyTilemapToVram(3);
    if (data[1] <= 0 || data[1] >= sStatusTilemapCtrl1.field_6)
    {
        if (data[0] < 0)
        {
            CreateSetStatusSprite();
            PutWindowTilemap(PSS_LABEL_WINDOW_POKEMON_SKILLS_STATUS);
            ScheduleBgCopyTilemapToVram(0);
        }
        DestroyTask(taskId);
    }
}

static void TilemapFiveMovesDisplay(u16 *dst, u16 palette, bool8 remove)
{
    u16 i, id;

    palette *= 0x1000;
    id = 0x56A;
    if (!remove)
    {
        for (i = 0; i < 20; i++)
        {
            dst[id + i] = gSummaryScreenWindow_Tilemap[i] + palette;
            dst[id + i + 0x20] = gSummaryScreenWindow_Tilemap[i] + palette;
            dst[id + i + 0x40] = gSummaryScreenWindow_Tilemap[i + 20] + palette;
        }
    }
    else // Remove
    {
        for (i = 0; i < 20; i++)
        {
            dst[id + i] = gSummaryScreenWindow_Tilemap[i + 20] + palette;
            dst[id + i + 0x20] = gSummaryScreenWindow_Tilemap[i + 40] + palette;
            dst[id + i + 0x40] = gSummaryScreenWindow_Tilemap[i + 40] + palette;
        }
    }
}

static void DrawPokerusCuredSymbol(struct Pokemon *mon) // This checks if the mon has been cured of pokerus
{
    /*/if (!CheckPartyPokerus(mon, 0) && CheckPartyHasHadPokerus(mon, 0)) // If yes it draws the cured symbol
    {
        sMonSummaryScreen->bgTilemapBuffers[PSS_PAGE_INFO][0][0x223] = 0x2C;
        sMonSummaryScreen->bgTilemapBuffers[PSS_PAGE_INFO][1][0x223] = 0x2C;
    }
    else
    {
        sMonSummaryScreen->bgTilemapBuffers[PSS_PAGE_INFO][0][0x223] = 0x81A;
        sMonSummaryScreen->bgTilemapBuffers[PSS_PAGE_INFO][1][0x223] = 0x81A;
    }
    ScheduleBgCopyTilemapToVram(3);/*/
}

static void SetDexNumberColor(bool8 isMonShiny)
{
    if (!isMonShiny)
        SetBgTilemapPalette(3, 1, 4, 8, 8, 0);
    else
        SetBgTilemapPalette(3, 1, 4, 8, 8, 2);
    ScheduleBgCopyTilemapToVram(3);
}

static void DrawExperienceProgressBar(struct Pokemon *unused)
{//asdf
    s64 numExpProgressBarTicks;
    struct PokeSummary *summary = &sMonSummaryScreen->summary;
    u16 *dst;
    u8 i;
    u16 formSpeciesId = GetFormSpeciesId(summary->species, summary->formId);
    u8 windowID = PSS_LABEL_WINDOW_POKEMON_SKILLS_STATS_LEFT;

    if (summary->level < MAX_LEVEL)
    {
        u32 expBetweenLevels = gExperienceTables[gBaseStats[formSpeciesId].growthRate][summary->level + 1] - gExperienceTables[gBaseStats[formSpeciesId].growthRate][summary->level];
        u32 expSinceLastLevel = summary->exp - gExperienceTables[gBaseStats[formSpeciesId].growthRate][summary->level];

        // Calculate the number of 1-pixel "ticks" to illuminate in the experience progress bar.
        // There are 8 tiles that make up the bar, and each tile has 8 "ticks". Hence, the numerator
        // is multiplied by 64.
        numExpProgressBarTicks = expSinceLastLevel * 64 / expBetweenLevels;
        if (numExpProgressBarTicks == 0 && expSinceLastLevel != 0)
            numExpProgressBarTicks = 1;
    }
    else
    {
        numExpProgressBarTicks = 0;
    }

    dst = &sMonSummaryScreen->bgTilemapBuffers[windowID][1][0x255];
    for (i = 0; i < 8; i++)
    {
        if (numExpProgressBarTicks > 7)
            dst[i] = 0x206A;
        else
            dst[i] = 0x2062 + (numExpProgressBarTicks % 8);
        numExpProgressBarTicks -= 8;
        if (numExpProgressBarTicks < 0)
            numExpProgressBarTicks = 0;
    }

    if (GetBgTilemapBuffer(1) == sMonSummaryScreen->bgTilemapBuffers[windowID][0])
        ScheduleBgCopyTilemapToVram(1);
    else
        ScheduleBgCopyTilemapToVram(2);
}

static void DrawContestMoveHearts(u16 move)
{
    u16 *tilemap = sMonSummaryScreen->bgTilemapBuffers[PSS_PAGE_CONTEST_MOVES][1];
    u8 i;

    if (move != MOVE_NONE)
    {
        u8 effectValue = gContestEffects[gContestMoves[move].effect].appeal;
        if (effectValue != 0xFF)
            effectValue /= 10;

        for (i = 0; i < 8; i++)
        {
            if (effectValue != 0xFF && i < effectValue)
                tilemap[(i / 4 * 32) + (i & 3) + 0x1E6] = 0x103A;
            else
                tilemap[(i / 4 * 32) + (i & 3) + 0x1E6] = 0x1039;
        }

        effectValue = gContestEffects[gContestMoves[move].effect].jam;

        if (effectValue != 0xFF)
            effectValue /= 10;

        for (i = 0; i < 8; i++)
        {
            if (effectValue != 0xFF && i < effectValue)
                tilemap[(i / 4 * 32) + (i & 3) + 0x226] = 0x103C;
            else
                tilemap[(i / 4 * 32) + (i & 3) + 0x226] = 0x103D;
        }
    }
}

static void LimitEggSummaryPageDisplay(void) // If the pokemon is an egg, limit the number of pages displayed to 1
{
    if (sMonSummaryScreen->summary.isEgg)
        ChangeBgX(3, 0x10000, 0);
    else
        ChangeBgX(3, 0, 0);
}

static void ResetWindows(void)
{
    u8 i;

    InitWindows(sNewSummaryTemplate);
    DeactivateAllTextPrinters();
    for (i = 0; i < PSS_LABEL_WINDOW_END; i++)
        FillWindowPixelBuffer(i, PIXEL_FILL(0));
    for (i = 0; i < ARRAY_COUNT(sMonSummaryScreen->windowIds); i++)
        sMonSummaryScreen->windowIds[i] = 0xFF;
}

static void PrintMonInfo(void)
{
    FillWindowPixelBuffer(PSS_LABEL_WINDOW_PORTRAIT_NICKNAME, PIXEL_FILL(0));
    ScheduleBgCopyTilemapToVram(0);
}

static u8 AddWindowFromTemplateList(const struct WindowTemplate *template, u8 templateId)
{
    u8 *windowIdPtr = &sMonSummaryScreen->windowIds[templateId];
    if (*windowIdPtr == 0xFF)
    {
        *windowIdPtr = AddWindow(&template[templateId]);
        FillWindowPixelBuffer(*windowIdPtr, PIXEL_FILL(0));
    }
    return *windowIdPtr;
}

static void PrintEggInfo(void)
{
    GetMonNickname(&sMonSummaryScreen->currentMon, gStringVar1);
    PrintTextOnWindow(PSS_LABEL_WINDOW_PORTRAIT_NICKNAME, gStringVar1, 0, 1, 0, 1);
    PutWindowTilemap(PSS_LABEL_WINDOW_PORTRAIT_NICKNAME);
    ClearWindowTilemap(PSS_LABEL_WINDOW_PORTRAIT_DEX_NUMBER);
    ClearWindowTilemap(PSS_LABEL_WINDOW_PORTRAIT_SPECIES);
}

static void PrintGenderSymbol(struct Pokemon *mon, u16 species)
{
    if (species != SPECIES_NIDORAN_M && species != SPECIES_NIDORAN_F)
    {
        switch (GetMonGender(mon))
        {
        case MON_MALE:
            PrintTextOnWindow(PSS_LABEL_WINDOW_PORTRAIT_SPECIES, gText_MaleSymbol, 57, 17, 0, 3);
            break;
        case MON_FEMALE:
            PrintTextOnWindow(PSS_LABEL_WINDOW_PORTRAIT_SPECIES, gText_FemaleSymbol, 57, 17, 0, 4);
            break;
        }
    }
}

static void PrintAOrBButtonIcon(u8 windowId, bool8 bButton, u32 x)
{
    // sSummaryBButtonBitmap - 0x80 = sSummaryAButtonBitmap
    BlitBitmapToWindow(windowId, sSummaryAButtonBitmap, x, 6, 8, 8);
}

static void PrintPageNamesAndStats(void)
{
    PrintTitile(PSS_PAGE_INFO, HELP_BAR_A_CANCEL);
    PrintMiddleRightPart(PSS_PAGE_INFO);
}

static void PutPageWindowTilemaps(u8 page)
{
    u8 i;
    switch (page)
    {
    case PSS_PAGE_INFO:
        PrintTitile(PSS_PAGE_INFO, HELP_BAR_A_CANCEL);
        PrintMiddleRightPart(PSS_PAGE_INFO);
        break;
    case PSS_PAGE_SKILLS:
        PrintTitile(PSS_PAGE_SKILLS, HELP_BAR_A_RESET_EVS);
        PrintMiddleRightPart(PSS_PAGE_SKILLS);
        break;
    case PSS_PAGE_BATTLE_MOVES:
        PrintTitile(PSS_PAGE_BATTLE_MOVES, HELP_BAR_A_INFO);
        PrintMiddleRightPart(PSS_PAGE_BATTLE_MOVES);
        break;
    case PSS_PAGE_CONTEST_MOVES:
        PrintTitile(PSS_PAGE_CONTEST_MOVES, HELP_BAR_A_INFO);
        PrintMiddleRightPart(PSS_PAGE_CONTEST_MOVES);
        break;
    }

    for (i = 0; i < ARRAY_COUNT(sMonSummaryScreen->windowIds); i++)
        PutWindowTilemap(sMonSummaryScreen->windowIds[i]);

    ScheduleBgCopyTilemapToVram(0);
}

static void ClearPageWindowTilemaps(u8 page)
{
    u8 i;

    switch (page)
    {
    case PSS_PAGE_INFO:
        if (InBattleFactory() == TRUE || InSlateportBattleTent() == TRUE)
            ClearWindowTilemap(PSS_LABEL_WINDOW_POKEMON_INFO_RENTAL);
        break;
    case PSS_PAGE_SKILLS:
        ClearWindowTilemap(PSS_LABEL_WINDOW_POKEMON_SKILLS_STATS_LEFT);
        break;
    case PSS_PAGE_BATTLE_MOVES:
        if (sMonSummaryScreen->mode == PSS_MODE_SELECT_MOVE)
        {
            if (sMonSummaryScreen->newMove != MOVE_NONE || sMonSummaryScreen->firstMoveIndex != MAX_MON_MOVES)
            {
                ClearWindowTilemap(PSS_LABEL_WINDOW_MOVES_POWER_ACC);
                gSprites[sMonSummaryScreen->splitIconSpriteId].invisible = TRUE;
            }
        }
        break;
    case PSS_PAGE_CONTEST_MOVES:
        if (sMonSummaryScreen->mode == PSS_MODE_SELECT_MOVE)
        {
            if (sMonSummaryScreen->newMove != MOVE_NONE || sMonSummaryScreen->firstMoveIndex != MAX_MON_MOVES)
                ClearWindowTilemap(PSS_LABEL_WINDOW_MOVES_APPEAL_JAM);
        }
        break;
    }

    for (i = 0; i < ARRAY_COUNT(sMonSummaryScreen->windowIds); i++)
        RemoveWindowByIndex(i);

    ScheduleBgCopyTilemapToVram(0);
}



static void RemoveWindowByIndex(u8 windowIndex)
{
    u8 *windowIdPtr = &sMonSummaryScreen->windowIds[windowIndex];
    if (*windowIdPtr != 0xFF)
    {
        ClearWindowTilemap(*windowIdPtr);
        RemoveWindow(*windowIdPtr);
        *windowIdPtr = 0xFF;
    }
}

static void PrintPageSpecificText(u8 pageIndex)
{
    u16 i;
    for (i = 0; i < ARRAY_COUNT(sMonSummaryScreen->windowIds); i++)
    {
        if (sMonSummaryScreen->windowIds[i] != 0xFF)
            FillWindowPixelBuffer(sMonSummaryScreen->windowIds[i], PIXEL_FILL(0));
    }
    sTextPrinterFunctions[pageIndex]();
}

static void CreateTextPrinterTask(u8 pageIndex)
{
    CreateTask(sTextPrinterTasks[pageIndex], 16);
}

static void PrintInfoPageText(void)
{
    PrintInfoPage_Midde();
}

static void Task_PrintInfoPage(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    switch (data[0])
    {
    case 1:
        DestroyTask(taskId);
        return;
    }
    data[0]++;
}

static void BufferNatureString(void)
{
    struct PokemonSummaryScreenData *sumStruct = sMonSummaryScreen;
    DynamicPlaceholderTextUtil_SetPlaceholderPtr(2, gNatureNamePointers[sumStruct->summary.nature]);
    DynamicPlaceholderTextUtil_SetPlaceholderPtr(5, gText_EmptyString5);
}

static void GetMetLevelString(u8 *output)
{
    u8 level = sMonSummaryScreen->summary.metLevel;
    if (level == 0)
        level = EGG_HATCH_LEVEL;
    ConvertIntToDecimalStringN(output, level, STR_CONV_MODE_LEFT_ALIGN, 3);
    DynamicPlaceholderTextUtil_SetPlaceholderPtr(3, output);
}

static bool8 DoesMonOTMatchOwner(void)
{
    struct PokeSummary *sum = &sMonSummaryScreen->summary;
    u32 trainerId;
    u8 gender;

    if (sMonSummaryScreen->monList.mons == gEnemyParty)
    {
        u8 multiID = GetMultiplayerId() ^ 1;
        trainerId = gLinkPlayers[multiID].trainerId & 0xFFFF;
        gender = gLinkPlayers[multiID].gender;
        StringCopy(gStringVar1, gLinkPlayers[multiID].name);
    }
    else
    {
        trainerId = GetPlayerIDAsU32() & 0xFFFF;
        gender = gSaveBlock2Ptr->playerGender;
        StringCopy(gStringVar1, gSaveBlock2Ptr->playerName);
    }

    if (gender != sum->OTGender || trainerId != (sum->OTID & 0xFFFF) || StringCompareWithoutExtCtrlCodes(gStringVar1, sum->OTName))
        return FALSE;
    else
        return TRUE;
}

static bool8 DidMonComeFromGBAGames(void)
{
    struct PokeSummary *sum = &sMonSummaryScreen->summary;
    if (sum->metGame > 0 && sum->metGame <= VERSION_LEAF_GREEN)
        return TRUE;
    return FALSE;
}

bool8 DidMonComeFromRSE(void)
{
    struct PokeSummary *sum = &sMonSummaryScreen->summary;
    if (sum->metGame > 0 && sum->metGame <= VERSION_EMERALD)
        return TRUE;
    return FALSE;
}

static bool8 IsInGamePartnerMon(void)
{
    if ((gBattleTypeFlags & BATTLE_TYPE_INGAME_PARTNER) && gMain.inBattle)
    {
        if (sMonSummaryScreen->curMonIndex == 1 || sMonSummaryScreen->curMonIndex == 4 || sMonSummaryScreen->curMonIndex == 5)
            return TRUE;
    }
    return FALSE;
}

static void PrintSkillsPageText(void)
{
    PrintStatPage_Bottom();
}

static void Task_PrintSkillsPage(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    switch (data[0])
    {
    case 1:
        PrintStatPage_Bottom();
        break;
    case 2:
        DestroyTask(taskId);
        return;
    }
    data[0]++;
}

static void BufferStat(u8 *dst, s8 natureMod, u32 stat, u32 strId, u32 n)
{
    static const u8 sTextNatureDown[] = _("{COLOR}{08}");
    static const u8 sTextNatureUp[] = _("{COLOR}{05}");
    static const u8 sTextNatureNeutral[] = _("{COLOR}{01}");
    u8 *txtPtr;

    if (natureMod == 0)
        txtPtr = StringCopy(dst, sTextNatureNeutral);
    else if (natureMod > 0)
        txtPtr = StringCopy(dst, sTextNatureUp);
    else
        txtPtr = StringCopy(dst, sTextNatureDown);

    ConvertIntToDecimalStringN(txtPtr, stat, STR_CONV_MODE_RIGHT_ALIGN, n);
    DynamicPlaceholderTextUtil_SetPlaceholderPtr(strId, dst);
}

static void PrintBattleMoves(void)
{
    PrintMoveNameAndPP(0);
    PrintMoveNameAndPP(1);
    PrintMoveNameAndPP(2);
    PrintMoveNameAndPP(3);

    if (sMonSummaryScreen->mode == PSS_MODE_SELECT_MOVE)
    {
        PrintNewMoveDetailsOrCancelText();
        if (sMonSummaryScreen->firstMoveIndex == MAX_MON_MOVES)
        {
            if (sMonSummaryScreen->newMove != MOVE_NONE)
                PrintMoveDetails(sMonSummaryScreen->newMove);
        }
        else
        {
            PrintMoveDetails(sMonSummaryScreen->summary.moves[sMonSummaryScreen->firstMoveIndex]);
        }
    }
}

static void Task_PrintBattleMoves(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    switch (data[0])
    {
    case 1:
        PrintMoveNameAndPP(0);
        break;
    case 2:
        PrintMoveNameAndPP(1);
        break;
    case 3:
        PrintMoveNameAndPP(2);
        break;
    case 4:
        PrintMoveNameAndPP(3);
        break;
    case 5:
        if (sMonSummaryScreen->mode == PSS_MODE_SELECT_MOVE)
            PrintNewMoveDetailsOrCancelText();
        break;
    case 6:
        if (sMonSummaryScreen->mode == PSS_MODE_SELECT_MOVE)
        {
            if (sMonSummaryScreen->firstMoveIndex == MAX_MON_MOVES)
                data[1] = sMonSummaryScreen->newMove;
            else
                data[1] = sMonSummaryScreen->summary.moves[sMonSummaryScreen->firstMoveIndex];
        }
        break;
    case 7:
        if (sMonSummaryScreen->mode == PSS_MODE_SELECT_MOVE)
        {
            if (sMonSummaryScreen->newMove != MOVE_NONE || sMonSummaryScreen->firstMoveIndex != MAX_MON_MOVES)
                PrintMoveDetails(data[1]);
        }
        break;
    case 8:
        DestroyTask(taskId);
        return;
    }
    data[0]++;
}

static void PrintMovePowerAndAccuracy(u16 moveIndex)
{
    u8 windowId = PSS_WINDOW_BOTTOM;
    const u8 *text;
    struct Pokemon *mon = &sMonSummaryScreen->currentMon;
    u8 movePower = getMoveBasePowerFromMon(mon, moveIndex);
    u8 moveAccuracy = getMoveAccuracyFromMon(mon, moveIndex);
    u8 PosX = 0;
    u8 PosY = 9;

    if (moveIndex != MOVE_NONE)
    {
        if (movePower < 2)
        {
            text = gText_ThreeDashes;
        }
        else
        {
            ConvertIntToDecimalStringN(gStringVar1, movePower, STR_CONV_MODE_RIGHT_ALIGN, 3);
            text = gStringVar1;
        }
        
        PrintNarrowTextOnWindow(windowId, gText_Power, PosX, PosY, 0, SUMMARY_FONT_COLOR_WHITE);
        PosX = PosX + 53;
        PrintNarrowTextOnWindow(windowId, text, PosX, PosY, 0, SUMMARY_FONT_COLOR_WHITE);

        if (moveAccuracy == 0)
        {
            text = gText_ThreeDashes;
        }
        else
        {
            ConvertIntToDecimalStringN(gStringVar1, moveAccuracy, STR_CONV_MODE_RIGHT_ALIGN, 3);
            text = gStringVar1;
        }

        PosX = 0;
        PosY = PosY + 16;
        PrintNarrowTextOnWindow(windowId, gText_Accuracy2, PosX, PosY, 0, SUMMARY_FONT_COLOR_WHITE);
        PosX = PosX + 53;
        PrintNarrowTextOnWindow(windowId, text, PosX, PosY, 0, SUMMARY_FONT_COLOR_WHITE);
    }
}

static void PrintContestMoves(void)
{
    PrintMoveNameAndPP(0);
    PrintMoveNameAndPP(1);
    PrintMoveNameAndPP(2);
    PrintMoveNameAndPP(3);

    PrintNewMoveDetailsOrCancelText();
    PrintContestMoveDescription(sMonSummaryScreen->firstMoveIndex);
}

static void Task_PrintContestMoves(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    switch (data[0])
    {
    case 1:
        PrintMoveNameAndPP(0);
        break;
    case 2:
        PrintMoveNameAndPP(1);
        break;
    case 3:
        PrintMoveNameAndPP(2);
        break;
    case 4:
        PrintMoveNameAndPP(3);
        break;
    case 5:
        PrintNewMoveDetailsOrCancelText();
        break;
    case 6:
        if (sMonSummaryScreen->newMove != MOVE_NONE || sMonSummaryScreen->firstMoveIndex != MAX_MON_MOVES)
            PrintContestMoveDescription(sMonSummaryScreen->firstMoveIndex);
        break;
    case 7:
        DestroyTask(taskId);
        return;
    }
    data[0]++;
}

static void PrintContestMoveDescription(u8 moveSlot)
{
    u16 move;

    if (moveSlot == MAX_MON_MOVES)
        move = sMonSummaryScreen->newMove;
    else
        move = sMonSummaryScreen->summary.moves[moveSlot];

    PrintMoveDetails(move);
}

static void PrintMoveDetails(u16 move)
{
    u8 windowId = PSS_WINDOW_BOTTOM;
    struct PokeSummary *summary = &sMonSummaryScreen->summary;
    struct Pokemon *mon = &sMonSummaryScreen->currentMon;
    u16 speciesId = GetFormSpeciesId(summary->species, summary->formId);
    u16 ability = RandomizePokemonAbility(GetAbilityBySpecies(sMonSummaryScreen->summary.species, sMonSummaryScreen->summary.abilityNum, sMonSummaryScreen->summary.formId), sMonSummaryScreen->summary.pid);
    u16 PosX = (9 * 8) + 14;
    u16 PosY = 9;

    FillWindowPixelBuffer(windowId, PIXEL_FILL(0));
    if (move != MOVE_NONE)
    {
        if (sMonSummaryScreen->currPageIndex == PSS_PAGE_BATTLE_MOVES)
        {
            ShowSplitIcon(GetBattleMoveSplitFromMon(move, mon));
            PrintMovePowerAndAccuracy(move);
            
            //Signature Move
            if(gSignatureMoveList[speciesId].move == move && gSignatureMoveList[speciesId].differentDescription)
                PrintSmallTextOnWindow(windowId, gSignatureMoveList[speciesId].description, PosX, PosY, 0, SUMMARY_FONT_COLOR_WHITE);
            else
                PrintNarrowTextOnWindow(windowId, gMoveDescriptionPointers[move - 1], PosX, PosY, 0, SUMMARY_FONT_COLOR_WHITE);
        }
        else
        {
            PrintNarrowTextOnWindow(windowId, gContestEffectDescriptionPointers[gContestMoves[move].effect], PosX, PosY, 0, SUMMARY_FONT_COLOR_WHITE);
        }
        PutWindowTilemap(windowId);
    }
    else
    {
        ClearWindowTilemap(windowId);
    }

    ScheduleBgCopyTilemapToVram(0);
}

static void PrintNewMoveDetailsOrCancelText(void)
{
    PrintMoveNameAndPP(4);
}

static void AddAndFillMoveNamesWindow(void)
{
    u8 windowId = AddWindowFromTemplateList(sPageMovesTemplate, PSS_DATA_WINDOW_MOVE_NAMES);
    FillWindowPixelRect(windowId, PIXEL_FILL(0), 0, 66, 72, 16);
    CopyWindowToVram(windowId, 2);
}

static void SwapMovesNamesPP(u8 moveIndex1, u8 moveIndex2)
{
    u8 windowId1 = AddWindowFromTemplateList(sPageMovesTemplate, PSS_DATA_WINDOW_MOVE_NAMES);
    u8 windowId2 = AddWindowFromTemplateList(sPageMovesTemplate, PSS_DATA_WINDOW_MOVE_PP);

    FillWindowPixelRect(windowId1, PIXEL_FILL(0), 0, moveIndex1 * 16, 72, 16);
    FillWindowPixelRect(windowId1, PIXEL_FILL(0), 0, moveIndex2 * 16, 72, 16);

    FillWindowPixelRect(windowId2, PIXEL_FILL(0), 0, moveIndex1 * 16, 48, 16);
    FillWindowPixelRect(windowId2, PIXEL_FILL(0), 0, moveIndex2 * 16, 48, 16);

    PrintMoveNameAndPP(moveIndex1);
    PrintMoveNameAndPP(moveIndex2);
}

static void PrintHMMovesCantBeForgotten(void)
{
    u8 windowId = AddWindowFromTemplateList(sPageMovesTemplate, PSS_DATA_WINDOW_MOVE_DESCRIPTION);
    FillWindowPixelBuffer(windowId, PIXEL_FILL(0));
    PrintTextOnWindow(windowId, gText_HMMovesCantBeForgotten2, 6, 1, 0, 0);
}

static void ResetSpriteIds(void)
{
    u8 i;

    for (i = 0; i < ARRAY_COUNT(sMonSummaryScreen->spriteIds); i++)
        sMonSummaryScreen->spriteIds[i] = 0xFF;
}

static void DestroySpriteInArray(u8 spriteArrayId)
{
    if (sMonSummaryScreen->spriteIds[spriteArrayId] != 0xFF)
    {
        DestroySprite(&gSprites[sMonSummaryScreen->spriteIds[spriteArrayId]]);
        sMonSummaryScreen->spriteIds[spriteArrayId] = 0xFF;
    }
}

static void SetSpriteInvisibility(u8 spriteArrayId, bool8 invisible)
{
    gSprites[sMonSummaryScreen->spriteIds[spriteArrayId]].invisible = invisible;
}

static void HidePageSpecificSprites(void)
{
    // Keeps Pok�mon, caught ball and status sprites visible.
    u8 i;

    for (i = SPRITE_ARR_ID_TYPE; i < ARRAY_COUNT(sMonSummaryScreen->spriteIds); i++)
    {
        if (sMonSummaryScreen->spriteIds[i] != 0xFF)
            SetSpriteInvisibility(i, TRUE);
    }
}

static void SetTypeIcons(void)
{
    switch (sMonSummaryScreen->currPageIndex)
    {
    case PSS_PAGE_INFO:
        SetMonTypeIcons();
        break;
    case PSS_PAGE_BATTLE_MOVES:
        SetMoveTypeIcons();
        SetNewMoveTypeIcon();
        break;
    case PSS_PAGE_CONTEST_MOVES:
        SetContestMoveTypeIcons();
        SetNewMoveTypeIcon();
        break;
    }
}

static void CreateMoveTypeIcons(void)
{
    u8 i;

    for (i = SPRITE_ARR_ID_TYPE; i < SPRITE_ARR_ID_TYPE + 5; i++)
    {
        if (sMonSummaryScreen->spriteIds[i] == 0xFF)
            sMonSummaryScreen->spriteIds[i] = CreateSprite(&gSpriteTemplate_MoveTypes, 0, 0, 2);

        SetSpriteInvisibility(i, TRUE);
    }
}

void SetTypeSpritePosAndPal(u8 typeId, u8 x, u8 y, u8 spriteArrayId) //HGSS_Ui
{
    struct Sprite *sprite = &gSprites[sMonSummaryScreen->spriteIds[spriteArrayId]];
    StartSpriteAnim(sprite, typeId);
    sprite->oam.paletteNum = sMoveTypeToOamPaletteNum[typeId];
    sprite->pos1.x = x + 16;
    sprite->pos1.y = y + 8;
    SetSpriteInvisibility(spriteArrayId, FALSE);
}

static void SetMonTypeIcons(void)
{
	//Pokemon Type
    struct PokeSummary *summary = &sMonSummaryScreen->summary;
    u16 formSpeciesId = GetFormSpeciesId(summary->species, summary->formId);
    u8 type1 = RandomizePokemonType(gBaseStats[formSpeciesId].type1, summary->pid, FALSE);
    u8 type2 = RandomizePokemonType(gBaseStats[formSpeciesId].type2, summary->pid, TRUE);

    if(FlagGet(FLAG_VANILLA_MODE)){
        type1 = RandomizePokemonType(gVanillaBaseStats[formSpeciesId].type1, summary->pid, FALSE);
        type2 = RandomizePokemonType(gVanillaBaseStats[formSpeciesId].type2, summary->pid, TRUE);
    }

    if (summary->isEgg)
    {
        SetTypeSpritePosAndPal(TYPE_MYSTERY, 120, 48, SPRITE_ARR_ID_TYPE);
        SetSpriteInvisibility(SPRITE_ARR_ID_TYPE + 1, TRUE);
    }
    else
    {
        SetTypeSpritePosAndPal(type1, 160, 49, SPRITE_ARR_ID_TYPE);
        if (type1 != type2)
        {
            SetTypeSpritePosAndPal(type2, 200, 49, SPRITE_ARR_ID_TYPE + 1);
            SetSpriteInvisibility(SPRITE_ARR_ID_TYPE + 1, FALSE);
        }
        else
        {
            SetSpriteInvisibility(SPRITE_ARR_ID_TYPE + 1, TRUE);
        }
    }
}

static void SetMoveTypeIcons(void)
{
    u8 i;
    struct PokeSummary *summary = &sMonSummaryScreen->summary;
    struct Pokemon *mon = &sMonSummaryScreen->currentMon;
    u16 species = sMonSummaryScreen->summary.species;
    u8  formID = sMonSummaryScreen->summary.formId;
    u16 speciesId = GetFormSpeciesId(species, formID);
    u16 ability = RandomizePokemonAbility(GetAbilityBySpecies(sMonSummaryScreen->summary.species, sMonSummaryScreen->summary.abilityNum, sMonSummaryScreen->summary.formId), sMonSummaryScreen->summary.pid);

    for (i = 0; i < MAX_MON_MOVES; i++)
    {
        u16 move = summary->moves[i];
        if (move != MOVE_NONE){
            if (move == MOVE_HIDDEN_POWER || move == MOVE_SECRET_POWER){
				u8 typeBits  = ((GetMonData(mon, MON_DATA_HP_IV) & 1) << 0)
                     | ((GetMonData(mon, MON_DATA_ATK_IV) & 1) << 1)
                     | ((GetMonData(mon, MON_DATA_DEF_IV) & 1) << 2)
                     | ((GetMonData(mon, MON_DATA_SPEED_IV) & 1) << 3)
                     | ((GetMonData(mon, MON_DATA_SPATK_IV) & 1) << 4)
                     | ((GetMonData(mon, MON_DATA_SPDEF_IV) & 1) << 5);

                u8 type = (15 * typeBits) / 63 + 1;
                if (type >= TYPE_MYSTERY)
                    type++;
                type |= 0xC0;
                SetTypeSpritePosAndPal(type & 0x3F, 85 + 8, 32 + (i * 16), i + SPRITE_ARR_ID_TYPE);
            }
            else {
                u8 type = getMoveType(move, speciesId, ability);
                SetTypeSpritePosAndPal(type, 85 + 8, 32 + (i * 16), i + SPRITE_ARR_ID_TYPE);
            }
        }
        else
            SetSpriteInvisibility(i + SPRITE_ARR_ID_TYPE, TRUE);
    }
}

static void SetContestMoveTypeIcons(void)
{
    u8 i;
    struct PokeSummary *summary = &sMonSummaryScreen->summary;
    for (i = 0; i < MAX_MON_MOVES; i++)
    {
        if (summary->moves[i] != MOVE_NONE)
            SetTypeSpritePosAndPal(NUMBER_OF_MON_TYPES + gContestMoves[summary->moves[i]].contestCategory, 85 + 8, 32 + (i * 16), i + SPRITE_ARR_ID_TYPE);
        else
            SetSpriteInvisibility(i + SPRITE_ARR_ID_TYPE, TRUE);
    }
}

static void SetNewMoveTypeIcon(void)
{
    struct Pokemon *mon = &sMonSummaryScreen->currentMon;
    u16 species = GetMonData(mon, MON_DATA_SPECIES);

    if (sMonSummaryScreen->newMove == MOVE_NONE)
    {
        SetSpriteInvisibility(SPRITE_ARR_ID_TYPE + 4, TRUE);
    }
    else
    {
        if (sMonSummaryScreen->currPageIndex == PSS_PAGE_BATTLE_MOVES)
            if (sMonSummaryScreen->newMove == MOVE_HIDDEN_POWER) {
                u8 typeBits  = ((GetMonData(mon, MON_DATA_HP_IV) & 1) << 0)
                     | ((GetMonData(mon, MON_DATA_ATK_IV) & 1) << 1)
                     | ((GetMonData(mon, MON_DATA_DEF_IV) & 1) << 2)
                     | ((GetMonData(mon, MON_DATA_SPEED_IV) & 1) << 3)
                     | ((GetMonData(mon, MON_DATA_SPATK_IV) & 1) << 4)
                     | ((GetMonData(mon, MON_DATA_SPDEF_IV) & 1) << 5);

                u8 type = (15 * typeBits) / 63 + 1;
                if (type >= TYPE_MYSTERY)
                    type++;
                type |= 0xC0;
                SetTypeSpritePosAndPal(type & 0x3F, 85 + 8, 96, SPRITE_ARR_ID_TYPE + 4);
            } else {
                SetTypeSpritePosAndPal(gBattleMoves[sMonSummaryScreen->newMove].type, 85 + 8, 96, SPRITE_ARR_ID_TYPE + 4);
            }
        else
            SetTypeSpritePosAndPal(NUMBER_OF_MON_TYPES + gContestMoves[sMonSummaryScreen->newMove].contestCategory, 85 + 8, 96, SPRITE_ARR_ID_TYPE + 4);
    }
}

static void SwapMovesTypeSprites(u8 moveIndex1, u8 moveIndex2)
{
    struct Sprite *sprite1 = &gSprites[sMonSummaryScreen->spriteIds[moveIndex1 + SPRITE_ARR_ID_TYPE]];
    struct Sprite *sprite2 = &gSprites[sMonSummaryScreen->spriteIds[moveIndex2 + SPRITE_ARR_ID_TYPE]];

    u8 temp = sprite1->animNum;
    sprite1->animNum = sprite2->animNum;
    sprite2->animNum = temp;

    temp = sprite1->oam.paletteNum;
    sprite1->oam.paletteNum = sprite2->oam.paletteNum;
    sprite2->oam.paletteNum = temp;

    sprite1->animBeginning = TRUE;
    sprite1->animEnded = FALSE;
    sprite2->animBeginning = TRUE;
    sprite2->animEnded = FALSE;
}
    
static u8 LoadMonGfxAndSprite(struct Pokemon *mon, s16 *state)
{
    const struct CompressedSpritePalette *pal;
    struct PokeSummary *summary = &sMonSummaryScreen->summary;
	u16 species = GetMonData(mon, MON_DATA_SPECIES2, 0);
	u8 formId = GetMonData(mon, MON_DATA_FORM_ID, 0);
    u16 formSpeciesId = GetFormSpeciesId(species, formId);

    switch (*state)
    {
    default:
        return CreateMonSprite(mon);
    case 0:
        if (gMain.inBattle)
        {
            HandleLoadSpecialPokePic(&gMonFrontPicTable[formSpeciesId], gMonSpritesGfxPtr->sprites[1], formSpeciesId, summary->pid);
        }
        else
        {
            if (gMonSpritesGfxPtr != NULL)
            {
                HandleLoadSpecialPokePic(&gMonFrontPicTable[formSpeciesId], gMonSpritesGfxPtr->sprites[1], formSpeciesId, summary->pid);
            }
            else
            {
                HandleLoadSpecialPokePic(&gMonFrontPicTable[formSpeciesId], sub_806F4F8(0, 1), formSpeciesId, summary->pid);
            }
        }
        (*state)++;
        return 0xFF;
    case 1:
        pal = GetMonSpritePalStructFromOtIdPersonality(formSpeciesId, summary->OTID, summary->pid);
        LoadCompressedSpritePalette(pal);
        SetMultiuseSpriteTemplateToPokemon(pal->tag, 1, formId);
        (*state)++;
        return 0xFF;
    }
}


static void PlayMonCry(void)
{
    struct PokeSummary *summary = &sMonSummaryScreen->summary;
    u16 formSpeciesId = GetFormSpeciesId(summary->species, summary->formId);
    if (!summary->isEgg)
    {
        if (ShouldPlayNormalMonCry(&sMonSummaryScreen->currentMon) == TRUE)
            PlayCry3(formSpeciesId, 0, 0);
        else
            PlayCry3(formSpeciesId, 0, 11);
    }
}

extern const struct PokedexEntry gPokedexEntries[];

static u8 CreateMonSprite(struct Pokemon *unused)
{
    struct PokeSummary *summary = &sMonSummaryScreen->summary;
    u8 spriteId = CreateSprite(&gMultiuseSpriteTemplate, 40, 80, 5);
    u16 paletteOffset;

    FreeSpriteOamMatrix(&gSprites[spriteId]);
    gSprites[spriteId].data[0] = summary->species2;
    gSprites[spriteId].data[2] = 0;
    gSprites[spriteId].callback = SpriteCB_Pokemon;
    gSprites[spriteId].oam.priority = 0;

    paletteOffset = 0x100 + (gSprites[spriteId].oam.paletteNum * 16);
    SetCustomMonPalette(&gPlttBufferUnfaded[paletteOffset], unused);
    SetCustomMonPalette(&gPlttBufferFaded[paletteOffset], unused);

    if (!IsMonSpriteNotFlipped(summary->species2))
        gSprites[spriteId].hFlip = TRUE;
    else
        gSprites[spriteId].hFlip = FALSE;

    return spriteId;
}


static void SpriteCB_Pokemon(struct Sprite *sprite)
{
    struct PokeSummary *summary = &sMonSummaryScreen->summary;

    if (!gPaletteFade.active && sprite->data[2] != 1)
    {
        sprite->data[1] = IsMonSpriteNotFlipped(sprite->data[0]);
        PlayMonCry();
        PokemonSummaryDoMonAnimation(sprite, sprite->data[0], summary->isEgg);
    }
}

void SummaryScreen_SetUnknownTaskId(u8 taskId)
{
    sUnknownTaskId = taskId;
}

void SummaryScreen_DestroyUnknownTask(void)
{
    if (sUnknownTaskId != 0xFF)
    {
        DestroyTask(sUnknownTaskId);
        sUnknownTaskId = 0xFF;
    }
}

// unused
static bool32 IsMonAnimationFinished(void)
{
    if (gSprites[sMonSummaryScreen->spriteIds[SPRITE_ARR_ID_MON]].callback == SpriteCallbackDummy)
        return FALSE;
    else
        return TRUE;
}

static void StopPokemonAnimations(void)  // A subtle effect, this function stops pokemon animations when leaving the PSS
{
    u16 i;
    u16 paletteIndex;

    gSprites[sMonSummaryScreen->spriteIds[SPRITE_ARR_ID_MON]].animPaused = TRUE;
    gSprites[sMonSummaryScreen->spriteIds[SPRITE_ARR_ID_MON]].callback = SpriteCallbackDummy;
    StopPokemonAnimationDelayTask();

    paletteIndex = (gSprites[sMonSummaryScreen->spriteIds[SPRITE_ARR_ID_MON]].oam.paletteNum * 16) | 0x100;

    for (i = 0; i < 16; i++)
    {
        u16 id = i + paletteIndex;
        gPlttBufferUnfaded[id] = gPlttBufferFaded[id];
    }
}

static void CreateMonMarkingsSprite(struct Pokemon *mon)
{
    /*/struct Sprite *sprite = CreateMonMarkingsSpriteWithPal(TAG_MON_MARKINGS, TAG_MON_MARKINGS, sSummaryMarkingsPalette);

    sMonSummaryScreen->markingsSprite = sprite;
    if (sprite != NULL)
    {
        StartSpriteAnim(sprite, GetMonData(mon, MON_DATA_MARKINGS));
        sMonSummaryScreen->markingsSprite->pos1.x = 60;
        sMonSummaryScreen->markingsSprite->pos1.y = 26;
        sMonSummaryScreen->markingsSprite->oam.priority = 1;
    }/*/
}

static void RemoveAndCreateMonMarkingsSprite(struct Pokemon *mon)
{
    DestroySprite(sMonSummaryScreen->markingsSprite);
    FreeSpriteTilesByTag(TAG_MON_MARKINGS);
    CreateMonMarkingsSprite(mon);
}

static void CreateCaughtBallSprite(struct Pokemon *mon)
{
    u8 ball = ItemIdToBallId(GetMonData(mon, MON_DATA_POKEBALL));
	u8 PosX = 7;
	u8 PosY = 5;
	
    LoadBallGfx(ball);
    sMonSummaryScreen->spriteIds[SPRITE_ARR_ID_BALL] = CreateSprite(&gBallSpriteTemplates[ball], (PosX*8), (PosY*8), 1);
    gSprites[sMonSummaryScreen->spriteIds[SPRITE_ARR_ID_BALL]].callback = SpriteCallbackDummy;
    gSprites[sMonSummaryScreen->spriteIds[SPRITE_ARR_ID_BALL]].oam.priority = 0;
}

static void CreateSetStatusSprite(void)
{
    u8 *spriteId = &sMonSummaryScreen->spriteIds[SPRITE_ARR_ID_STATUS];
    u8 statusAnim;
	u8 PosX = 8;
	u8 PosY = 13;
    if (*spriteId == 0xFF){
        *spriteId = CreateSprite(&sSpriteTemplate_StatusCondition, (PosX*8), (PosY*8), 1);
	}
    statusAnim = GetMonAilment(&sMonSummaryScreen->currentMon);
    if (statusAnim != 0)
    {
        StartSpriteAnim(&gSprites[*spriteId], statusAnim - 1);
        SetSpriteInvisibility(SPRITE_ARR_ID_STATUS, FALSE);
    }
    else
    {
        SetSpriteInvisibility(SPRITE_ARR_ID_STATUS, TRUE);
    }
}

static void CreateMoveSelectorSprites(u8 idArrayStart)
{
    u8 i;
    u8 *spriteIds = &sMonSummaryScreen->spriteIds[idArrayStart];

    if (sMonSummaryScreen->currPageIndex >= PSS_PAGE_BATTLE_MOVES)
    {
        u8 subpriority = 0;
        if (idArrayStart == SPRITE_ARR_ID_MOVE_SELECTOR1)
            subpriority = 1;

        for (i = 0; i < MOVE_SELECTOR_SPRITES_COUNT; i++)
        {
            spriteIds[i] = CreateSprite(&sMoveSelectorSpriteTemplate, i * 16 + 89, 40, subpriority);
            if (i == 0)
                StartSpriteAnim(&gSprites[spriteIds[i]], 4); // left
            else if (i == 9)
                StartSpriteAnim(&gSprites[spriteIds[i]], 5); // right, actually the same as left, but flipped
            else
                StartSpriteAnim(&gSprites[spriteIds[i]], 6); // middle

            gSprites[spriteIds[i]].callback = SpriteCb_MoveSelector;
            gSprites[spriteIds[i]].data[0] = idArrayStart;
            gSprites[spriteIds[i]].data[1] = 0;
        }
    }
}

static void SpriteCb_MoveSelector(struct Sprite *sprite)
{
    if (sprite->animNum > 3 && sprite->animNum < 7)
    {
        sprite->data[1] = (sprite->data[1] + 1) & 0x1F;
        if (sprite->data[1] > 24)
            sprite->invisible = TRUE;
        else
            sprite->invisible = FALSE;
    }
    else
    {
        sprite->data[1] = 0;
        sprite->invisible = FALSE;
    }

    if (sprite->data[0] == SPRITE_ARR_ID_MOVE_SELECTOR1)
        sprite->pos2.y = sMonSummaryScreen->firstMoveIndex * 16;
    else
        sprite->pos2.y = sMonSummaryScreen->secondMoveIndex * 16;
}

static void DestroyMoveSelectorSprites(u8 firstArrayId)
{
    u8 i;
    for (i = 0; i < MOVE_SELECTOR_SPRITES_COUNT; i++)
        DestroySpriteInArray(firstArrayId + i);
}

static void SetMainMoveSelectorColor(u8 which)
{
    u8 i;
    u8 *spriteIds = &sMonSummaryScreen->spriteIds[SPRITE_ARR_ID_MOVE_SELECTOR1];

    which *= 3;
    for (i = 0; i < MOVE_SELECTOR_SPRITES_COUNT; i++)
    {
        if (i == 0)
            StartSpriteAnim(&gSprites[spriteIds[i]], which + 4);
        else if (i == 9)
            StartSpriteAnim(&gSprites[spriteIds[i]], which + 5);
        else
            StartSpriteAnim(&gSprites[spriteIds[i]], which + 6);
    }
}

static void KeepMoveSelectorVisible(u8 firstSpriteId)
{
    u8 i;
    u8 *spriteIds = &sMonSummaryScreen->spriteIds[firstSpriteId];

    for (i = 0; i < MOVE_SELECTOR_SPRITES_COUNT; i++)
    {
        gSprites[spriteIds[i]].data[1] = 0;
        gSprites[spriteIds[i]].invisible = FALSE;
    }
}