/* EE Battle-Effect Overlay: group 0x11, file 09089
 * .text: 0x01B00E00..0x01B00ED8 (1 function).
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
extern TtCfg *D_01B005F4;
extern u8 D_01B005F8[];
extern TtPObj D_01B007B0[];
extern int D_01B008B0;
extern char D_01B02B60[];

extern void func_01B020A0(const char *, int);
extern void func_00267658(void *, int, int, int);

int func_01B00E00(TtPObj *o)
{
    func_01B020A0(D_01B02B60, D_01B008B0);
    D_006A3924 = D_01B005F8;
    func_00267658(o, 0x1000, D_01B005F4->w10[13], 1);
    o->x = 0.0f;
    o->y = 0.0f;
    o->z = 0.0f;
    o->w = 1.0f;
    o->rx = 0;
    o->ry = 0;
    o->rz = 0;
    o->rw = 1;
    if (o - D_01B007B0 == 0) {
        o->sx = 0.0762439966f;
        o->sy = 0.0762439966f;
        o->sz = 0.0762439966f;
        o->sw = 1.0f;
    } else {
        o->sx = 0.0609951988f;
        o->sy = 0.0609951988f;
        o->sz = 0.0609951988f;
        o->sw = 1.0f;
    }
    return 1;
}
