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
} Work5C40;

typedef struct {
    u8 pad0[0x5F0];
    Work5C40 unk5F0;
    u8 pad720[0xF70 - 0x720];
    Work5C40 unkF70;
    u8 pad10A0[0x1300 - 0x10A0];
    Work5C40 unk1300;
    u8 pad1430[0x2730 - 0x1430];
    Work5C40 unk2730;
    u8 pad2860[0x2F80 - 0x2860];
    Vec4 unk2F80;
    u8 pad2F90[0xEC00 - 0x2F90];
    float unkEC00;
} State5C40;

extern u8 D_01B0DEB0[];
extern State5C40 *D_01B0DF78;

extern void func_01B071D8(void);
extern void func_01B09F18(void *, void *, s32, s32, s32, void *, float);
extern void func_01B0A388(void *, void *);

void func_01B05C40(void) {
    func_01B0A388(D_01B0DEB0, &D_01B0DF78->unkF70);
}

void func_01B05C58(void) {
    register void *d __asm__("$17") = D_01B0DEB0;
    State5C40 *s = D_01B0DF78;
    Work5C40 *w = &s->unk5F0;

    func_01B09F18(d, w, 5, 0, 0, 0, 0.4f);
    MMI_COPY_LQ_A3(&w->unkD0, &s->unk2F80);
    MMI_COPY_SQ_A3(&w->unkD0);
    w->unkC4 = s->unkEC00;
    w->unkE8 = -5.0f;

    w = &s->unk2730;
    func_01B09F18(d, w, 0x21, 0, 0, 0, 0.08f);
    w->unkC4 = s->unkEC00;
    w->unk104 = func_01B071D8;
}

void func_01B05D38(void) {
    State5C40 *s = D_01B0DF78;
    Work5C40 *w = &s->unk1300;

    func_01B09F18(D_01B0DEB0, w, 0x10, 0, 0, 0, 0.2f);
    MMI_COPY_LQ_A3(&w->unkD0, &s->unk2F80);
    __asm__ volatile("sq $7, 0(%0)" : : "r"(&w->unkD0), "r"(&s->unk2F80) : "memory");
    w->unkC4 = s->unkEC00;
    w->unkE8 = -17.0f;
}
