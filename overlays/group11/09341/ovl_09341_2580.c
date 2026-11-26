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
    u8 pad1C[0x110];
    void *p12C;
    u8 pad130[0x10];
    void *w140;
    float w144;
    void *w148;
    u8 b14C;
    u8 pad14D[3];
    void *p150;
};

typedef struct {
    Node *obj;
    Node *parent;
    void *p08;
} Arg2580;

extern u32 D_01B00790;
extern u32 D_01B01490;

void ovl_09341_2580(Arg2580 *a)
{
    Node *a2 = a->obj;
    Node *v1 = a->parent;

    a2->b1A = 0xFF;
    a2->head = a2;
    a2->tail = a2;
    a2->parent = v1;
    a2->b1B = 0;
    if (v1 != 0) {
        a2->prev = v1;
        a2->next = v1->head;
        if (v1->head == v1) {
            v1->tail = a2;
        } else {
            v1->head->prev = a2;
        }
        v1->head = a2;
        v1->h18++;
    }
    {
        void *p08 = a->p08;
        register u32 *r790 __asm__("$3") = &D_01B00790;
        register u32 *r1490 __asm__("$2") = &D_01B01490;
        a2->b14C = 0;
        __asm__("" : "+r"(r790), "+r"(r1490));
        a2->p12C = r790;
        a->obj->vtable = r1490;
        a2->p150 = p08;
        __asm__ __volatile__("");
        a2->w140 = 0;
        __asm__ __volatile__("");
        a2->w148 = 0;
        __asm__ __volatile__("");
        a2->w144 = 0.0f;
    }
}
