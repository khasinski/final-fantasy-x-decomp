/* Shared particle emitter task (588 B, 09109 @ 0x01B007E8, 09097 @ 0x01B00900). */

#include "common.h"
#include "vu0.h"

typedef struct {
    float x, y, z, w;
} __attribute__((aligned(16))) Vec4;

typedef struct {
    Vec4 pos;       /* 0x00 */
    float vx;       /* 0x10 */
    float vy;       /* 0x14 */
    float vz;       /* 0x18 */
    float rot;      /* 0x1C */
    float ax;       /* 0x20 */
    float ay;       /* 0x24 */
    float az;       /* 0x28 */
    float f2C;      /* 0x2C */
    u8 anim[0x0C];  /* 0x30 */
    float f3C;      /* 0x3C */
    float f40;      /* 0x40 */
    u8 pad44[0x08]; /* 0x44 */
    int w4C;        /* 0x4C */
    int w50;        /* 0x50 */
    u8 pad54[0x04]; /* 0x54 */
    int w58;        /* 0x58 */
    int w5C;        /* 0x5C */
    int w60;        /* 0x60 */
    u8 pad64[0x1C]; /* 0x64 */
} PartSlot;

extern u16 g_5328;
extern int g_5394;
extern int g_5398;
extern u8 g_b410[];

extern void fn_3458(void);
extern void fn_1840(int, int);
extern void fn_1318(int, int, Vec4 *);
extern PartSlot *fn_4b40(void);
extern void *func_002B49A0(void *, int, int);
extern void fn_4438(void *, void *);
extern float func_002B3DB0(float);

void ovl_09109_07e8(void)
{
    Vec4 pos;
    int i;
    int trigger;

    if (g_5328 & 0x8000) {
        fn_3458();
        return;
    }
    g_5394++;
    if (g_5394 == g_5398) {
        fn_1840(0, 0x200);
    }
    trigger = 0;
    if (g_5394 == g_5398 + 10) {
        trigger = 1;
    }
    if (g_5394 == g_5398 + 26) {
        trigger = 1;
    }
    if (g_5394 == g_5398 + 34) {
        trigger = 1;
    }
    if (trigger) {
        fn_1318(0, 1, &pos);
        for (i = 0; i < 4; i++) {
            PartSlot *s = fn_4b40();
            if (s == 0) {
                break;
            }
            fn_4438(s->anim, func_002B49A0(g_b410, 9, 0));
            MMI_COPY_LQ_A3(&s->pos, &pos);
            MMI_COPY_SQ_A3(&s->pos);
            s->pos.x += func_002B3DB0(1.0f);
            s->pos.z += func_002B3DB0(1.0f);
            s->vx = func_002B3DB0(0.25f) + func_002B3DB0(0.25f);
            s->vy = func_002B3DB0(0.3f) + (-0.35f);
            s->vz = func_002B3DB0(0.25f) + func_002B3DB0(0.25f);
            s->rot = func_002B3DB0(3.1415927f);
            s->ax = s->vx * (-1.0f / 28.0f);
            s->ay = s->vy * (-1.0f / 28.0f);
            s->az = s->vz * (-1.0f / 28.0f);
            s->w58 = 8;
            s->f3C = 0.015000001f;
            s->f40 = 10.0f;
            s->w4C = -1;
            s->f2C = 1.0f;
            s->w5C = 0;
            s->w50 = 0;
            s->w60 = 0;
        }
    }
}
