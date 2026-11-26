#include "common.h"

typedef struct Node Node;
struct Node {
    void *vtable;
    Node *prev;
    Node *next;
    Node *tail;
    Node *head;
    Node *parent;
    u16 h18;
    u8 b1A;
    u8 b1B;
    u8 pad1C[0x6C];
    void *p88;
    u32 p8C;
    u32 w90;
    float f94;
    float f98;
    u8 pad9C[0x18];
    u16 hB4;
    u16 hB6;
    u16 hB8;
    u16 hBA;
};

typedef struct {
    Node *obj;
    Node *parent;
    void *p08;
    u32 p0C;
} Arg4AA8;

typedef struct {
    void *p00;
    s32 w04;
} Call5C58;

extern u32 D_01B02E00;
extern void func_1B05C58(Call5C58 *);

void ovl_09470_4aa8(Arg4AA8 *a)
{
    Node *a3 = a->obj;
    Node *a1 = a->parent;
    void *p08;
    u32 p0C;
    Call5C58 c;

    a3->vtable = &D_01B02E00;
    a3->b1A = 0xFF;
    a3->head = a3;
    a3->tail = a3;
    a3->parent = a1;
    a3->b1B = 0;
    if (a1 != 0) {
        a3->prev = a1;
        a3->next = a1->head;
        if (a1->head == a1) {
            a1->tail = a3;
        } else {
            a1->head->prev = a3;
        }
        a1->head = a3;
        a1->h18++;
    }
    {
        register u32 r5 __asm__("$5") = a->p0C;
        register u16 r2 __asm__("$2") = 2;
        register float f0 __asm__("$f0") = 20000.0f;
        register u16 r3 __asm__("$3");
        register void *r6 __asm__("$6");
        register Call5C58 *ca0 __asm__("$4");
        __asm__ __volatile__("" : "+r"(r5), "+r"(r2), "+f"(f0));
        r3 = 1;
        __asm__ __volatile__("" : "+r"(r3));
        r6 = a->p08;
        a3->hB4 = r2;
        __asm__ __volatile__("");
        ca0 = &c;
        __asm__ __volatile__("" : "+r"(ca0));
        a3->p8C = r5;
        a3->hBA = r3;
        a3->f94 = f0;
        a3->hB6 = 0;
        __asm__ __volatile__("" : "+r"(r6));
        c.p00 = r6;
        a3->w90 = 0;
        a3->p88 = r6;
        a3->f98 = 0.0f;
        c.w04 = 0;
        func_1B05C58(ca0);
    }
}
