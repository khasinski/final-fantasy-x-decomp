/* tu_315 0x294cd8-0x2967e8: medium; ~opus (config/tu_map.tsv) */
/* Module guess: event-script VM / field-event runtime (no __FILE__ string found for this range). */
#include "common.h"
#include "ffx/r6.h"
#include "ffx/w9.h"
#include "ffx/q6.h"
#define func_00295EB8 _proto_func_00295EB8
#define opus_no_get _proto_opus_no_get
#include "ffx/t6.h"
#undef func_00295EB8
#undef opus_no_get
#include "ffx/u4.h"
#include "ffx/v6.h"
#include "ffx/g4.h"

void func_00295EB8(void *obj300, s16 id, ScriptSub *sub, u16 *pc);
ScriptSub *opus_no_get(void *obj300, ScriptSub *sub, s16 id);
void op_free(void *heap, void *p);

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

extern void (*_opu_jtbl_00373518[])(ScriptThread *, u16 *) __asm__("jtbl_00373518");

u16 *func_00295560(ScriptThread *th, u16 *pc)
{
    ScriptSub *sub = th->sub;
    register ScriptSub *tgt __asm__("$5");
    u16 flags = th->flags;
    register u32 raw __asm__("$6");
    register s32 op1 __asm__("$3");
    s16 op2;

    if (flags & 0x400) {
        tgt = opus_no_get(th->obj300, sub, (s16)pc[1]);
        pc += 1;
        flags = th->flags;
    } else {
        tgt = sub;
    }
    op1 = pc[1];
    raw = (u32)op1 << 16;
    op1 = (s32)raw >> 16;
    op2 = pc[2];
    switch (flags & 0xF000) {
    case 0x0000: {
        register float val __asm__("$f1") = (float)op2;
        register float *dst __asm__("$2") = (float *)((u8 *)tgt + op1);
        __asm__("" : "+r"(dst) : "f"(val));
        pc += 3;
        *dst = val;
        break;
    }
    case 0x1000: {
        register u32 hi __asm__("$4") = raw >> 24;
        register float *src __asm__("$2") = (float *)((u8 *)tgt + hi);
        register float *dst __asm__("$3") = (float *)((u8 *)tgt + (op1 & 0xFF));
        register float v __asm__("$f0");
        __asm__("" : "+r"(src), "+r"(dst));
        v = *src;
        __asm__("" : "+r"(pc) : "f"(v));
        pc += 2;
        goto store_f0;
    }
    case 0x2000: {
        register u32 hi __asm__("$4") = raw >> 24;
        register float *p0 __asm__("$2") = (float *)((u8 *)tgt + hi);
        register float *p1 __asm__("$3") = (float *)((u8 *)tgt + (op1 & 0xFF));
        register float tmp0 __asm__("$f0");
        register float tmp1 __asm__("$f1");
        __asm__("" : "+r"(p0), "+r"(p1));
        tmp0 = *p0;
        __asm__("" : "+r"(pc) : "f"(tmp0));
        pc += 2;
        __asm__("" : "+r"(p1) : "r"(pc));
        tmp1 = *p1;
        *p1 = tmp0;
        *p0 = tmp1;
        break;
    }
    case 0x3000: {
        register u32 hi __asm__("$4") = raw >> 24;
        register float *src __asm__("$2") = (float *)((u8 *)tgt + hi);
        register float *dst __asm__("$3");
        register float v __asm__("$f0");
        op1 &= 0xFF;
        __asm__("" : "+r"(src));
        __asm__("" : "+r"(op1) : "r"(src));
        dst = (float *)((u8 *)sub + op1);
        __asm__("" : "+r"(src) : "r"(dst));
        v = *src;
        __asm__("" : "+r"(pc) : "f"(v));
        pc += 2;
        goto store_f0;
    }
    case 0x4000: {
        register u32 hi __asm__("$4");
        register float *src __asm__("$2");
        register float *dst __asm__("$3");
        register float v __asm__("$f0");
        op1 &= 0xFF;
        __asm__("" : "+r"(op1));
        hi = raw >> 24;
        __asm__("" : "+r"(hi) : "r"(op1));
        src = (float *)((u8 *)sub + op1);
        __asm__("" : "+r"(pc) : "r"(src));
        pc += 2;
        __asm__("" : "+r"(src) : "r"(pc));
        v = *src;
        __asm__("" : "+r"(hi) : "f"(v));
        dst = (float *)((u8 *)tgt + hi);
        goto store_f0;
    }
    case 0x5000: {
        register float *src __asm__("$2");
        register float *dst __asm__("$3");
        register float v __asm__("$f0");
        op1 &= 0xFF;
        pc += 2;
        src = (float *)((u8 *)sub + op1);
        __asm__("" : "+r"(src));
        v = *src;
        __asm__("" : "+r"(op1) : "f"(v));
        dst = (float *)((u8 *)tgt + op1);
        __asm__("" : "+f"(v) : "r"(dst));
        v = -v;
    store_f0:
        *dst = v;
        break;
    }
    }
    if (flags & 0x200) {
        _opu_jtbl_00373518[tgt->bBA](th, pc);
    }
    return pc;
}

u16 *opu_gw(ScriptThread *th, u16 *pc)
{
    u16 flags = th->flags;
    int dst_off;
    register ScriptSub *src __asm__("$5");
    ScriptSub *dst;
    float a;
    float b;
    float *dp;

    if (flags & 0x400) {
        src = opus_no_get(th->obj300, th->sub, (s16)pc[1]);
        flags = th->flags;
        if ((flags & 0xFF) == 0xA9) {
            dst = src;
        } else {
            dst = th->sub;
        }
        pc += 1;
    } else {
        dst = th->sub;
        src = dst;
    }
    if (flags & 0x800) {
        u8 *bp = (u8 *)pc;
        register u8 o1 __asm__("$3") = bp[3];
        register u8 o2 __asm__("$2") = bp[4];
        register float *p0 __asm__("$3");
        register float *p1 __asm__("$2");
        dst_off = bp[2];
        __asm__("" : : "r"(dst_off));
        p0 = (float *)((u8 *)dst + o1);
        __asm__("" : "+r"(p0) : "r"(dst_off));
        p1 = (float *)((u8 *)src + o2);
        __asm__("" : "+r"(p1) : "r"(p0));
        a = *p0;
        b = *p1;
    } else {
        u8 *bp = (u8 *)pc;
        register int imm __asm__("$2") = (s16)pc[1];
        register int o5 __asm__("$3") = bp[5];
        register float *p0 __asm__("$2");
        b = (float)imm;
        dst_off = bp[4];
        p0 = (float *)((u8 *)src + o5);
        __asm__("" : "+r"(p0));
        a = *p0;
    }
    dp = (float *)((u8 *)dst + dst_off);
    switch (flags & 0xF000) {
    case 0x0000:
        *dp = a + b;
        break;
    case 0x1000:
        *dp = a - b;
        break;
    case 0x2000:
        *dp = a * b;
        break;
    case 0x3000:
        if (b == 0.0f) {
            *dp = 0.0f;
        } else {
            *dp = a / b;
        }
        break;
    }
    pc += 3;
    if (flags & 0x200) {
        _opu_jtbl_00373518[dst->bBA](th, pc);
    }
    return pc;
}

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

#ifndef MMI_SQ_ZERO
#define MMI_SQ_ZERO(off, p) __asm__ volatile("sq $0, " #off "(%0)" : : "r"(p) : "memory")
#endif
/* DEBT(CAST) */
void func_00295C50(T6_Blk *b) {
    MMI_SQ_ZERO(0, b);
    MMI_SQ_ZERO(0x10, b);
    MMI_SQ_ZERO(0x20, b);
    MMI_SQ_ZERO(0x30, b);
    MMI_SQ_ZERO(0x40, b);
    MMI_SQ_ZERO(0x50, b);
    MMI_SQ_ZERO(0x60, b);
    MMI_SQ_ZERO(0x70, b);
    MMI_SQ_ZERO(0x80, b);
    MMI_SQ_ZERO(0x90, b);
    MMI_SQ_ZERO(0xA0, b);
    MMI_SQ_ZERO(0xB0, b);
    MMI_SQ_ZERO(0xC0, b);
    MMI_SQ_ZERO(0xD0, b);
    MMI_SQ_ZERO(0xE0, b);
    MMI_SQ_ZERO(0xF0, b);
    (*(s32 *)((u8 *)(b) + (0xC8))) = 0x80808080;
}

/* DEBT(CAST): 0x100-byte script block copied field by field, raw byte offsets */
void func_00295CA0(T6_BlkPool *p, T6_Blk *b, int arg)
{
    u8 *d = (u8 *)b;
    u8 *s = (u8 *)arg;

    *(u_long128 *)(d + 0x30) = *(u_long128 *)(s + 0x30);
    *(u16 *)(d + 0x1C) = (u32)(s - p->blocks) >> 8;
    *(u_long128 *)(d + 0x40) = *(u_long128 *)(s + 0x40);
    *(u_long128 *)(d + 0x90) = *(u_long128 *)(s + 0x90);
    d[0x1E] = s[0x1E];
    *(u16 *)(d + 0x14) = *(u16 *)(s + 0x14);
    d[0x18] = s[0x18];
    d[0xBA] = s[0xBA];
    d[0xB3] = s[0xB3];
}

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

typedef struct OpusVt54 {
    u8 pad00[0x54];
    void (*f54)(ScriptSub *);
} OpusVt54;

typedef struct OpusPool {
    u8 pad00[0x10];
    s16 *lists[3];
    s16 *draw_list;
    u8 *subs;
    u8 pad24[0x10];
    u16 count;
    u16 max_used;
    u16 cur_used;
    u8 pad3A[0x16];
    OpusVt54 *vt50;
    u8 pad54[0x54];
    void *pA8;
} OpusPool;

int func_00295D58(T6_BlkPool *pool, int key)
{
    OpusPool *o = (OpusPool *)pool;
    u16 max = o->count - 1;
    s16 *list = o->lists[key];
    s16 i;
    s16 j;

    for (i = 0; i < max; i++) {
        if (list[i] < 0) {
            goto found_slot;
        }
    }
    return -1;
found_slot:
    for (j = 0; j < max; j++) {
        if (*(int *)(o->subs + (j << 8)) == 0) {
            goto found_blk;
        }
    }
    return -1;
found_blk:
    list[i] = j;
    o->cur_used++;
    if (o->max_used < o->cur_used) {
        o->max_used = o->cur_used;
    }
    return j;
}

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

void opus_draw_off(IdList *o, s16 id) {
    s16 *p = o->list;
    int value;
    while ((value = *p) >= 0) {
        if (value == id) {
            /* DEBT(GOTO): preserve the original search/removal block layout. */
            goto found;
        }
        p++;
    }
    return;
found:
    while ((value = p[1]) >= 0) {
        *p = value;
        p++;
    }
    *p = -1;
}

typedef struct {
    u8 pad0[0x10];
    s16 *list10;
    s16 *list14;
    s16 *list18;
    u8 pad1C[4];
    u8 *subs;
} OpusPoolView; /* DEBT(TYPE): list pointers inside OpusPool */

ScriptSub *opus_no_get(void *obj300, ScriptSub *sub, s16 id)
{
    OpusPoolView *o = (OpusPoolView *)obj300;
    ScriptSub *cur;
    s16 *p;
    register int idx __asm__("$2"); /* DEBT(REG): matches $v0 for list index */

    if (id >= 0) {
    search:
        p = o->list14;
        while ((idx = *p) >= 0) {
            register int h1a __asm__("$3"); /* DEBT(REG): matches $v1 for cur->h1A compare */
            cur = (ScriptSub *)(o->subs + (idx << 8));
            p++;
            h1a = cur->h1A;
            if (h1a == id && cur->b1E == sub->b1E) {
                return cur;
            }
        }
        p = o->list10;
        while ((idx = *p) >= 0) {
            register int h1a __asm__("$3"); /* DEBT(REG): matches $v1 for cur->h1A compare */
            cur = (ScriptSub *)(o->subs + (idx << 8));
            p++;
            h1a = cur->h1A;
            if (h1a == id && cur->b1E == sub->b1E) {
                return cur;
            }
        }
        p = o->list18;
        while ((idx = *p) >= 0) {
            register int h1a __asm__("$3"); /* DEBT(REG): matches $v1 for cur->h1A compare */
            cur = (ScriptSub *)(o->subs + (idx << 8));
            p++;
            h1a = cur->h1A;
            if (h1a == id && cur->b1E == sub->b1E) {
                return cur;
            }
        }
        return (ScriptSub *)o->subs;
    }
    if (id == -0x100) {
        return sub;
    }
    if (id == -1) {
        cur = (ScriptSub *)(o->subs + (*(u16 *)((u8 *)sub + 0x1C) << 8));
        goto check_live; /* DEBT(GOTO): shares live-check tail with parent-walk loop */
    }
    if (id < -0x3000) {
        if (id >= -0x4FFF) {
            id += (s16)(sub->h1A + 0x4000);
            goto search; /* DEBT(GOTO): jumps back to positive-id search */
        }
    }
    if ((id & 0xFF00) == 0xFE00) {
        register SlotEntry *tbl __asm__("$2") = owu_eff_status; /* DEBT(REG): matches $v0 for owu_eff_status base */
        cur = tbl[sub->h14].sub;
        id = (cur->h1A & 0x7FF0) | (id & 0xF);
        goto search; /* DEBT(GOTO): jumps back to positive-id search */
    }
    cur = sub;
    while (id < 0) {
        cur = (ScriptSub *)(o->subs + (*(u16 *)((u8 *)cur + 0x1C) << 8));
        id++;
    }
check_live:
    if (*(s32 *)cur != 0) {
        return cur;
    }
    return (ScriptSub *)o->subs;
}

ScriptSub *opus_get_osu_by_draw(OpusPool *o, ScriptSub *sub, u8 type, int any)
{
    s16 *p;
    ScriptSub *cur;
    s16 idx;
    u8 id;

    if (o == 0) {
        o = (OpusPool *)D_0054D5E8[0];
        any = 1;
        sub = (ScriptSub *)o->subs;
        goto start; /* DEBT(GOTO): return block sits between the default-arg block and the loop */
    } else {
        goto start;
    }
found:
    return cur;
start:
    p = o->draw_list;
    id = sub->b1E;
    for (; (idx = *p) >= 0; p++) {
        cur = (ScriptSub *)(o->subs + (idx << 8));
        if (cur->bBB == type) {
            if (any != 0 || cur->b1E == id) {
                goto found;
            }
        }
    }
    return 0;
}

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

/* DEBT(TYPE): func_00110910 returns float, but this TU compiled without its prototype (implicit int return converted to float) */
extern int _func_00110910(Chr *) __asm__("func_00110910");

float opus_cscale_get(int id, int live)
{
    Chr *chr = owu_chr_hd[id];
    float a;
    float b;
    float m;
    u8 unused[0x10];

    if (live) {
        a = MsGetChrHeight(id);
        b = MsGetChrWidth(id);
    } else {
        a = T6_INTCALL(Ch_GetFixHeight, chr);
        b = _func_00110910(chr);
    }
    __asm__(".set mips3");
    m = a < b ? b : a;
    __asm__(".set mips4");
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

float func_00296640(int id, int in_battle)
{
    if (in_battle) {
        return MsGetChrWidth(id);
    } else {
        return _func_00110910(owu_chr_hd[id]);
    }
}

float opus_cwidth_scale_get(int id, int in_battle)
{
    float w;

    if (in_battle) {
        w = MsGetChrWidth(id);
    } else {
        w = _func_00110910(owu_chr_hd[id]);
    }
    return w / 6.0f;
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
