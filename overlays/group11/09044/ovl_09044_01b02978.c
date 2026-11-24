#include "p3_overlay.h"

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
    register P3EdgePart *p __asm__("$6");
    register P3EdgeQuad *q __asm__("$8");
    register int c80 __asm__("$9");
    register int zval __asm__("$10");
    register int a0 __asm__("$11");
    register int a1 __asm__("$14");
    float px;
    float py;

    pkt->d10 = 0x5000000000000001LL;
    pkt->d18 = 0xEEEEE;
    pkt->d30 = ((u8 *)sub)[0xCB];
    pkt->d38 = 0x3B;
    pkt->d40 = 5;
    pkt->d48 = 8;
    pkt->d20 = 0x7000D;
    pkt->d28 = 0x47;
    p = ed->part;
    q = pkt->quad;
    zval = 0xFFFFFF;
    {
        register float f4c __asm__("$f0") = sub->f4C;
        register float f48 __asm__("$f1");
        a1 = (int)f4c;
        pkt->w60 = ((u8 *)sub)[0xC2];
        c80 = 0x80;
        f48 = sub->v40[2];
        a0 = (int)f48;
    }
    px = pos[0];
    py = pos[1];
    pkt->w64 = ((u8 *)sub)[0xC3];
    pkt->w68 = 0x42;
    pkt->d50 = 0x264A21A00LL;
    pkt->d58 = 6;
    {
        register int i __asm__("$5") = 0x73F;
        register int paused __asm__("$4") = th->paused;
        do {
            if (paused == 0) {
                p->t0 += p->dt0;
                if (p->t0 >= 1.0f) {
                    p->t0 = 1.0f;
                }
                p->t1 += p->dt1;
                if (p->t1 >= 1.0f) {
                    p->t1 = 1.0f;
                }
            }
            q->v[0].z = zval;
            q->v[0].f = 0;
            q->v[0].r = c80;
            q->v[0].g = c80;
            q->v[0].b = c80;
            q->v[0].a = a0;
            q->v[1].z = zval;
            q->v[1].f = 0;
            q->v[1].r = c80;
            q->v[1].g = c80;
            q->v[1].b = c80;
            q->v[0].s = (p->u - p->dx) * p->t0 + p->dx;
            q->v[0].t = (p->v - p->dy) * p->t0 + p->dy;
            q->v[0].q = 1.0f;
            {
                register int vx __asm__("$2");
                register int vy __asm__("$3");
                vx = (int)(p->x + px);
                vy = (int)(p->y + py);
                q->v[1].s = p->u;
                q->v[1].t = p->v;
                q->v[1].q = 1.0f;
                vx <<= 4;
                q->v[0].x = vx;
                vy <<= 4;
                q->v[0].y = vy;
                vx = (int)p->x1;
                vy = (int)p->y1;
                vx <<= 4;
                q->v[1].x = vx;
                vy <<= 4;
                q->v[1].y = vy;
            }
            q->v[1].a = a1;
            p++;
            q++;
        } while (--i >= 0);
        i = (u_long128 *)q - (u_long128 *)pkt;
        i += 0x6FFFFFFF;
        pkt->tag = i;
        {
            register u64 hi __asm__("$6") = 0x602CC00000000000LL;
            register int qv __asm__("$3");
            i &= 0xFFFF;
            i -= 7;
            qv = 6;
            qv = (i / qv) | 0x8000;
            pkt->d78 = 0x412412;
            pkt->d70 = hi | qv;
        }
    }
    func_002DA610(0, 0);
    func_002F8660(0);
    func_002DBA28(D_003F395C, pkt);
    func_002DA610(0, 0);
}
