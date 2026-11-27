#include "common.h"

extern u8 D_01B05170[];
extern s32 func_001CEA70(s32, s32, s32);
extern float func_001AA038(void);
extern int func_001A9DB8(s32, s32);

typedef struct Node {
    void *vtable;
    struct Node *prev;
    struct Node *next;
    struct Node *first_child;
    struct Node *last_child;
    struct Node *parent;
    u16 child_count;
    u8 flags1A;
    u8 flags1B;
} Node;

typedef struct {
    u8 *obj;
    Node *parent;
    float f8;
} ArgC270;

#define ZERO_VF0(p, off) __asm__ volatile("sqc2 $vf0, " #off "(%0)" : : "r"(p) : "memory")

void func_01B0C270(ArgC270 *arg) {
    Node *s0 = (Node *)arg->obj;
    Node *parent = arg->parent;
    u8 *p;
    float f;

    s0->vtable = D_01B05170;
    s0->flags1A = 0xFF;
    s0->last_child = s0;
    s0->first_child = s0;
    s0->parent = parent;
    s0->flags1B = 0;

    if (parent != 0) {
        s0->prev = parent;
        s0->next = parent->last_child;
        if (parent->last_child == parent) {
            parent->first_child = s0;
        } else {
            parent->last_child->prev = s0;
        }
        parent->last_child = s0;
        parent->child_count++;
    }

    p = (u8 *)s0 + 0x20;
    ZERO_VF0(p, 0x0);
    ZERO_VF0(p, 0x10);
    ZERO_VF0(p, 0x20);
    ZERO_VF0(p, 0x30);
    ZERO_VF0(p, 0x40);
    ZERO_VF0(p, 0x90);
    ZERO_VF0(p, 0xA0);
    ZERO_VF0(p, 0xC0);

    *(u32 *)((u8 *)s0 + 0x12C) = 0;
    *(u32 *)((u8 *)s0 + 0x128) = 0;
    *(u32 *)((u8 *)s0 + 0x130) = 0;
    *(u32 *)((u8 *)s0 + 0x8C) = 0;
    *(u32 *)((u8 *)s0 + 0x7C) = 0;
    *((u8 *)s0 + 0x13B) = 0;
    *(u16 *)((u8 *)s0 + 0x9C) = 0;

    *(s32 *)((u8 *)s0 + 0x134) = func_001CEA70(1, 0, 7);
    *(float *)((u8 *)s0 + 0x6C) = func_001AA038();

    {
        register int a1 __asm__("$5") = 0;
        register s32 a0 __asm__("$4") = *(s32 *)((u8 *)s0 + 0x134);
        int r;
        f = arg->f8;
        __asm__("" : "+r"(a1), "+r"(a0), "+f"(f) : : "memory");
        *(u32 *)((u8 *)s0 + 0xEC) = 0;
        __asm__("" : : "m"(*(u32 *)((u8 *)s0 + 0xEC)));
        *(float *)((u8 *)s0 + 0xCC) = f;
        __asm__("" : : "m"(*(float *)((u8 *)s0 + 0xCC)));
        *(float *)((u8 *)s0 + 0x68) = f;
        func_001A9DB8(a0, a1);
        r = func_001A9DB8(*(s32 *)((u8 *)s0 + 0x134), 1);
        __asm__("" : : "r"(r));
    }
}
