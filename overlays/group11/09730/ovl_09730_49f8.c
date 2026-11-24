#include "common.h"

extern int D_01B00784;
extern int D_01B00788;
extern int D_01B0078C;
extern int D_01B00794;
extern int D_01B007A0;
extern void *D_01B007A8;
extern u8 D_01B007B8;
extern int D_01B009F0;
extern u8 D_01B00A00;
extern int D_01B032C8;

extern void *D_006A3924;
extern u8 D_006A3970;
extern u8 D_006A3A70;
extern int D_006A3BC4;
extern int D_006A3BCC;

extern int func_01B05220(void *);
extern int func_00116068(void);
extern void func_001A9EE0(void *);
extern void func_001AACA0(void *);
extern int func_001CDAF8(int);
extern void func_001CDC58(int, int);
extern void func_001CDDD8(int);
extern void func_00294968(void *, void *, int);
extern int func_0029B830(int);

int func_01B049F8(void)
{
    if (func_00116068() == 0) {
        return 0;
    }
    if (D_01B00784 == 0) {
        if (func_0029B830(0x2000) != 0) {
            return 1;
        }
        D_01B00784++;
    }
    if (D_01B00788 == 0) {
        D_01B00788 = 1;
        func_001CDC58(D_01B007A0, 1);
    }
    if (D_01B0078C == 0) {
        if (func_001CDAF8(D_01B007A0) > 0) {
            D_01B0078C++;
        } else {
            return 1;
        }
    }
}

int func_01B04AB8(void)
{
    if (D_01B0078C == 0) {
        return 0;
    }
    D_006A3BC4 = 0;
    if (func_00116068() == 0) {
        D_006A3BC4 = 1;
    }
    D_006A3924 = &D_01B007B8;
    func_001AACA0(&D_006A3A70);
    func_001A9EE0(&D_006A3970);
    D_006A3BCC = D_01B00794;
    if (func_01B05220(&D_01B032C8) == 0) {
        func_001CDDD8(D_01B007A0);
        return 1;
    }
    if (D_01B032C8 == 5) {
        func_00294968(D_01B007A8, &D_01B00A00, 0x100);
    }
    D_01B009F0++;
    return 1;
}
