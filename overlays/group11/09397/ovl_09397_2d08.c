#include "common.h"

typedef struct {
    u8 pad00[0x18];
    u8 b18;
} Task9397_C;

typedef struct {
    u8 pad0000[0x1444];
    int w1444;
} Obj9397_C;

extern Obj9397_C *D_01B09E00;
extern void func_01B02C30(void);
extern Task9397_C *func_01B05C90(void *);
extern void func_01B05E58(Task9397_C *);

void func_01B02D08(void)
{
    Task9397_C *v0;

    D_01B09E00->w1444 = 80;
    v0 = func_01B05C90(func_01B02C30);
    v0->b18 = 1;
    func_01B05E58(v0);
}
