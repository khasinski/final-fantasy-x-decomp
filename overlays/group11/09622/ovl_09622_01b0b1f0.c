#include "common.h"

typedef struct TaskArg {
    void *task;
    void *work;
} TaskArg;

typedef struct WorkB1F0 {
    u8 pad00[0x18];
    int state;         /* 0x18 */
    int timer;         /* 0x1C */
    int idx;           /* 0x20 */
    void *chr;         /* 0x24 */
    u8 pad28[0x68];
    void *p90;         /* 0x90 */
} WorkB1F0;

typedef struct WorkB278 {
    u8 pad00[0x18];
    u32 state;         /* 0x18 */
    int timer;         /* 0x1C */
    u8 obj20[0x34];    /* 0x20 */
    float f54;         /* 0x54 */
    u8 pad58[0x08];
    u8 obj60[0x20];    /* 0x60 */
    float col80[4];    /* 0x80 */
    u8 obj90[0x14C];   /* 0x90 */
    u8 b1DC;           /* 0x1DC */
    u8 pad1DD[3];
    u8 obj1E0[0x100];  /* 0x1E0 */
} WorkB278;

extern u8 D_01B00720[];
extern u8 D_01B00750[];
extern u8 D_01B00960[];
extern u8 D_01B00998[];
extern u8 D_01B18A40[];
extern void *D_01B18A6C;

void func_01B0AE48(TaskArg *);
void func_01B0B278(TaskArg *);
void func_01B0DA18(void *);
void func_01B0DA98(void *);
void func_01B0DBC0(void *);
void func_01B11D30(void *);
void func_01B11D80(void *);
void func_01B11E78(void *);
void func_01B13550(void *);
void func_01B135A0(void *);
void func_01B13648(void *);
void func_01B16528(void *);
void func_01B16578(void *);
void func_01B16680(void *);
void func_01B174D8(void *);
void func_01B17580(void *);
void func_01B178E0(void *);

void func_01B0B1F0(WorkB1F0 *w, void *chr, int idx, void *p90)
{
    void *m[3];

    m[0] = w;
    m[1] = (void *)func_01B0AE48;
    m[2] = w;
    func_01B174D8(m);

    m[0] = D_01B00960;
    m[1] = w;
    func_01B178E0(m);

    w->p90 = p90;
    w->idx = idx;
    w->chr = chr;
    w->state = 0;
}

void func_01B0B278(TaskArg *arg)
{
    WorkB278 *w = (WorkB278 *)arg->work;

loop:
    switch (w->state) {
    case 0:
        w->timer = 30;
        w->state++;
    case 1:
        w->f54 -= 8.0f;
        if (w->f54 <= 0.0f) {
            w->f54 = 0.0f;
            w->state = 20;
            goto loop;
        }
        break;
    case 20:
        {
            void *m0[1];
            void *m1[1];
            void *m2[1];
            void *m3[1];
            void *m4[1];
            void *m5[1];
            void *m6[1];
            void *m7[1];
            void *m8[1];

            m0[0] = w->obj1E0;
            func_01B16680(m0);
            m1[0] = w->obj1E0;
            func_01B16578(m1);
            m2[0] = w->obj90;
            func_01B13648(m2);
            m3[0] = w->obj90;
            func_01B135A0(m3);
            m4[0] = w->obj60;
            func_01B11E78(m4);
            m5[0] = w->obj60;
            func_01B11D80(m5);
            m6[0] = w->obj20;
            func_01B0DBC0(m6);
            m7[0] = w->obj20;
            func_01B0DA98(m7);
            m8[0] = arg->task;
            func_01B17580(m8);
            w->state = 20000;
        }
        break;
    }
    w->timer--;
}
