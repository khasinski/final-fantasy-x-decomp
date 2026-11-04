/* tu_310 0x28b480-0x28d740: low; ~ppp (config/tu_map.tsv) */
/* Module guess: event-script VM / field-event runtime (no __FILE__ string found for this range). */
#include "common.h"
#include "ffx/w9.h"
#include "ffx/q6.h"
#include "ffx/t6.h"
#include "ffx/r6.h" /* needed by t6.h (R6Fvec) */
#include "ffx/u4.h"
#include "ffx/v6.h"

void pppKeLnsLpDraw(ScriptWork *base, void *p, ScriptCtx *ctx)
{
    T6_SWorkB480 *hdr = (T6_SWorkB480 *)base; /* DEBT(CAST): ScriptWork only describes the owner word */
    T6_MsgB480 *msg = p;
    T6_WkB480 *w = SLOT_WORK(T6_WkB480, base, ctx, 0);
    float v[4];
    T6_ReqB480 req;

    if (msg->id == base->owner) {
        w->fA8 += msg->f8;
        w->b8E = msg->bC;
        w->f9C += msg->f4;
        w->b8F = msg->bD;
    }
    if (w->b8F != 0) {
        *(u_long128 *)v = 0; /* DEBT(CAST): vector cleared with one quadword store */
        v[2] = 1.0f;
        v[3] = 1.0f;
        func_002DCE08(v, hdr->m10, v);
        func_00282798(w->m90, v);
    }
    w->f80 = hdr->f40;
    w->f84 = hdr->f44;
    w->f88 = hdr->f48;
    req.pos = &hdr->f40;
    req.a = D_006A39B0;
    req.b = D_006A3A70;
    req.self = w;
    KeLnsLp_Update(&req);
}

void func_0028B578(char *base, ScriptCtx *ctx) {
    Wk9CA8 *w = SLOT_WORK(Wk9CA8, base, ctx, 0);

    func_0027F928(w);
    w->w9C = 0;
    w->wA8 = 0;
}

void func_0028B5B8(char *base, ScriptCtx *ctx) {
    Wkw9CwA8 *w = SLOT_WORK(Wkw9CwA8, base, ctx, 0);

    w->w9C = 0;
    w->wA8 = 0;
}

void func_0028B5D8(ScriptWork *base, ScriptMsg *msg, ScriptCtx *ctx) {
    AttachWork *w = SLOT_WORK(AttachWork, base, ctx, 0);
    DataRef **p;

    if (msg->id == base->owner) {
        w->ref = (char *)base + (ctx->info->slot[1] + 0xA0);
        if (msg->idx == 0xFFFF) {
            w->cur = 0;
        } else {
            p = D_006A3924->tbl + msg->idx;
            if (p != w->cur) {
                w->cur = p;
                w->h8 = (*p)->h12;
                w->a.b = 0;
            }
        }
    }
}

void func_0028B658(ScriptWork *base, T6_ColMsg *msg, ScriptCtx *ctx)
{
    T6_ColMgr *mgr = ppvMng;
    T6_ColReq req;

    func_0028B5D8(base, (ScriptMsg *)msg, ctx); /* DEBT(CAST): shared handler takes the base message type */
    req.col[0] = (msg->col[0] * ppvMng->scale[0]) >> 12;
    req.col[1] = (msg->col[1] * ppvMng->scale[1]) >> 12;
    req.col[2] = (msg->col[2] * ppvMng->scale[2]) >> 12;
    req.col[3] = (msg->col[3] * ppvMng->scale[3]) >> 12;
    req.tbl = D_006A3A70;
    req.fC = msg->fC;
    req.sub = mgr->m60;
    req.self = SLOT_WORK(void, base, ctx, 0);
    func_0027FD60((R6Req5 *)&req, 0); /* DEBT(CAST): see T6_ColReq */
}

void func_0028B740(char *base, ScriptCtx *ctx) {
    func_0027FF00(base + (ctx->info->slot[0] + 0xA0));
}

void func_0028B758(ScriptWork *base, AttachMsg *msg, ScriptCtx *ctx) {
    AttachWork *w = SLOT_WORK(AttachWork, base, ctx, 0);
    DataRef **p;

    if (msg->id == base->owner) {
        w->ref = (char *)base + (ctx->info->slot[1] + 0xA0);
        if (msg->idx == 0xFFFF) {
            w->cur = 0;
        } else {
            p = D_006A3924->tbl + msg->idx;
            if (p != w->cur) {
                func_0027FC48(w, p, msg->b16);
            }
        }
        w->a.h = msg->h12;
        w->hC = msg->h10;
        w->bE = msg->b17;
    }
}

void func_0028B808(ScriptWork *base, T6_ColMsg *msg, ScriptCtx *ctx)
{
    T6_ColMgr *mgr = ppvMng;
    T6_ColReq6 req;

    func_0028B758(base, (AttachMsg *)msg, ctx); /* DEBT(CAST): shared handler takes the base message type */
    req.col[0] = (msg->col[0] * ppvMng->scale[0]) >> 12;
    req.col[1] = (msg->col[1] * ppvMng->scale[1]) >> 12;
    req.col[2] = (msg->col[2] * ppvMng->scale[2]) >> 12;
    req.col[3] = (msg->col[3] * ppvMng->scale[3]) >> 12;
    req.fC = msg->fC;
    req.f10 = msg->h14;
    req.tbl = D_006A3A70;
    req.sub = mgr->m60;
    req.self = SLOT_WORK(void, base, ctx, 0);
    func_0027F960((R6Req6 *)&req, 0);
}

void func_0028B900(char *base, ScriptCtx *ctx) {
    Wkb8 *w = SLOT_WORK(Wkb8, base, ctx, 0);

    func_0027FD48(w);
    w->b8 = 4;
}

void func_0028B940(ScriptWork *base, ScriptMsg *msg, ScriptCtx *ctx) {
    AttachWork *w = SLOT_WORK(AttachWork, base, ctx, 0);
    DataRef **p;

    if (msg->id == base->owner) {
        w->ref = (char *)base + (ctx->info->slot[1] + 0xA0);
        if (msg->idx == 0xFFFF) {
            w->cur = 0;
        } else {
            p = D_006A3924->tbl + msg->idx;
            if (p != w->cur) {
                func_00280150(w, p);
            }
        }
    }
}

void func_0028B9B8(ScriptWork *base, T6_ColMsg *msg, ScriptCtx *ctx)
{
    T6_ColMgr *mgr = ppvMng;
    T6_ColReqH req;

    func_0028B940(base, (ScriptMsg *)msg, ctx); /* DEBT(CAST): shared handler takes the base message type */
    req.col[0] = (msg->col[0] * ppvMng->scale[0]) >> 12;
    req.col[1] = (msg->col[1] * ppvMng->scale[1]) >> 12;
    req.col[2] = (msg->col[2] * ppvMng->scale[2]) >> 12;
    req.col[3] = (msg->col[3] * ppvMng->scale[3]) >> 12;
    req.h10 = msg->h10;
    req.h12 = msg->h12;
    req.fC = msg->fC;
    req.tbl = D_006A3A70;
    req.sub = mgr->m60;
    req.self = SLOT_WORK(void, base, ctx, 0);
    func_0027FF18(&req, 0);
}

void func_0028BAB0(char *base, ScriptCtx *ctx) {
    func_00280168(base + (ctx->info->slot[0] + 0xA0));
}

void func_0028BAC8(ScriptWork *base, ScriptMsg *msg, ScriptCtx *ctx) {
    AttachWork *w = SLOT_WORK(AttachWork, base, ctx, 0);
    DataRef **p;

    if (msg->id == base->owner) {
        w->ref = (char *)base + (ctx->info->slot[1] + 0xA0);
        if (msg->idx == 0xFFFF) {
            w->cur = 0;
        } else {
            p = D_006A3924->tbl + msg->idx;
            if (p != w->cur) {
                w->cur = p;
                w->h8 = (*p)->h12;
                w->a.b = 0;
            }
        }
    }
}

void func_0028BB48(ScriptWork *base, T6_ColMsg *msg, ScriptCtx *ctx)
{
    T6_ColMgr *mgr = ppvMng;
    T6_ColReqH req;

    func_0028BAC8(base, (ScriptMsg *)msg, ctx); /* DEBT(CAST): shared handler takes the base message type */
    req.col[0] = (msg->col[0] * ppvMng->scale[0]) >> 12;
    req.col[1] = (msg->col[1] * ppvMng->scale[1]) >> 12;
    req.col[2] = (msg->col[2] * ppvMng->scale[2]) >> 12;
    req.col[3] = (msg->col[3] * ppvMng->scale[3]) >> 12;
    req.fC = msg->fC;
    req.tbl = D_006A3A70;
    req.h10 = msg->h10;
    req.h12 = msg->h12;
    req.sub = mgr->m60;
    req.self = SLOT_WORK(void, base, ctx, 0);
    func_00280180(&req, 0);
}

void func_0028BC40(char *base, ScriptCtx *ctx) {
    func_002803A8(base + (ctx->info->slot[0] + 0xA0));
}

void pppKeLnsLpTDraw(ScriptWork *base, T6_MsgBC58 *msg, ScriptCtx *ctx)
{
    T6_WkBC58 *w;
    float v[4];

    pppKeLnsLpDraw(base, msg, ctx);
    w = SLOT_WORK(T6_WkBC58, base, ctx, 0);
    if (msg->id == base->owner) {
        w->bD0 = msg->bE << 3;
        w->bD1 = msg->bF << 2;
        w->b8D = msg->b10;
    }
    v[0] = 0.0f;
    v[1] = 0.0f;
    v[2] = 0.0f;
    v[3] = 1.0f;
    func_002DCE08(v, (char *)base + 0x50, v); /* DEBT(CAST): matrix inside the script memory header */
    func_002DD068(w->mC0, v, 1.0f / v[3]);
    w->hCC = D_0036F1F0.hE;
}

INCLUDE_ASM("build/ee_asm/game/particle/eiProg/ppp_28B480", func_0028BD28);

void func_0028C150(char *base, ScriptCtx *ctx) {
    WkB0 *w = SLOT_WORK(WkB0, base, ctx, 0);

    func_0027F928(w);
    w->w9C = 0;
    w->wA8 = 0;
    w->b8C = D_003730E4;
    w->bD0 = 0;
    w->bD1 = 0;
    w->b8D = 2;
    func_00266EB8(&D_0036F1F0, w->sub, func_0028BD28, w);
    w->hCC = ~D_0036F1F0.hE;
    D_003730E4++;
}

void func_0028C1F0(char *base, ScriptCtx *ctx) {
    Wkw9CwA8 *w = SLOT_WORK(Wkw9CwA8, base, ctx, 0);

    w->w9C = 0;
    w->wA8 = 0;
}

void func_0028C210(char *base, ScriptCtx *ctx) {
    func_00266EE8(&D_0036F1F0, SLOT_WORK(WkSubB0, base, ctx, 0)->sub);
}

void func_0028C230(ScriptWork *base, T6_ColMsg *msg, ScriptCtx *ctx)
{
    T6_ColMgr *mgr = ppvMng;
    T6_WkCol30 *w = SLOT_WORK(T6_WkCol30, base, ctx, 0);

    func_0028B5D8(base, (ScriptMsg *)msg, ctx); /* DEBT(CAST): shared handler takes the base message type */
    if (msg->id == base->owner) {
        w->f30 = msg->fC;
    }
    w->col[0] = (msg->col[0] * ppvMng->scale[0]) >> 12;
    w->col[1] = (msg->col[1] * ppvMng->scale[1]) >> 12;
    w->col[2] = (msg->col[2] * ppvMng->scale[2]) >> 12;
    w->col[3] = (msg->col[3] * ppvMng->scale[3]) >> 12;
    func_002DD0B0(w->m10, mgr->m60);
}

void func_0028C310(void *p) {
    R6EmitA *o = p;
    R6Req5 req;

    req.self = o;
    req.w4 = o->w34;
    req.fC = o->f30;
    req.tbl = D_006A3A70;
    req.sub = o->sub;
    func_0027FD60(&req, 4);
}

void func_0028C360(char *base, ScriptCtx *ctx) {
    WkSub20 *w = SLOT_WORK(WkSub20, base, ctx, 0);

    func_0027FF00(w);
    func_00266EB8(&D_0036F1F0, w->sub, func_0028C310, w);
}

void func_0028C3B0(char *base, ScriptCtx *ctx) {
    func_00266EE8(&D_0036F1F0, SLOT_WORK(WkSub20, base, ctx, 0)->sub);
}

void func_0028C3D0(ScriptWork *base, T6_ColMsg *msg, ScriptCtx *ctx)
{
    T6_ColMgr *mgr = ppvMng;
    T6_WkCol50 *w = SLOT_WORK(T6_WkCol50, base, ctx, 0);

    func_0028B758(base, (AttachMsg *)msg, ctx); /* DEBT(CAST): shared handler takes the base message type */
    if (msg->id == base->owner) {
        w->f54 = msg->fC;
        w->f50 = msg->h14;
    }
    w->col[0] = (msg->col[0] * ppvMng->scale[0]) >> 12;
    w->col[1] = (msg->col[1] * ppvMng->scale[1]) >> 12;
    w->col[2] = (msg->col[2] * ppvMng->scale[2]) >> 12;
    w->col[3] = (msg->col[3] * ppvMng->scale[3]) >> 12;
    func_002DD0B0(w->m30, mgr->m60);
}

void func_0028C4C0(void *p) {
    R6EmitB *o = p;
    R6Req6 req;

    req.self = o;
    req.f10 = o->f50;
    req.w4 = o->w58;
    req.fC = o->f54;
    req.tbl = D_006A3A70;
    req.sub = o->sub;
    func_0027F960(&req, 4);
}

void func_0028C518(char *base, ScriptCtx *ctx) {
    Wkb8Sub40 *w = SLOT_WORK(Wkb8Sub40, base, ctx, 0);

    func_0027FD48(w);
    w->b8 = 4;
    func_00266EB8(&D_0036F1F0, w->sub, func_0028C4C0, w);
}

void func_0028C570(char *base, ScriptCtx *ctx) {
    func_00266EE8(&D_0036F1F0, SLOT_WORK(Wkb8Sub40, base, ctx, 0)->sub);
}

void func_0028C590(ScriptWork *base, T6_ColMsg *msg, ScriptCtx *ctx)
{
    T6_ColMgr *mgr = ppvMng;
    T6_WkCol30 *w = SLOT_WORK(T6_WkCol30, base, ctx, 0);

    func_0028B940(base, (ScriptMsg *)msg, ctx); /* DEBT(CAST): shared handler takes the base message type */
    if (msg->id == base->owner) {
        w->f30 = msg->fC;
        w->f38 = msg->h10;
        w->f3C = msg->h12;
    }
    w->col[0] = (msg->col[0] * ppvMng->scale[0]) >> 12;
    w->col[1] = (msg->col[1] * ppvMng->scale[1]) >> 12;
    w->col[2] = (msg->col[2] * ppvMng->scale[2]) >> 12;
    w->col[3] = (msg->col[3] * ppvMng->scale[3]) >> 12;
    func_002DD0B0(w->m10, mgr->m60);
}

void func_0028C690(void *p)
{
    V6EmitH *o = p;
    T6_ColReqH req;

    req.self = o;
    *(int *)req.col = o->w34; /* DEBT(CAST): colour bytes copied as one word */
    req.h10 = o->f38;
    req.h12 = o->f3C;
    req.fC = o->f30;
    req.tbl = D_006A3A70;
    req.sub = o->sub;
    func_0027FF18(&req, 4);
}

void func_0028C700(char *base, ScriptCtx *ctx) {
    WkSub20 *w = SLOT_WORK(WkSub20, base, ctx, 0);

    func_00280168(w);
    func_00266EB8(&D_0036F1F0, w->sub, func_0028C690, w);
}

void func_0028C750(char *base, ScriptCtx *ctx) {
    func_00266EE8(&D_0036F1F0, SLOT_WORK(WkSub20, base, ctx, 0)->sub);
}

void func_0028C770(ScriptWork *base, T6_ColMsg *msg, ScriptCtx *ctx)
{
    T6_ColMgr *mgr = ppvMng;
    T6_WkCol30h *w = SLOT_WORK(T6_WkCol30h, base, ctx, 0);

    func_0028BAC8(base, (ScriptMsg *)msg, ctx); /* DEBT(CAST): shared handler takes the base message type */
    if (msg->id == base->owner) {
        w->f30 = msg->fC;
        w->f38 = msg->h10;
        w->h3C = msg->h12;
    }
    w->col[0] = (msg->col[0] * ppvMng->scale[0]) >> 12;
    w->col[1] = (msg->col[1] * ppvMng->scale[1]) >> 12;
    w->col[2] = (msg->col[2] * ppvMng->scale[2]) >> 12;
    w->col[3] = (msg->col[3] * ppvMng->scale[3]) >> 12;
    func_002DD0B0(w->m10, mgr->m60);
}

void func_0028C868(void *p)
{
    V6EmitH2 *o = p;
    T6_ColReqH req;

    req.self = o;
    *(int *)req.col = o->w34; /* DEBT(CAST): colour bytes copied as one word */
    req.fC = o->f30;
    req.h10 = o->f38;
    req.h12 = o->h3C;
    req.tbl = D_006A3A70;
    req.sub = o->sub;
    func_00280180(&req, 4);
}

void func_0028C8D0(char *base, ScriptCtx *ctx) {
    WkSub20 *w = SLOT_WORK(WkSub20, base, ctx, 0);

    func_002803A8(w);
    func_00266EB8(&D_0036F1F0, w->sub, func_0028C868, w);
}

void func_0028C920(char *base, ScriptCtx *ctx) {
    func_00266EE8(&D_0036F1F0, SLOT_WORK(WkSub20, base, ctx, 0)->sub);
}

void func_0028C940(ScriptWork *base, R6FMsg2 *msg, ScriptCtx *ctx)
{
    T6_Wkf9CfA8 *w;
    Wkf0f4f8 *d;

    if (D_006A3BC4 == 0) {
        d = SLOT_WORK(Wkf0f4f8, base, ctx, 0);
        w = SLOT_WORK(T6_Wkf9CfA8, base, ctx, 1);
        if (base->owner == msg->id) {
            d->f0 += msg->f4;
            d->f4 += msg->f8;
            if (base->owner == 0) {
                return;
            }
        }
        w->f9C += d->f0;
        w->fA8 += d->f4;
    }
}

void func_0028C9C8(char *base, ScriptCtx *ctx) {
    Wkw0w4 *w = SLOT_WORK(Wkw0w4, base, ctx, 0);

    w->w0 = 0;
    w->w4 = 0;
}

INCLUDE_ASM("build/ee_asm/game/particle/eiProg/ppp_28B480", pppKeHmgEff);

void func_0028CBA8(void) {
}

void func_0028CBB0(ScriptWork *base, R6FMsg2 *msg, ScriptCtx *ctx) {
    R6FPPtr *w;

    if (base->owner == msg->id) {
        w = SLOT_WORK(R6FPPtr, base, ctx, 1);
        w->f0 = msg->f4;
        w->p8 = SLOT_WORK(void, base, ctx, 0);
        w->f4 = msg->f8;
    }
}

void func_0028CC00(char *base, ScriptCtx *ctx) {
    Wkw0w4w8 *w = SLOT_WORK(Wkw0w4w8, base, ctx, 1);

    w->w8 = 0;
}

INCLUDE_ASM("build/ee_asm/game/particle/eiProg/ppp_28B480", func_0028CC18);

void func_0028CD58(void) {
}

void func_0028CD60(ScriptWork *base, R6FMsg *msg, ScriptCtx *ctx) {
    R6FPtr *w;

    if (base->owner == msg->id) {
        w = SLOT_WORK(R6FPtr, base, ctx, 1);
        w->p4 = SLOT_WORK(void, base, ctx, 0);
        w->f0 = msg->f4;
    }
}

void func_0028CDA8(void) {
}

void func_0028CDB0(ScriptWork *base, T6_MsgCDB0 *msg, ScriptCtx *ctx)
{
    u8 *flags = SLOT_WORK(u8, base, ctx, 2);
    T6_WkB10 *w;
    T6_MemEnt *e;
    T6_Mem *m;
    char *dst;
    void *src;

    if (*flags & 2) {
        return;
    }
    if (base->owner == msg->id) {
        if (msg->bC != 0) {
            *flags |= 1;
        } else {
            *flags &= ~1;
        }
    }
    if (D_006A3BC4 == 0) {
        w = SLOT_WORK(T6_WkB10, base, ctx, 1);
        if ((w->b10 & 1) && msg->idx != 0xFFFFFFFF) {
            e = &ppvMng->p3C[msg->idx];
            if (e == 0) {
                m = 0;
            } else {
                m = func_00267320(ppvMng, e);
                if (m == 0) {
                    return;
                }
                m->user = base;
            }
            src = SLOT_WORK(void, base, ctx, 0);
            dst = (char *)m + (msg->ofs + 0xA0);
            if (!(*flags & 1)) {
                *flags |= 2;
                func_00282798(dst, w);
            } else {
                func_00282798(dst, src);
            }
        }
    }
}

void func_0028CEF8(char *base, ScriptCtx *ctx) {
    Wkb0b1b2b3 *w = SLOT_WORK(Wkb0b1b2b3, base, ctx, 2);

    w->b0 = 0;
}

INCLUDE_ASM("build/ee_asm/game/particle/eiProg/ppp_28B480", pppKeHitChkPxB);

void func_0028D100(char *base, ScriptCtx *ctx)
{
    WkfCb10 *w = SLOT_WORK(WkfCb10, base, ctx, 2);

    w->fC = 1.0f;
    w->b10 = 0;
}

void func_0028D128(ScriptWork *base, R6FMsg3 *msg, ScriptCtx *ctx) {
    Wkf0f4f8 *w;

    if (base->owner == msg->id) {
        w = SLOT_WORK(Wkf0f4f8, base, ctx, 0);
        w->f0 = msg->f10;
        w->f4 = msg->f14;
        w->f8 = msg->f18;
    }
}

void func_0028D168(char *base, ScriptCtx *ctx)
{
    SLOT_WORK(WkfCw1C, base, ctx, 0)->fC = 1.0f;
}

typedef struct IVec4 {
    int x, y, z, w;
} __attribute__((aligned(8))) IVec4;

extern u_long128 D_003730A0;
extern void pppGetRotMatrixXYZ(void *m, void *rot);

void func_0028D188(char *base, int unused, ScriptCtx *ctx) {
    IVec4 t;
    IVec4 *s = SLOT_WORK(IVec4, base, ctx, 1);
    IVec4 *d = SLOT_WORK(IVec4, base, ctx, 0);
    int x, y, z;

    x = s->x;
    t = d[8];
    d[8].x = x;
    y = s->y;
    d[8].y = y;
    z = s->z;
    t.x -= x;
    t.y -= y;
    t.z -= z;
    d[8].z = z;
    pppGetRotMatrixXYZ(d + 4, &t);
    *(u_long128 *)(d + 7) = D_003730A0;
}

void func_0028D230(char *base, ScriptCtx *ctx) {
    Wkw80w84w88 *w = SLOT_WORK(Wkw80w84w88, base, ctx, 0);

    w->w80 = 0;
    w->w84 = 0;
    w->w88 = 0;
}

void func_0028D250(T6_MtxNode *o)
{
    T6_MtxNode *p = o->parent;
    float rot[4][4];
    Vec4 pos;

    func_002DCEC8((s32)rot[0], (s32)p->m[0]); /* DEBT(CAST): funcs.h prototype takes ints */
    func_002DCEC8((s32)rot[1], (s32)p->m[1]);
    func_002DCEC8((s32)rot[2], (s32)p->m[2]);
    func_002DCE08(&pos, p->m, o->m[3]);
    func_002DCE38(o->m, rot, o->m);
    func_002DD0B0(o->m[3], &pos);
}

INCLUDE_ASM("build/ee_asm/game/particle/eiProg/ppp_28B480", func_0028D2F0);
