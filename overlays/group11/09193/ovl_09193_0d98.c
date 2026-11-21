typedef struct { int pad[4]; int cb; } OvlNode;
typedef struct { int pad0[2]; OvlNode *node; int pad1[2]; int timer; } OvlTask;

extern char g_ovl_dat_5048[];
extern int g_ovl_t0;
extern int g_ovl_t1;
extern char g_ovl_mgr[];
extern void *g_ovl_ptr_5974;
extern char g_ovl_res[];

extern void fn_ovl_09c8(void);
extern int fn_ovl_2cd0(void *);
extern void fn_ovl_34e0(void *, int, int);
extern int fn_ovl_3c30(void *, void *);

void ovl_09193_0d98(OvlTask *t) {
    int r0;
    int r1;

    if (g_ovl_t0 > 0) {
        g_ovl_t0--;
        if (g_ovl_t0 == 0) {
            fn_ovl_34e0(g_ovl_res, 0, 0);
        }
    }
    if (g_ovl_t1 > 0) {
        g_ovl_t1--;
        if (g_ovl_t1 == 0) {
            fn_ovl_34e0(g_ovl_res, 0, 1);
        }
    }
    r0 = fn_ovl_2cd0(g_ovl_dat_5048);
    r1 = fn_ovl_3c30(g_ovl_mgr, g_ovl_ptr_5974);
    if (r1 == 1 && r0 == 1) {
        t->timer = 3;
        t->node->cb = (int)fn_ovl_09c8;
    }
}
