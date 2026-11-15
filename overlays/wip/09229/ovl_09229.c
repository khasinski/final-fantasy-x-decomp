/* EE Battle-Effect Overlay: group 0x11, file 09229
 * Load base: 0x01B00000, .text: 0x01B00468..0x01B01858 (15 functions)
 */
#include "oef_overlay.h"
#include "vu0.h"

typedef struct Blk176 {
    unsigned long long q[22];
} Blk176;

typedef struct Prt {
    float p[4];   /* 0x00 */
    float s;      /* 0x10 */
    u16 a;        /* 0x14 */
    s16 idx;      /* 0x16 */
    u8 pad18[8];
} Prt;

typedef struct PEnt { s16 off; s16 lim; s16 c; s16 d; } PEnt;

typedef struct DrawReq {
    u8 b0;
    u8 b1;
    s16 h2;
    u32 w4;
    long long q8;
    void *p10;
    void *p14;
    u8 b18;
    void *p1C;
    u8 pad20[0x10];
} DrawReq;

typedef union Mat {
    float f[16];
    u_long128 q[4];
} Mat;

typedef union Vec4 {
    float f[4];
    u_long128 q;
} Vec4;

typedef struct TgtEnt {
    int chr;          /* 0x00 */
    void *hnd;        /* 0x04 */
    u8 pad08[8];
    Mat a;            /* 0x10 */
    Mat b;            /* 0x50 */
} TgtEnt;

extern int D_01B00450;
extern int D_01B00454;
extern int D_01B00458;
extern u8 D_01B00040[];
extern Blk176 D_01B01880;
extern u8 D_01B01930[];
extern int D_01B01A30;
extern int D_01B01A34;
extern int D_01B01A38;
extern OefPartObj D_01B01A40;
extern OefPartObj D_01B01AC0;
extern OefPartObj D_01B01B40;
extern OefHeapMgr D_01B01BC0;
extern u8 D_01B01BF0[];
extern u8 D_01C01C00[];
extern int D_01D01C00;
extern int D_01D01C04;
extern void *D_01D01C08;
extern int D_01D01C0C;
extern TgtEnt D_01D01C10[];
extern Vec4 D_01D01DC0;
extern Mat D_01D01DD0;
extern Mat D_01D01E10;
extern Mat D_01D01E50;
extern Mat D_01D01E90;
extern int D_01D01ED0;
extern Prt D_01D01EE0[128];
extern OefHeapCfg D_01D02EF0;
extern s16 D_01D0E180[];
extern u8 D_01D0E790[];
extern u8 D_006A3A70_a[] __asm__("D_006A3A70");
extern Blk176 D_006F2CE0;

void func_002B4980(void *res);
void func_002B2A80(void *p, int a, int b, int c);
void *func_002B49A0(void *res, int a, int b);
void func_002944B0(void *res, int a, int b, int c);
int func_00294B70(void *h, int a, int b);
void *func_0011A538(s32 *p);
void func_002DCE08(void *out, void *m, void *in);
void func_002DD020(void *d, void *a, void *b);
void func_002DD128(void *m);
void func_002DD0C0(void *a, void *b);
void func_0026BE48(void *m, int angle);
void *func_001B4E58(int id);
int func_001CE048(int id);
u8 *func_001E53D0(int id, void *buf);
float func_001102F8(void *chr);
void func_00107378(void *chr, void *dst);
void func_00107428_i(void *chr, int bone, int a2, void *dst) __asm__("func_00107428");
void func_00110820(void *chr, int v);
void func_00110830(void *chr, void *m);
void func_00110820(void *chr, int v);
void func_001CDC58(int id, int v);
int func_001CDAF8(int id);
void func_001CE2F0(int h, int v);
void func_001CE050(int h, int v);
int func_001CDDD8(int id);
int func_001DC7C0(int id);
int func_001C5E90(int id, int v, int z);
void func_001AAC18(float a, float b);
long long func_002ED038(float f);
long long func_002EBBB0(long long a, long long b);
long long func_002EBC08(long long a, long long b);
long long func_002EBC70(long long a, long long b);
float func_002EC440(long long d);
void func_002CD590(void *a, DrawReq *r);
void *func_002CD590_p(void *a, DrawReq *r) __asm__("func_002CD590");
int func_0029B830(int eff_id);
void func_001AACA0(void *m);
int func_001A9EE0(void *m);

#define RAND01(r) \
    __asm__ volatile("addi $8, $0, -1\n\tqmtc2 $8, $vf2\n\t.word 0x4A00143F\n\t.word 0x4B02113C\n\t.word 0x4B01043C\n\t.word 0x4B020868\n\tqmfc2 $2, $vf1\n\tmtc1 $2, %0" \
                     : "=f"(r) : : "$2", "$8")

void func_01B00B30(void);
Prt *func_01B00B70(void);
void func_01B00BA8(void);
void func_01B00D80(float *base);
void func_01B00568(int alpha);
extern float D_004F4610[];

void func_01B00468(void *res)
{
    int *p0 = &D_01B01A34;
    int *p1 = &D_01B01A38;

    func_002B4980(res);
    func_002D02E8(res, 0, 1000, 0x100);
    func_002944B0(res, 0, 1000, 0x100);
    *p0 = (int)func_002B49A0(res, 6, 0);
    *p1 = (int)func_002B49A0(res, 6, 1);
}

void func_01B004F8(void)
{
    D_01B01880 = D_006F2CE0;
    func_002B2A80(&D_01B01880, 0xb, 1, 0);
}

void func_01B00568(int alpha)
{
    s32 idx;
    u8 *base;
    unsigned long long *rec;
    unsigned long long *q;
    int *w;
    float *f;

    base = func_0011A538(&idx);
    q = (unsigned long long *)D_01B01930;
    w = (int *)D_01B01930;
    f = (float *)D_01B01930;
    q[2] = 0xE02A400000008001ULL;
    q[3] = 0x005252525216EEEEULL;
    q[4] = 0x0000008000000080ULL;
    q[5] = 0x3B;
    q[6] = 0x44;
    q[7] = 0x42;
    rec = (unsigned long long *)(((idx & 1) == 0) ? base + 0x1D0 : base + 0x60);
    q[8] = rec[4];
    q[9] = 0x18;
    q[10] = 0x067C007FC00AULL;
    q[11] = 8;
    w[28] = 0x80;
    w[54] = 0xFFFFFF;
    q[12] = 0x24020000ULL | (long long)((int)(rec[0] & 0x1FF) << 5) | 0x240000000ULL;
    q[13] = 0;
    w[29] = 0x80;
    w[45] = 0x7300;
    f[32] = 0.0f;
    f[33] = 0.0f;
    f[34] = 1.0f;
    f[35] = 0.0f;
    w[36] = 0x7000;
    w[38] = 0xFFFFFF;
    w[39] = 0;
    f[40] = 1.0f;
    f[41] = 0.0f;
    f[42] = 1.0f;
    f[43] = 0.0f;
    w[44] = 0x8FF0;
    w[37] = 0x7300;
    w[46] = 0xFFFFFF;
    w[52] = 0x7000;
    w[31] = alpha;
    f[58] = 1.0f;
    w[47] = 0;
    w[48] = 0;
    w[61] = 0x8CF0;
    f[50] = 1.0f;
    w[51] = 0;
    w[30] = 0x80;
    f[56] = 1.0f;
    w[55] = 0;
    w[60] = 0x8FF0;
    w[62] = 0xFFFFFF;
    w[53] = 0x8CF0;
    f[49] = 0.8125f;
    w[59] = 0;
    w[63] = 0;
    f[57] = 0.8125f;
    func_002B2A80(D_01B01930, 0x10, 1, 0);
    func_01B004F8();
}

int func_01B00740(int eff_id)
{
    float m[16];
    float v[4];
    float w[4];
    u8 *list;
    int i;
    TgtEnt *e;
    float s;

    D_01B01A30 = eff_id;
    __asm__ volatile("" ::: "memory");
    D_01D01C04 = func_001CE048(eff_id);
    list = func_001E53D0(D_01B01A30, &D_01D01C0C);
    D_01D01C08 = func_001B4E58(D_01D01C04);
    s = func_001102F8(D_01D01C08);
    D_01D01ED0 = (int)(s * 32768.0f / 3.1415927f);
    for (i = 0; i < D_01D01C0C; i++) {
        int c = list[i];

        e = &D_01D01C10[i];
        e->chr = c;
        e->hnd = func_001B4E58(c);
        func_00107378(e->hnd, &e->a);
        e->b.q[0] = e->a.q[0];
        e->b.q[1] = e->a.q[1];
        e->b.q[2] = e->a.q[2];
        e->b.q[3] = e->a.q[3];
    }
    func_00107378(D_01D01C08, &D_01D01DD0);
    D_01D01DC0.q = D_01D01DD0.q[3];
    D_01D01DD0.q[3] = 0;
    D_01D01DC0.f[3] = 1.0f;
    D_01D01DD0.f[15] = 1.0f;
    func_002DD068(&D_01D01DD0.f[0], &D_01D01DD0.f[0], 100.0f);
    func_002DD068(&D_01D01DD0.f[4], &D_01D01DD0.f[4], 100.0f);
    func_002DD068(&D_01D01DD0.f[8], &D_01D01DD0.f[8], 100.0f);
    func_0026BE48(m, 0);
    func_002DCE38(&D_01D01E10, &D_01D01DD0, m);
    D_01D01E10.q[3] = D_01D01DC0.q;
    D_01D01E10.f[13] = D_01D01E10.f[13] - 25.0f;
    func_0026BE48(m, 0);
    func_002DCE38(&D_01D01E50, &D_01D01DD0, m);
    v[0] = 50.0f;
    v[1] = 0.0f;
    v[2] = -50.0f;
    v[3] = 1.0f;
    func_002DCE08(w, &D_01D01DD0, v);
    func_002DD020(&D_01D01E50.f[12], &D_01D01DC0, w);
    D_01D01E50.f[15] = 1.0f;
    func_0026BE48(m, 0);
    func_002DCE38(&D_01D01E90, &D_01D01DD0, m);
    v[0] = -50.0f;
    v[2] = -50.0f;
    v[1] = 0.0f;
    v[3] = 1.0f;
    func_002DCE08(w, &D_01D01DD0, v);
    func_002DD020(&D_01D01E90.f[12], &D_01D01DC0, w);
    D_01D01E90.f[15] = 1.0f;
    D_01D01C00 = 0;
    func_01B00468(D_01D0E790);
    _pppInitData(&D_01D02EF0, D_01B00040);
    pppInitEnv(&D_01B01BC0, &D_01D02EF0, D_01B01BF0, 0x100000);
    D_006A3924 = &D_01B01BC0;
    _pppStartPart(&D_01B01A40, 0x1000, D_01D02EF0.pdt[0], 1);
    D_006A3924 = &D_01B01BC0;
    _pppStartPart(&D_01B01AC0, 0x1000, D_01D02EF0.pdt[1], 1);
    D_006A3924 = &D_01B01BC0;
    _pppStartPart(&D_01B01B40, 0x1000, D_01D02EF0.pdt[2], 1);
    D_01B01A40.enabled = 1;
    D_01B01B40.enabled = 1;
    D_01B01AC0.enabled = 1;
    func_01B00B30();
    return 0;
}

int func_01B00B20(void)
{
    return 0;
}

int func_01B00B28(void)
{
    return 0;
}

void func_01B00B30(void)
{
    int i;
    s16 n = -1;

    for (i = 127; i >= 0; i--) {
        D_01D01EE0[i].idx = n;
    }
}

Prt *func_01B00B70(void)
{
    int i;
    Prt *p = D_01D01EE0;

    for (i = 0; i < 128; ) {
        if (p->idx == -1) {
            return p;
        }
        i++;
        p++;
    }
    return 0;
}

void func_01B00BA8(void)
{
    DrawReq r;
    float m[16];
    int i;
    s16 *t = D_01D0E180;

    for (i = 0; i < 128; i++) {
        Prt *p = &D_01D01EE0[i];
        s16 *e;

        if (p->idx == -1) {
            continue;
        }
        func_002DD128(m);
        t = D_01D0E180;
        m[0] = m[5] = m[10] = p->s;
        func_002DCE08(&m[12], D_006A39B0, p);
        func_002DCE38(m, D_006A3A70, m);
        e = t + p->idx * 4 + 8;
        r.h2 = 0x80;
        r.w4 = 0x70608080;
        r.p14 = D_006A3BCC;
        r.q8 = 0;
        r.b18 = 0;
        r.p1C = m;
        r.p10 = m;
        D_006A3BCC = func_002CD590_p((u8 *)t + e[0], &r);
        p->a += 0x200;
        if ((s16)p->a >= e[1]) {
            p->a -= (u16)e[1];
            p->idx++;
            if (p->idx >= t[3]) {
                p->idx = -1;
            }
        }
    }
}

void func_01B00D28(float *out, int angle)
{
    float m[16];
    float z;
    float one;

    func_0026BE48(m, -angle);
    one = 1.0f;
    out[0] = one;
    z = 0.0f;
    out[3] = one;
    out[2] = z;
    out[1] = z;
    func_002DCE08(out, m, out);
}

void func_01B00D80(float *base)
{
    float v[4];
    float w[4];
    int c = 3;
    Prt *p;
    float r;
    float len;
    int a;
    int odd;
    long long d;

    func_01B00D28(v, D_01D01ED0);
    v[0] = v[0] * -40.0f;
    v[2] = v[2] * -40.0f;
    do {
        p = func_01B00B70();
        if (p == 0) {
            return;
        }
        RAND01(r);
        odd = c & 1;
        a = (int)(r * 8192.0f);
        if (odd) {
            a = -a;
        }
        func_01B00D28(w, D_01D01ED0 + a);
        RAND01(r);
        len = r * 20.0f + 30.0f;
        p->p[0] = base[0] + v[0] + w[0] * len;
        p->p[1] = base[1] - 5.0f;
        p->p[2] = base[2] + v[2] + w[2] * len;
        p->p[3] = 1.0f;
        RAND01(r);
        c--;
        d = func_002EBBB0(func_002ED038(r * 3.0f), 0x3FF0000000000000LL);
        p->s = func_002EC440(func_002EBC70(d, func_002ED038(0.3f)));
        p->a = 0;
        p->idx = 0;
    } while (c != -1);
}

int func_01B00F70(void)
{
    volatile int pad[20];
    float v[4];

    if (D_01B00450 == 0) {
        if (func_0029B830(D_01B01A30) != 0) {
            return 0;
        }
        D_01B00450++;
    }
    if (D_01B00454 == 0) {
        D_01B00454 = 1;
        func_001CDC58(D_01B01A30, 0);
    }
    if (D_01B00458 == 0) {
        if (func_001CDAF8(D_01B01A30) <= 0) {
            return 0;
        }
        D_01B00458++;
    }
    if (D_01D01C00 == 0x24) {
        func_001CE050(D_01D01C04, 0xC9);
    } else if (D_01D01C00 == 0x8F) {
        func_001CE050(D_01D01C04, 0xCA);
    } else if (D_01D01C00 == 0xA1) {
        func_001CE050(D_01D01C04, 0xCB);
    }
    if ((unsigned)(D_01D01C00 - 0x28) < 0x23) {
        func_00107428_i(D_01D01C08, 0x11, 0, v);
        func_01B00D80(v);
    }
    return 0;
}

#define DRAW_PART(part, mtx, k) \
    if ((part).enabled != 0 && COND) { \
        (part).scale[0] = (part).scale[1] = (part).scale[2] = (part).scale[3] = (k); \
        func_002DD068(D_006A3930, &(mtx).f[0], (part).scale[0]); \
        func_002DD068(D_006A3930 + 0x10, &(mtx).f[4], (part).scale[1]); \
        func_002DD068(D_006A3930 + 0x20, &(mtx).f[8], (part).scale[2]); \
        *(u_long128 *)(D_006A3930 + 0x30) = (mtx).q[3]; \
        func_002DCE38(D_006A39B0, D_006A3970, D_006A3930); \
        func_002DCE38(D_006A3AB0, D_006A3A70, D_006A39B0); \
        D_006A3924 = &D_01B01BC0; \
        if (_pppRunPart(&(part), 0x30) != 0) { \
            (part).enabled = 0; \
        } \
    }

int func_01B010A0(void)
{
    volatile int pad[4];
    int a, s3, i;
    register int b __asm__("$21");

    if (D_01B00458 == 0) {
        return 0;
    }
    if (D_01D01C00 == 0) {
        func_00294B70((void *)D_01B01A34, 0x40, 0x100);
        func_00294B70((void *)D_01B01A38, 0x40, 0x100);
    }
    func_001AACA0(D_006A3A70);
    func_001A9EE0(D_006A3970);
    D_006A3BCC = D_01C01C00;
    a = D_01D01C00 - 0x28;
    if ((unsigned)a < 0x43) {
        func_002DD0C0(D_006A39B0, D_006A3970);
        func_01B00BA8();
    }
    a = D_01D01C00 - 0x65;
    b = D_01D01C00 - 0x6F;
    if (a >= 0 || b >= 0) {
        D_01B01BC0.w20 = D_01D02EF0.w14;
        D_01B01BC0.tbl = D_01D02EF0.tbl;
        D_01B01BC0.p28 = D_01D02EF0.p1C;
        D_006A3924 = &D_01B01BC0;
#define COND a >= 0
        DRAW_PART(D_01B01A40, D_01D01E10, 0.12f)
#undef COND
#define COND b >= 0
        DRAW_PART(D_01B01AC0, D_01D01E50, 0.2f)
        DRAW_PART(D_01B01B40, D_01D01E90, 0.2f)
#undef COND
        if (b >= 0) {
            if (b == 0) {
                for (i = 0; i < D_01D01C0C; i++) {
                    func_001CE050(D_01D01C10[i].chr, 0x40);
                }
            }
            if ((unsigned)(b - 10) < 10) {
                for (i = 0; i < D_01D01C0C; i++) {
                    func_00110820(D_01D01C10[i].hnd, 0);
                }
            }
            if (b >= 20) {
                if (b == 20) {
                    for (i = 0; i < D_01D01C0C; i++) {
                        func_00110820(D_01D01C10[i].hnd, 0x100);
                    }
                }
                for (i = 0; i < D_01D01C0C; i++) {
                    if (func_001DC7C0(D_01D01C10[i].chr) != 0) {
                        func_001CE2F0(D_01D01C10[i].chr, 0);
                    }
                }
            }
            if (b < 50) {
                float k = (float)(1.0 - (double)((float)b / 50.0f));

                func_001AAC18(0.0f, *(float *)((u8 *)D_004F4610 + ((b << 11) & 0x3800)) * k * k * 16.0f);
            } else if (b == 50) {
                func_001AAC18(0.0f, 0.0f);
            }
            if (b < 20) {
                float k = (float)(1.0 - (double)((float)b / 40.0f));

                for (i = 0; i < D_01D01C0C; i++) {
                    TgtEnt *e = &D_01D01C10[i];
                    float t = (float)((double)*(float *)((u8 *)D_004F4610 + (((b + i) << 11) & 0x3800)) + 1.0) * k * 10.0f;

                    e->b.f[13] = e->a.f[13] - t;
                    func_00110830(e->hnd, &e->b);
                }
            } else if (b == 20) {
                for (i = 0; i < D_01D01C0C; i++) {
                    func_00110830(D_01D01C10[i].hnd, 0);
                    func_001C5E90(D_01B01A30, -5, 0);
                }
            }
        }
        s3 = b - 10;
        if (s3 >= 0) {
            int mul = 0x60;
            int den = 0x1E;

            if (s3 < 20) {
                func_01B00568(0x60);
            } else if (s3 < 50) {
                func_01B00568((50 - s3) * mul / den);
            }
        }
    }
    if (D_01D01C00 == 0xDE) {
        func_001CE2F0(D_01D01C04, 0);
        func_001CDDD8(D_01B01A30);
    }
    D_01D01C00++;
    return 0;
}

int func_01B01848(void)
{
    return 0;
}

void func_01B01850(void)
{
}
