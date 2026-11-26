#include "iopsound.h"

typedef struct {
    u8 pad0[0x24];
    s32 f24;
    u8 pad28[0x70 - 0x28];
} StreamCh;

extern u8 *D_018754;

extern void func_00FDF4(s32, void *, s32);
extern void func_00CDFC(void *, s32, s32, s32);
extern void func_00D3A0(s32, s32, s32);

s32 func_00D5EC(s32 ch) {
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
    func_00FDF4(core, NULL, 0);
    vbit |= s->f24;
    func_00CDFC(s, vbit, 0, base + 0x5120);
    func_00CDFC(s, ++vbit, 0, base + 0x5120);
    func_00D3A0(core, 0x800, base + 0x5100);
    return ch;
}
