#include "common.h"

typedef struct {
    u8 pad00[0x54];
    int f54;
    u8 pad58[0x8];
} Sub750;

typedef struct {
    u8 pad00[0x5F0];
    float pos5f0[4];
    u8 pad600[0x150];
    Sub750 sub750;
    u8 pad7b0[0x40];
    float f7f0;
    int f7f4;
    int f7f8;
    int f7fc;
    int f800;
    int done;
} Work9491;

extern Work9491 *g_work;
extern u8 g_seq[];
extern u8 g_7570[];
extern u8 g_mgr[];
extern void *g_ptr1;
extern int g_eff_handle;
extern u8 g_res_data[];
extern u8 g_680[];
extern int g_7584;

extern int ovl_seq_step(void *);
extern int ovl_check_7570(void *);
extern void ovl_0ed0(void);
extern void ovl_kill_task(void *);
extern int ovl_mgr_step(void *, void *);
extern void MsEffectTerminate(int);
extern void ovl_get_pos(int, void *, int);
extern float ovl_get_scale(int);
extern int ovl_get_chr(int);
extern int func_001BBCF8(int, int);
extern void ovl_init_750(void *, void *, void *, int);

void ovl_09491_0d38(void *task)
{
    Work9491 *w = g_work;
    int a = ovl_seq_step(g_seq);
    int b = ovl_check_7570(g_7570);

    if (a != 0 && b != 0) {
        w->done = 1;
        ovl_0ed0();
        ovl_kill_task(task);
    }
}

void ovl_09491_0dc0(void)
{
    Work9491 *w = g_work;

    if (ovl_mgr_step(g_mgr, g_ptr1) == 1 && w->done == 1) {
        MsEffectTerminate(g_eff_handle);
    }
}

void ovl_09491_0e28(void)
{
    Work9491 *w = g_work;
    Sub750 *sub = &w->sub750;

    ovl_get_pos(-1, w->pos5f0, 0);
    w->f7f0 = ovl_get_scale(-1);
    w->f800 = func_001BBCF8(g_eff_handle, ovl_get_chr(0));
    ovl_init_750(sub, g_res_data, g_680, 1);
    sub->f54 = -1;
    w->f7fc = -1;
    w->done = 0;
    g_7584 = 1;
}
