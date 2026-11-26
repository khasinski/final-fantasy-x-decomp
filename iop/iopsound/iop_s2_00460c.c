#include "iopsound.h"

typedef struct Seq {
    u8 pad000[0x38C];
    u8 unk38C;
    u8 pad38D[2];
    u8 unk38F;
} Seq;

typedef struct Track {
    u8 *ptr;            /* 0x000 */
    u8 pad004[0x22];
    u8 flags26;         /* 0x026 */
    u8 pad027[0x31];
    s32 unk58;          /* 0x058 */
    u8 pad05C[0x08];
    s32 lfo0_wave;      /* 0x064 */
    s32 lfo0_rate;      /* 0x068 */
    s32 lfo0_rate_step; /* 0x06C */
    s32 lfo0_depth;     /* 0x070 */
    s32 lfo0_depth_step;/* 0x074 */
    u8 pad078[0x04];
    s16 lfo0_rate_cnt;  /* 0x07C */
    s16 lfo0_depth_cnt; /* 0x07E */
    u16 lfo0_delay;     /* 0x080 */
    s16 lfo0_fade;      /* 0x082 */
    s32 lfo1_wave;      /* 0x084 */
    s32 lfo1_rate;      /* 0x088 */
    s32 lfo1_rate_step; /* 0x08C */
    s32 lfo1_depth;     /* 0x090 */
    s32 lfo1_depth_step;/* 0x094 */
    u8 pad098[0x04];
    s16 lfo1_rate_cnt;  /* 0x09C */
    s16 lfo1_depth_cnt; /* 0x09E */
    u16 lfo1_delay;     /* 0x0A0 */
    s16 lfo1_fade;      /* 0x0A2 */
    s32 lfo2_wave;      /* 0x0A4 */
    s32 lfo2_rate;      /* 0x0A8 */
    s32 lfo2_rate_step; /* 0x0AC */
    s32 lfo2_depth;     /* 0x0B0 */
    s32 lfo2_depth_step;/* 0x0B4 */
    s32 lfo2_unkB8;     /* 0x0B8 */
    s32 lfo2_unkBC;     /* 0x0BC */
    s16 lfo2_rate_cnt;  /* 0x0C0 */
    s16 lfo2_depth_cnt; /* 0x0C2 */
    u8 pad0C4;
    u8 unkC5;           /* 0x0C5 */
    u8 unkC6;           /* 0x0C6 */
    u8 pad0C7[0x05];
    s32 unkCC;          /* 0x0CC */
    s32 unkD0;          /* 0x0D0 */
    s32 unkD4;          /* 0x0D4 */
    s32 unkD8;          /* 0x0D8 */
    s32 unkDC;          /* 0x0DC */
    u8 pad0E0[0x08];
    u32 flags;          /* 0x0E8 */
    u8 pad0EC[0x34];
    s16 unk120;         /* 0x120 */
    s16 unk122;         /* 0x122 */
    u8 pad124[0x02];
    s16 unk126;         /* 0x126 */
    s16 unk128;         /* 0x128 */
    s16 unk12A;         /* 0x12A */
    u8 pad12C[0x04];
    s8 unk130;          /* 0x130 */
    u8 pad131[0x02];
    s8 unk133;          /* 0x133 */
} Track;

typedef struct VoiceInst {
    u8 pad00[0x10];
    s32 unk10;
} VoiceInst;

typedef struct VoiceLfo {
    s32 cur;
    s32 step;
    s32 acc;
    u16 delay;
    u16 pad0E;
} VoiceLfo;

typedef struct Voice {
    Track *trk;         /* 0x00 */
    VoiceInst *inst;    /* 0x04 */
    u8 pad08[0x0E];
    u8 unk16;           /* 0x16 */
    u8 pad17;
    VoiceLfo lfo0;      /* 0x18 */
    VoiceLfo lfo1;      /* 0x28 */
    u8 pad38[0x14];
    u32 flags4C;        /* 0x4C */
    s32 unk50;          /* 0x50 */
    s32 unk54;          /* 0x54 */
    u16 voice_id;       /* 0x58 */
    u8 pad5A[0x06];
    union {
        u32 w;
        u16 h[2];
    } unk60;            /* 0x60 */
    u8 pad64[0x04];
    u32 flags68;        /* 0x68 */
    u8 pad6C[0x08];
} Voice; /* size 0x74 = 116 */

extern Voice *D_0192F0;
extern s32 D_0174C0[];
extern volatile u32 D_0193A0;
extern s32 D_122440;
extern s32 D_01933C;
extern u32 D_01931C;

extern s32 func_006118(Track *);
extern s32 func_002CC0(s32 *, u32, s32 *);
extern s32 func_0013E4(s32, s32, s32, s32);

void func_00460C(Seq *seq, s32 a1, Track *trk) {
    s32 b0 = *trk->ptr++;
    s32 b1 = *trk->ptr++;
    Voice *v;

    trk->unkC5 = b0;
    trk->unkC6 = b1;
    v = D_0192F0;
    do {
        if (v->trk == trk) {
            v->unk60.w = (v->unk60.w & ~0xF0) | (b0 << 4);
            v->unk60.w = (v->unk60.w & ~0x0F) | b1;
            imp_libsd_5(v->voice_id | 0x300, v->unk60.h[0]);
        }
    } while (++v < D_0192F0 + 48);
}

void func_0046EC(Seq *seq, s32 a1, Track *trk) {
    Voice *v;

    if (*trk->ptr != 0) {
        trk->flags |= 4;
        v = D_0192F0;
        do {
            if (v->trk == trk) {
                v->flags4C |= 4;
            }
        } while (++v < D_0192F0 + 48);
    } else {
        trk->flags &= ~4;
        v = D_0192F0;
        do {
            if (v->trk == trk) {
                v->flags4C &= ~4;
            }
        } while (++v < D_0192F0 + 48);
    }
    trk->ptr++;
}

void func_0047BC(Seq *seq, s32 a1, Track *trk) {
    seq->unk38C = *trk->ptr++;
}

void func_0047D8(Seq *seq, s32 a1, Track *trk) {
    if (*trk->ptr++ != 0) {
        trk->flags26 |= 0x20;
    } else {
        trk->flags26 &= ~0x20;
    }
}

void func_004818(Seq *seq, s32 a1, Track *trk) {
    if (*trk->ptr++ != 0) {
        trk->flags26 |= 0x10;
    } else {
        trk->flags26 &= ~0x10;
    }
}

void func_004858(Seq *seq, s32 a1, Track *trk) {
    s32 rate;
    Voice *v;

    trk->lfo0_depth = trk->ptr[0] << 12;
    rate = (trk->ptr[1] != 0) ? trk->ptr[1] : 256;
    trk->lfo0_rate = 0x100000 / rate;
    trk->lfo0_wave = D_0174C0[trk->ptr[2] & 0xF];
    trk->lfo0_depth_cnt = 0;
    trk->lfo0_rate_cnt = 0;
    trk->ptr += 3;

    v = D_0192F0;
    do {
        if (v->trk == trk) {
            s32 r;
            s32 inv;
            v->lfo0.delay = trk->lfo0_delay;
            r = trk->lfo0_rate >> 12;
            inv = 256;
            if (r != 0) {
                inv /= r;
            }
            v->lfo0.step = (trk->lfo0_fade != 0) ? (inv * (trk->lfo0_fade << 2)) : 0;
            v->lfo0.acc = 0;
            v->lfo0.cur = 0;
        }
    } while (++v < D_0192F0 + 48);
}

void func_004998(Seq *seq, s32 a1, Track *trk) {
    trk->lfo0_wave = 0;
}

void func_0049A0(Seq *seq, s32 a1, Track *trk) {
    s32 b = *trk->ptr++;
    trk->lfo0_depth_cnt = 0;
    trk->lfo0_depth = b << 12;
}

void func_0049C4(Seq *seq, s32 a1, Track *trk) {
    s32 len = func_006118(trk);
    if (len == 0) {
        len = 1;
    }
    trk->lfo0_depth_step = func_002CC0(&trk->lfo0_depth, *trk->ptr, &len);
    trk->lfo0_depth_cnt = len;
    trk->ptr++;
}

void func_004A28(Seq *seq, s32 a1, Track *trk) {
    s32 rate = *trk->ptr != 0 ? *trk->ptr : 256;
    trk->lfo0_rate_cnt = 0;
    trk->ptr++;
    trk->lfo0_rate = 0x100000 / rate;
}

void func_004A88(Seq *seq, s32 a1, Track *trk) {
    s32 rate;
    s32 len = func_006118(trk);
    if (len == 0) {
        len = 1;
    }
    rate = (*trk->ptr != 0) ? *trk->ptr : 256;
    rate = 256 / rate;
    trk->lfo0_rate_step = func_002CC0(&trk->lfo0_rate, rate, &len);
    trk->lfo0_rate_cnt = len;
    trk->ptr++;
}

void func_004B2C(Seq *seq, s32 a1, Track *trk) {
    s32 idx = *trk->ptr++;
    trk->lfo0_wave = D_0174C0[idx & 0xF];
}

void func_004B5C(Seq *seq, s32 a1, Track *trk) {
    trk->lfo0_delay = trk->ptr[0];
    trk->lfo0_fade = trk->ptr[1];
    trk->ptr += 2;
}

void func_004B88(Seq *seq, s32 a1, Track *trk) {
    s32 rate;
    Voice *v;

    trk->lfo1_depth = trk->ptr[0] << 12;
    rate = (trk->ptr[1] != 0) ? trk->ptr[1] : 256;
    trk->lfo1_rate = 0x100000 / rate;
    trk->lfo1_wave = D_0174C0[trk->ptr[2] & 0xF];
    trk->lfo1_depth_cnt = 0;
    trk->lfo1_rate_cnt = 0;
    trk->ptr += 3;

    v = D_0192F0;
    do {
        if (v->trk == trk) {
            s32 r;
            s32 inv;
            v->lfo1.delay = trk->lfo1_delay;
            r = trk->lfo1_rate >> 12;
            inv = 256;
            if (r != 0) {
                inv /= r;
            }
            v->lfo1.step = (trk->lfo1_fade != 0) ? (inv * (trk->lfo1_fade << 2)) : 0;
            v->lfo1.acc = 0;
            v->lfo1.cur = 0;
        }
    } while (++v < D_0192F0 + 48);
}

void func_004CC8(Seq *seq, s32 a1, Track *trk) {
    trk->lfo1_wave = 0;
}

void func_004CD0(Seq *seq, s32 a1, Track *trk) {
    s32 b = *trk->ptr++;
    trk->lfo1_depth_cnt = 0;
    trk->lfo1_depth = b << 12;
}

void func_004CF4(Seq *seq, s32 a1, Track *trk) {
    s32 len = func_006118(trk);
    if (len == 0) {
        len = 1;
    }
    trk->lfo1_depth_step = func_002CC0(&trk->lfo1_depth, *trk->ptr, &len);
    trk->lfo1_depth_cnt = len;
    trk->ptr++;
}

void func_004D58(Seq *seq, s32 a1, Track *trk) {
    s32 rate = *trk->ptr != 0 ? *trk->ptr : 256;
    trk->lfo1_rate_cnt = 0;
    trk->ptr++;
    trk->lfo1_rate = 0x100000 / rate;
}

void func_004DB8(Seq *seq, s32 a1, Track *trk) {
    s32 rate;
    s32 len = func_006118(trk);
    if (len == 0) {
        len = 1;
    }
    rate = (*trk->ptr != 0) ? *trk->ptr : 256;
    rate = 256 / rate;
    trk->lfo1_rate_step = func_002CC0(&trk->lfo1_rate, rate, &len);
    trk->lfo1_rate_cnt = len;
    trk->ptr++;
}

void func_004E5C(Seq *seq, s32 a1, Track *trk) {
    s32 idx = *trk->ptr++;
    trk->lfo1_wave = D_0174C0[idx & 0xF];
}

void func_004E8C(Seq *seq, s32 a1, Track *trk) {
    trk->lfo1_delay = trk->ptr[0];
    trk->lfo1_fade = trk->ptr[1];
    trk->ptr += 2;
}

void func_004EB8(Seq *seq, s32 a1, Track *trk) {
    s32 rate;

    trk->lfo2_depth = trk->ptr[0] << 12;
    rate = (trk->ptr[1] != 0) ? trk->ptr[1] : 256;
    trk->lfo2_rate = 0x100000 / rate;
    trk->lfo2_wave = D_0174C0[trk->ptr[2] & 0xF];
    trk->lfo2_unkBC = 0;
    trk->lfo2_unkB8 = 0;
    trk->lfo2_depth_cnt = 0;
    trk->lfo2_rate_cnt = 0;
    trk->ptr += 3;
}

void func_004F58(Seq *seq, s32 a1, Track *trk) {
    trk->lfo2_wave = 0;
}

void func_004F60(Seq *seq, s32 a1, Track *trk) {
    s32 b = *trk->ptr++;
    trk->lfo2_depth_cnt = 0;
    trk->lfo2_depth = b << 12;
}

void func_004F84(Seq *seq, s32 a1, Track *trk) {
    s32 len = func_006118(trk);
    if (len == 0) {
        len = 1;
    }
    trk->lfo2_depth_step = func_002CC0(&trk->lfo2_depth, *trk->ptr, &len);
    trk->lfo2_depth_cnt = len;
    trk->ptr++;
}

void func_004FE8(Seq *seq, s32 a1, Track *trk) {
    s32 rate = *trk->ptr != 0 ? *trk->ptr : 256;
    trk->lfo2_rate_cnt = 0;
    trk->ptr++;
    trk->lfo2_rate = 0x100000 / rate;
}

void func_005048(Seq *seq, s32 a1, Track *trk) {
    s32 rate;
    s32 len = func_006118(trk);
    if (len == 0) {
        len = 1;
    }
    rate = (*trk->ptr != 0) ? *trk->ptr : 256;
    rate = 256 / rate;
    trk->lfo2_rate_step = func_002CC0(&trk->lfo2_rate, rate, &len);
    trk->lfo2_rate_cnt = len;
    trk->ptr++;
}

void func_0050EC(Seq *seq, s32 a1, Track *trk) {
    s32 idx = *trk->ptr++;
    trk->lfo2_wave = D_0174C0[idx & 0xF];
}
