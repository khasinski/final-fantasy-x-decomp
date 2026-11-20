#include "common.h"

extern int D_01B00498;
extern int D_01B0049C;
extern int D_01B004A0;
extern void *D_01B004A8;
extern void *D_01B004AC;
extern void *D_01B004B0;
extern void *D_01B004B4;
extern void *D_01B004B8;
extern int D_01B051A4;
extern u8 D_01B051A8;
extern u8 D_01B052B8;
extern char D_01B07098[];
extern char D_01B070B0[];
extern u8 D_01B29170;

extern void *D_006A3BCC;

extern int func_01B063F0(char *, ...);
extern void func_01B06DD8(void *);
extern int func_01B06F30(void *);
extern int func_00116068(void);
extern int func_0014AA50(int);
extern int func_001CDAF8(void *);
extern void func_001CDC58(void *, int);
extern void func_001CDDD8(void *);
extern int func_0029B830(int);
extern void func_002B4980(void *);
extern void func_002D02E8(void *, int, int, int);
extern void func_002D05F0(int);

int func_01B05D48(void)
{
    if (func_00116068() == 0) {
        return 0;
    }
    if (D_01B00498 == 0) {
        if (func_0029B830(0x2000) != 0) {
            return 1;
        }
        D_01B00498++;
    }
    if (D_01B0049C == 0) {
        D_01B0049C = 1;
        func_001CDC58(D_01B004B4, 0);
    }
    if (D_01B004A0 == 0) {
        if (func_001CDAF8(D_01B004B4) > 0) {
            return ++D_01B004A0;
        }
        return 1;
    }
    return D_01B004A0;
}

int func_01B05E00(void)
{
    if (func_00116068() == 0 || D_01B004A0 == 0) {
        return 0;
    }
    D_006A3BCC = D_01B004A8;
    D_01B004B0 = D_01B004AC;
    if (func_0014AA50(0) != 0) {
        func_01B06DD8(&D_01B051A8);
    }
    if (func_0014AA50(1) != 0) {
        func_01B06DD8(&D_01B052B8);
    }
    if (func_0014AA50(2) != 0) {
        func_01B06F30(&D_01B051A8);
        func_01B06F30(&D_01B052B8);
        func_01B063F0(D_01B07098, D_01B051A4);
        D_01B004B8 = &D_01B29170;
        func_002B4980(D_01B004B8);
        func_002D02E8(D_01B004B8, 0, 1000, 0x2000);
        func_002D05F0(0x2000);
        func_01B063F0(D_01B070B0, D_01B051A4);
        func_001CDDD8(D_01B004B4);
        return 1;
    }
    D_01B051A4++;
    return 1;
}
