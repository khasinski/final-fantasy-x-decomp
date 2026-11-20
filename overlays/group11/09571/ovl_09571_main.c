/* EE Battle-Effect Overlay: group 0x11, file 09571
 * .text: 0x01B007E0..0x01B00D60 (12 functions: tt_scene main + ppp part + delay loop).
 */
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

typedef struct TtPObj {
    u8 pad00[0x40];
    float x, y, z, w;
    int rx, ry, rz, rw;
    float sx, sy, sz, sw;
} TtPObj;

extern void *D_006A3924;
extern u8 D_006A3930[];
extern u8 D_006A3970[];
extern u8 D_006A39B0[];
extern u8 D_006A3A70[];
extern u8 D_006A3AB0[];
extern void *D_006A3BCC;

extern u8 D_01B00040[];
extern u8 D_01B005B8[];
extern int D_01B005E8;
extern int D_01B005EC;
extern int D_01B005F0;
extern void *D_01B005F4;
extern int D_01B005F8;
extern void *D_01B005FC;
extern u8 *D_01B00600;
extern u8 *D_01B00604;
extern TtCfg *D_01B00608;
extern TtHeap D_01B00610;
extern TtPObj D_01B00640;
extern void *D_01B006C0;
extern u8 D_01B006C8[];
extern char D_01B01190[];
extern char D_01B011A0[];
extern char D_01B011B8[];
extern char D_01B011C8[];
extern char D_01B011D8[];
extern u8 D_01B01220[];
extern u8 D_01B3C510[];

extern int func_01B00E20(char *, ...);
extern int func_01B00E50(char *, ...);
extern void func_01B00EC0(void *, void *, int);
extern void func_01B00F70(void *);
extern void func_01B010C8(void *);

extern void func_00107428(void *, int, int, float *);
extern int func_00116068(void);
extern void *func_0013B150(int);
extern int func_0014AA50(int);
extern void func_001A9EE0(void *);
extern void func_001AACA0(void *);
extern int func_001CDAF8(void *);
extern void func_001CDC58(void *, int);
extern void func_001CDDD8(void *);
extern void func_00267530(void *);
extern void func_002675B0(void *);
extern void func_00267658(void *, int, int, int);
extern void func_002678E0(void *, void *);
extern void func_00267A68(void *, void *, void *, int);
extern int func_00267FA0(void *, int);
extern int func_0029B830(int);
extern void func_002B4980(void *);
extern TtCfg *func_002B49A0(void *, int, int);
extern void func_002D02E8(void *, int, int, int);
extern void func_002DCE38(void *, void *, void *);

void func_01B00898(void)
{
    int i;
    i = 100000;
    do {
        i--;
        __asm__ volatile("nop");
    } while (i != 0);
    i = 100000;
    do {
        i--;
        __asm__ volatile("nop");
    } while (i != 0);
    i = 100000;
    do {
        i--;
        __asm__ volatile("nop");
    } while (i != 0);
    i = 100000;
    do {
        i--;
        __asm__ volatile("nop");
    } while (i != 0);
    i = 100000;
    do {
        i--;
        __asm__ volatile("nop");
    } while (i != 0);
}

int func_01B00968(void)
{
    float pos[4];

    D_006A3924 = &D_01B00610;
    func_001AACA0(D_006A3A70);
    func_001A9EE0(D_006A3970);
    func_00107428(D_01B006C0, 0x2B, 0, pos);
    D_01B00640.x = pos[0];
    D_01B00640.y = pos[1];
    D_01B00640.z = pos[2];
    func_002675B0(&D_01B00640);
    func_002DCE38(D_006A39B0, D_006A3970, D_006A3930);
    func_002DCE38(D_006A3AB0, D_006A3A70, D_006A39B0);
    D_006A3924 = &D_01B00610;
    return func_00267FA0(&D_01B00640, 0x30) == 0;
}

int func_01B00A60(void)
{
    D_006A3924 = &D_01B00610;
    func_00267530(&D_01B00640);
    func_01B00E20(D_01B011A0, D_01B005F8);
    return 1;
}

int func_01B00AA8(void)
{
    return 1;
}

int func_01B00AB0(void *arg)
{
    TtCfg *c;

    func_01B00E20(D_01B011B8);
    D_01B005F4 = arg;
    D_01B00600 = D_01B3C510;
    D_01B00604 = D_01B00600 + 0x100000;
    D_01B005FC = D_01B01220;
    func_002B4980(D_01B005FC);
    func_002D02E8(D_01B005FC, 0, 0x3E8, 0x2000);
    D_01B00608 = func_002B49A0(D_01B005FC, 8, 0);
    func_002678E0(D_01B00608, D_01B00040);
    func_00267A68(&D_01B00610, D_01B00608, D_01B00600, 0x100000);
    c = D_01B00608;
    D_01B00610.w20 = c->w14;
    D_01B00610.w24 = c->w18;
    D_01B00610.w28 = c->w1c;
    func_01B00EC0(D_01B006C8, D_01B005B8, 1);
    D_01B006C0 = func_0013B150(0);
    if (D_01B006C0 == 0) {
        func_01B00E50(D_01B011C8);
    }
    return 1;
}

int func_01B00BE0(void)
{
    return 1;
}

int func_01B00BE8(void)
{
    return 1;
}

int func_01B00BF0(void)
{
    if (func_00116068() == 0) {
        return 0;
    }
    if (D_01B005E8 == 0) {
        if (func_0029B830(0x2000) != 0) {
            return 1;
        }
        D_01B005E8++;
    }
    if (D_01B005EC == 0) {
        D_01B005EC = 1;
        func_001CDC58(D_01B005F4, 0);
    }
    if (D_01B005F0 == 0) {
        if (func_001CDAF8(D_01B005F4) > 0) {
            return ++D_01B005F0;
        }
        return 1;
    }
    return D_01B005F0;
}

int func_01B00CA8(void)
{
    if (func_00116068() == 0 || D_01B005F0 == 0) {
        return 0;
    }
    D_006A3BCC = D_01B00604;
    if (func_0014AA50(0) != 0) {
        func_01B00F70(D_01B006C8);
    }
    if (func_0014AA50(1) != 0) {
        func_01B010C8(D_01B006C8);
        func_01B00E20(D_01B011D8);
        func_001CDDD8(D_01B005F4);
        return 1;
    }
    D_01B005F8++;
    return 1;
}

int func_01B00D50(void)
{
    return 1;
}

int func_01B00D58(void)
{
    return 1;
}
