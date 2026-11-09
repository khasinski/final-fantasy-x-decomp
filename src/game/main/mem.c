/* tu_030 0x11ba20-0x11d598: medium; mem (config/tu_map.tsv) */
#include "common.h"
#include "ffx/q0.h"
#include "ffx/r0.h"
#include "ffx/u0.h"
#include "ffx/s0.h"
#include "ffx/w6.h"
#include "ffx/v0.h"

void func_0011BFE0(s32 a);

void func_0011BA20(void)
{
    s32 i;
    u8 *p;

    if (ffx_debugmode) {
        p = (u8 *)0x5FBFFE0; /* DEBT(CAST): fixed address */
        for (i = 0x7FF; i >= 0; i--) {
            *p = 0;
            p -= 0x20;
        }
    }
}

/* DEBT(CAST): frees the scratch address recorded in the header two slots back. */
/* DEBT(CAST) */
void func_0011BA60(void *p) {
    u32 temp_3;
    void *temp_5;

    temp_5 = p - 0x10;
    if ((ffx_debugmode != 0) && (p != 0)) {
        temp_3 = (*(u32 *)((u8 *)(temp_5) + (8)));
        if (temp_3 & 0x07FF0000) {
            *(s8 *)(0x05FB0000 + ((temp_3 >> 0xB) & 0xFFE0)) = 0;
            (*(u32 *)((u8 *)(temp_5) + (8))) = (u32) ((*(u32 *)((u8 *)(temp_5) + (8))) & 0xF800FFFF);
        }
    }
}

INCLUDE_ASM("build/ee_asm/game/main/mem", func_0011BAB8);

INCLUDE_ASM("build/ee_asm/game/main/mem", func_0011BB08);

INCLUDE_ASM("build/ee_asm/game/main/mem", Sg_MemSetCurrentAddr);

/* DEBT(TYPE): global type guessed from the access width only */
void func_0011BD70(u8 v)
{
    D_00580914 = v;
}

/* DEBT(TYPE): global type guessed from the access width only */
void func_0011BD80(u8 v)
{
    D_00580915 = v;
}

INCLUDE_ASM("build/ee_asm/game/main/mem", func_0011BD90);

/* DEBT(ORDER): heap flag clears retain the original scheduling order. */
void func_0011BE48(void)
{
    D_005808C0 = 0;
    D_005808C8->flag01 = 0;
    D_005808C8[1].flag01 = 0;
    func_0011BD70(1U);
    func_0011BD80(0);
    if (ffx_debugmode != 0)
    {
        func_0011BD90(0, 0xA00000, 0x01B00000);
        func_0011BD90(1, 0x03000000, 0x05D00000);
        func_0011BA20();
    }
    else
    {
        func_0011BD90(0, 0xA00000, 0x01B00000);
    }
    Sg_MemSetMoveHeapStartAddr(D_005808C8->first);
}

int Sg_MemGetSize(u8 *p)
{
    if (p == 0) {
        return 0;
    }
    return (u8 *)((R0Blk *)p - 1)->end - p;
}

void func_0011BEF8(R0Blk *b, u32 v)
{
    int n = ((u32)b->end - (u32)b - sizeof(R0Blk)) >> 4;
    u32 *q = (u32 *)(b + 1);

    while (n-- != 0) {
        q[3] = v;
        q[2] = v;
        q[1] = v;
        q[0] = v;
        q += 4;
    }
}

void func_0011BF40(s32 v)
{
    D_00307F58 = v;
}

void func_0011BF50(R0Heap *h)
{
    R0Blk *b = h->first;

    while ((b->flags & 0xF) != 0xF) {
        while ((b->flags & 0xF) == 0 && (b->end->flags & 0xF) == 0) {
            b->end = b->end->end;
        }
        b->end->next = b;
        b = b->end;
    }
    h->b00 = 0;
}

void func_0011BFD0(void)
{
    func_0011BF50(&D_005808C8[0]);
}

void func_0011BFE0(s32 a)
{
    D_00580910 = ((a - 8) >> 2) & 0x7FFFFF;
}

s32 func_0011C000(arg0)
void *arg0;
{
    u32 temp_8 = (*(u32 *)((u8 *)(arg0) + (0xC)));
    R0Heap *temp_3 = &D_005808C8[(temp_8 >> 0x1B) & 3];
    if ((s32)arg0 < (s32)temp_3->first) {
        return -1;
    }
    if ((s32)temp_3->last < (s32)arg0) {
        return -2;
    }
    if ((*(s32 *)((u8 *)(arg0) + (0))) < (s32)temp_3->first && (temp_8 & 0xF) != 0xF) {
        return -3;
    }
    if ((s32)temp_3->last < (*(s32 *)((u8 *)(arg0) + (0)))) {
        return -4;
    }
    if ((*(s32 *)((u8 *)(arg0) + (4))) < (s32)temp_3->first && (*(s32 *)((u8 *)(arg0) + (4))) != 0) {
        return -5;
    }
    if ((s32)temp_3->last < (*(s32 *)((u8 *)(arg0) + (4)))) {
        return -6;
    }
    return 0;
}

int Sg_MemCheckPtr(u8 *p)
{
    R0Heap *h = &D_005808C8[0];

    if (p == 0) {
        return 0;
    }
    if ((s32)p < (s32)h->first) { /* DEBT(CAST): compared signed */
        return -10;
    }
    if ((s32)h->last < (s32)p) {
        return -20;
    }
    return func_0011C000(p - 0x10);
}

void _Sg_MemCheckMCBerr(void)
{
    int v = func_0011C000();

    if (v) {
        yiAssert(0, D_00569B78, D_00569B90, v);
    }
}

void func_0011C140(R0Blk *blk, char *msg, int c) /* DEBT(TYPE): msg and c are passed by the callers but unused here */
{
    func_0011CB08(blk, 0);
    _Sg_MemDump(&D_005808C8[(blk->flags >> 27) & 3]);
}

u16 func_0011C188(R0Blk *b)
{
    int n = ((u32)b->end - (u32)b - sizeof(R0Blk)) >> 1;
    u16 *q = (u16 *)(b + 1);
    u16 sum = 0;

    while (n--) {
        sum += *q++;
    }
    return sum;
}

INCLUDE_ASM("build/ee_asm/game/main/mem", Sg_MemCheckHeap);

void func_0011C328(s32 a, void *b, s32 c)
{
    Sg_MemCheckHeap(&D_005808C8[a], b, c);
}

void func_0011C340(void) {
}

void func_0011C348(int a)
{
    D_005808C0 = a - 1;
}

INCLUDE_ASM("build/ee_asm/game/main/mem", Sg_MemGet);

void _m2c_func_0011C6E0__Sg_MemCheckMCBerr() __asm__("_Sg_MemCheckMCBerr");
/* DEBT(CAST) */
s32 func_0011C6E0(s32 a, s32 b, s32 c, s32 d) {
    s32 temp_7_2;
    u32 temp_16;
    u32 temp_18;
    void *temp_17;
    void *temp_2;

    if (c == 0) {
        return Sg_MemGet(0, a, 0xE, d, 0);
    }
    __asm__ volatile("" : : : "memory");
    temp_17 = c - 0x10;
    d += 0xF;
    temp_16 = d & 0xFFFFFFF0;
    _m2c_func_0011C6E0__Sg_MemCheckMCBerr(temp_17);
    temp_7_2 = (*(s32 *)((u8 *)(c) + (-0x10)));
    temp_18 = (((s32)((u8 *)(temp_7_2) - (u8 *)temp_17))) - 0x10;
    if (temp_18 == temp_16) {
        return c;
    }
    if (temp_16 < temp_18) {
        func_0011C950(((u32) (*(u32 *)((u8 *)(temp_17) + (0xC))) >> 0x1B) & 3, temp_17 + (temp_16 + 0x10), temp_17, temp_7_2);
        return c;
    }
    temp_2 = Sg_MemGet(0, a, (*(u32 *)((u8 *)(temp_17) + (0xC))) & 0xF, (s32) temp_16, 0);
    func_002EEF1C(temp_2, (void *) c, (s32) temp_18);
    func_0011CA28(c, (*(u32 *)((u8 *)(temp_17) + (0xC))) & 0xF);
    return (s32) temp_2;
}

void func_0011C7E8(u8 *p, int f)
{
    R0Blk *b = (R0Blk *)p - 1;
    u32 bit = (f & 1) << 26;

    b->flags = (b->flags & ~0x4000000) | bit;
    if (f) {
        *(u16 *)&b->w08 = func_0011C188(b); /* DEBT(CAST): checksum in the low half of w08 */
    }
}

typedef struct MemBlk {
    struct MemBlk *end;
    struct MemBlk *next;
    u16 sum;
    u16 hi16;
    u32 kind : 4;
    u32 pc : 22;
    u32 chk : 1;
    u32 heap_id : 2;
    u32 top : 3;
} MemBlk;

INCLUDE_ASM("build/ee_asm/game/main/mem", func_0011C838);

R0Blk *func_0011C8B8(R0Blk *b)
{
    if ((b->flags & 0xF) != 0) {
        return b;
    }
    while ((b->next->flags & 0xF) == 0) {
        b = b->next;
    }
    while ((b->flags & 0xF) == 0 && (b->end->flags & 0xF) == 0) {
        b->end = b->end->end;
    }
    b->end->next = b;
    return b;
}

void func_0011C950(int idx, R0Blk *arg1, R0Blk *arg2, R0Blk *arg3)
{
    MemBlk *b = (MemBlk *)arg1;
    MemBlk *prev = (MemBlk *)arg2;
    MemBlk *next = (MemBlk *)arg3;
    R0Heap *h = &D_005808C8[idx];

    func_002EF0D0(b, 0, 0x10);
    b->heap_id = idx;
    b->end = next;
    b->next = prev;
    prev->end = b;
    b->end->next = b;
    func_0011C838(arg1);
    func_0011C8B8(arg1);
    h->b00 = 0;
}

s32 func_0011CA08(void *p)
{
    AllocHdr *h = (AllocHdr *)p - 1;

    if (p == 0) {
        return 0;
    }
    return (h->wC & 0xF) == 0;
}

void func_0011CA28(s32 a, s32 kind)
{
    R0Blk *blk = (R0Blk *)a - 1;

    if (a != 0) {
        if ((blk->flags & 0xF) == 0) {
            func_0011C140(blk, D_00569C30, 0);
        }
        if ((blk->flags & 0xF) != kind && (blk->flags & 0xF) != 0xE && kind != -1) {
            func_0011C140(blk, D_00569C50, 0);
        }
        func_0011BA60((void *)a);
        func_0011C838(blk);
    }
}

void func_0011CAE0(s32 *p, s32 a)
{
    if (ffx_debugmode != 0) {
        Sg_PcWrite(p, p[-4] - (s32)p, a);
    }
}

void func_0011CB08(AllocHdr *h, s32 idx) /* DEBT(TYPE): second argument is passed by the callers but unused here */
{
    s32 k = h->wC & 0xF;

    if (k != 0 && k != 0xF) {
        func_0011BAB8(h + 1);
    }
}

void _Sg_MemDump(void *heap)
{
    R0Heap *h = heap;
    R0Blk *block = h->first;
    int index;

    if (h->b00 != 0) {
        func_0011BF50(h);
    }
    index = 0;
    if (block != 0) {
        do {
            if ((u32)((char *)block->end - (char *)block - sizeof(R0Blk)) >= 0x40U || (block->flags & 0xF)) {
                func_0011CB08((AllocHdr *)block, index); /* DEBT(CAST): alternate view of the same 16-byte heap header. */
            }
            block = block->end;
            index++;
        } while (block != 0);
    }
}

void Sg_MemDump(int a)
{
    switch (a) {
    case 1:
        _Sg_MemDump(&D_005808C8[1]);
        break;
    case 2:
        _Sg_MemDump(&D_005808C8[2]);
        break;
    default:
        _Sg_MemDump(&D_005808C8[0]);
        break;
    }
    Cache_Dump(D_00569C70);
}

void *Sg_MemCache_SerchFree(void *mem)
{
    R0Blk *blk = (R0Blk *)mem - 1;
    R0Blk *p = D_005808D8;

    while (p != blk) {
        if ((p->flags & 0xF) == 0) {
            u32 ps = (u32)((u8 *)p->end - (u8 *)p) - 16;
            u32 bs = (u32)((u8 *)blk->end - (u8 *)blk) - 16;

            if (bs < ps) {
                return p + 1;
            }
        }
        p = p->next;
    }
    return 0;
}

void *func_0011CC78(void *mem)
{
    R0Blk *hdr = ((R0Blk *)mem) - 1;
    R0Blk *nxt = hdr->end;
    R0Blk *after;
    R0Blk *dst;
    R0Blk *prev;
    s32 n;

    if ((nxt->flags & 0xF) != 0) {
        return mem;
    }
    after = nxt->end;
    n = (u8 *)nxt - (u8 *)hdr;
    dst = (R0Blk *)(((u8 *)after - (n - 0x10)) - 0x10);
    func_002EEFCC(dst, hdr, n);
    dst->end = after;
    dst->next = hdr;
    hdr->end = dst;
    after->next = dst;
    prev = hdr->next;
    if ((prev->flags & 0xF) == 0) {
        prev->end = hdr->end;
    } else {
        func_0011C838(hdr);
    }
    return dst + 1;
}

void *func_0011CD30(void *a, void *b)
{
    R0Blk *ha = (R0Blk *)a - 1;
    R0Blk *hb = (R0Blk *)b - 1;
    s32 nb = (u8 *)hb->end - (u8 *)hb;

    a = (u8 *)a + (((u8 *)ha->end - (u8 *)ha) - nb - 0x10);
    func_002EEFCC(a, hb, nb);
    func_0011C838(hb);
    ((R0Blk *)a)->end = ha->end;
    ha->end->next = (R0Blk *)a;
    ha->end = (R0Blk *)a;
    ((R0Blk *)a)->next = ha;
    return (R0Blk *)a + 1;
}

void Sg_MemSetMoveHeapStartAddr(s32 p)
{
    if (p != 0) {
        D_00580918 = p - 0x10;
    } else {
        D_00580918 = D_005808D4;
    }
}

/* DEBT(CAST): defrag-grows the current allocation into preceding free space. */
INCLUDE_ASM("build/ee_asm/game/main/mem", func_0011CDE8);

int func_0011CFB8(int a, int v)
{
    AllocHdr *h = (AllocHdr *)a - 1; /* DEBT(TYPE) */

    h->w8 = (h->w8 & 0x7FFFFFF) | (v << 27);
}

void func_0011CFE0(void *p, s32 v)
{
    AllocHdr *h = (AllocHdr *)p - 1;

    h->wC = (h->wC & ~0xF) | ((v + 1) & 0xF);
}

void *func_0011D008(s32 *tab)
{
    R0Blk *b = D_005808C8[0].first;
    s32 kind = 0;
    s32 i;

    func_0011C328(0, D_00569C80, 0x42F);
    for (i = 8; i >= 0; i--) {
        tab[i] = 0;
    }
    while (b != 0) {
        switch (b->flags & 0xF) {
        case 15:
            kind = -1;
            break;
        case 0:
            kind = 7;
            break;
        case 13:
            kind = 3;
            break;
        case 12:
            kind = 1;
            break;
        case 7:
            switch (b->w08 >> 27) {
            case 1:
                kind = 4;
                break;
            case 2:
                kind = 5;
                break;
            case 3:
                kind = 6;
                break;
            case 4:
                kind = 8;
                break;
            case 5:
                kind = 2;
                break;
            case 0:
                kind = 0;
                break;
            }
            break;
        case 1:
        case 2:
        case 4:
        case 9:
            kind = 2;
            break;
        default:
            kind = 0;
            break;
        }
        if (kind != -1) {
            tab[kind] += (u8 *)b->end - (u8 *)b;
        }
        b = b->end;
    }
    return D_005808C8[0].p08 + 0x10;
}

s32 Sg_MemGetMaxFree(s32 mode)
{
    AllocHdr *h = (AllocHdr *)D_005808D4;
    u32 max = 0;

    if (mode == 1) {
        func_0011BFD0();
    } else if (mode == 2) {
        while (Ch_MemMove_Over()) {
        }
        while (!Cache_OverFlow()) {
        }
    }

    while (h != 0) {
        if ((h->wC & 0xF) == 0) {
            u32 free = h->w0 - (s32)h - 0x10;

            if (max < free) {
                max = free;
            }
        }
        h = (AllocHdr *)h->w0;
    }
    return max;
}

void func_0011D228(void) {
}

INCLUDE_ASM("build/ee_asm/game/main/mem", func_0011D230);

INCLUDE_ASM("build/ee_asm/game/main/mem", user_malloc);

INCLUDE_ASM("build/ee_asm/game/main/mem", func_0011D420);

INCLUDE_ASM("build/ee_asm/game/main/mem", func_0011D4B8);


s32 func_0011D568(s32 a, s32 b, s32 c)
{
    return func_0011C6E0(0, c, a, b);
}

void func_0011D590(s32 a, s32 b)
{
    func_0011CA28(a, b + 1);
}
