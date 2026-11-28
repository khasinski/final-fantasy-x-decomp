#include "common.h"

extern void *D_01B19A00[];

typedef struct Node20038 {
    void *vtable;
    struct Node20038 *prev;
    struct Node20038 *next;
    struct Node20038 *tail;
    struct Node20038 *head;
    struct Node20038 *parent;
    u16 child_count;
    u8 flag_1a;
    u8 flag_1b;
    u8 pad1C[0x3C4];
    void *f3E0;
    float f3E4;
    float f3E8;
    u8 f3EC;
    u8 pad3ED[3];
    void *f3F0;
    int f3F4;
    int f3F8;
    int f3FC;
} Node20038;

typedef struct {
    Node20038 *obj;
    Node20038 *parent;
    void *f08;
    void *f0C;
} Arg20038;

void func_01B20038(Arg20038 *a0)
{
    Node20038 *a2 = a0->obj;
    Node20038 *v1 = a0->parent;

    a2->flag_1a = 0xFF;
    a2->head = a2;
    a2->tail = a2;
    a2->parent = v1;
    a2->flag_1b = 0;

    if (v1 != 0) {
        a2->prev = v1;
        a2->next = v1->head;
        if (v1->head == v1) {
            v1->tail = a2;
        } else {
            v1->head->prev = a2;
        }
        v1->head = a2;
        v1->child_count += 1;
    }

    {
        void *f08 = a0->f08;
        Node20038 *v1p;
        void *f0C;
        a2->f3EC = 0;
        v1p = a0->obj;
        f0C = a0->f0C;
        v1p->vtable = D_01B19A00;
        a2->f3F0 = f0C;
        a2->f3E0 = f08;
    }
    a2->f3E4 = 1.0f;
    a2->f3E8 = 1.0f;
    __asm__ volatile("");
    a2->f3F4 = 0;
    a2->f3F8 = 0;
    __asm__ volatile("");
    a2->f3FC = 0;
}
