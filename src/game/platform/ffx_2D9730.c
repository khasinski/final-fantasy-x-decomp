/* tu_347 0x2d9730-0x2dba00: low; libgraph (config/tu_map.tsv) */
#include "common.h"
#include "ffx/q7.h"
#include "ffx/w11.h"
#include "ffx/g4.h"
#include "ffx/r7.h"
#include "ffx/v7.h"

int TkIsDebug(void)
{
    int ret = 0;

    if (D_00576479 != 0) {
        ret = ffx_debugmode != 0;
    }
    return ret;
}

s8 FFXIsPC(void)
{
    return D_00576479;
}

s8 FFXIsDebug(void)
{
    return ffx_debugmode;
}

void func_002D9778(int on)
{
    if (D_00576479 != 0) {
        if (on) {
            on = 1;
        }
        ffx_debugmode = on;
    }
}

void func_002D97A0(int v)
{
    D_00567EB0 = v;
}

s8 func_002D97B0(void)
{
    return D_00567EB0;
}

void func_002D97C8(int v)
{
    func_002D97A0(v);
}

int FFXGetLang(void)
{
    return func_002D97B0();
}

extern char D_00576468[];

void FFXSetVideoMode(int a)
{
    if ((u32)a >= 2) {
        a = 0;
    }
    D_00567EB1 = a;
    switch (a) {
    case 0:
        func_002D63D8(0);
        break;
    case 1:
        func_002D63D8(1);
        break;
    }
    func_002EF240(D_00576468, (s8)D_00567EB1);
}

s8 func_002D9868(void)
{
    return D_00567EB1;
}

u8 func_002D9880(void)
{
    return D_00567EB3;
}

void func_002D9890(int v)
{
    D_00567EB3 = v;
}

int func_002D98A0(void)
{
    return 1;
}
