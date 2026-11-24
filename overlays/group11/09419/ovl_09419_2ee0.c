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

typedef struct {
    s16 s00;
    s16 s02;
    u8 pad04[0x2C];
} PtHeader;

extern u8 D_01B00040;
extern u8 D_01B005B8;
extern u8 D_01B00600;
extern u8 D_01B00630;
extern u8 D_01B00708;
extern u8 *D_01B007C4;
extern u8 *D_01B007C8;
extern u8 *D_01B007CC;
extern u8 *D_01B007D4;
extern int D_01B007D8;
extern void *D_01B007DC;
extern TtCfg *D_01B007E0;
extern TtHeap D_01B007E8;
extern PtHeader D_01B00FA0;
extern u8 *D_01B00FD4;
extern void *D_01B01054;
extern u8 D_01B01060;
extern u8 D_01B01170;
extern u8 D_01B01280;
extern u8 D_01B01390;
extern char D_01B04228[];
extern char D_01B04238[];
extern u8 D_01B043E0;
extern u8 D_01B5FB10;

extern int func_01B03408(char *, ...);
extern void func_01B03438(char *);
extern void func_01B03D28(void *, void *, int);
extern void *func_0013B150(int);
extern void func_002678E0(void *, void *);
extern void func_00267A68(void *, void *, void *, int);
extern void func_002B4980(void *);
extern TtCfg *func_002B49A0(void *, int, int);
extern void func_002D02E8(void *, int, int, int);
extern void *func_002EF0D0(void *, int, int);

int func_01B02EE0(int a0)
{
    func_01B03408(D_01B04228);
    D_01B007C4 = &D_01B5FB10;
    D_01B007C8 = D_01B007C4 + 0x80000;
    D_01B007CC = D_01B007C8 + 0x80000;
    D_01B007D4 = D_01B007CC + 0x80000;
    D_01B00FD4 = D_01B007D4;
    D_01B007D8 = a0;
    D_01B007DC = &D_01B043E0;
    func_002B4980(D_01B007DC);
    func_002D02E8(D_01B007DC, 0, 1000, 0x2000);
    D_01B007E0 = func_002B49A0(D_01B007DC, 8, 0);
    func_002678E0(D_01B007E0, &D_01B00040);
    func_00267A68(&D_01B007E8, D_01B007E0, D_01B007C4, 0x80000);
    D_01B007E8.w20 = D_01B007E0->w14;
    D_01B007E8.w24 = D_01B007E0->w18;
    D_01B007E8.w28 = D_01B007E0->w1c;
    func_002EF0D0(&D_01B00FA0, 0, 0x30);
    D_01B00FA0.s02 = 0x80;
    func_01B03D28(&D_01B01060, &D_01B005B8, 3);
    func_01B03D28(&D_01B01170, &D_01B00600, 2);
    func_01B03D28(&D_01B01280, &D_01B00630, 9);
    func_01B03D28(&D_01B01390, &D_01B00708, 2);
    D_01B01054 = func_0013B150(0);
    if (D_01B01054 == 0) {
        func_01B03438(D_01B04238);
    }
    return 1;
}
