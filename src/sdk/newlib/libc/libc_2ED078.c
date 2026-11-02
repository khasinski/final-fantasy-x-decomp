/* tu_361 0x2ed078-0x2ed128: low; ~atoi (config/tu_map.tsv) */
#include "common.h"
#include "ffx/r7.h"
#include "ffx/q7.h"
#include "ffx/w11.h"
#include "ffx/v7.h"

double func_002ED078(const char *s)
{
    return func_002F1D20(s, 0);
}

int func_002ED098(const char *s)
{
    return func_002F2078(s, 0, 10);
}

long func_002ED0C0(const char *s)
{
    return func_002F2078(s, 0, 10);
}

void func_002ED0E0(u8 *p, u32 n)
{
    while (n-- != 0) {
        *p++ = 0;
    }
}

W11Reent *func_002ED118(void)
{
    return D_005681A4;
}
