Common_EventScript_PkmnCenterNurse:: @ 827191E
    lock
    faceplayer
	goto_if_unset FLAG_UPDATED_SAVE, EventScript_PkmnCenterNurse_CheckUpdatedSave
	goto_if_unset FLAG_UPDATED_SAVE_2, EventScript_PkmnCenterNurse_CheckUpdatedSave_3
    setvar VAR_0x8004, 0
    specialvar VAR_RESULT, CountPlayerTrainerStars
    compare VAR_RESULT, 4
    goto_if_eq EventScript_PkmnCenterNurse_GoldCard
    @ msgbox gText_WouldYouLikeToRestYourPkmn, MSGBOX_YESNO
    @ compare VAR_RESULT, YES
    @ goto_if_eq EventScript_PkmnCenterNurse_HealPkmn
    @ compare VAR_RESULT, NO
    @ goto_if_eq EventScript_PkmnCenterNurse_Goodbye
    goto EventScript_PkmnCenterNurse_HealPkmn
    end

EventScript_PkmnCenterNurse_Goodbye:: @ 8271954
    message gText_WeHopeToSeeYouAgain
    return

@ VAR_0x8004 is 1 when player has Gold Card; jumps are identical
EventScript_PkmnCenterNurse_HealPkmn:: @ 827195A
    incrementgamestat GAME_STAT_USED_POKECENTER
    compare VAR_0x8004, 0
    call_if_eq EventScript_PkmnCenterNurse_IllTakeYourPkmn
    compare VAR_0x8004, 1
    call_if_eq EventScript_PkmnCenterNurse_IllTakeYourPkmn2
    waitmessage
    call EventScript_PkmnCenterNurse_TakeAndHealPkmn
    goto_if_unset FLAG_POKERUS_EXPLAINED, EventScript_PkmnCenterNurse_CheckPokerus
    goto EventScript_PkmnCenterNurse_ReturnPkmn
    end

EventScript_PkmnCenterNurse_IllTakeYourPkmn:: @ 8271987
    message gText_IllTakeYourPkmn
    return

EventScript_PkmnCenterNurse_IllTakeYourPkmn2:: @ 827198D
    message gText_IllTakeYourPkmn2
    return

EventScript_PkmnCenterNurse_TakeAndHealPkmn:: @ 8271993
    applymovement VAR_0x800B, Common_Movement_WalkInPlaceFastestLeft
    waitmovement 0
    dofieldeffect FLDEFF_POKECENTER_HEAL
    //waitfieldeffect FLDEFF_POKECENTER_HEAL
	delay 90
	delay 90
	delay 90
    applymovement VAR_0x800B, Common_Movement_WalkInPlaceFastestDown
    waitmovement 0
    special HealPlayerParty
    return

EventScript_PkmnCenterNurse_CheckTrainerHillAndUnionRoom:: @ 82719B1
    specialvar VAR_RESULT, PlayerNotAtTrainerHillEntrance
    compare VAR_RESULT, 0
    goto_if_eq EventScript_PkmnCenterNurse_ReturnPkmn
    specialvar VAR_RESULT, BufferUnionRoomPlayerName
    copyvar VAR_0x8008, VAR_RESULT
    compare VAR_0x8008, 0
    goto_if_eq EventScript_PkmnCenterNurse_ReturnPkmn
    compare VAR_0x8008, 1
    goto_if_eq EventScript_PkmnCenterNurse_PlayerWaitingInUnionRoom
    end

@ VAR_0x8004 is 1 when player has Gold Card
EventScript_PkmnCenterNurse_ReturnPkmn:: @ 82719E2
    compare VAR_0x8004, 1
    goto_if_eq EventScript_PkmnCenterNurse_ReturnPkmn2
    @ message gText_RestoredPkmnToFullHealth
    @ waitmessage
    applymovement VAR_0x800B, EventScript_PkmnCenterNurse_Bow
    waitmovement 0
    message gText_WeHopeToSeeYouAgain
    goto EventScript_PkmnCenterNurse_PlayerTurn
    return

PkmnCenterNurse_Movement_FaceDown: @ 81EBDC2
	face_down
	step_end

EventScript_PkmnCenterNurse_ReturnPkmn2:: @ 8271A03
    goto EventScript_PkmnCenterNurse_PlayerTurn

EventScript_PkmnCenterNurse_PlayerWaitingInUnionRoom:: @ 8271A19
    goto_if_set FLAG_NURSE_UNION_ROOM_REMINDER, EventScript_PkmnCenterNurse_ReturnPkmn
    msgbox gText_RestoredPkmnToFullHealth, MSGBOX_DEFAULT
    setflag FLAG_NURSE_UNION_ROOM_REMINDER
    message CableClub_Text_PlayerIsWaiting
    waitmessage
    applymovement VAR_0x800B, EventScript_PkmnCenterNurse_Bow
    waitmovement 0
    message gText_WeHopeToSeeYouAgain
    return

EventScript_PkmnCenterNurse_CheckPokerus:: @ 8271A43
    specialvar VAR_RESULT, IsPokerusInParty
    compare VAR_RESULT, TRUE
    goto_if_eq EventScript_PkmnCenterNurse_ExplainPokerus
    compare VAR_RESULT, FALSE
    goto_if_eq EventScript_PkmnCenterNurse_ReturnPkmn
    end

EventScript_PkmnCenterNurse_ExplainPokerus:: @ 8271A5F
    message gText_PokerusExplanation
    setflag FLAG_POKERUS_EXPLAINED
    return

EventScript_PkmnCenterNurse_GoldCard:: @ 8271A68
    goto_if_set FLAG_NURSE_MENTIONS_GOLD_CARD, EventScript_PkmnCenterNurse_AskForUsual
    setflag FLAG_NURSE_MENTIONS_GOLD_CARD
    msgbox gText_WelcomeCutShort, MSGBOX_DEFAULT
    playse SE_PIN
    applymovement VAR_0x800B, Common_Movement_ExclamationMark
    waitmovement 0
    applymovement VAR_0x800B, Common_Movement_Delay48
    waitmovement 0
    msgbox gText_NoticesGoldCard, MSGBOX_YESNO
    compare VAR_RESULT, YES
    goto_if_eq EventScript_PkmnCenterNurse_GoldCardHealPkmn
    message gText_WeHopeToSeeYouAgain2
    return

EventScript_PkmnCenterNurse_AskForUsual:: @ 8271AAC
    msgbox gText_YouWantTheUsual, MSGBOX_YESNO
    compare VAR_RESULT, YES
    goto_if_eq EventScript_PkmnCenterNurse_GoldCardHealPkmn
    message gText_WeHopeToSeeYouAgain2
    return

EventScript_PkmnCenterNurse_GoldCardHealPkmn:: @ 8271AC5
    setvar VAR_0x8004, 1
    goto EventScript_PkmnCenterNurse_HealPkmn
    end

EventScript_PkmnCenterNurse_Bow: @ 8271AD0
    nurse_joy_bow
    delay_4
    step_end

EventScript_PkmnCenterNurse_PlayerTurn::
    closemessage
    applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceDown
    waitmovement 0
    release
    end
	
EventScript_PkmnCenterNurse_CheckUpdatedSave::
	msgbox Special_Gym_Text_Explain_Old_Save, MSGBOX_DEFAULT
	call_if_unset FLAG_SYS_DEXNAV_GET, EventScript_PkmnCenterNurse_Randomized_Mode
	setflag FLAG_UPDATED_SAVE
	clearflag FLAG_UNUSED_0x26D
	removeitem ITEM_MAGMA_EMBLEM
	removeitem ITEM_OLD_SEA_MAP
	removeitem ITEM_WAILMER_PAIL
	removeitem ITEM_OLD_ROD
	removeitem ITEM_MACH_BIKE
	removeitem ITEM_ACRO_BIKE
	removeitem ITEM_GOOD_ROD
	removeitem ITEM_EXP_SHARE
	removeitem ITEM_SUPER_ROD
	removeitem ITEM_SHINY_CHARM
	removeitem ITEM_TEACHY_TV
	additem ITEM_WAILMER_PAIL
	additem ITEM_ACRO_BIKE
	additem ITEM_OLD_ROD
	additem ITEM_EXP_SHARE
	additem ITEM_POTION, 5
	additem ITEM_POKE_BALL, 10
	additem ITEM_REPEL, 3
	goto_if_unset FLAG_RECEIVED_BADGE_01, EventScript_PkmnCenterNurse_CheckUpdatedSave_2
	additem ITEM_AMULET_COIN
	goto_if_unset FLAG_RECEIVED_BADGE_02, EventScript_PkmnCenterNurse_CheckUpdatedSave_2
	additem ITEM_ITEMFINDER
	goto_if_unset FLAG_RECEIVED_BADGE_03, EventScript_PkmnCenterNurse_CheckUpdatedSave_2
	additem ITEM_GOOD_ROD
	goto_if_unset FLAG_RECEIVED_BADGE_04, EventScript_PkmnCenterNurse_CheckUpdatedSave_2
	additem ITEM_OVAL_CHARM
	goto_if_unset FLAG_RECEIVED_BADGE_05, EventScript_PkmnCenterNurse_CheckUpdatedSave_2
	additem ITEM_SUPER_ROD
	goto_if_unset FLAG_RECEIVED_BADGE_06, EventScript_PkmnCenterNurse_CheckUpdatedSave_2
	additem ITEM_LUCKY_EGG
	goto_if_unset FLAG_RECEIVED_BADGE_07, EventScript_PkmnCenterNurse_CheckUpdatedSave_2
	additem ITEM_MEGA_BRACELET
	goto_if_unset FLAG_RECEIVED_BADGE_08, EventScript_PkmnCenterNurse_CheckUpdatedSave_2
	additem ITEM_SHINY_CHARM
	goto EventScript_PkmnCenterNurse_CheckUpdatedSave_2
	end

EventScript_PkmnCenterNurse_Randomized_Mode::
	setflag FLAG_RANDOMIZED_MODE
	setflag FLAG_SYS_DEXNAV_GET
	return
	
EventScript_PkmnCenterNurse_CheckUpdatedSave_2::
	msgbox Game_Start_Text_Difficulty, MSGBOX_DEFAULT
	waitmessage
	multichoice 0, 0, MULTI_GAME_LEVEL, 0
	switch VAR_RESULT
    case 0, EventScript_PkmnCenterNurseGame_Level_Easy
	case 1, EventScript_PkmnCenterNurseGame_Level_Normal
    case 2, EventScript_PkmnCenterNurseGame_Level_Hard
	end
	
EventScript_PkmnCenterNurseGame_Level_Easy::
	lockall
	msgbox Game_Start_Text_Difficulty_Easy, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq EventScript_PkmnCenterNurse_CheckUpdatedSave_2
	setflag FLAG_EASY_MODE
	clearflag FLAG_NORMAL_MODE
	clearflag FLAG_HARD_MODE
	goto EventScript_PkmnCenterNurse_Goodbye
	end
	
EventScript_PkmnCenterNurseGame_Level_Normal::
	lockall
	msgbox Game_Start_Text_Difficulty_Normal, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq EventScript_PkmnCenterNurse_CheckUpdatedSave_2
	clearflag FLAG_EASY_MODE
	setflag FLAG_NORMAL_MODE
	clearflag FLAG_HARD_MODE
	goto EventScript_PkmnCenterNurse_Goodbye
	end
	
EventScript_PkmnCenterNurseGame_Level_Hard::
	lockall
	msgbox Game_Start_Text_Difficulty_Hard, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq EventScript_PkmnCenterNurse_CheckUpdatedSave_2
	clearflag FLAG_EASY_MODE
	clearflag FLAG_NORMAL_MODE
	setflag FLAG_HARD_MODE
	goto EventScript_PkmnCenterNurse_Goodbye
	end
	
EventScript_PkmnCenterNurseDifficulty_Save::
	playfanfare SE_SAVE
	msgbox Game_Start_Text_Game_Difficulty_Changes_Saved, MSGBOX_DEFAULT
	waitfanfare
	goto EventScript_PkmnCenterNurse_Goodbye
	end
	
EventScript_PkmnCenterNurse_CheckUpdatedSave_3::
	msgbox Special_Gym_Text_Explain_Old_Save, MSGBOX_DEFAULT
	additem ITEM_WAILMER_PAIL
	additem ITEM_JOLLY_MINT
	additem ITEM_ADAMANT_MINT
	additem ITEM_TIMID_MINT
	additem ITEM_MODEST_MINT
	additem ITEM_ABILITY_PATCH
	setflag FLAG_UPDATED_SAVE_2
	goto_if_unset FLAG_RECEIVED_BADGE_08, EventScript_PkmnCenterNurse_Goodbye
	additem ITEM_SHINY_CHARM
	additem ITEM_TM39
	additem ITEM_TM08
	additem ITEM_TM34
	additem ITEM_TM50
	additem ITEM_TM42
	additem ITEM_TM40
	additem ITEM_TM04
	additem ITEM_TM03
	setflag FLAG_BADGE01_GET
	setflag FLAG_BADGE02_GET
	setflag FLAG_BADGE03_GET
	setflag FLAG_BADGE04_GET
	setflag FLAG_BADGE05_GET
	setflag FLAG_BADGE06_GET
	setflag FLAG_BADGE07_GET
	setflag FLAG_BADGE08_GET
	playfanfare SE_SAVE
	goto EventScript_PkmnCenterNurse_Goodbye
	end
