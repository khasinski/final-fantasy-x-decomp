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
extern u8 D_01B00428;
extern void *D_01B004EC;
extern int D_01B004F0[];
extern void *D_01B00508;
extern void *D_01B0050C;
extern void *D_01B00510;
extern void *D_01B00514;
extern void *D_01B0051C;
extern TtCfg *D_01B00520;
extern TtHeap D_01B00528;
extern u8 D_01B007E0;
extern void *D_01B00930;
extern char D_01B01FC8[];
extern char D_01B01FD8[];
extern u8 D_01B02140;
extern u8 D_01B1BE80;

extern int func_01B01380(char *, ...);
extern void func_01B013B0(char *, ...);
extern void func_01B01CA0(void *, void *, int);
extern int func_0013B150(int);
extern void func_002678E0(void *, void *);
extern void func_00267A68(void *, void *, void *, int);
extern void func_002B4980(void *);
extern TtCfg *func_002B49A0(void *, int, int);
extern void func_002D02E8(void *, int, int, int);

int func_01B00F78(void *a0)
{
    int i;

    func_01B01380(D_01B01FC8);
    D_01B004EC = a0;
    D_01B0050C = &D_01B1BE80;
    D_01B00510 = (u8 *)D_01B0050C + 0x80000;
    D_01B00514 = (u8 *)D_01B00510 + 0x80000;
    D_01B0051C = (u8 *)D_01B00514 + 0x80000;
    D_01B00930 = D_01B0051C;
    D_01B00508 = &D_01B02140;
    func_002B4980(D_01B00508);
    func_002D02E8(D_01B00508, 0, 1000, 0x2000);
    D_01B00520 = func_002B49A0(D_01B00508, 8, 0);
    func_002678E0(D_01B00520, &D_01B00040);
    func_00267A68(&D_01B00528, D_01B00520, D_01B0050C, 0x80000);
    D_01B00528.w20 = D_01B00520->w14;
    D_01B00528.w24 = D_01B00520->w18;
    D_01B00528.w28 = D_01B00520->w1c;
    func_01B01CA0(&D_01B007E0, &D_01B00428, 5);
    for (i = 0; i < 5; i++) {
        D_01B004F0[i] = func_0013B150(i + 0x14);
        if (D_01B004F0[i] == 0) {
            func_01B013B0(D_01B01FD8, 0x14);
        }
    }
    return 1;
}
