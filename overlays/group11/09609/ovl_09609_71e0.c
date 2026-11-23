#include "common.h"

extern void func_00110540(s32, s32, float);
extern s32 func_01B06880(void);
extern void func_01B06A18(void);

void func_01B071E0(void) {
    func_01B06A18();
    func_00110540(func_01B06880(), 10, 1.0f);
}
