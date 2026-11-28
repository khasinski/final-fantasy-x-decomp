#include "common.h"

typedef struct {
    u8 pad00[0x18];
    u32 state;
    int timer;
    u8 pad20[0x30B0];
    u8 f30D0[0x30];
    u8 f3100[0x30];
    u8 f3130[0x150];
    u8 f3280[0x50];
    u8 f32D0[0x2C];
    float f32FC;
    u8 pad3300[0x30];
    u8 f3330[0x50];
    u8 f3380[0xE8];
    u32 f3468;
} ObjCD50;

typedef struct {
    void *p00;
    ObjCD50 *obj;
} MsgCD50;

typedef struct {
    void *a;
    void *b;
    s16 c;
} MsgBC28;

extern void func_01B20DF0(void *);
extern void func_01B2BC28(void *);
extern void func_01B21180(void *);
extern void func_01B20F88(void *);
extern void func_01B272D0(void *);
extern void func_01B27228(void *);
extern void func_01B28DB8(void *);
extern void func_01B28D10(void *);
extern void func_01B26338(void *);
extern void func_01B26240(void *);
extern void func_01B27968(void *);
extern void func_01B278C0(void *);
extern void func_01B20D88(void *);
extern void func_01B20C38(void *);
extern void func_01B2CCF0(void *);
extern void func_01B2CCC8(void *);

void func_01B1CD50(MsgCD50 *a0)
{
    ObjCD50 *s4 = a0->obj;
    void *m0[4];
    float col[4];
    MsgBC28 m1;
    void *d[14];

loop:
    switch (s4->state) {
    case 0:
        s4->state = 0x10;
        goto loop;
    case 0x10:
        m0[0] = s4->f32D0;
        func_01B20DF0(m0);
        if (m0[1] != 0) {
            s4->state = 0x50;
            goto loop;
        }
        break;
    case 0x50:
        s4->state = 0x51;
        s4->timer = 10;
    case 0x51:
        if (s4->timer <= 0) {
            s4->state = 0x80;
            goto loop;
        }
        break;
    case 0x80:
        s4->timer = 8;
        {
            register u8 *a __asm__("$3") = s4->f3380;
            MsgBC28 *p = &m1;
            int t;
            col[0] = 1.0f;
            col[1] = 1.0f;
            col[2] = 1.0f;
            col[3] = 0.0f;
            t = *(s16 *)&s4->timer;
            __asm__("" : "+r"(t));
            m1.a = a;
            p->b = col;
            m1.c = t;
            func_01B2BC28(p);
        }
        s4->state++;
    case 0x81:
        s4->f32FC -= 0.125f;
        if (s4->timer <= 0) {
            s4->state = 0x1000;
            goto loop;
        }
        break;
    case 0x1000:
        if (s4->f3468 & 4) {
            u8 *p0 = s4->f32D0;
            u8 *p1 = s4->f3280;
            u8 *p2 = s4->f3130;
            u8 *p3 = s4->f30D0;
            u8 *p4 = s4->f3100;
            u8 *p5 = s4->f3330;

            d[0] = p0; func_01B21180(&d[0]);
            d[1] = p0; func_01B20F88(&d[1]);
            d[2] = p1; func_01B272D0(&d[2]);
            d[3] = p1; func_01B27228(&d[3]);
            d[4] = p2; func_01B28DB8(&d[4]);
            d[5] = p2; func_01B28D10(&d[5]);
            d[6] = p3; func_01B26338(&d[6]);
            d[7] = p3; func_01B26240(&d[7]);
            d[8] = p4; func_01B27968(&d[8]);
            d[9] = p4; func_01B278C0(&d[9]);
            d[10] = p5; func_01B20D88(&d[10]);
            d[11] = p5; func_01B20C38(&d[11]);
            d[12] = a0->p00; func_01B2CCF0(&d[12]);
            d[13] = a0->p00; func_01B2CCC8(&d[13]);
            s4->state = 0x2000;
        }
        break;
    }

    s4->timer--;
}
