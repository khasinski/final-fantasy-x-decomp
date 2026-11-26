#include "iopsound.h"

typedef struct Track {
    u8 *ptr;            /* 0x000 */
    u8 pad004[0x3C];
    s32 pan;            /* 0x040 */
    s32 pan_step;       /* 0x044 */
    s32 pan_cnt;        /* 0x048 */
    s32 vol;            /* 0x04C */
    s32 vol_step;       /* 0x050 */
    s32 vol_cnt;        /* 0x054 */
    u8 pad058[0x88];
    s32 se_id;          /* 0x0E0 */
    u8 pad0E4[0x08];
    u32 flagsEC;        /* 0x0EC */
    u8 pad0F0[0x47];
    u8 voice_idx;       /* 0x137 */
    u8 pad138[0x04];
} Track; /* size 0x13C = 316 */

typedef struct Voice {
    Track *trk;         /* 0x00 */
    u8 pad04[0x64];
    u32 flags68;        /* 0x68 */
    u8 pad6C[0x08];
} Voice; /* size 0x74 = 116 */

typedef struct DriverState {
    u8 pad000[0x720];
    Track *se_tracks;   /* 0x720 */
} DriverState;

extern DriverState *D_01936C;
extern Voice *D_0192F0;
extern s32 D_019328;

s32 func_007D38(s32 se_id, s32 time) {
    Track *trk;
    s32 ticks;

    time *= 3;
    trk = D_01936C->se_tracks;
    ticks = time * 32;
    if (D_019328 != 120) {
        ticks *= 60;
        ticks /= 50;
    }
    ticks /= 60;

    do {
        if (trk->ptr != NULL) {
            if (se_id == -1 || trk->se_id == se_id) {
                trk->vol_step = (0x800 - trk->vol) / ticks;
                trk->vol_cnt = ticks;
                trk->flagsEC |= 0x100;
            }
        }
    } while (++trk < D_01936C->se_tracks + 24);
    return 0;
}

s32 func_007E44(s32 se_id, s32 pan) {
    Track *trk;

    pan = (pan + 64) << 12;
    trk = D_01936C->se_tracks;
    do {
        if (trk->ptr != NULL) {
            if (se_id == -1 || trk->se_id == se_id) {
                D_0192F0[trk->voice_idx].flags68 |= 2;
                trk->pan = pan;
                trk->pan_cnt = 0;
            }
        }
    } while (++trk < D_01936C->se_tracks + 24);
    return 0;
}
