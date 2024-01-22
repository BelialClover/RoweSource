#if GAME_LANGUAGE == LANGUAGE_SPANISH
Text_BootUpPC: @ 827265A
	.string "{PLAYER} encendió el PC.$"

gText_WhichPCShouldBeAccessed:: @ 827266F
	.string "¿A qué PC quieres acceder?$"

gText_AccessedSomeonesPC:: @ 827268C
	.string "Accedido al PC de alguien.$"

gText_StorageSystemOpened:: @ 82726A3
	.string "Ingresado al Sistema de Almacenamiento\n"
	.string "de Pokémon.$"

gText_AccessedPlayersPC:: @ 82726C2
	.string "Accedido al PC de {PLAYER}.$"

gText_AccessedLanettesPC:: @ 82726D4
	.string "Accedido al PC de Aredia.$"
#else
Text_BootUpPC: @ 827265A
	.string "{PLAYER} booted up the PC.$"

gText_WhichPCShouldBeAccessed:: @ 827266F
	.string "Which PC should be accessed?$"

gText_AccessedSomeonesPC:: @ 827268C
	.string "Accessed Someone's PC.$"

gText_StorageSystemOpened:: @ 82726A3
	.string "Pokémon Storage System opened.$"

gText_AccessedPlayersPC:: @ 82726C2
	.string "Accessed {PLAYER}'s PC.$"

gText_AccessedLanettesPC:: @ 82726D4
	.string "Accessed Lanette's PC.$"
#endif
