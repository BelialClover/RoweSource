#ifndef GUARD_CONSTANTS_QUESTS_H
#define GUARD_CONSTANTS_QUESTS_H

//questmenu scripting command params
#define QUEST_MENU_OPEN                 0   //opens the quest menu (questId = 0)
#define QUEST_MENU_UNLOCK_QUEST         1   //questId = SIDE_QUEST_X (0-indexed)
#define QUEST_MENU_COMPLETE_QUEST       2   //questId = SIDE_QUEST_X (0-indexed)
#define QUEST_MENU_SET_ACTIVE           3   //questId = SIDE_QUEST_X (0-indexed)
#define QUEST_MENU_RESET_ACTIVE         4   //remove current quest from being 'active'
#define QUEST_MENU_BUFFER_QUEST_NAME    5   //buffers a quest name to gStringVar1
#define QUEST_MENU_GET_ACTIVE_QUEST     6   //returns the active quest index (-1, or 0xFF for none)
#define QUEST_MENU_CHECK_UNLOCKED       7   //checks if questId has been unlocked. Returns result to gSpecialVar_Result
#define QUEST_MENU_CHECK_COMPLETE       8   //checks if questId has been completed. Returns result to gSpecialVar_Result

// quest number defines
#define SIDE_QUEST_1          0
#define SIDE_QUEST_2          1
#define SIDE_QUEST_3          2
#define SIDE_QUEST_4          3
#define SIDE_QUEST_5          4
#define SIDE_QUEST_6          5
#define SIDE_QUEST_7          6
#define SIDE_QUEST_8          7
#define SIDE_QUEST_9          8
#define SIDE_QUEST_10         9
#define SIDE_QUEST_11        10
#define SIDE_QUEST_12        11
#define SIDE_QUEST_13        12
#define SIDE_QUEST_14        13
#define SIDE_QUEST_15        14
#define SIDE_QUEST_16        15
#define SIDE_QUEST_17        16
#define SIDE_QUEST_18        17
#define SIDE_QUEST_19        18
#define SIDE_QUEST_20        19
#define SIDE_QUEST_21        20
#define SIDE_QUEST_22        21
#define SIDE_QUEST_23        22
#define SIDE_QUEST_24        23
#define SIDE_QUEST_25        24
#define SIDE_QUEST_26        25
#define SIDE_QUEST_27        26
#define SIDE_QUEST_28        27
#define SIDE_QUEST_29        28
#define SIDE_QUEST_30        29
#define SIDE_QUEST_31        30
#define SIDE_QUEST_32        31
#define SIDE_QUEST_33        32
#define SIDE_QUEST_34        33
#define SIDE_QUEST_35        34
#define SIDE_QUEST_36        35
#define SIDE_QUEST_37        36
#define SIDE_QUEST_38        37
#define SIDE_QUEST_39        38
#define SIDE_QUEST_40        39
#define SIDE_QUEST_41        40
#define SIDE_QUEST_42        41
#define SIDE_QUEST_43        42
#define SIDE_QUEST_44        43
#define SIDE_QUEST_45        44
#define SIDE_QUEST_46        45
#define SIDE_QUEST_47        46
#define SIDE_QUEST_48        47
#define SIDE_QUEST_49        48
#define SIDE_QUEST_50        49
#define SIDE_QUEST_51        50
#define SIDE_QUEST_52        51
#define SIDE_QUEST_53        52
#define SIDE_QUEST_54        53
#define SIDE_QUEST_55        54
#define SIDE_QUEST_56        55
#define SIDE_QUEST_57        56
#define SIDE_QUEST_58        57
#define SIDE_QUEST_59        58
#define SIDE_QUEST_60        59
#define SIDE_QUEST_61        60
#define SIDE_QUEST_62        61
#define SIDE_QUEST_63        62
#define SIDE_QUEST_64        63
#define SIDE_QUEST_65        64
#define SIDE_QUEST_66        65
#define SIDE_QUEST_67        66
#define SIDE_QUEST_68        67
#define SIDE_QUEST_69        68
#define SIDE_QUEST_70        69
#define SIDE_QUEST_71        70
#define SIDE_QUEST_72        71
#define SIDE_QUEST_73        72
#define SIDE_QUEST_74        73
#define SIDE_QUEST_75        74
#define SIDE_QUEST_76        75
#define SIDE_QUEST_77        76
#define SIDE_QUEST_78        77
#define SIDE_QUEST_79        78
#define SIDE_QUEST_80        79
#define SIDE_QUEST_81        80
#define SIDE_QUEST_82        81
#define SIDE_QUEST_83        82
#define SIDE_QUEST_84        83
#define SIDE_QUEST_85        84
#define SIDE_QUEST_86        85
#define SIDE_QUEST_87        86
#define SIDE_QUEST_88        87
#define SIDE_QUEST_89        88
#define SIDE_QUEST_90        89
#define SIDE_QUEST_91        90
#define SIDE_QUEST_92        91
#define SIDE_QUEST_93        92
#define SIDE_QUEST_94        93
#define SIDE_QUEST_95        94
#define SIDE_QUEST_96        95
#define SIDE_QUEST_97        96
#define SIDE_QUEST_98        97
#define SIDE_QUEST_99        98
#define SIDE_QUEST_100       99
#define SIDE_QUEST_COUNT     (SIDE_QUEST_100 + 1)

#endif // GUARD_CONSTANTS_QUESTS_H