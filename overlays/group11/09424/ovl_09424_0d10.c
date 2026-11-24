#include "common.h"

typedef struct {
    s32 w00;
    s32 w04;
    s32 w08;
    s32 w0C;
    u8 pad10[0x8];
    u16 h18;
} Obj8250;

typedef struct {
    u8 pad00[0x4];
    float f04;
    float f08;
    s32 w0C;
    float f10;
    float f14;
    s32 w18;
    u8 pad1C[0xC];
    s32 w28;
    u16 h2C;
} Obj8270;

typedef struct {
    u8 pad00[0x10];
    void *p10;
} Sub08;

typedef struct {
    u8 pad00[0x8];
    Sub08 *p08;
    u8 pad0C[0x8];
    s32 w14;
} TaskD10;

extern u8 D_01B06358[];
extern u8 D_01B06378[];
extern u8 D_01B08300[];
extern u8 *D_01B08804;
extern Obj8250 D_01B08250;
extern Obj8270 D_01B08270;
extern u8 D_01B00A30[];

extern s32 func_01B03268(void *);
extern s32 func_01B041C8(void *, void *);

void ovl_09424_0d10(TaskD10 *a0)
{
    s32 s0 = func_01B03268(D_01B06358);
    s32 s1 = func_01B03268(D_01B06378);

    if (func_01B041C8(D_01B08300, D_01B08804) == 1 && s0 == 1 && s1 == 1) {
        Obj8250 *o1 = &D_01B08250;
        Obj8270 *o2 = &D_01B08270;
        register s32 c3 __asm__("$8") = 3;
        register Sub08 *p08 __asm__("$7");
        register void *p0a30 __asm__("$4");
        register u16 t1 __asm__("$3") = o1->h18;
        register u16 t2 __asm__("$2") = o2->h2C;
        p0a30 = D_01B00A30;
        p08 = a0->p08;
        *(volatile u16 *)&o1->h18 = t1 & ~1;
        *(volatile u16 *)&o2->h2C = t2 & ~4;
        *(volatile s32 *)&a0->w14 = c3;
        *(void *volatile *)&p08->p10 = p0a30;
    }
}
