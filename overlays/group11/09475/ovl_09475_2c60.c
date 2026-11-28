#include "common.h"

extern u8 *D_01B0A068;

extern void func_01B03EF8(s32, float (*)[4]);
extern void *func_01B037F0(s32);
extern void func_0010D380(void *, s32, s32);
extern void func_0010D3A8(void *, s32, s32);
extern void func_0010D4A0(void *, s32);
extern void func_0010D4D8(void *, s32);
extern void func_002DD128(float (*)[4]);
extern void func_002DD318(float (*)[4], float (*)[4], float);
extern void func_002DD270(float (*)[4], float (*)[4], float);
extern void func_002DCE38(float (*)[4], float (*)[4], float (*)[4]);
extern void func_002DCE08(float *, float (*)[4], float *);
extern void func_01B01938(float *, float *, float *, float *);
extern void func_01B06FF8(float *, float *, float *);
extern void func_002DD998(float *, float *, float);
extern void func_01B02AF8(float (*)[4]);

typedef struct {
    float unk00;
    float unk04;
    float unk08;
    float unk0C;
    float unk10;
    float unk14;
    float unk18;
    float unk1C;
    float (*unk20)[4];
    float *unk24;
    float *unk28;
    float *unk2C;
} Item2C60;

static inline float wrap_angle(float a) {
    if (a > 3.1415927f) {
        a -= 6.2831855f;
    } else if (a < -3.1415927f) {
        a += 6.2831855f;
    }
    return a;
}

void func_01B02C60(void) {
    float m0[4][4];
    float m1[4][4];
    float m2[4][4];
    float m3[4][4];
    float m4[4][4];
    float va[4];
    float vb[4];
    float vc[4];
    float vd[4];
    float ve[4];
    float vf[4];
    u8 *s6 = D_01B0A068;
    void *p;
    s32 i;

    if (*(s32 *)(s6 + 0xD6C) > 0) {
        *(s32 *)(s6 + 0xD6C) -= 1;
    } else if (*(s32 *)(s6 + 0xD70) > 0) {
        *(s32 *)(s6 + 0xD70) -= 1;
    }

    func_01B03EF8(0, m4);
    p = func_01B037F0(2);
    func_0010D380(p, -1, 0x3C00);
    func_0010D3A8(p, -1, 0x2EE0);
    func_0010D4A0(p, -1);
    func_0010D4D8(p, -1);

    for (i = 0; i < 3; i++) {
        Item2C60 *it = (Item2C60 *)(s6 + (i * 0x30 + 0xCD0));

        func_002DD128(m1);
        func_002DD318(m1, m1, it->unk08);
        func_002DD270(m1, m1, -1.5707964f);
        func_002DD128(m0);
        func_002DD270(m0, m0, it->unk00);
        func_002DD318(m0, m0, it->unk04);
        func_002DCE38(m0, m0, m1);

        func_002DCE38(m2, m4, it->unk20);
        func_002DCE08(va, m2, it->unk24);
        func_002DCE08(vb, m2, it->unk28);
        func_002DCE08(vc, m2, it->unk2C);
        func_01B01938(ve, va, vb, vc);

        ve[0] *= 1000.0f;
        ve[1] *= 1000.0f;
        ve[2] *= 1000.0f;
        vd[0] = 0.0f;
        vd[1] = 0.0f;
        vd[2] = 0.0f;
        vd[3] = 0.0f;
        func_01B06FF8(vf, vd, ve);

        vd[0] = 0.0f;
        vd[1] = -6.0f;
        vd[2] = 0.0f;
        vd[3] = 1.0f;
        func_002DCE08(vd, m0, vd);
        m0[3][0] += vd[0];
        m0[3][1] += vd[1];
        m0[3][2] += vd[2];

        func_002DD128(m3);
        func_002DD270(m3, m3, wrap_angle(vf[0] - it->unk10));
        func_002DD318(m3, m3, wrap_angle(vf[1] - it->unk14));
        func_002DCE38(m0, m3, m0);

        vd[0] = (it->unk24[0] + it->unk28[0] + it->unk2C[0]) / 3.0f;
        vd[1] = (it->unk24[1] + it->unk28[1] + it->unk2C[1]) / 3.0f;
        vd[2] = (it->unk24[2] + it->unk28[2] + it->unk2C[2]) / 3.0f;
        vd[3] = 1.0f;
        func_002DCE08(vd, m2, vd);
        m0[3][0] += vd[0];
        m0[3][1] += vd[1];
        m0[3][2] += vd[2];
        m0[3][3] = 1.0f;

        func_002DD998(m0[0], m0[0], 0.002f);
        func_002DD998(m0[1], m0[1], 0.002f);
        func_002DD998(m0[2], m0[2], 0.002f);
        func_01B02AF8(m0);
    }
}
