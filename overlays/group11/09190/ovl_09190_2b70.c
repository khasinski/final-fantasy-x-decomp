#include "common.h"

typedef struct {
    void *a;
    void *b;
} PairArg;

typedef struct {
    u8 pad00[0x1B];
    u8 flag1B;
} Node1B;

extern void *D_01B0004C;
extern u8 D_01B00050;
extern void *D_01B005F0;
extern u8 D_01B00A80;
extern Node1B D_01B00A98;
extern u8 D_01B00AB8;
extern u8 D_01B017C0;
extern u8 D_01B0E280;
extern void *D_01B0E2AC;
extern u8 D_01B80B30;
extern u8 D_01C80B30;

extern void func_01B01D60(void);
extern void func_01B02B18(void *);
extern void func_01B03C88(PairArg *);
extern void func_01B0D1C8(void **);
extern void func_002678E0(void *, void *);
extern void func_00267A68(void *, void *, void *, int);
extern void func_002944B0(void *, int, int, int);
extern void func_0029A878(void);
extern void func_002B4980(void *);
extern void *func_002B49A0(void *, int, int);
extern void func_002D02E8(void *, int, int, int);

int func_01B02B70(void)
{
    PairArg p;
    void *arg10;

    func_01B01D60();
    D_01B0004C = &D_01C80B30;
    arg10 = &D_01B00A80;
    func_01B0D1C8(&arg10);
    p.a = &D_01B00A98;
    p.b = 0;
    func_01B03C88(&p);
    D_01B00A98.flag1B = 1;
    p.a = &D_01B00AB8;
    p.b = 0;
    func_01B03C88(&p);
    func_002B4980(D_01B005F0);
    D_01B0E2AC = func_002B49A0(D_01B005F0, 8, 0);
    func_002678E0(D_01B0E2AC, &D_01B00050);
    func_00267A68(&D_01B0E280, D_01B0E2AC, &D_01B80B30, 0x100000);
    func_002D02E8(D_01B005F0, 0, 1000, 2);
    func_002944B0(D_01B005F0, 0, 1000, 2);
    func_01B02B18(&D_01B017C0);
    func_0029A878();
    return 0;
}
