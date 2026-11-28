#include "common.h"

extern u8 D_01B02020[];

typedef struct Node4DC8 {
    void *vtable;
    struct Node4DC8 *next;
    struct Node4DC8 *prev;
    struct Node4DC8 *head;
    struct Node4DC8 *tail;
    struct Node4DC8 *parent;
    u16 count;
    u8 f1A;
    u8 f1B;
    s32 f1C;
    s32 f20;
    s32 f24;
} Node4DC8;

typedef struct {
    Node4DC8 *node;
    Node4DC8 *parent;
    s32 f8;
    s32 fC;
    s32 f10;
} Arg4DC8;

void func_01B04DC8(Arg4DC8 *arg) {
    Node4DC8 *node = arg->node;
    Node4DC8 *parent = arg->parent;
    s32 a, b, c;

    node->vtable = D_01B02020;
    node->f1A = 0xFF;
    node->tail = node;
    node->head = node;
    node->parent = parent;
    node->f1B = 0;
    if (parent != 0) {
        node->next = parent;
        node->prev = parent->tail;
        if (parent->tail == parent) {
            parent->head = node;
        } else {
            parent->tail->next = node;
        }
        parent->tail = node;
        parent->count++;
    }
    a = arg->f8;
    b = arg->fC;
    c = arg->f10;
    node->f1C = a;
    node->f20 = b;
    node->f24 = c;
}
