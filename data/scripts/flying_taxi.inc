Common_EventScript_FlyingTaxi::
    lock
    faceplayer
    setvar VAR_0x800A, LAST_TALKED_TO_FLYING_TAXI
    msgbox gText_FlyingTaxi_Intro, MSGBOX_YESNO
    compare VAR_RESULT, YES
    goto_if_eq EventScript_FlyingTaxi_ChooseDestination
    compare VAR_RESULT, NO
    goto_if_eq EventScript_FlyingTaxi_Goodbye
    end

EventScript_FlyingTaxi_ChooseDestination::
    special FieldLoadFlyMap
    goto EventScript_FlyingTaxi_Goodbye
    end

EventScript_FlyingTaxi_Goodbye::
    message gText_WeHopeToSeeYouAgain
    setvar VAR_LAST_TALKED, 0
    releaseall
    return
	
//Gym Items
Special_Gym_EventScript_Give_Item::
	setflag (FLAG_GYM_ATTENDANT_CALL)
	goto_if_unset FLAG_RECEIVED_BADGE_01, Special_Gym_EventScript_Amulet_Coin
	goto_if_unset FLAG_RECEIVED_BADGE_02, Special_Gym_EventScript_Item_Finder
	goto_if_unset FLAG_RECEIVED_BADGE_03, Special_Gym_EventScript_Good_Rod
	goto_if_unset FLAG_RECEIVED_BADGE_04, Special_Gym_EventScript_Catching_Charm
	goto_if_unset FLAG_RECEIVED_BADGE_05, Special_Gym_EventScript_Super_Rod
	goto_if_unset FLAG_RECEIVED_BADGE_06, Special_Gym_EventScript_Lucky_Egg
	goto_if_unset FLAG_RECEIVED_BADGE_07, Special_Gym_EventScript_Mega_Bracelet
	goto_if_unset FLAG_RECEIVED_BADGE_08, Special_Gym_EventScript_Shiny_Charm
	end
	
Special_Gym_EventScript_Amulet_Coin::
	giveitem ITEM_AMULET_COIN
	msgbox   Special_Gym_Text_Explain_Amulet_Coin, MSGBOX_DEFAULT
	setflag  FLAG_RECEIVED_BADGE_01
	setvar   VAR_NUM_BADGES, 1
	return
	end
	
Special_Gym_EventScript_Item_Finder::
	giveitem ITEM_ITEMFINDER
	msgbox   Special_Gym_Text_Explain_Item_Finder, MSGBOX_DEFAULT
	setflag  FLAG_RECEIVED_BADGE_02
	setvar   VAR_NUM_BADGES, 2
	return
	end
	
Special_Gym_EventScript_Good_Rod::
	giveitem ITEM_GOOD_ROD
	msgbox   Special_Gym_Text_Explain_Good_Rod, MSGBOX_DEFAULT
	setflag  FLAG_RECEIVED_BADGE_03
	setvar   VAR_NUM_BADGES, 3
	return
	end
	
Special_Gym_EventScript_Catching_Charm::
	giveitem ITEM_CATCHING_CHARM
	msgbox   Special_Gym_Text_Explain_Catching_Charm, MSGBOX_DEFAULT
	setflag  FLAG_RECEIVED_BADGE_04
	setvar   VAR_NUM_BADGES, 4
	return
	end
	
Special_Gym_EventScript_Super_Rod::
	giveitem ITEM_SUPER_ROD
	msgbox   Special_Gym_Text_Explain_Super_Rod, MSGBOX_DEFAULT
	setflag  FLAG_RECEIVED_BADGE_05
	setvar   VAR_NUM_BADGES, 5
	return
	end
	
Special_Gym_EventScript_Lucky_Egg::
	giveitem ITEM_LUCKY_EGG
	msgbox   Special_Gym_Text_Explain_Lucky_Egg, MSGBOX_DEFAULT
	setflag  FLAG_RECEIVED_BADGE_06
	setvar   VAR_NUM_BADGES, 6
	return
	end
	
Special_Gym_EventScript_Mega_Bracelet::
	giveitem ITEM_MEGA_BRACELET
	msgbox   Special_Gym_Text_Explain_Mega_Bracelet, MSGBOX_DEFAULT
	setflag  FLAG_RECEIVED_BADGE_07
	setvar   VAR_NUM_BADGES, 7
	return
	end
	
Special_Gym_EventScript_Shiny_Charm::
	giveitem ITEM_SHINY_CHARM
	msgbox   Special_Gym_Text_Explain_Shiny_Charm, MSGBOX_DEFAULT
	setflag  FLAG_RECEIVED_BADGE_08
	setvar   VAR_NUM_BADGES, 8
	return
	end
