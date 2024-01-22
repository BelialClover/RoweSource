#include "global.h"
#include "strings.h"
#include "bg.h"
#include "data.h"
#include "decompress.h"
#include "gpu_regs.h"
#include "graphics.h"
#include "item.h"
#include "level_scaling.h"
#include "item_menu.h"
#include "item_menu_icons.h"
#include "list_menu.h"
#include "item_icon.h"
#include "item_use.h"
#include "main.h"
#include "pokedex.h"
#include "malloc.h"
#include "menu.h"
#include "menu_helpers.h"
#include "palette.h"
#include "party_menu.h"
#include "scanline_effect.h"
#include "sound.h"
#include "string_util.h"
#include "strings.h"
#include "task.h"
#include "text_window.h"
#include "quests.h"
#include "overworld.h"
#include "event_data.h"
#include "constants/items.h"
#include "constants/field_weather.h"
#include "constants/songs.h"
#include "constants/rgb.h"
#include "rtc.h"

#define tCount          data[2]
#define tPageItems      data[4]
#define tItemPcParam    data[6]
#define tWindowId       data[10]
#define tListMenuTaskId data[11]

#define tState          data[0]
#define tXSpeed         data[1]
#define tYSpeed         data[2]
#define tWin0Left       data[3]
#define tWin0Right      data[4]
#define tWin0Top        data[5]
#define tWin0Bottom     data[6]
#define tBldCntBak      data[7]
#define tBldYBak        data[8]

// Defines
#define NO_ACTIVE_QUEST -1

struct QuestMenuResources
{
    /*0x00*/ MainCallback savedCallback;
    /*0x04*/ u8 moveModeOrigPos;
    /*0x05*/ u8 itemMenuIconSlot;
    /*0x06*/ u8 maxShowed;
    /*0x07*/ u8 nItems;
    /*0x08*/ u8 scrollIndicatorArrowPairId;
    /*0x0A*/ u16 withdrawQuantitySubmenuCursorPos;
    /*0x0C*/ s16 data[3];
}; /* size = 0x14 */

struct QuestMenuStaticResources
{
    /*0x00*/ MainCallback savedCallback;
    /*0x04*/ u16 scroll;
    /*0x06*/ u16 row;
    /*0x08*/ u8 initialized;
};  /* size = 0xC */

// RAM
EWRAM_DATA static struct QuestMenuResources *sStateDataPtr = NULL;
EWRAM_DATA static u8 *sBg1TilemapBuffer = NULL;
EWRAM_DATA static struct ListMenuItem *sListMenuItems = NULL;
EWRAM_DATA static struct QuestMenuStaticResources sListMenuState = {0};
EWRAM_DATA static u8 sSubmenuWindowIds[3] = {0};
EWRAM_DATA static u8 gUnknown_2039878[12] = {0};        // from pokefirered src/item_menu_icons.c

// This File's Functions
static void UnlockQuestMenu(void);
static void QuestMenu_RunSetup(void);
static bool8 QuestMenu_DoGfxSetup(void);
static void QuestMenu_FadeAndBail(void);
static void Task_QuestMenuWaitFadeAndBail(u8 taskId);
static bool8 QuestMenu_InitBgs(void);
static bool8 QuestMenu_LoadGraphics(void);
static bool8 QuestMenu_AllocateResourcesForListMenu(void);
static void QuestMenu_BuildListMenuTemplate(void);
static void QuestMenu_MoveCursorFunc(s32 itemIndex, bool8 onInit, struct ListMenu * list);
static void QuestMenu_ItemPrintFunc(u8 windowId, u32 itemId, u8 y);
static void QuestMenu_PrintOrRemoveCursorAt(u8 y, u8 state);
static void QuestMenu_PrintHeader(void);
static void QuestMenu_PlaceTopMenuScrollIndicatorArrows(void);
static void QuestMenu_SetCursorPosition(void);
static void QuestMenu_FreeResources(void);
static void Task_QuestMenuTurnOff2(u8 taskId);
static void QuestMenu_InitItems(void);
static void QuestMenu_SetScrollPosition(void);
static void Task_QuestMenuMain(u8 taskId);
static void QuestMenu_InsertItemIntoNewSlot(u8 taskId, u32 pos);
static void Task_QuestMenuSubmenuInit(u8 taskId);
static void Task_QuestMenuSubmenuRun(u8 taskId);
static void Task_QuestMenuHint(u8 taskId);
static void Task_QuestMenuProgress(u8 taskId);
static void Task_QuestMenuRewardInfo(u8 taskId);
static void Task_QuestMenuGetReward(u8 taskId);
static void Task_QuestMenuBeginQuest(u8 taskId);
static void Task_QuestMenuEndQuest(u8 taskId);
static void QuestMenu_DisplaySubMenuMessage(u8 taskId);
static void Task_QuestMenuRefreshAfterAcknowledgement(u8 taskId);
static void Task_QuestMenuCleanUp(u8 taskId);
static void QuestMenu_WithdrawMultipleInitWindow(u16 slotId);
static void Task_QuestMenuCancel(u8 taskId);
static void QuestMenu_InitWindows(void);
static void QuestMenu_AddTextPrinterParameterized(u8 windowId, u8 fontId, const u8 * str, u8 x, u8 y, u8 letterSpacing, u8 lineSpacing, u8 speed, u8 colorIdx);
static void QuestMenu_SetBorderStyleOnWindow(u8 windowId);
static u8 QuestMenu_GetOrCreateSubwindow(u8 idx);
static void QuestMenu_DestroySubwindow(u8 idx);
static void QuestMenu_SetInitializedFlag(u8 a0);
static bool8 IsActiveQuest(u8 questId);

// Data
// graphics
static const u32 sQuestMenuTiles[] = INCBIN_U32("graphics/quest_menu/menu.4bpp.lz");
static const u32 sQuestMenuBgPals[] = INCBIN_U32("graphics/quest_menu/menu_pal.gbapal.lz");
static const u32 sQuestMenuTilemap[] = INCBIN_U32("graphics/quest_menu/tilemap.bin.lz");
static const u16 sMainWindowPal[] = INCBIN_U16("graphics/quest_menu/main_window.gbapal");

// text window from firered
static const u16 sFR_StdFrame0[] = INCBIN_U16("graphics/text_window/fr_std0.4bpp");
//static const u16 sFR_StdFrame1[] = INCBIN_U16("graphics/text_window/fr_std1.4bpp");
static const u16 sFR_MessageBoxTiles[] = INCBIN_U16("graphics/text_window/fr_message_box.4bpp");

// strings
static const u8 sText_Empty[] = _("");
static const u8 sText_Quests[] = _("Achievement");
static const u8 sText_QuestMenu_Begin[] = _("Begin");
static const u8 sText_QuestMenu_End[] = _("End");
static const u8 sText_QuestMenu_Hint[] = _("Hint");
static const u8 sText_QuestMenu_Progress[] = _("Progress");
static const u8 sText_QuestMenu_Reward[] = _("Reward");
static const u8 sText_QuestMenu_Get_Reward[] = _("Prize");
static const u8 sText_QuestMenu_Complete[] = _("{COLOR}{BLUE}Done");
static const u8 sText_QuestMenu_Exit[] = _("Exit the Quest Menu");
static const u8 sText_QuestMenu_SelectedQuest[] = _("Do what with\nthis quest?");
static const u8 sText_QuestMenu_DisplayDetails[] = _("Hint: {STR_VAR_1}");
static const u8 sText_QuestMenu_DisplayProgress[] = _("Progress: {STR_VAR_1}/{STR_VAR_2}");
static const u8 sText_QuestMenu_DisplayReward[] = _("Reward: {STR_VAR_1}\nQuantity: {STR_VAR_2}");
static const u8 sText_QuestMenu_DisplayRewardDisabled[] = _("Reward: ?\nQuantity: Unknown");
static const u8 sText_QuestMenu_YouAlreadyHaveReward[] = _("You already got this prize");
static const u8 sText_QuestMenu_GotReward[] = _("Achievement Completed, You got\n{STR_VAR_1} x{STR_VAR_2} as a Reward.");
static const u8 sText_QuestMenu_BeginQuest[] = _("Initiating Quest:\n{STR_VAR_1}");
static const u8 sText_QuestMenu_EndQuest[] = _("Cancelling Quest:\n{STR_VAR_1}");

//Quest Status
static const u8 sText_QuestMenu_QuestNumber[] = _("{STR_VAR_1} - {STR_VAR_2}");
static const u8 sText_QuestMenu_Unk[] = _("?????????");
static const u8 sText_QuestMenu_Locked[] = _("Status: {COLOR}{LIGHT_RED}{SHADOW RED}Locked");
static const u8 sText_QuestMenu_Unlocked[] = _("Status: {COLOR}{LIGHT_BLUE}{SHADOW BLUE}Unlocked");
static const u8 sText_QuestMenu_Completed[] = _("Status: {COLOR}{LIGHT_GREEN}{SHADOW GREEN}Completed");
static const u8 sText_QuestMenu_GetYourReward[] = _("{COLOR}{LIGHT_GREEN}{SHADOW GREEN}Get your Reward!");

//Quest Difficulty
static const u8 sText_QuestMenu_Difficulty_Easy[] = _("Difficulty: {COLOR}{LIGHT_GREEN}{SHADOW GREEN}Easy");
static const u8 sText_QuestMenu_Difficulty_Medium[] = _("Difficulty: {COLOR}{LIGHT_BLUE}{SHADOW BLUE}Medium");
static const u8 sText_QuestMenu_Difficulty_Hard[] = _("Difficulty: {COLOR}{LIGHT_RED}{SHADOW RED}Hard");
static const u8 sText_QuestMenu_Difficulty_Extreme[] = _("Difficulty: {COLOR}{LIGHT_RED}{SHADOW RED}Extreme");
static const u8 sText_QuestMenu_Difficulty_Impossible[] = _("Difficulty: {COLOR}{LIGHT_RED}{SHADOW RED}Impossible");
static const u8 sText_QuestMenu_Difficulty_Disabled[] = _("{COLOR}{LIGHT_RED}{SHADOW RED}Disabled");
//// side quest data
//Quest 1	-	Done
static const u8 gText_SideQuestName_1[]  = _("001 - The Start of the Journey");
static const u8 gText_SideQuestDesc_1[]  = _("Win your first Gym Badge");
static const u8 gText_SideQuestHint_1[]  = _("One");
//Quest 2	-	Done
static const u8 gText_SideQuestName_2[]  = _("002 - Half way there");
static const u8 gText_SideQuestDesc_2[]  = _("Defeat 4 Different Gym Leaders");
static const u8 gText_SideQuestHint_2[]  = _("Four");
//Quest 3	-	Done
static const u8 gText_SideQuestName_3[]  = _("003 - Ready for Victory");
static const u8 gText_SideQuestDesc_3[]  = _("Defeat every Gym Leader in Hoenn");
static const u8 gText_SideQuestHint_3[]  = _("Eight");
//Quest 4	-	Done
static const u8 gText_SideQuestName_4[]  = _("004 - Frail Boy");
static const u8 gText_SideQuestDesc_4[]  = _("Defeat the Pokémon Trainer Wally in\nthe Victory Road");
static const u8 gText_SideQuestHint_4[]  = _("Frail");
//Quest 5	-	Done
static const u8 gText_SideQuestName_5[]  = _("005 - Hoenn Champion");
static const u8 gText_SideQuestDesc_5[]  = _("Enter the Hall of Fame for the first\ntime");
static const u8 gText_SideQuestHint_5[]  = _("Champion");
//Quest 6	-	Done
static const u8 gText_SideQuestName_6[]  = _("006 - Fry HIGHER");
static const u8 gText_SideQuestDesc_6[]  = _("Defeat or Catch the Sky High Pokémon\nRayquaza");
static const u8 gText_SideQuestHint_6[]  = _("Sky High");
//Quest 7	-	Done
static const u8 gText_SideQuestName_7[]  = _("007 - Pokémon Trader");
static const u8 gText_SideQuestDesc_7[]  = _("Complete every in-game Trade");
static const u8 gText_SideQuestHint_7[]  = _("Trade");
//Quest 8	-	Done
static const u8 gText_SideQuestName_8[]  = _("008 - Fossil Maniac");
static const u8 gText_SideQuestDesc_8[]  = _("Catch and Register every fossil\nin your Pokedex");
static const u8 gText_SideQuestHint_8[]  = _("Fossil");
//Quest 9	-	
static const u8 gText_SideQuestName_9[]  = _("009 - Friendly Trainer");
static const u8 gText_SideQuestDesc_9[]  = _("Have 6 Pokemon with Max\nHappiness");
static const u8 gText_SideQuestHint_9[]  = _("Friendship");
//Quest 10	-	Done
static const u8 gText_SideQuestName_10[] = _("010 - Changing times");
static const u8 gText_SideQuestDesc_10[] = _("Evolve 150 Pokemon");
static const u8 gText_SideQuestHint_10[] = _("Evolution");
//Quest 11	-	Done
static const u8 gText_SideQuestName_11[] = _("011 - I need new Shoes");
static const u8 gText_SideQuestDesc_11[] = _("Max out your step count");
static const u8 gText_SideQuestHint_11[] = _("Steps");
//Quest 12	-	
static const u8 gText_SideQuestName_12[] = _("012 - Seasoned Traveler");
static const u8 gText_SideQuestDesc_12[] = _("Visit every city in Hoenn");
static const u8 gText_SideQuestHint_12[] = _("Map");
//Quest 13	-	Done
static const u8 gText_SideQuestName_13[] = _("013 - JACKPOT");
static const u8 gText_SideQuestDesc_13[] = _("Match three 7 in the slot machines\n20 times");
static const u8 gText_SideQuestHint_13[] = _("Seven");
//Quest 14	-	Done
static const u8 gText_SideQuestName_14[] = _("014 - Big Prize");
static const u8 gText_SideQuestDesc_14[] = _("Win the Lottery for the first time");
static const u8 gText_SideQuestHint_14[] = _("Lottery");
//Quest 15
static const u8 gText_SideQuestName_15[] = _("015 - That thing's green");
static const u8 gText_SideQuestDesc_15[] = _("Get a green Shiny");
static const u8 gText_SideQuestHint_15[] = _("Green");
//Quest 16
static const u8 gText_SideQuestName_16[] = _("016 - Shiny Hunter");
static const u8 gText_SideQuestDesc_16[] = _("Have 5 Shiny Pokemon in your party");
static const u8 gText_SideQuestHint_16[] = _("Sparkle");
//Quest 17
static const u8 gText_SideQuestName_17[] = _("017 - A farmer's life");
static const u8 gText_SideQuestDesc_17[] = _("Plant 50 Berries");
static const u8 gText_SideQuestHint_17[] = _("Berry");
//Quest 18
static const u8 gText_SideQuestName_18[] = _("018 - Detective");
static const u8 gText_SideQuestDesc_18[] = _("Use the Dexnav 500 times");
static const u8 gText_SideQuestHint_18[] = _("Dexnav");
//Quest 19
static const u8 gText_SideQuestName_19[] = _("019 - I need an Umbrella");
static const u8 gText_SideQuestDesc_19[] = _("Get in a rainy weather 50 times");
static const u8 gText_SideQuestHint_19[] = _("Rain");
//Quest 20
static const u8 gText_SideQuestName_20[] = _("020 - Pokémon Breeder");
static const u8 gText_SideQuestDesc_20[] = _("Use the daycare 50 times");
static const u8 gText_SideQuestHint_20[] = _("Daycare");
//Quest 21
//static const u8 gText_SideQuestName_21[] = _("021 - The concept of time is scary");
static const u8 gText_SideQuestName_21[] = _("021 - Time is a scary thing");
static const u8 gText_SideQuestDesc_21[] = _("Check the clock 75 times");
static const u8 gText_SideQuestHint_21[] = _("Clock");
//Quest 22
static const u8 gText_SideQuestName_22[] = _("022 - True Coordinator");
static const u8 gText_SideQuestDesc_22[] = _("Win 25 Pokémon Contests");
static const u8 gText_SideQuestHint_22[] = _("Contest");
//Quest 23
static const u8 gText_SideQuestName_23[] = _("023 - One with the Rod");
static const u8 gText_SideQuestDesc_23[] = _("Fish and Capture 25 Pokémon ");
static const u8 gText_SideQuestHint_23[] = _("Fish");
//Quest 24
static const u8 gText_SideQuestName_24[] = _("024 - Rock or Bait");
static const u8 gText_SideQuestDesc_24[] = _("Go to the Safari Zone 50 times");
static const u8 gText_SideQuestHint_24[] = _("Safari");
//Quest 25
static const u8 gText_SideQuestName_25[] = _("025 - Out of PP");
static const u8 gText_SideQuestDesc_25[] = _("Use struggle 20 times");
static const u8 gText_SideQuestHint_25[] = _("PP");
//Quest 26
static const u8 gText_SideQuestName_26[] = _("026 - Gotta catch 'em all!");
static const u8 gText_SideQuestDesc_26[] = _("Catch 200 Pokemon");
static const u8 gText_SideQuestHint_26[] = _("Catch");
//Quest 27
static const u8 gText_SideQuestName_27[] = _("027 - Battle Enthusiast");
static const u8 gText_SideQuestDesc_27[] = _("Start 30 Normal Mock Battles");
static const u8 gText_SideQuestHint_27[] = _("Mock");
//Quest 28
static const u8 gText_SideQuestName_28[] = _("028 - Here we go Again");
static const u8 gText_SideQuestDesc_28[] = _("Update your game 5 times");
static const u8 gText_SideQuestHint_28[] = _("Update");
//Quest 29
static const u8 gText_SideQuestName_29[] = _("029 - Happy Birthday!");
static const u8 gText_SideQuestDesc_29[] = _("Have a Year old Save File");
static const u8 gText_SideQuestHint_29[] = _("Year");
//Quest 30
static const u8 gText_SideQuestName_30[] = _("030 - Trendy");
static const u8 gText_SideQuestDesc_30[] = _("Start 30 Trends");
static const u8 gText_SideQuestHint_30[] = _("Trend");
//Quest 31
static const u8 gText_SideQuestName_31[] = _("031 - Blockhead");
static const u8 gText_SideQuestDesc_31[] = _("Make 30 Pokéblocks");
static const u8 gText_SideQuestHint_31[] = _("Blocks");
//Quest 32
static const u8 gText_SideQuestName_32[] = _("032 - Sea-man");
static const u8 gText_SideQuestDesc_32[] = _("Gave the scanner to Capt. Stern");
static const u8 gText_SideQuestHint_32[] = _("Scanner");
//Quest 49
static const u8 gText_SideQuestName_49[] = _("049 - Pokémon Master");
static const u8 gText_SideQuestDesc_49[] = _("Defeat the Pokémon Master Red and the\nEx-Champion Steven");
static const u8 gText_SideQuestHint_49[] = _("Master");
//Quest 50
static const u8 gText_SideQuestName_50[] = _("050 - Silver Symbols");
static const u8 gText_SideQuestDesc_50[] = _("Get all the Silver Symbols in the    \n""Battle Frontier");
static const u8 gText_SideQuestHint_50[] = _("Silver");
//Quest 51
static const u8 gText_SideQuestName_51[] = _("051 - Ambition");
static const u8 gText_SideQuestDesc_51[] = _("Get a Shiny Rayquaza at the Title Screen");
static const u8 gText_SideQuestHint_51[] = _("Nobunaga");
//Quest 52
static const u8 gText_SideQuestName_52[] = _("052 - Hard Battler");
static const u8 gText_SideQuestDesc_52[] = _("Fight 50 Hard Mock battles");
static const u8 gText_SideQuestHint_52[] = _("Mock");
//Quest 53
static const u8 gText_SideQuestName_53[] = _("053 - Virus Detected");
static const u8 gText_SideQuestDesc_53[] = _("Get Pokerus atleast once");
static const u8 gText_SideQuestHint_53[] = _("Pokerus");
//Quest 54
static const u8 gText_SideQuestName_54[] = _("054 - Two times the fun");
static const u8 gText_SideQuestDesc_54[] = _("Start a New Game+ Save");
static const u8 gText_SideQuestHint_54[] = _("Plus");
//Quest 66
static const u8 gText_SideQuestName_66[] = _("066 - Spooky Time");
static const u8 gText_SideQuestDesc_66[] = _("Open this menu at 3AM");
static const u8 gText_SideQuestHint_66[] = _("Ghost");
//Quest 67
static const u8 gText_SideQuestName_67[] = _("067 - Luck's on my Side");
static const u8 gText_SideQuestDesc_67[] = _("Win a Hard Mock Battle with a Party of 6\nPokémon that only know Metronome");
static const u8 gText_SideQuestHint_67[] = _("Metronome");
//Quest 96
static const u8 gText_SideQuestName_96[] = _("096 - Double Platinum");
static const u8 gText_SideQuestDesc_96[] = _("Complete your TM Collection");
static const u8 gText_SideQuestHint_96[] = _("Discs");
//Quest 97
static const u8 gText_SideQuestName_97[] = _("097 - Gold Symbols");
static const u8 gText_SideQuestDesc_97[] = _("Get all the Gold Symbols in the      \nBattle Frontier");
static const u8 gText_SideQuestHint_97[] = _("Gold");
//Quest 98
static const u8 gText_SideQuestName_98[] = _("098 - Complete Researcher");
static const u8 gText_SideQuestDesc_98[] = _("Complete your Pokedex");
static const u8 gText_SideQuestHint_98[] = _("Dex");
//Quest 99
static const u8 gText_SideQuestName_99[] = _("099 - The last challenge");
static const u8 gText_SideQuestDesc_99[] = _("Defeat or Catch the Alpha Pokémon \nArceus");
static const u8 gText_SideQuestHint_99[] = _("Alpha");
//Quest 100
static const u8 gText_SideQuestName_100[] = _("100 - My deepest apologies");
static const u8 gText_SideQuestDesc_100[] = _("Complete every mission in the game");
static const u8 gText_SideQuestHint_100[] = _("The End");
//Test Quest
static const u8 gText_SideQuestName_00[] = _("Disabled Quest");
static const u8 gText_SideQuestDesc_00[] = _("This Quest is Disabled");
static const u8 gText_SideQuestHint_00[] = _("Wait");

#define side_quest(n, d, r, q, h, f) {.name = n, .desc = d, .reward = r, .reward_qty = q, .hint = h, .reward_flag = f}
static const struct SideQuest sSideQuests[SIDE_QUEST_COUNT] =
{
    side_quest(gText_SideQuestName_1,  gText_SideQuestDesc_1,  ITEM_LUCKY_EGG		, 1, 	gText_SideQuestHint_1,  FLAG_ACHIEVEMENT_REWARD_01),
    side_quest(gText_SideQuestName_2,  gText_SideQuestDesc_2,  ITEM_DESTINY_KNOT	, 1, 	gText_SideQuestHint_2,  FLAG_ACHIEVEMENT_REWARD_02),
    side_quest(gText_SideQuestName_3,  gText_SideQuestDesc_3,  ITEM_POWER_CANDY		, 6, 	gText_SideQuestHint_3,  FLAG_ACHIEVEMENT_REWARD_03),
    side_quest(gText_SideQuestName_4,  gText_SideQuestDesc_4,  ITEM_GALLADITE		, 1, 	gText_SideQuestHint_4,  FLAG_ACHIEVEMENT_REWARD_04),
    side_quest(gText_SideQuestName_5,  gText_SideQuestDesc_5,  ITEM_SWAMPERTITE		, 1, 	gText_SideQuestHint_5,  FLAG_ACHIEVEMENT_REWARD_05),
    side_quest(gText_SideQuestName_6,  gText_SideQuestDesc_6,  ITEM_LATIOSITE		, 1, 	gText_SideQuestHint_6,  FLAG_ACHIEVEMENT_REWARD_06),
    side_quest(gText_SideQuestName_7,  gText_SideQuestDesc_7,  ITEM_ALAKAZITE		, 1, 	gText_SideQuestHint_7,  FLAG_ACHIEVEMENT_REWARD_07),
    side_quest(gText_SideQuestName_8,  gText_SideQuestDesc_8,  ITEM_AERODACTYLITE	, 1, 	gText_SideQuestHint_8,  FLAG_ACHIEVEMENT_REWARD_08),
    side_quest(gText_SideQuestName_9,  gText_SideQuestDesc_9,  ITEM_SOOTHE_BELL		, 6, 	gText_SideQuestHint_9,  FLAG_ACHIEVEMENT_REWARD_09),
    side_quest(gText_SideQuestName_10, gText_SideQuestDesc_10, ITEM_RARE_CANDY		, 10, 	gText_SideQuestHint_10, FLAG_ACHIEVEMENT_REWARD_10),
    side_quest(gText_SideQuestName_11, gText_SideQuestDesc_11, ITEM_JOLLY_MINT		, 6, 	gText_SideQuestHint_11, FLAG_ACHIEVEMENT_REWARD_11),
    side_quest(gText_SideQuestName_12, gText_SideQuestDesc_12, ITEM_FLYING_GEM		, 6, 	gText_SideQuestHint_12, FLAG_ACHIEVEMENT_REWARD_12),
    side_quest(gText_SideQuestName_13, gText_SideQuestDesc_13, ITEM_BLACK_GLASSES	, 7, 	gText_SideQuestHint_13, FLAG_ACHIEVEMENT_REWARD_13),
    side_quest(gText_SideQuestName_14, gText_SideQuestDesc_14, ITEM_SHOCK_DRIVE		, 1, 	gText_SideQuestHint_14, FLAG_ACHIEVEMENT_REWARD_14),
    side_quest(gText_SideQuestName_15, gText_SideQuestDesc_15, ITEM_GREEN_SHARD		, 12, 	gText_SideQuestHint_15, FLAG_ACHIEVEMENT_REWARD_15),
    side_quest(gText_SideQuestName_16, gText_SideQuestDesc_16, ITEM_SHINY_STONE		, 6, 	gText_SideQuestHint_16, FLAG_ACHIEVEMENT_REWARD_16),
    side_quest(gText_SideQuestName_17, gText_SideQuestDesc_17, ITEM_ENIGMA_BERRY	, 1, 	gText_SideQuestHint_17, FLAG_ACHIEVEMENT_REWARD_17),
    side_quest(gText_SideQuestName_18, gText_SideQuestDesc_18, ITEM_ZOOM_LENS		, 3, 	gText_SideQuestHint_18, FLAG_ACHIEVEMENT_REWARD_18),
    side_quest(gText_SideQuestName_19, gText_SideQuestDesc_19, ITEM_DAMP_ROCK		, 3, 	gText_SideQuestHint_19, FLAG_ACHIEVEMENT_REWARD_19),
    side_quest(gText_SideQuestName_20, gText_SideQuestDesc_20, ITEM_OVAL_CHARM		, 1, 	gText_SideQuestHint_20, FLAG_ACHIEVEMENT_REWARD_20),
    side_quest(gText_SideQuestName_21, gText_SideQuestDesc_21, ITEM_ADAMANT_ORB		, 1, 	gText_SideQuestHint_21, FLAG_ACHIEVEMENT_REWARD_21),
    side_quest(gText_SideQuestName_22, gText_SideQuestDesc_22, ITEM_LATIASITE		, 1, 	gText_SideQuestHint_22, FLAG_ACHIEVEMENT_REWARD_22),
    side_quest(gText_SideQuestName_23, gText_SideQuestDesc_23, ITEM_LURE_BALL		, 20, 	gText_SideQuestHint_23, FLAG_ACHIEVEMENT_REWARD_23),
    side_quest(gText_SideQuestName_24, gText_SideQuestDesc_24, ITEM_SAFARI_BALL_SEAL, 5, 	gText_SideQuestHint_24, FLAG_ACHIEVEMENT_REWARD_24),
    side_quest(gText_SideQuestName_25, gText_SideQuestDesc_25, ITEM_MAX_ELIXIR		, 5, 	gText_SideQuestHint_25, FLAG_ACHIEVEMENT_REWARD_25),
    side_quest(gText_SideQuestName_26, gText_SideQuestDesc_26, ITEM_POKE_BALL		, 200, 	gText_SideQuestHint_26, FLAG_ACHIEVEMENT_REWARD_26),
    side_quest(gText_SideQuestName_27, gText_SideQuestDesc_27, ITEM_TM119_DRAIN_PUNCH, 1, 	gText_SideQuestHint_27, FLAG_ACHIEVEMENT_REWARD_27),
    side_quest(gText_SideQuestName_28, gText_SideQuestDesc_28, ITEM_UP_GRADE		, 1, 	gText_SideQuestHint_28, FLAG_ACHIEVEMENT_REWARD_28),
    side_quest(gText_SideQuestName_29, gText_SideQuestDesc_29, ITEM_CHERISH_BALL_SEAL, 1, 	gText_SideQuestHint_29, FLAG_ACHIEVEMENT_REWARD_29),
    side_quest(gText_SideQuestName_30, gText_SideQuestDesc_30, ITEM_PRETTY_WING		, 20, 	gText_SideQuestHint_30, FLAG_ACHIEVEMENT_REWARD_30),
	side_quest(gText_SideQuestName_31, gText_SideQuestDesc_31, ITEM_GARDEVOIRITE	, 1,    gText_SideQuestHint_31, FLAG_ACHIEVEMENT_REWARD_31),
    side_quest(gText_SideQuestName_32, gText_SideQuestDesc_32, ITEM_EXP_CHARM		, 1, 	gText_SideQuestHint_32, FLAG_ACHIEVEMENT_REWARD_32),
    side_quest(gText_SideQuestName_00, gText_SideQuestDesc_00, ITEM_POKE_BALL		, 1, 	gText_SideQuestHint_00, FLAG_ACHIEVEMENT_REWARD_01),
    side_quest(gText_SideQuestName_00, gText_SideQuestDesc_00, ITEM_POKE_BALL		, 1, 	gText_SideQuestHint_00, FLAG_ACHIEVEMENT_REWARD_01),
    side_quest(gText_SideQuestName_00, gText_SideQuestDesc_00, ITEM_POKE_BALL		, 1, 	gText_SideQuestHint_00, FLAG_ACHIEVEMENT_REWARD_01),
    side_quest(gText_SideQuestName_00, gText_SideQuestDesc_00, ITEM_POKE_BALL		, 1, 	gText_SideQuestHint_00, FLAG_ACHIEVEMENT_REWARD_01),
    side_quest(gText_SideQuestName_00, gText_SideQuestDesc_00, ITEM_POKE_BALL		, 1, 	gText_SideQuestHint_00, FLAG_ACHIEVEMENT_REWARD_01),
    side_quest(gText_SideQuestName_00, gText_SideQuestDesc_00, ITEM_POKE_BALL		, 1, 	gText_SideQuestHint_00, FLAG_ACHIEVEMENT_REWARD_01),
    side_quest(gText_SideQuestName_00, gText_SideQuestDesc_00, ITEM_POKE_BALL		, 1, 	gText_SideQuestHint_00, FLAG_ACHIEVEMENT_REWARD_01),
    side_quest(gText_SideQuestName_00, gText_SideQuestDesc_00, ITEM_POKE_BALL		, 1, 	gText_SideQuestHint_00, FLAG_ACHIEVEMENT_REWARD_01),//40
	side_quest(gText_SideQuestName_00, gText_SideQuestDesc_00, ITEM_POKE_BALL		, 1, 	gText_SideQuestHint_00, FLAG_ACHIEVEMENT_REWARD_01),
    side_quest(gText_SideQuestName_00, gText_SideQuestDesc_00, ITEM_POKE_BALL		, 1, 	gText_SideQuestHint_00, FLAG_ACHIEVEMENT_REWARD_01),
    side_quest(gText_SideQuestName_00, gText_SideQuestDesc_00, ITEM_POKE_BALL		, 1, 	gText_SideQuestHint_00, FLAG_ACHIEVEMENT_REWARD_01),
    side_quest(gText_SideQuestName_00, gText_SideQuestDesc_00, ITEM_POKE_BALL		, 1, 	gText_SideQuestHint_00, FLAG_ACHIEVEMENT_REWARD_01),
    side_quest(gText_SideQuestName_00, gText_SideQuestDesc_00, ITEM_POKE_BALL		, 1, 	gText_SideQuestHint_00, FLAG_ACHIEVEMENT_REWARD_01),
    side_quest(gText_SideQuestName_00, gText_SideQuestDesc_00, ITEM_POKE_BALL		, 1, 	gText_SideQuestHint_00, FLAG_ACHIEVEMENT_REWARD_01),
    side_quest(gText_SideQuestName_00, gText_SideQuestDesc_00, ITEM_POKE_BALL		, 1, 	gText_SideQuestHint_00, FLAG_ACHIEVEMENT_REWARD_01),
    side_quest(gText_SideQuestName_00, gText_SideQuestDesc_00, ITEM_POKE_BALL		, 1, 	gText_SideQuestHint_00, FLAG_ACHIEVEMENT_REWARD_01),
    side_quest(gText_SideQuestName_49, gText_SideQuestDesc_49, ITEM_GRACIDEA		, 1, 	gText_SideQuestHint_49, FLAG_ACHIEVEMENT_REWARD_49),
    side_quest(gText_SideQuestName_50, gText_SideQuestDesc_50, ITEM_SAFARI_PASS		, 1, 	gText_SideQuestHint_50, FLAG_ACHIEVEMENT_REWARD_50),//50
	side_quest(gText_SideQuestName_51, gText_SideQuestDesc_51, ITEM_TERRAIN_EXTENDER, 2, 	gText_SideQuestHint_51, FLAG_ACHIEVEMENT_REWARD_51),
    side_quest(gText_SideQuestName_52, gText_SideQuestDesc_52, ITEM_PROTECTIVE_PADS	, 3, 	gText_SideQuestHint_52, FLAG_ACHIEVEMENT_REWARD_52),
    side_quest(gText_SideQuestName_53, gText_SideQuestDesc_53, ITEM_SAFETY_GOGGLES	, 3, 	gText_SideQuestHint_53, FLAG_ACHIEVEMENT_REWARD_53),
    side_quest(gText_SideQuestName_54, gText_SideQuestDesc_54, ITEM_BEAST_BALL_SEAL	, 5,    gText_SideQuestHint_54, FLAG_ACHIEVEMENT_REWARD_54),
    side_quest(gText_SideQuestName_00, gText_SideQuestDesc_00, ITEM_POKE_BALL	, 1, gText_SideQuestHint_00, FLAG_ACHIEVEMENT_REWARD_01),
    side_quest(gText_SideQuestName_00, gText_SideQuestDesc_00, ITEM_POKE_BALL	, 1, gText_SideQuestHint_00, FLAG_ACHIEVEMENT_REWARD_01),
    side_quest(gText_SideQuestName_00, gText_SideQuestDesc_00, ITEM_POKE_BALL	, 1, gText_SideQuestHint_00, FLAG_ACHIEVEMENT_REWARD_01),
    side_quest(gText_SideQuestName_00, gText_SideQuestDesc_00, ITEM_POKE_BALL	, 1, gText_SideQuestHint_00, FLAG_ACHIEVEMENT_REWARD_01),
    side_quest(gText_SideQuestName_00, gText_SideQuestDesc_00, ITEM_POKE_BALL	, 1, gText_SideQuestHint_00, FLAG_ACHIEVEMENT_REWARD_01),
    side_quest(gText_SideQuestName_00, gText_SideQuestDesc_00, ITEM_POKE_BALL	, 1, gText_SideQuestHint_00, FLAG_ACHIEVEMENT_REWARD_01),//60
	side_quest(gText_SideQuestName_00, gText_SideQuestDesc_00, ITEM_POKE_BALL	, 1, gText_SideQuestHint_00, FLAG_ACHIEVEMENT_REWARD_01),
    side_quest(gText_SideQuestName_00, gText_SideQuestDesc_00, ITEM_POKE_BALL	, 1, gText_SideQuestHint_00, FLAG_ACHIEVEMENT_REWARD_01),
    side_quest(gText_SideQuestName_00, gText_SideQuestDesc_00, ITEM_POKE_BALL	, 1, gText_SideQuestHint_00, FLAG_ACHIEVEMENT_REWARD_01),
    side_quest(gText_SideQuestName_00, gText_SideQuestDesc_00, ITEM_POKE_BALL	, 1, gText_SideQuestHint_00, FLAG_ACHIEVEMENT_REWARD_01),
    side_quest(gText_SideQuestName_00, gText_SideQuestDesc_00, ITEM_POKE_BALL	, 1, gText_SideQuestHint_00, FLAG_ACHIEVEMENT_REWARD_01),
    side_quest(gText_SideQuestName_66, gText_SideQuestDesc_66, ITEM_TM65_SHADOW_CLAW, 1, gText_SideQuestHint_66, FLAG_ACHIEVEMENT_REWARD_66),
    side_quest(gText_SideQuestName_67, gText_SideQuestDesc_67, ITEM_METRONOME	, 6, gText_SideQuestHint_67, FLAG_ACHIEVEMENT_REWARD_67),
    side_quest(gText_SideQuestName_00, gText_SideQuestDesc_00, ITEM_POKE_BALL	, 1, gText_SideQuestHint_00, FLAG_ACHIEVEMENT_REWARD_01),
    side_quest(gText_SideQuestName_00, gText_SideQuestDesc_00, ITEM_POKE_BALL	, 1, gText_SideQuestHint_00, FLAG_ACHIEVEMENT_REWARD_01),
    side_quest(gText_SideQuestName_00, gText_SideQuestDesc_00, ITEM_POKE_BALL	, 1, gText_SideQuestHint_00, FLAG_ACHIEVEMENT_REWARD_01),//70
	side_quest(gText_SideQuestName_00, gText_SideQuestDesc_00, ITEM_POKE_BALL	, 1, gText_SideQuestHint_00, FLAG_ACHIEVEMENT_REWARD_01),
    side_quest(gText_SideQuestName_00, gText_SideQuestDesc_00, ITEM_POKE_BALL	, 1, gText_SideQuestHint_00, FLAG_ACHIEVEMENT_REWARD_01),
    side_quest(gText_SideQuestName_00, gText_SideQuestDesc_00, ITEM_POKE_BALL	, 1, gText_SideQuestHint_00, FLAG_ACHIEVEMENT_REWARD_01),
    side_quest(gText_SideQuestName_00, gText_SideQuestDesc_00, ITEM_POKE_BALL	, 1, gText_SideQuestHint_00, FLAG_ACHIEVEMENT_REWARD_01),
    side_quest(gText_SideQuestName_00, gText_SideQuestDesc_00, ITEM_POKE_BALL	, 1, gText_SideQuestHint_00, FLAG_ACHIEVEMENT_REWARD_01),
    side_quest(gText_SideQuestName_00, gText_SideQuestDesc_00, ITEM_POKE_BALL	, 1, gText_SideQuestHint_00, FLAG_ACHIEVEMENT_REWARD_01),
    side_quest(gText_SideQuestName_00, gText_SideQuestDesc_00, ITEM_POKE_BALL	, 1, gText_SideQuestHint_00, FLAG_ACHIEVEMENT_REWARD_01),
    side_quest(gText_SideQuestName_00, gText_SideQuestDesc_00, ITEM_POKE_BALL	, 1, gText_SideQuestHint_00, FLAG_ACHIEVEMENT_REWARD_01),
    side_quest(gText_SideQuestName_00, gText_SideQuestDesc_00, ITEM_POKE_BALL	, 1, gText_SideQuestHint_00, FLAG_ACHIEVEMENT_REWARD_01),
	side_quest(gText_SideQuestName_00, gText_SideQuestDesc_00, ITEM_POKE_BALL	, 1, gText_SideQuestHint_00, FLAG_ACHIEVEMENT_REWARD_01),//80
	side_quest(gText_SideQuestName_00, gText_SideQuestDesc_00, ITEM_POKE_BALL	, 1, gText_SideQuestHint_00, FLAG_ACHIEVEMENT_REWARD_01),
    side_quest(gText_SideQuestName_00, gText_SideQuestDesc_00, ITEM_POKE_BALL	, 1, gText_SideQuestHint_00, FLAG_ACHIEVEMENT_REWARD_01),
    side_quest(gText_SideQuestName_00, gText_SideQuestDesc_00, ITEM_POKE_BALL	, 1, gText_SideQuestHint_00, FLAG_ACHIEVEMENT_REWARD_01),
    side_quest(gText_SideQuestName_00, gText_SideQuestDesc_00, ITEM_POKE_BALL	, 1, gText_SideQuestHint_00, FLAG_ACHIEVEMENT_REWARD_01),
    side_quest(gText_SideQuestName_00, gText_SideQuestDesc_00, ITEM_POKE_BALL	, 1, gText_SideQuestHint_00, FLAG_ACHIEVEMENT_REWARD_01),
    side_quest(gText_SideQuestName_00, gText_SideQuestDesc_00, ITEM_POKE_BALL	, 1, gText_SideQuestHint_00, FLAG_ACHIEVEMENT_REWARD_01),
    side_quest(gText_SideQuestName_00, gText_SideQuestDesc_00, ITEM_POKE_BALL	, 1, gText_SideQuestHint_00, FLAG_ACHIEVEMENT_REWARD_01),
    side_quest(gText_SideQuestName_00, gText_SideQuestDesc_00, ITEM_POKE_BALL	, 1, gText_SideQuestHint_00, FLAG_ACHIEVEMENT_REWARD_01),
    side_quest(gText_SideQuestName_00, gText_SideQuestDesc_00, ITEM_POKE_BALL	, 1, gText_SideQuestHint_00, FLAG_ACHIEVEMENT_REWARD_01),
    side_quest(gText_SideQuestName_00, gText_SideQuestDesc_00, ITEM_POKE_BALL	, 1, gText_SideQuestHint_00, FLAG_ACHIEVEMENT_REWARD_01),//90
	side_quest(gText_SideQuestName_00, gText_SideQuestDesc_00, ITEM_POKE_BALL	, 1, gText_SideQuestHint_00, FLAG_ACHIEVEMENT_REWARD_01),
    side_quest(gText_SideQuestName_00, gText_SideQuestDesc_00, ITEM_POKE_BALL	, 1, gText_SideQuestHint_00, FLAG_ACHIEVEMENT_REWARD_01),
    side_quest(gText_SideQuestName_00, gText_SideQuestDesc_00, ITEM_POKE_BALL	, 1, gText_SideQuestHint_00, FLAG_ACHIEVEMENT_REWARD_01),
    side_quest(gText_SideQuestName_00, gText_SideQuestDesc_00, ITEM_POKE_BALL	, 1, gText_SideQuestHint_00, FLAG_ACHIEVEMENT_REWARD_01),
    side_quest(gText_SideQuestName_00, gText_SideQuestDesc_00, ITEM_POKE_BALL	, 1, gText_SideQuestHint_00, FLAG_ACHIEVEMENT_REWARD_01),
    side_quest(gText_SideQuestName_96, gText_SideQuestDesc_96, ITEM_GRISEOUS_ORB, 1, gText_SideQuestHint_96, FLAG_ACHIEVEMENT_REWARD_96),
    side_quest(gText_SideQuestName_97, gText_SideQuestDesc_97, ITEM_NUGGET		, 50, gText_SideQuestHint_97, FLAG_ACHIEVEMENT_REWARD_97),
    side_quest(gText_SideQuestName_98, gText_SideQuestDesc_98, ITEM_POKE_BALL	, 1, gText_SideQuestHint_98, FLAG_ACHIEVEMENT_REWARD_98),
    side_quest(gText_SideQuestName_99, gText_SideQuestDesc_99, ITEM_IRON_PLATE	, 1, gText_SideQuestHint_99, FLAG_ACHIEVEMENT_REWARD_99),
	side_quest(gText_SideQuestName_100, gText_SideQuestDesc_100, ITEM_MASTER_BALL, 1, gText_SideQuestHint_100, FLAG_ACHIEVEMENT_REWARD_100),//100
};

static const u16 sSideQuestDifficultyItemIds[] = 
{
	ITEM_POKE_BALL,
	ITEM_GREAT_BALL,
	ITEM_ULTRA_BALL,
	ITEM_MASTER_BALL,
};

static const u8 sSideQuestDifficulties[SIDE_QUEST_COUNT] = 
{
    [SIDE_QUEST_1] 	= QUEST_DIFFICULTY_EASY,
    [SIDE_QUEST_2] 	= QUEST_DIFFICULTY_EASY,
    [SIDE_QUEST_3] 	= QUEST_DIFFICULTY_EASY,
    [SIDE_QUEST_4] 	= QUEST_DIFFICULTY_MEDIUM,
    [SIDE_QUEST_5] 	= QUEST_DIFFICULTY_HARD,
    [SIDE_QUEST_6] 	= QUEST_DIFFICULTY_HARD,
    [SIDE_QUEST_7] 	= QUEST_DIFFICULTY_EASY,
    [SIDE_QUEST_8] 	= QUEST_DIFFICULTY_MEDIUM,
    [SIDE_QUEST_9] 	= QUEST_DIFFICULTY_MEDIUM,
    [SIDE_QUEST_10] = QUEST_DIFFICULTY_HARD,
    [SIDE_QUEST_11] = QUEST_DIFFICULTY_MEDIUM,
    [SIDE_QUEST_12] = QUEST_DIFFICULTY_EASY,
    [SIDE_QUEST_13] = QUEST_DIFFICULTY_MEDIUM,
    [SIDE_QUEST_14] = QUEST_DIFFICULTY_EXTREME,
    [SIDE_QUEST_15] = QUEST_DIFFICULTY_MEDIUM,
    [SIDE_QUEST_16] = QUEST_DIFFICULTY_HARD,
    [SIDE_QUEST_17] = QUEST_DIFFICULTY_MEDIUM,
    [SIDE_QUEST_18] = QUEST_DIFFICULTY_MEDIUM,
    [SIDE_QUEST_19] = QUEST_DIFFICULTY_MEDIUM,
    [SIDE_QUEST_20] = QUEST_DIFFICULTY_MEDIUM,
    [SIDE_QUEST_21] = QUEST_DIFFICULTY_MEDIUM,
    [SIDE_QUEST_22] = QUEST_DIFFICULTY_HARD,
    [SIDE_QUEST_23] = QUEST_DIFFICULTY_HARD,
    [SIDE_QUEST_24] = QUEST_DIFFICULTY_EASY,
    [SIDE_QUEST_25] = QUEST_DIFFICULTY_MEDIUM,
    [SIDE_QUEST_26] = QUEST_DIFFICULTY_MEDIUM,
    [SIDE_QUEST_27] = QUEST_DIFFICULTY_MEDIUM,
    [SIDE_QUEST_28] = QUEST_DIFFICULTY_EASY,
    [SIDE_QUEST_29] = QUEST_DIFFICULTY_EXTREME,
    [SIDE_QUEST_30] = QUEST_DIFFICULTY_MEDIUM,
	[SIDE_QUEST_31] = QUEST_DIFFICULTY_MEDIUM,
	[SIDE_QUEST_32] = QUEST_DIFFICULTY_MEDIUM,
	[SIDE_QUEST_33] = QUEST_DIFFICULTY_DISABLED,
	[SIDE_QUEST_34] = QUEST_DIFFICULTY_DISABLED,
	[SIDE_QUEST_35] = QUEST_DIFFICULTY_DISABLED,
	[SIDE_QUEST_36] = QUEST_DIFFICULTY_DISABLED,
	[SIDE_QUEST_37] = QUEST_DIFFICULTY_DISABLED,
	[SIDE_QUEST_38] = QUEST_DIFFICULTY_DISABLED,
	[SIDE_QUEST_39] = QUEST_DIFFICULTY_DISABLED,
	[SIDE_QUEST_40] = QUEST_DIFFICULTY_DISABLED,
	[SIDE_QUEST_41] = QUEST_DIFFICULTY_DISABLED,
	[SIDE_QUEST_42] = QUEST_DIFFICULTY_DISABLED,
	[SIDE_QUEST_43] = QUEST_DIFFICULTY_DISABLED,
	[SIDE_QUEST_44] = QUEST_DIFFICULTY_DISABLED,
	[SIDE_QUEST_45] = QUEST_DIFFICULTY_DISABLED,
	[SIDE_QUEST_46] = QUEST_DIFFICULTY_DISABLED,
	[SIDE_QUEST_47] = QUEST_DIFFICULTY_DISABLED,
	[SIDE_QUEST_48] = QUEST_DIFFICULTY_DISABLED,
	[SIDE_QUEST_49] = QUEST_DIFFICULTY_HARD,
	[SIDE_QUEST_50] = QUEST_DIFFICULTY_HARD,
	[SIDE_QUEST_51] = QUEST_DIFFICULTY_MEDIUM,
	[SIDE_QUEST_52] = QUEST_DIFFICULTY_HARD,
	[SIDE_QUEST_53] = QUEST_DIFFICULTY_EXTREME,
	[SIDE_QUEST_54] = QUEST_DIFFICULTY_MEDIUM,
	[SIDE_QUEST_55] = QUEST_DIFFICULTY_DISABLED,
	[SIDE_QUEST_56] = QUEST_DIFFICULTY_DISABLED,
	[SIDE_QUEST_57] = QUEST_DIFFICULTY_DISABLED,
	[SIDE_QUEST_58] = QUEST_DIFFICULTY_DISABLED,
	[SIDE_QUEST_59] = QUEST_DIFFICULTY_DISABLED,
	[SIDE_QUEST_60] = QUEST_DIFFICULTY_DISABLED,
	[SIDE_QUEST_61] = QUEST_DIFFICULTY_DISABLED,
	[SIDE_QUEST_62] = QUEST_DIFFICULTY_DISABLED,
	[SIDE_QUEST_63] = QUEST_DIFFICULTY_DISABLED,
	[SIDE_QUEST_64] = QUEST_DIFFICULTY_DISABLED,
	[SIDE_QUEST_65] = QUEST_DIFFICULTY_DISABLED,
	[SIDE_QUEST_66] = QUEST_DIFFICULTY_MEDIUM,
	[SIDE_QUEST_67] = QUEST_DIFFICULTY_HARD,
	[SIDE_QUEST_68] = QUEST_DIFFICULTY_DISABLED,
	[SIDE_QUEST_69] = QUEST_DIFFICULTY_DISABLED,
	[SIDE_QUEST_70] = QUEST_DIFFICULTY_DISABLED,
	[SIDE_QUEST_71] = QUEST_DIFFICULTY_DISABLED,
	[SIDE_QUEST_72] = QUEST_DIFFICULTY_DISABLED,
	[SIDE_QUEST_73] = QUEST_DIFFICULTY_DISABLED,
	[SIDE_QUEST_74] = QUEST_DIFFICULTY_DISABLED,
	[SIDE_QUEST_75] = QUEST_DIFFICULTY_DISABLED,
	[SIDE_QUEST_76] = QUEST_DIFFICULTY_DISABLED,
	[SIDE_QUEST_77] = QUEST_DIFFICULTY_DISABLED,
	[SIDE_QUEST_78] = QUEST_DIFFICULTY_DISABLED,
	[SIDE_QUEST_79] = QUEST_DIFFICULTY_DISABLED,
	[SIDE_QUEST_80] = QUEST_DIFFICULTY_DISABLED,
	[SIDE_QUEST_81] = QUEST_DIFFICULTY_DISABLED,
	[SIDE_QUEST_82] = QUEST_DIFFICULTY_DISABLED,
	[SIDE_QUEST_83] = QUEST_DIFFICULTY_DISABLED,
	[SIDE_QUEST_84] = QUEST_DIFFICULTY_DISABLED,
	[SIDE_QUEST_85] = QUEST_DIFFICULTY_DISABLED,
	[SIDE_QUEST_86] = QUEST_DIFFICULTY_DISABLED,
	[SIDE_QUEST_87] = QUEST_DIFFICULTY_DISABLED,
	[SIDE_QUEST_88] = QUEST_DIFFICULTY_DISABLED,
	[SIDE_QUEST_89] = QUEST_DIFFICULTY_DISABLED,
	[SIDE_QUEST_90] = QUEST_DIFFICULTY_DISABLED,
	[SIDE_QUEST_91] = QUEST_DIFFICULTY_DISABLED,
	[SIDE_QUEST_92] = QUEST_DIFFICULTY_DISABLED,
	[SIDE_QUEST_93] = QUEST_DIFFICULTY_DISABLED,
	[SIDE_QUEST_94] = QUEST_DIFFICULTY_DISABLED,
	[SIDE_QUEST_95] = QUEST_DIFFICULTY_DISABLED,
	[SIDE_QUEST_96] = QUEST_DIFFICULTY_EXTREME,
	[SIDE_QUEST_97] = QUEST_DIFFICULTY_DISABLED,
	[SIDE_QUEST_98] = QUEST_DIFFICULTY_DISABLED,
	[SIDE_QUEST_99] = QUEST_DIFFICULTY_DISABLED,
	[SIDE_QUEST_100] = QUEST_DIFFICULTY_DISABLED,
};

// Selected an incomplete quest
static const struct MenuAction sQuestSubmenuOptions[] =
{
    {sText_QuestMenu_Hint,           	{.void_u8 = Task_QuestMenuHint}},
	{sText_QuestMenu_Reward,            {.void_u8 = Task_QuestMenuRewardInfo}},
    {gText_Cancel,                      {.void_u8 = Task_QuestMenuCancel}},
};

// Selected the active quest
static const struct MenuAction sActiveQuestSubmenuOptions[] =
{
    {sText_QuestMenu_Progress,          {.void_u8 = Task_QuestMenuProgress}},
    {sText_QuestMenu_Reward,           	{.void_u8 = Task_QuestMenuRewardInfo}},
    {gText_Cancel,                      {.void_u8 = Task_QuestMenuCancel}},
};

// completed quest selection
static const struct MenuAction sCompletedQuestSubmenuOptions[] =
{
    {sText_QuestMenu_Get_Reward,        {.void_u8 = Task_QuestMenuGetReward}},
    {sText_QuestMenu_Reward,           	{.void_u8 = Task_QuestMenuRewardInfo}},
    {gText_Cancel,                      {.void_u8 = Task_QuestMenuCancel}},
};

static const struct BgTemplate sQuestMenuBgTemplates[2] =
{
    {
        .bg = 0,
        .charBaseIndex = 0,
        .mapBaseIndex = 31,
        .priority = 0
    }, 
    {
        .bg = 1,
        .charBaseIndex = 3,
        .mapBaseIndex = 30,
        .priority = 1
    }
};

static const u8 sQuestMenuWindowFontColors[][3] = 
{
    {TEXT_COLOR_TRANSPARENT,  TEXT_COLOR_WHITE,      TEXT_COLOR_DARK_GREY},
    {TEXT_COLOR_TRANSPARENT,  TEXT_COLOR_DARK_GREY,  TEXT_COLOR_LIGHT_GREY},
    {TEXT_COLOR_TRANSPARENT,  TEXT_COLOR_LIGHT_GREY, TEXT_COLOR_DARK_GREY},
    {TEXT_COLOR_TRANSPARENT,  TEXT_DYNAMIC_COLOR_1,  TEXT_COLOR_DARK_GREY}
};

static const struct WindowTemplate sQuestMenuHeaderWindowTemplates[] =
{
    {//Quest name
        .bg = 0,
        .tilemapLeft = 0x02,
        .tilemapTop = 0x01,
        .width = 0x14,
        .height = 0x0b,
        .paletteNum = 0x0f,
        .baseBlock = 0x02bf
    }, 
    {//Quest Description
        .bg = 0,
        .tilemapLeft = 0x05,
        .tilemapTop = 0x0e,
        .width = 0x19,
        .height = 0x06,
        .paletteNum = 0x0d,
        .baseBlock = 0x0229
    },//Disabled
    {
        .bg = 0,
        .tilemapLeft = 0x01,
        .tilemapTop = 0x02,
        .width = 0x00,
        .height = 0x00,
        .paletteNum = 15,
        .baseBlock = 0x0215
    }, 
    {
        .bg = 0,
        .tilemapLeft = 0x18,
        .tilemapTop = 0x0f,
        .width = 0x05,
        .height = 0x04,
        .paletteNum = 15,
        .baseBlock = 0x0201
    }, 
    {   // submenu cursor selection window
        .bg = 0,
        .tilemapLeft = 0x16,
        .tilemapTop = 0xD,  //+2 for 4 options
        .width = 0x07,
        .height = 0x06,     //+2 for 4 options
        .paletteNum = 15,
        .baseBlock = 0x01d7
    }, 
    {
        .bg = 0,
        .tilemapLeft = 0x02,
        .tilemapTop = 0x0f,
        .width = 0x1a,
        .height = 0x04,
        .paletteNum = 0x0b,
        .baseBlock = 0x016f
    }, 
    DUMMY_WIN_TEMPLATE
};

static const struct WindowTemplate sQuestMenuSubWindowTemplates[] =
{
    {
        .bg = 0,
        .tilemapLeft = 0x06,
        .tilemapTop = 0x0f,
        .width = 0x0e,
        .height = 0x04,
        .paletteNum = 12,
        .baseBlock = 0x0137
    }, 
    {
        .bg = 0,
        .tilemapLeft = 0x06,
        .tilemapTop = 0x0f,
        .width = 0x10,
        .height = 0x04,
        .paletteNum = 12,
        .baseBlock = 0x0137
    }, 
    {
        .bg = 0,
        .tilemapLeft = 0x06,
        .tilemapTop = 0x0f,
        .width = 0x17,
        .height = 0x04,
        .paletteNum = 12,
        .baseBlock = 0x009b
    }
};

// Functions -> ported from pokefirered
void QuestMenu_Init(u8 a0, MainCallback callback)
{
    u8 i;

    if (a0 >= 2)
    {
        SetMainCallback2(callback);
        return;
    }
    
    if ((sStateDataPtr = Alloc(sizeof(struct QuestMenuResources))) == NULL)
    {
        SetMainCallback2(callback);
        return;
    }
    
    if (a0 != 1)
    {
        sListMenuState.savedCallback = callback;
        sListMenuState.scroll = sListMenuState.row = 0;
    }
    
    sStateDataPtr->moveModeOrigPos = 0xFF;
    sStateDataPtr->itemMenuIconSlot = 0;
    sStateDataPtr->scrollIndicatorArrowPairId = 0xFF;
    sStateDataPtr->savedCallback = 0;
    for (i = 0; i < 3; i++)
    {
        sStateDataPtr->data[i] = 0;
    }
    
    SetMainCallback2(QuestMenu_RunSetup);
}

static void QuestMenu_MainCB(void)
{
    RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    DoScheduledBgTilemapCopiesToVram();
    UpdatePaletteFade();
}

static void QuestMenu_VBlankCB(void)
{
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
}

static void QuestMenu_RunSetup(void)
{
    while (1)
    {
        if (QuestMenu_DoGfxSetup() == TRUE)
            break;
    }
}

// from pc_screen_effect
static void BeginPCScreenEffect(TaskFunc task, u16 a1, u16 a2, u16 priority)
{
    u8 taskId = CreateTask(task, priority);
    gTasks[taskId].data[0] = 0;
    if (a1 == 0)
        gTasks[taskId].data[1] = 16;
    else
        gTasks[taskId].data[1] = 0;
    
    if (a1 == 0)
        gTasks[taskId].data[2] = 20;
    else
        gTasks[taskId].data[2] = 0;
    
    gTasks[taskId].func(taskId);
}

/// from pc_screen_effect
static void Task_PCScreenEffect_TurnOn(u8 taskId)
{
    struct Task *task = &gTasks[taskId];

    switch (task->tState)
    {
    case 0:
        task->tWin0Left = 120;
        task->tWin0Right = 120;
        task->tWin0Top = 80;
        task->tWin0Bottom = 81;
        SetGpuRegBits(REG_OFFSET_DISPCNT, DISPCNT_WIN0_ON);
        SetGpuReg(REG_OFFSET_WIN0H, WIN_RANGE(task->tWin0Left, task->tWin0Right));
        SetGpuReg(REG_OFFSET_WIN0V, WIN_RANGE(task->tWin0Top, task->tWin0Bottom));
        SetGpuReg(REG_OFFSET_WININ, WININ_WIN0_BG_ALL | WININ_WIN0_OBJ | WININ_WIN0_CLR);
        SetGpuReg(REG_OFFSET_WINOUT, 0);
        break;
    case 1:
        task->tBldCntBak = GetGpuReg(REG_OFFSET_BLDCNT);
        task->tBldYBak = GetGpuReg(REG_OFFSET_BLDY);
        SetGpuReg(REG_OFFSET_BLDCNT, BLDCNT_TGT1_BG0 | BLDCNT_TGT1_BG1 | BLDCNT_TGT1_BG2 | BLDCNT_TGT1_BG3 | BLDCNT_TGT1_OBJ | BLDCNT_TGT1_BD | BLDCNT_EFFECT_LIGHTEN);
        SetGpuReg(REG_OFFSET_BLDY, 16);
        break;
    case 2:
        task->tWin0Left -= task->tXSpeed;
        task->tWin0Right += task->tXSpeed;
        if (task->tWin0Left <= 0 || task->tWin0Right >= DISPLAY_WIDTH)
        {
            task->tWin0Left = 0;
            task->tWin0Right = DISPLAY_WIDTH;
            SetGpuReg(REG_OFFSET_BLDY, 0);
            SetGpuReg(REG_OFFSET_BLDCNT, task->tBldCntBak);
            BlendPalettes(0xFFFFFFFF, 0, RGB_BLACK);
            gPlttBufferFaded[0] = 0;
        }
        SetGpuReg(REG_OFFSET_WIN0H, WIN_RANGE(task->tWin0Left, task->tWin0Right));
        if (task->tWin0Left)
            return;
        break;
    case 3:
        task->tWin0Top -= task->tYSpeed;
        task->tWin0Bottom += task->tYSpeed;
        if (task->tWin0Top <= 0 || task->tWin0Bottom >= DISPLAY_HEIGHT)
        {
            task->tWin0Top = 0;
            task->tWin0Bottom = DISPLAY_HEIGHT;
            ClearGpuRegBits(REG_OFFSET_DISPCNT, DISPCNT_WIN0_ON);
        }
        SetGpuReg(REG_OFFSET_WIN0V, WIN_RANGE(task->tWin0Top, task->tWin0Bottom));
        if (task->tWin0Top)
            return;
        break;
    default:
        SetGpuReg(REG_OFFSET_BLDCNT, task->tBldCntBak);
        DestroyTask(taskId);
        return;
    }
    ++task->tState;
}

// from pc_screen_effect
static void BeginPCScreenEffect_TurnOn(u16 a0, u16 a1, u16 a2)
{
    BeginPCScreenEffect(Task_PCScreenEffect_TurnOn, a0, a1, a2);
}

static bool8 QuestMenu_DoGfxSetup(void)
{
    u8 taskId;
    switch (gMain.state)
    {
    case 0:
        SetVBlankHBlankCallbacksToNull();
        ClearScheduledBgCopiesToVram();
        gMain.state++;
        break;
    case 1:
        ScanlineEffect_Stop();
        gMain.state++;
        break;
    case 2:
        FreeAllSpritePalettes();
        gMain.state++;
        break;
    case 3:
        ResetPaletteFade();
        gMain.state++;
        break;
    case 4:
        ResetSpriteData();
        gMain.state++;
        break;
    case 5:
        ResetItemMenuIconState();
        gMain.state++;
        break;
    case 6:
        ResetTasks();
        gMain.state++;
        break;
    case 7:
        if (QuestMenu_InitBgs())
        {
            sStateDataPtr->data[0] = 0;
            gMain.state++;
        }
        else
        {
            QuestMenu_FadeAndBail();
            return TRUE;
        }
        break;
    case 8:
        if (QuestMenu_LoadGraphics() == TRUE)
            gMain.state++;
        break;
    case 9:
        QuestMenu_InitWindows();
        gMain.state++;
        break;
    case 10:
        QuestMenu_InitItems();
        QuestMenu_SetCursorPosition();
        QuestMenu_SetScrollPosition();
        gMain.state++;
        break;
    case 11:
        if (QuestMenu_AllocateResourcesForListMenu())
        {
            gMain.state++;
        }
        else
        {
            QuestMenu_FadeAndBail();
            return TRUE;
        }
        break;
    case 12:
        QuestMenu_BuildListMenuTemplate();
        gMain.state++;
        break;
    case 13:
        QuestMenu_PrintHeader();
        gMain.state++;
        break;
    case 14:
        //sub_80985E4();
        gMain.state++;
        break;
    case 15:
        taskId = CreateTask(Task_QuestMenuMain, 0);
        gTasks[taskId].data[0] = ListMenuInit(&gMultiuseListMenuTemplate, sListMenuState.scroll, sListMenuState.row);
        gMain.state++;
        break;
    case 16:
        QuestMenu_PlaceTopMenuScrollIndicatorArrows();
        gMain.state++;
        break;
    case 17:
        //HelpSystem_SetSomeVariable2(29);
        gMain.state++;
        break;
    case 18:
        if (sListMenuState.initialized == 1)
        {
            BlendPalettes(0xFFFFFFFF, 16, RGB_BLACK);
        }
        gMain.state++;
        break;
    case 19:
        if (sListMenuState.initialized == 1)
        {
            BeginNormalPaletteFade(0xFFFFFFFF, 0, 16, 0, RGB_BLACK);
        }
        else
        {
            BeginPCScreenEffect_TurnOn(0, 0, 0);
            QuestMenu_SetInitializedFlag(1);
            PlaySE(SE_PC_LOGIN);
        }
        gMain.state++;
        break;
    case 20:
        //if ((u8)sub_80BF72C() != TRUE)
            //gMain.state++;
        gMain.state++;
        break;
    default:
        SetVBlankCallback(QuestMenu_VBlankCB);
        SetMainCallback2(QuestMenu_MainCB);
        return TRUE;
    }
    return FALSE;
}

static void QuestMenu_FadeAndBail(void)
{
    BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 16, RGB_BLACK);
    CreateTask(Task_QuestMenuWaitFadeAndBail, 0);
    SetVBlankCallback(QuestMenu_VBlankCB);
    SetMainCallback2(QuestMenu_MainCB);
}

static void Task_QuestMenuWaitFadeAndBail(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        SetMainCallback2(sListMenuState.savedCallback);
        QuestMenu_FreeResources();
        DestroyTask(taskId);
    }
}

static bool8 QuestMenu_InitBgs(void)
{
    ResetAllBgsCoordinatesAndBgCntRegs();
    sBg1TilemapBuffer = Alloc(0x800);
    if (sBg1TilemapBuffer == NULL)
        return FALSE;
    
    memset(sBg1TilemapBuffer, 0, 0x800);
    ResetBgsAndClearDma3BusyFlags(0);
    InitBgsFromTemplates(0, sQuestMenuBgTemplates, NELEMS(sQuestMenuBgTemplates));
    SetBgTilemapBuffer(1, sBg1TilemapBuffer);
    ScheduleBgCopyTilemapToVram(1);
    SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_OBJ_1D_MAP | DISPCNT_OBJ_ON);
    SetGpuReg(REG_OFFSET_BLDCNT , 0);
    ShowBg(0);
    ShowBg(1);
    return TRUE;
}

static bool8 QuestMenu_LoadGraphics(void)
{
    switch (sStateDataPtr->data[0])
    {
    case 0:
        ResetTempTileDataBuffers();
        DecompressAndCopyTileDataToVram(1, sQuestMenuTiles, 0, 0, 0);
        sStateDataPtr->data[0]++;
        break;
    case 1:
        if (FreeTempTileDataBuffersIfPossible() != TRUE)
        {
            LZDecompressWram(sQuestMenuTilemap, sBg1TilemapBuffer);
            sStateDataPtr->data[0]++;
        }
        break;
    case 2:
        LoadCompressedPalette(sQuestMenuBgPals, 0x00, 0x60);
        sStateDataPtr->data[0]++;
        break;
    case 3:
        //LoadCompressedSpriteSheet(&gBagSwapSpriteSheet);
        sStateDataPtr->data[0]++;
        break;
    default:
        //LoadCompressedSpritePalette(&gBagSwapSpritePalette);
        sStateDataPtr->data[0] = 0;
        return TRUE;
    }
    return FALSE;
}

#define try_alloc(ptr__, size) ({ \
    void ** ptr = (void **)&(ptr__);             \
    *ptr = Alloc(size);                 \
    if (*ptr == NULL)                   \
    {                                   \
        QuestMenu_FreeResources();                  \
        QuestMenu_FadeAndBail();                  \
        return FALSE;                   \
    }                                   \
})

static bool8 QuestMenu_AllocateResourcesForListMenu(void)
{
    try_alloc(sListMenuItems, sizeof(struct ListMenuItem) * (SIDE_QUEST_COUNT + 1));
    //try_alloc(sUnusedStringAllocation, 14 * (PC_ITEMS_COUNT + 1));
    return TRUE;
}

static void QuestMenu_BuildListMenuTemplate(void)
{
    u16 i;
	const u8 * questName;
    for (i = 0; i < sStateDataPtr->nItems; i++)
    {
        if (GetSetQuestFlag(i, FLAG_GET_UNLOCKED) || GetSetQuestFlag(i, FLAG_GET_COMPLETED))
            sListMenuItems[i].name = sSideQuests[i].name;
        else
			sListMenuItems[i].name = sText_QuestMenu_Unk;
        sListMenuItems[i].id = i;
    }
    sListMenuItems[i].name = gText_Cancel;
    sListMenuItems[i].id = LIST_CANCEL;

    gMultiuseListMenuTemplate.items = sListMenuItems;
    gMultiuseListMenuTemplate.totalItems = sStateDataPtr->nItems + 1;
    gMultiuseListMenuTemplate.windowId = 0;
    gMultiuseListMenuTemplate.header_X = 0;
    gMultiuseListMenuTemplate.item_X = 12;
    gMultiuseListMenuTemplate.cursor_X = 1;
    gMultiuseListMenuTemplate.lettersSpacing = 1;
    gMultiuseListMenuTemplate.itemVerticalPadding = 2;
    gMultiuseListMenuTemplate.upText_Y = 2;
    gMultiuseListMenuTemplate.maxShowed = sStateDataPtr->maxShowed;
    gMultiuseListMenuTemplate.fontId = 0;
    gMultiuseListMenuTemplate.cursorPal = 2;
    gMultiuseListMenuTemplate.fillValue = 0;
    gMultiuseListMenuTemplate.cursorShadowPal = 3;
    gMultiuseListMenuTemplate.moveCursorFunc = QuestMenu_MoveCursorFunc;
	gMultiuseListMenuTemplate.itemPrintFunc = 0;
  //gMultiuseListMenuTemplate.itemPrintFunc = QuestMenu_ItemPrintFunc; tofix
    gMultiuseListMenuTemplate.scrollMultiple = 0;
    gMultiuseListMenuTemplate.cursorKind = 0;
}

void CreateItemMenuIcon(u16 itemId, u8 idx)
{
    u8 * ptr = &gUnknown_2039878[10];
    u8 spriteId;

    if (ptr[idx] == 0xFF)
    {
        FreeSpriteTilesByTag(102 + idx);
        FreeSpritePaletteByTag(102 + idx);
        spriteId = AddItemIconSprite(102 + idx, 102 + idx, itemId);
        if (spriteId != MAX_SPRITES)
        {
            ptr[idx] = spriteId;
            gSprites[spriteId].pos2.x = 24;
            gSprites[spriteId].pos2.y = 144;
        }
    }
}

void ResetItemMenuIconState(void)
{
    u16 i;

    for (i = 0; i < NELEMS(gUnknown_2039878); i++)
        gUnknown_2039878[i] = 0xFF;
}

void DestroyItemMenuIcon(u8 idx)
{
    u8 * ptr = &gUnknown_2039878[10];

    if (ptr[idx] != 0xFF)
    {
        DestroySpriteAndFreeResources(&gSprites[ptr[idx]]);
        ptr[idx] = 0xFF;
    }
}

static void QuestMenu_MoveCursorFunc(s32 itemIndex, bool8 onInit, struct ListMenu * list)
{
    u16 itemId;
    const u8 * desc;
	const u8 * difficulty;
	const u8 * status;
	u8 itemQty;
	u8 posX = 0;
	u8 posY = 3;
    
    if (onInit != TRUE)
        PlaySE(SE_SELECT);

    if (sStateDataPtr->moveModeOrigPos == 0xFF)
    {
        DestroyItemMenuIcon(sStateDataPtr->itemMenuIconSlot ^ 1);
        if (itemIndex != LIST_CANCEL)
        {
            if (GetSetQuestFlag(itemIndex, FLAG_GET_UNLOCKED) || GetSetQuestFlag(itemIndex, FLAG_GET_COMPLETED))
            {
				itemId = sSideQuests[itemIndex].reward;
				itemQty = sSideQuests[itemIndex].reward_qty;
                desc = sSideQuests[itemIndex].desc;
            }
            else
            {
                if(sSideQuestDifficulties[itemIndex] != QUEST_DIFFICULTY_DISABLED && sSideQuestDifficulties[itemIndex] != QUEST_DIFFICULTY_IMPOSSIBLE){
					itemId = sSideQuests[itemIndex].reward;
					itemQty = sSideQuests[itemIndex].reward_qty;
				}
				else{
					itemId = ITEM_NONE;	
					itemQty = 0;
				}
				desc = sText_QuestMenu_Unk;
                
                
            }
			
            CreateItemMenuIcon(itemId, sStateDataPtr->itemMenuIconSlot);
        }
        else
        {
            CreateItemMenuIcon(ITEM_NONE, sStateDataPtr->itemMenuIconSlot);
            desc = sText_QuestMenu_Exit;
        }
        
        sStateDataPtr->itemMenuIconSlot ^= 1;
        FillWindowPixelBuffer(1, 0);
		
		if (itemIndex != LIST_CANCEL)
        {
			switch(sSideQuestDifficulties[itemIndex]){
				case QUEST_DIFFICULTY_EASY:
					difficulty = sText_QuestMenu_Difficulty_Easy;
				break;
				case QUEST_DIFFICULTY_MEDIUM:
					difficulty = sText_QuestMenu_Difficulty_Medium;
				break;
				case QUEST_DIFFICULTY_HARD:
					difficulty = sText_QuestMenu_Difficulty_Hard;
				break;
				case QUEST_DIFFICULTY_EXTREME:
					difficulty = sText_QuestMenu_Difficulty_Extreme;
				break;
				case QUEST_DIFFICULTY_IMPOSSIBLE:
					difficulty = sText_QuestMenu_Difficulty_Impossible;
				break;
				case QUEST_DIFFICULTY_DISABLED:
					difficulty = sText_QuestMenu_Difficulty_Disabled;
				break;
			}
			
			QuestMenu_AddTextPrinterParameterized(1, 0, difficulty, posX, posY, 2, 0, 0, 3);
			
			posX = posX + 110;
			
			if(GetSetQuestFlag(itemIndex, FLAG_GET_COMPLETED)){
				if(FlagGet(sSideQuests[itemIndex].reward_flag))
					status = sText_QuestMenu_Completed;
				else
					status = sText_QuestMenu_GetYourReward;
			}
			else if (GetSetQuestFlag(itemIndex, FLAG_GET_UNLOCKED))
				status = sText_QuestMenu_Unlocked;
			else
				status = sText_QuestMenu_Locked;
			
			QuestMenu_AddTextPrinterParameterized(1, 0, status, posX, posY, 2, 0, 0, 3);
			
			posY = posY + 10;
			posX = 0;
		}
		
        QuestMenu_AddTextPrinterParameterized(1, 0, desc, posX, posY, 2, 0, 0, 3);
    }
}

static void QuestMenu_ItemPrintFunc(u8 windowId, u32 itemId, u8 y)
{
    if (sStateDataPtr->moveModeOrigPos != 0xFF)
    {
        if (sStateDataPtr->moveModeOrigPos == (u8)itemId)
            QuestMenu_PrintOrRemoveCursorAt(y, 2);
        else
            QuestMenu_PrintOrRemoveCursorAt(y, 0xFF);
    }
    if (itemId != LIST_CANCEL)
    {
        if (GetSetQuestFlag(itemId, FLAG_GET_COMPLETED))
            StringCopy(gStringVar4, sText_QuestMenu_Complete);
        else if (IsActiveQuest(itemId))
            StringCopy(gStringVar4, sText_QuestMenu_Unlocked);
        else
            StringCopy(gStringVar4, sText_Empty);
        
        QuestMenu_AddTextPrinterParameterized(windowId, 0, gStringVar4, 110, y, 0, 0, 0xFF, 1);
    }
}

static void QuestMenu_PrintOrRemoveCursor(u8 listMenuId, u8 colorIdx)
{
    QuestMenu_PrintOrRemoveCursorAt(ListMenuGetYCoordForPrintingArrowCursor(listMenuId), colorIdx);
}

static void QuestMenu_PrintOrRemoveCursorAt(u8 y, u8 colorIdx)
{
    if (colorIdx == 0xFF)
    {
        u8 maxWidth = GetFontAttribute(1, FONTATTR_MAX_LETTER_WIDTH);
        u8 maxHeight = GetFontAttribute(1, FONTATTR_MAX_LETTER_HEIGHT);
        FillWindowPixelRect(0, 0, 0, y, maxWidth, maxHeight);
    }
    else
    {
        QuestMenu_AddTextPrinterParameterized(0, 0, gText_SelectorArrow, 0, y, 0, 0, 0, colorIdx);
    }
}

static void QuestMenu_PrintHeader(void)
{
    QuestMenu_AddTextPrinterParameterized(2, 0, sText_Quests, 0, 1, 0, 1, 0, 0);
}

static void QuestMenu_PlaceTopMenuScrollIndicatorArrows(void)
{
    sStateDataPtr->scrollIndicatorArrowPairId = AddScrollIndicatorArrowPairParameterized(2, 128, 8, 104, sStateDataPtr->nItems - sStateDataPtr->maxShowed + 1, 110, 110, &sListMenuState.scroll);
}

static void QuestMenu_PlaceWithdrawQuantityScrollIndicatorArrows(void)
{
    sStateDataPtr->withdrawQuantitySubmenuCursorPos = 1;
    sStateDataPtr->scrollIndicatorArrowPairId = AddScrollIndicatorArrowPairParameterized(2, 212, 120, 152, 2, 110, 110, &sStateDataPtr->withdrawQuantitySubmenuCursorPos);
}

static void QuestMenu_RemoveScrollIndicatorArrowPair(void)
{
    if (sStateDataPtr->scrollIndicatorArrowPairId != 0xFF)
    {
        RemoveScrollIndicatorArrowPair(sStateDataPtr->scrollIndicatorArrowPairId);
        sStateDataPtr->scrollIndicatorArrowPairId = 0xFF;
    }
}

static void QuestMenu_SetCursorPosition(void)
{
    if (sListMenuState.scroll != 0 && sListMenuState.scroll + sStateDataPtr->maxShowed > sStateDataPtr->nItems + 1)
        sListMenuState.scroll = (sStateDataPtr->nItems + 1) - sStateDataPtr->maxShowed;
    if (sListMenuState.scroll + sListMenuState.row >= sStateDataPtr->nItems + 1)
    {
        if (sStateDataPtr->nItems + 1 < 2)
            sListMenuState.row = 0;
        else
            sListMenuState.row = sStateDataPtr->nItems;
    }
}

#define try_free(ptr) ({        \
    void ** ptr__ = (void **)&(ptr);   \
    if (*ptr__ != NULL)                \
        Free(*ptr__);                  \
})

static void QuestMenu_FreeResources(void)
{
    try_free(sStateDataPtr);
    try_free(sBg1TilemapBuffer);
    try_free(sListMenuItems);
    //try_free(sUnusedStringAllocation);
    FreeAllWindowBuffers();
}

// pc_screen_effect
static void Task_PCScreenEffect_TurnOff(u8 taskId)
{
    struct Task *task = &gTasks[taskId];

    switch (task->tState)
    {
    case 0:
        gPlttBufferFaded[0] = 0;
        break;
    case 1:
        task->tWin0Left = 0;
        task->tWin0Right = DISPLAY_WIDTH;
        task->tWin0Top = 0;
        task->tWin0Bottom = DISPLAY_HEIGHT;
        SetGpuRegBits(REG_OFFSET_DISPCNT, DISPCNT_WIN0_ON);
        SetGpuReg(REG_OFFSET_WIN0H, WIN_RANGE(task->tWin0Left, task->tWin0Right));
        SetGpuReg(REG_OFFSET_WIN0V, WIN_RANGE(task->tWin0Top, task->tWin0Bottom));
        SetGpuReg(REG_OFFSET_WININ, WININ_WIN0_BG_ALL | WININ_WIN0_OBJ | WININ_WIN0_CLR);
        SetGpuReg(REG_OFFSET_WINOUT, 0);
        break;
    case 2:
        task->tWin0Top += task->tYSpeed;
        task->tWin0Bottom -= task->tYSpeed;
        if (task->tWin0Top >= 80 || task->tWin0Bottom <= 81)
        {
            task->tWin0Top = 80;
            task->tWin0Bottom = 81;
            SetGpuReg(REG_OFFSET_BLDCNT, BLDCNT_TGT1_BG0 | BLDCNT_TGT1_BG1 | BLDCNT_TGT1_BG2 | BLDCNT_TGT1_BG3 | BLDCNT_TGT1_OBJ | BLDCNT_TGT1_BD | BLDCNT_EFFECT_LIGHTEN);
            SetGpuReg(REG_OFFSET_BLDY, 16);
        }
        SetGpuReg(REG_OFFSET_WIN0V, WIN_RANGE(task->tWin0Top, task->tWin0Bottom));
        if (task->tWin0Top != 80)
            return;
        break;
    case 3:
        task->tWin0Left += task->tXSpeed;
        task->tWin0Right -= task->tXSpeed;
        if (task->tWin0Left >= 120 || task->tWin0Right <= 120)
        {
            task->tWin0Left = 120;
            task->tWin0Right = 120;
            BlendPalettes(0xFFFFFFFF, 0x10, RGB_BLACK);
            gPlttBufferFaded[0] = 0;
        }
        SetGpuReg(REG_OFFSET_WIN0H, WIN_RANGE(task->tWin0Left, task->tWin0Right));
        if (task->tWin0Left != 120)
            return;
        break;
    default:
        ClearGpuRegBits(REG_OFFSET_DISPCNT, DISPCNT_WIN0_ON);
        SetGpuReg(REG_OFFSET_BLDY, 0);
        SetGpuReg(REG_OFFSET_BLDCNT, 0);
        DestroyTask(taskId);
        return;
    }
    ++task->tState;
}

// pc_screen_effect
static void BeginPCScreenEffect_TurnOff(u16 a0, u16 a1, u16 a2)
{
    BeginPCScreenEffect(Task_PCScreenEffect_TurnOff, a0, a1, a2);
}

static void Task_QuestMenuTurnOff1(u8 taskId)
{
    if (sListMenuState.initialized == 1)
    {
        BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 16, RGB_BLACK);
    }
    else
    {
        BeginPCScreenEffect_TurnOff(0, 0, 0);
        PlaySE(SE_PC_OFF);
    }
    
    gTasks[taskId].func = Task_QuestMenuTurnOff2;
}

// pc_screen_effect
static bool8 IsPCScreenEffectRunning_TurnOff(void)
{
    return FuncIsActiveTask(Task_PCScreenEffect_TurnOff);
}

static void Task_QuestMenuTurnOff2(u8 taskId)
{
    s16 * data = gTasks[taskId].data;

    if (!gPaletteFade.active && !IsPCScreenEffectRunning_TurnOff())
    {
        DestroyListMenuTask(data[0], &sListMenuState.scroll, &sListMenuState.row);
        if (sStateDataPtr->savedCallback != NULL)
            SetMainCallback2(sStateDataPtr->savedCallback);
        else
            SetMainCallback2(sListMenuState.savedCallback);
        
        QuestMenu_RemoveScrollIndicatorArrowPair();
        QuestMenu_FreeResources();
        DestroyTask(taskId);
    }
}

static u8 QuestMenu_GetCursorPosition(void)
{
    return sListMenuState.scroll + sListMenuState.row;
}


static void QuestMenu_InitItems(void)
{
    sStateDataPtr->nItems = SIDE_QUEST_COUNT;
    sStateDataPtr->maxShowed = sStateDataPtr->nItems + 1 <= 6 ? sStateDataPtr->nItems + 1 : 6;
    UnlockQuestMenu();
}

static void QuestMenu_SetScrollPosition(void)
{
    u8 i;

    if (sListMenuState.row > 3)
    {
        for (i = 0; i <= sListMenuState.row - 3; sListMenuState.row--, sListMenuState.scroll++, i++)
        {
            if (sListMenuState.scroll + sStateDataPtr->maxShowed == sStateDataPtr->nItems + 1)
                break;
        }
    }
}

static void QuestMenu_SetMessageWindowPalette(int a0)
{
    SetBgTilemapPalette(1, 0, 14, 30, 6, a0 + 1);
    //SetBgTilemapPalette(1, 0, 14, 30, 6, 15);
    ScheduleBgCopyTilemapToVram(1);
}

static void QuestMenu_SetInitializedFlag(u8 a0)
{
    sListMenuState.initialized = a0;
}

static bool8 IsPCScreenEffectRunning_TurnOn(void)
{
    return FuncIsActiveTask(Task_PCScreenEffect_TurnOn);
}

static void Task_QuestMenuMain(u8 taskId)
{
    s16 * data = gTasks[taskId].data;
    u16 scroll;
    u16 row;
    s32 input;

    if (!gPaletteFade.active && !IsPCScreenEffectRunning_TurnOn())
    {
        /*
        if (JOY_NEW(SELECT_BUTTON))
        {
            ListMenuGetScrollAndRow(data[0], &scroll, &row);
            if (scroll + row != sStateDataPtr->nItems)
            {
                PlaySE(SE_SELECT);
                QuestMenu_MoveItemModeInit(taskId, scroll + row);
                return;
            }
        }
        */
        input = ListMenu_ProcessInput(data[0]);
        ListMenuGetScrollAndRow(data[0], &sListMenuState.scroll, &sListMenuState.row);
        switch (input)
        {
        case LIST_NOTHING_CHOSEN:
            break;
            
        case LIST_CANCEL:
            PlaySE(SE_SELECT);
            QuestMenu_SetInitializedFlag(0);
            gTasks[taskId].func = Task_QuestMenuTurnOff1;
            break;
            
        default:
            if (GetSetQuestFlag(input, FLAG_GET_UNLOCKED))
            {
                PlaySE(SE_SELECT);
                QuestMenu_SetMessageWindowPalette(1);
                QuestMenu_RemoveScrollIndicatorArrowPair();
                data[1] = input;
                //data[2] = QuestMenu_GetItemQuantityBySlotId(input);
                data[2] = 0;
                QuestMenu_PrintOrRemoveCursor(data[0], 2);            
                gTasks[taskId].func = Task_QuestMenuSubmenuInit;
            }
            else
            {
                PlaySE(SE_SELECT);
                QuestMenu_SetMessageWindowPalette(1);
                QuestMenu_RemoveScrollIndicatorArrowPair();
                data[1] = input;
                //data[2] = QuestMenu_GetItemQuantityBySlotId(input);
                data[2] = 0;
                QuestMenu_PrintOrRemoveCursor(data[0], 2);            
                gTasks[taskId].func = Task_QuestMenuSubmenuInit;
				//PlaySE(SE_FAILURE);
            }
            break;
        }
    }
}

static void QuestMenu_ReturnFromSubmenu(u8 taskId)
{
    QuestMenu_SetMessageWindowPalette(0);
    QuestMenu_PlaceTopMenuScrollIndicatorArrows();
    gTasks[taskId].func = Task_QuestMenuMain;
}

// pokefirered item_menu_icon
static void sub_8098660(u8 flag)
{
    u8 i;
    u8 * ptr = &gUnknown_2039878[1];

    for (i = 0; i < 9; i++)
    {
        gSprites[ptr[i]].invisible = flag;
    }
}

// pokefirered item_menu_icon
static void sub_80986A8(s16 x, u16 y)
{
    u8 i;
    u8 * ptr = &gUnknown_2039878[1];

    for (i = 0; i < 9; i++)
    {
        gSprites[ptr[i]].pos2.x = x;
        gSprites[ptr[i]].pos1.y = y + 7;
    }
}



static void Task_QuestMenuSubmenuInit(u8 taskId)
{
    s16 * data = gTasks[taskId].data;
    u8 windowId;

    QuestMenu_SetBorderStyleOnWindow(4);    //for sub menu list items
    windowId = QuestMenu_GetOrCreateSubwindow(0);
    
    if (GetSetQuestFlag(data[1], FLAG_GET_COMPLETED))
    {
        // completed
        PrintTextArray(4, 2, 8, 2, GetFontAttribute(2, FONTATTR_MAX_LETTER_HEIGHT) + 2, NELEMS(sCompletedQuestSubmenuOptions), sCompletedQuestSubmenuOptions);
        Menu_InitCursor(4, 2, 0, 2, GetFontAttribute(2, FONTATTR_MAX_LETTER_HEIGHT) + 2, NELEMS(sCompletedQuestSubmenuOptions), 0);

    }
    else if (GetSetQuestFlag(data[1], FLAG_GET_UNLOCKED))
    {
        // active
        PrintTextArray(4, 2, 8, 2, GetFontAttribute(2, FONTATTR_MAX_LETTER_HEIGHT) + 2, NELEMS(sActiveQuestSubmenuOptions), sActiveQuestSubmenuOptions);
        Menu_InitCursor(4, 2, 0, 2, GetFontAttribute(2, FONTATTR_MAX_LETTER_HEIGHT) + 2, NELEMS(sActiveQuestSubmenuOptions), 0);
    }
    else
    {
        // unlocked
        PrintTextArray(4, 2, 8, 2, GetFontAttribute(2, FONTATTR_MAX_LETTER_HEIGHT) + 2, NELEMS(sQuestSubmenuOptions), sQuestSubmenuOptions);
        Menu_InitCursor(4, 2, 0, 2, GetFontAttribute(2, FONTATTR_MAX_LETTER_HEIGHT) + 2, NELEMS(sQuestSubmenuOptions), 0);
    }    
    //CopyItemName(QuestMenu_GetItemIdBySlotId(data[1]), gStringVar1);
    //StringExpandPlaceholders(gStringVar4, gText_StrVar1);
    
    StringCopy(gStringVar4, sText_QuestMenu_SelectedQuest);
    //StringExpandPlaceholders(gStringVar4, sText_QuestMenu_SelectedQuest);
    
    QuestMenu_AddTextPrinterParameterized(windowId, 0, gStringVar4, 0, 2, 1, 0, 0, 1);
    ScheduleBgCopyTilemapToVram(0);
    gTasks[taskId].func = Task_QuestMenuSubmenuRun;
}

static void Task_QuestMenuSubmenuRun(u8 taskId)
{
    u8 questIndex = QuestMenu_GetCursorPosition();
    s8 input = Menu_ProcessInputNoWrapAround_other();
    
    switch (input)
    {
    case LIST_NOTHING_CHOSEN:
        PlaySE(SE_SELECT);
        Task_QuestMenuCancel(taskId);
        break;
    case LIST_CANCEL:
        break;
    default:
        PlaySE(SE_SELECT);
        if (GetSetQuestFlag(questIndex, FLAG_GET_COMPLETED))
            sCompletedQuestSubmenuOptions[input].func.void_u8(taskId);
        else if (GetSetQuestFlag(questIndex, FLAG_GET_UNLOCKED))
            sActiveQuestSubmenuOptions[input].func.void_u8(taskId);
        else       
            sQuestSubmenuOptions[input].func.void_u8(taskId);
    }
}

static void QuestMenuSubmenuSelectionMessage(u8 taskId)
{
    s16 * data = gTasks[taskId].data;

    ClearStdWindowAndFrameToTransparent(4, FALSE);
    QuestMenu_DestroySubwindow(0);
    ClearWindowTilemap(4);
    data[8] = 1;
    PutWindowTilemap(0);
    ScheduleBgCopyTilemapToVram(0);
}

static void Task_QuestMenuHint(u8 taskId)
{
    u8 questIndex = QuestMenu_GetCursorPosition();
	QuestMenuSubmenuSelectionMessage(taskId);
    StringCopy(gStringVar1, sSideQuests[questIndex].hint);
    StringExpandPlaceholders(gStringVar4, sText_QuestMenu_DisplayDetails);
    QuestMenu_DisplaySubMenuMessage(taskId);
}

static void Task_QuestMenuRewardInfo(u8 taskId)
{
    u8 questIndex = QuestMenu_GetCursorPosition();
	u16 reward = sSideQuests[questIndex].reward;
	u8 reward_quantity = sSideQuests[questIndex].reward_qty;
    
    QuestMenuSubmenuSelectionMessage(taskId);
	CopyItemName(reward, gStringVar1);
    ConvertIntToDecimalStringN(gStringVar2, reward_quantity, STR_CONV_MODE_LEFT_ALIGN, 5);
	
	if(sSideQuestDifficulties[questIndex] != QUEST_DIFFICULTY_DISABLED)
		StringExpandPlaceholders(gStringVar4, sText_QuestMenu_DisplayReward);
	else
		StringExpandPlaceholders(gStringVar4, sText_QuestMenu_DisplayRewardDisabled);
    QuestMenu_DisplaySubMenuMessage(taskId);
}

static void Task_QuestMenuGetReward(u8 taskId)
{
    u8 questIndex = QuestMenu_GetCursorPosition();
	u16 reward = sSideQuests[questIndex].reward;
	u8 reward_quantity = sSideQuests[questIndex].reward_qty;
	QuestMenuSubmenuSelectionMessage(taskId);
    if(!FlagGet(sSideQuests[questIndex].reward_flag)){
		
		CopyItemName(reward, gStringVar1);
		ConvertIntToDecimalStringN(gStringVar2, reward_quantity, STR_CONV_MODE_LEFT_ALIGN, 5);
		//StringCopy(gStringVar3, sSideQuests[questIndex].name);
		StringExpandPlaceholders(gStringVar4, sText_QuestMenu_GotReward);
		AddBagItem(reward, reward_quantity);
		PlaySE(MUS_LEVEL_UP);
		FlagSet(sSideQuests[questIndex].reward_flag);
	}
	else{
		StringExpandPlaceholders(gStringVar4, sText_QuestMenu_YouAlreadyHaveReward);
		PlaySE(SE_FAILURE);
	}
    QuestMenu_DisplaySubMenuMessage(taskId);
}

static void Task_QuestMenuEndQuest(u8 taskId)
{
    u8 questIndex = QuestMenu_GetCursorPosition();
    
    ResetActiveQuest();
    QuestMenuSubmenuSelectionMessage(taskId);
    StringCopy(gStringVar1, sSideQuests[questIndex].name);
    StringExpandPlaceholders(gStringVar4, sText_QuestMenu_EndQuest);
    QuestMenu_DisplaySubMenuMessage(taskId);
}

static void Task_QuestMenuBeginQuest(u8 taskId)
{
    u8 questIndex = QuestMenu_GetCursorPosition();
    
    SetActiveQuest(questIndex);
    QuestMenuSubmenuSelectionMessage(taskId);
    StringCopy(gStringVar1, sSideQuests[questIndex].name);
    StringExpandPlaceholders(gStringVar4, sText_QuestMenu_BeginQuest);
    QuestMenu_DisplaySubMenuMessage(taskId);
}

static void QuestMenu_DisplaySubMenuMessage(u8 taskId)
{
    s16 * data = gTasks[taskId].data;
    u8 windowId;
    
    windowId = QuestMenu_GetOrCreateSubwindow(2);
    AddTextPrinterParameterized(windowId, 2, gStringVar4, 0, 2, 0, NULL);
    gTasks[taskId].func = Task_QuestMenuRefreshAfterAcknowledgement;
}

static void Task_QuestMenuRefreshAfterAcknowledgement(u8 taskId)
{
    if (JOY_NEW(A_BUTTON) || JOY_NEW(B_BUTTON))
    {
        PlaySE(SE_SELECT);
        Task_QuestMenuCleanUp(taskId);
    }
}

static void Task_QuestMenuCleanUp(u8 taskId)
{
    s16 * data = gTasks[taskId].data;

    QuestMenu_DestroySubwindow(2);
    PutWindowTilemap(1);
    DestroyListMenuTask(data[0], &sListMenuState.scroll, &sListMenuState.row);
    
    QuestMenu_InitItems();
    
    QuestMenu_SetCursorPosition();
    QuestMenu_BuildListMenuTemplate();
    data[0] = ListMenuInit(&gMultiuseListMenuTemplate, sListMenuState.scroll, sListMenuState.row);
    ScheduleBgCopyTilemapToVram(0);
    QuestMenu_ReturnFromSubmenu(taskId);
}

static void Task_QuestMenuCancel(u8 taskId)
{
    s16 * data = gTasks[taskId].data;

    ClearStdWindowAndFrameToTransparent(4, FALSE);
    QuestMenu_DestroySubwindow(0);
    ClearWindowTilemap(4);
    PutWindowTilemap(0);
    PutWindowTilemap(1);
    QuestMenu_PrintOrRemoveCursor(data[0], 1);
    ScheduleBgCopyTilemapToVram(0);
    QuestMenu_ReturnFromSubmenu(taskId);
}

// pokefirered text_window.c
void TextWindow_SetStdFrame0_WithPal(u8 windowId, u16 destOffset, u8 palIdx)
{
    LoadBgTiles(GetWindowAttribute(windowId, WINDOW_BG), sFR_StdFrame0, 0x120, destOffset);
    LoadPalette(GetTextWindowPalette(3), palIdx, 32);
}
void TextWindow_LoadResourcesStdFrame0(u8 windowId, u16 destOffset, u8 palIdx)
{
    LoadBgTiles(GetWindowAttribute(windowId, WINDOW_BG), sFR_MessageBoxTiles, 0x280, destOffset);
    LoadPalette(GetTextWindowPalette(0), palIdx, 32);
}

static void QuestMenu_InitWindows(void)
{
    u8 i;

    InitWindows(sQuestMenuHeaderWindowTemplates);
    DeactivateAllTextPrinters();
    LoadUserWindowBorderGfx(0, 0x3C0, 0xE0);
    
    TextWindow_SetStdFrame0_WithPal(0, 0x3A3, 0xC0); 
    TextWindow_LoadResourcesStdFrame0(0, 0x3AC, 0xB0);
    //LoadMessageBoxGfx(0, 0x3A3, 0xC0);
    //LoadMessageBoxGfx(0, 0x3AC, 0xB0);
    
    LoadPalette(GetTextWindowPalette(2), 0xD0, 0x20);
    LoadPalette(sMainWindowPal, 0xF0, 0x20);
    for (i = 0; i < 3; i++)
    {
        FillWindowPixelBuffer(i, 0x00);
        PutWindowTilemap(i);
    }
    
    ScheduleBgCopyTilemapToVram(0);
    for (i = 0; i < 3; i++)
        sSubmenuWindowIds[i] = 0xFF;
}

static void QuestMenu_AddTextPrinterParameterized(u8 windowId, u8 fontId, const u8 * str, u8 x, u8 y, u8 letterSpacing, u8 lineSpacing, u8 speed, u8 colorIdx)
{
    AddTextPrinterParameterized4(windowId, fontId, x, y, letterSpacing, lineSpacing, sQuestMenuWindowFontColors[colorIdx], speed, str);
}

static void QuestMenu_SetBorderStyleOnWindow(u8 windowId)
{
    DrawStdFrameWithCustomTileAndPalette(windowId, FALSE, 0x3C0, 14);
}

static u8 QuestMenu_GetOrCreateSubwindow(u8 idx)
{
    if (sSubmenuWindowIds[idx] == 0xFF)
    {
        sSubmenuWindowIds[idx] = AddWindow(&sQuestMenuSubWindowTemplates[idx]);
        DrawStdFrameWithCustomTileAndPalette(sSubmenuWindowIds[idx], TRUE, 0x3A3, 0x0C);
    }

    return sSubmenuWindowIds[idx];
}

static void QuestMenu_DestroySubwindow(u8 idx)
{
    ClearStdWindowAndFrameToTransparent(sSubmenuWindowIds[idx], FALSE);
    ClearWindowTilemap(sSubmenuWindowIds[idx]); // redundant
    RemoveWindow(sSubmenuWindowIds[idx]);
    sSubmenuWindowIds[idx] = 0xFF;
}

// Start Menu Function
void Task_OpenQuestMenuFromStartMenu(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    if (!gPaletteFade.active)
    {
        CleanupOverworldWindowsAndTilemaps();
        QuestMenu_Init(tItemPcParam, CB2_ReturnToUIMenu);
        DestroyTask(taskId);
    }
}

s8 GetSetQuestFlag(u8 quest, u8 caseId)
{
    u8 index;
    u8 bit;
    u8 mask;
    
    index = quest / 8; //8 bits per byte
    bit = quest % 8;
    mask = 1 << bit;
    
    switch (caseId)
    {
    case FLAG_GET_UNLOCKED:
        return gSaveBlock2Ptr->unlockedQuests[index] & mask;
    case FLAG_SET_UNLOCKED:
        gSaveBlock2Ptr->unlockedQuests[index] |= mask;
        return 1;
    case FLAG_GET_COMPLETED:
        return gSaveBlock2Ptr->completedQuests[index] & mask;
    case FLAG_SET_COMPLETED:
        gSaveBlock2Ptr->completedQuests[index] |= mask;
        return 1;
    }
    
    return -1;  //failure
}

s8 GetActiveQuestIndex(void)
{
    return NO_ACTIVE_QUEST;
}

static bool8 IsActiveQuest(u8 questId)
{
    if ((u8)GetActiveQuestIndex() == questId)
        return TRUE;
    
    return FALSE;
}

void SetActiveQuest(u8 questId)
{
    //gSaveBlock2Ptr->activeQuest = questId + 1;  // 1-indexed
}

void ResetActiveQuest(void)
{
    //gSaveBlock2Ptr->activeQuest = 0;
}

void ResetQuestFlags(void)
{
    if(!FlagGet(FLAG_ACHIEVEMENT_DATA_CREATED)){
		memset(&gSaveBlock2Ptr->unlockedQuests, 0, sizeof(gSaveBlock2Ptr->unlockedQuests));
		memset(&gSaveBlock2Ptr->completedQuests, 0, sizeof(gSaveBlock2Ptr->completedQuests));
		//gSaveBlock2Ptr->activeQuest = 0;
		SetGameStat(GAME_STAT_MAXED_FRIENDSHIP		, 0);
		SetGameStat(GAME_STAT_CAUGHT_SHINIES		, 0);
		SetGameStat(GAME_STAT_DEFEATED_WILD_SHINIES	, 0);
		SetGameStat(GAME_STAT_GAME_UPDATED			, 0);
		SetGameStat(GAME_STAT_WONDER_TRADED			, 0);
		FlagSet(FLAG_ACHIEVEMENT_DATA_CREATED);
	}
}

static void UnlockQuestMenu(void)
{
	u8 i = 0;
	u8 friendshipCount = 0;
	u8 tmCount = 0;
	u8 shinyCount = 0;
	
	if(!CheckBagHasItem(ITEM_TM65_SHADOW_CLAW, 1))
		FlagClear(FLAG_ACHIEVEMENT_REWARD_66);
	
	if(!CheckBagHasItem(ITEM_TM119_DRAIN_PUNCH, 1))
		FlagClear(FLAG_ACHIEVEMENT_REWARD_27);
	
	//Achievement 1----------------------------------------------------------
    //Achievement 1 is always unlocked
	GetSetQuestFlag(SIDE_QUEST_1, FLAG_SET_UNLOCKED);
	
	if(FlagGet(FLAG_RECEIVED_BADGE_01))
		GetSetQuestFlag(SIDE_QUEST_1, FLAG_SET_COMPLETED);
    //Achievement 2----------------------------------------------------------
	if(FlagGet(FLAG_RECEIVED_BADGE_01))
		GetSetQuestFlag(SIDE_QUEST_2, FLAG_SET_UNLOCKED);
	
	if(FlagGet(FLAG_RECEIVED_BADGE_04))
		GetSetQuestFlag(SIDE_QUEST_2, FLAG_SET_COMPLETED);
	//Achievement 3----------------------------------------------------------
	if(FlagGet(FLAG_RECEIVED_BADGE_04))
		GetSetQuestFlag(SIDE_QUEST_3, FLAG_SET_UNLOCKED);
	
	if(FlagGet(FLAG_RECEIVED_BADGE_08))
		GetSetQuestFlag(SIDE_QUEST_3, FLAG_SET_COMPLETED);
	//Achievement 4----------------------------------------------------------
	if(FlagGet(FLAG_RECEIVED_BADGE_08))
		GetSetQuestFlag(SIDE_QUEST_4, FLAG_SET_UNLOCKED);
	
	if(FlagGet(FLAG_DEFEATED_WALLY_VICTORY_ROAD))
		GetSetQuestFlag(SIDE_QUEST_4, FLAG_SET_COMPLETED);
	//Achievement 5----------------------------------------------------------
	if(FlagGet(FLAG_DEFEATED_WALLY_VICTORY_ROAD))
		GetSetQuestFlag(SIDE_QUEST_5, FLAG_SET_UNLOCKED);
	
	if(FlagGet(FLAG_SYS_GAME_CLEAR))
		GetSetQuestFlag(SIDE_QUEST_5, FLAG_SET_COMPLETED);
	//Achievement 6----------------------------------------------------------
	//Unlocked after you defeat Groudon and Kyogre
	//Completed after you defeat Rayquaza
	if(FlagGet(FLAG_DEFEATED_KYOGRE) && FlagGet(FLAG_DEFEATED_GROUDON))
		GetSetQuestFlag(SIDE_QUEST_6, FLAG_SET_UNLOCKED);
	
	if(FlagGet(FLAG_DEFEATED_RAYQUAZA))
		GetSetQuestFlag(SIDE_QUEST_6, FLAG_SET_COMPLETED);
	
	//Achievement 7----------------------------------------------------------
	//Unlocked after you trade with an NPC once
	//Completed after you trade with all the NPC
	if( FlagGet(FLAG_RUSTBORO_NPC_TRADE_COMPLETED) 	|| 
		FlagGet(FLAG_PACIFIDLOG_NPC_TRADE_COMPLETED)||
		FlagGet(FLAG_FORTREE_NPC_TRADE_COMPLETED)	||
		FlagGet(FLAG_BATTLE_FRONTIER_TRADE_DONE))
		GetSetQuestFlag(SIDE_QUEST_7, FLAG_SET_UNLOCKED);
	
	if( FlagGet(FLAG_RUSTBORO_NPC_TRADE_COMPLETED) 	&&
		FlagGet(FLAG_PACIFIDLOG_NPC_TRADE_COMPLETED)&&
		FlagGet(FLAG_FORTREE_NPC_TRADE_COMPLETED)	&&
		FlagGet(FLAG_BATTLE_FRONTIER_TRADE_DONE))
		GetSetQuestFlag(SIDE_QUEST_7, FLAG_SET_COMPLETED);
	
	//Achievement 8
	//Unlocked after you have 1 fossil marked as caught
	//Completed after you have all the fossils marked as caught
	if(	GetSetPokedexFlag(SpeciesToNationalPokedexNum(SPECIES_OMANYTE), 	FLAG_GET_CAUGHT)	||
		GetSetPokedexFlag(SpeciesToNationalPokedexNum(SPECIES_OMASTAR), 	FLAG_GET_CAUGHT)	||
		GetSetPokedexFlag(SpeciesToNationalPokedexNum(SPECIES_KABUTO), 		FLAG_GET_CAUGHT)	||
		GetSetPokedexFlag(SpeciesToNationalPokedexNum(SPECIES_KABUTOPS), 	FLAG_GET_CAUGHT)	||
		GetSetPokedexFlag(SpeciesToNationalPokedexNum(SPECIES_AERODACTYL), 	FLAG_GET_CAUGHT)	||
		GetSetPokedexFlag(SpeciesToNationalPokedexNum(SPECIES_LILEEP), 		FLAG_GET_CAUGHT)	||
		GetSetPokedexFlag(SpeciesToNationalPokedexNum(SPECIES_ANORITH), 	FLAG_GET_CAUGHT)	||
		GetSetPokedexFlag(SpeciesToNationalPokedexNum(SPECIES_ARMALDO), 	FLAG_GET_CAUGHT)	||
		GetSetPokedexFlag(SpeciesToNationalPokedexNum(SPECIES_CRANIDOS), 	FLAG_GET_CAUGHT)	||
		GetSetPokedexFlag(SpeciesToNationalPokedexNum(SPECIES_RAMPARDOS), 	FLAG_GET_CAUGHT)	||
		GetSetPokedexFlag(SpeciesToNationalPokedexNum(SPECIES_SHIELDON), 	FLAG_GET_CAUGHT)	||
		GetSetPokedexFlag(SpeciesToNationalPokedexNum(SPECIES_BASTIODON), 	FLAG_GET_CAUGHT)	||
		GetSetPokedexFlag(SpeciesToNationalPokedexNum(SPECIES_TIRTOUGA), 	FLAG_GET_CAUGHT)	||
		GetSetPokedexFlag(SpeciesToNationalPokedexNum(SPECIES_CARRACOSTA), 	FLAG_GET_CAUGHT)	||
		GetSetPokedexFlag(SpeciesToNationalPokedexNum(SPECIES_ARCHEN), 		FLAG_GET_CAUGHT)	||
		GetSetPokedexFlag(SpeciesToNationalPokedexNum(SPECIES_ARCHEOPS), 	FLAG_GET_CAUGHT)	||
		GetSetPokedexFlag(SpeciesToNationalPokedexNum(SPECIES_TYRUNT), 		FLAG_GET_CAUGHT)	||
		GetSetPokedexFlag(SpeciesToNationalPokedexNum(SPECIES_TYRANTRUM), 	FLAG_GET_CAUGHT)	||
		GetSetPokedexFlag(SpeciesToNationalPokedexNum(SPECIES_AMAURA), 		FLAG_GET_CAUGHT)	||
		GetSetPokedexFlag(SpeciesToNationalPokedexNum(SPECIES_AURORUS), 	FLAG_GET_CAUGHT)	||
		GetSetPokedexFlag(SpeciesToNationalPokedexNum(SPECIES_DRACOZOLT), 	FLAG_GET_CAUGHT)	||
		GetSetPokedexFlag(SpeciesToNationalPokedexNum(SPECIES_ARCTOZOLT), 	FLAG_GET_CAUGHT)	||
		GetSetPokedexFlag(SpeciesToNationalPokedexNum(SPECIES_DRACOVISH), 	FLAG_GET_CAUGHT)	||
		GetSetPokedexFlag(SpeciesToNationalPokedexNum(SPECIES_ARCTOVISH), 	FLAG_GET_CAUGHT)	||
		GetSetPokedexFlag(SpeciesToNationalPokedexNum(SPECIES_RELICANTH), 	FLAG_GET_CAUGHT))
			GetSetQuestFlag(SIDE_QUEST_8, FLAG_SET_UNLOCKED);
			
	if(	GetSetPokedexFlag(SpeciesToNationalPokedexNum(SPECIES_OMANYTE), 	FLAG_GET_CAUGHT)	&&
		GetSetPokedexFlag(SpeciesToNationalPokedexNum(SPECIES_OMASTAR), 	FLAG_GET_CAUGHT)	&&
		GetSetPokedexFlag(SpeciesToNationalPokedexNum(SPECIES_KABUTO), 		FLAG_GET_CAUGHT)	&&
		GetSetPokedexFlag(SpeciesToNationalPokedexNum(SPECIES_KABUTOPS), 	FLAG_GET_CAUGHT)	&&
		GetSetPokedexFlag(SpeciesToNationalPokedexNum(SPECIES_AERODACTYL), 	FLAG_GET_CAUGHT)	&&
		GetSetPokedexFlag(SpeciesToNationalPokedexNum(SPECIES_LILEEP), 		FLAG_GET_CAUGHT)	&&
		GetSetPokedexFlag(SpeciesToNationalPokedexNum(SPECIES_ANORITH), 	FLAG_GET_CAUGHT)	&&
		GetSetPokedexFlag(SpeciesToNationalPokedexNum(SPECIES_ARMALDO), 	FLAG_GET_CAUGHT)	&&
		GetSetPokedexFlag(SpeciesToNationalPokedexNum(SPECIES_CRANIDOS), 	FLAG_GET_CAUGHT)	&&
		GetSetPokedexFlag(SpeciesToNationalPokedexNum(SPECIES_RAMPARDOS), 	FLAG_GET_CAUGHT)	&&
		GetSetPokedexFlag(SpeciesToNationalPokedexNum(SPECIES_SHIELDON), 	FLAG_GET_CAUGHT)	&&
		GetSetPokedexFlag(SpeciesToNationalPokedexNum(SPECIES_BASTIODON), 	FLAG_GET_CAUGHT)	&&
		GetSetPokedexFlag(SpeciesToNationalPokedexNum(SPECIES_TIRTOUGA), 	FLAG_GET_CAUGHT)	&&
		GetSetPokedexFlag(SpeciesToNationalPokedexNum(SPECIES_CARRACOSTA), 	FLAG_GET_CAUGHT)	&&
		GetSetPokedexFlag(SpeciesToNationalPokedexNum(SPECIES_ARCHEN), 		FLAG_GET_CAUGHT)	&&
		GetSetPokedexFlag(SpeciesToNationalPokedexNum(SPECIES_ARCHEOPS), 	FLAG_GET_CAUGHT)	&&
		GetSetPokedexFlag(SpeciesToNationalPokedexNum(SPECIES_TYRUNT), 		FLAG_GET_CAUGHT)	&&
		GetSetPokedexFlag(SpeciesToNationalPokedexNum(SPECIES_TYRANTRUM), 	FLAG_GET_CAUGHT)	&&
		GetSetPokedexFlag(SpeciesToNationalPokedexNum(SPECIES_AMAURA), 		FLAG_GET_CAUGHT)	&&
		GetSetPokedexFlag(SpeciesToNationalPokedexNum(SPECIES_AURORUS), 	FLAG_GET_CAUGHT)	&&
		GetSetPokedexFlag(SpeciesToNationalPokedexNum(SPECIES_DRACOZOLT), 	FLAG_GET_CAUGHT)	&&
		GetSetPokedexFlag(SpeciesToNationalPokedexNum(SPECIES_ARCTOZOLT), 	FLAG_GET_CAUGHT)	&&
		GetSetPokedexFlag(SpeciesToNationalPokedexNum(SPECIES_DRACOVISH), 	FLAG_GET_CAUGHT)	&&
		GetSetPokedexFlag(SpeciesToNationalPokedexNum(SPECIES_ARCTOVISH), 	FLAG_GET_CAUGHT)	&&
		GetSetPokedexFlag(SpeciesToNationalPokedexNum(SPECIES_RELICANTH), 	FLAG_GET_CAUGHT))
			GetSetQuestFlag(SIDE_QUEST_8, FLAG_SET_COMPLETED);
	//Quest 9----------------------------------------------------------
	for(i = 0; i < PARTY_SIZE; i++){
		if(GetMonData(&gPlayerParty[i], MON_DATA_FRIENDSHIP) >= 220)
			friendshipCount++;
	}
	
	if(friendshipCount >= 2)
		GetSetQuestFlag(SIDE_QUEST_9, FLAG_SET_UNLOCKED);
	
	if(friendshipCount >= PARTY_SIZE)
		GetSetQuestFlag(SIDE_QUEST_9, FLAG_SET_COMPLETED);
	//Quest 10----------------------------------------------------------
	if(GetGameStat(GAME_STAT_EVOLVED_POKEMON) >= 30)
		GetSetQuestFlag(SIDE_QUEST_10, FLAG_SET_UNLOCKED);
	
	if(GetGameStat(GAME_STAT_EVOLVED_POKEMON) >= 150)
		GetSetQuestFlag(SIDE_QUEST_10, FLAG_SET_COMPLETED);
	//Quest 11----------------------------------------------------------
	if(GetGameStat(GAME_STAT_STEPS) >= 1000)
		GetSetQuestFlag(SIDE_QUEST_11, FLAG_SET_UNLOCKED);
	
	if(GetGameStat(GAME_STAT_STEPS) >= 9999)
		GetSetQuestFlag(SIDE_QUEST_11, FLAG_SET_COMPLETED);
	//Quest 12----------------------------------------------------------
	GetSetQuestFlag(SIDE_QUEST_12, FLAG_SET_UNLOCKED);
	
	if( FlagGet(FLAG_VISITED_LITTLEROOT_TOWN) 	&&
		FlagGet(FLAG_VISITED_OLDALE_TOWN) 		&&
		FlagGet(FLAG_VISITED_DEWFORD_TOWN) 		&&
		FlagGet(FLAG_VISITED_LAVARIDGE_TOWN) 	&&
		FlagGet(FLAG_VISITED_FALLARBOR_TOWN) 	&&
		FlagGet(FLAG_VISITED_VERDANTURF_TOWN) 	&&
		FlagGet(FLAG_VISITED_PACIFIDLOG_TOWN) 	&&
		FlagGet(FLAG_VISITED_PETALBURG_CITY) 	&&
		FlagGet(FLAG_VISITED_SLATEPORT_CITY) 	&&
		FlagGet(FLAG_VISITED_MAUVILLE_CITY) 	&&
		FlagGet(FLAG_VISITED_RUSTBORO_CITY) 	&&
		FlagGet(FLAG_VISITED_FORTREE_CITY) 		&&
		FlagGet(FLAG_VISITED_LILYCOVE_CITY) 	&&
		FlagGet(FLAG_VISITED_MOSSDEEP_CITY) 	&&
		FlagGet(FLAG_VISITED_SOOTOPOLIS_CITY) 	&&
		FlagGet(FLAG_VISITED_EVER_GRANDE_CITY))
			GetSetQuestFlag(SIDE_QUEST_12, FLAG_SET_COMPLETED);
	//Quest 13----------------------------------------------------------
	if(GetGameStat(GAME_STAT_SLOT_JACKPOTS) >= 7)
		GetSetQuestFlag(SIDE_QUEST_13, FLAG_SET_UNLOCKED);
	
	if(GetGameStat(GAME_STAT_SLOT_JACKPOTS) >= 20)
		GetSetQuestFlag(SIDE_QUEST_13, FLAG_SET_COMPLETED);
	
	//Quest 14----------------------------------------------------------
	if(GetGameStat(GAME_STAT_WON_POKEMON_LOTTERY) >= 1)
		GetSetQuestFlag(SIDE_QUEST_14, FLAG_SET_COMPLETED);
	
	//Quest 15----------------------------------------------------------
	//Green Shiny
	for(i = 0; i < PARTY_SIZE; i++){
		
		if(IsMonShiny(&gPlayerParty[i]) && GetMonData(&gPlayerParty[i], MON_DATA_POKEBALL, NULL) != ITEM_CHERISH_BALL){
			switch(GetMonData(&gPlayerParty[i], MON_DATA_SPECIES2)){
				case SPECIES_MANKEY:
				case SPECIES_MARILL:
				case SPECIES_SWELLOW:
				case SPECIES_ESPEON:
				case SPECIES_BEEDRILL:
				case SPECIES_DODRIO:
				case SPECIES_DRAGONITE:
				case SPECIES_HUNTAIL:
				case SPECIES_SUDOWOODO:
				case SPECIES_VENUSAUR:
				case SPECIES_HITMONCHAN:
				case SPECIES_MUK:
				case SPECIES_GRIMER:
				case SPECIES_BRONZONG:
				case SPECIES_CRUSTLE:
				case SPECIES_HYDREIGON:
				case SPECIES_KARRABLAST:
				case SPECIES_SKARMORY:
				case SPECIES_TANGROWTH:
				case SPECIES_TANGELA:
				case SPECIES_MEWTWO:
				case SPECIES_POLIWRATH:
				case SPECIES_ZUBAT:
				case SPECIES_GOLBAT:
				case SPECIES_SPINDA:
				case SPECIES_TORTERRA:
				case SPECIES_HOPPIP:
				case SPECIES_SANDSHREW:
				case SPECIES_MR_MIME:
				case SPECIES_WOOBAT:
				case SPECIES_SWOOBAT:
				case SPECIES_KELDEO:
				case SPECIES_DIALGA:
				case SPECIES_MACHAMP:
				case SPECIES_PELIPPER:
				case SPECIES_WINGULL:
				case SPECIES_SALAMENCE:
				case SPECIES_BAGON:
				case SPECIES_SCIZOR:
				case SPECIES_PRIMEAPE:
				case SPECIES_MAROWAK:
				case SPECIES_HITMONLEE:
				case SPECIES_TAUROS:
				case SPECIES_KABUTO:
				case SPECIES_KABUTOPS:
				case SPECIES_JOLTEON:
				case SPECIES_DRUDDIGON:
				case SPECIES_KINGLER:
				case SPECIES_LEAFEON:
				case SPECIES_NIDOQUEEN:
				case SPECIES_REGISTEEL:
				case SPECIES_STANTLER:
				case SPECIES_URSARING:
				case SPECIES_TEDDIURSA:
				case SPECIES_LARVITAR:
				case SPECIES_AZURILL:
				case SPECIES_CUBONE:
				case SPECIES_CHIMECHO:
				case SPECIES_SANDILE:
				case SPECIES_KAKUNA:
				case SPECIES_DEINO:
				case SPECIES_ZWEILOUS:
				case SPECIES_TURTWIG:
				case SPECIES_LURANTIS:
				case SPECIES_BRONZOR:
				case SPECIES_DODUO:
				case SPECIES_TAILLOW:
				case SPECIES_MIMEJR:
				case SPECIES_NINCADA:
				case SPECIES_MACHOKE:
				case SPECIES_VICTREEBEL:
				case SPECIES_CHANSEY:
				case SPECIES_SILCOON:
				case SPECIES_MINUN:
				case SPECIES_LILEEP:
				case SPECIES_TROPIUS:
				case SPECIES_SHELGON:
				case SPECIES_MUNNA:
				case SPECIES_PETILIL:
				case SPECIES_ARCHEN:
					GetSetQuestFlag(SIDE_QUEST_15, FLAG_SET_COMPLETED);
				break;
			}
		}
	}
	//Quest 16----------------------------------------------------------
	for(i = 0; i < PARTY_SIZE; i++){
		if(IsMonShiny(&gPlayerParty[i]) && 
		   GetMonData(&gPlayerParty[i], MON_DATA_POKEBALL, NULL) != ITEM_CHERISH_BALL && 
		   GetMonData(&gPlayerParty[i], MON_DATA_SPECIES2, NULL) != SPECIES_NONE)
			shinyCount++;
	}
	
	if(shinyCount >= 1)
		GetSetQuestFlag(SIDE_QUEST_16, FLAG_SET_UNLOCKED);
	
	if(shinyCount >= 5)
		GetSetQuestFlag(SIDE_QUEST_16, FLAG_SET_COMPLETED);
	//Quest 17----------------------------------------------------------
	if(GetGameStat(GAME_STAT_PLANTED_BERRIES) >= 10)
		GetSetQuestFlag(SIDE_QUEST_17, FLAG_SET_UNLOCKED);
	
	if(GetGameStat(GAME_STAT_PLANTED_BERRIES) >= 50)
		GetSetQuestFlag(SIDE_QUEST_17, FLAG_SET_COMPLETED);
	//Quest 18----------------------------------------------------------
	if(GetGameStat(GAME_STAT_DEXNAV_SCANNED) >= 100)
		GetSetQuestFlag(SIDE_QUEST_18, FLAG_SET_UNLOCKED);
	
	if(GetGameStat(GAME_STAT_DEXNAV_SCANNED) >= 500)
		GetSetQuestFlag(SIDE_QUEST_18, FLAG_SET_COMPLETED);
	//Quest 19----------------------------------------------------------
	if(GetGameStat(GAME_STAT_GOT_RAINED_ON) >= 10)
		GetSetQuestFlag(SIDE_QUEST_19, FLAG_SET_UNLOCKED);
	
	if(GetGameStat(GAME_STAT_GOT_RAINED_ON) >= 50)
		GetSetQuestFlag(SIDE_QUEST_19, FLAG_SET_COMPLETED);
	//Quest 20----------------------------------------------------------
	if(GetGameStat(GAME_STAT_USED_DAYCARE) >= 10)
		GetSetQuestFlag(SIDE_QUEST_20, FLAG_SET_UNLOCKED);
	
	if(GetGameStat(GAME_STAT_USED_DAYCARE) >= 50)
		GetSetQuestFlag(SIDE_QUEST_20, FLAG_SET_COMPLETED);
	//Quest 21----------------------------------------------------------
	if(GetGameStat(GAME_STAT_CHECKED_CLOCK) >= 15)
		GetSetQuestFlag(SIDE_QUEST_21, FLAG_SET_UNLOCKED);
	
	if(GetGameStat(GAME_STAT_CHECKED_CLOCK) >= 75)
		GetSetQuestFlag(SIDE_QUEST_21, FLAG_SET_COMPLETED);
	//Quest 22----------------------------------------------------------
	if(GetGameStat(GAME_STAT_WON_CONTEST) >= 5)
		GetSetQuestFlag(SIDE_QUEST_22, FLAG_SET_UNLOCKED);
	
	if(GetGameStat(GAME_STAT_WON_CONTEST) >= 25)
		GetSetQuestFlag(SIDE_QUEST_22, FLAG_SET_COMPLETED);
	//Quest 23----------------------------------------------------------
	if(GetGameStat(GAME_STAT_FISHING_CAPTURES) >= 5)
		GetSetQuestFlag(SIDE_QUEST_23, FLAG_SET_UNLOCKED);
	
	if(GetGameStat(GAME_STAT_FISHING_CAPTURES) >= 25)
		GetSetQuestFlag(SIDE_QUEST_23, FLAG_SET_COMPLETED);
	//Quest 24 Safari -------------------------------------------
	if(GetGameStat(GAME_STAT_ENTERED_SAFARI_ZONE) >= 10)
		GetSetQuestFlag(SIDE_QUEST_24, FLAG_SET_UNLOCKED);
	
	if(GetGameStat(GAME_STAT_ENTERED_SAFARI_ZONE) >= 50)
		GetSetQuestFlag(SIDE_QUEST_24, FLAG_SET_COMPLETED);
	//Quest 25 Struggle -------------------------------------------
	if(GetGameStat(GAME_STAT_USED_STRUGGLE) >= 2)
		GetSetQuestFlag(SIDE_QUEST_25, FLAG_SET_UNLOCKED);
	
	if(GetGameStat(GAME_STAT_USED_STRUGGLE) >= 10)
		GetSetQuestFlag(SIDE_QUEST_25, FLAG_SET_COMPLETED);
	//Quest 26 Catch -------------------------------------------
	if(GetGameStat(GAME_STAT_POKEMON_CAPTURES) >= 50)
		GetSetQuestFlag(SIDE_QUEST_26, FLAG_SET_UNLOCKED);
	
	if(GetGameStat(GAME_STAT_POKEMON_CAPTURES) >= 200)
		GetSetQuestFlag(SIDE_QUEST_26, FLAG_SET_COMPLETED);
	//Quest 27 Bad Day -------------------------------------------
	if (VarGet(VAR_NORMAL_MOCK_BATTLES) >= 5)
		GetSetQuestFlag(SIDE_QUEST_27, FLAG_SET_UNLOCKED);
	
	if (VarGet(VAR_NORMAL_MOCK_BATTLES) >= 30)
		GetSetQuestFlag(SIDE_QUEST_27, FLAG_SET_COMPLETED);
	
	//Quest 29 Happy Birthday -------------------------------------------
	if(gLocalTime.days >= 100)
		GetSetQuestFlag(SIDE_QUEST_29, FLAG_SET_UNLOCKED);
	
	if(gLocalTime.days >= 365)
		GetSetQuestFlag(SIDE_QUEST_29, FLAG_SET_COMPLETED);
	//Quest 30 Catch -------------------------------------------
	if(GetGameStat(GAME_STAT_STARTED_TRENDS) >= 3)
		GetSetQuestFlag(SIDE_QUEST_30, FLAG_SET_UNLOCKED);
	
	if(GetGameStat(GAME_STAT_STARTED_TRENDS) >= 5)
		GetSetQuestFlag(SIDE_QUEST_30, FLAG_SET_COMPLETED);
	//Quest 31 Pokeblocks -------------------------------------------
	if(GetGameStat(GAME_STAT_POKEBLOCKS) >= 5)
		GetSetQuestFlag(SIDE_QUEST_31, FLAG_SET_UNLOCKED);
	
	if(GetGameStat(GAME_STAT_POKEBLOCKS) >= 30)
		GetSetQuestFlag(SIDE_QUEST_31, FLAG_SET_COMPLETED);
    //Quest 31 Pokeblocks -------------------------------------------
	if(CheckBagHasItem(ITEM_SCANNER, 1))
		GetSetQuestFlag(SIDE_QUEST_32, FLAG_SET_UNLOCKED);
	
	if(FlagGet(FLAG_EXCHANGED_SCANNER))
		GetSetQuestFlag(SIDE_QUEST_32, FLAG_SET_COMPLETED);
	//Quest 49----------------------------------------------------------
	//Red and Steven Fight
	if(FlagGet(FLAG_DEFEATED_METEOR_FALLS_STEVEN))
		GetSetQuestFlag(SIDE_QUEST_49, FLAG_SET_UNLOCKED);
	
	if(FlagGet(FLAG_ENABLE_RED_FIGHT))
		GetSetQuestFlag(SIDE_QUEST_49, FLAG_SET_COMPLETED);
	//Achievement 50----------------------------------------------------------
	if(FlagGet(FLAG_SYS_GAME_CLEAR))
		GetSetQuestFlag(SIDE_QUEST_50, FLAG_SET_UNLOCKED);
	
	//Achievement 51----------------------------------------------------------
	if(FlagGet(FLAG_SHINY_RAYQUAZA_TITLE_SCREEN))
		GetSetQuestFlag(SIDE_QUEST_51, FLAG_SET_COMPLETED);
	
	//Achievement 52----------------------------------------------------------
	if (VarGet(VAR_HARD_MOCK_BATTLES) >= 50)
		GetSetQuestFlag(SIDE_QUEST_52, FLAG_SET_COMPLETED);
	
	//Achievement 53----------------------------------------------------------
	if(FlagGet(FLAG_POKERUS_EXPLAINED))
		GetSetQuestFlag(SIDE_QUEST_53, FLAG_SET_COMPLETED);
	//Achievement 54----------------------------------------------------------
	if(FlagGet(FLAG_SYS_GAME_CLEAR))
		GetSetQuestFlag(SIDE_QUEST_54, FLAG_SET_UNLOCKED);
	
	if(FlagGet(FLAG_NEW_GAME_PLUS))
		GetSetQuestFlag(SIDE_QUEST_54, FLAG_SET_COMPLETED);
	//Quest 66----------------------------------------------------------
	//3 AM
	if(gLocalTime.hours == 3)
		GetSetQuestFlag(SIDE_QUEST_66, FLAG_SET_COMPLETED);
	//Quest 67----------------------------------------------------------
	if(FlagGet(FLAG_WON_METRONOME_HARD_BATTLE))
		GetSetQuestFlag(SIDE_QUEST_67, FLAG_SET_COMPLETED);
	
	//Quest 96----------------------------------------------------------
	//TMs and HMs
	for(i = 0; i < 120; i++){
		if (CheckBagHasItem(ITEM_TM01_FOCUS_PUNCH + i, 1))
			tmCount++;
	}
	
	if(tmCount >= 60)
		GetSetQuestFlag(SIDE_QUEST_96, FLAG_SET_UNLOCKED);
	
	if(tmCount >= 120)
		GetSetQuestFlag(SIDE_QUEST_96, FLAG_SET_COMPLETED);
	//----------------------------------------------------------
   /*/GetSetQuestFlag(SIDE_QUEST_1, FLAG_SET_UNLOCKED);
    GetSetQuestFlag(SIDE_QUEST_2, FLAG_SET_UNLOCKED);
    GetSetQuestFlag(SIDE_QUEST_3, FLAG_SET_UNLOCKED);
    GetSetQuestFlag(SIDE_QUEST_5, FLAG_SET_UNLOCKED);
    GetSetQuestFlag(SIDE_QUEST_5, FLAG_SET_COMPLETED);    
    SetActiveQuest(SIDE_QUEST_2);/*/
}

static void Task_QuestMenuProgress(u8 taskId)
{
	u8 i;
    u8 questIndex = QuestMenu_GetCursorPosition();
	u16 currentProgress = 0;
	u16 Objetive = 1;
	QuestMenuSubmenuSelectionMessage(taskId);
	
	switch(questIndex){
		//--------------------------------------------------------------------------
		case SIDE_QUEST_2://4 Badges
			currentProgress = GetNumBadges();
			Objetive = 4;
		break;
		//--------------------------------------------------------------------------
		case SIDE_QUEST_3://4 Badges
			currentProgress = GetNumBadges();
			Objetive = 8;
		break;
		//--------------------------------------------------------------------------
		case SIDE_QUEST_7:
			currentProgress = 0;
			Objetive = 4;
			
			if(FlagGet(FLAG_RUSTBORO_NPC_TRADE_COMPLETED))
				currentProgress++;
			if(FlagGet(FLAG_PACIFIDLOG_NPC_TRADE_COMPLETED))
				currentProgress++;
			if(FlagGet(FLAG_FORTREE_NPC_TRADE_COMPLETED))
				currentProgress++;
			if(FlagGet(FLAG_BATTLE_FRONTIER_TRADE_DONE))
				currentProgress++;
		break;
		//--------------------------------------------------------------------------
		case SIDE_QUEST_8:
			if(TRUE){
			u16 fossilMons[] = {
				SPECIES_OMANYTE,
				SPECIES_OMASTAR,
				SPECIES_KABUTO,
				SPECIES_KABUTOPS,
				SPECIES_AERODACTYL,
				SPECIES_LILEEP,
				SPECIES_ANORITH,
				SPECIES_ARMALDO,
				SPECIES_CRANIDOS,
				SPECIES_RAMPARDOS,
				SPECIES_SHIELDON,
				SPECIES_BASTIODON,
				SPECIES_TIRTOUGA,
				SPECIES_CARRACOSTA,
				SPECIES_ARCHEN,
				SPECIES_ARCHEOPS,
				SPECIES_TYRUNT,
				SPECIES_TYRANTRUM,
				SPECIES_AMAURA,
				SPECIES_AURORUS,
				SPECIES_DRACOZOLT,
				SPECIES_ARCTOZOLT,
				SPECIES_DRACOVISH,
				SPECIES_ARCTOVISH,
				SPECIES_RELICANTH};
			
			currentProgress = 0;
			Objetive = (sizeof(fossilMons)/sizeof(fossilMons[0]));
			
			for(i = 0; i < Objetive; i++){
				if(GetSetPokedexFlag(SpeciesToNationalPokedexNum(fossilMons[i]), FLAG_GET_CAUGHT))
					currentProgress++;
			}
			
		}
		break;
		//--------------------------------------------------------------------------
		case SIDE_QUEST_9:
			for(i = 0; i < PARTY_SIZE; i++){
				if(GetMonData(&gPlayerParty[i], MON_DATA_FRIENDSHIP) >= 220)
					currentProgress++;
			}
			Objetive = PARTY_SIZE;
		break;
		//--------------------------------------------------------------------------
		case SIDE_QUEST_10:
			currentProgress = GetGameStat(GAME_STAT_EVOLVED_POKEMON);
			Objetive = 150;
		break;
		//--------------------------------------------------------------------------
		case SIDE_QUEST_11:
			currentProgress = GetGameStat(GAME_STAT_STEPS);
			Objetive = 9999;
		break;
		//--------------------------------------------------------------------------
		case SIDE_QUEST_12:
			if( FlagGet(FLAG_VISITED_LITTLEROOT_TOWN))
				currentProgress++;
			if( FlagGet(FLAG_VISITED_OLDALE_TOWN))
				currentProgress++;
			if( FlagGet(FLAG_VISITED_DEWFORD_TOWN))
				currentProgress++;
			if( FlagGet(FLAG_VISITED_LAVARIDGE_TOWN))
				currentProgress++;
			if( FlagGet(FLAG_VISITED_FALLARBOR_TOWN))
				currentProgress++;
			if( FlagGet(FLAG_VISITED_VERDANTURF_TOWN))
				currentProgress++;
			if( FlagGet(FLAG_VISITED_PACIFIDLOG_TOWN))
				currentProgress++;
			if( FlagGet(FLAG_VISITED_PETALBURG_CITY))
				currentProgress++;
			if( FlagGet(FLAG_VISITED_SLATEPORT_CITY))
				currentProgress++;
			if( FlagGet(FLAG_VISITED_MAUVILLE_CITY))
				currentProgress++;
			if( FlagGet(FLAG_VISITED_RUSTBORO_CITY))
				currentProgress++;
			if( FlagGet(FLAG_VISITED_FORTREE_CITY))
				currentProgress++;
			if( FlagGet(FLAG_VISITED_LILYCOVE_CITY))
				currentProgress++;
			if( FlagGet(FLAG_VISITED_MOSSDEEP_CITY))
				currentProgress++;
			if( FlagGet(FLAG_VISITED_SOOTOPOLIS_CITY))
				currentProgress++;
			if( FlagGet(FLAG_VISITED_EVER_GRANDE_CITY))
				currentProgress++;
		
			
			Objetive = 16;
		break;
		//--------------------------------------------------------------------------
		case SIDE_QUEST_13:
			currentProgress = GetGameStat(GAME_STAT_SLOT_JACKPOTS);
			Objetive = 20;
		break;
		//--------------------------------------------------------------------------
		case SIDE_QUEST_16:
			currentProgress = GetGameStat(GAME_STAT_CAUGHT_SHINIES);
			Objetive = 5;
		break;
		//--------------------------------------------------------------------------
		case SIDE_QUEST_17:
			currentProgress = GetGameStat(GAME_STAT_PLANTED_BERRIES);
			Objetive = 50;
		break;
		//--------------------------------------------------------------------------
		case SIDE_QUEST_18:
			currentProgress = GetGameStat(GAME_STAT_DEXNAV_SCANNED);
			Objetive = 500;
		break;
		//--------------------------------------------------------------------------
		case SIDE_QUEST_19:
			currentProgress = GetGameStat(GAME_STAT_GOT_RAINED_ON);
			Objetive = 50;
		break;
		//--------------------------------------------------------------------------
		case SIDE_QUEST_20:
			currentProgress = GetGameStat(GAME_STAT_USED_DAYCARE);
			Objetive = 50;
		break;
		//--------------------------------------------------------------------------
		case SIDE_QUEST_21:
			currentProgress = GetGameStat(GAME_STAT_CHECKED_CLOCK);
			Objetive = 75;
		break;
		//--------------------------------------------------------------------------
		case SIDE_QUEST_22:
			currentProgress = GetGameStat(GAME_STAT_WON_CONTEST);
			Objetive = 25;
		break;
		//--------------------------------------------------------------------------
		case SIDE_QUEST_23:
			currentProgress = GetGameStat(GAME_STAT_FISHING_CAPTURES);
			Objetive = 25;
		break;
		//--------------------------------------------------------------------------
		case SIDE_QUEST_24:
			currentProgress = GetGameStat(GAME_STAT_ENTERED_SAFARI_ZONE);
			Objetive = 50;
		break;
		//--------------------------------------------------------------------------
		case SIDE_QUEST_25:
			currentProgress = GetGameStat(GAME_STAT_USED_STRUGGLE);
			Objetive = 5;
		break;
		//--------------------------------------------------------------------------
		case SIDE_QUEST_26:
			currentProgress = GetGameStat(GAME_STAT_POKEMON_CAPTURES);
			Objetive = 200;
		break;
		//--------------------------------------------------------------------------
		case SIDE_QUEST_27:
			currentProgress = VarGet(VAR_NORMAL_MOCK_BATTLES);
			Objetive = 30;
		break;
		//--------------------------------------------------------------------------
		case SIDE_QUEST_29:
			currentProgress = gLocalTime.days;
			Objetive = 365;
		break;
		//--------------------------------------------------------------------------
		case SIDE_QUEST_30:
			currentProgress = GetGameStat(GAME_STAT_STARTED_TRENDS);
			Objetive = 5;
		break;
		//--------------------------------------------------------------------------
		case SIDE_QUEST_31:
			currentProgress = GetGameStat(GAME_STAT_POKEBLOCKS);
			Objetive = 30;
		break;
		//--------------------------------------------------------------------------
		case SIDE_QUEST_52:
			currentProgress = VarGet(VAR_HARD_MOCK_BATTLES);
			Objetive = 50;
		break;
		//--------------------------------------------------------------------------
		default:
			currentProgress = 0;
			Objetive = 1;
		break;
	}
	
	if(currentProgress > Objetive)
		currentProgress = Objetive;
	
	ConvertIntToDecimalStringN(gStringVar1, currentProgress, STR_CONV_MODE_LEFT_ALIGN, 5);
	ConvertIntToDecimalStringN(gStringVar2, Objetive, STR_CONV_MODE_LEFT_ALIGN, 5);
    StringExpandPlaceholders(gStringVar4, sText_QuestMenu_DisplayProgress);
    QuestMenu_DisplaySubMenuMessage(taskId);
}

void SetQuestMenuActive(void)
{
    FlagSet(FLAG_QUEST_MENU_ACTIVE);
}

void CopyQuestName(u8 *dst, u8 questId)
{
    StringCopy(dst, sSideQuests[questId].name);
}

void GetQuestName(u8 *dst, u8 questId)
{
    ConvertIntToDecimalStringN(gStringVar1, questId, STR_CONV_MODE_LEFT_ALIGN, 5);
	
	if (GetSetQuestFlag(questId, FLAG_GET_UNLOCKED))
		StringCopy(gStringVar2, sSideQuests[questId].name);
    else
		StringCopy(gStringVar2, sText_QuestMenu_Unk);
	
	StringExpandPlaceholders(gStringVar4, sText_QuestMenu_QuestNumber);
	StringCopy(dst, gStringVar4);
	
	//return gStringVar4;
}

#undef tBldYBak
#undef tBldCntBak
#undef tWin0Bottom
#undef tWin0Top
#undef tWin0Right
#undef tWin0Left
#undef tYSpeed
#undef tXSpeed
#undef tState