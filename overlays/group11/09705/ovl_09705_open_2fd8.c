/* Battle-effect overlay 09705: 0x01B02FD8..0x01B032A0 */
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

typedef struct TtTask {
    u8 pad[0x110];
} TtTask;

extern void *D_006A3924;
extern u8 D_006A3970[];
extern u8 D_006A3A70[];
extern void *D_006A3BCC;

extern u8 D_01B00040[];
extern int D_01B006B0[14];
extern void *D_01B01010[14];
extern int D_01B01048;
extern int D_01B0104C;
extern int D_01B01050;
extern void *D_01B01054;
extern void *D_01B01058;
extern int D_01B0105C;
extern void *D_01B01060;
extern TtCfg *D_01B01064;
extern TtHeap D_01B01068;
extern int D_01B012A0;
extern TtTask D_01B01358[14];
extern char D_01B03C40[];
extern char D_01B03C50[];
extern u8 D_01B03CB0[];
extern u8 D_01B2FE50[];

void func_01B02288(void);
int func_01B03748(char *, ...);
void func_01B03800(void *, void *, int);
void func_002B4980(void *);
void func_002D02E8(void *, int, int, int);
TtCfg *func_002B49A0(void *, int, int);
void func_002678E0(void *, void *);
void func_00267A68(TtHeap *, TtCfg *, void *, int);
int func_00116068(void);
int func_0029B830(int);
void func_001CDC58(int, int);
int func_001CDAF8(int);
void func_001AACA0(void *);
void func_001A9EE0(void *);
int func_0014AA50(int);
void func_001CDDD8(int);

int func_01B02FD8(int a0)
{
    register int arg0 __asm__("$18") = a0; /* DEBT(FAKE): pin $s2 to match saved reg allocation */
    u8 *mem;
    int i;

    func_01B03748(D_01B03C40);
    mem = D_01B2FE50;
    D_01B01054 = mem;
    D_01B01058 = mem + 0x80000;
    D_01B01060 = D_01B03CB0;
    D_01B0105C = arg0;
    func_002B4980(D_01B03CB0);
    func_002D02E8(D_01B01060, 0, 1000, 0x2000);
    D_01B01064 = func_002B49A0(D_01B01060, 8, 0);
    func_002678E0(D_01B01064, D_01B00040);
    func_00267A68(&D_01B01068, D_01B01064, D_01B01054, 0x80000);
    D_01B01068.w20 = D_01B01064->w14;
    D_01B01068.w24 = D_01B01064->w18;
    D_01B01068.w28 = D_01B01064->w1c;
    for (i = 0; i < 14; i++) {
        func_01B03800(&D_01B01358[i], D_01B01010[i], D_01B006B0[i]);
    }
    return 1;
}

int func_01B03120(void)
{
    return 1;
}

int func_01B03128(void)
{
    return 1;
}

int func_01B03130(void)
{
    if (func_00116068() == 0) {
        return 0;
    }
    if (D_01B01048 == 0) {
        if (func_0029B830(0x2000) != 0) {
            return 1;
        }
        D_01B01048++;
    }
    if (D_01B0104C == 0) {
        D_01B0104C = 1;
        func_001CDC58(D_01B0105C, 0);
    }
    if (D_01B01050 == 0) {
        if (func_001CDAF8(D_01B0105C) > 0) {
            return ++D_01B01050;
        }
        return 1;
    }
    return D_01B01050;
}

int func_01B031E8(void)
{
    if (D_01B01050 == 0) {
        return 0;
    }
    D_006A3924 = &D_01B01068;
    func_001AACA0(D_006A3A70);
    func_001A9EE0(D_006A3970);
    D_006A3BCC = D_01B01058;
    func_01B02288();
    if (func_0014AA50(0x1C) != 0) {
        func_01B03748(D_01B03C50, D_01B012A0);
        func_001CDDD8(D_01B0105C);
        return 1;
    }
    D_01B012A0++;
    return 1;
}

int func_01B03290(void)
{
    return 1;
}

int func_01B03298(void)
{
    return 1;
}
