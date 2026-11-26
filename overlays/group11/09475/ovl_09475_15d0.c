#include "common.h"

typedef struct {
    u8 pad00[0xD74];
    int wD74;
} OvlState;

extern void *D_01B00834;
extern int D_01B09F18;
extern u8 D_01B09F20[];
extern void *D_01B09F64;
extern u8 D_01B09F68[];
extern u8 D_01B09FC8[];
extern u8 D_01B0A028[];
extern u8 D_01B0A048[];
extern OvlState *D_01B0A068;
extern void *D_01B0A06C;

extern void func_001CDDD8(int);
extern void func_01B01768(void);
extern int func_01B05448(void *);
extern void func_01B05FE8(void *);
extern int func_01B063A8(void *, void *);
extern void func_01B07650(void);
extern int func_01B09878(void *);

void func_01B015D0(void *a0)
{
    OvlState *s = D_01B0A068;
    int r0, r1;

    func_01B07650();
    D_01B00834 = D_01B0A06C;
    r0 = func_01B09878(D_01B09F68);
    func_01B09878(D_01B09FC8);
    r1 = func_01B05448(D_01B0A028);
    func_01B05448(D_01B0A048);
    if (r0 != 0 && r1 != 0) {
        s->wD74 = 1;
        func_01B01768();
        func_01B05FE8(a0);
    }
}

void func_01B01698(void)
{
    OvlState *s = D_01B0A068;

    if (func_01B063A8(D_01B09F20, D_01B09F64) == 1 && s->wD74 == 1) {
        func_001CDDD8(D_01B09F18);
    }
}
