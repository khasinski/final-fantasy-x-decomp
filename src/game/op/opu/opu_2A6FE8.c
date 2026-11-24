/* tu_322 0x2a6fe8-0x2ac750: low; ~op_mdc_size_get_main (config/tu_map.tsv) */
/* DEBT(NAME): module and names guessed: script call wrappers (see w10.h). */
#define func_002A74A8 _hdr_func_002A74A8
#include "common.h"
#include "vu0.h"
#include "ffx/q7.h"
#include "ffx/w10.h"
#include "ffx/t6.h"
#include "ffx/v6.h"
#include "ffx/r6.h"
#include "ffx/s6.h"
#include "ffx/r7.h"
#undef func_002A74A8

int Ch_ModelGetHide(Chr *chr, int i);
int Ch_ModelCalcSizeEffectPacket(Chr *chr, int i);
ResEntry *opus_mimic_check(Chr *key);
int opus_mdc_size_get_mimic(int mode, int flag);

int op_mdc_size_get_main(int a, int mode, int flag, int check_mimic)
{
    Chr *chr = (Chr *)a;
    int total;
    int nb;
    int i;
    int ret;

    if (check_mimic == 0 || opus_mimic_check(chr) == 0) {
        total = 0;
        nb = Ch_GetNbModel(chr);
        if (nb == 0) {
            return 0;
        }
        for (i = 0; i < nb; i++) {
            u32 sz;
            u32 extra;

            if (Ch_ModelGetHide(chr, i) == 0 || flag == 0) {
                sz = (Ch_ModelCalcSizeEffectPacket(chr, i) + 0xF) & 0xFFFFFF0;
                extra = 0;
                if (mode == 2) {
                    extra = (sz / 0x1C * 3) << 2;
                    extra = (extra + 0xF) & 0xFFFFFF0;
                }
                total = total + sz + extra;
            }
        }
        ret = total + 0x10;
        return ret + nb * 16;
    } else {
        return opus_mdc_size_get_mimic(mode, flag);
    }
}

int func_002A7120(int a, int b, int c)
{
    return op_mdc_size_get_main(a, b, c, 1);
}

typedef struct MdcModelEntry {
    u8 *pkt;
    void *mat;
    u16 flags;
    u16 model_idx;
    u32 padC;
} MdcModelEntry;

typedef struct MdcHdr {
    Chr *chr;
    u16 count;
    u8 mode;
    u8 pad7[9];
    MdcModelEntry entries[1];
} MdcHdr;

void *Ch_ModelGetBaseMatrix(Chr *chr, int i, int j);
void func_002A7420(int id, int val);
void opus_mdc_make_mimic(MdcHdr *hdr, int mode, int work);
u8 *op_md_vn_index(u8 *pkt, u8 *end, int work);

void func_002A7140(s32 a, s32 b, s32 mode, s32 flag, s32 check_mimic, s32 work)
{
    MdcHdr *hdr = (MdcHdr *)a; /* DEBT(CAST): s32 ptr arg */
    Chr *chr = (Chr *)b; /* DEBT(CAST): s32 ptr arg */
    MdcModelEntry *e;
    u8 *dst;
    int nb;
    int count;
    int i;

    if (check_mimic == 0 || opus_mimic_check(chr) == 0) {
        e = &hdr->entries[0];
        nb = Ch_GetNbModel(chr);
        i = 0;
        hdr->chr = chr;
        count = 0;
        dst = (u8 *)hdr + (nb * 16 + 0x10);
        hdr->mode = mode;
        for (; i < nb; i++) {
            u32 sz;
            u8 *next;

            if (Ch_ModelGetHide(chr, i) != 0) {
                if (flag != 0) {
                    continue;
                }
            } else {
                e->flags |= 1;
            }
            e->pkt = dst;
            e->mat = Ch_ModelGetBaseMatrix(chr, i, 0);
            e->model_idx = i;
            sz = Ch_ModelCalcSizeEffectPacket(chr, i);
            Ch_ModelCreateEffectPacket(chr, i, dst);
            next = dst + ((sz + 0xF) & 0xFFFFFF0);
            if (mode == 2) {
                next = op_md_vn_index(dst, next, work);
            }
            dst = next;
            e++;
            count++;
        }
        hdr->count = count;
        func_002A7420((int)chr, (int)hdr);
    } else {
        opus_mdc_make_mimic(hdr, mode, work);
    }
}

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

void op_free(int addr, void *p);
void op_oef2_a_set(int res, int type, int idx, int val);

void opus_mdc_free(int res, Chr *chr, int addr)
{
    int idx;
    ResEntry *e;
    u8 slot;

    if (chr == 0) {
        return;
    }
    idx = opus_get_chr_status_index(chr, 0, 0);
    if (idx < 0) {
        return;
    }
    e = &owu_chr_status[idx];
    if (addr <= 0x1AFFFFF) {
        slot = e->pad14[0];
        e->pad14[0] = 0xFF;
    } else {
        slot = e->pad14[1];
        e->pad14[1] = 0xFF;
    }
    Ch_TextureSetImageBase(chr, -1, -1);
    Ch_TextureSetClutBase(chr, -1, -1);
    if (slot != 0xFF) {
        void *p = op_oef2_a_get(res, 4, slot);

        if (p != 0) {
            op_free(addr, p);
            op_oef2_a_set(res, 4, slot, 0);
        }
    }
}

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

s32 _m2c_func_002A74A8_Ch_ModelGetBaseMatrix(s32, u16, s32) __asm__("Ch_ModelGetBaseMatrix");
s32 _m2c_func_002A74A8_func_00110C00(s32, u16) __asm__("func_00110C00");
s32 _m2c_func_002A74A8_func_00110C18(s32, u16) __asm__("func_00110C18");
extern u8 _m2c_func_002A74A8_D_00703FFA __asm__("D_00703FFA");
/* DEBT(CAST) */ /* DEBT(FAKE) */
void func_002A74A8(void) {
    register s32 _cond __asm__("$3");
    Slot16 *var_22;
    Slot16 *var_3;
    s32 temp_18;
    register s32 var_19 __asm__("$19");
    s32 var_20;
    s32 var_4;
    void *temp_16;
    register void * temp_21 __asm__("$21");
    void *var_17;

    if (_m2c_func_002A74A8_D_00703FFA != 0) {
        var_4 = 0;
        var_3 = D_006F37E0;
        do {
            temp_18 = (*(s32 *)((u8 *)(var_3) + (0)));
            var_19 = 0;
            if ((temp_18 != 0) && (temp_21 = (*(void **)((u8 *)(var_3) + (4))), var_17 = temp_21 + 0x10, ((*(u16 *)((u8 *)(temp_21) + (4))) != 0))) {
                var_22 = &var_3[1];
                var_20 = var_4 + 1;
                do {
                    temp_16 = (*(void **)((u8 *)(var_17) + (0)));
                    var_19 += 1;
                    (*(s32 *)((u8 *)(temp_16) + (8))) = (s32) (((s32)((u8 *)(_m2c_func_002A74A8_func_00110C18(temp_18, (*(u16 *)((u8 *)(var_17) + (0xA))))) - (u8 *)temp_16)));
                    (*(s32 *)((u8 *)(temp_16) + (0xC))) = (s32) (((s32)((u8 *)(_m2c_func_002A74A8_func_00110C00(temp_18, (*(u16 *)((u8 *)(var_17) + (0xA))))) - (u8 *)temp_16)));
                    (*(s32 *)((u8 *)(var_17) + (4))) = _m2c_func_002A74A8_Ch_ModelGetBaseMatrix(temp_18, (*(u16 *)((u8 *)(var_17) + (0xA))), 0);
                    var_17 += 0x10;
                } while ((_cond = (var_19 < (s32) (*(u16 *)((u8 *)(temp_21) + (4))))) != 0);
            } else {
                var_22 = &var_3[1];
                var_20 = var_4 + 1;
            }
            var_4 = var_20;
            var_3 = var_22;
        } while (var_4 < 8);
    }
}

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

extern char D_005756C0[];
extern char D_005756F0[];
extern char D_00575728[];
extern char D_00575760[];
int Ch_SetSequence(Chr *chr, int seq);
int Ch_GetSeqFrame(Chr *chr);

int func_002A7620(int id, int seq, int flag)
{
    int ret;
    Chr *chr = owu_chr_hd[id];

    if (MsBattleChrStart() != 0) {
        if (flag != 0) {
            return;
        }
        if (id < 0x20) {
            func_00120108(D_005756C0, id, seq);
            ret = ((int (*)(int, int))func_001CE050)(id, seq);
            goto out;
        } else if (chr != 0) {
            func_00120108(D_005756F0, chr, seq);
            Ch_ResetMotion(chr);
            Ch_SetSysMotion((int)chr, 1, seq);
            ret = Ch_GetSeqFrame(chr);
            goto out;
        }
    } else {
        if (flag == 0) {
            return;
        }
        if (chr != 0) {
            func_00120108(D_00575728, chr, seq);
            Ch_ResetMotion(chr);
            Ch_SetSequence(chr, seq);
            ret = Ch_GetSeqFrame(chr);
            goto out;
        }
    }
    func_00120108(D_00575760);
out:
    return ret;
}

INCLUDE_ASM("build/ee_asm/game/op/opu/opu_2A6FE8", opus_mdc_break_make_VitaSafe);

INCLUDE_ASM("build/ee_asm/game/op/opu/opu_2A6FE8", func_002A7BA8);

void func_002A8460(EntList *l, int n, int c, int d);
void op_2point_shadow(void *a0, void *a1, void *a2);
int MsDetachWeapon(int a, int b);

u16 *func_002A81D0(ScriptThread *th, u16 *pc)
{
    ScriptSub *sub = th->sub;

    switch (((s16)th->flags & 0xF000) >> 12) {
    case 0: {
        u16 n = (int)*(float *)((u8 *)sub + 0x40);
        int sz;
        void *p;

        sub->bBB = pc[1];
        *(u16 *)((u8 *)sub + 0xD0) = n;
        sz = (n << 9) | 0x120;
        *(u16 *)((u8 *)sub + 0xD2) = pc[2];
        *(u16 *)((u8 *)sub + 0xD4) = pc[3];
        pc += 4;
        __asm__ volatile("" : "+r"(sz) : : "memory");
        p = op_malloc(*(void **)((u8 *)th + 0x3A8), sz);
        *(void **)((u8 *)sub + 0xBC) = p;
        func_002A8460(p, 8, 16, *(u16 *)((u8 *)sub + 0xD0));
        opus_draw_on((IdList *)((u8 *)th + 0x300), th->h214);
        break;
    }
    case 1: {
        if (th->h212 == 0) {
            Chr *c;
            if (sub->b18 < 0x14) {
                c = (Chr *)MsGetWeaponHandle(sub->b18, 0);
            } else {
                c = owu_chr_hd[sub->b18];
            }
            if (c != 0) {
                u8 *m40 = (u8 *)th + 0x40;
                u8 *mA0 = (u8 *)th + 0xA0;
                Ch_GetRootGlobalMatrix(c, th);
                opus_get_bone_matrix(m40, c, *(u16 *)((u8 *)sub + 0xD2));
                opus_get_bone_matrix(mA0, c, *(u16 *)((u8 *)sub + 0xD4));
                func_002B56D8(m40, th, m40);
                func_002B56D8(mA0, th, mA0);
                op_2point_shadow(*(void **)((u8 *)sub + 0xBC), (u8 *)th + 0x70, (u8 *)th + 0xD0);
            }
        }
        pc += 1;
        break;
    }
    case 2: {
        u8 *obj300;
        int r = op_et_weapon_afterimage(owu_chr_hd[sub->b18], 0, 0, 0, 0, 0, 0);
        *(int *)((u8 *)sub + 0xA8) = r;
        obj300 = (u8 *)th + 0x300;
        if (*(void **)(obj300 + 0x24) == *(void **)D_0054D5E8) {
            (*(u16 *)(obj300 + 0x38))++;
            if (*(u16 *)(obj300 + 0x36) < *(u16 *)(obj300 + 0x38)) {
                *(u16 *)(obj300 + 0x36) = *(u16 *)(obj300 + 0x38);
            }
        }
        pc += 9;
        break;
    }
    case 3:
        func_00297CE8(*(Chr **)((u8 *)sub + 0xA8));
        pc += 1;
        break;
    case 4:
        if (sub->b18 < 8) {
            MsDetachWeapon(sub->b18, 0);
        }
        pc += 1;
        break;
    case 5:
        if (sub->b18 < 8) {
            MsDetachWeapon(sub->b18, 1);
        }
        pc += 1;
        break;
    case 6: {
        int flag = 2;
        goto set_shadow;
    case 7:
        flag = 0;
    set_shadow:
        func_002967E8(th, pc);
        pc += 1;
        MsSetChrShadow(sub->b18, flag);
        break;
    }
    }
    return pc;
}

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

extern void op_oef2_se_on(void *, int, int);
extern void op_oef2_sound_cue_multi(int, int, int, int);
extern void op_oef2_sep_free_all(int);
extern int op_oef2_sound_cue_check(int);
extern void op_oef2_se_3d_on(void *, void *, int);
extern void op_oef2_se_3d_move(void *, void *, int);
extern void op_oef2_stream_cue(void *, int, int);
extern void op_oef2_se_fade_out(void *, int);
extern void _2A8D08_MsChrSEfoot(int, int) __asm__("MsChrSEfoot"); /* DEBT(TYPE): int arg 1 */
extern int SndGetNowPlayMusic(void);

s16 *func_002A8D08(ScriptThread *th, s16 *pc)
{
    ScriptSub *sub = th->sub;
    u8 b1e = sub->b1E;
    u16 pc1 = (u16)pc[1];
    int res = th->res[b1e];
    int mask = 8;
    int i;

    if (!(th->flags & 0x800)) {
        mask = 0x10000;
        if (b1e != 0) {
            i = b1e;
            do {
                mask <<= 1;
                i--;
            } while (i != 0);
        }
    }

    switch (th->flags & 0xF000) {
        case 0x0000:
            pc += 2;
            op_oef2_se_on(op_oef2_a_get(res, 6, pc1), 0x40, 0x100);
            break;
        case 0x1000:
            op_oef2_sound_cue_multi(res, 0, 0x3E8, mask);
            pc += 1;
            break;
        case 0x2000:
            op_oef2_sep_free_all(mask);
            pc += 1;
            break;
        case 0x3000:
            if (op_oef2_sound_cue_check(mask) == 0) {
                pc += 1;
            } else {
                *((u8 *)th + 0x210) = 1; /* DEBT(CAST): ScriptThread +0x210 byte */
            }
            break;
        case 0x4000:
            pc += 3;
            op_oef2_se_3d_on(op_oef2_a_get(res, 6, pc1), (u8 *)sub + 0x90, 0x100); /* DEBT(CAST): ScriptSub +0x90 */
            break;
        case 0x5000:
            pc += 3;
            op_oef2_se_3d_move(op_oef2_a_get(res, 6, pc1), (u8 *)sub + 0x90, 0x100); /* DEBT(CAST): ScriptSub +0x90 */
            break;
        case 0x6000:
            op_oef2_stream_cue(op_oef2_a_get(res, 6, pc1), pc[2], mask);
            pc += 3;
            break;
        case 0x7000:
            MsChrSEfoot(*((u8 *)sub + 0x18), 1); /* DEBT(CAST): ScriptSub +0x18 */
            pc += 1;
            break;
        case 0x8000:
            MsChrSEfoot(*((u8 *)sub + 0x18), 0); /* DEBT(CAST): ScriptSub +0x18 */
            pc += 1;
            break;
        case 0x9000:
            for (i = 0; i < 0x20; i++) {
                if (owu_chr_hd[i] != 0) {
                    _2A8D08_MsChrSEfoot(i, 1);
                }
            }
            pc += 1;
            break;
        case 0xA000:
            for (i = 0; i < 0x20; i++) {
                if (owu_chr_hd[i] != 0) {
                    _2A8D08_MsChrSEfoot(i, 0);
                }
            }
            pc += 1;
            break;
        case 0xB000:
            op_oef2_se_fade_out(op_oef2_a_get(res, 6, pc1), pc[2]);
            pc += 3;
            break;
        case 0xC000:
            {
                register int mus __asm__("$16") = SndGetNowPlayMusic(); /* DEBT(REG): pin mus to $s0 */
                if (mus >= 0) {
                    func_002D85F0(mus, pc[1], 0);
                }
                pc += 2;
            }
            break;
    }
    return pc;
}

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

u16 *opu_et_etc(ScriptThread *th, u16 *pc)
{
    u8 *obj300 = (u8 *)th + 0x300;
    ScriptSub *sub = th->sub;
    u8 chrid = sub->b18;
    Chr *chr = owu_chr_hd[chrid];
    register u16 mask __asm__("$18");

    switch ((s16)(pc[1] - 1)) {
    case 0:
        obj300[0x3A]++;
        if (obj300[0x3A] >= 0xFA) {
            obj300[0x3A] = 0xFA;
        }
        pc += 2;
        break;
    case 1:
        if (obj300[0x3A] != 0) {
            obj300[0x3A]--;
        }
        pc += 2;
        break;
    case 2:
        if (obj300[0x3A] >= 10) {
            pc = (u16 *)((u8 *)pc + (s16)pc[2]);
        } else {
            pc += 3;
        }
        break;
    case 3:
        MMI_SQ_ZERO(0, th);
        *(float *)((u8 *)th + 4) = *(float *)((u8 *)sub + 0x34);
        pc += 2;
        op_et_weapon_effect_on(sub->b18, (u8 *)sub + 0x90, th);
        break;
    case 4:
        func_002992B8(chr, pc[2]);
        pc += 3;
        break;
    case 5:
        func_002994B8(chr);
        pc += 2;
        break;
    case 6:
        func_002994D8(chr);
        pc += 2;
        break;
    case 7:
        op_et_bindeff_off(chr);
        pc += 2;
        break;
    case 8:
        op_et_bindeff(chr);
        pc += 2;
        break;
    case 9:
        func_002985C0(chr);
        pc += 2;
        break;
    case 10:
        func_002985E0(chr);
        pc += 2;
        break;
    case 11:
        sub->bB3 = 0x7F;
        pc += 2;
        break;
    case 12: {
        register int i __asm__("$5") = opus_get_weapon_index_by_chrid(chrid);
        register HandlePool *hp __asm__("$3");
        register u8 *ap __asm__("$2");
        __asm__ volatile("" : "+r"(i));
        hp = &D_00703E20;
        __asm__("sll %0, %2, 2\n\taddu %0, %1, %0" : "=&r"(ap) : "r"(hp), "r"(i));
        chr = *(Chr **)(ap + 0x10);
        if (chr == 0) {
            pc += 3;
        } else {
            if (hp->b6C[i] >= 0x21) {
                pc = (u16 *)((u8 *)pc + (s16)pc[2]);
            } else {
                pc += 3;
            }
        }
        break;
    }
    case 13:
        mask = 0x100;
        goto check_status;
    case 14:
        mask = 0x200;
        goto check_status;
    case 15:
        mask = 0x2000;
        goto check_status;
    case 16:
        mask = 0x1000;
        goto check_status;
    case 17:
        mask = 0x800;
check_status:
        if (func_00110758(chr) != 0) {
            pc = (u16 *)((u8 *)pc + (s16)pc[2]);
        } else {
            register int idx __asm__("$5") = opus_get_chr_status_index(chr, 0, 0);
            if (idx < 0) {
                pc = (u16 *)((u8 *)pc + (s16)pc[2]);
            } else {
                register int off __asm__("$3") = idx << 5;
                register u16 gflags __asm__("$5") = D_00704010;
                register int hit __asm__("$2");
                mask |= 0x4020;
                hit = mask & (((ResEntry *)((u8 *)owu_chr_status + off))->flags | gflags);
                if (hit != 0) {
                    pc = (u16 *)((u8 *)pc + (s16)pc[2]);
                } else {
                    pc += 3;
                }
            }
        }
        break;
    case 18:
        if (D_00703FFE & 1) {
            pc = (u16 *)((u8 *)pc + (s16)pc[2]);
        } else {
            pc += 3;
        }
        break;
    case 19:
        if (D_00703FFE & 2) {
            pc = (u16 *)((u8 *)pc + (s16)pc[2]);
        } else {
            pc += 3;
        }
        break;
    }
    return pc;
}

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
        func_002B5348(th->m80, th->m80, sub->v30, &sub->f90);
        func_002B56D8(th->m80, opus_local_get(th, sub), th->m80);
        func_002B56D8(th->mC0, th->m2C0, th->m80);
        op_md_draw_map_test(0x6800000, (int)th->mC0, 0x1F00000); /* DEBT(TYPE): takes the matrix as an int */
        break;
    case 0x2000:
        break;
    }
    return pc;
}

void func_002A9960(void *p);
void func_002A9A70(ScriptThread *th, ScriptSub *sub, void *p);
void op_ota_encount1_draw(void *p);
int func_001AE5D8(void);
int func_002AA6C8(int res, int start, int n);
void opus_encount4_init(void *p, int res, void *p324, ScriptSub *sub, s16 *pc);
int opus_encount4_calc(void *p, ScriptThread *th, void *obj300, ScriptSub *sub, void *no, s16 *pc);
void func_002AAF30(void *p);
void func_002AB178(void *p);
void func_002B2E10(void (*fn)(void *), void *arg, int a, int b);
void func_002B2E50(void (*fn)(void *), void *arg, s16 *pc, int b);
void func_002AB3F8(u8 *a0, float *a1);
void func_002AB678(ScriptThread *th, ScriptSub *sub, int addr, void *pos, int w328);

typedef struct {
    void *p0;
    void *p4;
    void *p8;
    int wC;
    s16 *p10;
} EncWork;

typedef struct {
    s16 h0;
    s16 h2;
    s16 h4;
    s16 h6;
    void *p8;
} EncWork0;

s16 *opu_encount(ScriptThread *th, s16 *pc_arg)
{
    register ScriptSub *sub __asm__("$18") = th->sub;
    register s16 *pc __asm__("$19") = pc_arg;
    s16 mode = pc[1];
    int res = th->res[sub->b1E];
    u8 stack_pad[0x20];

    switch (mode) {
    case 0: {
        register EncWork0 *p0 __asm__("$2") = op_malloc(*(void **)((u8 *)th + 0x3A8), 0xD830);
        EncWork0 *p = p0;
        register int c12 __asm__("$3") = 12;
        register int a0 __asm__("$4");
        register int a1 __asm__("$5");
        __asm__ volatile("" : "+r"(p0), "+r"(c12));
        *(void **)((u8 *)sub + 0xBC) = p0;
        __asm__ volatile("" : "+r"(res), "+r"(c12) : "r"(p0) : "memory");
        a0 = res;
        __asm__ volatile("" : "+r"(a0), "+r"(c12));
        p->h6 = c12;
        __asm__ volatile("" : "+r"(c12) : "r"(a0) : "memory");
        a1 = 4;
        __asm__ volatile("" : "+r"(a1), "+r"(c12));
        p->h2 = c12;
        __asm__ volatile("" : "+r"(c12));
        p->h4 = c12;
        p->p8 = op_oef2_a_get(a0, a1, pc[2]);
        pc += 3;
        func_002A9960(p);
        break;
    }
    case 1:
        func_002A9A70(th, sub, *(void **)((u8 *)sub + 0xBC));
        pc += 2;
        break;
    case 2: {
        EncWork *p = *(EncWork **)((u8 *)sub + 0xBC);
        void *m;
        if (p == 0) {
            register EncWork *p0 __asm__("$2") = op_malloc(*(void **)((u8 *)th + 0x3A8), 0xE0);
            *(void **)((u8 *)sub + 0xBC) = p0;
            p = p0;
        }
        p->p0 = *(void **)((u8 *)th + 0x324);
        p->p4 = sub;
        p->p8 = opus_no_get((u8 *)th + 0x300, sub, pc[2]);
        p->wC = res;
        p->p10 = pc;
        pc += 9;
        op_unit_m_scale((u8 *)p + 0x20, 0.0625f);
        __asm__("" : "+r"(p));
        m = opus_local_get(th, sub);
        op_m_copy((u8 *)p + 0x60, m);
        func_002DD610((u8 *)p + 0xA0, 512.0f, 0.8f, 0.87285f,
                      *(float *)((u8 *)sub + 0x40) + 2048.0f,
                      *(float *)((u8 *)sub + 0x44) + 2048.0f,
                      1.0f, 16777215.0f, 1.0f, 65536.0f);
        func_002B2E10(op_ota_encount1_draw, p, th->h214, 1);
        break;
    }
    case 4:
        if (func_001AE5D8() != 0) {
            pc += 2;
        } else {
            *((u8 *)th + 0x210) = 1;
        }
        break;
    case 8: {
        void *p = op_malloc(*(void **)((u8 *)th + 0x3A8), func_002AA6C8(res, pc[2], pc[3]));
        register s16 *old_pc __asm__("$8") = pc;
        void *p324;
        __asm__("" : "+r"(old_pc));
        p324 = *(void **)((u8 *)th + 0x324);
        *(void **)((u8 *)sub + 0xBC) = p;
        pc += 5;
        opus_encount4_init(p, res, p324, sub, old_pc);
        break;
    }
    case 9: {
        u8 *obj300 = (u8 *)th + 0x300;
        void *no = opus_no_get(obj300, sub, pc[2]);
        if (opus_encount4_calc(*(void **)((u8 *)sub + 0xBC), th, obj300, sub, no, pc) == 0) {
            *(u16 *)((u8 *)sub + 0xB0) |= 0x8000;
        }
        pc += 3;
        break;
    }
    case 10:
    case 11: {
        void *p = *(void **)((u8 *)sub + 0xBC);
        void *m = opus_local_get(th, sub);
        op_m_copy((u8 *)p + 0x60, m);
        if (mode == 10) {
            func_002B2E50(func_002AAF30, p, pc, 1);
        } else {
            func_002B2E50(func_002AB178, p, pc, 1);
        }
        pc += 5;
        break;
    }
    case 12:
        MMI_SQ_ZERO(0, th);
        ((s32 *)th)[0] = 0;
        ((s32 *)th)[1] = 0;
        func_002AB3F8((u8 *)0x1D00000, (float *)th);
        pc += 1;
        break;
    case 13: {
        float f;
        register ScriptThread *a0 __asm__("$4");
        register ScriptSub *a1 __asm__("$5");
        register int a2 __asm__("$6");
        register u8 *a3 __asm__("$7");
        MMI_SQ_ZERO(0, th);
        f = 2048.0f;
        __asm__ volatile("" : "+f"(f));
        a0 = th;
        __asm__ volatile("" : "+r"(a0));
        a1 = sub;
        a2 = 0x1D00000;
        __asm__ volatile("" : "+r"(a0), "+r"(a1), "+r"(a2), "+f"(f));
        ((float *)th)[1] = f;
        __asm__ volatile("" : "+r"(a1), "+f"(f) : : "memory");
        a3 = (u8 *)a1 + 0x90;
        __asm__ volatile("" : "+r"(a3), "+f"(f));
        ((float *)th)[0] = f;
        __asm__ volatile("" : "+r"(pc) : "r"(a2), "r"(a3) : "memory");
        pc += 1;
        __asm__ volatile("" : "+r"(pc) : : "memory");
        func_002AB678(a0, a1, a2, a3, *(int *)((u8 *)a0 + 0x328));
        break;
    }
    }
    (void)stack_pad;
    return pc;
}

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

float func_002B3DF8(float a);

void func_002AB3F8(u8 *a0, float *a1)
{
    u8 *v1 = a0 + 0x20;
    u8 *s0 = v1;
    float f20 = a1[0] + 2048.0f;
    float f21 = a1[1] + 2048.0f;
    int i;

    *(int *)(a0 + 0) = 0;
    for (i = 0; i < 0x200; i++, s0 += 0x58) {
        *(float *)(s0 + 0x10) = (f20 - 256.0f) + (float)i;
        *(float *)(s0 + 0x14) = f21 - 208.0f;
        *(float *)(s0 + 0x18) = 0.0f;
        *(float *)(s0 + 0x38) = (float)i * 0.001953125f;
        *(float *)(s0 + 0x3C) = 0.0f;
    }
    for (i = 0; i < 0x1A0; i++, s0 += 0x58) {
        *(float *)(s0 + 0x10) = f20 + 256.0f;
        *(float *)(s0 + 0x14) = (f21 - 208.0f) + (float)i;
        *(float *)(s0 + 0x18) = 0.0f;
        *(float *)(s0 + 0x38) = 1.0f;
        *(float *)(s0 + 0x3C) = (float)i * 0.001953125f;
    }
    for (i = 0x1FF; i >= 0; i--, s0 += 0x58) {
        *(float *)(s0 + 0x10) = (f20 - 256.0f) + (float)i;
        *(float *)(s0 + 0x14) = f21 + 208.0f;
        *(float *)(s0 + 0x18) = 0.0f;
        *(float *)(s0 + 0x38) = (float)i * 0.001953125f;
        *(float *)(s0 + 0x3C) = 0.8125f;
    }
    for (i = 0x19F; i >= 0; i--) {
        *(float *)(s0 + 0x10) = f20 - 256.0f;
        *(float *)(s0 + 0x18) = 0.0f;
        *(float *)(s0 + 0x14) = (f21 - 208.0f) + (float)i;
        s0 += 0x58;
        *(float *)(s0 + 0x3C) = (float)i * 0.001953125f;
        *(float *)(s0 + 0x38) = 0.0f;
    }
    s0 = v1;
    for (i = 0; i < 0x740; i++, s0 += 0x58) {
        *(float *)(s0 + 0x0) = f20;
        *(float *)(s0 + 0x4) = f21;
        *(float *)(s0 + 0x8) = 0.0f;
        *(float *)(s0 + 0x30) = (f20 - 1792.0f) * 0.001953125f;
        *(float *)(s0 + 0x34) = (f21 - 1840.0f) * 0.001953125f;
        *(u32 *)(s0 + 0x20) = 0x80808080;
        *(u32 *)(s0 + 0x24) = 0x80808080;
        *(float *)(s0 + 0x40) = 0.0f;
        *(float *)(s0 + 0x44) = 0.0f;
        *(float *)(s0 + 0x48) = 0.0f;
        *(float *)(s0 + 0x4C) = 0.0f;
        *(float *)(s0 + 0x50) = 0.0f;
        *(float *)(s0 + 0x54) = func_002B3DF8(0.001f) + 0.002f;
    }
}

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

extern char D_00575878[];
extern char D_005758B8[];
extern char D_005758E0[];
extern char D_00575900[];
extern char D_00575930[];
extern char D_00575960[];
extern char D_00575988[];
extern char D_005759A0[];
extern char D_005759C8[];
int Ch_TextureGetNbImage(Chr *chr);
void *Ch_TextureGetImagePtr(Chr *chr, int i, int *w, int *h);
int func_00117580(Chr *chr);
void *func_001175D8(Chr *chr, int i, int *nb);

s16 *opu_file(void *a0, s16 *p)
{
    char path[0x200];
    int w;
    int h;
    int nb;
    int chrno;
    int idx;
    Chr *chr;
    int n_img;
    int n_clut;
    int cnt;
    int i;
    void *ptr;
    int fd;

    if (p[1] == 0) {
        chrno = p[2];
        i = opus_get_chr_status_index_by_chrno(chrno);
        if (i >= 0) {
            chr = owu_chr_status[i].chr;
            if (chr != 0) {
                n_img = p[3];
                n_clut = p[4];
                func_00120108(D_00575878, chrno);
                cnt = Ch_TextureGetNbImage(chr);
                if (cnt != n_img) {
                    func_00120108(D_005758B8, cnt);
                } else {
                    func_00120108(D_005758E0, cnt);
                }
                for (i = 0; i < cnt; i++) {
                    ptr = Ch_TextureGetImagePtr(chr, i, &w, &h);
                    func_00120108(D_00575900, i, w * h);
                    func_002F0008(path, D_00575930, chrno, i);
                    fd = func_002FC4E0(path, 0x602);
                    if (fd >= 0) {
                        func_002FCD90(fd, ptr, w * h);
                        func_002FC768(fd);
                    }
                }
                cnt = func_00117580(chr);
                if (cnt != n_clut) {
                    func_00120108(D_00575960, cnt);
                } else {
                    func_00120108(D_00575988, cnt);
                }
                for (i = 0; i < cnt; i++) {
                    ptr = func_001175D8(chr, i, &nb);
                    func_00120108(D_005759A0, i, nb);
                    func_002F0008(path, D_005759C8, chrno, i);
                    fd = func_002FC4E0(path, 0x602);
                    if (fd >= 0) {
                        func_002FCD90(fd, ptr, nb * 4);
                        func_002FC768(fd);
                    }
                }
            }
        }
        p += 5;
    }
    return p;
}

typedef struct MimicItem60 {
    void *p0;
    s16 h4;
    s16 h6;
    u8 pad8[8];
    u_long128 q10;
    u8 pad20[0x40];
} MimicItem60; /* DEBT(NAME) */

typedef struct OpuMimicWork {
    ResEntry *p0;
    ResEntry *p4;
    s32 p8;
    s16 hC;
    u16 hE;
    s8 b10;
    u8 pad11[0xF];
    s32 a20[32];
    s32 aA0[32];
    MimicItem60 items[1];
} OpuMimicWork; /* DEBT(NAME) */

void *_opu_op_malloc(s32, s32) __asm__("op_malloc");
s32 _opu_opus_get_chr_status_index_by_chrno(s32) __asm__("opus_get_chr_status_index_by_chrno");
void _opu_opus_draw_on(void *, s32) __asm__("opus_draw_on");
void *_opu_opus_no_get(void *, void *, s32) __asm__("opus_no_get");
void *_opu_opus_get_osu_by_draw(s32, s32, s32, s32) __asm__("opus_get_osu_by_draw");
void _opu_Ch_TextureSetImageBase(Chr *, s32, s32) __asm__("Ch_TextureSetImageBase");
void _opu_Ch_TextureSetClutBase(Chr *, s32, s32) __asm__("Ch_TextureSetClutBase");
void *_opu_func_001E4F20(s32) __asm__("func_001E4F20");
void _opu_op_mdc_mem_transfer_cue_free(Chr *) __asm__("op_mdc_mem_transfer_cue_free");
s32 _opu_func_00110C18(Chr *, s32) __asm__("func_00110C18");
s32 _opu_func_00110C00(Chr *, s32) __asm__("func_00110C00");
extern s8 D_007649A0;
extern char D_005759F8[];
extern char D_00575A28[];

/* DEBT(CAST): raw AnimCtx/AnimTgt offsets and 128-bit vector copy */
s16 *opu_mimic(void *arg0, s16 *p)
{
    void *t = *(void **)((u8 *)arg0 + 0x220);
    OpuMimicWork *m;
    s32 i;

    switch (*(s16 *)((u8 *)arg0 + 0x21A) & 0xF000) {
    case 0: {
        i = p[1];
        *(OpuMimicWork **)((u8 *)t + 0xBC) = (OpuMimicWork *)_opu_op_malloc(*(s32 *)((u8 *)arg0 + 0x3A8), i * 0x60 + 0x120);
        m = *(OpuMimicWork **)((u8 *)t + 0xBC);
        m->hC = i;
        m->hE = 0;
        m->b10 = 0;
        m->p0 = &owu_chr_status[_opu_opus_get_chr_status_index_by_chrno(p[2])];
        m->p4 = &owu_chr_status[_opu_opus_get_chr_status_index_by_chrno(p[3])];
        p += 4;
        *(s8 *)((u8 *)t + 0xBB) = 0x12;
        _opu_opus_draw_on((u8 *)arg0 + 0x300, *(s16 *)((u8 *)arg0 + 0x214));
        break;
    }
    case 0x1000: {
        MimicItem60 *items;
        s32 idx;
        u_long128 q;

        m = *(OpuMimicWork **)((u8 *)_opu_opus_no_get((u8 *)arg0 + 0x300, t, p[1]) + 0xBC);
        items = m->items;
        idx = m->hE;
        items[idx].h4 = (s32)*(float *)((u8 *)t + 0x40);
        items[idx].h6 = (s32)*(float *)((u8 *)t + 0x4C);
        items[idx].p0 = t;
        __asm__ volatile("lq %0, 0x30(%1)" : "=r"(q) : "r"(t));
        __asm__ volatile("sq %0, 0x10(%1)" : : "r"(q), "r"(&items[idx]) : "memory");
        *(s32 *)((u8 *)&items[idx] + 0x1C) = 0;
        m->hE++;
        p += 2;
        break;
    }
    case 0x2000: {
        s32 buf;
        s32 nb;

        m = *(OpuMimicWork **)((u8 *)_opu_opus_get_osu_by_draw(0, 0, 0x12, 1) + 0xBC);
        t = *(void **)m->p4;
        _opu_Ch_TextureSetImageBase((Chr *)t, -1, 0x3C00);
        _opu_Ch_TextureSetClutBase((Chr *)t, -1, 0x2EE0);
        if (op_mdc_size_get_main((int)t, 2, 1, 0) == 0) {
            return p + 3;
        }
        buf = (s32)_opu_func_001E4F20(0);
        if (buf == 0) {
            if (D_007649A0 == 0) {
                func_00120108(D_005759F8);
                func_002EA328(1);
            }
            func_00120108(D_00575A28);
            buf = 0x01E80000;
        }
        m->p8 = buf;
        func_002A7140(buf, (s32)t, 2, 0, 0, *(s32 *)((u8 *)arg0 + 0x328));
        _opu_op_mdc_mem_transfer_cue_free((Chr *)t);
        nb = Ch_GetNbModel((Chr *)t);
        for (i = 0; i < nb; i++) {
            m->a20[i] = _opu_func_00110C18((Chr *)t, i);
            m->aA0[i] = _opu_func_00110C00((Chr *)t, i);
        }
        p += 1;
        break;
    }
    }
    return p;
}

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

typedef struct MimicEntry {
    u8 pad0[4];
    u16 h4;
    u8 pad6[0x1A];
    u8 mat20[0x40];
} MimicEntry;

typedef struct MimicWork {
    Chr **pp0;
    Chr **pp4;
    u8 pad8[6];
    u16 hE;
    u8 pad10[0x110];
    MimicEntry entries[1];
} MimicWork;

typedef struct MimicOsu {
    u8 pad0[0xBC];
    MimicWork *w;
} MimicOsu;

MimicOsu *opus_get_osu_by_draw(int a, int b, int c, int d);

int opus_mdc_size_get_mimic(int mode, int flag)
{
    MimicOsu *osu = opus_get_osu_by_draw(0, 0, 0x12, 1);
    MimicWork *w;
    int i;
    int total;
    Chr *chr;
    MimicEntry *e;

    if (osu == 0) {
        return 0;
    }
    w = osu->w;
    chr = *w->pp4;
    e = &w->entries[0];
    total = 0;
    for (i = 0; i < w->hE; i++, e++) {
        u32 sz = (Ch_ModelCalcSizeEffectPacket(chr, e->h4) + 0xF) & 0xFFFFFF0;
        u32 extra = 0;

        if (mode == 2) {
            extra = sz / 0x1C * 3;
            extra <<= 2;
            extra = (extra + 0xF) & 0xFFFFFF0;
        }
        total = total + sz + extra;
    }
    return total;
}

void opus_mdc_make_mimic(MdcHdr *hdr, int mode, int work)
{
    u8 *fp = (u8 *)hdr;
    MimicOsu *osu = opus_get_osu_by_draw(0, 0, 0x12, 1);
    u8 *s3;
    MimicWork *s5;
    MimicEntry *s2;
    Chr *s4;
    u8 *s1;
    int s7;
    int i;

    if (osu == 0) {
        return;
    }
    s3 = fp + 0x10;
    s5 = osu->w;
    s7 = 0;
    s2 = &s5->entries[0];
    {
        Chr *c0 = *s5->pp0;
        s4 = *s5->pp4;
        fp[6] = mode;
        *(Chr **)fp = c0;
    }
    s1 = s3 + (s5->hE << 4);
    for (i = 0; i < s5->hE; i++, s2++, s3 += 0x10, s7++) {
        u32 sz;
        u8 *next;
        if (Ch_ModelGetHide(s4, s2->h4) != 0) {
            *(u16 *)(s3 + 8) |= 1;
        }
        *(u8 **)s3 = s1;
        *(u8 **)(s3 + 4) = s2->mat20;
        sz = Ch_ModelCalcSizeEffectPacket(s4, s2->h4);
        Ch_ModelCreateEffectPacket(s4, s2->h4, s1);
        next = s1 + ((sz + 0xF) & 0xFFFFFF0);
        if (mode == 2) {
            next = op_md_vn_index(s1, next, work);
        }
        s1 = next;
    }
    *(s16 *)(fp + 4) = s7;
}

