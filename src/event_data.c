#include "global.h"
#include "event_data.h"
#include "pokedex.h"
#include "random.h"


#define NUM_SPECIAL_FLAGS (SPECIAL_FLAGS_END - SPECIAL_FLAGS_START + 1)
#define NUM_TEMP_FLAGS    (TEMP_FLAGS_END - TEMP_FLAGS_START + 1)
#define NUM_DAILY_FLAGS   (DAILY_FLAGS_END - DAILY_FLAGS_START + 1)
#define NUM_TEMP_VARS     (TEMP_VARS_END - TEMP_VARS_START + 1)

#define SPECIAL_FLAGS_SIZE  (NUM_SPECIAL_FLAGS / 8)  // 8 flags per byte
#define TEMP_FLAGS_SIZE     (NUM_TEMP_FLAGS / 8)
#define DAILY_FLAGS_SIZE    (NUM_DAILY_FLAGS / 8)
#define TEMP_VARS_SIZE      (NUM_TEMP_VARS * 2)      // 1/2 var per byte

EWRAM_DATA u16 gSpecialVar_0x8000 = 0;
EWRAM_DATA u16 gSpecialVar_0x8001 = 0;
EWRAM_DATA u16 gSpecialVar_0x8002 = 0;
EWRAM_DATA u16 gSpecialVar_0x8003 = 0;
EWRAM_DATA u16 gSpecialVar_0x8004 = 0;
EWRAM_DATA u16 gSpecialVar_0x8005 = 0;
EWRAM_DATA u16 gSpecialVar_0x8006 = 0;
EWRAM_DATA u16 gSpecialVar_0x8007 = 0;
EWRAM_DATA u16 gSpecialVar_0x8008 = 0;
EWRAM_DATA u16 gSpecialVar_0x8009 = 0;
EWRAM_DATA u16 gSpecialVar_0x800A = 0;
EWRAM_DATA u16 gSpecialVar_0x800B = 0;
EWRAM_DATA u16 gSpecialVar_Result = 0;
EWRAM_DATA u16 gSpecialVar_LastTalked = 0;
EWRAM_DATA u16 gSpecialVar_Facing = 0;
EWRAM_DATA u16 gSpecialVar_MonBoxId = 0;
EWRAM_DATA u16 gSpecialVar_MonBoxPos = 0;
EWRAM_DATA u16 gSpecialVar_Unused_0x8014 = 0;
EWRAM_DATA static u8 gSpecialFlags[SPECIAL_FLAGS_SIZE] = {0};

extern u16 *const gSpecialVars[];

void InitEventData(void)
{
    memset(gSaveBlock1Ptr->flags, 0, sizeof(gSaveBlock1Ptr->flags));
    memset(gSaveBlock1Ptr->vars, 0, sizeof(gSaveBlock1Ptr->vars));
    memset(gSpecialFlags, 0, sizeof(gSpecialFlags));
}

void ClearTempFieldEventData(void)
{
    memset(gSaveBlock1Ptr->flags + (TEMP_FLAGS_START / 8), 0, TEMP_FLAGS_SIZE);
    memset(gSaveBlock1Ptr->vars + ((TEMP_VARS_START - VARS_START) * 2), 0, TEMP_VARS_SIZE);
    FlagClear(FLAG_SYS_ENC_UP_ITEM);
    FlagClear(FLAG_SYS_ENC_DOWN_ITEM);
    FlagClear(FLAG_SYS_USE_STRENGTH);
    FlagClear(FLAG_SYS_CTRL_OBJ_DELETE);
    FlagClear(FLAG_NURSE_UNION_ROOM_REMINDER);
}

static u16 FindItemFlags[] = {
	FLAG_ITEM_ROUTE_102_POTION,
	FLAG_ITEM_ROUTE_115_SUPER_POTION,
	FLAG_ITEM_ROUTE_119_HYPER_POTION_1,
	FLAG_ITEM_MT_PYRE_EXTERIOR_MAX_POTION,
	FLAG_ITEM_ROUTE_119_HYPER_POTION_2,
	FLAG_ITEM_ROUTE_120_HYPER_POTION,
	FLAG_ITEM_ROUTE_118_HYPER_POTION,
	FLAG_ITEM_ROUTE_104_POTION,
	FLAG_ITEM_ROUTE_109_POTION,
	FLAG_ITEM_ROUTE_113_HYPER_POTION,
	FLAG_ITEM_ROUTE_116_POTION,
	FLAG_ITEM_ROUTE_117_GREAT_BALL,
	FLAG_ITEM_MOSSDEEP_CITY_NET_BALL,
	FLAG_ITEM_RUSTURF_TUNNEL_POKE_BALL,
	FLAG_ITEM_GRANITE_CAVE_B1F_POKE_BALL,
	FLAG_ITEM_PETALBURG_WOODS_GREAT_BALL,
	FLAG_ITEM_ROUTE_104_POKE_BALL,
	FLAG_ITEM_AQUA_HIDEOUT_B2F_NEST_BALL,
	FLAG_ITEM_NEW_MAUVILLE_ULTRA_BALL,
	FLAG_ITEM_ABANDONED_SHIP_HIDDEN_FLOOR_ROOM_6_LUXURY_BALL,
	FLAG_ITEM_ABANDONED_SHIP_ROOMS_2_B1F_DIVE_BALL,
	FLAG_ITEM_ROUTE_123_ULTRA_BALL,
	FLAG_ITEM_ROUTE_120_NEST_BALL,
	FLAG_ITEM_ROUTE_115_GREAT_BALL,
	FLAG_ITEM_MT_PYRE_2F_ULTRA_BALL,
	FLAG_ITEM_MT_PYRE_3F_SUPER_REPEL,
	FLAG_ITEM_ROUTE_113_SUPER_REPEL,
	FLAG_ITEM_ROUTE_116_REPEL,
	FLAG_ITEM_ROUTE_119_SUPER_REPEL,
	FLAG_ITEM_LILYCOVE_CITY_MAX_REPEL,
	FLAG_ITEM_GRANITE_CAVE_B2F_REPEL,
	FLAG_ITEM_ROUTE_113_MAX_ETHER,
	FLAG_ITEM_ROUTE_116_ETHER,
	FLAG_ITEM_PETALBURG_CITY_ETHER,
	FLAG_ITEM_RUSTURF_TUNNEL_MAX_ETHER,
	FLAG_ITEM_PETALBURG_WOODS_ETHER,
	FLAG_ITEM_ROUTE_119_ELIXIR_1,
	FLAG_ITEM_AQUA_HIDEOUT_B1F_MAX_ELIXIR,
	FLAG_ITEM_VICTORY_ROAD_1F_MAX_ELIXIR,
	FLAG_ITEM_ROUTE_123_ELIXIR,
	FLAG_ITEM_ROUTE_110_ELIXIR,
	FLAG_ITEM_ROUTE_111_ELIXIR,
	FLAG_ITEM_ROUTE_119_ELIXIR_2,
	FLAG_ITEM_MAGMA_HIDEOUT_2F_2R_MAX_ELIXIR,
	FLAG_ITEM_ROUTE_117_REVIVE,
	FLAG_ITEM_PETALBURG_CITY_MAX_REVIVE,
	FLAG_ITEM_ABANDONED_SHIP_ROOMS_2_1F_REVIVE,
	FLAG_ITEM_SAFARI_ZONE_SOUTH_WEST_MAX_REVIVE,
	FLAG_ITEM_ROUTE_120_REVIVE,
	FLAG_ITEM_ROUTE_121_REVIVE,
	FLAG_ITEM_ROUTE_133_MAX_REVIVE,
	FLAG_ITEM_MAGMA_HIDEOUT_4F_MAX_REVIVE,
	FLAG_ITEM_ROUTE_120_FULL_HEAL,
	FLAG_ITEM_METEOR_FALLS_1F_1R_FULL_HEAL,
	FLAG_ITEM_VICTORY_ROAD_B1F_FULL_RESTORE,
	FLAG_ITEM_VICTORY_ROAD_B2F_FULL_HEAL,
	FLAG_ITEM_NEW_MAUVILLE_FULL_HEAL,
	FLAG_ITEM_MAGMA_HIDEOUT_2F_2R_FULL_RESTORE,
	FLAG_ITEM_JAGGED_PASS_BURN_HEAL,
	FLAG_ITEM_SHOAL_CAVE_STAIRS_ROOM_ICE_HEAL,
	FLAG_ITEM_PETALBURD_WOODS_PARALYZE_HEAL,
	FLAG_ITEM_NEW_MAUVILLE_PARALYZE_HEAL,
	FLAG_ITEM_ROUTE_115_HEAL_POWDER,
	FLAG_ITEM_NEW_MAUVILLE_ESCAPE_ROPE,
	FLAG_ITEM_GRANITE_CAVE_1F_ESCAPE_ROPE,
	FLAG_ITEM_ABANDONED_SHIP_ROOMS_B1F_ESCAPE_ROPE,
	FLAG_ITEM_ROUTE_124_YELLOW_SHARD,
	FLAG_ITEM_ROUTE_124_RED_SHARD,
	FLAG_ITEM_ROUTE_124_BLUE_SHARD,
	FLAG_ITEM_ROUTE_126_GREEN_SHARD,
	FLAG_ITEM_ROUTE_109_RARE_CANDY,
	FLAG_ITEM_ROUTE_114_RARE_CANDY,
	FLAG_ITEM_ROUTE_119_RARE_CANDY,
	FLAG_ITEM_ROUTE_132_RARE_CANDY,
	FLAG_ITEM_GRANITE_CAVE_B2F_RARE_CANDY,
	FLAG_ITEM_SHOAL_CAVE_INNER_ROOM_RARE_CANDY,
	FLAG_ITEM_MAGMA_HIDEOUT_1F_RARE_CANDY,
	FLAG_ITEM_ROUTE_127_RARE_CANDY,
	FLAG_ITEM_ROUTE_104_PP_UP,
	FLAG_ITEM_ROUTE_109_PP_UP,
	FLAG_ITEM_METEOR_FALLS_1F_1R_PP_UP,
	FLAG_ITEM_VICTORY_ROAD_1F_PP_UP,
	FLAG_ITEM_ROUTE_103_PP_UP,
	FLAG_ITEM_ROUTE_123_PP_UP,
	FLAG_ITEM_ROUTE_115_PP_UP,
	FLAG_ITEM_MAGMA_HIDEOUT_3F_2R_PP_MAX,
	FLAG_ITEM_ROUTE_112_NUGGET,
	FLAG_ITEM_ROUTE_120_NUGGET,
	FLAG_ITEM_AQUA_HIDEOUT_B1F_NUGGET,
	FLAG_ITEM_ROUTE_119_NUGGET,
	FLAG_ITEM_MAGMA_HIDEOUT_3F_1R_NUGGET,
	FLAG_ITEM_SAFARI_ZONE_NORTH_EAST_NUGGET
};

void ClearDailyFlags(void)
{
	u8 i;
	u8 usedCandies = VarGet(VAR_USED_RARE_CANDIES);
    memset(gSaveBlock1Ptr->flags + (DAILY_FLAGS_START / 8), 0, DAILY_FLAGS_SIZE);
	
	for(i = 0; i < MAX_REMATCH_ENTRIES; i++)
		gSaveBlock1Ptr->trainerRematches[i] = 1;
	
	for(i = 0; i < sizeof(FindItemFlags) ; i++){
		if(Random() % 10 < 3)
			FlagClear(FindItemFlags[i]);
	}
	
	if(usedCandies <= 5)
		VarSet(VAR_USED_RARE_CANDIES, usedCandies - 5);
}

void DisableNationalPokedex(void)
{
    u16 *nationalDexVar = GetVarPointer(VAR_NATIONAL_DEX);
    gSaveBlock2Ptr->pokedex.nationalMagic = 0;
    *nationalDexVar = 0;
    FlagClear(FLAG_SYS_NATIONAL_DEX);
}

void EnableNationalPokedex(void)
{
    u16 *nationalDexVar = GetVarPointer(VAR_NATIONAL_DEX);
    gSaveBlock2Ptr->pokedex.nationalMagic = 0xDA;
    *nationalDexVar = 0x302;
    FlagSet(FLAG_SYS_NATIONAL_DEX);
    gSaveBlock2Ptr->pokedex.mode = DEX_MODE_NATIONAL;
    gSaveBlock2Ptr->pokedex.order = 0;
    ResetPokedexScrollPositions();
}

bool32 IsNationalPokedexEnabled(void)
{
    /*/if (gSaveBlock2Ptr->pokedex.nationalMagic == 0xDA && VarGet(VAR_NATIONAL_DEX) == 0x302 && FlagGet(FLAG_SYS_NATIONAL_DEX))
        return TRUE;
    else
        return FALSE;/*/
	return TRUE;
}

void DisableMysteryEvent(void)
{
    FlagClear(FLAG_SYS_MYSTERY_EVENT_ENABLE);
}

void EnableMysteryEvent(void)
{
    FlagSet(FLAG_SYS_MYSTERY_EVENT_ENABLE);
}

bool32 IsMysteryEventEnabled(void)
{
    return FlagGet(FLAG_SYS_GAME_CLEAR);
}

void DisableMysteryGift(void)
{
    FlagClear(FLAG_SYS_MYSTERY_GIFT_ENABLE);
}

void EnableMysteryGift(void)
{
    FlagSet(FLAG_SYS_MYSTERY_GIFT_ENABLE);
}

bool32 IsMysteryGiftEnabled(void)
{
    //return FlagGet(FLAG_SYS_MYSTERY_GIFT_ENABLE);
	return TRUE;
}

void ClearMysteryEventFlags(void)
{
    FlagClear(FLAG_MYSTERY_EVENT_DONE);
    FlagClear(FLAG_MYSTERY_EVENT_1);
    FlagClear(FLAG_MYSTERY_EVENT_2);
    FlagClear(FLAG_MYSTERY_EVENT_3);
    FlagClear(FLAG_MYSTERY_EVENT_4);
    FlagClear(FLAG_MYSTERY_EVENT_5);
    FlagClear(FLAG_MYSTERY_EVENT_6);
    FlagClear(FLAG_MYSTERY_EVENT_7);
    FlagClear(FLAG_MYSTERY_EVENT_8);
    FlagClear(FLAG_MYSTERY_EVENT_9);
    FlagClear(FLAG_MYSTERY_EVENT_10);
    FlagClear(FLAG_MYSTERY_EVENT_11);
    FlagClear(FLAG_MYSTERY_EVENT_12);
    FlagClear(FLAG_MYSTERY_EVENT_13);
    FlagClear(FLAG_MYSTERY_EVENT_14);
    FlagClear(FLAG_MYSTERY_EVENT_15);
}

void ClearMysteryEventVars(void)
{
    VarSet(VAR_EVENT_PICHU_SLOT, 0);
    VarSet(VAR_NEVER_READ_0x40DE, 0);
    VarSet(VAR_NEVER_READ_0x40DF, 0);
    VarSet(VAR_NEVER_READ_0x40E0, 0);
    VarSet(VAR_NEVER_READ_0x40E1, 0);
    VarSet(VAR_NEVER_READ_0x40E2, 0);
    VarSet(VAR_NEVER_READ_0x40E3, 0);
    VarSet(VAR_NEVER_READ_0x40E4, 0);
}

void DisableResetRTC(void)
{
    VarSet(VAR_RESET_RTC_ENABLE, 0);
    FlagClear(FLAG_SYS_RESET_RTC_ENABLE);
}

void EnableResetRTC(void)
{
    VarSet(VAR_RESET_RTC_ENABLE, 0x920);
    FlagSet(FLAG_SYS_RESET_RTC_ENABLE);
}

bool32 CanResetRTC(void)
{
    if (FlagGet(FLAG_SYS_RESET_RTC_ENABLE) && VarGet(VAR_RESET_RTC_ENABLE) == 0x920)
        return TRUE;
    else
        return FALSE;
}

u16 *GetVarPointer(u16 id)
{
    if (id < VARS_START)
        return NULL;
    else if (id < SPECIAL_VARS_START)
        return &gSaveBlock1Ptr->vars[id - VARS_START];
    else
        return gSpecialVars[id - SPECIAL_VARS_START];
}

u16 VarGet(u16 id)
{
    u16 *ptr = GetVarPointer(id);
    if (!ptr)
        return id;
    return *ptr;
}

u16 VarGetIfExist(u16 id)
{
    u16 *ptr = GetVarPointer(id);
    if (!ptr)
        return 65535;
    return *ptr;
}

bool8 VarSet(u16 id, u16 value)
{
    u16 *ptr = GetVarPointer(id);
    if (!ptr)
        return FALSE;
    *ptr = value;
    return TRUE;
}

u16 VarGetObjectEventGraphicsId(u8 id)
{
    return VarGet(VAR_OBJ_GFX_ID_0 + id);
}

u8 *GetFlagPointer(u16 id)
{
    if (id == 0)
        return NULL;
    else if (id < SPECIAL_FLAGS_START)
        return &gSaveBlock1Ptr->flags[id / 8];
    else
        return &gSpecialFlags[(id - SPECIAL_FLAGS_START) / 8];
}

u8 FlagSet(u16 id)
{
    u8 *ptr = GetFlagPointer(id);
    if (ptr)
        *ptr |= 1 << (id & 7);
    return 0;
}

u8 FlagToggle(u16 id)
{
    u8 *ptr = GetFlagPointer(id);
    if (ptr)
        *ptr ^= 1 << (id & 7);
    return 0;
}

u8 FlagClear(u16 id)
{
    u8 *ptr = GetFlagPointer(id);
    if (ptr)
        *ptr &= ~(1 << (id & 7));
    return 0;
}

bool8 FlagGet(u16 id)
{
    u8 *ptr = GetFlagPointer(id);

    if (!ptr)
        return FALSE;

    if (!(((*ptr) >> (id & 7)) & 1))
        return FALSE;

    return TRUE;
}
