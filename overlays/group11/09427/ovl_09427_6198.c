/* Shared 09427-cluster script ops 6198..6260 (200 B span / 196 B code, 3 funcs). */

#include "common.h"

typedef struct {
    u16 op;
    u16 id;
    int a;
    int b;
    int c;
    int d;
} Cmd5;

typedef struct {
    u16 op;
    u16 id;
    int a;
    int b;
    int c;
} Cmd4;

extern void *fn_get_obj(int);
extern void fn_op_5120(void *, int, int, int, int);
extern void fn_op_52e8(void *, int, int, int);
extern void fn_op_5330(void *, int, int, int);

void *ovl_09427_6198(void *ctx, Cmd5 *cmd)
{
    fn_op_5120(fn_get_obj(cmd->id), cmd->a, cmd->b, cmd->c, cmd->d);
    return cmd + 1;
}

void *ovl_09427_61e0(void *ctx, Cmd4 *cmd)
{
    fn_op_52e8(fn_get_obj(cmd->id), cmd->a, cmd->b, cmd->c);
    return cmd + 1;
}

void *ovl_09427_6220(void *ctx, Cmd4 *cmd)
{
    fn_op_5330(fn_get_obj(cmd->id), cmd->a, cmd->b, cmd->c);
    return cmd + 1;
}
