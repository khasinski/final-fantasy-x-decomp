/* Shared 09662/09455/09718 init routine (276 B, 09662 @ 0x01B04408). */

#include "common.h"

typedef struct { void *p; } PtrArg;
typedef struct { void *p0; int w1; } Arg2i;

extern void *g_4c;
extern u8 g_50[];
extern void *g_4d8;
extern u8 g_8b0[];
extern u8 g_8c8[];
extern u8 g_8e8[];
extern u8 g_f10[];
extern u8 g_edb0[];
extern void *g_eddc;
extern u8 g_heap1[];
extern u8 g_heap2[];

extern void fn_3730(void);
extern void fn_dd18(PtrArg *);
extern void fn_4ea8(Arg2i *);
extern void func_002B4980(void *);
extern void *func_002B49A0(void *, int, int);
extern void func_002678E0(void *, void *);
extern void func_00267A68(void *, void *, void *, int);
extern void func_002D02E8(void *, int, int, int);
extern void func_002944B0(void *, int, int, int);
extern void fn_43b0(void *);

int ovl_09662_4408(void)
{
    Arg2i a2;
    PtrArg a1;

    fn_3730();
    g_4c = g_heap2;
    a1.p = g_8b0;
    fn_dd18(&a1);
    a2.p0 = g_8c8;
    a2.w1 = 0;
    fn_4ea8(&a2);
    g_8c8[0x1B] = 1;
    a2.p0 = g_8e8;
    a2.w1 = 0;
    fn_4ea8(&a2);
    func_002B4980(g_4d8);
    g_eddc = func_002B49A0(g_4d8, 8, 3);
    func_002678E0(g_eddc, g_50);
    func_00267A68(g_edb0, g_eddc, g_heap1, 0x100000);
    func_002D02E8(g_4d8, 0, 1000, 2);
    func_002944B0(g_4d8, 0, 1000, 2);
    fn_43b0(g_f10);
    return 0;
}
