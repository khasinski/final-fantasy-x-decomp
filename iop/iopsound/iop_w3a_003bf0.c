#include "iopsound.h"

typedef struct Track {
    u8 *ptr;            /* 0x000 */
    u8 pad004[0x24];    /* 0x004 */
    s32 unk028;         /* 0x028 */
    s32 unk02c;         /* 0x02C */
    s32 unk030;         /* 0x030 */
} Track;

extern u32 D_0193A0;

void func_003BF0(void *seq, void *q, Track *trk) {
    s32 val;

    val = ((s8)*trk->ptr++) << 19;
    if (val > 0) {
        val += 0x80000;
        val -= 0x1000;
    }
    trk->unk028 = val;
    trk->unk02c = 0;
    trk->unk030 = 0;
    D_0193A0 |= 2;
}
