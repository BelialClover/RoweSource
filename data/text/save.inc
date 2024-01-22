	.align 2
#if GAME_LANGUAGE == LANGUAGE_SPANISH
gText_ConfirmSave:: @ 82C87B4
	.string "¿Quieres guardar la partida?$"

gText_AlreadySavedFile:: @ 82C87D5
	.string "Ya hay una partida guardada.\n"
	.string "¿Quieres sobrescribirla?$"

gText_SavingDontTurnOff:: @ 82C8810
	.string "Guardando…\n"
	.string "No apagues la consola.$"

gText_PlayerSavedGame:: @ 82C8832
	.string "{PLAYER} guardó la partida.$"

gText_DifferentSaveFile:: @ 82C8845
	.string "¡ATENCIÓN!\p"
	.string "Ya hay una partida guardada.\p"
	.string "Si guardas, perderás los datos\n"
	.string "de la partida incluyendo los\l"
	.string "objetos y los Pokémon.\p"
	.string "¿Seguro que quieres guardar ahora\n"
	.string "y sobrescribir los otros datos?$"

gText_SaveError:: @ 82C892A
	.string "Error al guardar.\p"
	.string "Por favor cambie la\n"
	.string "memoria de respaldo.$"

gText_SavingDontTurnOffPower:: @ 82C8959
	.string "Guardando…\n"
	.string "No apagues la consola.$"
	
#else

gText_ConfirmSave:: @ 82C87B4
	.string "Would you like to save the game?$"

gText_AlreadySavedFile:: @ 82C87D5
	.string "There is already a saved file.\n"
	.string "Is it okay to overwrite it?$"

gText_SavingDontTurnOff:: @ 82C8810
	.string "Saving…\n"
	.string "Don't turn off the power.$"

gText_PlayerSavedGame:: @ 82C8832
	.string "{PLAYER} saved the game.$"

gText_DifferentSaveFile:: @ 82C8845
	.string "WARNING!\p"
	.string "There is a different game file that\n"
	.string "is already saved.\p"
	.string "If you save now, the other file's\n"
	.string "adventure, including items and\l"
	.string "Pokémon, will be entirely lost.\p"
	.string "Are you sure you want to save now\n"
	.string "and overwrite the other save file?$"

gText_SaveError:: @ 82C892A
	.string "Save error.\p"
	.string "Please exchange the\n"
	.string "backup memory.$"

gText_SavingDontTurnOffPower:: @ 82C8959
	.string "Saving…\n"
	.string "Don't turn off the power.$"

#endif
