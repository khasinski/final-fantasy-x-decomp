/* Shared 09136-family update step (136 B, PI/20). */
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

extern int g_ovl_51dc;
extern int g_ovl_51f0;
extern u8 g_ovl_51f8[];
extern int g_ovl_55d4;
extern u8 g_ovl_09f0[];

extern void fn_ovl_4668(float, float);
extern void fn_ovl_4630(int);
extern int fn_ovl_3c28(void *, int);

void ovl_09136_0cf0(OvlTask *a0)
{
    fn_ovl_4668(0.0f, 0.15707964f);
    fn_ovl_4630(g_ovl_51f0);
    if (fn_ovl_3c28(g_ovl_51f8, g_ovl_55d4) == 1 && g_ovl_51dc <= 0) {
        OvlTaskSub *sub = a0->p08;
        *(volatile int *)&a0->w14 = 3;
        *(void *volatile *)&sub->fn10 = g_ovl_09f0;
    }
}
