/* Shared 09291/09703 task completion check (176 B, 2 containers). */

typedef struct { int pad[4]; int cb; } OvlNode;
typedef struct { int pad0[2]; OvlNode *node; int pad1[2]; int timer; } OvlTask;

extern char g_ovl_dat_4e68[];
extern int g_ovl_flag_68d0;
extern char g_ovl_mgr[];
extern void *g_ovl_ptr_691c;

extern int fn_ovl_3a50(void *, void *);
extern void fn_ovl_23b0(int, int);
extern int fn_ovl_2af0(void *);
extern void fn_ovl_08b0(void);

void ovl_09291_0be0(OvlTask *t)
{
    int r0 = fn_ovl_3a50(g_ovl_mgr, g_ovl_ptr_691c);
    int r1;

    if (r0 == 1 && g_ovl_flag_68d0 == 0) {
        fn_ovl_23b0(-5, 2);
        g_ovl_flag_68d0 = 1;
    }
    r1 = fn_ovl_2af0(g_ovl_dat_4e68);
    if (r1 == 1 && r0 == 1) {
        t->timer = 3;
        t->node->cb = (int)fn_ovl_08b0;
    }
}
