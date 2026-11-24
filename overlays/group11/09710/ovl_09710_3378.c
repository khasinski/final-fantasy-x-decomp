#include "common.h"

extern int D_01B00540;
extern int D_01B00544;
extern int D_01B007EC;
extern int D_01B007F4;
extern int D_01B007F8;
extern u8 D_01B00808;
extern int D_01B012C0;
extern u8 D_01B012D0;
extern u8 D_01B013E0;
extern u8 D_01B014F0;
extern char D_01B04DE0[];

extern void *D_006A3924;
extern u8 D_006A3970;
extern u8 D_006A3A70;
extern int D_006A3BCC;

extern int func_01B03970(char *, ...);
extern int func_01B03AD8(void *);
extern int func_01B03C30(void *);
extern int func_0014AA50(int);
extern void func_001A9EE0(void *);
extern void func_001AACA0(void *);
extern void func_001CDDD8(int);

int func_01B03378(void)
{
    if (D_01B007EC == 0) {
        return 0;
    }
    D_006A3924 = &D_01B00808;
    func_001AACA0(&D_006A3A70);
    func_001A9EE0(&D_006A3970);
    D_006A3BCC = D_01B007F4;
    if (func_0014AA50(0) != 0) {
        func_01B03AD8(&D_01B012D0);
    }
    if (func_0014AA50(1) != 0) {
        if (D_01B00540 == 0) {
            D_01B00540 = 1;
            func_01B03C30(&D_01B012D0);
        }
        func_01B03AD8(&D_01B013E0);
    }
    if (func_0014AA50(2) != 0) {
        if (D_01B00544 == 0) {
            D_01B00544 = 1;
            func_01B03C30(&D_01B013E0);
        }
        func_01B03AD8(&D_01B014F0);
    }
    if (func_0014AA50(3) != 0) {
        func_01B03C30(&D_01B014F0);
        func_01B03970(D_01B04DE0, D_01B012C0);
        func_001CDDD8(D_01B007F8);
        return 1;
    } else {
        D_01B012C0++;
    }
    return 1;
}
