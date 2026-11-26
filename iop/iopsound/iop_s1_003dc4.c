#include "iopsound.h"

typedef struct Track Track;
typedef struct Voice Voice;

struct Track {
    u8 *ptr;            /* 0x000 */
    u8 pad004[0x3c];    /* 0x004 */
    s32 unk040;         /* 0x040 */
    s32 unk044;         /* 0x044 */
    s32 unk048;         /* 0x048 */
    u8 pad04c[0x58];    /* 0x04c */
    s32 unk0a4;         /* 0x0a4 */
    u8 pad0a8[0x14];    /* 0x0a8 */
    s32 unk0bc;         /* 0x0bc */
    u8 pad0c0[0x30];    /* 0x0c0 */
    u32 flags;          /* 0x0f0 */
    s32 unk0f4;         /* 0x0f4 */
    s32 unk0f8;         /* 0x0f8 */
    s32 unk0fc;         /* 0x0fc */
    s32 unk100;         /* 0x100 */
    s32 unk104;         /* 0x104 */
    s32 unk108;         /* 0x108 */
    s32 unk10c;         /* 0x10c */
};

struct Voice {
    Track *trk;         /* 0x00 */
    u8 pad04[0x50];     /* 0x04 */
    u32 unk54;          /* 0x54 */
    u8 pad58[0x1c];     /* 0x58 */
}; /* size 0x74 = 116 */

extern Voice *D_0192F0;
extern s32 func_002CC0(s32 *, s32, s32 *);
extern s32 func_006118(void *);

void func_003DC4(void *seq, void *q, Track *trk) {
    s32 cnt;

    cnt = func_006118(trk);
    if (cnt == 0) {
        cnt = 1;
    }
    if (trk->unk0a4 == 0) {
        trk->unk040 += trk->unk0bc << 12;
        trk->unk0bc = 0;
    }
    trk->unk044 = func_002CC0(&trk->unk040, ((s8)*trk->ptr++) + 64, &cnt);
    trk->unk048 = cnt;
}

void func_003E4C(void *seq, void *q, Track *trk) {
    trk->unk104 = func_006118(trk);
}

void func_003E78(void *seq, void *q, Track *trk) {
    trk->unk104 = 0;
    trk->unk10c = -1;
}

void func_003E88(void *seq, void *q, Track *trk) {
    trk->flags = (trk->flags | 0x80000) & ~0x100000;
}

void func_003EA8(void *seq, void *q, Track *trk) {
    trk->flags &= ~0x80000;
}

void func_003EC0(void *seq, void *q, Track *trk) {
    s32 zero;
    s32 cnt;
    s32 val;
    Voice *v;
    Voice *vend;

    cnt = func_006118(trk);
    if (cnt == 0) {
        cnt = 1;
    }
    val = (s8)*trk->ptr++;
    zero = 0;
    trk->unk100 = func_002CC0(&zero, val << 8, &cnt);
    trk->unk0fc = cnt;
    trk->unk10c &= ~0xfff;
    v = D_0192F0;
    vend = v + 48;
    do {
        if (v->trk == trk) {
            v->unk54 &= ~0xfff;
        }
        v++;
    } while (v < vend);
}

void func_003F7C(void *seq, void *q, Track *trk) {
    trk->flags |= 0x200000;
}

void func_003F90(void *seq, void *q, Track *trk) {
    trk->flags &= ~0x200000;
}
