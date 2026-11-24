/* tu_134 0x187260-0x188d98: low; ~yiAnimInfo_init (config/tu_map.tsv) */
#define yiAnimInfo_init _hdr_yiAnimInfo_init
#define func_00187EA0 _hdr_func_00187EA0
#include "common.h"
#include "ffx/r2.h"
#include "ffx/q3.h"
#include "ffx/s2.h"
#include "ffx/t2.h"
#include "ffx/v2.h"
#undef yiAnimInfo_init
#undef func_00187EA0

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
/* DEBT(CAST) */
void yiAnimInfo_init(void *arg0) {
    s32 *var_2;
    s32 *var_3;
    s32 *var_4;
    s32 *var_5;
    s32 *var_6;
    s32 *s7;
    s32 *s6;
    s32 *s5;
    s32 *s4;
    s32 *s3;
    s32 var_16;
    s32 var_18;

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

typedef struct {
    u8 pad0[8];
    u32 h8;
} YiAnimHdr;

typedef struct {
    s32 w00;
    u32 w04;
    u8 pad08[0x18];
} YiAnimKey;

typedef struct {
    u16 h0;
    u16 h2;
    u16 h4;
    u16 h6;
    u16 h8;
    u16 hA;
    u8 padC[8];
    u32 w14;
    u32 w18;
    u8 pad1C[8];
    void *p24;
} YiAnimEnt;

typedef struct {
    u8 pad0[0x9F200];
    u32 cnt;
    YiAnimEnt ent[0x40];
    s32 w9FC04;
    YiAnimHdr *p9FC08[0x40];
    YiAnimKey *p9FD08[0x40];
    u32 n9FE08[0x40];
    u32 a9FF08[0x40];
    u32 aA0008[0x40];
    u32 wA0108;
} YiAnimSys;

INCLUDE_ASM("build/ee_asm/game/yi/yi_187260", yiKeyFrame_attachDObj);

typedef union {
    float f[16];
    u64 d[8];
} YiMat64;

typedef struct {
    u8 pad00[0x10];
    YiMat64 m10;
    float v50[4];
    float v60[4];
    u8 pad70[0x16];
    u16 h86;
    u8 pad88[0x10];
    float f98;
    float f9C;
    u8 padA0[0x20];
} YiDObj188450;

typedef struct {
    u8 pad00[8];
    s32 w08;
    u8 pad0C[0x10];
} YiGrpSub188450;

typedef struct {
    u32 flags;
    s32 cur;
    u8 pad08[0x18];
    YiGrpSub188450 sub[64];
} YiGrp188450;

typedef struct {
    u16 h00;
    u16 h02;
    u32 w04;
    u8 pad08[8];
    float f10[4];
    float f20[4];
    float f30[4];
    float f40[4];
} YiAnimInterpKey;

typedef struct {
    u16 h0;
    u16 h2;
    u16 h4;
    u16 h6;
    u16 h8;
    u16 hA;
    u32 w0C;
    u32 w10;
    u32 w14;
    u32 w18;
    u8 pad1C[8];
    YiAnimInterpKey *p24;
} YiAnimEntFull;

typedef struct {
    u8 pad0[0x687B8];
    u32 w687B8;
    u8 pad687BC[4];
    YiDObj188450 dobj[0x40];
    u8 pad6B7C0[0x9F200 - 0x6B7C0];
    u32 cnt;
    YiAnimEntFull ent[0x40];
    s32 w9FC04;
    YiAnimHdr *p9FC08[0x40];
    YiAnimKey *p9FD08[0x40];
    u32 n9FE08[0x40];
    u32 a9FF08[0x40];
    u32 aA0008[0x40];
    u32 wA0108;
    YiGrp188450 grp[0x40];
    u8 padBC90C[0xBCB20 - (0xA010C + 0x40 * 0x720)];
    u32 wBCB20;
    u32 wBCB24;
} YiAnimSysFull;

u32 yiGetFCount(void);
u32 yiGetVCount(void);

int func_00187D40(void *arg0, int grpIdx, int animIdx, int loop)
{
    YiAnimSysFull *s = (YiAnimSysFull *)arg0;
    u32 t;
    int i;

    if (_m2c_yiAnimInfo_init_D_0065FD18 == 0) {
        t = yiGetFCount();
    } else {
        t = yiGetVCount();
    }
    if (s->p9FC08[animIdx] == 0) {
        BREAK();
        return 0;
    }
    if ((u32)grpIdx >= s->wA0108) {
        BREAK();
        return 0;
    }
    for (i = 0; i < 0x40; i++) {
        if ((s->ent[i].h0 & 1) == 0) {
            s->ent[i].h0 = 1;
            s->ent[i].h2 = loop;
            s->ent[i].h4 = s->p9FC08[animIdx]->h8;
            s->ent[i].w14 = t;
            s->ent[i].w18 = t;
            s->ent[i].p24 = (YiAnimInterpKey *)s->p9FC08[animIdx];
            s->cnt++;
            s->ent[i].h6 = grpIdx;
            s->ent[i].h8 = animIdx;
            s->ent[i].hA = 0;
            break;
        }
    }
    if (i >= 0x40) {
        BREAK();
        return 0;
    }
}

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

void func_00188138(YiAnimSysFull *s, YiAnimEntFull *e, u32 t)
{
    if (Sg_GetPause() != 0) {
        u32 d = t - e->w18;
        e->w18 = t;
        e->w14 += d;
        return;
    }
    if (t < e->w14) {
        e->w14 = t;
    }
    e->w18 = t;
    while (t >= e->p24->w04 + e->w14) {
        if ((e->p24->h00 & 1) != 0) {
            e->h0 = 0;
            e->w14 = t;
            e->w18 = t;
            e->h8 = 0;
            e->hA = 0;
            e->h6 = 0;
            e->p24 = 0;
            break;
        }
        e->hA++;
        if (e->hA < s->n9FE08[e->h8]) {
            e->w14 = e->p24->w04 + e->w14;
            e->w18 = t;
            e->p24 = (YiAnimInterpKey *)((u8 *)e->p24 + 0x80);
            if (e->p24->w04 == 0) {
                break;
            }
        } else if (e->h2 != 0) {
            if (t > e->p24->w04 + e->w14) {
                e->w14 = t;
                e->w18 = t;
                e->h0 = 0;
                s->cnt--;
                e->h8 = 0;
                e->hA = 0;
                e->h6 = 0;
                e->p24 = 0;
            }
            break;
        } else {
            e->w14 = e->p24->w04 + e->w14;
            e->w18 = t;
            e->p24 = (YiAnimInterpKey *)s->p9FC08[e->h8];
            e->hA = 0;
            if (e->p24->w04 == 0) {
                break;
            }
        }
    }
}

void yiKeyFrame_main(YiAnimSys *s, YiAnimEnt *e, u32 t)
{
    YiAnimKey *k;

    if (Sg_GetPause() != 0) {
        u32 d = t - e->w18;
        e->w18 = t;
        e->w14 += d;
        return;
    }
    if (t < e->w14) {
        e->w14 = t;
    }
    k = s->p9FD08[e->h8];
    e->w18 = t;
    k += e->hA;
    while (t >= (k->w04 << 1) + e->w14) {
        e->hA++;
        if (e->hA < s->n9FE08[e->h8]) {
            e->w14 = (k->w04 << 1) + e->w14;
            e->w18 = t;
        } else if (e->h2 != 0) {
            e->w14 = t;
            e->w18 = t;
            e->h0 = 0;
            s->cnt--;
            e->h8 = 0;
            e->hA = 0;
            e->h6 = 0;
            e->p24 = 0;
            return;
        } else {
            e->w14 = (k->w04 << 1) + e->w14;
            e->w18 = t;
            e->hA = 0;
        }
    }
}

INCLUDE_ASM("build/ee_asm/game/yi/yi_187260", func_00188450);
INCLUDE_RODATA("build/ee_asm/game/yi/yi_187260/rodata", jtbl_0056D120);
