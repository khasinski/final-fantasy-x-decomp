#include "common.h"
int Sg_GetCurExecFrames(void);
int func_0029B830(int);
int MsEffectReady(int,int);
int MsEffectMotionLevel(int);
extern int D_01B00570;
extern int D_01B00574;
extern int D_01B00578;
extern int D_01B0057C;

int func_01B01900(void)
{
    return 1;
}

int func_01B01908(void)
{
    if (Sg_GetCurExecFrames() == 0) {
        return 0;
    }
    if (D_01B00570 == 0) {
        if (func_0029B830(0x2000) != 0) {
            return 1;
        }
        D_01B00570 = D_01B00570 + 1;
    }
    if (D_01B00574 == 0) {
        D_01B00574 = 1;
        MsEffectReady(D_01B0057C, 0);
    }
    if (D_01B00578 == 0) {
        if (MsEffectMotionLevel(D_01B0057C) > 0) {
            D_01B00578 = D_01B00578 + 1;
            return D_01B00578;
        }
        return 1;
    }
    return D_01B00578;
}
