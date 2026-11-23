#include "common.h"

typedef struct {
    u8 pad0[0x10];
    void (*unk10)(void);
} Unk3A00Sub;

typedef struct {
    u8 pad0[0x8];
    Unk3A00Sub *unk08;
    u8 padC[0x8];
    s32 unk14;
    u8 unk18;
} Unk3A00Task;

typedef struct {
    u8 pad0[0xEC04];
    s32 unkEC04;
    s32 unkEC08;
    s32 unkEC0C;
} Unk3A00Work;

typedef struct {
    u8 pad0[0x2C];
    s32 unk2C;
} Unk3A00State;

extern u8 D_01BF1130[];
extern u8 D_01C334C0[];
extern u8 D_01B00040[];
extern u8 D_01B10AB0[];
extern s32 *D_01B00C78[];
extern void *D_01B00F34;
extern Unk3A00State D_01B0B2D0;
extern s32 D_01B0B310;
extern u8 *D_01B0B314;
extern u8 D_01B0B318[];
extern u8 D_01B0B378[];
extern Unk3A00Work *D_01B0B398;
extern u8 *D_01B0B39C;
extern u8 *D_01B0B3A0;

extern void op_oef2_set2(void *);
extern s32 op_oef2_a_get(void *, s32, s32);
extern void func_01B01210(void);
extern void func_01B03CF8(void);
extern void func_01B03D78(void);
extern void func_01B03DD8(void);
extern void func_01B060C8(void *, s32, s32);
extern void func_01B064C0(void *);
extern void func_01B06860(s32);
extern Unk3A00Task *func_01B07000(void (*)(Unk3A00Task *));
extern void func_01B07080(Unk3A00Task *);
extern void func_01B071C8(Unk3A00Task *);
extern void func_01B07288(void *, void *, void *, s32);
extern s32 func_01B07440(void *, void *);
extern void func_01B08720(void);
extern void func_01B0A9A0(void *, s32);
extern s32 func_01B0A9C0(void *);
extern void func_01B0AC80(void *, s32);

void func_01B03B50(Unk3A00Task *task);
void func_01B03C58(Unk3A00Task *task);

void func_01B03A00(void) {
    op_oef2_set2(D_01BF1130);
    func_01B060C8(D_01BF1130, 0, 11);
}

s32 func_01B03A38(void) {
    Unk3A00Task *task;
    Unk3A00State *st;
    u8 *base = D_01C334C0;

    D_01B0B310 = 0;
    D_01B0B314 = base + 0x40000;
    D_01B0B3A0 = base + 0x180000;
    D_01B0B39C = base + 0x1C0000;
    D_01B0B398 = (Unk3A00Work *)(base + 0x1D8000);

    st = &D_01B0B2D0;
    st->unk2C = op_oef2_a_get(D_01B10AB0, 8, 0);
    func_01B07288(st, D_01B00040, base, 0x40000);
    func_01B03CF8();
    func_01B03D78();
    func_01B06860(1);

    task = func_01B07000(func_01B03B50);
    task->unk18 = 1;
    func_01B071C8(task);

    func_01B0AC80(base + 0x1C8000, 0x200);

    task = func_01B07000(func_01B03C58);
    task->unk18 = 2;
    func_01B071C8(task);
    return 0;
}

void func_01B03B50(Unk3A00Task *task) {
    Unk3A00Work *work = D_01B0B398;

    func_01B08720();
    D_01B00F34 = D_01B0B3A0;

    switch (work->unkEC08) {
    case 0:
        func_01B0A9A0(D_01B0B318, *D_01B00C78[work->unkEC04]);
        work->unkEC08 = 1;
        work->unkEC04++;
        /* fallthrough */
    case 1:
        if (func_01B0A9C0(D_01B0B318) == 1) {
            if (work->unkEC04 > 0) {
                work->unkEC0C = 1;
                func_01B03DD8();
                func_01B07080(task);
            } else {
                work->unkEC08 = 0;
            }
        }
        break;
    }

    func_01B064C0(D_01B0B378);
}

void func_01B03C58(Unk3A00Task *task) {
    Unk3A00Work *work = D_01B0B398;

    if (func_01B07440(&D_01B0B2D0, D_01B0B314) == 1) {
        if (work->unkEC0C == 1) {
            task->unk14 = 3;
            ((s32 *)task->unk08)[4] = (s32)func_01B01210;
        }
    }
}
