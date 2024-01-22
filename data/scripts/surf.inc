EventScript_UseSurf:: @ 8271EA0
	checkpartymove MOVE_SURF
	compare VAR_RESULT, PARTY_SIZE
	goto_if_eq EventScript_EndUseSurf
	bufferpartymonnick 0, VAR_RESULT
	setfieldeffectargument 0, VAR_RESULT
	lockall
	msgbox gText_WantToUseSurf, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq EventScript_ReleaseUseSurf
	msgbox gText_PlayerUsedSurf, MSGBOX_DEFAULT
	dofieldeffect FLDEFF_USE_SURF
EventScript_ReleaseUseSurf:: @ 8271ED5
	releaseall
EventScript_EndUseSurf:: @ 8271ED6
	end

EventScript_ExploudSurf::
	setvar VAR_0x8004, SPECIES_LAPRAS
	setvar VAR_0x8008, MOVE_SURF
	setvar VAR_0x8009, 1
	bufferspeciesname 0, VAR_0x8004	
	buffermovename 1, VAR_0x8008
	msgbox Text_ExploudSurf, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq EventScript_ReleaseUseSurf
	msgbox Text_MonUsedFieldMove, MSGBOX_DEFAULT
	closemessage
	dofieldeffect FLDEFF_USE_SURF
	end
