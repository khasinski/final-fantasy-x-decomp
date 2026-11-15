#include "common.h"
int Sg_GetCurExecFrames(void);
int func_0029B830(int);
int MsEffectReady(int,int);
int MsEffectMotionLevel(int);
extern int D_01B00850;
extern int D_01B00854;
extern int D_01B00858;
extern int D_01B00870;

int func_01B03510(void)
{
    if (D_01B00850 == 0) {
        if (func_0029B830(0x2000) != 0) {
            return 1;
        }
        D_01B00850 = D_01B00850 + 1;
    }
    if (D_01B00854 == 0) {
        D_01B00854 = 1;
        MsEffectReady(D_01B00870, 0);
    }
    if (D_01B00858 == 0) {
        if (MsEffectMotionLevel(D_01B00870) > 0) {
            D_01B00858 = D_01B00858 + 1;
            return D_01B00858;
        }
        return 1;
    }
    return D_01B00858;
}
