#include "p9_overlay.h"
#include "vu0.h"

struct Ovl09224B;
struct Ovl09224Task;

typedef struct Ovl09224TaskSub {
    u8 pad0[0x10];
    void (*fn)(struct Ovl09224Task *);
} Ovl09224TaskSub;

typedef struct Ovl09224Task {
    u8 pad0[8];
    Ovl09224TaskSub *unk8;
    u8 padC[8];
    struct Ovl09224B *arg;
} Ovl09224Task;

typedef struct Ovl09224B {
    u8 pad0[0x10];
    P9Vec pos;                  /* 0x10 */
    u8 pad20[0x10];
    u8 unk30[0x228];            /* 0x30 */
    int unk258;                 /* 0x258 */
    u8 pad25C[4];
    P9Vec target;               /* 0x260 */
    P9Vec vel;                  /* 0x270 */
    void (*cbMove)(struct Ovl09224B *); /* 0x280 */
    void (*cbHit)(struct Ovl09224B *);  /* 0x284 */
    float speed;                /* 0x288 */
    float scale;                /* 0x28C */
    int delay;                  /* 0x290 */
    u8 pad294[4];
    u16 flags;                  /* 0x298 */
} Ovl09224B;

void func_002DD038(float dst[4], float a[4], float b[4]);
Ovl09224Task *func_01B03820(void (*fn)(Ovl09224Task *));
void func_01B038A0(Ovl09224Task *task);
void func_01B039E8(Ovl09224Task *task);
void func_01B048B0(P9Vec *rot, P9Vec *from, P9Vec *to);
void func_01B04F68(Ovl09224B *s, float m[4][4], int a2);
void func_01B051A8(void *p, float m[4][4], P9Vec *pos);

void func_01B05AB8(Ovl09224Task *task);
void func_01B05C90(Ovl09224Task *task);

void func_01B05A10(Ovl09224B *s, float speed)
{
    float m[4][4];
    P9Vec rot;
    Ovl09224Task *task;

    s->vel.x = 0.0f;
    s->vel.y = 0.0f;
    s->vel.w = 0.0f;
    s->vel.z = -speed;
    func_01B048B0(&rot, &s->pos, &s->target);
    func_002DD128(m);
    func_002DD270(m, m, rot.x);
    func_002DD318(m, m, rot.y);
    func_002DCE08((float *)&s->vel, m, (float *)&s->vel);
    s->speed = speed;
    task = func_01B03820(func_01B05AB8);
    task->arg = s;
    func_01B039E8(task);
}

void func_01B05AB8(Ovl09224Task *task)
{
    float m[4][4];
    float diff[4];
    register Ovl09224B *s __asm__("$16") = task->arg;
    register P9Vec *target __asm__("$19");
    register u32 len_i __asm__("$7");
    float len;

    if (s->delay > 0) {
        s->delay--;
        return;
    }
    if (s->delay == 0) {
        MMI_COPY_LQ_A3(diff, &s->pos);
        MMI_COPY_SQ_A3(diff);
    } else {
        func_002DD020(diff, (float *)&s->pos, (float *)&s->vel);
    }
    target = &s->target;
    func_002DD038(diff, diff, (float *)target);
    VU0_LQC2(1, 0, diff);
    VU0_OP("vmul.xyz $vf1, $vf1, $vf1");
    VU0_OP("vaddy.x $vf1, $vf1, $vf1y");
    VU0_OP("vaddz.x $vf1, $vf1, $vf1z");
    VU0_OP("vsqrt Q, $vf1x");
    VU0_OP("vwaitq");
    VU0_OP("vaddq.x $vf1, $vf0, Q");
    VU0_QMFC2_NI(len_i, 1);
    __asm__ volatile("mtc1 %1, %0" : "=f"(len) : "r"(len_i));

    if (len > s->speed) {
        if (s->delay == 0) {
            s->delay = -1;
        } else {
            func_002DD020((float *)&s->pos, (float *)&s->pos, (float *)&s->vel);
        }
        if (s->cbMove != 0) {
            s->cbMove(s);
        }
        if (!(s->flags & 2)) {
            func_002DD128(m);
            m[2][2] = 1.0f;
            m[1][1] = 1.0f;
            m[0][0] = 1.0f;
            func_01B04F68(s, m, 1);
        }
    } else {
        MMI_COPY_LQ_A3(&s->pos, target);
        MMI_COPY_SQ_A3(&s->pos);
        if (s->cbHit != 0) {
            s->cbHit(s);
        }
        if (s->flags & 1) {
            task->unk8->fn = func_01B05C90;
        } else {
            s->flags |= 0x8000;
            func_01B038A0(task);
            return;
        }
    }
    if (s->flags & 1) {
        float sc;
        func_002DD128(m);
        sc = s->scale;
        m[2][2] = sc;
        m[1][1] = sc;
        m[0][0] = sc;
        func_01B051A8(s->unk30, m, &s->pos);
    }
}

void func_01B05C90(Ovl09224Task *task)
{
    float m[4][4];
    register Ovl09224B *s __asm__("$16") = task->arg;

    if (s->unk258 > 0) {
        float sc;
        s->unk258 = (int)(s->unk258 * 0.5f);
        func_002DD128(m);
        sc = s->scale;
        m[2][2] = sc;
        m[1][1] = sc;
        m[0][0] = sc;
        func_01B051A8(s->unk30, m, &s->target);
    } else {
        s->flags |= 0x8000;
        func_01B038A0(task);
    }
}
