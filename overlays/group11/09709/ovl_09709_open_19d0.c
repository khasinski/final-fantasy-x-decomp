/* Battle-effect overlay 09709: 0x01B019D0..0x01B01CC8 */
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
extern u8 D_01B00540[];
extern int D_01B00638;
extern int D_01B0063C;
extern int D_01B00640;
extern void *D_01B00644;
extern void *D_01B00648;
extern int D_01B0064C;
extern void *D_01B00650;
extern TtCfg *D_01B00654;
extern TtHeap D_01B00658;
extern int D_01B00A90;
extern int D_01B00A94;
extern int D_01B00A98;
extern u8 D_01B00AA0[];
extern char D_01B02650[];
extern char D_01B02660[];
extern char D_01B02670[];
extern char D_01B02678[];
extern u8 D_01B026E0[];
extern u8 D_01B57840[];

int func_01B02170(char *, ...);
void func_01B021A0(char *);
void func_01B02228(void *, void *, int);
void func_01B022D8(void *);
int func_01B02430(void *);
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
void func_001CDDD8(int);

int func_01B019D0(int a0)
{
    u8 *mem;

    func_01B02170(D_01B02650);
    mem = D_01B57840;
    D_01B00644 = mem;
    D_01B00648 = mem + 0x80000;
    D_01B00650 = D_01B026E0;
    D_01B0064C = a0;
    func_002B4980(D_01B026E0);
    func_002D02E8(D_01B00650, 0, 1000, 0x2000);
    D_01B00654 = func_002B49A0(D_01B00650, 8, 0);
    func_002678E0(D_01B00654, D_01B00040);
    func_00267A68(&D_01B00658, D_01B00654, D_01B00644, 0x80000);
    D_01B00658.w20 = D_01B00654->w14;
    D_01B00658.w24 = D_01B00654->w18;
    D_01B00658.w28 = D_01B00654->w1c;
    func_01B02228(D_01B00AA0, D_01B00540, 9);
    D_01B00A94 = func_0013B150(0);
    if (D_01B00A94 == 0) {
        func_01B021A0(D_01B02660);
    }
    D_01B00A98 = func_0013B150(1);
    if (D_01B00A98 == 0) {
        func_01B021A0(D_01B02670);
    }
    return 1;
}

int func_01B01B28(void)
{
    return 1;
}

int func_01B01B30(void)
{
    return 1;
}

int func_01B01B38(void)
{
    if (func_00116068() == 0) {
        return 0;
    }
    if (D_01B00638 == 0) {
        if (func_0029B830(0x2000) != 0) {
            return 1;
        }
        D_01B00638++;
    }
    if (D_01B0063C == 0) {
        D_01B0063C = 1;
        func_001CDC58(D_01B0064C, 0);
    }
    if (D_01B00640 == 0) {
        if (func_001CDAF8(D_01B0064C) > 0) {
            return ++D_01B00640;
        }
        return 1;
    }
    return D_01B00640;
}

int func_01B01BF0(void)
{
    if (D_01B00640 == 0) {
        return 0;
    }
    D_006A3924 = &D_01B00658;
    func_001AACA0(D_006A3A70);
    func_001A9EE0(D_006A3970);
    D_006A3BCC = D_01B00648;
    if (func_0014AA50(0) != 0) {
        func_01B022D8(D_01B00AA0);
    }
    if (func_0014AA50(1) != 0) {
        func_01B02430(D_01B00AA0);
        func_01B02170(D_01B02678, D_01B00A90);
        func_001CDDD8(D_01B0064C);
        return 1;
    }
    D_01B00A90++;
    return 1;
}

int func_01B01CB8(void)
{
    return 1;
}

int func_01B01CC0(void)
{
    return 1;
}
