#include "common.h"

typedef struct {
    s32 unk00;
    s32 unk04;
    u8 *unk08;
    s32 unk0C;
    s32 unk10;
    u8 unk14[0x30];
    s32 unk44[0x20];
} Unk46D8;

extern Unk46D8 D_01B00D28;

extern s32 func_001CE048(void);
extern s32 func_001E53D0(s32, s32 *);
extern s32 func_01B06D28(s32);
extern void func_01B06D60(s32, Unk46D8 *, s32);

void func_01B046D8(s32 arg0) {
    register Unk46D8 *p __asm__("$16") = &D_01B00D28;
    register s32 s1 __asm__("$17") = arg0;

    __asm__("" : "+r"(s1), "+r"(p));
    p->unk0C = 0;
    D_01B00D28.unk00 = func_001CE048();
    p->unk10 = func_01B06D28(D_01B00D28.unk00);
    func_01B06D60(s1, p, func_001E53D0(s1, &p->unk04));
}

void func_01B04740(void) {
    Unk46D8 *p = &D_01B00D28;
    s32 i;

    p->unk0C = 1;
    p->unk10 = func_01B06D28(p->unk00);
    for (i = 0; i < p->unk04; i++) {
        u8 idx = p->unk14[i];
        p->unk44[idx] = func_01B06D28(idx);
    }
    p->unk08 = p->unk14;
}
