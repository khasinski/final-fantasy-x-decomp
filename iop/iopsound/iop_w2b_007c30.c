#include "iopsound.h"

typedef struct Track {
    u8 *ptr;            /* 0x000 */
    u8 pad004[0x48];
    s32 unk4C;          /* 0x04C */
    s32 unk50;          /* 0x050 */
    s32 unk54;          /* 0x054 */
    u8 pad058[0x88];
    s32 se_id;          /* 0x0E0 */
    u8 pad0E4[0x58];
} Track; /* size 0x13C = 316 */

typedef struct DriverState {
    u8 pad000[0x720];
    Track *se_tracks;   /* 0x720 */
} DriverState;

extern s32 D_019328;
extern DriverState *D_01936C;

s32 func_007C30(s32 se_id, s32 time, s32 target) {
    Track *trk;

    target <<= 12;
    target |= 0x800;
    time *= 96;
    if (D_019328 != 120) {
        time *= 60;
        time /= 50;
    }
    time /= 60;

    trk = D_01936C->se_tracks;
    do {
        if (trk->ptr != NULL) {
            if (se_id == -1 || trk->se_id == se_id) {
                trk->unk50 = (target - trk->unk4C) / time;
                trk->unk54 = time;
            }
        }
        trk++;
    } while (trk < D_01936C->se_tracks + 24);

    return 0;
}
