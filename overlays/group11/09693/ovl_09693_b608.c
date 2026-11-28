#include "common.h"

typedef struct {
    void *p0;
    void *p4;
    void *p8;
    void *pC;
    void *p10;
    void *p14;
} MsgB608;

extern u8 D_01B00720[];
extern u8 D_01B00750[];
extern u8 D_01B00960[];
extern u8 D_01B00998[];
extern u8 D_01B181A0[];
extern void *D_01B181CC;

extern void func_01B0B4C8(void *);
extern void func_01B16C58(void *);
extern void func_01B17060(void *);
extern void func_01B0DA50(void *);
extern void func_01B11D68(void *);
extern void func_01B13B48(void *);
extern void func_01B15CA8(void *);

static inline void set_p8(MsgB608 *p, void *v) { p->p8 = v; }
static inline void set_p10(MsgB608 *p, void *v) { p->p10 = v; }
static inline void set_p4(MsgB608 *p, void *v) { p->p4 = v; }

void func_01B0B608(u8 *s0, void *s2) {
    void *a00[4];
    MsgB608 a10;
    u8 *s3 = s0 + 0x20;
    u8 *s4 = s0 + 0x60;
    u8 *s5 = s0 + 0x90;

    a00[0] = s0;
    a00[1] = (void *)func_01B0B4C8;
    a00[2] = s0;
    func_01B16C58(a00);

    a00[0] = D_01B00960;
    a00[1] = s0;
    func_01B17060(a00);

    a00[0] = s3;
    a00[1] = D_01B00998;
    a00[2] = s2;
    func_01B0DA50(a00);

    *(float *)(s0 + 0x54) = 80.0f;

    a00[0] = s4;
    a00[1] = D_01B00998;
    func_01B11D68(a00);

    {
        MsgB608 *p = &a10;
        *(volatile void **)&a10.p0 = s5;
        *(float *)(s0 + 0x80) = 1.0f;
        *(float *)(s0 + 0x84) = 1.0f;
        *(float *)(s0 + 0x88) = 1.0f;
        *(float *)(s0 + 0x8C) = 0.15f;
        *(volatile void **)&p->p8 = D_01B00750;
        a10.pC = s3;
        *(volatile void **)&p->p10 = D_01B00720;
        a10.p14 = s4;
        *(volatile void **)&p->p4 = D_01B00998;
        func_01B13B48(p);
    }

    s0[0x1DC] = 1;

    {
        void **p = a00;
        p[0] = s0 + 0x1E0;
        p[1] = D_01B00998;
        p[2] = s5;
        p[3] = D_01B181CC;
        p[4] = D_01B181A0;
        p[5] = (void *)6;
        func_01B15CA8(p);
    }

    *(s32 *)(s0 + 0x18) = 0;
}
