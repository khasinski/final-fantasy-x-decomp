#include "iopsound.h"

typedef struct Track Track;
typedef struct Seq Seq;
typedef struct SaveData SaveData;

struct SaveData {
    u8 *ptr[49];        /* 0x000 */
    s32 f4[49];         /* 0x0c4 */
    u32 f0[49];         /* 0x188 */
    u32 u24[49];        /* 0x24c */
};

struct Track {
    u8 *ptr;            /* 0x000 */
    u8 pad004[0x20];    /* 0x004 */
    u32 unk024_w;       /* 0x024 */
    u8 pad028[0xc8];    /* 0x028 */
    u32 flags;          /* 0x0f0 */
    s32 unk0f4;         /* 0x0f4 */
    u8 pad0f8[0x44];    /* 0x0f8 */
}; /* size 0x13c = 316 */

struct Seq {
    Track *tracks;      /* 0x000 */
    u8 pad004[0x08];    /* 0x004 */
    s32 unk00c[4];      /* 0x00c */
    u8 pad01c[0x0c];    /* 0x01c */
    SaveData save;      /* 0x028 */
    s32 unk338[3];      /* 0x338 */
    s32 unk344;         /* 0x344 */
    s32 unk348[4];      /* 0x348 */
    s32 unk358[3];      /* 0x358 */
    u8 pad364[0x0c];    /* 0x364 */
    u32 unk370;         /* 0x370 */
    u8 pad374[0x16];    /* 0x374 */
    s16 unk38a;         /* 0x38a */
    u8 unk38c;          /* 0x38c */
    u8 num_tracks;      /* 0x38d */
    u8 pad38e[2];       /* 0x38e */
}; /* size 0x390 = 912 */

extern Seq *D_019374;
extern void *D_019314;

extern s32 func_00617C(Seq *, void *, Track *, s32);
extern void func_009360(void *, void *, s32);

void func_000824(void) {
    if (func_00617C(D_019374, D_019314, D_019374->tracks, 1) == 0) {
        do {
            Seq *seq = D_019374;
            SaveData *sd;
            Track *t;
            s32 n;
            s32 i;

            if (!(seq->unk370 & 1)) {
                break;
            }
            seq->unk38a = seq->unk344;
            func_009360(seq->unk348, seq->unk00c, 16);
            func_009360(D_019374->unk338, D_019374->unk358, 12);
            sd = &D_019374->save;
            t = D_019374->tracks;
            n = D_019374->num_tracks;
            i = 0;
            do {
                t->ptr = sd->ptr[i];
                t->unk0f4 = sd->f4[i];
                t->flags = sd->f0[i];
                t->unk024_w = sd->u24[i];
                i++;
                t++;
            } while (--n != 0);
        } while (func_00617C(D_019374, D_019314, D_019374->tracks, 1) == 0);
    }
}
