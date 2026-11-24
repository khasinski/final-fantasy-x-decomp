#include "common.h"

typedef struct {
    u8 pad00[0x10];
    void *p10;
} Sub08;

typedef struct {
    u8 pad00[0x8];
    Sub08 *p08;
    u8 pad0C[0x8];
    s32 w14;
} Task12C8;

extern u8 D_01B08468[];
extern u8 D_01B08408[];
extern u8 D_01B085F8[];
extern void *D_01B089D4;
extern u8 D_01B00DB8[];

extern s32 func_01B03678(void *);
extern s32 func_01B07AA8(void *);
extern s32 func_01B045D8(void *, void *);

void ovl_09314_12c8(Task12C8 *s2)
{
    s32 s0 = func_01B03678(D_01B08468);
    s32 s1 = func_01B07AA8(D_01B08408);

    if (func_01B045D8(D_01B085F8, D_01B089D4) == 1 && s0 == 1 && s1 == 1) {
        register Sub08 *p08 __asm__("$4") = s2->p08;
        register s32 c3 __asm__("$3") = 3;
        register void *p0db8 __asm__("$2") = D_01B00DB8;
        *(volatile s32 *)&s2->w14 = c3;
        *(void *volatile *)&p08->p10 = p0db8;
    }
}
