#include "iopsound.h"

typedef struct Track {
    u8 *ptr;            /* 0x000 */
    u8 pad004[0x30];    /* 0x004 */
    s32 unk034;         /* 0x034 */
    s32 unk038;         /* 0x038 */
    s32 unk03c;         /* 0x03C */
} Track;

extern u32 D_0193A0;

void func_003CB0(void *seq, void *q, Track *trk) {
    s32 val;

    val = ((s8)*trk->ptr++) << 19;
    if (val > 0) {
        val += 0x80000;
        val -= 0x1000;
    }
    trk->unk034 = val;
    trk->unk038 = 0;
    trk->unk03c = 0;
    D_0193A0 |= 2;
}
