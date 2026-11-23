#include "common.h"
#include "vu0.h"

#define COPY_VEC(dst, src) { MMI_COPY_LQ_A3(dst, src); MMI_COPY_SQ_A3(dst); }

typedef struct S4400Trail {
    u8 pad00[0x22C];
    s32 s22C;
} S4400Trail;

typedef struct S4400Entry {
    u8 pad00[0xD0];
    float vD0[4];
    u8 padE0[0x180];
    float v260[4];
    float v270[4];
    float v280[4];
    u8 pad290[0x30];
    S4400Trail trail; /* 0x2C0 */
    u8 pad4F0[0x20];
    s32 s510;
    s32 s514;
} S4400Entry;

typedef struct S4400Task {
    u8 pad00[0x14];
    S4400Entry *ent;
} S4400Task;

typedef struct S4400Sub {
    u8 pad00[0x2B68];
    s32 s2B68;
    s32 s2B6C;
    s32 s2B70;
} S4400Sub;

typedef struct S4400Global {
    u8 pad00[0x2F80];
    S4400Sub sub;
} S4400Global;

extern S4400Global *D_01B0DCA8;
extern u8 D_01B0DBE0[];

extern void func_01B04018(s32 a0, float *a1);
extern void func_01B06CD8(float *a0, float *a1, s32 a2);
extern void func_01B04308(S4400Entry *a0, float *a1, s32 a2);
extern void func_01B0A0B8(void *a0, void *a1);
extern void func_01B09968(void *a0);
extern void func_002DD128(float (*m)[4]);
extern void func_01B067B8(S4400Trail *a0, float (*m)[4], float *v);

void func_01B04400(S4400Task *a0)
{
    float m00[4][4];
    float v40[4];
    S4400Entry *ent = a0->ent;
    S4400Sub *sub = &D_01B0DCA8->sub;
    S4400Trail *trail = &ent->trail;

    if (ent->s510 > 0) {
        ent->s510--;
    }

    if (ent->s510 >= 0) {
        register float *v280 __asm__("$21") = ent->v280;
        float t = (float)ent->s510 / (float)ent->s514;
        float omt = 1.0f - t;
        s32 i;
        for (i = 0; i < 3; i++) {
            v40[i] = ent->v270[i] * omt + ent->v260[i] * t;
        }
        v40[3] = 1.0f;
        func_01B04018(sub->s2B68, v40);
        func_01B06CD8(v280, v40, 0x80);
        COPY_VEC(ent->vD0, v40);
        if (ent->s510 == 0) {
            register s32 mode __asm__("$3");
            func_01B04308(ent, v280, sub->s2B68);
            func_01B0A0B8(D_01B0DBE0, ent);
            mode = sub->s2B68;
            if (mode == 0) {
                ent->s510--;
            } else {
                sub->s2B70++;
                func_01B09968(a0);
                return;
            }
        }
    } else {
        if (trail->s22C <= 0) {
            sub->s2B70++;
            func_01B09968(a0);
            return;
        }
        trail->s22C--;
        COPY_VEC(v40, ent->v270);
    }

    if (sub->s2B68 == 0) {
        func_002DD128(m00);
        m00[2][2] = 0.2f;
        m00[1][1] = 0.2f;
        m00[0][0] = 0.2f;
        func_01B067B8(trail, m00, v40);
    }
}
