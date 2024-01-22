#if GAME_LANGUAGE == LANGUAGE_SPANISH

gText_PkmnCenterJack_GotPokemonQuestions::
    .string "Soy todo un experto en Pokémon.\n"
    .string "¿En qué te puedo ayudar hoy?$"

@Rate Nickname
Common_PkmnCenterJack_Text_CritiqueWhichMonNickname:
	.string "¿Qué mote quieres que evalúe?$"

Common_PkmnCenterJack_Text_FineNameSuggestBetterOne:
	.string "Hmmm… ¿{STR_VAR_1}, has dicho?\n"
	.string "No está mal, no está mal…\p"
	.string "Pero ¿cómo decirlo? Creo que se le\n"
	.string "podría poner un mote aún mejor.\l"
	.string "¿Qué me dices?$"

Common_PkmnCenterJack_Text_WhatShallNewNameBe:
	.string "Así me gusta. A ver…\n"
	.string "¿Qué mote crees que le pegaría?$"

Common_PkmnCenterJack_Text_MonShallBeKnownAsName:
	.string "¡Ya está! ¡A partir de ahora, el mote\n"
	.string "de esté Pokémon será {STR_VAR_1}!\p"
	.string "Es un mote mucho mejor que el\n"
	.string "anterior. ¡Qué bien!$"

Common_PkmnCenterJack_Text_DoVisitAgain:
	.string "Entiendo…\n"
	.string "Entonces vuelve cuando quieras.$"

Common_PkmnCenterJack_Text_NameNoDifferentYetSuperior:
	.string "¡Ya está! ¡A partir de ahora, el mote\n"
	.string "de esté Pokémon será {STR_VAR_1}!\p"
	.string "No parece muy diferente del anterior\n"
	.string "y, sin embargo, es muchísimo mejor.\l"
	.string "¡Qué suerte tienes!$"

Common_PkmnCenterJack_Text_ThatIsMerelyAnEgg:
	.string "Pero vamos a ver…\n"
	.string "¡Esto es sólo un Huevo!$"

@Remember Move
Common_PkmnCenterJack_Text_TutorWhichMon: @ 82015A5
	.string "Which Pokémon should I have\n"
	.string "remember a move?$"

Common_PkmnCenterJack_Text_TeachWhichMove: @ 82015C3
	.string "Which move should it remember?$"

Common_PkmnCenterJack_Text_DontHaveMoveToTeachPokemon: @ 82015DE
	.string "It doesn't seem like that Pokémon has\n"
	.string "any moves that it can remember.$"

@Forget Move
Common_PkmnCenterJack_Text_WhichMonShouldForget:
	.string "Which Pokémon should forget a move?$"

Common_PkmnCenterJack_Text_WhichMoveShouldBeForgotten:
	.string "Which move should be forgotten?$"

Common_PkmnCenterJack_Text_MonOnlyKnowsOneMove:
	.string "{STR_VAR_1} knows only one move\n"
	.string "so it can't be forgotten…$"

Common_PkmnCenterJack_Text_MonsMoveShouldBeForgotten:
	.string "Hm! {STR_VAR_1}'s {STR_VAR_2}?\n"
	.string "That move should be forgotten?$"

Common_PkmnCenterJack_Text_MonHasForgottenMove:
	.string "It worked to perfection!\p"
	.string "{STR_VAR_1} has forgotten\n"
	.string "{STR_VAR_2} completely.$"

Common_PkmnCenterJack_Text_ComeAgain:
	.string "Come again if there are moves that\n"
	.string "need to be forgotten.$"

Common_PkmnCenterJack_Text_EggCantForgetMoves:
	.string "What?\n"
	.string "No Egg should know any moves.$"

Common_PkmnCenterJack_Text_CantForgetSurf:
	.string "Hm!\p"
	.string "Your {STR_VAR_1} doesn't seem willing\n"
	.string "to forget Surf.$"

@Move Tutor
gText_PkmnCenterJack_Teach::
    .string "Tutor$"

@Nevermind
gText_PkmnCenterJack_ComeBackAnytime::
    .string "¡Vuelve cuando quieras!$"

#else

gText_PkmnCenterJack_GotPokemonQuestions::
    .string "Do you need anything?\n"
    .string "Feel free to ask away.$"

gText_PkmnCenterJack_Change_Costume::
    .string "What costume do you want\n"
    .string "to use?$"
	
gText_PkmnCenterJack_TeachMoves::
    .string "What kind of move you want\n"
    .string "your Pokémon to learn?$"
	
gText_PkmnCenterJack_Teach_TM_Moves::
    .string "This will cost you 6000,\n"
    .string "do you want to Continue?$"
	
gText_PkmnCenterJack_Teach_Egg_Moves::
    .string "This will cost you 3000,\n"
    .string "do you want to Continue?$"
	
gText_PkmnCenterJack_Teach_Tutor_Moves::
    .string "This will cost you 4500,\n"
    .string "do you want to Continue?$"
	
gText_PkmnCenterJack_CantTeachMoves::
	.string "You need to get more badges\n"
	.string "before I can help you with that.$"

@Rate Nickname
Common_PkmnCenterJack_Text_CritiqueWhichMonNickname:
	.string "Which Pokémon's nickname should\n"
	.string "I rate for you?$"

Common_PkmnCenterJack_Text_FineNameSuggestBetterOne:
	.string "Hmmm… {STR_VAR_1}, is it? That is\n"
	.string "quite a fine nickname.\p"
	.string "But I think we could give it\n"
	.string "one even better. What do you think?$"

Common_PkmnCenterJack_Text_WhatShallNewNameBe:
	.string "I see! What would you like the new\n"
	.string "nickname to be?$"

Common_PkmnCenterJack_Text_MonShallBeKnownAsName:
	.string "Done! From now on, this Pokémon\n"
	.string "shall be known as {STR_VAR_1}!\p"
	.string "You're right, that does seem to\n"
	.string "fit it better. Nicely done!$"

Common_PkmnCenterJack_Text_DoVisitAgain:
	.string "All right. Let me know if you\n"
	.string "change your mind.$"

Common_PkmnCenterJack_Text_NameNoDifferentYetSuperior:
	.string "Done! From now on, this Pokémon\n"
	.string "shall be known as {STR_VAR_1}!\p"
	.string "It looks no different from before,\n"
	.string "and yet, this is vastly superior!\p"
	.string "How fortunate for you!$"

Common_PkmnCenterJack_Text_ThatIsMerelyAnEgg:
	.string "Now, now…\n"
	.string "That is merely an Egg.$"

@Remember Move
Common_PkmnCenterJack_Text_TutorWhichMon: @ 82015A5
	.string "Which Pokémon should I have\n"
	.string "remember a move?$"

Common_PkmnCenterJack_Text_TeachWhichMove: @ 82015C3
	.string "Which move should it remember?$"

Common_PkmnCenterJack_Text_DontHaveMoveToTeachPokemon: @ 82015DE
	.string "It doesn't seem like that Pokémon has\n"
	.string "any moves that it can remember.$"

@Forget Move
Common_PkmnCenterJack_Text_WhichMonShouldForget:
	.string "Which Pokémon should forget a move?$"

Common_PkmnCenterJack_Text_WhichMoveShouldBeForgotten:
	.string "Which move should be forgotten?$"

Common_PkmnCenterJack_Text_MonOnlyKnowsOneMove:
	.string "{STR_VAR_1} knows only one move\n"
	.string "so it can't be forgotten…$"

Common_PkmnCenterJack_Text_MonsMoveShouldBeForgotten:
	.string "Hm! {STR_VAR_1}'s {STR_VAR_2}?\n"
	.string "That move should be forgotten?$"

Common_PkmnCenterJack_Text_MonHasForgottenMove:
	.string "It worked to perfection!\p"
	.string "{STR_VAR_1} has forgotten\n"
	.string "{STR_VAR_2} completely.$"

Common_PkmnCenterJack_Text_ComeAgain:
	.string "Come again if there are moves that\n"
	.string "need to be forgotten.$"

Common_PkmnCenterJack_Text_EggCantForgetMoves:
	.string "What?\n"
	.string "No Egg should know any moves.$"

Common_PkmnCenterJack_Text_CantForgetSurf:
	.string "Hm!\p"
	.string "Your {STR_VAR_1} doesn't seem willing\n"
	.string "to forget Surf.$"

@Move Tutor
gText_PkmnCenterJack_Teach::
    .string "Teach$"
	
Text_IVChecker_1:
	.string "Your {STR_VAR_1}...$"

Text_IVChecker_2:
	.string "Your Pokémon's IVs are...\n"
	.string "HP: {STR_VAR_1}, Atk: {STR_VAR_2}, Def: {STR_VAR_3}$"

Text_IVChecker_3:
	.string "SpAtk: {STR_VAR_1}, SpDef: {STR_VAR_2}, Speed: {STR_VAR_3}\n"
	.string "Come back anytime!$"

@Nevermind
gText_PkmnCenterJack_ComeBackAnytime::
    .string "Come back anytime!$"
	
Common_PkmnCenterJack_Text_WonderTrade1:
	.string "Do you want to try\n"
	.string "Wonder Trading?$"
	
Common_PkmnCenterJack_Text_WonderTrade2:
	.string "Take care of your new Pokémon.$"
	
Common_PkmnCenterJack_Text_MockBattle:
	.string "What kind of mock battle do you want\n"
	.string "to start?$"
	
Common_PkmnCenterJack_Text_MockBattle_Easy:
	.string "Easy Mock Battle: Start!$"
	
Common_PkmnCenterJack_Text_MockBattle_Normal:
	.string "Normal Mock Battle: Start!$"
	
Common_PkmnCenterJack_Text_MockBattle_Hard:
	.string "Hard Mock Battle: Start!$"

Common_PkmnCenterJack_Text_MockBattle_PSS:
	.string "PC Storage Mock Battle: Start!$"
	
Common_PkmnCenterJack_Text_MockBattle_Defeat:
	.string "That was a nice battle,\n"
	.string "Good Work!$"

Common_PkmnCenterJack_Text_No_Costume:
	.string "Sorry but this costume\n"
	.string "is not available yet.$"

#endif
