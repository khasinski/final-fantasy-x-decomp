/* tu_275 0x250f68-0x251178: medium; ~Tk (config/tu_map.tsv) */
#include "common.h"
#include "ffx/r6.h"
#include "ffx/w8.h"
#include "ffx/q6.h"
#include "ffx/s6.h"
#include "ffx/u4.h"
#include "ffx/v5.h"
#include "ffx/t6.h"

void TkMenuExecHddCopyTask(void)
{
    func_001660B0();
    D_00326FFC = 1;
}

void func_00250F90(void)
{
    SysIf *sys;

    D_00326FFC = 0;
    sys = func_00241FC0();
    if (sys != 0) {
        sys->fn(TkMenuExecHddCopyTask, 0, 0);
    }
}

INCLUDE_ASM("build/ee_asm/game/menu/tk/tk_250F68", TkMenuCtrlHdd);

/* DEBT(NAME): module guessed: event/command queue (func_00251360 posts a request, func_00251178 waits for the reply);
 * many tiny wrappers below only differ in the command id. No source file name found in the ELF strings. */

void func_00251068(void) {
}

void func_00251070(void)
{
    func_00251068();
}

void func_00251078(void) {
}

int func_00251080(void)
{
    return 1;
}

void func_00251088(int *p)
{
    p[7] = 0;
}

void func_00251090(void) {
}

void func_00251098(void) {
}

u16 func_002510A0(int n, u8 *p)
{
    u16 tab[256];
    int i;
    u32 j;
    u32 k;
    u32 c;
    u32 crc;
    u16 *t;

    for (i = 255; i >= 0; i--) {
        tab[i] = 0;
    }
    crc = 0xFFFF;
    t = tab;
    for (j = 0; j < 255; j++) {
        c = j << 8;
        for (k = 0; k < 8; k++) {
            if (c & 0x8000) {
                c = (c << 1) ^ 0x1021;
            } else {
                c <<= 1;
            }
            t[j] = c;
        }
    }
    for (; n > 0; n--) {
        crc = (tab[*p++ ^ (crc >> 8)] ^ (crc << 8)) & 0xFFFF;
    }
    return ~crc;
}
