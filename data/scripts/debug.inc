Debug_ShowFieldMessageStringVar4::
	special ShowFieldMessageStringVar4
	waitmessage
	waitbuttonpress
	releaseall
	end

Debug_CheatStart::
	lockall
	setvar VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 5
	clearflag FLAG_DEFEATED_LATIAS
	clearflag FLAG_DEFEATED_LATIOS
	closemessage
	release
	end
