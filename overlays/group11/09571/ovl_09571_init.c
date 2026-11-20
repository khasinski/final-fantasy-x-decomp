/* EE Battle-Effect Overlay: group 0x11, file 09571
 * .text: 0x01B007E0..0x01B00894 (1 function: ppp part init).
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
} TtPObj;

extern void *D_006A3924;
extern int D_01B005F8;
extern TtCfg *D_01B00608;
extern u8 D_01B00610[];
extern TtPObj D_01B00640;
extern char D_01B01190[];

extern int func_01B00E20(char *, ...);
extern void func_00267658(void *, int, int, int);

int func_01B007E0(void)
{
    func_01B00E20(D_01B01190, D_01B005F8);
    D_006A3924 = D_01B00610;
    func_00267658(&D_01B00640, 0x1000, D_01B00608->w10[0], 1);
    D_01B00640.x = 0.0f;
    D_01B00640.y = 0.0f;
    D_01B00640.z = 0.0f;
    D_01B00640.w = 1.0f;
    D_01B00640.rx = 0;
    D_01B00640.ry = 0;
    D_01B00640.rz = 0;
    D_01B00640.rw = 1;
    D_01B00640.sx = 0.14f;
    D_01B00640.sy = 0.14f;
    D_01B00640.sz = 0.14f;
    D_01B00640.sw = 1.0f;
    return 1;
}
