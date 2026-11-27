#include "common.h"

extern u8 D_01B092E0[];
extern u8 *D_01B093A8;
extern int D_01B093BC;

void func_01B060B8(void *a0, void *a1);
u8 *func_001E4F58(int a0, int *a1);
int func_01B030D8(int a0);
void func_001E4CD0(int a0);
void func_001E4D50(int a0);

void func_01B02D98(void)
{
    func_01B060B8(D_01B092E0, D_01B093A8 + 0x390);
}

int func_01B02DB0(void)
{
    return D_01B093BC == 0;
}

void func_01B02DC0(void)
{
    int count;
    u8 *list;
    u8 id;
    int i;

    list = func_001E4F58(9, &count);
    id = func_01B030D8(-1);
    for (i = 0; i < count; i++) {
        u8 c = list[i];
        if (c != id) {
            func_001E4CD0(c);
        }
    }
}

void func_01B02E40(void)
{
    int count;
    u8 *list;
    u8 id;
    int i;

    list = func_001E4F58(9, &count);
    id = func_01B030D8(-1);
    for (i = 0; i < count; i++) {
        u8 c = list[i];
        if (c != id) {
            func_001E4D50(c);
        }
    }
}
