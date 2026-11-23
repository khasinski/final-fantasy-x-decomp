/* 09097 effect init (472 B). */

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
} OvlObj5450;

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
extern u8 g_ovl_53f8[];
extern OvlParam g_ovl_5418;
extern OvlObj5450 g_ovl_5450;
extern void *g_ovl_54b0;
extern int g_ovl_54b4;
extern int g_ovl_54b8;
extern int g_ovl_54bc;
extern int g_ovl_54c0;

extern void fn_ovl_07a8(void);
extern void fn_ovl_07d8(void);
extern void fn_ovl_08b8(void);
extern void fn_ovl_0900(void);
extern int fn_ovl_0b50(int);
extern void fn_ovl_2918(int, void *, void *);
extern OvlTaskObj *fn_ovl_34f0(void *);
extern void fn_ovl_36b8(OvlTaskObj *);
extern void *fn_ovl_4bc0(void *, int);
extern void fn_ovl_5158(OvlParam *);
extern void fn_ovl_5280(OvlObj5450 *, void *, int *, int);

int ovl_09097_05d0(void)
{
    u8 *p = g_ovl_buf;
    int a0;
    int flag;
    int idx;
    int val;
    int *dat;
    OvlTaskObj *t;

    a0 = g_ovl_210;
    g_ovl_54b0 = p;
    flag = a0 >> 10;
    flag &= 1;
    g_ovl_54c0 = flag;
    idx = fn_ovl_0b50(a0);
    g_ovl_54b4 = 0;
    val = g_ovl_tab_0040[idx];
    g_ovl_54b8 = val;
    if (flag == 1) {
        OvlParam *q = &g_ovl_5418;
        q->f00 = 1.5f;
        q->f04 = 0.5f;
        q->f08 = 0.5f;
        q->w18 = 0x20;
        q->w1C = val;
        q->w20 = 0x10;
        q->w24 = 0x28;
        q->w28 = 0;
        fn_ovl_5158(q);
        dat = g_ovl_dat_0060;
    } else {
        dat = g_ovl_dat_0088;
    }
    dat[1] = g_ovl_54b8;
    fn_ovl_5280(&g_ovl_5450, g_ovl_res, dat, 1);
    g_ovl_5450.w54 = 0;
    fn_ovl_2918(-1, g_ovl_53f8, g_ovl_dat_00b0);
    g_ovl_54bc = 0;
    t = fn_ovl_34f0((void *)fn_ovl_07a8);
    t->b18 = 1;
    fn_ovl_36b8(t);
    if (idx == 0) {
        t = fn_ovl_34f0((void *)fn_ovl_08b8);
        t->b18 = 1;
        fn_ovl_36b8(t);
    }
    fn_ovl_4bc0(p + 0x20000, 0x80);
    switch (flag) {
    case 1:
        fn_ovl_36b8(fn_ovl_34f0((void *)fn_ovl_0900));
        break;
    }
    t = fn_ovl_34f0((void *)fn_ovl_07d8);
    t->b18 = 2;
    fn_ovl_36b8(t);
    return 0;
}
