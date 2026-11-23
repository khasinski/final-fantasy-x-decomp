#include "common.h"
#include "vu0.h"

typedef union {
    u_long128 q;
    float f[4];
} VecQ;

typedef struct {
    VecQ row[4];
} Mat4;

typedef struct {
    s16 unk00;
    u16 unk02;
    s8 unk04;
    u8 pad05[3];
} UnkADC8Frame;

typedef struct {
    u8 pad0[6];
    s16 unk06;
    u8 pad08[8];
    UnkADC8Frame frames[1];
} UnkADC8Anim;

typedef struct {
    UnkADC8Anim *unk00;
    s32 unk04;
    s16 unk08;
    u16 unk0A;
} UnkADC8Sub;

typedef struct {
    VecQ unk00;
    VecQ unk10;
    VecQ unk20;
    UnkADC8Sub unk30;
    float unk3C;
    float unk40;
    float unk44;
    float unk48;
    s32 unk4C;
    s32 unk50;
    s32 unk54;
    s32 unk58;
    s32 unk5C;
    s32 unk60;
    union {
        u32 w;
        u8 b[4];
    } unk64;
    union {
        u32 w;
        u8 b[4];
    } unk68;
    s32 unk6C;
    u16 unk70;
    u8 pad72[0xE];
} UnkADC8Item;

typedef struct {
    u8 pad0[4];
    union {
        u32 w;
        u8 b[4];
    } unk04;
    u8 pad08[8];
    Mat4 *unk10;
    s32 unk14;
    u8 pad18[4];
    Mat4 *unk1C;
} UnkADC8Draw;

extern UnkADC8Draw D_01B00F20;
extern UnkADC8Item *D_01B10470;
extern s32 D_01B10478;
extern s32 D_01B1047C;

extern s32 func_00116068(void);
extern s32 func_0011ABB8(void);
extern s32 func_002CD590(void *, UnkADC8Draw *);
extern void func_002DCE08(void *, void *, void *);
extern void func_002DCE38(void *, void *, void *);
extern void func_002DD0C0(void *, void *);
extern void func_002DD128(void *);
extern void func_002DD1C8(void *, void *, float);
extern void func_002DD998(void *, void *, float);
extern void func_01B06120(void *, void *);

static inline void wrap_angle(float *a, float d) {
    float v = *a + d;
    if (v > 3.1415927f) {
        v -= 6.2831855f;
    } else if (v < -3.1415927f) {
        v += 6.2831855f;
    }
    *a = v;
}

void func_01B0ADC8(void) {
    Mat4 m0;
    Mat4 m1;
    Mat4 m2;
    Mat4 m3;
    Mat4 m4;
    s32 i;
    UnkADC8Item *p;
    UnkADC8Draw *draw;
    s32 active;

    if (func_0011ABB8() != 0) {
        return;
    }

    p = D_01B10470;
    func_01B06120(&m1, &m2);
    active = 0;
    draw = &D_01B00F20;
    draw->unk10 = &m3;
    func_002DD128(&m0);

    for (i = 0; i < D_01B10478; i++, p++) {
        float sc;
        UnkADC8Sub *sub;
        UnkADC8Anim *anim;
        UnkADC8Frame *frame;
        s32 show;

        if (p->unk6C == 0) {
            continue;
        }
        active++;
        if (p->unk60 > 0) {
            if (func_00116068() != 0) {
                p->unk60--;
            }
            continue;
        }

        if (func_00116068() != 0) {
            if ((p->unk70 & 2) != 0) {
                func_002DD998(&p->unk20, &p->unk20, p->unk20.f[3]);
            }
            VU0_LQC2(1, 0, &p->unk10);
            VU0_LQC2(2, 0, &p->unk20);
            VU0_OP("vadd.xyz $vf1xyz, $vf1xyz, $vf2xyz");
            VU0_SQC2(1, 0, &p->unk10);

            VU0_LQC2(1, 0, &p->unk00);
            VU0_LQC2(2, 0, &p->unk10);
            VU0_OP("vadd.xyz $vf1xyz, $vf1xyz, $vf2xyz");
            VU0_SQC2(1, 0, &p->unk00);
        }

        sc = p->unk3C;
        if (p->unk58 > 0) {
            float d = p->unk40;
            float t = (float)p->unk5C / (float)p->unk58;
            sc *= (1.0f - t) + d * t;
            if (func_00116068() != 0) {
                p->unk5C++;
                if (p->unk5C > p->unk58) {
                    p->unk58 = 0;
                }
            }
        } else {
            sc *= p->unk40;
        }

        m0.row[2].f[2] = sc;
        m0.row[1].f[1] = sc;
        m0.row[0].f[0] = sc;

        wrap_angle(&p->unk10.f[3], p->unk48);
        func_002DD1C8(&m3, &m0, p->unk10.f[3]);
        func_002DCE08(&m3.row[3], &m2, &p->unk00);

        draw->unk1C = 0;
        if ((p->unk70 & 1) != 0) {
            func_002DD0C0(&m4, &m3);
            m4.row[3].f[2] += p->unk44;
            func_002DCE38(&m4, &m1, &m4);
            draw->unk1C = &m4;
        }
        func_002DCE38(&m3, &m1, &m3);

        if (p->unk50 > 0) {
            s32 t = p->unk54;
            if (t < 0) {
                t = -t;
            }
            draw->unk04.b[0] = (p->unk68.b[0] * t + p->unk64.b[0] * (p->unk50 - t)) / p->unk50;
            draw->unk04.b[1] = (p->unk68.b[1] * t + p->unk64.b[1] * (p->unk50 - t)) / p->unk50;
            draw->unk04.b[2] = (p->unk68.b[2] * t + p->unk64.b[2] * (p->unk50 - t)) / p->unk50;
            draw->unk04.b[3] = (p->unk68.b[3] * t + p->unk64.b[3] * (p->unk50 - t)) / p->unk50;
            if (func_00116068() != 0) {
                p->unk54++;
                if (p->unk54 > p->unk50) {
                    p->unk50 = 0;
                }
            }
        } else {
            draw->unk04.w = p->unk68.w;
        }

        sub = &p->unk30;
        anim = sub->unk00;
        frame = &anim->frames[sub->unk08];
        {
            UnkADC8Frame *cur_frame;
            if (func_00116068() == 0 && sub->unk08 <= 0) {
                cur_frame = &anim->frames[0];
            } else {
                if (func_00116068() != 0 && sub->unk04 != 0) {
                    sub->unk0A -= 0x200;
                    if ((s16)sub->unk0A <= 0) {
                        u16 old_idx = sub->unk08;
                        sub->unk08 = old_idx + 1;
                        if (sub->unk08 >= anim->unk06) {
                            if (frame->unk04 & 0x80) {
                                sub->unk08 = 0;
                            } else {
                                sub->unk08 = old_idx;
                                sub->unk04 = 0;
                                cur_frame = frame;
                                goto skip_frame;
                            }
                        }
                        frame = &anim->frames[sub->unk08];
                        sub->unk0A = frame->unk02;
                    }
                }
                cur_frame = frame;
            }
skip_frame:
            show = 1;
            if (p->unk4C < 0) {
                show = p->unk30.unk04;
            }
            if (show == 1) {
                draw->unk14 = func_002CD590((u8 *)p->unk30.unk00 + cur_frame->unk00, draw);
            } else {
                p->unk4C = 1;
            }
        }

        if (p->unk4C > 0) {
            if (func_00116068() != 0) {
                p->unk4C--;
            }
            if (p->unk4C == 0) {
                p->unk6C = 0;
            }
        }
    }

    D_01B1047C = active;
}
