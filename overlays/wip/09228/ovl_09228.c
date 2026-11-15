/* EE Battle-Effect Overlay: group 0x11, file 09228
 * Load base: 0x01B00000, .text: 0x01B00468..0x01B018F0 (12 functions)
 */
#include "oef_overlay.h"
#include "vu0.h"

typedef struct Prt {
    float p[4];   /* 0x00 */
    float s;      /* 0x10 */
    u16 a;        /* 0x14 */
    s16 idx;      /* 0x16 */
    u8 pad18[8];
} Prt;

typedef struct PEnt { s16 off; s16 lim; s16 c; s16 d; } PEnt;
typedef struct PTab {
    u8 pad00[6];
    s16 cnt;      /* 0x06 */
    u8 pad08[8];
    PEnt e[1];    /* 0x10 */
} PTab;

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

extern int D_01B00450;
extern int D_01B00454;
extern int D_01B00458;
extern char D_01B018F8[];
extern char D_01B01908[];
extern int D_01B01940;
extern void *D_01B01944;
extern void *D_01B01948;
extern void *D_01B0194C;
extern void *D_01B01950;
extern OefPartObj D_01B01960;
extern OefPartObj D_01B019E0;
extern OefPartObj D_01B01A60;
extern OefPartObj D_01B01AE0;
extern OefHeapMgr D_01B01B60;
extern u8 D_01B01B90[];
extern u8 D_01B00040[];
extern u8 D_006A3A70_a[] __asm__("D_006A3A70");
extern u8 D_01C01BC0[];
extern Prt D_01D01BC0[64];
extern int D_01D023C0;
extern int D_01D023C4;
extern int D_01D023C8;
extern void *D_01D023CC;
extern void *D_01D023D0;
extern int D_01D023D4;
extern int D_01D023D8;
extern s16 D_01D023DC;
extern u16 D_01D023DC_u __asm__("D_01D023DC");
extern float D_01D023F0[4];
extern float D_01D02400[4];
extern float D_01D02410[4];
extern float D_01D02420[4];
extern float D_01D02430[4];
extern float D_01D02440[16];
extern float D_01D02480[16];
extern float D_01D024C0[16];
extern float D_01D02500[16];
extern float D_01D02580[16];
extern float D_01D025C0[16];
extern float D_01D02600;
extern OefHeapCfg D_01D02620;
extern s16 D_01D0C360[];

extern u8 D_01D0C970[];

#define DK(sym) ({ register double _k __asm__("$5"); \
    __asm__ volatile (".set push\n\t.set noat\n\tlui $1, %%hi(" #sym ")\n\tld $5, %%lo(" #sym ")($1)\n\t.set pop" : "=r"(_k) : : "$1"); _k; })

void func_0029B810_i(int a, int b, int c) __asm__("func_0029B810");
void func_002CD590_i(void *a, DrawReq *r) __asm__("func_002CD590");
void *func_002CD590_p(void *a, DrawReq *r) __asm__("func_002CD590");
void func_002DCE08(void *out, void *m, void *in);
void func_002B4980(void *res);
void func_002944B0(void *res, int a, int b, int c);
void *func_002B49A0(void *res, int a, int b);
int func_001CE048(int id);
u8 *func_001E53D0(int id, void *buf);
void *func_001B4E58(int id);
float func_001B63B8(int id);
void func_001CDC58(int id, int v);
int func_001CDAF8(int id);
void func_001CE2F0(int h, int v);
void func_001CE050(int h, int v);
int func_001CDDD8(int id);
int func_00294B70(void *h, int a, int b);
void func_00107378(void *chr, void *dst);
void func_00110830(void *chr, void *m);
void func_0026BEB0(void *m, int angle);
void func_00107428_i(void *chr, int bone, int a2, void *dst) __asm__("func_00107428");

#define DRAW_PART(part, mtx, k) \
    if ((part).enabled != 0) { \
        (part).scale[0] = (part).scale[1] = (part).scale[2] = (part).scale[3] = (k); \
        func_002DD068(D_006A3930, &(mtx)[0], (part).scale[0]); \
        func_002DD068(D_006A3930 + 0x10, &(mtx)[4], (part).scale[1]); \
        func_002DD068(D_006A3930 + 0x20, &(mtx)[8], (part).scale[2]); \
        *(u_long128 *)(D_006A3930 + 0x30) = *(u_long128 *)&(mtx)[12]; \
        func_002DCE38(D_006A39B0, D_006A3970, D_006A3930); \
        func_002DCE38(D_006A3AB0, D_006A3A70, D_006A39B0); \
        D_006A3924 = &D_01B01B60; \
        if (_pppRunPart(&(part), 0x30) != 0) { \
            (part).enabled = 0; \
        } \
    }

Prt *func_01B004A8(void);
void func_01B00660(float *base, int n, float k0, float k1);
void func_01B00800(void *res);
void func_01B004E0(void);

#define RAND01(r) \
    __asm__ volatile("addi $8, $0, -1\n\tqmtc2 $8, $vf2\n\t.word 0x4A00143F\n\t.word 0x4B02113C\n\t.word 0x4B01043C\n\t.word 0x4B020868\n\tqmfc2 $2, $vf1\n\tmtc1 $2, %0" \
                     : "=f"(r) : : "$2", "$8")

void func_01B00468(void)
{
    int i;
    s16 n = -1;

    for (i = 63; i >= 0; i--) {
        D_01D01BC0[i].idx = n;
    }
}

Prt *func_01B004A8(void)
{
    int i;
    Prt *p = D_01D01BC0;

    for (i = 0; i < 64; ) {
        if (p->idx == -1) {
            return p;
        }
        i++;
        p++;
    }
    return 0;
}

void func_01B004E0(void)
{
    DrawReq r;
    float m[16];
    int i;
    s16 *t = D_01D0C360;

    for (i = 0; i < 64; i++) {
        Prt *p = &D_01D01BC0[i];
        s16 *e;

        if (p->idx == -1) {
            continue;
        }
        func_002DD128(m);
        t = D_01D0C360;
        m[0] = m[5] = m[10] = p->s;
        func_002DCE08(&m[12], D_006A39B0, p);
        func_002DCE38(m, D_006A3A70_a, m);
        e = t + p->idx * 4 + 8;
        r.h2 = 0x80;
        r.w4 = 0x70808080;
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

void func_01B00660(float *base, int n, float k0, float k1)
{
    int c = n - 1;
    Prt *p;
    float r;

    if (n == 0) {
        return;
    }
    do {
        p = func_01B004A8();
        if (p == 0) {
            return;
        }
        RAND01(r);
        p->p[0] = base[0] + (r - 0.5f) * k0;
        RAND01(r);
        p->p[1] = base[1] - r * k0;
        RAND01(r);
        p->p[2] = base[2] + (r - 0.5f) * k0;
        p->p[3] = 1.0f;
        RAND01(r);
        p->s = (float)(((double)r + 1.0) * (double)k1);
        p->idx = 0;
        p->a = 0;
    } while (--c != -1);
}

void func_01B00800(void *res)
{
    void **p0 = &D_01B01944;
    void **p1 = &D_01B01948;
    void **p2 = &D_01B0194C;
    void **p3 = &D_01B01950;

    func_002B4980(res);
    func_002D02E8(res, 0, 1000, 0x100);
    func_002944B0(res, 0, 1000, 0x100);
    *p0 = func_002B49A0(res, 6, 0);
    *p1 = func_002B49A0(res, 6, 1);
    *p2 = func_002B49A0(res, 6, 2);
    *p3 = func_002B49A0(res, 6, 3);
}

int func_01B008D0(int eff_id)
{
    float m[16];
    float v[4];
    float a[4];
    float b[4];
    u8 buf[16];
    float one = 1.0f;
    register float *c __asm__("$20");

    c = D_01D02420;

    D_01B01940 = eff_id;
    D_01D023C4 = func_001CE048(eff_id);
    D_01D023C8 = *func_001E53D0(D_01B01940, buf);
    D_01D023CC = func_001B4E58(D_01D023C4);
    D_01D023D0 = func_001B4E58(D_01D023C8);
    func_001B6790(D_01D023C8, D_01D023F0);
    D_01D02600 = func_001B63B8(D_01D023C8) * DK(D_01B01910);
    D_01D023D4 = -1;
    func_00107378(D_01D023D0, D_01D025C0);
    D_01D023DC = 0;
    *(u_long128 *)&D_01D025C0[12] = 0;
    D_01D025C0[15] = one;
    func_00107428_i(D_01D023CC, 0xA8, 0, a);
    func_00107428_i(D_01D023CC, 0xEB, 0, b);
    D_01D02420[0] = (a[0] + b[0]) * 0.5;
    c[1] = (a[1] + b[1]) * 0.5;
    c[2] = (a[2] + b[2]) * 0.5;
    c[3] = one;
    func_002DD128(D_01D024C0);
    D_01D024C0[15] = one;
    func_0026BDE0(m, 0);
    *(u_long128 *)&D_01D024C0[12] = *(u_long128 *)D_01D02420;
    func_002DCE38(D_01D02580, D_01D025C0, m);
    v[3] = one;
    v[0] = 0.0f;
    v[2] = 0.0f;
    v[1] = D_01D02600 * 100.0f;
    func_002DCE08(v, D_01D02580, v);
    v[1] -= D_01D02600;
    D_01D02580[15] = one;
    D_01D02580[12] = D_01D024C0[12] + v[0];
    D_01D02580[13] = D_01D024C0[13] + v[1] + D_01D02600;
    D_01D02580[14] = D_01D024C0[14] + v[2];
    func_00110830(D_01D023D0, D_01D02580);
    D_01D023C0 = 0x47;
    D_01D023D8 = 0;
    func_01B00800(D_01D0C970);
    func_0029B810_i(0, 0, -1);
    _pppInitData(&D_01D02620, D_01B00040);
    pppInitEnv(&D_01B01B60, &D_01D02620, D_01B01B90, 0x100000);
    D_006A3924 = &D_01B01B60;
    _pppStartPart(&D_01B01960, 0x1000, D_01D02620.pdt[0], 1);
    D_006A3924 = &D_01B01B60;
    _pppStartPart(&D_01B019E0, 0x1000, D_01D02620.pdt[1], 1);
    D_006A3924 = &D_01B01B60;
    _pppStartPart(&D_01B01A60, 0x1000, D_01D02620.pdt[2], 1);
    D_006A3924 = &D_01B01B60;
    _pppStartPart(&D_01B01AE0, 0x1000, D_01D02620.pdt[3], 1);
    D_01B01960.enabled = 1;
    D_01B01AE0.enabled = 1;
    D_01B01A60.enabled = 1;
    D_01B019E0.enabled = 1;
    func_01B00468();
    func_002EF240(D_01B018F8, D_01B01908, 0x142);
    return 0;
}

int func_01B00CA8(void)
{
    return 0;
}

int func_01B00CB0(void)
{
    return 0;
}

int func_01B00CB8(void)
{
    float a[4];
    float b[4];
    float mm[32];
    float z;
    float u;
    float t;
    int s6, s5, s4;
    float fs1;

    if (D_01B00450 == 0) {
        if (func_0029B830(D_01B01940) != 0) {
            return 0;
        }
        D_01B00450++;
    }
    if (D_01B00454 == 0) {
        D_01B00454 = 1;
        func_001CDC58(D_01B01940, 0);
    }
    if (D_01B00458 == 0) {
        if (func_001CDAF8(D_01B01940) <= 0) {
            return 0;
        }
        D_01B00458++;
    }
    if (D_01D023C0 == 0x47) {
        func_001CE050(D_01D023C4, 0xB8);
    } else if (D_01D023C0 == 0x10E) {
        func_001CE2F0(D_01D023C4, 0);
    }
    s6 = D_01D023C0 - 0xF1;
    s5 = D_01D023C0 - 0xDD;
    s4 = D_01D023C0 - 0x83;
    if (s4 < 0 && s5 < 0 && s6 < 0) {
        goto tail;
    }
    if (s4 >= 0) {
        double h = 0.5;

        func_00107428_i(D_01D023CC, 0xA8, 0, a);
        func_00107428_i(D_01D023CC, 0xEB, 0, b);
        D_01D02420[0] = (a[0] + b[0]) * h;
        D_01D02420[1] = (a[1] + b[1]) * h;
        D_01D02420[2] = (a[2] + b[2]) * h;
        D_01D02420[3] = 1.0f;
        func_001072F8(D_01D023CC, 0x2D, D_01D02440);
        func_002DD068(&D_01D02440[0], &D_01D02440[0], 100.0f);
        func_002DD068(&D_01D02440[4], &D_01D02440[4], 100.0f);
        func_002DD068(&D_01D02440[8], &D_01D02440[8], 100.0f);
        if (D_01B01AE0.enabled != 0) {
            func_0026BEB0(mm, 0x4000);
            func_002DCE38(D_01D02500, D_01D02440, mm);
            func_0026BDE0(mm, -0x4000);
            func_002DCE38(D_01D02500, D_01D02500, mm);
            func_0026BEB0(mm, 0x8000);
            func_002DCE38(D_01D02500, D_01D02500, mm);
            *(u_long128 *)&D_01D02500[12] = *(u_long128 *)D_01D02420;
        }
        if (D_01B01960.enabled != 0) {
            func_0026BEB0(mm, 0x4000);
            func_002DCE38(D_01D02440, D_01D02440, mm);
            *(u_long128 *)&D_01D02440[12] = *(u_long128 *)D_01D02420;
        }
    }
    if (s5 == 0) {
        func_001B57F0(D_01D023C8, 1);
        *(u_long128 *)D_01D02430 = *(u_long128 *)D_01D02420;
        func_002DCFF8(D_01D02400, D_01D023F0, D_01D02430, 0.7f);
        D_01D02400[1] = D_01D023F0[1];
        func_002DD038(mm, D_01D023F0, D_01D02430);
        mm[1] = 0;
        func_002DCEC8(mm, mm);
        func_002DD068(D_01D02410, mm, 20.0f);
        func_002DD128(D_01D02480);
        *(u_long128 *)&D_01D02480[12] = *(u_long128 *)D_01D02400;
        D_01D02480[15] = 1.0f;
        D_01D02480[13] -= 0.1f;
        func_001CE050(D_01D023C8, 0x22);
    }
    if ((unsigned)s5 < 0x14) {
        t = (float)s5 / 20.0f + 0.1f;
        func_002DD128(D_01D024C0);
        func_002DCFF8(&D_01D024C0[12], D_01D02400, D_01D02430, t);
        fs1 = t * t;
        D_01D024C0[15] = 1.0f;
        D_01D024C0[13] = (D_01D02400[1] - D_01D02430[1]) * fs1 + D_01D02430[1];
        if (s5 == 0x13) {
            func_001CE050(D_01D023C8, 0x49);
        }
        func_0026BDE0(&mm[16], D_01D023DC);
        func_002DCE38(D_01D02580, D_01D025C0, &mm[16]);
        z = 0.0f;
        mm[4+0] = z;
        mm[4+1] = D_01D02600 * 100.0f;
        mm[4+2] = z;
        mm[4+3] = 1.0f;
        func_002DCE08(&mm[4], D_01D02580, &mm[4]);
        mm[4+1] -= D_01D02600;
        D_01D02580[12] = D_01D024C0[12] + mm[4+0];
        D_01D02580[13] = D_01D024C0[13] + mm[4+1] + D_01D02600 * (1.0f - fs1);
        D_01D02580[14] = D_01D024C0[14] + mm[4+2];
        D_01D02580[15] = 1.0f;
        func_00110830(D_01D023D0, D_01D02580);
    }
    if ((unsigned)s6 < 0x14) {
        u = (float)s6 / 20.0f;
        fs1 = *(float *)((u8 *)D_004F4610 + ((((unsigned)(int)(u * u * 98304.0f)) >> 2) & 0x3FFC));
        if (fs1 < 0) {
            fs1 = -fs1;
        }
        func_002DD0C0(D_01D02580, D_01D025C0);
        u = 1.0f - u;
        t = u * u;
        func_002DCFF8(&D_01D02580[12], D_01D02400, D_01D023F0, t);
        mm[8] = D_01D02580[12] + D_01D02410[0];
        mm[9] = D_01D02580[13];
        mm[10] = D_01D02580[14] + D_01D02410[2];
        func_01B00660(&mm[8], 2, 15.0f, (float)(((double)u + DK(D_01B01918)) * DK(D_01B01920)));
        t = fs1 * t * 10.0f;
        D_01D02580[13] = D_01D02580[13] - t;
        if (s6 == 10) {
            func_001C5E90(D_01B01940, -5, 6);
        }
    } else if (s6 == 0x14) {
        func_00110830(D_01D023D0, 0);
        func_001CE050(D_01D023C8, 0x4A);
    }
tail:
    D_01D023DC_u -= 0x1000;
    return 0;
}

int func_01B013D8(void)
{
    int s7, s0, s5;
    register u8 *q __asm__("$2");

    if (D_01B00458 == 0) {
        return 0;
    }
    if (D_01D023C0 == 0x83) {
        func_00294B70(D_01B01944, 0x40, 0x100);
        func_00294B70(D_01B01948, 0x40, 0x100);
    }
    if (D_01D023C0 == 0xD3) {
        func_00294B70(D_01B0194C, 0x40, 0x100);
        func_00294B70(D_01B01950, 0x40, 0x100);
    }
    s5 = D_01D023C0 - 0xDD;
    s0 = D_01D023C0 - 0x83;
    s7 = D_01D023C0 - 0xF1;
    if (s0 >= 0 || s5 >= 0 || s7 >= 0) {
        D_01B01B60.w20 = D_01D02620.w14;
        D_01B01B60.tbl = D_01D02620.tbl;
        D_01B01B60.p28 = D_01D02620.p1C;
        D_006A3924 = &D_01B01B60;
        func_001AACA0(D_006A3A70);
        func_001A9EE0(D_006A3970);
        q = D_01C01BC0;
        D_006A3BCC = q;
        if (s0 >= 0) {
            DRAW_PART(D_01B01AE0, D_01D02500, 0.8f)
        }
        if (s5 >= -5) {
            DRAW_PART(D_01B01960, D_01D02440, 1.0f)
        }
        if (s5 >= 0) {
            DRAW_PART(D_01B01A60, D_01D024C0, 1.0f)
        }
        if (s7 >= 0) {
            DRAW_PART(D_01B019E0, D_01D02480, 1.0f)
        }
        if (s7 >= 0) {
            func_002DD0C0(D_006A39B0, D_006A3970);
            func_01B004E0();
        }
    }
    if (D_01D023C0 >= 0x11E) {
        if (func_001DC7C0(D_01D023C8) != 0) {
            func_001CE2F0(D_01D023C4, 0);
            func_001CE2F0(D_01D023C8, 4);
            func_001CDDD8(D_01B01940);
        }
    }
    D_01D023C0++;
    return 0;
}

int func_01B018E0(void)
{
    return 0;
}

void func_01B018E8(void)
{
}
