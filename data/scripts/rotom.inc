@ Rotom form change script
@ Vars used:
@ gSpecialVar_0x8004: set to the party slot of the chosen Rotom, or the first Rotom found if there's only one
@ gSpecialVar_0x8005: set to the form to change Rotom to (e.g. SPECIES_ROTOM_WASH)
@ gSpecialVar_0x8006: special move learned by Rotom after form change (set by ChangeRotomForm)
@ gSpecialVar_0x8007: Rotom's initial form
@ gSpecialVar_0x8008: Rotom's initial special move (set by RotomForgetSpecialMove)

Rotom_Appliances_Main::
    lockall
    specialVar VAR_RESULT, CountRotomInParty
    switch VAR_RESULT
    case 0, Rotom_Appliances_NoRotomInParty
    case 1, Rotom_Appliances_RotomInParty
    goto Rotom_Appliances_WhichRotom

Rotom_Appliances_RotomInParty::
    msgbox Rotom_Text_RotomWouldLikeToInvestigate, MSGBOX_YESNO
    compare VAR_RESULT, NO
	goto_if_eq Rotom_Appliances_Exit
    goto Rotom_Appliances_Multichoice

Rotom_Appliances_WhichRotom::
    msgbox Rotom_Text_RotomWouldLikeToInvestigate, MSGBOX_YESNO
    compare VAR_RESULT, NO
	goto_if_eq Rotom_Appliances_Exit
    msgbox Rotom_Text_WhichRotom, MSGBOX_DEFAULT
    special ChoosePartyMon
	waitstate
    compare VAR_0x8004, 255
	goto_if_eq Rotom_Appliances_Exit
	special IsSelectedMonEgg
	compare VAR_RESULT, TRUE
    goto_if_eq Rotom_Appliances_SelectedMonIsEgg
    specialvar VAR_RESULT, IsSelectedMonRotom
    compare VAR_RESULT, FALSE
    goto_if_eq Rotom_Appliances_SelectedMonIsntRotom
	compare VAR_0x8004, PARTY_SIZE
	goto_if_ge Rotom_Appliances_Exit
    goto Rotom_Appliances_Multichoice

Rotom_Appliances_Multichoice::
    special GetRotomState
    bufferpartymonnick 0, VAR_0x8004
    msgbox Rotom_Text_WhichAppliancesMotor, MSGBOX_DEFAULT
    waitmessage
	multichoice 0, 0, MULTI_ROTOM_APPLIANCES, 0
	switch VAR_RESULT
    case 0, Rotom_Appliances_Heat
	case 1, Rotom_Appliances_Wash
    case 2, Rotom_Appliances_Frost
	case 3, Rotom_Appliances_Fan
    case 4, Rotom_Appliances_Mow
	case 5, Rotom_Appliances_Recall
    case MULTI_B_PRESSED, Rotom_Appliances_Exit

Rotom_Appliances_Heat::
    setvar VAR_0x8005, SPECIES_ROTOM_HEAT
    goto Rotom_Appliances_CheckForSpecialMove

Rotom_Appliances_Wash::
    setvar VAR_0x8005, SPECIES_ROTOM_WASH
    goto Rotom_Appliances_CheckForSpecialMove

Rotom_Appliances_Frost::
    setvar VAR_0x8005, SPECIES_ROTOM_FROST
    goto Rotom_Appliances_CheckForSpecialMove

Rotom_Appliances_Fan::
    setvar VAR_0x8005, SPECIES_ROTOM_FAN
    goto Rotom_Appliances_CheckForSpecialMove

Rotom_Appliances_Mow::
    setvar VAR_0x8005, SPECIES_ROTOM_MOW
    goto Rotom_Appliances_CheckForSpecialMove

Rotom_Appliances_Recall::
    setvar VAR_0x8005, SPECIES_ROTOM
    goto Rotom_Appliances_RecallFromMotor

Rotom_Appliances_CheckForSpecialMove::
    compare VAR_0x8005, VAR_0x8007
    goto_if_eq Rotom_Appliances_AlreadyEnteredThatMotor
    special GetRotomNewSpecialMove
    special ChangeRotomForm @ Change form here so new form is shown while choosing move to forget
    msgbox Rotom_Text_EnteredTheMotor, MSGBOX_DEFAULT
    specialVar VAR_RESULT, DoesRotomKnowSpecialMove
    compare VAR_RESULT, TRUE
    goto_if_eq Rotom_Appliances_DeleteSpecialMove
    special GetNumMovesSelectedMonHas
	compare VAR_RESULT, MAX_MON_MOVES
    goto_if_eq Rotom_Appliances_ChooseMoveToForget
    goto Rotom_Appliances_LearnSpecialMove

Rotom_Appliances_DeleteSpecialMove::
    special RotomForgetSpecialMove
    bufferpartymonnick 0, VAR_0x8004
    buffermovename 1, VAR_0x8008
    msgbox Rotom_Text_RotomForgotMove, MSGBOX_DEFAULT
    goto Rotom_Appliances_LearnSpecialMove

Rotom_Appliances_ChooseMoveToForget::
    buffermovename 1, VAR_0x8006
    msgbox Rotom_Text_TryLearnSpecialMove, MSGBOX_YESNO
    compare VAR_RESULT, NO
	goto_if_eq Rotom_Appliances_GaveUpOnEnteringMotor
    msgbox Rotom_Text_WhichMoveShouldBeForgotten, MSGBOX_DEFAULT
	fadescreen FADE_TO_BLACK
	special MoveDeleterChooseMoveToForget
	fadescreen FADE_FROM_BLACK
	compare VAR_0x8005, MAX_MON_MOVES
	goto_if_eq Rotom_Appliances_GaveUpOnEnteringMotor
	special BufferMoveDeleterNicknameAndMove
    msgbox Rotom_Text_RotomForgotMove, MSGBOX_DEFAULT
    special MoveDeleterForgetMove
    goto Rotom_Appliances_LearnSpecialMove

Rotom_Appliances_LearnSpecialMove::
    special TeachRotomMove
    bufferpartymonnick 0, VAR_0x8004
    buffermovename 1, VAR_0x8006
    playfanfare MUS_LEVEL_UP
    msgbox Rotom_Text_LearnedMove, MSGBOX_DEFAULT
    releaseall
    end

Rotom_Appliances_RecallFromMotor::
    compare VAR_0x8007, SPECIES_ROTOM
    goto_if_eq Rotom_Appliances_RotomHasntEnteredMotor
    special GetRotomNewSpecialMove
    special ChangeRotomForm
    msgbox Rotom_Text_EmergedFromTheMotor, MSGBOX_DEFAULT
    specialVar VAR_RESULT, DoesRotomKnowSpecialMove
    compare VAR_RESULT, TRUE
    goto_if_eq Rotom_Appliances_DeleteSpecialMove
    releaseall
    end

Rotom_Appliances_AlreadyEnteredThatMotor::
    msgbox Rotom_Text_AlreadyEnteredTheMotor, MSGBOX_DEFAULT
    releaseall
    end

Rotom_Appliances_SelectedMonIsEgg::
    msgbox Rotom_Text_EggCantEnterMotor, MSGBOX_DEFAULT
    releaseall
    end

Rotom_Appliances_SelectedMonIsntRotom::
    msgbox Rotom_Text_CantEnterMotor, MSGBOX_DEFAULT
    releaseall
    end

Rotom_Appliances_NoRotomInParty::
    msgbox Rotom_Text_ItsFullOfCarboardBoxes, MSGBOX_DEFAULT
    releaseall
    end

Rotom_Appliances_GaveUpOnEnteringMotor::
    copyvar VAR_0x8005, VAR_0x8007
    special ChangeRotomForm
    msgbox Rotom_Text_NicknameReluctantlyGaveUp, MSGBOX_DEFAULT
    releaseall
    end

Rotom_Appliances_RotomHasntEnteredMotor::
    msgbox Rotom_Text_HasntEnteredAMotor, MSGBOX_DEFAULT
    releaseall
    end

Rotom_Appliances_Exit::
    releaseall
    end

Rotom_Text_ItsFullOfCarboardBoxes:
    .string "It's full of cardboard boxes with\n"
    .string "electrical appliances in them.$"

Rotom_Text_RotomWouldLikeToInvestigate:
    .string "It's full of cardboard boxes with\n"
    .string "electrical appliances in them.\p"
    .string "Oh?\p"
    .string "Rotom would like to investigate the\n"
    .string "motors of the electrical appliances…\l"
    .string "Is that OK?$"

Rotom_Text_RotomReluctantlyGaveUp:
    .string "Rotom reluctantly gave up on entering\n"
    .string "a motor…$"

Rotom_Text_NicknameReluctantlyGaveUp:
    .string "{STR_VAR_1} reluctantly gave up on\n"
    .string "entering a motor…$"

Rotom_Text_WhichRotom:
    .string "Which Rotom will you allow to enter\n"
    .string "a motor?$"

Rotom_Text_CantEnterMotor:
    .string "That Pokémon can't enter a motor.$"

Rotom_Text_EggCantEnterMotor:
    .string "An Egg can't enter a motor.$"

Rotom_Text_WhichAppliancesMotor:
    .string "Which appliance's motor will you\n"
    .string "allow {STR_VAR_1} to enter?$"

Rotom_Text_EnteredTheMotor:
    .string "{STR_VAR_1} entered the motor.$"

Rotom_Text_TryLearnSpecialMove:
    .string "{STR_VAR_1} is trying to learn\n{STR_VAR_2}.\p"
    .string "But {STR_VAR_1} can't learn more\n"
    .string "than four moves.\p"
    .string "Delete an older move to make\n"
    .string "room for {STR_VAR_2}?$"

Rotom_Text_AlreadyEnteredTheMotor:
    .string "{STR_VAR_1} has already entered that\n"
    .string "appliance motor.$"

Rotom_Text_EmergedFromTheMotor:
    .string "{STR_VAR_1} emerged from the motor.$"

Rotom_Text_HasntEnteredAMotor:
    .string "{STR_VAR_1} hasn't entered a motor.$"

Rotom_Text_RotomForgotMove:
    .string "{PAUSE 32}1, {PAUSE 15}2, and {PAUSE 15}… {PAUSE 15}… {PAUSE 15}… {PAUSE 15}{PLAY_SE SE_BALL_BOUNCE_1}Poof!\p"
    .string "{STR_VAR_1} forgot how to use\n"
    .string "{STR_VAR_2}.\p"
    .string "And…$"

Rotom_Text_LearnedMove:
    .string "{STR_VAR_1} learned {STR_VAR_2}!{WAIT_SE}$"

Rotom_Text_WhichMoveShouldBeForgotten:
	.string "Which move should be forgotten?$"
