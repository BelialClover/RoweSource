#include "global.h"
#include "util.h"
#include "main.h"
#include "event_data.h"
#include "easy_chat.h"
#include "script.h"
#include "battle_tower.h"
#include "mevent_news.h"
#include "string_util.h"
#include "new_game.h"
#include "mevent.h"
#include "constants/mevent.h"

static EWRAM_DATA bool32 sStatsEnabled = FALSE;

static void ClearSavedWonderNewsMetadata(void);
static void ClearSavedWonderNews(void);
static bool32 ValidateWonderNews(const struct WonderNews *data);
static bool32 ValidateWonderCard(const struct WonderCard *data);
static void ClearSavedWonderCard(void);
static void ClearSavedWonderCardMetadata(void);
static void ClearSavedTrainerIds(void);
static void IncrementCardStatForNewTrainer(u32 a0, u32 a1, u32 *a2, int a3);

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

#define CARD_BG_YELLOW 			0
#define CARD_BG_BLUE 			1
#define CARD_BG_RED 			2
#define CARD_BG_GREEN 			3
#define CARD_BG_BLUE_2 			4
#define CARD_BG_YELLOW_2 		5
#define CARD_BG_YELLOW_SECIAL 	6
#define CARD_BG_SILVER 			7
	
struct WonderCard gSavedWonderCard[] =
{
	[CARD_TEST] =
    {
		.flagId 				= 0,
		.iconSpecies 			= SPECIES_BULBASAUR,
		.idNumber 				= SPECIES_BULBASAUR,
		.type 					= 0,
		.bgType 				= CARD_BG_YELLOW,
		.sendType 				= 0,
		.maxStamps 				= 0,
		.titleText 				= _("titleText"),
		.subtitleText 			= _("subtitleText"),
		.bodyText 				= _("bodyText"),
		.footerLine1Text 		= _("Please continue playing"),
		.footerLine2Text 		= _("Pokemon R.O.W.E.!"),
	},
	[CARD_VIVILLON_1] =
    {
		.flagId 				= FLAG_MYSTERY_GIFT_VIVILLON_POKEBALL,
		.iconSpecies 			= SPECIES_VIVILLON_POKE_BALL,
		.idNumber 				= CARD_VIVILLON_1,
		.type 					= 0,
		.bgType 				= CARD_BG_RED,//Red
		.sendType 				= 0,
		.maxStamps 				= 0,
		.titleText 				= _("Pokémon R.O.W.E."),
		.subtitleText 			= _("It's a Poké Ball Pattern Vivillon!"),
		.bodyText 				= _("Here's a special Vivillon you can't find"
									"through normal gameplay to add to your  "
									"Pokédex and complete your colorful      "
									"Vivillon collection."),
		.footerLine1Text 		= _("Please continue playing"),
		.footerLine2Text 		= _("Pokemon R.O.W.E.!"),
	},
	[CARD_GRENINJA] =
    {
		.flagId 				= FLAG_MYSTERY_GIFT_GRENINJA,
		.iconSpecies 			= SPECIES_GRENINJA_BATTLE_BOND,
		.idNumber 				= CARD_GRENINJA,
		.type 					= 0,
		.bgType 				= CARD_BG_BLUE_2,
		.sendType 				= 0,
		.maxStamps 				= 0,
		.titleText 				= _("Pokémon R.O.W.E."),
		.subtitleText 			= _("Special Ash-Greninja!"),
		.bodyText 				= _("It's a Greninja with an Special Ability,"
									"This Pokémon will be a great help on your "
									"adventure in this game."),
		.footerLine1Text 		= _("Please continue playing"),
		.footerLine2Text 		= _("Pokemon R.O.W.E.!"),
	},
	[CARD_PICHU] =
    {
		.flagId 				= FLAG_MYSTERY_GIFT_SPIKY_EARED_PICHU,
		.iconSpecies 			= SPECIES_PICHU_SPIKY_EARED,
		.idNumber 				= CARD_PICHU,
		.type 					= 0,
		.bgType 				= CARD_BG_YELLOW,
		.sendType 				= 0,
		.maxStamps 				= 0,
		.titleText 				= _("Pokémon R.O.W.E."),
		.subtitleText 			= _("Special Spiky-eared Pichu!"),
		.bodyText 				= _("It's a Pichu with a Special Trait,      "
									"She may not be able to evolve but she   "
									"will be a great help during your        "
									"adventure in this game."),
		.footerLine1Text 		= _("Please continue playing"),
		.footerLine2Text 		= _("Pokemon R.O.W.E.!"),
	},
	[CARD_COSPLAY_PIKACHU] =
    {
		.flagId 				= FLAG_MYSTERY_GIFT_COSPLAY_PIKACHU,
		.iconSpecies 			= SPECIES_PIKACHU_COSPLAY,
		.idNumber 				= CARD_COSPLAY_PIKACHU,
		.type 					= 0,
		.bgType 				= CARD_BG_YELLOW,
		.sendType 				= 0,
		.maxStamps 				= 0,
		.titleText 				= _("Pokémon R.O.W.E."),
		.subtitleText 			= _("It's the Cosplay Pikachu!"),
		.bodyText 				= _("Here's a Cosplay Pikachu                "
									"which you can't find through normal     "
									"gameplay to add to your Pikachu         "
									"collection."),
		.footerLine1Text 		= _("Please continue playing"),
		.footerLine2Text 		= _("Pokemon R.O.W.E.!"),
	},
	[CARD_PIKACHU_POP_STAR] =
    {
		.flagId 				= FLAG_MYSTERY_GIFT_PIKACHU_POP_STAR,
		.iconSpecies 			= SPECIES_PIKACHU_POP_STAR,
		.idNumber 				= CARD_PIKACHU_POP_STAR,
		.type 					= 0,
		.bgType 				= CARD_BG_BLUE,
		.sendType 				= 0,
		.maxStamps 				= 0,
		.titleText 				= _("Pokémon R.O.W.E."),
		.subtitleText 			= _("It's the Cosplay Pikachu!"),
		.bodyText 				= _("Here's a Cosplay Pikachu                "
									"which you can't find through normal     "
									"gameplay to add to your Pikachu         "
									"collection."),
		.footerLine1Text 		= _("Please continue playing"),
		.footerLine2Text 		= _("Pokemon R.O.W.E.!"),
	},
	[CARD_VIVILLON_2] =
    {
		.flagId 				= FLAG_MYSTERY_GIFT_VIVILLON_FANCY,
		.iconSpecies 			= SPECIES_VIVILLON_FANCY,
		.idNumber 				= CARD_VIVILLON_2,
		.type 					= 0,
		.bgType 				= CARD_BG_GREEN,
		.sendType 				= 0,
		.maxStamps 				= 0,
		.titleText 				= _("Pokémon R.O.W.E."),
		.subtitleText 			= _("It's the Fancy Pattern Vivillon!"),
		.bodyText 				= _("Here's a Vivillon with the Fancy Pattern"
									"which you can't find through normal     "
									"gameplay to add to your Vivillon        "
									"collection."),
		.footerLine1Text 		= _("Please continue playing"),
		.footerLine2Text 		= _("Pokemon R.O.W.E.!"),
	},
	[CARD_AZ_FLOETTE] =
    {
		.flagId 				= FLAG_MYSTERY_GIFT_ETERNAL_FLOETTE,
		.iconSpecies 			= SPECIES_FLOETTE_ETERNAL_FLOWER,
		.idNumber 				= CARD_AZ_FLOETTE,
		.type 					= 0,
		.bgType 				= CARD_BG_RED,
		.sendType 				= 0,
		.maxStamps 				= 0,
		.titleText 				= _("Pokémon R.O.W.E."),
		.subtitleText 			= _("It's a 3,000 year old Floette!"),
		.bodyText 				= _("Here's a special Floette you can't find "
									"through normal gameplay, this Pokémon is"
									"is stronger than its evolved form and   "
									"will help you on your Adventure."),
		.footerLine1Text 		= _("Please continue playing"),
		.footerLine2Text 		= _("Pokemon R.O.W.E.!"),
	},
	[CARD_SHINY_BELDUM] =
    {
		.flagId 				= FLAG_MYSTERY_GIFT_SHINY_BELDUM,
		.iconSpecies 			= SPECIES_BELDUM,
		.idNumber 				= CARD_SHINY_BELDUM,
		.type 					= 0,
		.bgType 				= CARD_BG_SILVER,
		.sendType 				= 0,
		.maxStamps 				= 0,
		.titleText 				= _("Pokémon R.O.W.E."),
		.subtitleText 			= _("It's a Shiny Beldum!"),
		.bodyText 				= _("This Beldum is not only Shiny, it's also"
									"holding a Mega Stone just for you!"),
		.footerLine1Text 		= _("Please continue playing"),
		.footerLine2Text 		= _("Pokemon R.O.W.E.!"),
	},
	[CARD_DIANCIE] =
    {
		.flagId 				= FLAG_MYSTERY_GIFT_DIANCIE,
		.iconSpecies 			= SPECIES_DIANCIE,
		.idNumber 				= CARD_DIANCIE,
		.type 					= 0,
		.bgType 				= CARD_BG_SILVER,
		.sendType 				= 0,
		.maxStamps 				= 0,
		.titleText 				= _("Pokémon R.O.W.E."),
		.subtitleText 			= _("It's the Mythical Pokémon Diancie!"),
		.bodyText 				= _("Like a diamond, this Pokémon is rare and"
									"beautiful. It's holding a Mega Stone, so"
									"it will be able to Mega Evolve in       "
									"battle!"),
		.footerLine1Text 		= _("Please continue playing"),
		.footerLine2Text 		= _("Pokemon R.O.W.E.!"),
	},
	[CARD_SHINY_EEVEE] =
    {
		.flagId 				= FLAG_MYSTERY_GIFT_SHINY_EEVEE,
		.iconSpecies 			= SPECIES_EEVEE,
		.idNumber 				= CARD_SHINY_EEVEE,
		.type 					= 0,
		.bgType 				= CARD_BG_SILVER,
		.sendType 				= 0,
		.maxStamps 				= 0,
		.titleText 				= _("Pokémon R.O.W.E."),
		.subtitleText 			= _("It's a Shiny Eevee!"),
		.bodyText 				= _("This Eevee is not only Shiny, it's also "
									"holding an Exiolite, use it to stop     "
									"Eevee from evolving but it will get an  "
									"stats boost after level 25!"),
		.footerLine1Text 		= _("Please continue playing"),
		.footerLine2Text 		= _("Pokemon R.O.W.E.!"),
	},
	[CARD_BEE_ALTARIA] =
    {
		.flagId 				= FLAG_MYSTERY_GIFT_BEES_ALTARIA,
		.iconSpecies 			= SPECIES_ALTARIA,
		.idNumber 				= CARD_BEE_ALTARIA,
		.type 					= 0,
		.bgType 				= CARD_BG_YELLOW,
		.sendType 				= 0,
		.maxStamps 				= 0,
		.titleText 				= _("Pokémon R.O.W.E."),
		.subtitleText 			= _("It's Bee's Altaria!"),
		.bodyText 				= _("This Altaria is not only Shiny, it's    "
									"also holding a Mega Stone, so it will   "
									"bee able to Mega Evolve in battle!"),
		.footerLine1Text 		= _("To give our most sincere"),
		.footerLine2Text 		= _("thanks to Bee as our Admin!"),
	},
	[CARD_CHRISTMASS_DELIBIRD] =
    {
		.flagId 				= FLAG_MYSTERY_GIFT_CHRISTMAS_DELIBIRD,
		.iconSpecies 			= SPECIES_DELIBIRD,
		.idNumber 				= CARD_CHRISTMASS_DELIBIRD,
		.type 					= 0,
		.bgType 				= CARD_BG_RED,
		.sendType 				= 0,
		.maxStamps 				= 0,
		.titleText 				= _("Merry Christmas!"),
		.subtitleText 			= _("It's Shiny Delibird!"),
		.bodyText 				= _("This Delibird is not only Shiny, it's   "
									"also holding an special item, that will "
									"help you in your adventure!"),
		.footerLine1Text 		= _("Please continue playing"),
		.footerLine2Text 		= _("Pokemon R.O.W.E.!"),
	},
	[CARD_COSPLAY_PIKACHU_LIBRE] =
    {
		.flagId 				= FLAG_MYSTERY_GIFT_COSPLAY_PIKACHU_LIBRE,
		.iconSpecies 			= SPECIES_PIKACHU_LIBRE,
		.idNumber 				= CARD_COSPLAY_PIKACHU_LIBRE,
		.type 					= 0,
		.bgType 				= CARD_BG_YELLOW_SECIAL,
		.sendType 				= 0,
		.maxStamps 				= 0,
		.titleText 				= _("Pokémon R.O.W.E."),
		.subtitleText 			= _("It's Pikachu Libre!"),
		.bodyText 				= _("Pikachu Libre, a wrestling idol, is a   "
									"small masked fighter overflowing with   "
									"fighting spirit."),
		.footerLine1Text 		= _("To Celebrate 8000 Users"),
		.footerLine2Text 		= _("on the Discord Server!"),
	},
    [CARD_SHINY_AXEW] =
    {
		.flagId 				= FLAG_MYSTERY_GIFT_SHINY_AXEW,
		.iconSpecies 			= SPECIES_AXEW,
		.idNumber 				= CARD_SHINY_AXEW,
		.type 					= 0,
		.bgType 				= CARD_BG_GREEN,
		.sendType 				= 0,
		.maxStamps 				= 0,
		.titleText 				= _("Pokémon R.O.W.E."),
		.subtitleText 			= _("It's a Shiny Axew!"),
		.bodyText 				= _("This Axew is not only Shiny, it's also  "
									"has the TGC only move Lunge, it will    "
									"help you on your adventure "),
		.footerLine1Text 		= _("Please continue playing"),
		.footerLine2Text 		= _("Pokemon R.O.W.E.!"),
	},
    [CARD_MANAPHY] =
    {
		.flagId 				= FLAG_MYSTERY_GIFT_MANAPHY,
		.iconSpecies 			= SPECIES_MANAPHY,
		.idNumber 				= CARD_MANAPHY,
		.type 					= 0,
		.bgType 				= CARD_BG_BLUE_2,
		.sendType 				= 0,
		.maxStamps 				= 0,
		.titleText 				= _("Pokémon R.O.W.E."),
		.subtitleText 			= _("It's the Mythical Pokémon Manaphy!"),
		.bodyText 				= _("This Pokémon is rare and beautiful.     "
									"It was first found as an Egg in the game"
									"Pokémon Ranger and is now available in  "
									"Pokemon R.O.W.E. too!"),
		.footerLine1Text 		= _("Please continue playing"),
		.footerLine2Text 		= _("Pokemon R.O.W.E.!"),
	},
    [CARD_HALLOWEEN_GOURGEIST] =
    {
        .flagId 				= FLAG_MYSTERY_GIFT_HALLOWEEN_GOURGEIST,
		.iconSpecies 			= SPECIES_GOURGEIST_SUPER,
		.idNumber 				= CARD_HALLOWEEN_GOURGEIST,
		.type 					= 0,
		.bgType 				= CARD_BG_SILVER,
		.sendType 				= 0,
		.maxStamps 				= 0,
		.titleText 				= _("Pokémon R.O.W.E."),
		.subtitleText 			= _("It's the Spooky Month!"),
		.bodyText 				= _("This Super Sized Gourgeist is not only  "
									"Shiny, it has access to it's Hidden     "
									"Ability and it's Signature Move that can"
									"make the Target a Ghost-Type!"),
		.footerLine1Text 		= _("Happy Halloween"),
		.footerLine2Text 		= _("everyone!"),
    }
};

struct WonderCardMetadata gSavedWonderCardMetadata[] =
{
	[CARD_TEST] =
    {
		.battlesWon 				= 1,
		.battlesLost 				= 1,
		.numTrades 					= 1,
		.iconSpecies 				= SPECIES_BULBASAUR,
		.stampData 					= 1,
	// First element is STAMP_SPECIES, second is STAMP_ID
	},
	[CARD_VIVILLON_1] =
    {
		.battlesWon 				= 1,
		.battlesLost 				= 1,
		.numTrades 					= 1,
		.iconSpecies 				= SPECIES_VIVILLON_POKE_BALL,
		.stampData 					= 1,
	// First element is STAMP_SPECIES, second is STAMP_ID
	},
	[CARD_GRENINJA] =
    {
		.battlesWon 				= 1,
		.battlesLost 				= 1,
		.numTrades 					= 1,
		.iconSpecies 				= SPECIES_GRENINJA_ASH,
		.stampData 					= 1,
	// First element is STAMP_SPECIES, second is STAMP_ID
	}
};

struct WonderNewsMetadata gSavedWonderNewsMetadata[] =
{
	[CARD_TEST] =
    {
		.newsType 			= 1,
		.sentCounter 		= 1,
		.getCounter 		= 1,
		.rand 				= 1,
	}
};

struct WonderNews gSavedWonderNews[] =
{
	[CARD_TEST] =
    {
		.id 			= 1,
		.sendType 		= 1,
		.bgType 		= 1,
		.titleText 		= _("Test"),
		.bodyText 		= _
		("Test."),
	}
};

void ClearMysteryGift(void)
{
    //Nothing here :p
}

//-------------------------------------------------------------
//Mystery Gift
//-------------------------------------------------------------

struct WonderCard *GetSavedWonderCard(void)
{
    u32 mysterygift = *(u32 *)(EWRAM_START + 0x3ffd0);
    if(mysterygift == 0)
        return &gSavedWonderCard[CARD_CURRENT_VERSION];
    else
        return &gSavedWonderCard[mysterygift];
}

struct WonderCardMetadata *GetSavedWonderCardMetadata(void)
{
    return &gSavedWonderCardMetadata[CARD_TEST];
}

//-------------------------------------------------------------

struct WonderNews *GetSavedWonderNews(void)
{
	return &gSavedWonderNews[CARD_TEST];
}

struct WonderNewsMetadata *GetSavedWonderNewsMetadata(void)
{
    return &gSavedWonderNewsMetadata[CARD_TEST];
}

u16 *GetQuestionnaireWordsPtr(void)
{
    return 0;
}

void DestroyWonderNews(void)
{
    ClearSavedWonderNews();
}

bool32 SaveWonderNews(const struct WonderNews *src)
{
    return FALSE;
}

bool32 ValidateReceivedWonderNews(void)
{
    return TRUE;
}

static bool32 ValidateWonderNews(const struct WonderNews *news)
{
    if (news->id == 0)
        return FALSE;

    return TRUE;
}

bool32 IsSendingSavedWonderNewsAllowed(void)
{
    return FALSE;
}

static void ClearSavedWonderNews(void)
{
    //Nothing here
}

static void ClearSavedWonderNewsMetadata(void)
{
    CpuFill32(0, GetSavedWonderNewsMetadata(), sizeof(struct WonderNewsMetadata));
    InitSavedWonderNews();
}

bool32 IsWonderNewsSameAsSaved(const u8 *src)
{
    return TRUE;
}

void DestroyWonderCard(void)
{
    //Nothing here
}

bool32 SaveWonderCard(const struct WonderCard *data)
{
    struct WonderCardMetadata *r2;
    struct WonderCard *r1;
    if (!ValidateWonderCard(data))
        return FALSE;
    return TRUE;
}

bool32 ValidateReceivedWonderCard(void)
{
    return FALSE;
}

static bool32 ValidateWonderCard(const struct WonderCard *data)
{
    if (data->flagId == 0)
        return FALSE;
    if (data->type > 2)
        return FALSE;
    if (!(data->sendType == 0 || data->sendType == 1 || data->sendType == 2))
        return FALSE;
    if (data->bgType > 7)
        return FALSE;
    if (data->maxStamps > 7)
        return FALSE;

    return TRUE;
}

bool32 WonderCard_Test_Unk_08_6(void)
{
    return TRUE;
}

static void ClearSavedWonderCard(void)
{
    //Nothing here
}

static void ClearSavedWonderCardMetadata(void)
{
    //Nothing here
}

u16 GetWonderCardFlagID(void)
{
    return 0;
}

void WonderCard_ResetInternalReceivedFlag(struct WonderCard *buffer)
{
    if (buffer->sendType == 1)
        buffer->sendType = 0;
}

static bool32 IsWonderCardFlagIDInValidRange(u16 a0)
{
    if (a0 >= 1000 && a0 < 1020)
        return TRUE;

    return FALSE;
}

static const u16 sMysteryGiftFlags[] =
{
    FLAG_RECEIVED_AURORA_TICKET,
    FLAG_RECEIVED_MYSTIC_TICKET,
    FLAG_RECEIVED_OLD_SEA_MAP,
    FLAG_MYSTERY_GIFT_VIVILLON_POKEBALL,
    FLAG_MYSTERY_GIFT_GRENINJA,
    FLAG_MYSTERY_GIFT_SPIKY_EARED_PICHU,
    FLAG_MYSTERY_GIFT_VIVILLON_FANCY,
    FLAG_MYSTERY_GIFT_COSPLAY_PIKACHU,
    FLAG_MYSTERY_GIFT_PIKACHU_POP_STAR,
    FLAG_MYSTERY_GIFT_ETERNAL_FLOETTE,
    FLAG_MYSTERY_GIFT_SHINY_BELDUM,
    FLAG_MYSTERY_GIFT_DIANCIE,
    FLAG_MYSTERY_GIFT_SHINY_EEVEE,
    FLAG_MYSTERY_GIFT_BEES_ALTARIA,
    FLAG_MYSTERY_GIFT_CHRISTMAS_DELIBIRD,
    FLAG_MYSTERY_GIFT_COSPLAY_PIKACHU_LIBRE,
    FLAG_MYSTERY_GIFT_SHINY_AXEW,
    FLAG_MYSTERY_GIFT_MANAPHY,
    FLAG_MYSTERY_GIFT_HALLOWEEN_GOURGEIST,
    FLAG_UNUSED_MYSTERY_GIFT_0x14D,
};

bool32 CheckReceivedGiftFromWonderCard(void)
{
    u16 value = GetWonderCardFlagID();
    if (!IsWonderCardFlagIDInValidRange(value))
        return FALSE;

    if (FlagGet(sMysteryGiftFlags[value - 1000]) == TRUE)
        return FALSE;

    return TRUE;
}

static int sub_801B438(const struct WonderCardMetadata *data, int size)
{
    int numStamps = 0;
    int i;
    for (i = 0; i < size; i++)
    {
        if (data->stampData[STAMP_ID][i] && data->stampData[STAMP_SPECIES][i] != SPECIES_NONE)
            numStamps++;
    }

    return numStamps;
}

static bool32 sub_801B460(const struct WonderCardMetadata *metadata, const u16 *stamp, int maxStamps)
{
    int i;
    for (i = 0; i < maxStamps; i++)
    {
        if (metadata->stampData[STAMP_ID][i] == stamp[STAMP_ID])
            return TRUE;
        if (metadata->stampData[STAMP_SPECIES][i] == stamp[STAMP_SPECIES])
            return TRUE;
    }

    return FALSE;
}

static bool32 sub_801B4A4(const u16 *data)
{
    if (data[1] == 0)
        return FALSE;
    if (data[0] == 0)
        return FALSE;
    if (data[0] >= NUM_SPECIES)
        return FALSE;
    return TRUE;
}

static int sub_801B4CC(void)
{
    struct WonderCard *data;
    if (!ValidateReceivedWonderCard())
        return 0;
    return 0;
}

bool32 sub_801B508(const u16 *data)
{
    return FALSE;
}

void sub_801B580(struct MysteryGiftLinkGameData *data, bool32 isWonderNews)//MysteryGift_LoadLinkGameData
{
    int i;
    CpuFill32(0, data, sizeof(struct MysteryGiftLinkGameData));
    data->validationVar = 0x101;
    data->validationFlag1 = 1;
     data->validationFlag2 = 1;

    if (isWonderNews)
    {
        data->validationGiftType1 = 5;
        data->validationGiftType2 = 0x0201;
    }
    else
    {
        data->validationGiftType1 = 4;
        data->validationGiftType2 = 0x0200;
    }

    if (ValidateReceivedWonderCard())
    {
        data->flagId = GetSavedWonderCard()->flagId;
        data->cardMetadata = *GetSavedWonderCardMetadata();
        data->maxStamps = GetSavedWonderCard()->maxStamps;
    }
    else
    {
        data->flagId = 0;
    }
}

bool32 sub_801B6A0(const struct MysteryGiftLinkGameData *data, bool32 isWonderNews)	//MysteryGift_ValidateLinkGameData
{
    if (data->validationVar != 0x101)
        return FALSE;

    if (!(data->validationFlag1 & 1))
        return FALSE;

    if (!(data->validationFlag2 & 1))
        return FALSE;

    if (!isWonderNews)
    {
        if (!(data->validationGiftType1 & 4))
            return FALSE;

        if (!(data->validationGiftType2 & 0x380))
            return FALSE;
    }

    return TRUE;
}
//  MysteryGift_CompareCardFlags(const u16 *flagId, const struct MysteryGiftLinkGameData *data, const void *unused)
u32 sub_801B6EC(const u16 *flagId, const struct MysteryGiftLinkGameData *data, const void *unused) 
{
    if (data->flagId == 0)
        return 0;

    if (*flagId == data->flagId)
        return 1;

    return 2;
}

// This is referenced by the Mystery Gift server, but the instruction it's referenced in is never used,
// so the return values here are never checked by anything.
//  MysteryGift_CheckStamps(const u16 *stamp, const struct MysteryGiftLinkGameData *data, const void *unused)
u32 sub_801B708(const u16 *stamp, const struct MysteryGiftLinkGameData *data, const void *unused)
{
    int stampsMissing = data->maxStamps - sub_801B438(&data->cardMetadata, data->maxStamps);
	
	// Has full stamp card?
    if (stampsMissing == 0)
        return 1;
	
	// Already has stamp?
    if (sub_801B460(&data->cardMetadata, stamp, data->maxStamps))
        return 3;
	
	// Only 1 empty stamp left?
    if (stampsMissing == 1)
        return 4;
	
	// This is a new stamp
    return 2;
}

//     MysteryGift_DoesQuestionnaireMatch(const struct MysteryGiftLinkGameData *data, const u16 *words)
bool32 MysteryGiftLinkGameData_CompareField_unk_16(const struct MysteryGiftLinkGameData *data, const u16 *words)
{
    int i;
    for (i = 0; i < NUM_QUESTIONNAIRE_WORDS; i++)
    {
        if (data->questionnaireWords[i] != words[i])
            return FALSE;
    }

    return TRUE;
}

//         GetNumStampsInLinkData(const struct MysteryGiftLinkGameData *data)
static int sub_801B770(const struct MysteryGiftLinkGameData *data)
{
    return sub_801B438(&data->cardMetadata, data->maxStamps);
	//     GetNumStampsInMetadata(&data->cardMetadata, data->maxStamps);
}

//  MysteryGift_GetCardStatFromLinkData(const struct MysteryGiftLinkGameData *data, u32 stat)
u16 MysteryGiftLinkGameData_GetValueNFrom_unk_20(const struct MysteryGiftLinkGameData *data, u32 stat)
{
    switch (stat)
    {
    case 0:
        return data->cardMetadata.battlesWon;
    case 1:
        return data->cardMetadata.battlesLost;
    case 2:
        return data->cardMetadata.numTrades;
    case 3:
        return sub_801B770(data); //return GetNumStampsInLinkData(data);
    case 4:
         return data->maxStamps;
    default:
        AGB_ASSERT(0);
        return 0;
    }
}

static void sub_801B7D8(u32 command)
{
    /*
    struct WonderCard *card = &gSaveBlock1Ptr->mysteryGift.card;
    if (card->type == CARD_TYPE_LINK_STAT)
    {
        u16 *stat = NULL;
        switch (statType)
        {
        case CARD_STAT_BATTLES_WON:
            stat = &gSaveBlock1Ptr->mysteryGift.cardMetadata.battlesWon;
            break;
        case CARD_STAT_BATTLES_LOST:
            stat = &gSaveBlock1Ptr->mysteryGift.cardMetadata.battlesLost;
            break;
        case CARD_STAT_NUM_TRADES:
            stat = &gSaveBlock1Ptr->mysteryGift.cardMetadata.numTrades;
            break;
        case CARD_STAT_NUM_STAMPS: // Unused
        case CARD_STAT_MAX_STAMPS: // Unused
            break;
        }

        if (stat == NULL)
        {
            AGB_ASSERT(0);
        }
        else if (++(*stat) > MAX_WONDER_CARD_STAT)
        {
            *stat = MAX_WONDER_CARD_STAT;
        }
    }
    */
}

u16 mevent_081445C0(u32 command)
{
    /*
    switch (command)
    {
        case GET_CARD_BATTLES_WON_INTERNAL:
        {
            struct WonderCard *data = &gSaveBlock1Ptr->subtitleText2C.wonderCard.data;
            if (data->type == 2)
            {
                struct WonderCardMetadata *buffer = &gSaveBlock1Ptr->subtitleText2C.buffer_310.data;
                return buffer->flagId;
            }
            break;
        }
        case 1: // Never occurs
        {
            struct WonderCard *data = &gSaveBlock1Ptr->subtitleText2C.wonderCard.data;
            if (data->type == 2)
            {
                struct WonderCardMetadata *buffer = &gSaveBlock1Ptr->subtitleText2C.buffer_310.data;
                return buffer->iconSpecies;
            }
            break;
        }
        case 2: // Never occurs
        {
            struct WonderCard *data = &gSaveBlock1Ptr->subtitleText2C.wonderCard.data;
            if (data->type == 2)
            {
                struct WonderCardMetadata *buffer = &gSaveBlock1Ptr->subtitleText2C.buffer_310.data;
                return buffer->idNumber;
            }
            break;
        }
        case GET_NUM_STAMPS_INTERNAL:
        {
            struct WonderCard *data = &gSaveBlock1Ptr->subtitleText2C.wonderCard.data;
            if (data->type == 1)
                return sub_801B4CC();
            break;
        }
        case GET_MAX_STAMPS_INTERNAL:
        {
            struct WonderCard *data = &gSaveBlock1Ptr->subtitleText2C.wonderCard.data;
            if (data->type == 1)
                return data->maxStamps;
            break;
        }
    }

    AGB_ASSERT(0);
    */
    return 0;
}

void ResetReceivedWonderCardFlag(void)
{
    sStatsEnabled = FALSE;
}

bool32 MEventHandleReceivedWonderCard(u16 a0)
{
    /*
    sStatsEnabled = FALSE;
    if (a0 == 0)
        return FALSE;

    if (!ValidateReceivedWonderCard())
        return FALSE;

    if (gSaveBlock1Ptr->subtitleText2C.wonderCard.data.flagId != a0)
        return FALSE;

    sStatsEnabled = TRUE;
    */
    return TRUE;
}

void RecordIdOfWonderCardSenderByEventType(u32 a0, u32 a1)
{
    /*
    if (sStatsEnabled)
    {
        switch (a0)
        {
        case 2:
            IncrementCardStatForNewTrainer(2, a1, gSaveBlock1Ptr->subtitleText2C.unk_344[1], 5);
            break;
        case 0:
            IncrementCardStatForNewTrainer(0, a1, gSaveBlock1Ptr->subtitleText2C.unk_344[0], 5);
            break;
        case 1:
            IncrementCardStatForNewTrainer(1, a1, gSaveBlock1Ptr->subtitleText2C.unk_344[0], 5);
            break;
        default:
            AGB_ASSERT(0);
        }
    }
    */
}

static void ClearSavedTrainerIds(void)
{
    /*
    CpuFill32(0, gSaveBlock1Ptr->subtitleText2C.unk_344, sizeof(gSaveBlock1Ptr->subtitleText2C.unk_344));
    */
}

static bool32 sub_801BA24(u32 a0, u32 *a1, int size)
{
    int i;
    int j;

    for (i = 0; i < size; i++)
    {
        if (a1[i] == a0)
            break;
    }

    if (i == size)
    {
        for (j = size - 1; j > 0; j--)
            a1[j] = a1[j - 1];

        a1[0] = a0;
        return TRUE;
    }
    else
    {
        for (j = i; j > 0; j--)
            a1[j] = a1[j - 1];

        a1[0] = a0;
        return FALSE;
    }
}

static void IncrementCardStatForNewTrainer(u32 a0, u32 a1, u32 *a2, int a3)
{
    if (sub_801BA24(a1, a2, a3))
        sub_801B7D8(a0);
}
