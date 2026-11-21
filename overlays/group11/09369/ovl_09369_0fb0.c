typedef struct { int pad[4]; int cb; } OvlNode;
typedef struct { int pad0[2]; OvlNode *node; int pad1[2]; int timer; } OvlTask;

extern char g_ovl_dat_5628[];
extern int g_ovl_t0;
extern char g_ovl_mgr[];
extern void *g_ovl_ptr_62d4;

extern void fn_ovl_0b60(void);
extern void fn_ovl_1f90(int);
extern void fn_ovl_20e0(int, int);
extern int fn_ovl_2eb8(void *);
extern int fn_ovl_3e18(void *, void *);

void ovl_09369_0fb0(OvlTask *t) {
    int r0;
    int r1;

    if (g_ovl_t0 > 0) {
        g_ovl_t0--;
        if (g_ovl_t0 == 0) {
            fn_ovl_20e0(-1, 0);
            fn_ovl_1f90(-1);
        }
    }
    r0 = fn_ovl_3e18(g_ovl_mgr, g_ovl_ptr_62d4);
    r1 = fn_ovl_2eb8(g_ovl_dat_5628);
    if (r1 == 1 && r0 == 1) {
        t->timer = 3;
        t->node->cb = (int)fn_ovl_0b60;
    }
}
