#include "common.h"

extern void *D_01B0004C;
extern u8 D_01CC0330[];
extern u8 D_01BC0330[];
extern u8 D_01B009C0[];
extern u8 D_01B009D8[];
extern u8 D_01B009F8[];
extern void *D_01B005F0;
extern void *D_01B106CC;
extern u8 D_01B00050[];
extern u8 D_01B106A0[];
extern u8 D_01B02068[];

extern void func_01B02650(void);
extern void func_01B0F608(void *);
extern void func_01B055B8(void *);
extern void func_002B4980(void *);
extern void *func_002B49A0(void *, int, int);
extern void func_002678E0(void *, void *);
extern void func_00267A68(void *, void *, void *, int);
extern void func_002D02E8(void *, int, int, int);
extern void func_002944B0(void *, int, int, int);
extern void func_00294468(void *, int, int);
extern void func_01B03208(void *);

static __inline__ void call_f608(void *a) { void *m[1]; m[0] = a; func_01B0F608(m); }
static __inline__ void call_55b8(void *a, void *b) { void *m[2]; m[0] = a; m[1] = b; func_01B055B8(m); }

int func_01B03260(void)
{
    void *v0;

    func_01B02650();
    D_01B0004C = D_01CC0330;
    call_f608(D_01B009C0);
    call_55b8(D_01B009D8, 0);
    D_01B009D8[0x1B] = 1;
    call_55b8(D_01B009F8, 0);
    func_002B4980(D_01B005F0);
    v0 = func_002B49A0(D_01B005F0, 8, 0);
    D_01B106CC = v0;
    func_002678E0(v0, D_01B00050);
    func_00267A68(D_01B106A0, D_01B106CC, D_01BC0330, 0x00100000);
    func_002D02E8(D_01B005F0, 0, 1000, 2);
    func_002944B0(D_01B005F0, 0, 1000, 2);
    func_00294468(func_002B49A0(D_01B005F0, 6, 2), 0, 2);
    func_01B03208(D_01B02068);
    return 0;
}
