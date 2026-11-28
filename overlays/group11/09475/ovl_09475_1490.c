#include "common.h"

extern u8 D_01B00040[];
extern u8 D_01B00508[];
extern u8 D_01B09F20[];
extern s32 D_01B09F60;
extern u8 *D_01B09F64;
extern u8 D_01B09F68[];
extern u8 *D_01B0A068;
extern u8 *D_01B0A06C;
extern u8 *D_01B0A070;
extern u8 *D_01B0A074;
extern u8 *D_01B0A078;
extern u8 D_01B0FCB0[];
extern u8 D_01B91140[];

extern void *func_002B49A0(void *, s32, s32);
extern void func_01B061F0(void *, void *, void *, s32);
extern void func_01B01700(void);
extern void func_01B09858(void *, void *);
extern void func_01B057D8(s32);
extern u8 *func_01B05F68(void *);
extern void func_01B06130(void *);
extern void func_01B09978(void *, s32);
extern void func_01B015D0(void);
extern void func_01B01698(void);

typedef struct {
    u8 pad[0x2C];
    void *unk2C;
} Tbl1490;

s32 func_01B01490(void) {
    u8 *base = D_01B91140;
    Tbl1490 *t;
    u8 *p;

    D_01B09F60 = 0;
    D_01B09F64 = base + 0x40000;
    D_01B0A06C = base + 0x140000;
    D_01B0A070 = base + 0x180000;
    D_01B0A074 = base + 0x1D0000;
    D_01B0A078 = base + 0x1E0000;
    D_01B0A068 = base + 0x210000;

    t = (Tbl1490 *)D_01B09F20;
    t->unk2C = func_002B49A0(D_01B0FCB0, 8, 0);
    func_01B061F0(t, D_01B00040, base, 0x40000);

    func_01B01700();
    func_01B09858(D_01B09F68, D_01B00508);
    func_01B057D8(1);

    p = func_01B05F68((void *)func_01B015D0);
    p[0x18] = 1;
    func_01B06130(p);

    func_01B09978(base + 0x1F0000, 0x400);

    p = func_01B05F68((void *)func_01B01698);
    p[0x18] = 2;
    func_01B06130(p);

    return 0;
}
