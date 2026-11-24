/* tu_074 0x13ca80-0x141ff0: low; ~Atel (config/tu_map.tsv) */
#define func_0013BE58 _hdr_func_0013BE58
#define func_00110270 _hdr_func_00110270
#include "common.h"
#define func_0013EF90 _hdr_func_0013EF90
#define func_002D47E8 _hdr_func_002D47E8
#include "ffx/q1.h"
#undef func_0013EF90
#include "ffx/r0.h"
#include "ffx/u0.h"
#include "ffx/s0.h"
#include "ffx/v1.h"
#undef func_002D47E8
#undef func_0013BE58
#undef func_00110270
int func_002D47E8(float a, float b, float c, float d, float e, float f);
void func_0013BE58(Actor *a, int n);
void func_00110270(Chr *chr, float v);

int func_0013CA80(Actor *s, int i) {
    return ((int *)((char *)s->blob + s->hdr->o24))[i];
}

int func_0013CAA0(int id, int i) {
    return func_0013CA80(AtelGetBasicWork(id), i);
}

void func_0013CAD0(Actor *s, ActorBind *e, int off) {
    e->b1E = 0;
    e->p18 = (char *)s->blob + s->blob->o30 + off;
}

void func_0013CAF0(int id, int slot, int off) {
    Actor *x = AtelGetBasicWork(id);

    func_0013CAD0(x, func_0013C9C8(x, slot), off);
}

int func_0013CB48(Actor *s, ActorBind *e) {
    return e->p18 - ((char *)s->blob + s->blob->o30);
}

void func_0013CB60(Actor *s, ActorBind *e, int i) {
    if (e->b1D <= 0) {
        func_0013CAD0(s, e, func_0013CA80(s, i));
    } else {
        func_0013CAD0(s, e, func_0013CA80(AtelGetBasicWork(e->h10[e->b1D - 1]), i));
    }
}

char *func_0013CBF8(Actor *s, ActorBind *e) {
    return e->p18;
}

char *func_0013CC00(Actor *s, int off) {
    return (char *)s->blob + s->blob->o30 + off;
}

char *func_0013CC18(Actor *s, int i) {
    ActorHdr *h = s->hdr;
    char *b = (char *)s->blob;
    char *t = b + h->o28;
    t += i * 4;
    return b + *(int *)t;
}

int func_0013CC40(Actor *s, int i) {
    ActorHdr *h = s->hdr;
    char *t = (char *)s->blob + h->o14;
    t += i * 8;
    return *(u16 *)(t + 4);
}

int func_0013CC60(Actor *s, int i) {
    ActorHdr *h = s->hdr;
    char *t = (char *)s->blob + h->o14;
    t += i * 8;
    return *(u16 *)(t + 6);
}

int func_0013CC80(Actor *s, int i) {
    ActorHdr *h = s->hdr;
    char *t = (char *)s->blob + h->o14;
    t += i * 8;
    return *(int *)t;
}

int func_0013CCA0(int v) {
    return v & 0x80;
}

int func_0013CCA8(int flag, u8 *p) {
    int c = p[0];
    int v;

    if (func_0013CCA0(c) || flag) {
        c &= 0x7F;
        v = p[1] | (p[2] << 8);
    } else {
        v = 0;
    }
    return (c << 24) | v;
}

int func_0013CD18(Actor *s, ActorBind *e) {
    return func_0013CCA8(0, (u8 *)func_0013CBF8(s, e));
}

void func_0013CD40(Actor *s, ActorBind *e, int c) {
    int ch;
    int pos;
    int step;

    if (c < 0) {
        ch = *(u8 *)func_0013CBF8(s, e);
    } else {
        ch = c & 0xFF;
    }
    pos = func_0013CB48(s, e);
    step = func_0013CCA0(ch) ? 3 : 1;
    func_0013CAD0(s, e, pos + step);
}

void func_0013CDC8(int id, int off) {
    Actor *x = AtelGetBasicWork(id);

    func_0013CD40(x, func_0013C9C8(x, x->slotIdx), off);
}

void func_0013CE10(Actor *a, ScriptCtx *ctx, float f) {
    int n = ctx->argc;

    if (n >= 0x13) {
        func_0013AB38((int)a, 1);
        return;
    }
    ctx->tag[n] = 2;
    ctx->v[n++] = *(int *)&f; /* DEBT(CAST): float pushed as its bit pattern */
    ctx->argc = n;
}

int func_0013CE70(int a, ScriptCtx *k)
{
    if (k->tag[k->argc - 1] == k->tag[k->argc - 2]) {
        if (k->tag[k->argc - 1] == 1) {
            return 1;
        }
    }
    return 0;
}

void AtelPushStackInteger(Actor *a, ScriptCtx *ctx, int v) {
    int n = ctx->argc;

    if (n >= 0x13) {
        func_0013AB38((int)a, 1);
        return;
    }
    ctx->tag[n] = 1;
    ctx->v[n++] = v;
    ctx->argc = n;
}

int AtelPopStackInteger(Actor *a, ScriptCtx *ctx) {
    int n = ctx->argc;
    int r;

    if (n <= 0) {
        func_0013AB38((int)a, 2);
        return 0;
    }
    n--;
    if (ctx->tag[n] == 1) {
        r = ctx->v[n];
    } else {
        r = (int)*(float *)&ctx->v[n];
    }
    ctx->argc = n;
    return r;
}

int func_0013CF40(Actor *a, ScriptCtx *ctx) {
    int n = ctx->argc;
    int r;

    if (n <= 0) {
        func_0013AB38((int)a, 2);
        return 0;
    }
    n--;
    if (ctx->tag[n] == 1) {
        r = ctx->v[n];
    } else {
        r = (int)*(float *)&ctx->v[n];
    }
    return r;
}

float AtelPopStackFloat(Actor *a, ScriptCtx *ctx) {
    register ScriptCtx *c __asm__("$6") = ctx;
    int n = c->argc;
    float r;

    if (n <= 0) {
        ActorBind *b;
        char *fmt;
        int id;
        register int pos __asm__("$6");
        func_002EF240(D_0056A860);
        b = func_0013C9C8(a, a->slotIdx);
        fmt = D_0056A878;
        id = a->id;
        pos = func_0013CB48(a, b);
        func_002EF240(fmt, id, pos);
        func_0013AB38((int)a, 2);
        return 0.0f;
    }
    n--;
    if (c->tag[n] == 2) {
        r = *(float *)&c->v[n];
    } else {
        r = (float)*(int *)&c->v[n];
    }
    c->argc = n;
    return r;
}

int func_0013D068(Actor *a, int i) {
    return AtelGetRealVarAdrs(a, func_0013CC80(a, i));
}

int func_0013D098(Actor *s, int i) {
    return (unsigned)func_0013CC80(s, i) >> 28;
}

int func_0013D0B8(Actor *s, int i) {
    return func_0013CC40(s, i);
}

int func_0013D0D8(unsigned int kind) {
    int r = 0;

    switch (kind) {
    case 2:
    case 3:
        r = 2;
        break;
    case 4:
    case 5:
    case 6:
        r = 4;
        break;
    case 0:
    case 1:
    case 7:
        r = 1;
        break;
    }
    return r;
}

void *func_0013D120(Actor *a, int idx, int n) {
    int w = func_0013CC80(a, idx);
    int kind = (unsigned)w >> 28;
    int cnt = func_0013CC40(a, idx);
    int addr = AtelGetRealVarAdrs(a, w);

    if (n < 0) {
        n = 0;
    }
    if (n >= cnt) {
        n = cnt - 1;
    }
    return (void *)(addr + func_0013D0D8(kind) * n);
}

void func_0013D1C0(Actor *a, int idx, int n, int val, int clamp)
{
    void *p = func_0013D120(a, idx, n);
    int kind = func_0013D098(a, idx);

    switch (kind) {
    case 0:
        if (clamp) {
            int hi = 255;
            int t = val > -1 ? val : 0;

            if (t > hi) {
                t = hi;
            }
            val = t;
        }
        *(u8 *)p = val;
        break;
    case 1:
        if (clamp) {
            int hi = 127;
            int t = val > -129 ? val : -128;

            if (t > hi) {
                t = hi;
            }
            val = t;
        }
        *(s8 *)p = val;
        break;
    case 2:
        if (clamp) {
            int hi = 65535;
            int t = val > -1 ? val : 0;

            if (t > hi) {
                t = hi;
            }
            val = t;
        }
        *(u16 *)p = val;
        break;
    case 3:
        if (clamp) {
            int hi = 32767;
            int t = val > -32769 ? val : -32768;

            if (t > hi) {
                t = hi;
            }
            val = t;
        }
        *(s16 *)p = val;
        break;
    case 4:
    case 5:
        *(s32 *)p = val;
        break;
    case 6:
        *(float *)p = val;
        break;
    }
}

void func_0013D2E8(Actor *a, int idx, int n, int clamp, float f)
{
    void *p = func_0013D120(a, idx, n);
    int kind = func_0013D098(a, idx);
    int val = (int)f;

    switch (kind) {
    case 0:
        if (clamp) {
            int hi = 255;
            int t = val > -1 ? val : 0;

            if (t > hi) {
                t = hi;
            }
            val = t;
        }
        *(u8 *)p = val;
        break;
    case 1:
        if (clamp) {
            int hi = 127;
            int t = val > -129 ? val : -128;

            if (t > hi) {
                t = hi;
            }
            val = t;
        }
        *(s8 *)p = val;
        break;
    case 2:
        if (clamp) {
            int hi = 65535;
            int t = val > -1 ? val : 0;

            if (t > hi) {
                t = hi;
            }
            val = t;
        }
        *(u16 *)p = val;
        break;
    case 3:
        if (clamp) {
            int hi = 32767;
            int t = val > -32769 ? val : -32768;

            if (t > hi) {
                t = hi;
            }
            val = t;
        }
        *(s16 *)p = val;
        break;
    case 4:
    case 5:
        *(s32 *)p = val;
        break;
    case 6:
        *(float *)p = f;
        break;
    }
}

int func_0013D410(Actor *a, int idx, int n)
{
    void *p = func_0013D120(a, idx, n);
    int r = 0;

    switch (func_0013D098(a, idx)) {
    case 0:
        r = *(u8 *)p;
        break;
    case 1:
        r = *(s8 *)p;
        break;
    case 2:
        r = *(u16 *)p;
        break;
    case 3:
        r = *(s16 *)p;
        break;
    case 4:
    case 5:
        r = *(s32 *)p;
        break;
    case 6:
        r = (int)*(float *)p;
        break;
    }
    return r;
}

float func_0013D4C8(Actor *a, int idx, int n)
{
    void *p = func_0013D120(a, idx, n);
    int kind = func_0013D098(a, idx);
    float r = 0;

    switch (kind) {
    case 0:
        r = *(u8 *)p;
        break;
    case 1:
        r = *(s8 *)p;
        break;
    case 2:
        r = *(u16 *)p;
        break;
    case 3:
        r = *(s16 *)p;
        break;
    case 4:
        r = *(u32 *)p;
        break;
    case 5:
        r = *(s32 *)p;
        break;
    case 6:
        r = *(float *)p;
        break;
    }
    return r;
}

void func_0013D5D8(Actor *a, ScriptCtx *ctx, int idx, int v) {
    if (((unsigned)func_0013CC80(a, idx) >> 28) == 6) {
        func_0013CE10(a, ctx, func_0013D4C8(a, idx, v));
    } else {
        AtelPushStackInteger(a, ctx, func_0013D410(a, idx, v));
    }
}

void func_0013D680(Actor *a, ScriptCtx *ctx, int idx) {
    func_0013D5D8(a, ctx, idx, 0);
}

void func_0013D688(Actor *a, ScriptCtx *ctx, int idx) {
    func_0013D5D8(a, ctx, idx, AtelPopStackInteger(a, ctx));
}

void func_0013D6D8(Actor *a, ScriptCtx *ctx, int idx) {
    int base = func_0013CC80(a, idx);
    int kind = func_0013D098(a, idx);
    int n = AtelPopStackInteger(a, ctx);
    int cnt = func_0013CC40(a, idx);

    if (n < 0) {
        n = 0;
    }
    if (n >= cnt) {
        n = cnt - 1;
    }
    AtelPushStackInteger(a, ctx, base + func_0013D0D8(kind) * n);
}

int func_0013D790(int *p) {
    return *p;
}

void func_0013D798(int *p, int v) {
    *p = v;
}

void func_0013D7A0(int *p) {
    func_0013D798(p, 0);
}

ObjNodeR *func_0013D7A8(Actor *a, u8 *op) {
    u16 *q = (u16 *)(op + 0x2C); /* DEBT(CAST): op layout unknown */
    u16 x = q[0];
    u16 z = q[2];
    u16 y = q[1];
    ObjNodeR *r = 0;
    ObjNodeR *n;
    ObjNodeR *next;

    for (n = OBJR(a)->head80; n != 0; n = next) {
        next = n->next;
        if (n->u0E.b.hi == 3 && n->h0A == y && n->h08 == x && (n->u0E.h & 0xF) == z) {
            r = n;
        }
    }
    return r;
}

float func_0013D818(Actor *a) {
    return OBJR(a)->f94 * D_0058E590;
}

void func_0013D830(int id, float f) {
    OBJR(AtelGetBasicWork(id))->f94 = f;
}

void func_0013D858(float f) {
    D_0058E590 = f;
}

int func_0013D868(Actor *a, float w, float x, float y, float z) {
    ActorState *st = AtelGetPosWorkAdrs(a);

    return func_002D4850(w, x - st->x, y - st->y, z - st->z);
}

int func_0013D8D0(Actor *a, float w, float x, float y, float z) {
    ActorState *st = AtelGetPosWorkAdrs(a);

    return func_002D4850(w, x - st->x, 0.0f, z - st->z);
}

void func_0013D928(int a, int *p, float f) {
    if (f < 0.0f) {
        f = 0.0f;
    }
    if (f > 1.0f) {
        f = 1.0f;
    }
    TkMtCalcSpline(a, p + 4, p[0], f);
}

void func_0013D960(int a, int *p, float f) {
    if (f < 0.0f) {
        f = 0.0f;
    }
    if (f > 1.0f) {
        f = 1.0f;
    }
    func_002D5188(a, p + 4, p[0], f);
}

void func_0013D998(int a, int *p, float f) {
    if (f < 0.0f) {
        f = 0.0f;
    }
    if (f > 1.0f) {
        f = 1.0f;
    }
    func_002D5450(a, p + 4, p[0], f);
}

void func_0013D9D0(int a, int *p, float f) {
    if (f < 0.0f) {
        f = 0.0f;
    }
    if (f > 1.0f) {
        f = 1.0f;
    }
    func_002D5448(a, p + 4, p[0], f);
}

/* old-style definition: callers in this file pass other argument counts (DEBT(TYPE)) */
void func_0013DA08(a)
    Actor *a;
{
    ActorState *st = AtelGetPosWorkAdrs(a);
    Sys3D8 *g;

    st->px = st->x;
    st->py = st->y;
    st->pz = st->z;
    if (AQ(a)->stateAA == 1 && AQ(a)->ptr9C != 0) {
        Ch_GetPos(AQ(a)->ptr9C, &st->x, &st->y, &st->z);
        AQ(a)->bAC = func_00110560(AQ(a)->ptr9C);
    }
    g = D_0058E3D8;
    if (AQ(a)->id == g->hA) {
        g->prev[0] = g->cur[0];
        g->prev[1] = g->cur[1];
        g->prev[2] = g->cur[2];
        g->prev[3] = g->cur[3];
        g->cur[0] = st->x;
        g->cur[1] = st->y;
        g->cur[2] = st->z;
        g->cur[3] = 1.0f;
        if (AQ(a)->ptr9C != 0) {
            AtelSetBattleSceneGroup(Ch_IdGetEncount(AQ(a)->ptr9C));
            AtelSetSaveDicIndex(func_00121AB0(AQ(a)->ptr9C));
        } else {
            AtelSetBattleSceneGroup(0);
            AtelSetSaveDicIndex(0);
        }
    }
}

typedef struct {
    u16 h0;
    u16 h2;
    s16 h4;
    s16 h6;
    float f08;
    float fC;
    float f10;
    int w14;
    float f18;
    float f1C;
    float f20;
    float f24;
    float f28;
    float f2C;
    float f30;
    float f34;
    float f38;
    float f3C;
    float f40;
} AtelSlotAR;

float func_002D4798(float a, float b, float c, int d);

void func_0013DB38(Actor *a, void *op)
{
    ActorState *st = AtelGetPosWorkAdrs(a);
    AtelSlotAR *s = (AtelSlotAR *)((ObjBindR *)op)->s44;
    int flags = s->h2;
    float scale;
    float d[3];
    float pos[4];
    float out[2];

    if ((flags & 0xA000) == 0xA000) {
        func_0013EB20(a, s->h0);
    }
    scale = 1.0f;
    flags &= ~0xFF80;
    if (s->h4 > 0 || flags == 9 || flags == 7) {
        if (s->h6 < 0x7FFE) {
            s->h6++;
        }
        if (s->h4 < s->h6) {
            scale = (float)s->h6 / (float)s->h4;
            if (scale > 8.0f) {
                scale = 8.0f;
            }
        }
    }
    switch (flags) {
    case 1:
        s->f2C = st->y;
    case 2:
        if (s->h2 & 0x8000) {
            float tx = s->f28;
            float ty = s->f2C;
            float tz = s->f30;
            if (tx == st->x && tz == st->z) {
                if (ty < st->y) {
                    st->f24 = -3.1415927f;
                } else {
                    st->f24 = 3.1415927f;
                }
            } else {
                float r0, r1;
                func_002D45C0(&out[0], &out[1], st->x, st->y, st->z, tx, ty, tz);
                r0 = s->f3C;
                r1 = s->f40;
                if (s->h2 & 0x200) {
                    r0 = r1 = 6.2831855f;
                }
                r0 *= scale;
                r1 *= scale;
                st->f20 = func_002D46B0(st->f20, out[0], r0);
                st->f24 = func_002D46B0(st->f24, out[1], r1);
            }
        }
        d[0] = s->f28 - st->x;
        d[1] = s->f2C - st->y;
        d[2] = s->f30 - st->z;
        {
            float spd = s->f10;
            float len = func_002D4290(func_002D4278(d[0], d[1], d[2]));
            float div = 10.0f;
            if (AQ(a)->stateAA == 4 || AQ(a)->stateAA == 5) {
                div = 1.0f;
            }
            if (len <= spd / div) {
                spd = len * div;
                s->h2 |= 0x1000;
            }
            st->f0C = spd;
        }
        break;
    case 3:
        s->f2C = st->y;
    case 4:
        d[0] = s->f28 - st->x;
        d[1] = s->f2C - st->y;
        d[2] = s->f30 - st->z;
        {
            float len = func_002D4290(func_002D4278(d[0], d[1], d[2]));
            float spd = st->f0C;
            float maxSpd = s->f10;
            float brake;
            spd += s->f34;
            brake = func_002D4290((s->f34 + s->f34) * len);
            if (brake < maxSpd) {
                spd = (spd < 0.001f) ? 0.001f : ((spd > brake) ? brake : spd);
            }
            spd = (spd < 0.001f) ? 0.001f : ((spd > maxSpd) ? maxSpd : spd);
            st->f0C = spd;
            if (len <= spd / 10.0f) {
                s->h2 |= 0x1000;
            }
        }
        break;
    case 7:
        {
            float t = s->f08 / s->fC;
            float u;
            s->f08 += 1.0f;
            if (t < 0.0f) t = 0.0f;
            if (t > 1.0f) t = 1.0f;
            u = 1.0f - t;
            st->x = s->f1C * u + s->f28 * t;
            st->y = s->f20 * u + s->f2C * t;
            st->z = s->f24 * u + s->f30 * t;
            st->f0C = 0.0f;
        }
        break;
    case 5:
    case 6:
        {
            float t = s->f08 / s->fC;
            s->f08 += 1.0f;
            if (t < 0.0f) t = 0.0f;
            if (t > 1.0f) t = 1.0f;
            if (s->w14 != 0) {
                if (flags == 5) {
                    func_0013D928((int)pos, (int *)s->w14, t);
                } else {
                    func_0013D9D0((int)pos, (int *)s->w14, t);
                }
                func_002D45C0(&st->f20, &st->f24, st->x, st->y, st->z, pos[0], pos[1], pos[2]);
                st->f0C = func_002D4290(func_002D4278(pos[0] - st->x, pos[1] - st->y, pos[2] - st->z));
            } else {
                s->f08 = s->fC + 1.0f;
                st->f0C = 0.0f;
            }
        }
        break;
    case 9:
        {
            float t;
            float u;
            float nx, ny, nz;
            if (s->h6 >= *(u16 *)((u8 *)a + 0xB16)) {
                s->f08 += 1.0f;
                t = s->f08 / s->fC;
                if (s->f08 >= s->fC) {
                    t = 1.0f;
                    s->h2 |= 0x1000;
                }
            } else {
                t = 0.0f;
            }
            u = 1.0f - t;
            nx = s->f28 * t + s->f1C * u;
            nz = s->f30 * t + s->f24 * u;
            ny = (s->f18 + (s->f34 * 0.5f) * t) * t + s->f20;
            st->f0C = 0.0f;
            st->x = nx;
            st->z = nz;
            st->y = ny;
        }
        break;
    case 0:
    case 8:
    case 10:
    case 11:
    default:
        st->f0C = 0.0f;
        break;
    }
}

typedef struct {
    u16 h0;
    u16 h2;
    s16 h4;
    s16 h6;
    float f08;
    float fC;
    float f10;
    float f14;
    float f18;
    float f1C;
    float f20;
    float f24;
    float f28;
    float f2C;
    float f30;
    float f34;
} AtelSlotBR;

void func_0013E150(Actor *a, void *op)
{
    ActorState *st = AtelGetPosWorkAdrs(a);
    AtelSlotAR *s44 = (AtelSlotAR *)((ObjBindR *)op)->s44;
    float scale = 1.0f;
    float ease = 1.0f;
    u16 flags;
    float spd;
    float t;
    float d0, d1, d2;

    op = ((ObjBindR *)op)->s48;
#define s ((AtelSlotBR *)op)
    flags = s->h2;
    if (s->h4 > 0) {
        if (s->h6 < 0x7FFE) {
            s->h6++;
        }
        if (s->h4 < s->h6) {
            scale = (float)s->h6 / (float)s->h4;
            if (scale > 8.0f) {
                scale = 8.0f;
            }
        }
    }
    if (flags & 0x200) {
        spd = s->f14;
    } else {
        spd = s->f10;
    }
    switch (flags & 0x1F) {
    case 0:
        break;
    case 2: {
        float f = s->f08;
        float u;
        f += s->fC;
        if (f < 0.0f) {
            f = 0.0f;
        }
        if (f >= 1.0f) {
            if (s->f20 == st->f34) {
                s->h2 = (s->h2 & ~0x1F) | 1;
            }
            f = 1.0f;
        }
        s->f08 = f;
        u = f - 0.5f;
        ease = (u * -4.0f * u + 1.0f) * 0.6f + 0.4f;
        if (ease < 0.0f) {
            ease = 0.0f;
        }
        if (ease > 1.0f) {
            ease = 1.0f;
        }
    }
    case 1:
    case 5:
        if (flags & 0x8000) {
            int mode = 0;
            float ox, oy;
            if (flags & 0x800) {
                mode = 1;
            }
            if (flags & 0x400) {
                mode = 2;
            }
            if (flags & 0x2000) {
                func_0013EC20(a, s->h0);
            }
            func_002D45C0(&ox, &oy, st->x, st->y, st->z, s44->f28, s44->f2C, s44->f30);
            s->f2C = func_002D4338(s->f2C + ox - s->f20);
            s->f30 = func_002D4338(s->f30 + oy - s->f24);
            s->f20 = ox;
            s->f24 = oy;
            st->f34 = func_002D4798(st->f34, s->f20, spd * ease * scale, mode);
            st->f30 = func_002D4798(st->f30, s->f24, s->f18 * ease * scale, mode);
        } else {
            st->f34 = func_002D4338(st->f34 + s->f10);
            st->f30 = func_002D4338(st->f30 + s->f18);
            st->f38 = func_002D4338(st->f38 + s->f1C);
        }
        break;
    case 3: {
        float f = s->f08 + 1.0f;
        t = f / s->fC;
        s->f08 = f;
        if (t < 0.0f) {
            t = 0.0f;
        }
        if (t > 1.0f) {
            t = 1.0f;
        }
        if (flags & 0x8000) {
            float ox, oy;
            if (flags & 0x2000) {
                func_0013EC20(a, s->h0);
            }
            func_002D45C0(&ox, &oy, st->x, st->y, st->z, s44->f28, s44->f2C, s44->f30);
            s->f2C = func_002D4338(s->f2C + ox - s->f20);
            s->f30 = func_002D4338(s->f30 + oy - s->f24);
        }
        if (t >= 1.0f) {
            st->f34 = s->f20;
            st->f30 = s->f24;
            st->f38 = s->f28;
        } else if (t == 0.0f) {
            st->f34 = func_002D4338(s->f20 + s->f2C);
            st->f30 = func_002D4338(s->f24 + s->f30);
            st->f38 = func_002D4338(s->f28 + s->f34);
        } else {
            float u;
            d0 = 0.0f;
            d1 = 0.0f;
            d2 = 0.0f;
            if (flags & 0x800) {
                if (s->f2C > 0.0f) {
                    d0 = -6.2831855f;
                }
                if (s->f30 > 0.0f) {
                    d1 = -6.2831855f;
                }
                if (s->f34 > 0.0f) {
                    d2 = -6.2831855f;
                }
            }
            if (flags & 0x400) {
                if (s->f2C < 0.0f) {
                    d0 = 6.2831855f;
                }
                if (s->f30 < 0.0f) {
                    d1 = 6.2831855f;
                }
                if (s->f34 < 0.0f) {
                    d2 = 6.2831855f;
                }
            }
            u = 1.0f - t;
            st->f34 = func_002D4338(s->f20 + (s->f2C + d0) * u);
            st->f30 = func_002D4338(s->f24 + (s->f30 + d1) * u);
            st->f38 = func_002D4338(s->f28 + (s->f34 + d2) * u);
        }
        break;
    }
    case 4: {
        float f = s->f08 + 1.0f;
        t = f / s->fC;
        s->f08 = f;
        if (t < 0.0f) {
            t = 0.0f;
        }
        if (t > 1.0f) {
            t = 1.0f;
        }
        if (flags & 0x8000) {
            float ox, oy;
            if (flags & 0x2000) {
                func_0013EC20(a, s->h0);
            }
            func_002D45C0(&ox, &oy, st->x, st->y, st->z, s44->f28, s44->f2C, s44->f30);
            s->f2C = func_002D4338(s->f2C + ox - s->f20);
            s->f30 = func_002D4338(s->f30 + oy - s->f24);
        }
        if (t >= 0.5f) {
            t = 1.0f - t;
            t = 1.0f - (t + t) * t;
        } else {
            t = t * (t + t);
        }
        if (t >= 1.0f) {
            st->f34 = s->f20;
            st->f30 = s->f24;
            st->f38 = s->f28;
        } else if (t <= 0.0f) {
            st->f34 = func_002D4338(s->f2C + s->f20);
            st->f30 = func_002D4338(s->f30 + s->f24);
            st->f38 = func_002D4338(s->f34 + s->f28);
        } else {
            float u;
            d0 = 0.0f;
            d1 = 0.0f;
            d2 = 0.0f;
            if (flags & 0x800) {
                if (s->f2C > 0.0f) {
                    d0 = -6.2831855f;
                }
                if (s->f30 > 0.0f) {
                    d1 = -6.2831855f;
                }
                if (s->f34 > 0.0f) {
                    d2 = -6.2831855f;
                }
            }
            if (flags & 0x400) {
                if (s->f2C < 0.0f) {
                    d0 = 6.2831855f;
                }
                if (s->f30 < 0.0f) {
                    d1 = 6.2831855f;
                }
                if (s->f34 < 0.0f) {
                    d2 = 6.2831855f;
                }
            }
            u = 1.0f - t;
            st->f34 = func_002D4338(s->f20 + (s->f2C + d0) * u);
            st->f30 = func_002D4338(s->f24 + (s->f30 + d1) * u);
            st->f38 = func_002D4338(s->f28 + (s->f34 + d2) * u);
        }
        break;
    }
    }
    if (flags & 0x1000) {
        st->f20 = st->f34;
        st->f24 = st->f30;
    }
#undef s
}

void func_0013E850(Actor *a) {
    ActorState *st = AtelGetPosWorkAdrs(a);

    if (AQ(a)->stateAA == 1 && AQ(a)->ptr9C != 0) {
        st->f20 = func_001102F8(AQ(a)->ptr9C);
    }
}

void func_0013E8A8(Actor *a) {
    ActorState *st = AtelGetPosWorkAdrs(a);

    if (AQ(a)->stateAA == 1 && AQ(a)->ptr9C != 0) {
        st->f34 = func_002D4338(func_00110288(AQ(a)->ptr9C));
    }
}

void func_0013E908(Actor *a) {
    ActorState *st = AtelGetPosWorkAdrs(a);

    if (AQ(a)->stateAA == 1 && AQ(a)->ptr9C != 0) {
        st->f34 = func_002D4338(func_001102F8(AQ(a)->ptr9C));
    }
}

void func_0013E968(Actor *a, void *op) {
    float f = AtelGetPosWorkAdrs(a)->f20;

    if (AQ(a)->stateAA == 1 && AQ(a)->ptr9C != 0) {
        func_00110308(AQ(a)->ptr9C, f);
    }
}

void func_0013E9B8(Actor *a, void *op) {
    ActorState *st = AtelGetPosWorkAdrs(a);
    ObjSlotBR *s = ((ObjBindR *)op)->s48;
    float f = st->f34;
    u16 h2 = s->h2;

    if (AQ(a)->stateAA == 1 && AQ(a)->ptr9C != 0) {
        func_00110300(AQ(a)->ptr9C, f);
    }
    switch (h2 & 0x1F) {
    case 5:
        goto done;
    case 3:
    case 4:
        if (s->f08 > s->fC && !(s->h2 & 0x4000)) {
            s->h2 &= 0x5000;
            func_0013BE58(a, -1);
        }
        break;
    }
    if (st->f34 == s->f20) {
        if ((!(s->h2 & 0x80) || st->f30 == s->f24) && (!(s->h2 & 0x40) || st->f38 == s->f28)) {
            if (!(s->h2 & 0x4000)) {
                s->h2 &= 0x5000;
                func_0013BE58(a, -1);
            }
        }
    }
done:;
}

int func_0013EB20(Actor *a, int v) {
    ObjBindR *b = OBJBIND(a, a->slotIdx);
    ActorState *st = AtelGetPosWorkAdrs(AtelGetBasicWork(v));

    b->s44->h0 = v;
    func_0013BCE0(a, st->x, st->y, st->z);
}

void func_0013EB88(Actor *a, float x, float y, float z) {
    ObjSlotBR *s = OBJBIND(a, a->slotIdx)->s48;
    ActorState *st = AtelGetPosWorkAdrs(a);
    float out[2];

    func_002D45C0(&out[0], &out[1], st->x, st->y, st->z, x, y, z);
    s->f20 = out[0];
    s->f24 = out[1];
}

int func_0013EC20(Actor *a, int v) {
    ObjBindR *b = OBJBIND(a, a->slotIdx);
    ActorState *st;

    b->s48->h0 = v;
    st = AtelGetPosWorkAdrs(AtelGetBasicWork(v));
    func_0013EB88(a, st->x, st->y, st->z);
}

INCLUDE_ASM("build/ee_asm/game/atel/atel_13CA80", func_0013EC80);
INCLUDE_RODATA("build/ee_asm/game/atel/atel_13CA80/rodata", jtbl_0056A980);
INCLUDE_RODATA("build/ee_asm/game/atel/atel_13CA80/rodata", jtbl_0056A9A0);

int func_002D5458(float *a, float *b, float *c, float *d);
float func_002D5540(float *a, float *b, float *c, float *d);

void func_0013EF90(Actor *a, void *op, int id, PoolEntQ *entry) {
    float v0[4];
    float v1[4];
    float v2[4];
    float v3[4];
    ActorState *st = AtelGetPosWorkAdrs(a);
    float f1C;

    if (id == 0xFFFF) {
        v2[0] = D_0058E3D8->prev[0];
        v2[1] = D_0058E3D8->prev[1];
        v2[2] = D_0058E3D8->prev[2];
        v3[0] = D_0058E3D8->cur[0];
        v3[1] = D_0058E3D8->cur[1];
        v3[2] = D_0058E3D8->cur[2];
    } else {
        ActorState *st2 = AtelGetPosWorkAdrs(AtelGetBasicWork(id));
        v2[0] = st2->px;
        v2[1] = st2->py;
        v2[2] = st2->pz;
        v3[0] = st2->x;
        v3[1] = st2->y;
        v3[2] = st2->z;
    }
    v0[0] = st->x;
    v0[1] = st->y;
    v0[2] = st->z;
    v1[0] = st->f30;
    v1[1] = st->f34;
    v1[2] = st->f38;
    f1C = st->f1C;
    if (v2[0] != v3[0] || v2[2] != v3[2] || (a->flags34.w & 0x10000)) {
        int res;
        a->flags34.w &= ~0x10000;
        res = func_002D5458(v2, v3, v0, v1);
        if (res != 0) {
            float d = func_002D5540(v2, v3, v0, v1);
            if (f1C <= 0.0f || d <= f1C) {
                if (entry == 0) {
                    if (res > 0) {
                        a->flags34.w = (a->flags34.w & ~0x60000) | 0x20000;
                    } else {
                        a->flags34.w &= ~0x60000;
                    }
                    func_0014B720(0xFFFF, a->id, 4);
                } else {
                    if (res > 0) {
                        entry->b4 = 1;
                    } else {
                        entry->b4 = 0;
                    }
                    func_0014B780(0xFFFF, a->id, 4, entry->h2);
                }
            }
        }
    }
}

void func_0013F1D8(Actor *a, void *op) {
    PoolEntQ *pool, *entry;
    u16 *flags;
    int left;
    u16 id, enabled, sentinel;

    func_0013EF90(a, op, AtelGetPosWorkAdrs(a)->h28, 0);
    pool = a->poolEntries;
    if (pool) {
        /* DEBT(ORDER): initialize the flag stream before the record cursor. */
        sentinel = 0xFFFF;
        flags = &pool->h2;
        entry = pool;
        left = 7;
        do {
            id = entry->h0;
            enabled = *flags;
            if (id != sentinel && enabled)
                func_0013EF90(a, op, id, entry);
            flags += 4;
            left--;
            entry++;
        } while (left >= 0);
    }
}

float func_002D5AE8(float *a, float *b, float *c);

void func_0013F288(Actor *a, void *op, Actor *target) {
    float v0[4];
    float v1[4];
    float v2[4];
    float v3[4];
    ActorState *st = AtelGetPosWorkAdrs(a);
    ActorState *st2 = AtelGetPosWorkAdrs(target);
    int crossed = 0;
    float f1C;
    float t;
    float cx, cy, cz;
    float dist2;
    int prev;

    v0[0] = st->x;
    v0[1] = st->y;
    v0[2] = st->z;
    v1[0] = st->f30;
    v1[1] = st->f34;
    v1[2] = st->f38;
    v2[0] = D_0058E3D8->prev[0];
    v2[1] = D_0058E3D8->prev[1];
    v2[2] = D_0058E3D8->prev[2];
    v3[0] = D_0058E3D8->cur[0];
    v3[1] = D_0058E3D8->cur[1];
    v3[2] = D_0058E3D8->cur[2];
    f1C = st->f1C;
    if (v2[0] != v3[0] || v2[2] != v3[2] || (a->flags34.w & 0x10000)) {
        a->flags34.w &= ~0x10000;
        crossed = func_002D5458(v2, v3, v0, v1);
        if (crossed != 0) {
            float d = func_002D5540(v2, v3, v0, v1);
            if (f1C <= 0.0f || d <= f1C) {
                if (crossed > 0) {
                    a->flags34.w = (a->flags34.w & ~0x60000) | 0x20000;
                } else {
                    a->flags34.w &= ~0x60000;
                }
                crossed = 1;
                func_0014B720(0xFFFF, a->id, 4);
            } else {
                crossed = 0;
            }
        }
    }
    t = func_002D5AE8(v3, v0, v1);
    {
        float p3x = v3[0];
        float p3y = v3[1];
        float p3z = v3[2];

        cx = (v1[0] - v0[0]) * t + v0[0];
        cz = (v1[2] - v0[2]) * t + v0[2];
        cy = (v1[1] - v0[1]) * t + v0[1];
        dist2 = func_002D4278(cx - p3x, 0.0f, cz - p3z);
        prev = ((u32)a->flags34.w >> 6) & 1;
        t = st->f48 * st->f48;
        if (dist2 <= t && (f1C <= 0.0f || (p3y <= cy + f1C && cy - f1C <= p3y))) {
            a->flags34.w |= 0x40;
            func_0014B720(0xFFFF, a->id, 3);
            if (!prev) {
                func_0014B720(0xFFFF, a->id, 5);
            }
        } else {
            a->flags34.w &= ~0x40;
            if (crossed) {
                func_0014B720(0xFFFF, a->id, 5);
            }
            if (prev == 1 || crossed) {
                func_0014B720(0xFFFF, a->id, 6);
            }
        }
        if ((a->flagsAB & 1) && D_0058E3D8->b1E4 == 1) {
            float r = st->f40 + D_0058E3D8->f1F0;
            t = r * r;

            if (dist2 <= t && (f1C <= 0.0f || (p3y <= cy + f1C && cy - f1C <= p3y))) {
                if (D_0058E3D8->h1E8 == 0xFFFF || t < D_0058E3D8->f1EC) {
                    if (func_002D47E8(st2->f34, st->f3C, p3x, p3z, cx, cz)) {
                        D_0058E3D8->f1EC = t;
                        D_0058E3D8->h1E8 = a->id;
                    }
                }
            }
        }
    }
}

int func_0013F6D8(Actor *a, void *op)
{
    ActorState *st;
    float sx, sy, sz;
    float angle;
    float hz, hx;
    float f1C;
    float prev_x, prev_y, prev_z;
    float cur_x, cur_y, cur_z;
    float s, c;
    int code1, code2;
    int crossed = 0;
    int inside = 0;
    int prev;

    st = AtelGetPosWorkAdrs(a);
    sy = st->y;
    hz = st->f38;
    angle = -st->f34;
    hx = st->f30;
    f1C = st->f1C;
    sx = st->x;
    sz = st->z;
    if (st->h28 == 0xFFFF) {
        Sys3D8 *g = D_0058E3D8;
        prev_x = g->prev[0];
        prev_y = g->prev[1];
        prev_z = g->prev[2];
        cur_x = g->cur[0];
        cur_y = g->cur[1];
        cur_z = g->cur[2];
    } else {
        ActorState *st2 = AtelGetPosWorkAdrs(AtelGetBasicWork(st->h28));
        prev_x = st2->px;
        prev_y = st2->py;
        prev_z = st2->pz;
        cur_x = st2->x;
        cur_y = st2->y;
        cur_z = st2->z;
    }
    s = func_002E89C0(angle);
    c = func_002E8648(angle);
    prev_x -= sx;
    prev_z -= sz;
    cur_x -= sx;
    cur_z -= sz;
    a->flags34.w &= ~0x10000;
    {
        float px = c * prev_x + (-s) * prev_z;
        float pz = s * prev_x + c * prev_z;
        prev_x = px;
        prev_z = pz;
        sx = c * cur_x + (-s) * cur_z;
        sz = s * cur_x + c * cur_z;
    }
    prev_y -= sy;
    cur_y -= sy;
    code1 = 0;
    code2 = 0;
    if (prev_x >= hx) {
        code1 |= 1;
    }
    if (prev_x <= -hx) {
        code1 |= 2;
    }
    if (prev_z >= hz) {
        code1 |= 4;
    }
    if (prev_z <= -hz) {
        code1 |= 8;
    }
    if (f1C > 0.0f) {
        if (prev_y >= f1C) {
            code1 |= 0x10;
        }
        if (prev_y <= -f1C) {
            code1 |= 0x20;
        }
    }
    prev_x = sx;
    prev_z = sz;
    if (sx >= hx) {
        prev_x = hx;
        code2 |= 1;
    }
    if (sx <= -hx) {
        prev_x = -hx;
        code2 |= 2;
    }
    if (sz >= hz) {
        prev_z = hz;
        code2 |= 4;
    }
    if (sz <= -hz) {
        prev_z = -hz;
        code2 |= 8;
    }
    if (f1C > 0.0f) {
        if (cur_y >= f1C) {
            code2 |= 0x10;
        }
        if (cur_y <= -f1C) {
            code2 |= 0x20;
        }
    }
    if ((code1 & code2) == 0) {
        if ((code1 | code2) != 0) {
            crossed = 1;
        }
    }
    prev = ((u32)a->flags34.w >> 6) & 1;
    if (code2 == 0) {
        a->flags34.w |= 0x100;
        inside = 1;
    } else {
        a->flags34.w &= ~0x100;
        if (f1C <= 0.0f || (prev_y <= f1C && prev_y >= -f1C)) {
            if (func_002D4278(sx - prev_x, 0.0f, sz - prev_z) <= st->f48 * st->f48) {
                inside = 1;
            }
        }
    }
    a->flags34.w = (a->flags34.w & ~0x40) | (inside << 6);
    if (inside) {
        if (!prev) {
            func_0014B740(0xFFFF, a->id, 5);
        }
    } else {
        if (crossed && !prev) {
            func_0014B740(0xFFFF, a->id, 5);
        }
        if (prev == 1 || crossed) {
            func_0014B740(0xFFFF, a->id, 6);
        }
    }
}

void func_0013FB40(Actor *a, void *op, Actor *target)
{
    ActorState *st;
    ActorState *st2;
    float angle;
    float prev_x, prev_y, prev_z;
    float cur_x, cur_y, cur_z;
    float hz, hx, f1C;
    float t, p1, p2, p3, p4;
    int code1;
    int crossed = 0;
    int inside = 0;
    int code2 = 0;
    int prev;

    st = AtelGetPosWorkAdrs(a);
    st2 = AtelGetPosWorkAdrs(target);
    angle = -st->f34;
    t = st->x;
    prev_x = D_0058E3D8->prev[0];
    prev_y = D_0058E3D8->prev[1];
    prev_x -= t;
    cur_y = D_0058E3D8->cur[1];
    p1 = st->z;
    prev_y -= st->y;
    prev_z = D_0058E3D8->prev[2];
    cur_y -= st->y;
    cur_z = D_0058E3D8->cur[2];
    hx = st->f30;
    prev_z -= p1;
    cur_x = D_0058E3D8->cur[0];
    cur_z -= p1;
    hz = st->f38;
    f1C = st->f1C;
    cur_x -= t;
    p1 = func_002E8648(angle) * prev_x;
    t = p1 - func_002E89C0(angle) * prev_z;
    p2 = func_002E89C0(angle) * prev_x;
    prev_x = t;
    prev_z = p2 + func_002E8648(angle) * prev_z;
    p3 = func_002E8648(angle) * cur_x;
    t = p3 - func_002E89C0(angle) * cur_z;
    p4 = func_002E89C0(angle) * cur_x;
    p4 = p4 + func_002E8648(angle) * cur_z;
    a->flags34.w &= ~0x10000;
    code1 = 0;
    if (prev_x >= hx) {
        code1 |= 1;
    }
    if (prev_x <= -hx) {
        code1 |= 2;
    }
    if (prev_z >= hz) {
        code1 |= 4;
    }
    if (prev_z <= -hz) {
        code1 |= 8;
    }
    if (f1C > 0.0f) {
        if (prev_y >= f1C) {
            code1 |= 0x10;
        }
        if (prev_y <= -f1C) {
            code1 |= 0x20;
        }
    }
    prev_x = t;
    prev_z = p4;
    if (t >= hx) {
        prev_x = hx;
        code2 |= 1;
    }
    if (t <= -hx) {
        prev_x = -hx;
        code2 |= 2;
    }
    if (p4 >= hz) {
        prev_z = hz;
        code2 |= 4;
    }
    if (p4 <= -hz) {
        prev_z = -hz;
        code2 |= 8;
    }
    if (f1C > 0.0f) {
        if (cur_y >= f1C) {
            code2 |= 0x10;
        }
        if (cur_y <= -f1C) {
            code2 |= 0x20;
        }
    }
    if ((code1 & code2) == 0) {
        if ((code1 | code2) != 0) {
            crossed = 1;
        }
    }
    if (crossed && !(a->flags34.w & 0x100)) {
        func_0014B720(0xFFFF, a->id, 4);
    }
    prev = ((u32)a->flags34.w >> 6) & 1;
    if (code2 == 0) {
        a->flags34.w |= 0x100;
        inside = 1;
    } else {
        a->flags34.w &= ~0x100;
        if (f1C <= 0.0f || (prev_y <= f1C && prev_y >= -f1C)) {
            if (func_002D4278(t - prev_x, 0.0f, p4 - prev_z) <= st->f48 * st->f48) {
                inside = 1;
            }
        }
    }
    a->flags34.w = (a->flags34.w & ~0x40) | (inside << 6);
    if (inside) {
        func_0014B720(0xFFFF, a->id, 3);
        if (!prev) {
            func_0014B720(0xFFFF, a->id, 5);
        }
    } else {
        if (crossed && !prev) {
            func_0014B720(0xFFFF, a->id, 5);
        }
        if (prev == 1 || crossed) {
            func_0014B720(0xFFFF, a->id, 6);
        }
    }
    if (a->flagsAB & 1) {
        int hit = 0;
        if (D_0058E3D8->b1E4 == 1) {
            float r = st->f40 + D_0058E3D8->f1F0;
            float r2 = r * r;

            if (code2 == 0) {
                hit = 1;
            } else if ((f1C <= 0.0f || (prev_y <= f1C && prev_y >= -f1C)) &&
                       func_002D4278(t - prev_x, 0.0f, p4 - prev_z) <= r2) {
                hit = 1;
            }
            if (hit) {
                if (D_0058E3D8->h1E8 == 0xFFFF || r2 < D_0058E3D8->f1EC) {
                    if (func_002D47E8(st2->f34, st->f3C, D_0058E3D8->cur[0], D_0058E3D8->cur[2], st->x, st->z)) {
                        D_0058E3D8->f1EC = r2;
                        D_0058E3D8->h1E8 = a->id;
                    }
                }
            }
        }
    }
}

float fabsf(float);
int func_00140038(Actor *a, void *op, Actor *a2)
{
    register int ret __asm__("$20") = 0; /* DEBT(REG) */
    ActorState *st = AtelGetPosWorkAdrs(a);
    ActorState *st2 = AtelGetPosWorkAdrs(a2);
    int hit;
    float cy, py, cx, pz, px, cz;
    float f1C;
    float dist;
    u32 flags;
    __asm__("" : "=r"(hit) : "0"(ret));

    {
        register int stAA __asm__("$3") = a->stateAA; /* DEBT(REG) */
        register int one __asm__("$4") = 1; /* DEBT(REG) */
        __asm__("" : "+r"(stAA));
        __asm__("" : "+r"(stAA));
        __asm__("" : "+r"(one));
        flags = a->flags34.w;
        f1C = st->f1C;
        px = st->x;
        py = st->y;
        pz = st->z;
        cx = D_0058E3D8->cur[0];
        cy = D_0058E3D8->cur[1];
        cz = D_0058E3D8->cur[2];
        if (stAA != one) {
            return 0;
        }
    }
    a->flags34.w = flags & ~0x10000;
    if (fabsf(cy - py) < f1C) {
        float t = func_002D4278(cx - px, 0.0f, cz - pz);
        dist = st->f48 * st->f48;
        if (t <= dist) {
            hit = 1;
        }
    }
    if (hit != 0) {
        ret = func_0014B720(0xFFFF, a->id, 3);
    }
    a->flags34.w = (a->flags34.w & ~0x40) | (hit << 6);
    if (a->flagsAB & 1) {
        hit = 0;
        if (D_0058E3D8->b1E4 == 1) {
            float r;
            float r2;
            px = st->x;
            py = st->y;
            pz = st->z;
            cx = D_0058E3D8->cur[0];
            cy = D_0058E3D8->cur[1];
            cz = D_0058E3D8->cur[2];
            if (st->f2C < 0.0f) {
                dist = func_002D4278(cx - px, cy - py, cz - pz);
            } else {
                dist = func_002D4278(cx - px, 0.0f, cz - pz);
            }
            r = st->f40 + D_0058E3D8->f1F0;
            r2 = r * r;
            if (st->f2C < 0.0f) {
                if (dist < r2) {
                    if ((a->flags34.w & 0x80220) == 0) {
                        hit = 1;
                    }
                }
            } else {
                if (dist < r2 && (a->flags34.w & 0x80220) == 0 && fabsf(cy - py) < st->f2C) {
                    hit = 1;
                }
            }
            if (hit != 0) {
                if (D_0058E3D8->h1E8 == 0xFFFF || dist < D_0058E3D8->f1EC) {
                    if (func_002D47E8(st2->f34, st->f3C, cx, cz, px, pz)) {
                        D_0058E3D8->f1EC = dist;
                        D_0058E3D8->h1E8 = a->id;
                    }
                }
            }
        }
    }
    return ret;
}

void func_001402F8(Actor *a, void *op)
{
    ObjBindR *bind;
    ActorState *st;
    float speed;
    float d[4];
    float pos[4];

    switch (a->stateAA) {
    case 2:
    case 3:
    case 4:
    case 5:
        bind = OBJBIND(a, a->slotIdx);
        st = AtelGetPosWorkAdrs(a);
        speed = st->f0C;
        if (a->stateAA != 4 && a->stateAA != 5) {
            speed *= func_00138C88();
        } else {
            speed /= 10.0f;
        }
        func_002D4D58(d, speed, st->f20, st->f24);
        st->x += d[0];
        st->y += d[1];
        st->z += d[2];
        switch (a->stateAA) {
        case 2:
            if (bind->s44->h2 != 0 || bind->s48->h2 != 0) {
                pos[0] = st->x;
                pos[1] = st->y;
                pos[2] = st->z;
                pos[3] = 1.0f;
                MsCameraSetRect(a->w3C, 1, pos);
            }
            break;
        case 4:
        case 5:
            AtelSetBindObject(a);
            break;
        }
        break;
    }
}

void func_00140468(Actor *a, void *op)
{
    ActorState *st;

    if (a->hdr->type != 1) {
        return;
    }
    if (a->ptr9C != 0 && (a->w38 & 1)) {
        ActorState *pos = AtelGetPosWorkAdrs(a);

        graphicPreviousLevelGetNameHash(a->ptr9C, pos->x, pos->y - 0.1f, pos->z);
        Ch_ClothReset(a->ptr9C);
        a->w38 &= ~1;
    }
    func_0013DA08(a, op);
    if (a->w38 & 4) {
        if (D_0058E3D8->flags & 0x3000000) {
            st = AtelGetPosWorkAdrs(a);
            func_0013E850(a);
            st->f34 = st->f20;
        }
    }
}

void func_00140558(Actor *a, void *op)
{
    u16 id;

    if (!(a->flags34.w & 0x80)) {
        return;
    }
    id = D_0058E3D8->hA;
    switch (a->hdr->type) {
    case 2:
        if (id != 0xFFFF) {
            func_0013F288(a, op, AtelGetBasicWork(id));
        }
        break;
    case 5:
        func_0013F1D8(a, op);
        break;
    case 3:
        if (id != 0xFFFF) {
            func_0013FB40(a, op, AtelGetBasicWork(id));
        }
        break;
    case 6:
        func_0013F6D8(a, op);
        break;
    case 1:
        func_0013DB38(a, op);
        func_0013E150(a, op);
        if (!(a->flags34.w & 0x20)) {
            func_0013EC80(a, op);
            func_0013E968(a, op);
            func_0013E9B8(a, op);
            func_001402F8(a, op);
        } else {
            func_0013E850(a);
            func_0013E8A8(a);
        }
        if (id != 0xFFFF) {
            func_00140038(a, op, AtelGetBasicWork(id));
        }
        break;
    }
}

int func_001406E8(void) {
    return 1;
}

int func_001406F0(u8 op, Actor *a, OpRes1406 *r, ScriptCtx *ctx)
{
    int ok = 1;
    int x, y, z;
    int res;

    switch (op) {
    case 0x4C:
    case 0x4D:
    case 0x4E:
        ok = D_0058E3D8->f60();
        break;
    }
    x = AtelPopStackInteger(a, ctx);
    y = AtelPopStackInteger(a, ctx);
    z = AtelPopStackInteger(a, ctx);
    if (ok && x) {
        switch (op) {
        case 0x4B:
        case 0x4E:
            res = func_00142688(a->id, y, 1, z, x);
            break;
        case 0x4A:
        case 0x4D:
            res = func_00142530(a->id, y, 1, z, x);
            break;
        case 0x37:
        default:
            res = func_001425E0(a->id, y, 1, z, x);
            break;
        }
    } else {
        res = 0;
    }
    AtelPushStackInteger(a, ctx, res);
    if (res) {
        s16 *v = r->v;

        v[0] = x;
        v[1] = y;
        v[2] = z;
        r->valid = 1;
    }
    return 0;
}

int func_00140878(u8 op, Actor *a, OpRes1406 *r, ScriptCtx *ctx)
{
    int ok = 1;
    int x, y, z;
    int res;

    switch (op) {
    case 0x51:
    case 0x52:
    case 0x53:
        ok = D_0058E3D8->f60();
        break;
    }
    x = AtelPopStackInteger(a, ctx);
    y = AtelPopStackInteger(a, ctx);
    z = AtelPopStackInteger(a, ctx);
    if (ok && x) {
        switch (op) {
        case 0x50:
        case 0x53:
            res = func_00142688(a->id, y, 2, z, x);
            break;
        case 0x4F:
        case 0x52:
            res = func_00142530(a->id, y, 2, z, x);
            break;
        case 0x38:
        default:
            res = func_001425E0(a->id, y, 2, z, x);
            break;
        }
    } else {
        res = 0;
    }
    AtelPushStackInteger(a, ctx, res);
    if (res) {
        s16 *v = r->v;

        v[0] = x;
        v[1] = y;
        v[2] = z;
        r->valid = 1;
    }
    return 0;
}

void func_00140A00(u8 op, void *unused, Actor *a, ScriptCtx *ctx)
{
    int ok = 1;
    int x, y, z;
    int res;

    switch (op) {
    case 0x47:
    case 0x48:
    case 0x49:
        ok = D_0058E3D8->f60();
        break;
    }
    x = AtelPopStackInteger(a, ctx);
    y = AtelPopStackInteger(a, ctx);
    z = AtelPopStackInteger(a, ctx);
    if (ok && x) {
        switch (op) {
        case 0x46:
        case 0x49:
            res = func_00142688(a->id, y, 0, z, x);
            break;
        case 0x45:
        case 0x48:
            res = func_00142530(a->id, y, 0, z, x);
            break;
        case 0x36:
        default:
            res = func_001425E0(a->id, y, 0, z, x);
            break;
        }
    } else {
        res = 0;
    }
    AtelPushStackInteger(a, ctx, res);
}

typedef struct {
    u32 w00[4];
    u16 h10[4];
    char *p18;
    u8 b1C;
    s8 b1D;
    u8 b1E;
    u8 b1F;
    int w20;
    int w24;
    float f28;
    u16 h2C;
    u16 h2E;
    u16 h30;
} ActorBindVM;

typedef struct {
    s32 flags;
    u8 pad04[0x24];
    void (*f28)(int id, u32 op);
    u8 pad2C[0x2C];
    void (*f58)(Actor *a, ActorBind *b);
    void (*f5C)(Actor *a, ActorBind *b);
    int (*f60)(void);
    Ent3D8 ent[4];
} Sys3D8VM;

typedef struct {
    ActorHdr *hdr;
    void *blob;
    u8 pad08[0x26];
    u16 id;
    u8 pad30[2];
    u8 slotIdx;
    u8 pad33;
    s32 flags34;
    u8 pad38[0x10];
    int w48[4];
    float f58[10];
    u8 pad80[0x18];
    float f98;
    u8 pad9C[0x28];
    ScriptCtx ctxC4;
} ActorVM;

extern int D_0030B8C8[];
int MsBattleCheck(void);
int func_0013CA30(Actor *a, int n);
int func_0013B008(int id);
void func_0013A3B8(Actor *a, int x, int y, int z);
int func_00143FB8(Actor *a, int x, int y);
void func_0014BA30(int arg, Actor *a, void *slot, ScriptCtx *ctx);
int func_0014B9E0(int arg, Actor *a, void *slot);
void func_0014B920(int arg, Actor *a, void *slot, ScriptCtx *ctx);
int _vm_func_001406F0(u8 op, Actor *a, void *r, ScriptCtx *ctx, int running) __asm__("func_001406F0");
int _vm_func_00140878(u8 op, Actor *a, void *r, ScriptCtx *ctx, int running) __asm__("func_00140878");

int func_00140B48(Actor *a, int mode, int cbFlag)
{
    ActorVM *av = (ActorVM *)a;
    ActorBindVM *bind;
    ScriptCtx *ctx;
    int running;
    int advance;
    int savedOp;
    int flag10;
    int ret;
    int steps;
    u32 op;
    u32 arg;
    int res;
    int b;
    u16 *slot;

    if (!(a->flags34.w & 2)) {
        return 0;
    }
    if (!(a->flags34.w & 4)) {
        if (!(a->flags34.w & 0x400000)) {
            if (MsBattleCheck()) {
                return 0;
            }
        }
    }
    {
        u8 st = ((u8 *)D_0058E3D8)[3] & 3;
        if (st == 1 || (st == 2 && (s32)a->flags34.w >= 0)) {
            return 0;
        }
    }

    ctx = &av->ctxC4;
    bind = (ActorBindVM *)func_0013C9C8(a, av->slotIdx);
    {
        float acc = av->f98;
        acc += func_0013D818(a);
        if (func_0013D818(a) >= 1.0f) {
            acc -= 1.0f;
            running = 1;
        } else {
            running = 0;
        }
        ret = 0;
        av->f98 = acc;
        if (acc >= 1.0f) {
            ret = 1;
        }
    }
    flag10 = 1;
    savedOp = -1;
    if (cbFlag) {
        ((Sys3D8VM *)D_0058E3D8)->f58(a, (ActorBind *)bind);
    }

check_wait:
    switch (bind->b1F) {
    case 2:
        if (func_00142748(bind->h2E, bind->h2C) != 0) {
            goto done;
        }
        bind->b1F = 0;
        goto check_wait;
    case 1: {
        void *node = func_0013D7A8(a, (u8 *)bind);
        if (node == 0) {
            goto done;
        }
        AtelDeleteSignal(av->id, node);
        bind->b1F = 0;
        break;
    }
    case 0:
        break;
    default:
        goto done;
    }

    a->flags34.w = (a->flags34.w & ~0x1C00) | 0x400;
    __asm__ volatile("");
    steps = 1;
    while (1) {
        if (steps > 0x10000) {
            running = 0;
            a->flags34.w = (a->flags34.w & ~0x1C00) | 0x1400;
            func_0013AB38(a, 6);
        }
        if (mode == 1) {
            if (!running) {
                if (func_0013D790((int *)ctx)) {
                    flag10 = 0;
                }
                break;
            }
        } else {
            if (!running && !func_0013D790((int *)ctx)) {
                break;
            }
        }

        op = func_0013CD18(a, (ActorBind *)bind);
        advance = 1;
        flag10 = 1;
        steps++;
        arg = op & 0xFFFFFF;
        __asm__("" : "+r"(arg));
        op >>= 24;

    dispatch:
    switch (op) {
    case 0x40: {
        Ent3D8 *e = ((Sys3D8VM *)D_0058E3D8)->ent;
        int i;
        a->flags34.w &= ~0x1C00;
        advance = 0;
        running = 0;
        for (i = 0; i < 4; i++, e++) {
            char *pc = func_0013CBF8(a, (ActorBind *)bind);
            savedOp = e->bE;
            if (e->w0 >= 0 && (char *)e->w8 == pc) {
                if (e->bF != 0 || mode == 1) {
                    int raw;
                    int flg;
                    e->bF = 0;
                    advance = 1;
                    running = 1;
                    raw = savedOp;
                    flg = func_0013CCA0((u8)raw);
                    arg = func_0013CCA8(flg, (u8 *)func_0013CBF8(a, (ActorBind *)bind)) & 0xFFFFFF;
                    op = raw & 0xFFFFFF7Fu;
                    op = (u8)op;
                    goto dispatch;
                } else {
                    e->bF = 1;
                    ret |= 0x8000;
                    mode = 1;
                    break;
                }
            }
        }
        break;
    }
    case 0x01: {
        int x;
        b = AtelPopStackInteger(a, ctx);
        x = AtelPopStackInteger(a, ctx);
        res = x;
        if (res != 0 || b != 0) {
            res = 1;
        }
        AtelPushStackInteger(a, ctx, res);
        break;
    }
    case 0x02:
        b = AtelPopStackInteger(a, ctx);
        if (AtelPopStackInteger(a, ctx) == 0 || b == 0) {
            res = 0;
        } else {
            res = 1;
        }
        AtelPushStackInteger(a, ctx, res);
        break;
    case 0x05: {
        int x;
        b = AtelPopStackInteger(a, ctx);
        x = AtelPopStackInteger(a, ctx);
        AtelPushStackInteger(a, ctx, x & b);
        break;
    }
    case 0x03: {
        int x;
        b = AtelPopStackInteger(a, ctx);
        x = AtelPopStackInteger(a, ctx);
        AtelPushStackInteger(a, ctx, x | b);
        break;
    }
    case 0x04: {
        int x;
        b = AtelPopStackInteger(a, ctx);
        x = AtelPopStackInteger(a, ctx);
        AtelPushStackInteger(a, ctx, x ^ b);
        break;
    }
    case 0x06:
    case 0x07: {
        res = 0;
        if (func_0013CE70(a, ctx)) {
            int x;
            b = AtelPopStackInteger(a, ctx);
            x = AtelPopStackInteger(a, ctx);
            res = (x == b);
        } else {
            float bf = AtelPopStackFloat(a, ctx);
            float xf = AtelPopStackFloat(a, ctx);
            if (bf == xf) {
                res = 1;
            }
        }
        if (op == 7) {
            res = !res;
        }
        AtelPushStackInteger(a, ctx, res);
        break;
    }
    case 0x08:
    case 0x0D: {
        res = 0;
        if (func_0013CE70(a, ctx)) {
            u32 y = AtelPopStackInteger(a, ctx);
            u32 x = AtelPopStackInteger(a, ctx);
            res = (y < x);
        } else {
            float bf = AtelPopStackFloat(a, ctx);
            float xf = AtelPopStackFloat(a, ctx);
            if (bf < xf) {
                res = 1;
            }
        }
        if (op == 0x0D) {
            res = !res;
        }
        AtelPushStackInteger(a, ctx, res);
        break;
    }
    case 0x09:
    case 0x0C: {
        res = 0;
        if (func_0013CE70(a, ctx)) {
            u32 y = AtelPopStackInteger(a, ctx);
            u32 x = AtelPopStackInteger(a, ctx);
            res = (y <= x);
        } else {
            float bf = AtelPopStackFloat(a, ctx);
            float xf = AtelPopStackFloat(a, ctx);
            if (bf <= xf) {
                res = 1;
            }
        }
        if (op == 0x09) {
            res = !res;
        }
        AtelPushStackInteger(a, ctx, res);
        break;
    }
    case 0x0A:
    case 0x0F: {
        res = 0;
        if (func_0013CE70(a, ctx)) {
            int x;
            b = AtelPopStackInteger(a, ctx);
            x = AtelPopStackInteger(a, ctx);
            res = (b < x);
        } else {
            float bf = AtelPopStackFloat(a, ctx);
            float xf = AtelPopStackFloat(a, ctx);
            if (bf < xf) {
                res = 1;
            }
        }
        if (op == 0x0F) {
            res = !res;
        }
        AtelPushStackInteger(a, ctx, res);
        break;
    }
    case 0x0B:
    case 0x0E: {
        res = 0;
        if (func_0013CE70(a, ctx)) {
            int x;
            b = AtelPopStackInteger(a, ctx);
            x = AtelPopStackInteger(a, ctx);
            res = (b <= x);
        } else {
            float bf = AtelPopStackFloat(a, ctx);
            float xf = AtelPopStackFloat(a, ctx);
            if (bf <= xf) {
                res = 1;
            }
        }
        if (op == 0x0B) {
            res = !res;
        }
        AtelPushStackInteger(a, ctx, res);
        break;
    }
    case 0x10: {
        int x;
        b = AtelPopStackInteger(a, ctx);
        x = AtelPopStackInteger(a, ctx);
        AtelPushStackInteger(a, ctx, (x >> b) & 1);
        break;
    }
    case 0x11: {
        int x;
        b = AtelPopStackInteger(a, ctx);
        x = AtelPopStackInteger(a, ctx);
        AtelPushStackInteger(a, ctx, ((x >> b) & 1) ^ 1);
        break;
    }
    case 0x12: {
        int x;
        b = AtelPopStackInteger(a, ctx);
        x = AtelPopStackInteger(a, ctx);
        AtelPushStackInteger(a, ctx, x << b);
        break;
    }
    case 0x13: {
        int x;
        b = AtelPopStackInteger(a, ctx);
        x = AtelPopStackInteger(a, ctx);
        AtelPushStackInteger(a, ctx, x >> b);
        break;
    }
    case 0x14:
        if (func_0013CE70(a, ctx)) {
            int x;
            b = AtelPopStackInteger(a, ctx);
            x = AtelPopStackInteger(a, ctx);
            AtelPushStackInteger(a, ctx, x + b);
        } else {
            float bf = AtelPopStackFloat(a, ctx);
            float xf = AtelPopStackFloat(a, ctx);
            func_0013CE10(a, ctx, xf + bf);
        }
        break;
    case 0x15:
        if (func_0013CE70(a, ctx)) {
            int x;
            b = AtelPopStackInteger(a, ctx);
            x = AtelPopStackInteger(a, ctx);
            AtelPushStackInteger(a, ctx, x - b);
        } else {
            float bf = AtelPopStackFloat(a, ctx);
            float xf = AtelPopStackFloat(a, ctx);
            func_0013CE10(a, ctx, xf - bf);
        }
        break;
    case 0x16:
        if (func_0013CE70(a, ctx)) {
            int x;
            b = AtelPopStackInteger(a, ctx);
            x = AtelPopStackInteger(a, ctx);
            AtelPushStackInteger(a, ctx, x * b);
        } else {
            float bf = AtelPopStackFloat(a, ctx);
            float xf = AtelPopStackFloat(a, ctx);
            func_0013CE10(a, ctx, xf * bf);
        }
        break;
    case 0x17:
        if (func_0013CE70(a, ctx)) {
            int x;
            b = AtelPopStackInteger(a, ctx);
            x = AtelPopStackInteger(a, ctx);
            AtelPushStackInteger(a, ctx, x / b);
        } else {
            float bf = AtelPopStackFloat(a, ctx);
            float xf = AtelPopStackFloat(a, ctx);
            func_0013CE10(a, ctx, xf / bf);
        }
        break;
    case 0x18: {
        int x;
        b = AtelPopStackInteger(a, ctx);
        x = AtelPopStackInteger(a, ctx);
        AtelPushStackInteger(a, ctx, x % b);
        break;
    }
    case 0x19:
        res = AtelPopStackInteger(a, ctx);
        if (res != 0) {
            res = 0;
        } else {
            res = 1;
        }
        AtelPushStackInteger(a, ctx, res);
        break;
    case 0x1C: {
        int x = AtelPopStackInteger(a, ctx);
        AtelPushStackInteger(a, ctx, ~x);
        break;
    }
    case 0x1A: {
        float xf = AtelPopStackFloat(a, ctx);
        func_0013CE10(a, ctx, -xf);
        break;
    }
    case 0x22:
        func_0013D688(a, ctx, arg);
        break;
    case 0x27:
        func_0013D6D8(a, ctx, arg);
        break;
    case 0x23: {
        u32 v = func_0013CC80(a, arg);
        u32 kind = v >> 28;
        func_0013CC40(a, arg);
        AtelGetRealVarAdrs(a, v);
        if (kind != 6) {
            int val = AtelPopStackInteger(a, ctx);
            int idx = AtelPopStackInteger(a, ctx);
            func_0013D1C0(a, arg, idx, val, 0);
        } else {
            float f = AtelPopStackFloat(a, ctx);
            int idx = AtelPopStackInteger(a, ctx);
            func_0013D2E8(a, arg, idx, 0, f);
        }
        break;
    }
    case 0x24: {
        u32 v = func_0013CC80(a, arg);
        u32 kind = v >> 28;
        func_0013CC40(a, arg);
        AtelGetRealVarAdrs(a, v);
        if (kind != 6) {
            int val = AtelPopStackInteger(a, ctx);
            int idx = AtelPopStackInteger(a, ctx);
            func_0013D1C0(a, arg, idx, val, 1);
        } else {
            float f = AtelPopStackFloat(a, ctx);
            int idx = AtelPopStackInteger(a, ctx);
            func_0013D2E8(a, arg, idx, 1, f);
        }
        break;
    }
    case 0x1F:
        func_0013D680(a, ctx, arg);
        break;
    case 0x20: {
        u32 v = func_0013CC80(a, arg);
        u32 kind = v >> 28;
        func_0013CC40(a, arg);
        AtelGetRealVarAdrs(a, v);
        if (kind != 6) {
            int val = AtelPopStackInteger(a, ctx);
            func_0013D1C0(a, arg, 0, val, 0);
        } else {
            float f = AtelPopStackFloat(a, ctx);
            func_0013D2E8(a, arg, 0, 0, f);
        }
        break;
    }
    case 0x21: {
        u32 v = func_0013CC80(a, arg);
        u32 kind = v >> 28;
        func_0013CC40(a, arg);
        AtelGetRealVarAdrs(a, v);
        if (kind != 6) {
            int val = AtelPopStackInteger(a, ctx);
            func_0013D1C0(a, arg, 0, val, 1);
        } else {
            float f = AtelPopStackFloat(a, ctx);
            func_0013D2E8(a, arg, 0, 1, f);
        }
        break;
    }
    case 0x26:
        func_0013CE10(a, ctx, bind->f28);
        break;
    case 0x67:
    case 0x68:
    case 0x69:
    case 0x6A:
        AtelPushStackInteger(a, ctx, av->w48[op - 0x67]);
        break;
    case 0x6B:
    case 0x6C:
    case 0x6D:
    case 0x6E:
    case 0x6F:
    case 0x70:
    case 0x71:
    case 0x72:
    case 0x73:
    case 0x74:
        func_0013CE10(a, ctx, av->f58[op - 0x6B]);
        break;
    case 0x59:
    case 0x5A:
    case 0x5B:
    case 0x5C:
        av->w48[op - 0x59] = AtelPopStackInteger(a, ctx);
        break;
    case 0x5D:
    case 0x5E:
    case 0x5F:
    case 0x60:
    case 0x61:
    case 0x62:
    case 0x63:
    case 0x64:
    case 0x65:
    case 0x66:
        av->f58[op - 0x5D] = AtelPopStackFloat(a, ctx);
        break;
    case 0x75:
        AtelPushStackInteger(a, ctx, D_0030B8C8[arg]);
        break;
    case 0x28:
        AtelPushStackInteger(a, ctx, bind->w20);
        break;
    case 0x29:
        AtelPushStackInteger(a, ctx, bind->w24);
        break;
    case 0x2A:
        bind->w20 = AtelPopStackInteger(a, ctx);
        break;
    case 0x2C:
        bind->w24 = AtelPopStackInteger(a, ctx);
        break;
    case 0x2B:
        AtelPushStackInteger(a, ctx, func_0013CF40(a, ctx));
        break;
    case 0x2D:
        AtelPushStackInteger(a, ctx, ((int *)((u8 *)av->blob + *(int *)((u8 *)av->hdr + 0x18)))[arg]);
        break;
    case 0x2E:
        AtelPushStackInteger(a, ctx, (s16)arg);
        break;
    case 0x2F:
        func_0013CE10(a, ctx, ((float *)((u8 *)av->blob + *(int *)((u8 *)av->hdr + 0x1C)))[arg]);
        break;
    case 0x55:
        bind->w20 = AtelPopStackInteger(a, ctx);
        goto do_jump;
    case 0x56:
        bind->w20 = AtelPopStackInteger(a, ctx);
    case 0x31:
        res = bind->w20;
        if (res == 0) {
            break;
        }
        goto do_jump;
    case 0x57:
        bind->w20 = AtelPopStackInteger(a, ctx);
    case 0x32:
        res = bind->w20;
        if (res != 0) {
            break;
        }
    case 0x30:
    do_jump:
        advance = 0;
        func_0013CB60(a, (ActorBind *)bind, arg);
        break;
    case 0x33: {
        int depth = bind->b1D;
        if (depth >= 3) {
            func_0013AB38(a, 4);
        } else {
            int off = func_0013CB48(a, (ActorBind *)bind) + 3;
            advance = 0;
            bind->w00[depth] = off;
            bind->h10[depth] = arg;
            depth++;
            bind->b1D = depth;
            func_0013CAD0(a, (ActorBind *)bind, func_0013CA30(AtelGetBasicWork(arg), 0));
        }
        break;
    }
    case 0x34: {
        int depth = bind->b1D;
        if (depth <= 0) {
            func_0013AB38(a, 5);
        } else {
            depth--;
            advance = 0;
            func_0013CAD0(a, (ActorBind *)bind, bind->w00[depth]);
            bind->b1D = depth;
        }
        break;
    }
    case 0x35:
    case 0x58: {
        register int one __asm__("$4") = 1;
        u8 st;
        int r;
        __asm__("" : "+r"(one));
        a->flags34.w = (a->flags34.w & ~0x1C00) | 0x400;
        advance = 0;
        running = 0;
        st = bind->b1E;
        if (st == 0) {
            goto ext_0;
        }
        if (st == one) {
            goto ext_1;
        }
        break;
    ext_0:
        slot = &bind->h2C;
        __asm__("" : "+r"(slot));
        bind->b1E = one;
        func_0014BA30(arg, a, slot, ctx);
        goto ext_poll;
    ext_1:
        slot = &bind->h2C;
    ext_poll:
        {
            register int r4 __asm__("$4") = func_0014B9E0(arg, a, slot);
            __asm__("" : "+r"(r4));
            r = r4;
        }
        if (r & 2) {
            flag10 = 0;
        }
        if (r & 4) {
            running = 1;
        } else {
            running = 0;
        }
        {
            register int r1 __asm__("$2") = r & 1;
            if (r1) {
                func_0014B920(arg, a, slot, ctx);
                advance = 1;
                bind->b1E = 0;
                if (op == 0x58) {
                    goto case_25;
                }
            }
        }
        break;
    }
    case 0x25:
    case_25:
        bind->f28 = AtelPopStackFloat(a, ctx);
        break;
    case 0x39: {
        int x = AtelPopStackInteger(a, ctx);
        int y = AtelPopStackInteger(a, ctx);
        int z = AtelPopStackInteger(a, ctx);
        res = func_0013B008(y);
        if (x != 0 && res >= 0) {
            res = func_001425E0(av->id, res, 0, z, x);
        } else {
            res = 0;
        }
        AtelPushStackInteger(a, ctx, res);
        break;
    }
    case 0x36:
    case 0x45:
    case 0x46:
    case 0x47:
    case 0x48:
    case 0x49:
        func_00140A00(op, bind, a, ctx);
        break;
    case 0x3A: {
        int x, z, id, r;
        x = AtelPopStackInteger(a, ctx);
        b = AtelPopStackInteger(a, ctx);
        z = AtelPopStackInteger(a, ctx);
        id = func_0013B008(b);
        if (x != 0 && id >= 0) {
            r = func_001425E0(av->id, id, 1, z, x);
        } else {
            r = 0;
        }
        AtelPushStackInteger(a, ctx, r);
        if (r != 0) {
            slot = &bind->h2C;
            slot[0] = x;
            slot[1] = id;
            slot[2] = z;
            bind->b1F = 1;
        }
        running = 0;
        a->flags34.w = (a->flags34.w & ~0x1C00) | 0x800;
        break;
    }
    case 0x37:
    case 0x4A:
    case 0x4B:
    case 0x4C:
    case 0x4D:
    case 0x4E:
        running = _vm_func_001406F0(op, a, bind, ctx, running);
        a->flags34.w = (a->flags34.w & ~0x1C00) | 0x800;
        break;
    case 0x3B: {
        int x, z, id, r;
        x = AtelPopStackInteger(a, ctx);
        b = AtelPopStackInteger(a, ctx);
        z = AtelPopStackInteger(a, ctx);
        id = func_0013B008(b);
        if (x != 0 && id >= 0) {
            r = func_001425E0(av->id, id, 2, z, x);
        } else {
            r = 0;
        }
        AtelPushStackInteger(a, ctx, r);
        if (r != 0) {
            slot = &bind->h2C;
            slot[0] = x;
            slot[1] = id;
            slot[2] = z;
            bind->b1F = 1;
        }
        running = 0;
        a->flags34.w = (a->flags34.w & ~0x1C00) | 0x800;
        break;
    }
    case 0x38:
    case 0x4F:
    case 0x50:
    case 0x51:
    case 0x52:
    case 0x53:
        running = _vm_func_00140878(op, a, bind, ctx, running);
        a->flags34.w = (a->flags34.w & ~0x1C00) | 0x800;
        break;
    case 0x78: {
        int x = AtelPopStackInteger(a, ctx);
        int y = AtelPopStackInteger(a, ctx);
        int id = func_0013B008(y);
        if (func_00142748(id, x) != 0 && id >= 0) {
            bind->h2E = id;
            bind->h2C = x;
            running = 0;
            a->flags34.w = (a->flags34.w & ~0x1C00) | 0x400;
            bind->b1F = 2;
        }
        break;
    }
    case 0x77: {
        int x = AtelPopStackInteger(a, ctx);
        int id = AtelPopStackInteger(a, ctx);
        if (func_00142748(id, x) != 0) {
            bind->h2E = id;
            bind->h2C = x;
            running = 0;
            a->flags34.w = (a->flags34.w & ~0x1C00) | 0x400;
            bind->b1F = 2;
        }
        break;
    }
    case 0x79: {
        int z = AtelPopStackInteger(a, ctx);
        int y = AtelPopStackInteger(a, ctx);
        int x = AtelPopStackInteger(a, ctx);
        func_0013A3B8(a, x, y, z);
        break;
    }
    case 0x7A: {
        int y = AtelPopStackInteger(a, ctx);
        int x = AtelPopStackInteger(a, ctx);
        AtelPushStackInteger(a, ctx, func_00143FB8(a, x, y));
        break;
    }
    case 0x54:
        a->flags34.w = (a->flags34.w & ~0x1C00) | 0x1000;
        running = 0;
        advance = 0;
        AtelExecReturn(av->id, 0, 0);
        break;
    case 0x3C:
        a->flags34.w = (a->flags34.w & ~0x1C00) | 0xC00;
        advance = 0;
        running = 0;
        if (((Sys3D8VM *)D_0058E3D8)->f28 != 0) {
            ((Sys3D8VM *)D_0058E3D8)->f28(av->id, op);
        } else {
            AtelExecReturn(av->id, -1, 0);
        }
        break;
    case 0x3D: {
        int v;
        a->flags34.w = (a->flags34.w & ~0x1C00) | 0xC00;
        advance = 0;
        running = 0;
        v = AtelPopStackInteger(a, ctx);
        AtelExecReturn(av->id, v, 0);
        break;
    }
    case 0x3E:
        a->flags34.w = (a->flags34.w & ~0x1C00) | 0xC00;
        advance = 0;
        running = 0;
        if (((Sys3D8VM *)D_0058E3D8)->f28 != 0) {
            ((Sys3D8VM *)D_0058E3D8)->f28(av->id, op);
        } else {
            AtelExecReturn(av->id, -1, 1);
        }
        break;
    case 0x3F: {
        int v;
        a->flags34.w = (a->flags34.w & ~0x1C00) | 0xC00;
        advance = 0;
        running = 0;
        v = AtelPopStackInteger(a, ctx);
        AtelExecReturn(av->id, v, 1);
        break;
    }
    case 0x00:
    case 0x1D:
    case 0x1E:
    case 0x76:
        break;
    default:
        func_0013AB38(a, 7);
        advance = 0;
        break;
    }

        if (advance) {
            func_0013CD40(a, (ActorBind *)bind, savedOp);
        }
        savedOp = -1;
        if (mode == 1) {
            if (running) {
                ret |= 0x4000;
            }
            running = 0;
            ret &= 0xC000;
        }
    }

done:
    bind = (ActorBindVM *)func_0013C9C8(a, av->slotIdx);
    if (cbFlag) {
        ((Sys3D8VM *)D_0058E3D8)->f5C(a, (ActorBind *)bind);
    }
    a->flags34.w = (a->flags34.w & ~8) | ((flag10 & 1) << 3);
    return ret;
}

