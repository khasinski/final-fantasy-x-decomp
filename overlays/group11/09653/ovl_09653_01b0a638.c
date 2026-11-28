#include "common.h"

extern void g_fn_ba8(void *);
extern void g_fn_c88(void *);
extern void g_fn_390(void *);

typedef struct {
    int a;
    int b;
    int c;
    int d;
} Msg;

void func_01B0A638(u8 *a0)
{
    u8 *s0 = *(u8 **)(a0 + 4);
    Msg msg0;
    Msg msg1;
    Msg msg2;
    Msg msg3;
    Msg msg4;

loop:
    switch (*(u32 *)(s0 + 0x18)) {
    case 0:
    case 1:
        break;
    case 10:
        msg0.a = *(int *)(s0 + 0x1C);
        msg0.b = 0xB8;
        g_fn_c88(&msg0);
        *(u32 *)(s0 + 0x18) += 1;
        break;
    case 11:
        msg0.a = *(int *)(s0 + 0x1C);
        g_fn_ba8(&msg0);
        if (msg0.b != 0) {
            *(u32 *)(s0 + 0x18) = 20;
            goto loop;
        }
        break;
    case 20: {
        Msg *p = &msg1;
        p->a = *(int *)(s0 + 0x1C);
        p->b = 0xB9;
        g_fn_c88(p);
        *(u32 *)(s0 + 0x18) += 1;
        break;
    }
    case 21:
        break;
    case 30: {
        Msg *p = &msg1;
        p->a = *(int *)(s0 + 0x1C);
        p->b = 0xBA;
        g_fn_c88(p);
        *(u32 *)(s0 + 0x18) += 1;
        break;
    }
    case 31:
        msg1.a = *(int *)(s0 + 0x1C);
        g_fn_ba8(&msg1);
        if (msg1.b != 0) {
            *(u32 *)(s0 + 0x18) = 40;
            goto loop;
        }
        break;
    case 40: {
        Msg *p = &msg2;
        p->a = *(int *)(s0 + 0x1C);
        p->b = 0xBB;
        g_fn_c88(p);
        *(u32 *)(s0 + 0x18) += 1;
        break;
    }
    case 41:
        break;
    case 50:
        *(u32 *)(s0 + 0x18) = 51;
        break;
    case 51:
        break;
    case 60: {
        Msg *p = &msg2;
        p->a = *(int *)(s0 + 0x1C);
        p->b = 0xBD;
        g_fn_c88(p);
        *(u32 *)(s0 + 0x18) += 1;
        break;
    }
    case 61:
        msg2.a = *(int *)(s0 + 0x1C);
        g_fn_ba8(&msg2);
        if (msg2.b != 0) {
            Msg *p = &msg3;
            p->a = *(int *)(s0 + 0x1C);
            p->b = 0xBC;
            g_fn_c88(p);
            *(u32 *)(s0 + 0x18) += 1;
        }
        break;
    case 62:
        break;
    case 10000:
        msg4.a = *(int *)(a0 + 0);
        g_fn_390(&msg4);
        break;
    }

    *(int *)(s0 + 0x2C) += 1;
    *(int *)(s0 + 0x30) += 1;
}
