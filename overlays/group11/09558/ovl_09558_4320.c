#include "common.h"

typedef struct {
    void *p0;
    void *p4;
    void *p8;
    void *pC;
    void *p10;
    void *p14;
} Msg4320;

extern u8 D_01B00940[];
extern u8 D_01B00B80[];
extern u8 D_01B00B98[];
extern u8 D_01B00BB8[];
extern u8 D_01B110D0[];
extern void *D_01B110FC;

extern void func_01B04230(void *);
extern void func_01B0FBF0(void *);
extern void func_01B0FFF8(void *);
extern void func_01B0B2C0(void *);
extern void func_01B0CAE0(void *);
extern void func_01B0EC40(void *);

static inline void set_p4(Msg4320 *p, void *p4) { p->p4 = p4; }
static inline void set_p10(Msg4320 *p, void *p10) { p->p10 = p10; }

void func_01B04320(u8 *s0, void *s5) {
    u8 *s4 = s0 + 0x20;
    u8 *s2 = s0 + 0x170;
    u8 *s3 = s0 + 0x1A0;
    void *a00[4];
    Msg4320 a10;

    a00[0] = s0;
    a00[1] = (void *)func_01B04230;
    a00[2] = s0;
    func_01B0FBF0(a00);

    a00[0] = D_01B00B80;
    a00[1] = s0;
    func_01B0FFF8(a00);

    a00[0] = s2;
    a00[1] = D_01B00B98;
    func_01B0B2C0(a00);

    *(float *)(s0 + 0x190) = 0.0f;
    *(float *)(s0 + 0x194) = -4.5f;
    *(float *)(s0 + 0x198) = -1.5f;
    *(float *)(s0 + 0x19C) = 1.0f;

    a00[0] = s3;
    a00[1] = D_01B00B98;
    func_01B0B2C0(a00);

    *(float *)(s0 + 0x1C0) = 1.0f;
    *(float *)(s0 + 0x1C4) = 1.0f;
    *(float *)(s0 + 0x1C8) = 1.0f;
    *(volatile float *)(s0 + 0x1CC) = 120.0f;

    {
        Msg4320 *p = &a10;
        *(volatile void **)&p->p4 = D_01B00B98;
        a10.p8 = s5;
        a10.pC = s2;
        *(volatile void **)&p->p10 = D_01B00940;
        a10.p14 = s3;
        a10.p0 = s4;
        func_01B0CAE0(p);
    }

    {
        void **p = a00;
        p[0] = s0 + 0x1D0;
        p[1] = D_01B00BB8;
        p[2] = s4;
        p[3] = D_01B110FC;
        p[4] = D_01B110D0;
        p[5] = 0;
        func_01B0EC40(p);
    }

    *(s32 *)(s0 + 0x18) = 0;
}
