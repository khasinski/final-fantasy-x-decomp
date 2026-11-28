#include "common.h"

typedef struct SubAd28 {
    u8 pad0[0x54];
    s32 f54;
    s32 f58;
} SubAd28;

typedef struct NodeAd28 {
    void *vtbl;
    struct NodeAd28 *prev;
    struct NodeAd28 *next;
    struct NodeAd28 *tail;
    struct NodeAd28 *head;
    struct NodeAd28 *parent;
    u16 child_count;
    u8 flag_1a;
    u8 flag_1b;
    void *f1C;
    u16 f20;
    u16 f22;
    u16 f24;
    u16 f26;
    u16 f28;
    u8 pad2A[0xB6];
    void *fE0;
    void *fE4;
    s32 fE8;
    s32 fEC;
    u16 fF0;
    u16 fF2;
    SubAd28 *fF4;
    u32 fF8;
    u32 padFC;
    void *f100;
} NodeAd28;

typedef struct {
    NodeAd28 *obj;
    NodeAd28 *parent;
    void *f08;
    u16 f0C;
    u16 f0E;
    void *f10;
    void *f14;
    SubAd28 *f18;
    void *f1C;
} ArgAd28;

extern u8 g_vtbl_ad28[];
extern u32 func_001B4E18(s32);
extern void func_002A7308(void *, s32, s32, s32);

void ovl_09194_01b0ad28(ArgAd28 *a0) {
    NodeAd28 *n = a0->obj;
    NodeAd28 *p = a0->parent;
    NodeAd28 *cur;
    u32 id;

    n->flag_1a = 0xFF;
    n->head = n;
    n->tail = n;
    n->parent = p;
    n->flag_1b = 0;
    if (p != 0) {
        n->prev = p;
        n->next = p->head;
        if (p->head == p) {
            p->tail = n;
        } else {
            p->head->prev = n;
        }
        p->head = n;
        p->child_count++;
    }

    {
        register u16 c __asm__("$5") = a0->f0C;
        register u16 one __asm__("$7") = 1;
        register NodeAd28 *v0 __asm__("$2") = a0->obj;
        register void *v1 __asm__("$3") = a0->f10;
        v0->f20 = c;
        {
            register void *f8 __asm__("$4") = a0->f08;
            register u16 e __asm__("$5");
            register SubAd28 *a2 __asm__("$6");
            __asm__ volatile("" : : "r"(f8), "r"(v1), "r"(v0) : "memory");
            e = a0->f0E;
            __asm__ volatile("" : : "r"(e), "r"(v1), "r"(f8), "r"(v0) : "memory");
            n->fE0 = v1;
            a2 = a0->f18;
            __asm__ volatile("" : : "r"(e), "r"(a2), "r"(f8), "r"(v0) : "memory");
            v0->f1C = f8;
            v0->f22 = e;
            v0->f24 = 0;
            v0->f28 = 0;
            __asm__ volatile("" : : "r"(v0), "r"(a2), "r"(one) : "memory");
            v0->f26 = 0;
            {
                register void *f14 __asm__("$3") = a0->f14;
                register s32 arg0 __asm__("$4");
                __asm__ volatile("" : : "r"(f14), "r"(a2), "r"(one) : "memory");
                arg0 = a2->f54;
                n->fE8 = 0;
                n->f28 = 0;
                n->f26 = 0;
                n->fF0 = 0;
                n->fEC = 0;
                n->fE4 = f14;
                n->fF2 = one;
                n->fF4 = a2;
                id = func_001B4E18(arg0);
            }
        }
    }
    n->fF8 = id;
    n->f100 = a0->f1C;

    switch (id) {
    case 0x1071:
    case 0x1088:
    case 0x1089:
    case 0x108C:
        func_002A7308(n->f100, n->fF4->f58, 0, 0);
        break;
    default:
        n->f100 = 0;
        break;
    }

    a0->obj->vtbl = g_vtbl_ad28;
}
