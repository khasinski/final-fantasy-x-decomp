#include "common.h"

extern int D_01B00044;
extern int D_01B006E4;

extern void func_001CDC58(int, int);
extern int func_00294578(int);
extern int func_0029B830(int);
extern void func_002B37A0(void);
extern int func_002D0570(int);

int func_01B09E20(void)
{
top:
    switch (D_01B00044) {
    case 0:
        if (func_0029B830(2) == 0) {
            goto inc;
        }
        return 0;
    case 1:
        if (func_002D0570(2) != 0) {
            return 0;
        }
    inc:
        D_01B00044++;
        goto top;
    case 2:
        if (func_00294578(2) != 0) {
            return 0;
        }
        func_001CDC58(D_01B006E4, 0);
        D_01B00044 = 4;
        break;
    }
    func_002B37A0();
    return 0;
}
