#ifndef GUARD_DAY_NIGHT_H
#define GUARD_DAY_NIGHT_H

#define PALOVER_LIST_TERM 0xFF

struct PaletteOverride
{
    u8 slot;
    u8 timeOfDay;
    void *palette;
};

extern u16 gPlttBufferPreDN[];
extern struct PaletteOverride *gPaletteOverrides[];

bool8 IsCurrentlyDay(void);
u8 GetCurrentTimeOfDay(void);
u8 GetTimeOfDay(s8 hours);
void LoadCompressedPaletteDayNight(const void *src, u16 offset, u16 size);
void LoadPaletteDayNight(const void *src, u16 offset, u16 size);
void LoadPlayerPaletteDayNight(const void *src, u16 offset, u16 size);//
void LoadOpponentPaletteDayNight(const void *src, u16 offset, u16 size);//
void LoadPlayerTrainerPalette(const void *src, u16 offset, u16 size);//
void CheckClockForImmediateTimeEvents(void);
void ProcessImmediateTimeEvents(void);
void DoLoadSpritePaletteDayNight(const u16 *src, u16 paletteOffset);
void DoLoadPlayerSpritePaletteDayNight(const u16 *src, u16 paletteOffset);
void DoLoadOpponentSpritePaletteDayNight(const u16 *src, u16 paletteOffset);
const u8 *GetDayOfWeekString(u8 dayOfWeek);
const u8 GetTimeOfDayString(void);
bool8 ShouldTintOverworld(void);
void TintPaletteForDayNight(u16 offset, u16 size);
u8 GetTimeOfDayHours(void);
bool8 IsCurrentlyDusk(void);

#endif // GUARD_DAY_NIGHT_H
