#ifndef GUARD_QUESTS_H
#define GUARD_QUESTS_H 

//#include constants/quests.h       //included in global.h

//#define FLAG_QUEST_MENU_ACTIVE    0x264 //added to constants/flags.h

#define NO_ACTIVE_QUEST             -1

struct SideQuest 
{
	/*0x00*/ const u8* name;
	/*0x04*/ const u8* desc; 
	/*0x14*/ u16 reward;
	/*0x0C*/ u8  reward_qty;
	/*0x04*/ const u8* hint; 
	/*0x14*/ u16 reward_flag;
}; /* size = 0x18 */


extern const struct SideQuest gSideQuests[SIDE_QUEST_COUNT];

enum 
{
	QUEST_DIFFICULTY_EASY,
	QUEST_DIFFICULTY_MEDIUM,
	QUEST_DIFFICULTY_HARD,
	QUEST_DIFFICULTY_EXTREME,
	QUEST_DIFFICULTY_IMPOSSIBLE,
	QUEST_DIFFICULTY_DISABLED,
};

enum QuestCases
{
    FLAG_GET_UNLOCKED,      // check if quest is unlocked
    FLAG_SET_UNLOCKED,      // mark unlocked quest
    FLAG_GET_COMPLETED,     // check if quest is completed
    FLAG_SET_COMPLETED,     // mark completed quest
};

// functions
void CreateItemMenuIcon(u16, u8);
void ResetItemMenuIconState(void);
void DestroyItemMenuIcon(u8 idx);
void Task_OpenQuestMenuFromStartMenu(u8);
s8 GetSetQuestFlag(u8 quest, u8 caseId);
s8 GetActiveQuestIndex(void);
void SetActiveQuest(u8 questId);
void TextWindow_SetStdFrame0_WithPal(u8 windowId, u16 destOffset, u8 palIdx);
void QuestMenu_Init(u8 a0, MainCallback callback);
void SetQuestMenuActive(void);
void ResetActiveQuest(void);
void GetQuestName(u8 *dst, u8 questId);
void CopyQuestName(u8 *dst, u8 questId);
void ResetQuestFlags(void);

#endif // GUARD_QUESTS_H