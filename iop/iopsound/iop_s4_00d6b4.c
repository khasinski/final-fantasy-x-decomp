#include "iopsound.h"

extern void func_00CDFC(void *, s32, s32, s32);
extern void func_00D3A0(s32, s32, s32);
extern void func_00FDF4(s32, void *, s32);

extern u8 *D_018754;
extern s32 D_018F98;
extern s32 D_019318;
extern s32 D_06D2E0;

typedef struct {
    u8 *f0;
    s32 f4;
    s32 f8;
    s32 fC;
    s32 f10;
    s32 f14;
    s32 f18;
    s32 f1C;
    s32 f20;
    s32 f24;
    u32 f28;
    u8 pad2C[0x44 - 0x2C];
    s32 f44;
    u8 pad48[112 - 0x48];
} StreamCh;

s32 func_00D6B4(s32 ch) {
    StreamCh *s = (StreamCh *)D_018754;
    s32 core;
    s32 vbit;
    s32 base;

    if (ch != 0) {
        s++;
    }
    core = (ch != 0);
    vbit = core << 31;
    base = (ch != 0) ? 0x1af00 : 0;
    vbit |= s->f24;
    func_00CDFC(s, vbit, 1, base + 0x5120);
    func_00CDFC(s, vbit + 1, 2, base + 0x5920);
    func_00D3A0(core, 0x1000, base + 0x5100);
    return ch;
}

s32 func_00D760(s32 ch) {
    StreamCh *s = (StreamCh *)D_018754;

    D_018F98--;
    if (ch != 0) {
        s++;
    }
    func_00FDF4(ch, NULL, 0);
    if (s->f1C != 0 && s->f10 == 0 && D_06D2E0 != 0 && (s->f44 & 7) == 0) {
        imp_thsemap_7(D_019318);
    }
    return ch;
}
