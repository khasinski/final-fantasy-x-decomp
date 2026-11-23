/* 09463 wait/transition task (200 B, 09463 @ 0x01B00D58). */

#include "common.h"

typedef struct {
    u8 pad00[0x10];
    s32 fn10;
} TaskSub;

typedef struct {
    u8 pad00[0x08];
    TaskSub *sub;
    u8 pad0C[0x08];
    int state14;
} TaskObj;

extern int g_timer_6630;
extern u8 g_data_6450[];
extern u8 g_data_6638[];
extern void *g_ptr_67b4;
extern u16 g_flags_6500;
extern int g_val_661c;
extern u8 g_fn_0960[];

extern void func_01B020F8(int, int);
extern void func_01B025B0(int, int, float, float, float);
extern void func_01B03170(void *, int);
extern int func_01B03E30(void *, void *);

void ovl_09463_0d58(TaskObj *t)
{
    if (g_timer_6630 > 0) {
        g_timer_6630--;
        if (g_timer_6630 == 0) {
            func_01B020F8(-1, 0);
            func_01B025B0(-1, 1, 1.0f, 1.0f, 1.0f);
            func_01B03170(g_data_6450, 1);
        }
    }

    if (func_01B03E30(g_data_6638, g_ptr_67b4) == 1 && (g_flags_6500 & 0x8000) && g_val_661c <= 0) {
        t->state14 = 3;
        t->sub->fn10 = (s32)g_fn_0960;
    }
}
