#ifndef GUARD_EVOLUTION_SCENE_H
#define GUARD_EVOLUTION_SCENE_H

void BeginEvolutionScene(struct Pokemon* mon, u16 speciesToEvolve, bool8 canStopEvo, u8 partyID, u8 formIdToEvolve);
void EvolutionScene(struct Pokemon* mon, u16 speciesToEvolve, bool8 canStopEvo, u8 partyID, u8 formIdToEvolve);
void TradeEvolutionScene(struct Pokemon* mon, u16 speciesToEvolve, u8 preEvoSpriteID, u8 partyID, u8 formIdToEvolve);

extern void (*gCB2_AfterEvolution)(void);

#endif // GUARD_EVOLUTION_SCENE_H
