/* tu_000 0x1008d8-0x103c28: low; chr (config/tu_map.tsv) */
/* Module guess: src/chr/chr.c (character/entity object code; the 0x840-byte Chr pool
 * D_00300664/D_00300668, 64-bit flag word at +0x1A0). Chunks up to c_126830 are mostly
 * its accessors, the resource Handle table (D_0057F2C0) and a small command stream. */
#include "common.h"
#include "ffx/q0.h"
#include "ffx/r0.h"
#include "ffx/s0.h"
#include "ffx/u0.h"
#define func_00101528 v0_func_00101528 /* DEBT(TYPE): this header's guess conflicts with the TU */
#include "ffx/v0.h"
#undef func_00101528

INCLUDE_ASM("build/ee_asm/game/chr/chr", func_001008D8);

INCLUDE_ASM("build/ee_asm/game/chr/chr", Ch_ArcMapping);

INCLUDE_ASM("build/ee_asm/game/chr/chr", Ch_CbArcMapping);

INCLUDE_ASM("build/ee_asm/game/chr/chr", func_00101210);

INCLUDE_ASM("build/ee_asm/game/chr/chr", func_00101368);

char *sg_getdbname(int a)
{
    switch (a) {
    case 6:
    case 'k':
        return D_00568F60;
    case 0:
    case 'c':
        return D_00568F68;
    case 1:
    case 'm':
        return D_00568F70;
    case 2:
    case 'n':
        return D_00568F78;
    case 3:
    case 's':
        return D_00568F80;
    case 4:
    case 'w':
        return D_00568F88;
    case 5:
    case 'f':
        return D_00568F90;
    }
    return D_00568F00;
}

s32 func_001014C0(int c)
{
    switch (c) {
    case 'k':
        return 6;
    case 'c':
        return 0;
    case 'm':
        return 1;
    case 'n':
        return 2;
    case 's':
        return 3;
    case 'w':
        return 4;
    case 'f':
        return 5;
    }
    return -1;
}

s32 func_00101528(int i)
{
    switch (i) {
    case 6:
        return 'k';
    case 0:
        return 'c';
    case 1:
        return 'm';
    case 2:
        return 'n';
    case 3:
        return 's';
    case 4:
        return 'w';
    case 5:
        return 'f';
    }
    return '-';
}

INCLUDE_ASM("build/ee_asm/game/chr/chr", func_00101590);

Rec12C *Ch_BlkGetHandleFast(s32 id)
{
    s32 i;

    for (i = 0; i < 40; i++) {
        if (chrblk[i].w0 == id) {
            return &chrblk[i];
        }
    }
    return 0;
}

INCLUDE_ASM("build/ee_asm/game/chr/chr", Ch_BlkGetHandle);

u8 *func_00101B70(Chr *chr)
{
    return chr->param->bB8;
}

void Ch_BlkDispose(Rec12C *r)
{
    if (r->w0 != -1) {
        if (r->w70 & 1) {
            ChN_DisposeSystemMGRP(r->w0, 0);
            ChN_DisposeSystemMGRP(r->w0, 1);
            ChN_DisposeSystemMGRP(r->w0, 2);
            ChN_DisposeSystemMGRP(r->w0, 3);
            func_00111500(1, r->w0);
            if (r->w124 != 0) {
                func_0011D590(r->w124, 6);
                r->w124 = 0;
            }
        } else {
            func_0011D590(r->w4, 6);
            func_0011D590(r->w14, 6);
            func_0011D590(r->w10C, 6);
            func_0011D590(r->w108, 6);
        }
        if ((r->w70 & 3) == 3) {
            func_0011D590(r->w6C, 6);
            if (r->w70 & 4) {
                func_0011D590(r->w14, 6);
            }
        }
        func_0011D590(r->w11C, 6);
        func_0011D590(r->w68, 6);
        func_0011D590(r->w100, 6);
        r->w100 = 0;
        r->w0 = -1;
    }
}

Chr *func_00101CB0(s32 id)
{
    Chr *p;

    for (p = D_00300664; p != D_00300664 + D_00300668; p++) {
        if (p->active && p->h00 == id) {
            return p;
        }
    }
    return 0;
}

int ChN_DataDispose(int id, int quiet)
{
    Rec12C *r;
    s32 w;

    if (func_00101CB0(id) != 0) {
        if (quiet != 0) {
            yiAssert(0, D_005692A0, D_005692B8, ch_create_chrname(id));
        }
        return -1;
    }
    r = Ch_BlkGetHandleFast(id);
    if (r == 0) {
        return 0;
    }
    w = r->w0;
    Ch_BlkDispose(r);
    Sg_CacheDisposeChr(w);
    return 0;
}

void func_00101DA8(void)
{
    s32 i;

    for (i = 0; i < 40; i++) {
        if (chrblk[i].w0 != -1) {
            Ch_BlkDispose(&chrblk[i]);
        }
    }
}

void Ch_BlkDisposeHandle(int id)
{
    int i;
    Rec12C *r;

    for (i = 0; i < 40; i++) {
        r = &chrblk[i];
        if (r->w0 == id) {
            Ch_BlkDispose(r);
            Sg_CacheDisposeChr(id);
            break;
        }
    }
}

INCLUDE_ASM("build/ee_asm/game/chr/chr", Ch_ReadMotionViewer);

void Ch_ChrMemHeapSet(void)
{
    void *h = user_malloc(0x1000, 6, D_00568F00, 0x31A);

    SgRealloc((s32)h, 0); /* DEBT(TYPE): handle passed as int */
    func_0011BB08(h, D_00569320, -1);
    Sg_MemSetMoveHeapStartAddr((s32)h);
}

void Ch_DisposeAll(void)
{
    Chr *p;

    if (D_00300664 != 0) {
        for (p = D_00300664; p != D_00300664 + D_00300668; p++) {
            if (p->active) {
                Ch_Dispose((int)p); /* DEBT(CAST): prototype takes the character as int */
            }
        }
        func_0011D590((s32)D_00300664, 6);
        D_00300664 = 0;
        D_00300668 = 0;
    }
}

void Ch_Allocate_InitAll(int n)
{
    s32 i;

    D_0057CE80 = 0;
    D_00300668 = n;
    D_00300664 = user_malloc(n * 0x1080, 6, D_00568F00, 0x332);
    for (i = 0; i < D_00300668; i++) {
        D_00300664[i].active = 0;
    }
    func_0011BB08(D_00300664, D_00569338, -1);
    Ch_CalcNormalAutoInit();
}

Chr *func_00102220(Chr *pool)
{
    pool[D_00300668] = pool[0];
    return &pool[D_00300668];
}

INCLUDE_ASM("build/ee_asm/game/chr/chr", func_00102288);

s32 func_001029F0(void)
{
    Chr *p;
    s32 n = 0;

    for (p = D_00300664; p != D_00300664 + D_00300668; p++) {
        if (p->active) {
            n++;
        }
    }
    return n;
}

s32 Ch_GetName(Chr *chr)
{
    return chr->w04;
}

u16 func_00102A48(Chr *chr)
{
    return chr->h00;
}

void Ch_HandleRewind(void)
{
    D_0057CE84 = 0;
}

Chr *func_00102A60(void)
{
    Chr *c;

    while (D_0057CE84 < D_00300668) {
        c = &D_00300664[D_0057CE84++];
        if (c->active != 0) {
            return c;
        }
    }
    return 0;
}

void func_00102AC0(void)
{
    D_0057CE80 = 0x1;
}

void Ch_Allocate2(s32 id, s32 v)
{
    CHR_S32(func_00102B98(id), 0x19C) = v; /* DEBT(CAST) */
}

INCLUDE_ASM("build/ee_asm/game/chr/chr", func_00102AF8);

INCLUDE_ASM("build/ee_asm/game/chr/chr", func_00102B98);
INCLUDE_RODATA("build/ee_asm/game/chr/chr/rodata", jtbl_00569350);

int Ch_CheckHandle(Chr *chr)
{
    Chr *p;

    if (chr == 0) {
        return -1;
    }
    for (p = D_00300664; p != D_00300664 + D_00300668; p++) {
        if (p->active) {
            if (p == chr) {
                return 0;
            }
        }
    }
    return -1;
}

void func_001031F8(void)
{
    D_0057CE88 = 0x1;
}

INCLUDE_ASM("build/ee_asm/game/chr/chr", Ch_Dispose);

void func_00103358(Chr *chr, int d)
{
    ChrSlot *s = chr->slots;
    int i;

    for (i = 0; i < chr->hdr->h0A; i++, s++) {
        if ((u8 *)s->data != chr->u1E0) {
            s->data = (ChrSlotData *)((u8 *)s->data + d);
        }
    }
}

INCLUDE_ASM("build/ee_asm/game/chr/chr", Ch_MemMove);

s32 Ch_MemMove_Over(void)
{
    s32 n = 0;

    while (Ch_MemMove() != 0) {
        n++;
    }
    return n;
}

INCLUDE_ASM("build/ee_asm/game/chr/chr", Ch_InitAll);

void func_00103788(void)
{
    CALL0_func_0010C780();
    func_0010DF20();
    func_0010CA88();
    func_0010E2D0();
    Sg_MFIFOSync();
    func_0010C780(0);
    op_gs1_transfer();
    if (func_0010BE28()) {
        func_002D0AD0();
    }
}

void func_001037E8(void)
{
    s32 i;

    D_0057CE8C = 0;
    for (i = 0x7E; i >= 0; i--) {
        D_0057CE90[i].flag = 0;
    }
}

/* DEBT(TYPE): declared with a return type (shared header) but no value is returned; callers ignore it */
int Ch_FunctionHistoryDump(void)
{
    int idx = D_0057CE8C - 1;
    int i;

    for (i = 0; i < 0x7F; i++) {
        if (D_0057CE90[idx & 0x7F].flag == 0) {
            break;
        }
        idx--;
    }
}

INCLUDE_ASM("build/ee_asm/game/chr/chr", func_00103878);

s32 Sg_PacketGetPtr(void)
{
    return D_00303550;
}

s32 func_00103908(void)
{
    return 0x100000;
}

void Sg_InitAll(void)
{
    Sg_LoadVramResource();
    *(volatile u32 *)0x10000010 = 0x83; /* EE timer 0 mode register */
    *(volatile u32 *)0x10000810 = 0x83; /* EE timer 1 mode register */
    D_00303550 = 0x1F00000;
    if (ffx_debugmode) {
        func_2026AC0();
    }
    Sg_InitFilter();
    func_0011EA98();
    func_0011ECC8();
    func_00112F08(1);
    func_001037E8();
    func_00117608();
    Ch_DrawSetShadowMode(0);
}

INCLUDE_ASM("build/ee_asm/game/chr/chr", func_001039A0);

void Sg_EventjumpDispose(void)
{
    func_0011BD80(0);
    Ch_DisposeAll();
    func_00101DA8();
    Ch_DisposeAllMGRP();
    func_0010D720();
}

INCLUDE_ASM("build/ee_asm/game/chr/chr", func_00103AA8);
