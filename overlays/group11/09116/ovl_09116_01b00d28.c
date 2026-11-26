#include "common.h"

typedef struct Ovl09116Node {
    u8 pad00[0x10];
    int cb;
} Ovl09116Node;

typedef struct Ovl09116Task {
    u8 pad00[0x08];
    Ovl09116Node *node;
    u8 pad0C[0x08];
    int timer;
} Ovl09116Task;

extern u8 D_01B00930[];
extern u8 D_01B062E8[];
extern int D_01B06D34;
extern u8 D_01B06D38[];
extern int D_01B06FE4;

void func_01B00DB8(void);
int func_01B03798(void *a0);
int func_01B046F8(void *a0, int a1);

void func_01B00D28(Ovl09116Task *a0)
{
    int s0;
    int v1;

    func_01B00DB8();
    s0 = func_01B046F8(D_01B06D38, D_01B06FE4);
    v1 = func_01B03798(D_01B062E8);
    if (v1 == 1 && s0 == 1 && D_01B06D34 == 0) {
        a0->timer = 3;
        a0->node->cb = (int)D_01B00930;
    }
}
