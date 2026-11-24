#include "common.h"

typedef struct OvlTask {
    void *p0;
    void *work;
} OvlTask;

typedef struct Ovl9558Sub1 {
    u8 pad00[0x18];
    u32 state;          /* 0x18 */
    int timer;          /* 0x1C */
    int w20;            /* 0x20 */
    void *p24;          /* 0x24 */
    u8 pad28[0x8];
    u8 sub30[0x80];     /* 0x30 */
    u8 bB0;             /* 0xB0 */
    u8 bB1;             /* 0xB1 */
} Ovl9558Sub1;

void func_01B05BF8(void *a0);
void func_01B0FC98(void *a0);

void func_01B03E98(OvlTask *task)
{
    Ovl9558Sub1 *s = task->work;

top:
    switch (s->state) {
    case 0:
        s->bB0 -= 2;
        if (s->bB0 == 0x60) {
            s->timer = 0x1A;
            s->state++;
        }
        break;
    case 1:
        if (s->timer > 0) {
            break;
        }
        s->state = 0x1E;
        goto top;
    case 0x1E:
        s->timer = 0x28;
        s->state++;
    case 0x1F:
        if (s->timer > 0) {
            break;
        }
        s->w20 = 0x10;
        s->timer = 0;
        s->state++;
        goto top;
    case 0x20:
        if (s->bB1 != 0) {
            s->bB1 -= 0x20;
        }
        if (s->timer > 0) {
            break;
        }
        s->bB1 = 0x80;
        if (--s->w20 != 0) {
            s->timer = 6;
        } else {
            s->state++;
        }
        break;
    case 0x21:
        s->bB1 -= 0x20;
        if (s->bB1 != 0) {
            break;
        }
        s->state = 0xA;
        goto top;
    case 0xA:
        s->timer = 0x14;
        s->state++;
    case 0xB:
        if (s->timer > 0) {
            break;
        }
        s->state++;
        break;
    case 0xC:
        s->bB0 += 2;
        if (s->bB0 == 0x80) {
            void *arg = s->sub30;
            func_01B05BF8(&arg);
            s->timer = 2;
            s->state++;
        }
        break;
    case 0xD:
        if (s->timer > 0) {
            break;
        }
        {
            void *arg = task->p0;
            func_01B0FC98(&arg);
        }
        s->state = 0x4E20;
        break;
    }
    s->timer--;
}
