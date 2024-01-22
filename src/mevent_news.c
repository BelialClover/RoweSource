#include "global.h"
#include "mevent.h"
#include "random.h"
#include "event_data.h"
#include "mevent_news.h"

static u32 sub_801DCAC(struct WonderNewsMetadata *);
static void sub_801DD10(struct WonderNewsMetadata *);
static u32 sub_801DD44(struct WonderNewsMetadata *);
static void sub_801DCD8(struct WonderNewsMetadata *);
static void sub_801DCCC(struct WonderNewsMetadata *);

void GenerateRandomNews(u32 a0)
{
    struct WonderNewsMetadata *r5 = GetSavedWonderNewsMetadata();

    r5->newsType = a0;
    switch (a0)
    {
    case 0:
        break;
    case 1:
    case 2:
        r5->rand = (Random() % 15) + 16;
        break;
    case 3:
        r5->rand = (Random() % 15) + 1;
        break;
    }
}

void InitSavedWonderNews(void)
{
    struct WonderNewsMetadata *r5 = GetSavedWonderNewsMetadata();

    r5->newsType = 0;
    r5->sentCounter = 0;
    r5->getCounter = 0;
    r5->rand = 0;
    VarSet(VAR_0x402E, 0);
}

void sub_801DBDC(void)
{
    u16 *r4 = GetVarPointer(VAR_0x402E);
    struct WonderNewsMetadata *r2 = GetSavedWonderNewsMetadata();
    struct WonderNewsMetadata r0 = *r2;

    if ((u8)r0.getCounter > 4 && ++(*r4) > 0x1f3)
    {
        r2->getCounter = 0;
        *r4 = 0;
    }
}

// Unused
u16 sub_801DC20(void)
{
    u16 *r6 = &gSpecialVar_Result;
    struct WonderNewsMetadata *r4 = GetSavedWonderNewsMetadata();
    u16 r5;

    if (!IsMysteryEventEnabled() || !ValidateReceivedWonderNews())
        return 0;

    r5 = sub_801DD44(r4);

    switch (r5)
    {
    case 0:
        break;
    case 1:
        *r6 = sub_801DCAC(r4);
        break;
    case 2:
        *r6 = sub_801DCAC(r4);
        break;
    case 3:
        break;
    case 4:
        *r6 = sub_801DCAC(r4);
        sub_801DCD8(r4);
        break;
    case 5:
        *r6 = sub_801DCAC(r4);
        sub_801DCCC(r4);
        break;
    case 6:
        break;
    }

    return r5;
}

static u32 sub_801DCAC(struct WonderNewsMetadata *a0)
{
    u32 r4;

    a0->newsType = 0;
    r4 = a0->rand + 0x84;
    a0->rand = 0;
    sub_801DD10(a0);
    return r4;
}

static void sub_801DCCC(struct WonderNewsMetadata *a0)
{
    a0->sentCounter = 0;
}

static void sub_801DCD8(struct WonderNewsMetadata *a0)
{
    a0->sentCounter++;
    if ((u8)a0->sentCounter > 4)
        a0->sentCounter = 4;
}

static void sub_801DD10(struct WonderNewsMetadata *a0)
{
    a0->getCounter++;
    if ((u8)a0->getCounter > 5)
        a0->getCounter = 5;
}

static u32 sub_801DD44(struct WonderNewsMetadata *a0)
{
    struct WonderNewsMetadata r0;
    if ((u8)a0->getCounter == 5)
        return 6;

    r0 = *a0;
    switch (r0.newsType)
    {
    case 0:
        return 3;
    case 1:
        return 1;
    case 2:
        return 2;
    case 3:
        if ((u8)r0.sentCounter < 3)
            return 4;
        return 5;
    default:
        AGB_ASSERT(0);
        return 0;
    }
}
