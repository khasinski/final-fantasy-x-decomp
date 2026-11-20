#include "common.h"

typedef struct {
    s16 h00;
    u16 h02;
    u8 pad04[4];
} SprFrame;

typedef struct {
    u8 pad00[4];
    s16 h04;
} SprHdr;

typedef struct {
    SprHdr *hdr;
    SprFrame *frame;
    s16 idx;
    u8 pad0a[2];
    void *cur;
    s16 timer;
    u8 pad12[0xE];
    float pos[4];
    float scale;
    float rot;
    u8 r;
    u8 pad39[3];
    u8 g;
    u8 pad3d[3];
    u8 b;
    u8 pad41[3];
    float alpha;
} SprObj;

typedef struct {
    u8 pad00[4];
    u8 r;
    u8 g;
    u8 b;
    u8 a;
    u8 pad08[8];
    void *m0;
    void *p14;
    u8 pad18[4];
    void *m1;
} SprDraw;

extern float D_01B02030[4][4];
extern float D_01B02070[4][4];
extern float D_01B020B0[4][4];
extern float D_01B020F0[4][4];

extern void func_001A9EE0(void *);
extern void func_001AACA0(void *);
extern void func_002B57D0(void *, float);
extern void func_002CD590(void *, void *);
extern void func_002DCE08(void *, void *, void *);
extern void func_002DCE38(void *, void *, void *);
extern void func_002DD0C0(void *, void *);
extern void func_002DD128(void *);
extern void func_002DD1C8(void *, void *, float);

void func_01B014A8(SprObj *s, SprDraw *d, void *a2, float f0)
{
    float m0[4][4];
    float m1[4][4];

    func_001AACA0(m1);
    func_001A9EE0(m0);
    func_002DD128(D_01B02030);
    func_002DD128(D_01B020B0);
    func_002DD128(D_01B020F0);
    func_002B57D0(D_01B02030, s->scale);
    func_002DCE38(D_01B02030, D_01B020F0, D_01B02030);
    func_002DD1C8(D_01B02030, D_01B02030, s->rot);
    func_002DCE38(D_01B02030, D_01B020B0, D_01B02030);
    func_002DCE08(D_01B02030[3], m0, s->pos);
    func_002DD0C0(D_01B02070, D_01B02030);
    D_01B02070[3][2] -= f0;
    func_002DCE38(D_01B02070, m1, D_01B02070);
    func_002DCE38(D_01B02030, m1, D_01B02030);
    d->m0 = D_01B02030;
    d->m1 = D_01B02070;
    s->timer -= 0x200;
    if (s->timer == 0) {
        SprFrame *f;
        s->idx++;
        if (s->idx >= s->hdr->h04) {
            s->idx = 0;
        }
        f = (SprFrame *)((u8 *)s->hdr + (s->idx * 8 + 0x10));
        s->frame = f;
        s->cur = (void *)(f->h00 + (u32)s->hdr);
        s->timer += f->h02;
    }
    d->r = s->r;
    d->g = s->g;
    d->b = s->b;
    d->a = (u8)(int)(s->alpha * 127.0f);
    d->p14 = a2;
    func_002CD590(s->cur, d);
}
