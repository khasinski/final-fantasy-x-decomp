/* tu_028 0x11a428-0x11a538: low; ~Sg (config/tu_map.tsv) */
#include "common.h"
#include "ffx/q0.h"
#include "ffx/r0.h"
#include "ffx/u0.h"
#include "ffx/v0.h"
#include "ffx/g0.h"

s8 func_0011A428(void)
{
    return D_00580822;
}

void func_0011A438(const char *s)
{
    D_00307F08 = (s32)func_0011D640(s); /* DEBT(TYPE): D_00307F08 holds a char * */
}

s8 func_0011A460(void)
{
    return D_00580820;
}

s32 Sg_GetUserName(void)
{
    return D_00307F08;
}

char *func_0011A480(void)
{
    return func_0011A460() ? D_00569AD0 : (char *)D_00307F08; /* DEBT(TYPE): D_00307F08 is declared s32 but holds a string pointer */
}

void SgStrdupD(int a, int b)
{
    ((int (*)(s32))func_00116000)(0); /* DEBT(CAST): caller expects int return */
    D_00580822 = -1;
    D_00580821 = 0;
    D_00580820 = 0;
    if (ffx_debugmode != 0 && a >= 2) {
        func_0011A438(((const char **)b)[1]); /* DEBT(CAST): b is char **argv */
    }
}
