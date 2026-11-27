#include "common.h"

typedef struct {
    u8 pad00[0x293C];
    int w293C;
    int w2940;
} State9351;

extern void *D_01B01404;
extern int D_01B0D6B0;
extern u8 D_01B0D6B8[];
extern void *D_01B0E7A4;
extern u8 D_01B0E7A8[];
extern u8 D_01B0E808[];
extern State9351 *D_01B0E828;
extern void *D_01B0E830;
extern void *D_01B0E834;

extern void func_001CDDD8(int);
extern void func_01B025E0(void);
extern void func_01B07C98(void *);
extern void func_01B08838(void *);
extern int func_01B08BF8(void *, void *);
extern void func_01B09EA0(void);
extern void func_01B0A6C8(void);
extern int func_01B0C0C8(void *);

void func_01B01908(void *a0)
{
    State9351 *s = D_01B0E828;

    func_01B09EA0();
    D_01B01404 = D_01B0E834;
    D_01B0E830 = D_01B0E7A4;
    if (func_01B0C0C8(D_01B0E7A8) == 0) {
        func_01B07C98(D_01B0E808);
        func_01B0A6C8();
    } else if (s->w293C == 1) {
        s->w2940 = 1;
        func_01B025E0();
        func_01B08838(a0);
    }
}

void func_01B019B8(void)
{
    State9351 *s = D_01B0E828;

    if (func_01B08BF8(D_01B0D6B8, D_01B0E830) == 1 && s->w2940 == 1) {
        func_001CDDD8(D_01B0D6B0);
    }
}
