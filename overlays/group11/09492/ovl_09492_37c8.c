#include "common.h"

typedef struct {
    int w0;
    int count;
} List9492;

extern List9492 D_01B00678;
extern void func_01B036F8(int, int);

void func_01B037C8(int visible)
{
    int i;

    for (i = 0; i < D_01B00678.count; i++) {
        func_01B036F8(i, visible);
    }
}
