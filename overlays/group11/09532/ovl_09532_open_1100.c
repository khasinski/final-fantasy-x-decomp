#include "common.h"

extern int D_01B004E0;
extern int D_01B004E4;
extern int D_01B004E8;
extern void *D_01B004EC;
extern int D_01B00504;
extern void *D_01B00510;
extern void *D_01B00514;
extern void *D_01B00518;
extern u8 D_01B00528;
extern int D_01B007E0;
extern char D_01B01FE8[];
extern char D_01B01FF8[];

extern void *D_006A3924;
extern u8 D_006A3970;
extern u8 D_006A3A70;
extern void *D_006A3BCC;

extern int func_01B01380(char *, ...);
extern void func_01B013D8(char *, ...);
extern void func_01B01418(int, int);
extern void func_01B01D50(void *);
extern int func_01B01EA8(void *);
extern int func_00116068(void);
extern int func_0014AA50(int);
extern void func_001A9EE0(void *);
extern void func_001AACA0(void *);
extern int func_001CDAF8(void *);
extern void func_001CDC58(void *, int);
extern void func_001CDDD8(void *);
extern int func_0029B830(int);

int func_01B01100(void)
{
    if (func_00116068() == 0) {
        return 0;
    }
    if (D_01B004E0 == 0) {
        if (func_0029B830(0x2000) != 0) {
            return 1;
        }
        D_01B004E0++;
    }
    if (D_01B004E4 == 0) {
        D_01B004E4 = 1;
        func_001CDC58(D_01B004EC, 0);
    }
    if (D_01B004E8 == 0) {
        if (func_001CDAF8(D_01B004EC) > 0) {
            return ++D_01B004E8;
        }
        return 1;
    }
    return D_01B004E8;
}

int func_01B011B8(void)
{
    if (D_01B004E8 == 0) {
        return 0;
    }
    D_006A3924 = &D_01B00528;
    func_001AACA0(&D_006A3A70);
    func_001A9EE0(&D_006A3970);
    D_006A3BCC = D_01B00510;
    D_01B00518 = D_01B00514;
    if (func_0014AA50(0) != 0) {
        func_01B01418(0x20, 0x1A);
        func_01B013D8(D_01B01FE8, D_01B007E0);
        func_01B01D50(&D_01B007E0);
    }
    if (func_0014AA50(1) != 0) {
        func_01B01EA8(&D_01B007E0);
        func_01B01380(D_01B01FF8);
        func_001CDDD8(D_01B004EC);
        return 1;
    }
    D_01B00504++;
    return 1;
}
