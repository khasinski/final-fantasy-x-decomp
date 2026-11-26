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
    void *w90;
    float f94;
    void *w98;
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
} Arg2A40;

extern u32 D_01B01508;

void ovl_09341_2a40(Arg2A40 *a)
{
    Node *a2 = a->obj;
    Node *a1 = a->parent;

    a2->vtable = &D_01B01508;
    a2->b1A = 0xFF;
    a2->head = a2;
    a2->tail = a2;
    a2->parent = a1;
    a2->b1B = 0;
    if (a1 != 0) {
        a2->prev = a1;
        a2->next = a1->head;
        if (a1->head == a1) {
            a1->tail = a2;
        } else {
            a1->head->prev = a2;
        }
        a1->head = a2;
        a1->h18++;
    }
    {
        void *p08 = a->p08;
        u32 p0C = a->p0C;
        a2->hB4 = 2;
        a2->p88 = p08;
        a2->p8C = p0C;
        a2->hBA = 1800;
        a2->f94 = 20000.0f;
        a2->hB6 = 0;
        __asm__ __volatile__("");
        a2->w90 = 0;
        __asm__ __volatile__("");
        a2->w98 = 0;
    }
}
