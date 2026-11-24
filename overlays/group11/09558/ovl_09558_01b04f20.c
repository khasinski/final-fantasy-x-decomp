#include "common.h"

typedef struct OvlTask {
    void *p0;
    void *work;
} OvlTask;

typedef struct Ovl9558Sub5 {
    u8 pad00[0x18];
    u32 state;          /* 0x18 */
    u8 pad1C[0x1B44];
} Ovl9558Sub5; /* size 0x1B60 */

typedef struct Ovl9558Sub6 {
    u8 pad00[0x18];
    u32 state;          /* 0x18 */
    int timer;          /* 0x1C */
    int w20;            /* 0x20 */
    void *p24;          /* 0x24 */
    void *p28;          /* 0x28 */
    void *p2C;          /* 0x2C */
    void *p30;          /* 0x30 */
    u8 pad34[0xC];
    Ovl9558Sub5 sub40[1]; /* 0x40..0x1BA0 */
} Ovl9558Sub6;

extern u8 D_01B00B80[];

void func_01B04D48(Ovl9558Sub5 *a0, void *a1, void *a2, void *a3, void *a4);
void func_01B0FBF0(void *a0);
void func_01B0FC98(void *a0);
void func_01B0FFF8(void *a0);

void func_01B04F20(OvlTask *task)
{
    volatile u32 pad[4];
    Ovl9558Sub6 *s = task->work;

    switch (s->state) {
    case 0:
        s->timer = 0;
        s->state++;
        s->w20 = 0;
    case 1:
        if (s->timer > 0) {
            break;
        }
        if (s->sub40[0].state == 0x4E20) {
            func_01B04D48(&s->sub40[0], s->p24, s->p28, s->p2C, s->p30);
            s->timer = 0xA;
            s->w20++;
        }
        break;
    case 0x2710:
        {
            int mask = 0x4E20;
            int i;
            for (i = 0; i < 1; i++) {
                mask &= s->sub40[i].state;
            }
            if (mask != 0) {
                void *arg = task->p0;
                func_01B0FC98(&arg);
                s->state = 0x4E20;
            }
        }
        break;
    }
    s->timer--;
}

void func_01B05018(Ovl9558Sub6 *s, void *a1, void *a2, void *a3, void *a4)
{
    void *args[3];
    int i;

    args[0] = s;
    args[1] = (void *)func_01B04F20;
    args[2] = s;
    func_01B0FBF0(args);

    args[0] = D_01B00B80;
    args[1] = s;
    func_01B0FFF8(args);

    for (i = 0; i >= 0; i--) {
        s->sub40[i].state = 0x4E20;
    }

    s->p30 = a4;
    s->p2C = a3;
    s->p28 = a2;
    s->p24 = a1;
    s->state = 0;
}
