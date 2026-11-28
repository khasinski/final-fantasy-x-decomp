#include "common.h"

extern void *D_01B0ADC0[];

typedef struct Node10060 {
    void *vtable;
    struct Node10060 *prev;
    struct Node10060 *next;
    struct Node10060 *tail;
    struct Node10060 *head;
    struct Node10060 *parent;
    u16 child_count;
    u8 flag_1a;
    u8 flag_1b;
    u8 pad1C[8];
    int f24;
} Node10060;

typedef struct {
    Node10060 *obj;
    Node10060 *parent;
} Arg10060;

void func_01B10060(Arg10060 *a0)
{
    Node10060 *a1 = a0->obj;
    Node10060 *a2 = a0->parent;

    a1->vtable = D_01B0ADC0;
    a1->flag_1a = 0xFF;
    a1->head = a1;
    a1->tail = a1;
    a1->parent = a2;
    a1->flag_1b = 0;

    if (a2 != 0) {
        a1->prev = a2;
        a1->next = a2->head;
        if (a2->head == a2) {
            a2->tail = a1;
        } else {
            a2->head->prev = a1;
        }
        a2->head = a1;
        a2->child_count += 1;
    }

    a0->obj->f24 = 0;
}
