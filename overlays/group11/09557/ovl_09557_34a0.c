#include "common.h"

typedef struct {
    void *task;
    u8 *work;
} TaskArg34A0;

typedef struct {
    void *p0;
    void *p4;
    void *p8;
    void *pC;
    void *p10;
    s32 w14;
} Msg34A0;

extern void *D_01B00640;
extern void *D_01B00648;
extern u8 D_01B00658;
extern u8 D_01B00A48[];
extern u8 D_01B10530[];
extern void *D_01B1055C;

extern void func_01B0E198(void *);
extern s32 func_001C5E90(void *, u32, s32);
extern void *func_002B49A0(void *, s32, s32);
extern void func_0014D3F0(s32, s32, void *);
extern void func_01B0F1F0(void *);

static inline void set_p4(Msg34A0 *p, void *v) { p->p4 = v; }
static inline void set_p10_14(Msg34A0 *p, void *p10, s32 w14) { p->p10 = p10; p->w14 = w14; }

void func_01B034A0(TaskArg34A0 *a0) {
    u8 pad00[0x10];
    Msg34A0 m;
    void *m30[1];
    u8 *s0 = a0->work;

loop:
    switch (*(u32 *)(s0 + 0x18)) {
    case 0:
        *(s32 *)(s0 + 0x1C) = 3;
        *(s32 *)(s0 + 0x18) += 1;
        break;
    case 1:
        if (*(s32 *)(s0 + 0x1C) <= 0) {
            Msg34A0 *p = &m;
            m.p0 = s0 + 0x200;
            *(volatile void **)&p->p4 = D_01B00A48;
            m.p8 = s0 + 0x20;
            m.pC = D_01B1055C;
            *(volatile void **)&p->p10 = D_01B10530;
            p->w14 = 1;
            func_01B0E198(p);
            func_001C5E90(D_01B00648, D_01B00658, 0);
            func_0014D3F0(7, 2, func_002B49A0(D_01B00640, 5, 0));
            *(s32 *)(s0 + 0x18) += 1;
        }
        break;
    case 2:
        if (*(u32 *)(s0 + 0x2E8) & 4) {
            *(s32 *)(s0 + 0x18) = 10000;
            goto loop;
        }
        break;
    case 10000:
        m30[0] = a0->task;
        func_01B0F1F0(m30);
        *(s32 *)(s0 + 0x18) = 20000;
        break;
    }
    *(s32 *)(s0 + 0x1C) -= 1;
}
