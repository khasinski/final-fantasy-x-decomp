#include "common.h"

typedef struct NodeA078 {
    void *vtbl;
    struct NodeA078 *prev;
    struct NodeA078 *next;
    struct NodeA078 *tail;
    struct NodeA078 *head;
    struct NodeA078 *parent;
    u16 child_count;
    u8 flag_1a;
    u8 flag_1b;
    u8 pad1C[0x904];
    void *f920;
    void *f924;
    void *f928;
    void *f92C;
    void *f930;
    float f934;
    float f938;
    u8 f93C;
    u8 f93D;
    u16 pad93E;
    void *f940;
    s32 f944;
    s32 f948;
    u32 f94C;
    u32 f950;
} NodeA078;

typedef struct {
    NodeA078 *obj;
    NodeA078 *parent;
    void *f08;
    void *f0C;
    void *f10;
    void *f14;
    void *f18;
    s32 f1C;
} ArgA078;

extern u8 g_vtbl_a078[];
extern void fn_01b09900(void);
extern void fn_01b09360(void);
extern s32 func_002B2E10(void (*)(void), void *, s32, s32);

void ovl_09194_01b0a078(ArgA078 *a0) {
    NodeA078 *n = a0->obj;
    NodeA078 *p = a0->parent;

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
        register void *f08 __asm__("$2") = a0->f08;
        register void (*fn0)(void) __asm__("$4") = fn_01b09900;
        register void *t1 __asm__("$9") = a0->f0C;
        register void *a1 __asm__("$5");
        register void *t0 __asm__("$8");
        register s32 a2 __asm__("$6");
        register void *v1 __asm__("$3");
        register s32 a3 __asm__("$7");
        n->f920 = f08;
        __asm__ volatile("" : : "r"(fn0), "r"(t1) : "memory");
        a1 = n;
        __asm__ volatile("" : : "r"(a1));
        t0 = a0->f14;
        a2 = 0;
        __asm__ volatile("" : : "r"(a2));
        v1 = a0->f10;
        a3 = 0;
        n->f93D = 0;
        n->f93C = 0;
        __asm__ volatile("" : : "r"(fn0), "r"(a1), "r"(a2), "r"(a3), "r"(t1), "r"(t0), "r"(v1) : "memory");
        {
            register float f0 __asm__("$f0") = 1.0f;
            void *f18;
            __asm__ volatile("" : : "f"(f0) : "memory");
            f18 = a0->f18;
            n->f924 = t1;
            n->f928 = v1;
            n->f92C = t0;
            n->f938 = f0;
            __asm__ volatile("" : : "f"(f0), "r"(f18) : "memory");
            n->f930 = f18;
            __asm__ volatile("" : : "f"(f0), "r"(fn0), "r"(a1), "r"(a2), "r"(a3) : "memory");
            n->f934 = f0;
        }
        n->f940 = (void *)func_002B2E10(fn0, a1, a2, a3);
    }
    n->f944 = func_002B2E10(fn_01b09360, n, 0, 0);
    if ((n->f948 = a0->f1C) != 0) {
        n->f94C = 0x008080F0;
        n->f950 = 0x00202020;
    } else {
        n->f94C = 0x28;
        n->f950 = 0x32;
    }
    a0->obj->vtbl = g_vtbl_a078;
}
