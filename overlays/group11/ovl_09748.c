/* EE Battle-Effect Overlay: group 0x11, file 09748
 * Load base: 0x01B00000, .text: 0x01B00738..0x01B01258 (14 functions)
 */
#include "../oef_overlay.h"

typedef struct P48Part {
    u8 pad00[8];
    int cnt;           /* 0x08 */
    u8 pad0C[0x12];
    u16 enabled;       /* 0x1E */
    u8 pad20[0x20];
    float position[4]; /* 0x40 */
    int rotation[3];   /* 0x50 */
    int flag5C;        /* 0x5C */
    float scale[4];    /* 0x60 */
    u8 pad70[0x10];
} P48Part;

typedef struct P48Ent {
    int chr;           /* 0x00 */
    void *hnd;         /* 0x04 */
    int state;         /* 0x08 */
    int dur;           /* 0x0C */
    int cnt;           /* 0x10 */
    short a14;         /* 0x14 */
    short a16;         /* 0x16 */
} P48Ent;

extern u8 D_01B00040[];
extern int D_01B00720;
extern int D_01B00724;
extern int D_01B00728;
extern int D_01B01280;
extern void *D_01B01284;
extern void *D_01B01288;
extern void *D_01B0128C;
extern P48Part D_01B01290;
extern P48Part D_01B01310;
extern OefHeapMgr D_01B01390;
extern u8 D_01B013C0[];
extern u8 D_01C013C0[];
extern int D_01D013C0;
extern int D_01D013C4;
extern int D_01D013C8;
extern void *D_01D013CC;
extern void *D_01D013D0;
extern P48Ent D_01D013F0[3];
extern OefHeapCfg D_01D01450;
extern u8 D_01D158F0[];

void func_0026BE48(void *mtx, int angle);
void func_002DCE08(void *out, void *m, void *in);
void func_002B2A80(void *p, int a, int b, int c);
void func_002B2FF0(u32 rgba, int a, int b);
void *func_001B4E58(int id);
float func_001B6EA8(int id);
float func_001B5400(int id);
int func_001CDAF8(int id);
void func_001CDC58(int id, int v);
int func_001CDDD8(int id);
void func_001CE2F0(int h, int v);
int func_001CE050_i(int h, int v) __asm__("func_001CE050");
void *func_001CE048(int id);
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

void func_01B00738(float *out, float len, int angle)
{
    float m[16];
    float z = 0.0f;

    func_0026BE48(m, -angle);
    out[0] = len;
    out[3] = 1.0f;
    out[2] = z;
    out[1] = z;
    func_002DCE08(out, m, out);
}

void func_01B007A0(int cur, int start, int fin, int fout, u8 r, u8 g, u8 b, int prio)
{
    int t = cur - start;
    int total;
    int alpha;
    unsigned long long col;
    unsigned long long *p;

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
            col = (r | ((unsigned long long)(u8)alpha << 24)) | (((unsigned long long)b << 16) | ((unsigned long long)g << 8));
            ((unsigned long long *)p)[2] = 0x4023400000008001ULL;
            ((unsigned long long *)p)[3] = 21998;
            ((unsigned long long *)p)[4] = prio;
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

void func_01B008B0(void *res)
{
    void **p0 = &D_01B01284;
    void **p1 = &D_01B01288;
    void **p2 = &D_01B0128C;

    func_002B4980(res);
    func_002D02E8(res, 0, 1000, 0x100);
    func_002944B0(res, 0, 1000, 0x100);
    *p0 = func_002B49A0(res, 6, 0);
    *p1 = func_002B49A0(res, 6, 1);
    *p2 = func_002B49A0(res, 6, 2);
}

void func_01B00960(P48Ent *e, int chr)
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

void func_01B009D8(P48Ent *e, int state)
{
    if (e->chr != 255) {
        e->cnt = 0;
        e->state = state;
        e->dur = func_001CE050_i(e->chr, state);
    }
}

void func_01B00A18(P48Part *o, int id,
    float x, float y, float z, float rx, float ry, float rz,
    float sx, float sy, float sz)
{
    D_006A3924 = &D_01B01390;
    _pppStartPart((OefPartObj *)o, 0x1000, D_01D01450.pdt[id], 1);
    o->rotation[0] = (int)rx;
    o->rotation[1] = (int)ry;
    o->position[0] = x;
    o->rotation[2] = (int)rz;
    o->position[1] = y;
    o->position[2] = z;
    o->scale[0] = sx;
    o->scale[1] = sy;
    o->scale[2] = sz;
    o->position[3] = 1.0f;
    o->enabled = 1;
    o->flag5C = 1;
    o->scale[3] = 1.0f;
}

void func_01B00B28(P48Part *o)
{
    if (o->enabled != 0) {
        pppSetMatrix((OefPartObj *)o);
        func_002DCE38(D_006A39B0, D_006A3970, D_006A3930);
        func_002DCE38(D_006A3AB0, D_006A3A70, D_006A39B0);
        D_006A3924 = &D_01B01390;
        if (_pppRunPart((OefPartObj *)o, 0x30) != 0) {
            o->enabled = 0;
        }
    }
}

int func_01B00BC0(int eff_id)
{
    u8 target_buf[16];

    D_01B01280 = eff_id;
    D_01D013C4 = MsGetEff2Chr(eff_id);
    D_01D013C8 = *MsGetTargetList(D_01B01280, target_buf);
    D_01D013CC = MsGetChrHandle(D_01D013C4);
    D_01D013D0 = MsGetChrHandle(D_01D013C8);
    func_01B00960(&D_01D013F0[0], D_01D013C4);
    func_01B00960(&D_01D013F0[1], D_01D013C4 + 1);
    func_01B00960(&D_01D013F0[2], D_01D013C4 + 2);
    D_01D013C0 = 0;
    func_01B008B0(D_01D158F0);
    _pppInitData(&D_01D01450, D_01B00040);
    pppInitEnv(&D_01B01390, &D_01D01450, D_01B013C0, 0x100000);
    func_00110BC8(D_01D013F0[0].hnd, 0, 1);
    return 0;
}

int func_01B00CD0(void)
{
    return 0;
}

int func_01B00CD8(void)
{
    return 0;
}

int func_01B00CE0(void)
{
    int i;
    int j;
    P48Ent *e;
    float v[4];

    if (D_01B00720 == 0) {
        if (func_0029B830_i(D_01B01280) != 0) {
            return 0;
        }
        D_01B00720++;
    }
    if (D_01B00724 == 0) {
        D_01B00724 = 1;
        func_001CDC58(D_01B01280, 0);
    }
    if (D_01B00728 == 0) {
        if (func_001CDAF8(D_01B01280) > 0) {
            goto inc;
        }
        return 0;
    inc:
        D_01B00728++;
    }
    if (func_00116068() == 0) {
        D_006A3BC4 = 1;
    } else {
        D_006A3BC4 = 0;
    }
    if (D_006A3BC4 != 0) {
        return D_006A3BC4;
    }
    if (D_01D013C0 == 0) {
        func_00294B70(D_01B01284, 64, 256);
        func_01B009D8(&D_01D013F0[0], 176);
        func_01B009D8(&D_01D013F0[1], 176);
        func_01B009D8(&D_01D013F0[2], 176);
    }
    e = D_01D013F0;
    for (i = 0; i < 3; i++, e++) {
        switch (e->state) {
        case 176:
            if (e->cnt == e->dur) {
                func_01B009D8(e, 177);
            }
            break;
        case 177:
            if (i == 0 && e->cnt == 34) {
                func_01B00A18(&D_01B01290, 0, 0.0f, 0.0f, 0.0f, 0.0f,
                    (float)(-e->a16 - 0x4000), 0.0f, 0.15f, 0.15f, 0.15f);
                func_00107428(D_01D013F0[0].hnd, 38, 0, D_01B01290.position);
                func_01B00738(v, 10.0f, D_01D013F0[0].a16);
                D_01B01290.position[0] += v[0];
                D_01B01290.position[1] -= 20.0f;
                D_01B01290.position[2] += v[2];
                D_01B01290.position[3] = 1.0f;
                func_00294B70(D_01B01288, 64, 256);
            }
            if (e->cnt == 90) {
                func_01B009D8(e, 178);
            }
            break;
        case 178:
            break;
        }
    }
    if (D_01B01290.enabled != 0) {
        if (D_01B01290.cnt == 0x50000) {
            func_00294B70(D_01B0128C, 64, 256);
            func_01B00A18(&D_01B01310, 1, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.3f, 0.3f, 0.3f);
        }
    }
    if (D_01B01310.enabled != 0) {
        func_001B6790(D_01D013C8, D_01B01310.position);
        D_01B01310.position[1] = func_001B5400(D_01D013C8) - 1.0f;
        if (D_01B01310.cnt == 0xf000) {
            func_001C5E90(D_01B01280, -5, 0);
        }
    }
    if (D_006A3BC4 == 0) {
        j = 2;
        e = D_01D013F0;
        do {
            e->cnt++;
            e++;
        } while (--j >= 0);
    }
    return 0;
}

int func_01B010B0(void)
{
    u32 n;
    int i;
    P48Ent *e;

    if (D_01B00728 == 0 || D_01D013C0 < 0) {
        return 0;
    }
    D_006A3BCC = D_01C013C0;
    D_006A3924 = &D_01B01390;
    func_001AACA0(D_006A3A70);
    func_001A9EE0(D_006A3970);
    if (D_01B01290.enabled != 0) {
        n = D_01B01290.cnt >> 12;
        if (n < 30) {
            func_002B2FF0(((n << 6) / 30) << 24, 0x44, 0);
        } else if (n < 80) {
            func_002B2FF0(0x40000000, 0x44, 0);
        } else {
            func_01B007A0(n, 80, 1, 8, 255, 255, 255, 0x44);
        }
    }
    func_01B00B28(&D_01B01290);
    func_01B00B28(&D_01B01310);
    if (D_01D013F0[0].state == 178 && D_01D013F0[0].cnt == D_01D013F0[0].dur) {
        e = D_01D013F0;
        i = 2;
        do {
            func_001CE2F0(e->chr, 0);
            e++;
        } while (--i >= 0);
        func_001CDDD8(D_01B01280);
    }
    D_01D013C0++;
    return 0;
}

int func_01B01248(void)
{
    return 0;
}

void func_01B01250(void)
{
}
