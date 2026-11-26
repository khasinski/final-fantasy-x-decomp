#include "iopsound.h"

typedef struct WaveEntry {
    s32 unk00;
    s32 id;
    s32 unk08;
    void *data;
    s32 unk10;
    s32 unk14;
} WaveEntry; /* size 24 = 0x18 */

typedef struct WaveHeader {
    s16 unk00;
    s16 unk02;
} WaveHeader;

typedef struct Voice {
    void *trk;          /* 0x00 */
    u8 pad04[0x12];
    u8 unk16;           /* 0x16 */
    u8 pad17[0x35];
    u32 flags4C;        /* 0x4C */
    u8 pad50[0x08];
    u16 voice_id;       /* 0x58 */
    u8 pad5A[0x06];
    u16 unk60;          /* 0x60 */
    u16 unk62;          /* 0x62 */
    u8 pad64[0x10];
} Voice; /* size 0x74 = 116 */

typedef struct Track {
    u8 *ptr;            /* 0x000 */
    u8 pad004[0x14];
    WaveHeader *wave;   /* 0x018 */
    u8 pad01C[0x0A];
    u8 flags26;         /* 0x026 */
    u8 pad027[0xB9];
    s32 se_id;          /* 0x0E0 */
    s32 unkE4;          /* 0x0E4 */
    u8 pad0E8[0x08];
    s32 unkF0;          /* 0x0F0 */
    u8 pad0F4[0x04];
    s32 unkF8;          /* 0x0F8 */
    u8 pad0FC[0x3B];
    u8 voice_idx;       /* 0x137 */
    u8 prio;            /* 0x138 */
    u8 group;           /* 0x139 */
    u8 pad13A[0x02];
} Track; /* size 0x13C = 316 */

typedef struct DriverState {
    u8 pad000[0x720];
    Track *se_tracks;   /* 0x720 */
    u8 pad724[0x380];
    s32 unkAA4;         /* 0xAA4 */
} DriverState;

extern WaveEntry *D_019308;
extern DriverState *D_01936C;
extern Voice *D_0192F0;
extern void *D_019314;
extern s32 D_0193C0[];

extern void func_002D20(void *, Track *);
extern void func_00B5EC(s32, s32);

void *func_006CC0(s32 id) {
    WaveEntry *p;

    for (p = D_019308; p < D_019308 + 128; p++) {
        if (id == p->id) {
            break;
        }
    }
    if (p < D_019308 + 128) {
        return p->data;
    }
    return NULL;
}

void func_006D2C(Voice *v) {
    if (v->flags4C & 8) {
        imp_libsd_5(v->voice_id | 0x300, v->unk60);
        imp_libsd_5(v->voice_id | 0x400, v->unk62);
    }
}

void func_006D80(s32 prio, s32 group) {
    Track *trk = D_01936C->se_tracks;
    s32 *buf = D_0193C0;
    s32 *p;

    do {
        if (trk->ptr != NULL && prio >= trk->prio && (trk->group & group) != 0) {
            func_002D20(D_019314, trk);
            trk->unkF0 = 0;
            trk->ptr = NULL;
            func_006D2C(&D_0192F0[trk->voice_idx]);
            D_0192F0[trk->voice_idx].unk16 &= ~0x11;
            D_0192F0[trk->voice_idx].flags4C |= 2;
            D_0192F0[trk->voice_idx].flags4C &= ~0x09;
            *buf++ = trk->wave->unk02;
        }
    } while (++trk < D_01936C->se_tracks + 24);

    for (p = D_0193C0; buf != p; p++) {
        func_00B5EC(1, *p);
    }
}

s32 func_006F54(s32 prio) {
    Track *trk;
    s32 max_age;
    s32 target_id;
    s32 count;
    s32 *buf;
    s32 *p;

    max_age = 0;
    target_id = 0;
    trk = D_01936C->se_tracks;
    do {
        if (trk->ptr != NULL && trk->group == 0 && prio >= trk->prio && max_age < trk->unkF8) {
            max_age = trk->unkF8;
            target_id = trk->unkE4;
        }
    } while (++trk < D_01936C->se_tracks + 24);

    buf = D_0193C0;
    trk = D_01936C->se_tracks;
    count = 0;
    do {
        if (trk->ptr != NULL && trk->group == 0 && prio >= trk->prio && trk->unkE4 == target_id) {
            func_002D20(D_019314, trk);
            trk->unkF0 = 0;
            trk->ptr = NULL;
            func_006D2C(&D_0192F0[trk->voice_idx]);
            D_0192F0[trk->voice_idx].unk16 &= ~0x11;
            D_0192F0[trk->voice_idx].flags4C |= 2;
            D_0192F0[trk->voice_idx].flags4C &= ~0x09;
            count++;
            *buf++ = trk->wave->unk02;
        }
    } while (++trk < D_01936C->se_tracks + 24);

    for (p = D_0193C0; buf != p; p++) {
        func_00B5EC(1, *p);
    }
    return count;
}

Track *func_0071C8(s32 need, s32 prio, s32 group) {
    Track *trk;
    s32 i;
    s32 rem;

    if (group != 0) {
        func_006D80(prio, group);
    }

    i = 0;
    for (;;) {
        trk = D_01936C->se_tracks + 23;
        do {
            rem = need;
            while (rem != 0) {
                if (trk->ptr != NULL || (trk->flags26 & 2) != 0) {
                    trk--;
                    break;
                }
                rem--;
                if (rem == 0) {
                    break;
                }
                trk--;
            }
        } while (rem != 0 && trk >= D_01936C->se_tracks);

        if (trk >= D_01936C->se_tracks) {
            break;
        }
        while (func_006F54(i) == 0) {
            if (i >= prio) {
                goto done;
            }
            i++;
        }
    }
done:
    if (trk >= D_01936C->se_tracks) {
        return trk;
    }
    return NULL;
}

s32 func_0072F4(s32 se_id) {
    Track *trk = D_01936C->se_tracks;

    D_01936C->unkAA4 = 0;
    do {
        if (trk->ptr != NULL) {
            if (se_id == -1 || trk->se_id == se_id) {
                func_002D20(D_019314, trk);
                trk->unkF0 = 0;
                trk->ptr = NULL;
                func_006D2C(&D_0192F0[trk->voice_idx]);
                D_0192F0[trk->voice_idx].unk16 &= ~0x11;
                D_0192F0[trk->voice_idx].flags4C |= 2;
                D_0192F0[trk->voice_idx].flags4C &= ~0x09;
                func_00B5EC(1, trk->wave->unk02);
            }
        }
    } while (++trk < D_01936C->se_tracks + 24);
    return 0;
}

s32 func_00747C(s32 unkE4) {
    Track *trk = D_01936C->se_tracks;

    D_01936C->unkAA4 = 0;
    do {
        if (trk->ptr != NULL && trk->unkE4 == unkE4) {
            func_002D20(D_019314, trk);
            trk->unkF0 = 0;
            trk->ptr = NULL;
            func_006D2C(&D_0192F0[trk->voice_idx]);
            D_0192F0[trk->voice_idx].unk16 &= ~0x11;
            D_0192F0[trk->voice_idx].flags4C |= 2;
            D_0192F0[trk->voice_idx].flags4C &= ~0x09;
            func_00B5EC(1, trk->wave->unk02);
        }
    } while (++trk < D_01936C->se_tracks + 24);
    return 0;
}
