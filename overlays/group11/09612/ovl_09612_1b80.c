#include "common.h"

extern u8 D_01B00040[];
extern u8 D_01B00658[];
extern u8 D_01B00A90[];
extern u8 D_01B01048[];
extern u8 D_01B013F8[];
extern u8 D_01B0A3C0[];
extern s32 D_01B0A400;
extern u8 *D_01B0A404;
extern u8 D_01B0A408[];
extern u8 D_01B0A448[];
extern u8 D_01B0A488[];
extern u8 D_01B0A4E8[];
extern u8 *D_01B0A568;
extern u8 *D_01B0A56C;
extern u8 D_01B0FC10[];
extern u8 D_01C80100[];

extern void *func_002B49A0(void *, s32, s32);
extern void func_01B05BD8(void *, void *, void *, s32);
extern void func_01B01E90(void);
extern void func_01B01FA0(void);
extern void func_01B09240(void *, void *);
extern void func_01B051C0(s32);
extern u8 *func_01B05950(void *);
extern void func_01B05B18(void *);
extern void func_01B09980(void *, s32);
extern void func_01B01D28(void);
extern void func_01B01DD8(void);

typedef struct {
    u8 pad[0x2C];
    void *unk2C;
} Tbl1B80;

s32 func_01B01B80(void) {
    u8 *base = D_01C80100;
    u8 *p;
    Tbl1B80 *t;

    D_01B0A400 = 0;
    D_01B0A404 = base + 0x80000;
    D_01B0A56C = base + 0x160000;
    D_01B0A568 = base + 0x1C0000;

    t = (Tbl1B80 *)D_01B0A3C0;
    t->unk2C = func_002B49A0(D_01B0FC10, 8, 0);
    func_01B05BD8(t, D_01B00040, base, 0x50000);

    t = (Tbl1B80 *)D_01B0A408;
    t->unk2C = func_002B49A0(D_01B0FC10, 8, 1);
    func_01B05BD8(t, D_01B00658, base + 0x50000, 0x10000);

    t = (Tbl1B80 *)D_01B0A448;
    t->unk2C = func_002B49A0(D_01B0FC10, 8, 2);
    func_01B05BD8(t, D_01B00A90, base + 0x60000, 0x20000);

    func_01B01E90();
    func_01B01FA0();

    func_01B09240(D_01B0A488, D_01B01048);
    func_01B09240(D_01B0A4E8, D_01B013F8);

    func_01B051C0(1);

    p = func_01B05950((void *)func_01B01D28);
    p[0x18] = 1;
    func_01B05B18(p);

    func_01B09980(base + 0x1A0000, 0x400);

    p = func_01B05950((void *)func_01B01DD8);
    p[0x18] = 2;
    func_01B05B18(p);

    return 0;
}
