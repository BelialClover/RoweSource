UDTrade_EventScript_OpenDimensionList::
	lockall
	faceplayer
	message UDTrade_Text_WhichDimension
	waitmessage
	delay 28
	special OpenUDTradeMenu
	waitstate
	end

UDTrade_EventScript_SpeciesNotAllowed::
	msgbox UDTrade_Text_SpeciesNotAllowed
	goto UDTrade_EventScript_OpenDimensionList
	end
	
UDTrade_EventScript_ItemNotAllowed::
	msgbox UDTrade_Text_ItemNotAllowed
	goto UDTrade_EventScript_OpenDimensionList
	end
	
UDTrade_EventScript_MoveNotAllowed::
	msgbox UDTrade_Text_MoveNotAllowed
	goto UDTrade_EventScript_OpenDimensionList
	end
	
UDTrade_EventScript_on_Mantainance::
	msgbox UDTrade_Text_on_Mantainance
	goto UDTrade_EventScript_OpenDimensionList
	end
	
UDTrade_EventScript_Mode_Not_Allowed_To_Trade::
	msgbox UDTrade_Text_Mode_Not_Allowed_To_Trade
	goto UDTrade_EventScript_OpenDimensionList
	end

UDTrade_Text_WhichDimension:
	.string "With which Ultra Dimension do you\n"
	.string "wish to link with?$"

UDTrade_Text_on_Mantainance:
	.string "I'm sorry, but {STR_VAR_1} is not\n"
	.string "working at the moment.$"

UDTrade_Text_SpeciesNotAllowed:
	.string "I'm sorry, but {STR_VAR_1} is not\n"
	.string "allowed in the {STR_VAR_2}.$"

UDTrade_Text_ItemNotAllowed:
	.string "I'm sorry, but {STR_VAR_1} can't carry\n"
	.string "a Held Item into the {STR_VAR_2}.$"
	
UDTrade_Text_Mode_Not_Allowed_To_Trade:
	.string "I'm sorry, but you can't trade\n"
	.string "with the modes you have enabled.$"

UDTrade_Text_MoveNotAllowed:
	.string "I'm sorry, but {STR_VAR_1} can't go\n"
	.string "into the {STR_VAR_2} while\l"
	.string "knowing the move {STR_VAR_3}.$"
