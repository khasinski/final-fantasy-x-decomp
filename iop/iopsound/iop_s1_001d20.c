#include "iopsound.h"

typedef struct Track Track;
typedef struct Voice Voice;
typedef struct Tone Tone;

struct Tone {
    u32 flags;          /* 0x00 */
    u32 ssa;            /* 0x04 */
    u32 lsa;            /* 0x08 */
    u32 adsr;           /* 0x0c */
    s32 pitch_off;      /* 0x10 */
    s8 key_max;         /* 0x14 */
    u8 vel_max;         /* 0x15 */
    u8 vol;             /* 0x16 */
    u8 pan;             /* 0x17 */
    s8 unk18;           /* 0x18 */
    u8 pad19[7];        /* 0x19 */
}; /* size 0x20 = 32 */

struct Track {
    u8 *ptr;            /* 0x000 */
    u8 pad004[0x18];    /* 0x004 */
    Tone *unk01c;       /* 0x01c */
    s8 *scale_tbl;      /* 0x020 */
    u8 unk024;          /* 0x024 */
    u8 unk025;          /* 0x025 */
    u8 unk026;          /* 0x026 */
    u8 unk027;          /* 0x027 */
    s32 vol;            /* 0x028 */
    s32 unk02c;         /* 0x02c */
    s32 unk030;         /* 0x030 */
    s32 exp;            /* 0x034 */
    s32 unk038;         /* 0x038 */
    s32 unk03c;         /* 0x03c */
    s32 pan;            /* 0x040 */
    u8 pad044[0x14];    /* 0x044 */
    s32 unk058;         /* 0x058 */
    u8 pad05c[0x08];    /* 0x05c */
    void *vib_fn;       /* 0x064 */
    s32 vib_step;       /* 0x068 */
    u8 pad06c[0x14];    /* 0x06c */
    s16 vib_delay;      /* 0x080 */
    s16 vib_fade;       /* 0x082 */
    void *trm_fn;       /* 0x084 */
    s32 trm_step;       /* 0x088 */
    u8 pad08c[0x14];    /* 0x08c */
    s16 trm_delay;      /* 0x0a0 */
    s16 trm_fade;       /* 0x0a2 */
    u8 pad0a4[0x20];    /* 0x0a4 */
    s8 adsr_ov[8];      /* 0x0c4 */
    s32 rand_pitch;     /* 0x0cc */
    s32 rand_vol;       /* 0x0d0 */
    s32 rand_pan;       /* 0x0d4 */
    s32 unk0d8;         /* 0x0d8 */
    s32 rand_ar;        /* 0x0dc */
    u8 pad0e0[0x08];    /* 0x0e0 */
    u32 unk0e8;         /* 0x0e8 */
    u32 unk0ec;         /* 0x0ec */
    u32 flags;          /* 0x0f0 */
    s32 unk0f4;         /* 0x0f4 */
    s32 unk0f8;         /* 0x0f8 */
    s32 porta_cnt;      /* 0x0fc */
    s32 porta_step;     /* 0x100 */
    s32 porta_time;     /* 0x104 */
    u32 bank_addr;      /* 0x108 */
    s32 last_note;      /* 0x10c */
    u8 pad110[0x16];    /* 0x110 */
    s16 unk126;         /* 0x126 */
    s16 unk128;         /* 0x128 */
    s16 unk12a;         /* 0x12a */
    s16 unk12c;         /* 0x12c */
    s16 unk12e;         /* 0x12e */
    s8 unk130;          /* 0x130 */
    u8 pad131[0x0b];    /* 0x131 */
}; /* size 0x13c = 316 */

struct Voice {
    Track *trk;         /* 0x00 */
    Tone *tone;         /* 0x04 */
    s32 *vol_ptr;       /* 0x08 */
    s32 *exp_ptr;       /* 0x0c */
    s32 *pan_ptr;       /* 0x10 */
    u32 note_vel;       /* 0x14 */
    u32 vib_phase;      /* 0x18 */
    s32 vib_fade_len;   /* 0x1c */
    s32 vib_fade_cnt;   /* 0x20 */
    s16 vib_delay;      /* 0x24 */
    s16 unk26;          /* 0x26 */
    u32 trm_phase;      /* 0x28 */
    s32 trm_fade_len;   /* 0x2c */
    s32 trm_fade_cnt;   /* 0x30 */
    s16 trm_delay;      /* 0x34 */
    s16 unk36;          /* 0x36 */
    s32 rand_pitch;     /* 0x38 */
    s32 rand_vol;       /* 0x3c */
    s32 rand_pan;       /* 0x40 */
    u8 pad44[8];        /* 0x44 */
    u32 unk4c;          /* 0x4c */
    s32 pitch;          /* 0x50 */
    s32 note;           /* 0x54 */
    u32 voice_id;       /* 0x58 */
    u32 voice_bit;      /* 0x5c */
    u32 adsr;           /* 0x60 */
    u32 unk64;          /* 0x64 */
    u32 unk68;          /* 0x68 */
    u8 pad6c[8];        /* 0x6c */
}; /* size 0x74 = 116 */

typedef struct {
    u32 flags;
} DriverState;

extern DriverState D_01931C;
extern s32 D_122440;

extern s32 func_002CC0(s32 *, s32, s32 *);
extern u32 func_0013E4(s32, s32, s32, s32);
extern s32 func_009330(void);

void func_001D20(Track *trk, Voice *v, u32 *nv, u32 *kon) {
    s32 tmp;
    s32 val;
    u32 nv_w;

    v->trk = trk;
    if (trk->porta_time != 0 && trk->last_note >= 0) {
        trk->last_note &= ~0xfff;
        v->note = trk->last_note;
        trk->porta_cnt = trk->porta_time;
        tmp = 0;
        trk->porta_step = func_002CC0(&tmp, (((s8 *)nv)[0] << 8) - (trk->last_note >> 12), &trk->porta_cnt);
    } else {
        trk->last_note = ((s8 *)nv)[0] << 20;
        if (v->tone->flags & 0x20000) {
            v->note = v->tone->key_max << 20;
        } else {
            v->note = ((s8 *)nv)[0] << 20;
            if (v->trk->scale_tbl != NULL) {
                tmp = v->note >> 20;
                tmp = v->trk->scale_tbl[tmp % 12];
                v->note += tmp << 20;
            }
        }
    }

    nv_w = *nv;
    v->vol_ptr = &trk->vol;
    v->exp_ptr = &trk->exp;
    v->pan_ptr = &trk->pan;
    v->note_vel = nv_w;
    v->adsr = trk->unk01c->adsr;
    v->unk4c = trk->unk0e8;
    if (v->tone->unk18 != 0) {
        v->unk4c &= ~0x3c00;
        if (v->tone->unk18 == 1) {
            v->unk4c |= 0x3000;
        } else {
            v->unk4c |= 0x3c00;
        }
    }
    D_01931C.flags |= 1;

    tmp = trk->unk12a + trk->unk126;
    if (((u8 *)&v->note_vel)[2] & 3) {
        val = v->note + trk->unk058;
    } else {
        val = v->note + D_122440;
    }
    v->pitch = func_0013E4(val, tmp, v->tone->pitch_off, trk->unk130);

    if ((trk->flags & 0x100000) == 0) {
        goto do_lfo;
    }
    if (trk->unk026 & 0x11) {
        if ((trk->flags & 0x280000) == 0) {
            goto do_lfo;
        }
    } else {
        if ((trk->flags & 0x80000) == 0) {
do_lfo:
            if (v->trk->vib_fn != NULL) {
                v->vib_delay = trk->vib_delay;
                tmp = 256;
                if ((trk->vib_step >> 12) != 0) {
                    tmp = 256 / (trk->vib_step >> 12);
                }
                v->vib_fade_len = (trk->vib_fade != 0) ? (tmp * (trk->vib_fade << 2)) : 0;
                v->vib_fade_cnt = 0;
                v->vib_phase = 0;
            }
            if (v->trk->trm_fn != NULL) {
                v->trm_delay = trk->trm_delay;
                tmp = 256;
                if ((trk->trm_step >> 12) != 0) {
                    tmp = 256 / (trk->trm_step >> 12);
                }
                v->trm_fade_len = (trk->trm_fade != 0) ? (tmp * (trk->trm_fade << 2)) : 0;
                v->trm_fade_cnt = 0;
                v->trm_phase = 0;
            }
        }
    }

    if (v->unk4c & 0x4000) {
        s32 p;

        val = func_009330();
        val &= 0xff;
        tmp = v->trk->rand_pitch;
        p = v->pitch * tmp * (val + 1);
        tmp = p >> 15;
        if (val & 0x80) {
            v->rand_pitch = -(p >> 16);
        } else {
            v->rand_pitch = tmp;
        }
    } else {
        v->rand_pitch = 0;
    }

    if (v->unk4c & 0x8000) {
        s8 r = func_009330();
        v->rand_vol = (trk->rand_vol * r) >> 8;
    } else {
        v->rand_vol = 0;
    }

    if (v->unk4c & 0x10000) {
        s8 r = func_009330();
        v->rand_pan = (trk->rand_pan * r) >> 8;
    } else {
        v->rand_pan = 0;
    }

    if (v->voice_id & 1) {
        kon++;
    }

    tmp = v->tone->ssa + v->trk->bank_addr;
    imp_libsd_9((u16)v->voice_id | 0x2040, tmp);

    tmp = (!(v->tone->flags & 0x10)) ? (tmp + v->tone->lsa) : (tmp + 0x2000);
    imp_libsd_9((u16)v->voice_id | 0x2140, tmp);

    val = v->tone->adsr;
    if (!(trk->adsr_ov[0] & 0x80)) {
        val = (val & ~0x7f00) | (trk->adsr_ov[0] << 8);
    }
    if (!(trk->adsr_ov[1] & 0x80)) {
        val = (val & ~0x00f0) | (trk->adsr_ov[1] << 4);
    }
    if (!(trk->adsr_ov[2] & 0x80)) {
        val = (val & ~0x000f) | trk->adsr_ov[2];
    }
    if (!(trk->adsr_ov[3] & 0x80)) {
        val = (val & ~0x1fc00000) | (trk->adsr_ov[3] << 22);
    }
    if (!(trk->adsr_ov[4] & 0x80)) {
        val = (val & ~0x001f0000) | (trk->adsr_ov[4] << 16);
    }
    if (!(trk->adsr_ov[5] & 0x80)) {
        val = (val & ~0x00008000) | (((u8)trk->adsr_ov[5] & 4) << 13);
    }
    if (!(trk->adsr_ov[6] & 0x80)) {
        val = (val & ~0xe0000000) | (((u8)trk->adsr_ov[6] & 6) << 29);
    }
    if (!(trk->adsr_ov[7] & 0x80)) {
        val = (val & ~0x00200000) | (((u8)trk->adsr_ov[7] & 4) << 19);
    }

    if (v->unk4c & 0x40000) {
        s32 ar = (val >> 8) & 0x7f;
        s8 r;

        tmp = ar;
        r = func_009330();
        tmp = ((trk->rand_ar * r) >> 8) + ar;
        if (tmp < 0) {
            tmp = 0;
        } else if (tmp >= 128) {
            tmp = 127;
        }
        val = (val & ~0x7f00) | (tmp << 8);
    }

    v->adsr = val;
    imp_libsd_5((u16)v->voice_id | 0x300, val & 0xffff);
    imp_libsd_5((u16)v->voice_id | 0x400, (u32)val >> 16);

    if ((trk->flags & 0x180000) != 0x180000) {
        trk->flags |= 0x100000;
        *kon |= v->voice_bit;
    }
    v->unk68 |= 3;
}
