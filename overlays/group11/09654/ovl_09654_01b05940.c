#include "common.h"

extern int g_fn_getchr(int);
extern int func_001BC1D0(int);

int func_01B05940(int idx)
{
    return func_001BC1D0(g_fn_getchr(idx)) == 0;
}
