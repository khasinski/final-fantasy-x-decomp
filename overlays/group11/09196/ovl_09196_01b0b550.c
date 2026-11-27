#include "p6_overlay.h"

typedef struct {
    P6Node node;        /* 0x00 */
    u16 cap;            /* 0x1C */
    u16 stride;         /* 0x1E */
    u8 *buf;            /* 0x20 */
    u8 *rd0;            /* 0x24 */
    u8 *rd1;            /* 0x28 */
    u16 rd0_cnt;        /* 0x2C */
    u16 rd1_cnt;        /* 0x2E */
    u16 wr_pos;         /* 0x30 */
    u16 count;          /* 0x32 */
    u16 rd_pos;         /* 0x34 */
    u16 pad36;
    P6Node *src;        /* 0x38 */
} RingB550;

typedef struct {
    RingB550 *obj;      /* 0x00 */
    u16 req;            /* 0x04 */
    u16 out0_cnt;       /* 0x06 */
    u16 out1_cnt;       /* 0x08 */
    u16 pad0A;
    u8 *out0;           /* 0x0C */
    u8 *out1;           /* 0x10 */
} ArgB550;

typedef struct {
    P6Node *node;       /* 0x00 */
    u8 flag;            /* 0x04 */
    u8 mark;            /* 0x05 */
} WalkMsgB550;

extern void g_fn_b390(ArgB550 *);
void func_002DD0B0(void *, void *);

void func_01B0B550(WalkMsgB550 *m)
{
    P6Node *root = m->node;

    if (root->mark == m->mark) {
        m->flag = 0;
    } else {
        P6Node *cur = root->last;
        while (cur != root) {
            m->node = cur;
            cur = cur->prev;
            m->node->vt->fn[7](m);
        }
        m->node = root;
        root->mark = m->mark;
        m->flag = 1;
    }
    if (m->flag & 1) {
        RingB550 *o = (RingB550 *)m->node;
        ArgB550 arg;
        WalkMsgB550 sub;
        register P6Node *src __asm__("$5");

        src = o->src;
        sub.mark = m->mark;
        sub.node = src;
        src->vt->fn[7](&sub);
        arg.obj = o;
        arg.req = 1;
        g_fn_b390(&arg);
        func_002DD0B0(arg.out0, (u8 *)o->src + 0x20);
    }
}
