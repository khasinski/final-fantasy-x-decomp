/* Battle-effect overlay 09531: byte-exact C helpers and callbacks. */
#include "common.h"






extern int D_01B00440;
extern int D_01B00444;
extern int D_01B00448;
extern int D_01B0044C;


int Sg_GetCurExecFrames(void);
int func_0029B830(int a);
int MsEffectReady(int id, int flag);
int MsEffectMotionLevel(int id);


int func_01B00E78(void)
{
    return 1;
}

int func_01B00E80(void)
{
    return 1;
}

int func_01B00E88(void)
{
    if (Sg_GetCurExecFrames() == 0) {
        return 0;
    }
    if (D_01B00440 == 0) {
        if (func_0029B830(0x2000) != 0) {
            return 1;
        }
        D_01B00440 = D_01B00440 + 1;
    }
    if (D_01B00444 == 0) {
        D_01B00444 = 1;
        MsEffectReady(D_01B0044C, 0);
    }
    if (D_01B00448 == 0) {
        if (MsEffectMotionLevel(D_01B0044C) > 0) {
            D_01B00448 = D_01B00448 + 1;
            return D_01B00448;
        }
        return 1;
    }
    return D_01B00448;
}
