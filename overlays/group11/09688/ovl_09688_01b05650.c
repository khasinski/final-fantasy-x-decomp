#include "common.h"
#include "vu0.h"

#define COPY_VEC(dst, src) { MMI_COPY_LQ_A3(dst, src); MMI_COPY_SQ_A3(dst); }

typedef struct S5650Slot {
    s32 s00;
    s32 s04;
    u8 b08[0x20];
} S5650Slot;

typedef struct S5650Entry {
    u8 pad00[0x260];
    float v260[4];
    float v270[4];
    float v280[4];
    u8 pad290[0x280];
    s32 s510;
    s32 s514;
    s32 s518;
    u8 pad51C[4];
} S5650Entry; /* size 0x520 */

typedef struct S5650Item {
    u8 pad00[0x104];
    void *p104;
    u8 pad108[0x18];
    s32 s120;
    u8 pad124[0xC];
} S5650Item; /* size 0x130 */

typedef struct S5650SubC {
    S5650Entry entries[16]; /* 0x0000..0x5200 */
    s32 s5200;
    s32 s5204;
    s32 s5208;
    s32 s520C;
    s32 s5210;
    s32 s5214;
} S5650SubC;

typedef struct S5650Global {
    S5650Item items[16]; /* 0x0000..0x1300 */
    u8 pad1300[0x1B50];
    float v2E50[4];      /* 0x2E50 */
    u8 pad2E60[0x55C0];
    S5650SubC subC;      /* 0x8420 */
    u8 padD638[0x1498];
    float fEAD0;         /* 0xEAD0 */
    u8 padEAD4[0xA0];
    S5650Slot *cur_slot; /* 0xEB74 */
} S5650Global;

typedef struct S5650Task {
    u8 pad00[0x14];
    void *p14;
    u8 pad18[0x3E];
    u8 b56;
} S5650Task;

extern S5650Global *D_01B0DCA8;
extern void D_01B05230(void);
extern void D_01B05608(void);

extern void func_01B066A0(float *dst);
extern float func_002B3DB0(float a0);
extern void func_01B0ABF8(float *dst, float *a1, float *a2);
extern void func_01B07328(s32 a0, float *a1, s32 a2);
extern void func_01B0AAF0(float *a0, float *a1, float *a2);
extern float func_01B0AC98(float *a0, float *a1);
extern S5650Task *func_01B098E8(void (*fn)(void));
extern void func_01B09AB0(void *a0);
extern s32 func_001ACEA0(void);

void func_01B05650(S5650Task *a0)
{
    float v00[4];
    float v10[4];
    float v20[4];
    S5650Global *g = D_01B0DCA8;
    S5650SubC *subC = &g->subC;
    S5650Entry *ent;
    s32 target;
    s32 frames;
    S5650Task *t;

    if (subC->s5200 > 0) {
        subC->s5200--;
        return;
    }

    if (subC->s5208 == 0) {
        COPY_VEC(v00, g->v2E50);
    } else {
        func_01B066A0(v00);
    }

    ent = &subC->entries[subC->s5204];
    v10[0] = 0.0f;
    v10[1] = g->fEAD0;
    v10[2] = 0.0f;
    v10[3] = 0.0f;
    v20[0] = 0.0f;
    v20[1] = 0.0f;
    v20[2] = 0.0f;
    v20[3] = 1.0f;
    if (subC->s5208 == 0) {
        v20[0] = func_002B3DB0(5.0f);
        v20[1] = func_002B3DB0(2.0f) + -16.0f;
        func_01B0ABF8(v10, v00, v20);
    }

    {
        register float *v260 __asm__("$19") = ent->v260;
        COPY_VEC(v260, v00);
        target = g->cur_slot->b08[subC->s5204];
        func_01B07328(target, ent->v270, 4);
        if (subC->s5208 == 0) {
            ent->v270[0] += func_002B3DB0(4.0f);
            ent->v270[1] += func_002B3DB0(4.0f);
            ent->v270[2] += func_002B3DB0(4.0f);
        }

        func_01B0AAF0(ent->v280, v260, ent->v270);
        frames = (s32)(func_01B0AC98(v260, ent->v270) / 10.0f) + 1;
    }
    ent->s510 = frames;
    if (frames < 0) {
        ent->s510 = 1;
    }
    ent->s514 = ent->s510;
    ent->s518 = target;
    t = func_01B098E8(D_01B05230);
    t->p14 = ent;
    func_01B09AB0(t);

    subC->s5200 = (func_001ACEA0() % 8) + 4;
    subC->s5204++;
    if (subC->s5204 >= subC->s520C) {
        S5650Item *it = &g->items[15];
        it->p104 = D_01B05608;
        it->s120 = 0x3C;
        a0->b56 = 1;
    }
}

void func_01B058D0(S5650Task *a0)
{
    S5650SubC *subC = &D_01B0DCA8->subC;
    if (subC->s520C == subC->s5210) {
        subC->s5214 = 1;
        a0->b56 = 1;
    }
}
