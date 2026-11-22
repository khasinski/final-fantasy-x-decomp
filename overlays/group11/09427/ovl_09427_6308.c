/* Shared 09427-cluster script ops 6308..6430 (296 B span / 288 B code, 6 funcs). */

#include "common.h"

typedef struct {
    s16 op;
    s16 a;
} Cmd1;

typedef struct {
    u16 op;
    u16 a;
} Cmd1U;

typedef struct {
    s16 op;
    s16 a;
    int b;
} Cmd2;

typedef struct {
    s16 op;
    s16 a;
    int b;
    int c;
} Cmd3;

typedef struct {
    s16 op;
    s16 a;
    int b;
    s16 c;
    s16 d;
} Cmd3H;

extern void fn_op_1fc8(int, int);
extern void fn_op_2ef8(int, int, int, int);
extern void fn_op_2e80(int, int, int);
extern void fn_op_2eb8(void);
extern void func_00117E58(int);
extern void fn_op_1f98(int, int);

void *ovl_09427_6308(void *ctx, Cmd2 *cmd)
{
    fn_op_1fc8(cmd->a, cmd->b);
    return cmd + 1;
}

void *ovl_09427_6338(void *ctx, Cmd3H *cmd)
{
    fn_op_2ef8(cmd->b, cmd->a, cmd->c, cmd->d);
    return cmd + 1;
}

void *ovl_09427_6370(void *ctx, Cmd3 *cmd)
{
    fn_op_2e80(cmd->b, cmd->a, cmd->c);
    return cmd + 1;
}

void *ovl_09427_63a8(void *ctx, Cmd1 *cmd)
{
    fn_op_2eb8();
    return cmd + 1;
}

void *ovl_09427_63d0(void *ctx, Cmd1U *cmd)
{
    func_00117E58(cmd->a);
    return cmd + 1;
}

void *ovl_09427_6400(void *ctx, Cmd2 *cmd)
{
    fn_op_1f98(cmd->a, cmd->b);
    return cmd + 1;
}
