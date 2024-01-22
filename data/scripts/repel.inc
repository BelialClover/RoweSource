EventScript_RepelWoreOff:: @ 82A4B2A
	msgbox Text_RepelWoreOff, MSGBOX_SIGN
	checkitem ITEM_REPEL, 1
	compare VAR_RESULT, TRUE
	goto_if_eq EventScript_RepelWoreOff_AskAnother
	checkitem ITEM_SUPER_REPEL, 1
	compare VAR_RESULT, TRUE
	goto_if_eq EventScript_RepelWoreOff_AskAnother
	checkitem ITEM_MAX_REPEL, 1
	compare VAR_RESULT, FALSE
	goto_if_eq EventScript_RepelWoreOff_End
EventScript_RepelWoreOff_AskAnother:
	msgbox Text_RepelAskAnother, MSGBOX_YESNO
	closemessage
	compare VAR_RESULT, 0
	goto_if_eq EventScript_RepelWoreOff_End
	callnative TryDrawRepelMenu
	compare VAR_RESULT, FALSE
	goto_if_eq EventScript_RepelWoreOff_Chose
	waitstate
	compare VAR_RESULT, 127
	goto_if_eq EventScript_RepelWoreOff_End
EventScript_RepelWoreOff_Chose:
	callnative HandleRepelMenuChoice
	bufferitemname 1, VAR_0x8004
	removeitem VAR_0x8004, 1
	playse SE_REPEL
	msgbox gText_PlayerUsedVar2, MSGBOX_SIGN
EventScript_RepelWoreOff_End:
	end

EventScript_LureWoreOff::
	msgbox Text_LureWoreOff, MSGBOX_SIGN
	checkitem ITEM_LURE, 1
	compare VAR_RESULT, TRUE
	goto_if_eq EventScript_LureWoreOff_AskAnother
	checkitem ITEM_SUPER_LURE, 1
	compare VAR_RESULT, TRUE
	goto_if_eq EventScript_LureWoreOff_AskAnother
	checkitem ITEM_MAX_LURE, 1
	compare VAR_RESULT, FALSE
	goto_if_eq EventScript_LureWoreOff_End
EventScript_LureWoreOff_AskAnother:
	msgbox Text_RepelAskAnother, MSGBOX_YESNO
	closemessage
	compare VAR_RESULT, 0
	goto_if_eq EventScript_LureWoreOff_End
	callnative TryDrawLureMenu
	compare VAR_RESULT, FALSE
	goto_if_eq EventScript_LureWoreOff_Chose
	waitstate
	compare VAR_RESULT, 127
	goto_if_eq EventScript_LureWoreOff_End
EventScript_LureWoreOff_Chose:
	callnative HandleLureMenuChoice
	bufferitemname 1, VAR_0x8004
	removeitem VAR_0x8004, 1
	playse SE_REPEL
	msgbox gText_PlayerUsedVar2, MSGBOX_SIGN
EventScript_LureWoreOff_End:
	end

Text_RepelWoreOff: @ 82A4B33
	.string "Repel's effect wore off…$"
Text_RepelAskAnother:
	.string "Would you like to use another one?$"
Text_LureWoreOff:
	.string "Lure's effect wore off…$"
