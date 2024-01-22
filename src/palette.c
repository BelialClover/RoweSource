#include "global.h"
#include "data.h"
#include "event_data.h"
#include "day_night.h"
#include "palette.h"
#include "util.h"
#include "level_scaling.h"
#include "decompress.h"
#include "gpu_regs.h"
#include "task.h"
#include "constants/rgb.h"
#include "constants/event_objects.h"
#include "mgba.h"

enum
{
    NORMAL_FADE,
    FAST_FADE,
    HARDWARE_FADE,
};

// These are structs for some unused palette system.
// The full functionality of this system is unknown.

struct PaletteStructTemplate
{
    u16 uid;
    u16 *src;
    u16 pst_field_8_0:1;
    u16 pst_field_8_1:9;
    u16 size:5;
    u16 pst_field_9_7:1;
    u8 pst_field_A;
    u8 srcCount:5;
    u8 pst_field_B_5:3;
    u8 pst_field_C;
};

struct PaletteStruct
{
    const struct PaletteStructTemplate *base;
    u32 ps_field_4_0:1;
    u16 ps_field_4_1:1;
    u32 baseDestOffset:9;
    u16 destOffset:10;
    u16 srcIndex:7;
    u8 ps_field_8;
    u8 ps_field_9;
};

static void unused_sub_80A1CDC(struct PaletteStruct *, u32 *);
static void unused_sub_80A1E40(struct PaletteStruct *, u32 *);
static void unused_sub_80A1F00(struct PaletteStruct *);
static u8 GetPaletteNumByUid(u16);
static u8 UpdateNormalPaletteFade(void);
static void BeginFastPaletteFadeInternal(u8);
static u8 UpdateFastPaletteFade(void);
static u8 UpdateHardwarePaletteFade(void);
static void UpdateBlendRegisters(void);
static bool8 IsSoftwarePaletteFadeFinishing(void);
static void Task_BlendPalettesGradually(u8 taskId);

// palette buffers require alignment with agbcc because
// unaligned word reads are issued in BlendPalette otherwise
EWRAM_DATA u16 gPlttBufferPlayer[PLTT_BUFFER_SIZE] = {0};
ALIGNED(4) EWRAM_DATA u16 gPlttBufferUnfaded[PLTT_BUFFER_SIZE] = {0};
ALIGNED(4) EWRAM_DATA u16 gPlttBufferFaded[PLTT_BUFFER_SIZE] = {0};
EWRAM_DATA struct PaletteStruct sPaletteStructs[0x10] = {0};
EWRAM_DATA struct PaletteFadeControl gPaletteFade = {0};
static EWRAM_DATA u32 gFiller_2037FE0 = 0;
static EWRAM_DATA u32 sPlttBufferTransferPending = 0;
EWRAM_DATA u8 gPaletteDecompressionBuffer[PLTT_DECOMP_BUFFER_SIZE] = {0};

static const struct PaletteStructTemplate gDummyPaletteStructTemplate = {
    .uid = 0xFFFF,
    .pst_field_B_5 = 1
};

static const u8 sRoundedDownGrayscaleMap[] = {
     0,  0,  0,  0,  0,
     5,  5,  5,  5,  5,
    11, 11, 11, 11, 11,
    16, 16, 16, 16, 16,
    21, 21, 21, 21, 21,
    27, 27, 27, 27, 27,
    31, 31
};

void LoadCompressedPalette(const u32 *src, u16 offset, u16 size)
{
    LZDecompressWram(src, gPaletteDecompressionBuffer);
	//TintPalette_SepiaTone(gPlttBufferFaded, size);
    CpuCopy16(gPaletteDecompressionBuffer, gPlttBufferUnfaded + offset, size);
    CpuCopy16(gPaletteDecompressionBuffer, gPlttBufferFaded + offset, size);
}

void LoadPalette(const void *src, u16 offset, u16 size)
{
    CpuCopy16(src, gPlttBufferUnfaded + offset, size);
    CpuCopy16(src, gPlttBufferFaded + offset, size);
}

void LoadPlayerPalette(const void *src, u16 offset, u16 size)
{
    CpuCopy16(src, gPlttBufferUnfaded + offset, size);
	TintPaletteForDayNight(offset, size);
    CpuCopy16(src, gPlttBufferFaded + offset, size);
}

void LoadPokemonPalette(u8 r, u8 g, u8 b, const void *src, u16 offset, u16 size)
{
    CpuCopy16(src, gPlttBufferUnfaded + offset, size);
	BlendPokemonPalette(offset, size, 6, RGB(r, g, b));
    CpuCopy16(src, gPlttBufferFaded + offset, size);
}

void FillPalette(u16 value, u16 offset, u16 size)
{
    CpuFill16(value, gPlttBufferUnfaded + offset, size);
    CpuFill16(value, gPlttBufferFaded + offset, size);
}

void TransferPlttBuffer(void)
{
    if (!gPaletteFade.bufferTransferDisabled)
    {
        void *src = gPlttBufferFaded;
        void *dest = (void *)PLTT;
        DmaCopy16(3, src, dest, PLTT_SIZE);
        sPlttBufferTransferPending = 0;
        if (gPaletteFade.mode == HARDWARE_FADE && gPaletteFade.active)
            UpdateBlendRegisters();
    }
}

u8 UpdatePaletteFade(void)
{
    u8 result;
    u8 dummy = 0;

    if (sPlttBufferTransferPending)
        return PALETTE_FADE_STATUS_LOADING;

    if (gPaletteFade.mode == NORMAL_FADE)
        result = UpdateNormalPaletteFade();
    else if (gPaletteFade.mode == FAST_FADE)
        result = UpdateFastPaletteFade();
    else
        result = UpdateHardwarePaletteFade();

    sPlttBufferTransferPending = gPaletteFade.multipurpose1 | dummy;

    return result;
}

void ResetPaletteFade(void)
{
    u8 i;

    for (i = 0; i < 16; i++)
        ResetPaletteStruct(i);

    ResetPaletteFadeControl();
}

void ReadPlttIntoBuffers(void)
{
    u16 i;
    u16 *pltt = (u16 *)PLTT;

    for (i = 0; i < PLTT_SIZE / 2; i++)
    {
        gPlttBufferUnfaded[i] = pltt[i];
        gPlttBufferFaded[i] = pltt[i];
    }
}

bool8 BeginNormalPaletteFade(u32 selectedPalettes, s8 delay, u8 startY, u8 targetY, u16 blendColor)
{
    u8 temp;
    u16 color = blendColor;

    if (gPaletteFade.active)
    {
        return FALSE;
    }
    else
    {
        static const u8 deltaByTransitionSpeed[] = {2, 3, 4, 10};
        gPaletteFade.deltaY = deltaByTransitionSpeed[gSaveBlock2Ptr->optionsTransitionSpeed];

        if (delay < 0)
        {
            gPaletteFade.deltaY += (delay * -1);
            delay = 0;
        }

        gPaletteFade_selectedPalettes = selectedPalettes;
        gPaletteFade.delayCounter = delay;
        gPaletteFade_delay = delay;
        gPaletteFade.y = startY;
        gPaletteFade.targetY = targetY;
        gPaletteFade.blendColor = color;
        gPaletteFade.active = 1;
        gPaletteFade.mode = NORMAL_FADE;

        if (startY < targetY)
            gPaletteFade.yDec = 0;
        else
            gPaletteFade.yDec = 1;

        UpdatePaletteFade();

        temp = gPaletteFade.bufferTransferDisabled;
        gPaletteFade.bufferTransferDisabled = 0;
        CpuCopy32(gPlttBufferFaded, (void *)PLTT, PLTT_SIZE);
        sPlttBufferTransferPending = 0;
        if (gPaletteFade.mode == HARDWARE_FADE && gPaletteFade.active)
            UpdateBlendRegisters();
        gPaletteFade.bufferTransferDisabled = temp;
        return TRUE;
    }
}

bool8 unref_sub_80A1C1C(u32 a1, u8 a2, u8 a3, u8 a4, u16 a5)
{
    ReadPlttIntoBuffers();
    return BeginNormalPaletteFade(a1, a2, a3, a4, a5);
}

void unref_sub_80A1C64(u8 a1, u32 *a2)
{
    u8 i;

    for (i = 0; i < 16; i++)
    {
        struct PaletteStruct *palstruct = &sPaletteStructs[i];
        if (palstruct->ps_field_4_0)
        {
            if (palstruct->base->pst_field_8_0 == a1)
            {
                u8 val1 = palstruct->srcIndex;
                u8 val2 = palstruct->base->srcCount;
                if (val1 == val2)
                {
                    unused_sub_80A1F00(palstruct);
                    if (!palstruct->ps_field_4_0)
                        continue;
                }
                if (palstruct->ps_field_8 == 0)
                    unused_sub_80A1CDC(palstruct, a2);
                else
                    palstruct->ps_field_8--;

                unused_sub_80A1E40(palstruct, a2);
            }
        }
    }
}

static void unused_sub_80A1CDC(struct PaletteStruct *a1, u32 *a2)
{
    s32 srcIndex;
    s32 srcCount;
    u8 i = 0;
    u16 srcOffset = a1->srcIndex * a1->base->size;

    if (!a1->base->pst_field_8_0)
    {
        while (i < a1->base->size)
        {
            gPlttBufferUnfaded[a1->destOffset] = a1->base->src[srcOffset];
            gPlttBufferFaded[a1->destOffset] = a1->base->src[srcOffset];
            i++;
            a1->destOffset++;
            srcOffset++;
        }
    }
    else
    {
        while (i < a1->base->size)
        {
            gPlttBufferFaded[a1->destOffset] = a1->base->src[srcOffset];
            i++;
            a1->destOffset++;
            srcOffset++;
        }
    }

    a1->destOffset = a1->baseDestOffset;
    a1->ps_field_8 = a1->base->pst_field_A;
    a1->srcIndex++;

    srcIndex = a1->srcIndex;
    srcCount = a1->base->srcCount;

    if (srcIndex >= srcCount)
    {
        if (a1->ps_field_9)
            a1->ps_field_9--;
        a1->srcIndex = 0;
    }

    *a2 |= 1 << (a1->baseDestOffset >> 4);
}

static void unused_sub_80A1E40(struct PaletteStruct *a1, u32 *a2)
{
    if (gPaletteFade.active && ((1 << (a1->baseDestOffset >> 4)) & gPaletteFade_selectedPalettes))
    {
        if (!a1->base->pst_field_8_0)
        {
            if (gPaletteFade.delayCounter != gPaletteFade_delay)
            {
                BlendPalette(
                    a1->baseDestOffset,
                    a1->base->size,
                    gPaletteFade.y,
                    gPaletteFade.blendColor);
            }
        }
        else
        {
            if (!gPaletteFade.delayCounter)
            {
                if (a1->ps_field_8 != a1->base->pst_field_A)
                {
                    u32 srcOffset = a1->srcIndex * a1->base->size;
                    u8 i;

                    for (i = 0; i < a1->base->size; i++)
                        gPlttBufferFaded[a1->baseDestOffset + i] = a1->base->src[srcOffset + i];
                }
            }
        }
    }
}

static void unused_sub_80A1F00(struct PaletteStruct *a1)
{
    if (!a1->ps_field_9)
    {
        s32 val = a1->base->pst_field_B_5;

        if (!val)
        {
            a1->srcIndex = 0;
            a1->ps_field_8 = a1->base->pst_field_A;
            a1->ps_field_9 = a1->base->pst_field_C;
            a1->destOffset = a1->baseDestOffset;
        }
        else
        {
            if (val < 0)
                return;
            if (val > 2)
                return;
            ResetPaletteStructByUid(a1->base->uid);
        }
    }
    else
    {
        a1->ps_field_9--;
    }
}

void ResetPaletteStructByUid(u16 a1)
{
    u8 paletteNum = GetPaletteNumByUid(a1);
    if (paletteNum != 16)
        ResetPaletteStruct(paletteNum);
}

void ResetPaletteStruct(u8 paletteNum)
{
    sPaletteStructs[paletteNum].base = &gDummyPaletteStructTemplate;
    sPaletteStructs[paletteNum].ps_field_4_0 = 0;
    sPaletteStructs[paletteNum].baseDestOffset = 0;
    sPaletteStructs[paletteNum].destOffset = 0;
    sPaletteStructs[paletteNum].srcIndex = 0;
    sPaletteStructs[paletteNum].ps_field_4_1 = 0;
    sPaletteStructs[paletteNum].ps_field_8 = 0;
    sPaletteStructs[paletteNum].ps_field_9 = 0;
}

void ResetPaletteFadeControl(void)
{
    gPaletteFade.multipurpose1 = 0;
    gPaletteFade.multipurpose2 = 0;
    gPaletteFade.delayCounter = 0;
    gPaletteFade.y = 0;
    gPaletteFade.targetY = 0;
    gPaletteFade.blendColor = 0;
    gPaletteFade.active = 0;
    gPaletteFade.multipurpose2 = 0; // assign same value twice
    gPaletteFade.yDec = 0;
    gPaletteFade.bufferTransferDisabled = 0;
    gPaletteFade.shouldResetBlendRegisters = 0;
    gPaletteFade.hardwareFadeFinishing = 0;
    gPaletteFade.softwareFadeFinishing = 0;
    gPaletteFade.softwareFadeFinishingCounter = 0;
    gPaletteFade.objPaletteToggle = 0;
    gPaletteFade.deltaY = 2;
}

void unref_sub_80A2048(u16 uid)
{
    u8 paletteNum = GetPaletteNumByUid(uid);
    if (paletteNum != 16)
        sPaletteStructs[paletteNum].ps_field_4_1 = 1;
}

void unref_sub_80A2074(u16 uid)
{
    u8 paletteNum = GetPaletteNumByUid(uid);
    if (paletteNum != 16)
        sPaletteStructs[paletteNum].ps_field_4_1 = 0;
}

static u8 GetPaletteNumByUid(u16 uid)
{
    u8 i;

    for (i = 0; i < 16; i++)
        if (sPaletteStructs[i].base->uid == uid)
            return i;

    return 16;
}

static u8 UpdateNormalPaletteFade(void)
{
    u16 paletteOffset;
    u16 selectedPalettes;

    if (!gPaletteFade.active)
        return PALETTE_FADE_STATUS_DONE;

    if (IsSoftwarePaletteFadeFinishing())
    {
        return gPaletteFade.active ? PALETTE_FADE_STATUS_ACTIVE : PALETTE_FADE_STATUS_DONE;
    }
    else
    {
        if (!gPaletteFade.objPaletteToggle)
        {
            if (gPaletteFade.delayCounter < gPaletteFade_delay)
            {
                gPaletteFade.delayCounter++;
                return 2;
            }
            gPaletteFade.delayCounter = 0;
        }

        paletteOffset = 0;

        if (!gPaletteFade.objPaletteToggle)
        {
            selectedPalettes = gPaletteFade_selectedPalettes;
        }
        else
        {
            selectedPalettes = gPaletteFade_selectedPalettes >> 16;
            paletteOffset = 256;
        }

        while (selectedPalettes)
        {
            if (selectedPalettes & 1)
                BlendPalette(
                    paletteOffset,
                    16,
                    gPaletteFade.y,
                    gPaletteFade.blendColor);
            selectedPalettes >>= 1;
            paletteOffset += 16;
        }

        gPaletteFade.objPaletteToggle ^= 1;

        if (!gPaletteFade.objPaletteToggle)
        {
            if (gPaletteFade.y == gPaletteFade.targetY)
            {
                gPaletteFade_selectedPalettes = 0;
                gPaletteFade.softwareFadeFinishing = 1;
            }
            else
            {
                s8 val;

                if (!gPaletteFade.yDec)
                {
                    val = gPaletteFade.y;
                    val += gPaletteFade.deltaY;
                    if (val > gPaletteFade.targetY)
                        val = gPaletteFade.targetY;
                    gPaletteFade.y = val;
                }
                else
                {
                    val = gPaletteFade.y;
                    val -= gPaletteFade.deltaY;
                    if (val < gPaletteFade.targetY)
                        val = gPaletteFade.targetY;
                    gPaletteFade.y = val;
                }
            }
        }

        // gPaletteFade.active cannot change since the last time it was checked. So this
        // is equivalent to `return PALETTE_FADE_STATUS_ACTIVE;`
        return gPaletteFade.active ? PALETTE_FADE_STATUS_ACTIVE : PALETTE_FADE_STATUS_DONE;
    }
}

void InvertPlttBuffer(u32 selectedPalettes)
{
    u16 paletteOffset = 0;

    while (selectedPalettes)
    {
        if (selectedPalettes & 1)
        {
            u8 i;
            for (i = 0; i < 16; i++)
                gPlttBufferFaded[paletteOffset + i] = ~gPlttBufferFaded[paletteOffset + i];
        }
        selectedPalettes >>= 1;
        paletteOffset += 16;
    }
}

void TintPlttBuffer(u32 selectedPalettes, s8 r, s8 g, s8 b)
{
    u16 paletteOffset = 0;

    while (selectedPalettes)
    {
        if (selectedPalettes & 1)
        {
            u8 i;
            for (i = 0; i < 16; i++)
            {
                struct PlttData *data = (struct PlttData *)&gPlttBufferFaded[paletteOffset + i];
                data->r += r;
                data->g += g;
                data->b += b;
            }
        }
        selectedPalettes >>= 1;
        paletteOffset += 16;
    }
}

void UnfadePlttBuffer(u32 selectedPalettes)
{
    u16 paletteOffset = 0;

    while (selectedPalettes)
    {
        if (selectedPalettes & 1)
        {
            u8 i;
            for (i = 0; i < 16; i++)
                gPlttBufferFaded[paletteOffset + i] = gPlttBufferUnfaded[paletteOffset + i];
        }
        selectedPalettes >>= 1;
        paletteOffset += 16;
    }
}

void BeginFastPaletteFade(u8 submode)
{
    gPaletteFade.deltaY = 2;
    BeginFastPaletteFadeInternal(submode);
}

static void BeginFastPaletteFadeInternal(u8 submode)
{
    gPaletteFade.y = 31;
    gPaletteFade_submode = submode & 0x3F;
    gPaletteFade.active = 1;
    gPaletteFade.mode = FAST_FADE;

    if (submode == FAST_FADE_IN_FROM_BLACK)
        CpuFill16(RGB_BLACK, gPlttBufferFaded, PLTT_SIZE);

    if (submode == FAST_FADE_IN_FROM_WHITE)
        CpuFill16(RGB_WHITE, gPlttBufferFaded, PLTT_SIZE);

    UpdatePaletteFade();
}

static u8 UpdateFastPaletteFade(void)
{
    u16 i;
    u16 paletteOffsetStart;
    u16 paletteOffsetEnd;
    s8 r0;
    s8 g0;
    s8 b0;
    s8 r;
    s8 g;
    s8 b;

    if (!gPaletteFade.active)
        return PALETTE_FADE_STATUS_DONE;

    if (IsSoftwarePaletteFadeFinishing())
        return gPaletteFade.active ? PALETTE_FADE_STATUS_ACTIVE : PALETTE_FADE_STATUS_DONE;
        

    if (gPaletteFade.objPaletteToggle)
    {
        paletteOffsetStart = 256;
        paletteOffsetEnd = 512;
    }
    else
    {
        paletteOffsetStart = 0;
        paletteOffsetEnd = 256;
    }

    switch (gPaletteFade_submode)
    {
    case FAST_FADE_IN_FROM_WHITE:
        for (i = paletteOffsetStart; i < paletteOffsetEnd; i++)
        {
            struct PlttData *unfaded;
            struct PlttData *faded;

            unfaded = (struct PlttData *)&gPlttBufferUnfaded[i];
            r0 = unfaded->r;
            g0 = unfaded->g;
            b0 = unfaded->b;

            faded = (struct PlttData *)&gPlttBufferFaded[i];
            r = faded->r - 2;
            g = faded->g - 2;
            b = faded->b - 2;

            if (r < r0)
                r = r0;
            if (g < g0)
                g = g0;
            if (b < b0)
                b = b0;

            gPlttBufferFaded[i] = r | (g << 5) | (b << 10);
        }
        break;
    case FAST_FADE_OUT_TO_WHITE:
        for (i = paletteOffsetStart; i < paletteOffsetEnd; i++)
        {
            struct PlttData *data = (struct PlttData *)&gPlttBufferFaded[i];
            r = data->r + 2;
            g = data->g + 2;
            b = data->b + 2;

            if (r > 31)
                r = 31;
            if (g > 31)
                g = 31;
            if (b > 31)
                b = 31;

            gPlttBufferFaded[i] = r | (g << 5) | (b << 10);
        }
        break;
    case FAST_FADE_IN_FROM_BLACK:
        for (i = paletteOffsetStart; i < paletteOffsetEnd; i++)
        {
            struct PlttData *unfaded;
            struct PlttData *faded;

            unfaded = (struct PlttData *)&gPlttBufferUnfaded[i];
            r0 = unfaded->r;
            g0 = unfaded->g;
            b0 = unfaded->b;

            faded = (struct PlttData *)&gPlttBufferFaded[i];
            r = faded->r + 2;
            g = faded->g + 2;
            b = faded->b + 2;

            if (r > r0)
                r = r0;
            if (g > g0)
                g = g0;
            if (b > b0)
                b = b0;

            gPlttBufferFaded[i] = r | (g << 5) | (b << 10);
        }
        break;
    case FAST_FADE_OUT_TO_BLACK:
        for (i = paletteOffsetStart; i < paletteOffsetEnd; i++)
        {
            struct PlttData *data = (struct PlttData *)&gPlttBufferFaded[i];
            r = data->r - 2;
            g = data->g - 2;
            b = data->b - 2;

            if (r < 0)
                r = 0;
            if (g < 0)
                g = 0;
            if (b < 0)
                b = 0;

            gPlttBufferFaded[i] = r | (g << 5) | (b << 10);
        }
    }

    gPaletteFade.objPaletteToggle ^= 1;

    if (gPaletteFade.objPaletteToggle)
        // gPaletteFade.active cannot change since the last time it was checked. So this
        // is equivalent to `return PALETTE_FADE_STATUS_ACTIVE;`
        return gPaletteFade.active ? PALETTE_FADE_STATUS_ACTIVE : PALETTE_FADE_STATUS_DONE;

    if (gPaletteFade.y - gPaletteFade.deltaY < 0)
        gPaletteFade.y = 0;
    else
        gPaletteFade.y -= gPaletteFade.deltaY;

    if (gPaletteFade.y == 0)
    {
        switch (gPaletteFade_submode)
        {
        case FAST_FADE_IN_FROM_WHITE:
        case FAST_FADE_IN_FROM_BLACK:
            CpuCopy32(gPlttBufferUnfaded, gPlttBufferFaded, PLTT_SIZE);
            break;
        case FAST_FADE_OUT_TO_WHITE:
            CpuFill32(0xFFFFFFFF, gPlttBufferFaded, PLTT_SIZE);
            break;
        case FAST_FADE_OUT_TO_BLACK:
            CpuFill32(0x00000000, gPlttBufferFaded, PLTT_SIZE);
            break;
        }

        gPaletteFade.mode = NORMAL_FADE;
        gPaletteFade.softwareFadeFinishing = 1;
    }
    
    // gPaletteFade.active cannot change since the last time it was checked. So this
    // is equivalent to `return PALETTE_FADE_STATUS_ACTIVE;`
    return gPaletteFade.active ? PALETTE_FADE_STATUS_ACTIVE : PALETTE_FADE_STATUS_DONE;
}

void BeginHardwarePaletteFade(u8 blendCnt, u8 delay, u8 y, u8 targetY, u8 shouldResetBlendRegisters)
{
    gPaletteFade_blendCnt = blendCnt;
    gPaletteFade.delayCounter = delay;
    gPaletteFade_delay = delay;
    gPaletteFade.y = y;
    gPaletteFade.targetY = targetY;
    gPaletteFade.active = 1;
    gPaletteFade.mode = HARDWARE_FADE;
    gPaletteFade.shouldResetBlendRegisters = shouldResetBlendRegisters & 1;
    gPaletteFade.hardwareFadeFinishing = 0;

    if (y < targetY)
        gPaletteFade.yDec = 0;
    else
        gPaletteFade.yDec = 1;
}

static u8 UpdateHardwarePaletteFade(void)
{
    if (!gPaletteFade.active)
        return PALETTE_FADE_STATUS_DONE;

    if (gPaletteFade.delayCounter < gPaletteFade_delay)
    {
        gPaletteFade.delayCounter++;
        return PALETTE_FADE_STATUS_DELAY;
    }

    gPaletteFade.delayCounter = 0;

    if (!gPaletteFade.yDec)
    {
        gPaletteFade.y++;
        if (gPaletteFade.y > gPaletteFade.targetY)
        {
            gPaletteFade.hardwareFadeFinishing++;
            gPaletteFade.y--;
        }
    }
    else
    {
        s32 y = gPaletteFade.y--;
        if (y - 1 < gPaletteFade.targetY)
        {
            gPaletteFade.hardwareFadeFinishing++;
            gPaletteFade.y++;
        }
    }

    if (gPaletteFade.hardwareFadeFinishing)
    {
        if (gPaletteFade.shouldResetBlendRegisters)
        {
            gPaletteFade_blendCnt = 0;
            gPaletteFade.y = 0;
        }
        gPaletteFade.shouldResetBlendRegisters = 0;
    }

    // gPaletteFade.active cannot change since the last time it was checked. So this
    // is equivalent to `return PALETTE_FADE_STATUS_ACTIVE;`
    return gPaletteFade.active ? PALETTE_FADE_STATUS_ACTIVE : PALETTE_FADE_STATUS_DONE;
}

static void UpdateBlendRegisters(void)
{
    SetGpuReg(REG_OFFSET_BLDCNT, (u16)gPaletteFade_blendCnt);
    SetGpuReg(REG_OFFSET_BLDY, gPaletteFade.y);
    if (gPaletteFade.hardwareFadeFinishing)
    {
        gPaletteFade.hardwareFadeFinishing = 0;
        gPaletteFade.mode = 0;
        gPaletteFade_blendCnt = 0;
        gPaletteFade.y = 0;
        gPaletteFade.active = 0;
    }
}

static bool8 IsSoftwarePaletteFadeFinishing(void)
{
    if (gPaletteFade.softwareFadeFinishing)
    {
        if (gPaletteFade.softwareFadeFinishingCounter == 4)
        {
            gPaletteFade.active = 0;
            gPaletteFade.softwareFadeFinishing = 0;
            gPaletteFade.softwareFadeFinishingCounter = 0;
        }
        else
        {
            gPaletteFade.softwareFadeFinishingCounter++;
        }

        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

void BlendPalettes(u32 selectedPalettes, u8 coeff, u16 color)
{
    u16 paletteOffset;

    for (paletteOffset = 0; selectedPalettes; paletteOffset += 16)
    {
        if (selectedPalettes & 1)
            BlendPalette(paletteOffset, 16, coeff, color);
        selectedPalettes >>= 1;
    }
}

void BlendPalettesUnfaded(u32 selectedPalettes, u8 coeff, u16 color)
{
    void *src = gPlttBufferUnfaded;
    void *dest = gPlttBufferFaded;
    DmaCopy32(3, src, dest, PLTT_SIZE);
    BlendPalettes(selectedPalettes, coeff, color);
}

void TintPalette_GrayScale(u16 *palette, u16 count)
{
    s32 r, g, b, i;
    u32 gray;

    for (i = 0; i < count; i++)
    {
        r = (*palette >>  0) & 0x1F;
        g = (*palette >>  5) & 0x1F;
        b = (*palette >> 10) & 0x1F;

        gray = (r * Q_8_8(0.3) + g * Q_8_8(0.59) + b * Q_8_8(0.1133)) >> 8;

        *palette++ = (gray << 10) | (gray << 5) | (gray << 0);
    }
}

void TintPalette_GrayScale2(u16 *palette, u16 count)
{
    s32 r, g, b, i;
    u32 gray;

    for (i = 0; i < count; i++)
    {
        r = (*palette >>  0) & 0x1F;
        g = (*palette >>  5) & 0x1F;
        b = (*palette >> 10) & 0x1F;

        gray = (r * Q_8_8(0.3) + g * Q_8_8(0.59) + b * Q_8_8(0.1133)) >> 8;

        if (gray > 0x1F)
            gray = 0x1F;

        gray = sRoundedDownGrayscaleMap[gray];

        *palette++ = (gray << 10) | (gray << 5) | (gray << 0);
    }
}

void TintPalette_SepiaTone(u16 *palette, u16 count)
{
    s32 r, g, b, i;
    u32 gray;

    for (i = 0; i < count; i++)
    {
        r = (*palette >>  0) & 0x1F;
        g = (*palette >>  5) & 0x1F;
        b = (*palette >> 10) & 0x1F;

        gray = (r * Q_8_8(0.3) + g * Q_8_8(0.59) + b * Q_8_8(0.1133)) >> 8;

        r = (u16)((Q_8_8(1.2) * gray)) >> 8;
        g = (u16)((Q_8_8(1.0) * gray)) >> 8;
        b = (u16)((Q_8_8(0.94) * gray)) >> 8;

        if (r > 31)
            r = 31;

        *palette++ = (b << 10) | (g << 5) | (r << 0);
    }
}

void TintPalette_CustomTone(u16 *palette, u16 count, u16 rTone, u16 gTone, u16 bTone)
{
    s32 r, g, b, i;
    u32 gray;

    for (i = 0; i < count; i++)
    {
        r = (*palette >>  0) & 0x1F;
        g = (*palette >>  5) & 0x1F;
        b = (*palette >> 10) & 0x1F;

        gray = (r * Q_8_8(0.3) + g * Q_8_8(0.59) + b * Q_8_8(0.1133)) >> 8;

        r = (u16)((rTone * gray)) >> 8;
        g = (u16)((gTone * gray)) >> 8;
        b = (u16)((bTone * gray)) >> 8;

        if (r > 31)
            r = 31;
        if (g > 31)
            g = 31;
        if (b > 31)
            b = 31;

        *palette++ = (b << 10) | (g << 5) | (r << 0);
    }
}

void TintPalette_CustomToneWithCopy(const u16 *src, u16 *dest, u16 count, u16 rTone, u16 gTone, u16 bTone, bool8 excludeZeroes)
{
    s32 r, g, b, i;
    u32 gray;

    for (i = 0; i < count; i++, src++, dest++)
    {
        if (excludeZeroes && *src == RGB_BLACK)
            continue;

        r = (*src >>  0) & 0x1F;
        g = (*src >>  5) & 0x1F;
        b = (*src >> 10) & 0x1F;

        r = (u16)((rTone * r)) >> 8;
        g = (u16)((gTone * g)) >> 8;
        b = (u16)((bTone * b)) >> 8;
		
        if (r > 31)
            r = 31;
        if (g > 31)
            g = 31;
        if (b > 31)
            b = 31;

        *dest = (b << 10) | (g << 5) | (r << 0);
    }
}

#define GET_R(color) ((color) & 0x1F)
#define GET_G(color) (((color) >> 5) & 0x1F)
#define GET_B(color) (((color) >> 10) & 0x1F)
#define POKEMON_BLEND_INTENSITY 1

void SetCustomMonPalette(u16 *palette, struct Pokemon *mon)
{
    s32 r, g, b, i;
    u8 count = 16;
    u8 tone = Q_8_8(0.6);
    bool8 disableCustomColor = FALSE;
    u8 rgb[] = {0,0,0};
    u8 temprgb[] = {0,0,0};
    u8 playerRGB[] = {0,0,0};
    u32 monsPersonality = GetMonData(mon, MON_DATA_PERSONALITY);
    u16 monSpecies = GetMonData(mon, MON_DATA_SPECIES);
    u16 friendship = GetMonData(mon, MON_DATA_FRIENDSHIP);
    u16 color = monsPersonality & 0x7FFF;
    bool8 shouldBlend = TRUE;
    u8 changeColorMode = FALSE;

	rgb[0] = GET_R(monsPersonality);
	rgb[1] = GET_G(monsPersonality);
	rgb[2] = GET_B(monsPersonality);

    playerRGB[0] = gSaveBlock2Ptr->playerRGB[0] * 2 + 5;
    playerRGB[1] = gSaveBlock2Ptr->playerRGB[1] * 2 + 5;
    playerRGB[2] = gSaveBlock2Ptr->playerRGB[2] * 2 + 5;

    for (i = 0; i < count; i++)
    {
        r = GET_R(*palette);
        g = GET_G(*palette);
        b = GET_B(*palette);

        switch(monSpecies){
            case SPECIES_KECLEON:
                if(gSaveBlock2Ptr->playerRGB[0] == 0 && 
                   gSaveBlock2Ptr->playerRGB[1] == 0 && 
                   gSaveBlock2Ptr->playerRGB[2] == 0)
                    shouldBlend = FALSE;

                /*if(friendship >= 220)
                    shouldBlend = FALSE;*/
                
                if(shouldBlend){
                    if(i == 2){ //Darkest Color
                        r = playerRGB[0];
                        g = playerRGB[1];
                        b = playerRGB[2];

                        r = (u16)((tone * r)/2) >> 8;
                        g = (u16)((tone * g)/2) >> 8;
                        b = (u16)((tone * b)/2) >> 8;
                    }
                    else if(i == 7){ //Second Darkest Color
                        r = playerRGB[0];
                        g = playerRGB[1];
                        b = playerRGB[2];

                        r = (u16)((tone * r)) >> 8;
                        g = (u16)((tone * g)) >> 8;
                        b = (u16)((tone * b)) >> 8;
                    }
                    else if(i == 6){ //Middle Color
                        r = playerRGB[0];
                        g = playerRGB[1];
                        b = playerRGB[2];
                    }
                    else if(i == 10){ //Second Lightest Color
                        r = playerRGB[0] + 2;
                        g = playerRGB[1] + 2;
                        b = playerRGB[2] + 2;
                    }
                    else if(i == 11){ //Lightest Color
                        r = playerRGB[0] + 5;
                        g = playerRGB[1] + 5;
                        b = playerRGB[2] + 5;
                    }
                }
            break;
            default:
                if(r != g && g != b && shouldBlend){
                    r = (r + (((rgb[0] - r) * POKEMON_BLEND_INTENSITY) >> 4));
                    g = (g + (((rgb[1] - g) * POKEMON_BLEND_INTENSITY) >> 4));
                    b = (b + (((rgb[2] - b) * POKEMON_BLEND_INTENSITY) >> 4));
                }
            break;
        }

        temprgb[0] = r;
        temprgb[1] = g;
        temprgb[2] = b;

        if(changeColorMode == 1){
            r = temprgb[2];
            g = temprgb[0];
            b = temprgb[1];
        }
        else if(changeColorMode == 2){
            r = temprgb[1];
            g = temprgb[2];
            b = temprgb[0];
        }

        if (r > 31)
            r = 31;
        if (g > 31)
            g = 31;
        if (b > 31)
            b = 31;

        *palette++ = RGB2(r, g, b);
    }
}

void SetEnemyCustomMonPalette(u16 *palette, struct Pokemon *mon)
{
    s32 r, g, b, i;
    u8 count = 16;
    u8 tone = Q_8_8(0.6);
    bool8 disableCustomColor = FALSE;
    u8 rgb[] = {0,0,0};
    u32 monsPersonality = GetMonData(mon, MON_DATA_PERSONALITY);
    u16 monSpecies = GetMonData(mon, MON_DATA_SPECIES);
    u16 monHappiness = GetMonData(mon, MON_DATA_FRIENDSHIP);
    u16 color = monsPersonality & 0x7FFF;
    bool8 shouldBlend = TRUE;

	rgb[0] = GET_R(monsPersonality);
	rgb[1] = GET_G(monsPersonality);
	rgb[2] = GET_B(monsPersonality);

    for (i = 0; i < count; i++)
    {
        r = GET_R(*palette);
        g = GET_G(*palette);
        b = GET_B(*palette);
        
        if(r != g && g != b && shouldBlend){
            r = (r + (((rgb[0] - r) * POKEMON_BLEND_INTENSITY) >> 4));
            g = (g + (((rgb[1] - g) * POKEMON_BLEND_INTENSITY) >> 4));
            b = (b + (((rgb[2] - b) * POKEMON_BLEND_INTENSITY) >> 4));
        }

        if (r > 31)
            r = 31;
        if (g > 31)
            g = 31;
        if (b > 31)
            b = 31;

        *palette++ = RGB2(r, g, b);
    }
}

void SetCharacterPalette(const u16 *src, u16 *dest, u16 count, u16 rTone, u16 gTone, u16 bTone, bool8 excludeZeroes)
{
	//This Function changes the color of the Player Overworld Sprites
    s32 r, g, b, i;
    u32 gray;
	u8 tone 	= Q_8_8(0.6);
	u8 CapColorPaletteIndex[]  	= {0,0,0};
	u8 CapColorRGB[] 			= {0,0,0};
	u8 costume 	= VarGet(VAR_COSTUME_NUMBER);
	u8 gender 	= gSaveBlock2Ptr->playerGender;
	bool8 ShouldDisableColorChange = FALSE;
	
	if(	gSaveBlock2Ptr->playerRGB[0] == 0 &&
		gSaveBlock2Ptr->playerRGB[1] == 0 &&
		gSaveBlock2Ptr->playerRGB[2] == 0)
			ShouldDisableColorChange = TRUE;

	CapColorRGB[0] = gSaveBlock2Ptr->playerRGB[0]*2 + 5;
	CapColorRGB[1] = gSaveBlock2Ptr->playerRGB[1]*2 + 5;
	CapColorRGB[2] = gSaveBlock2Ptr->playerRGB[2]*2 + 5;

	switch(costume){
	case EMERALD_COSTUME:
		if(gender == GENDER_MALE) //Emerald Brendan
		{
			CapColorPaletteIndex[0] = 10;
			CapColorPaletteIndex[1] = 11;
			CapColorPaletteIndex[2] = 16;
		}
		else//Emerald May
		{
			CapColorPaletteIndex[0] = 10;
			CapColorPaletteIndex[1] = 11;
			CapColorPaletteIndex[2] = 16;
		}
	break;
	case RS_COSTUME:
		if(gender == GENDER_MALE) //RS Brendan
		{
			CapColorPaletteIndex[0] = 12;
			CapColorPaletteIndex[1] = 13;
			CapColorPaletteIndex[2] = 16;
		}
		else//RS May
		{
			CapColorPaletteIndex[0] = 2;
			CapColorPaletteIndex[1] = 4;
			CapColorPaletteIndex[2] = 12;
		}
	break;
	case FRLG_COSTUME:
		if(gender == GENDER_MALE) //Red
		{
			CapColorPaletteIndex[0] = 12;
			CapColorPaletteIndex[1] = 13;
			CapColorPaletteIndex[2] = 8;
		}
		else//Leaf
		{
			CapColorPaletteIndex[0] = 7;
			CapColorPaletteIndex[1] = 9;
			CapColorPaletteIndex[2] = 14;
		}
	break;
	case BW_COSTUME:
		if(gender == GENDER_MALE) //Hilbert
		{
			CapColorPaletteIndex[0] = 6;
			CapColorPaletteIndex[1] = 7;
			CapColorPaletteIndex[2] = 16;
		}
		else//Hilda
		{
			CapColorPaletteIndex[0] = 7;
			CapColorPaletteIndex[1] = 9;
			CapColorPaletteIndex[2] = 14;
		}
	break;
	}

    for (i = 0; i < count; i++, src++, dest++)
    {
        if (excludeZeroes && *src == RGB_BLACK)
            continue;

        r = (*src >>  0) & 0x1F;
        g = (*src >>  5) & 0x1F;
        b = (*src >> 10) & 0x1F;
		
		//Changes the color if its a cap color
		if(i == CapColorPaletteIndex[0] && !ShouldDisableColorChange){
			r = CapColorRGB[0];
			g = CapColorRGB[1];
			b = CapColorRGB[2];
		}
		else if(i == CapColorPaletteIndex[1] && !ShouldDisableColorChange){
			r = CapColorRGB[0];
			g = CapColorRGB[1];
			b = CapColorRGB[2];
		
			r = (u16)((tone * r)) >> 8;
			g = (u16)((tone * g)) >> 8;
			b = (u16)((tone * b)) >> 8;
		}
		else if(i == CapColorPaletteIndex[2] && !ShouldDisableColorChange){
			r = CapColorRGB[0];
			g = CapColorRGB[1];
			b = CapColorRGB[2];
			
			r = (u16)((tone * r)/2) >> 8;
			g = (u16)((tone * g)/2) >> 8;
			b = (u16)((tone * b)/2) >> 8;
		}

		if(ShouldTintOverworld()){
			r = (u16)((rTone * r)) >> 8;
			g = (u16)((gTone * g)) >> 8;
			b = (u16)((bTone * b)) >> 8;
		}

        if (r > 31)
            r = 31;
        if (g > 31)
            g = 31;
        if (b > 31)
            b = 31;

        *dest = (b << 10) | (g << 5) | (r << 0);
    }
}


void SetPasswordTrainerPalette(const u16 *src, u16 *dest)
{
    //Front Sprites
	s32 r, g, b, i;
    u32 gray;
	u8 CapColorPaletteIndex[]  	= {0,0,0};
	u8 CapColorRGB[] 			= {0,0,0};
	u8 tone = Q_8_8(0.6);
    struct CompressedPlayerParty CompressedPlayerParty = CreatePartyFromRamData();
	u8 costume = CompressedPlayerParty.trainerCostume;
	u8 gender = CompressedPlayerParty.trainerGender;
	bool8 ShouldDisableColorChange = FALSE;
    u8 count = 16;
    u8 redColor   = CompressedPlayerParty.redColor;
    u8 greenColor = CompressedPlayerParty.greenColor;
    u8 blueColor  = CompressedPlayerParty.blueColor;

    if(FlagGet(FLAG_MGBA_PRINT_ENABLED))
		mgba_printf(MGBA_LOG_WARN, "redColor %d, greenColor %d, blueColor %d, costume %d, gender %d", redColor, greenColor, blueColor, costume, gender);
	
	if(	redColor   == 0 &&
		greenColor == 0 &&
		blueColor  == 0)
		ShouldDisableColorChange = TRUE;
	
	CapColorRGB[0] = redColor   *2 + 5;	
	CapColorRGB[1] = greenColor *2 + 5;	
	CapColorRGB[2] = blueColor  *2 + 5;
	
	switch(costume){
	case EMERALD_COSTUME:
		if(gender == GENDER_MALE){
			//Brendan
			CapColorPaletteIndex[0] = 10;
			CapColorPaletteIndex[1] = 11;
			CapColorPaletteIndex[2] = 16;
		}
		else{
			//May
			CapColorPaletteIndex[0] = 10;
			CapColorPaletteIndex[1] = 11;
			CapColorPaletteIndex[2] = 5;
		}
	break;
	case RS_COSTUME:
		if(gender == GENDER_MALE){
			//Brendan
			CapColorPaletteIndex[0] = 12;
			CapColorPaletteIndex[1] = 13;
			CapColorPaletteIndex[2] = 16;
		}
		else{
			//May
			CapColorPaletteIndex[0] = 12;
			CapColorPaletteIndex[1] = 13;
			CapColorPaletteIndex[2] = 11;
		}
	break;
	case FRLG_COSTUME:
		if(gender == GENDER_MALE){
			//Red
			CapColorPaletteIndex[0] = 12;
			CapColorPaletteIndex[1] = 13;
			CapColorPaletteIndex[2] = 16;
		}
		else{
			//Leaf
			CapColorPaletteIndex[0] = 10;
			CapColorPaletteIndex[1] = 11;
			CapColorPaletteIndex[2] = 12;
		}
	break;
	case BW_COSTUME:
		if(gender == GENDER_MALE){
			//Hilbert
			CapColorPaletteIndex[0] = 1;
			CapColorPaletteIndex[1] = 2;
			CapColorPaletteIndex[2] = 16;
		}
		else{
			//Leaf
			CapColorPaletteIndex[0] = 10;
			CapColorPaletteIndex[1] = 11;
			CapColorPaletteIndex[2] = 12;
		}
	break;
	}

    for (i = 0; i < count; i++, src++, dest++)
    {

        r = (*src >>  0) & 0x1F;
        g = (*src >>  5) & 0x1F;
        b = (*src >> 10) & 0x1F;
		
		//Changes the color if its a cap color
		if(i == CapColorPaletteIndex[0] && !ShouldDisableColorChange){
			r = CapColorRGB[0];
			g = CapColorRGB[1];
			b = CapColorRGB[2];
		}
		else if(i == CapColorPaletteIndex[1] && !ShouldDisableColorChange){
			r = CapColorRGB[0];
			g = CapColorRGB[1];
			b = CapColorRGB[2];
		
			r = (u16)((tone * r)) >> 8;
			g = (u16)((tone * g)) >> 8;
			b = (u16)((tone * b)) >> 8;
		}
		else if(i == CapColorPaletteIndex[2] && !ShouldDisableColorChange){
			r = CapColorRGB[0];
			g = CapColorRGB[1];
			b = CapColorRGB[2];
			
			r = (u16)((tone * r)/2) >> 8;
			g = (u16)((tone * g)/2) >> 8;
			b = (u16)((tone * b)/2) >> 8;
		}

        if (r > 31)
            r = 31;
        if (g > 31)
            g = 31;
        if (b > 31)
            b = 31;

        *dest = (b << 10) | (g << 5) | (r << 0);
    }
}

void SetCharacterPaletteDayNight(const u16 *src, u16 *dest, u16 count, u16 rTone, u16 gTone, u16 bTone, bool8 excludeZeroes)
{
	//This Function changes the color of the Player Overworld Sprites
    s32 r, g, b, i;
    u32 gray;
	u8 tone 	= Q_8_8(0.6);
	u8 CapColorPaletteIndex[]  	= {0,0,0};
	u8 CapColorRGB[] 			= {0,0,0};
	u8 costume 	= VarGet(VAR_COSTUME_NUMBER);
	u8 gender 	= gSaveBlock2Ptr->playerGender;
	bool8 ShouldDisableColorChange = FALSE;
	
	if(	gSaveBlock2Ptr->playerRGB[0] == 0 &&
		gSaveBlock2Ptr->playerRGB[1] == 0 &&
		gSaveBlock2Ptr->playerRGB[2] == 0)
			ShouldDisableColorChange = TRUE;

	CapColorRGB[0] = gSaveBlock2Ptr->playerRGB[0]*2 + 5;
	CapColorRGB[1] = gSaveBlock2Ptr->playerRGB[1]*2 + 5;
	CapColorRGB[2] = gSaveBlock2Ptr->playerRGB[2]*2 + 5;

	switch(costume){
	case EMERALD_COSTUME:
		if(gender == GENDER_MALE) //Emerald Brendan
		{
			CapColorPaletteIndex[0] = 10;
			CapColorPaletteIndex[1] = 11;
			CapColorPaletteIndex[2] = 16;
		}
		else//Emerald May
		{
			CapColorPaletteIndex[0] = 10;
			CapColorPaletteIndex[1] = 11;
			CapColorPaletteIndex[2] = 16;
		}
	break;
	case RS_COSTUME:
		if(gender == GENDER_MALE) //RS Brendan
		{
			CapColorPaletteIndex[0] = 12;
			CapColorPaletteIndex[1] = 13;
			CapColorPaletteIndex[2] = 16;
		}
		else//RS May
		{
			CapColorPaletteIndex[0] = 2;
			CapColorPaletteIndex[1] = 4;
			CapColorPaletteIndex[2] = 12;
		}
	break;
	case FRLG_COSTUME:
		if(gender == GENDER_MALE) //Red
		{
			CapColorPaletteIndex[0] = 12;
			CapColorPaletteIndex[1] = 13;
			CapColorPaletteIndex[2] = 8;
		}
		else//Leaf
		{
			CapColorPaletteIndex[0] = 7;
			CapColorPaletteIndex[1] = 9;
			CapColorPaletteIndex[2] = 14;
		}
	break;
	case BW_COSTUME:
		if(gender == GENDER_MALE) //Hilbert
		{
			CapColorPaletteIndex[0] = 6;
			CapColorPaletteIndex[1] = 7;
			CapColorPaletteIndex[2] = 16;
		}
		else//Hilda
		{
			CapColorPaletteIndex[0] = 7;
			CapColorPaletteIndex[1] = 9;
			CapColorPaletteIndex[2] = 14;
		}
	break;
	}

    for (i = 0; i < count; i++, src++, dest++)
    {
        if (excludeZeroes && *src == RGB_BLACK)
            continue;

        r = (*src >>  0) & 0x1F;
        g = (*src >>  5) & 0x1F;
        b = (*src >> 10) & 0x1F;
		
		//Changes the color if its a cap color
		if(i == CapColorPaletteIndex[0] && !ShouldDisableColorChange){
			r = CapColorRGB[0];
			g = CapColorRGB[1];
			b = CapColorRGB[2];
		}
		else if(i == CapColorPaletteIndex[1] && !ShouldDisableColorChange){
			r = CapColorRGB[0];
			g = CapColorRGB[1];
			b = CapColorRGB[2];
		
			r = (u16)((tone * r)) >> 8;
			g = (u16)((tone * g)) >> 8;
			b = (u16)((tone * b)) >> 8;
		}
		else if(i == CapColorPaletteIndex[2] && !ShouldDisableColorChange){
			r = CapColorRGB[0];
			g = CapColorRGB[1];
			b = CapColorRGB[2];
			
			r = (u16)((tone * r)/2) >> 8;
			g = (u16)((tone * g)/2) >> 8;
			b = (u16)((tone * b)/2) >> 8;
		}

		r = (u16)((rTone * r)) >> 8;
		g = (u16)((gTone * g)) >> 8;
		b = (u16)((bTone * b)) >> 8;

        if (r > 31)
            r = 31;
        if (g > 31)
            g = 31;
        if (b > 31)
            b = 31;

        *dest = (b << 10) | (g << 5) | (r << 0);
    }
}

void SetCharacterTrainerPalette(const u16 *src, u16 *dest, u16 count)
{
    //Back Sprites
	s32 r, g, b, i;
    u32 gray;
	u8 CapColorPaletteIndex[]  	= {0,0,0};
	u8 CapColorRGB[] 			= {0,0,0};
	u8 tone = Q_8_8(0.6);
	u8 costume = VarGet(VAR_COSTUME_NUMBER);
	u8 gender = gSaveBlock2Ptr->playerGender;
	bool8 ShouldDisableColorChange = FALSE;
	
	if(	gSaveBlock2Ptr->playerRGB[0] == 0 &&
		gSaveBlock2Ptr->playerRGB[1] == 0 &&
		gSaveBlock2Ptr->playerRGB[2] == 0)
			ShouldDisableColorChange = TRUE;
			
	if(gSaveBlock2Ptr->playerRGB[0] > 9 ||
	   gSaveBlock2Ptr->playerRGB[1] > 9 ||
	   gSaveBlock2Ptr->playerRGB[2] > 9){
		//Fix Colors if they are above the max number
		gSaveBlock2Ptr->playerRGB[0] = 0;
		gSaveBlock2Ptr->playerRGB[1] = 0;
		gSaveBlock2Ptr->playerRGB[2] = 0;
	}
	
	CapColorRGB[0] = gSaveBlock2Ptr->playerRGB[0]*2 + 5;	
	CapColorRGB[1] = gSaveBlock2Ptr->playerRGB[1]*2 + 5;	
	CapColorRGB[2] = gSaveBlock2Ptr->playerRGB[2]*2 + 5;
	
	switch(costume){
	case EMERALD_COSTUME:
		if(gender == GENDER_MALE){
			//Brendan
			CapColorPaletteIndex[0] = 10;
			CapColorPaletteIndex[1] = 11;
			CapColorPaletteIndex[2] = 16;
		}
		else{
			//May
			CapColorPaletteIndex[0] = 10;
			CapColorPaletteIndex[1] = 11;
			CapColorPaletteIndex[2] = 5;
		}
	break;
	case RS_COSTUME:
		if(gender == GENDER_MALE){
			//Brendan
			CapColorPaletteIndex[0] = 12;
			CapColorPaletteIndex[1] = 13;
			CapColorPaletteIndex[2] = 16;
		}
		else{
			//May
			CapColorPaletteIndex[0] = 12;
			CapColorPaletteIndex[1] = 13;
			CapColorPaletteIndex[2] = 11;
		}
	break;
	case FRLG_COSTUME:
		if(gender == GENDER_MALE){
			//Red
			CapColorPaletteIndex[0] = 11;
			CapColorPaletteIndex[1] = 12;
			CapColorPaletteIndex[2] = 16;
		}
		else{
			//Leaf
			CapColorPaletteIndex[0] = 10;
			CapColorPaletteIndex[1] = 11;
			CapColorPaletteIndex[2] = 12;
		}
	break;
	case BW_COSTUME:
		if(gender == GENDER_MALE){
			//Hilbert
			CapColorPaletteIndex[0] = 1;
			CapColorPaletteIndex[1] = 2;
			CapColorPaletteIndex[2] = 16;
		}
		else{
			//Leaf
			CapColorPaletteIndex[0] = 10;
			CapColorPaletteIndex[1] = 11;
			CapColorPaletteIndex[2] = 12;
		}
	break;
	}

    for (i = 0; i < count; i++, src++, dest++)
    {

        r = (*src >>  0) & 0x1F;
        g = (*src >>  5) & 0x1F;
        b = (*src >> 10) & 0x1F;
		
		//Changes the color if its a cap color
		if(i == CapColorPaletteIndex[0] && !ShouldDisableColorChange){
			r = CapColorRGB[0];
			g = CapColorRGB[1];
			b = CapColorRGB[2];
		}
		else if(i == CapColorPaletteIndex[1] && !ShouldDisableColorChange){
			r = CapColorRGB[0];
			g = CapColorRGB[1];
			b = CapColorRGB[2];
		
			r = (u16)((tone * r)) >> 8;
			g = (u16)((tone * g)) >> 8;
			b = (u16)((tone * b)) >> 8;
		}
		else if(i == CapColorPaletteIndex[2] && !ShouldDisableColorChange){
			r = CapColorRGB[0];
			g = CapColorRGB[1];
			b = CapColorRGB[2];
			
			r = (u16)((tone * r)/2) >> 8;
			g = (u16)((tone * g)/2) >> 8;
			b = (u16)((tone * b)/2) >> 8;
		}

        if (r > 31)
            r = 31;
        if (g > 31)
            g = 31;
        if (b > 31)
            b = 31;

        *dest = (b << 10) | (g << 5) | (r << 0);
    }
}

void SetFrontCharacterTrainerPalette(const u16 *src, u16 *dest)
{
    //Front Sprites
	s32 r, g, b, i;
    u32 gray;
	u8 CapColorPaletteIndex[]  	= {0,0,0};
	u8 CapColorRGB[] 			= {0,0,0};
	u8 tone = Q_8_8(0.6);
	u8 costume = VarGet(VAR_COSTUME_NUMBER);
	u8 gender = gSaveBlock2Ptr->playerGender;
	bool8 ShouldDisableColorChange = FALSE;
    u8 count = 16;
	
	if(	gSaveBlock2Ptr->playerRGB[0] == 0 &&
		gSaveBlock2Ptr->playerRGB[1] == 0 &&
		gSaveBlock2Ptr->playerRGB[2] == 0)
			ShouldDisableColorChange = TRUE;
			
	if(gSaveBlock2Ptr->playerRGB[0] > 9 ||
	   gSaveBlock2Ptr->playerRGB[1] > 9 ||
	   gSaveBlock2Ptr->playerRGB[2] > 9){
		//Fix Colors if they are above the max number
		gSaveBlock2Ptr->playerRGB[0] = 0;
		gSaveBlock2Ptr->playerRGB[1] = 0;
		gSaveBlock2Ptr->playerRGB[2] = 0;
	}
	
	CapColorRGB[0] = gSaveBlock2Ptr->playerRGB[0]*2 + 5;	
	CapColorRGB[1] = gSaveBlock2Ptr->playerRGB[1]*2 + 5;	
	CapColorRGB[2] = gSaveBlock2Ptr->playerRGB[2]*2 + 5;
	
	switch(costume){
	case EMERALD_COSTUME:
		if(gender == GENDER_MALE){
			//Brendan
			CapColorPaletteIndex[0] = 10;
			CapColorPaletteIndex[1] = 11;
			CapColorPaletteIndex[2] = 16;
		}
		else{
			//May
			CapColorPaletteIndex[0] = 10;
			CapColorPaletteIndex[1] = 11;
			CapColorPaletteIndex[2] = 5;
		}
	break;
	case RS_COSTUME:
		if(gender == GENDER_MALE){
			//Brendan
			CapColorPaletteIndex[0] = 12;
			CapColorPaletteIndex[1] = 13;
			CapColorPaletteIndex[2] = 16;
		}
		else{
			//May
			CapColorPaletteIndex[0] = 12;
			CapColorPaletteIndex[1] = 13;
			CapColorPaletteIndex[2] = 11;
		}
	break;
	case FRLG_COSTUME:
		if(gender == GENDER_MALE){
			//Red
			CapColorPaletteIndex[0] = 12;
			CapColorPaletteIndex[1] = 13;
			CapColorPaletteIndex[2] = 16;
		}
		else{
			//Leaf
			CapColorPaletteIndex[0] = 10;
			CapColorPaletteIndex[1] = 11;
			CapColorPaletteIndex[2] = 12;
		}
	break;
	case BW_COSTUME:
		if(gender == GENDER_MALE){
			//Hilbert
			CapColorPaletteIndex[0] = 1;
			CapColorPaletteIndex[1] = 2;
			CapColorPaletteIndex[2] = 16;
		}
		else{
			//Leaf
			CapColorPaletteIndex[0] = 10;
			CapColorPaletteIndex[1] = 11;
			CapColorPaletteIndex[2] = 12;
		}
	break;
	}

    for (i = 0; i < count; i++, src++, dest++)
    {

        r = (*src >>  0) & 0x1F;
        g = (*src >>  5) & 0x1F;
        b = (*src >> 10) & 0x1F;
		
		//Changes the color if its a cap color
		if(i == CapColorPaletteIndex[0] && !ShouldDisableColorChange){
			r = CapColorRGB[0];
			g = CapColorRGB[1];
			b = CapColorRGB[2];
		}
		else if(i == CapColorPaletteIndex[1] && !ShouldDisableColorChange){
			r = CapColorRGB[0];
			g = CapColorRGB[1];
			b = CapColorRGB[2];
		
			r = (u16)((tone * r)) >> 8;
			g = (u16)((tone * g)) >> 8;
			b = (u16)((tone * b)) >> 8;
		}
		else if(i == CapColorPaletteIndex[2] && !ShouldDisableColorChange){
			r = CapColorRGB[0];
			g = CapColorRGB[1];
			b = CapColorRGB[2];
			
			r = (u16)((tone * r)/2) >> 8;
			g = (u16)((tone * g)/2) >> 8;
			b = (u16)((tone * b)/2) >> 8;
		}

        if (r > 31)
            r = 31;
        if (g > 31)
            g = 31;
        if (b > 31)
            b = 31;

        *dest = (b << 10) | (g << 5) | (r << 0);
    }
}

#define tCoeff       data[0]
#define tCoeffTarget data[1]
#define tCoeffDelta  data[2]
#define tDelay       data[3]
#define tDelayTimer  data[4]
#define tPalettes    5 // data[5] and data[6], set/get via Set/GetWordTaskArg
#define tColor       data[7]
#define tId          data[8]

// Blend the selected palettes in a series of steps toward or away from the color.
// Only used by the Groudon/Kyogre fight scene to flash the screen for lightning
// One call is used to fade the bg from white, while another fades the duo from black
void BlendPalettesGradually(u32 selectedPalettes, s8 delay, u8 coeff, u8 coeffTarget, u16 color, u8 priority, u8 id)
{
    u8 taskId;

    taskId = CreateTask((void *)Task_BlendPalettesGradually, priority);
    gTasks[taskId].tCoeff = coeff;
    gTasks[taskId].tCoeffTarget = coeffTarget;

    if (delay >= 0)
    {
        gTasks[taskId].tDelay = delay;
        gTasks[taskId].tCoeffDelta = 1;
    }
    else
    {
        gTasks[taskId].tDelay = 0;
        gTasks[taskId].tCoeffDelta = -delay + 1;
    }

    if (coeffTarget < coeff)
        gTasks[taskId].tCoeffDelta *= -1;

    SetWordTaskArg(taskId, tPalettes, selectedPalettes);
    gTasks[taskId].tColor = color;
    gTasks[taskId].tId = id;
    gTasks[taskId].func(taskId);
}

// Unused
static bool32 IsBlendPalettesGraduallyTaskActive(u8 id)
{
    int i;

    for (i = 0; i < NUM_TASKS; i++)
        if ((gTasks[i].isActive == TRUE) 
            && (gTasks[i].func == Task_BlendPalettesGradually) 
            && (gTasks[i].tId == id))
            return TRUE;

    return FALSE;
}

// Unused
static void DestroyBlendPalettesGraduallyTask(void)
{
    u8 taskId;

    while (1)
    {
        taskId = FindTaskIdByFunc(Task_BlendPalettesGradually);
        if (taskId == 0xFF)
            break;
        DestroyTask(taskId);
    }
}

static void Task_BlendPalettesGradually(u8 taskId)
{
    u32 palettes;
    s16 *data;
    s16 target;

    data = gTasks[taskId].data;
    palettes = GetWordTaskArg(taskId, tPalettes);

    if (++tDelayTimer > tDelay)
    {
        tDelayTimer = 0;
        BlendPalettes(palettes, tCoeff, tColor);
        target = tCoeffTarget;
        if (tCoeff == target)
        {
            DestroyTask(taskId);
        }
        else
        {
            tCoeff += tCoeffDelta;
            if (tCoeffDelta >= 0)
            {
                if (tCoeff < target)
                    return;
            }
            else if (tCoeff > target)
            {
                return;
            }
            tCoeff = target;
        }
    }
}
