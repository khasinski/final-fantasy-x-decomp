/* Debug spline point editor for 09142 (0x01B042B0..0x01B04480) and 09395 (0x01B055B8..0x01B05788). */
#include "common.h"

typedef unsigned int u_long128 __attribute__((mode(TI)));

typedef struct Vec4 {
    float x, y, z, w;
} __attribute__((aligned(16))) Vec4;

extern u16 D_01B00F10;
extern u16 D_01B00F14;
extern u8 D_01B00F16;
extern s32 D_01B00F1C;
extern u_long128 D_01B00F20;
extern char D_01B047D0[];
extern u8 D_01B047F0[];
extern u8 D_006A3970[];
extern u8 D_006A3A70[];

extern void func_01B03598(void *, void *, void *);
extern void func_01B04028(void);
extern void func_01B04158(void *, int);
extern void func_002DCE38(void *, void *, void *);
extern void func_002EF240(const char *, ...);
extern void op_spline_xyz_table(void *, void *, int);
extern void op_spline_draw_path3(void *, void *, int, void *, void *);

void func_01B042B0(void *a0, Vec4 *pts, int count)
{
    float mtx[16];
    Vec4 *p;

    p = &pts[D_01B00F1C];
    D_01B00F20 = *(u_long128 *)p;
    func_01B03598(&D_01B00F20, 0, 0);
    if (D_01B00F10 != 0) {
        if (D_01B00F14 & 0x100) {
            func_01B04158(pts, count);
        } else if (D_01B00F16 < 2) {
            if (D_01B00F14 & 2) {
                D_01B00F1C++;
                if (D_01B00F1C >= count) {
                    D_01B00F1C = 0;
                }
reload:
                p = &pts[D_01B00F1C];
                D_01B00F20 = *(u_long128 *)p;
            } else if ((u16)(D_01B00F14 & 1)) {
                D_01B00F1C--;
                if (D_01B00F1C < 0) {
                    D_01B00F1C = count - 1;
                }
                goto reload;
            }
        }
        *(u_long128 *)p = D_01B00F20;
        func_002EF240(D_01B047D0, (double)p->x, (double)p->y, (double)p->z);
        op_spline_xyz_table(a0, pts, count);
    }
    func_01B04028();
    func_002DCE38(mtx, D_006A3A70, D_006A3970);
    op_spline_draw_path3(pts, a0, count, mtx, D_01B047F0);
}
