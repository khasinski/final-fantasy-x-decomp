#include "common.h"

typedef struct {
    u8 pad00[0x10];
    u32 fn10;
} OvlSub;

typedef struct {
    u8 pad00[0x08];
    OvlSub *sub;
    u8 pad0C[0x08];
    u32 state;
} OvlTask;

extern u8 D_01B00BC0[];
extern u8 D_01B06598[];
extern u8 D_01B066D0[];
extern u8 D_01B06728[];
extern void *D_01B069D4;

extern void func_01B02770(int, void *, int);
extern int func_01B04210(void *);
extern void func_01B04870(void *);
extern void func_01B04A10(void *, void *);
extern int func_01B05170(void *, void *);

void ovl_09311_1d28(OvlTask *task)
{
    float pos[4];
    int a;
    int b;

    func_01B02770(-1, pos, 0);
    func_01B04A10(D_01B066D0, pos);
    func_01B04870(D_01B066D0);
    a = func_01B04210(D_01B06598);
    b = func_01B05170(D_01B06728, D_01B069D4);
    if (b == 1 && a == 1) {
        task->state = 3;
        task->sub->fn10 = (u32)D_01B00BC0;
    }
}
