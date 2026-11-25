/* tu_319 0x2a0820-0x2a2220: medium; ~opu (config/tu_map.tsv) */
/* Module guess: event-script VM / field-event runtime (no __FILE__ string found for this range). */
#define opu_unit _hdr_opu_unit
#include "common.h"
#include "ffx/q7.h"
#include "ffx/w9.h"
#include "ffx/t6.h"
#include "ffx/v6.h"
#include "ffx/w10.h"
#undef opu_unit

T6_Blk *func_002A0820(T6_BlkPool *p, int arg, int w, int key)
{
    int i = func_00295D58(p, key);
    T6_Blk *b;

    if (i < 0) {
        return 0;
    }
    b = (T6_Blk *)(p->blocks + (i << 8));
    func_00295C50(b);
    func_00295CA0(p, b, arg);
    b->serial = p->serial;
    if ((u16)++p->serial > 0xFFEF) {
        p->serial = -0x8000;
    }
    b->w0 = w;
    return b;
}

void func_002A08D0(void) {
}

void _m2c_opu_unit_func_00295C50(void *) __asm__("func_00295C50");
void _m2c_opu_unit_func_00295CA0(void *, void *, s32) __asm__("func_00295CA0");
s32 _m2c_opu_unit_func_00295D58(void *, u32) __asm__("func_00295D58");
/* DEBT(CAST) */
void *opu_unit(void *arg0, void *arg1) {
    s32 temp_17;
    s32 temp_2;
    void *temp_16;
    void *temp_19;

    if ((*(s16 *)((u8 *)(arg0) + (0x212))) != 0) {
        (*(void **)((u8 *)(arg0) + (0))) = arg0;
        return arg1 + 4;
    }
    temp_16 = arg0 + 0x300;
    temp_17 = (*(s32 *)((u8 *)(arg0) + (0x220)));
    temp_19 = (*(s32 *)((u8 *)(arg0) + (0x320))) + (_m2c_opu_unit_func_00295D58(temp_16, (u32) ((*(u16 *)((u8 *)(arg0) + (0x21A))) & 0x3000) >> 0xC) << 8);
    _m2c_opu_unit_func_00295C50(temp_19);
    _m2c_opu_unit_func_00295CA0(temp_16, temp_19, temp_17);
    (*(u16 *)((u8 *)(temp_19) + (0x1A))) = (u16) (*(u16 *)((u8 *)(arg0) + (0x302)));
    temp_2 = (*(u16 *)((u8 *)(arg0) + (0x302))) + 1;
    (*(u16 *)((u8 *)(arg0) + (0x302))) = temp_2;
    if ((u32) (temp_2 & 0xFFFF) > 0xFFEFU) {
        (*(s16 *)((u8 *)(arg0) + (0x302))) = -0x8000;
    }
    (*(void **)((u8 *)(temp_19) + (0))) = (void *) (arg1 + (*(s16 *)((u8 *)(arg1) + (2))));
    (*(void **)((u8 *)(arg0) + (0))) = temp_19;
    return arg1 + 4;
}

u16 *opu_unit_en(ScriptThread *th, u16 *pc)
{
    ScriptSub *sub = th->sub;
    SlotEntry *e = &owu_eff_status[sub->h14];
    u16 base;
    int i;
    u8 id;
    T6_Blk *b;

    switch ((s16)th->flags & 0xC000) {
    case 0:
        base = (((T6_BlkPool *)th->obj300)->serial + 0x10) & 0xFFF0;
        if (base > 0xFF7F) {
            base = 0x8000;
        }
        for (i = 0; i < e->b8; i++) {
            opu_unit(th, pc);
            b = ((T6_ThBlk *)th)->blk;
            id = e->list[i];
            b->serial = base + i;
            b->b18 = id;
        }
        ((T6_BlkPool *)th->obj300)->serial = base + 0x10;
        pc += 2;
        break;
    case 0x4000:
        opu_unit(th, pc);
        b = ((T6_ThBlk *)th)->blk;
        b->serial = sub->h1A + pc[2];
        pc += 3;
        break;
    }
    return pc;
}

u16 *opu_unit_ex(ScriptThread *th, u16 *pc)
{
    s16 *tbl;
    T6_Blk *b;

    if ((th->flags & 0xF00) == 0) {
        opu_unit(th, pc);
        tbl = (s16 *)((char *)pc + (s16)pc[2]);
        b = ((T6_ThBlk *)th)->blk; /* DEBT(CAST): see T6_ThBlk */
        pc += 3;
        b->f30[0] = tbl[0];
        b->f30[1] = tbl[1];
        b->f30[2] = tbl[2];
        b->f30[3] = tbl[3];
        b->f30[4] = tbl[4];
        b->f30[5] = tbl[5];
        b->f30[6] = tbl[6];
        b->f30[7] = tbl[7];
    }
    return pc;
}

INCLUDE_ASM("build/ee_asm/game/op/opu/opu_2A0820", opu_task);

u16 *func_002A0C58(ScriptThread *th, u16 *pc) {
    u16 idx = th->flags >> 12;
    ScriptSub *sub = th->sub;

    if (idx == 0) {
        sub->reg[3] = 0;
        sub->reg[2] = 0;
        sub->reg[1] = 0;
    } else {
        sub->reg[idx] = 0;
    }
    return pc + 1;
}

s16 *opu_et_eff(ScriptThread *th, s16 *pc)
{
    int unused[4]; /* DEBT(PADDING): the original frame has 16 more bytes */

    switch ((s16)th->flags & 0xF000) {
    case 0:
        opu_et_unit(D_00703E20.cur, pc[1], pc[2], -2);
        pc += 3;
        break;
    case 0x1000:
        ((int (*)(int, int))func_00298230)(-2, 0); /* DEBT(CAST): key passed as the int -2 (current thread) */
        pc += 2;
        break;
    case 0x2000:
        op_et_eff_off_signal(-2);
        pc += 1;
        break;
    }
    return pc;
}

extern void func_00295E28(void *, int, int);
extern void func_002B2DF0(void *, int, int, int);
extern void func_002B2E10(void *, int, int, int);
extern void func_002B2E30(void *, int, int, int);
extern void func_002B2E50(void *, void *, void *, s32);

s16 *opu_unit_etc(ScriptThread *th, s16 *pc)
{
    u8 *obj300 = (u8 *)th + 0x300;
    register ScriptSub *sub __asm__("$20") = th->sub;
    s16 flags = th->flags;

    switch (flags & 0xF000) {
    case 0: {
        register int id __asm__("$18") = pc[1];
        register int off __asm__("$16") = pc[2];
        u8 *p = (u8 *)opus_no_get(obj300, sub, id);
        register u8 *p20 __asm__("$3") = *(u8 **)(obj300 + 0x20);

        if (p == p20) {
            if (id != 0) {
                pc += 3;
            } else if ((u8 *)sub == p) {
                pc += 3;
            } else if (*(u16 *)(p + 0x1A) == 0) {
                pc = (s16 *)((u8 *)pc + off);
                break;
            } else {
                pc += 3;
            }
        } else {
            if ((u8 *)sub != p) {
                pc = (s16 *)((u8 *)pc + off);
            } else {
                pc += 3;
            }
        }
        break;
    }
    case 0x1000: {
        register u8 *p20 __asm__("$2") = *(u8 **)(obj300 + 0x20);
        s16 *tbl = *(s16 **)(obj300 + 0x10);
        int idx = (s16)(((u8 *)sub - p20) >> 8);
        int v = *tbl;

        if (v >= 0) {
            pc += 1;
            do {
                if (v == idx) {
                    goto case1_found;
                }
                v = *++tbl;
            } while (v >= 0);
            return pc;
        }
        pc += 1;
        break;
    case1_found:
        ((void (*)(void *, int))func_00295EB8)(obj300, v);
        func_00295E28(obj300, v, 1);
        *(u8 *)((u8 *)th + 0x210) = 1;
        *(s16 *)((u8 *)th + 0x216) = 0;
        *(u16 *)((u8 *)th + 0x218) -= 1;
        break;
    }
    case 0x2000: {
        u8 *p = (u8 *)opus_no_get(obj300, sub, pc[1]);
        register int off __asm__("$16") = pc[2];

        *(u16 *)(p + off) = *(u16 *)((u8 *)th + 0x214);
        pc += 3;
        break;
    }
    case 0x3000: {
        register int idx __asm__("$16") = pc[1];
        {
            register u8 *ptr __asm__("$2") = (u8 *)sub + idx;
            __asm__("" : "+r"(ptr));
            idx = *(s16 *)ptr;
        }

        if (idx != 0) {
            register int sh __asm__("$5") = idx << 8;
            register int pc2 __asm__("$2") = (u16)pc[2];
            register u8 *p20 __asm__("$4") = *(u8 **)(obj300 + 0x20);
            register u32 mask __asm__("$7") = 0x80000000;
            register int slot __asm__("$16") = pc2 & 3;
            register int off __asm__("$8") = pc[3];
            register u8 *base __asm__("$2") = p20 + sh;
            register u32 *wp __asm__("$3") = &((u32 *)base)[slot];
            register u8 *bp __asm__("$6");
            register u32 old __asm__("$4");
            register int one __asm__("$5");
            register u32 nv __asm__("$2");
            __asm__("" : "+r"(wp));
            bp = base + slot;
            __asm__("" : "+r"(wp), "+r"(bp), "+r"(mask), "+r"(off));
            old = *wp;
            __asm__ volatile("" : "+r"(old));
            one = 1;
            __asm__("" : "+r"(old), "+r"(one));
            nv = old & mask;
            nv = (u32)pc + nv + off;
            *wp = nv;
            bp[0x10] = one;
        }
        pc += 4;
        break;
    }
    case 0x4000: {
        void *fn = *(void **)(*(u8 **)(obj300 + 0x50) + 0x74);
        register int mode __asm__("$16") = pc[1];

        if (mode == 0) {
            __asm__("" : "+r"(mode));
            func_002B2DF0(fn, 0, 0, 1);
        }
        if (mode == 1) {
            __asm__("" : "+r"(mode));
            func_002B2E10(fn, 0, 0, 1);
        }
        if (mode == 2) {
            func_002B2E30(fn, 0, 0, 1);
        }
        if (mode == 3) {
            func_002B2E50(fn, 0, 0, 1);
        }
        pc += 2;
        break;
    }
    case 0x5000:
        {
            u32 trig = th->flags & 0x800;
            __asm__("" : "+r"(trig));
            trig <<= 16;
            __asm__("" : "+r"(trig));
            op_wot_triger(trig >> 16);
        }
        pc += 1;
        break;
    }
    return pc;
}

u16 *func_002A0FF0(ScriptThread *th, u16 *pc)
{
    T6_SubMove *sub = (T6_SubMove *)th->sub; /* DEBT(CAST): see T6_SubMove */
    int mode;

    sub->bBA = ((u8 *)pc)[2];
    mode = sub->bBA;
    sub->hA0 = pc[2];
    sub->hA2 = pc[3];
    switch (mode) {
    case 8:
    case 9:
        sub->v40[0] = sub->pos[0] * 16.0f;
        sub->v40[1] = sub->pos[1] * 16.0f;
        sub->v40[2] = sub->pos[2] * 16.0f;
        break;
    case 11:
        sub->fA4 = sub->pos[0];
        sub->v40[1] = sub->pos[1];
        sub->v40[2] = sub->pos[2];
        break;
    }
    return pc + 4;
}

typedef struct {
    s16 n;
    u8 pad2[5];
    u8 b7;
    float *p8;
    float *pC;
} OpuSplBuf;

typedef struct {
    u8 pad00[0x40];
    float v40[3];
    float f4C;
    u8 pad50[0x1C];
    float f6C;
    u8 pad70[0x20];
    float v90[3];
    u8 pad9C[4];
    u16 hA0;
    u16 hA2;
    u8 padA4[0x16];
    u8 bBA;
    u8 padBB;
    OpuSplBuf *pBC;
    u8 fC0[4];
} OpuSplSub;

extern void op_free(void *, void *);
extern void *op_malloc(void *, int);
extern void op_spline_xyz_table(float *, float *, int);
extern void op_spline_xyz(void *, float *, float *, int, float);
extern void func_002B6358(void *, void *, void *);
extern void func_002B56D8(void *, void *, void *);

s16 *opu_spl(ScriptThread *th, s16 *pc)
{
    OpuSplSub *sub = (OpuSplSub *)th->sub;
    OpuSplBuf *buf;
    s16 i;

    switch ((s16)th->flags & 0xF000) {
    case 0x0000: {
        OpuSplBuf *b;
        s16 n;
        s16 mode;
        s16 *tbl;
        float *dst;

        n = pc[1];
        op_free(*(void **)((u8 *)th + 0x3A8), sub->pBC);
        b = (OpuSplBuf *)op_malloc(*(void **)((u8 *)th + 0x3A8), (n << 5) | 0x10);
        sub->pBC = b;
        buf = b;
        buf->n = n;
        buf->p8 = (float *)(buf + 1);
        buf->pC = (float *)((u8 *)buf->p8 + (n << 4));
        dst = buf->p8;
        tbl = (s16 *)((u8 *)pc + pc[2]);
        mode = pc[3];
        for (i = 0; i < n; i++, tbl++) {
            OpuSplSub *t = (OpuSplSub *)opus_no_get((u8 *)th + 0x300, (void *)sub, *tbl);
            if (mode == 0) {
                dst[0] = t->v40[0];
                dst[1] = t->v40[1];
                dst[2] = t->v40[2];
            } else {
                dst[0] = t->v90[0];
                dst[1] = t->v90[1];
                dst[2] = t->v90[2];
            }
            dst += 4;
        }
        pc += 4;
        op_spline_xyz_table(b->pC, b->p8, n);
        if (mode == 0) {
            b->b7 = 1;
        } else {
            b->b7 = 0;
        }
        break;
    }
    case 0x1000: {
        OpuSplSub *t;
        i = pc[1];
        if (i != 0) {
            t = (OpuSplSub *)opus_no_get((u8 *)th + 0x300, (void *)sub, i);
        } else {
            t = sub;
        }
        buf = t->pBC;
        op_spline_xyz(th, buf->p8, buf->pC, buf->n, sub->f4C * (1.0f / 256.0f));
        if (pc[2] == 0) {
            func_002B5978(sub->v40, th, 1.0f);
        } else {
            func_002B5978(sub->v40, th, 16.0f);
        }
        func_002B5978(sub->v90, sub->v40, 0.0625f);
        pc += 3;
        break;
    }
    case 0x2000: {
        OpuSplSub *t;
        float f;
        i = pc[1];
        if (i != 0) {
            t = (OpuSplSub *)opus_no_get((u8 *)th + 0x300, (void *)sub, i);
        } else {
            t = sub;
        }
        buf = t->pBC;
        f = sub->f4C;
        op_spline_xyz(th, buf->p8, buf->pC, buf->n, f * (1.0f / 256.0f));
        if (sub->f6C == 0.0f) {
            f += 0.000001f;
        } else {
            f += sub->f6C;
        }
        op_spline_xyz((u8 *)th + 0x10, buf->p8, buf->pC, buf->n, f * (1.0f / 256.0f));
        if (pc[2] == 0) {
            func_002B5978(sub->v40, th, 1.0f);
        } else {
            func_002B5978(sub->v40, th, 16.0f);
            func_002B5978((u8 *)th + 0x10, (u8 *)th + 0x10, 16.0f);
        }
        func_002B5978(sub->v90, sub->v40, 0.0625f);
        func_002B5978((u8 *)th + 0x10, (u8 *)th + 0x10, 0.0625f);
        func_002B6358((u8 *)th + 0x40, sub->v90, (u8 *)th + 0x10);
        func_002B56D8(sub->fC0, (u8 *)th + 0x280, (u8 *)th + 0x40);
        pc += 3;
        break;
    }
    case 0x3000:
        sub->bBA = 10;
        sub->hA0 = pc[1];
        sub->hA2 = pc[2];
        pc += 3;
        break;
    }
    return pc;
}

typedef struct OpeAnmSub {
    u8 pad00[0x1E];
    u8 b1E;
    u8 pad1F[0xA8 - 0x1F];
    u8 bA8[3];
    u8 padAB[0xBB - 0xAB];
    u8 bBB;
    u8 padBC[4];
    s16 hC0;
    s16 hC2;
    s32 wC4;
    u8 padC8[0xE0 - 0xC8];
    u8 *pE0;
    u8 *pE4;
    u8 *pE8;
    u16 hEC;
    s16 hEE;
    s16 hF0;
    s16 hF2;
    s16 hF4;
} OpeAnmSub;

u16 *ope_anm(ScriptThread *th, u16 *pc)
{
    OpeAnmSub *sub = (OpeAnmSub *)th->sub;
    u8 *a = (u8 *)op_oef2_a_get(*(int *)((u8 *)th + (sub->b1E << 2) + 0x360), 4, pc[1]);
    register int c80 __asm__("$3") = 0x80;
    register int c1 __asm__("$2") = 1;
    register int c48 __asm__("$4") = 0x48;
    register int c100 __asm__("$5") = 0x100;
    register u8 *p __asm__("$6");
    register u8 *o300 __asm__("$4");

    __asm__ volatile("" : "+r"(c80), "+r"(c1), "+r"(c48), "+r"(c100));
    *(volatile s16 *)&sub->hC2 = c48;
    *(u8 * volatile *)&sub->pE0 = a;
    __asm__ volatile("" : : : "memory");
    p = sub->bA8;
    __asm__ volatile("" : "+r"(p));
    *(volatile u8 *)&sub->bBB = c1;
    __asm__ volatile("" : : : "memory");
    o300 = (u8 *)th + 0x300;
    __asm__ volatile("" : "+r"(o300));
    *(volatile s16 *)&sub->hC0 = c80;
    *(volatile s16 *)&sub->hF2 = c100;
    *(volatile s16 *)&sub->hF4 = 0;
    *(volatile s32 *)&sub->wC4 = 0;
    sub->bA8[0] = ((s16)th->flags & 0xE000) >> 13;
    p[1] = (th->flags & 0xE00) >> 9;
    p[2] = *(u8 *)&th->flags - 0x24;
    ((void (*)(void *, s32, void *))opus_draw_on)(o300, *(s16 *)((u8 *)th + 0x214), p);
    sub->pE4 = a + 0x10;
    sub->pE8 = (u8 *)(*(s16 *)(a + 0x10) + (s32)a);
    sub->hEC = 0xFFFF;
    sub->hEE = 0x200;
    sub->hF0 = 0x200;
    return pc + 2;
}

u16 *func_002A1538(ScriptThread *th, u16 *pc)
{
    T6_SubAnim *sub = (T6_SubAnim *)th->sub; /* DEBT(CAST): see T6_SubAnim */
    u16 flags = th->flags;
    int a;
    int b;
    s16 v;
    float f;

    switch ((s16)th->flags & 0xF000) {
    case 0x0000:
        sub->hC0 |= 0x8000;
        pc += 1;
        break;
    case 0x1000:
        a = ((u8 *)pc)[2];
        b = ((u8 *)pc)[3];
        if (a != 0) {
            f = *(float *)((u8 *)sub + a); /* DEBT(CAST): operand is a byte offset; DEBT(FAKE): temp f only on this path (keeps it in $f20) */
            sub->hF2 = f;
        }
        if (b != 0) {
            sub->hF4 = *(float *)((u8 *)sub + b);
        }
        pc += 3;
        break;
    case 0x2000:
        v = pc[1];
        if (flags & 0x200) {
            f = v;
            v = f * opus_cwidth_scale_get(sub->b18, th->b21E);
        }
        sub->hC6 = v;
        pc += 2;
        break;
    case 0x3000:
        sub->hC4 = pc[1];
        pc += 2;
        break;
    }
    return pc;
}

u16 *func_002A1658(ScriptThread *th, u16 *pc) {
    ScriptSub *sub = th->sub;
    s16 val = pc[1];

    if (th->flags & 0x1000) {
        sub->hC4 = val;
    } else {
        sub->hC6 = val;
    }
    return pc + 2;
}

u16 *func_002A1680(ScriptThread *th, u16 *pc) {
    th->sub->hC2 = pc[1];
    return pc + 2;
}

void func_002B2E50(void *, void *, void *, s32);
#include "vu0.h"

void func_002A1778(u8 *a, u8 *b);

u16 *func_002A1698(ScriptThread *th, u16 *pc)
{
    ScriptSub *sub = th->sub;

    *(u16 *)((u8 *)sub + 0xA8) = pc[1];
    switch (*(s16 *)((u8 *)th + 0x21A) & 0xF000) {
    case 0x0000:
        ((u8 *)sub)[0xBB] = 4;
        opus_draw_on((u8 *)th + 0x300, *(s16 *)((u8 *)th + 0x214));
        break;
    case 0x1000: {
        register u32 rgba __asm__("$7");
        VU0_LQC2(31, 0x40, sub);
        VU0_CTC2_NI(21, 0x437F0000);
        VU0_OP("vsub.xyzw $vf30, $vf0, $vf0");
        VU0_OP("vminii.xyzw $vf31, $vf31, I");
        VU0_OP("vmax.xyzw $vf31, $vf31, $vf30");
        VU0_OP("vftoi0.xyzw $vf31, $vf31");
        VU0_QMFC2_NI(rgba, 31);
        MMI_OP2Z("ppach", rgba, rgba);
        MMI_OP2Z("ppacb", rgba, rgba);
        func_002B2FF0(rgba, ((u8 *)pc)[2], ((u8 *)pc)[3]);
        break;
    }
    case 0x2000:
        ((void (*)(void *, void *, void *, s32))func_002B2E50)(func_002A1778, sub, pc, 1);
        break;
    }
    return pc + 2;
}

void func_002A1778(u8 *a, u8 *b)
{
    int rgba;

    __asm__ volatile(
        "lqc2        $vf31, 0x40(%1)\n"
        "lui         $2, (0x437F0000 >> 16)\n"
        "ctc2.ni     $2, $vi21\n"
        "vsub.xyzw   $vf30, $vf0, $vf0\n"
        "vminii.xyzw $vf31, $vf31, I\n"
        "vmax.xyzw   $vf31, $vf31, $vf30\n"
        "vftoi0.xyzw $vf31, $vf31\n"
        "qmfc2.ni    %0, $vf31\n"
        "ppach       %0, $0, %0\n"
        "ppacb       %0, $0, %0\n"
        : "=&r"(rgba) : "r"(a) : "$2", "memory");
    func_002B2FF0(rgba, b[2], b[3]);
}

extern u8 owu_chr_drawoff_back[];
void func_002B3EA8(void *, s32, s32, s32);
void func_002B3ED0(void *, void *, s32);

u16 *ope_anm_sippo(ScriptThread *th, u16 *pc)
{
    u8 *sub = (u8 *)th->sub;
    u8 *a = (u8 *)op_oef2_a_get(*(int *)((u8 *)th + (sub[0x1E] << 2) + 0x360), 4, pc[1]);
    int i;
    int cnt;
    int extra;
    int base_sz;

    opus_draw_on((u8 *)th + 0x300, *(s16 *)((u8 *)th + 0x214));
    *(s16 *)(sub + 0xC0) = 0x80;
    *(s16 *)(sub + 0xC2) = 0x48;
    *(s32 *)(sub + 0xC4) = 0;
    *(s16 *)(sub + 0xE8) = 0;

    {
        register s16 *p __asm__("$6") = (s16 *)(a + 0x10);
        s16 *p0 = p;
        register int sum __asm__("$5") = 0;
        register int tmp __asm__("$3");
        register int n __asm__("$5");
        register int mask __asm__("$4");
        int sz;

        for (i = 0; i < *(s16 *)(a + 6); i++) {
            sum += p[1];
            p += 4;
        }
        {
            register int m1 __asm__("$2") = -1;
            tmp = sum + 255;
            if (m1 < sum) {
                tmp = sum;
            }
        }
        mask = 0x7FFFFFF0;
        n = tmp >> 8;
        *(s16 *)(sub + 0xE8) = n;
        sz = (n * 4 + 0xF) & mask;
        cnt = (s16)pc[2];
        extra = cnt << 4;
        base_sz = extra + 0x10;
        if ((*(u16 *)((u8 *)th + 0x21A) & 0x1000) == 0) {
            extra = 0;
        }
        *(void **)(sub + 0xBC) = op_malloc(*(void **)((u8 *)th + 0x3A8), base_sz + sz + extra);
        func_002B3EA8(*(void **)(sub + 0xBC), 0, 0x8001, cnt);
        {
            register u8 *base __asm__("$2") = *(u8 **)(sub + 0xBC);
            register u8 **dst __asm__("$8");
            p = p0;
            i = 0;
            dst = (u8 **)((base + base_sz) + extra);
            ((union { u8 **p; s16 h; } *)(sub + 0xE0))->p = dst;
            for (; i < *(s16 *)(a + 6); i++) {
                u8 *ent = a + p[0];
                int j;
                for (j = 0; j < p[1]; j += 0x100) {
                    *dst++ = ent;
                }
                p += 4;
            }
        }
    }

    switch (*(u16 *)((u8 *)th + 0x21A) & 0xF000) {
    case 0x0000:
        sub[0xBB] = 10;
        pc += 3;
        break;
    case 0x1000: {
        register u8 *base __asm__("$3");
        register u_long128 *q __asm__("$8");
        sub[0xBB] = 17;
        func_002B3ED0(*(void **)(sub + 0xBC), sub + 0x90, 0);
        base = *(u8 **)(sub + 0xBC);
        q = (u_long128 *)(base + base_sz);
        for (i = 0; i < cnt; i++) {
            *q++ = *(u_long128 *)(sub + 0x90);
        }
        *(u16 *)(sub + 0xA8) = pc[3];
        *(u16 *)(sub + 0xAA) = pc[4];
        if (owu_chr_drawoff_back[sub[0x18]] & sub[0xB3]) {
            *(u16 *)(sub + 0xB0) |= 1;
        }
        pc += 5;
        break;
    }
    }
    return pc;
}

u16 *func_002A1A60(ScriptThread *th, u16 *pc)
{
    ScriptSub *sub = th->sub;
    ScriptSub *orig_sub = sub;
    u8 *entry;
    s32 step;

    switch (th->flags & 0x7000) {
    case 0x0000: {
        u16 cnt;
        register u8 *mem __asm__("$7");

        ((u8 *)sub)[0xBB] = 9;
        cnt = pc[1];
        {
            u8 *p = (u8 *)op_malloc(*(void **)((u8 *)th + 0x3A8), cnt * 0x50 + 0x70);
            *(u8 * volatile *)((u8 *)sub + 0xBC) = p;
            mem = p;
        }
        __asm__("" : "+r"(mem));
        *(volatile u16 *)mem = cnt;
        entry = mem + 0x20;
        *(volatile u16 *)(mem + 2) = 0;
        *(volatile u16 *)(mem + 4) = *(u16 *)((u8 *)sub + 0xC4);
        *(volatile u16 *)(mem + 6) = *(u16 *)((u8 *)sub + 0xC6);
        *(volatile u32 *)(mem + 8) = *(volatile u32 *)((u8 *)sub + 0xC8);
        __asm__("" : "+r"(mem));
        *(u8 **)((u8 *)sub + 0xA8) = mem;
        while (cnt != 0) {
            *(u32 *)entry = 0;
            cnt--;
            entry += 0x50;
        }
        {
            register u16 *npc __asm__("$18") = pc + 2;
            __asm__("" : "+r"(npc));
            pc = npc;
        }
        opus_draw_on((u8 *)th + 0x300, *(s16 *)((u8 *)th + 0x214));
        break;
    }
    case 0x1000:
        step = 4;
    common:
        if (*(s16 *)((u8 *)th + 0x212) == 0) {
            if (((u8 *)sub)[0xBB] == 9) {
                register u8 *hdr __asm__("$7") = *(u8 **)((u8 *)sub + 0xA8);
                u16 cur = *(u16 *)(hdr + 2);
                u16 max = *(u16 *)hdr;
                register u32 next_cur __asm__("$5") = cur + 1;
                u32 idx = cur % max;

                *(u16 *)(hdr + 2) = next_cur;
                entry = hdr + (idx * 0x50 + 0x20);
                MMI_SQ_ZERO(0, entry);
                {
                    s32 off = (s16)pc[1];
                    entry[9] = 1;
                    *(u32 *)(entry + 4) = 0;
                    *(u8 **)entry = (u8 *)pc + off;
                }
                MMI_SQ_ZERO(0x4C, entry);
                {
                    register u32 d __asm__("$3") = ((u32)((u8 *)orig_sub - *(u8 **)((u8 *)th + 0x320))) >> 8;
                    *(volatile u16 *)(entry + 0x4C) = d;
                }
                __asm__ volatile("" : : : "memory");
                *(u_long128 *)(entry + 0x20) = *(u_long128 *)((u8 *)orig_sub + 0x60);
                {
                    register u_long128 q80 __asm__("$2") = *(u_long128 *)((u8 *)orig_sub + 0x80);
                    *(u_long128 *)(entry + 0x30) = q80;
                }
                {
                    register s32 fl __asm__("$3") = *(s16 *)((u8 *)th + 0x21A);
                    if (fl & 0x8000) {
                        ((void (*)(void *, void *, float))func_002B5978)(entry + 0x10, (u8 *)orig_sub + 0x90, 16.0f);
                    } else {
                        *(u_long128 *)(entry + 0x10) = *(u_long128 *)((u8 *)orig_sub + 0x40);
                    }
                }
            }
            *(u32 *)(entry + 0x3C) = 0;
        }
        pc = (u16 *)((u8 *)pc + step);
        break;
    case 0x2000:
        sub = opus_no_get((u8 *)th + 0x300, sub, (s16)pc[2]);
        step = 6;
        goto common;
    }
    return pc;
}

u16 *func_002A1C90(ScriptThread *th, s16 *pc) {
    register ScriptThread *s1 __asm__("$17") = th;
    register s16 *s0 __asm__("$16") = pc;
    u8 *obj300 = (u8 *)s1 + 0x300;
    ScriptSub *sub = s1->sub;
    register ScriptSub *p __asm__("$3");
    u32 rgba;

    switch (s1->flags >> 12) {
    case 0:
        p = opus_no_get(obj300, sub, s0[1]);
        VU0_LQC2(31, 0x40, p);
        s0 += 2;
        break;
    case 1:
        p = opus_no_get(obj300, sub, s0[1]);
        VU0_CTC2_NI(21, 0x3C000000);
        VU0_LQC2(31, 0x40, p);
        VU0_OP("vmulw.xyz $vf31, $vf31, $vf31w");
        VU0_OP("vmuli.xyz $vf31, $vf31, I");
        *(u32 *)((u8 *)s1 + 0xC) = 0x43000000;
        VU0_LQC2(30, 0, s1);
        VU0_OP("vmove.w $vf31, $vf30");
        s0 += 2;
        break;
    case 2:
        ((s32 *)s1)[0] = s0[1];
        ((s32 *)s1)[1] = s0[2];
        ((s32 *)s1)[2] = s0[3];
        ((s32 *)s1)[3] = s0[4];
        VU0_LQC2(31, 0, s1);
        VU0_OP("vitof0.xyzw $vf31, $vf31");
        s0 += 5;
        break;
    case 3:
        VU0_LQC2(31, 0x30, sub);
        s0 += 1;
        break;
    case 4:
        p = opus_no_get(obj300, sub, s0[1]);
        VU0_LQC2(31, 0x30, p);
        s0 += 2;
        break;
    case 5:
        ((s32 *)s1)[0] = ((u8 *)sub)[0xC8];
        ((s32 *)s1)[1] = ((u8 *)sub)[0xC9];
        ((s32 *)s1)[2] = ((u8 *)sub)[0xCA];
        ((s32 *)s1)[3] = s0[1];
        VU0_LQC2(31, 0, s1);
        VU0_OP("vitof0.xyzw $vf31, $vf31");
        s0 += 2;
        break;
    }

    VU0_CTC2_NI(21, 0x437F0000);
    VU0_OP("vsub.xyzw $vf30, $vf0, $vf0");
    VU0_OP("vminii.xyzw $vf31, $vf31, I");
    VU0_OP("vmax.xyzw $vf31, $vf31, $vf30");
    VU0_OP("vftoi0.xyzw $vf31, $vf31");
    VU0_QMFC2_NI(rgba, 31);
    MMI_OP2Z("ppach", rgba, rgba);
    MMI_OP2Z("ppacb", rgba, rgba);
    *(u32 *)((u8 *)sub + 0xC8) = rgba;
    return (u16 *)s0;
}

void func_001750A8(s32);
void func_001750E8(float, float, float, float);
void func_00175110(float, float, float, float, float, float);
void func_00175140(void);
void func_00175148(void *, void *);
void opus_map_rgba_free(void);
void func_002A2168(void);
void func_002A21A8(void *arg0);

u16 *opu_rgba_map(ScriptThread *th, u16 *pc)
{
    ScriptSub *sub = th->sub;

    switch (th->flags & 0xF000) {
    case 0x0000:
        VU0_LQC2(31, 0x40, sub);
        pc += 1;
        break;
    case 0x1000:
        opus_map_rgba_free();
        return pc + 1;
    case 0x2000:
        yiRenderDisable(4);
        yiRenderEnable(1);
        ((float *)th)[0] = ((float *)th)[1] = ((float *)th)[2] = ((float *)th)[3] = 1.0f;
        func_00173720(th);
        ((void (*)(void *))func_002A2168)((u8 *)sub + 0x40);
        return pc + 1;
    case 0x3000:
        yiRenderEnable(4);
        yiRenderDisable(1);
        MMI_SQ_ZERO(0, th);
        func_00173720(th);
        func_002A21A8(th);
        return pc + 1;
    case 0x4000:
        func_001750A8(4);
        func_001750E8(
            *(float *)((u8 *)sub + 0x40) * (1.0f / 4096.0f),
            *(float *)((u8 *)sub + 0x44) * (1.0f / 4096.0f),
            *(float *)((u8 *)sub + 0x48) * (1.0f / 4096.0f),
            *(float *)((u8 *)sub + 0x3C) * (1.0f / 4096.0f));
        return pc + 1;
    case 0x5000:
    case 0xA000:
        func_00175140();
        return pc + 1;
    case 0x6000:
        func_002A21A8((u8 *)sub + 0x40);
        return pc + 1;
    case 0x7000:
        yiSetDrawMask(yiGetDrawMask() | 4);
        return pc + 1;
    case 0x8000:
        yiSetDrawMask(yiGetDrawMask() & 0xFFFFFFFBu);
        return pc + 1;
    case 0x9000:
        func_001750A8(8);
        func_00175110(
            *(float *)((u8 *)sub + 0x40) * (1.0f / 256.0f),
            *(float *)((u8 *)sub + 0x44) * (1.0f / 256.0f),
            *(float *)((u8 *)sub + 0x48) * (1.0f / 256.0f),
            *(float *)((u8 *)sub + 0x30) * (1.0f / 16.0f),
            *(float *)((u8 *)sub + 0x34) * (1.0f / 16.0f),
            *(float *)((u8 *)sub + 0x38) * (1.0f / 16.0f));
        return pc + 1;
    case 0xB000: {
        float c[4];
        float p[4];
        c[0] = *(float *)((u8 *)sub + 0x40) * (1.0f / 256.0f);
        c[1] = *(float *)((u8 *)sub + 0x44) * (1.0f / 256.0f);
        c[2] = *(float *)((u8 *)sub + 0x48) * (1.0f / 256.0f);
        c[3] = 1.0f;
        p[0] = *(float *)((u8 *)sub + 0x30) * (1.0f / 16.0f);
        p[1] = *(float *)((u8 *)sub + 0x34) * (1.0f / 16.0f);
        p[2] = *(float *)((u8 *)sub + 0x38) * (1.0f / 16.0f);
        p[3] = 1.0f;
        func_00175148(c, p);
        func_00175140();
        return pc + 1;
    }
    }
    {
        register u32 r2 __asm__("$2");
        register u32 r3 __asm__("$3");
        __asm__ volatile("" : : : "$2", "$3");
        r2 = 0x3F800000;
        r3 = 0x3C000000;
        VU0_CTC2_NI(21, r2);
        VU0_QMTC2_NI(29, r3);
        VU0_OP("vmulx.xyzw $vf31, $vf31, $vf29x");
        VU0_OP("vsub.xyzw $vf30, $vf0, $vf0");
        VU0_OP("vminii.xyzw $vf31, $vf31, I");
        VU0_OP("vmax.xyzw $vf31, $vf31, $vf30");
        VU0_SQC2(31, 0, th);
    }
    yiRenderEnable(4);
    func_00173720(th);
    return pc;
}

void opus_map_rgba_free(void)
{
    float v[8]; /* DEBT(PADDING): only the first 4 floats are used, 32 bytes needed for the frame */

    v[0] = v[1] = v[2] = v[3] = 1.0f;
    yiRenderDisable(4);
    func_00173720(v);
    func_002A2168();
}

void func_002A2168(void) {
    if (D_00703FF0.flagF) {
        func_00173650(D_00703FF0.buf);
        D_00703FF0.flagF = 0;
    }
}

void _m2c_func_002A21A8_yiGetBackColor(int *v) __asm__("yiGetBackColor");
void _m2c_func_002A21A8_func_00173650(void *) __asm__("func_00173650");
/* DEBT(CAST) */
void func_002A21A8(void *arg0) {
    s32 sp[4];
    if (D_00703FF0.flagF == 0) {
        D_00703FF0.flagF = 1;
        _m2c_func_002A21A8_yiGetBackColor((s32 *) D_00703FF0.buf);
    }
    sp[0] = (s32) (*(float *)((u8 *)(arg0) + (0)));
    sp[1] = (s32) (*(float *)((u8 *)(arg0) + (4)));
    sp[2] = (s32) (*(float *)((u8 *)(arg0) + (8)));
    sp[3] = (s32) (*(float *)((u8 *)(arg0) + (0xC)));
    _m2c_func_002A21A8_func_00173650(sp);
}
