#include "common.h"

typedef struct {
    u8 pad00[0x1CC];
    void *p1CC;      /* 0x1CC */
    u8 pad1D0[0x48];
    int w218;        /* 0x218 */
    u8 pad21C[0x24];
    float f240;      /* 0x240 */
    float f244;      /* 0x244 */
    u8 pad248[4];
    float f24C;      /* 0x24C */
    u8 pad250[0x30];
    float f280;      /* 0x280 */
    s16 h284;        /* 0x284 */
    u16 h286;        /* 0x286 */
    int w288;        /* 0x288 */
    float f28C;      /* 0x28C */
} ItemE068;          /* 0x290 */

typedef struct {
    u8 pad00[0xB0];
    ItemE068 items[1]; /* 0xB0 */
    u8 pad340[0x13D0];
    int count;       /* 0x1710 */
    float f1714;     /* 0x1714 */
    u8 pad1718[0x0C];
    u8 flags1724;    /* 0x1724 */
} ObjE068;

typedef struct {
    ObjE068 *obj;    /* 0x00 */
    float f04;       /* 0x04 */
    float f08;       /* 0x08 */
} ArgE068;

extern u8 g_sym_0ab0[];
extern void g_fn_18f0(void *);
extern int func_001ACEA0(void);
extern float func_001ACED8(void);

void func_01B0E068(ArgE068 *a0)
{
    ObjE068 *s2 = a0->obj;
    ItemE068 *it;
    int i;

    s2->flags1724 = (s2->flags1724 & ~2) | 4;
    it = s2->items;
    for (i = 0; i < s2->count; i++, it++) {
        void *m[4];
        int r = func_001ACEA0();
        float f;

        m[0] = it;
        m[1] = &it->f240;
        g_fn_18f0(m);
        it->f24C = 1.0f;
        f = func_001ACED8();
        it->f244 -= (f - 0.99f) * 300.0f + 100.0f;
        it->w218 += 0x8000;
        it->p1CC = g_sym_0ab0;
        it->w288 = (1 - (r & 2)) * (r & 0xFFF);
        it->h284 = 0;
        it->f280 = a0->f04;
    }
    s2->f1714 = a0->f08;
}
