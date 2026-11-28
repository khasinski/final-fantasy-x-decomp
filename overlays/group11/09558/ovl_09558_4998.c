#include "common.h"

typedef struct {
    void *p0;
    void *p4;
    void *p8;
    void *pC;
    void *p10;
    void *p14;
} Msg4998;

extern void *D_01B007A8;
extern u8 D_01B00940[];
extern u8 D_01B00B80[];
extern u8 D_01B00B98[];
extern u8 D_01B00BB8[];

extern void func_01B04870(void *);
extern void func_01B0FBF0(void *);
extern void func_01B0FFF8(void *);
extern void func_01B0B2C0(void *);
extern void func_01B0CAE0(void *);
extern void *func_002B49A0(void *, s32, s32);
extern void func_01B05998(void *);

static inline void set_p4(Msg4998 *p, void *p4) { p->p4 = p4; }
static inline void set_p10(Msg4998 *p, void *p10) { p->p10 = p10; }

void func_01B04998(u8 *s0, void *s6, float *s2) {
    void *a00[4];
    Msg4998 a10;
    u8 *s5 = s0 + 0x20;
    u8 *s4 = s0 + 0x170;
    u8 *s3 = s0 + 0x1A0;

    a00[0] = s0;
    a00[1] = (void *)func_01B04870;
    a00[2] = s0;
    func_01B0FBF0(a00);

    a00[0] = D_01B00B80;
    a00[1] = s0;
    func_01B0FFF8(a00);

    a00[0] = s4;
    a00[1] = D_01B00B98;
    func_01B0B2C0(a00);

    *(float *)(s0 + 0x190) = s2[8];
    *(float *)(s0 + 0x194) = -0.5f;
    *(float *)(s0 + 0x198) = s2[10];
    *(float *)(s0 + 0x19C) = 1.0f;

    a00[0] = s3;
    a00[1] = D_01B00B98;
    func_01B0B2C0(a00);

    *(float *)(s0 + 0x1C0) = 1.0f;
    *(float *)(s0 + 0x1C4) = 1.0f;
    *(float *)(s0 + 0x1C8) = 1.0f;
    *(volatile float *)(s0 + 0x1CC) = 0.049999997f;

    {
        Msg4998 *p = &a10;
        *(volatile void **)&p->p4 = D_01B00B98;
        a10.p8 = s6;
        a10.pC = s4;
        *(volatile void **)&p->p10 = D_01B00940;
        a10.p14 = s3;
        a10.p0 = s5;
        func_01B0CAE0(p);
    }

    {
        void *v0 = func_002B49A0(D_01B007A8, 4, 0);
        a00[0] = s0 + 0x1D0;
        a00[1] = D_01B00BB8;
        a00[2] = s5;
        a00[3] = v0;
        func_01B05998(a00);
    }

    *(s32 *)(s0 + 0x18) = 0;
    s0[0x1F7] = 0x40;
}
