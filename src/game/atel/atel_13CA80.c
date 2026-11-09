/* tu_074 0x13ca80-0x141ff0: low; ~Atel (config/tu_map.tsv) */
#include "common.h"
#include "ffx/q1.h"
#include "ffx/r0.h"
#include "ffx/u0.h"
#include "ffx/s0.h"
#include "ffx/v1.h"

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

INCLUDE_ASM("build/ee_asm/game/atel/atel_13CA80", AtelPopStackFloat);

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

INCLUDE_ASM("build/ee_asm/game/atel/atel_13CA80", func_0013DB38);
INCLUDE_RODATA("build/ee_asm/game/atel/atel_13CA80/rodata", jtbl_0056A930);

INCLUDE_ASM("build/ee_asm/game/atel/atel_13CA80", func_0013E150);
INCLUDE_RODATA("build/ee_asm/game/atel/atel_13CA80/rodata", jtbl_0056A960);

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

INCLUDE_ASM("build/ee_asm/game/atel/atel_13CA80", func_0013E9B8);

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

INCLUDE_ASM("build/ee_asm/game/atel/atel_13CA80", func_0013EF90);

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

INCLUDE_ASM("build/ee_asm/game/atel/atel_13CA80", func_0013F288);

INCLUDE_ASM("build/ee_asm/game/atel/atel_13CA80", func_0013F6D8);

INCLUDE_ASM("build/ee_asm/game/atel/atel_13CA80", func_0013FB40);

INCLUDE_ASM("build/ee_asm/game/atel/atel_13CA80", func_00140038);

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

INCLUDE_ASM("build/ee_asm/game/atel/atel_13CA80", func_00140B48);
INCLUDE_RODATA("build/ee_asm/game/atel/atel_13CA80/rodata", jtbl_0056AB10);
