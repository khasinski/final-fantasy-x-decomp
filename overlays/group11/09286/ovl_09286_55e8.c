/* 09286 particle pool init & alloc (288 B, 2 funcs). */

#include "common.h"

typedef struct {
    u8 pad00[0x40];
    u32 w40;
    u32 w44;
    u32 w48;
    int active;
    s16 h50;
    u8 pad52[0x0E];
} OvlPoolPart;

extern OvlPoolPart *g_part_buf;
extern int g_part_cur;
extern int g_part_max;
extern int g_part_unk;

extern void *fn_ovl_3850(void *);
extern void fn_ovl_3a18(void *);
extern void fn_ovl_5718(void);

void *ovl_09286_55e8(OvlPoolPart *buf, int count)
{
    int i;
    void *task;

    g_part_buf = buf;
    for (i = 0; i < count; i++, buf++) {
        buf->active = 0;
    }
    g_part_cur = 0;
    g_part_max = count;
    g_part_unk = 0;
    task = fn_ovl_3850((void *)fn_ovl_5718);
    fn_ovl_3a18(task);
    return task;
}

OvlPoolPart *ovl_09286_5680(void)
{
    int i;
    int idx = g_part_cur;

    for (i = 0; i < g_part_max; i++) {
        OvlPoolPart *p = &g_part_buf[idx];
        idx++;
        if (idx >= g_part_max) {
            idx = 0;
        }
        if (!p->active) {
            p->active = 1;
            p->w44 = 0x80808080;
            p->w40 = 0;
            p->w48 = 0x80808080;
            g_part_cur = idx;
            p->h50 = 0;
            return p;
        }
    }
    return 0;
}
