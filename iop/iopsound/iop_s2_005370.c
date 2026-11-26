#include "iopsound.h"

typedef struct Seq {
    u8 pad000[0x38C];
    u8 unk38C;
    u8 pad38D[2];
    u8 unk38F;
} Seq;

typedef struct Track {
    u8 *ptr;            /* 0x000 */
    u8 pad004[0xE4];
    u32 flags;          /* 0x0E8 */
    u8 pad0EC[0x34];
    s16 unk120;         /* 0x120 */
    s16 unk122;         /* 0x122 */
} Track;

extern s32 D_01933C;
extern u32 D_01931C[];

void func_005370(Seq *seq, s32 a1, Track *trk) {
    D_01933C = 1;
    trk->flags |= 0x3C00;
}

void func_00538C(Seq *seq, s32 a1, Track *trk) {
    D_01933C = 1;
    trk->flags = (trk->flags & ~0x3000) | 0x0C00;
}

void func_0053B0(Seq *seq, s32 a1, Track *trk) {
    trk->flags &= ~0x3C00;
    switch (trk->ptr[0]) {
    case 1:
        trk->flags |= 0x1000;
        break;
    case 2:
        trk->flags |= 0x1000;
        /* fallthrough */
    default:
        trk->flags |= 0x0400;
        break;
    }
    switch (trk->ptr[1]) {
    case 1:
        trk->flags |= 0x2000;
        break;
    case 2:
        trk->flags |= 0x2000;
        /* fallthrough */
    default:
        trk->flags |= 0x0800;
        break;
    }
    D_01933C = 1;
    trk->ptr += 2;
}

void func_005474(Seq *seq, s32 a1, Track *trk) {
    D_01933C = 1;
    trk->flags |= 0x0200;
}

void func_005490(Seq *seq, s32 a1, Track *trk) {
    D_01933C = 1;
    trk->flags &= ~0x0200;
}

void func_0054B0(Seq *seq, s32 a1, Track *trk) {
    D_01933C = 1;
    trk->flags |= 0x0100;
}

void func_0054CC(Seq *seq, s32 a1, Track *trk) {
    D_01933C = 1;
    trk->flags &= ~0x0100;
}

void func_0054EC(Seq *seq, s32 a1, Track *trk) {
    s32 b = *trk->ptr++;
    if (b < 64) {
        seq->unk38F = b;
    } else if (b < 96) {
        s32 d = (b & 0x1F) + 1;
        seq->unk38F = (seq->unk38F + d) & 0x3F;
    } else {
        s32 d = (b & 0x1F) - 32;
        seq->unk38F = (seq->unk38F + d) & 0x3F;
    }
    D_01931C[0] |= 2;
}

void func_005560(Seq *seq, s32 a1, Track *trk) {
    s32 b = (s8)*trk->ptr++;
    if (b != 0) {
        trk->unk120 += b;
    } else {
        trk->unk120 = 0;
    }
    trk->unk122 = 0;
    if (trk->unk120 < -9999) {
        trk->unk120 = -9999;
    } else if (trk->unk120 > 9999) {
        trk->unk120 = 9999;
    }
}

void func_0055C8(Seq *seq, s32 a1, Track *trk) {
    s32 b = *trk->ptr++;
    trk->unk120 = 0;
    if (b != 0) {
        trk->unk122 += b;
    } else {
        trk->unk122 = 0;
    }
    if (trk->unk122 < -9999) {
        trk->unk122 = -9999;
    } else if (trk->unk122 > 9999) {
        trk->unk122 = 9999;
    }
}
