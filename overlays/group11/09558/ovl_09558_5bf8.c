#include "common.h"

typedef struct {
    u8 pad00[0x68];
    void *p68;          /* 0x68 */
    u8 pad6C[0x18];
    float f84;          /* 0x84 */
    float f88;          /* 0x88 */
    float f8C;          /* 0x8C */
    float f90;          /* 0x90 */
    u8 pad94[0x10];
    u16 flagsA4;        /* 0xA4 */
} Node5BF8;

extern void func_01B06FE0(void *);

void func_01B05BF8(Node5BF8 **arg)
{
    Node5BF8 *n = *arg;
    struct {
        void *a;
        int b;
    } p;

    p.a = n->p68;
    p.b = 1;
    func_01B06FE0(&p);
    n->flagsA4 |= 0x10;
}

void func_01B05C40(void *arg)
{
    struct {
        Node5BF8 *n;
        float a;
        float b;
        float c;
        float d;
    } *p = arg;
    Node5BF8 *n = p->n;

    n->f88 = p->a;
    n->flagsA4 |= 4;
    n->f84 = p->b;
    n->f8C = p->c;
    n->f90 = p->d;
}
