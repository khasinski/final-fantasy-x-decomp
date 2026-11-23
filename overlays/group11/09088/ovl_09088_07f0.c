#include "common.h"

extern int D_01B02C40;
extern int D_01B02C44;
extern void *D_01B00000[8];
extern void func_01B00890(void);
extern void func_01B008B0(void);
extern void func_01B00958(void);
extern int func_0029B830(int);
extern void func_001CDC58(int, int);
extern int func_001CDAF8(int);

int func_01B007F0(void)
{
    if (func_0029B830(D_01B02C40) != 0) {
        return 0;
    }
    if (D_01B02C44 == 0) {
        int one = 1;
        func_001CDC58(D_01B02C40, one);
        D_01B02C44 = one;
    }
    if (func_001CDAF8(D_01B02C40) <= 0) {
        return 0;
    }
    func_01B00958();
    D_01B00000[3] = (void *)func_01B00890;
    D_01B00000[4] = (void *)func_01B008B0;
    return 0;
}
