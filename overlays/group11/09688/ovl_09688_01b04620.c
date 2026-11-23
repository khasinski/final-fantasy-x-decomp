#include "common.h"
#include "vu0.h"

#define COPY_VEC(dst, src) { MMI_COPY_LQ_A3(dst, src); MMI_COPY_SQ_A3(dst); }

static inline void copy_vec(void *dst, void *src)
{
    MMI_COPY_LQ_A3(dst, src);
    MMI_COPY_SQ_A3(dst);
}

typedef struct S4620Slot {
    s32 s00;
    s32 s04;
    u8 b08[0x20];
} S4620Slot;

typedef struct S4620Entry {
    u8 pad00[0xC0];
    float vC0[4];
    u8 padD0[0x190];
    float v260[4];
    float v270[4];
    float v280[4];
    u8 pad290[0x30];
    u8 trail[0x250];
    s32 s510;
    s32 s514;
    s32 s518;
    s32 s51C;
} S4620Entry; /* size 0x520 */

typedef struct S4620Item {
    u8 pad00[0xC4];
    float fC4;
    u8 padC8[8];
    float vD0[4];
    u8 padE0[0x24];
    void *p104;
    u8 pad108[0x28];
} S4620Item; /* size 0x130 */

typedef struct S4620SubA {
    u8 pad00[0x10];
    S4620Entry entries[8];
    u8 pad2910[0x258];
    s32 s2B68;
    s32 s2B6C;
    s32 s2B70;
    s32 s2B74;
} S4620SubA;

typedef struct S4620SubB {
    u8 pad00[0x2900];
    void *p2900;
    s32 s2904;
} S4620SubB;

typedef struct S4620Global {
    S4620Item items[24]; /* 0x0000..0x1C80 */
    u8 pad1C80[0x11D0];
    float v2E50[4];      /* 0x2E50 */
    u8 pad2E60[0x120];
    S4620SubA subA;      /* 0x2F80 */
    u8 pad5AF8[8];
    S4620SubB subB;      /* 0x5B00 */
    u8 pad8408[0x66C8];
    float fEAD0;         /* 0xEAD0 */
    u8 padEAD4[0xA0];
    S4620Slot *cur_slot; /* 0xEB74 */
} S4620Global;

typedef struct S4620Task {
    u8 pad00[0x14];
    void *p14;
    u8 pad18[0x14];
    s32 s2C;
    u8 pad30[0x26];
    u8 b56;
} S4620Task;

extern S4620Global *D_01B0DCA8;
extern u8 D_01B0DBE0[];
extern s32 D_01B00C78[];
extern void D_01B04400(void *);
extern void D_01B06F08(void);

extern void func_01B066A0(float *dst);
extern void func_01B07328(s32 a0, float *a1, s32 a2);
extern void func_01B0AAF0(float *a0, float *a1, float *a2);
extern float func_01B0AC98(float *a0, float *a1);
extern void func_01B04168(void *a0);
extern void func_01B045E0(S4620Entry *a0, s32 a1);
extern S4620Task *func_01B098E8(void (*fn)(void *));
extern void func_01B09AB0(void *a0);
extern void func_01B066E8(void);
extern void *func_01B06578(void);
extern void func_00110540(void *a0, s32 a1, float f0);
extern void func_01B09C48(void *a0, void *a1, s32 a2, s32 a3, s32 a4, s32 a5, float f0);

void func_01B04620(void *a0)
{
    float v00[4];
    S4620Global *g = D_01B0DCA8;
    S4620SubA *subA = &g->subA;
    S4620Entry *ent = subA->entries;
    s32 count = g->cur_slot->s04;
    s32 i;

    func_01B066A0(v00);
    for (i = 0; i < count; i++, ent++) {
        s32 target = g->cur_slot->b08[i];
        s32 frames;
        S4620Task *t;

        copy_vec(ent->v260, v00);
        func_01B07328(target, ent->v270, 4);
        func_01B0AAF0(ent->v280, ent->v260, ent->v270);
        frames = (s32)(func_01B0AC98(ent->v260, ent->v270) / 6.0f);
        ent->s510 = frames;
        if (frames < 0) {
            ent->s510 = 1;
        }
        ent->s514 = ent->s510;
        if (subA->s2B68 == 0) {
            func_01B04168(ent->trail);
        }
        func_01B045E0(ent, subA->s2B68);
        copy_vec(ent->vC0, ent->v280);
        ent->s51C = i;
        ent->s518 = target;
        t = func_01B098E8(D_01B04400);
        t->p14 = ent;
        func_01B09AB0(t);
    }

    subA->s2B6C = count;
    subA->s2B70 = 0;
    func_01B066E8();
    func_00110540(func_01B06578(), 1, 0.0f);
}

void func_01B047C0(S4620Task *a0)
{
    S4620SubA *subA = &D_01B0DCA8->subA;
    if (subA->s2B6C == subA->s2B70) {
        subA->s2B74 = 1;
        a0->b56 = 1;
    }
}

void func_01B047F0(void)
{
    S4620Global *g = D_01B0DCA8;
    S4620Item *it = &g->items[16];
    func_01B09C48(D_01B0DBE0, it, 16, 0, 0, 0, 0.1f);
    {
        register void *dst __asm__("$4") = g->items[16].vD0;
        COPY_VEC(dst, g->v2E50);
    }
    {
        register u32 off __asm__("$3") = 0x8000;
        u8 *hi;
        __asm__("" : "+r"(off));
        hi = (u8 *)g + off;
        it->fC4 = *(float *)(hi + 0x6AD0);
    }
}
