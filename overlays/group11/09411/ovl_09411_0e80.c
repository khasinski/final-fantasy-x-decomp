/* 09411 effect setup helper (144 B, 09411 @ 0x01B00E80). */

#include "common.h"

typedef struct {
    u8 pad00[0xC4];
    float fC4;
    u8 padC8[0x08];
    float posD0[4];
    float fE0;
    float fE4;
    float fE8;
} EffSlot;

extern u8 g_mgr_7f50[];
extern EffSlot g_slot_7a30;

extern void func_01B03F08(void *, void *, int, int, int, int, float);
extern void func_01B015E8(int, void *, int);
extern float func_01B014C0(int);

void ovl_09411_0e80(void)
{
    EffSlot *s = &g_slot_7a30;

    func_01B03F08(g_mgr_7f50, s, 0, 0, 0, 0, 0.1f);
    func_01B015E8(-1, s->posD0, 3);
    s->posD0[1] -= 0.5f;
    s->fC4 = func_01B014C0(-1);
    s->fE0 = -5.0f;
    s->fE8 = -5.0f;
}
