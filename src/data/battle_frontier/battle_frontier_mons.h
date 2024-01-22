const struct FacilityMon gBattleFrontierMons[NUM_FRONTIER_MONS] =
{
    [FRONTIER_MON_SUNKERN] = {
        .species = SPECIES_GUMSHOOS,//
        .moves = {MOVE_U_TURN, MOVE_EARTHQUAKE, MOVE_RETURN, MOVE_PURSUIT},
        .itemTableId = BATTLE_FRONTIER_ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_JOLLY,
		.abilitynum = 2
    },
    [FRONTIER_MON_AZURILL] = {
        .species = SPECIES_MIENSHAO,//
        .moves = {MOVE_U_TURN, MOVE_KNOCK_OFF, MOVE_HI_JUMP_KICK, MOVE_POISON_FANG},
        .itemTableId = BATTLE_FRONTIER_ITEM_CHOICE_SCARF,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_ADAMANT,
		.abilitynum = ABILITY_2
    },
    [FRONTIER_MON_CATERPIE] = {
        .species = SPECIES_GOLISOPOD,//
        .moves = {MOVE_FIRST_IMPRESSION, MOVE_LIQUIDATION, MOVE_AQUA_JET, MOVE_LEECH_LIFE},
        .itemTableId = BATTLE_FRONTIER_ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_JOLLY,
		.abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_WEEDLE] = {
        .species = SPECIES_VIVILLON,//
        .moves = {MOVE_HURRICANE, MOVE_GIGA_DRAIN, MOVE_BUG_BUZZ, MOVE_QUIVER_DANCE},
        .itemTableId = BATTLE_FRONTIER_ITEM_FOCUS_SASH,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
		.abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_WURMPLE] = {
        .species = SPECIES_GOODRA,//
        .moves = {MOVE_FLAMETHROWER, MOVE_THUNDERBOLT, MOVE_SLUDGE_WAVE, MOVE_DRAGON_PULSE},
        .itemTableId = BATTLE_FRONTIER_ITEM_ASSAULT_VEST,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SP_DEFENSE,
        .nature = NATURE_CALM,
		.abilitynum = ABILITY_2
    },
    [FRONTIER_MON_RALTS] = {
        .species = SPECIES_FLORGES,//
        .moves = {MOVE_AROMATHERAPY, MOVE_MOONBLAST, MOVE_WISH, MOVE_CALM_MIND},
        .itemTableId = BATTLE_FRONTIER_ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
		.abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_MAGIKARP] = {
        .species = SPECIES_BRUXISH,//
        .moves = {MOVE_SWORDS_DANCE, MOVE_CRUNCH, MOVE_PSYCHIC_FANGS, MOVE_AQUA_JET},
        .itemTableId = BATTLE_FRONTIER_ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_ADAMANT,
		.abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_FEEBAS] = {
        .species = SPECIES_TOXAPEX,//
        .moves = {MOVE_SCALD, MOVE_RECOVER, MOVE_TOXIC_SPIKES, MOVE_HAZE},
        .itemTableId = BATTLE_FRONTIER_ITEM_BLACK_SLUDGE,
        .evSpread = F_EV_SPREAD_DEFENSE |F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_BOLD,
		.abilitynum = 2
    },
    [FRONTIER_MON_METAPOD] = {
        .species = SPECIES_ACCELGOR,//
        .moves = {MOVE_ENCORE, MOVE_SPIKES, MOVE_SLUDGE_BOMB, MOVE_WATER_SHURIKEN},
        .itemTableId = BATTLE_FRONTIER_ITEM_FOCUS_SASH,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
		.abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_KAKUNA] = {
        .species = SPECIES_COMFEY,//
        .moves = {MOVE_REST, MOVE_CALM_MIND, MOVE_DRAINING_KISS, MOVE_LEECH_SEED},
        .itemTableId = BATTLE_FRONTIER_ITEM_CHESTO_BERRY,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
		.abilitynum = ABILITY_1
    },
    [FRONTIER_MON_PICHU] = {
        .species = SPECIES_LUXRAY,//
        .moves = {MOVE_ICE_FANG, MOVE_WILD_CHARGE, MOVE_FIRE_FANG, MOVE_SUPERPOWER},
        .itemTableId = BATTLE_FRONTIER_ITEM_FLAME_ORB,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_JOLLY,
		.abilitynum = 2
    },
    [FRONTIER_MON_SILCOON] = {
        .species = SPECIES_LILLIGANT,//
        .moves = {MOVE_QUIVER_DANCE, MOVE_GIGA_DRAIN, MOVE_SLEEP_POWDER, MOVE_EARTH_POWER},
        .itemTableId = BATTLE_FRONTIER_ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
		.abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_CASCOON] = {
        .species = SPECIES_YANMEGA,//
        .moves = {MOVE_AIR_SLASH, MOVE_PROTECT, MOVE_ANCIENT_POWER, MOVE_GIGA_DRAIN},
        .itemTableId = BATTLE_FRONTIER_ITEM_FOCUS_SASH,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST,
		.abilitynum = ABILITY_1
    },
    [FRONTIER_MON_IGGLYBUFF] = {
        .species = SPECIES_TOGEDEMARU,//
        .moves = {MOVE_ZING_ZAP, MOVE_U_TURN, MOVE_NUZZLE, MOVE_FAKE_OUT},
        .itemTableId = BATTLE_FRONTIER_ITEM_ASSAULT_VEST,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_JOLLY,
		.abilitynum = ABILITY_1
    },
    [FRONTIER_MON_WOOPER] = {
        .species = SPECIES_JELLICENT,//
        .moves = {MOVE_TAUNT, MOVE_SCALD, MOVE_RECOVER, MOVE_SHADOW_BALL},
        .itemTableId = BATTLE_FRONTIER_ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
		.abilitynum = ABILITY_1
    },
    [FRONTIER_MON_TYROGUE] = {
        .species = SPECIES_SCRAFTY,//
        .moves = {MOVE_CRUNCH, MOVE_REST, MOVE_HI_JUMP_KICK, MOVE_DRAGON_DANCE},
        .itemTableId = BATTLE_FRONTIER_ITEM_LUM_BERRY,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_ADAMANT,
		.abilitynum = ABILITY_2
    },
    [FRONTIER_MON_SENTRET] = {
        .species = SPECIES_BEWEAR,//
        .moves = {MOVE_HAMMER_ARM, MOVE_ICE_PUNCH, MOVE_RETURN, MOVE_PAYBACK},
        .itemTableId = BATTLE_FRONTIER_ITEM_ASSAULT_VEST,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
		.abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_CLEFFA] = {
        .species = SPECIES_TSAREENA,
        .moves = {MOVE_U_TURN, MOVE_RAPID_SPIN, MOVE_TROP_KICK, MOVE_PLAY_ROUGH},
        .itemTableId = BATTLE_FRONTIER_ITEM_ASSAULT_VEST,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_JOLLY,
		.abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_SEEDOT] = {
        .species = SPECIES_STOUTLAND,
        .moves = {MOVE_CRUNCH, MOVE_SUPERPOWER, MOVE_RETURN, MOVE_ICE_FANG},
        .itemTableId = BATTLE_FRONTIER_ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_JOLLY,
		.abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_LOTAD] = {
        .species = SPECIES_LUDICOLO,//TO REMOVE
        .moves = {MOVE_HYDRO_PUMP, MOVE_ICE_BEAM, MOVE_GIGA_DRAIN, MOVE_SCALD},
        .itemTableId = BATTLE_FRONTIER_ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
		.abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_POOCHYENA] = {
        .species = SPECIES_LYCANROC,
        .moves = {MOVE_STONE_EDGE, MOVE_STEALTH_ROCK, MOVE_ACCELEROCK, MOVE_FIRE_FANG},
        .itemTableId = BATTLE_FRONTIER_ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_JOLLY,
		.abilitynum = ABILITY_2
    },
    [FRONTIER_MON_SHEDINJA] = {
        .species = SPECIES_SHEDINJA,//
        .moves = {MOVE_SHADOW_SNEAK, MOVE_LEECH_LIFE, MOVE_SUCKER_PUNCH, MOVE_ENDURE},
        .itemTableId = BATTLE_FRONTIER_ITEM_FOCUS_SASH,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
		.abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_MAKUHITA] = {
        .species = SPECIES_PANGORO,//
        .moves = {MOVE_DRAIN_PUNCH, MOVE_ICE_PUNCH, MOVE_GUNK_SHOT, MOVE_BULLET_PUNCH},
        .itemTableId = BATTLE_FRONTIER_ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_JOLLY,
		.abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_WHISMUR] = {
        .species = SPECIES_SCYTHER,
        .moves = {MOVE_WING_ATTACK, MOVE_BUG_BITE, MOVE_ROOST, MOVE_SWORDS_DANCE},
        .itemTableId = BATTLE_FRONTIER_ITEM_EVIOLITE,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_SP_DEFENSE,
        .nature = NATURE_JOLLY,
		.abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_ZIGZAGOON] = {
        .species = SPECIES_BIBAREL,
        .moves = {MOVE_SWORDS_DANCE, MOVE_AQUA_JET, MOVE_QUICK_ATTACK, MOVE_SUBSTITUTE},
        .itemTableId = BATTLE_FRONTIER_ITEM_SILK_SCARF,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_JOLLY,
		.abilitynum = ABILITY_1
    },
    [FRONTIER_MON_ZUBAT] = {
        .species = SPECIES_OBSTAGOON,
        .moves = {MOVE_FIRE_PUNCH, MOVE_FACADE, MOVE_SWITCHEROO, MOVE_NIGHT_SLASH},
        .itemTableId = BATTLE_FRONTIER_ITEM_FLAME_ORB,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_ADAMANT,
		.abilitynum = ABILITY_2
    },
    [FRONTIER_MON_TOGEPI] = {
        .species = SPECIES_ABOMASNOW,
        .moves = {MOVE_BLIZZARD, MOVE_GIGA_DRAIN, MOVE_AURORA_VEIL, MOVE_FOCUS_BLAST},
        .itemTableId = BATTLE_FRONTIER_ITEM_ABOMASITE,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
		.abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_SPINARAK] = {
        .species = SPECIES_EMBOAR,//TO MOVE
        .moves = {MOVE_WILD_CHARGE, MOVE_FLARE_BLITZ, MOVE_SUCKER_PUNCH, MOVE_HAMMER_ARM},
        .itemTableId = BATTLE_FRONTIER_ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_ADAMANT,
		.abilitynum = 2
    },
    [FRONTIER_MON_MARILL] = {
        .species = SPECIES_CRYOGONAL,//TO MOVE
        .moves = {MOVE_FREEZE_DRY, MOVE_RECOVER, MOVE_FLASH_CANNON, MOVE_SIGNAL_BEAM},
        .itemTableId = BATTLE_FRONTIER_ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
		.abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_HOPPIP] = {
        .species = SPECIES_CARBINK,//TO MOVE
        .moves = {MOVE_EXPLOSION, MOVE_TRICK, MOVE_STEALTH_ROCK, MOVE_MAGIC_COAT},
        .itemTableId = BATTLE_FRONTIER_ITEM_MENTAL_HERB,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_DEFENSE,
        .nature = NATURE_LAX,
		.abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_SLUGMA] = {
        .species = SPECIES_HOUNDOOM,//TO MOVE
        .moves = {MOVE_FIRE_BLAST, MOVE_SUCKER_PUNCH, MOVE_PURSUIT, MOVE_DESTINY_BOND},
        .itemTableId = BATTLE_FRONTIER_ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
		.abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_SWINUB] = {
        .species = SPECIES_MAMOSWINE,//TO MOVE
        .moves = {MOVE_ICICLE_CRASH, MOVE_EARTHQUAKE, MOVE_STONE_EDGE, MOVE_ICE_SHARD},
        .itemTableId = BATTLE_FRONTIER_ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_JOLLY,
		.abilitynum = 2
    },
    [FRONTIER_MON_SMEARGLE] = {
        .species = SPECIES_SMEARGLE,
        .moves = {MOVE_SPORE, MOVE_FAKE_OUT, MOVE_FOUL_PLAY, MOVE_STEALTH_ROCK},
        .itemTableId = BATTLE_FRONTIER_ITEM_FOCUS_SASH,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_HP,
        .nature = NATURE_JOLLY,
		.abilitynum = 2
    },
    [FRONTIER_MON_PIDGEY] = {
        .species = SPECIES_TOUCANNON,//
        .moves = {MOVE_ROCK_BLAST, MOVE_BULLET_SEED, MOVE_U_TURN, MOVE_BRAVE_BIRD},
        .itemTableId = BATTLE_FRONTIER_ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_JOLLY,
        .abilitynum = ABILITY_HIDDEN
    },
    [FRONTIER_MON_RATTATA] = {
        .species = SPECIES_DIGGERSBY,//
        .moves = {MOVE_RETURN, MOVE_EARTHQUAKE, MOVE_FIRE_PUNCH, MOVE_SUCKER_PUNCH},
        .itemTableId = BATTLE_FRONTIER_ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_JOLLY,
        .abilitynum = 2
    },
    [FRONTIER_MON_WYNAUT] = {
        .species = SPECIES_WOBBUFFET,//TO MOVE
        .moves = {MOVE_ENCORE, MOVE_COUNTER, MOVE_MIRROR_COAT, MOVE_DESTINY_BOND},
        .itemTableId = BATTLE_FRONTIER_ITEM_QUICK_CLAW,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_DEFENSE,
        .nature = NATURE_BOLD,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_SKITTY] = {
        .species = SPECIES_SALAZZLE,//TO MOVE
        .moves = {MOVE_FLAMETHROWER, MOVE_NASTY_PLOT, MOVE_DRAGON_PULSE, MOVE_SLUDGE_WAVE},
        .itemTableId = BATTLE_FRONTIER_ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_SPEAROW] = {
        .species = SPECIES_SLOWKING,//TO MOVE
        .moves = {MOVE_SCALD, MOVE_DRAGON_TAIL, MOVE_FLAMETHROWER, MOVE_PSYCHIC},
        .itemTableId = BATTLE_FRONTIER_ITEM_ASSAULT_VEST,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_BOLD,
        .abilitynum = ABILITY_HIDDEN
    },
    [FRONTIER_MON_HOOTHOOT] = {
        .species = SPECIES_AROMATISSE,//TO MOVE
        .moves = {MOVE_MOONBLAST, MOVE_TRICK_ROOM, MOVE_WISH, MOVE_CALM_MIND},
        .itemTableId = BATTLE_FRONTIER_ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_DIGLETT] = {
        .species = SPECIES_BEEDRILL,
        .moves = {MOVE_DRILL_RUN, MOVE_KNOCK_OFF, MOVE_POISON_JAB, MOVE_X_SCISSOR},
        .itemTableId = BATTLE_FRONTIER_ITEM_BEEDRILLITE,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_JOLLY,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_LEDYBA] = {
        .species = SPECIES_AURORUS,
        .moves = {MOVE_AURORA_VEIL, MOVE_FREEZE_DRY, MOVE_STEALTH_ROCK, MOVE_POWER_GEM},
        .itemTableId = BATTLE_FRONTIER_ITEM_ICY_ROCK,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_NINCADA] = {
        .species = SPECIES_WISHIWASHI,
        .moves = {MOVE_ICE_BEAM, MOVE_EARTH_POWER, MOVE_U_TURN, MOVE_HYDRO_PUMP},
        .itemTableId = BATTLE_FRONTIER_ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_HP | F_EV_SPREAD_SP_ATTACK,
        .nature = NATURE_CALM,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_SURSKIT] = {
        .species = SPECIES_COBALION,
        .moves = {MOVE_IRON_HEAD, MOVE_SWORDS_DANCE, MOVE_CLOSE_COMBAT, MOVE_SACRED_SWORD},
        .itemTableId = BATTLE_FRONTIER_ITEM_SCOPE_LENS,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_JOLLY,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_JIGGLYPUFF] = {
        .species = SPECIES_BASTIODON,
        .moves = {MOVE_STEALTH_ROCK, MOVE_METAL_BURST, MOVE_TOXIC, MOVE_MAGIC_COAT},
        .itemTableId = BATTLE_FRONTIER_ITEM_ROCKY_HELMET,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_RELAXED,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_TAILLOW] = {
        .species = SPECIES_TYRANTRUM,
        .moves = {MOVE_HEAD_SMASH, MOVE_OUTRAGE, MOVE_DRAGON_DANCE, MOVE_EARTHQUAKE},
        .itemTableId = BATTLE_FRONTIER_ITEM_FOCUS_SASH,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .abilitynum = ABILITY_HIDDEN
    },
    [FRONTIER_MON_WINGULL] = {
        .species = SPECIES_BEARTIC,
        .moves = {MOVE_SUPERPOWER, MOVE_ICICLE_CRASH, MOVE_STONE_EDGE, MOVE_PLAY_ROUGH},
        .itemTableId = BATTLE_FRONTIER_ITEM_ASSAULT_VEST,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_JOLLY,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_NIDORAN_M] = {
        .species = SPECIES_TYPE_NULL,
        .moves = {MOVE_SWORDS_DANCE, MOVE_RETURN, MOVE_SHADOW_CLAW, MOVE_IRON_HEAD},
        .itemTableId = BATTLE_FRONTIER_ITEM_EVIOLITE,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_CAREFUL,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_NIDORAN_F] = {
        .species = SPECIES_VOLCANION,
        .moves = {MOVE_LAVA_PLUME, MOVE_STEAM_ERUPTION, MOVE_SCORCHING_SANDS, MOVE_BODY_PRESS},
        .itemTableId = BATTLE_FRONTIER_ITEM_ASSAULT_VEST,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_DEFENSE,
        .nature = NATURE_BOLD,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_KIRLIA] = {
        .species = SPECIES_REUNICLUS,
        .moves = {MOVE_FOCUS_BLAST, MOVE_SHADOW_BALL, MOVE_RECOVER, MOVE_TRICK_ROOM},
        .itemTableId = BATTLE_FRONTIER_ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
		.abilitynum = ABILITY_2
    },
    [FRONTIER_MON_MAREEP] = {
        .species = SPECIES_AMPHAROS,
        .moves = {MOVE_THUNDERBOLT, MOVE_DRAGON_PULSE, MOVE_POWER_GEM, MOVE_COTTON_GUARD},
        .itemTableId = BATTLE_FRONTIER_ITEM_AMPHAROSITE,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_MEDITITE] = {
        .species = SPECIES_MEDICHAM,
        .moves = {MOVE_HI_JUMP_KICK, MOVE_ZEN_HEADBUTT, MOVE_ICE_PUNCH, MOVE_SWORDS_DANCE},
        .itemTableId = BATTLE_FRONTIER_ITEM_MEDICHAMITE,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_JOLLY,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_SLAKOTH] = {
        .species = SPECIES_VIGOROTH,
        .moves = {MOVE_RETURN, MOVE_SUCKER_PUNCH, MOVE_EARTHQUAKE, MOVE_YAWN},
        .itemTableId = BATTLE_FRONTIER_ITEM_EVIOLITE,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_JOLLY,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_PARAS] = {
        .species = SPECIES_MALAMAR,
        .moves = {MOVE_TOPSY_TURVY, MOVE_PSYCHO_BOOST, MOVE_SUPERPOWER, MOVE_NIGHT_SLASH},
        .itemTableId = BATTLE_FRONTIER_ITEM_FOCUS_SASH,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_BRAVE,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_EKANS] = {
        .species = SPECIES_WEAVILE,
        .moves = {MOVE_ICICLE_CRASH, MOVE_NIGHT_SLASH, MOVE_SWORDS_DANCE, MOVE_FOUL_PLAY},
        .itemTableId = BATTLE_FRONTIER_ITEM_FOCUS_SASH,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_JOLLY,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_DITTO] = {
        .species = SPECIES_DITTO,
        .moves = {MOVE_TRANSFORM, MOVE_NONE, MOVE_NONE, MOVE_NONE},
        .itemTableId = BATTLE_FRONTIER_ITEM_METAL_POWDER,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_HP,
        .nature = NATURE_HARDY,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_BARBOACH] = {
        .species = SPECIES_GRIMMSNARL,
        .moves = {MOVE_TRICK, MOVE_SWAGGER, MOVE_PLAY_ROUGH, MOVE_FOUL_PLAY},
        .itemTableId = BATTLE_FRONTIER_ITEM_IRON_BALL,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_MEOWTH] = {
        .species = SPECIES_DUSCLOPS,
        .moves = {MOVE_WILL_O_WISP, MOVE_CURSE, MOVE_PROTECT, MOVE_PAYBACK},
        .itemTableId = BATTLE_FRONTIER_ITEM_EVIOLITE,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP | F_EV_SPREAD_SP_DEFENSE,
        .nature = NATURE_IMPISH,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_PINECO] = {
        .species = SPECIES_UNOWN,
        .moves = {MOVE_COSMIC_POWER, MOVE_STORED_POWER, MOVE_ANCIENT_POWER, MOVE_EARTH_POWER},
        .itemTableId = BATTLE_FRONTIER_ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_TRAPINCH] = {
        .species = SPECIES_AEGISLASH,
        .moves = {MOVE_IRON_HEAD, MOVE_SHADOW_SNEAK, MOVE_SWORDS_DANCE, MOVE_KINGS_SHIELD},
        .itemTableId = BATTLE_FRONTIER_ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP | F_EV_SPREAD_SP_DEFENSE,
        .nature = NATURE_CAREFUL,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_SPHEAL] = {
        .species = SPECIES_SANDSLASH_ALOLAN,
        .moves = {MOVE_ICE_BALL, MOVE_HONE_CLAWS, MOVE_IRON_TAIL, MOVE_SPIKY_SHIELD},
        .itemTableId = BATTLE_FRONTIER_ITEM_SHELL_BELL,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_DEFENSE,
        .nature = NATURE_IMPISH,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_HORSEA] = {
        .species = SPECIES_PORYGON_Z,
        .moves = {MOVE_ICE_BEAM, MOVE_SHADOW_BALL, MOVE_TRI_ATTACK, MOVE_RECOVER},
        .itemTableId = BATTLE_FRONTIER_ITEM_WISE_GLASSES,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_SHROOMISH] = {
        .species = SPECIES_BRELOOM,
        .moves = {MOVE_SPORE, MOVE_BULK_UP, MOVE_DRAIN_PUNCH, MOVE_SEED_BOMB},
        .itemTableId = BATTLE_FRONTIER_ITEM_QUICK_CLAW,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_DEFENSE,
        .nature = NATURE_IMPISH,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_SHUPPET] = {
        .species = SPECIES_DRAPION,
        .moves = {MOVE_WICKED_BLOW, MOVE_CROSS_POISON, MOVE_SWORDS_DANCE, MOVE_LEECH_LIFE},
        .itemTableId = BATTLE_FRONTIER_ITEM_SCOPE_LENS,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_JOLLY,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_DUSKULL] = {
        .species = SPECIES_CHANDELURE,
        .moves = {MOVE_SHADOW_BALL, MOVE_TRICK, MOVE_MEMENTO, MOVE_FIRE_BLAST},
        .itemTableId = BATTLE_FRONTIER_ITEM_CHOICE_SCARF,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
		.abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_ELECTRIKE] = {
        .species = SPECIES_CHESNAUGHT,
        .moves = {MOVE_SPIKY_SHIELD, MOVE_DRAIN_PUNCH, MOVE_SHELL_SMASH, MOVE_NEEDLE_ARM},
        .itemTableId = BATTLE_FRONTIER_ITEM_WHITE_HERB,
		.evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP | F_EV_SPREAD_SPEED,
        .nature = NATURE_JOLLY,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_VULPIX] = {
        .species = SPECIES_NINETALES,
        .moves = {MOVE_MORNING_SUN, MOVE_SOLAR_BEAM, MOVE_FIRE_BLAST, MOVE_SHADOW_BALL},
        .itemTableId = BATTLE_FRONTIER_ITEM_HEAT_ROCK,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
		.abilitynum = 2
    },
    [FRONTIER_MON_PIKACHU] = {
        .species = SPECIES_MEGANIUM,
        .moves = {MOVE_GIGA_DRAIN, MOVE_STRENGTH_SAP, MOVE_DRAINING_KISS, MOVE_TOXIC    },
        .itemTableId = BATTLE_FRONTIER_ITEM_LUM_BERRY,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_BOLD,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_SANDSHREW] = {
        .species = SPECIES_PIDGEOT,
        .moves = {MOVE_HURRICANE, MOVE_HEAT_WAVE, MOVE_AIR_SLASH, MOVE_U_TURN    },
        .itemTableId = BATTLE_FRONTIER_ITEM_PIDGEOTITE,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_POLIWAG] = {
        .species = SPECIES_POLIWRATH,
        .moves = {MOVE_BULLET_PUNCH, MOVE_AQUA_JET, MOVE_MACH_PUNCH, MOVE_BELLY_DRUM    },
        .itemTableId = BATTLE_FRONTIER_ITEM_SITRUS_BERRY,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_DEFENSE,
        .nature = NATURE_RELAXED,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_BELLSPROUT] = {
        .species = SPECIES_LEAFEON,
        .moves = {MOVE_LEAF_BLADE, MOVE_SWORDS_DANCE, MOVE_DIG, MOVE_BITE   },
        .itemTableId = BATTLE_FRONTIER_ITEM_QUICK_CLAW,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_DEFENSE | F_EV_SPREAD_SPEED,
        .nature = NATURE_IMPISH,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_GEODUDE] = {
        .species = SPECIES_SHUCKLE,
        .moves = {MOVE_TOXIC, MOVE_STRENGTH_SAP, MOVE_INFESTATION, MOVE_PROTECT    },
        .itemTableId = BATTLE_FRONTIER_ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_CALM,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_DRATINI] = {
        .species = SPECIES_PORYGON2,
        .moves = {MOVE_TRICK_ROOM, MOVE_RECOVER, MOVE_CHARGE_BEAM, MOVE_ICE_BEAM    },
        .itemTableId = BATTLE_FRONTIER_ITEM_EVIOLITE,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_SP_DEFENSE,
        .nature = NATURE_BOLD,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_SNUBBULL] = {
        .species = SPECIES_UMBREON,
        .moves = {MOVE_SWAGGER, MOVE_FOUL_PLAY, MOVE_PROTECT, MOVE_WISH    },
        .itemTableId = BATTLE_FRONTIER_ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_BOLD,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_REMORAID] = {
        .species = SPECIES_PRIMARINA,
        .moves = {MOVE_SCALD, MOVE_MOONBLAST, MOVE_PSYCHIC, MOVE_ENERGY_BALL    },
        .itemTableId = BATTLE_FRONTIER_ITEM_CHOICE_SPECS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SP_DEFENSE,
        .nature = NATURE_MODEST,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_LARVITAR] = {
        .species = SPECIES_CENTISKORCH,
        .moves = {MOVE_COIL, MOVE_IRON_TAIL, MOVE_LUNGE, MOVE_FIRE_LASH    },
        .itemTableId = BATTLE_FRONTIER_ITEM_WIDE_LENS,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_JOLLY,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_BALTOY] = {
        .species = SPECIES_CORVIKNIGHT,
        .moves = {MOVE_BULK_UP, MOVE_ROOST, MOVE_POWER_TRIP, MOVE_BODY_PRESS    },
        .itemTableId = BATTLE_FRONTIER_ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_HP | F_EV_SPREAD_DEFENSE,
        .nature = NATURE_IMPISH,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_SNORUNT] = {
        .species = SPECIES_LATIAS,
        .moves = {MOVE_DRAGON_PULSE, MOVE_MYSTICAL_FIRE, MOVE_PSYSHOCK, MOVE_ROOST    },
        .itemTableId = BATTLE_FRONTIER_ITEM_SOUL_DEW,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SP_DEFENSE,
        .nature = NATURE_CALM,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_BAGON] = {
        .species = SPECIES_LATIOS,
        .moves = {MOVE_DRAGON_PULSE, MOVE_PSYCHIC, MOVE_AIR_SLASH, MOVE_ROOST    },
        .itemTableId = BATTLE_FRONTIER_ITEM_SOUL_DEW,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SP_DEFENSE,
        .nature = NATURE_MODEST,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_BELDUM] = {
        .species = SPECIES_METAGROSS,
        .moves = {MOVE_METEOR_MASH, MOVE_ZEN_HEADBUTT, MOVE_ICE_PUNCH, MOVE_EARTHQUAKE},
        .itemTableId = BATTLE_FRONTIER_ITEM_METAGROSSITE,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_JOLLY,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_GULPIN] = {
        .species = SPECIES_KROOKODILE,
        .moves = {MOVE_CRUNCH, MOVE_ROCK_SLIDE, MOVE_EARTHQUAKE, MOVE_DRAIN_PUNCH    },
        .itemTableId = BATTLE_FRONTIER_ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_JOLLY,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_VENONAT] = {
        .species = SPECIES_TYRANITAR,
        .moves = {MOVE_SHORE_UP, MOVE_CRUNCH, MOVE_DRAGON_DANCE, MOVE_STONE_EDGE   },
        .itemTableId = BATTLE_FRONTIER_ITEM_TYRANITARITE,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_DEFENSE,
        .nature = NATURE_IMPISH,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_MANKEY] = {
        .species = SPECIES_CHANSEY,
        .moves = {MOVE_SOFT_BOILED, MOVE_TOXIC, MOVE_ATTRACT, MOVE_SEISMIC_TOSS    },
        .itemTableId = BATTLE_FRONTIER_ITEM_EVIOLITE,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_BOLD,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_MACHOP] = {
        .species = SPECIES_SLAKING,
        .moves = {MOVE_GIGA_IMPACT, MOVE_SHADOW_CLAW, MOVE_SLACK_OFF, MOVE_FEINT    },
        .itemTableId = BATTLE_FRONTIER_ITEM_LUM_BERRY,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_SHELLDER] = {
        .species = SPECIES_HONCHKROW,
        .moves = {MOVE_NIGHT_SLASH, MOVE_ROOST, MOVE_AIR_SLASH, MOVE_PSYCHIC    },
        .itemTableId = BATTLE_FRONTIER_ITEM_SCOPE_LENS,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_SP_ATTACK,
        .nature = NATURE_SERIOUS,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_SMOOCHUM] = {
        .species = SPECIES_EELEKTROSS,
        .moves = {MOVE_COIL, MOVE_WILD_CHARGE, MOVE_FIRE_PUNCH, MOVE_AQUA_TAIL    },
        .itemTableId = BATTLE_FRONTIER_ITEM_SHELL_BELL,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_DEFENSE,
        .nature = NATURE_ADAMANT,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_NUMEL] = {
        .species = SPECIES_CHATOT,
        .moves = {MOVE_NASTY_PLOT, MOVE_AIR_SLASH, MOVE_BOOMBURST, MOVE_HEAT_WAVE   },
        .itemTableId = BATTLE_FRONTIER_ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_CARVANHA] = {
        .species = SPECIES_HERACROSS,
        .moves = {MOVE_PIN_MISSILE, MOVE_ARM_THRUST, MOVE_ROCK_BLAST, MOVE_BULK_UP    },
        .itemTableId = BATTLE_FRONTIER_ITEM_HERACRONITE,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_DEFENSE,
        .nature = NATURE_ADAMANT,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_CORPHISH] = {
        .species = SPECIES_GLISCOR,
        .moves = {MOVE_CRABHAMMER, MOVE_SWORDS_DANCE, MOVE_EARTHQUAKE, MOVE_AERIAL_ACE    },
        .itemTableId = BATTLE_FRONTIER_ITEM_SCOPE_LENS,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_JOLLY,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_CHARMANDER] = {
        .species = SPECIES_CRESSELIA,
        .moves = {MOVE_COSMIC_POWER, MOVE_RECOVER, MOVE_STORED_POWER, MOVE_ICE_BEAM    },
        .itemTableId = BATTLE_FRONTIER_ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_HP | F_EV_SPREAD_DEFENSE | F_EV_SPREAD_SP_DEFENSE,
        .nature = NATURE_BOLD,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_CYNDAQUIL] = {
        .species = SPECIES_SWELLOW,
        .moves = {MOVE_FACADE, MOVE_U_TURN, MOVE_AERIAL_ACE, MOVE_STEEL_WING    },
        .itemTableId = BATTLE_FRONTIER_ITEM_FLAME_ORB,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_JOLLY,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_ABRA] = {
        .species = SPECIES_AGGRON,
        .moves = {MOVE_BODY_PRESS, MOVE_FIRE_PUNCH, MOVE_METAL_BURST, MOVE_CURSE    },
        .itemTableId = BATTLE_FRONTIER_ITEM_AGGRONITE,
        .evSpread = F_EV_SPREAD_HP | F_EV_SPREAD_DEFENSE,
        .nature = NATURE_RELAXED,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_DODUO] = {
        .species = SPECIES_DODRIO,
        .moves = {MOVE_JUMP_KICK, MOVE_BRAVE_BIRD, MOVE_DRILL_RUN, MOVE_SWORDS_DANCE    },
        .itemTableId = BATTLE_FRONTIER_ITEM_SITRUS_BERRY,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_GASTLY] = {
        .species = SPECIES_GOURGEIST,
        .moves = {MOVE_LEECH_SEED, MOVE_SYNTHESIS, MOVE_WILL_O_WISP, MOVE_FOUL_PLAY},
        .itemTableId = BATTLE_FRONTIER_ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_BOLD,
		.abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_SWABLU] = {
        .species = SPECIES_SLOWBRO,
        .moves = {MOVE_BODY_PRESS, MOVE_SLACK_OFF, MOVE_PSYSHOCK, MOVE_SCALD    },
        .itemTableId = BATTLE_FRONTIER_ITEM_SLOWBRONITE,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_RELAXED,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_TREECKO] = {
        .species = SPECIES_INTELEON,
        .moves = {MOVE_AIR_SLASH, MOVE_DARK_PULSE, MOVE_SCALD, MOVE_ICE_BEAM    },
        .itemTableId = BATTLE_FRONTIER_ITEM_CHOICE_SPECS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_TORCHIC] = {
        .species = SPECIES_MACHAMP,
        .moves = {MOVE_FISSURE, MOVE_DYNAMIC_PUNCH, MOVE_STONE_EDGE, MOVE_BULLET_PUNCH    },
        .itemTableId = BATTLE_FRONTIER_ITEM_FOCUS_SASH,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_MUDKIP] = {
        .species = SPECIES_DARMANITAN_GALARIAN,
        .moves = {MOVE_FLARE_BLITZ, MOVE_ICICLE_CRASH, MOVE_EARTHQUAKE, MOVE_DRAIN_PUNCH    },
        .itemTableId = BATTLE_FRONTIER_ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_JOLLY,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_SQUIRTLE] = {
        .species = SPECIES_POLTEAGEIST,
        .moves = {MOVE_SHELL_SMASH, MOVE_STRENGTH_SAP, MOVE_SHADOW_BALL, MOVE_GIGA_DRAIN    },
        .itemTableId = BATTLE_FRONTIER_ITEM_WHITE_HERB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SP_DEFENSE,
        .nature = NATURE_MODEST,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_TOTODILE] = {
        .species = SPECIES_REUNICLUS,
        .moves = {MOVE_THUNDERBOLT, MOVE_TRICK_ROOM, MOVE_SHADOW_BALL, MOVE_PSYCHIC    },
        .itemTableId = BATTLE_FRONTIER_ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_SLOWPOKE] = {
        .species = SPECIES_TALONFLAME,
        .moves = {MOVE_BRAVE_BIRD, MOVE_FLARE_BLITZ, MOVE_U_TURN, MOVE_SWORDS_DANCE    },
        .itemTableId = BATTLE_FRONTIER_ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_JOLLY,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_BULBASAUR] = {
        .species = SPECIES_MAROWAK_ALOLAN,
        .moves = {MOVE_FLARE_BLITZ, MOVE_THUNDER_PUNCH, MOVE_SHADOW_BONE, MOVE_EARTHQUAKE    },
        .itemTableId = BATTLE_FRONTIER_ITEM_THICK_CLUB,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_DEFENSE,
        .nature = NATURE_ADAMANT,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_CHIKORITA] = {
        .species = SPECIES_BLACEPHALON,
        .moves = {MOVE_MIND_BLOWN, MOVE_CALM_MIND, MOVE_SHADOW_BALL, MOVE_PSYCHIC    },
        .itemTableId = BATTLE_FRONTIER_ITEM_SITRUS_BERRY,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_RELAXED,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_ODDISH] = {
        .species = SPECIES_VIKAVOLT,
        .moves = {MOVE_BUG_BUZZ, MOVE_THUNDERBOLT, MOVE_FLASH_CANNON, MOVE_AIR_SLASH    },
        .itemTableId = BATTLE_FRONTIER_ITEM_CHOICE_SPECS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_PSYDUCK] = {
        .species = SPECIES_GOODRA,
        .moves = {MOVE_DRAGON_PULSE, MOVE_SLUDGE_WAVE, MOVE_MUDDY_WATER, MOVE_THUNDERBOLT    },
        .itemTableId = BATTLE_FRONTIER_ITEM_ASSAULT_VEST,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SP_DEFENSE,
        .nature = NATURE_CALM,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_CUBONE] = {
        .species = SPECIES_HYDREIGON,
        .moves = {MOVE_DARK_PULSE, MOVE_DRACO_METEOR, MOVE_EARTH_POWER, MOVE_FLASH_CANNON    },
        .itemTableId = BATTLE_FRONTIER_ITEM_WHITE_HERB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_GOLDEEN] = {
        .species = SPECIES_TOGEKISS,
        .moves = {MOVE_MOONBLAST, MOVE_AIR_SLASH, MOVE_SILVER_WIND, MOVE_WATER_PULSE    },
        .itemTableId = BATTLE_FRONTIER_ITEM_ASSAULT_VEST,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_NATU] = {
        .species = SPECIES_CHARIZARD,
        .moves = {MOVE_FLAMETHROWER, MOVE_SOLAR_BEAM, MOVE_AIR_SLASH, MOVE_DRAGON_PULSE    },
        .itemTableId = BATTLE_FRONTIER_ITEM_CHARIZARDITE_Y,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_CLEFAIRY] = {
        .species = SPECIES_CLEFABLE,
        .moves = {MOVE_COSMIC_POWER, MOVE_MOONBLAST, MOVE_CHARGE_BEAM, MOVE_SOFT_BOILED    },
        .itemTableId = BATTLE_FRONTIER_ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_DEFENSE	| F_EV_SPREAD_HP,
        .nature = NATURE_CALM,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_MAGNEMITE] = {
        .species = SPECIES_MAGNEZONE,
        .moves = {MOVE_DISCHARGE, MOVE_FLASH_CANNON, MOVE_MIRROR_COAT, MOVE_SIGNAL_BEAM    },
        .itemTableId = BATTLE_FRONTIER_ITEM_AIR_BALLOON,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_SEEL] = {
        .species = SPECIES_PROBOPASS,
        .moves = {MOVE_BODY_PRESS, MOVE_METAL_BURST, MOVE_IRON_DEFENSE, MOVE_TAUNT    },
        .itemTableId = BATTLE_FRONTIER_ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_BOLD,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_GRIMER] = {
        .species = SPECIES_HITMONTOP,
        .moves = {MOVE_CLOSE_COMBAT, MOVE_RAPID_SPIN, MOVE_U_TURN, MOVE_FORESIGHT    },
        .itemTableId = BATTLE_FRONTIER_ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_IMPISH,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_KRABBY] = {
        .species = SPECIES_BISHARP,
        .moves = {MOVE_SWORDS_DANCE, MOVE_IRON_HEAD, MOVE_KNOCK_OFF, MOVE_SUCKER_PUNCH    },
        .itemTableId = BATTLE_FRONTIER_ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_ADAMANT,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_EXEGGCUTE] = {
        .species = SPECIES_ABSOL,
        .moves = {MOVE_SWORDS_DANCE, MOVE_SUCKER_PUNCH, MOVE_KNOCK_OFF, MOVE_PLAY_ROUGH    },
        .itemTableId = BATTLE_FRONTIER_ITEM_ABSOLITE,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_JOLLY,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_EEVEE] = {
        .species = SPECIES_ACCELGOR,
        .moves = {MOVE_SPIKES, MOVE_BUG_BUZZ, MOVE_ENERGY_BALL, MOVE_FINAL_GAMBIT    },
        .itemTableId = BATTLE_FRONTIER_ITEM_CHOICE_SPECS,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_HP,
        .nature = NATURE_TIMID,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_DROWZEE] = {
        .species = SPECIES_AERODACTYL,
        .moves = {MOVE_STONE_EDGE, MOVE_EARTHQUAKE, MOVE_ICE_FANG, MOVE_ROOST    },
        .itemTableId = BATTLE_FRONTIER_ITEM_AERODACTYLITE,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_VOLTORB] = {
        .species = SPECIES_ELECTRODE,
        .moves = {MOVE_ELECTRO_BALL, MOVE_MIRROR_COAT, MOVE_SIGNAL_BEAM, MOVE_LIGHT_SCREEN    },
        .itemTableId = BATTLE_FRONTIER_ITEM_FOCUS_SASH,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_HP,
        .nature = NATURE_TIMID,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_CHINCHOU] = {
        .species = SPECIES_LANTURN,
        .moves = {MOVE_TAIL_GLOW, MOVE_SCALD, MOVE_THUNDERBOLT, MOVE_SIGNAL_BEAM    },
        .itemTableId = BATTLE_FRONTIER_ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_CALM,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_TEDDIURSA] = {
        .species = SPECIES_URSARING,
        .moves = {MOVE_FACADE, MOVE_SWORDS_DANCE, MOVE_CRUNCH, MOVE_CLOSE_COMBAT    },
        .itemTableId = BATTLE_FRONTIER_ITEM_FLAME_ORB,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_BRAVE,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_DELIBIRD] = {
        .species = SPECIES_ALAKAZAM,
        .moves = {MOVE_PSYCHIC, MOVE_SHADOW_BALL, MOVE_RECOVER, MOVE_FOCUS_BLAST    },
        .itemTableId = BATTLE_FRONTIER_ITEM_ALAKAZITE,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_HOUNDOUR] = {
        .species = SPECIES_ALOMOMOLA,
        .moves = {MOVE_WISH, MOVE_PROTECT, MOVE_TOXIC, MOVE_KNOCK_OFF    },
        .itemTableId = BATTLE_FRONTIER_ITEM_ROCKY_HELMET,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_DEFENSE,
        .nature = NATURE_IMPISH,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_PHANPY] = {
        .species = SPECIES_ALTARIA,
        .moves = {MOVE_DRAGON_DANCE, MOVE_RETURN, MOVE_DEFOG, MOVE_ROOST    },
        .itemTableId = BATTLE_FRONTIER_ITEM_ALTARIANITE,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_ADAMANT,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_SPOINK] = {
        .species = SPECIES_DURANT,
        .moves = {MOVE_HONE_CLAWS, MOVE_IRON_HEAD, MOVE_SUPERPOWER, MOVE_ROCK_SLIDE    },
        .itemTableId = BATTLE_FRONTIER_ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_JOLLY,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_ARON] = {
        .species = SPECIES_CRAWDAUNT,
        .moves = {MOVE_SWORDS_DANCE, MOVE_AQUA_JET, MOVE_CRABHAMMER, MOVE_KNOCK_OFF    },
        .itemTableId = BATTLE_FRONTIER_ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_JOLLY,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_LUVDISC] = {
        .species = SPECIES_DHELMISE,
        .moves = {MOVE_POWER_WHIP, MOVE_ANCHOR_SHOT, MOVE_RAPID_SPIN, MOVE_SYNTHESIS    },
        .itemTableId = BATTLE_FRONTIER_ITEM_QUICK_CLAW,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_TENTACOOL] = {
        .species = SPECIES_ESPEON,
        .moves = {MOVE_CALM_MIND, MOVE_PSYCHIC, MOVE_SHADOW_BALL, MOVE_ZAP_CANNON    },
        .itemTableId = BATTLE_FRONTIER_ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_CACNEA] = {
        .species = SPECIES_ORICORIO,
        .moves = {MOVE_QUIVER_DANCE, MOVE_REVELATION_DANCE, MOVE_AIR_SLASH, MOVE_ROOST    },
        .itemTableId = BATTLE_FRONTIER_ITEM_FOCUS_SASH,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_UNOWN] = {
        .species = SPECIES_CLOYSTER,
        .moves = {MOVE_SHELL_SMASH, MOVE_LIQUIDATION, MOVE_ICICLE_CRASH, MOVE_MEGAHORN    },
        .itemTableId = BATTLE_FRONTIER_ITEM_WHITE_HERB,
        .evSpread = F_EV_SPREAD_HP | F_EV_SPREAD_ATTACK,
        .nature = NATURE_IMPISH,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_KOFFING] = {
        .species = SPECIES_ARMALDO,
        .moves = {MOVE_RAPID_SPIN, MOVE_STONE_EDGE, MOVE_KNOCK_OFF, MOVE_EARTHQUAKE    },
        .itemTableId = BATTLE_FRONTIER_ITEM_ASSAULT_VEST,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_HP,
        .nature = NATURE_JOLLY,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_STARYU] = {
        .species = SPECIES_KABUTOPS,
        .moves = {MOVE_RAPID_SPIN, MOVE_SUPERPOWER, MOVE_STONE_EDGE, MOVE_LIQUIDATION    },
        .itemTableId = BATTLE_FRONTIER_ITEM_CHOICE_SCARF,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_JOLLY,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_SKIPLOOM] = {
        .species = SPECIES_GASTRODON,
        .moves = {MOVE_SCALD, MOVE_EARTHQUAKE, MOVE_TOXIC, MOVE_RECOVER    },
        .itemTableId = BATTLE_FRONTIER_ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_SASSY,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_NUZLEAF] = {
        .species = SPECIES_BRONZONG,
        .moves = {MOVE_PSYWAVE, MOVE_TOXIC, MOVE_STEALTH_ROCK, MOVE_PROTECT    },
        .itemTableId = BATTLE_FRONTIER_ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_SASSY,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_LOMBRE] = {
        .species = SPECIES_LUDICOLO,
        .moves = {MOVE_HYDRO_PUMP, MOVE_ICE_BEAM, MOVE_GIGA_DRAIN, MOVE_SCALD},
        .itemTableId = BATTLE_FRONTIER_ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
		.abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_VIBRAVA] = {
        .species = SPECIES_DRAMPA,
        .moves = {MOVE_DRACO_METEOR, MOVE_HYPER_VOICE, MOVE_FLAMETHROWER, MOVE_FOCUS_BLAST    },
        .itemTableId = BATTLE_FRONTIER_ITEM_CHOICE_SPECS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_RHYHORN] = {
        .species = SPECIES_RHYPERIOR,//TO REMOVE
        .moves = {MOVE_STEALTH_ROCK, MOVE_ICE_PUNCH, MOVE_EARTHQUAKE, MOVE_ROCK_BLAST},
        .itemTableId = BATTLE_FRONTIER_ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
		.abilitynum = ABILITY_2
    },
    [FRONTIER_MON_CLAMPERL] = {
        .species = SPECIES_CELEBI,
        .moves = {MOVE_NASTY_PLOT, MOVE_PSYCHIC, MOVE_LEAF_STORM, MOVE_RECOVER    },
        .itemTableId = BATTLE_FRONTIER_ITEM_WHITE_HERB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_PIDGEOTTO] = {
        .species = SPECIES_CHATOT,
        .moves = {MOVE_BOOMBURST, MOVE_HEAT_WAVE, MOVE_CHATTER, MOVE_NASTY_PLOT},
        .itemTableId = BATTLE_FRONTIER_ITEM_FOCUS_SASH,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
		.abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_GROWLITHE] = {
        .species = SPECIES_AVALUGG,
        .moves = {MOVE_MIRROR_COAT, MOVE_ICE_SHARD, MOVE_EARTHQUAKE, MOVE_TOXIC    },
        .itemTableId = BATTLE_FRONTIER_ITEM_FOCUS_SASH,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_IMPISH,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_FARFETCHD] = {
        .species = SPECIES_FARFETCHD,
        .moves = {MOVE_SLASH, MOVE_KNOCK_OFF, MOVE_SWORDS_DANCE, MOVE_LEAF_BLADE    },
        .itemTableId = BATTLE_FRONTIER_ITEM_STICK,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_ADAMANT,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_OMANYTE] = {
        .species = SPECIES_MOLTRES,
        .moves = {MOVE_NASTY_PLOT, MOVE_HEAT_WAVE, MOVE_SOLAR_BEAM, MOVE_AIR_SLASH    },
        .itemTableId = BATTLE_FRONTIER_ITEM_POWER_HERB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_KABUTO] = {
        .species = SPECIES_INFERNAPE,
        .moves = {MOVE_BULK_UP, MOVE_DRAIN_PUNCH, MOVE_FLARE_BLITZ, MOVE_BULLET_PUNCH    },
        .itemTableId = BATTLE_FRONTIER_ITEM_FOCUS_SASH,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_LILEEP] = {
        .species = SPECIES_VICTINI,
        .moves = {MOVE_V_CREATE, MOVE_ZEN_HEADBUTT, MOVE_THUNDER_PUNCH, MOVE_BRICK_BREAK    },
        .itemTableId = BATTLE_FRONTIER_ITEM_CHOICE_SCARF,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_JOLLY,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_ANORITH] = {
        .species = SPECIES_REGICE,
        .moves = {MOVE_CHARGE_BEAM, MOVE_ICY_WIND, MOVE_FOCUS_BLAST, MOVE_FLASH_CANNON    },
        .itemTableId = BATTLE_FRONTIER_ITEM_ASSAULT_VEST,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SP_DEFENSE,
        .nature = NATURE_CALM,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_AIPOM] = {
        .species = SPECIES_REGISTEEL,
        .moves = {MOVE_GYRO_BALL, MOVE_SUBSTITUTE, MOVE_CURSE, MOVE_BODY_PRESS    },
        .itemTableId = BATTLE_FRONTIER_ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_RELAXED,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_ELEKID] = {
        .species = SPECIES_GALLADE,
        .moves = {MOVE_SWORDS_DANCE, MOVE_CLOSE_COMBAT, MOVE_ZEN_HEADBUTT, MOVE_KNOCK_OFF    },
        .itemTableId = BATTLE_FRONTIER_ITEM_GALLADITE,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_JOLLY,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_LOUDRED] = {
        .species = SPECIES_EXPLOUD,//TO REMOVE
        .moves = {MOVE_BOOMBURST, MOVE_ICE_BEAM, MOVE_FIRE_BLAST, MOVE_THUNDERBOLT},
        .itemTableId = BATTLE_FRONTIER_ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_TIMID,
		.abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_SPINDA] = {
        .species = SPECIES_GOGOAT,
        .moves = {MOVE_WILD_CHARGE, MOVE_MILK_DRINK, MOVE_LEAF_BLADE, MOVE_EARTHQUAKE    },
        .itemTableId = BATTLE_FRONTIER_ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_JOLLY,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_NIDORINA] = {
        .species = SPECIES_HEATRAN,
        .moves = {MOVE_LAVA_PLUME, MOVE_PROTECT, MOVE_TOXIC, MOVE_TAUNT    },
        .itemTableId = BATTLE_FRONTIER_ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_CALM,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_NIDORINO] = {
        .species = SPECIES_HELIOLISK,
        .moves = {MOVE_VOLT_SWITCH, MOVE_SURF, MOVE_HYPER_VOICE, MOVE_THUNDERBOLT    },
        .itemTableId = BATTLE_FRONTIER_ITEM_CHOICE_SPECS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_FLAAFFY] = {
        .species = SPECIES_LOPUNNY,
        .moves = {MOVE_RETURN, MOVE_FAKE_OUT, MOVE_HI_JUMP_KICK, MOVE_ICE_PUNCH    },
        .itemTableId = BATTLE_FRONTIER_ITEM_LOPUNNITE,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_JOLLY,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_MAGBY] = {
        .species = SPECIES_JIRACHI,
        .moves = {MOVE_FIRE_PUNCH, MOVE_ZEN_HEADBUTT, MOVE_IRON_HEAD, MOVE_DRAIN_PUNCH     },
        .itemTableId = BATTLE_FRONTIER_ITEM_CHOICE_SCARF,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_JOLLY,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_NOSEPASS] = {
        .species = SPECIES_LUGIA,
        .moves = {MOVE_ROOST, MOVE_PSYCHIC, MOVE_TOXIC, MOVE_ICE_BEAM    },
        .itemTableId = BATTLE_FRONTIER_ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_BOLD,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_CORSOLA] = {
        .species = SPECIES_MANDIBUZZ,
        .moves = {MOVE_FOUL_PLAY, MOVE_ROOST, MOVE_TAUNT, MOVE_DEFOG    },
        .itemTableId = BATTLE_FRONTIER_ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_CAREFUL,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_MAWILE] = {
        .species = SPECIES_MAWILE,
        .moves = {MOVE_SUCKER_PUNCH, MOVE_PLAY_ROUGH, MOVE_SWORDS_DANCE, MOVE_THUNDER_PUNCH    },
        .itemTableId = BATTLE_FRONTIER_ITEM_MAWILITE,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_ADAMANT,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_BUTTERFREE] = {
        .species = SPECIES_BUTTERFREE,
        .moves = {MOVE_QUIVER_DANCE, MOVE_SLEEP_POWDER, MOVE_HURRICANE, MOVE_BUG_BUZZ    },
        .itemTableId = BATTLE_FRONTIER_ITEM_WIDE_LENS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_BEEDRILL] = {
        .species = SPECIES_WOBBUFFET,
        .moves = {MOVE_METAL_BURST, MOVE_DESTINY_BOND, MOVE_STRENGTH_SAP, MOVE_HAZE    },
        .itemTableId = BATTLE_FRONTIER_ITEM_FOCUS_SASH,
        .evSpread = F_EV_SPREAD_HP | F_EV_SPREAD_DEFENSE,
        .nature = NATURE_SASSY,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_POLIWHIRL] = {
        .species = SPECIES_POLIWRATH,
        .moves = {MOVE_WATER_PULSE, MOVE_DOUBLE_SLAP, MOVE_ICY_WIND, MOVE_RAIN_DANCE    },
        .itemTableId = BATTLE_FRONTIER_ITEM_PETAYA_BERRY,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_QUIRKY,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_ONIX] = {
        .species = SPECIES_STEELIX,
        .moves = {MOVE_EARTHQUAKE, MOVE_COIL, MOVE_BODY_PRESS, MOVE_IRON_HEAD    },
        .itemTableId = BATTLE_FRONTIER_ITEM_STEELIXITE,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_CAREFUL,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_BEAUTIFLY] = {
        .species = SPECIES_BEAUTIFLY,
        .moves = {MOVE_BUG_BUZZ, MOVE_AIR_SLASH, MOVE_ATTRACT, MOVE_QUIVER_DANCE    },
        .itemTableId = BATTLE_FRONTIER_ITEM_FOCUS_SASH,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_SP_ATTACK,
        .nature = NATURE_DOCILE,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_DUSTOX] = {
        .species = SPECIES_GOODRA,
        .moves = {MOVE_FLAMETHROWER, MOVE_THUNDERBOLT, MOVE_SLUDGE_WAVE, MOVE_DRAGON_PULSE},
        .itemTableId = BATTLE_FRONTIER_ITEM_ASSAULT_VEST,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SP_DEFENSE,
        .nature = NATURE_CALM,
		.abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_LEDIAN] = {
        .species = SPECIES_OBSTAGOON,
        .moves = {MOVE_OBSTRUCT, MOVE_FACADE, MOVE_SWITCHEROO, MOVE_NIGHT_SLASH},
        .itemTableId = BATTLE_FRONTIER_ITEM_FLAME_ORB,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_ADAMANT,
		.abilitynum = ABILITY_2
    },
    [FRONTIER_MON_ARIADOS] = {
        .species = SPECIES_ARIADOS, //
        .moves = {MOVE_SIGNAL_BEAM, MOVE_SPIDER_WEB, MOVE_NIGHT_SHADE, MOVE_TOXIC    },
        .itemTableId = BATTLE_FRONTIER_ITEM_LAX_INCENSE,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_SERIOUS,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_YANMA] = {
        .species = SPECIES_YANMA,
        .moves = {MOVE_SIGNAL_BEAM, MOVE_AERIAL_ACE, MOVE_DOUBLE_TEAM, MOVE_DETECT    },
        .itemTableId = BATTLE_FRONTIER_ITEM_LAX_INCENSE,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_DEFENSE,
        .nature = NATURE_RELAXED,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_DELCATTY_1] = {
        .species = SPECIES_DELCATTY,
        .moves = {MOVE_SECRET_POWER, MOVE_FAINT_ATTACK, MOVE_DOUBLE_TEAM, MOVE_HEAL_BELL    },
        .itemTableId = BATTLE_FRONTIER_ITEM_SITRUS_BERRY,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_LONELY,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_SABLEYE_1] = {
        .species = SPECIES_SABLEYE,
        .moves = {MOVE_FAINT_ATTACK, MOVE_CONFUSE_RAY, MOVE_KNOCK_OFF, MOVE_FAKE_OUT    },
        .itemTableId = BATTLE_FRONTIER_ITEM_BLACK_GLASSES,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_LONELY,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_LICKITUNG_1] = {
        .species = SPECIES_LICKITUNG,
        .moves = {MOVE_SLAM, MOVE_BRICK_BREAK, MOVE_LICK, MOVE_MUD_SLAP    },
        .itemTableId = BATTLE_FRONTIER_ITEM_SITRUS_BERRY,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_QUIRKY,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_WEEPINBELL_1] = {
        .species = SPECIES_WEEPINBELL,
        .moves = {MOVE_RAZOR_LEAF, MOVE_ACID, MOVE_WRAP, MOVE_SWEET_SCENT    },
        .itemTableId = BATTLE_FRONTIER_ITEM_SCOPE_LENS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_QUIET,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_GRAVELER_1] = {
        .species = SPECIES_GRAVELER,
        .moves = {MOVE_MAGNITUDE, MOVE_ROCK_THROW, MOVE_DEFENSE_CURL, MOVE_BRICK_BREAK    },
        .itemTableId = BATTLE_FRONTIER_ITEM_FOCUS_BAND,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_GLOOM_1] = {
        .species = SPECIES_GLOOM,
        .moves = {MOVE_PETAL_DANCE, MOVE_ACID, MOVE_STUN_SPORE, MOVE_MOONLIGHT    },
        .itemTableId = BATTLE_FRONTIER_ITEM_PERSIM_BERRY,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_QUIRKY,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_PORYGON_1] = {
        .species = SPECIES_PORYGON_Z,//TO REMOVE
        .moves = {MOVE_TRI_ATTACK, MOVE_ICE_BEAM, MOVE_THUNDERBOLT, MOVE_RECOVER},
        .itemTableId = BATTLE_FRONTIER_ITEM_CHOICE_SCARF,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
		.abilitynum = ABILITY_1
    },
    [FRONTIER_MON_KADABRA_1] = {
        .species = SPECIES_KADABRA,
        .moves = {MOVE_CONFUSION, MOVE_ROLE_PLAY, MOVE_FUTURE_SIGHT, MOVE_DISABLE    },
        .itemTableId = BATTLE_FRONTIER_ITEM_TWISTED_SPOON,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_IMPISH,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_WAILMER_1] = {
        .species = SPECIES_WAILMER,
        .moves = {MOVE_WHIRLPOOL, MOVE_ROAR, MOVE_DEFENSE_CURL, MOVE_ROLLOUT    },
        .itemTableId = BATTLE_FRONTIER_ITEM_LAX_INCENSE,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_DEFENSE,
        .nature = NATURE_DOCILE,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_ROSELIA_1] = {
        .species = SPECIES_ROSERADE,
        .moves = {MOVE_SLUDGE_BOMB, MOVE_GIGA_DRAIN, MOVE_HIDDEN_POWER, MOVE_SYNTHESIS},
        .itemTableId = BATTLE_FRONTIER_ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_SP_ATTACK,
        .nature = NATURE_TIMID,
        .abilitynum = ABILITY_HIDDEN
    },
    [FRONTIER_MON_VOLBEAT_1] = {
        .species = SPECIES_VOLBEAT,
        .moves = {MOVE_SILVER_WIND, MOVE_CONFUSE_RAY, MOVE_QUICK_ATTACK, MOVE_HELPING_HAND    },
        .itemTableId = BATTLE_FRONTIER_ITEM_LIECHI_BERRY,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_QUIRKY,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_ILLUMISE_1] = {
        .species = SPECIES_ILLUMISE,
        .moves = {MOVE_SILVER_WIND, MOVE_WISH, MOVE_QUICK_ATTACK, MOVE_HELPING_HAND    },
        .itemTableId = BATTLE_FRONTIER_ITEM_LIECHI_BERRY,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_QUIRKY,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_IVYSAUR_1] = {
        .species = SPECIES_IVYSAUR,
        .moves = {MOVE_PETAL_DANCE, MOVE_GROWTH, MOVE_SWEET_SCENT, MOVE_FURY_CUTTER    },
        .itemTableId = BATTLE_FRONTIER_ITEM_PERSIM_BERRY,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_GENTLE,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_CHARMELEON_1] = {
        .species = SPECIES_CHARMELEON,
        .moves = {MOVE_SLASH, MOVE_FIRE_SPIN, MOVE_SWORDS_DANCE, MOVE_AERIAL_ACE    },
        .itemTableId = BATTLE_FRONTIER_ITEM_SCOPE_LENS,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_NAUGHTY,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_WARTORTLE_1] = {
        .species = SPECIES_WARTORTLE,
        .moves = {MOVE_WATER_PULSE, MOVE_BITE, MOVE_MUD_SLAP, MOVE_YAWN    },
        .itemTableId = BATTLE_FRONTIER_ITEM_FOCUS_BAND,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_DOCILE,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_PARASECT_1] = {
        .species = SPECIES_PARASECT,
        .moves = {MOVE_SLASH, MOVE_PSYBEAM, MOVE_STUN_SPORE, MOVE_FLASH    },
        .itemTableId = BATTLE_FRONTIER_ITEM_SITRUS_BERRY,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_DEFENSE,
        .nature = NATURE_RASH,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_MACHOKE_1] = {
        .species = SPECIES_MACHOKE,
        .moves = {MOVE_LOW_KICK, MOVE_ROCK_TOMB, MOVE_FORESIGHT, MOVE_SCARY_FACE    },
        .itemTableId = BATTLE_FRONTIER_ITEM_FOCUS_BAND,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_HAUNTER_1] = {
        .species = SPECIES_HAUNTER,
        .moves = {MOVE_SHADOW_BALL, MOVE_SLUDGE_BOMB, MOVE_PSYCHIC, MOVE_CURSE},
        .itemTableId = BATTLE_FRONTIER_ITEM_EVIOLITE,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_BAYLEEF_1] = {
        .species = SPECIES_BAYLEEF,
        .moves = {MOVE_RAZOR_LEAF, MOVE_TOXIC, MOVE_SAFEGUARD, MOVE_LIGHT_SCREEN    },
        .itemTableId = BATTLE_FRONTIER_ITEM_BRIGHT_POWDER,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_DOCILE,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_QUILAVA_1] = {
        .species = SPECIES_QUILAVA,
        .moves = {MOVE_FLAME_WHEEL, MOVE_FURY_SWIPES, MOVE_SWIFT, MOVE_SMOKESCREEN    },
        .itemTableId = BATTLE_FRONTIER_ITEM_FOCUS_BAND,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_DOCILE,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_CROCONAW_1] = {
        .species = SPECIES_CROCONAW,
        .moves = {MOVE_SLASH, MOVE_WATER_PULSE, MOVE_BITE, MOVE_SCARY_FACE    },
        .itemTableId = BATTLE_FRONTIER_ITEM_SCOPE_LENS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_ATTACK,
        .nature = NATURE_DOCILE,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_TOGETIC_1] = {
        .species = SPECIES_TOGETIC,
        .moves = {MOVE_AERIAL_ACE, MOVE_MAGICAL_LEAF, MOVE_WISH, MOVE_FOLLOW_ME    },
        .itemTableId = BATTLE_FRONTIER_ITEM_LAX_INCENSE,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_RELAXED,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_MURKROW_1] = {
        .species = SPECIES_MURKROW,
        .moves = {MOVE_FAINT_ATTACK, MOVE_FLY, MOVE_TORMENT, MOVE_TAUNT    },
        .itemTableId = BATTLE_FRONTIER_ITEM_LAX_INCENSE,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_QUIRKY,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_WOBBUFFET_1] = {
        .species = SPECIES_WOBBUFFET,
        .moves = {MOVE_COUNTER, MOVE_MIRROR_COAT, MOVE_CHARM, MOVE_SAFEGUARD    },
        .itemTableId = BATTLE_FRONTIER_ITEM_FOCUS_BAND,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_CAREFUL,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_PLUSLE_1] = {
        .species = SPECIES_PLUSLE,
        .moves = {MOVE_SPARK, MOVE_FAKE_TEARS, MOVE_QUICK_ATTACK, MOVE_HELPING_HAND    },
        .itemTableId = BATTLE_FRONTIER_ITEM_PETAYA_BERRY,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_DOCILE,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_MINUN_1] = {
        .species = SPECIES_MINUN,
        .moves = {MOVE_SPARK, MOVE_CHARM, MOVE_ENCORE, MOVE_HELPING_HAND    },
        .itemTableId = BATTLE_FRONTIER_ITEM_SALAC_BERRY,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_DOCILE,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_GROVYLE_1] = {
        .species = SPECIES_GROVYLE,
        .moves = {MOVE_FURY_CUTTER, MOVE_ENDEAVOR, MOVE_BRICK_BREAK, MOVE_DOUBLE_TEAM    },
        .itemTableId = BATTLE_FRONTIER_ITEM_BRIGHT_POWDER,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_RELAXED,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_COMBUSKEN_1] = {
        .species = SPECIES_COMBUSKEN,
        .moves = {MOVE_EMBER, MOVE_DOUBLE_KICK, MOVE_QUICK_ATTACK, MOVE_SAND_ATTACK    },
        .itemTableId = BATTLE_FRONTIER_ITEM_SCOPE_LENS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_ATTACK,
        .nature = NATURE_DOCILE,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_MARSHTOMP_1] = {
        .species = SPECIES_MARSHTOMP,
        .moves = {MOVE_MUD_SHOT, MOVE_WATER_GUN, MOVE_ROCK_TOMB, MOVE_MUD_SLAP    },
        .itemTableId = BATTLE_FRONTIER_ITEM_FOCUS_BAND,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_ATTACK,
        .nature = NATURE_HARDY,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_PONYTA_1] = {
        .species = SPECIES_PONYTA,
        .moves = {MOVE_FIRE_SPIN, MOVE_BOUNCE, MOVE_QUICK_ATTACK, MOVE_TAIL_WHIP    },
        .itemTableId = BATTLE_FRONTIER_ITEM_RAWST_BERRY,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_HARDY,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_AZUMARILL_1] = {
        .species = SPECIES_AZUMARILL,
        .moves = {MOVE_LIQUIDATION, MOVE_PLAY_ROUGH, MOVE_ICE_PUNCH, MOVE_AQUA_JET},
        .itemTableId = BATTLE_FRONTIER_ITEM_ASSAULT_VEST,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
		.abilitynum = ABILITY_2
    },
    [FRONTIER_MON_SUDOWOODO_1] = {
        .species = SPECIES_SUDOWOODO,
        .moves = {MOVE_HEAD_SMASH, MOVE_EARTHQUAKE, MOVE_SUCKER_PUNCH, MOVE_WOOD_HAMMER},
        .itemTableId = BATTLE_FRONTIER_ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_ADAMANT,
		.abilitynum = ABILITY_2
    },
    [FRONTIER_MON_MAGCARGO_1] = {
        .species = SPECIES_MAGCARGO,
        .moves = {MOVE_ROCK_SLIDE, MOVE_EMBER, MOVE_ACID_ARMOR, MOVE_SANDSTORM    },
        .itemTableId = BATTLE_FRONTIER_ITEM_LAX_INCENSE,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_GENTLE,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_PUPITAR_1] = {
        .species = SPECIES_PUPITAR,
        .moves = {MOVE_DIG, MOVE_BITE, MOVE_SCARY_FACE, MOVE_SANDSTORM    },
        .itemTableId = BATTLE_FRONTIER_ITEM_SOFT_SAND,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_HP,
        .nature = NATURE_HARDY,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_SEALEO_1] = {
        .species = SPECIES_SEALEO,
        .moves = {MOVE_ICE_BALL, MOVE_HAIL, MOVE_SNORE, MOVE_REST    },
        .itemTableId = BATTLE_FRONTIER_ITEM_PERSIM_BERRY,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_QUIRKY,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_RATICATE_1] = {
        .species = SPECIES_RATICATE,
        .moves = {MOVE_SWORDS_DANCE, MOVE_CRUNCH, MOVE_SUPER_FANG, MOVE_RETURN},
        .itemTableId = BATTLE_FRONTIER_ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_MASQUERAIN_1] = {
        .species = SPECIES_MASQUERAIN,
        .moves = {MOVE_SILVER_WIND, MOVE_AERIAL_ACE, MOVE_ICY_WIND, MOVE_STUN_SPORE    },
        .itemTableId = BATTLE_FRONTIER_ITEM_CHERI_BERRY,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_ATTACK,
        .nature = NATURE_RELAXED,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_FURRET_1] = {
        .species = SPECIES_FURRET,
        .moves = {MOVE_SLAM, MOVE_PROTECT, MOVE_HELPING_HAND, MOVE_FOLLOW_ME    },
        .itemTableId = BATTLE_FRONTIER_ITEM_LIECHI_BERRY,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_DEFENSE,
        .nature = NATURE_SERIOUS,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_DUNSPARCE_1] = {
        .species = SPECIES_DUNSPARCE,
        .moves = {MOVE_HEADBUTT, MOVE_GLARE, MOVE_DEFENSE_CURL, MOVE_ROLLOUT    },
        .itemTableId = BATTLE_FRONTIER_ITEM_LAX_INCENSE,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_DOCILE,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_DRAGONAIR_1] = {
        .species = SPECIES_DRAGONAIR,
        .moves = {MOVE_DRAGON_BREATH, MOVE_LEER, MOVE_WRAP, MOVE_SAFEGUARD    },
        .itemTableId = BATTLE_FRONTIER_ITEM_CHERI_BERRY,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_DOCILE,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_MIGHTYENA_1] = {
        .species = SPECIES_MIGHTYENA,
        .moves = {MOVE_BITE, MOVE_POISON_FANG, MOVE_TAUNT, MOVE_ROAR    },
        .itemTableId = BATTLE_FRONTIER_ITEM_MENTAL_HERB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_ATTACK,
        .nature = NATURE_TIMID,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_LINOONE_1] = {
        .species = SPECIES_LINOONE,
        .moves = {MOVE_SECRET_POWER, MOVE_SAND_ATTACK, MOVE_COVET, MOVE_TICKLE    },
        .itemTableId = BATTLE_FRONTIER_ITEM_WHITE_HERB,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_CASTFORM_1] = {
        .species = SPECIES_CASTFORM,
        .moves = {MOVE_EMBER, MOVE_WATER_PULSE, MOVE_SHOCK_WAVE, MOVE_ICY_WIND    },
        .itemTableId = BATTLE_FRONTIER_ITEM_PETAYA_BERRY,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_HASTY,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_SHELGON_1] = {
        .species = SPECIES_SHELGON,
        .moves = {MOVE_HEADBUTT, MOVE_DRAGON_BREATH, MOVE_PROTECT, MOVE_SCARY_FACE    },
        .itemTableId = BATTLE_FRONTIER_ITEM_CHERI_BERRY,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_HARDY,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_METANG_1] = {
        .species = SPECIES_METANG,
        .moves = {MOVE_METAL_CLAW, MOVE_CONFUSION, MOVE_PURSUIT, MOVE_SCARY_FACE    },
        .itemTableId = BATTLE_FRONTIER_ITEM_FOCUS_BAND,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_ATTACK,
        .nature = NATURE_HARDY,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_WIGGLYTUFF_1] = {
        .species = SPECIES_WIGGLYTUFF,
        .moves = {MOVE_SING, MOVE_DISABLE, MOVE_WISH, MOVE_SECRET_POWER    },
        .itemTableId = BATTLE_FRONTIER_ITEM_SILK_SCARF,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_DEFENSE,
        .nature = NATURE_RELAXED,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_SUNFLORA_1] = {
        .species = SPECIES_SUNFLORA,
        .moves = {MOVE_PETAL_DANCE, MOVE_INGRAIN, MOVE_LEECH_SEED, MOVE_LIGHT_SCREEN    },
        .itemTableId = BATTLE_FRONTIER_ITEM_PERSIM_BERRY,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_QUIRKY,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_CHIMECHO_1] = {
        .species = SPECIES_CHIMECHO,
        .moves = {MOVE_PSYWAVE, MOVE_TAKE_DOWN, MOVE_HEAL_BELL, MOVE_SAFEGUARD    },
        .itemTableId = BATTLE_FRONTIER_ITEM_TWISTED_SPOON,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_SASSY,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_GLIGAR_1] = {
        .species = SPECIES_GLIGAR,
        .moves = {MOVE_METAL_CLAW, MOVE_DIG, MOVE_AERIAL_ACE, MOVE_QUICK_ATTACK    },
        .itemTableId = BATTLE_FRONTIER_ITEM_SCOPE_LENS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_HASTY,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_QWILFISH_1] = {
        .species = SPECIES_QWILFISH,
        .moves = {MOVE_BUBBLE_BEAM, MOVE_PIN_MISSILE, MOVE_SPIKES, MOVE_MINIMIZE    },
        .itemTableId = BATTLE_FRONTIER_ITEM_CHERI_BERRY,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_SP_ATTACK,
        .nature = NATURE_IMPISH,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_SNEASEL_1] = {
        .species = SPECIES_SNEASEL,
        .moves = {MOVE_FAINT_ATTACK, MOVE_FAKE_OUT, MOVE_ICY_WIND, MOVE_QUICK_ATTACK    },
        .itemTableId = BATTLE_FRONTIER_ITEM_PERSIM_BERRY,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_RELAXED,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_PELIPPER_1] = {
        .species = SPECIES_PELIPPER,
        .moves = {MOVE_WATER_PULSE, MOVE_AERIAL_ACE, MOVE_STOCKPILE, MOVE_SWALLOW    },
        .itemTableId = BATTLE_FRONTIER_ITEM_SITRUS_BERRY,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_QUIET,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_SWELLOW_1] = {
        .species = SPECIES_SWELLOW,
        .moves = {MOVE_FLY, MOVE_ENDEAVOR, MOVE_FACADE, MOVE_QUICK_ATTACK    },
        .itemTableId = BATTLE_FRONTIER_ITEM_KINGS_ROCK,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_LAIRON_1] = {
        .species = SPECIES_LAIRON,
        .moves = {MOVE_METAL_CLAW, MOVE_ROCK_TOMB, MOVE_IRON_DEFENSE, MOVE_PROTECT    },
        .itemTableId = BATTLE_FRONTIER_ITEM_METAL_COAT,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_SASSY,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_TANGELA_1] = {
        .species = SPECIES_TANGELA,
        .moves = {MOVE_MEGA_DRAIN, MOVE_SLAM, MOVE_TOXIC, MOVE_BIND    },
        .itemTableId = BATTLE_FRONTIER_ITEM_LAX_INCENSE,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_HARDY,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_ARBOK_1] = {
        .species = SPECIES_ARBOK,
        .moves = {MOVE_POISON_FANG, MOVE_DIG, MOVE_BITE, MOVE_GLARE    },
        .itemTableId = BATTLE_FRONTIER_ITEM_PERSIM_BERRY,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_PERSIAN_1] = {
        .species = SPECIES_PERSIAN,
        .moves = {MOVE_FAKE_OUT, MOVE_SLASH, MOVE_TORMENT, MOVE_SWAGGER    },
        .itemTableId = BATTLE_FRONTIER_ITEM_SILK_SCARF,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_QUIRKY,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_SEADRA_1] = {
        .species = SPECIES_SEADRA,
        .moves = {MOVE_AURORA_BEAM, MOVE_SMOKESCREEN, MOVE_WATER_GUN, MOVE_RAIN_DANCE    },
        .itemTableId = BATTLE_FRONTIER_ITEM_MYSTIC_WATER,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_SASSY,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_KECLEON_1] = {
        .species = SPECIES_KECLEON,
        .moves = {MOVE_SECRET_POWER, MOVE_PSYBEAM, MOVE_MAGIC_COAT, MOVE_SEISMIC_TOSS    },
        .itemTableId = BATTLE_FRONTIER_ITEM_FOCUS_BAND,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_NAIVE,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_VIGOROTH_1] = {
        .species = SPECIES_VIGOROTH,
        .moves = {MOVE_SLASH, MOVE_COUNTER, MOVE_ENCORE, MOVE_UPROAR    },
        .itemTableId = BATTLE_FRONTIER_ITEM_FOCUS_BAND,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_LONELY,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_LUNATONE_1] = {
        .species = SPECIES_LUNATONE,
        .moves = {MOVE_CONFUSION, MOVE_COSMIC_POWER, MOVE_LIGHT_SCREEN, MOVE_SANDSTORM    },
        .itemTableId = BATTLE_FRONTIER_ITEM_SITRUS_BERRY,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_QUIET,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_SOLROCK_1] = {
        .species = SPECIES_SOLROCK,
        .moves = {MOVE_CONFUSION, MOVE_FIRE_SPIN, MOVE_LIGHT_SCREEN, MOVE_SANDSTORM    },
        .itemTableId = BATTLE_FRONTIER_ITEM_SITRUS_BERRY,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_QUIET,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_NOCTOWL_1] = {
        .species = SPECIES_QWILFISH_HUSIAN,
        .moves = {MOVE_CRUNCH, MOVE_POISON_JAB, MOVE_LIQUIDATION, MOVE_TOXIC_SPIKES    },
        .itemTableId = BATTLE_FRONTIER_ITEM_EVIOLITE,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_RELAXED,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_SANDSLASH_1] = {
        .species = SPECIES_SANDSLASH,
        .moves = {MOVE_CRUSH_CLAW, MOVE_ROCK_SLIDE, MOVE_SWIFT, MOVE_SANDSTORM    },
        .itemTableId = BATTLE_FRONTIER_ITEM_SITRUS_BERRY,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_VENOMOTH_1] = {
        .species = SPECIES_VENOMOTH,
        .moves = {MOVE_SILVER_WIND, MOVE_PSYBEAM, MOVE_SLEEP_POWDER, MOVE_SKILL_SWAP    },
        .itemTableId = BATTLE_FRONTIER_ITEM_PERSIM_BERRY,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_HP,
        .nature = NATURE_QUIRKY,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_CHANSEY_1] = {
        .species = SPECIES_CHANSEY,
        .moves = {MOVE_METRONOME, MOVE_REFRESH, MOVE_DEFENSE_CURL, MOVE_MINIMIZE    },
        .itemTableId = BATTLE_FRONTIER_ITEM_EVIOLITE,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_DEFENSE,
        .nature = NATURE_RELAXED,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_SEAKING_1] = {
        .species = SPECIES_SEAKING,
        .moves = {MOVE_WATER_PULSE, MOVE_PSYBEAM, MOVE_SWIFT, MOVE_AGILITY    },
        .itemTableId = BATTLE_FRONTIER_ITEM_SITRUS_BERRY,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_DOCILE,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_JUMPLUFF_1] = {
        .species = SPECIES_JUMPLUFF,
        .moves = {MOVE_AERIAL_ACE, MOVE_SWAGGER, MOVE_PSYCH_UP, MOVE_SYNTHESIS    },
        .itemTableId = BATTLE_FRONTIER_ITEM_LAX_INCENSE,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_HP,
        .nature = NATURE_DOCILE,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_PILOSWINE_1] = {
        .species = SPECIES_PILOSWINE,
        .moves = {MOVE_DIG, MOVE_ANCIENT_POWER, MOVE_HAIL, MOVE_LIGHT_SCREEN    },
        .itemTableId = BATTLE_FRONTIER_ITEM_SOFT_SAND,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_QUIRKY,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_GOLBAT_1] = {
        .species = SPECIES_GOLBAT,
        .moves = {MOVE_AIR_CUTTER, MOVE_CONFUSE_RAY, MOVE_TOXIC, MOVE_STEEL_WING    },
        .itemTableId = BATTLE_FRONTIER_ITEM_SCOPE_LENS,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_RELAXED,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_PRIMEAPE_1] = {
        .species = SPECIES_PRIMEAPE,
        .moves = {MOVE_KARATE_CHOP, MOVE_COUNTER, MOVE_SWAGGER, MOVE_SCREECH    },
        .itemTableId = BATTLE_FRONTIER_ITEM_SCOPE_LENS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_QUIRKY,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_HITMONLEE_1] = {
        .species = SPECIES_HITMONLEE,
        .moves = {MOVE_ROLLING_KICK, MOVE_BRICK_BREAK, MOVE_FOCUS_ENERGY, MOVE_FACADE    },
        .itemTableId = BATTLE_FRONTIER_ITEM_BLACK_BELT,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_HITMONCHAN_1] = {
        .species = SPECIES_HITMONCHAN,
        .moves = {MOVE_MACH_PUNCH, MOVE_SKY_UPPERCUT, MOVE_DETECT, MOVE_COUNTER    },
        .itemTableId = BATTLE_FRONTIER_ITEM_KINGS_ROCK,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_GIRAFARIG_1] = {
        .species = SPECIES_GIRAFARIG,
        .moves = {MOVE_PSYBEAM, MOVE_STOMP, MOVE_WISH, MOVE_SKILL_SWAP    },
        .itemTableId = BATTLE_FRONTIER_ITEM_PETAYA_BERRY,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_QUIET,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_HITMONTOP_1] = {
        .species = SPECIES_HITMONTOP,
        .moves = {MOVE_TRIPLE_KICK, MOVE_DIG, MOVE_MACH_PUNCH, MOVE_QUICK_ATTACK    },
        .itemTableId = BATTLE_FRONTIER_ITEM_LIECHI_BERRY,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_HARDY,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_BANETTE_1] = {
        .species = SPECIES_BANETTE,
        .moves = {MOVE_NIGHT_SHADE, MOVE_WILL_O_WISP, MOVE_SPITE, MOVE_KNOCK_OFF    },
        .itemTableId = BATTLE_FRONTIER_ITEM_RAWST_BERRY,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_SASSY,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_NINJASK_1] = {
        .species = SPECIES_NINJASK,
        .moves = {MOVE_BATON_PASS, MOVE_SWORDS_DANCE, MOVE_ENDURE, MOVE_DIG    },
        .itemTableId = BATTLE_FRONTIER_ITEM_PETAYA_BERRY,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_MILD,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_SEVIPER_1] = {
        .species = SPECIES_SEVIPER,
        .moves = {MOVE_POISON_TAIL, MOVE_BITE, MOVE_GLARE, MOVE_SCREECH    },
        .itemTableId = BATTLE_FRONTIER_ITEM_SCOPE_LENS,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_HARDY,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_ZANGOOSE_1] = {
        .species = SPECIES_ZANGOOSE,
        .moves = {MOVE_SLASH, MOVE_DOUBLE_KICK, MOVE_ROAR, MOVE_QUICK_ATTACK    },
        .itemTableId = BATTLE_FRONTIER_ITEM_PERSIM_BERRY,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_HARDY,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_CAMERUPT_1] = {
        .species = SPECIES_CAMERUPT,
        .moves = {MOVE_EARTH_POWER, MOVE_FIRE_BLAST, MOVE_SOLAR_BEAM, MOVE_SLACK_OFF    },
        .itemTableId = BATTLE_FRONTIER_ITEM_CAMERUPTITE,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_QUIRKY,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_SHARPEDO_1] = {
        .species = SPECIES_SHARPEDO,
        .moves = {MOVE_WATERFALL, MOVE_CRUNCH, MOVE_PSYCHIC_FANGS, MOVE_ICE_FANG    },
        .itemTableId = BATTLE_FRONTIER_ITEM_SHARPEDONITE,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_TROPIUS_1] = {
        .species = SPECIES_TROPIUS,
        .moves = {MOVE_MAGICAL_LEAF, MOVE_WHIRLWIND, MOVE_AERIAL_ACE, MOVE_STEEL_WING    },
        .itemTableId = BATTLE_FRONTIER_ITEM_SITRUS_BERRY,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_HARDY,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_MAGNETON_1] = {
        .species = SPECIES_MAGNEZONE,
        .moves = {MOVE_THUNDERBOLT, MOVE_FLASH_CANNON, MOVE_TRI_ATTACK, MOVE_HIDDEN_POWER},
        .itemTableId = BATTLE_FRONTIER_ITEM_CHERI_BERRY,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_LONELY,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_MANTINE_1] = {
        .species = SPECIES_MANTINE,
        .moves = {MOVE_BUBBLE_BEAM, MOVE_AERIAL_ACE, MOVE_RAIN_DANCE, MOVE_ICY_WIND    },
        .itemTableId = BATTLE_FRONTIER_ITEM_MYSTIC_WATER,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_DOCILE,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_STANTLER_1] = {
        .species = SPECIES_STANTLER,
        .moves = {MOVE_EXTRASENSORY, MOVE_CONFUSE_RAY, MOVE_STOMP, MOVE_SAND_ATTACK    },
        .itemTableId = BATTLE_FRONTIER_ITEM_TWISTED_SPOON,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_GENTLE,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_ABSOL_1] = {
        .species = SPECIES_ABSOL,
        .moves = {MOVE_BITE, MOVE_RAZOR_WIND, MOVE_FUTURE_SIGHT, MOVE_QUICK_ATTACK    },
        .itemTableId = BATTLE_FRONTIER_ITEM_BRIGHT_POWDER,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_SWALOT_1] = {
        .species = SPECIES_SWALOT,
        .moves = {MOVE_STOCKPILE, MOVE_SWALLOW, MOVE_SPIT_UP, MOVE_SLUDGE    },
        .itemTableId = BATTLE_FRONTIER_ITEM_LAX_INCENSE,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_DEFENSE,
        .nature = NATURE_QUIRKY,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_CRAWDAUNT_1] = {
        .species = SPECIES_CRAWDAUNT,
        .moves = {MOVE_BUBBLE_BEAM, MOVE_VICE_GRIP, MOVE_KNOCK_OFF, MOVE_PROTECT    },
        .itemTableId = BATTLE_FRONTIER_ITEM_PERSIM_BERRY,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_PIDGEOT_1] = {
        .species = SPECIES_PIDGEOT,//MEGA
        .moves = {MOVE_HURRICANE, MOVE_HEAT_WAVE, MOVE_ROOST, MOVE_HYPER_VOICE},
        .itemTableId = BATTLE_FRONTIER_ITEM_PIDGEOTITE,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .abilitynum = ABILITY_1
    },
    [FRONTIER_MON_GRUMPIG_1] = {
        .species = SPECIES_GRUMPIG,
        .moves = {MOVE_PSYBEAM, MOVE_CONFUSE_RAY, MOVE_FUTURE_SIGHT, MOVE_MAGIC_COAT    },
        .itemTableId = BATTLE_FRONTIER_ITEM_PETAYA_BERRY,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_RELAXED,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_TORKOAL_1] = {
        .species = SPECIES_TORKOAL,
        .moves = {MOVE_EMBER, MOVE_FIRE_SPIN, MOVE_SMOKESCREEN, MOVE_AMNESIA    },
        .itemTableId = BATTLE_FRONTIER_ITEM_SITRUS_BERRY,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_RELAXED,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_KINGLER_1] = {
        .species = SPECIES_KINGLER,
        .moves = {MOVE_CRABHAMMER, MOVE_METAL_CLAW, MOVE_MUD_SHOT, MOVE_PROTECT    },
        .itemTableId = BATTLE_FRONTIER_ITEM_SCOPE_LENS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_HARDY,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_CACTURNE_1] = {
        .species = SPECIES_CACTURNE,
        .moves = {MOVE_NEEDLE_ARM, MOVE_FAINT_ATTACK, MOVE_ACID, MOVE_MEGA_PUNCH    },
        .itemTableId = BATTLE_FRONTIER_ITEM_SCOPE_LENS,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_HP,
        .nature = NATURE_HASTY,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_BELLOSSOM_1] = {
        .species = SPECIES_BELLOSSOM,
        .moves = {MOVE_PETAL_DANCE, MOVE_SAFEGUARD, MOVE_SUNNY_DAY, MOVE_SYNTHESIS    },
        .itemTableId = BATTLE_FRONTIER_ITEM_PERSIM_BERRY,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_QUIET,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_OCTILLERY_1] = {
        .species = SPECIES_OCTILLERY,
        .moves = {MOVE_OCTAZOOKA, MOVE_AURORA_BEAM, MOVE_PSYBEAM, MOVE_ROCK_BLAST    },
        .itemTableId = BATTLE_FRONTIER_ITEM_SHELL_BELL,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_ATTACK,
        .nature = NATURE_HARDY,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_HUNTAIL_1] = {
        .species = SPECIES_HUNTAIL,
        .moves = {MOVE_WHIRLPOOL, MOVE_SCARY_FACE, MOVE_MUD_SLAP, MOVE_BITE    },
        .itemTableId = BATTLE_FRONTIER_ITEM_PERSIM_BERRY,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_QUIET,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_GOREBYSS_1] = {
        .species = SPECIES_GOREBYSS,
        .moves = {MOVE_WHIRLPOOL, MOVE_AMNESIA, MOVE_ICY_WIND, MOVE_CONFUSION    },
        .itemTableId = BATTLE_FRONTIER_ITEM_PERSIM_BERRY,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_BRAVE,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_RELICANTH_1] = {
        .species = SPECIES_RELICANTH,
        .moves = {MOVE_ANCIENT_POWER, MOVE_WATER_PULSE, MOVE_HARDEN, MOVE_AMNESIA    },
        .itemTableId = BATTLE_FRONTIER_ITEM_LIECHI_BERRY,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_SASSY,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_OMASTAR_1] = {
        .species = SPECIES_OMASTAR,
        .moves = {MOVE_BUBBLE_BEAM, MOVE_SPIKE_CANNON, MOVE_TICKLE, MOVE_ANCIENT_POWER    },
        .itemTableId = BATTLE_FRONTIER_ITEM_SHELL_BELL,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_QUIRKY,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_KABUTOPS_1] = {
        .species = SPECIES_KABUTOPS,
        .moves = {MOVE_SLASH, MOVE_DIG, MOVE_FURY_CUTTER, MOVE_KNOCK_OFF    },
        .itemTableId = BATTLE_FRONTIER_ITEM_SCOPE_LENS,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_POLIWRATH_1] = {
        .species = SPECIES_POLIWRATH,
        .moves = {MOVE_SUBMISSION, MOVE_DIG, MOVE_ROCK_TOMB, MOVE_BUBBLE_BEAM    },
        .itemTableId = BATTLE_FRONTIER_ITEM_BLACK_BELT,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_SCYTHER_1] = {
        .species = SPECIES_SCYTHER,
        .moves = {MOVE_SWORDS_DANCE, MOVE_AERIAL_ACE, MOVE_BRICK_BREAK, MOVE_BUG_BITE},
        .itemTableId = BATTLE_FRONTIER_ITEM_EVIOLITE,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_JOLLY,
        .abilitynum = ABILITY_1
    },
    [FRONTIER_MON_PINSIR_1] = {
        .species = SPECIES_PINSIR,
        .moves = {MOVE_SUBMISSION, MOVE_FOCUS_ENERGY, MOVE_SWORDS_DANCE, MOVE_REVENGE    },
        .itemTableId = BATTLE_FRONTIER_ITEM_BLACK_BELT,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_NAUGHTY,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_POLITOED_1] = {
        .species = SPECIES_POLITOED,
        .moves = {MOVE_DIVE, MOVE_DIG, MOVE_HYPNOSIS, MOVE_SWAGGER    },
        .itemTableId = BATTLE_FRONTIER_ITEM_SHELL_BELL,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_DEFENSE,
        .nature = NATURE_RELAXED,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_CLOYSTER_1] = {
        .species = SPECIES_CLOYSTER,
        .moves = {MOVE_AURORA_BEAM, MOVE_SPIKE_CANNON, MOVE_SUPERSONIC, MOVE_PROTECT    },
        .itemTableId = BATTLE_FRONTIER_ITEM_NEVER_MELT_ICE,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_SASSY,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_DELCATTY_2] = {
        .species = SPECIES_DELCATTY,
        .moves = {MOVE_FAKE_TEARS, MOVE_SING, MOVE_THUNDERBOLT, MOVE_ICE_BEAM    },
        .itemTableId = BATTLE_FRONTIER_ITEM_QUICK_CLAW,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_SABLEYE_2] = {
        .species = SPECIES_SABLEYE,
        .moves = {MOVE_SHADOW_BALL, MOVE_FAINT_ATTACK, MOVE_CONFUSE_RAY, MOVE_RECOVER    },
        .itemTableId = BATTLE_FRONTIER_ITEM_LUM_BERRY,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_QUIRKY,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_LICKITUNG_2] = {
        .species = SPECIES_LICKITUNG,
        .moves = {MOVE_EARTHQUAKE, MOVE_BODY_SLAM, MOVE_SHADOW_BALL, MOVE_ROCK_SLIDE    },
        .itemTableId = BATTLE_FRONTIER_ITEM_CHERI_BERRY,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_DEFENSE | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_WEEPINBELL_2] = {
        .species = SPECIES_WEEPINBELL,
        .moves = {MOVE_SLUDGE_BOMB, MOVE_RAZOR_LEAF, MOVE_SLEEP_POWDER, MOVE_REFLECT    },
        .itemTableId = BATTLE_FRONTIER_ITEM_SCOPE_LENS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_DEFENSE,
        .nature = NATURE_QUIRKY,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_GRAVELER_2] = {
        .species = SPECIES_GRAVELER,
        .moves = {MOVE_EARTHQUAKE, MOVE_ROCK_SLIDE, MOVE_BRICK_BREAK, MOVE_COUNTER    },
        .itemTableId = BATTLE_FRONTIER_ITEM_FOCUS_BAND,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_GLOOM_2] = {
        .species = SPECIES_GLOOM,
        .moves = {MOVE_SOLAR_BEAM, MOVE_SUNNY_DAY, MOVE_SLUDGE_BOMB, MOVE_MOONLIGHT    },
        .itemTableId = BATTLE_FRONTIER_ITEM_PECHA_BERRY,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_ATTACK,
        .nature = NATURE_QUIRKY,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_PORYGON_2] = {
        .species = SPECIES_PORYGON_Z,//TO REMOVE
        .moves = {MOVE_TRI_ATTACK, MOVE_ICE_BEAM, MOVE_THUNDERBOLT, MOVE_RECOVER},
        .itemTableId = BATTLE_FRONTIER_ITEM_CHOICE_SCARF,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
		.abilitynum = ABILITY_1
    },
    [FRONTIER_MON_KADABRA_2] = {
        .species = SPECIES_KADABRA,
        .moves = {MOVE_PSYCHIC, MOVE_THUNDER_WAVE, MOVE_REFLECT, MOVE_RECOVER    },
        .itemTableId = BATTLE_FRONTIER_ITEM_TWISTED_SPOON,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_WAILMER_2] = {
        .species = SPECIES_WAILMER,
        .moves = {MOVE_WATER_SPOUT, MOVE_EARTHQUAKE, MOVE_BODY_SLAM, MOVE_REST    },
        .itemTableId = BATTLE_FRONTIER_ITEM_CHESTO_BERRY,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_DEFENSE,
        .nature = NATURE_DOCILE,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_ROSELIA_2] = {
        .species = SPECIES_ROSELIA,
        .moves = {MOVE_GIGA_DRAIN, MOVE_SLUDGE_BOMB, MOVE_GRASS_WHISTLE, MOVE_SYNTHESIS    },
        .itemTableId = BATTLE_FRONTIER_ITEM_QUICK_CLAW,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_DOCILE,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_VOLBEAT_2] = {
        .species = SPECIES_VOLBEAT,
        .moves = {MOVE_SIGNAL_BEAM, MOVE_THUNDERBOLT, MOVE_ICE_PUNCH, MOVE_TAIL_GLOW    },
        .itemTableId = BATTLE_FRONTIER_ITEM_PETAYA_BERRY,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_QUIRKY,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_ILLUMISE_2] = {
        .species = SPECIES_ILLUMISE,
        .moves = {MOVE_SILVER_WIND, MOVE_THUNDERBOLT, MOVE_ICE_PUNCH, MOVE_GIGA_DRAIN    },
        .itemTableId = BATTLE_FRONTIER_ITEM_PETAYA_BERRY,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_QUIRKY,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_IVYSAUR_2] = {
        .species = SPECIES_IVYSAUR,
        .moves = {MOVE_GIGA_DRAIN, MOVE_SLUDGE_BOMB, MOVE_SLEEP_POWDER, MOVE_LEECH_SEED    },
        .itemTableId = BATTLE_FRONTIER_ITEM_BRIGHT_POWDER,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_ATTACK,
        .nature = NATURE_QUIRKY,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_CHARMELEON_2] = {
        .species = SPECIES_CHARMELEON,
        .moves = {MOVE_FLAMETHROWER, MOVE_SLASH, MOVE_ANCIENT_POWER, MOVE_DRAGON_RAGE    },
        .itemTableId = BATTLE_FRONTIER_ITEM_SCOPE_LENS,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_HARDY,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_WARTORTLE_2] = {
        .species = SPECIES_WARTORTLE,
        .moves = {MOVE_SURF, MOVE_ICE_BEAM, MOVE_RAPID_SPIN, MOVE_PROTECT    },
        .itemTableId = BATTLE_FRONTIER_ITEM_SHELL_BELL,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_DOCILE,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_PARASECT_2] = {
        .species = SPECIES_PARASECT,
        .moves = {MOVE_SPORE, MOVE_GIGA_DRAIN, MOVE_DIG, MOVE_DOUBLE_TEAM    },
        .itemTableId = BATTLE_FRONTIER_ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_CALM,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_MACHOKE_2] = {
        .species = SPECIES_MACHOKE,
        .moves = {MOVE_CROSS_CHOP, MOVE_ROCK_SLIDE, MOVE_FORESIGHT, MOVE_SCARY_FACE    },
        .itemTableId = BATTLE_FRONTIER_ITEM_SCOPE_LENS,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_HAUNTER_2] = {
        .species = SPECIES_DOUBLADE,
        .moves = {MOVE_SWORDS_DANCE, MOVE_SHADOW_SNEAK, MOVE_SACRED_SWORD, MOVE_GYRO_BALL},
        .itemTableId = BATTLE_FRONTIER_ITEM_EVIOLITE,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
		.abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_BAYLEEF_2] = {
        .species = SPECIES_BAYLEEF,
        .moves = {MOVE_GIGA_DRAIN, MOVE_BODY_SLAM, MOVE_GRASS_WHISTLE, MOVE_REST    },
        .itemTableId = BATTLE_FRONTIER_ITEM_CHESTO_BERRY,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_DOCILE,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_QUILAVA_2] = {
        .species = SPECIES_QUILAVA,
        .moves = {MOVE_FLAMETHROWER, MOVE_CRUSH_CLAW, MOVE_BODY_SLAM, MOVE_SMOKESCREEN    },
        .itemTableId = BATTLE_FRONTIER_ITEM_BRIGHT_POWDER,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_ATTACK,
        .nature = NATURE_DOCILE,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_CROCONAW_2] = {
        .species = SPECIES_CROCONAW,
        .moves = {MOVE_MEGA_KICK, MOVE_AERIAL_ACE, MOVE_ROCK_SLIDE, MOVE_DIG    },
        .itemTableId = BATTLE_FRONTIER_ITEM_FOCUS_BAND,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_TOGETIC_2] = {
        .species = SPECIES_TOGETIC,
        .moves = {MOVE_RETURN, MOVE_SWEET_KISS, MOVE_AERIAL_ACE, MOVE_YAWN    },
        .itemTableId = BATTLE_FRONTIER_ITEM_SCOPE_LENS,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_RELAXED,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_MURKROW_2] = {
        .species = SPECIES_MURKROW,
        .moves = {MOVE_PERISH_SONG, MOVE_MEAN_LOOK, MOVE_DOUBLE_TEAM, MOVE_THUNDER_WAVE    },
        .itemTableId = BATTLE_FRONTIER_ITEM_BRIGHT_POWDER,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_QUIRKY,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_WOBBUFFET_2] = {
        .species = SPECIES_WOBBUFFET,
        .moves = {MOVE_COUNTER, MOVE_MIRROR_COAT, MOVE_ENCORE, MOVE_DESTINY_BOND    },
        .itemTableId = BATTLE_FRONTIER_ITEM_FOCUS_BAND,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_DEFENSE,
        .nature = NATURE_CAREFUL,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_PLUSLE_2] = {
        .species = SPECIES_PLUSLE,
        .moves = {MOVE_THUNDERBOLT, MOVE_THUNDER_WAVE, MOVE_SEISMIC_TOSS, MOVE_WISH    },
        .itemTableId = BATTLE_FRONTIER_ITEM_PETAYA_BERRY,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_DOCILE,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_MINUN_2] = {
        .species = SPECIES_MINUN,
        .moves = {MOVE_THUNDERBOLT, MOVE_ATTRACT, MOVE_CHARM, MOVE_WISH    },
        .itemTableId = BATTLE_FRONTIER_ITEM_SALAC_BERRY,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_DOCILE,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_GROVYLE_2] = {
        .species = SPECIES_GROVYLE,
        .moves = {MOVE_GIGA_DRAIN, MOVE_CRUSH_CLAW, MOVE_SCREECH, MOVE_ROCK_TOMB    },
        .itemTableId = BATTLE_FRONTIER_ITEM_LUM_BERRY,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_DOCILE,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_COMBUSKEN_2] = {
        .species = SPECIES_COMBUSKEN,
        .moves = {MOVE_FLAMETHROWER, MOVE_SKY_UPPERCUT, MOVE_SLASH, MOVE_SAND_ATTACK    },
        .itemTableId = BATTLE_FRONTIER_ITEM_SCOPE_LENS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_DOCILE,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_MARSHTOMP_2] = {
        .species = SPECIES_MARSHTOMP,
        .moves = {MOVE_MUDDY_WATER, MOVE_EARTHQUAKE, MOVE_MUD_SLAP, MOVE_PROTECT    },
        .itemTableId = BATTLE_FRONTIER_ITEM_FOCUS_BAND,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_ATTACK,
        .nature = NATURE_DOCILE,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_PONYTA_2] = {
        .species = SPECIES_PONYTA,
        .moves = {MOVE_FLAMETHROWER, MOVE_BODY_SLAM, MOVE_DOUBLE_KICK, MOVE_DOUBLE_TEAM    },
        .itemTableId = BATTLE_FRONTIER_ITEM_SITRUS_BERRY,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_QUIRKY,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_AZUMARILL_2] = {
        .species = SPECIES_AZUMARILL,//TO REMOVE
        .moves = {MOVE_LIQUIDATION, MOVE_PLAY_ROUGH, MOVE_ICE_PUNCH, MOVE_AQUA_JET},
        .itemTableId = BATTLE_FRONTIER_ITEM_ASSAULT_VEST,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
		.abilitynum = ABILITY_2
    },
    [FRONTIER_MON_SUDOWOODO_2] = {
        .species = SPECIES_SUDOWOODO,//TO REMOVE
        .moves = {MOVE_HEAD_SMASH, MOVE_EARTHQUAKE, MOVE_SUCKER_PUNCH, MOVE_WOOD_HAMMER},
        .itemTableId = BATTLE_FRONTIER_ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_ADAMANT,
		.abilitynum = ABILITY_2
    },
    [FRONTIER_MON_MAGCARGO_2] = {
        .species = SPECIES_MAGCARGO,
        .moves = {MOVE_OVERHEAT, MOVE_EARTHQUAKE, MOVE_ROCK_SLIDE, MOVE_BODY_SLAM    },
        .itemTableId = BATTLE_FRONTIER_ITEM_QUICK_CLAW,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_QUIET,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_PUPITAR_2] = {
        .species = SPECIES_PUPITAR,
        .moves = {MOVE_EARTHQUAKE, MOVE_ROCK_SLIDE, MOVE_CRUNCH, MOVE_SCARY_FACE    },
        .itemTableId = BATTLE_FRONTIER_ITEM_SCOPE_LENS,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_HARDY,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_SEALEO_2] = {
        .species = SPECIES_SEALEO,
        .moves = {MOVE_ICE_BEAM, MOVE_SURF, MOVE_BODY_SLAM, MOVE_HAIL    },
        .itemTableId = BATTLE_FRONTIER_ITEM_SITRUS_BERRY,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_QUIET,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_RATICATE_2] = {
        .species = SPECIES_RATICATE_ALOLAN,
        .moves = {MOVE_SWORDS_DANCE, MOVE_CRUNCH, MOVE_SUCKER_PUNCH, MOVE_FRUSTRATION},
        .itemTableId = BATTLE_FRONTIER_ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_MASQUERAIN_2] = {
        .species = SPECIES_MASQUERAIN,
        .moves = {MOVE_HYDRO_PUMP, MOVE_ICE_BEAM, MOVE_GIGA_DRAIN, MOVE_STUN_SPORE    },
        .itemTableId = BATTLE_FRONTIER_ITEM_LAX_INCENSE,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_DEFENSE,
        .nature = NATURE_QUIET,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_FURRET_2] = {
        .species = SPECIES_FURRET,
        .moves = {MOVE_TRICK, MOVE_FRUSTRATION, MOVE_SHADOW_BALL, MOVE_FOLLOW_ME    },
        .itemTableId = BATTLE_FRONTIER_ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_DUNSPARCE_2] = {
        .species = SPECIES_DUNSPARCE,
        .moves = {MOVE_ICE_BEAM, MOVE_ROCK_TOMB, MOVE_BITE, MOVE_SHADOW_BALL    },
        .itemTableId = BATTLE_FRONTIER_ITEM_LAX_INCENSE,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_DEFENSE,
        .nature = NATURE_QUIET,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_DRAGONAIR_2] = {
        .species = SPECIES_DRAGONAIR,
        .moves = {MOVE_RETURN, MOVE_REST, MOVE_THUNDER_WAVE, MOVE_DRAGON_DANCE    },
        .itemTableId = BATTLE_FRONTIER_ITEM_CHESTO_BERRY,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_MIGHTYENA_2] = {
        .species = SPECIES_MIGHTYENA,
        .moves = {MOVE_CRUNCH, MOVE_SHADOW_BALL, MOVE_FRUSTRATION, MOVE_SCARY_FACE    },
        .itemTableId = BATTLE_FRONTIER_ITEM_KINGS_ROCK,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_DEFENSE,
        .nature = NATURE_QUIRKY,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_LINOONE_2] = {
        .species = SPECIES_LINOONE,
        .moves = {MOVE_TRICK, MOVE_FRUSTRATION, MOVE_THUNDER_WAVE, MOVE_SAND_ATTACK    },
        .itemTableId = BATTLE_FRONTIER_ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_CASTFORM_2] = {
        .species = SPECIES_CASTFORM,
        .moves = {MOVE_THUNDERBOLT, MOVE_FLAMETHROWER, MOVE_ICE_BEAM, MOVE_WATER_PULSE    },
        .itemTableId = BATTLE_FRONTIER_ITEM_LAX_INCENSE,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_SHELGON_2] = {
        .species = SPECIES_SHELGON,
        .moves = {MOVE_FRUSTRATION, MOVE_DRAGON_DANCE, MOVE_CRUNCH, MOVE_SCARY_FACE    },
        .itemTableId = BATTLE_FRONTIER_ITEM_FOCUS_BAND,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_HARDY,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_METANG_2] = {
        .species = SPECIES_METANG,
        .moves = {MOVE_METEOR_MASH, MOVE_PSYCHIC, MOVE_BODY_SLAM, MOVE_SCARY_FACE    },
        .itemTableId = BATTLE_FRONTIER_ITEM_FOCUS_BAND,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_QUIRKY,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_WIGGLYTUFF_2] = {
        .species = SPECIES_WIGGLYTUFF,
        .moves = {MOVE_FAKE_TEARS, MOVE_SING, MOVE_DREAM_EATER, MOVE_BRICK_BREAK    },
        .itemTableId = BATTLE_FRONTIER_ITEM_SITRUS_BERRY,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_DEFENSE,
        .nature = NATURE_DOCILE,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_SUNFLORA_2] = {
        .species = SPECIES_SUNFLORA,
        .moves = {MOVE_GIGA_DRAIN, MOVE_GRASS_WHISTLE, MOVE_GROWTH, MOVE_DOUBLE_TEAM    },
        .itemTableId = BATTLE_FRONTIER_ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_QUIET,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_CHIMECHO_2] = {
        .species = SPECIES_CHIMECHO,
        .moves = {MOVE_PSYCHIC, MOVE_HYPNOSIS, MOVE_DREAM_EATER, MOVE_HEAL_BELL    },
        .itemTableId = BATTLE_FRONTIER_ITEM_TWISTED_SPOON,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_QUIET,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_GLIGAR_2] = {
        .species = SPECIES_GLIGAR,
        .moves = {MOVE_EARTHQUAKE, MOVE_AERIAL_ACE, MOVE_GUILLOTINE, MOVE_SCREECH    },
        .itemTableId = BATTLE_FRONTIER_ITEM_QUICK_CLAW,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_QWILFISH_2] = {
        .species = SPECIES_QWILFISH,
        .moves = {MOVE_REVENGE, MOVE_SLUDGE_BOMB, MOVE_SHADOW_BALL, MOVE_DESTINY_BOND    },
        .itemTableId = BATTLE_FRONTIER_ITEM_FOCUS_BAND,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_SNEASEL_2] = {
        .species = SPECIES_SNEASEL,
        .moves = {MOVE_CRUSH_CLAW, MOVE_BRICK_BREAK, MOVE_AERIAL_ACE, MOVE_SCREECH    },
        .itemTableId = BATTLE_FRONTIER_ITEM_KINGS_ROCK,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_JOLLY,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_PELIPPER_2] = {
        .species = SPECIES_PELIPPER,
        .moves = {MOVE_SURF, MOVE_BLIZZARD, MOVE_AERIAL_ACE, MOVE_PROTECT    },
        .itemTableId = BATTLE_FRONTIER_ITEM_SHELL_BELL,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_QUIET,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_SWELLOW_2] = {
        .species = SPECIES_SWELLOW,
        .moves = {MOVE_FACADE, MOVE_AERIAL_ACE, MOVE_PURSUIT, MOVE_DOUBLE_TEAM    },
        .itemTableId = BATTLE_FRONTIER_ITEM_KINGS_ROCK,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_LAIRON_2] = {
        .species = SPECIES_LAIRON,
        .moves = {MOVE_EARTHQUAKE, MOVE_IRON_TAIL, MOVE_ROAR, MOVE_PROTECT    },
        .itemTableId = BATTLE_FRONTIER_ITEM_SITRUS_BERRY,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_SASSY,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_TANGELA_2] = {
        .species = SPECIES_TANGELA,
        .moves = {MOVE_GIGA_DRAIN, MOVE_STUN_SPORE, MOVE_REST, MOVE_AMNESIA    },
        .itemTableId = BATTLE_FRONTIER_ITEM_CHESTO_BERRY,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_CALM,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_ARBOK_2] = {
        .species = SPECIES_ARBOK,
        .moves = {MOVE_SLUDGE_BOMB, MOVE_EARTHQUAKE, MOVE_IRON_TAIL, MOVE_GLARE    },
        .itemTableId = BATTLE_FRONTIER_ITEM_LUM_BERRY,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_PERSIAN_2] = {
        .species = SPECIES_PERSIAN,
        .moves = {MOVE_FRUSTRATION, MOVE_SHADOW_BALL, MOVE_ROAR, MOVE_FAKE_OUT    },
        .itemTableId = BATTLE_FRONTIER_ITEM_SILK_SCARF,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_QUIRKY,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_SEADRA_2] = {
        .species = SPECIES_SEADRA,
        .moves = {MOVE_HYDRO_PUMP, MOVE_FRUSTRATION, MOVE_DRAGON_BREATH, MOVE_DRAGON_DANCE    },
        .itemTableId = BATTLE_FRONTIER_ITEM_SHELL_BELL,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_DOCILE,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_KECLEON_2] = {
        .species = SPECIES_KECLEON,
        .moves = {MOVE_TRICK, MOVE_BRICK_BREAK, MOVE_SHADOW_BALL, MOVE_SKILL_SWAP    },
        .itemTableId = BATTLE_FRONTIER_ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_DOCILE,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_VIGOROTH_2] = {
        .species = SPECIES_VIGOROTH,
        .moves = {MOVE_CRUSH_CLAW, MOVE_REVERSAL, MOVE_ENDURE, MOVE_SHADOW_BALL    },
        .itemTableId = BATTLE_FRONTIER_ITEM_SALAC_BERRY,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_LUNATONE_2] = {
        .species = SPECIES_LUNATONE,
        .moves = {MOVE_PSYCHIC, MOVE_ICE_BEAM, MOVE_COSMIC_POWER, MOVE_CALM_MIND    },
        .itemTableId = BATTLE_FRONTIER_ITEM_LAX_INCENSE,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_QUIET,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_SOLROCK_2] = {
        .species = SPECIES_SOLROCK,
        .moves = {MOVE_EARTHQUAKE, MOVE_ROCK_SLIDE, MOVE_COSMIC_POWER, MOVE_OVERHEAT    },
        .itemTableId = BATTLE_FRONTIER_ITEM_WHITE_HERB,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_HARDY,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_NOCTOWL_2] = {
        .species = SPECIES_NOCTOWL,
        .moves = {MOVE_PSYCHIC, MOVE_FAINT_ATTACK, MOVE_AERIAL_ACE, MOVE_REFLECT    },
        .itemTableId = BATTLE_FRONTIER_ITEM_PERSIM_BERRY,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_DEFENSE,
        .nature = NATURE_QUIET,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_SANDSLASH_2] = {
        .species = SPECIES_PALOSSAND,
        .moves = {MOVE_SHORE_UP, MOVE_EARTH_POWER, MOVE_SHADOW_BALL, MOVE_AMNESIA},
        .itemTableId = BATTLE_FRONTIER_ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
		.abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_VENOMOTH_2] = {
        .species = SPECIES_VENOMOTH,
        .moves = {MOVE_SIGNAL_BEAM, MOVE_PSYCHIC, MOVE_SLUDGE_BOMB, MOVE_GIGA_DRAIN    },
        .itemTableId = BATTLE_FRONTIER_ITEM_LUM_BERRY,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_HP,
        .nature = NATURE_DOCILE,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_CHANSEY_2] = {
        .species = SPECIES_CHANSEY,
        .moves = {MOVE_SEISMIC_TOSS, MOVE_SHADOW_BALL, MOVE_DOUBLE_TEAM, MOVE_SOFT_BOILED    },
        .itemTableId = BATTLE_FRONTIER_ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_DEFENSE,
        .nature = NATURE_RELAXED,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_SEAKING_2] = {
        .species = SPECIES_SEAKING,
        .moves = {MOVE_HORN_DRILL, MOVE_MEGAHORN, MOVE_SLEEP_TALK, MOVE_REST    },
        .itemTableId = BATTLE_FRONTIER_ITEM_QUICK_CLAW,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_IMPISH,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_JUMPLUFF_2] = {
        .species = SPECIES_JUMPLUFF,
        .moves = {MOVE_LEECH_SEED, MOVE_SLEEP_POWDER, MOVE_GIGA_DRAIN, MOVE_DOUBLE_TEAM    },
        .itemTableId = BATTLE_FRONTIER_ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_DEFENSE,
        .nature = NATURE_BOLD,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_PILOSWINE_2] = {
        .species = SPECIES_PILOSWINE,
        .moves = {MOVE_EARTHQUAKE, MOVE_ROCK_SLIDE, MOVE_BODY_SLAM, MOVE_ROAR    },
        .itemTableId = BATTLE_FRONTIER_ITEM_SHELL_BELL,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_DEFENSE,
        .nature = NATURE_ADAMANT,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_GOLBAT_2] = {
        .species = SPECIES_GOLBAT,
        .moves = {MOVE_SLUDGE_BOMB, MOVE_SHADOW_BALL, MOVE_CONFUSE_RAY, MOVE_AIR_CUTTER    },
        .itemTableId = BATTLE_FRONTIER_ITEM_SCOPE_LENS,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_PRIMEAPE_2] = {
        .species = SPECIES_PRIMEAPE,
        .moves = {MOVE_CROSS_CHOP, MOVE_ROCK_TOMB, MOVE_OVERHEAT, MOVE_BULK_UP    },
        .itemTableId = BATTLE_FRONTIER_ITEM_SCOPE_LENS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_QUIRKY,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_HITMONLEE_2] = {
        .species = SPECIES_HITMONLEE,
        .moves = {MOVE_MEGA_KICK, MOVE_BRICK_BREAK, MOVE_FORESIGHT, MOVE_ROCK_TOMB    },
        .itemTableId = BATTLE_FRONTIER_ITEM_LAX_INCENSE,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_HITMONCHAN_2] = {
        .species = SPECIES_HITMONCHAN,
        .moves = {MOVE_DYNAMIC_PUNCH, MOVE_MACH_PUNCH, MOVE_DETECT, MOVE_COUNTER    },
        .itemTableId = BATTLE_FRONTIER_ITEM_KINGS_ROCK,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_GIRAFARIG_2] = {
        .species = SPECIES_GIRAFARIG,
        .moves = {MOVE_PSYCHIC, MOVE_CRUNCH, MOVE_BATON_PASS, MOVE_AGILITY    },
        .itemTableId = BATTLE_FRONTIER_ITEM_LUM_BERRY,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_DEFENSE,
        .nature = NATURE_MODEST,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_HITMONTOP_2] = {
        .species = SPECIES_HITMONTOP,
        .moves = {MOVE_DOUBLE_EDGE, MOVE_SEISMIC_TOSS, MOVE_ROCK_SLIDE, MOVE_COUNTER    },
        .itemTableId = BATTLE_FRONTIER_ITEM_FOCUS_BAND,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_BANETTE_2] = {
        .species = SPECIES_BANETTE,
        .moves = {MOVE_SHADOW_BALL, MOVE_FRUSTRATION, MOVE_SCREECH, MOVE_WILL_O_WISP    },
        .itemTableId = BATTLE_FRONTIER_ITEM_LAX_INCENSE,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_DEFENSE,
        .nature = NATURE_ADAMANT,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_NINJASK_2] = {
        .species = SPECIES_NINJASK,
        .moves = {MOVE_SLASH, MOVE_SHADOW_BALL, MOVE_SWORDS_DANCE, MOVE_BATON_PASS    },
        .itemTableId = BATTLE_FRONTIER_ITEM_FOCUS_BAND,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_QUIRKY,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_SEVIPER_2] = {
        .species = SPECIES_SEVIPER,
        .moves = {MOVE_SLUDGE_BOMB, MOVE_EARTHQUAKE, MOVE_CRUNCH, MOVE_GIGA_DRAIN    },
        .itemTableId = BATTLE_FRONTIER_ITEM_QUICK_CLAW,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_QUIRKY,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_ZANGOOSE_2] = {
        .species = SPECIES_ZANGOOSE,
        .moves = {MOVE_CRUSH_CLAW, MOVE_SHADOW_BALL, MOVE_BRICK_BREAK, MOVE_AERIAL_ACE    },
        .itemTableId = BATTLE_FRONTIER_ITEM_SCOPE_LENS,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_CAMERUPT_2] = {
        .species = SPECIES_CAMERUPT,
        .moves = {MOVE_EARTHQUAKE, MOVE_ERUPTION, MOVE_BODY_SLAM, MOVE_SCARY_FACE    },
        .itemTableId = BATTLE_FRONTIER_ITEM_LAX_INCENSE,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_ATTACK,
        .nature = NATURE_QUIRKY,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_SHARPEDO_2] = {
        .species = SPECIES_SHARPEDO,
        .moves = {MOVE_DOUBLE_EDGE, MOVE_CRUNCH, MOVE_EARTHQUAKE, MOVE_SURF    },
        .itemTableId = BATTLE_FRONTIER_ITEM_SCOPE_LENS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_QUIRKY,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_TROPIUS_2] = {
        .species = SPECIES_TROPIUS,
        .moves = {MOVE_SOLAR_BEAM, MOVE_SUNNY_DAY, MOVE_SYNTHESIS, MOVE_BODY_SLAM    },
        .itemTableId = BATTLE_FRONTIER_ITEM_FOCUS_BAND,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_ATTACK,
        .nature = NATURE_QUIET,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_MAGNETON_2] = {
        .species = SPECIES_MAGNETON,
        .moves = {MOVE_THUNDER, MOVE_RAIN_DANCE, MOVE_THUNDER_WAVE, MOVE_METAL_SOUND    },
        .itemTableId = BATTLE_FRONTIER_ITEM_LUM_BERRY,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_HARDY,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_MANTINE_2] = {
        .species = SPECIES_MANTINE,
        .moves = {MOVE_SURF, MOVE_ICE_BEAM, MOVE_RAIN_DANCE, MOVE_CONFUSE_RAY    },
        .itemTableId = BATTLE_FRONTIER_ITEM_SHELL_BELL,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_STANTLER_2] = {
        .species = SPECIES_STANTLER,
        .moves = {MOVE_FRUSTRATION, MOVE_SHADOW_BALL, MOVE_THUNDER_WAVE, MOVE_CONFUSE_RAY    },
        .itemTableId = BATTLE_FRONTIER_ITEM_LAX_INCENSE,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_ABSOL_2] = {
        .species = SPECIES_ABSOL,
        .moves = {MOVE_DOUBLE_EDGE, MOVE_SHADOW_BALL, MOVE_AERIAL_ACE, MOVE_IRON_TAIL    },
        .itemTableId = BATTLE_FRONTIER_ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_SWALOT_2] = {
        .species = SPECIES_SWALOT,
        .moves = {MOVE_SLUDGE_BOMB, MOVE_SHADOW_BALL, MOVE_BODY_SLAM, MOVE_COUNTER    },
        .itemTableId = BATTLE_FRONTIER_ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_CRAWDAUNT_2] = {
        .species = SPECIES_CRAWDAUNT,
        .moves = {MOVE_GUILLOTINE, MOVE_FRUSTRATION, MOVE_ANCIENT_POWER, MOVE_AERIAL_ACE    },
        .itemTableId = BATTLE_FRONTIER_ITEM_QUICK_CLAW,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_PIDGEOT_2] = {
        .species = SPECIES_PIDGEOT,//NOT MEGA
        .moves = {MOVE_AIR_SLASH, MOVE_HEAT_WAVE, MOVE_ROOST, MOVE_TAILWIND},
        .itemTableId = BATTLE_FRONTIER_ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .abilitynum = ABILITY_1
    },
    [FRONTIER_MON_GRUMPIG_2] = {
        .species = SPECIES_GRUMPIG,
        .moves = {MOVE_PSYCHIC, MOVE_ICE_PUNCH, MOVE_THUNDER_PUNCH, MOVE_FIRE_PUNCH    },
        .itemTableId = BATTLE_FRONTIER_ITEM_LUM_BERRY,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_DEFENSE,
        .nature = NATURE_MODEST,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_TORKOAL_2] = {
        .species = SPECIES_TORKOAL,
        .moves = {MOVE_OVERHEAT, MOVE_BODY_SLAM, MOVE_SMOKESCREEN, MOVE_PROTECT    },
        .itemTableId = BATTLE_FRONTIER_ITEM_WHITE_HERB,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_SASSY,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_KINGLER_2] = {
        .species = SPECIES_KINGLER,
        .moves = {MOVE_GUILLOTINE, MOVE_ROCK_TOMB, MOVE_FLAIL, MOVE_ENDURE    },
        .itemTableId = BATTLE_FRONTIER_ITEM_SALAC_BERRY,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_CACTURNE_2] = {
        .species = SPECIES_CACTURNE,
        .moves = {MOVE_MEGA_KICK, MOVE_TEETER_DANCE, MOVE_FAINT_ATTACK, MOVE_SANDSTORM    },
        .itemTableId = BATTLE_FRONTIER_ITEM_PERSIM_BERRY,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_DEFENSE,
        .nature = NATURE_HARDY,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_BELLOSSOM_2] = {
        .species = SPECIES_BELLOSSOM,
        .moves = {MOVE_SOLAR_BEAM, MOVE_ATTRACT, MOVE_SUNNY_DAY, MOVE_SYNTHESIS    },
        .itemTableId = BATTLE_FRONTIER_ITEM_BRIGHT_POWDER,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_DEFENSE,
        .nature = NATURE_MODEST,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_OCTILLERY_2] = {
        .species = SPECIES_OCTILLERY,
        .moves = {MOVE_OCTAZOOKA, MOVE_FIRE_BLAST, MOVE_THUNDER_WAVE, MOVE_MUD_SLAP    },
        .itemTableId = BATTLE_FRONTIER_ITEM_LAX_INCENSE,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_QUIRKY,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_HUNTAIL_2] = {
        .species = SPECIES_HUNTAIL,
        .moves = {MOVE_SURF, MOVE_RAIN_DANCE, MOVE_CRUNCH, MOVE_BODY_SLAM    },
        .itemTableId = BATTLE_FRONTIER_ITEM_SHELL_BELL,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_QUIET,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_GOREBYSS_2] = {
        .species = SPECIES_GOREBYSS,
        .moves = {MOVE_SURF, MOVE_RAIN_DANCE, MOVE_PSYCHIC, MOVE_BODY_SLAM    },
        .itemTableId = BATTLE_FRONTIER_ITEM_SHELL_BELL,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_QUIET,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_RELICANTH_2] = {
        .species = SPECIES_RELICANTH,
        .moves = {MOVE_EARTHQUAKE, MOVE_ROCK_SLIDE, MOVE_AMNESIA, MOVE_REST    },
        .itemTableId = BATTLE_FRONTIER_ITEM_CHESTO_BERRY,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_SASSY,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_OMASTAR_2] = {
        .species = SPECIES_OMASTAR,
        .moves = {MOVE_HYDRO_PUMP, MOVE_RAIN_DANCE, MOVE_ICE_BEAM, MOVE_PROTECT    },
        .itemTableId = BATTLE_FRONTIER_ITEM_SITRUS_BERRY,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_KABUTOPS_2] = {
        .species = SPECIES_KABUTOPS,
        .moves = {MOVE_SLASH, MOVE_ROCK_SLIDE, MOVE_FLAIL, MOVE_ENDURE    },
        .itemTableId = BATTLE_FRONTIER_ITEM_SALAC_BERRY,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_POLIWRATH_2] = {
        .species = SPECIES_POLIWRATH,
        .moves = {MOVE_BRICK_BREAK, MOVE_HYPNOSIS, MOVE_REST, MOVE_BELLY_DRUM    },
        .itemTableId = BATTLE_FRONTIER_ITEM_CHESTO_BERRY,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_SCYTHER_2] = {
        .species = SPECIES_SCYTHER,//TO REMOVE
        .moves = {MOVE_SWORDS_DANCE, MOVE_AERIAL_ACE, MOVE_BRICK_BREAK, MOVE_BUG_BITE},
        .itemTableId = BATTLE_FRONTIER_ITEM_EVIOLITE,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_JOLLY,
        .abilitynum = ABILITY_1
    },
    [FRONTIER_MON_PINSIR_2] = {
        .species = SPECIES_PINSIR,
        .moves = {MOVE_GUILLOTINE, MOVE_SWORDS_DANCE, MOVE_FLAIL, MOVE_ENDURE    },
        .itemTableId = BATTLE_FRONTIER_ITEM_SALAC_BERRY,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_HP,
        .nature = NATURE_JOLLY,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_POLITOED_2] = {
        .species = SPECIES_POLITOED,
        .moves = {MOVE_SURF, MOVE_PSYCHIC, MOVE_MUD_SLAP, MOVE_SWAGGER    },
        .itemTableId = BATTLE_FRONTIER_ITEM_LAX_INCENSE,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_DEFENSE,
        .nature = NATURE_MODEST,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_CLOYSTER_2] = {
        .species = SPECIES_CLOYSTER,
        .moves = {MOVE_DIVE, MOVE_TOXIC, MOVE_DOUBLE_TEAM, MOVE_PROTECT    },
        .itemTableId = BATTLE_FRONTIER_ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_CAREFUL,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_DUGTRIO_1] = {
        .species = SPECIES_DUGTRIO,
        .moves = {MOVE_EARTHQUAKE, MOVE_SUCKER_PUNCH, MOVE_REVERSAL, MOVE_ROCK_SLIDE},
        .itemTableId = BATTLE_FRONTIER_ITEM_FOCUS_SASH,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_MEDICHAM_1] = {
        .species = SPECIES_MEDICHAM,
        .moves = {MOVE_PSYCHIC, MOVE_HI_JUMP_KICK, MOVE_CALM_MIND, MOVE_BATON_PASS    },
        .itemTableId = BATTLE_FRONTIER_ITEM_FOCUS_BAND,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_DOCILE,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_MISDREAVUS_1] = {
        .species = SPECIES_MISDREAVUS,
        .moves = {MOVE_PAIN_SPLIT, MOVE_SHADOW_BALL, MOVE_CONFUSE_RAY, MOVE_THUNDER_WAVE    },
        .itemTableId = BATTLE_FRONTIER_ITEM_FOCUS_BAND,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_IMPISH,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_FEAROW_1] = {
        .species = SPECIES_FEAROW,
        .moves = {MOVE_DRILL_PECK, MOVE_TRI_ATTACK, MOVE_FACADE, MOVE_MUD_SLAP    },
        .itemTableId = BATTLE_FRONTIER_ITEM_SHARP_BEAK,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_GRANBULL_1] = {
        .species = SPECIES_GRANBULL,
        .moves = {MOVE_MEGA_KICK, MOVE_SMELLING_SALT, MOVE_THUNDER_WAVE, MOVE_ROAR    },
        .itemTableId = BATTLE_FRONTIER_ITEM_CHERI_BERRY,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_JYNX_1] = {
        .species = SPECIES_JYNX,
        .moves = {MOVE_ICE_BEAM, MOVE_FAKE_OUT, MOVE_LOVELY_KISS, MOVE_ATTRACT    },
        .itemTableId = BATTLE_FRONTIER_ITEM_SHELL_BELL,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_DUSCLOPS_1] = {
        .species = SPECIES_DUSCLOPS,
        .moves = {MOVE_WILL_O_WISP, MOVE_SEISMIC_TOSS, MOVE_PAIN_SPLIT, MOVE_CONFUSE_RAY},
        .itemTableId = BATTLE_FRONTIER_ITEM_EVIOLITE,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_IMPISH,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_DODRIO_1] = {
        .species = SPECIES_DODRIO,
        .moves = {MOVE_SWORDS_DANCE, MOVE_BRAVE_BIRD, MOVE_JUMP_KICK, MOVE_RETURN},
        .itemTableId = BATTLE_FRONTIER_ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_MR_MIME_1] = {
        .species = SPECIES_MR_MIME,
        .moves = {MOVE_PSYCHIC, MOVE_MAGICAL_LEAF, MOVE_FAKE_OUT, MOVE_REFLECT    },
        .itemTableId = BATTLE_FRONTIER_ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_RELAXED,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_LANTURN_1] = {
        .species = SPECIES_LANTURN,
        .moves = {MOVE_SURF, MOVE_CONFUSE_RAY, MOVE_ATTRACT, MOVE_THUNDER_WAVE    },
        .itemTableId = BATTLE_FRONTIER_ITEM_CHERI_BERRY,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_DEFENSE,
        .nature = NATURE_QUIET,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_BRELOOM_1] = {
        .species = SPECIES_BRELOOM,
        .moves = {MOVE_SKY_UPPERCUT, MOVE_MACH_PUNCH, MOVE_HEADBUTT, MOVE_COUNTER    },
        .itemTableId = BATTLE_FRONTIER_ITEM_KINGS_ROCK,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_FORRETRESS_1] = {
        .species = SPECIES_FORRETRESS,
        .moves = {MOVE_DOUBLE_EDGE, MOVE_ROCK_SLIDE, MOVE_LIGHT_SCREEN, MOVE_SPIKES    },
        .itemTableId = BATTLE_FRONTIER_ITEM_FOCUS_BAND,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_WHISCASH_1] = {
        .species = SPECIES_WHISCASH,
        .moves = {MOVE_EARTHQUAKE, MOVE_ROCK_SLIDE, MOVE_AMNESIA, MOVE_REST    },
        .itemTableId = BATTLE_FRONTIER_ITEM_CHESTO_BERRY,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_XATU_1] = {
        .species = SPECIES_XATU,
        .moves = {MOVE_DRILL_PECK, MOVE_NIGHT_SHADE, MOVE_WISH, MOVE_FUTURE_SIGHT    },
        .itemTableId = BATTLE_FRONTIER_ITEM_SHARP_BEAK,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_HARDY,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_SKARMORY_1] = {
        .species = SPECIES_SKARMORY,
        .moves = {MOVE_STEEL_WING, MOVE_AIR_CUTTER, MOVE_COUNTER, MOVE_AGILITY    },
        .itemTableId = BATTLE_FRONTIER_ITEM_SCOPE_LENS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_MAROWAK_1] = {
        .species = SPECIES_MAROWAK,
        .moves = {MOVE_BONEMERANG, MOVE_ROCK_SLIDE, MOVE_ICY_WIND, MOVE_HEADBUTT    },
        .itemTableId = BATTLE_FRONTIER_ITEM_THICK_CLUB,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_QUAGSIRE_1] = {
        .species = SPECIES_QUAGSIRE,
        .moves = {MOVE_EARTHQUAKE, MOVE_BRICK_BREAK, MOVE_COUNTER, MOVE_MUD_SLAP    },
        .itemTableId = BATTLE_FRONTIER_ITEM_FOCUS_BAND,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_CLEFABLE_1] = {
        .species = SPECIES_CLEFABLE,
        .moves = {MOVE_METRONOME, MOVE_DOUBLE_TEAM, MOVE_REFLECT, MOVE_FOLLOW_ME    },
        .itemTableId = BATTLE_FRONTIER_ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_DEFENSE,
        .nature = NATURE_BRAVE,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_HARIYAMA_1] = {
        .species = SPECIES_HARIYAMA,
        .moves = {MOVE_CROSS_CHOP, MOVE_ROCK_SLIDE, MOVE_COUNTER, MOVE_FAKE_OUT    },
        .itemTableId = BATTLE_FRONTIER_ITEM_FOCUS_BAND,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_RAICHU_1] = {
        .species = SPECIES_RAICHU,
        .moves = {MOVE_THUNDERBOLT, MOVE_SURF, MOVE_GRASS_KNOT, MOVE_NUZZLE},
        .itemTableId = BATTLE_FRONTIER_ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
		.abilitynum = 2
    },
    [FRONTIER_MON_DEWGONG_1] = {
        .species = SPECIES_DEWGONG,
        .moves = {MOVE_ICE_BEAM, MOVE_ICY_WIND, MOVE_HEADBUTT, MOVE_FAKE_OUT    },
        .itemTableId = BATTLE_FRONTIER_ITEM_NEVER_MELT_ICE,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_QUIET,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_MANECTRIC_1] = {
        .species = SPECIES_MANECTRIC,
        .moves = {MOVE_THUNDERBOLT, MOVE_FLASH, MOVE_QUICK_ATTACK, MOVE_ROAR    },
        .itemTableId = BATTLE_FRONTIER_ITEM_MAGNET,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_VILEPLUME_1] = {
        .species = SPECIES_VILEPLUME,
        .moves = {MOVE_SLUDGE_BOMB, MOVE_PETAL_DANCE, MOVE_MOONLIGHT, MOVE_AROMATHERAPY    },
        .itemTableId = BATTLE_FRONTIER_ITEM_PERSIM_BERRY,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_IMPISH,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_VICTREEBEL_1] = {
        .species = SPECIES_VICTREEBEL,
        .moves = {MOVE_GIGA_DRAIN, MOVE_SLEEP_POWDER, MOVE_SWEET_SCENT, MOVE_SYNTHESIS    },
        .itemTableId = BATTLE_FRONTIER_ITEM_SITRUS_BERRY,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_DEFENSE,
        .nature = NATURE_QUIET,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_ELECTRODE_1] = {
        .species = SPECIES_ELECTRODE,
        .moves = {MOVE_THUNDERBOLT, MOVE_SWIFT, MOVE_LIGHT_SCREEN, MOVE_PROTECT    },
        .itemTableId = BATTLE_FRONTIER_ITEM_FOCUS_BAND,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_QUIET,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_EXPLOUD_1] = {
        .species = SPECIES_EXPLOUD,
        .moves = {MOVE_BOOMBURST, MOVE_ICE_BEAM, MOVE_FIRE_BLAST, MOVE_THUNDERBOLT},
        .itemTableId = BATTLE_FRONTIER_ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_TIMID,
		.abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_SHIFTRY_1] = {
        .species = SPECIES_SHIFTRY,
        .moves = {MOVE_GIGA_DRAIN, MOVE_FAINT_ATTACK, MOVE_QUICK_ATTACK, MOVE_FAKE_OUT    },
        .itemTableId = BATTLE_FRONTIER_ITEM_MIRACLE_SEED,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_DEFENSE,
        .nature = NATURE_QUIET,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_GLALIE_1] = {
        .species = SPECIES_GLALIE,
        .moves = {MOVE_ICE_BEAM, MOVE_CRUNCH, MOVE_HAIL, MOVE_PROTECT    },
        .itemTableId = BATTLE_FRONTIER_ITEM_PETAYA_BERRY,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_LUDICOLO_1] = {
        .species = SPECIES_LUDICOLO,
        .moves = {MOVE_HYDRO_PUMP, MOVE_ICE_BEAM, MOVE_GIGA_DRAIN, MOVE_SCALD},
        .itemTableId = BATTLE_FRONTIER_ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
		.abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_HYPNO_1] = {
        .species = SPECIES_HYPNO,
        .moves = {MOVE_THUNDER_PUNCH, MOVE_FIRE_PUNCH, MOVE_ICE_PUNCH, MOVE_HYPNOSIS    },
        .itemTableId = BATTLE_FRONTIER_ITEM_TWISTED_SPOON,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_DEFENSE,
        .nature = NATURE_QUIET,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_GOLEM_1] = {
        .species = SPECIES_GOLEM,
        .moves = {MOVE_EARTHQUAKE, MOVE_EXPLOSION, MOVE_STONE_EDGE, MOVE_STEALTH_ROCK},
        .itemTableId = BATTLE_FRONTIER_ITEM_WEAKNESS_POLICY,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
		.abilitynum = ABILITY_1
    },
    [FRONTIER_MON_RHYDON_1] = {
        .species = SPECIES_RHYDON,//EVIOLITE
        .moves = {MOVE_STEALTH_ROCK, MOVE_ICE_PUNCH, MOVE_EARTHQUAKE, MOVE_ROCK_BLAST},
        .itemTableId = BATTLE_FRONTIER_ITEM_EVIOLITE,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
		.abilitynum = ABILITY_2
    },
    [FRONTIER_MON_ALAKAZAM_1] = {
        .species = SPECIES_ALAKAZAM,
        .moves = {MOVE_THUNDER_PUNCH, MOVE_FIRE_PUNCH, MOVE_ICE_PUNCH, MOVE_THUNDER_WAVE    },
        .itemTableId = BATTLE_FRONTIER_ITEM_FOCUS_BAND,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_DEFENSE,
        .nature = NATURE_MODEST,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_WEEZING_1] = {
        .species = SPECIES_WEEZING,
        .moves = {MOVE_SLUDGE_BOMB, MOVE_WILL_O_WISP, MOVE_SHADOW_BALL, MOVE_SMOKESCREEN    },
        .itemTableId = BATTLE_FRONTIER_ITEM_BRIGHT_POWDER,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_KANGASKHAN_1] = {
        .species = SPECIES_KANGASKHAN,
        .moves = {MOVE_DIZZY_PUNCH, MOVE_BRICK_BREAK, MOVE_COUNTER, MOVE_FAKE_OUT    },
        .itemTableId = BATTLE_FRONTIER_ITEM_FOCUS_BAND,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_ELECTABUZZ_1] = {
        .species = SPECIES_ELECTABUZZ,
        .moves = {MOVE_THUNDERBOLT, MOVE_THUNDER_WAVE, MOVE_BRICK_BREAK, MOVE_LIGHT_SCREEN    },
        .itemTableId = BATTLE_FRONTIER_ITEM_CHERI_BERRY,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_RELAXED,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_TAUROS_1] = {
        .species = SPECIES_TAUROS,
        .moves = {MOVE_EARTHQUAKE, MOVE_THRASH, MOVE_SWAGGER, MOVE_FACADE    },
        .itemTableId = BATTLE_FRONTIER_ITEM_PERSIM_BERRY,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_SLOWBRO_1] = {
        .species = SPECIES_SLOWBRO,
        .moves = {MOVE_SURF, MOVE_RAIN_DANCE, MOVE_HEADBUTT, MOVE_ICE_PUNCH    },
        .itemTableId = BATTLE_FRONTIER_ITEM_SHELL_BELL,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_QUIET,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_SLOWKING_1] = {
        .species = SPECIES_SLOWKING,
        .moves = {MOVE_PSYCHIC, MOVE_BRICK_BREAK, MOVE_AMNESIA, MOVE_ATTRACT    },
        .itemTableId = BATTLE_FRONTIER_ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_QUIET,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_MILTANK_1] = {
        .species = SPECIES_MILTANK,
        .moves = {MOVE_FACADE, MOVE_SHADOW_BALL, MOVE_COUNTER, MOVE_MILK_DRINK    },
        .itemTableId = BATTLE_FRONTIER_ITEM_FOCUS_BAND,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_CAREFUL,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_ALTARIA_1] = {
        .species = SPECIES_ALTARIA,
        .moves = {MOVE_DRAGON_CLAW, MOVE_AERIAL_ACE, MOVE_REFRESH, MOVE_BODY_SLAM    },
        .itemTableId = BATTLE_FRONTIER_ITEM_CHERI_BERRY,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_DOCILE,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_NIDOQUEEN_1] = {
        .species = SPECIES_NIDOQUEEN,
        .moves = {MOVE_SLUDGE_BOMB, MOVE_DOUBLE_KICK, MOVE_BODY_SLAM, MOVE_COUNTER    },
        .itemTableId = BATTLE_FRONTIER_ITEM_FOCUS_BAND,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_NIDOKING_1] = {
        .species = SPECIES_NIDOKING,
        .moves = {MOVE_HORN_DRILL, MOVE_DOUBLE_KICK, MOVE_BODY_SLAM, MOVE_COUNTER    },
        .itemTableId = BATTLE_FRONTIER_ITEM_QUICK_CLAW,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_MAGMAR_1] = {
        .species = SPECIES_MAGMAR,
        .moves = {MOVE_FLAMETHROWER, MOVE_SMOKESCREEN, MOVE_BRICK_BREAK, MOVE_BARRIER    },
        .itemTableId = BATTLE_FRONTIER_ITEM_RAWST_BERRY,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_RELAXED,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_CRADILY_1] = {
        .species = SPECIES_CRADILY,
        .moves = {MOVE_GIGA_DRAIN, MOVE_ROCK_SLIDE, MOVE_BARRIER, MOVE_CONFUSE_RAY    },
        .itemTableId = BATTLE_FRONTIER_ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_RELAXED,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_ARMALDO_1] = {
        .species = SPECIES_ARMALDO,
        .moves = {MOVE_EARTHQUAKE, MOVE_X_SCISSOR, MOVE_STEALTH_ROCK, MOVE_STONE_EDGE},
        .itemTableId = BATTLE_FRONTIER_ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_ADAMANT,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_GOLDUCK_1] = {
        .species = SPECIES_GOLDUCK,
        .moves = {MOVE_HYDRO_PUMP, MOVE_DIG, MOVE_BRICK_BREAK, MOVE_LIGHT_SCREEN    },
        .itemTableId = BATTLE_FRONTIER_ITEM_SHELL_BELL,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_ATTACK,
        .nature = NATURE_QUIET,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_RAPIDASH_1] = {
        .species = SPECIES_RAPIDASH,
        .moves = {MOVE_FLAMETHROWER, MOVE_DOUBLE_KICK, MOVE_QUICK_ATTACK, MOVE_PROTECT    },
        .itemTableId = BATTLE_FRONTIER_ITEM_CHARCOAL,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_QUIET,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_MUK_1] = {
        .species = SPECIES_MUK,
        .moves = {MOVE_SLUDGE_BOMB, MOVE_BODY_SLAM, MOVE_SCREECH, MOVE_MINIMIZE    },
        .itemTableId = BATTLE_FRONTIER_ITEM_POISON_BARB,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_GENGAR_1] = {
         .species = SPECIES_GENGAR,//MEGA
        .moves = {MOVE_SLUDGE_BOMB, MOVE_HEX, MOVE_WILL_O_WISP, MOVE_DESTINY_BOND},
        .itemTableId = BATTLE_FRONTIER_ITEM_GENGARITE,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_SP_ATTACK,
        .nature = NATURE_TIMID,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_AMPHAROS_1] = {
        .species = SPECIES_AMPHAROS,
        .moves = {MOVE_THUNDER, MOVE_RAIN_DANCE, MOVE_THUNDER_WAVE, MOVE_ATTRACT    },
        .itemTableId = BATTLE_FRONTIER_ITEM_MAGNET,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_RELAXED,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_SCIZOR_1] = {
        .species = SPECIES_SCIZOR,
        .moves = {MOVE_METAL_CLAW, MOVE_AERIAL_ACE, MOVE_COUNTER, MOVE_QUICK_ATTACK    },
        .itemTableId = BATTLE_FRONTIER_ITEM_FOCUS_BAND,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_HERACROSS_1] = {//MEGA
        .species = SPECIES_HERACROSS,
        .moves = {MOVE_ARM_THRUST, MOVE_PIN_MISSILE, MOVE_ROCK_BLAST, MOVE_BULLET_SEED},
        .itemTableId = BATTLE_FRONTIER_ITEM_HERACRONITE,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
		.abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_URSARING_1] = {
        .species = SPECIES_URSARING,
        .moves = {MOVE_SWORDS_DANCE, MOVE_FACADE, MOVE_PLAY_ROUGH, MOVE_FIRE_PUNCH},
        .itemTableId = BATTLE_FRONTIER_ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_JOLLY,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_HOUNDOOM_1] = {
        .species = SPECIES_HOUNDOOM,
        .moves = {MOVE_FLAMETHROWER, MOVE_SHADOW_BALL, MOVE_COUNTER, MOVE_WILL_O_WISP    },
        .itemTableId = BATTLE_FRONTIER_ITEM_FOCUS_BAND,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_QUIRKY,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_DONPHAN_1] = {
        .species = SPECIES_DONPHAN,
        .moves = {MOVE_EARTHQUAKE, MOVE_ANCIENT_POWER, MOVE_SWAGGER, MOVE_REST    },
        .itemTableId = BATTLE_FRONTIER_ITEM_CHESTO_BERRY,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_CLAYDOL_1] = {
        .species = SPECIES_CLAYDOL,
        .moves = {MOVE_EARTHQUAKE, MOVE_ROCK_SLIDE, MOVE_SWAGGER, MOVE_PSYCH_UP    },
        .itemTableId = BATTLE_FRONTIER_ITEM_LUM_BERRY,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_WAILORD_1] = {
        .species = SPECIES_WAILORD,
        .moves = {MOVE_SURF, MOVE_ICY_WIND, MOVE_BODY_SLAM, MOVE_ROAR    },
        .itemTableId = BATTLE_FRONTIER_ITEM_SHELL_BELL,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_SASSY,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_NINETALES_1] = {
        .species = SPECIES_NINETALES,
        .moves = {MOVE_WILL_O_WISP, MOVE_SOLAR_BEAM, MOVE_FIRE_BLAST, MOVE_SHADOW_BALL},
        .itemTableId = BATTLE_FRONTIER_ITEM_HEAT_ROCK,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
		.abilitynum = 2
    },
    [FRONTIER_MON_MACHAMP_1] = {
        .species = SPECIES_MACHAMP,
        .moves = {MOVE_CROSS_CHOP, MOVE_ROCK_SLIDE, MOVE_COUNTER, MOVE_SCARY_FACE    },
        .itemTableId = BATTLE_FRONTIER_ITEM_SCOPE_LENS,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_SHUCKLE_1] = {
        .species = SPECIES_SHUCKLE,
        .moves = {MOVE_ROLLOUT, MOVE_DEFENSE_CURL, MOVE_SLEEP_TALK, MOVE_REST    },
        .itemTableId = BATTLE_FRONTIER_ITEM_CHESTO_BERRY,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_DEFENSE,
        .nature = NATURE_BRAVE,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_STEELIX_1] = {
        .species = SPECIES_STEELIX,
        .moves = {MOVE_EARTHQUAKE, MOVE_DRAGON_BREATH, MOVE_ROCK_TOMB, MOVE_ROAR    },
        .itemTableId = BATTLE_FRONTIER_ITEM_SITRUS_BERRY,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_TENTACRUEL_1] = {
        .species = SPECIES_TENTACRUEL,
        .moves = {MOVE_SLUDGE_BOMB, MOVE_ICY_WIND, MOVE_BARRIER, MOVE_CONFUSE_RAY    },
        .itemTableId = BATTLE_FRONTIER_ITEM_PERSIM_BERRY,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_ATTACK,
        .nature = NATURE_IMPISH,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_AERODACTYL_1] = {
        .species = SPECIES_AERODACTYL,
        .moves = {MOVE_ANCIENT_POWER, MOVE_DRAGON_BREATH, MOVE_AERIAL_ACE, MOVE_ROAR    },
        .itemTableId = BATTLE_FRONTIER_ITEM_KINGS_ROCK,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_PORYGON2_1] = {
        .species = SPECIES_PORYGON2,
        .moves = {MOVE_TRI_ATTACK, MOVE_ICE_BEAM, MOVE_TRICK_ROOM, MOVE_RECOVER},
        .itemTableId = BATTLE_FRONTIER_ITEM_EVIOLITE,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_BOLD,
		.abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_GARDEVOIR_1] = {
        .species = SPECIES_GARDEVOIR,//MEGA
        .moves = {MOVE_HYPER_VOICE, MOVE_PSYSHOCK, MOVE_SHADOW_BALL, MOVE_THUNDERBOLT},
        .itemTableId = BATTLE_FRONTIER_ITEM_GARDEVOIRITE,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_SP_ATTACK,
        .nature = NATURE_TIMID,
        .abilitynum = ABILITY_1
    },
    [FRONTIER_MON_EXEGGUTOR_1] = {
        .species = SPECIES_EXEGGUTOR,
        .moves = {MOVE_SOLAR_BEAM, MOVE_SUNNY_DAY, MOVE_SYNTHESIS, MOVE_LIGHT_SCREEN    },
        .itemTableId = BATTLE_FRONTIER_ITEM_QUICK_CLAW,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_DEFENSE,
        .nature = NATURE_QUIET,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_STARMIE_1] = {
        .species = SPECIES_STARMIE,
        .moves = {MOVE_PSYCHIC, MOVE_CONFUSE_RAY, MOVE_THUNDER_WAVE, MOVE_RECOVER    },
        .itemTableId = BATTLE_FRONTIER_ITEM_SHELL_BELL,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_FLYGON_1] = {
        .species = SPECIES_FLYGON,
        .moves = {MOVE_EARTHQUAKE, MOVE_STEEL_WING, MOVE_FAINT_ATTACK, MOVE_FACADE    },
        .itemTableId = BATTLE_FRONTIER_ITEM_BRIGHT_POWDER,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_VENUSAUR_1] = {
        .species = SPECIES_VENUSAUR,
        .moves = {MOVE_GIGA_DRAIN, MOVE_SUNNY_DAY, MOVE_SYNTHESIS, MOVE_SLEEP_POWDER    },
        .itemTableId = BATTLE_FRONTIER_ITEM_CHESTO_BERRY,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_QUIET,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_VAPOREON_1] = {
        .species = SPECIES_VAPOREON,
        .moves = {MOVE_SURF, MOVE_ROAR, MOVE_BITE, MOVE_QUICK_ATTACK    },
        .itemTableId = BATTLE_FRONTIER_ITEM_MYSTIC_WATER,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_DEFENSE,
        .nature = NATURE_MODEST,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_JOLTEON_1] = {
        .species = SPECIES_JOLTEON,
        .moves = {MOVE_VOLT_SWITCH, MOVE_SHADOW_BALL, MOVE_THUNDERBOLT, MOVE_HIDDEN_POWER},
        .itemTableId = BATTLE_FRONTIER_ITEM_CHOICE_SPECS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
		.abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_FLAREON_1] = {
        .species = SPECIES_FLAREON,
        .moves = {MOVE_FLAMETHROWER, MOVE_ROAR, MOVE_BITE, MOVE_SAND_ATTACK    },
        .itemTableId = BATTLE_FRONTIER_ITEM_SITRUS_BERRY,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_DEFENSE,
        .nature = NATURE_MODEST,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_MEGANIUM_1] = {
        .species = SPECIES_MEGANIUM,
        .moves = {MOVE_SOLAR_BEAM, MOVE_SUNNY_DAY, MOVE_LIGHT_SCREEN, MOVE_SYNTHESIS    },
        .itemTableId = BATTLE_FRONTIER_ITEM_BRIGHT_POWDER,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_ESPEON_1] = {
        .species = SPECIES_ESPEON,
        .moves = {MOVE_PSYCHIC, MOVE_CHARM, MOVE_CALM_MIND, MOVE_BATON_PASS    },
        .itemTableId = BATTLE_FRONTIER_ITEM_LUM_BERRY,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_SPEED | F_EV_SPREAD_DEFENSE,
        .nature = NATURE_MODEST,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_UMBREON_1] = {
        .species = SPECIES_UMBREON,
        .moves = {MOVE_CONFUSE_RAY, MOVE_FAINT_ATTACK, MOVE_DOUBLE_TEAM, MOVE_BATON_PASS    },
        .itemTableId = BATTLE_FRONTIER_ITEM_BRIGHT_POWDER,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_BOLD,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_BLASTOISE_1] = {
        .species = SPECIES_BLASTOISE,
        .moves = {MOVE_AURA_SPHERE, MOVE_DARK_PULSE, MOVE_RAPID_SPIN, MOVE_WATER_PULSE},
        .itemTableId = BATTLE_FRONTIER_ITEM_BLASTOISINITE,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_FERALIGATR_1] = {
        .species = SPECIES_FERALIGATR,
        .moves = {MOVE_SURF, MOVE_RAIN_DANCE, MOVE_AERIAL_ACE, MOVE_ROAR    },
        .itemTableId = BATTLE_FRONTIER_ITEM_LUM_BERRY,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_QUIET,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_AGGRON_1] = {
        .species = SPECIES_AGGRON,
        .moves = {MOVE_IRON_TAIL, MOVE_EARTHQUAKE, MOVE_AERIAL_ACE, MOVE_ROAR    },
        .itemTableId = BATTLE_FRONTIER_ITEM_QUICK_CLAW,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_BLAZIKEN_1] = {
        .species = SPECIES_BLAZIKEN,
        .moves = {MOVE_FLAMETHROWER, MOVE_SUNNY_DAY, MOVE_DOUBLE_KICK, MOVE_ROAR    },
        .itemTableId = BATTLE_FRONTIER_ITEM_QUICK_CLAW,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_ATTACK,
        .nature = NATURE_DOCILE,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_WALREIN_1] = {
        .species = SPECIES_WALREIN,
        .moves = {MOVE_BLIZZARD, MOVE_HAIL, MOVE_YAWN, MOVE_PROTECT    },
        .itemTableId = BATTLE_FRONTIER_ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_QUIET,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_SCEPTILE_1] = {
        .species = SPECIES_SCEPTILE,
        .moves = {MOVE_LEAF_BLADE, MOVE_LEECH_SEED, MOVE_AERIAL_ACE, MOVE_DETECT    },
        .itemTableId = BATTLE_FRONTIER_ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_CHARIZARD_1] = {
        .species = SPECIES_CHARIZARD,
        .moves = {MOVE_FIRE_BLAST, MOVE_SUNNY_DAY, MOVE_ROAR, MOVE_SCARY_FACE    },
        .itemTableId = BATTLE_FRONTIER_ITEM_FOCUS_BAND,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_TYPHLOSION_1] = {
        .species = SPECIES_TYPHLOSION,
        .moves = {MOVE_FIRE_BLAST, MOVE_SUNNY_DAY, MOVE_SMOKESCREEN, MOVE_ROAR    },
        .itemTableId = BATTLE_FRONTIER_ITEM_FOCUS_BAND,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_LAPRAS_1] = {
        .species = SPECIES_LAPRAS,
        .moves = {MOVE_SURF, MOVE_ATTRACT, MOVE_CONFUSE_RAY, MOVE_SING    },
        .itemTableId = BATTLE_FRONTIER_ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_DEFENSE,
        .nature = NATURE_BOLD,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_CROBAT_1] = {
        .species = SPECIES_CROBAT,
        .moves = {MOVE_SLUDGE_BOMB, MOVE_BITE, MOVE_ASTONISH, MOVE_SCREECH    },
        .itemTableId = BATTLE_FRONTIER_ITEM_KINGS_ROCK,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_QUIRKY,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_SWAMPERT_1] = {
        .species = SPECIES_SWAMPERT,
        .moves = {MOVE_EARTHQUAKE, MOVE_COUNTER, MOVE_REST, MOVE_CURSE    },
        .itemTableId = BATTLE_FRONTIER_ITEM_LUM_BERRY,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_GYARADOS_1] = {
        .species = SPECIES_GYARADOS,
        .moves = {MOVE_RETURN, MOVE_BITE, MOVE_THUNDER_WAVE, MOVE_DRAGON_DANCE    },
        .itemTableId = BATTLE_FRONTIER_ITEM_LUM_BERRY,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_CAREFUL,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_SNORLAX_1] = {
        .species = SPECIES_SNORLAX,
        .moves = {MOVE_FACADE, MOVE_SHADOW_BALL, MOVE_ATTRACT, MOVE_DOUBLE_TEAM    },
        .itemTableId = BATTLE_FRONTIER_ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_KINGDRA_1] = {
        .species = SPECIES_KINGDRA,
        .moves = {MOVE_HYDRO_PUMP, MOVE_DRAGON_BREATH, MOVE_ICY_WIND, MOVE_ATTRACT    },
        .itemTableId = BATTLE_FRONTIER_ITEM_LUM_BERRY,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_BLISSEY_1] = {
        .species = SPECIES_BLISSEY,
        .moves = {MOVE_TOXIC, MOVE_DOUBLE_TEAM, MOVE_SING, MOVE_SOFT_BOILED    },
        .itemTableId = BATTLE_FRONTIER_ITEM_BRIGHT_POWDER,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_DEFENSE,
        .nature = NATURE_BOLD,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_MILOTIC_1] = {
        .species = SPECIES_MILOTIC,
        .moves = {MOVE_HYDRO_PUMP, MOVE_ICY_WIND, MOVE_RECOVER, MOVE_MIRROR_COAT    },
        .itemTableId = BATTLE_FRONTIER_ITEM_LUM_BERRY,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_ARCANINE_1] = {
        .species = SPECIES_ARCANINE,
        .moves = {MOVE_FLAMETHROWER, MOVE_EXTREME_SPEED, MOVE_CRUNCH, MOVE_BODY_SLAM    },
        .itemTableId = BATTLE_FRONTIER_ITEM_KINGS_ROCK,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_SALAMENCE_1] = {
        .species = SPECIES_KROOKODILE,
        .moves = {MOVE_STONE_EDGE, MOVE_EARTHQUAKE, MOVE_KNOCK_OFF, MOVE_DRAGON_DANCE},
        .itemTableId = BATTLE_FRONTIER_ITEM_ROCKY_HELMET,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_JOLLY,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_METAGROSS_1] = {
        .species = SPECIES_METAGROSS,
        .moves = {MOVE_METEOR_MASH, MOVE_AERIAL_ACE, MOVE_FACADE, MOVE_LIGHT_SCREEN    },
        .itemTableId = BATTLE_FRONTIER_ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_SLAKING_1] = {
        .species = SPECIES_SLAKING,
        .moves = {MOVE_YAWN, MOVE_BULK_UP, MOVE_SWAGGER, MOVE_AERIAL_ACE    },
        .itemTableId = BATTLE_FRONTIER_ITEM_SCOPE_LENS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_DUGTRIO_2] = {
        .species = SPECIES_DUGTRIO_ALOLAN,
        .moves = {MOVE_EARTHQUAKE, MOVE_IRON_HEAD, MOVE_SUCKER_PUNCH, MOVE_ROCK_SLIDE},
        .itemTableId = BATTLE_FRONTIER_ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_MEDICHAM_2] = {
        .species = SPECIES_MEDICHAM,
        .moves = {MOVE_REVERSAL, MOVE_ENDURE, MOVE_PSYCHIC, MOVE_FAKE_OUT    },
        .itemTableId = BATTLE_FRONTIER_ITEM_SALAC_BERRY,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_HARDY,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_MAROWAK_2] = {
        .species = SPECIES_MAROWAK,
        .moves = {MOVE_EARTHQUAKE, MOVE_ROCK_SLIDE, MOVE_SWORDS_DANCE, MOVE_ICY_WIND    },
        .itemTableId = BATTLE_FRONTIER_ITEM_THICK_CLUB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_QUAGSIRE_2] = {
        .species = SPECIES_QUAGSIRE,
        .moves = {MOVE_CURSE, MOVE_ATTRACT, MOVE_YAWN, MOVE_ANCIENT_POWER    },
        .itemTableId = BATTLE_FRONTIER_ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_DEFENSE,
        .nature = NATURE_SASSY,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_MISDREAVUS_2] = {
        .species = SPECIES_MISDREAVUS,
        .moves = {MOVE_PSYCHIC, MOVE_ATTRACT, MOVE_THUNDER_WAVE, MOVE_CONFUSE_RAY    },
        .itemTableId = BATTLE_FRONTIER_ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_DEFENSE,
        .nature = NATURE_BOLD,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_FEAROW_2] = {
        .species = SPECIES_FEAROW,
        .moves = {MOVE_DRILL_PECK, MOVE_TRI_ATTACK, MOVE_ATTRACT, MOVE_PURSUIT    },
        .itemTableId = BATTLE_FRONTIER_ITEM_FOCUS_BAND,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_GRANBULL_2] = {
        .species = SPECIES_GRANBULL,
        .moves = {MOVE_OVERHEAT, MOVE_THUNDERBOLT, MOVE_ICE_PUNCH, MOVE_FACADE    },
        .itemTableId = BATTLE_FRONTIER_ITEM_WHITE_HERB,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_SP_ATTACK,
        .nature = NATURE_QUIET,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_JYNX_2] = {
        .species = SPECIES_JYNX,
        .moves = {MOVE_PERISH_SONG, MOVE_MEAN_LOOK, MOVE_LOVELY_KISS, MOVE_PROTECT    },
        .itemTableId = BATTLE_FRONTIER_ITEM_BRIGHT_POWDER,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_IMPISH,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_DUSCLOPS_2] = {
        .species = SPECIES_DUSKNOIR,
        .moves = {MOVE_WILL_O_WISP, MOVE_PAIN_SPLIT, MOVE_SHADOW_SNEAK, MOVE_ICE_PUNCH},
        .itemTableId = BATTLE_FRONTIER_ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
		.abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_DODRIO_2] = {
        .species = SPECIES_DODRIO,
        .moves = {MOVE_DRILL_PECK, MOVE_DOUBLE_EDGE, MOVE_FAINT_ATTACK, MOVE_PROTECT    },
        .itemTableId = BATTLE_FRONTIER_ITEM_KINGS_ROCK,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_MR_MIME_2] = {
        .species = SPECIES_MR_MIME,
        .moves = {MOVE_BATON_PASS, MOVE_SWAGGER, MOVE_PSYCH_UP, MOVE_PSYCHIC    },
        .itemTableId = BATTLE_FRONTIER_ITEM_LIECHI_BERRY,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_LANTURN_2] = {
        .species = SPECIES_LANTURN,
        .moves = {MOVE_FLAIL, MOVE_ENDURE, MOVE_THUNDERBOLT, MOVE_SURF    },
        .itemTableId = BATTLE_FRONTIER_ITEM_SALAC_BERRY,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_ATTACK,
        .nature = NATURE_DOCILE,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_BRELOOM_2] = {
        .species = SPECIES_BRELOOM,
        .moves = {MOVE_GIGA_DRAIN, MOVE_LEECH_SEED, MOVE_FOCUS_PUNCH, MOVE_SPORE    },
        .itemTableId = BATTLE_FRONTIER_ITEM_BRIGHT_POWDER,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_DOCILE,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_FORRETRESS_2] = {
        .species = SPECIES_FORRETRESS,
        .moves = {MOVE_EARTHQUAKE, MOVE_DOUBLE_EDGE, MOVE_COUNTER, MOVE_PROTECT    },
        .itemTableId = BATTLE_FRONTIER_ITEM_LUM_BERRY,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_SKARMORY_2] = {
        .species = SPECIES_SKARMORY,
        .moves = {MOVE_SPIKES, MOVE_ROAR, MOVE_DRILL_PECK, MOVE_TOXIC    },
        .itemTableId = BATTLE_FRONTIER_ITEM_BRIGHT_POWDER,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_CAREFUL,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_WHISCASH_2] = {
        .species = SPECIES_WHISCASH,
        .moves = {MOVE_SURF, MOVE_EARTHQUAKE, MOVE_SPARK, MOVE_FUTURE_SIGHT    },
        .itemTableId = BATTLE_FRONTIER_ITEM_SHELL_BELL,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_ATTACK,
        .nature = NATURE_HARDY,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_XATU_2] = {
        .species = SPECIES_XATU,
        .moves = {MOVE_FLY, MOVE_TOXIC, MOVE_CONFUSE_RAY, MOVE_ATTRACT    },
        .itemTableId = BATTLE_FRONTIER_ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_IMPISH,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_CLEFABLE_2] = {
        .species = SPECIES_CLEFABLE,
        .moves = {MOVE_METEOR_MASH, MOVE_COSMIC_POWER, MOVE_DOUBLE_TEAM, MOVE_FOLLOW_ME    },
        .itemTableId = BATTLE_FRONTIER_ITEM_FOCUS_BAND,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_HARIYAMA_2] = {
        .species = SPECIES_HARIYAMA,
        .moves = {MOVE_CROSS_CHOP, MOVE_FIRE_PUNCH, MOVE_ICE_PUNCH, MOVE_THUNDER_PUNCH    },
        .itemTableId = BATTLE_FRONTIER_ITEM_QUICK_CLAW,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_ATTACK,
        .nature = NATURE_QUIET,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_RAICHU_2] = {
        .species = SPECIES_RAICHU_ALOLAN,
        .moves = {MOVE_THUNDERBOLT, MOVE_SURF, MOVE_GRASS_KNOT, MOVE_PSYSHOCK},
        .itemTableId = BATTLE_FRONTIER_ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
		.abilitynum = 2
    },
    [FRONTIER_MON_DEWGONG_2] = {
        .species = SPECIES_DEWGONG,
        .moves = {MOVE_BLIZZARD, MOVE_DOUBLE_EDGE, MOVE_ENCORE, MOVE_DISABLE    },
        .itemTableId = BATTLE_FRONTIER_ITEM_SHELL_BELL,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_ATTACK,
        .nature = NATURE_DOCILE,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_MANECTRIC_2] = {
        .species = SPECIES_MANECTRIC,
        .moves = {MOVE_THUNDER, MOVE_RAIN_DANCE, MOVE_CRUNCH, MOVE_ROAR    },
        .itemTableId = BATTLE_FRONTIER_ITEM_PETAYA_BERRY,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_VILEPLUME_2] = {
        .species = SPECIES_VILEPLUME,
        .moves = {MOVE_INGRAIN, MOVE_DOUBLE_TEAM, MOVE_TOXIC, MOVE_GIGA_DRAIN    },
        .itemTableId = BATTLE_FRONTIER_ITEM_BRIGHT_POWDER,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_BOLD,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_VICTREEBEL_2] = {
        .species = SPECIES_VICTREEBEL,
        .moves = {MOVE_GIGA_DRAIN, MOVE_SLUDGE_BOMB, MOVE_SLEEP_POWDER, MOVE_ATTRACT    },
        .itemTableId = BATTLE_FRONTIER_ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_ATTACK,
        .nature = NATURE_SERIOUS,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_ELECTRODE_2] = {
        .species = SPECIES_ELECTRODE,
        .moves = {MOVE_THUNDER, MOVE_RAIN_DANCE, MOVE_DOUBLE_TEAM, MOVE_SWAGGER    },
        .itemTableId = BATTLE_FRONTIER_ITEM_BRIGHT_POWDER,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_EXPLOUD_2] = {
        .species = SPECIES_EXPLOUD,//TO REMOVE
        .moves = {MOVE_BOOMBURST, MOVE_ICE_BEAM, MOVE_FIRE_BLAST, MOVE_THUNDERBOLT},
        .itemTableId = BATTLE_FRONTIER_ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_TIMID,
		.abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_SHIFTRY_2] = {
        .species = SPECIES_SHIFTRY,
        .moves = {MOVE_LEECH_SEED, MOVE_DIG, MOVE_DOUBLE_TEAM, MOVE_REST    },
        .itemTableId = BATTLE_FRONTIER_ITEM_CHESTO_BERRY,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_DEFENSE,
        .nature = NATURE_IMPISH,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_GLALIE_2] = {
        .species = SPECIES_GLALIE,
        .moves = {MOVE_EXPLOSION, MOVE_ENDURE, MOVE_BODY_SLAM, MOVE_ICY_WIND    },
        .itemTableId = BATTLE_FRONTIER_ITEM_SALAC_BERRY,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_QUIRKY,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_LUDICOLO_2] = {
        .species = SPECIES_LUDICOLO,//TO REMOVE
        .moves = {MOVE_HYDRO_PUMP, MOVE_ICE_BEAM, MOVE_GIGA_DRAIN, MOVE_SCALD},
        .itemTableId = BATTLE_FRONTIER_ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
		.abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_HYPNO_2] = {
        .species = SPECIES_HYPNO,
        .moves = {MOVE_HYPNOSIS, MOVE_NIGHTMARE, MOVE_DREAM_EATER, MOVE_PSYCHIC    },
        .itemTableId = BATTLE_FRONTIER_ITEM_TWISTED_SPOON,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_DEFENSE,
        .nature = NATURE_MODEST,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_GOLEM_2] = {
        .species = SPECIES_GOLEM,//ALOLAN
        .moves = {MOVE_EARTHQUAKE, MOVE_EXPLOSION, MOVE_STONE_EDGE, MOVE_STEALTH_ROCK},
        .itemTableId = BATTLE_FRONTIER_ITEM_WEAKNESS_POLICY,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
		.abilitynum = ABILITY_1
    },
    [FRONTIER_MON_RHYDON_2] = {
        .species = SPECIES_RHYPERIOR,
        .moves = {MOVE_STEALTH_ROCK, MOVE_ICE_PUNCH, MOVE_EARTHQUAKE, MOVE_ROCK_BLAST},
        .itemTableId = BATTLE_FRONTIER_ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
		.abilitynum = ABILITY_2
    },
    [FRONTIER_MON_ALAKAZAM_2] = {
        .species = SPECIES_ALAKAZAM,
        .moves = {MOVE_PSYCHIC, MOVE_CALM_MIND, MOVE_THUNDER_WAVE, MOVE_RECOVER    },
        .itemTableId = BATTLE_FRONTIER_ITEM_LUM_BERRY,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_DEFENSE,
        .nature = NATURE_MODEST,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_WEEZING_2] = {
        .species = SPECIES_WEEZING,
        .moves = {MOVE_MEMENTO, MOVE_SLUDGE_BOMB, MOVE_FACADE, MOVE_DESTINY_BOND    },
        .itemTableId = BATTLE_FRONTIER_ITEM_SITRUS_BERRY,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_KANGASKHAN_2] = {
        .species = SPECIES_KANGASKHAN,
        .moves = {MOVE_CRUSH_CLAW, MOVE_SHADOW_BALL, MOVE_ATTRACT, MOVE_REST    },
        .itemTableId = BATTLE_FRONTIER_ITEM_LUM_BERRY,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_ELECTABUZZ_2] = {
        .species = SPECIES_ELECTABUZZ,
        .moves = {MOVE_THUNDER, MOVE_RAIN_DANCE, MOVE_ATTRACT, MOVE_FOCUS_PUNCH    },
        .itemTableId = BATTLE_FRONTIER_ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_QUIRKY,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_TAUROS_2] = {
        .species = SPECIES_TAUROS,
        .moves = {MOVE_DOUBLE_EDGE, MOVE_EARTHQUAKE, MOVE_DOUBLE_TEAM, MOVE_REST    },
        .itemTableId = BATTLE_FRONTIER_ITEM_CHESTO_BERRY,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_SLOWBRO_2] = {
        .species = SPECIES_SLOWBRO,
        .moves = {MOVE_SURF, MOVE_ICE_BEAM, MOVE_CALM_MIND, MOVE_YAWN    },
        .itemTableId = BATTLE_FRONTIER_ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_ATTACK,
        .nature = NATURE_MODEST,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_SLOWKING_2] = {
        .species = SPECIES_SLOWKING,
        .moves = {MOVE_YAWN, MOVE_THUNDER_WAVE, MOVE_SURF, MOVE_PSYCHIC    },
        .itemTableId = BATTLE_FRONTIER_ITEM_SHELL_BELL,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_DEFENSE,
        .nature = NATURE_MODEST,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_MILTANK_2] = {
        .species = SPECIES_MILTANK,
        .moves = {MOVE_FOCUS_PUNCH, MOVE_SHADOW_BALL, MOVE_ATTRACT, MOVE_THUNDER_WAVE    },
        .itemTableId = BATTLE_FRONTIER_ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_CAREFUL,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_ALTARIA_2] = {
        .species = SPECIES_ALTARIA,
        .moves = {MOVE_PERISH_SONG, MOVE_DRAGON_BREATH, MOVE_PURSUIT, MOVE_ATTRACT    },
        .itemTableId = BATTLE_FRONTIER_ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_BOLD,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_NIDOQUEEN_2] = {
        .species = SPECIES_NIDOQUEEN,
        .moves = {MOVE_DOUBLE_EDGE, MOVE_EARTHQUAKE, MOVE_AERIAL_ACE, MOVE_ROCK_SLIDE    },
        .itemTableId = BATTLE_FRONTIER_ITEM_SHELL_BELL,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_NIDOKING_2] = {
        .species = SPECIES_NIDOKING,
        .moves = {MOVE_MEGA_KICK, MOVE_EARTHQUAKE, MOVE_SHADOW_BALL, MOVE_BRICK_BREAK    },
        .itemTableId = BATTLE_FRONTIER_ITEM_SHELL_BELL,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_MAGMAR_2] = {
        .species = SPECIES_MAGMAR,
        .moves = {MOVE_FIRE_BLAST, MOVE_SMOKESCREEN, MOVE_THUNDER_PUNCH, MOVE_CONFUSE_RAY    },
        .itemTableId = BATTLE_FRONTIER_ITEM_QUICK_CLAW,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_CRADILY_2] = {
        .species = SPECIES_CRADILY,
        .moves = {MOVE_EARTHQUAKE, MOVE_ANCIENT_POWER, MOVE_SWAGGER, MOVE_PSYCH_UP    },
        .itemTableId = BATTLE_FRONTIER_ITEM_SITRUS_BERRY,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_ARMALDO_2] = {
        .species = SPECIES_ARCHEOPS,
        .moves = {MOVE_STEALTH_ROCK, MOVE_HEAD_SMASH, MOVE_ENDEAVOR, MOVE_TAUNT},
        .itemTableId = BATTLE_FRONTIER_ITEM_FOCUS_SASH,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_JOLLY,
		.abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_GOLDUCK_2] = {
        .species = SPECIES_GOLDUCK,
        .moves = {MOVE_CROSS_CHOP, MOVE_SURF, MOVE_SWAGGER, MOVE_PSYCH_UP    },
        .itemTableId = BATTLE_FRONTIER_ITEM_LUM_BERRY,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_QUIRKY,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_RAPIDASH_2] = {
        .species = SPECIES_RAPIDASH,
        .moves = {MOVE_FIRE_BLAST, MOVE_BOUNCE, MOVE_DOUBLE_TEAM, MOVE_ATTRACT    },
        .itemTableId = BATTLE_FRONTIER_ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_DOCILE,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_MUK_2] = {
        .species = SPECIES_MUK,
        .moves = {MOVE_CURSE, MOVE_REST, MOVE_SLUDGE_BOMB, MOVE_DYNAMIC_PUNCH    },
        .itemTableId = BATTLE_FRONTIER_ITEM_CHESTO_BERRY,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_ATTACK,
        .nature = NATURE_HARDY,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_GENGAR_2] = {
        .species = SPECIES_GENGAR,//NOT MEGA
        .moves = {MOVE_SLUDGE_BOMB, MOVE_SHADOW_BALL, MOVE_THUNDERBOLT, MOVE_PSYCHIC},
        .itemTableId = BATTLE_FRONTIER_ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_SP_ATTACK,
        .nature = NATURE_TIMID,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_AMPHAROS_2] = {
        .species = SPECIES_AMPHAROS,
        .moves = {MOVE_THUNDER_PUNCH, MOVE_FIRE_PUNCH, MOVE_FOCUS_PUNCH, MOVE_THUNDER_WAVE    },
        .itemTableId = BATTLE_FRONTIER_ITEM_BRIGHT_POWDER,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_ATTACK,
        .nature = NATURE_HARDY,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_SCIZOR_2] = {
        .species = SPECIES_SCIZOR,
        .moves = {MOVE_SILVER_WIND, MOVE_STEEL_WING, MOVE_SWORDS_DANCE, MOVE_LIGHT_SCREEN    },
        .itemTableId = BATTLE_FRONTIER_ITEM_QUICK_CLAW,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_HERACROSS_2] = {//NOT MEGA
        .species = SPECIES_HERACROSS,
        .moves = {MOVE_CLOSE_COMBAT, MOVE_MEGAHORN, MOVE_EARTHQUAKE, MOVE_ROCK_SLIDE},
        .itemTableId = BATTLE_FRONTIER_ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_JOLLY,
		.abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_URSARING_2] = {
        .species = SPECIES_URSARING,//TO REMOVE
        .moves = {MOVE_SWORDS_DANCE, MOVE_FACADE, MOVE_PLAY_ROUGH, MOVE_FIRE_PUNCH},
        .itemTableId = BATTLE_FRONTIER_ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_JOLLY,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_HOUNDOOM_2] = {
        .species = SPECIES_HOUNDOOM,
        .moves = {MOVE_FIRE_BLAST, MOVE_CRUNCH, MOVE_ROAR, MOVE_REST    },
        .itemTableId = BATTLE_FRONTIER_ITEM_LUM_BERRY,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_DONPHAN_2] = {
        .species = SPECIES_DONPHAN,
        .moves = {MOVE_FLAIL, MOVE_ENDURE, MOVE_EARTHQUAKE, MOVE_ROCK_TOMB    },
        .itemTableId = BATTLE_FRONTIER_ITEM_QUICK_CLAW,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_CLAYDOL_2] = {
        .species = SPECIES_CLAYDOL,
        .moves = {MOVE_PSYCHIC, MOVE_EARTHQUAKE, MOVE_DOUBLE_TEAM, MOVE_COSMIC_POWER    },
        .itemTableId = BATTLE_FRONTIER_ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_CALM,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_WAILORD_2] = {
        .species = SPECIES_WAILORD,
        .moves = {MOVE_DOUBLE_EDGE, MOVE_REST, MOVE_CURSE, MOVE_AMNESIA    },
        .itemTableId = BATTLE_FRONTIER_ITEM_CHESTO_BERRY,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_NINETALES_2] = {
        .species = SPECIES_NINETALES_ALOLAN,
        .moves = {MOVE_AURORA_VEIL, MOVE_MOONBLAST, MOVE_ICE_BEAM, MOVE_SHADOW_BALL},
        .itemTableId = BATTLE_FRONTIER_ITEM_ICY_ROCK,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
		.abilitynum = 2
    },
    [FRONTIER_MON_MACHAMP_2] = {
        .species = SPECIES_MACHAMP,
        .moves = {MOVE_CROSS_CHOP, MOVE_EARTHQUAKE, MOVE_BULK_UP, MOVE_REST    },
        .itemTableId = BATTLE_FRONTIER_ITEM_CHESTO_BERRY,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_SHUCKLE_2] = {
        .species = SPECIES_SHUCKLE,
        .moves = {MOVE_SANDSTORM, MOVE_DIG, MOVE_FLASH, MOVE_DOUBLE_TEAM    },
        .itemTableId = BATTLE_FRONTIER_ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_DEFENSE,
        .nature = NATURE_CAREFUL,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_STEELIX_2] = {
        .species = SPECIES_STEELIX,
        .moves = {MOVE_EARTHQUAKE, MOVE_DRAGON_BREATH, MOVE_SANDSTORM, MOVE_BLOCK    },
        .itemTableId = BATTLE_FRONTIER_ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_ATTACK,
        .nature = NATURE_HARDY,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_TENTACRUEL_2] = {
        .species = SPECIES_TENTACRUEL,
        .moves = {MOVE_TOXIC, MOVE_GIGA_DRAIN, MOVE_CONFUSE_RAY, MOVE_SURF    },
        .itemTableId = BATTLE_FRONTIER_ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_HARDY,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_AERODACTYL_2] = {
        .species = SPECIES_AERODACTYL,
        .moves = {MOVE_HYPER_BEAM, MOVE_EARTHQUAKE, MOVE_AERIAL_ACE, MOVE_ANCIENT_POWER    },
        .itemTableId = BATTLE_FRONTIER_ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_PORYGON2_2] = {
        .species = SPECIES_PORYGON_Z,//
        .moves = {MOVE_TRI_ATTACK, MOVE_ICE_BEAM, MOVE_THUNDERBOLT, MOVE_RECOVER},
        .itemTableId = BATTLE_FRONTIER_ITEM_CHOICE_SCARF,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
		.abilitynum = ABILITY_1
    },
    [FRONTIER_MON_GARDEVOIR_2] = {
        .species = SPECIES_GALLADE,//MEGA
        .moves = {MOVE_CLOSE_COMBAT, MOVE_ZEN_HEADBUTT, MOVE_LEAF_BLADE, MOVE_EARTHQUAKE},
        .itemTableId = BATTLE_FRONTIER_ITEM_GALLADITE,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_JOLLY,
		.abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_EXEGGUTOR_2] = {
        .species = SPECIES_EXEGGUTOR,
        .moves = {MOVE_RETURN, MOVE_CURSE, MOVE_SLEEP_POWDER, MOVE_REST    },
        .itemTableId = BATTLE_FRONTIER_ITEM_CHESTO_BERRY,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_ATTACK,
        .nature = NATURE_HARDY,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_STARMIE_2] = {
        .species = SPECIES_STARMIE,
        .moves = {MOVE_HYDRO_PUMP, MOVE_THUNDER, MOVE_RAIN_DANCE, MOVE_RECOVER    },
        .itemTableId = BATTLE_FRONTIER_ITEM_SHELL_BELL,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_FLYGON_2] = {
        .species = SPECIES_FLYGON,
        .moves = {MOVE_SOLAR_BEAM, MOVE_FIRE_BLAST, MOVE_CRUNCH, MOVE_SUNNY_DAY    },
        .itemTableId = BATTLE_FRONTIER_ITEM_BRIGHT_POWDER,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_VENUSAUR_2] = {
        .species = SPECIES_VENUSAUR,
        .moves = {MOVE_LEECH_SEED, MOVE_GIGA_DRAIN, MOVE_DOUBLE_TEAM, MOVE_LIGHT_SCREEN    },
        .itemTableId = BATTLE_FRONTIER_ITEM_BRIGHT_POWDER,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_BOLD,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_VAPOREON_2] = {
        .species = SPECIES_VAPOREON,
        .moves = {MOVE_SURF, MOVE_ICE_BEAM, MOVE_BODY_SLAM, MOVE_SHADOW_BALL    },
        .itemTableId = BATTLE_FRONTIER_ITEM_SHELL_BELL,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_DOCILE,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_JOLTEON_2] = {//TO REMOVE
        .species = SPECIES_JOLTEON,
        .moves = {MOVE_VOLT_SWITCH, MOVE_SHADOW_BALL, MOVE_THUNDERBOLT, MOVE_HIDDEN_POWER},
        .itemTableId = BATTLE_FRONTIER_ITEM_CHOICE_SPECS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
		.abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_FLAREON_2] = {
        .species = SPECIES_FLAREON,
        .moves = {MOVE_CURSE, MOVE_ATTRACT, MOVE_DOUBLE_EDGE, MOVE_SHADOW_BALL    },
        .itemTableId = BATTLE_FRONTIER_ITEM_QUICK_CLAW,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_RELAXED,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_MEGANIUM_2] = {
        .species = SPECIES_MEGANIUM,
        .moves = {MOVE_LEECH_SEED, MOVE_SUBSTITUTE, MOVE_DOUBLE_TEAM, MOVE_GRASS_WHISTLE    },
        .itemTableId = BATTLE_FRONTIER_ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_CALM,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_ESPEON_2] = {
        .species = SPECIES_ESPEON,
        .moves = {MOVE_PSYCHIC, MOVE_SHADOW_BALL, MOVE_CALM_MIND, MOVE_REST    },
        .itemTableId = BATTLE_FRONTIER_ITEM_CHESTO_BERRY,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_DOCILE,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_UMBREON_2] = {
        .species = SPECIES_UMBREON,
        .moves = {MOVE_CURSE, MOVE_SCREECH, MOVE_DOUBLE_TEAM, MOVE_DOUBLE_EDGE    },
        .itemTableId = BATTLE_FRONTIER_ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_BLASTOISE_2] = {
        .species = SPECIES_BLASTOISE,
        .moves = {MOVE_AURA_SPHERE, MOVE_SHELL_SMASH, MOVE_ICE_BEAM, MOVE_SCALD},
        .itemTableId = BATTLE_FRONTIER_ITEM_WHITE_HERB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_FERALIGATR_2] = {
        .species = SPECIES_FERALIGATR,
        .moves = {MOVE_SURF, MOVE_DRAGON_CLAW, MOVE_BRICK_BREAK, MOVE_SCARY_FACE    },
        .itemTableId = BATTLE_FRONTIER_ITEM_QUICK_CLAW,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_SASSY,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_AGGRON_2] = {
        .species = SPECIES_AGGRON,
        .moves = {MOVE_FOCUS_PUNCH, MOVE_EARTHQUAKE, MOVE_ROCK_SLIDE, MOVE_THUNDER_WAVE    },
        .itemTableId = BATTLE_FRONTIER_ITEM_SCOPE_LENS,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_BLAZIKEN_2] = {
        .species = SPECIES_BLAZIKEN,
        .moves = {MOVE_BLAZE_KICK, MOVE_MEGA_KICK, MOVE_THUNDER_PUNCH, MOVE_BRICK_BREAK    },
        .itemTableId = BATTLE_FRONTIER_ITEM_SCOPE_LENS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_ATTACK,
        .nature = NATURE_DOCILE,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_WALREIN_2] = {
        .species = SPECIES_WALREIN,
        .moves = {MOVE_EARTHQUAKE, MOVE_ICE_BEAM, MOVE_CURSE, MOVE_DOUBLE_TEAM    },
        .itemTableId = BATTLE_FRONTIER_ITEM_FOCUS_BAND,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_QUIRKY,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_SCEPTILE_2] = {
        .species = SPECIES_SCEPTILE,
        .moves = {MOVE_LEAF_BLADE, MOVE_THUNDER_PUNCH, MOVE_ATTRACT, MOVE_DOUBLE_TEAM    },
        .itemTableId = BATTLE_FRONTIER_ITEM_LUM_BERRY,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_CHARIZARD_2] = {
        .species = SPECIES_CHARIZARD,
        .moves = {MOVE_EARTHQUAKE, MOVE_AERIAL_ACE, MOVE_DRAGON_DANCE, MOVE_SMOKESCREEN    },
        .itemTableId = BATTLE_FRONTIER_ITEM_BRIGHT_POWDER,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_TYPHLOSION_2] = {
        .species = SPECIES_TYPHLOSION,
        .moves = {MOVE_FLAMETHROWER, MOVE_THUNDER_PUNCH, MOVE_AERIAL_ACE, MOVE_ROCK_SLIDE    },
        .itemTableId = BATTLE_FRONTIER_ITEM_SCOPE_LENS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_HARDY,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_LAPRAS_2] = {
        .species = SPECIES_LAPRAS,
        .moves = {MOVE_SURF, MOVE_ICE_BEAM, MOVE_BODY_SLAM, MOVE_ROAR    },
        .itemTableId = BATTLE_FRONTIER_ITEM_QUICK_CLAW,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_CROBAT_2] = {
        .species = SPECIES_CROBAT,
        .moves = {MOVE_TOXIC, MOVE_GIGA_DRAIN, MOVE_CONFUSE_RAY, MOVE_DOUBLE_TEAM    },
        .itemTableId = BATTLE_FRONTIER_ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_CALM,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_SWAMPERT_2] = {
        .species = SPECIES_SWAMPERT,
        .moves = {MOVE_SURF, MOVE_EARTHQUAKE, MOVE_COUNTER, MOVE_MIRROR_COAT    },
        .itemTableId = BATTLE_FRONTIER_ITEM_QUICK_CLAW,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_DOCILE,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_GYARADOS_2] = {
        .species = SPECIES_GYARADOS,
        .moves = {MOVE_HYDRO_PUMP, MOVE_THUNDERBOLT, MOVE_FIRE_BLAST, MOVE_BLIZZARD    },
        .itemTableId = BATTLE_FRONTIER_ITEM_SHELL_BELL,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_SNORLAX_2] = {
        .species = SPECIES_SNORLAX,
        .moves = {MOVE_EARTHQUAKE, MOVE_ROCK_SLIDE, MOVE_CURSE, MOVE_REST    },
        .itemTableId = BATTLE_FRONTIER_ITEM_CHESTO_BERRY,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_KINGDRA_2] = {
        .species = SPECIES_KINGDRA,
        .moves = {MOVE_SURF, MOVE_ICE_BEAM, MOVE_DRAGON_BREATH, MOVE_REST    },
        .itemTableId = BATTLE_FRONTIER_ITEM_CHESTO_BERRY,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_BLISSEY_2] = {
        .species = SPECIES_BLISSEY,
        .moves = {MOVE_SEISMIC_TOSS, MOVE_SING, MOVE_ATTRACT, MOVE_SUBSTITUTE    },
        .itemTableId = BATTLE_FRONTIER_ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_DEFENSE,
        .nature = NATURE_BOLD,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_MILOTIC_2] = {
        .species = SPECIES_MILOTIC,
        .moves = {MOVE_SURF, MOVE_ICE_BEAM, MOVE_SAFEGUARD, MOVE_MIRROR_COAT    },
        .itemTableId = BATTLE_FRONTIER_ITEM_FOCUS_BAND,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_ARCANINE_2] = {
        .species = SPECIES_ARCANINE,
        .moves = {MOVE_FIRE_BLAST, MOVE_SUNNY_DAY, MOVE_CRUNCH, MOVE_ROAR    },
        .itemTableId = BATTLE_FRONTIER_ITEM_LUM_BERRY,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_DOCILE,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_SALAMENCE_2] = {
        .species = SPECIES_HAXORUS,
        .moves = {MOVE_POISON_JAB, MOVE_EARTHQUAKE, MOVE_OUTRAGE, MOVE_DRAGON_CLAW},
        .itemTableId = BATTLE_FRONTIER_ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_METAGROSS_2] = {
        .species = SPECIES_METAGROSS,
        .moves = {MOVE_EARTHQUAKE, MOVE_METEOR_MASH, MOVE_PSYCH_UP, MOVE_SWAGGER    },
        .itemTableId = BATTLE_FRONTIER_ITEM_LUM_BERRY,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_SPEED | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_SLAKING_2] = {
        .species = SPECIES_SLAKING,
        .moves = {MOVE_MEGA_KICK, MOVE_SHADOW_BALL, MOVE_YAWN, MOVE_AMNESIA    },
        .itemTableId = BATTLE_FRONTIER_ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_DEFENSE,
        .nature = NATURE_ADAMANT,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_DUGTRIO_3] = {
        .species = SPECIES_DUGTRIO,//TO REMOVE
        .moves = {MOVE_EARTHQUAKE, MOVE_SUCKER_PUNCH, MOVE_REVERSAL, MOVE_ROCK_SLIDE},
        .itemTableId = BATTLE_FRONTIER_ITEM_FOCUS_SASH,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_MEDICHAM_3] = {
        .species = SPECIES_MEDICHAM,
        .moves = {MOVE_DYNAMIC_PUNCH, MOVE_THUNDER_PUNCH, MOVE_ICE_PUNCH, MOVE_FIRE_PUNCH    },
        .itemTableId = BATTLE_FRONTIER_ITEM_SCOPE_LENS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_HARDY,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_MISDREAVUS_3] = {
        .species = SPECIES_MISDREAVUS,
        .moves = {MOVE_PERISH_SONG, MOVE_MEAN_LOOK, MOVE_THUNDER_WAVE, MOVE_CONFUSE_RAY    },
        .itemTableId = BATTLE_FRONTIER_ITEM_BRIGHT_POWDER,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_BOLD,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_FEAROW_3] = {
        .species = SPECIES_FEAROW,
        .moves = {MOVE_DRILL_PECK, MOVE_RETURN, MOVE_STEEL_WING, MOVE_FAINT_ATTACK    },
        .itemTableId = BATTLE_FRONTIER_ITEM_SCOPE_LENS,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_HARDY,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_GRANBULL_3] = {
        .species = SPECIES_GRANBULL,
        .moves = {MOVE_DOUBLE_EDGE, MOVE_EARTHQUAKE, MOVE_SLUDGE_BOMB, MOVE_ROCK_SLIDE    },
        .itemTableId = BATTLE_FRONTIER_ITEM_QUICK_CLAW,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_JYNX_3] = {
        .species = SPECIES_JYNX,
        .moves = {MOVE_DREAM_EATER, MOVE_LOVELY_KISS, MOVE_ATTRACT, MOVE_SUBSTITUTE    },
        .itemTableId = BATTLE_FRONTIER_ITEM_QUICK_CLAW,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_HARDY,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_DUSCLOPS_3] = {
        .species = SPECIES_DUSKNOIR,//TO REMOVE
        .moves = {MOVE_WILL_O_WISP, MOVE_PAIN_SPLIT, MOVE_SHADOW_SNEAK, MOVE_ICE_PUNCH},
        .itemTableId = BATTLE_FRONTIER_ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
		.abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_DODRIO_3] = {
        .species = SPECIES_DODRIO,
        .moves = {MOVE_DOUBLE_EDGE, MOVE_DRILL_PECK, MOVE_STEEL_WING, MOVE_FAINT_ATTACK    },
        .itemTableId = BATTLE_FRONTIER_ITEM_LUM_BERRY,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_MR_MIME_3] = {
        .species = SPECIES_MR_MIME,
        .moves = {MOVE_TRICK, MOVE_TORMENT, MOVE_PSYCHIC, MOVE_THUNDERBOLT    },
        .itemTableId = BATTLE_FRONTIER_ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_LANTURN_3] = {
        .species = SPECIES_LANTURN,
        .moves = {MOVE_HYDRO_PUMP, MOVE_THUNDER, MOVE_CONFUSE_RAY, MOVE_RAIN_DANCE    },
        .itemTableId = BATTLE_FRONTIER_ITEM_BRIGHT_POWDER,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_BRELOOM_3] = {
        .species = SPECIES_BRELOOM,
        .moves = {MOVE_IRON_TAIL, MOVE_FOCUS_PUNCH, MOVE_ATTRACT, MOVE_SPORE    },
        .itemTableId = BATTLE_FRONTIER_ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_FORRETRESS_3] = {
        .species = SPECIES_FORRETRESS,
        .moves = {MOVE_EXPLOSION, MOVE_EARTHQUAKE, MOVE_GIGA_DRAIN, MOVE_ZAP_CANNON    },
        .itemTableId = BATTLE_FRONTIER_ITEM_FOCUS_BAND,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_ATTACK,
        .nature = NATURE_QUIET,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_WHISCASH_3] = {
        .species = SPECIES_WHISCASH,
        .moves = {MOVE_SLEEP_TALK, MOVE_REST, MOVE_SURF, MOVE_FISSURE    },
        .itemTableId = BATTLE_FRONTIER_ITEM_CHESTO_BERRY,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_DEFENSE,
        .nature = NATURE_HARDY,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_XATU_3] = {
        .species = SPECIES_XATU,
        .moves = {MOVE_DRILL_PECK, MOVE_PSYCHIC, MOVE_GIGA_DRAIN, MOVE_STEEL_WING    },
        .itemTableId = BATTLE_FRONTIER_ITEM_KINGS_ROCK,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_SKARMORY_3] = {
        .species = SPECIES_SKARMORY,
        .moves = {MOVE_TOXIC, MOVE_CURSE, MOVE_REST, MOVE_FLY    },
        .itemTableId = BATTLE_FRONTIER_ITEM_CHESTO_BERRY,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_CAREFUL,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_MAROWAK_3] = {
        .species = SPECIES_MAROWAK,
        .moves = {MOVE_EARTHQUAKE, MOVE_ROCK_SLIDE, MOVE_SWORDS_DANCE, MOVE_BRICK_BREAK    },
        .itemTableId = BATTLE_FRONTIER_ITEM_THICK_CLUB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_QUAGSIRE_3] = {
        .species = SPECIES_QUAGSIRE,
        .moves = {MOVE_EARTHQUAKE, MOVE_SLUDGE_BOMB, MOVE_DOUBLE_EDGE, MOVE_CURSE    },
        .itemTableId = BATTLE_FRONTIER_ITEM_QUICK_CLAW,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_CLEFABLE_3] = {
        .species = SPECIES_CLEFABLE,
        .moves = {MOVE_THUNDERBOLT, MOVE_ICE_BEAM, MOVE_FLAMETHROWER, MOVE_MAGICAL_LEAF    },
        .itemTableId = BATTLE_FRONTIER_ITEM_LUM_BERRY,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_DEFENSE,
        .nature = NATURE_MODEST,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_HARIYAMA_3] = {
        .species = SPECIES_HARIYAMA,
        .moves = {MOVE_CROSS_CHOP, MOVE_EARTHQUAKE, MOVE_ROCK_SLIDE, MOVE_FACADE    },
        .itemTableId = BATTLE_FRONTIER_ITEM_QUICK_CLAW,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_RAICHU_3] = {
        .species = SPECIES_RAICHU,
        .moves = {MOVE_THUNDER, MOVE_RAIN_DANCE, MOVE_IRON_TAIL, MOVE_ATTRACT    },
        .itemTableId = BATTLE_FRONTIER_ITEM_CHERI_BERRY,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_DOCILE,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_DEWGONG_3] = {
        .species = SPECIES_DEWGONG,
        .moves = {MOVE_HORN_DRILL, MOVE_SHEER_COLD, MOVE_SLEEP_TALK, MOVE_REST    },
        .itemTableId = BATTLE_FRONTIER_ITEM_CHESTO_BERRY,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_BOLD,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_MANECTRIC_3] = {
        .species = SPECIES_MANECTRIC,
        .moves = {MOVE_THUNDERBOLT, MOVE_IRON_TAIL, MOVE_THUNDER_WAVE, MOVE_ROAR    },
        .itemTableId = BATTLE_FRONTIER_ITEM_LUM_BERRY,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_QUIRKY,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_VILEPLUME_3] = {
        .species = SPECIES_VILEPLUME,
        .moves = {MOVE_ATTRACT, MOVE_STUN_SPORE, MOVE_SLUDGE_BOMB, MOVE_GIGA_DRAIN    },
        .itemTableId = BATTLE_FRONTIER_ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_ATTACK,
        .nature = NATURE_QUIRKY,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_VICTREEBEL_3] = {
        .species = SPECIES_VICTREEBEL,
        .moves = {MOVE_STUN_SPORE, MOVE_INGRAIN, MOVE_GIGA_DRAIN, MOVE_SLUDGE_BOMB    },
        .itemTableId = BATTLE_FRONTIER_ITEM_BRIGHT_POWDER,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_ATTACK,
        .nature = NATURE_QUIRKY,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_ELECTRODE_3] = {
        .species = SPECIES_ELECTRODE,
        .moves = {MOVE_EXPLOSION, MOVE_THUNDERBOLT, MOVE_THUNDER_WAVE, MOVE_ENDURE    },
        .itemTableId = BATTLE_FRONTIER_ITEM_LIECHI_BERRY,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_ATTACK,
        .nature = NATURE_NAUGHTY,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_EXPLOUD_3] = {
        .species = SPECIES_EXPLOUD,//TO REMOVE
        .moves = {MOVE_BOOMBURST, MOVE_ICE_BEAM, MOVE_FIRE_BLAST, MOVE_THUNDERBOLT},
        .itemTableId = BATTLE_FRONTIER_ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_TIMID,
		.abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_SHIFTRY_3] = {
        .species = SPECIES_SHIFTRY,
        .moves = {MOVE_SOLAR_BEAM, MOVE_SUNNY_DAY, MOVE_EXPLOSION, MOVE_SYNTHESIS    },
        .itemTableId = BATTLE_FRONTIER_ITEM_FOCUS_BAND,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_ATTACK,
        .nature = NATURE_QUIRKY,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_GLALIE_3] = {
        .species = SPECIES_GLALIE,
        .moves = {MOVE_BLIZZARD, MOVE_EARTHQUAKE, MOVE_DOUBLE_EDGE, MOVE_SHADOW_BALL    },
        .itemTableId = BATTLE_FRONTIER_ITEM_SHELL_BELL,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_HARDY,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_LUDICOLO_3] = {
		.species = SPECIES_LUDICOLO,//TO REMOVE
        .moves = {MOVE_HYDRO_PUMP, MOVE_ICE_BEAM, MOVE_GIGA_DRAIN, MOVE_SCALD},
        .itemTableId = BATTLE_FRONTIER_ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
		.abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_HYPNO_3] = {
        .species = SPECIES_HYPNO,
        .moves = {MOVE_PSYCH_UP, MOVE_SWAGGER, MOVE_MEGA_KICK, MOVE_SHADOW_BALL    },
        .itemTableId = BATTLE_FRONTIER_ITEM_LUM_BERRY,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_GOLEM_3] = {
        .species = SPECIES_GOLEM,//TO REMOVE
        .moves = {MOVE_EARTHQUAKE, MOVE_EXPLOSION, MOVE_STONE_EDGE, MOVE_STEALTH_ROCK},
        .itemTableId = BATTLE_FRONTIER_ITEM_WEAKNESS_POLICY,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
		.abilitynum = ABILITY_1
    },
    [FRONTIER_MON_RHYDON_3] = {
        .species = SPECIES_RHYPERIOR,//TO REMOVE
        .moves = {MOVE_STEALTH_ROCK, MOVE_ICE_PUNCH, MOVE_EARTHQUAKE, MOVE_ROCK_BLAST},
        .itemTableId = BATTLE_FRONTIER_ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
		.abilitynum = ABILITY_2
    },
    [FRONTIER_MON_ALAKAZAM_3] = {
        .species = SPECIES_ALAKAZAM,
        .moves = {MOVE_TRICK, MOVE_DISABLE, MOVE_PSYCHIC, MOVE_SKILL_SWAP    },
        .itemTableId = BATTLE_FRONTIER_ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_DEFENSE,
        .nature = NATURE_MODEST,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_WEEZING_3] = {
        .species = SPECIES_WEEZING,
        .moves = {MOVE_EXPLOSION, MOVE_SLUDGE_BOMB, MOVE_FLAMETHROWER, MOVE_THUNDERBOLT    },
        .itemTableId = BATTLE_FRONTIER_ITEM_FOCUS_BAND,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_ATTACK,
        .nature = NATURE_QUIRKY,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_KANGASKHAN_3] = {
        .species = SPECIES_KANGASKHAN,
        .moves = {MOVE_REVERSAL, MOVE_ENDURE, MOVE_THUNDERBOLT, MOVE_EARTHQUAKE    },
        .itemTableId = BATTLE_FRONTIER_ITEM_SALAC_BERRY,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_ELECTABUZZ_3] = {
        .species = SPECIES_ELECTABUZZ,
        .moves = {MOVE_FIRE_PUNCH, MOVE_ICE_PUNCH, MOVE_THUNDERBOLT, MOVE_CROSS_CHOP    },
        .itemTableId = BATTLE_FRONTIER_ITEM_LUM_BERRY,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_QUIRKY,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_TAUROS_3] = {
        .species = SPECIES_TAUROS,
        .moves = {MOVE_DOUBLE_EDGE, MOVE_EARTHQUAKE, MOVE_FLAMETHROWER, MOVE_ICE_BEAM    },
        .itemTableId = BATTLE_FRONTIER_ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_ATTACK,
        .nature = NATURE_DOCILE,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_SLOWBRO_3] = {
        .species = SPECIES_SLOWBRO,
        .moves = {MOVE_SURF, MOVE_PSYCHIC, MOVE_SHADOW_BALL, MOVE_ATTRACT    },
        .itemTableId = BATTLE_FRONTIER_ITEM_QUICK_CLAW,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_SP_ATTACK,
        .nature = NATURE_QUIET,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_SLOWKING_3] = {
        .species = SPECIES_SLOWKING,
        .moves = {MOVE_PSYCHIC, MOVE_SURF, MOVE_ICE_BEAM, MOVE_EARTHQUAKE    },
        .itemTableId = BATTLE_FRONTIER_ITEM_QUICK_CLAW,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_DEFENSE | F_EV_SPREAD_ATTACK,
        .nature = NATURE_QUIET,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_MILTANK_3] = {
        .species = SPECIES_MILTANK,
        .moves = {MOVE_REVERSAL, MOVE_ENDURE, MOVE_EARTHQUAKE, MOVE_SHADOW_BALL    },
        .itemTableId = BATTLE_FRONTIER_ITEM_SALAC_BERRY,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_ALTARIA_3] = {
        .species = SPECIES_ALTARIA,
        .moves = {MOVE_SING, MOVE_DRAGON_DANCE, MOVE_EARTHQUAKE, MOVE_AERIAL_ACE    },
        .itemTableId = BATTLE_FRONTIER_ITEM_LUM_BERRY,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_NIDOQUEEN_3] = {
        .species = SPECIES_NIDOQUEEN,
        .moves = {MOVE_THUNDERBOLT, MOVE_FLAMETHROWER, MOVE_ICE_BEAM, MOVE_CRUNCH    },
        .itemTableId = BATTLE_FRONTIER_ITEM_LUM_BERRY,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_NIDOKING_3] = {
        .species = SPECIES_NIDOKING,
        .moves = {MOVE_HORN_DRILL, MOVE_FIRE_BLAST, MOVE_BLIZZARD, MOVE_SURF    },
        .itemTableId = BATTLE_FRONTIER_ITEM_LEPPA_BERRY,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_MAGMAR_3] = {
        .species = SPECIES_MAGMAR,
        .moves = {MOVE_MEGA_KICK, MOVE_CROSS_CHOP, MOVE_IRON_TAIL, MOVE_COUNTER    },
        .itemTableId = BATTLE_FRONTIER_ITEM_SCOPE_LENS,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_ATTACK,
        .nature = NATURE_IMPISH,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_CRADILY_3] = {
        .species = SPECIES_CRADILY,
        .moves = {MOVE_SUBSTITUTE, MOVE_SOLAR_BEAM, MOVE_SUNNY_DAY, MOVE_RECOVER    },
        .itemTableId = BATTLE_FRONTIER_ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_DEFENSE,
        .nature = NATURE_MODEST,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_ARMALDO_3] = {
        .species = SPECIES_ARMALDO,
        .moves = {MOVE_EARTHQUAKE, MOVE_ROCK_SLIDE, MOVE_BRICK_BREAK, MOVE_SWORDS_DANCE    },
        .itemTableId = BATTLE_FRONTIER_ITEM_QUICK_CLAW,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_GOLDUCK_3] = {
        .species = SPECIES_GOLDUCK,
        .moves = {MOVE_HYDRO_PUMP, MOVE_CROSS_CHOP, MOVE_BLIZZARD, MOVE_PROTECT    },
        .itemTableId = BATTLE_FRONTIER_ITEM_SHELL_BELL,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_ATTACK,
        .nature = NATURE_DOCILE,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_RAPIDASH_3] = {
        .species = SPECIES_RAPIDASH,
        .moves = {MOVE_OVERHEAT, MOVE_SOLAR_BEAM, MOVE_SUNNY_DAY, MOVE_HYPNOSIS    },
        .itemTableId = BATTLE_FRONTIER_ITEM_WHITE_HERB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_MUK_3] = {
        .species = SPECIES_MUK,
        .moves = {MOVE_SLUDGE_BOMB, MOVE_THUNDERBOLT, MOVE_FLAMETHROWER, MOVE_ICE_PUNCH    },
        .itemTableId = BATTLE_FRONTIER_ITEM_LUM_BERRY,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_DEFENSE,
        .nature = NATURE_QUIET,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_GENGAR_3] = {
        .species = SPECIES_DOUBLADE,
        .moves = {MOVE_SWORDS_DANCE, MOVE_SHADOW_SNEAK, MOVE_SACRED_SWORD, MOVE_GYRO_BALL},
        .itemTableId = BATTLE_FRONTIER_ITEM_EVIOLITE,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
		.abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_AMPHAROS_3] = {
        .species = SPECIES_AMPHAROS,
        .moves = {MOVE_THUNDERBOLT, MOVE_MEGA_KICK, MOVE_IRON_TAIL, MOVE_BRICK_BREAK    },
        .itemTableId = BATTLE_FRONTIER_ITEM_FOCUS_BAND,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_ATTACK,
        .nature = NATURE_HARDY,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_SCIZOR_3] = {
        .species = SPECIES_SCIZOR,
        .moves = {MOVE_REVERSAL, MOVE_ENDURE, MOVE_AGILITY, MOVE_SLASH    },
        .itemTableId = BATTLE_FRONTIER_ITEM_FOCUS_BAND,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_ATTACK,
        .nature = NATURE_CAREFUL,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_HERACROSS_3] = {
        .species = SPECIES_HERACROSS,
        .moves = {MOVE_MEGAHORN, MOVE_EARTHQUAKE, MOVE_ROCK_SLIDE, MOVE_BRICK_BREAK    },
        .itemTableId = BATTLE_FRONTIER_ITEM_BRIGHT_POWDER,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_URSARING_3] = {
        .species = SPECIES_URSARING,//TO REMOVE
        .moves = {MOVE_SWORDS_DANCE, MOVE_FACADE, MOVE_PLAY_ROUGH, MOVE_FIRE_PUNCH},
        .itemTableId = BATTLE_FRONTIER_ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_JOLLY,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_HOUNDOOM_3] = {
        .species = SPECIES_HOUNDOOM,
        .moves = {MOVE_OVERHEAT, MOVE_SHADOW_BALL, MOVE_SLUDGE_BOMB, MOVE_DOUBLE_EDGE    },
        .itemTableId = BATTLE_FRONTIER_ITEM_WHITE_HERB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_QUIRKY,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_DONPHAN_3] = {
        .species = SPECIES_DONPHAN,
        .moves = {MOVE_FISSURE, MOVE_EARTHQUAKE, MOVE_ROCK_SLIDE, MOVE_SECRET_POWER    },
        .itemTableId = BATTLE_FRONTIER_ITEM_QUICK_CLAW,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_CLAYDOL_3] = {
        .species = SPECIES_CLAYDOL,
        .moves = {MOVE_PSYCHIC, MOVE_ICE_BEAM, MOVE_SOLAR_BEAM, MOVE_SUNNY_DAY    },
        .itemTableId = BATTLE_FRONTIER_ITEM_SHELL_BELL,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_WAILORD_3] = {
        .species = SPECIES_WAILORD,
        .moves = {MOVE_HYDRO_PUMP, MOVE_FISSURE, MOVE_DOUBLE_TEAM, MOVE_REST    },
        .itemTableId = BATTLE_FRONTIER_ITEM_CHESTO_BERRY,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_NINETALES_3] = {
        .species = SPECIES_NINETALES,//TO REMOVE
        .moves = {MOVE_WILL_O_WISP, MOVE_SOLAR_BEAM, MOVE_FIRE_BLAST, MOVE_SHADOW_BALL},
        .itemTableId = BATTLE_FRONTIER_ITEM_HEAT_ROCK,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
		.abilitynum = 2
    },
    [FRONTIER_MON_MACHAMP_3] = {
        .species = SPECIES_MACHAMP,
        .moves = {MOVE_CROSS_CHOP, MOVE_FIRE_BLAST, MOVE_THUNDER_PUNCH, MOVE_ICE_PUNCH    },
        .itemTableId = BATTLE_FRONTIER_ITEM_QUICK_CLAW,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_ATTACK,
        .nature = NATURE_HARDY,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_SHUCKLE_3] = {
        .species = SPECIES_SHUCKLE,
        .moves = {MOVE_SUBSTITUTE, MOVE_ATTRACT, MOVE_TOXIC, MOVE_DOUBLE_TEAM    },
        .itemTableId = BATTLE_FRONTIER_ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_DEFENSE,
        .nature = NATURE_CAREFUL,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_STEELIX_3] = {
        .species = SPECIES_STEELIX,
        .moves = {MOVE_EARTHQUAKE, MOVE_BODY_SLAM, MOVE_ROCK_SLIDE, MOVE_EXPLOSION    },
        .itemTableId = BATTLE_FRONTIER_ITEM_QUICK_CLAW,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_TENTACRUEL_3] = {
        .species = SPECIES_TENTACRUEL,
        .moves = {MOVE_SURF, MOVE_GIGA_DRAIN, MOVE_ICE_BEAM, MOVE_MIRROR_COAT    },
        .itemTableId = BATTLE_FRONTIER_ITEM_SHELL_BELL,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED | F_EV_SPREAD_DEFENSE,
        .nature = NATURE_MODEST,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_AERODACTYL_3] = {
        .species = SPECIES_AERODACTYL,
        .moves = {MOVE_DOUBLE_EDGE, MOVE_ROCK_SLIDE, MOVE_FIRE_BLAST, MOVE_DRAGON_CLAW    },
        .itemTableId = BATTLE_FRONTIER_ITEM_KINGS_ROCK,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_ATTACK,
        .nature = NATURE_HARDY,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_PORYGON2_3] = {
        .species = SPECIES_PORYGON_Z,//TO REMOVE
        .moves = {MOVE_TRI_ATTACK, MOVE_ICE_BEAM, MOVE_THUNDERBOLT, MOVE_RECOVER},
        .itemTableId = BATTLE_FRONTIER_ITEM_CHOICE_SCARF,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
		.abilitynum = ABILITY_1
    },
    [FRONTIER_MON_GARDEVOIR_3] = {
        .species = SPECIES_GARDEVOIR,//NOT MEGA
        .moves = {MOVE_MOONBLAST, MOVE_PSYSHOCK, MOVE_SHADOW_BALL, MOVE_THUNDERBOLT},
        .itemTableId = BATTLE_FRONTIER_ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_SP_ATTACK,
        .nature = NATURE_TIMID,
        .abilitynum = ABILITY_1
    },
    [FRONTIER_MON_EXEGGUTOR_3] = {
        .species = SPECIES_EXEGGUTOR,
        .moves = {MOVE_LEECH_SEED, MOVE_GIGA_DRAIN, MOVE_TOXIC, MOVE_EXPLOSION    },
        .itemTableId = BATTLE_FRONTIER_ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_HARDY,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_STARMIE_3] = {
        .species = SPECIES_STARMIE,
        .moves = {MOVE_SURF, MOVE_PSYCHIC, MOVE_THUNDERBOLT, MOVE_ICE_BEAM    },
        .itemTableId = BATTLE_FRONTIER_ITEM_LUM_BERRY,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_FLYGON_3] = {
        .species = SPECIES_FLYGON,
        .moves = {MOVE_EARTHQUAKE, MOVE_DRAGON_CLAW, MOVE_FLAMETHROWER, MOVE_GIGA_DRAIN    },
        .itemTableId = BATTLE_FRONTIER_ITEM_SCOPE_LENS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_HARDY,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_VENUSAUR_3] = {
        .species = SPECIES_VENUSAUR,
        .moves = {MOVE_DOUBLE_EDGE, MOVE_SLUDGE_BOMB, MOVE_EARTHQUAKE, MOVE_SLEEP_POWDER    },
        .itemTableId = BATTLE_FRONTIER_ITEM_SCOPE_LENS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_DEFENSE | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_VAPOREON_3] = {
        .species = SPECIES_VAPOREON,
        .moves = {MOVE_SURF, MOVE_ICE_BEAM, MOVE_ACID_ARMOR, MOVE_BATON_PASS    },
        .itemTableId = BATTLE_FRONTIER_ITEM_QUICK_CLAW,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_CALM,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_JOLTEON_3] = {
        .species = SPECIES_JOLTEON,//TO REMOVE
        .moves = {MOVE_VOLT_SWITCH, MOVE_SHADOW_BALL, MOVE_THUNDERBOLT, MOVE_HIDDEN_POWER},
        .itemTableId = BATTLE_FRONTIER_ITEM_CHOICE_SPECS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
		.abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_FLAREON_3] = {
        .species = SPECIES_FLAREON,
        .moves = {MOVE_SHADOW_BALL, MOVE_FLAIL, MOVE_ENDURE, MOVE_OVERHEAT    },
        .itemTableId = BATTLE_FRONTIER_ITEM_QUICK_CLAW,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_MEGANIUM_3] = {
        .species = SPECIES_MEGANIUM,
        .moves = {MOVE_EARTHQUAKE, MOVE_FLAIL, MOVE_ENDURE, MOVE_GIGA_DRAIN    },
        .itemTableId = BATTLE_FRONTIER_ITEM_SALAC_BERRY,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_ESPEON_3] = {
        .species = SPECIES_ESPEON,
        .moves = {MOVE_PSYCHIC, MOVE_BITE, MOVE_WISH, MOVE_REFLECT    },
        .itemTableId = BATTLE_FRONTIER_ITEM_LUM_BERRY,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_UMBREON_3] = {
        .species = SPECIES_UMBREON,
        .moves = {MOVE_SWAGGER, MOVE_PSYCH_UP, MOVE_ATTRACT, MOVE_SHADOW_BALL    },
        .itemTableId = BATTLE_FRONTIER_ITEM_BRIGHT_POWDER,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_BOLD,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_BLASTOISE_3] = {
        .species = SPECIES_BLASTOISE,//TO REMOVE
        .moves = {MOVE_AURA_SPHERE, MOVE_SHELL_SMASH, MOVE_ICE_BEAM, MOVE_SCALD},
        .itemTableId = BATTLE_FRONTIER_ITEM_WHITE_HERB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_FERALIGATR_3] = {
        .species = SPECIES_FERALIGATR,
        .moves = {MOVE_HYDRO_PUMP, MOVE_CRUNCH, MOVE_EARTHQUAKE, MOVE_ROCK_SLIDE    },
        .itemTableId = BATTLE_FRONTIER_ITEM_SCOPE_LENS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_HARDY,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_AGGRON_3] = {
        .species = SPECIES_AGGRON,
        .moves = {MOVE_SURF, MOVE_THUNDER, MOVE_FIRE_BLAST, MOVE_BLIZZARD    },
        .itemTableId = BATTLE_FRONTIER_ITEM_BRIGHT_POWDER,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_BLAZIKEN_3] = {
        .species = SPECIES_BLAZIKEN,
        .moves = {MOVE_OVERHEAT, MOVE_EARTHQUAKE, MOVE_ENDURE, MOVE_REVERSAL    },
        .itemTableId = BATTLE_FRONTIER_ITEM_SALAC_BERRY,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_HARDY,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_WALREIN_3] = {
        .species = SPECIES_WALREIN,
        .moves = {MOVE_SHEER_COLD, MOVE_FISSURE, MOVE_SURF, MOVE_ATTRACT    },
        .itemTableId = BATTLE_FRONTIER_ITEM_QUICK_CLAW,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_HARDY,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_SCEPTILE_3] = {
        .species = SPECIES_SCEPTILE,
        .moves = {MOVE_LEAF_BLADE, MOVE_EARTHQUAKE, MOVE_CRUSH_CLAW, MOVE_AERIAL_ACE    },
        .itemTableId = BATTLE_FRONTIER_ITEM_SCOPE_LENS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_DOCILE,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_CHARIZARD_3] = {
        .species = SPECIES_CHARIZARD,
        .moves = {MOVE_FLAMETHROWER, MOVE_DRAGON_CLAW, MOVE_BITE, MOVE_BRICK_BREAK    },
        .itemTableId = BATTLE_FRONTIER_ITEM_LUM_BERRY,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_TYPHLOSION_3] = {
        .species = SPECIES_TYPHLOSION,
        .moves = {MOVE_EARTHQUAKE, MOVE_OVERHEAT, MOVE_ENDURE, MOVE_REVERSAL    },
        .itemTableId = BATTLE_FRONTIER_ITEM_SALAC_BERRY,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_LAPRAS_3] = {
        .species = SPECIES_LAPRAS,
        .moves = {MOVE_DOUBLE_EDGE, MOVE_PSYCHIC, MOVE_CONFUSE_RAY, MOVE_DRAGON_DANCE    },
        .itemTableId = BATTLE_FRONTIER_ITEM_BRIGHT_POWDER,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_DOCILE,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_CROBAT_3] = {
        .species = SPECIES_CROBAT,
        .moves = {MOVE_AIR_CUTTER, MOVE_DOUBLE_EDGE, MOVE_SHADOW_BALL, MOVE_SCREECH    },
        .itemTableId = BATTLE_FRONTIER_ITEM_SCOPE_LENS,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_SWAMPERT_3] = {
        .species = SPECIES_SWAMPERT,
        .moves = {MOVE_SURF, MOVE_EARTHQUAKE, MOVE_ICE_BEAM, MOVE_COUNTER    },
        .itemTableId = BATTLE_FRONTIER_ITEM_SHELL_BELL,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_ATTACK,
        .nature = NATURE_BRAVE,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_GYARADOS_3] = {
        .species = SPECIES_GYARADOS,
        .moves = {MOVE_SURF, MOVE_THUNDER, MOVE_RAIN_DANCE, MOVE_EARTHQUAKE    },
        .itemTableId = BATTLE_FRONTIER_ITEM_QUICK_CLAW,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_ATTACK,
        .nature = NATURE_QUIRKY,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_SNORLAX_3] = {
        .species = SPECIES_SNORLAX,
        .moves = {MOVE_MEGA_KICK, MOVE_SHADOW_BALL, MOVE_SWAGGER, MOVE_PSYCH_UP    },
        .itemTableId = BATTLE_FRONTIER_ITEM_QUICK_CLAW,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_DEFENSE,
        .nature = NATURE_ADAMANT,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_KINGDRA_3] = {
        .species = SPECIES_KINGDRA,
        .moves = {MOVE_FLAIL, MOVE_HYDRO_PUMP, MOVE_DRAGON_DANCE, MOVE_ENDURE    },
        .itemTableId = BATTLE_FRONTIER_ITEM_SALAC_BERRY,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_BLISSEY_3] = {
        .species = SPECIES_BLISSEY,
        .moves = {MOVE_FIRE_BLAST, MOVE_BLIZZARD, MOVE_CALM_MIND, MOVE_SOFT_BOILED    },
        .itemTableId = BATTLE_FRONTIER_ITEM_FOCUS_BAND,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_DEFENSE,
        .nature = NATURE_BOLD,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_MILOTIC_3] = {
        .species = SPECIES_MILOTIC,
        .moves = {MOVE_SURF, MOVE_BLIZZARD, MOVE_ATTRACT, MOVE_RECOVER    },
        .itemTableId = BATTLE_FRONTIER_ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_BOLD,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_ARCANINE_3] = {
        .species = SPECIES_ARCANINE,
        .moves = {MOVE_OVERHEAT, MOVE_EXTREME_SPEED, MOVE_CRUNCH, MOVE_AERIAL_ACE    },
        .itemTableId = BATTLE_FRONTIER_ITEM_WHITE_HERB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_SALAMENCE_3] = {
        .species = SPECIES_SALAMENCE,
        .moves = {MOVE_DRAGON_CLAW, MOVE_EARTHQUAKE, MOVE_OUTRAGE, MOVE_DRAGON_DANCE},
        .itemTableId = BATTLE_FRONTIER_ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_JOLLY,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_METAGROSS_3] = {
        .species = SPECIES_METAGROSS,
        .moves = {MOVE_EARTHQUAKE, MOVE_METEOR_MASH, MOVE_DOUBLE_TEAM, MOVE_REST    },
        .itemTableId = BATTLE_FRONTIER_ITEM_CHESTO_BERRY,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_SLAKING_3] = {
        .species = SPECIES_SLAKING,
        .moves = {MOVE_EARTHQUAKE, MOVE_SHADOW_BALL, MOVE_AERIAL_ACE, MOVE_BRICK_BREAK    },
        .itemTableId = BATTLE_FRONTIER_ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_DEFENSE,
        .nature = NATURE_ADAMANT,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_DUGTRIO_4] = {
        .species = SPECIES_DUGTRIO,//TO REMOVE
        .moves = {MOVE_EARTHQUAKE, MOVE_SUCKER_PUNCH, MOVE_REVERSAL, MOVE_ROCK_SLIDE},
        .itemTableId = BATTLE_FRONTIER_ITEM_FOCUS_SASH,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_MEDICHAM_4] = {
        .species = SPECIES_MEDICHAM,
        .moves = {MOVE_MEGA_KICK, MOVE_PSYCHIC, MOVE_SHADOW_BALL, MOVE_ROCK_SLIDE    },
        .itemTableId = BATTLE_FRONTIER_ITEM_LUM_BERRY,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_ATTACK,
        .nature = NATURE_HARDY,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_MISDREAVUS_4] = {
        .species = SPECIES_MISDREAVUS,
        .moves = {MOVE_DESTINY_BOND, MOVE_PSYCHIC, MOVE_SHADOW_BALL, MOVE_THUNDERBOLT    },
        .itemTableId = BATTLE_FRONTIER_ITEM_LUM_BERRY,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_FEAROW_4] = {
        .species = SPECIES_FEAROW,
        .moves = {MOVE_DRILL_PECK, MOVE_DOUBLE_EDGE, MOVE_STEEL_WING, MOVE_SKY_ATTACK    },
        .itemTableId = BATTLE_FRONTIER_ITEM_LUM_BERRY,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_ATTACK,
        .nature = NATURE_HARDY,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_GRANBULL_4] = {
        .species = SPECIES_GRANBULL,
        .moves = {MOVE_MEGA_KICK, MOVE_EARTHQUAKE, MOVE_CRUNCH, MOVE_SHADOW_BALL    },
        .itemTableId = BATTLE_FRONTIER_ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_ATTACK,
        .nature = NATURE_BRAVE,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_JYNX_4] = {
        .species = SPECIES_JYNX,
        .moves = {MOVE_PSYCHIC, MOVE_ICE_BEAM, MOVE_LOVELY_KISS, MOVE_FAKE_TEARS    },
        .itemTableId = BATTLE_FRONTIER_ITEM_LUM_BERRY,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_DUSCLOPS_4] = {
        .species = SPECIES_DUSKNOIR,//TO REMOVE
        .moves = {MOVE_WILL_O_WISP, MOVE_PAIN_SPLIT, MOVE_SHADOW_SNEAK, MOVE_ICE_PUNCH},
        .itemTableId = BATTLE_FRONTIER_ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
		.abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_DODRIO_4] = {
        .species = SPECIES_DODRIO,
        .moves = {MOVE_FLAIL, MOVE_ENDURE, MOVE_DRILL_PECK, MOVE_FACADE    },
        .itemTableId = BATTLE_FRONTIER_ITEM_SALAC_BERRY,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_MR_MIME_4] = {
        .species = SPECIES_MR_MIME,
        .moves = {MOVE_PSYCHIC, MOVE_THUNDERBOLT, MOVE_ICE_PUNCH, MOVE_FIRE_PUNCH    },
        .itemTableId = BATTLE_FRONTIER_ITEM_BRIGHT_POWDER,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_LANTURN_4] = {
        .species = SPECIES_LANTURN,
        .moves = {MOVE_SURF, MOVE_THUNDERBOLT, MOVE_ICE_BEAM, MOVE_CONFUSE_RAY    },
        .itemTableId = BATTLE_FRONTIER_ITEM_LUM_BERRY,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_BRELOOM_4] = {
        .species = SPECIES_BRELOOM,
        .moves = {MOVE_FOCUS_PUNCH, MOVE_SLUDGE_BOMB, MOVE_SPORE, MOVE_DOUBLE_TEAM    },
        .itemTableId = BATTLE_FRONTIER_ITEM_QUICK_CLAW,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_FORRETRESS_4] = {
        .species = SPECIES_FORRETRESS,
        .moves = {MOVE_EXPLOSION, MOVE_EARTHQUAKE, MOVE_ROCK_SLIDE, MOVE_DOUBLE_EDGE    },
        .itemTableId = BATTLE_FRONTIER_ITEM_QUICK_CLAW,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_WHISCASH_4] = {
        .species = SPECIES_WHISCASH,
        .moves = {MOVE_FISSURE, MOVE_SURF, MOVE_EARTHQUAKE, MOVE_ICE_BEAM    },
        .itemTableId = BATTLE_FRONTIER_ITEM_QUICK_CLAW,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_ATTACK,
        .nature = NATURE_QUIET,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_XATU_4] = {
        .species = SPECIES_XATU,
        .moves = {MOVE_PSYCHIC, MOVE_DRILL_PECK, MOVE_SHADOW_BALL, MOVE_CONFUSE_RAY    },
        .itemTableId = BATTLE_FRONTIER_ITEM_PETAYA_BERRY,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_ATTACK,
        .nature = NATURE_DOCILE,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_SKARMORY_4] = {
        .species = SPECIES_SKARMORY,
        .moves = {MOVE_DRILL_PECK, MOVE_STEEL_WING, MOVE_COUNTER, MOVE_ROCK_SLIDE    },
        .itemTableId = BATTLE_FRONTIER_ITEM_QUICK_CLAW,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_MAROWAK_4] = {
        .species = SPECIES_MAROWAK,
        .moves = {MOVE_EARTHQUAKE, MOVE_ROCK_SLIDE, MOVE_SWORDS_DANCE, MOVE_MEGA_KICK    },
        .itemTableId = BATTLE_FRONTIER_ITEM_THICK_CLUB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_QUAGSIRE_4] = {
        .species = SPECIES_QUAGSIRE,
        .moves = {MOVE_SURF, MOVE_EARTHQUAKE, MOVE_ICE_BEAM, MOVE_AMNESIA    },
        .itemTableId = BATTLE_FRONTIER_ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_ATTACK,
        .nature = NATURE_SASSY,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_CLEFABLE_4] = {
        .species = SPECIES_CLEFABLE,
        .moves = {MOVE_MEGA_KICK, MOVE_PSYCHIC, MOVE_SHADOW_BALL, MOVE_SOFT_BOILED    },
        .itemTableId = BATTLE_FRONTIER_ITEM_FOCUS_BAND,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_ATTACK,
        .nature = NATURE_DOCILE,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_HARIYAMA_4] = {
        .species = SPECIES_HARIYAMA,
        .moves = {MOVE_CROSS_CHOP, MOVE_EARTHQUAKE, MOVE_ROCK_SLIDE, MOVE_FAKE_OUT    },
        .itemTableId = BATTLE_FRONTIER_ITEM_SCOPE_LENS,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_RAICHU_4] = {
        .species = SPECIES_RAICHU,
        .moves = {MOVE_THUNDERBOLT, MOVE_THUNDER_WAVE, MOVE_PROTECT, MOVE_MEGA_KICK    },
        .itemTableId = BATTLE_FRONTIER_ITEM_BRIGHT_POWDER,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_ATTACK,
        .nature = NATURE_DOCILE,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_DEWGONG_4] = {
        .species = SPECIES_DEWGONG,
        .moves = {MOVE_SHEER_COLD, MOVE_ICE_BEAM, MOVE_SURF, MOVE_SIGNAL_BEAM    },
        .itemTableId = BATTLE_FRONTIER_ITEM_LUM_BERRY,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_ATTACK,
        .nature = NATURE_DOCILE,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_MANECTRIC_4] = {
        .species = SPECIES_MANECTRIC,
        .moves = {MOVE_THUNDERBOLT, MOVE_CRUNCH, MOVE_THUNDER_WAVE, MOVE_ROAR    },
        .itemTableId = BATTLE_FRONTIER_ITEM_LUM_BERRY,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_VILEPLUME_4] = {
        .species = SPECIES_VILEPLUME,
        .moves = {MOVE_SOLAR_BEAM, MOVE_SLUDGE_BOMB, MOVE_SUNNY_DAY, MOVE_SYNTHESIS    },
        .itemTableId = BATTLE_FRONTIER_ITEM_QUICK_CLAW,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_ATTACK,
        .nature = NATURE_QUIET,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_VICTREEBEL_4] = {
        .species = SPECIES_VICTREEBEL,
        .moves = {MOVE_GIGA_DRAIN, MOVE_DOUBLE_EDGE, MOVE_SLUDGE_BOMB, MOVE_SYNTHESIS    },
        .itemTableId = BATTLE_FRONTIER_ITEM_BRIGHT_POWDER,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_ATTACK,
        .nature = NATURE_QUIRKY,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_ELECTRODE_4] = {
        .species = SPECIES_ELECTRODE,
        .moves = {MOVE_EXPLOSION, MOVE_THUNDERBOLT, MOVE_THUNDER_WAVE, MOVE_MIRROR_COAT    },
        .itemTableId = BATTLE_FRONTIER_ITEM_LUM_BERRY,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_ATTACK,
        .nature = NATURE_NAUGHTY,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_EXPLOUD_4] = {
        .species = SPECIES_EXPLOUD,//TO REMOVE
        .moves = {MOVE_BOOMBURST, MOVE_ICE_BEAM, MOVE_FIRE_BLAST, MOVE_THUNDERBOLT},
        .itemTableId = BATTLE_FRONTIER_ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_TIMID,
		.abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_SHIFTRY_4] = {
        .species = SPECIES_SHIFTRY,
        .moves = {MOVE_EXPLOSION, MOVE_GIGA_DRAIN, MOVE_MEGA_KICK, MOVE_FAKE_OUT    },
        .itemTableId = BATTLE_FRONTIER_ITEM_FOCUS_BAND,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_ATTACK,
        .nature = NATURE_HARDY,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_GLALIE_4] = {
        .species = SPECIES_GLALIE,
        .moves = {MOVE_ICE_BEAM, MOVE_EARTHQUAKE, MOVE_CRUNCH, MOVE_SHADOW_BALL    },
        .itemTableId = BATTLE_FRONTIER_ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_HARDY,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_LUDICOLO_4] = {
        .species = SPECIES_LUDICOLO,//TO REMOVE
        .moves = {MOVE_HYDRO_PUMP, MOVE_ICE_BEAM, MOVE_GIGA_DRAIN, MOVE_SCALD},
        .itemTableId = BATTLE_FRONTIER_ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
		.abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_HYPNO_4] = {
        .species = SPECIES_HYPNO,
        .moves = {MOVE_PSYCHIC, MOVE_THUNDER_PUNCH, MOVE_FIRE_PUNCH, MOVE_ICE_PUNCH    },
        .itemTableId = BATTLE_FRONTIER_ITEM_LUM_BERRY,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_GOLEM_4] = {
       .species = SPECIES_GOLEM,//TO REMOVE
        .moves = {MOVE_EARTHQUAKE, MOVE_EXPLOSION, MOVE_STONE_EDGE, MOVE_STEALTH_ROCK},
        .itemTableId = BATTLE_FRONTIER_ITEM_WEAKNESS_POLICY,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
		.abilitynum = ABILITY_1
    },
    [FRONTIER_MON_RHYDON_4] = {
        .species = SPECIES_RHYPERIOR,//TO REMOVE
        .moves = {MOVE_STEALTH_ROCK, MOVE_ICE_PUNCH, MOVE_EARTHQUAKE, MOVE_ROCK_BLAST},
        .itemTableId = BATTLE_FRONTIER_ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
		.abilitynum = ABILITY_2
    },
    [FRONTIER_MON_ALAKAZAM_4] = {
        .species = SPECIES_ALAKAZAM,
        .moves = {MOVE_PSYCHIC, MOVE_THUNDER_PUNCH, MOVE_FIRE_PUNCH, MOVE_ICE_PUNCH    },
        .itemTableId = BATTLE_FRONTIER_ITEM_BRIGHT_POWDER,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_DEFENSE,
        .nature = NATURE_MODEST,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_WEEZING_4] = {
        .species = SPECIES_WEEZING,
        .moves = {MOVE_EXPLOSION, MOVE_SLUDGE_BOMB, MOVE_FRUSTRATION, MOVE_SHADOW_BALL    },
        .itemTableId = BATTLE_FRONTIER_ITEM_FOCUS_BAND,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_KANGASKHAN_4] = {
        .species = SPECIES_KANGASKHAN,
        .moves = {MOVE_MEGA_KICK, MOVE_EARTHQUAKE, MOVE_AERIAL_ACE, MOVE_SHADOW_BALL    },
        .itemTableId = BATTLE_FRONTIER_ITEM_BRIGHT_POWDER,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_ELECTABUZZ_4] = {
        .species = SPECIES_ELECTABUZZ,
        .moves = {MOVE_THUNDERBOLT, MOVE_PSYCHIC, MOVE_MEGA_KICK, MOVE_CROSS_CHOP    },
        .itemTableId = BATTLE_FRONTIER_ITEM_SCOPE_LENS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_ATTACK,
        .nature = NATURE_DOCILE,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_TAUROS_4] = {
        .species = SPECIES_TAUROS,
        .moves = {MOVE_DOUBLE_EDGE, MOVE_ROCK_TOMB, MOVE_THUNDERBOLT, MOVE_SURF    },
        .itemTableId = BATTLE_FRONTIER_ITEM_BRIGHT_POWDER,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_ATTACK,
        .nature = NATURE_DOCILE,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_SLOWBRO_4] = {
        .species = SPECIES_SLOWBRO,
        .moves = {MOVE_PSYCHIC, MOVE_SURF, MOVE_EARTHQUAKE, MOVE_ICE_BEAM    },
        .itemTableId = BATTLE_FRONTIER_ITEM_QUICK_CLAW,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_SP_ATTACK,
        .nature = NATURE_SASSY,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_SLOWKING_4] = {
        .species = SPECIES_SLOWKING,
        .moves = {MOVE_PSYCHIC, MOVE_SURF, MOVE_ICE_BEAM, MOVE_FLAMETHROWER    },
        .itemTableId = BATTLE_FRONTIER_ITEM_QUICK_CLAW,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_DEFENSE,
        .nature = NATURE_MODEST,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_MILTANK_4] = {
        .species = SPECIES_MILTANK,
        .moves = {MOVE_DOUBLE_EDGE, MOVE_CURSE, MOVE_DOUBLE_TEAM, MOVE_MILK_DRINK    },
        .itemTableId = BATTLE_FRONTIER_ITEM_LUM_BERRY,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_ALTARIA_4] = {
        .species = SPECIES_ALTARIA,
        .moves = {MOVE_DRAGON_CLAW, MOVE_EARTHQUAKE, MOVE_FLAMETHROWER, MOVE_ICE_BEAM    },
        .itemTableId = BATTLE_FRONTIER_ITEM_SHELL_BELL,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_ATTACK,
        .nature = NATURE_DOCILE,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_NIDOQUEEN_4] = {
        .species = SPECIES_NIDOQUEEN,
        .moves = {MOVE_SUPERPOWER, MOVE_SLUDGE_BOMB, MOVE_EARTHQUAKE, MOVE_SHADOW_BALL    },
        .itemTableId = BATTLE_FRONTIER_ITEM_WHITE_HERB,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_NIDOKING_4] = {
        .species = SPECIES_NIDOKING,
        .moves = {MOVE_MEGAHORN, MOVE_SLUDGE_BOMB, MOVE_EARTHQUAKE, MOVE_THUNDER    },
        .itemTableId = BATTLE_FRONTIER_ITEM_LUM_BERRY,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_ATTACK,
        .nature = NATURE_DOCILE,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_MAGMAR_4] = {
        .species = SPECIES_MAGMAR,
        .moves = {MOVE_FLAMETHROWER, MOVE_PSYCHIC, MOVE_CROSS_CHOP, MOVE_CONFUSE_RAY    },
        .itemTableId = BATTLE_FRONTIER_ITEM_SCOPE_LENS,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_DOCILE,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_CRADILY_4] = {
        .species = SPECIES_CRADILY,
        .moves = {MOVE_TOXIC, MOVE_INGRAIN, MOVE_MIRROR_COAT, MOVE_GIGA_DRAIN    },
        .itemTableId = BATTLE_FRONTIER_ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_BOLD,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_ARMALDO_4] = {
        .species = SPECIES_ARMALDO,
        .moves = {MOVE_DOUBLE_EDGE, MOVE_EARTHQUAKE, MOVE_AERIAL_ACE, MOVE_ROCK_SLIDE    },
        .itemTableId = BATTLE_FRONTIER_ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_GOLDUCK_4] = {
        .species = SPECIES_GOLDUCK,
        .moves = {MOVE_SURF, MOVE_CROSS_CHOP, MOVE_ICE_BEAM, MOVE_AERIAL_ACE    },
        .itemTableId = BATTLE_FRONTIER_ITEM_SCOPE_LENS,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_DOCILE,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_RAPIDASH_4] = {
        .species = SPECIES_RAPIDASH,
        .moves = {MOVE_OVERHEAT, MOVE_DOUBLE_EDGE, MOVE_IRON_TAIL, MOVE_DOUBLE_KICK    },
        .itemTableId = BATTLE_FRONTIER_ITEM_WHITE_HERB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_DOCILE,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_MUK_4] = {
        .species = SPECIES_MUK,
        .moves = {MOVE_SLUDGE_BOMB, MOVE_BRICK_BREAK, MOVE_GIGA_DRAIN, MOVE_EXPLOSION    },
        .itemTableId = BATTLE_FRONTIER_ITEM_QUICK_CLAW,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_ATTACK,
        .nature = NATURE_BRAVE,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_GENGAR_4] = {
        .species = SPECIES_AEGISLASH,
        .moves = {MOVE_KINGS_SHIELD, MOVE_SHADOW_BALL, MOVE_FLASH_CANNON, MOVE_AUTOTOMIZE},
        .itemTableId = BATTLE_FRONTIER_ITEM_WEAKNESS_POLICY,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
		.abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_AMPHAROS_4] = {
        .species = SPECIES_AMPHAROS,
        .moves = {MOVE_THUNDERBOLT, MOVE_FIRE_PUNCH, MOVE_THUNDER_WAVE, MOVE_REFLECT    },
        .itemTableId = BATTLE_FRONTIER_ITEM_LUM_BERRY,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_DEFENSE,
        .nature = NATURE_MODEST,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_SCIZOR_4] = {
        .species = SPECIES_SCIZOR,
        .moves = {MOVE_SILVER_WIND, MOVE_SWORDS_DANCE, MOVE_AGILITY, MOVE_BATON_PASS    },
        .itemTableId = BATTLE_FRONTIER_ITEM_BRIGHT_POWDER,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_CAREFUL,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_HERACROSS_4] = {
        .species = SPECIES_HERACROSS,
        .moves = {MOVE_MEGAHORN, MOVE_EARTHQUAKE, MOVE_REVERSAL, MOVE_ENDURE    },
        .itemTableId = BATTLE_FRONTIER_ITEM_SALAC_BERRY,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_URSARING_4] = {
		.species = SPECIES_URSARING,//TO REMOVE
        .moves = {MOVE_SWORDS_DANCE, MOVE_FACADE, MOVE_PLAY_ROUGH, MOVE_FIRE_PUNCH},
        .itemTableId = BATTLE_FRONTIER_ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_JOLLY,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_HOUNDOOM_4] = {
        .species = SPECIES_HOUNDOOM,
        .moves = {MOVE_OVERHEAT, MOVE_SOLAR_BEAM, MOVE_CRUNCH, MOVE_SUNNY_DAY    },
        .itemTableId = BATTLE_FRONTIER_ITEM_WHITE_HERB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_DONPHAN_4] = {
        .species = SPECIES_DONPHAN,
        .moves = {MOVE_FISSURE, MOVE_EARTHQUAKE, MOVE_ROCK_SLIDE, MOVE_IRON_TAIL    },
        .itemTableId = BATTLE_FRONTIER_ITEM_QUICK_CLAW,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_CLAYDOL_4] = {
        .species = SPECIES_CLAYDOL,
        .moves = {MOVE_PSYCHIC, MOVE_EARTHQUAKE, MOVE_SHADOW_BALL, MOVE_EXPLOSION    },
        .itemTableId = BATTLE_FRONTIER_ITEM_FOCUS_BAND,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_WAILORD_4] = {
        .species = SPECIES_WAILORD,
        .moves = {MOVE_SURF, MOVE_ICE_BEAM, MOVE_EARTHQUAKE, MOVE_FISSURE    },
        .itemTableId = BATTLE_FRONTIER_ITEM_QUICK_CLAW,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_HARDY,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_NINETALES_4] = {
        .species = SPECIES_NINETALES,//TO REMOVE
        .moves = {MOVE_WILL_O_WISP, MOVE_SOLAR_BEAM, MOVE_FIRE_BLAST, MOVE_SHADOW_BALL},
        .itemTableId = BATTLE_FRONTIER_ITEM_HEAT_ROCK,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
		.abilitynum = 2
    },
    [FRONTIER_MON_MACHAMP_4] = {
        .species = SPECIES_MACHAMP,
        .moves = {MOVE_CROSS_CHOP, MOVE_EARTHQUAKE, MOVE_FLAMETHROWER, MOVE_ROCK_SLIDE    },
        .itemTableId = BATTLE_FRONTIER_ITEM_SCOPE_LENS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_ATTACK,
        .nature = NATURE_HARDY,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_SHUCKLE_4] = {
        .species = SPECIES_SHUCKLE,
        .moves = {MOVE_TOXIC, MOVE_DOUBLE_TEAM, MOVE_WRAP, MOVE_REST    },
        .itemTableId = BATTLE_FRONTIER_ITEM_CHESTO_BERRY,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_DEFENSE,
        .nature = NATURE_CAREFUL,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_STEELIX_4] = {
        .species = SPECIES_STEELIX,
        .moves = {MOVE_EARTHQUAKE, MOVE_IRON_TAIL, MOVE_DOUBLE_EDGE, MOVE_EXPLOSION    },
        .itemTableId = BATTLE_FRONTIER_ITEM_QUICK_CLAW,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_TENTACRUEL_4] = {
        .species = SPECIES_TENTACRUEL,
        .moves = {MOVE_HYDRO_PUMP, MOVE_SLUDGE_BOMB, MOVE_ICE_BEAM, MOVE_MIRROR_COAT    },
        .itemTableId = BATTLE_FRONTIER_ITEM_SHELL_BELL,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_DEFENSE | F_EV_SPREAD_ATTACK,
        .nature = NATURE_QUIRKY,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_AERODACTYL_4] = {
        .species = SPECIES_AERODACTYL,
        .moves = {MOVE_DOUBLE_EDGE, MOVE_EARTHQUAKE, MOVE_FIRE_BLAST, MOVE_BITE    },
        .itemTableId = BATTLE_FRONTIER_ITEM_KINGS_ROCK,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_ATTACK,
        .nature = NATURE_HARDY,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_PORYGON2_4] = {
        .species = SPECIES_PORYGON_Z,//TO REMOVE
        .moves = {MOVE_TRI_ATTACK, MOVE_ICE_BEAM, MOVE_THUNDERBOLT, MOVE_RECOVER},
        .itemTableId = BATTLE_FRONTIER_ITEM_CHOICE_SCARF,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
		.abilitynum = ABILITY_1
    },
    [FRONTIER_MON_GARDEVOIR_4] = {
        .species = SPECIES_GALLADE,//NOT MEGA
        .moves = {MOVE_CLOSE_COMBAT, MOVE_ZEN_HEADBUTT, MOVE_LEAF_BLADE, MOVE_EARTHQUAKE},
        .itemTableId = BATTLE_FRONTIER_ITEM_ASSAULT_VEST,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_JOLLY,
		.abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_EXEGGUTOR_4] = {
        .species = SPECIES_EXEGGUTOR,
        .moves = {MOVE_PSYCHIC, MOVE_GIGA_DRAIN, MOVE_SLUDGE_BOMB, MOVE_EXPLOSION    },
        .itemTableId = BATTLE_FRONTIER_ITEM_BRIGHT_POWDER,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_ATTACK,
        .nature = NATURE_HARDY,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_STARMIE_4] = {
        .species = SPECIES_STARMIE,
        .moves = {MOVE_PSYCHIC, MOVE_THUNDERBOLT, MOVE_ICE_BEAM, MOVE_RECOVER    },
        .itemTableId = BATTLE_FRONTIER_ITEM_LUM_BERRY,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_FLYGON_4] = {
        .species = SPECIES_FLYGON,
        .moves = {MOVE_EARTHQUAKE, MOVE_DRAGON_CLAW, MOVE_DOUBLE_EDGE, MOVE_CRUNCH    },
        .itemTableId = BATTLE_FRONTIER_ITEM_SCOPE_LENS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_HARDY,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_VENUSAUR_4] = {
        .species = SPECIES_VENUSAUR,
        .moves = {MOVE_SOLAR_BEAM, MOVE_SLUDGE_BOMB, MOVE_SUNNY_DAY, MOVE_EARTHQUAKE    },
        .itemTableId = BATTLE_FRONTIER_ITEM_LUM_BERRY,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_ATTACK,
        .nature = NATURE_DOCILE,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_VAPOREON_4] = {
        .species = SPECIES_VAPOREON,
        .moves = {MOVE_SURF, MOVE_ICE_BEAM, MOVE_ACID_ARMOR, MOVE_REST    },
        .itemTableId = BATTLE_FRONTIER_ITEM_LUM_BERRY,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_CALM,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_JOLTEON_4] = {
        .species = SPECIES_JOLTEON,//TO REMOVE
        .moves = {MOVE_VOLT_SWITCH, MOVE_SHADOW_BALL, MOVE_THUNDERBOLT, MOVE_HIDDEN_POWER},
        .itemTableId = BATTLE_FRONTIER_ITEM_CHOICE_SPECS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
		.abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_FLAREON_4] = {
        .species = SPECIES_FLAREON,
        .moves = {MOVE_OVERHEAT, MOVE_SUNNY_DAY, MOVE_DOUBLE_EDGE, MOVE_SHADOW_BALL    },
        .itemTableId = BATTLE_FRONTIER_ITEM_QUICK_CLAW,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_ATTACK,
        .nature = NATURE_QUIET,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_MEGANIUM_4] = {
        .species = SPECIES_MEGANIUM,
        .moves = {MOVE_GIGA_DRAIN, MOVE_EARTHQUAKE, MOVE_ANCIENT_POWER, MOVE_BODY_SLAM    },
        .itemTableId = BATTLE_FRONTIER_ITEM_BRIGHT_POWDER,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_HARDY,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_ESPEON_4] = {
        .species = SPECIES_ESPEON,
        .moves = {MOVE_PSYCHIC, MOVE_BITE, MOVE_ATTRACT, MOVE_CALM_MIND    },
        .itemTableId = BATTLE_FRONTIER_ITEM_BRIGHT_POWDER,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_UMBREON_4] = {
        .species = SPECIES_UMBREON,
        .moves = {MOVE_CONFUSE_RAY, MOVE_TOXIC, MOVE_FAINT_ATTACK, MOVE_DOUBLE_TEAM    },
        .itemTableId = BATTLE_FRONTIER_ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_BOLD,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_BLASTOISE_4] = {
        .species = SPECIES_BLASTOISE,//TO REMOVE
        .moves = {MOVE_AURA_SPHERE, MOVE_SHELL_SMASH, MOVE_ICE_BEAM, MOVE_SCALD},
        .itemTableId = BATTLE_FRONTIER_ITEM_WHITE_HERB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_FERALIGATR_4] = {
        .species = SPECIES_FERALIGATR,
        .moves = {MOVE_HYDRO_PUMP, MOVE_ICE_BEAM, MOVE_EARTHQUAKE, MOVE_AERIAL_ACE    },
        .itemTableId = BATTLE_FRONTIER_ITEM_SCOPE_LENS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_HARDY,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_AGGRON_4] = {
        .species = SPECIES_AGGRON,
        .moves = {MOVE_DOUBLE_EDGE, MOVE_EARTHQUAKE, MOVE_ROCK_SLIDE, MOVE_AERIAL_ACE    },
        .itemTableId = BATTLE_FRONTIER_ITEM_QUICK_CLAW,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_BLAZIKEN_4] = {
        .species = SPECIES_BLAZIKEN,
        .moves = {MOVE_OVERHEAT, MOVE_EARTHQUAKE, MOVE_THUNDER_PUNCH, MOVE_ROCK_SLIDE    },
        .itemTableId = BATTLE_FRONTIER_ITEM_WHITE_HERB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_ATTACK,
        .nature = NATURE_HARDY,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_WALREIN_4] = {
        .species = SPECIES_WALREIN,
        .moves = {MOVE_SURF, MOVE_ICE_BEAM, MOVE_EARTHQUAKE, MOVE_SHEER_COLD    },
        .itemTableId = BATTLE_FRONTIER_ITEM_BRIGHT_POWDER,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_ATTACK,
        .nature = NATURE_QUIET,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_SCEPTILE_4] = {
        .species = SPECIES_SCEPTILE,
        .moves = {MOVE_LEAF_BLADE, MOVE_DRAGON_CLAW, MOVE_CRUNCH, MOVE_THUNDER_PUNCH    },
        .itemTableId = BATTLE_FRONTIER_ITEM_BRIGHT_POWDER,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_CHARIZARD_4] = {
        .species = SPECIES_CHARIZARD,
        .moves = {MOVE_OVERHEAT, MOVE_EARTHQUAKE, MOVE_AERIAL_ACE, MOVE_ROCK_SLIDE    },
        .itemTableId = BATTLE_FRONTIER_ITEM_WHITE_HERB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_HARDY,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_TYPHLOSION_4] = {
        .species = SPECIES_TYPHLOSION,
        .moves = {MOVE_OVERHEAT, MOVE_THUNDER_PUNCH, MOVE_EARTHQUAKE, MOVE_CRUSH_CLAW    },
        .itemTableId = BATTLE_FRONTIER_ITEM_WHITE_HERB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_HARDY,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_LAPRAS_4] = {
        .species = SPECIES_LAPRAS,
        .moves = {MOVE_SURF, MOVE_ICE_BEAM, MOVE_THUNDERBOLT, MOVE_PSYCHIC    },
        .itemTableId = BATTLE_FRONTIER_ITEM_LUM_BERRY,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_CROBAT_4] = {
        .species = SPECIES_CROBAT,
        .moves = {MOVE_SLUDGE_BOMB, MOVE_AERIAL_ACE, MOVE_SHADOW_BALL, MOVE_CONFUSE_RAY    },
        .itemTableId = BATTLE_FRONTIER_ITEM_BRIGHT_POWDER,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_SWAMPERT_4] = {
        .species = SPECIES_SWAMPERT,
        .moves = {MOVE_SURF, MOVE_EARTHQUAKE, MOVE_ICE_BEAM, MOVE_MIRROR_COAT    },
        .itemTableId = BATTLE_FRONTIER_ITEM_SHELL_BELL,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_ATTACK,
        .nature = NATURE_QUIET,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_GYARADOS_4] = {
        .species = SPECIES_GYARADOS,
        .moves = {MOVE_RETURN, MOVE_EARTHQUAKE, MOVE_DRAGON_DANCE, MOVE_REST    },
        .itemTableId = BATTLE_FRONTIER_ITEM_CHESTO_BERRY,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_SNORLAX_4] = {
        .species = SPECIES_SNORLAX,
        .moves = {MOVE_DOUBLE_EDGE, MOVE_SHADOW_BALL, MOVE_BRICK_BREAK, MOVE_CURSE    },
        .itemTableId = BATTLE_FRONTIER_ITEM_QUICK_CLAW,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_KINGDRA_4] = {
        .species = SPECIES_KINGDRA,
        .moves = {MOVE_DOUBLE_EDGE, MOVE_ICE_BEAM, MOVE_DRAGON_DANCE, MOVE_REST    },
        .itemTableId = BATTLE_FRONTIER_ITEM_CHESTO_BERRY,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_HARDY,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_BLISSEY_4] = {
        .species = SPECIES_BLISSEY,
        .moves = {MOVE_ICE_BEAM, MOVE_CALM_MIND, MOVE_COUNTER, MOVE_SOFT_BOILED    },
        .itemTableId = BATTLE_FRONTIER_ITEM_FOCUS_BAND,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_DEFENSE,
        .nature = NATURE_BOLD,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_MILOTIC_4] = {
        .species = SPECIES_MILOTIC,
        .moves = {MOVE_SURF, MOVE_ICE_BEAM, MOVE_RECOVER, MOVE_MIRROR_COAT    },
        .itemTableId = BATTLE_FRONTIER_ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_DEFENSE,
        .nature = NATURE_MODEST,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_ARCANINE_4] = {
        .species = SPECIES_ARCANINE,
        .moves = {MOVE_OVERHEAT, MOVE_EXTREME_SPEED, MOVE_CRUNCH, MOVE_DOUBLE_EDGE    },
        .itemTableId = BATTLE_FRONTIER_ITEM_WHITE_HERB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_DOCILE,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_SALAMENCE_4] = {
        .species = SPECIES_SALAMENCE,
        .moves = {MOVE_HYPER_VOICE, MOVE_FIRE_BLAST, MOVE_DRACO_METEOR, MOVE_ROOST},
        .itemTableId = BATTLE_FRONTIER_ITEM_SALAMENCITE,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_METAGROSS_4] = {
        .species = SPECIES_METAGROSS,
        .moves = {MOVE_METEOR_MASH, MOVE_PSYCHIC, MOVE_EARTHQUAKE, MOVE_SHADOW_BALL    },
        .itemTableId = BATTLE_FRONTIER_ITEM_QUICK_CLAW,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_ATTACK,
        .nature = NATURE_HARDY,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_SLAKING_4] = {
        .species = SPECIES_SLAKING,
        .moves = {MOVE_THUNDERBOLT, MOVE_FLAMETHROWER, MOVE_ICE_BEAM, MOVE_YAWN    },
        .itemTableId = BATTLE_FRONTIER_ITEM_LUM_BERRY,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_SP_ATTACK,
        .nature = NATURE_MODEST,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_ARTICUNO_1] = {
        .species = SPECIES_ARTICUNO,
        .moves = {MOVE_ICE_BEAM, MOVE_WATER_PULSE, MOVE_ICY_WIND, MOVE_ROAR    },
        .itemTableId = BATTLE_FRONTIER_ITEM_LUM_BERRY,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_ZAPDOS_1] = {
        .species = SPECIES_ZAPDOS,
        .moves = {MOVE_THUNDERBOLT, MOVE_DRILL_PECK, MOVE_THUNDER_WAVE, MOVE_ROAR    },
        .itemTableId = BATTLE_FRONTIER_ITEM_LUM_BERRY,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_DOCILE,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_MOLTRES_1] = {
        .species = SPECIES_MOLTRES,
        .moves = {MOVE_FLAMETHROWER, MOVE_AERIAL_ACE, MOVE_MUD_SLAP, MOVE_ROAR    },
        .itemTableId = BATTLE_FRONTIER_ITEM_LUM_BERRY,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_ATTACK,
        .nature = NATURE_DOCILE,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_RAIKOU_1] = {
        .species = SPECIES_RAIKOU,
        .moves = {MOVE_THUNDERBOLT, MOVE_THUNDER_WAVE, MOVE_CALM_MIND, MOVE_REST    },
        .itemTableId = BATTLE_FRONTIER_ITEM_CHESTO_BERRY,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_ENTEI_1] = {
        .species = SPECIES_ENTEI,
        .moves = {MOVE_FLAMETHROWER, MOVE_DOUBLE_TEAM, MOVE_CALM_MIND, MOVE_REST    },
        .itemTableId = BATTLE_FRONTIER_ITEM_CHESTO_BERRY,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_SUICUNE_1] = {
        .species = SPECIES_SUICUNE,
        .moves = {MOVE_SURF, MOVE_DOUBLE_TEAM, MOVE_CALM_MIND, MOVE_REST    },
        .itemTableId = BATTLE_FRONTIER_ITEM_CHESTO_BERRY,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_REGIROCK_1] = {
        .species = SPECIES_REGIROCK,
        .moves = {MOVE_SUPERPOWER, MOVE_EARTHQUAKE, MOVE_ROCK_SLIDE, MOVE_EXPLOSION    },
        .itemTableId = BATTLE_FRONTIER_ITEM_WHITE_HERB,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_REGICE_1] = {
        .species = SPECIES_REGICE,
        .moves = {MOVE_ICE_BEAM, MOVE_THUNDERBOLT, MOVE_AMNESIA, MOVE_REST    },
        .itemTableId = BATTLE_FRONTIER_ITEM_CHESTO_BERRY,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_REGISTEEL_1] = {
        .species = SPECIES_REGISTEEL,
        .moves = {MOVE_METAL_CLAW, MOVE_CURSE, MOVE_AMNESIA, MOVE_REST    },
        .itemTableId = BATTLE_FRONTIER_ITEM_CHESTO_BERRY,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_LATIAS_1] = {
        .species = SPECIES_LATIAS,
        .moves = {MOVE_PSYCHIC, MOVE_THUNDERBOLT, MOVE_ICE_BEAM, MOVE_DRAGON_CLAW    },
        .itemTableId = BATTLE_FRONTIER_ITEM_LUM_BERRY,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_LATIOS_1] = {
        .species = SPECIES_LATIOS,
        .moves = {MOVE_PSYCHIC, MOVE_THUNDERBOLT, MOVE_ICE_BEAM, MOVE_DRAGON_CLAW    },
        .itemTableId = BATTLE_FRONTIER_ITEM_LUM_BERRY,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_ARTICUNO_2] = {
        .species = SPECIES_ARTICUNO,
        .moves = {MOVE_SUBSTITUTE, MOVE_TOXIC, MOVE_BLIZZARD, MOVE_DOUBLE_TEAM    },
        .itemTableId = BATTLE_FRONTIER_ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_IMPISH,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_ZAPDOS_2] = {
        .species = SPECIES_ZAPDOS,
        .moves = {MOVE_THUNDER, MOVE_RAIN_DANCE, MOVE_DRILL_PECK, MOVE_DOUBLE_TEAM    },
        .itemTableId = BATTLE_FRONTIER_ITEM_BRIGHT_POWDER,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_DOCILE,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_MOLTRES_2] = {
        .species = SPECIES_MOLTRES,
        .moves = {MOVE_OVERHEAT, MOVE_AERIAL_ACE, MOVE_DOUBLE_TEAM, MOVE_PROTECT    },
        .itemTableId = BATTLE_FRONTIER_ITEM_WHITE_HERB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_ATTACK,
        .nature = NATURE_HARDY,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_RAIKOU_2] = {
        .species = SPECIES_RAIKOU,
        .moves = {MOVE_THUNDER, MOVE_RAIN_DANCE, MOVE_DOUBLE_TEAM, MOVE_REFLECT    },
        .itemTableId = BATTLE_FRONTIER_ITEM_BRIGHT_POWDER,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_ENTEI_2] = {
        .species = SPECIES_ENTEI,
        .moves = {MOVE_FIRE_BLAST, MOVE_SUNNY_DAY, MOVE_SOLAR_BEAM, MOVE_REFLECT    },
        .itemTableId = BATTLE_FRONTIER_ITEM_BRIGHT_POWDER,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_SUICUNE_2] = {
        .species = SPECIES_SUICUNE,
        .moves = {MOVE_TOXIC, MOVE_DIVE, MOVE_DOUBLE_TEAM, MOVE_PROTECT    },
        .itemTableId = BATTLE_FRONTIER_ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_CALM,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_REGIROCK_2] = {
        .species = SPECIES_REGIROCK,
        .moves = {MOVE_EARTHQUAKE, MOVE_ROCK_SLIDE, MOVE_COUNTER, MOVE_EXPLOSION    },
        .itemTableId = BATTLE_FRONTIER_ITEM_QUICK_CLAW,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_REGICE_2] = {
        .species = SPECIES_REGICE,
        .moves = {MOVE_THUNDER, MOVE_RAIN_DANCE, MOVE_BLIZZARD, MOVE_BRICK_BREAK    },
        .itemTableId = BATTLE_FRONTIER_ITEM_BRIGHT_POWDER,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_QUIET,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_REGISTEEL_2] = {
        .species = SPECIES_REGISTEEL,
        .moves = {MOVE_THUNDERBOLT, MOVE_ICE_PUNCH, MOVE_EARTHQUAKE, MOVE_AERIAL_ACE    },
        .itemTableId = BATTLE_FRONTIER_ITEM_BRIGHT_POWDER,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_QUIET,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_LATIAS_2] = {
        .species = SPECIES_LATIAS,
        .moves = {MOVE_PSYCHIC, MOVE_THUNDERBOLT, MOVE_ICE_BEAM, MOVE_EARTHQUAKE    },
        .itemTableId = BATTLE_FRONTIER_ITEM_QUICK_CLAW,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_ATTACK,
        .nature = NATURE_DOCILE,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_LATIOS_2] = {
        .species = SPECIES_LATIOS,
        .moves = {MOVE_PSYCHIC, MOVE_THUNDERBOLT, MOVE_ICE_BEAM, MOVE_EARTHQUAKE    },
        .itemTableId = BATTLE_FRONTIER_ITEM_QUICK_CLAW,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_ATTACK,
        .nature = NATURE_DOCILE,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_ARTICUNO_3] = {
        .species = SPECIES_ARTICUNO,
        .moves = {MOVE_ICE_BEAM, MOVE_FACADE, MOVE_AERIAL_ACE, MOVE_PROTECT    },
        .itemTableId = BATTLE_FRONTIER_ITEM_BRIGHT_POWDER,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_ATTACK,
        .nature = NATURE_DOCILE,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_ZAPDOS_3] = {
        .species = SPECIES_ZAPDOS,
        .moves = {MOVE_THUNDERBOLT, MOVE_DRILL_PECK, MOVE_THUNDER_WAVE, MOVE_SUBSTITUTE    },
        .itemTableId = BATTLE_FRONTIER_ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_DOCILE,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_MOLTRES_3] = {
        .species = SPECIES_MOLTRES,
        .moves = {MOVE_FIRE_BLAST, MOVE_SUNNY_DAY, MOVE_DOUBLE_TEAM, MOVE_REST    },
        .itemTableId = BATTLE_FRONTIER_ITEM_CHESTO_BERRY,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_RAIKOU_3] = {
        .species = SPECIES_RAIKOU,
        .moves = {MOVE_THUNDERBOLT, MOVE_THUNDER_WAVE, MOVE_QUICK_ATTACK, MOVE_ROAR    },
        .itemTableId = BATTLE_FRONTIER_ITEM_KINGS_ROCK,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_ENTEI_3] = {
        .species = SPECIES_ENTEI,
        .moves = {MOVE_FLAMETHROWER, MOVE_DOUBLE_EDGE, MOVE_SWAGGER, MOVE_PSYCH_UP    },
        .itemTableId = BATTLE_FRONTIER_ITEM_LUM_BERRY,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_DOCILE,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_SUICUNE_3] = {
        .species = SPECIES_SUICUNE,
        .moves = {MOVE_SURF, MOVE_ICE_BEAM, MOVE_RAIN_DANCE, MOVE_ROAR    },
        .itemTableId = BATTLE_FRONTIER_ITEM_LUM_BERRY,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_REGIROCK_3] = {
        .species = SPECIES_REGIROCK,
        .moves = {MOVE_ROCK_SLIDE, MOVE_EARTHQUAKE, MOVE_CURSE, MOVE_REST    },
        .itemTableId = BATTLE_FRONTIER_ITEM_CHESTO_BERRY,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_REGICE_3] = {
        .species = SPECIES_REGICE,
        .moves = {MOVE_ICE_BEAM, MOVE_THUNDERBOLT, MOVE_THUNDER_WAVE, MOVE_EXPLOSION    },
        .itemTableId = BATTLE_FRONTIER_ITEM_LUM_BERRY,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_QUIET,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_REGISTEEL_3] = {
        .species = SPECIES_REGISTEEL,
        .moves = {MOVE_ANCIENT_POWER, MOVE_AMNESIA, MOVE_COUNTER, MOVE_EXPLOSION    },
        .itemTableId = BATTLE_FRONTIER_ITEM_QUICK_CLAW,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_LATIAS_3] = {
        .species = SPECIES_LATIAS,
        .moves = {MOVE_DRAGON_CLAW, MOVE_THUNDERBOLT, MOVE_ICE_BEAM, MOVE_EARTHQUAKE    },
        .itemTableId = BATTLE_FRONTIER_ITEM_FOCUS_BAND,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_ATTACK,
        .nature = NATURE_DOCILE,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_LATIOS_3] = {
        .species = SPECIES_LATIOS,
        .moves = {MOVE_DRAGON_CLAW, MOVE_THUNDERBOLT, MOVE_ICE_BEAM, MOVE_EARTHQUAKE    },
        .itemTableId = BATTLE_FRONTIER_ITEM_FOCUS_BAND,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_ATTACK,
        .nature = NATURE_DOCILE,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_ARTICUNO_4] = {
        .species = SPECIES_ARTICUNO,
        .moves = {MOVE_BLIZZARD, MOVE_DOUBLE_EDGE, MOVE_REST, MOVE_REFLECT    },
        .itemTableId = BATTLE_FRONTIER_ITEM_CHESTO_BERRY,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_ATTACK,
        .nature = NATURE_DOCILE,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_ZAPDOS_4] = {
        .species = SPECIES_ZAPDOS,
        .moves = {MOVE_THUNDERBOLT, MOVE_DRILL_PECK, MOVE_THUNDER_WAVE, MOVE_LIGHT_SCREEN    },
        .itemTableId = BATTLE_FRONTIER_ITEM_SHELL_BELL,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_ATTACK,
        .nature = NATURE_DOCILE,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_MOLTRES_4] = {
        .species = SPECIES_MOLTRES,
        .moves = {MOVE_OVERHEAT, MOVE_DOUBLE_EDGE, MOVE_STEEL_WING, MOVE_SAFEGUARD    },
        .itemTableId = BATTLE_FRONTIER_ITEM_WHITE_HERB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_ATTACK,
        .nature = NATURE_QUIET,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_RAIKOU_4] = {
        .species = SPECIES_RAIKOU,
        .moves = {MOVE_THUNDERBOLT, MOVE_BITE, MOVE_THUNDER_WAVE, MOVE_REFLECT    },
        .itemTableId = BATTLE_FRONTIER_ITEM_LUM_BERRY,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_ENTEI_4] = {
        .species = SPECIES_ENTEI,
        .moves = {MOVE_FLAMETHROWER, MOVE_BITE, MOVE_DOUBLE_TEAM, MOVE_REFLECT    },
        .itemTableId = BATTLE_FRONTIER_ITEM_KINGS_ROCK,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_SUICUNE_4] = {
        .species = SPECIES_SUICUNE,
        .moves = {MOVE_SURF, MOVE_ICE_BEAM, MOVE_BITE, MOVE_REFLECT    },
        .itemTableId = BATTLE_FRONTIER_ITEM_BRIGHT_POWDER,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_REGIROCK_4] = {
        .species = SPECIES_REGIROCK,
        .moves = {MOVE_ROCK_SLIDE, MOVE_BRICK_BREAK, MOVE_DOUBLE_TEAM, MOVE_THUNDER_WAVE    },
        .itemTableId = BATTLE_FRONTIER_ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_CAREFUL,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_REGICE_4] = {
        .species = SPECIES_REGICE,
        .moves = {MOVE_ICE_BEAM, MOVE_HAIL, MOVE_DOUBLE_TEAM, MOVE_THUNDER_WAVE    },
        .itemTableId = BATTLE_FRONTIER_ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_BOLD,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_REGISTEEL_4] = {
        .species = SPECIES_REGISTEEL,
        .moves = {MOVE_ANCIENT_POWER, MOVE_EARTHQUAKE, MOVE_DOUBLE_TEAM, MOVE_THUNDER_WAVE    },
        .itemTableId = BATTLE_FRONTIER_ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_IMPISH,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_LATIAS_4] = {
        .species = SPECIES_LATIAS,
        .moves = {MOVE_MIST_BALL, MOVE_SHADOW_BALL, MOVE_CHARM, MOVE_REFLECT    },
        .itemTableId = BATTLE_FRONTIER_ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_DOCILE,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_LATIOS_4] = {
        .species = SPECIES_LATIOS,
        .moves = {MOVE_LUSTER_PURGE, MOVE_THUNDERBOLT, MOVE_ICE_BEAM, MOVE_DRAGON_CLAW    },
        .itemTableId = BATTLE_FRONTIER_ITEM_LUM_BERRY,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_GENGAR_5] = {
        .species = SPECIES_GENGAR,
        .moves = {MOVE_PSYCHIC, MOVE_SHADOW_BALL, MOVE_THUNDERBOLT, MOVE_FIRE_PUNCH    },
        .itemTableId = BATTLE_FRONTIER_ITEM_BRIGHT_POWDER,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_GENGAR_6] = {
        .species = SPECIES_GENGAR,
        .moves = {MOVE_PSYCHIC, MOVE_SHADOW_BALL, MOVE_THUNDERBOLT, MOVE_ICE_PUNCH    },
        .itemTableId = BATTLE_FRONTIER_ITEM_BRIGHT_POWDER,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_GENGAR_7] = {
        .species = SPECIES_GENGAR,
        .moves = {MOVE_PSYCHIC, MOVE_THUNDERBOLT, MOVE_FIRE_PUNCH, MOVE_DESTINY_BOND    },
        .itemTableId = BATTLE_FRONTIER_ITEM_LUM_BERRY,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_GENGAR_8] = {
        .species = SPECIES_GENGAR,
        .moves = {MOVE_PSYCHIC, MOVE_THUNDERBOLT, MOVE_ICE_PUNCH, MOVE_DESTINY_BOND    },
        .itemTableId = BATTLE_FRONTIER_ITEM_LUM_BERRY,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_URSARING_5] = {
        .species = SPECIES_URSARING,//TO REMOVE
        .moves = {MOVE_SWORDS_DANCE, MOVE_FACADE, MOVE_PLAY_ROUGH, MOVE_FIRE_PUNCH},
        .itemTableId = BATTLE_FRONTIER_ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_JOLLY,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_URSARING_6] = {
        .species = SPECIES_URSARING,//TO REMOVE
        .moves = {MOVE_SWORDS_DANCE, MOVE_FACADE, MOVE_PLAY_ROUGH, MOVE_FIRE_PUNCH},
        .itemTableId = BATTLE_FRONTIER_ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_JOLLY,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_URSARING_7] = {
        .species = SPECIES_URSARING,//TO REMOVE
        .moves = {MOVE_SWORDS_DANCE, MOVE_FACADE, MOVE_PLAY_ROUGH, MOVE_FIRE_PUNCH},
        .itemTableId = BATTLE_FRONTIER_ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_JOLLY,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_URSARING_8] = {
        .species = SPECIES_URSARING,//TO REMOVE
        .moves = {MOVE_SWORDS_DANCE, MOVE_FACADE, MOVE_PLAY_ROUGH, MOVE_FIRE_PUNCH},
        .itemTableId = BATTLE_FRONTIER_ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_JOLLY,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_MACHAMP_5] = {
        .species = SPECIES_MACHAMP,
        .moves = {MOVE_CROSS_CHOP, MOVE_DOUBLE_EDGE, MOVE_EARTHQUAKE, MOVE_ROCK_SLIDE    },
        .itemTableId = BATTLE_FRONTIER_ITEM_SCOPE_LENS,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_MACHAMP_6] = {
        .species = SPECIES_MACHAMP,
        .moves = {MOVE_CROSS_CHOP, MOVE_EARTHQUAKE, MOVE_COUNTER, MOVE_ROCK_TOMB    },
        .itemTableId = BATTLE_FRONTIER_ITEM_FOCUS_BAND,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_MACHAMP_7] = {
        .species = SPECIES_MACHAMP,
        .moves = {MOVE_FOCUS_PUNCH, MOVE_SUBSTITUTE, MOVE_ATTRACT, MOVE_DOUBLE_TEAM    },
        .itemTableId = BATTLE_FRONTIER_ITEM_BRIGHT_POWDER,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_MACHAMP_8] = {
        .species = SPECIES_MACHAMP,
        .moves = {MOVE_REVENGE, MOVE_ROCK_SLIDE, MOVE_FACADE, MOVE_COUNTER    },
        .itemTableId = BATTLE_FRONTIER_ITEM_FOCUS_BAND,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_GARDEVOIR_5] = {
        .species = SPECIES_GARDEVOIR,//TO REMOVE
        .moves = {MOVE_HYPER_VOICE, MOVE_PSYSHOCK, MOVE_SHADOW_BALL, MOVE_THUNDERBOLT},
        .itemTableId = BATTLE_FRONTIER_ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_SP_ATTACK,
        .nature = NATURE_TIMID,
        .abilitynum = ABILITY_1
    },
    [FRONTIER_MON_GARDEVOIR_6] = {
        .species = SPECIES_GARDEVOIR,//TO REMOVE
        .moves = {MOVE_HYPER_VOICE, MOVE_PSYSHOCK, MOVE_SHADOW_BALL, MOVE_THUNDERBOLT},
        .itemTableId = BATTLE_FRONTIER_ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_SP_ATTACK,
        .nature = NATURE_TIMID,
        .abilitynum = ABILITY_1
    },
    [FRONTIER_MON_GARDEVOIR_7] = {
        .species = SPECIES_GARDEVOIR,//TO REMOVE
        .moves = {MOVE_HYPER_VOICE, MOVE_PSYSHOCK, MOVE_SHADOW_BALL, MOVE_THUNDERBOLT},
        .itemTableId = BATTLE_FRONTIER_ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_SP_ATTACK,
        .nature = NATURE_TIMID,
        .abilitynum = ABILITY_1
    },
    [FRONTIER_MON_GARDEVOIR_8] = {
        .species = SPECIES_GARDEVOIR,//TO REMOVE
        .moves = {MOVE_HYPER_VOICE, MOVE_PSYSHOCK, MOVE_SHADOW_BALL, MOVE_THUNDERBOLT},
        .itemTableId = BATTLE_FRONTIER_ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_SP_ATTACK,
        .nature = NATURE_TIMID,
        .abilitynum = ABILITY_1
    },
    [FRONTIER_MON_STARMIE_5] = {
        .species = SPECIES_STARMIE,
        .moves = {MOVE_SURF, MOVE_PSYCHIC, MOVE_RECOVER, MOVE_LIGHT_SCREEN    },
        .itemTableId = BATTLE_FRONTIER_ITEM_LUM_BERRY,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_STARMIE_6] = {
        .species = SPECIES_STARMIE,
        .moves = {MOVE_SURF, MOVE_CONFUSE_RAY, MOVE_THUNDER_WAVE, MOVE_RECOVER    },
        .itemTableId = BATTLE_FRONTIER_ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_CALM,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_STARMIE_7] = {
        .species = SPECIES_STARMIE,
        .moves = {MOVE_PSYCHIC, MOVE_ICE_BEAM, MOVE_COSMIC_POWER, MOVE_RECOVER    },
        .itemTableId = BATTLE_FRONTIER_ITEM_BRIGHT_POWDER,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_STARMIE_8] = {
        .species = SPECIES_STARMIE,
        .moves = {MOVE_SURF, MOVE_THUNDERBOLT, MOVE_COSMIC_POWER, MOVE_RECOVER    },
        .itemTableId = BATTLE_FRONTIER_ITEM_BRIGHT_POWDER,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_LAPRAS_5] = {
        .species = SPECIES_LAPRAS,
        .moves = {MOVE_PSYCHIC, MOVE_THUNDERBOLT, MOVE_IRON_TAIL, MOVE_DOUBLE_EDGE    },
        .itemTableId = BATTLE_FRONTIER_ITEM_SHELL_BELL,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_ATTACK,
        .nature = NATURE_DOCILE,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_LAPRAS_6] = {
        .species = SPECIES_LAPRAS,
        .moves = {MOVE_HYDRO_PUMP, MOVE_THUNDER, MOVE_RAIN_DANCE, MOVE_BLIZZARD    },
        .itemTableId = BATTLE_FRONTIER_ITEM_BRIGHT_POWDER,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_LAPRAS_7] = {
        .species = SPECIES_LAPRAS,
        .moves = {MOVE_SHEER_COLD, MOVE_HORN_DRILL, MOVE_REST, MOVE_SLEEP_TALK    },
        .itemTableId = BATTLE_FRONTIER_ITEM_LEPPA_BERRY,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_CALM,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_LAPRAS_8] = {
        .species = SPECIES_LAPRAS,
        .moves = {MOVE_SHEER_COLD, MOVE_HORN_DRILL, MOVE_SING, MOVE_ATTRACT    },
        .itemTableId = BATTLE_FRONTIER_ITEM_QUICK_CLAW,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_CALM,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_SNORLAX_5] = {
        .species = SPECIES_SNORLAX,
        .moves = {MOVE_MEGA_KICK, MOVE_SHADOW_BALL, MOVE_BRICK_BREAK, MOVE_COUNTER    },
        .itemTableId = BATTLE_FRONTIER_ITEM_QUICK_CLAW,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_SNORLAX_6] = {
        .species = SPECIES_SNORLAX,
        .moves = {MOVE_EARTHQUAKE, MOVE_SHADOW_BALL, MOVE_BRICK_BREAK, MOVE_COUNTER    },
        .itemTableId = BATTLE_FRONTIER_ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_SNORLAX_7] = {
        .species = SPECIES_DIANCIE,//MEGA
        .moves = {MOVE_DIAMOND_STORM, MOVE_MOONBLAST, MOVE_EARTHQUAKE, MOVE_STEALTH_ROCK},
        .itemTableId = BATTLE_FRONTIER_ITEM_DIANCITE,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
		.abilitynum = ABILITY_1
    },
    [FRONTIER_MON_SNORLAX_8] = {
        .species = SPECIES_DIANCIE,//NOT MEGA
        .moves = {MOVE_DIAMOND_STORM, MOVE_EXPLOSION, MOVE_TRICK_ROOM, MOVE_STEALTH_ROCK},
        .itemTableId = BATTLE_FRONTIER_ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
		.abilitynum = ABILITY_1
    },
    [FRONTIER_MON_SALAMENCE_5] = {
        .species = SPECIES_SALAMENCE,
        .moves = {MOVE_RETURN, MOVE_EARTHQUAKE, MOVE_OUTRAGE, MOVE_DRAGON_DANCE},
        .itemTableId = BATTLE_FRONTIER_ITEM_SALAMENCITE,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_JOLLY,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_SALAMENCE_6] = {
        .species = SPECIES_SALAMENCE,
        .moves = {MOVE_HEADBUTT, MOVE_AERIAL_ACE, MOVE_CRUNCH, MOVE_DRAGON_DANCE    },
        .itemTableId = BATTLE_FRONTIER_ITEM_LUM_BERRY,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_HARDY,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_SALAMENCE_7] = {
        .species = SPECIES_SALAMENCE,
        .moves = {MOVE_FLAMETHROWER, MOVE_DRAGON_CLAW, MOVE_CRUNCH, MOVE_BRICK_BREAK    },
        .itemTableId = BATTLE_FRONTIER_ITEM_LUM_BERRY,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_SALAMENCE_8] = {
        .species = SPECIES_SALAMENCE,
        .moves = {MOVE_FLAMETHROWER, MOVE_DRAGON_CLAW, MOVE_CRUNCH, MOVE_ATTRACT    },
        .itemTableId = BATTLE_FRONTIER_ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_METAGROSS_5] = {
        .species = SPECIES_METAGROSS,
        .moves = {MOVE_EXPLOSION, MOVE_EARTHQUAKE, MOVE_ROCK_SLIDE, MOVE_BRICK_BREAK    },
        .itemTableId = BATTLE_FRONTIER_ITEM_QUICK_CLAW,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_JOLLY,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_METAGROSS_6] = {
        .species = SPECIES_METAGROSS,
        .moves = {MOVE_METEOR_MASH, MOVE_PSYCHIC, MOVE_ICE_PUNCH, MOVE_THUNDER_PUNCH    },
        .itemTableId = BATTLE_FRONTIER_ITEM_BRIGHT_POWDER,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_ATTACK,
        .nature = NATURE_HARDY,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_METAGROSS_7] = {
        .species = SPECIES_METAGROSS,
        .moves = {MOVE_EARTHQUAKE, MOVE_SHADOW_BALL, MOVE_ICE_PUNCH, MOVE_THUNDER_PUNCH    },
        .itemTableId = BATTLE_FRONTIER_ITEM_SHELL_BELL,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_ATTACK,
        .nature = NATURE_HARDY,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_METAGROSS_8] = {
        .species = SPECIES_METAGROSS,
        .moves = {MOVE_METEOR_MASH, MOVE_EARTHQUAKE, MOVE_BRICK_BREAK, MOVE_EXPLOSION    },
        .itemTableId = BATTLE_FRONTIER_ITEM_QUICK_CLAW,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_REGIROCK_5] = {
        .species = SPECIES_REGIROCK,
        .moves = {MOVE_HYPER_BEAM, MOVE_FOCUS_PUNCH, MOVE_ROCK_SLIDE, MOVE_DOUBLE_TEAM    },
        .itemTableId = BATTLE_FRONTIER_ITEM_QUICK_CLAW,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_REGIROCK_6] = {
        .species = SPECIES_REGIROCK,
        .moves = {MOVE_SWAGGER, MOVE_PSYCH_UP, MOVE_ROCK_SLIDE, MOVE_EXPLOSION    },
        .itemTableId = BATTLE_FRONTIER_ITEM_BRIGHT_POWDER,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_REGICE_5] = {
        .species = SPECIES_REGICE,
        .moves = {MOVE_EARTHQUAKE, MOVE_ICE_BEAM, MOVE_CURSE, MOVE_COUNTER    },
        .itemTableId = BATTLE_FRONTIER_ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_BRAVE,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_REGICE_6] = {
        .species = SPECIES_REGICE,
        .moves = {MOVE_ICE_BEAM, MOVE_THUNDERBOLT, MOVE_SLEEP_TALK, MOVE_REST    },
        .itemTableId = BATTLE_FRONTIER_ITEM_CHESTO_BERRY,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_REGISTEEL_5] = {
        .species = SPECIES_REGISTEEL,
        .moves = {MOVE_FOCUS_PUNCH, MOVE_SUBSTITUTE, MOVE_TOXIC, MOVE_DOUBLE_TEAM    },
        .itemTableId = BATTLE_FRONTIER_ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_REGISTEEL_6] = {
        .species = SPECIES_REGISTEEL,
        .moves = {MOVE_SUPERPOWER, MOVE_AERIAL_ACE, MOVE_SWAGGER, MOVE_PSYCH_UP    },
        .itemTableId = BATTLE_FRONTIER_ITEM_WHITE_HERB,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_LATIAS_5] = {
        .species = SPECIES_LATIAS,
        .moves = {MOVE_DRAGON_CLAW, MOVE_THUNDER_WAVE, MOVE_CALM_MIND, MOVE_RECOVER    },
        .itemTableId = BATTLE_FRONTIER_ITEM_BRIGHT_POWDER,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_LATIAS_6] = {
        .species = SPECIES_LATIAS,
        .moves = {MOVE_MIST_BALL, MOVE_DRAGON_CLAW, MOVE_ATTRACT, MOVE_THUNDER_WAVE    },
        .itemTableId = BATTLE_FRONTIER_ITEM_SHELL_BELL,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_LATIAS_7] = {
        .species = SPECIES_LATIAS,
        .moves = {MOVE_EARTHQUAKE, MOVE_SHADOW_BALL, MOVE_SWAGGER, MOVE_PSYCH_UP    },
        .itemTableId = BATTLE_FRONTIER_ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_LATIAS_8] = {
        .species = SPECIES_LATIAS,
        .moves = {MOVE_PSYCHIC, MOVE_SHADOW_BALL, MOVE_EARTHQUAKE, MOVE_AERIAL_ACE    },
        .itemTableId = BATTLE_FRONTIER_ITEM_KINGS_ROCK,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_DOCILE,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_LATIOS_5] = {
        .species = SPECIES_LATIOS,
        .moves = {MOVE_DRAGON_CLAW, MOVE_THUNDER_WAVE, MOVE_CALM_MIND, MOVE_RECOVER    },
        .itemTableId = BATTLE_FRONTIER_ITEM_BRIGHT_POWDER,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_LATIOS_6] = {
        .species = SPECIES_LATIOS,
        .moves = {MOVE_LUSTER_PURGE, MOVE_SHADOW_BALL, MOVE_DRAGON_CLAW, MOVE_THUNDER_WAVE    },
        .itemTableId = BATTLE_FRONTIER_ITEM_SHELL_BELL,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_ATTACK,
        .nature = NATURE_DOCILE,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_LATIOS_7] = {
        .species = SPECIES_LATIOS,
        .moves = {MOVE_EARTHQUAKE, MOVE_SHADOW_BALL, MOVE_DRAGON_DANCE, MOVE_RECOVER    },
        .itemTableId = BATTLE_FRONTIER_ITEM_BRIGHT_POWDER,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_LATIOS_8] = {
        .species = SPECIES_LATIOS,
        .moves = {MOVE_PSYCHIC, MOVE_SHADOW_BALL, MOVE_EARTHQUAKE, MOVE_AERIAL_ACE    },
        .itemTableId = BATTLE_FRONTIER_ITEM_KINGS_ROCK,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_DOCILE,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_DRAGONITE_1] = {
        .species = SPECIES_DRAGONITE,
        .moves = {MOVE_EARTHQUAKE, MOVE_AERIAL_ACE, MOVE_BRICK_BREAK, MOVE_DRAGON_DANCE    },
        .itemTableId = BATTLE_FRONTIER_ITEM_BRIGHT_POWDER,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_DRAGONITE_2] = {
        .species = SPECIES_DRAGONITE,
        .moves = {MOVE_EARTHQUAKE, MOVE_DOUBLE_EDGE, MOVE_AERIAL_ACE, MOVE_DRAGON_DANCE    },
        .itemTableId = BATTLE_FRONTIER_ITEM_BRIGHT_POWDER,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_DRAGONITE_3] = {
        .species = SPECIES_DRAGONITE,
        .moves = {MOVE_HYPER_BEAM, MOVE_ATTRACT, MOVE_DOUBLE_TEAM, MOVE_THUNDER_WAVE    },
        .itemTableId = BATTLE_FRONTIER_ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_DEFENSE | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_DRAGONITE_4] = {
        .species = SPECIES_DRAGONITE,
        .moves = {MOVE_HYPER_BEAM, MOVE_THUNDER_WAVE, MOVE_DRAGON_DANCE, MOVE_REST    },
        .itemTableId = BATTLE_FRONTIER_ITEM_CHESTO_BERRY,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_DRAGONITE_5] = {
        .species = SPECIES_DRAGONITE,
        .moves = {MOVE_OUTRAGE, MOVE_DOUBLE_EDGE, MOVE_THUNDER_WAVE, MOVE_ROAR    },
        .itemTableId = BATTLE_FRONTIER_ITEM_LUM_BERRY,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_ATTACK,
        .nature = NATURE_DOCILE,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_DRAGONITE_6] = {
        .species = SPECIES_DRAGONITE,
        .moves = {MOVE_DRAGON_CLAW, MOVE_THUNDERBOLT, MOVE_SURF, MOVE_FLAMETHROWER    },
        .itemTableId = BATTLE_FRONTIER_ITEM_SHELL_BELL,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_DRAGONITE_7] = {
        .species = SPECIES_DRAGONITE,
        .moves = {MOVE_DRAGON_CLAW, MOVE_THUNDERBOLT, MOVE_SURF, MOVE_ICE_BEAM    },
        .itemTableId = BATTLE_FRONTIER_ITEM_SHELL_BELL,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_DRAGONITE_8] = {
        .species = SPECIES_DRAGONITE,
        .moves = {MOVE_DRAGON_CLAW, MOVE_FLAMETHROWER, MOVE_ICE_BEAM, MOVE_BRICK_BREAK    },
        .itemTableId = BATTLE_FRONTIER_ITEM_SHELL_BELL,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_DRAGONITE_9] = {
        .species = SPECIES_DRAGONITE,
        .moves = {MOVE_THUNDER, MOVE_SURF, MOVE_RAIN_DANCE, MOVE_EARTHQUAKE    },
        .itemTableId = BATTLE_FRONTIER_ITEM_QUICK_CLAW,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_DOCILE,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_DRAGONITE_10] = {
        .species = SPECIES_DRAGONITE,
        .moves = {MOVE_FIRE_BLAST, MOVE_BLIZZARD, MOVE_SUNNY_DAY, MOVE_EARTHQUAKE    },
        .itemTableId = BATTLE_FRONTIER_ITEM_QUICK_CLAW,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_DOCILE,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_TYRANITAR_1] = {
        .species = SPECIES_TYRANITAR,
        .moves = {MOVE_SHORE_UP, MOVE_CRUNCH, MOVE_DRAGON_DANCE, MOVE_STONE_EDGE   },
        .itemTableId = BATTLE_FRONTIER_ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_IMPISH,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_TYRANITAR_2] = {
        .species = SPECIES_TYRANITAR,
        .moves = {MOVE_SHORE_UP, MOVE_CRUNCH, MOVE_DRAGON_DANCE, MOVE_STONE_EDGE   },
        .itemTableId = BATTLE_FRONTIER_ITEM_TYRANITARITE,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_DEFENSE,
        .nature = NATURE_IMPISH,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_TYRANITAR_3] = {
        .species = SPECIES_TYRANITAR,
        .moves = {MOVE_SHORE_UP, MOVE_CRUNCH, MOVE_DRAGON_DANCE, MOVE_STONE_EDGE   },
        .itemTableId = BATTLE_FRONTIER_ITEM_TYRANITARITE,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_DEFENSE,
        .nature = NATURE_IMPISH,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_TYRANITAR_4] = {
        .species = SPECIES_TYRANITAR,
        .moves = {MOVE_SHORE_UP, MOVE_CRUNCH, MOVE_DRAGON_DANCE, MOVE_STONE_EDGE   },
        .itemTableId = BATTLE_FRONTIER_ITEM_TYRANITARITE,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_DEFENSE,
        .nature = NATURE_IMPISH,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_TYRANITAR_5] = {
        .species = SPECIES_TYRANITAR,
        .moves = {MOVE_SHORE_UP, MOVE_CRUNCH, MOVE_DRAGON_DANCE, MOVE_STONE_EDGE   },
        .itemTableId = BATTLE_FRONTIER_ITEM_TYRANITARITE,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_DEFENSE,
        .nature = NATURE_IMPISH,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_TYRANITAR_6] = {
        .species = SPECIES_TYRANITAR,
        .moves = {MOVE_SHORE_UP, MOVE_CRUNCH, MOVE_DRAGON_DANCE, MOVE_STONE_EDGE   },
        .itemTableId = BATTLE_FRONTIER_ITEM_TYRANITARITE,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_DEFENSE,
        .nature = NATURE_IMPISH,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_TYRANITAR_7] = {
        .species = SPECIES_TYRANITAR,
        .moves = {MOVE_SHORE_UP, MOVE_CRUNCH, MOVE_DRAGON_DANCE, MOVE_STONE_EDGE   },
        .itemTableId = BATTLE_FRONTIER_ITEM_TYRANITARITE,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_DEFENSE,
        .nature = NATURE_IMPISH,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_TYRANITAR_8] = {
        .species = SPECIES_TYRANITAR,
        .moves = {MOVE_SHORE_UP, MOVE_CRUNCH, MOVE_DRAGON_DANCE, MOVE_STONE_EDGE   },
        .itemTableId = BATTLE_FRONTIER_ITEM_TYRANITARITE,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_DEFENSE,
        .nature = NATURE_IMPISH,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_TYRANITAR_9] = {
        .species = SPECIES_TYRANITAR,
        .moves = {MOVE_SHORE_UP, MOVE_CRUNCH, MOVE_DRAGON_DANCE, MOVE_STONE_EDGE   },
        .itemTableId = BATTLE_FRONTIER_ITEM_TYRANITARITE,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_DEFENSE,
        .nature = NATURE_IMPISH,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_TYRANITAR_10] = {
        .species = SPECIES_TYRANITAR,
        .moves = {MOVE_SHORE_UP, MOVE_CRUNCH, MOVE_DRAGON_DANCE, MOVE_STONE_EDGE   },
        .itemTableId = BATTLE_FRONTIER_ITEM_TYRANITARITE,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_DEFENSE,
        .nature = NATURE_IMPISH,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_ARTICUNO_5] = {
        .species = SPECIES_ARTICUNO,
        .moves = {MOVE_ICE_BEAM, MOVE_HURRICANE, MOVE_AURA_SPHERE, MOVE_SHEER_COLD    },
        .itemTableId = BATTLE_FRONTIER_ITEM_FOCUS_SASH,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_SP_ATTACK,
        .nature = NATURE_TIMID,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_ARTICUNO_6] = {
        .species = SPECIES_ARTICUNO_GALARIAN,
        .moves = {MOVE_ICE_BEAM, MOVE_HURRICANE, MOVE_AURA_SPHERE, MOVE_PSYSHOCK    },
        .itemTableId = BATTLE_FRONTIER_ITEM_FOCUS_SASH,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_SP_ATTACK,
        .nature = NATURE_TIMID,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_ZAPDOS_5] = {
        .species = SPECIES_ZAPDOS,
        .moves = {MOVE_THUNDER, MOVE_HURRICANE, MOVE_RAIN_DANCE, MOVE_ROOST    },
        .itemTableId = BATTLE_FRONTIER_ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_ATTACK,
        .nature = NATURE_TIMID,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_ZAPDOS_6] = {
        .species = SPECIES_ZAPDOS_GALARIAN,
        .moves = {MOVE_CLOSE_COMBAT, MOVE_DRILL_PECK, MOVE_ROOST, MOVE_BLAZE_KICK    },
        .itemTableId = BATTLE_FRONTIER_ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_JOLLY,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_MOLTRES_5] = {
        .species = SPECIES_MOLTRES,
        .moves = {MOVE_OVERHEAT, MOVE_HURRICANE, MOVE_SOLAR_BEAM, MOVE_ANCIENT_POWER    },
        .itemTableId = BATTLE_FRONTIER_ITEM_WHITE_HERB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_MOLTRES_6] = {
        .species = SPECIES_MOLTRES_GALARIAN,
        .moves = {MOVE_FIERY_DANCE, MOVE_DARK_PULSE, MOVE_HURRICANE, MOVE_ROOST    },
        .itemTableId = BATTLE_FRONTIER_ITEM_FOCUS_SASH,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_RAIKOU_5] = {
        .species = SPECIES_PHEROMOSA,
        .moves = {MOVE_HI_JUMP_KICK, MOVE_ICE_BEAM, MOVE_BUG_BUZZ, MOVE_STONE_EDGE    },
        .itemTableId = BATTLE_FRONTIER_ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_RAIKOU_6] = {
        .species = SPECIES_RAIKOU,
        .moves = {MOVE_THUNDERBOLT, MOVE_CALM_MIND, MOVE_SUBSTITUTE, MOVE_AURA_SPHERE    },
        .itemTableId = BATTLE_FRONTIER_ITEM_LIFE_ORB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_ENTEI_5] = {
        .species = SPECIES_MELMETAL,
        .moves = {MOVE_THUNDER_PUNCH, MOVE_IRON_HEAD, MOVE_EARTHQUAKE, MOVE_STONE_EDGE    },
        .itemTableId = BATTLE_FRONTIER_ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_DEFENSE,
        .nature = NATURE_ADAMANT,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_ENTEI_6] = {
        .species = SPECIES_ENTEI,
        .moves = {MOVE_SACRED_FIRE, MOVE_EARTHQUAKE, MOVE_IRON_HEAD, MOVE_STONE_EDGE    },
        .itemTableId = BATTLE_FRONTIER_ITEM_ASSAULT_VEST,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_ADAMANT,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_SUICUNE_5] = {
        .species = SPECIES_URSHIFU_RAPID_STRIKE_STYLE,
        .moves = {MOVE_CLOSE_COMBAT, MOVE_LIQUIDATION, MOVE_ICE_PUNCH, MOVE_IRON_HEAD    },
        .itemTableId = BATTLE_FRONTIER_ITEM_LUM_BERRY,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_JOLLY,
        .abilitynum = ABILITY_RANDOM
    },
    [FRONTIER_MON_SUICUNE_6] = {
        .species = SPECIES_SUICUNE,
        .moves = {MOVE_SCALD, MOVE_ICE_BEAM, MOVE_CALM_MIND, MOVE_REST    },
        .itemTableId = BATTLE_FRONTIER_ITEM_CHESTO_BERRY,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST
    }
};
