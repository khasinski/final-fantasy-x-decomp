/* 09304 hit-impact spawner (280 B, 09304 @ 0x01B00E78). */

#include "common.h"

typedef struct {
    u8 pad00[0xC4];
    float fC4;
    u8 padC8[0x08];
    float posD0[4];
    u8 padE0[0x30];
    void *p110;
    u8 pad114[0x1C];
} EffSlot;

typedef struct {
    u8 pad00[0xC4];
    float fC4;
    u8 padC8[0x298];
    float tgt360[4];
    u8 pad370[0x28];
    int idx398;
} ProjObj;

extern EffSlot g_slots_6c20[];
extern u8 g_data_4210[];
extern u8 g_mgr_7258[];
extern u8 g_buf_7210[];
extern u8 g_buf_c960[];
extern u8 g_data_0570[];

extern void func_01B03C70(void *, void *, int, int, int, void *, float);
extern void func_002DD0B0(void *, void *);
extern void func_01B033F8(void *, void *, void *);

void ovl_09304_0e78(ProjObj *o)
{
    EffSlot *s = &g_slots_6c20[o->idx398];
    void *extra = (o->idx398 == 0) ? (void *)g_data_4210 : (void *)0;
    float ang;

    func_01B03C70(g_mgr_7258, s, 0, 0, 0, extra, 0.12f);
    func_002DD0B0(s->posD0, o->tgt360);
    ang = o->fC4 + 3.1415927f;
    if (ang > 3.1415927f) {
        ang -= 6.2831855f;
    } else if (ang < -3.1415927f) {
        ang += 6.2831855f;
    }
    s->fC4 = ang;
    if (o->idx398 == 0) {
        func_01B033F8(g_buf_7210, g_buf_c960, g_data_0570);
        s->p110 = g_buf_7210;
    }
}
