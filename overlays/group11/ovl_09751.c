/* EE Battle-Effect Overlay: group 0x11, file 09751
 * Load base: 0x01B00000, .text: 0x01B00698..0x01B00F08 (14 functions)
 */
#include "../oef_overlay.h"

typedef struct P51Part {
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
} P51Part;

typedef struct P51Ent {
    int chr;           /* 0x00 */
    void *hnd;         /* 0x04 */
    int state;         /* 0x08 */
    int dur;           /* 0x0C */
    int cnt;           /* 0x10 */
    short a14;         /* 0x14 */
    short a16;         /* 0x16 */
} P51Ent;

extern u8 D_01B00040[];
extern int D_01B00680;
extern int D_01B00684;
extern int D_01B00688;
extern int D_01B00F40;
extern void *D_01B00F44;
extern OefHeapMgr D_01B00F48;
extern u8 D_01B00F80[];
extern u8 D_01C00F80[];
extern P51Part D_01D00F80[16];
extern int D_01D01780;
extern int D_01D01784;
extern P51Ent D_01D01788;
extern OefHeapCfg D_01D017B0;
extern u8 D_01D12B90[];

void func_0026BE48(void *mtx, int angle);
void func_002DCE08(void *out, void *m, void *in);
void *func_001B4E58(int id);
float func_001B6EA8(int id);
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
void func_00110BC8(void *h, int a, int b);
float func_001ACED8(void);
void func_00267658(void *o, int a, int b, int c);

P51Part *func_01B00698(P51Part *p, int n)
{
    do {
        if (p->enabled == 0) {
            return p;
        }
        p++;
    } while (--n);
    return 0;
}

void func_01B006C0(float *out, float len, int angle)
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

void func_01B00728(void *res)
{
    void **p0 = &D_01B00F44;

    func_002B4980(res);
    func_002D02E8(res, 0, 1000, 0x100);
    func_002944B0(res, 0, 1000, 0x100);
    *p0 = func_002B49A0(res, 6, 0);
}

void func_01B00798(P51Ent *e, int chr)
{
    int v;
    volatile int pad[4];

    e->chr = chr;
    if (chr != 255) {
        e->hnd = func_001B4E58(e->chr);
        v = (int)(func_001B6EA8(e->chr) * 32768.0f / 3.1415927f);
        e->a16 = v;
        e->a14 = v;
    }
}

void func_01B00810(P51Ent *e, int state)
{
    if (e->chr != 255) {
        e->cnt = 0;
        e->state = state;
        e->dur = func_001CE050_i(e->chr, state);
    }
}

void func_01B00850(P51Part *o, int id,
    float x, float y, float z, float rx, float ry, float rz,
    float sx, float sy, float sz)
{
    D_006A3924 = &D_01B00F48;
    _pppStartPart((OefPartObj *)o, 0x1000, D_01D017B0.pdt[id], 1);
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

void func_01B00960(P51Part *o)
{
    if (o->enabled != 0) {
        pppSetMatrix((OefPartObj *)o);
        func_002DCE38(D_006A39B0, D_006A3970, D_006A3930);
        func_002DCE38(D_006A3AB0, D_006A3A70, D_006A39B0);
        D_006A3924 = &D_01B00F48;
        if (_pppRunPart((OefPartObj *)o, 0x30) != 0) {
            o->enabled = 0;
        }
    }
}

int func_01B009F8(int eff_id)
{
    D_01B00F40 = eff_id;
    D_01D01784 = func_001CE048(eff_id);
    func_01B00798(&D_01D01788, D_01D01784);
    D_01D01780 = 0;
    func_01B00728(D_01D12B90);
    _pppInitData(&D_01D017B0, D_01B00040);
    pppInitEnv(&D_01B00F48, &D_01D017B0, D_01B00F80, 0x100000);
    return 0;
}

int func_01B00A88(void)
{
    return 0;
}

int func_01B00A90(void)
{
    return 0;
}

int func_01B00A98(void)
{
    unsigned n;
    P51Part *p;
    float s;
    float a;
    float r4;
    float k;
    float b;
    float v[4];

    if (D_01B00680 == 0) {
        if (func_0029B830_i(D_01B00F40) != 0) {
            return 0;
        }
        D_01B00680++;
    }
    if (D_01B00684 == 0) {
        D_01B00684 = 1;
        func_001CDC58(D_01B00F40, 0);
    }
    if (D_01B00688 == 0) {
        if (func_001CDAF8(D_01B00F40) > 0) {
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
    if (D_01D01780 == 0) {
        func_01B00810(&D_01D01788, 200);
        func_00110BC8(D_01D01788.hnd, 0, 0);
        func_00110BC8(D_01D01788.hnd, 3, 0);
    }
    switch (D_01D01788.state) {
    case 200:
        if (D_01D01788.cnt == D_01D01788.dur) {
            func_01B00810(&D_01D01788, 201);
        }
        break;
    case 201:
        if (D_01D01788.cnt == 90) {
            func_01B00810(&D_01D01788, 202);
        }
        break;
    case 202:
        break;
    }
    n = D_01D01780 - 5;
    if (n < 300 && (n & 7) == 0) {
        p = func_01B00698(D_01D00F80, 16);
        if (p != 0) {
            a = func_001ACED8() - 1.0f;
            a = a * 1000.0f + 5000.0f;
            s = func_001ACED8() - 1.0f;
            s = s * 65536.0f;
            func_01B006C0(v, a, (int)s);
            v[1] = v[0];
            a = func_001ACED8() - 1.0f;
            v[0] = a * 25000.0f;
            b = func_001ACED8() - 1.0f; b = 0.15f + b * 0.075f;
            func_01B00850(p, 0, v[0], v[1], v[2], 0.0f, s, 0.0f, b, b, b);
        }
        if (n == 0) {
            func_00294B70(D_01B00F44, 64, 256);
        }
    }
    if (D_006A3BC4 == 0) {
        D_01D01788.cnt++;
    }
    return 0;
}

int func_01B00D80(void)
{
    float m[16];
    union { float f[4]; u_long128 q; } t;
    P51Part *p;
    int i;

    if (D_01B00688 == 0 || D_01D01780 < 0) {
        __asm__ volatile("");
        return 0;
    }
    D_006A3BCC = D_01C00F80;
    D_006A3924 = &D_01B00F48;
    func_001AACA0(D_006A3A70);
    func_001A9EE0(D_006A3970);
    i = 16;
    p = D_01D00F80;
    func_001072F8(D_01D01788.hnd, 6, m);
    for (; i != 0; i--, p++) {
        if (p->enabled != 0) {
            t.q = p->position.q;
            func_002DCE08(&p->position, m, &t);
            func_01B00960(p);
            p->position.q = t.q;
        }
    }
    if (D_01D01788.state == 202 && D_01D01788.cnt == D_01D01788.dur) {
        func_00110BC8(D_01D01788.hnd, 0, 1);
        func_00110BC8(D_01D01788.hnd, 3, 0);
        func_001CE2F0(D_01D01788.chr, 0);
        func_001CDDD8(D_01B00F40);
    }
    if (D_006A3BC4 == 0) {
        register int c __asm__("$3");
        c = D_01D01780;
        D_01D01780 = c + 1;
    }
    return 0;
}

int func_01B00EF8(void)
{
    return 0;
}

void func_01B00F00(void)
{
}
