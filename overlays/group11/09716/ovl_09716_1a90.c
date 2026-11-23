#include "common.h"

typedef struct {
    u8 pad000[0x5B4];
    int w5B4;
    int w5B8;
    int w5BC;
    int w5C0;
    int w5C4;
} Obj1A90;

extern Obj1A90 *D_01B07ED0;
extern void func_01B01920(void);
extern void *func_01B04850(void *);
extern void func_01B04A18(void *);

void func_01B01A90(void)
{
    Obj1A90 *v0 = D_01B07ED0;
    v0->w5B4 = 0;
    v0->w5B8 = 60;
    v0->w5BC = 60;
    v0->w5C0 = 500;
    v0->w5C4 = 500;
    func_01B04A18(func_01B04850((void *)func_01B01920));
}
