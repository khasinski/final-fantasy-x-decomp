#include "common.h"

typedef struct CmdVm {
    u32 u00;
    u32 loop_pc[4];     /* 0x04 */
    u32 call_pc[4];     /* 0x14 */
    u32 w24;            /* 0x24 */
    u32 w28;            /* 0x28 */
    u32 reg[8];         /* 0x2C */
    u16 loop_cnt[4];    /* 0x4C */
    u16 wait;           /* 0x54 */
    u8 state;           /* 0x56 */
    u8 loop_sp;         /* 0x57 */
    u8 call_sp;         /* 0x58 */
} CmdVm;

void func_01B06F48(int a, u32 b, u32 c);

u8 *func_01B0A930(CmdVm *vm, u8 *pc)
{
    vm->state = 2;
    vm->wait = *(u16 *)(pc + 2);
    return pc + 4;
}

u8 *func_01B0A948(CmdVm *vm, u8 *pc)
{
    return *(u8 **)(pc + 4);
}

u8 *func_01B0A950(CmdVm *vm, u8 *pc)
{
    return (u8 *)vm->reg[*(u16 *)(pc + 2)];
}

u8 *func_01B0A968(CmdVm *vm, u8 *pc)
{
    u8 *next = pc + 4;
    vm->loop_cnt[vm->loop_sp] = *(u16 *)(pc + 2);
    vm->loop_pc[vm->loop_sp] = (u32)next;
    vm->loop_sp++;
    return next;
}

u8 *func_01B0A9A8(CmdVm *vm, u8 *pc)
{
    u8 idx = vm->loop_sp - 1;
    if (vm->loop_cnt[idx] != 0xFFFF) {
        vm->loop_cnt[idx]--;
    }
    if (vm->loop_cnt[idx] != 0) {
        return (u8 *)vm->loop_pc[idx];
    }
    vm->loop_sp--;
    return pc + 4;
}

u8 *func_01B0AA10(CmdVm *vm, u8 *pc)
{
    vm->call_pc[vm->call_sp] = (u32)(pc + 8);
    vm->call_sp++;
    return *(u8 **)(pc + 4);
}

u8 *func_01B0AA38(CmdVm *vm, u8 *pc)
{
    vm->call_sp--;
    return (u8 *)vm->call_pc[vm->call_sp];
}

u8 *func_01B0AA58(CmdVm *vm, u8 *pc)
{
    ((void (*)(void))(*(u32 *)(pc + 4)))();
    return pc + 8;
}

u8 *func_01B0AA88(CmdVm *vm, u8 *pc)
{
    vm->state = 3;
    vm->w24 = *(u32 *)(pc + 4);
    return pc + 8;
}

u8 *func_01B0AAA0(CmdVm *vm, u8 *pc)
{
    vm->w28 = *(u32 *)(pc + 4);
    return pc + 8;
}

u8 *func_01B0AAB0(CmdVm *vm, u8 *pc)
{
    vm->reg[*(u16 *)(pc + 2)] = *(u32 *)(pc + 4);
    return pc + 8;
}

u8 *func_01B0AAD0(CmdVm *vm, u8 *pc)
{
    u8 *next = pc + 4;
    vm->reg[*(u16 *)(pc + 2)] = (u32)next;
    return next;
}

u8 *func_01B0AAF0(CmdVm *vm, u8 *pc)
{
    vm->state = 0;
    return pc;
}

u8 *func_01B0AB00(CmdVm *vm, u8 *pc)
{
    func_01B06F48(*(s16 *)(pc + 2), *(u32 *)(pc + 4), *(u32 *)(pc + 8));
    return pc + 12;
}
