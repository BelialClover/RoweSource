Route120_EventScript_Kecleon1:: @ 82722DB
	lock
	faceplayer
	setvar VAR_0x8009, 1
	goto EventScript_Kecleon
	end

Route120_EventScript_Kecleon2:: @ 82722E8
	lock
	faceplayer
	setvar VAR_0x8009, 2
	goto EventScript_Kecleon
	end

Route120_EventScript_Kecleon3:: @ 82722F5
	lock
	faceplayer
	setvar VAR_0x8009, 3
	goto EventScript_Kecleon
	end

Route120_EventScript_Kecleon4:: @ 8272302
	lock
	faceplayer
	setvar VAR_0x8009, 4
	goto EventScript_Kecleon
	end

Route120_EventScript_Kecleon5:: @ 827230F
	lock
	faceplayer
	setvar VAR_0x8009, 5
	goto EventScript_Kecleon
	end

Route119_EventScript_Kecleon1:: @ 827231C
	lock
	faceplayer
	setvar VAR_0x8009, 6
	goto EventScript_Kecleon
	end

Route119_EventScript_Kecleon2:: @ 8272329
	lock
	faceplayer
	setvar VAR_0x8009, 7
	goto EventScript_Kecleon
	end

EventScript_Kecleon:: @ 8272336
	goto EventScript_AskUseDevonScope
	//msgbox Kecleon_Text_SomethingUnseeable, MSGBOX_DEFAULT
	release
	end

EventScript_AskUseDevonScope:: @ 8272350
	msgbox Kecleon_Text_WantToUseDevonScope, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq EventScript_BattleKecleon
	release
	end

EventScript_BattleKecleon:: @ 8272365
	msgbox Kecleon_Text_UseDevonScopeMonAttacked, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FacePlayer
	waitmovement 0
	applymovement VAR_LAST_TALKED, Movement_KecleonAppears
	waitmovement 0
	waitse
	playmoncry SPECIES_KECLEON, 2
	delay 40
	waitmoncry
	setwildbattle SPECIES_KECLEON, 1, ITEM_NONE
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	dowildbattle
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq EventScript_RemoveKecleon
	compare VAR_RESULT, B_OUTCOME_RAN
	goto_if_eq EventScript_RemoveKecleon
	compare VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED
	goto_if_eq EventScript_RemoveKecleon
	release
	end

EventScript_RemoveKecleon:: @ 82723C1
	goto Common_EventScript_RemoveStaticPokemon
	end

Movement_KecleonAppears: @ 82723C7
	set_visible
	delay_4
	set_invisible
	delay_4
	set_visible
	delay_4
	set_invisible
	delay_4
	set_visible
	delay_8
	set_invisible
	delay_8
	set_visible
	delay_8
	set_invisible
	delay_8
	set_visible
	delay_16
	set_invisible
	delay_16
	set_visible
	step_end
	
// Munchlax & Snorlax -------------------------------------------------------------------------
EventScript_SetMunchlaxFamilyGfx:: @ 82574C6
	special ShouldStaticEncounterBeFirstStage
	compare VAR_RESULT, TRUE
	goto_if_eq EventScript_SetMunchlaxGfx
	goto_if_unset FLAG_BADGE04_GET, EventScript_SetMunchlaxGfx
    goto_if_set   FLAG_BADGE04_GET, EventScript_SetSnorlaxGfx
	return
	
EventScript_SetMunchlaxGfx:: @ 82574C6
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_MUNCHLAX
	return
	
EventScript_SetSnorlaxGfx:: @ 82574C6
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_SNORLAX
	return

EventScript_Snorlax:: @ 8272350
	msgbox Snorlax_Text_MonSprawledOutInSlumber, MSGBOX_DEFAULT
	checkitem ITEM_BLUE_FLUTE, 1
	compare VAR_RESULT, TRUE
	goto_if_eq EventScript_Snorlax_AskUseFlute
	release
	end

EventScript_Snorlax_AskUseFlute:: @ 8272350
	msgbox Snorlax_Text_WantToUsePokeFlute, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq EventScript_BattleSnorlax
	release
	end
	
EventScript_BattleSnorlax:: @ 8272365
	goto_if_unset FLAG_BADGE04_GET, EventScript_BattleMunchlax
	goto_if_set FLAG_TEMP_5, EventScript_BattleMunchlax
	msgbox Snorlax_Text_PlayedPokeFlute, MSGBOX_DEFAULT
	playfanfare MUS_RG_JIGGLYPUFF
	delay 400
	playse SE_PIN
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_Delay48
	waitmovement 0
	msgbox Snorlax_Text_SnorlaxWokeUp, MSGBOX_DEFAULT
	closemessage
	waitse
	playmoncry SPECIES_SNORLAX, 2
	delay 40
	waitmoncry
	setwildbattle SPECIES_SNORLAX, 2, ITEM_LEFTOVERS
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	dowildbattle
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq EventScript_RemoveSnorlax
	compare VAR_RESULT, B_OUTCOME_CAUGHT
	goto_if_eq EventScript_RemoveSnorlax
	compare VAR_RESULT, B_OUTCOME_RAN
	goto_if_eq EventScript_RemoveSnorlax
	compare VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED
	goto_if_eq EventScript_RemoveSnorlax
	release
	end
	
EventScript_BattleMunchlax:: @ 8272365
	msgbox Snorlax_Text_PlayedPokeFlute, MSGBOX_DEFAULT
	playfanfare MUS_RG_JIGGLYPUFF
	delay 400
	playse SE_PIN
	msgbox Snorlax_Text_SnorlaxWokeUp, MSGBOX_DEFAULT
	closemessage
	waitse
	playmoncry SPECIES_MUNCHLAX, 2
	delay 40
	waitmoncry
	setwildbattle SPECIES_MUNCHLAX, 2, ITEM_LEFTOVERS
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	dowildbattle
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq EventScript_RemoveSnorlax
	compare VAR_RESULT, B_OUTCOME_CAUGHT
	goto_if_eq EventScript_RemoveSnorlax
	compare VAR_RESULT, B_OUTCOME_RAN
	goto_if_eq EventScript_RemoveSnorlax
	compare VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED
	goto_if_eq EventScript_RemoveSnorlax
	release
	end
	
EventScript_RemoveSnorlax:: @ 82723C1
	goto Common_EventScript_RemoveStaticPokemon
	end

Snorlax_Text_MonSprawledOutInSlumber::
    .string "A Pokémon is sprawled out in\n"
    .string "a deep and comfortable slumber.$"

Snorlax_Text_SnorlaxWokeUp::
    .string "The Pokémon woke up!\p"
    .string "It attacked in a grumpy rage!$"

Snorlax_Text_SnorlaxReturnedToMountains::
    .string "The Pokémon calmed down.\n"
    .string "It gave a huge yawn…\l"
    .string "And returned to the mountains.$"

Snorlax_Text_WantToUsePokeFlute::
    .string "Do you want to use the Blue Flute?$"

Snorlax_Text_PlayedPokeFlute::
    .string "{PLAYER} played the Blue Flute.$"
	
// Bonsly & Sudowoodo -------------------------------------------------------------------------
EventScript_SetSudowoodoFamilyGfx:: @ 82574C6
	special ShouldStaticEncounterBeFirstStage
	compare VAR_RESULT, TRUE
	goto_if_eq EventScript_SetBonslyGfx
	goto_if_unset FLAG_BADGE03_GET, EventScript_SetBonslyGfx
    goto_if_set   FLAG_BADGE03_GET, EventScript_SetSudowoodoGfx
	return
	
EventScript_SetBonslyGfx:: @ 82574C6
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_BONSLY
	return
	
EventScript_SetSudowoodoGfx:: @ 82574C6
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_SUDOWOODO
	return

EventScript_Sudowoodo::
	lock
	faceplayer
	waitse
	playse SE_SUDOWOODO_SHAKE
	applymovement VAR_LAST_TALKED, Sudowoodo_Movement_SudowoodoShake
	waitmovement 0
	release
	end

EventScript_WaterSudowoodo::
	lock
	faceplayer
	goto_if_unset FLAG_BADGE03_GET, EventScript_WaterBonsly
	goto_if_set FLAG_TEMP_5, EventScript_WaterBonsly
	special DoWateringBerryTreeAnim
	waitstate
	waitse
	playse SE_SUDOWOODO_SHAKE
	applymovement VAR_LAST_TALKED, Sudowoodo_Movement_SudowoodoShake
	waitmovement 0
	msgbox gText_Sudowoodo_Attacked, MSGBOX_DEFAULT
	closemessage
	waitse
	playmoncry SPECIES_SUDOWOODO, 2
	delay 40
	waitmoncry
	setwildbattle SPECIES_SUDOWOODO, 1, ITEM_NONE
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	dowildbattle
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq EventScript_DefeatedSudowoodo
	compare VAR_RESULT, B_OUTCOME_RAN
	goto_if_eq EventScript_DefeatedSudowoodo
	compare VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED
	goto_if_eq EventScript_DefeatedSudowoodo
	release
	end
	
EventScript_WaterBonsly::
	special DoWateringBerryTreeAnim
	waitstate
	waitse
	playse SE_SUDOWOODO_SHAKE
	applymovement VAR_LAST_TALKED, Sudowoodo_Movement_SudowoodoShake
	waitmovement 0
	msgbox gText_Sudowoodo_Attacked, MSGBOX_DEFAULT
	closemessage
	waitse
	playmoncry SPECIES_BONSLY, 2
	delay 40
	waitmoncry
	setwildbattle SPECIES_BONSLY, 1, ITEM_NONE
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	dowildbattle
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq EventScript_DefeatedSudowoodo
	compare VAR_RESULT, B_OUTCOME_RAN
	goto_if_eq EventScript_DefeatedSudowoodo
	compare VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED
	goto_if_eq EventScript_DefeatedSudowoodo
	release
	end

EventScript_DefeatedSudowoodo:: @ 8242D60
	goto Common_EventScript_RemoveStaticPokemon
	end

Sudowoodo_Movement_SudowoodoShake: @ 8242D69
	face_right
	delay_8
	face_down
	delay_8
	face_left
	delay_8
	face_down
	delay_8
	face_right
	delay_8
	face_down
	delay_8
	face_left
	delay_8
	face_down
	step_end