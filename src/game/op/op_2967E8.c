/* tu_316 0x2967e8-0x29a8a8: medium; ~op (config/tu_map.tsv) */
/* Module guess: event-script VM / field-event runtime (no __FILE__ string found for this range). */
#include "common.h"
#include "ffx/w9.h"
#include "ffx/q6.h"
#include "ffx/t6.h"
#include "ffx/r6.h" /* needed by t6.h */
#include "ffx/u4.h"
#include "ffx/g4.h"
#include "ffx/v6.h"
#include "ffx/u5.h"

INCLUDE_ASM("build/ee_asm/game/op/op_2967E8", func_002967E8);

INCLUDE_ASM("build/ee_asm/game/op/op_2967E8", opu_init);

INCLUDE_ASM("build/ee_asm/game/op/op_2967E8", opu_et_unit);

INCLUDE_ASM("build/ee_asm/game/op/op_2967E8", opu_et_init);

int func_002971F0(int a, int b, int c, int d) /* DEBT(TYPE): b..d only forwarded */
{
    return opu_et_unit(a + 0x10, b, c, d);
}

INCLUDE_ASM("build/ee_asm/game/op/op_2967E8", func_00297210);

void func_002973A8(int a) {
    func_00297210(D_0054D5E8[0], a);
}

INCLUDE_ASM("build/ee_asm/game/op/op_2967E8", func_002973B8);

void func_00297520(int a) {
    func_002973B8(D_0054D5E8[0], a);
}

void func_00297530(int a) {
    op_oef2_set2(a);
    opu_et_unit(a, 0, 0, -1);
}

void func_00297568(int a) {
    func_00297530(a);
}

void func_00297570(int a) {
    func_002973A8(a);
}

void func_00297578(int a) {
    HwRegs2008250 *hw = &D_2008250;
    int v = a;

    if (D_007649A0 != 0 && (hw->h40 & 0x20)) {
        v = hw->w98;
    }
    D_00703E20.w8 = v;
    func_00297530(v);
}

void func_002975B0(void) {
    int w = D_00703E20.w8;

    if (w != 0) {
        func_002973A8(w);
        D_00703E20.w8 = 0;
    }
}

void op_et_battle_init(int h)
{
    HwRegs2008250 *pad = &D_2008250;

    func_00297650();
    if (D_007649A0 != 0 && (pad->h40 & 1)) {
        h = pad->w80;
    }
    D_00703E20.cur = h;
    func_00297530(h);
}

void func_00297650(void) {
    int cur = D_00703E20.cur;

    if (cur != 0) {
        func_002973A8(cur);
        D_00703E20.cur = 0;
    }
}

INCLUDE_ASM("build/ee_asm/game/op/op_2967E8", op_et_monster_init);

INCLUDE_ASM("build/ee_asm/game/op/op_2967E8", op_et_monster_free);

void func_002979B8(void) {
    int i;

    for (i = 0; i < 0xF0; i++) {
        if (owu_chr_status[i].chr != 0) {
            op_et_monster_free(owu_chr_status[i].chr);
        }
    }
}

int func_00297A10(int h)
{
    int i;

    if (h == 0) {
        return -1;
    }
    for (i = 0; i < 8; i++) {
        if (D_00703E20.b[i] == h) {
            return 0;
        }
    }
    for (i = 0; i < 8; i++) {
        if (D_00703E20.b[i] == 0) {
            D_00703E20.b[i] = h;
            func_00297530(h);
            return 1;
        }
    }
    return; /* DEBT(TYPE): no value when the pool is full */
}

void op_et_weapon_init(int h, int f)
{
    int i;

    for (i = 0; i < 4; i++) {
        if (D_00703E20.a[i] == h) {
            return;
        }
    }
    for (i = 0; i < 4; i++) {
        if (D_00703E20.a[i] == 0) {
            D_00703E20.a[i] = h;
            D_00703E20.b68[i] = 0;
            D_00703E20.b6C[i] = 0;
            D_00703E20.flags[i] = f;
            func_00297530(h);
            return;
        }
    }
}

void op_et_weapon_free(int v)
{
    int i = opus_get_weapon_index(v);

    if (i >= 0) {
        func_00120108(D_00574C88);
        func_002973A8(D_00703E20.a[i]);
        D_00703E20.a[i] = 0;
        D_00703E20.b68[i] = 0;
        D_00703E20.b6C[i] = 0;
        D_00703E20.flags[i] = 0xFF;
    }
}

void func_00297BC0(void) {
    int i;

    for (i = 0; i < 4; i++) {
        if (D_00703E20.a[i] != 0) {
            op_et_weapon_free(D_00703E20.a[i]);
        }
    }
}

void op_et_weapon_effect_on(void) {
}

INCLUDE_ASM("build/ee_asm/game/op/op_2967E8", op_et_weapon_afterimage);

void func_00297CE8(Chr *key) {
    func_00298230(key, 0x8000);
}

void op_et_battle_effect_init(void) {
    func_00120108(D_00574CA8);
    D_00704012 = 1;
    op_ovl_effect_free();
    if (D_0054D5E8[0] != 0) {
        D_0054D5E8[0]->b3A = 0;
    }
}

void op_et_battle_effect_free(void)
{
    int h;

    func_00297BC0();
    h = D_00703E20.cur;
    if (h != 0) {
        func_00297650();
        op_et_battle_init(h);
    }
    op_oef2_sep_free_all(0xFFFF);
    func_0029A7B8();
    opus_all_clut_dispose();
    func_00298D80();
    func_00120108(D_00574CD8);
    D_00704012 = 0;
}

void func_00297DA8(void) {
}

void op_ovl_effect_init(void)
{
    func_00120108(D_00574D08);
    op_oef2_tex_clut_ovl_clear(0xFFFF);
    op_oef2_sep_free_all(0xFFFF);
    op_mdc_mem_transfer_cue_free_all();
    ((int (*)(void))opus_clip_off_all_in_battle)(); /* DEBT(CAST): the original call site sees an int-returning declaration */
    D_00703FF0.bA = 1;
    D_00703FF0.hC = 0;
    D_00703FF0.b23 = 0;
}

void op_ovl_effect_free(void)
{
    func_00120108(D_00574D28);
    op_oef2_tex_clut_ovl_clear(0xFFFF);
    opus_check_forced_draw();
    opus_ffxfocus_free();
    opus_map_rgba_free();
    op_wot_triger(0);
    op_mdc_mem_transfer_cue_free_all();
    opus_clip_on_all_in_battle();
    func_0014D468(7);
    if (D_00703FF0.b22 == 0) {
        op_oef2_sep_free_all(0xFFFF);
    }
    D_00703FF0.bA = 0;
    D_00703FF0.hC = 0;
    D_00703FF0.bE = 0;
    D_00703FF0.b23 = 0;
}

void func_00297EA0(void) {
    opus_end_all_sub(-1);
    op_ovl_effect_free();
}

void op_fp_effect_init(void) {
    func_00120108(D_00574D48);
    op_oef2_tex_clut_ovl_clear(0x40000000);
}

void op_fp_effect_free(void) {
    func_00120108(D_00574D68);
    op_oef2_tex_clut_ovl_clear(0x40000000);
}

void op_event_effect_init(void) {
    func_00120108(D_00574D88);
    D_00703FFB = 1;
}

void op_event_effect_free(void)
{
    func_00120108((char *)D_00574DA8);
    ((int (*)(void))func_00299AD8)(); /* DEBT(CAST): the original call site sees an int-returning declaration */
    D_00703FFB = 0;
}

INCLUDE_ASM("build/ee_asm/game/op/op_2967E8", op_et_eff);

int op_et_eff_off_signal(int id)
{
    int i = opus_get_eff_status_index((Chr *)id, 0, 0); /* DEBT(CAST): the key is an id here (see func_00299360) */

    if (i >= 0) {
        SlotEntry *e = &owu_eff_status[i];

        e->sub->hB0 |= 0x4000;
        func_00120108(D_00574FC0, id);
    }
}

int func_00298230(Chr *key, int b)
{
    u16 bits = b;
    int i = opus_get_eff_status_index(key, 0, 0);

    if (i >= 0) {
        SlotEntry *e = &owu_eff_status[i];

        e->sub->hB0 |= bits;
        func_00120108(D_00574FE0, key, bits);
    }
}

int func_002982B0(Chr *key, int b)
{
    u16 bits = b;
    int i = opus_get_eff_status_index(key, 0, 0);

    if (i >= 0) {
        SlotEntry *e = &owu_eff_status[i];

        e->sub->hB0 &= bits;
        func_00120108(D_00575010, key, bits);
    }
}

int func_00298330(int id, int b)
{
    int i = opus_get_eff_status_index((Chr *)id, 0, 0); /* DEBT(CAST): the key is an id (see func_00299360) */

    if (i >= 0) {
        SlotEntry *e = &owu_eff_status[i];

        e->wC |= b;
        func_00120108(D_00575048, id, b);
    }
}

int func_002983B0(int id, int b)
{
    int i = opus_get_eff_status_index((Chr *)id, 0, 0); /* DEBT(CAST): the key is an id (see func_00299360) */

    if (i >= 0) {
        SlotEntry *e = &owu_eff_status[i];

        e->wC &= b;
        func_00120108(D_00575080, id, b);
    }
}

void func_00298430(void) {
}

int func_00298438(Chr *key, int set) {
    int i = opus_get_chr_status_index(key, 0, 0);
    s8 *p;
    int old;

    if (i < 0) {
        return 0;
    }
    p = owu_chr_drawoff[owu_chr_status[i].hE] != 0 ? (s8 *)&owu_chr_drawoff[owu_chr_status[i].hE] : (s8 *)&owu_chr_drawoff_back[owu_chr_status[i].hE];
    old = ~*p & 1;
    if (set) {
        *(u8 *)p |= 1;
    } else {
        *(u8 *)p &= 0xFE;
    }
    return old;
}

int func_002984D8(Chr *key) {
    return func_00298438(key, 0);
}

int func_002984F8(Chr *key) {
    return func_00298438(key, 1);
}

INCLUDE_ASM("build/ee_asm/game/op/op_2967E8", func_00298518);

int func_002985C0(Chr *key) {
    return func_00298518(key, 0);
}

int func_002985E0(Chr *key) {
    return func_00298518(key, 1);
}

void opus_check_forced_draw(void)
{
    s8 any = 0;
    int i;

    for (i = 0; i < 0xF0; i++) {
        any |= owu_chr_drawoff[i];
    }
    if (any != 0) {
        func_00120108(D_005750C0);
        func_002EA328(1);
    }
}

int func_00298668(int a) {
    return a == D_00703E20.w8 ? 0 : -1;
}

int func_00298680(int a) {
    return a == D_00703E20.cur ? 0 : -1;
}

int func_00298698(int v) {
    int i;

    for (i = 0; i < 8; i++) {
        if (v == D_00703E20.b[i]) {
            return i;
        }
    }
    return -1;
}

int func_002986D0(int v) {
    int i;

    for (i = 0; i < 4; i++) {
        if (v == D_00703E20.a[i]) {
            return i;
        }
    }
    return -1;
}

void func_00298708(void) {
    int i;

    for (i = 0; i < 0xF0; i++) {
        func_00298740(i);
    }
}

INCLUDE_ASM("build/ee_asm/game/op/op_2967E8", func_00298740);

INCLUDE_ASM("build/ee_asm/game/op/op_2967E8", opus_get_chr_status_index);

int func_002989C8(u32 id) {
    ResEntry *e;
    int i;

    if ((id & 0xF0000000) == 0) {
        id &= 0xFF;
        e = owu_chr_status;
        for (i = 0; i < 0xF0; i++, e++) {
            if (e->hE == id) {
                return i;
            }
        }
        e = owu_chr_status;
        for (i = 0; i < 0xF0; i++, e++) {
            if (e->chr != 0) {
                return i;
            }
        }
        return -1;
    }
    return id & 0xFF;
}

int opus_get_chr_status_index_by_chrno(int key) {
    int i;

    for (i = 0; i < 0xD0; i++) {
        if (owu_chr_status[i].key == key) {
            return i;
        }
    }
    return -1;
}

int func_00298A80(Chr *key)
{
    int i = opus_get_chr_status_index(key, 0, 0);
    ResEntry *e;
    int n;
    int j;

    if (i < 0) {
        return 0;
    }
    e = &owu_chr_status[i];
    n = 0;
    for (j = 0; j < 0xF0; j++) {
        if (owu_chr_status[j].key == e->key) {
            n++;
        }
    }
    return n;
}

INCLUDE_ASM("build/ee_asm/game/op/op_2967E8", func_00298AF0);

INCLUDE_ASM("build/ee_asm/game/op/op_2967E8", func_00298BB8);

INCLUDE_ASM("build/ee_asm/game/op/op_2967E8", func_00298CA0);

INCLUDE_ASM("build/ee_asm/game/op/op_2967E8", func_00298D80);

void func_00298E30(void) {
    func_00298CA0();
}

Chr *func_00298E38(int key) {
    int i = opus_get_chr_status_index_by_chrno(key);

    if (i < 0) {
        return 0;
    }
    return owu_chr_status[i].chr;
}

int func_00298E78(Chr **out) {
    int n = 0;
    int i;

    for (i = 0; i < 0xD0; i++) {
        if (owu_chr_status[i].chr != 0) {
            *out++ = owu_chr_status[i].chr;
            n++;
        }
    }
    return n;
}

void func_00298EB0(Chr *key) {
    opus_get_chr_status_index(key, 0, 0);
    op_et_astatus_effect_off(key);
}

void func_00298EE0(Chr *key) {
    SysObj *obj = D_0054D5E0;

    if (obj != 0 && obj->w320 > 0x1AFFFFF) {
        D_0054D5E0 = 0;
    }
    func_00298EB0(key);
    D_0054D5E0 = obj;
}

INCLUDE_ASM("build/ee_asm/game/op/op_2967E8", op_et_bindeff);

void op_et_bindeff_off(Chr *key)
{
    int i = opus_get_chr_status_index(key, 0, 0);
    ResEntry *e;
    int id;

    if (i >= 0) {
        e = &owu_chr_status[i];
        e->flags &= 0xFFFC;
        func_00120108(D_005751B0, e->key, key);
        id = i + 0x40000000;
        func_00297520(id + 0x400);
        func_00297520(id + 0x500);
        func_00297520(id + 0x600);
        func_00297520(id + 0x700);
    }
}

void func_00299218(Chr *chr)
{
    int i = opus_get_chr_status_index(chr, 0, 0);
    int id;

    if (i >= 0) {
        owu_chr_status[i].flags &= 0xFFFC;
        func_00120108(D_005751E0, chr);
        id = i + 0x40000000;
        op_et_eff_off_signal(id + 0x400);
        op_et_eff_off_signal(id + 0x500);
        op_et_eff_off_signal(id + 0x600);
        op_et_eff_off_signal(id + 0x700);
    }
}

void func_002992B8(Chr *key, u16 v)
{
    int i = opus_get_chr_status_index(key, 0, 0);
    int id;

    if (i >= 0) {
        func_00120108(D_00575208, key, v);
        id = i + 0x40000000;
        /* DEBT(TYPE): func_00298230 also takes thread ids, its first parameter is declared Chr * */
        func_00298230((Chr *)(id + 0x400), v);
        func_00298230((Chr *)(id + 0x500), v);
        func_00298230((Chr *)(id + 0x600), v);
        func_00298230((Chr *)(id + 0x700), v);
    }
}

void func_00299360(void *key, int v)
{
    int i = opus_get_chr_status_index(key, 0, 0);
    int id;

    if (i >= 0) {
        func_00120108(D_00575240, key, v);
        id = i + 0x40000000;
        func_00298330(id + 0x400, v);
        func_00298330(id + 0x500, v);
        func_00298330(id + 0x600, v);
        func_00298330(id + 0x700, v);
    }
}

int func_00299408(Chr *key, int set) {
    int i = opus_get_chr_status_index(key, 0, 0);
    ResEntry *e;
    s8 *p;
    int old;

    if (i < 0) {
        return 0;
    }
    e = &owu_chr_status[i];
    if (!(e->flags & 0x1)) {
        return 0;
    }
    p = owu_chr_drawoff[e->hE] != 0 ? (s8 *)&owu_chr_drawoff[e->hE] : (s8 *)&owu_chr_drawoff_back[e->hE];
    old = ~*p & 4;
    if (set) {
        *(u8 *)p |= 4;
    } else {
        *(u8 *)p &= 0xFB;
    }
    return old;
}

int func_002994B8(Chr *key) {
    return func_00299408(key, 0);
}

int func_002994D8(Chr *key) {
    return func_00299408(key, 1);
}

void func_002994F8(void) {
    int i;

    if (D_00703FF0.b[5] != 0) {
        D_00703FF0.b[5] = 0;
        for (i = 0; i < 0xCF; i++) {
            if (owu_chr_status[i].chr != 0) {
                op_et_bindeff(owu_chr_status[i].chr);
            }
        }
    }
}

void func_00299558(void) {
    int i;

    D_00703FF0.b[5] = 1;
    for (i = 0; i < 0xCF; i++) {
        if (owu_chr_status[i].chr != 0) {
            op_et_bindeff_off(owu_chr_status[i].chr);
        }
    }
}

INCLUDE_ASM("build/ee_asm/game/op/op_2967E8", op_et_bindeff2);

void func_002996E0(Chr *key)
{
    int i = opus_get_chr_status_index(key, 0, 0);
    ResEntry *e;

    if (i >= 0) {
        e = &owu_chr_status[i];
        e->flags &= 0xF8CF;
        func_00120108(D_005751B0, e->key, key);
        func_00297520(i + 0x50001800);
    }
}

int func_00299770(Chr *key, int set) {
    int i = opus_get_chr_status_index(key, 0, 0);
    ResEntry *e;
    s8 *p;
    int old;

    if (i < 0) {
        return 0;
    }
    e = &owu_chr_status[i];
    if (!(e->flags & 0x10)) {
        return 0;
    }
    p = owu_chr_drawoff[e->hE] != 0 ? (s8 *)&owu_chr_drawoff[e->hE] : (s8 *)&owu_chr_drawoff_back[e->hE];
    old = ~*p & 8;
    if (set) {
        *(u8 *)p |= 8;
    } else {
        *(u8 *)p &= 0xF7;
    }
    return old;
}

int func_00299820(Chr *key) {
    return func_00299770(key, 0);
}

int func_00299840(Chr *key) {
    return func_00299770(key, 1);
}

T6_Blk *func_002A0820(T6_BlkPool *p, int arg, int w, int key);

void func_00299860(Chr *key, float *src)
{
    int i;
    int e;
    T6_Blk *b;

    if (D_00703FFB != 0) {
        i = opus_get_chr_status_index(key, 0, 0);
        if (i >= 0) {
            e = opus_get_eff_status_index((Chr *)(i + 0x50001800), 0, 0);
            if (e > 0) {
                SlotEntry *se = &owu_eff_status[e];

                b = func_002A0820((T6_BlkPool *)D_0054D5E8[0], (int)se->sub, op_oef2_obj_a_get(D_00703E28, 0, 0x20), 1);
                if (b != 0) {
                    func_002B5978((float *)((u8 *)b + 0x40), src, 16.0f);
                }
            }
        }
    }
}

void func_00299928(Chr *key) {
    int i = opus_get_chr_status_index(key, 0, 0);

    if (i >= 0) {
        owu_chr_status[i].flags |= 0x100;
    }
}

void op_et_bindeff2_walk_on(Chr *key) {
    int i = opus_get_chr_status_index(key, 0, 0);

    if (i >= 0) {
        owu_chr_status[i].flags &= 0xFEFF;
    }
}

void func_002999B8(Chr *key) {
    int i = opus_get_chr_status_index(key, 0, 0);

    if (i >= 0) {
        owu_chr_status[i].flags |= 0x200;
    }
}

void func_00299A00(Chr *key) {
    int i = opus_get_chr_status_index(key, 0, 0);

    if (i >= 0) {
        owu_chr_status[i].flags &= 0xFDFF;
    }
}

void func_00299A48(Chr *key) {
    int i = opus_get_chr_status_index(key, 0, 0);

    if (i >= 0) {
        owu_chr_status[i].flags |= 0x3400;
    }
}

void func_00299A90(Chr *key) {
    int i = opus_get_chr_status_index(key, 0, 0);

    if (i >= 0) {
        owu_chr_status[i].flags &= 0xCBFF;
    }
}

void func_00299AD8(void) {
    D_00703FF0.h20 = (D_00703FF0.h20 & 0xC3FF) | 0x800;
}

void func_00299AF8(void) {
    D_00703FF0.h20 = (D_00703FF0.h20 & 0xC3FF) | 0x800;
}

void func_00299B18(void) {
    D_00703FF0.h20 |= 0x3C00;
}

void func_00299B30(void) {
    D_00703FF0.h20 &= 0xF7FF;
    func_00299CE8();
}

void func_00299B48(void) {
    D_00703FF0.h20 |= 0x800;
}

void func_00299B60(void) {
    D_00703FF0.h20 &= 0xEFFF;
}

void func_00299B78(void) {
    D_00703FF0.h20 |= 0x1000;
}

void func_00299B90(void) {
    D_00703FF0.h20 &= 0xDFFF;
}

void func_00299BA8(void) {
    D_00703FF0.h20 |= 0x2000;
}

int func_00299BC0(Chr *key)
{
    int v = func_001730F0(key);
    int i;
    ResEntry *e;

    i = 0;
    do {
        if (D_00373568[i] == v) {
            break;
        }
        i++;
    } while (i < 0x12);
    i = opus_get_chr_status_index(key, 0, 0);
    if (i < 0) {
        return 0;
    }
    e = &owu_chr_status[i];
    if (e->flags & 0x10) {
        e->flags |= 0x400;
    }
    return 0;
}

void func_00299C58(void)
{
    int found = 0;
    int i;

    for (i = 0; i < 0xD0; i++) {
        if (owu_chr_status[i].chr != 0) {
            found |= func_00299BC0(owu_chr_status[i].chr);
        }
    }
    if (found) {
        func_00120108(D_005752B0);
    } else {
        func_00120108(D_005752C8);
    }
}

void func_00299CE8(void) {
    int i;

    for (i = 0; i < 0xD0; i++) {
        Chr *chr = owu_chr_status[i].chr;

        if (chr != 0) {
            owu_chr_status[i].b16 = func_00110560(chr);
        }
    }
}

INCLUDE_ASM("build/ee_asm/game/op/op_2967E8", func_00299D40);

void func_00299E60(void) {
}

u8 func_00299E68(V6Keys *o, int key, int add)
{
    int i;

    if (key == 0) {
        return 0xFF;
    }
    for (i = 0; i < 16; i++) {
        if (o->key[i] == key) {
            return i;
        }
    }
    if (!add) {
        return 0xFF;
    }
    for (i = 0; i < 16; i++) {
        if (o->key[i] == 0) {
            o->key[i] = key;
            return i;
        }
    }
    return 0xFF;
}

void func_00299EE0(char *base, int key) {
    int *p = (int *)(base + 0x60);
    int i;

    for (i = 15; i >= 0; i--) {
        if (*p == key) {
            *p = 0;
        }
        p++;
    }
}

INCLUDE_ASM("build/ee_asm/game/op/op_2967E8", opus_get_eff_status_index);

int func_0029A110(int key) {
    int i;

    for (i = 0; i < 0x200; i++) {
        if (owu_eff_status[i].key == key) {
            return i;
        }
    }
    return -1;
}

void opus_free_eff_status(int key) {
    int i;

    if (key == -1) {
        return;
    }
    for (i = 0; i < 0x200; i++) {
        if (owu_eff_status[i].key == key) {
            owu_eff_status[i].key = -1;
            owu_eff_status[i].sub = 0;
            owu_eff_status[i].b8 = 1;
            owu_eff_status[i].b9 = 1;
            owu_eff_status[i].wC = 0;
            owu_eff_status[i].list[0] = 0;
            owu_eff_status[i].b18 = 0;
            owu_eff_status[i].b1C = 0xFF;
            owu_eff_status[i].b1D = 0;
        }
    }
}

void func_0029A1A8(void) {
    int i;

    for (i = 0; i < 0x200; i++) {
        owu_eff_status[i].key = -1;
        owu_eff_status[i].b8 = 1;
        owu_eff_status[i].wC = 0;
        owu_eff_status[i].list[0] = 0;
        owu_eff_status[i].b9 = 1;
        owu_eff_status[i].b18 = 0;
        owu_eff_status[i].b1C = 0xFF;
        owu_eff_status[i].b1D = 0;
    }
}

INCLUDE_ASM("build/ee_asm/game/op/op_2967E8", func_0029A1F8);

INCLUDE_ASM("build/ee_asm/game/op/op_2967E8", func_0029A2E8);

void func_0029A3A0(void) {
    int i;

    for (i = 0xEF; i >= 0; i--) {
        owu_chr_hd[i] = 0;
    }
}

/* DEBT(NAME): event host record; ffx-rust opu_end_all */
typedef struct OpuEndUnit {
    u8 pad0[0x14];
    u16 h14;
} OpuEndUnit;
typedef struct OpuEndHost {
    u8 pad0[0x210];
    u8 b210;
    u8 pad211[3];
    u16 h214;
    u16 pad216;
    u16 h218;
    u8 pad21A[6];
    OpuEndUnit *unit;
} OpuEndHost;

int func_0029A3D8(OpuEndHost *h)
{
    OpuEndUnit *u;
    u_long128 z = 0;

    h->h218 = 0;
    u = h->unit;
    h->h214 = 0;
    *(u_long128 *)u = z;
    h->b210 = 1;
    opus_end_all_sub(u->h14);
    return 0;
}

INCLUDE_ASM("build/ee_asm/game/op/op_2967E8", opus_end_all_sub);

INCLUDE_ASM("build/ee_asm/game/op/op_2967E8", op_et_astatus_effect_change);

void op_et_astatus_effect_off(Chr *key)
{
    ResEntry *temp_17;
    s32 temp_16;
    s32 temp_2;
    u8 temp_3;

    temp_2 = opus_get_chr_status_index(key, 0, 0);
    if (temp_2 >= 0)
    {
        temp_17 = &owu_chr_status[temp_2];
        func_00120108(&D_00575378, temp_17->key, key);
        func_00297520(temp_2 + 0x60004000);
        temp_16 = MsBattleChrStart() != 0;
        /* DEBT(ORDER): independent packed color writes retain original scheduling. */
        temp_17->color10 = 0x80808080;
        temp_17->color18 = 0x80808080;
        func_002A2558(key, 0x80808080, temp_16);
        opus_chara_status_rgb_set(key, temp_16);
        temp_3 = temp_17->b17;
        if (temp_3 & 1)
        {
            temp_17->b17 = temp_3 & 0xFE;
            Ch_ClutDispose(temp_17->chr);
        }
        temp_17->b17 = 0;
    }
}

void func_0029A7B8(void) {
    int i;

    for (i = 0; i < 0xF0; i++) {
        if (owu_chr_status[i].chr != 0) {
            op_et_astatus_effect_off(owu_chr_status[i].chr);
        }
    }
}

int op_get_chr_status_stone(Chr *key) {
    int i = opus_get_chr_status_index(key, 0, 0);

    return owu_chr_status[i].b17 & 1;
}

void func_0029A848(void) {
    D_00703FF0.bE |= 1;
}

void func_0029A860(void) {
    D_00703FF0.bE &= 0xFE;
}

void func_0029A878(void) {
    D_00703FF0.bE |= 2;
}

void func_0029A890(void) {
    D_00703FF0.bE &= 0xFD;
}
