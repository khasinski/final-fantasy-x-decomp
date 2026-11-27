#include "common.h"

extern u8 *D_01B0A8E8;
extern void *D_01B0A8EC;

void func_00173650(void *a0);
void *func_01B039E0(int a0);
void func_01B05528(int a0, int a1, int a2);
void *func_001038F8(void);
void func_002A7308(void *a0, void *a1, int a2, void *a3);
void func_0010D4A0(void *a0, int a1);
void func_0010D4D8(void *a0, int a1);
void func_01B05268(void *a0, void *a1);
void func_002DCE38(void *a0, void *a1, void *a2);
void func_002B7BE8(void *a0, void *a1, void *a2, void *a3, void *a4);
void func_002DA610(int a0, int a1);
void func_002D0698(u32 a0);
void func_01B07880(void *a0, void *a1);

void func_01B01AF8(int *a0)
{
    int t3;
    int a2;
    int t0;

    if (a0[13] > 0) {
        a0[13]--;
    }
    t3 = a0[13];
    a2 = a0[12];
    t0 = a2 - t3;
    a0[0] = (a0[4] * t3 + a0[8] * t0) / a2;
    a0[1] = (a0[5] * t3 + a0[9] * t0) / a2;
    a0[2] = (a0[6] * t3 + a0[10] * t0) / a2;
    a0[3] = 0x80;
    func_00173650(a0);
}

void func_01B01B90(void)
{
    void *s0 = func_01B039E0(-1);

    func_01B05528(-1, 0x3C00, 0x2EE0);
    func_002A7308(D_01B0A8EC, s0, 2, func_001038F8());
    func_01B05528(-1, -1, -1);
}

typedef struct {
    int w00;
    void *w04;
    u8 b08;
    u8 b09;
    u8 b0A;
    u8 b0B;
    s16 h0C;
    s16 h0E;
    int w10;
    int w14;
    u8 b18;
    u8 b19;
    u8 b1A;
    u8 b1B;
    u8 b1C;
    u8 b1D;
    u8 b1E;
    u8 b1F;
    void *p20;
    void *p24;
    void *p28;
    void *p2C;
    int w30;
    float w34;
    float w38;
    float w3C;
    s16 h40;
    s16 h42;
    float w44;
    float w48;
    u8 b4C;
    u8 b4D;
    u8 pad4E[0x22];
} DrawParams;

typedef struct {
    u8 pad00[0x9C0];
    u8 m9C0[0x40];
    u8 mA00[0x40];
    u8 mA40[0x40];
    u8 padA80[0x2750];
    int x31D0;
} Work9212;

void func_01B01C00(void)
{
    DrawParams params;
    float m0[4][4];
    float m1[4][4];
    float m2[4][4];
    Work9212 *s1 = (Work9212 *)D_01B0A8E8;
    void *s4 = s1->m9C0;
    void *s0;

    func_01B05528(-1, 0x3C00, 0x2EE0);
    s0 = func_01B039E0(-1);
    func_0010D4A0(s0, -1);
    func_0010D4D8(s0, -1);
    params.w00 = 0x5C;
    params.w04 = func_001038F8();
    params.b08 = 0x44;
    params.b09 = 0x80;
    params.b0A = 0;
    params.h0C = 0;
    params.h0E = 0;
    params.w10 = 0;
    params.w14 = 0;
    params.b18 = 0x80;
    params.b19 = 0x80;
    params.b1A = 0x80;
    params.b1B = 0x80;
    params.b1C = 0;
    params.b1D = 0;
    params.b1E = 0;
    params.b1F = 0;
    params.w34 = 0;
    params.w38 = 0;
    params.w3C = 0;
    params.h40 = 0;
    params.h42 = 0;
    params.w44 = 0;
    params.w48 = 0;
    {
        int d = 100;
        params.b4C = ((d - s1->x31D0) * 64) / d;
        params.b4D = (s1->x31D0 * 128 + (100 - s1->x31D0) * 64) / 100;
    }
    func_01B05268(m1, m2);
    func_002DCE38(m0, m2, s4);
    func_002DCE38(m0, m1, m0);
    params.p20 = m0;
    params.p24 = s1->mA00;
    params.p28 = s1->mA40;
    params.p2C = s4;
    func_002B7BE8(D_01B0A8EC, &params, s4, m2, m1);
    func_002DA610(0, 0);
    func_01B05528(-1, -1, -1);
    func_002D0698(0xFFFFFFFFU);
}

void func_01B01DC8(u8 *a0, void *a1)
{
    u8 *p;
    int i;

    func_01B07880(a0, a1);
    *(int *)(a0 + 0x814) = 0;
    *(u32 *)(a0 + 0x810) = 0x80808080U;
    *(int *)(a0 + 0x824) = 0;
    *(float *)(a0 + 0x818) = 1.0f;
    *(float *)(a0 + 0x81C) = 1.0f;
    p = a0 + 0x8AB;
    for (i = 0x7F; i >= 0; i--) {
        *p-- = 0;
    }
}
