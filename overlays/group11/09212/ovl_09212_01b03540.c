#include "common.h"

typedef struct Ovl09212Work {
    u8 pad00[0xCE0];
    u8 bCE0[0x24E4];
    int w31C4;
} Ovl09212Work;

extern Ovl09212Work *D_01B0A8E8;

void func_01B01AC8(void *a0, int a1);
void func_01B059B0(void *a0);
void func_01B05A08(int a0);
void func_01B061D8(int a0);
void func_01B0A0C0(void *a0, int a1, int a2, float a3, float a4);

void func_01B03540(void)
{
    Ovl09212Work *w = D_01B0A8E8;
    u8 buf[0x10];

    func_01B059B0(buf);
    func_01B01AC8(buf, 0x14);
    func_01B0A0C0(w->bCE0, 0x14, 0, 0.0f, 1.0f);
    func_01B05A08(0);
}

void func_01B035A0(void)
{
    Ovl09212Work *w = D_01B0A8E8;

    if (w->w31C4 != 0) {
        func_01B061D8(w->w31C4);
        w->w31C4 = 0;
    }
}
