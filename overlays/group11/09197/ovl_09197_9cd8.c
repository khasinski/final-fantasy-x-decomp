#include "common.h"

typedef struct {
    u8 pad00[0x1B];
    u8 b1B;
} Node9CD8;

typedef struct {
    void *p00;
    void *p04;
} PairPtr;

extern void *D_01B0004C;
extern u8 D_01B00050[];
extern void *D_01B006E0;
extern u8 D_01B00AB0[];
extern Node9CD8 D_01B00AC8;
extern Node9CD8 D_01B00AE8;
extern u8 D_01B08BA0[];
extern u8 D_01B14860[];
extern void *D_01B1488C;
extern u8 D_01B9CAE0[];
extern u8 D_01C9CAE0[];

extern void func_002678E0(void *, void *);
extern void func_00267A68(void *, void *, void *, int);
extern void func_00294468(void *, int, int);
extern void func_002944B0(void *, int, int, int);
extern void func_002B4980(void *);
extern void *func_002B49A0(void *, int, int);
extern void func_002D02E8(void *, int, int, int);
extern void func_01B09180(void);
extern void func_01B09C70(void *);
extern void func_01B0BE58(PairPtr *);
extern void func_01B137C8(void **);

int func_01B09CD8(void)
{
    PairPtr pair;
    void *p10;

    func_01B09180();
    D_01B0004C = D_01C9CAE0;
    p10 = D_01B00AB0;
    func_01B137C8(&p10);

    pair.p00 = &D_01B00AC8;
    pair.p04 = 0;
    func_01B0BE58(&pair);
    D_01B00AC8.b1B = 1;

    pair.p00 = &D_01B00AE8;
    pair.p04 = 0;
    func_01B0BE58(&pair);

    func_002B4980(D_01B006E0);
    D_01B1488C = func_002B49A0(D_01B006E0, 8, 1);
    func_002678E0(D_01B1488C, D_01B00050);
    func_00267A68(D_01B14860, D_01B1488C, D_01B9CAE0, 0x100000);
    func_002D02E8(D_01B006E0, 0, 1000, 2);
    func_002944B0(D_01B006E0, 0, 1000, 2);
    func_00294468(func_002B49A0(D_01B006E0, 6, 2), 0, 2);
    func_01B09C70(D_01B08BA0);
    return 0;
}
