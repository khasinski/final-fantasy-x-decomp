/* 09109 effect init (400 B). */

#include "common.h"

typedef struct {
    float f00;
    float f04;
    float f08;
    u8 pad0C[0x0C];
    int w18;
    int w1C;
    int w20;
    int w24;
    int w28;
} OvlParam;

typedef struct {
    u8 pad00[0x54];
    int w54;
} OvlObj5330;

typedef struct {
    u8 pad00[0x18];
    u8 b18;
} OvlTaskObj;

extern u8 g_ovl_buf[];
extern u8 g_ovl_res[];
extern int g_ovl_tab_0040[];
extern int g_ovl_dat_0060[];
extern int g_ovl_dat_0088[];
extern u8 g_ovl_dat_00b0[];
extern int g_ovl_210;
extern u8 g_ovl_52d8[];
extern OvlParam g_ovl_52f8;
extern OvlObj5330 g_ovl_5330;
extern void *g_ovl_5390;
extern int g_ovl_5394;
extern int g_ovl_5398;
extern int g_ovl_539c;

extern void fn_ovl_0708(void);
extern void fn_ovl_0738(void);
extern void fn_ovl_07e8(void);
extern int fn_ovl_0a38(int);
extern void fn_ovl_2800(int, void *, void *);
extern OvlTaskObj *fn_ovl_33d8(void *);
extern void fn_ovl_35a0(OvlTaskObj *);
extern void *fn_ovl_4aa8(void *, int);
extern void fn_ovl_5040(OvlParam *);
extern void fn_ovl_5168(OvlObj5330 *, void *, int *, int);

int ovl_09109_0578(void)
{
    u8 *p = g_ovl_buf;
    int a0;
    int flag;
    int idx;
    int val;
    int *dat;
    OvlTaskObj *t;

    a0 = g_ovl_210;
    g_ovl_5390 = p;
    flag = a0 >> 10;
    flag &= 1;
    g_ovl_539c = flag;
    idx = fn_ovl_0a38(a0);
    g_ovl_5394 = 0;
    val = g_ovl_tab_0040[idx];
    g_ovl_5398 = val;
    if (flag == 1) {
        OvlParam *q = &g_ovl_52f8;
        q->f00 = 1.5f;
        q->f04 = 0.5f;
        q->f08 = 0.5f;
        q->w18 = 0x20;
        q->w1C = val;
        q->w20 = 0x10;
        q->w24 = 0x28;
        q->w28 = 0;
        fn_ovl_5040(q);
        dat = g_ovl_dat_0060;
    } else {
        dat = g_ovl_dat_0088;
    }
    dat[1] = g_ovl_5398;
    fn_ovl_5168(&g_ovl_5330, g_ovl_res, dat, 1);
    g_ovl_5330.w54 = 0;
    fn_ovl_2800(-1, g_ovl_52d8, g_ovl_dat_00b0);
    t = fn_ovl_33d8((void *)fn_ovl_0708);
    t->b18 = 1;
    fn_ovl_35a0(t);
    fn_ovl_4aa8(p + 0x20000, 0x80);
    switch (flag) {
    case 1:
        fn_ovl_35a0(fn_ovl_33d8((void *)fn_ovl_07e8));
        break;
    }
    t = fn_ovl_33d8((void *)fn_ovl_0738);
    t->b18 = 2;
    fn_ovl_35a0(t);
    return 0;
}
