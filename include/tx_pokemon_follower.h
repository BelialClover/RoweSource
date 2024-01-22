#ifndef GUARD_TX_POKEMON_FOLLOWER
#define GUARD_TX_POKEMON_FOLLOWER

#include "constants/tx_pokemon_follower.h"

#define DEFAULT_FOLLOWER_LOCAL_ID 0xFE
#define MOVEMENT_INVALID 0xFE

enum FollowerSpriteTypes
{
    FOLLOWER_SPRITE_INDEX_NORMAL,
    FOLLOWER_SPRITE_INDEX_MACH_BIKE,
    FOLLOWER_SPRITE_INDEX_ACRO_BIKE,
    FOLLOWER_SPRITE_INDEX_SURF,
    FOLLOWER_SPRITE_INDEX_UNDERWATER,
};

// Exported Functions
void POF_DestroyFollower(void);
bool8 POF_FollowerComingThroughDoor(void);

u8 POF_GetFollowerObjectId(void);
const u8* POF_GetFollowerScriptPointer(void);
void POF_FollowerHide(void);
void POF_IsFollowerStoppingRockClimb(void);
void POF_FollowMe_SetIndicatorToComeOutDoor(void);
void POF_FollowMe_TryRemoveFollowerOnWhiteOut(void);
void POF_FollowMe(struct ObjectEvent* npc, u8 state, bool8 ignoreScriptActive);
void POF_FollowMe_Ledges(struct ObjectEvent* npc, struct Sprite* obj, u16* ledgeFramesTbl);
bool8 POF_FollowMe_IsCollisionExempt(struct ObjectEvent* obstacle, struct ObjectEvent* collider);
void POF_FollowMe_FollowerToWater(void);
void POF_StairsMoveFollower(void);
void POF_FollowMe_HandleBike(void);
void POF_FollowMe_HandleSprite(void);
void POF_FollowMe_WarpSetEnd(void);
void POF_CreateFollowerAvatar(void);
void POF_EscalatorMoveFollower(u8 movementType);
void POF_EscalatorMoveFollowerFinish(void);
bool8 POF_CheckFollowerFlag(u16 flag);
void POF_FollowerPositionFix(u8 offset);
void POF_SetFollowerSprite(u8 spriteIndex);
bool8 POF_PlayerHasFollower(void);
void POF_CreateMonFromPartySlotId(void);
void POF_FollowerUnhide(void);
u8 POF_GetFollowerSlotId(void);
void POF_SetFollowerSlotId(u8 slotId);
bool8 POF_IsFollowerSlotId(u8 slotId);
bool8 POF_IsFollowerAlive(void);
bool8 POF_IsFollowerAliveAndWell(void);
// moved from field_screen_effect.c
void POF_Task_DoDoorWarp(u8 taskId);
bool8 POF_IsPlayerOnFoot(void);
void POF_ForceToggleFollower(void);
bool8 CanMonFollow(u16 species);
u8 POF_ChoseAutomaticFollower(void);

static u8 POF_GetFollowerMapObjId(void);
struct ObjectEvent * GetFollowerObject(void);

void POF_ToggleFollower(void);
void POF_MoveFollowerToPlayer(void);
void POF_SetAutomaticFollow(void);

static const u16 gSpeciesLookUpTable[] = 
{
    [SPECIES_TREECKO] = 252,
    [SPECIES_GROVYLE] = 253,
    [SPECIES_SCEPTILE] = 254,
    [SPECIES_TORCHIC] = 255,
    [SPECIES_COMBUSKEN] = 256,
    [SPECIES_BLAZIKEN] = 257,
    [SPECIES_MUDKIP] = 258,
    [SPECIES_MARSHTOMP] = 259,
    [SPECIES_SWAMPERT] = 260,
    [SPECIES_POOCHYENA] = 261,
    [SPECIES_MIGHTYENA] = 262,
    [SPECIES_ZIGZAGOON] = 263,
    [SPECIES_LINOONE] = 264,
    [SPECIES_WURMPLE] = 265,
    [SPECIES_SILCOON] = 266,
    [SPECIES_BEAUTIFLY] = 267,
    [SPECIES_CASCOON] = 268,
    [SPECIES_DUSTOX] = 269,
    [SPECIES_LOTAD] = 270,
    [SPECIES_LOMBRE] = 271,
    [SPECIES_LUDICOLO] = 272,
    [SPECIES_SEEDOT] = 273,
    [SPECIES_NUZLEAF] = 274,
    [SPECIES_SHIFTRY] = 275,
    [SPECIES_TAILLOW] = 276,
    [SPECIES_SWELLOW] = 277,
    [SPECIES_WINGULL] = 278,
    [SPECIES_PELIPPER] = 279,
    [SPECIES_RALTS] = 280,
    [SPECIES_KIRLIA] = 281,
    [SPECIES_GARDEVOIR] = 282,
    [SPECIES_SURSKIT] = 283,
    [SPECIES_MASQUERAIN] = 284,
    [SPECIES_SHROOMISH] = 285,
    [SPECIES_BRELOOM] = 286,
    [SPECIES_SLAKOTH] = 287,
    [SPECIES_VIGOROTH] = 288,
    [SPECIES_SLAKING] = 289,
    [SPECIES_NINCADA] = 290,
    [SPECIES_NINJASK] = 291,
    [SPECIES_SHEDINJA] = 292,
    [SPECIES_WHISMUR] = 293,
    [SPECIES_LOUDRED] = 294,
    [SPECIES_EXPLOUD] = 295,
    [SPECIES_MAKUHITA] = 296,
    [SPECIES_HARIYAMA] = 297,
    [SPECIES_AZURILL] = 298,
    [SPECIES_NOSEPASS] = 299,
    [SPECIES_SKITTY] = 300,
    [SPECIES_DELCATTY] = 301,
    [SPECIES_SABLEYE] = 302,
    [SPECIES_MAWILE] = 303,
    [SPECIES_ARON] = 304,
    [SPECIES_LAIRON] = 305,
    [SPECIES_AGGRON] = 306,
    [SPECIES_MEDITITE] = 307,
    [SPECIES_MEDICHAM] = 308,
    [SPECIES_ELECTRIKE] = 309,
    [SPECIES_MANECTRIC] = 310,
    [SPECIES_PLUSLE] = 311,
    [SPECIES_MINUN] = 312,
    [SPECIES_VOLBEAT] = 313,
    [SPECIES_ILLUMISE] = 314,
    [SPECIES_ROSELIA] = 315,
    [SPECIES_GULPIN] = 316,
    [SPECIES_SWALOT] = 317,
    [SPECIES_CARVANHA] = 318,
    [SPECIES_SHARPEDO] = 319,
    [SPECIES_WAILMER] = 320,
    [SPECIES_WAILORD] = 321,
    [SPECIES_NUMEL] = 322,
    [SPECIES_CAMERUPT] = 323,
    [SPECIES_TORKOAL] = 324,
    [SPECIES_SPOINK] = 325,
    [SPECIES_GRUMPIG] = 326,
    [SPECIES_SPINDA] = 327,
    [SPECIES_TRAPINCH] = 328,
    [SPECIES_VIBRAVA] = 329,
    [SPECIES_FLYGON] = 330,
    [SPECIES_CACNEA] = 331,
    [SPECIES_CACTURNE] = 332,
    [SPECIES_SWABLU] = 333,
    [SPECIES_ALTARIA] = 334,
    [SPECIES_ZANGOOSE] = 335,
    [SPECIES_SEVIPER] = 336,
    [SPECIES_LUNATONE] = 337,
    [SPECIES_SOLROCK] = 338,
    [SPECIES_BARBOACH] = 339,
    [SPECIES_WHISCASH] = 340,
    [SPECIES_CORPHISH] = 341,
    [SPECIES_CRAWDAUNT] = 342,
    [SPECIES_BALTOY] = 343,
    [SPECIES_CLAYDOL] = 344,
    [SPECIES_LILEEP] = 345,
    [SPECIES_CRADILY] = 346,
    [SPECIES_ANORITH] = 347,
    [SPECIES_ARMALDO] = 348,
    [SPECIES_FEEBAS] = 349,
    [SPECIES_MILOTIC] = 350,
    [SPECIES_CASTFORM] = 351,
    [SPECIES_KECLEON] = 352,
    [SPECIES_SHUPPET] = 353,
    [SPECIES_BANETTE] = 354,
    [SPECIES_DUSKULL] = 355,
    [SPECIES_DUSCLOPS] = 356,
    [SPECIES_TROPIUS] = 357,
    [SPECIES_CHIMECHO] = 358,
    [SPECIES_ABSOL] = 359,
    [SPECIES_WYNAUT] = 360,
    [SPECIES_SNORUNT] = 361,
    [SPECIES_GLALIE] = 362,
    [SPECIES_SPHEAL] = 363,
    [SPECIES_SEALEO] = 364,
    [SPECIES_WALREIN] = 365,
    [SPECIES_CLAMPERL] = 366,
    [SPECIES_HUNTAIL] = 367,
    [SPECIES_GOREBYSS] = 368,
    [SPECIES_RELICANTH] = 369,
    [SPECIES_LUVDISC] = 370,
    [SPECIES_BAGON] = 371,
    [SPECIES_SHELGON] = 372,
    [SPECIES_SALAMENCE] = 373,
    [SPECIES_BELDUM] = 374,
    [SPECIES_METANG] = 375,
    [SPECIES_METAGROSS] = 376,
    [SPECIES_REGIROCK] = 377,
    [SPECIES_REGICE] = 378,
    [SPECIES_REGISTEEL] = 379,
    [SPECIES_LATIAS] = 380,
    [SPECIES_LATIOS] = 381,
    [SPECIES_KYOGRE] = 382,
    [SPECIES_GROUDON] = 383,
    [SPECIES_RAYQUAZA] = 384,
    [SPECIES_JIRACHI] = 385,
    [SPECIES_DEOXYS] = 386,
};

#endif
