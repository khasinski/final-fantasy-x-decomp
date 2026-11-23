#include "common.h"
#include "vu0.h"

typedef struct {
    u8 pad0[0xC4];
    float unkC4;
    u8 padC8[0x8];
    float unkD0[4];
} Unk4960Sub;

typedef struct {
    u8 pad0[0x1300];
    Unk4960Sub unk1300;
    u8 pad13E0[0x2F80 - 0x13E0];
    float unk2F80[4];
    u8 pad2F90[0xEC00 - 0x2F90];
    float unkEC00;
} Unk4960Work;

extern u8 D_01B0DEB0;
extern Unk4960Work *D_01B0DF78;

extern void func_01B09F18(void *, void *, s32, s32, s32, void *, float);

void func_01B04960(void) {
    Unk4960Work *work = D_01B0DF78;
    Unk4960Sub *sub = &work->unk1300;
    register float *dst __asm__("$4");
    register float *src __asm__("$2");
    register s32 off __asm__("$3");

    func_01B09F18(&D_01B0DEB0, sub, 0x10, 0, 0, 0, 0.1f);
    dst = sub->unkD0;
    src = work->unk2F80;
    MMI_COPY_LQ_A3(dst, src);
    MMI_COPY_SQ_A3(dst);
    off = 0x8000;
    sub->unkC4 = *(float *)((u8 *)work + off + 0x6C00);
}
