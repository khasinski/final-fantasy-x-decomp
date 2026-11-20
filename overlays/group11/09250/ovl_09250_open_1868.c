#include "common.h"

extern int D_01B00534;
extern int D_01B00538;
extern int D_01B0053C;
extern void *D_01B00544;
extern void *D_01B00548;
extern void *D_01B0054C;
extern void *D_01B00554;
extern u8 D_01B00560;
extern int D_01B00850;
extern u8 D_01B00878;
extern char D_01B02BA8[];

extern void *D_006A3924;
extern u8 D_006A3970;
extern u8 D_006A3A70;
extern void *D_006A3BCC;

extern int func_01B01E48(char *, ...);
extern void func_01B02820(void *);
extern int func_01B02978(void *);
extern int func_00116068(void);
extern int func_0014AA50(int);
extern void func_001A9EE0(void *);
extern void func_001AACA0(void *);
extern int func_001CDAF8(void *);
extern void func_001CDC58(void *, int);
extern void func_001CDDD8(void *);
extern int func_0029B830(int);

int func_01B01868(void)
{
    if (func_00116068() == 0) {
        return 0;
    }
    if (D_01B00534 == 0) {
        if (func_0029B830(0x2000) != 0) {
            return 1;
        }
        D_01B00534++;
    }
    if (D_01B00538 == 0) {
        D_01B00538 = 1;
        func_001CDC58(D_01B00554, 0);
    }
    if (D_01B0053C == 0) {
        if (func_001CDAF8(D_01B00554) > 0) {
            return ++D_01B0053C;
        }
        return 1;
    }
    return D_01B0053C;
}

int func_01B01920(void)
{
    if (D_01B0053C == 0) {
        return 0;
    }
    D_006A3924 = &D_01B00560;
    func_001AACA0(&D_006A3A70);
    func_001A9EE0(&D_006A3970);
    D_006A3BCC = D_01B00544;
    D_01B0054C = D_01B00548;
    if (func_0014AA50(0) != 0) {
        func_01B02820(&D_01B00878);
    }
    if (func_0014AA50(1) != 0) {
        func_01B02978(&D_01B00878);
        func_01B01E48(D_01B02BA8, D_01B00850);
        func_001CDDD8(D_01B00554);
        return 1;
    }
    D_01B00850++;
    return 1;
}
