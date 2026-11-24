#include "common.h"

typedef struct TtCfg {
    u8 pad00[0x10];
    int *w10;
    float *w14;
    s16 *w18;
    char *w1c;
} TtCfg;

typedef struct TtHeap {
    u8 pad00[0x20];
    float *w20;
    s16 *w24;
    char *w28;
} TtHeap;

typedef struct SprParam {
    u16 h00;
    u16 h02;
    u32 w04;
    u8 pad08[0x28];
} SprParam;

extern u8 D_01B00040[];
extern u8 D_01B005E0[];
extern u8 D_01B006A0[];
extern u8 D_01B006B8[];
extern u8 D_01B006D0[];
extern void *D_01B0085C;
extern void *D_01B00860;
extern void *D_01B00864;
extern void *D_01B0086C;
extern int D_01B00870;
extern void *D_01B00874;
extern TtCfg *D_01B00878;
extern TtHeap D_01B00880;
extern SprParam D_01B01130;
extern void *D_01B01168[2];
extern int D_01B01250;
extern int D_01B01254;
extern u8 D_01B01260[];
extern u8 D_01B01370[];
extern u8 D_01B01480[];
extern u8 D_01B01590[];

extern char D_01B04678[];
extern char D_01B04688[];
extern char D_01B04690[];
extern u8 D_01B04830[];
extern u8 D_01B8FC50[];

int func_01B03858(char *, ...);
void func_01B03888(char *, ...);
void func_01B04178(void *, void *, int);
int func_0013B150(int);
void func_002678E0(void *, void *);
void func_00267A68(void *, void *, void *, int);
void func_002B4980(void *);
void *func_002B49A0(void *, int, int);
void func_002D02E8(void *, int, int, int);
void *func_002EF0D0(void *, int, int);

int func_01B03310(int a0)
{
    func_01B03858(D_01B04678);
    D_01B0085C = D_01B8FC50;
    D_01B00860 = (u8 *)D_01B0085C + 0x100000;
    D_01B00864 = (u8 *)D_01B00860 + 0x100000;
    D_01B0086C = (u8 *)D_01B00864 + 0x80000;
    D_01B01168[0] = D_01B0086C;
    D_01B01168[1] = (u8 *)D_01B0086C + 0x4B00;
    D_01B00870 = a0;
    D_01B00874 = D_01B04830;
    func_002B4980(D_01B04830);
    func_002D02E8(D_01B00874, 0, 1000, 0x2000);
    D_01B00878 = func_002B49A0(D_01B00874, 8, 0);
    func_002678E0(D_01B00878, D_01B00040);
    func_00267A68(&D_01B00880, D_01B00878, D_01B0085C, 0x100000);
    D_01B00880.w20 = D_01B00878->w14;
    D_01B00880.w24 = D_01B00878->w18;
    D_01B00880.w28 = D_01B00878->w1c;
    func_002EF0D0(&D_01B01130, 0, 0x30);
    D_01B01130.h02 = 0x80;
    func_01B04178(D_01B01260, D_01B005E0, 8);
    func_01B04178(D_01B01370, D_01B006A0, 1);
    func_01B04178(D_01B01480, D_01B006B8, 1);
    func_01B04178(D_01B01590, D_01B006D0, 8);
    D_01B01250 = func_0013B150(0);
    if (D_01B01250 == 0) {
        func_01B03888(D_01B04688);
    }
    D_01B01254 = func_0013B150(0x17);
    if (D_01B01254 == 0) {
        func_01B03888(D_01B04690);
    }
    return 1;
}
