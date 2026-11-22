/* tu_347 0x2d98a8-0x2dba00: low; libgraph; split at 0x2d98a8: library split: 0x2D9730-0x2D98A8 is FFX platform glue (FFXIsPC, FFXGetLang, FFXSetVideoMode: Switch-port names), 0x2D98A8 is sceGsResetGraph (libgraph); tu_map's low boundary 0x2D9730 put both in one TU (config/tu_map.tsv) */
#include "common.h"
#include "vu0.h"
#include "ffx/q7.h"
#include "ffx/w11.h"
#include "ffx/g4.h"
#include "ffx/r7.h"
#include "ffx/v7.h"

typedef struct GsGParam {
    s16 interlace;
    s16 omode;
    s16 ffmode;
    s16 version;
    s32 vimode;
    s32 vblank_id;
} GsGParam;

u8 *func_002D9A38(void);
void func_002F8720(int mask);
void func_002F8E08(int irq);
void func_002F80E0(int irq, int id);
void func_002F7FE0(int interlace, int omode, int ffmode);

void func_002D98A8(s16 mode, s16 interlace, s16 omode, s16 ffmode)
{
    GsGParam *gp;

    switch (mode) {
    case 0:
        gp = (GsGParam *)func_002D9A38();
        *(volatile unsigned long *)0x12001000 = 0x200;
        gp->interlace = interlace;
        gp->omode = omode;
        gp->version = (s16)((*(volatile unsigned long *)0x12001000 >> 16) & 0xFF);
        func_002F8720(0xFF00);
        {
            register int ff __asm__("$3") = (ffmode != 0);
            __asm__ volatile("" : "+r"(ff));
            gp->ffmode = ff;
        }
        if (gp->vimode != 0) {
            func_002F8E08(2);
            func_002F80E0(2, gp->vblank_id);
            gp->vimode = 0;
            gp->vblank_id = 0;
        }
        func_002F7FE0(interlace & 1, omode & 0xFF, ffmode & 1);
        break;
    case 1:
        *(volatile unsigned long *)0x12001000 = 0x100;
        break;
    case 5:
        gp = (GsGParam *)func_002D9A38();
        gp->ffmode = (ffmode != 0);
        gp->interlace = interlace;
        gp->omode = omode;
        gp->version = (s16)((*(volatile unsigned long *)0x12001000 >> 16) & 0xFF);
        func_002F7FE0(interlace & 1, omode & 0xFF, ffmode & 1);
        break;
    }
}

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

int func_002D9EA8(unsigned long *p, s16 psm, s16 w, s16 h, s16 ztest, s16 zpsm)
{
    p[1] = 0x4C;
    p[0] = ((unsigned long)(((w + 63) >> 6) & 0x3F) << 16) | ((unsigned long)(psm & 0xF) << 24);
    p[3] = 0x4E;
    if (ztest == 0) {
        p[2] = func_002D9DE0(psm, w, h) | ((unsigned long)(zpsm & 0xF) << 24) | (1UL << 32);
    } else {
        p[2] = func_002D9DE0(psm, w, h) | ((unsigned long)(zpsm & 0xF) << 24);
    }
    p[5] = 0x18;
    p[4] = ((0x800UL - (s16)(w >> 1)) << 4) | ((0x800UL - (s16)(h >> 1)) << 36);
    p[7] = 0x40;
    p[6] = ((unsigned long)(w - 1) << 16) | ((unsigned long)(s16)(h - 1) << 48);
    p[9] = 0x1A;
    p[8] |= 1;
    p[11] = 0x46;
    p[10] |= 1;
    p[13] = 0x45;
    if (psm & 2) {
        p[12] |= 1;
    } else {
        p[12] &= ~1UL;
    }
    p[15] = 0x47;
    if (ztest != 0) {
        p[14] = ((unsigned long)(ztest & 3) << 17) | 0x10000;
    } else {
        p[14] = 0x30000;
    }
    SYNC();
    return 8;
}

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

typedef struct {
    unsigned long NLOOP : 15;
    unsigned long EOP : 1;
    unsigned long pad16 : 16;
    unsigned long id : 14;
    unsigned long PRE : 1;
    unsigned long PRIM : 11;
    unsigned long FLG : 2;
    unsigned long NREG : 4;
    unsigned long REGS0 : 4;
    unsigned long REGS1 : 4;
    unsigned long REGS2 : 4;
    unsigned long REGS3 : 4;
    unsigned long REGS4 : 4;
    unsigned long REGS5 : 4;
    unsigned long REGS6 : 4;
    unsigned long REGS7 : 4;
    unsigned long REGS8 : 4;
    unsigned long REGS9 : 4;
    unsigned long REGS10 : 4;
    unsigned long REGS11 : 4;
    unsigned long REGS12 : 4;
    unsigned long REGS13 : 4;
    unsigned long REGS14 : 4;
    unsigned long REGS15 : 4;
} GsGifTag;

typedef struct {
    unsigned long FBP : 9;
    unsigned long pad : 55;
} GsFbpReg;

typedef struct {
    unsigned long pmode;
    unsigned long smode2;
    GsFbpReg dispfb;
    unsigned long display;
    unsigned long bgcolor;
} GsDispEnv;

typedef struct {
    GsDispEnv disp[2];
    GsGifTag gif0;
    GsFbpReg frame1_0;
    unsigned long draw0[15];
    unsigned long clear0[12];
    GsGifTag gif1;
    unsigned long draw1[16];
    unsigned long clear1[12];
} GsDBuff;

void func_002DA280(GsDBuff *db, s16 psm, s16 w, s16 h, s16 ztest, s16 zpsm, s16 clear)
{
    u8 *gp = func_002D9A38();
    s16 fbp;

    func_002D9AB0((unsigned long *)&db->disp[0], psm, w, h, 0, 0);
    func_002D9AB0((unsigned long *)&db->disp[1], psm, w, h, 0, 0);
    func_002D9EA8((unsigned long *)&db->frame1_0, psm, w, h, ztest, zpsm);
    func_002D9EA8(db->draw1, psm, w, h, ztest, zpsm);
    if (clear) {
        s16 x = 0x800 - (w >> 1);
        s16 y = 0x800 - (h >> 1);
        func_002DA090(db->clear0, ztest, x, y, w, h, 0, 0, 0, 0, 0);
        func_002DA090(db->clear1, ztest, x, y, w, h, 0, 0, 0, 0, 0);
    }
    *(u_long128 *)&db->gif0 = 0;
    *(u_long128 *)&db->gif1 = 0;
    db->gif0.NLOOP = clear ? 14 : 8;
    db->gif0.EOP = 1;
    db->gif0.NREG = 1;
    db->gif0.REGS0 = 0xE;
    db->gif1.NLOOP = clear ? 14 : 8;
    db->gif1.EOP = 1;
    db->gif1.NREG = 1;
    db->gif1.REGS0 = 0xE;
    fbp = func_002D9DE0(psm, w, h);
    if ((*(unsigned long *)gp & 0x0000ffff0000ffffUL) == 0x0000000100000001UL || *(s16 *)gp == 0) {
        s16 half = fbp >> 1;
        db->disp[1].dispfb.FBP = half;
        db->frame1_0.FBP = fbp >> 1;
    }
}

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

typedef struct {
    u32 vifcode[4];
    GsGifTag giftag;
    unsigned long bitbltbuf;
    unsigned long bitbltbufaddr;
    unsigned long trxpos;
    unsigned long trxposaddr;
    unsigned long trxreg;
    unsigned long trxregaddr;
    unsigned long finish;
    unsigned long finishaddr;
    unsigned long trxdir;
    unsigned long trxdiraddr;
} GsStoreImage;

int func_002DAB10(GsStoreImage *p, s16 sbp, s16 sbw, s16 spsm, s16 x, s16 y, s16 w, s16 h)
{
    *(u_long128 *)&p->giftag = 0;
    p->vifcode[0] = 0;
    p->vifcode[1] = 0x06008000;
    p->vifcode[2] = 0x13000000;
    p->vifcode[3] = 0x50000006;
    p->giftag.NLOOP = 5;
    p->giftag.EOP = 1;
    p->giftag.NREG = 1;
    p->giftag.REGS0 = 0xE;
    p->bitbltbuf = ((unsigned long)sbp) | ((unsigned long)sbw << 16) | ((unsigned long)spsm << 24);
    p->bitbltbufaddr = 0x50;
    p->trxpos = ((unsigned long)x) | ((unsigned long)y << 16);
    p->trxposaddr = 0x51;
    p->trxreg = ((unsigned long)w) | ((unsigned long)h << 32);
    p->trxregaddr = 0x52;
    p->finish = 0;
    p->finishaddr = 0x61;
    p->trxdir = 1;
    p->trxdiraddr = 0x53;
    SYNC();
    return 7;
}

extern char D_005767A0[];

int func_002DAC50(void *packet, void *src)
{
    unsigned int timeout = 0;

    while (*(volatile unsigned int *)0x1000A000 & 0x100) {
        if (timeout++ > 0x1000000U) {
            func_002EF240(D_005767A0);
            return -1;
        }
    }
    *(volatile unsigned int *)0x1000A020 = 6;
    if (((unsigned int)packet & 0x70000000) == 0x70000000) {
        *(volatile unsigned int *)0x1000A010 = ((unsigned int)packet & 0xfffffff) | 0x80000000;
    } else {
        *(volatile unsigned int *)0x1000A010 = (unsigned int)packet & 0xfffffff;
    }
    *(volatile unsigned int *)0x1000A000 = 0x101;
    while (*(volatile unsigned int *)0x1000A000 & 0x100) {
        if (timeout++ > 0x1000000U) {
            func_002EF240(D_005767A0);
            return -1;
        }
    }
    *(volatile unsigned int *)0x1000A020 = (int)(*((unsigned long *)packet + 10) & 0x7fff);
    if (((unsigned int)src & 0x70000000) == 0x70000000) {
        *(volatile unsigned int *)0x1000A010 = ((unsigned int)src & 0xfffffff) | 0x80000000;
    } else {
        *(volatile unsigned int *)0x1000A010 = (unsigned int)src & 0xfffffff;
    }
    *(volatile unsigned int *)0x1000A000 = 0x101;
    return 0;
}

INCLUDE_ASM("build/ee_asm/sdk/libgraph/libgraph", func_002DADD0);
INCLUDE_RODATA("build/ee_asm/sdk/libgraph/libgraph/rodata", jtbl_005768C0);

int func_002DB460(unsigned long *p, s16 psm, s16 w, s16 h, s16 ztest, s16 zpsm)
{
    p[1] = 0x4D;
    p[0] = ((unsigned long)((w >> 6) & 0x3F) << 16) | ((unsigned long)(psm & 0xF) << 24);
    p[3] = 0x4F;
    if (ztest == 0) {
        p[2] = func_002D9DE0(psm, w, h) | ((unsigned long)(zpsm & 0xF) << 24) | (1UL << 32);
    } else {
        p[2] = func_002D9DE0(psm, w, h) | ((unsigned long)(zpsm & 0xF) << 24);
    }
    p[5] = 0x19;
    p[4] = ((0x800UL - (s16)(w >> 1)) << 4) | ((0x800UL - (s16)(h >> 1)) << 36);
    p[7] = 0x41;
    p[6] = ((unsigned long)(w - 1) << 16) | ((unsigned long)(s16)(h - 1) << 48);
    p[9] = 0x1A;
    p[8] |= 1;
    p[11] = 0x46;
    p[10] |= 1;
    p[13] = 0x45;
    if (psm & 2) {
        p[12] |= 1;
    } else {
        p[12] &= ~1UL;
    }
    p[15] = 0x48;
    if (ztest != 0) {
        p[14] = ((unsigned long)(ztest & 3) << 17) | 0x10000;
    } else {
        p[14] = 0x30000;
    }
    SYNC();
    return 8;
}

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

typedef struct DmaEnv {
    u8 sts;
    u8 std;
    u8 mfd;
    u8 rcycle;
    u16 express;
    u16 notify;
    u16 sqwc;
    u16 tqwc;
    void *rbadr;
    u32 rbsiz;
} DmaEnv;

extern u8 D_005662B8[];
extern u8 D_005662C8[];
extern u8 D_005662D8[];

int func_002DB7F0(void *arg)
{
    DmaEnv *env = arg;
    u32 ctrl, pcr, sqwc, rbsiz, rbadr;

    ctrl = *(volatile u32 *)0x1000E000;
    pcr = *(volatile u32 *)0x1000E020;
    sqwc = *(volatile u32 *)0x1000E030;
    rbadr = *(volatile u32 *)0x1000E050;
    rbsiz = *(volatile u32 *)0x1000E040;
    if (env->sts >= 10) {
        return -1;
    }
    if (env->std >= 10) {
        return -2;
    }
    if (env->mfd >= 10) {
        return -3;
    }
    if (env->rcycle >= 7) {
        return -4;
    }
    ctrl = (ctrl & 0xFFFFFFCF) | (D_005662B8[env->sts] << 4);
    ctrl = (ctrl & 0xFFFFFF3F) | (D_005662C8[env->std] << 6);
    ctrl = (ctrl & 0xFFFFFFF3) | (D_005662D8[env->mfd] << 2);
    if (env->rcycle != 0) {
        ctrl |= 2;
        ctrl = (ctrl & 0xFFFFFCFF) | ((env->rcycle - 1) << 8);
    } else {
        ctrl &= 0xFFFFFFFD;
    }
    pcr = (env->express << 16) | env->notify;
    sqwc = (env->tqwc << 16) | env->sqwc;
    rbadr = (u32)env->rbadr;
    rbsiz = env->rbsiz;
    *(volatile u32 *)0x1000E000 = ctrl;
    *(volatile u32 *)0x1000E020 = pcr;
    *(volatile u32 *)0x1000E030 = sqwc;
    *(volatile u32 *)0x1000E050 = rbadr;
    *(volatile u32 *)0x1000E040 = rbsiz;
    D_005662E8 = *(R7Blk20 *)env;
    return 0;
}

R7Blk20 *func_002DB9C8(R7Blk20 *d)
{
    *d = D_005662E8;
    return d;
}
