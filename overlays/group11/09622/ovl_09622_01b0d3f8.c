#include "common.h"

typedef struct OvlNodeD3F8 OvlNodeD3F8;

struct OvlNodeD3F8 {
    void *vtable;
    OvlNodeD3F8 *prev;
    OvlNodeD3F8 *next;
    OvlNodeD3F8 *tail;
    OvlNodeD3F8 *head;
    OvlNodeD3F8 *parent;
    u16 child_count;
    u8 flag1A;
    u8 flag1B;
    u8 pad1C[0x24];
    void *p40;
    void *p44;
};

typedef struct {
    OvlNodeD3F8 *node;
    OvlNodeD3F8 *parent;
    void *p40;
    void *p44;
} InitArgsD3F8;

extern u8 g_vtable_d3f8[];

void ovl_09622_d3f8(InitArgsD3F8 *args)
{
    OvlNodeD3F8 *node = args->node;
    OvlNodeD3F8 *parent = args->parent;

    node->vtable = g_vtable_d3f8;
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
        register void *p44 __asm__("$2") = args->p44;
        register void *p40 __asm__("$3");
        __asm__ volatile("" : "+r"(p44));
        p40 = args->p40;
        __asm__ volatile("" : "+r"(p40));
        node->p44 = p44;
        __asm__ volatile("" : : "m"(node->p44));
        node->p40 = p40;
    }
}
