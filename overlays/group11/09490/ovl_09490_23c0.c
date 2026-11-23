#include "common.h"

typedef struct {
    u8 pad0[0xC4];
    float unkC4;
    u8 padC8[0x3C];
    void *unk104;
    u8 pad108[0x28];
} Work23C0;

typedef struct {
    u8 pad0[0x2900];
    Work23C0 *unk2900;
    s32 unk2904;
} Sub5C30;

typedef struct {
    Work23C0 works[0x4D];
    u8 pad5B70[0xC0];
    Sub5C30 unk5C30;
    u8 pad8538[0xEC00 - 0x8538];
    float unkEC00;
} State23C0;

typedef struct {
    u8 pad0[0x2C];
    s32 unk2C;
} Arg23C0;

extern s32 D_01B00A30[];
extern u8 D_01B0B2D0[];
extern State23C0 *D_01B0B398;

extern void func_01B046A8(void);
extern void func_01B07360(void *, void *, s32, s32, s32, void *, float);

void func_01B023C0(Arg23C0 *arg0) {
    State23C0 *s = D_01B0B398;
    Sub5C30 *sub = &s->unk5C30;
    s32 id = arg0->unk2C;
    s32 idx;
    Work23C0 *w;

    sub->unk2904 = id;
    idx = D_01B00A30[id];
    w = &s->works[idx];
    func_01B07360(D_01B0B2D0, w, idx, 0, 0, 0, 0.12f);
    sub->unk2900 = w;
    w->unk104 = func_01B046A8;
    w->unkC4 = s->unkEC00;
}
