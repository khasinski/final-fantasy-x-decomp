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
    u8 padE0[0x8];
    float unkE8;
    u8 padEC[0x18];
    void *unk104;
    u8 pad108[0x28];
} Work3380;

typedef struct {
    u8 pad0[0x720];
    Work3380 unk720;
    u8 pad850[0x1300 - 0x850];
    Work3380 unk1300;
    Work3380 unk1430;
    u8 pad1560[0x2860 - 0x1560];
    Work3380 unk2860;
    u8 pad2990[0x2F80 - 0x2990];
    Vec4 unk2F80;
    u8 pad2F90[0xEC00 - 0x2F90];
    float unkEC00;
} State3380;

extern u8 D_01B0B2D0[];
extern State3380 *D_01B0B398;

extern void func_01B046A8(void);
extern void func_01B07360(void *, void *, s32, s32, s32, void *, float);
extern void func_01B07828(void *, void *);

void func_01B03380(void) {
    func_01B07828(D_01B0B2D0, &D_01B0B398->unk1300);
}

void func_01B03398(void) {
    register void *d __asm__("$17") = D_01B0B2D0;
    State3380 *s = D_01B0B398;
    Work3380 *w = &s->unk720;

    func_01B07360(d, w, 6, 0, 0, 0, 0.4f);
    MMI_COPY_LQ_A3(&w->unkD0, &s->unk2F80);
    MMI_COPY_SQ_A3(&w->unkD0);
    w->unkC4 = s->unkEC00;
    w->unkE8 = -5.0f;

    w = &s->unk2860;
    func_01B07360(d, w, 0x22, 0, 0, 0, 0.08f);
    w->unkC4 = s->unkEC00;
    w->unk104 = func_01B046A8;
}

void func_01B03478(void) {
    State3380 *s = D_01B0B398;
    Work3380 *w = &s->unk1430;

    func_01B07360(D_01B0B2D0, w, 0x11, 0, 0, 0, 0.2f);
    MMI_COPY_LQ_A3(&w->unkD0, &s->unk2F80);
    __asm__ volatile("sq $7, 0(%0)" : : "r"(&w->unkD0), "r"(&s->unk2F80) : "memory");
    w->unkC4 = s->unkEC00;
    w->unkE8 = -17.0f;
}
