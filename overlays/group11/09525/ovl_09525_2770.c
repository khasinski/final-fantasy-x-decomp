#include "common.h"

typedef unsigned long u64;

typedef struct ClipVert {
    s32 x, y, z, w;
    float f10;
    u8 clipped;
    u8 pad15[0xB];
} __attribute__((aligned(16))) ClipVert;

typedef struct Part30 {
    u8 pad00[0x28];
    s16 h28;
    u8 pad2A[6];
} Part30;

extern u8 D_006A3970[];
extern u8 D_006A3A70[];
extern u16 D_01B00568;
extern u16 D_01B0056C;
extern u8 D_01B0056E;
extern int D_01B00574;
extern Part30 D_01B00660[128];
extern char D_01B046E0[];
extern char D_01B04708[];
extern char D_01B04720[];
extern u_long128 D_01B06340;

extern void func_002B33F8(void *, void *, int, void *, void *);
extern void func_002B5C18(void *, void *, int);
extern void func_002DCE08(float *, void *, float *);
extern void func_002DCE38(float *, void *, void *);
extern void func_002DCFD8(float *, float *);
extern int func_002DD9B0(float *);
extern void func_002EF240(const char *, ...);
extern void func_01B02000(void *, int, int);
extern void func_01B02570(void);
extern void func_01B025B0(void);
extern void func_01B025D0(u32, u32, u32, u32, u64);
extern void func_01B02758(s32 *, float *);

void func_01B02770(void *mtx, float *p0, float *p1, u64 rgba)
{
    float cur[4];
    float step[4];
    float proj[4];
    ClipVert vcur;
    ClipVert vprev;
    int i;

    step[0] = (p1[0] - p0[0]) * 0.125f;
    step[1] = (p1[1] - p0[1]) * 0.125f;
    step[2] = (p1[2] - p0[2]) * 0.125f;
    cur[0] = p0[0];
    cur[1] = p0[1];
    cur[2] = p0[2];
    cur[3] = 1.0f;
    func_01B02570();
    i = 9;
    do {
        register float w __asm__("$f12");
        func_002DCE08(proj, mtx, cur);
        w = proj[3];
        if (w > 0.0f) {
            func_002DCFD8(proj, proj);
            if (func_002DD9B0(proj) == 0) {
                func_01B02758(&vcur.x, proj);
                vcur.f10 = proj[3];
                vcur.clipped = 0;
            } else {
                vcur.clipped = 1;
            }
        } else {
            vcur.clipped = 1;
        }
        if (i != 9 && vcur.clipped == 0 && vprev.clipped == 0) {
            func_01B025D0(vprev.x, vprev.y, vcur.x, vcur.y, rgba);
        }
        i--;
        vprev = vcur;
        cur[0] += step[0];
        cur[1] += step[1];
        cur[2] += step[2];
    } while (i != 0);
    func_01B025B0();
}

void func_01B02920(void)
{
    float pts[6][4];
    float mtx[16];
    float *p = (float *)&D_01B06340;

    pts[0][0] = pts[1][0] = pts[2][0] = pts[3][0] = pts[4][0] = pts[5][0] = p[0];
    pts[0][1] = pts[1][1] = pts[2][1] = pts[3][1] = pts[4][1] = pts[5][1] = p[1];
    pts[0][2] = pts[1][2] = pts[2][2] = pts[3][2] = pts[4][2] = pts[5][2] = p[2];
    pts[0][0] -= 50.0f;
    pts[1][0] += 50.0f;
    pts[2][1] -= 50.0f;
    pts[3][1] += 50.0f;
    pts[4][2] -= 50.0f;
    pts[5][2] += 50.0f;
    func_002DCE38(mtx, D_006A3A70, D_006A3970);
    func_01B02770(mtx, pts[0], pts[1], 0x3F800000FF8080FFULL);
    func_01B02770(mtx, pts[2], pts[3], 0x3F800000FF80FF80ULL);
    func_01B02770(mtx, pts[4], pts[5], 0x3F800000FF80FFFFULL);
}

void func_01B02A40(float (*m)[4], int n)
{
    int i;

    for (i = 0; i < n; i++, m++) {
        func_002EF240(D_01B046E0, (*m)[0], (*m)[1], (*m)[2], (*m)[3], i);
    }
}

void func_01B02B08(void *a0, float (*pts)[4], int n,
                   float x0, float y0, float z0,
                   float x1, float y1, float z1)
{
    int i;
    float (*p)[4] = pts;

    for (i = 0; i < n; i++, p++) {
        float t = (float)i / (float)(n - 1);
        (*p)[0] = x0 + (x1 - x0) * t;
        (*p)[1] = y0 + (y1 - y0) * t;
        (*p)[2] = z0 + (z1 - z0) * t;
        (*p)[3] = 1.0f;
    }
    func_002B5C18(a0, pts, n);
}

void func_01B02B90(void *a0, u_long128 *pts, int n)
{
    float mtx[16];
    u_long128 *cur = &pts[D_01B00574];

    D_01B06340 = *cur;
    func_01B02000(&D_01B06340, 0, 0);
    if (D_01B00568 != 0) {
        if (D_01B0056C & 0x100) {
            func_01B02A40((float (*)[4])pts, n);
        } else if (D_01B0056E < 2) {
            if (D_01B0056C & 2) {
                D_01B00574++;
                if (D_01B00574 >= n) {
                    D_01B00574 = 0;
                }
            reload:
                cur = &pts[D_01B00574];
                D_01B06340 = *cur;
            } else if (D_01B0056C & 1) {
                D_01B00574--;
                if (D_01B00574 < 0) {
                    D_01B00574 = n - 1;
                }
                goto reload;
            }
        }
        *cur = D_01B06340;
        func_002EF240(D_01B04708, ((float *)cur)[0], ((float *)cur)[1], ((float *)cur)[2]);
        func_002B5C18(a0, pts, n);
    }
    func_01B02920();
    func_002DCE38(mtx, D_006A3A70, D_006A3970);
    func_002B33F8(pts, a0, n, mtx, D_01B04720);
}

void func_01B02D48(void)
{
    int i;

    for (i = 127; i >= 0; i--) {
        D_01B00660[i].h28 = 0;
    }
}

Part30 *func_01B02D80(void)
{
    Part30 *p = D_01B00660;
    int i;

    for (i = 127; i != -1; i--, p++) {
        if (p->h28 == 0) {
            return p;
        }
    }
    return 0;
}
