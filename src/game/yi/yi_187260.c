/* tu_134 0x187260-0x188d98: low; ~yiAnimInfo_init (config/tu_map.tsv) */
#define yiAnimInfo_init _hdr_yiAnimInfo_init
#include "common.h"
#include "ffx/r2.h"
#include "ffx/q3.h"
#include "ffx/s2.h"
#include "ffx/t2.h"
#include "ffx/v2.h"
#undef yiAnimInfo_init

void func_00187260(float t, float *p0, float *p1, float *m0, float *m1, float *out) {
    float t2 = t * t;
    float h00 = (t - 1.0f) * (t - 1.0f) * (2.0f * t + 1.0f);
    float h01 = t2 * (3.0f - 2.0f * t);
    float h10 = (1.0f - t) * (1.0f - t) * t;
    float h11 = (t - 1.0f) * t2;
    int i;
    for (i = 0; i < 4; i++) {
        out[i] = p0[i] * h00 + p1[i] * h01 + m0[i] * h10 + m1[i] * h11;
    }
}

void func_00187300(float t, float *p0, float *p1, float *m0, float *m1, float *out) {
    float t2 = t * t;
    float h00 = (t - 1.0f) * (t - 1.0f) * (2.0f * t + 1.0f);
    float h01 = t2 * (3.0f - 2.0f * t);
    float h10 = (1.0f - t) * (1.0f - t) * t;
    float h11 = (t - 1.0f) * t2;
    int i;
    for (i = 0; i < 2; i++) {
        out[i] = p0[i] * h00 + p1[i] * h01 + m0[i] * h10 + m1[i] * h11;
    }
}

float func_001873A0(float t, float a, float b) {
    return (b - a) * t + a;
}

void func_001873B0(float *a, float *b, float *out, float t) {
    int i;

    for (i = 0; i < 4; i++) {
        out[i] = (b[i] - a[i]) * t + a[i];
    }
}

void func_001873F0(float *a, float *b, float *out, float t) {
    int i;

    for (i = 0; i < 2; i++) {
        out[i] = (b[i] - a[i]) * t + a[i];
    }
}

INCLUDE_ASM("build/ee_asm/game/yi/yi_187260", func_00187430);

void func_00187578(Obj187260 *o) {
    o->h00 = 0;
    o->h02 = 0;
    o->h04 = 0;
    o->w14 = 0;
    o->w18 = 0;
    o->h06 = 0;
    o->h08 = 0;
    o->h0A = 0;
    o->w24 = 0;
}

s32 _m2c_yiAnimInfo_init_Sg_GetKeepFps() __asm__("Sg_GetKeepFps");
void _m2c_yiAnimInfo_init_func_00187578(s32) __asm__("func_00187578");
extern s32 _m2c_yiAnimInfo_init_D_0065FD18 __asm__("D_0065FD18");
/* DEBT(CAST) */ /* DEBT(FAKE) */
void yiAnimInfo_init(void *arg0) {
    register s32 *var_2 __asm__("$2");
    register s32 *var_3 __asm__("$3");
    register s32 *var_4 __asm__("$4");
    register s32 *var_5 __asm__("$5");
    register s32 *var_6 __asm__("$6");
    register s32 *s7 __asm__("$23");
    register s32 *s6 __asm__("$22");
    register s32 *s5 __asm__("$21");
    register s32 *s4 __asm__("$20");
    register s32 *s3 __asm__("$19");
    s32 var_16;
    register s32 var_18 __asm__("$18");

    s7 = arg0 + 0xA0C;
    s6 = arg0 + 0xB0C;
    s5 = arg0 + 0xC0C;
    s4 = arg0 + 0xD0C;
    s3 = arg0 + 0xE0C;
    var_18 = 0x3F;
    var_16 = arg0 + 8;
    _m2c_yiAnimInfo_init_D_0065FD18 = _m2c_yiAnimInfo_init_Sg_GetKeepFps();
    (*(s32 *)((u8 *)(arg0) + (4))) = 0;
    do {
        var_18 -= 1;
        _m2c_yiAnimInfo_init_func_00187578(var_16);
        var_16 += 0x28;
    } while (var_18 >= 0);
    (*(s32 *)((u8 *)(arg0) + (0xA08))) = 0;
    var_6 = s3;
    var_5 = s4;
    var_4 = s5;
    var_3 = s6;
    var_2 = s7;
    var_18 = 0x3F;
    do {
        *var_5 = 0;
        var_18 -= 1;
        *var_2 = 0;
        var_5 = (s32 *)((u8 *)var_5 + (4));
        *var_3 = 0;
        var_2 = (s32 *)((u8 *)var_2 + (4));
        *var_4 = 0;
        var_3 = (s32 *)((u8 *)var_3 + (4));
        *var_6 = 0;
        var_4 = (s32 *)((u8 *)var_4 + (4));
        var_6 = (s32 *)((u8 *)var_6 + (4));
    } while (var_18 >= 0);
}

void yiTexSwap_init(S2ClrBig *p) {
    int i, j;
    p->e[0].w00 = 0;
    for (i = 0; i < 64; i++) {
        p->e[i].w04 = 0;
        p->e[i].w08 = 0;
        p->e[i].w0C = 0;
        p->e[i].w10 = 0;
        p->e[i].w14 = 0;
        p->e[i].w18 = 0;
        p->e[i].w1C = 0;
        p->e[i].w20 = 0;
        for (j = 0; j < 64; j++) {
            p->e[i].in[j].a = 0;
            p->e[i].in[j].b = 0;
            p->e[i].in[j].c = 0;
            p->e[i].in[j].d = 0;
        }
    }
}

void yiAnimAttachDefault(Sys597F00 *s) {
    u32 i;
    u32 j;

    for (i = 0; i < s->w687B8; i++) {
        for (j = 0; j < s->ent[i].n8C; j++) {
            yiKeyFrame_attachDObj(s, i, s->ent[i].id90[j], 0);
        }
    }
    for (i = 0; i < s->wA0108; i++) {
        for (j = 0; j < s->grp[i].n; j++) {
            func_00187D40(s, i, s->grp[i].id[j], 0);
        }
    }
}

void yiRotMatrixSeq(void *m, float *rot, u32 order) {
    if (order == 0 || order == 3) {
        func_002DD270(m, m, rot[0]);
    } else if (order == 4 || order == 1) {
        func_002DD318(m, m, rot[1]);
    } else if (order == 2 || order == 5) {
        func_002DD1C8(m, m, rot[2]);
    }
    if (order == 1 || order == 2) {
        func_002DD270(m, m, rot[0]);
    } else if (order == 0 || order == 5) {
        func_002DD318(m, m, rot[1]);
    } else if (order == 3 || order == 4) {
        func_002DD1C8(m, m, rot[2]);
    }
    if (order == 4 || order == 5) {
        func_002DD270(m, m, rot[0]);
    } else if (order == 2 || order == 3) {
        func_002DD318(m, m, rot[1]);
    } else if (order == 0 || order == 1) {
        func_002DD1C8(m, m, rot[2]);
    }
}

void func_00187AB0(R2ResTbl *t) {
    int i;

    t->cnt = 0;
    for (i = 63; i >= 0; i--) {
        t->ent[i].h0 = 0;
    }
}

INCLUDE_ASM("build/ee_asm/game/yi/yi_187260", yiKeyFrame_attachDObj);

INCLUDE_ASM("build/ee_asm/game/yi/yi_187260", func_00187D40);

INCLUDE_ASM("build/ee_asm/game/yi/yi_187260", func_00187EA0);

int func_00188020(void *p, int id, int unused) { /* DEBT(TYPE): funcs.h declares int and a third argument the body ignores */
    R2ResTbl *t = p;
    u32 seen = 0;
    int i;
    int u;
    for (i = 0; i < 0x40; i++) {
        if ((t->ent[i].h0 & 1) != 0) {
            if (t->ent[i].h6 == id) {
                t->ent[i].w14 = u;
                t->ent[i].w18 = u;
                t->ent[i].h0 = 0;
                t->cnt--;
                t->ent[i].h8 = 0;
                t->ent[i].hA = 0;
                t->ent[i].h6 = 0;
            }
            seen++;
            if (!(seen < t->cnt)) {
                break;
            }
        }
    }
}

int func_001880A8(void *p, int id, int id2) { /* DEBT(TYPE): funcs.h declares int; the body leaves v0 undefined */
    R2ResTbl *t = p;
    u32 seen = 0;
    int i;
    int u;
    for (i = 0; i < 0x40; i++) {
        if ((t->ent[i].h0 & 1) != 0) {
            if (t->ent[i].h6 == id && t->ent[i].h4 == id2) {
                t->ent[i].w14 = u;
                t->ent[i].w18 = u;
                t->ent[i].h0 = 0;
                t->cnt--;
                t->ent[i].h8 = 0;
                t->ent[i].hA = 0;
                t->ent[i].h6 = 0;
            }
            seen++;
            if (!(seen < t->cnt)) {
                break;
            }
        }
    }
}

INCLUDE_ASM("build/ee_asm/game/yi/yi_187260", func_00188138);

INCLUDE_ASM("build/ee_asm/game/yi/yi_187260", yiKeyFrame_main);

INCLUDE_ASM("build/ee_asm/game/yi/yi_187260", func_00188450);
INCLUDE_RODATA("build/ee_asm/game/yi/yi_187260/rodata", jtbl_0056D120);
