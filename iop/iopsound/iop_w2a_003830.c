#include "iopsound.h"

typedef struct Track {
    u8 *ptr;            /* 0x000 */
} Track;

typedef struct Seq {
    u8 pad000[0x14];
    s32 unk014;         /* 0x014 */
    s16 unk018;         /* 0x018 */
    s16 unk01a;         /* 0x01a */
} Seq;

void func_003830(Seq *seq, void *q, Track *trk) {
    s16 d;

    seq->unk018 = trk->ptr[0];
    d = 1;
    if (trk->ptr[1] != 0) {
        d = trk->ptr[1];
    }
    seq->unk01a = d;
    seq->unk014 = (192 / d) * seq->unk018;
    trk->ptr += 2;
}
