#include "common.h"

typedef struct {
    u8 pad00[0x130];
} OvlCtx;

extern OvlCtx D_01B05150[];
extern s8 D_01B05F90[12];

OvlCtx *ovl_09290_1020(void)
{
    int i;
    for (i = 0; i < 12; i++) {
        if (D_01B05F90[i] == 0) {
            D_01B05F90[i] = 1;
            return &D_01B05150[i];
        }
    }
    return 0;
}
