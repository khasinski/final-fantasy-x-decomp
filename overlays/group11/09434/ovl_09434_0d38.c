#include "common.h"

typedef struct {
    u8 pad00[0x54];
    int f54;
    u8 pad58[0x8];
} SubBF0;

typedef struct {
    u8 pad00[0xAB0];
    float posab0[4];
    u8 padac0[0x130];
    SubBF0 subbf0;
    u8 padc50[0x44];
    float fc94;
    int fc98;
    int fc9c;
    int fca0;
    int fca4;
    int done;
} Work9434;

extern Work9434 *g_work;
extern u8 g_seq[];
extern u8 g_77e8[];
extern u8 g_mgr[];
extern void *g_ptr1;
extern int g_eff_handle;
extern u8 g_res_data[];
extern u8 g_680[];
extern int g_77fc;

extern int ovl_seq_step(void *);
extern int ovl_check_77e8(void *);
extern void ovl_0ed0(void);
extern void ovl_kill_task(void *);
extern int ovl_mgr_step(void *, void *);
extern void MsEffectTerminate(int);
extern void ovl_get_pos(int, void *, int);
extern float ovl_get_scale(int);
extern int ovl_get_chr(int);
extern int func_001BBCF8(int, int);
extern void ovl_init_bf0(void *, void *, void *, int);

void ovl_09434_0d38(void *task)
{
    Work9434 *w = g_work;
    int a = ovl_seq_step(g_seq);
    int b = ovl_check_77e8(g_77e8);

    if (a != 0 && b != 0) {
        w->done = 1;
        ovl_0ed0();
        ovl_kill_task(task);
    }
}

void ovl_09434_0dc0(void)
{
    Work9434 *w = g_work;

    if (ovl_mgr_step(g_mgr, g_ptr1) == 1 && w->done == 1) {
        MsEffectTerminate(g_eff_handle);
    }
}

void ovl_09434_0e28(void)
{
    Work9434 *w = g_work;
    SubBF0 *sub = &w->subbf0;

    ovl_get_pos(-1, w->posab0, 0);
    w->fc94 = ovl_get_scale(-1);
    w->fca4 = func_001BBCF8(g_eff_handle, ovl_get_chr(0));
    ovl_init_bf0(sub, g_res_data, g_680, 1);
    sub->f54 = -1;
    w->fc9c = -1;
    w->done = 0;
    g_77fc = 1;
}
