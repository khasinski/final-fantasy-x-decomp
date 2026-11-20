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
    u32 w04;
    u8 pad08[0x28];
} SprParam;

extern u8 D_01B00040;
extern u8 D_01B00450;
extern u8 D_01B00468;
extern void *D_01B004A4;
extern void *D_01B004A8;
extern void *D_01B004AC;
extern void *D_01B004B0;
extern void *D_01B004B4;
extern void *D_01B004B8;
extern TtCfg *D_01B004BC;
extern TtHeap D_01B004C0;
extern void *D_01B005F0;
extern SprParam D_01B00600;
extern u8 D_01B00630;
extern u8 D_01B05130;
extern int D_01B051A0;
extern u8 D_01B051A8;
extern u8 D_01B052B8;
extern char D_01B07068[];
extern char D_01B07078[];
extern char D_01B07088[];
extern u8 D_01B07210;
extern u8 D_01B48760;

extern void func_01B05400(void *, void *, void *);
extern int func_01B063F0(char *, ...);
extern void func_01B06420(char *, ...);
extern void func_01B06998(void *, void *, int);
extern void func_01B06A10(void *);
extern void *func_01B06BA8(void *, void *, void *, float);
extern void func_01B06C80(void *, int, float, float);
extern void func_01B06D28(void *, void *, int);
extern void func_00107428(int, int, int, void *);
extern int func_0013B150(int);
extern void func_002678E0(void *, void *);
extern void func_00267A68(void *, void *, void *, int);
extern void func_002B4980(void *);
extern void *func_002B49A0(void *, int, int);
extern void func_002D02E8(void *, int, int, int);
extern void *func_002EF0D0(void *, int, int);

void func_01B059D8(void)
{
    func_01B063F0(D_01B07068);
    D_01B005F0 = func_002B49A0(D_01B004B8, 4, 0);
    func_002EF0D0(&D_01B00600, 0, 0x30);
    D_01B00600.h02 = 0x80;
    D_01B00600.w04 = 0x80808080;
    func_01B06998(&D_01B05130, &D_01B00630, 100);
    func_01B06C80(&D_01B05130, 0, 0.100000001f, 0.0f);
}

void func_01B05A88(void)
{
    float pos[4];

    func_00107428(D_01B051A0, 0, 0, pos);
    func_01B05400(&D_01B05130, D_01B005F0, pos);
    func_01B05400(&D_01B05130, D_01B005F0, pos);
    func_01B05400(&D_01B05130, D_01B005F0, pos);
    func_01B05400(&D_01B05130, D_01B005F0, pos);
    func_01B05400(&D_01B05130, D_01B005F0, pos);
    func_01B05400(&D_01B05130, D_01B005F0, pos);
    func_01B06A10(&D_01B05130);
    D_01B004B0 = func_01B06BA8(&D_01B05130, &D_01B00600, D_01B004B0, 0.0f);
}

int func_01B05B60(void *a0)
{
    func_01B063F0(D_01B07078);
    D_01B004A4 = &D_01B48760;
    D_01B004A8 = (u8 *)D_01B004A4 + 0x80000;
    D_01B004AC = (u8 *)D_01B004A8 + 0x80000;
    D_01B004B8 = &D_01B07210;
    D_01B004B4 = a0;
    func_002B4980(D_01B004B8);
    func_002D02E8(D_01B004B8, 0, 1000, 0x2000);
    D_01B004BC = func_002B49A0(D_01B004B8, 8, 0);
    func_002678E0(D_01B004BC, &D_01B00040);
    func_00267A68(&D_01B004C0, D_01B004BC, D_01B004A4, 0x80000);
    D_01B004C0.w20 = D_01B004BC->w14;
    D_01B004C0.w24 = D_01B004BC->w18;
    D_01B004C0.w28 = D_01B004BC->w1c;
    func_01B06D28(&D_01B051A8, &D_01B00450, 1);
    func_01B06D28(&D_01B052B8, &D_01B00468, 2);
    D_01B051A0 = func_0013B150(0x14);
    if (D_01B051A0 == 0) {
        func_01B06420(D_01B07088);
    }
    D_01B005F0 = func_002B49A0(D_01B004B8, 4, 0);
    func_002EF0D0(&D_01B00600, 0, 0x30);
    D_01B00600.h02 = 0x80;
    D_01B00600.w04 = 0x80808080;
    func_01B06998(&D_01B05130, &D_01B00630, 100);
    func_01B06C80(&D_01B05130, 0, 0.100000001f, 0.0f);
    return 1;
}
