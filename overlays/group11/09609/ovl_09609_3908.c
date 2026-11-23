#include "common.h"

typedef struct {
    u8 pad0[0x2C];
    s32 unk2C;
} Unk3908Arg;

typedef struct {
    u8 pad0[0xC4];
    float unkC4;
    u8 padC8[0x3C];
    void *unk104;
    u8 pad108[0x1E];
    u8 unk126;
    u8 pad127[9];
} Unk3908Sub;

typedef struct {
    u8 pad0[0x2B60];
    void *unk2B60;
    s32 unk2B64;
    s32 unk2B68;
} Unk3908Block;

typedef struct {
    Unk3908Sub subs[10];
    Unk3908Sub unkBE0;
    u8 padD10[0x23A0];
    Unk3908Block unk30B0;
    u8 pad5C1C[0x8FE4];
    float unkEC00;
} Unk3908Work;

extern s32 D_01B00B38[];
extern u8 D_01B03860;
extern u8 D_01B071D8;
extern u8 D_01B0DEB0;
extern Unk3908Work *D_01B0DF78;

extern s32 func_01B09F18(void *, void *, s32, s32, s32, void *, float);

void func_01B03908(Unk3908Arg *arg0) {
    Unk3908Work *work = D_01B0DF78;
    Unk3908Block *blk = &work->unk30B0;
    s32 kind = arg0->unk2C;
    s32 id;
    Unk3908Sub *sub;

    blk->unk2B68 = kind;
    id = D_01B00B38[kind];
    sub = &work->subs[id];
    func_01B09F18(&D_01B0DEB0, sub, id, 0, 0, 0, 0.1f);
    sub->unk104 = &D_01B071D8;
    sub->unkC4 = work->unkEC00;
    if (blk->unk2B68 == 2) {
        sub = &work->unkBE0;
        func_01B09F18(&D_01B0DEB0, sub, 10, 20, 0, 0, 0.06f);
        sub->unk126 = 2;
        sub->unk104 = &D_01B03860;
    }
    blk->unk2B60 = sub;
}
