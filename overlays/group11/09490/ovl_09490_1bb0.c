#include "common.h"
#include "vu0.h"

typedef struct {
    u8 pad0[0x213];
    u8 unk213;
    u8 pad214[0x8];
    float unk21C;
    float unk220;
    u8 pad224[0x8];
    s32 unk22C;
} Unk1BB0Trail;

typedef struct {
    float unk0[4];
    u8 pad10[0x2900];
    Unk1BB0Trail unk2910;
    u8 pad2B40[0x24];
    s32 unk2B64;
    s32 unk2B68;
} Unk1BB0Block;

typedef struct {
    u8 pad0[0x30B0];
    Unk1BB0Block unk30B0;
} Unk1BB0Work;

extern u8 D_01B0B2D0;
extern Unk1BB0Work *D_01B0B398;

extern s32 func_00116068(void);
extern void func_002DD128(float *);
extern void func_01B01B58(s32, float *);
extern void func_01B03E00(float *);
extern void func_01B03E98(void *, s32);
extern void func_01B03F18(void *, float *, float *);
extern void func_01B07080(void *);
extern s32 *func_01B07948(void *, s32);

static inline void copy_vec(void *dst, void *src) {
    MMI_COPY_LQ_A3(dst, src);
    MMI_COPY_SQ_A3(dst);
}

void func_01B01BB0(void *arg0) {
    float mat[16];
    float pos[4];
    Unk1BB0Block *blk = &D_01B0B398->unk30B0;
    Unk1BB0Trail *trail;

    if (blk->unk2B64 > 0) {
        if (func_00116068() != 0) {
            blk->unk2B64--;
        }
    }

    trail = &blk->unk2910;
    func_01B03E00(pos);

    if (blk->unk2B64 <= 0) {
        if (blk->unk2B68 == 0 && trail->unk22C > 0) {
            if (func_00116068() != 0) {
                trail->unk22C--;
            }
            MMI_COPY_LQ_A3(pos, blk->unk0);
            MMI_COPY_SQ_A3(pos);
        } else {
            func_01B07080(arg0);
            return;
        }
    } else {
        if (func_00116068() != 0) {
            func_01B01B58(blk->unk2B68, pos);
        }
        MMI_COPY_LQ_A3(blk->unk0, pos);
        MMI_COPY_SQ_A3(blk->unk0);
    }

    if (blk->unk2B68 == 0) {
        func_002DD128(mat);
        mat[10] = 0.2f;
        mat[5] = 0.2f;
        mat[0] = 0.2f;
        func_01B03F18(trail, mat, pos);
    }
}

void func_01B01CE8(Unk1BB0Trail *arg0) {
    func_01B03E98(arg0, *func_01B07948(&D_01B0B2D0, 9));
    arg0->unk22C = 0x10;
    arg0->unk220 = 1.0f;
    arg0->unk21C = 0.5f;
    arg0->unk213 = 0x40;
}
