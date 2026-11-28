#include "common.h"

typedef struct {
    void *task;
    u8 *work;
} TaskArgB0C8;

typedef struct {
    void *p0;
    void *p4;
    void *p8;
    void *pC;
    void *p10;
    void *p14;
} MsgB0C8;

typedef struct {
    s32 a;
    s32 b;
} Pair4E0;

extern Pair4E0 D_01B004E0[];
extern u8 D_01B00720[];
extern u8 D_01B00978[];
extern u8 D_01B00998[];
extern u8 D_01B181A0[];
extern void *D_01B181CC;

extern s32 func_001CE050(void *, s32);
extern s32 func_001CE1A8(void *);
extern void func_001CE2F0(void *, s32);
extern void func_01B11D68(void *);
extern void func_01B13B48(void *);
extern void func_01B15CA8(void *);
extern void func_01B16D00(void *);

static inline void set_p4_p10(MsgB0C8 *p, void *p4, void *p10) {
    p->p4 = p4;
    p->p10 = p10;
}

void func_01B0B0C8(TaskArgB0C8 *s0) {
    void *a00[4];
    MsgB0C8 a10;
    void *m30[1];
    u8 *s4 = s0->work;

loop:
    switch (*(u32 *)(s4 + 0x18)) {
    case 0: {
        u8 *chr = *(u8 **)(s4 + 0x24);
        func_001CE050(*(void **)(chr + 0x54), 178);
        *(s32 *)(s4 + 0x18) += 1;
        break;
    }
    case 1: {
        u8 *chr = *(u8 **)(s4 + 0x24);
        if (func_001CE1A8(*(void **)(chr + 0x54)) != 0) {
            u8 *s2 = s4 + 0x30;
            u8 *s1 = s4 + 0x60;
            u8 *s3 = s4 + 0x160;
            chr = *(u8 **)(s4 + 0x24);
            func_001CE050(*(void **)(chr + 0x54), 179);

            a00[0] = s2;
            a00[1] = D_01B00978;
            func_01B11D68(a00);

            *(float *)(s4 + 0x5C) = 1.0f;
            *(float *)(s4 + 0x54) = 25.0f;
            *(float *)(s4 + 0x58) = -4.0f;
            *(float *)(s4 + 0x50) = ((float)*(s32 *)(s4 + 0x20) * 2.0f + -1.0f) * -12.0f;

            a00[0] = s1;
            a00[1] = D_01B00978;
            func_01B11D68(a00);

            *(float *)(s4 + 0x80) = 1.0f;
            *(float *)(s4 + 0x84) = 1.0f;
            *(float *)(s4 + 0x88) = 1.0f;
            *(volatile float *)(s4 + 0x8C) = 130.0f;

            {
                MsgB0C8 *p = &a10;
                *(volatile void **)&p->p4 = D_01B00978;
                a10.p8 = *(void **)(s4 + 0x400);
                a10.pC = s2;
                *(volatile void **)&p->p10 = D_01B00720;
                a10.p14 = s1;
                a10.p0 = s3;
                func_01B13B48(p);
            }

            {
                void **p = a00;
                p[0] = s4 + 0x410;
                p[1] = D_01B00998;
                p[2] = s3;
                p[3] = D_01B181CC;
                p[4] = D_01B181A0;
                p[5] = (void *)D_01B004E0[*(s32 *)(s4 + 0x20)].a;
                func_01B15CA8(p);
            }

            *(s32 *)(s4 + 0x1C) = 40;
            *(s32 *)(s4 + 0x18) += 1;
        }
        break;
    }
    case 2:
        if (*(s32 *)(s4 + 0x1C) <= 0) {
            *(s32 *)(s4 + 0x18) = 10;
            goto loop;
        }
        break;
    case 10: {
        u8 *s1 = s4 + 0xA0;
        u8 *s2 = s4 + 0x2B0;
        a00[0] = s1;
        a00[1] = D_01B00978;
        func_01B11D68(a00);

        *(float *)(s4 + 0xC0) = 1.0f;
        *(float *)(s4 + 0xC4) = 1.0f;
        *(float *)(s4 + 0xC8) = 1.0f;
        *(volatile float *)(s4 + 0xCC) = 600.0f;

        {
            void **p = a00;
            *(volatile void **)&p[1] = D_01B00978;
            *(volatile void **)&p[2] = *(void **)(s4 + 0x400);
            p[3] = *(void **)(s4 + 0x90);
            p[4] = D_01B00720;
            p[5] = s1;
            p[0] = s2;
            func_01B13B48(p);
        }

        {
            void **p = a00;
            p[0] = s4 + 0x510;
            p[1] = D_01B00998;
            p[2] = s2;
            p[3] = D_01B181CC;
            p[4] = D_01B181A0;
            p[5] = (void *)D_01B004E0[*(s32 *)(s4 + 0x20)].b;
            func_01B15CA8(p);
        }

        *(s32 *)(s4 + 0x1C) = 110;
        *(s32 *)(s4 + 0x18) += 1;
        break;
    }
    case 11:
        if (*(s32 *)(s4 + 0x1C) <= 0) {
            *(s32 *)(s4 + 0x18) = 20;
            goto loop;
        }
        break;
    case 20: {
        u8 *chr = *(u8 **)(s4 + 0x24);
        func_001CE050(*(void **)(chr + 0x54), 180);
        *(s32 *)(s4 + 0x20) = 0;
        *(s32 *)(s4 + 0x18) += 1;
        break;
    }
    case 21: {
        u8 *chr = *(u8 **)(s4 + 0x24);
        if (func_001CE1A8(*(void **)(chr + 0x54)) != 0) {
            chr = *(u8 **)(s4 + 0x24);
            func_001CE2F0(*(void **)(chr + 0x54), 0);
            m30[0] = s0->task;
            func_01B16D00(m30);
            *(s32 *)(s4 + 0x18) = 20000;
        }
        break;
    }
    }
    *(s32 *)(s4 + 0x1C) -= 1;
}
