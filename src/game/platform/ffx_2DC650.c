/* tu_350 0x2dc580-0x2dce38: medium; ~FFXVu0ApplyMatrix (config/tu_map.tsv) */
#include "common.h"
#include "vu0.h"
#include "ffx/r7.h"
#include "ffx/q7.h"
#include "ffx/w11.h"
#include "ffx/v7.h"

int func_002DC650(void)
{
    int r = 0;

    switch (func_002DC780()) {
    case 4: {
        u32 v;

        VU0_CFC2_NI(v, 28);
        VU0_CTC2_NI(28, v | 0x100);
    }
    /* fallthrough */
    case 0:
    case 3:
        r = 1;
        break;
    case 1:
    case 2:
        break;
    }
    return r;
}

int func_002DC6B0(void)
{
    int r = 0;
    int n = func_002DC780();

    if (n < 4) {
        if (n > 0) {
            r = 1;
            func_002DC7C8(func_002DC7D8());
        }
    }
    return r;
}
