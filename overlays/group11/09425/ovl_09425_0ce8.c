/* 09425 task completion check (156 B). */

typedef struct { int pad[4]; int cb; } OvlNode;
typedef struct { int pad0[2]; OvlNode *node; int pad1[2]; int timer; } OvlTask;
typedef struct { char pad[0x20]; } OvlSnd;

extern char g_ovl_snd0[];
extern char g_ovl_snd1[];
extern char g_ovl_mgr[];
extern void *g_ovl_ptr_4b94;

extern int fn_ovl_2c30(void *);
extern int fn_ovl_3b90(void *, void *);
extern void fn_ovl_0a80(void);

void ovl_09425_0ce8(OvlTask *t)
{
    int r0 = fn_ovl_2c30(g_ovl_snd0);
    int r1 = fn_ovl_2c30(g_ovl_snd1);
    int r2 = fn_ovl_3b90(g_ovl_mgr, g_ovl_ptr_4b94);

    if (r2 == 1 && r0 == 1 && r1 == 1) {
        t->timer = 3;
        t->node->cb = (int)fn_ovl_0a80;
    }
}
