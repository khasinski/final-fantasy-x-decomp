/* tu_315 0x294cd8-0x2967e8: medium; ~opus (config/tu_map.tsv) */
/* Module guess: event-script VM / field-event runtime (no __FILE__ string found for this range). */
#include "common.h"
#include "ffx/r6.h"
#include "ffx/w9.h"
#include "ffx/q6.h"
#include "ffx/t6.h"
#include "ffx/u4.h"
#include "ffx/v6.h"
#include "ffx/g4.h"

INCLUDE_ASM("build/ee_asm/game/op/opus_294CD8", func_00294CD8);

u16 *opu_end(ScriptThread *th, u16 *pc)
{
    ScriptSub *sub = th->sub;
    SlotEntry *e;

    if (th->sp == 0) {
        *(u_long128 *)sub->reg = 0; /* DEBT(CAST): the four registers are cleared with one quadword store */
        e = &owu_eff_status[sub->h14];
        if (e->sub == sub && (e->key & 0xF0000000) == 0x40000000) {
            th->f210 = 0x78;
            return pc;
        }
        func_00295EB8(th->obj300, th->h214, sub, pc);
        opus_draw_off((IdList *)th->obj300, th->h214); /* DEBT(CAST): obj300 is an IdList */
        if (D_007649A0) {
            func_2069EB8(th->h214);
        }
        th->h218--;
    }
    th->f210 = 1;
    return 0;
}

u16 *opu_et_end(ScriptThread *th, u16 *pc)
{
    SlotEntry *e = &owu_eff_status[th->sub->h14];
    int key = e->key;
    int type;

    if (key >= 0 && e->b1D == 0) {
        type = key & 0xF0000000;
        if (type == 0) {
            e->b1D = 1;
            func_00120108(D_00574610, key);
            MsEffectTerminate(key);
        } else {
            if (type == 0x40000000) {
                func_00120108(D_00574638, key);
            }
            if (type == 0x50000000) {
                func_00120108(D_00574660, key);
            }
            if (type == 0x30000000) {
                func_00120108(D_00574688, key);
            }
        }
    }
    if (((s16)th->flags & 0xF000) != 0) {
        return pc + 2;
    }
    opus_free_eff_status(key);
    return opu_end(th, pc);
}

u16 *func_00295390(ScriptThread *th, u16 *pc)
{
    V6Obj300 *o = (V6Obj300 *)th->obj300; /* DEBT(CAST): obj300 is described as bytes */

    if (opus_no_get(o, th->sub, (s16)pc[1]) == o->cur) {
        return opu_end(th, pc);
    }
    th->f210 = 1;
    return pc;
}

u16 *func_00295400(ScriptThread *th, u16 *pc) {
    th->f210 = th->flags >> 9;
    return pc + 1;
}

u16 *func_00295418(ScriptThread *th, u16 *pc)
{
    ScriptSub *sub = th->sub;

    switch ((s16)th->flags & 0xF000) {
    case 0:
        th->f210 = func_002B3D68((s16)pc[1]);
        pc += 2;
        break;
    case 0x1000:
        th->f210 = (s16)pc[1] * opus_en_index(sub);
        pc += 2;
        break;
    case 0x2000:
        th->f210 = *(float *)((char *)sub + (s16)pc[1]); /* DEBT(CAST): operand is a byte offset into the sub */
        pc += 2;
        break;
    case 0x3000:
        if (opus_get_chr_status_index_by_chrno((s16)pc[1]) < 0) {
            th->f210 = 1;
        } else {
            pc += 2;
        }
        break;
    case 0x8000:
        if (opus_no_get(th->obj300, sub, (s16)pc[1]) == ((T6_Th300c *)th->obj300)->cur) { /* DEBT(CAST): see T6_Th300c */
            pc += 2;
        } else {
            th->f210 = 1;
        }
        break;
    case 0x9000:
        if (D_00703FFB) {
            pc += 1;
        } else {
            th->f210 = 1;
        }
        break;
    }
    return pc;
}

INCLUDE_ASM("build/ee_asm/game/op/opus_294CD8", func_00295560);

INCLUDE_ASM("build/ee_asm/game/op/opus_294CD8", opu_gw);

INCLUDE_ASM("build/ee_asm/game/op/opus_294CD8", func_00295890);

INCLUDE_ASM("build/ee_asm/game/op/opus_294CD8", opu_gw_etc);

void func_00295C00(u16 i, u16 n) {
    u_long128 *p = D_0054D5E8[i]->p20;
    int cnt = n;

    for (; cnt != 0; cnt--) {
        *p = 0;
        p += 16;
    }
}

INCLUDE_ASM("build/ee_asm/game/op/opus_294CD8", func_00295C50);

INCLUDE_ASM("build/ee_asm/game/op/opus_294CD8", func_00295CA0);

void func_00295CF8(u_long128 *a, u_long128 *b)
{
    int n = 63;

    do {
        *b++ = *a++;
    } while (--n >= 0);
}

void func_00295D28(u_long128 *a, u_long128 *b)
{
    int n = 63;

    do {
        *a++ = *b++;
    } while (--n >= 0);
}

INCLUDE_ASM("build/ee_asm/game/op/opus_294CD8", func_00295D58);

INCLUDE_ASM("build/ee_asm/game/op/opus_294CD8", func_00295E28);

INCLUDE_ASM("build/ee_asm/game/op/opus_294CD8", func_00295EB8);

void opus_draw_on(IdList *o, s16 id)
{
    u16 n = o->count - 1;
    s16 *list = o->list;
    int i;

    for (i = 0; i < n; i++) {
        if (list[i] < 0) {
            goto done; /* DEBT(GOTO): break gives a different loop layout */
        }
        if (list[i] == id) {
            return;
        }
    }
done:
    list[i] = id;
}

INCLUDE_ASM("build/ee_asm/game/op/opus_294CD8", opus_draw_off);

INCLUDE_ASM("build/ee_asm/game/op/opus_294CD8", opus_no_get);

INCLUDE_ASM("build/ee_asm/game/op/opus_294CD8", opus_get_osu_by_draw);

/* NAME guess: find slot index of thread's id in its list */
int opus_en_index(ScriptSub *sub) {
    SlotEntry *e = &owu_eff_status[sub->h14];
    int n = sub->h1A & 7;
    int i;

    if (n < e->b8) {
        return n;
    }
    for (i = 0; i < e->b8; i++) {
        if (e->list[i] == sub->b18) {
            return (u8)i;
        }
    }
    return 0;
}

int func_00296390(int v) {
    int i;

    if (v == 0) {
        return -1;
    }
    for (i = 0; i < 8; i++) {
        if (D_00703E20.b[i] == v) {
            return i;
        }
    }
    return -1;
}

int func_002963E0(int k) {
    int b = D_00703E20.b60[k];
    int flag;
    int i;

    if (b == 0) {
        return 0;
    }
    flag = b & 1;
    for (i = 0; ; ) {
        if (flag) {
            break;
        }
        i++;
        if (i >= 2) {
            break;
        }
    }
    return ((i << 6) + 0x3F40) & 0xFFC0;
}

int func_00296430(int k) {
    int b = D_00703E20.b60[k];
    int flag;
    int i;

    if (b == 0) {
        return 0;
    }
    flag = b & 1;
    for (i = 0; ; ) {
        if (flag) {
            break;
        }
        i++;
        if (i >= 2) {
            break;
        }
    }
    return ((i << 3) + 0x3FC0) & 0xFFF8;
}

int opus_get_weapon_index(int v) {
    int i;

    for (i = 0; i < 4; i++) {
        if (D_00703E20.a[i] == v) {
            return i;
        }
    }
    return -1;
}

int opus_get_weapon_index_by_chrid(int v) {
    int i;

    for (i = 0; i < 4; i++) {
        if (D_00703E20.flags[i] == v) {
            return i;
        }
    }
    return -1;
}

int func_002964F0(int flag) {
    int i;

    for (i = 0; i < 4; i++) {
        if (D_00703E20.flags[i] == flag) {
            return D_00703E20.a[i];
        }
    }
    return 0;
}

int func_00296538(Counter16 *c) {
    int n = c->n;

    c->n = n + 1;
    return n;
}

float opus_cscale_get(int id, int live)
{
    Chr *chr = owu_chr_hd[id];
    float a;
    float b;
    float m;
    u8 unused[0x10]; /* DEBT(PADDING): the original frame has an unused 16-byte local */

    if (live) {
        a = MsGetChrHeight(id);
        b = MsGetChrWidth(id);
    } else {
        a = T6_INTCALL(Ch_GetFixHeight, chr);
        b = T6_INTCALL(func_00110910, chr);
    }
    m = a < b ? b : a;
    return m / 18.0f;
}

float func_002965F8(int id, int live)
{
    u8 unused[0x10]; /* DEBT(PADDING): the original frame has an unused 16-byte local */

    if (live) {
        return MsGetChrHeight(id);
    }
    return T6_INTCALL(Ch_GetFixHeight, owu_chr_hd[id]);
}

float func_00296640(int id, int live)
{
    if (live) {
        return MsGetChrWidth(id);
    }
    return T6_INTCALL(func_00110910, owu_chr_hd[id]);
}

float opus_cwidth_scale_get(int id, int live)
{
    float r;

    if (live) {
        r = MsGetChrWidth(id);
    } else {
        r = T6_INTCALL(func_00110910, owu_chr_hd[id]);
    }
    return r / 6.0f;
}

int func_002966E8(int a, int b) {
    if (b != 0 && (MsGetChrFly(a) || func_001ADA00())) {
        return 1;
    }
    return 0;
}

void opus_clip_off_all_in_battle(void) {
    int i;

    if (MsBattleChrStart()) {
        for (i = 0; i < 0x20; i++) {
            if (owu_chr_hd[i] != 0) {
                Ch_EnClip(owu_chr_hd[i], 0);
            }
        }
    }
}

void opus_clip_on_all_in_battle(void) {
    int i;

    if (MsBattleChrStart()) {
        for (i = 0; i < 0x20; i++) {
            if (owu_chr_hd[i] != 0) {
                Ch_EnClip(owu_chr_hd[i], 1);
            }
        }
    }
}
