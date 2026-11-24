/* tu_305 0x27f2e8-0x2803c0: low; ~KeLnsLp (config/tu_map.tsv) */
/* Module guess: event-script VM / field-event runtime (no __FILE__ string found for this range). */
#define func_0027F960 _hdr_func_0027F960
#define func_0027FC48 _hdr_func_0027FC48
#define func_0027FD60 _hdr_func_0027FD60
#define func_0027FF18 _hdr_func_0027FF18
#define func_00280180 _hdr_func_00280180
#include "common.h"
#include "ffx/r6.h"
#include "ffx/w9.h"
#include "ffx/q6.h"
#include "ffx/u4.h"
#include "ffx/v6.h"
#include "ffx/g4.h"
#undef func_0027F960
#undef func_0027FC48
#undef func_0027FD60
#undef func_0027FF18
#undef func_00280180

void func_0027F2E8(R6Hb *dst, DataRef **p) {
    dst->h0 = (*p)->keys[0].dur;
    dst->b2 = 0;
}

void func_0027F300(G4PtPlayer *p)
{
    G4Hb *pos = p->pos;
    G4PtKey *key;
    union { u8 b; } prev; /* DEBT(TYPE): 1-byte union keeps QImode without PROMOTE_MODE zero-extend */

    pos->h0 += 0x200;
    key = &(*p->anim)->keys[pos->b2];
    if ((s16)pos->h0 >= key->dur) {
        pos->h0 -= key->dur;
        prev.b = pos->b2++;
        if (pos->b2 >= (*p->anim)->frames) {
            if (key->flags & 0x80) {
                pos->b2 = 0;
                pos->h0 = 0;
            } else {
                pos->b2 = prev.b;
                pos->h0 = 0;
            }
        }
    }
}

void func_0027F3A0(G4PtPlayer *p)
{
    G4PtAnim **anim = p->anim;
    G4Hb *pos = p->pos;
    G4PtKey *key = &(*anim)->keys[pos->b2];

    p->sub.b18 = 0;
    *(u8 **)((char *)p + 0x18) = 0; /* DEBT(CAST): scalar u8* store so D_006A3BCC load depends on it */
    p->sub.hC = 0x11;
    p->sub.p14 = D_006A3BCC;
    p->sub.h2 |= 0xB0;
    D_006A3BCC = (u8 *)func_002CD590((int)((char *)*anim + key->ofs), (int)&p->sub); /* DEBT(CAST): byte offset from anim base */
}

INCLUDE_ASM("build/ee_asm/game/particle/ke_27F2E8", KeLnsLp_Update);

void func_0027F928(void *p)
{
    WkM40fAC *w = p;

    func_002DD128(w->m40);
    w->fAC = 1.0f;
}

extern float D_006A39B0[];
extern float D_006A39E8;
void func_002DD0C0(void *, void *);
void func_002DD0B0(void *, void *);
void func_002DD068(void *, void *, float);
void func_002DCE38(void *, void *, void *);

typedef struct {
    R6Hb hb;
    float f4;
} KeLnsItem;

typedef struct {
    void *w;
    DataRef **anim;
    u8 cnt;
    u8 flags;
    s16 hA;
    s16 hC;
    u8 bE;
    u8 padF;
    KeLnsItem items[1];
} KeLnsSlot;

typedef struct {
    KeLnsSlot *slot;
    u32 col;
    void *p08;
    float scale;
    float f10;
    float *vec14;
} KeArgF960;

void func_0027F960(KeArgF960 *arg, int flags)
{
    float m0[4][4];
    float m1[4][4];
    G4PtPlayer pl;
    u8 pad[0x10];
    KeLnsSlot *s = arg->slot;
    u8 *vt = (u8 *)s->w;
    register float py __asm__("$f22");
    register float px __asm__("$f23");
    float sx;
    float sy;
    float t;
    s32 cnt;
    KeLnsItem *it;

    if (vt == (u8 *)D_006EA450) {
        return;
    }
    if (s->anim == 0) {
        return;
    }
    if (*(float *)(vt + 0x7C) == 0.0f) {
        return;
    }
    if (vt[0x8F] != 0) {
        func_002DD0C0(m0, vt);
    } else {
        func_002DD128(m0);
        m0[3][2] = D_006A39E8 + *(float *)(vt + 0x88);
    }
    {
        G4PtAnim **anim = (G4PtAnim **)s->anim;
        __asm__ volatile("" : "+r"(anim) : "r"(m1));
        pl.anim = anim;
    }
    *(u32 *)((u8 *)&pl + 0x14) = arg->col;
    pl.sub.h2 = flags;
    *(void **)((u8 *)&pl + 0x20) = m1;
    *(s32 *)((u8 *)&pl + 0x2C) = 0;
    *(s32 *)((u8 *)&pl + 0x18) = 0;
    *(s16 *)((u8 *)&pl + 0x1C) = 0;
    *(s16 *)((u8 *)&pl + 0x1E) = 0;
    if (vt[0x8F] != 0) {
        py = 0.0f;
        px = 0.0f;
    } else {
        float *b = D_006A39B0;
        py = b[13];
        __asm__("" : "+r"(b) : "f"(py));
        px = b[12];
    }
    {
        float fC = (float)s->hC;
        register float fA __asm__("$f3") = (float)s->hA;

        t = *(float *)(vt + 0x70);
        px += t * fC;
        sx = t * fA;
        t = *(float *)(vt + 0x74);
        py += t * fC;
        sy = t * fA;
        __asm__("" : "+f"(t));
    }
    t = *(float *)(vt + 0xA4);
    t -= (float)vt[0x8E];
    if (t <= 0.0f) {
        t = 0.0f;
    } else {
        t = t / (arg->f10 * *(float *)(vt + 0x78));
        if (t > 1.0f) {
            t = 1.0f;
        }
    }
    if (s->bE != 0) {
        t = 1.0f - t;
    }
    t = t * ((float)*((u8 *)&pl + 0x17) * *(float *)(vt + 0x7C));
    it = s->items;
    cnt = s->cnt;
    while (cnt > 0) {
        float f = it->f4;

        pl.pos = (G4Hb *)it;
        func_0027F300(&pl);
        cnt--;
        it++;
        px += sx * f;
        py += sy * f;
        m0[3][0] = px;
        m0[3][1] = py;
        *((u8 *)&pl + 0x17) = (u8)(u32)((double)t * ((double)f * 0.75 + 0.25));
        f *= arg->scale;
        m0[0][0] = *(float *)(vt + 0x00) * f * arg->vec14[0];
        m0[1][1] = *(float *)(vt + 0x14) * f * arg->vec14[1];
        func_002DCE38(m1, arg->p08, m0);
        func_0027F3A0(&pl);
    }
}

void func_0027FC48(KeLnsSlot *s, DataRef **anim, int seed)
{
    int i;

    s->anim = anim;
    for (i = 0; i < s->cnt; i++) {
        func_0027F2E8(&s->items[i].hb, anim);
    }
    if ((s->flags & 1) == 0) {
        int r = seed;
        for (i = 0; i < s->cnt; i++) {
            r = (r * 0x80D + 7) & 0xFFFF;
            s->items[i].f4 = (float)r / 65535.0f;
        }
        s->flags |= 1;
    }
}

void func_0027FD48(R6VObj *o) {
    o->w4 = 0;
    o->b9 = 0;
    o->vt = D_006EA450;
}

typedef struct {
    void *vt;
    void *w04;
    u8 b08[8];
} KeWork10;

typedef struct {
    KeWork10 *work;
    u32 col;
    void *p08;
    float scale;
    float *vec10;
} KeArgFD60;

typedef struct {
    KeWork10 *work;
    u32 col;
    void *p08;
    float scale;
    u16 h10;
    u16 h12;
    float *vec14;
} KeArgFF18;

typedef struct {
    KeWork10 *work;
    u32 col;
    void *p08;
    float scale;
    u16 h10;
    u8 b12;
    u8 b13;
    float *vec14;
} KeArg0180;

void func_0027FD60(KeArgFD60 *arg, int flags)
{
    float m[4][4];
    G4PtPlayer pl;
    u8 pad[0x10];
    KeWork10 *w = arg->work;
    u8 *vt = (u8 *)w->vt;
    float s;

    if (vt != (u8 *)D_006EA450 && w->w04 != 0 && *(float *)(vt + 0x7C) != 0.0f) {
        if (vt[0x8F] != 0) {
            func_002DD0C0(m, vt);
        } else {
            func_002DD128(m);
            m[3][0] = D_006A39B0[12] + *(float *)(vt + 0x80);
            m[3][1] = D_006A39B0[13] + *(float *)(vt + 0x84);
            m[3][2] = D_006A39B0[14] + *(float *)(vt + 0x88);
        }
        s = arg->scale;
        m[0][0] *= s;
        m[1][1] *= s;
        func_002DD068(m[0], m[0], arg->vec10[0]);
        func_002DD068(m[1], m[1], arg->vec10[1]);
        func_002DD068(m[2], m[2], arg->vec10[2]);
        func_002DCE38(m, arg->p08, m);
        {
            u32 col = arg->col;
            G4Hb *pos = (G4Hb *)w->b08;
            float alpha = *(float *)(vt + 0x7C);
            __asm__ volatile("" : : "r"(vt));
            *(u32 *)((u8 *)&pl + 0x14) = col;
            pl.pos = pos;
            *((u8 *)&pl + 0x17) = (u8)((float)*((u8 *)&pl + 0x17) * alpha);
        }
        pl.anim = (G4PtAnim **)w->w04;
        func_0027F300(&pl);
        pl.sub.h2 = flags;
        *(void **)((u8 *)&pl + 0x20) = m;
        *(s32 *)((u8 *)&pl + 0x2C) = 0;
        *(s32 *)((u8 *)&pl + 0x18) = 0;
        *(s32 *)((u8 *)&pl + 0x1C) = 0;
        func_0027F3A0(&pl);
    }
}

void func_0027FF00(R6VObj *o) {
    o->w4 = 0;
    o->vt = D_006EA450;
}

void func_0027FF18(KeArgFF18 *arg, int flags)
{
    float m[4][4];
    G4PtPlayer pl;
    u8 pad[0x10];
    KeWork10 *w = arg->work;
    u8 *vt = (u8 *)w->vt;
    float s;
    float a;

    if (vt == (u8 *)D_006EA450) {
        return;
    }
    if (w->w04 == 0) {
        return;
    }
    if (*(float *)(vt + 0x7C) == 0.0f) {
        return;
    }
    func_002DD0B0(m[0], vt + 0x40);
    func_002DD0B0(m[1], vt + 0x50);
    func_002DD0B0(m[2], vt + 0x60);
    func_002DD0B0(m[3], vt + 0x30);
    s = (arg->scale * *(float *)(vt + 0xA4)) / (float)arg->h10;
    func_002DD068(m[0], m[0], -s);
    func_002DD068(m[1], m[1], s);
    if (vt[0x8F] == 0) {
        m[3][0] = D_006A39B0[12] + *(float *)(vt + 0x80);
        m[3][1] = D_006A39B0[13] + *(float *)(vt + 0x84);
        m[3][2] = D_006A39B0[14] + *(float *)(vt + 0x88);
    }
    func_002DD068(m[0], m[0], arg->vec14[0]);
    func_002DD068(m[1], m[1], arg->vec14[1]);
    func_002DD068(m[2], m[2], arg->vec14[2]);
    func_002DCE38(m, arg->p08, m);
    s = *(float *)(vt + 0xA4) / (float)arg->h12;
    *(u32 *)((u8 *)&pl + 0x14) = arg->col;
    a = (s > 1.0f) ? 1.0f : s;
    {
        u8 b = *((u8 *)&pl + 0x17);
        G4Hb *pos = (G4Hb *)w->b08;
        float alpha = *(float *)(vt + 0x7C);
        __asm__ volatile("" : : "r"(vt));
        pl.pos = pos;
        *((u8 *)&pl + 0x17) = (u8)((float)b * alpha * a);
    }
    pl.anim = (G4PtAnim **)w->w04;
    func_0027F300(&pl);
    pl.sub.h2 = flags;
    *(void **)((u8 *)&pl + 0x20) = m;
    *(s32 *)((u8 *)&pl + 0x2C) = 0;
    *(s32 *)((u8 *)&pl + 0x18) = 0;
    *(s16 *)((u8 *)&pl + 0x1C) = 0;
    *(s16 *)((u8 *)&pl + 0x1E) = 0;
    func_0027F3A0(&pl);
}

void func_00280150(AttachWork *w, DataRef **p) {
    w->cur = p;
    func_0027F2E8((R6Hb *)&w->h8, p); /* DEBT(CAST): sub-block at +8 */
}

void func_00280168(R6VObj *o) {
    o->w4 = 0;
    o->vt = D_006EA450;
}

void func_00280180(KeArg0180 *arg, int flags)
{
    float m[4][4];
    G4PtPlayer pl;
    u8 pad[0x10];
    KeWork10 *w = arg->work;
    u8 *vt = (u8 *)w->vt;
    float r;
    float inv;
    float s;

    if (vt == (u8 *)D_006EA450) {
        return;
    }
    if (w->w04 == 0) {
        return;
    }
    if (*(float *)(vt + 0x7C) == 0.0f) {
        return;
    }
    inv = 0.0f;
    r = *(float *)(vt + 0xA4) / (float)arg->h10;
    if (r > 1.0f) {
    } else {
        inv = 1.0f - r;
    }
    if (vt[0x8F] != 0) {
        func_002DD0C0(m, vt);
    } else {
        func_002DD128(m);
        m[3][0] = D_006A39B0[12] + *(float *)(vt + 0x80);
        m[3][1] = D_006A39B0[13] + *(float *)(vt + 0x84);
        m[3][2] = D_006A39B0[14] + *(float *)(vt + 0x88);
    }
    m[0][0] = arg->scale;
    switch (arg->b12) {
    case 1:
        m[0][0] = arg->scale * inv;
        break;
    case 2:
        m[0][0] = r * arg->scale + arg->scale;
        break;
    }
    m[1][1] = arg->scale;
    switch (arg->b13) {
    case 1:
        m[1][1] = arg->scale * inv;
        break;
    case 2:
        m[1][1] = r * arg->scale + arg->scale;
        break;
    }
    func_002DD068(m[0], m[0], arg->vec14[0]);
    func_002DD068(m[1], m[1], arg->vec14[1]);
    func_002DCE38(m, arg->p08, m);
    {
        u32 col = arg->col;
        G4Hb *pos = (G4Hb *)w->b08;
        float alpha = *(float *)(vt + 0x7C);
        __asm__ volatile("" : : "r"(vt));
        *(u32 *)((u8 *)&pl + 0x14) = col;
        pl.pos = pos;
        *((u8 *)&pl + 0x17) = (u8)((float)*((u8 *)&pl + 0x17) * alpha * inv);
    }
    pl.anim = (G4PtAnim **)w->w04;
    func_0027F300(&pl);
    pl.sub.h2 = flags;
    *(void **)((u8 *)&pl + 0x20) = m;
    *(s32 *)((u8 *)&pl + 0x2C) = 0;
    *(s32 *)((u8 *)&pl + 0x18) = 0;
    *(s16 *)((u8 *)&pl + 0x1C) = 0;
    *(s16 *)((u8 *)&pl + 0x1E) = 0;
    func_0027F3A0(&pl);
}

void func_002803A8(R6VObj *o) {
    o->w4 = 0;
    o->vt = D_006EA450;
}
