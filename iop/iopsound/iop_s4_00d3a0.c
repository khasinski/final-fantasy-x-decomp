#include "iopsound.h"

extern void func_00DAC4(void);

extern u8 *D_018754;
extern u8 *D_0192F0;
extern u8 D_06D2B0[];

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

typedef struct {
    s32 f0;
    u8 pad4[12];
    s32 f10;
    void *f14;
} DmaState;

void func_00D3A0(s32 ch, s32 add_off, s32 unused) {
    StreamCh *s = (StreamCh *)D_018754;
    DmaState *st;
    s32 flags;
    u16 sw;
    u8 vidx;
    u8 *vp;

    if (ch != 0) {
        s++;
    }
    if (s->f1C == 0) {
        return;
    }
    s->f4 += add_off;
    st = (DmaState *)(D_06D2B0 + ch * 20);
    st->f14 = (void *)func_00DAC4;
    if (s->f28 < 2) {
        st->f10 = 1;
    }
    if (s->f18 & 0x100) {
        flags = 0x3c00;
        sw = (u16)(ch | 0x1800);
        imp_libsd_7(sw, imp_libsd_8(sw) | s->f1C);
        sw = (u16)(ch | 0x1a00);
        imp_libsd_7(sw, imp_libsd_8(sw) | s->f1C);
        sw = (u16)(ch | 0x1900);
        imp_libsd_7(sw, imp_libsd_8(sw) | s->f1C);
        sw = (u16)(ch | 0x1b00);
        imp_libsd_7(sw, imp_libsd_8(sw) | s->f1C);
    } else {
        flags = 0x0c00;
        sw = (u16)(ch | 0x1800);
        imp_libsd_7(sw, imp_libsd_8(sw) | s->f1C);
        sw = (u16)(ch | 0x1a00);
        imp_libsd_7(sw, imp_libsd_8(sw) | s->f1C);
        sw = (u16)(ch | 0x1900);
        imp_libsd_7(sw, imp_libsd_8(sw) & ~s->f1C);
        sw = (u16)(ch | 0x1b00);
        imp_libsd_7(sw, imp_libsd_8(sw) & ~s->f1C);
    }
    sw = (u16)(ch | 0x1400);
    imp_libsd_7(sw, imp_libsd_8(sw) & ~s->f1C);
    sw = (u16)(ch | 0x1300);
    imp_libsd_7(sw, imp_libsd_8(sw) & ~s->f1C);

    vidx = *(u8 *)(s->f0 + 311);
    vp = (u8 *)((u32)(vidx * 116) + (u32)D_0192F0);
    *(s32 *)(vp + 76) = flags;
    *(s32 *)(vp + 192) = flags;
    imp_libsd_7((u16)(ch | 0x1500), s->f1C);
}
