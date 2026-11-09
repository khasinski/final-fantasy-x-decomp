/* tu_232 0x20cc98-0x20d058: low; meswin (config/tu_map.tsv) */
#include "common.h"
#include "ffx/q5.h"
#include "ffx/w6.h"
#include "ffx/r4.h"
#include "ffx/s4.h"
#include "ffx/t4.h"
#include "ffx/v4.h"

void *TODVDFileReadAuto(const char *name, int id)
{
    SysVt *vt = GetCD();
    int size;
    void *buf;

    vt->f10(name);
    size = vt->f14(id);
    if (size == 0) {
        return 0;
    }
    buf = user_malloc(size, 2, D_00570A38, 0xC67);
    if (buf == 0) {
        return 0;
    }
    func_0020CC20(name, id, buf);
    return buf;
}

void func_0020CD30(int a, int b, int c)
{
    D_0068F420 = GetCD();
    D_0068F420->f10(a);
    if (D_0068F420->f14(b) != 0) {
        D_0068F420->f0(b, c, 0, 0);
    }
}

int func_0020CDB8(void)
{
    return D_0068F420->f8(1);
}

INCLUDE_ASM("build/ee_asm/game/menu/to/meswin", func_0020CDE0);

int func_0020D000(int a)
{
    D_0078E498.f10(0x12);
    return D_0078E498.f14(a);
}

void *func_0020D048(void)
{
    return &D_00570A48;
}
