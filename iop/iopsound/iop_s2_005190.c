#include "iopsound.h"

typedef struct Seq {
    u8 pad000[0x38C];
    u8 unk38C;
    u8 pad38D[2];
    u8 unk38F;
} Seq;

typedef struct Track {
    u8 *ptr;            /* 0x000 */
    u8 pad004[0x54];
    s32 unk58;          /* 0x058 */
    u8 pad05C[0xCE];
    s16 unk12A;         /* 0x12A */
    u8 pad12C[0x04];
    s8 unk130;          /* 0x130 */
} Track;

typedef struct VoiceInst {
    u8 pad00[0x10];
    s32 unk10;
} VoiceInst;

typedef struct Voice {
    Track *trk;         /* 0x00 */
    VoiceInst *inst;    /* 0x04 */
    u8 pad08[0x0E];
    u8 unk16;           /* 0x16 */
    u8 pad17[0x39];
    s32 unk50;          /* 0x50 */
    s32 unk54;          /* 0x54 */
    u8 pad58[0x10];
    u32 flags68;        /* 0x68 */
    u8 pad6C[0x08];
} Voice; /* size 0x74 = 116 */

extern Voice *D_0192F0;
extern s32 D_122440;

extern s32 func_0013E4(s32, s32, s32, s32);

void func_005190(Seq *seq, s32 a1, Track *trk) {
    trk->unk12A = *trk->ptr++ << 8;
}

void func_0051B0(Seq *seq, s32 a1, Track *trk) {
    s8 b = *trk->ptr++;
    trk->unk12A += b << 8;
}

void func_0051DC(Track *trk, s32 pitch) {
    Voice *v = D_0192F0;

    do {
        if (v->trk == trk) {
            s32 base;
            if ((v->unk16 & 3) != 0) {
                base = v->unk54 + trk->unk58;
            } else {
                base = v->unk54 + D_122440;
            }
            v->unk50 = func_0013E4(base, trk->unk12A + pitch, v->inst->unk10, trk->unk130);
            v->flags68 |= 1;
        }
    } while (++v < D_0192F0 + 48);
}
