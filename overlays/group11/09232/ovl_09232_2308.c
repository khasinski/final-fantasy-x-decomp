/* Shared 09142 (0x01B02AD0..0x01B02B8C) & 09395 (0x01B035A0..0x01B0365C). */
#include "common.h"

extern int D_01B00840;
extern int D_01B00844;
extern int D_01B00848;
extern int D_01B0085C;

extern int func_00116068(void);
extern int func_001CDAF8(int);
extern void func_001CDC58(int, int);
extern int func_0029B830(int);

int func_01B02AD0(void)
{
    if (func_00116068() == 0) {
        return 0;
    }
    if (D_01B00840 == 0) {
        if (func_0029B830(0x2000) != 0) {
            return 1;
        }
        D_01B00840++;
    }
    if (D_01B00844 == 0) {
        D_01B00844 = 1;
        func_001CDC58(D_01B0085C, 1);
    }
    if (D_01B00848 == 0) {
        if (func_001CDAF8(D_01B0085C) > 0) {
            D_01B00848++;
        } else {
            return 1;
        }
    }
}
