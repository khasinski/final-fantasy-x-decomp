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
} Unk41E0Sub;

typedef struct {
    float unk0[4];
    u8 pad10[0x2B54];
    s32 unk2B64;
    s32 unk2B68;
} Unk41E0Block;

extern u8 D_01B0DEB0;
extern u8 *D_01B0DF78;

extern void func_002DD128(float (*)[4]);
extern void func_01B04188(s32, float *);
extern void func_01B069A8(float *);
extern void func_01B06A40(Unk41E0Sub *, void *);
extern void func_01B06AC0(Unk41E0Sub *, float (*)[4], float *);
extern void func_01B09C38(void *);
extern void **func_01B0A4A8(void *, s32);

void func_01B041E0(void *task) {
    float mat[4][4];
    float pos[4];
    u8 *base = D_01B0DF78;
    Unk41E0Block *blk = (Unk41E0Block *)(base + 0x30B0);
    Unk41E0Sub *sub;

    if (blk->unk2B64 > 0) {
        blk->unk2B64--;
    }
    sub = (Unk41E0Sub *)(base + 0x59C0);
    func_01B069A8(pos);
    if (blk->unk2B64 <= 0) {
        if (blk->unk2B68 == 0 && sub->unk22C > 0) {
            sub->unk22C--;
            MMI_COPY_LQ_A3(pos, blk->unk0);
            MMI_COPY_SQ_A3(pos);
        } else {
            func_01B09C38(task);
            return;
        }
    } else {
        func_01B04188(blk->unk2B68, pos);
        MMI_COPY_LQ_A3(blk->unk0, pos);
        MMI_COPY_SQ_A3(blk->unk0);
    }

    if (blk->unk2B68 == 0) {
        func_002DD128(mat);
        mat[2][2] = 0.2f;
        mat[1][1] = 0.2f;
        mat[0][0] = 0.2f;
        func_01B06AC0(sub, mat, pos);
    }
}

void func_01B042D8(Unk41E0Sub *sub) {
    func_01B06A40(sub, *func_01B0A4A8(&D_01B0DEB0, 0xA));
    sub->unk22C = 0x10;
    sub->unk220 = 1.0f;
    sub->unk21C = 0.5f;
    sub->unk213 = 0x40;
}
