/* Shared 09427-cluster script ops 5f80..600c (140 B span / 136 B code, 3 funcs). */

#include "common.h"

typedef struct {
    s16 op;
    s16 a;
    int b;
} Cmd2;

extern void fn_op_1c68(int, int);
extern void fn_op_1cc8(int);
extern void fn_op_1df0(int);

void *ovl_09427_5f80(void *ctx, Cmd2 *cmd)
{
    fn_op_1c68(cmd->a, cmd->b);
    return cmd + 1;
}

void *ovl_09427_5fb0(void *ctx, Cmd2 *cmd)
{
    fn_op_1cc8(cmd->b);
    return cmd + 1;
}

void *ovl_09427_5fe0(void *ctx, Cmd2 *cmd)
{
    fn_op_1df0(cmd->b);
    return cmd + 1;
}
