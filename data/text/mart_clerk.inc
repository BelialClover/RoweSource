#if GAME_LANGUAGE == LANGUAGE_SPANISH
gText_HowMayIServeYou:: @ 8272A21
	.string "¡Hola!\p"
	.string "¿En qué puedo ayudarte?$"

gText_PleaseComeAgain:: @ 8272A3F
	.string "¡Vuelve cuando quieras!$"

gText_PlayerWhatCanIDoForYou:: @ 8272A52
	.string "¡Hola, {PLAYER}!\p"
	.string "¿En qué puedo ayudarte?$"
#else
gText_HowMayIServeYou:: @ 8272A21
	.string "Welcome!\p"
	.string "How may I serve you?$"

gText_PleaseComeAgain:: @ 8272A3F
	.string "Please come again!$"

gText_PlayerWhatCanIDoForYou:: @ 8272A52
	.string "{PLAYER}{STRING 5}, welcome!\p"
	.string "What can I do for you?$"
#endif
