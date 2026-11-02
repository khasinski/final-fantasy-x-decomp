/* tu_001 0x103c28-0x1041c8: low; unk_103C28 (config/tu_map.tsv) */
#include "common.h"
#include "ffx/q0.h"
#include "ffx/r0.h"
#include "ffx/s0.h"
#include "ffx/u0.h"
#include "ffx/v0.h"

/* DEBT(TYPE): global type guessed from the access width only */
void func_00103C28(s32 a, s32 b)
{
    D_0057D680 = a;
    D_0057D684 = b;
}

u32 func_00103C40(u32 *p)
{
    u32 i;

    for (i = 1; i <= p[0]; i++) {
        p[i] += (u32)p; /* offsets to addresses */
    }
    return p[0];
}

void func_00103C78(s32 v)
{
    D_0057D688 = v;
}

ResParse *func_00103C88(ResParse *out)
{
    s32 *hdr = (s32 *)D_0057D688; /* DEBT(CAST): the global holds the block address as an int */
    u8 *p = (u8 *)hdr;

    p += 8;
    if (hdr[0] != 0x10) {
        func_002EA328(-1);
    }
    out->flags = hdr[1];
    if (hdr[1] & 8) {
        out->p4 = p + 4;
        out->p8 = p + 0xC;
        p += *(s32 *)p;
    }
    out->pC = p + 4;
    out->p10 = p + 0xC;
    return out;
}

INCLUDE_ASM("build/ee_asm/game/chr/chr_103C28", func_00103D08);

void func_00104158(R0Obj104158 *p)
{
    func_002F8660(0);
    func_002DA610(0, 0);
    func_002DAC50(p->u10, p->w08);
    func_002DA610(0, 0);
    func_002DAC50(p->u70, p->w0C);
    func_002DA610(0, 0);
}

s32 func_001041B8(Chr *chr)
{
    return chr->w04;
}

void func_001041C0(void) {
}
