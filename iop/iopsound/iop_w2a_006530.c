#include "iopsound.h"

typedef struct Track {
    u8 *ptr;            /* 0x000 */
    u8 pad004[0xd4];
    s32 unk0d8;         /* 0x0d8 */
    u8 pad0dc[0x0c];
    u32 unk0e8;         /* 0x0e8 */
    u8 pad0ec[0x04];
    u32 flags;          /* 0x0f0 */
    s32 unk0f4;         /* 0x0f4 */
    u8 pad0f8[0x28];
    s16 unk120;         /* 0x120 */
    u8 pad122[0x1a];
} Track; /* size 0x13c = 316 */

typedef struct Seq {
    Track *tracks;      /* 0x000 */
    u8 pad004[0x08];
    s32 unk00c;         /* 0x00c */
    s32 unk010;         /* 0x010 */
    s32 unk014;         /* 0x014 */
    u8 pad018[0x34c];
    s32 unk364;         /* 0x364 */
    s32 unk368;         /* 0x368 */
    volatile s32 unk36c; /* 0x36c */
    u32 unk370;         /* 0x370 */
    s32 unk374;         /* 0x374 */
    s32 unk378;         /* 0x378 */
    u8 pad37c[0x0e];
    s16 unk38a;         /* 0x38a */
    u8 pad38c[4];
} Seq; /* size 0x390 = 912 */

typedef struct Voice {
    Track *trk;         /* 0x00 */
    u8 pad04[0x48];
    u32 unk4c;          /* 0x4c */
    u8 pad50[0x18];
    u32 unk68;          /* 0x68 */
    u8 pad6c[0x08];
} Voice; /* size 0x74 = 116 */

typedef struct {
    u32 flags;
} DriverState;

extern s32 *D_018750;
extern s32 D_019344[];
extern DriverState D_01931C;
extern u32 D_0193A0;
extern u32 D_01933C;
extern Voice *D_0192F0;
extern volatile s32 D_018748;
extern void (*D_017500[])(Seq *, void *, Track *);

extern void func_0057A0(Track *, s32);
extern void func_002E70(void *, Track *);
extern void func_00F0D4(s32);
extern s32 func_006118(Track *);
extern s32 func_009330(void);

s32 func_006530(Seq *seq, void *q, Track *trk, s32 step) {
    s32 ticks = step << *D_018750;
    s32 *bar = (s32 *)seq + 3;
    s32 adv;
    s32 v0;
    s32 r;

    do {
        s32 cnt;
        Track *t;

        seq->unk378 = ticks;
        D_019344[0] = ticks;
        bar[1] += ticks;
        while (bar[1] >= bar[2]) {
            bar[0]++;
            bar[1] -= bar[2];
        }

        {
            s32 rem = seq->unk36c;
            if (rem != 0) {
                adv = ticks;
                if (ticks >= rem) {
                    adv = rem;
                }
                seq->unk36c -= adv;
                seq->unk364 += seq->unk368 * adv;
                D_01931C.flags |= 4;
            }
        }

        cnt = seq->unk38a;
        t = trk;
        while (cnt != 0) {
            if (t->ptr != NULL) {
                s32 rem = t->unk0f4;

                D_0193A0 = 0;
                D_01933C = 0;
                if (rem < ticks) {
                    adv = rem;
                } else {
                    adv = ticks;
                }
                t->unk0f4 = rem - ticks;
                func_0057A0(t, adv);

                if (!(t->flags & 0x200000) && t->unk0f4 == 1) {
                    func_002E70(q, t);
                }

                while (t->ptr != NULL && t->unk0f4 <= 0) {
                    v0 = *t->ptr++;
                    if (v0 & 0x80) {
                        v0 = 0;
                        func_00F0D4(28);
                    }
                    D_017500[v0](seq, q, t);
                    if (t->ptr == NULL) {
                        break;
                    }
                    v0 = func_006118(t);
                    if (v0 != 0) {
                        v0 += t->unk120;
                        if (v0 <= 0) {
                            v0 = 1;
                        } else if (t->unk0e8 & 0x20000) {
                            r = (v0 * t->unk0d8) >> 8;
                            r *= (s8)func_009330();
                            r >>= 7;
                            v0 += r;
                            if (v0 <= 0) {
                                v0 = 1;
                            }
                        }
                    }
                    if (t->unk0f4 < -1) {
                        adv = (t->unk0f4 + v0 <= 0) ? v0 : -t->unk0f4;
                        func_0057A0(t, adv);
                    }
                    t->unk0f4 += v0;
                }

                if (D_01933C | D_0193A0) {
                    u32 flg = D_0193A0;
                    Voice *v;

                    r = t->unk0e8 & ~3;
                    v = D_0192F0;
                    do {
                        if (v->trk == t) {
                            v->unk68 |= flg;
                            v->unk4c = (v->unk4c & 3) | r;
                            D_01931C.flags |= 1;
                        }
                        v++;
                    } while (v < D_0192F0 + 48);
                }
                cnt--;
            }
            t++;
        }

        if (D_018748 != 0 && seq->unk38a != 0 && !(seq->unk370 & 2)) {
            ticks = bar[2];
            D_018748--;
        }
    } while (D_018748 != 0 && seq->unk38a != 0);

    seq->unk378 = 1;
    if (seq->unk370 & 2) {
        seq->unk370 &= ~2;
        if (seq->unk370 & 1) {
            seq->unk38a = 0;
        }
    }
    return seq->unk38a;
}
