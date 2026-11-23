#include "common.h"

typedef struct {
    u8 pad0[0x2B64];
    s32 unk2B64;
    s32 unk2B68;
} Sub30B0;

typedef struct {
    u8 pad0[0x30B0];
    Sub30B0 unk30B0;
} State1D50;

extern State1D50 *D_01B0B398;

extern void func_01B01BB0(void);
extern void func_01B01CE8(void *);
extern void *func_01B07000(void (*)(void));
extern void func_01B071C8(void *);

void func_01B01D50(void) {
    State1D50 *s = D_01B0B398;
    Sub30B0 *sub = &s->unk30B0;

    if (sub->unk2B68 == 0) {
        func_01B01CE8((u8 *)s + 0x59C0);
    }
    if (sub->unk2B68 != 1) {
        sub->unk2B64 = 0x71;
        func_01B071C8(func_01B07000(func_01B01BB0));
    }
}
