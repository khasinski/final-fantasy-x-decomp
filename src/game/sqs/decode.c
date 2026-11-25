/* tu_277 0x254028-0x254a38: medium; decode (config/tu_map.tsv) */
#define TkMtCalcSpline _hdr_TkMtCalcSpline
#define func_002D5448 _hdr_func_002D5448
#define spline_get_near_point _hdr_spline_get_near_point
#define spline_get_near_point_init _hdr_spline_get_near_point_init
#include "common.h"
#include "ffx/r6.h"
#include "ffx/w8.h"
#include "ffx/q6.h"
#include "ffx/s6.h"
#include "ffx/u4.h"
#include "ffx/v6.h"
#undef spline_get_near_point_init
#undef spline_get_near_point
#undef func_002D5448
#undef TkMtCalcSpline

int func_00254028(Actor *a, int b, ScriptCtx *ctx) {
    AtelPopStackInteger(a, ctx);
    return 0;
}

extern float D_00327068;
extern float D_0032706C;
void TkMtCalcSpline(void *, void *, int, float);
void func_002D5448(void *, void *, int, float);

typedef struct {
    int count;
    int pad[3];
    float pts[1][4];
} DecodeSpline;

float spline_get_near_point(DecodeSpline *sp, float x, float y, float z, float *ox, float *oy, float *oz, int flag)
{
    float p0[4];
    float p1[4];
    float p2[4];
    float *pp1 = p1;
    float *pp2 = p2;
    int i;
    register void *pts __asm__("$21") = sp->pts;
    register int count __asm__("$19") = sp->count;
    float step = 10.0f / D_0032706C;

    for (i = 0; i < 40; i++) {
        float dt = step / (float)(i * i + 1);
        float d0, d1, d2;
        float dx, dy, dz;

        if (flag == 0) {
            TkMtCalcSpline(pp1, pts, count, D_00327068 - dt);
        } else {
            func_002D5448(pp1, pts, count, D_00327068 - dt);
        }
        dx = p1[0] - x;
        dy = p1[1] - y;
        dz = p1[2] - z;
        d1 = dx * dx + dy * dy + dz * dz;

        if (flag == 0) {
            TkMtCalcSpline(pp2, pts, count, D_00327068 + dt);
        } else {
            func_002D5448(pp2, pts, count, D_00327068 + dt);
        }
        dx = p2[0] - x;
        dy = p2[1] - y;
        dz = p2[2] - z;
        d2 = dx * dx + dy * dy + dz * dz;

        if (flag == 0) {
            TkMtCalcSpline(p0, pts, count, D_00327068);
        } else {
            func_002D5448(p0, pts, count, D_00327068);
        }
        dx = p0[0] - x;
        dy = p0[1] - y;
        dz = p0[2] - z;
        d0 = dx * dx + dy * dy + dz * dz;

        if (d1 == d2) {
            *ox = p0[0];
            *oy = p0[1];
            *oz = p0[2];
            break;
        }
        if (d1 < d2) {
            if (d1 < d0) {
                D_00327068 -= dt;
                if (D_00327068 < 0.0f) {
                    *ox = p0[0];
                    *oy = p0[1];
                    *oz = p0[2];
                    return D_00327068 + dt;
                }
                *ox = p1[0];
                *oy = p1[1];
                *oz = p1[2];
            } else {
                *ox = p0[0];
                *oy = p0[1];
                *oz = p0[2];
            }
        } else {
            if (d2 < d0) {
                D_00327068 += dt;
                if (D_00327068 > 1.0f) {
                    *ox = p0[0];
                    *oy = p0[1];
                    *oz = p0[2];
                    return D_00327068 - dt;
                }
                *ox = p2[0];
                *oy = p2[1];
                *oz = p2[2];
            } else {
                *ox = p0[0];
                *oy = p0[1];
                *oz = p0[2];
            }
        }
    }
    return D_00327068;
}

float sqrtf(float);

float spline_get_near_point_init(DecodeSpline *sp, int flag, float x, float y, float z)
{
    float p[4];
    float prev[4];
    float diff[4];
    register float rx __asm__("$f23") = x;
    register float rz __asm__("$f22") = z;
    register float ry __asm__("$f21") = y;
    int count;
    void *pts;
    float t;
    float step;
    float min_d2;

    *(s32 *)&D_0032706C = 0;
    t = D_0032706C;
    D_00327068 = t;
    pts = sp->pts;
    count = sp->count;
    step = 1.0f / (float)(count * 10);
    min_d2 = 999999.0f;
    if (flag == 0) {
        TkMtCalcSpline(prev, pts, count, t);
    } else {
        func_002D5448(prev, pts, count, t);
    }
    for (;;) {
        float d2;
        if (flag == 0) {
            TkMtCalcSpline(p, pts, count, t);
        } else {
            func_002D5448(p, pts, count, t);
        }
        diff[0] = p[0] - prev[0];
        diff[1] = p[1] - prev[1];
        diff[2] = p[2] - prev[2];
        D_0032706C += sqrtf(diff[0] * diff[0] + diff[1] * diff[1] + diff[2] * diff[2]);
        diff[0] = p[0] - rx;
        diff[1] = p[1] - ry;
        diff[2] = p[2] - rz;
        d2 = diff[0] * diff[0] + diff[1] * diff[1] + diff[2] * diff[2];
        if (d2 < min_d2) {
            min_d2 = d2;
            D_00327068 = t;
        }
        t += step;
        prev[0] = p[0];
        prev[1] = p[1];
        prev[2] = p[2];
        if (t > 1.0f) {
            break;
        }
    }
    return spline_get_near_point(sp, rx, ry, rz, &diff[0], &diff[1], &diff[2], flag);
}

typedef struct {
    u8 pad0[0x503E0];
    float m0[16];
    float m1[16];
    float m2[16];
    float m3[16];
    float v0[4];
    float v1[4];
    float v2[4];
    float f50510;
    u8 pad50514[0x14];
    s32 w50528;
    u8 pad5052C[0x5076C - 0x5052C];
    s8 b5076C;
    u8 pad5076D[6];
    s8 b50773;
} Decode503E0;

extern float D_0031430C;
void func_001ACB48(void *a, void *b, void *c, void *d, float f);
void MsSetCameraMatrix(int a, void *b, void *c, void *d, void *e, float f);
void yiRenderEnable(int a);
void func_00173450(void *a, void *b);

void func_002545E0(Decode503E0 *a)
{
    int i;

    D_0031430C = a->f50510;
    func_001ACB48(a->m0, a->v0, a->v1, a->v2, 0.0f);
    MsSetCameraMatrix(1, a->m1, a->m0, a->v1, a->v0, a->f50510);
    switch (a->b50773) {
    case 1:
        if (a->w50528 >= 0x406) {
            a->b50773 = 2;
        }
        break;
    case 2:
        yiRenderEnable(0x800);
        func_00173450(a->m3, a->m2);
        break;
    }
    for (i = 0; i < 16; i++) {
        a->m2[i] = a->m0[i];
        a->m3[i] = a->m1[i];
    }
}

typedef struct {
    float f00;
    float f04;
    float f08;
    float f0C;
    float f10;
    float f14;
    float f18;
    float f1C;
    float f20;
    float f24;
} MsScreen;

extern MsScreen _dec_ms_screen __asm__("ms_screen");
float func_002E8AB0(float);
void func_002DD610(float *, float, float, float, float, float, float, float, float, float);

void func_00254730(float *a0, int a1, int a2, Decode503E0 *a3)
{
    MsScreen *scr = &_dec_ms_screen;
    float f20 = (float)a1;
    /* DEBT(FAKE): register pins fix $f0..$f4 allocation in tanf argument */
    register float pi __asm__("$f1") = 3.1415f;
    register float d180 __asm__("$f4") = 180.0f;
    register float f4 __asm__("$f3") = 4.0f;
    float aspect = ((float)a2 * f4) / (f20 * 3.0f);
    float t;
    float d;
    float sx;

    {
        register float fov __asm__("$f12") = a0[9];
        register float prod __asm__("$f1") = fov * pi;
        register float q __asm__("$f12") = prod / d180;
        t = q * 0.5f;
    }

    t = func_002E8AB0(t);

    if (a3->b5076C == 0) {
        a3->f50510 = 1024.0f;
    } else {
        a3->f50510 = (f20 * 0.5f) / t;
    }
    d = a3->f50510;
    sx = f20 / ((d + d) * t);
    func_002DD610(a3->m1, d, sx, sx * aspect,
        scr->f20, scr->f24,
        scr->f00, scr->f04,
        scr->f08, scr->f0C);
    a3->v0[0] = a0[0];
    a3->v0[1] = -a0[1];
    a3->v0[2] = -a0[2];
    a3->v0[3] = 1.0f;
    a3->v1[0] = a0[3];
    a3->v1[1] = -a0[4];
    a3->v1[2] = -a0[5];
    a3->v1[3] = 1.0f;
    a3->v2[0] = a0[6] - a0[0];
    a3->v2[1] = -(a0[7] - a0[1]);
    a3->v2[2] = -(a0[8] - a0[2]);
    a3->v2[3] = 1.0f;
}

int func_00254910(u8 *p, void *dst, int *out)
{
    int len = p[1] + (p[2] << 8) + (p[3] << 16) + (p[4] << 24);

    func_002EEF1C(dst, p + 5, len);
    *out = len;
    return len;
}

int sa_decode(int a, u8 *p)
{
    int out;

    D_00327070[*p](p, a, &out);
    return out;
}

int func_002549C8(u8 *p)
{
    if (p[0] != 1) {
        func_001577A8(D_00573818, D_00573820, 0x40);
    }
    return p[1] + (p[2] << 8) + (p[3] << 16) + (p[4] << 24);
}
