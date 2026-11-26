#include "iopsound.h"

typedef struct Track {
    u8 *ptr;            /* 0x000 */
    u8 pad004[0x122];
    s16 unk126;         /* 0x126 */
    s16 unk128;         /* 0x128 */
    u8 pad12a[0x09];
    s8 unk133;          /* 0x133 */
} Track;

extern void func_0051DC(Track *, s32);

void func_0052B0(void *seq, void *q, Track *trk) {
    s32 v = (trk->ptr[0] + (trk->ptr[1] << 7)) - 8192;

    trk->unk128 = v;
    v *= trk->unk133;
    v >>= 5;
    trk->unk126 = v;
    trk->ptr += 2;
    func_0051DC(trk, trk->unk126);
}
