/* EE Battle-Effect Overlay: group 0x11, file 09755
 * .text: 0x01B00630..0x01B00D88 (13 functions: GS tex-transfer + ppp part + tt_scene main + matrix norm).
 */
#include "common.h"

typedef struct TtCfg {
    u8 pad00[0x10];
    int *w10;
    float *w14;
    s16 *w18;
    char *w1c;
} TtCfg;

typedef struct TtHeap {
    u8 pad00[0x20];
    float *w20;
    s16 *w24;
    char *w28;
} TtHeap;

typedef struct TtPObj {
    u8 pad00[0x40];
    float x, y, z, w;
    int rx, ry, rz, rw;
    float sx, sy, sz, sw;
} TtPObj;

extern void *D_006A3924;
extern u8 D_006A3930[];
extern u8 D_006A3970[];
extern u8 D_006A39B0[];
extern u8 D_006A3A70[];
extern u8 D_006A3AB0[];
extern int D_006A3BC4;
extern void *D_006A3BCC;

extern u8 D_01B00040[];
extern int D_01B003B0;
extern u8 D_01B003B8[];
extern int D_01B003D0;
extern int D_01B003D4;
extern int D_01B003D8;
extern u8 *D_01B003DC;
extern u8 *D_01B003E0;
extern u8 *D_01B003E4;
extern u8 *D_01B003E8;
extern u8 *D_01B003EC;
extern u8 *D_01B003F0;
extern void *D_01B003F4;
extern void *D_01B003F8;
extern int D_01B003FC;
extern TtCfg *D_01B00404;
extern TtHeap D_01B00408;
extern int D_01B004C0;
extern float D_01B004D0[16];
extern int D_01B00510;
extern int D_01B00518;
extern u8 D_01B01510[];
extern u8 D_01B016D0[];
extern u8 D_01B01870[];
extern u8 D_01BB9DC0[];

extern void func_01B00E68(float *, float);
extern void func_01B01288(void *, void *, int);
extern void func_01B01308(void *);
extern int func_01B01460(void *);

extern void func_001072F8(void *, int, float *);
extern int func_00116068(void);
extern int func_0014AA50(int);
extern void func_001A9EE0(void *);
extern void func_001AACA0(void *);
extern int func_001CDAF8(void *);
extern void func_001CDC58(void *, int);
extern void func_001CDDD8(void *);
extern void func_00267530(void *);
extern void func_00267658(void *, int, int, int);
extern void func_002678E0(void *, void *);
extern void func_00267A68(void *, void *, void *, int);
extern int func_00267FA0(void *, int);
extern int func_0029B830(int);
extern void func_002B2730(int);
extern void func_002B2C50(int);
extern int func_002B2E30(void *, int, int, int);
extern void func_002B2F20(int);
extern void func_002B4980(void *);
extern TtCfg *func_002B49A0(void *, int, int);
extern void func_002D02E8(void *, int, int, int);
extern void func_002D05F0(int);
extern void func_002D0698(int);
extern void func_002D0750(int);
extern int func_002D28E8(int, int, int);
extern void func_002DA928(void *, int, int, int, int, int, int, int);
extern void func_002DAB10(void *, int, int, int, int, int, int, int);
extern void func_002DAC50(void *, void *);
extern int func_002DADD0(void *, void *);
extern void func_002DCE08(float *, float *, float *);
extern void func_002DCE38(void *, void *, void *);
extern void func_002DCEC8(float *, float *);
extern void func_002DCF48(float *, float *);
extern void func_002DD0B0(float *, float *);
extern void func_002DD0C0(void *, void *);
extern void func_002F8660(int);

void func_01B00630(void)
{
    func_002DAB10(D_01B01510, 0x2E00, 4, 0, 0, 0, 0x100, 0x100);
    func_002F8660(0);
    func_002DADD0(D_01B01510, D_01B003E4);
    func_002DAB10(D_01B01510 + 0x70, 0x3200, 4, 0, 0, 0, 0x100, 0x100);
    func_002F8660(0);
    func_002DADD0(D_01B01510 + 0x70, D_01B003E8);
    func_002D02E8(D_01B003F4, 0, 0x3E8, 0x2000);
    func_002D05F0(0x2000);
    func_002D0698(0x2000);
    func_002D0750(0x2000);
    func_002B2730(0);
    D_006A3BCC = D_01B003E0;
    func_01B01308(&D_01B00518);
    func_002DA928(D_01B016D0, 0x2E00, 4, 0, 0, 0, 0x100, 0x100);
    func_002F8660(0);
    func_002DAC50(D_01B016D0, D_01B003E4);
    func_002DA928(D_01B016D0 + 0x60, 0x3200, 4, 0, 0, 0, 0x100, 0x100);
    func_002F8660(0);
    func_002DAC50(D_01B016D0 + 0x60, D_01B003E8);
}

int func_01B007B8(TtPObj *o)
{
    D_006A3924 = &D_01B00408;
    func_00267658(o, 0x1000, D_01B00404->w10[0], 1);
    o->x = -16.0f;
    o->y = -13.0f;
    o->z = 259.0f;
    o->w = 1.0f;
    o->rx = 0;
    o->ry = 0;
    o->rz = 0;
    o->rw = 1;
    o->sx = 0.091646f;
    o->sy = 0.091646f;
    o->sz = 0.091646f;
    o->sw = 1.0f;
    return 1;
}

int func_01B00870(TtPObj *o)
{
    float m0[16];
    float m1[16];
    float m2[16];
    float m3[16];
    float v[4];

    func_001A9EE0(m0);
    func_002DCF48(m1, m0);
    func_002DD0C0(D_01B004D0, m1);
    func_002DCE08(v, m1, &o->x);
    func_002DD0B0(&D_01B004D0[12], v);
    func_01B00E68(m3, o->sx);
    func_002DCE38(D_01B004D0, D_01B004D0, m3);
    func_002DD0C0(D_006A3930, D_01B004D0);
    func_002DCE38(D_006A39B0, D_006A3970, D_006A3930);
    func_002DCE38(D_006A3AB0, D_006A3A70, D_006A39B0);
    if (D_01B00518 >= 0x321) {
        D_006A3BC4 = 1;
    }
    D_006A3924 = &D_01B00408;
    if (func_00267FA0(o, 0x30) != 0) {
        D_006A3924 = &D_01B00408;
        func_00267530(o);
        D_006A3924 = &D_01B00408;
        func_00267658(o, 0x1000, D_01B00404->w10[0], 1);
    }
    return 1;
}

int func_01B009D8(TtPObj *o)
{
    D_006A3924 = &D_01B00408;
    func_00267530(o);
    return 1;
}

int func_01B00A08(void *arg)
{
    TtCfg *c;

    D_01B003F8 = arg;
    D_01B003DC = D_01BB9DC0;
    D_01B003E0 = D_01B003DC + 0x80000;
    D_01B003E4 = D_01B003E0 + 0x80000;
    D_01B003E8 = D_01B003E4 + 0x40000;
    D_01B003EC = D_01B003E8 + 0x40000;
    D_01B003F0 = D_01B003EC + 0x40000;
    D_01B003F4 = D_01B01870;
    func_002B4980(D_01B003F4);
    D_01B00404 = func_002B49A0(D_01B003F4, 8, 0);
    func_002678E0(D_01B00404, D_01B00040);
    func_00267A68(&D_01B00408, D_01B00404, D_01B003DC, 0x80000);
    c = D_01B00404;
    D_01B00408.w20 = c->w14;
    D_01B00408.w24 = c->w18;
    D_01B00408.w28 = c->w1c;
    func_01B01288(&D_01B00518, D_01B003B8, 1);
    return 1;
}

int func_01B00B28(void)
{
    return 1;
}

int func_01B00B30(void)
{
    return 1;
}

int func_01B00B38(void)
{
    if (func_00116068() == 0) {
        return 0;
    }
    if (D_01B003D0 == 0) {
        if (func_0029B830(0x2000) != 0) {
            return 1;
        }
        D_01B003D0++;
    }
    if (D_01B003D4 == 0) {
        D_01B003D4 = 1;
        func_001CDC58(D_01B003F8, 0);
    }
    if (D_01B003D8 == 0) {
        if (func_001CDAF8(D_01B003F8) > 0) {
            return ++D_01B003D8;
        }
        return 1;
    }
    return D_01B003D8;
}

int func_01B00BF0(void)
{
    if (D_01B003D8 == 0) {
        return 0;
    }
    {
        /* DEBT(FAKE): pin overlay base to $s0 so lui $s0,0x1B0 fills the jal delay slot. */
        register u8 *base __asm__("$16") = (u8 *)0x01B00000;
        *(volatile int *)(base + 0x510) = func_002D28E8(0, 0, 0);
    }
    D_006A3924 = &D_01B00408;
    func_001AACA0(D_006A3A70);
    func_001A9EE0(D_006A3970);
    D_006A3BCC = D_01B003E0;
    if (func_0014AA50(0) != 0) {
        if (D_01B003B0 == 0) {
            D_01B003FC = func_002B2E30((void *)func_01B00630, 0, 0, 0);
            func_002B2C50(1);
            D_01B003B0++;
        }
    }
    if (func_0014AA50(1) != 0) {
        func_002B2F20(D_01B003FC);
        func_002B2C50(0);
        func_01B01460(&D_01B00518);
        func_001CDDD8(D_01B003F8);
        return 1;
    }
    D_01B004C0++;
    return 1;
}

int func_01B00D10(void)
{
    return 1;
}

int func_01B00D18(void)
{
    return 1;
}

void func_01B00D20(float *m)
{
    func_002DCEC8(m, m);
    func_002DCEC8(m + 4, m + 4);
    func_002DCEC8(m + 8, m + 8);
}

void func_01B00D60(void *a, int b, float *m)
{
    func_001072F8(a, b, m);
    func_01B00D20(m);
}
