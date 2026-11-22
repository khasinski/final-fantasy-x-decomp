/* Shared 09427-cluster script op 5e58 (52 B, 1 func). */

#include "common.h"

typedef struct {
    s16 op;
    s16 a;
    int b;
    int c;
} Cmd3;

extern void fn_op_2988(int, int, int);

void *ovl_09427_5e58(void *ctx, Cmd3 *cmd)
{
    fn_op_2988(cmd->a, cmd->b, cmd->c);
    return cmd + 1;
}
