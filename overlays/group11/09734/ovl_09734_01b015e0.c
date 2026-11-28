#include "common.h"

extern int D_01B009B4;
extern float D_01B007AC;
extern u8 D_006A3930[];
extern u8 D_006A3970[];
extern u8 D_006A39B0[];
extern u8 D_006A3A70[];
extern u8 D_006A3AB0[];
extern void *D_006A3924;
extern u8 D_01B00800[];

extern void pppSetMatrix(void *);
extern void func_002DCE38(void *, void *, void *);
extern int _pppRunPart(void *, int);

int func_01B015E0(u8 *s1)
{
    if (D_01B009B4 == 0) {
        return 0;
    }
    {
        float f = D_01B007AC;
        *(float *)(s1 + 0x6C) = 1.0f;
        *(float *)(s1 + 0x60) = f;
        *(float *)(s1 + 0x64) = f;
        *(float *)(s1 + 0x68) = f;
    }
    pppSetMatrix(s1);
    func_002DCE38(D_006A39B0, D_006A3970, D_006A3930);
    func_002DCE38(D_006A3AB0, D_006A3A70, D_006A39B0);
    D_006A3924 = D_01B00800;
    return _pppRunPart(s1, 0x30) == 0;
}
