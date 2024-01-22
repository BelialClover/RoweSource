#ifndef GUARD_CONSTANTS_GLOBAL_H
#define GUARD_CONSTANTS_GLOBAL_H
// Invalid Versions show as "----------" in Gen 4 and Gen 5's summary screen.
// In Gens 6 and 7, invalid versions instead show "a distant land" in the summary screen.
// In Gen 4 only, migrated Pokemon with Diamond, Pearl, or Platinum's ID show as "----------".
// Gen 5 and up read Diamond, Pearl, or Platinum's ID as "Sinnoh".
// In Gen 4 and up, migrated Pokemon with HeartGold or SoulSilver's ID show the otherwise unused "Johto" string.
#define VERSION_SAPPHIRE 1
#define VERSION_RUBY 2
#define VERSION_EMERALD 3
#define VERSION_FIRE_RED 4
#define VERSION_LEAF_GREEN 5
#define VERSION_HEART_GOLD 7
#define VERSION_SOUL_SILVER 8
#define VERSION_DIAMOND 10
#define VERSION_PEARL 11
#define VERSION_PLATINUM 12
#define VERSION_GAMECUBE 15

#define LANGUAGE_JAPANESE 1
#define LANGUAGE_ENGLISH  2
#define LANGUAGE_FRENCH   3
#define LANGUAGE_ITALIAN  4
#define LANGUAGE_GERMAN   5
#define LANGUAGE_KOREAN   6 // 6 goes unused but the theory is it was meant to be Korean
#define LANGUAGE_SPANISH  7
#define NUM_LANGUAGES     7

#define GAME_VERSION (VERSION_EMERALD)
#define GAME_LANGUAGE (LANGUAGE_ENGLISH)

// capacities of various saveblock objects
#define DAYCARE_MON_COUNT 2
#define POKEBLOCKS_COUNT 40
#define OBJECT_EVENTS_COUNT 16
#define BERRY_TREES_COUNT 128
#define MAIL_COUNT 16
#define SECRET_BASES_COUNT 5
#define TV_SHOWS_COUNT 25
#define POKE_NEWS_COUNT 16
#define PC_ITEMS_COUNT 50
#define BAG_ITEMS_COUNT 80
#define BAG_KEYITEMS_COUNT 50
#define BAG_POKEBALLS_COUNT 31
#define BAG_TMHM_COUNT 208
#define NUM_TMS 120
#define BAG_BERRIES_COUNT 70
#define BAG_MEDICINE_COUNT 40
#define BAG_BATTLEITEMS_COUNT 100
#define BAG_POWERUP_COUNT 70
#define BAG_TYPEITEMS_COUNT 80
#define BAG_MEGASTONES_COUNT 47
#define OBJECT_EVENT_TEMPLATES_COUNT 64
#define DECOR_MAX_SECRET_BASE 16
#define DECOR_MAX_PLAYERS_HOUSE 12
#define APPRENTICE_COUNT 4
#define APPRENTICE_MAX_QUESTIONS 9
#define MAX_REMATCH_ENTRIES 100 // only REMATCH_TABLE_ENTRIES (78) are used
#define NUM_CONTEST_WINNERS 13
#define UNION_ROOM_KB_ROW_COUNT 10

#define PYRAMID_BAG_ITEMS_COUNT 10
#define HALL_FACILITIES_COUNT 9 // 7 facilities for single mode + tower double mode + tower multi mode.

#define TRAINER_ID_LENGTH 4
#define MAX_MON_MOVES 4
#define NUM_STATS 6

#define CONTESTANT_COUNT 4
#define CONTEST_CATEGORY_COOL     0
#define CONTEST_CATEGORY_BEAUTY   1
#define CONTEST_CATEGORY_CUTE     2
#define CONTEST_CATEGORY_SMART    3
#define CONTEST_CATEGORY_TOUGH    4
#define CONTEST_CATEGORIES_COUNT  5

// party sizes
#define PARTY_SIZE 6
#define MULTI_PARTY_SIZE PARTY_SIZE / 2
#define FRONTIER_PARTY_SIZE         3
#define FRONTIER_DOUBLES_PARTY_SIZE 4
#define FRONTIER_MULTI_PARTY_SIZE   2
#define MAX_FRONTIER_PARTY_SIZE     FRONTIER_DOUBLES_PARTY_SIZE
#define UNION_ROOM_PARTY_SIZE       2

// string lengths
#define ITEM_NAME_LENGTH 18
#define POKEMON_NAME_LENGTH 10
#define PLAYER_NAME_LENGTH 7
#define MAIL_WORDS_COUNT 9
#define EASY_CHAT_BATTLE_WORDS_COUNT 6
#define MOVE_NAME_LENGTH 16

#define MALE 0
#define FEMALE 1
#define GENDER_COUNT 2

#define BARD_SONG_LENGTH       6
#define NUM_STORYTELLER_TALES  4
#define NUM_TRADER_ITEMS       4

#define OPTIONS_BUTTON_MODE_NORMAL 0
#define OPTIONS_BUTTON_MODE_LR 1
#define OPTIONS_BUTTON_MODE_L_EQUALS_A 2

#define OPTIONS_TEXT_SPEED_SLOW 0
#define OPTIONS_TEXT_SPEED_MID 1
#define OPTIONS_TEXT_SPEED_FAST 2
#define OPTIONS_TEXT_SPEED_INSTANT 3

#define OPTIONS_SOUND_MONO 0
#define OPTIONS_SOUND_STEREO 1

#define OPTIONS_BATTLE_STYLE_SHIFT 0
#define OPTIONS_BATTLE_STYLE_SET 1

#define OPTIONS_TRANSITION_NORMAL 0
#define OPTIONS_TRANSITION_INSTANT 1

#define OPTIONS_MUSIC_KANTO  0
#define OPTIONS_MUSIC_JOTHO  1
#define OPTIONS_MUSIC_HOENN  2
#define OPTIONS_MUSIC_SINNOH 3

#define DIR_NONE        0
#define DIR_SOUTH       1
#define DIR_NORTH       2
#define DIR_WEST        3
#define DIR_EAST        4
#define DIR_SOUTHWEST   5
#define DIR_SOUTHEAST   6
#define DIR_NORTHWEST   7
#define DIR_NORTHEAST   8

//Mystery Gift
#define GAME_CODE_LENGTH 4
#define NUM_QUESTIONNAIRE_WORDS 4
#define WONDER_CARD_TEXT_LENGTH 40
#define WONDER_NEWS_TEXT_LENGTH 40
#define WONDER_CARD_BODY_TEXT_LINES 4
#define WONDER_NEWS_BODY_TEXT_LINES 10

#define MAX_STAMP_CARD_STAMPS 7

// Values for the type field of Wonder CardBAG_TMHM_COUNT
#define CARD_TYPE_GIFT       0 // Normal "Wonder Card"
#define CARD_TYPE_STAMP      1 // "Stamp Card"
#define CARD_TYPE_LINK_STAT  2 // Referred to as the "Battle Card", shows battle and trade stats
#define CARD_TYPE_COUNT      3

// Values for the sendType field of Wonder Card/News
#define SEND_TYPE_DISALLOWED     0
#define SEND_TYPE_ALLOWED        1
#define SEND_TYPE_ALLOWED_ALWAYS 2

// Return values for MysteryGift_CompareCardFlags, handled by gMysteryGiftServerScript_SendWonderCard
#define HAS_NO_CARD   0
#define HAS_SAME_CARD 1
#define HAS_DIFF_CARD 2

// The number of battles needed to be recorded on a Battle Card to win a prize
#define REQUIRED_CARD_BATTLES 3

// Stamps are 32 bits. The first 16 bits are the species
// and the second 16 bits are a number (presumably an ID of some kind)
#define STAMP_SPECIES 0
#define STAMP_ID      1

// Number of different types/colors of Wonder Card and News backgrounds
#define NUM_WONDER_BGS 8

#define MAX_WONDER_CARD_STAT 999

#define WONDER_CARD_FLAG_OFFSET 1000

//Genders
#define GENDER_MALE	      0
#define GENDER_FEMALE	  1

#define NUM_GENDERS 	  2

//Saveblock Toggle Stuff
#define COMPANION_TRAINER_PASSWORD         0
#define COMPANION_WORKING_PASSWORD_TRAINER 1
#define COMPANION_WORKING_ROAMER           2

//Cry Types
#define CRY_TYPE_DISABLED 0
#define CRY_TYPE_GENERIC  1
#define CRY_TYPE_NORMAL   2
#define CRY_TYPE_ANIME    3

#endif // GUARD_CONSTANTS_GLOBAL_H
