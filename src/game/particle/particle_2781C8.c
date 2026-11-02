/* tu_300 0x2781c8-0x278c40: medium; unk_2781C8 (config/tu_map.tsv) */
/* Module guess: event-script VM / field-event runtime (no __FILE__ string found for this range). */
#include "common.h"
#include "ffx/r6.h"
#include "ffx/w9.h"
#include "ffx/q6.h"
#include "ffx/t6.h"
#include "ffx/u4.h"
#include "ffx/v6.h"

void func_002781C8(void) {
}

void func_002781D0(void) {
}

void func_002781D8(ScriptWork *base, T6_LtKey *k, ScriptCtx *ctx)
{
    T6_LtRot *rot = SLOT_WORK(T6_LtRot, base, ctx, 1);
    float *pos = SLOT_WORK(float, base, ctx, 2);
    T6_LtCam *cam = (T6_LtCam *)D_006A3930; /* DEBT(CAST): camera block type unknown */
    float size;
    float x;
    float y;
    float z;
    int sc;
    int rx;
    int ry;
    int rz;

    sc = (s16)rot->s >> 7;
    rx = rot->x * sc >> 14;
    ry = rot->y * sc >> 14;
    rz = rot->z * sc >> 14;
    x = pos[0] + cam->x;
    y = pos[1] + cam->y;
    z = pos[2] + cam->z;
    if (D_003708BC < D_003708C0) {
        Sg_PLightDefine(x, y, z, k->f4, D_003708BC, rx, ry, rz, k->b8);
        size = k->size;
        if (size == 0.0f) {
            size = 2.0f;
        }
        ((void (*)(int, double))Sg_PLightSetAttenuation)(D_003708BC, func_002ED038(size)); /* DEBT(CAST): called unprototyped in the original (float promoted to double) */
    }
    D_003708C4 |= 1 << k->b8;
    D_003708BC++;
}

void func_002782F8(void) {
}

void func_00278300(void) {
}

void func_00278308(ScriptWork *base, T6_LtKey *k, ScriptCtx *ctx)
{
    T6_LtRot *rot = SLOT_WORK(T6_LtRot, base, ctx, 1);
    float *pos = SLOT_WORK(float, base, ctx, 2);
    T6_LtCam *cam;
    T6_LtShape *shape;
    s16 *pt;
    float size;
    float x;
    float y;
    float z;
    float px;
    float py;
    float pz;
    int sc;
    int rx;
    int ry;
    int rz;
    int i;

    if (k->id != 0xFFFF) {
        cam = (T6_LtCam *)D_006A3930; /* DEBT(CAST): camera block type unknown */
        sc = (s16)rot->s >> 7;
        rx = rot->x * sc >> 14;
        ry = rot->y * sc >> 14;
        rz = rot->z * sc >> 14;
        size = k->size;
        x = pos[0] + cam->x;
        y = pos[1] + cam->y;
        z = pos[2] + cam->z;
        shape = ((T6_LtHeap *)D_006A3924)->res[k->id].shape; /* DEBT(CAST): HeapMgr view */
        if (size == 0.0f) {
            size = 2.0f;
        }
        pt = (s16 *)((char *)shape + shape->ofs);
        for (i = 0; i < shape->n; i++, pt += 3) {
            px = pt[0] + x;
            py = pt[1] + y;
            pz = pt[2] + z;
            if (D_003708BC < D_003708C0) {
                Sg_PLightDefine(px, py, pz, k->f4, D_003708BC, rx, ry, rz, k->b8);
                ((void (*)(int, double))Sg_PLightSetAttenuation)(D_003708BC, func_002ED038(size)); /* DEBT(CAST): called unprototyped in the original (float promoted to double) */
            }
            D_003708BC++;
        }
        D_003708C4 |= 1 << k->b8;
    }
}

void func_00278528(void) {
}

void func_00278530(void) {
}

void func_00278538(ScriptWork *base, T6_LtKey *k, ScriptCtx *ctx)
{
    T6_LtRot *rot = SLOT_WORK(T6_LtRot, base, ctx, 1);
    float *pos = SLOT_WORK(float, base, ctx, 2);
    float *scl = SLOT_WORK(float, base, ctx, 3);
    T6_LtCam *cam;
    T6_LtShape *shape;
    s16 *pt;
    float size;
    float x;
    float y;
    float z;
    float px;
    float py;
    float pz;
    int sc;
    int rx;
    int ry;
    int rz;
    int i;

    if (k->id != 0xFFFF) {
        cam = (T6_LtCam *)D_006A3930; /* DEBT(CAST): camera block type unknown */
        sc = (s16)rot->s >> 7;
        rx = rot->x * sc >> 14;
        ry = rot->y * sc >> 14;
        rz = rot->z * sc >> 14;
        size = k->size;
        x = pos[0] + cam->x;
        y = pos[1] + cam->y;
        z = pos[2] + cam->z;
        shape = ((T6_LtHeap *)D_006A3924)->res[k->id].shape; /* DEBT(CAST): HeapMgr view */
        if (size == 0.0f) {
            size = 2.0f;
        }
        pt = (s16 *)((char *)shape + shape->ofs);
        for (i = 0; i < shape->n; i++, pt += 3) {
            px = pt[0] * scl[0] + x;
            py = pt[1] * scl[1] + y;
            pz = pt[2] * scl[2] + z;
            if (D_003708BC < D_003708C0) {
                Sg_PLightDefine(px, py, pz, k->f4, D_003708BC, rx, ry, rz, k->b8);
                ((void (*)(int, double))Sg_PLightSetAttenuation)(D_003708BC, func_002ED038(size)); /* DEBT(CAST): called unprototyped in the original (float promoted to double) */
            }
            D_003708BC++;
        }
        D_003708C4 |= 1 << k->b8;
    }
}

void func_00278778(void) {
}

void func_00278780(void) {
}

void func_00278788(ScriptWork *base, T6_LtKeyG *k, ScriptCtx *ctx)
{
    T6_LtRot *rot = SLOT_WORK(T6_LtRot, base, ctx, 1);
    float *pos = SLOT_WORK(float, base, ctx, 2);
    T6_LtGrp *grp = &((T6_LtHeap *)D_006A3924)->grp[k->grp]; /* DEBT(CAST): HeapMgr view */
    T6_LtCam *cam;
    T6_LtPt *pts;
    T6_LtPt *pt;
    float size;
    float x;
    float y;
    float z;
    float px;
    float py;
    float pz;
    int sc;
    int rx;
    int ry;
    int rz;
    int i;

    if (grp != 0) {
        pts = ((T6_LtWork *)base)->pts; /* DEBT(CAST): script work view */
        if (pts == 0) {
            pts = ((T6_LtHeap *)D_006A3924)->res[grp->res].pts; /* DEBT(CAST) */
        }
        cam = (T6_LtCam *)D_006A3930; /* DEBT(CAST): camera block type unknown */
        sc = (s16)rot->s >> 7;
        rx = rot->x * sc >> 14;
        ry = rot->y * sc >> 14;
        rz = rot->z * sc >> 14;
        size = k->size;
        x = pos[0] + cam->x;
        y = pos[1] + cam->y;
        z = pos[2] + cam->z;
        if (size == 0.0f) {
            size = 2.0f;
        }
        for (i = 0; i < grp->n; i++) {
            pt = &pts[grp->idx[i]];
            px = pt->x + x;
            py = pt->y + y;
            pz = pt->z + z;
            if (D_003708BC < D_003708C0) {
                Sg_PLightDefine(px, py, pz, k->f4, D_003708BC, rx, ry, rz, k->b8);
                ((void (*)(int, double))Sg_PLightSetAttenuation)(D_003708BC, func_002ED038(size)); /* DEBT(CAST): called unprototyped in the original (float promoted to double) */
            }
            D_003708BC++;
        }
        D_003708C4 |= 1 << k->b8;
    }
}

void func_002789D0(void) {
}

void func_002789D8(void) {
}

void func_002789E0(ScriptWork *base, T6_LtKeyG *k, ScriptCtx *ctx)
{
    T6_LtRot *rot = SLOT_WORK(T6_LtRot, base, ctx, 1);
    float *pos = SLOT_WORK(float, base, ctx, 2);
    float *scl = SLOT_WORK(float, base, ctx, 3);
    T6_LtGrp *grp = &((T6_LtHeap *)D_006A3924)->grp[k->grp]; /* DEBT(CAST): HeapMgr view */
    T6_LtCam *cam;
    T6_LtPt *pts;
    T6_LtPt *pt;
    float size;
    float x;
    float y;
    float z;
    float px;
    float py;
    float pz;
    int sc;
    int rx;
    int ry;
    int rz;
    int i;

    if (grp != 0) {
        pts = ((T6_LtWork *)base)->pts; /* DEBT(CAST): script work view */
        if (pts == 0) {
            pts = ((T6_LtHeap *)D_006A3924)->res[grp->res].pts; /* DEBT(CAST) */
        }
        cam = (T6_LtCam *)D_006A3930; /* DEBT(CAST): camera block type unknown */
        sc = (s16)rot->s >> 7;
        rx = rot->x * sc >> 14;
        ry = rot->y * sc >> 14;
        rz = rot->z * sc >> 14;
        size = k->size;
        x = pos[0] + cam->x;
        y = pos[1] + cam->y;
        z = pos[2] + cam->z;
        if (size == 0.0f) {
            size = 2.0f;
        }
        for (i = 0; i < grp->n; i++) {
            pt = &pts[grp->idx[i]];
            px = pt->x * scl[0] + x;
            py = pt->y * scl[1] + y;
            pz = pt->z * scl[2] + z;
            if (D_003708BC < D_003708C0) {
                Sg_PLightDefine(px, py, pz, k->f4, D_003708BC, rx, ry, rz, k->b8);
                ((void (*)(int, double))Sg_PLightSetAttenuation)(D_003708BC, func_002ED038(size)); /* DEBT(CAST): called unprototyped in the original (float promoted to double) */
            }
            D_003708BC++;
        }
        D_003708C4 |= 1 << k->b8;
    }
}
