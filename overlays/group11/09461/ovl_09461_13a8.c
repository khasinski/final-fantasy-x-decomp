#include "common.h"

typedef struct {
    u8 pad00[0x40];
    u32 w40;
    u32 w44;
    u8 pad48[0x10];
    float f58;
    u8 pad5C[0x10];
    u32 w6C;
    u32 w70;
    u32 w74;
    u32 w78;
    u32 w7C;
} Elem80;

extern Elem80 *D_01B06D68;
extern s32 D_01B06D6C;
extern s32 D_01B06D70;
extern s32 D_01B06D74;
extern u8 D_01B014D8;

extern void *func_1B042F8(void *);
extern void func_1B044C0(void *);

void *ovl_09461_13a8(Elem80 *a0, s32 a1)
{
    s32 i;
    void *s0;

    D_01B06D68 = a0;
    for (i = 0; i < a1; i++) {
        a0->w7C = 0;
        a0++;
    }
    D_01B06D6C = 0;
    D_01B06D70 = a1;
    D_01B06D74 = 0;
    s0 = func_1B042F8(&D_01B014D8);
    func_1B044C0(s0);
    return s0;
}

Elem80 *ovl_09461_1440(void)
{
    s32 i;
    s32 idx;
    Elem80 *e;

    idx = D_01B06D6C;
    for (i = 0; i < D_01B06D70; i++) {
        e = &D_01B06D68[idx];
        idx++;
        if (idx >= D_01B06D70) {
            idx = 0;
        }
        if (e->w7C == 0) {
            e->w40 = 0x80808080;
            e->w44 = 0x80808080;
            e->f58 = 1.0f;
            e->w7C = 1;
            e->w78 = 0;
            e->w6C = 0;
            e->w70 = 0;
            D_01B06D6C = idx;
            return e;
        }
    }
    return 0;
}
