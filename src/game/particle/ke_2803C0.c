/* tu_306 0x2803c0-0x2856f0: low; ~KeThBP_Update (config/tu_map.tsv) */
/* Module guess: event-script VM / field-event runtime (no __FILE__ string found for this range). */
#include "common.h"
#include "vu0.h"
#include "ffx/r6.h"
#include "ffx/w9.h"
#include "ffx/q6.h"
#include "ffx/u4.h"
#include "ffx/t6.h"
#include "ffx/v6.h"

void func_002803C0(LinkOwner *owner, int flags) {
    LinkNode *n;

    flags |= 8;
    for (n = owner->head; n != 0; n = n->next) {
        n->wC = 0;
        n->h3E |= flags;
    }
}

INCLUDE_ASM("build/ee_asm/game/particle/ke_2803C0", func_002803F8);

INCLUDE_ASM("build/ee_asm/game/particle/ke_2803C0", func_00280860);

INCLUDE_ASM("build/ee_asm/game/particle/ke_2803C0", func_00280D28);

INCLUDE_ASM("build/ee_asm/game/particle/ke_2803C0", func_00280F90);

INCLUDE_ASM("build/ee_asm/game/particle/ke_2803C0", func_00280FD0);

INCLUDE_ASM("build/ee_asm/game/particle/ke_2803C0", func_00281010);

INCLUDE_ASM("build/ee_asm/game/particle/ke_2803C0", KeThBP_Update);

INCLUDE_ASM("build/ee_asm/game/particle/ke_2803C0", func_00281ED0);

void KeThBP_Quit(PoolNode *n)
{
    V6LinkObj *o = (V6LinkObj *)n; /* DEBT(CAST): the pool hands out untyped nodes */
    V6Link30 *p = o->ent;
    int f = o->h3E & 0x20;
    int i;

    for (i = o->h3C; i > 0; i--, p++) {
        func_002803C0(&p->o, f);
    }
    p = &o->ent[o->h34];
    for (i = o->h38; i > 0; i--, p++) {
        func_002803C0(&p->o, f);
    }
    if (o->pprev != 0) {
        if (o->next != 0) {
            o->next->pprev = o->pprev;
        }
        *o->pprev = o->next;
    }
}

void *func_00282040(Pool *pool) {
    PoolNode *node = pool->free;

    if (node == 0) {
        return 0;
    }
    pool->free = node->next;
    return node;
}

void func_00282060(Pool *pool, u8 count, u8 size) {
    PoolNode *node;
    int stride;
    int i;

    pool->count = count;
    pool->size = size;
    node = (PoolNode *)(pool + 1);
    pool->free = node;
    stride = (u8)(size - 1) * 0x30 + 0x80;
    pool->stride = stride;
    for (i = count - 1; i > 0; i--) {
        PoolNode *cur = node;
        node = (PoolNode *)((char *)node + stride);
        cur->next = node;
    }
    node->next = 0;
}

void func_002820C0(PoolNode **list, Pool *pool)
{
    PoolNode *n = *list;
    PoolNode *cur;

    while (n != 0) {
        cur = n;
        n = n->next;
        KeThBP_Quit(cur);
        cur->next = pool->free;
        ((PoolNode *)&pool->free)->next = cur; /* DEBT(CAST): the free-list head acts as a node (aliases cur->next) */
    }
    *list = 0;
}

INCLUDE_ASM("build/ee_asm/game/particle/ke_2803C0", func_00282128);

INCLUDE_ASM("build/ee_asm/game/particle/ke_2803C0", KeThCp_Update);

INCLUDE_ASM("build/ee_asm/game/particle/ke_2803C0", func_00282358);

void func_00282478(Pair *p) {
    p->ptr = 0;
    p->flag = 0;
}

int func_00282488(float *v, float *out)
{
    float x = v[0];
    float y = v[1];
    float a;
    double t;

    a = x * y; /* DEBT(FAKE): the product shares the result variable (register steering) */
    if (a > 0.0f) {
        a = -3.1415927f;
        if (x > 0.0f) {
            a = 0.0f;
        }
        t = func_002E76D0(func_002ED038(y / x));
        a = func_002EC440(func_002EBBB0(func_002ED038(a), t));
    } else if (a < 0.0f) {
        a = -1.5707964f;
        if (y > 0.0f) {
            a = 1.5707964f;
        }
        t = func_002E76D0(func_002ED038(x / y));
        a = func_002EC440(func_002EBC08(func_002ED038(a), t));
    } else if (x != 0.0f) {
        a = 3.1415927f;
        if (x > 0.0f) {
            a = 0.0f;
        }
    } else if (y != 0.0f) {
        a = -1.5707964f;
        if (y > 0.0f) {
            a = 1.5707964f;
        }
    } else {
        return 0;
    }
    *out = a;
    return 1;
}

/* NAME guess: LCG random step */
void func_00282608(void) {
    D_00373050 = (D_00373050 * 0x80D + 7) & 0xFFFF;
}

int func_00282628(void) {
    float a;
    register int t __asm__("$8");

    MIPS_ADDI0(t, -1);
    VU0_QMTC2_NI(2, t);
    VU0_OP("vrxor R, $vf2x");
    VU0_OP("vitof0.x $vf2, $vf2");
    VU0_OP("vrnext.x $vf1, R");
    VU0_OP("vadd.x $vf1, $vf1, $vf2");
    VU0_QMFC2_NI(a, 1);
    return (int)(a * 32768.0f);
}

INCLUDE_ASM("build/ee_asm/game/particle/ke_2803C0", KeVu0ItrsBallLine);

float func_00282758(float x, float y) {
    union {
        u_long128 q;
        float f[4];
    } v;

    v.f[0] = x;
    v.f[1] = y;
    VU0_LQC2(1, 0, &v);
    VU0_OP("vmaxy.x $vf1, $vf1, $vf1y");
    VU0_SQC2(1, 0, &v);
    return v.f[0];
}

void func_00282780(u32 a0, u32 a1)
{
    __asm__ volatile(
        "lqc2       $vf1, 0x0($4)\n"
        "lqc2       $vf2, 0x0($5)\n"
        "vmove.xy   $vf1, $vf2\n"
        "sqc2       $vf31, 0x0($4)\n"
        "nop\n"
        :  : "r"(a0), "r"(a1));
}

void func_00282798(void * dst, void * src)
{
    __asm__ volatile(
        "lqc2       $vf1, 0x0($4)\n"
        "lqc2       $vf4, 0x0($5)\n"
        "vmove.xyz  $vf1, $vf4\n"
        "sqc2       $vf1, 0x0($4)\n"
        "nop\n"
        :  : "r"(dst), "r"(src));
}

void func_002827B0(u32 a0, u32 a1, float f12)
{
    __asm__ volatile(
        "swc1       $f12, 0x0($4)\n"
        "lqc2       $vf1, 0x0($4)\n"
        "lqc2       $vf2, 0x0($5)\n"
        "vmulx.xyz  $vf2, $vf2, $vf1x\n"
        "sqc2       $vf2, 0x0($4)\n"
        "nop\n"
        :  : "r"(a0), "r"(a1));
}

void func_002827D0(u32 a0, u32 a1, float f12)
{
    __asm__ volatile(
        "swc1       $f12, 0x0($4)\n"
        "lqc2       $vf1, 0x0($4)\n"
        "lqc2       $vf2, 0x0($5)\n"
        "vmulx.xy   $vf2, $vf2, $vf1x\n"
        "sqc2       $vf2, 0x0($4)\n"
        "nop\n"
        :  : "r"(a0), "r"(a1));
}

void func_002827F0(u32 a0, u32 a1, u32 a2)
{
    __asm__ volatile(
        "lqc2       $vf1, 0x0($5)\n"
        "lqc2       $vf2, 0x0($6)\n"
        "lqc2       $vf3, 0x0($4)\n"
        "vadd.xy    $vf3, $vf1, $vf2\n"
        "sqc2       $vf3, 0x0($4)\n"
        "nop\n"
        :  : "r"(a0), "r"(a1), "r"(a2));
}

void func_00282810(u32 a0, u32 a1, u32 a2)
{
    __asm__ volatile(
        "lqc2       $vf1, 0x0($5)\n"
        "lqc2       $vf2, 0x0($6)\n"
        "lqc2       $vf3, 0x0($4)\n"
        "vsub.xyz   $vf3, $vf1, $vf2\n"
        "sqc2       $vf3, 0x0($4)\n"
        "nop\n"
        :  : "r"(a0), "r"(a1), "r"(a2));
}

void func_00282830(u32 a0, u32 a1, u32 a2)
{
    __asm__ volatile(
        "lqc2       $vf1, 0x0($5)\n"
        "lqc2       $vf2, 0x0($6)\n"
        "lqc2       $vf3, 0x0($4)\n"
        "vadd.xyz   $vf3, $vf1, $vf2\n"
        "sqc2       $vf3, 0x0($4)\n"
        "nop\n"
        :  : "r"(a0), "r"(a1), "r"(a2));
}

void func_00282850(u32 a0, u32 a1, u32 a2)
{
    __asm__ volatile(
        "lqc2       $vf1, 0x0($5)\n"
        "lqc2       $vf2, 0x0($6)\n"
        "lqc2       $vf3, 0x0($4)\n"
        "vsub.xy    $vf3, $vf1, $vf2\n"
        "sqc2       $vf3, 0x0($4)\n"
        "nop\n"
        :  : "r"(a0), "r"(a1), "r"(a2));
}

void func_00282870(u32 a0, u32 a1, u32 a2)
{
    __asm__ volatile(
        ".set noreorder\n"
        "lqc2       $vf1, 0x0($5)\n"
        "lqc2       $vf2, 0x0($6)\n"
        "vadd.xy    $vf1, $vf1, $vf2\n"
        "vftoi4.xy  $vf31, $vf1\n"
        "vftoi0.zw  $vf31, $vf1\n"
        "lui        $2, (0x45800000 >> 16)\n"
        "dsll       $2, $2, 16\n"
        "ori        $2, $2, 0x4580\n"
        "dsll       $2, $2, 16\n"
        "qmtc2.ni   $2, $vf29\n"
        "ctc2.ni    $0, $vi16\n"
        "vsub.xyw   $vf0, $vf1, $vf0\n"
        "vsub.xy    $vf0, $vf29, $vf1\n"
        "vnop\n"
        "vnop\n"
        "vnop\n"
        "vnop\n"
        "cfc2.ni    $2, $vi16\n"
        "andi       $2, $2, 0xC0\n"
        "beqz       $2, 1f\n"
        " nop\n"
        "addiu      $2, $0, 0x0\n"
        "ori        $2, $0, 0x8000\n"
        "ctc2.ni    $2, $vi1\n"
        "vmfir.w    $vf31, $vi1\n"
        "1:\n"
        "sqc2       $vf31, 0x0($4)\n"
        ".set reorder\n"
        : : "r"(a0), "r"(a1), "r"(a2) : "$2");
}

void func_002828E0(u32 a0, u32 a1)
{
    __asm__ volatile(
        ".set noreorder\n"
        "lqc2       $vf1, 0x0($5)\n"
        "vftoi4.xy  $vf2, $vf1\n"
        "vftoi0.zw  $vf2, $vf1\n"
        "lui        $2, (0x45800000 >> 16)\n"
        "dsll       $2, $2, 16\n"
        "ori        $2, $2, 0x4580\n"
        "dsll       $2, $2, 16\n"
        "qmtc2.ni   $2, $vf29\n"
        "ctc2.ni    $0, $vi16\n"
        "vsub.xyw   $vf0, $vf1, $vf0\n"
        "vsub.xy    $vf0, $vf29, $vf1\n"
        "vnop\n"
        "vnop\n"
        "vnop\n"
        "vnop\n"
        "cfc2.ni    $2, $vi16\n"
        "andi       $2, $2, 0xC0\n"
        "beqz       $2, 1f\n"
        " nop\n"
        "addiu      $2, $0, 0x0\n"
        "ori        $2, $0, 0x8000\n"
        "ctc2.ni    $2, $vi1\n"
        "vmfir.w    $vf2, $vi1\n"
        "1:\n"
        "sqc2       $vf2, 0x0($4)\n"
        ".set reorder\n"
        : : "r"(a0), "r"(a1) : "$2");
}

void func_00282948(u32 a0, u32 a1)
{
    __asm__ volatile(
        "lqc2       $vf1, 0x0($5)\n"
        "vmul.xy    $vf31, $vf1, $vf1\n"
        "vaddy.x    $vf31, $vf31, $vf31y\n"
        ".word      0x4A1F03BD                    # vsqrt      Q, $vf31x # 00000000 <InstrIdType: R5900_COP2_SPECIAL2>\n"
        "vwaitq\n"
        "vaddq.x    $vf31, $vf0, Q\n"
        "vdiv       Q, $vf0w, $vf31x\n"
        "vwaitq\n"
        "vmulq.xy   $vf31, $vf1, Q\n"
        "sqc2       $vf31, 0x0($4)\n"
        "nop\n"
        :  : "r"(a0), "r"(a1));
}

int func_00282978(u32 a0, u32 a1, u32 a2)
{
    register int res __asm__("$2");

    __asm__ volatile(
        "lqc2       $vf1, 0x0($5)\n"
        "lqc2       $vf2, 0x10($5)\n"
        "lqc2       $vf3, 0x20($5)\n"
        "lqc2       $vf4, 0x30($5)\n"
        "lqc2       $vf5, 0x0($6)\n"
        "vmulax.xyzw ACC, $vf1, $vf5x\n"
        "vmadday.xyzw ACC, $vf2, $vf5y\n"
        "vmaddaz.xyzw ACC, $vf3, $vf5z\n"
        "vmaddw.xyzw $vf5, $vf4, $vf5w\n"
        "vdiv       Q, $vf0w, $vf5w\n"
        "lui        $2, (0x45800000 >> 16)\n"
        "dsll       $2, $2, 16\n"
        "ori        $2, $2, 0x4580\n"
        "dsll       $2, $2, 16\n"
        "qmtc2.ni   $2, $vf29\n"
        "vwaitq\n"
        "vmulq.xyz  $vf5, $vf5, Q\n"
        "vnop\n"
        "vnop\n"
        "vnop\n"
        "ctc2.ni    $0, $vi16\n"
        "vsub.xyw   $vf0, $vf5, $vf0\n"
        "vsub.xy    $vf0, $vf29, $vf5\n"
        "vnop\n"
        "vnop\n"
        "vnop\n"
        "vnop\n"
        "cfc2.ni    $2, $vi16\n"
        "andi       $2, $2, 0xC0\n"
        "sqc2       $vf5, 0x0($4)\n"
        "nop\n"
        : "=r"(res) : "r"(a0), "r"(a1), "r"(a2));
    return res;
}

void func_002829F8(u32 a0, u32 a1)
{
    __asm__ volatile(
        "lqc2       $vf10, 0x0($5)\n"
        "vdiv       Q, $vf0w, $vf10w\n"
        "vwaitq\n"
        "vmulq.xyz  $vf9, $vf10, Q\n"
        "vftoi4.xy  $vf9, $vf9\n"
        "vftoi0.z   $vf9, $vf9\n"
        "vftoi0.w   $vf9, $vf10\n"
        "sqc2       $vf9, 0x0($4)\n"
        "nop\n"
        :  : "r"(a0), "r"(a1));
}

float func_00282A20(int n, float x)
{
    float r = 1.0f;
    int i;

    for (i = 0; i < n; i++) {
        r *= x;
    }
    return r;
}

float func_00282A58(float x) {
    union {
        u_long128 q;
        float f[4];
    } v;
    float r;

    v.f[1] = x;
    VU0_LQC2(10, 0, &v);
    VU0_OP("vsqrt Q, $vf10y");
    VU0_OP("vwaitq");
    VU0_CFC2_NI(r, 22);
    return r;
}

float KeVu0VecLen(Vec4 *v) {
    union {
        u_long128 q;
        float f[4];
    } o;

    VU0_LQC2(10, 0, v);
    VU0_OP("vmul.xyz $vf10, $vf10, $vf10");
    VU0_OP("vmove.xyz $vf9, $vf10");
    VU0_OP("vaddx.y $vf9, $vf9, $vf9x");
    VU0_OP("vaddy.z $vf9, $vf9, $vf9y");
    VU0_OP("vsqrt Q, $vf9z");
    VU0_OP("vwaitq");
    VU0_OP("vaddq.x $vf10, $vf0, Q");
    VU0_SQC2(10, 0, &o);
    return o.f[0];
}

float KeVu0VecLenXY(Vec4 *v) {
    float r;

    VU0_LQC2(10, 0, v);
    VU0_OP("vmul.xy $vf10, $vf10, $vf10");
    VU0_OP("vaddx.y $vf10, $vf10, $vf10x");
    VU0_OP("vsqrt Q, $vf10y");
    VU0_OP("vwaitq");
    VU0_CFC2_NI(r, 22);
    return r;
}

/* NAME guess: length of difference vector (result discarded by this wrapper) */
void func_00282AE0(Vec4 *a, Vec4 *b) {
    Vec4 d;

    func_002DD038(&d, a, b);
    KeVu0VecLen(&d);
}

u16 func_00282B10(IdPool *pool) {
    u16 head;

    if (pool->head == 0xFFFF) {
        return 0xFFFF;
    }
    head = pool->head;
    pool->head = pool->next[head];
    return head;
}

void func_00282B40(IdPool *pool, u16 *next, u16 count) {
    u16 i;

    pool->next = next;
    pool->head = 0;
    pool->count = count;
    for (i = 1; i < count; i++) {
        *next++ = i;
    }
    *next = 0xFFFF;
}

INCLUDE_ASM("build/ee_asm/game/particle/ke_2803C0", func_00282B88);

INCLUDE_ASM("build/ee_asm/game/particle/ke_2803C0", func_00282E68);

INCLUDE_ASM("build/ee_asm/game/particle/ke_2803C0", func_002830A0);

INCLUDE_ASM("build/ee_asm/game/particle/ke_2803C0", func_002832F0);

INCLUDE_ASM("build/ee_asm/game/particle/ke_2803C0", pppKeTh);

INCLUDE_ASM("build/ee_asm/game/particle/ke_2803C0", func_002839F8);

void func_00283B00(char *base, ScriptCtx *ctx)
{
    V6Wk *w = SLOT_WORK(V6Wk, base, ctx, 0);
    V6Sub *s = &w->s;

    func_00282478(&w->p);
    w->d70 = 0;
    w->d78 = 0;
    w->d80 = 0;
    w->d88 = 0;
    w->w6C = 0;
    s->wC = 0;
    s->w24 = 0;
    s->w2C = 0;
}

void func_00283B60(char *base, ScriptCtx *ctx)
{
    V6Wk *w = SLOT_WORK(V6Wk, base, ctx, 0);
    V6Sub *s = &w->s;

    w->d70 = 0;
    w->d78 = 0;
    w->d80 = 0;
    w->d88 = 0;
    w->w6C = 0;
    s->wC = 0;
    s->w24 = 0;
    s->w2C = 0;
}

void func_00283B98(void) {
}

typedef struct Ke3BA0Key {
    int owner;
    float f4;
    float f8;
    float fC;
    u32 idx;
    int ofs;
} Ke3BA0Key;

typedef struct Ke3BA0Work {
    u8 pad0[0x10];
    float f10;
    float f14;
    float f18;
    void *src;
} Ke3BA0Work;

void func_00283BA0(ScriptWork *base, Ke3BA0Key *k, ScriptCtx *ctx)
{
    Ke3BA0Work *w = SLOT_WORK(Ke3BA0Work, base, ctx, 0);

    if (base->owner == k->owner) {
        w->f10 = k->f8;
        w->f18 = k->f4;
        w->f14 = k->fC;
        w->src = (k->idx != 0xFFFFFFFF) ? (void *)(ppvMng->p3C[k->idx].base + (k->ofs + 0xA0)) : (void *)D_006EA450;
        if (w->src == D_006EA450) {
            w->src = 0;
        }
    }
    if (D_006A3BC4 == 0) {
        func_00282798(w, (char *)base + 0x40);
    }
}

void func_00283C50(char *base, ScriptCtx *ctx) {
    WkwCw1C *w = SLOT_WORK(WkwCw1C, base, ctx, 0);

    w->w1C = 0;
    w->wC = 0;
}

void func_00283C70(char *base, ScriptCtx *ctx)
{
    WkfCw1C *w = SLOT_WORK(WkfCw1C, base, ctx, 0);

    w->fC = 1.0f;
    w->w1C = 0;
}

void func_00283C98(char *base, ScriptCtx *ctx) {
    func_00282060(SLOT_WORK(Pool, base, ctx, 0), 1, 3);
}

void func_00283CB8(char *base, ScriptCtx *ctx) {
    func_00282060(SLOT_WORK(Pool, base, ctx, 0), 1, 8);
}

void func_00283CD8(char *base, ScriptCtx *ctx) {
    func_00282060(SLOT_WORK(Pool, base, ctx, 0), 4, 8);
}

void func_00283CF8(char *base, ScriptCtx *ctx) {
    func_00282060(SLOT_WORK(Pool, base, ctx, 0), 128, 8);
}

void func_00283D18(char *base, ScriptCtx *ctx) {
    func_00282060(SLOT_WORK(Pool, base, ctx, 0), 1, 16);
}

void func_00283D38(char *base, ScriptCtx *ctx) {
    func_00282060(SLOT_WORK(Pool, base, ctx, 0), 4, 16);
}

void func_00283D58(char *base, ScriptCtx *ctx) {
    func_00282060(SLOT_WORK(Pool, base, ctx, 0), 64, 16);
}

void func_00283D78(char *base, ScriptCtx *ctx) {
    func_00282060(SLOT_WORK(Pool, base, ctx, 0), 1, 24);
}

void func_00283D98(char *base, ScriptCtx *ctx) {
    func_00282060(SLOT_WORK(Pool, base, ctx, 0), 4, 24);
}

void func_00283DB8(char *base, ScriptCtx *ctx) {
    func_00282060(SLOT_WORK(Pool, base, ctx, 0), 1, 32);
}

void func_00283DD8(char *base, ScriptCtx *ctx) {
    func_00282060(SLOT_WORK(Pool, base, ctx, 0), 4, 32);
}

void func_00283DF8(char *base, ScriptCtx *ctx) {
    func_00282060(SLOT_WORK(Pool, base, ctx, 0), 32, 32);
}

void func_00283E18(char *base, ScriptCtx *ctx) {
    func_00282060(SLOT_WORK(Pool, base, ctx, 0), 1, 40);
}

void func_00283E38(char *base, ScriptCtx *ctx) {
    func_00282060(SLOT_WORK(Pool, base, ctx, 0), 4, 40);
}

void func_00283E58(char *base, ScriptCtx *ctx) {
    func_00282060(SLOT_WORK(Pool, base, ctx, 0), 1, 48);
}

void func_00283E78(char *base, ScriptCtx *ctx) {
    func_00282060(SLOT_WORK(Pool, base, ctx, 0), 4, 48);
}

void func_00283E98(char *base, ScriptCtx *ctx) {
    func_00282060(SLOT_WORK(Pool, base, ctx, 0), 1, 64);
}

void func_00283EB8(char *base, ScriptCtx *ctx) {
    func_00282060(SLOT_WORK(Pool, base, ctx, 0), 4, 64);
}

void func_00283ED8(char *base, ScriptCtx *ctx) {
    func_00282060(SLOT_WORK(Pool, base, ctx, 0), 16, 64);
}

void func_00283EF8(char *base, ScriptCtx *ctx) {
    func_00282060(SLOT_WORK(Pool, base, ctx, 0), 1, 128);
}

void func_00283F18(char *base, ScriptCtx *ctx) {
    func_00282060(SLOT_WORK(Pool, base, ctx, 0), 4, 128);
}

void func_00283F38(char *base, ScriptCtx *ctx) {
    func_00282060(SLOT_WORK(Pool, base, ctx, 0), 8, 128);
}

void func_00283F58(char *base, ScriptCtx *ctx) {
    func_00282060(SLOT_WORK(Pool, base, ctx, 0), 1, 255);
}

void func_00283F78(char *base, ScriptCtx *ctx) {
    func_00282060(SLOT_WORK(Pool, base, ctx, 0), 4, 255);
}

void func_00283F98(char *base, ScriptCtx *ctx) {
    func_00282060(SLOT_WORK(Pool, base, ctx, 0), 8, 16);
}

void func_00283FB8(char *base, ScriptCtx *ctx) {
    func_00282060(SLOT_WORK(Pool, base, ctx, 0), 16, 16);
}

void func_00283FD8(char *base, ScriptCtx *ctx) {
    func_00282060(SLOT_WORK(Pool, base, ctx, 0), 24, 16);
}

void func_00283FF8(char *base, ScriptCtx *ctx) {
    func_00282060(SLOT_WORK(Pool, base, ctx, 0), 8, 24);
}

void func_00284018(char *base, ScriptCtx *ctx) {
    func_00282060(SLOT_WORK(Pool, base, ctx, 0), 16, 24);
}

void func_00284038(char *base, ScriptCtx *ctx) {
    func_00282060(SLOT_WORK(Pool, base, ctx, 0), 8, 32);
}

void func_00284058(char *base, ScriptCtx *ctx) {
    func_00282060(SLOT_WORK(Pool, base, ctx, 0), 16, 32);
}

void func_00284078(char *base, ScriptCtx *ctx) {
    func_00282060(SLOT_WORK(Pool, base, ctx, 0), 24, 32);
}

void func_00284098(char *base, ScriptCtx *ctx) {
    func_00282060(SLOT_WORK(Pool, base, ctx, 0), 8, 40);
}

void func_002840B8(char *base, ScriptCtx *ctx) {
    func_00282060(SLOT_WORK(Pool, base, ctx, 0), 16, 40);
}

void func_002840D8(char *base, ScriptCtx *ctx) {
    func_00282060(SLOT_WORK(Pool, base, ctx, 0), 8, 48);
}

void func_002840F8(char *base, ScriptCtx *ctx) {
    func_00282060(SLOT_WORK(Pool, base, ctx, 0), 16, 48);
}

void func_00284118(char *base, ScriptCtx *ctx) {
    func_00282060(SLOT_WORK(Pool, base, ctx, 0), 8, 64);
}

INCLUDE_ASM("build/ee_asm/game/particle/ke_2803C0", func_00284138);

void func_00284310(char *base, ScriptCtx *ctx) {
    Wkb0b1b2b3 *w = SLOT_WORK(Wkb0b1b2b3, base, ctx, 1);

    w->b0 = 0;
}

void func_00284328(T6TransformFrame *frame, T6AttributeDelta *delta, T6TransformInput *input)
{
    T6AttributeValues *values;
    T6AttributeOutput *output;
    T6AttributeVectors *vectors;
    int *offsets;

    if (D_006A3BC4 != 0)
        return;
    offsets = input->offsets;
    /* DEBT(CAST): payload offsets select these typed attribute blocks. */
    output = (T6AttributeOutput *)(frame->payload + offsets[1]);
    vectors = &output->vectors;
    values = (T6AttributeValues *)(frame->payload + offsets[0]);
    if (frame->idC == delta->id)
    {
        output->enabled = (u8) delta->enabled;
        values->channels[0] = (u16) (values->channels[0] + delta->channels[0]);
        values->channels[1] = (u16) (values->channels[1] + delta->channels[1]);
        values->values[2] = (float) (values->values[2] + delta->values[2]);
        values->channels[2] = (u16) (values->channels[2] + delta->channels[2]);
        values->values[0] = (float) (values->values[0] + delta->values[0]);
        /* DEBT(ORDER): this independent float update precedes channel 3. */
        values->values[1] = (float) (values->values[1] + delta->values[1]);
        values->channels[3] = (u16) (values->channels[3] + delta->channels[3]);
        values->channels[4] = (u16) (values->channels[4] + delta->channels[4]);
        values->channels[5] = (u16) (values->channels[5] + delta->channels[5]);
        values->values[3] = (float) (values->values[3] + delta->values[3]);
        values->channels[6] = (u16) (values->channels[6] + delta->channels[6]);
        values->channels[7] = (u16) (values->channels[7] + delta->channels[7]);
        values->channels[8] = (u16) (values->channels[8] + delta->channels[8]);
        values->channels[9] = (u16) (values->channels[9] + delta->channels[9]);
        values->channels[10] = (u16) (values->channels[10] + delta->channels[10]);
        values->channels[11] = (u16) (values->channels[11] + delta->channels[11]);
        values->channels[12] = (u16) (values->channels[12] + delta->channels[12]);
        values->channels[13] = (u16) (values->channels[13] + delta->channels[13]);
        values->channels[14] = (u16) (values->channels[14] + delta->channels[14]);
        values->channels[15] = (u16) (values->channels[15] + delta->channels[15]);
        if (frame->idC == 0)
            return;
    }

    output->channels[0] = (u16) (output->channels[0] + values->channels[0]);
    output->channels[1] = (u16) (output->channels[1] + values->channels[1]);
    output->value6C = (float) (output->value6C + values->values[2]);
    output->channels[2] = (u16) (output->channels[2] + values->channels[2]);
    output->channels[3] = (u16) (output->channels[3] + values->channels[3]);
    vectors->value0C = (float) (vectors->value0C + values->values[0]);
    output->channels[4] = (u16) (output->channels[4] + values->channels[4]);
    output->channels[5] = (u16) (output->channels[5] + values->channels[5]);
    vectors->value24 = (float) (vectors->value24 + values->values[1]);
    output->channels[6] = (u16) (output->channels[6] + values->channels[6]);
    vectors->value2C = (float) (vectors->value2C + values->values[3]);
    output->channels[7] = (u16) (output->channels[7] + values->channels[7]);
    output->channels[8] = (u16) (output->channels[8] + values->channels[8]);
    output->channels[9] = (u16) (output->channels[9] + values->channels[9]);
    output->channels[10] = (u16) (output->channels[10] + values->channels[10]);
    output->channels[11] = (u16) (output->channels[11] + values->channels[11]);
    output->channels[12] = (u16) (output->channels[12] + values->channels[12]);
    output->channels[13] = (u16) (output->channels[13] + values->channels[13]);
    output->channels[14] = (u16) (output->channels[14] + values->channels[14]);
    output->channels[15] = (u16) (output->channels[15] + values->channels[15]);
}

void func_00284600(char *base, ScriptCtx *ctx) {
    Wkq0q8q10q18w20w24w28w2C *w = SLOT_WORK(Wkq0q8q10q18w20w24w28w2C, base, ctx, 0);

    w->w28 = 0;
    w->w20 = 0;
    w->w24 = 0;
    w->w2C = 0;
    w->q0 = 0;
    w->q8 = 0;
    w->q10 = 0;
    w->q18 = 0;
}

INCLUDE_ASM("build/ee_asm/game/particle/ke_2803C0", func_00284638);

void func_00284920(char *base, ScriptCtx *ctx) {
    Wkh0h2 *w = SLOT_WORK(Wkh0h2, base, ctx, 0);

    w->h0 = 0;
}

void func_00284938(char *base, void *p, void *entry, int *out)
{
    T6_EvA *ev = p;
    s16 *pos = entry;
    T6_Mem **mp = (T6_Mem **)out; /* DEBT(CAST): EvFrameCb declares the out slot as int * */
    T6_MemEnt *e = &ppvMng->p3C[ev->idx];
    T6_Mem *m;
    char *dir;
    char *at;
    Vec4 v;

    if (e == 0) {
        *mp = 0;
    } else {
        m = func_00267320(ppvMng, e);
        *mp = m;
        if (m == 0) {
            return;
        }
        m->user = (ScriptWork *)base;
    }
    v.x = pos[0];
    v.y = pos[1];
    v.z = pos[2];
    v.w = 1.0f;
    at = (char *)*mp + (ev->ofs14 + 0xA0);
    dir = (char *)*mp + (ev->ofs1C + 0xA0);
    func_002DCE08(&v, base + 0x10, &v);
    func_00282798(at, &v);
    func_002DD038(&v, &v, (Vec4 *)(base + 0x40)); /* DEBT(CAST): position inside the script memory header */
    func_002DCEC8(&v, &v);
    func_002DD068(&v, &v, ev->f8);
    func_00282798(dir, &v);
}

int func_00284A60(char *base, EvMsgA *ev, ScriptCtx *ctx) {
    if (D_006A3BC4 == 0) {
        if (ev->bD != 0xFF) {
            if (!((func_00282628() >> 8) & ev->bD)) {
                if (ev->w10 != 0xFFFFFFFF && ev->w18 != 0xFFFFFFFF) {
                    return func_0027F180(base, ev, func_00284938, &SLOT_WORK(Wkh0h2, base, ctx, 0)->h0, ev->h4, ev->bE, ev->bC);
                }
            }
        }
    }
}

void func_00284B20(char *base, ScriptCtx *ctx) {
    Wkh0h2 *w = SLOT_WORK(Wkh0h2, base, ctx, 0);

    w->h0 = 0;
}

INCLUDE_ASM("build/ee_asm/game/particle/ke_2803C0", func_00284B38);

int func_00284C50(char *base, EvMsgB *ev, ScriptCtx *ctx) {
    if (D_006A3BC4 == 0) {
        if (ev->b7 != 0xFF) {
            if (!((func_00282628() >> 8) & ev->b7)) {
                if (ev->wC != 0xFFFFFFFF && ev->w14 != 0xFFFFFFFF) {
                    return func_0027F180(base, ev, func_00284B38, &SLOT_WORK(Wkh0h2, base, ctx, 0)->h0, ev->h4, ev->b8, ev->b6);
                }
            }
        }
    }
}

void func_00284D10(char *base, ScriptCtx *ctx) {
    Wkh0h2 *w = SLOT_WORK(Wkh0h2, base, ctx, 0);

    w->h0 = 0;
}

INCLUDE_ASM("build/ee_asm/game/particle/ke_2803C0", func_00284D28);

INCLUDE_ASM("build/ee_asm/game/particle/ke_2803C0", func_00284E70);

void func_002851C0(char *base, ScriptCtx *ctx) {
    Wkh0h2 *w = SLOT_WORK(Wkh0h2, base, ctx, 0);

    w->h0 = 0;
}

void func_002851D8(char *base, void *p, void *entry, int *out)
{
    T6_EvA *ev = p;
    s16 *pos = entry;
    T6_Mem **mp = (T6_Mem **)out; /* DEBT(CAST): EvFrameCb declares the out slot as int * */
    T6_MemEnt *e = &ppvMng->p3C[ev->idx];
    T6_Mem *m;
    char *dir;
    char *at;
    Vec4 v;

    if (e == 0) {
        *mp = 0;
    } else {
        m = func_00267320(ppvMng, e);
        *mp = m;
        if (m == 0) {
            return;
        }
        m->user = (ScriptWork *)base;
    }
    v.x = pos[0];
    v.y = pos[1];
    v.z = pos[2];
    v.w = 1.0f;
    at = (char *)*mp + (ev->ofs14 + 0xA0);
    dir = (char *)*mp + (ev->ofs1C + 0xA0);
    func_002DCE08(&v, base + 0x10, &v);
    func_00282798(at, &v);
    func_002DD038(&v, &v, (Vec4 *)(base + 0x40)); /* DEBT(CAST): position inside the script memory header */
    func_002DCEC8(&v, &v);
    func_002DD068(&v, &v, ev->f8);
    func_00282798(dir, &v);
}

void func_00285300(char *base, EvMsgA *ev, ScriptCtx *ctx) {
    Wkh0b2 *w;
    int cnt;

    if (D_006A3BC4 == 0) {
        cnt = ev->bD;
        if (cnt != 0) {
            w = SLOT_WORK(Wkh0b2, base, ctx, 0);
            if (w->b2 != 0) {
                w->b2--;
            } else {
                w->b2 = cnt;
                if (ev->w10 != 0xFFFFFFFF && ev->w18 != 0xFFFFFFFF) {
                    if (func_0027F180(base, ev, func_002851D8, &w->h0, ev->h4, ev->bE, ev->bC)) {
                        w->b2--;
                    }
                }
            }
        }
    }
}

void func_002853A0(char *base, ScriptCtx *ctx) {
    Wkh0b2 *w = SLOT_WORK(Wkh0b2, base, ctx, 0);

    w->h0 = 0;
    w->b2 = 0;
}

int func_002853C0(float *v, float *out)
{
    float x = v[0];
    float y = v[1];
    float a;
    double t;

    a = x * y; /* DEBT(FAKE): the product shares the result variable (register steering) */
    if (a > 0.0f) {
        a = -3.1415927f;
        if (x > 0.0f) {
            a = 0.0f;
        }
        t = func_002E76D0(func_002ED038(y / x));
        a = func_002EC440(func_002EBBB0(func_002ED038(a), t));
    } else if (a < 0.0f) {
        a = -1.5707964f;
        if (y > 0.0f) {
            a = 1.5707964f;
        }
        t = func_002E76D0(func_002ED038(x / y));
        a = func_002EC440(func_002EBC08(func_002ED038(a), t));
    } else if (x != 0.0f) {
        a = 3.1415927f;
        if (x > 0.0f) {
            a = 0.0f;
        }
    } else if (y != 0.0f) {
        a = -1.5707964f;
        if (y > 0.0f) {
            a = 1.5707964f;
        }
    } else {
        return 0;
    }
    *out = a;
    return 1;
}

INCLUDE_ASM("build/ee_asm/game/particle/ke_2803C0", func_00285540);
