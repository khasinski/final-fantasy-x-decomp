#include "common.h"

typedef struct {
    float x, y, z, w;
} __attribute__((aligned(16))) Vec4;

static inline void wrap_angle(float *p, float d) {
    float a = *p + d;
    if (a > 3.1415927f) {
        a -= 6.2831855f;
    } else if (a < -3.1415927f) {
        a += 6.2831855f;
    }
    *p = a;
}

typedef struct {
    u8 pad00[0x813];
    u8 b813;
    u8 pad814[0x9C];
} OvlSub8B0; /* size 0x8B0 = 2224 */

typedef struct {
    u8 pad00[0x980];
    u8 f980[0xC0]; /* 0x980 */
    Vec4 vA40;     /* 0xA40 */
    Vec4 vA50;     /* 0xA50 */
    u8 padA60[0x24];
    float fA84;    /* 0xA84 */
    u8 padA88[0xC];
    float fA94;    /* 0xA94 */
    u8 padA98[0x3E8];
    OvlSub8B0 sE80[4]; /* 0xE80 */
    u8 pad3140[0x10];
    s32 w3150;     /* 0x3150 */
} Ovl09631Work;

extern Ovl09631Work *D_01B0A1E0;

extern void func_01B05138(s32, void *, void *);
extern void func_01B01AE0(void);

void func_01B02C88(void) {
    Ovl09631Work *w = D_01B0A1E0;
    s32 i;

    w->fA84 -= w->fA94;
    wrap_angle(&w->vA40.y, w->fA84);

    func_01B05138(-1, w->f980, &w->vA40);
    w->vA50.y += 15.0f;

    {
        OvlSub8B0 *p = w->sE80;
        for (i = 3; i >= 0; i--, p++) {
            if (p->b813 < 24) {
                p->b813++;
            }
        }
    }
}

void func_01B02D70(void) {
    Ovl09631Work *w = D_01B0A1E0;

    if (w->w3150 > 0) {
        w->w3150--;
    }
    func_01B01AE0();
}
