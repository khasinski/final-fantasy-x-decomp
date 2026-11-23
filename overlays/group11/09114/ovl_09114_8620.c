#include "common.h"

typedef struct {
    u8 pad0[0x1C];
    void (*unk1C)(void *);
} Unk8620Vtbl;

typedef struct {
    Unk8620Vtbl *vtbl;
    u8 pad04[0x9C];
    u8 unkA0[0x40];
} Unk8620Inner;

typedef struct {
    u8 pad0[0x20];
    u8 unk20[0x10];
    u8 unk30[0x10];
    Unk8620Inner *unk40;
} Unk8620Obj;

typedef struct {
    Unk8620Obj *unk00;
    u8 unk04;
    u8 unk05;
    u8 pad06[2];
} Unk8620Arg;

typedef struct {
    Unk8620Inner *unk00;
    u8 unk04;
    u8 unk05;
    u8 pad06[2];
} Unk8620SubArg;

extern void func_002DCE08(void *, void *, void *);
extern void func_01B188E8(Unk8620Arg *);

void func_01B18620(register Unk8620Arg *arg0) {
    Unk8620Obj *obj;
    Unk8620SubArg sub;

    func_01B188E8(arg0);
    if (!((u8)(arg0->unk04 & 1))) {
        return;
    }
    obj = arg0->unk00;
    sub.unk00 = obj->unk40;
    sub.unk05 = arg0->unk05;
    sub.unk00->vtbl->unk1C(&sub);
    func_002DCE08(obj->unk20, obj->unk40->unkA0, obj->unk30);
}
