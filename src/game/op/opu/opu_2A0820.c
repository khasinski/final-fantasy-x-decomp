/* tu_319 0x2a0820-0x2a2220: medium; ~opu (config/tu_map.tsv) */
/* Module guess: event-script VM / field-event runtime (no __FILE__ string found for this range). */
#include "common.h"
#include "ffx/q7.h"
#include "ffx/w9.h"
#include "ffx/t6.h"
#include "ffx/v6.h"
#include "ffx/w10.h"

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

INCLUDE_ASM("build/ee_asm/game/op/opu/opu_2A0820", opu_unit);

INCLUDE_ASM("build/ee_asm/game/op/opu/opu_2A0820", opu_unit_en);

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

INCLUDE_ASM("build/ee_asm/game/op/opu/opu_2A0820", opu_unit_etc);

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

INCLUDE_ASM("build/ee_asm/game/op/opu/opu_2A0820", opu_spl);

INCLUDE_ASM("build/ee_asm/game/op/opu/opu_2A0820", ope_anm);

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

INCLUDE_ASM("build/ee_asm/game/op/opu/opu_2A0820", func_002A1698);

INCLUDE_ASM("build/ee_asm/game/op/opu/opu_2A0820", func_002A1778);

INCLUDE_ASM("build/ee_asm/game/op/opu/opu_2A0820", ope_anm_sippo);

INCLUDE_ASM("build/ee_asm/game/op/opu/opu_2A0820", func_002A1A60);

INCLUDE_ASM("build/ee_asm/game/op/opu/opu_2A0820", func_002A1C90);
INCLUDE_RODATA("build/ee_asm/game/op/opu/opu_2A0820/rodata", jtbl_005755D0);

INCLUDE_ASM("build/ee_asm/game/op/opu/opu_2A0820", opu_rgba_map);

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

INCLUDE_ASM("build/ee_asm/game/op/opu/opu_2A0820", func_002A21A8);
