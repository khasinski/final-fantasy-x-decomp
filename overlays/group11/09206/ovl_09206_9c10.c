#include "common.h"
#include "vu0.h"

typedef unsigned int u128 __attribute__((mode(TI)));

typedef struct TrackVec {
    float v0[4];        /* 0x00 */
    float v1[4];        /* 0x10 */
    u8 pad20[0xC];
    s32 w2C;            /* 0x2C */
    float f30;          /* 0x30 */
    s32 w34;            /* 0x34 */
    u8 pad38[0x4];
    s32 w3C;            /* 0x3C */
} TrackVec;

TrackVec *func_01B0A0D0(void *a0, s32 a1);

void func_01B09C10(void *a0, s32 a1, void *a2, void *a3, s32 t0)
{
    TrackVec *p = func_01B0A0D0(a0, a1);

    MMI_COPY_LQ_A3(p->v0, a2);
    MMI_COPY_SQ_A3(p->v0);
    MMI_COPY_LQ_A3(p->v1, a3);
    MMI_COPY_SQ_A3(p->v1);
    p->w2C = 0;
    p->w3C = 1;
    p->v1[3] = 1.0f;
    p->v0[3] = 1.0f;
    p->f30 = 1.0f / (float)t0;
}

void func_01B09C98(void *a0, s32 a1, void *a2, void *a3, s32 t0)
{
    TrackVec *p = func_01B0A0D0(a0, a1);
    float z;

    MMI_COPY_LQ_A3(p->v0, a2);
    MMI_COPY_SQ_A3(p->v0);
    MMI_COPY_LQ_A3(p->v1, a3);
    MMI_COPY_SQ_A3(p->v1);
    z = 0.0f;
    p->w34 = t0;
    p->v1[3] = z;
    p->v0[3] = z;
    p->w3C = 2;
}
