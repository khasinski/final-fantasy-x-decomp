#include "common.h"

typedef struct ShakeParam {
    float amp0;         /* 0x00 */
    float amp1;         /* 0x04 */
    s32 cnt0;           /* 0x08 */
    s32 cnt1;           /* 0x0C */
} ShakeParam;

typedef struct ShakeSlot {
    u8 pad00[0x50];
    float v50[3];       /* 0x50 */
    u32 pad5C;
    float v60[3];       /* 0x60 */
    u8 pad6C[0xBC];
    ShakeParam param;   /* 0x128 */
} ShakeSlot;

float func_002B3DB0(float a);

void func_01B0A850(ShakeSlot *s)
{
    ShakeParam *p = &s->param;
    s32 i;
    float sum;

    sum = 0.0f;
    for (i = 0; i < p->cnt0; i++) {
        sum += func_002B3DB0(p->amp0);
    }
    s->v50[0] += sum;
    s->v50[1] += sum;
    s->v50[2] += sum;

    sum = 0.0f;
    for (i = 0; i < p->cnt1; i++) {
        sum += func_002B3DB0(p->amp1);
    }
    s->v60[0] += sum;
    s->v60[1] += sum;
    s->v60[2] += sum;
}
