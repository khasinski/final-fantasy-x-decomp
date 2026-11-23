#include "common.h"

typedef struct {
    u8 pad0[0x1C];
} Reel35F0;

typedef struct {
    Reel35F0 reels[3];
    s32 unk54;
    s32 unk58;
    s32 unk5C;
    s32 unk60;
    s32 unk64;
    s32 unk68;
    s32 unk6C;
    s32 unk70;
    s32 unk74;
    float unk78;
} ReelGroup35F0;

typedef struct {
    ReelGroup35F0 groups[4];
    s32 unk1F0[4];
    s32 cur_idx;
    s32 count;
    s32 state;
} SlotMgr35F0;

extern SlotMgr35F0 D_01B0DF88;
extern u8 D_01C03DD0[];

extern void *op_oef2_a_get(void *, s32, s32);
extern void op_oef2_texture_load(void *, s32);
extern void op_oef2_clut_load(void *, s32);
extern s32 func_01B024A8(Reel35F0 *);
extern void func_01B02A10(void);
extern void func_01B02AA0(void);
extern void func_01B02B30(s32, s32, s32, s32, s32, s32, s32);
extern void func_01B02E18(s32, s32, s32, s32, s32, s32, s32);
extern void func_01B03318(Reel35F0 *, s32, s32);

void func_01B035F0(ReelGroup35F0 *grp, s32 x, s32 y) {
    s32 i;
    s32 alpha;
    Reel35F0 *r;
    s32 sx = x;
    s32 sy = y << 4;

    if (grp->unk6C > 0) {
        grp->unk6C--;
    }

    {
        s32 d = 8;
        alpha = ((d - grp->unk6C) * 0x80) / d;
    }
    r = grp->reels;
    for (i = 0; i < 3; i++, r++) {
        s32 sym = func_01B024A8(r);
        func_01B02B30(sym, sx, sy, 0x28, 0x19, 0x80, alpha);
        sx += 0x28;
    }

    func_01B02E18(x - 2, y - 2, 0x7C, 0x1D, 0x40, 0x20, alpha);
}

void func_01B036E0(void) {
    SlotMgr35F0 *mgr = &D_01B0DF88;
    ReelGroup35F0 *g;
    s32 i, j;

    for (i = 0xC; i < 0x17; i++) {
        op_oef2_texture_load(op_oef2_a_get(D_01C03DD0, 2, i), 0);
        op_oef2_clut_load(op_oef2_a_get(D_01C03DD0, 3, i), 0);
    }

    func_01B02A10();

    g = mgr->groups;
    for (i = 0; i < mgr->count; i++, g++) {
        if (g->unk74 == 1) {
            Reel35F0 *r = g->reels;
            for (j = 0; j < 3; j++) {
                func_01B03318(r++, g->unk58 + j * 0x3F, g->unk5C);
            }
        }
    }

    g = mgr->groups;
    for (i = 0; i < mgr->count - 1; i++) {
        if (i < mgr->cur_idx) {
            func_01B035F0(g, 0x41 + i * 0x82, 0x4E);
        }
        g++;
    }

    func_01B02AA0();
}
