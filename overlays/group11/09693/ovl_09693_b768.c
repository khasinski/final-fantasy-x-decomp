#include "common.h"

typedef struct TaskArg {
    void *task;
    void *work;
} TaskArg;

typedef struct WorkB518 {
    u8 pad00[0x18];
    int state;         /* 0x18 */
    float f1C;         /* 0x1C */
    int timer;         /* 0x20 */
    int cnt;           /* 0x24 */
    int idx;           /* 0x28 */
    u8 pad2C[0x634];
    u8 obj660[0x60];   /* 0x660 */
} WorkB518;

typedef struct Data4F0 {
    u8 col[8];         /* 0x00 */
    u8 pad08[0x1C];
    float f24;         /* 0x24 */
    u8 pad28[0x28];
} Data4F0;             /* 0x50 */

extern Data4F0 D_01B004F0[];

void func_01B0D7B8(void *);
void func_01B0D9B0(void *);
void func_01B17580(void *);

void func_01B0B768(TaskArg *arg)
{
    WorkB518 *w = (WorkB518 *)arg->work;

loop:
    switch (w->state) {
    case 0:
        w->timer = 5;
        w->state++;
    case 1:
        if (w->timer <= 0) {
            Data4F0 *d = &D_01B004F0[w->idx];
            d->f24 += 0.05f;
            if (d->f24 >= 0.7f) {
                w->state = 10;
                goto loop;
            }
        }
        break;
    case 10:
        w->timer = 30;
        w->cnt = 1;
        w->state++;
    case 11:
        if (w->timer <= 0) {
            if (w->cnt == 0) {
                w->state = 40;
                goto loop;
            }
            w->cnt--;
            w->timer = 15;
        }
        break;
    case 40:
        w->timer = 14;
        w->state++;
        break;
    case 41:
        if (w->timer <= 0) {
            w->f1C = 1.0f;
            w->state++;
            goto loop;
        }
        break;
    case 42:
        w->f1C -= 0.05f;
        if (w->f1C <= 0.0f) {
            void *m0[1];
            void *m1[1];
            m0[0] = w->obj660;
            func_01B0D9B0(m0);
            m1[0] = w->obj660;
            func_01B0D7B8(m1);
            w->state = 20;
            goto loop;
        } else {
            D_01B004F0[w->idx].col[0] = (u8)((float)D_01B004F0[w->idx].col[0] * w->f1C);
            D_01B004F0[w->idx].col[1] = (u8)((float)D_01B004F0[w->idx].col[1] * w->f1C);
            D_01B004F0[w->idx].col[2] = (u8)((float)D_01B004F0[w->idx].col[2] * w->f1C);
            D_01B004F0[w->idx].col[3] = (u8)((float)D_01B004F0[w->idx].col[3] * w->f1C);
            D_01B004F0[w->idx].col[4] = (u8)((float)D_01B004F0[w->idx].col[4] * w->f1C);
            D_01B004F0[w->idx].col[5] = (u8)((float)D_01B004F0[w->idx].col[5] * w->f1C);
            D_01B004F0[w->idx].col[6] = (u8)((float)D_01B004F0[w->idx].col[6] * w->f1C);
            D_01B004F0[w->idx].col[7] = (u8)((float)D_01B004F0[w->idx].col[7] * w->f1C);
        }
        break;
    case 20:
        {
            void *m4[1];
            m4[0] = arg->task;
            func_01B17580(m4);
            w->state = 20000;
        }
        break;
    }
    w->timer--;
}
