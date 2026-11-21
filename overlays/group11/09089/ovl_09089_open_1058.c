/* EE Battle-Effect Overlay: group 0x11, file 09089
 * .text: 0x01B01058..0x01B011E4 (2 functions).
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
extern TtCfg *D_01B005F4;
extern u8 D_01B005F8[];
extern int D_01B008B0;
extern char D_01B02B90[];

extern void func_01B020A0(const char *, int);
extern void func_01B02430(float *, int, float *, int, float, float);
extern void func_002675B0(void *);
extern void func_00267658(void *, int, int, int);
extern int func_00267FA0(void *, int);
extern void func_002DCE38(void *, void *, void *);

int func_01B01058(TtPObj *o)
{
    func_01B020A0(D_01B02B90, D_01B008B0);
    D_006A3924 = D_01B005F8;
    func_00267658(o, 0x1000, D_01B005F4->w10[2], 1);
    o->x = -36.6400146f;
    o->y = 0.300000012f;
    o->z = -9.73992825f;
    o->w = 1.0f;
    o->rx = 0;
    o->ry = 0;
    o->rz = 0;
    o->rw = 1;
    o->sx = 0.00193999999f;
    o->sy = 0.00193999999f;
    o->sz = 0.00193999999f;
    o->sw = 1.0f;
    return 1;
}

int func_01B01130(TtPObj *o)
{
    func_01B02430(&o->x, 0, &o->sx, 1, 0.100000001f, 9.99999975e-06f);
    func_002675B0(o);
    func_002DCE38(D_006A39B0, D_006A3970, D_006A3930);
    func_002DCE38(D_006A3AB0, D_006A3A70, D_006A39B0);
    D_006A3924 = D_01B005F8;
    return func_00267FA0(o, 0x30) == 0;
}
