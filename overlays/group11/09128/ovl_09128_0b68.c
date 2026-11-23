/* Shared 09128-family update step (136 B, PI/10). */
#include "common.h"

typedef struct {
    u8 pad00[0x10];
    void *fn10;
} OvlTaskSub;

typedef struct {
    u8 pad00[0x08];
    OvlTaskSub *p08;
    u8 pad0C[0x08];
    int w14;
} OvlTask;

extern int g_ovl_504c;
extern int g_ovl_5060;
extern u8 g_ovl_5068[];
extern int g_ovl_5444;
extern u8 g_ovl_0910[];

extern void fn_ovl_44e0(float, float);
extern void fn_ovl_44a8(int);
extern int fn_ovl_3aa0(void *, int);

void ovl_09128_0b68(OvlTask *a0)
{
    fn_ovl_44e0(0.0f, 0.31415927f);
    fn_ovl_44a8(g_ovl_5060);
    if (fn_ovl_3aa0(g_ovl_5068, g_ovl_5444) == 1 && g_ovl_504c <= 0) {
        OvlTaskSub *sub = a0->p08;
        *(volatile int *)&a0->w14 = 3;
        *(void *volatile *)&sub->fn10 = g_ovl_0910;
    }
}
