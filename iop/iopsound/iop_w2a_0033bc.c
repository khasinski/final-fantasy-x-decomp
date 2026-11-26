#include "iopsound.h"

typedef struct SaveData {
    u8 *ptr[49];        /* 0x000 */
    s32 f4[49];         /* 0x0c4 */
    u32 f0[49];         /* 0x188 */
    u32 u24[49];        /* 0x24c */
} SaveData;

typedef struct Track {
    u8 *ptr;            /* 0x000 */
    u8 pad004[0x20];
    u32 unk024_w;       /* 0x024 */
    u8 pad028[0xc8];
    u32 flags;          /* 0x0f0 */
    s32 unk0f4;         /* 0x0f4 */
    u8 pad0f8[0x44];
} Track; /* size 0x13c = 316 */

typedef struct Seq {
    Track *tracks;      /* 0x000 */
    u8 pad004[0x08];
    s32 unk00c[4];      /* 0x00c */
    u8 pad01c[0x0c];
    SaveData save;      /* 0x028 */
    s32 unk338[3];      /* 0x338 */
    s32 unk344;         /* 0x344 */
    s32 unk348[4];      /* 0x348 */
    s32 unk358[3];      /* 0x358 */
    u8 pad364[0x0c];
    u32 unk370;         /* 0x370 */
    u8 pad374[0x16];
    s16 unk38a;         /* 0x38a */
    u8 unk38c;          /* 0x38c */
    u8 num_tracks;      /* 0x38d */
    u8 pad38e[2];
} Seq; /* size 0x390 = 912 */

extern Seq *D_01936C;
extern s32 D_019340;
extern s32 D_019344;

extern s32 func_006118(u8 **);
extern void func_009360(void *, void *, s32);

void func_0033BC(Seq *seq, void *q, Track *trk) {
    s32 tick;

    if (seq == &D_01936C[3]) {
        tick = D_019344;
    } else {
        tick = D_019340;
    }
    if (trk == &seq->tracks[1]) {
        Track *t;
        SaveData *sd = &seq->save;
        s32 delta;
        s32 idx = 0;
        s32 n;
        u8 *tmp_ptr;
        s32 vlq;

        seq->unk370 |= 1;
        t = seq->tracks;
        delta = -trk->unk0f4 + 1;
        n = trk - t;
        while (n != 0) {
            sd->ptr[idx] = t->ptr;
            sd->f4[idx] = t->unk0f4 + delta;
            sd->f0[idx] = t->flags;
            sd->u24[idx] = t->unk024_w;
            idx++;
            t++;
            n--;
        }
        tmp_ptr = t->ptr;
        vlq = func_006118(&tmp_ptr);
        sd->ptr[idx] = tmp_ptr;
        sd->f4[idx] = t->unk0f4 + vlq + delta;
        sd->f0[idx] = t->flags;
        sd->u24[idx] = t->unk024_w;
        t++;
        idx++;
        n = seq->num_tracks - (t - seq->tracks);
        while (n != 0) {
            sd->ptr[idx] = t->ptr;
            sd->f4[idx] = t->unk0f4 - tick + delta;
            sd->f0[idx] = t->flags;
            sd->u24[idx] = t->unk024_w;
            idx++;
            t++;
            n--;
        }
        seq->unk344 = seq->unk38a;
        func_009360(seq->unk00c, seq->unk348, 16);
        seq->unk348[1] -= delta;
        func_009360(seq->unk358, seq->unk338, 12);
    }
}
