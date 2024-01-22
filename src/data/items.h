const struct Item gItems[] =
{
    [ITEM_NONE] =
    {
        .name = _("????????"),
        .itemId = ITEM_NONE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

// Pokeballs

    [ITEM_MASTER_BALL] =
    {
        .name = _("Master Ball"),
        .itemId = ITEM_MASTER_BALL,
        .price = 0,
        .description = sMasterBallDesc,
        .pocket = POCKET_POKE_BALLS,
        .type = 1,
        .fieldUseFunc = NULL,
        .battleUsage = 2,
        .battleUseFunc = ItemUseInBattle_PokeBall,
        .secondaryId = 0,
    },

    [ITEM_ULTRA_BALL] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Ultraball"),
#else
        .name = _("Ultra Ball"),
#endif
        .itemId = ITEM_ULTRA_BALL,
        .price = 1200,
        .description = sUltraBallDesc,
        .pocket = POCKET_POKE_BALLS,
        .type = 1,
        .fieldUseFunc = NULL,
        .battleUsage = 2,
        .battleUseFunc = ItemUseInBattle_PokeBall,
        .secondaryId = 1,
    },

    [ITEM_GREAT_BALL] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Superball"),
#else
        .name = _("Great Ball"),
#endif
        .itemId = ITEM_GREAT_BALL,
        .price = 600,
        .description = sGreatBallDesc,
        .pocket = POCKET_POKE_BALLS,
        .type = 2,
        .fieldUseFunc = NULL,
        .battleUsage = 2,
        .battleUseFunc = ItemUseInBattle_PokeBall,
        .secondaryId = 2,
    },

    [ITEM_POKE_BALL] =
    {
        .name = _("Poké Ball"),
        .itemId = ITEM_POKE_BALL,
        .price = 200,
        .description = sPokeBallDesc,
        .pocket = POCKET_POKE_BALLS,
        .type = 3,
        .fieldUseFunc = NULL,
        .battleUsage = 2,
        .battleUseFunc = ItemUseInBattle_PokeBall,
        .secondaryId = 3,
    },

    [ITEM_SAFARI_BALL] =
    {
        .name = _("Safari Ball"),
        .itemId = ITEM_SAFARI_BALL,
        .price = 0,
        .description = sSafariBallDesc,
        .pocket = POCKET_POKE_BALLS,
        .type = 4,
        .fieldUseFunc = NULL,
        .battleUsage = 2,
        .battleUseFunc = ItemUseInBattle_PokeBall,
        .secondaryId = 4,
    },

    [ITEM_NET_BALL] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Malla Ball"),
#else
        .name = _("Net Ball"),
#endif
        .itemId = ITEM_NET_BALL,
        .price = 1000,
        .description = sNetBallDesc,
        .pocket = POCKET_POKE_BALLS,
        .type = 5,
        .fieldUseFunc = NULL,
        .battleUsage = 2,
        .battleUseFunc = ItemUseInBattle_PokeBall,
        .secondaryId = 5,
    },

    [ITEM_DIVE_BALL] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Buceo Ball"),
#else
        .name = _("Dive Ball"),
#endif
        .itemId = ITEM_DIVE_BALL,
        .price = 1000,
        .description = sDiveBallDesc,
        .pocket = POCKET_POKE_BALLS,
        .type = 6,
        .fieldUseFunc = NULL,
        .battleUsage = 2,
        .battleUseFunc = ItemUseInBattle_PokeBall,
        .secondaryId = 6,
    },

    [ITEM_NEST_BALL] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Nido Ball"),
#else
        .name = _("Nest Ball"),
#endif
        .itemId = ITEM_NEST_BALL,
        .price = 1000,
        .description = sNestBallDesc,
        .pocket = POCKET_POKE_BALLS,
        .type = 7,
        .fieldUseFunc = NULL,
        .battleUsage = 2,
        .battleUseFunc = ItemUseInBattle_PokeBall,
        .secondaryId = 7,
    },

    [ITEM_REPEAT_BALL] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Acopio Ball"),
#else
        .name = _("Repeat Ball"),
#endif
        .itemId = ITEM_REPEAT_BALL,
        .price = 1000,
        .description = sRepeatBallDesc,
        .pocket = POCKET_POKE_BALLS,
        .type = 8,
        .fieldUseFunc = NULL,
        .battleUsage = 2,
        .battleUseFunc = ItemUseInBattle_PokeBall,
        .secondaryId = 8,
    },

    [ITEM_TIMER_BALL] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Turno Ball"),
#else
        .name = _("Timer Ball"),
#endif
        .itemId = ITEM_TIMER_BALL,
        .price = 1000,
        .description = sTimerBallDesc,
        .pocket = POCKET_POKE_BALLS,
        .type = 9,
        .fieldUseFunc = NULL,
        .battleUsage = 2,
        .battleUseFunc = ItemUseInBattle_PokeBall,
        .secondaryId = 9,
    },

    [ITEM_LUXURY_BALL] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Lujo Ball"),
#else
        .name = _("Luxury Ball"),
#endif
        .itemId = ITEM_LUXURY_BALL,
        .price = 1000,
        .description = sLuxuryBallDesc,
        .pocket = POCKET_POKE_BALLS,
        .type = 10,
        .fieldUseFunc = NULL,
        .battleUsage = 2,
        .battleUseFunc = ItemUseInBattle_PokeBall,
        .secondaryId = 10,
    },

    [ITEM_PREMIER_BALL] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Honor Ball"),
#else
        .name = _("Premier Ball"),
#endif
        .itemId = ITEM_PREMIER_BALL,
        .price = 200,
        .description = sPremierBallDesc,
        .pocket = POCKET_POKE_BALLS,
        .type = 11,
        .fieldUseFunc = NULL,
        .battleUsage = 2,
        .battleUseFunc = ItemUseInBattle_PokeBall,
        .secondaryId = 11,
    },

    [ITEM_LEVEL_BALL] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Nivel Ball"),
#else
        .name = _("Level Ball"),
#endif
        .itemId = ITEM_LEVEL_BALL,
        .price = 2000,
        .description = sLevelBallDesc,
        .pocket = POCKET_POKE_BALLS,
        .type = 11,
        .fieldUseFunc = NULL,
        .battleUsage = 2,
        .battleUseFunc = ItemUseInBattle_PokeBall,
        .secondaryId = 12,
    },

    [ITEM_LURE_BALL] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Cebo Ball"),
#else
        .name = _("Lure Ball"),
#endif
        .itemId = ITEM_LURE_BALL,
        .price = 2000,
        .description = sLureBallDesc,
        .pocket = POCKET_POKE_BALLS,
        .type = 11,
        .fieldUseFunc = NULL,
        .battleUsage = 2,
        .battleUseFunc = ItemUseInBattle_PokeBall,
        .secondaryId = 13,
    },

    [ITEM_MOON_BALL] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Luna Ball"),
#else
        .name = _("Moon Ball"),
#endif
        .itemId = ITEM_MOON_BALL,
        .price = 2000,
        .description = sMoonBallDesc,
        .pocket = POCKET_POKE_BALLS,
        .type = 11,
        .fieldUseFunc = NULL,
        .battleUsage = 2,
        .battleUseFunc = ItemUseInBattle_PokeBall,
        .secondaryId = 14,
    },

    [ITEM_FRIEND_BALL] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Amigo Ball"),
#else
        .name = _("Friend Ball"),
#endif
        .itemId = ITEM_FRIEND_BALL,
        .price = 2000,
        .description = sFriendBallDesc,
        .pocket = POCKET_POKE_BALLS,
        .type = 11,
        .fieldUseFunc = NULL,
        .battleUsage = 2,
        .battleUseFunc = ItemUseInBattle_PokeBall,
        .secondaryId = 15,
    },

    [ITEM_LOVE_BALL] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Amor Ball"),
#else
        .name = _("Love Ball"),
#endif
        .itemId = ITEM_LOVE_BALL,
        .price = 2000,
        .description = sLoveBallDesc,
        .pocket = POCKET_POKE_BALLS,
        .type = 11,
        .fieldUseFunc = NULL,
        .battleUsage = 2,
        .battleUseFunc = ItemUseInBattle_PokeBall,
        .secondaryId = 16,
    },

    [ITEM_HEAVY_BALL] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Peso Ball"),
#else
        .name = _("Heavy Ball"),
#endif
        .itemId = ITEM_HEAVY_BALL,
        .price = 2000,
        .description = sHeavyBallDesc,
        .pocket = POCKET_POKE_BALLS,
        .type = 11,
        .fieldUseFunc = NULL,
        .battleUsage = 2,
        .battleUseFunc = ItemUseInBattle_PokeBall,
        .secondaryId = 17,
    },

    [ITEM_FAST_BALL] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Rapid Ball"),
#else
        .name = _("Fast Ball"),
#endif
        .itemId = ITEM_FAST_BALL,
        .price = 2000,
        .description = sFastBallDesc,
        .pocket = POCKET_POKE_BALLS,
        .type = 11,
        .fieldUseFunc = NULL,
        .battleUsage = 2,
        .battleUseFunc = ItemUseInBattle_PokeBall,
        .secondaryId = 18,
    },

    [ITEM_HEAL_BALL] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Sana Ball"),
#else
        .name = _("Heal Ball"),
#endif
        .itemId = ITEM_HEAL_BALL,
        .price = 300,
        .description = sHealBallDesc,
        .pocket = POCKET_POKE_BALLS,
        .type = 11,
        .fieldUseFunc = NULL,
        .battleUsage = 2,
        .battleUseFunc = ItemUseInBattle_PokeBall,
        .secondaryId = 19,
    },

    [ITEM_QUICK_BALL] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Veloz Ball"),
#else
        .name = _("Quick Ball"),
#endif
        .itemId = ITEM_QUICK_BALL,
        .price = 1000,
        .description = sQuickBallDesc,
        .pocket = POCKET_POKE_BALLS,
        .type = 11,
        .fieldUseFunc = NULL,
        .battleUsage = 2,
        .battleUseFunc = ItemUseInBattle_PokeBall,
        .secondaryId = 20,
    },

    [ITEM_DUSK_BALL] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Ocaso Ball"),
#else
        .name = _("Dusk Ball"),
#endif
        .itemId = ITEM_DUSK_BALL,
        .price = 1000,
        .description = sDuskBallDesc,
        .pocket = POCKET_POKE_BALLS,
        .type = 11,
        .fieldUseFunc = NULL,
        .battleUsage = 2,
        .battleUseFunc = ItemUseInBattle_PokeBall,
        .secondaryId = 21,
    },

    [ITEM_CHERISH_BALL] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Gloria Ball"),
#else
        .name = _("Cherish Ball"),
#endif
        .itemId = ITEM_CHERISH_BALL,
        .price = 10,
        .description = sCherishBallDesc,
        .pocket = POCKET_POKE_BALLS,
        .type = 11,
        .fieldUseFunc = NULL,
        .battleUsage = 2,
        .battleUseFunc = ItemUseInBattle_PokeBall,
        .secondaryId = 22,
    },

    [ITEM_SPORT_BALL] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Competi Ball"),
#else
        .name = _("Sport Ball"),
#endif
        .itemId = ITEM_SPORT_BALL,
        .price = 10,
        .description = sSportBallDesc,
        .pocket = POCKET_POKE_BALLS,
        .type = 11,
        .fieldUseFunc = NULL,
        .battleUsage = 2,
        .battleUseFunc = ItemUseInBattle_PokeBall,
        .secondaryId = 23, // To Do
    },

    [ITEM_PARK_BALL] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Parque Ball"),
#else
        .name = _("Park Ball"),
#endif
        .itemId = ITEM_PARK_BALL,
        .price = 10,
        .description = sParkBallDesc,
        .pocket = POCKET_POKE_BALLS,
        .type = 11,
        .fieldUseFunc = NULL,
        .battleUsage = 2,
        .battleUseFunc = ItemUseInBattle_PokeBall,
        .secondaryId = 24, // To Do
    },

    [ITEM_DREAM_BALL] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Ensueño Ball"),
#else
        .name = _("Dream Ball"),
#endif
        .itemId = ITEM_DREAM_BALL,
        .price = 2400,
        .description = sDreamBallDesc,
        .pocket = POCKET_POKE_BALLS,
        .type = 11,
        .fieldUseFunc = NULL,
        .battleUsage = 2,
        .battleUseFunc = ItemUseInBattle_PokeBall,
        .secondaryId = 25, // To Do
    },

    [ITEM_BEAST_BALL] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Ente Ball"),
#else
        .name = _("Beast Ball"),
#endif
        .itemId = ITEM_BEAST_BALL,
        .price = 10,
        .description = sBeastBallDesc,
        .pocket = POCKET_POKE_BALLS,
        .type = 11,
        .fieldUseFunc = NULL,
        .battleUsage = 2,
        .battleUseFunc = ItemUseInBattle_PokeBall,
        .secondaryId = 26, // To Do
    },

// Medicine

    [ITEM_POTION] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Poción"),
#else
        .name = _("Potion"),
#endif
        .itemId = ITEM_POTION,
        .price = 300,
        .holdEffectParam = 20,
        .description = sPotionDesc,
        .pocket = POCKET_MEDICINE,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = 1,
        .battleUseFunc = ItemUseInBattle_Medicine,
        .secondaryId = 0,
    },

    [ITEM_ANTIDOTE] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Antídoto"),
#else
        .name = _("Antidote"),
#endif
        .itemId = ITEM_ANTIDOTE,
        .price = 100,
        .description = sAntidoteDesc,
        .pocket = POCKET_MEDICINE,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = 1,
        .battleUseFunc = ItemUseInBattle_Medicine,
        .secondaryId = 0,
    },

    [ITEM_BURN_HEAL] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Antiquemar"),
#else
        .name = _("Burn Heal"),
#endif
        .itemId = ITEM_BURN_HEAL,
        .price = 250,
        .description = sBurnHealDesc,
        .pocket = POCKET_MEDICINE,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = 1,
        .battleUseFunc = ItemUseInBattle_Medicine,
        .secondaryId = 0,
    },

    [ITEM_ICE_HEAL] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Antihielo"),
#else
        .name = _("Ice Heal"),
#endif
        .itemId = ITEM_ICE_HEAL,
        .price = 250,
        .description = sIceHealDesc,
        .pocket = POCKET_MEDICINE,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = 1,
        .battleUseFunc = ItemUseInBattle_Medicine,
        .secondaryId = 0,
    },

    [ITEM_AWAKENING] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Despertar"),
#else
        .name = _("Awakening"),
#endif
        .itemId = ITEM_AWAKENING,
        .price = 250,
        .description = sAwakeningDesc,
        .pocket = POCKET_MEDICINE,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = 1,
        .battleUseFunc = ItemUseInBattle_Medicine,
        .secondaryId = 0,
    },

    [ITEM_PARALYZE_HEAL] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Antiparalizador"),
#else
        .name = _("Parlyz Heal"),
#endif
        .itemId = ITEM_PARALYZE_HEAL,
        .price = 200,
        .description = sParalyzeHealDesc,
        .pocket = POCKET_MEDICINE,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = 1,
        .battleUseFunc = ItemUseInBattle_Medicine,
        .secondaryId = 0,
    },

    [ITEM_FULL_RESTORE] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Restaurar Todo"),
#else
        .name = _("Full Restore"),
#endif
        .itemId = ITEM_FULL_RESTORE,
        .price = 3000,
        .holdEffectParam = 255,
        .description = sFullRestoreDesc,
        .pocket = POCKET_MEDICINE,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = 1,
        .battleUseFunc = ItemUseInBattle_Medicine,
        .secondaryId = 0,
    },

    [ITEM_MAX_POTION] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Máxima Poción"),
#else
        .name = _("Max Potion"),
#endif
        .itemId = ITEM_MAX_POTION,
        .price = 2500,
        .holdEffectParam = 255,
        .description = sMaxPotionDesc,
        .pocket = POCKET_MEDICINE,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = 1,
        .battleUseFunc = ItemUseInBattle_Medicine,
        .secondaryId = 0,
    },

    [ITEM_HYPER_POTION] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Hiperpoción"),
#else
        .name = _("Hyper Potion"),
#endif
        .itemId = ITEM_HYPER_POTION,
        .price = 1200,
        .holdEffectParam = 120,
        .description = sHyperPotionDesc,
        .pocket = POCKET_MEDICINE,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = 1,
        .battleUseFunc = ItemUseInBattle_Medicine,
        .secondaryId = 0,
    },

    [ITEM_SUPER_POTION] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Superpoción"),
#else
        .name = _("Super Potion"),
#endif
        .itemId = ITEM_SUPER_POTION,
        .price = 700,
        .holdEffectParam = 60,
        .description = sSuperPotionDesc,
        .pocket = POCKET_MEDICINE,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = 1,
        .battleUseFunc = ItemUseInBattle_Medicine,
        .secondaryId = 0,
    },

    [ITEM_FULL_HEAL] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Cura Total"),
#else
        .name = _("Full Heal"),
#endif
        .itemId = ITEM_FULL_HEAL,
        .price = 600,
        .description = sFullHealDesc,
        .pocket = POCKET_MEDICINE,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = 1,
        .battleUseFunc = ItemUseInBattle_Medicine,
        .secondaryId = 0,
    },

    [ITEM_REVIVE] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Revivir"),
#else
        .name = _("Revive"),
#endif
        .itemId = ITEM_REVIVE,
        .price = 1500,
        .description = sReviveDesc,
        .pocket = POCKET_MEDICINE,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = 1,
        .battleUseFunc = ItemUseInBattle_Medicine,
        .secondaryId = 0,
    },

    [ITEM_MAX_REVIVE] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Revivir Máximo"),
#else
        .name = _("Max Revive"),
#endif
        .itemId = ITEM_MAX_REVIVE,
        .price = 4000,
        .description = sMaxReviveDesc,
        .pocket = POCKET_MEDICINE,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = 1,
        .battleUseFunc = ItemUseInBattle_Medicine,
        .secondaryId = 0,
    },

    [ITEM_FRESH_WATER] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Agua Fresca"),
#else
        .name = _("Fresh Water"),
#endif
        .itemId = ITEM_FRESH_WATER,
        .price = 200,
        .holdEffectParam = 30,
        .description = sFreshWaterDesc,
        .pocket = POCKET_MEDICINE,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = 1,
        .battleUseFunc = ItemUseInBattle_Medicine,
        .secondaryId = 0,
    },

    [ITEM_SODA_POP] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Refresco"),
#else
        .name = _("Soda Pop"),
#endif
        .itemId = ITEM_SODA_POP,
        .price = 300,
        .holdEffectParam = 50,
        .description = sSodaPopDesc,
        .pocket = POCKET_MEDICINE,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = 1,
        .battleUseFunc = ItemUseInBattle_Medicine,
        .secondaryId = 0,
    },

    [ITEM_LEMONADE] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Limonada"),
#else
        .name = _("Lemonade"),
#endif
        .itemId = ITEM_LEMONADE,
        .price = 350,
        .holdEffectParam = 70,
        .description = sLemonadeDesc,
        .pocket = POCKET_MEDICINE,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = 1,
        .battleUseFunc = ItemUseInBattle_Medicine,
        .secondaryId = 0,
    },

    [ITEM_MOOMOO_MILK] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Leche Mu-Mu"),
#else
        .name = _("Moomoo Milk"),
#endif
        .itemId = ITEM_MOOMOO_MILK,
        .price = 500,
        .holdEffectParam = 100,
        .description = sMoomooMilkDesc,
        .pocket = POCKET_MEDICINE,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = 1,
        .battleUseFunc = ItemUseInBattle_Medicine,
        .secondaryId = 0,
    },

    [ITEM_ENERGY_POWDER] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Polvo Energía"),
#else
        .name = _("Energypowder"),
#endif
        .itemId = ITEM_ENERGY_POWDER,
        .price = 500,
        .description = sEnergyPowderDesc,
        .pocket = POCKET_MEDICINE,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = 1,
        .battleUseFunc = ItemUseInBattle_Medicine,
        .secondaryId = 0,
    },

    [ITEM_ENERGY_ROOT] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Raíz Energía"),
#else
        .name = _("Energy Root"),
#endif
        .itemId = ITEM_ENERGY_ROOT,
        .price = 800,
        .description = sEnergyRootDesc,
        .pocket = POCKET_MEDICINE,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = 1,
        .battleUseFunc = ItemUseInBattle_Medicine,
        .secondaryId = 0,
    },

    [ITEM_HEAL_POWDER] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Polvo Curación"),
#else
        .name = _("Heal Powder"),
#endif
        .itemId = ITEM_HEAL_POWDER,
        .price = 450,
        .description = sHealPowderDesc,
        .pocket = POCKET_MEDICINE,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = 1,
        .battleUseFunc = ItemUseInBattle_Medicine,
        .secondaryId = 0,
    },

    [ITEM_REVIVAL_HERB] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Hierba Revivir"),
#else
        .name = _("Revival Herb"),
#endif
        .itemId = ITEM_REVIVAL_HERB,
        .price = 2800,
        .description = sRevivalHerbDesc,
        .pocket = POCKET_MEDICINE,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = 1,
        .battleUseFunc = ItemUseInBattle_Medicine,
        .secondaryId = 0,
    },

    [ITEM_ETHER] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Éter"),
#else
        .name = _("Ether"),
#endif
        .itemId = ITEM_ETHER,
        .price = 1200,
        .holdEffectParam = 10,
        .description = sEtherDesc,
        .pocket = POCKET_MEDICINE,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_PPRecovery,
        .battleUsage = 1,
        .battleUseFunc = ItemUseInBattle_PPRecovery,
        .secondaryId = 0,
    },

    [ITEM_MAX_ETHER] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Éter Máximo"),
#else
        .name = _("Max Ether"),
#endif
        .itemId = ITEM_MAX_ETHER,
        .price = 2000,
        .holdEffectParam = 255,
        .description = sMaxEtherDesc,
        .pocket = POCKET_MEDICINE,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_PPRecovery,
        .battleUsage = 1,
        .battleUseFunc = ItemUseInBattle_PPRecovery,
        .secondaryId = 0,
    },

    [ITEM_ELIXIR] =
    {
        .name = _("Elixir"),
        .itemId = ITEM_ELIXIR,
        .price = 3000,
        .holdEffectParam = 10,
        .description = sElixirDesc,
        .pocket = POCKET_MEDICINE,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_PPRecovery,
        .battleUsage = 1,
        .battleUseFunc = ItemUseInBattle_PPRecovery,
        .secondaryId = 0,
    },

    [ITEM_MAX_ELIXIR] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Elixir Máximo"),
#else
        .name = _("Max Elixir"),
#endif
        .itemId = ITEM_MAX_ELIXIR,
        .price = 4500,
        .holdEffectParam = 255,
        .description = sMaxElixirDesc,
        .pocket = POCKET_MEDICINE,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_PPRecovery,
        .battleUsage = 1,
        .battleUseFunc = ItemUseInBattle_PPRecovery,
        .secondaryId = 0,
    },

    [ITEM_LAVA_COOKIE] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Galleta Lava"),
#else
        .name = _("Lava Cookie"),
#endif
        .itemId = ITEM_LAVA_COOKIE,
        .price = 200,
        .description = sLavaCookieDesc,
        .pocket = POCKET_MEDICINE,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = 1,
        .battleUseFunc = ItemUseInBattle_Medicine,
        .secondaryId = 0,
    },

    [ITEM_BLUE_FLUTE] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Flauta Azul"),
#else
        .name = _("Blue Flute"),
#endif
        .itemId = ITEM_BLUE_FLUTE,
        .price = 100,
        .description = sBlueFluteDesc,
        .pocket = POCKET_MEDICINE,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = 1,
        .battleUseFunc = ItemUseInBattle_Medicine,
        .secondaryId = 0,
    },

    [ITEM_YELLOW_FLUTE] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Flauta Amarilla"),
#else
        .name = _("Yellow Flute"),
#endif
        .itemId = ITEM_YELLOW_FLUTE,
        .price = 200,
        .description = sYellowFluteDesc,
        .pocket = POCKET_MEDICINE,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .battleUsage = 1,
        .battleUseFunc = ItemUseInBattle_Medicine,
        .secondaryId = 0,
    },

    [ITEM_RED_FLUTE] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Flauta Roja"),
#else
        .name = _("Red Flute"),
#endif
        .itemId = ITEM_RED_FLUTE,
        .price = 300,
        .description = sRedFluteDesc,
        .pocket = POCKET_MEDICINE,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .battleUsage = 1,
        .battleUseFunc = ItemUseInBattle_Medicine,
        .secondaryId = 0,
    },

    [ITEM_BLACK_FLUTE] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Flauta Negra"),
#else
        .name = _("Black Flute"),
#endif
        .itemId = ITEM_BLACK_FLUTE,
        .price = 400,
        .holdEffectParam = 50,
        .description = sBlackFluteDesc,
        .pocket = POCKET_MEDICINE,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_BlackWhiteFlute,
        .secondaryId = 0,
    },

    [ITEM_WHITE_FLUTE] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Flauta Blanca"),
#else
        .name = _("White Flute"),
#endif
        .itemId = ITEM_WHITE_FLUTE,
        .price = 500,
        .holdEffectParam = 150,
        .description = sWhiteFluteDesc,
        .pocket = POCKET_MEDICINE,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_BlackWhiteFlute,
        .secondaryId = 0,
    },

    [ITEM_BERRY_JUICE] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Zumo de Baya"),
#else
        .name = _("Berry Juice"),
#endif
        .itemId = ITEM_BERRY_JUICE,
        .price = 100,
        .holdEffect = HOLD_EFFECT_RESTORE_HP,
        .holdEffectParam = 20,
        .description = sBerryJuiceDesc,
        .pocket = POCKET_MEDICINE,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = 1,
        .battleUseFunc = ItemUseInBattle_Medicine,
        .secondaryId = 0,
    },

    [ITEM_SWEET_HEART] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Corazón Dulce"),
#else
        .name = _("Sweet Heart"),
#endif
        .itemId = ITEM_SWEET_HEART,
        .price = 3000,
        .holdEffectParam = 20,
        .description = sSweetHeartDesc,
        .pocket = POCKET_MEDICINE,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = 1,
        .battleUseFunc = ItemUseInBattle_Medicine,
        .secondaryId = 0,
    },

    [ITEM_BIG_MALASADA] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Malasada Maxi"),
#else
        .name = _("Big Malasada"),
#endif
        .itemId = ITEM_BIG_MALASADA,
        .price = 350,
        .description = sBigMalasadaDesc,
        .pocket = POCKET_MEDICINE,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = 1,
        .battleUseFunc = ItemUseInBattle_Medicine,
        .secondaryId = 0,
    },

    [ITEM_OLD_GATEAU] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Barrita Plus"),
#else
        .name = _("Old Gateau"),
#endif
        .itemId = ITEM_OLD_GATEAU,
        .price = 350,
        .description = sOldGateauDesc,
        .pocket = POCKET_MEDICINE,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = 1,
        .battleUseFunc = ItemUseInBattle_Medicine,
        .secondaryId = 0,
    },

    [ITEM_SACRED_ASH] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Ceniza Sagrada"),
#else
        .name = _("Sacred Ash"),
#endif
        .itemId = ITEM_SACRED_ASH,
        .price = 200,
        .description = sSacredAshDesc,
        .pocket = POCKET_MEDICINE,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_SacredAsh,
        .secondaryId = 0,
    },

// Collectibles

    [ITEM_SHOAL_SALT] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Sal Cardumen"),
#else
        .name = _("Shoal Salt"),
#endif
        .itemId = ITEM_SHOAL_SALT,
        .price = 20,
        .description = sShoalSaltDesc,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_SHOAL_SHELL] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Concha Cardumen"),
#else
        .name = _("Shoal Shell"),
#endif
        .itemId = ITEM_SHOAL_SHELL,
        .price = 20,
        .description = sShoalShellDesc,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_RED_SHARD] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Parte Roja"),
#else
        .name = _("Red Shard"),
#endif
        .itemId = ITEM_RED_SHARD,
        .price = 200,
        .description = sRedShardDesc,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_BLUE_SHARD] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Parte Azul"),
#else
        .name = _("Blue Shard"),
#endif
        .itemId = ITEM_BLUE_SHARD,
        .price = 200,
        .description = sBlueShardDesc,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_YELLOW_SHARD] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Parte Amarilla"),
#else
        .name = _("Yellow Shard"),
#endif
        .itemId = ITEM_YELLOW_SHARD,
        .price = 200,
        .description = sYellowShardDesc,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_GREEN_SHARD] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Parte Verde"),
#else
        .name = _("Green Shard"),
#endif
        .itemId = ITEM_GREEN_SHARD,
        .price = 200,
        .description = sGreenShardDesc,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

// Vitamins

    [ITEM_HP_UP] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Más PS"),
#else
        .name = _("HP Up"),
#endif
        .itemId = ITEM_HP_UP,
        .price = 900,
        .description = sHPUpDesc,
        .pocket = POCKET_POWER_UP,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .secondaryId = 0,
    },

    [ITEM_PROTEIN] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Proteína"),
#else
        .name = _("Protein"),
#endif
        .itemId = ITEM_PROTEIN,
        .price = 900,
        .description = sProteinDesc,
        .pocket = POCKET_POWER_UP,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .secondaryId = 0,
    },

    [ITEM_IRON] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Hierro"),
#else
        .name = _("Iron"),
#endif
        .itemId = ITEM_IRON,
        .price = 900,
        .description = sIronDesc,
        .pocket = POCKET_POWER_UP,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .secondaryId = 0,
    },

    [ITEM_CARBOS] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Carburante"),
#else
        .name = _("Carbos"),
#endif
        .itemId = ITEM_CARBOS,
        .price = 900,
        .description = sCarbosDesc,
        .pocket = POCKET_POWER_UP,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .secondaryId = 0,
    },

    [ITEM_CALCIUM] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Calcio"),
#else
        .name = _("Calcium"),
#endif
        .itemId = ITEM_CALCIUM,
        .price = 900,
        .description = sCalciumDesc,
        .pocket = POCKET_POWER_UP,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .secondaryId = 0,
    },

    [ITEM_RARE_CANDY] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Caramelo Raro"),
#else
        .name = _("Rare Candy"),
#endif
        .itemId = ITEM_RARE_CANDY,
        .price = 9800,
        .description = sRareCandyDesc,
        .pocket = POCKET_POWER_UP,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_RareCandy,
        .secondaryId = 0,
    },
    
    [ITEM_POWER_CANDY] =
    {
        .name = _("Power Candy"),
        .itemId = ITEM_POWER_CANDY,
        .price = 9800,
        .description = sPokeFluteDesc,
        .pocket = POCKET_POWER_UP,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_PowerCandy,
        .secondaryId = 0,
    },

    [ITEM_PP_UP] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Más PP"),
#else
        .name = _("PP Up"),
#endif
        .itemId = ITEM_PP_UP,
        .price = 2500,
        .description = sPPUpDesc,
        .pocket = POCKET_POWER_UP,
        .type = 1,
        .fieldUseFunc =  ItemUseOutOfBattle_PPUp,
        .secondaryId = 0,
    },

    [ITEM_ZINC] =
    {
        .name = _("Zinc"),
        .itemId = ITEM_ZINC,
        .price = 900,
        .description = sZincDesc,
        .pocket = POCKET_POWER_UP,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .secondaryId = 0,
    },

    [ITEM_PP_MAX] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("PP Máximos"),
#else
        .name = _("PP Max"),
#endif
        .itemId = ITEM_PP_MAX,
        .price = 5000,
        .description = sPPMaxDesc,
        .pocket = POCKET_POWER_UP,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_PPUp,
        .secondaryId = 0,
    },

// Battle items

    [ITEM_GUARD_SPEC] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Protección X"),
#else
        .name = _("Guard Spec."),
#endif
        .itemId = ITEM_GUARD_SPEC,
        .price = 700,
        .description = sGuardSpecDesc,
        .pocket = POCKET_BATTLE_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .battleUsage = 2,
        .battleUseFunc = ItemUseInBattle_StatIncrease,
        .secondaryId = 0,
    },

    [ITEM_DIRE_HIT] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Directo"),
#else
        .name = _("Dire Hit"),
#endif
        .itemId = ITEM_DIRE_HIT,
        .price = 650,
        .description = sDireHitDesc,
        .pocket = POCKET_BATTLE_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .battleUsage = 2,
        .battleUseFunc = ItemUseInBattle_StatIncrease,
        .secondaryId = 0,
    },

    [ITEM_X_ATTACK] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Ataque X"),
#else
        .name = _("X Attack"),
#endif
        .itemId = ITEM_X_ATTACK,
        .price = 1000,
        .description = sXAttackDesc,
        .pocket = POCKET_BATTLE_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .battleUsage = 2,
        .battleUseFunc = ItemUseInBattle_StatIncrease,
        .secondaryId = 0,
    },

    [ITEM_X_DEFENSE] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Defensa X"),
#else
        .name = _("X Defend"),
#endif
        .itemId = ITEM_X_DEFENSE,
        .price = 2000,
        .description = sXDefendDesc,
        .pocket = POCKET_BATTLE_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .battleUsage = 2,
        .battleUseFunc = ItemUseInBattle_StatIncrease,
        .secondaryId = 0,
    },

    [ITEM_X_SPEED] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Velocidad X"),
#else
        .name = _("X Speed"),
#endif
        .itemId = ITEM_X_SPEED,
        .price = 1000,
        .description = sXSpeedDesc,
        .pocket = POCKET_BATTLE_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .battleUsage = 2,
        .battleUseFunc = ItemUseInBattle_StatIncrease,
        .secondaryId = 0,
    },

    [ITEM_X_ACCURACY] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Precisión X"),
#else
        .name = _("X Accuracy"),
#endif
        .itemId = ITEM_X_ACCURACY,
        .price = 1000,
        .description = sXAccuracyDesc,
        .pocket = POCKET_BATTLE_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .battleUsage = 2,
        .battleUseFunc = ItemUseInBattle_StatIncrease,
        .secondaryId = 0,
    },

    [ITEM_X_SP_ATK] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("At. Especial X"),
#else
        .name = _("X Sp. Atk."),
#endif
        .itemId = ITEM_X_SP_ATK,
        .price = 1000,
        .description = sXSpecialAttackDesc,
        .pocket = POCKET_BATTLE_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .battleUsage = 2,
        .battleUseFunc = ItemUseInBattle_StatIncrease,
        .secondaryId = 0,
    },

    [ITEM_X_SP_DEF] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Def. Especial X"),
#else
        .name = _("X Sp. Def."),
#endif
        .itemId = ITEM_X_SP_DEF,
        .price = 2000,
        .description = sXSpecialDefenseDesc,
        .pocket = POCKET_BATTLE_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .battleUsage = 2,
        .battleUseFunc = ItemUseInBattle_StatIncrease,
        .secondaryId = 0,
    },

    [ITEM_POKE_DOLL] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Poké Muñeco"),
#else
        .name = _("Poké Doll"),
#endif
        .itemId = ITEM_POKE_DOLL,
        .price = 1000,
        .description = sPokeDollDesc,
        .pocket = POCKET_BATTLE_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .battleUsage = 2,
        .battleUseFunc = ItemUseInBattle_Escape,
        .secondaryId = 0,
    },

    [ITEM_FLUFFY_TAIL] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Cola Skitty"),
#else
        .name = _("Fluffy Tail"),
#endif
        .itemId = ITEM_FLUFFY_TAIL,
        .price = 1000,
        .description = sFluffyTailDesc,
        .pocket = POCKET_BATTLE_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .battleUsage = 2,
        .battleUseFunc = ItemUseInBattle_Escape,
        .secondaryId = 0,
    },

// Field items

    [ITEM_SUPER_REPEL] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Superrepelente"),
#else
        .name = _("Super Repel"),
#endif
        .itemId = ITEM_SUPER_REPEL,
        .price = 500,
        .holdEffectParam = 200,
        .description = sSuperRepelDesc,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_Repel,
        .secondaryId = 0,
    },

    [ITEM_MAX_REPEL] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Repelente Maximo"),
#else
        .name = _("Max Repel"),
#endif
        .itemId = ITEM_MAX_REPEL,
        .price = 700,
        .holdEffectParam = 250,
        .description = sMaxRepelDesc,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_Repel,
        .secondaryId = 0,
    },

    [ITEM_ABILITY_CAPSULE] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Cáps. Habilidad"),
#else
        .name = _("Ability Capsule"),
#endif
        .itemId = ITEM_ABILITY_CAPSULE,
        .price = 10000,
        .holdEffectParam = 0,
        .description = sAbilityCapsuleDesc,
        .pocket = POCKET_POWER_UP,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_AbilityCapsule,
        .secondaryId = 0,
    },
    
    [ITEM_ABILITY_PATCH] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Parche Hab."),
#else
        .name = _("Ability Patch"),
#endif
        .itemId = ITEM_ABILITY_PATCH,
        .price = 100,
        .holdEffectParam = 0,
        .description = sAbilityPatchDesc,
        .pocket = POCKET_POWER_UP,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_AbilityPatch,
        .secondaryId = 0,
    },

    [ITEM_ESCAPE_ROPE] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Cuerda Huida"),
#else
        .name = _("Escape Rope"),
#endif
        .itemId = ITEM_ESCAPE_ROPE,
        .description = sEscapeRopeDesc,
        #if I_KEY_ESCAPE_ROPE >= GEN_8
        .price = 0,
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        #else
        .price = 550,
        .importance = 0,
        .pocket = POCKET_ITEMS,
        #endif
        .type = 2,
        .fieldUseFunc = ItemUseOutOfBattle_EscapeRope,
        .secondaryId = 0,
    },

    [ITEM_REPEL] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Repelente"),
#else
        .name = _("Repel"),
#endif
        .itemId = ITEM_REPEL,
        .price = 350,
        .holdEffectParam = 100,
        .description = sRepelDesc,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_Repel,
        .secondaryId = 0,
    },

// Evolution stones

    [ITEM_SUN_STONE] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Piedra Solar"),
#else
        .name = _("Sun Stone"),
#endif
        .itemId = ITEM_SUN_STONE,
        .price = 2100,
        .description = sSunStoneDesc,
        .pocket = POCKET_POWER_UP,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_EvolutionStone,
        .secondaryId = 0,
    },

    [ITEM_MOON_STONE] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Piedra Lunar"),
#else
        .name = _("Moon Stone"),
#endif
        .itemId = ITEM_MOON_STONE,
        .price = 2100,
        .description = sMoonStoneDesc,
        .pocket = POCKET_POWER_UP,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_EvolutionStone,
        .secondaryId = 0,
    },

    [ITEM_FIRE_STONE] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Piedra Fuego"),
#else
        .name = _("Fire Stone"),
#endif
        .itemId = ITEM_FIRE_STONE,
        .price = 2100,
        .description = sFireStoneDesc,
        .pocket = POCKET_POWER_UP,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_EvolutionStone,
        .secondaryId = 0,
    },

    [ITEM_THUNDER_STONE] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Piedra Trueno"),
#else
        .name = _("ThunderStone"),
#endif
        .itemId = ITEM_THUNDER_STONE,
        .price = 2100,
        .description = sThunderStoneDesc,
        .pocket = POCKET_POWER_UP,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_EvolutionStone,
        .secondaryId = 0,
    },

    [ITEM_WATER_STONE] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Piedra Agua"),
#else
        .name = _("Water Stone"),
#endif
        .itemId = ITEM_WATER_STONE,
        .price = 2100,
        .description = sWaterStoneDesc,
        .pocket = POCKET_POWER_UP,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_EvolutionStone,
        .secondaryId = 0,
    },

    [ITEM_LEAF_STONE] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Piedra Hoja"),
#else
        .name = _("Leaf Stone"),
#endif
        .itemId = ITEM_LEAF_STONE,
        .price = 2100,
        .description = sLeafStoneDesc,
        .pocket = POCKET_POWER_UP,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_EvolutionStone,
        .secondaryId = 0,
    },

    [ITEM_DAWN_STONE] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Piedra Alba"),
#else
        .name = _("Dawn Stone"),
#endif
        .itemId = ITEM_DAWN_STONE,
        .price = 2100,
        .description = sDawnStoneDesc,
        .pocket = POCKET_POWER_UP,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_EvolutionStone,
        .secondaryId = 0,
    },

    [ITEM_DUSK_STONE] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Piedra Noche"),
#else
        .name = _("Dusk Stone"),
#endif
        .itemId = ITEM_DUSK_STONE,
        .price = 2100,
        .description = sDuskStoneDesc,
        .pocket = POCKET_POWER_UP,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_EvolutionStone,
        .secondaryId = 0,
    },

    [ITEM_SHINY_STONE] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Piedra Día"),
#else
        .name = _("Shiny Stone"),
#endif
        .itemId = ITEM_SHINY_STONE,
        .price = 2100,
        .description = sShinyStoneDesc,
        .pocket = POCKET_POWER_UP,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_EvolutionStone,
        .secondaryId = 0,
    },

    [ITEM_ICE_STONE] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Piedra Hielo"),
#else
        .name = _("Ice Stone"),
#endif
        .itemId = ITEM_ICE_STONE,
        .price = 2100,
        .description = sIceStoneDesc,
        .pocket = POCKET_POWER_UP,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_EvolutionStone,
        .secondaryId = 0,
    },

// Valuable items

    [ITEM_RED_APRICORN] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Bonguri Rojo"),
#else
        .name = _("Red Apricorn"),
#endif
        .itemId = ITEM_RED_APRICORN,
        .price = 200,
        .description = sRedApricornDesc,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_BLUE_APRICORN] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Bonguri Azul"),
#else
        .name = _("Blue Apricorn"),
#endif
        .itemId = ITEM_BLUE_APRICORN,
        .price = 200,
        .description = sBlueApricornDesc,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_YELLOW_APRICORN] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Bonguri Amarillo"),
#else
        .name = _("Yellow Apricorn"),
#endif
        .itemId = ITEM_YELLOW_APRICORN,
        .price = 200,
        .description = sYellowApricornDesc,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_GREEN_APRICORN] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Bonguri Verde"),
#else
        .name = _("Green Apricorn"),
#endif
        .itemId = ITEM_GREEN_APRICORN,
        .price = 200,
        .description = sGreenApricornDesc,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_PINK_APRICORN] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Bonguri Rosa"),
#else
        .name = _("Pink Apricorn"),
#endif
        .itemId = ITEM_PINK_APRICORN,
        .price = 200,
        .description = sPinkApricornDesc,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_WHITE_APRICORN] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Bonguri Blanco"),
#else
        .name = _("White Apricorn"),
#endif
        .itemId = ITEM_WHITE_APRICORN,
        .price = 200,
        .description = sWhiteApricornDesc,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_BLACK_APRICORN] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Bonguri Negro"),
#else
        .name = _("Black Apricorn"),
#endif
        .itemId = ITEM_BLACK_APRICORN,
        .price = 200,
        .description = sBlackApricornDesc,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_TINY_MUSHROOM] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Mini Seta"),
#else
        .name = _("Tiny Mushroom"),
#endif
        .itemId = ITEM_TINY_MUSHROOM,
        .price = 500,
        .description = sTinyMushroomDesc,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_BIG_MUSHROOM] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Seta Grande"),
#else
        .name = _("Big Mushroom"),
#endif
        .itemId = ITEM_BIG_MUSHROOM,
        .price = 5000,
        .description = sBigMushroomDesc,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_PEARL] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Perla"),
#else
        .name = _("Pearl"),
#endif
        .itemId = ITEM_PEARL,
        .price = 1400,
        .description = sPearlDesc,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_BIG_PEARL] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Perla Grande"),
#else
        .name = _("Big Pearl"),
#endif
        .itemId = ITEM_BIG_PEARL,
        .price = 7500,
        .description = sBigPearlDesc,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_STARDUST] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Polvoestelar"),
#else
        .name = _("Stardust"),
#endif
        .itemId = ITEM_STARDUST,
        .price = 2000,
        .description = sStardustDesc,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_STAR_PIECE] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Trozo Estrella"),
#else
        .name = _("Star Piece"),
#endif
        .itemId = ITEM_STAR_PIECE,
        .price = 9800,
        .description = sStarPieceDesc,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_NUGGET] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Pepita"),
#else
        .name = _("Nugget"),
#endif
        .itemId = ITEM_NUGGET,
        .price = 15000,
        .description = sNuggetDesc,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_HEART_SCALE] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Escama Corazón"),
#else
        .name = _("Heart Scale"),
#endif
        .itemId = ITEM_HEART_SCALE,
        .holdEffect = HOLD_EFFECT_HEART_SCALE,
        .price = 1000,
        .description = sHeartScaleDesc,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_RED_NECTAR] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Néctar Rojo"),
#else
        .name = _("Red Nectar"),
#endif
        .itemId = ITEM_RED_NECTAR,
        .price = 300,
        .holdEffectParam = 0,
        .description = sRedNectarDesc,
        .pocket = POCKET_POWER_UP,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse, // Placeholder
        .secondaryId = 0,
    },

    [ITEM_YELLOW_NECTAR] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Néctar Amarillo"),
#else
        .name = _("Yellow Nectar"),
#endif
        .itemId = ITEM_YELLOW_NECTAR,
        .price = 300,
        .holdEffectParam = 0,
        .description = sYellowNectarDesc,
        .pocket = POCKET_POWER_UP,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse, // Placeholder
        .secondaryId = 0,
    },

    [ITEM_PINK_NECTAR] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Néctar Rosa"),
#else
        .name = _("Pink Nectar"),
#endif
        .itemId = ITEM_PINK_NECTAR,
        .price = 300,
        .holdEffectParam = 0,
        .description = sPinkNectarDesc,
        .pocket = POCKET_POWER_UP,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse, // Placeholder
        .secondaryId = 0,
    },

    [ITEM_PURPLE_NECTAR] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Néctar Violeta"),
#else
        .name = _("Purple Nectar"),
#endif
        .itemId = ITEM_PURPLE_NECTAR,
        .price = 300,
        .holdEffectParam = 0,
        .description = sPurpleNectarDesc,
        .pocket = POCKET_POWER_UP,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse, // Placeholder
        .secondaryId = 0,
    },

    [ITEM_RARE_BONE] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Hueso Raro"),
#else
        .name = _("Rare Bone"),
#endif
        .itemId = ITEM_RARE_BONE,
        .price = 5000,
        .description = sRareBoneDesc,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

// Mail
    [ITEM_ORANGE_MAIL] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Carta Naranja"),
#else
        .name = _("Orange Mail"),
#endif
        .itemId = ITEM_ORANGE_MAIL,
        .price = 50,
        .description = sOrangeMailDesc,
        .pocket = POCKET_ITEMS,
        .type = 0,
        .fieldUseFunc = ItemUseOutOfBattle_Mail,
        .secondaryId = 0,
    },

    [ITEM_HARBOR_MAIL] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Carta Puerto"),
#else
        .name = _("Harbor Mail"),
#endif
        .itemId = ITEM_HARBOR_MAIL,
        .price = 50,
        .description = sHarborMailDesc,
        .pocket = POCKET_ITEMS,
        .type = 0,
        .fieldUseFunc = ItemUseOutOfBattle_Mail,
        .secondaryId = 1,
    },

    [ITEM_GLITTER_MAIL] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Carta Brillo"),
#else
        .name = _("Glitter Mail"),
#endif
        .itemId = ITEM_GLITTER_MAIL,
        .price = 50,
        .description = sGlitterMailDesc,
        .pocket = POCKET_ITEMS,
        .type = 0,
        .fieldUseFunc = ItemUseOutOfBattle_Mail,
        .secondaryId = 2,
    },

    [ITEM_MECH_MAIL] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Carta Imán"),
#else
        .name = _("Mech Mail"),
#endif
        .itemId = ITEM_MECH_MAIL,
        .price = 50,
        .description = sMechMailDesc,
        .pocket = POCKET_ITEMS,
        .type = 0,
        .fieldUseFunc = ItemUseOutOfBattle_Mail,
        .secondaryId = 3,
    },

    [ITEM_WOOD_MAIL] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Carta Madera"),
#else
        .name = _("Wood Mail"),
#endif
        .itemId = ITEM_WOOD_MAIL,
        .price = 50,
        .description = sWoodMailDesc,
        .pocket = POCKET_ITEMS,
        .type = 0,
        .fieldUseFunc = ItemUseOutOfBattle_Mail,
        .secondaryId = 4,
    },

    [ITEM_WAVE_MAIL] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Carta Ola"),
#else
        .name = _("Wave Mail"),
#endif
        .itemId = ITEM_WAVE_MAIL,
        .price = 50,
        .description = sWaveMailDesc,
        .pocket = POCKET_ITEMS,
        .type = 0,
        .fieldUseFunc = ItemUseOutOfBattle_Mail,
        .secondaryId = 5,
    },

    [ITEM_BEAD_MAIL] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Carta Imagen"),
#else
        .name = _("Bead Mail"),
#endif
        .itemId = ITEM_BEAD_MAIL,
        .price = 50,
        .description = sBeadMailDesc,
        .pocket = POCKET_ITEMS,
        .type = 0,
        .fieldUseFunc = ItemUseOutOfBattle_Mail,
        .secondaryId = 6,
    },

    [ITEM_SHADOW_MAIL] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Carta Sombra"),
#else
        .name = _("Shadow Mail"),
#endif
        .itemId = ITEM_SHADOW_MAIL,
        .price = 50,
        .description = sShadowMailDesc,
        .pocket = POCKET_ITEMS,
        .type = 0,
        .fieldUseFunc = ItemUseOutOfBattle_Mail,
        .secondaryId = 7,
    },

    [ITEM_TROPIC_MAIL] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Carta Tropical"),
#else
        .name = _("Tropic Mail"),
#endif
        .itemId = ITEM_TROPIC_MAIL,
        .price = 50,
        .description = sTropicMailDesc,
        .pocket = POCKET_ITEMS,
        .type = 0,
        .fieldUseFunc = ItemUseOutOfBattle_Mail,
        .secondaryId = 8,
    },

    [ITEM_DREAM_MAIL] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Carta Sueño"),
#else
        .name = _("Dream Mail"),
#endif
        .itemId = ITEM_DREAM_MAIL,
        .price = 50,
        .description = sDreamMailDesc,
        .pocket = POCKET_ITEMS,
        .type = 0,
        .fieldUseFunc = ItemUseOutOfBattle_Mail,
        .secondaryId = 9,
    },

    [ITEM_FAB_MAIL] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Carta Fabulosa"),
#else
        .name = _("Fab Mail"),
#endif
        .itemId = ITEM_FAB_MAIL,
        .price = 50,
        .description = sFabMailDesc,
        .pocket = POCKET_ITEMS,
        .type = 0,
        .fieldUseFunc = ItemUseOutOfBattle_Mail,
        .secondaryId = 10,
    },

    [ITEM_RETRO_MAIL] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Carta Retro"),
#else
        .name = _("Retro Mail"),
#endif
        .itemId = ITEM_RETRO_MAIL,
        .price = 0,
        .description = sRetroMailDesc,
        .pocket = POCKET_ITEMS,
        .type = 0,
        .fieldUseFunc = ItemUseOutOfBattle_Mail,
        .secondaryId = 11,
    },

// Berries

    [ITEM_CHERI_BERRY] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Baya Zreza"),
#else
        .name = _("Cheri Berry"),
#endif
        .itemId = ITEM_CHERI_BERRY,
        .price = 200,
        .holdEffect = HOLD_EFFECT_CURE_PAR,
        .description = sCheriBerryDesc,
        .pocket = POCKET_BERRIES,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = 1,
        .battleUseFunc = ItemUseInBattle_Medicine,
        .secondaryId = 0,
    },

    [ITEM_CHESTO_BERRY] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Baya Atania"),
#else
        .name = _("Chesto Berry"),
#endif
        .itemId = ITEM_CHESTO_BERRY,
        .price = 200,
        .holdEffect = HOLD_EFFECT_CURE_SLP,
        .description = sChestoBerryDesc,
        .pocket = POCKET_BERRIES,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = 1,
        .battleUseFunc = ItemUseInBattle_Medicine,
        .secondaryId = 0,
    },

    [ITEM_PECHA_BERRY] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Baya Meloc"),
#else
        .name = _("Pecha Berry"),
#endif
        .itemId = ITEM_PECHA_BERRY,
        .price = 200,
        .holdEffect = HOLD_EFFECT_CURE_PSN,
        .description = sPechaBerryDesc,
        .pocket = POCKET_BERRIES,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = 1,
        .battleUseFunc = ItemUseInBattle_Medicine,
        .secondaryId = 0,
    },

    [ITEM_RAWST_BERRY] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Baya Safre"),
#else
        .name = _("Rawst Berry"),
#endif
        .itemId = ITEM_RAWST_BERRY,
        .price = 200,
        .holdEffect = HOLD_EFFECT_CURE_BRN,
        .description = sRawstBerryDesc,
        .pocket = POCKET_BERRIES,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = 1,
        .battleUseFunc = ItemUseInBattle_Medicine,
        .secondaryId = 0,
    },

    [ITEM_ASPEAR_BERRY] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Baya Perasi"),
#else
        .name = _("Aspear Berry"),
#endif
        .itemId = ITEM_ASPEAR_BERRY,
        .price = 200,
        .holdEffect = HOLD_EFFECT_CURE_FRZ,
        .description = sAspearBerryDesc,
        .pocket = POCKET_BERRIES,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = 1,
        .battleUseFunc = ItemUseInBattle_Medicine,
        .secondaryId = 0,
    },

    [ITEM_LEPPA_BERRY] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Baya Zanama"),
#else
        .name = _("Leppa Berry"),
#endif
        .itemId = ITEM_LEPPA_BERRY,
        .price = 200,
        .holdEffect = HOLD_EFFECT_RESTORE_PP,
        .holdEffectParam = 10,
        .description = sLeppaBerryDesc,
        .pocket = POCKET_BERRIES,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_PPRecovery,
        .battleUsage = 1,
        .battleUseFunc = ItemUseInBattle_PPRecovery,
        .secondaryId = 0,
    },

    [ITEM_ORAN_BERRY] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Baya Aranja"),
#else
        .name = _("Oran Berry"),
#endif
        .itemId = ITEM_ORAN_BERRY,
        .price = 200,
        .holdEffect = HOLD_EFFECT_RESTORE_HP,
        .holdEffectParam = 10,
        .description = sOranBerryDesc,
        .pocket = POCKET_BERRIES,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = 1,
        .battleUseFunc = ItemUseInBattle_Medicine,
        .secondaryId = 0,
    },

    [ITEM_PERSIM_BERRY] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Baya Caquic"),
#else
        .name = _("Persim Berry"),
#endif
        .itemId = ITEM_PERSIM_BERRY,
        .price = 200,
        .holdEffect = HOLD_EFFECT_CURE_CONFUSION,
        .description = sPersimBerryDesc,
        .pocket = POCKET_BERRIES,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .battleUsage = 1,
        .battleUseFunc = ItemUseInBattle_Medicine,
        .secondaryId = 0,
    },

    [ITEM_LUM_BERRY] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Baya Ziuela"),
#else
        .name = _("Lum Berry"),
#endif
        .itemId = ITEM_LUM_BERRY,
        .price = 1000,
        .holdEffect = HOLD_EFFECT_CURE_STATUS,
        .description = sLumBerryDesc,
        .pocket = POCKET_BERRIES,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = 1,
        .battleUseFunc = ItemUseInBattle_Medicine,
        .secondaryId = 0,
    },

    [ITEM_SITRUS_BERRY] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Baya Zidra"),
#else
        .name = _("Sitrus Berry"),
#endif
        .itemId = ITEM_SITRUS_BERRY,
        .price = 1000,
        .holdEffect = HOLD_EFFECT_RESTORE_PCT_HP,
        .holdEffectParam = 25, //restores 25% of the max HP
        .description = sSitrusBerryDesc,
        .pocket = POCKET_BERRIES,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = 1,
        .battleUseFunc = ItemUseInBattle_Medicine,
        .secondaryId = 0,
    },

    [ITEM_FIGY_BERRY] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Baya Higog"),
#else
        .name = _("Figy Berry"),
#endif
        .itemId = ITEM_FIGY_BERRY,
        .price = 500,
        .holdEffect = HOLD_EFFECT_CONFUSE_SPICY,
        .holdEffectParam = 8,
        .description = sFigyBerryDesc,
        .pocket = POCKET_BERRIES,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_WIKI_BERRY] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Baya Wiki"),
#else
        .name = _("Wiki Berry"),
#endif
        .itemId = ITEM_WIKI_BERRY,
        .price = 500,
        .holdEffect = HOLD_EFFECT_CONFUSE_DRY,
        .holdEffectParam = 8,
        .description = sWikiBerryDesc,
        .pocket = POCKET_BERRIES,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_MAGO_BERRY] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Baya Ango"),
#else
        .name = _("Mago Berry"),
#endif
        .itemId = ITEM_MAGO_BERRY,
        .price = 500,
        .holdEffect = HOLD_EFFECT_CONFUSE_SWEET,
        .holdEffectParam = 8,
        .description = sMagoBerryDesc,
        .pocket = POCKET_BERRIES,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_AGUAV_BERRY] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Baya Guaya"),
#else
        .name = _("Aguav Berry"),
#endif
        .itemId = ITEM_AGUAV_BERRY,
        .price = 500,
        .holdEffect = HOLD_EFFECT_CONFUSE_BITTER,
        .holdEffectParam = 8,
        .description = sAguavBerryDesc,
        .pocket = POCKET_BERRIES,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_IAPAPA_BERRY] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Baya Pabaya"),
#else
        .name = _("Iapapa Berry"),
#endif
        .itemId = ITEM_IAPAPA_BERRY,
        .price = 500,
        .holdEffect = HOLD_EFFECT_CONFUSE_SOUR,
        .holdEffectParam = 8,
        .description = sIapapaBerryDesc,
        .pocket = POCKET_BERRIES,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_RAZZ_BERRY] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Baya Frambu"),
#else
        .name = _("Razz Berry"),
#endif
        .itemId = ITEM_RAZZ_BERRY,
        .price = 20,
        .description = sRazzBerryDesc,
        .pocket = POCKET_BERRIES,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_BLUK_BERRY] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Baya Oram"),
#else
        .name = _("Bluk Berry"),
#endif
        .itemId = ITEM_BLUK_BERRY,
        .price = 20,
        .description = sBlukBerryDesc,
        .pocket = POCKET_BERRIES,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_NANAB_BERRY] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Baya Latano"),
#else
        .name = _("Nanab Berry"),
#endif
        .itemId = ITEM_NANAB_BERRY,
        .price = 20,
        .description = sNanabBerryDesc,
        .pocket = POCKET_BERRIES,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_WEPEAR_BERRY] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Baya Peragu"),
#else
        .name = _("Wepear Berry"),
#endif
        .itemId = ITEM_WEPEAR_BERRY,
        .price = 20,
        .description = sWepearBerryDesc,
        .pocket = POCKET_BERRIES,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_PINAP_BERRY] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Baya Pinia"),
#else
        .name = _("Pinap Berry"),
#endif
        .itemId = ITEM_PINAP_BERRY,
        .price = 20,
        .description = sPinapBerryDesc,
        .pocket = POCKET_BERRIES,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_POMEG_BERRY] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Baya Grana"),
#else
        .name = _("Pomeg Berry"),
#endif
        .itemId = ITEM_POMEG_BERRY,
        .price = 200,
        .description = sPomegBerryDesc,
        .pocket = POCKET_BERRIES,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_ReduceEV,
        .secondaryId = 0,
    },

    [ITEM_KELPSY_BERRY] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Baya Algama"),
#else
        .name = _("Kelpsy Berry"),
#endif
        .itemId = ITEM_KELPSY_BERRY,
        .price = 200,
        .description = sKelpsyBerryDesc,
        .pocket = POCKET_BERRIES,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_ReduceEV,
        .secondaryId = 0,
    },

    [ITEM_QUALOT_BERRY] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Baya Ispero"),
#else
        .name = _("Qualot Berry"),
#endif
        .itemId = ITEM_QUALOT_BERRY,
        .price = 200,
        .description = sQualotBerryDesc,
        .pocket = POCKET_BERRIES,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_ReduceEV,
        .secondaryId = 0,
    },

    [ITEM_HONDEW_BERRY] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Baya Meluce"),
#else
        .name = _("Hondew Berry"),
#endif
        .itemId = ITEM_HONDEW_BERRY,
        .price = 200,
        .description = sHondewBerryDesc,
        .pocket = POCKET_BERRIES,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_ReduceEV,
        .secondaryId = 0,
    },

    [ITEM_GREPA_BERRY] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Baya Uvav"),
#else
        .name = _("Grepa Berry"),
#endif
        .itemId = ITEM_GREPA_BERRY,
        .price = 200,
        .description = sGrepaBerryDesc,
        .pocket = POCKET_BERRIES,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_ReduceEV,
        .secondaryId = 0,
    },

    [ITEM_TAMATO_BERRY] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Baya Tamate"),
#else
        .name = _("Tamato Berry"),
#endif
        .itemId = ITEM_TAMATO_BERRY,
        .price = 200,
        .description = sTamatoBerryDesc,
        .pocket = POCKET_BERRIES,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_ReduceEV,
        .secondaryId = 0,
    },

    [ITEM_CORNN_BERRY] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Baya Mais"),
#else
        .name = _("Cornn Berry"),
#endif
        .itemId = ITEM_CORNN_BERRY,
        .price = 20,
        .description = sCornnBerryDesc,
        .pocket = POCKET_BERRIES,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_MAGOST_BERRY] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Baya Aostan"),
#else
        .name = _("Magost Berry"),
#endif
        .itemId = ITEM_MAGOST_BERRY,
        .price = 20,
        .description = sMagostBerryDesc,
        .pocket = POCKET_BERRIES,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_RABUTA_BERRY] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Baya Rautan"),
#else
        .name = _("Rabuta Berry"),
#endif
        .itemId = ITEM_RABUTA_BERRY,
        .price = 20,
        .description = sRabutaBerryDesc,
        .pocket = POCKET_BERRIES,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_NOMEL_BERRY] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Baya Monli"),
#else
        .name = _("Nomel Berry"),
#endif
        .itemId = ITEM_NOMEL_BERRY,
        .price = 20,
        .description = sNomelBerryDesc,
        .pocket = POCKET_BERRIES,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_SPELON_BERRY] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Baya Wikano"),
#else
        .name = _("Spelon Berry"),
#endif
        .itemId = ITEM_SPELON_BERRY,
        .price = 20,
        .description = sSpelonBerryDesc,
        .pocket = POCKET_BERRIES,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_PAMTRE_BERRY] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Baya Plamna"),
#else
        .name = _("Pamtre Berry"),
#endif
        .itemId = ITEM_PAMTRE_BERRY,
        .price = 20,
        .description = sPamtreBerryDesc,
        .pocket = POCKET_BERRIES,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_WATMEL_BERRY] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Baya Sambia"),
#else
        .name = _("Watmel Berry"),
#endif
        .itemId = ITEM_WATMEL_BERRY,
        .price = 20,
        .description = sWatmelBerryDesc,
        .pocket = POCKET_BERRIES,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_DURIN_BERRY] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Baya Rudion"),
#else
        .name = _("Durin Berry"),
#endif
        .itemId = ITEM_DURIN_BERRY,
        .price = 20,
        .description = sDurinBerryDesc,
        .pocket = POCKET_BERRIES,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_BELUE_BERRY] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Baya Andano"),
#else
        .name = _("Belue Berry"),
#endif
        .itemId = ITEM_BELUE_BERRY,
        .price = 20,
        .description = sBelueBerryDesc,
        .pocket = POCKET_BERRIES,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_LIECHI_BERRY] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Baya Lichi"),
#else
        .name = _("Liechi Berry"),
#endif
        .itemId = ITEM_LIECHI_BERRY,
        .price = 500,
        .holdEffect = HOLD_EFFECT_ATTACK_UP,
        .holdEffectParam = 4,
        .description = sLiechiBerryDesc,
        .pocket = POCKET_BERRIES,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_GANLON_BERRY] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Baya Gonlan"),
#else
        .name = _("Ganlon Berry"),
#endif
        .itemId = ITEM_GANLON_BERRY,
        .price = 500,
        .holdEffect = HOLD_EFFECT_DEFENSE_UP,
        .holdEffectParam = 4,
        .description = sGanlonBerryDesc,
        .pocket = POCKET_BERRIES,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_SALAC_BERRY] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Baya Aslac"),
#else
        .name = _("Salac Berry"),
#endif
        .itemId = ITEM_SALAC_BERRY,
        .price = 500,
        .holdEffect = HOLD_EFFECT_SPEED_UP,
        .holdEffectParam = 4,
        .description = sSalacBerryDesc,
        .pocket = POCKET_BERRIES,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_PETAYA_BERRY] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Baya Yapati"),
#else
        .name = _("Petaya Berry"),
#endif
        .itemId = ITEM_PETAYA_BERRY,
        .price = 500,
        .holdEffect = HOLD_EFFECT_SP_ATTACK_UP,
        .holdEffectParam = 4,
        .description = sPetayaBerryDesc,
        .pocket = POCKET_BERRIES,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_APICOT_BERRY] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Baya Aricoc"),
#else
        .name = _("Apicot Berry"),
#endif
        .itemId = ITEM_APICOT_BERRY,
        .price = 500,
        .holdEffect = HOLD_EFFECT_SP_DEFENSE_UP,
        .holdEffectParam = 4,
        .description = sApicotBerryDesc,
        .pocket = POCKET_BERRIES,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_LANSAT_BERRY] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Baya Zonlan"),
#else
        .name = _("Lansat Berry"),
#endif
        .itemId = ITEM_LANSAT_BERRY,
        .price = 500,
        .holdEffect = HOLD_EFFECT_CRITICAL_UP,
        .holdEffectParam = 4,
        .description = sLansatBerryDesc,
        .pocket = POCKET_BERRIES,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_STARF_BERRY] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Baya Arabol"),
#else
        .name = _("Starf Berry"),
#endif
        .itemId = ITEM_STARF_BERRY,
        .price = 500,
        .holdEffect = HOLD_EFFECT_RANDOM_STAT_UP,
        .holdEffectParam = 4,
        .description = sStarfBerryDesc,
        .pocket = POCKET_BERRIES,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_MICLE_BERRY] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Baya Lagro"),
#else
        .name = _("Micle Berry"),
#endif
        .itemId = ITEM_MICLE_BERRY,
        .price = 20,
        .holdEffect = HOLD_EFFECT_NONE, // Placeholder
        .holdEffectParam = 4,
        .description = sMicleBerryDesc,
        .pocket = POCKET_BERRIES,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_ENIGMA_BERRY] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Baya Enigma"),
#else
        .name = _("Enigma Berry"),
#endif
        .itemId = ITEM_ENIGMA_BERRY,
        .price = 20,
        .description = sEnigmaBerryDesc,
        .pocket = POCKET_BERRIES,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_EnigmaBerry,
        .battleUsage = 1,
        .battleUseFunc = ItemUseInBattle_EnigmaBerry,
        .secondaryId = 0,
    },

    [ITEM_OCCA_BERRY] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Baya Caoca"),
#else
        .name = _("Occa Berry"),
#endif
        .itemId = ITEM_OCCA_BERRY,
        .price = 500,
        .holdEffect = HOLD_EFFECT_RESIST_BERRY,
        .holdEffectParam = TYPE_FIRE,
        .description = sOccaBerryDesc,
        .pocket = POCKET_BERRIES,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_PASSHO_BERRY] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Baya Pasio"),
#else
        .name = _("Passho Berry"),
#endif
        .itemId = ITEM_PASSHO_BERRY,
        .price = 500,
        .holdEffect = HOLD_EFFECT_RESIST_BERRY,
        .holdEffectParam = TYPE_WATER,
        .description = sPasshoBerryDesc,
        .pocket = POCKET_BERRIES,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_WACAN_BERRY] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Baya Gualot"),
#else
        .name = _("Wacan Berry"),
#endif
        .itemId = ITEM_WACAN_BERRY,
        .price = 500,
        .holdEffect = HOLD_EFFECT_RESIST_BERRY,
        .holdEffectParam = TYPE_ELECTRIC,
        .description = sWacanBerryDesc,
        .pocket = POCKET_BERRIES,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_RINDO_BERRY] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Baya Tamar"),
#else
        .name = _("Rindo Berry"),
#endif
        .itemId = ITEM_RINDO_BERRY,
        .price = 500,
        .holdEffect = HOLD_EFFECT_RESIST_BERRY,
        .holdEffectParam = TYPE_GRASS,
        .description = sRindoBerryDesc,
        .pocket = POCKET_BERRIES,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_YACHE_BERRY] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Baya Rimoya"),
#else
        .name = _("Yache Berry"),
#endif
        .itemId = ITEM_YACHE_BERRY,
        .price = 500,
        .holdEffect = HOLD_EFFECT_RESIST_BERRY,
        .holdEffectParam = TYPE_ICE,
        .description = sYacheBerryDesc,
        .pocket = POCKET_BERRIES,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_CHOPLE_BERRY] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Baya Pomaro"),
#else
        .name = _("Chople Berry"),
#endif
        .itemId = ITEM_CHOPLE_BERRY,
        .price = 500,
        .holdEffect = HOLD_EFFECT_RESIST_BERRY,
        .holdEffectParam = TYPE_FIGHTING,
        .description = sChopleBerryDesc,
        .pocket = POCKET_BERRIES,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_KEBIA_BERRY] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Baya Kebia"),
#else
        .name = _("Kebia Berry"),
#endif
        .itemId = ITEM_KEBIA_BERRY,
        .price = 500,
        .holdEffect = HOLD_EFFECT_RESIST_BERRY,
        .holdEffectParam = TYPE_POISON,
        .description = sKebiaBerryDesc,
        .pocket = POCKET_BERRIES,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_SHUCA_BERRY] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Baya Acardo"),
#else
        .name = _("Shuca Berry"),
#endif
        .itemId = ITEM_SHUCA_BERRY,
        .price = 500,
        .holdEffect = HOLD_EFFECT_RESIST_BERRY,
        .holdEffectParam = TYPE_GROUND,
        .description = sShucaBerryDesc,
        .pocket = POCKET_BERRIES,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_COBA_BERRY] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Baya Kouba"),
#else
        .name = _("Coba Berry"),
#endif
        .itemId = ITEM_COBA_BERRY,
        .price = 500,
        .holdEffect = HOLD_EFFECT_RESIST_BERRY,
        .holdEffectParam = TYPE_FIGHTING,
        .description = sCobaBerryDesc,
        .pocket = POCKET_BERRIES,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_PAYAPA_BERRY] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Baya Payapa"),
#else
        .name = _("Payapa Berry"),
#endif
        .itemId = ITEM_PAYAPA_BERRY,
        .price = 500,
        .holdEffect = HOLD_EFFECT_RESIST_BERRY,
        .holdEffectParam = TYPE_PSYCHIC,
        .description = sPayapaBerryDesc,
        .pocket = POCKET_BERRIES,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_TANGA_BERRY] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Baya Yecana"),
#else
        .name = _("Tanga Berry"),
#endif
        .itemId = ITEM_TANGA_BERRY,
        .price = 500,
        .holdEffect = HOLD_EFFECT_RESIST_BERRY,
        .holdEffectParam = TYPE_BUG,
        .description = sTangaBerryDesc,
        .pocket = POCKET_BERRIES,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_CHARTI_BERRY] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Baya Alcho"),
#else
        .name = _("Charti Berry"),
#endif
        .itemId = ITEM_CHARTI_BERRY,
        .price = 500,
        .holdEffect = HOLD_EFFECT_RESIST_BERRY,
        .holdEffectParam = TYPE_ROCK,
        .description = sChartiBerryDesc,
        .pocket = POCKET_BERRIES,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_KASIB_BERRY] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Baya Drasi"),
#else
        .name = _("Kasib Berry"),
#endif
        .itemId = ITEM_KASIB_BERRY,
        .price = 500,
        .holdEffect = HOLD_EFFECT_RESIST_BERRY,
        .holdEffectParam = TYPE_GHOST,
        .description = sKasibBerryDesc,
        .pocket = POCKET_BERRIES,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_HABAN_BERRY] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Baya Anjiro"),
#else
        .name = _("Haban Berry"),
#endif
        .itemId = ITEM_HABAN_BERRY,
        .price = 500,
        .holdEffect = HOLD_EFFECT_RESIST_BERRY,
        .holdEffectParam = TYPE_DRAGON,
        .description = sHabanBerryDesc,
        .pocket = POCKET_BERRIES,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_COLBUR_BERRY] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Baya Dillo"),
#else
        .name = _("Colbur Berry"),
#endif
        .itemId = ITEM_COLBUR_BERRY,
        .price = 500,
        .holdEffect = HOLD_EFFECT_RESIST_BERRY,
        .holdEffectParam = TYPE_DARK,
        .description = sColburBerryDesc,
        .pocket = POCKET_BERRIES,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_BABIRI_BERRY] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Baya Baribá"),
#else
        .name = _("Babiri Berry"),
#endif
        .itemId = ITEM_BABIRI_BERRY,
        .price = 500,
        .holdEffect = HOLD_EFFECT_RESIST_BERRY,
        .holdEffectParam = TYPE_STEEL,
        .description = sBabiriBerryDesc,
        .pocket = POCKET_BERRIES,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_CHILAN_BERRY] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Baya Chilan"),
#else
        .name = _("Chilan Berry"),
#endif
        .itemId = ITEM_CHILAN_BERRY,
        .price = 500,
        .holdEffect = HOLD_EFFECT_RESIST_BERRY,
        .holdEffectParam = TYPE_NORMAL,
        .description = sChilanBerryDesc,
        .pocket = POCKET_BERRIES,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_ROSELI_BERRY] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Baya Hibis"),
#else
        .name = _("Roseli Berry"),
#endif
        .itemId = ITEM_ROSELI_BERRY,
        .price = 500,
        .holdEffect = HOLD_EFFECT_RESIST_BERRY,
        .holdEffectParam = TYPE_FAIRY,
        .description = sRoseliBerryDesc,
        .pocket = POCKET_BERRIES,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_CUSTAP_BERRY] =
    {
        .name = _("Custap Berry"),
        .itemId = ITEM_CUSTAP_BERRY,
        .price = 20,
        .holdEffect = HOLD_EFFECT_NONE, // To Do
        .holdEffectParam = TYPE_FAIRY,
        .description = sCustapBerryDesc,
        .pocket = POCKET_BERRIES,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_JABOCA_BERRY] =
    {
        .name = _("Jaboca Berry"),
        .itemId = ITEM_JABOCA_BERRY,
        .price = 20,
        .holdEffect = HOLD_EFFECT_NONE, // To Do
        .holdEffectParam = TYPE_FAIRY,
        .description = sJabocaBerryDesc,
        .pocket = POCKET_BERRIES,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_ROWAP_BERRY] =
    {
        .name = _("Rowap Berry"),
        .itemId = ITEM_ROWAP_BERRY,
        .price = 20,
        .holdEffect = HOLD_EFFECT_NONE, // To Do
        .holdEffectParam = TYPE_FAIRY,
        .description = sRowapBerryDesc,
        .pocket = POCKET_BERRIES,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_KEE_BERRY] =
    {
        .name = _("Kee Berry"),
        .itemId = ITEM_KEE_BERRY,
        .price = 20,
        .holdEffect = HOLD_EFFECT_NONE, // To Do
        .holdEffectParam = TYPE_FAIRY,
        .description = sKeeBerryDesc,
        .pocket = POCKET_BERRIES,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_MARANGA_BERRY] =
    {
        .name = _("Maranga Berry"),
        .itemId = ITEM_MARANGA_BERRY,
        .price = 20,
        .holdEffect = HOLD_EFFECT_NONE, // To Do
        .holdEffectParam = TYPE_FAIRY,
        .description = sMarangaBerryDesc,
        .pocket = POCKET_BERRIES,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

// Hold items

    [ITEM_BRIGHT_POWDER] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Polvo Brillo"),
#else
        .name = _("Bright Powder"),
#endif
        .itemId = ITEM_BRIGHT_POWDER,
        .price = 10,
        .holdEffect = HOLD_EFFECT_EVASION_UP,
        .holdEffectParam = 10,
        .description = sBrightPowderDesc,
        .pocket = POCKET_BATTLE_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_WHITE_HERB] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Hierba Blanca"),
#else
        .name = _("White Herb"),
#endif
        .itemId = ITEM_WHITE_HERB,
        .price = 5000,
        .holdEffect = HOLD_EFFECT_RESTORE_STATS,
        .description = sWhiteHerbDesc,
        .pocket = POCKET_BATTLE_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_MACHO_BRACE] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Vestidura"),
#else
        .name = _("Macho Brace"),
#endif
        .itemId = ITEM_MACHO_BRACE,
        .price = 10000,
        .holdEffect = HOLD_EFFECT_MACHO_BRACE,
        .description = sMachoBraceDesc,
        .pocket = POCKET_BATTLE_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_EXP_SHARE] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Repartir Exp."),
#else
        .name = _("Exp. Share"),
#endif
        .itemId = ITEM_EXP_SHARE,
        .price = 3000,
        .holdEffect = HOLD_EFFECT_EXP_SHARE,
        .description = sExpShareDesc,
        .pocket = POCKET_KEY_ITEMS,
        .type = 2,
        .fieldUseFunc = ItemUseOutOfBattle_ExpShare,
        .secondaryId = 0,
    },

    [ITEM_QUICK_CLAW] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Garra Rápida"),
#else
        .name = _("Quick Claw"),
#endif
        .itemId = ITEM_QUICK_CLAW,
        .price = 100,
        .holdEffect = HOLD_EFFECT_QUICK_CLAW,
        .holdEffectParam = 20,
        .description = sQuickClawDesc,
        .pocket = POCKET_BATTLE_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_SOOTHE_BELL] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Campana Alivio"),
#else
        .name = _("Soothe Bell"),
#endif
        .itemId = ITEM_SOOTHE_BELL,
        .price = 100,
        .holdEffect = HOLD_EFFECT_HAPPINESS_UP,
        .description = sSootheBellDesc,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_MENTAL_HERB] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Hierba Mental"),
#else
        .name = _("Mental Herb"),
#endif
        .itemId = ITEM_MENTAL_HERB,
        .price = 100,
        .holdEffect = HOLD_EFFECT_CURE_ATTRACT,
        .description = sMentalHerbDesc,
        .pocket = POCKET_BATTLE_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_CHOICE_BAND] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Cinta Elección"),
#else
        .name = _("Choice Band"),
#endif
        .itemId = ITEM_CHOICE_BAND,
        .price = 10000,
        .holdEffect = HOLD_EFFECT_CHOICE_BAND,
        .description = sChoiceBandDesc,
        .pocket = POCKET_BATTLE_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_KINGS_ROCK] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Roca del Rey"),
#else
        .name = _("King's Rock"),
#endif
        .itemId = ITEM_KINGS_ROCK,
        .price = 2100,
        .holdEffect = HOLD_EFFECT_FLINCH,
        .holdEffectParam = 10,
        .description = sKingsRockDesc,
        .pocket = POCKET_POWER_UP,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_SILVER_POWDER] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Polvo Plata"),
#else
        .name = _("Silver Powder"),
#endif
        .itemId = ITEM_SILVER_POWDER,
        .price = 2500,
        .holdEffect = HOLD_EFFECT_BUG_POWER,
        .holdEffectParam = 10,
        .description = sSilverPowderDesc,
        .pocket = POCKET_TYPE_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_AMULET_COIN] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Moneda Amuleto"),
#else
        .name = _("Amulet Coin"),
#endif
        .itemId = ITEM_AMULET_COIN,
        .price = 100,
        .holdEffect = HOLD_EFFECT_DOUBLE_PRIZE,
        .holdEffectParam = 10,
        .description = sAmuletCoinDesc,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_CLEANSE_TAG] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Amuleto"),
#else
        .name = _("Cleanse Tag"),
#endif
        .itemId = ITEM_CLEANSE_TAG,
        .price = 200,
        .holdEffect = HOLD_EFFECT_REPEL,
        .description = sCleanseTagDesc,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_SOUL_DEW] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Rocío Bondad"),
#else
        .name = _("Soul Dew"),
#endif
        .itemId = ITEM_SOUL_DEW,
        .price = 200,
        .holdEffect = HOLD_EFFECT_SOUL_DEW,
        .description = sSoulDewDesc,
        .pocket = POCKET_BATTLE_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_DEEP_SEA_TOOTH] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Diente Marino"),
#else
        .name = _("Deep Sea Tooth"),
#endif
        .itemId = ITEM_DEEP_SEA_TOOTH,
        .price = 2100,
        .holdEffect = HOLD_EFFECT_DEEP_SEA_TOOTH,
        .description = sDeepSeaToothDesc,
        .pocket = POCKET_POWER_UP,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_DEEP_SEA_SCALE] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Escama Marina"),
#else
        .name = _("Deep Sea Scale"),
#endif
        .itemId = ITEM_DEEP_SEA_SCALE,
        .price = 2100,
        .holdEffect = HOLD_EFFECT_DEEP_SEA_SCALE,
        .description = sDeepSeaScaleDesc,
        .pocket = POCKET_POWER_UP,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_SMOKE_BALL] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Bola Humo"),
#else
        .name = _("Smoke Ball"),
#endif
        .itemId = ITEM_SMOKE_BALL,
        .price = 200,
        .holdEffect = HOLD_EFFECT_CAN_ALWAYS_RUN,
        .description = sSmokeBallDesc,
        .pocket = POCKET_BATTLE_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_EVERSTONE] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Piedra Eterna"),
#else
        .name = _("Everstone"),
#endif
        .itemId = ITEM_EVERSTONE,
        .price = 200,
        .holdEffect = HOLD_EFFECT_PREVENT_EVOLVE,
        .description = sEverstoneDesc,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_FOCUS_BAND] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Cinta Focus"),
#else
        .name = _("Focus Band"),
#endif
        .itemId = ITEM_FOCUS_BAND,
        .price = 9000,
        .holdEffect = HOLD_EFFECT_FOCUS_BAND,
        .holdEffectParam = 10,
        .description = sFocusBandDesc,
        .pocket = POCKET_BATTLE_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_LUCKY_EGG] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Huevo Suerte"),
#else
        .name = _("Lucky Egg"),
#endif
        .itemId = ITEM_LUCKY_EGG,
        .price = 200,
        .holdEffect = HOLD_EFFECT_LUCKY_EGG,
        .description = sLuckyEggDesc,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_SCOPE_LENS] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Periscopio"),
#else
        .name = _("Scope Lens"),
#endif
        .itemId = ITEM_SCOPE_LENS,
        .price = 5000,
        .holdEffect = HOLD_EFFECT_SCOPE_LENS,
        .description = sScopeLensDesc,
        .pocket = POCKET_BATTLE_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_METAL_COAT] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Revest. Metálico"),
#else
        .name = _("Metal Coat"),
#endif
        .itemId = ITEM_METAL_COAT,
        .price = 2100,
        .holdEffect = HOLD_EFFECT_STEEL_POWER,
        .holdEffectParam = 10,
        .description = sMetalCoatDesc,
        .pocket = POCKET_TYPE_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_LEFTOVERS] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Restos"),
#else
        .name = _("Leftovers"),
#endif
        .itemId = ITEM_LEFTOVERS,
        .price = 200,
        .holdEffect = HOLD_EFFECT_LEFTOVERS,
        .holdEffectParam = 10,
        .description = sLeftoversDesc,
        .pocket = POCKET_BATTLE_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_DRAGON_SCALE] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Escama Dragón"),
#else
        .name = _("Dragon Scale"),
#endif
        .itemId = ITEM_DRAGON_SCALE,
        .price = 2100,
        .holdEffect = HOLD_EFFECT_DRAGON_SCALE,
        .holdEffectParam = 10,
        .description = sDragonScaleDesc,
        .pocket = POCKET_POWER_UP,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_OVAL_STONE] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Piedra Oval"),
#else
        .name = _("Oval Stone"),
#endif
        .itemId = ITEM_OVAL_STONE,
        .price = 2100,
        .description = sOvalStoneDesc,
        .pocket = POCKET_POWER_UP,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_PROTECTOR] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Protector"),
#else
        .name = _("Protector"),
#endif
        .itemId = ITEM_PROTECTOR,
        .price = 2100,
        .description = sProtectorDesc,
        .pocket = POCKET_POWER_UP,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_ELECTIRIZER] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Electrizador"),
#else
        .name = _("Electirizer"),
#endif
        .itemId = ITEM_ELECTIRIZER,
        .price = 2100,
        .description = sElectirizerDesc,
        .pocket = POCKET_POWER_UP,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_MAGMARIZER] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Magmatizador"),
#else
        .name = _("Magmarizer"),
#endif
        .itemId = ITEM_MAGMARIZER,
        .price = 2100,
        .description = sMagmarizerDesc,
        .pocket = POCKET_POWER_UP,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_DUBIOUS_DISC] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Disco Extraño"),
#else
        .name = _("Dubious Disc"),
#endif
        .itemId = ITEM_DUBIOUS_DISC,
        .price = 2100,
        .description = sDubiousDiscDesc,
        .pocket = POCKET_POWER_UP,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_REAPER_CLOTH] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Tela Terrible"),
#else
        .name = _("Reaper Cloth"),
#endif
        .itemId = ITEM_REAPER_CLOTH,
        .price = 2100,
        .description = sReaperClothDesc,
        .pocket = POCKET_POWER_UP,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_RAZOR_CLAW] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Garra Afilada"),
#else
        .name = _("Razor Claw"),
#endif
        .itemId = ITEM_RAZOR_CLAW,
        .price = 2100,
        .holdEffect = HOLD_EFFECT_NONE, // Placeholder.
        .description = sRazorClawDesc,
        .pocket = POCKET_POWER_UP,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_RAZOR_FANG] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Colmillo Agudo"),
#else
        .name = _("Razor Fang"),
#endif
        .itemId = ITEM_RAZOR_FANG,
        .price = 2100,
        .holdEffect = HOLD_EFFECT_FLINCH,
        .holdEffectParam = 10,
        .description = sRazorFangDesc,
        .pocket = POCKET_POWER_UP,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_PRISM_SCALE] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Escama Bella"),
#else
        .name = _("Prism Scale"),
#endif
        .itemId = ITEM_PRISM_SCALE,
        .price = 2100,
        .description = sPrismScaleDesc,
        .pocket = POCKET_POWER_UP,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_WHIPPED_DREAM] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Dulce de Nata"),
#else
        .name = _("Whipped Dream"),
#endif
        .itemId = ITEM_WHIPPED_DREAM,
        .price = 2100,
        .description = sWhippedDreamDesc,
        .pocket = POCKET_POWER_UP,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_SACHET] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Saquito Fragante"),
#else
        .name = _("Sachet"),
#endif
        .itemId = ITEM_SACHET,
        .price = 2100,
        .description = sSachetDesc,
        .pocket = POCKET_POWER_UP,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_LIGHT_BALL] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Bola Luminosa"),
#else
        .name = _("Light Ball"),
#endif
        .itemId = ITEM_LIGHT_BALL,
        .price = 5000,
        .holdEffect = HOLD_EFFECT_LIGHT_BALL,
        .description = sLightBallDesc,
        .pocket = POCKET_BATTLE_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_SOFT_SAND] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Arena Fina"),
#else
        .name = _("Soft Sand"),
#endif
        .itemId = ITEM_SOFT_SAND,
        .price = 100,
        .holdEffect = HOLD_EFFECT_GROUND_POWER,
        .holdEffectParam = 10,
        .description = sSoftSandDesc,
        .pocket = POCKET_TYPE_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_HARD_STONE] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Piedra Dura"),
#else
        .name = _("Hard Stone"),
#endif
        .itemId = ITEM_HARD_STONE,
        .price = 100,
        .holdEffect = HOLD_EFFECT_ROCK_POWER,
        .holdEffectParam = 10,
        .description = sHardStoneDesc,
        .pocket = POCKET_TYPE_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_MIRACLE_SEED] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Semilla Milagro"),
#else
        .name = _("Miracle Seed"),
#endif
        .itemId = ITEM_MIRACLE_SEED,
        .price = 100,
        .holdEffect = HOLD_EFFECT_GRASS_POWER,
        .holdEffectParam = 10,
        .description = sMiracleSeedDesc,
        .pocket = POCKET_TYPE_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_BLACK_GLASSES] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Gafas de Sol"),
#else
        .name = _("Black Glasses"),
#endif
        .itemId = ITEM_BLACK_GLASSES,
        .price = 100,
        .holdEffect = HOLD_EFFECT_DARK_POWER,
        .holdEffectParam = 10,
        .description = sBlackGlassesDesc,
        .pocket = POCKET_TYPE_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_BLACK_BELT] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Cinturón Negro"),
#else
        .name = _("Black Belt"),
#endif
        .itemId = ITEM_BLACK_BELT,
        .price = 100,
        .holdEffect = HOLD_EFFECT_FIGHTING_POWER,
        .holdEffectParam = 10,
        .description = sBlackBeltDesc,
        .pocket = POCKET_TYPE_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_MAGNET] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Imán"),
#else
        .name = _("Magnet"),
#endif
        .itemId = ITEM_MAGNET,
        .price = 100,
        .holdEffect = HOLD_EFFECT_ELECTRIC_POWER,
        .holdEffectParam = 10,
        .description = sMagnetDesc,
        .pocket = POCKET_TYPE_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_MYSTIC_WATER] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Agua Mística"),
#else
        .name = _("Mystic Water"),
#endif
        .itemId = ITEM_MYSTIC_WATER,
        .price = 100,
        .holdEffect = HOLD_EFFECT_WATER_POWER,
        .holdEffectParam = 10,
        .description = sMysticWaterDesc,
        .pocket = POCKET_TYPE_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_SHARP_BEAK] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Pico Afilado"),
#else
        .name = _("Sharp Beak"),
#endif
        .itemId = ITEM_SHARP_BEAK,
        .price = 100,
        .holdEffect = HOLD_EFFECT_FLYING_POWER,
        .holdEffectParam = 10,
        .description = sSharpBeakDesc,
        .pocket = POCKET_TYPE_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_POISON_BARB] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Flecha Venenosa"),
#else
        .name = _("Poison Barb"),
#endif
        .itemId = ITEM_POISON_BARB,
        .price = 100,
        .holdEffect = HOLD_EFFECT_POISON_POWER,
        .holdEffectParam = 10,
        .description = sPoisonBarbDesc,
        .pocket = POCKET_TYPE_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_NEVER_MELT_ICE] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Antiderretir"),
#else
        .name = _("Never-Melt Ice"),
#endif
        .itemId = ITEM_NEVER_MELT_ICE,
        .price = 100,
        .holdEffect = HOLD_EFFECT_ICE_POWER,
        .holdEffectParam = 10,
        .description = sNeverMeltIceDesc,
        .pocket = POCKET_TYPE_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_SPELL_TAG] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Hechizo"),
#else
        .name = _("Spell Tag"),
#endif
        .itemId = ITEM_SPELL_TAG,
        .price = 100,
        .holdEffect = HOLD_EFFECT_GHOST_POWER,
        .holdEffectParam = 10,
        .description = sSpellTagDesc,
        .pocket = POCKET_TYPE_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_TWISTED_SPOON] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Cuchara Torcida"),
#else
        .name = _("Twisted Spoon"),
#endif
        .itemId = ITEM_TWISTED_SPOON,
        .price = 100,
        .holdEffect = HOLD_EFFECT_PSYCHIC_POWER,
        .holdEffectParam = 10,
        .description = sTwistedSpoonDesc,
        .pocket = POCKET_TYPE_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_CHARCOAL] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Carbón"),
#else
        .name = _("Charcoal"),
#endif
        .itemId = ITEM_CHARCOAL,
        .price = 9800,
        .holdEffect = HOLD_EFFECT_FIRE_POWER,
        .holdEffectParam = 10,
        .description = sCharcoalDesc,
        .pocket = POCKET_TYPE_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_DRAGON_FANG] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Colmillo Dragón"),
#else
        .name = _("Dragon Fang"),
#endif
        .itemId = ITEM_DRAGON_FANG,
        .price = 100,
        .holdEffect = HOLD_EFFECT_DRAGON_POWER,
        .holdEffectParam = 10,
        .description = sDragonFangDesc,
        .pocket = POCKET_TYPE_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_SILK_SCARF] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Pañuelo Seda"),
#else
        .name = _("Silk Scarf"),
#endif
        .itemId = ITEM_SILK_SCARF,
        .price = 100,
        .holdEffect = HOLD_EFFECT_NORMAL_POWER,
        .holdEffectParam = 10,
        .description = sSilkScarfDesc,
        .pocket = POCKET_TYPE_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_UP_GRADE] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Mejora"),
#else
        .name = _("Upgrade"),
#endif
        .itemId = ITEM_UP_GRADE,
        .price = 2100,
        .holdEffect = HOLD_EFFECT_UP_GRADE,
        .description = sUpGradeDesc,
        .pocket = POCKET_POWER_UP,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_SHELL_BELL] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Cascabel Concha"),
#else
        .name = _("Shell Bell"),
#endif
        .itemId = ITEM_SHELL_BELL,
        .price = 200,
        .holdEffect = HOLD_EFFECT_SHELL_BELL,
        .holdEffectParam = 8,
        .description = sShellBellDesc,
        .pocket = POCKET_BATTLE_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_POWER_BRACER] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Brazal recio"),
#else
        .name = _("Power Bracer"),
#endif
        .itemId = ITEM_POWER_BRACER,
        .price = 5000,
        .holdEffect = HOLD_EFFECT_POWER_ITEM,
        .holdEffectParam = 4,
        .description = sPowerBracerDesc,
        .pocket = POCKET_POWER_UP,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = STAT_ATK,
    },

    [ITEM_POWER_BELT] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Cinto recio"),
#else
        .name = _("Power Belt"),
#endif
        .itemId = ITEM_POWER_BELT,
        .price = 5000,
        .holdEffect = HOLD_EFFECT_POWER_ITEM,
        .holdEffectParam = 4,
        .description = sPowerBeltDesc,
        .pocket = POCKET_POWER_UP,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = STAT_DEF,
    },

    [ITEM_POWER_LENS] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Lente recia"),
#else
        .name = _("Power Lens"),
#endif
        .itemId = ITEM_POWER_LENS,
        .price = 5000,
        .holdEffect = HOLD_EFFECT_POWER_ITEM,
        .holdEffectParam = 4,
        .description = sPowerLensDesc,
        .pocket = POCKET_POWER_UP,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = STAT_SPATK,
    },

    [ITEM_POWER_BAND] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Banda recia"),
#else
        .name = _("Power Band"),
#endif
        .itemId = ITEM_POWER_BAND,
        .price = 5000,
        .holdEffect = HOLD_EFFECT_POWER_ITEM,
        .holdEffectParam = 4,
        .description = sPowerBandDesc,
        .pocket = POCKET_POWER_UP,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = STAT_SPDEF,
    },

    [ITEM_POWER_ANKLET] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Franja recia"),
#else
        .name = _("Power Anklet"),
#endif
        .itemId = ITEM_POWER_ANKLET,
        .price = 5000,
        .holdEffect = HOLD_EFFECT_POWER_ITEM,
        .holdEffectParam = 4,
        .description = sPowerAnkletDesc,
        .pocket = POCKET_POWER_UP,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = STAT_SPEED,
    },

    [ITEM_POWER_WEIGHT] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Pesa recia"),
#else
        .name = _("Power Weight"),
#endif
        .itemId = ITEM_POWER_WEIGHT,
        .price = 5000,
        .holdEffect = HOLD_EFFECT_POWER_ITEM,
        .holdEffectParam = 4,
        .description = sPowerWeightDesc,
        .pocket = POCKET_POWER_UP,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = STAT_HP,
    },

    [ITEM_SEA_INCENSE] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Incienso marino"),
#else
        .name = _("Sea Incense"),
#endif
        .itemId = ITEM_SEA_INCENSE,
        .price = 2000,
        .holdEffect = HOLD_EFFECT_WATER_POWER,
        .holdEffectParam = 20,
        .description = sSeaIncenseDesc,
        .pocket = POCKET_POWER_UP,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_LAX_INCENSE] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Incienso suave"),
#else
        .name = _("Lax Incense"),
#endif
        .itemId = ITEM_LAX_INCENSE,
        .price = 5000,
        .holdEffect = HOLD_EFFECT_EVASION_UP,
        .holdEffectParam = 10,
        .description = sLaxIncenseDesc,
        .pocket = POCKET_POWER_UP,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_ODD_INCENSE] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Incienso raro"),
#else
        .name = _("Odd Incense"),
#endif
        .itemId = ITEM_ODD_INCENSE,
        .price = 2000,
        .holdEffect = HOLD_EFFECT_PSYCHIC_POWER,
        .holdEffectParam = 20,
        .description = sOddIncenseDesc,
        .pocket = POCKET_POWER_UP,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_ROCK_INCENSE] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Incienso roca"),
#else
        .name = _("Rock Incense"),
#endif
        .itemId = ITEM_ROCK_INCENSE,
        .price = 2000,
        .holdEffect = HOLD_EFFECT_ROCK_POWER,
        .holdEffectParam = 20,
        .description = sRockIncenseDesc,
        .pocket = POCKET_POWER_UP,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_FULL_INCENSE] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Incienso lento"),
#else
        .name = _("Full Incense"),
#endif
        .itemId = ITEM_FULL_INCENSE,
        .price = 5000,
        .holdEffect = HOLD_EFFECT_LAGGING_TAIL,
        .holdEffectParam = 5,
        .description = sFullIncenseDesc,
        .pocket = POCKET_POWER_UP,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_WAVE_INCENSE] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Incienso Acua"),
#else
        .name = _("Wave Incense"),
#endif
        .itemId = ITEM_WAVE_INCENSE,
        .price = 2000,
        .holdEffect = HOLD_EFFECT_WATER_POWER,
        .holdEffectParam = 20,
        .description = sWaveIncenseDesc,
        .pocket = POCKET_POWER_UP,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_ROSE_INCENSE] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Incienso floral"),
#else
        .name = _("Rose Incense"),
#endif
        .itemId = ITEM_ROSE_INCENSE,
        .price = 2000,
        .holdEffect = HOLD_EFFECT_GRASS_POWER,
        .holdEffectParam = 20,
        .description = sRoseIncenseDesc,
        .pocket = POCKET_POWER_UP,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_LUCK_INCENSE] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Incienso duplo"),
#else
        .name = _("Luck Incense"),
#endif
        .itemId = ITEM_LUCK_INCENSE,
        .price = 11000,
        .holdEffect = HOLD_EFFECT_DOUBLE_PRIZE,
        .holdEffectParam = 10,
        .description = sLuckIncenseDesc,
        .pocket = POCKET_POWER_UP,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_PURE_INCENSE] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Incienso puro"),
#else
        .name = _("Pure Incense"),
#endif
        .itemId = ITEM_PURE_INCENSE,
        .price = 6000,
        .holdEffect = HOLD_EFFECT_REPEL,
        .description = sPureIncenseDesc,
        .pocket = POCKET_POWER_UP,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_LUCKY_PUNCH] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Puño Suerte"),
#else
        .name = _("Lucky Punch"),
#endif
        .itemId = ITEM_LUCKY_PUNCH,
        .price = 5000,
        .holdEffect = HOLD_EFFECT_LUCKY_PUNCH,
        .description = sLuckyPunchDesc,
        .pocket = POCKET_BATTLE_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_METAL_POWDER] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Polvo Metálico"),
#else
        .name = _("Metal Powder"),
#endif
        .itemId = ITEM_METAL_POWDER,
        .price = 5000,
        .holdEffect = HOLD_EFFECT_METAL_POWDER,
        .description = sMetalPowderDesc,
        .pocket = POCKET_BATTLE_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_THICK_CLUB] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Hueso Grueso"),
#else
        .name = _("Thick Club"),
#endif
        .itemId = ITEM_THICK_CLUB,
        .price = 5000,
        .holdEffect = HOLD_EFFECT_THICK_CLUB,
        .description = sThickClubDesc,
        .pocket = POCKET_BATTLE_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_STICK] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Puerro"),
#else
        .name = _("Leek"),
#endif
        .itemId = ITEM_STICK,
        .price = 2000,
        .holdEffect = HOLD_EFFECT_STICK,
        .description = sStickDesc,
        .pocket = POCKET_BATTLE_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_RED_SCARF] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Pañuelo Rojo"),
#else
        .name = _("Red Scarf"),
#endif
        .itemId = ITEM_RED_SCARF,
        .price = 100,
        .description = sRedScarfDesc,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_BLUE_SCARF] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Pañuelo Azul"),
#else
        .name = _("Blue Scarf"),
#endif
        .itemId = ITEM_BLUE_SCARF,
        .price = 100,
        .description = sBlueScarfDesc,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_PINK_SCARF] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Pañuelo Rosa"),
#else
        .name = _("Pink Scarf"),
#endif
        .itemId = ITEM_PINK_SCARF,
        .price = 100,
        .description = sPinkScarfDesc,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_GREEN_SCARF] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Pañuelo Verde"),
#else
        .name = _("Green Scarf"),
#endif
        .itemId = ITEM_GREEN_SCARF,
        .price = 100,
        .description = sGreenScarfDesc,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_YELLOW_SCARF] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Pañuelo Amarillo"),
#else
        .name = _("Yellow Scarf"),
#endif
        .itemId = ITEM_YELLOW_SCARF,
        .price = 100,
        .description = sYellowScarfDesc,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

// Key items

    [ITEM_MACH_BIKE] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Bici Carrera"),
#else
        .name = _("Mach Bike"),
#endif
        .itemId = ITEM_MACH_BIKE,
        .price = 0,
        .description = sMachBikeDesc,
        .importance = 1,
        .unk19 = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = 2,
        .fieldUseFunc = ItemUseOutOfBattle_Bike,
        .secondaryId = 0,
    },

    [ITEM_COIN_CASE] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Monedero"),
#else
        .name = _("Coin Case"),
#endif
        .itemId = ITEM_COIN_CASE,
        .price = 0,
        .description = sCoinCaseDesc,
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CoinCase,
        .secondaryId = 0,
    },

    [ITEM_ITEMFINDER] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Zahorí"),
#else
        .name = _("Dowsing Machine"),
#endif
        .itemId = ITEM_ITEMFINDER,
        .price = 0,
        .description = sItemfinderDesc,
        .importance = 1,
        .unk19 = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = 2,
        .fieldUseFunc = ItemUseOutOfBattle_Itemfinder,
        .secondaryId = 0,
    },

    [ITEM_OLD_ROD] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Caña Vieja"),
#else
        .name = _("Old Rod"),
#endif
        .itemId = ITEM_OLD_ROD,
        .price = 0,
        .description = sOldRodDesc,
        .importance = 1,
        .unk19 = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = 2,
        .fieldUseFunc = ItemUseOutOfBattle_Rod,
        .secondaryId = OLD_ROD,
    },

    [ITEM_GOOD_ROD] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Caña Buena"),
#else
        .name = _("Good Rod"),
#endif
        .itemId = ITEM_GOOD_ROD,
        .price = 0,
        .description = sGoodRodDesc,
        .importance = 1,
        .unk19 = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = 2,
        .fieldUseFunc = ItemUseOutOfBattle_Rod,
        .secondaryId = GOOD_ROD,
    },

    [ITEM_SUPER_ROD] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Supercaña"),
#else
        .name = _("Super Rod"),
#endif
        .itemId = ITEM_SUPER_ROD,
        .price = 0,
        .description = sSuperRodDesc,
        .importance = 1,
        .unk19 = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = 2,
        .fieldUseFunc = ItemUseOutOfBattle_Rod,
        .secondaryId = SUPER_ROD,
    },

    [ITEM_SS_TICKET] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Ticket Barco"),
#else
        .name = _("S.S. Ticket"),
#endif
        .itemId = ITEM_SS_TICKET,
        .price = 0,
        .description = sSSTicketDesc,
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_CONTEST_PASS] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Pase Concurso"),
#else
        .name = _("Contest Pass"),
#endif
        .itemId = ITEM_CONTEST_PASS,
        .price = 0,
        .description = sContestPassDesc,
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_WAILMER_PAIL] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Wailmegadera"),
#else
        .name = _("Wailmer Pail"),
#endif
        .itemId = ITEM_WAILMER_PAIL,
        .price = 0,
        .description = sWailmerPailDesc,
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = 2,
        .fieldUseFunc = ItemUseOutOfBattle_WailmerPail,
        .secondaryId = 0,
    },

    [ITEM_DEVON_GOODS] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Piezas Devon"),
#else
        .name = _("Devon Goods"),
#endif
        .itemId = ITEM_DEVON_GOODS,
        .price = 0,
        .description = sDevonGoodsDesc,
        .importance = 2,
        .pocket = POCKET_KEY_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_SOOT_SACK] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Saco Hollín"),
#else
        .name = _("Soot Sack"),
#endif
        .itemId = ITEM_SOOT_SACK,
        .price = 0,
        .description = sSootSackDesc,
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_SootSack,
        .secondaryId = 0,
    },

    [ITEM_BASEMENT_KEY] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Llave Sótano"),
#else
        .name = _("Basement Key"),
#endif
        .itemId = ITEM_BASEMENT_KEY,
        .price = 0,
        .description = sBasementKeyDesc,
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_ACRO_BIKE] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Bici"),
#else
        .name = _("Bike"),
#endif
        .itemId = ITEM_ACRO_BIKE,
        .price = 0,
        .description = sAcroBikeDesc,
        .importance = 1,
        .unk19 = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = 2,
        .fieldUseFunc = ItemUseOutOfBattle_Bike,
        .secondaryId = 1,
    },

    [ITEM_POKEBLOCK_CASE] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Tubo {POKEBLOCK}"),
#else
        .name = _("{POKEBLOCK} case"),
#endif
        .itemId = ITEM_POKEBLOCK_CASE,
        .price = 0,
        .description = sPokeblockCaseDesc,
        .importance = 1,
        .unk19 = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = 3,
        .fieldUseFunc = ItemUseOutOfBattle_PokeblockCase,
        .secondaryId = 0,
    },

    [ITEM_LETTER] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Carta"),
#else
        .name = _("Letter"),
#endif
        .itemId = ITEM_LETTER,
        .price = 0,
        .description = sLetterDesc,
        .importance = 2,
        .pocket = POCKET_KEY_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_EON_TICKET] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Ticket Eón"),
#else
        .name = _("Eon Ticket"),
#endif
        .itemId = ITEM_EON_TICKET,
        .price = 0,
        .description = sEonTicketDesc,
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 1,
    },

    [ITEM_RED_ORB] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Esfera Roja"),
#else
        .name = _("Red Orb"),
#endif
        .itemId = ITEM_RED_ORB,
        .price = 0,
        .description = sRedOrbDesc,
        .importance = 2,
        .pocket = POCKET_KEY_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_BLUE_ORB] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Esfera Azul"),
#else
        .name = _("Blue Orb"),
#endif
        .itemId = ITEM_BLUE_ORB,
        .price = 0,
        .description = sBlueOrbDesc,
        .importance = 2,
        .pocket = POCKET_KEY_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_SCANNER] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Escáner"),
#else
        .name = _("Scanner"),
#endif
        .itemId = ITEM_SCANNER,
        .price = 0,
        .description = sScannerDesc,
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_GO_GOGGLES] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Gafas Aislantes"),
#else
        .name = _("Go-Goggles"),
#endif
        .itemId = ITEM_GO_GOGGLES,
        .price = 0,
        .description = sGoGogglesDesc,
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_METEORITE] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Meteorito"),
#else
        .name = _("Meteorite"),
#endif
        .itemId = ITEM_METEORITE,
        .price = 0,
        .description = sMeteoriteDesc,
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_ROOM_1_KEY] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Ll. Habitación 1"),
#else
        .name = _("Key to Room 1"),
#endif
        .itemId = ITEM_ROOM_1_KEY,
        .price = 0,
        .description = sRoom1KeyDesc,
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_ROOM_2_KEY] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Ll. Habitación 2"),
#else
        .name = _("Key to Room 2"),
#endif
        .itemId = ITEM_ROOM_2_KEY,
        .price = 0,
        .description = sRoom2KeyDesc,
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_ROOM_4_KEY] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Ll. Habitación 4"),
#else
        .name = _("Key to Room 4"),
#endif
        .itemId = ITEM_ROOM_4_KEY,
        .price = 0,
        .description = sRoom4KeyDesc,
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_ROOM_6_KEY] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Ll. Habitación 6"),
#else
        .name = _("Key to Room 6"),
#endif
        .itemId = ITEM_ROOM_6_KEY,
        .price = 0,
        .description = sRoom6KeyDesc,
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_STORAGE_KEY] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Llave Almacén"),
#else
        .name = _("Storage Key"),
#endif
        .itemId = ITEM_STORAGE_KEY,
        .price = 0,
        .description = sStorageKeyDesc,
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_DEVON_SCOPE] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Detector Devon"),
#else
        .name = _("Devon Scope"),
#endif
        .itemId = ITEM_DEVON_SCOPE,
        .price = 0,
        .description = sDevonScopeDesc,
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

// TMs/HMs

    [ITEM_TM01_FOCUS_PUNCH] =
    {
        .name = _("TM01"),
        .itemId = ITEM_TM01_FOCUS_PUNCH,
        .price = 50000,
        .description = sTM01Desc,
        .pocket = POCKET_TM_HM,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = 0,
        .importance = 1,
    },

    [ITEM_TM02_DRAGON_CLAW] =
    {
        .name = _("TM02"),
        .itemId = ITEM_TM02_DRAGON_CLAW,
        .price = 50000,
        .description = sTM02Desc,
        .pocket = POCKET_TM_HM,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = 0,
        .importance = 1,
    },

    [ITEM_TM03_WATER_PULSE] =
    {
        .name = _("TM03"),
        .itemId = ITEM_TM03_WATER_PULSE,
        .price = 50000,
        .description = sTM03Desc,
        .pocket = POCKET_TM_HM,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = 0,
        .importance = 1,
    },

    [ITEM_TM04_CALM_MIND] =
    {
        .name = _("TM04"),
        .itemId = ITEM_TM04_CALM_MIND,
        .price = 50000,
        .description = sTM04Desc,
        .pocket = POCKET_TM_HM,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = 0,
        .importance = 1,
    },

    [ITEM_TM05_ROAR] =
    {
        .name = _("TM05"),
        .itemId = ITEM_TM05_ROAR,
        .price = 50000,
        .description = sTM05Desc,
        .pocket = POCKET_TM_HM,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = 0,
        .importance = 1,
    },

    [ITEM_TM06_TOXIC] =
    {
        .name = _("TM06"),
        .itemId = ITEM_TM06_TOXIC,
        .price = 50000,
        .description = sTM06Desc,
        .pocket = POCKET_TM_HM,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = 0,
        .importance = 1,
    },

    [ITEM_TM07_HAIL] =
    {
        .name = _("TM07"),
        .itemId = ITEM_TM07_HAIL,
        .price = 50000,
        .description = sTM07Desc,
        .pocket = POCKET_TM_HM,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = 0,
        .importance = 1,
    },

    [ITEM_TM08_BULK_UP] =
    {
        .name = _("TM08"),
        .itemId = ITEM_TM08_BULK_UP,
        .price = 50000,
        .description = sTM08Desc,
        .pocket = POCKET_TM_HM,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = 0,
        .importance = 1,
    },

    [ITEM_TM09_BULLET_SEED] =
    {
        .name = _("TM09"),
        .itemId = ITEM_TM09_BULLET_SEED,
        .price = 50000,
        .description = sTM09Desc,
        .pocket = POCKET_TM_HM,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = 0,
        .importance = 1,
    },

    [ITEM_TM10_HIDDEN_POWER] =
    {
        .name = _("TM10"),
        .itemId = ITEM_TM10_HIDDEN_POWER,
        .price = 50000,
        .description = sTM10Desc,
        .pocket = POCKET_TM_HM,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = 0,
        .importance = 1,
    },

    [ITEM_TM11_SUNNY_DAY] =
    {
        .name = _("TM11"),
        .itemId = ITEM_TM11_SUNNY_DAY,
        .price = 50000,
        .description = sTM11Desc,
        .pocket = POCKET_TM_HM,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = 0,
        .importance = 1,
    },

    [ITEM_TM12_TAUNT] =
    {
        .name = _("TM12"),
        .itemId = ITEM_TM12_TAUNT,
        .price = 50000,
        .description = sTM12Desc,
        .pocket = POCKET_TM_HM,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = 0,
        .importance = 1,
    },

    [ITEM_TM13_ICE_BEAM] =
    {
        .name = _("TM13"),
        .itemId = ITEM_TM13_ICE_BEAM,
        .price = 50000,
        .description = sTM13Desc,
        .pocket = POCKET_TM_HM,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = 0,
        .importance = 1,
    },

    [ITEM_TM14_BLIZZARD] =
    {
        .name = _("TM14"),
        .itemId = ITEM_TM14_BLIZZARD,
        .price = 50000,
        .description = sTM14Desc,
        .pocket = POCKET_TM_HM,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = 0,
        .importance = 1,
    },

    [ITEM_TM15_HYPER_BEAM] =
    {
        .name = _("TM15"),
        .itemId = ITEM_TM15_HYPER_BEAM,
        .price = 50000,
        .description = sTM15Desc,
        .pocket = POCKET_TM_HM,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = 0,
        .importance = 1,
    },

    [ITEM_TM16_LIGHT_SCREEN] =
    {
        .name = _("TM16"),
        .itemId = ITEM_TM16_LIGHT_SCREEN,
        .price = 50000,
        .description = sTM16Desc,
        .pocket = POCKET_TM_HM,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = 0,
        .importance = 1,
    },

    [ITEM_TM17_PROTECT] =
    {
        .name = _("TM17"),
        .itemId = ITEM_TM17_PROTECT,
        .price = 50000,
        .description = sTM17Desc,
        .pocket = POCKET_TM_HM,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = 0,
        .importance = 1,
    },

    [ITEM_TM18_RAIN_DANCE] =
    {
        .name = _("TM18"),
        .itemId = ITEM_TM18_RAIN_DANCE,
        .price = 50000,
        .description = sTM18Desc,
        .pocket = POCKET_TM_HM,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = 0,
        .importance = 1,
    },

    [ITEM_TM19_GIGA_DRAIN] =
    {
        .name = _("TM19"),
        .itemId = ITEM_TM19_GIGA_DRAIN,
        .price = 50000,
        .description = sTM19Desc,
        .pocket = POCKET_TM_HM,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = 0,
        .importance = 1,
    },

    [ITEM_TM20_SAFEGUARD] =
    {
        .name = _("TM20"),
        .itemId = ITEM_TM20_SAFEGUARD,
        .price = 50000,
        .description = sTM20Desc,
        .pocket = POCKET_TM_HM,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = 0,
        .importance = 1,
    },

    [ITEM_TM21_FRUSTRATION] =
    {
        .name = _("TM21"),
        .itemId = ITEM_TM21_FRUSTRATION,
        .price = 50000,
        .description = sTM21Desc,
        .pocket = POCKET_TM_HM,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = 0,
        .importance = 1,
    },

    [ITEM_TM22_SOLARBEAM] =
    {
        .name = _("TM22"),
        .itemId = ITEM_TM22_SOLARBEAM,
        .price = 50000,
        .description = sTM22Desc,
        .pocket = POCKET_TM_HM,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = 0,
        .importance = 1,
    },

    [ITEM_TM23_IRON_TAIL] =
    {
        .name = _("TM23"),
        .itemId = ITEM_TM23_IRON_TAIL,
        .price = 50000,
        .description = sTM23Desc,
        .pocket = POCKET_TM_HM,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = 0,
        .importance = 1,
    },

    [ITEM_TM24_THUNDERBOLT] =
    {
        .name = _("TM24"),
        .itemId = ITEM_TM24_THUNDERBOLT,
        .price = 50000,
        .description = sTM24Desc,
        .pocket = POCKET_TM_HM,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = 0,
        .importance = 1,
    },

    [ITEM_TM25_THUNDER] =
    {
        .name = _("TM25"),
        .itemId = ITEM_TM25_THUNDER,
        .price = 50000,
        .description = sTM25Desc,
        .pocket = POCKET_TM_HM,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = 0,
        .importance = 1,
    },

    [ITEM_TM26_EARTHQUAKE] =
    {
        .name = _("TM26"),
        .itemId = ITEM_TM26_EARTHQUAKE,
        .price = 50000,
        .description = sTM26Desc,
        .pocket = POCKET_TM_HM,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = 0,
        .importance = 1,
    },

    [ITEM_TM27_RETURN] =
    {
        .name = _("TM27"),
        .itemId = ITEM_TM27_RETURN,
        .price = 50000,
        .description = sTM27Desc,
        .pocket = POCKET_TM_HM,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = 0,
        .importance = 1,
    },

    [ITEM_TM28_DIG] =
    {
        .name = _("TM28"),
        .itemId = ITEM_TM28_DIG,
        .price = 50000,
        .description = sTM28Desc,
        .pocket = POCKET_TM_HM,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = 0,
        .importance = 1,
    },

    [ITEM_TM29_PSYCHIC] =
    {
        .name = _("TM29"),
        .itemId = ITEM_TM29_PSYCHIC,
        .price = 50000,
        .description = sTM29Desc,
        .pocket = POCKET_TM_HM,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = 0,
        .importance = 1,
    },

    [ITEM_TM30_SHADOW_BALL] =
    {
        .name = _("TM30"),
        .itemId = ITEM_TM30_SHADOW_BALL,
        .price = 50000,
        .description = sTM30Desc,
        .pocket = POCKET_TM_HM,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = 0,
        .importance = 1,
    },

    [ITEM_TM31_BRICK_BREAK] =
    {
        .name = _("TM31"),
        .itemId = ITEM_TM31_BRICK_BREAK,
        .price = 50000,
        .description = sTM31Desc,
        .pocket = POCKET_TM_HM,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = 0,
        .importance = 1,
    },

    [ITEM_TM32_DOUBLE_TEAM] =
    {
        .name = _("TM32"),
        .itemId = ITEM_TM32_DOUBLE_TEAM,
        .price = 50000,
        .description = sTM32Desc,
        .pocket = POCKET_TM_HM,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = 0,
        .importance = 1,
    },

    [ITEM_TM33_REFLECT] =
    {
        .name = _("TM33"),
        .itemId = ITEM_TM33_REFLECT,
        .price = 50000,
        .description = sTM33Desc,
        .pocket = POCKET_TM_HM,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = 0,
        .importance = 1,
    },

    [ITEM_TM34_SHOCK_WAVE] =
    {
        .name = _("TM34"),
        .itemId = ITEM_TM34_SHOCK_WAVE,
        .price = 50000,
        .description = sTM34Desc,
        .pocket = POCKET_TM_HM,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = 0,
        .importance = 1,
    },

    [ITEM_TM35_FLAMETHROWER] =
    {
        .name = _("TM35"),
        .itemId = ITEM_TM35_FLAMETHROWER,
        .price = 50000,
        .description = sTM35Desc,
        .pocket = POCKET_TM_HM,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = 0,
        .importance = 1,
    },

    [ITEM_TM36_SLUDGE_BOMB] =
    {
        .name = _("TM36"),
        .itemId = ITEM_TM36_SLUDGE_BOMB,
        .price = 50000,
        .description = sTM36Desc,
        .pocket = POCKET_TM_HM,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = 0,
        .importance = 1,
    },

    [ITEM_TM37_SANDSTORM] =
    {
        .name = _("TM37"),
        .itemId = ITEM_TM37_SANDSTORM,
        .price = 50000,
        .description = sTM37Desc,
        .pocket = POCKET_TM_HM,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = 0,
        .importance = 1,
    },

    [ITEM_TM38_FIRE_BLAST] =
    {
        .name = _("TM38"),
        .itemId = ITEM_TM38_FIRE_BLAST,
        .price = 50000,
        .description = sTM38Desc,
        .pocket = POCKET_TM_HM,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = 0,
        .importance = 1,
    },

    [ITEM_TM39_ROCK_TOMB] =
    {
        .name = _("TM39"),
        .itemId = ITEM_TM39_ROCK_TOMB,
        .price = 50000,
        .description = sTM39Desc,
        .pocket = POCKET_TM_HM,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = 0,
        .importance = 1,
    },

    [ITEM_TM40_AERIAL_ACE] =
    {
        .name = _("TM40"),
        .itemId = ITEM_TM40_AERIAL_ACE,
        .price = 50000,
        .description = sTM40Desc,
        .pocket = POCKET_TM_HM,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = 0,
        .importance = 1,
    },

    [ITEM_TM41_TORMENT] =
    {
        .name = _("TM41"),
        .itemId = ITEM_TM41_TORMENT,
        .price = 50000,
        .description = sTM41Desc,
        .pocket = POCKET_TM_HM,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = 0,
        .importance = 1,
    },

    [ITEM_TM42_FACADE] =
    {
        .name = _("TM42"),
        .itemId = ITEM_TM42_FACADE,
        .price = 50000,
        .description = sTM42Desc,
        .pocket = POCKET_TM_HM,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = 0,
        .importance = 1,
    },

    [ITEM_TM43_SECRET_POWER] =
    {
        .name = _("TM43"),
        .itemId = ITEM_TM43_SECRET_POWER,
        .price = 50000,
        .description = sTM43Desc,
        .pocket = POCKET_TM_HM,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = 0,
        .importance = 1,
    },

    [ITEM_TM44_REST] =
    {
        .name = _("TM44"),
        .itemId = ITEM_TM44_REST,
        .price = 50000,
        .description = sTM44Desc,
        .pocket = POCKET_TM_HM,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = 0,
        .importance = 1,
    },

    [ITEM_TM45_ATTRACT] =
    {
        .name = _("TM45"),
        .itemId = ITEM_TM45_ATTRACT,
        .price = 50000,
        .description = sTM45Desc,
        .pocket = POCKET_TM_HM,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = 0,
        .importance = 1,
    },

    [ITEM_TM46_THIEF] =
    {
        .name = _("TM46"),
        .itemId = ITEM_TM46_THIEF,
        .price = 50000,
        .description = sTM46Desc,
        .pocket = POCKET_TM_HM,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = 0,
        .importance = 1,
    },

    [ITEM_TM47_STEEL_WING] =
    {
        .name = _("TM47"),
        .itemId = ITEM_TM47_STEEL_WING,
        .price = 50000,
        .description = sTM47Desc,
        .pocket = POCKET_TM_HM,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = 0,
        .importance = 1,
    },

    [ITEM_TM48_SKILL_SWAP] =
    {
        .name = _("TM48"),
        .itemId = ITEM_TM48_SKILL_SWAP,
        .price = 50000,
        .description = sTM48Desc,
        .pocket = POCKET_TM_HM,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = 0,
        .importance = 1,
    },

    [ITEM_TM49_SNATCH] =
    {
        .name = _("TM49"),
        .itemId = ITEM_TM49_SNATCH,
        .price = 50000,
        .description = sTM49Desc,
        .pocket = POCKET_TM_HM,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = 0,
        .importance = 1,
    },

    [ITEM_TM50_OVERHEAT] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("TM50"),
#else
        .name = _("TM50"),
#endif
        .itemId = ITEM_TM50_OVERHEAT,
        .price = 50000,
        .description = sTM50Desc,
        .pocket = POCKET_TM_HM,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = 0,
        .importance = 1,
    },
    
    [ITEM_TM51_LOW_SWEEP] =
    {
        .name = _("TM51"),
        .itemId = ITEM_TM51_LOW_SWEEP,
        .price = 50000,
        .description = sTM51Desc,
        .pocket = POCKET_TM_HM,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = 0,
        .importance = 1,
    },
    
    [ITEM_TM52_FOCUS_BLAST] =
    {
        .name = _("TM52"),
        .itemId = ITEM_TM52_FOCUS_BLAST,
        .price = 50000,
        .description = sTM52Desc,
        .pocket = POCKET_TM_HM,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = 0,
        .importance = 1,
    },
    
    [ITEM_TM53_ENERGY_BALL] =
    {
        .name = _("TM53"),
        .itemId = ITEM_TM53_ENERGY_BALL,
        .price = 50000,
        .description = sTM53Desc,
        .pocket = POCKET_TM_HM,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = 0,
        .importance = 1,
    },
    
    [ITEM_TM54_FALSE_SWIPE] =
    {
        .name = _("TM54"),
        .itemId = ITEM_TM54_FALSE_SWIPE,
        .price = 50000,
        .description = sTM54Desc,
        .pocket = POCKET_TM_HM,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = 0,
        .importance = 1,
    },
    
    [ITEM_TM55_SCALD] =
    {
        .name = _("TM55"),
        .itemId = ITEM_TM55_SCALD,
        .price = 50000,
        .description = sTM55Desc,
        .pocket = POCKET_TM_HM,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = 0,
        .importance = 1,
    },
    
    [ITEM_TM56_DARKEST_LARIAT] =
    {
        .name = _("TM56"),
        .itemId = ITEM_TM56_DARKEST_LARIAT,
        .price = 50000,
        .description = sTM56Desc,
        .pocket = POCKET_TM_HM,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = 0,
        .importance = 1,
    },
    
    [ITEM_TM57_CHARGE_BEAM] =
    {
        .name = _("TM57"),
        .itemId = ITEM_TM57_CHARGE_BEAM,
        .price = 50000,
        .description = sTM57Desc,
        .pocket = POCKET_TM_HM,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = 0,
        .importance = 1,
    },
    
    [ITEM_TM58_ROOST] =
    {
        .name = _("TM58"),
        .itemId = ITEM_TM58_ROOST,
        .price = 50000,
        .description = sTM58Desc,
        .pocket = POCKET_TM_HM,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = 0,
        .importance = 1,
    },
    
    [ITEM_TM59_BRUTAL_SWING] =
    {
        .name = _("TM59"),
        .itemId = ITEM_TM59_BRUTAL_SWING,
        .price = 50000,
        .description = sTM59Desc,
        .pocket = POCKET_TM_HM,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = 0,
        .importance = 1,
    },
    
    [ITEM_TM60_QUASH] =
    {
        .name = _("TM60"),
        .itemId = ITEM_TM60_QUASH,
        .price = 50000,
        .description = sTM60Desc,
        .pocket = POCKET_TM_HM,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = 0,
        .importance = 1,
    },
    
    [ITEM_TM61_WILL_O_WISP] =
    {
        .name = _("TM61"),
        .itemId = ITEM_TM61_WILL_O_WISP,
        .price = 50000,
        .description = sTM61Desc,
        .pocket = POCKET_TM_HM,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = 0,
        .importance = 1,
    },
    
    [ITEM_TM62_ACROBATICS] =
    {
        .name = _("TM62"),
        .itemId = ITEM_TM62_ACROBATICS,
        .price = 50000,
        .description = sTM62Desc,
        .pocket = POCKET_TM_HM,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = 0,
        .importance = 1,
    },
    
    [ITEM_TM63_EMBARGO] =
    {
        .name = _("TM63"),
        .itemId = ITEM_TM63_EMBARGO,
        .price = 50000,
        .description = sTM63Desc,
        .pocket = POCKET_TM_HM,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = 0,
        .importance = 1,
    },

    [ITEM_TM64_EXPLOSION] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("TM64"),
#else
        .name = _("TM64"),
#endif
        .itemId = ITEM_TM64_EXPLOSION,
        .price = 50000,
        .description = sTM64Desc,
        .pocket = POCKET_TM_HM,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = 0,
        .importance = 1,
    },
    
    [ITEM_TM65_SHADOW_CLAW] =
    {
        .name = _("TM65"),
        .itemId = ITEM_TM65_SHADOW_CLAW,
        .price = 50000,
        .description = sTM65Desc,
        .pocket = POCKET_TM_HM,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = 0,
        .importance = 1,
    },
    
    [ITEM_TM66_PAYBACK] =
    {
        .name = _("TM66"),
        .itemId = ITEM_TM66_PAYBACK,
        .price = 50000,
        .description = sTM66Desc,
        .pocket = POCKET_TM_HM,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = 0,
        .importance = 1,
    },
    
    [ITEM_TM67_SMART_STRIKE] =
    {
        .name = _("TM67"),
        .itemId = ITEM_TM67_SMART_STRIKE,
        .price = 50000,
        .description = sTM67Desc,
        .pocket = POCKET_TM_HM,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = 0,
        .importance = 1,
    },
    
    [ITEM_TM68_GIGA_IMPACT] =
    {
        .name = _("TM68"),
        .itemId = ITEM_TM68_GIGA_IMPACT,
        .price = 50000,
        .description = sTM68Desc,
        .pocket = POCKET_TM_HM,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = 0,
        .importance = 1,
    },
    
    [ITEM_TM69_ROCK_POLISH] =
    {
        .name = _("TM69"),
        .itemId = ITEM_TM69_ROCK_POLISH,
        .price = 50000,
        .description = sTM69Desc,
        .pocket = POCKET_TM_HM,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = 0,
        .importance = 1,
    },
    
    [ITEM_TM70_AURORA_VEIL] =
    {
        .name = _("TM70"),
        .itemId = ITEM_TM70_AURORA_VEIL,
        .price = 50000,
        .description = sTM70Desc,
        .pocket = POCKET_TM_HM,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = 0,
        .importance = 1,
    },
    
    [ITEM_TM71_STONE_EDGE] =
    {
        .name = _("TM71"),
        .itemId = ITEM_TM71_STONE_EDGE,
        .price = 50000,
        .description = sTM71Desc,
        .pocket = POCKET_TM_HM,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = 0,
        .importance = 1,
    },
    
    [ITEM_TM72_VOLT_SWITCH] =
    {
        .name = _("TM72"),
        .itemId = ITEM_TM72_VOLT_SWITCH,
        .price = 50000,
        .description = sTM72Desc,
        .pocket = POCKET_TM_HM,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = 0,
        .importance = 1,
    },
    
    [ITEM_TM73_THUNDER_WAVE] =
    {
        .name = _("TM73"),
        .itemId = ITEM_TM73_THUNDER_WAVE,
        .price = 50000,
        .description = sTM73Desc,
        .pocket = POCKET_TM_HM,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = 0,
        .importance = 1,
    },
    
    [ITEM_TM74_GYRO_BALL] =
    {
        .name = _("TM74"),
        .itemId = ITEM_TM74_GYRO_BALL,
        .price = 50000,
        .description = sTM74Desc,
        .pocket = POCKET_TM_HM,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = 0,
        .importance = 1,
    },
    
    [ITEM_TM75_SWORDS_DANCE] =
    {
        .name = _("TM75"),
        .itemId = ITEM_TM75_SWORDS_DANCE,
        .price = 50000,
        .description = sTM75Desc,
        .pocket = POCKET_TM_HM,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = 0,
        .importance = 1,
    },
    
    [ITEM_TM76_FLY] =
    {
        .name = _("TM76"),
        .itemId = ITEM_TM76_FLY,
        .price = 50000,
        .description = sTM76Desc,
        .pocket = POCKET_TM_HM,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = 0,
        .importance = 1,
    },
    
    [ITEM_TM77_PSYCH_UP] =
    {
        .name = _("TM77"),
        .itemId = ITEM_TM77_PSYCH_UP,
        .price = 50000,
        .description = sTM77Desc,
        .pocket = POCKET_TM_HM,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = 0,
        .importance = 1,
    },
    
    [ITEM_TM78_BULLDOZE] =
    {
        .name = _("TM78"),
        .itemId = ITEM_TM78_BULLDOZE,
        .price = 50000,
        .description = sTM78Desc,
        .pocket = POCKET_TM_HM,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = 0,
        .importance = 1,
    },
    
    [ITEM_TM79_FROST_BREATH] =
    {
        .name = _("TM79"),
        .itemId = ITEM_TM79_FROST_BREATH,
        .price = 50000,
        .description = sTM79Desc,
        .pocket = POCKET_TM_HM,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = 0,
        .importance = 1,
    },
    
    [ITEM_TM80_ROCK_SLIDE] =
    {
        .name = _("TM80"),
        .itemId = ITEM_TM80_ROCK_SLIDE,
        .price = 50000,
        .description = sTM80Desc,
        .pocket = POCKET_TM_HM,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = 0,
        .importance = 1,
    },
    
    [ITEM_TM81_X_SCISSOR] =
    {
        .name = _("TM81"),
        .itemId = ITEM_TM81_X_SCISSOR,
        .price = 50000,
        .description = sTM81Desc,
        .pocket = POCKET_TM_HM,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = 0,
        .importance = 1,
    },
    
    [ITEM_TM82_DRAGON_TAIL] =
    {
        .name = _("TM82"),
        .itemId = ITEM_TM82_DRAGON_TAIL,
        .price = 50000,
        .description = sTM82Desc,
        .pocket = POCKET_TM_HM,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = 0,
        .importance = 1,
    },
    
    [ITEM_TM83_INFESTATION] =
    {
        .name = _("TM83"),
        .itemId = ITEM_TM83_INFESTATION,
        .price = 50000,
        .description = sTM83Desc,
        .pocket = POCKET_TM_HM,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = 0,
        .importance = 1,
    },
    
    [ITEM_TM84_POISON_JAB] =
    {
        .name = _("TM84"),
        .itemId = ITEM_TM84_POISON_JAB,
        .price = 50000,
        .description = sTM84Desc,
        .pocket = POCKET_TM_HM,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = 0,
        .importance = 1,
    },
    
    [ITEM_TM85_DREAM_EATER] =
    {
        .name = _("TM85"),
        .itemId = ITEM_TM85_DREAM_EATER,
        .price = 50000,
        .description = sTM85Desc,
        .pocket = POCKET_TM_HM,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = 0,
        .importance = 1,
    },
    
    [ITEM_TM86_GRASS_KNOT] =
    {
        .name = _("TM86"),
        .itemId = ITEM_TM86_GRASS_KNOT,
        .price = 50000,
        .description = sTM86Desc,
        .pocket = POCKET_TM_HM,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = 0,
        .importance = 1,
    },
    
    [ITEM_TM87_SWAGGER] =
    {
        .name = _("TM87"),
        .itemId = ITEM_TM87_SWAGGER,
        .price = 50000,
        .description = sTM87Desc,
        .pocket = POCKET_TM_HM,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = 0,
        .importance = 1,
    },
    
    [ITEM_TM88_SLEEP_TALK] =
    {
        .name = _("TM88"),
        .itemId = ITEM_TM88_SLEEP_TALK,
        .price = 50000,
        .description = sTM88Desc,
        .pocket = POCKET_TM_HM,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = 0,
        .importance = 1,
    },
    
    [ITEM_TM89_U_TURN] =
    {
        .name = _("TM89"),
        .itemId = ITEM_TM89_U_TURN,
        .price = 50000,
        .description = sTM89Desc,
        .pocket = POCKET_TM_HM,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = 0,
        .importance = 1,
    },
    
    [ITEM_TM90_SUBSTITUTE] =
    {
        .name = _("TM90"),
        .itemId = ITEM_TM90_SUBSTITUTE,
        .price = 50000,
        .description = sTM90Desc,
        .pocket = POCKET_TM_HM,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = 0,
        .importance = 1,
    },
    
    [ITEM_TM91_FLASH_CANNON] =
    {
        .name = _("TM91"),
        .itemId = ITEM_TM91_FLASH_CANNON,
        .price = 50000,
        .description = sTM91Desc,
        .pocket = POCKET_TM_HM,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = 0,
        .importance = 1,
    },
    
    [ITEM_TM92_TRICK_ROOM] =
    {
        .name = _("TM92"),
        .itemId = ITEM_TM92_TRICK_ROOM,
        .price = 50000,
        .description = sTM92Desc,
        .pocket = POCKET_TM_HM,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = 0,
        .importance = 1,
    },
    
    [ITEM_TM93_WILD_CHARGE] =
    {
        .name = _("TM93"),
        .itemId = ITEM_TM93_WILD_CHARGE,
        .price = 50000,
        .description = sTM93Desc,
        .pocket = POCKET_TM_HM,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = 0,
        .importance = 1,
    },
    
    [ITEM_TM94_SURF] =
    {
        .name = _("TM94"),
        .itemId = ITEM_TM94_SURF,
        .price = 50000,
        .description = sTM94Desc,
        .importance = 1,
        .pocket = POCKET_TM_HM,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },  

    [ITEM_TM95_SNARL] =
    {
        .name = _("TM95"),
        .itemId = ITEM_TM95_SNARL,
        .price = 50000,
        .description = sTM95Desc,
        .pocket = POCKET_TM_HM,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = 0,
        .importance = 1,
    },    
    
    [ITEM_TM96_NATURE_POWER] =
    {
        .name = _("TM96"),
        .itemId = ITEM_TM96_NATURE_POWER,
        .price = 50000,
        .description = sTM96Desc,
        .pocket = POCKET_TM_HM,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = 0,
        .importance = 1,
    },    
    
    [ITEM_TM97_DARK_PULSE] =
    {
        .name = _("TM97"),
        .itemId = ITEM_TM97_DARK_PULSE,
        .price = 50000,
        .description = sTM97Desc,
        .pocket = POCKET_TM_HM,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = 0,
        .importance = 1,
    },    
    
    [ITEM_TM98_WATERFALL] =
    {
        .name = _("TM98"),
        .itemId = ITEM_TM98_WATERFALL,
        .price = 50000,
        .description = sTM98Desc,
        .importance = 1,
        .pocket = POCKET_TM_HM,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = 0,
    },
    
    [ITEM_TM99_DAZZLING_GLEAM] =
    {
        .name = _("TM99"),
        .itemId = ITEM_TM99_DAZZLING_GLEAM,
        .price = 50000,
        .description = sTM99Desc,
        .pocket = POCKET_TM_HM,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = 0,
        .importance = 1,
    },    
    
    [ITEM_TM100_CONFIDE] =
    {
        .name = _("TM100"),
        .itemId = ITEM_TM100_CONFIDE,
        .price = 50000,
        .description = sTM100Desc,
        .pocket = POCKET_TM_HM,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = 0,
        .importance = 1,
    },    
    
    [ITEM_TM101_SLUDGE_WAVE] =
    {
        .name = _("TM101"),
        .itemId = ITEM_TM101_SLUDGE_WAVE,
        .price = 50000,
        .description = sTM101Desc,
        .pocket = POCKET_TM_HM,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = 0,
        .importance = 1,
    },    
    
    [ITEM_TM102_LIQUIDATION] =
    {
        .name = _("TM102"),
        .itemId = ITEM_TM102_LIQUIDATION,
        .price = 50000,
        .description = sTM102Desc,
        .pocket = POCKET_TM_HM,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = 0,
        .importance = 1,
    },    
    
    [ITEM_TM103_LEECH_LIFE] =
    {
        .name = _("TM103"),
        .itemId = ITEM_TM103_LEECH_LIFE,
        .price = 50000,
        .description = sTM103Desc,
        .pocket = POCKET_TM_HM,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = 0,
        .importance = 1,
    },    
    
    [ITEM_TM104_PLAY_ROUGH] =
    {
        .name = _("TM104"),
        .itemId = ITEM_TM104_PLAY_ROUGH,
        .price = 50000,
        .description = sTM104Desc,
        .pocket = POCKET_TM_HM,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = 0,
        .importance = 1,
    },    
    
    [ITEM_TM105_PSYSHOCK] =
    {
        .name = _("TM105"),
        .itemId = ITEM_TM105_PSYSHOCK,
        .price = 50000,
        .description = sTM105Desc,
        .pocket = POCKET_TM_HM,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = 0,
        .importance = 1,
    },    
    
    [ITEM_TM106_AURA_SPHERE] =
    {
        .name = _("TM106"),
        .itemId = ITEM_TM106_AURA_SPHERE,
        .price = 50000,
        .description = sTM106Desc,
        .pocket = POCKET_TM_HM,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = 0,
        .importance = 1,
    },    
    
    [ITEM_TM107_POWER_GEM] =
    {
        .name = _("TM107"),
        .itemId = ITEM_TM107_POWER_GEM,
        .price = 50000,
        .description = sTM107Desc,
        .pocket = POCKET_TM_HM,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = 0,
        .importance = 1,
    },    
    
    [ITEM_TM108_EARTH_POWER] =
    {
        .name = _("TM108"),
        .itemId = ITEM_TM108_EARTH_POWER,
        .price = 50000,
        .description = sTM108Desc,
        .pocket = POCKET_TM_HM,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = 0,
        .importance = 1,
    },    

    [ITEM_TM109_GUNK_SHOT] =
    {
        .name = _("TM109"),
        .itemId = ITEM_TM109_GUNK_SHOT,
        .price = 50000,
        .description = sTM109Desc,
        .pocket = POCKET_TM_HM,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = 0,
        .importance = 1,
    },    
    
    [ITEM_TM110_STEALTH_ROCK] =
    {
        .name = _("TM110"),
        .itemId = ITEM_TM110_STEALTH_ROCK,
        .price = 50000,
        .description = sTM110Desc,
        .pocket = POCKET_TM_HM,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = 0,
        .importance = 1,
    },    
    
    [ITEM_TM111_HEAT_CRASH] =
    {
        .name = _("TM111"),
        .itemId = ITEM_TM111_HEAT_CRASH,
        .price = 50000,
        .description = sTM111Desc,
        .pocket = POCKET_TM_HM,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = 0,
        .importance = 1,
    },    
    
    [ITEM_TM112_POLLEN_PUFF] =
    {
        .name = _("TM112"),
        .itemId = ITEM_TM112_POLLEN_PUFF,
        .price = 50000,
        .description = sTM112Desc,
        .pocket = POCKET_TM_HM,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = 0,
        .importance = 1,
    },    
    
    [ITEM_TM113_NASTY_PLOT] =
    {
        .name = _("TM113"),
        .itemId = ITEM_TM113_NASTY_PLOT,
        .price = 50000,
        .description = sTM113Desc,
        .pocket = POCKET_TM_HM,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = 0,
        .importance = 1,
    },    
    
    [ITEM_TM114_BRAVE_BIRD] =
    {
        .name = _("TM114"),
        .itemId = ITEM_TM114_BRAVE_BIRD,
        .price = 50000,
        .description = sTM114Desc,
        .pocket = POCKET_TM_HM,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = 0,
        .importance = 1,
    },
    
    [ITEM_TM115_BUG_BUZZ] =
    {
        .name = _("TM115"),
        .itemId = ITEM_TM115_BUG_BUZZ,
        .price = 50000,
        .description = sTM115Desc,
        .pocket = POCKET_TM_HM,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = 0,
        .importance = 1,
    },
    
    [ITEM_TM116_DRAGON_DANCE] =
    {
        .name = _("TM116"),
        .itemId = ITEM_TM116_DRAGON_DANCE,
        .price = 50000,
        .description = sTM116Desc,
        .pocket = POCKET_TM_HM,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = 0,
        .importance = 1,
    },
    
    [ITEM_TM117_BLAZE_KICK] =
    {
        .name = _("TM117"),
        .itemId = ITEM_TM117_BLAZE_KICK,
        .price = 50000,
        .description = sTM117Desc,
        .pocket = POCKET_TM_HM,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = 0,
        .importance = 1,
    },
    
    [ITEM_TM118_TRI_ATTACK] =
    {
        .name = _("TM118"),
        .itemId = ITEM_TM118_TRI_ATTACK,
        .price = 50000,
        .description = sTM118Desc,
        .pocket = POCKET_TM_HM,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = 0,
        .importance = 1,
    },
    
    [ITEM_TM119_DRAIN_PUNCH] =
    {
        .name = _("TM119"),
        .itemId = ITEM_TM119_DRAIN_PUNCH,
        .price = 50000,
        .description = sTM119Desc,
        .pocket = POCKET_TM_HM,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = 0,
        .importance = 1,
    },
    
    [ITEM_TM120_MYSTICAL_FIRE] =
    {
        .name = _("TM120"),
        .itemId = ITEM_TM120_MYSTICAL_FIRE,
        .price = 50000,
        .description = sTM120Desc,
        .pocket = POCKET_TM_HM,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = 0,
        .importance = 1,
    },

    [ITEM_HM01_CUT] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("HM01"),
#else
        .name = _("HM01"),
#endif
        .itemId = ITEM_HM01_CUT,
        .price = 0,
        .description = sHM01Desc,
        .importance = 1,
        .pocket = POCKET_TM_HM,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = 0,
    },

    [ITEM_HM02_FLY] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("HM02"),
#else
        .name = _("HM02"),
#endif
        .itemId = ITEM_HM02_FLY,
        .price = 0,
        .description = sHM02Desc,
        .importance = 1,
        .pocket = POCKET_TM_HM,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = 0,
    },

    [ITEM_HM03_SURF] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("HM03"),
#else
        .name = _("HM03"),
#endif
        .itemId = ITEM_HM03_SURF,
        .price = 0,
        .description = sHM03Desc,
        .importance = 1,
        .pocket = POCKET_TM_HM,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = 0,
    },

    [ITEM_HM04_STRENGTH] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("HM04"),
#else
        .name = _("HM04"),
#endif
        .itemId = ITEM_HM04_STRENGTH,
        .price = 0,
        .description = sHM04Desc,
        .importance = 1,
        .pocket = POCKET_TM_HM,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = 0,
    },

    [ITEM_HM05_FLASH] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("HM05"),
#else
        .name = _("HM05"),
#endif
        .itemId = ITEM_HM05_FLASH,
        .price = 0,
        .description = sHM05Desc,
        .importance = 1,
        .pocket = POCKET_TM_HM,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = 0,
    },

    [ITEM_HM06_ROCK_SMASH] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("HM06"),
#else
        .name = _("HM06"),
#endif
        .itemId = ITEM_HM06_ROCK_SMASH,
        .price = 0,
        .description = sHM06Desc,
        .importance = 1,
        .pocket = POCKET_TM_HM,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = 0,
    },

    [ITEM_HM07_WATERFALL] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("HM07"),
#else
        .name = _("HM07"),
#endif
        .itemId = ITEM_HM07_WATERFALL,
        .price = 0,
        .description = sHM07Desc,
        .importance = 1,
        .pocket = POCKET_TM_HM,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = 0,
    },

    [ITEM_HM08_DIVE] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("HM08"),
#else
        .name = _("HM08"),
#endif
        .itemId = ITEM_HM08_DIVE,
        .price = 0,
        .description = sHM08Desc,
        .importance = 1,
        .pocket = POCKET_TM_HM,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = 0,
    },

    [ITEM_HEAVY_DUTY_BOOTS] =
    {
        .name = _("HeavyDutyBoots"),
        .itemId = ITEM_HEAVY_DUTY_BOOTS,
        .price = 9000,
        .holdEffect = HOLD_EFFECT_HEAVY_DUTY_BOOTS,
        .description = sHeavyDutyBootsDesc,
        .pocket = POCKET_BATTLE_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_BIKE_VOUCHER] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Bono Bici"),
#else
        .name = _("Bike Voucher"),
#endif
        .itemId = ITEM_BIKE_VOUCHER,
        .price = 0,
        .description = sBikeVoucherDesc,
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_GOLD_TEETH] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Dientes Oro"),
#else
        .name = _("Gold Teeth"),
#endif
        .itemId = ITEM_GOLD_TEETH,
        .price = 0,
        .description = sGoldTeethDesc,
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_OLD_AMBER] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Ámbar Viejo"),
#else
        .name = _("Old Amber"),
#endif
        .itemId = ITEM_OLD_AMBER,
        .price = 0,
        .description = sOldAmberDesc,
        #if I_KEY_FOSSILS >= GEN_4
            .importance = 0,
            .pocket = POCKET_ITEMS,
        #else
            .importance = 1,
            .pocket = POCKET_KEY_ITEMS,
        #endif
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_CARD_KEY] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Llave Magnética"),
#else
        .name = _("Card Key"),
#endif
        .itemId = ITEM_CARD_KEY,
        .price = 0,
        .description = sCardKeyDesc,
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_LIFT_KEY] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Llave Ascensor"),
#else
        .name = _("Lift Key"),
#endif
        .itemId = ITEM_LIFT_KEY,
        .price = 0,
        .description = sLiftKeyDesc,
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_ARMOR_FOSSIL] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Fósil Coraza"),
#else
        .name = _("Armor Fossil"),
#endif
        .itemId = ITEM_ARMOR_FOSSIL,
        .price = 0,
        .description = sArmorFossilDesc,
        .importance = 0,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_SKULL_FOSSIL] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Fósil Cráneo"),
#else
        .name = _("Skull Fossil"),
#endif
        .itemId = ITEM_SKULL_FOSSIL,
        .price = 0,
        .description = sSkullFossilDesc,
        .importance = 0,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_HELIX_FOSSIL] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Fósil Helix"),
#else
        .name = _("Helix Fossil"),
#endif
        .itemId = ITEM_HELIX_FOSSIL,
        .price = 0,
        .description = sHelixFossilDesc,
        #if I_KEY_FOSSILS >= GEN_4
            .importance = 0,
            .pocket = POCKET_ITEMS,
        #else
            .importance = 1,
            .pocket = POCKET_KEY_ITEMS,
        #endif
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_DOME_FOSSIL] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Fósil Domo"),
#else
        .name = _("Dome Fossil"),
#endif
        .itemId = ITEM_DOME_FOSSIL,
        .price = 0,
        .description = sDomeFossilDesc,
        #if I_KEY_FOSSILS >= GEN_4
            .importance = 0,
            .pocket = POCKET_ITEMS,
        #else
            .importance = 1,
            .pocket = POCKET_KEY_ITEMS,
        #endif
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_ROOT_FOSSIL] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Fósil Raíz"),
#else
        .name = _("Root Fossil"),
#endif
        .itemId = ITEM_ROOT_FOSSIL,
        .price = 0,
        .description = sRootFossilDesc,
        #if I_KEY_FOSSILS >= GEN_4
            .importance = 0,
            .pocket = POCKET_ITEMS,
        #else
            .importance = 1,
            .pocket = POCKET_KEY_ITEMS,
        #endif
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_CLAW_FOSSIL] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Fósil Garra"),
#else
        .name = _("Claw Fossil"),
#endif
        .itemId = ITEM_CLAW_FOSSIL,
        .price = 0,
        .description = sClawFossilDesc,
        #if I_KEY_FOSSILS >= GEN_4
            .importance = 0,
            .pocket = POCKET_ITEMS,
        #else
            .importance = 1,
            .pocket = POCKET_KEY_ITEMS,
        #endif
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_COVER_FOSSIL] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Fósil Tapa"),
#else
        .name = _("Cover Fossil"),
#endif
        .itemId = ITEM_COVER_FOSSIL,
        .price = 0,
        .description = sCoverFossilDesc,
        .importance = 0,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_PLUME_FOSSIL] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Fósil Pluma"),
#else
        .name = _("Plume Fossil"),
#endif
        .itemId = ITEM_PLUME_FOSSIL,
        .price = 0,
        .description = sPlumeFossilDesc,
        .importance = 0,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_JAW_FOSSIL] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Fósil Mandíbula"),
#else
        .name = _("Jaw Fossil"),
#endif
        .itemId = ITEM_JAW_FOSSIL,
        .price = 0,
        .description = sJawFossilDesc,
        .importance = 0,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_SAIL_FOSSIL] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Fósil Aleta"),
#else
        .name = _("Sail Fossil"),
#endif
        .itemId = ITEM_SAIL_FOSSIL,
        .price = 0,
        .description = sSailFossilDesc,
        .importance = 0,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_SILPH_SCOPE] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Visor Silph"),
#else
        .name = _("Silph Scope"),
#endif
        .itemId = ITEM_SILPH_SCOPE,
        .price = 0,
        .description = sSilphScopeDesc,
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_BICYCLE] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Bicicleta"),
#else
        .name = _("Bicycle"),
#endif
        .itemId = ITEM_BICYCLE,
        .price = 0,
        .description = sBicycleDesc,
        .importance = 1,
        .unk19 = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = 2,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_TOWN_MAP] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Mapa"),
#else
        .name = _("Town Map"),
#endif
        .itemId = ITEM_TOWN_MAP,
        .price = 0,
        .description = sTownMapDesc,
        .importance = 1,
        .unk19 = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_VS_SEEKER] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Buscapelea"),
#else
        .name = _("Vs Seeker"),
#endif
        .itemId = ITEM_VS_SEEKER,
        .price = 0,
        .description = sVSSeekerDesc,
        .importance = 1,
        .unk19 = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = 2,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_FAME_CHECKER] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Memorín"),
#else
        .name = _("Fame Checker"),
#endif
        .itemId = ITEM_FAME_CHECKER,
        .price = 0,
        .description = sFameCheckerDesc,
        .importance = 1,
        .unk19 = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_TM_CASE] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Tubo MT-MO"),
#else
        .name = _("TM Case"),
#endif
        .itemId = ITEM_TM_CASE,
        .price = 0,
        .description = sTMCaseDesc,
        .importance = 1,
        .unk19 = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_BERRY_POUCH] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Saco Bayas"),
#else
        .name = _("Berry Pouch"),
#endif
        .itemId = ITEM_BERRY_POUCH,
        .price = 0,
        .description = sBerryPouchDesc,
        .importance = 1,
        .unk19 = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_TEACHY_TV] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Poké Tele"),
#else
        .name = _("Ride Pager"),
#endif
        .itemId = ITEM_TEACHY_TV,
        .price = 0,
        .description = sTeachyTVDesc,
        .importance = 1,
        .unk19 = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = 2,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_TRI_PASS] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Tri-Ticket"),
#else
        .name = _("Tri-Pass"),
#endif
        .itemId = ITEM_TRI_PASS,
        .price = 0,
        .description = sTriPassDesc,
        .importance = 1,
        .unk19 = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_RAINBOW_PASS] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Iris-Ticket"),
#else
        .name = _("Rainbow Pass"),
#endif
        .itemId = ITEM_RAINBOW_PASS,
        .price = 0,
        .description = sRainbowPassDesc,
        .importance = 1,
        .unk19 = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_TEA] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Té"),
#else
        .name = _("Tea"),
#endif
        .itemId = ITEM_TEA,
        .price = 0,
        .description = sTeaDesc,
        .importance = 1,
        .unk19 = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_MYSTIC_TICKET] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Misti-Ticket"),
#else
        .name = _("Mystic Ticket"),
#endif
        .itemId = ITEM_MYSTIC_TICKET,
        .price = 0,
        .description = sMysticTicketDesc,
        .importance = 1,
        .unk19 = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_AURORA_TICKET] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Ori-Ticket"),
#else
        .name = _("Aurora Ticket"),
#endif
        .itemId = ITEM_AURORA_TICKET,
        .price = 0,
        .description = sAuroraTicketDesc,
        .importance = 1,
        .unk19 = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_POWDER_JAR] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Bote Polvos"),
#else
        .name = _("Powder Jar"),
#endif
        .itemId = ITEM_POWDER_JAR,
        .price = 0,
        .description = sPowderJarDesc,
        .importance = 1,
        .unk19 = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_PowderJar,
        .secondaryId = 0,
    },

    [ITEM_RUBY] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Rubí"),
#else
        .name = _("Ruby"),
#endif
        .itemId = ITEM_RUBY,
        .price = 0,
        .description = sRubyDesc,
        .importance = 1,
        .unk19 = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_SAPPHIRE] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Zafiro"),
#else
        .name = _("Sapphire"),
#endif
        .itemId = ITEM_SAPPHIRE,
        .price = 0,
        .description = sSapphireDesc,
        .importance = 1,
        .unk19 = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

// Emerald-specific key items

    [ITEM_MAGMA_EMBLEM] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Signo Magma"),
#else
        .name = _("Magma Emblem"),
#endif
        .itemId = ITEM_MAGMA_EMBLEM,
        .price = 0,
        .description = sMagmaEmblemDesc,
        .importance = 1,
        .unk19 = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_OLD_SEA_MAP] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Mapa Viejo"),
#else
        .name = _("Old Sea Map"),
#endif
        .itemId = ITEM_OLD_SEA_MAP,
        .price = 0,
        .description = sOldSeaMapDesc,
        .importance = 1,
        .unk19 = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

// New items

    [ITEM_WIDE_LENS] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Lupa"),
#else
        .name = _("Wide Lens"),
#endif
        .itemId = ITEM_WIDE_LENS,
        .price = 200,
        .holdEffect = HOLD_EFFECT_WIDE_LENS,
        .holdEffectParam = 10,
        .description = sWideLensDesc,
        .pocket = POCKET_BATTLE_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_MUSCLE_BAND] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Cinta Fuerte"),
#else
        .name = _("Muscle Band"),
#endif
        .itemId = ITEM_MUSCLE_BAND,
        .price = 200,
        .holdEffect = HOLD_EFFECT_MUSCLE_BAND,
        .holdEffectParam = 10,
        .description = sMuscleBandDesc,
        .pocket = POCKET_BATTLE_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_WISE_GLASSES] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Gafas Especiales"),
#else
        .name = _("Wise Glasses"),
#endif
        .itemId = ITEM_WISE_GLASSES,
        .price = 200,
        .holdEffect = HOLD_EFFECT_WISE_GLASSES,
        .holdEffectParam = 10,
        .description = sWiseGlassesDesc,
        .pocket = POCKET_BATTLE_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_EXPERT_BELT] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Cinta Experto"),
#else
        .name = _("Expert Belt"),
#endif
        .itemId = ITEM_EXPERT_BELT,
        .price = 200,
        .holdEffect = HOLD_EFFECT_EXPERT_BELT,
        .holdEffectParam = 20,
        .description = sExpertBeltDesc,
        .pocket = POCKET_BATTLE_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_LIGHT_CLAY] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Refleluz"),
#else
        .name = _("Light Clay"),
#endif
        .itemId = ITEM_LIGHT_CLAY,
        .price = 200,
        .holdEffect = HOLD_EFFECT_LIGHT_CLAY,
        .description = sLightClayDesc,
        .pocket = POCKET_BATTLE_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_LIFE_ORB] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Vidasfera"),
#else
        .name = _("Life Orb"),
#endif
        .itemId = ITEM_LIFE_ORB,
        .price = 9000,
        .holdEffect = HOLD_EFFECT_LIFE_ORB,
        .description = sLifeOrbDesc,
        .pocket = POCKET_BATTLE_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_POWER_HERB] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Hierba Única"),
#else
        .name = _("Power Herb"),
#endif
        .itemId = ITEM_POWER_HERB,
        .price = 5000,
        .holdEffect = HOLD_EFFECT_POWER_HERB,
        .description = sPowerHerbDesc,
        .pocket = POCKET_BATTLE_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_TOXIC_ORB] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Toxisfera"),
#else
        .name = _("Toxic Orb"),
#endif
        .itemId = ITEM_TOXIC_ORB,
        .price = 9000,
        .holdEffect = HOLD_EFFECT_TOXIC_ORB,
        .description = sToxicOrbDesc,
        .pocket = POCKET_BATTLE_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_FLAME_ORB] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Llamasfera"),
#else
        .name = _("Flame Orb"),
#endif
        .itemId = ITEM_FLAME_ORB,
        .price = 9000,
        .holdEffect = HOLD_EFFECT_FLAME_ORB,
        .description = sFlameOrbDesc,
        .pocket = POCKET_BATTLE_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_QUICK_POWDER] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Polvo Veloz"),
#else
        .name = _("Quick Powder"),
#endif
        .itemId = ITEM_QUICK_POWDER,
        .price = 5000,
        .holdEffect = HOLD_EFFECT_QUICK_POWDER,
        .description = sQuickPowderDesc,
        .pocket = POCKET_BATTLE_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_FOCUS_SASH] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Banda Focus"),
#else
        .name = _("Focus Sash"),
#endif
        .itemId = ITEM_FOCUS_SASH,
        .price = 5000,
        .holdEffect = HOLD_EFFECT_FOCUS_SASH,
        .description = sFocusSashDesc,
        .pocket = POCKET_BATTLE_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_ZOOM_LENS] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Telescopio"),
#else
        .name = _("Zoom Lens"),
#endif
        .itemId = ITEM_ZOOM_LENS,
        .price = 200,
        .holdEffect = HOLD_EFFECT_ZOOM_LENS,
        .holdEffectParam = 20,
        .description = sZoomLensDesc,
        .pocket = POCKET_BATTLE_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_METRONOME] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Metrónomo"),
#else
        .name = _("Metronome"),
#endif
        .itemId = ITEM_METRONOME,
        .price = 200,
        .holdEffect = HOLD_EFFECT_METRONOME,
        .holdEffectParam = 20,
        .description = sMetronomeDesc,
        .pocket = POCKET_BATTLE_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_IRON_BALL] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Bola Férrea"),
#else
        .name = _("Iron Ball"),
#endif
        .itemId = ITEM_IRON_BALL,
        .price = 200,
        .holdEffect = HOLD_EFFECT_IRON_BALL,
        .description = sIronBallDesc,
        .pocket = POCKET_BATTLE_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_LAGGING_TAIL] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Cola Plúmbea"),
#else
        .name = _("Lagging Tail"),
#endif
        .itemId = ITEM_LAGGING_TAIL,
        .price = 200,
        .holdEffect = HOLD_EFFECT_LAGGING_TAIL,
        .description = sLaggingTailDesc,
        .pocket = POCKET_BATTLE_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_DESTINY_KNOT] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Lazo Destino"),
#else
        .name = _("Destiny Knot"),
#endif
        .itemId = ITEM_DESTINY_KNOT,
        .price = 200,
        .holdEffect = HOLD_EFFECT_DESTINY_KNOT,
        .description = sDestinyKnotDesc,
        .pocket = POCKET_BATTLE_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_BLACK_SLUDGE] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Lodo Negro"),
#else
        .name = _("Black Sludge"),
#endif
        .itemId = ITEM_BLACK_SLUDGE,
        .price = 10000,
        .holdEffect = HOLD_EFFECT_BLACK_SLUDGE,
        .description = sBlackSludgeDesc,
        .pocket = POCKET_BATTLE_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_ICY_ROCK] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Roca Helada"),
#else
        .name = _("Icy Rock"),
#endif
        .itemId = ITEM_ICY_ROCK,
        .price = 200,
        .holdEffect = HOLD_EFFECT_ICY_ROCK,
        .description = sIcyRockDesc,
        .pocket = POCKET_BATTLE_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_SMOOTH_ROCK] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Roca Suave"),
#else
        .name = _("Smooth Rock"),
#endif
        .itemId = ITEM_SMOOTH_ROCK,
        .price = 200,
        .holdEffect = HOLD_EFFECT_SMOOTH_ROCK,
        .description = sSmoothRockDesc,
        .pocket = POCKET_BATTLE_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_HEAT_ROCK] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Roca Calor"),
#else
        .name = _("Heat Rock"),
#endif
        .itemId = ITEM_HEAT_ROCK,
        .price = 200,
        .holdEffect = HOLD_EFFECT_HEAT_ROCK,
        .description = sHeatRockDesc,
        .pocket = POCKET_BATTLE_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_DAMP_ROCK] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Roca Lluvia"),
#else
        .name = _("Damp Rock"),
#endif
        .itemId = ITEM_DAMP_ROCK,
        .price = 200,
        .holdEffect = HOLD_EFFECT_DAMP_ROCK,
        .description = sDampRockDesc,
        .pocket = POCKET_BATTLE_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_GRIP_CLAW] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Garra Garfio"),
#else
        .name = _("Grip Claw"),
#endif
        .itemId = ITEM_GRIP_CLAW,
        .price = 200,
        .holdEffect = HOLD_EFFECT_GRIP_CLAW,
        .description = sGripClawDesc,
        .pocket = POCKET_BATTLE_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_CHOICE_SCARF] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Pañuelo Elección"),
#else
        .name = _("Choice Scarf"),
#endif
        .itemId = ITEM_CHOICE_SCARF,
        .price = 10000,
        .holdEffect = HOLD_EFFECT_CHOICE_SCARF,
        .description = sChoiceScarfDesc,
        .pocket = POCKET_BATTLE_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_STICKY_BARB] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Toxiestrella"),
#else
        .name = _("Sticky Barb"),
#endif
        .itemId = ITEM_STICKY_BARB,
        .price = 200,
        .holdEffect = HOLD_EFFECT_STICKY_BARB,
        .description = sStickyBarbDesc,
        .pocket = POCKET_BATTLE_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_SHED_SHELL] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Muda Concha"),
#else
        .name = _("Shed Shell"),
#endif
        .itemId = ITEM_SHED_SHELL,
        .price = 200,
        .holdEffect = HOLD_EFFECT_SHED_SHELL,
        .description = sShedShellDesc,
        .pocket = POCKET_BATTLE_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_BIG_ROOT] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Raíz Grande"),
#else
        .name = _("Big Root"),
#endif
        .itemId = ITEM_BIG_ROOT,
        .price = 200,
        .holdEffect = HOLD_EFFECT_BIG_ROOT,
        .holdEffectParam = 30,
        .description = sBigRootDesc,
        .pocket = POCKET_BATTLE_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_CHOICE_SPECS] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Gafas Elección"),
#else
        .name = _("Choice Specs"),
#endif
        .itemId = ITEM_CHOICE_SPECS,
        .price = 10000,
        .holdEffect = HOLD_EFFECT_CHOICE_SPECS,
        .description = sChoiceSpecsDesc,
        .pocket = POCKET_BATTLE_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_ODD_KEYSTONE] =
    {
        .name = _("Odd Keystone"),
        .itemId = ITEM_ODD_KEYSTONE,
        .price = 2100,
        .description = sOddKeystoneDesc,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_ADAMANT_ORB] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Diamansfera"),
#else
        .name = _("Adamant Orb"),
#endif
        .itemId = ITEM_ADAMANT_ORB,
        .price = 200,
        .holdEffect = HOLD_EFFECT_ADAMANT_ORB,
        .description = sAdamantOrbDesc,
        .pocket = POCKET_BATTLE_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_LUSTROUS_ORB] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Lustresfera"),
#else
        .name = _("Lustrous Orb"),
#endif
        .itemId = ITEM_LUSTROUS_ORB,
        .price = 200,
        .holdEffect = HOLD_EFFECT_LUSTROUS_ORB,
        .description = sLustrousOrbDesc,
        .pocket = POCKET_BATTLE_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_GRISEOUS_ORB] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Griseosfera"),
#else
        .name = _("Griseous Orb"),
#endif
        .itemId = ITEM_GRISEOUS_ORB,
        .price = 200,
        .holdEffect = HOLD_EFFECT_GRISEOUS_ORB,
        .description = sGriseousOrbDesc,
        .pocket = POCKET_BATTLE_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_GRACIDEA] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Gracídea"),
#else
        .name = _("Gracidea"),
#endif
        .itemId = ITEM_GRACIDEA,
        .price = 200,
        .description = sGracideaDesc,
        .pocket = POCKET_KEY_ITEMS,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_FormChangeItem,
        .secondaryId = 0,
    },

    [ITEM_BUG_MEMORY] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Disco Bicho"),
#else
        .name = _("Bug Memory"),
#endif
        .itemId = ITEM_BUG_MEMORY,
        .price = 4900,
        .holdEffect = HOLD_EFFECT_MEMORY,
        .holdEffectParam = 0,
        .description = sBugMemoryDesc,
        .pocket = POCKET_BATTLE_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_BUG,
    },

    [ITEM_DARK_MEMORY] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Disco Siniestro"),
#else
        .name = _("Dark Memory"),
#endif
        .itemId = ITEM_DARK_MEMORY,
        .price = 4900,
        .holdEffect = HOLD_EFFECT_MEMORY,
        .holdEffectParam = 0,
        .description = sDarkMemoryDesc,
        .pocket = POCKET_BATTLE_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_DARK,
    },

    [ITEM_DRAGON_MEMORY] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Disco Dragón"),
#else
        .name = _("Dragon Memory"),
#endif
        .itemId = ITEM_DRAGON_MEMORY,
        .price = 4900,
        .holdEffect = HOLD_EFFECT_MEMORY,
        .holdEffectParam = 0,
        .description = sDragonMemoryDesc,
        .pocket = POCKET_BATTLE_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_DRAGON,
    },

    [ITEM_ELECTRIC_MEMORY] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Disco Eléctrico"),
#else
        .name = _("Elec. Memory"),
#endif
        .itemId = ITEM_ELECTRIC_MEMORY,
        .price = 4900,
        .holdEffect = HOLD_EFFECT_MEMORY,
        .holdEffectParam = 0,
        .description = sElectricMemoryDesc,
        .pocket = POCKET_BATTLE_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_ELECTRIC,
    },

    [ITEM_FAIRY_MEMORY] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Disco Hada"),
#else
        .name = _("Fairy Memory"),
#endif
        .itemId = ITEM_FAIRY_MEMORY,
        .price = 4900,
        .holdEffect = HOLD_EFFECT_MEMORY,
        .holdEffectParam = 0,
        .description = sFairyMemoryDesc,
        .pocket = POCKET_BATTLE_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_FAIRY,
    },

    [ITEM_FIGHTING_MEMORY] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Disco Lucha"),
#else
        .name = _("Fight Memory"),
#endif
        .itemId = ITEM_FIGHTING_MEMORY,
        .price = 4900,
        .holdEffect = HOLD_EFFECT_MEMORY,
        .holdEffectParam = 0,
        .description = sFightingMemoryDesc,
        .pocket = POCKET_BATTLE_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_FIGHTING,
    },

    [ITEM_FIRE_MEMORY] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Disco Lucha"),
#else
        .name = _("Fire Memory"),
#endif
        .itemId = ITEM_FIRE_MEMORY,
        .price = 4900,
        .holdEffect = HOLD_EFFECT_MEMORY,
        .holdEffectParam = 0,
        .description = sFireMemoryDesc,
        .pocket = POCKET_BATTLE_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_FIRE,
    },

    [ITEM_FLYING_MEMORY] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Disco Lucha"),
#else
        .name = _("Flying Memory"),
#endif
        .itemId = ITEM_FLYING_MEMORY,
        .price = 4900,
        .holdEffect = HOLD_EFFECT_MEMORY,
        .holdEffectParam = 0,
        .description = sFlyingMemoryDesc,
        .pocket = POCKET_BATTLE_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_FLYING,
    },

    [ITEM_GHOST_MEMORY] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Disco Fantasma"),
#else
        .name = _("Ghost Memory"),
#endif
        .itemId = ITEM_GHOST_MEMORY,
        .price = 4900,
        .holdEffect = HOLD_EFFECT_MEMORY,
        .holdEffectParam = 0,
        .description = sGhostMemoryDesc,
        .pocket = POCKET_BATTLE_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_GHOST,
    },

    [ITEM_GRASS_MEMORY] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Disco Planta"),
#else
        .name = _("Grass Memory"),
#endif
        .itemId = ITEM_GRASS_MEMORY,
        .price = 4900,
        .holdEffect = HOLD_EFFECT_MEMORY,
        .holdEffectParam = 0,
        .description = sGrassMemoryDesc,
        .pocket = POCKET_BATTLE_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_GRASS,
    },

    [ITEM_GROUND_MEMORY] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Disco Tierra"),
#else
        .name = _("Ground Memory"),
#endif
        .itemId = ITEM_GROUND_MEMORY,
        .price = 4900,
        .holdEffect = HOLD_EFFECT_MEMORY,
        .holdEffectParam = 0,
        .description = sGroundMemoryDesc,
        .pocket = POCKET_BATTLE_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_GROUND,
    },

    [ITEM_ICE_MEMORY] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Disco Hielo"),
#else
        .name = _("Ice Memory"),
#endif
        .itemId = ITEM_ICE_MEMORY,
        .price = 4900,
        .holdEffect = HOLD_EFFECT_MEMORY,
        .holdEffectParam = 0,
        .description = sIceMemoryDesc,
        .pocket = POCKET_BATTLE_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_ICE,
    },

    [ITEM_POISON_MEMORY] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Disco Veneno"),
#else
        .name = _("Poison Memory"),
#endif
        .itemId = ITEM_POISON_MEMORY,
        .price = 4900,
        .holdEffect = HOLD_EFFECT_MEMORY,
        .holdEffectParam = 0,
        .description = sPoisonMemoryDesc,
        .pocket = POCKET_BATTLE_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_POISON,
    },

    [ITEM_PSYCHIC_MEMORY] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Disco Psíquico"),
#else
        .name = _("Psychic Memory"),
#endif
        .itemId = ITEM_PSYCHIC_MEMORY,
        .price = 4900,
        .holdEffect = HOLD_EFFECT_MEMORY,
        .holdEffectParam = 0,
        .description = sPsychicMemoryDesc,
        .pocket = POCKET_BATTLE_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_PSYCHIC,
    },

    [ITEM_ROCK_MEMORY] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Disco Roca"),
#else
        .name = _("Rock Memory"),
#endif
        .itemId = ITEM_ROCK_MEMORY,
        .price = 4900,
        .holdEffect = HOLD_EFFECT_MEMORY,
        .holdEffectParam = 0,
        .description = sRockMemoryDesc,
        .pocket = POCKET_BATTLE_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_ROCK,
    },

    [ITEM_STEEL_MEMORY] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Disco Acero"),
#else
        .name = _("Steel Memory"),
#endif
        .itemId = ITEM_STEEL_MEMORY,
        .price = 4900,
        .holdEffect = HOLD_EFFECT_MEMORY,
        .holdEffectParam = 0,
        .description = sSteelMemoryDesc,
        .pocket = POCKET_BATTLE_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_STEEL,
    },

    [ITEM_WATER_MEMORY] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Disco Agua"),
#else
        .name = _("Water Memory"),
#endif
        .itemId = ITEM_WATER_MEMORY,
        .price = 4900,
        .holdEffect = HOLD_EFFECT_MEMORY,
        .holdEffectParam = 0,
        .description = sWaterMemoryDesc,
        .pocket = POCKET_BATTLE_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_WATER,
    },

    [ITEM_FLAME_PLATE] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Tabla Llama"),
#else
        .name = _("Flame Plate"),
#endif
        .itemId = ITEM_FLAME_PLATE,
        .price = 200,
        .holdEffect = HOLD_EFFECT_PLATE,
        .holdEffectParam = 20,
        .description = sFlamePlateDesc,
        .pocket = POCKET_TYPE_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_FIRE,
    },

    [ITEM_SPLASH_PLATE] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Tabla Linfa"),
#else
        .name = _("Splash Plate"),
#endif
        .itemId = ITEM_SPLASH_PLATE,
        .price = 200,
        .holdEffect = HOLD_EFFECT_PLATE,
        .holdEffectParam = 20,
        .description = sSplashPlateDesc,
        .pocket = POCKET_TYPE_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_WATER,
    },

    [ITEM_ZAP_PLATE] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Tabla Trueno"),
#else
        .name = _("Zap Plate"),
#endif
        .itemId = ITEM_ZAP_PLATE,
        .price = 200,
        .holdEffect = HOLD_EFFECT_PLATE,
        .holdEffectParam = 20,
        .description = sZapPlateDesc,
        .pocket = POCKET_TYPE_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_ELECTRIC,
    },

    [ITEM_MEADOW_PLATE] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Tabla Pradal"),
#else
        .name = _("Meadow Plate"),
#endif
        .itemId = ITEM_MEADOW_PLATE,
        .price = 200,
        .holdEffect = HOLD_EFFECT_PLATE,
        .holdEffectParam = 20,
        .description = sMeadowPlateDesc,
        .pocket = POCKET_TYPE_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_GRASS,
    },

    [ITEM_ICICLE_PLATE] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Tabla Helada"),
#else
        .name = _("Icicle Plate"),
#endif
        .itemId = ITEM_ICICLE_PLATE,
        .price = 200,
        .holdEffect = HOLD_EFFECT_PLATE,
        .holdEffectParam = 20,
        .description = sIciclePlateDesc,
        .pocket = POCKET_TYPE_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_ICE,
    },

    [ITEM_FIST_PLATE] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Tabla Fuerte"),
#else
        .name = _("Fist Plate"),
#endif
        .itemId = ITEM_FIST_PLATE,
        .price = 200,
        .holdEffect = HOLD_EFFECT_PLATE,
        .holdEffectParam = 20,
        .description = sFistPlateDesc,
        .pocket = POCKET_TYPE_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_FIGHTING,
    },

    [ITEM_TOXIC_PLATE] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Tabla Tóxica"),
#else
        .name = _("Toxic Plate"),
#endif
        .itemId = ITEM_TOXIC_PLATE,
        .price = 200,
        .holdEffect = HOLD_EFFECT_PLATE,
        .holdEffectParam = 20,
        .description = sToxicPlateDesc,
        .pocket = POCKET_TYPE_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_POISON,
    },

    [ITEM_EARTH_PLATE] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Tabla Terrax"),
#else
        .name = _("Earth Plate"),
#endif
        .itemId = ITEM_EARTH_PLATE,
        .price = 200,
        .holdEffect = HOLD_EFFECT_PLATE,
        .holdEffectParam = 20,
        .description = sEarthPlateDesc,
        .pocket = POCKET_TYPE_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_GROUND,
    },

    [ITEM_SKY_PLATE] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Tabla Cielo"),
#else
        .name = _("Sky Plate"),
#endif
        .itemId = ITEM_SKY_PLATE,
        .price = 200,
        .holdEffect = HOLD_EFFECT_PLATE,
        .holdEffectParam = 20,
        .description = sSkyPlateDesc,
        .pocket = POCKET_TYPE_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_FLYING,
    },

    [ITEM_MIND_PLATE] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Tabla Mental"),
#else
        .name = _("Mind Plate"),
#endif
        .itemId = ITEM_MIND_PLATE,
        .price = 200,
        .holdEffect = HOLD_EFFECT_PLATE,
        .holdEffectParam = 20,
        .description = sMindPlateDesc,
        .pocket = POCKET_TYPE_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_PSYCHIC,
    },

    [ITEM_INSECT_PLATE] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Tabla Bicho"),
#else
        .name = _("Insect Plate"),
#endif
        .itemId = ITEM_INSECT_PLATE,
        .price = 200,
        .holdEffect = HOLD_EFFECT_PLATE,
        .holdEffectParam = 20,
        .description = sInsectPlateDesc,
        .pocket = POCKET_TYPE_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_BUG,
    },

    [ITEM_STONE_PLATE] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Tabla Pétrea"),
#else
        .name = _("Stone Plate"),
#endif
        .itemId = ITEM_STONE_PLATE,
        .price = 200,
        .holdEffect = HOLD_EFFECT_PLATE,
        .holdEffectParam = 20,
        .description = sStonePlateDesc,
        .pocket = POCKET_TYPE_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_ROCK,
    },

    [ITEM_SPOOKY_PLATE] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Tabla Terror"),
#else
        .name = _("Spooky Plate"),
#endif
        .itemId = ITEM_SPOOKY_PLATE,
        .price = 200,
        .holdEffect = HOLD_EFFECT_PLATE,
        .holdEffectParam = 20,
        .description = sSpookyPlateDesc,
        .pocket = POCKET_TYPE_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_GHOST,
    },

    [ITEM_DRACO_PLATE] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Tabla Draco"),
#else
        .name = _("Draco Plate"),
#endif
        .itemId = ITEM_DRACO_PLATE,
        .price = 200,
        .holdEffect = HOLD_EFFECT_PLATE,
        .holdEffectParam = 20,
        .description = sDracoPlateDesc,
        .pocket = POCKET_TYPE_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_DRAGON,
    },

    [ITEM_DREAD_PLATE] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Tabla Oscura"),
#else
        .name = _("Dread Plate"),
#endif
        .itemId = ITEM_DREAD_PLATE,
        .price = 200,
        .holdEffect = HOLD_EFFECT_PLATE,
        .holdEffectParam = 20,
        .description = sDreadPlateDesc,
        .pocket = POCKET_TYPE_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_DARK,
    },

    [ITEM_IRON_PLATE] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Tabla Acero"),
#else
        .name = _("Iron Plate"),
#endif
        .itemId = ITEM_IRON_PLATE,
        .price = 200,
        .holdEffect = HOLD_EFFECT_PLATE,
        .holdEffectParam = 20,
        .description = sIronPlateDesc,
        .pocket = POCKET_TYPE_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_STEEL,
    },

    [ITEM_EVIOLITE] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Mineral Evolutivo"),
#else
        .name = _("Eviolite"),
#endif
        .itemId = ITEM_EVIOLITE,
        .price = 200,
        .holdEffect = HOLD_EFFECT_EVIOLITE,
        .holdEffectParam = 50,
        .description = sEvioliteDesc,
        .pocket = POCKET_BATTLE_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_FLOAT_STONE] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Piedra Pómez"),
#else
        .name = _("Float Stone"),
#endif
        .itemId = ITEM_FLOAT_STONE,
        .price = 200,
        .holdEffect = HOLD_EFFECT_FLOAT_STONE,
        .description = sFloatStoneDesc,
        .pocket = POCKET_BATTLE_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_ROCKY_HELMET] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Casco Dentado"),
#else
        .name = _("Rocky Helmet"),
#endif
        .itemId = ITEM_ROCKY_HELMET,
        .price = 9000,
        .holdEffect = HOLD_EFFECT_ROCKY_HELMET,
        .holdEffectParam = 0,
        .description = sRockyHelmetDesc,
        .pocket = POCKET_BATTLE_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_AIR_BALLOON] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Globo Helio"),
#else
        .name = _("Air Balloon"),
#endif
        .itemId = ITEM_AIR_BALLOON,
        .price = 2000,
        .holdEffect = HOLD_EFFECT_AIR_BALLOON,
        .holdEffectParam = 0,
        .description = sAirBalloonDesc,
        .pocket = POCKET_BATTLE_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_RED_CARD] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Tarjeta Roja"),
#else
        .name = _("Red Card"),
#endif
        .itemId = ITEM_RED_CARD,
        .price = 2000,
        .holdEffect = HOLD_EFFECT_RED_CARD,
        .holdEffectParam = 0,
        .description = sRedCardDesc,
        .pocket = POCKET_BATTLE_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_RING_TARGET] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Blanco"),
#else
        .name = _("Ring Target"),
#endif
        .itemId = ITEM_RING_TARGET,
        .price = 2000,
        .holdEffect = HOLD_EFFECT_RING_TARGET,
        .holdEffectParam = 0,
        .description = sRingTargetDesc,
        .pocket = POCKET_BATTLE_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_BINDING_BAND] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Banda Atadura"),
#else
        .name = _("Binding Band"),
#endif
        .itemId = ITEM_BINDING_BAND,
        .price = 2000,
        .holdEffect = HOLD_EFFECT_BINDING_BAND,
        .description = sBindingBandDesc,
        .pocket = POCKET_BATTLE_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_EJECT_BUTTON] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Botón Escape"),
#else
        .name = _("Eject Button"),
#endif
        .itemId = ITEM_EJECT_BUTTON,
        .price = 2000,
        .holdEffect = HOLD_EFFECT_EJECT_BUTTON,
        .holdEffectParam = 0,
        .description = sEjectButtonDesc,
        .pocket = POCKET_BATTLE_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_ABSORB_BULB] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Tubérculo"),
#else
        .name = _("Absorb Bulb"),
#endif
        .itemId = ITEM_ABSORB_BULB,
        .price = 2000,
        .holdEffect = HOLD_EFFECT_ABSORB_BULB,
        .holdEffectParam = 0,
        .description = sAbsorbBulbDesc,
        .pocket = POCKET_BATTLE_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_CELL_BATTERY] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Pila"),
#else
        .name = _("Cell Battery"),
#endif
        .itemId = ITEM_CELL_BATTERY,
        .price = 2000,
        .holdEffect = HOLD_EFFECT_CELL_BATTERY,
        .holdEffectParam = 0,
        .description = sCellBatteryDesc,
        .pocket = POCKET_BATTLE_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_LUMINOUS_MOSS] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Musgo Brillante"),
#else
        .name = _("Luminous Moss"),
#endif
        .itemId = ITEM_LUMINOUS_MOSS,
        .price = 2000,
        .holdEffect = HOLD_EFFECT_LUMINOUS_MOSS,
        .holdEffectParam = 0,
        .description = sLuminousMossDesc,
        .pocket = POCKET_BATTLE_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_SNOWBALL] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Bola de Nieve"),
#else
        .name = _("Snowball"),
#endif
        .itemId = ITEM_SNOWBALL,
        .price = 2000,
        .holdEffect = HOLD_EFFECT_SNOWBALL,
        .holdEffectParam = 0,
        .description = sSnowballDesc,
        .pocket = POCKET_BATTLE_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_WEAKNESS_POLICY] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Seguro Debilidad"),
#else
        .name = _("Weakness Policy"),
#endif
        .itemId = ITEM_WEAKNESS_POLICY,
        .price = 5000,
        .holdEffect = HOLD_EFFECT_WEAKNESS_POLICY,
        .holdEffectParam = 0,
        .description = sWeaknessPolicyDesc,
        .pocket = POCKET_BATTLE_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_DOUSE_DRIVE] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("HidroROM"),
#else
        .name = _("Douse Drive"),
#endif
        .itemId = ITEM_DOUSE_DRIVE,
        .price = 200,
        .holdEffect = HOLD_EFFECT_DRIVE,
        .description = sDouseDriveDesc,
        .pocket = POCKET_BATTLE_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_WATER,
    },

    [ITEM_SHOCK_DRIVE] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("FulgoROM"),
#else
        .name = _("Shock Drive"),
#endif
        .itemId = ITEM_SHOCK_DRIVE,
        .price = 200,
        .holdEffect = HOLD_EFFECT_DRIVE,
        .description = sShockDriveDesc,
        .pocket = POCKET_BATTLE_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_ELECTRIC,
    },

    [ITEM_BURN_DRIVE] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("PiroROM"),
#else
        .name = _("Burn Drive"),
#endif
        .itemId = ITEM_BURN_DRIVE,
        .price = 200,
        .holdEffect = HOLD_EFFECT_DRIVE,
        .description = sBurnDriveDesc,
        .pocket = POCKET_BATTLE_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_FIRE,
    },

    [ITEM_CHILL_DRIVE] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("CrioROM"),
#else
        .name = _("Chill Drive"),
#endif
        .itemId = ITEM_CHILL_DRIVE,
        .price = 200,
        .holdEffect = HOLD_EFFECT_DRIVE,
        .description = sChillDriveDesc,
        .pocket = POCKET_BATTLE_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_ICE,
    },

    [ITEM_FIRE_GEM] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Gema Fuego"),
#else
        .name = _("Fire Gem"),
#endif
        .itemId = ITEM_FIRE_GEM,
        .price = 5000,
        .holdEffect = HOLD_EFFECT_GEMS,
        .holdEffectParam = 30,
        .description = sFireGemDesc,
        .pocket = POCKET_POWER_UP,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_TypeGem,
        .secondaryId = TYPE_FIRE,
    },

    [ITEM_WATER_GEM] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Gema Agua"),
#else
        .name = _("Water Gem"),
#endif
        .itemId = ITEM_WATER_GEM,
        .price = 5000,
        .holdEffect = HOLD_EFFECT_GEMS,
        .holdEffectParam = 30,
        .description = sWaterGemDesc,
        .pocket = POCKET_POWER_UP,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_TypeGem,
        .secondaryId = TYPE_WATER,
    },

    [ITEM_ELECTRIC_GEM] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Gema Eléctrica"),
#else
        .name = _("Electric Gem"),
#endif
        .itemId = ITEM_ELECTRIC_GEM,
        .price = 5000,
        .holdEffect = HOLD_EFFECT_GEMS,
        .holdEffectParam = 30,
        .description = sElectricGemDesc,
        .pocket = POCKET_POWER_UP,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_TypeGem,
        .secondaryId = TYPE_ELECTRIC,
    },

    [ITEM_GRASS_GEM] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Gema Planta"),
#else
        .name = _("Grass Gem"),
#endif
        .itemId = ITEM_GRASS_GEM,
        .price = 5000,
        .holdEffect = HOLD_EFFECT_GEMS,
        .holdEffectParam = 30,
        .description = sGrassGemDesc,
        .pocket = POCKET_POWER_UP,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_TypeGem,
        .secondaryId = TYPE_GRASS,
    },

    [ITEM_ICE_GEM] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Gema Hielo"),
#else
        .name = _("Ice Gem"),
#endif
        .itemId = ITEM_ICE_GEM,
        .price = 5000,
        .holdEffect = HOLD_EFFECT_GEMS,
        .holdEffectParam = 30,
        .description = sIceGemDesc,
        .pocket = POCKET_POWER_UP,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_TypeGem,
        .secondaryId = TYPE_ICE,
    },

    [ITEM_FIGHTING_GEM] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Gema Lucha"),
#else
        .name = _("Fighting Gem"),
#endif
        .itemId = ITEM_FIGHTING_GEM,
        .price = 5000,
        .holdEffect = HOLD_EFFECT_GEMS,
        .holdEffectParam = 30,
        .description = sFightingGemDesc,
        .pocket = POCKET_POWER_UP,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_TypeGem,
        .secondaryId = TYPE_FIGHTING,
    },

    [ITEM_POISON_GEM] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Gema Veneno"),
#else
        .name = _("Poison Gem"),
#endif
        .itemId = ITEM_POISON_GEM,
        .price = 5000,
        .holdEffect = HOLD_EFFECT_GEMS,
        .holdEffectParam = 30,
        .description = sPoisonGemDesc,
        .pocket = POCKET_POWER_UP,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_TypeGem,
        .secondaryId = TYPE_POISON,
    },

    [ITEM_GROUND_GEM] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Gema Tierra"),
#else
        .name = _("Ground Gem"),
#endif
        .itemId = ITEM_GROUND_GEM,
        .price = 5000,
        .holdEffect = HOLD_EFFECT_GEMS,
        .holdEffectParam = 30,
        .description = sGroundGemDesc,
        .pocket = POCKET_POWER_UP,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_TypeGem,
        .secondaryId = TYPE_GROUND,
    },

    [ITEM_FLYING_GEM] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Gema Voladora"),
#else
        .name = _("Flying Gem"),
#endif
        .itemId = ITEM_FLYING_GEM,
        .price = 5000,
        .holdEffect = HOLD_EFFECT_GEMS,
        .holdEffectParam = 30,
        .description = sFlyingGemDesc,
        .pocket = POCKET_POWER_UP,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_TypeGem,
        .secondaryId = TYPE_FLYING,
    },

    [ITEM_PSYCHIC_GEM] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Gema Psíquica"),
#else
        .name = _("Psychic Gem"),
#endif
        .itemId = ITEM_PSYCHIC_GEM,
        .price = 5000,
        .holdEffect = HOLD_EFFECT_GEMS,
        .holdEffectParam = 30,
        .description = sPsychicGemDesc,
        .pocket = POCKET_POWER_UP,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_TypeGem,
        .secondaryId = TYPE_PSYCHIC,
    },

    [ITEM_BUG_GEM] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Gema Bicho"),
#else
        .name = _("Bug Gem"),
#endif
        .itemId = ITEM_BUG_GEM,
        .price = 5000,
        .holdEffect = HOLD_EFFECT_GEMS,
        .holdEffectParam = 30,
        .description = sBugGemDesc,
        .pocket = POCKET_POWER_UP,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_TypeGem,
        .secondaryId = TYPE_BUG,
    },

    [ITEM_ROCK_GEM] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Gema Roca"),
#else
        .name = _("Rock Gem"),
#endif
        .itemId = ITEM_ROCK_GEM,
        .price = 5000,
        .holdEffect = HOLD_EFFECT_GEMS,
        .holdEffectParam = 30,
        .description = sRockGemDesc,
        .pocket = POCKET_POWER_UP,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_TypeGem,
        .secondaryId = TYPE_ROCK,
    },

    [ITEM_GHOST_GEM] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Gema Fantasma"),
#else
        .name = _("Ghost Gem"),
#endif
        .itemId = ITEM_GHOST_GEM,
        .price = 5000,
        .holdEffect = HOLD_EFFECT_GEMS,
        .holdEffectParam = 30,
        .description = sGhostGemDesc,
        .pocket = POCKET_POWER_UP,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_TypeGem,
        .secondaryId = TYPE_GHOST,
    },

    [ITEM_DRAGON_GEM] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Gema Dragón"),
#else
        .name = _("Dragon Gem"),
#endif
        .itemId = ITEM_DRAGON_GEM,
        .price = 5000,
        .holdEffect = HOLD_EFFECT_GEMS,
        .holdEffectParam = 30,
        .description = sDragonGemDesc,
        .pocket = POCKET_POWER_UP,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_TypeGem,
        .secondaryId = TYPE_DRAGON,
    },

    [ITEM_DARK_GEM] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Gema Siniestra"),
#else
        .name = _("Dark Gem"),
#endif
        .itemId = ITEM_DARK_GEM,
        .price = 5000,
        .holdEffect = HOLD_EFFECT_GEMS,
        .holdEffectParam = 30,
        .description = sDarkGemDesc,
        .pocket = POCKET_POWER_UP,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_TypeGem,
        .secondaryId = TYPE_DARK,
    },

    [ITEM_STEEL_GEM] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Gema Acero"),
#else
        .name = _("Steel Gem"),
#endif
        .itemId = ITEM_STEEL_GEM,
        .price = 5000,
        .holdEffect = HOLD_EFFECT_GEMS,
        .holdEffectParam = 30,
        .description = sSteelGemDesc,
        .pocket = POCKET_POWER_UP,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_TypeGem,
        .secondaryId = TYPE_STEEL,
    },

    [ITEM_NORMAL_GEM] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Gema Normal"),
#else
        .name = _("Normal Gem"),
#endif
        .itemId = ITEM_NORMAL_GEM,
        .price = 5000,
        .holdEffect = HOLD_EFFECT_GEMS,
        .holdEffectParam = 30,
        .description = sNormalGemDesc,
        .pocket = POCKET_BATTLE_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_NORMAL,
    },

    [ITEM_FAIRY_GEM] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Gema Hada"),
#else
        .name = _("Fairy Gem"),
#endif
        .itemId = ITEM_FAIRY_GEM,
        .price = 5000,
        .holdEffect = HOLD_EFFECT_GEMS,
        .holdEffectParam = 30,
        .description = sFairyGemDesc,
        .pocket = POCKET_BATTLE_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_FAIRY,
    },

    [ITEM_ASSAULT_VEST] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Chaleco Asalto"),
#else
        .name = _("Assault Vest"),
#endif
        .itemId = ITEM_ASSAULT_VEST,
        .price = 10000,
        .holdEffect = HOLD_EFFECT_ASSAULT_VEST,
        .holdEffectParam = 50,
        .description = sAssaultVestDesc,
        .pocket = POCKET_BATTLE_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_PIXIE_PLATE] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Tabla Duende"),
#else
        .name = _("Pixie Plate"),
#endif
        .itemId = ITEM_PIXIE_PLATE,
        .price = 200,
        .holdEffect = HOLD_EFFECT_PLATE,
        .holdEffectParam = 20,
        .description = sPixiePlateDesc,
        .pocket = POCKET_TYPE_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_FAIRY,
    },

    [ITEM_SAFETY_GOGGLES] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Gafa Protectora"),
#else
        .name = _("Safety Goggles"),
#endif
        .itemId = ITEM_SAFETY_GOGGLES,
        .price = 4000,
        .holdEffect = HOLD_EFFECT_SAFETY_GOOGLES,
        .description = sSafetyGogglesDesc,
        .pocket = POCKET_BATTLE_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_GENGARITE] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Gengarita"),
#else
        .name = _("Gengarite"),
#endif
        .itemId = ITEM_GENGARITE,
        .price = 200,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = sGengariteDesc,
        .pocket = POCKET_MEGA_STONES,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_GARDEVOIRITE] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Gardevoirita"),
#else
        .name = _("Gardevoirite"),
#endif
        .itemId = ITEM_GARDEVOIRITE,
        .price = 200,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = sGardevoiriteDesc,
        .pocket = POCKET_MEGA_STONES,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_AMPHAROSITE] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Ampharosita"),
#else
        .name = _("Ampharosite"),
#endif
        .itemId = ITEM_AMPHAROSITE,
        .price = 200,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = sAmpharositeDesc,
        .pocket = POCKET_MEGA_STONES,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_VENUSAURITE] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Venusaurita"),
#else
        .name = _("Venusaurite"),
#endif
        .itemId = ITEM_VENUSAURITE,
        .price = 200,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = sVenusauriteDesc,
        .pocket = POCKET_MEGA_STONES,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_CHARIZARDITE_X] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Charizardita X"),
#else
        .name = _("Charizardite X"),
#endif
        .itemId = ITEM_CHARIZARDITE_X,
        .price = 200,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = sCharizarditeDesc,
        .pocket = POCKET_MEGA_STONES,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_BLASTOISINITE] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Blastoisita"),
#else
        .name = _("Blastoisinite"),
#endif
        .itemId = ITEM_BLASTOISINITE,
        .price = 200,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = sBlastoisiniteDesc,
        .pocket = POCKET_MEGA_STONES,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_MEWTWONITE_X] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Mewtwoita X"),
#else
        .name = _("Mewtwonite X"),
#endif
        .itemId = ITEM_MEWTWONITE_X,
        .price = 200,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = sMewtwoniteDesc,
        .pocket = POCKET_MEGA_STONES,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_MEWTWONITE_Y] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Mewtwoita Y"),
#else
        .name = _("Mewtwonite Y"),
#endif
        .itemId = ITEM_MEWTWONITE_Y,
        .price = 200,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = sMewtwoniteDesc,
        .pocket = POCKET_MEGA_STONES,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_BLAZIKENITE] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Blazikenita"),
#else
        .name = _("Blazikenite"),
#endif
        .itemId = ITEM_BLAZIKENITE,
        .price = 200,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = sBlazikeniteDesc,
        .pocket = POCKET_MEGA_STONES,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_MEDICHAMITE] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Medichamita"),
#else
        .name = _("Medichamite"),
#endif
        .itemId = ITEM_MEDICHAMITE,
        .price = 200,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = sMedichamiteDesc,
        .pocket = POCKET_MEGA_STONES,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_HOUNDOOMINITE] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Houndoomita"),
#else
        .name = _("Houndoominite"),
#endif
        .itemId = ITEM_HOUNDOOMINITE,
        .price = 200,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = sHoundoominiteDesc,
        .pocket = POCKET_MEGA_STONES,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_AGGRONITE] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Aggronita"),
#else
        .name = _("Aggronite"),
#endif
        .itemId = ITEM_AGGRONITE,
        .price = 200,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = sAggroniteDesc,
        .pocket = POCKET_MEGA_STONES,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_BANETTITE] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Banettita"),
#else
        .name = _("Banettite"),
#endif
        .itemId = ITEM_BANETTITE,
        .price = 200,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = sBanettiteDesc,
        .pocket = POCKET_MEGA_STONES,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_TYRANITARITE] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Tyranitarita"),
#else
        .name = _("Tyranitarite"),
#endif
        .itemId = ITEM_TYRANITARITE,
        .price = 200,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = sTyranitariteDesc,
        .pocket = POCKET_MEGA_STONES,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_SCIZORITE] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Scizorita"),
#else
        .name = _("Scizorite"),
#endif
        .itemId = ITEM_SCIZORITE,
        .price = 200,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = sScizoriteDesc,
        .pocket = POCKET_MEGA_STONES,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_PINSIRITE] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Pinsirita"),
#else
        .name = _("Pinsirite"),
#endif
        .itemId = ITEM_PINSIRITE,
        .price = 200,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = sPinsiriteDesc,
        .pocket = POCKET_MEGA_STONES,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_AERODACTYLITE] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Aerodactylita"),
#else
        .name = _("Aerodactylite"),
#endif
        .itemId = ITEM_AERODACTYLITE,
        .price = 200,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = sAerodactyliteDesc,
        .pocket = POCKET_MEGA_STONES,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_LUCARIONITE] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Lucarita"),
#else
        .name = _("Lucarionite"),
#endif
        .itemId = ITEM_LUCARIONITE,
        .price = 200,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = sLucarioniteDesc,
        .pocket = POCKET_MEGA_STONES,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_ABOMASITE] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Abomasnowita"),
#else
        .name = _("Abomasite"),
#endif
        .itemId = ITEM_ABOMASITE,
        .price = 200,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = sAbomasiteDesc,
        .pocket = POCKET_MEGA_STONES,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_KANGASKHANITE] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Kangaskhanita"),
#else
        .name = _("Kangaskhanite"),
#endif
        .itemId = ITEM_KANGASKHANITE,
        .price = 200,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = sKangaskhaniteDesc,
        .pocket = POCKET_MEGA_STONES,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_GYARADOSITE] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Gyaradosita"),
#else
        .name = _("Gyaradosite"),
#endif
        .itemId = ITEM_GYARADOSITE,
        .price = 200,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = sGyaradositeDesc,
        .pocket = POCKET_MEGA_STONES,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_ABSOLITE] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Absolita"),
#else
        .name = _("Absolite"),
#endif
        .itemId = ITEM_ABSOLITE,
        .price = 200,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = sAbsoliteDesc,
        .pocket = POCKET_MEGA_STONES,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_CHARIZARDITE_Y] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Charizardita Y"),
#else
        .name = _("Charizardite Y"),
#endif
        .itemId = ITEM_CHARIZARDITE_Y,
        .price = 200,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = sCharizarditeDesc,
        .pocket = POCKET_MEGA_STONES,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_ALAKAZITE] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Alakazamita"),
#else
        .name = _("Alakazite"),
#endif
        .itemId = ITEM_ALAKAZITE,
        .price = 200,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = sAlakaziteDesc,
        .pocket = POCKET_MEGA_STONES,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_HERACRONITE] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Heracrossita"),
#else
        .name = _("Heracronite"),
#endif
        .itemId = ITEM_HERACRONITE,
        .price = 200,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = sHeracroniteDesc,
        .pocket = POCKET_MEGA_STONES,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_MAWILITE] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Mawilita"),
#else
        .name = _("Mawilite"),
#endif
        .itemId = ITEM_MAWILITE,
        .price = 200,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = sMawiliteDesc,
        .pocket = POCKET_MEGA_STONES,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_MANECTITE] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Manectricita"),
#else
        .name = _("Manectite"),
#endif
        .itemId = ITEM_MANECTITE,
        .price = 200,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = sManectiteDesc,
        .pocket = POCKET_MEGA_STONES,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_GARCHOMPITE] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Garchompita"),
#else
        .name = _("Garchompite"),
#endif
        .itemId = ITEM_GARCHOMPITE,
        .price = 200,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = sGarchompiteDesc,
        .pocket = POCKET_MEGA_STONES,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_LATIASITE] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Latiasita"),
#else
        .name = _("Latiasite"),
#endif
        .itemId = ITEM_LATIASITE,
        .price = 200,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = sLatiasiteDesc,
        .pocket = POCKET_MEGA_STONES,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_LATIOSITE] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Latiosita"),
#else
        .name = _("Latiosite"),
#endif
        .itemId = ITEM_LATIOSITE,
        .price = 200,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = sLatiositeDesc,
        .pocket = POCKET_MEGA_STONES,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_SWAMPERTITE] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Swampertita"),
#else
        .name = _("Swampertite"),
#endif
        .itemId = ITEM_SWAMPERTITE,
        .price = 200,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = sSwampertiteDesc,
        .pocket = POCKET_MEGA_STONES,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_SCEPTILITE] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Sceptileita"),
#else
        .name = _("Sceptilite"),
#endif
        .itemId = ITEM_SCEPTILITE,
        .price = 200,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = sSceptiliteDesc,
        .pocket = POCKET_MEGA_STONES,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_SABLENITE] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Sableynita"),
#else
        .name = _("Sablenite"),
#endif
        .itemId = ITEM_SABLENITE,
        .price = 200,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = sSableniteDesc,
        .pocket = POCKET_MEGA_STONES,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_ALTARIANITE] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Altarianita"),
#else
        .name = _("Altarianite"),
#endif
        .itemId = ITEM_ALTARIANITE,
        .price = 200,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = sAltarianiteDesc,
        .pocket = POCKET_MEGA_STONES,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_GALLADITE] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Galladita"),
#else
        .name = _("Galladite"),
#endif
        .itemId = ITEM_GALLADITE,
        .price = 200,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = sGalladiteDesc,
        .pocket = POCKET_MEGA_STONES,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_AUDINITE] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Audinita"),
#else
        .name = _("Audinite"),
#endif
        .itemId = ITEM_AUDINITE,
        .price = 200,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = sAudiniteDesc,
        .pocket = POCKET_MEGA_STONES,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_METAGROSSITE] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Metagrossita"),
#else
        .name = _("Metagrossite"),
#endif
        .itemId = ITEM_METAGROSSITE,
        .price = 200,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = sMetagrossiteDesc,
        .pocket = POCKET_MEGA_STONES,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_SHARPEDONITE] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Sharpedonita"),
#else
        .name = _("Sharpedonite"),
#endif
        .itemId = ITEM_SHARPEDONITE,
        .price = 200,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = sSharpedoniteDesc,
        .pocket = POCKET_MEGA_STONES,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_SLOWBRONITE] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Slowbronita"),
#else
        .name = _("Slowbronite"),
#endif
        .itemId = ITEM_SLOWBRONITE,
        .price = 200,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = sSlowbroniteDesc,
        .pocket = POCKET_MEGA_STONES,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_STEELIXITE] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Steelixita"),
#else
        .name = _("Steelixite"),
#endif
        .itemId = ITEM_STEELIXITE,
        .price = 200,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = sSteelixiteDesc,
        .pocket = POCKET_MEGA_STONES,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_PIDGEOTITE] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Pidgeotita"),
#else
        .name = _("Pidgeotite"),
#endif
        .itemId = ITEM_PIDGEOTITE,
        .price = 200,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = sPidgeotiteDesc,
        .pocket = POCKET_MEGA_STONES,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_GLALITITE] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Glalita"),
#else
        .name = _("Glalitite"),
#endif
        .itemId = ITEM_GLALITITE,
        .price = 200,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = sGlalititeDesc,
        .pocket = POCKET_MEGA_STONES,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_DIANCITE] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Diancita"),
#else
        .name = _("Diancite"),
#endif
        .itemId = ITEM_DIANCITE,
        .price = 200,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = sDianciteDesc,
        .pocket = POCKET_MEGA_STONES,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_CAMERUPTITE] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Cameruptita"),
#else
        .name = _("Cameruptite"),
#endif
        .itemId = ITEM_CAMERUPTITE,
        .price = 200,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = sCameruptiteDesc,
        .pocket = POCKET_MEGA_STONES,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_LOPUNNITE] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Lopunnita"),
#else
        .name = _("Lopunnite"),
#endif
        .itemId = ITEM_LOPUNNITE,
        .price = 200,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = sLopunniteDesc,
        .pocket = POCKET_MEGA_STONES,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_SALAMENCITE] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Salamencita"),
#else
        .name = _("Salamencite"),
#endif
        .itemId = ITEM_SALAMENCITE,
        .price = 200,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = sSalamenciteDesc,
        .pocket = POCKET_MEGA_STONES,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_BEEDRILLITE] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Beedrillita"),
#else
        .name = _("Beedrillite"),
#endif
        .itemId = ITEM_BEEDRILLITE,
        .price = 200,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = sBeedrilliteDesc,
        .pocket = POCKET_MEGA_STONES,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_MEGA_BRACELET] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Megapulsera"),
#else
        .name = _("Mega Bracelet"),
#endif
        .itemId = ITEM_MEGA_BRACELET,
        .price = 200,
        .description = sMegaBraceletDesc,
        .pocket = POCKET_KEY_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_PROTECTIVE_PADS] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Paracontacto"),
#else
        .name = _("Protective Pads"), // Shortened name from Protective Pads
#endif
        .itemId = ITEM_PROTECTIVE_PADS,
        .price = 4000,
        .holdEffect = HOLD_EFFECT_PROTECTIVE_PADS,
        .description = sProtectPadsDesc,
        .pocket = POCKET_BATTLE_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_TERRAIN_EXTENDER] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Cubresuelos"),
#else
        .name = _("Terrain Extender"),
#endif
        .itemId = ITEM_TERRAIN_EXTENDER,
        .price = 4000,
        .holdEffect = HOLD_EFFECT_TERRAIN_EXTENDER,
        .description = sTerrainExtenderDesc,
        .pocket = POCKET_BATTLE_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_ELECTRIC_SEED] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Semilla Electro"),
#else
        .name = _("Electric Seed"),
#endif
        .itemId = ITEM_ELECTRIC_SEED,
        .price = 4000,
        .holdEffect = HOLD_EFFECT_SEEDS,
        .description = sElectricSeedDesc,
        .pocket = POCKET_BATTLE_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_GRASSY_SEED] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Semilla Hierba"),
#else
        .name = _("Grassy Seed"),
#endif
        .itemId = ITEM_GRASSY_SEED,
        .price = 4000,
        .holdEffect = HOLD_EFFECT_SEEDS,
        .description = sGrassySeedDesc,
        .pocket = POCKET_BATTLE_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_MISTY_SEED] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Semilla Bruma"),
#else
        .name = _("Misty Seed"),
#endif
        .itemId = ITEM_MISTY_SEED,
        .price = 4000,
        .holdEffect = HOLD_EFFECT_SEEDS,
        .description = sMistySeedDesc,
        .pocket = POCKET_BATTLE_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_PSYCHIC_SEED] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Semilla Psique"),
#else
        .name = _("Psychic Seed"),
#endif
        .itemId = ITEM_PSYCHIC_SEED,
        .price = 4000,
        .holdEffect = HOLD_EFFECT_SEEDS,
        .description = sPsychicSeedDesc,
        .pocket = POCKET_BATTLE_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_ADRENALINE_ORB] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Nerviosfera"),
#else
        .name = _("Adrenaline Orb"),
#endif
        .itemId = ITEM_ADRENALINE_ORB,
        .price = 300,
        .holdEffect = HOLD_EFFECT_ADRENALINE_ORB,
        .description = sAdrenalineOrbDesc,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_HONEY] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Miel"),
#else
        .name = _("Honey"),
#endif
        .itemId = ITEM_HONEY,
        .price = 100,
        .description = sHoneyDesc,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_HEALTH_WING] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Pluma Vigor"),
#else
        .name = _("Health Feather"),
#endif
        .itemId = ITEM_HEALTH_WING,
        .price = 300,
        .holdEffect = 0,
        .holdEffectParam = 4,
        .description = sHealthWingDesc,
        .pocket = POCKET_POWER_UP,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_IVWings,
        .secondaryId = STAT_HP,
    },

    [ITEM_MUSCLE_WING] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Pluma Músculo"),
#else
        .name = _("Muscle Feather"),
#endif
        .itemId = ITEM_MUSCLE_WING,
        .price = 300,
        .holdEffect = 0,
        .holdEffectParam = 4,
        .description = sMuscleWingDesc,
        .pocket = POCKET_POWER_UP,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_IVWings,
        .secondaryId = STAT_ATK,
    },

    [ITEM_RESIST_WING] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Pluma Músculo"),
#else
        .name = _("Resist Feather"),
#endif
        .itemId = ITEM_RESIST_WING,
        .price = 300,
        .holdEffect = 0,
        .holdEffectParam = 4,
        .description = sResistWingDesc,
        .pocket = POCKET_POWER_UP,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_IVWings,
        .secondaryId = STAT_DEF,
    },

    [ITEM_GENIUS_WING] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Pluma Intelecto"),
#else
        .name = _("Genius Feather"),
#endif
        .itemId = ITEM_GENIUS_WING,
        .price = 300,
        .holdEffect = 0,
        .holdEffectParam = 4,
        .description = sGeniusWingDesc,
        .pocket = POCKET_POWER_UP,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_IVWings,
        .secondaryId = STAT_SPATK,
    },

    [ITEM_CLEVER_WING] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Pluma Mente"),
#else
        .name = _("Clever Feather"),
#endif
        .itemId = ITEM_CLEVER_WING,
        .price = 300,
        .holdEffect = 0,
        .holdEffectParam = 4,
        .description = sCleverWingDesc,
        .pocket = POCKET_POWER_UP,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_IVWings,
        .secondaryId = STAT_SPDEF,
    },

    [ITEM_SWIFT_WING] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Pluma Ímpetu"),
#else
        .name = _("Swift Feather"),
#endif
        .itemId = ITEM_SWIFT_WING,
        .price = 300,
        .holdEffect = 0,
        .holdEffectParam = 4,
        .description = sSwiftWingDesc,
        .pocket = POCKET_POWER_UP,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_IVWings,
        .secondaryId = STAT_SPEED,
    },

    [ITEM_PRETTY_WING] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Pluma Bella"),
#else
        .name = _("Pretty Feather"),
#endif
        .itemId = ITEM_PRETTY_WING,
        .price = 1000,
        .description = sPrettyWingDesc,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_SHINY_CHARM] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Amuleto Iris"),
#else
        .name = _("Shiny Charm"),
#endif
        .itemId = ITEM_SHINY_CHARM,
        .price = 0,
        .description = sShinyCharmDesc,
        .pocket = POCKET_KEY_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },
    
    [ITEM_OVAL_CHARM] =
    {
        .name = _("Oval Charm"),
        .itemId = ITEM_OVAL_CHARM,
        .price = 0,
        .importance = 1,
        .description = sOvalCharmDesc,
        .pocket = POCKET_KEY_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },
    
    //Mod items
    [ITEM_LINK_CABLE] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Cable Link"),
#else
        .name = _("Link Cable"),
#endif
        .itemId = ITEM_LINK_CABLE,
        .price = 0,
        .description = sLinkCableDesc,
        .pocket = POCKET_POWER_UP,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },
    
    [ITEM_STRANGE_SOUVENIR] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Estatuilla Rara"),
#else
        .name = _("S.Souvenir"),
#endif
        .itemId = ITEM_STRANGE_SOUVENIR,
        .price = 3500,
        .description = sStrangeSouvenirDesc,
        .pocket = POCKET_POWER_UP,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_EON_FLUTE] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Flauta Eón"),
#else
        .name = _("Eon Flute"),
#endif
        .itemId = ITEM_EON_FLUTE,
        .price = 0,
        .description = sEonFluteDesc,
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = 2,
        .fieldUseFunc = ItemUseOutOfBattle_EonFlute,
        .secondaryId = 0,
    },

    [ITEM_LURE] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Colonia"),
#else
        .name = _("Lure"),
#endif
        .itemId = ITEM_LURE,
        .price = 350,
        .holdEffectParam = 100,
        .description = sLureDesc,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_Lure,
        .secondaryId = 0,
    },

    [ITEM_SUPER_LURE] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Supercolonia"),
#else
        .name = _("Super Lure"),
#endif
        .itemId = ITEM_SUPER_LURE,
        .price = 500,
        .holdEffectParam = 200,
        .description = sSuperLureDesc,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_Lure,
        .secondaryId = 0,
    },

    [ITEM_MAX_LURE] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Colonia Máxima"),
#else
        .name = _("Max Lure"),
#endif
        .itemId = ITEM_MAX_LURE,
        .price = 700,
        .holdEffectParam = 250,
        .description = sMaxLureDesc,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_Lure,
        .secondaryId = 0,
    },

    [ITEM_SAFARI_PASS] =
    {
#if GAME_LANGUAGE == LANGUAGE_SPANISH
        .name = _("Pase Safari"),
#else
        .name = _("Safari Pass"),
#endif
        .itemId = ITEM_SAFARI_PASS,
        .price = 0,
        .description = sSafariPassDesc,
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },
    
//mints
    [ITEM_ADAMANT_MINT] = 
    {
        .name = _("Adamant Mint"),
        .itemId = ITEM_ADAMANT_MINT,
        .price = 8000,
        .description = sAdamantMintDesc,
        .pocket = POCKET_POWER_UP,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_Mints,
        .secondaryId = NATURE_ADAMANT,
    },
    
    [ITEM_BOLD_MINT] = 
    {
        .name = _("Bold Mint"),
        .itemId = ITEM_BOLD_MINT,
        .price = 8000,
        .description = sBoldMintDesc,
        .pocket = POCKET_POWER_UP,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_Mints,
        .secondaryId = NATURE_BOLD,
    },
    
    [ITEM_BRAVE_MINT] = 
    {
        .name = _("Brave Mint"),
        .itemId = ITEM_BRAVE_MINT,
        .price = 8000,
        .description = sBraveMintDesc,
        .pocket = POCKET_POWER_UP,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_Mints,
        .secondaryId = NATURE_BRAVE,
    },
    
    [ITEM_CALM_MINT] = 
    {
        .name = _("Calm Mint"),
        .itemId = ITEM_CALM_MINT,
        .price = 8000,
        .description = sCalmMintDesc,
        .pocket = POCKET_POWER_UP,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_Mints,
        .secondaryId = NATURE_CALM,
    },
    
    [ITEM_CAREFUL_MINT] = 
    {
        .name = _("Careful Mint"),
        .itemId = ITEM_CAREFUL_MINT,
        .price = 8000,
        .description = sCarefulMintDesc,
        .pocket = POCKET_POWER_UP,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_Mints,
        .secondaryId = NATURE_CAREFUL,
    },
    
    [ITEM_GENTLE_MINT] = 
    {
        .name = _("Gentle Mint"),
        .itemId = ITEM_GENTLE_MINT,
        .price = 8000,
        .description = sGentleMintDesc,
        .pocket = POCKET_POWER_UP,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_Mints,
        .secondaryId = NATURE_GENTLE,
    },
    
    [ITEM_HASTY_MINT] = 
    {
        .name = _("Hasty Mint"),
        .itemId = ITEM_HASTY_MINT,
        .price = 8000,
        .description = sHastyMintDesc,
        .pocket = POCKET_POWER_UP,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_Mints,
        .secondaryId = NATURE_HASTY,
    },
    
    [ITEM_IMPISH_MINT] = 
    {
        .name = _("Impish Mint"),
        .itemId = ITEM_IMPISH_MINT,
        .price = 8000,
        .description = sImpishMintDesc,
        .pocket = POCKET_POWER_UP,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_Mints,
        .secondaryId = NATURE_IMPISH,
    },
    
    [ITEM_JOLLY_MINT] = 
    {
        .name = _("Jolly Mint"),
        .itemId = ITEM_JOLLY_MINT,
        .price = 8000,
        .description = sJollyMintDesc,
        .pocket = POCKET_POWER_UP,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_Mints,
        .secondaryId = NATURE_JOLLY,
    },
    
    [ITEM_LAX_MINT] = 
    {
        .name = _("Lax Mint"),
        .itemId = ITEM_LAX_MINT,
        .price = 8000,
        .description = sLaxMintDesc,
        .pocket = POCKET_POWER_UP,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_Mints,
        .secondaryId = NATURE_LAX,
    },
    
    [ITEM_LONELY_MINT] = 
    {
        .name = _("Lonely Mint"),
        .itemId = ITEM_LONELY_MINT,
        .price = 8000,
        .description = sLonelyMintDesc,
        .pocket = POCKET_POWER_UP,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_Mints,
        .secondaryId = NATURE_LONELY,
    },
    
    [ITEM_MILD_MINT] = 
    {
        .name = _("Mild Mint"),
        .itemId = ITEM_MILD_MINT,
        .price = 8000,
        .description = sMildMintDesc,
        .pocket = POCKET_POWER_UP,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_Mints,
        .secondaryId = NATURE_MILD,
    },
    
    [ITEM_MODEST_MINT] = 
    {
        .name = _("Modest Mint"),
        .itemId = ITEM_MODEST_MINT,
        .price = 8000,
        .description = sModestMintDesc,
        .pocket = POCKET_POWER_UP,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_Mints,
        .secondaryId = NATURE_MODEST,
    },
    
    [ITEM_NAIVE_MINT] = 
    {
        .name = _("Naive Mint"),
        .itemId = ITEM_NAIVE_MINT,
        .price = 8000,
        .description = sNaiveMintDesc,
        .pocket = POCKET_POWER_UP,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_Mints,
        .secondaryId = NATURE_NAIVE,
    },
    
    [ITEM_NAUGHTY_MINT] = 
    {
        .name = _("Naughty Mint"),
        .itemId = ITEM_NAUGHTY_MINT,
        .price = 8000,
        .description = sNaughtyMintDesc,
        .pocket = POCKET_POWER_UP,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_Mints,
        .secondaryId = NATURE_NAUGHTY,
    },
    
    [ITEM_QUIET_MINT] = 
    {
        .name = _("Quiet Mint"),
        .itemId = ITEM_QUIET_MINT,
        .price = 8000,
        .description = sQuietMintDesc,
        .pocket = POCKET_POWER_UP,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_Mints,
        .secondaryId = NATURE_QUIET,
    },
    
    [ITEM_RASH_MINT] = 
    {
        .name = _("Rash Mint"),
        .itemId = ITEM_RASH_MINT,
        .price = 8000,
        .description = sRashMintDesc,
        .pocket = POCKET_POWER_UP,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_Mints,
        .secondaryId = NATURE_RASH,
    },
    
    [ITEM_RELAXED_MINT] = 
    {
        .name = _("Relaxed Mint"),
        .itemId = ITEM_RELAXED_MINT,
        .price = 8000,
        .description = sRelaxedMintDesc,
        .pocket = POCKET_POWER_UP,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_Mints,
        .secondaryId = NATURE_RELAXED,
    },
    
    [ITEM_SASSY_MINT] = 
    {
        .name = _("Sassy Mint"),
        .itemId = ITEM_SASSY_MINT,
        .price = 8000,
        .description = sSassyMintDesc,
        .pocket = POCKET_POWER_UP,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_Mints,
        .secondaryId = NATURE_SASSY,
    },
    
    [ITEM_SERIOUS_MINT] = 
    {
        .name = _("Serious Mint"),
        .itemId = ITEM_SERIOUS_MINT,
        .price = 8000,
        .description = sSeriousMintDesc,
        .pocket = POCKET_POWER_UP,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_Mints,
        .secondaryId = NATURE_SERIOUS,
    },
    
    [ITEM_TIMID_MINT] = 
    {
        .name = _("Timid Mint"),
        .itemId = ITEM_TIMID_MINT,
        .price = 8000,
        .description = sTimidMintDesc,
        .pocket = POCKET_POWER_UP,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_Mints,
        .secondaryId = NATURE_TIMID,
    },
    
    //Seals
    [ITEM_MASTER_BALL_SEAL] = 
    {
        .name = _("Master Ball Seal"),
        .itemId = ITEM_MASTER_BALL_SEAL,
        .price = 50000,
        .description = sSealDesc,
        .pocket = POCKET_POWER_UP,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_Seal,
        .secondaryId = ITEM_MASTER_BALL,
    },
    
    [ITEM_ULTRA_BALL_SEAL] = 
    {
        .name = _("Ultra Ball S."),
        .itemId = ITEM_ULTRA_BALL_SEAL,
        .price = 7500,
        .description = sSealDesc,
        .pocket = POCKET_POWER_UP,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_Seal,
        .secondaryId = ITEM_ULTRA_BALL,
    },
    
    [ITEM_GREAT_BALL_SEAL] = 
    {
        .name = _("Great Ball Seal"),
        .itemId = ITEM_GREAT_BALL_SEAL,
        .price = 5000,
        .description = sSealDesc,
        .pocket = POCKET_POWER_UP,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_Seal,
        .secondaryId = ITEM_GREAT_BALL,
    },
    
    [ITEM_POKE_BALL_SEAL] = 
    {
        .name = _("Poke Ball Seal"),
        .itemId = ITEM_POKE_BALL_SEAL,
        .price = 1000,
        .description = sSealDesc,
        .pocket = POCKET_POWER_UP,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_Seal,
        .secondaryId = ITEM_POKE_BALL,
    },
    
    [ITEM_SAFARI_BALL_SEAL] = 
    {
        .name = _("Safari Ball S."),
        .itemId = ITEM_SAFARI_BALL_SEAL,
        .price = 12500,
        .description = sSealDesc,
        .pocket = POCKET_POWER_UP,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_Seal,
        .secondaryId = ITEM_SAFARI_BALL,
    },
    
    [ITEM_NET_BALL_SEAL] = 
    {
        .name = _("Net Ball Seal"),
        .itemId = ITEM_NET_BALL_SEAL,
        .price = 10000,
        .description = sSealDesc,
        .pocket = POCKET_POWER_UP,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_Seal,
        .secondaryId = ITEM_NET_BALL,
    },
    
    [ITEM_DIVE_BALL_SEAL] = 
    {
        .name = _("Dive Ball Seal"),
        .itemId = ITEM_DIVE_BALL_SEAL,
        .price = 10000,
        .description = sSealDesc,
        .pocket = POCKET_POWER_UP,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_Seal,
        .secondaryId = ITEM_DIVE_BALL,
    },
    
    [ITEM_NEST_BALL_SEAL] = 
    {
        .name = _("Nest Ball Seal"),
        .itemId = ITEM_NEST_BALL_SEAL,
        .price = 10000,
        .description = sSealDesc,
        .pocket = POCKET_POWER_UP,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_Seal,
        .secondaryId = ITEM_NEST_BALL,
    },
    
    [ITEM_REPEAT_BALL_SEAL] = 
    {
        .name = _("Repeat Ball S."),
        .itemId = ITEM_REPEAT_BALL_SEAL,
        .price = 10000,
        .description = sSealDesc,
        .pocket = POCKET_POWER_UP,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_Seal,
        .secondaryId = ITEM_REPEAT_BALL,
    },
    
    [ITEM_TIMER_BALL_SEAL] = 
    {
        .name = _("Timer Ball S."),
        .itemId = ITEM_TIMER_BALL_SEAL,
        .price = 10000,
        .description = sSealDesc,
        .pocket = POCKET_POWER_UP,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_Seal,
        .secondaryId = ITEM_TIMER_BALL,
    },
    
    [ITEM_LUXURY_BALL_SEAL] = 
    {
        .name = _("Luxury Ball S."),
        .itemId = ITEM_LUXURY_BALL_SEAL,
        .price = 10000,
        .description = sSealDesc,
        .pocket = POCKET_POWER_UP,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_Seal,
        .secondaryId = ITEM_LUXURY_BALL,
    },
    
    [ITEM_PREMIER_BALL_SEAL] = 
    {
        .name = _("Premier Ball S."),
        .itemId = ITEM_PREMIER_BALL_SEAL,
        .price = 10000,
        .description = sSealDesc,
        .pocket = POCKET_POWER_UP,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_Seal,
        .secondaryId = ITEM_PREMIER_BALL,
    },
    
    [ITEM_LEVEL_BALL_SEAL] = 
    {
        .name = _("Level Ball S."),
        .itemId = ITEM_LEVEL_BALL_SEAL,
        .price = 10000,
        .description = sSealDesc,
        .pocket = POCKET_POWER_UP,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_Seal,
        .secondaryId = ITEM_LEVEL_BALL,
    },
    
    [ITEM_LURE_BALL_SEAL] = 
    {
        .name = _("Lure Ball Seal"),
        .itemId = ITEM_LURE_BALL_SEAL,
        .price = 10000,
        .description = sSealDesc,
        .pocket = POCKET_POWER_UP,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_Seal,
        .secondaryId = ITEM_LURE_BALL,
    },
    
    [ITEM_MOON_BALL_SEAL] = 
    {
        .name = _("Moon Ball Seal"),
        .itemId = ITEM_MOON_BALL_SEAL,
        .price = 10000,
        .description = sSealDesc,
        .pocket = POCKET_POWER_UP,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_Seal,
        .secondaryId = ITEM_MOON_BALL,
    },
    
    [ITEM_FRIEND_BALL_SEAL] = 
    {
        .name = _("Friend Ball S."),
        .itemId = ITEM_FRIEND_BALL_SEAL,
        .price = 10000,
        .description = sSealDesc,
        .pocket = POCKET_POWER_UP,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_Seal,
        .secondaryId = ITEM_FRIEND_BALL,
    },
    
    [ITEM_LOVE_BALL_SEAL] = 
    {
        .name = _("Love Ball Seal"),
        .itemId = ITEM_LOVE_BALL_SEAL,
        .price = 10000,
        .description = sSealDesc,
        .pocket = POCKET_POWER_UP,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_Seal,
        .secondaryId = ITEM_LOVE_BALL,
    },
    
    [ITEM_HEAVY_BALL_SEAL] = 
    {
        .name = _("Heavy Ball S."),
        .itemId = ITEM_HEAVY_BALL_SEAL,
        .price = 10000,
        .description = sSealDesc,
        .pocket = POCKET_POWER_UP,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_Seal,
        .secondaryId = ITEM_HEAVY_BALL,
    },
    
    [ITEM_FAST_BALL_SEAL] = 
    {
        .name = _("Fast Ball Seal"),
        .itemId = ITEM_FAST_BALL_SEAL,
        .price = 10000,
        .description = sSealDesc,
        .pocket = POCKET_POWER_UP,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_Seal,
        .secondaryId = ITEM_FAST_BALL,
    },
    
    [ITEM_SPORT_BALL_SEAL] = 
    {
        .name = _("Sport Ball S."),
        .itemId = ITEM_SPORT_BALL_SEAL,
        .price = 10000,
        .description = sSealDesc,
        .pocket = POCKET_POWER_UP,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_Seal,
        .secondaryId = ITEM_SPORT_BALL,
    },
    
    [ITEM_DUSK_BALL_SEAL] = 
    {
        .name = _("Dusk Ball S."),
        .itemId = ITEM_DUSK_BALL_SEAL,
        .price = 10000,
        .description = sSealDesc,
        .pocket = POCKET_POWER_UP,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_Seal,
        .secondaryId = ITEM_DUSK_BALL,
    },
    
    [ITEM_QUICK_BALL_SEAL] = 
    {
        .name = _("Quick Ball S."),
        .itemId = ITEM_QUICK_BALL_SEAL,
        .price = 10000,
        .description = sSealDesc,
        .pocket = POCKET_POWER_UP,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_Seal,
        .secondaryId = ITEM_QUICK_BALL,
    },
    
    [ITEM_HEAL_BALL_SEAL] = 
    {
        .name = _("Heal Ball S."),
        .itemId = ITEM_HEAL_BALL_SEAL,
        .price = 10000,
        .description = sSealDesc,
        .pocket = POCKET_POWER_UP,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_Seal,
        .secondaryId = ITEM_HEAL_BALL,
    },
    
    [ITEM_CHERISH_BALL_SEAL] = 
    {
        .name = _("Cherish Ball S."),
        .itemId = ITEM_CHERISH_BALL_SEAL,
        .price = 10000,
        .description = sSealDesc,
        .pocket = POCKET_POWER_UP,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_Seal,
        .secondaryId = ITEM_CHERISH_BALL,
    },
    
    [ITEM_PARK_BALL_SEAL] = 
    {
        .name = _("Park Ball S."),
        .itemId = ITEM_PARK_BALL_SEAL,
        .price = 10000,
        .description = sSealDesc,
        .pocket = POCKET_POWER_UP,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_Seal,
        .secondaryId = ITEM_PARK_BALL,
    },
    
    [ITEM_DREAM_BALL_SEAL] = 
    {
        .name = _("Dream Ball S."),
        .itemId = ITEM_DREAM_BALL_SEAL,
        .price = 10000,
        .description = sSealDesc,
        .pocket = POCKET_POWER_UP,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_Seal,
        .secondaryId = ITEM_DREAM_BALL,
    },
    
    [ITEM_BEAST_BALL_SEAL] = 
    {
        .name = _("Beast Ball S."),
        .itemId = ITEM_BEAST_BALL_SEAL,
        .price = 10000,
        .description = sSealDesc,
        .pocket = POCKET_POWER_UP,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_Seal,
        .secondaryId = ITEM_BEAST_BALL,
    },
    
    [ITEM_EXIOLITE] = 
    {
        .name = _("Exiolite"),
        .itemId = ITEM_EXIOLITE,
        .price = 9000,
        .description = sExioliteDesc,
        .pocket = POCKET_POWER_UP,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_Exiolite,
        .secondaryId = 0,
    },
    
    [ITEM_IRON_PILL] = 
    {
        .name = _("Iron Pill"),
        .itemId = ITEM_IRON_PILL,
        .price = 9000,
        .description = sIronPillDesc,
        .pocket = POCKET_POWER_UP,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_IronPill,
        .secondaryId = 0,
    },

    [ITEM_EXP_CHARM] =
    {
        .name = _("Exp Charm"),
        .itemId = ITEM_EXP_CHARM,
        .price = 0,
        .description = sExpCharmDesc,
        .pocket = POCKET_KEY_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_CATCHING_CHARM] =
    {
        .name = _("Catching Charm"),
        .itemId = ITEM_CATCHING_CHARM,
        .price = 0,
        .description = sCatchingCharmDesc,
        .pocket = POCKET_KEY_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },
};
