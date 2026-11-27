#include "common.h"

extern u8 *g_state_db20;
typedef struct {
    float x, y, z;
} Vec3_6158;

extern Vec3_6158 g_vec_08e0[];

extern void *g_fn_b188(int);
extern void func_002DCF48(void *, void *);
extern void func_002DCE08(void *, void *, void *);

void func_01B06100(void *a0)
{
    u8 mat[0x40];
    u8 *st = g_state_db20;

    func_002DCF48(mat, g_fn_b188(0));
    func_002DCE08(a0, mat, st + 0xCB0);
}

void func_01B06158(void)
{
    float v[4];
    Vec3_6158 *p;
    register float x __asm__("$f5");
    register float y __asm__("$f2");
    register float z __asm__("$f0");
    register float c1 __asm__("$f3");
    register float y1 __asm__("$f1");
    register float c4 __asm__("$f4");
    register float y2 __asm__("$f2");

    func_01B06100(v);
    p = g_vec_08e0;
    x = v[0];
    c1 = 5.9999f;
    y = v[1];
    x = x + c1;
    z = v[2];
    c1 = 6.4552f;
    y1 = 15.0f;
    z = z - c1;
    c4 = 40.0f;
    y1 = y - y1;
    p->x = x;
    y2 = y - c4;
    p->z = z;
    p->y = y1;
    p++;
    p->x = x;
    p->y = y2;
    p->z = z;
}
