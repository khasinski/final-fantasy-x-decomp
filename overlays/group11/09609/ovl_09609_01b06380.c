#include "common.h"

typedef struct {
    u8 pad0[0x18];
    u8 unk18;
} Task6380;

typedef struct {
    u8 pad0[0x2C];
    s32 unk2C;
} UnkDEB0;

extern u8 D_01B00040;
extern u8 D_01B064F0;
extern u8 D_01B066A8;
extern UnkDEB0 D_01B0DEB0;
extern s32 D_01B0DEF0;
extern void *D_01B0DEF4;
extern void *D_01B0DF78;
extern void *D_01B0DF7C;
extern void *D_01B0DF80;
extern void *D_01B0DF84;
extern u8 D_01B17DF0;
extern u8 D_01C03DD0;
extern u8 D_01C50C80[];

extern void func_002B4980(void *);
extern s32 func_002B49A0(void *, s32, s32);
extern void func_01B068A0(void);
extern void func_01B06920(void);
extern void func_01B08C70(void *, s32, s32);
extern void func_01B09428(s32);
extern void func_01B09538(void *, s32, s32);
extern Task6380 *func_01B09BB8(void *);
extern void func_01B09D80(Task6380 *);
extern void func_01B09E40(void *, void *, void *, s32);
extern void func_01B0D8B0(void *, s32);

void func_01B06380(void) {
    func_002B4980(&D_01C03DD0);
    func_01B08C70(&D_01C03DD0, 0, 0x16);
}

s32 func_01B063B8(void) {
    Task6380 *task;
    UnkDEB0 *st;
    u8 *base = D_01C50C80;

    D_01B0DEF0 = 0;
    D_01B0DEF4 = base + 0x40000;
    D_01B0DF84 = base + 0x180000;
    D_01B0DF7C = base + 0x1C0000;
    D_01B0DF78 = base + 0x1D8000;
    D_01B0DF80 = base + 0x40000;
    st = &D_01B0DEB0;
    st->unk2C = func_002B49A0(&D_01B17DF0, 8, 0);
    func_01B09E40(st, &D_01B00040, base, 0x40000);
    func_01B068A0();
    func_01B06920();
    func_01B09428(1);
    func_01B09538(&D_01C03DD0, 2, 0x16);
    task = func_01B09BB8(&D_01B064F0);
    task->unk18 = 1;
    func_01B09D80(task);
    func_01B0D8B0(base + 0x1C8000, 0x200);
    task = func_01B09BB8(&D_01B066A8);
    task->unk18 = 2;
    func_01B09D80(task);
    return 0;
}
