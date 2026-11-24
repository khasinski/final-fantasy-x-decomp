/* Battle-effect overlay 09304: 0x01B00A00..0x01B00DC4 */
#include "common.h"

typedef struct {
    u8 pad00[0x2C];
    u32 unk2C;
} Mgr7258;

typedef struct {
    u8 pad00[0xC4];
    float fC4;
    u8 padC8[0x08];
    float posD0[4];
    u8 padE0[0x30];
    void *p110;
    u8 pad114[0x1C];
} EffSlot73D0;

typedef struct {
    u8 pad00[0xD0];
    float posD0[4];
    u8 padE0[0x50];
    u8 unk130[0x210];
    u8 unk340;
    u8 unk341;
    u8 unk342;
    u8 pad343[0x0D];
    float unk350;
    u8 pad354[0x04];
    u32 unk358;
    u8 pad35C[0x04];
    float tgt360[4];
    u8 pad370[0x10];
    void *unk380;
    u32 unk384;
    void *unk388;
    u8 pad38C[0x04];
    float unk390;
    s32 unk394;
    s32 unk398;
    s16 unk39C;
    u8 pad39E[0x02];
} ProjObj0A00;

extern u8 g_data_0040[];
extern u8 g_data_0540[];
extern s32 g_tbl_0558[];
extern u8 g_data_0588[];
extern u8 g_data_0dc8[];
extern u8 g_data_0df8[];
extern u8 g_data_59d8[];
extern ProjObj0A00 g_proj_5a00[];
extern u8 *g_ptr_7250;
extern Mgr7258 g_mgr_7258;
extern EffSlot73D0 g_slot_73d0;
extern float g_vec_74a0[4];
extern u8 *g_ptr_7630;
extern u8 *g_ptr_7634;
extern u8 g_buf_c960[];
extern u8 g_buf_01B58C00[];

extern u32 func_002B49A0(void *, int, int);
extern float func_002B3DB0(float);
extern void func_002DCE08(float *, float *, float *);
extern void func_002DD020(float *, float *, float *);
extern void func_002DD0B0(float *, float *);
extern void func_002DD128(float *);
extern void func_002DD318(float *, float *, float);

extern void func_01B00E78(void *);
extern float func_01B01228(int);
extern void func_01B01350(int, float *, int);
extern void func_01B02D38(int, void *, void *);
extern void func_01B033F8(void *, void *, void *);
extern u8 *func_01B03910(void *);
extern void func_01B03AD8(void *);
extern void func_01B03B98(void *, void *, void *, int);
extern void func_01B03C70(void *, void *, int, int, float, int, void *);
extern u32 *func_01B04200(void *, int);
extern void func_01B049A0(float *, float *, float *);
extern void func_01B04AA8(float *, float *, float *);
extern void func_01B05218(void *, u32, float *);
extern void func_01B056A8(void *, int, float);

int func_01B00A00(void)
{
    float mtx[16];
    float vec40[4];
    float vec50[4];
    float vec60[4];
    u8 *base;
    Mgr7258 *mgr = &g_mgr_7258;
    float *vec = g_vec_74a0;
    register int i __asm__("$23");
    s32 *tbl;
    ProjObj0A00 *proj;
    register float *v60 __asm__("$21");
    register float *v50 __asm__("$22");
    u8 *p;

    base = g_buf_01B58C00;
    { register u8 *_a1 __asm__("$5") = base + 0x40000; g_ptr_7634 = _a1; }
    g_ptr_7250 = base + 0x140000;
    g_ptr_7630 = base;

    mgr->unk2C = func_002B49A0(g_buf_c960, 8, 0);
    func_01B03B98(mgr, g_data_0040, g_ptr_7630, 0x40000);
    func_01B03C70(mgr, &g_slot_73d0, 1, 0x12, 0.12f, 0, 0);

    func_01B01350(-1, vec, 0);
    g_slot_73d0.fC4 = func_01B01228(-1);
    g_slot_73d0.posD0[1] -= 10.0f;

    base += 0x160000;
    func_01B033F8(base, g_buf_c960, g_data_0540);
    g_slot_73d0.p110 = base;

    v50 = vec50;
    func_01B01350(0, v50, 1);
    func_01B049A0(vec40, vec, v50);
    vec40[0] = 0.0f;
    vec60[0] = 0.0f;
    vec60[1] = 0.0f;
    vec60[2] = -12.0f;
    func_01B04AA8(vec40, vec, vec60);
    v60 = vec60;
    proj = g_proj_5a00;
    func_01B049A0(vec40, v50, vec);

    func_002DD128(mtx);
    func_002DD318(mtx, mtx, vec40[1]);

    tbl = g_tbl_0558;
    for (i = 0; i < 5; i++, proj++, tbl++) {
        s32 val = *tbl + 0x14;

        func_01B03C70(mgr, proj, 2, val, 0.01f, 0, 0);
        func_002DD0B0(proj->posD0, vec);

        vec60[0] = func_002B3DB0(1.0f);
        vec60[1] = func_002B3DB0(2.2f);
        vec60[2] = -2.0f;
        vec60[3] = 1.0f;
        func_002DCE08(v60, mtx, v60);
        vec60[3] = 0.0f;

        func_002DD020(proj->posD0, proj->posD0, v60);
        func_002DD0B0(proj->tgt360, v50);
        func_002DD020(proj->tgt360, proj->tgt360, v60);

        proj->unk398 = i;
        proj->unk380 = &g_mgr_7258;
        proj->unk388 = (void *)func_01B00E78;
        proj->unk394 = val;
        proj->unk390 = 0.03f;
        proj->unk384 = 0;
        proj->unk39C = 1;

        func_01B05218(proj->unk130, *func_01B04200(mgr, 0), proj->posD0);

        proj->unk350 = 0.5f;
        proj->unk340 = 0x20;
        proj->unk342 = 0xC0;
        proj->unk358 = 0x40;
        proj->unk341 = 0x40;

        func_01B056A8(proj, 1, 8.0f);
    }

    func_01B02D38(-1, g_data_59d8, g_data_0588);

    p = func_01B03910(g_data_0dc8);
    p[0x18] = 1;
    func_01B03AD8(p);

    p = func_01B03910(g_data_0df8);
    p[0x18] = 2;
    func_01B03AD8(p);

    return 0;
}
