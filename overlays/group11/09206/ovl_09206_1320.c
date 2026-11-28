#include "common.h"

extern void func_01B01550(void *, float *, float *, float *, float *);

typedef struct {
    u8 pad0[4];
    s32 sub_off;
    s32 vtx_off;
    u8 padC[4];
    s16 count;
} ModelHdr;

typedef struct {
    u8 b0;
    s8 type;
    u16 n;
} SubHdr;

typedef struct {
    s16 x;
    s16 y;
    s16 z;
} Vtx3;

typedef struct {
    float u;
    float v;
    float p2;
    float p3;
} UvOut;

void func_01B01320(u8 *base, UvOut *out) {
    float v0[4];
    float v1[4];
    float v2[4];
    float v3[4];
    float dx, dy, scale;
    SubHdr *p;
    Vtx3 *verts;
    s32 count;

    func_01B01550(base, v0, v1, v2, v3);
    dx = v1[0] - v0[0];
    dy = v1[1] - v0[1];
    if (dy < dx) {
        v0[1] -= (dx - dy) * 0.5f;
        scale = dx * 1.2337349653244019f;
    } else {
        v0[0] -= (dy - dx) * 0.5f;
        scale = dy * 1.2337349653244019f;
    }

    p = (SubHdr *)(base + ((ModelHdr *)base)->sub_off);
    verts = (Vtx3 *)(base + ((ModelHdr *)base)->vtx_off);
    count = ((ModelHdr *)base)->count;
    while (count > 0) {
        u8 *t = (u8 *)p + 0x10;
        if (p->type == 3) {
            s32 i;
            for (i = 0; i < (s16)p->n; i++) {
                Vtx3 *va = &verts[*(u16 *)(t + 0xC)];
                Vtx3 *vb = &verts[*(u16 *)(t + 0xE)];
                Vtx3 *vc = &verts[*(u16 *)(t + 0x10)];
                s16 x, y;
                t += 0x28;
                x = va->x;
                y = va->y;
                out->u = ((float)x - v0[0]) / scale;
                out->v = ((float)y - v0[1]) / scale;
                out++;
                x = vb->x;
                y = vb->y;
                out->u = ((float)x - v0[0]) / scale;
                out->v = ((float)y - v0[1]) / scale;
                out++;
                x = vc->x;
                y = vc->y;
                out->u = ((float)x - v0[0]) / scale;
                out->v = ((float)y - v0[1]) / scale;
                out++;
            }
        }
        count -= (s16)p->n;
        p = (SubHdr *)t;
    }
}
