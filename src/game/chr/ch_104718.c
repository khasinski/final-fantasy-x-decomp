/* tu_004 0x104718-0x106380: low; ~Ch (config/tu_map.tsv) */
#include "common.h"
#include "ffx/q0.h"
#include "ffx/r0.h"
#include "ffx/s0.h"
#include "ffx/u0.h"
#include "ffx/v0.h"
#include "ffx/g0.h"

void func_00104718(void)
{
    HdlRec *prev = 0;
    HdlRec *rec;
    HdlRec *cur;
    HdlRec *q;
    s32 i, j;

    D_0057E2A8 = 0;
    for (i = 0; i < 100; i++) {
        D_0057DAD8[i].h6 = 0;
        D_0057DAD8[i].next = 0;
    }
    for (i = 0; i < 100; i++) {
        rec = &D_0057DAD8[i];
        if (rec->w0 != 0 && rec->h6 == 0) {
            if (D_0057E2A8 == 0) {
                D_0057E2A8 = rec;
            }
            rec->link = 0;
            if (prev != 0) {
                prev->link = rec;
            }
            prev = rec;
            cur = rec;
            for (j = 0; j < 100; j++) {
                q = &D_0057DAD8[j];
                if (q->w0 != 0 && q->h6 == 0 && rec != q && rec->h4 == q->h4) {
                    cur->next = q;
                    q->h6 = 1;
                    cur = q;
                    q->next = 0;
                }
            }
        }
    }
}

void func_00104838(RelObj *src, s32 arg)
{
    HdlRec *slot = 0;
    s32 i;

    for (i = 0; i < 100; i++) {
        if (D_0057DAD8[i].w0 == 0) {
            slot = &D_0057DAD8[i];
            slot->h4 = src->h4;
            slot->w0 = src;
            slot->w10 = arg;
            break;
        }
    }
    if (slot == 0) {
        yiAssert(0, D_005693F0, D_00569400);
    }
    func_00104718();
}

void func_001048D8(RelObj *src)
{
    HdlRec *slot = 0;
    s32 i;

    for (i = 0; i < 100; i++) {
        if (D_0057DAD8[i].w0 == src) {
            slot = &D_0057DAD8[i];
            break;
        }
    }
    if (slot != 0) {
        slot->w0 = 0;
        func_00104718();
    }
}

s32 func_00104948(int a, int b, int c)
{
    s32 i;

    for (i = 0; i < 50; i++) {
        if (D_0057E2B0[i].w0 != 0 && D_0057E2B0[i].h4 == a && D_0057E2B0[i].h6 == b && D_0057E2B0[i].w8 == c) {
            return D_0057E2B0[i].w0;
        }
    }
    return 0;
}

void func_001049A0(s32 w)
{
    s32 i;

    if (w != 0) {
        for (i = 0; i < 50; i++) {
            if (D_0057E2B0[i].w0 == w) {
                D_0057E2B0[i].w0 = 0;
                break;
            }
        }
    }
}

void func_001049F8(int top) /* DEBT(CAST): prototype in funcs.h/r0.h takes an int */
{
    RelTop *p = (RelTop *)top;
    s32 d;
    s32 i;

    if (p != 0) {
        d = (s32)p - (s32)p->self;
        if (d != 0) {
            p->objs = (RelObj *)((s32)p->objs + d);
            p->self = p;
            for (i = 0; i < p->count; i++) {
                func_00104528(p->objs + i, d);
            }
        }
    }
}

int func_00104A88(int top, int h4, int h6, int w8) /* DEBT(CAST): prototype in r0.h takes the pointer as int */
{
    RelTop *p = (RelTop *)top;
    s32 i;
    s32 j;

    if (p != 0) {
        for (i = 0; i < 50; i++) {
            if (D_0057E2B0[i].w0 == 0) {
                D_0057E2B0[i].w8 = w8;
                D_0057E2B0[i].h4 = h4;
                D_0057E2B0[i].h6 = h6;
                D_0057E2B0[i].w0 = (s32)p;
                break;
            }
        }
        if (i == 50) {
            yiAssert(0, D_00569410, D_00569420);
        }
        func_001049F8((int)p);
        for (j = 0; j < p->count; j++) {
            func_00104838(p->objs + j, (s32)p);
        }
    }
}

s32 func_00104B58(int mode, int b, int c)
{
    RelTop *p = (RelTop *)func_00104948(mode, b, c);
    Chr *chr;
    s32 i;
    char buf[256]; /* DEBT(PAD): unused 256-byte frame slot kept for the original stack layout */

    if (p != 0) {
        for (i = 0; i < p->count; i++) {
            func_001048D8(p->objs + i);
        }
        func_001049A0((s32)p);
        switch (mode) {
        default:
            func_0011D590((s32)p, 6);
            func_001031F8();
            break;
        case 0:
            func_00111500(2, (b << 16) | c);
            break;
        case 2:
            func_00111500(2, 0x903E7);
            break;
        }
        for (chr = D_00300664; chr != D_00300664 + D_00300668; chr++) {
            if (chr->active != 0 && chr->w7F4 == (s32)p) {
                func_00105E08(chr);
            }
        }
    }
}

char *func_00104CC0(int id)
{
    int kind = (id >> 12) & 0xF;

    func_002F0008(D_0057DAB8, D_00569460, sg_getdbname(kind), func_00101528(kind), id & 0xFFF);
    return D_0057DAB8;
}

void func_00104D48(void)
{
    func_00111038(2, 0x903E7);
}

void func_00104D58(void)
{
    Cache_Use(2, 0x903E7);
}

/* DEBT(CAST): existing handle-based prototypes require pointer conversions. */
void Ch_RegMotionEntryCache(s32 h)
{
    func_0011BB08((void *) h, D_00569480, -1);
    func_0011CFB8(h, 3);
    func_0011CFE0(h, 6);
    Cache_Entry(2, 0x903E7, h);
    Cache_Use(2, 0x903E7);
    Cache_Lock(2, 0x903E7);
    Cache_Entry_NotYet(2, 0x903E7, 1);
}

s32 Ch_RegMotionGetExistMem(void)
{
    return Cache_Exist3(2, 0x903E7) != 0;
}

s32 func_00104E20(void)
{
    return func_00104948(2, 0, 0) != 0;
}

void Ch_RegMotionSetup(int a)
{
    if (func_00104E20() == 0) {
        func_00104A88(a, 2, 0, 0);
        Cache_Entry_NotYet(2, 0x903E7, 0);
    }
}

void func_00104EA8(void)
{
    func_00104B58(2, 0, 0);
    func_00110E38(2, 0x903E7, 1);
}

void func_00104EE0(int a)
{
    func_00104B58(1, a, 0);
}

void ChN_DisposeSystemMGRP(int a, int b)
{
    func_00104B58(0, b, a);
}

s32 ChN_ExistSystemMGRP(s32 a, s32 b)
{
    return func_00104948(0, b, a) != 0;
}

void func_00104F28(int a, int b)
{
    char buf[0x100]; /* DEBT(PADDING): unused 0x100-byte frame in the original */

    if (a) {
        func_00104A88(a, 1, b, 0);
    }
}

void func_00104F50(int a)
{
    Ch_RomReadEventMGRP(func_0014A350(func_0013A238(), a), a);
}

int func_00104F88(int a)
{
    return func_00113820(func_0014A350(func_0013A238(), a));
}

void func_00104FC0(int v)
{
    char buf[0x100]; /* DEBT(PADDING): unused 0x100-byte frame in the original */

    if (func_00104948(1, v, 0) == 0) {
        if (func_00104F88(v) == 0) {
            func_00104F50(v);
        }
        func_00113480(0);
    }
}

void ChN_ReadSystemMGRPstart(int a, int b)
{
    Ch_MgrpRead(a, b);
}

s32 ChN_ReadSystemMGRPsync(s32 a, s32 b)
{
    s32 r = Cache_CheckYet(2, (b << 16) | a);

    return r == 2 ? 0 : r;
}

INCLUDE_ASM("build/ee_asm/game/chr/ch_104718", ChN_ReadSystemMGRP);

void Ch_DisposeAllMGRP(void)
{
    int i;
    R0Ent12 *p;

again: /* DEBT(GOTO): restart the scan after each call */
    for (i = 0; i < 50; i++) {
        p = &D_0057E2B0[i];
        if (p->w0 != 0 && p->h4 != 2) {
            func_00104B58(p->h4, p->h6, p->w8);
            goto again;
        }
    }
}

s32 func_00105180(s8 *p)
{
    return (s16)((p[1] << 8) | p[0]);
}

INCLUDE_ASM("build/ee_asm/game/chr/ch_104718", Ch_SetSysMotion);

void func_00105320(Chr *c)
{
    Ch_SetSysMotion((int)c, c->b191, 0); /* DEBT(TYPE): funcs.h declares Ch_SetSysMotion(int, int, int) */
}

void func_00105330(void)
{
    int i;
    G0Ent16 *p;

    for (i = 49; i >= 0; i--) {
        D_0057E2B0[i].w0 = 0;
    }
    for (i = 99; i >= 0; i--) {
        D_0057DAD8[i].w0 = 0;
    }
    p = D_0057E508;
    for (i = 49; i >= 0; i--) {
        p->w0 = 0;
        p->w4 = 0;
        p++;
    }
}

void func_001053C0(OfsList *l, u32 base)
{
    u32 *p = l->arr;
    u32 i;

    for (i = 0; i < l->count; i++) {
        *p++ += base;
    }
}

INCLUDE_ASM("build/ee_asm/game/chr/ch_104718", Chb_AttachMotionTBL_OLD);

INCLUDE_ASM("build/ee_asm/game/chr/ch_104718", func_00105500);

INCLUDE_ASM("build/ee_asm/game/chr/ch_104718", func_001055B0);

INCLUDE_ASM("build/ee_asm/game/chr/ch_104718", func_00105670);

s32 func_00105750(Chr *chr, s8 v)
{
    chr->b743 = v;
    return 0;
}

s32 func_00105760(Chr *chr)
{
    ChrVm *vm = CHR_VM(chr);
    s8 *pc = vm->pc;
    s32 r = 0;

    switch (*pc) {
    case 0:
        r = 2;
        break;
    case 5:
        r = 3;
        break;
    case 1: {
        ChrVmRec *rec;
        s32 x;
        s32 y;
        s32 id;

        pc++;
        rec = &vm->res->recs[func_00105180(pc)];
        x = rec->tab[func_00105180(pc + 4)];
        y = rec->tab[func_00105180(pc + 6)];
        id = func_00105180(pc + 2);
        if (func_00105180(pc + 6) != 1 && id != 1) {
            y++;
        }
        func_00112A70(chr, rec->arg, id, x << 8, y << 8);
        pc += 8;
        vm->b32 = 0;
        break;
    }
    case 2:
        if (vm->h1C != 0) {
            r = 1;
        } else {
            pc++;
        }
        break;
    case 6:
        if (func_00105180(pc + 1) > vm->b2B) {
            r = 1;
        } else {
            pc += 3;
        }
        break;
    case 3:
        if (vm->h1E == 0) {
            vm->h1E = func_00105180(pc + 1);
        }
        if (--vm->h1E == 0) {
            pc += 3;
        } else {
            r = 1;
        }
        break;
    case 4:
        pc = vm->hdr->base + vm->hdr->ofs[func_00105180(pc + 1)];
        break;
    default:
        r = -1;
        break;
    }
    vm->pc = pc;
    return r;
}

int Ch_GetSeqFrame(Chr *chr)
{
    ChrVm *vm = CHR_VM(chr);
    s8 *pc = vm->pc;
    int sum = 0;

    if (pc != 0) {
        for (;;) {
            switch (*pc) {
            case 0:
            case 5:
                return sum;
            case 1: {
                ChrVmRec *rec;
                s32 n;
                s32 a;
                s32 b;

                pc++;
                rec = &vm->res->recs[func_00105180(pc)];
                if (rec == 0) {
                    return -1;
                }
                n = func_00105180(pc + 2);
                a = rec->tab[func_00105180(pc + 4)];
                b = rec->tab[func_00105180(pc + 6)];
                if (n == 0) {
                    return -1;
                }
                sum += (b - a) * n;
                pc += 8;
                break;
            }
            case 2:
                pc++;
                break;
            case 3:
                sum += func_00105180(pc + 1);
                pc += 3;
                break;
            case 6:
                pc += 3;
                break;
            case 4:
                pc = vm->hdr->base + vm->hdr->ofs[func_00105180(pc + 1)];
                break;
            default:
                return -1;
            }
        }
    }
    return -1;
}

ChrVmRec *func_00105A88(Chr *chr)
{
    ChrVm *vm = CHR_VM(chr);
    s8 *pc = vm->pc;

    if (pc != 0) {
        for (;;) {
            switch (*pc) {
            case 0:
            case 5:
                return 0;
            case 1:
                return &vm->res->recs[func_00105180(pc + 1)];
            case 2:
                pc++;
                break;
            case 3:
                func_00105180(pc + 1);
            case 6:
                pc += 3;
                break;
            case 4:
                pc = vm->hdr->base + vm->hdr->ofs[func_00105180(pc + 1)];
                break;
            default:
                return 0;
            }
        }
    }
    return 0;
}

INCLUDE_ASM("build/ee_asm/game/chr/ch_104718", Ch_SeqFrame);

INCLUDE_ASM("build/ee_asm/game/chr/ch_104718", Ch_MotionGetName);

void func_00105E08(Chr *chr)
{
    chr->w720 = 0;
    chr->w738 = 0;
    chr->w7F4 = 0;
}

int func_00105E18(Chr *chr)
{
    return ((chr->b74A != 0) ? ~Ch_GetSeqFrame(chr) : chr->h730) == 0;
}

s32 func_00105E48(Chr *chr)
{
    return chr->w738;
}

INCLUDE_ASM("build/ee_asm/game/chr/ch_104718", Ch_SetSequence);

INCLUDE_ASM("build/ee_asm/game/chr/ch_104718", func_00106108);

INCLUDE_ASM("build/ee_asm/game/chr/ch_104718", func_00106198);

INCLUDE_ASM("build/ee_asm/game/chr/ch_104718", Ch_MemMoveEventMgrp);
