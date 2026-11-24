#include "common.h"

typedef struct {
    int w0;
    int count;
} List9492;

typedef struct {
    u8 pad0[0xD34];
    int wD34;
} Work9492;

extern List9492 D_01B00678;
extern Work9492 *D_01B09098;

extern int func_00297C28(int, int, int, int, int, int, int);
extern int func_01B02878(int);
extern void func_01B03B80(int, int);

void func_01B00EE0(int);

void func_01B00ED8(void)
{
    func_01B00EE0(1);
}

void func_01B00EE0(int a0)
{
    int i;

    for (i = 0; i < D_01B00678.count; i++) {
        func_01B03B80(i, a0);
    }
}

void func_01B00F50(void)
{
    Work9492 *w = D_01B09098;

    w->wD34 = func_00297C28(func_01B02878(-1), 0, 0, 0, 0, 0, 0);
}
