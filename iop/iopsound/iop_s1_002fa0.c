#include "iopsound.h"

typedef struct Track Track;
typedef struct Seq Seq;
typedef struct Voice Voice;
typedef struct QueueEntry QueueEntry;
typedef struct Bank Bank;

struct Bank {
    s16 unk00;
    s16 unk02;
};

struct Track {
    u8 *ptr;            /* 0x000 */
    u8 pad004[0x14];    /* 0x004 */
    Bank *unk018;       /* 0x018 */
    u8 pad01c[0xd0];    /* 0x01c */
    u32 unk0ec;         /* 0x0ec */
    u32 flags;          /* 0x0f0 */
    s32 unk0f4;         /* 0x0f4 */
    u8 pad0f8[0x44];    /* 0x0f8 */
}; /* size 0x13c = 316 */

struct Seq {
    Track *tracks;      /* 0x000 */
    u8 pad004[0x36c];   /* 0x004 */
    u32 unk370;         /* 0x370 */
    s32 unk374;         /* 0x374 */
    s32 unk378;         /* 0x378 */
    s32 unk37c;         /* 0x37c */
    s32 unk380;         /* 0x380 */
    u32 unk384;         /* 0x384 */
    s16 unk388;         /* 0x388 */
    s16 unk38a;         /* 0x38a */
    u8 unk38c;          /* 0x38c */
    u8 num_tracks;      /* 0x38d */
    u8 pad38e[2];       /* 0x38e */
}; /* size 0x390 = 912 */

struct Voice {
    Track *trk;         /* 0x00 */
    u8 pad04[0x12];     /* 0x04 */
    u8 unk16;           /* 0x16 */
    u8 pad17[0x35];     /* 0x17 */
    u32 unk4c;          /* 0x4c */
    u8 pad50[0x18];     /* 0x50 */
    u32 unk68;          /* 0x68 */
    u8 pad6c[0x08];     /* 0x6c */
}; /* size 0x74 = 116 */

extern Voice *D_0192F0;
extern Seq *D_01936C;
extern s32 D_016CC0[];
extern s8 D_018C70[];

extern void func_002E70(QueueEntry *, Track *);
extern void func_009834(void *);
extern void func_00B5EC(s32, s32);
extern void func_00C1C8(s32, s32);

void func_0031D8(Seq *seq, QueueEntry *q, Track *trk);

void func_002FA0(Track *trk, u32 val) {
    Voice *v = D_0192F0;
    Voice *vend = v + 48;

    do {
        if (v->trk == trk) {
            v->unk68 |= val;
        }
        v++;
    } while (v < vend);
}

s32 func_002FEC(s32 x) {
    s32 v = D_016CC0[x & 0x1ff];

    if (x & 0x200) {
        v = -v;
    }
    return v;
}

s32 func_003018(s32 x) {
    s32 v = (x & 0xff) << 8;

    switch ((x >> 8) & 3) {
    case 3:
        v = v - 0x10000;
        break;
    case 2:
        v = -v;
        break;
    case 1:
        v = 0x10000 - v;
        break;
    }
    return v;
}

s32 func_003080(s32 x) {
    return ((x << 22) >> 24) << 8;
}

s32 func_003090(s32 x) {
    return (x & 0x200) ? -0x10000 : 0x10000;
}

s32 func_0030A8(s32 x) {
    return D_018C70[(x >> 8) & 0xff] << 8;
}

s32 func_0030C4(s32 x) {
    s32 v;

    x ^= 0x200;
    v = D_016CC0[x & 0x1ff];
    if (x & 0x200) {
        v = -v;
    }
    return v;
}

s32 func_0030F4(s32 x) {
    s32 v;

    x ^= 0x200;
    v = (x & 0xff) << 8;
    switch ((x >> 8) & 3) {
    case 3:
        v = v - 0x10000;
        break;
    case 2:
        v = -v;
        break;
    case 1:
        v = 0x10000 - v;
        break;
    }
    return v;
}

s32 func_003160(s32 x) {
    x ^= 0x200;
    return (x & 0x200) ? -0x10000 : 0x10000;
}

s32 func_00317C(s32 x) {
    return (((~x) << 22) >> 24) << 8;
}

s32 func_003190(s32 x) {
    return D_018C70[((x >> 8) & 0xff) ^ 0x40] << 8;
}

void func_0031B0(Seq *seq, QueueEntry *q, Track *trk) {
    func_0031D8(seq, q, trk);
}

void func_0031D0(void) {
}

void func_0031D8(Seq *seq, QueueEntry *q, Track *trk) {
    Voice *v;

    trk->flags = 0;
    func_002E70(q, trk);
    v = D_0192F0;
    do {
        if (v->trk == trk) {
            u32 f = v->unk16;
            f &= ~0x11;
            v->unk16 = f;
        }
        v++;
    } while (v < D_0192F0 + 48);
    trk->ptr = NULL;
    if (seq < D_01936C + 2 || seq == D_01936C + 3) {
        if (--seq->unk38a == 0 && !(seq->unk370 & 1)) {
            v = D_0192F0;
            do {
                if (v->trk >= seq->tracks && v->trk < &seq->tracks[seq->num_tracks]) {
                    v->unk4c = (v->unk4c & ~0xd) | 2;
                    v->trk = NULL;
                }
                v++;
            } while (v < D_0192F0 + 48);
            func_00C1C8(1, seq->unk374);
            func_00B5EC(4, seq->unk37c);
            seq->unk374 = -1;
            seq->unk384 = 0;
            func_009834(seq->tracks);
            seq->tracks = NULL;
        }
    } else {
        func_00B5EC(1, trk->unk018->unk02);
    }
}

void func_003378(Seq *seq, QueueEntry *q, Track *trk) {
    if (seq->unk370 & 0x200) {
        trk->unk0ec |= 0x100;
        seq->tracks->unk0f4++;
    }
}
