/* Battle-effect overlay 09540: 0x01B02B80..0x01B02F20 */
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

extern void *D_006A3924;
extern u8 D_006A3970[];
extern u8 D_006A3A70[];
extern void *D_006A3BCC;

extern int D_01B00AD8;
extern int D_01B00ADC;
extern int D_01B00AE0;
extern void *D_01B00AE4;
extern void *D_01B00AE8;
extern int D_01B00AEC;
extern void *D_01B00AF0;
extern TtCfg *D_01B00AF4;
extern TtHeap D_01B00AF8;
extern u8 D_01B00040[];
extern u8 D_01B00730[];
extern u8 D_01B007D8[];
extern u8 D_01B008B0[];
extern int D_01B01EB0;
extern int D_01B01EB4;
extern int D_01B01EB8[];
extern int D_01B01FC8[];
extern int D_01B020D8[];
extern char D_01B03440[];
extern char D_01B03450[];
extern char D_01B03460[];
extern char D_01B03470[];
extern char D_01B03480[];
extern char D_01B03490[];
extern u8 D_01B034E0[];
extern u8 D_01B55500[];

int func_01B02FE0(char *, ...);
void func_01B03010(char *);
void func_01B03038(char *, int);
void func_01B03078(int, int);
void func_01B03080(void *, void *, int);
void func_01B03130(void *);
int func_01B03288(void *);
void func_002B4980(void *);
void func_002D02E8(void *, int, int, int);
TtCfg *func_002B49A0(void *, int, int);
void func_002678E0(void *, void *);
void func_00267A68(TtHeap *, TtCfg *, void *, int);
int func_0013B150(int);
int func_0029B830(int);
void func_001CDC58(int, int);
int func_001CDAF8(int);
void func_001AACA0(void *);
void func_001A9EE0(void *);
int func_0014AA50(int);
void func_001CDDD8(int);

int func_01B02B80(int a0)
{
    TtCfg *cfg;
    u8 *mem;

    func_01B02FE0(D_01B03440);
    mem = D_01B55500;
    D_01B00AE4 = mem;
    D_01B00AE8 = mem + 0x80000;
    D_01B00AF0 = D_01B034E0;
    D_01B00AEC = a0;
    func_002B4980(D_01B034E0);
    func_002D02E8(D_01B00AF0, 0, 1000, 0x2000);
    D_01B00AF4 = func_002B49A0(D_01B00AF0, 8, 0);
    func_002678E0(D_01B00AF4, D_01B00040);
    func_00267A68(&D_01B00AF8, D_01B00AF4, D_01B00AE4, 0x80000);
    D_01B00AF8.w20 = D_01B00AF4->w14;
    D_01B00AF8.w24 = D_01B00AF4->w18;
    D_01B00AF8.w28 = D_01B00AF4->w1c;
    func_01B03080(D_01B01EB8, D_01B008B0, 0x17);
    func_01B03080(D_01B01FC8, D_01B007D8, 9);
    func_01B03080(D_01B020D8, D_01B00730, 7);
    D_01B01EB0 = func_0013B150(0);
    if (D_01B01EB0 == 0) {
        func_01B03010(D_01B03450);
    }
    return 1;
}

int func_01B02CE8(void)
{
    return 1;
}

int func_01B02CF0(void)
{
    return 1;
}

int func_01B02CF8(void)
{
    if (D_01B00AD8 == 0) {
        if (func_0029B830(0x2000) != 0) {
            return 1;
        }
        D_01B00AD8++;
    }
    if (D_01B00ADC == 0) {
        D_01B00ADC = 1;
        func_001CDC58(D_01B00AEC, 0);
    }
    if (D_01B00AE0 == 0) {
        if (func_001CDAF8(D_01B00AEC) > 0) {
            return ++D_01B00AE0;
        }
        return 1;
    }
    return D_01B00AE0;
}

int func_01B02DA0(void)
{
    if (D_01B00AE0 == 0) {
        return 0;
    }
    D_006A3924 = &D_01B00AF8;
    func_001AACA0(D_006A3A70);
    func_001A9EE0(D_006A3970);
    D_006A3BCC = D_01B00AE8;
    if (func_0014AA50(0) != 0) {
        func_01B03078(0x20, 0x1A);
        func_01B03038(D_01B03460, D_01B01EB8[0]);
        func_01B03078(0x20, 0x1B);
        func_01B03038(D_01B03470, D_01B01FC8[0]);
        func_01B03078(0x20, 0x1C);
        func_01B03038(D_01B03480, D_01B020D8[0]);
        func_01B03130(D_01B01EB8);
        func_01B03130(D_01B01FC8);
        func_01B03130(D_01B020D8);
    }
    if (func_0014AA50(1) != 0) {
        func_01B03288(D_01B01EB8);
        func_01B03288(D_01B01FC8);
        func_01B03288(D_01B020D8);
        func_01B02FE0(D_01B03490, D_01B01EB4);
        func_001CDDD8(D_01B00AEC);
        return 1;
    }
    D_01B01EB4++;
    return 1;
}

int func_01B02F10(void)
{
    return 1;
}

int func_01B02F18(void)
{
    return 1;
}
