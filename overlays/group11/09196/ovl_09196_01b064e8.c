#include "common.h"

typedef struct TaskArg {
    void *task;
    void *work;
} TaskArg;

typedef struct Work64E8 {
    u8 pad00[0x18];
    int timer;      /* 0x18 */
    int state;      /* 0x1C */
    void *cam;      /* 0x20 */
    u8 *p24;        /* 0x24 */
    u8 *p28;        /* 0x28 */
    void *p2C;      /* 0x2C */
    u8 pad30[0x80];
    float fB0;      /* 0xB0 */
    u8 padB4[0xA0];
    int f154;       /* 0x154 */
} Work64E8;

extern void Sg_AccSetAlpha(int, int);
extern void MsSetScreenInfo(int, int, int);
extern void MsCameraFree(void *);
extern void MsCameraSetRect(void *, int, void *);
extern void func_01B183A8(void *);

void func_01B064E8(TaskArg *s1)
{
    Work64E8 *s0 = (Work64E8 *)s1->work;

loop:
    switch (s0->state) {
    case 0:
        s0->state = 1;
        s0->timer = 40;
    case 1:
        if (s0->timer <= 0) {
            s0->state = 10000;
            goto loop;
        }
        break;
    case 10000:
        Sg_AccSetAlpha(0, 30);
        {
            register int st __asm__("$3") = s0->state;
            s0->timer = 40;
            s0->state = st + 1;
        }
    case 10001:
        if (s0->timer <= 0) {
            void *arg[1];
            register void *t __asm__("$3");
            MsSetScreenInfo(0, 1, 0);
            MsSetScreenInfo(1, 0, 1);
            MsCameraFree(s0->cam);
            t = s1->task;
            arg[0] = t;
            func_01B183A8(arg);
            return;
        }
        break;
    }

    MsCameraSetRect(s0->cam, 1, s0->p24 + 0x20);
    MsCameraSetRect(s0->cam, 0, s0->p28 + 0x20);
    s0->fB0 -= 0.04f;
    s0->f154 += 0x90;
    s0->timer--;
}
