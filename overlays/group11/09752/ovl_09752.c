/* EE Battle-Effect Overlay: group 0x11, file 09752
 * Load base: 0x01B00000, .text: 0x01B00698..0x01B01AF0 (22 functions)
 */
#include "oef_overlay.h"
#include "vu0.h"

typedef struct P52Part {
    u8 pad00[8];
    int cnt;           /* 0x08 */
    u8 pad0C[0x12];
    u16 enabled;       /* 0x1E */
    u8 pad20[0x20];
    union {
        float f[4];
        u_long128 q;
    } position;        /* 0x40 */
    int rotation[3];   /* 0x50 */
    int flag5C;        /* 0x5C */
    float scale[4];    /* 0x60 */
    u8 pad70[0x10];
} P52Part;

typedef struct P52Ent {
    int chr;           /* 0x00 */
    void *hnd;         /* 0x04 */
    int state;         /* 0x08 */
    int dur;           /* 0x0C */
    int cnt;           /* 0x10 */
    short a14;         /* 0x14 */
    short a16;         /* 0x16 */
    u8 pad18[8];
    float m20[12];     /* 0x20 */
    union {
        float f[4];
        u_long128 q;
    } v50;             /* 0x50 */
    union {
        float f[4];
        u_long128 q;
    } v60;             /* 0x60 */
    float pos[4];      /* 0x70 */
    void *p80;         /* 0x80 */
    void *p84;         /* 0x84 */
    u8 pad88[8];
    float v90[4];      /* 0x90 */
    float wid;         /* 0xA0 */
    int cntA4;         /* 0xA4 */
    void *pA8;         /* 0xA8 */
    u8 bAC;            /* 0xAC */
} P52Ent;

typedef struct MdlSub {
    u8 pad00[8];
    int off;           /* 0x08 */
    u8 pad0C[6];
    short n;           /* 0x12 */
} MdlSub;

typedef struct MdlEnt {
    MdlSub *sub;
    void *q;
    u8 pad08[8];
} MdlEnt;

typedef struct Mdl {
    u8 pad00[4];
    u16 cnt;           /* 0x04 */
    u8 pad06[10];
    MdlEnt e[1];       /* 0x10 */
} Mdl;

typedef struct DrawCtx {
    int f00;
    int f04;
    short f08;
    u8 f0A;
    u8 pad0B;
    int f0C;
    long long f10;
    union {
        int w;
        u8 b[4];
    } f18;
    int f1C;
    void *p20;
    void *p24;
    void *p28;
    void *p2C;
    u8 pad30[8];
    int f38;
    int f3C;
    int f40;
    int f44;
    u8 b48[4];
    u8 b4C;
    u8 b4D;
    u8 pad4E[0x22];
} DrawCtx;

extern u8 D_01B00040[];
extern s32 D_00303550;
extern int D_01B00680;
extern int D_01B00684;
extern int D_01B00688;
extern int D_01B01B00;
extern void *D_01B01B04;
extern void *D_01B01B08;
extern OefHeapMgr D_01B01B10;
extern u8 D_01B01B40[];
extern u8 D_01D01B40[];
extern P52Part D_01E01B40[16];
extern P52Part D_01E02340;
extern int D_01E023C0;
extern int D_01E023C4;
extern int D_01E023C8;
extern int D_01E023CC;
extern int D_01E023D0;
extern P52Ent D_01E023E0;
extern OefHeapCfg D_01E024A0;
extern u8 D_01E13880[];

void func_0026BE48(void *mtx, int angle);
void func_002DCE08(void *out, void *m, void *in);
void func_002B2FF0(u32 rgba, int a, int b);
void func_002B2A80(void *p, int a, int b, int c);
void *func_001B4E58(int id);
float func_001B6EA8(int id);
float func_001B63B8(int id);
float func_001B6410(int id);
int func_001CDAF8(int id);
void func_001CDC58(int id, int v);
int func_001CDDD8(int id);
void func_001CE2F0(int h, int v);
int func_001CE050_i(int h, int v) __asm__("func_001CE050");
int func_001CE048(int id);
int func_0029B830_i(int id) __asm__("func_0029B830");
void func_00294B70(void *h, int a, int b);
void func_002944B0(void *res, int a, int b, int c);
void *func_002B49A0(void *res, int a, int b);
void func_002B4980(void *res);
int func_00116068(void);
void func_00107378(void *h, void *m);
void func_002DD0B0(void *dst, void *src);
void func_002DD0C0(void *src, void *dst);
void func_002DD128(void *m);
void func_002DD020(float *d, float *a, float *b);
void *func_002B3888(int n);
void func_002B39C0(int n);
void func_002C9B78(void *sub, void *ctx);
void func_002B7CE8(void *h, void *c, void *m, void *a, void *b, void *s2, void *s1, float f);
void *func_002A3BD8_v(void *h, void *b) __asm__("func_002A3BD8");
void func_001B57F0_v(int chr, int v) __asm__("func_001B57F0");
void func_0010D380(void *h, int a, int b);
void func_0010D3A8(void *h, int a, int b);
void func_0010D4A0(void *h, int a);
void func_0010D4D8_v(void *h, int a) __asm__("func_0010D4D8");
void func_001178E0(void *h);
void func_00117A68(void *h);
int func_002A3B48(void *h);
void func_00110830(void *h, void *m);
int func_002A7120_v(void *h, int a, int b) __asm__("func_002A7120");
void func_002A7308_v(void *a, void *b, int c, int d) __asm__("func_002A7308");
void *func_00266FA0(void *mgr, void *sub, int size);
float func_001ACED8(void);
void func_001B6790(int chr, float *pos);
void op_chara_hsv_v(void *chr, void *buf, int a, int b, int c, int d) __asm__("op_chara_hsv");

void func_01B00698(int cur, int start, int in, int hold_end, int out, u32 color, int max, int prio)
{
    int t = cur - start;
    int total;
    int alpha;

    if (t > 0) {
        hold_end -= start;
        total = hold_end + out;
        if (t < total) {
            if (t <= in) {
                alpha = t * max / in;
            } else if (t > hold_end) {
                alpha = (total - t) * max / out;
            } else {
                alpha = max;
            }
            func_002B2FF0(color | (alpha << 24), 0x44, 0);
        }
    }
}

void func_01B00720(int cur, int start, int fin, int fout, u8 r, u8 g, u8 b, int prio)
{
    int t = cur - start;
    register int total __asm__("$8");
    u8 alpha;
    register int pr __asm__("$24") = prio;
    register int rr __asm__("$11") = r;
    unsigned long long col;
    register unsigned long long *p __asm__("$15");

    if (t > 0) {
        total = fin + fout;
        if (t < total) {
            p = (unsigned long long *)D_006A3BCC;
            D_006A3BCC = (u8 *)p + 0x60;
            if (t <= fin) {
                alpha = (t << 7) / fin;
            } else {
                t = total - t;
                alpha = (t << 7) / fout;
            }
            col = (((unsigned long long)alpha << 24) | (((unsigned long long)b << 16) | ((unsigned long long)g << 8))) | (unsigned long long)rr;
            ((unsigned long long *)p)[2] = 0x4023400000008001ULL;
            ((unsigned long long *)p)[3] = 21998;
            ((unsigned long long *)p)[4] = pr;
            ((unsigned long long *)p)[5] = 66;
            ((unsigned long long *)p)[6] = col;
            ((unsigned long long *)p)[7] = 1;
            ((int *)p)[16] = 0x7000;
            ((int *)p)[17] = 0x7300;
            ((int *)p)[20] = 0x9000;
            ((int *)p)[21] = 0x8d00;
            ((int *)p)[18] = 0xffff00;
            ((int *)p)[22] = 0xffff00;
            ((int *)p)[19] = 0;
            ((int *)p)[23] = 0;
            func_002B2A80(p, 6, 1, 0);
        }
    }
}

P52Part *func_01B00830(P52Part *p, int n)
{
    do {
        if (p->enabled == 0) {
            return p;
        }
        p++;
    } while (--n);
    return 0;
}

void func_01B00858(float *out, float len, int angle)
{
    float m[16];
    float z;
    float one;

    func_0026BE48(m, -angle);
    one = 1.0f;
    z = 0.0f;
    out[0] = len;
    out[2] = z;
    out[1] = z;
    out[3] = one;
    func_002DCE08(out, m, out);
}

void func_01B008C0(void *res)
{
    void **p0 = &D_01B01B04;
    void **p1 = &D_01B01B08;

    func_002B4980(res);
    func_002D02E8(res, 0, 1000, 0x100);
    func_002944B0(res, 0, 1000, 0x100);
    *p0 = func_002B49A0(res, 6, 0);
    *p1 = func_002B49A0(res, 6, 1);
}

int MsSetChrVisible(int id, int b);

void func_01B00950(P52Ent *e, int vis)
{
    if (e->chr != 255) {
        MsSetChrVisible(e->chr, vis);
    }
}

void func_01B00970(P52Ent *e, int chr)
{
    int v;
    volatile int pad[4];

    e->chr = chr;
    if (chr != 255) {
        e->hnd = func_001B4E58(e->chr);
        func_00107378(e->hnd, e->m20);
        v = (int)(func_001B6EA8(e->chr) * 32768.0f / 3.1415927f);
        e->a16 = v;
        e->a14 = v;
        func_001B6790(e->chr, e->pos);
        func_002DD0B0(&e->v60, e->pos);
        func_002DD0B0(e->v90, e->pos);
        e->v90[1] -= func_001B63B8(e->chr) * 0.25f;
        e->wid = func_001B6410(e->chr);
        e->bAC = 0x80;
    }
}

void func_01B00A58(P52Ent *e, int state)
{
    if (e->chr != 255) {
        e->cnt = 0;
        e->state = state;
        e->dur = func_001CE050_i(e->chr, state);
    }
}

void func_01B00A98(P52Ent *e)
{
    e->v50.q = e->v60.q;
}

void func_01B00AA8(void *hnd, void *buf, int cur, int start, int dur, int v0, int v1)
{
    int t = cur - start;
    int val;

    if (t > 0 && t <= dur) {
        val = (v1 - v0) * t / dur + v0;
        op_chara_hsv_v(hnd, buf, 0, -val, val, 0);
        D_01E023E0.bAC = -0x80 - (t << 7) / dur;
    }
}

void func_01B00B40(Mdl *m, float *mtx, float *ref, float *out_, float k0, float k1)
{
    register float *out __asm__("$22") = out_;
    register MdlEnt *e __asm__("$17") = m->e;
    register int i __asm__("$18") = m->cnt - 1;
    register float *w __asm__("$19");
    MdlSub *sub;
    float *src;
    float *p40;
    float *p50;
    float *p60;
    float *q;
    register int n __asm__("$16");
    int tmp;
    float len;
    MdlEnt *en;
    int i2;

    w = func_002B3888(0x80);
    while (i != -1) {
        sub = e->sub;
        q = e->q;
        n = sub->n;
        src = (float *)((u8 *)sub + sub->off);
        __asm__ volatile(
            "lqc2 $vf28, 0x00(%1)\n"
            "lqc2 $vf29, 0x10(%1)\n"
            "lqc2 $vf30, 0x20(%1)\n"
            "lqc2 $vf31, 0x30(%1)\n"
            "lqc2 $vf24, 0x00(%2)\n"
            "lqc2 $vf25, 0x10(%2)\n"
            "lqc2 $vf26, 0x20(%2)\n"
            "lqc2 $vf27, 0x30(%2)\n"
            "vmulax.xyzw ACC, $vf28, $vf24x\n"
            "vmadday.xyzw ACC, $vf29, $vf24y\n"
            "vmaddaz.xyzw ACC, $vf30, $vf24z\n"
            "vmaddw.xyzw $vf24, $vf31, $vf24w\n"
            "vmulax.xyzw ACC, $vf28, $vf25x\n"
            "vmadday.xyzw ACC, $vf29, $vf25y\n"
            "vmaddaz.xyzw ACC, $vf30, $vf25z\n"
            "vmaddw.xyzw $vf25, $vf31, $vf25w\n"
            "vmulax.xyzw ACC, $vf28, $vf26x\n"
            "vmadday.xyzw ACC, $vf29, $vf26y\n"
            "vmaddaz.xyzw ACC, $vf30, $vf26z\n"
            "vmaddw.xyzw $vf26, $vf31, $vf26w\n"
            "vmulax.xyzw ACC, $vf28, $vf27x\n"
            "vmadday.xyzw ACC, $vf29, $vf27y\n"
            "vmaddaz.xyzw ACC, $vf30, $vf27z\n"
            "vmaddw.xyzw $vf27, $vf31, $vf27w\n"
            "sqc2 $vf24, 0x00(%0)\n"
            "sqc2 $vf25, 0x10(%0)\n"
            "sqc2 $vf26, 0x20(%0)\n"
            "sqc2 $vf27, 0x30(%0)\n"
            : : "r"(w), "r"(mtx), "r"(q) : "memory");
        i2 = i - 1;
        if (--n != -1) {
            en = e + 1;
            p40 = w + 16;
            p50 = w + 20;
            p60 = w + 24;
            do {
                VU0_LQC2(27, 0x00, src);
                VU0_LQC2(28, 0x00, w);
                VU0_LQC2(29, 0x10, w);
                VU0_LQC2(30, 0x20, w);
                VU0_LQC2(31, 0x30, w);
                VU0_OP("vmulax.xyzw ACC, $vf28, $vf27x");
                VU0_OP("vmadday.xyzw ACC, $vf29, $vf27y");
                VU0_OP("vmaddaz.xyzw ACC, $vf30, $vf27z");
                VU0_OP("vmaddw.xyzw $vf26, $vf31, $vf0w");
                VU0_SQC2(26, 0x00, p40);
                func_002DD038(p50, p40, ref);
                VU0_LQC2(10, 0x00, p50);
                VU0_OP("vadd.xyz $vf8, $vf0, $vf10");
                VU0_OP("vmul.xyz $vf10, $vf10, $vf10");
                VU0_OP("vmove.xyz $vf9, $vf10");
                VU0_OP("vaddx.y $vf9, $vf9, $vf9x");
                VU0_OP("vaddy.z $vf9, $vf9, $vf9y");
                VU0_OP(".word 0x4B0903BD");
                VU0_OP("vwaitq");
                VU0_OP("vaddq.x $vf10, $vf0, Q");
                VU0_QMFC2(tmp, 10);
                VU0_OP(".word 0x4A6A03BC");
                VU0_OP("vwaitq");
                VU0_OP("vmulq.xyz $vf9, $vf8, Q");
                VU0_SQC2(9, 0x00, p60);
                __asm__("mtc1 %1, %0" : "=f"(len) : "r"(tmp));
                w[28] = len;
                VU0_QMTC2(9, k0);
                VU0_LQC2(10, 0x00, p60);
                VU0_OP("vmulx.xyz $vf10, $vf10, $vf9x");
                VU0_SQC2(10, 0x00, p60);
                func_002DCFF8(p40, p60, p50, k1);
                src += 4;
                __asm__("" : : "r"(i2), "r"(en));
                func_002DD020(out, p40, ref);
                out += 4;
            } while (--n != -1);
        }
        else {
            en = e + 1;
        }
        e = en;
        i = i2;
    }
    func_002B39C0(0x80);
}

void func_01B00D78(Mdl *m, DrawCtx *c, int base)
{
    MdlEnt *e = m->e;
    int i = m->cnt;
    void *buf = func_002B3888(0x40);

    c->p20 = buf;
    func_002DCE38(buf, D_006A3A70, D_006A3970);
    for (i--; i != -1; i--) {
        MdlSub *sub = e->sub;

        c->f38 = base;
        e++;
        base += sub->n << 4;
        func_002C9B78(sub, c);
    }
    func_002B39C0(0x40);
}

int func_01B00E30(Mdl *m)
{
    MdlEnt *e;
    int i = m->cnt;
    int sum = 0;

    i--;
    __asm__("" : "+r"(i));
    if (i != -1) {
        e = m->e;
        do {
            sum += e->sub->n;
            e++;
        } while (--i != -1);
    }
    return sum;
}

void func_01B00E78(P52Part *o, int id,
    float x, float y, float z, float rx, float ry, float rz,
    float sx, float sy, float sz)
{
    D_006A3924 = &D_01B01B10;
    _pppStartPart((OefPartObj *)o, 0x1000, D_01E024A0.pdt[id], 1);
    o->rotation[0] = (int)rx;
    o->rotation[1] = (int)ry;
    o->position.f[0] = x;
    o->rotation[2] = (int)rz;
    o->position.f[1] = y;
    o->position.f[2] = z;
    o->scale[0] = sx;
    o->scale[1] = sy;
    o->scale[2] = sz;
    o->position.f[3] = 1.0f;
    o->enabled = 1;
    o->flag5C = 1;
    o->scale[3] = 1.0f;
}

void func_01B00F88(P52Part *o)
{
    if (o->enabled != 0) {
        pppSetMatrix((OefPartObj *)o);
        func_002DCE38(D_006A39B0, D_006A3970, D_006A3930);
        func_002DCE38(D_006A3AB0, D_006A3A70, D_006A39B0);
        D_006A3924 = &D_01B01B10;
        if (_pppRunPart((OefPartObj *)o, 0x30) != 0) {
            o->enabled = 0;
        }
    }
}

int func_01B01020(int eff_id)
{
    D_01B01B00 = eff_id;
    D_01E023C4 = func_001CE048(eff_id);
    func_01B00970(&D_01E023E0, D_01E023C4);
    D_01E023C0 = D_01E023C8 = 0;
    func_01B008C0(D_01E13880);
    _pppInitData(&D_01E024A0, D_01B00040);
    pppInitEnv(&D_01B01B10, &D_01E024A0, D_01B01B40, 0x200000);
    return 0;
}

int func_01B010B8(void)
{
    return 0;
}

int func_01B010C0(void)
{
    return 0;
}

int func_01B010C8(void)
{
    u32 n;
    P52Part *p;
    float s;
    float a;
    float b;
    float v[4];
    volatile int pad[4];
    float pv[4];
    float t;
    float tt;
    float u;
    int sz;

    if (D_01B00680 == 0) {
        if (func_0029B830_i(D_01B01B00) != 0) {
            return 0;
        }
        D_01B00680++;
    }
    if (D_01B00684 == 0) {
        D_01B00684 = 1;
        func_001CDC58(D_01B01B00, 0);
    }
    if (D_01B00688 == 0) {
        if (func_001CDAF8(D_01B01B00) > 0) {
            D_01B00688 += 1;
        } else {
            __asm__ volatile("");
            return 0;
        }
    }
    if (func_00116068() == 0) {
        D_006A3BC4 = 1;
    } else {
        D_006A3BC4 = 0;
    }
    if (D_006A3BC4 != 0) {
        return D_006A3BC4;
    }
    if (D_01E023C0 == 0) {
        func_001B57F0_v(D_01E023C4 + 1, 0);
        func_001B57F0_v(D_01E023C4 + 2, 0);
        func_0010D380(D_01E023E0.hnd, -1, 0x3C00);
        func_0010D3A8(D_01E023E0.hnd, -1, 0x2EE0);
        sz = func_002A7120_v(D_01E023E0.hnd, 1, 1);
        D_01E023E0.p80 = func_00266FA0(&D_01B01B10, &D_01B01B10.sub, sz + 0x400);
        func_002A7308_v(D_01E023E0.p80, D_01E023E0.hnd, 1, 0);
        D_01E023E0.cntA4 = func_01B00E30(D_01E023E0.p80);
        D_01E023E0.p84 = func_00266FA0(&D_01B01B10, &D_01B01B10.sub, (D_01E023E0.cntA4 << 4) + 0x400);
        func_01B00950(&D_01E023E0, 0);
        func_00117A68(D_01E023E0.hnd);
        D_01E023E0.pA8 = func_00266FA0(&D_01B01B10, &D_01B01B10.sub, func_002A3B48(D_01E023E0.hnd) + 0x400);
        func_00110830(D_01E023E0.hnd, D_01E023E0.m20);
        func_00294B70(D_01B01B04, 64, 256);
    }
    func_002A3BD8_v(D_01E023E0.hnd, D_01E023E0.pA8);
    func_01B00AA8(D_01E023E0.hnd, D_01E023E0.pA8, D_01E023C0, 120, 150, 0, 255);
    if (D_01E023C0 == 0) {
        func_01B00A58(&D_01E023E0, 0x48);
    }
    n = D_01E023C0;
    if (n < 370) {
        t = (float)n / (t = 370.0f);
        func_01B00858(v, t * 200.0f, D_01E023E0.a16 + 0x8000);
        t = t * 100.0f;
        D_01E023E0.v60.f[0] = D_01E023E0.v90[0] = D_01E023E0.pos[0] + v[0];
        D_01E023E0.v60.f[2] = D_01E023E0.v90[2] = D_01E023E0.pos[2] + v[2];
        D_01E023E0.v60.f[1] = D_01E023E0.v90[1] = D_01E023E0.pos[1] - t;
    }
    func_01B00A98(&D_01E023E0);
    if (D_01E023E0.state == 0x48 && D_01E023E0.cnt == D_01E023E0.dur) {
        func_01B00A58(&D_01E023E0, 0x49);
    }
    if (D_01E023C0 < 0xDC) {
        func_01B00B40(D_01E023E0.p80, D_01E023E0.m20, D_01E023E0.v90, D_01E023E0.p84, 0.0f, 0.0f);
    } else if ((u32)(D_01E023C0 - 0xDC) < 0xB4) {
        u = (float)(u32)(D_01E023C0 - 0xDC) / 180.0f;
        tt = u + u;
        if (1.0f < tt) {
            tt = 1.0f;
        }
        func_01B00B40(D_01E023E0.p80, D_01E023E0.m20, D_01E023E0.v90, D_01E023E0.p84, D_01E023E0.wid * (1.0f - u * u), tt);
    }
    n = D_01E023C0;
    if (n < 0x163 && (n & 7) == 0) {
        p = func_01B00830(D_01E01B40, 16);
        if (p != 0) {
            a = func_001ACED8() - 1.0f;
            *(u_long128 *)pv = ((u_long128 *)D_01E023E0.p84)[(int)(a * (float)D_01E023E0.cntA4)];
            s = func_001ACED8() - 1.0f;
            s = s * 65536.0f;
            b = func_001ACED8() - 1.0f;
            b = b * 0.075f + 0.15f;
            func_01B00E78(p, 0, pv[0], pv[1], pv[2], 0.0f, s, 0.0f, b, b, b);
        }
    }
    if (D_01E023C0 == 0x172) {
        func_00294B70(D_01B01B08, 64, 256);
        func_01B00E78(&D_01E02340, 1, D_01E023E0.v90[0], D_01E023E0.v90[1], D_01E023E0.v90[2],
            0.0f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f);
    }
    if (D_006A3BC4 == 0) {
        D_01E023E0.cnt++;
    }
    return 0;
}

int func_01B01650(void)
{
    DrawCtx c;
    float mi[16];
    float mv[16];
    float m1[16];
    float m2[16];
    float m3[16];
    float mr[16];
    void *s2;
    int i;
    int n;
    P52Part *p;
    float ra;
    float rb;
    float kk;

    if (D_01B00688 == 0 || D_01E023C0 < 0) {
        goto out;
    }
    D_006A3BCC = D_01D01B40;
    D_006A3924 = &D_01B01B10;
    func_001AACA0(D_006A3A70);
    func_001A9EE0(D_006A3970);
    func_01B00698(D_01E023C0, 0, 90, 460, 90, 0, 0x58, 0x44);
    func_0010D4A0(D_01E023E0.hnd, -1);
    func_0010D4D8_v(D_01E023E0.hnd, -1);
    func_002DD0C0(mi, D_01E023E0.m20);
    func_002DCE38(mv, D_006A3970, mi);
    func_002DCE38(mv, D_006A3A70, mv);
    c.f18.w = 0x80808080;
    c.f00 = 0x1C;
    c.f08 = 0x44;
    c.f1C = 0x808080;
    c.f04 = D_00303550;
    c.f0A = 0;
    c.f3C = 0;
    c.f38 = 0;
    c.f0C = 0;
    c.f10 = 0;
    c.f40 = 0;
    func_002DD128(m1);
    func_002DD128(m2);
    func_002DD128(m3);
    c.p24 = m1;
    c.p28 = m2;
    c.p2C = m3;
    c.b4C = D_01E023E0.bAC;
    c.f44 = 0;
    c.b4D = 0;
    if (D_01E023C0 < 0x191) {
        func_01B00D78(D_01E023E0.p80, &c, (int)D_01E023E0.p84);
    }
    s2 = func_002B49A0(D_01E13880, 2, 0);
    func_0026BDE0(mr, D_01E023C0 << 10);
    c.f18.w = 0x80000080;
    if (D_01E023C0 >= 0xF) {
        if (D_01E023C0 < 0x69) {
            n = D_01E023C0 - 0xF;
            c.f18.b[3] = (u32)(n << 7) / 0x5A;
        } else if (D_01E023C0 < 0x78) {
            c.f18.b[3] = 0x80;
        } else {
            n = D_01E023C0 - 0x78;
            if ((u32)n >= 0x64) {
                goto skip;
            }
            c.f18.b[3] = (u32)((0x64 - n) << 7) / 0x64;
        }
        c.f04 = D_00303550;
        c.p20 = mv;
        c.f3C = 0;
        c.f38 = 0;
        func_002B7CE8(D_01E023E0.p80, &c, mi, D_006A3970, D_006A3A70, s2, mr, 0.0f);
    }
skip:
    n = D_01E023C0 - 0xBE;
    if ((u32)n < 0xB4) {
        if (D_01E023C8 == 0) {
            if ((u32)n < 0x96) {
                D_01E023CC = n;
                kk = 20.0f;
                ra = func_001ACED8();
                rb = ra - 1.0f;
                D_01E023D0 = (int)(rb * kk + 10.0f);
                ra = func_001ACED8();
                rb = ra - 1.0f;
                kk = rb * kk;
                kk = kk + (float)D_01E023D0;
                D_01E023C8 = (int)kk;
            }
        }
        D_01E023C8--;
        func_01B00720(n, D_01E023CC, 1, D_01E023D0, 255, 255, 255, 0x44);
    }
    p = D_01E01B40;
    for (i = 16; i != 0; i--, p++) {
        if (p->enabled != 0) {
            func_01B00F88(p);
        }
    }
    func_01B00F88(&D_01E02340);
    func_01B00720(D_01E023C0, 0x172, 1, 12, 255, 255, 255, 0x44);
    if (D_01E023C0 >= 0x173 && D_01E02340.enabled == 0) {
        func_0010D380(D_01E023E0.hnd, -1, -1);
        func_0010D3A8(D_01E023E0.hnd, -1, -1);
        func_001178E0(D_01E023E0.hnd);
        func_00110830(D_01E023E0.hnd, 0);
        func_001B57F0_v(D_01E023E0.chr, 0);
        func_001CE2F0(D_01E023E0.chr, 0);
        func_001CDDD8(D_01B01B00);
    }
    if (D_006A3BC4 != 0) {
out:
        return 0;
    }
    {
        register int c2 __asm__("$3");
        c2 = D_01E023C0;
        D_01E023C0 = c2 + 1;
    }
    return 0;
}

int func_01B01AE0(void)
{
    return 0;
}

void func_01B01AE8(void)
{
}
