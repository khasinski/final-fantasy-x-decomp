#include "common.h"

typedef struct {
    float x, y, z, w;
} __attribute__((aligned(16))) Vec7A08;

typedef struct {
    Vec7A08 pos;     /* 0x00 */
    float vx;        /* 0x10 */
    float vy;        /* 0x14 */
    float vz;        /* 0x18 */
    float f1C;       /* 0x1C */
    float f20;       /* 0x20 */
    float f24;       /* 0x24 */
    float f28;       /* 0x28 */
    float f2C;       /* 0x2C */
    u8 x30[0x0C];    /* 0x30 */
    float f3C;       /* 0x3C */
    u8 pad40[0x0C];  /* 0x40 */
    int w4C;         /* 0x4C */
    int w50;         /* 0x50 */
    u8 pad54[0x17];  /* 0x54 */
    u8 b6B;          /* 0x6B */
} Part7A08;

extern u8 g_sym_67a0[];
extern void g_fn_8d70(int, void *, int);
extern Part7A08 *g_fn_f728(void);
extern void g_fn_cfb8(void *, int);

extern int func_002B49A0(void *, int, int);
extern float func_002B3DB0(float);

void func_01B05238(int a0, int a1, float f12)
{
    Vec7A08 pos;
    int i;

    g_fn_8d70(a0, &pos, 0);
    pos.y = f12;
    i = 0;
    do {
        Part7A08 *p = g_fn_f728();
        if (p == 0) {
            break;
        }
        g_fn_cfb8(p->x30, func_002B49A0(g_sym_67a0, 9, 1));
        {
            register u_long128 q __asm__("$7") = *(u_long128 *)&pos;
            *(u_long128 *)&p->pos = q;
        }
        __asm__ volatile("");
        {
            register float f20 __asm__("$f20") = -0.01f;
            register float f23 __asm__("$f23") = 0.01f;
            register float f24 __asm__("$f24") = 1.0f;
            p->pos.x += func_002B3DB0(2.0f);
            p->pos.y += func_002B3DB0(2.0f);
            p->pos.z += func_002B3DB0(2.0f);
            p->vx = func_002B3DB0(0.1f);
            p->vy = func_002B3DB0(0.1f);
            p->vz = func_002B3DB0(0.1f);
            p->f1C = func_002B3DB0(3.1415927f);
            p->f20 = p->vx * f20;
            p->f24 = f23;
            p->f28 = p->vz * f20;
            p->f2C = f24;
            p->f3C = func_002B3DB0(0.025f) + 0.15f;
            p->b6B = a1;
            p->w50 = 0;
            p->w4C = 0x20;

            p = g_fn_f728();
            if (p == 0) {
                break;
            }
            g_fn_cfb8(p->x30, func_002B49A0(g_sym_67a0, 9, 2));
            {
                register u_long128 q __asm__("$7") = *(u_long128 *)&pos;
                *(u_long128 *)&p->pos = q;
            }
            __asm__ volatile("");
            i++;
            p->pos.x += func_002B3DB0(2.0f);
            p->pos.y += func_002B3DB0(2.0f);
            p->pos.z += func_002B3DB0(2.0f);
            p->vx = func_002B3DB0(0.5f);
            p->vy = func_002B3DB0(0.1f);
            p->vz = func_002B3DB0(0.5f);
            p->f1C = func_002B3DB0(3.1415927f);
            p->f20 = p->vx * f20;
            p->f24 = f23;
            p->f28 = p->vz * f20;
            p->f2C = f24;
            {
                float s = func_002B3DB0(0.025f) + 0.15f;
                p->w4C = 0x1B;
                p->b6B = a1;
                p->f3C = s;
                __asm__ volatile("");
                p->w50 = 0;
            }
        }
    } while (i <= 0);
}
