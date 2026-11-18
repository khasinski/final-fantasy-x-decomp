/* tu_347 0x2d98a8-0x2dba00: low; libgraph; split at 0x2d98a8: library split: 0x2D9730-0x2D98A8 is FFX platform glue (FFXIsPC, FFXGetLang, FFXSetVideoMode: Switch-port names), 0x2D98A8 is sceGsResetGraph (libgraph); tu_map's low boundary 0x2D9730 put both in one TU (config/tu_map.tsv) */
#include "common.h"
#include "ffx/q7.h"
#include "ffx/w11.h"
#include "ffx/g4.h"
#include "ffx/r7.h"
#include "ffx/v7.h"

INCLUDE_ASM("build/ee_asm/sdk/libgraph/libgraph", func_002D98A8);

u8 *func_002D9A38(void)
{
    return D_00566210;
}

INCLUDE_ASM("build/ee_asm/sdk/libgraph/libgraph", func_002D9A48);

INCLUDE_ASM("build/ee_asm/sdk/libgraph/libgraph", func_002D9AB0);

void func_002D9D20(void *data) {
    /* DEBT(CAST): buffer and MMIO registers use 64-bit GS words. */
    unsigned long *regs = data;
    if (*(s16 *)(func_002D9A38() + 6) == 1) {
        *(volatile unsigned long *)0x12000000 = regs[0];
        *(volatile unsigned long *)0x12000070 = regs[2];
        *(volatile unsigned long *)0x12000080 = regs[3];
        *(volatile unsigned long *)0x120000C0 = regs[4];
    } else {
        *(volatile unsigned long *)0x12000000 = regs[0];
        *(volatile unsigned long *)0x12000020 = regs[1];
        *(volatile unsigned long *)0x12000090 = regs[2];
        *(volatile unsigned long *)0x120000A0 = regs[3];
        *(volatile unsigned long *)0x120000E0 = regs[4];
    }
}

s16 func_002D9DE0(s16 format, s16 width, s16 height) {
    u8 *state = func_002D9A38();
    int columns = (width + 63) / 64;
    int rows;
    if (format & 2) rows = (height + 63) / 64;
    else rows = (height + 31) / 32;
    /* DEBT(CAST): read the packed GS mode fields as one 64-bit word. */
    if ((*(unsigned long *)state & 0x0000ffff0000ffffUL) == 1) return columns * rows;
    return columns * rows * 2;
}

INCLUDE_ASM("build/ee_asm/sdk/libgraph/libgraph", func_002D9EA8);

int func_002DA090(unsigned long *p, s16 test, s16 x, s16 y, s16 width, s16 height, u8 r, u8 g, u8 b, u8 a, u32 z) {
    unsigned long color = r | ((unsigned long)g << 8) | ((unsigned long)b << 16) | ((unsigned long)a << 24) | 0x3f80000000000000UL;
    unsigned long start = (x * 16) | ((unsigned long)(y * 16) << 16) | ((unsigned long)z << 32);
    unsigned long end = ((x + width) * 16) | ((unsigned long)((y + height) * 16) << 16) | ((unsigned long)z << 32);
    p[1]=0x47;
    p[0]=0x30000;
    p[2]=6;
    p[3]=0;
    p[5]=1;
    p[4]=color;
    p[6]=start;
    p[7]=5;
    p[9]=5;
    p[8]=end;
    p[11]=0x47;
    if (test) {
        p[10] = ((unsigned long)(test & 3) << 17) | 0x10000;
    } else {
        p[10] = 0x30000;
    }
    /* Publish the completed packet before the DMA consumer reads it. */
    SYNC();
    return 6;
}

extern char D_005764B8[];

int func_002DA198(void *packet) {
    /* DEBT(CAST): EE hardware registers and packet addresses. */
    unsigned int timeout = 0;
    while (*(volatile unsigned int *)0x1000A000 & 0x100) {
        if (timeout++ > 0x1000000U) {
            func_002EF240(D_005764B8);
            return -1;
        }
    }
    *(volatile unsigned int *)0x1000A020 = (int)(*(unsigned long *)packet & 0x7fff) + 1;
    if (((unsigned int)packet & 0x70000000) == 0x70000000) {
        *(volatile unsigned int *)0x1000A010 = ((unsigned int)packet & 0xfffffff) | 0x80000000;
    } else {
        *(volatile unsigned int *)0x1000A010 = (unsigned int)packet & 0xfffffff;
    }
    *(volatile unsigned int *)0x1000A000 = 0x101;
    return 0;
}

INCLUDE_ASM("build/ee_asm/sdk/libgraph/libgraph", func_002DA280);

/* Module: sound/vu glue */

int func_002DA518(u8 *base, int side)
{
    int ret;

    side &= 1;
    func_002D9D20(base + side * 0x28);
    if (side != 0) {
        ret = func_002DA198(base + 0x140);
    } else {
        ret = func_002DA198(base + 0x50);
    }
    return ret;
}

void func_002F8860(void);
long func_002F88A0(void);

int func_002DA578(void)
{
    u8 *state = func_002D9A38();

    if (*(int *)(state + 8) == 0) {
        func_002F8860();
        if (*(s16 *)state == 1) {
            return (int)((*(volatile unsigned long *)0x12001000 >> 13) & 1);
        }
    } else {
        long bit = (func_002F88A0() >> 13) & 1;
        if (*(s16 *)state == 1) {
            return (int)bit;
        }
    }
    return 1;
}

INCLUDE_ASM("build/ee_asm/sdk/libgraph/libgraph", func_002DA610);

INCLUDE_ASM("build/ee_asm/sdk/libgraph/libgraph", func_002DA928);
INCLUDE_RODATA("build/ee_asm/sdk/libgraph/libgraph/rodata", jtbl_005766B0);

INCLUDE_ASM("build/ee_asm/sdk/libgraph/libgraph", func_002DAB10);

INCLUDE_ASM("build/ee_asm/sdk/libgraph/libgraph", func_002DAC50);

INCLUDE_ASM("build/ee_asm/sdk/libgraph/libgraph", func_002DADD0);
INCLUDE_RODATA("build/ee_asm/sdk/libgraph/libgraph/rodata", jtbl_005768C0);

INCLUDE_ASM("build/ee_asm/sdk/libgraph/libgraph", func_002DB460);

/* Module: sound/misc glue, VU0 helpers */

int func_002DB640(u8 *base, int side)
{
    int ret;

    side &= 1;
    func_002D9D20(base + side * 0x28);
    if (side != 0) {
        ret = func_002DA198(base + 0x1C0);
    } else {
        ret = func_002DA198(base + 0x50);
    }
    return ret;
}

void func_002DB6A0(u8 *p, int n)
{
    while (n-- != 0) {
        *p++ = 0;
    }
}

u32 *func_002DB6D8(int id)
{
    if ((u32)id < 10) {
        return (u32 *)D_00566250[id]; /* DEBT(TYPE): callers take the channel as u32 * */
    }
    return 0;
}

int func_002DB700(int mode)
{
    u32 env[5];
    int old = V7_D_CTRL & 1;
    int i;

    for (i = 0; i < 10; i++) {
        if (D_00566290[i] != 0) {
            volatile V7DmaChan *ch = D_00566250[i];
            ch->sadr = 0;
            ch->chcr = 0;
            ch->tadr = 0;
            ch->madr = 0;
            ch->asr1 = 0;
            ch->asr0 = 0;
        }
    }
    V7_D_STAT = 0xFF1F;
    V7_D_STAT_W = V7_D_STAT & 0xFF1F0000;
    func_002DB6A0((u8 *)env, sizeof(env));
    func_002DB7F0(env);
    if (mode == 1) {
        V7_D_CTRL |= 1;
    }
    return old;
}

int func_002DB7E0(int v)
{
    int old = D_00566278;

    D_00566278 = v;
    return old;
}

INCLUDE_ASM("build/ee_asm/sdk/libgraph/libgraph", func_002DB7F0);

R7Blk20 *func_002DB9C8(R7Blk20 *d)
{
    *d = D_005662E8;
    return d;
}
