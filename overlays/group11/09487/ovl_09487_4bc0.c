#include "common.h"

extern int D_01B007AC;
extern int D_01B007B4;
extern int D_01B007C0;
extern void *D_01B007C8;
extern u8 D_01B007D8;
extern int D_01B00A10;
extern u8 D_01B00A20;
extern int D_01B032F8;

extern void *D_006A3924;
extern u8 D_006A3970;
extern u8 D_006A3A70;
extern int D_006A3BC4;
extern int D_006A3BCC;

extern int func_01B05328(void *);
extern int func_00116068(void);
extern void func_001A9EE0(void *);
extern void func_001AACA0(void *);
extern void func_001CDDD8(int);
extern void func_00294968(void *, void *, int);

int func_01B04BC0(void)
{
    if (D_01B007AC == 0) {
        return 0;
    }
    D_006A3BC4 = 0;
    if (func_00116068() == 0) {
        D_006A3BC4 = 1;
    }
    D_006A3924 = &D_01B007D8;
    func_001AACA0(&D_006A3A70);
    func_001A9EE0(&D_006A3970);
    D_006A3BCC = D_01B007B4;
    if (func_01B05328(&D_01B032F8) == 0) {
        func_001CDDD8(D_01B007C0);
        return 1;
    }
    if (D_01B032F8 == 5) {
        func_00294968(D_01B007C8, &D_01B00A20, 0x100);
    }
    D_01B00A10++;
    return 1;
}
