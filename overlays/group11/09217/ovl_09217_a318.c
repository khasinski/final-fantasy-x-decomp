#include "common.h"

typedef struct OvlNodeA OvlNodeA;

struct OvlNodeA {
    void *vtable;
    OvlNodeA *prev;
    OvlNodeA *next;
    OvlNodeA *tail;
    OvlNodeA *head;
    OvlNodeA *parent;
    u16 child_count;
    u8 flag1A;
    u8 flag1B;
    u32 pad1C;
    float f20[4];
    u8 pad30[0x0C];
    void *p3C;
    OvlNodeA *p40;
    OvlNodeA *p44;
};

typedef struct {
    OvlNodeA *node;
    OvlNodeA *parent;
    OvlNodeA *p40;
    OvlNodeA *p44;
} InitArgsA;

extern u8 g_vtable_a318[];

void ovl_09217_a318(InitArgsA *args)
{
    OvlNodeA *node = args->node;
    OvlNodeA *parent = args->parent;
    OvlNodeA *p44;

    node->vtable = g_vtable_a318;
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
        register OvlNodeA *p44r __asm__("$3") = args->p44;
        OvlNodeA *p40;
        __asm__("" : "+r"(p44r));
        p40 = args->p40;
        node->p44 = p44r;
        node->p40 = p40;
        if (p44r != 0) {
            register void *p3c __asm__("$2") = p44r->f20;
            __asm__("" : "+r"(p3c));
            node->p3C = p3c;
            return;
        }
        __asm__("" : "+r"(p44r));
        node->p3C = 0;
    }
}
