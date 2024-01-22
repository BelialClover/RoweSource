#ifndef GUARD_START_MENU_H
#define GUARD_START_MENU_H

extern bool8 (*gMenuCallback)(void);

void ShowReturnToFieldStartMenu(void);
void Task_ShowStartMenu(u8 taskId);
void ShowStartMenu(void);
void ShowUIStartMenu(void);
void ShowBattlePyramidStartMenu(void);
void SaveGame(void);
void CB2_SetUpSaveAfterLinkBattle(void);
void SaveForBattleTowerLink(void);
void HideStartMenu(void);
void AppendToList(u8* list, u8* pos, u8 newEntry);
bool8 HasMapMons(void);

bool8 StartMenuPokedexCallback(void);
bool8 StartMenuPokemonCallback(void);
bool8 StartMenuBagCallback(void);
bool8 StartMenuPokeNavCallback(void);
bool8 StartMenuPlayerNameCallback(void);
bool8 StartMenuSaveCallback(void);
bool8 StartMenuOptionCallback(void);
bool8 StartMenuExitCallback(void);
bool8 StartMenuSafariZoneRetireCallback(void);
bool8 StartMenuLinkModePlayerNameCallback(void);
bool8 StartMenuBattlePyramidRetireCallback(void);
bool8 StartMenuBattlePyramidBagCallback(void);
bool8 StartMenuDexNavCallback(void);
bool8 StartMenuUiModeMenuCallback(void);
bool8 StartMenuUiStartMenuCallback(void);

#endif // GUARD_START_MENU_H
