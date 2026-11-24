#include "common.h"

typedef struct {
    u8 pad00[0x10];
    int *w10;
    int w14;
    void **w18;
    char *w1c;
} TtCfg;

typedef struct {
    u8 pad00[0x20];
    int w20;
    void **w24;
    char *w28;
} TtHeap;

extern u8 D_01B00040;
extern u8 D_01B00548;
extern u8 D_01B00620;
extern u8 D_01B00770;
extern void *D_01B007F0;
extern void *D_01B007F4;
extern int D_01B007F8;
extern void *D_01B007FC;
extern TtCfg *D_01B00800;
extern TtHeap D_01B00808;
extern void *D_01B012C4;
extern void *D_01B012C8;
extern u8 D_01B012D0;
extern u8 D_01B013E0;
extern u8 D_01B014F0;
extern char D_01B04DB8[];
extern char D_01B04DC8[];
extern char D_01B04DD8[];
extern u8 D_01B05F20;
extern u8 D_01B5B080;

extern int func_01B03970(char *, ...);
extern void func_01B039A0(char *);
extern void func_01B03A28(void *, void *, int);
extern void *func_0013B150(int);
extern void func_002678E0(void *, void *);
extern void func_00267A68(void *, void *, void *, int);
extern void func_002B4980(void *);
extern TtCfg *func_002B49A0(void *, int, int);
extern void func_002D02E8(void *, int, int, int);

int func_01B03128(int a0)
{
    func_01B03970(D_01B04DB8);
    D_01B007F0 = &D_01B5B080;
    D_01B007F4 = (u8 *)D_01B007F0 + 0x80000;
    D_01B007F8 = a0;
    D_01B007FC = &D_01B05F20;
    func_002B4980(D_01B007FC);
    func_002D02E8(D_01B007FC, 0, 1000, 0x2000);
    D_01B00800 = func_002B49A0(D_01B007FC, 8, 0);
    func_002678E0(D_01B00800, &D_01B00040);
    func_00267A68(&D_01B00808, D_01B00800, D_01B007F0, 0x80000);
    D_01B00808.w20 = D_01B00800->w14;
    D_01B00808.w24 = D_01B00800->w18;
    D_01B00808.w28 = D_01B00800->w1c;
    func_01B03A28(&D_01B012D0, &D_01B00548, 9);
    func_01B03A28(&D_01B013E0, &D_01B00620, 14);
    func_01B03A28(&D_01B014F0, &D_01B00770, 3);
    D_01B012C4 = func_0013B150(0);
    if (D_01B012C4 == 0) {
        func_01B039A0(D_01B04DC8);
    }
    D_01B012C8 = func_0013B150(1);
    if (D_01B012C8 == 0) {
        func_01B039A0(D_01B04DD8);
    }
    return 1;
}
