#include "p7_overlay.h"

/* F3 TU rank 45: target set setup. */

void func_01B01428(int arg)
{
    int chr;

    D_01B005A0.arg = arg;
    D_01B005A0.mode = 0;
    chr = MsGetEff2Chr(arg);
    D_01B005A0.chr = chr;
    D_01B005A0.handle = func_01B03AD0(chr);
    func_01B03B08(arg, &D_01B005A0, MsGetTargetList(arg, &D_01B005A0.count));
}
