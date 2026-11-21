/* 09145 task completion check (104 B). */

typedef struct { int pad[4]; int cb; } OvlNode;
typedef struct { int pad0[2]; OvlNode *node; int pad1[2]; int timer; } OvlTask;

extern char g_ovl_mgr[];
extern void *g_ovl_ptr_4834;
extern unsigned short g_ovl_cfade_flags;

extern int fn_ovl_3830(void *, void *);
extern void fn_ovl_0808(void);

void ovl_09145_0a08(OvlTask *t)
{
    if (fn_ovl_3830(g_ovl_mgr, g_ovl_ptr_4834) == 1 && (g_ovl_cfade_flags & 0x8000)) {
        t->timer = 3;
        t->node->cb = (int)fn_ovl_0808;
    }
}
