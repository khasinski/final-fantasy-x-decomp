#include "common.h"

extern int func_0029B830(int);
extern int func_001CDC58(int, int);
extern int func_001CDAF8(int);

extern int D_01B006A0;
extern int D_01B006A4;
extern int D_01B006A8;
extern int D_01B006C0;

int func_01B02778(void)
{
    if (D_01B006A0 == 0) {
        if (func_0029B830(0x2000) != 0) {
            return 1;
        }
        D_01B006A0 = D_01B006A0 + 1;
    }
    if (D_01B006A4 == 0) {
        D_01B006A4 = 1;
        func_001CDC58(D_01B006C0, 0);
    }
    if (D_01B006A8 == 0) {
        if (func_001CDAF8(D_01B006C0) > 0) {
            D_01B006A8 = D_01B006A8 + 1;
            return D_01B006A8;
        }
        return 1;
    }
    return D_01B006A8;
}
