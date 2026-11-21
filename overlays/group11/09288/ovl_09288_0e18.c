/* 09288 dual-manager task completion check (148 B). */

typedef struct { int pad[4]; int cb; } OvlNode;
typedef struct { int pad0[2]; OvlNode *node; int pad1[2]; int timer; } OvlTask;
typedef struct { char pad[0x40]; } OvlMgr;

extern OvlMgr g_ovl_mgr[];
extern void *g_ovl_ptr_4978[];
extern int fn_ovl_3c70(void *, void *);
extern void fn_ovl_0c40(void);

void ovl_09288_0e18(OvlTask *t)
{
    int r0 = fn_ovl_3c70(&g_ovl_mgr[0], g_ovl_ptr_4978[0]);
    int r1 = fn_ovl_3c70(&g_ovl_mgr[1], g_ovl_ptr_4978[1]);

    if (r0 == 1 && r1 == 1) {
        t->timer = 3;
        t->node->cb = (int)fn_ovl_0c40;
    }
}
