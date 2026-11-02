/* tu_125 0x178648-0x1787e8: low; unk_178648 (config/tu_map.tsv) */
#include "common.h"
#include "ffx/q3.h"
#include "ffx/r1.h"
#include "ffx/r2.h"
#include "ffx/s2.h"
#include "ffx/v2.h"

INCLUDE_ASM("build/ee_asm/game/yi/yi_178648", func_00178648);

void func_001786F8(int a) {
    func_00178648(a + 0x27640, 0x4007);
    func_00178790(a);
}

void func_00178730(int a) {
    u32 st = *(u32 *)(a + 0x67F38); /* DEBT(CAST): unknown object type */

    if (st >= 2) {
        if (st < 5) {
            func_00178648(a + 0x10, *(int *)(a + 0x13B10) - 1); /* DEBT(CAST) */
        }
    }
    func_00178790(a);
}

void func_00178790(int a) {
    V2SndReq req;
    V2Quad *q;

    req.w04 = 0x10000000;
    req.w08 = 0xE;
    req.w0C = 0;
    q = &req.sub;
    q->w0 = 0;
    q->w8 = 0x3F;
    q->w4 = 0;
    q->wC = 0;
    req.w00 = 0x8001;
    func_00178648((int)&req, 2); /* DEBT(TYPE): funcs.h takes the address as int */
}
