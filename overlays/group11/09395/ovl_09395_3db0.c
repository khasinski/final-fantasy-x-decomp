#include "common.h"

typedef struct {
    s16 off;
    u16 dur;
    u32 pad4;
} Key3DB0;

typedef struct {
    u8 pad0[4];
    s16 count;
    u8 pad6[10];
    Key3DB0 keys[1];
} Anim3DB0;

typedef struct {
    Anim3DB0 *anim;
    Key3DB0 *cur;
    s16 idx;
    u16 padA;
    void *frame;
    s16 timer;
    u8 pad12[0xE];
    float pos[4];
    float f30;
    float f34;
    s32 r;
    s32 g;
    s32 b;
    float a;
} Obj3DB0;

typedef struct {
    u8 pad0[4];
    u8 r;
    u8 g;
    u8 b;
    u8 a;
    u8 pad8[8];
    void *p10;
    void *p14;
    u32 pad18;
    void *p1C;
} Pkt3DB0;

extern float D_01B05A90[16];
extern float D_01B05AD0[16];
extern float D_01B05B10[16];
extern float D_01B05B50[16];

extern void func_001AACA0(void *);
extern void func_001A9EE0(void *);
extern void func_002DD128(void *);
extern void func_002B57D0(void *, float);
extern void func_002DCE38(void *, void *, void *);
extern void func_002DD1C8(void *, void *, float);
extern void func_002DCE08(void *, void *, void *);
extern void func_002DD0C0(void *, void *);
extern void func_002CD590(void *, void *);

void func_01B03DB0(Obj3DB0 *s4, Pkt3DB0 *s5, void *s6, float f20) {
    float m0[16];
    float m1[16];

    func_001AACA0(m1);
    func_001A9EE0(m0);
    func_002DD128(D_01B05A90);
    func_002DD128(D_01B05B10);
    func_002DD128(D_01B05B50);
    func_002B57D0(D_01B05A90, s4->f30);
    func_002DCE38(D_01B05A90, D_01B05B50, D_01B05A90);
    func_002DD1C8(D_01B05A90, D_01B05A90, s4->f34);
    func_002DCE38(D_01B05A90, D_01B05B10, D_01B05A90);
    func_002DCE08(&D_01B05A90[12], m0, s4->pos);
    func_002DD0C0(D_01B05AD0, D_01B05A90);
    D_01B05AD0[14] -= f20;
    func_002DCE38(D_01B05AD0, m1, D_01B05AD0);
    func_002DCE38(D_01B05A90, m1, D_01B05A90);

    s5->p10 = D_01B05A90;
    s5->p1C = D_01B05AD0;
    s4->timer -= 0x200;
    if (s4->timer == 0) {
        register Anim3DB0 *anim __asm__("$7") = s4->anim;
        register u8 *v0 __asm__("$2");
        register s32 v1 __asm__("$3");
        s4->idx++;
        if (s4->idx >= anim->count) {
            s4->idx = 0;
        }
        v0 = (u8 *)anim + s4->idx * 8;
        v0 += 16;
        v1 = *(s16 *)v0;
        s4->cur = (Key3DB0 *)v0;
        s4->timer += *(volatile u16 *)(v0 + 2);
        s4->frame = (void *)(v1 + (u32)anim);
    }
    s5->r = s4->r;
    s5->p14 = s6;
    s5->g = s4->g;
    s5->b = s4->b;
    s5->a = (s32)(s4->a * 127.0f);
    func_002CD590(s4->frame, s5);
}
