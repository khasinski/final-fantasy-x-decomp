#include "iopsound.h"

typedef struct VoiceInst {
    u8 pad00[0x10];
    s32 unk10;
} VoiceInst;

typedef struct Track {
    u8 *ptr;            /* 0x000 */
    u8 pad004[0x54];
    s32 pitch;          /* 0x058 */
    s32 pitch_step;     /* 0x05C */
    s32 pitch_cnt;      /* 0x060 */
    u8 pad064[0x7C];
    s32 se_id;          /* 0x0E0 */
    u8 pad0E4[0x42];
    s16 unk126;         /* 0x126 */
    u8 pad128[0x02];
    s16 unk12A;         /* 0x12A */
    u8 pad12C[0x04];
    s8 unk130;          /* 0x130 */
    u8 pad131[0x06];
    u8 voice_idx;       /* 0x137 */
    u8 pad138[0x04];
} Track; /* size 0x13C = 316 */

typedef struct Voice {
    Track *trk;         /* 0x00 */
    VoiceInst *inst;    /* 0x04 */
    u8 pad08[0x48];
    s32 unk50;          /* 0x50 */
    s32 unk54;          /* 0x54 */
    u8 pad58[0x10];
    u32 flags68;        /* 0x68 */
    u8 pad6C[0x08];
} Voice; /* size 0x74 = 116 */

typedef struct DriverState {
    u8 pad000[0x720];
    Track *se_tracks;   /* 0x720 */
} DriverState;

extern DriverState *D_01936C;
extern Voice *D_0192F0;

extern s32 func_0013E4(s32, s32, s32, s32);

s32 func_007FF8(s32 se_id, s32 pitch) {
    Track *trk;

    pitch <<= 12;
    trk = D_01936C->se_tracks;
    do {
        if (trk->ptr != NULL) {
            if (se_id == -1 || trk->se_id == se_id) {
                Voice *v = &D_0192F0[trk->voice_idx];
                v->unk50 = func_0013E4(v->unk54 + pitch, v->trk->unk12A + v->trk->unk126, v->inst->unk10, v->trk->unk130);
                v->flags68 |= 1;
                trk->pitch = pitch;
                trk->pitch_cnt = 0;
            }
        }
    } while (++trk < D_01936C->se_tracks + 24);
    return 0;
}
