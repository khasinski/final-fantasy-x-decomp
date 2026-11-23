#include "common.h"
#include "vu0.h"

typedef struct {
    u8 pad0[0x14];
    void *unk14;
} Unk1F38Task;

typedef struct {
    u8 pad0[0x22C];
    s32 unk22C;
} Unk1F38Trail;

typedef struct {
    u8 pad0[0xD0];
    float unkD0[4];
    u8 padE0[0x180];
    float unk260[4];
    float unk270[4];
    u8 unk280[0x40];
    Unk1F38Trail unk2C0;
    u8 pad4F0[0x20];
    s32 unk510;
    s32 unk514;
} Unk1F38Item;

typedef struct {
    u8 pad0[0x2B68];
    s32 unk2B68;
    s32 unk2B6C;
    s32 unk2B70;
} Unk1F38Block;

typedef struct {
    u8 pad0[0x30B0];
    Unk1F38Block unk30B0;
} Unk1F38Work;

extern u8 D_01B0B2D0;
extern Unk1F38Work *D_01B0B398;

extern s32 func_00116068(void);
extern void func_002DD128(float *);
extern void func_01B01B58(s32, float *);
extern void func_01B01E90(void *, void *, s32);
extern void func_01B03F18(void *, float *, float *);
extern void func_01B04478(void *, float *, s32);
extern void func_01B07080(Unk1F38Task *);
extern s32 func_01B07828(void *, void *);

static inline void copy_vec(void *dst, void *src) {
    MMI_COPY_LQ_A3(dst, src);
    MMI_COPY_SQ_A3(dst);
}

void func_01B01F38(Unk1F38Task *arg0) {
    float mat[16];
    float pos[4];
    Unk1F38Item *item = (Unk1F38Item *)arg0->unk14;
    Unk1F38Block *blk = &D_01B0B398->unk30B0;
    Unk1F38Trail *trail = &item->unk2C0;
    s32 i;

    if (item->unk510 > 0) {
        if (func_00116068() != 0) {
            item->unk510--;
        }
    }

    if (item->unk510 >= 0) {
        float t = (float)item->unk510 / (float)item->unk514;
        for (i = 0; i < 3; i++) {
            pos[i] = item->unk270[i] * (1.0f - t) + item->unk260[i] * t;
        }
        pos[3] = 1.0f;

        if (func_00116068() != 0) {
            func_01B01B58(blk->unk2B68, pos);
        }
        func_01B04478(item->unk280, pos, 0x80);
        MMI_COPY_LQ_A3(pos, pos);
        MMI_COPY_SQ_A3(item->unkD0);

        if (item->unk510 == 0) {
            func_01B01E90(item, item->unk280, blk->unk2B68);
            if (blk->unk2B68 != 0) {
                func_01B07828(&D_01B0B2D0, item);
                blk->unk2B70++;
                func_01B07080(arg0);
                return;
            }
            item->unk510--;
        }
    } else {
        if (trail->unk22C > 0) {
            if (func_00116068() != 0) {
                trail->unk22C--;
            }
            MMI_COPY_LQ_A3(pos, item->unk270);
            MMI_COPY_SQ_A3(pos);
        } else {
            blk->unk2B70++;
            func_01B07080(arg0);
            return;
        }
    }

    if (blk->unk2B68 == 0) {
        func_002DD128(mat);
        mat[10] = 0.2f;
        mat[5] = 0.2f;
        mat[0] = 0.2f;
        func_01B03F18(trail, mat, pos);
    }
}
