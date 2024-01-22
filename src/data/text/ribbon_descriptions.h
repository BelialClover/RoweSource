#if GAME_LANGUAGE == LANGUAGE_SPANISH
const u8 gRibbonDescriptionPart1_Champion[] = _("Cinta del Hall Fama");
const u8 gRibbonDescriptionPart2_Champion[] = _("por ganar al Campeón");
const u8 gRibbonDescriptionPart1_CoolContest[] = _("Concurso Carisma");
const u8 gRibbonDescriptionPart1_BeautyContest[] = _("Concurso Belleza");
const u8 gRibbonDescriptionPart1_CuteContest[] = _("Concurso Dulzura");
const u8 gRibbonDescriptionPart1_SmartContest[] = _("Concurso Ingenio");
const u8 gRibbonDescriptionPart1_ToughContest[] = _("Concurso Dureza");
const u8 gRibbonDescriptionPart2_NormalRank[] = _("Ganador nivel normal.");
const u8 gRibbonDescriptionPart2_SuperRank[] = _("Ganador nivel alto.");
const u8 gRibbonDescriptionPart2_HyperRank[] = _("Ganador nivel avanzado.");
const u8 gRibbonDescriptionPart2_MasterRank[] = _("Ganador nivel experto.");
const u8 gRibbonDescriptionPart1_Winning[] = _("Cinta del Nivel 50");
const u8 gRibbonDescriptionPart2_Winning[] = _("de Torre Batalla.");
const u8 gRibbonDescriptionPart1_Victory[] = _("Cinta del Nivel Libre");
const u8 gRibbonDescriptionPart2_Victory[] = _("de Torre Batalla.");
const u8 gRibbonDescriptionPart1_Artist[] = _("Cinta ganada por ser");
const u8 gRibbonDescriptionPart2_Artist[] = _("un modelo a seguir.");
const u8 gRibbonDescriptionPart1_Effort[] = _("Cinta ganada por ser");
const u8 gRibbonDescriptionPart2_Effort[] = _("un buen contrincante.");
#else
const u8 gRibbonDescriptionPart1_Champion[] = _("Champion-beating, Hall");
const u8 gRibbonDescriptionPart2_Champion[] = _("of Fame Member Ribbon");
const u8 gRibbonDescriptionPart1_CoolContest[] = _("Cool Contest");
const u8 gRibbonDescriptionPart1_BeautyContest[] = _("Beauty Contest");
const u8 gRibbonDescriptionPart1_CuteContest[] = _("Cute Contest");
const u8 gRibbonDescriptionPart1_SmartContest[] = _("Smart Contest");
const u8 gRibbonDescriptionPart1_ToughContest[] = _("Tough Contest");
const u8 gRibbonDescriptionPart2_NormalRank[] = _("Normal Rank winner!");
const u8 gRibbonDescriptionPart2_SuperRank[] = _("Super Rank winner!");
const u8 gRibbonDescriptionPart2_HyperRank[] = _("Hyper Rank winner!");
const u8 gRibbonDescriptionPart2_MasterRank[] = _("Master Rank winner!");
const u8 gRibbonDescriptionPart1_Winning[] = _("For clearing LV50");
const u8 gRibbonDescriptionPart2_Winning[] = _("at the Battle Tower.");
const u8 gRibbonDescriptionPart1_Victory[] = _("For clearing Open Level");
const u8 gRibbonDescriptionPart2_Victory[] = _("at the Battle Tower.");
const u8 gRibbonDescriptionPart1_Artist[] = _("Ribbon for being chosen");
const u8 gRibbonDescriptionPart2_Artist[] = _("as a super sketch model.");
const u8 gRibbonDescriptionPart1_Effort[] = _("Ribbon awarded for");
const u8 gRibbonDescriptionPart2_Effort[] = _("being a hard worker.");
#endif

const u8 *const gRibbonDescriptionPointers[][2] = 
{
    {gRibbonDescriptionPart1_Champion,      gRibbonDescriptionPart2_Champion},
    {gRibbonDescriptionPart1_CoolContest,   gRibbonDescriptionPart2_NormalRank},
    {gRibbonDescriptionPart1_CoolContest,   gRibbonDescriptionPart2_SuperRank},
    {gRibbonDescriptionPart1_CoolContest,   gRibbonDescriptionPart2_HyperRank},
    {gRibbonDescriptionPart1_CoolContest,   gRibbonDescriptionPart2_MasterRank},
    {gRibbonDescriptionPart1_BeautyContest, gRibbonDescriptionPart2_NormalRank},
    {gRibbonDescriptionPart1_BeautyContest, gRibbonDescriptionPart2_SuperRank},
    {gRibbonDescriptionPart1_BeautyContest, gRibbonDescriptionPart2_HyperRank},
    {gRibbonDescriptionPart1_BeautyContest, gRibbonDescriptionPart2_MasterRank},
    {gRibbonDescriptionPart1_CuteContest,   gRibbonDescriptionPart2_NormalRank},
    {gRibbonDescriptionPart1_CuteContest,   gRibbonDescriptionPart2_SuperRank},
    {gRibbonDescriptionPart1_CuteContest,   gRibbonDescriptionPart2_HyperRank},
    {gRibbonDescriptionPart1_CuteContest,   gRibbonDescriptionPart2_MasterRank},
    {gRibbonDescriptionPart1_SmartContest,  gRibbonDescriptionPart2_NormalRank},
    {gRibbonDescriptionPart1_SmartContest,  gRibbonDescriptionPart2_SuperRank},
    {gRibbonDescriptionPart1_SmartContest,  gRibbonDescriptionPart2_HyperRank},
    {gRibbonDescriptionPart1_SmartContest,  gRibbonDescriptionPart2_MasterRank},
    {gRibbonDescriptionPart1_ToughContest,  gRibbonDescriptionPart2_NormalRank},
    {gRibbonDescriptionPart1_ToughContest,  gRibbonDescriptionPart2_SuperRank},
    {gRibbonDescriptionPart1_ToughContest,  gRibbonDescriptionPart2_HyperRank},
    {gRibbonDescriptionPart1_ToughContest,  gRibbonDescriptionPart2_MasterRank},
    {gRibbonDescriptionPart1_Winning,       gRibbonDescriptionPart2_Winning},
    {gRibbonDescriptionPart1_Victory,       gRibbonDescriptionPart2_Victory},
    {gRibbonDescriptionPart1_Artist,        gRibbonDescriptionPart2_Artist},
    {gRibbonDescriptionPart1_Effort,        gRibbonDescriptionPart2_Effort},
};
