#include "common.h"

typedef struct StepEnt {
    u8 pad00[0x24];
    int target;        /* 0x24 */
} StepEnt;             /* 0x28 */

extern StepEnt *D_01B1D4A0;
extern int D_01B1D4A4;
extern int D_01B1D4A8;

int func_01B060D0(void);
void func_01B064B0(StepEnt *);

void func_01B065A0(void)
{
    int v;

    v = func_01B060D0();
    if (D_01B1D4A0 != 0) {
        D_01B1D4A4++;
        if (v == D_01B1D4A0->target) {
            D_01B1D4A0++;
            D_01B1D4A4 = 0;
            D_01B1D4A8++;
            func_01B064B0(D_01B1D4A0);
            __asm__ volatile("");
        }
    }
}
