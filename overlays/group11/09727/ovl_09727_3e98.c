#include "common.h"

typedef struct {
    u8 pad00[0x20];
    u8 b20[0x200];
    u8 b220[0x20];
    float f240;
    float f244;
    float f248;
    u8 pad24C[0x34];
    u8 b280[0x20];
    float f2A0;
    float f2A4;
    float f2A8;
    float f2AC;
    u8 pad2B0[0x30];
    u8 b2E0[0x2A0];
    float f580;
    float f584;
    s32 w588;
    s32 w58C;
    void *p590;
    u8 b594[0x10];
} Ovl9727Eff;

extern void *D_01B007F8;
extern u8 D_01B00990[];
extern u8 D_01B009C0[];
extern u8 D_01B00BD0[];
extern u8 D_01B00BE8[];
extern u8 D_01B00C08[];
extern u8 D_01B0EFA0[];
extern void *D_01B0EFCC;

extern float func_001ACED8(void);
extern void func_01B03BD8(void *);
extern void func_01B05C28(void *);
extern void func_01B09920(void *);
extern void func_01B0AAA8(void *);
extern void func_01B0C360(void *);
extern void func_01B0C398(void *);
extern void func_01B0CC08(void *);
extern void func_01B0DBB8(void *);
extern void func_01B0DFC0(void *);

void func_01B03E98(Ovl9727Eff *eff, void *arg1, float arg2) {
    void *m0[10];
    float scale;

    m0[0] = eff;
    m0[1] = func_01B03BD8;
    m0[2] = eff;
    func_01B0DBB8(m0);

    m0[0] = D_01B00BD0;
    m0[1] = eff;
    func_01B0DFC0(m0);

    m0[0] = eff->b220;
    m0[1] = D_01B00BE8;
    func_01B09920(m0);

    m0[0] = eff->b280;
    m0[1] = D_01B00BE8;
    func_01B09920(m0);

    {
        void **m1 = m0 + 4;
        float one = 1.0f;
        *(void *volatile *)&m0[4] = eff->b2E0;
        *(volatile float *)&eff->f2A8 = one;
        m1[4] = D_01B00990;
        *(void *volatile *)&m0[9] = eff->b280;
        *(volatile float *)&eff->f2A0 = one;
        *(volatile float *)&eff->f2A4 = one;
        *(void *volatile *)&m1[1] = D_01B00BE8;
        *(void *volatile *)&m1[2] = D_01B009C0;
        m0[7] = eff->b220;
        func_01B0AAA8(m1);
    }

    m0[0] = arg1;
    m0[1] = &eff->f240;
    m0[2] = 0;
    func_01B05C28(m0);

    eff->f244 += (func_001ACED8() - 0.99f) * 20.0f + -10.0f;
    scale = arg2 * 1.2f * 0.9f;
    eff->f2AC = scale;

    m0[0] = eff->b20;
    m0[1] = D_01B00C08;
    m0[2] = eff->b2E0;
    m0[3] = D_01B0EFCC;
    m0[4] = D_01B0EFA0;
    m0[5] = (void *)2;
    func_01B0CC08(m0);

    m0[0] = eff->b594;
    m0[1] = D_01B00BE8;
    m0[2] = D_01B009C0;
    m0[3] = eff->b220;
    m0[4] = D_01B007F8;
    m0[5] = 0;
    func_01B0C398(m0);

    m0[0] = eff->b594;
    m0[1] = 0;
    func_01B0C360(m0);

    eff->f240 += (func_001ACED8() - 0.99f) * 20.0f + -10.0f;
    eff->f248 += (func_001ACED8() - 0.99f) * 20.0f + -10.0f;

    eff->f584 = arg2;
    eff->p590 = arg1;
    eff->f580 = 0.0f;
    eff->w588 = 0;
    eff->w58C = 0;
}
