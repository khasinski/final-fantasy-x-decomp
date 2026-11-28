#include "common.h"

extern int D_01B007DC;
extern int D_006A3BC4;
extern void *D_006A3924;
extern u8 D_01B00800[];
extern u8 D_006A3A70[];
extern u8 D_006A3970[];
extern void *D_01B007E4;
extern void *D_006A3BCC;
extern u8 D_01B00AA8[];
extern int D_01B007F0;
extern int D_01B009B0;

extern int Sg_GetCurExecFrames(void);
extern void func_001AACA0(void *);
extern void func_001A9EE0(void *);
extern int func_01B029B8(void *);
extern void MsEffectTerminate(int);

int func_01B02308(void)
{
    if (D_01B007DC == 0) {
        return 0;
    }
    D_006A3BC4 = 0;
    if (Sg_GetCurExecFrames() == 0) {
        D_006A3BC4 = 1;
    }
    D_006A3924 = D_01B00800;
    func_001AACA0(D_006A3A70);
    func_001A9EE0(D_006A3970);
    D_006A3BCC = D_01B007E4;
    if (func_01B029B8(D_01B00AA8) == 0) {
        MsEffectTerminate(D_01B007F0);
        return 1;
    }
    D_01B009B0++;
    return 1;
}
