#include "common.h"

int func_00116068(void);
int func_0029B830(int);
int func_001CDC58(int, int);
int func_001CDAF8(int);

extern int D_01B007D4;
extern int D_01B007D8;
extern int D_01B007DC;
extern int D_01B007F0;

int func_01B02250(void)
{
    if (func_00116068() == 0) {
        return 0;
    }
    if (D_01B007D4 == 0) {
        if (func_0029B830(0x2000) != 0) {
            return 1;
        }
        D_01B007D4 = D_01B007D4 + 1;
    }
    if (D_01B007D8 == 0) {
        D_01B007D8 = 1;
        func_001CDC58(D_01B007F0, 1);
    }
    if (D_01B007DC == 0) {
        if (func_001CDAF8(D_01B007F0) > 0) {
            D_01B007DC = D_01B007DC + 1;
            return D_01B007DC;
        }
        return 1;
    }
    return D_01B007DC;
}
