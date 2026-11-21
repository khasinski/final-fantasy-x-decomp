/* 09296 task completion check (136 B). */

typedef struct {
    unsigned char pad00[0x10];
    int cb;
} OvlNode;

typedef struct {
    unsigned char pad00[0x08];
    OvlNode *node;
    unsigned char pad0C[0x08];
    int timer;
} OvlTask;

extern unsigned char g_ovl_dat_a[];
extern unsigned char g_ovl_dat_b[];
extern int g_ovl_cnt;

extern int fn_ovl_29b8(void *);
extern int fn_ovl_3918(void *, int);
extern void fn_ovl_1c80(int, int);
extern void fn_ovl_next(void);

void ovl_09296_0aa8(OvlTask *t)
{
    int a = fn_ovl_29b8(g_ovl_dat_a);
    int b = fn_ovl_3918(g_ovl_dat_b, g_ovl_cnt);
    if (b == 1 && a == 1) {
        fn_ovl_1c80(-1, 0);
        t->timer = 3;
        /* DEBT(CAST): int cb aliases timer to preserve original store order. */
        t->node->cb = (int)fn_ovl_next;
    }
}
