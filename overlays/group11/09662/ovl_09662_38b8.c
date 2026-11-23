/* Shared 09662/09455/09718 state machine A (328 B, 09662 @ 0x01B038B8). */

#include "common.h"

typedef struct {
    u8 pad00[0x54];
    int w54;
} Sub590;

typedef struct {
    u8 pad00[0x108];
    int w108;
    u8 pad10C[0x114];
    u8 b220[0x60];
    u8 b280[0x60];
    u8 b2E0[0x2A0];
    float f580;
    u8 pad584[0x08];
    int state;
    Sub590 *p590;
    u8 b594[4];
} OvlObj;

extern void *g_4f4;
extern int func_001C5E90(void *, int, int);
extern void fn_9878(void *);
extern void fn_9780(void *);
extern void fn_a9b0(void *);
extern void fn_a908(void *);
extern void fn_c300(void *);
extern void fn_c1f8(void *);
extern void fn_da70(void *);

void ovl_09662_38b8(void **arg)
{
    void *end[9];
    OvlObj *o = (OvlObj *)arg[1];

    o->f580 += 1.0f / 30.0f;
    switch (o->state) {
    case 0:
        if (o->f580 >= 0.25f) {
            func_001C5E90(g_4f4, o->p590->w54, 0x20);
            o->state++;
        }
        break;
    case 1:
        if (o->w108 & 4) {
            u8 *p0 = o->b220;
            u8 *p1 = o->b280;
            u8 *p2 = o->b2E0;
            u8 *p3 = o->b594;

            end[0] = p0;
            fn_9878(&end[0]);
            end[1] = p0;
            fn_9780(&end[1]);
            end[2] = p1;
            fn_9878(&end[2]);
            end[3] = p1;
            fn_9780(&end[3]);
            end[4] = p2;
            fn_a9b0(&end[4]);
            end[5] = p2;
            fn_a908(&end[5]);
            end[6] = p3;
            fn_c300(&end[6]);
            end[7] = p3;
            fn_c1f8(&end[7]);
            end[8] = arg[0];
            fn_da70(&end[8]);
            o->state = 0xFF;
        }
        break;
    }
}
