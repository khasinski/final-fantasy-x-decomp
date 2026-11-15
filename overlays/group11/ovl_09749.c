/* EE Battle-Effect Overlay: group 0x11, file 09749
 * Load base: 0x01B00000, .text: 0x01B00618..0x01B019A8 (20 functions)
 */
#include "../oef_overlay.h"

typedef struct P49Part {
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
} P49Part;

typedef struct P49Ent {
    int chr;           /* 0x00 */
    void *hnd;         /* 0x04 */
    int state;         /* 0x08 */
    int dur;           /* 0x0C */
    int cnt;           /* 0x10 */
    short a14;         /* 0x14 */
    short a16;         /* 0x16 */
    u8 pad18[8];
    float pos[4];      /* 0x20 */
} P49Ent;

typedef struct Blk176 {
    unsigned long long q[22];
} Blk176;

extern u8 D_01B00040[];
extern int D_01B00540;
extern int D_01B00544;
extern int D_01B00548;
extern float D_01B00550[][4];
extern Blk176 D_01B01A00;
extern u8 D_01B01AB0[];
extern int D_01B01BB0;
extern void *D_01B01BB4;
extern void *D_01B01BB8;
extern int D_01B01BBC;
extern int D_01B01BC0;
extern int D_01B01BC4;
extern P49Part D_01B01BD0;
extern P49Part D_01B01C50;
extern P49Part D_01B01CD0[16];
extern P49Part D_01B024D0[12];
extern void *D_01B019B0[5];
extern OefHeapMgr D_01B02AD0;
extern u8 D_01B02B00[];
extern u8 D_01C02B00[];
extern int D_01D02B00;
extern int D_01D02B04;
extern int D_01D02B08;
extern void *D_01D02B0C;
extern void *D_01D02B10;
extern float D_01D02B20[4];
extern P49Ent D_01D02B30;
extern P49Ent D_01D02B60[];
extern int D_01D02BF0;
extern OefHeapCfg D_01D02C10;
extern u8 D_01D13500[];
extern Blk176 D_006F2CE0;

void func_0026BE48(void *mtx, int angle);
void func_002DCE08(void *out, void *m, void *in);
void func_002DD020(float *d, float *a, float *b);
void func_002B2A80(void *p, int a, int b, int c);
void *func_001B4E58(int id);
float func_001B6EA8(int id);
float func_001B5400(int id);
int func_001CDAF8(int id);
void func_001CDC58(int id, int v);
int func_001CDDD8(int id);
void func_001CE2F0(int h, int v);
int func_001CE050_i(int h, int v) __asm__("func_001CE050");
int func_001CE048(int id);
u8 *func_001E53D0(int id, void *out);
void func_00294B70(void *h, int a, int b);
int func_0029B830_i(int id) __asm__("func_0029B830");
void func_002944B0(void *res, int a, int b, int c);
void *func_002B49A0(void *res, int a, int b);
void func_002B4980(void *res);
int func_00116068(void);
void func_00110BC8(void *h, int a, int b);
void func_002678E0(void *a, void *b);
void func_00267A68(void *a, void *b, void *c, int d);
void func_00267658(void *o, int a, int b, int c);
void func_002675B0(void);
int func_00267FA0(void *o, int a);
void func_001B6790(int chr, float *pos);
void func_00173720(float *v);
void func_00173A70(int n);
void func_00173A90(int n);
void *func_0011A538(s32 *p);
float func_001ACED8(void);
long long func_002ED038(float f);
long long func_002EBC08(long long a, long long b);
long long func_002EBC70(long long a, long long b);
float func_002EC440(long long d);

void func_01B00618(float *out, float len, int angle)
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

void func_01B00680(float *out, int angle, float *in)
{
    float m[16];

    func_0026BE48(m, -angle);
    func_002DCE08(out, m, in);
}

void func_01B006C8(void *res)
{
    void **p0 = &D_01B01BB4;
    void **p1 = &D_01B01BB8;

    func_002B4980(res);
    func_002D02E8(res, 0, 1000, 0x100);
    func_002944B0(res, 0, 1000, 0x100);
    *p0 = func_002B49A0(res, 6, 0);
    *p1 = func_002B49A0(res, 6, 1);
}

void func_01B00758(P49Ent *e, int chr)
{
    volatile int pad[4];

    e->chr = chr;
    if (chr != 255) {
        e->hnd = func_001B4E58(e->chr);
        e->a14 = (int)(func_001B6EA8(e->chr) * 32768.0f / 3.1415927f);
        func_001B6790(e->chr, e->pos);
    }
}

void func_01B007D8(P49Ent *e, int state)
{
    if (e->chr != 255) {
        e->cnt = 0;
        e->state = state;
        e->dur = func_001CE050_i(e->chr, state);
    }
}

float func_01B00818(int cur, int start, int fin, int hold, int fout)
{
    int t = cur - start;

    if (t > 0) {
        hold -= start;
        if (t < hold + fout) {
            if (t <= fin) {
                return (float)t / (float)fin;
            }
            if (t > hold) {
                return 1.0f - (float)(t - hold) / (float)fout;
            }
            return 1.0f;
        }
    }
    return 0.0f;
}

void func_01B008B0(int cur, int start, int fin, int hold, int fout, int unused,
    float a, float b, float c, float d)
{
    float v[4];
    float k;

    k = func_01B00818(cur, start, fin, hold, fout);
    v[0] = 1.0f - a * k;
    v[1] = 1.0f - b * k;
    v[2] = 1.0f - c * k;
    v[3] = 1.0f - d * k;
    func_00173720(v);
}

void func_01B00938(int cur, int start, int fin, int fout, u8 r, u8 g, u8 b, int prio)
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

void func_01B00A48(void)
{
    D_01B01A00 = D_006F2CE0;
    func_002B2A80(&D_01B01A00, 0xb, 1, 0);
}

void func_01B00AB8(int cur, int start, int fin, int hold, int fout, int alpha)
{
    float k;
    s32 idx;
    u8 *base;
    unsigned long long *rec;
    unsigned long long *q;
    int *w;
    float *f;

    k = func_01B00818(cur, start, fin, hold, fout);
    if (k != 0.0f) {
        alpha = (int)((float)alpha * k);
        base = func_0011A538(&idx);
        q = (unsigned long long *)D_01B01AB0;
        w = (int *)D_01B01AB0;
        f = (float *)D_01B01AB0;
        rec = (unsigned long long *)(((idx & 1) == 0) ? base + 0x1D0 : base + 0x60);
        q[2] = 0xE02A400000008001ULL;
        q[3] = 0x005252525216EEEEULL;
        q[4] = 0x0000008000000080ULL;
        q[5] = 0x3B;
        q[7] = 0x42;
        q[6] = 0x44;
        q[8] = rec[4];
        q[9] = 0x18;
        q[10] = 0x067C007FC00AULL;
        q[11] = 8;
        q[12] = 0x24020000ULL | (long long)(((int)(rec[0] & 0x1FF)) << 5) | 0x240000000ULL;
        q[13] = 0;
        w[29] = 0x80;
        w[30] = 0x80;
        w[28] = 0x80;
        w[31] = alpha;
        f[32] = 0.0f;
        f[33] = 0.0f;
        f[34] = 1.0f;
        f[35] = 0.0f;
        f[42] = 1.0f;
        w[36] = 0x6FE0;
        w[37] = 0x72E0;
        w[38] = 0xFFFFFF;
        w[39] = 0;
        f[40] = 1.0f;
        f[41] = 0.0f;
        f[50] = 1.0f;
        f[43] = 0.0f;
        w[44] = 0x9010;
        w[46] = 0xFFFFFF;
        w[47] = 0;
        f[48] = 0.0f;
        f[49] = 0.8125f;
        f[51] = 0.0f;
        w[52] = 0x6FE0;
        w[45] = 0x72E0;
        w[53] = 0x8D10;
        w[55] = 0;
        f[56] = 1.0f;
        w[54] = 0xFFFFFF;
        f[57] = 0.8125f;
        f[58] = 1.0f;
        w[60] = 0x9010;
        f[59] = 0.0f;
        w[61] = 0x8D10;
        w[62] = 0xFFFFFF;
        w[63] = 0;
        func_002B2A80(D_01B01AB0, 0x10, 1, 0);
        func_01B00A48();
    }
}

void func_01B00CC8(P49Part *o, int id,
    float x, float y, float z, float rx, float ry, float rz,
    float sx, float sy, float sz)
{
    D_006A3924 = &D_01B02AD0;
    func_00267658(o, 0x1000, D_01D02C10.pdt[id], 1);
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

void func_01B00DD8(P49Part *o)
{
    if (o->enabled != 0) {
        pppSetMatrix((OefPartObj *)o);
        func_002DCE38(D_006A39B0, D_006A3970, D_006A3930);
        func_002DCE38(D_006A3AB0, D_006A3A70, D_006A39B0);
        D_006A3924 = &D_01B02AD0;
        if (_pppRunPart((OefPartObj *)o, 0x30) != 0) {
            o->enabled = 0;
        }
    }
}

int func_01B00E70(int eff_id)
{
    u8 target_buf[16];
    u8 *list;
    int i;
    P49Ent *e;
    float n;

    D_01B01BB0 = eff_id;
    D_01D02B04 = MsGetEff2Chr(eff_id);
    D_01D02B08 = *MsGetTargetList(D_01B01BB0, target_buf);
    D_01D02B0C = func_001B4E58(D_01D02B04);
    D_01D02B10 = func_001B4E58(D_01D02B08);
    func_01B00758(&D_01D02B30, D_01D02B04);
    D_01D02B20[0] = D_01D02B20[1] = D_01D02B20[2] = 0.0f;
    list = func_001E53D0(D_01B01BB0, &D_01D02BF0);
    for (i = 0; i < D_01D02BF0; i++) {
        e = &D_01D02B60[i];
        func_01B00758(e, list[i]);
        D_01D02B20[0] += e->pos[0];
        D_01D02B20[1] += func_001B5400(e->chr);
        D_01D02B20[2] += e->pos[2];
    }
    n = (float)D_01D02BF0;
    D_01D02B20[0] /= n;
    D_01D02B20[1] /= n;
    D_01D02B20[2] /= n;
    D_01D02B20[3] = 1.0f;
    D_01B01BC4 = -1;
    D_01D02B00 = 0;
    D_01B01BC0 = 0;
    D_01B01BBC = 0;
    func_01B006C8(D_01D13500);
    func_002678E0(&D_01D02C10, D_01B00040);
    func_00267A68(&D_01B02AD0, &D_01D02C10, D_01B02B00, 0x100000);
    func_00173A70(4);
    return 0;
}

int func_01B010A8(void)
{
    return 0;
}

int func_01B010B0(void)
{
    return 0;
}

void func_01B010B8(float *out, float len)
{
    float a[4];
    float b[4];

    func_00107428(D_01D02B30.hnd, 0x11, 0, a);
    func_00107428(D_01D02B30.hnd, 0x14, 0, b);
    func_01B00618(out, len, D_01D02B30.a14);
    out[0] += (a[0] + b[0]) * 0.5f;
    out[1] = (a[1] + b[1]) * 0.5f + 5.0f;
    out[2] += (a[2] + b[2]) * 0.5f;
    out[3] = 1.0f;
}

int func_01B01198(void)
{
    int n;
    unsigned sw;
    float *t;
    P49Ent *e;
    float v[4];
    float ry;
    float sz;
    float tt;
    P49Ent *e2;
    static void *keep[5] = { &&L_c0, &&L_c1, &&L_c2, &&L_c3, &&L_c4 };

    if (D_01B00540 == 0) {
        if (func_0029B830_i(D_01B01BB0) != 0) {
            return 0;
        }
        D_01B00540++;
    }
    if (D_01B00544 == 0) {
        D_01B00544 = 1;
        func_001CDC58(D_01B01BB0, 0);
    }
    if (D_01B00548 == 0) {
        if (func_001CDAF8(D_01B01BB0) > 0) {
            D_01B00548 += 1;
        } else {
            return 0;
        }
    }
    if (func_00116068() == 0) {
        D_006A3BC4 = 1;
    } else {
        D_006A3BC4 = 0;
    }
    if (D_006A3BC4 != 0) {
        return 0;
    }
    if (D_01D02B00 == 0) {
        func_00294B70(D_01B01BB4, 64, 256);
        func_01B007D8(&D_01D02B30, 0xC0);
    }
    e = &D_01D02B30;
    for (n = 0; n < 1; n++, e++) {
        sw = e->state - 0xC0;
        if (sw >= 5) {
            continue;
        }
        goto *D_01B019B0[sw];
    L_c0:
        if (e->cnt == e->dur) {
            func_01B007D8(e, 0xC1);
        }
        continue;
    L_c1:
        if (e->cnt == 0x58) {
            func_01B00CC8(&D_01B01BD0, 2, 0.0f, 0.0f, 0.0f, 0.0f,
                (float)(-e->a14 - 0x4000), 0.0f, 0.3f, 0.3f, 0.3f);
            func_01B007D8(e, 0xC2);
        }
        continue;
    L_c2:
        if (e->cnt == e->dur) {
            func_01B007D8(e, 0xC3);
        }
        continue;
    L_c3:
        if (e->cnt == 0x2C) {
            func_01B007D8(e, 0xC4);
        }
        continue;
    L_c4:
        if (e->cnt == e->dur) {
            func_001CE2F0(e->chr, 0);
        }
    }
    n = D_01D02B00 - 15;
    if ((unsigned)n < 0x58 && (unsigned)n % 7 == 0) {
        if (D_01B01BBC < 12) {
            t = D_01B00550[D_01B01BBC];
            func_01B00CC8(&D_01B024D0[D_01B01BBC], 3,
                t[0], t[1], t[2],
                0.0f, (float)(-D_01D02B30.a14 - 0x4000), 0.0f, 0.4f, 0.4f, 0.4f);
            D_01B01BBC++;
        }
    }
    if (D_01B01BD0.enabled != 0) {
        func_01B010B8(D_01B01BD0.position.f, 20.0f);
        if (D_01B01BD0.cnt == 0x3C000) {
            func_01B00CC8(&D_01B01C50, 1, 0.0f, 0.0f, 0.0f, -3640.0f,
                (float)(-D_01D02B30.a14 - 0x4000), 0.0f, 0.3f, 0.3f, 0.3f);
            D_01B01BC4 = 0;
        }
    }
    if (D_01B01C50.enabled != 0) {
        func_01B010B8(D_01B01C50.position.f, 15.0f);
    }
    if (D_01B01BC4 >= 0 && D_01B01BC0 < 16) {
        n = D_01B01BC4 - 0x50;
        if (n == 0) {
            func_00294B70(D_01B01BB8, 64, 256);
        }
        if ((unsigned)n < 0x20 && (n & 1) == 0) {
            v[0] = (float)(((double)(func_001ACED8() - 1.0f) - 0.5) * 50.0);
            v[2] = (float)(((double)(func_001ACED8() - 1.0f) - 0.5) * 100.0);
            v[1] = 0.0f;
            v[3] = 1.0f;
            func_01B00680(v, D_01D02B30.a14, v);
            func_002DD020(v, v, D_01D02B20);
            ry = (func_001ACED8() - 1.0f) * 65536.0f;
            tt = func_001ACED8() - 1.0f;
            sz = tt * 0.1f + 0.25f;
            func_01B00CC8(&D_01B01CD0[D_01B01BC0], 0, v[0], v[1] - 1.0f, v[2], 0.0f,
                ry, 0.0f, sz, sz, sz);
            D_01B01BC0++;
        }
        if (n == 0x1E) {
            func_001C5E90(D_01B01BB0, -5, 0);
        }
        D_01B01BC4++;
    }
    if (D_006A3BC4 == 0) {
        int j = 0;
        e2 = &D_01D02B30;
        do {
            e2->cnt++;
            e2++;
        } while (--j >= 0);
    }
    return 0;
}

int func_01B01770(void)
{
    float m[16];
    union { float f[4]; u_long128 q; } t;
    P49Part *p;
    P49Ent *e;
    int i;
    int k;
    int alive;

    if (D_01B00548 == 0 || D_01D02B00 < 0) {
        __asm__ volatile("");
        return 0;
    }
    D_006A3BCC = D_01C02B00;
    D_006A3924 = &D_01B02AD0;
    func_001AACA0(D_006A3A70);
    alive = 1;
    func_001A9EE0(D_006A3970);
    func_01B008B0(D_01D02B00, 0, 60, 270, 60, 0x44, 0.66f, 0.66f, 0.66f, 0.66f);
    func_01B00938(D_01B01BC4, 0x50, 1, 0x1E, 0xFF, 0xFF, 0xFF, 0x44);
    func_01B00DD8(&D_01B01BD0);
    func_01B00DD8(&D_01B01C50);
    p = D_01B01CD0;
    for (i = 15; i >= 0; i--, p++) {
        func_01B00DD8(p);
        if (p->enabled != 0) {
            alive = 0;
        }
    }
    p = D_01B024D0;
    i = 12;
    func_001072F8(D_01D02B30.hnd, 6, m);
    for (; i != 0; i--, p++) {
        if (p->enabled != 0) {
            t.q = p->position.q;
            func_002DCE08(&p->position, m, &t);
            func_01B00DD8(p);
            p->position.q = t.q;
        }
    }
    if (D_01B01BC0 != 0 && alive != 0) {
        e = &D_01D02B30;
        for (k = 0; k >= 0; k--, e++) {
            func_001CE2F0(e->chr, 0);
        }
        func_00173A90(4);
        func_001CDDD8(D_01B01BB0);
    }
    func_01B00AB8(D_01B01BC4, 0, 1, 100, 20, 96);
    if (D_006A3BC4 == 0) {
        register int c __asm__("$3");
        c = D_01D02B00;
        D_01D02B00 = c + 1;
    }
    return 0;
}

int func_01B01998(void)
{
    return 0;
}

void func_01B019A0(void)
{
}
