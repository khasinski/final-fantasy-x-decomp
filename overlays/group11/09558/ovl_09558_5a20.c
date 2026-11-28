#include "common.h"

typedef struct Node5A20 Node5A20;

typedef struct {
    u8 pad00[0x1C];
    void (*fn1C)(void *);
} Vtbl5A20;

struct Node5A20 {
    Vtbl5A20 *vtbl;
    Node5A20 *prev;
    Node5A20 *next;
    Node5A20 *tail;
    Node5A20 *head;
    Node5A20 *parent;
    u16 nchild;
    u8 b1A;
    u8 b1B;
    u8 *p1C;
    u8 *p20;
    u32 w24;
};

typedef struct {
    Node5A20 *node;
    u8 flag4;
    u8 stamp5;
} Ctx5A20;

typedef struct {
    s32 w00;
    void *p04;
    u16 h08;
    u16 pad0A;
    s32 w0C;
    unsigned long d10;
    u32 w18;
    s32 w1C;
    void *p20;
    void *p24;
    void *p28;
    void *p2C;
    u32 pad30;
    void *p34;
    void *p38;
    void *p3C;
    s32 w40;
    s32 w44;
    u8 pad48[0x28];
} Pkt5A20;

extern void *D_00303550;
extern void *D_01B00048;
extern u8 D_01B00B40[];

extern void func_002DCE38(void *, void *, void *);
extern void *func_002B7B20(void *, void *);

void func_01B05A20(Ctx5A20 *s1) {
    float mat[16];
    Pkt5A20 pkt;
    Node5A20 *s2 = s1->node;

    if (s2->b1A == s1->stamp5) {
        s1->flag4 = 0;
    } else {
        Node5A20 *s0 = s2->head;
        while (s0 != s2) {
            s1->node = s0;
            s0 = s0->next;
            s1->node->vtbl->fn1C(s1);
        }
        s1->node = s2;
        s2->b1A = s1->stamp5;
        s1->flag4 = 1;
    }

    if (s1->flag4 & 1) {
        Node5A20 *t0 = s1->node;
        u8 *s0 = t0->p20;

        pkt.w00 = 0x1C;
        pkt.w1C = 0;
        pkt.p38 = s0 + *(s32 *)(s0 + 8);
        pkt.h08 = *(u16 *)(s0 + 0x16);
        pkt.p3C = s0 + *(s32 *)(s0 + 0xC);
        pkt.w0C = 0;
        pkt.p04 = D_00303550;
        pkt.w18 = t0->w24;
        pkt.d10 = 0;
        pkt.w40 = 0;
        func_002DCE38(mat, D_01B00B40, t0->p1C + 0xA0);

        pkt.p20 = mat;
        pkt.p34 = D_01B00048;
        pkt.w44 = 0;
        pkt.p24 = mat;
        pkt.p28 = mat;
        pkt.p2C = mat;
        D_01B00048 = func_002B7B20(s0, &pkt);
    }
}
