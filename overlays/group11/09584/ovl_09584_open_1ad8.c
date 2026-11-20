/* Battle-effect overlay 09584: 0x01B01AD8..0x01B01F38 */
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

extern u8 D_01B00040[];
extern int D_01B007C0;
extern u8 D_01B007C8[];
extern u8 D_01B007F8[];
extern u8 D_01B00810[];
extern int D_01B00900;
extern int D_01B00904;
extern int D_01B00908;
extern void *D_01B0090C;
extern void *D_01B00910;
extern int D_01B00914;
extern int D_01B00918;
extern void *D_01B0091C;
extern TtCfg *D_01B00920;
extern TtHeap D_01B00928;
extern int D_01B00D60;
extern int D_01B00D68[9];
extern u8 D_01B00DA0[];
extern u8 D_01B00EB0[];
extern u8 D_01B00FC0[];
extern char D_01B02868[];
extern char D_01B02878[];
extern char D_01B02888[];
extern char D_01B02898[];
extern char D_01B028A8[];
extern char D_01B028B8[];
extern char D_01B028C8[];
extern char D_01B028D8[];
extern char D_01B028E8[];
extern char D_01B028F8[];
extern char D_01B02908[];
extern u8 D_01B02970[];
extern u8 D_01B8F220[];

void func_01B01190(void);
int func_01B023F0(char *, ...);
void func_01B02420(char *);
void func_01B024A8(void *, void *, int);
void func_01B02558(void *);
int func_01B026B0(void *);
void func_002B4980(void *);
void func_002D02E8(void *, int, int, int);
TtCfg *func_002B49A0(void *, int, int);
void func_002678E0(void *, void *);
void func_00267A68(void *, void *, void *, int);
int func_0013B150(int);
int func_00116068(void);
int func_0029B830(int);
void func_001CDC58(int, int);
int func_001CDAF8(int);
void func_001AACA0(void *);
void func_001A9EE0(void *);
int func_0014AA50(int);
int func_002B2DF0(void *, int, int, int);
void func_002B2F10(int);
void func_001CDDD8(int);

int func_01B01AD8(int a0)
{
    u8 *mem;

    func_01B023F0(D_01B02868);
    mem = D_01B8F220;
    D_01B0090C = mem;
    D_01B00910 = mem + 0x80000;
    D_01B0091C = D_01B02970;
    D_01B00914 = a0;
    func_002B4980(D_01B02970);
    func_002D02E8(D_01B0091C, 0, 1000, 0x2000);
    D_01B00920 = func_002B49A0(D_01B0091C, 8, 0);
    func_002678E0(D_01B00920, D_01B00040);
    func_00267A68(&D_01B00928, D_01B00920, D_01B0090C, 0x80000);
    D_01B00928.w20 = D_01B00920->w14;
    D_01B00928.w24 = D_01B00920->w18;
    D_01B00928.w28 = D_01B00920->w1c;
    func_01B024A8(D_01B00DA0, D_01B007C8, 2);
    func_01B024A8(D_01B00EB0, D_01B007F8, 1);
    func_01B024A8(D_01B00FC0, D_01B00810, 10);
    D_01B00D68[0] = func_0013B150(3);
    if (D_01B00D68[0] == 0) func_01B02420(D_01B02878);
    D_01B00D68[1] = func_0013B150(0x16);
    if (D_01B00D68[1] == 0) func_01B02420(D_01B02888);
    D_01B00D68[2] = func_0013B150(0x17);
    if (D_01B00D68[2] == 0) func_01B02420(D_01B02898);
    D_01B00D68[3] = func_0013B150(0x18);
    if (D_01B00D68[3] == 0) func_01B02420(D_01B028A8);
    D_01B00D68[4] = func_0013B150(0x19);
    if (D_01B00D68[4] == 0) func_01B02420(D_01B028B8);
    D_01B00D68[5] = func_0013B150(0x1A);
    if (D_01B00D68[5] == 0) func_01B02420(D_01B028C8);
    D_01B00D68[6] = func_0013B150(0x1B);
    if (D_01B00D68[6] == 0) func_01B02420(D_01B028D8);
    D_01B00D68[7] = func_0013B150(7);
    if (D_01B00D68[7] == 0) func_01B02420(D_01B028E8);
    D_01B00D68[8] = func_0013B150(0x15);
    if (D_01B00D68[8] == 0) func_01B02420(D_01B028F8);
    return 1;
}

int func_01B01D20(void)
{
    return 1;
}

int func_01B01D28(void)
{
    return 1;
}

int func_01B01D30(void)
{
    if (func_00116068() == 0) {
        return 0;
    }
    if (D_01B00900 == 0) {
        if (func_0029B830(0x2000) != 0) {
            return 1;
        }
        D_01B00900++;
    }
    if (D_01B00904 == 0) {
        D_01B00904 = 1;
        func_001CDC58(D_01B00914, 0);
    }
    if (D_01B00908 == 0) {
        if (func_001CDAF8(D_01B00914) > 0) {
            return ++D_01B00908;
        }
        return 1;
    }
    return D_01B00908;
}

int func_01B01DE8(void)
{
    if (D_01B00908 == 0) {
        return 0;
    }
    D_006A3924 = &D_01B00928;
    func_001AACA0(D_006A3A70);
    func_001A9EE0(D_006A3970);
    D_006A3BCC = D_01B00910;
    if (func_0014AA50(3) != 0) {
        if (D_01B007C0 == 0) {
            D_01B00918 = func_002B2DF0(func_01B01190, 0, 0, 0);
            D_01B007C0++;
        }
    }
    if (func_0014AA50(3) != 0) {
        func_01B02558(D_01B00EB0);
    }
    if (func_0014AA50(2) != 0) {
        func_01B02558(D_01B00FC0);
    }
    if (func_0014AA50(1) != 0) {
        func_002B2F10(D_01B00918);
        func_01B026B0(D_01B00DA0);
        func_01B026B0(D_01B00EB0);
        func_01B026B0(D_01B00FC0);
        func_01B023F0(D_01B02908, D_01B00D60);
        func_001CDDD8(D_01B00914);
        return 1;
    }
    D_01B00D60++;
    return 1;
}
