#include "p7_overlay.h"

/* F3 TU rank 43: chr data load / dispose and misc wrappers. */

void func_01B02D80(int a0)
{
    Ch_DataRead(a0);
    ChN_ReadSystemMGRPstart(a0, 1);
}

int func_01B02DB0(int a0)
{
    if (Ch_DataReadSync(a0) != 0) {
        return 0;
    }
    return ChN_ReadSystemMGRPsync(a0, 1) == 0;
}

int func_01B02DF0(int a0)
{
    int r = func_00102B98(a0);

    ChN_ReadSystemMGRP(a0, 1);
    return r;
}

void func_01B02E30(int a0)
{
    ChN_DisposeSystemMGRP(a0, 1);
    ChN_DataDispose(a0, 0);
}

void func_01B02E60(int a0, u16 a1, u16 a2)
{
    func_002D02E8(a0, a1, a2, 1);
}

int func_01B02E70(void)
{
    int r = 1;

    if (func_002D0570(1) != 0) {
        func_002D05F0(1);
        r = 0;
    }
    return r;
}

void func_01B02EB0(void)
{
    MsBattleSpecialCameraPause(1);
}
