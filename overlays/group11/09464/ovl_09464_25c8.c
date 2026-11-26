#include "common.h"

typedef struct {
    void *p00;
} Arg4;

extern s32 D_01B00418;
extern u8 D_01B00E90[];
extern u16 D_01B016D8;
extern float D_01B016DC;

extern s32 func_001CE050(s32, s32);
extern void func_001CE2F0(s32, s32);
extern s32 func_001DC7C0(s32);
extern void func_01B021B0(void *);
extern void func_01B0E418(void *);

void ovl_09464_25c8(Arg4 *ctx)
{
    switch (D_01B016D8) {
    case 0:
        D_01B016D8++;
        /* fallthrough */
    case 1:
        func_001CE050(D_01B00418, 0xB8);
        D_01B016DC = 0.0f;
        D_01B016D8 = 2;
        break;
    case 2:
        if (func_001DC7C0(D_01B00418) != 0) {
            func_001CE050(D_01B00418, 0xB9);
            func_01B021B0(D_01B00E90);
            D_01B016D8 = 3;
        }
        break;
    case 3:
        if (D_01B016DC >= 0.8f) {
            func_001CE050(D_01B00418, 0xBA);
            D_01B016D8++;
        }
        break;
    case 4:
        if (func_001DC7C0(D_01B00418) != 0) {
            Arg4 arg;
            func_001CE2F0(D_01B00418, 0);
            arg.p00 = ctx->p00;
            func_01B0E418(&arg);
        }
        break;
    }
    D_01B016DC += (1.0f / 30.0f);
}
