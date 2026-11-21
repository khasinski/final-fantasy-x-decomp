/* EE Battle-Effect Overlay: group 0x11, file 09541
 * .text: 0x01B009A0..0x01B00AD4 (1 function).
 */
#include "common.h"

typedef struct TtCfg {
    u8 pad00[0x14];
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

extern u8 D_01B00040[];
extern u8 D_01B00388[];
extern u8 *D_01B003C8;
extern u8 *D_01B003CC;
extern void *D_01B003D0;
extern void *D_01B003D4;
extern TtCfg *D_01B003D8;
extern TtHeap D_01B003E0;
extern void *D_01B00494;
extern u8 D_01B004B0[];
extern char D_01B02318[];
extern char D_01B02328[];
extern u8 D_01B03480[];
extern u8 D_01B163E0[];

extern void func_01B010B8(const char *);
extern void func_01B010E8(const char *);
extern void func_01B01160(void *, void *, int);
extern void *func_0013B150(int);
extern void func_002678E0(void *, void *);
extern void func_00267A68(void *, void *, void *, int);
extern void func_002B4980(void *);
extern void *func_002B49A0(void *, int, int);
extern void func_002D02E8(void *, int, int, int);

int func_01B009A0(void *arg)
{
    TtCfg *c;

    func_01B010B8(D_01B02318);
    D_01B003C8 = D_01B163E0;
    D_01B003CC = D_01B003C8 + 0x80000;
    D_01B003D4 = D_01B03480;
    D_01B003D0 = arg;
    func_002B4980(D_01B003D4);
    func_002D02E8(D_01B003D4, 0, 0x3E8, 0x2000);
    D_01B003D8 = (TtCfg *)func_002B49A0(D_01B003D4, 8, 0);
    func_002678E0(D_01B003D8, D_01B00040);
    func_00267A68(&D_01B003E0, D_01B003D8, D_01B003C8, 0x80000);
    c = D_01B003D8;
    D_01B003E0.w20 = c->w14;
    D_01B003E0.w24 = c->w18;
    D_01B003E0.w28 = c->w1c;
    func_01B01160(D_01B004B0, D_01B00388, 2);
    D_01B00494 = func_0013B150(7);
    if (D_01B00494 == 0) {
        func_01B010E8(D_01B02328);
    }
    return 1;
}
