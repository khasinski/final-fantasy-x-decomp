/* tu_322 0x2a6fe8-0x2ac750: low; ~op_mdc_size_get_main (config/tu_map.tsv) */
/* DEBT(NAME): module and names guessed: script call wrappers (see w10.h). */
#include "common.h"
#include "ffx/q7.h"
#include "ffx/w10.h"
#include "ffx/t6.h"
#include "ffx/v6.h"
#include "ffx/r6.h"
#include "ffx/s6.h"
#include "ffx/r7.h"

INCLUDE_ASM("build/ee_asm/game/op/opu/opu_2A6FE8", op_mdc_size_get_main);

int func_002A7120(int a, int b, int c)
{
    return op_mdc_size_get_main(a, b, c, 1);
}

INCLUDE_ASM("build/ee_asm/game/op/opu/opu_2A6FE8", func_002A7140);

void func_002A72F8(s32 a, s32 b, s32 c, s32 d) {
    func_002A7140(a, b, c, 0, 1, d);
}

void func_002A7308(s32 a, s32 b, s32 c, s32 d) {
    func_002A7140(a, b, c, 1, 1, d);
}

s32 func_002A7318(char *a, s32 i) {
    a += i * 16;
    return *(s32 *)(a + 0x10); /* DEBT(CAST): 16-byte entry type unknown, word at +0x10 (i.e. member 0 of the next entry) */
}

INCLUDE_ASM("build/ee_asm/game/op/opu/opu_2A6FE8", opus_mdc_free);

void func_002A7420(int id, int val)
{
    T6_Slot16 *s;
    int i;

    if (val > 0x1EFFFFF) {
        return;
    }
    s = (T6_Slot16 *)D_006F37E0; /* DEBT(CAST): see T6_Slot16 */
    for (i = 0; i < 8; i++, s++) {
        if (s->id == id) {
            goto found;
        }
    }
    s = (T6_Slot16 *)D_006F37E0;
    for (i = 0; i < 8; i++, s++) {
        if (s->id == 0) {
            goto found;
        }
    }
    func_00120108(D_005756A0);
    func_002EA328(1);
found:
    s->id = id;
    s->val = val;
}

INCLUDE_ASM("build/ee_asm/game/op/opu/opu_2A6FE8", func_002A74A8);

void op_mdc_mem_transfer_cue_free_all(void)
{
    Slot16 *s = D_006F37E0;
    int i;

    for (i = 7; i >= 0; i--) {
        s->id = 0;
        s++;
    }
}

void op_mdc_mem_transfer_cue_free(int id)
{
    int i;

    for (i = 0; i < 8; i++) {
        if (D_006F37E0[i].id == id) {
            D_006F37E0[i].id = 0;
            return;
        }
    }
}

INCLUDE_ASM("build/ee_asm/game/op/opu/opu_2A6FE8", func_002A7620);

INCLUDE_ASM("build/ee_asm/game/op/opu/opu_2A6FE8", opus_mdc_break_make_VitaSafe);

INCLUDE_ASM("build/ee_asm/game/op/opu/opu_2A6FE8", func_002A7BA8);

INCLUDE_ASM("build/ee_asm/game/op/opu/opu_2A6FE8", func_002A81D0);
INCLUDE_RODATA("build/ee_asm/game/op/opu/opu_2A6FE8/rodata", jtbl_00575780);

void func_002A8460(EntList *l, int n, int c, int d)
{
    l->h0 = 0;
    l->h2 = n;
    l->h4 = c;
    l->h6 = d;
    l->h8 = 0;
    l->p18 = (Ent20 *)(l + 1);
    l->p1C = l->p18 + n;
}

INCLUDE_ASM("build/ee_asm/game/op/opu/opu_2A6FE8", op_2point_shadow);

INCLUDE_ASM("build/ee_asm/game/op/opu/opu_2A6FE8", func_002A88F8);

INCLUDE_ASM("build/ee_asm/game/op/opu/opu_2A6FE8", func_002A8D08);

s16 *opu_vibration(ScriptThread *th, s16 *pc)
{
    ScriptSub *sub = th->sub;
    int *r;

    if (((s16)th->flags & 0xF000) == 0) {
        r = op_oef2_a_get(th->res[sub->b1E], 5, pc[1]);
        func_0014D468(7);
        func_0014D3F0(7, pc[2], (int)r); /* DEBT(TYPE): prototype takes an int */
        pc += 3;
    }
    return pc;
}

u16 *opu_et_ovl(ScriptThread *th, u16 *pc)
{
    ScriptSub *sub = th->sub;
    u16 *dst = SCRIPT_JUMP_AT(pc, 2);
    s16 v = pc[1];

    switch ((s16)th->flags & 0xF000) {
    case 0:
        break;
    case 0x1000:
        sub->a8.h = v;
        sub->pAC = dst;
        sub->bBB = 11;
        opus_draw_on((IdList *)th->obj300, th->h214); /* DEBT(CAST): obj300 is described as bytes */
        break;
    }
    return pc + 3;
}

INCLUDE_ASM("build/ee_asm/game/op/opu/opu_2A6FE8", opu_et_etc);
INCLUDE_RODATA("build/ee_asm/game/op/opu/opu_2A6FE8/rodata", jtbl_005757A0);

s16 *opu_bind2(ScriptThread *th, s16 *pc)
{
    Chr *c = owu_chr_hd[th->sub->b18];
    int n;
    s16 *t;

    if (((s16)th->flags & 0xF000) == 0) {
        n = Ch_IdGetEffectTable(c);
        if (n >= 10) {
            func_00120108(D_005757F0, n);
            func_002EA328(1);
        }
        t = (s16 *)((char *)pc + pc[1]) + n;
        pc = (s16 *)(*t + (int)t); /* DEBT(CAST): table entries are byte offsets from themselves */
    }
    return pc;
}

u16 *func_002A9470(ScriptThread *th, u16 *pc)
{
    ResEntry *e = &owu_chr_status[opus_get_chr_status_index(owu_chr_hd[th->sub->b18], 0, 0)];

    switch ((s16)th->flags & 0xF000) {
    case 0:
        e->b17 |= 1;
        pc += 2;
        break;
    case 0x1000:
        e->b17 &= ~1;
        pc += 2;
        break;
    }
    return pc;
}

u16 *opu_mdmap(ScriptThread *th, u16 *pc)
{
    ScriptSub *sub = th->sub;

    switch ((s16)th->flags & 0xF000) {
    case 0:
        yiDObjToOMD(0x6800000, 0);
        pc += 1;
        break;
    case 0x1000:
        pc += 1;
        op_unit_m_scale(th->m80, sub->f3C * (1.0f / 1024));
        func_002B5348((int)th->m80, (int)th->m80, (int)sub->v30, (int)&sub->f90); /* DEBT(TYPE): prototype takes ints */
        func_002B56D8(th->m80, opus_local_get(th, sub), th->m80);
        func_002B56D8(th->mC0, th->m2C0, th->m80);
        op_md_draw_map_test(0x6800000, (int)th->mC0, 0x1F00000); /* DEBT(TYPE): takes the matrix as an int */
        break;
    case 0x2000: /* DEBT(FAKE): empty case, gives the compare tree of the original */
        break;
    }
    return pc;
}

INCLUDE_ASM("build/ee_asm/game/op/opu/opu_2A6FE8", opu_encount);
INCLUDE_RODATA("build/ee_asm/game/op/opu/opu_2A6FE8/rodata", jtbl_00575820);

INCLUDE_ASM("build/ee_asm/game/op/opu/opu_2A6FE8", func_002A9960);

INCLUDE_ASM("build/ee_asm/game/op/opu/opu_2A6FE8", func_002A9A70);

INCLUDE_ASM("build/ee_asm/game/op/opu/opu_2A6FE8", op_ota_encount1_draw);

INCLUDE_ASM("build/ee_asm/game/op/opu/opu_2A6FE8", func_002A9F10);

int func_002AA6C8(int res, int start, int n)
{
    int total = 0;
    int i;

    for (i = 0; i < n; i++) {
        total += ((s16 *)op_oef2_a_get(res, 4, start++))[9]; /* DEBT(CAST): s16 count at 0x12 of the entry */
    }
    return total * 16 + (0x110 + n * 0x70);
}

INCLUDE_ASM("build/ee_asm/game/op/opu/opu_2A6FE8", opus_encount4_init);

INCLUDE_ASM("build/ee_asm/game/op/opu/opu_2A6FE8", opus_encount4_calc);

INCLUDE_ASM("build/ee_asm/game/op/opu/opu_2A6FE8", func_002AAF30);

INCLUDE_ASM("build/ee_asm/game/op/opu/opu_2A6FE8", func_002AB178);

INCLUDE_ASM("build/ee_asm/game/op/opu/opu_2A6FE8", func_002AB3F8);

INCLUDE_ASM("build/ee_asm/game/op/opu/opu_2A6FE8", func_002AB678);

s16 *opu_dvd(ScriptThread *th, s16 *pc)
{
    int id;
    int i;

    switch (pc[1]) {
    case 0:
        Ch_DataRead(pc[2]);
        pc += 3;
        break;
    case 1:
        if (Ch_DataReadSync(pc[2]) == 1) {
            th->f210 = 1;
            break;
        }
        pc += 3;
        break;
    case 2:
        ChN_ReadSystemMGRPstart(pc[2], pc[3]);
        pc += 4;
        break;
    case 3:
        if (ChN_ReadSystemMGRPsync(pc[2], pc[3]) == 1) {
            th->f210 = 1;
            break;
        }
        ChN_ReadSystemMGRP(pc[2], pc[3]);
        pc += 4;
        break;
    case 4:
        id = pc[2];
        pc += 3;
        func_00102B98(id);
        opus_get_chr_status_index_by_chrno(id);
        break;
    case 5:
        id = pc[2];
        i = opus_get_chr_status_index_by_chrno(id);
        if (i >= 0) {
            if (owu_chr_status[i].chr == 0) {
                pc += 4;
                break;
            }
            Ch_Dispose((int)owu_chr_status[i].chr); /* DEBT(TYPE): prototype takes an int */
            ChN_DataDispose(id, 1);
            ChN_DisposeSystemMGRP(id, pc[3]);
        }
        pc += 4;
        break;
    }
    return pc;
}

INCLUDE_ASM("build/ee_asm/game/op/opu/opu_2A6FE8", opu_file);

INCLUDE_ASM("build/ee_asm/game/op/opu/opu_2A6FE8", opu_mimic);

INCLUDE_ASM("build/ee_asm/game/op/opu/opu_2A6FE8", opp_mimic);

ResEntry *opus_mimic_check(Chr *key)
{
    ResEntry *e = &owu_chr_status[opus_get_chr_status_index(key, 0, 0)];

    if (e->key == 0x10FB) {
        return e;
    }
    if (e->key == 0x10FC) {
        return e;
    }
    if (e->key == 0x10FD) {
        return e;
    }
    if (e->key == 0x1100) {
        return e;
    }
    return 0;
}

INCLUDE_ASM("build/ee_asm/game/op/opu/opu_2A6FE8", opus_mdc_size_get_mimic);

INCLUDE_ASM("build/ee_asm/game/op/opu/opu_2A6FE8", opus_mdc_make_mimic);
