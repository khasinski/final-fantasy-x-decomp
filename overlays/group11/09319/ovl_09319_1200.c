#include "common.h"

typedef struct {
    u8 pad00[0x104];
    float f104;
} State9319;

typedef struct {
    u8 pad00[0x04];
    s32 w04;
    u8 pad08[0x0D];
    u8 b15;
    u8 pad16[0xAE];
    void *pC4;
} Obj758;

typedef struct {
    s32 w00;
    void *p04;
    u8 b08;
    u8 b09;
    u8 b0A;
    u8 pad0B;
    u16 h0C;
    u16 h0E;
    s32 w10;
    s32 w14;
    u8 b18;
    u8 b19;
    u8 b1A;
    u8 b1B;
    s8 b1C;
    s8 b1D;
    s8 b1E;
    u8 b1F;
    void *p20;
    void *p24;
    void *p28;
    void *p2C;
    u8 pad30[0x04];
    s32 w34;
    s32 w38;
    s32 w3C;
    u16 h40;
    u16 h42;
    s32 w44;
    s32 w48;
    u8 b4C;
    u8 b4D;
    u8 pad4E[0x22];
} DrawCfg;

extern float D_01B006D8[];
extern Obj758 D_01B00758;
extern u8 *D_01B056E8;
extern State9319 *D_01B056EC;
extern u8 *D_01B056F0;

extern void *func_001038F8(void);
extern void func_001051A0(void *, int, int);
extern void func_0010D4A0(void *, int);
extern void func_0010D4D8(void *, int);
extern void func_00110648(void *, int);
extern void func_00110820(void *, int);
extern void func_00110AC0(void *, int);
extern void func_00110BC8(void *, int, int);
extern void func_00117A68(void *);
extern void func_002A3BD8(void *, void *);
extern void func_002A3CA0(void *, void *, int, int, int, int);
extern void func_002A7308(void *, void *, int, int);
extern void func_002B7BE8(void *, DrawCfg *, float (*)[4], float (*)[4], float (*)[4]);
extern void func_002DCE38(float (*)[4], float (*)[4], float (*)[4]);
extern void func_002DD128(float (*)[4]);

extern int func_01B01660(int);
extern void *func_01B016F8(int);
extern void *func_01B01D28(int);
extern void func_01B02948(int, int);
extern void *func_01B02EB8(void *);
extern void func_01B02F80(float (*)[4], float (*)[4]);
extern void func_01B03240(int, int, int);

void ovl_09319_1200(void)
{
    Obj758 *o = &D_01B00758;
    void *s1;
    int s0;

    s1 = func_01B02EB8(func_01B01D28(0));
    o->b15 = 32;
    o->w04 = 2;
    o->pC4 = s1;
    s0 = func_01B01660(0);
    func_01B03240(1, 15360, 12000);
    if (s0 == 13) {
        func_00110BC8(s1, 1, 1);
    }
    func_002A7308(D_01B056E8, s1, 1, 0);
    func_00110AC0(s1, 0);
    if (s0 == 8) {
        func_001051A0(s1, 1, 18);
    } else {
        func_001051A0(s1, 1, 16);
    }
    func_00110820(s1, 0);
    func_00110648(s1, 0);
    func_01B02948(1, 1);
    func_00117A68(s1);
    func_002A3BD8(s1, D_01B056F0);
}

void ovl_09319_1318(void)
{
    State9319 *s0 = D_01B056EC;
    s0->f104 = D_01B006D8[func_01B01660(0) - 8];
}

void ovl_09319_1360(float (*a0)[4], u8 a1)
{
    DrawCfg cfg;
    float m0[4][4];
    float m1[4][4];
    float m2[4][4];
    float m3[4][4];
    float m4[4][4];
    void *s0;

    func_002A3CA0(func_01B016F8(1), D_01B056F0, 0, -128, -32, 0);
    s0 = func_01B016F8(1);
    func_0010D4A0(s0, -1);
    func_0010D4D8(s0, -1);

    cfg.w00 = 28;
    cfg.p04 = func_001038F8();
    cfg.b08 = 68;
    cfg.b09 = 128;
    cfg.b0A = 0;
    cfg.h0C = 0;
    cfg.h0E = 0;
    cfg.w10 = 0;
    cfg.w14 = 0;
    cfg.b18 = 0;
    cfg.b19 = 0;
    cfg.b1A = 0;
    cfg.b1B = 0;
    cfg.b1C = -128;
    cfg.b1D = -128;
    cfg.b1E = -128;
    cfg.b1F = a1;
    cfg.w34 = 0;
    cfg.w38 = 0;
    cfg.w3C = 0;
    cfg.h40 = 0;
    cfg.h42 = 0;
    cfg.w44 = 0;
    cfg.w48 = 0;
    cfg.b4C = 0;
    cfg.b4D = 0;

    func_01B02F80(m1, m2);
    func_002DCE38(m0, m2, a0);
    func_002DCE38(m0, m1, m0);
    func_002DD128(m4);
    func_002DD128(m3);
    cfg.p20 = m0;
    cfg.p24 = m4;
    cfg.p28 = m3;
    cfg.p2C = a0;
    func_002B7BE8(D_01B056E8, &cfg, a0, m2, m1);
}
