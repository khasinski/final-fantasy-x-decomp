/* 09411 dual slot setup (248 B, 09411 @ 0x01B00D20). */

#include "common.h"

typedef struct {
    u8 pad00[0xE0];
    float fE0;
    float fE4;
    float fE8;
    u8 padEC[0x18];
    void *p104;
    u8 pad108[0x28];
} EffSlot;

extern u8 g_mgr_7f50[];
extern EffSlot g_slots_7c90[2];

extern void func_01B03F08(void *, void *, int, int, int, int, float);
extern void ovl_09411_0cc8(void *);

void ovl_09411_0d20(void)
{
    EffSlot *s = &g_slots_7c90[0];

    func_01B03F08(g_mgr_7f50, s, 2, 0, 0, 0, 0.02f);
    s->p104 = (void *)ovl_09411_0cc8;
    s->fE0 = 3000.0f;
    s->fE4 = 100.0f;
    s->fE8 = 650.0f;

    s++;
    func_01B03F08(g_mgr_7f50, s, 2, 0, 0, 0, 0.02f);
    s->p104 = (void *)ovl_09411_0cc8;
    s->fE0 = 3000.0f;
    s->fE4 = 100.0f;
    s->fE8 = -650.0f;
}
