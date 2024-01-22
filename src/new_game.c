#include "global.h"
#include "new_game.h"
#include "random.h"
#include "pokemon.h"
#include "roamer.h"
#include "pokemon_size_record.h"
#include "script.h"
#include "lottery_corner.h"
#include "play_time.h"
#include "mauville_old_man.h"
#include "match_call.h"
#include "lilycove_lady.h"
#include "load_save.h"
#include "pokeblock.h"
#include "dewford_trend.h"
#include "berry.h"
#include "rtc.h"
#include "easy_chat.h"
#include "event_data.h"
#include "money.h"
#include "trainer_hill.h"
#include "tv.h"
#include "coins.h"
#include "text.h"
#include "overworld.h"
#include "mail.h"
#include "battle_records.h"
#include "item.h"
#include "pokedex.h"
#include "apprentice.h"
#include "frontier_util.h"
#include "constants/maps.h"
#include "pokedex.h"
#include "save.h"
#include "link_rfu.h"
#include "main.h"
#include "contest.h"
#include "item_menu.h"
#include "pokemon_storage_system.h"
#include "pokemon_jump.h"
#include "decoration_inventory.h"
#include "secret_base.h"
#include "player_pc.h"
#include "field_specials.h"
#include "berry_powder.h"
#include "mevent.h"
#include "ui_mode_menu.h"
#include "union_room_chat.h"
#include "constants/map_groups.h"
#include "constants/items.h"
#include "tx_pokemon_follower.h"

extern const u8 EventScript_ResetAllMapFlags[];

// this file's functions
static void ClearFrontierRecord(void);
static void WarpToTruck(void);
static void ResetMiniGamesResults(void);

// EWRAM vars
EWRAM_DATA bool8 gDifferentSaveFile = FALSE;
EWRAM_DATA bool8 gEnableContestDebugging = FALSE;

// const rom data
static const struct ContestWinner sContestWinnerPicDummy =
{
    .monName = _(""),
    .trainerName = _("")
};

// code
void SetTrainerId(u32 trainerId, u8 *dst)
{
    dst[0] = trainerId;
    dst[1] = trainerId >> 8;
    dst[2] = trainerId >> 16;
    dst[3] = trainerId >> 24;
}

u32 GetTrainerId(u8 *trainerId)
{
    return (trainerId[3] << 24) | (trainerId[2] << 16) | (trainerId[1] << 8) | (trainerId[0]);
}

void CopyTrainerId(u8 *dst, u8 *src)
{
    s32 i;
    for (i = 0; i < TRAINER_ID_LENGTH; i++)
        dst[i] = src[i];
}

static void InitPlayerTrainerId(void)
{
    u32 trainerId = (Random() << 16) | GetGeneratedTrainerIdLower();
    SetTrainerId(trainerId, gSaveBlock2Ptr->playerTrainerId);
}

// L=A isnt set here for some reason.
static void SetDefaultOptions(void)
{
    gSaveBlock2Ptr->optionsTextSpeed = OPTIONS_TEXT_SPEED_FAST;
	gSaveBlock2Ptr->optionsDifficulty = OPTIONS_MUSIC_HOENN;
    gSaveBlock2Ptr->optionsWindowFrameType = 0;
    gSaveBlock2Ptr->optionsSound = OPTIONS_SOUND_STEREO;
    gSaveBlock2Ptr->optionsBattleStyle = OPTIONS_BATTLE_STYLE_SHIFT;
    gSaveBlock2Ptr->optionsBattleSceneOff = FALSE;
    gSaveBlock2Ptr->regionMapZoom = FALSE;
}

static void ClearPokedexFlags(void)
{
    gUnusedPokedexU8 = 0;
    memset(&gSaveBlock1Ptr->dexCaught, 0, sizeof(gSaveBlock1Ptr->dexCaught));
    memset(&gSaveBlock1Ptr->dexSeen, 0, sizeof(gSaveBlock1Ptr->dexSeen));
}

void ClearAllContestWinnerPics(void)
{
    s32 i;

    ClearContestWinnerPicsInContestHall();
    for (i = 8; i < 13; i++)
        gSaveBlock1Ptr->contestWinners[i] = sContestWinnerPicDummy;
}

static void ClearFrontierRecord(void)
{
    CpuFill32(0, &gSaveBlock2Ptr->frontier, sizeof(gSaveBlock2Ptr->frontier));

    gSaveBlock2Ptr->frontier.opponentNames[0][0] = EOS;
    gSaveBlock2Ptr->frontier.opponentNames[1][0] = EOS;
}

static void WarpToTruck(void)
{
    SetWarpDestination(MAP_GROUP(INSIDE_OF_TRUCK), MAP_NUM(INSIDE_OF_TRUCK), 5, 5, -1);
    WarpIntoMap();
}

void Sav2_ClearSetDefault(void)
{
    ClearSav2();
    SetDefaultOptions();
}

void ResetMenuAndMonGlobals(void)
{
    gDifferentSaveFile = 0;
    ResetPokedexScrollPositions();
    ZeroPlayerPartyMons();
    ZeroEnemyPartyMons();
    ResetBagScrollPositions();
    ResetPokeblockScrollPositions();
}

u16 newGamePlusFlagstoCarry[FLAGS_TO_CARRY_COUNT] = {
    FLAG_ACHIEVEMENT_REWARD_01,
    FLAG_ACHIEVEMENT_REWARD_02,
    FLAG_ACHIEVEMENT_REWARD_03,
    FLAG_ACHIEVEMENT_REWARD_04,
    FLAG_ACHIEVEMENT_REWARD_05,
    FLAG_ACHIEVEMENT_REWARD_06,
    FLAG_ACHIEVEMENT_REWARD_07,
    FLAG_ACHIEVEMENT_REWARD_08,
    FLAG_ACHIEVEMENT_REWARD_09,
    FLAG_ACHIEVEMENT_REWARD_10,
    FLAG_ACHIEVEMENT_REWARD_11,
    FLAG_ACHIEVEMENT_REWARD_12,
    FLAG_ACHIEVEMENT_REWARD_13,
    FLAG_ACHIEVEMENT_REWARD_14,
    FLAG_ACHIEVEMENT_REWARD_15,
    FLAG_ACHIEVEMENT_REWARD_16,
    FLAG_ACHIEVEMENT_REWARD_17,
    FLAG_ACHIEVEMENT_REWARD_18,
    FLAG_ACHIEVEMENT_REWARD_19,
    FLAG_ACHIEVEMENT_REWARD_20,
    FLAG_ACHIEVEMENT_REWARD_21,
    FLAG_ACHIEVEMENT_REWARD_22,
    FLAG_ACHIEVEMENT_REWARD_23,
    FLAG_ACHIEVEMENT_REWARD_24,
    FLAG_ACHIEVEMENT_REWARD_25,
    FLAG_ACHIEVEMENT_REWARD_26,
    FLAG_ACHIEVEMENT_REWARD_27,
    FLAG_ACHIEVEMENT_REWARD_28,
    FLAG_ACHIEVEMENT_REWARD_29,
    FLAG_ACHIEVEMENT_REWARD_30,
	FLAG_ACHIEVEMENT_REWARD_31,
    FLAG_ACHIEVEMENT_REWARD_32,
    FLAG_ACHIEVEMENT_REWARD_01,
    FLAG_ACHIEVEMENT_REWARD_01,
    FLAG_ACHIEVEMENT_REWARD_01,
    FLAG_ACHIEVEMENT_REWARD_01,
    FLAG_ACHIEVEMENT_REWARD_01,
    FLAG_ACHIEVEMENT_REWARD_01,
    FLAG_ACHIEVEMENT_REWARD_01,
    FLAG_ACHIEVEMENT_REWARD_01,//40
	FLAG_ACHIEVEMENT_REWARD_01,
    FLAG_ACHIEVEMENT_REWARD_01,
    FLAG_ACHIEVEMENT_REWARD_01,
    FLAG_ACHIEVEMENT_REWARD_01,
    FLAG_ACHIEVEMENT_REWARD_01,
    FLAG_ACHIEVEMENT_REWARD_01,
    FLAG_ACHIEVEMENT_REWARD_01,
    FLAG_ACHIEVEMENT_REWARD_01,
    FLAG_ACHIEVEMENT_REWARD_49,
    FLAG_ACHIEVEMENT_REWARD_50,//50
	FLAG_ACHIEVEMENT_REWARD_51,
    FLAG_ACHIEVEMENT_REWARD_52,
    FLAG_ACHIEVEMENT_REWARD_53,
    FLAG_ACHIEVEMENT_REWARD_54,
    FLAG_ACHIEVEMENT_REWARD_01,
    FLAG_ACHIEVEMENT_REWARD_01,
    FLAG_ACHIEVEMENT_REWARD_01,
    FLAG_ACHIEVEMENT_REWARD_01,
    FLAG_ACHIEVEMENT_REWARD_01,
    FLAG_ACHIEVEMENT_REWARD_01,//60
	FLAG_ACHIEVEMENT_REWARD_01,
    FLAG_ACHIEVEMENT_REWARD_01,
    FLAG_ACHIEVEMENT_REWARD_01,
    FLAG_ACHIEVEMENT_REWARD_01,
    FLAG_ACHIEVEMENT_REWARD_01,
    FLAG_ACHIEVEMENT_REWARD_66,
    FLAG_ACHIEVEMENT_REWARD_67,
    FLAG_ACHIEVEMENT_REWARD_01,
    FLAG_ACHIEVEMENT_REWARD_01,
    FLAG_ACHIEVEMENT_REWARD_01,//70
	FLAG_ACHIEVEMENT_REWARD_01,
    FLAG_ACHIEVEMENT_REWARD_01,
    FLAG_ACHIEVEMENT_REWARD_01,
    FLAG_ACHIEVEMENT_REWARD_01,
    FLAG_ACHIEVEMENT_REWARD_01,
    FLAG_ACHIEVEMENT_REWARD_01,
    FLAG_ACHIEVEMENT_REWARD_01,
    FLAG_ACHIEVEMENT_REWARD_01,
    FLAG_ACHIEVEMENT_REWARD_01,
	FLAG_ACHIEVEMENT_REWARD_01,//80
	FLAG_ACHIEVEMENT_REWARD_01,
    FLAG_ACHIEVEMENT_REWARD_01,
    FLAG_ACHIEVEMENT_REWARD_01,
    FLAG_ACHIEVEMENT_REWARD_01,
    FLAG_ACHIEVEMENT_REWARD_01,
    FLAG_ACHIEVEMENT_REWARD_01,
    FLAG_ACHIEVEMENT_REWARD_01,
    FLAG_ACHIEVEMENT_REWARD_01,
    FLAG_ACHIEVEMENT_REWARD_01,
    FLAG_ACHIEVEMENT_REWARD_01,//90
	FLAG_ACHIEVEMENT_REWARD_01,
    FLAG_ACHIEVEMENT_REWARD_01,
    FLAG_ACHIEVEMENT_REWARD_01,
    FLAG_ACHIEVEMENT_REWARD_01,
    FLAG_ACHIEVEMENT_REWARD_01,
    FLAG_ACHIEVEMENT_REWARD_96,
    FLAG_ACHIEVEMENT_REWARD_97,
    FLAG_ACHIEVEMENT_REWARD_98,
    FLAG_ACHIEVEMENT_REWARD_99,
	FLAG_ACHIEVEMENT_REWARD_100,//100
};

void NewGameInitData(void)
{
    u8 i;
    u16 j;
    bool8 newgameplus = FlagGet(FLAG_SYS_GAME_CLEAR);
    u32 money = GetMoney(&gSaveBlock1Ptr->money);
    u8 dexSeen[DEX_FLAGS_NO];
    u8 dexCaught[DEX_FLAGS_NO];
    u16 newgamepluscount = VarGet(VAR_NEW_GAME_PLUS_COUNT);

    u16 pcItems_plus_itemID[PC_ITEMS_COUNT];
    u8 pcItems_plus_quantity[PC_ITEMS_COUNT];

    struct ItemSlot pcItemsplus[PC_ITEMS_COUNT];
	
    u16 bagPocket_Items_plus_itemID[BAG_ITEMS_COUNT];
    u8 bagPocket_Items_plus_quantity[BAG_ITEMS_COUNT];
	
    u16 bagPocket_KeyItems_plus_itemID[BAG_ITEMS_COUNT]; //Unused
    u8 bagPocket_KeyItems_plus_quantity[BAG_ITEMS_COUNT]; //Unused
	
    u16 bagPocket_PokeBalls_plus_itemID[BAG_POKEBALLS_COUNT];
    u8 bagPocket_PokeBalls_plus_quantity[BAG_POKEBALLS_COUNT];
	
    u16 bagPocket_Berries_plus_itemID[BAG_BERRIES_COUNT];
    u8 bagPocket_Berries_plus_quantity[BAG_BERRIES_COUNT];
	
	u16 bagPocket_Medicine_plus_itemID[BAG_MEDICINE_COUNT];
    u8 bagPocket_Medicine_plus_quantity[BAG_MEDICINE_COUNT];
	
	u16 bagPocket_BattleItems_plus_itemID[BAG_BATTLEITEMS_COUNT];
    u8 bagPocket_BattleItems_plus_quantity[BAG_BATTLEITEMS_COUNT];
	
	u16 bagPocket_PowerUp_plus_itemID[BAG_POWERUP_COUNT];
    u8 bagPocket_PowerUp_plus_quantity[BAG_POWERUP_COUNT];
	
	u16 bagPocket_TypeItems_plus_itemID[BAG_TYPEITEMS_COUNT];
    u8 bagPocket_TypeItems_plus_quantity[BAG_TYPEITEMS_COUNT];
	
	u16 bagPocket_MegaStones_plus_itemID[BAG_MEGASTONES_COUNT];
    u8 bagPocket_MegaStones_plus_quantity[BAG_MEGASTONES_COUNT];

    u8 unlockedQuestsplus[SIDE_QUEST_FLAGS_COUNT];
	u8 completedQuestsplus[SIDE_QUEST_FLAGS_COUNT];

    
	bool8 flagstoCarry[FLAGS_TO_CARRY_COUNT];
	
    bool8 DoesPlayerHasTM[NUM_TMS];

    if(FlagGet(FLAG_FULL_RANDOMIZED_MODE) || FlagGet(FLAG_NO_EVOLUTION_MODE))
        newgameplus = FALSE;

    if(newgameplus){
        //Achievements
        for (i = 0; i < SIDE_QUEST_FLAGS_COUNT; i++)
        {
            unlockedQuestsplus[i] = gSaveBlock2Ptr->unlockedQuests[i];
            completedQuestsplus[i] = gSaveBlock2Ptr->completedQuests[i];
        }

        //Flags to Carry
        for (i = 0; i < FLAGS_TO_CARRY_COUNT; i++)
        {
            flagstoCarry[i] = FlagGet(newGamePlusFlagstoCarry[i]);
        }

        //Pokedex Flags
        for (i = 0; i < DEX_FLAGS_NO; i++)
        {
            dexCaught[i] = gSaveBlock1Ptr->dexCaught[i];
            dexSeen[i] = gSaveBlock1Ptr->dexSeen[i];
        }

        //PC Items
        for (i = 0; i < PC_ITEMS_COUNT; i++)
        {
            pcItemsplus[i] = gSaveBlock1Ptr->pcItems[i];
        }

        //TMs
        for (i = 0; i < NUM_TMS; i++)
        {
            DoesPlayerHasTM[i] = CheckBagHasItem(ITEM_TM01 + i, 1);
        }

        //Items
        for (i = 0; i < BAG_ITEMS_COUNT; i++)
        {
            bagPocket_Items_plus_itemID[i] = gSaveBlock1Ptr->bagPocket_Items[i].itemId;
            bagPocket_Items_plus_quantity[i] = CountTotalItemQuantityInBag(bagPocket_Items_plus_itemID[i]);
        }

        //Pokeballs
        for (i = 0; i < BAG_POKEBALLS_COUNT; i++)
        {
			bagPocket_PokeBalls_plus_itemID[i] = gSaveBlock1Ptr->bagPocket_PokeBalls[i].itemId;
            bagPocket_PokeBalls_plus_quantity[i] = CountTotalItemQuantityInBag(bagPocket_PokeBalls_plus_itemID[i]);
        }

        //Berries
        for (i = 0; i < BAG_BERRIES_COUNT; i++)
        {
            bagPocket_Berries_plus_itemID[i] = gSaveBlock1Ptr->bagPocket_Berries[i].itemId;
            bagPocket_Berries_plus_quantity[i] = CountTotalItemQuantityInBag(bagPocket_Berries_plus_itemID[i]);
        }

        //Medicine
        for (i = 0; i < BAG_MEDICINE_COUNT; i++)
        {
            bagPocket_Medicine_plus_itemID[i] = gSaveBlock1Ptr->bagPocket_Medicine[i].itemId;
            bagPocket_Medicine_plus_quantity[i] = CountTotalItemQuantityInBag(bagPocket_Medicine_plus_itemID[i]);
        }

        //Battle Items
        for (i = 0; i < BAG_BATTLEITEMS_COUNT; i++)
        {
            bagPocket_BattleItems_plus_itemID[i] = gSaveBlock1Ptr->bagPocket_BattleItems[i].itemId;
            bagPocket_BattleItems_plus_quantity[i] = CountTotalItemQuantityInBag(bagPocket_BattleItems_plus_itemID[i]);
        }

        //Power-ups
        for (i = 0; i < BAG_POWERUP_COUNT; i++)
        {
            bagPocket_PowerUp_plus_itemID[i] = gSaveBlock1Ptr->bagPocket_PowerUp[i].itemId;
            bagPocket_PowerUp_plus_quantity[i] = CountTotalItemQuantityInBag(bagPocket_PowerUp_plus_itemID[i]);
        }

        //Type Items
        for (i = 0; i < BAG_TYPEITEMS_COUNT; i++)
        {
            bagPocket_TypeItems_plus_itemID[i] = gSaveBlock1Ptr->bagPocket_TypeItems[i].itemId;
            bagPocket_TypeItems_plus_quantity[i] = CountTotalItemQuantityInBag(bagPocket_TypeItems_plus_itemID[i]);
        }

        //Type Items
        for (i = 0; i < BAG_MEGASTONES_COUNT; i++)
        {
            bagPocket_MegaStones_plus_itemID[i] = gSaveBlock1Ptr->bagPocket_MegaStones[i].itemId;
            bagPocket_MegaStones_plus_quantity[i] = CountTotalItemQuantityInBag(bagPocket_MegaStones_plus_itemID[i]);
        }
		
		
        AddBagItem(ITEM_EXP_SHARE, 1);
        AddBagItem(ITEM_OLD_ROD, 1);
        AddBagItem(ITEM_WAILMER_PAIL, 1);
        AddBagItem(ITEM_ACRO_BIKE, 1);

        if(FlagGet(FLAG_ACHIEVEMENT_REWARD_20))
            AddBagItem(ITEM_OVAL_CHARM, 1);

        if(FlagGet(FLAG_ACHIEVEMENT_REWARD_32))
            AddBagItem(ITEM_EXP_CHARM, 1);

        if(FlagGet(FLAG_ACHIEVEMENT_REWARD_50))
            AddBagItem(ITEM_SAFARI_PASS, 1);

        newgamepluscount++;
    }

    if (gSaveFileStatus == SAVE_STATUS_EMPTY || gSaveFileStatus == SAVE_STATUS_CORRUPT)
        RtcReset();

    gDifferentSaveFile = 1;
    gSaveBlock2Ptr->encryptionKey = 0;
    //ZeroPlayerPartyMons();
    ZeroEnemyPartyMons();
    ClearFrontierRecord();
    ClearSav1();
    ClearMailData();
    gSaveBlock2Ptr->specialSaveWarpFlags = 0;
	gSaveBlock2Ptr->gcnLinkFlags = 0;
    InitPlayerTrainerId();
    PlayTimeCounter_Reset();
    InitEventData();
    ClearTVShowData();
    ResetGabbyAndTy();
    ClearSecretBases();
    ClearBerryTrees();
    ResetLinkContestBoolean();
    ClearAllContestWinnerPics();
    ClearPlayerLinkBattleRecords();
    InitSeedotSizeRecord();
    InitLotadSizeRecord();
    ClearBag();
    if(!newgameplus){
        gPlayerPartyCount = 0;
        ZeroPlayerPartyMons();
        ResetGameStats();
        ResetPokedex();
        ClearPokedexFlags();
        SetMoney(&gSaveBlock1Ptr->money, 3000);
        SetCoins(0);
        ResetPokemonStorageSystem();
        NewGameInitPCItems();
        memset(&gSaveBlock2Ptr->unlockedQuests, 0, sizeof(gSaveBlock2Ptr->unlockedQuests));
        memset(&gSaveBlock2Ptr->completedQuests, 0, sizeof(gSaveBlock2Ptr->completedQuests));
    }
    else{
        SetMoney(&gSaveBlock1Ptr->money, money);

        //Achievements
        for (i = 0; i < SIDE_QUEST_FLAGS_COUNT; i++)
        {
            gSaveBlock2Ptr->unlockedQuests[i] = unlockedQuestsplus[i];
            gSaveBlock2Ptr->completedQuests[i] = completedQuestsplus[i];
        }

        //Flags to Carry
        for (i = 0; i < FLAGS_TO_CARRY_COUNT; i++)
        {
            if(flagstoCarry[i] == TRUE) 
                FlagSet(newGamePlusFlagstoCarry[i]);
        }

        //Pokedex Flags
        for (i = 0; i < DEX_FLAGS_NO; i++)
        {
            gSaveBlock1Ptr->dexCaught[i] = dexCaught[i];
            gSaveBlock1Ptr->dexSeen[i] = dexSeen[i];
        }

        //PC Items
        for (i = 0; i < PC_ITEMS_COUNT; i++)
        {
            if(pcItemsplus[i].quantity != ITEM_NONE && pcItemsplus[i].quantity != ITEM_MASTER_BALL)
				gSaveBlock1Ptr->pcItems[i] = pcItemsplus[i];
        }

        //TMs
        for (i = 0; i < NUM_TMS; i++)
        {
            if(DoesPlayerHasTM[i])
                AddBagItem(ITEM_TM01 + i, 1);
        }

        //Items
        for (i = 0; i < BAG_ITEMS_COUNT; i++)
        {
		   if(bagPocket_Items_plus_itemID[i] != ITEM_NONE && bagPocket_Items_plus_itemID[i] != ITEM_MASTER_BALL && !CheckBagHasItem(bagPocket_Items_plus_itemID[i], 1))
				AddBagItem(bagPocket_Items_plus_itemID[i], bagPocket_Items_plus_quantity[i]);
        }

        //Pokeballs
        for (i = 0; i < BAG_POKEBALLS_COUNT; i++)
        {
            //gSaveBlock1Ptr->bagPocket_PokeBalls[i] = bagPocket_PokeBalls_plus[i];
		   if(bagPocket_PokeBalls_plus_itemID[i] != ITEM_NONE && bagPocket_Items_plus_itemID[i] != ITEM_MASTER_BALL && !CheckBagHasItem(bagPocket_PokeBalls_plus_itemID[i], 1))
				AddBagItem(bagPocket_PokeBalls_plus_itemID[i], bagPocket_PokeBalls_plus_quantity[i]);
        }

        //Berries
        for (i = 0; i < BAG_BERRIES_COUNT; i++)
        {
		   if(bagPocket_Berries_plus_itemID[i] != ITEM_NONE && 
              bagPocket_Berries_plus_itemID[i] != ITEM_MASTER_BALL && 
              !CheckBagHasItem(bagPocket_Berries_plus_itemID[i], 1)){
                AddBagItem(bagPocket_Berries_plus_itemID[i], bagPocket_Berries_plus_quantity[i]);
              }
        }

        //Medicine
        for (i = 0; i < BAG_MEDICINE_COUNT; i++)
        {
		   if(bagPocket_Medicine_plus_itemID[i] != ITEM_NONE && 
              bagPocket_Medicine_plus_itemID[i] != ITEM_MASTER_BALL && 
              !CheckBagHasItem(bagPocket_Medicine_plus_itemID[i], 1)){
                AddBagItem(bagPocket_Medicine_plus_itemID[i], bagPocket_Medicine_plus_quantity[i]);
              }
        }

        //Battle Items
        for (i = 0; i < BAG_BATTLEITEMS_COUNT; i++)
        {
		   if(bagPocket_BattleItems_plus_itemID[i] != ITEM_NONE && 
              bagPocket_BattleItems_plus_itemID[i] != ITEM_MASTER_BALL && 
              !CheckBagHasItem(bagPocket_BattleItems_plus_itemID[i], 1)){
                AddBagItem(bagPocket_BattleItems_plus_itemID[i], bagPocket_BattleItems_plus_quantity[i]);
              }
        }

        //Power-ups
        for (i = 0; i < BAG_POWERUP_COUNT; i++)
        {
		   if(bagPocket_PowerUp_plus_itemID[i] != ITEM_NONE && 
              bagPocket_PowerUp_plus_itemID[i] != ITEM_MASTER_BALL && 
              !CheckBagHasItem(bagPocket_PowerUp_plus_itemID[i], 1)){
                AddBagItem(bagPocket_PowerUp_plus_itemID[i], bagPocket_PowerUp_plus_quantity[i]);
              }
        }

        //Type Items
        for (i = 0; i < BAG_TYPEITEMS_COUNT; i++)
        {
		   if(bagPocket_TypeItems_plus_itemID[i] != ITEM_NONE && 
              bagPocket_TypeItems_plus_itemID[i] != ITEM_MASTER_BALL && 
              !CheckBagHasItem(bagPocket_TypeItems_plus_itemID[i], 1)){
                AddBagItem(bagPocket_TypeItems_plus_itemID[i], bagPocket_TypeItems_plus_quantity[i]);
              }
        }

        //Type Items
        for (i = 0; i < BAG_MEGASTONES_COUNT; i++)
        {
		   if(bagPocket_MegaStones_plus_itemID[i] != ITEM_NONE && 
              bagPocket_MegaStones_plus_itemID[i] != ITEM_MASTER_BALL && 
              !CheckBagHasItem(bagPocket_MegaStones_plus_itemID[i], 1)){
                AddBagItem(bagPocket_MegaStones_plus_itemID[i], bagPocket_MegaStones_plus_quantity[i]);
              }
        }
		
		ResetPokemonStorageSystemLevels();

        VarSet(VAR_NEW_GAME_PLUS_COUNT, newgamepluscount);
        FlagSet(FLAG_NEW_GAME_PLUS);
    }
    ClearRoamerData();
    ClearRoamerLocationData();
    //gSaveBlock1Ptr->registeredItem = 0;
	ReShuffleGyms();
    ClearPokeblocks();
    ClearDecorationInventories();
    InitEasyChatPhrases();
    SetMauvilleOldMan();
    InitDewfordTrend();
    ResetFanClub();
    ResetLotteryCorner();
    WarpToTruck();
    ScriptContext2_RunNewScript(EventScript_ResetAllMapFlags);
    ResetMiniGamesResults();
    InitUnionRoomChatRegisteredTexts();
    InitLilycoveLady();
    ResetAllApprenticeData();
    ClearRankingHallRecords();
    InitMatchCallCounters();
    ClearMysteryGift();
    WipeTrainerNameRecords();
    ResetTrainerHillResults();
    ResetContestLinkResults();
	POF_DestroyFollower();
    
    memset(&gSaveBlock2Ptr->itemFlags, 0, sizeof(gSaveBlock2Ptr->itemFlags));
    
    gSaveBlock1Ptr->registeredItemSelect = 0;
    gSaveBlock1Ptr->registeredItemL = 0;
    gSaveBlock1Ptr->registeredItemR = 0;
	gSaveBlock2Ptr->optionsAutomaticFollower = 0;

    memset(gSaveBlock1Ptr->dexNavSearchLevels, 0, sizeof(gSaveBlock1Ptr->dexNavSearchLevels));
    gSaveBlock1Ptr->dexNavChain = 0;
	gSaveBlock2Ptr->lastUsedBall = ITEM_POKE_BALL;
    gSaveBlock2Ptr->titleScreen = 0;
}

static void ResetMiniGamesResults(void)
{
    CpuFill16(0, &gSaveBlock2Ptr->berryCrush, sizeof(struct BerryCrush));
    SetBerryPowder(&gSaveBlock2Ptr->berryCrush.berryPowderAmount, 0);
    ResetPokeJumpResults();
    CpuFill16(0, &gSaveBlock2Ptr->berryPick, sizeof(struct BerryPickingResults));
}
