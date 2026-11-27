#include "common.h"

typedef struct {
    u8 pad00[0x4C0];
    u8 sub4C0[0x2CB4];
    void *p3174;
} Work34A8;

extern u8 D_01B0B130[];
extern Work34A8 *D_01B0B1F8;
extern void func_01B066D8(void *);
extern void func_01B06E28(void *, void *);

void func_01B034A8(void)
{
    Work34A8 *w = D_01B0B1F8;
    if (w->p3174 != 0) {
        func_01B066D8(w->p3174);
        w->p3174 = 0;
    }
    func_01B06E28(D_01B0B130, w->sub4C0);
}
