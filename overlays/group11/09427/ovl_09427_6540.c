/* Shared 09427-cluster script ops 6540..674c (524 B span / 500 B code, 10 funcs). */

#include "common.h"

typedef struct {
    s16 op;
    s16 a;
} Cmd1;

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
    u16 op;
    u16 id;
    int a;
    int b;
    int c;
    int d;
    int e;
} Cmd6;

typedef struct {
    s16 op;
    s16 a;
    int (*fn)(void);
    void *target;
} CmdBranch;

typedef struct {
    void *pc;
    u8 pad04[0x24];
    int w28;
    u8 pad2C[0x2A];
    u8 b56;
    u8 b57;
    u8 b58;
} ScriptCtx;

extern void fn_op_1aa8(int);
extern void fn_op_1d38(int);
extern void *fn_get_obj(int);
extern void fn_op_5098(void *, int, int, int, int, int);
extern void fn_op_51c8(void *, int, int, int, int, int);
extern void fn_op_2d80(int);
extern void fn_op_31e0(int, int, int);
extern void fn_op_1ee0(int);
extern void fn_op_1e80(void);

void *ovl_09427_6540(void *ctx, Cmd1 *cmd)
{
    fn_op_1aa8(cmd->a);
    return cmd + 1;
}

void *ovl_09427_6570(void *ctx, Cmd2 *cmd)
{
    fn_op_1d38(cmd->b);
    return cmd + 1;
}

void *ovl_09427_65a0(void *ctx, Cmd6 *cmd)
{
    fn_op_5098(fn_get_obj(cmd->id), cmd->a, cmd->b, cmd->c, cmd->d, cmd->e);
    return cmd + 1;
}

void *ovl_09427_65e8(void *ctx, Cmd6 *cmd)
{
    fn_op_51c8(fn_get_obj(cmd->id), cmd->a, cmd->b, cmd->c, cmd->d, cmd->e);
    return cmd + 1;
}

void *ovl_09427_6630(void *ctx, Cmd2 *cmd)
{
    fn_op_2d80(cmd->b);
    return cmd + 1;
}

void *ovl_09427_6660(void *ctx, CmdBranch *cmd)
{
    if (cmd->fn() == 1) {
        return cmd->target;
    }
    return cmd + 1;
}

void *ovl_09427_66a0(void *ctx, Cmd3 *cmd)
{
    fn_op_31e0(cmd->b, cmd->a, cmd->c);
    return cmd + 1;
}

void *ovl_09427_66d8(void *ctx, Cmd2 *cmd)
{
    fn_op_1ee0(cmd->b);
    return cmd + 1;
}

void *ovl_09427_6708(void *ctx, Cmd1 *cmd)
{
    fn_op_1e80();
    return cmd + 1;
}

void ovl_09427_6730(ScriptCtx *ctx, void *pc)
{
    ctx->pc = pc;
    ctx->w28 = 0;
    ctx->b57 = 0;
    ctx->b58 = 0;
    ctx->b56 = 1;
}
