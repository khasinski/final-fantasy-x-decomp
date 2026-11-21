/* Shared 09210/09352 task completion check with timer (160 B). */

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

extern int g_ovl_timer;
extern unsigned char g_ovl_dat_a[];
extern unsigned char g_ovl_dat_b[];
extern int g_ovl_cnt;

extern void fn_ovl_1b70(int, int);
extern int fn_ovl_2948(void *);
extern int fn_ovl_38a8(void *, int);
extern void fn_ovl_next(void);

void ovl_09210_0a48(OvlTask *t)
{
    int a;
    int b;

    if (g_ovl_timer > 0) {
        g_ovl_timer--;
        if (g_ovl_timer <= 0) {
            fn_ovl_1b70(-1, 0);
        }
    }
    a = fn_ovl_2948(g_ovl_dat_a);
    b = fn_ovl_38a8(g_ovl_dat_b, g_ovl_cnt);
    if (b == 1 && a == 1) {
        t->timer = 3;
        /* DEBT(CAST): int cb aliases timer to preserve original store order. */
        t->node->cb = (int)fn_ovl_next;
    }
}
