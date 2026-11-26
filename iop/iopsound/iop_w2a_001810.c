#include "iopsound.h"

typedef struct Tone {
    u8 pad00[0x10];
    s32 pitch_off;      /* 0x10 */
} Tone;

typedef struct Track {
    u8 pad000[0x58];
    s32 unk058;         /* 0x058 */
    u8 pad05c[0x08];
    s32 (*vib_fn)(u32); /* 0x064 */
    u32 vib_step;       /* 0x068 */
    u8 pad06c[4];
    s32 vib_depth;      /* 0x070 */
    u8 pad074[0xb2];
    s16 unk126;         /* 0x126 */
    s16 unk128;         /* 0x128 */
    s16 unk12a;         /* 0x12a */
    u8 pad12c[4];
    s8 unk130;          /* 0x130 */
} Track;

typedef struct Voice {
    Track *trk;         /* 0x00 */
    Tone *tone;         /* 0x04 */
    u8 pad08[0x0e];
    u8 unk16;           /* 0x16 */
    u8 unk17;           /* 0x17 */
    u32 vib_phase;      /* 0x18 */
    s32 vib_fade_len;   /* 0x1c */
    s32 vib_fade_cnt;   /* 0x20 */
    s16 vib_delay;      /* 0x24 */
    s16 unk26;          /* 0x26 */
    u8 pad28[0x10];
    s32 rand_pitch;     /* 0x38 */
    u8 pad3c[0x14];
    s32 pitch;          /* 0x50 */
    s32 note;           /* 0x54 */
    u16 voice_id;       /* 0x58 */
    u16 unk5a;          /* 0x5a */
} Voice;

extern s32 D_122440;
extern s32 func_0013E4(s32, s32, s32, s32);

void func_001810(Voice *v) {
    s32 vib = 0;

    if (v->trk->vib_fn != NULL && v->vib_delay == 0) {
        s32 tmp = v->trk->vib_depth >> 12;
        s32 note;

        s32 v2;
        if (tmp < 128) {
            v2 = (tmp + 1) << 1;
        } else {
            v2 = ((tmp & 0x7f) + 1) * 24;
        }
        tmp = v2 + (v->trk->unk12a + v->trk->unk126);
        if (v->unk16 & 3) {
            note = v->note + v->trk->unk058;
        } else {
            note = v->note + D_122440;
        }
        tmp = func_0013E4(note, tmp, v->tone->pitch_off, v->trk->unk130) - v->pitch;
        tmp *= v->trk->vib_fn(v->vib_phase >> 12);
        tmp >>= 16;
        if (v->vib_fade_len != 0) {
            tmp *= v->vib_fade_cnt;
            tmp /= v->vib_fade_len;
            if (++v->vib_fade_cnt >= v->vib_fade_len) {
                v->vib_fade_len = 0;
            }
        }
        vib = tmp;
        if (vib < 0) {
            vib >>= 1;
        }
        v->vib_phase += v->trk->vib_step;
    }
    {
        s32 p = vib + v->pitch;
        p += v->rand_pitch;
        p &= 0x3fff;
        imp_libsd_5(v->voice_id | 0x200, p);
    }
}
