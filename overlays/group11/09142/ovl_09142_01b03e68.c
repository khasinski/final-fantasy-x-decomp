/* 3D clipped line + axes helpers for 09142 (0x01B03E68..0x01B04148) and 09395 (0x01B05170..0x01B05450). */
#include "common.h"

typedef unsigned long u64;

typedef struct ClipVert {
    s32 x, y, z, w;
    float f10;
    u8 clipped;
    u8 pad15[0xB];
} __attribute__((aligned(16))) ClipVert;

extern u8 D_006A3970[];
extern u8 D_006A3A70[];
extern float D_01B00F20[3];

extern void func_01B03B28(void);
extern void func_01B03B68(void);
extern void func_01B03B88(u32 x0, u32 y0, u32 z0, u32 x1, u32 y1, u32 z1, u64 rgba);
extern void func_01B03E50(s32 *dst, float *src);
extern void func_002DCE08(float *, void *, float *);
extern void func_002DCE38(float *, void *, void *);
extern void func_002DCFD8(float *, float *, float);
extern int func_002DD9B0(float *);

void func_01B03E68(void *mtx, float *p0, float *p1, u64 rgba)
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
    func_01B03B28();
    i = 9;
    do {
        func_002DCE08(proj, mtx, cur);
        if (proj[3] > 0.0f) {
            func_002DCFD8(proj, proj, proj[3]);
            if (func_002DD9B0(proj) == 0) {
                func_01B03E50(&vcur.x, proj);
                vcur.f10 = proj[3];
                vcur.clipped = 0;
            } else {
                vcur.clipped = 1;
            }
        } else {
            vcur.clipped = 1;
        }
        if (i != 9 && vcur.clipped == 0 && vprev.clipped == 0) {
            func_01B03B88(vprev.x, vprev.y, vprev.z, vcur.x, vcur.y, vcur.z, rgba);
        }
        i--;
        vprev = vcur;
        cur[0] += step[0];
        cur[1] += step[1];
        cur[2] += step[2];
    } while (i != 0);
    func_01B03B68();
}

void func_01B04028(void)
{
    float pts[6][4];
    float mtx[16];

    pts[0][0] = pts[1][0] = pts[2][0] = pts[3][0] = pts[4][0] = pts[5][0] = D_01B00F20[0];
    pts[0][1] = pts[1][1] = pts[2][1] = pts[3][1] = pts[4][1] = pts[5][1] = D_01B00F20[1];
    pts[0][2] = pts[1][2] = pts[2][2] = pts[3][2] = pts[4][2] = pts[5][2] = D_01B00F20[2];
    pts[0][0] -= 50.0f;
    pts[1][0] += 50.0f;
    pts[2][1] -= 50.0f;
    pts[3][1] += 50.0f;
    pts[4][2] -= 50.0f;
    pts[5][2] += 50.0f;
    func_002DCE38(mtx, D_006A3A70, D_006A3970);
    func_01B03E68(mtx, pts[0], pts[1], 0x3F800000FF8080FFULL);
    func_01B03E68(mtx, pts[2], pts[3], 0x3F800000FF80FF80ULL);
    func_01B03E68(mtx, pts[4], pts[5], 0x3F800000FF80FFFFULL);
}
