#include "common.h"
int Sg_GetCurExecFrames(void);
int func_0029B830(int);
int MsEffectReady(int,int);
int MsEffectMotionLevel(int);
extern int D_01B007B8;
extern int D_01B007BC;
extern int D_01B007C0;
extern int D_01B007D8;

int func_01B030B0(void)
{
    if (Sg_GetCurExecFrames() == 0) {
        return 0;
    }
    if (D_01B007B8 == 0) {
        if (func_0029B830(0x2000) != 0) {
            return 1;
        }
        D_01B007B8 = D_01B007B8 + 1;
    }
    if (D_01B007BC == 0) {
        D_01B007BC = 1;
        MsEffectReady(D_01B007D8, 0);
    }
    if (D_01B007C0 == 0) {
        if (MsEffectMotionLevel(D_01B007D8) > 0) {
            D_01B007C0 = D_01B007C0 + 1;
            return D_01B007C0;
        }
        return 1;
    }
    return D_01B007C0;
}
