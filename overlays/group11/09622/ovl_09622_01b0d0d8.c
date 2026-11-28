#include "common.h"

typedef struct NodeD0D8 {
    void *vtable;           /* 0x00 */
    struct NodeD0D8 *prev;  /* 0x04 */
    struct NodeD0D8 *next;  /* 0x08 */
    struct NodeD0D8 *tail;  /* 0x0C */
    struct NodeD0D8 *head;  /* 0x10 */
    struct NodeD0D8 *parent;/* 0x14 */
    u16 count;              /* 0x18 */
    u8 flag1A;              /* 0x1A */
    u8 flag1B;              /* 0x1B */
    u8 pad1C[4];
    u8 mat20[0x48];         /* 0x20 */
    void *f68;              /* 0x68 */
    void *f6C;              /* 0x6C */
    void *f70;              /* 0x70 */
    int f74;                /* 0x74 */
    u32 f78;                /* 0x78 */
    float f7C;              /* 0x7C */
    int f80;                /* 0x80 */
    u8 pad84[0x14];
    int f98;                /* 0x98 */
    int f9C;                /* 0x9C */
    u8 padA0[4];
    u16 fA4;                /* 0xA4 */
    u16 fA6;                /* 0xA6 */
    u16 fA8;                /* 0xA8 */
    u16 fAA;                /* 0xAA */
} NodeD0D8;

typedef struct ArgD0D8 {
    NodeD0D8 *node;
    NodeD0D8 *parent;
    void *f8;
    void *fC;
    void *f10;
} ArgD0D8;

extern u8 D_01B0A770[];
extern void func_002DD128(void *);

void func_01B0D0D8(ArgD0D8 *a0)
{
    NodeD0D8 *s0 = a0->node;
    NodeD0D8 *parent = a0->parent;

    s0->vtable = D_01B0A770;
    s0->flag1A = 0xFF;
    s0->head = s0;
    s0->tail = s0;
    s0->parent = parent;
    s0->flag1B = 0;
    if (parent != 0) {
        s0->prev = parent;
        s0->next = parent->head;
        if (parent->head == parent) {
            parent->tail = s0;
        } else {
            parent->head->prev = s0;
        }
        parent->head = s0;
        parent->count += 1;
    }

    func_002DD128(s0->mat20);
    {
        register void *p10 __asm__("$3") = a0->f10;
        register void *p8 __asm__("$5") = a0->f8;
        register void *pC __asm__("$7") = a0->fC;
        s0->f70 = p10;
        s0->fA4 = 2;
        s0->f68 = p8;
        s0->f6C = pC;
        s0->fAA = 1;
        s0->f78 = 0x80808080;
        s0->f7C = 20000.0f;
        s0->f74 = 0;
        s0->f80 = 0;
        s0->f98 = 0;
        s0->f9C = 0;
        s0->fA6 = 0;
    }
}
