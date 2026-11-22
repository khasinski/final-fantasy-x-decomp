#include "common.h"

typedef struct {
    u8 pad00[0x18];
    u8 prio;
} OvlTask;

typedef struct {
    u8 pad00[0x2C];
    void *f2c;
} OvlMgr;

extern u8 g_heap_buf[];
extern void *g_ptr1;
extern void *g_work;
extern int g_flag0;
extern OvlMgr g_mgr;
extern u8 g_res_data[];
extern u8 g_hdr_40[];
extern u8 g_seq[];
extern u8 g_seq_tbl[];

extern void *func_002B49A0(void *, int, int);
extern void ovl_init_mgr(void *, void *, void *, int);
extern void ovl_setup(void);
extern void ovl_init_seq(void *, void *);
extern void ovl_set_mode(int);
extern OvlTask *ovl_alloc_task(void (*)(void));
extern void ovl_add_task(OvlTask *);
extern void ovl_task1(void);
extern void ovl_task2(void);

int ovl_09491_0c48(void)
{
    u8 *heap = g_heap_buf;
    OvlMgr *mgr = &g_mgr;
    OvlTask *t;

    g_ptr1 = heap + 0x40000;
    g_work = heap + 0x140000;
    g_flag0 = 0;
    mgr->f2c = func_002B49A0(g_res_data, 8, 0);
    ovl_init_mgr(mgr, g_hdr_40, heap, 0x40000);
    ovl_setup();
    ovl_init_seq(g_seq, g_seq_tbl);
    ovl_set_mode(1);

    t = ovl_alloc_task(ovl_task1);
    t->prio = 1;
    ovl_add_task(t);

    t = ovl_alloc_task(ovl_task2);
    t->prio = 2;
    ovl_add_task(t);

    return 0;
}
