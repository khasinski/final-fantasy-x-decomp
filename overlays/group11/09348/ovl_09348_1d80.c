#include "common.h"

extern u8 D_01B00040[];
extern u8 D_01B00658[];
extern u8 D_01B00A90[];
extern u8 D_01B01068[];
extern u8 D_01B01528[];
extern u8 D_01B0A9C0[];
extern s32 D_01B0AA00;
extern u8 *D_01B0AA04;
extern u8 D_01B0AA08[];
extern u8 D_01B0AA48[];
extern u8 D_01B0AA88[];
extern u8 D_01B0AAE8[];
extern u8 *D_01B0AB88;
extern u8 *D_01B0AB8C;
extern u8 D_01B10130[];
extern u8 D_01C90000[];

extern void *func_002B49A0(void *, s32, s32);
extern void func_01B061D8(void *, void *, void *, s32);
extern void func_01B020A0(void);
extern void func_01B02218(void);
extern void func_01B09840(void *, void *);
extern void func_01B057C0(s32);
extern u8 *func_01B05F50(void *);
extern void func_01B06118(void *);
extern void func_01B09F80(void *, s32);
extern void func_01B01F28(void);
extern void func_01B01FE8(void);

typedef struct {
    u8 pad[0x2C];
    void *unk2C;
} Tbl1D80;

s32 func_01B01D80(void) {
    u8 *base = D_01C90000;
    u8 *p;
    Tbl1D80 *t;

    D_01B0AA00 = 0;
    D_01B0AA04 = base + 0x80000;
    D_01B0AB8C = base + 0x160000;
    D_01B0AB88 = base + 0x1C0000;

    t = (Tbl1D80 *)D_01B0A9C0;
    t->unk2C = func_002B49A0(D_01B10130, 8, 0);
    func_01B061D8(t, D_01B00040, base, 0x50000);

    t = (Tbl1D80 *)D_01B0AA08;
    t->unk2C = func_002B49A0(D_01B10130, 8, 1);
    func_01B061D8(t, D_01B00658, base + 0x50000, 0x10000);

    t = (Tbl1D80 *)D_01B0AA48;
    t->unk2C = func_002B49A0(D_01B10130, 8, 2);
    func_01B061D8(t, D_01B00A90, base + 0x60000, 0x20000);

    func_01B020A0();
    func_01B02218();

    func_01B09840(D_01B0AA88, D_01B01068);
    func_01B09840(D_01B0AAE8, D_01B01528);

    func_01B057C0(1);

    p = func_01B05F50((void *)func_01B01F28);
    p[0x18] = 1;
    func_01B06118(p);

    func_01B09F80(base + 0x1A0000, 0x400);

    p = func_01B05F50((void *)func_01B01FE8);
    p[0x18] = 2;
    func_01B06118(p);

    return 0;
}
