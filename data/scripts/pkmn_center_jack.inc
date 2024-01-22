Common_EventScript_PkmnCenterJack::
	lockall
	msgbox gText_PkmnCenterJack_GotPokemonQuestions, MSGBOX_DEFAULT
	//multichoice 16, 0, MULTI_POKECENTER_JACK, 0
	scrollingmultichoice 9, 0, 0, 6, TRUE
	copyvar VAR_TEMP_1, VAR_RESULT
	switch VAR_TEMP_1
	case 0, Common_EventScript_PkmnCenterJack_NameRater_ChooseMonToRate
	case 1, Common_EventScript_PkmnCenterJack_Move_Learner
	case 2, Common_EventScript_PkmnCenterJack_MoveDeleter_ChooseMonAndMoveToForget
	case 3, Common_EventScript_PkmnCenterJack_WonderTrade
	case 4, Common_EventScript_PkmnCenterJack_Change_Costume
	case 5, Common_EventScript_PkmnCenterJack_StartARandomBattle
	case 6, Common_EventScript_PkmnCenterJack_Companion_Stuff
	case 7, Common_EventScript_PkmnCenterJack_ComeBackAnytime
	case MULTI_B_PRESSED, Common_EventScript_PkmnCenterJack_ComeBackAnytime
	end

Common_EventScript_PkmnCenterJack_Companion_Stuff::
	msgbox gText_PkmnCenterJack_GotPokemonQuestions, MSGBOX_DEFAULT
	multichoice 16, 0, MULTI_COMPANION_OPTIONS, 0
	copyvar VAR_TEMP_1, VAR_RESULT
	switch VAR_TEMP_1
	case 0, Common_EventScript_PkmnCenterJack_Companion_Get_Trainer_Password
	case 4, Common_EventScript_PkmnCenterJack
	case MULTI_B_PRESSED, Common_EventScript_PkmnCenterJack
	end
	
Common_EventScript_PkmnCenterJack_Move_Learner::
	msgbox gText_PkmnCenterJack_TeachMoves, MSGBOX_DEFAULT
	multichoice 16, 0, MULTI_TEACH_MOVES, 0
	copyvar VAR_TEMP_1, VAR_RESULT
	switch VAR_TEMP_1
	case 0, Common_EventScript_PkmnCenterJack_MoveReminder_ChooseMon
	case 1, Common_EventScript_PkmnCenterJack_EggMoveTutor_Price
	case 2, Common_EventScript_PkmnCenterJack_TutorMoveTutor_Price
	case 3, Common_EventScript_PkmnCenterJack_TmMoveTutor_Price
	case 4, Common_EventScript_PkmnCenterJack_ComeBackAnytime
	case MULTI_B_PRESSED, Common_EventScript_PkmnCenterJack_ComeBackAnytime
	end
	
Common_EventScript_PkmnCenterJack_Change_Costume::
	lock
	faceplayer
	msgbox gText_PkmnCenterJack_Change_Costume, MSGBOX_DEFAULT
	multichoice 16, 0, MULTI_COSTUMES, 0
	copyvar VAR_TEMP_1, VAR_RESULT
	switch VAR_TEMP_1
	case 0, Common_EventScript_PkmnCenterJack_Change_Costume_0
	case 1, Common_EventScript_PkmnCenterJack_Change_Costume_1
	case 2, Common_EventScript_PkmnCenterJack_Change_Costume_2
	case 3, Common_EventScript_PkmnCenterJack_Change_Costume_3
	case 4, Common_EventScript_PkmnCenterJack_ComeBackAnytime
	case MULTI_B_PRESSED, Common_EventScript_PkmnCenterJack_ComeBackAnytime
	end
	
Common_EventScript_PkmnCenterJack_Change_Costume_0::
	setvar VAR_COSTUME_NUMBER, 0
	goto Common_EventScript_PkmnCenterJack_Change_Costume_End
	end
	
Common_EventScript_PkmnCenterJack_Change_Costume_1::
	setvar VAR_COSTUME_NUMBER, 1
	goto Common_EventScript_PkmnCenterJack_Change_Costume_End
	end
	
Common_EventScript_PkmnCenterJack_Change_Costume_2::
	setvar VAR_COSTUME_NUMBER, 2
	goto Common_EventScript_PkmnCenterJack_Change_Costume_End
	end

Common_EventScript_PkmnCenterJack_Change_Costume_3::
	checkplayergender
	compare VAR_RESULT, GENDER_FEMALE
	goto_if_eq Common_EventScript_PkmnCenterJack_Change_Costume_No_Costume
	setvar VAR_COSTUME_NUMBER, 3
	goto Common_EventScript_PkmnCenterJack_Change_Costume_End
	end

Common_EventScript_PkmnCenterJack_Change_Costume_No_Costume::
	msgbox Common_PkmnCenterJack_Text_No_Costume, MSGBOX_DEFAULT
	releaseall
    end
	
Common_EventScript_PkmnCenterJack_Change_Costume_End::
	//fadescreen 1
	warp MAP_LITTLEROOT_TOWN, 192, 192, 192
	//fadescreen 0
	releaseall
    end

Common_EventScript_PkmnCenterJack_TeachMove::
	lock
	faceplayer
	bufferpartymonnick 0, 0
	msgbox Text_IVChecker_1, MSGBOX_DEFAULT
	specialvar VAR_RESULT, GetHpIV
	buffernumberstring 0, VAR_RESULT
	specialvar VAR_RESULT, GetAtkIV
	buffernumberstring 1, VAR_RESULT
	specialvar VAR_RESULT, GetDefIV
	buffernumberstring 2, VAR_RESULT
	msgbox Text_IVChecker_2, MSGBOX_DEFAULT
	specialvar VAR_RESULT, GetSpAtkIV
	buffernumberstring 0, VAR_RESULT
	specialvar VAR_RESULT, GetSpDefIV
	buffernumberstring 1, VAR_RESULT
	specialvar VAR_RESULT, GetSpeedIV
	buffernumberstring 2, VAR_RESULT
	msgbox Text_IVChecker_3, MSGBOX_DEFAULT
	release
	end

Common_EventScript_PkmnCenterJack_ComeBackAnytime::
	msgbox gText_PkmnCenterJack_ComeBackAnytime, MSGBOX_DEFAULT
	releaseall
    end
	
Common_EventScript_PkmnCenterJack_NoEnoughBadges::
	msgbox gText_PkmnCenterJack_CantTeachMoves, MSGBOX_DEFAULT
	releaseall
    end

@Start a Random Battle	
Common_EventScript_PkmnCenterJack_StartARandomBattle::
	msgbox Common_PkmnCenterJack_Text_MockBattle, MSGBOX_DEFAULT
	waitmessage
	multichoice 0, 0, MULTI_MOCK_BATTLE_OPTIONS, 0
	switch VAR_RESULT
    case 0, Common_EventScript_PkmnCenterJack_StartARandomBattle_Easy
	case 1, Common_EventScript_PkmnCenterJack_StartARandomBattle_Medium
    case 2, Common_EventScript_PkmnCenterJack_StartARandomBattle_Hard
	case 3, Common_EventScript_PkmnCenterJack_StartARandomBattle_PSS
	case 4, Common_EventScript_PkmnCenterJack_StartARandomBattle_Password
	case MULTI_B_PRESSED, Common_EventScript_PkmnCenterJack_ComeBackAnytime
	end
	
Common_EventScript_PkmnCenterJack_StartARandomBattle_Easy::
	msgbox Common_PkmnCenterJack_Text_MockBattle_Easy, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_MAY_PLACEHOLDER, Common_PkmnCenterJack_Text_MockBattle_Defeat
	special HealPlayerParty
	msgbox gText_PkmnCenterJack_ComeBackAnytime, MSGBOX_DEFAULT
	releaseall
    end
	
Common_EventScript_PkmnCenterJack_StartARandomBattle_Medium::
	msgbox Common_PkmnCenterJack_Text_MockBattle_Normal, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_BRENDAN_PLACEHOLDER, Common_PkmnCenterJack_Text_MockBattle_Defeat
	special HealPlayerParty
	msgbox gText_PkmnCenterJack_ComeBackAnytime, MSGBOX_DEFAULT
	releaseall
    end
	
Common_EventScript_PkmnCenterJack_StartARandomBattle_Hard::
	msgbox Common_PkmnCenterJack_Text_MockBattle_Hard, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_LEAF, Common_PkmnCenterJack_Text_MockBattle_Defeat
	special HealPlayerParty
	msgbox gText_PkmnCenterJack_ComeBackAnytime, MSGBOX_DEFAULT
	releaseall
    end

Common_EventScript_PkmnCenterJack_StartARandomBattle_PSS::
	msgbox Common_PkmnCenterJack_Text_MockBattle_PSS, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_PSS_TRAINER, Common_PkmnCenterJack_Text_MockBattle_Defeat
	special HealPlayerParty
	msgbox gText_PkmnCenterJack_ComeBackAnytime, MSGBOX_DEFAULT
	releaseall
    end

@Rate Nickname
Common_EventScript_PkmnCenterJack_NameRater_ChooseMonToRate::
	msgbox Common_PkmnCenterJack_Text_CritiqueWhichMonNickname, MSGBOX_DEFAULT
	special ChoosePartyMon
	waitstate
	compare VAR_0x8004, 255
	goto_if_ne Common_EventScript_PkmnCenterJack_NameRater_RateMonNickname
	compare VAR_0x8004, 255
	goto_if_eq Common_EventScript_PkmnCenterJack_NameRater_DeclineNameRate
	end

Common_EventScript_PkmnCenterJack_NameRater_DeclineNameRate::
	msgbox Common_PkmnCenterJack_Text_DoVisitAgain, MSGBOX_DEFAULT
	release
	end

Common_EventScript_PkmnCenterJack_NameRater_RateMonNickname::
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
	compare VAR_RESULT, SPECIES_EGG
	goto_if_eq Common_EventScript_PkmnCenterJack_NameRater_CantRateEgg
	special BufferMonNickname
	msgbox Common_PkmnCenterJack_Text_FineNameSuggestBetterOne, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq Common_EventScript_PkmnCenterJack_NameRater_ChangeNickname
	compare VAR_RESULT, NO
	goto_if_eq Common_EventScript_PkmnCenterJack_NameRater_DeclineNameRate
	end

Common_EventScript_PkmnCenterJack_NameRater_CantRateEgg::
	msgbox Common_PkmnCenterJack_Text_ThatIsMerelyAnEgg, MSGBOX_DEFAULT
	release
	end

Common_EventScript_PkmnCenterJack_NameRater_ChangeNickname::
	msgbox Common_PkmnCenterJack_Text_WhatShallNewNameBe, MSGBOX_DEFAULT
	call Common_EventScript_NameReceivedPartyMon
	specialvar VAR_RESULT, TryPutNameRaterShowOnTheAir
	special BufferMonNickname
	compare VAR_RESULT, TRUE
	goto_if_eq Common_EventScript_PkmnCenterJack_NameRater_NewNameDifferent
	msgbox Common_PkmnCenterJack_Text_NameNoDifferentYetSuperior, MSGBOX_DEFAULT
	release
	end

Common_EventScript_PkmnCenterJack_NameRater_NewNameDifferent::
	msgbox Common_PkmnCenterJack_Text_MonShallBeKnownAsName, MSGBOX_DEFAULT
	release
	end

@Move Deleter
Common_EventScript_PkmnCenterJack_MoveDeleter_ChooseMonAndMoveToForget::
	msgbox Common_PkmnCenterJack_Text_WhichMonShouldForget, MSGBOX_DEFAULT
	special ChoosePartyMon
	waitstate
	compare VAR_0x8004, 255
	goto_if_eq Common_EventScript_PkmnCenterJack_MoveDeleter_ComeAgain
	special IsSelectedMonEgg
	compare VAR_RESULT, TRUE
	goto_if_eq Common_EventScript_PkmnCenterJack_MoveDeleter_EggCantForgetMoves
	special GetNumMovesSelectedMonHas
	compare VAR_RESULT, 1
	goto_if_eq Common_EventScript_PkmnCenterJack_MoveDeleter_MonOnlyKnowsOneMove
	msgbox Common_PkmnCenterJack_Text_WhichMoveShouldBeForgotten, MSGBOX_DEFAULT
	fadescreen FADE_TO_BLACK
	special MoveDeleterChooseMoveToForget
	fadescreen FADE_FROM_BLACK
	compare VAR_0x8005, MAX_MON_MOVES
	goto_if_eq Common_EventScript_PkmnCenterJack_MoveDeleter_ChooseMonAndMoveToForget
	special BufferMoveDeleterNicknameAndMove
	msgbox Common_PkmnCenterJack_Text_MonsMoveShouldBeForgotten, MSGBOX_YESNO
	switch VAR_RESULT
	case YES, Common_EventScript_PkmnCenterJack_MoveDeleter_TryForgetMove
	case NO, Common_EventScript_PkmnCenterJack_MoveDeleter_ComeAgain
	releaseall
	end

Common_EventScript_PkmnCenterJack_MoveDeleter_TryForgetMove::
	special IsLastMonThatKnowsSurf
	compare VAR_RESULT, TRUE
	goto_if_eq Common_EventScript_PkmnCenterJack_MoveDeleter_LastMonWithSurf
	special MoveDeleterForgetMove
	playfanfare MUS_MOVE_DELETED
	waitfanfare
	msgbox Common_PkmnCenterJack_Text_MonHasForgottenMove, MSGBOX_DEFAULT
	releaseall
	end

Common_EventScript_PkmnCenterJack_MoveDeleter_MonOnlyKnowsOneMove::
	special BufferMoveDeleterNicknameAndMove
	msgbox Common_PkmnCenterJack_Text_MonOnlyKnowsOneMove, MSGBOX_DEFAULT
	releaseall
	end

Common_EventScript_PkmnCenterJack_MoveDeleter_EggCantForgetMoves::
	msgbox Common_PkmnCenterJack_Text_EggCantForgetMoves, MSGBOX_DEFAULT
	releaseall
	end

Common_EventScript_PkmnCenterJack_MoveDeleter_ComeAgain::
	msgbox Common_PkmnCenterJack_Text_ComeAgain, MSGBOX_DEFAULT
	releaseall
	end

Common_EventScript_PkmnCenterJack_MoveDeleter_LastMonWithSurf::
	special BufferMoveDeleterNicknameAndMove
	msgbox Common_PkmnCenterJack_Text_CantForgetSurf, MSGBOX_DEFAULT
	releaseall
	end

//------------------------------------------------------------------------------
//Move Relearner
//------------------------------------------------------------------------------
Common_EventScript_PkmnCenterJack_MoveReminder_ChooseMon:: @ 82013D6
	msgbox Common_PkmnCenterJack_Text_TutorWhichMon, MSGBOX_DEFAULT
	special ChooseMonForMoveRelearner
	waitstate
	compare VAR_0x8004, 255
	goto_if_eq Common_EventScript_PkmnCenterJack_MoveReminder_ComeBackAnytime
	special IsSelectedMonEgg
	compare VAR_RESULT, TRUE
	goto_if_eq Common_EventScript_PkmnCenterJack_MoveReminder_CantTeachEgg
	compare VAR_0x8005, 0
	goto_if_eq Common_EventScript_PkmnCenterJack_MoveReminder_NoMoveToTeachMon
	goto Common_EventScript_PkmnCenterJack_MoveReminder_ChooseMove
	end
	
Common_EventScript_PkmnCenterJack_MoveReminder_ChooseMove:: @ 820140C
	msgbox Common_PkmnCenterJack_Text_TeachWhichMove, MSGBOX_DEFAULT
	special TeachMoveRelearnerMove
	waitstate
	compare VAR_0x8004, 0
	goto_if_eq Common_EventScript_PkmnCenterJack_MoveReminder_ChooseMon
	goto Common_EventScript_PkmnCenterJack_MoveReminder_ComeBackAnytime
	end
	
Common_EventScript_PkmnCenterJack_MoveReminder_NoMoveToTeachMon:: @ 8201436
	msgbox Common_PkmnCenterJack_Text_DontHaveMoveToTeachPokemon, MSGBOX_DEFAULT
	goto Common_EventScript_PkmnCenterJack_MoveReminder_ChooseMon
	end
	
Common_EventScript_PkmnCenterJack_MoveReminder_CantTeachEgg:: @ 8201444
	msgbox Common_PkmnCenterJack_Text_ThatIsMerelyAnEgg, MSGBOX_DEFAULT
	goto Common_EventScript_PkmnCenterJack_MoveReminder_ChooseMon
	end
	
//------------------------------------------------------------------------------
//Egg Move Tutor
//------------------------------------------------------------------------------
Common_EventScript_PkmnCenterJack_EggMoveTutor_Price::
	goto_if_unset FLAG_RECEIVED_BADGE_06 Common_EventScript_PkmnCenterJack_NoEnoughBadges
	msgbox gText_PkmnCenterJack_Teach_Egg_Moves, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq Common_EventScript_PkmnCenterJack_MoveReminder_ComeBackAnytime
	checkmoney 3000, 0
	compare VAR_RESULT, FALSE
	goto_if_eq EverGrandeCity_PokemonLeague_1F_EventScript_Power_Candy_no_Money
	goto Common_EventScript_PkmnCenterJack_EggMoveTutor_ChooseMon
	end

Common_EventScript_PkmnCenterJack_EggMoveTutor_ChooseMon:: @ 82013D6
	msgbox Common_PkmnCenterJack_Text_TutorWhichMon, MSGBOX_DEFAULT
	special ChooseMonForEggTutor
	waitstate
	compare VAR_0x8004, 255
	goto_if_eq Common_EventScript_PkmnCenterJack_MoveReminder_ComeBackAnytime
	special IsSelectedMonEgg
	compare VAR_RESULT, TRUE
	goto_if_eq Common_EventScript_PkmnCenterJack_TMMMoveTutor_CantTeachEgg
	compare VAR_0x8005, 0
	goto_if_eq Common_EventScript_PkmnCenterJack_TMMoveTutor_NoMoveToTeachMon
	goto Common_EventScript_PkmnCenterJack_MoveReminder_ChooseEggMove
	end
	
Common_EventScript_PkmnCenterJack_MoveReminder_ChooseEggMove:: @ 820140C
	msgbox Common_PkmnCenterJack_Text_TeachWhichMove, MSGBOX_DEFAULT
	special TeachEggTutorMove
	waitstate
	compare VAR_0x8004, 0
	goto_if_eq Common_EventScript_PkmnCenterJack_EggMoveTutor_ChooseMon
	removemoney 3000, 0
	goto Common_EventScript_PkmnCenterJack_MoveReminder_ComeBackAnytime
	end
	
Common_EventScript_PkmnCenterJack_EggMoveTutor_NoMoveToTeachMon:: @ 8201436
	msgbox Common_PkmnCenterJack_Text_DontHaveMoveToTeachPokemon, MSGBOX_DEFAULT
	goto Common_EventScript_PkmnCenterJack_MoveReminder_ChooseMon
	end
	
Common_EventScript_PkmnCenterJack_EggMoveTutor_CantTeachEgg:: @ 8201444
	msgbox Common_PkmnCenterJack_Text_ThatIsMerelyAnEgg, MSGBOX_DEFAULT
	goto Common_EventScript_PkmnCenterJack_MoveReminder_ChooseMon
	end
	
//------------------------------------------------------------------------------
//Tm Move Tutor
//------------------------------------------------------------------------------
Common_EventScript_PkmnCenterJack_TmMoveTutor_Price::
	goto_if_unset FLAG_RECEIVED_BADGE_08 Common_EventScript_PkmnCenterJack_NoEnoughBadges
	msgbox gText_PkmnCenterJack_Teach_TM_Moves, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq Common_EventScript_PkmnCenterJack_MoveReminder_ComeBackAnytime
	checkmoney 6000, 0
	compare VAR_RESULT, FALSE
	goto_if_eq EverGrandeCity_PokemonLeague_1F_EventScript_Power_Candy_no_Money
	goto Common_EventScript_PkmnCenterJack_TmMoveTutor_ChooseMon
	end

Common_EventScript_PkmnCenterJack_TmMoveTutor_ChooseMon:: @ 82013D6
	msgbox Common_PkmnCenterJack_Text_TutorWhichMon, MSGBOX_DEFAULT
	special ChooseMonForTMTutor
	waitstate
	compare VAR_0x8004, 255
	goto_if_eq Common_EventScript_PkmnCenterJack_MoveReminder_ComeBackAnytime
	special IsSelectedMonEgg
	compare VAR_RESULT, TRUE
	goto_if_eq Common_EventScript_PkmnCenterJack_TMMMoveTutor_CantTeachEgg
	compare VAR_0x8005, 0
	goto_if_eq Common_EventScript_PkmnCenterJack_TMMoveTutor_NoMoveToTeachMon
	goto Common_EventScript_PkmnCenterJack_TmMoveTutor_ChooseTmMove
	end
	
Common_EventScript_PkmnCenterJack_TmMoveTutor_ChooseTmMove:: @ 820140C
	msgbox Common_PkmnCenterJack_Text_TeachWhichMove, MSGBOX_DEFAULT
	special TeachTMTutorMove
	waitstate
	compare VAR_0x8004, 0
	goto_if_eq Common_EventScript_PkmnCenterJack_TmMoveTutor_ChooseMon
	removemoney 6000, 0
	goto Common_EventScript_PkmnCenterJack_MoveReminder_ComeBackAnytime
	end
	
Common_EventScript_PkmnCenterJack_TMMoveTutor_NoMoveToTeachMon:: @ 8201436
	msgbox Common_PkmnCenterJack_Text_DontHaveMoveToTeachPokemon, MSGBOX_DEFAULT
	goto Common_EventScript_PkmnCenterJack_MoveReminder_ChooseMon
	end
	
Common_EventScript_PkmnCenterJack_TMMMoveTutor_CantTeachEgg:: @ 8201444
	msgbox Common_PkmnCenterJack_Text_ThatIsMerelyAnEgg, MSGBOX_DEFAULT
	goto Common_EventScript_PkmnCenterJack_MoveReminder_ChooseMon
	end
	
//------------------------------------------------------------------------------
//Move Tutor
//------------------------------------------------------------------------------
Common_EventScript_PkmnCenterJack_TutorMoveTutor_Price::
	goto_if_unset FLAG_RECEIVED_BADGE_07 Common_EventScript_PkmnCenterJack_NoEnoughBadges
	msgbox gText_PkmnCenterJack_Teach_Tutor_Moves, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq Common_EventScript_PkmnCenterJack_MoveReminder_ComeBackAnytime
	checkmoney 4500, 0
	compare VAR_RESULT, FALSE
	goto_if_eq EverGrandeCity_PokemonLeague_1F_EventScript_Power_Candy_no_Money
	goto Common_EventScript_PkmnCenterJack_TutorMoveTutor_ChooseMon
	end

Common_EventScript_PkmnCenterJack_TutorMoveTutor_ChooseMon:: @ 82013D6
	msgbox Common_PkmnCenterJack_Text_TutorWhichMon, MSGBOX_DEFAULT
	special ChooseMonForNewMoveTutor
	waitstate
	compare VAR_0x8004, 255
	goto_if_eq Common_EventScript_PkmnCenterJack_MoveReminder_ComeBackAnytime
	special IsSelectedMonEgg
	compare VAR_RESULT, TRUE
	goto_if_eq Common_EventScript_PkmnCenterJack_TutorMoveTutor_CantTeachEgg
	compare VAR_0x8005, 0
	goto_if_eq Common_EventScript_PkmnCenterJack_TutorMoveTutor_NoMoveToTeachMon
	goto Common_EventScript_PkmnCenterJack_MoveReminder_ChooseTutorMove
	end
	
Common_EventScript_PkmnCenterJack_MoveReminder_ChooseTutorMove:: @ 820140C
	msgbox Common_PkmnCenterJack_Text_TeachWhichMove, MSGBOX_DEFAULT
	special TeachTutorMove
	waitstate
	compare VAR_0x8004, 0
	goto_if_eq Common_EventScript_PkmnCenterJack_TutorMoveTutor_ChooseMon
	removemoney 4500, 0
	goto Common_EventScript_PkmnCenterJack_MoveReminder_ComeBackAnytime
	end
	
Common_EventScript_PkmnCenterJack_TutorMoveTutor_NoMoveToTeachMon:: @ 8201436
	msgbox Common_PkmnCenterJack_Text_DontHaveMoveToTeachPokemon, MSGBOX_DEFAULT
	goto Common_EventScript_PkmnCenterJack_MoveReminder_ChooseMon
	end
	
Common_EventScript_PkmnCenterJack_TutorMoveTutor_CantTeachEgg:: @ 8201444
	msgbox Common_PkmnCenterJack_Text_ThatIsMerelyAnEgg, MSGBOX_DEFAULT
	goto Common_EventScript_PkmnCenterJack_MoveReminder_ChooseMon
	end
	
//------------------------------------------------------------------------------
	
Common_EventScript_PkmnCenterJack_MoveReminder_ComeBackAnytime:: @ 8201452
	msgbox gText_PkmnCenterJack_ComeBackAnytime, MSGBOX_DEFAULT
	releaseall
	end

Common_EventScript_PkmnCenterJack_WonderTrade:
	setvar VAR_0x8008, INGAME_TRADE_SEEDOT
	copyvar VAR_0x8004, VAR_0x8008
	specialvar VAR_RESULT, GetInGameTradeSpeciesInfo
	copyvar VAR_0x8009, VAR_RESULT
	msgbox Common_PkmnCenterJack_Text_WonderTrade1, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq Common_EventScript_PkmnCenterJack_WonderTrade_Cancel
	special ChoosePartyMon
	waitstate
	copyvar VAR_0x800A, VAR_0x8004
	compare VAR_0x8004, 255
	goto_if_eq Common_EventScript_PkmnCenterJack_WonderTrade_Cancel
	copyvar VAR_0x8005, VAR_0x800A
	specialvar VAR_RESULT, GetTradeSpecies
	copyvar VAR_0x800B, VAR_RESULT
	compare VAR_RESULT, VAR_0x8009
	//goto_if_ne FortreeCity_House1_EventScript_NotRequestedMon
	copyvar VAR_0x8004, VAR_0x8008
	copyvar VAR_0x8005, VAR_0x800A
	special CreateInGameWonderTradePokemon
	special DoInGameTradeScene
	waitstate
	special DestroyFollower
	bufferspeciesname 0, VAR_0x8009
	msgbox Common_PkmnCenterJack_Text_WonderTrade2, MSGBOX_DEFAULT
	release
	end
	
Common_EventScript_PkmnCenterJack_WonderTrade_Cancel:
	msgbox Common_PkmnCenterJack_Text_DoVisitAgain, MSGBOX_DEFAULT
	releaseall
	end
