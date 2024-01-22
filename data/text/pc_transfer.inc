#if GAME_LANGUAGE == LANGUAGE_SPANISH
gText_PkmnTransferredSomeonesPC:: @ 8273216
	.string "{STR_VAR_2} fue enviado al PC\n"
	.string "de alguien.\p"
	.string "Se ha guardado en la Caja\n"
	.string "“{STR_VAR_1}.”$"

gText_PkmnTransferredLanettesPC:: @ 8273256
	.string "{STR_VAR_2} fue enviado al PC\nde Aredia.\p"
	.string "Se ha guardado en la Caja\n"
	.string "“{STR_VAR_1}”.$"

gText_PkmnTransferredSomeonesPCBoxFull:: @ 8273296
	.string "La Caja “{STR_VAR_3}” del PC\n"
	.string "de alguien estaba llena.\p"
	.string "{STR_VAR_2} fue enviado a la Caja\n"
	.string "“{STR_VAR_1}”.$"

gText_PkmnTransferredLanettesPCBoxFull:: @ 82732D9
	.string "La Caja “{STR_VAR_3}” del PC\n"
	.string "de Aredia estaba llena.\p"
	.string "{STR_VAR_2} fue enviado a la Caja\n"
	.string "“{STR_VAR_1}”.$"

gText_NoMoreRoomForPokemon:: @ 827331C
	.string "¡No queda sitio para más Pokémon!\p"
	.string "¡Las Cajas Pokémon están llenas!$"

gText_NicknameThisPokemon:: @ 8273374
	.string "Do you want to give a nickname to\n"
	.string "this {STR_VAR_1}?$"
#else
gText_PkmnTransferredSomeonesPC:: @ 8273216
	.string "{STR_VAR_2} was transferred to\n"
	.string "Someone's PC.\p"
	.string "It was placed in \n"
	.string "Box “{STR_VAR_1}.”$"

gText_PkmnTransferredLanettesPC:: @ 8273256
	.string "{STR_VAR_2} was transferred to\nLanette's PC.\p"
	.string "It was placed in \n"
	.string "Box “{STR_VAR_1}.”$"

gText_PkmnTransferredSomeonesPCBoxFull:: @ 8273296
	.string "Box “{STR_VAR_3}” on\n"
	.string "Someone's PC was full.\p"
	.string "{STR_VAR_2} was transferred to\n"
	.string "Box “{STR_VAR_1}.”$"

gText_PkmnTransferredLanettesPCBoxFull:: @ 82732D9
	.string "Box “{STR_VAR_3}” on\n"
	.string "Lanette's PC was full.\p"
	.string "{STR_VAR_2} was transferred to\n"
	.string "Box “{STR_VAR_1}.”$"

gText_NoMoreRoomForPokemon:: @ 827331C
	.string "There's no more room for Pokémon!\p"
	.string "The Pokémon Boxes are full and\n"
	.string "can't accept any more!$"

gText_NicknameThisPokemon:: @ 8273374
	.string "Do you want to give a nickname to\n"
	.string "this {STR_VAR_1}?$"

#endif
