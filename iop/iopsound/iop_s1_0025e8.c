#include "iopsound.h"

typedef struct Track Track;
typedef struct Seq Seq;
typedef struct Voice Voice;
typedef struct QueueEntry QueueEntry;
typedef struct Slide Slide;

struct Slide {
    s32 val;
    s32 step;
    s32 cnt;
};

struct Track {
    u8 *ptr;            /* 0x000 */
    u8 pad004[0x18];    /* 0x004 */
    void *unk01c;       /* 0x01c */
    u8 pad020[0x44];    /* 0x020 */
    s32 (*vib_fn)(s32); /* 0x064 */
    u8 pad068[0x1c];    /* 0x068 */
    s32 (*trm_fn)(s32); /* 0x084 */
    u8 pad088[0x1c];    /* 0x088 */
    s32 (*pan_fn)(s32); /* 0x0a4 */
    s32 pan_step;       /* 0x0a8 */
    s32 unk0ac;         /* 0x0ac */
    s32 pan_depth;      /* 0x0b0 */
    s32 unk0b4;         /* 0x0b4 */
    u32 pan_phase;      /* 0x0b8 */
    s32 pan_out;        /* 0x0bc */
    u8 pad0c0[0x28];    /* 0x0c0 */
    u32 unk0e8;         /* 0x0e8 */
    u8 pad0ec[0x50];    /* 0x0ec */
}; /* size 0x13c = 316 */

struct Seq {
    Track *tracks;      /* 0x000 */
    u8 pad004[0x18];    /* 0x004 */
    s32 unk01c;         /* 0x01c */
    u8 pad020[0x344];   /* 0x020 */
    s32 unk364;         /* 0x364 */
    u8 pad368[0x08];    /* 0x368 */
    u32 unk370;         /* 0x370 */
    u8 pad374[0x16];    /* 0x374 */
    s16 unk38a;         /* 0x38a */
    u8 unk38c;          /* 0x38c */
    u8 num_tracks;      /* 0x38d */
    s8 unk38e;          /* 0x38e */
    u8 unk38f;          /* 0x38f */
}; /* size 0x390 = 912 */

struct Voice {
    Track *trk;         /* 0x00 */
    u8 pad04[0x64];     /* 0x04 */
    u32 unk68;          /* 0x68 */
    u8 pad6c[0x08];     /* 0x6c */
}; /* size 0x74 = 116 */

struct QueueEntry {
    Track *trk;         /* 0x00 */
    u32 w;              /* 0x04 */
}; /* size 8 */

extern s32 D_01874C;
extern QueueEntry *D_019314;
extern Voice *D_0192F0;
extern Seq *D_01936C;
extern Seq *D_019374;
extern Slide D_122460;
extern u32 D_01931C;
extern s32 D_018724;

extern void func_0012D8(void);
extern Voice *func_002468(Track *, void *, u32 *);
extern void func_0014B4(Voice *, s32);
extern void func_001810(Voice *);
extern void func_0019D0(Voice *, s32);

void func_0025E8(void) {
    u32 kon[2];
    Voice *v;
    s32 val;
    Slide *sl;

    func_0012D8();
    kon[1] = 0;
    kon[0] = 0;

    if (D_01874C != 0) {
        QueueEntry *q = D_019314;

        v = D_0192F0;
        do {
            if (q->trk != NULL && q->trk->unk01c != NULL) {
                v = func_002468(q->trk, &q->w, kon);
            }
            q++;
        } while (v != NULL && q < D_019314 + 144);
    }

    if (D_01936C[0].unk38a != 0 && !(D_01936C[0].unk370 & 0x10)) {
        Seq *seq = &D_01936C[0];
        Track *t = seq->tracks;

        do {
            if (t->ptr != NULL && t->pan_fn != NULL) {
                val = (t->pan_depth >> 12) + 1;
                val *= t->pan_fn(t->pan_phase >> 12);
                val >>= 16;
                t->pan_out = val;
                t->pan_phase += t->pan_step;
            }
            t++;
        } while (t < &seq->tracks[seq->num_tracks]);
    }

    if (D_01936C[1].unk38a != 0 && !(D_01936C[1].unk370 & 0x10)) {
        Seq *seq = &D_01936C[1];
        Track *t = seq->tracks;

        do {
            if (t->ptr != NULL && t->pan_fn != NULL) {
                val = (t->pan_depth >> 12) + 1;
                val *= t->pan_fn(t->pan_phase >> 12);
                val >>= 16;
                t->pan_out = val;
                t->pan_phase += t->pan_step;
            }
            t++;
        } while (t < &seq->tracks[seq->num_tracks]);
    }

    {
        Seq *seq = &D_01936C[2];
        Track *t = seq->tracks;

        do {
            if (t->ptr != NULL && t->pan_fn != NULL) {
                val = (t->pan_depth >> 12) + 1;
                val *= t->pan_fn(t->pan_phase >> 12);
                val >>= 16;
                t->pan_out = val;
                t->pan_phase += t->pan_step;
            }
            t++;
        } while (t < &seq->tracks[24]);
    }

    v = D_0192F0;
    val = 0;
    sl = &D_122460;
    do {
        if (v->trk != NULL) {
            if (!(v->trk->unk0e8 & 8)) {
                if ((v->unk68 & 2) || v->trk->trm_fn != NULL || v->trk->pan_fn != NULL) {
                    s32 mvol;

                    if (v->trk >= D_019374[0].tracks && v->trk < &D_019374[0].tracks[D_019374[0].num_tracks]) {
                        mvol = (D_01936C[0].unk38e + 1) * (D_01936C[0].unk01c >> 12);
                        mvol >>= 7;
                        if (sl->cnt != 0) {
                            mvol *= sl->val >> 12;
                            mvol >>= 9;
                        }
                    } else if (v->trk >= D_019374[1].tracks && v->trk < &D_019374[1].tracks[D_019374[1].num_tracks]) {
                        mvol = (D_01936C[1].unk38e + 1) * (D_01936C[1].unk01c >> 12);
                        mvol >>= 7;
                        if (sl->cnt != 0) {
                            mvol *= 512 - (sl->val >> 12);
                            mvol >>= 9;
                        }
                    } else {
                        mvol = 511;
                    }
                    func_0014B4(v, mvol);
                }
                if ((v->unk68 & 1) | (u32)v->trk->vib_fn) {
                    func_001810(v);
                }
                v->unk68 = 0;
            }
            val++;
        }
        v++;
    } while (v < D_0192F0 + 48);

    D_018724 = val;
    {
        u32 *flag = &D_01931C;

        if (*flag != 0) {
            if (*flag & 1) {
                func_0019D0(D_0192F0, 0);
            }
            if (*flag & 2) {
                imp_libsd_11(8, (u16)(s8)D_01936C[0].unk38f);
                imp_libsd_11(9, (u16)(s8)D_01936C[2].unk38f);
            }
            if (*flag & 4) {
                imp_libsd_5(0xb80, (u16)(D_019374->unk364 >> 4));
                imp_libsd_5(0xc80, (u16)(D_019374->unk364 >> 4));
                imp_libsd_5(0xb81, (u16)(D_019374->unk364 >> 4));
                imp_libsd_5(0xc81, (u16)(D_019374->unk364 >> 4));
            }
            *flag = 0;
        }
    }

    if (kon[0] != 0) {
        imp_libsd_7(0x1500, kon[0]);
    }
    if (kon[1] != 0) {
        imp_libsd_7(0x1501, kon[1]);
    }
}
