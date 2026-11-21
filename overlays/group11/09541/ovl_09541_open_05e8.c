/* EE Battle-Effect Overlay: group 0x11, file 09541
 * .text: 0x01B005E8..0x01B008C4 (4 functions).
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
extern float D_01B003B8;
extern TtCfg *D_01B003D8;
extern u8 D_01B003E0[];
extern int D_01B00490;
extern void *D_01B00494;
extern float D_01B004A0[4];
extern char D_01B022B8[];
extern char D_01B022D0[];
extern char D_01B022E8[];

extern void func_01B010B8(const char *, int);
extern void func_01B01438(float *, int, int);
extern void func_01B01FA0(float *, float);
extern void func_00107BE8(void *, int);
extern void func_0010D720(void);
extern void func_0010D728(int);
extern void func_0010DB58(int, int, int, int, int, float, float, float, float);
extern void func_0010DC38(void *, int);
extern void func_00267658(void *, int, int, int);

int func_01B005E8(void)
{
    int i;

    func_01B010B8(D_01B022B8, D_01B00490);
    D_01B004A0[0] = -7.69987011f;
    D_01B004A0[1] = -86.8999557f;
    D_01B004A0[2] = 57.1000443f;
    D_01B004A0[3] = 1.0f;
    func_0010D728(3);
    for (i = 0; i < 3; i++) {
        func_0010DB58(i, 0xFF, 0xFF, 0xFF, i, D_01B004A0[0], D_01B004A0[1], D_01B004A0[2], D_01B003B8);
    }
    func_0010DC38(D_01B00494, 7);
    func_00107BE8(D_01B00494, 1);
    return 1;
}

int func_01B006F0(void)
{
    int i;

    func_01B01438(D_01B004A0, 0, 0);
    for (i = 0; i < 3; i++) {
        func_0010DB58(i, 0xFF, 0xFF, 0xFF, i, D_01B004A0[0], D_01B004A0[1], D_01B004A0[2], D_01B003B8);
    }
    func_01B01FA0(D_01B004A0, D_01B003B8);
    return 1;
}

int func_01B007A0(void)
{
    func_01B010B8(D_01B022D0, D_01B00490);
    func_00107BE8(D_01B00494, 0);
    func_0010DC38(D_01B00494, 0);
    func_0010D720();
    return 1;
}

int func_01B007F8(TtPObj *o)
{
    func_01B010B8(D_01B022E8, D_01B00490);
    D_006A3924 = D_01B003E0;
    func_00267658(o, 0x1000, D_01B003D8->w10[0], 1);
    o->x = -13.0f;
    o->y = -81.0f;
    o->z = 49.0f;
    o->w = 1.0f;
    o->rx = 0;
    o->ry = 0x2000;
    o->rz = 0;
    o->rw = 1;
    o->sx = 0.175595999f;
    o->sy = 0.175595999f;
    o->sz = 0.175595999f;
    o->sw = 1.0f;
    return 1;
}
