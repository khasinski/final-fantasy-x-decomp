/* Battle-effect overlay 09580: byte-exact C helpers and callbacks. */
#include "common.h"

typedef struct TtEnt {
    int start;
    int len;
    void (*on_start)(int);
    int (*on_run)(int);
    void (*on_end)(int);
    int arg;
} TtEnt;

typedef struct TtRing {
    int frame;
    int n;
    int active;
    struct {
        int on;
        int pad;
    } slot[32];
    TtEnt *tbl;
} TtRing;


typedef struct TtHeap {
    u8 pad00[0x20];
    int w20;
    void **w24;
    char *w28;
} TtHeap;


extern int D_01B00598;
extern int D_01B0059C;
extern int D_01B005A0;
extern u8 *D_01B005A8;
extern int D_01B005AC;
extern TtHeap D_01B005B8;
extern int D_01B008F4;
extern TtRing D_01B008F8;
extern char D_01B01978[];

extern void *D_006A3924;
extern u8 D_006A3970[];
extern u8 D_006A3A70[];
extern int D_006A3BCC;

int Sg_GetCurExecFrames(void);
int func_0029B830(int a);
int MsEffectReady(int id, int flag);
int MsEffectMotionLevel(int id);
void MsEffectTerminate(int id);
void func_001AACA0(void *m);
void func_001A9EE0(void *m);
int func_0014AA50(int a);

int func_01B01570(char *fmt, ...);
int func_01B016C8(TtRing *r);
int func_01B01820(TtRing *r);

int func_01B00F98(void)
{
    return 1;
}

int func_01B00FA0(void)
{
    if (Sg_GetCurExecFrames() == 0) {
        return 0;
    }
    if (D_01B00598 == 0) {
        if (func_0029B830(0x2000) != 0) {
            return 1;
        }
        D_01B00598 = D_01B00598 + 1;
    }
    if (D_01B0059C == 0) {
        D_01B0059C = 1;
        MsEffectReady(D_01B005AC, 0);
    }
    if (D_01B005A0 == 0) {
        if (MsEffectMotionLevel(D_01B005AC) > 0) {
            D_01B005A0 = D_01B005A0 + 1;
            return D_01B005A0;
        }
        return 1;
    }
    return D_01B005A0;
}

int func_01B01058(void)
{
    if (D_01B005A0 == 0) {
        return 0;
    }
    D_006A3924 = &D_01B005B8;
    func_001AACA0(D_006A3A70);
    func_001A9EE0(D_006A3970);
    D_006A3BCC = (int)D_01B005A8;
    if (func_0014AA50(0) != 0) {
        func_01B016C8(&D_01B008F8);
    }
    if (func_0014AA50(1) != 0) {
        func_01B01820(&D_01B008F8);
        func_01B01570(D_01B01978, D_01B008F4);
        MsEffectTerminate(D_01B005AC);
        return 1;
    }
    D_01B008F4 = D_01B008F4 + 1;
    return 1;
}

int func_01B01120(void)
{
    return 1;
}

int func_01B01128(void)
{
    return 1;
}
