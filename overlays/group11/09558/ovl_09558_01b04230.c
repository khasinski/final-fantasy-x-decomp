#include "common.h"

typedef struct OvlTask {
    void *p0;
    void *work;
} OvlTask;

typedef struct Ovl9558Sub2 {
    u8 pad00[0x18];
    u32 state;          /* 0x18 */
    int timer;          /* 0x1C */
    u8 pad20[0x1B0];
    u8 sub1D0[0xE8];    /* 0x1D0 */
    int w2B8;           /* 0x2B8 */
} Ovl9558Sub2;

void func_01B0EBD0(void *a0);
void func_01B0EC90(void *a0);
void func_01B0ED98(void *a0);
void func_01B0FC98(void *a0);

void func_01B04230(OvlTask *task)
{
    Ovl9558Sub2 *s = task->work;

    switch (s->state) {
    case 0:
        break;
    case 0x14:
        {
            float v[4];
            struct {
                void *p0;
                float *p4;
                s16 h8;
            } arg;

            v[0] = 1.0f;
            v[1] = 1.0f;
            v[2] = 1.0f;
            v[3] = 0.0f;
            arg.p0 = s->sub1D0;
            arg.p4 = v;
            arg.h8 = 0x14;
            func_01B0EBD0(&arg);
            s->state++;
        }
    case 0x15:
        if ((s->w2B8 & 1) == 0) {
            void *p = s->sub1D0;
            void *a0 = p;
            void *a1;
            void *a2;
            func_01B0ED98(&a0);
            a1 = p;
            func_01B0EC90(&a1);
            a2 = task->p0;
            func_01B0FC98(&a2);
            s->state = 0x4E20;
        }
        break;
    }
    s->timer--;
}
