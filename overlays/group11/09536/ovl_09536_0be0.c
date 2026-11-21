/* 09536 task completion check (160 B). */

typedef struct { int pad[4]; int cb; } OvlNode;
typedef struct { int pad0[2]; OvlNode *node; int pad1[2]; int timer; } OvlTask;
typedef struct { char pad[0x30]; unsigned short flags; } OvlColorFade;

extern char g_ovl_dat_4808[];
extern char g_ovl_mgr[];
extern void *g_ovl_ptr_5c04;
extern int g_ovl_w489c;
extern OvlColorFade *g_ovl_cfade_p;

extern int fn_ovl_2ae0(void *);
extern int fn_ovl_3a40(void *, void *);
extern void fn_ovl_0890(void);

void ovl_09536_0be0(OvlTask *t)
{
    int r0 = fn_ovl_2ae0(g_ovl_dat_4808);
    int r1 = fn_ovl_3a40(g_ovl_mgr, g_ovl_ptr_5c04);

    if (r1 == 1 && r0 == 1 && g_ovl_w489c <= 0 && (g_ovl_cfade_p->flags & 0x8000)) {
        t->timer = 3;
        t->node->cb = (int)fn_ovl_0890;
    }
}
