#include "vu0.h"

typedef struct {
    u8 *obj;
    float f04;
    float f08;
    u32 u0C;
} Arg10D8;

typedef struct {
    u8 *obj;
    u32 shift;
    u32 set;
} Arg1120;

typedef struct Node1168 Node1168;
struct Node1168 {
    void *vtbl;
    Node1168 *prev;
    Node1168 *next;
    Node1168 *tail;
    Node1168 *head;
    Node1168 *parent;
    u16 count;
    u8 b1A;
    u8 b1B;
    u32 pad1C;
    u8 vec20[0x48];
    float f68;
    float f6C;
    u8 pad70[0x0C];
    u32 w7C;
    u8 pad80[0x0C];
    u32 w8C;
    u8 pad90[0x0C];
    u16 h9C;
    u8 pad9E[0x2E];
    float fCC;
    u8 padD0[0x1C];
    u32 wEC;
    u8 padF0[0x38];
    u32 w128;
    u32 w12C;
    u32 w130;
    void *p134;
    u8 b138;
    u8 b139;
    u8 b13A;
    u8 b13B;
};

typedef struct {
    Node1168 *node;
    Node1168 *parent;
    float f08;
} Arg1168;

extern u8 g_vtable_1168[];
extern void *func_001CEA70(int, int, int);
extern float func_001AA038(void);
extern void func_001D9F08(int);
extern int func_001A9DB8(void *, int);

void func_01B110D8(Arg10D8 *a)
{
    u8 *obj = a->obj;
    if (a->u0C < 2) {
        float cur = *(float *)(obj + 0x68);
        float f04;
        *(float *)(obj + 0xEC) = 1.0f;
        *(float *)(obj + 0xFC) = a->f08;
        f04 = a->f04;
        *(float *)(obj + 0xCC) = f04;
        *(float *)(obj + 0xDC) = cur - f04;
        *(u16 *)(obj + 0x9C) = (u16)a->u0C;
    }
}

void func_01B11120(Arg1120 *a)
{
    u8 *obj = a->obj;
    if (a->set != 0) {
        *(u32 *)(obj + 0x130) |= (1 << a->shift);
    } else {
        *(u32 *)(obj + 0x130) &= ~(1 << a->shift);
    }
}

void func_01B11168(Arg1168 *a)
{
    Node1168 *n = a->node;
    Node1168 *p = a->parent;
    u8 *v;
    float f;

    n->vtbl = g_vtable_1168;
    n->b1A = 0xFF;
    n->head = n;
    n->tail = n;
    n->parent = p;
    n->b1B = 0;
    if (p != 0) {
        n->prev = p;
        n->next = p->head;
        if (p->head == p) {
            p->tail = n;
        } else {
            p->head->prev = n;
        }
        p->head = n;
        p->count++;
    }

    v = n->vec20;
    VU0_SQC2(0, 0x0, v);
    VU0_SQC2(0, 0x10, v);
    VU0_SQC2(0, 0x20, v);
    VU0_SQC2(0, 0x30, v);
    VU0_SQC2(0, 0x40, v);
    VU0_SQC2(0, 0x90, v);
    VU0_SQC2(0, 0xA0, v);
    VU0_SQC2(0, 0xC0, v);

    n->w12C = 0;
    n->w128 = 0;
    n->w130 = 0;
    n->w8C = 0;
    n->w7C = 0;
    n->b13B = 0;
    n->h9C = 0;
    n->p134 = func_001CEA70(1, 0, 7);
    n->f6C = func_001AA038();
    {
        register int arg1 __asm__("$4") = 1;
        int r;
        f = a->f08;
        __asm__("" : "+r"(arg1), "+f"(f) : : "memory");
        n->wEC = 0;
        __asm__("" : : "m"(n->wEC));
        n->fCC = f;
        __asm__("" : : "m"(n->fCC));
        n->f68 = f;
        func_001D9F08(arg1);
        func_001A9DB8(n->p134, 0);
        r = func_001A9DB8(n->p134, 1);
        __asm__("" : : "r"(r));
    }
}
