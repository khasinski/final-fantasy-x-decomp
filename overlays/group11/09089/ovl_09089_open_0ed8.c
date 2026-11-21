/* EE Battle-Effect Overlay: group 0x11, file 09089 (shared with 09710)
 * .text: 0x01B00ED8..0x01B01004 (1 function).
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
extern float D_01B005D0;
extern float D_01B005D4;
extern TtCfg *D_01B005F4;
extern u8 D_01B005F8[];
extern TtPObj D_01B007B0[];
extern void *D_01B008B4;
extern void *D_01B008B8;

extern void func_01B00D60(float *, void *, float, float);
extern void func_00267530(void *);
extern void func_00267658(void *, int, int, int);
extern int func_00267FA0(void *, int);
extern void func_002DCE38(void *, void *, void *);
extern void func_002DD0C0(void *, float *);

int func_01B00ED8(TtPObj *o)
{
    float mtx[16];

    if (o - D_01B007B0 == 0) {
        func_01B00D60(mtx, D_01B008B8, D_01B005D0, o->sx);
    } else {
        func_01B00D60(mtx, D_01B008B4, D_01B005D4, o->sx);
    }
    func_002DD0C0(D_006A3930, mtx);
    func_002DCE38(D_006A39B0, D_006A3970, D_006A3930);
    func_002DCE38(D_006A3AB0, D_006A3A70, D_006A39B0);
    D_006A3924 = D_01B005F8;
    if (func_00267FA0(o, 0x30) != 0) {
        D_006A3924 = D_01B005F8;
        func_00267530(o);
        D_006A3924 = D_01B005F8;
        func_00267658(o, 0x1000, D_01B005F4->w10[13], 1);
    }
    return 1;
}
