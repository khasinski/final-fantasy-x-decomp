/* tu_322 0x2a6fe8-0x2ac750: low; ~op_mdc_size_get_main (config/tu_map.tsv) */
/* DEBT(NAME): module and names guessed: script call wrappers (see w10.h). */
#define func_002A74A8 _hdr_func_002A74A8
#include "common.h"
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

INCLUDE_ASM("build/ee_asm/game/op/opu/opu_2A6FE8", opus_mdc_make_mimic);
