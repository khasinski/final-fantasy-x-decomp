#include "common.h"

typedef struct OvlTask {
    void *p0;
    void *work;
} OvlTask;

typedef struct Ovl9558Sub4 {
    u8 pad00[0x18];
    u32 state;          /* 0x18 */
    int timer;          /* 0x1C */
    u8 sub20[0x150];    /* 0x20 */
    u8 sub170[0x30];    /* 0x170 */
    u8 sub1A0[0x30];    /* 0x1A0 */
    u8 sub1D0[0x27];    /* 0x1D0 */
    u8 b1F7;            /* 0x1F7 */
} Ovl9558Sub4;

void func_01B05A18(void *a0);
void func_01B05B90(void *a0);
void func_01B0B310(void *a0);
void func_01B0B408(void *a0);
void func_01B0CB30(void *a0);
void func_01B0CBD8(void *a0);
void func_01B0FC98(void *a0);

void func_01B04870(OvlTask *task)
{
    volatile u32 pad[4];
    Ovl9558Sub4 *s = task->work;

top:
    switch (s->state) {
    case 0:
        s->state++;
    case 1:
        s->b1F7 -= 0x10;
        if (s->b1F7 != 0) {
            break;
        }
        s->state = 0x2710;
        goto top;
    case 0x2710:
        {
            void *p1D0 = s->sub1D0;
            void *p20 = s->sub20;
            void *p170 = s->sub170;
            void *p1A0 = s->sub1A0;
            void *a0 = p1D0;
            void *a1;
            void *a2;
            void *a3;
            void *a4;
            void *a5;
            void *a6;
            void *a7;
            void *a8;
            func_01B05B90(&a0);
            a1 = p1D0;
            func_01B05A18(&a1);
            a2 = p20;
            func_01B0CBD8(&a2);
            a3 = p20;
            func_01B0CB30(&a3);
            a4 = p170;
            func_01B0B408(&a4);
            a5 = p170;
            func_01B0B310(&a5);
            a6 = p1A0;
            func_01B0B408(&a6);
            a7 = p1A0;
            func_01B0B310(&a7);
            a8 = task->p0;
            func_01B0FC98(&a8);
            s->state = 0x4E20;
        }
        break;
    }
    s->timer--;
}
