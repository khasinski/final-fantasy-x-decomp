#include "common.h"

typedef struct Node Node;
typedef struct TravArg TravArg;

typedef struct {
    u8 pad00[0x1C];
    void (*fn1C)(TravArg *);
} VTable;

typedef union {
    float v[4];
    u_long128 q;
} Vec128;

struct Node {
    VTable *vtable;
    Node *prev;
    Node *next;
    Node *tail;
    Node *head;
    Node *parent;
    u16 h18;
    u8 b1A;
    u8 b1B;
    u8 pad1C[4];
    float mat20[3][4];
    float vec50[4];
    float mat60[4][4];
    float matA0[4][4];
    float matE0[4][4];
    Vec128 vec120;
    float vec130[4];
    u8 pad140[0xC];
    u8 b14C;
    u8 pad14D[3];
    Node *p150;
};

struct TravArg {
    Node *node;
    u8 b04;
    u8 b05;
};

typedef struct {
    void *p00;
    void *p04;
} Call2;

typedef void (*RotFn)(float (*)[4], float *);

extern void func_1B04FB0(Call2 *);
extern void func_1B04C68(Call2 *);
extern void func_002DD068(float *, float *, float);
extern void func_002DD0B0(float *, void *);
extern void func_002DD0C0(float (*)[4], float (*)[4]);

extern RotFn D_01B01688[];
extern u8 D_01B00750;

void ovl_09341_2610(TravArg *s1)
{
    Node *s4 = s1->node;

    if (s4->b1A == s1->b05) {
        s1->b04 = 0;
    } else {
        Node *s0 = s4->head;
        while (s0 != s4) {
            s1->node = s0;
            s0 = s0->next;
            s1->node->vtable->fn1C(s1);
        }
        s1->node = s4;
        s4->b1A = s1->b05;
        s1->b04 = 1;
    }

    if (s1->b04 & 1) {
        u8 pad00[0x10];
        Vec128 vec10;
        TravArg ta;
        Call2 c;
        register Call2 *cp __asm__("$17");
        register float (*m60)[4] __asm__("$18");
        register Node *a1 __asm__("$5");

        {
            u8 b05 = s1->b05;
            a1 = s4->p150;
            __asm__("" : "+r"(a1));
            m60 = s4->mat60;
            ta.b05 = b05;
            ta.node = a1;
            {
                register VTable *vt __asm__("$2") = a1->vtable;
                vt->fn1C(&ta);
            }
        }

        cp = &c;
        {
            register Node *v0 __asm__("$2") = s4->p150;
            cp->p00 = v0;
        }
        cp->p04 = vec10.v;
        func_1B04FB0(cp);

        vec10.v[2] = 0.0f;
        vec10.v[0] = 0.0f;
        D_01B01688[s4->b14C](m60, vec10.v);

        func_002DD068(s4->mat20[0], m60[0], 0.001f);
        func_002DD068(s4->mat20[1], s4->mat60[1], 0.001f);
        func_002DD068(s4->mat20[2], s4->mat60[2], 0.001f);

        {
            register Node *v1 __asm__("$3") = s4->p150;
            c.p04 = s4->vec50;
            c.p00 = v1;
        }
        func_1B04C68(cp);

        s4->vec120.q = vec10.q;
        s4->vec50[3] = 1.0f;
        func_002DD0B0(s4->vec130, &D_01B00750);
        s4->vec130[3] *= 1000.0f;
        func_002DD0C0(s4->matE0, m60);
        func_002DD0C0(s4->matA0, (float (*)[4])s4->mat20);
    }
}
