#include "common.h"

typedef struct Obj4030 {
    u8 pad00[0x10];
    float pos[4];       /* 0x10 */
    float vel[4];       /* 0x20 */
    int maxLife;        /* 0x30 */
    int life;           /* 0x34 */
    u32 flags;          /* 0x38 */
    u8 pad3C[0x34];
    float scale;        /* 0x70 */
    u8 pad74[4];
    int r;              /* 0x78 */
    int g;              /* 0x7C */
    int b;              /* 0x80 */
    float alpha;        /* 0x84 */
    u8 pad88[8];
    int r0;             /* 0x90 */
    int g0;             /* 0x94 */
    int b0;             /* 0x98 */
    int a0;             /* 0x9C */
    int r1;             /* 0xA0 */
    int g1;             /* 0xA4 */
    int b1;             /* 0xA8 */
    int a1;             /* 0xAC */
    float scale0;       /* 0xB0 */
    float scale1;       /* 0xB4 */
} Obj4030;

extern void func_002DD020(void *, void *, void *);

int func_01B04030(Obj4030 *t0)
{
    u32 flags = t0->flags;

    if (!(flags & 1)) {
        t0->life--;
        if (t0->life <= 0) {
            return 0;
        }
    }
    if (flags & 2) {
        t0->alpha = (float)t0->life / (float)t0->maxLife;
    }
    if (flags & 4) {
        float t = 1.0f - (float)t0->life / (float)t0->maxLife;
        t0->r = (int)((float)t0->r0 + (float)(t0->r1 - t0->r0) * t);
        t0->g = (int)((float)t0->g0 + (float)(t0->g1 - t0->g0) * t);
        t0->b = (int)((float)t0->b0 + (float)(t0->b1 - t0->b0) * t);
        t0->alpha = ((float)t0->a0 + (float)(t0->a1 - t0->a0) * t) / 127.0f;
        if (t0->alpha < 0.0f) {
            t0->alpha = 0.0f;
        }
        if (t0->alpha > 1.0f) {
            t0->alpha = 1.0f;
        }
    }
    if (flags & 8) {
        float ds = t0->scale1 - t0->scale0;
        t0->scale = t0->scale0 + ds * (1.0f - (float)t0->life / (float)t0->maxLife);
    }
    func_002DD020(t0->pos, t0->pos, t0->vel);
    return 1;
}
