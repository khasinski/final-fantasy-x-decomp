/* 09289 task update & completion check (284 B). */

typedef struct { int pad[4]; int cb; } OvlNode;
typedef struct { int pad0[2]; OvlNode *node; int pad1[2]; int timer; } OvlTask;
typedef struct { int w0; int count; } OvlHdr;

extern OvlHdr g_ovl_hdr;
extern char g_ovl_dat_4dc8[];
extern int g_ovl_timers[];
extern char g_ovl_mgr[];
extern void *g_ovl_ptr_4fe4;

extern int fn_ovl_0d58(int);
extern void fn_ovl_2308(int, int);
extern int fn_ovl_2a48(void *);
extern int fn_ovl_39a8(void *, void *);
extern void fn_ovl_0870(void);

void ovl_09289_0ac8(OvlTask *t)
{
    int i;
    int r0;
    int r1;

    for (i = 0; i < g_ovl_hdr.count; i++) {
        if (g_ovl_timers[i] > 0) {
            if (--g_ovl_timers[i] == 0) {
                fn_ovl_2308(fn_ovl_0d58(i), 0);
            }
        }
    }
    r0 = fn_ovl_2a48(g_ovl_dat_4dc8);
    r1 = fn_ovl_39a8(g_ovl_mgr, g_ovl_ptr_4fe4);
    if (r1 == 1 && r0 == 1) {
        t->timer = 3;
        t->node->cb = (int)fn_ovl_0870;
    }
}
