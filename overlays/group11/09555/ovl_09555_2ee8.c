#include "common.h"

typedef struct {
    u8 pad00[0x210];
    u8 b210;
    u8 b211;
    u8 b212;
    u8 b213;
    u8 pad214[0x8];
    float f21C;
    float f220;
    u8 pad224[0x4];
    s32 w228;
} Obj20C0;

typedef struct {
    u8 pad00[0x20C0];
    Obj20C0 obj;
    u8 pad22EC[0xC];
    s32 w22F8;
    s32 w22FC;
} Work9555;

extern u8 D_01B0AA60[];
extern Work9555 *D_01B0ABE8;

extern void **func_01B06B10(void *, s32);
extern void func_01B02AE0(float *);
extern void func_01B07B28(void *, void *, float *);
extern void func_01B02B90(void);
extern void *func_01B06220(void (*)(void));
extern void func_01B063E8(void *);

void func_01B02EE8(void)
{
    Work9555 *w = D_01B0ABE8;
    Obj20C0 *o = &w->obj;
    void *p;
    float vec[4];

    p = *func_01B06B10(D_01B0AA60, 10);
    func_01B02AE0(vec);
    func_01B07B28(o, p, vec);

    o->w228 = 0x140;
    o->f220 = 0.15f;
    o->f21C = 2.0f;
    o->b213 = 0x40;
    o->b212 = 0x40;
    o->b211 = 0x40;
    o->b210 = 0x40;
    w->w22F8 = 0x28;
    w->w22FC = 0x4B;

    func_01B063E8(func_01B06220(func_01B02B90));
}
