#include "common.h"
int Sg_GetCurExecFrames(void);
int func_0029B830(int);
int MsEffectReady(int,int);
int MsEffectMotionLevel(int);
extern int D_01B004E8;
extern int D_01B004EC;
extern int D_01B004F0;
extern int D_01B00504;

int func_01B19F50(void)
{
    return 1;
}

int func_01B19F58(void)
{
    return 1;
}

int func_01B19F60(void)
{
    if (D_01B004E8 == 0) {
        if (func_0029B830(0x2000) != 0) {
            return 1;
        }
        D_01B004E8 = D_01B004E8 + 1;
    }
    if (D_01B004EC == 0) {
        D_01B004EC = 1;
        MsEffectReady(D_01B00504, 0);
    }
    if (D_01B004F0 == 0) {
        if (MsEffectMotionLevel(D_01B00504) > 0) {
            D_01B004F0 = D_01B004F0 + 1;
            return D_01B004F0;
        }
        return 1;
    }
    return D_01B004F0;
}
