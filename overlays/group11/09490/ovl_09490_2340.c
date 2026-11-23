#include "common.h"
#include "vu0.h"

typedef struct {
    float x, y, z, w;
} __attribute__((aligned(16))) Vec4;

typedef struct {
    u8 pad0[0xC4];
    float unkC4;
    u8 padC8[0x8];
    Vec4 unkD0;
    u8 padE0[0x50];
} Work2340;

typedef struct {
    u8 pad0[0x1430];
    Work2340 unk1430;
    u8 pad1560[0x2F80 - 0x1560];
    Vec4 unk2F80;
    u8 pad2F90[0xEC00 - 0x2F90];
    float unkEC00;
} State2340;

extern u8 D_01B0B2D0[];
extern State2340 *D_01B0B398;

extern void func_01B07360(void *, void *, s32, s32, s32, void *, float);

void func_01B02340(void) {
    State2340 *s = D_01B0B398;
    Work2340 *w = &s->unk1430;
    register Vec4 *dst __asm__("$4");
    register u32 off __asm__("$3");

    func_01B07360(D_01B0B2D0, w, 0x11, 0, 0, 0, 0.1f);
    dst = &w->unkD0;
    MMI_COPY_LQ_A3(dst, &s->unk2F80);
    MMI_COPY_SQ_A3(dst);
    __asm__("ori %0, $0, 0x8000" : "=r"(off));
    w->unkC4 = *(float *)((u8 *)s + off + 0x6C00);
}
