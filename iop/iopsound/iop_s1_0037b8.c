#include "iopsound.h"

typedef struct Track Track;
typedef struct Seq Seq;

struct Track {
    u8 *ptr;            /* 0x000 */
};

struct Seq {
    u8 pad000[0x364];   /* 0x000 */
    s32 unk364;         /* 0x364 */
    s32 unk368;         /* 0x368 */
    s32 unk36c;         /* 0x36c */
};

extern s32 func_002CC0(s32 *, s32, s32 *);

void func_0037B8(Seq *seq, void *q, Track *trk) {
    s32 cnt;

    cnt = trk->ptr[0] ? trk->ptr[0] : 256;
    seq->unk368 = func_002CC0(&seq->unk364, (s8)trk->ptr[1], &cnt);
    seq->unk36c = cnt;
    trk->ptr += 2;
}
