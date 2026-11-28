#include "common.h"

typedef struct TaskB280 {
    struct TaskB280 *prev;
    struct TaskB280 *next;
    struct TaskB280 *self;
    u32 f0C;
    void (*fn)(struct TaskB280 *);
    u32 f14;
    u8 prio;
} TaskB280;

extern TaskB280 *g_head_b280;
extern TaskB280 *g_free_b280;
extern TaskB280 *g_cur_b280;
extern u16 g_free_cnt_b280;

s32 ovl_09478_01b0b280(u8 a0) {
    s32 cnt = 0;
    TaskB280 *s0;
    g_cur_b280 = g_head_b280;
    s0 = g_cur_b280;
    while (s0 != 0) {
        if (s0->prio == a0) {
            s0->self->fn(s0);
            cnt++;
        }
        if (s0 == g_cur_b280) {
            g_cur_b280 = s0->next;
        }
        s0 = g_cur_b280;
    }
    g_cur_b280 = 0;
    return cnt;
}

TaskB280 *ovl_09478_01b0b330(void (*a0)(TaskB280 *)) {
    TaskB280 *n;
    if (g_free_cnt_b280 == 0) {
        return 0;
    }
    n = g_free_b280;
    n->prev->next = n->next;
    n->next->prev = n->prev;
    if (g_free_cnt_b280 >= 2) {
        g_free_b280 = n->next;
    } else {
        g_free_b280 = 0;
    }
    n->prio = 0;
    n->f14 = 0;
    g_free_cnt_b280--;
    n->fn = a0;
    n->f0C = 0;
    n->next = 0;
    n->prev = 0;
    n->self = n;
    return n;
}
