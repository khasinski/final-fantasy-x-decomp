#include "common.h"

typedef struct SCC08Item {
    u8 pad00[0x74];
    s32 s74;
    u8 pad78[0x28];
} SCC08Item;

typedef struct SCC08Src {
    SCC08Item items[8];
    u8 pad500[0x20];
    s32 count;
} SCC08Src;

typedef struct SCC08Obj {
    u8 pad00[0x18];
    s32 s18;
    u8 pad1C[0x8];
    s32 total;
    s32 lens[3];
    float ratios[3];
    SCC08Src *src;
} SCC08Obj;

extern void func_01B1C9B8(void);
extern void func_01B2CC48(void *a0);
extern void func_01B2D050(void *a0);
extern s32 func_001BB3F0(void *a0, s32 a1, void *a2, void *a3, void *a4);
extern u8 D_01B00AF0[];
extern void *D_01B00730;

void func_01B1CC08(SCC08Obj *a0, SCC08Src *a1)
{
    void *m[4];
    u8 buf[0x10];
    s32 i;
    float total_f;

    m[0] = a0;
    m[1] = func_01B1C9B8;
    m[2] = a0;
    func_01B2CC48(m);

    m[0] = D_01B00AF0;
    m[1] = a0;
    func_01B2D050(m);

    a0->total = 0;
    for (i = 0; i < a1->count; i++) {
        SCC08Item *it = &a1->items[i];
        s32 n;
        __asm__("" : "+r"(it));
        n = func_001BB3F0(D_01B00730, it->s74, buf, buf, buf) - 2;
        a0->lens[i] = n;
        a0->total += n;
    }

    total_f = (float)a0->total;
    for (i = 0; i < a1->count; i++) {
        a0->ratios[i] = (float)a0->lens[i] / total_f;
    }

    a0->src = a1;
    a0->s18 = 0;
}
