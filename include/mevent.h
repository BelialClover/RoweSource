#ifndef GUARD_MEVENT_H
#define GUARD_MEVENT_H

struct MEvent_Str_1
{
    u16 unk_000;
    size_t unk_004;
    const void * unk_008;
};

struct MEvent_Str_2
{
    u8 fill_00[0x40];
};

struct MysteryGiftLinkGameData
{
    // It's possible these first 5 fields had some other meaningful purpose,
    // but they are only ever set when creating this data and read to validate it.
    u32 validationVar;									//u32 unk_00;
    u16 validationFlag1;								//u16 unk_04;
    u32 validationFlag2;								//u32 unk_08;
    u16 validationGiftType1;							//u16 unk_0C;
    u32 validationGiftType2;							//u32 unk_10;
    u16 flagId;											//u16 unk_14;
    u16 questionnaireWords[NUM_QUESTIONNAIRE_WORDS]; 	//u16 unk_16[4];
    struct WonderCardMetadata cardMetadata; 			//struct WonderCardMetadata cardMetadata; unk_20;
    u8 maxStamps;										//u8 unk_44;
    u8 playerName[PLAYER_NAME_LENGTH];    				//u8 unk_45[7];
    u8 playerTrainerId[TRAINER_ID_LENGTH];				//u8 unk_4C[4];
    u16 easyChatProfile[EASY_CHAT_BATTLE_WORDS_COUNT];	//u16 unk_50[6];
    u8 romHeaderGameCode[GAME_CODE_LENGTH];				//u8 unk_5C[4];
    u8 romHeaderSoftwareVersion;						//u8 unk_60;
};

void ClearMysteryGift(void);
struct WonderNews *GetSavedWonderNews(void);
struct WonderCard *GetSavedWonderCard(void);
struct WonderCardMetadata *GetSavedWonderCardMetadata(void);
struct WonderNewsMetadata *GetSavedWonderNewsMetadata(void);
u16 *GetQuestionnaireWordsPtr(void);
void DestroyWonderNews(void);
bool32 SaveWonderNews(const struct WonderNews *src);
bool32 ValidateReceivedWonderNews(void);
bool32 IsSendingSavedWonderNewsAllowed(void);
bool32 IsWonderNewsSameAsSaved(const u8 *src);
void DestroyWonderCard(void);
bool32 SaveWonderCard(const struct WonderCard *data);
bool32 ValidateReceivedWonderCard(void);
bool32 WonderCard_Test_Unk_08_6(void);
u16 GetWonderCardFlagID(void);
void WonderCard_ResetInternalReceivedFlag(struct WonderCard *buffer);
bool32 CheckReceivedGiftFromWonderCard(void);
bool32 sub_801B508(const u16 *data);
void sub_801B580(struct MysteryGiftLinkGameData *data, bool32 a1);
bool32 sub_801B6A0(const struct MysteryGiftLinkGameData *data, bool32 a1);
u32 sub_801B6EC(const u16 *a0, const struct MysteryGiftLinkGameData *a1, const void *unused);
u32 sub_801B708(const u16 *a0, const struct MysteryGiftLinkGameData *a1, const void *unused);
bool32 MysteryGiftLinkGameData_CompareField_unk_16(const struct MysteryGiftLinkGameData *a0, const u16 *a1);
u16 MysteryGiftLinkGameData_GetValueNFrom_unk_20(const struct MysteryGiftLinkGameData *a0, u32 command);
u16 mevent_081445C0(u32 command);
void ResetReceivedWonderCardFlag(void);
bool32 MEventHandleReceivedWonderCard(u16 a0);

#endif //GUARD_MEVENT_H
