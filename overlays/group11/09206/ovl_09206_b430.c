#include "common.h"

typedef struct VmCtx VmCtx;
typedef u8 *(*VmOpFn)(VmCtx *vm, u8 *pc);
typedef void (*VmCbFn)(VmCtx *vm);

struct VmCtx {
    u8 *pc;             /* 0x00 */
    u8 pad04[0x20];
    VmCbFn cb24;        /* 0x24 */
    VmCbFn cb28;        /* 0x28 */
    u8 pad2C[0x28];
    u16 wait;           /* 0x54 */
    u8 state;           /* 0x56 */
};

extern VmOpFn D_01B00FB0[];

s32 func_01B0B430(VmCtx *vm)
{
    u8 *pc = vm->pc;

    while (vm->state == 1) {
        pc = D_01B00FB0[*(u16 *)pc](vm, pc);
    }
    vm->pc = pc;

    switch (vm->state) {
    case 0:
        return 1;
    case 2:
        if (vm->wait != 0xFFFF) {
            if (--vm->wait == 0) {
                vm->state = 1;
            }
        }
        goto run_cb28;
    case 3:
        vm->cb24(vm);
    run_cb28:
        if (vm->cb28 != 0) {
            vm->cb28(vm);
        }
        break;
    }

    return 0;
}
