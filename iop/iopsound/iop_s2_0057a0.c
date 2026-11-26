#include "iopsound.h"

typedef struct VoiceInst {
    u8 pad00[0x10];
    s32 unk10;
} VoiceInst;

typedef struct VoiceLfo {
    s32 cur;
    s32 step;
    s32 acc;
    s16 delay;
    s16 pad0E;
} VoiceLfo;

typedef struct Track {
    u8 *ptr;            /* 0x000 */
    u8 pad004[0x24];
    s32 unk28;          /* 0x028 */
    s32 unk2C;          /* 0x02C */
    s32 unk30;          /* 0x030 */
    s32 unk34;          /* 0x034 */
    s32 unk38;          /* 0x038 */
    s32 unk3C;          /* 0x03C */
    s32 unk40;          /* 0x040 */
    s32 unk44;          /* 0x044 */
    s32 unk48;          /* 0x048 */
    s32 unk4C;          /* 0x04C */
    s32 unk50;          /* 0x050 */
    s32 unk54;          /* 0x054 */
    s32 unk58;          /* 0x058 */
    s32 unk5C;          /* 0x05C */
    s32 unk60;          /* 0x060 */
    s32 lfo0_wave;      /* 0x064 */
    s32 lfo0_rate;      /* 0x068 */
    s32 lfo0_rate_step; /* 0x06C */
    s32 lfo0_depth;     /* 0x070 */
    s32 lfo0_depth_step;/* 0x074 */
    u8 pad078[0x04];
    s16 lfo0_rate_cnt;  /* 0x07C */
    s16 lfo0_depth_cnt; /* 0x07E */
    u8 pad080[0x04];
    s32 lfo1_wave;      /* 0x084 */
    s32 lfo1_rate;      /* 0x088 */
    s32 lfo1_rate_step; /* 0x08C */
    s32 lfo1_depth;     /* 0x090 */
    s32 lfo1_depth_step;/* 0x094 */
    u8 pad098[0x04];
    s16 lfo1_rate_cnt;  /* 0x09C */
    s16 lfo1_depth_cnt; /* 0x09E */
    u8 pad0A0[0x04];
    s32 lfo2_wave;      /* 0x0A4 */
    s32 lfo2_rate;      /* 0x0A8 */
    s32 lfo2_rate_step; /* 0x0AC */
    s32 lfo2_depth;     /* 0x0B0 */
    s32 lfo2_depth_step;/* 0x0B4 */
    u8 pad0B8[0x08];
    s16 lfo2_rate_cnt;  /* 0x0C0 */
    s16 lfo2_depth_cnt; /* 0x0C2 */
    u8 pad0C4[0x28];
    u32 flagsEC;        /* 0x0EC */
    u8 pad0F0[0x04];
    s32 unkF4;          /* 0x0F4 */
    s32 unkF8;          /* 0x0F8 */
    s32 unkFC;          /* 0x0FC */
    s32 unk100;         /* 0x100 */
    u8 pad104[0x08];
    s32 unk10C;         /* 0x10C */
    u8 pad110[0x16];
    s16 unk126;         /* 0x126 */
    u8 pad128[0x02];
    s16 unk12A;         /* 0x12A */
    u8 pad12C[0x04];
    s8 unk130;          /* 0x130 */
    u8 pad131[0x06];
    u8 voice_idx;       /* 0x137 */
    u8 pad138[0x04];
} Track; /* size 0x13C = 316 */

typedef struct Voice {
    Track *trk;         /* 0x00 */
    VoiceInst *inst;    /* 0x04 */
    u8 pad08[0x0E];
    u8 unk16;           /* 0x16 */
    u8 pad17;
    VoiceLfo lfo0;      /* 0x18 */
    VoiceLfo lfo1;      /* 0x28 */
    u8 pad38[0x18];
    s32 unk50;          /* 0x50 */
    s32 unk54;          /* 0x54 */
    u8 pad58[0x1C];
} Voice; /* size 0x74 = 116 */

extern u32 D_0193A0;
extern Voice *D_0192F0;
extern s32 D_122440;
extern u8 D_018764[];

extern s32 func_0013E4(s32, s32, s32, s32);

void func_0057A0(Track *trk, s32 dt) {
    s32 step;
    Voice *v;

    trk->unkF8 += dt;
    if (trk->unk30 != 0) {
        if (dt < trk->unk30) {
            step = dt;
        } else {
            step = trk->unk30;
        }
        trk->unk30 -= step;
        D_0193A0 |= 2;
        trk->unk28 += trk->unk2C * step;
    }
    if (trk->unk3C != 0) {
        if (dt < trk->unk3C) {
            step = dt;
        } else {
            step = trk->unk3C;
        }
        trk->unk3C -= step;
        D_0193A0 |= 2;
        trk->unk34 += trk->unk38 * step;
    }
    if (trk->unk48 != 0) {
        if (dt < trk->unk48) {
            step = dt;
        } else {
            step = trk->unk48;
        }
        trk->unk48 -= step;
        D_0193A0 |= 2;
        trk->unk40 += trk->unk44 * step;
    }
    if (trk->unkFC != 0) {
        if (dt < trk->unkFC) {
            step = dt;
        } else {
            step = trk->unkFC;
        }
        trk->unkFC -= step;
        step *= trk->unk100;
        D_0193A0 |= 1;
        trk->unk10C += step;
        v = D_0192F0;
        do {
            if (v->trk == trk) {
                s32 base;
                s32 pitch;
                v->unk54 += step;
                pitch = trk->unk12A + trk->unk126;
                if ((v->unk16 & 3) != 0) {
                    base = v->unk54 + trk->unk58;
                } else {
                    base = v->unk54 + D_122440;
                }
                v->unk50 = func_0013E4(base, pitch, v->inst->unk10, trk->unk130);
            }
        } while (++v < D_0192F0 + 48);
    }

    if (trk->lfo0_wave != 0) {
        if (trk->lfo0_rate_cnt != 0) {
            if (dt < trk->lfo0_rate_cnt) {
                step = dt;
            } else {
                step = trk->lfo0_rate_cnt;
            }
            trk->lfo0_rate_cnt -= step;
            trk->lfo0_rate += trk->lfo0_rate_step * step;
        }
        if (trk->lfo0_depth_cnt != 0) {
            if (dt < trk->lfo0_depth_cnt) {
                step = dt;
            } else {
                step = trk->lfo0_depth_cnt;
            }
            trk->lfo0_depth_cnt -= step;
            trk->lfo0_depth += trk->lfo0_depth_step * step;
        }
    }
    if (trk->lfo1_wave != 0) {
        if (trk->lfo1_rate_cnt != 0) {
            if (dt < trk->lfo1_rate_cnt) {
                step = dt;
            } else {
                step = trk->lfo1_rate_cnt;
            }
            trk->lfo1_rate_cnt -= step;
            trk->lfo1_rate += trk->lfo1_rate_step * step;
        }
        if (trk->lfo1_depth_cnt != 0) {
            if (dt < trk->lfo1_depth_cnt) {
                step = dt;
            } else {
                step = trk->lfo1_depth_cnt;
            }
            trk->lfo1_depth_cnt -= step;
            trk->lfo1_depth += trk->lfo1_depth_step * step;
        }
    }
    if (trk->lfo2_wave != 0) {
        if (trk->lfo2_rate_cnt != 0) {
            if (dt < trk->lfo2_rate_cnt) {
                step = dt;
            } else {
                step = trk->lfo2_rate_cnt;
            }
            trk->lfo2_rate_cnt -= step;
            trk->lfo2_rate += trk->lfo2_rate_step * step;
        }
        if (trk->lfo2_depth_cnt != 0) {
            if (dt < trk->lfo2_depth_cnt) {
                step = dt;
            } else {
                step = trk->lfo2_depth_cnt;
            }
            trk->lfo2_depth_cnt -= step;
            trk->lfo2_depth += trk->lfo2_depth_step * step;
        }
    }

    v = D_0192F0;
    do {
        if (v->trk == trk) {
            if (v->lfo0.delay != 0) {
                if (dt < v->lfo0.delay) {
                    step = dt;
                } else {
                    step = v->lfo0.delay;
                }
                v->lfo0.delay -= step;
            }
            if (v->lfo1.delay != 0) {
                if (dt < v->lfo1.delay) {
                    step = dt;
                } else {
                    step = v->lfo1.delay;
                }
                v->lfo1.delay -= step;
            }
        }
    } while (++v < D_0192F0 + 48);
}

void func_005BFC(Track *trk, s32 dt) {
    s32 step;
    Voice *v;

    trk->unkF8 += dt;
    if (trk->unk30 != 0) {
        if (dt < trk->unk30) {
            step = dt;
        } else {
            step = trk->unk30;
        }
        trk->unk30 -= step;
        D_0193A0 |= 2;
        trk->unk28 += trk->unk2C * step;
    }
    if (trk->unk3C != 0) {
        if (dt < trk->unk3C) {
            step = dt;
        } else {
            step = trk->unk3C;
        }
        trk->unk3C -= step;
        D_0193A0 |= 2;
        trk->unk34 += trk->unk38 * step;
    }
    if (trk->unk48 != 0) {
        if (dt < trk->unk48) {
            step = dt;
        } else {
            step = trk->unk48;
        }
        trk->unk48 -= step;
        D_0193A0 |= 2;
        trk->unk40 += trk->unk44 * step;
    }
    if (trk->unk54 != 0) {
        if (dt < trk->unk54) {
            step = dt;
        } else {
            step = trk->unk54;
        }
        trk->unk54 -= step;
        if (trk->unk54 == 0 && (trk->flagsEC & 0x100) != 0) {
            trk->ptr = D_018764;
            trk->unkF4 = 1;
        }
        D_0193A0 |= 2;
        trk->unk4C += trk->unk50 * step;
    }
    if (trk->unk60 != 0) {
        if (dt < trk->unk60) {
            step = dt;
        } else {
            step = trk->unk60;
        }
        trk->unk60 -= step;
        D_0193A0 |= 1;
        trk->unk58 += trk->unk5C * step;
    }
    if (trk->unkFC != 0) {
        if (dt < trk->unkFC) {
            step = dt;
        } else {
            step = trk->unkFC;
        }
        trk->unkFC -= step;
        step *= trk->unk100;
        D_0193A0 |= 1;
        v = &D_0192F0[trk->voice_idx];
        trk->unk10C += step;
        v->unk54 += step;
    }
    if ((D_0193A0 & 1) != 0) {
        v = &D_0192F0[trk->voice_idx];
        v->unk50 = func_0013E4(v->unk54 + trk->unk58, trk->unk12A + trk->unk126, v->inst->unk10, trk->unk130);
    }

    if (trk->lfo0_wave != 0) {
        if (trk->lfo0_rate_cnt != 0) {
            if (dt < trk->lfo0_rate_cnt) {
                step = dt;
            } else {
                step = trk->lfo0_rate_cnt;
            }
            trk->lfo0_rate_cnt -= step;
            trk->lfo0_rate += trk->lfo0_rate_step * step;
        }
        if (trk->lfo0_depth_cnt != 0) {
            if (dt < trk->lfo0_depth_cnt) {
                step = dt;
            } else {
                step = trk->lfo0_depth_cnt;
            }
            trk->lfo0_depth_cnt -= step;
            trk->lfo0_depth += trk->lfo0_depth_step * step;
        }
    }
    if (trk->lfo1_wave != 0) {
        if (trk->lfo1_rate_cnt != 0) {
            if (dt < trk->lfo1_rate_cnt) {
                step = dt;
            } else {
                step = trk->lfo1_rate_cnt;
            }
            trk->lfo1_rate_cnt -= step;
            trk->lfo1_rate += trk->lfo1_rate_step * step;
        }
        if (trk->lfo1_depth_cnt != 0) {
            if (dt < trk->lfo1_depth_cnt) {
                step = dt;
            } else {
                step = trk->lfo1_depth_cnt;
            }
            trk->lfo1_depth_cnt -= step;
            trk->lfo1_depth += trk->lfo1_depth_step * step;
        }
    }
    if (trk->lfo2_wave != 0) {
        if (trk->lfo2_rate_cnt != 0) {
            if (dt < trk->lfo2_rate_cnt) {
                step = dt;
            } else {
                step = trk->lfo2_rate_cnt;
            }
            trk->lfo2_rate_cnt -= step;
            trk->lfo2_rate += trk->lfo2_rate_step * step;
        }
        if (trk->lfo2_depth_cnt != 0) {
            if (dt < trk->lfo2_depth_cnt) {
                step = dt;
            } else {
                step = trk->lfo2_depth_cnt;
            }
            trk->lfo2_depth_cnt -= step;
            trk->lfo2_depth += trk->lfo2_depth_step * step;
        }
    }

    v = &D_0192F0[trk->voice_idx];
    if (v->lfo0.delay != 0) {
        if (dt < v->lfo0.delay) {
            step = dt;
        } else {
            step = v->lfo0.delay;
        }
        v->lfo0.delay -= step;
    }
    if (v->lfo1.delay != 0) {
        if (dt < v->lfo1.delay) {
            step = dt;
        } else {
            step = v->lfo1.delay;
        }
        v->lfo1.delay -= step;
    }
}
