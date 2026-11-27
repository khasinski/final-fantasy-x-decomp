#include "common.h"

typedef struct OvlNodeDA18 OvlNodeDA18;

struct OvlNodeDA18 {
    void *vtable;
    OvlNodeDA18 *prev;
    OvlNodeDA18 *next;
    OvlNodeDA18 *tail;
    OvlNodeDA18 *head;
    OvlNodeDA18 *parent;
    u16 child_count;
    u8 flag1A;
    u8 flag1B;
    u8 pad1C[0x10];
    float f2C;
    void *p30;
    u32 pad34;
    int w38;
};

typedef struct {
    OvlNodeDA18 *node;
    OvlNodeDA18 *parent;
    void *p30;
} InitArgsDA18;

extern u8 g_vtable_da18[];

void ovl_09622_da18(InitArgsDA18 *args)
{
    register InitArgsDA18 *a __asm__("$3") = args;
    register OvlNodeDA18 *node __asm__("$4");
    OvlNodeDA18 *parent;
    void *p30;

    __asm__("" : "+r"(a));
    node = a->node;
    __asm__("" : "+r"(node));
    parent = a->parent;

    node->flag1A = 0xFF;
    node->head = node;
    node->tail = node;
    node->parent = parent;
    node->flag1B = 0;

    if (parent != 0) {
        node->prev = parent;
        node->next = parent->head;
        if (parent->head == parent) {
            parent->tail = node;
        } else {
            parent->head->prev = node;
        }
        parent->head = node;
        parent->child_count++;
    }

    {
        register void *p30r __asm__("$4") = a->p30;
        register OvlNodeDA18 *n2 __asm__("$3") = a->node;
        __asm__("" : "+r"(p30r), "+r"(n2));
        n2->vtable = g_vtable_da18;
        n2->p30 = p30r;
        n2->f2C = 1.0f;
        n2->w38 = 0;
    }
}
