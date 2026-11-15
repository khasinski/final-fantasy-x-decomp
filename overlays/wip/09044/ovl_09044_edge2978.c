/* WIP (p3, TU rank 11 function 2, file09044 0x01B02978..0x01B02C24, 131 containers). NOT MATCHING.
 * Same size; remaining ~60 lines are scheduling in the GIF-tag prologue (constant order 8/0x3B/5),
 * the loop counter's register (target reuses a1 after the last ScriptSub read), and the XYZ
 * conversions in the loop tail. */
#include "p3_overlay.h"

/* GS STQ / RGBAQ / XYZF2 vertex as packed by the edge strip (0x30 bytes). */
typedef struct P3EdgeVtx {
    float s, t, q;
    int pad0C;
    int r, g, b, a;
    int x, y, z, f;
} P3EdgeVtx;

typedef struct P3EdgeQuad {
    P3EdgeVtx v[2];
} P3EdgeQuad;

typedef struct P3EdgePkt {
    u64 tag;            /* 0x00 */
    u64 d08;
    u64 d10;
    u64 d18;
    u64 d20;
    u64 d28;
    u64 d30;
    u64 d38;
    u64 d40;
    u64 d48;
    u64 d50;
    u64 d58;
    int w60;
    int w64;
    int w68;
    int pad6C;
    u64 d70;
    u64 d78;
    P3EdgeQuad quad[0x740];     /* 0x80 */
} P3EdgePkt;

typedef struct P3EdgeOwner {
    u8 pad00[0x212];
    s16 paused;         /* 0x212 */
} P3EdgeOwner;

extern void *D_003F395C;

int func_002DA610(int a, int b);
void func_002F8660(int a);
void func_002DBA28(void *a, void *pkt);

void func_01B02978(P3EdgeOwner *th, ScriptSub *sub, P3Edge *ed, float *pos, P3EdgePkt *pkt)
{
    P3EdgePart *p;
    P3EdgeQuad *q;
    int i;
    int a0;
    int a1;
    float px;
    float py;

    pkt->d10 = 0x5000000000000001LL;
    pkt->d18 = 0xEEEEE;
    pkt->d30 = ((u8 *)sub)[0xCB]; /* DEBT(CAST): alpha byte of ScriptSub.wC8 */
    pkt->d48 = 8;
    pkt->d38 = 0x3B;
    pkt->d40 = 5;
    pkt->d20 = 0x7000D;
    pkt->d28 = 0x47;
    a1 = sub->f4C;
    pkt->w60 = ((u8 *)sub)[0xC2]; /* DEBT(CAST): bytes of ScriptSub.hC2 */
    a0 = sub->v40[2];
    pkt->w64 = ((u8 *)sub)[0xC3];
    pkt->w68 = 0x42;
    pkt->d50 = 0x264A21A00LL;
    pkt->d58 = 6;
    p = ed->part;
    q = pkt->quad;
    px = pos[0];
    py = pos[1];
    for (i = 0; i < 0x740; i++) {
        if (th->paused == 0) {
            p->t0 += p->dt0;
            if (p->t0 >= 1.0f) {
                p->t0 = 1.0f;
            }
            p->t1 += p->dt1;
            if (p->t1 >= 1.0f) {
                p->t1 = 1.0f;
            }
        }
        q->v[0].z = 0xFFFFFF;
        q->v[0].f = 0;
        q->v[0].r = 0x80;
        q->v[0].g = 0x80;
        q->v[0].b = 0x80;
        q->v[0].a = a0;
        q->v[1].z = 0xFFFFFF;
        q->v[1].f = 0;
        q->v[1].r = 0x80;
        q->v[1].g = 0x80;
        q->v[1].b = 0x80;
        q->v[0].s = (p->u - p->dx) * p->t0 + p->dx;
        q->v[0].t = (p->v - p->dy) * p->t0 + p->dy;
        q->v[0].q = 1.0f;
        q->v[0].y = (int)(p->y + py) << 4;
        q->v[1].s = p->u;
        q->v[0].x = (int)(p->x + px) << 4;
        q->v[1].t = p->v;
        q->v[1].q = 1.0f;
        q->v[1].x = (int)p->x1 << 4;
        q->v[1].y = (int)p->y1 << 4;
        q->v[1].a = a1;
        p++;
        q++;
    }
    i = ((u_long128 *)q - (u_long128 *)pkt) + 0x6FFFFFFF;
    pkt->tag = i;
    pkt->d70 = (((i & 0xFFFF) - 7) / 6 | 0x8000) | 0x602CC00000000000LL;
    pkt->d78 = 0x412412;
    func_002DA610(0, 0);
    func_002F8660(0);
    func_002DBA28(D_003F395C, pkt);
    func_002DA610(0, 0);
}
