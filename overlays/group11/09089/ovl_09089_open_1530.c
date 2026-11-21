/* EE Battle-Effect Overlay: group 0x11, file 09089
 * .text: 0x01B01530..0x01B01808 (2 functions).
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
    u8 pad70[0x10];
} TtPObj;

extern void *D_006A3924;
extern u8 D_006A3930[];
extern u8 D_006A3970[];
extern u8 D_006A39B0[];
extern u8 D_006A3A70[];
extern u8 D_006A3AB0[];
extern float D_01B00540[];
extern float D_01B005C8;
extern float D_01B005CC;
extern TtCfg *D_01B005F4;
extern u8 D_01B005F8[];
extern int D_01B008B0;
extern void *D_01B008B4;
extern float D_01B008C0[];
extern char D_01B02BF0[];

extern void func_01B01C38(void *, int, float *);
extern void func_01B01D38(float *, float);
extern void func_01B020A0(const char *, int);
extern void func_01B02430(float *, int, float *, int, float, float);
extern void func_001A9EE0(float *);
extern void func_00267530(void *);
extern void func_00267658(void *, int, int, int);
extern int func_00267FA0(void *, int);
extern void func_002DCE08(float *, float *, float *);
extern void func_002DCE38(void *, void *, void *);
extern void func_002DCF48(float *, float *);
extern void func_002DD0B0(float *, float *);
extern void func_002DD0C0(void *, float *);
extern void func_002DD128(float *);
extern void func_002DD270(float *, float *, float);

int func_01B01530(TtPObj *o)
{
    float m0[16];
    float m1[16];

    func_01B020A0(D_01B02BF0, D_01B008B0);
    D_006A3924 = D_01B005F8;
    func_00267658(o, 0x1000, D_01B005F4->w10[1], 1);
    o->x = -33.2944336f;
    o->y = -1.60089302f;
    o->z = -17.7085419f;
    o->w = 1.0f;
    o->rx = 0;
    o->ry = -0x728B;
    o->rz = 0;
    o->rw = 1;
    o->sx = 0.00925000012f;
    o->sy = 0.00925000012f;
    o->sz = 0.00925000012f;
    o->sw = 1.0f;
    func_001A9EE0(m0);
    func_002DCF48(m1, m0);
    func_002DD0C0(D_01B008C0, m1);
    func_002DD0B0(&D_01B008C0[12], &o->x);
    return 1;
}

int func_01B01650(TtPObj *o)
{
    float m0[16];
    float m1[16];
    float m2[16];
    float v[4];
    float m3[16];

    func_01B02430(D_01B00540, 0, &o->sx, 1, 0.25f, 9.99999975e-06f);
    func_01B01C38(D_01B008B4, (int)D_01B005C8, m0);
    func_002DD0C0(D_01B008C0, m0);
    func_002DD128(m3);
    func_002DD270(m3, m3, D_01B005CC);
    func_002DCE38(D_01B008C0, m0, m3);
    func_002DCE08(v, m0, D_01B00540);
    func_002DD0B0(&D_01B008C0[12], v);
    func_01B01D38(m2, o->sx);
    func_002DCE38(m1, D_01B008C0, m2);
    func_002DD0C0(D_006A3930, m1);
    func_002DCE38(D_006A39B0, D_006A3970, D_006A3930);
    func_002DCE38(D_006A3AB0, D_006A3A70, D_006A39B0);
    D_006A3924 = D_01B005F8;
    if (func_00267FA0(o, 0x30) != 0) {
        D_006A3924 = D_01B005F8;
        func_00267530(o);
        D_006A3924 = D_01B005F8;
        func_00267658(o, 0x1000, D_01B005F4->w10[1], 1);
    }
    return 1;
}
