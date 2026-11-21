/* EE Battle-Effect Overlay: group 0x11, file 09685
 * .text: 0x01B01778..0x01B02080 (11 functions).
 */
#include "common.h"

typedef struct TtCfg {
    u8 pad00[0x10];
    int *w10;
} TtCfg;

typedef struct TtPObj {
    u8 pad00[0x40];
    float x, y, z, w;
    int rx, ry, rz, rw;
    float sx, sy, sz, sw;
    u8 pad70[0x6];
    s16 h76;
    u8 pad78[0x8];
} TtPObj;

extern void *D_006A3924;
extern u8 D_006A3930[];
extern u8 D_006A3970[];
extern u8 D_006A39B0[];
extern u8 D_006A3A70[];
extern u8 D_006A3AB0[];
extern float D_01B00380;
extern float D_01B00384;
extern float D_01B00390[9][4];
extern float D_01B00420;
extern float D_01B00428[9];
extern TtCfg *D_01B00474;
extern u8 D_01B00478[];
extern int D_01B00E70;
extern s32 D_01B00E80[9];
extern s32 D_01B00EA8[9];
extern s32 D_01B00ED0[9];
extern s32 D_01B00EF8[9];
extern float D_01B00F20[9];
extern float D_01B00F48[9];
extern s32 D_01B00F70[9];
extern char D_01B043F8[];
extern char D_01B04410[];
extern char D_01B04428[];
extern char D_01B04440[];
extern char D_01B04458[];
extern char D_01B04470[];
extern char D_01B04488[];

extern void func_01B025A8(float *, float);
extern int func_01B02910(const char *, int);
extern void func_01B04080(void *, float);
extern void func_001A9EE0(float *);
extern void func_00267530(void *);
extern void func_00267658(void *, int, int, int);
extern void func_00267FA0(void *, int);
extern void func_002DCE08(float *, float *, float *);
extern void func_002DCE38(void *, void *, void *);
extern void func_002DCF48(float *, float *);
extern void func_002DD020(float *, float *, float *);
extern void func_002DD0C0(void *, void *);

static inline float clamp_val(float v, float lo, float hi)
{
    if (v < lo) {
        return lo;
    }
    if (v > hi) {
        return hi;
    }
    return v;
}

static inline void clamp_f(float *p, float lo, float hi)
{
    *p = clamp_val(*p, lo, hi);
}

void func_01B01778(int flag)
{
    int i;

    for (i = 0; i < 9; i++) {
        if (D_01B00E80[i] == 1 && D_01B00ED0[i] == 0) {
            D_01B00ED0[i] = 1;
            D_01B00F20[i] = 1.0f;
            func_01B02910(D_01B043F8, i);
        } else if (D_01B00E80[i] == 0 && D_01B00EA8[i] == 1) {
            func_01B02910(D_01B04410, i);
            D_01B00F48[i] = 1.0f;
            if (flag != 0) {
                D_01B00EF8[i] = 1;
                func_01B02910(D_01B04428, i);
                D_01B00F70[i] = 0x18;
            }
        }
        if (D_01B00F48[i] == 1.0f) {
            D_01B00F20[i] -= 0.125f;
            clamp_f(&D_01B00F20[i], 0.0f, 1.0f);
            if (D_01B00F20[i] == 0.0f) {
                D_01B00ED0[i] = 0;
                func_01B02910(D_01B04440, i);
                D_01B00F48[i] = 0.0f;
            }
        }
        if (D_01B00EF8[i] != 0) {
            if (--D_01B00F70[i] == 0) {
                D_01B00EF8[i] = 0;
                func_01B02910(D_01B04458, i);
            }
        }
    }
}

void func_01B019A8(TtPObj *o)
{
    D_006A3924 = D_01B00478;
    func_00267658(o, 0x1000, D_01B00474->w10[0], 1);
    o->x = 0.0f;
    o->y = 0.0f;
    o->z = 0.0f;
    o->w = 1.0f;
    o->rx = 0;
    o->ry = 0;
    o->rz = 0;
    o->rw = 1;
    o->sx = 1.0f;
    o->sy = 1.0f;
    o->sz = 1.0f;
    o->sw = 1.0f;
}

void func_01B01A30(int idx, TtPObj *o)
{
    float m0[16];
    float m1[16];
    float m2[16];
    float m3[4][4];
    float v1[4];

    o->sx = D_01B00384;
    o->sy = D_01B00384;
    o->sz = D_01B00384;
    o->sw = 1.0f;
    func_001A9EE0(m0);
    func_002DCF48(m1, m0);
    func_002DD0C0(m3, m1);
    D_01B00390[idx][2] = D_01B00380;
    func_002DCE08(v1, m3[0], D_01B00390[idx]);
    func_002DD020(m3[3], m3[3], v1);
    func_01B025A8(m2, D_01B00384);
    func_002DCE38(m3, m3, m2);
    func_002DD0C0(D_006A3930, m3);
    func_01B04080(D_006A3930, 50.0f);
    func_002DCE38(D_006A39B0, D_006A3970, D_006A3930);
    func_002DCE38(D_006A3AB0, D_006A3A70, D_006A39B0);
    D_006A3924 = D_01B00478;
    func_00267FA0(o, 0x30);
}

void func_01B01B90(TtPObj *o)
{
    int i;

    for (i = 0; i < 9; i++) {
        func_01B019A8(&o[i]);
    }
}

int func_01B01BD0(TtPObj *o)
{
    int i;

    for (i = 0; i < 9; i++) {
        if (D_01B00EF8[i] != 0) {
            if (D_01B00F70[i] == 0x17) {
                func_01B019A8(&o[i]);
            }
            func_01B01A30(i, &o[i]);
        }
    }
    return 1;
}

int func_01B01C90(TtPObj *o)
{
    int i;

    func_01B02910(D_01B04470, D_01B00E70);
    for (i = 0; i < 9; i++) {
        D_006A3924 = D_01B00478;
        func_00267530(&o[i]);
    }
    return 1;
}

void func_01B01D10(TtPObj *o)
{
    D_006A3924 = D_01B00478;
    func_00267658(o, 0x1000, D_01B00474->w10[1], 1);
    o->x = 0.0f;
    o->y = 0.0f;
    o->z = 0.0f;
    o->w = 1.0f;
    o->rx = 0;
    o->ry = 0;
    o->rz = 0;
    o->rw = 1;
    o->sx = 1.0f;
    o->sy = 1.0f;
    o->sz = 1.0f;
    o->sw = 1.0f;
}

void func_01B01D98(int idx, TtPObj *o, float alpha)
{
    float m0[16];
    float m1[16];
    float m2[16];
    float m3[4][4];
    float v1[4];

    o->sx = D_01B00428[idx];
    o->sy = D_01B00420;
    o->sz = D_01B00420;
    o->sw = 1.0f;
    func_001A9EE0(m0);
    func_002DCF48(m1, m0);
    func_002DD0C0(m3, m1);
    D_01B00390[idx][2] = D_01B00380;
    func_002DCE08(v1, m3[0], D_01B00390[idx]);
    func_002DD020(m3[3], m3[3], v1);
    func_01B025A8(m2, D_01B00420);
    m2[0] = D_01B00428[idx];
    func_002DCE38(m3, m3, m2);
    func_002DD0C0(D_006A3930, m3);
    func_01B04080(D_006A3930, 50.0f);
    func_002DCE38(D_006A39B0, D_006A3970, D_006A3930);
    func_002DCE38(D_006A3AB0, D_006A3A70, D_006A39B0);
    o->h76 = (s16)(alpha * 4096.0f);
    D_006A3924 = D_01B00478;
    func_00267FA0(o, 0x30);
}

void func_01B01F40(TtPObj *o)
{
    int i;

    for (i = 0; i < 9; i++) {
        func_01B01D10(&o[i]);
    }
}

int func_01B01F80(TtPObj *o)
{
    int i;

    for (i = 0; i < 9; i++) {
        if (D_01B00ED0[i] != 0) {
            func_01B01D98(i, &o[i], D_01B00F20[i]);
        }
    }
    return 1;
}

int func_01B02000(TtPObj *o)
{
    int i;

    func_01B02910(D_01B04488, D_01B00E70);
    for (i = 0; i < 9; i++) {
        D_006A3924 = D_01B00478;
        func_00267530(&o[i]);
    }
    return 1;
}
