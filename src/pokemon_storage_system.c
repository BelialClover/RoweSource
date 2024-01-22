#include "global.h"
#include "malloc.h"
#include "bg.h"
#include "data.h"
#include "decompress.h"
#include "dma3.h"
#include "dynamic_placeholder_text_util.h"
#include "event_data.h"
#include "field_screen_effect.h"
#include "field_weather.h"
#include "fldeff_misc.h"
#include "gpu_regs.h"
#include "graphics.h"
#include "international_string_util.h"
#include "item.h"
#include "item_icon.h"
#include "item_menu.h"
#include "mail.h"
#include "main.h"
#include "menu.h"
#include "mon_markings.h"
#include "naming_screen.h"
#include "overworld.h"
#include "palette.h"
#include "pc_screen_effect.h"
#include "pokedex.h"
#include "pokemon.h"
#include "pokemon_icon.h"
#include "pokemon_summary_screen.h"
#include "pokemon_storage_system.h"
#include "script.h"
#include "sound.h"
#include "string_util.h"
#include "strings.h"
#include "text.h"
#include "text_window.h"
#include "trig.h"
#include "walda_phrase.h"
#include "window.h"
#include "constants/items.h"
#include "constants/maps.h"
#include "constants/moves.h"
#include "constants/rgb.h"
#include "constants/songs.h"
#include "tx_pokemon_follower.h"
#include "constants/abilities.h"
#include "constants/hold_effects.h"
#include "printf.h"
#include "mgba.h"

struct WallpaperTable
{
    const u32 *tiles;
    const u32 *tileMap;
    const u16 *palettes;
};

struct PokemonStorageSystemFunc
{
    u8 (*func)(void);
    s8 unk4;
};

struct StorageAction
{
    const u8 *text;
    u8 format;
};

struct StorageMenu
{
    const u8 *text;
    int textId;
};

struct PSS_MenuStringPtrs
{
    const u8 *text;
    const u8 *desc;
};

struct UnkUtilData
{
    const u8 *unk_00;
    u8 *unk_04;
    u16 unk_08;
    u16 unk_0a;
    u16 newField;
    void (*unk_0c)(struct UnkUtilData *data);
};

struct UnkUtil
{
    struct UnkUtilData *unk_00;
    u8 unk_04;
    u8 unk_05;
};

struct ChooseBoxMenu
{
    struct Sprite *menuSprite;
    struct Sprite *menuSideSprites[4];
    u32 unused1[3];
    struct Sprite *arrowSprites[2];
    u8 unused2[0x214];
    u32 loadedPalette;
    u16 tileTag;
    u16 paletteTag;
    u8 curBox;
    u8 unused3;
    u8 subpriority;
};

struct ItemIcon
{
    struct Sprite *sprite;
    u8 *tiles;
    u16 palIndex;
    u8 area;
    u8 pos;
    u8 active;
};

struct PokemonStorageSystemData
{
    u8 state;
    u8 boxOption;
    u8 screenChangeType;
    bool8 isReshowingPSS;
    u8 taskId;
    struct UnkUtil unkUtil;
    struct UnkUtilData unkUtilData[8];
    u16 partyMenuTilemapBuffer[528 / 2];
    u16 partyMenuUnused1; // Never read
    u16 partyMenuY;
    u8 partyMenuUnused2; // Unused
    u8 partyMenuMoveTimer;
    u8 showPartyMenuState;
    u8 closeBoxFlashing;
    u8 closeBoxFlashTimer;
    bool8 closeBoxFlashState;
    s16 newCurrBoxId;
    u16 bg2_X;
    s16 scrollSpeed;
    u16 scrollTimer;
    u8 wallpaperOffset;
    u8 scrollUnused1; // Written to, but never read.
    u8 scrollToBoxIdUnused; // Written to, but never read.
    u16 scrollUnused2; // Written to, but never read.
    s16 scrollDirectionUnused; // Written to, but never read.
    u16 scrollUnused3; // Written to, but never read.
    u16 scrollUnused4; // Written to, but never read.
    u16 scrollUnused5; // Written to, but never read.
    u16 scrollUnused6; // Written to, but never read.
    u8 filler[22];
    u8 boxTitleTiles[1024];
    u8 boxTitleCycleId;
    u8 wallpaperLoadState; // Written to, but never read.
    u8 wallpaperLoadBoxId;
    s8 wallpaperLoadDir;
    u16 boxTitlePal[16];
    u16 boxTitlePalOffset;
    u16 boxTitleAltPalOffset;
    struct Sprite *curBoxTitleSprites[2];
    struct Sprite *nextBoxTitleSprites[2];
    struct Sprite *arrowSprites[2];
    u32 wallpaperPalBits;
    u8 filler2[80]; // Unused
    u16 unkUnused1; // Written to, but never read.
    s16 wallpaperSetId;
    s16 wallpaperId;
    u16 wallpaperTilemap[360];
    u8 wallpaperChangeState;
    u8 scrollState;
    u8 scrollToBoxId;
    s8 scrollDirection;
    u8 *wallpaperTiles;
    struct Sprite *movingMonSprite;
    struct Sprite *partySprites[PARTY_SIZE];
    struct Sprite *boxMonsSprites[IN_BOX_COUNT];
    struct Sprite **shiftMonSpritePtr;
    struct Sprite **releaseMonSpritePtr;
    u16 numIconsPerSpecies[40];
    u16 iconSpeciesList[40];
    u16 boxSpecies[IN_BOX_COUNT];
    u8 boxFormId[IN_BOX_COUNT];
    u32 boxPersonalities[IN_BOX_COUNT];
    u8 incomingBoxId;
    u8 shiftTimer;
    u8 numPartyToCompact;
    u16 iconScrollDistance;
    s16 iconScrollPos;
    s16 iconScrollSpeed;
    u16 iconScrollNumIncoming;
    u8 iconScrollCurColumn;
    s8 iconScrollDirection; // Unnecessary duplicate of scrollDirection
    u8 iconScrollState;
    u8 iconScrollToBoxId; // Unused duplicate of scrollToBoxId
    struct WindowTemplate menuWindow;
    struct StorageMenu menuItems[7];
    u8 menuItemsCount;
    u8 menuWidth;
    u8 menuUnusedField; // Written to, but never read.
    u16 menuWindowId;
    struct Sprite *cursorSprite;
    struct Sprite *cursorShadowSprite;
    s32 cursorNewX;
    s32 cursorNewY;
    u32 cursorSpeedX;
    u32 cursorSpeedY;
    s16 cursorTargetX;
    s16 cursorTargetY;
    u16 cursorMoveSteps;
    s8 cursorVerticalWrap;
    s8 cursorHorizontalWrap;
    u8 newCursorArea;
    u8 newCursorPosition;
    u8 cursorPrevHorizPos;
    u8 cursorFlipTimer;
    u8 cursorPalNums[2];
    const u32 *cursorMonPalette;
    u32 cursorMonPersonality;
    u16 cursorMonSpecies:11;
    u16 cursorMonFormId:5;
    u16 cursorMonItem;
    u16 field_CE8;
    bool8 setMosaic;
    u8 cursorMonMarkings;
    u8 cursorMonLevel;
    bool8 cursorMonIsEgg;
    u8 cursorMonNick[POKEMON_NAME_LENGTH + 1];
    u8 cursorMonNickText[36];
    u8 cursorMonSpeciesName[36];
    u8 cursorMonGenderLvlText[36];
    u8 cursorMonItemName[36];
    bool8 (*monPlaceChangeFunc)(void);
    u8 monPlaceChangeState;
    u8 shiftBoxId;
    struct Sprite *markingComboSprite;
    struct Sprite *waveformSprites[2];
    u16 *markingComboTilesPtr;
    struct PokemonMarkMenu markMenu;
    struct ChooseBoxMenu chooseBoxMenu;
    struct Pokemon movingMon;
    struct Pokemon tempMon;
    s8 canReleaseMon;
    u8 releaseStatusResolved;
    s8 releaseCheckBoxId;
    s8 releaseCheckBoxPos;
    s8 releaseBoxId;
    s8 releaseBoxPos;
    u16 releaseCheckState;
    u16 restrictedReleaseMonMoves;
    u16 restrictedMoveList[8];
    u8 summaryMaxPos;
    u8 summaryStartPos;
    u8 pokemonSummaryScreenMode;
    union
    {
        struct Pokemon *mon;
        struct BoxPokemon *box;
    } summaryMon;
    u8 messageText[40];
    u8 boxTitleText[40];
    u8 releaseMonName[POKEMON_NAME_LENGTH + 1];
    u8 itemName[20];
    u8 inBoxMovingMode;
    u16 multiMoveWindowId;
    struct ItemIcon itemIcons[3];
    u16 movingItem;
    u16 itemInfoWindowOffset;
    u8 iteunkUnused2; // Unused
    u16 displayMonPalOffset;
    u16 *displayMonTilePtr;
    struct Sprite *cursorMonSprite;
    u16 displayMonPalBuffer[0x40];
    u8 tileBuffer[0x800];
    u8 unusedBuffer[0x1800]; // Unused
    u8 itemIconBuffer[0x800];
    u8 wallpaperBgTilemapBuffer[0x1000];
    u8 displayMenuTilemapBuffer[0x800];
};

struct UnkSubStruct_2039D84
{
    s16 field_0;
    s16 field_2;
    u16 field_4;
    u16 field_6;
    s16 field_8;
    s16 field_A;
};

struct UnkStruct_2039D84
{
    struct UnkSubStruct_2039D84 field_0[2];
    const void *field_18;
    const void *field_1C;
    u16 field_20;
    u16 field_22;
    u16 field_24;
    u16 field_26;
    u16 field_28;
    u8 field_2A;
    u8 field_2B;
    u8 field_2C;
    u8 field_2D;
};

enum
{
    OPTION_WITHDRAW,
    OPTION_DEPOSIT,
    OPTION_MOVE_MONS,
    OPTION_MOVE_ITEMS,
    OPTION_EXIT,
};

// States for the outer switch in Task_PokeStorageMain
enum {
    MSTATE_HANDLE_INPUT,
    MSTATE_MOVE_CURSOR,
    MSTATE_SCROLL_BOX,
    MSTATE_WAIT_MSG,
    MSTATE_ERROR_LAST_PARTY_MON,
    MSTATE_ERROR_HAS_MAIL,
    MSTATE_WAIT_ERROR_MSG,
    MSTATE_MULTIMOVE_RUN,
    MSTATE_MULTIMOVE_RUN_CANCEL,
    MSTATE_MULTIMOVE_RUN_MOVED,
    MSTATE_SCROLL_BOX_ITEM,
    MSTATE_WAIT_ITEM_ANIM,
};

// IDs for the main functions for moving multiple Pokémon.
// Given as arguments to MultiMove_SetFunction
enum {
    MULTIMOVE_START,
    MULTIMOVE_CANCEL, // If only 1 Pokémon is grabbed
    MULTIMOVE_CHANGE_SELECTION,
    MULTIMOVE_GRAB_SELECTION,
    MULTIMOVE_MOVE_MONS,
    MULTIMOVE_PLACE_MONS,
};

enum {
    MOVE_MODE_NORMAL,
    MOVE_MODE_MULTIPLE_SELECTING,
    MOVE_MODE_MULTIPLE_MOVING,
};

enum
{
    PC_TEXT_EXIT_BOX,
    PC_TEXT_WHAT_YOU_DO,
    PC_TEXT_PICK_A_THEME,
    PC_TEXT_PICK_A_WALLPAPER,
    PC_TEXT_IS_SELECTED,
    PC_TEXT_JUMP_TO_WHICH_BOX,
    PC_TEXT_DEPOSIT_IN_WHICH_BOX,
    PC_TEXT_WAS_DEPOSITED,
    PC_TEXT_BOX_IS_FULL,
    PC_TEXT_RELEASE_POKE,
    PC_TEXT_WAS_RELEASED,
    PC_TEXT_BYE_BYE,
    PC_TEXT_MARK_POKE,
    PC_TEXT_LAST_POKE,
    PC_TEXT_PARTY_FULL,
    PC_TEXT_HOLDING_POKE,
    PC_TEXT_WHICH_ONE_WILL_TAKE,
    PC_TEXT_CANT_RELEASE_EGG,
    PC_TEXT_CONTINUE_BOX,
    PC_TEXT_CAME_BACK,
    PC_TEXT_WORRIED,
    PC_TEXT_SURPRISE,
    PC_TEXT_PLEASE_REMOVE_MAIL,
    PC_TEXT_IS_SELECTED2,
    PC_TEXT_GIVE_TO_MON,
    PC_TEXT_PLACED_IN_BAG,
    PC_TEXT_BAG_FULL,
    PC_TEXT_PUT_IN_BAG,
    PC_TEXT_ITEM_IS_HELD,
    PC_TEXT_CHANGED_TO_ITEM,
    PC_TEXT_CANT_STORE_MAIL,
};

enum
{
    PC_TEXT_FMT_NORMAL,
    PC_TEXT_FMT_MON_NAME_1,
    PC_TEXT_FMT_MON_NAME_2,
    PC_TEXT_FMT_MON_NAME_3,
    PC_TEXT_FMT_MON_NAME_4,
    PC_TEXT_FMT_MON_NAME_5,
    PC_TEXT_FMT_MON_NAME_6,
    PC_TEXT_FMT_ITEM_NAME,
};

enum
{
    SCREEN_CHANGE_EXIT_BOX,
    SCREEN_CHANGE_SUMMARY_SCREEN,
    SCREEN_CHANGE_NAME_BOX,
    SCREEN_CHANGE_ITEM_FROM_BAG,
};

enum
{
    MODE_PARTY,
    MODE_BOX,
    MODE_MOVE,
};

enum
{
    WALLPAPER_FOREST,
    WALLPAPER_CITY,
    WALLPAPER_DESERT,
    WALLPAPER_SAVANNA,
    WALLPAPER_CRAG,
    WALLPAPER_VOLCANO,
    WALLPAPER_SNOW,
    WALLPAPER_CAVE,
    WALLPAPER_BEACH,
    WALLPAPER_SEAFLOOR,
    WALLPAPER_RIVER,
    WALLPAPER_SKY,
    WALLPAPER_POLKADOT,
    WALLPAPER_POKECENTER,
    WALLPAPER_MACHINE,
    WALLPAPER_PLAIN,
    WALLPAPER_FRIENDS, // The one received as a gift from Walda's parents.
    WALLPAPER_COUNT
};

// Return IDs for input handlers
enum {
    INPUT_NONE,
    INPUT_MOVE_CURSOR,
    INPUT_2, // Unused
    INPUT_3, // Unused
    INPUT_CLOSE_BOX,
    INPUT_SHOW_PARTY,
    INPUT_HIDE_PARTY,
    INPUT_BOX_OPTIONS,
    INPUT_IN_MENU,
    INPUT_SCROLL_RIGHT,
    INPUT_SCROLL_LEFT,
    INPUT_DEPOSIT,
    INPUT_WITHDRAW,
    INPUT_MOVE_MON,
    INPUT_SHIFT_MON,
    INPUT_PLACE_MON,
    INPUT_TAKE_ITEM,
    INPUT_GIVE_ITEM,
    INPUT_SWITCH_ITEMS,
    INPUT_PRESSED_B,
    INPUT_MULTIMOVE_START,
    INPUT_MULTIMOVE_CHANGE_SELECTION,
    INPUT_MULTIMOVE_SINGLE,
    INPUT_MULTIMOVE_GRAB_SELECTION,
    INPUT_MULTIMOVE_UNABLE,
    INPUT_MULTIMOVE_MOVE_MONS,
    INPUT_MULTIMOVE_PLACE_MONS,
};

// IDs for menu selection items. See SetMenuText, HandleMenuInput, etc
enum {
    MENU_CANCEL,
    MENU_STORE,
    MENU_WITHDRAW,
    MENU_MOVE,
    MENU_SHIFT,
    MENU_PLACE,
    MENU_SUMMARY,
    MENU_RELEASE,
    MENU_MARK,
    MENU_JUMP,
    MENU_WALLPAPER,
    MENU_NAME,
    MENU_TAKE,
    MENU_GIVE,
    MENU_GIVE_2,
    MENU_SWITCH,
    MENU_BAG,
    MENU_INFO,
    MENU_SCENERY_1,
    MENU_SCENERY_2,
    MENU_SCENERY_3,
    MENU_ETCETERA,
    MENU_FRIENDS,
    MENU_FOREST,
    MENU_CITY,
    MENU_DESERT,
    MENU_SAVANNA,
    MENU_CRAG,
    MENU_VOLCANO,
    MENU_SNOW,
    MENU_CAVE,
    MENU_BEACH,
    MENU_SEAFLOOR,
    MENU_RIVER,
    MENU_SKY,
    MENU_POLKADOT,
    MENU_POKECENTER,
    MENU_MACHINE,
    MENU_SIMPLE,
};

enum
{
    FRIENDS_ZIGZAGOON,
    FRIENDS_SCREEN,
    FRIENDS_HORIZONTAL,
    FRIENDS_DIAGONAL,
    FRIENDS_BLOCK,
    FRIENDS_RIBBON,
    FRIENDS_POKECENTER2,
    FRIENDS_FRAME,
    FRIENDS_BLANK,
    FRIENDS_CIRCLES,
    FRIENDS_AZUMARILL,
    FRIENDS_PIKACHU,
    FRIENDS_LEGENDARY,
    FRIENDS_DUSCLOPS,
    FRIENDS_LUDICOLO,
    FRIENDS_WHISCASH,
    FRIENDS_WALLPAPERS_COUNT
};

enum
{
    CURSOR_AREA_IN_BOX,
    CURSOR_AREA_IN_PARTY,
    CURSOR_AREA_BOX,
    CURSOR_AREA_BUTTONS, // Party Pokemon and Close Box
};

#define TAG_PAL_WAVEFORM    0xDACA
#define TAG_PAL_DAC8        0xDAC8
#define TAG_PAL_DAC6        0xDAC6
#define TAG_PAL_DACE        0xDACE
#define TAG_PAL_DAC7        0xDAC7
#define TAG_PAL_DAC9        0xDAC9
#define TAG_PAL_DAC0        0xDAC0
#define TAG_PAL_DACB        0xDACB

#define TAG_TILE_WAVEFORM   0x5
#define TAG_TILE_10         0x10
#define TAG_TILE_2          0x2
#define TAG_TILE_D          0xD
#define TAG_TILE_A          0xA
#define TAG_TILE_3          0x3
#define TAG_TILE_4          0x4
#define TAG_TILE_12         0x12
#define TAG_TILE_7          0x7
#define TAG_TILE_0          0x0
#define TAG_TILE_1          0x1

// IWRAM bss
static u32 gUnknown_03000F78[98];

// EWRAM DATA
EWRAM_DATA static u8 sPreviousBoxOption = 0;
EWRAM_DATA static struct ChooseBoxMenu *gUnknown_02039D04 = NULL;
EWRAM_DATA static struct PokemonStorageSystemData *sStorage = NULL;
EWRAM_DATA static bool8 sInPartyMenu = 0;
EWRAM_DATA static u8 sCurrentBoxOption = 0;
EWRAM_DATA static u8 sDepositBoxId = 0;
EWRAM_DATA static u8 sWhichToReshow = 0;
EWRAM_DATA static u8 sLastUsedBox = 0;
EWRAM_DATA static u16 sMovingItemId = 0;
EWRAM_DATA static struct Pokemon gUnknown_02039D14 = {0};
EWRAM_DATA static s8 sBoxCursorArea = 0;
EWRAM_DATA static s8 sBoxCursorPosition = 0;
EWRAM_DATA static bool8 sIsMonBeingMoved = 0;
EWRAM_DATA static u8 sMovingMonOrigBoxId = 0;
EWRAM_DATA static u8 sMovingMonOrigBoxPos = 0;
EWRAM_DATA static bool8 sCanOnlyMove = 0;

// This file's functions.
static void CreatePCMenu(u8 whichMenu, s16 *windowIdPtr);
static void EnterPokeStorage(u8 boxOption);
static u8 GetCurrentBoxOption(void);
static u8 HandleInput(void);
static u8 sub_80CDC2C(void);
static u8 GetNumPartySpritesCompacting(void);
static void LoadWallpaperGfx(u8 boxId, s8 direction);
static void CreateIncomingBoxTitle(u8 boxId, s8 direction);
static void StartBoxScrollArrowsSlide(s8 direction);
static void SetCurrentBox(u8 boxId);
static void CreateInitBoxTask(u8 boxId);
static void sub_80C7958(u8 curBox);
static void sub_80CCAE0(void *arg0);
static void sub_80C7B14(void);
static void sub_80C7BB4(void);
static void ScrollBackground(void);
static void sub_80C7B80(void);
static void sub_80C7BE4(void);
static void UpdateCloseBoxButtonFlash(void);
static void sub_80CFDC4(void);
static void LoadSavedMovingMon(void);
static void SetSelectionAfterSummaryScreen(void);
static void GiveChosenBagItem(void);
static void SetUpHidePartyMenu(void);
static void DestroyAllPartyMonIcons(void);
static void sub_80D11CC(void);
static void LoadPSSMenuGfx(void);
static void LoadWaveformSpritePalette(void);
static void sub_80CDC18(void);
static void InitCursor(void);
static void InitCursorOnReopen(void);
static void InitPokeStorageBg0(void);
static void sub_80CEBDC(void);
static void SetScrollingBackground(void);
static void UpdateBoxToSendMons(void);
static void InitCursorItemIcon(void);
static void CreateItemIconSprites(void);
static void TryHideItemAtCursor(void);
static void ClearSavedCursorPos(void);
static void InitMonIconFields(void);
static void InitPalettesAndSprites(void);
static void AddMenu(void);
static void InitReleaseMon(void);
static void InitCanRelaseMonVars(void);
static void sub_80D01B8(void);
static void ReleaseMon(void);
static void RefreshCursorMonData(void);
static void LoadCursorMonSprite(void);
static void sub_80CA154(void);
static void sub_80CA1C4(void);
static void ReshowReleaseMon(void);
static void TrySetCursorFistAnim(void);
static void ClearBottomWindow(void);
static void InitSupplementalTilemaps(void);
static void sub_80D013C(void);
static void RefreshDisplayMon(void);
static void sub_80D1194(void);
static void PrintCursorMonInfo(void);
static void sub_80CA65C(void);
static void AddWallpaperSetsMenu(void);
static void CreateBoxScrollArrows(void);
static void InitMenu(void);
static void StopBoxScrollArrowsSlide(void);
static void sub_80CFC14(void);
static void sub_80CEB40(void);
static void CycleBoxTitleSprites(void);
static void sub_80D1818(void);
static void sub_80D19B4(u32 arg0);
static void sub_80CAA74(void);
static void PrintItemDescription(void);
static void sub_80CE760(void);
static void sub_80CDBA0(void);
static void sub_80CE7E8(void);
static void sub_80CFECC(void);
static void sub_80CA9EC(void);
static void FreePSSData(void);
static void AddBoxMenu(void);
static void CycleBoxTitleColor(void);
static void MoveMon(void);
static void PlaceMon(void);
static void UpdatePartySlotColors(void);
static void sub_80CE22C(void);
static void sub_80CDA68(void);
static void CompactPartySprites(void);
static void sub_80CA9C0(void);
static void SetUpDoShowPartyMenu(void);
static void StartDisplayMonMosaicEffect(void);
static void sub_80C7CF4(struct Sprite *sprite);
static void SpriteCB_HeldMon(struct Sprite *sprite);
static void SpriteCB_BoxMonIconScrollOut(struct Sprite *sprite);
static void sub_80CD210(struct Sprite *sprite);
static bool32 WaitForWallpaperGfxLoad(void);
static bool8 InitPSSWindows(void);
static bool8 ResetReleaseMonSpritePtr(void);
static bool8 TryHideReleaseMon(void);
static bool8 MultiMove_Init(void);
static bool8 IsInitBoxActive(void);
static bool8 sub_80D01E4(void);
static bool8 sub_80CDED4(void);
static bool8 sub_80CDF08(void);
static bool8 sub_80D184C(void);
static bool8 sub_80D18E4(void);
static bool8 DoShowPartyMenu(void);
static bool8 sub_80D1218(void);
static bool8 ScrollToBox(void);
static bool8 sub_80CD554(void);
static bool8 HidePartyMenu(void);
static bool8 IsActiveItemMoving(void);
static bool8 sub_80D0580(u8 arg0);
static bool8 sub_80D0BC0(void);
static bool8 sub_80CA2B8(void);
static bool8 DoWallpaperGfxChange(void);
static bool8 DoMonPlaceChange(void);
static bool8 sub_80D00A8(void);
static bool8 IsRemovingLastPartyMon(void);
static bool8 CanShiftMon(void);
static bool8 IsCursorOnCloseBox(void);
static bool8 IsCursorOnBox(void);
static bool8 IsCursorInBox(void);
static bool8 IsMonBeingMoved(void);
static bool8 TryStorePartyMonInBox(u8 boxId);
static void Task_InitPokeStorage(u8 taskId);
static void Cb_PlaceMon(u8 taskId);
static void Cb_ChangeScreen(u8 taskId);
static void Cb_ShowPSS(u8 taskId);
static void Task_OnBPressed(u8 taskId);
static void Task_HandleBoxOptions(u8 taskId);
static void Task_OnSelectedMon(u8 taskId);
static void Task_OnCloseBoxPressed(u8 taskId);
static void Task_HidePartyPokemon(u8 taskId);
static void Task_DepositMenu(u8 taskId);
static void Task_MoveMon(u8 taskId);
static void Cb_GiveMovingItemToMon(u8 taskId);
static void Cb_SwitchSelectedItem(u8 taskId);
static void Cb_TakeItemForMoving(u8 taskId);
static void Task_WithdrawMon(u8 taskId);
static void Task_ShiftMon(u8 taskId);
static void Cb_ShowPartyPokemon(u8 taskId);
static void Cb_ShowItemInfo(u8 taskId);
static void Cb_GiveItemFromBag(u8 taskId);
static void Cb_ItemToBag(u8 taskId);
static void Cb_TakeItemForMoving(u8 taskId);
static void Cb_ShowMarkMenu(u8 taskId);
static void Cb_ShowMonSummary(u8 taskId);
static void Task_ReleaseMon(u8 taskId);
static void Cb_ReshowPSS(u8 taskId);
static void Task_PokeStorageMain(u8 taskId);
static void Cb_JumpBox(u8 taskId);
static void Cb_HandleWallpapers(u8 taskId);
static void Cb_NameBox(u8 taskId);
static void Cb_PrintCantStoreMail(u8 taskId);
static void Cb_HandleMovingMonFromParty(u8 taskId);
static void SetUpScrollToBox(u8 boxId);
static void sub_80CFE54(u8 animNum);
static void SetMovingMonPriority(u8 priority);
static void InitMonPlaceChange(u8 arg0);
static void SetMonMarkings(u8 markings);
static void ShowYesNoWindow(s8 cursorPos);
static void sub_80CDBF8(u8 cursorBoxPosition);
static void MultiMove_SetFunction(u8 arg0);
static void AnimateBoxScrollArrows(bool8 arg0);
static void sub_80CA984(bool8 arg0);
static void CreatePartyMonsSprites(bool8 arg0);
static void PrintMessage(u8 id);
static s16 sub_80D00AC(void);
static s8 RunCanReleaseMon(void);
static u8 GetBoxCursorPosition(void);
static void Item_FromMonToMoving(u8 cursorArea, u8 cursorPos);
static void Item_GiveMovingToMon(u8 cursorArea, u8 cursorPos);
static void Item_TakeMons(u8 cursorArea, u8 cursorPos);
static void Item_SwitchMonsWithMoving(u8 cursorArea, u8 cursorPos);
static struct Sprite *sub_80CD2E8(u16 x, u16 y, u8 animId, u8 priority, u8 subpriority);
static void SetWallpaperForCurrentBox(u8 wallpaperId);
static void AddWallpapersMenu(u8 wallpaperSet);
static u16 GetMovingItem(void);
static void LoadCursorMonGfx(u16 species, u32 pid, u8 formId);
static void sub_80CA2D0(struct Sprite *sprite);
static void sub_80CCF64(struct Sprite *sprite);
static void SpriteCB_MovePartyMonToNextSlot(struct Sprite *sprite);
static void sub_80CCF30(struct Sprite *sprite);
static void MovePartySprites(s16 yDelta);
static void sub_80CAAA8(u8 arg0, bool8 isPartyMon);
static const u8 *GetMovingItemName(void);
static void SetMenuText(u8 textId);
static void sub_80D0D8C(u8 cursorArea, u8 cursorPos);
static void sub_80D0E50(u8 cursorArea, u8 cursorPos);
static void sub_80D0F38(u16 item);
static struct Sprite *CreateMonIconSprite(u16 species, u32 personality, s16 x, s16 y, u8 oamPriority, u8 subpriority, u8 formId);
static void DestroyBoxMonIcon(struct Sprite *sprite);
static void GetIncomingBoxMonData(u8 boxId);
static void MovePartySpriteToNextSlot(struct Sprite *sprite, u16 partyId);
static void Task_InitBox(u8 taskId);
static void InitBoxTitle(u8 boxId);
static s8 DetermineBoxScrollDirection(u8 boxId);
static void sub_80CCA3C(const void *tilemap, s8 direction, u8 arg2);
static s16 sub_80CD00C(const u8 *string);
static bool8 MonPlaceChange_Shift(void);
static bool8 MonPlaceChange_Move(void);
static bool8 MonPlaceChange_Place(void);
static bool8 sub_80CDEC4(void);
static bool8 sub_80CDEB4(void);
static void sub_80CD444(u8 cursorArea, u8 cursorPosition, u16 *x, u16 *y);
static void SetShiftedMonData(u8 boxId, u8 position);
static void SetMovedMonData(u8 boxId, u8 position);
static void SetPlacedMonData(u8 boxId, u8 position);
static void PurgeMonOrBoxMon(u8 boxId, u8 position, bool8 send);
static void SetCursorMonData(void *pokemon, u8 mode);
static bool32 AtLeastThreeUsableMons(void);
static u8 InBoxInput_Normal(void);
static u8 InBoxInput_MovingMultiple(void);
static u8 InBoxInput_GrabbingMultiple(void);
static s8 GetMenuItemTextId(u8 arg0);
static u8 SetSelectionMenuTexts(void);
static u8 sub_80D0BA4(void);
static bool8 SetMenuTexts_Mon(void);
static bool8 SetMenuTexts_Item(void);
static bool8 sub_80D024C(void);
static bool8 sub_80D0344(void);
static bool8 sub_80D03B0(void);
static bool8 sub_80D0420(void);
static bool8 sub_80D04A0(void);
static bool8 sub_80D04C8(void);
static void sub_80D07B0(u8 arg0, u8 arg1);
static void sub_80D0834(u8 arg0, u8 arg1);
static void sub_80D0B5C(void);
static void sub_80D062C(void);
static void sub_80D0884(u16 arg0, u16 arg1, u16 arg2);
static void sub_80D08CC(void);
static void sub_80D09A4(void);
static void sub_80D0A1C(void);
static void sub_80D0AAC(void);
static u8 sub_80D0894(void);
static void sub_80D0778(u8 arg0, u8 arg1, u8 arg2);
static void sub_80D0708(u8 arg0, u8 arg1, u8 arg2);
static void sub_80D06D0(u8 arg0, u8 arg1, u8 arg2);
static void sub_80D0740(u8 arg0, u8 arg1, u8 arg2);
static void sub_80D27AC(u8 id, u16 arg1, u16 arg2, u16 arg3, u16 arg4);
static void sub_80D27F4(u8 id, u8 arg1, s8 arg2);
static void TilemapUtil_SetMap(u8 id, u8 bg, const void *arg2, u16 arg3, u16 arg4);
static void TilemapUtil_SetPos(u8 id, u16 arg1, u16 arg2);
static void TilemapUtil_Init(u8 count);
static void sub_80D25F0(void);
static void sub_80D2918(u8 id);
static void sub_80D2960(u8 id);
static void sub_80D29F8(u8 id);
static void UnkUtil_Init(struct UnkUtil *arg0, struct UnkUtilData *arg1, u32 arg2);
static void sub_80D2AA4(void);
static void sub_80D2B88(struct UnkUtilData *unkStruct);
static void sub_80D2C1C(struct UnkUtilData *unkStruct);

void SetArceusFormPSS(struct BoxPokemon *boxMon);
u16 GetArceusFormPSS(struct BoxPokemon *boxMon);
u16 GetSilvallyFormPSS(struct BoxPokemon *boxMon);
void UpdateSpeciesSpritePSS(struct BoxPokemon *boxmon);

// static const rom data
static const struct PSS_MenuStringPtrs sMainMenuTexts[] =
{
    [OPTION_WITHDRAW]   = {gText_WithdrawPokemon, gText_WithdrawMonDescription},
    [OPTION_DEPOSIT]    = {gText_DepositPokemon,  gText_DepositMonDescription},
    [OPTION_MOVE_MONS]  = {gText_MovePokemon,     gText_MoveMonDescription},
    [OPTION_MOVE_ITEMS] = {gText_MoveItems,       gText_MoveItemsDescription},
    [OPTION_EXIT]       = {gText_SeeYa,           gText_SeeYaDescription},
};

static const struct WindowTemplate sMainMenusWindowTemplate_MainMenuTexts =
{
    .bg = 0,
    .tilemapLeft = 1,
    .tilemapTop = 1,
    .width = 17,
    .height = 10,
    .paletteNum = 15,
    .baseBlock = 0x1,
};

static const union AnimCmd sAnim_ChooseBoxMenu_TopLeft[] =
{
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_END
};

static const union AnimCmd sAnim_ChooseBoxMenu_BottomLeft[] =
{
    ANIMCMD_FRAME(4, 5),
    ANIMCMD_END
};

static const union AnimCmd sAnim_ChooseBoxMenu_TopRight[] =
{
    ANIMCMD_FRAME(6, 5),
    ANIMCMD_END
};

static const union AnimCmd sAnim_ChooseBoxMenu_BottomRight[] =
{
    ANIMCMD_FRAME(10, 5),
    ANIMCMD_END
};

static const union AnimCmd *const sAnims_ChooseBoxMenu[] =
{
    sAnim_ChooseBoxMenu_TopLeft,
    sAnim_ChooseBoxMenu_BottomLeft,
    sAnim_ChooseBoxMenu_TopRight,
    sAnim_ChooseBoxMenu_BottomRight
};

static const union AffineAnimCmd sAffineAnim_ChooseBoxMenu[] =
{
    AFFINEANIMCMD_FRAME(0xE0, 0xE0, 0, 0),
    AFFINEANIMCMD_END
};

static const union AffineAnimCmd *const sAffineAnims_ChooseBoxMenu[] =
{
    sAffineAnim_ChooseBoxMenu
};

static const u8 sBoxInfoTextColors[] = {TEXT_COLOR_RED, TEXT_DYNAMIC_COLOR_6, TEXT_DYNAMIC_COLOR_5};
static const u8 sText_OutOf30[] = _("/30");

static const u16 gBoxSelectionPopupPalette[] = INCBIN_U16("graphics/unknown/unknown_57173C.gbapal");
static const u8 gBoxSelectionPopupCenterTiles[] = INCBIN_U8("graphics/pokemon_storage/box_selection_popup_center.4bpp");
static const u8 gBoxSelectionPopupSidesTiles[] = INCBIN_U8("graphics/pokemon_storage/box_selection_popup_sides.4bpp");
static const u32 gPokemonStorageScrollingBGTileset[] = INCBIN_U32("graphics/pokemon_storage/scrolling_bg.4bpp.lz");
static const u32 gPokemonStorageScrollingBGTilemap[] = INCBIN_U32("graphics/pokemon_storage/scrolling_bg.bin.lz");
static const u32 sDisplayMenu_Pal[] = INCBIN_U32("graphics/unknown/unknown_572280.gbapal");
static const u32 sDisplayMenu_Tilemap[] = INCBIN_U32("graphics/unknown/unknown_5722A0.bin.lz");

static const u16 sPkmnData_Tilemap[] =
{
    0x0101, 0x0102, 0x0103, 0x0104, 0x0105, 0x0106, 0x0107, 0x0108, 0x0111, 0x0112, 0x0113, 0x0114, 0x0115, 0x0116, 0x0117, 0x0118,
    0x2101, 0x2102, 0x2103, 0x2104, 0x2105, 0x2106, 0x2107, 0x2108, 0x2111, 0x2112, 0x2113, 0x2114, 0x2115, 0x2116, 0x2117, 0x2118,
};

static const u16 gUnknown_085723DC[] = INCBIN_U16("graphics/unknown/unknown_5723DC.gbapal"); // Left-most part and Close Box.
static const u16 gUnknown_085723FC[] = INCBIN_U16("graphics/unknown/unknown_5723FC.gbapal");
static const u16 gUnknown_0857241C[] = INCBIN_U16("graphics/unknown/unknown_57241C.gbapal");
static const u16 gUnknown_0857243C[] = INCBIN_U16("graphics/unknown/unknown_57243C.gbapal");

static const u16 gUnknown_0857245C[] =
{
    0x014c, 0x014d, 0x014e, 0x014f, 0x0170, 0x0171, 0x0172, 0x0173, 0x0174, 0x015c, 0x015d, 0x015e, 0x015f, 0x0180, 0x0181, 0x0182,
    0x0183, 0x0184, 0x0175, 0x0176, 0x0177, 0x0178, 0x0179, 0x017a, 0x017b, 0x017c, 0x017d, 0x0185, 0x0186, 0x0187, 0x0188, 0x0189,
    0x018a, 0x018b, 0x018c, 0x018d
};
static const u16 gUnknown_085724A4[] =
{
    0x1140, 0x1141, 0x1141, 0x1142, 0x1150, 0x1151, 0x1151, 0x1152, 0x1160, 0x1161, 0x1161, 0x1162,
};
static const u16 gUnknown_085724BC[] =
{
    0x1143, 0x1144, 0x1144, 0x1145, 0x1153, 0x1154, 0x1154, 0x1155, 0x1163, 0x1164, 0x1164, 0x1165,
};

static const u16 gWaveformPalette[] = INCBIN_U16("graphics/pokemon_storage/waveform.gbapal");
static const u32 gWaveformTiles[] = INCBIN_U32("graphics/pokemon_storage/waveform.4bpp");
static const u32 gUnknown_085726B4[] = INCBIN_U32("graphics/unused/unknown_5726B4.gbapal");
static const u32 gUnknown_085726F4[] = INCBIN_U32("graphics/unknown/unknown_5726F4.gbapal");

static const struct WindowTemplate gUnknown_08572714[] =
{
    { // 0
        .bg = 1,
        .tilemapLeft = 0,
        .tilemapTop = 11,
        .width = 9,
        .height = 7,
        .paletteNum = 3,
        .baseBlock = 0xC0,
    },
    { // 1
        .bg = 0,
        .tilemapLeft = 11,
        .tilemapTop = 17,
        .width = 18,
        .height = 2,
        .paletteNum = 15,
        .baseBlock = 0x14,
    },
    { // 2
        .bg = 0,
        .tilemapLeft = 0,
        .tilemapTop = 13,
        .width = 21,
        .height = 7,
        .paletteNum = 15,
        .baseBlock = 0x14,
    },
    DUMMY_WIN_TEMPLATE
};

static const struct BgTemplate sBgTemplates[] =
{
    {
        .bg = 0,
        .charBaseIndex = 0,
        .mapBaseIndex = 29,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 0,
        .baseTile = 0
    },
    {
        .bg = 1,
        .charBaseIndex = 1,
        .mapBaseIndex = 30,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 1,
        .baseTile = 0x100
    },
    {
        .bg = 2,
        .charBaseIndex = 2,
        .mapBaseIndex = 27,
        .screenSize = 1,
        .paletteMode = 0,
        .priority = 2,
        .baseTile = 0
    },
    {
        .bg = 3,
        .charBaseIndex = 3,
        .mapBaseIndex = 31,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 3,
        .baseTile = 0
    },
};

static const struct SpritePalette gWaveformSpritePalette =
{
    gWaveformPalette, TAG_PAL_WAVEFORM
};

static const struct SpriteSheet gWaveformSpriteSheet =
{
    gWaveformTiles, sizeof(gWaveformTiles), TAG_TILE_WAVEFORM
};

static const struct OamData sOamData_857286C;
static const struct SpriteTemplate sSpriteTemplate_CursorMon =
{
    .tileTag = TAG_TILE_2,
    .paletteTag = TAG_PAL_DAC6,
    .oam = &sOamData_857286C,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};

static const struct StorageAction gPCStorageActionTexts[] =
{
    [PC_TEXT_EXIT_BOX] = {gText_ExitFromBox, PC_TEXT_FMT_NORMAL},
    [PC_TEXT_WHAT_YOU_DO] = {gText_WhatDoYouWantToDo, PC_TEXT_FMT_NORMAL},
    [PC_TEXT_PICK_A_THEME] = {gText_PleasePickATheme, PC_TEXT_FMT_NORMAL},
    [PC_TEXT_PICK_A_WALLPAPER] = {gText_PickTheWallpaper, PC_TEXT_FMT_NORMAL},
    [PC_TEXT_IS_SELECTED] = {gText_PkmnIsSelected, PC_TEXT_FMT_MON_NAME_1},
    [PC_TEXT_JUMP_TO_WHICH_BOX] = {gText_JumpToWhichBox, PC_TEXT_FMT_NORMAL},
    [PC_TEXT_DEPOSIT_IN_WHICH_BOX] = {gText_DepositInWhichBox, PC_TEXT_FMT_NORMAL},
    [PC_TEXT_WAS_DEPOSITED] = {gText_PkmnWasDeposited, PC_TEXT_FMT_MON_NAME_1},
    [PC_TEXT_BOX_IS_FULL] = {gText_BoxIsFull2, PC_TEXT_FMT_NORMAL},
    [PC_TEXT_RELEASE_POKE] = {gText_ReleaseThisPokemon, PC_TEXT_FMT_NORMAL},
    [PC_TEXT_WAS_RELEASED] = {gText_PkmnWasReleased, PC_TEXT_FMT_MON_NAME_4},
    [PC_TEXT_BYE_BYE] = {gText_ByeByePkmn, PC_TEXT_FMT_MON_NAME_6},
    [PC_TEXT_MARK_POKE] = {gText_MarkYourPkmn, PC_TEXT_FMT_NORMAL},
    [PC_TEXT_LAST_POKE] = {gText_ThatsYourLastPkmn, PC_TEXT_FMT_NORMAL},
    [PC_TEXT_PARTY_FULL] = {gText_YourPartysFull, PC_TEXT_FMT_NORMAL},
    [PC_TEXT_HOLDING_POKE] = {gText_YoureHoldingAPkmn, PC_TEXT_FMT_NORMAL},
    [PC_TEXT_WHICH_ONE_WILL_TAKE] = {gText_WhichOneWillYouTake, PC_TEXT_FMT_NORMAL},
    [PC_TEXT_CANT_RELEASE_EGG] = {gText_YouCantReleaseAnEgg, PC_TEXT_FMT_NORMAL},
    [PC_TEXT_CONTINUE_BOX] = {gText_ContinueBoxOperations, PC_TEXT_FMT_NORMAL},
    [PC_TEXT_CAME_BACK] = {gText_PkmnCameBack, PC_TEXT_FMT_MON_NAME_1},
    [PC_TEXT_WORRIED] = {gText_WasItWorriedAboutYou, PC_TEXT_FMT_NORMAL},
    [PC_TEXT_SURPRISE] = {gText_FourEllipsesExclamation, PC_TEXT_FMT_NORMAL},
    [PC_TEXT_PLEASE_REMOVE_MAIL] = {gText_PleaseRemoveTheMail, PC_TEXT_FMT_NORMAL},
    [PC_TEXT_IS_SELECTED2] = {gText_PkmnIsSelected, PC_TEXT_FMT_ITEM_NAME},
    [PC_TEXT_GIVE_TO_MON] = {gText_GiveToAPkmn, PC_TEXT_FMT_NORMAL},
    [PC_TEXT_PLACED_IN_BAG] = {gText_PlacedItemInBag, PC_TEXT_FMT_ITEM_NAME},
    [PC_TEXT_BAG_FULL] = {gText_BagIsFull2, PC_TEXT_FMT_NORMAL},
    [PC_TEXT_PUT_IN_BAG] = {gText_PutItemInBag, PC_TEXT_FMT_NORMAL},
    [PC_TEXT_ITEM_IS_HELD] = {gText_ItemIsNowHeld, PC_TEXT_FMT_ITEM_NAME},
    [PC_TEXT_CHANGED_TO_ITEM] = {gText_ChangedToNewItem, PC_TEXT_FMT_ITEM_NAME},
    [PC_TEXT_CANT_STORE_MAIL] = {gText_MailCantBeStored, PC_TEXT_FMT_NORMAL},
};

static const struct WindowTemplate sYesNoWindowTemplate =
{
    .bg = 0,
    .tilemapLeft = 24,
    .tilemapTop = 11,
    .width = 5,
    .height = 4,
    .paletteNum = 15,
    .baseBlock = 0x5C,
};

static const struct OamData sOamData_857286C =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = 0,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(64x64),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(64x64),
    .tileNum = 0,
    .priority = 0,
    .paletteNum = 0,
    .affineParam = 0
};

static const struct OamData sOamData_8572874 =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = 0,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(16x8),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(16x8),
    .tileNum = 0,
    .priority = 0,
    .paletteNum = 0,
    .affineParam = 0
};

static const union AnimCmd sSpriteAnim_857287C[] =
{
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_8572884[] =
{
    ANIMCMD_FRAME(2, 8),
    ANIMCMD_FRAME(4, 8),
    ANIMCMD_FRAME(6, 8),
    ANIMCMD_JUMP(0)
};

static const union AnimCmd sSpriteAnim_8572894[] =
{
    ANIMCMD_FRAME(8, 5),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_857289C[] =
{
    ANIMCMD_FRAME(10, 8),
    ANIMCMD_FRAME(4, 8),
    ANIMCMD_FRAME(12, 8),
    ANIMCMD_JUMP(0)
};

static const union AnimCmd *const sSpriteAnimTable_85728AC[] =
{
    sSpriteAnim_857287C,
    sSpriteAnim_8572884,
    sSpriteAnim_8572894,
    sSpriteAnim_857289C
};

static const struct SpriteTemplate sSpriteTemplate_Waveform =
{
    .tileTag = TAG_TILE_WAVEFORM,
    .paletteTag = TAG_PAL_WAVEFORM,
    .oam = &sOamData_8572874,
    .anims = sSpriteAnimTable_85728AC,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};

static const struct OamData sOamData_85728EC;
static const struct SpriteTemplate sSpriteTemplate_MonIcon =
{
    .tileTag = TAG_TILE_12,
    .paletteTag = TAG_PAL_DAC0,
    .oam = &sOamData_85728EC,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};

static const struct OamData sOamData_85728EC =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = 0,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(32x32),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(32x32),
    .tileNum = 0,
    .priority = 0,
    .paletteNum = 0,
    .affineParam = 0
};

static const union AffineAnimCmd gSpriteAffineAnim_85728F4[] =
{
    AFFINEANIMCMD_FRAME(-2, -2, 0, 120),
    AFFINEANIMCMD_END
};

static const union AffineAnimCmd gSpriteAffineAnim_8572904[] =
{
    AFFINEANIMCMD_FRAME(16, 16, 0, 0),
    AFFINEANIMCMD_FRAME(16, 16, 0, 15),
    AFFINEANIMCMD_END
};

static const union AffineAnimCmd *const gSpriteAffineAnimTable_857291C[] =
{
    gSpriteAffineAnim_85728F4,
    gSpriteAffineAnim_8572904
};

static const u16 gWallpaperPalettes_Forest[][16] =
{
    INCBIN_U16("graphics/pokemon_storage/forest_frame.gbapal"),
    INCBIN_U16("graphics/pokemon_storage/forest_bg.gbapal"),
};
static const u32 gWallpaperTiles_Forest[] = INCBIN_U32("graphics/pokemon_storage/forest.4bpp.lz");
static const u32 gWallpaperTilemap_Forest[] = INCBIN_U32("graphics/pokemon_storage/forest.bin.lz");

static const u16 gWallpaperPalettes_City[][16] =
{
    INCBIN_U16("graphics/pokemon_storage/city_frame.gbapal"),
    INCBIN_U16("graphics/pokemon_storage/city_bg.gbapal"),
};
static const u32 gWallpaperTiles_City[] = INCBIN_U32("graphics/pokemon_storage/city.4bpp.lz");
static const u32 gWallpaperTilemap_City[] = INCBIN_U32("graphics/pokemon_storage/city.bin.lz");

static const u16 gWallpaperPalettes_Desert[][16] =
{
    INCBIN_U16("graphics/pokemon_storage/desert_frame.gbapal"),
    INCBIN_U16("graphics/pokemon_storage/desert_bg.gbapal"),
};
static const u32 gWallpaperTiles_Desert[] = INCBIN_U32("graphics/pokemon_storage/desert.4bpp.lz");
static const u32 gWallpaperTilemap_Desert[] = INCBIN_U32("graphics/pokemon_storage/desert.bin.lz");

static const u16 gWallpaperPalettes_Savanna[][16] =
{
    INCBIN_U16("graphics/pokemon_storage/savanna_frame.gbapal"),
    INCBIN_U16("graphics/pokemon_storage/savanna_bg.gbapal"),
};
static const u32 gWallpaperTiles_Savanna[] = INCBIN_U32("graphics/pokemon_storage/savanna.4bpp.lz");
static const u32 gWallpaperTilemap_Savanna[] = INCBIN_U32("graphics/pokemon_storage/savanna.bin.lz");

static const u16 gWallpaperPalettes_Crag[][16] =
{
    INCBIN_U16("graphics/pokemon_storage/crag_frame.gbapal"),
    INCBIN_U16("graphics/pokemon_storage/crag_bg.gbapal"),
};
static const u32 gWallpaperTiles_Crag[] = INCBIN_U32("graphics/pokemon_storage/crag.4bpp.lz");
static const u32 gWallpaperTilemap_Crag[] = INCBIN_U32("graphics/pokemon_storage/crag.bin.lz");

static const u16 gWallpaperPalettes_Volcano[][16] =
{
    INCBIN_U16("graphics/pokemon_storage/volcano_frame.gbapal"),
    INCBIN_U16("graphics/pokemon_storage/volcano_bg.gbapal"),
};
static const u32 gWallpaperTiles_Volcano[] = INCBIN_U32("graphics/pokemon_storage/volcano.4bpp.lz");
static const u32 gWallpaperTilemap_Volcano[] = INCBIN_U32("graphics/pokemon_storage/volcano.bin.lz");

static const u16 gWallpaperPalettes_Snow[][16] =
{
    INCBIN_U16("graphics/pokemon_storage/snow_frame.gbapal"),
    INCBIN_U16("graphics/pokemon_storage/snow_bg.gbapal"),
};
static const u32 gWallpaperTiles_Snow[] = INCBIN_U32("graphics/pokemon_storage/snow.4bpp.lz");
static const u32 gWallpaperTilemap_Snow[] = INCBIN_U32("graphics/pokemon_storage/snow.bin.lz");

static const u16 gWallpaperPalettes_Cave[][16] =
{
    INCBIN_U16("graphics/pokemon_storage/cave_frame.gbapal"),
    INCBIN_U16("graphics/pokemon_storage/cave_bg.gbapal"),
};
static const u32 gWallpaperTiles_Cave[] = INCBIN_U32("graphics/pokemon_storage/cave.4bpp.lz");
static const u32 gWallpaperTilemap_Cave[] = INCBIN_U32("graphics/pokemon_storage/cave.bin.lz");

static const u16 gWallpaperPalettes_Beach[][16] =
{
    INCBIN_U16("graphics/pokemon_storage/beach_frame.gbapal"),
    INCBIN_U16("graphics/pokemon_storage/beach_bg.gbapal"),
};
static const u32 gWallpaperTiles_Beach[] = INCBIN_U32("graphics/pokemon_storage/beach.4bpp.lz");
static const u32 gWallpaperTilemap_Beach[] = INCBIN_U32("graphics/pokemon_storage/beach.bin.lz");

static const u16 gWallpaperPalettes_Seafloor[][16] =
{
    INCBIN_U16("graphics/pokemon_storage/seafloor_frame.gbapal"),
    INCBIN_U16("graphics/pokemon_storage/seafloor_bg.gbapal"),
};
static const u32 gWallpaperTiles_Seafloor[] = INCBIN_U32("graphics/pokemon_storage/seafloor.4bpp.lz");
static const u32 gWallpaperTilemap_Seafloor[] = INCBIN_U32("graphics/pokemon_storage/seafloor.bin.lz");

static const u16 gWallpaperPalettes_River[][16] =
{
    INCBIN_U16("graphics/pokemon_storage/river_frame.gbapal"),
    INCBIN_U16("graphics/pokemon_storage/river_bg.gbapal"),
};
static const u32 gWallpaperTiles_River[] = INCBIN_U32("graphics/pokemon_storage/river.4bpp.lz");
static const u32 gWallpaperTilemap_River[] = INCBIN_U32("graphics/pokemon_storage/river.bin.lz");
static const u16 gWallpaperPalettes_Sky[][16] =
{
    INCBIN_U16("graphics/pokemon_storage/sky_frame.gbapal"),
    INCBIN_U16("graphics/pokemon_storage/sky_bg.gbapal"),
};
static const u32 gWallpaperTiles_Sky[] = INCBIN_U32("graphics/pokemon_storage/sky.4bpp.lz");
static const u32 gWallpaperTilemap_Sky[] = INCBIN_U32("graphics/pokemon_storage/sky.bin.lz");

static const u16 gWallpaperPalettes_PolkaDot[][16] =
{
    INCBIN_U16("graphics/pokemon_storage/polkadot_frame.gbapal"),
    INCBIN_U16("graphics/pokemon_storage/polkadot_bg.gbapal"),
};
static const u32 gWallpaperTiles_PolkaDot[] = INCBIN_U32("graphics/pokemon_storage/polkadot.4bpp.lz");
static const u32 gWallpaperTilemap_PolkaDot[] = INCBIN_U32("graphics/pokemon_storage/polkadot.bin.lz");

static const u16 gWallpaperPalettes_Pokecenter[][16] =
{
    INCBIN_U16("graphics/pokemon_storage/pokecenter_frame.gbapal"),
    INCBIN_U16("graphics/pokemon_storage/pokecenter_bg.gbapal"),
};
static const u32 gWallpaperTiles_Pokecenter[] = INCBIN_U32("graphics/pokemon_storage/pokecenter.4bpp.lz");
static const u32 gWallpaperTilemap_Pokecenter[] = INCBIN_U32("graphics/pokemon_storage/pokecenter.bin.lz");

static const u16 gWallpaperPalettes_Machine[][16] =
{
    INCBIN_U16("graphics/pokemon_storage/machine_frame.gbapal"),
    INCBIN_U16("graphics/pokemon_storage/machine_bg.gbapal"),
};
static const u32 gWallpaperTiles_Machine[] = INCBIN_U32("graphics/pokemon_storage/machine.4bpp.lz");
static const u32 gWallpaperTilemap_Machine[] = INCBIN_U32("graphics/pokemon_storage/machine.bin.lz");

static const u16 gWallpaperPalettes_Plain[][16] =
{
    INCBIN_U16("graphics/pokemon_storage/plain_frame.gbapal"),
    INCBIN_U16("graphics/pokemon_storage/plain_bg.gbapal"),
};
static const u32 gWallpaperTiles_Plain[] = INCBIN_U32("graphics/pokemon_storage/plain.4bpp.lz");
static const u32 gWallpaperTilemap_Plain[] = INCBIN_U32("graphics/pokemon_storage/plain.bin.lz");

// 12x18 tilemap
static const u32 gUnknown_085773C4[] = INCBIN_U32("graphics/unused/tilemap_5773C4.bin");

static const u16 gUnknown_08577574[][2] =
{
    {0x1CE7, 0x7FFF},
    {0x1CE7, 0x7FFF},
    {0x1CE7, 0x7FFF},
    {0x1CE7, 0x7FFF},
    {0x1CE7, 0x7FFF},
    {0x1CE7, 0x7FFF},
    {0x1CE7, 0x7FFF},
    {0x1CE7, 0x7FFF},
    {0x1CE7, 0x7FFF},
    {0x1CE7, 0x7FFF},
    {0x1CE7, 0x7FFF},
    {0x1CE7, 0x7FFF},
    {0x1CE7, 0x7FFF},
    {0x1CE7, 0x7FFF},
    {0x1CE7, 0x7FFF},
    {0x1CE7, 0x7FFF},
    {0x1CE7, 0x7FFF}
};

#define WALLPAPER_ENTRY(name) {gWallpaperTiles_##name, gWallpaperTilemap_##name, gWallpaperPalettes_##name[0]}

static const struct WallpaperTable gWallpaperTable[] =
{
    [WALLPAPER_FOREST] = WALLPAPER_ENTRY(Forest),
    [WALLPAPER_CITY] = WALLPAPER_ENTRY(City),
    [WALLPAPER_DESERT] = WALLPAPER_ENTRY(Desert),
    [WALLPAPER_SAVANNA] = WALLPAPER_ENTRY(Savanna),
    [WALLPAPER_CRAG] = WALLPAPER_ENTRY(Crag),
    [WALLPAPER_VOLCANO] = WALLPAPER_ENTRY(Volcano),
    [WALLPAPER_SNOW] = WALLPAPER_ENTRY(Snow),
    [WALLPAPER_CAVE] = WALLPAPER_ENTRY(Cave),
    [WALLPAPER_BEACH] = WALLPAPER_ENTRY(Beach),
    [WALLPAPER_SEAFLOOR] = WALLPAPER_ENTRY(Seafloor),
    [WALLPAPER_RIVER] = WALLPAPER_ENTRY(River),
    [WALLPAPER_SKY] = WALLPAPER_ENTRY(Sky),
    [WALLPAPER_POLKADOT] = WALLPAPER_ENTRY(PolkaDot),
    [WALLPAPER_POKECENTER] = WALLPAPER_ENTRY(Pokecenter),
    [WALLPAPER_MACHINE] = WALLPAPER_ENTRY(Machine),
    [WALLPAPER_PLAIN] = WALLPAPER_ENTRY(Plain),
};

static const u8 gPCGfx_Arrow[] = INCBIN_U8("graphics/pokemon_storage/arrow.4bpp");

static const u16 gWallpaperPalettes_Zigzagoon[][16] =
{
    INCBIN_U16("graphics/pokemon_storage/friends_frame1.gbapal"),
    INCBIN_U16("graphics/pokemon_storage/zigzagoon_bg.gbapal"),
};
static const u32 gWallpaperTiles_Zigzagoon[] = INCBIN_U32("graphics/pokemon_storage/zigzagoon.4bpp.lz");
static const u32 gWallpaperTilemap_Zigzagoon[] = INCBIN_U32("graphics/pokemon_storage/zigzagoon.bin.lz");

static const u16 gWallpaperPalettes_Screen[][16] =
{
    INCBIN_U16("graphics/pokemon_storage/friends_frame1.gbapal"),
    INCBIN_U16("graphics/pokemon_storage/screen_bg.gbapal"),
};
static const u32 gWallpaperTiles_Screen[] = INCBIN_U32("graphics/pokemon_storage/screen.4bpp.lz");
static const u32 gWallpaperTilemap_Screen[] = INCBIN_U32("graphics/pokemon_storage/screen.bin.lz");

static const u16 gWallpaperPalettes_Diagonal[][16] =
{
    INCBIN_U16("graphics/pokemon_storage/friends_frame1.gbapal"),
    INCBIN_U16("graphics/pokemon_storage/diagonal_bg.gbapal"),
};
static const u32 gWallpaperTiles_Diagonal[] = INCBIN_U32("graphics/pokemon_storage/diagonal.4bpp.lz");
static const u32 gWallpaperTilemap_Diagonal[] = INCBIN_U32("graphics/pokemon_storage/diagonal.bin.lz");

static const u16 gWallpaperPalettes_Block[][16] =
{
    INCBIN_U16("graphics/pokemon_storage/block_bg.gbapal"),
    INCBIN_U16("graphics/pokemon_storage/block_bg.gbapal"),
};
static const u32 gWallpaperTiles_Block[] = INCBIN_U32("graphics/pokemon_storage/block.4bpp.lz");
static const u32 gWallpaperTilemap_Block[] = INCBIN_U32("graphics/pokemon_storage/block.bin.lz");

static const u16 gWallpaperPalettes_Pokecenter2[][16] =
{
    INCBIN_U16("graphics/pokemon_storage/pokecenter2_bg.gbapal"),
    INCBIN_U16("graphics/pokemon_storage/pokecenter2_bg.gbapal"),
};
static const u32 gWallpaperTiles_Pokecenter2[] = INCBIN_U32("graphics/pokemon_storage/pokecenter2.4bpp.lz");
static const u32 gWallpaperTilemap_Pokecenter2[] = INCBIN_U32("graphics/pokemon_storage/pokecenter2.bin.lz");

static const u16 gWallpaperPalettes_Frame[][16] =
{
    INCBIN_U16("graphics/pokemon_storage/frame_bg.gbapal"),
    INCBIN_U16("graphics/pokemon_storage/frame_bg.gbapal"),
};
static const u32 gWallpaperTiles_Frame[] = INCBIN_U32("graphics/pokemon_storage/frame.4bpp.lz");
static const u32 gWallpaperTilemap_Frame[] = INCBIN_U32("graphics/pokemon_storage/frame.bin.lz");

static const u16 gWallpaperPalettes_Blank[][16] =
{
    INCBIN_U16("graphics/pokemon_storage/friends_frame1.gbapal"),
    INCBIN_U16("graphics/pokemon_storage/zigzagoon_bg.gbapal"),
};
static const u32 gWallpaperTiles_Blank[] = INCBIN_U32("graphics/pokemon_storage/blank.4bpp.lz");
static const u32 gWallpaperTilemap_Blank[] = INCBIN_U32("graphics/pokemon_storage/blank.bin.lz");

static const u16 gWallpaperPalettes_Circles[][16] =
{
    INCBIN_U16("graphics/pokemon_storage/friends_frame2.gbapal"),
    INCBIN_U16("graphics/pokemon_storage/circles_bg.gbapal"),
};
static const u32 gWallpaperTiles_Circles[] = INCBIN_U32("graphics/pokemon_storage/circles.4bpp.lz");
static const u32 gWallpaperTilemap_Circles[] = INCBIN_U32("graphics/pokemon_storage/circles.bin.lz");

static const u16 gWallpaperPalettes_Azumarill[][16] =
{
    INCBIN_U16("graphics/pokemon_storage/friends_frame2.gbapal"),
    INCBIN_U16("graphics/pokemon_storage/azumarill_bg.gbapal"),
};
static const u32 gWallpaperTiles_Azumarill[] = INCBIN_U32("graphics/pokemon_storage/azumarill.4bpp.lz");
static const u32 gWallpaperTilemap_Azumarill[] = INCBIN_U32("graphics/pokemon_storage/azumarill.bin.lz");

static const u16 gWallpaperPalettes_Pikachu[][16] =
{
    INCBIN_U16("graphics/pokemon_storage/friends_frame2.gbapal"),
    INCBIN_U16("graphics/pokemon_storage/pikachu_bg.gbapal"),
};
static const u32 gWallpaperTiles_Pikachu[] = INCBIN_U32("graphics/pokemon_storage/pikachu.4bpp.lz");
static const u32 gWallpaperTilemap_Pikachu[] = INCBIN_U32("graphics/pokemon_storage/pikachu.bin.lz");

static const u16 gWallpaperPalettes_Legendary[][16] =
{
    INCBIN_U16("graphics/pokemon_storage/friends_frame2.gbapal"),
    INCBIN_U16("graphics/pokemon_storage/legendary_bg.gbapal"),
};
static const u32 gWallpaperTiles_Legendary[] = INCBIN_U32("graphics/pokemon_storage/legendary.4bpp.lz");
static const u32 gWallpaperTilemap_Legendary[] = INCBIN_U32("graphics/pokemon_storage/legendary.bin.lz");

static const u16 gWallpaperPalettes_Dusclops[][16] =
{
    INCBIN_U16("graphics/pokemon_storage/friends_frame2.gbapal"),
    INCBIN_U16("graphics/pokemon_storage/dusclops_bg.gbapal"),
};
static const u32 gWallpaperTiles_Dusclops[] = INCBIN_U32("graphics/pokemon_storage/dusclops.4bpp.lz");
static const u32 gWallpaperTilemap_Dusclops[] = INCBIN_U32("graphics/pokemon_storage/dusclops.bin.lz");

static const u16 gWallpaperPalettes_Ludicolo[][16] =
{
    INCBIN_U16("graphics/pokemon_storage/friends_frame2.gbapal"),
    INCBIN_U16("graphics/pokemon_storage/ludicolo_bg.gbapal"),
};
static const u32 gWallpaperTiles_Ludicolo[] = INCBIN_U32("graphics/pokemon_storage/ludicolo.4bpp.lz");
static const u32 gWallpaperTilemap_Ludicolo[] = INCBIN_U32("graphics/pokemon_storage/ludicolo.bin.lz");

static const u16 gWallpaperPalettes_Whiscash[][16] =
{
    INCBIN_U16("graphics/pokemon_storage/friends_frame2.gbapal"),
    INCBIN_U16("graphics/pokemon_storage/whiscash_bg.gbapal"),
};
static const u32 gWallpaperTiles_Whiscash[] = INCBIN_U32("graphics/pokemon_storage/whiscash.4bpp.lz");
static const u32 gWallpaperTilemap_Whiscash[] = INCBIN_U32("graphics/pokemon_storage/whiscash.bin.lz");

static const u32 gWallpaperIcon_Aqua[] = INCBIN_U32("graphics/pokemon_storage/aqua_icon.4bpp.lz");
static const u32 gWallpaperIcon_Heart[] = INCBIN_U32("graphics/pokemon_storage/heart_icon.4bpp.lz");
static const u32 gWallpaperIcon_FiveStar[] = INCBIN_U32("graphics/pokemon_storage/five_star_icon.4bpp.lz");
static const u32 gWallpaperIcon_Brick[] = INCBIN_U32("graphics/pokemon_storage/brick_icon.4bpp.lz");
static const u32 gWallpaperIcon_FourStar[] = INCBIN_U32("graphics/pokemon_storage/four_star_icon.4bpp.lz");
static const u32 gWallpaperIcon_Asterisk[] = INCBIN_U32("graphics/pokemon_storage/asterisk_icon.4bpp.lz");
static const u32 gWallpaperIcon_Dot[] = INCBIN_U32("graphics/pokemon_storage/dot_icon.4bpp.lz");
static const u32 gWallpaperIcon_LineCircle[] = INCBIN_U32("graphics/pokemon_storage/line_circle_icon.4bpp.lz");
static const u32 gWallpaperIcon_PokeBall[] = INCBIN_U32("graphics/pokemon_storage/pokeball_icon.4bpp.lz");
static const u32 gWallpaperIcon_Maze[] = INCBIN_U32("graphics/pokemon_storage/maze_icon.4bpp.lz");
static const u32 gWallpaperIcon_Footprint[] = INCBIN_U32("graphics/pokemon_storage/footprint_icon.4bpp.lz");
static const u32 gWallpaperIcon_BigAsterisk[] = INCBIN_U32("graphics/pokemon_storage/big_asterisk_icon.4bpp.lz");
static const u32 gWallpaperIcon_Circle[] = INCBIN_U32("graphics/pokemon_storage/circle_icon.4bpp.lz");
static const u32 gWallpaperIcon_Koffing[] = INCBIN_U32("graphics/pokemon_storage/koffing_icon.4bpp.lz");
static const u32 gWallpaperIcon_Ribbon[] = INCBIN_U32("graphics/pokemon_storage/ribbon_icon.4bpp.lz");
static const u32 gWallpaperIcon_FourCircles[] = INCBIN_U32("graphics/pokemon_storage/four_circles_icon.4bpp.lz");
static const u32 gWallpaperIcon_Lotad[] = INCBIN_U32("graphics/pokemon_storage/lotad_icon.4bpp.lz");
static const u32 gWallpaperIcon_Crystal[] = INCBIN_U32("graphics/pokemon_storage/crystal_icon.4bpp.lz");
static const u32 gWallpaperIcon_Pichu[] = INCBIN_U32("graphics/pokemon_storage/pichu_icon.4bpp.lz");
static const u32 gWallpaperIcon_Diglett[] = INCBIN_U32("graphics/pokemon_storage/diglett_icon.4bpp.lz");
static const u32 gWallpaperIcon_Luvdisc[] = INCBIN_U32("graphics/pokemon_storage/luvdisc_icon.4bpp.lz");
static const u32 gWallpaperIcon_StarInCircle[] = INCBIN_U32("graphics/pokemon_storage/star_in_circle_icon.4bpp.lz");
static const u32 gWallpaperIcon_Spinda[] = INCBIN_U32("graphics/pokemon_storage/spinda_icon.4bpp.lz");
static const u32 gWallpaperIcon_Latis[] = INCBIN_U32("graphics/pokemon_storage/latis_icon.4bpp.lz");
static const u32 gWallpaperIcon_Minun[] = INCBIN_U32("graphics/pokemon_storage/minun_icon.4bpp.lz");
static const u32 gWallpaperIcon_Togepi[] = INCBIN_U32("graphics/pokemon_storage/togepi_icon.4bpp.lz");
static const u32 gWallpaperIcon_Magma[] = INCBIN_U32("graphics/pokemon_storage/magma_icon.4bpp.lz");

static const struct WallpaperTable gFriendsWallpaperTable[] =
{
    WALLPAPER_ENTRY(Zigzagoon),
    WALLPAPER_ENTRY(Screen),
    WALLPAPER_ENTRY(Horizontal),
    WALLPAPER_ENTRY(Diagonal),
    WALLPAPER_ENTRY(Block),
    WALLPAPER_ENTRY(Ribbon),
    WALLPAPER_ENTRY(Pokecenter2),
    WALLPAPER_ENTRY(Frame),
    WALLPAPER_ENTRY(Blank),
    WALLPAPER_ENTRY(Circles),
    WALLPAPER_ENTRY(Azumarill),
    WALLPAPER_ENTRY(Pikachu),
    WALLPAPER_ENTRY(Legendary),
    WALLPAPER_ENTRY(Dusclops),
    WALLPAPER_ENTRY(Ludicolo),
    WALLPAPER_ENTRY(Whiscash),
};

static const u32 *const gFriendsIcons[] =
{
    gWallpaperIcon_Aqua,
    gWallpaperIcon_Heart,
    gWallpaperIcon_FiveStar,
    gWallpaperIcon_Brick,
    gWallpaperIcon_FourStar,
    gWallpaperIcon_Asterisk,
    gWallpaperIcon_Dot,
    gWallpaperIcon_Cross,
    gWallpaperIcon_LineCircle,
    gWallpaperIcon_PokeBall,
    gWallpaperIcon_Maze,
    gWallpaperIcon_Footprint,
    gWallpaperIcon_BigAsterisk,
    gWallpaperIcon_Circle,
    gWallpaperIcon_Koffing,
    gWallpaperIcon_Ribbon,
    gWallpaperIcon_Bolt,
    gWallpaperIcon_FourCircles,
    gWallpaperIcon_Lotad,
    gWallpaperIcon_Crystal,
    gWallpaperIcon_Pichu,
    gWallpaperIcon_Diglett,
    gWallpaperIcon_Luvdisc,
    gWallpaperIcon_StarInCircle,
    gWallpaperIcon_Spinda,
    gWallpaperIcon_Latis,
    gWallpaperIcon_Plusle,
    gWallpaperIcon_Minun,
    gWallpaperIcon_Togepi,
    gWallpaperIcon_Magma,
};

// Unknown Unused data.
static const u16 gUnknown_0857B07C = 0x23BA;

static const struct SpriteSheet sSpriteSheet_Arrow = {gPCGfx_Arrow, 0x80, 6};

static const struct OamData gOamData_83BB298 =
{
    .shape = SPRITE_SHAPE(32x16),
    .size = SPRITE_SIZE(32x16),
    .priority = 2
};

static const union AnimCmd gSpriteAnim_83BB2A0[] =
{
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_END
};

static const union AnimCmd gSpriteAnim_83BB2A8[] =
{
    ANIMCMD_FRAME(8, 5),
    ANIMCMD_END
};

static const union AnimCmd *const gSpriteAnimTable_83BB2B0[] =
{
    gSpriteAnim_83BB2A0,
    gSpriteAnim_83BB2A8
};

static const struct SpriteTemplate gSpriteTemplate_857B0A8 =
{
    TAG_TILE_3,
    TAG_PAL_DAC9,
    &gOamData_83BB298,
    gSpriteAnimTable_83BB2B0,
    NULL,
    gDummySpriteAffineAnimTable,
    SpriteCallbackDummy
};

static const struct OamData gOamData_83BB2D0 =
{
    .shape = SPRITE_SHAPE(8x16),
    .size = SPRITE_SIZE(8x16),
    .priority = 2
};

static const union AnimCmd gSpriteAnim_83BB2D8[] =
{
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_END
};

static const union AnimCmd gSpriteAnim_83BB2E0[] =
{
    ANIMCMD_FRAME(2, 5),
    ANIMCMD_END
};

static const union AnimCmd *const gSpriteAnimTable_83BB2E8[] =
{
    gSpriteAnim_83BB2D8,
    gSpriteAnim_83BB2E0
};

static const struct SpriteTemplate sSpriteTemplate_Arrow =
{
    6,
    TAG_PAL_WAVEFORM,
    &gOamData_83BB2D0,
    gSpriteAnimTable_83BB2E8,
    NULL,
    gDummySpriteAffineAnimTable,
    sub_80CD210
};

static const u16 gHandCursorPalette[] = INCBIN_U16("graphics/pokemon_storage/hand_cursor.gbapal");
static const u8 gHandCursorTiles[] = INCBIN_U8("graphics/pokemon_storage/hand_cursor.4bpp");
static const u8 gHandCursorShadowTiles[] = INCBIN_U8("graphics/pokemon_storage/hand_cursor_shadow.4bpp");

// code
void DrawTextWindowAndBufferTiles(const u8 *string, void *dst, u8 zero1, u8 zero2, s32 bytesToBuffer)
{
    s32 i, tileBytesToBuffer, remainingBytes;
    u16 windowId;
    u8 txtColor[3];
    u8 *tileData1, *tileData2;
    struct WindowTemplate winTemplate = {0};

    winTemplate.width = 24;
    winTemplate.height = 2;
    windowId = AddWindow(&winTemplate);
    FillWindowPixelBuffer(windowId, PIXEL_FILL(zero2));
    tileData1 = (u8*) GetWindowAttribute(windowId, WINDOW_TILE_DATA);
    tileData2 = (winTemplate.width * 32) + tileData1;

    if (!zero1)
        txtColor[0] = TEXT_COLOR_TRANSPARENT;
    else
        txtColor[0] = zero2;
    txtColor[1] = TEXT_DYNAMIC_COLOR_6;
    txtColor[2] = TEXT_DYNAMIC_COLOR_5;
    AddTextPrinterParameterized4(windowId, 1, 0, 1, 0, 0, txtColor, -1, string);

    tileBytesToBuffer = bytesToBuffer;
    if (tileBytesToBuffer > 6u)
        tileBytesToBuffer = 6;
    remainingBytes = bytesToBuffer - 6;
    if (tileBytesToBuffer > 0)
    {
        for (i = tileBytesToBuffer; i != 0; i--)
        {
            CpuCopy16(tileData1, dst, 0x80);
            CpuCopy16(tileData2, dst + 0x80, 0x80);
            tileData1 += 0x80;
            tileData2 += 0x80;
            dst += 0x100;
        }
    }

    // Never used. bytesToBuffer is always passed <= 6, so remainingBytes is always <= 0 here
    if (remainingBytes > 0)
        CpuFill16((zero2 << 4) | zero2, dst, (u32)(remainingBytes) * 0x100);

    RemoveWindow(windowId);
}

// Unused
void sub_80C6EAC(const u8 *string, void *dst, u16 arg2, u8 arg3, u8 clr2, u8 clr3)
{
    u32 var;
    u8 windowId;
    u8 txtColor[3];
    u8 *tileData1, *tileData2;
    struct WindowTemplate winTemplate = {0};

    winTemplate.width = StringLength_Multibyte(string);
    winTemplate.height = 2;
    var = winTemplate.width * 32;
    windowId = AddWindow(&winTemplate);
    FillWindowPixelBuffer(windowId, PIXEL_FILL(arg3));
    tileData1 = (u8*) GetWindowAttribute(windowId, WINDOW_TILE_DATA);
    tileData2 = (winTemplate.width * 32) + tileData1;
    txtColor[0] = arg3;
    txtColor[1] = clr2;
    txtColor[2] = clr3;
    AddTextPrinterParameterized4(windowId, 1, 0, 2, 0, 0, txtColor, -1, string);
    CpuCopy16(tileData1, dst, var);
    CpuCopy16(tileData2, dst + arg2, var);
    RemoveWindow(windowId);
}

u8 CountMonsInBox(u8 boxId)
{
    u16 i, count;

    for (i = 0, count = 0; i < IN_BOX_COUNT; i++)
    {
        if (GetBoxMonDataAt(boxId, i, MON_DATA_SPECIES) != SPECIES_NONE)
            count++;
    }

    return count;
}

s16 GetFirstFreeBoxSpot(u8 boxId)
{
    u16 i;

    for (i = 0; i < IN_BOX_COUNT; i++)
    {
        if (GetBoxMonDataAt(boxId, i, MON_DATA_SPECIES) == SPECIES_NONE)
            return i;
    }

    return -1; // all spots are taken
}

u8 CountPartyNonEggMons(void)
{
    u16 i, count;

    for (i = 0, count = 0; i < PARTY_SIZE; i++)
    {
        if (GetMonData(&gPlayerParty[i], MON_DATA_SPECIES) != SPECIES_NONE
            && !GetMonData(&gPlayerParty[i], MON_DATA_IS_EGG))
        {
            count++;
        }
    }

    return count;
}

u8 CountPartyAliveNonEggMonsExcept(u8 slotToIgnore)
{
    u16 i, count;

    for (i = 0, count = 0; i < PARTY_SIZE; i++)
    {
        if (i != slotToIgnore
            && GetMonData(&gPlayerParty[i], MON_DATA_SPECIES) != SPECIES_NONE
            && !GetMonData(&gPlayerParty[i], MON_DATA_IS_EGG)
            && GetMonData(&gPlayerParty[i], MON_DATA_HP) != 0)
        {
            count++;
        }
    }

    return count;
}

u16 CountPartyAliveNonEggMons_IgnoreVar0x8004Slot(void)
{
    return CountPartyAliveNonEggMonsExcept(gSpecialVar_0x8004);
}

u8 CountPartyMons(void)
{
    u16 i, count;

    for (i = 0, count = 0; i < PARTY_SIZE; i++)
    {
        if (GetMonData(&gPlayerParty[i], MON_DATA_SPECIES) != SPECIES_NONE)
        {
            count++;
        }
    }

    return count;
}

u8 *StringCopyAndFillWithSpaces(u8 *dst, const u8 *src, u16 n)
{
    u8 *str;

    for (str = StringCopy(dst, src); str < dst + n; str++)
        *str = CHAR_SPACE;

    *str = EOS;
    return str;
}

static void sub_80C7128(u16 *dest, u16 dest_left, u16 dest_top, const u16 *src, u16 src_left, u16 src_top, u16 dest_width, u16 dest_height, u16 src_width)
{
    u16 i;

    dest_width *= 2;
    dest += dest_top * 0x20 + dest_left;
    src += src_top * src_width + src_left;
    for (i = 0; i < dest_height; i++)
    {
        CpuCopy16(src, dest, dest_width);
        dest += 0x20;
        src += src_width;
    }
}

static void sub_80C71A4(u16 *dest, u16 dest_left, u16 dest_top, u16 width, u16 height)
{
    u16 i;

    dest += dest_top * 0x20 + dest_left;
    width *= 2;
    for (i = 0; i < height; dest += 0x20, i++)
        Dma3FillLarge16_(0, dest, width);
}

static void Task_PokemonStorageSystemPC(u8 taskId)
{
    struct Task *task = &gTasks[taskId];

    switch (task->data[0])
    {
    case 0:
        CreatePCMenu(task->data[1], &task->data[15]);
        LoadMessageBoxAndBorderGfx();
        DrawDialogueFrame(0, 0);
        FillWindowPixelBuffer(0, PIXEL_FILL(MESSAGEBOX_BACKGROUND_COLOR));
        AddTextPrinterParameterized2(0, 1, sMainMenuTexts[task->data[1]].desc, TEXT_SPEED_FF, NULL, MESSAGEBOX_FONT_COLOR, MESSAGEBOX_BACKGROUND_COLOR, MESSAGEBOX_FONT_SHADOW_COLOR);
        //AddTextPrinterParameterized2(0, 1, sMainMenuTexts[task->data[1]].desc, TEXT_SPEED_FF, NULL, 2, 1, 3);
        CopyWindowToVram(0, 3);
        CopyWindowToVram(task->data[15], 3);
        task->data[0]++;
        break;
    case 1:
        if (IsWeatherNotFadingIn())
        {
            task->data[0]++;
        }
        break;
    case 2:
        task->data[2] = Menu_ProcessInput();
        switch(task->data[2])
        {
        case MENU_NOTHING_CHOSEN:
            task->data[3] = task->data[1];
            if (JOY_NEW(DPAD_UP) && --task->data[3] < 0)
                task->data[3] = 4;

            if (JOY_NEW(DPAD_DOWN) && ++task->data[3] > 4)
                task->data[3] = 0;
            if (task->data[1] != task->data[3])
            {
                task->data[1] = task->data[3];
                //FillWindowPixelBuffer(0, PIXEL_FILL(1));
                //AddTextPrinterParameterized2(0, 1, sMainMenuTexts[task->data[1]].desc, 0, NULL, 2, 1, 3);
                
                FillWindowPixelBuffer(0, PIXEL_FILL(MESSAGEBOX_BACKGROUND_COLOR));
                AddTextPrinterParameterized2(0, 1, sMainMenuTexts[task->data[1]].desc, 0, NULL, MESSAGEBOX_FONT_COLOR, MESSAGEBOX_BACKGROUND_COLOR, MESSAGEBOX_FONT_SHADOW_COLOR);
            }
            break;
        case MENU_B_PRESSED:
        case  4:
            ClearStdWindowAndFrame(task->data[15], TRUE);
            ScriptContext2_Disable();
            EnableBothScriptContexts();
            RemoveWindow(task->data[15]);
            DestroyTask(taskId);
            break;
        default:
            if (task->data[2] == 0 && CountPartyMons() == PARTY_SIZE)
            {
                //FillWindowPixelBuffer(0, PIXEL_FILL(1));
                //AddTextPrinterParameterized2(0, 1, gText_PartyFull, 0, NULL, 2, 1, 3);
                
                FillWindowPixelBuffer(0, PIXEL_FILL(MESSAGEBOX_BACKGROUND_COLOR));
                AddTextPrinterParameterized2(0, 1, gText_PartyFull, 0, NULL, MESSAGEBOX_FONT_COLOR, MESSAGEBOX_BACKGROUND_COLOR, MESSAGEBOX_FONT_SHADOW_COLOR);
                task->data[0] = 3;
            }
            else if (task->data[2] == 1 && CountPartyMons() == 1)
            {
                //FillWindowPixelBuffer(0, PIXEL_FILL(1));
                //AddTextPrinterParameterized2(0, 1, gText_JustOnePkmn, 0, NULL, 2, 1, 3);
                FillWindowPixelBuffer(0, PIXEL_FILL(MESSAGEBOX_BACKGROUND_COLOR));
                AddTextPrinterParameterized2(0, 1, gText_JustOnePkmn, 0, NULL, MESSAGEBOX_FONT_COLOR, MESSAGEBOX_BACKGROUND_COLOR, MESSAGEBOX_FONT_SHADOW_COLOR);
                task->data[0] = 3;
            }
            else
            {
                FadeScreen(FADE_TO_BLACK, 0);
                task->data[0] = 4;
            }
            break;
        }
        break;
    case 3:
        if (JOY_NEW(A_BUTTON | B_BUTTON))
        {
            //FillWindowPixelBuffer(0, PIXEL_FILL(1));
            //AddTextPrinterParameterized2(0, 1, sMainMenuTexts[task->data[1]].desc, 0, NULL, 2, 1, 3);
            
            FillWindowPixelBuffer(0, PIXEL_FILL(MESSAGEBOX_BACKGROUND_COLOR));
            AddTextPrinterParameterized2(0, 1, sMainMenuTexts[task->data[1]].desc, 0, NULL, MESSAGEBOX_FONT_COLOR, MESSAGEBOX_BACKGROUND_COLOR, MESSAGEBOX_FONT_SHADOW_COLOR);
            task->data[0] = 2;
        }
        else if (JOY_NEW(DPAD_UP))
        {
            if (--task->data[1] < 0)
                task->data[1] = 4;
            Menu_MoveCursor(-1);
            task->data[1] = Menu_GetCursorPos();
            FillWindowPixelBuffer(0, PIXEL_FILL(1));
            AddTextPrinterParameterized2(0, 1, sMainMenuTexts[task->data[1]].desc, 0, NULL, 2, 1, 3);
            task->data[0] = 2;
        }
        else if (JOY_NEW(DPAD_DOWN))
        {
            if (++task->data[1] > 3)
                task->data[1] = 0;
            Menu_MoveCursor(1);
            task->data[1] = Menu_GetCursorPos();
            FillWindowPixelBuffer(0, PIXEL_FILL(1));
            AddTextPrinterParameterized2(0, 1, sMainMenuTexts[task->data[1]].desc, 0, NULL, 2, 1, 3);
            task->data[0] = 2;
        }
        break;
    case 4:
        if (!gPaletteFade.active)
        {
            CleanupOverworldWindowsAndTilemaps();
            EnterPokeStorage(task->data[2]);
            RemoveWindow(task->data[15]);
            DestroyTask(taskId);
        }
        break;
    }
}

void ShowPokemonStorageSystemPC(void)
{
    u8 taskId = CreateTask(Task_PokemonStorageSystemPC, 80);
    gTasks[taskId].data[0] = 0;
    gTasks[taskId].data[1] = 0;
    ScriptContext2_Enable();
}

static void FieldCb_ReturnToPcMenu(void)
{
    u8 taskId;
    MainCallback vblankCb = gMain.vblankCallback;

    SetVBlankCallback(NULL);
    taskId = CreateTask(Task_PokemonStorageSystemPC, 80);
    gTasks[taskId].data[0] = 0;
    gTasks[taskId].data[1] = sPreviousBoxOption;
    Task_PokemonStorageSystemPC(taskId);
    SetVBlankCallback(vblankCb);
    FadeInFromBlack();
}

static void CreatePCMenu(u8 whichMenu, s16 *windowIdPtr)
{
    s16 windowId;
    struct WindowTemplate winTemplate = sMainMenusWindowTemplate_MainMenuTexts;
    winTemplate.width = GetMaxWidthInMenuTable((void *)sMainMenuTexts, ARRAY_COUNT(sMainMenuTexts));
    windowId = AddWindow(&winTemplate);

    DrawStdWindowFrame(windowId, FALSE);
    PrintMenuTable(windowId, ARRAY_COUNT(sMainMenuTexts), (void *)sMainMenuTexts);
    InitMenuInUpperLeftCornerPlaySoundWhenAPressed(windowId, ARRAY_COUNT(sMainMenuTexts), whichMenu);
    *windowIdPtr = windowId;
}

static void Cb2_ExitPSS(void)
{
    sPreviousBoxOption = GetCurrentBoxOption();
    gFieldCallback = FieldCb_ReturnToPcMenu;
    SetMainCallback2(CB2_ReturnToField);
}

static s16 StorageSystemGetNextMonIndex(struct BoxPokemon *box, s8 startIdx, u8 stopIdx, u8 mode)
{
    s16 i;
    s16 direction;
    if (mode == 0 || mode == 1)
    {
        direction = 1;
    }
    else
    {
        direction = -1;
    }
    if (mode == 1 || mode == 3)
    {
        for (i = startIdx + direction; i >= 0 && i <= stopIdx; i += direction)
        {
            if (GetBoxMonData(box + i, MON_DATA_SPECIES) != 0)
                return i;
        }
    }
    else
    {
        for (i = startIdx + direction; i >= 0 && i <= stopIdx; i += direction)
        {
            if (GetBoxMonData(box + i, MON_DATA_SPECIES) != 0 && !GetBoxMonData(box + i, MON_DATA_IS_EGG))
                return i;
        }
    }
    return -1;
}

void ResetPokemonStorageSystem(void)
{
    u16 boxId, boxPosition;

    SetCurrentBox(0);
    for (boxId = 0; boxId < TOTAL_BOXES_COUNT; boxId++)
    {
        for (boxPosition = 0; boxPosition < IN_BOX_COUNT; boxPosition++)
            ZeroBoxMonAt(boxId, boxPosition);
    }
    for (boxId = 0; boxId < TOTAL_BOXES_COUNT; boxId++)
    {
        u8 *dest = StringCopy(GetBoxNamePtr(boxId), gText_Box);
        ConvertIntToDecimalStringN(dest, boxId + 1, STR_CONV_MODE_LEFT_ALIGN, 2);
    }
    for (boxId = 0; boxId < TOTAL_BOXES_COUNT; boxId++)
    {
        SetBoxWallpaper(boxId, boxId % 4);
    }
    ResetWaldaWallpaper();
}

void ResetPokemonStorageSystemLevels(void)
{
    u16 boxId, boxPosition;
	u32 defaultExp = 1;
	u8 defaultLevel = 1;
	u16 move = MOVE_NONE;
	u8 i;
	u8 j;

    for (boxId = 0; boxId < TOTAL_BOXES_COUNT; boxId++)
    {
        for (boxPosition = 0; boxPosition < IN_BOX_COUNT; boxPosition++){
			if(GetMonData(&gPokemonStoragePtr->boxes[boxId][boxPosition], MON_DATA_SPECIES, NULL) != SPECIES_NONE){
				SetBoxMonData(&gPokemonStoragePtr->boxes[boxId][boxPosition], MON_DATA_LEVEL, &defaultLevel);
				SetBoxMonData(&gPokemonStoragePtr->boxes[boxId][boxPosition], MON_DATA_EXP, &defaultExp);
				
				for (i = 0; i < MAX_MON_MOVES; i++)
				{
					SetBoxMonData(&gPokemonStoragePtr->boxes[boxId][boxPosition], MON_DATA_MOVE1 + i, &move);
					SetBoxMonData(&gPokemonStoragePtr->boxes[boxId][boxPosition], MON_DATA_PP1 + i, &gBattleMoves[move].pp);
				}
				
				GiveBoxMonInitialMoveset(&gPokemonStoragePtr->boxes[boxId][boxPosition]);
			}
		}
    }
	
	for (j = 0; j < PARTY_SIZE; j++)
	{
		if(GetMonData(&gPlayerParty[j], MON_DATA_SPECIES, NULL) != SPECIES_NONE){
			SetMonData(&gPlayerParty[j], MON_DATA_LEVEL, &defaultLevel);
			SetMonData(&gPlayerParty[j], MON_DATA_EXP, &defaultExp);
				
			for (i = 0; i < MAX_MON_MOVES; i++)
			{
				SetMonData(&gPlayerParty[j], MON_DATA_MOVE1 + i, &move);
				SetMonData(&gPlayerParty[j], MON_DATA_PP1 + i, &gBattleMoves[move].pp);
			}
			
			GiveMonInitialMoveset(&gPlayerParty[j]);
			CalculateMonStats(&gPlayerParty[j]);
		}
	}
}

static void sub_80C77E8(struct ChooseBoxMenu *a0, u16 tileTag, u16 palTag, u8 a3, bool32 loadPal)
{
    struct SpritePalette palette =
    {
        gBoxSelectionPopupPalette, palTag
    };
    struct SpriteSheet sheets[] =
    {
        {gBoxSelectionPopupCenterTiles, 0x800, tileTag},
        {gBoxSelectionPopupSidesTiles,  0x180, tileTag + 1},
        {}
    };

    if (loadPal)
        LoadSpritePalette(&palette);

    LoadSpriteSheets(sheets);
    gUnknown_02039D04 = a0;
    a0->tileTag = tileTag;
    a0->paletteTag = palTag;
    a0->subpriority = a3;
    a0->loadedPalette = loadPal;
}

static void sub_80C7890(void)
{
    if (gUnknown_02039D04->loadedPalette)
        FreeSpritePaletteByTag(gUnknown_02039D04->paletteTag);
    FreeSpriteTilesByTag(gUnknown_02039D04->tileTag);
    FreeSpriteTilesByTag(gUnknown_02039D04->tileTag + 1);
}

static void sub_80C78D4(u8 curBox)
{
    sub_80C7958(curBox);
}

static void sub_80C78E4(void)
{
    sub_80C7B14();
}

static u8 HandleBoxChooseSelectionInput(void)
{
    if (JOY_NEW(B_BUTTON))
    {
        PlaySE(SE_SELECT);
        return 201;
    }
    if (JOY_NEW(A_BUTTON))
    {
        PlaySE(SE_SELECT);
        return gUnknown_02039D04->curBox;
    }
    if (JOY_NEW(DPAD_LEFT))
    {
        PlaySE(SE_SELECT);
        sub_80C7BB4();
    }
    else if (JOY_NEW(DPAD_RIGHT))
    {
        PlaySE(SE_SELECT);
        sub_80C7B80();
    }
    return 200;
}

static void sub_80C7958(u8 curBox)
{
    u16 i;
    u8 spriteId;
    struct SpriteTemplate template;
    struct OamData oamData = {};
    oamData.size = SPRITE_SIZE(64x64);
    oamData.paletteNum = 1;
    template = (struct SpriteTemplate){
        0, 0, &oamData, gDummySpriteAnimTable, NULL, gDummySpriteAffineAnimTable, SpriteCallbackDummy
    };

    gUnknown_02039D04->curBox = curBox;
    template.tileTag = gUnknown_02039D04->tileTag;
    template.paletteTag = gUnknown_02039D04->paletteTag;

    spriteId = CreateSprite(&template, 160, 96, 0);
    gUnknown_02039D04->menuSprite = gSprites + spriteId;

    oamData.shape = SPRITE_SHAPE(8x32);
    oamData.size = SPRITE_SIZE(8x32);
    template.tileTag = gUnknown_02039D04->tileTag + 1;
    template.anims = sAnims_ChooseBoxMenu;
    for (i = 0; i < 4; i++)
    {
        u16 r5;
        spriteId = CreateSprite(&template, 124, 80, gUnknown_02039D04->subpriority);
        gUnknown_02039D04->menuSideSprites[i] = gSprites + spriteId;
        r5 = 0;
        if (i & 2)
        {
            gUnknown_02039D04->menuSideSprites[i]->pos1.x = 196;
            r5 = 2;
        }
        if (i & 1)
        {
            gUnknown_02039D04->menuSideSprites[i]->pos1.y = 112;
            gUnknown_02039D04->menuSideSprites[i]->oam.size = 0;
            r5++;
        }
        StartSpriteAnim(gUnknown_02039D04->menuSideSprites[i], r5);
    }
    for (i = 0; i < 2; i++)
    {
        gUnknown_02039D04->arrowSprites[i] = sub_80CD2E8(72 * i + 0x7c, 0x58, i, 0, gUnknown_02039D04->subpriority);
        if (gUnknown_02039D04->arrowSprites[i])
        {
            gUnknown_02039D04->arrowSprites[i]->data[0] = (i == 0 ? -1 : 1);
            gUnknown_02039D04->arrowSprites[i]->callback = sub_80C7CF4;
        }
    }
    sub_80C7BE4();
}

static void sub_80C7B14(void)
{
    u16 i;
    if (gUnknown_02039D04->menuSprite)
    {
        DestroySprite(gUnknown_02039D04->menuSprite);
        gUnknown_02039D04->menuSprite = NULL;
    }
    for (i = 0; i < 4; i++)
    {
        if (gUnknown_02039D04->menuSideSprites[i])
        {
            DestroySprite(gUnknown_02039D04->menuSideSprites[i]);
            gUnknown_02039D04->menuSideSprites[i] = NULL;
        }
    }
    for (i = 0; i < 2; i++)
    {
        if (gUnknown_02039D04->arrowSprites[i])
            DestroySprite(gUnknown_02039D04->arrowSprites[i]);
    }
}

static void sub_80C7B80(void)
{
    if (++gUnknown_02039D04->curBox >= TOTAL_BOXES_COUNT)
        gUnknown_02039D04->curBox = 0;
    sub_80C7BE4();
}

static void sub_80C7BB4(void)
{
    gUnknown_02039D04->curBox = (gUnknown_02039D04->curBox == 0 ? TOTAL_BOXES_COUNT - 1 : gUnknown_02039D04->curBox - 1);
    sub_80C7BE4();
}

static void sub_80C7BE4(void)
{
    u8 numBoxMonsText[16];
    struct WindowTemplate winTemplate;
    u8 windowId;
    u8 *boxName = GetBoxNamePtr(gUnknown_02039D04->curBox);
    u8 nPokemonInBox = CountMonsInBox(gUnknown_02039D04->curBox);
    u32 winTileData;
    s32 center;

    memset(&winTemplate, 0, sizeof(winTemplate));
    winTemplate.width = 8;
    winTemplate.height = 4;

    windowId = AddWindow(&winTemplate);
    FillWindowPixelBuffer(windowId, PIXEL_FILL(4));

    center = GetStringCenterAlignXOffset(1, boxName, 64);
    AddTextPrinterParameterized3(windowId, 1, center, 1, sBoxInfoTextColors, TEXT_SPEED_FF, boxName);

    ConvertIntToDecimalStringN(numBoxMonsText, nPokemonInBox, STR_CONV_MODE_RIGHT_ALIGN, 2);
    StringAppend(numBoxMonsText, sText_OutOf30);
    center = GetStringCenterAlignXOffset(1, numBoxMonsText, 64);
    AddTextPrinterParameterized3(windowId, 1, center, 17, sBoxInfoTextColors, TEXT_SPEED_FF, numBoxMonsText);

    winTileData = GetWindowAttribute(windowId, WINDOW_TILE_DATA);
    CpuCopy32((void *)winTileData, (void *)OBJ_VRAM0 + 0x100 + (GetSpriteTileStartByTag(gUnknown_02039D04->tileTag) * 32), 0x400);

    RemoveWindow(windowId);
}

static void sub_80C7CF4(struct Sprite *sprite)
{
    if (++sprite->data[1] > 3)
    {
        sprite->data[1] = 0;
        sprite->pos2.x += sprite->data[0];
        if (++sprite->data[2] > 5)
        {
            sprite->data[2] = 0;
            sprite->pos2.x = 0;
        }
    }
}

static void VblankCb_PSS(void)
{
    LoadOam();
    ProcessSpriteCopyRequests();
    sub_80D2AA4();
    TransferPlttBuffer();
    SetGpuReg(REG_OFFSET_BG2HOFS, sStorage->bg2_X);
}

static void CB2_PokeStorage(void)
{
    RunTasks();
    DoScheduledBgTilemapCopiesToVram();
    ScrollBackground();
    UpdateCloseBoxButtonFlash();
    AnimateSprites();
    BuildOamBuffer();
}

static void EnterPokeStorage(u8 boxOption)
{
    ResetTasks();
    sCurrentBoxOption = boxOption;
    sStorage = Alloc(sizeof(*sStorage));
    if (sStorage == NULL)
    {
        SetMainCallback2(Cb2_ExitPSS);
    }
    else
    {
        sStorage->boxOption = boxOption;
        sStorage->isReshowingPSS = FALSE;
        sMovingItemId = ITEM_NONE;
        sStorage->state = 0;
        sStorage->taskId = CreateTask(Task_InitPokeStorage, 3);
        sLastUsedBox = StorageGetCurrentBox();
        SetMainCallback2(CB2_PokeStorage);
    }
}

static void CB2_ReturnToPokeStorage(void)
{
    ResetTasks();
    sStorage = Alloc(sizeof(*sStorage));
    if (sStorage == NULL)
    {
        SetMainCallback2(Cb2_ExitPSS);
    }
    else
    {
        sStorage->boxOption = sCurrentBoxOption;
        sStorage->isReshowingPSS = TRUE;
        sStorage->state = 0;
        sStorage->taskId = CreateTask(Task_InitPokeStorage, 3);
        SetMainCallback2(CB2_PokeStorage);
    }
}

static void ResetAllBgCoords(void)
{
    SetGpuReg(REG_OFFSET_BG0HOFS, 0);
    SetGpuReg(REG_OFFSET_BG0VOFS, 0);
    SetGpuReg(REG_OFFSET_BG1HOFS, 0);
    SetGpuReg(REG_OFFSET_BG1VOFS, 0);
    SetGpuReg(REG_OFFSET_BG2HOFS, 0);
    SetGpuReg(REG_OFFSET_BG2VOFS, 0);
    SetGpuReg(REG_OFFSET_BG3HOFS, 0);
    SetGpuReg(REG_OFFSET_BG3VOFS, 0);
}

static void ResetForPokeStorage(void)
{
    ResetPaletteFade();
    ResetSpriteData();
    FreeSpriteTileRanges();
    FreeAllSpritePalettes();
    ClearDma3Requests();
    gReservedSpriteTileCount = 0x280;
    UnkUtil_Init(&sStorage->unkUtil, sStorage->unkUtilData, 8);
    gKeyRepeatStartDelay = 20;
    ClearScheduledBgCopiesToVram();
    TilemapUtil_Init(3);
    TilemapUtil_SetMap(0, 1, sPkmnData_Tilemap, 8, 4);
    TilemapUtil_SetPos(0, 1, 0);
    sStorage->closeBoxFlashing = 0;
}

static void InitStartingPosData(void)
{
    ClearSavedCursorPos();
    sInPartyMenu = (sStorage->boxOption == OPTION_DEPOSIT);
    sDepositBoxId = 0;
}

static void SetMonIconTransparency(void)
{
    if (sStorage->boxOption == OPTION_MOVE_ITEMS)
    {
        SetGpuReg(REG_OFFSET_BLDCNT, BLDCNT_TGT2_ALL);
        SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(7, 11));
    }
    SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_OBJ_ON | DISPCNT_BG_ALL_ON | DISPCNT_OBJ_1D_MAP);
}

static void SetPokeStorageTask(TaskFunc newFunc)
{
    gTasks[sStorage->taskId].func = newFunc;
    sStorage->state = 0;
}

static void Task_InitPokeStorage(u8 taskId)
{
	if (POF_PlayerHasFollower()) //tx_pokemon_follower
        POF_DestroyFollower();
	
    switch (sStorage->state)
    {
    case 0:
        SetVBlankCallback(NULL);
        SetGpuReg(REG_OFFSET_DISPCNT, 0);
        ResetForPokeStorage();
        if (sStorage->isReshowingPSS)
        {
            switch (sWhichToReshow)
            {
            case 1:
                // Return from naming box
                LoadSavedMovingMon();
                break;
            case 0:
                // Return from summary screen
                SetSelectionAfterSummaryScreen();
                break;
            case 2:
                // Return from bag menu
                GiveChosenBagItem();
                break;
            }
        }
        LoadPSSMenuGfx();
        LoadWaveformSpritePalette();
        break;
    case 1:
        if (!InitPSSWindows())
        {
            SetPokeStorageTask(Cb_ChangeScreen);
            return;
        }
        break;
    case 2:
        PutWindowTilemap(0);
        ClearWindowTilemap(1);
        CpuFill32(0, (void *)VRAM, 0x200);
        LoadUserWindowBorderGfx(1, 0xB, 0xE0);
        break;
    case 3:
        ResetAllBgCoords();
        if (!sStorage->isReshowingPSS)
            InitStartingPosData();
        break;
    case 4:
        InitMonIconFields();
        if (!sStorage->isReshowingPSS)
            InitCursor();
        else
            InitCursorOnReopen();
        break;
    case 5:
        if (!MultiMove_Init())
        {
            SetPokeStorageTask(Cb_ChangeScreen);
            return;
        }
        else
        {
            SetScrollingBackground();
            InitPokeStorageBg0();
        }
        break;
    case 6:
        InitPalettesAndSprites();
        break;
    case 7:
        InitSupplementalTilemaps();
        break;
    case 8:
        CreateInitBoxTask(StorageGetCurrentBox());
        break;
    case 9:
        if (IsInitBoxActive())
            return;

        if (sStorage->boxOption != OPTION_MOVE_ITEMS)
        {
            sStorage->markMenu.baseTileTag = TAG_TILE_D;
            sStorage->markMenu.basePaletteTag = TAG_PAL_DACE;
            InitMonMarkingsMenu(&sStorage->markMenu);
            BufferMonMarkingsMenuTiles();
        }
        else
        {
            CreateItemIconSprites();
            InitCursorItemIcon();
        }
        break;
    case 10:
        SetMonIconTransparency();
        if (!sStorage->isReshowingPSS)
        {
            BlendPalettes(0xFFFFFFFF, 0x10, RGB_BLACK);
            SetPokeStorageTask(Cb_ShowPSS);
        }
        else
        {
            BlendPalettes(0xFFFFFFFF, 0x10, RGB_BLACK);
            SetPokeStorageTask(Cb_ReshowPSS);
        }
        SetVBlankCallback(VblankCb_PSS);
        return;
    default:
        return;
    }

    sStorage->state++;
}

static void Cb_ShowPSS(u8 taskId)
{
    switch (sStorage->state)
    {
    case 0:
        PlaySE(SE_PC_LOGIN);
        ComputerScreenOpenEffect(20, 0, 1);
        sStorage->state++;
        break;
    case 1:
        if (!IsComputerScreenOpenEffectActive())
            SetPokeStorageTask(Task_PokeStorageMain);
        break;
    }
}

static void Cb_ReshowPSS(u8 taskId)
{
    switch (sStorage->state)
    {
    case 0:
        BeginNormalPaletteFade(0xFFFFFFFF, -1, 0x10, 0, RGB_BLACK);
        sStorage->state++;
        break;
    case 1:
        if (!UpdatePaletteFade())
        {
            if (sWhichToReshow == 2 && gSpecialVar_ItemId != 0)
            {
                PrintMessage(PC_TEXT_ITEM_IS_HELD);
                sStorage->state++;
            }
            else
            {
                SetPokeStorageTask(Task_PokeStorageMain);
            }
        }
        break;
    case 2:
        if (!IsDma3ManagerBusyWithBgCopy() && JOY_NEW(A_BUTTON | B_BUTTON))
        {
            ClearBottomWindow();
            sStorage->state++;
        }
        break;
    case 3:
        if (!IsDma3ManagerBusyWithBgCopy())
            SetPokeStorageTask(Task_PokeStorageMain);
        break;
    }
}

static void Task_PokeStorageMain(u8 taskId)
{
    switch (sStorage->state)
    {
    case 0:
        switch (HandleInput())
        {
        case INPUT_MOVE_CURSOR:
            PlaySE(SE_SELECT);
            sStorage->state = 1;
            break;
        case INPUT_SHOW_PARTY:
            if (sStorage->boxOption != OPTION_MOVE_MONS && sStorage->boxOption != OPTION_MOVE_ITEMS)
            {
                PrintMessage(PC_TEXT_WHICH_ONE_WILL_TAKE);
                sStorage->state = MSTATE_WAIT_MSG;
            }
            else
            {
                ClearSavedCursorPos();
                SetPokeStorageTask(Cb_ShowPartyPokemon);
            }
            break;
        case INPUT_HIDE_PARTY:
            if (sStorage->boxOption == OPTION_MOVE_MONS)
            {
                if (IsMonBeingMoved() && ItemIsMail(sStorage->cursorMonItem))
                    sStorage->state = MSTATE_ERROR_HAS_MAIL;
                else
                    SetPokeStorageTask(Task_HidePartyPokemon);
            }
            else if (sStorage->boxOption == OPTION_MOVE_ITEMS)
            {
                SetPokeStorageTask(Task_HidePartyPokemon);
            }
            break;
        case INPUT_CLOSE_BOX:
            SetPokeStorageTask(Task_OnCloseBoxPressed);
            break;
        case INPUT_PRESSED_B:
            SetPokeStorageTask(Task_OnBPressed);
            break;
        case INPUT_BOX_OPTIONS:
            PlaySE(SE_SELECT);
            SetPokeStorageTask(Task_HandleBoxOptions);
            break;
        case INPUT_IN_MENU:
            SetPokeStorageTask(Task_OnSelectedMon);
            break;
        case INPUT_SCROLL_RIGHT:
            PlaySE(SE_SELECT);
            sStorage->newCurrBoxId = StorageGetCurrentBox() + 1;
            if (sStorage->newCurrBoxId >= TOTAL_BOXES_COUNT)
                sStorage->newCurrBoxId = 0;
            if (sStorage->boxOption != OPTION_MOVE_ITEMS)
            {
                SetUpScrollToBox(sStorage->newCurrBoxId);
                sStorage->state = MSTATE_SCROLL_BOX;
            }
            else
            {
                TryHideItemAtCursor();
                sStorage->state = MSTATE_SCROLL_BOX_ITEM;
            }
            break;
        case INPUT_SCROLL_LEFT:
            PlaySE(SE_SELECT);
            sStorage->newCurrBoxId = StorageGetCurrentBox() - 1;
            if (sStorage->newCurrBoxId < 0)
                sStorage->newCurrBoxId = TOTAL_BOXES_COUNT - 1;
            if (sStorage->boxOption != OPTION_MOVE_ITEMS)
            {
                SetUpScrollToBox(sStorage->newCurrBoxId);
                sStorage->state = 2;
            }
            else
            {
                TryHideItemAtCursor();
                sStorage->state = 10;
            }
            break;
        case INPUT_DEPOSIT:
            if (!IsRemovingLastPartyMon())
            {
                if (ItemIsMail(sStorage->cursorMonItem))
                {
                    sStorage->state = 5;
                }
                else
                {
                    PlaySE(SE_SELECT);
                    SetPokeStorageTask(Task_DepositMenu);
                }
            }
            else
            {
                sStorage->state = MSTATE_ERROR_LAST_PARTY_MON;
            }
            break;
        case INPUT_MOVE_MON:
            if (IsRemovingLastPartyMon())
            {
                sStorage->state = MSTATE_ERROR_LAST_PARTY_MON;
            }
            else
            {
                PlaySE(SE_SELECT);
                SetPokeStorageTask(Task_MoveMon);
            }
            break;
        case INPUT_SHIFT_MON:
            if (!CanShiftMon())
            {
                sStorage->state = MSTATE_ERROR_LAST_PARTY_MON;
            }
            else
            {
                PlaySE(SE_SELECT);
                SetPokeStorageTask(Task_ShiftMon);
            }
            break;
        case INPUT_WITHDRAW:
            PlaySE(SE_SELECT);
            SetPokeStorageTask(Task_WithdrawMon);
            break;
        case INPUT_PLACE_MON:
            PlaySE(SE_SELECT);
            SetPokeStorageTask(Cb_PlaceMon);
            break;
        case INPUT_TAKE_ITEM:
            PlaySE(SE_SELECT);
            SetPokeStorageTask(Cb_TakeItemForMoving);
            break;
        case INPUT_GIVE_ITEM:
            PlaySE(SE_SELECT);
            SetPokeStorageTask(Cb_GiveMovingItemToMon);
            break;
        case INPUT_SWITCH_ITEMS:
            PlaySE(SE_SELECT);
            SetPokeStorageTask(Cb_SwitchSelectedItem);
            break;
        case INPUT_MULTIMOVE_START:
            PlaySE(SE_SELECT);
            MultiMove_SetFunction(MULTIMOVE_START);
            sStorage->state = MSTATE_MULTIMOVE_RUN;
            break;
        case INPUT_MULTIMOVE_SINGLE:
            MultiMove_SetFunction(MULTIMOVE_CANCEL);
            sStorage->state = MSTATE_MULTIMOVE_RUN_CANCEL;
            break;
        case INPUT_MULTIMOVE_CHANGE_SELECTION:
            PlaySE(SE_SELECT);
            MultiMove_SetFunction(MULTIMOVE_CHANGE_SELECTION);
            sStorage->state = MSTATE_MULTIMOVE_RUN_MOVED;
            break;
        case INPUT_MULTIMOVE_GRAB_SELECTION:
            MultiMove_SetFunction(MULTIMOVE_GRAB_SELECTION);
            sStorage->state = MSTATE_MULTIMOVE_RUN;
            break;
        case INPUT_MULTIMOVE_MOVE_MONS:
            PlaySE(SE_SELECT);
            MultiMove_SetFunction(MULTIMOVE_MOVE_MONS);
            sStorage->state = MSTATE_MULTIMOVE_RUN_MOVED;
            break;
        case INPUT_MULTIMOVE_PLACE_MONS:
            PlaySE(SE_SELECT);
            MultiMove_SetFunction(MULTIMOVE_PLACE_MONS);
            sStorage->state = MSTATE_MULTIMOVE_RUN;
            break;
        case INPUT_MULTIMOVE_UNABLE:
            // When selecting/moving multiple Pokémon the
            // cursor may not wrap around the edges.
            PlaySE(SE_FAILURE);
            break;
        }
        break;
    case 1:
        if (!sub_80CD554())
        {
            if (IsCursorOnCloseBox())
                sub_80CA9C0();
            else
                sub_80CA9EC();

            if (sStorage->setMosaic)
                StartDisplayMonMosaicEffect();
            sStorage->state = 0;
        }
        break;
    case 2:
        if (!ScrollToBox())
        {
            SetCurrentBox(sStorage->newCurrBoxId);
            if (!sInPartyMenu && !IsMonBeingMoved())
            {
                RefreshDisplayMon();
                StartDisplayMonMosaicEffect();
            }

            if (sStorage->boxOption == OPTION_MOVE_ITEMS)
            {
                sub_80CFECC();
                sStorage->state = 11;
            }
            else
            {
                sStorage->state = 0;
            }
        }
        break;
    case 3:
        if (JOY_NEW(A_BUTTON | B_BUTTON | DPAD_ANY))
        {
            ClearBottomWindow();
            sStorage->state = 0;
        }
        break;
    case 4:
        PlaySE(SE_FAILURE);
        PrintMessage(PC_TEXT_LAST_POKE);
        sStorage->state = 6;
        break;
    case 5:
        PlaySE(SE_FAILURE);
        PrintMessage(PC_TEXT_PLEASE_REMOVE_MAIL);
        sStorage->state = 6;
        break;
    case 6:
        if (JOY_NEW(A_BUTTON | B_BUTTON | DPAD_ANY))
        {
            ClearBottomWindow();
            SetPokeStorageTask(Task_PokeStorageMain);
        }
        break;
    case 7:
        if (!sub_80D01E4())
            sStorage->state = 0;
        break;
    case 8:
        if (!sub_80D01E4())
            SetPokeStorageTask(Task_MoveMon);
        break;
    case 9:
        if (!sub_80D01E4())
        {
            if (sStorage->setMosaic)
                StartDisplayMonMosaicEffect();
            sStorage->state = 0;
        }
        break;
    case 10:
        if (!sub_80D1218())
        {
            SetUpScrollToBox(sStorage->newCurrBoxId);
            sStorage->state = 2;
        }
        break;
    case 11:
        if (!sub_80D1218())
            sStorage->state = 0;
        break;
    }
}

static void Cb_ShowPartyPokemon(u8 taskId)
{
    switch (sStorage->state)
    {
    case 0:
        SetUpDoShowPartyMenu();
        sStorage->state++;
        break;
    case 1:
        if (!DoShowPartyMenu())
            SetPokeStorageTask(Task_PokeStorageMain);
        break;
    }
}

static void Task_HidePartyPokemon(u8 taskId)
{
    switch (sStorage->state)
    {
    case 0:
        PlaySE(SE_SELECT);
        SetUpHidePartyMenu();
        sStorage->state++;
        break;
    case 1:
        if (!HidePartyMenu())
        {
            sub_80CDBF8(sub_80CDC2C());
            sStorage->state++;
        }
        break;
    case 2:
        if (!sub_80CD554())
        {
            if (sStorage->setMosaic)
                StartDisplayMonMosaicEffect();
            SetPokeStorageTask(Task_PokeStorageMain);
        }
        break;
    }
}

static void Task_OnSelectedMon(u8 taskId)
{
    switch (sStorage->state)
    {
    case 0:
        if (!sub_80CA2B8())
        {
            PlaySE(SE_SELECT);
            if (sStorage->boxOption != OPTION_MOVE_ITEMS)
                PrintMessage(PC_TEXT_IS_SELECTED);
            else if (IsActiveItemMoving() || sStorage->cursorMonItem != 0)
                PrintMessage(PC_TEXT_IS_SELECTED2);
            else
                PrintMessage(PC_TEXT_GIVE_TO_MON);

            AddMenu();
            sStorage->state = 1;
        }
        break;
    case 1: // debug?
        if (!sub_80D00A8())
            sStorage->state = 2;
        break;
    case 2:
        switch (sub_80D00AC())
        {
        case -1:
        case  0:
            ClearBottomWindow();
            SetPokeStorageTask(Task_PokeStorageMain);
            break;
        case 3:
            if (IsRemovingLastPartyMon())
            {
                sStorage->state = 3;
            }
            else
            {
                PlaySE(SE_SELECT);
                ClearBottomWindow();
                SetPokeStorageTask(Task_MoveMon);
            }
            break;
        case 5:
            PlaySE(SE_SELECT);
            ClearBottomWindow();
            SetPokeStorageTask(Cb_PlaceMon);
            break;
        case 4:
            if (!CanShiftMon())
            {
                sStorage->state = 3;
            }
            else
            {
                PlaySE(SE_SELECT);
                ClearBottomWindow();
                SetPokeStorageTask(Task_ShiftMon);
            }
            break;
        case 2:
            PlaySE(SE_SELECT);
            ClearBottomWindow();
            SetPokeStorageTask(Task_WithdrawMon);
            break;
        case 1:
            if (IsRemovingLastPartyMon())
            {
                sStorage->state = 3;
            }
            else if (ItemIsMail(sStorage->cursorMonItem))
            {
                sStorage->state = 4;
            }
            else
            {
                PlaySE(SE_SELECT);
                ClearBottomWindow();
                SetPokeStorageTask(Task_DepositMenu);
            }
            break;
        case 7:
            if (IsRemovingLastPartyMon())
            {
                sStorage->state = 3;
            }
            else if (sStorage->cursorMonIsEgg)
            {
                sStorage->state = 5; // Cannot release an Egg.
            }
            else if (ItemIsMail(sStorage->cursorMonItem))
            {
                sStorage->state = 4;
            }
            else
            {
                PlaySE(SE_SELECT);
                SetPokeStorageTask(Task_ReleaseMon);
            }
            break;
        case 6:
            PlaySE(SE_SELECT);
            SetPokeStorageTask(Cb_ShowMonSummary);
            break;
        case 8:
            PlaySE(SE_SELECT);
            SetPokeStorageTask(Cb_ShowMarkMenu);
            break;
        case 12:
            PlaySE(SE_SELECT);
            SetPokeStorageTask(Cb_TakeItemForMoving);
            break;
        case 13:
            PlaySE(SE_SELECT);
            SetPokeStorageTask(Cb_GiveMovingItemToMon);
            break;
        case 16:
            SetPokeStorageTask(Cb_ItemToBag);
            break;
        case 15:
            PlaySE(SE_SELECT);
            SetPokeStorageTask(Cb_SwitchSelectedItem);
            break;
        case 14:
            PlaySE(SE_SELECT);
            SetPokeStorageTask(Cb_GiveItemFromBag);
            break;
        case 17:
            SetPokeStorageTask(Cb_ShowItemInfo);
            break;
        }
        break;
    case 3:
        PlaySE(SE_FAILURE);
        PrintMessage(PC_TEXT_LAST_POKE);
        sStorage->state = 6;
        break;
    case 5:
        PlaySE(SE_FAILURE);
        PrintMessage(PC_TEXT_CANT_RELEASE_EGG);
        sStorage->state = 6;
        break;
    case 4:
        PlaySE(SE_FAILURE);
        PrintMessage(PC_TEXT_PLEASE_REMOVE_MAIL);
        sStorage->state = 6;
        break;
    case 6:
        if (JOY_NEW(A_BUTTON | B_BUTTON | DPAD_ANY))
        {
            ClearBottomWindow();
            SetPokeStorageTask(Task_PokeStorageMain);
        }
        break;
    }
}

static void Task_MoveMon(u8 taskId)
{
    switch (sStorage->state)
    {
    case 0:
        InitMonPlaceChange(0);
        sStorage->state++;
        break;
    case 1:
        if (!DoMonPlaceChange())
        {
            if (sInPartyMenu)
                SetPokeStorageTask(Cb_HandleMovingMonFromParty);
            else
                SetPokeStorageTask(Task_PokeStorageMain);
        }
        break;
    }
}

static void Cb_PlaceMon(u8 taskId)
{
    switch (sStorage->state)
    {
    case 0:
        InitMonPlaceChange(1);
        sStorage->state++;
        break;
    case 1:
        if (!DoMonPlaceChange())
        {
            if (sInPartyMenu)
                SetPokeStorageTask(Cb_HandleMovingMonFromParty);
            else
                SetPokeStorageTask(Task_PokeStorageMain);
        }
        break;
    }
}

static void Task_ShiftMon(u8 taskId)
{
    switch (sStorage->state)
    {
    case 0:
        InitMonPlaceChange(2);
        sStorage->state++;
        break;
    case 1:
        if (!DoMonPlaceChange())
        {
            StartDisplayMonMosaicEffect();
            SetPokeStorageTask(Task_PokeStorageMain);
        }
        break;
    }
}

static void Task_WithdrawMon(u8 taskId)
{
    switch (sStorage->state)
    {
    case 0:
        if (CalculatePlayerPartyCount() == PARTY_SIZE)
        {
            PrintMessage(PC_TEXT_PARTY_FULL);
            sStorage->state = 1;
        }
        else
        {
            sub_80CDC18();
            InitMonPlaceChange(0);
            sStorage->state = 2;
        }
        break;
    case 1:
        if (JOY_NEW(A_BUTTON | B_BUTTON | DPAD_ANY))
        {
            ClearBottomWindow();
            SetPokeStorageTask(Task_PokeStorageMain);
        }
        break;
    case 2:
        if (!DoMonPlaceChange())
        {
            SetMovingMonPriority(1);
            SetUpDoShowPartyMenu();
            sStorage->state++;
        }
        break;
    case 3:
        if (!DoShowPartyMenu())
        {
            InitMonPlaceChange(1);
            sStorage->state++;
        }
        break;
    case 4:
        if (!DoMonPlaceChange())
        {
            UpdatePartySlotColors();
            sStorage->state++;
        }
        break;
    case 5:
        SetPokeStorageTask(Task_HidePartyPokemon);
        break;
    }
}

static void Task_DepositMenu(u8 taskId)
{
    u8 boxId;

    switch (sStorage->state)
    {
    case 0:
        PrintMessage(PC_TEXT_DEPOSIT_IN_WHICH_BOX);
        sub_80C77E8(&sStorage->chooseBoxMenu, TAG_TILE_A, TAG_PAL_DAC7, 3, FALSE);
        sub_80C78D4(sDepositBoxId);
        sStorage->state++;
        break;
    case 1:
        boxId = HandleBoxChooseSelectionInput();
        if (boxId == 200)
        {
            // no box chosen yet
        }
        else if (boxId == 201)
        {
            ClearBottomWindow();
            sub_80C78E4();
            sub_80C7890();
            SetPokeStorageTask(Task_PokeStorageMain);
        }
        else
        {
            if (TryStorePartyMonInBox(boxId))
            {
                sDepositBoxId = boxId;
                ClearBottomWindow();
                sub_80C78E4();
                sub_80C7890();
                sStorage->state = 2;
            }
            else
            {
                PrintMessage(PC_TEXT_BOX_IS_FULL);
                sStorage->state = 4;
            }
        }
        break;
    case 2:
        CompactPartySlots();
        CompactPartySprites();
        sStorage->state++;
        break;
    case 3:
        if (!GetNumPartySpritesCompacting())
        {
            sub_80CE22C();
            StartDisplayMonMosaicEffect();
            UpdatePartySlotColors();
            SetPokeStorageTask(Task_PokeStorageMain);
        }
        break;
    case 4:
        if (JOY_NEW(A_BUTTON | B_BUTTON | DPAD_ANY))
        {
            PrintMessage(PC_TEXT_DEPOSIT_IN_WHICH_BOX);
            sStorage->state = 1;
        }
        break;
    }
}

static void Task_ReleaseMon(u8 taskId)
{
    switch (sStorage->state)
    {
    case 0:
        PrintMessage(PC_TEXT_RELEASE_POKE);
        ShowYesNoWindow(1);
        sStorage->state++;
        // fallthrough
    case 1:
        switch (Menu_ProcessInputNoWrapClearOnChoose())
        {
        case MENU_B_PRESSED:
        case  1:
            ClearBottomWindow();
            SetPokeStorageTask(Task_PokeStorageMain);
            break;
        case  0:
            ClearBottomWindow();
            InitCanRelaseMonVars();
            InitReleaseMon();
            sStorage->state++;
            break;
        }
        break;
    case 2:
        RunCanReleaseMon();
        if (!TryHideReleaseMon())
        {
            while (1)
            {
                s8 r0 = RunCanReleaseMon();
                if (r0 == 1)
                {
                    sStorage->state++;
                    break;
                }
                else if (r0 == 0)
                {
                    sStorage->state = 8; // Can't release the mon.
                    break;
                }
            }
        }
        break;
    case 3:
        ReleaseMon();
        RefreshCursorMonData();
        PrintMessage(PC_TEXT_WAS_RELEASED);
        sStorage->state++;
        break;
    case 4:
        if (JOY_NEW(A_BUTTON | B_BUTTON | DPAD_ANY))
        {
            PrintMessage(PC_TEXT_BYE_BYE);
            sStorage->state++;
        }
        break;
    case 5:
        if (JOY_NEW(A_BUTTON | B_BUTTON | DPAD_ANY))
        {
            ClearBottomWindow();
            if (sInPartyMenu)
            {
                CompactPartySlots();
                CompactPartySprites();
                sStorage->state++;
            }
            else
            {
                sStorage->state = 7;
            }
        }
        break;
    case 6:
        if (!GetNumPartySpritesCompacting())
        {
            RefreshDisplayMon();
            StartDisplayMonMosaicEffect();
            UpdatePartySlotColors();
            sStorage->state++;
        }
        break;
    case 7:
        SetPokeStorageTask(Task_PokeStorageMain);
        break;
    case 8:
        // Start "can't release" sequence
        PrintMessage(PC_TEXT_WAS_RELEASED);
        sStorage->state++;
        break;
    case 9:
        if (JOY_NEW(A_BUTTON | B_BUTTON | DPAD_ANY))
        {
            PrintMessage(PC_TEXT_SURPRISE);
            sStorage->state++;
        }
        break;
    case 10:
        if (JOY_NEW(A_BUTTON | B_BUTTON | DPAD_ANY))
        {
            ClearBottomWindow();
            ReshowReleaseMon();
            sStorage->state++;
        }
        break;
    case 11:
        if (!ResetReleaseMonSpritePtr())
        {
            TrySetCursorFistAnim();
            PrintMessage(PC_TEXT_CAME_BACK);
            sStorage->state++;
        }
        break;
    case 12:
        if (JOY_NEW(A_BUTTON | B_BUTTON | DPAD_ANY))
        {
            PrintMessage(PC_TEXT_WORRIED);
            sStorage->state++;
        }
        break;
    case 13:
        if (JOY_NEW(A_BUTTON | B_BUTTON | DPAD_ANY))
        {
            ClearBottomWindow();
            SetPokeStorageTask(Task_PokeStorageMain);
        }
        break;
    }
}

static void Cb_ShowMarkMenu(u8 taskId)
{
    switch (sStorage->state)
    {
    case 0:
        PrintMessage(PC_TEXT_MARK_POKE);
        sStorage->markMenu.markings = sStorage->cursorMonMarkings;
        sub_811FAA4(sStorage->cursorMonMarkings, 0xb0, 0x10);
        sStorage->state++;
        break;
    case 1:
        if (!MonMarkingsMenuHandleInput())
        {
            sub_811FAF8();
            ClearBottomWindow();
            SetMonMarkings(sStorage->markMenu.markings);
            RefreshCursorMonData();
            SetPokeStorageTask(Task_PokeStorageMain);
        }
        break;
    }
}

static void Cb_TakeItemForMoving(u8 taskId)
{
    switch (sStorage->state)
    {
    case 0:
        if (!ItemIsMail(sStorage->cursorMonItem))
        {
            ClearBottomWindow();
            sStorage->state++;
        }
        else
        {
            SetPokeStorageTask(Cb_PrintCantStoreMail);
        }
        break;
    case 1:
        sub_80CFE54(2);
        Item_FromMonToMoving((sInPartyMenu != FALSE) ? CURSOR_AREA_IN_PARTY : CURSOR_AREA_IN_BOX, GetBoxCursorPosition());
        sStorage->state++;
        break;
    case 2:
        if (!sub_80D1218())
        {
            sub_80CFE54(3);
            ClearBottomWindow();
            RefreshDisplayMon();
            PrintCursorMonInfo();
            sStorage->state++;
        }
        break;
    case 3:
        if (!IsDma3ManagerBusyWithBgCopy())
            SetPokeStorageTask(Task_PokeStorageMain);
        break;
    }
}

static void Cb_GiveMovingItemToMon(u8 taskId)
{
    switch (sStorage->state)
    {
    case 0:
        ClearBottomWindow();
        sStorage->state++;
        break;
    case 1:
        sub_80CFE54(2);
        Item_GiveMovingToMon((sInPartyMenu != FALSE) ? CURSOR_AREA_IN_PARTY : CURSOR_AREA_IN_BOX, GetBoxCursorPosition());
        sStorage->state++;
        break;
    case 2:
        if (!sub_80D1218())
        {
            sub_80CFE54(0);
            RefreshDisplayMon();
            PrintCursorMonInfo();
            PrintMessage(PC_TEXT_ITEM_IS_HELD);
            sStorage->state++;
        }
        break;
    case 3:
        if (JOY_NEW(A_BUTTON | B_BUTTON | DPAD_ANY))
        {
            ClearBottomWindow();
            sStorage->state++;
        }
        break;
    case 4:
        if (!IsDma3ManagerBusyWithBgCopy())
            SetPokeStorageTask(Task_PokeStorageMain);
        break;
    }
}

static void Cb_ItemToBag(u8 taskId)
{
    switch (sStorage->state)
    {
    case 0:
        if (!AddBagItem(sStorage->cursorMonItem, 1))
        {
            PlaySE(SE_FAILURE);
            PrintMessage(PC_TEXT_BAG_FULL);
            sStorage->state = 3;
        }
        else
        {
            PlaySE(SE_SELECT);
            Item_TakeMons((sInPartyMenu != FALSE) ? CURSOR_AREA_IN_PARTY : CURSOR_AREA_IN_BOX, GetBoxCursorPosition());
            sStorage->state = 1;
        }
        break;
    case 1:
        if (!sub_80D1218())
        {
            PrintMessage(PC_TEXT_PLACED_IN_BAG);
            sStorage->state = 2;
        }
        break;
    case 2:
        if (JOY_NEW(A_BUTTON | B_BUTTON | DPAD_ANY))
        {
            ClearBottomWindow();
            RefreshDisplayMon();
            PrintCursorMonInfo();
            sStorage->state = 4;
        }
        break;
    case 4:
        if (!IsDma3ManagerBusyWithBgCopy())
            SetPokeStorageTask(Task_PokeStorageMain);
        break;
    case 3:
        if (JOY_NEW(A_BUTTON | B_BUTTON | DPAD_ANY))
        {
            ClearBottomWindow();
            SetPokeStorageTask(Task_PokeStorageMain);
        }
        break;
    }
}

static void Cb_SwitchSelectedItem(u8 taskId)
{
    switch (sStorage->state)
    {
    case 0:
        if (!ItemIsMail(sStorage->cursorMonItem))
        {
            ClearBottomWindow();
            sStorage->state++;
        }
        else
        {
            SetPokeStorageTask(Cb_PrintCantStoreMail);
        }
        break;
    case 1:
        sub_80CFE54(2);
        Item_SwitchMonsWithMoving((sInPartyMenu != FALSE) ? CURSOR_AREA_IN_PARTY : CURSOR_AREA_IN_BOX, GetBoxCursorPosition());
        sStorage->state++;
        break;
    case 2:
        if (!sub_80D1218())
        {
            sub_80CFE54(3);
            RefreshDisplayMon();
            PrintCursorMonInfo();
            PrintMessage(PC_TEXT_CHANGED_TO_ITEM);
            sStorage->state++;
        }
        break;
    case 3:
        if (JOY_NEW(A_BUTTON | B_BUTTON | DPAD_ANY))
        {
            ClearBottomWindow();
            sStorage->state++;
        }
        break;
    case 4:
        if (!IsDma3ManagerBusyWithBgCopy())
            SetPokeStorageTask(Task_PokeStorageMain);
        break;
    }
}

static void Cb_ShowItemInfo(u8 taskId)
{
    switch (sStorage->state)
    {
    case 0:
        ClearBottomWindow();
        sStorage->state++;
        break;
    case 1:
        if (!IsDma3ManagerBusyWithBgCopy())
        {
            PlaySE(SE_WIN_OPEN);
            PrintItemDescription();
            sub_80D1818();
            sStorage->state++;
        }
        break;
    case 2:
        if (!sub_80D184C())
            sStorage->state++;
        break;
    case 3:
        if (!IsDma3ManagerBusyWithBgCopy())
            sStorage->state++;
        break;
    case 4:
        if (JOY_NEW(A_BUTTON | B_BUTTON | DPAD_ANY))
        {
            PlaySE(SE_WIN_OPEN);
            sStorage->state++;
        }
        break;
    case 5:
        if (!sub_80D18E4())
            sStorage->state++;
        break;
    case 6:
        if (!IsDma3ManagerBusyWithBgCopy())
            SetPokeStorageTask(Task_PokeStorageMain);
        break;
    }
}

static void Cb_CloseBoxWhileHoldingItem(u8 taskId)
{
    switch (sStorage->state)
    {
    case 0:
        PlaySE(SE_SELECT);
        PrintMessage(PC_TEXT_PUT_IN_BAG);
        ShowYesNoWindow(0);
        sStorage->state = 1;
        break;
    case 1:
        switch (Menu_ProcessInputNoWrapClearOnChoose())
        {
        case MENU_B_PRESSED:
        case 1:
            ClearBottomWindow();
            SetPokeStorageTask(Task_PokeStorageMain);
            break;
        case 0:
            if (AddBagItem(sStorage->movingItem, 1) == TRUE)
            {
                ClearBottomWindow();
                sStorage->state = 3;
            }
            else
            {
                PrintMessage(PC_TEXT_BAG_FULL);
                sStorage->state = 2;
            }
            break;
        }
        break;
    case 2:
        if (JOY_NEW(A_BUTTON | B_BUTTON | DPAD_ANY))
        {
            ClearBottomWindow();
            sStorage->state = 5;
        }
        break;
    case 3:
        sub_80D1194();
        sStorage->state = 4;
        break;
    case 4:
        if (!sub_80D1218())
        {
            sub_80CFE54(0);
            SetPokeStorageTask(Task_PokeStorageMain);
        }
        break;
    case 5:
        if (!IsDma3ManagerBusyWithBgCopy())
            SetPokeStorageTask(Task_PokeStorageMain);
        break;
    }
}

static void Cb_HandleMovingMonFromParty(u8 taskId)
{
    switch (sStorage->state)
    {
    case 0:
        CompactPartySlots();
        CompactPartySprites();
        sStorage->state++;
        break;
    case 1:
        if (!GetNumPartySpritesCompacting())
        {
            UpdatePartySlotColors();
            SetPokeStorageTask(Task_PokeStorageMain);
        }
        break;
    }
}

static void Cb_PrintCantStoreMail(u8 taskId)
{
    switch (sStorage->state)
    {
    case 0:
        PrintMessage(PC_TEXT_CANT_STORE_MAIL);
        sStorage->state++;
        break;
    case 1:
        if (!IsDma3ManagerBusyWithBgCopy())
            sStorage->state++;
        break;
    case 2:
        if (JOY_NEW(A_BUTTON | B_BUTTON | DPAD_ANY))
        {
            ClearBottomWindow();
            sStorage->state++;
        }
        break;
    case 3:
        if (!IsDma3ManagerBusyWithBgCopy())
            SetPokeStorageTask(Task_PokeStorageMain);
        break;
    }
}

static void Task_HandleBoxOptions(u8 taskId)
{
    switch (sStorage->state)
    {
    case 0:
        PrintMessage(PC_TEXT_WHAT_YOU_DO);
        AddMenu();
        sStorage->state++;
        break;
    case 1:
        if (sub_80D00A8())
            return;
        sStorage->state++;
    case 2:
        switch (sub_80D00AC())
        {
        case -1:
        case  0:
            AnimateBoxScrollArrows(TRUE);
            ClearBottomWindow();
            SetPokeStorageTask(Task_PokeStorageMain);
            break;
        case 11:
            PlaySE(SE_SELECT);
            SetPokeStorageTask(Cb_NameBox);
            break;
        case 10:
            PlaySE(SE_SELECT);
            ClearBottomWindow();
            SetPokeStorageTask(Cb_HandleWallpapers);
            break;
        case 9:
            PlaySE(SE_SELECT);
            ClearBottomWindow();
            SetPokeStorageTask(Cb_JumpBox);
            break;
        }
        break;
    }
}

static void Cb_HandleWallpapers(u8 taskId)
{
    switch (sStorage->state)
    {
    case 0:
        AddWallpaperSetsMenu();
        PrintMessage(PC_TEXT_PICK_A_THEME);
        sStorage->state++;
        break;
    case 1:
        if (!sub_80D00A8())
             sStorage->state++;
        break;
    case 2:
        sStorage->wallpaperSetId = sub_80D00AC();
        switch (sStorage->wallpaperSetId)
        {
        case -1:
            AnimateBoxScrollArrows(TRUE);
            ClearBottomWindow();
            SetPokeStorageTask(Task_PokeStorageMain);
            break;
        case 18 ... 21:
            PlaySE(SE_SELECT);
            sub_80D013C();
            sStorage->wallpaperSetId -= 18;
            sStorage->state++;
            break;
        // New wallpaper from Walda.
        case 22:
            PlaySE(SE_SELECT);
            sStorage->wallpaperId = 16;
            sub_80D013C();
            ClearBottomWindow();
            sStorage->state = 6;
            break;
        }
        break;
    case 3:
        if (!IsDma3ManagerBusyWithBgCopy())
        {
            AddWallpapersMenu(sStorage->wallpaperSetId);
            PrintMessage(PC_TEXT_PICK_A_WALLPAPER);
            sStorage->state++;
        }
        break;
    case 4:
        sStorage->wallpaperId = sub_80D00AC();
        switch (sStorage->wallpaperId)
        {
        case -2:
            break;
        case -1:
            ClearBottomWindow();
            sStorage->state = 0;
            break;
        default:
            PlaySE(SE_SELECT);
            ClearBottomWindow();
            sStorage->wallpaperId -= 23;
            SetWallpaperForCurrentBox(sStorage->wallpaperId);
            sStorage->state++;
            break;
        }
        break;
    case 5:
        if (!DoWallpaperGfxChange())
        {
            AnimateBoxScrollArrows(TRUE);
            SetPokeStorageTask(Task_PokeStorageMain);
        }
        break;
    case 6:
        if (!IsDma3ManagerBusyWithBgCopy())
        {
            SetWallpaperForCurrentBox(sStorage->wallpaperId);
            sStorage->state = 5;
        }
        break;
    }
}

static void Cb_JumpBox(u8 taskId)
{
    switch (sStorage->state)
    {
    case 0:
        PrintMessage(PC_TEXT_JUMP_TO_WHICH_BOX);
        sub_80C77E8(&sStorage->chooseBoxMenu, TAG_TILE_A, TAG_PAL_DAC7, 3, FALSE);
        sub_80C78D4(StorageGetCurrentBox());
        sStorage->state++;
        break;
    case 1:
        sStorage->newCurrBoxId = HandleBoxChooseSelectionInput();
        switch (sStorage->newCurrBoxId)
        {
        case 200:
            break;
        default:
            ClearBottomWindow();
            sub_80C78E4();
            sub_80C7890();
            if (sStorage->newCurrBoxId == 201 || sStorage->newCurrBoxId == StorageGetCurrentBox())
            {
                AnimateBoxScrollArrows(TRUE);
                SetPokeStorageTask(Task_PokeStorageMain);
            }
            else
            {
                sStorage->state++;
            }
            break;
        }
        break;
    case 2:
        SetUpScrollToBox(sStorage->newCurrBoxId);
        sStorage->state++;
        break;
    case 3:
        if (!ScrollToBox())
        {
            SetCurrentBox(sStorage->newCurrBoxId);
            SetPokeStorageTask(Task_PokeStorageMain);
        }
        break;
    }
}

static void Cb_NameBox(u8 taskId)
{
    switch (sStorage->state)
    {
    case 0:
        sub_80CE760();
        BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 16, RGB_BLACK);
        sStorage->state++;
        break;
    case 1:
        if (!UpdatePaletteFade())
        {
            sWhichToReshow = 1;
            sStorage->screenChangeType = SCREEN_CHANGE_NAME_BOX;
            SetPokeStorageTask(Cb_ChangeScreen);
        }
        break;
    }
}

static void Cb_ShowMonSummary(u8 taskId)
{
    switch (sStorage->state)
    {
    case 0:
        sub_80CE7E8();
        BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 16, RGB_BLACK);
        sStorage->state++;
        break;
    case 1:
        if (!UpdatePaletteFade())
        {
            sWhichToReshow = 0;
            sStorage->screenChangeType = SCREEN_CHANGE_SUMMARY_SCREEN;
            SetPokeStorageTask(Cb_ChangeScreen);
        }
        break;
    }
}

static void Cb_GiveItemFromBag(u8 taskId)
{
    switch (sStorage->state)
    {
    case 0:
        BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 16, RGB_BLACK);
        sStorage->state++;
        break;
    case 1:
        if (!UpdatePaletteFade())
        {
            sWhichToReshow = 2;
            sStorage->screenChangeType = SCREEN_CHANGE_ITEM_FROM_BAG;
            SetPokeStorageTask(Cb_ChangeScreen);
        }
        break;
    }
}

static void Task_OnCloseBoxPressed(u8 taskId)
{
    switch (sStorage->state)
    {
    case 0:
        if (IsMonBeingMoved())
        {
            PlaySE(SE_FAILURE);
            PrintMessage(PC_TEXT_HOLDING_POKE);
            sStorage->state = 1;
        }
        else if (IsActiveItemMoving())
        {
            SetPokeStorageTask(Cb_CloseBoxWhileHoldingItem);
        }
        else
        {
            PlaySE(SE_SELECT);
            PrintMessage(PC_TEXT_EXIT_BOX);
            ShowYesNoWindow(0);
            sStorage->state = 2;
        }
        break;
    case 1:
        if (JOY_NEW(A_BUTTON | B_BUTTON | DPAD_ANY))
        {
            ClearBottomWindow();
            SetPokeStorageTask(Task_PokeStorageMain);
        }
        break;
    case 2:
        switch (Menu_ProcessInputNoWrapClearOnChoose())
        {
        case MENU_B_PRESSED:
        case 1:
            ClearBottomWindow();
            SetPokeStorageTask(Task_PokeStorageMain);
            break;
        case 0:
            PlaySE(SE_PC_OFF);
            ClearBottomWindow();
            sStorage->state++;
            break;
        }
        break;
    case 3:
        ComputerScreenCloseEffect(20, 0, 1);
        sStorage->state++;
        break;
    case 4:
        if (!IsComputerScreenCloseEffectActive())
        {
            UpdateBoxToSendMons();
            gPlayerPartyCount = CalculatePlayerPartyCount();
            sStorage->screenChangeType = SCREEN_CHANGE_EXIT_BOX;
            SetPokeStorageTask(Cb_ChangeScreen);
        }
        break;
    }
}

static void Task_OnBPressed(u8 taskId)
{
    switch (sStorage->state)
    {
    case 0:
        if (IsMonBeingMoved())
        {
            PlaySE(SE_FAILURE);
            PrintMessage(PC_TEXT_HOLDING_POKE);
            sStorage->state = 1;
        }
        else if (IsActiveItemMoving())
        {
            SetPokeStorageTask(Cb_CloseBoxWhileHoldingItem);
        }
        else
        {
            PlaySE(SE_SELECT);
            PrintMessage(PC_TEXT_CONTINUE_BOX);
            ShowYesNoWindow(0);
            sStorage->state = 2;
        }
        break;
    case 1:
        if (JOY_NEW(A_BUTTON | B_BUTTON | DPAD_ANY))
        {
            ClearBottomWindow();
            SetPokeStorageTask(Task_PokeStorageMain);
        }
        break;
    case 2:
        switch (Menu_ProcessInputNoWrapClearOnChoose())
        {
        case 0:
            ClearBottomWindow();
            SetPokeStorageTask(Task_PokeStorageMain);
            break;
        case 1:
        case MENU_B_PRESSED:
            PlaySE(SE_PC_OFF);
            ClearBottomWindow();
            sStorage->state++;
            break;
        }
        break;
    case 3:
        ComputerScreenCloseEffect(20, 0, 0);
        sStorage->state++;
        break;
    case 4:
        if (!IsComputerScreenCloseEffectActive())
        {
            UpdateBoxToSendMons();
            gPlayerPartyCount = CalculatePlayerPartyCount();
            sStorage->screenChangeType = SCREEN_CHANGE_EXIT_BOX;
            SetPokeStorageTask(Cb_ChangeScreen);
        }
        break;
    }
}

static void Cb_ChangeScreen(u8 taskId)
{
    struct BoxPokemon *boxMons;
    u8 mode, monIndex, maxMonIndex;
    u8 screenChangeType = sStorage->screenChangeType;

    if (sStorage->boxOption == OPTION_MOVE_ITEMS && IsActiveItemMoving() == TRUE)
        sMovingItemId = GetMovingItem();
    else
        sMovingItemId = ITEM_NONE;

    switch (screenChangeType)
    {
    case SCREEN_CHANGE_EXIT_BOX:
    default:
        FreePSSData();
        SetMainCallback2(Cb2_ExitPSS);
        break;
    case SCREEN_CHANGE_SUMMARY_SCREEN:
        boxMons = sStorage->summaryMon.box;
        monIndex = sStorage->summaryStartPos;
        maxMonIndex = sStorage->summaryMaxPos;
        mode = sStorage->pokemonSummaryScreenMode;
        FreePSSData();
        if (mode == PSS_MODE_NORMAL && boxMons == &gUnknown_02039D14.box)
            ShowPokemonSummaryScreenSet40EF(mode, boxMons, monIndex, maxMonIndex, CB2_ReturnToPokeStorage);
        else
            ShowPokemonSummaryScreen(mode, boxMons, monIndex, maxMonIndex, CB2_ReturnToPokeStorage);
        break;
    case SCREEN_CHANGE_NAME_BOX:
        FreePSSData();
        DoNamingScreen(NAMING_SCREEN_BOX, GetBoxNamePtr(StorageGetCurrentBox()), 0, 0, 0, CB2_ReturnToPokeStorage, 0);
        break;
    case SCREEN_CHANGE_ITEM_FROM_BAG:
        FreePSSData();
        GoToBagMenu(ITEMMENULOCATION_PCBOX, 0, CB2_ReturnToPokeStorage);
        break;
    }

    DestroyTask(taskId);
}

static void GiveChosenBagItem(void)
{
    u16 item = gSpecialVar_ItemId;

    if (item != 0)
    {
        u8 id = GetBoxCursorPosition();

        if (sInPartyMenu)
            SetMonData(&gPlayerParty[id], MON_DATA_HELD_ITEM, &item);
        else
            SetCurrentBoxMonData(id, MON_DATA_HELD_ITEM, &item);

        RemoveBagItem(item, 1);
    }
}

static void FreePSSData(void)
{
    sub_80D25F0();
    sub_80D01B8();
    FREE_AND_SET_NULL(sStorage);
    FreeAllWindowBuffers();
}

static void SetScrollingBackground(void)
{
    SetGpuReg(REG_OFFSET_BG3CNT, BGCNT_PRIORITY(3) | BGCNT_CHARBASE(3) | BGCNT_16COLOR | BGCNT_SCREENBASE(31));
    DecompressAndLoadBgGfxUsingHeap(3, gPokemonStorageScrollingBGTileset, 0, 0, 0);
    LZ77UnCompVram(gPokemonStorageScrollingBGTilemap, (void *)BG_SCREEN_ADDR(31));
}

static void ScrollBackground(void)
{
    ChangeBgX(3, 128, 1);
    ChangeBgY(3, 128, 2);
}

static void LoadPSSMenuGfx(void)
{
    InitBgsFromTemplates(0, sBgTemplates, ARRAY_COUNT(sBgTemplates));
    DecompressAndLoadBgGfxUsingHeap(1, gPSSMenu_Gfx, 0, 0, 0);
    LZ77UnCompWram(sDisplayMenu_Tilemap, sStorage->displayMenuTilemapBuffer);
    SetBgTilemapBuffer(1, sStorage->displayMenuTilemapBuffer);
    ShowBg(1);
    ScheduleBgCopyTilemapToVram(1);
}

static bool8 InitPSSWindows(void)
{
    if (!InitWindows(gUnknown_08572714))
    {
        return FALSE;
    }
    else
    {
        DeactivateAllTextPrinters();
        return TRUE;
    }
}

static void LoadWaveformSpritePalette(void)
{
    LoadSpritePalette(&gWaveformSpritePalette);
}

static void InitPalettesAndSprites(void)
{
    LoadPalette(gUnknown_085723DC, 0, 0x20);
    LoadPalette(gUnknown_085723FC, 0x20, 0x20);
    LoadPalette(gUnknown_085726F4, 0xF0, 0x20);
    if (sStorage->boxOption != OPTION_MOVE_ITEMS)
        LoadPalette(gUnknown_0857241C, 0x30, 0x20);
    else
        LoadPalette(gUnknown_0857243C, 0x30, 0x20);

    SetGpuReg(REG_OFFSET_BG1CNT, BGCNT_PRIORITY(1) | BGCNT_CHARBASE(1) | BGCNT_16COLOR | BGCNT_SCREENBASE(30));
    LoadCursorMonSprite();
    sub_80CA154();
    sub_80CA1C4();
    RefreshCursorMonData();
}

static void sub_80CA154(void)
{
    sStorage->markingComboSprite = sub_811FFB4(TAG_TILE_10, TAG_PAL_DAC8, NULL);
    sStorage->markingComboSprite->oam.priority = 1;
    sStorage->markingComboSprite->subpriority = 1;
    sStorage->markingComboSprite->pos1.x = 40;
    sStorage->markingComboSprite->pos1.y = 150;
    sStorage->markingComboTilesPtr = (void*) OBJ_VRAM0 + 32 * GetSpriteTileStartByTag(TAG_TILE_10);
}

static void sub_80CA1C4(void)
{
    u16 i;
    struct SpriteSheet sheet = gWaveformSpriteSheet;

    LoadSpriteSheet(&sheet);
    for (i = 0; i < 2; i++)
    {
        u8 spriteId = CreateSprite(&sSpriteTemplate_Waveform, i * 63 + 8, 9, 2);
        sStorage->waveformSprites[i] = &gSprites[spriteId];
    }
}

static void RefreshCursorMonData(void)
{
    LoadCursorMonGfx(sStorage->cursorMonSpecies, sStorage->cursorMonPersonality, sStorage->cursorMonFormId);
    PrintCursorMonInfo();
    sub_80CA65C();
    ScheduleBgCopyTilemapToVram(0);
}

static void StartDisplayMonMosaicEffect(void)
{
    RefreshCursorMonData();
    if (sStorage->cursorMonSprite)
    {
        sStorage->cursorMonSprite->oam.mosaic = TRUE;
        sStorage->cursorMonSprite->data[0] = 10;
        sStorage->cursorMonSprite->data[1] = 1;
        sStorage->cursorMonSprite->callback = sub_80CA2D0;
        SetGpuReg(REG_OFFSET_MOSAIC, (sStorage->cursorMonSprite->data[0] << 12) | (sStorage->cursorMonSprite->data[0] << 8));
    }
}

static u8 sub_80CA2B8(void)
{
    return sStorage->cursorMonSprite->oam.mosaic;
}

static void sub_80CA2D0(struct Sprite *sprite)
{
    sprite->data[0] -= sprite->data[1];
    if (sprite->data[0] < 0)
        sprite->data[0] = 0;
    SetGpuReg(REG_OFFSET_MOSAIC, (sprite->data[0] << 12) | (sprite->data[0] << 8));
    if (sprite->data[0] == 0)
    {
        sprite->oam.mosaic = FALSE;
        sprite->callback = SpriteCallbackDummy;
    }
}

static void LoadCursorMonSprite(void)
{
    u16 i;
    u16 tileStart;
    u8 palSlot;
    u8 spriteId;
    struct SpriteSheet sheet = {sStorage->tileBuffer, 0x800, TAG_TILE_2};
    struct SpritePalette palette = {sStorage->displayMonPalBuffer, TAG_PAL_DAC6};
    struct SpriteTemplate template = sSpriteTemplate_CursorMon;

    for (i = 0; i < 0x800; i++)
        sStorage->tileBuffer[i] = 0;
    for (i = 0; i < 0x10; i++)
        sStorage->displayMonPalBuffer[i] = 0;

    sStorage->cursorMonSprite = NULL;

    do
    {
        tileStart = LoadSpriteSheet(&sheet);
        if (tileStart == 0)
            break;

        palSlot = LoadSpritePalette(&palette);
        if (palSlot == 0xFF)
            break;

        spriteId = CreateSprite(&template, 40, 48, 0);
        if (spriteId == MAX_SPRITES)
            break;

        sStorage->cursorMonSprite = &gSprites[spriteId];
        sStorage->displayMonPalOffset = palSlot * 16 + 0x100;
        sStorage->displayMonTilePtr = (void*) OBJ_VRAM0 + tileStart * 32;
    } while (0);

    if (sStorage->cursorMonSprite == NULL)
    {
        FreeSpriteTilesByTag(TAG_TILE_2);
        FreeSpritePaletteByTag(TAG_PAL_DAC6);
    }
}

static void LoadCursorMonGfx(u16 species, u32 pid, u8 formId)
{
    struct Pokemon *mon;
    u16 formSpeciesId = GetFormSpeciesId(species, formId);
    if (sStorage->cursorMonSprite == NULL)
        return;

    if (species != SPECIES_NONE)
    {
        LoadSpecialPokePic(&gMonFrontPicTable[formSpeciesId], sStorage->tileBuffer, formSpeciesId, pid, TRUE);
        LZ77UnCompWram(sStorage->cursorMonPalette, sStorage->displayMonPalBuffer);
        CpuCopy32(sStorage->tileBuffer, sStorage->displayMonTilePtr, 0x800);
        LoadPalette(sStorage->displayMonPalBuffer, sStorage->displayMonPalOffset, 0x20);
        //Custom Palette Stuff
        BoxMonAtToMon(StorageGetCurrentBox(), sBoxCursorPosition, &sStorage->tempMon);
        SetCustomMonPalette(&gPlttBufferUnfaded[sStorage->displayMonPalOffset], &sStorage->tempMon);
        SetCustomMonPalette(&gPlttBufferFaded[sStorage->displayMonPalOffset], &sStorage->tempMon);

        sStorage->cursorMonSprite->invisible = FALSE;
    }
    else
    {
        sStorage->cursorMonSprite->invisible = TRUE;
    }
}

static void PrintCursorMonInfo(void)
{
    FillWindowPixelBuffer(0, PIXEL_FILL(1));
    if (sStorage->boxOption != OPTION_MOVE_ITEMS)
    {
        AddTextPrinterParameterized(0, 1, sStorage->cursorMonNickText, 6, 0, TEXT_SPEED_FF, NULL);
        AddTextPrinterParameterized(0, 2, sStorage->cursorMonSpeciesName, 6, 15, TEXT_SPEED_FF, NULL);
        AddTextPrinterParameterized(0, 2, sStorage->cursorMonGenderLvlText, 10, 29, TEXT_SPEED_FF, NULL);
        AddTextPrinterParameterized(0, 0, sStorage->cursorMonItemName, 6, 43, TEXT_SPEED_FF, NULL);
    }
    else
    {
        AddTextPrinterParameterized(0, 0, sStorage->cursorMonItemName, 6, 0, TEXT_SPEED_FF, NULL);
        AddTextPrinterParameterized(0, 1, sStorage->cursorMonNickText, 6, 13, TEXT_SPEED_FF, NULL);
        AddTextPrinterParameterized(0, 2, sStorage->cursorMonSpeciesName, 6, 28, TEXT_SPEED_FF, NULL);
        AddTextPrinterParameterized(0, 2, sStorage->cursorMonGenderLvlText, 10, 42, TEXT_SPEED_FF, NULL);
    }

    CopyWindowToVram(0, 2);
    if (sStorage->cursorMonSpecies != SPECIES_NONE)
    {
        sub_8120084(sStorage->cursorMonMarkings, sStorage->markingComboTilesPtr);
        sStorage->markingComboSprite->invisible = FALSE;
    }
    else
    {
        sStorage->markingComboSprite->invisible = TRUE;
    }
}

static void sub_80CA65C(void)
{
    u16 i;

    if (sStorage->cursorMonSpecies != SPECIES_NONE)
    {
        sub_80D27AC(0, 0, 0, 8, 2);
        for (i = 0; i < 2; i++)
            StartSpriteAnimIfDifferent(sStorage->waveformSprites[i], i * 2 + 1);
    }
    else
    {
        sub_80D27AC(0, 0, 2, 8, 2);
        for (i = 0; i < 2; i++)
            StartSpriteAnim(sStorage->waveformSprites[i], i * 2);
    }

    sub_80D2918(0);
    ScheduleBgCopyTilemapToVram(1);
}

static void InitSupplementalTilemaps(void)
{
    LZ77UnCompWram(gUnknown_08DD36C8, sStorage->partyMenuTilemapBuffer);
    LoadPalette(gPSSMenu_Pal, 0x10, 0x20);
    TilemapUtil_SetMap(1, 1, sStorage->partyMenuTilemapBuffer, 12, 22);
    TilemapUtil_SetMap(2, 1, gUnknown_0857245C, 9, 4);
    TilemapUtil_SetPos(1, 10, 0);
    TilemapUtil_SetPos(2, 21, 0);
    sub_80CAA74();
    if (sInPartyMenu)
    {
        sub_80CA984(TRUE);
        CreatePartyMonsSprites(TRUE);
        sub_80D2918(2);
        sub_80D2918(1);
    }
    else
    {
        sub_80D27AC(1, 0, 20, 12, 2);
        sub_80CA984(TRUE);
        sub_80D2918(1);
        sub_80D2918(2);
    }

    ScheduleBgCopyTilemapToVram(1);
    sStorage->closeBoxFlashing = 0;
}

static void SetUpShowPartyMenu(void)
{
    sStorage->partyMenuUnused1 = 20;
    sStorage->partyMenuY = 2;
    sStorage->partyMenuMoveTimer = 0;
    CreatePartyMonsSprites(FALSE);
}

static bool8 ShowPartyMenu(void)
{
    if (sStorage->partyMenuMoveTimer == 20)
        return FALSE;

    sStorage->partyMenuUnused1--;
    sStorage->partyMenuY++;
    sub_80D27F4(1, 3, 1);
    sub_80D2918(1);
    ScheduleBgCopyTilemapToVram(1);
    MovePartySprites(8);
    if (++sStorage->partyMenuMoveTimer == 20)
    {
        sInPartyMenu = TRUE;
        return FALSE;
    }
    else
    {
        return TRUE;
    }
}

static void SetUpHidePartyMenu(void)
{
    sStorage->partyMenuUnused1 = 0;
    sStorage->partyMenuY = 22;
    sStorage->partyMenuMoveTimer = 0;
    if (sStorage->boxOption == OPTION_MOVE_ITEMS)
        sub_80D11CC();
}

static bool8 HidePartyMenu(void)
{
    if (sStorage->partyMenuMoveTimer != 20)
    {
        sStorage->partyMenuUnused1++;
        sStorage->partyMenuY--;
        sub_80D27F4(1, 3, -1);
        sub_80D2918(1);
        FillBgTilemapBufferRect_Palette0(1, 0x100, 10, sStorage->partyMenuY, 12, 1);
        MovePartySprites(-8);
        if (++sStorage->partyMenuMoveTimer != 20)
        {
            ScheduleBgCopyTilemapToVram(1);
            return TRUE;
        }
        else
        {
            sInPartyMenu = FALSE;
            DestroyAllPartyMonIcons();
            CompactPartySlots();
            sub_80D27AC(2, 0, 0, 9, 2);
            sub_80D2918(2);
            ScheduleBgCopyTilemapToVram(1);
            return FALSE;
        }
    }

    return FALSE;
}

static void sub_80CA984(bool8 arg0)
{
    if (arg0)
        sub_80D27AC(2, 0, 0, 9, 2);
    else
        sub_80D27AC(2, 0, 2, 9, 2);

    sub_80D2918(2);
    ScheduleBgCopyTilemapToVram(1);
}

static void sub_80CA9C0(void)
{
    sStorage->closeBoxFlashing = 1;
    sStorage->closeBoxFlashTimer = 30;
    sStorage->closeBoxFlashState = TRUE;
}

static void sub_80CA9EC(void)
{
    if (sStorage->closeBoxFlashing)
    {
        sStorage->closeBoxFlashing = 0;
        sub_80CA984(TRUE);
    }
}

static void UpdateCloseBoxButtonFlash(void)
{
    if (sStorage->closeBoxFlashing && ++sStorage->closeBoxFlashTimer > 30)
    {
        sStorage->closeBoxFlashTimer = 0;
        sStorage->closeBoxFlashState = (sStorage->closeBoxFlashState == FALSE);
        sub_80CA984(sStorage->closeBoxFlashState);
    }
}

static void sub_80CAA74(void)
{
    u8 i;

    for (i = 1; i < PARTY_SIZE; i++)
    {
        s32 species = GetMonData(gPlayerParty + i, MON_DATA_SPECIES);
        sub_80CAAA8(i, (species != SPECIES_NONE));
    }
}

static void sub_80CAAA8(u8 arg0, bool8 isPartyMon)
{
    u16 i, j, index;
    const u16 *data;

    if (isPartyMon)
        data = gUnknown_085724A4;
    else
        data = gUnknown_085724BC;

    index = 3 * (3 * (arg0 - 1) + 1);
    index *= 4;
    index += 7;
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 4; j++)
        {
            sStorage->partyMenuTilemapBuffer[index + j] = data[j];
        }
        data += 4;
        index += 12;
    }
}

static void UpdatePartySlotColors(void)
{
    sub_80CAA74();
    sub_80D27AC(1, 0, 0, 12, 22);
    sub_80D2918(1);
    ScheduleBgCopyTilemapToVram(1);
}

static void SetUpDoShowPartyMenu(void)
{
    sStorage->showPartyMenuState = 0;
    PlaySE(SE_WIN_OPEN);
    SetUpShowPartyMenu();
}

static bool8 DoShowPartyMenu(void)
{
    switch (sStorage->showPartyMenuState)
    {
    case 0:
        if (!ShowPartyMenu())
        {
            sub_80CDBA0();
            sStorage->showPartyMenuState++;
        }
        break;
    case 1:
        if (!sub_80CD554())
        {
            if (sStorage->setMosaic)
                StartDisplayMonMosaicEffect();
            sStorage->showPartyMenuState++;
        }
        break;
    case 2:
        return FALSE;
    }
    return TRUE;
}

static void UpdateBoxToSendMons(void)
{
    if (sLastUsedBox != StorageGetCurrentBox())
    {
        FlagClear(FLAG_SHOWN_BOX_WAS_FULL_MESSAGE);
        VarSet(VAR_PC_BOX_TO_SEND_MON, StorageGetCurrentBox());
    }
}

static void InitPokeStorageBg0(void)
{
    SetGpuReg(REG_OFFSET_BG0CNT, BGCNT_PRIORITY(0) | BGCNT_CHARBASE(0) | BGCNT_SCREENBASE(29));
    LoadUserWindowBorderGfx(1, 2, 208);
    FillBgTilemapBufferRect(0, 0, 0, 0, 32, 20, 17);
    CopyBgTilemapBufferToVram(0);
}

static void PrintMessage(u8 id)
{
    u8 *txtPtr;

    DynamicPlaceholderTextUtil_Reset();
    switch (gPCStorageActionTexts[id].format)
    {
    case PC_TEXT_FMT_NORMAL:
        break;
    case PC_TEXT_FMT_MON_NAME_1:
    case PC_TEXT_FMT_MON_NAME_2:
    case PC_TEXT_FMT_MON_NAME_3:
        DynamicPlaceholderTextUtil_SetPlaceholderPtr(0, sStorage->cursorMonNick);
        break;
    case PC_TEXT_FMT_MON_NAME_4:
    case PC_TEXT_FMT_MON_NAME_5:
    case PC_TEXT_FMT_MON_NAME_6:
        DynamicPlaceholderTextUtil_SetPlaceholderPtr(0, sStorage->releaseMonName);
        break;
    case PC_TEXT_FMT_ITEM_NAME:
        if (IsActiveItemMoving())
            txtPtr = StringCopy(sStorage->itemName, GetMovingItemName());
        else
            txtPtr = StringCopy(sStorage->itemName, sStorage->cursorMonItemName);

        while (*(txtPtr - 1) == CHAR_SPACE)
            txtPtr--;

        *txtPtr = EOS;
        DynamicPlaceholderTextUtil_SetPlaceholderPtr(0, sStorage->itemName);
        break;
    }

    DynamicPlaceholderTextUtil_ExpandPlaceholders(sStorage->messageText, gPCStorageActionTexts[id].text);
    FillWindowPixelBuffer(1, PIXEL_FILL(1));
    AddTextPrinterParameterized(1, 1, sStorage->messageText, 0, 1, TEXT_SPEED_FF, NULL);
    DrawTextBorderOuter(1, 2, 14);
    PutWindowTilemap(1);
    CopyWindowToVram(1, 2);
    ScheduleBgCopyTilemapToVram(0);
}

static void ShowYesNoWindow(s8 cursorPos)
{
    CreateYesNoMenu(&sYesNoWindowTemplate, 11, 14, 0);
    Menu_MoveCursorNoWrapAround(cursorPos);
}

static void ClearBottomWindow(void)
{
    ClearStdWindowAndFrameToTransparent(1, FALSE);
    ScheduleBgCopyTilemapToVram(0);
}

static void AddWallpaperSetsMenu(void)
{
    InitMenu();
    SetMenuText(18);
    SetMenuText(19);
    SetMenuText(20);
    SetMenuText(21);
    if (IsWaldaWallpaperUnlocked())
        SetMenuText(22);
    AddMenu();
}

static void AddWallpapersMenu(u8 wallpaperSet)
{
    InitMenu();
    switch (wallpaperSet)
    {
    case 0:
        SetMenuText(23);
        SetMenuText(24);
        SetMenuText(25);
        SetMenuText(26);
        break;
    case 1:
        SetMenuText(27);
        SetMenuText(28);
        SetMenuText(29);
        SetMenuText(30);
        break;
    case 2:
        SetMenuText(31);
        SetMenuText(32);
        SetMenuText(33);
        SetMenuText(34);
        break;
    case 3:
        SetMenuText(35);
        SetMenuText(36);
        SetMenuText(37);
        SetMenuText(38);
        break;
    }
    AddMenu();
}

static u8 GetCurrentBoxOption(void)
{
    return sCurrentBoxOption;
}

static void InitCursorItemIcon(void)
{
    if (!IsCursorOnBox())
    {
        if (sInPartyMenu)
            sub_80D0D8C(CURSOR_AREA_IN_PARTY, GetBoxCursorPosition());
        else
            sub_80D0D8C(CURSOR_AREA_IN_BOX, GetBoxCursorPosition());
    }

    if (sMovingItemId != ITEM_NONE)
    {
        sub_80D0F38(sMovingItemId);
        sub_80CFE54(3);
    }
}

static void InitMonIconFields(void)
{
    u16 i;

    LoadMonIconPalettes();
    for (i = 0; i < 40; i++)
        sStorage->numIconsPerSpecies[i] = 0;
    for (i = 0; i < 40; i++)
        sStorage->iconSpeciesList[i] = 0;
    for (i = 0; i < PARTY_SIZE; i++)
        sStorage->partySprites[i] = NULL;
    for (i = 0; i < IN_BOX_COUNT; i++)
        sStorage->boxMonsSprites[i] = NULL;

    sStorage->movingMonSprite = NULL;
    sStorage->unkUnused1 = 0;
}

static u8 GetMonIconPriorityByCursorPos(void)
{
    return (IsCursorInBox() ? 2 : 1);
}

static void CreateMovingMonIcon(void)
{
    u32 personality = GetMonData(&sStorage->movingMon, MON_DATA_PERSONALITY);
    u16 species = GetMonData(&sStorage->movingMon, MON_DATA_SPECIES2);
    u8 formId = GetMonData(&sStorage->movingMon, MON_DATA_FORM_ID);
    u8 priority = GetMonIconPriorityByCursorPos();

    sStorage->movingMonSprite = CreateMonIconSprite(species, personality, 0, 0, priority, 7, formId);
    sStorage->movingMonSprite->callback = SpriteCB_HeldMon;
}

static void InitBoxMonSprites(u8 boxId)
{
    u8 boxPosition;
    u16 i, j, count;
    u16 species;
    u32 personality;
    u8 formId;

    count = 0;
    boxPosition = 0;
    for (i = 0; i < IN_BOX_COLUMNS; i++)
    {
        for (j = 0; j < IN_BOX_ROWS; j++)
        {
            species = GetBoxMonDataAt(boxId, boxPosition, MON_DATA_SPECIES2);
            formId = GetBoxMonDataAt(boxId, boxPosition, MON_DATA_FORM_ID);
            if (species != SPECIES_NONE)
            {
                personality = GetBoxMonDataAt(boxId, boxPosition, MON_DATA_PERSONALITY);
                sStorage->boxMonsSprites[count] = CreateMonIconSprite(species, personality, 8 * (3 * j) + 100, 8 * (3 * i) + 44, 2, 19 - j, formId);
            }
            else
            {
                sStorage->boxMonsSprites[count] = NULL;
            }
            boxPosition++;
            count++;
        }
    }

    if (sStorage->boxOption == OPTION_MOVE_ITEMS)
    {
        for (boxPosition = 0; boxPosition < IN_BOX_COUNT; boxPosition++)
        {
            if (GetBoxMonDataAt(boxId, boxPosition, MON_DATA_HELD_ITEM) == 0)
                sStorage->boxMonsSprites[boxPosition]->oam.objMode = ST_OAM_OBJ_BLEND;
        }
    }
}

static void createBoxMonIconAtPos(u8 boxPosition)
{
    u16 species = GetCurrentBoxMonData(boxPosition, MON_DATA_SPECIES2);
    u8 formId = GetCurrentBoxMonData(boxPosition, MON_DATA_FORM_ID);

    if (species != SPECIES_NONE)
    {
        s16 x = 8 * (3 * (boxPosition % IN_BOX_ROWS)) + 100;
        s16 y = 8 * (3 * (boxPosition / IN_BOX_ROWS)) + 44;
        u32 personality = GetCurrentBoxMonData(boxPosition, MON_DATA_PERSONALITY);

        sStorage->boxMonsSprites[boxPosition] = CreateMonIconSprite(species, personality, x, y, 2, 19 - (boxPosition % IN_BOX_ROWS), formId);
        if (sStorage->boxOption == OPTION_MOVE_ITEMS)
            sStorage->boxMonsSprites[boxPosition]->oam.objMode = ST_OAM_OBJ_BLEND;
    }
}

static void startBoxMonIconsScrollOut(s16 arg0)
{
    u16 i;

    for (i = 0; i < IN_BOX_COUNT; i++)
    {
        if (sStorage->boxMonsSprites[i] != NULL)
        {
            sStorage->boxMonsSprites[i]->data[2] = arg0;
            sStorage->boxMonsSprites[i]->data[4] = 1;
            sStorage->boxMonsSprites[i]->callback = SpriteCB_BoxMonIconScrollOut;
        }
    }
}

static void SpriteCB_BoxMonIconScrollIn(struct Sprite *sprite)
{
    if (sprite->data[1] != 0)
    {
        // Icon moving
        sprite->data[1]--;
        sprite->pos1.x += sprite->data[2];
    }
    else
    {
        // Icon arrived
        sStorage->iconScrollNumIncoming--;
        sprite->pos1.x = sprite->data[3];
        sprite->callback = SpriteCallbackDummy;
    }
}

static void SpriteCB_BoxMonIconScrollOut(struct Sprite *sprite)
{
    if (sprite->data[4] != 0)
    {
        sprite->data[4]--;
    }
    else
    {
        // Icon moving
        sprite->pos1.x += sprite->data[2];
        sprite->data[5] = sprite->pos1.x + sprite->pos2.x;

        // Check if icon offscreen
        if (sprite->data[5] <= 68 || sprite->data[5] >= 252)
            sprite->callback = SpriteCallbackDummy;
    }
}

// Sprites for Pokémon icons are destroyed during
// the box scroll once they've gone offscreen
static void DestroyAllIconsInRow(u8 row)
{
    u16 column;
    u8 boxPosition = row;

    for (column = 0; column < IN_BOX_COLUMNS; column++)
    {
        if (sStorage->boxMonsSprites[boxPosition] != NULL)
        {
            DestroyBoxMonIcon(sStorage->boxMonsSprites[boxPosition]);
            sStorage->boxMonsSprites[boxPosition] = NULL;
        }
        boxPosition += IN_BOX_ROWS;
    }
}

// Create the appearing icons for the incoming scrolling box
static u8 CreateBoxMonIconsInColumn(u8 row, u16 times, s16 xDelta)
{
    s32 i;
    u16 y = 44;
    s16 xDest = 8 * (3 * row) + 100;
    u16 x = xDest - ((times + 1) * xDelta);
    u8 subpriority = 19 - row;
    u8 count = 0;
    u8 boxPosition = row;
	u8 formId;
    if (sStorage->boxOption != OPTION_MOVE_ITEMS)
    {
        for (i = 0; i < IN_BOX_COLUMNS; i++)
        {
            if (sStorage->boxSpecies[boxPosition] != SPECIES_NONE)
            {
				formId = sStorage->boxFormId[boxPosition];
                sStorage->boxMonsSprites[boxPosition] = CreateMonIconSprite(sStorage->boxSpecies[boxPosition],
                                                                                        sStorage->boxPersonalities[boxPosition],
                                                                                        x, y, 2, subpriority, formId); // handle forms
                if (sStorage->boxMonsSprites[boxPosition] != NULL)
                {
                    sStorage->boxMonsSprites[boxPosition]->data[1] = times;
                    sStorage->boxMonsSprites[boxPosition]->data[2] = xDelta;
                    sStorage->boxMonsSprites[boxPosition]->data[3] = xDest;
                    sStorage->boxMonsSprites[boxPosition]->callback = SpriteCB_BoxMonIconScrollIn;
                    count++;
                }
            }
            boxPosition += IN_BOX_ROWS;
            y += 24;
        }
    }
    else
    {
        // Separate case for Move Items mode is used
        // to create the icons with the proper blend
        for (i = 0; i < IN_BOX_COLUMNS; i++)
        {
            if (sStorage->boxSpecies[boxPosition] != SPECIES_NONE)
            {
				formId = sStorage->boxFormId[boxPosition];
                sStorage->boxMonsSprites[boxPosition] = CreateMonIconSprite(sStorage->boxSpecies[boxPosition],
                                                                                        sStorage->boxPersonalities[boxPosition],
                                                                                        x, y, 2, subpriority, formId); // handle forms
                if (sStorage->boxMonsSprites[boxPosition] != NULL)
                {
                    sStorage->boxMonsSprites[boxPosition]->data[1] = times;
                    sStorage->boxMonsSprites[boxPosition]->data[2] = xDelta;
                    sStorage->boxMonsSprites[boxPosition]->data[3] = xDest;
                    sStorage->boxMonsSprites[boxPosition]->callback = SpriteCB_BoxMonIconScrollIn;
                    if (GetBoxMonDataAt(sStorage->incomingBoxId, boxPosition, MON_DATA_HELD_ITEM) == 0)
                        sStorage->boxMonsSprites[boxPosition]->oam.objMode = ST_OAM_OBJ_BLEND;
                    count++;
                }
            }
            boxPosition += IN_BOX_ROWS;
            y += 24;
        }
    }

    return count;
}

static void InitBoxMonIconScroll(u8 boxId, s8 direction)
{
    sStorage->iconScrollState = 0;
    sStorage->iconScrollToBoxId = boxId;
    sStorage->iconScrollDirection = direction;
    sStorage->iconScrollDistance = 32;
    sStorage->iconScrollSpeed = -(6 * direction);
    sStorage->iconScrollNumIncoming = 0;
    GetIncomingBoxMonData(boxId);
    if (direction > 0)
        sStorage->iconScrollCurColumn = 0;
    else
        sStorage->iconScrollCurColumn = IN_BOX_ROWS - 1;

    sStorage->iconScrollPos = (24 * sStorage->iconScrollCurColumn) + 100;
    startBoxMonIconsScrollOut(sStorage->iconScrollSpeed);
}

static bool8 UpdateBoxMonIconScroll(void)
{
    if (sStorage->iconScrollDistance != 0)
        sStorage->iconScrollDistance--;

    switch (sStorage->iconScrollState)
    {
    case 0:
        sStorage->iconScrollPos += sStorage->iconScrollSpeed;
        if (sStorage->iconScrollPos <= 64 || sStorage->iconScrollPos >= 252)
        {
            // A column of icons has gone offscreen, destroy them
            DestroyAllIconsInRow(sStorage->iconScrollCurColumn);
            sStorage->iconScrollPos += sStorage->iconScrollDirection * 24;
            sStorage->iconScrollState++;
        }
        break;
    case 1:
        // Create the new incoming column of icons
        sStorage->iconScrollPos += sStorage->iconScrollSpeed;
        sStorage->iconScrollNumIncoming += CreateBoxMonIconsInColumn(sStorage->iconScrollCurColumn, sStorage->iconScrollDistance, sStorage->iconScrollSpeed);
        if ((sStorage->iconScrollDirection > 0 && sStorage->iconScrollCurColumn == IN_BOX_ROWS - 1)
            || (sStorage->iconScrollDirection < 0 && sStorage->iconScrollCurColumn == 0))
        {
            // Scroll has reached final column
            sStorage->iconScrollState++;
        }
        else
        {
            // Continue scrolling
            sStorage->iconScrollCurColumn += sStorage->iconScrollDirection;
            sStorage->iconScrollState = 0;
        }
        break;
    case 2:
        // Wait to make sure all icons have arrived
        if (sStorage->iconScrollNumIncoming == 0)
        {
            sStorage->iconScrollDistance++;
            return FALSE;
        }
        break;
    default:
        return FALSE;
    }

    return TRUE;
}

static void GetIncomingBoxMonData(u8 boxId)
{
    s32 i, j, boxPosition;

    boxPosition = 0;
    for (i = 0; i < IN_BOX_COLUMNS; i++)
    {
        for (j = 0; j < IN_BOX_ROWS; j++)
        {
            sStorage->boxSpecies[boxPosition] = GetBoxMonDataAt(boxId, boxPosition, MON_DATA_SPECIES2);
            sStorage->boxFormId[boxPosition] = GetBoxMonDataAt(boxId, boxPosition, MON_DATA_FORM_ID);
            if (sStorage->boxSpecies[boxPosition] != SPECIES_NONE)
                sStorage->boxPersonalities[boxPosition] = GetBoxMonDataAt(boxId, boxPosition, MON_DATA_PERSONALITY);
            boxPosition++;
        }
    }

    sStorage->incomingBoxId = boxId;
}

static void DestroyBoxMonIconAtPosition(u8 boxPosition)
{
    if (sStorage->boxMonsSprites[boxPosition] != NULL)
    {
        DestroyBoxMonIcon(sStorage->boxMonsSprites[boxPosition]);
        sStorage->boxMonsSprites[boxPosition] = NULL;
    }
}

static void SetBoxMonIconObjMode(u8 boxPosition, u8 objMode)
{
    if (sStorage->boxMonsSprites[boxPosition] != NULL)
    {
        sStorage->boxMonsSprites[boxPosition]->oam.objMode = objMode;
    }
}

static void CreatePartyMonsSprites(bool8 arg0)
{
    u16 i, count;
    u16 species = GetMonData(&gPlayerParty[0], MON_DATA_SPECIES2);
    u32 personality = GetMonData(&gPlayerParty[0], MON_DATA_PERSONALITY);
    u8 formId = GetMonData(&gPlayerParty[0], MON_DATA_FORM_ID);

    sStorage->partySprites[0] = CreateMonIconSprite(species, personality, 104, 64, 1, 12, formId);
    count = 1;
    for (i = 1; i < PARTY_SIZE; i++)
    {
        species = GetMonData(&gPlayerParty[i], MON_DATA_SPECIES2);
        formId = GetMonData(&gPlayerParty[i], MON_DATA_FORM_ID);

        if (species != SPECIES_NONE)
        {
            personality = GetMonData(&gPlayerParty[i], MON_DATA_PERSONALITY);
            sStorage->partySprites[i] = CreateMonIconSprite(species, personality, 152,  8 * (3 * (i - 1)) + 16, 1, 12, formId);
            count++;
        }
        else
        {
            sStorage->partySprites[i] = NULL;
        }
    }

    if (!arg0)
    {
        for (i = 0; i < count; i++)
        {
            sStorage->partySprites[i]->pos1.y -= 160;
            sStorage->partySprites[i]->invisible = TRUE;
        }
    }

    if (sStorage->boxOption == OPTION_MOVE_ITEMS)
    {
        for (i = 0; i < PARTY_SIZE; i++)
        {
            if (sStorage->partySprites[i] != NULL && GetMonData(&gPlayerParty[i], MON_DATA_HELD_ITEM) == 0)
                sStorage->partySprites[i]->oam.objMode = ST_OAM_OBJ_BLEND;
        }
    }
}

static void CompactPartySprites(void)
{
    u16 i, count;

    sStorage->numPartyToCompact = 0;
    for (i = 0, count = 0; i < PARTY_SIZE; i++)
    {
        if (sStorage->partySprites[i] != NULL)
        {
            if (i != count)
            {
                MovePartySpriteToNextSlot(sStorage->partySprites[i], count);
                sStorage->partySprites[i] = NULL;
                sStorage->numPartyToCompact++;
            }
            count++;
        }
    }
}

static u8 GetNumPartySpritesCompacting(void)
{
    return sStorage->numPartyToCompact;
}

static void MovePartySpriteToNextSlot(struct Sprite *sprite, u16 partyId)
{
    s16 x, y;

    sprite->data[1] = partyId;
    if (partyId == 0)
        x = 104, y = 64;
    else
        x = 152, y = 8 * (3 * (partyId - 1)) + 16;

    sprite->data[2] = (u16)(sprite->pos1.x) * 8;
    sprite->data[3] = (u16)(sprite->pos1.y) * 8;
    sprite->data[4] = ((x * 8) - sprite->data[2]) / 8;
    sprite->data[5] = ((y * 8) - sprite->data[3]) / 8;
    sprite->data[6] = 8;
    sprite->callback = SpriteCB_MovePartyMonToNextSlot;
}

static void SpriteCB_MovePartyMonToNextSlot(struct Sprite *sprite)
{
    if (sprite->data[6] != 0)
    {
        s16 x = sprite->data[2] += sprite->data[4];
        s16 y = sprite->data[3] += sprite->data[5];
        sprite->pos1.x = x / 8u;
        sprite->pos1.y = y / 8u;
        sprite->data[6]--;
    }
    else
    {
        if (sprite->data[1] == 0)
        {
            sprite->pos1.x = 104;
            sprite->pos1.y = 64;
        }
        else
        {
            sprite->pos1.x = 152;
            sprite->pos1.y = 8 * (3 * (sprite->data[1] - 1)) + 16;
        }
        sprite->callback = SpriteCallbackDummy;
        sStorage->partySprites[sprite->data[1]] = sprite;
        sStorage->numPartyToCompact--;
    }
}

static void DestroyMovingMonIcon(void)
{
    if (sStorage->movingMonSprite != NULL)
    {
        DestroyBoxMonIcon(sStorage->movingMonSprite);
        sStorage->movingMonSprite = NULL;
    }
}

static void MovePartySprites(s16 yDelta)
{
    u16 i, posY;

    for (i = 0; i < PARTY_SIZE; i++)
    {
        if (sStorage->partySprites[i] != NULL)
        {
            sStorage->partySprites[i]->pos1.y += yDelta;
            posY = sStorage->partySprites[i]->pos1.y + sStorage->partySprites[i]->pos2.y + sStorage->partySprites[i]->centerToCornerVecY;
            posY += 16;
            if (posY > 192)
                sStorage->partySprites[i]->invisible = TRUE;
            else
                sStorage->partySprites[i]->invisible = FALSE;
        }
    }
}

static void DestroyPartyMonIcon(u8 partyId)
{
    if (sStorage->partySprites[partyId] != NULL)
    {
        DestroyBoxMonIcon(sStorage->partySprites[partyId]);
        sStorage->partySprites[partyId] = NULL;
    }
}

static void DestroyAllPartyMonIcons(void)
{
    u16 i;

    for (i = 0; i < PARTY_SIZE; i++)
    {
        if (sStorage->partySprites[i] != NULL)
        {
            DestroyBoxMonIcon(sStorage->partySprites[i]);
            sStorage->partySprites[i] = NULL;
        }
    }
}

static void SetPartyMonIconObjMode(u8 partyId, u8 objMode)
{
    if (sStorage->partySprites[partyId] != NULL)
    {
        sStorage->partySprites[partyId]->oam.objMode = objMode;
    }
}

static void SetMovingMonSprite(u8 mode, u8 id)
{
    if (mode == MODE_PARTY)
    {
        sStorage->movingMonSprite = sStorage->partySprites[id];
        sStorage->partySprites[id] = NULL;
    }
    else if (mode == MODE_BOX)
    {
        sStorage->movingMonSprite = sStorage->boxMonsSprites[id];
        sStorage->boxMonsSprites[id] = NULL;
    }
    else
    {
        return;
    }

    sStorage->movingMonSprite->callback = SpriteCB_HeldMon;
    sStorage->movingMonSprite->oam.priority = GetMonIconPriorityByCursorPos();
    sStorage->movingMonSprite->subpriority = 7;
}

static void SetPlacedMonSprite(u8 boxId, u8 position)
{
    if (boxId == TOTAL_BOXES_COUNT) // party mon
    {
        sStorage->partySprites[position] = sStorage->movingMonSprite;
        sStorage->partySprites[position]->oam.priority = 1;
        sStorage->partySprites[position]->subpriority = 12;
    }
    else
    {
        sStorage->boxMonsSprites[position] = sStorage->movingMonSprite;
        sStorage->boxMonsSprites[position]->oam.priority = 2;
        sStorage->boxMonsSprites[position]->subpriority = 19 - (position % IN_BOX_ROWS);
    }
    sStorage->movingMonSprite->callback = SpriteCallbackDummy;
    sStorage->movingMonSprite = NULL;
}

static void SaveMonSpriteAtPos(u8 boxId, u8 position)
{
    if (boxId == TOTAL_BOXES_COUNT) // party mon
        sStorage->shiftMonSpritePtr = &sStorage->partySprites[position];
    else
        sStorage->shiftMonSpritePtr = &sStorage->boxMonsSprites[position];

    sStorage->movingMonSprite->callback = SpriteCallbackDummy;
    sStorage->shiftTimer = 0;
}

static bool8 MoveShiftingMons(void)
{
    if (sStorage->shiftTimer == 16)
        return FALSE;

    sStorage->shiftTimer++;
    if (sStorage->shiftTimer & 1)
    {
        (*sStorage->shiftMonSpritePtr)->pos1.y--;
        sStorage->movingMonSprite->pos1.y++;
    }

    (*sStorage->shiftMonSpritePtr)->pos2.x = gSineTable[sStorage->shiftTimer * 8] / 16;
    sStorage->movingMonSprite->pos2.x = -(gSineTable[sStorage->shiftTimer * 8] / 16);
    if (sStorage->shiftTimer == 8)
    {
        sStorage->movingMonSprite->oam.priority = (*sStorage->shiftMonSpritePtr)->oam.priority;
        sStorage->movingMonSprite->subpriority = (*sStorage->shiftMonSpritePtr)->subpriority;
        (*sStorage->shiftMonSpritePtr)->oam.priority = GetMonIconPriorityByCursorPos();
        (*sStorage->shiftMonSpritePtr)->subpriority = 7;
    }

    if (sStorage->shiftTimer == 16)
    {
        struct Sprite *sprite = sStorage->movingMonSprite;
        sStorage->movingMonSprite = (*sStorage->shiftMonSpritePtr);
        *sStorage->shiftMonSpritePtr = sprite;

        sStorage->movingMonSprite->callback = SpriteCB_HeldMon;
        (*sStorage->shiftMonSpritePtr)->callback = SpriteCallbackDummy;
    }

    return TRUE;
}

static void SetReleaseMon(u8 mode, u8 position)
{
    switch (mode)
    {
    case MODE_PARTY:
        sStorage->releaseMonSpritePtr = &sStorage->partySprites[position];
        break;
    case MODE_BOX:
        sStorage->releaseMonSpritePtr = &sStorage->boxMonsSprites[position];
        break;
    case MODE_MOVE:
        sStorage->releaseMonSpritePtr = &sStorage->movingMonSprite;
        break;
    default:
        return;
    }

    if (*sStorage->releaseMonSpritePtr != NULL)
    {
        InitSpriteAffineAnim(*sStorage->releaseMonSpritePtr);
        (*sStorage->releaseMonSpritePtr)->oam.affineMode = ST_OAM_AFFINE_NORMAL;
        (*sStorage->releaseMonSpritePtr)->affineAnims = gSpriteAffineAnimTable_857291C;
        StartSpriteAffineAnim(*sStorage->releaseMonSpritePtr, 0);
    }
}

static bool8 TryHideReleaseMonSprite(void)
{
    if (*sStorage->releaseMonSpritePtr == NULL || (*sStorage->releaseMonSpritePtr)->invisible)
        return FALSE;

    if ((*sStorage->releaseMonSpritePtr)->affineAnimEnded)
        (*sStorage->releaseMonSpritePtr)->invisible = TRUE;

    return TRUE;
}

static void DestroyReleaseMonIcon(void)
{
    if (*sStorage->releaseMonSpritePtr != NULL)
    {
        FreeOamMatrix((*sStorage->releaseMonSpritePtr)->oam.matrixNum);
        DestroyBoxMonIcon(*sStorage->releaseMonSpritePtr);
        *sStorage->releaseMonSpritePtr = NULL;
    }
}

static void ReshowReleaseMon(void)
{
    if (*sStorage->releaseMonSpritePtr != NULL)
    {
        (*sStorage->releaseMonSpritePtr)->invisible = FALSE;
        StartSpriteAffineAnim(*sStorage->releaseMonSpritePtr, 1);
    }
}

static bool8 ResetReleaseMonSpritePtr(void)
{
    if (sStorage->releaseMonSpritePtr == NULL)
        return FALSE;

    if ((*sStorage->releaseMonSpritePtr)->affineAnimEnded)
        sStorage->releaseMonSpritePtr = NULL;

    return TRUE;
}

static void SetMovingMonPriority(u8 priority)
{
    sStorage->movingMonSprite->oam.priority = priority;
}

static void SpriteCB_HeldMon(struct Sprite *sprite)
{
    sprite->pos1.x = sStorage->cursorSprite->pos1.x;
    sprite->pos1.y = sStorage->cursorSprite->pos1.y + sStorage->cursorSprite->pos2.y + 4;
}

#define MAX_MON_ICONS 40

static u16 TryLoadMonIconTiles(u16 species, u32 personality)
{
    u16 i, var;

    // Treat female mons as a seperate species as they may have a different icon than males
    // if (ShouldShowFemaleDifferences(species, personality))
    //    species |= 0x8000; // 1 << 15

    for (i = 0; i < MAX_MON_ICONS; i++)
    {
        if (sStorage->iconSpeciesList[i] == species)
            break;
    }

    if (i == MAX_MON_ICONS)
    {
        for (i = 0; i < MAX_MON_ICONS; i++)
        {
            if (sStorage->iconSpeciesList[i] == 0)
                break;
        }
        if (i == MAX_MON_ICONS)
            return 0xFFFF;
    }

    sStorage->iconSpeciesList[i] = species;
    sStorage->numIconsPerSpecies[i]++;
    var = 16 * i;
    CpuCopy32(GetMonIconTiles(species, personality), (void*)(OBJ_VRAM0) + var * 32, 0x200);

    return var;
}

static void RemoveSpeciesFromIconList(u16 species)
{
    u16 i;
    bool8 hasFemale = FALSE;

    for (i = 0; i < MAX_MON_ICONS; i++)
    {
        if (sStorage->iconSpeciesList[i] == (species | 0x8000))
        {
            hasFemale = TRUE;
            break;
        }
    }

    for (i = 0; i < MAX_MON_ICONS; i++)
    {
        if (sStorage->iconSpeciesList[i] == species && !hasFemale)
        {
            if (--sStorage->numIconsPerSpecies[i] == 0)
                sStorage->iconSpeciesList[i] = SPECIES_NONE;
            break;
        }
    }
}

static struct Sprite *CreateMonIconSprite(u16 species, u32 personality, s16 x, s16 y, u8 oamPriority, u8 subpriority, u8 formId)
{
    u16 tileNum;
    u8 spriteId;
    struct SpriteTemplate tempalte = sSpriteTemplate_MonIcon;

	species = GetIconSpecies(species, personality, formId);
	if (SpeciesHasGenderDifference[species] && GetGenderFromSpeciesAndPersonality(species, personality) == MON_FEMALE)
		tempalte.paletteTag = 0xDAC0 + gMonIconPaletteIndicesFemale[species];
	else
		tempalte.paletteTag = 0xDAC0 + gMonIconPaletteIndices[species];

    tileNum = TryLoadMonIconTiles(species, personality);
    if (tileNum == 0xFFFF)
        return NULL;

    spriteId = CreateSprite(&tempalte, x, y, subpriority);
    if (spriteId == MAX_SPRITES)
    {
        RemoveSpeciesFromIconList(species);
        return NULL;
    }

    gSprites[spriteId].oam.tileNum = tileNum;
    gSprites[spriteId].oam.priority = oamPriority;
    gSprites[spriteId].data[0] = species;
    return &gSprites[spriteId];
}

static void DestroyBoxMonIcon(struct Sprite *sprite)
{
    RemoveSpeciesFromIconList(sprite->data[0]);
    DestroySprite(sprite);
}

//------------------------------------------------------------------------------
//  SECTION: General box
//
//  Some basic box functions, including initializing the box and scrolling.
//------------------------------------------------------------------------------


static void CreateInitBoxTask(u8 boxId)
{
    u8 taskId = CreateTask(Task_InitBox, 2);

    gTasks[taskId].data[2] = boxId;
}

static bool8 IsInitBoxActive(void)
{
    return FuncIsActiveTask(Task_InitBox);
}

static void Task_InitBox(u8 taskId)
{
    struct Task *task = &gTasks[taskId];

    switch (task->data[0])
    {
    case 0:
        sStorage->wallpaperOffset = 0;
        sStorage->bg2_X = 0;
        task->data[1] = RequestDma3Fill(0, sStorage->wallpaperBgTilemapBuffer, 0x1000, 1);
        break;
    case 1:
        if (CheckForSpaceForDma3Request(task->data[1]) == -1)
            return;

        SetBgTilemapBuffer(2, sStorage->wallpaperBgTilemapBuffer);
        ShowBg(2);
        break;
    case 2:
        LoadWallpaperGfx(task->data[2], 0);
        break;
    case 3:
        if (!WaitForWallpaperGfxLoad())
            return;

        InitBoxTitle(task->data[2]);
        CreateBoxScrollArrows();
        InitBoxMonSprites(task->data[2]);
        SetGpuReg(REG_OFFSET_BG2CNT, BGCNT_PRIORITY(2) | BGCNT_CHARBASE(2) | BGCNT_SCREENBASE(27) | BGCNT_TXT512x256);
        break;
    case 4:
        DestroyTask(taskId);
        break;
    default:
        task->data[0] = 0;
        return;
    }

    task->data[0]++;
}

static void SetUpScrollToBox(u8 boxId)
{
    s8 direction = DetermineBoxScrollDirection(boxId);

    sStorage->scrollSpeed = (direction > 0) ? 6 : -6;
    sStorage->scrollUnused1 = (direction > 0) ? 1 : 2;
    sStorage->scrollTimer = 32;
    sStorage->scrollToBoxIdUnused = boxId;
    sStorage->scrollUnused2 = (direction <= 0) ? 5 : 0;
    sStorage->scrollDirectionUnused = direction;

    sStorage->scrollUnused3 = (direction > 0) ? 264 : 56;
    sStorage->scrollUnused4 = (direction <= 0) ? 5 : 0;
    sStorage->scrollUnused5 = 0;
    sStorage->scrollUnused6 = 2;
    sStorage->scrollToBoxId = boxId;
    sStorage->scrollDirection = direction;
    sStorage->scrollState = 0;
}

static bool8 ScrollToBox(void)
{
    bool8 var;

    switch (sStorage->scrollState)
    {
    case 0:
        LoadWallpaperGfx(sStorage->scrollToBoxId, sStorage->scrollDirection);
        sStorage->scrollState++;
    case 1:
        if (!WaitForWallpaperGfxLoad())
            return TRUE;

        InitBoxMonIconScroll(sStorage->scrollToBoxId, sStorage->scrollDirection);
        CreateIncomingBoxTitle(sStorage->scrollToBoxId, sStorage->scrollDirection);
        StartBoxScrollArrowsSlide(sStorage->scrollDirection);
        break;
    case 2:
        var = UpdateBoxMonIconScroll();
        if (sStorage->scrollTimer != 0)
        {
            sStorage->bg2_X += sStorage->scrollSpeed;
            if (--sStorage->scrollTimer != 0)
                return TRUE;
            CycleBoxTitleSprites();
            StopBoxScrollArrowsSlide();
        }
        return var;
    }

    sStorage->scrollState++;
    return TRUE;
}

static s8 DetermineBoxScrollDirection(u8 boxId)
{
    u8 i;
    u8 currentBox = StorageGetCurrentBox();

    for (i = 0; currentBox != boxId; i++)
    {
        currentBox++;
        if (currentBox >= TOTAL_BOXES_COUNT)
            currentBox = 0;
    }

    return (i < TOTAL_BOXES_COUNT / 2) ? 1 : -1;
}

//------------------------------------------------------------------------------
//  SECTION: Wallpaper gfx
//------------------------------------------------------------------------------

static void SetWallpaperForCurrentBox(u8 wallpaperId)
{
    u8 boxId = StorageGetCurrentBox();
    SetBoxWallpaper(boxId, wallpaperId);
    sStorage->wallpaperChangeState = 0;
}

static bool8 DoWallpaperGfxChange(void)
{
    switch (sStorage->wallpaperChangeState)
    {
    case 0:
        BeginNormalPaletteFade(sStorage->wallpaperPalBits, 1, 0, 16, RGB_WHITEALPHA);
        sStorage->wallpaperChangeState++;
        break;
    case 1:
        if (!UpdatePaletteFade())
        {
            u8 curBox = StorageGetCurrentBox();
            LoadWallpaperGfx(curBox, 0);
            sStorage->wallpaperChangeState++;
        }
        break;
    case 2:
        if (WaitForWallpaperGfxLoad() == TRUE)
        {
            CycleBoxTitleColor();
            BeginNormalPaletteFade(sStorage->wallpaperPalBits, 1, 16, 0, RGB_WHITEALPHA);
            sStorage->wallpaperChangeState++;
        }
        break;
    case 3:
        if (!UpdatePaletteFade())
            sStorage->wallpaperChangeState++;
        break;
    case 4:
        return FALSE;
    }

    return TRUE;
}

static void LoadWallpaperGfx(u8 boxId, s8 direction)
{
    u8 wallpaperId;
    const struct WallpaperTable *wallpaperGfx;
    void *iconGfx;
    u32 size1, size2;

    sStorage->wallpaperLoadState = 0;
    sStorage->wallpaperLoadBoxId = boxId;
    sStorage->wallpaperLoadDir = direction;
    if (sStorage->wallpaperLoadDir != 0)
    {
        sStorage->wallpaperOffset = (sStorage->wallpaperOffset == 0);
        sub_80CCAE0(sStorage->wallpaperBgTilemapBuffer);
    }

    wallpaperId = GetBoxWallpaper(sStorage->wallpaperLoadBoxId);
    if (wallpaperId != WALLPAPER_FRIENDS)
    {
        wallpaperGfx = &gWallpaperTable[wallpaperId];
        LZ77UnCompWram(wallpaperGfx->tileMap, sStorage->wallpaperTilemap);
        sub_80CCA3C(sStorage->wallpaperTilemap, sStorage->wallpaperLoadDir, sStorage->wallpaperOffset);

        if (sStorage->wallpaperLoadDir != 0)
            LoadPalette(wallpaperGfx->palettes, (sStorage->wallpaperOffset * 32) + 0x40, 0x40);
        else
            CpuCopy16(wallpaperGfx->palettes, &gPlttBufferUnfaded[(sStorage->wallpaperOffset * 32) + 0x40], 0x40);

        sStorage->wallpaperTiles = malloc_and_decompress(wallpaperGfx->tiles, &size1);
        LoadBgTiles(2, sStorage->wallpaperTiles, size1, sStorage->wallpaperOffset << 8);
    }
    else
    {
        wallpaperGfx = &gFriendsWallpaperTable[GetWaldaWallpaperPatternId()];
        LZ77UnCompWram(wallpaperGfx->tileMap, sStorage->wallpaperTilemap);
        sub_80CCA3C(sStorage->wallpaperTilemap, sStorage->wallpaperLoadDir, sStorage->wallpaperOffset);

        CpuCopy16(wallpaperGfx->palettes, sStorage->wallpaperTilemap, 0x40);
        CpuCopy16(GetWaldaWallpaperColorsPtr(), &sStorage->wallpaperTilemap[1], 4);
        CpuCopy16(GetWaldaWallpaperColorsPtr(), &sStorage->wallpaperTilemap[17], 4);

        if (sStorage->wallpaperLoadDir != 0)
            LoadPalette(sStorage->wallpaperTilemap, (sStorage->wallpaperOffset * 32) + 0x40, 0x40);
        else
            CpuCopy16(sStorage->wallpaperTilemap, &gPlttBufferUnfaded[(sStorage->wallpaperOffset * 32) + 0x40], 0x40);

        sStorage->wallpaperTiles = malloc_and_decompress(wallpaperGfx->tiles, &size1);
        iconGfx = malloc_and_decompress(gFriendsIcons[GetWaldaWallpaperIconId()], &size2);
        CpuCopy32(iconGfx, sStorage->wallpaperTiles + 0x800, size2);
        Free(iconGfx);
        LoadBgTiles(2, sStorage->wallpaperTiles, size1, sStorage->wallpaperOffset << 8);
    }

    CopyBgTilemapBufferToVram(2);
}

static bool32 WaitForWallpaperGfxLoad(void)
{
    if (IsDma3ManagerBusyWithBgCopy())
        return FALSE;

    if (sStorage->wallpaperTiles != NULL)
    {
        Free(sStorage->wallpaperTiles);
        sStorage->wallpaperTiles = NULL;
    }
    return TRUE;
}

static void sub_80CCA3C(const void *tilemap, s8 direction, u8 arg2)
{
    s16 var = (arg2 * 2) + 3;
    s16 x = ((sStorage->bg2_X / 8 + 10) + (direction * 24)) & 0x3F;

    CopyRectToBgTilemapBufferRect(2, tilemap, 0, 0, 0x14, 0x12, x, 2, 0x14, 0x12, 0x11, arg2 << 8, var);

    if (direction == 0)
        return;
    if (direction > 0)
        x *= 1, x += 0x14; // x * 1 is needed to match, but can be safely removed as it makes no functional difference
    else
        x -= 4;

    FillBgTilemapBufferRect(2, 0, x, 2, 4, 0x12, 0x11);
}

static void sub_80CCAE0(void *arg0)
{
    u16 i;
    u16 *dest = arg0;
    s16 r3 = ((sStorage->bg2_X / 8) + 30) & 0x3F;

    if (r3 <= 31)
        dest += r3 + 0x260;
    else
        dest += r3 + 0x640;

    for (i = 0; i < 0x2C; i++)
    {
        *dest++ = 0;
        r3 = (r3 + 1) & 0x3F;
        if (r3 == 0)
            dest -= 0x420;
        if (r3 == 0x20)
            dest += 0x3e0;
    }
}

static void InitBoxTitle(u8 boxId)
{
    u8 tagIndex;
    s16 r6;
    u16 i;

    struct SpriteSheet spriteSheet = {sStorage->boxTitleTiles, 0x200, TAG_TILE_3};
    struct SpritePalette palettes[] = {
        {sStorage->boxTitlePal, TAG_PAL_DAC9},
        {}
    };

    u16 wallpaperId = GetBoxWallpaper(boxId);

    sStorage->boxTitlePal[14] = gUnknown_08577574[wallpaperId][0];
    sStorage->boxTitlePal[15] = gUnknown_08577574[wallpaperId][1];
    LoadSpritePalettes(palettes);
    sStorage->wallpaperPalBits = 0x3f0;

    tagIndex = IndexOfSpritePaletteTag(TAG_PAL_DAC9);
    sStorage->boxTitlePalOffset = 0x10e + 16 * tagIndex;
    sStorage->wallpaperPalBits |= 0x10000 << tagIndex;

    tagIndex = IndexOfSpritePaletteTag(TAG_PAL_DAC9);
    sStorage->boxTitleAltPalOffset = 0x10e + 16 * tagIndex;
    sStorage->wallpaperPalBits |= 0x10000 << tagIndex;

    StringCopyPadded(sStorage->boxTitleText, GetBoxNamePtr(boxId), 0, 8);
    DrawTextWindowAndBufferTiles(sStorage->boxTitleText, sStorage->boxTitleTiles, 0, 0, 2);
    LoadSpriteSheet(&spriteSheet);
    r6 = sub_80CD00C(GetBoxNamePtr(boxId));

    for (i = 0; i < 2; i++)
    {
        u8 spriteId = CreateSprite(&gSpriteTemplate_857B0A8, r6 + i * 32, 28, 24);
        sStorage->curBoxTitleSprites[i] = &gSprites[spriteId];
        StartSpriteAnim(sStorage->curBoxTitleSprites[i], i);
    }
    sStorage->boxTitleCycleId = 0;
}

static void CreateIncomingBoxTitle(u8 boxId, s8 direction)
{
    u16 r8;
    s16 x, x2;
    u16 i;
    struct SpriteSheet spriteSheet = {sStorage->boxTitleTiles, 0x200, TAG_TILE_3};
    struct SpriteTemplate template = gSpriteTemplate_857B0A8;

    sStorage->boxTitleCycleId = (sStorage->boxTitleCycleId == 0);
    if (sStorage->boxTitleCycleId == 0)
    {
        spriteSheet.tag = TAG_TILE_3;
        r8 = sStorage->boxTitlePalOffset;
    }
    else
    {
        spriteSheet.tag = TAG_TILE_4;
        r8 = sStorage->boxTitlePalOffset;
        template.tileTag = TAG_TILE_4;
        template.paletteTag = TAG_PAL_DAC9;
    }

    StringCopyPadded(sStorage->boxTitleText, GetBoxNamePtr(boxId), 0, 8);
    DrawTextWindowAndBufferTiles(sStorage->boxTitleText, sStorage->boxTitleTiles, 0, 0, 2);
    LoadSpriteSheet(&spriteSheet);
    LoadPalette(gUnknown_08577574[GetBoxWallpaper(boxId)], r8, 4);
    x = sub_80CD00C(GetBoxNamePtr(boxId));
    x2 = x;
    x2 += direction * 192;

    for (i = 0; i < 2; i++)
    {
        u8 spriteId = CreateSprite(&template, i * 32 + x2, 28, 24);

        sStorage->nextBoxTitleSprites[i] = &gSprites[spriteId];
        sStorage->nextBoxTitleSprites[i]->data[0] = (-direction) * 6;
        sStorage->nextBoxTitleSprites[i]->data[1] = i * 32 + x;
        sStorage->nextBoxTitleSprites[i]->data[2] = 0;
        sStorage->nextBoxTitleSprites[i]->callback = sub_80CCF30;
        StartSpriteAnim(sStorage->nextBoxTitleSprites[i], i);

        sStorage->curBoxTitleSprites[i]->data[0] = (-direction) * 6;
        sStorage->curBoxTitleSprites[i]->data[1] = 1;
        sStorage->curBoxTitleSprites[i]->callback = sub_80CCF64;
    }
}

static void CycleBoxTitleSprites(void)
{
    if (sStorage->boxTitleCycleId == 0)
        FreeSpriteTilesByTag(TAG_TILE_4);
    else
        FreeSpriteTilesByTag(TAG_TILE_3);

    sStorage->curBoxTitleSprites[0] = sStorage->nextBoxTitleSprites[0];
    sStorage->curBoxTitleSprites[1] = sStorage->nextBoxTitleSprites[1];
}

static void sub_80CCF30(struct Sprite *sprite)
{
    if (sprite->data[2] != 0)
        sprite->data[2]--;
    else if ((sprite->pos1.x += sprite->data[0]) == sprite->data[1])
        sprite->callback = SpriteCallbackDummy;
}

static void sub_80CCF64(struct Sprite *sprite)
{
    if (sprite->data[1] != 0)
    {
        sprite->data[1]--;
    }
    else
    {
        sprite->pos1.x += sprite->data[0];
        sprite->data[2] = sprite->pos1.x + sprite->pos2.x;
        if (sprite->data[2] < 0x40 || sprite->data[2] > 0x100)
            DestroySprite(sprite);
    }
}

static void CycleBoxTitleColor(void)
{
    u8 boxId = StorageGetCurrentBox();
    u8 wallpaperId = GetBoxWallpaper(boxId);
    if (sStorage->boxTitleCycleId == 0)
        CpuCopy16(gUnknown_08577574[wallpaperId], gPlttBufferUnfaded + sStorage->boxTitlePalOffset, 4);
    else
        CpuCopy16(gUnknown_08577574[wallpaperId], gPlttBufferUnfaded + sStorage->boxTitleAltPalOffset, 4);
}

static s16 sub_80CD00C(const u8 *string)
{
    return 0xB0 - GetStringWidth(1, string, 0) / 2;
}

static void CreateBoxScrollArrows(void)
{
    u16 i;

    LoadSpriteSheet(&sSpriteSheet_Arrow);
    for (i = 0; i < 2; i++)
    {
        u8 spriteId = CreateSprite(&sSpriteTemplate_Arrow, 0x5c + i * 0x88, 28, 22);
        if (spriteId != MAX_SPRITES)
        {
            struct Sprite *sprite = &gSprites[spriteId];
            StartSpriteAnim(sprite, i);
            sprite->data[3] = (i == 0) ? -1 : 1;
            sStorage->arrowSprites[i] = sprite;
        }
    }
    if (IsCursorOnBox())
        AnimateBoxScrollArrows(TRUE);
}

static void StartBoxScrollArrowsSlide(s8 direction)
{
    u16 i;

    for (i = 0; i < 2; i++)
    {
        sStorage->arrowSprites[i]->pos2.x = 0;
        sStorage->arrowSprites[i]->data[0] = 2;
    }
    if (direction < 0)
    {
        sStorage->arrowSprites[0]->data[1] = 29;
        sStorage->arrowSprites[1]->data[1] = 5;
        sStorage->arrowSprites[0]->data[2] = 0x48;
        sStorage->arrowSprites[1]->data[2] = 0x48;
    }
    else
    {
        sStorage->arrowSprites[0]->data[1] = 5;
        sStorage->arrowSprites[1]->data[1] = 29;
        sStorage->arrowSprites[0]->data[2] = 0xF8;
        sStorage->arrowSprites[1]->data[2] = 0xF8;
    }
    sStorage->arrowSprites[0]->data[7] = 0;
    sStorage->arrowSprites[1]->data[7] = 1;
}

static void StopBoxScrollArrowsSlide(void)
{
    u16 i;

    for (i = 0; i < 2; i++)
    {
        sStorage->arrowSprites[i]->pos1.x = 0x88 * i + 0x5c;
        sStorage->arrowSprites[i]->pos2.x = 0;
        sStorage->arrowSprites[i]->invisible = FALSE;
    }
    AnimateBoxScrollArrows(TRUE);
}

static void AnimateBoxScrollArrows(bool8 a0)
{
    u16 i;

    if (a0)
    {
        for (i = 0; i < 2; i++)
        {
            sStorage->arrowSprites[i]->data[0] = 1;
            sStorage->arrowSprites[i]->data[1] = 0;
            sStorage->arrowSprites[i]->data[2] = 0;
            sStorage->arrowSprites[i]->data[4] = 0;
        }
    }
    else
    {
        for (i = 0; i < 2; i++)
        {
            sStorage->arrowSprites[i]->data[0] = 0;
        }
    }
}

static void sub_80CD210(struct Sprite *sprite)
{
    switch (sprite->data[0])
    {
    case 0:
        sprite->pos2.x = 0;
        break;
    case 1:
        if (++sprite->data[1] > 3)
        {
            sprite->data[1] = 0;
            sprite->pos2.x += sprite->data[3];
            if (++sprite->data[2] > 5)
            {
                sprite->data[2] = 0;
                sprite->pos2.x = 0;
            }
        }
        break;
    case 2:
        sprite->data[0] = 3;
        break;
    case 3:
        sprite->pos1.x -= sStorage->scrollSpeed;
        if (sprite->pos1.x < 73 || sprite->pos1.x > 247)
            sprite->invisible = TRUE;
        if (--sprite->data[1] == 0)
        {
            sprite->pos1.x = sprite->data[2];
            sprite->invisible = FALSE;
            sprite->data[0] = 4;
        }
        break;
    case 4:
        sprite->pos1.x -= sStorage->scrollSpeed;
        break;
    }
}

static struct Sprite *sub_80CD2E8(u16 x, u16 y, u8 animId, u8 priority, u8 subpriority)
{
    u8 spriteId = CreateSprite(&sSpriteTemplate_Arrow, x, y, subpriority);
    if (spriteId == MAX_SPRITES)
        return NULL;

    animId %= 2;
    StartSpriteAnim(&gSprites[spriteId], animId);
    gSprites[spriteId].oam.priority = priority;
    gSprites[spriteId].callback = SpriteCallbackDummy;
    return &gSprites[spriteId];
}

static void InitCursor(void)
{
    if (sStorage->boxOption != OPTION_DEPOSIT)
        sBoxCursorArea = CURSOR_AREA_IN_BOX;
    else
        sBoxCursorArea = CURSOR_AREA_IN_PARTY;

    sBoxCursorPosition = 0;
    sIsMonBeingMoved = FALSE;
    sMovingMonOrigBoxId = 0;
    sMovingMonOrigBoxPos = 0;
    sCanOnlyMove = FALSE;
    ClearSavedCursorPos();
    sub_80CFC14();
    sStorage->cursorPrevHorizPos = 1;
    sStorage->inBoxMovingMode = 0;
    sub_80CEB40();
}

static void InitCursorOnReopen(void)
{
    sub_80CFC14();
    sub_80CEBDC();
    sStorage->cursorPrevHorizPos = 1;
    sStorage->inBoxMovingMode = 0;
    if (sIsMonBeingMoved)
    {
        sStorage->movingMon = gUnknown_02039D14;
        CreateMovingMonIcon();
    }
}

static void sub_80CD444(u8 cursorArea, u8 cursorPosition, u16 *x, u16 *y)
{
    switch (cursorArea)
    {
    case CURSOR_AREA_IN_BOX:
        *x = (cursorPosition % IN_BOX_ROWS) * 24 + 100;
        *y = (cursorPosition / IN_BOX_ROWS) * 24 +  32;
        break;
    case CURSOR_AREA_IN_PARTY:
        if (cursorPosition == 0)
        {
            *x = 0x68;
            *y = 0x34;
        }
        else if (cursorPosition == PARTY_SIZE)
        {
            *x = 0x98;
            *y = 0x84;
        }
        else
        {
            *x = 0x98;
            *y = (cursorPosition - 1) * 24 + 4;
        }
        break;
    case CURSOR_AREA_BOX:
        *x = 0xa2;
        *y = 0x0c;
        break;
    case CURSOR_AREA_BUTTONS:
        *y = sIsMonBeingMoved ? 8 : 14;
        *x = cursorPosition * 0x58 + 0x78;
        break;
    case 4:
        *x = 0xa0;
        *y = 0x60;
        break;
    }
}

static u16 GetSpeciesAtCursorPosition(void)
{
    switch (sBoxCursorArea)
    {
    case CURSOR_AREA_IN_PARTY:
        return GetMonData(&gPlayerParty[sBoxCursorPosition], MON_DATA_SPECIES);
    case CURSOR_AREA_IN_BOX:
        return GetCurrentBoxMonData(sBoxCursorPosition, MON_DATA_SPECIES);
    default:
        return SPECIES_NONE;
    }
}

static bool8 sub_80CD554(void)
{
    s16 tmp;

    if (sStorage->cursorMoveSteps == 0)
    {
        if (sStorage->boxOption != OPTION_MOVE_ITEMS)
            return FALSE;
        else
            return sub_80D1218();
    }
    else if (--sStorage->cursorMoveSteps != 0)
    {
        sStorage->cursorNewX += sStorage->cursorSpeedX;
        sStorage->cursorNewY += sStorage->cursorSpeedY;
        sStorage->cursorSprite->pos1.x = sStorage->cursorNewX >> 8;
        sStorage->cursorSprite->pos1.y = sStorage->cursorNewY >> 8;
        if (sStorage->cursorSprite->pos1.x > 0x100)
        {
            tmp = sStorage->cursorSprite->pos1.x - 0x100;
            sStorage->cursorSprite->pos1.x = tmp + 0x40;
        }
        if (sStorage->cursorSprite->pos1.x < 0x40)
        {
            tmp = 0x40 - sStorage->cursorSprite->pos1.x;
            sStorage->cursorSprite->pos1.x = 0x100 - tmp;
        }
        if (sStorage->cursorSprite->pos1.y > 0xb0)
        {
            tmp = sStorage->cursorSprite->pos1.y - 0xb0;
            sStorage->cursorSprite->pos1.y = tmp - 0x10;
        }
        if (sStorage->cursorSprite->pos1.y < -0x10)
        {
            tmp = -0x10 - sStorage->cursorSprite->pos1.y;
            sStorage->cursorSprite->pos1.y = 0xb0 - tmp;
        }
        if (sStorage->cursorFlipTimer && --sStorage->cursorFlipTimer == 0)
            sStorage->cursorSprite->vFlip = (sStorage->cursorSprite->vFlip == FALSE);
    }
    else
    {
        sStorage->cursorSprite->pos1.x = sStorage->cursorTargetX;
        sStorage->cursorSprite->pos1.y = sStorage->cursorTargetY;
        sub_80CDA68();
    }

    return TRUE;
}

static void sub_80CD6AC(u8 newCurosrArea, u8 newCursorPosition)
{
    u16 x, y;

    sub_80CD444(newCurosrArea, newCursorPosition, &x, &y);
    sStorage->newCursorArea = newCurosrArea;
    sStorage->newCursorPosition = newCursorPosition;
    sStorage->cursorTargetX = x;
    sStorage->cursorTargetY = y;
}

static void sub_80CD70C(void)
{
    int r7, r0;

    if (sStorage->cursorVerticalWrap != 0 || sStorage->cursorHorizontalWrap != 0)
        sStorage->cursorMoveSteps = 12;
    else
        sStorage->cursorMoveSteps = 6;

    if (sStorage->cursorFlipTimer)
        sStorage->cursorFlipTimer = sStorage->cursorMoveSteps >> 1;

    switch (sStorage->cursorVerticalWrap)
    {
        default:
            r7 = sStorage->cursorTargetY - sStorage->cursorSprite->pos1.y;
            break;
        case -1:
            r7 = sStorage->cursorTargetY - 0xc0 - sStorage->cursorSprite->pos1.y;
            break;
        case 1:
            r7 = sStorage->cursorTargetY + 0xc0 - sStorage->cursorSprite->pos1.y;
            break;
    }

    switch (sStorage->cursorHorizontalWrap)
    {
        default:
            r0 = sStorage->cursorTargetX - sStorage->cursorSprite->pos1.x;
            break;
        case -1:
            r0 = sStorage->cursorTargetX - 0xc0 - sStorage->cursorSprite->pos1.x;
            break;
        case 1:
            r0 = sStorage->cursorTargetX + 0xc0 - sStorage->cursorSprite->pos1.x;
            break;
    }

    r7 <<= 8;
    r0 <<= 8;
    sStorage->cursorSpeedX = r0 / sStorage->cursorMoveSteps;
    sStorage->cursorSpeedY = r7 / sStorage->cursorMoveSteps;
    sStorage->cursorNewX = sStorage->cursorSprite->pos1.x << 8;
    sStorage->cursorNewY = sStorage->cursorSprite->pos1.y << 8;
}

static void sub_80CD894(u8 newCurosrArea, u8 newCursorPosition)
{
    sub_80CD6AC(newCurosrArea, newCursorPosition);
    sub_80CD70C();
    if (sStorage->boxOption != OPTION_MOVE_ITEMS)
    {
        if (sStorage->inBoxMovingMode == 0 && !sIsMonBeingMoved)
            StartSpriteAnim(sStorage->cursorSprite, 1);
    }
    else
    {
        if (!IsActiveItemMoving())
            StartSpriteAnim(sStorage->cursorSprite, 1);
    }

    if (sStorage->boxOption == OPTION_MOVE_ITEMS)
    {
        if (sBoxCursorArea == CURSOR_AREA_IN_BOX)
            sub_80D0E50(CURSOR_AREA_IN_BOX, sBoxCursorPosition);
        else if (sBoxCursorArea == CURSOR_AREA_IN_PARTY)
            sub_80D0E50(CURSOR_AREA_IN_PARTY, sBoxCursorPosition);

        if (newCurosrArea == CURSOR_AREA_IN_BOX)
            sub_80D0D8C(newCurosrArea, newCursorPosition);
        else if (newCurosrArea == CURSOR_AREA_IN_PARTY)
            sub_80D0D8C(newCurosrArea, newCursorPosition);
    }

    if (newCurosrArea == CURSOR_AREA_IN_PARTY && sBoxCursorArea != CURSOR_AREA_IN_PARTY)
    {
        sStorage->cursorPrevHorizPos = newCurosrArea;
        sStorage->cursorShadowSprite->invisible = TRUE;
    }

    switch (newCurosrArea)
    {
    case CURSOR_AREA_IN_PARTY:
    case CURSOR_AREA_BOX:
    case CURSOR_AREA_BUTTONS:
        sStorage->cursorSprite->oam.priority = 1;
        sStorage->cursorShadowSprite->invisible = TRUE;
        sStorage->cursorShadowSprite->oam.priority = 1;
        break;
    case CURSOR_AREA_IN_BOX:
        if (sStorage->inBoxMovingMode != 0)
        {
            sStorage->cursorSprite->oam.priority = 0;
            sStorage->cursorShadowSprite->invisible = TRUE;
        }
        else
        {
            sStorage->cursorSprite->oam.priority = 2;
            if (sBoxCursorArea == CURSOR_AREA_IN_BOX && sIsMonBeingMoved)
                SetMovingMonPriority(2);
        }
        break;
    }
}

static void sub_80CDA68(void)
{
    sBoxCursorArea = sStorage->newCursorArea;
    sBoxCursorPosition = sStorage->newCursorPosition;
    if (sStorage->boxOption != OPTION_MOVE_ITEMS)
    {
        if (sStorage->inBoxMovingMode == 0 && !sIsMonBeingMoved)
            StartSpriteAnim(sStorage->cursorSprite, 0);
    }
    else
    {
        if (!IsActiveItemMoving())
            StartSpriteAnim(sStorage->cursorSprite, 0);
    }

    sub_80CEB40();
    switch (sBoxCursorArea)
    {
    case CURSOR_AREA_BUTTONS:
        SetMovingMonPriority(1);
        break;
    case CURSOR_AREA_BOX:
        AnimateBoxScrollArrows(TRUE);
        break;
    case CURSOR_AREA_IN_PARTY:
        sStorage->cursorShadowSprite->subpriority = 13;
        SetMovingMonPriority(1);
        break;
    case CURSOR_AREA_IN_BOX:
        if (sStorage->inBoxMovingMode == 0)
        {
            sStorage->cursorSprite->oam.priority = 1;
            sStorage->cursorShadowSprite->oam.priority = 2;
            sStorage->cursorShadowSprite->subpriority = 21;
            sStorage->cursorShadowSprite->invisible = FALSE;
            SetMovingMonPriority(2);
        }
        break;
    }
}

static void sub_80CDBA0(void)
{
    u8 partyCount;

    if (!sIsMonBeingMoved)
    {
        partyCount = 0;
    }
    else
    {
        partyCount = CalculatePlayerPartyCount();
        if (partyCount >= PARTY_SIZE)
            partyCount = PARTY_SIZE - 1;
    }
    if (sStorage->cursorSprite->vFlip)
        sStorage->cursorFlipTimer = 1;
    sub_80CD894(CURSOR_AREA_IN_PARTY, partyCount);
}

static void sub_80CDBF8(u8 cursorBoxPosition)
{
    sub_80CD894(CURSOR_AREA_IN_BOX, cursorBoxPosition);
}

EWRAM_DATA static u8 gUnknown_02039D7E = 0;

static void ClearSavedCursorPos(void)
{
    gUnknown_02039D7E = 0;
}

static void sub_80CDC18(void)
{
    gUnknown_02039D7E = sBoxCursorPosition;
}

static u8 sub_80CDC2C(void)
{
    return gUnknown_02039D7E;
}

static void InitMonPlaceChange(u8 a0)
{
    static bool8 (*const placeChangeFuncs[])(void) =
    {
        MonPlaceChange_Move,
        MonPlaceChange_Place,
        MonPlaceChange_Shift,
    };

    sStorage->monPlaceChangeFunc = placeChangeFuncs[a0];
    sStorage->monPlaceChangeState = 0;
}

static void sub_80CDC64(bool8 arg0)
{
    if (!arg0)
        sStorage->monPlaceChangeFunc = sub_80CDEB4;
    else
        sStorage->monPlaceChangeFunc = sub_80CDEC4;

    sStorage->monPlaceChangeState = 0;
}

static bool8 DoMonPlaceChange(void)
{
    return sStorage->monPlaceChangeFunc();
}

static bool8 MonPlaceChange_Move(void)
{
    switch (sStorage->monPlaceChangeState)
    {
    case 0:
        if (sIsMonBeingMoved)
            return FALSE;
        StartSpriteAnim(sStorage->cursorSprite, 2);
        sStorage->monPlaceChangeState++;
        break;
    case 1:
        if (!sub_80CDED4())
        {
            StartSpriteAnim(sStorage->cursorSprite, 3);
            MoveMon();
            sStorage->monPlaceChangeState++;
        }
        break;
    case 2:
        if (!sub_80CDF08())
            sStorage->monPlaceChangeState++;
        break;
    case 3:
        return FALSE;
    }

    return TRUE;
}

static bool8 MonPlaceChange_Place(void)
{
    switch (sStorage->monPlaceChangeState)
    {
    case 0:
        if (!sub_80CDED4())
        {
            StartSpriteAnim(sStorage->cursorSprite, 2);
            PlaceMon();
            sStorage->monPlaceChangeState++;
        }
        break;
    case 1:
        if (!sub_80CDF08())
        {
            StartSpriteAnim(sStorage->cursorSprite, 0);
            sStorage->monPlaceChangeState++;
        }
        break;
    case 2:
        return FALSE;
    }

    return TRUE;
}

static bool8 MonPlaceChange_Shift(void)
{
    switch (sStorage->monPlaceChangeState)
    {
    case 0:
        switch (sBoxCursorArea)
        {
        case CURSOR_AREA_IN_PARTY:
            sStorage->shiftBoxId = TOTAL_BOXES_COUNT;
            break;
        case CURSOR_AREA_IN_BOX:
            sStorage->shiftBoxId = StorageGetCurrentBox();
            break;
        default:
            return FALSE;
        }
        StartSpriteAnim(sStorage->cursorSprite, 2);
        SaveMonSpriteAtPos(sStorage->shiftBoxId, sBoxCursorPosition);
        sStorage->monPlaceChangeState++;
        break;
    case 1:
        if (!MoveShiftingMons())
        {
            StartSpriteAnim(sStorage->cursorSprite, 3);
            SetShiftedMonData(sStorage->shiftBoxId, sBoxCursorPosition);
            sStorage->monPlaceChangeState++;
        }
        break;
    case 2:
        return FALSE;
    }

    return TRUE;
}

static bool8 sub_80CDEB4(void)
{
    return sub_80CDED4();
}

static bool8 sub_80CDEC4(void)
{
    return sub_80CDF08();
}

static bool8 sub_80CDED4(void)
{
    switch (sStorage->cursorSprite->pos2.y)
    {
    default:
        sStorage->cursorSprite->pos2.y++;
        break;
    case 0:
        sStorage->cursorSprite->pos2.y++;
        break;
    case 8:
        return FALSE;
    }

    return TRUE;
}

static bool8 sub_80CDF08(void)
{
    switch (sStorage->cursorSprite->pos2.y)
    {
    case 0:
        return FALSE;
    default:
        sStorage->cursorSprite->pos2.y--;
        break;
    }

    return TRUE;
}

static void MoveMon(void)
{
    switch (sBoxCursorArea)
    {
    case CURSOR_AREA_IN_PARTY:
        SetMovedMonData(TOTAL_BOXES_COUNT, sBoxCursorPosition);
        SetMovingMonSprite(MODE_PARTY, sBoxCursorPosition);
        break;
    case CURSOR_AREA_IN_BOX:
        if (sStorage->inBoxMovingMode == 0)
        {
            SetMovedMonData(StorageGetCurrentBox(), sBoxCursorPosition);
            SetMovingMonSprite(MODE_BOX, sBoxCursorPosition);
        }
        break;
    default:
        return;
    }

    sIsMonBeingMoved = TRUE;
}

static void PlaceMon(void)
{
    u8 boxId;

    switch (sBoxCursorArea)
    {
    case CURSOR_AREA_IN_PARTY:
        SetPlacedMonData(TOTAL_BOXES_COUNT, sBoxCursorPosition);
        SetPlacedMonSprite(TOTAL_BOXES_COUNT, sBoxCursorPosition);
        break;
    case CURSOR_AREA_IN_BOX:
        boxId = StorageGetCurrentBox();
        SetPlacedMonData(boxId, sBoxCursorPosition);
        SetPlacedMonSprite(boxId, sBoxCursorPosition);
        break;
    default:
        return;
    }

    sIsMonBeingMoved = FALSE;
}

static void RefreshDisplayMon(void)
{
    sub_80CEB40();
}

static void SetMovedMonData(u8 boxId, u8 position)
{
    if (boxId == TOTAL_BOXES_COUNT)
        sStorage->movingMon = gPlayerParty[sBoxCursorPosition];
    else
        BoxMonAtToMon(boxId, position, &sStorage->movingMon);

    PurgeMonOrBoxMon(boxId, position, FALSE);
    sMovingMonOrigBoxId = boxId;
    sMovingMonOrigBoxPos = position;
}

static void SetPlacedMonData(u8 boxId, u8 position)
{
    if (boxId == TOTAL_BOXES_COUNT)
    {
        gPlayerParty[position] = sStorage->movingMon;
    }
    else
    {
        BoxMonRestorePP(&sStorage->movingMon.box);
        SetBoxMonAt(boxId, position, &sStorage->movingMon.box);
    }
}

static void PurgeMonOrBoxMon(u8 boxId, u8 position, bool8 send)
{
    if (boxId == TOTAL_BOXES_COUNT){
        /*if(send){
            SendPartyMonToDB(position);
        }*/
        ZeroMonData(&gPlayerParty[position]);
    }
    else{
        /*if(send){
            SendBoxMonToDB(boxId, position);
        }*/
        ZeroBoxMonAt(boxId, position);
    } 
}

static void SetShiftedMonData(u8 boxId, u8 position)
{
    if (boxId == TOTAL_BOXES_COUNT)
        sStorage->tempMon = gPlayerParty[position];
    else
        BoxMonAtToMon(boxId, position, &sStorage->tempMon);

    SetPlacedMonData(boxId, position);
    sStorage->movingMon = sStorage->tempMon;
    SetCursorMonData(&sStorage->movingMon, MODE_PARTY);
    sMovingMonOrigBoxId = boxId;
    sMovingMonOrigBoxPos = position;
}

static bool8 TryStorePartyMonInBox(u8 boxId)
{
    s16 boxPosition = GetFirstFreeBoxSpot(boxId);
    if (boxPosition == -1)
        return FALSE;

    if (sIsMonBeingMoved)
    {
        SetPlacedMonData(boxId, boxPosition);
        DestroyMovingMonIcon();
        sIsMonBeingMoved = FALSE;
    }
    else
    {
        SetMovedMonData(TOTAL_BOXES_COUNT, sBoxCursorPosition);
        SetPlacedMonData(boxId, boxPosition);
        DestroyPartyMonIcon(sBoxCursorPosition);
    }

    if (boxId == StorageGetCurrentBox())
        createBoxMonIconAtPos(boxPosition);

    StartSpriteAnim(sStorage->cursorSprite, 1);
    return TRUE;
}

static void sub_80CE22C(void)
{
    StartSpriteAnim(sStorage->cursorSprite, 0);
    sub_80CEB40();
}

static void InitReleaseMon(void)
{
    u8 mode;

    if (sIsMonBeingMoved)
        mode = MODE_MOVE;
    else if (sBoxCursorArea == CURSOR_AREA_IN_PARTY)
        mode = MODE_PARTY;
    else
        mode = MODE_BOX;

    SetReleaseMon(mode, sBoxCursorPosition);
    StringCopy(sStorage->releaseMonName, sStorage->cursorMonNick);
}

static bool8 TryHideReleaseMon(void)
{
    if (!TryHideReleaseMonSprite())
    {
        StartSpriteAnim(sStorage->cursorSprite, 0);
        return FALSE;
    }
    else
    {
        return TRUE;
    }
}

static void ReleaseMon(void)
{
    u8 boxId;

    DestroyReleaseMonIcon();
    if (sIsMonBeingMoved)
    {
        sIsMonBeingMoved = FALSE;
    }
    else
    {
        if (sBoxCursorArea == CURSOR_AREA_IN_PARTY)
            boxId = TOTAL_BOXES_COUNT;
        else
            boxId = StorageGetCurrentBox();

        PurgeMonOrBoxMon(boxId, sBoxCursorPosition, TRUE);
    }
    sub_80CEB40();
}

static void TrySetCursorFistAnim(void)
{
    if (sIsMonBeingMoved)
        StartSpriteAnim(sStorage->cursorSprite, 3);
}

struct
{
    s8 mapGroup;
    s8 mapNum;
    u16 move;
} static const gUnknown_0857B9A4[] =
{
    {MAP_GROUPS_COUNT, 0, MOVE_SURF},
    {MAP_GROUPS_COUNT, 0, MOVE_DIVE},
    {MAP_GROUP(EVER_GRANDE_CITY_POKEMON_LEAGUE_1F), MAP_NUM(EVER_GRANDE_CITY_POKEMON_LEAGUE_1F), MOVE_STRENGTH},
    {MAP_GROUP(EVER_GRANDE_CITY_POKEMON_LEAGUE_1F), MAP_NUM(EVER_GRANDE_CITY_POKEMON_LEAGUE_1F), MOVE_ROCK_SMASH},
    {MAP_GROUP(EVER_GRANDE_CITY_POKEMON_LEAGUE_2F), MAP_NUM(EVER_GRANDE_CITY_POKEMON_LEAGUE_2F), MOVE_STRENGTH},
    {MAP_GROUP(EVER_GRANDE_CITY_POKEMON_LEAGUE_2F), MAP_NUM(EVER_GRANDE_CITY_POKEMON_LEAGUE_2F), MOVE_ROCK_SMASH},
};

static void sub_80CE350(u16 *moves)
{
    s32 i;

    for (i = 0; i < ARRAY_COUNT(gUnknown_0857B9A4); i++)
    {
        if (gUnknown_0857B9A4[i].mapGroup == MAP_GROUPS_COUNT
            || (gUnknown_0857B9A4[i].mapGroup == gSaveBlock1Ptr->location.mapGroup && gUnknown_0857B9A4[i].mapNum == gSaveBlock1Ptr->location.mapNum))
        {
            *moves = gUnknown_0857B9A4[i].move;
            moves++;
        }
    }

    *moves = MOVES_COUNT;
}

static void InitCanRelaseMonVars(void)
{
    if (!AtLeastThreeUsableMons())
    {
        sStorage->releaseStatusResolved = 1;
        sStorage->canReleaseMon = 0;
        return;
    }

    if (sIsMonBeingMoved)
    {
        sStorage->tempMon = sStorage->movingMon;
        sStorage->releaseBoxId = -1;
        sStorage->releaseBoxPos = -1;
    }
    else
    {
        if (sBoxCursorArea == CURSOR_AREA_IN_PARTY)
        {
            sStorage->tempMon = gPlayerParty[sBoxCursorPosition];
            sStorage->releaseBoxId = TOTAL_BOXES_COUNT;
        }
        else
        {
            BoxMonAtToMon(StorageGetCurrentBox(), sBoxCursorPosition, &sStorage->tempMon);
            sStorage->releaseBoxId = StorageGetCurrentBox();
        }
        sStorage->releaseBoxPos = sBoxCursorPosition;
    }

    sub_80CE350(sStorage->restrictedMoveList);
    sStorage->restrictedReleaseMonMoves = GetMonData(&sStorage->tempMon, MON_DATA_KNOWN_MOVES, (u8*)sStorage->restrictedMoveList);
    if (sStorage->restrictedReleaseMonMoves != 0)
    {
        sStorage->releaseStatusResolved = 0;
    }
    else
    {
        sStorage->releaseStatusResolved = 1;
        sStorage->canReleaseMon = 1;
    }

    sStorage->releaseCheckState = 0;
}

static bool32 AtLeastThreeUsableMons(void)
{
    s32 i, j, count;

    count = (sIsMonBeingMoved != FALSE);
    for (j = 0; j < PARTY_SIZE; j++)
    {
        if (GetMonData(&gPlayerParty[j], MON_DATA_SANITY_HAS_SPECIES))
            count++;
    }

    if (count >= 3)
        return TRUE;

    for (i = 0; i < TOTAL_BOXES_COUNT; i++)
    {
        for (j = 0; j < IN_BOX_COUNT; j++)
        {
            if (CheckBoxMonSanityAt(i, j))
            {
                if (++count >= 3)
                    return TRUE;
            }
        }
    }

    return FALSE;
}

static s8 RunCanReleaseMon(void)
{
    u16 i;
    u16 knownMoves;

    if (sStorage->releaseStatusResolved)
        return sStorage->canReleaseMon;

    switch (sStorage->releaseCheckState)
    {
    case 0:
        for (i = 0; i < PARTY_SIZE; i++)
        {
            if (sStorage->releaseBoxId != TOTAL_BOXES_COUNT || sStorage->releaseBoxPos != i)
            {
                knownMoves = GetMonData(gPlayerParty + i, MON_DATA_KNOWN_MOVES, (u8*)sStorage->restrictedMoveList);
                sStorage->restrictedReleaseMonMoves &= ~(knownMoves);
            }
        }
        if (sStorage->restrictedReleaseMonMoves == 0)
        {
            sStorage->releaseStatusResolved = 1;
            sStorage->canReleaseMon = 1;
        }
        else
        {
            sStorage->releaseCheckBoxId = 0;
            sStorage->releaseCheckBoxPos = 0;
            sStorage->releaseCheckState++;
        }
        break;
    case 1:
        for (i = 0; i < IN_BOX_COUNT; i++)
        {
            knownMoves = GetAndCopyBoxMonDataAt(sStorage->releaseCheckBoxId, sStorage->releaseCheckBoxPos, MON_DATA_KNOWN_MOVES, (u8*)sStorage->restrictedMoveList);
            if (knownMoves != 0
                && !(sStorage->releaseBoxId == sStorage->releaseCheckBoxId && sStorage->releaseBoxPos == sStorage->releaseCheckBoxPos))
            {
                sStorage->restrictedReleaseMonMoves &= ~(knownMoves);
                if (sStorage->restrictedReleaseMonMoves == 0)
                {
                    sStorage->releaseStatusResolved = 1;
                    sStorage->canReleaseMon = 1;
                    break;
                }
            }
            if (++sStorage->releaseCheckBoxPos >= IN_BOX_COUNT)
            {
                sStorage->releaseCheckBoxPos = 0;
                if (++sStorage->releaseCheckBoxId >= TOTAL_BOXES_COUNT)
                {
                    sStorage->releaseStatusResolved = 1;
                    sStorage->canReleaseMon = 0;
                }
            }
        }
        break;
    }

    return -1;
}

static void sub_80CE760(void)
{
    if (sIsMonBeingMoved)
        gUnknown_02039D14 = sStorage->movingMon;
}

static void LoadSavedMovingMon(void)
{
    if (sIsMonBeingMoved)
    {
        if (sMovingMonOrigBoxId == TOTAL_BOXES_COUNT)
            sStorage->movingMon = gUnknown_02039D14;
        else
            sStorage->movingMon.box = gUnknown_02039D14.box;
    }
}

static void sub_80CE7E8(void)
{
    if (sIsMonBeingMoved)
    {
        sub_80CE760();
        sStorage->summaryMon.mon = &gUnknown_02039D14;
        sStorage->summaryStartPos = 0;
        sStorage->summaryMaxPos = 0;
        sStorage->pokemonSummaryScreenMode = PSS_MODE_NORMAL;
    }
    else if (sBoxCursorArea == CURSOR_AREA_IN_PARTY)
    {
        sStorage->summaryMon.mon = gPlayerParty;
        sStorage->summaryStartPos = sBoxCursorPosition;
        sStorage->summaryMaxPos = CountPartyMons() - 1;
        sStorage->pokemonSummaryScreenMode = PSS_MODE_NORMAL;
    }
    else
    {
        sStorage->summaryMon.box = GetBoxedMonPtr(StorageGetCurrentBox(), 0);
        sStorage->summaryStartPos = sBoxCursorPosition;
        sStorage->summaryMaxPos = IN_BOX_COUNT - 1;
        sStorage->pokemonSummaryScreenMode = PSS_MODE_BOX;
    }
}

static void SetSelectionAfterSummaryScreen(void)
{
    if (sIsMonBeingMoved)
        LoadSavedMovingMon();
    else
        sBoxCursorPosition = gLastViewedMonIndex;
}

s16 CompactPartySlots(void)
{
    s16 retVal = -1;
    u16 i, last;

    for (i = 0, last = 0; i < PARTY_SIZE; i++)
    {
        u16 species = GetMonData(gPlayerParty + i, MON_DATA_SPECIES);
        if (species != SPECIES_NONE)
        {
            if (i != last)
                gPlayerParty[last] = gPlayerParty[i];
            last++;
        }
        else if (retVal == -1)
        {
            retVal = i;
        }
    }
    for (; last < PARTY_SIZE; last++)
        ZeroMonData(gPlayerParty + last);

    return retVal;
}

static void SetMonMarkings(u8 markings)
{
    sStorage->cursorMonMarkings = markings;
    if (sIsMonBeingMoved)
    {
        SetMonData(&sStorage->movingMon, MON_DATA_MARKINGS, &markings);
    }
    else
    {
        if (sBoxCursorArea == CURSOR_AREA_IN_PARTY)
            SetMonData(gPlayerParty + sBoxCursorPosition, MON_DATA_MARKINGS, &markings);
        if (sBoxCursorArea == CURSOR_AREA_IN_BOX)
            SetCurrentBoxMonData(sBoxCursorPosition, MON_DATA_MARKINGS, &markings);
    }
}

static bool8 IsRemovingLastPartyMon(void)
{
    if (sBoxCursorArea == CURSOR_AREA_IN_PARTY && !sIsMonBeingMoved && CountPartyAliveNonEggMonsExcept(sBoxCursorPosition) == 0)
        return TRUE;
    else
        return FALSE;
}

static bool8 CanShiftMon(void)
{
    if (sIsMonBeingMoved)
    {
        if (sBoxCursorArea == CURSOR_AREA_IN_PARTY && CountPartyAliveNonEggMonsExcept(sBoxCursorPosition) == 0)
        {
            if (sStorage->cursorMonIsEgg || GetMonData(&sStorage->movingMon, MON_DATA_HP) == 0)
                return FALSE;
        }
        return TRUE;
    }
    return FALSE;
}

static bool8 IsMonBeingMoved(void)
{
    return sIsMonBeingMoved;
}

static bool8 IsCursorOnBox(void)
{
    return (sBoxCursorArea == CURSOR_AREA_BOX);
}

static bool8 IsCursorOnCloseBox(void)
{
    return (sBoxCursorArea == CURSOR_AREA_BUTTONS && sBoxCursorPosition == 1);
}

static bool8 IsCursorInBox(void)
{
    return (sBoxCursorArea == CURSOR_AREA_IN_BOX);
}

static void sub_80CEB40(void)
{
    sStorage->setMosaic = (sIsMonBeingMoved == FALSE);
    if (!sIsMonBeingMoved)
    {
        switch (sBoxCursorArea)
        {
        case CURSOR_AREA_IN_PARTY:
            if (sBoxCursorPosition < PARTY_SIZE)
            {
                SetCursorMonData(&gPlayerParty[sBoxCursorPosition], MODE_PARTY);
                break;
            }
            // fallthrough
        case CURSOR_AREA_BUTTONS:
        case CURSOR_AREA_BOX:
            SetCursorMonData(NULL, MODE_MOVE);
            break;
        case CURSOR_AREA_IN_BOX:
            SetCursorMonData(GetBoxedMonPtr(StorageGetCurrentBox(), sBoxCursorPosition), MODE_BOX);
            break;
        }
    }
}

static void sub_80CEBDC(void)
{
    if (sIsMonBeingMoved)
        SetCursorMonData(&gUnknown_02039D14, MODE_PARTY);
    else
        sub_80CEB40();
}

void SetArceusFormPSS(struct BoxPokemon *boxMon)
{
#ifdef POKEMON_EXPANSION
    u16 species = GetMonData(boxMon, MON_DATA_SPECIES);
	u16 formid = GetMonData(boxMon, MON_DATA_FORM_ID);
	u16 newformid;
    u16 forme;
    u8 abilityNum = GetMonData(boxMon, MON_DATA_ABILITY_NUM);
    u16 ability = GetAbilityBySpecies(species, abilityNum, formid);

    if (species == SPECIES_ARCEUS
     && ability == ABILITY_MULTITYPE)
    {
        forme = GetArceusFormPSS(boxMon);
		newformid = GetFormIdFromFormSpeciesId(forme);
        SetBoxMonData(boxMon, MON_DATA_FORM_ID, &newformid);
        UpdateSpeciesSpritePSS(boxMon);
    }
	else if (species == SPECIES_SILVALLY
     && ability == ABILITY_RKS_SYSTEM)
    {
        forme = GetSilvallyFormPSS(boxMon);
		newformid = GetFormIdFromFormSpeciesId(forme);
        SetBoxMonData(boxMon, MON_DATA_FORM_ID, &newformid);
        UpdateSpeciesSpritePSS(boxMon);
    }
#endif
}

u16 GetArceusFormPSS(struct BoxPokemon *boxMon)
{
    u16 item = GetMonData(boxMon, MON_DATA_HELD_ITEM, NULL);

    switch (item)
    {
#if defined (ITEM_EXPANSION) && defined (POKEMON_EXPANSION)
        case ITEM_FLAME_PLATE:
            return SPECIES_ARCEUS_FIRE;
        case ITEM_SPLASH_PLATE:
            return SPECIES_ARCEUS_WATER;
        case ITEM_ZAP_PLATE:
            return SPECIES_ARCEUS_ELECTRIC;
        case ITEM_MEADOW_PLATE:
            return SPECIES_ARCEUS_GRASS;
        case ITEM_ICICLE_PLATE:
            return SPECIES_ARCEUS_ICE;
        case ITEM_FIST_PLATE:
            return SPECIES_ARCEUS_FIGHTING;
        case ITEM_TOXIC_PLATE:
            return SPECIES_ARCEUS_POISON;
        case ITEM_EARTH_PLATE:
            return SPECIES_ARCEUS_GROUND;
        case ITEM_SKY_PLATE:
            return SPECIES_ARCEUS_FLYING;
        case ITEM_MIND_PLATE:
            return SPECIES_ARCEUS_PSYCHIC;
        case ITEM_INSECT_PLATE:
            return SPECIES_ARCEUS_BUG;
        case ITEM_STONE_PLATE:
            return SPECIES_ARCEUS_ROCK;
        case ITEM_SPOOKY_PLATE:
            return SPECIES_ARCEUS_GHOST;
        case ITEM_DRACO_PLATE:
            return SPECIES_ARCEUS_DRAGON;
        case ITEM_DREAD_PLATE:
            return SPECIES_ARCEUS_DARK;
        case ITEM_IRON_PLATE:
            return SPECIES_ARCEUS_STEEL;
        case ITEM_PIXIE_PLATE:
            return SPECIES_ARCEUS_FAIRY;
#endif
        default:
            return SPECIES_ARCEUS;
    }
}

u16 GetSilvallyFormPSS(struct BoxPokemon *boxMon)
{
    u16 item = GetMonData(boxMon, MON_DATA_HELD_ITEM, NULL);

    switch (item)
    {
#if defined (ITEM_EXPANSION) && defined (POKEMON_EXPANSION)
        case ITEM_FIRE_MEMORY:
            return SPECIES_SILVALLY_FIRE;
        case ITEM_WATER_MEMORY:
            return SPECIES_SILVALLY_WATER;
        case ITEM_ELECTRIC_MEMORY:
            return SPECIES_SILVALLY_ELECTRIC;
        case ITEM_GRASS_MEMORY:
            return SPECIES_SILVALLY_GRASS;
        case ITEM_ICE_MEMORY:
            return SPECIES_SILVALLY_ICE;
        case ITEM_FIGHTING_MEMORY:
            return SPECIES_SILVALLY_FIGHTING;
        case ITEM_POISON_MEMORY:
            return SPECIES_SILVALLY_POISON;
        case ITEM_GROUND_MEMORY:
            return SPECIES_SILVALLY_GROUND;
        case ITEM_FLYING_MEMORY:
            return SPECIES_SILVALLY_FLYING;
        case ITEM_PSYCHIC_MEMORY:
            return SPECIES_SILVALLY_PSYCHIC;
        case ITEM_BUG_MEMORY:
            return SPECIES_SILVALLY_BUG;
        case ITEM_ROCK_MEMORY:
            return SPECIES_SILVALLY_ROCK;
        case ITEM_GHOST_MEMORY:
            return SPECIES_SILVALLY_GHOST;
        case ITEM_DRAGON_MEMORY:
            return SPECIES_SILVALLY_DRAGON;
        case ITEM_DARK_MEMORY:
            return SPECIES_SILVALLY_DARK;
        case ITEM_STEEL_MEMORY:
            return SPECIES_SILVALLY_STEEL;
        case ITEM_FAIRY_MEMORY:
            return SPECIES_SILVALLY_FAIRY;
#endif
        default:
            return SPECIES_SILVALLY;
    }
}

static void SetCursorMonData(void *pokemon, u8 mode)
{
    u8 *txtPtr;
    u16 gender;
    bool8 sanityIsBagEgg;

    sStorage->cursorMonItem = 0;
    gender = MON_MALE;
    sanityIsBagEgg = FALSE;
    if (mode == MODE_PARTY)
    {
        struct Pokemon *mon = (struct Pokemon *)pokemon;

        sStorage->cursorMonSpecies = GetMonData(mon, MON_DATA_SPECIES2);
        if (sStorage->cursorMonSpecies != SPECIES_NONE)
        {
            sanityIsBagEgg = GetMonData(mon, MON_DATA_SANITY_IS_BAD_EGG);
            if (sanityIsBagEgg)
                sStorage->cursorMonIsEgg = TRUE;
            else
                sStorage->cursorMonIsEgg = GetMonData(mon, MON_DATA_IS_EGG);

            sStorage->cursorMonFormId = GetMonData(mon, MON_DATA_FORM_ID);
            GetMonData(mon, MON_DATA_NICKNAME, sStorage->cursorMonNick);
            StringGetEnd10(sStorage->cursorMonNick);
            sStorage->cursorMonLevel = GetMonData(mon, MON_DATA_LEVEL);
            sStorage->cursorMonMarkings = GetMonData(mon, MON_DATA_MARKINGS);
            sStorage->cursorMonPersonality = GetMonData(mon, MON_DATA_PERSONALITY);
            sStorage->cursorMonPalette = GetMonFrontSpritePal(mon);
            gender = GetMonGender(mon);
            sStorage->cursorMonItem = GetMonData(mon, MON_DATA_HELD_ITEM);
        }
    }
    else if (mode == MODE_BOX)
    {
        struct BoxPokemon *boxMon = (struct BoxPokemon *)pokemon;

        sStorage->cursorMonSpecies = GetBoxMonData(pokemon, MON_DATA_SPECIES2);
        if (sStorage->cursorMonSpecies != SPECIES_NONE)
        {
            u32 otId = GetBoxMonData(boxMon, MON_DATA_OT_ID);
			u16 formSpeciesId;
            sanityIsBagEgg = GetBoxMonData(boxMon, MON_DATA_SANITY_IS_BAD_EGG);
            if (sanityIsBagEgg)
                sStorage->cursorMonIsEgg = TRUE;
            else
                sStorage->cursorMonIsEgg = GetBoxMonData(boxMon, MON_DATA_IS_EGG);

            sStorage->cursorMonFormId = GetMonData(boxMon, MON_DATA_FORM_ID);
			formSpeciesId = GetFormSpeciesId(sStorage->cursorMonSpecies, sStorage->cursorMonFormId);
            GetBoxMonData(boxMon, MON_DATA_NICKNAME, sStorage->cursorMonNick);
            StringGetEnd10(sStorage->cursorMonNick);
            sStorage->cursorMonLevel = GetLevelFromBoxMonExp(boxMon);
            sStorage->cursorMonMarkings = GetBoxMonData(boxMon, MON_DATA_MARKINGS);
            sStorage->cursorMonPersonality = GetBoxMonData(boxMon, MON_DATA_PERSONALITY);
            sStorage->cursorMonPalette = GetMonSpritePalFromSpeciesAndPersonality(formSpeciesId, otId, sStorage->cursorMonPersonality);
            gender = GetGenderFromSpeciesAndPersonality(sStorage->cursorMonSpecies, sStorage->cursorMonPersonality);
            sStorage->cursorMonItem = GetBoxMonData(boxMon, MON_DATA_HELD_ITEM);
        }
    }
    else
    {
        sStorage->cursorMonSpecies = SPECIES_NONE;
        sStorage->cursorMonItem = 0;
    }

    if (sStorage->cursorMonSpecies == SPECIES_NONE)
    {
        StringFill(sStorage->cursorMonNick, CHAR_SPACE, 5);
        StringFill(sStorage->cursorMonNickText, CHAR_SPACE, 8);
        StringFill(sStorage->cursorMonSpeciesName, CHAR_SPACE, 8);
        StringFill(sStorage->cursorMonGenderLvlText, CHAR_SPACE, 8);
        StringFill(sStorage->cursorMonItemName, CHAR_SPACE, 8);
    }
    else if (sStorage->cursorMonIsEgg)
    {
        if (sanityIsBagEgg)
            StringCopyPadded(sStorage->cursorMonNickText, sStorage->cursorMonNick, CHAR_SPACE, 5);
        else
            StringCopyPadded(sStorage->cursorMonNickText, gText_EggNickname, CHAR_SPACE, 8);

        StringFill(sStorage->cursorMonSpeciesName, CHAR_SPACE, 8);
        StringFill(sStorage->cursorMonGenderLvlText, CHAR_SPACE, 8);
        StringFill(sStorage->cursorMonItemName, CHAR_SPACE, 8);
    }
    else
    {
        if (sStorage->cursorMonSpecies == SPECIES_NIDORAN_F || sStorage->cursorMonSpecies == SPECIES_NIDORAN_M)
            gender = MON_GENDERLESS;
		
		 #ifdef POKEMON_EXPANSION
        if (sStorage->cursorMonSpecies == SPECIES_ARCEUS)
            SetArceusFormPSS(pokemon);
		#endif

        StringCopyPadded(sStorage->cursorMonNickText, sStorage->cursorMonNick, CHAR_SPACE, 5);

        txtPtr = sStorage->cursorMonSpeciesName;
        *(txtPtr)++ = CHAR_SLASH;
        StringCopyPadded(txtPtr, gSpeciesNames[sStorage->cursorMonSpecies], CHAR_SPACE, 5);

        txtPtr = sStorage->cursorMonGenderLvlText;
        *(txtPtr)++ = EXT_CTRL_CODE_BEGIN;
        *(txtPtr)++ = EXT_CTRL_CODE_COLOR_HIGHLIGHT_SHADOW;
        switch (gender)
        {
        case MON_MALE:
            *(txtPtr)++ = TEXT_COLOR_RED;
            *(txtPtr)++ = TEXT_COLOR_WHITE;
            *(txtPtr)++ = TEXT_COLOR_LIGHT_RED;
            *(txtPtr)++ = CHAR_MALE;
            break;
        case MON_FEMALE:
            *(txtPtr)++ = TEXT_COLOR_GREEN;
            *(txtPtr)++ = TEXT_COLOR_WHITE;
            *(txtPtr)++ = TEXT_COLOR_LIGHT_GREEN;
            *(txtPtr)++ = CHAR_FEMALE;
            break;
        default:
            *(txtPtr)++ = TEXT_COLOR_DARK_GREY;
            *(txtPtr)++ = TEXT_COLOR_WHITE;
            *(txtPtr)++ = TEXT_COLOR_LIGHT_GREY;
            *(txtPtr)++ = CHAR_UNK_SPACER;
            break;
        }

        *(txtPtr++) = EXT_CTRL_CODE_BEGIN;
        *(txtPtr++) = EXT_CTRL_CODE_COLOR_HIGHLIGHT_SHADOW;
        *(txtPtr++) = TEXT_COLOR_DARK_GREY;
        *(txtPtr++) = TEXT_COLOR_WHITE;
        *(txtPtr++) = TEXT_COLOR_LIGHT_GREY;
        *(txtPtr++) = CHAR_SPACE;
        *(txtPtr++) = CHAR_EXTRA_SYMBOL;
        *(txtPtr++) = CHAR_LV_2;

        txtPtr = ConvertIntToDecimalStringN(txtPtr, sStorage->cursorMonLevel, STR_CONV_MODE_LEFT_ALIGN, 3);
        txtPtr[0] = CHAR_SPACE;
        txtPtr[1] = EOS;

        if (sStorage->cursorMonItem != 0)
            StringCopyPadded(sStorage->cursorMonItemName, ItemId_GetName(sStorage->cursorMonItem), CHAR_SPACE, 8);
        else
            StringFill(sStorage->cursorMonItemName, CHAR_SPACE, 8);
    }
}

void UpdateSpeciesSpritePSS(struct BoxPokemon *boxMon)
{
    u16 species = GetBoxMonData(boxMon, MON_DATA_SPECIES);
	u16 formid = GetMonData(boxMon, MON_DATA_FORM_ID);
    u32 otId = GetBoxMonData(boxMon, MON_DATA_OT_ID);
    u32 pid = GetBoxMonData(boxMon, MON_DATA_PERSONALITY);

    // Update front sprite
    sStorage->cursorMonSpecies = species;
    sStorage->cursorMonPalette = GetMonSpritePalFromSpeciesAndPersonality(species, otId, pid);
    LoadCursorMonGfx(species, pid, formid);
}

static u8 HandleInput_InBox(void)
{
    switch (sStorage->inBoxMovingMode)
    {
    case MOVE_MODE_NORMAL:
    default:
        return InBoxInput_Normal();
    case MOVE_MODE_MULTIPLE_SELECTING:
        return InBoxInput_GrabbingMultiple();
    case MOVE_MODE_MULTIPLE_MOVING:
        return InBoxInput_MovingMultiple();
    }
}

static u8 InBoxInput_Normal(void)
{
    u8 retVal;
    s8 cursorArea;
    s8 cursorPosition;

    do
    {
        cursorArea = sBoxCursorArea;
        cursorPosition = sBoxCursorPosition;
        sStorage->cursorVerticalWrap = 0;
        sStorage->cursorHorizontalWrap = 0;
        sStorage->cursorFlipTimer = 0;

        if (JOY_REPEAT(DPAD_UP))
        {
            retVal = TRUE;
            if (sBoxCursorPosition >= IN_BOX_ROWS)
            {
                cursorPosition -= IN_BOX_ROWS;
            }
            else
            {
                cursorArea = CURSOR_AREA_BOX;
                cursorPosition = 0;
            }
            break;
        }
        else if (JOY_REPEAT(DPAD_DOWN))
        {
            retVal = TRUE;
            cursorPosition += IN_BOX_ROWS;
            if (cursorPosition >= IN_BOX_COUNT)
            {
                cursorArea = CURSOR_AREA_BUTTONS;
                cursorPosition -= IN_BOX_COUNT;
                cursorPosition /= 3;
                sStorage->cursorVerticalWrap = 1;
                sStorage->cursorFlipTimer = 1;
            }
            break;
        }
        else if (JOY_REPEAT(DPAD_LEFT))
        {
            retVal = TRUE;
            if (sBoxCursorPosition % IN_BOX_ROWS != 0)
            {
                cursorPosition--;
            }
            else
            {
                sStorage->cursorHorizontalWrap = -1;
                cursorPosition += (IN_BOX_ROWS - 1);
            }
            break;
        }
        else if (JOY_REPEAT(DPAD_RIGHT))
        {
            retVal = TRUE;
            if ((sBoxCursorPosition + 1) % IN_BOX_ROWS != 0)
            {
                cursorPosition++;
            }
            else
            {
                sStorage->cursorHorizontalWrap = 1;
                cursorPosition -= (IN_BOX_ROWS - 1);
            }
            break;
        }
        else if (JOY_NEW(START_BUTTON))
        {
            retVal = TRUE;
            cursorArea = CURSOR_AREA_BOX;
            cursorPosition = 0;
            break;
        }

        if ((JOY_NEW(A_BUTTON)) && SetSelectionMenuTexts())
        {
            if (!sCanOnlyMove)
                return INPUT_IN_MENU;

            if (sStorage->boxOption != OPTION_MOVE_MONS || sIsMonBeingMoved == TRUE)
            {
                switch (GetMenuItemTextId(0))
                {
                case MENU_STORE:
                    return INPUT_DEPOSIT;
                case MENU_WITHDRAW:
                    return INPUT_WITHDRAW;
                case MENU_MOVE:
                    return INPUT_MOVE_MON;
                case MENU_SHIFT:
                    return INPUT_SHIFT_MON;
                case MENU_PLACE:
                    return INPUT_PLACE_MON;
                case MENU_TAKE:
                    return INPUT_TAKE_ITEM;
                case MENU_GIVE:
                    return INPUT_GIVE_ITEM;
                case MENU_SWITCH:
                    return INPUT_SWITCH_ITEMS;
                }
            }
            else
            {
                sStorage->inBoxMovingMode = MOVE_MODE_MULTIPLE_SELECTING;
                return INPUT_MULTIMOVE_START;
            }
        }

        if (JOY_NEW(B_BUTTON))
            return 19;

        if (gSaveBlock2Ptr->optionsButtonMode == OPTIONS_BUTTON_MODE_LR)
        {
            if (JOY_HELD(L_BUTTON))
                return 10;
            if (JOY_HELD(R_BUTTON))
                return 9;
        }

        if (JOY_NEW(SELECT_BUTTON))
        {
            sub_80CFDC4();
            return 0;
        }

        retVal = 0;

    } while (0);

    if (retVal)
        sub_80CD894(cursorArea, cursorPosition);

    return retVal;
}

static u8 InBoxInput_GrabbingMultiple(void)
{
    if (JOY_HELD(A_BUTTON))
    {
        if (JOY_REPEAT(DPAD_UP))
        {
            if (sBoxCursorPosition / IN_BOX_ROWS != 0)
            {
                sub_80CD894(CURSOR_AREA_IN_BOX, sBoxCursorPosition - IN_BOX_ROWS);
                return 21;
            }
            else
            {
                return 24;
            }
        }
        else if (JOY_REPEAT(DPAD_DOWN))
        {
            if (sBoxCursorPosition + IN_BOX_ROWS < IN_BOX_COUNT)
            {
                sub_80CD894(CURSOR_AREA_IN_BOX, sBoxCursorPosition + IN_BOX_ROWS);
                return 21;
            }
            else
            {
                return 24;
            }
        }
        else if (JOY_REPEAT(DPAD_LEFT))
        {
            if (sBoxCursorPosition % IN_BOX_ROWS != 0)
            {
                sub_80CD894(CURSOR_AREA_IN_BOX, sBoxCursorPosition - 1);
                return 21;
            }
            else
            {
                return 24;
            }
        }
        else if (JOY_REPEAT(DPAD_RIGHT))
        {
            if ((sBoxCursorPosition + 1) % IN_BOX_ROWS != 0)
            {
                sub_80CD894(CURSOR_AREA_IN_BOX, sBoxCursorPosition + 1);
                return 21;
            }
            else
            {
                return 24;
            }
        }
        else
        {
            return 0;
        }
    }
    else
    {
        if (sub_80D0BA4() == sBoxCursorPosition)
        {
            sStorage->inBoxMovingMode = 0;
            sStorage->cursorShadowSprite->invisible = FALSE;
            return 22;
        }
        else
        {
            sIsMonBeingMoved = (sStorage->cursorMonSpecies != SPECIES_NONE);
            sStorage->inBoxMovingMode = 2;
            sMovingMonOrigBoxId = StorageGetCurrentBox();
            return 23;
        }
    }
}

static u8 InBoxInput_MovingMultiple(void)
{
    if (JOY_REPEAT(DPAD_UP))
    {
        if (sub_80D0580(0))
        {
            sub_80CD894(CURSOR_AREA_IN_BOX, sBoxCursorPosition - IN_BOX_ROWS);
            return 25;
        }
        else
        {
            return 24;
        }
    }
    else if (JOY_REPEAT(DPAD_DOWN))
    {
        if (sub_80D0580(1))
        {
            sub_80CD894(CURSOR_AREA_IN_BOX, sBoxCursorPosition + IN_BOX_ROWS);
            return 25;
        }
        else
        {
            return 24;
        }
    }
    else if (JOY_REPEAT(DPAD_LEFT))
    {
        if (sub_80D0580(2))
        {
            sub_80CD894(CURSOR_AREA_IN_BOX, sBoxCursorPosition - 1);
            return 25;
        }
        else
        {
            return 10;
        }
    }
    else if (JOY_REPEAT(DPAD_RIGHT))
    {
        if (sub_80D0580(3))
        {
            sub_80CD894(CURSOR_AREA_IN_BOX, sBoxCursorPosition + 1);
            return 25;
        }
        else
        {
            return 9;
        }
    }
    else if (JOY_NEW(A_BUTTON))
    {
        if (sub_80D0BC0())
        {
            sIsMonBeingMoved = FALSE;
            sStorage->inBoxMovingMode = 0;
            return 26;
        }
        else
        {
            return 24;
        }
    }
    else if (JOY_NEW(B_BUTTON))
    {
        return 24;
    }
    else
    {
        if (gSaveBlock2Ptr->optionsButtonMode == OPTIONS_BUTTON_MODE_LR)
        {
            if (JOY_HELD(L_BUTTON))
                return 10;
            if (JOY_HELD(R_BUTTON))
                return 9;
        }

        return 0;
    }
}

static u8 HandleInput_InParty(void)
{
    u8 retVal;
    bool8 gotoBox;
    s8 cursorArea;
    s8 cursorPosition;

    do
    {
        cursorArea = sBoxCursorArea;
        cursorPosition = sBoxCursorPosition;
        sStorage->cursorHorizontalWrap = 0;
        sStorage->cursorVerticalWrap = 0;
        sStorage->cursorFlipTimer = 0;
        gotoBox = FALSE;
        retVal = 0;

        if (JOY_REPEAT(DPAD_UP))
        {
            if (--cursorPosition < 0)
                cursorPosition = PARTY_SIZE;
            if (cursorPosition != sBoxCursorPosition)
                retVal = 1;
            break;
        }
        else if (JOY_REPEAT(DPAD_DOWN))
        {
            if (++cursorPosition > PARTY_SIZE)
                cursorPosition = 0;
            if (cursorPosition != sBoxCursorPosition)
                retVal = 1;
            break;
        }
        else if (JOY_REPEAT(DPAD_LEFT) && sBoxCursorPosition != 0)
        {
            retVal = 1;
            sStorage->cursorPrevHorizPos = sBoxCursorPosition;
            cursorPosition = 0;
            break;
        }
        else if (JOY_REPEAT(DPAD_RIGHT))
        {
            if (sBoxCursorPosition == 0)
            {
                retVal = 1;
                cursorPosition = sStorage->cursorPrevHorizPos;
            }
            else
            {
                retVal = 6;
                cursorArea = CURSOR_AREA_IN_BOX;
                cursorPosition = 0;
            }
            break;
        }

        if (JOY_NEW(A_BUTTON))
        {
            if (sBoxCursorPosition == PARTY_SIZE)
            {
                if (sStorage->boxOption == OPTION_DEPOSIT)
                    return 4;

                gotoBox = TRUE;
            }
            else if (SetSelectionMenuTexts())
            {
                if (!sCanOnlyMove)
                    return 8;

                switch (GetMenuItemTextId(0))
                {
                case 1:
                    return 11;
                case 2:
                    return 12;
                case 3:
                    return 13;
                case 4:
                    return 14;
                case 5:
                    return 15;
                case 12:
                    return 16;
                case 13:
                    return 17;
                case 15:
                    return 18;
                }
            }
        }

        if (JOY_NEW(B_BUTTON))
        {
            if (sStorage->boxOption == OPTION_DEPOSIT)
                return 19;

            gotoBox = TRUE;
        }

        if (gotoBox)
        {
            retVal = 6;
            cursorArea = CURSOR_AREA_IN_BOX;
            cursorPosition = 0;
        }
        else if (JOY_NEW(SELECT_BUTTON))
        {
            sub_80CFDC4();
            return 0;
        }

    } while (0);

    if (retVal != 0)
    {
        if (retVal != 6)
            sub_80CD894(cursorArea, cursorPosition);
    }

    return retVal;
}

static u8 HandleInput_OnBox(void)
{
    u8 retVal;
    s8 cursorArea;
    s8 cursorPosition;

    do
    {
        sStorage->cursorHorizontalWrap = 0;
        sStorage->cursorVerticalWrap = 0;
        sStorage->cursorFlipTimer = 0;

        if (JOY_REPEAT(DPAD_UP))
        {
            retVal = 1;
            cursorArea = CURSOR_AREA_BUTTONS;
            cursorPosition = 0;
            sStorage->cursorFlipTimer = 1;
            break;
        }
        else if (JOY_REPEAT(DPAD_DOWN))
        {
            retVal = 1;
            cursorArea = CURSOR_AREA_IN_BOX;
            cursorPosition = 2;
            break;
        }

        if (JOY_HELD(DPAD_LEFT))
            return 10;
        if (JOY_HELD(DPAD_RIGHT))
            return 9;

        if (gSaveBlock2Ptr->optionsButtonMode == OPTIONS_BUTTON_MODE_LR)
        {
            if (JOY_HELD(L_BUTTON))
                return 10;
            if (JOY_HELD(R_BUTTON))
                return 9;
        }

        if (JOY_NEW(A_BUTTON))
        {
            AnimateBoxScrollArrows(FALSE);
            AddBoxMenu();
            return 7;
        }

        if (JOY_NEW(B_BUTTON))
            return 19;

        if (JOY_NEW(SELECT_BUTTON))
        {
            sub_80CFDC4();
            return 0;
        }

        retVal = 0;

    } while (0);

    if (retVal)
    {
        if (cursorArea != CURSOR_AREA_BOX)
            AnimateBoxScrollArrows(FALSE);
        sub_80CD894(cursorArea, cursorPosition);
    }

    return retVal;
}

static u8 HandleInput_OnButtons(void)
{
    u8 retVal;
    s8 cursorArea;
    s8 cursorPosition;

    do
    {
        cursorArea = sBoxCursorArea;
        cursorPosition = sBoxCursorPosition;
        sStorage->cursorHorizontalWrap = 0;
        sStorage->cursorVerticalWrap = 0;
        sStorage->cursorFlipTimer = 0;

        if (JOY_REPEAT(DPAD_UP))
        {
            retVal = 1;
            cursorArea = CURSOR_AREA_IN_BOX;
            sStorage->cursorVerticalWrap = -1;
            if (sBoxCursorPosition == 0)
                cursorPosition = IN_BOX_COUNT - 1 - 5;
            else 
                cursorPosition = IN_BOX_COUNT - 1;
            sStorage->cursorFlipTimer = 1;
            break;
        }

        if (JOY_REPEAT(DPAD_DOWN | START_BUTTON))
        {
            retVal = 1;
            cursorArea = CURSOR_AREA_BOX;
            cursorPosition = 0;
            sStorage->cursorFlipTimer = 1;
            break;
        }

        if (JOY_REPEAT(DPAD_LEFT))
        {
            retVal = 1;
            if (--cursorPosition < 0)
                cursorPosition = 1;
            break;
        }
        else if (JOY_REPEAT(DPAD_RIGHT))
        {
            retVal = 1;
            if (++cursorPosition > 1)
                cursorPosition = 0;
            break;
        }

        if (JOY_NEW(A_BUTTON))
            return (cursorPosition == 0) ? 5 : 4;
        if (JOY_NEW(B_BUTTON))
            return 19;

        if (JOY_NEW(SELECT_BUTTON))
        {
            sub_80CFDC4();
            return 0;
        }

        retVal = 0;
    } while (0);

    if (retVal != 0)
        sub_80CD894(cursorArea, cursorPosition);

    return retVal;
}

static u8 HandleInput(void)
{
    struct
    {
        u8 (*func)(void);
        s8 area;
    }
    static const inputFuncs[] =
    {
        {HandleInput_InBox, CURSOR_AREA_IN_BOX},
        {HandleInput_InParty, CURSOR_AREA_IN_PARTY},
        {HandleInput_OnBox, CURSOR_AREA_BOX},
        {HandleInput_OnButtons, CURSOR_AREA_BUTTONS},
        {NULL, 0},
    };

    u16 i = 0;
    while (inputFuncs[i].func != NULL)
    {
        if (inputFuncs[i].area == sBoxCursorArea)
            return inputFuncs[i].func();
        i++;
    }

    return 0;
}

static void AddBoxMenu(void)
{
    InitMenu();
    SetMenuText(9);
    SetMenuText(10);
    SetMenuText(11);
    SetMenuText(0);
}

static u8 SetSelectionMenuTexts(void)
{
    InitMenu();
    if (sStorage->boxOption != OPTION_MOVE_ITEMS)
        return SetMenuTexts_Mon();
    else
        return SetMenuTexts_Item();
}

static bool8 SetMenuTexts_Mon(void)
{
    u16 species = GetSpeciesAtCursorPosition();

    switch (sStorage->boxOption)
    {
    case OPTION_DEPOSIT:
        if (species != SPECIES_NONE)
            SetMenuText(MENU_STORE);
        else
            return FALSE;
        break;
    case OPTION_WITHDRAW:
        if (species != SPECIES_NONE)
            SetMenuText(MENU_WITHDRAW);
        else
            return FALSE;
        break;
    case OPTION_MOVE_MONS:
        if (sIsMonBeingMoved)
        {
            if (species != SPECIES_NONE)
                SetMenuText(MENU_SHIFT);
            else
                SetMenuText(MENU_PLACE);
        }
        else
        {
            if (species != SPECIES_NONE)
                SetMenuText(MENU_MOVE);
            else
                return FALSE;
        }
        break;
    case OPTION_MOVE_ITEMS:
    default:
        return FALSE;
    }

    SetMenuText(MENU_SUMMARY);
    if (sStorage->boxOption == OPTION_MOVE_MONS)
    {
        if (sBoxCursorArea == CURSOR_AREA_IN_BOX)
            SetMenuText(MENU_WITHDRAW);
        else
            SetMenuText(MENU_STORE);
    }

    SetMenuText(MENU_MARK);
    SetMenuText(MENU_RELEASE);
    SetMenuText(MENU_CANCEL);
    return TRUE;
}

static bool8 SetMenuTexts_Item(void)
{
    if (sStorage->cursorMonSpecies == SPECIES_EGG)
        return FALSE;

    if (!IsActiveItemMoving())
    {
        if (sStorage->cursorMonItem == 0)
        {
            if (sStorage->cursorMonSpecies == SPECIES_NONE)
                return FALSE;

            SetMenuText(14);
        }
        else
        {
            if (!ItemIsMail(sStorage->cursorMonItem))
            {
                SetMenuText(12);
                SetMenuText(16);
            }
            SetMenuText(17);
        }
    }
    else
    {
        if (sStorage->cursorMonItem == 0)
        {
            if (sStorage->cursorMonSpecies == SPECIES_NONE)
                return FALSE;

            SetMenuText(13);
        }
        else
        {
            if (ItemIsMail(sStorage->cursorMonItem) == TRUE)
                return FALSE;

            SetMenuText(15);
        }
    }

    SetMenuText(0);
    return TRUE;
}

static void sub_80CFBF4(struct Sprite *sprite)
{
    sprite->pos1.x = sStorage->cursorSprite->pos1.x;
    sprite->pos1.y = sStorage->cursorSprite->pos1.y + 20;
}

static void sub_80CFC14(void)
{
    u16 x, y;
    u8 spriteId;
    u8 priority, subpriority;
    struct SpriteSheet spriteSheets[] =
    {
        {gHandCursorTiles, 0x800, 0},
        {gHandCursorShadowTiles, 0x80, 1},
        {}
    };

    struct SpritePalette spritePalettes[] =
    {
        {gHandCursorPalette, TAG_PAL_DAC7},
        {}
    };

    static const struct OamData sOamData_857BA0C =
    {
        .shape = SPRITE_SHAPE(32x32),
        .size = SPRITE_SIZE(32x32),
        .priority = 1,
    };
    static const struct OamData sOamData_857BA14 =
    {
        .shape = SPRITE_SHAPE(16x16),
        .size = SPRITE_SIZE(16x16),
        .priority = 1,
    };

    static const union AnimCmd sSpriteAnim_857BA1C[] =
    {
        ANIMCMD_FRAME(0, 30),
        ANIMCMD_FRAME(16, 30),
        ANIMCMD_JUMP(0)
    };
    static const union AnimCmd sSpriteAnim_857BA28[] =
    {
        ANIMCMD_FRAME(0, 5),
        ANIMCMD_END
    };
    static const union AnimCmd sSpriteAnim_857BA30[] =
    {
        ANIMCMD_FRAME(32, 5),
        ANIMCMD_END
    };
    static const union AnimCmd sSpriteAnim_857BA38[] =
    {
        ANIMCMD_FRAME(48, 5),
        ANIMCMD_END
    };

    static const union AnimCmd *const sSpriteAnimTable_857BA40[] =
    {
        sSpriteAnim_857BA1C,
        sSpriteAnim_857BA28,
        sSpriteAnim_857BA30,
        sSpriteAnim_857BA38
    };

    static const struct SpriteTemplate gSpriteTemplate_857BA50 =
    {
        .tileTag = TAG_TILE_0,
        .paletteTag = TAG_PAL_WAVEFORM,
        .oam = &sOamData_857BA0C,
        .anims = sSpriteAnimTable_857BA40,
        .images = NULL,
        .affineAnims = gDummySpriteAffineAnimTable,
        .callback = SpriteCallbackDummy,
    };

    static const struct SpriteTemplate gSpriteTemplate_857BA68 =
    {
        .tileTag = TAG_TILE_1,
        .paletteTag = TAG_PAL_WAVEFORM,
        .oam = &sOamData_857BA14,
        .anims = gDummySpriteAnimTable,
        .images = NULL,
        .affineAnims = gDummySpriteAffineAnimTable,
        .callback = sub_80CFBF4,
    };

    LoadSpriteSheets(spriteSheets);
    LoadSpritePalettes(spritePalettes);
    sStorage->cursorPalNums[0] = IndexOfSpritePaletteTag(TAG_PAL_WAVEFORM);
    sStorage->cursorPalNums[1] = IndexOfSpritePaletteTag(TAG_PAL_DAC7);

    sub_80CD444(sBoxCursorArea, sBoxCursorPosition, &x, &y);
    spriteId = CreateSprite(&gSpriteTemplate_857BA50, x, y, 6);
    if (spriteId != MAX_SPRITES)
    {
        sStorage->cursorSprite = &gSprites[spriteId];
        sStorage->cursorSprite->oam.paletteNum = sStorage->cursorPalNums[sCanOnlyMove];
        sStorage->cursorSprite->oam.priority = 1;
        if (sIsMonBeingMoved)
            StartSpriteAnim(sStorage->cursorSprite, 3);
    }
    else
    {
        sStorage->cursorSprite = NULL;
    }

    if (sBoxCursorArea == CURSOR_AREA_IN_PARTY)
    {
        subpriority = 13;
        priority = 1;
    }
    else
    {
        subpriority = 21;
        priority = 2;
    }

    spriteId = CreateSprite(&gSpriteTemplate_857BA68, 0, 0, subpriority);
    if (spriteId != MAX_SPRITES)
    {
        sStorage->cursorShadowSprite = &gSprites[spriteId];
        sStorage->cursorShadowSprite->oam.priority = priority;
        if (sBoxCursorArea)
            sStorage->cursorShadowSprite->invisible = 1;
    }
    else
    {
        sStorage->cursorShadowSprite = NULL;
    }
}

static void sub_80CFDC4(void)
{
    sCanOnlyMove = !sCanOnlyMove;
    sStorage->cursorSprite->oam.paletteNum = sStorage->cursorPalNums[sCanOnlyMove];
}

static u8 GetBoxCursorPosition(void)
{
    return sBoxCursorPosition;
}

static void sub_80CFE14(u8 *arg0, u8 *arg1)
{
    if (sBoxCursorArea == CURSOR_AREA_IN_BOX)
    {
        *arg0 = sBoxCursorPosition % IN_BOX_ROWS;
        *arg1 = sBoxCursorPosition / IN_BOX_ROWS;
    }
    else
    {
        *arg0 = 0;
        *arg1 = 0;
    }
}

static void sub_80CFE54(u8 animNum)
{
    StartSpriteAnim(sStorage->cursorSprite, animNum);
}

static u8 sub_80CFE78(void)
{
    return sMovingMonOrigBoxId;
}

static void sub_80CFE84(void)
{
    sStorage->cursorSprite->oam.priority = 1;
}

static void TryHideItemAtCursor(void)
{
    if (sBoxCursorArea == CURSOR_AREA_IN_BOX)
        sub_80D0E50(CURSOR_AREA_IN_BOX, sBoxCursorPosition);
}

static void sub_80CFECC(void)
{
    if (sBoxCursorArea == CURSOR_AREA_IN_BOX)
        sub_80D0D8C(CURSOR_AREA_IN_BOX, sBoxCursorPosition);
}

static void InitMenu(void)
{
    sStorage->menuItemsCount = 0;
    sStorage->menuWidth = 0;
    sStorage->menuWindow.bg = 0;
    sStorage->menuWindow.paletteNum = 15;
    sStorage->menuWindow.baseBlock = 92;
}

static const u8 *const gUnknown_0857BA80[] =
{
    gPCText_Cancel,
    gPCText_Store,
    gPCText_Withdraw,
    gPCText_Move,
    gPCText_Shift,
    gPCText_Place,
    gPCText_Summary,
    gPCText_Release,
    gPCText_Mark,
    gPCText_Jump,
    gPCText_Wallpaper,
    gPCText_Name,
    gPCText_Take,
    gPCText_Give,
    gPCText_Give,
    gPCText_Switch,
    gPCText_Bag,
    gPCText_Info,
    gPCText_Scenery1,
    gPCText_Scenery2,
    gPCText_Scenery3,
    gPCText_Etcetera,
    gPCText_Friends,
    gPCText_Forest,
    gPCText_City,
    gPCText_Desert,
    gPCText_Savanna,
    gPCText_Crag,
    gPCText_Volcano,
    gPCText_Snow,
    gPCText_Cave,
    gPCText_Beach,
    gPCText_Seafloor,
    gPCText_River,
    gPCText_Sky,
    gPCText_PolkaDot,
    gPCText_Pokecenter,
    gPCText_Machine,
    gPCText_Simple,
};

static void SetMenuText(u8 textId)
{
    if (sStorage->menuItemsCount < 7)
    {
        u8 len;
        struct StorageMenu *menu = &sStorage->menuItems[sStorage->menuItemsCount];

        menu->text = gUnknown_0857BA80[textId];
        menu->textId = textId;
        len = StringLength(menu->text);
        if (len > sStorage->menuWidth)
            sStorage->menuWidth = len;

        sStorage->menuItemsCount++;
    }
}

static s8 GetMenuItemTextId(u8 arg0)
{
    if (arg0 >= sStorage->menuItemsCount)
        return -1;
    else
        return sStorage->menuItems[arg0].textId;
}

static void AddMenu(void)
{
    sStorage->menuWindow.width = sStorage->menuWidth + 2;
    sStorage->menuWindow.height = 2 * sStorage->menuItemsCount;
    sStorage->menuWindow.tilemapLeft = 29 - sStorage->menuWindow.width;
    sStorage->menuWindow.tilemapTop = 15 - sStorage->menuWindow.height;
    sStorage->menuWindowId = AddWindow(&sStorage->menuWindow);
    ClearWindowTilemap(sStorage->menuWindowId);
    DrawStdFrameWithCustomTileAndPalette(sStorage->menuWindowId, FALSE, 11, 14);
    PrintMenuTable(sStorage->menuWindowId, sStorage->menuItemsCount, (void*)sStorage->menuItems);
    InitMenuInUpperLeftCornerPlaySoundWhenAPressed(sStorage->menuWindowId, sStorage->menuItemsCount, 0);
    ScheduleBgCopyTilemapToVram(0);
    sStorage->menuUnusedField = 0;
}

static bool8 sub_80D00A8(void)
{
    return FALSE;
}

static s16 sub_80D00AC(void)
{
    s32 textId = -2;

    do
    {
        if (JOY_NEW(A_BUTTON))
        {
            textId = Menu_GetCursorPos();
            break;
        }
        else if (JOY_NEW(B_BUTTON))
        {
            PlaySE(SE_SELECT);
            textId = -1;
        }

        if (JOY_NEW(DPAD_UP))
        {
            PlaySE(SE_SELECT);
            Menu_MoveCursor(-1);
        }
        else if (JOY_NEW(DPAD_DOWN))
        {
            PlaySE(SE_SELECT);
            Menu_MoveCursor(1);
        }
    } while (0);

    if (textId != -2)
        sub_80D013C();

    if (textId >= 0)
        textId = sStorage->menuItems[textId].textId;

    return textId;
}

static void sub_80D013C(void)
{
    ClearStdWindowAndFrameToTransparent(sStorage->menuWindowId, TRUE);
    RemoveWindow(sStorage->menuWindowId);
}

// The functions below handle moving and grabbing multiple mons at once.
// The icons are converted to background 0 which coordinates are changed while moving mons.
// There is also a bit of math involved in determining how many column/rows of mons to grab/move.

static const struct WindowTemplate gUnknown_0857BB1C =
{
    .bg = 0,
    .tilemapLeft = 10,
    .tilemapTop = 3,
    .width = 20,
    .height = 18,
    .paletteNum = 9,
    .baseBlock = 0xA,
};

EWRAM_DATA static struct
{
    u8 field_0;
    u8 state;
    u8 fromRow;
    u8 fromColumn;
    u8 toRow;
    u8 toColumn;
    u8 field_6;
    u8 field_7;
    u8 minRow;
    u8 minColumn;
    u8 rowsTotal;
    u8 columsTotal;
    u16 bgX;
    u16 bgY;
    u16 field_10;
    struct BoxPokemon boxMons[IN_BOX_COUNT];
}
*sMoveMonsPtr = NULL;

static bool8 MultiMove_Init(void)
{
    sMoveMonsPtr = Alloc(sizeof(*sMoveMonsPtr));
    if (sMoveMonsPtr != NULL)
    {
        sStorage->multiMoveWindowId = AddWindow8Bit(&gUnknown_0857BB1C);
        if (sStorage->multiMoveWindowId != 0xFF)
        {
            FillWindowPixelBuffer(sStorage->multiMoveWindowId, PIXEL_FILL(0));
            return TRUE;
        }
    }

    return FALSE;
}

static void sub_80D01B8(void)
{
    if (sMoveMonsPtr != NULL)
        Free(sMoveMonsPtr);
}

static void MultiMove_SetFunction(u8 arg0)
{
    sMoveMonsPtr->field_0 = arg0;
    sMoveMonsPtr->state = 0;
}

static bool8 sub_80D01E4(void)
{
    switch (sMoveMonsPtr->field_0)
    {
    case 0:
        return sub_80D024C();
    case 1:
        return sub_80D0344();
    case 2:
        return sub_80D03B0();
    case 3:
        return sub_80D0420();
    case 4:
        return sub_80D04A0();
    case 5:
        return sub_80D04C8();
    }

    return FALSE;
}

static bool8 sub_80D024C(void)
{
    switch (sMoveMonsPtr->state)
    {
    case 0:
        HideBg(0);
        sub_80D304C(0x80);
        sMoveMonsPtr->state++;
        break;
    case 1:
        sub_80CFE14(&sMoveMonsPtr->fromRow, &sMoveMonsPtr->fromColumn);
        sMoveMonsPtr->toRow = sMoveMonsPtr->fromRow;
        sMoveMonsPtr->toColumn = sMoveMonsPtr->fromColumn;
        ChangeBgX(0, -1024, 0);
        ChangeBgY(0, -1024, 0);
        FillBgTilemapBufferRect_Palette0(0, 0, 0, 0, 0x20, 0x20);
        FillWindowPixelBuffer8Bit(sStorage->multiMoveWindowId, PIXEL_FILL(0));
        sub_80D07B0(sMoveMonsPtr->fromRow, sMoveMonsPtr->fromColumn);
        SetBgAttribute(0, BG_ATTR_PALETTEMODE, 1);
        PutWindowTilemap(sStorage->multiMoveWindowId);
        CopyWindowToVram8Bit(sStorage->multiMoveWindowId, 3);
        BlendPalettes(0x3F00, 8, RGB_WHITE);
        sub_80CFE54(2);
        SetGpuRegBits(REG_OFFSET_BG0CNT, BGCNT_256COLOR);
        sMoveMonsPtr->state++;
        break;
    case 2:
        if (!IsDma3ManagerBusyWithBgCopy())
        {
            ShowBg(0);
            return FALSE;
        }
        break;
    }

    return TRUE;
}

static bool8 sub_80D0344(void)
{
    switch (sMoveMonsPtr->state)
    {
    case 0:
        HideBg(0);
        sMoveMonsPtr->state++;
        break;
    case 1:
        sub_80D0B5C();
        sub_80CFE54(0);
        sMoveMonsPtr->state++;
        break;
    case 2:
        if (!IsDma3ManagerBusyWithBgCopy())
        {
            sub_80CFE84();
            LoadPalette(GetTextWindowPalette(3), 0xD0, 0x20);
            ShowBg(0);
            return FALSE;
        }
        break;
    }

    return TRUE;
}

static bool8 sub_80D03B0(void)
{
    switch (sMoveMonsPtr->state)
    {
    case 0:
        if (!sub_80CD554())
        {
            sub_80CFE14(&sMoveMonsPtr->field_6, &sMoveMonsPtr->field_7);
            sub_80D062C();
            sMoveMonsPtr->toRow = sMoveMonsPtr->field_6;
            sMoveMonsPtr->toColumn = sMoveMonsPtr->field_7;
            CopyWindowToVram8Bit(sStorage->multiMoveWindowId, 2);
            sMoveMonsPtr->state++;
        }
        break;
    case 1:
        return IsDma3ManagerBusyWithBgCopy();
    }

    return TRUE;
}

static bool8 sub_80D0420(void)
{
    u8 var1, var2;

    switch (sMoveMonsPtr->state)
    {
    case 0:
        sub_80D08CC();
        sub_80D09A4();
        sub_80CDC64(FALSE);
        sMoveMonsPtr->state++;
        break;
    case 1:
        if (!DoMonPlaceChange())
        {
            sub_80CFE54(3);
            sub_80D0884(0, 256, 8);
            sub_80CDC64(TRUE);
            sMoveMonsPtr->state++;
        }
        break;
    case 2:
        var1 = sub_80D0894();
        var2 = DoMonPlaceChange();
        if (!var1 && !var2)
            return FALSE;
        break;
    }

    return TRUE;
}

static bool8 sub_80D04A0(void)
{
    u8 var1 = sub_80CD554();
    u8 var2 = sub_80D0894();

    if (!var1 && !var2)
        return FALSE;
    else
        return TRUE;
}

static bool8 sub_80D04C8(void)
{
    switch (sMoveMonsPtr->state)
    {
    case 0:
        sub_80D0AAC();
        sub_80D0884(0, -256, 8);
        sub_80CDC64(FALSE);
        sMoveMonsPtr->state++;
        break;
    case 1:
        if (!DoMonPlaceChange() && !sub_80D0894())
        {
            sub_80D0A1C();
            sub_80CFE54(2);
            sub_80CDC64(TRUE);
            HideBg(0);
            sMoveMonsPtr->state++;
        }
        break;
    case 2:
        if (!DoMonPlaceChange())
        {
            sub_80CFE54(0);
            sub_80D0B5C();
            sMoveMonsPtr->state++;
        }
        break;
    case 3:
        if (!IsDma3ManagerBusyWithBgCopy())
        {
            LoadPalette(GetTextWindowPalette(3), 0xD0, 0x20);
            sub_80CFE84();
            ShowBg(0);
            return FALSE;
        }
        break;
    }

    return TRUE;
}

static bool8 sub_80D0580(u8 arg0)
{
    switch (arg0)
    {
    case 0:
        if (sMoveMonsPtr->minColumn == 0)
            return FALSE;
        sMoveMonsPtr->minColumn--;
        sub_80D0884(0, 1024, 6);
        break;
    case 1:
        if (sMoveMonsPtr->minColumn + sMoveMonsPtr->columsTotal >= 5)
            return FALSE;
        sMoveMonsPtr->minColumn++;
        sub_80D0884(0, -1024, 6);
        break;
    case 2:
        if (sMoveMonsPtr->minRow == 0)
            return FALSE;
        sMoveMonsPtr->minRow--;
        sub_80D0884(1024, 0, 6);
        break;
    case 3:
        if (sMoveMonsPtr->minRow + sMoveMonsPtr->rowsTotal > 5)
            return FALSE;
        sMoveMonsPtr->minRow++;
        sub_80D0884(-1024, 0, 6);
        break;
    }

    return TRUE;
}

static void sub_80D062C(void)
{
    s16 var = (abs(sMoveMonsPtr->fromRow - sMoveMonsPtr->field_6)) - (abs(sMoveMonsPtr->fromRow - sMoveMonsPtr->toRow));
    s16 var2 = (abs(sMoveMonsPtr->fromColumn - sMoveMonsPtr->field_7)) - (abs(sMoveMonsPtr->fromColumn - sMoveMonsPtr->toColumn));

    if (var > 0)
        sub_80D06D0(sMoveMonsPtr->field_6, sMoveMonsPtr->fromColumn, sMoveMonsPtr->toColumn);

    if (var < 0)
    {
        sub_80D0740(sMoveMonsPtr->toRow, sMoveMonsPtr->fromColumn, sMoveMonsPtr->toColumn);
        sub_80D06D0(sMoveMonsPtr->field_6, sMoveMonsPtr->fromColumn, sMoveMonsPtr->toColumn);
    }

    if (var2 > 0)
        sub_80D0708(sMoveMonsPtr->field_7, sMoveMonsPtr->fromRow, sMoveMonsPtr->toRow);

    if (var2 < 0)
    {
        sub_80D0778(sMoveMonsPtr->toColumn, sMoveMonsPtr->fromRow, sMoveMonsPtr->toRow);
        sub_80D0708(sMoveMonsPtr->field_7, sMoveMonsPtr->fromRow, sMoveMonsPtr->toRow);
    }
}

static void sub_80D06D0(u8 arg0, u8 arg1, u8 arg2)
{
    u8 var1 = arg1;

    if (arg1 > arg2)
    {
        arg1 = arg2;
        arg2 = var1;
    }

    while (arg1 <= arg2)
        sub_80D07B0(arg0, arg1++);
}

static void sub_80D0708(u8 arg0, u8 arg1, u8 arg2)
{
    u8 var1 = arg1;

    if (arg1 > arg2)
    {
        arg1 = arg2;
        arg2 = var1;
    }

    while (arg1 <= arg2)
        sub_80D07B0(arg1++, arg0);
}

static void sub_80D0740(u8 arg0, u8 arg1, u8 arg2)
{
    u8 var1 = arg1;

    if (arg1 > arg2)
    {
        arg1 = arg2;
        arg2 = var1;
    }

    while (arg1 <= arg2)
        sub_80D0834(arg0, arg1++);
}

static void sub_80D0778(u8 arg0, u8 arg1, u8 arg2)
{
    u8 var1 = arg1;

    if (arg1 > arg2)
    {
        arg1 = arg2;
        arg2 = var1;
    }

    while (arg1 <= arg2)
        sub_80D0834(arg1++, arg0);
}

static void sub_80D07B0(u8 arg0, u8 arg1)
{
    u8 position = arg0 + (6 * arg1);
    u16 species = GetCurrentBoxMonData(position, MON_DATA_SPECIES2);
    u32 personality = GetCurrentBoxMonData(position, MON_DATA_PERSONALITY);
    u8 formId = GetCurrentBoxMonData(position, MON_DATA_FORM_ID);

    if (species != SPECIES_NONE)
    {
        const u8 *iconGfx = GetMonIconPtr(species, 0, formId);
        u8 index = GetValidMonIconPalIndex(species, formId) + 8;

        BlitBitmapRectToWindow4BitTo8Bit(sStorage->multiMoveWindowId,
                                         iconGfx,
                                         0,
                                         0,
                                         32,
                                         32,
                                         24 * arg0,
                                         24 * arg1,
                                         32,
                                         32,
                                         index);
    }
}

static void sub_80D0834(u8 arg0, u8 arg1)
{
    u8 position = arg0 + (6 * arg1);
    u16 species = GetCurrentBoxMonData(position, MON_DATA_SPECIES2);

    if (species != SPECIES_NONE)
    {
        FillWindowPixelRect8Bit(sStorage->multiMoveWindowId,
                                PIXEL_FILL(0),
                                24 * arg0,
                                24 * arg1,
                                32,
                                32);
    }
}

static void sub_80D0884(u16 arg0, u16 arg1, u16 arg2)
{
    sMoveMonsPtr->bgX = arg0;
    sMoveMonsPtr->bgY = arg1;
    sMoveMonsPtr->field_10 = arg2;
}

static u8 sub_80D0894(void)
{
    if (sMoveMonsPtr->field_10 != 0)
    {
        ChangeBgX(0, sMoveMonsPtr->bgX, 1);
        ChangeBgY(0, sMoveMonsPtr->bgY, 1);
        sMoveMonsPtr->field_10--;
    }

    return sMoveMonsPtr->field_10;
}

static void sub_80D08CC(void)
{
    s32 i, j, r8, r9;
    s32 rowCount, columnCount;
    u8 boxId;
    u8 monArrayId;

    sMoveMonsPtr->minRow = min(sMoveMonsPtr->fromRow, sMoveMonsPtr->toRow);
    sMoveMonsPtr->minColumn = min(sMoveMonsPtr->fromColumn, sMoveMonsPtr->toColumn);
    sMoveMonsPtr->rowsTotal = abs(sMoveMonsPtr->fromRow - sMoveMonsPtr->toRow) + 1;
    sMoveMonsPtr->columsTotal = abs(sMoveMonsPtr->fromColumn - sMoveMonsPtr->toColumn) + 1;
    boxId = StorageGetCurrentBox();
    monArrayId = 0;
    rowCount = sMoveMonsPtr->minRow + sMoveMonsPtr->rowsTotal;
    columnCount = sMoveMonsPtr->minColumn + sMoveMonsPtr->columsTotal;
    for (i = sMoveMonsPtr->minColumn; i < columnCount; i++)
    {
        u8 boxPosition = (IN_BOX_ROWS * i) + sMoveMonsPtr->minRow;
        for (j = sMoveMonsPtr->minRow; j < rowCount; j++)
        {
            struct BoxPokemon *boxMon = GetBoxedMonPtr(boxId, boxPosition);

            sMoveMonsPtr->boxMons[monArrayId] = *boxMon;
            monArrayId++;
            boxPosition++;
        }
    }
}

static void sub_80D09A4(void)
{
    s32 i, j;
    s32 rowCount = sMoveMonsPtr->minRow + sMoveMonsPtr->rowsTotal;
    s32 columnCount = sMoveMonsPtr->minColumn + sMoveMonsPtr->columsTotal;
    u8 boxId = StorageGetCurrentBox();

    for (i = sMoveMonsPtr->minColumn; i < columnCount; i++)
    {
        u8 boxPosition = (IN_BOX_ROWS * i) + sMoveMonsPtr->minRow;
        for (j = sMoveMonsPtr->minRow; j < rowCount; j++)
        {
            DestroyBoxMonIconAtPosition(boxPosition);
            ZeroBoxMonAt(boxId, boxPosition);
            boxPosition++;
        }
    }
}

static void sub_80D0A1C(void)
{
    s32 i, j;
    s32 rowCount = sMoveMonsPtr->minRow + sMoveMonsPtr->rowsTotal;
    s32 columnCount = sMoveMonsPtr->minColumn + sMoveMonsPtr->columsTotal;
    u8 monArrayId = 0;

    for (i = sMoveMonsPtr->minColumn; i < columnCount; i++)
    {
        u8 boxPosition = (IN_BOX_ROWS * i) + sMoveMonsPtr->minRow;
        for (j = sMoveMonsPtr->minRow; j < rowCount; j++)
        {
            if (GetBoxMonData(&sMoveMonsPtr->boxMons[monArrayId], MON_DATA_SANITY_HAS_SPECIES))
                createBoxMonIconAtPos(boxPosition);
            monArrayId++;
            boxPosition++;
        }
    }
}

static void sub_80D0AAC(void)
{
    s32 i, j;
    s32 rowCount = sMoveMonsPtr->minRow + sMoveMonsPtr->rowsTotal;
    s32 columnCount = sMoveMonsPtr->minColumn + sMoveMonsPtr->columsTotal;
    u8 boxId = StorageGetCurrentBox();
    u8 monArrayId = 0;

    for (i = sMoveMonsPtr->minColumn; i < columnCount; i++)
    {
        u8 boxPosition = (IN_BOX_ROWS * i) + sMoveMonsPtr->minRow;
        for (j = sMoveMonsPtr->minRow; j < rowCount; j++)
        {
            if (GetBoxMonData(&sMoveMonsPtr->boxMons[monArrayId], MON_DATA_SANITY_HAS_SPECIES))
                SetBoxMonAt(boxId, boxPosition, &sMoveMonsPtr->boxMons[monArrayId]);
            boxPosition++;
            monArrayId++;
        }
    }
}

static void sub_80D0B5C(void)
{
    ChangeBgX(0, 0, 0);
    ChangeBgY(0, 0, 0);
    SetBgAttribute(0, BG_ATTR_PALETTEMODE, 0);
    ClearGpuRegBits(REG_OFFSET_BG0CNT, BGCNT_256COLOR);
    FillBgTilemapBufferRect_Palette0(0, 0, 0, 0, 32, 32);
    CopyBgTilemapBufferToVram(0);
}

static u8 sub_80D0BA4(void)
{
    return (IN_BOX_ROWS * sMoveMonsPtr->fromColumn) + sMoveMonsPtr->fromRow;
}

static bool8 sub_80D0BC0(void)
{
    s32 i, j;
    s32 rowCount = sMoveMonsPtr->minRow + sMoveMonsPtr->rowsTotal;
    s32 columnCount = sMoveMonsPtr->minColumn + sMoveMonsPtr->columsTotal;
    u8 monArrayId = 0;

    for (i = sMoveMonsPtr->minColumn; i < columnCount; i++)
    {
        u8 boxPosition = (IN_BOX_ROWS * i) + sMoveMonsPtr->minRow;
        for (j = sMoveMonsPtr->minRow; j < rowCount; j++)
        {
            if (GetBoxMonData(&sMoveMonsPtr->boxMons[monArrayId], MON_DATA_SANITY_HAS_SPECIES)
                && GetCurrentBoxMonData(boxPosition, MON_DATA_SANITY_HAS_SPECIES))
                return FALSE;

            monArrayId++;
            boxPosition++;
        }
    }

    return TRUE;
}

static const u32 gUnknown_0857BB24[] = INCBIN_U32("graphics/pokemon_storage/unknown_frame.4bpp");

static const struct OamData sOamData_857BBA4 =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_NORMAL,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = 0,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(32x32),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(32x32),
    .tileNum = 0,
    .priority = 1,
    .paletteNum = 0,
    .affineParam = 0
};

static const union AffineAnimCmd sSpriteAffineAnim_857BBAC[] =
{
    AFFINEANIMCMD_FRAME(128, 128, 0, 0),
    AFFINEANIMCMD_END
};

static const union AffineAnimCmd sSpriteAffineAnim_857BBBC[] =
{
    AFFINEANIMCMD_FRAME(88, 88, 0, 0),
    AFFINEANIMCMD_FRAME(5, 5, 0, 8),
    AFFINEANIMCMD_END
};

static const union AffineAnimCmd sSpriteAffineAnim_857BBD4[] =
{
    AFFINEANIMCMD_FRAME(128, 128, 0, 0),
    AFFINEANIMCMD_FRAME(-5, -5, 0, 8),
    AFFINEANIMCMD_END
};

static const union AffineAnimCmd sSpriteAffineAnim_857BBEC[] =
{
    AFFINEANIMCMD_FRAME(128, 128, 0, 0),
    AFFINEANIMCMD_FRAME(10, 10, 0, 12),
    AFFINEANIMCMD_FRAME(256, 256, 0, 0),
    AFFINEANIMCMD_END
};

static const union AffineAnimCmd sSpriteAffineAnim_857BC0C[] =
{
    AFFINEANIMCMD_FRAME(256, 256, 0, 0),
    AFFINEANIMCMD_FRAME(-10, -10, 0, 12),
    AFFINEANIMCMD_FRAME(128, 128, 0, 0),
    AFFINEANIMCMD_END
};

static const union AffineAnimCmd sSpriteAffineAnim_857BC2C[] =
{
    AFFINEANIMCMD_FRAME(256, 256, 0, 0),
    AFFINEANIMCMD_FRAME(-5, -5, 0, 16),
    AFFINEANIMCMD_END
};

static const union AffineAnimCmd sSpriteAffineAnim_857BC44[] =
{
    AFFINEANIMCMD_FRAME(256, 256, 0, 0),
    AFFINEANIMCMD_END
};

static const union AffineAnimCmd *const sSpriteAffineAnimTable_857BC44[] =
{
    sSpriteAffineAnim_857BBAC,
    sSpriteAffineAnim_857BBBC,
    sSpriteAffineAnim_857BBD4,
    sSpriteAffineAnim_857BBEC,
    sSpriteAffineAnim_857BC0C,
    sSpriteAffineAnim_857BC2C,
    sSpriteAffineAnim_857BC44
};

static const struct SpriteTemplate gSpriteTemplate_857BC70 =
{
    .tileTag = TAG_TILE_7,
    .paletteTag = TAG_PAL_DACB,
    .oam = &sOamData_857BBA4,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = sSpriteAffineAnimTable_857BC44,
    .callback = SpriteCallbackDummy,
};

static void CreateItemIconSprites(void)
{
    s32 i;
    u8 spriteId;
    struct CompressedSpriteSheet spriteSheet;
    struct SpriteTemplate spriteTemplate;

    if (sStorage->boxOption == OPTION_MOVE_ITEMS)
    {
        spriteSheet.data = gUnknown_03000F78;
        spriteSheet.size = 0x200;
        spriteTemplate = gSpriteTemplate_857BC70;

        for (i = 0; i < 3; i++)
        {
            spriteSheet.tag = TAG_TILE_7 + i;
            LoadCompressedSpriteSheet(&spriteSheet);
            sStorage->itemIcons[i].tiles = GetSpriteTileStartByTag(spriteSheet.tag) * 32 + (void*)(OBJ_VRAM0);
            sStorage->itemIcons[i].palIndex = AllocSpritePalette(TAG_PAL_DACB + i);
            sStorage->itemIcons[i].palIndex *= 16;
            sStorage->itemIcons[i].palIndex += 0x100;
            spriteTemplate.tileTag = TAG_TILE_7 + i;
            spriteTemplate.paletteTag = TAG_PAL_DACB + i;
            spriteId = CreateSprite(&spriteTemplate, 0, 0, 11);
            sStorage->itemIcons[i].sprite = &gSprites[spriteId];
            sStorage->itemIcons[i].sprite->invisible = TRUE;
            sStorage->itemIcons[i].active = 0;
        }
    }
    sStorage->movingItem = 0;
}

// The functions below handle new features of MOVE_ITEMS box option.
static bool32 sub_80D1324(u8 cursorArea, u8 cursorPos);
static const u32 *GetItemIconPic(u16 itemId);
static const u32 *GetItemIconPalette(u16 itemId);
static u8 sub_80D12E8(void);
static void sub_80D140C(u8 id, u8 cursorArea, u8 cursorPos);
static void sub_80D1524(u8 id, const u32 *itemTiles, const u32 *itemPal);
static void sub_80D15D4(u8 id, u8 animNum);
static void sub_80D1740(u8 id, bool8 arg1);
static u8 sub_80D1370(u8 cursorArea, u8 cursorPos);
static void sub_80D1604(u8 id, u8 arg1, u8 arg2, u8 arg3);
static void sub_80D1AD8(struct Sprite *sprite);
static void sub_80D1A48(struct Sprite *sprite);
static void sub_80D1A74(struct Sprite *sprite);
static void sub_80D1B14(struct Sprite *sprite);
static void sub_80D1B94(struct Sprite *sprite);
static void sub_80D1CCC(struct Sprite *sprite);
static void sub_80D1C30(struct Sprite *sprite);

static void sub_80D0D8C(u8 cursorArea, u8 cursorPos)
{
    u16 heldItem;

    if (sStorage->boxOption != OPTION_MOVE_ITEMS)
        return;
    if (sub_80D1324(cursorArea, cursorPos))
        return;

    switch (cursorArea)
    {
    case CURSOR_AREA_IN_BOX:
        if (!GetCurrentBoxMonData(cursorPos, MON_DATA_SANITY_HAS_SPECIES))
            return;
        heldItem = GetCurrentBoxMonData(cursorPos, MON_DATA_HELD_ITEM);
        break;
    case CURSOR_AREA_IN_PARTY:
        if (cursorPos >= PARTY_SIZE || !GetMonData(&gPlayerParty[cursorPos], MON_DATA_SANITY_HAS_SPECIES))
            return;
        heldItem = GetMonData(&gPlayerParty[cursorPos], MON_DATA_HELD_ITEM);
        break;
    default:
        return;
    }

    if (heldItem != 0)
    {
        const u32 *tiles = GetItemIconPic(heldItem);
        const u32 *pal = GetItemIconPalette(heldItem);
        u8 id = sub_80D12E8();

        sub_80D140C(id, cursorArea, cursorPos);
        sub_80D1524(id, tiles, pal);
        sub_80D15D4(id, 1);
        sub_80D1740(id, TRUE);
    }
}

static void sub_80D0E50(u8 cursorArea, u8 cursorPos)
{
    u8 id;

    if (sStorage->boxOption != OPTION_MOVE_ITEMS)
        return;

    id = sub_80D1370(cursorArea, cursorPos);
    sub_80D15D4(id, 2);
    sub_80D1604(id, 0, cursorArea, cursorPos);
}

static void Item_FromMonToMoving(u8 cursorArea, u8 cursorPos)
{
    u8 id;
    u16 item;

    if (sStorage->boxOption != OPTION_MOVE_ITEMS)
        return;

    id = sub_80D1370(cursorArea, cursorPos);
    item = 0;
    sub_80D15D4(id, 3);
    sub_80D1604(id, 1, cursorArea, cursorPos);
    sub_80D140C(id, 2, 0);
    if (cursorArea  == CURSOR_AREA_IN_BOX)
    {
        SetCurrentBoxMonData(cursorPos, MON_DATA_HELD_ITEM, &item);
        SetBoxMonIconObjMode(cursorPos, 1);
    }
    else
    {
        SetMonData(&gPlayerParty[cursorPos], MON_DATA_HELD_ITEM, &item);
        SetPartyMonIconObjMode(cursorPos, 1);
    }

    sStorage->movingItem = sStorage->cursorMonItem;
}

static void sub_80D0F38(u16 item)
{
    const u32 *tiles = GetItemIconPic(item);
    const u32 *pal = GetItemIconPalette(item);
    u8 id = sub_80D12E8();

    sub_80D1524(id, tiles, pal);
    sub_80D15D4(id, 6);
    sub_80D1604(id, 1, 0, 0);
    sub_80D140C(id, 2, 0);
    sub_80D1740(id, TRUE);
    sStorage->movingItem = item;
}

static void Item_SwitchMonsWithMoving(u8 cursorArea, u8 cursorPos)
{
    u8 id;
    u16 item;

    if (sStorage->boxOption != OPTION_MOVE_ITEMS)
        return;

    id = sub_80D1370(cursorArea, cursorPos);
    sub_80D15D4(id, 3);
    sub_80D1604(id, 3, 2, 0);
    if (cursorArea == CURSOR_AREA_IN_BOX)
    {
        item = GetCurrentBoxMonData(cursorPos, MON_DATA_HELD_ITEM);
        SetCurrentBoxMonData(cursorPos, MON_DATA_HELD_ITEM, &sStorage->movingItem);
        sStorage->movingItem = item;
    }
    else
    {
        item = GetMonData(&gPlayerParty[cursorPos], MON_DATA_HELD_ITEM);
        SetMonData(&gPlayerParty[cursorPos], MON_DATA_HELD_ITEM, &sStorage->movingItem);
        sStorage->movingItem = item;
    }

    id = sub_80D1370(2, 0);
    sub_80D15D4(id, 4);
    sub_80D1604(id, 4, cursorArea, cursorPos);
}

static void Item_GiveMovingToMon(u8 cursorArea, u8 cursorPos)
{
    u8 id;

    if (sStorage->boxOption != OPTION_MOVE_ITEMS)
        return;

    id = sub_80D1370(2, 0);
    sub_80D15D4(id, 4);
    sub_80D1604(id, 2, cursorArea, cursorPos);
    if (cursorArea == CURSOR_AREA_IN_BOX)
    {
        SetCurrentBoxMonData(cursorPos, MON_DATA_HELD_ITEM, &sStorage->movingItem);
        SetBoxMonIconObjMode(cursorPos, 0);
    }
    else
    {
        SetMonData(&gPlayerParty[cursorPos], MON_DATA_HELD_ITEM, &sStorage->movingItem);
        SetPartyMonIconObjMode(cursorPos, 0);
    }
}

static void Item_TakeMons(u8 cursorArea, u8 cursorPos)
{
    u8 id;
    u16 item;

    if (sStorage->boxOption != OPTION_MOVE_ITEMS)
        return;

    item = 0;
    id = sub_80D1370(cursorArea, cursorPos);
    sub_80D15D4(id, 2);
    sub_80D1604(id, 0, cursorArea, cursorPos);
    if (cursorArea  == CURSOR_AREA_IN_BOX)
    {
        SetCurrentBoxMonData(cursorPos, MON_DATA_HELD_ITEM, &item);
        SetBoxMonIconObjMode(cursorPos, 1);
    }
    else
    {
        SetMonData(&gPlayerParty[cursorPos], MON_DATA_HELD_ITEM, &item);
        SetPartyMonIconObjMode(cursorPos, 1);
    }
}

static void sub_80D1194(void)
{
    if (sStorage->boxOption == OPTION_MOVE_ITEMS)
    {
        u8 id = sub_80D1370(2, 0);
        sub_80D15D4(id, 5);
        sub_80D1604(id, 0, 2, 0);
    }
}

static void sub_80D11CC(void)
{
    s32 i;

    if (sStorage->boxOption != OPTION_MOVE_ITEMS)
        return;

    for (i = 0; i < 3; i++)
    {
        if (sStorage->itemIcons[i].active && sStorage->itemIcons[i].area == 1)
            sub_80D1604(i, 7, 2, 0);
    }
}

static bool8 sub_80D1218(void)
{
    s32 i;

    for (i = 0; i < 3; i++)
    {
        if (sStorage->itemIcons[i].active)
        {
            if (!sStorage->itemIcons[i].sprite->affineAnimEnded && sStorage->itemIcons[i].sprite->affineAnimBeginning)
                return TRUE;
            if (sStorage->itemIcons[i].sprite->callback != SpriteCallbackDummy && sStorage->itemIcons[i].sprite->callback != sub_80D1AD8)
                return TRUE;
        }
    }

    return FALSE;
}

static bool8 IsActiveItemMoving(void)
{
    s32 i;

    if (sStorage->boxOption == OPTION_MOVE_ITEMS)
    {
        for (i = 0; i < 3; i++)
        {
            if (sStorage->itemIcons[i].active && sStorage->itemIcons[i].area == 2)
                return TRUE;
        }
    }

    return FALSE;
}

static const u8 *GetMovingItemName(void)
{
    return ItemId_GetName(sStorage->movingItem);
}

static u16 GetMovingItem(void)
{
    return sStorage->movingItem;
}

static u8 sub_80D12E8(void)
{
    u8 i;

    for (i = 0; i < 3; i++)
    {
        if (sStorage->itemIcons[i].active == 0)
        {
            sStorage->itemIcons[i].active = 1;
            return i;
        }
    }

    return 3;
}

static bool32 sub_80D1324(u8 cursorArea, u8 cursorPos)
{
    s32 i;

    for (i = 0; i < 3; i++)
    {
        if (sStorage->itemIcons[i].active
            && sStorage->itemIcons[i].area == cursorArea
            && sStorage->itemIcons[i].pos == cursorPos)
            return TRUE;
    }

    return FALSE;
}

static u8 sub_80D1370(u8 cursorArea, u8 cursorPos)
{
    u8 i;

    for (i = 0; i < 3; i++)
    {
        if (sStorage->itemIcons[i].active
            && sStorage->itemIcons[i].area == cursorArea
            && sStorage->itemIcons[i].pos == cursorPos)
            return i;
    }

    return 3;
}

static u8 sub_80D13C4(struct Sprite *sprite)
{
    u8 i;

    for (i = 0; i < 3; i++)
    {
        if (sStorage->itemIcons[i].active
            && sStorage->itemIcons[i].sprite == sprite)
            return i;
    }

    return 3;
}

static void sub_80D140C(u8 id, u8 cursorArea, u8 cursorPos)
{
    u8 row, column;

    if (id >= 3)
        return;

    switch (cursorArea)
    {
    case CURSOR_AREA_IN_BOX:
        row = cursorPos % IN_BOX_ROWS;
        column = cursorPos / IN_BOX_ROWS;
        sStorage->itemIcons[id].sprite->pos1.x = (24 * row) + 112;
        sStorage->itemIcons[id].sprite->pos1.y = (24 * column) + 56;
        sStorage->itemIcons[id].sprite->oam.priority = 2;
        break;
    case CURSOR_AREA_IN_PARTY:
        if (cursorPos == 0)
        {
            sStorage->itemIcons[id].sprite->pos1.x = 116;
            sStorage->itemIcons[id].sprite->pos1.y = 76;
        }
        else
        {
            sStorage->itemIcons[id].sprite->pos1.x = 164;
            sStorage->itemIcons[id].sprite->pos1.y = 24 * (cursorPos - 1) + 28;
        }
        sStorage->itemIcons[id].sprite->oam.priority = 1;
        break;
    }

    sStorage->itemIcons[id].area = cursorArea;
    sStorage->itemIcons[id].pos = cursorPos;
}

static void sub_80D1524(u8 id, const u32 *itemTiles, const u32 *itemPal)
{
    s32 i;

    if (id >= 3)
        return;

    CpuFastFill(0, sStorage->itemIconBuffer, 0x200);
    LZ77UnCompWram(itemTiles, sStorage->tileBuffer);
    for (i = 0; i < 3; i++)
        CpuFastCopy(sStorage->tileBuffer + (i * 0x60), sStorage->itemIconBuffer + (i * 0x80), 0x60);

    CpuFastCopy(sStorage->itemIconBuffer, sStorage->itemIcons[id].tiles, 0x200);
    LZ77UnCompWram(itemPal, sStorage->itemIconBuffer);
    LoadPalette(sStorage->itemIconBuffer, sStorage->itemIcons[id].palIndex, 0x20);
}

static void sub_80D15D4(u8 id, u8 animNum)
{
    if (id >= 3)
        return;

    StartSpriteAffineAnim(sStorage->itemIcons[id].sprite, animNum);
}

static void sub_80D1604(u8 id, u8 arg1, u8 arg2, u8 arg3)
{
    if (id >= 3)
        return;

    switch (arg1)
    {
    case 0:
        sStorage->itemIcons[id].sprite->data[0] = id;
        sStorage->itemIcons[id].sprite->callback = sub_80D1A48;
        break;
    case 1:
        sStorage->itemIcons[id].sprite->data[0] = 0;
        sStorage->itemIcons[id].sprite->callback = sub_80D1A74;
        break;
    case 2:
        sStorage->itemIcons[id].sprite->data[0] = 0;
        sStorage->itemIcons[id].sprite->data[6] = arg2;
        sStorage->itemIcons[id].sprite->data[7] = arg3;
        sStorage->itemIcons[id].sprite->callback = sub_80D1B14;
        break;
    case 3:
        sStorage->itemIcons[id].sprite->data[0] = 0;
        sStorage->itemIcons[id].sprite->callback = sub_80D1B94;
        sStorage->itemIcons[id].sprite->data[6] = arg2;
        sStorage->itemIcons[id].sprite->data[7] = arg3;
        break;
    case 4:
        sStorage->itemIcons[id].sprite->data[0] = 0;
        sStorage->itemIcons[id].sprite->data[6] = arg2;
        sStorage->itemIcons[id].sprite->data[7] = arg3;
        sStorage->itemIcons[id].sprite->callback = sub_80D1C30;
        break;
    case 7:
        sStorage->itemIcons[id].sprite->callback = sub_80D1CCC;
        break;
    }
}

static void sub_80D1740(u8 id, bool8 arg1)
{
    if (id >= 3)
        return;

    sStorage->itemIcons[id].active = arg1;
    sStorage->itemIcons[id].sprite->invisible = (arg1 == FALSE);
}

static const u32 *GetItemIconPic(u16 itemId)
{
    return GetItemIconPicOrPalette(itemId, 0);
}

static const u32 *GetItemIconPalette(u16 itemId)
{
    return GetItemIconPicOrPalette(itemId, 1);
}

static void PrintItemDescription(void)
{
    const u8 *description;

    if (IsActiveItemMoving())
        description = ItemId_GetDescription(sStorage->movingItem);
    else
        description = ItemId_GetDescription(sStorage->cursorMonItem);

    FillWindowPixelBuffer(2, PIXEL_FILL(1));
    AddTextPrinterParameterized5(2, 1, description, 4, 0, 0, NULL, 0, 1);
}

static void sub_80D1818(void)
{
    sStorage->itemInfoWindowOffset = 0x15;
    LoadBgTiles(0, gUnknown_0857BB24, 0x80, 0x13A);
    sub_80D19B4(0);
}

static bool8 sub_80D184C(void)
{
    s32 i, var;

    if (sStorage->itemInfoWindowOffset == 0)
        return FALSE;

    sStorage->itemInfoWindowOffset--;
    var = 0x15 - sStorage->itemInfoWindowOffset;
    for (i = 0; i < var; i++)
    {
        WriteSequenceToBgTilemapBuffer(0, GetBgAttribute(0, BG_ATTR_BASETILE) + 0x14 + sStorage->itemInfoWindowOffset + i, i, 13, 1, 7, 15, 21);
    }

    sub_80D19B4(var);
    return (sStorage->itemInfoWindowOffset != 0);
}

static bool8 sub_80D18E4(void)
{
    s32 i, var;

    if (sStorage->itemInfoWindowOffset == 0x16)
        return FALSE;

    if (sStorage->itemInfoWindowOffset == 0)
        FillBgTilemapBufferRect(0, 0, 21, 12, 1, 9, 17);

    sStorage->itemInfoWindowOffset++;
    var = 0x15 - sStorage->itemInfoWindowOffset;
    for (i = 0; i < var; i++)
    {
        WriteSequenceToBgTilemapBuffer(0, GetBgAttribute(0, BG_ATTR_BASETILE) + 0x14 + sStorage->itemInfoWindowOffset + i, i, 13, 1, 7, 15, 21);
    }

    if (var >= 0)
        sub_80D19B4(var);

    FillBgTilemapBufferRect(0, 0, var + 1, 12, 1, 9, 0x11);
    ScheduleBgCopyTilemapToVram(0);
    return TRUE;
}

static void sub_80D19B4(u32 arg0)
{
    if (arg0 != 0)
    {
        FillBgTilemapBufferRect(0, 0x13A, 0, 0xC, arg0, 1, 0xFu);
        FillBgTilemapBufferRect(0, 0x93A, 0, 0x14, arg0, 1, 0xFu);
    }
    FillBgTilemapBufferRect(0, 0x13B, arg0, 0xD, 1, 7, 0xFu);
    FillBgTilemapBufferRect(0, 0x13C, arg0, 0xC, 1, 1, 0xFu);
    FillBgTilemapBufferRect(0, 0x13D, arg0, 0x14, 1, 1, 0xFu);
    ScheduleBgCopyTilemapToVram(0);
}

static void sub_80D1A48(struct Sprite *sprite)
{
    if (sprite->affineAnimEnded)
    {
        sub_80D1740(sprite->data[0], FALSE);
        sprite->callback = SpriteCallbackDummy;
    }
}

static void sub_80D1A74(struct Sprite *sprite)
{
    switch (sprite->data[0])
    {
    case 0:
        sprite->data[1] = sprite->pos1.x << 4;
        sprite->data[2] = sprite->pos1.y << 4;
        sprite->data[3] = 10;
        sprite->data[4] = 21;
        sprite->data[5] = 0;
        sprite->data[0]++;
    case 1:
        sprite->data[1] -= sprite->data[3];
        sprite->data[2] -= sprite->data[4];
        sprite->pos1.x = sprite->data[1] >> 4;
        sprite->pos1.y = sprite->data[2] >> 4;
        if (++sprite->data[5] > 11)
            sprite->callback = sub_80D1AD8;
        break;
    }
}

static void sub_80D1AD8(struct Sprite *sprite)
{
    sprite->pos1.x = sStorage->cursorSprite->pos1.x + 4;
    sprite->pos1.y = sStorage->cursorSprite->pos1.y + sStorage->cursorSprite->pos2.y + 8;
    sprite->oam.priority = sStorage->cursorSprite->oam.priority;
}

static void sub_80D1B14(struct Sprite *sprite)
{
    switch (sprite->data[0])
    {
    case 0:
        sprite->data[1] = sprite->pos1.x << 4;
        sprite->data[2] = sprite->pos1.y << 4;
        sprite->data[3] = 10;
        sprite->data[4] = 21;
        sprite->data[5] = 0;
        sprite->data[0]++;
    case 1:
        sprite->data[1] += sprite->data[3];
        sprite->data[2] += sprite->data[4];
        sprite->pos1.x = sprite->data[1] >> 4;
        sprite->pos1.y = sprite->data[2] >> 4;
        if (++sprite->data[5] > 11)
        {
            sub_80D140C(sub_80D13C4(sprite), sprite->data[6], sprite->data[7]);
            sprite->callback = SpriteCallbackDummy;
        }
        break;
    }
}

static void sub_80D1B94(struct Sprite *sprite)
{
    switch (sprite->data[0])
    {
    case 0:
        sprite->data[1] = sprite->pos1.x << 4;
        sprite->data[2] = sprite->pos1.y << 4;
        sprite->data[3] = 10;
        sprite->data[4] = 21;
        sprite->data[5] = 0;
        sprite->data[0]++;
    case 1:
        sprite->data[1] -= sprite->data[3];
        sprite->data[2] -= sprite->data[4];
        sprite->pos1.x = sprite->data[1] >> 4;
        sprite->pos1.y = sprite->data[2] >> 4;
        sprite->pos2.x = gSineTable[sprite->data[5] * 8] >> 4;
        if (++sprite->data[5] > 11)
        {
            sub_80D140C(sub_80D13C4(sprite), sprite->data[6], sprite->data[7]);
            sprite->pos2.x = 0;
            sprite->callback = sub_80D1AD8;
        }
        break;
    }
}

static void sub_80D1C30(struct Sprite *sprite)
{
    switch (sprite->data[0])
    {
    case 0:
        sprite->data[1] = sprite->pos1.x << 4;
        sprite->data[2] = sprite->pos1.y << 4;
        sprite->data[3] = 10;
        sprite->data[4] = 21;
        sprite->data[5] = 0;
        sprite->data[0]++;
    case 1:
        sprite->data[1] += sprite->data[3];
        sprite->data[2] += sprite->data[4];
        sprite->pos1.x = sprite->data[1] >> 4;
        sprite->pos1.y = sprite->data[2] >> 4;
        sprite->pos2.x = -(gSineTable[sprite->data[5] * 8] >> 4);
        if (++sprite->data[5] > 11)
        {
            sub_80D140C(sub_80D13C4(sprite), sprite->data[6], sprite->data[7]);
            sprite->callback = SpriteCallbackDummy;
            sprite->pos2.x = 0;
        }
        break;
    }
}

static void sub_80D1CCC(struct Sprite *sprite)
{
    sprite->pos1.y -= 8;
    if (sprite->pos1.y + sprite->pos2.y < -16)
    {
        sprite->callback = SpriteCallbackDummy;
        sub_80D1740(sub_80D13C4(sprite), FALSE);
    }
}

void nullsub_pss(void)
{

}

void nullsub_98(void)
{

}

// Functions here are general utility functions.
u8 StorageGetCurrentBox(void)
{
    return gPokemonStoragePtr->currentBox;
}

static void SetCurrentBox(u8 boxId)
{
    if (boxId < TOTAL_BOXES_COUNT)
        gPokemonStoragePtr->currentBox = boxId;
}

u32 GetBoxMonDataAt(u8 boxId, u8 boxPosition, s32 request)
{
    if (boxId < TOTAL_BOXES_COUNT && boxPosition < IN_BOX_COUNT)
        return GetBoxMonData(&gPokemonStoragePtr->boxes[boxId][boxPosition], request);
    else
        return 0;
}

void SetBoxMonDataAt(u8 boxId, u8 boxPosition, s32 request, const void *value)
{
    if (boxId < TOTAL_BOXES_COUNT && boxPosition < IN_BOX_COUNT)
        SetBoxMonData(&gPokemonStoragePtr->boxes[boxId][boxPosition], request, value);
}

u32 GetCurrentBoxMonData(u8 boxPosition, s32 request)
{
    return GetBoxMonDataAt(gPokemonStoragePtr->currentBox, boxPosition, request);
}

void SetCurrentBoxMonData(u8 boxPosition, s32 request, const void *value)
{
    SetBoxMonDataAt(gPokemonStoragePtr->currentBox, boxPosition, request, value);
}

void GetBoxMonNickAt(u8 boxId, u8 boxPosition, u8 *dst)
{
    if (boxId < TOTAL_BOXES_COUNT && boxPosition < IN_BOX_COUNT)
        GetBoxMonData(&gPokemonStoragePtr->boxes[boxId][boxPosition], MON_DATA_NICKNAME, dst);
    else
        *dst = EOS;
}

u32 GetBoxMonLevelAt(u8 boxId, u8 boxPosition)
{
    u32 lvl;

    // BUG: Missed 'else' statement.
    if (boxId < TOTAL_BOXES_COUNT && boxPosition < IN_BOX_COUNT && GetBoxMonData(&gPokemonStoragePtr->boxes[boxId][boxPosition], MON_DATA_SANITY_HAS_SPECIES))
        lvl = GetLevelFromBoxMonExp(&gPokemonStoragePtr->boxes[boxId][boxPosition]);
    else
        lvl = 0;

    return lvl;
}

void SetBoxMonNickAt(u8 boxId, u8 boxPosition, const u8 *nick)
{
    if (boxId < TOTAL_BOXES_COUNT && boxPosition < IN_BOX_COUNT)
        SetBoxMonData(&gPokemonStoragePtr->boxes[boxId][boxPosition], MON_DATA_NICKNAME, nick);
}

u32 GetAndCopyBoxMonDataAt(u8 boxId, u8 boxPosition, s32 request, void *dst)
{
    if (boxId < TOTAL_BOXES_COUNT && boxPosition < IN_BOX_COUNT)
        return GetBoxMonData(&gPokemonStoragePtr->boxes[boxId][boxPosition], request, dst);
    else
        return 0;
}

void SetBoxMonAt(u8 boxId, u8 boxPosition, struct BoxPokemon *src)
{
    if (boxId < TOTAL_BOXES_COUNT && boxPosition < IN_BOX_COUNT)
        gPokemonStoragePtr->boxes[boxId][boxPosition] = *src;
}

void CopyBoxMonAt(u8 boxId, u8 boxPosition, struct BoxPokemon *dst)
{
    if (boxId < TOTAL_BOXES_COUNT && boxPosition < IN_BOX_COUNT)
        *dst = gPokemonStoragePtr->boxes[boxId][boxPosition];
}

void CreateBoxMonAt(u8 boxId, u8 boxPosition, u16 species, u8 level, u8 fixedIV, u8 hasFixedPersonality, u32 personality, u8 otIDType, u32 otID, u8 formId)
{
    if (boxId < TOTAL_BOXES_COUNT && boxPosition < IN_BOX_COUNT)
    {
        CreateBoxMon(&gPokemonStoragePtr->boxes[boxId][boxPosition],
                     species,
                     level,
                     fixedIV,
                     hasFixedPersonality, personality,
                     otIDType, otID, formId);
    }
}

void ZeroBoxMonAt(u8 boxId, u8 boxPosition)
{
    if (boxId < TOTAL_BOXES_COUNT && boxPosition < IN_BOX_COUNT)
        ZeroBoxMonData(&gPokemonStoragePtr->boxes[boxId][boxPosition]);
}

void BoxMonAtToMon(u8 boxId, u8 boxPosition, struct Pokemon *dst)
{
    if (boxId < TOTAL_BOXES_COUNT && boxPosition < IN_BOX_COUNT)
        BoxMonToMon(&gPokemonStoragePtr->boxes[boxId][boxPosition], dst);
}

struct BoxPokemon *GetBoxedMonPtr(u8 boxId, u8 boxPosition)
{
    if (boxId < TOTAL_BOXES_COUNT && boxPosition < IN_BOX_COUNT)
        return &gPokemonStoragePtr->boxes[boxId][boxPosition];
    else
        return NULL;
}

u8 *GetBoxNamePtr(u8 boxId)
{
    if (boxId < TOTAL_BOXES_COUNT)
        return gPokemonStoragePtr->boxNames[boxId];
    else
        return NULL;
}

u8 GetBoxWallpaper(u8 boxId)
{
    if (boxId < TOTAL_BOXES_COUNT)
        return gPokemonStoragePtr->boxWallpapers[boxId];
    else
        return 0;
}

void SetBoxWallpaper(u8 boxId, u8 wallpaperId)
{
    if (boxId < TOTAL_BOXES_COUNT && wallpaperId < WALLPAPER_COUNT)
        gPokemonStoragePtr->boxWallpapers[boxId] = wallpaperId;
}

s16 sub_80D214C(struct BoxPokemon *boxMons, u8 currIndex, u8 maxIndex, u8 arg3)
{
    s16 i;
    s16 adder = -1;

    if (arg3 < 2)
        adder = 1;

    if (arg3 == 1 || arg3 == 3)
    {
        for (i = (s8)currIndex + adder; i >= 0 && i <= maxIndex; i += adder)
        {
            if (GetBoxMonData(&boxMons[i], MON_DATA_SPECIES) != SPECIES_NONE)
                return i;
        }
    }
    else
    {
        for (i = (s8)currIndex + adder; i >= 0 && i <= maxIndex; i += adder)
        {
            if (GetBoxMonData(&boxMons[i], MON_DATA_SPECIES) != SPECIES_NONE
                && !GetBoxMonData(&boxMons[i], MON_DATA_IS_EGG))
                return i;
        }
    }

    return -1;
}

bool8 CheckFreePokemonStorageSpace(void)
{
    s32 i, j;

    for (i = 0; i < TOTAL_BOXES_COUNT; i++)
    {
        for (j = 0; j < IN_BOX_COUNT; j++)
        {
            if (!GetBoxMonData(&gPokemonStoragePtr->boxes[i][j], MON_DATA_SANITY_HAS_SPECIES))
                return TRUE;
        }
    }

    return FALSE;
}

bool32 CheckBoxMonSanityAt(u32 boxId, u32 boxPosition)
{
    if (boxId < TOTAL_BOXES_COUNT
        && boxPosition < IN_BOX_COUNT
        && GetBoxMonData(&gPokemonStoragePtr->boxes[boxId][boxPosition], MON_DATA_SANITY_HAS_SPECIES)
        && !GetBoxMonData(&gPokemonStoragePtr->boxes[boxId][boxPosition], MON_DATA_SANITY_IS_EGG)
        && !GetBoxMonData(&gPokemonStoragePtr->boxes[boxId][boxPosition], MON_DATA_SANITY_IS_BAD_EGG))
        return TRUE;
    else
        return FALSE;
}

u32 CountStorageNonEggMons(void)
{
    s32 i, j;
    u32 count = 0;

    for (i = 0; i < TOTAL_BOXES_COUNT; i++)
    {
        for (j = 0; j < IN_BOX_COUNT; j++)
        {
            if (GetBoxMonData(&gPokemonStoragePtr->boxes[i][j], MON_DATA_SANITY_HAS_SPECIES)
                && !GetBoxMonData(&gPokemonStoragePtr->boxes[i][j], MON_DATA_SANITY_IS_EGG))
                count++;
        }
    }

    return count;
}

u32 CountAllStorageMons(void)
{
    s32 i, j;
    u32 count = 0;

    for (i = 0; i < TOTAL_BOXES_COUNT; i++)
    {
        for (j = 0; j < IN_BOX_COUNT; j++)
        {
            if (GetBoxMonData(&gPokemonStoragePtr->boxes[i][j], MON_DATA_SANITY_HAS_SPECIES)
                || GetBoxMonData(&gPokemonStoragePtr->boxes[i][j], MON_DATA_SANITY_IS_EGG))
                count++;
        }
    }

    return count;
}

bool32 AnyStorageMonWithMove(u16 moveId)
{
    u16 moves[] = {moveId, MOVES_COUNT};
    s32 i, j;

    for (i = 0; i < TOTAL_BOXES_COUNT; i++)
    {
        for (j = 0; j < IN_BOX_COUNT; j++)
        {
            if (GetBoxMonData(&gPokemonStoragePtr->boxes[i][j], MON_DATA_SANITY_HAS_SPECIES)
                && !GetBoxMonData(&gPokemonStoragePtr->boxes[i][j], MON_DATA_SANITY_IS_EGG)
                && GetBoxMonData(&gPokemonStoragePtr->boxes[i][j], MON_DATA_KNOWN_MOVES, (u8*)moves))
                return TRUE;
        }
    }

    return FALSE;
}

void ResetWaldaWallpaper(void)
{
    gSaveBlock1Ptr->waldaPhrase.iconId = 0;
    gSaveBlock1Ptr->waldaPhrase.patternId = 0;
    gSaveBlock1Ptr->waldaPhrase.patternUnlocked = FALSE;
    gSaveBlock1Ptr->waldaPhrase.colors[0] = RGB(21, 25, 30);
    gSaveBlock1Ptr->waldaPhrase.colors[1] = RGB(6, 12, 24);
    gSaveBlock1Ptr->waldaPhrase.text[0] = EOS;
}

void SetWaldaWallpaperLockedOrUnlocked(bool32 unlocked)
{
    gSaveBlock1Ptr->waldaPhrase.patternUnlocked = unlocked;
}

bool32 IsWaldaWallpaperUnlocked(void)
{
    return gSaveBlock1Ptr->waldaPhrase.patternUnlocked;
}

u32 GetWaldaWallpaperPatternId(void)
{
    return gSaveBlock1Ptr->waldaPhrase.patternId;
}

void SetWaldaWallpaperPatternId(u8 id)
{
    if (id < FRIENDS_WALLPAPERS_COUNT)
        gSaveBlock1Ptr->waldaPhrase.patternId = id;
}

u32 GetWaldaWallpaperIconId(void)
{
    return gSaveBlock1Ptr->waldaPhrase.iconId;
}

void SetWaldaWallpaperIconId(u8 id)
{
    if (id < 30)
        gSaveBlock1Ptr->waldaPhrase.iconId = id;
}

u16 *GetWaldaWallpaperColorsPtr(void)
{
    return gSaveBlock1Ptr->waldaPhrase.colors;
}

void SetWaldaWallpaperColors(u16 color1, u16 color2)
{
    gSaveBlock1Ptr->waldaPhrase.colors[0] = color1;
    gSaveBlock1Ptr->waldaPhrase.colors[1] = color2;
}

u8 *GetWaldaPhrasePtr(void)
{
    return gSaveBlock1Ptr->waldaPhrase.text;
}

void SetWaldaPhrase(const u8 *src)
{
    StringCopy(gSaveBlock1Ptr->waldaPhrase.text, src);
}

bool32 IsWaldaPhraseEmpty(void)
{
    return (gSaveBlock1Ptr->waldaPhrase.text[0] == EOS);
}

// Not sure what the purpose of these functions is.
// They seem to only be called while PSS is initialized.

EWRAM_DATA static struct UnkStruct_2039D84 *gUnknown_02039D84 = NULL;
EWRAM_DATA static u16 gUnknown_02039D88 = 0;

static void TilemapUtil_Init(u8 count)
{
    u16 i;

    gUnknown_02039D84 = Alloc(sizeof(*gUnknown_02039D84) * count);
    gUnknown_02039D88 = (gUnknown_02039D84 == NULL) ? 0 : count;
    for (i = 0; i < gUnknown_02039D88; i++)
    {
        gUnknown_02039D84[i].field_18 = NULL;
        gUnknown_02039D84[i].field_2C = 0;
    }
}

static void sub_80D25F0(void)
{
    Free(gUnknown_02039D84);
}

static void sub_80D2604(void)
{
    s32 i;

    for (i = 0; i < gUnknown_02039D88; i++)
    {
        if (gUnknown_02039D84[i].field_2C == 1)
            sub_80D2918(i);
    }
}

struct
{
    u16 a;
    u16 b;
}
static const sUnkVars[][4] =
{
    {
        {0x0100, 0x0100},
        {0x0200, 0x0100},
        {0x0100, 0x0200},
        {0x0200, 0x0200},
    },
    {
        {0x0080, 0x0080},
        {0x0100, 0x0100},
        {0x0200, 0x0200},
        {0x0400, 0x0400},
    },
};

static void TilemapUtil_SetMap(u8 id, u8 bg, const void *arg2, u16 arg3, u16 arg4)
{
    u16 bgScreenSize, bgType;

    if (id >= gUnknown_02039D88)
        return;

    gUnknown_02039D84[id].field_18 = NULL;
    gUnknown_02039D84[id].field_1C = arg2;
    gUnknown_02039D84[id].field_2B = bg;
    gUnknown_02039D84[id].field_24 = arg3;
    gUnknown_02039D84[id].field_26 = arg4;

    bgScreenSize = GetBgAttribute(bg, BG_ATTR_SCREENSIZE);
    bgType = GetBgAttribute(bg, BG_ATTR_TYPE);
    gUnknown_02039D84[id].field_20 = sUnkVars[bgType][bgScreenSize].a;
    gUnknown_02039D84[id].field_22 = sUnkVars[bgType][bgScreenSize].b;
    if (bgType != 0)
        gUnknown_02039D84[id].field_2A = 1;
    else
        gUnknown_02039D84[id].field_2A = 2;

    gUnknown_02039D84[id].field_28 = gUnknown_02039D84[id].field_2A * arg3;
    gUnknown_02039D84[id].field_0[1].field_4 = arg3;
    gUnknown_02039D84[id].field_0[1].field_6 = arg4;
    gUnknown_02039D84[id].field_0[1].field_0 = 0;
    gUnknown_02039D84[id].field_0[1].field_2 = 0;
    gUnknown_02039D84[id].field_0[1].field_8 = 0;
    gUnknown_02039D84[id].field_0[1].field_A = 0;
    gUnknown_02039D84[id].field_0[0] = gUnknown_02039D84[id].field_0[1];
    gUnknown_02039D84[id].field_2C = 1;
}

static void sub_80D2740(u8 id, const void *arg1)
{
    if (id >= gUnknown_02039D88)
        return;

    gUnknown_02039D84[id].field_18 = arg1;
    gUnknown_02039D84[id].field_2C = 1;
}

static void TilemapUtil_SetPos(u8 id, u16 arg1, u16 arg2)
{
    if (id >= gUnknown_02039D88)
        return;

    gUnknown_02039D84[id].field_0[1].field_8 = arg1;
    gUnknown_02039D84[id].field_0[1].field_A = arg2;
    gUnknown_02039D84[id].field_2C = 1;
}

static void sub_80D27AC(u8 id, u16 arg1, u16 arg2, u16 arg3, u16 arg4)
{
    if (id >= gUnknown_02039D88)
        return;

    gUnknown_02039D84[id].field_0[1].field_0 = arg1;
    gUnknown_02039D84[id].field_0[1].field_2 = arg2;
    gUnknown_02039D84[id].field_0[1].field_4 = arg3;
    gUnknown_02039D84[id].field_0[1].field_6 = arg4;
    gUnknown_02039D84[id].field_2C = 1;
}

static void sub_80D27F4(u8 id, u8 arg1, s8 arg2)
{
    if (id >= gUnknown_02039D88)
        return;

    switch (arg1)
    {
    case 0:
        gUnknown_02039D84[id].field_0[1].field_8 += arg2;
        gUnknown_02039D84[id].field_0[1].field_4 -= arg2;
        break;
    case 1:
        gUnknown_02039D84[id].field_0[1].field_0 += arg2;
        gUnknown_02039D84[id].field_0[1].field_4 += arg2;
        break;
    case 2:
        gUnknown_02039D84[id].field_0[1].field_A += arg2;
        gUnknown_02039D84[id].field_0[1].field_6 -= arg2;
        break;
    case 3:
        gUnknown_02039D84[id].field_0[1].field_2 -= arg2;
        gUnknown_02039D84[id].field_0[1].field_6 += arg2;
        break;
    case 4:
        gUnknown_02039D84[id].field_0[1].field_8 += arg2;
        break;
    case 5:
        gUnknown_02039D84[id].field_0[1].field_A += arg2;
        break;
    }

    gUnknown_02039D84[id].field_2C = 1;
}

static void sub_80D2918(u8 id)
{
    if (id >= gUnknown_02039D88)
        return;

    if (gUnknown_02039D84[id].field_18 != NULL)
        sub_80D2960(id);

    sub_80D29F8(id);
    gUnknown_02039D84[id].field_0[0] = gUnknown_02039D84[id].field_0[1];
}

static void sub_80D2960(u8 id)
{
    s32 i;
    u32 adder = gUnknown_02039D84[id].field_2A * gUnknown_02039D84[id].field_20;
    const void *tiles = (gUnknown_02039D84[id].field_18 + (adder * gUnknown_02039D84[id].field_0[0].field_A))
                      + (gUnknown_02039D84[id].field_2A * gUnknown_02039D84[id].field_0[0].field_8);

    for (i = 0; i < gUnknown_02039D84[id].field_0[0].field_6; i++)
    {
        CopyToBgTilemapBufferRect(gUnknown_02039D84[id].field_2B,
                                  tiles,
                                  gUnknown_02039D84[id].field_0[0].field_8,
                                  gUnknown_02039D84[id].field_0[0].field_A + i,
                                  gUnknown_02039D84[id].field_0[0].field_4,
                                  1);
        tiles += adder;
    }
}

static void sub_80D29F8(u8 id)
{
    s32 i;
    u32 adder = gUnknown_02039D84[id].field_2A * gUnknown_02039D84[id].field_24;
    const void *tiles = (gUnknown_02039D84[id].field_1C + (adder * gUnknown_02039D84[id].field_0[1].field_2))
                      + (gUnknown_02039D84[id].field_2A * gUnknown_02039D84[id].field_0[1].field_0);

    for (i = 0; i < gUnknown_02039D84[id].field_0[1].field_6; i++)
    {
        CopyToBgTilemapBufferRect(gUnknown_02039D84[id].field_2B,
                                  tiles,
                                  gUnknown_02039D84[id].field_0[1].field_8,
                                  gUnknown_02039D84[id].field_0[1].field_A + i,
                                  gUnknown_02039D84[id].field_0[1].field_4,
                                  1);
        tiles += adder;
    }
}

EWRAM_DATA static struct UnkUtil *gUnknown_02039D8C = NULL;

static void UnkUtil_Init(struct UnkUtil *arg0, struct UnkUtilData *arg1, u32 arg2)
{
    gUnknown_02039D8C = arg0;
    arg0->unk_00 = arg1;
    arg0->unk_05 = arg2;
    arg0->unk_04 = 0;
}

static void sub_80D2AA4(void)
{
    u16 i;

    if (gUnknown_02039D8C->unk_04)
    {
        for (i = 0; i < gUnknown_02039D8C->unk_04; i++)
        {
            struct UnkUtilData *unkStruct = &gUnknown_02039D8C->unk_00[i];
            unkStruct->unk_0c(unkStruct);
        }

        gUnknown_02039D8C->unk_04 = 0;
    }
}

static bool8 sub_80D2AEC(u8 *dest, u16 dLeft, u16 dTop, const u8 *src, u16 sLeft, u16 sTop, u16 width, u16 height, u16 unkArg)
{
    struct UnkUtilData *unkStruct;

    if (gUnknown_02039D8C->unk_04 >= gUnknown_02039D8C->unk_05)
        return FALSE;

    unkStruct = &gUnknown_02039D8C->unk_00[gUnknown_02039D8C->unk_04++];
    unkStruct->unk_08 = width * 2;
    unkStruct->unk_04 = dest + 2 * (dTop * 32 + dLeft);
    unkStruct->unk_00 = src + 2 * (sTop * unkArg + sLeft);
    unkStruct->newField = height;
    unkStruct->unk_0a = unkArg;
    unkStruct->unk_0c = sub_80D2B88;
    return TRUE;
}

static void sub_80D2B88(struct UnkUtilData *unkStruct)
{
    u16 i;

    for (i = 0; i < unkStruct->newField; i++)
    {
        CpuSet(unkStruct->unk_00, unkStruct->unk_04, (unkStruct->unk_08 / 2));
        unkStruct->unk_04 += 64;
        unkStruct->unk_00 += (unkStruct->unk_0a * 2);
    }
}

static bool8 sub_80D2BC0(void *dest, u16 dLeft, u16 dTop, u16 width, u16 height)
{
    struct UnkUtilData *unkStruct;

    if (gUnknown_02039D8C->unk_04 >= gUnknown_02039D8C->unk_05)
        return FALSE;

    unkStruct = &gUnknown_02039D8C->unk_00[gUnknown_02039D8C->unk_04++];
    unkStruct->unk_08 = width * 2;
    unkStruct->unk_04 = dest + ((dTop * 32) + dLeft) * 2;
    unkStruct->newField = height;
    unkStruct->unk_0c = sub_80D2C1C;
    return TRUE;
}

static void sub_80D2C1C(struct UnkUtilData *unkStruct)
{
    u16 i;

    for (i = 0; i < unkStruct->newField; i++)
    {
        Dma3FillLarge_(0, unkStruct->unk_04, unkStruct->unk_08, 16);
        unkStruct->unk_04 += 64;
    }
}

//DB Stuff -----------------------------------------------------------------------------------------
#define COMPRESSED_POKEMON_BYTE_SIZE 36
#define NUM_CLEAN_EWRAM_DATA         0

void SendPartyMonToDB(u8 position){
    u8 i;
    struct CompressedPokemon CompressedPokemon;
    u16 to[COMPRESSED_POKEMON_BYTE_SIZE / 2];
    struct Pokemon *mon = &gPlayerParty[position];

    CompressedPokemon.personality = GetMonData(mon, MON_DATA_PERSONALITY, NULL);
    CompressedPokemon.otId        = GetMonData(mon, MON_DATA_OT_ID, NULL);
    GetMonData(mon, MON_DATA_OT_NAME, CompressedPokemon.otName);
    CompressedPokemon.species     = GetMonData(mon, MON_DATA_SPECIES2, NULL);
    CompressedPokemon.formId      = GetMonData(mon, MON_DATA_FORM_ID, NULL);
    CompressedPokemon.heldItem    = GetMonData(mon, MON_DATA_HELD_ITEM, NULL);
    CompressedPokemon.nature      = GetMonData(mon, MON_DATA_HIDDEN_NATURE, NULL);
    CompressedPokemon.exiolite    = GetMonData(mon, MON_DATA_EXIOLITE_ENABLED, NULL);
    CompressedPokemon.hpIV        = GetMonData(mon, MON_DATA_HP_IV, NULL);
    CompressedPokemon.attackIV    = GetMonData(mon, MON_DATA_ATK_IV, NULL);
    CompressedPokemon.defenseIV   = GetMonData(mon, MON_DATA_DEF_IV, NULL);
    CompressedPokemon.spAttackIV  = GetMonData(mon, MON_DATA_SPATK_IV, NULL);
    CompressedPokemon.spDefenseIV = GetMonData(mon, MON_DATA_SPDEF_IV, NULL);
    CompressedPokemon.speedIV     = GetMonData(mon, MON_DATA_SPEED_IV, NULL);

    CompressedPokemon.hpEV        = GetMonData(mon, MON_DATA_HP_EV, NULL);
    CompressedPokemon.attackEV    = GetMonData(mon, MON_DATA_ATK_EV, NULL);
    CompressedPokemon.defenseEV   = GetMonData(mon, MON_DATA_DEF_EV, NULL);
    CompressedPokemon.spAttackEV  = GetMonData(mon, MON_DATA_SPATK_EV, NULL);
    CompressedPokemon.spDefenseEV = GetMonData(mon, MON_DATA_SPDEF_EV, NULL);
    CompressedPokemon.speedEV     = GetMonData(mon, MON_DATA_SPEED_EV, NULL);

    CompressedPokemon.level       = GetMonData(mon, MON_DATA_LEVEL, NULL);
    CompressedPokemon.moves1      = GetMonData(mon, MON_DATA_MOVE1, NULL);
    CompressedPokemon.moves2      = GetMonData(mon, MON_DATA_MOVE2, NULL);
    CompressedPokemon.moves3      = GetMonData(mon, MON_DATA_MOVE3, NULL);
    CompressedPokemon.moves4      = GetMonData(mon, MON_DATA_MOVE4, NULL);
    CompressedPokemon.abilityNum  = GetMonData(mon, MON_DATA_ABILITY_NUM, NULL);
    CompressedPokemon.pokeball    = GetMonData(mon, MON_DATA_POKEBALL, NULL);

    memcpy(to, &CompressedPokemon, sizeof(to));
    mgba_printf(MGBA_LOG_WARN, "InsertMon:%d:%d:%d:Nickname:%d:%d:%d:%d:%d:%d:%d:%d:%d:%d:%d:%d:%d:%d:%d:%d:%d:%d", CompressedPokemon.species, CompressedPokemon.level, IsMonShiny(mon), to[0],to[1],to[2],to[3],to[4],to[5],to[6],to[7],to[8],to[9],to[10],to[11],to[12],to[13],to[14],to[15],to[16],to[17],to[18]);
}

void SendBoxMonToDB(u8 boxId, u8 boxPosition){
    u8 i;
    struct CompressedPokemon CompressedPokemon;
    u16 to[COMPRESSED_POKEMON_BYTE_SIZE / 2];
    struct BoxPokemon *boxMon = &gPokemonStoragePtr->boxes[boxId][boxPosition];
    struct Pokemon pokemon;
    BoxMonToMon(boxMon, &pokemon);

    CompressedPokemon.personality = GetMonData(&pokemon, MON_DATA_PERSONALITY, NULL);
    CompressedPokemon.otId        = GetMonData(&pokemon, MON_DATA_OT_ID, NULL);
    GetMonData(&pokemon, MON_DATA_OT_NAME, CompressedPokemon.otName);
    CompressedPokemon.species     = GetMonData(&pokemon, MON_DATA_SPECIES2, NULL);
    CompressedPokemon.formId      = GetMonData(&pokemon, MON_DATA_FORM_ID, NULL);
    CompressedPokemon.heldItem    = GetMonData(&pokemon, MON_DATA_HELD_ITEM, NULL);
    CompressedPokemon.nature      = GetMonData(&pokemon, MON_DATA_HIDDEN_NATURE, NULL);
    CompressedPokemon.exiolite    = GetMonData(&pokemon, MON_DATA_EXIOLITE_ENABLED, NULL);
    CompressedPokemon.hpIV        = GetMonData(&pokemon, MON_DATA_HP_IV, NULL);
    CompressedPokemon.attackIV    = GetMonData(&pokemon, MON_DATA_ATK_IV, NULL);
    CompressedPokemon.defenseIV   = GetMonData(&pokemon, MON_DATA_DEF_IV, NULL);
    CompressedPokemon.spAttackIV  = GetMonData(&pokemon, MON_DATA_SPATK_IV, NULL);
    CompressedPokemon.spDefenseIV = GetMonData(&pokemon, MON_DATA_SPDEF_IV, NULL);
    CompressedPokemon.speedIV     = GetMonData(&pokemon, MON_DATA_SPEED_IV, NULL);

    CompressedPokemon.hpEV        = GetMonData(&pokemon, MON_DATA_HP_EV, NULL);
    CompressedPokemon.attackEV    = GetMonData(&pokemon, MON_DATA_ATK_EV, NULL);
    CompressedPokemon.defenseEV   = GetMonData(&pokemon, MON_DATA_DEF_EV, NULL);
    CompressedPokemon.spAttackEV  = GetMonData(&pokemon, MON_DATA_SPATK_EV, NULL);
    CompressedPokemon.spDefenseEV = GetMonData(&pokemon, MON_DATA_SPDEF_EV, NULL);
    CompressedPokemon.speedEV     = GetMonData(&pokemon, MON_DATA_SPEED_EV, NULL);

    CompressedPokemon.level       = GetMonData(&pokemon, MON_DATA_LEVEL, NULL);
    CompressedPokemon.moves1      = GetMonData(&pokemon, MON_DATA_MOVE1, NULL);
    CompressedPokemon.moves2      = GetMonData(&pokemon, MON_DATA_MOVE2, NULL);
    CompressedPokemon.moves3      = GetMonData(&pokemon, MON_DATA_MOVE3, NULL);
    CompressedPokemon.moves4      = GetMonData(&pokemon, MON_DATA_MOVE4, NULL);
    CompressedPokemon.abilityNum  = GetMonData(&pokemon, MON_DATA_ABILITY_NUM, NULL);
    CompressedPokemon.pokeball    = GetMonData(&pokemon, MON_DATA_POKEBALL, NULL);

    memcpy(to, &CompressedPokemon, sizeof(to));
    mgba_printf(MGBA_LOG_WARN,"InsertMon:%d:%d:%d:Nickname:%d:%d:%d:%d:%d:%d:%d:%d:%d:%d:%d:%d:%d:%d:%d:%d:%d:%d", CompressedPokemon.species, CompressedPokemon.level, IsMonShiny(&pokemon), to[0],to[1],to[2],to[3],to[4],to[5],to[6],to[7],to[8],to[9],to[10],to[11],to[12],to[13],to[14],to[15],to[16],to[17],to[18]);
}

bool8 GiveCompressedPokemon(struct CompressedPokemon CompressedPokemon){
	struct Pokemon mon;
    u8 i;
	u16 nationalDexNum;
    int sentToPc;
    u32 otid        = CompressedPokemon.otId;
    u32 personality = CompressedPokemon.personality;
    u16 species     = CompressedPokemon.species;
    u8 formId       = CompressedPokemon.formId;
    u16 heldItem    = CompressedPokemon.heldItem;
    u8 nature       = CompressedPokemon.nature;
    bool8 exiolite  = CompressedPokemon.exiolite;

    u8 hpIV         = CompressedPokemon.hpIV;
    u8 attackIV     = CompressedPokemon.attackIV;
    u8 defenseIV    = CompressedPokemon.defenseIV;
    u8 spAttackIV   = CompressedPokemon.spAttackIV;
    u8 spDefenseIV  = CompressedPokemon.spDefenseIV;
    u8 speedIV      = CompressedPokemon.speedIV;

    bool8 otGender  = CompressedPokemon.otGender;
    u8 hpEV         = CompressedPokemon.hpEV;
    u8 attackEV     = CompressedPokemon.attackEV;
    u8 defenseEV    = CompressedPokemon.defenseEV;
    u8 spAttackEV   = CompressedPokemon.spAttackEV;
    u8 spDefenseEV  = CompressedPokemon.spDefenseEV;
    u8 speedEV      = CompressedPokemon.speedEV;
    u8 level        = CompressedPokemon.level;
    u16 moves1      = CompressedPokemon.moves1;
    u16 moves2      = CompressedPokemon.moves2;
    u16 moves3      = CompressedPokemon.moves3;
    u16 moves4      = CompressedPokemon.moves4;
    u8 abilityNum   = CompressedPokemon.abilityNum;
    u8 pokeball     = CompressedPokemon.pokeball;

    CreateMon(&mon, species, level, 32, 1, personality, OT_ID_PRESET, otid, formId);

    SetMonData(&mon, MON_DATA_HELD_ITEM,        &heldItem);
    SetMonData(&mon, MON_DATA_HIDDEN_NATURE,    &nature);
    SetMonData(&mon, MON_DATA_EXIOLITE_ENABLED, &exiolite);
    SetMonData(&mon, MON_DATA_HP_IV,            &hpIV);
    SetMonData(&mon, MON_DATA_ATK_IV,           &attackIV);
    SetMonData(&mon, MON_DATA_DEF_IV,           &defenseIV);
    SetMonData(&mon, MON_DATA_SPATK_IV,         &spAttackIV);
    SetMonData(&mon, MON_DATA_SPDEF_IV,         &spDefenseIV);
    SetMonData(&mon, MON_DATA_SPEED_IV,         &speedIV);
    SetMonData(&mon, MON_DATA_HP_EV,            &hpEV);
    SetMonData(&mon, MON_DATA_ATK_EV,           &attackEV);
    SetMonData(&mon, MON_DATA_DEF_EV,           &defenseEV);
    SetMonData(&mon, MON_DATA_SPATK_EV,         &spAttackEV);
    SetMonData(&mon, MON_DATA_SPDEF_EV,         &spDefenseEV);
    SetMonData(&mon, MON_DATA_SPEED_EV,         &speedEV);
    SetMonData(&mon, MON_DATA_LEVEL,            &level);
    SetMonData(&mon, MON_DATA_MOVE1,            &moves1);
    SetMonData(&mon, MON_DATA_MOVE2,            &moves2);
    SetMonData(&mon, MON_DATA_MOVE3,            &moves3);
    SetMonData(&mon, MON_DATA_MOVE4,            &moves4);
    SetMonData(&mon, MON_DATA_ABILITY_NUM,      &abilityNum);
    SetMonData(&mon, MON_DATA_POKEBALL,         &pokeball);
    SetMonData(&mon, MON_DATA_OT_GENDER,        &otGender);
    SetMonData(&mon, MON_DATA_OT_NAME,          &CompressedPokemon.otName);

    for (i = 0; i < PARTY_SIZE; i++)
    {
        if (GetMonData(&gPlayerParty[i], MON_DATA_SPECIES, NULL) == SPECIES_NONE)
            break;
    }
	//Pokedex entry
    nationalDexNum = SpeciesToNationalPokedexNum(species); 

    if (i >= PARTY_SIZE)
		sentToPc = SendMonToPC(&mon);
	else
	{
		sentToPc = MON_GIVEN_TO_PARTY;
		CopyMon(&gPlayerParty[i], &mon, sizeof(mon));
		gPlayerPartyCount = i + 1;
	}

    switch(sentToPc)
    {
    case MON_GIVEN_TO_PARTY:
    case MON_GIVEN_TO_PC:
        GetSetPokedexFlag(nationalDexNum, FLAG_SET_SEEN);
        GetSetPokedexFlag(nationalDexNum, FLAG_SET_CAUGHT);
        break;
    case MON_CANT_GIVE:
		return FALSE;
        break;
    }
    return TRUE;
}

struct CompressedPokemon CreateCompressedMonFromRam(void){
    u8 i;
    u8 password[COMPRESSED_POKEMON_BYTE_SIZE];
    bool8 working = TRUE;
    struct CompressedPokemon CompressedPokemon;
    for(i = 0; i < COMPRESSED_POKEMON_BYTE_SIZE; i++){
        password[i] = *(u8 *)(EWRAM_START + 0x3fd30 + (i * 0x1)); //Sends the password data into an array
    }
    memcpy(&CompressedPokemon, password, sizeof(CompressedPokemon));

    /*for(i = 0; i < COMPRESSED_POKEMON_BYTE_SIZE; i++){
        DmaFill16(3, NUM_CLEAN_EWRAM_DATA, EWRAM_START + 0x3fd30 + (i * 0x1), 0x2); //Clears the data
    }*/

    return CompressedPokemon;
}

bool8 GiveMonFromRam(void){
    struct CompressedPokemon CompressedPokemon = CreateCompressedMonFromRam();
    return GiveCompressedPokemon(CompressedPokemon);
}