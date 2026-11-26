/* tu_012 0x10de98-0x10ea50: low; ~Sg (config/tu_map.tsv) */
#include "common.h"
#include "ffx/q0.h"
#include "ffx/r0.h"
#include "ffx/s0.h"
#include "ffx/u0.h"

/* DEBT(FAKE) */
s32 func_0010DE98(s32 a) {
    register s32 hi2 __asm__("$6") = 0x580000;
    register s32 hi5 __asm__("$5");
    D_0057EB38 = 0;
    __asm__ volatile("" : "+r"(hi2) : : "$2", "memory");
    D_0057EB34 = a;
    hi5 = 0x580000;
    __asm__("" : "+r"(hi5));
    *(s32 *)(hi2 - 0x14d0) = 0;
    __asm__("" : "+r"(hi5) : "m"(*(s32 *)(hi2 - 0x14d0)));
    *(s32 *)(hi5 - 0x14c4) = 0;
    return 0x70000000;
}

s32 Sg_GetSpadPtr(void)
{
    return D_0057EB30 ? 0x70002000 : 0x70000000;
}

s32 func_0010DEE0(void)
{
    return D_0057EB30 ? 0x70000000 : 0x70002000;
}

s32 func_0010DF00(void)
{
    return Sg_GetSpadPtr();
}

void func_0010DF20(void)
{
    while (*(volatile u32 *)0x10009000 & 0x100) {
    }
    while (*(volatile u32 *)0x1000D000 & 0x100) {
    }
    *(volatile s32 *)0x1000E000 = (*(volatile s32 *)0x1000E000 & ~0xC) | 0x8;
    *(volatile u32 *)0x1000E050 = 0x800000;
    *(volatile u32 *)0x1000E040 = 0x1FFFF0;
    *(volatile u32 *)0x1000D010 = 0x800000;
    *(volatile u32 *)0x10009030 = 0x800000;
    *(volatile u32 *)0x10009010 = 0;
    *(volatile u32 *)0x10009020 = 0;
    *(volatile u32 *)0x10009000 = 0x1C5;
    func_0010DE98(0x800000);
}

s32 func_0010DFF8(s32 a)
{
    return (a - (D_0057EB30 ? 0x70002000 : 0x70000000)) >> 4;
}

s32 func_0010E028(s32 addr)
{
    s32 qwc;
    u32 bytes;
    u32 free_bytes;

    if (D_0057EB30 != 0) {
        qwc = (addr - 0x70002000) >> 4;
        if (qwc == 0) {
            return addr;
        }
        while (*(volatile u32 *)0x1000D000 & 0x100) {
            (*(volatile s32 *)&D_0057EB38)++;
        }
        bytes = qwc << 4;
        *(volatile u32 *)0x1000D080 = 0x2000;
        *(volatile u32 *)0x1000D020 = qwc;
        (*(volatile s32 *)&D_0057EB3C)--;
        do {
            u32 a = *(volatile u32 *)0x10009030;
            u32 b = *(volatile u32 *)0x1000D010;
            if (a != b) {
                b -= 0x200000;
                free_bytes = (a - b) & 0x1FFFF0;
            } else {
                free_bytes = 0x200000;
            }
            (*(volatile s32 *)&D_0057EB3C)++;
        } while (bytes >= free_bytes);
        __asm__ volatile("sync.l; sync.p");
        *(volatile u32 *)0x1000D000 = 0x100;
        D_0057EB30 = 0;
        return 0x70000000;
    } else {
        qwc = (addr - 0x70000000) >> 4;
        if (qwc == 0) {
            return addr;
        }
        while (*(volatile u32 *)0x1000D000 & 0x100) {
            (*(volatile s32 *)&D_0057EB38)++;
        }
        bytes = qwc << 4;
        *(volatile u32 *)0x1000D080 = 0;
        *(volatile u32 *)0x1000D020 = qwc;
        (*(volatile s32 *)&D_0057EB3C)--;
        do {
            u32 a = *(volatile u32 *)0x10009030;
            u32 b = *(volatile u32 *)0x1000D010;
            if (a != b) {
                b -= 0x200000;
                free_bytes = (a - b) & 0x1FFFF0;
            } else {
                free_bytes = 0x200000;
            }
            (*(volatile s32 *)&D_0057EB3C)++;
        } while (bytes >= free_bytes);
        __asm__ volatile("sync.l; sync.p");
        *(volatile u32 *)0x1000D000 = 0x100;
        D_0057EB30 = 1;
        return 0x70002000;
    }
}

s32 func_0010E260(void)
{
    return Sg_GetSpadPtr();
}

s32 func_0010E280(s32 a)
{
    if (a) {
        return func_0010E028(a);
    }
    return Sg_GetSpadPtr();
}

void func_0010E2B0(void)
{
    if (D_0057EB38 < 4) {
        *(volatile s32 *)&D_0057EB3C;
    }
}

void func_0010E2D0(void)
{
    u64 *p = (u64 *)Sg_GetSpadPtr(); /* DEBT(TYPE): getter returns s32 */

    p[0] = 0xF0000000;
    p[1] = 0;
    func_0010E028((int)(p + 2)); /* DEBT(TYPE) */
    func_0010E2B0();
}

/* Wait until the DMA channel has cleared its transfer-in-progress bit. */
void func_0010E308(void)
{
    do { } while (DMA_FROM_SPR_CHCR & 0x100);
}

extern char D_00569628[];
void func_00120108(char *fmt, ...);
extern u16 D_0057EB2C;
extern struct { u16 x0; u16 x2; u16 x4; u16 x6; } *D_0057EB28;
extern struct { u16 x0; u16 x2; u16 x4; u16 x6; } D_0057EB10[];
void Ch_EffectPacketStorePoly(void *a, void *b, void *c, int d);

void Sg_MFIFOSync(void)
{
    volatile int cnt = 0x1234;
    volatile int j;

    while ((*(volatile s32 *)0x10009000 & 0x100) && cnt != 0) {
        j = 0x4D2;
        do {
            j--;
        } while (j != -1);
        cnt--;
    }
    if (cnt == 0) {
        *(volatile s32 *)0x10003C10 = 9;
        ((struct { s32 x; } *)0x10009000)->x &= ~0x100;
        func_00120108(D_00569628, D_00307F2C);
    }
    *(volatile s32 *)0x1000E000 &= ~0xC;
}

void func_0010E430(u16 *p)
{
    if (p == 0) {
        D_0057EB2C = 0;
        return;
    }
    D_0057EB28 = &D_0057EB10[D_0057EB2C % 3];
    D_0057EB28->x0 = (p[0] & 0x8000) ? p[-((p[0] & 0x7FFF) * 4) / 3] : p[0];
    D_0057EB28->x2 = (p[1] & 0x8000) ? p[-((p[1] & 0x7FFF) * 4) / 3 - 1] : p[1];
    D_0057EB28->x4 = p[2];
    D_0057EB28->x6 = p[3];
    if (D_0057EB2C >= 2) {
        if (D_0057EB2C & 1) {
            Ch_EffectPacketStorePoly(&D_0057EB10[(D_0057EB2C - 2) % 3], &D_0057EB10[(D_0057EB2C - 1) % 3], D_0057EB28, 3);
        } else {
            Ch_EffectPacketStorePoly(&D_0057EB10[(D_0057EB2C - 1) % 3], &D_0057EB10[(D_0057EB2C - 2) % 3], D_0057EB28, 3);
        }
    }
    D_0057EB2C++;
}

typedef struct {
    u16 x0;
    u16 x2;
    u16 x4;
    u16 x6;
} EffVtx;

typedef struct {
    u8 f0;
    u8 f1;
    u8 f2;
    u8 f3;
    u16 f4;
    u16 f6;
    void *f8;
} EffSub;

typedef struct {
    u8 pad0[6];
    u16 count;
    u8 pad8[8];
    EffSub *subs;
} EffHdr;

typedef struct {
    EffHdr *hdr;
    void *p4;
    void *p8;
} EffArg;

void Ch_EffectPacketCreateMain(ChrEnt *arg_p)
{
    EffArg *arg = (EffArg *)arg_p;
    u8 prev[3];
    EffVtx tri[3];
    EffHdr *hdr;
    s32 cur_mode;
    s32 prev_mode;
    EffSub *sub;
    s32 i;
    s32 j;
    u16 *p;

    hdr = arg->hdr;
    prev_mode = -1;
    cur_mode = 0;
    sub = hdr->subs;
    prev[1] = 0xFF;
    prev[2] = 0xFF;
    prev[0] = 0xFF;
    ((int (*)(void *, void *))func_00123878)(arg->p8, arg->p4);
    for (i = 0; i < hdr->count; i++, sub++) {
        if (prev[1] != sub->f1) {
            prev[1] = sub->f1;
            prev_mode = -1;
            func_00113948(sub->f1);
        }
        if (prev[2] != sub->f2) {
            prev[2] = sub->f2;
            prev_mode = -1;
            func_00113938(sub->f2);
        }
        if (prev[0] != sub->f0) {
            prev[0] = sub->f0;
            func_00113968(sub->f0);
            cur_mode = (sub->f0 >> 2) & 1;
        }
        if (prev_mode != cur_mode) {
            func_00113958(cur_mode);
            __asm__ volatile("" : : : "memory");
            prev_mode = cur_mode;
            __asm__ volatile("" : : : "memory");
        }
        j = 0;
        if (sub->f0 & 1) {
            u8 *s = (u8 *)sub->f8;

            for (; j < sub->f4; j++) {
                u8 *cnts = s + 4;
                s32 k;

                p = (u16 *)(s + s[1]);
                for (k = 0; k < s[2]; k++) {
                    s32 m;

                    func_0010E430(0);
                    for (m = 0; m < cnts[k]; m++) {
                        func_0010E430(p);
                        p += 4;
                    }
                }
                s += s[0] * 16;
            }
        } else {
            p = (u16 *)sub->f8;
            for (; j < (s32)((u32)sub->f4 / 3); j++) {
                tri[0].x0 = (p[0] & 0x8000) ? p[-((p[0] & 0x7FFF) * 4) / 3] : p[0];
                tri[0].x2 = (p[1] & 0x8000) ? p[-((p[1] & 0x7FFF) * 4) / 3 - 1] : p[1];
                tri[0].x4 = p[2];
                tri[0].x6 = p[3];
                p += 4;
                tri[1].x0 = (p[0] & 0x8000) ? p[-((p[0] & 0x7FFF) * 4) / 3] : p[0];
                tri[1].x2 = (p[1] & 0x8000) ? p[-((p[1] & 0x7FFF) * 4) / 3 - 1] : p[1];
                tri[1].x4 = p[2];
                tri[1].x6 = p[3];
                p += 4;
                tri[2].x0 = (p[0] & 0x8000) ? p[-((p[0] & 0x7FFF) * 4) / 3] : p[0];
                tri[2].x2 = (p[1] & 0x8000) ? p[-((p[1] & 0x7FFF) * 4) / 3 - 1] : p[1];
                tri[2].x4 = p[2];
                tri[2].x6 = p[3];
                p += 4;
                ((int (*)(void *, void *, void *))Ch_EffectPacketStorePoly)(&tri[0], &tri[1], &tri[2]);
            }
        }
    }
    func_00113978();
}
