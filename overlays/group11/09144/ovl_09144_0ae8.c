/* 09144 task completion check (120 B). */

typedef struct { int pad[4]; int cb; } OvlNode;
typedef struct { int pad0[2]; OvlNode *node; int pad1[2]; int timer; } OvlTask;

extern char g_ovl_mgr[];
extern void *g_ovl_ptr_4a54;
extern int g_ovl_w475c;
extern unsigned short g_ovl_cfade_flags;

extern int fn_ovl_3920(void *, void *);
extern void fn_ovl_0880(void);

void ovl_09144_0ae8(OvlTask *t)
{
    if (fn_ovl_3920(g_ovl_mgr, g_ovl_ptr_4a54) == 1 && g_ovl_w475c <= 0 && (g_ovl_cfade_flags & 0x8000)) {
        t->timer = 3;
        t->node->cb = (int)fn_ovl_0880;
    }
}
