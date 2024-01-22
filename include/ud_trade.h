#ifndef GUARD_DEBUG_H
#define GUARD_DEBUG_H

void UDTrade_ShowMainMenu(void);
u16 GetDimensionSpeciesFromLocalSpecies(u16 species, u8 dimension);
u16 GetLocalSpeciesFromDimensionSpecies(u16 species, u8 dimension);
u8 CalculateTradeEnemyPartyCount(void);

#endif // GUARD_DEBUG_H