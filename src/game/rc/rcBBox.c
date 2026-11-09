/* tu_145 0x18ef98-0x18fce0: medium; rcBBox (config/tu_map.tsv) */
#define rcBBoxSet _hdr_rcBBoxSet
#include "common.h"
#include "ffx/r2.h"
#include "ffx/q3.h"
#include "ffx/s2.h"
#include "ffx/t2.h"
#include "ffx/v2.h"
#undef rcBBoxSet

int rcLog2(int n) {
    int i;

    for (i = 1; i < 16; i++) {
        if ((1 << i) >= n) {
            break;
        }
    }
    return i;
}

void rcVec3fMul(float *d, float *a, float *b) {
    d[0] = a[1] * b[2] - a[2] * b[1];
    d[1] = a[2] * b[0] - a[0] * b[2];
    d[2] = a[0] * b[1] - a[1] * b[0];
}

void func_0018F038(float *out, float *in, float *m) {
    out[0] = in[0] * m[0] + in[1] * m[4] + in[2] * m[8] + m[12];
    out[1] = in[0] * m[1] + in[1] * m[5] + in[2] * m[9] + m[13];
    out[2] = in[0] * m[2] + in[1] * m[6] + in[2] * m[10] + m[14];
}

float func_0018F0E8(float *a, float *b) {
    return a[0] * b[0] + a[1] * b[1] + a[2] * b[2];
}

float rcVec3fLength(Vec4 *v)
{
    return sqrtf(v->x * v->x + v->y * v->y + v->z * v->z);
}

void rcVec3fNormalize(Vec4 *v)
{
    float len = rcVec3fLength(v);
    float inv;

    if (len > 0) {
        inv = 1.0f / len;
        v->x *= inv;
        v->y *= inv;
        v->z *= inv;
    } else {
        v->x = v->y = v->z = v->w = 0;
    }
}

void func_0018F1F0(Vec4 *dst, Vec4 *a, Vec4 *b, float t)
{
    dst->x = a->x + (b->x - a->x) * t;
    dst->y = a->y + (b->y - a->y) * t;
    dst->z = a->z + (b->z - a->z) * t;
}

void rcMat4fSetTranslate(Q3Vec30 *o, float x, float y, float z) {
    o->x = x;
    o->y = y;
    o->z = z;
}

void func_0018F250(void *o, float *v) {
    rcMat4fSetTranslate(o, v[0], v[1], v[2]);
}

void func_0018F260(float *m, float x, float y, float z) {
    func_002DD128(m);
    m[0] = x;
    m[5] = y;
    m[10] = z;
}

void rcMat4fSetScaleVec3f(void *o, float *v) {
    func_0018F260(o, v[0], v[1], v[2]);
}

void *func_0018F2C8(void) {
    void *p = _rcAlloc(0x20, D_0056D3A0, 0x15);

    func_0018F310(p);
    return p;
}

void func_0018F308(void *p) {
    func_0018FC10(p);
}

void func_0018F310(W3Obj20 *o) {
    float a = D_0056D3AC;
    float b = D_0056D3B0;
    float *v = o->v;

    v[0] = a;
    v[1] = a;
    v[2] = a;
    v[3] = 1.0f;
    v[4] = b;
    v[5] = b;
    v[6] = b;
    v[7] = 1.0f;
}

typedef struct {
    float min[4];
    float max[4];
} RcBBox;

void rcBBoxSet(RcBBox *box, float (*v)[4], int n)
{
    int i;
    int j;

    func_0018F310((W3Obj20 *)box);
    for (i = 0; i < n; i++) {
        for (j = 0; j < 3; j++) {
            if (box->min[j] > v[i][j]) {
                box->min[j] = v[i][j];
            }
            if (box->max[j] < v[i][j]) {
                box->max[j] = v[i][j];
            }
        }
    }
}

void func_0018F410(float *a, float *out) {
    float *b = a + 4;
    int i;

    for (i = 0; i < 3; i++) {
        out[i] = (a[i] + b[i]) * 0.5f;
    }
}

INCLUDE_ASM("build/ee_asm/game/rc/rcBBox", func_0018F458);

void func_0018F5E8(char *fmt, ...) {
}

void func_0018F610(u64 tex0) {
    func_0018F5E8(D_0056D3B8, (int)(tex0 & 0x3FFF), (int)(tex0 >> 14 & 0x3F), (int)(tex0 >> 20 & 0x3F),
                  (int)(tex0 >> 26 & 0xF), (int)(tex0 >> 30 & 0xF), (int)(tex0 >> 34 & 1), (int)(tex0 >> 35 & 3));
    func_0018F5E8(D_0056D3F0, (int)(tex0 >> 37 & 0x3FFF), (int)(tex0 >> 51 & 0xF), (int)(tex0 >> 55 & 1),
                  (int)(tex0 >> 56 & 0x1F), (int)(tex0 >> 61 & 7));
}

void func_0018F6F8(Rsd *rsd) {
    int i;
    RsdPoly *p;

    func_0018F5E8(D_0056D418);
    func_0018F5E8(D_0056D428, rsd->nvert);
    for (i = 0; i < rsd->nvert; i++) {
        func_0018F5E8(D_0056D438, i, rsd->vert[i][0], rsd->vert[i][1], rsd->vert[i][2]);
    }
    func_0018F5E8(D_0056D448, rsd->nnorm);
    for (i = 0; i < rsd->nnorm; i++) {
        func_0018F5E8(D_0056D438, i, rsd->norm[i][0], rsd->norm[i][1], rsd->norm[i][2]);
    }
    func_0018F5E8(D_0056D458, rsd->npoly);
    p = rsd->poly;
    for (i = 0; i < rsd->npoly; i++, p++) {
        func_0018F5E8(D_0056D468, i, p->type, p->v[0], p->v[1], p->v[2], p->v[3], p->w24);
    }
    func_0018F5E8(D_0056D480);
}

void func_0018F900(OmdH *h) {
    OmdPrimSize size = D_0056D490; /* an initialised local array in the original; its initializer is in the existing rodata */
    OmdPrimName type = D_0056D4E8; /* same */
    OmdPrimH *p = h->prim;
    u8 *data;

    func_0018F5E8(D_0056D508);
    func_0018F5E8(D_0056D518, h->flag);
    func_0018F5E8(D_0056D520, h->pa, h->va, h->na);
    func_0018F5E8(D_0056D538, h->pc, h->vc, h->nc);
    func_0018F5E8(D_0056D550, h->alpha, h->alphafix);
    func_0018F5E8(D_0056D568, h->res[0], h->res[1]);
    func_0018F5E8(D_0056D578, h->vna);
    while (p->flag != -1) {
        func_0018F5E8(D_0056D580);
        func_0018F5E8(D_0056D590, p->flag, type.name[p->ptype]);
        func_0018F5E8(D_0056D5A8, p->pc);
        func_0018F5E8(D_0056D5B0, p->tno, p->timposx);
        func_0018F5E8(D_0056D568, p->res[0], p->res[1]);
        func_0018F5E8(D_0056D5C8, p->tex0[0], p->tex0[1]);
        data = (u8 *)(p + 1); /* primitive data follows the header */
        p = (OmdPrimH *)(data + size.size[p->ptype] * p->pc);
    }
    func_0018F5E8(D_0056D5D8);
}

void func_0018FB10(void) {
}

void func_0018FB18(void) {
}

void func_0018FB20(char *name) {
    if (D_003135B0 == 0) {
        D_003135B0 = func_002ED670(name, D_0056D5E8);
    }
}

void func_0018FB60(void) {
    if (D_003135B0 != 0) {
        func_002ED128(D_003135B0);
        D_003135B0 = 0;
    }
}

void *_rcAlloc(int size, const char *file, int line) {
    return user_malloc(size, 0xB, file, line);
}

void *_rcCalloc(int n, int size, const char *file, int line) {
    int total = n * size;
    void *p = user_malloc(total, 0xB, file, line);

    func_002EF0D0(p, 0, total);
    return p;
}

void func_0018FC10(void *p) {
    func_0011D590((s32)p, 11); /* DEBT(CAST): handle passed as s32 */
}

void *_rcRealloc(void *p, int size, const char *file, int line)
{
    void *q;
    int old;
    int n;

    if (p != 0) {
        old = Sg_MemGetSize(p);
        if (size != old) {
            n = size < old ? size : old;
            q = user_malloc(size, 0xB, file, line);
            func_002EEF1C(q, p, n);
            func_0011D590((s32)p, 0xB); /* DEBT(TYPE): funcs.h takes the block as s32 */
            return q;
        }
        q = p;
    } else {
        q = _rcAlloc(size, file, line);
    }
    return q;
}
