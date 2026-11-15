/* tu_350 0x2dc580-0x2dce38: medium; ~FFXVu0ApplyMatrix (config/tu_map.tsv) */
#include "common.h"
#include "vu0.h"
#include "ffx/r7.h"
#include "ffx/q7.h"
#include "ffx/w11.h"
#include "ffx/v7.h"

void func_002DC638(void)
{
    int status;

    VU0_CFC2_NI(status, 28);
    status |= 0x200;
    VU0_CTC2_NI(28, status);
}
