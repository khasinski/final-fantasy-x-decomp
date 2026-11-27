#include "common.h"

extern u8 D_01CBA630[];
extern u8 D_01BBA630[];
extern u8 D_01B00050[];
extern u8 D_01B00A30[];
extern u8 D_01B00A48[];
extern u8 D_01B00A68[];
extern u8 D_01B02170[];
extern u8 D_01B0E390[];
extern void *D_01B0004C;
extern void *D_01B00668;
extern void *D_01B0E3BC;
extern void *D_01B0E3C0;

void func_01B02A80(void);
void func_01B0D2D0(void *);
void func_01B05118(void *);
void func_002B4980(void *);
void *func_002B49A0(void *, int, int);
void func_002678E0(void *, void *);
void func_00267A68(void *, void *, void *, int);
void func_002D02E8(void *, int, int, int);
void func_002944B0(void *, int, int, int);
void func_00294468(void *, int, int);
void func_01B03F20(void *);

int func_01B03F78(void)
{
    struct {
        void *a;
        void *b;
        u8 pad08[8];
        void *c;
    } arg;

    u8 *base;

    func_01B02A80();
    base = D_01CBA630;
    D_01B0E3C0 = base;
    D_01B0004C = base + 0x40000;
    arg.c = D_01B00A30;
    func_01B0D2D0(&arg.c);
    arg.b = 0;
    arg.a = D_01B00A48;
    func_01B05118(&arg);
    D_01B00A48[0x1B] = 1;
    arg.a = D_01B00A68;
    arg.b = 0;
    func_01B05118(&arg);
    func_002B4980(D_01B00668);
    D_01B0E3BC = func_002B49A0(D_01B00668, 8, 0);
    func_002678E0(D_01B0E3BC, D_01B00050);
    func_00267A68(D_01B0E390, D_01B0E3BC, D_01BBA630, 0x100000);
    func_002D02E8(D_01B00668, 0, 0x3E8, 2);
    func_002944B0(D_01B00668, 0, 0x3E8, 2);
    func_00294468(func_002B49A0(D_01B00668, 6, 2), 0, 2);
    func_01B03F20(D_01B02170);
    return 0;
}
