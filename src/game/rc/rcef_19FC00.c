/* tu_169 0x19fc00-0x1a21e0: low; ~rcef (config/tu_map.tsv) */
#define func_001A1A68 _hdr_func_001A1A68
#define func_001A1BE8 _hdr_func_001A1BE8
#define Sg_Blur _hdr_Sg_Blur
#include "common.h"
#include "ffx/q3.h"
#include "ffx/s2.h"
#include "ffx/v2.h"
#include "ffx/r2.h"
#include "ffx/w3.h"
#include "ffx/u2.h"
#include "vu0.h"
#undef func_001A1A68
#undef func_001A1BE8
#undef Sg_Blur

void Sg_Blur(int);

INCLUDE_ASM("build/ee_asm/game/rc/rcef_19FC00", func_0019FC00);

void rcefMainProcRunAfter(void *p) {
    S2Obj1C *o = p;
    HeapMgr *temp_4;
    void *temp_6;

    temp_4 = o->w10;
    temp_6 = o->w18;
    D_006A3924 = temp_4;
    if (temp_6 != 0) {
        func_00267028(temp_4, temp_4->sub, temp_6);
        o->w18 = 0;
    }
    func_001A1F28(&o->sched);
}

void func_0019FE38(S2Obj1C *o)
{
    D_006A3924 = o->w10;
}

void func_0019FE48(S2Obj1C *o)
{
    D_006A3924 = o->w10;
}

typedef struct RcefMainCtx {
    s32 w00;
    s32 w04;
    s32 w08;
    u8 *p0C;
    HeapMgr *w10;
    s32 w14;
    void **w18;
    W3Sched sched;
    u8 pad198[0x200 - 0x198];
    s32 w200;
    s32 w204;
    float f208;
    s32 w20C;
    s32 w210;
    s32 w214;
    s32 w218;
    float f21C;
    s32 w220;
    s32 w224;
    s32 w228;
    s32 w22C;
    s32 w230;
    s32 w234;
    s32 w238;
} RcefMainCtx;

extern float D_006A3970[16];
extern float D_006A3A70[16];
extern float D_00313EF0[16];
void func_002DCF48(void *dst, void *src);
void MsEffectTerminate(int key);
void func_001A0308(void *ctx);
void func_001A08A8(RcefMainCtx *o);
void func_001A0A10(void *o);

void func_0019FE58(RcefMainCtx *o)
{
    W3Sched *sched = &o->sched;

    D_006A3924 = o->w10;
    func_001A9EE0(D_006A3970);
    func_001AACA0(D_006A3A70);
    func_002DD0C0(D_00313EF0, D_006A3970);
    D_00313EF0[12] = D_00313EF0[13] = D_00313EF0[14] = 0.0f;
    func_002DCF48(D_00313EF0, D_00313EF0);
    D_006A3BCC = o->p0C;
    rcefTaskCtrlProc(&sched->head);
    if (func_001A2040(sched) != 0) {
        MsEffectTerminate(o->w04);
    }
    if (o->w200 == 0) {
        func_001A0308(o);
    }
    func_001A08A8(o);
    func_001A0A10(o);
    o->w238++;
}

void *func_0019FF48(S2Obj1C *o) {
    void *p = rcefObjNew();

    rcefObjInit(p);
    func_001A1FF0(&o->sched.head, p);
    return p;
}

void *func_0019FF90(S2Obj1C *o, int fn) {
    void *p = func_0019FF48(o);

    func_001A1D08(p, fn);
    return p;
}

s32 _m2c_rcefMainKickPar_func_001A14D0(void *, void *, s32, void *, void *, void *) __asm__("func_001A14D0");
void rcefMainKickPar(S2Obj1C *arg0, S2Obj1A *arg1, s32 arg2, s32 arg3) {
    _m2c_rcefMainKickPar_func_001A14D0(arg1->b280, arg0->w18[arg2], arg3, arg1->m1F0, arg1->v160, arg1->v170);
}

int *_m2c_func_001A0000_op_oef2_a_get(int a, int b, int c) __asm__("op_oef2_a_get");
s32 _m2c_func_001A0000_func_001A1780(void *, s32 *, void *, void *) __asm__("func_001A1780");
void func_001A0000(S2Obj1C *arg0, S2Obj1A *arg1, s32 arg2) {
    _m2c_func_001A0000_func_001A1780(arg1->b330, _m2c_func_001A0000_op_oef2_a_get(arg0->w8, 4, arg2), arg1->m1F0, arg1->v170);
}

int *_m2c_func_001A0040_op_oef2_a_get(int a, int b, int c) __asm__("op_oef2_a_get");
s32 _m2c_func_001A0040_func_001A1A08(void *, s32 *, void *, void *) __asm__("func_001A1A08");
void func_001A0040(S2Obj1C *arg0, S2Obj1A *arg1, s32 arg2) {
    _m2c_func_001A0040_func_001A1A08(arg1->b3C0, _m2c_func_001A0040_op_oef2_a_get(arg0->w8, 4, arg2), arg1->m1F0, arg1->v170);
}

INCLUDE_ASM("build/ee_asm/game/rc/rcef_19FC00", func_001A0080);

void func_001A01B0(u32 a0, u32 a1, u32 a2)
{
    __asm__ volatile(
        "addiu      $7, $0, 0x1\n"
        "addiu      $2, $4, 0x1D0\n"
        "sw         $7, 0x1C0($4)\n"
        "sqc2       $vf0, 0x0($2)\n"
        "addiu      $3, $4, 0x1E0\n"
        "lqc2       $vf31, 0x0($5)\n"
        "sqc2       $vf31, 0x0($3)\n"
        "sw         $6, 0x1F0($4)\n"
        "sw         $7, 0x1FC($4)\n"
        "sw         $0, 0x200($4)\n"
        "sw        $0, 0x1F4($4)\n"
        :  : "r"(a0), "r"(a1), "r"(a2) : "$2", "$3", "$7");
}

void func_001A01E0(u32 a0, u32 a1, u32 a2, u32 a3)
{
    __asm__ volatile(
        "addiu      $8, $0, 0x1\n"
        "addiu      $2, $4, 0x1D0\n"
        "sw         $8, 0x1C0($4)\n"
        "lqc2       $vf31, 0x0($5)\n"
        "sqc2       $vf31, 0x0($2)\n"
        "addiu      $3, $4, 0x1E0\n"
        "lqc2       $vf31, 0x0($6)\n"
        "sqc2       $vf31, 0x0($3)\n"
        "sw         $8, 0x1FC($4)\n"
        "sw         $7, 0x1F0($4)\n"
        "sw        $0, 0x1F4($4)\n"
        :  : "r"(a0), "r"(a1), "r"(a2), "r"(a3) : "$2", "$3", "$8");
}

void func_001A0210(u8 *o)
{
    u_long128 tmp;
    register u8 *b __asm__("$3") = o + 0x1E0; /* DEBT(FAKE) */
    register u8 *a __asm__("$2");

    VU0_LQC2(31, 0, b); /* DEBT(CAST) */
    VU0_SQC2(31, 0, &tmp);
    a = o + 0x1D0;
    VU0_LQC2(31, 0, a);
    VU0_SQC2(31, 0, b);
    VU0_LQC2(31, 0, &tmp);
    VU0_SQC2(31, 0, a);
    *(s32 *)(o + 0x1F4) = 0;
    {
        register s32 one __asm__("$3") = 1; /* DEBT(FAKE) */
        *(s32 *)(o + 0x1FC) = one;
    }
}

int func_001A0248(Chr *chr)
{
    int ret = -1;
    int i;

    for (i = 0; i < 15; i++) {
        if (MsGetChrHandle(i) == chr) {
            ret = i;
            break;
        }
    }
    if (ret == -1) {
        for (i = 20; i < 28; i++) {
            if (MsGetChrHandle(i) == chr) {
                ret = i;
                break;
            }
        }
    }
    return ret;
}

s32 _m2c_func_001A02D8_func_001A0308(s32 *) __asm__("func_001A0308");
extern s32 _m2c_func_001A02D8_D_00313CB0 __asm__("D_00313CB0");
void func_001A02D8(void) {
    _m2c_func_001A02D8_func_001A0308(&_m2c_func_001A02D8_D_00313CB0);
}

typedef struct RcefCtx200 {
    u8 pad0[0x1C0];
    s32 w1C0;
    u8 pad1C4[0x3C];
    s32 w200;
} RcefCtx200;

extern RcefCtx200 D_00313CB0;

void func_001A02E8(int a)
{
    D_00313CB0.w200 = a;
    if (a != 0) {
        D_00313CB0.w1C0 = 3;
    }
}

INCLUDE_ASM("build/ee_asm/game/rc/rcef_19FC00", func_001A0308);

INCLUDE_ASM("build/ee_asm/game/rc/rcef_19FC00", func_001A04D8);

void func_001A06A8(s32 arg0, s32 arg1) {
    u32 *temp_16;

    temp_16 = func_002DB6D8(2);
    func_002F8660(0);
    func_002DBA28(temp_16, arg1);
    func_002DBF78((s32) temp_16, 0, 0);
}

INCLUDE_ASM("build/ee_asm/game/rc/rcef_19FC00", func_001A0700);

typedef struct RcefBlurCtx {
    u8 pad0[0x224];
    s32 w224;
    s32 w228;
    s32 w22C;
    s32 w230;
    s32 w234;
} RcefBlurCtx;

INCLUDE_ASM("build/ee_asm/game/rc/rcef_19FC00", func_001A08A8);

void func_001A0A10(void *p)
{
    RcefBlurCtx *o = p;
    int v;

    if (o->w234 == 0 || o->w224 == 0) {
        return;
    }
    v = o->w228;
    if (o->w224 == 2 && o->w22C > 0) {
        v = v * (o->w22C - o->w230) / o->w22C;
    }
    o->w230++;
    if (o->w230 <= o->w22C) {
        Sg_Blur(v);
        return;
    }
    Sg_Blur(0);
    o->w234 = 0;
}

s32 _m2c_func_001A0AB0_func_201E1B0(s32, s32, s32, s32) __asm__("func_201E1B0");
s32 _m2c_func_001A0AB0_func_201E210(s32, s32) __asm__("func_201E210");
void func_001A0AB0(void) {
    func_001A2058(0);
    func_001A2098(0);
    _m2c_func_001A0AB0_func_201E1B0(0, 0, 0, 0);
    _m2c_func_001A0AB0_func_201E210(0, 0);
    func_001A2388();
}

void *rcefObjNew(void)
{
    void *p = pppMemAlloc(D_006A3924, D_006A3924->sub, 0x490);

    rcefObjInit(p);
    return p;
}

void func_001A0B38(void *p)
{
    rcefObjProc(p);
    func_00267028(D_006A3924, D_006A3924->sub, p);
}

void rcefObjInit(void *p)
{
    S2Obj1A *o = p;

    func_002EF0D0(o, 0, 0x490);
    rcefTaskInit(&o->task);
    o->i13C = 0;
    o->i16C = 0;
    o->task.fnCleanup = rcefObjProc;
    o->task.fnExit = func_001A0C70;
    o->v130[2] = o->v130[1] = o->v130[0] = 1.0f;
    o->v160[2] = o->v160[1] = o->v160[0] = 1.0f;
    o->v170[2] = o->v170[1] = o->v170[0] = 1.0f;
    o->v170[3] = 1.0f;
    func_002DD128(o->m1B0);
    func_002DD128(o->m1F0);
    func_002DD128(o->m230);
    rcefParInit(o->b280);
    rcefAnimeInit(o->b330);
    func_001A19F0(o->b3C0);
}

void rcefObjProc(S2Obj1A *o) {
    func_001A14C8(o->b280);
    func_001A1778(o->b330);
    func_001A1A00(o->b3C0);
    func_001A1C40(&o->task);
}

void func_001A0C60(S2Obj1A *o) {
    o->flagsBC = 1;
}

void func_001A0C70(S2Obj1A *o) {
    rcefObjCalcLocalMatrix(o);
    func_001A0F58(o);
    rcefParProc(o->b280);
    func_001A17A0(o->b330);
    func_001A1A68(o->b3C0);
}

INCLUDE_ASM("build/ee_asm/game/rc/rcef_19FC00", rcefObjCalcLocalMatrix);

typedef struct {
    u64 pad0[0x17];
    u32 wB8;
    u32 pad_b0 : 8;
    u32 b8 : 1;
    u32 pad_b9 : 3;
    u32 b12 : 1;
} RcefFlagsObj;

extern void rcefObjCalcParentMatrix(S2Obj1A *o, float *m);

void func_001A0F58(S2Obj1A *o)
{
    RcefFlagsObj *f = (RcefFlagsObj *)o;

    if (!f->b12 || f->b8) {
        rcefObjCalcParentMatrix(o, o->m230);
        o->flagsBC |= 0x1000;
    }
    func_002DCE38(o->m1F0, o->m230, o->m1B0);
}

INCLUDE_ASM("build/ee_asm/game/rc/rcef_19FC00", rcefObjCalcParentMatrix);

void func_001A11F0(S2Obj1A *arg0, S2Obj1A *arg1) {
    S2Obj1A *temp_4;

    temp_4 = arg0->pC4;
    if (temp_4 == 0) {
        arg0->pC4 = arg1;
    } else {
        func_001A1238(temp_4, arg1);
    }
    arg1->pC0 = arg0;
}

void func_001A1238(S2Obj1A *arg0, S2Obj1A *arg1) {
    S2Obj1A *temp_2;
    S2Obj1A *var_3;
    S2Obj1A *var_4;

    var_4 = arg0;
    var_3 = var_4->pCC;
    if (var_3 != 0) {
        do {
            var_4 = var_3;
            temp_2 = var_4->pCC;
            var_3 = temp_2;
        } while (temp_2 != 0);
    }
    var_4->pCC = arg1;
    arg1->pC8 = var_4;
}

void func_001A1270(S2Obj1A *o)
{
    S2Obj1A *cur;
    S2Obj1A *next;
    S2Obj1A *tmp;

    cur = o->pC4;
    if (cur != 0) {
        if (o->pC0 != 0) {
            if (o->pC0->pC4 == o) {
                o->pC0->pC4 = cur;
            }
            do {
                cur->pC0 = o->pC0;
                cur = cur->pCC;
            } while (cur != 0);
        }
        if (o->pC8 != 0) {
            o->pC8->pCC = o->pC4;
            o->pC4->pC8 = o->pC8;
        }
        if (o->pCC != 0) {
            cur = o->pC4;
            next = cur->pCC;
            if (next != 0) {
                do {
                    cur = next;
                    tmp = cur->pCC;
                    next = tmp;
                } while (tmp != 0);
            }
            o->pCC->pC8 = cur;
            cur->pCC = o->pCC;
        }
    } else {
        if (o->pC0 != 0 && o->pC0->pC4 == o) {
            o->pC0->pC4 = o->pCC;
        }
        if (o->pC8 != 0) {
            o->pC8->pCC = o->pCC;
        }
        if (o->pCC != 0) {
            o->pCC->pC8 = o->pC8;
        }
    }
    o->pC8 = 0;
    o->pCC = 0;
    o->pC4 = 0;
    o->pC0 = 0;
}

void func_001A1378(S2Obj1A *o, int a, int b) {
    o->f270 = a;
    o->flagsBC = (o->flagsBC & ~6) | 2;
    o->f274 = b;
}

void func_001A13A0(S2Obj1A *o, int a, int b) {
    func_001A1378(o, a, Ch_OptposGetElement(rcefGetChrHandle(a), b, 0));
}

int func_001A1400(void *a) {
    Obj1A0B70 *o = a;

    return (o->flags280 & 1) ^ 1;
}

int func_001A1410(void *p) {
    Obj1A0B70 *o = p;

    return (o->flags330 & 1) ^ 1;
}

void func_001A1420(Obj1A0B70 *o, u32 flags) {
    func_001A1460(o);
    o->flagsBC |= flags;
}

void func_001A1460(Obj1A0B70 *o) {
    o->flagsBC &= 0xFFFFF00F;
}

void rcefParInit(R2Obj1A14 *o) {
    func_002EF0D0(o, 0, 0xB0);
    o->w6C = 1;
    o->f5C = 1.0f;
    o->fA0 = 1.0f;
    o->fA4 = 1.0f;
    o->fA8 = 1.0f;
    o->wAC = 0;
}

void func_001A14C8(void *b) {
}

void func_001A14D0(R2Obj1A14D0 *o, R2Tbl50 *tbl, int n, int a, int b, int c) {
    o->f0 = 1;
    o->f4 = (int)tbl;
    o->f8 = n;
    o->f70 = o->f74 = o->f78 = 1.0f;
    o->fC = tbl->ent[n].b;
    o->f90 = a;
    o->f94 = b;
    o->f98 = c;
}

INCLUDE_ASM("build/ee_asm/game/rc/rcef_19FC00", rcefParProc);

void rcefAnimeInit(Obj1A1740 *o) {
    func_002EF0D0(o, 0, 0x90);
    o->h44 = 0x200;
}

void func_001A1778(void *b) {
}

void func_001A1780(R2Rec1A17 *r, int a, int b, int c) {
    r->f0 = 1;
    r->f4 = a;
    r->f48 = b;
    r->f4C = c;
    r->f20 = r->f50;
}

void func_001A17A0(void *b) {
    u32 *o = b;

    if (*o & 1) {
        func_001A17E8(o);
        func_001A1948(o);
    }
}

extern u8 _m2c_func_001A17E8_D_006A3970[] __asm__("D_006A3970");
extern u8 _m2c_func_001A17E8_D_006A3A70[] __asm__("D_006A3A70");
/* DEBT(CAST) */
void func_001A17E8(u32 *o) {
    s16 *temp_20;
    s32 temp_19;
    s32 off;
    s32 temp_f0;
    s32 temp_f0_2;
    s32 temp_f1;
    s32 temp_f5;
    u32 *temp_17;
    u32 *temp_18;
    void *temp_2;

    temp_17 = ((u32 *)((u8 *)o + (0x50)));
    temp_19 = (*(s32 *)((u8 *)(o) + (4)));
    temp_18 = ((u32 *)((u8 *)o + (0x10)));
    off = ((*(s16 *)((u8 *)(o) + (0x42))) * 8) + 0x10;
    temp_20 = (s16 *)(temp_19 + off);
    func_002DCE38(temp_17, _m2c_func_001A17E8_D_006A3970, (*(void **)((u8 *)(o) + (0x48))));
    func_002DCE38(temp_17, _m2c_func_001A17E8_D_006A3A70, temp_17);
    temp_2 = (*(void **)((u8 *)(o) + (0x4C)));
    temp_f5 = (s32) ((*(float *)((u8 *)(temp_2) + (0))) * 128.0f);
    temp_f1 = (s32) ((*(float *)((u8 *)(temp_2) + (4))) * 128.0f);
    temp_f0_2 = (s32) ((*(float *)((u8 *)(temp_2) + (8))) * 128.0f);
    temp_f0 = (s32) ((*(float *)((u8 *)(temp_2) + (0xC))) * 128.0f);
    if (temp_f5 >= 0) {
        (*(s8 *)((u8 *)(temp_18) + (4))) = (s8) ((temp_f5 < 0x100) ? temp_f5 : 0xFF);
    } else {
        (*(s8 *)((u8 *)(temp_18) + (4))) = 0;
    }
    if (temp_f1 >= 0) {
        (*(s8 *)((u8 *)(temp_18) + (5))) = (s8) ((temp_f1 < 0x100) ? temp_f1 : 0xFF);
    } else {
        (*(s8 *)((u8 *)(temp_18) + (5))) = 0;
    }
    if (temp_f0_2 >= 0) {
        (*(s8 *)((u8 *)(temp_18) + (6))) = (s8) ((temp_f0_2 < 0x100) ? temp_f0_2 : 0xFF);
    } else {
        (*(s8 *)((u8 *)(temp_18) + (6))) = 0;
    }
    if (temp_f0 >= 0) {
        (*(s8 *)((u8 *)(temp_18) + (7))) = (s8) ((temp_f0 < 0x100) ? temp_f0 : 0xFF);
    } else {
        (*(s8 *)((u8 *)(temp_18) + (7))) = 0;
    }
    (*(u8 **)((u8 *)(temp_18) + (0x14))) = (u8 *) D_006A3BCC;
    D_006A3BCC = func_002CD590(temp_19 + *temp_20, temp_18, temp_f0_2, temp_f0);
}

typedef struct {
    s16 h0;
    s16 dur;
    s8 flags;
    u8 pad5[3];
} RcefAnimEnt;

typedef struct {
    u8 pad0[6];
    s16 count;
    u8 pad8[8];
    RcefAnimEnt ent[1];
} RcefAnimHdr;

typedef struct {
    u32 flags;
    RcefAnimHdr *hdr;
    u8 pad8[0x38];
    s16 h40;
    s16 h42;
    s16 h44;
} RcefAnime;

void func_001A1948(u32 *p)
{
    RcefAnime *o = (RcefAnime *)p;
    RcefAnimEnt *ent;

    ent = &o->hdr->ent[o->h42];
    o->h40 += o->h44;
    if (o->h40 >= ent->dur) {
        o->h40 -= ent->dur;
        o->h42++;
        if (o->h42 >= o->hdr->count) {
            if (ent->flags & 0x80) {
                o->h42 = 0;
                o->h40 = 0;
            } else {
                o->h42--;
                o->h40 = 0;
                o->flags &= ~1;
            }
        }
    }
}

void func_001A19F0(void *b) {
    func_002EF0D0(b, 0, 0xD0);
}

void func_001A1A00(void *b)
{
}

typedef struct RcefObj3C0 {
    s32 w00;
    void *p04;
    u8 pad08[8];
    V2GsSub sub;
    void *p80;
    void *p84;
    u8 pad88[8];
    float m90[16];
} RcefObj3C0;

extern u32 D_006A3B70[];
extern u32 D_006A3B30[];

INCLUDE_ASM("build/ee_asm/game/rc/rcef_19FC00", func_001A1A08);

s32 _m2c_func_001A1A68_func_001A1AB0() __asm__("func_001A1AB0");
s32 _m2c_func_001A1A68_func_001A1BE8(s32 *) __asm__("func_001A1BE8");
void func_001A1A68(s32 *arg0) {
    if (*arg0 & 1) {
        _m2c_func_001A1A68_func_001A1AB0();
        _m2c_func_001A1A68_func_001A1BE8(arg0);
    }
}

extern u8 _m2c_func_001A1AB0_D_006A3970[] __asm__("D_006A3970");
extern u8 _m2c_func_001A1AB0_D_006A3A70[] __asm__("D_006A3A70");
u8 *_m2c_func_001A1AB0_op1_md_draw(s32, void *, s32, s32) __asm__("op1_md_draw");
/* DEBT(CAST) */
void func_001A1AB0(void *arg0) {
    s32 temp_f0;
    s32 temp_f0_2;
    s32 temp_f1;
    s32 temp_f5;
    void *temp_16;
    void *temp_17;
    void *temp_2;

    temp_17 = arg0 + 0x10;
    temp_16 = arg0 + 0x90;
    func_002DCE38(temp_16, _m2c_func_001A1AB0_D_006A3970, (*(void **)((u8 *)(arg0) + (0x80))));
    func_002DCE38(temp_16, _m2c_func_001A1AB0_D_006A3A70, temp_16);
    temp_2 = (*(void **)((u8 *)(arg0) + (0x84)));
    temp_f5 = (s32) ((*(float *)((u8 *)(temp_2) + (0))) * 128.0f);
    temp_f1 = (s32) ((*(float *)((u8 *)(temp_2) + (4))) * 128.0f);
    temp_f0_2 = (s32) ((*(float *)((u8 *)(temp_2) + (8))) * 128.0f);
    temp_f0 = (s32) ((*(float *)((u8 *)(temp_2) + (0xC))) * 128.0f);
    if (temp_f5 >= 0) {
        (*(s8 *)((u8 *)(temp_17) + (0x18))) = (s8) ((temp_f5 < 0x100) ? temp_f5 : 0xFF);
    } else {
        (*(s8 *)((u8 *)(temp_17) + (0x18))) = 0;
    }
    if (temp_f1 >= 0) {
        (*(s8 *)((u8 *)(temp_17) + (0x19))) = (s8) ((temp_f1 < 0x100) ? temp_f1 : 0xFF);
    } else {
        (*(s8 *)((u8 *)(temp_17) + (0x19))) = 0;
    }
    if (temp_f0_2 >= 0) {
        (*(s8 *)((u8 *)(temp_17) + (0x1A))) = (s8) ((temp_f0_2 < 0x100) ? temp_f0_2 : 0xFF);
    } else {
        (*(s8 *)((u8 *)(temp_17) + (0x1A))) = 0;
    }
    if (temp_f0 >= 0) {
        (*(s8 *)((u8 *)(temp_17) + (0x1B))) = (s8) ((temp_f0 < 0x100) ? temp_f0 : 0xFF);
    } else {
        (*(s8 *)((u8 *)(temp_17) + (0x1B))) = 0;
    }
    (*(u8 **)((u8 *)(temp_17) + (0x34))) = (u8 *) D_006A3BCC;
    D_006A3BCC = _m2c_func_001A1AB0_op1_md_draw((*(s32 *)((u8 *)(arg0) + (4))), temp_17, temp_f0_2, temp_f0);
}

void func_001A1BE8(void)
{
}

void rcefTaskInit(W3Task *t)
{
    func_002EF0D0(t, 0, sizeof(W3Task));
    t->flags |= 1;
    t->fnCleanup = func_001A1C40;
    t->prio = 0x8000;
}

void func_001A1C40(W3Task *t)
{
}

void rcefTaskProc(W3Task *t)
{
    do {
        t->flags &= ~2;
        if (t->fn[t->sp] != 0) {
            t->fn[t->sp](t);
        }
    } while (t->flags & 2);
    if (t->fnExit != 0 && !(t->flags & 4)) {
        t->fnExit(t);
    }
}

void func_001A1CE0(W3Task *t)
{
    if (t->fnCleanup != 0) {
        t->fnCleanup(t);
    }
}

void func_001A1D08(W3Task *t, W3TaskFn fn)
{
    t->fn[t->sp] = fn;
}

void func_001A1D20(W3Task *t, W3TaskFn fn)
{
    func_001A1D08(t, fn);
    t->flags |= 2;
}

void func_001A1D50(W3Task *t, W3TaskFn fn)
{
    if (t->sp < 7) {
        t->sp++;
        t->fn[t->sp] = fn;
    }
}

void func_001A1D78(W3Task *t, W3TaskFn fn)
{
    func_001A1D50(t, fn);
    t->flags |= 2;
}

void func_001A1DA8(W3Task *t)
{
    if (t->sp > 0) {
        t->sp--;
    }
}

void func_001A1DC0(W3Task *t)
{
    func_001A1DA8(t);
    t->flags |= 2;
}

void func_001A1DF0(W3Task *t, int n)
{
    if (n > 0) {
        func_001A1D50(t, func_001A1E40);
        t->frame[t->sp].count = n;
    }
}

void func_001A1E40(W3Task *t)
{
    t->frame[t->sp].count--;
    if (t->frame[t->sp].count <= 0) {
        func_001A1DC0(t);
    }
}

void rcefTaskKill(W3Task *t)
{
    t->prev->next = t->next;
    t->next->prev = t->prev;
    func_001A1CE0(t);
    func_00267028(D_006A3924, D_006A3924->sub, t);
}

void func_001A1ED8(W3Sched *s)
{
    rcefTaskInit(&s->head);
    rcefTaskInit(&s->tail);
    s->head.next = &s->tail;
    s->tail.prio = 0xFFFF;
    s->head.prio = 0;
    s->tail.prev = &s->head;
    s->i178 = 0;
}

void func_001A1F28(W3Sched *s)
{
    while (s->tail.prev != &s->head) {
        rcefTaskKill(s->tail.prev);
    }
}

void rcefTaskCtrlProc(W3Task *t)
{
    W3Task *first;
    W3Task *cur;

    first = t;
    for (; t != 0; t = t->next) {
        rcefTaskProc(t);
    }
    t = first;
    while (t != 0) {
        if (t->flags & 4) {
            cur = t;
            t = t->next;
            rcefTaskKill(cur);
        } else {
            t = t->next;
        }
    }
}

void func_001A1FF0(W3Task *t, W3Task *n) {
    int prio; /* DEBT(FAKE): temp only steers the loop entry */

    for (; t != 0; t = t->next) {
        prio = t->prio;
        if (n->prio < prio) {
            t->prev->next = n;
            n->prev = t->prev;
            t->prev = n;
            n->next = t;
            break;
        }
    }
}

int func_001A2040(W3Sched *s)
{
    return s->head.next == &s->tail;
}

void func_001A2058(W3Task *t)
{
    if (func_0029B830(D_00313CB4) == 0) {
        func_001A1DC0(t);
    }
}

void func_001A2098(W3Task *t)
{
    if (MsEffectMotionLevel(D_00313CB4) != 0) {
        func_001A1DC0(t);
    }
}

void func_001A20D8(W3Task *t)
{
    if (func_001A1400(t) != 0) {
        func_001A1DC0(t);
    }
}

void func_001A2110(W3Task *t)
{
    if (func_001A1410(t) != 0) {
        func_001A1DC0(t);
    }
}

void func_001A2148(W3Task *t)
{
    if (MsEffectCheckMotion(t->frame[t->sp].count) == -1) {
        func_001A1DC0(t);
    }
}

void func_001A2198(W3Task *t)
{
    if (func_001D4578(t->frame[t->sp].count) == 0) {
        func_001A1DC0(t);
    }
}
