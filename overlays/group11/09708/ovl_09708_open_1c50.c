#include "common.h"

typedef struct {
    u8 pad00[0x10];
    int *w10;
    float *w14;
    s16 *w18;
    char *w1c;
} TtCfg;

typedef struct {
    u8 pad00[0x20];
    float *w20;
    s16 *w24;
    char *w28;
} TtHeap;

extern u8 D_01B00040;
extern u8 D_01B00540;
extern u8 D_01B00618;
extern void *D_01B00660;
extern void *D_01B00664;
extern void *D_01B00668;
extern void *D_01B0066C;
extern TtCfg *D_01B00670;
extern TtHeap D_01B00678;
extern int D_01B00C34;
extern int D_01B00C38;
extern u8 D_01B00C40;
extern u8 D_01B00D50;
extern char D_01B028D0[];
extern char D_01B028E0[];
extern char D_01B028F0[];
extern u8 D_01B02960;
extern u8 D_01B57AC0;

extern int func_01B02430(char *, ...);
extern void func_01B02460(char *, ...);
extern void func_01B024E8(void *, void *, int);
extern int func_0013B150(int);
extern void func_002678E0(void *, void *);
extern void func_00267A68(void *, void *, void *, int);
extern void func_002B4980(void *);
extern TtCfg *func_002B49A0(void *, int, int);
extern void func_002D02E8(void *, int, int, int);

int func_01B01C50(void *a0)
{
    func_01B02430(D_01B028D0);
    D_01B00660 = &D_01B57AC0;
    D_01B00664 = (u8 *)D_01B00660 + 0x80000;
    D_01B0066C = &D_01B02960;
    D_01B00668 = a0;
    func_002B4980(D_01B0066C);
    func_002D02E8(D_01B0066C, 0, 1000, 0x2000);
    D_01B00670 = func_002B49A0(D_01B0066C, 8, 0);
    func_002678E0(D_01B00670, &D_01B00040);
    func_00267A68(&D_01B00678, D_01B00670, D_01B00660, 0x80000);
    D_01B00678.w20 = D_01B00670->w14;
    D_01B00678.w24 = D_01B00670->w18;
    D_01B00678.w28 = D_01B00670->w1c;
    func_01B024E8(&D_01B00C40, &D_01B00540, 9);
    func_01B024E8(&D_01B00D50, &D_01B00618, 1);
    D_01B00C34 = func_0013B150(0);
    if (D_01B00C34 == 0) {
        func_01B02460(D_01B028E0);
    }
    D_01B00C38 = func_0013B150(1);
    if (D_01B00C38 == 0) {
        func_01B02460(D_01B028F0);
    }
    return 1;
}
