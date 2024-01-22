#ifndef GUARD_BATTLE_AI_SCRIPT_COMMANDS_H
#define GUARD_BATTLE_AI_SCRIPT_COMMANDS_H

// return values for BattleAI_ChooseMoveOrAction
// 0 - 3 are move idx
#define AI_CHOICE_FLEE 4
#define AI_CHOICE_WATCH 5
#define AI_CHOICE_SWITCH 7

// for IsAiFaster
#define AI_CHECK_FASTER   0       // if_user_faster
#define AI_CHECK_SLOWER   1       // if_target_faster

#define FOE(battler) ((battler ^ BIT_SIDE) & BIT_SIDE)

#define RETURN_SCORE_MINUS(val)     \
{                                   \
    score -= val;                   \
    return score;                   \
}

s32 AI_CalcDamage(u16 move, u8 battlerAtk, u8 battlerDef);
s32 AI_CalcPartyMonDamage(u16 move, u8 battlerAtk, u8 battlerDef, struct Pokemon *mon);
u16 AI_GetTypeEffectiveness(u16 move, u8 battlerAtk, u8 battlerDef);
void BattleAI_SetupItems(void);
void BattleAI_SetupFlags(void);
void BattleAI_SetupAIData(u8 defaultScoreMoves);
u8 BattleAI_ChooseMoveOrAction(void);
bool32 IsTruantMonVulnerable(u32 battlerAI, u32 opposingBattler);
bool32 IsBattlerAIControlled(u32 battlerId);
void ClearBattlerMoveHistory(u8 battlerId);
void RecordLastUsedMoveBy(u32 battlerId, u32 move);
void RecordKnownMove(u8 battlerId, u32 move);
void RecordAbilityBattle(u8 battlerId, u16 abilityId);
void ClearBattlerAbilityHistory(u8 battlerId);
void RecordItemEffectBattle(u8 battlerId, u8 itemEffect);
void ClearBattlerItemEffectHistory(u8 battlerId);
s32 CountUsablePartyMons(u8 battlerId);
u16 *GetMovesArray(u32 battler);
bool32 IsTargetingPartner(u8 battlerAtk, u8 battlerDef);
bool32 IsStatLoweringMoveEffect(u16 moveEffect);
bool32 IsNonVolatileStatusMoveEffect(u16 moveEffect);
bool32 IsMoveRedirectionPrevented(u16 move, u16 atkAbility);
bool32 BattlerStatCanRise(u8 battler, u16 battlerAbility, u8 stat);
bool32 HasMoveWithType(u32 battler, u8 type);
bool32 HasMoveWithTypeAndSplit(u32 battler, u8 type, u8 split);

bool32 AnyStatIsRaised(u8 battlerId);
bool32 ShouldLowerStat(u8 battler, u16 battlerAbility, u8 stat);
bool32 BattlerStatCanRise(u8 battler, u16 battlerAbility, u8 stat);
bool32 AreBattlersStatsMaxed(u8 battler);
u32 CountPositiveStatStages(u8 battlerId);
u32 CountNegativeStatStages(u8 battlerId);
bool32 ShouldLowerAttack(u8 battlerAtk, u8 battlerDef, u16 defAbility);
bool32 ShouldLowerDefense(u8 battlerAtk, u8 battlerDef, u16 defAbility);/*
bool32 ShouldLowerSpeed(u8 battlerAtk, u8 battlerDef, u16 defAbility);
bool32 ShouldLowerSpAtk(u8 battlerAtk, u8 battlerDef, u16 defAbility);
bool32 ShouldLowerSpDef(u8 battlerAtk, u8 battlerDef, u16 defAbility);
bool32 ShouldLowerAccuracy(u8 battlerAtk, u8 battlerDef, u16 defAbility);
bool32 ShouldLowerEvasion(u8 battlerAtk, u8 battlerDef, u16 defAbility);*/

bool32 IsBattlerIncapacitated(u8 battler, u16 ability);
bool32 ShouldTryOHKO(u8 battlerAtk, u8 battlerDef, u16 atkAbility, u16 defAbility, u32 accuracy, u16 move);
u32 GetHealthPercentage(u8 battler);
bool32 AtMaxHp(u8 battlerId);
bool32 PartnerHasSameMoveEffectWithoutTarget(u8 battlerAtkPartner, u16 move, u16 partnerMove);
bool32 TestMoveFlagsInMoveset(u8 battler, u32 flags);
bool32 IsWakeupTurn(u8 battler);
bool32 IsBattlerTrapped(u8 battler, bool8 switching);
bool32 DoesPartnerHaveSameMoveEffect(u8 battlerAtkPartner, u8 battlerDef, u16 move, u16 partnerMove);
bool32 PartnerMoveIsSameNoTarget(u8 battlerAtkPartner, u16 move, u16 partnerMove);
bool32 PartnerMoveEffectIsWeather(u8 battlerAtkPartner, u16 partnerMove);
bool32 CanBeInfatuated(u8 battlerAtk, u8 battlerDef, u16 defAbility, u8 atkGender, u8 defGender);
bool32 CanIndexMoveFaintTarget(u8 battlerAtk, u8 battlerDef, u8 index, u8 numHits);
bool32 HasDamagingMove(u8 battlerId);
u32 GetBattlerSecondaryDamage(u8 battlerId);
bool32 ShouldUseRecoilMove(u8 battlerAtk, u8 battlerDef, u32 recoilDmg, u8 moveIndex);
bool32 CanTargetFaintAi(u8 battlerDef, u8 battlerAtk);
bool32 AnyPartyMemberStatused(u8 battlerId, bool32 checkSoundproof);
bool32 IsHazardMoveEffect(u16 moveEffect);
bool32 IsPartyFullyHealedExceptBattler(u8 battler);
u16 GetBattlerSideSpeedAverage(u8 battler);
bool32 PartnerMoveIs(u8 battlerAtkPartner, u16 partnerMove, u16 moveCheck);
bool32 PartnerMoveIsSameAsAttacker(u8 battlerAtkPartner, u8 battlerDef, u16 move, u16 partnerMove);
bool32 IsAiFaster(u8 battler);
bool32 CanAIFaintTarget(u8 battlerAtk, u8 battlerDef, u8 numHits);
bool32 CanMoveFaintBattler(u16 move, u8 battlerDef, u8 battlerAtk, u8 nHits);
bool32 HasThawingMove(u8 battlerId);

#endif // GUARD_BATTLE_AI_SCRIPT_COMMANDS_H
