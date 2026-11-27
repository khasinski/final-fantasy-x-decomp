#include "p6_overlay.h"
#include "vu0.h"

extern P6NodeVt D_01B057B0;
extern void func_01B11310(void *);
extern void func_01B0F5A0(void *);
extern void func_01B0A740(void *);
extern void func_001D9F08(int);
extern int func_001A6738(int);

typedef struct {
    P6Node node;        /* 0x000 */
    u8 pad01C[0x110];
    void *p12C;         /* 0x12C */
    u8 pad130[0x10];
    void *p140;         /* 0x140 */
    void *p144;         /* 0x144 */
    void *p148;         /* 0x148 */
    u8 b14C;            /* 0x14C */
    u8 pad14D[0x13];
    s32 w160;           /* 0x160 */
    s32 w164;           /* 0x164 */
    s32 w168;           /* 0x168 */
    s32 w16C;           /* 0x16C */
    u8 pad170[4];
    s32 w174;           /* 0x174 */
    u8 pad178[4];
    u8 b17C;            /* 0x17C */
    u8 pad17D[3];
    u8 x180[0x20];      /* 0x180 */
    u8 x1A0[0x10];      /* 0x1A0 */
    u8 x1B0[0x20];      /* 0x1B0 */
    u8 x1D0[0x10];      /* 0x1D0 */
    u8 x1E0[0x20];      /* 0x1E0 */
    u8 x200[0x10];      /* 0x200 */
} ObjA180;

typedef struct {
    ObjA180 *obj;       /* 0x00 */
    P6Node *parent;     /* 0x04 */
    void *p08;          /* 0x08 */
    void *p0C;          /* 0x0C */
    void *p10;          /* 0x10 */
    void *p14;          /* 0x14 */
    s32 w18;            /* 0x18 */
    s32 w1C;            /* 0x1C */
    s32 w20;            /* 0x20 */
    s32 w24;            /* 0x24 */
} ArgA180;

void func_01B0A180(ArgA180 *a0)
{
    void *m[2];
    ObjA180 *s0 = a0->obj;
    void *s2 = s0->x1E0;
    void *s3 = s0->x1B0;
    void *s4 = s0->x180;
    P6Node *p;

    m[0] = s2;
    m[1] = 0;
    func_01B11310(m);

    m[0] = s3;
    m[1] = 0;
    func_01B0F5A0(m);

    m[0] = s4;
    m[1] = 0;
    func_01B0F5A0(m);

    {
        ObjA180 *a2 = a0->obj;
        p = a0->parent;
        a0->p0C = a2->x180;
        a0->p10 = a2->x1E0;
        a0->p14 = a2->x1B0;
        a2->node.mark = 0xFF;
        a2->node.last = &a2->node;
        a2->node.first = &a2->node;
        a2->node.parent = p;
        a2->node.b1B = 0;
        if (p != 0) {
            a2->node.next = p;
            a2->node.prev = p->last;
            if (p->last == p) {
                p->first = &a2->node;
            } else {
                p->last->next = &a2->node;
            }
            p->last = &a2->node;
            p->count++;
        }

        {
            register void *p0C __asm__("$2") = a0->p0C;
            register void **mp __asm__("$4") = m;
            register void *p10 __asm__("$3") = a0->p10;
            register void *p08 __asm__("$5");
            void *p14;
            a2->p140 = p0C;
            p08 = a0->p08;
            __asm__ volatile("" : "+r"(p08), "+r"(mp));
            p14 = a0->p14;
            a2->b14C = 0;
            __asm__ volatile("" : "+r"(p10), "+r"(p14), "+r"(p08) : "m"(a2->b14C));
            a2->p148 = p10;
            __asm__ volatile("" : "+r"(p14), "+r"(p08) : "m"(a2->p148));
            a2->p144 = p14;
            __asm__ volatile("" : "+r"(p08) : "m"(a2->p144));
            a2->p12C = p08;
            m[0] = s0;
            m[1] = s2;
            func_01B0A740(mp);
        }
    }

    m[0] = s0;
    m[1] = s3;
    func_01B0A740(m);

    m[0] = s0;
    m[1] = s4;
    func_01B0A740(m);

    {
        register void *p200 __asm__("$4") = s0->x200;
        register void *p1D0 __asm__("$3");
        register void *p1A0 __asm__("$2");
        __asm__("" : "+r"(p200));
        p1D0 = s0->x1D0;
        p1A0 = s0->x1A0;
        VU0_OP("vaddw.xyz $vf31xyz, $vf0xyz, $vf0w");
        VU0_SQC2(0, 0, p200);
        VU0_SQC2(0, 0, p1A0);
        VU0_OP("vmove.w $vf31w, $vf0w");
        VU0_SQC2(31, 0, p1D0);
    }

    s0->b17C = 0;
    {
        s32 w1C = a0->w1C;
        s32 w18 = a0->w18;
        s0->w160 = w1C;
        s0->w168 = w18;
    }
    {
        s32 w24 = a0->w24;
        s32 w20 = a0->w20;
        s0->w164 = w24;
        s0->w16C = w20;
    }
    func_001D9F08(1);
    s0->w174 = func_001A6738(0);

    a0->obj->node.vt = &D_01B057B0;
}
