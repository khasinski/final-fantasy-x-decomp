#include "p9_overlay.h"

typedef struct Ovl09315Obj {
    u8 pad0[0x210];
    u32 unk210;
    u32 unk214;
    float unk218;
    float unk21C;
    u8 pad220[4];
    u32 unk224;
    u32 unk228;
    u8 pad22C[4];
    u8 unk230[0x20];
} Ovl09315Obj;

void func_01B059F8(Ovl09315Obj *obj);
int func_002EFD78(void);

void func_01B01298(Ovl09315Obj *obj)
{
    u8 *p;
    int i;

    func_01B059F8(obj);
    obj->unk214 = 0;
    obj->unk228 = 0;
    obj->unk210 = 0x80808080;
    obj->unk218 = 1.0f;
    obj->unk21C = 1.0f;
    obj->unk224 = func_002EFD78() & 0xFFFF;
    p = &obj->unk230[0x1F];
    for (i = 0x1F; i >= 0; i--) {
        *p-- = 0;
    }
}
