#include "common.h"

typedef struct {
    u8 pad0[0xD628];
    s32 unkD628;
} Unk6F48Work;

extern Unk6F48Work *D_01B0DCA8;

void func_01B06F48(void) {
    D_01B0DCA8->unkD628 = 1;
}
