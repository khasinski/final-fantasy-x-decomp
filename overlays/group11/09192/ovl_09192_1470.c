#include "common.h"

typedef struct {
    u8 pad00[0x10];
    s8 b10;
    s8 b11;
} Struct4990;

extern int D_00704014;
extern int D_0054D5EC;
extern Struct4990 D_00764990;

extern int MsGetEff2Chr(int);
extern float MsGetChrBtlDir(int);
extern void MsSetChrDirF(int, float);
extern void func_0206C3B8(int);

void ovl_09192_1470(void)
{
    volatile int unused;
    int chr;
    register Struct4990 *p __asm__("$3");

    chr = MsGetEff2Chr(D_00704014);
    MsSetChrDirF(chr, MsGetChrBtlDir(chr));
    D_0054D5EC = 0;
    p = &D_00764990;
    p->b11 = 0;
    if (p->b10 != 0) {
        func_0206C3B8(1);
        func_0206C3B8(2);
        func_0206C3B8(0x8003);
    }
}
