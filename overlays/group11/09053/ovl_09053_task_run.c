/* Shared 09053-family task runner by group id (172 B, zero debt). */

typedef unsigned char u8;

typedef struct OvlTask {
    struct OvlTask *prev;
    struct OvlTask *next;
    struct OvlTask *top;
    struct OvlTask *link;
    void (*fn)(struct OvlTask *);
    u8 pad14[4];
    u8 group;
} OvlTask;

extern OvlTask *g_ovl_head;
extern OvlTask *g_ovl_cur;

int ovl_09053_task_run(u8 group)
{
    OvlTask *t;
    int count = 0;

    g_ovl_cur = g_ovl_head;
    t = g_ovl_cur;
    while (t != 0) {
        if (t->group == group) {
            t->top->fn(t);
            count++;
        }
        if (t == g_ovl_cur) {
            g_ovl_cur = t->next;
        }
        t = g_ovl_cur;
    }
    g_ovl_cur = 0;
    return count;
}
