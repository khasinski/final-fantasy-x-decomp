/* 09339 unique state machine (1612 B). */
#include "common.h"

typedef struct {
    u8 pad00[0x18];
    u32 state;
    float t1;
    float t2;
    u32 pad24;
    int frame;
} OvlState;

typedef struct {
    u32 w00;
    OvlState *st;
} OvlCtx;

typedef struct {
    u8 pad00[0x20];
    float f20;
    float f24;
    float f28;
    float f2c;
} Obj8A0;

extern u8 g_0410[];
extern int g_0418;
extern u8 g_0428;
extern u8 g_0540[];
extern u8 g_05a0[];
extern u8 g_05d0[];
extern u8 g_07f8[];
extern u8 g_0818[];
extern u8 g_0840[];
extern Obj8A0 g_08a0[3];
extern u8 g_0930[];
extern u8 *g_0a70;
extern u8 g_0a80[];
extern u8 g_0bd0[];
extern u8 g_0bf0[];
extern u8 g_0c10[];
extern u8 g_0c50[];
extern u8 g_0d50[];
extern int g_0e50;
extern u8 g_0e58[];
extern u8 g_7d60[];
extern int g_7d8c;

extern int MsGetChrHandle(int);
extern int func_001CE050(int, int);
extern void func_001D41D8(int, int, int, int, int, int, float, float, float, float, float);
extern int func_001B7178(int, int, int, int, int, int);
extern int func_001CE1A8(int);
extern void func_002DD0B0(void *, void *);
extern int func_001C5E90(int, int, int);
extern void MsEffectEndMotion(int, int);

extern void fn_ovl_2d20(void *);
extern void fn_ovl_33c8(void *);
extern void fn_ovl_3958(void *);
extern void fn_ovl_2850(void *);
extern void fn_ovl_4610(void *);
extern void fn_ovl_6770(void *);
extern void fn_ovl_5f00(void *);
extern void fn_ovl_5ec8(void *);
extern void fn_ovl_3450(void *);
extern void fn_ovl_77c8(void *);

void ovl_09339_1498(OvlCtx *a0)
{
    OvlState *st = a0->st;
    union {
        u32 buf0[6];
        struct {
            u32 pad[4];
            u32 buf1[6];
        } s;
    } u;
    u32 arg30;
    u32 arg34;
#define buf0 (u.buf0)
#define buf1 (u.s.buf1)

    st->t1 += 1.0f / 30.0f;
    st->t2 += 1.0f / 30.0f;
    st->frame++;

    switch (st->state) {
    case 0:
        buf0[0] = (u32)g_0c10;
        buf0[1] = (u32)g_07f8;
        fn_ovl_2d20(buf0);
        g_0c10[0x30] = g_0428;
        g_0c10[0x31] |= 1;
        g_0e50 = MsGetChrHandle(20);
        buf0[0] = (u32)g_0bd0;
        buf0[1] = (u32)g_07f8;
        buf0[2] = (u32)g_0e50;
        buf0[3] = 13;
        fn_ovl_33c8(buf0);
        st->state = 10;
        /* fallthrough */

    case 10:
        func_001CE050(20, 0xB0);
        func_001D41D8(20, 11, g_0428, 30, 64, 16, 0.0f, 70.0f, 1.0f, 0.0f, 0.0f);
        func_001B7178(20, 2, 0, g_0428, 5, 15);
        st->state = 20;
        /* fallthrough */

    case 20:
        if (func_001CE1A8(20) == 0) {
            break;
        }
        func_001CE050(20, 0xB1);
        st->t2 = 0.0f;
        st->state = 30;
        /* fallthrough */

    case 30:
        if (st->t2 < 1.0f) {
            break;
        }
        buf0[0] = (u32)g_0840;
        buf0[1] = (u32)g_07f8;
        fn_ovl_3958(buf0);
        buf0[0] = (u32)&g_08a0[0];
        buf0[1] = (u32)g_07f8;
        fn_ovl_2850(buf0);
        g_08a0[0].f20 = 1.1f;
        g_08a0[0].f24 = 1.3f;
        g_08a0[0].f28 = 1.1f;
        g_08a0[0].f2c = 0.17f;
        {
            u32 *p = buf1;
            buf1[0] = (u32)g_0930;
            p[1] = (u32)g_07f8;
            p[2] = (u32)g_05d0;
            p[3] = (u32)g_0bd0;
            p[4] = (u32)g_05a0;
            p[5] = (u32)&g_08a0[0];
            fn_ovl_4610(p);
        }
        g_0930[0x14C] = 1;
        buf0[0] = (u32)g_0c50;
        buf0[1] = (u32)g_0818;
        buf0[2] = (u32)g_0930;
        buf0[3] = (u32)g_7d8c;
        buf0[4] = (u32)g_7d60;
        buf0[5] = 1;
        fn_ovl_6770(buf0);
        buf0[0] = (u32)g_0e58;
        buf0[1] = (u32)g_07f8;
        buf0[2] = (u32)g_0930;
        buf0[3] = (u32)g_0540;
        buf0[4] = *(u32 *)g_0410;
        buf0[5] = 0;
        fn_ovl_5f00(buf0);
        buf0[0] = (u32)g_0e58;
        buf0[1] = 0;
        fn_ovl_5ec8(buf0);
        buf0[0] = (u32)(g_0e58 + 0x38);
        buf0[1] = (u32)g_07f8;
        buf0[2] = (u32)g_0930;
        buf0[3] = (u32)g_0540;
        buf0[4] = *(u32 *)g_0410;
        buf0[5] = 1;
        fn_ovl_5f00(buf0);
        buf0[0] = (u32)(g_0e58 + 0x38);
        buf0[1] = 0;
        fn_ovl_5ec8(buf0);
        st->t2 = 0.0f;
        st->state = 40;
        /* fallthrough */

    case 40:
        if (func_001CE1A8(20) == 0) {
            break;
        }
        func_001CE050(20, 0xB2);
        buf0[0] = (u32)&g_08a0[2];
        buf0[1] = (u32)g_07f8;
        fn_ovl_2850(buf0);
        func_002DD0B0(&g_08a0[2].f20, g_0bf0);
        g_0a70 = (u8 *)&g_08a0[2];
        arg30 = (u32)(g_0bf0 - 0x20);
        fn_ovl_3450(&arg30);
        st->state = 50;
        /* fallthrough */

    case 41:
    case 50:
        if (st->t2 < 0.4f) {
            break;
        }
        buf0[0] = (u32)&g_08a0[1];
        buf0[1] = (u32)g_07f8;
        fn_ovl_2850(buf0);
        g_08a0[1].f20 = 1.0f;
        g_08a0[1].f24 = 1.0f;
        g_08a0[1].f28 = 1.0f;
        g_08a0[1].f2c = 0.16f;
        buf0[0] = (u32)g_0a80;
        buf0[1] = (u32)g_07f8;
        buf0[2] = (u32)g_05d0;
        buf0[3] = (u32)g_0c10;
        buf0[4] = (u32)g_05a0;
        buf0[5] = (u32)&g_08a0[1];
        fn_ovl_4610(buf0);
        g_0a80[0x14C] = 1;
        buf0[0] = (u32)g_0d50;
        buf0[1] = (u32)g_0818;
        buf0[2] = (u32)g_0a80;
        buf0[3] = (u32)g_7d8c;
        buf0[4] = (u32)g_7d60;
        buf0[5] = 0;
        fn_ovl_6770(buf0);
        func_001C5E90(g_0418, -5, 0);
        st->t2 = 0.0f;
        st->state++;
        /* fallthrough */

    case 51:
        if (st->t2 < 1.0f) {
            break;
        }
        func_001CE050(20, 0xB3);
        st->state = 60;
        /* fallthrough */

    case 60:
        if (func_001CE1A8(20) == 0) {
            break;
        }
        func_001CE050(20, 0xB4);
        func_001D41D8(20, 1, g_0428, 28, 64, 16, 0.0f, 0.0f, 0.7f, 0.0f, 0.0f);
        st->state++;
        /* fallthrough */

    case 61:
        if (func_001CE1A8(20) == 0) {
            break;
        }
        func_001CE050(20, 0xB5);
        st->state++;
        /* fallthrough */

    case 62:
        if (func_001CE1A8(20) == 0) {
            break;
        }
        st->state = 10000;
        /* fallthrough */

    case 10000:
        MsEffectEndMotion(20, 0);
        arg34 = a0->w00;
        fn_ovl_77c8(&arg34);
        break;
    }
}
