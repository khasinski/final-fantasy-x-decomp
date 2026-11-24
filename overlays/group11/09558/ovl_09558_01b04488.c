#include "common.h"

typedef struct OvlTask {
    void *p0;
    void *work;
} OvlTask;

typedef struct Ovl9558Sub3 {
    u8 pad00[0x18];
    u32 state;          /* 0x18 */
    int timer;          /* 0x1C */
    u8 sub20[0x160];    /* 0x20 */
    u8 sub180[0x30];    /* 0x180 */
    u8 sub1B0[0x118];   /* 0x1B0 */
    int w2C8;           /* 0x2C8 */
} Ovl9558Sub3;

void func_01B0B310(void *a0);
void func_01B0B408(void *a0);
void func_01B0CB30(void *a0);
void func_01B0CBD8(void *a0);
void func_01B0FC98(void *a0);

void func_01B04488(OvlTask *task)
{
    volatile u32 pad[4];
    Ovl9558Sub3 *s = task->work;

top:
    switch (s->state) {
    case 0:
        s->timer = 2;
        s->state++;
    case 1:
        if (s->timer > 0) {
            break;
        }
        s->state = 0x2710;
        goto top;
    case 0x2710:
        if ((s->w2C8 & 4) != 0) {
            void *p20 = s->sub20;
            void *p180 = s->sub180;
            void *p1B0 = s->sub1B0;
            void *a0 = p20;
            void *a1;
            void *a2;
            void *a3;
            void *a4;
            void *a5;
            void *a6;
            func_01B0CBD8(&a0);
            a1 = p20;
            func_01B0CB30(&a1);
            a2 = p180;
            func_01B0B408(&a2);
            a3 = p180;
            func_01B0B310(&a3);
            a4 = p1B0;
            func_01B0B408(&a4);
            a5 = p1B0;
            func_01B0B310(&a5);
            a6 = task->p0;
            func_01B0FC98(&a6);
            s->state = 0x4E20;
        }
        break;
    }
    s->timer--;
}
