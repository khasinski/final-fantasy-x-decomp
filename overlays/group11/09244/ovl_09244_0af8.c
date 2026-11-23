/* EE Battle-Effect Overlay: group 0x11, file 09244 (0x01B00AF8..0x01B00C20)
 * Load base: 0x01B00000, .text: 0x01B00AF8..0x01B00C20 (1 function)
 */
#include "common.h"

typedef struct Vec4 {
    float x, y, z, w;
} Vec4;

typedef struct SubC0 {
    u8 pad00[0x14];
    int w14;
    u8 pad18[0x90];
    int wA8;
    u8 padAC[0x04];
    u16 hB0;
    u8 padB2[0x0E];
} SubC0;

typedef struct TaskParent {
    u8 pad00[0x10];
    int p10;
} TaskParent;

typedef struct Task09244 {
    u8 pad00[0x08];
    TaskParent *p08;
    u8 pad0C[0x08];
    int w14;
} Task09244;

extern u8 D_01B05128[];
extern SubC0 D_01B05610[2];
extern int D_01B057F0;
extern u8 D_01B057F8[];
extern void *D_01B0583C;

extern void func_01B00800(void);

int func_01B00D90(int);
void func_001B72F0(int, void *);
void func_01B04C88(void *, int, void *, int, float, float, float);
int func_01B02A80(void *);
int func_01B039E0(void *, void *);

void func_01B00AF8(Task09244 *t)
{
    Vec4 v;
    register int done __asm__("$19") = 0;
    int r1;
    int r2;

    if (D_01B057F0 == 0) {
        if (D_01B05610[0].hB0 & 0x8000) {
            SubC0 *s = &D_01B05610[1];
            func_001B72F0(func_01B00D90(-1), &v);
            func_01B04C88(s, -1, &v, 0x18, 0.5f, 0.75f, 0.99f);
            s->wA8 = 0x28;
            __asm__("" : "+m"(s->wA8));
            s->w14 = 1;
            D_01B057F0 = 1;
        }
    } else {
        register int flg __asm__("$2") = D_01B05610[1].hB0 & 0x8000;
        __asm__("" : "+r"(flg));
        done = flg != 0;
    }

    r1 = func_01B02A80(D_01B05128);
    r2 = func_01B039E0(D_01B057F8, D_01B0583C);
    if (r2 == 1 && r1 == 1 && done == 1) {
        register TaskParent *p __asm__("$4") = t->p08;
        t->w14 = 3;
        p->p10 = (int)func_01B00800;
    }
}
