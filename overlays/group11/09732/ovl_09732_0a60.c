#include "common.h"

typedef struct {
    u8 pad00[0x2C];
    void *w2c;
} OvlMgr9732;

typedef struct {
    u8 pad00[0x18];
    u8 b18;
} OvlTask9732;

typedef struct {
    u8 pad00[0x130];
    int done;
} OvlWork9732;

extern int g_588[2];
extern int g_7810;
extern OvlMgr9732 g_7818;
extern void *g_7858;
extern void *g_785c;
extern u8 g_7860[];
extern OvlWork9732 *g_78bc;
extern void *g_78c0;
extern void *g_794;
extern u8 g_heap_buf[];
extern u8 g_res_data[];
extern u8 g_hdr_40[];
extern u8 g_528[];

extern void ovl_0f50(int);
extern void *func_002B49A0(void *, int, int);
extern void ovl_3ae8(void *, void *, void *, int);
extern void ovl_7150(void *, void *);
extern OvlTask9732 *ovl_3860(void *);
extern void ovl_3a28(void *);
extern void ovl_7270(void *, int);
extern void ovl_4f48(void);
extern int ovl_7170(void *);
extern void ovl_0c88(void);
extern void ovl_38e0(void *);
extern int ovl_3ca0(void *, void *);
extern void func_001CDDD8(int);

void ovl_09732_0b90(void *task);
void ovl_09732_0c10(void);
void ovl_09732_0c78(void);

int ovl_09732_0a60(void)
{
    u8 *p = g_heap_buf;
    OvlMgr9732 *mgr;
    OvlTask9732 *task;

    g_7858 = p;
    g_785c = p + 0x40000;
    g_78c0 = p + 0x140000;
    g_78bc = (OvlWork9732 *)(p + 0x170000);
    g_588[0] = 20;
    g_588[1] = 0;
    ovl_0f50(g_7810);
    mgr = &g_7818;
    mgr->w2c = func_002B49A0(g_res_data, 8, 0);
    ovl_3ae8(mgr, g_hdr_40, g_7858, 0x40000);
    ovl_09732_0c78();
    ovl_7150(g_7860, g_528);

    task = ovl_3860((void *)ovl_09732_0b90);
    task->b18 = 1;
    ovl_3a28(task);

    ovl_7270(p + 0x160000, 0x200);

    task = ovl_3860((void *)ovl_09732_0c10);
    task->b18 = 2;
    ovl_3a28(task);
    return 0;
}

void ovl_09732_0b90(void *task)
{
    OvlWork9732 *w = g_78bc;

    ovl_4f48();
    g_794 = g_78c0;
    if (ovl_7170(g_7860) == 1) {
        w->done = 1;
        ovl_0c88();
        ovl_38e0(task);
    }
}

void ovl_09732_0c10(void)
{
    OvlWork9732 *w = g_78bc;

    if (ovl_3ca0(&g_7818, g_785c) == 1 && w->done == 1) {
        func_001CDDD8(g_7810);
    }
}

void ovl_09732_0c78(void)
{
    g_78bc->done = 0;
}
