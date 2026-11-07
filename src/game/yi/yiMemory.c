/* tu_129 0x17db20-0x17dc98: low; yiMemory (config/tu_map.tsv) */
#include "common.h"
#include "ffx/q3.h"
#include "ffx/v2.h"
#include "ffx/r2.h"
#include "ffx/s2.h"

extern s8 _m2c_func_0017DB20_D_0056C6A8 __asm__("D_0056C6A8");
void func_0017DB20(void) {
    func_002EF240(&_m2c_func_0017DB20_D_0056C6A8, 0x40);
    func_002EF240(&_m2c_func_0017DB20_D_0056C6A8, 0x40);
    func_002EF240(&_m2c_func_0017DB20_D_0056C6A8, 0x40);
    func_002EF240(&_m2c_func_0017DB20_D_0056C6A8, 0x40);
    func_002EF240(&_m2c_func_0017DB20_D_0056C6A8, 0x40);
    func_002EF240(&_m2c_func_0017DB20_D_0056C6A8, 0x40);
    func_002EF240(&_m2c_func_0017DB20_D_0056C6A8, 0x80);
    func_002EF240(&_m2c_func_0017DB20_D_0056C6A8, 0x40);
}

void *func_0017DBA0(int size) {
    return user_malloc(size, 0xC, D_0056C6B0, -1);
}

void *func_0017DBC8(int size) {
    func_0011C348(0x40);
    return user_malloc(size, 0xC, D_0056C6B0, -1);
}

void *func_0017DC08(int size) {
    return func_0011D420(size, 0xC, D_0056C6B0, -1);
}

void *func_0017DC30(int size) {
    func_0011BF40(1);
    return user_malloc(size, 0xC, D_0056C6B0, -1);
}

void func_0017DC70(s32 h) {
    func_0011D590(h, 0xC);
}

int func_0017DC78(void) {
    return func_0011D718();
}
