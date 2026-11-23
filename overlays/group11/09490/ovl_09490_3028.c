#include "common.h"

typedef struct {
    u8 pad0[0x70];
    s16 unk70[4];
    u8 pad78[0x8C];
    void (*unk104)(void *);
    u8 pad108[0x18];
    s32 unk120;
    u8 pad124[0xC];
} Unk3028Elem;

typedef struct {
    u8 pad0[0x5200];
    s32 unk5200;
    s32 unk5204;
    s32 unk5208;
    s32 unk520C;
    s32 unk5210;
} Unk3028Block;

typedef struct {
    u8 pad0[0x8550];
    Unk3028Block unk8550;
} Unk3028Work;

extern Unk3028Work *D_01B0B398;
extern void func_01B03E48(void);

void func_01B03028(void) {
    Unk3028Work *work = D_01B0B398;
    Unk3028Block *blk = &work->unk8550;
    s32 cnt = 12;

    if (blk->unk5208 != 0) {
        cnt = 1;
        func_01B03E48();
    }
    blk->unk520C = cnt;
    blk->unk5200 = 0;
    blk->unk5204 = 0;
    blk->unk5210 = 0;
}

void func_01B03080(void *arg0) {
    Unk3028Elem *elem = (Unk3028Elem *)arg0;
    s32 t = elem->unk120 - 1;
    s32 val;

    elem->unk120 = t;
    val = (t << 12) / 60;
    elem->unk70[3] = val;
    elem->unk70[2] = val;
    elem->unk70[1] = val;
    elem->unk70[0] = val;
    if (t == 0) {
        elem->unk104 = 0;
    }
}
