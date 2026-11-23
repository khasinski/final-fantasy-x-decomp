#include "common.h"

typedef struct {
    u8 pad000[0x5C8];
    int w5C8;
} Obj1E90;

typedef struct {
    u8 pad00[0x18];
    u8 b18;
} Task1E90;

extern Obj1E90 *D_01B07ED0;
extern void func_01B01D28(void);
extern Task1E90 *func_01B04850(void *);
extern void func_01B04A18(void *);

void func_01B01E90(void)
{
    Task1E90 *t;
    D_01B07ED0->w5C8 = 80;
    t = func_01B04850((void *)func_01B01D28);
    t->b18 = 1;
    func_01B04A18(t);
}
