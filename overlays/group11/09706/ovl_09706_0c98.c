#include "common.h"
extern int D_01B00400, D_01B003D8, D_01B00648, D_01B00424, D_01B00420, D_01B004E0;
extern void *D_01B00530, *D_01B00408, *D_006A3924, *D_006A3BCC;
extern u8 D_01B00430[], D_006A3A70[], D_006A3970[], D_01B00658[], D_01B00538[];
extern void *func_002D28E8(int, int, int);
extern void func_001AACA0(void *);
extern void func_001A9EE0(void *);
extern int func_0014AA50(int);
extern int func_002B2E30(void *, int, int, int);
extern void func_002B2C50(int);
extern void func_002B2F20(int);
extern int func_01B015A0(void *);
extern void func_001CDDD8(int);

int func_01B00C98(void) {
    if (D_01B00400 == 0) {
        return 0;
    }
    { /* DEBT(FAKE): pin s0 for &D_01B00530 across call */ register void **p530 __asm__("$16") = &D_01B00530; *p530 = func_002D28E8(0, 0, 0); }
    D_006A3924 = D_01B00430;
    func_001AACA0(D_006A3A70);
    func_001A9EE0(D_006A3970);
    D_006A3BCC = D_01B00408;
    if (func_0014AA50(0) && D_01B003D8 == 0) {
        D_01B00648 = 0;
        D_01B00424 = func_002B2E30(D_01B00658, 0, 0, 0);
        func_002B2C50(1);
        D_01B003D8++;
    }
    if (func_0014AA50(1)) {
        func_002B2F20(D_01B00424);
        func_002B2C50(0);
        func_01B015A0(D_01B00538);
        func_001CDDD8(D_01B00420);
        return 1;
    }
    D_01B004E0++;
    return 1;
}
