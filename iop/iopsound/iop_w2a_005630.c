#include "iopsound.h"

typedef struct Track {
    u8 *ptr;            /* 0x000 */
    u8 pad004[0xc8];
    s32 rand_pitch;     /* 0x0cc */
    s32 rand_vol;       /* 0x0d0 */
    s32 rand_pan;       /* 0x0d4 */
    s32 unk0d8;         /* 0x0d8 */
    s32 rand_ar;        /* 0x0dc */
    u8 pad0e0[0x08];
    u32 flags;          /* 0x0e8 */
} Track;

void func_005630(void *seq, void *q, Track *trk) {
    s32 cmd = *trk->ptr++;
    s32 val = *trk->ptr++;

    val = (val == 0) ? 256 : val + 1;

    switch (cmd) {
    case 1:
        trk->rand_vol = val;
        trk->flags |= 0x8000;
        break;
    case 2:
        trk->rand_pan = val;
        trk->flags |= 0x10000;
        break;
    case 3:
        trk->unk0d8 = val;
        trk->flags |= 0x20000;
        break;
    case 4:
        trk->rand_ar = val;
        trk->flags |= 0x40000;
        break;
    default:
        trk->rand_pitch = val;
        trk->flags |= 0x4000;
        break;
    }
}
