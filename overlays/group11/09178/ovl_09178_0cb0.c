/* Shared 09176/09391 beam launch setup (752 B). */

#include "vu0.h"

typedef float sceVu0FVECTOR[4] __attribute__((aligned(16)));
typedef float sceVu0FMATRIX[4][4] __attribute__((aligned(16)));

typedef struct {
    u8 pad00[0xC4];
    float fC4;
    u8 padC8[0x08];
    sceVu0FVECTOR pos;
    u8 padE0[0x30];
    void *w110;
    u8 pad114[0x0C];
    int w120;
    u8 pad124[0x13C];
    u8 s260[0x210];
    u8 b470;
    u8 b471;
    u8 b472;
    u8 b473;
    u8 pad474[0x0C];
    float f480;
    int pad484;
    int w488;
    int pad48C;
    u8 s490[0x40];
    sceVu0FVECTOR p0;
    sceVu0FVECTOR p1;
    sceVu0FVECTOR p2;
    sceVu0FVECTOR p3;
    float t;
    float dt;
    int w518;
    int w51C;
    int w520;
    int w524;
} OvlWork;

extern u8 g_ovl_res[];
extern u8 g_ovl_dat_04c8[];
extern u8 g_ovl_dat_4680[];
extern u8 g_ovl_mgr[];

extern float func_002B3DB0(float);
extern float func_002B3DF8(float);
extern void func_002DCE08(void *, void *, void *);
extern void func_002DD128(void *);
extern void func_002DD318(void *, void *, float);
extern int fn_ovl_1550(int);
extern float fn_ovl_1678(int);
extern void fn_ovl_17a0(int, void *, int);
extern float fn_ovl_1bf0(int);
extern void fn_ovl_3848(void *, void *, void *);
extern int fn_ovl_40c0(void *, void *, int, int, int, void *, float);
extern void **fn_ovl_4650(void *, int);
extern void fn_ovl_4df0(void *, void *, void *);
extern void fn_ovl_5668(void *, void *, void *);

void ovl_09178_0cb0(OvlWork *work)
{
    sceVu0FMATRIX mat;
    sceVu0FVECTOR p0;
    sceVu0FVECTOR p1;
    sceVu0FVECTOR off;
    sceVu0FVECTOR rot;
    float dx;
    float dy;
    float dz;
    float fy;

    fn_ovl_17a0(work->w518, p0, 5);
    fn_ovl_17a0(-1, p1, 5);
    fn_ovl_40c0(g_ovl_mgr, work, 0, 0, 16, g_ovl_dat_4680, 0.06f);
    MMI_COPY_LQ_A3(work->pos, p0);
    MMI_COPY_SQ_A3(work->pos);
    work->fC4 = fn_ovl_1678(0);
    work->w120 = fn_ovl_1550(work->w518);
    fn_ovl_3848(work->s490, g_ovl_res, g_ovl_dat_04c8);
    work->w110 = work->s490;

    dx = (p1[0] - p0[0]) / 3.0f;
    dy = (p1[1] - p0[1]) / 3.0f;
    dz = (p1[2] - p0[2]) / 3.0f;
    MMI_COPY_LQ_A3(work->p0, p0);
    MMI_COPY_SQ_A3(work->p0);

    off[0] = func_002B3DB0(40.0f);
    off[1] = func_002B3DF8(20.0f);
    off[2] = 0.0f;
    off[3] = 1.0f;
    fn_ovl_4df0(rot, p0, p1);
    func_002DD128(mat);
    func_002DD318(mat, mat, rot[1]);
    func_002DCE08(off, mat, off);

    {
        float *vp = work->p1;
        vp[0] = p0[0] + dx + off[0];
        vp[1] = p0[1] + dy + off[1];
        vp[2] = p0[2] + dz + off[2];
        vp[3] = 1.0f;
        fy = fn_ovl_1bf0(work->w518);
        if (vp[1] > fy) {
            vp[1] = fy - 1.0f;
        }

        vp = work->p2;
        vp[0] = p0[0] + (dx + dx) - off[0];
        vp[1] = p0[1] + (dy + dy) - off[1];
        vp[2] = p0[2] + (dz + dz) - off[2];
        vp[3] = 1.0f;
    }
    MMI_COPY_LQ_A3(work->p3, p1);
    MMI_COPY_SQ_A3(work->p3);

    work->t = 0.0f;
    work->dt = 1.0f / 12.0f;
    work->w51C = 12;
    work->w524 = 16;
    {
        void *tex = *fn_ovl_4650(g_ovl_mgr, 4);
        fn_ovl_5668(work->s260, tex, p0);
    }
    work->b473 = 64;
    work->b472 = 64;
    work->b471 = 64;
    work->b470 = 64;
    work->f480 = 0.5f;
    work->w488 = 128;
}
