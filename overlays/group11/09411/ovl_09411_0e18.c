/* 09411 slot setup helper (104 B, 09411 @ 0x01B00E18). */

#include "common.h"

typedef struct {
    u8 pad00[0xD0];
    float posD0[4];
} EffSlot;

extern u8 g_mgr_7f50[];
extern EffSlot g_slot_7b60;

extern void func_01B03F08(void *, void *, int, int, int, int, float);

void ovl_09411_0e18(void)
{
    EffSlot *s = &g_slot_7b60;

    func_01B03F08(g_mgr_7f50, s, 4, 0, 0, 0, 0.1f);
    s->posD0[0] = 0.0f;
    s->posD0[1] = 0.0f;
    s->posD0[2] = 0.0f;
    s->posD0[3] = 1.0f;
}
