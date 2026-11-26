#include "iopsound.h"

typedef struct Track Track;
typedef struct Voice Voice;

struct Track {
    u8 *ptr;            /* 0x000 */
    u8 pad004[0xc0];    /* 0x004 */
    union {
        s32 w[2];
        u8 b[8];
    } adsr_ov;          /* 0x0c4 */
};

struct Voice {
    Track *trk;         /* 0x00 */
    u8 pad04[0x54];     /* 0x04 */
    u16 voice_id;       /* 0x58 */
    u16 unk5a;          /* 0x5a */
    u32 unk5c;          /* 0x5c */
    union {
        u32 w;
        u16 h[2];
    } adsr;             /* 0x60 */
    u8 pad64[0x10];     /* 0x64 */
}; /* size 0x74 = 116 */

extern Voice *D_0192F0;

void func_00404C(void *seq, void *q, Track *trk) {
    Voice *v;
    u32 val = *trk->ptr++;

    trk->adsr_ov.b[0] = val;
    v = D_0192F0;
    do {
        if (v->trk == trk) {
            v->adsr.w = (v->adsr.w & ~0x7f00) | (val << 8);
            imp_libsd_5(v->voice_id | 0x300, v->adsr.h[0]);
        }
        v++;
    } while (v < D_0192F0 + 48);
}

void func_004100(void *seq, void *q, Track *trk) {
    Voice *v;
    u32 val = *trk->ptr++;

    trk->adsr_ov.b[1] = val;
    v = D_0192F0;
    do {
        if (v->trk == trk) {
            v->adsr.w = (v->adsr.w & ~0x00f0) | (val << 4);
            imp_libsd_5(v->voice_id | 0x300, v->adsr.h[0]);
        }
        v++;
    } while (v < D_0192F0 + 48);
}

void func_0041B4(void *seq, void *q, Track *trk) {
    Voice *v;
    u32 val = *trk->ptr++;

    trk->adsr_ov.b[2] = val;
    v = D_0192F0;
    do {
        if (v->trk == trk) {
            v->adsr.w = (v->adsr.w & ~0x000f) | val;
            imp_libsd_5(v->voice_id | 0x300, v->adsr.h[0]);
        }
        v++;
    } while (v < D_0192F0 + 48);
}

void func_004268(void *seq, void *q, Track *trk) {
    Voice *v;
    u32 val = *trk->ptr++;

    trk->adsr_ov.b[3] = val;
    v = D_0192F0;
    do {
        if (v->trk == trk) {
            v->adsr.w = (v->adsr.w & ~0x1fc00000) | (val << 22);
            imp_libsd_5(v->voice_id | 0x400, v->adsr.w >> 16);
        }
        v++;
    } while (v < D_0192F0 + 48);
}

void func_004320(void *seq, void *q, Track *trk) {
    Voice *v;
    u32 val = *trk->ptr++;

    trk->adsr_ov.b[4] = val;
    v = D_0192F0;
    do {
        if (v->trk == trk) {
            v->adsr.w = (v->adsr.w & ~0x001f0000) | (val << 16);
            imp_libsd_5(v->voice_id | 0x400, v->adsr.w >> 16);
        }
        v++;
    } while (v < D_0192F0 + 48);
}

void func_0043D8(void *seq, void *q, Track *trk) {
    Voice *v;
    u32 val = *trk->ptr++;

    trk->adsr_ov.b[5] = val;
    v = D_0192F0;
    do {
        if (v->trk == trk) {
            v->adsr.w = (v->adsr.w & ~0x00008000) | ((val & 4) << 13);
            imp_libsd_5(v->voice_id | 0x300, v->adsr.h[0]);
        }
        v++;
    } while (v < D_0192F0 + 48);
}

void func_004494(void *seq, void *q, Track *trk) {
    Voice *v;
    u32 val = *trk->ptr++;

    trk->adsr_ov.b[6] = val;
    v = D_0192F0;
    do {
        if (v->trk == trk) {
            v->adsr.w = (v->adsr.w & ~0xe0000000) | ((val & 6) << 29);
            imp_libsd_5(v->voice_id | 0x400, v->adsr.w >> 16);
        }
        v++;
    } while (v < D_0192F0 + 48);
}

void func_004550(void *seq, void *q, Track *trk) {
    Voice *v;
    u32 val = *trk->ptr++;

    trk->adsr_ov.b[7] = val;
    v = D_0192F0;
    do {
        if (v->trk == trk) {
            v->adsr.w = (v->adsr.w & ~0x00200000) | ((val & 4) << 19);
            imp_libsd_5(v->voice_id | 0x400, v->adsr.w >> 16);
        }
        v++;
    } while (v < D_0192F0 + 48);
}
