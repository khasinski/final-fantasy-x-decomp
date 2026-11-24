#include "common.h"

typedef struct {
    int w0;
    int count;
} List9435;

extern List9435 D_01B00718;
extern void func_01B038A0(int, int);

void func_01B03970(int visible)
{
    int i;

    for (i = 0; i < D_01B00718.count; i++) {
        func_01B038A0(i, visible);
    }
}
