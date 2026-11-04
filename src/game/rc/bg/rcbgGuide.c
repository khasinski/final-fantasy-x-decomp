/* tu_152 0x195378-0x197cd8: medium; rcbgGuide (config/tu_map.tsv) */
#include "common.h"
#include "ffx/r2.h"
#include "ffx/q3.h"
#include "ffx/s2.h"
#include "ffx/t2.h"
#include "ffx/v2.h"
#include "ffx/g2.h"
#include "vu0.h"

INCLUDE_ASM("build/ee_asm/game/rc/bg/rcbgGuide", func_00195378);

INCLUDE_ASM("build/ee_asm/game/rc/bg/rcbgGuide", func_001953B8);

void rcbgModelCreateFromOMD(int *p, int v) {
    p[5] = v;
}

void rcbgModelSetScale(void *p, float v) {
    R2Obj195 *o = p;

    v = v * 10.0f;
    func_0018F260(&o->fC0, v, v, v);
}

float func_00195688(void *p) {
    R2Obj195 *o = p;

    return o->fC0 / 10.0f;
}

void func_001956A8(void *p, u64 v) {
    R2Obj195 *o = p;

    op_md_tex0_reset(o->f14, v);
}

INCLUDE_ASM("build/ee_asm/game/rc/bg/rcbgGuide", func_001956B0);

INCLUDE_ASM("build/ee_asm/game/rc/bg/rcbgGuide", func_00195750);

INCLUDE_ASM("build/ee_asm/game/rc/bg/rcbgGuide", rcbgModelDraw);

u8 *rcbgModelGetPrimHeader(R2Obj195b *o, int n) {
    u8 *p = (u8 *)o->f14 + o->f14->w4;
    int i;

    for (i = 0; i < n; i++) {
        p += D_00313710[(s8)p[1]] * *(s16 *)(p + 2) + 0x10;
    }
    return p;
}

u8 *func_001958F0(R2Obj195b *o, int n) {
    return rcbgModelGetPrimHeader(o, n) + 0x10;
}

u8 *func_00195910(R2Obj195b *o) {
    R2Sub195 *s = o->f14;
    int size = s->h14 * 6;

    if ((size & 0xF) != 0) {
        size = (size & ~0xF) + 0x10;
    }
    return (u8 *)s->wC + size;
}

void func_00195948(int a) {
    u64 regs[4];

    regs[1] = D_0056D948[1];
    regs[2] = D_0056D948[2];
    regs[3] = D_0056D948[3];
    regs[0] = (u64)a << 17 | 0x1000F;
    func_00192708(regs);
}

INCLUDE_ASM("build/ee_asm/game/rc/bg/rcbgGuide", rcbgModelFToS0);

void rcbgModelDump(float *dst, s16 *src, int n, float scale)
{
    int iv[4];
    u_long128 fv;
    int i;

    for (i = 0; i < n; i++) {
        iv[0] = src[0];
        iv[1] = src[1];
        iv[2] = src[2];
        VU0_LQC2(31, 0, iv);
        VU0_OP("vitof0.xyzw $vf31, $vf31");
        VU0_SQC2(31, 0, &fv);
        VU0_LQC2(31, 0, &fv);
        VU0_QMTC2_NI(30, scale);
        VU0_OP("vmulx.xyz $vf31, $vf31, $vf30x");
        VU0_SQC2(31, 0, dst);
        src += 3;
        dst += 4;
    }
}

INCLUDE_ASM("build/ee_asm/game/rc/bg/rcbgGuide", func_00195A88);

void *rcbgGuideNew(void) {
    void *p = _rcAlloc(0x80, D_0056D980, 0x6F);

    func_00195B68(p);
    return p;
}

void func_00195B40(void *p) {
    func_00195BB0(p);
    func_0018FC10(p);
}

void func_00195B68(void *p) {
    Obj195B68 *o = p;

    func_002EF0D0(o, 0, 0x80);
    o->f6C = 350.0f;
    D_00313720 |= 0x100;
    rcbgGuideUpdateEx();
}

void func_00195BB0(void *p) {
    Q3Slot8 *o = p;

    if (o->buf != 0) {
        rcbgModelDelete(o->buf);
        o->buf = 0;
    }
}

void func_00195BE8(void) {
}

void rcbgGuideSetModelFromIdMap(struct W3Sub *sub, void *item) {
    GuideMap *g = (GuideMap *)sub; /* DEBT(CAST): W3Sub is the opaque view */

    if (g->model != 0) {
        rcbgModelDelete(g->model);
        g->model = 0;
    }
    if (item != 0) {
        g->id = (int)item; /* DEBT(TYPE): declared as a pointer, it is an id */
        g->src = 0;
        rcbgGuideSetModelSub(g);
    } else {
        func_00195C58(g);
    }
}

void func_00195C58(GuideMap *g) {
    GuideSrc *src;
    S2Vt *m;
    Vec4 *v;
    GuidePoly *q;
    GuideTri *tri;
    u8 *data;
    float inv;
    float f;
    int total;
    int nv;
    int i;
    int j;

    if (g->model != 0) {
        rcbgModelDelete(g->model);
        g->model = 0;
    }
    g->id = 0;
    src = (GuideSrc *)Sg_IdGetPtr(); /* DEBT(TYPE): declared returning s32 */
    g->src = src;
    if (src != 0) {
        total = 0;
        for (i = 0; i < src->ngrp; i++) {
            total += src->grp[i].ntri;
        }
        if (total >= 512) {
            func_0018F5E8(D_0056D990, total, 512);
            return;
        }
        nv = src->nvtx;
        m = rcbgModelNew();
        func_00195378(m, 0, total, nv, 0);
        v = _rcAlloc(nv * sizeof(Vec4), D_0056D980, 229);
        inv = 1.0f / src->scale;
        for (i = 0; i < nv; i++) {
            v[i].x = src->vtx[i].x * inv;
            v[i].y = 0.0f;
            v[i].z = src->vtx[i].z * inv;
        }
        rcBBoxSet(&m->v90, v, nv);
        data = (u8 *)((R2Obj195b *)m)->f14 + ((R2Obj195b *)m)->f14->w8; /* DEBT(CAST): the model is also seen as R2Obj195b */
        f = func_0018F458(&m->v90);
        rcbgModelFToS0(data, v, nv, f);
        rcbgModelSetScale(m, f);
        q = (GuidePoly *)func_001958F0((R2Obj195b *)m, 0);
        for (i = 0; i < src->ngrp; i++) {
            tri = src->grp[i].tri;
            for (j = 0; j < src->grp[i].ntri; j++) {
                q->col[0][0] = q->col[0][1] = q->col[0][2] = 0xFF;
                q->col[0][3] = 0x80;
                q->col[1][0] = q->col[1][1] = q->col[1][2] = 0xFF;
                q->col[1][3] = 0x80;
                q->col[2][0] = q->col[2][1] = q->col[2][2] = 0xFF;
                q->col[2][3] = 0x80;
                q->v[0] = tri[j].v[0];
                q->v[1] = tri[j].v[1];
                q->v[2] = tri[j].v[2];
                q->h12 = 0;
                q++;
            }
        }
        m->w10 |= 6;
        if (v != 0) {
            func_0018FC10(v);
        }
        g->model = m;
        rcbgGuideSetModelSub(g);
    }
}

INCLUDE_ASM("build/ee_asm/game/rc/bg/rcbgGuide", rcbgGuideSetModelSub);

INCLUDE_ASM("build/ee_asm/game/rc/bg/rcbgGuide", func_00195FF8);

INCLUDE_ASM("build/ee_asm/game/rc/bg/rcbgGuide", func_001960D0);

INCLUDE_ASM("build/ee_asm/game/rc/bg/rcbgGuide", func_001961F8);

INCLUDE_ASM("build/ee_asm/game/rc/bg/rcbgGuide", func_00196498);

INCLUDE_ASM("build/ee_asm/game/rc/bg/rcbgGuide", rcbgGuideUpdateEx);

INCLUDE_ASM("build/ee_asm/game/rc/bg/rcbgGuide", func_00196638);

INCLUDE_ASM("build/ee_asm/game/rc/bg/rcbgGuide", func_00196640);

INCLUDE_ASM("build/ee_asm/game/rc/bg/rcbgGuide", rcbgGuideUpdateWalk);

INCLUDE_ASM("build/ee_asm/game/rc/bg/rcbgGuide", func_00197868);

void func_00197A00(void *unused, float *scale, float *pos) {
    *scale = D_00313728 * (1.0f / 256.0f);
    pos[0] = D_0031372C - 256.0f;
    pos[1] = D_00313730 - 208.0f;
}

void func_00197A58(struct W3Sub *sub, int a) {
    D_00313724 = a;
    switch (a) {
    case 0:
        func_00197B70(sub, 0x80);
        func_00197B80(sub, 0x50, 0x40);
        break;
    case 1:
        func_00197B70(sub, 0x80);
        func_00197B80(sub, 0x1B0, 0x40);
        break;
    case 2:
        func_00197B70(sub, 0x80);
        func_00197B80(sub, 0x50, 0x160);
        break;
    case 3:
        func_00197B70(sub, 0x80);
        func_00197B80(sub, 0x1B0, 0x160);
        break;
    case 4:
        func_00197B70(sub, 0x100);
        func_00197B80(sub, 0x100, 0xD0);
        break;
    }
}

void func_00197B70(struct W3Sub *sub, int a) {
    D_00313728 = a;
}

void func_00197B80(struct W3Sub *sub, int a, int b) {
    D_0031372C = a;
    D_00313730 = b;
}

void func_00197B98(struct W3Sub *sub, int a) {
    if (a != 0) {
        D_00313720 |= 8;
    } else {
        D_00313720 &= ~8U;
    }
}

void func_00197BD0(struct W3Sub *sub, int a) {
    if (a != 0) {
        D_00313720 |= 1;
    } else {
        D_00313720 &= ~1U;
    }
}

void func_00197C08(struct W3Sub *sub, int a) {
    if (a != 0) {
        D_00313720 |= 0x100;
    } else {
        D_00313720 &= ~0x100U;
    }
}

void func_00197C40(struct W3Sub *sub, int a) {
    D_00313720 |= a;
}

void func_00197C58(struct W3Sub *sub, int a) {
    D_00313720 &= ~a;
}

int func_00197C70(struct W3Sub *sub) {
    return func_00197C90(sub) != 0;
}

int func_00197C90(struct W3Sub *sub) {
    int v = sub->w00;

    if (v == 0) {
        v = sub->w08;
    }
    return v;
}

void func_00197CA8(struct W3Sub *sub, float f) {
    sub->f6C = f;
}

float func_00197CB0(struct W3Sub *sub) {
    return sub->f6C;
}

int func_00197CB8(void) {
    return D_00313720;
}

int func_00197CC8(void) {
    return D_00313724;
}
