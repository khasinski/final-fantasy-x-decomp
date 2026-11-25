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
#include "ffx/w6.h"
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
    u8 padAF0[0];
    int wAF0;
    int wAF4;
    int wAF8;
    int wAFC;
    int wB00;
    int wB04;
    int wB08;
    int wB0C;
    int wB10;
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

extern u8 D_003135C0[][0x10];
void func_00192618(u32);
void func_001925D8(void *, void *);
void func_002DCE08(void *, void *, void *);
void func_002DCFD8(void *, void *, float);
void func_0018FE80(void *, void *, float, float, float, float);
void func_00190120(void *, void *, float, float, float, float);
void func_00190230(void *, void *, int, void *, void *);
void func_00191A70(s32 a0, s32 a1);

typedef struct DbgAng4 {
    u32 a[4];
} DbgAng4;
typedef struct DbgVec4 {
    float x;
    float y;
    float z;
    float w;
} DbgVec4;
extern DbgAng4 D_0056D7B0;
extern float eff_sin_t[];

void func_001914C0(R2Pkt *pkt, void *item)
{
    DbgAng4 angs = D_0056D7B0;
    float mtx[16];
    DbgVec4 verts[33];
    R2DbgWorkFull *dbg = R2_DBGWORK_FULL;
    float r;
    int i;
    int col;

    Ch_GetRootGlobalMatrix(item, mtx);
    func_00192618((u32)mtx);
    r = func_001109E0(item) * 10.0f;
    func_002EF0D0(verts, 0, sizeof(verts));
    {
        u32 *ap = angs.a;
        DbgVec4 *v = verts;
        for (i = 0; i < 4; i++, ap++, v++) {
            u32 a = *ap;
            v->x = eff_sin_t[(a >> 4) & 0xFFF] * r;
            v->z = -eff_sin_t[((a + 0x4000) >> 4) & 0xFFF] * r;
        }
    }
    VU0_LQC2(31, 0, &verts[0]);
    VU0_SQC2(31, 0, &verts[4]);
    verts[2].x = verts[2].y = verts[2].z = verts[2].w = 0.0f;
    col = (dbg->arr874[dbg->w8B4] == item) ? 1 : 6;
    func_00190230(pkt, verts, 5, D_003135C0[col], mtx);
    {
        DbgVec4 *v;
        u32 ang2;
        for (i = 0, ang2 = 0x4000, v = verts; i < 33; i++, ang2 += 0x800, v++) {
            u32 a = i * 0x800;
            v->x = eff_sin_t[(a >> 4) & 0xFFF] * r;
            v->z = -eff_sin_t[(ang2 >> 4) & 0xFFF] * r;
        }
    }
    func_00190230(pkt, verts, 33, D_003135C0[col], mtx);
}

void func_001916D0(R2Pkt *pkt, void *item)
{
    float sp00[16];
    float sp40[16];
    u8 *s3 = (u8 *)R2_DBGWORK_FULL;
    int s5, s4;
    u8 *s6;
    int i;
    int col;

    if (*(s32 *)(s3 + 0x8C0) != 0) {
        s4 = *(s32 *)(s3 + 0x8C8);
        s5 = s4;
    } else {
        int n = *(s32 *)(s3 + 0x8BC);
        int last = n - 1;
        s5 = *(s32 *)(s3 + 0x8C4);
        s4 = s5 + 9;
        if (s4 >= n) {
            s4 = last;
        }
    }
    s6 = *(u8 **)(s3 + 0x8CC);
    for (i = 0; i < *(s32 *)(s3 + 0x8BC); i++) {
        float *v;
        func_001072F8(item, i, sp40);
        func_00192618((u32)sp40);
        func_001925D8(sp00, sp40);
        v = (float *)((u32)(i << 4) + (u32)s6);
        VU0_SQC2(0, 0, v);
        func_002DCE08(v, sp00, v);
        func_002DCFD8(v, v, v[3]);
    }
    for (i = 0; i < *(s32 *)(s3 + 0x8BC); i++) {
        int par = Ch_ElemGetParent(item, i);
        if (par != -1) {
            if ((i >= s5 && i <= s4) || (par >= s5 && par <= s4)) {
                col = 5;
            } else {
                col = 6;
            }
            func_00190120(pkt, D_003135C0[col], ((float (*)[4])s6)[i][0], ((float (*)[4])s6)[i][1], ((float (*)[4])s6)[par][0], ((float (*)[4])s6)[par][1]);
        }
    }
    for (i = 0; i < *(s32 *)(s3 + 0x8BC); i++) {
        if (i >= s5 && i <= s4) {
            col = 1;
        } else {
            col = 6;
        }
        func_0018FE80(pkt, D_003135C0[col], ((float (*)[4])s6)[i][0], ((float (*)[4])s6)[i][1], 4.0f, 14.0f / 3.0f);
    }
    if (*(s32 *)(s3 + 0x8C0) != 0) {
        func_001072F8(item, *(s32 *)(s3 + 0x8C8), sp40);
        func_00192618((u32)sp40);
        func_00191A70((s32)pkt, (s32)sp40);
    }
}

void func_00191920(R2Pkt *a0, void *a1)
{
    float sp00[16];
    float sp40[16];
    float sp80[4];
    u8 *s3 = (u8 *)R2_DBGWORK_FULL;
    int i;

    for (i = 0; i < *(s32 *)(s3 + 0x8D0); i++) {
        int col;
        func_001089E0(a1, i, 0, sp40);
        func_00192618((u32)sp40);
        func_001925D8(sp00, sp40);
        VU0_SQC2(0, 0, sp80);
        func_002DCE08(sp80, sp00, sp80);
        func_002DCFD8(sp80, sp80, sp80[3]);
        col = (i == *(s32 *)(s3 + 0x8D4)) ? 1 : 6;
        func_0018FE80(a0, D_003135C0[col], sp80[0], sp80[1], 4.0f, 14.0f / 3.0f);
    }
    func_001089E0(a1, *(s32 *)(s3 + 0x8D4), 0, sp40);
    func_00192618((u32)sp40);
    func_00191A70((s32)a0, (s32)sp40);
}

void _m2c_func_00191A70_func_00191A78() __asm__("func_00191A78");
void func_00191A70(s32 a0, s32 a1)
{
    _m2c_func_00191A70_func_00191A78(a0, a1, 1);
}

INCLUDE_ASM("build/ee_asm/game/rc/bg/rcbgDebug", func_00191A78);

void func_00191BF0(void)
{
}

u32 func_00192458(float z);
void rcCalcTex0Prm(int w, int h, int *tw, int *th, int *tbw);
R2Qw *func_0019A1F8(W3Img *img, R2Qw *p);
void func_002B2AD8(void *p, int qwc, int a, int b);
R2Qw *func_001933D0(R2Qw *q, float *rect, float *zp, float ang, float sx, float sy);
R2Qw *func_00193728(R2Qw *q, float *rect, float *zp, float ang, float sx, float sy);

typedef struct DbgPsm13 {
    u32 v[13];
} DbgPsm13;

extern DbgPsm13 D_0056D7C0;

void func_00191BF8(int idx)
{
    W3Core *core;
    W3Pool *pool;
    u32 z;
    W3Voice *v;
    int tw;
    int th;
    int tbw;
    R2Pkt pkt;
    R2Qw *q;

    core = (g_pMainWork != 0) ? g_pMainWork->core : 0;
    z = func_00192458(0.1f);
    if (core == 0) {
        return;
    }
    pool = 0;
    if (g_pMainWork != 0) {
        V2_POOL(core, pool);
    }
    v = &pool->voices[idx];
    rcCalcTex0Prm(v->i04, v->i08, &tw, &th, &tbw);
    func_0019A1A0(((R2Anim *)&v->sub90)->img, 0);
    func_00198CA8(&v->subB0, 0);
    func_0018FCE0(&pkt);
    func_0018FD88(&pkt, (void *)D_00303550);
    q = pkt.cur;
    q->d.lo = 7 | ((u64)1 << 60);
    q->d.hi = 0xE;
    q++;
    q->d.hi = 0x3F;
    q++;
    q->d.lo = SCE_GS_SET_TEX0(0x3C00, tbw, 0x13, tw, th, 1, 0, 0x2E00, 0, 0, 0, 1);
    q->d.hi = 0x6;
    q++;
    q->d.lo = v->d38;
    q->d.hi = 0x42;
    q++;
    q->d.lo = v->rgba[0] | ((u64)v->rgba[1] << 8) | ((u64)v->rgba[2] << 16) | ((u64)v->b43 << 24);
    q->d.hi = 0x1;
    q++;
    q->d.lo = SCE_GS_SET_CLAMP(2, 2, v->i24, v->i24 + v->i04 - 1, v->i28, v->i28 + v->i08 - 1);
    q->d.hi = 0x8;
    q++;
    q->d.lo = 0x60;
    q->d.hi = 0x14;
    q++;
    q->d.lo = 0x30000;
    q->d.hi = 0x47;
    q++;
    {
        int w = v->i04;
        int h = v->i08;

        q->d.lo = 0x408B400000000001ULL;
        q->d.hi = 0x5353;
        q++;
        q->w[0] = 0;
        q->w[1] = 0;
        q++;
        q->w[0] = 0x6FF8;
        q->w[1] = 0x7378;
        q->w[2] = z;
        q->w[3] = 0;
        q++;
        q->w[0] = w << 4;
        q->w[1] = h << 4;
        q++;
        q->w[0] = (w << 3) + 0x6FF8;
        q->w[1] = (h << 3) + 0x7378;
        q->w[2] = z;
        q->w[3] = 0;
        q++;
    }
    pkt.cur = q;
    func_0018FDD0(&pkt);
    func_0018FE28(&pkt);
}

void func_00191ED0(void)
{
    R2DbgWorkFull *dbg;
    DbgPsm13 psm;
    u32 z;
    R2Pkt pkt;
    u8 pad[0x10];
    R2Qw *q;
    int sw;
    int sh;
    int w;
    int h;
    int x0;
    int y0;

    dbg = R2_DBGWORK_FULL;
    psm = D_0056D7C0;
    z = func_00192458(0.1f);
    func_0018FCE0(&pkt);
    func_0018FD88(&pkt, (void *)D_00303550);
    q = pkt.cur;
    q->d.lo = 5 | ((u64)1 << 60);
    q->d.hi = 0xE;
    q++;
    q->d.hi = 0x3F;
    q++;
    q->d.lo = SCE_GS_SET_TEX0(
        *(s32 *)((u8 *)dbg + 0xAF0),
        *(s32 *)((u8 *)dbg + 0xAF4),
        psm.v[*(s32 *)((u8 *)dbg + 0xAF8)],
        *(s32 *)((u8 *)dbg + 0xAFC),
        *(s32 *)((u8 *)dbg + 0xB00),
        1, 0,
        *(s32 *)((u8 *)dbg + 0xB04),
        0, 0, 0, 1);
    q->d.hi = 0x6;
    q++;
    q->d.lo = 0x44;
    q->d.hi = 0x42;
    q++;
    q->d.lo = 0x80808080;
    q->d.hi = 0x1;
    q++;
    q->d.lo = 0x30003;
    q->d.hi = 0x47;
    q++;
    sh = 0;
    sw = 0;
    switch (*(s32 *)((u8 *)dbg + 0xB10)) {
    case 0:
        sw = *(s32 *)((u8 *)dbg + 0xB08) << 4;
        sh = *(s32 *)((u8 *)dbg + 0xB0C) << 4;
        break;
    case 1:
        sw = (*(s32 *)((u8 *)dbg + 0xB08) << 4) + (*(s32 *)((u8 *)dbg + 0xB08) << 3);
        sh = (*(s32 *)((u8 *)dbg + 0xB0C) << 4) + (*(s32 *)((u8 *)dbg + 0xB0C) << 3);
        break;
    case 2:
        sw = *(s32 *)((u8 *)dbg + 0xB08) << 5;
        sh = *(s32 *)((u8 *)dbg + 0xB0C) << 5;
        break;
    }
    w = *(s32 *)((u8 *)dbg + 0xB08);
    h = *(s32 *)((u8 *)dbg + 0xB0C);
    {
        int uw;
        int uh;

        q->d.lo = 0x408B400000000001ULL;
        q->d.hi = 0x5353;
        q++;
        q->w[0] = 0;
        q->w[1] = 0;
        q++;
        x0 = 0x7FF8 - (sw >> 1);
        y0 = 0x7FF8 - (sh >> 1);
        q->w[0] = x0;
        q->w[1] = y0;
        q->w[2] = z;
        q->w[3] = 0;
        q++;
        {
            register int uw __asm__("$4") = w << 4;
            register int uh __asm__("$5") = h << 4;
            int x1 = x0 + sw;
            int y1 = y0 + sh;

            q->w[0] = uw;
            q->w[1] = uh;
            __asm__ volatile("" : : "r"(w), "r"(h));
            {
                register R2Pkt *pktp __asm__("$4") = &pkt;
                __asm__ volatile("" : "+r"(pktp));
                q++;
                q->w[0] = x1;
                q->w[1] = y1;
                q->w[2] = z;
                q->w[3] = 0;
                q++;
                pkt.cur = q;
                func_0018FDD0(pktp);
            }
        }
    }
    func_0018FE28(&pkt);
}

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

void func_002DD610(void *a, float f0, float f1, float f2, float f3, float f4, float f5, float f6, float f7, float f8);

float rcbgSetProjectionMatrixSub(void *out, int a1, float fov, float *out_f, float ox, float oy)
{
    Rec142F0 *scr = &ms_screen[0];
    int flag = 0;
    W3Core *core;
    W3Pool *pool;
    float t;
    float d;
    float dy;

    core = (g_pMainWork != 0) ? g_pMainWork->core : 0;
    if (core != 0) {
        if (g_pMainWork != 0) {
            V2_POOL(core, pool);
        } else {
            pool = 0;
        }
        if (pool != 0) {
            flag = *(int *)&pool->pad100[4];
        }
    }
    t = func_002E8AB0(fov * 0.5f * (3.14159265f / 180.0f));
    d = 512.0f / ((scr->f1C + scr->f1C) * t);
    dy = d * (7.0f / 6.0f);
    if (flag != 0) {
        func_002DD610(out, scr->f1C, d, dy, ((float *)scr->pad20)[0] + ox, ((float *)scr->pad20)[1] + oy, ((float *)scr->pad0)[0], ((float *)scr->pad0)[1], scr->f08 * 10.0f, scr->f0C * 65536.0f * 2.0f);
    } else {
        func_002DD610(out, scr->f1C, d, dy, ((float *)scr->pad20)[0] + ox, ((float *)scr->pad20)[1] + oy, ((float *)scr->pad0)[0], ((float *)scr->pad0)[1], scr->f08, scr->f0C);
    }
    {
        float res = 256.0f / t;
        if (out_f != 0) {
            *out_f = res;
        }
    }
    return d;
}

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

u64 func_002EA358(float x);

INCLUDE_ASM("build/ee_asm/game/rc/bg/rcbgDebug", func_00192BC0);

void func_002F8660(int a);

void func_00192E00(W3Voice *v, W3Pool *pool, float *rect)
{
    int tw;
    int th;
    int tbw;
    u32 flags = *(u32 *)v;
    int b5;
    int b2;
    W3Img *img1;
    W3Img *img2;
    R2Qw *base;
    R2Qw *q;
    u64 tex0;
    u64 clamp;
    int minu;
    int minv;
    void *ch;

    if ((flags & 3) != 0) {
        return;
    }
    b2 = (s32)flags >> 2;
    b5 = (s32)flags >> 5;
    img1 = ((R2Anim *)&v->sub90)->img;
    img2 = v->subB0.img;
    rcCalcTex0Prm(v->i04, v->i08, &tw, &th, &tbw);
    b5 &= 1;
    *(u64 *)((u8 *)img1 + 0x18) = 0x13003C0000000000ULL | ((u64)tbw << 48);
    *(u64 *)((u8 *)img2 + 0x18) = 0x00012E0000000000ULL;
    tex0 = SCE_GS_SET_TEX0(0x3C00, tbw, 0x13, tw, th, 1, 0, 0x2E00, 0, 0, 0, 1);
    b2 &= 1;
    base = func_0019A1F8(img1, *(R2Qw **)((u8 *)pool + 0x114));
    base = func_0019A1F8(img2, base);
    q = base + 1;
    minu = (int)rect[4];
    minv = (int)rect[5];
    q->d.lo = 6 | ((u64)1 << 60);
    q->d.hi = 0xE;
    q++;
    q->d.hi = 0x3F;
    q++;
    q->d.lo = tex0;
    q->d.hi = 6;
    q++;
    if (minu < 0) {
        minu = 0;
    }
    if (minv < 0) {
        minv = 0;
    }
    q->d.lo = v->d38;
    q->d.hi = 0x42;
    q++;
    q->d.lo = (u64)v->rgba[0] | ((u64)v->rgba[1] << 8) | ((u64)v->rgba[2] << 16) | ((u64)v->b43 << 24);
    q->d.hi = 1;
    q++;
    clamp = (u64)minu << 4;
    {
        float h = rect[7];
        clamp |= func_002EA358(rect[5] + h - 1.0f) << 34;
    }
    {
        float w = rect[6];
        u64 t = func_002EA358(rect[4] + w - 1.0f);
        register u64 ten __asm__("$3") = 0xA;
        __asm__ volatile("" : "+r"(ten));
        t = (t << 14) | ten;
        clamp |= t;
        __asm__ volatile("" : "+r"(clamp));
        clamp |= (u64)minv << 24;
        __asm__ volatile("" : "+r"(clamp));
    }
    {
        register u64 r8 __asm__("$2") = 8;
        u64 b5s;
        __asm__ volatile("" : "+r"(r8));
        q->d.lo = clamp;
        b5s = (u64)b5 << 32;
        __asm__ volatile("" : "+r"(b5s));
        q->d.hi = r8;
        q++;
        q->d.lo = 0x31000108ULL | b5s;
        q->d.hi = 0x4E;
        q++;
    }
    if (b2 == 0) {
        q = func_001933D0(q, rect, (float *)((u8 *)v + 0x14), *(float *)((u8 *)pool + 0xB4), *(float *)((u8 *)pool + 0xB8), *(float *)((u8 *)pool + 0xBC));
    } else {
        q = func_00193728(q, rect, (float *)((u8 *)v + 0x14), *(float *)((u8 *)pool + 0xB4), *(float *)((u8 *)pool + 0xB8), *(float *)((u8 *)pool + 0xBC));
    }
    q->d.lo = 0x8000 | ((u64)1 << 60);
    q->d.hi = 0;
    q++;
    *(u_long128 *)base = 0;
    base->w[0] = (((u32)((u8 *)q - (u8 *)base) >> 4) - 1) | 0x70000000;
    ch = func_002DB6D8(2);
    func_002F8660(0);
    func_002DBA28(ch, *(void **)((u8 *)pool + 0x114));
    func_002DBF78(ch, 0, 0);
    *(R2Qw **)((u8 *)pool + 0x114) = q;
}

void func_00193110(W3Voice *v, W3Pool *pool, float *rect)
{
    int tw;
    int th;
    int tbw;
    u32 flags = *(u32 *)v;
    int b5;
    int b2;
    R2Qw *base;
    R2Qw *q;
    u64 tex0;
    u64 clamp;
    u32 qwc;

    if ((flags & 3) != 0) {
        return;
    }
    b2 = (s32)flags >> 2;
    b5 = (s32)flags >> 5;
    rcCalcTex0Prm(*(s32 *)((u8 *)v + 4), *(s32 *)((u8 *)v + 8), &tw, &th, &tbw);
    b5 &= 1;
    tex0 = (u64)*(u16 *)((u8 *)v + 0x34)
        | ((u64)tbw << 14)
        | (0x1BULL << 20)
        | ((u64)tw << 26)
        | ((u64)th << 30)
        | (1ULL << 34)
        | ((u64)*(u16 *)((u8 *)v + 0x36) << 37)
        | (1ULL << 61);
    base = *(R2Qw **)((u8 *)pool + 0x114);
    q = base + 1;
    q->d.lo = 7 | ((u64)1 << 60);
    q->d.hi = 0xE;
    q++;
    q->d.lo = tex0;
    q->d.hi = 6;
    q++;
    b2 &= 1;
    q->d.lo = v->d38;
    q->d.hi = 0x42;
    q++;
    q->d.lo = (u64)v->rgba[0] | ((u64)v->rgba[1] << 8) | ((u64)v->rgba[2] << 16) | ((u64)v->b43 << 24);
    q->d.hi = 1;
    q++;
    clamp = func_002EA358(rect[4]) << 4;
    {
        float h = rect[3];
        clamp |= func_002EA358(rect[5] + h - 1.0f) << 34;
    }
    {
        float w = rect[2];
        u64 t = func_002EA358(rect[4] + w - 1.0f) << 14;
        u64 ten = 0xA;
        float v5;
        __asm__ volatile("" : "+r"(ten));
        v5 = rect[5];
        __asm__ volatile("" : "+f"(v5));
        t |= ten;
        clamp |= t;
        clamp |= func_002EA358(v5) << 24;
    }
    q->d.lo = clamp;
    q->d.hi = 8;
    q++;
    q->d.lo = 0x31000108ULL | ((u64)b5 << 32);
    q->d.hi = 0x4E;
    q++;
    q->d.lo = 0x60;
    q->d.hi = 0x14;
    q++;
    q->d.lo = 0x5000F;
    q->d.hi = 0x47;
    q++;
    if (b2 == 0) {
        q = func_001933D0(q, rect, (float *)((u8 *)v + 0x14), *(float *)((u8 *)pool + 0xB4), *(float *)((u8 *)pool + 0xB8), *(float *)((u8 *)pool + 0xBC));
    } else {
        q = func_00193728(q, rect, (float *)((u8 *)v + 0x14), *(float *)((u8 *)pool + 0xB4), *(float *)((u8 *)pool + 0xB8), *(float *)((u8 *)pool + 0xBC));
    }
    q = func_00192848(q);
    q->d.lo = 0x8000 | ((u64)1 << 60);
    q->d.hi = 0;
    q++;
    *(u_long128 *)base = 0;
    qwc = (u32)((u8 *)q - (u8 *)base) >> 4;
    base->w[0] = qwc | 0x70000000;
    func_002B2AD8(base, qwc, func_00192508(*(float *)((u8 *)v + 0x14)), 0);
    *(R2Qw **)((u8 *)pool + 0x114) = q;
}

R2Qw *func_001933D0(R2Qw *q, float *rect, float *zp, float ang, float sx, float sy)
{
    float fv[4];
    int iv[4];
    float c;
    float s;
    float s_yx;
    float s_xy;
    float x0;
    float y0;
    float x1;
    float y1;
    float u0;
    float v0;
    float u1;
    float v1;
    u32 z;

    fv[2] = fv[3] = 0.0f;
    iv[3] = 0;
    iv[2] = 0;
    c = func_002E8648(ang);
    s = func_002E89C0(ang);
    {
        float r2 = sx / sy;
        float r1 = sy / sx;
        s_xy = s * r2;
        s_yx = s * r1;
    }
    x0 = rect[0] - 256.0f;
    y0 = rect[1] - 208.0f;
    x1 = x0 + rect[2];
    y1 = y0 + rect[3];
    u0 = rect[4];
    v0 = rect[5];
    u1 = u0 + rect[6];
    v1 = v0 + rect[7];
    z = func_00192458(*zp);
    q->d.lo = 0x80AA400000000001ULL;
    q->d.hi = 0x53535353ULL;
    q++;

    fv[0] = u0;
    fv[1] = v0;
    func_002DD0E8(iv, fv);
    q->w[0] = iv[0];
    q->w[1] = iv[1];
    q++;
    fv[0] = x0 * c - y0 * s_xy;
    fv[1] = y0 * c + x0 * s_yx;
    func_002DD0E8(iv, fv);
    iv[0] += 0x7FF8;
    iv[1] += 0x7FF8;
    q->w[0] = iv[0];
    q->w[1] = iv[1];
    q->w[2] = z;
    q->w[3] = 0;
    q++;

    fv[0] = u0;
    fv[1] = v1;
    func_002DD0E8(iv, fv);
    q->w[0] = iv[0];
    q->w[1] = iv[1];
    q++;
    fv[0] = x0 * c - y1 * s_xy;
    fv[1] = y1 * c + x0 * s_yx;
    func_002DD0E8(iv, fv);
    iv[0] += 0x7FF8;
    iv[1] += 0x7FF8;
    q->w[0] = iv[0];
    q->w[1] = iv[1];
    q->w[2] = z;
    q->w[3] = 0;
    q++;

    fv[0] = u1;
    fv[1] = v0;
    func_002DD0E8(iv, fv);
    q->w[0] = iv[0];
    q->w[1] = iv[1];
    q++;
    fv[0] = x1 * c - y0 * s_xy;
    fv[1] = y0 * c + x1 * s_yx;
    func_002DD0E8(iv, fv);
    iv[0] += 0x7FF8;
    iv[1] += 0x7FF8;
    q->w[0] = iv[0];
    q->w[1] = iv[1];
    q->w[2] = z;
    q->w[3] = 0;
    q++;

    fv[0] = u1;
    fv[1] = v1;
    func_002DD0E8(iv, fv);
    q->w[0] = iv[0];
    q->w[1] = iv[1];
    q++;
    fv[0] = x1 * c - y1 * s_xy;
    fv[1] = y1 * c + x1 * s_yx;
    func_002DD0E8(iv, fv);
    iv[0] += 0x7FF8;
    iv[1] += 0x7FF8;
    q->w[0] = iv[0];
    q->w[1] = iv[1];
    q->w[2] = z;
    q->w[3] = 0;
    q++;

    return q;
}

INCLUDE_ASM("build/ee_asm/game/rc/bg/rcbgDebug", func_00193728);
