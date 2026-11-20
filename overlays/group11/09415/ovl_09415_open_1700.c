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

typedef struct {
    u16 h00;
    u16 h02;
    u8 pad04[0x2C];
} SprParam;

extern u8 D_01B00040;
extern u8 D_01B00400;
extern void *D_01B0057C;
extern int D_01B00580;
extern int D_01B00588[];
extern int D_01B00594;
extern void *D_01B00598;
extern void *D_01B0059C;
extern void *D_01B005A0;
extern void *D_01B005A4;
extern void *D_01B005AC;
extern TtCfg *D_01B005B0;
extern TtHeap D_01B005B8;
extern u8 D_01B00AF0;
extern SprParam D_01B00C10;
extern void *D_01B00C40;
extern char D_01B02958[];
extern char D_01B02970[];
extern char D_01B02980[];
extern char D_01B02990[];
extern char D_01B029A0[];
extern char D_01B029B0[];
extern u8 D_01B02B30;
extern u8 D_01B631B0;

extern int func_01B01CA8(char *, ...);
extern void func_01B01CD8(char *, ...);
extern void func_01B025C8(void *, void *, int);
extern int func_0013B150(int);
extern void func_002678E0(void *, void *);
extern void func_00267A68(void *, void *, void *, int);
extern void func_002B4980(void *);
extern TtCfg *func_002B49A0(void *, int, int);
extern void func_002D02E8(void *, int, int, int);
extern void *func_002EF0D0(void *, int, int);

int func_01B01700(void *a0)
{
    func_01B01CA8(D_01B02958, D_01B00594);
    D_01B0057C = a0;
    D_01B0059C = &D_01B631B0;
    D_01B005A0 = (u8 *)D_01B0059C + 0x80000;
    D_01B005A4 = (u8 *)D_01B005A0 + 0x80000;
    D_01B005AC = (u8 *)D_01B005A4 + 0x80000;
    D_01B00C40 = D_01B005AC;
    D_01B00598 = &D_01B02B30;
    func_002B4980(D_01B00598);
    func_002D02E8(D_01B00598, 0, 1000, 0x2000);
    D_01B005B0 = func_002B49A0(D_01B00598, 8, 0);
    func_002678E0(D_01B005B0, &D_01B00040);
    func_00267A68(&D_01B005B8, D_01B005B0, D_01B0059C, 0x80000);
    D_01B005B8.w20 = D_01B005B0->w14;
    D_01B005B8.w24 = D_01B005B0->w18;
    D_01B005B8.w28 = D_01B005B0->w1c;
    func_01B025C8(&D_01B00AF0, &D_01B00400, 10);
    D_01B00580 = func_0013B150(0);
    if (D_01B00580 == 0) {
        func_01B01CA8(D_01B02970);
    }
    D_01B00588[0] = func_0013B150(0x14);
    if (D_01B00588[0] == 0) {
        func_01B01CD8(D_01B02980);
    }
    D_01B00588[1] = func_0013B150(0x15);
    if (D_01B00588[1] == 0) {
        func_01B01CD8(D_01B02990);
    }
    D_01B00588[2] = func_0013B150(0x16);
    if (D_01B00588[2] == 0) {
        func_01B01CD8(D_01B029A0);
    }
    func_002EF0D0(&D_01B00C10, 0, 0x30);
    D_01B00C10.h02 = 0x80;
    return 1;
}

int func_01B018D0(void)
{
    func_01B01CA8(D_01B029B0, D_01B00594);
    return 1;
}
