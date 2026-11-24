#include "common.h"

typedef struct OvlNodeB OvlNodeB;

struct OvlNodeB {
    void *vtable;
    OvlNodeB *prev;
    OvlNodeB *next;
    OvlNodeB *tail;
    OvlNodeB *head;
    OvlNodeB *parent;
    u16 child_count;
    u8 flag1A;
    u8 flag1B;
    u32 pad1C;
    float f20;
    float f24;
    float f28;
    float f2C;
    u8 data30[0x10];
    void *p40;
    void *p44;
    void *p48;
    void *p4C;
    void *p50;
    u8 flag54;
};

typedef struct {
    OvlNodeB *node;
    OvlNodeB *parent;
    void *p4C;
    void *p44;
    void *p50;
    void *p40;
    void *p48;
} InitArgsB;

extern u8 g_vtable_a598[];
extern int func_00282478(void *);

void ovl_09217_a598(InitArgsB *args)
{
    register InitArgsB *ap __asm__("$6") = args;
    register OvlNodeB *node __asm__("$8") = ap->node;
    OvlNodeB *parent = ap->parent;
    void *p40;
    void *p4C;
    void *p44;
    void *p48;
    void *p50;
    int r;

    node->vtable = g_vtable_a598;
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
        register void *p40r __asm__("$7") = ap->p40;
        register void *d30 __asm__("$4") = node->data30;
        __asm__("" : "+r"(p40r), "+r"(d30));
        {
            register void *p4Cr __asm__("$2") = ap->p4C;
            __asm__("" : "+r"(p4Cr));
            {
                register void *p44r __asm__("$3") = ap->p44;
                register void *p48r __asm__("$5") = ap->p48;
                register float one __asm__("$f0") = 1.0f;
                __asm__("" : "+r"(ap), "+r"(p44r), "+r"(p48r), "+f"(one));
                {
                    register void *p50r __asm__("$6") = ap->p50;
                    __asm__("" : "+r"(p50r));
                    node->p4C = p4Cr;
                    __asm__("" : : "m"(node->p4C));
                    node->p44 = p44r;
                    node->p48 = p48r;
                    node->p50 = p50r;
                    node->p40 = p40r;
                    node->f20 = one;
                    node->flag54 = 0;
                    __asm__("" : : "m"(node->flag54));
                    node->f2C = one;
                    node->f28 = one;
                    __asm__("" : : "m"(node->f28));
                    node->f24 = one;
                }
            }
        }
        r = func_00282478(d30);
        __asm__("" : : "r"(r));
    }
}
