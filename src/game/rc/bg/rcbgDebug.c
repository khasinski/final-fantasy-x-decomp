/* tu_148 0x190f20-0x193c80: medium; rcbgDebug (config/tu_map.tsv) */
#define func_00191BF0 _hdr_func_00191BF0
#define func_001921A8 _hdr_func_001921A8
#define func_001921B0 _hdr_func_001921B0
#define rcbgFpSaveSub _hdr_rcbgFpSaveSub
#define func_00191A70 _hdr_func_00191A70
#define rcbgIDLoad _hdr_rcbgIDLoad
#include "common.h"
#include "ffx/r2.h"
#include "ffx/q3.h"
#include "ffx/s2.h"
#include "ffx/t2.h"
#include "ffx/v2.h"
#include "ffx/w3.h"
#include "vu0.h"
#undef func_00191A70
#undef func_00191BF0
#undef func_001921A8
#undef func_001921B0
#undef rcbgFpSaveSub
#undef rcbgIDLoad

R2AnimFrame *func_00190F20(R2Anim *a) {
    u32 flags = a->flags;
    R2AnimFrame *frame;

    if (a->n == 0) {
        return 0;
    }
    frame = &a->frames[a->cur];
    if (!(flags & 1)) {
        a->frac += a->speed;
        if (a->frac >= 0x100) {
            a->time += a->frac / 256;
            a->frac = a->frac % 256;
            while (frame->time < a->time) {
                a->time -= frame->time + 1;
                if (!(flags & 2)) {
                    a->cur = a->cur + 1;
                    if (a->cur >= a->n) {
                        switch (flags & 0xF00) {
                        case 0:
                            a->cur = 0;
                            break;
                        case 0x100:
                            a->cur = a->n - 1;
                            break;
                        }
                    }
                } else {
                    a->cur = a->cur - 1;
                    if (a->cur < 0) {
                        switch (flags & 0xF00) {
                        case 0:
                            a->cur = a->n - 1;
                            break;
                        case 0x100:
                            a->cur = 0;
                            break;
                        }
                    }
                }
            }
        }
    }
    return frame;
}

R2AnimFrame *func_00191060(R2Anim *a, int i) {
    if (i < a->n) {
        return &a->frames[i];
    }
    return 0;
}

int *func_00191088(Q3Tab *t) {
    return &t->tab[t->idx];
}

void func_001910A0(void) {
    func_001921A8();
}

void func_001910A8(void) {
    func_001921B0();
}

void rcbgFpSaveSub(void)
{
}

void _m2c_func_001910B8_func_00194C18(int id) __asm__("func_00194C18");
extern s32 _m2c_func_001910B8_D_0056D640 __asm__("D_0056D640");
extern s32 _m2c_func_001910B8_D_0056D660 __asm__("D_0056D660");
extern s32 _m2c_func_001910B8_D_0056D688 __asm__("D_0056D688");
extern s32 _m2c_func_001910B8_D_0056D690 __asm__("D_0056D690");
void func_001910B8(void) {
    u8 sp[0x100];
    W3Pair *temp_2;
    W3Pair *temp_4;

    func_0018F5E8(&_m2c_func_001910B8_D_0056D640);
    func_002F0008(sp, &_m2c_func_001910B8_D_0056D660, func_0013A278());
    temp_4 = g_pMainWork->buf10;
    if (temp_4 != 0) {
        rcdtChunkDelete(temp_4);
        g_pMainWork->buf10 = 0;
    }
    temp_2 = rcdtChunkNew();
    if (rcdtChunkLoadFromFile(temp_2, sp) != 0) {
        func_0018F5E8(&_m2c_func_001910B8_D_0056D688, sp);
        _m2c_func_001910B8_func_00194C18(0x20006);
        _m2c_func_001910B8_func_00194C18(0x20005);
        func_00194C80(temp_2->ptr);
        g_pMainWork->buf10 = temp_2;
    } else if (temp_2 != 0) {
        rcdtChunkDelete(temp_2);
    }
    func_0018F5E8(&_m2c_func_001910B8_D_0056D690);
}

typedef struct R2DbgWorkFull {
    u8 pad0[0x34];
    int w34;
    int w38;
    int w3C;
    u8 pad40[8];
    int w48;
    int w4C;
    u8 pad50[0x174 - 0x50];
    char dir[0x828 - 0x174];
    int w828;
    u8 pad82C[0x874 - 0x82C];
    void *arr874[16];
    int w8B4;
    int w8B8;
    u8 pad8BC[0xAEC - 0x8BC];
    int wAEC;
    u8 padAF0[0xB14 - 0xAF0];
    int wB14;
} R2DbgWorkFull;

typedef struct DbgRegs6 {
    u64 r[6];
} DbgRegs6;

extern DbgRegs6 D_0056D780;
extern s32 D_0056D6A8;
extern s32 D_0056D6E0;
extern s32 D_0056D708;
extern s32 D_0056D730;
extern s32 D_0056D740;
extern s32 D_0056D760;
int func_2025BF0(int a, char *b);
void func_20233D0(void);
void func_00191388(void);
void func_001914C0(R2Pkt *pkt, void *item);
void func_001916D0(R2Pkt *pkt, void *item);
void func_00191920(R2Pkt *pkt, void *item);
void func_00191BF0(void);
void func_00191BF8(int a);
void func_00191ED0(void);
void func_001921B8(void);
void func_00192708(u64 *regs);
void func_001927F8(void);

void func_001911A0(void)
{
    char sp[0x100];
    char buf[0x10];
    W3Pair *chunk;

    if (func_2025BF0(func_0013A278(), buf) != 0) {
        func_002F0008(sp, &D_0056D6A8, buf[0], buf[1], buf[2], buf[3], buf);
        if (g_pMainWork->buf14 != 0) {
            func_0018F5E8(&D_0056D6E0, &D_0056D708, &D_0056D730, 0x93);
        }
        func_0018F5E8(&D_0056D740);
        chunk = rcdtChunkNew();
        if (rcdtChunkLoadFromFile(chunk, sp) != 0) {
            func_0018F5E8(&_m2c_func_001910B8_D_0056D688, sp);
            func_00194C80(chunk->ptr);
            g_pMainWork->buf14 = chunk;
            rcbgGuideSetModelFromIdMap(g_pMainWork->sub, W3_CORE()->pool->items[0]);
        } else if (chunk != 0) {
            rcdtChunkDelete(chunk);
        }
        func_0018F5E8(&D_0056D760);
    }
}

extern R2DbgWorkFull *D_02000088 __asm__("0x02000088");
#define R2_DBGWORK_FULL D_02000088
void func_002B2DF0(void *fn, int a1, int a2, int a3);

void func_001912B8(void)
{
    if (R2_DBGWORK_FULL == 0) {
        return;
    }
    func_001921B8();
    if (R2_DBGWORK_FULL->w3C != 0) {
        func_002B2DF0(func_00191388, 0, 0, 1);
    }
    if (R2_DBGWORK_FULL->w34 != 0) {
        func_002B2DF0(func_00191BF0, 0, 0, 1);
    }
    if (R2_DBGWORK_FULL->w48 != 0) {
        func_00191BF8(R2_DBGWORK_FULL->wAEC);
    }
    if (R2_DBGWORK_FULL->w4C != 0) {
        func_002B2DF0(func_00191ED0, 0, 0, 1);
    }
    if (R2_DBGWORK_FULL->wB14 != 0) {
        func_20233D0();
    }
}

void func_00191388(void)
{
    DbgRegs6 regs;
    R2Pkt pkt;
    R2DbgWorkFull *dbg;
    int i;
    void *item;

    dbg = R2_DBGWORK_FULL;
    regs = D_0056D780;
    regs.r[0] = 0x3000F;
    regs.r[2] = 0x44;
    func_00192708(regs.r);
    func_0018FCE0(&pkt);
    func_0018FD88(&pkt, (void *)D_00303550); /* DEBT(TYPE) */
    for (i = 0; i < dbg->w828; i++) {
        item = dbg->arr874[i];
        func_001914C0(&pkt, item);
        if (i == dbg->w8B4) {
            if (dbg->w8B8 == 0) {
                func_001916D0(&pkt, item);
            } else {
                func_00191920(&pkt, item);
            }
        }
    }
    func_0018FDD0(&pkt);
    func_0018FE28(&pkt);
    func_001927F8();
}

INCLUDE_ASM("build/ee_asm/game/rc/bg/rcbgDebug", func_001914C0);

INCLUDE_ASM("build/ee_asm/game/rc/bg/rcbgDebug", func_001916D0);

INCLUDE_ASM("build/ee_asm/game/rc/bg/rcbgDebug", func_00191920);

void _m2c_func_00191A70_func_00191A78() __asm__("func_00191A78");
void func_00191A70(s32 a0, s32 a1)
{
    _m2c_func_00191A70_func_00191A78(a0, a1, 1);
}

INCLUDE_ASM("build/ee_asm/game/rc/bg/rcbgDebug", func_00191A78);

void func_00191BF0(void)
{
}

INCLUDE_ASM("build/ee_asm/game/rc/bg/rcbgDebug", func_00191BF8);

INCLUDE_ASM("build/ee_asm/game/rc/bg/rcbgDebug", func_00191ED0);

void func_001921A8(void)
{
}

void func_001921B0(void)
{
}

void func_001921B8(void) {
}

void func_001921C0(void) {
}

void func_001921C8(void) {
}

void func_001921D0(void) {
}

void func_001921D8(void) {
}

void func_001921E0(float *m) {
    W3Core *core;
    W3Pool *pool;

    if (g_pMainWork != 0) {
        V2_POOL(core, pool);
    } else {
        pool = 0;
    }
    func_0018F260(m, pool->fFC, pool->fFC, pool->fFC);
}

extern void func_001ACB48(float ang, void *out, float *eye, float *tgt, void *up);

void rcbgSetViewMatrix(void *out, float *eye, float *tgt, void *up, float ang)
{
    W3Core *core;
    W3Pool *pool;
    float e[4];
    float t[4];
    float *tp;
    int s;

    if (g_pMainWork != 0) {
        V2_POOL(core, pool);
    } else {
        pool = 0;
    }
    s = *(int *)&pool->fFC; /* DEBT(CAST): the scale is moved as raw bits */
    VU0_LQC2(31, 0, eye);
    VU0_QMTC2_NI(30, s);
    VU0_OP("vmulx.xyz $vf31, $vf31, $vf30x");
    VU0_SQC2(31, 0, e);
    tp = t;
    VU0_LQC2(31, 0, tgt);
    VU0_QMTC2_NI(30, s);
    VU0_OP("vmulx.xyz $vf31, $vf31, $vf30x");
    VU0_SQC2(31, 0, tp);
    func_001ACB48(ang, out, e, tp, up);
}

s32 _m2c_rcbgSetProjectionMatrixSub(s32, s32, s32, float, float, float) __asm__("rcbgSetProjectionMatrixSub");
s32 func_00192280(s32 arg0, float arg1) {
    return _m2c_rcbgSetProjectionMatrixSub(arg0, 1, 0, arg1, 0.0f, 0.0f);
}

INCLUDE_ASM("build/ee_asm/game/rc/bg/rcbgDebug", rcbgSetProjectionMatrixSub);

u32 func_00192458(float z)
{
    W3Core *core;
    W3Pool *pool;
    float v[4];

    if (g_pMainWork != 0) {
        V2_POOL(core, pool);
    } else {
        pool = 0;
    }
    if (pool != 0) {
        v[0] = 0;
        v[1] = 0;
        v[2] = z * pool->fFC;
        v[3] = 1.0f;
    } else {
        v[0] = 0;
        v[1] = 0;
        v[2] = z * 10.0f;
        v[3] = 1.0f;
    }
    func_002DCE08(v, D_00314260, v);
    return (u32)(v[2] / v[3]);
}

int func_00192508(float z)
{
    W3Core *core;
    W3Pool *pool;
    float v[4];
    int out[4];

    if (g_pMainWork != 0) {
        V2_POOL(core, pool);
    } else {
        pool = 0;
    }
    if (pool != 0) {
        v[0] = 0;
        v[1] = 0;
        v[2] = z * pool->fFC;
        v[3] = 1.0f;
    } else {
        v[0] = 0;
        v[1] = 0;
        v[2] = z * 10.0f;
        v[3] = 1.0f;
    }
    func_002DCE08(v, D_00314260, v);
    v[2] = v[2] / v[3];
    func_002DD0E8(out, v);
    return out[2] / 0x3000;
}

void func_001925D8(void *a, void *b) {
    func_002DCE38(a, D_003142A0, b);
    func_002DCE38(a, D_00314260, a);
}

void func_00192618(u32 a0)
{
    __asm__ volatile(
        "lui        $3, (0x42C80000 >> 16)\n"
        "lqc2       $vf31, 0x0($4)\n"
        "qmtc2.ni   $3, $vf30\n"
        "vmulx.xyz  $vf31, $vf31, $vf30x\n"
        "sqc2       $vf31, 0x0($4)\n"
        "addiu      $2, $4, 0x10\n"
        "lqc2       $vf31, 0x0($2)\n"
        "qmtc2.ni   $3, $vf30\n"
        "vmulx.xyz  $vf31, $vf31, $vf30x\n"
        "sqc2       $vf31, 0x0($2)\n"
        "addiu      $4, $4, 0x20\n"
        "lqc2       $vf31, 0x0($4)\n"
        "qmtc2.ni   $3, $vf30\n"
        "vmulx.xyz  $vf31, $vf31, $vf30x\n"
        "sqc2       $vf31, 0x0($4)\n"
        "nop\n"
        : "+r"(a0) :  : "$2", "$3");
}

void rcCalcTex0Prm(int w, int h, int *tw, int *th, int *tbw) {
    if (tw != 0) {
        *tw = rcLog2(w);
    }
    if (th != 0) {
        *th = rcLog2(h);
    }
    if (tbw != 0) {
        *tbw = (w + 63) / 64;
        if (*tbw & 1) {
            *tbw = *tbw + 1;
        }
    }
}

void func_00192708(u64 *regs) {
    int n;
    int i;
    R2Qw *q;
    R2Pkt pkt;

    /* regs: (data, address) pairs for A+D, ended by address -1 */
    n = 0;
    for (i = 1; regs[i] != -1; i += 2) {
        n++;
    }
    func_0018FCE0(&pkt);
    func_0018FD88(&pkt, (void *)D_00303550); /* DEBT(TYPE): D_00303550 holds a buffer address but is declared s32 */
    q = pkt.cur;
    q->d.lo = n | (u64)1 << 60;
    q->d.hi = 0xE;
    q++;
    for (i = 0; i < n; i++) {
        q->d.lo = regs[i * 2];
        q->d.hi = regs[i * 2 + 1];
        q++;
    }
    pkt.cur = q;
    func_0018FDD0(&pkt);
    func_0018FE28(&pkt);
}

void func_001927F8(void) {
    R2Pkt pkt;
    R2Qw *q;

    func_0018FCE0(&pkt);
    func_0018FD88(&pkt, (void *)D_00303550); /* DEBT(TYPE): D_00303550 holds a buffer address but is declared s32 */
    q = pkt.cur;
    q = func_00192848(q);
    pkt.cur = q;
    func_0018FDD0(&pkt);
    func_0018FE28(&pkt);
}

R2Qw *func_00192848(R2Qw *p) {
    p->d.lo = 4 | (u64)1 << 60;
    p->d.hi = 0xE;
    p++;
    p->d.lo = D_006F2CE0.r30.data;
    p->d.hi = D_006F2CE0.r30.addr;
    p++;
    p->d.lo = D_006F2CE0.r60.data;
    p->d.hi = D_006F2CE0.r60.addr;
    p++;
    p->d.lo = D_006F2CE0.r70.data;
    p->d.hi = D_006F2CE0.r70.addr;
    p++;
    p->d.lo = D_006F2CE0.r80.data;
    p->d.hi = D_006F2CE0.r80.addr;
    return p + 1;
}

int func_001928C0(void) {
    return 0;
}

int rcbgIDLoad(void)
{
    char path[0x100];
    int fd;
    int size;
    int ptr;

    ptr = 0;
    func_002F0008(path, D_0056D7F8, R2_DBGWORK_FULL->dir);
    fd = func_002FC4E0(path, 1);
    if (fd >= 0) {
        size = func_002FC8E8(fd, 0, 2);
        func_002FC8E8(fd, 0, 0);
        ptr = func_0011D678(size);
        func_002FCB20(fd, (void *)ptr, size); /* DEBT(CAST) */
        func_002FC768(fd);
        Sg_MapSetPtr(ptr);
        Ch_EnMapID((Chr *)Sg_GetPlayer(), 1); /* DEBT(CAST) */
    }
    return ptr;
}

void func_00192990(W3Voice *v)
{
    func_002EF0D0(v, 0, 0xC0);
    func_00190E38((R2Anim *)&v->sub90); /* DEBT(CAST): W3Voice.sub90 is the R2Anim block of t2.h */
    func_00198870(&v->subB0);
    v->i2C = v->i30 = 0x100;
    v->d38 = 0x44;
    v->rgba[0] = v->rgba[1] = v->rgba[2] = v->b43 = 0x80;
    v->f44 = v->f48 = 1.0f;
}

void rcbgLayerFini(W3Voice *v) {
    /* DEBT(TYPE): W3Voice.sub90 is really an R2Anim block */
    if (((R2Anim *)&v->sub90)->img != 0) {
        func_00199F18(((R2Anim *)&v->sub90)->img);
        ((R2Anim *)&v->sub90)->img = 0;
    }
    if (v->subB0.img != 0) {
        func_00199F18(v->subB0.img);
        v->subB0.img = 0;
    }
    func_00190E70((R2Anim *)&v->sub90);
    func_00198880(&v->subB0);
}

void func_00192A68(W3Voice *v)
{
    R2Anim *anim = (R2Anim *)&v->sub90; /* DEBT(CAST): W3Voice.sub90 is the R2Anim block of t2.h */
    R2AnimFrame *fr;

    fr = func_00190F20(anim);
    if (fr != 0) {
        func_0019A1A0(anim->img, fr->cell);
        func_00198CA8(&v->subB0, fr->cell);
    }
    func_00198908(&v->subB0);
    func_00192AD8(v);
}

void func_00192AD8(W3Voice *v)
{
    float t;

    if (v->i74 != 0) {
        v->i78++;
        t = (float)v->i78 / v->i74;
        v->f44 = v->f54 + (v->f58 - v->f54) * t;
        v->f48 = v->f5C + (v->f60 - v->f5C) * t;
        if (v->i78 >= v->i74) {
            v->i74 = 0;
        }
    }
    if (v->i7C != 0) {
        v->i80++;
        t = (float)v->i80 / v->i7C;
        v->f4C = v->f64 + (v->f68 - v->f64) * t;
        v->f50 = v->f6C + (v->f70 - v->f6C) * t;
        if (v->i80 >= v->i7C) {
            v->i7C = 0;
        }
    }
}

INCLUDE_ASM("build/ee_asm/game/rc/bg/rcbgDebug", func_00192BC0);

INCLUDE_ASM("build/ee_asm/game/rc/bg/rcbgDebug", func_00192E00);

INCLUDE_ASM("build/ee_asm/game/rc/bg/rcbgDebug", func_00193110);

INCLUDE_ASM("build/ee_asm/game/rc/bg/rcbgDebug", func_001933D0);

INCLUDE_ASM("build/ee_asm/game/rc/bg/rcbgDebug", func_00193728);
