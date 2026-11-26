#include "iopsound.h"

typedef struct {
    u8 pad0[0x26];
    u8 f26;
    u8 pad27[0x137 - 0x27];
    u8 f137;
    u8 pad138[0x162 - 0x138];
    u8 f162;
} StreamTrack;

typedef struct {
    StreamTrack *f0;
    u8 *f4;
    s32 f8;
    s32 fC;
    s32 f10;
    s32 f14;
    s32 f18;
    s32 f1C;
    s32 f20;
    s32 f24;
    u8 pad28[0x70 - 0x28];
} StreamCh;

typedef struct {
    u8 pad0[0x16];
    u8 f16;
    u8 pad17[116 - 0x17];
} Voice;

typedef struct {
    s32 spu_l;
    s32 spu_r;
    s32 size;
    s32 end_flag;
    void *cb;
} DmaSlot;

typedef struct {
    s32 mask;
    DmaSlot slot[2];
} DmaState;

extern StreamCh *D_018754;
extern s32 D_018710;
extern Voice *D_0192F0;
extern s32 D_019350;
extern DmaState D_06D2B0;

extern void func_00FDF4(s32, s32, s32);
extern void func_00EFBC(s32, s32);
extern void func_00F084(s32);

s32 func_00C938(s32 mask, s32 no_notify) {
    StreamCh *s;
    StreamCh *base;
    s32 ch;

    if (mask & 1) {
        s = D_018754;
        D_06D2B0.slot[0].cb = NULL;
        if (s->f1C != 0) {
            func_00FDF4(0, 0, 0);
            imp_libsd_7(0x1600, s->f1C);
            imp_libsd_9((((u16)s->f24 << 1) | 0x2140) & 0xfffe, 0x5030);
            {
                Voice *vp = D_0192F0;
                ch = s->f0->f137;
                vp[ch].f16 = 0;
            }
            imp_libsd_9(((((u16)s->f24 + 1) << 1) | 0x2140) & 0xfffe, 0x5030);
            D_0192F0[ch + 1].f16 = 0;
            s->f1C = 0;
            D_019350 &= ~4;
            if (no_notify == 0) {
                func_00EFBC(5, D_018754[0].f1C);
            }
        }
        func_00F084(21);
    }

    if (mask & 2) {
        base = D_018754;
        D_06D2B0.slot[1].cb = NULL;
        s = base + 1;
        if (s->f1C != 0) {
            func_00FDF4(1, 0, 0);
            imp_libsd_7(0x1601, s->f1C);
            D_018710 = 0;
            imp_libsd_9((u16)(((u16)s->f24 << 1) | 0x2141), 0x5030);
            {
                StreamTrack *tr = base[1].f0;
                tr->f26 = (s8)tr->f26 & ~2;
                ch = tr->f137;
                D_0192F0[ch].f16 = 0;
            }
            imp_libsd_9((u16)((((u16)s->f24 + 1) << 1) | 0x2141), 0x5030);
            base[1].f0->f162 = (s8)base[1].f0->f162 & ~2;
            D_0192F0[ch + 1].f16 = 0;
            s->f1C = 0;
            D_019350 &= ~8;
            if (no_notify == 0) {
                func_00EFBC(6, D_018754[1].f1C);
            }
        }
        func_00F084(22);
    }

    return mask;
}
