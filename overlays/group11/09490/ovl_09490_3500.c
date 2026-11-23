#include "common.h"

typedef struct {
    u8 pad0[0xC0];
    float unkC0;
    float unkC4;
    u8 padC8[0x8];
    float unkD0[4];
    u8 padE0[0x4];
    float unkE4;
} Unk3500Sub;

typedef struct {
    u8 pad0[0x260];
    Unk3500Sub unk260;
    u8 pad348[0xE8B8];
    float unkEC00;
} Unk3500Work;

extern u8 D_01B0B2D0;
extern Unk3500Work *D_01B0B398;

extern void func_01B03E00(float *);
extern s32 func_01B07360(void *, void *, s32, s32, s32, void *, float);

void func_01B03500(void) {
    Unk3500Work *work = D_01B0B398;
    Unk3500Sub *sub = &work->unk260;

    func_01B07360(&D_01B0B2D0, sub, 2, 0, 0, 0, 0.1f);
    func_01B03E00((float *)((u8 *)work + 0x330));
    sub->unkC0 = 0.031415928f;
    sub->unkC4 = work->unkEC00;
    sub->unkE4 = 4.0f;
}
