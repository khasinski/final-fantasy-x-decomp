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

extern u8 D_01B00040;
extern u8 D_01B004A0;
extern void *D_01B00540;
extern void *D_01B00544;
extern void *D_01B00548;
extern void *D_01B00550;
extern void *D_01B00554;
extern void *D_01B00558;
extern TtCfg *D_01B0055C;
extern TtHeap D_01B00560;
extern void *D_01B007D0;
extern int D_01B00854;
extern u8 D_01B00878;
extern char D_01B02B30[];
extern char D_01B02B40[];
extern char D_01B02B50[];
extern char D_01B02B68[];
extern char D_01B02B80[];
extern char D_01B02B98[];
extern u8 D_01B02D10;
extern u8 D_01B92010;

extern int func_01B01E48(char *, ...);
extern void func_01B01E78(char *, ...);
extern void func_01B02770(void *, void *, int);
extern int func_0013B150(int);
extern void func_002678E0(void *, void *);
extern void func_00267A68(void *, void *, void *, int);
extern void func_002B4980(void *);
extern TtCfg *func_002B49A0(void *, int, int);
extern void func_002D02E8(void *, int, int, int);

int func_01B016A8(void *a0)
{
    func_01B01E48(D_01B02B30);
    D_01B00540 = &D_01B92010;
    D_01B00544 = (u8 *)D_01B00540 + 0x80000;
    D_01B00548 = (u8 *)D_01B00544 + 0x80000;
    D_01B00550 = (u8 *)D_01B00548 + 0x80000;
    func_01B01E48(D_01B02B40, D_01B00540);
    func_01B01E48(D_01B02B50, D_01B00544);
    func_01B01E48(D_01B02B68, D_01B00548);
    func_01B01E48(D_01B02B80, D_01B00550);
    D_01B007D0 = D_01B00550;
    D_01B00554 = a0;
    D_01B00558 = &D_01B02D10;
    func_002B4980(D_01B00558);
    func_002D02E8(D_01B00558, 0, 1000, 0x2000);
    D_01B0055C = func_002B49A0(D_01B00558, 8, 0);
    func_002678E0(D_01B0055C, &D_01B00040);
    func_00267A68(&D_01B00560, D_01B0055C, D_01B00540, 0x80000);
    D_01B00560.w20 = D_01B0055C->w14;
    D_01B00560.w24 = D_01B0055C->w18;
    D_01B00560.w28 = D_01B0055C->w1c;
    func_01B02770(&D_01B00878, &D_01B004A0, 5);
    D_01B00854 = func_0013B150(0x15);
    if (D_01B00854 == 0) {
        func_01B01E78(D_01B02B98);
    }
    return 1;
}
