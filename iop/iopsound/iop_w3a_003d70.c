#include "iopsound.h"

typedef struct Track {
    u8 *ptr;            /* 0x000 */
    u8 pad004[0x3C];    /* 0x004 */
    s32 unk040;         /* 0x040 */
    s32 unk044;         /* 0x044 */
    s32 unk048;         /* 0x048 */
    u8 pad04C[0x58];    /* 0x04C */
    s32 unk0a4;         /* 0x0A4 */
    u8 pad0A8[0x14];    /* 0x0A8 */
    s32 unk0bc;         /* 0x0BC */
} Track;

extern u32 D_0193A0;

void func_003D70(void *seq, void *q, Track *trk) {
    s32 val;

    val = (s8)*trk->ptr++;
    trk->unk040 = (val + 64) << 12;
    trk->unk044 = 0;
    trk->unk048 = 0;
    if (trk->unk0a4 == 0) {
        trk->unk0bc = 0;
    }
    D_0193A0 |= 2;
}
