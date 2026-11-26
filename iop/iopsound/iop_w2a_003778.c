#include "iopsound.h"

typedef struct Track {
    u8 *ptr;            /* 0x000 */
} Track;

typedef struct Seq {
    u8 pad000[0x364];
    s32 unk364;         /* 0x364 */
    s32 unk368;         /* 0x368 */
    s32 unk36c;         /* 0x36c */
} Seq;

typedef struct {
    u32 flags;
} DriverState;

extern DriverState D_01931C;

void func_003778(Seq *seq, void *q, Track *trk) {
    seq->unk364 = ((s8)*trk->ptr++) << 12;
    seq->unk368 = 0;
    seq->unk36c = 0;
    D_01931C.flags |= 4;
}
