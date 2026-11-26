#include "iopsound.h"

typedef struct Track {
    u8 *ptr;            /* 0x000 */
    u8 pad004[0x12C];   /* 0x004 */
    u8 unk130;          /* 0x130 */
} Track;

extern u32 D_0193A0;

void func_00511C(void *seq, void *q, Track *trk) {
    trk->unk130 = *trk->ptr++;
    D_0193A0 |= 1;
}

void func_005154(void *seq, void *q, Track *trk) {
    trk->unk130 += *trk->ptr++;
    D_0193A0 |= 1;
}
