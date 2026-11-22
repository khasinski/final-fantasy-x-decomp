#include "common.h"

typedef unsigned long u64;
typedef unsigned int u128 __attribute__((mode(TI)));

typedef union QWord {
    u128 q;
    u64 d[2];
    u32 u[4];
    s32 s[4];
    float f[4];
} QWord;

typedef struct BlurObj {
    u8 pad00[0x10];
    QWord q[13];        /* 0x10..0xDF */
    u8 padE0[0x10];
    u8 r;               /* 0xF0 */
    u8 g;               /* 0xF1 */
    u8 b;               /* 0xF2 */
    u8 a;               /* 0xF3 */
    u8 padF4[0x4];
    float fF8;          /* 0xF8 */
    float fFC;          /* 0xFC */
    float f100;         /* 0x100 */
    s32 w104;           /* 0x104 */
    s32 w108;           /* 0x108 */
    s32 w10C;           /* 0x10C */
    s32 w110;           /* 0x110 */
    s32 w114;           /* 0x114 */
    s32 w118;           /* 0x118 */
    u8 pad11C[0xA];
    u16 h126;           /* 0x126 */
} BlurObj;

typedef struct TaskObj {
    u8 pad00[0x14];
    BlurObj *p14;
} TaskObj;

extern QWord D_006F2D40;

TaskObj *func_01B07B20(void (*fn)(TaskObj *));
void func_01B07CE8(TaskObj *t);
void func_01B07BA0(TaskObj *t);
void func_0011A538(u32 *out);
void func_01B0C598(BlurObj *obj);
float func_01B08968(float a0, float a1, float a2, float a3);
void func_002B2A80(BlurObj *obj, s32 a1, s32 a2, s32 a3);

void func_01B0C2A0(TaskObj *t);

void func_01B0C258(BlurObj *a0, s32 a1)
{
    TaskObj *t;

    a0->h126 = 0;
    a0->w108 = a1;
    a0->w104 = a1;
    a0->w10C = 8;
    t = func_01B07B20(func_01B0C2A0);
    t->p14 = a0;
    func_01B07CE8(t);
}

void func_01B0C2A0(TaskObj *t)
{
    BlurObj *s1 = t->p14;
    u32 sp00[4];
    float f21;
    float f20;
    float sc;
    float u0, v0, u1, v1;
    QWord *p;
    u64 tex0;
    u64 alpha;
    s32 tbp;

    if (s1->w110 > 0) {
        s1->w110--;
        return;
    }

    func_0011A538(sp00);
    p = &s1->q[6];
    tbp = 0;
    if (sp00[0] & 1) {
        tbp = 0xD00;
    }
    alpha = ((u64)s1->a << 32) | 0x64ULL;
    tex0 = ((u64)tbp | ((u64)8 << 14) | ((u64)1 << 20) | ((u64)9 << 26) | ((u64)9 << 30) | ((u64)1 << 34));
    s1->q[0].q = 0;
    s1->q[0].d[0] = 0x1000000000008005ULL;
    s1->q[0].d[1] = 0xEULL;
    s1->q[1].d[0] = 0x3000DULL;
    s1->q[1].d[1] = 0x47ULL;
    s1->q[2].d[0] = alpha;
    s1->q[2].d[1] = 0x42ULL;
    s1->q[3].d[0] = 0x067C007FC00AULL;
    s1->q[3].d[1] = 0x8ULL;
    s1->q[4].d[0] = tex0;
    s1->q[4].d[1] = 0x6ULL;
    s1->q[5].d[0] = 0x0000008000008080ULL;
    s1->q[5].d[1] = 0x3BULL;
    func_01B0C598(s1);

    f21 = (float)s1->w114;
    f20 = (float)s1->w118;
    sc = func_01B08968(s1->fF8, s1->fFC, s1->f100, (float)(s1->w104 - s1->w108) / (float)s1->w104);

    p->q = 0;
    p->d[0] = 0x602B400000008001ULL;
    p->d[1] = 0xE52512ULL;
    p++;

    v0 = (f20 * (1.0f / 208.0f)) * sc * 0.8125f;
    u0 = (f21 * (1.0f / 256.0f)) * sc;
    p->f[0] = u0;
    p->f[1] = v0;
    p->f[2] = 1.0f;
    p++;

    p->u[0] = s1->r;
    p->u[1] = s1->g;
    p->u[2] = s1->b;
    p->u[3] = 128;
    p++;

    p->s[0] = 0x6FF8;
    p->s[1] = 0x72F8;
    p->s[2] = 0;
    p->s[3] = 0;
    p++;

    v1 = (1.0f - ((416.0f - f20) * (1.0f / 208.0f)) * sc) * 0.8125f;
    u1 = 1.0f - ((512.0f - f21) * (1.0f / 256.0f)) * sc;
    p->f[0] = u1;
    p->f[1] = v1;
    p->f[2] = 1.0f;
    p++;

    p->s[0] = 0x8FF8;
    p->s[1] = 0x8CF8;
    p->s[2] = 0;
    p->s[3] = 0;

    s1->q[12].d[0] = D_006F2D40.d[0];
    s1->q[12].d[1] = 0x47ULL;
    func_002B2A80(s1, 14, 4, 0);

    if (s1->w108 <= 0) {
        s1->a >>= 1;
        if (s1->w10C <= 0) {
            s1->h126 |= 0x8000;
            func_01B07BA0(t);
        } else {
            s1->w10C--;
        }
    } else {
        s1->w108--;
    }
}
