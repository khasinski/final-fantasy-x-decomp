#include "common.h"

typedef struct {
    u8 pad0[0x2C];
    s32 unk2C;
} Unk12D8Arg;

typedef struct {
    u8 pad0[0xC4];
    float unkC4;
    u8 padC8[0x3C];
    void *unk104;
    u8 pad108[0x1E];
    u8 unk126;
    u8 pad127[0x9];
} Unk12D8Sub;

typedef struct {
    u8 pad0[0x2B60];
    void *unk2B60;
    s32 unk2B64;
    s32 unk2B68;
} Unk12D8Block;

typedef struct {
    Unk12D8Sub subs[11];
    Unk12D8Sub unkD10;
    u8 padE40[0x2270];
    Unk12D8Block unk30B0;
    u8 pad5C20[0x8FE4];
    float unkEC00;
} Unk12D8Work;

extern s32 D_01B00928[];
extern u8 D_01B01230;
extern u8 D_01B046A8;
extern u8 D_01B0B2D0;
extern Unk12D8Work *D_01B0B398;

extern s32 func_01B07360(void *, void *, s32, s32, s32, void *, float);

void func_01B012D8(Unk12D8Arg *arg0) {
    Unk12D8Work *work = D_01B0B398;
    Unk12D8Block *blk = &work->unk30B0;
    s32 kind = arg0->unk2C;
    s32 id;
    Unk12D8Sub *sub;

    blk->unk2B68 = kind;
    id = D_01B00928[kind];
    sub = &work->subs[id];
    func_01B07360(&D_01B0B2D0, sub, id, 0, 0, 0, 0.1f);
    sub->unk104 = &D_01B046A8;
    sub->unkC4 = work->unkEC00;
    {
        s32 kind2 = blk->unk2B68;
        if (kind2 == 2) {
            sub = &work->unkD10;
            func_01B07360(&D_01B0B2D0, sub, 0xB, 0x14, 0, 0, 0.06f);
            sub->unk126 = kind2;
            sub->unk104 = &D_01B01230;
        }
    }
    blk->unk2B60 = sub;
}
