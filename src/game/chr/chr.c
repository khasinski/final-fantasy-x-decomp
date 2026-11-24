/* tu_000 0x1008d8-0x103c28: low; chr (config/tu_map.tsv) */
/* Module guess: src/chr/chr.c (character/entity object code; the 0x840-byte Chr pool
 * D_00300664/D_00300668, 64-bit flag word at +0x1A0). Chunks up to c_126830 are mostly
 * its accessors, the resource Handle table (D_0057F2C0) and a small command stream. */
#include "common.h"
#include "vu0.h"
#include "ffx/q0.h"
#include "ffx/r0.h"
#include "ffx/s0.h"
#include "ffx/u0.h"
#include "ffx/v0.h"

INCLUDE_ASM("build/ee_asm/game/chr/chr", func_001008D8);

typedef struct {
    s32 ptr;
    u32 count;
} ArcEnt;

typedef struct {
    s32 base;
    u32 count;
    s32 pad8;
    s32 padC;
    ArcEnt ents[5];
} ArcHdr;

void func_001001B8(s32);
void Ch_TexDataMapping(s32);
void func_001053C0(ArcEnt *, s32);

void Ch_ArcMapping(ArcHdr *arc)
{
    s32 diff = (s32)arc - arc->base;
    s32 i;

    if (diff != 0) {
        arc->base = (s32)arc;
        for (i = 0; (u32)i < arc->count; i++) {
            if (arc->ents[i].ptr != 0) {
                arc->ents[i].ptr += diff;
                switch (i) {
                case 0:
                    func_001001B8(arc->ents[0].ptr);
                    break;
                case 4:
                    func_001053C0(&arc->ents[4], diff);
                    break;
                case 1:
                    Ch_TexDataMapping(arc->ents[1].ptr);
                    break;
                }
            }
        }
    }
}

typedef struct {
    s32 w00;
    float f04;
    float f08;
    float f0C;
    float f10;
    float f14;
    float f18;
    float f1C;
    float f20;
    u8 b24;
    u8 b25;
    u8 b26;
    u8 b27;
    float f28;
    float f2C;
    float f30;
    float f34;
    float f38;
    float f3C;
    u8 b40;
    u8 b41;
    u8 b42;
    u8 b43;
    u8 b44;
    u8 b45;
} CbParamData;

typedef struct {
    s32 base;
    u32 count;
    s32 pad08;
    s32 pad0C;
    void *p10;
    s32 pad14;
    u32 p18;
    u32 w1C;
    u8 pad20[0x10];
    u32 p30;
    u32 w34;
    u8 pad38[0x20];
    CbParamData *p58;
    s32 pad5C;
    void *p60;
} CbArcHdr;

typedef struct {
    s32 w00;
    void *p04;
    u8 pad08[0xC];
    u32 p14;
    u32 w18;
    float f1C;
    float f20;
    float f24;
    float f28;
    float f2C;
    float f30;
    float f34;
    float f38;
    float f3C;
    u8 b40;
    u8 b41;
    u8 b42;
    u8 b43;
    float f44;
    float f48;
    float f4C;
    float f50;
    s32 w54;
    float f58;
    float f5C;
    u8 b60;
    u8 b61;
    u8 b62;
    u8 b63;
    u8 b64;
    u8 b65;
    u8 pad66[0x6];
    u32 p6C;
    u8 pad70[0xA0];
    u16 h110;
    u16 pad112;
    void *p114;
    u8 pad118[0x8];
    void *p120;
} CbRecView;

void Ch_CbArcMapping(Rec12C *r_in, s32 arc_in)
{
    CbRecView *r = (CbRecView *)r_in;
    CbArcHdr *arc = (CbArcHdr *)arc_in;

    Ch_ArcMapping((ArcHdr *)arc);
    r->p14 = arc->p18;
    r->p04 = arc->p10;
    r->w18 = arc->w1C;
    r->p6C = (u32)arc;
    r->h110 = arc->w34;
    r->p114 = (void *)arc->p30;
    if (arc->count < 11) {
        r->p120 = 0;
    } else {
        r->p120 = arc->p60;
    }
    r->f1C = 1.0f;
    r->f20 = 1.0f;
    r->f24 = 1.0f;
    r->f2C = 8.0f;
    r->f30 = 1.0f;
    r->f34 = 1.0f;
    r->f38 = 1.0f;
    r->b43 = 1;
    r->b40 = 0;
    r->b42 = 2;
    r->f44 = r->f48 = r->f4C = 0.0f;
    r->f50 = 1.0f;
    r->f58 = 1.0f;
    r->f5C = 2.0f;
    r->b60 = 0x80;
    r->b61 = 0x80;
    r->b62 = 0x80;
    r->b63 = 0x7F;
    r->b64 = 0;
    r->b65 = 0;
    if (((r->w00 & 0xF000) >> 12) == 2) {
        r->b40 = 1;
        r->b43 = 0;
    }
    r->w54 = 0;
    r->f3C = 1000.0f;
    if (arc->count >= 10) {
        CbParamData *pa = arc->p58;

        r->f30 = pa->f0C;
        r->w54 = pa->w00;
        r->f3C = 1000.0f / r->f30;
        r->f28 = pa->f14;
        r->f2C = pa->f08;
        r->f1C = pa->f04;
        r->f20 = pa->f10;
        r->f24 = pa->f18;
        r->f34 = pa->f1C;
        r->f38 = pa->f20;
        r->b40 = pa->b24;
        r->b42 = pa->b26;
        r->b43 = pa->b27;
        r->f44 = pa->f28;
        r->f48 = pa->f2C;
        r->f4C = pa->f30;
        r->f50 = pa->f34;
        if (pa->w00 >= 0x1624) {
            r->f58 = pa->f38;
            r->f5C = pa->f3C;
            r->b60 = pa->b40;
            r->b61 = pa->b41;
            r->b62 = pa->b42;
            r->b63 = pa->b43;
            r->b64 = pa->b44;
            r->b65 = pa->b45;
        }
    }
}

typedef struct {
    s32 w0;
    u8 pad04[0x6C];
    s32 w70;
    u8 pad74[0xAC];
    s32 w120;
    s32 w124;
    s32 w128;
} Rec12CView;

extern char D_00308100[];
extern char D_00568F50[];
void Ch_CbArcMapping(Rec12C *r, s32 arc);
s32 Sg_MemGetSize(s32 a);

Rec12C *func_00101210(s32 id, s32 arc)
{
    Rec12CView *r = 0;
    s32 i;

    for (i = 0; i < 40; i++) {
        if (chrblk[i].w0 == -1) {
            r = (Rec12CView *)&chrblk[i];
            break;
        }
    }
    CALL_func_002ED0E0_INT((u8 *)r, sizeof(Rec12C));
    r->w0 = id;
    r->w70 |= 1;
    Ch_CbArcMapping((Rec12C *)r, arc);
    if (r->w120 != 0) {
        s32 size = Sg_MemGetSize(arc) - (r->w120 - arc);

        r->w128 = size;
        r->w124 = (s32)user_malloc(size, 6, D_00568F00, 0x19E);
        func_002F0008(D_00308100, D_00568F50, ch_create_chrname(id));
        func_0011BB08((void *)r->w124, D_00308100, -1);
        func_0011CFB8(r->w124, 5);
        func_002EEF1C(r->w124, r->w120, r->w128);
    }
    return (Rec12C *)r;
}

Rec12C *func_00101368(s32 id, s32 a1, s32 a2)
{
    register u8 *gp __asm__("$28");
    Rec12C *r = 0;
    s32 i;

    for (i = 0; i < 40; i++) {
        if (chrblk[i].w0 == -1) {
            r = &chrblk[i];
            break;
        }
    }
    CALL_func_002ED0E0_INT((u8 *)r, sizeof(Rec12C));
    r->w0 = id;
    r->w4 = a1;
    func_001001B8(a1);
    {
        register float f1 __asm__("$f1") = 1.0f;
        register Rec12C *ret __asm__("$2") = r;
        register float f0 __asm__("$f0");
        __asm__ volatile("" : "+f"(f1), "+r"(ret));
        f0 = *(float *)(gp - 0x7FC0);
        r->w14 = a2;
        *(float *)((u8 *)r + 0x34) = f1;
        __asm__ volatile("" : "+f"(f0) :: "memory");
        *(float *)((u8 *)r + 0x38) = f0;
        __asm__ volatile("" ::: "memory");
        *(float *)((u8 *)r + 0x30) = f1;
        return ret;
    }
}

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

extern s32 D_0057CD88;
extern char *D_0057CD90[];
char *func_0011D6D0(char *s);

s32 func_00101590(char *s4, char *s2)
{
    s32 i;
    char *p;

    for (i = 0; i < D_0057CD88; i++) {
        if (func_002F05E8(D_0057CD90[i * 3], s2) == 0 &&
            func_002F05E8(D_0057CD90[i * 3 + 2], s4) == 0) {
            return i + 0xF000;
        }
    }
    i = D_0057CD88++;
    D_0057CD90[i * 3] = func_0011D6D0(s2);
    p = func_0011D6D0(s2);
    D_0057CD90[i * 3 + 1] = p;
    if ((u32)(p[0] - 'a') < 26) {
        p[0] -= 0x20;
    }
    D_0057CD90[i * 3 + 2] = func_0011D6D0(s4);
    return i + 0xF000;
}

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

typedef struct {
    s32 id;
    u8 pad04[0x2C];
    char s30[0x50];
} ChrDbEnt;

extern char D_00569200[];
extern char D_00569220[];
extern char D_00569228[];
extern char D_00569238[];
extern char D_00569248[];
extern char D_00569260[];
extern char D_00569270[];
extern char D_00569280[];
extern ChrDbEnt *_db_D_0057CD48[] __asm__("D_0057CD48");
extern s32 D_0057CD68[];
extern s8 ffx_debugmode;

void func_0011C348(s32 a);
void Ch_TexDataMapping(s32 a);
void Chb_AttachMotionTBL_OLD(Rec12C *r);
char *ch_create_name(s32 id);
char *ch_create_section(s32 id);
s32 Cache_Exist3(s32 a, s32 id);
void Ch_DataRead(s32 id);
void func_00113480(s32 a);
s32 Cache_CheckYet(s32 a, s32 id);

Rec12C *Ch_BlkGetHandle(s32 id)
{
    char buf0[0x100];
    char buf1[0x40];
    Rec12C *r;
    s32 p;
    s32 tex;
    char *name;
    char *sec;
    char *tag;

    r = Ch_BlkGetHandleFast(id);
    if (r != 0) {
        return r;
    }
    {
        register ChrDbEnt *found __asm__("$11") = 0;
        if ((id & 0xF000) == 0xF000) {
        register s32 idx __asm__("$9") = id & 0xFFF;
        register char *fmt __asm__("$5");
        register char *arg2 __asm__("$6");
        register char *arg3 __asm__("$7");
        register s32 off __asm__("$4");
        off = idx * 12;
        name = *(char **)((u8 *)D_0057CD90 + off);
        sec = D_0057CD90[idx * 3 + 2];
        func_002F0008(buf1, D_00569200, sec, name);
        tag = D_00569220;
        func_002F0008(buf0, D_00569228, buf1, name);
        p = Sg_PcRead(buf0);
        if (p != 0) {
            r = func_00101210(id, p);
            *(char **)((u8 *)r + 0xB4) = tag;
            r->w70 |= 2;
            func_002F0008(buf0, D_00569238, buf1, name);
            func_0011C348(0x80);
            tex = Sg_PcRead(buf0);
            if (tex != 0) {
                register s32 f __asm__("$3");
                func_0011BB08((void *)tex, buf0, -1);
                Ch_TexDataMapping(tex);
                f = r->w70;
                r->w14 = tex;
                r->w70 = f | 4;
            }
            func_002F072C((char *)r + 0xB8, buf1);
            func_002F072C((char *)r + 0x71, name);
            func_002F072C((char *)r + 0x91, sec);
            fmt = D_00569248;
            arg2 = (char *)r + 0x91;
            arg3 = (char *)r + 0x71;
        } else {
            func_002F0008(buf0, D_00569260, buf1, name);
            p = Sg_PcRead(buf0);
            if (p == 0) {
                return 0;
            }
            func_0011BB08((void *)p, buf0, -1);
            func_002F0008(buf0, D_00569238, buf1, name);
            func_0011C348(0x80);
            tex = Sg_PcRead(buf0);
            func_0011BB08((void *)tex, buf0, -1);
            Ch_TexDataMapping(tex);
            r = func_00101368(id, p, tex);
            *(char **)((u8 *)r + 0xB4) = tag;
            func_002F072C((char *)r + 0xB8, buf1);
            func_002F072C((char *)r + 0x71, name);
            func_002F072C((char *)r + 0x91, sec);
            Chb_AttachMotionTBL_OLD(r);
            fmt = D_00569270;
            arg2 = sec;
            arg3 = name;
        }
        func_002F0008(buf0, fmt, arg2, arg3);
        func_0011BB08((void *)p, buf0, -1);
        return r;
    } else {
        if (ffx_debugmode != 0) {
            s32 grp = id >> 12;
            register s32 sub __asm__("$9") = id & 0xFFF;
            s32 i;
            for (i = 0; i < D_0057CD68[grp]; i++) {
                if (_db_D_0057CD48[grp][i].id == sub) {
                    found = &_db_D_0057CD48[grp][i];
                }
            }
            if (found == 0) {
                return 0;
            }
            tag = found->s30;
        } else {
            tag = D_00568F00;
        }
        name = ch_create_name(id);
        sec = ch_create_section(id);
        p = Cache_Exist3(1, id);
        if (p == 0) {
            Ch_DataRead(id);
            func_00113480(0);
            p = Cache_Exist3(1, id);
            if (p == 0) {
                return 0;
            }
        }
        if (Cache_CheckYet(1, id) == 1) {
            func_00113480(0);
        }
        Cache_Use(1, id);
        r = func_00101210(id, p);
        *(char **)((u8 *)r + 0xB4) = tag;
        if (ffx_debugmode != 0) {
            func_002F0008(buf1, D_00569280, sec, name);
            func_002F072C((char *)r + 0xB8, buf1);
        } else {
            *((u8 *)r + 0xB8) = D_00568F00[0];
        }
        func_002F072C((char *)r + 0x71, ch_create_name(id));
        func_002F072C((char *)r + 0x91, ch_create_section(id));
        return r;
    }
    }
}

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

extern char D_005692E8[];
extern char D_005692F8[];

void Ch_ReadMotionViewer(Chr *chr, char *a1, char *a2, char *a3)
{
    char buf[0x80];
    u8 *blk;
    register u8 *slot __asm__("$20");
    u16 *p;
    s32 id;
    s32 i;
    s16 **tbl;
    register char *a2_r __asm__("$21") = a2;
    register char *a3_r __asm__("$19") = a3;

    chr->flags &= ~(1ULL << 31);
    blk = *(u8 **)((u8 *)chr + 0x1D0);
    if (((s8 *)blk)[0xF8] != 0) {
        return;
    }
    if ((chr->h00 & 0xF000) == 0xF000) {
        func_002F0008(buf, D_005692E8, blk + 0xB8);
    } else {
        func_002F0008(buf, D_005692F8, a1, a2_r, a3_r);
    }
    p = (u16 *)Sg_PcRead((s32)buf);
    if (p == 0) {
        return;
    }
    slot = blk + 0xFC;
    __asm__("" : "+r"(slot));
    if (*(s32 *)(slot + 4) != 0) {
        func_0011D590(*(s32 *)(slot + 4), 6);
        *(s32 *)(slot + 4) = 0;
    }
    *(u16 **)(slot + 4) = p;
    *(char **)(slot + 8) = func_0011D6D0(a3_r);
    if (p[4] < 2) {
        u16 h = p[0];
        register u64 bit31 __asm__("$4") = 1ULL << 31;
        register u16 c256 __asm__("$3") = 0x100;
        __asm__ volatile("" : "+r"(h), "+r"(bit31), "+r"(c256));
        *(s32 *)((u8 *)chr + 0x74C) = 0;
        __asm__ volatile("" ::: "memory");
        *(u16 *)(blk + 0xFC) = h;
        *(u16 *)((u8 *)chr + 0x760) = c256;
        __asm__ volatile("" ::: "memory");
        chr->flags |= bit31;
    } else {
        func_00112A70(chr, *(void **)(slot + 4), 0, 0, -1);
    }
    id = (func_001014C0(a2_r[0]) << 12) | func_002ED098(a2_r + 1);
    *(s32 *)((u8 *)chr + 0x764) = 0;
    tbl = *(s16 ***)(blk + 0x114);
    if (tbl != 0) {
        for (i = 0; i < *(s16 *)(blk + 0x110); i++) {
            if (tbl[i][0] == id) {
                *(s16 **)((u8 *)chr + 0x764) = tbl[i];
                break;
            }
        }
    }
    {
        register u64 f __asm__("$2") = chr->flags | 0x40;
        register s16 four __asm__("$3") = 4;
        __asm__ volatile("" : "+r"(f), "+r"(four));
        *(u8 **)((u8 *)chr + 0x80C) = slot;
        chr->flags = f;
        __asm__ volatile("" ::: "memory");
        *(s16 *)((u8 *)chr + 0x75E) = four;
    }
}

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

typedef struct {
    u64 b0 : 1;
    u64 b1 : 1;
    u64 b2 : 1;
    u64 b3 : 1;
    u64 b4 : 1;
    u64 b5 : 1;
    u64 b6 : 1;
    u64 b7 : 1;
    u64 b8 : 1;
    u64 b9 : 1;
    u64 b10 : 1;
    u64 b11 : 1;
    u64 b12 : 1;
    u64 b13 : 1;
    u64 b14 : 1;
    u64 b15 : 1;
    u64 b16 : 1;
    u64 b17 : 1;
    u64 b18 : 1;
    u64 b19 : 1;
    u64 b20 : 1;
    u64 b21 : 1;
    u64 b22 : 1;
    u64 b23 : 1;
    u64 b24 : 1;
    u64 b25 : 1;
    u64 b26 : 1;
    u64 b27 : 1;
    u64 b28 : 1;
    u64 b29 : 1;
    u64 b30 : 1;
    u64 b31 : 1;
    u64 b32 : 1;
    u64 b33 : 1;
    u64 b34 : 1;
    u64 b35 : 1;
    u64 b36 : 1;
    u64 b37 : 1;
    u64 b38 : 1;
    u64 b39 : 1;
    u64 b40 : 1;
    u64 b41 : 1;
    u64 b42 : 22;
} ChrFlagBits;

typedef struct {
    u64 d[2];
} ChrVec16;

typedef struct {
    u64 d[26];
} ChrBlkD0;

typedef struct {
    u32 w[4];
} ChrBlk10;

typedef struct {
    u32 w[21];
} ChrBlk54;

typedef struct {
    u32 w[32];
} ChrBlk80;

extern void *AtelGetEventCharHandleFromID(s32 id);

#define COPY_FLAG_LO(dst, src, n) \
    ((dst)->flags = ((dst)->flags & ~(1LL << (n))) | ((s64)(((s32)((s64)(src)->flags >> (n))) & 1) << (n)))

#define COPY_FLAG_HI(dst, src, n) \
    ((dst)->flags = ((dst)->flags & ~(1ULL << (n))) | ((s64)(((s32)((u64)(src)->flags >> (n))) & 1) << (n)))

void func_00102288(Chr *dst, Chr *src)
{
    *(ChrVec16 *)((u8 *)dst + 0x10) = *(ChrVec16 *)((u8 *)src + 0x10);
    *(ChrVec16 *)((u8 *)dst + 0x20) = *(ChrVec16 *)((u8 *)src + 0x20);
    *(ChrVec16 *)((u8 *)dst + 0x30) = *(ChrVec16 *)((u8 *)src + 0x30);
    *(ChrVec16 *)((u8 *)dst + 0x60) = *(ChrVec16 *)((u8 *)src + 0x60);
    *(ChrVec16 *)((u8 *)dst + 0x70) = *(ChrVec16 *)((u8 *)src + 0x70);
    *(ChrVec16 *)((u8 *)dst + 0x80) = *(ChrVec16 *)((u8 *)src + 0x80);
    *(ChrVec16 *)((u8 *)dst + 0xC0) = *(ChrVec16 *)((u8 *)src + 0xC0);

    *(float *)((u8 *)dst + 0x164) = *(float *)((u8 *)src + 0x164);
    *(float *)((u8 *)dst + 0x168) = *(float *)((u8 *)src + 0x168);
    *(float *)((u8 *)dst + 0x16C) = *(float *)((u8 *)src + 0x16C);
    *(float *)((u8 *)dst + 0x170) = *(float *)((u8 *)src + 0x170);
    *(float *)((u8 *)dst + 0x174) = *(float *)((u8 *)src + 0x174);
    *(float *)((u8 *)dst + 0x178) = *(float *)((u8 *)src + 0x178);
    *(float *)((u8 *)dst + 0x17C) = *(float *)((u8 *)src + 0x17C);
    *(float *)((u8 *)dst + 0x180) = *(float *)((u8 *)src + 0x180);
    *(float *)((u8 *)dst + 0x188) = *(float *)((u8 *)src + 0x188);

    *((u8 *)dst + 0x18C) = *((u8 *)src + 0x18C);
    *((u8 *)dst + 0x18D) = *((u8 *)src + 0x18D);
    *((u8 *)dst + 0x18E) = *((u8 *)src + 0x18E);
    *((u8 *)dst + 0x18F) = *((u8 *)src + 0x18F);
    *((u8 *)dst + 0x191) = *((u8 *)src + 0x191);
    *((u8 *)dst + 0x192) = *((u8 *)src + 0x192);
    *((u8 *)dst + 0x193) = *((u8 *)src + 0x193);
    *((u8 *)dst + 0x194) = *((u8 *)src + 0x194);

    COPY_FLAG_LO(dst, src, 0);
    COPY_FLAG_LO(dst, src, 1);
    COPY_FLAG_LO(dst, src, 2);
    COPY_FLAG_LO(dst, src, 6);
    COPY_FLAG_LO(dst, src, 7);
    COPY_FLAG_LO(dst, src, 8);
    COPY_FLAG_LO(dst, src, 11);
    COPY_FLAG_LO(dst, src, 18);
    COPY_FLAG_LO(dst, src, 19);
    COPY_FLAG_LO(dst, src, 20);
    COPY_FLAG_LO(dst, src, 21);
    COPY_FLAG_LO(dst, src, 22);
    COPY_FLAG_LO(dst, src, 29);
    COPY_FLAG_LO(dst, src, 30);
    COPY_FLAG_LO(dst, src, 31);
    COPY_FLAG_HI(dst, src, 33);
    COPY_FLAG_HI(dst, src, 34);
    COPY_FLAG_HI(dst, src, 35);
    COPY_FLAG_HI(dst, src, 39);
    COPY_FLAG_HI(dst, src, 40);
    *(volatile s64 *)&dst->flags = (dst->flags & ~(1ULL << 41)) | ((s64)(((s32)((u64)src->flags >> 41)) & 1) << 41);

    {
        volatile s32 *d_1ac = (volatile s32 *)((u8 *)dst + 0x1AC);
        *d_1ac = *(volatile s32 *)((u8 *)src + 0x1AC);
    }
    *(ChrVec16 *)((u8 *)dst + 0x1B0) = *(ChrVec16 *)((u8 *)src + 0x1B0);
    *(s32 *)((u8 *)dst + 0x1C4) = *(s32 *)((u8 *)src + 0x1C4);
    *(float *)((u8 *)dst + 0x1C0) = *(float *)((u8 *)src + 0x1C0);
    *(s32 *)((u8 *)dst + 0x404) = *(s32 *)((u8 *)src + 0x404);

    *(ChrBlkD0 *)((u8 *)dst + 0x410) = *(ChrBlkD0 *)((u8 *)src + 0x410);
    *(ChrBlk10 *)((u8 *)dst + 0x4E0) = *(ChrBlk10 *)((u8 *)src + 0x4E0);

    *(float *)((u8 *)dst + 0x4F0) = *(float *)((u8 *)src + 0x4F0);
    *(s32 *)((u8 *)dst + 0x6E4) = *(s32 *)((u8 *)src + 0x6E4);
    *(u16 *)((u8 *)dst + 0x75C) = *(u16 *)((u8 *)src + 0x75C);
    *(float *)((u8 *)dst + 0x4F8) = *(float *)((u8 *)src + 0x4F8);
    *(float *)((u8 *)dst + 0x4FC) = *(float *)((u8 *)src + 0x4FC);
    *(float *)((u8 *)dst + 0x500) = *(float *)((u8 *)src + 0x500);
    *(float *)((u8 *)dst + 0x504) = *(float *)((u8 *)src + 0x504);
    *(float *)((u8 *)dst + 0x508) = *(float *)((u8 *)src + 0x508);
    *(float *)((u8 *)dst + 0x50C) = *(float *)((u8 *)src + 0x50C);
    *(float *)((u8 *)dst + 0x820) = *(float *)((u8 *)src + 0x820);
    *(float *)((u8 *)dst + 0x824) = *(float *)((u8 *)src + 0x824);
    *(float *)((u8 *)dst + 0x828) = *(float *)((u8 *)src + 0x828);

    *(ChrBlk54 *)((u8 *)dst + 0x328) = *(ChrBlk54 *)((u8 *)src + 0x328);
    *(ChrBlk80 *)((u8 *)dst + 0x768) = *(ChrBlk80 *)((u8 *)src + 0x768);

    if (*(s32 *)((u8 *)dst + 0x1C4) == -1) {
        dst->p1A8 = 0;
    } else {
        dst->p1A8 = AtelGetEventCharHandleFromID(*(s32 *)((u8 *)dst + 0x1C4));
    }
}

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
    func_00102B98(id)->w19C = v;
}

/* DEBT(CAST) */ /* DEBT(FAKE) */
void func_00102AF8(Chr *arg0, ChrSrc *arg1) {
    s32 temp_4;
    s32 var_16;
    s32 var_19;
    register void *temp_17 __asm__("$17");
    register s32 p71 __asm__("$3");
    register u32 h0 __asm__("$2");
    s32 c8;

    p71 = (s32) ((u8 *)arg1 + 0x71);
    h0 = (*(u16 *)((u8 *)(arg1) + (0)));
    __asm__ volatile("" : "+r"(h0));
    temp_17 = (*(void **)((u8 *)(arg1) + (4)));
    c8 = (*(s32 *)((u8 *)(arg0) + (0x1C8)));
    __asm__ volatile("" : : : "memory");
    (*(u16 *)((u8 *)(arg0) + (0))) = h0;
    (*(s32 *)((u8 *)(arg0) + (4))) = p71;
    (*(void **)((u8 *)(arg0) + (0x1CC))) = temp_17;
    if (c8 != 0) {
        var_16 = 0;
        if ((*(u16 *)((u8 *)(temp_17) + (6))) != 0) {
            var_19 = 0;
            do {
                temp_4 = var_16;
                var_16 += 1;
                *(s32 *)(var_19 + (*(s32 *)((u8 *)(arg0) + (0x1C8)))) = (s32) func_00100178(temp_4, (*(s32 *)((u8 *)(temp_17) + (0x10))), (*(u16 *)((u8 *)(temp_17) + (4))));
                var_19 += 0x30;
            } while (var_16 < (s32) (*(u16 *)((u8 *)(temp_17) + (6))));
        }
    }
}

typedef struct {
    s32 id;
    float f4;
    float f8;
} RecC_3005C8;

extern s16 D_00300500[0x62];
extern RecC_3005C8 D_003005C8[13];
void Ch_SetPos3(Chr *chr, float x, float y, float z);
void func_001103A8(Chr *chr, float v, s32 frames);
void Ch_SetShadeCol(Chr *chr, float x, float y, float z, s32 n);
void func_00110478(Chr *chr, float v, s32 frames);
void func_00110540(Chr *chr, float v, s32 frames);
void func_00110548(Chr *chr, float v, s32 frames);
float Ch_SetClipZ(Chr *chr, float v);
void func_00110988(Chr *chr, float v);
void func_001109B8(Chr *chr, float v);
void func_00110958(Chr *chr, float v);
float func_00110888(Chr *chr, float v);
void func_0010A250(Chr *chr, float v);

Chr *func_00102B98(s32 id)
{
    register u8 *gp __asm__("$28");
    u8 pad[0x40];
    Chr *chr = 0;
    Rec12C *blk;
    s32 i;

    func_0011BD70(0);
    for (i = 0; i < D_00300668; i++) {
        if (D_00300664[i].active == 0) {
            chr = &D_00300664[i];
            break;
        }
    }
    blk = Ch_BlkGetHandle(id);
    if (blk == 0) {
        if (D_0057CE80 != 0) {
            D_0057CE80 = 0;
            return 0;
        }
        blk = Ch_BlkGetHandle(1);
        ((s8 *)blk)[0xF8] = 1;
    }
    D_0057CE80 = 0;
    func_002EF0D0(chr, 0, sizeof(Chr));
    *(Rec12C **)((u8 *)chr + 0x1D0) = blk;
    chr->active = 1;
    func_00102AF8(chr, (ChrSrc *)blk);
    *(volatile s32 *)((u8 *)chr + 0x1C4) = -1;
    *(volatile s32 *)((u8 *)chr + 0x7F0) = -1;
    *(volatile s32 *)((u8 *)chr + 0x19C) = -1;
    Ch_SetPos3(chr, 0.0f, 0.0f, 0.0f);
    Ch_SetGravMode(chr, 1);
    func_001103A8(chr, 1.0f, 0);
    Ch_SetShadeCol(chr, 1.0f, 1.0f, 1.0f, 0);
    func_00110530(chr, 1.0f, 1.0f, 1.0f);
    func_00110478(chr, 1.0f, 0);
    func_00110540(chr, 1.0f, 0);
    func_00110548(chr, 1.0f, 0);
    Ch_SetMotionSpeed(chr, 0x100);
    Ch_SetClipZ(chr, 50.0f);
    Ch_SetWeight(chr, 1.0f);
    func_00110770(chr, *(float *)((u8 *)blk + 0x34));
    func_00110988(chr, -1.0f);
    func_001109B8(chr, -1.0f);
    Ch_SetThickness(chr, -1.0f);
    func_00110958(chr, -1.0f);
    func_0010AF88(chr, *(float *)(gp - 0x7FBC));
    func_00112F10(chr, 1);
    func_00110850(chr, 0, 0);
    func_00110850(chr, 1, 1);
    func_00110850(chr, 2, 2);
    func_00110850(chr, 0x10, -1);
    func_00110850(chr, 0x11, -1);
    func_00110850(chr, 0x12, -1);
    func_00110850(chr, 0x13, -1);
    Ch_MotionSetNextHokan(chr, 1);
    Ch_EnClip(chr, 1);
    func_00110888(chr, -1.0f);
    Ch_EnRotHokan(chr, 1);
    Ch_IdEnableShade(chr, 1);
    func_00121BF8(chr);
    Ch_DrawSetCull(chr, 1);
    Ch_BindSetScale(chr, 1.0f);
    Ch_SetOverlapHit(chr, 1);
    Ch_ClothSetEnable(chr, 1);
    Ch_ClothEnableGrav(chr, 1);
    Ch_Vu1SetClipmode(chr, 0);
    func_0010A250(chr, 0.0f);
    func_0010B9B8(chr, 1);
    func_00110838(chr, 1.0f);
    func_00111250(1, id, 1);
    {
        register u64 f __asm__("$3") = chr->flags;
        f |= (1ULL << 42);
        chr->flags = f;
    }
    func_001008D8(chr);
    Ch_TextureSetup(chr);
    Ch_TextureSetImageBase(chr, -1, -1);
    Ch_TextureSetClutBase(chr, -1, -1);
    op_et_monster_init(chr, id);
    Ch_EffectSetEffectLevel(chr, 1);
    func_00111250(1, id, 0);
    chr->flags &= ~(1ULL << 42);
    switch (chr->h00 >> 12) {
    case 0:
    case 1:
    case 2:
    case 3:
        func_001108B8(chr, 1);
        break;
    case 4:
    case 5:
    case 6:
        func_001108B8(chr, 0);
        break;
    case 15:
        func_001108B8(chr, 3);
        chr->flags |= 0x40;
        break;
    }
    func_00109BF8(chr);
    Ch_CalcElement(chr);
    Ch_OptposCalc(chr);
    Ch_NeckInit(chr);
    Ch_ClothReset(chr);
    func_00114A20(chr);
    {
        s16 *p = D_00300500;
        register u32 j __asm__("$5");
        u32 k;
        for (j = 0; j < 0x62; j++, p++) {
            if (chr->h00 == *p) {
                chr->flags |= 2;
            }
        }
        *(float *)((u8 *)chr + 0x820) = D_003005C8[0].f4;
        *(float *)((u8 *)chr + 0x824) = D_003005C8[0].f8;
        for (k = 1; k < 13; k++) {
            if (chr->h00 == D_003005C8[k].id) {
                *(float *)((u8 *)chr + 0x820) = D_003005C8[k].f4;
                *(float *)((u8 *)chr + 0x824) = D_003005C8[k].f8;
            }
        }
    }
    switch (chr->h00) {
    case 0x1088:
    case 0x1089:
    case 0x108C:
        chr->flags |= (1ULL << 39);
        break;
    }
    switch (chr->h00) {
    case 0x10A6:
    case 0x10B2:
    case 0x10B3:
    case 0x10B4:
    case 0x111E:
    case 0x1121:
    case 0x1122:
    case 0x1123:
    case 0x3004:
    case 0x3009:
    case 0x300A:
    case 0x300B:
        chr->flags |= (1ULL << 41);
        break;
    }
    return chr;
}

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

void _m2c_Ch_Dispose_chr_texanim_del(s32) __asm__("chr_texanim_del");
/* DEBT(CAST) */ /* DEBT(FAKE) */
void Ch_Dispose(s32 v) {
    register s32 _cond __asm__("$2");
    s32 temp_4;
    register s32 var_18 __asm__("$18");
    register s32 var_19 __asm__("$19");
    register void *temp_16 __asm__("$16");
    register void *temp_20 __asm__("$20");

    if (Ch_CheckHandle(v) == 0) {
        Ch_ClutDispose((void *) v);
        if (!((*(s32 *)((u8 *)((*(void **)((u8 *)(v) + (0x1D0)))) + (0x70))) & 2)) {
            op_et_monster_free((Chr *) v);
        }
        (*(s8 *)((u8 *)(v) + (2))) = 0;
        if (Sg_GetPlayer() == v) {
            Sg_SetPlayer(0);
        }
        temp_20 = (*(void **)((u8 *)(v) + (0x1CC)));
        var_18 = 0;
        if ((*(u16 *)((u8 *)(temp_20) + (6))) != 0) {
            var_19 = 0;
            do {
                var_18 += 1;
                temp_16 = (*(s32 *)((u8 *)(v) + (0x1C8))) + var_19;
                temp_4 = (*(s32 *)((u8 *)(temp_16) + (4)));
                var_19 += 0x30;
                func_0011D590(temp_4, 6);
                func_0011D590((*(s32 *)((u8 *)(temp_16) + (8))), 6);
                func_0011D590((*(s32 *)((u8 *)(temp_16) + (0xC))), 6);
            } while ((_cond = (var_18 < (s32) (*(u16 *)((u8 *)(temp_20) + (6))))) != 0);
        }
        if ((*(s32 *)((u8 *)(v) + (0x708))) != 0) {
            _m2c_Ch_Dispose_chr_texanim_del((*(s32 *)((u8 *)(v) + (0x70C))));
        }
        func_0011D590((*(s32 *)((u8 *)(v) + (0x320))), 6);
        func_0011D590((*(s32 *)((u8 *)(v) + (0x1C8))), 6);
        func_0011D590((*(s32 *)((u8 *)(v) + (0x754))), 6);
        func_0011D590((*(s32 *)((u8 *)(v) + (0x6E8))), 6);
        func_0011D590((*(s32 *)((u8 *)(v) + (0x324))), 6);
        func_001031F8();
    }
}

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

extern s8 D_0057CE88;
extern char D_00569390[];
extern s32 D_00300668;
extern Chr *D_00300664;
extern void Ch_Check(char *, int);
extern int func_0011CDE8(void *, int *);
extern void Ch_MotionRemappingFcurve(Chr *, int);
extern void Ch_TextureReMapping(Chr *);
extern void *texanim_malloc_memory_get(void *);
extern void texanim_malloc_memory_set(void *, int);
extern void Ch_ClutMapping(Chr *, int);
extern void Ch_ClutEnable(Chr *, int);
extern int Ch_MemMoveEventMgrp(void);
extern void func_002A74A8(void);

s32 Ch_MemMove(void)
{
    int moved = 0;
    Chr *c;

    if (D_0057CE88 == 0) {
        return 0;
    }
    Ch_Check(D_00569390, 0x4ED);
    moved = 0;
    for (c = D_00300664; c != D_00300664 + D_00300668; c++) {
        if (((s8 *)c)[2] == 0) {
            continue;
        }
        {
            u64 f = *(u64 *)((u8 *)c + 0x1A0);
            if (((u32)(f >> 42) & 1) || ((u32)(f >> 43) & 1)) {
                continue;
            }
        }
        {
            int d = func_0011CDE8((u8 *)c + 0x320, &moved);
            if (d != 0) {
                func_00103358(c, d);
            }
        }
        {
            int d = func_0011CDE8((u8 *)c + 0x754, &moved);
            if (d != 0) {
                Ch_MotionRemappingFcurve(c, d);
            }
        }
        func_0011CDE8((u8 *)c + 0x1C8, &moved);
        func_0011CDE8((u8 *)c + 0x324, &moved);
        if (*(void **)((u8 *)c + 0x1C8) != 0) {
            int i;
            for (i = 0; i < *(u16 *)(*(u8 **)((u8 *)c + 0x1CC) + 6); i++) {
                u8 *e = *(u8 **)((u8 *)c + 0x1C8) + i * 0x30;
                func_0011CDE8(e + 8, &moved);
                func_0011CDE8(e + 4, &moved);
                func_0011CDE8(e + 0xC, &moved);
            }
        }
        if (func_0011CDE8((u8 *)c + 0x6E8, &moved) != 0) {
            Ch_TextureReMapping(c);
        }
        if (*(void **)((u8 *)c + 0x708) != 0) {
            void *p = texanim_malloc_memory_get(*(void **)((u8 *)c + 0x70C));
            int d = func_0011CDE8(&p, &moved);
            if (d != 0) {
                texanim_malloc_memory_set(*(void **)((u8 *)c + 0x70C), d);
            }
        }
        if (*(void **)((u8 *)c + 0x710) != 0) {
            func_0011CDE8((u8 *)c + 0x710, &moved);
            Ch_ClutMapping(c, 0);
            Ch_ClutEnable(c, ((s8 *)c)[0x714]);
        }
        if (moved != 0) {
            func_002A74A8();
            moved = 0;
            return 1;
        }
    }
    Ch_Check(D_00569390, 0x520);
    if (Ch_MemMoveEventMgrp() != 0) {
        return 1;
    }
    if (func_0011CDE8(Sg_PLightGetPtr(), &moved) != 0) {
        return 1;
    }
    D_0057CE88 = 0;
    return 0;
}

s32 Ch_MemMove_Over(void)
{
    s32 n = 0;

    while (Ch_MemMove() != 0) {
        n++;
    }
    return n;
}

extern s32 D_0057CD48[];
extern s32 D_0057CD68[];
extern char D_005693A0[];
void Ch_RomDataReadInit(void);
void Ch_DrawInitAll(void);
void Sg_InitLight(void);
void Sg_InitCamera(void);

void Ch_InitAll(void)
{
    char buf[100];
    s32 i;

    func_002ED0E0((u8 *)chrblk, 40 * sizeof(Rec12C));
    for (i = 0; i < 40; i++) {
        chrblk[i].w0 = -1;
    }
    Ch_RomDataReadInit();
    D_00300664 = 0;
    D_00300668 = 0;
    D_0057CD88 = 0;
    Ch_DrawInitAll();
    for (i = 0; i < 7; i++) {
        if (ffx_debugmode) {
            func_002F0008(buf, D_005693A0, sg_getdbname(i));
            D_0057CD48[i] = Sg_PcReadD((s32)buf);
            D_0057CD68[i] = (u32)Sg_PcReadGetLen() >> 7;
        } else {
            D_0057CD48[i] = 0;
            D_0057CD68[i] = 0;
        }
    }
    Ch_DisposeAll();
    Sg_InitLight();
    Sg_InitCamera();
}

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

void func_00103878(s32 *a0)
{
    s32 ra_save;

    {
        register void *t7 __asm__("$15");
        __asm__ volatile("" ::: "memory"); /* DEBT(ORDER): prevent move t7,sp hoisting into prologue */
        t7 = &ra_save;
        MIPS_STORE_RA(t7);
    }
    func_002F0C10((u8 *)&D_0057CE90[D_0057CE8C], (void *)a0[1], 7);
    *(s32 *)((u8 *)&D_0057CE90[D_0057CE8C] + 8) = ra_save; /* DEBT(CAST): Rec16 fields at +8/+C */
    *(s32 *)((u8 *)&D_0057CE90[D_0057CE8C] + 0xC) = D_00307F2C;
    D_0057CE8C = (D_0057CE8C + 1) & 0x7F;
}

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

u16 *func_00139440(s32);
void func_00111158(void);
s32 func_00111038(s32, s32);
void func_00104D48(void);
void func_00111AA0(void);
void func_00104D58(void);

void func_001039A0(void)
{
    u16 *list = func_00139440(0);
    s32 i;

    func_00111158();
    for (i = list[0]; i != 0; i--) {
        func_00111038(1, list[i]);
        func_00111038(2, list[i]);
    }
    func_00104D48();
    func_001110F0();
    func_00111AA0();
    func_00104D58();
    for (i = list[0]; i != 0; i--) {
        Ch_DataRead(list[i]);
        ChN_ReadSystemMGRPstart(list[i], 0);
    }
    func_00113480(0);
}

void Sg_EventjumpDispose(void)
{
    func_0011BD80(0);
    Ch_DisposeAll();
    func_00101DA8();
    Ch_DisposeAllMGRP();
    func_0010D720();
}

void _chr_func_00107888(s32) __asm__("func_00107888");
void _chr_func_00106A08(s32, s32, s32, s32, s32, s32) __asm__("func_00106A08");

void func_00103AA8(s32 n)
{
    register u8 *gp __asm__("$28");

    if (n < 10) {
        n = 10;
    }
    func_0011BD80(0);
    Sg_FilterReset();
    func_00117FC8();
    func_00118150();
    func_00118F98();
    func_0011A9E0(1);
    func_0011AA08(1);
    Sg_EnableDrawMenu(1);
    func_0011A968(1);
    func_0011A990(1);
    Sg_SetMapAlphaFast(1);
    Sg_SetMovieGomiAvoid(0);
    Sg_PlayerSetDirFix(0, 0);
    func_0010C780(0);
    _chr_func_00107888(1000000);
    {
        float f = *(float *)(gp - 0x7FB8);
        __asm__ volatile("" : "+f"(f));
        func_001078B0(f);
    }
    _chr_func_00106A08(0, 0x53, 0x53, 0x53, 0x82, 0x4C);
    _chr_func_00106A08(1, 0x37, 0x37, 0x37, 0x136, 0xE);
    _chr_func_00106A08(2, 0x12, 0x12, 0xD, 0x82, 0x11C);
    _chr_func_00106A08(3, 0x50, 0x5A, 0x69, 0, 0);
    func_00115F70(1);
    func_00114948();
    func_0010C130(1);
    func_0010C140(0, 0, 0);
    func_0010C198(0xE1, 0x2D);
    func_00121CC0();
    func_001164B0();
    Sg_SetKeepFps(1);
    func_001039A0();
    Ch_Allocate_InitAll(n);
}
