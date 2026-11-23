/* 09398 wait/transition task (220 B, 09398 @ 0x01B00E28). */

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

extern int g_timer_6480;
extern int g_flag_6484;
extern u8 g_data_0618[];
extern u8 g_data_6338[];
extern u8 g_data_6490[];
extern void *g_ptr_6864;
extern u8 g_fn_0a70[];

extern void func_01B02F90(int, void *, void *);
extern void func_01B028B8(int, int, int);
extern int func_01B03048(void *);
extern int func_01B03FA8(void *, void *);

void ovl_09398_0e28(TaskObj *t)
{
    int r;

    if (g_timer_6480 > 0) {
        g_timer_6480--;
        if (g_timer_6480 == 0) {
            func_01B02F90(-1, g_data_6338, g_data_0618);
            func_01B028B8(0, 10, 20);
            g_flag_6484 = 1;
        }
    }

    r = func_01B03048(g_data_6338);
    if (func_01B03FA8(g_data_6490, g_ptr_6864) == 1 && g_flag_6484 == 1 && r == 1) {
        t->state14 = 3;
        t->sub->fn10 = (s32)g_fn_0a70;
    }
}
