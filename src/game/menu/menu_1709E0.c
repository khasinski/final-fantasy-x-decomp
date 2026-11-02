/* tu_119 0x1709e0-0x170bc4: low; unk_1709E0 (config/tu_map.tsv) */
#include "common.h"
#include "ffx/q3.h"
#include "ffx/w2.h"
#include "ffx/r1.h"
#include "ffx/g1.h"

void func_001709E0(int a) {
    if (D_0030E0C4 == 0) {
        D_0030E0E0 = 1;
        D_0030E0C4 = 1;
        D_0030E0DC = a;
    }
}

void func_00170A10(int a) {
    if (D_0030E0C4 == 0) {
        D_0030E0E0 = 0;
        D_0030E0DC = a;
        D_0030E0C4 = 1;
    }
}

void func_00170A40(int a) {
    if (D_0030E0C4 == 0) {
        D_0030E0E0 = 3;
        D_0030E0DC = a;
        D_0030E0C4 = 1;
    }
}

void func_00170A78(int h) {
    SndSepPlaySimple(h | 0x80000000);
}

void func_00170A88(void) {
}

void func_00170A90(void)
{
    s32 value0;
    u32 *value1;

    value0 = Sg_PacketGetPtr();
    value1 = func_002DB6D8(2);
    func_0016C688(value0, D_0030E094 + 4, D_0030E094, 0x170, 0xF6, 0x80, 0x80);
    func_002F8660(0);
    func_002DBA28(value1, value0);
    func_002DA610(0, 0);
}

void func_00170B10(void)
{
    s32 value0;
    u32 *value1;

    value0 = Sg_PacketGetPtr();
    value1 = func_002DB6D8(2);
    func_0016C688(value0, D_0030E094 + 0x48, D_0030E094 + 0x44, 0, 0, 0x200, 0x200);
    func_002F8660(0);
    func_002DBA28(value1, value0);
    func_002DA610(0, 0);
}

void func_00170B90(int a) {
    if (a == 0) {
        D_005661F4 = 0;
    } else {
        D_005661F4 = 1;
        func_001663A0();
    }
    TkRefreshHDDMode();
}
