#include "common.h"

typedef struct {
    int unk00;
} TtArg;

typedef struct {
    int unk00;
} TtMem;

typedef struct {
    int unk00;
} PartBuf;

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
extern u8 D_01B003B0;
extern u8 D_01B003C8;
extern u8 D_01B00410;
extern TtArg *D_01B0044C;
extern int D_01B00450;
extern int D_01B00454;
extern TtMem *D_01B0045C;
extern u8 *D_01B00460;
extern u8 *D_01B00464;
extern u8 *D_01B00468;
extern u8 *D_01B00470;
extern TtCfg *D_01B00474;
extern TtHeap D_01B00478;
extern u8 D_01B00730;
extern u8 D_01B00840;
extern u8 D_01B00950;
extern PartBuf *D_01B00AD0[2];
extern char D_01B02B90[];
extern char D_01B02BA0[];
extern char D_01B02BB0[];
extern TtMem D_01B02D50;
extern u8 D_01B41C80;

extern int func_01B01EB0(char *, ...);
extern void func_01B01EE0(char *, ...);
extern void func_01B027D0(void *, void *, int);
extern int func_0013B150(int);
extern void func_002678E0(void *, void *);
extern void func_00267A68(void *, void *, void *, int);
extern void func_002B4980(void *);
extern TtCfg *func_002B49A0(void *, int, int);
extern void func_002D02E8(void *, int, int, int);

int func_01B018F0(TtArg *a0)
{
    func_01B01EB0(D_01B02B90);
    D_01B0044C = a0;
    D_01B00460 = &D_01B41C80;
    D_01B00464 = D_01B00460 + 0x80000;
    D_01B00468 = D_01B00464 + 0x80000;
    D_01B00470 = D_01B00468 + 0x80000;
    D_01B00AD0[0] = (PartBuf *)D_01B00470;
    D_01B00AD0[1] = (PartBuf *)(D_01B00470 + 0x17700);
    D_01B0045C = &D_01B02D50;
    func_002B4980(D_01B0045C);
    func_002D02E8(D_01B0045C, 0, 1000, 0x2000);
    D_01B00474 = func_002B49A0(D_01B0045C, 8, 0);
    func_002678E0(D_01B00474, &D_01B00040);
    func_00267A68(&D_01B00478, D_01B00474, D_01B00460, 0x80000);
    D_01B00478.w20 = D_01B00474->w14;
    D_01B00478.w24 = D_01B00474->w18;
    D_01B00478.w28 = D_01B00474->w1c;
    func_01B027D0(&D_01B00730, &D_01B003B0, 1);
    func_01B027D0(&D_01B00840, &D_01B003C8, 3);
    func_01B027D0(&D_01B00950, &D_01B00410, 2);
    D_01B00450 = func_0013B150(0x17);
    if (D_01B00450 == 0) {
        func_01B01EE0(D_01B02BA0);
    }
    D_01B00454 = func_0013B150(0x14);
    if (D_01B00454 == 0) {
        func_01B01EE0(D_01B02BB0);
    }
    return 1;
}
