#include "common.h"

typedef struct S38C8Item {
    u8 pad00[0xC4];
    float fC4;
    u8 padC8[0x3C];
    void *p104;
    u8 pad108[0x1E];
    u8 b126;
    u8 pad127[9];
} S38C8Item; /* size 0x130 */

typedef struct S38C8Sub {
    u8 pad00[0x2B60];
    void *p2B60;
    s32 s2B64;
    s32 s2B68;
} S38C8Sub;

typedef struct S38C8Global {
    S38C8Item items[16];
    u8 pad1300[0x1C80];
    S38C8Sub sub; /* 0x2F80 */
    u8 pad5AEC[0x8FE4];
    float fEAD0; /* 0xEAD0 */
} S38C8Global;

typedef struct S38C8Task {
    u8 pad00[0x2C];
    s32 s2C;
} S38C8Task;

extern S38C8Global *D_01B0DCA8;
extern u8 D_01B0DBE0[];
extern s32 D_01B00B10[];
extern void D_01B06F08(void);
extern void D_01B03820(void);

extern void func_01B09C48(void *a0, void *a1, s32 a2, s32 a3, s32 a4, s32 a5, float f0);

void func_01B038C8(S38C8Task *a0)
{
    S38C8Global *g = D_01B0DCA8;
    S38C8Sub *sub = &g->sub;
    s32 mode = a0->s2C;
    s32 idx;
    S38C8Item *it;

    sub->s2B68 = mode;
    idx = D_01B00B10[mode];
    it = &g->items[idx];
    func_01B09C48(D_01B0DBE0, it, idx, 0, 0, 0, 0.1f);
    it->p104 = D_01B06F08;
    it->fC4 = g->fEAD0;
    {
        s32 m = sub->s2B68;
        if (m == 2) {
            register void *fn __asm__("$3");
            it = &g->items[9];
            func_01B09C48(D_01B0DBE0, it, 9, 0x14, 0, 0, 0.06f);
            it->b126 = m;
            fn = D_01B03820;
            it->p104 = fn;
        }
        sub->p2B60 = it;
    }
}
