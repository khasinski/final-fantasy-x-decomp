#include "common.h"
#include "vu0.h"

#define COPY_VEC(dst, src) { MMI_COPY_LQ_A3(dst, src); MMI_COPY_SQ_A3(dst); }

typedef struct S4A10Entry {
    u8 pad00[0xD0];
    float vD0[4];
    u8 padE0[0x180];
    float v260[4];
    float v270[4];
    float v280[4];
    u8 pad290[0x280];
    s32 s510;
    s32 s514;
} S4A10Entry;

typedef struct S4A10Task {
    u8 pad00[0x14];
    S4A10Entry *ent;
} S4A10Task;

typedef struct S4A10SubB {
    u8 pad00[0x2904];
    s32 s2904;
    s32 s2908;
    s32 s290C;
} S4A10SubB;

typedef struct S4A10Global {
    u8 pad00[0x5B00];
    S4A10SubB subB;
} S4A10Global;

extern S4A10Global *D_01B0DCA8;
extern u8 D_01B0DBE0[];

extern void func_01B06CD8(float *a0, float *a1, s32 a2);
extern void func_01B04918(S4A10Entry *a0, float *a1, s32 a2);
extern void func_01B0A0B8(void *a0, void *a1);
extern void func_01B09968(void *a0);

void func_01B04A10(S4A10Task *a0)
{
    float v00[4];
    S4A10Entry *ent = a0->ent;
    S4A10SubB *subB = &D_01B0DCA8->subB;
    float t;
    float omt;
    s32 i;
    register float *v280 __asm__("$18");

    if (ent->s510 > 0) {
        ent->s510--;
    }
    t = (float)ent->s510 / (float)ent->s514;
    omt = 1.0f - t;
    v280 = ent->v280;
    for (i = 0; i < 3; i++) {
        v00[i] = ent->v270[i] * omt + ent->v260[i] * t;
    }
    v00[3] = 1.0f;
    func_01B06CD8(v280, v00, 0x80);
    COPY_VEC(ent->vD0, v00);
    if (ent->s510 <= 0) {
        register s32 cnt __asm__("$3");
        func_01B04918(ent, v280, subB->s2904);
        func_01B0A0B8(D_01B0DBE0, ent);
        cnt = subB->s290C;
        subB->s290C = cnt + 1;
        func_01B09968(a0);
    }
}
