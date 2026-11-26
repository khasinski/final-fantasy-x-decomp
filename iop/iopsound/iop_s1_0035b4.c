#include "iopsound.h"

typedef struct Track Track;
typedef struct Seq Seq;

struct Track {
    u8 *ptr;            /* 0x000 */
    s32 unk004;         /* 0x004 */
    u8 *loop_ptr[4];    /* 0x008 */
    u8 pad018[0xf8];    /* 0x018 */
    s16 loop_cnt[4];    /* 0x110 */
    s16 loop_unk[4];    /* 0x118 */
    s32 unk120;         /* 0x120 */
    s16 loop_idx;       /* 0x124 */
    s16 unk126;         /* 0x126 */
    s32 unk128;         /* 0x128 */
    s16 unk12c;         /* 0x12c */
    u8 pad12e[0x0e];    /* 0x12e */
}; /* size 0x13c = 316 */

struct Seq {
    u8 pad000[0x358];   /* 0x000 */
    s32 unk358;         /* 0x358 */
    s32 unk35c;         /* 0x35c */
    s32 unk360;         /* 0x360 */
    u8 pad364[0x0c];    /* 0x364 */
    u32 unk370;         /* 0x370 */
    u8 pad374[0x1c];    /* 0x374 */
}; /* size 0x390 = 912 */

extern s32 func_002CC0(s32 *, s32, s32 *);

void func_0035B4(Seq *seq, void *q, Track *trk) {
    seq->unk370 |= 2;
}

void func_0035C8(Seq *seq, void *q, Track *trk) {
    trk->loop_idx = (trk->loop_idx + 1) & 3;
    trk->loop_ptr[trk->loop_idx] = trk->ptr;
    trk->loop_unk[trk->loop_idx] = trk->unk12c;
    trk->loop_cnt[trk->loop_idx] = 0;
}

void func_003614(Seq *seq, void *q, Track *trk) {
    s32 max = *trk->ptr++;

    if (max == 0) {
        max = 256;
    }
    trk->loop_cnt[trk->loop_idx]++;
    if (trk->loop_cnt[trk->loop_idx] != max) {
        trk->ptr = trk->loop_ptr[trk->loop_idx];
        trk->unk12c = trk->loop_unk[trk->loop_idx];
    } else {
        trk->loop_idx = (trk->loop_idx - 1) & 3;
    }
}

void func_0036A4(Seq *seq, void *q, Track *trk) {
    trk->ptr = trk->loop_ptr[trk->loop_idx];
    trk->unk12c = trk->loop_unk[trk->loop_idx];
}

void func_0036D8(Seq *seq, void *q, Track *trk) {
    seq->unk358 = (*trk->ptr++) << 12;
    seq->unk35c = 0;
    seq->unk360 = 0;
}

void func_003700(Seq *seq, void *q, Track *trk) {
    s32 cnt;

    cnt = trk->ptr[0] ? trk->ptr[0] : 256;
    seq->unk35c = func_002CC0(&seq->unk358, trk->ptr[1], &cnt);
    seq->unk360 = cnt;
    trk->ptr += 2;
}
