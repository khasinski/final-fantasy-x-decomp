/* tu_349 0x2dc110-0x2dc580: medium; unk_2DC110 (config/tu_map.tsv) */
#include "common.h"
#include "vu0.h"
#include "ffx/r7.h"
#include "ffx/q7.h"
#include "ffx/w11.h"
#include "ffx/v7.h"

int func_002DC1A0(void)
{
    int r = 0;

    switch (func_002DC2D0()) {
    case 4: {
        u32 v;

        VU0_CFC2_NI(v, 28);
        VU0_CTC2_NI(28, v | 1);
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

int func_002DC200(void)
{
    int r = 0;
    int n = func_002DC2D0();

    if (n < 4) {
        if (n > 0) {
            r = 1;
            func_002DC310(func_002DC320());
        }
    }
    return r;
}
