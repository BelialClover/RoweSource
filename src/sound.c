#include "global.h"
#include "gba/m4a_internal.h"
#include "sound.h"
#include "battle.h"
#include "event_data.h"
#include "m4a.h"
#include "main.h"
#include "pokemon.h"
#include "rtc.h"
#include "day_night.h"
#include "script.h"
#include "constants/songs.h"
#include "constants/flags.h"
#include "task.h"
#ifdef GBA_PRINTF
#include "printf.h"
#include "mgba.h"
#endif

struct Fanfare
{
    u16 songNum;
    u16 duration;
};

// ewram
EWRAM_DATA struct MusicPlayerInfo* gMPlay_PokemonCry = NULL;
EWRAM_DATA u8 gPokemonCryBGMDuckingCounter = 0;

// iwram bss
static u16 sCurrentMapMusic;
static u16 sNextMapMusic;
static u8 sMapMusicState;
static u8 sMapMusicFadeInSpeed;
static u16 sFanfareCounter;

// iwram common
bool8 gDisableMusic;

extern struct MusicPlayerInfo gMPlayInfo_BGM;
extern struct MusicPlayerInfo gMPlayInfo_SE1;
extern struct MusicPlayerInfo gMPlayInfo_SE2;
extern struct MusicPlayerInfo gMPlayInfo_SE3;
extern struct ToneData gCryTable[];
extern struct ToneData gCryTable2[]; 

static void Task_Fanfare(u8 taskId);
static void CreateFanfareTask(void);
static void Task_DuckBGMForPokemonCry(u8 taskId);
static void RestoreBGMVolumeAfterPokemonCry(void);

static const struct Fanfare sFanfares[] = {
    [FANFARE_LEVEL_UP]                = { MUS_LEVEL_UP,               80 },
    [FANFARE_HEAL]                    = { MUS_HEAL,                  160 },
    [FANFARE_OBTAIN_BADGE]            = { MUS_OBTAIN_BADGE,          340 },
    [FANFARE_OBTAIN_ITEM]             = { MUS_OBTAIN_ITEM,           160 },
    [FANFARE_EVOLVED]                 = { MUS_EVOLVED,               220 },
    [FANFARE_OBTAIN_TMHM]             = { MUS_OBTAIN_TMHM,           220 },
    [FANFARE_EVOLUTION_INTRO]         = { MUS_EVOLUTION_INTRO,        60 },
    [FANFARE_MOVE_DELETED]            = { MUS_MOVE_DELETED,          180 },
    [FANFARE_OBTAIN_BERRY]            = { MUS_OBTAIN_BERRY,          120 },
    [FANFARE_AWAKEN_LEGEND]           = { MUS_AWAKEN_LEGEND,         710 },
    [FANFARE_SLOTS_JACKPOT]           = { MUS_SLOTS_JACKPOT,         250 },
    [FANFARE_SLOTS_WIN]               = { MUS_SLOTS_WIN,             150 },
    [FANFARE_TOO_BAD]                 = { MUS_TOO_BAD,               160 },
    [FANFARE_RG_JIGGLYPUFF]           = { MUS_RG_JIGGLYPUFF,         400 },
    [FANFARE_RG_DEX_RATING]           = { MUS_RG_DEX_RATING,         196 },
    [FANFARE_RG_OBTAIN_KEY_ITEM]      = { MUS_RG_OBTAIN_KEY_ITEM,    170 },
    [FANFARE_RG_CAUGHT_INTRO]         = { MUS_RG_CAUGHT_INTRO,       231 },
    [FANFARE_RG_PHOTO]                = { MUS_RG_PHOTO,               75 },
    [FANFARE_RG_POKE_FLUTE]           = { MUS_RG_POKE_FLUTE,         450 },
    [FANFARE_OBTAIN_B_POINTS]         = { MUS_OBTAIN_B_POINTS,       313 },
    [FANFARE_REGISTER_MATCH_CALL]     = { MUS_REGISTER_MATCH_CALL,   135 },
    [FANFARE_OBTAIN_SYMBOL]           = { MUS_OBTAIN_SYMBOL,         318 },
    [FANFARE_DP_TV_END]               = { DP_SEQ_TV_END,             244 },
    [FANFARE_DP_OBTAIN_ITEM]          = { DP_SEQ_FANFA4,             160 },
    [FANFARE_DP_HEAL]                 = { DP_SEQ_ASA,                160 },
    [FANFARE_DP_OBTAIN_KEY_ITEM]      = { DP_SEQ_FANFA3,             170 },
    [FANFARE_DP_OBTAIN_TMHM]          = { DP_SEQ_WAZA,               220 },
    [FANFARE_DP_OBTAIN_BADGE]         = { DP_SEQ_BADGE,              340 },
    [FANFARE_DP_LEVEL_UP]             = { DP_SEQ_FANFA1,              80 },
    [FANFARE_DP_OBTAIN_BERRY]         = { DP_SEQ_KINOMI,             120 },
    [FANFARE_DP_PARTNER]              = { DP_SEQ_GONIN,              180 },
    [FANFARE_DP_EVOLVED]              = { DP_SEQ_FANFA5,             252 },
    [FANFARE_DP_POKETCH]              = { DP_SEQ_POCKETCH,           120 },
    [FANFARE_DP_MOVE_DELETED]         = { DP_SEQ_WASURE,             180 },
    [FANFARE_DP_ACCESSORY]            = { DP_SEQ_ACCE,               160 },
    [FANFARE_PL_TV_END]               = { PL_SEQ_TV_END,             230 },
    [FANFARE_PL_CLEAR_MINIGAME]       = { PL_SEQ_PL_WINMINI2,        230 },
    [FANFARE_PL_OBTAIN_ARCADE_POINTS] = { PL_SEQ_PL_DON2,            175 },
    [FANFARE_PL_OBTAIN_CASTLE_POINTS] = { PL_SEQ_PL_FRO,             200 },
    [FANFARE_PL_OBTAIN_B_POINTS]      = { PL_SEQ_PL_POINTGET3,       264 },
    [FANFARE_HG_OBTAIN_KEY_ITEM]      = { HG_SEQ_ME_KEYITEM,         170 },
    [FANFARE_HG_LEVEL_UP]             = { HG_SEQ_ME_LVUP,             80 },
    [FANFARE_HG_HEAL]                 = { HG_SEQ_ME_ASA,             160 },
    [FANFARE_HG_DEX_RATING_1]         = { HG_SEQ_ME_HYOUKA1,         200 },
    [FANFARE_HG_DEX_RATING_2]         = { HG_SEQ_ME_HYOUKA2,         180 },
    [FANFARE_HG_DEX_RATING_3]         = { HG_SEQ_ME_HYOUKA3,         220 },
    [FANFARE_HG_DEX_RATING_4]         = { HG_SEQ_ME_HYOUKA4,         210 },
    [FANFARE_HG_DEX_RATING_5]         = { HG_SEQ_ME_HYOUKA5,         210 },
    [FANFARE_HG_DEX_RATING_6]         = { HG_SEQ_ME_HYOUKA6,         370 },
    [FANFARE_HG_RECEIVE_EGG]          = { HG_SEQ_ME_TAMAGO_GET,      155 },
    [FANFARE_HG_OBTAIN_ITEM]          = { HG_SEQ_ME_ITEM,            160 },
    [FANFARE_HG_EVOLVED]              = { HG_SEQ_ME_SHINKAOME,       240 },
    [FANFARE_HG_OBTAIN_BADGE]         = { HG_SEQ_ME_BADGE,           340 },
    [FANFARE_HG_OBTAIN_TMHM]          = { HG_SEQ_ME_WAZA,            220 },
    [FANFARE_HG_VOLTORB_FLIP_1]       = { HG_SEQ_ME_CARDGAME1,       195 },
    [FANFARE_HG_VOLTORB_FLIP_2]       = { HG_SEQ_ME_CARDGAME2,       240 },
    [FANFARE_HG_ACCESSORY]            = { HG_SEQ_ME_ACCE,            160 },
    [FANFARE_HG_REGISTER_POKEGEAR]    = { HG_SEQ_ME_POKEGEAR_REGIST, 185 },
    [FANFARE_HG_OBTAIN_BERRY]         = { HG_SEQ_ME_KINOMI,          120 },
    [FANFARE_HG_RECEIVE_POKEMON]      = { HG_SEQ_ME_PT_SPECIAL,      150 },
    [FANFARE_HG_MOVE_DELETED]         = { HG_SEQ_ME_WASURE,          180 },
    [FANFARE_HG_THIRD_PLACE]          = { HG_SEQ_ME_MUSHITORI3,      130 },
    [FANFARE_HG_SECOND_PLACE]         = { HG_SEQ_ME_MUSHITORI2,      225 },
    [FANFARE_HG_FIRST_PLACE]          = { HG_SEQ_ME_MUSHITORI1,      250 },
    [FANFARE_HG_POKEATHLON_NEW]       = { HG_SEQ_ME_PT_NEW,          110 },
    [FANFARE_HG_WINNING_POKEATHLON]   = { HG_SEQ_ME_PT_RESULTG,      144 },
    [FANFARE_HG_OBTAIN_B_POINTS]      = { HG_SEQ_ME_BPGET,           264 },
    [FANFARE_HG_OBTAIN_ARCADE_POINTS] = { HG_SEQ_ME_ROULETTE,        175 },
    [FANFARE_HG_OBTAIN_CASTLE_POINTS] = { HG_SEQ_ME_CASTLE,          200 },
    [FANFARE_HG_CLEAR_MINIGAME]       = { HG_SEQ_ME_MINIGAME,        230 },
    [FANFARE_HG_PARTNER]              = { HG_SEQ_ME_GONIN,           180 },
};

#define CRY_VOLUME  120 // was 125 in R/S

void InitMapMusic(void)
{
    //gDisableMusic = (gSaveBlock2Ptr->optionsSound == 2);
	if(gSaveBlock2Ptr->optionsSound == 2)
	gSaveBlock2Ptr->optionsSound = OPTIONS_SOUND_STEREO;
    ResetMapMusic();
}

void MapMusicMain(void)
{
    switch (sMapMusicState)
    {
    case 0:
        break;
    case 1:
        sMapMusicState = 2;
        PlayBGM(sCurrentMapMusic);
        break;
    case 2:
    case 3:
    case 4:
        break;
    case 5:
        if (IsBGMStopped())
        {
            sNextMapMusic = 0;
            sMapMusicState = 0;
        }
        break;
    case 6:
        if (IsBGMStopped() && IsFanfareTaskInactive())
        {
            sCurrentMapMusic = sNextMapMusic;
            sNextMapMusic = 0;
            sMapMusicState = 2;
            PlayBGM(sCurrentMapMusic);
        }
        break;
    case 7:
        if (IsBGMStopped() && IsFanfareTaskInactive())
        {
            FadeInNewBGM(sNextMapMusic, sMapMusicFadeInSpeed);
            sCurrentMapMusic = sNextMapMusic;
            sNextMapMusic = 0;
            sMapMusicState = 2;
            sMapMusicFadeInSpeed = 0;
        }
        break;
    }
}

void ResetMapMusic(void)
{
    sCurrentMapMusic = 0;
    sNextMapMusic = 0;
    sMapMusicState = 0;
    sMapMusicFadeInSpeed = 0;
}

u16 GetCurrentMapMusic(void)
{
	//if(sCurrentMapMusic >= 350 && sCurrentMapMusic <= 427)
	//return sCurrentMapMusic - 29;
	//else
	return sCurrentMapMusic;	
}

void PlayNewMapMusic(u16 songNum)
{
	sCurrentMapMusic = songNum;
    sNextMapMusic = 0;
    sMapMusicState = 1;
}

void StopMapMusic(void)
{
    sCurrentMapMusic = 0;
    sNextMapMusic = 0;
    sMapMusicState = 1;
}

void FadeOutMapMusic(u8 speed)
{
    if (IsNotWaitingForBGMStop())
        FadeOutBGM(speed);
    sCurrentMapMusic = 0;
    sNextMapMusic = 0;
    sMapMusicState = 5;
}

void FadeOutAndPlayNewMapMusic(u16 songNum, u8 speed)
{
    FadeOutMapMusic(speed);
    sCurrentMapMusic = 0;
    sNextMapMusic = songNum;
    sMapMusicState = 6;
}

void FadeOutAndFadeInNewMapMusic(u16 songNum, u8 fadeOutSpeed, u8 fadeInSpeed)
{
    FadeOutMapMusic(fadeOutSpeed);
    sCurrentMapMusic = 0;
    sNextMapMusic = songNum;
    sMapMusicState = 7;
    sMapMusicFadeInSpeed = fadeInSpeed;
}

void FadeInNewMapMusic(u16 songNum, u8 speed)
{
    FadeInNewBGM(songNum, speed);
    sCurrentMapMusic = songNum;
    sNextMapMusic = 0;
    sMapMusicState = 2;
    sMapMusicFadeInSpeed = 0;
}

bool8 IsNotWaitingForBGMStop(void)
{
    if (sMapMusicState == 6)
        return FALSE;
    if (sMapMusicState == 5)
        return FALSE;
    if (sMapMusicState == 7)
        return FALSE;
    return TRUE;
}

void PlayFanfareByFanfareNum(u8 fanfareNum)
{
    u16 songNum;
    m4aMPlayStop(&gMPlayInfo_BGM);
    songNum = RegionalMusicHandler(sFanfares[fanfareNum].songNum);
    sFanfareCounter = RegionalMusicHandler(sFanfares[fanfareNum].duration);
    m4aSongNumStart(songNum);
}

bool8 WaitFanfare(bool8 stop)
{
    if (sFanfareCounter)
    {
        sFanfareCounter--;
        return FALSE;
    }
    else
    {
        if (!stop)
            m4aMPlayContinue(&gMPlayInfo_BGM);
        else
            m4aSongNumStart(MUS_DUMMY);

        return TRUE;
    }
}

void StopFanfareByFanfareNum(u8 fanfareNum)
{
    m4aSongNumStop(sFanfares[fanfareNum].songNum);
}

void PlayFanfare(u16 songNum)
{
    s32 i;
    for (i = 0; (u32)i < 18; i++)
    {
        if (sFanfares[i].songNum == songNum)
        {
            PlayFanfareByFanfareNum(i);
            CreateFanfareTask();
            return;
        }
    }

    PlayFanfareByFanfareNum(0);
    CreateFanfareTask();
}

bool8 IsFanfareTaskInactive(void)
{
    if (FuncIsActiveTask(Task_Fanfare) == TRUE)
        return FALSE;
    return TRUE;
}

static void Task_Fanfare(u8 taskId)
{
    if (sFanfareCounter)
    {
        sFanfareCounter--;
    }
    else
    {
        m4aMPlayContinue(&gMPlayInfo_BGM);
        DestroyTask(taskId);
    }
}

static void CreateFanfareTask(void)
{
    if (FuncIsActiveTask(Task_Fanfare) != TRUE)
        CreateTask(Task_Fanfare, 80);
}

void FadeInNewBGM(u16 songNum, u8 speed)
{
    if (gDisableMusic)
        return;
    if (songNum == MUS_NONE)
        songNum = 0;
    m4aSongNumStart(songNum);
    m4aMPlayImmInit(&gMPlayInfo_BGM);
    m4aMPlayVolumeControl(&gMPlayInfo_BGM, 0xFFFF, 0);
    m4aSongNumStop(songNum);
    m4aMPlayFadeIn(&gMPlayInfo_BGM, speed);
}

void FadeOutBGMTemporarily(u8 speed)
{
    m4aMPlayFadeOutTemporarily(&gMPlayInfo_BGM, speed);
}

bool8 IsBGMPausedOrStopped(void)
{
    if (gMPlayInfo_BGM.status & MUSICPLAYER_STATUS_PAUSE)
        return TRUE;
    if (!(gMPlayInfo_BGM.status & MUSICPLAYER_STATUS_TRACK))
        return TRUE;
    return FALSE;
}

void FadeInBGM(u8 speed)
{
    m4aMPlayFadeIn(&gMPlayInfo_BGM, speed);
}

void FadeOutBGM(u8 speed)
{
    m4aMPlayFadeOut(&gMPlayInfo_BGM, speed);
}

bool8 IsBGMStopped(void)
{
    if (!(gMPlayInfo_BGM.status & MUSICPLAYER_STATUS_TRACK))
        return TRUE;
    return FALSE;
}

void PlayCry1(u16 species, s8 pan)
{
    if (gDisableMusic)
        return;
    m4aMPlayVolumeControl(&gMPlayInfo_BGM, 0xFFFF, 85);
    PlayCryInternal(species, pan, CRY_VOLUME, 10, 0);
    gPokemonCryBGMDuckingCounter = 2;
    RestoreBGMVolumeAfterPokemonCry();
}

void PlayCry2(u16 species, s8 pan, s8 volume, u8 priority)
{
    if (gDisableMusic)
        return;
    PlayCryInternal(species, pan, volume, priority, 0);
}

void PlayCry3(u16 species, s8 pan, u8 mode)
{
    if (gDisableMusic)
        return;
    if (mode == 1)
    {
        PlayCryInternal(species, pan, CRY_VOLUME, 10, 1);
    }
    else
    {
        m4aMPlayVolumeControl(&gMPlayInfo_BGM, 0xFFFF, 85);
        PlayCryInternal(species, pan, CRY_VOLUME, 10, mode);
        gPokemonCryBGMDuckingCounter = 2;
        RestoreBGMVolumeAfterPokemonCry();
    }
}

void PlayCry4(u16 species, s8 pan, u8 mode)
{
    if (gDisableMusic)
        return;
    if (mode == 1)
    {
        PlayCryInternal(species, pan, CRY_VOLUME, 10, 1);
    }
    else
    {
        if (!(gBattleTypeFlags & BATTLE_TYPE_MULTI))
            m4aMPlayVolumeControl(&gMPlayInfo_BGM, 0xFFFF, 85);
        PlayCryInternal(species, pan, CRY_VOLUME, 10, mode);
    }
}

void PlayCry6(u16 species, s8 pan, u8 mode) // not present in R/S
{
    if (gDisableMusic)
        return;
    if (mode == 1)
    {
        PlayCryInternal(species, pan, CRY_VOLUME, 10, 1);
    }
    else
    {
        m4aMPlayVolumeControl(&gMPlayInfo_BGM, 0xFFFF, 85);
        PlayCryInternal(species, pan, CRY_VOLUME, 10, mode);
        gPokemonCryBGMDuckingCounter = 2;
    }
}

void PlayCry5(u16 species, u8 mode)
{
    if (gDisableMusic)
        return;
    m4aMPlayVolumeControl(&gMPlayInfo_BGM, 0xFFFF, 85);
    PlayCryInternal(species, 0, CRY_VOLUME, 10, mode);
    gPokemonCryBGMDuckingCounter = 2;
    RestoreBGMVolumeAfterPokemonCry();
}

enum{
    CRY_GENERIC,
    CRY_KYOGRE,
    CRY_GROUDON,
    CRY_RAYQUAZA,
    CRY_MANAPHY,
    CRY_HOOPA,
    CRY_PIKACHU,
    CRY_ROTOM,
    CRY_FLABEBE,
    CRY_EGG_GROUP_WATER_1,
    CRY_EGG_GROUP_WATER_2,
    CRY_EGG_GROUP_WATER_3,
    CRY_EGG_GROUP_DRAGON,
    CRY_EGG_GROUP_FLYING,
    CRY_EGG_GROUP_MONSTER,
    CRY_EGG_GROUP_GRASS,
    CRY_EGG_GROUP_BUG,
    CRY_EGG_GROUP_MINERAL,
    CRY_EGG_GROUP_FIELD,
    CRY_EGG_GROUP_HUMAN_LIKE,
    CRY_EGG_GROUP_AMORPHOUS,
    CRY_EGG_GROUP_FAIRY,
    CRY_EGG_GROUP_DITTO,
};

void PlayCryInternal(u16 species, s8 pan, s8 volume, u8 priority, u8 mode)
{
    u16 baseSpecies;
    bool32 v0;
    u32 release;
    u32 length;
    u32 pitch;
    u32 chorus;

    length = 140;
    v0 = FALSE;
    release = 0;
    pitch = 15360;
    chorus = 0;

    switch (mode)
    {
    case 0:
        break;
    case 1:
        length = 20;
        release = 225;
        break;
    case 2:
        release = 225;
        pitch = 15600;
        chorus = 20;
        volume = 90;
        break;
    case 3:
        length = 50;
        release = 200;
        pitch = 15800;
        chorus = 20;
        volume = 90;
        break;
    case 4:
        length = 25;
        v0 = TRUE;
        release = 100;
        pitch = 15600;
        chorus = 192;
        volume = 90;
        break;
    case 5:
        release = 200;
        pitch = 14440;
        break;
    case 6:
        release = 220;
        pitch = 15555;
        chorus = 192;
        volume = 70;
        break;
    case 7:
        length = 10;
        release = 100;
        pitch = 14848;
        break;
    case 8:
        length = 60;
        release = 225;
        pitch = 15616;
        break;
    case 9:
        length = 15;
        v0 = TRUE;
        release = 125;
        pitch = 15200;
        break;
    case 10:
        length = 100;
        release = 225;
        pitch = 15200;
        break;
    case 12:
        length = 20;
        release = 225;
    case 11:
        pitch = 15000;
        break;
    }

    SetPokemonCryVolume(volume);
    SetPokemonCryPanpot(pan);
    SetPokemonCryPitch(pitch);
    SetPokemonCryLength(length);
    SetPokemonCryProgress(0);
    SetPokemonCryRelease(release);
    SetPokemonCryChorus(chorus);
    SetPokemonCryPriority(priority);

    species--;
	#ifdef POKEMON_CRIES
		gMPlay_PokemonCry = SetPokemonCryTone(v0 ? &gCryTable2[species] : &gCryTable[species]);
	#else
		species++;
        baseSpecies = GetBaseFormSpeciesId(species);
        switch(VarGet(VAR_CRY_SPECIES)){
            case CRY_TYPE_NORMAL:
                mgba_printf(MGBA_LOG_WARN, "PlayCry:%d", baseSpecies);
            break;
            case CRY_TYPE_ANIME:
                mgba_printf(MGBA_LOG_WARN, "PlayAnimeCry:%d", baseSpecies);
                break;
            case CRY_TYPE_GENERIC:
                PlayGenericCry(baseSpecies, v0);
            break;
        }
    #endif
}

void PlayGenericCry(u16 species, bool32 v0){
    switch(species){
        case SPECIES_KYOGRE:
            gMPlay_PokemonCry = SetPokemonCryTone(v0 ? &gCryTable2[CRY_KYOGRE] : &gCryTable[CRY_KYOGRE]);
        break;
        case SPECIES_GROUDON:
            gMPlay_PokemonCry = SetPokemonCryTone(v0 ? &gCryTable2[CRY_GROUDON] : &gCryTable[CRY_GROUDON]);
        break;
        case SPECIES_RAYQUAZA:
            gMPlay_PokemonCry = SetPokemonCryTone(v0 ? &gCryTable2[CRY_RAYQUAZA] : &gCryTable[CRY_RAYQUAZA]);
        break;
        case SPECIES_MANAPHY:
        case SPECIES_PHIONE:
            gMPlay_PokemonCry = SetPokemonCryTone(v0 ? &gCryTable2[CRY_MANAPHY] : &gCryTable[CRY_MANAPHY]);
        break;
        case SPECIES_HOOPA:
        case SPECIES_HOOPA_UNBOUND:
            gMPlay_PokemonCry = SetPokemonCryTone(v0 ? &gCryTable2[CRY_HOOPA] : &gCryTable[CRY_HOOPA]);
        break;
        case SPECIES_SWABLU:
            gMPlay_PokemonCry = SetPokemonCryTone(v0 ? &gCryTable2[CRY_EGG_GROUP_FLYING] : &gCryTable[CRY_EGG_GROUP_FLYING]);
        break;
        case SPECIES_PICHU_SPIKY_EARED:
        case SPECIES_PICHU:
        case SPECIES_PIKACHU:
        case SPECIES_RAICHU:
        case SPECIES_RAICHU_ALOLAN:
        case SPECIES_MINUN:
        case SPECIES_PLUSLE:
        case SPECIES_PACHIRISU:
        case SPECIES_EMOLGA:
        case SPECIES_TOGEDEMARU:
        case SPECIES_DEDENNE:
        case SPECIES_MORPEKO:
        case SPECIES_MORPEKO_HANGRY:
            gMPlay_PokemonCry = SetPokemonCryTone(v0 ? &gCryTable2[CRY_PIKACHU] : &gCryTable[CRY_PIKACHU]);
        break;
        case SPECIES_ROTOM:
        case SPECIES_ROTOM_WASH:
        case SPECIES_ROTOM_MOW:
        case SPECIES_ROTOM_FROST:
        case SPECIES_ROTOM_HEAT:
        case SPECIES_ROTOM_FAN:
            gMPlay_PokemonCry = SetPokemonCryTone(v0 ? &gCryTable2[CRY_ROTOM] : &gCryTable[CRY_ROTOM]);
        break;
        case SPECIES_DITTO:
            gMPlay_PokemonCry = SetPokemonCryTone(v0 ? &gCryTable2[CRY_EGG_GROUP_DITTO] : &gCryTable[CRY_EGG_GROUP_DITTO]);
        break;
        case SPECIES_MEW:
        case SPECIES_CELEBI:
        case SPECIES_JIRACHI:
        case SPECIES_VICTINI:
        case SPECIES_DIANCIE:
        case SPECIES_FLABEBE:
        case SPECIES_FLABEBE_BLUE_FLOWER:
        case SPECIES_FLABEBE_ORANGE_FLOWER:
        case SPECIES_FLABEBE_WHITE_FLOWER:
        case SPECIES_FLABEBE_YELLOW_FLOWER:
        case SPECIES_FLOETTE:
        case SPECIES_FLOETTE_BLUE_FLOWER:
        case SPECIES_FLOETTE_ORANGE_FLOWER:
        case SPECIES_FLOETTE_WHITE_FLOWER:
        case SPECIES_FLOETTE_YELLOW_FLOWER:
        case SPECIES_FLOETTE_ETERNAL_FLOWER:
        case SPECIES_FLORGES:
        case SPECIES_FLORGES_BLUE_FLOWER:
        case SPECIES_FLORGES_ORANGE_FLOWER:
        case SPECIES_FLORGES_WHITE_FLOWER:
        case SPECIES_FLORGES_YELLOW_FLOWER:
            gMPlay_PokemonCry = SetPokemonCryTone(v0 ? &gCryTable2[CRY_FLABEBE] : &gCryTable[CRY_FLABEBE]);
        break;
        default:
            if(gBaseStats[species].eggGroup2 == EGG_GROUP_WATER_1)
                gMPlay_PokemonCry = SetPokemonCryTone(v0 ? &gCryTable2[CRY_EGG_GROUP_WATER_1] : &gCryTable[CRY_EGG_GROUP_WATER_1]);
            else if(gBaseStats[species].eggGroup2 == EGG_GROUP_WATER_2)
                gMPlay_PokemonCry = SetPokemonCryTone(v0 ? &gCryTable2[CRY_EGG_GROUP_WATER_2] : &gCryTable[CRY_EGG_GROUP_WATER_2]);
            else if(gBaseStats[species].eggGroup2 == EGG_GROUP_WATER_2)
                gMPlay_PokemonCry = SetPokemonCryTone(v0 ? &gCryTable2[CRY_EGG_GROUP_WATER_3] : &gCryTable[CRY_EGG_GROUP_WATER_3]);
            else if(gBaseStats[species].eggGroup2 == EGG_GROUP_DRAGON)
                gMPlay_PokemonCry = SetPokemonCryTone(v0 ? &gCryTable2[CRY_EGG_GROUP_DRAGON] : &gCryTable[CRY_EGG_GROUP_DRAGON]);
            else if(gBaseStats[species].eggGroup2 == EGG_GROUP_FLYING)
                gMPlay_PokemonCry = SetPokemonCryTone(v0 ? &gCryTable2[CRY_EGG_GROUP_FLYING] : &gCryTable[CRY_EGG_GROUP_FLYING]);
            else if(gBaseStats[species].eggGroup2 == EGG_GROUP_MONSTER)
                gMPlay_PokemonCry = SetPokemonCryTone(v0 ? &gCryTable2[CRY_EGG_GROUP_MONSTER] : &gCryTable[CRY_EGG_GROUP_MONSTER]);
            else if(gBaseStats[species].eggGroup1 == EGG_GROUP_GRASS)
                gMPlay_PokemonCry = SetPokemonCryTone(v0 ? &gCryTable2[CRY_EGG_GROUP_GRASS] : &gCryTable[CRY_EGG_GROUP_GRASS]);
            else if(gBaseStats[species].eggGroup2 == EGG_GROUP_BUG || gBaseStats[species].eggGroup1 == EGG_GROUP_BUG)
                gMPlay_PokemonCry = SetPokemonCryTone(v0 ? &gCryTable2[CRY_EGG_GROUP_BUG] : &gCryTable[CRY_EGG_GROUP_BUG]);
            else if(gBaseStats[species].eggGroup2 == EGG_GROUP_MINERAL)
                gMPlay_PokemonCry = SetPokemonCryTone(v0 ? &gCryTable2[CRY_EGG_GROUP_MINERAL] : &gCryTable[CRY_EGG_GROUP_MINERAL]);
            else if(gBaseStats[species].eggGroup2 == EGG_GROUP_FIELD || gBaseStats[species].eggGroup1 == EGG_GROUP_FIELD)
                gMPlay_PokemonCry = SetPokemonCryTone(v0 ? &gCryTable2[CRY_EGG_GROUP_FIELD] : &gCryTable[CRY_EGG_GROUP_FIELD]);
            else if(gBaseStats[species].eggGroup2 == EGG_GROUP_HUMAN_LIKE)
                gMPlay_PokemonCry = SetPokemonCryTone(v0 ? &gCryTable2[CRY_EGG_GROUP_HUMAN_LIKE] : &gCryTable[CRY_EGG_GROUP_HUMAN_LIKE]);
            else if(gBaseStats[species].eggGroup2 == EGG_GROUP_AMORPHOUS)
                gMPlay_PokemonCry = SetPokemonCryTone(v0 ? &gCryTable2[CRY_EGG_GROUP_AMORPHOUS] : &gCryTable[CRY_EGG_GROUP_AMORPHOUS]);
            else if(gBaseStats[species].eggGroup2 == EGG_GROUP_FAIRY)
                gMPlay_PokemonCry = SetPokemonCryTone(v0 ? &gCryTable2[CRY_EGG_GROUP_FAIRY] : &gCryTable[CRY_EGG_GROUP_FAIRY]);
            else if(gBaseStats[species].eggGroup2 == EGG_GROUP_DITTO)
                gMPlay_PokemonCry = SetPokemonCryTone(v0 ? &gCryTable2[CRY_EGG_GROUP_DITTO] : &gCryTable[CRY_EGG_GROUP_DITTO]);
            else if(gBaseStats[species].eggGroup2 == EGG_GROUP_GRASS)
                gMPlay_PokemonCry = SetPokemonCryTone(v0 ? &gCryTable2[CRY_EGG_GROUP_GRASS] : &gCryTable[CRY_EGG_GROUP_GRASS]);
            else
                gMPlay_PokemonCry = SetPokemonCryTone(v0 ? &gCryTable2[CRY_GENERIC] : &gCryTable[CRY_GENERIC]);
            break;
        }
}

bool8 IsCryFinished(void)
{
    if (FuncIsActiveTask(Task_DuckBGMForPokemonCry) == TRUE)
    {
        return FALSE;
    }
    else
    {
        ClearPokemonCrySongs();
        return TRUE;
    }
}

void StopCryAndClearCrySongs(void)
{
    m4aMPlayStop(gMPlay_PokemonCry);
    ClearPokemonCrySongs();
}

void StopCry(void)
{
    m4aMPlayStop(gMPlay_PokemonCry);
}

bool8 IsCryPlayingOrClearCrySongs(void)
{
    if (IsPokemonCryPlaying(gMPlay_PokemonCry))
    {
        return TRUE;
    }
    else
    {
        ClearPokemonCrySongs();
        return FALSE;
    }
}

bool8 IsCryPlaying(void)
{
    if (IsPokemonCryPlaying(gMPlay_PokemonCry))
        return TRUE;
    else
        return FALSE;
}

static void Task_DuckBGMForPokemonCry(u8 taskId)
{
    if (gPokemonCryBGMDuckingCounter)
    {
        gPokemonCryBGMDuckingCounter--;
        return;
    }

    if (!IsPokemonCryPlaying(gMPlay_PokemonCry))
    {
        m4aMPlayVolumeControl(&gMPlayInfo_BGM, 0xFFFF, 256);
        DestroyTask(taskId);
    }
}

static void RestoreBGMVolumeAfterPokemonCry(void)
{
    if (FuncIsActiveTask(Task_DuckBGMForPokemonCry) != TRUE)
        CreateTask(Task_DuckBGMForPokemonCry, 80);
}

void PlayBGM(u16 songNum)
{
    u16 song;
	//if(songNum >= 350 && songNum <= 427)
	//song = RegionalMusicHandler(songNum - 29);
	//else
	song = RegionalMusicHandler(songNum);	
	if (gDisableMusic)
        songNum = 0;
    if (songNum == MUS_NONE)
        songNum = 0;
    m4aSongNumStart(song);
}

u16 RegionalMusicHandler(u16 songNum)
{
	bool8 music_enabled = FALSE;
	bool8 Gen4 = FALSE;
	switch(songNum)
	{
	case MUS_TITLE:
		if (gSaveBlock2Ptr->optionsDifficulty == OPTIONS_MUSIC_KANTO && music_enabled)
			return MUS_RG_TITLE;
		else if (gSaveBlock2Ptr->optionsDifficulty == OPTIONS_MUSIC_JOTHO && music_enabled)
			return HG_SEQ_GS_POKEMON_THEME;
		else if(gSaveBlock2Ptr->optionsDifficulty == OPTIONS_MUSIC_SINNOH && music_enabled)
			return PL_SEQ_TITLE01;
		else 
			return songNum;
	break;
	case MUS_BIRCH_LAB:
		if (gSaveBlock2Ptr->optionsDifficulty == OPTIONS_MUSIC_KANTO && music_enabled)
			return MUS_RG_OAK_LAB;
		else if (gSaveBlock2Ptr->optionsDifficulty == OPTIONS_MUSIC_JOTHO && music_enabled)
			return DP_SEQ_KENKYUJO;
		else if(gSaveBlock2Ptr->optionsDifficulty == OPTIONS_MUSIC_SINNOH && music_enabled)
			return HG_SEQ_GS_UTSUGI_RABO;
		else 
			return songNum;
	break;
	//Introduction
	case MUS_ROUTE122:
		/*/if (gSaveBlock2Ptr->optionsDifficulty == OPTIONS_MUSIC_KANTO)
			return MUS_RG_SURF;else /*/
		if (gSaveBlock2Ptr->optionsDifficulty == OPTIONS_MUSIC_JOTHO)
			return HG_SEQ_GS_STARTING;
		else if(gSaveBlock2Ptr->optionsDifficulty == OPTIONS_MUSIC_SINNOH)
			return DP_SEQ_OPENING;
		else 
			return songNum;
	break;
	//Route 101
	case MUS_ROUTE101:
		if (gSaveBlock2Ptr->optionsDifficulty == OPTIONS_MUSIC_KANTO && music_enabled)
			return MUS_RG_ROUTE1;
		else if (gSaveBlock2Ptr->optionsDifficulty == OPTIONS_MUSIC_JOTHO && music_enabled)
			return HG_SEQ_GS_R_1_29;
		else if(gSaveBlock2Ptr->optionsDifficulty == OPTIONS_MUSIC_SINNOH && music_enabled)
			return HG_SEQ_GS_RADIO_R_201;
		else 
			return songNum;
	break;
	//Bicycle
	case MUS_CYCLING:
		if (gSaveBlock2Ptr->optionsDifficulty == OPTIONS_MUSIC_KANTO)
			return MUS_RG_CYCLING;
		else if(gSaveBlock2Ptr->optionsDifficulty == OPTIONS_MUSIC_JOTHO)
			return HG_SEQ_PL_BICYCLE;
		else if(gSaveBlock2Ptr->optionsDifficulty == OPTIONS_MUSIC_SINNOH)
			return DP_SEQ_BICYCLE;
		else 
			return songNum;
	break;
	//Surf
	case MUS_SURF:
		if (gSaveBlock2Ptr->optionsDifficulty == OPTIONS_MUSIC_KANTO)
			return MUS_RG_SURF;
		else if(gSaveBlock2Ptr->optionsDifficulty == OPTIONS_MUSIC_JOTHO)
			return HG_SEQ_GS_NAMINORI;
		else if(gSaveBlock2Ptr->optionsDifficulty == OPTIONS_MUSIC_SINNOH)
			return DP_SEQ_NAMINORI;
		else 
			return songNum;
	break;
	//Pokemon Center SFX
	case MUS_HEAL:
		RtcCalcLocalTime();
		if (gSaveBlock2Ptr->optionsDifficulty == OPTIONS_MUSIC_KANTO)
			return MUS_HEAL;
		else if(gSaveBlock2Ptr->optionsDifficulty == OPTIONS_MUSIC_JOTHO)
			return HG_SEQ_ME_ASA;
		else if(gSaveBlock2Ptr->optionsDifficulty == OPTIONS_MUSIC_SINNOH)
			return DP_SEQ_ASA;
		else 
			return songNum;
	break;
	//Pokemon Center
	case MUS_POKE_CENTER:
		RtcCalcLocalTime();
		if (gSaveBlock2Ptr->optionsDifficulty == OPTIONS_MUSIC_KANTO)
			return MUS_RG_POKE_CENTER;
		else if(gSaveBlock2Ptr->optionsDifficulty == OPTIONS_MUSIC_JOTHO)
			return HG_SEQ_GS_POKESEN;
		else if(gSaveBlock2Ptr->optionsDifficulty == OPTIONS_MUSIC_SINNOH && IsCurrentlyDay())
			return DP_SEQ_PC_01;
		else if (gSaveBlock2Ptr->optionsDifficulty == OPTIONS_MUSIC_SINNOH && !IsCurrentlyDay())
			return DP_SEQ_PC_02;
		else 
			return songNum;
	break;
	//Poke Mart
	case MUS_POKE_MART:
		if(gSaveBlock2Ptr->optionsDifficulty == OPTIONS_MUSIC_JOTHO)
			return HG_SEQ_GS_FS;
		else if(gSaveBlock2Ptr->optionsDifficulty == OPTIONS_MUSIC_SINNOH)
			return DP_SEQ_FS;
		else 
			return songNum;
	break;
	//Game Corner
	case MUS_GAME_CORNER:
		if (gSaveBlock2Ptr->optionsDifficulty == OPTIONS_MUSIC_KANTO && !Gen4)
			return MUS_RG_GAME_CORNER;
		else if(gSaveBlock2Ptr->optionsDifficulty == OPTIONS_MUSIC_JOTHO)
			return HG_SEQ_GS_GAME;
		else if(gSaveBlock2Ptr->optionsDifficulty == OPTIONS_MUSIC_SINNOH)
			return DP_SEQ_BLD_GAME;
		else 
			return songNum;
	//Intro
	case MUS_INTRO:
		if (gSaveBlock2Ptr->optionsDifficulty == OPTIONS_MUSIC_KANTO && !Gen4)
			return MUS_INTRO;
		else if(gSaveBlock2Ptr->optionsDifficulty == OPTIONS_MUSIC_JOTHO)
			return HG_SEQ_GS_TITLE;
		else if(gSaveBlock2Ptr->optionsDifficulty == OPTIONS_MUSIC_SINNOH)
			return PL_SEQ_TITLE00;
		else 
			return songNum;
	break;
	//Wild Battle
	case MUS_VS_WILD:
		if (gSaveBlock2Ptr->optionsDifficulty == OPTIONS_MUSIC_KANTO && !Gen4)
			return MUS_RG_VS_WILD;
		else if (gSaveBlock2Ptr->optionsDifficulty == OPTIONS_MUSIC_KANTO && Gen4)
			return HG_SEQ_GS_VS_NORAPOKE_KANTO;
		else if(gSaveBlock2Ptr->optionsDifficulty == OPTIONS_MUSIC_JOTHO)
			return HG_SEQ_GS_VS_NORAPOKE;
		else if(gSaveBlock2Ptr->optionsDifficulty == OPTIONS_MUSIC_SINNOH)
			return DP_SEQ_BA_POKE;
		else 
			return songNum;
	break;
	//Vs Trainer
	case MUS_VS_TRAINER:
	if (gSaveBlock2Ptr->optionsDifficulty == OPTIONS_MUSIC_KANTO && !Gen4)
			return MUS_RG_VS_TRAINER;
		else if (gSaveBlock2Ptr->optionsDifficulty == OPTIONS_MUSIC_KANTO && Gen4)
			return HG_SEQ_GS_VS_TRAINER_KANTO;
		else if(gSaveBlock2Ptr->optionsDifficulty == OPTIONS_MUSIC_JOTHO)
			return HG_SEQ_GS_VS_TRAINER;
		else if(gSaveBlock2Ptr->optionsDifficulty == OPTIONS_MUSIC_SINNOH)
			return DP_SEQ_BA_TRAIN;
		else 
			return songNum;
	break;
	//Vs Frontier Brain
	case MUS_VS_FRONTIER_BRAIN:
		if(gSaveBlock2Ptr->optionsDifficulty == OPTIONS_MUSIC_JOTHO)
			return HG_SEQ_GS_BA_BRAIN;
		else if(gSaveBlock2Ptr->optionsDifficulty == OPTIONS_MUSIC_SINNOH)
			return PL_SEQ_PL_BA_BRAIN;
		else 
			return songNum;
	break;
	//Gym 
	case MUS_GYM:
	if (gSaveBlock2Ptr->optionsDifficulty == OPTIONS_MUSIC_KANTO)
			return MUS_RG_GYM;
		else if(gSaveBlock2Ptr->optionsDifficulty == OPTIONS_MUSIC_JOTHO)
			return HG_SEQ_GS_GYM;
		else if(gSaveBlock2Ptr->optionsDifficulty == OPTIONS_MUSIC_SINNOH)
			return DP_SEQ_GYM;
		else 
			return songNum;
	break;
	//Gym Battle
	case MUS_VS_GYM_LEADER:
	if (gSaveBlock2Ptr->optionsDifficulty == OPTIONS_MUSIC_KANTO)
			return MUS_RG_VS_GYM_LEADER;
		else if(gSaveBlock2Ptr->optionsDifficulty == OPTIONS_MUSIC_JOTHO)
			return HG_SEQ_GS_VS_GYMREADER;
		else if(gSaveBlock2Ptr->optionsDifficulty == OPTIONS_MUSIC_SINNOH)
			return DP_SEQ_BA_GYM;
		else 
			return songNum;
	break;
	//Victory Trainer
	case MUS_VICTORY_TRAINER:
	if(gSaveBlock2Ptr->optionsDifficulty == OPTIONS_MUSIC_JOTHO)
			return HG_SEQ_GS_WIN1;
		else if(gSaveBlock2Ptr->optionsDifficulty == OPTIONS_MUSIC_SINNOH)
			return DP_SEQ_WINTRAIN;
		else 
			return songNum;
	break;
	//Gym Victory
	case MUS_VICTORY_GYM_LEADER:
	if(gSaveBlock2Ptr->optionsDifficulty == OPTIONS_MUSIC_JOTHO)
			return HG_SEQ_GS_WIN3;
		else if(gSaveBlock2Ptr->optionsDifficulty == OPTIONS_MUSIC_SINNOH)
			return DP_SEQ_WINTGYM;
		else 
			return songNum;
	break;
	//Wild Victory
	case MUS_VICTORY_WILD:
	if(gSaveBlock2Ptr->optionsDifficulty == OPTIONS_MUSIC_JOTHO)
			return HG_SEQ_GS_WIN2_NOT_FAN;
		else if(gSaveBlock2Ptr->optionsDifficulty == OPTIONS_MUSIC_SINNOH)
			return DP_SEQ_WINPOKE;
		else 
			return songNum;
	break;
	//Victory Road
	case MUS_VICTORY_ROAD:
	if (gSaveBlock2Ptr->optionsDifficulty == OPTIONS_MUSIC_KANTO)
			return MUS_RG_VICTORY_ROAD;
		else if(gSaveBlock2Ptr->optionsDifficulty == OPTIONS_MUSIC_JOTHO)
			return HG_SEQ_GS_D_CHAMPROAD;
		else if(gSaveBlock2Ptr->optionsDifficulty == OPTIONS_MUSIC_SINNOH)
			return DP_SEQ_D_01;
		else 
			return songNum;
	break;
	//Safari Zone
	case MUS_SAFARI_ZONE:
	if(gSaveBlock2Ptr->optionsDifficulty == OPTIONS_MUSIC_JOTHO)
			return HG_SEQ_GS_SAFARI_HOUSE;
		else if(gSaveBlock2Ptr->optionsDifficulty == OPTIONS_MUSIC_SINNOH)
			return DP_SEQ_D_SAFARI;
		else 
			return songNum;
	break;
	return songNum;
	//Mystery Gift
	case MUS_RG_MYSTERY_GIFT:
		if (gSaveBlock2Ptr->optionsDifficulty == OPTIONS_MUSIC_KANTO)
			return MUS_RG_MYSTERY_GIFT;
		else if (gSaveBlock2Ptr->optionsDifficulty == OPTIONS_MUSIC_JOTHO)
			return HG_SEQ_GS_WIFI_PRESENT;
		else if(gSaveBlock2Ptr->optionsDifficulty == OPTIONS_MUSIC_SINNOH)
			return DP_SEQ_PRESENT;
		else 
			return songNum;
	break;
	//Evolution Start
	case MUS_EVOLUTION:
		if (gSaveBlock2Ptr->optionsDifficulty == OPTIONS_MUSIC_KANTO)
			return MUS_EVOLUTION;
		else if (gSaveBlock2Ptr->optionsDifficulty == OPTIONS_MUSIC_JOTHO)
			return HG_SEQ_GS_SHINKA;
		else if(gSaveBlock2Ptr->optionsDifficulty == OPTIONS_MUSIC_SINNOH)
			return DP_SEQ_SHINKA;
		else 
			return songNum;
	break;
	//Evolution Intro
	case MUS_EVOLUTION_INTRO:
	if (gSaveBlock2Ptr->optionsDifficulty == OPTIONS_MUSIC_KANTO)
			return MUS_EVOLUTION_INTRO;
		else if (gSaveBlock2Ptr->optionsDifficulty == OPTIONS_MUSIC_JOTHO)
			return 0;
		else if(gSaveBlock2Ptr->optionsDifficulty == OPTIONS_MUSIC_SINNOH)
			return 0;
		else 
			return songNum;
	break;
	//Evolution End
	case MUS_EVOLVED:
	if (gSaveBlock2Ptr->optionsDifficulty == OPTIONS_MUSIC_KANTO)
			return songNum;
		else if (gSaveBlock2Ptr->optionsDifficulty == OPTIONS_MUSIC_JOTHO)
			return HG_SEQ_ME_SHINKAOME;
		else if(gSaveBlock2Ptr->optionsDifficulty == OPTIONS_MUSIC_SINNOH)
			return DP_SEQ_FANFA5;
		else 
			return songNum;
	break;
	//Level Up
	case MUS_LEVEL_UP:
	if (gSaveBlock2Ptr->optionsDifficulty == OPTIONS_MUSIC_KANTO)
			return songNum;
		else if (gSaveBlock2Ptr->optionsDifficulty == OPTIONS_MUSIC_JOTHO)
			return HG_SEQ_ME_LVUP;
		else if(gSaveBlock2Ptr->optionsDifficulty == OPTIONS_MUSIC_SINNOH)
			return DP_SEQ_FANFA1;
		else 
			return songNum;
	break;
	//Picked Up an Item
	case MUS_OBTAIN_ITEM:
	if (gSaveBlock2Ptr->optionsDifficulty == OPTIONS_MUSIC_KANTO)
			return songNum;
		else if (gSaveBlock2Ptr->optionsDifficulty == OPTIONS_MUSIC_JOTHO)
			return HG_SEQ_ME_ITEM;
		else if(gSaveBlock2Ptr->optionsDifficulty == OPTIONS_MUSIC_SINNOH)
			return DP_SEQ_FANFA4;
		else 
			return songNum;
	break;
	//Obtained a TM!
	case MUS_OBTAIN_TMHM:
	if (gSaveBlock2Ptr->optionsDifficulty == OPTIONS_MUSIC_KANTO)
			return songNum;
		else if (gSaveBlock2Ptr->optionsDifficulty == OPTIONS_MUSIC_JOTHO)
			return HG_SEQ_ME_WAZA;
		else if(gSaveBlock2Ptr->optionsDifficulty == OPTIONS_MUSIC_SINNOH)
			return DP_SEQ_WAZA;
		else 
			return songNum;
	break;
	/*/Pokemon Caught
	case MUS_CAUGHT:
	if (gSaveBlock2Ptr->optionsDifficulty == OPTIONS_MUSIC_KANTO)
			return MUS_RG_CAUGHT;
		else if (gSaveBlock2Ptr->optionsDifficulty == OPTIONS_MUSIC_JOTHO)
			return DP_SEQ_FANFA5;
		else if(gSaveBlock2Ptr->optionsDifficulty == OPTIONS_MUSIC_SINNOH)
			return DP_SEQ_FANFA5;
		else 
			return songNum;
	break;/*/
	}
	//return DP_SEQ_KENKYUJO;		Rowan DPPt
	//return DP_SEQ_OPENING;		Introducction DPPt
	//return PL_SEQ_PL_BA_BRAIN;	Vs Frontier Brain Platinum
	//return DP_SEQ_BLD_GAME;		Game Corner(DPPt)?
	//return DP_SEQ_BA_AGAKI;	
	//return MUS_CAUGHT;			Pokemon Caught RSE
	//return DP_SEQ_FANFA5;			Pokemon Caught DPPt
	//return MUS_RG_CAUGHT;			Pokemon Caught FRLG
	//return MUS_RG_CAUGHT_INTRO;	Pokemon Caught Intro FRLG
	//return DP_SEQ_FANFA1;			
	//return DP_SEQ_WAZA;			Item Obtained DPPt
	//return MUS_RG_ENCOUNTER_RIVAL 
	//return DP_SEQ_BA_RIVAL;		Vs Barry
	//return DP_SEQ_BADGE;			Badge Obtained DPPt
	//return DP_SEQ_SHINKA;			Evolution DPPt
	//return MUS_EVOLUTION;			Evolution RSE
	//return MUS_EVOLUTION_INTRO;	Evolution Intro RSE
	//return HG_SEQ_GS_VS_CHAMP;	Vs Champion HGSS
	//return DP_SEQ_BA_CHANP;		Vs Champion DP
	//return MUS_VS_CHAMPION				Vs Champion(RSE)
	//return DP_SEQ_D_03;			Ghost Masion(DP)?
	//return MUS_RG_POKE_TOWER;		Pokemon Tower(FRLG)
	//return MUS_MT_PYRE			Mt Pyre
	//return DP_SEQ_D_02;				Eterna Forest
	//return MUS_RG_VIRIDIAN_FOREST;	Viridian Forest
	//return MUS_PETALBURG_WOODS		Petalburg woods
	//return DP_SEQ_FS;				Shops (DP)
	//return MUS_POKE_MART;			Shops (RSE)
	//return MUS_RG_POKE_MART;		Shops (FRLG)
	//return DP_SEQ_D_LAKE;			Lakes DPPt
	//DP_SEQ_ROAD_A_AN;				First Route DPPt?
	//DP_SEQ_ROAD_A_D;				First Route DPPt?
	//DP_SEQ_TOWN01_N;				First City DPPt(this shit is slow like the battles lmao)
	//DP_SEQ_TOWN01_D;				First City DPPt(this shit is slow like the battles lmao)
	//MUS_RG_PALLET;				Pallet Town(FRLG)
	//MUS_RG_CYCLING;				Bike (FRLG)
	//MUS_CYCLING;					Bike (FRLG)
	//MUS_GAME_CORNER				Game Corner(RSE)			
	//MUS_RG_GAME_CORNER			Game Corner(FRLG)
	//MUS_VS_ELITE_FOUR				Elite Four(RSE)
	//MUS_VS_RIVAL					Vs Rival(RSE)
	//MUS_ENCOUNTER_ELITE_FOUR		Elite four overworld
	//MUS_UNDERWATER				Underwater music
	//MUS_BIRCH_LAB					Birch lab
}

void PlaySE(u16 songNum)
{
    if (gDisableMusic)
        return;
    m4aSongNumStart(RegionalMusicHandler(songNum));
}

void PlaySE12WithPanning(u16 songNum, s8 pan)
{
    if (gDisableMusic)
        return;
    m4aSongNumStart(songNum);
    m4aMPlayImmInit(&gMPlayInfo_SE1);
    m4aMPlayImmInit(&gMPlayInfo_SE2);
    m4aMPlayPanpotControl(&gMPlayInfo_SE1, 0xFFFF, pan);
    m4aMPlayPanpotControl(&gMPlayInfo_SE2, 0xFFFF, pan);
}

void PlaySE1WithPanning(u16 songNum, s8 pan)
{
    if (gDisableMusic)
        return;
    m4aSongNumStart(songNum);
    m4aMPlayImmInit(&gMPlayInfo_SE1);
    m4aMPlayPanpotControl(&gMPlayInfo_SE1, 0xFFFF, pan);
}

void PlaySE2WithPanning(u16 songNum, s8 pan)
{
    if (gDisableMusic)
        return;
    m4aSongNumStart(songNum);
    m4aMPlayImmInit(&gMPlayInfo_SE2);
    m4aMPlayPanpotControl(&gMPlayInfo_SE2, 0xFFFF, pan);
}

void SE12PanpotControl(s8 pan)
{
    m4aMPlayPanpotControl(&gMPlayInfo_SE1, 0xFFFF, pan);
    m4aMPlayPanpotControl(&gMPlayInfo_SE2, 0xFFFF, pan);
}

bool8 IsSEPlaying(void)
{
    if ((gMPlayInfo_SE1.status & MUSICPLAYER_STATUS_PAUSE) && (gMPlayInfo_SE2.status & MUSICPLAYER_STATUS_PAUSE))
        return FALSE;
    if (!(gMPlayInfo_SE1.status & MUSICPLAYER_STATUS_TRACK) && !(gMPlayInfo_SE2.status & MUSICPLAYER_STATUS_TRACK))
        return FALSE;
    return TRUE;
}

bool8 IsBGMPlaying(void)
{
    if (gMPlayInfo_BGM.status & MUSICPLAYER_STATUS_PAUSE)
        return FALSE;
    if (!(gMPlayInfo_BGM.status & MUSICPLAYER_STATUS_TRACK))
        return FALSE;
    return TRUE;
}

bool8 IsSpecialSEPlaying(void)
{
    if (gMPlayInfo_SE3.status & MUSICPLAYER_STATUS_PAUSE)
        return FALSE;
    if (!(gMPlayInfo_SE3.status & MUSICPLAYER_STATUS_TRACK))
        return FALSE;
    return TRUE;
}