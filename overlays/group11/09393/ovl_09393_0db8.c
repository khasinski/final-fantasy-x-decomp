/* EE Battle-Effect Overlay: group 0x11, file 09393 (shared 0x01B00DB8..0x01B00EB4, also in 09635)
 * Load base: 0x01B00000, .text: 0x01B00DB8..0x01B00EB4 (1 function)
 */
#include "common.h"
#include "vu0.h"

typedef struct Vec4 {
    float x, y, z, w;
} Vec4;

typedef struct Sub20 {
    u8 pad00[0x20];
} Sub20;

typedef struct Mat40 {
    u8 pad00[0x30];
    Vec4 pos;
} Mat40;

typedef struct Work09393 {
    u8 pad0000[0x18F0];
    Mat40 unk18F0[3];    /* 0x18F0 */
    Vec4 unk19B0[3];     /* 0x19B0 */
    Vec4 unk19E0[3];     /* 0x19E0 */
    u8 pad1A10[0x250];
    int unk1C60;         /* 0x1C60 */
} Work09393;

extern u8 D_01B07B30[];
extern u8 D_01B07B90[];
extern Sub20 D_01B07BB0[3];
extern Work09393 *D_01B07C10;

int func_01B074C0(void *a0);
int func_01B03740(void *a0);
void func_01B00FB0(void);
void func_01B042E0(void *a0);

void func_01B00DB8(void *a0)
{
    register Work09393 *w __asm__("$18") = D_01B07C10;
    register int r1 __asm__("$20");
    register int r2 __asm__("$19");
    int i;

    r1 = func_01B074C0(D_01B07B30);
    r2 = func_01B03740(D_01B07B90);
    {
        Sub20 *p = D_01B07BB0;
        __asm__("" : "+r"(p));
        for (i = 0; i < 3; i++) {
            func_01B03740(&p[i]);
        }
    }
    __asm__("" : "+r"(w) : : "memory");
    {
        Vec4 *src = w->unk19E0;
        u8 *dp = (u8 *)&w->unk18F0[0].pos;
        for (i = 0; i < 3; ) {
            MMI_COPY_LQ_A3(dp, src);
            MMI_COPY_SQ_A3(dp);
            i++;
            __asm__("" : "+r"(i));
            src++;
            dp += 0x40;
            __asm__("" : "+r"(dp) : "r"(src));
        }
    }
    __asm__("" : "+r"(r1));
    if (r1 == 1 && r2 == r1) {
        w->unk1C60 = 1;
        func_01B00FB0();
        func_01B042E0(a0);
    }
}
