/* Shared 09486-family task completion check (140 B). */

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
extern int g_ovl_rem;

extern int fn_ovl_2d60(void *);
extern int fn_ovl_3cc0(void *, int);
extern void fn_ovl_next(void);

void ovl_09486_0e70(OvlTask *t)
{
    int a = fn_ovl_2d60(g_ovl_dat_a);
    int b = fn_ovl_3cc0(g_ovl_dat_b, g_ovl_cnt);
    if (b == 1 && a == 1 && g_ovl_rem <= 0) {
        t->timer = 3;
        /* DEBT(CAST): int cb aliases timer to preserve original store order. */
        t->node->cb = (int)fn_ovl_next;
    }
}
