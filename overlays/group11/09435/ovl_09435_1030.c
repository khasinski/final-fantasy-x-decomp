#include "common.h"

typedef struct {
    int w0;
    int count;
} List9435;

typedef struct {
    u8 pad0[0xD34];
    int wD34;
} Work9435;

extern List9435 D_01B00718;
extern Work9435 *D_01B09248;

extern int func_00297C28(int, int, int, int, int, int, int);
extern int func_01B02A20(int);
extern void func_01B03D28(int, int);

void func_01B01038(int);

void func_01B01030(void)
{
    func_01B01038(1);
}

void func_01B01038(int a0)
{
    int i;

    for (i = 0; i < D_01B00718.count; i++) {
        func_01B03D28(i, a0);
    }
}

void func_01B010A8(void)
{
    Work9435 *w = D_01B09248;

    w->wD34 = func_00297C28(func_01B02A20(-1), 0, 0, 0, 0, 0, 0);
}
