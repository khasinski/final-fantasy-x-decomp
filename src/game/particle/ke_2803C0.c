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

typedef struct KeThBP {
    struct KeThBP *next;
    struct KeThBP **pprev;
    u32 w8;
    u32 wC;
    struct KeThBP *p10;
    u32 w14;
    u32 w18;
    u16 h1C;
    u8 b1E;
    u8 pad1F;
    u16 h20;
    u8 pad22;
    u8 b23;
    u32 pad24;
    u32 w28;
    u32 pad2C;
    u32 w30;
    u16 h34;
    u8 b36;
    u8 b37;
    u16 h38;
    u16 pad3A;
    u16 h3C;
    u16 h3E;
    u8 pad40[0xC];
    float f4C;
    u8 pad50[8];
    u32 w58;
    u32 w5C;
} KeThBP; /* DEBT(NAME): KeThBP node layout (0x40-byte header + N*0x30 entries) */

typedef struct KeThBPInitArg {
    KeThBP *p;
    u8 n;
} KeThBPInitArg; /* DEBT(NAME): argument struct for func_00281ED0 */

typedef struct KeThCp {
    KeThBP *head;
    u8 flags;
} KeThCp; /* DEBT(NAME): KeThCp list header */

typedef struct KeThCpUpdateArg {
    KeThCp *cp;
    void *w4;
    void *w8;
    Pool *pool;
    void *p10;
    void *p14;
} KeThCpUpdateArg; /* DEBT(NAME): argument struct for KeThCp_Update */

typedef struct KeThBPUpdateArg {
    u8 mat[0x40];
    KeThBP *o;
    void *w44;
    Pool *w48;
    void *w4C;
} KeThBPUpdateArg; /* DEBT(NAME): stack argument struct for KeThBP_Update */

typedef struct KeThDrawArg {
    void *w0;
    KeThBP *o;
    u8 *w8;
    void *wC;
    void *w10;
    u64 *p14;
    u64 q18;
    u64 q20;
    void *w28;
} KeThDrawArg; /* DEBT(NAME): stack argument struct for func_00281010 */

typedef struct KeTh4138Ev {
    int id;
    u32 idx;
    int ofs;
    u8 bC;
} KeTh4138Ev; /* DEBT(NAME): event struct for func_00284138 */

void KeThBP_Update(KeThBPUpdateArg *a);
int func_00281010(KeThDrawArg *a);

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

void func_00282128(KeThCp *cp, Pool *pool, void *a2, void *a3)
{
    KeThBPInitArg init;
    KeThBP *o = (KeThBP *)func_00282040(pool);
    int flg;

    if (o == 0) {
        return;
    }
    init.p = o;
    init.n = pool->size;
    flg = 0x100;
    func_00281ED0(&init);
    o->w5C = 0;
    o->w30 = 0;
    if (cp->flags & 4) {
        flg = 0x180;
    }
    if (cp->flags & 0x10) {
        flg |= 0x200;
    }
    if (cp->flags & 8) {
        flg |= 0x400;
    }
    if (cp->flags & 0x20) {
        flg |= 0x1000;
    }
    o->h3E |= flg;
    func_00282798((u8 *)o + 0x40, a2);
    func_00282798((u8 *)o + 0x60, a3);
    if (cp->head != 0) {
        cp->head->pprev = &o->next;
    }
    o->next = cp->head;
    cp->head = o;
    __asm__ volatile("" ::: "memory"); /* DEBT(ORDER): keep pprev store after head store */
    o->pprev = &cp->head;
}

void KeThCp_Update(KeThCpUpdateArg *a)
{
    KeThCp *cp = a->cp;
    KeThBPUpdateArg u;
    KeThBP *o;
    int f = 0;

    if (cp->flags & 2) {
        cp->flags &= ~2;
        f = 0x20;
    }
    func_002DD128(&u);
    u.w44 = a->w4;
    u.w48 = a->pool;
    u.w4C = a->w8;
    o = cp->head;
    while (o != 0) {
        if (o->h3E & 0x200) {
            func_00282798((u8 *)o + (o->h34 * 0x30 + 0x40), a->p10);
            func_00282798((u8 *)o + o->h34 * 0x30 + 0x60, a->p14);
        }
        if (o->h3E & 0x100) {
            o->h3E |= f;
        }
        u.o = o;
        KeThBP_Update(&u);
        if (o->h3E & 0x10) {
            KeThBP *cur = o;
            PoolNode *pn = (PoolNode *)cur;
            o = o->next;
            if (cur->next != 0) {
                cur->next->pprev = cur->pprev;
            }
            *cur->pprev = cur->next;
            KeThBP_Quit(pn);
            pn->next = a->pool->free;
            ((PoolNode *)&a->pool->free)->next = pn; /* DEBT(CAST): free-list head acts as a node (aliases pn->next) */
        } else {
            o = o->next;
        }
    }
}

void func_00282358(KeThCp *cp, void *a1, void *a2, void *a3, u8 **pbuf, u64 a5, u64 a6, void *a7)
{
    KeThDrawArg d;
    u8 *cur = *pbuf;
    u8 *prev = cur;
    KeThBP *o = cp->head;

    d.wC = a3;
    d.w0 = a1;
    d.w10 = a2;
    d.q18 = a5;
    d.q20 = a6;
    d.w28 = a7;
    d.w8 = cur + 0x10;
    while (o != 0) {
        d.o = o;
        if (func_00281010(&d) != 0) {
            prev = cur;
            cur = d.w8;
            *(u_long128 *)prev = 0; /* DEBT(TYPE): 128-bit zero store via TI mode */
            prev[3] = 0x10;
            *(u16 *)prev = ((u32)(cur - prev) >> 4) - 1;
            d.w8 += 0x10;
        }
        o = o->next;
    }
    if (cur != *pbuf) {
        u32 *ch = func_002DB6D8(2);
        *d.p14 |= 0x8000;
        prev[3] = 0x70;
        func_002DA610(0, 0);
        func_002F8660(0);
        func_002DBA28(ch, (int)*pbuf);
        *pbuf = cur;
    }
}

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

extern u_long128 D_00373060[2];
extern s8 D_00373080[32];
void func_002DCFB8(Vec4 *dst, Vec4 *src, float s);

void func_00282B88(u32 c0, u32 c1, u32 *dst, float f)
{
    Vec4 step_col;
    Vec4 cur_col;
    u32 col1 = c1;
    u32 col0 = c0;
    s8 *step;
    s32 n;
    s32 i;
    u32 *p;
    float cnt;
    u8 *p1;
    u8 *p0;

    n = (s32)f;
    {
        register u_long128 *s __asm__("$4");
        step = (s8 *)func_002B3888(0x20);
        s = D_00373060;
        ((u_long128 *)step)[0] = s[0];
        ((u_long128 *)step)[1] = s[1];
    }
    if (n < 0) {
        if (n < -0x100) {
            n = -0x100;
        }
        n += 0x100;
        p = dst + (n & 0xE0) + D_00373080[n & 0x1F];
        for (i = n; i < 0x100; i++) {
            *p = col0;
            p += step[i & 0x1F];
        }
        cnt = (float)n;
        p = dst;
        i = 0;
    } else {
        if (n >= 0x100) {
            n = 0xFF;
        }
        p = dst;
        for (i = 0; i < n; i++) {
            *p = col1;
            p += step[i & 0x1F];
        }
        cnt = 256.0f - (float)n;
        n = 0x100;
    }
    p1 = (u8 *)&col1;
    p0 = (u8 *)&col0;
    cur_col.x = p1[0];
    cur_col.y = p1[1];
    cur_col.z = p1[2];
    cur_col.w = p1[3];
    step_col.x = p0[0];
    step_col.y = p0[1];
    step_col.z = p0[2];
    step_col.w = p0[3];
    func_002DD038(&step_col, &step_col, &cur_col);
    func_002DCFB8(&step_col, &step_col, cnt);
    for (; i < n; i++) {
        u32 c = ((u32)cur_col.w << 24) | (u32)cur_col.x;
        c |= ((u32)cur_col.y << 8) | ((u32)cur_col.z << 16);
        *p = c;
        func_002DD020(&cur_col, &cur_col, &step_col);
        p += step[i & 0x1F];
    }
    func_002B39C0(0x20);
}

INCLUDE_ASM("build/ee_asm/game/particle/ke_2803C0", func_00282E68);

INCLUDE_ASM("build/ee_asm/game/particle/ke_2803C0", func_002830A0);

INCLUDE_ASM("build/ee_asm/game/particle/ke_2803C0", func_002832F0);

typedef struct KeThEv {
    s32 w00;
    u32 w04;
    s32 w08;
    s32 pad0C;
    u16 h10[16];
    float f30;
    float f34;
    float f38;
    float f3C;
    float f40;
    float f44;
    float f48;
    float f4C;
    float f50;
    u16 h54;
    u8 b56;
    u8 b57;
    u8 b58;
    u8 b59;
    u8 b5A;
    u8 b5B;
    u8 b5C;
} KeThEv;

typedef struct KeThSub {
    u8 b00[8];
    u8 pad08[4];
    float f0C;
    u8 b10[8];
    u8 pad18[4];
    float f1C;
    float f20;
    float f24;
    float f28;
    float f2C;
    float f30;
    float f34;
    float f38;
    float f3C;
    u8 b40;
    u8 b41;
    u8 b42;
    u8 pad43;
} KeThSub;

typedef struct KeThWork {
    KeThCp cp;
    u8 pad08[8];
    KeThSub sub;
    u8 pad54[0xC];
    Pool *p60;
    void *p64;
    float f68;
    float f6C;
    u16 h70[16];
} KeThWork;

extern double D_005743E8;
extern double D_005743F0;

void pppKeTh(u8 *base, KeThEv *ev, ScriptCtx *ctx)
{
    u8 mat[0x40];
    Vec4 dir;
    Vec4 pos;
    KeThCpUpdateArg upd;
    KeThWork *w = SLOT_WORK(KeThWork, base, ctx, 0);
    KeThSub *sub = &w->sub;
    Vec4 *v_in = SLOT_WORK(Vec4, base, ctx, 2);

    if (D_006A3BC4 != 0) {
        return;
    }
    func_002DD0C0(mat, base + 0x10);
    *(u_long128 *)(mat + 0x30) = 0;
    *(float *)(mat + 0x3C) = 1.0f;
    func_002DCE08(&dir, mat, v_in);
    func_002DCEC8(&dir, &dir);
    func_002DD0B0(&pos, (Vec4 *)(base + 0x40));
    if (*(s32 *)(base + 0xC) == ev->w00) {
        if (*(s32 *)(base + 0xC) == 0) {
            Pool *pool = SLOT_WORK(Pool, base, ctx, 1);
            void *src = (ev->w04 != 0xFFFFFFFFU) ? (void *)(ppvMng->p3C[ev->w04].base + (ev->w08 + 0xA0)) : (void *)D_006EA450;
            if (w->p64 == D_006EA450) {
                return;
            }
            w->p64 = src;
            w->p60 = pool;
            if (ev->b5A == 0) {
                w->cp.flags |= 8;
            }
            if (ev->b59 != 0) {
                w->cp.flags |= 4;
            }
            if (ev->b5C != 0) {
                w->cp.flags |= 0x10;
            }
            if (ev->b5B != 0) {
                w->cp.flags |= 0x20;
            }
            func_00282128(&w->cp, w->p60, &pos, &dir);
        }
        w->h70[0] += ev->h10[0];
        w->h70[1] += ev->h10[1];
        w->h70[2] += ev->h10[2];
        w->h70[3] += ev->h10[3];
        w->h70[4] += ev->h10[4];
        w->h70[5] += ev->h10[5];
        w->h70[6] += ev->h10[6];
        w->h70[7] += ev->h10[7];
        w->h70[8] += ev->h10[8];
        w->h70[9] += ev->h10[9];
        w->h70[10] += ev->h10[10];
        w->h70[11] += ev->h10[11];
        w->h70[12] += ev->h10[12];
        w->h70[13] += ev->h10[13];
        w->h70[14] += ev->h10[14];
        w->h70[15] += ev->h10[15];
        w->f68 = ev->f30;
        w->f6C += ev->f4C;
        sub->b42 = w->p60->size - 1;
        sub->f0C += ev->f34;
        sub->f30 = ev->f3C;
        sub->f38 = ev->f40;
        sub->f3C = ev->f44;
        sub->f24 += ev->f48;
        sub->f2C += ev->f50;
        {
            register double x __asm__("$2") = (double)(s32)ev->h54;
            register double d __asm__("$5");
            __asm__ volatile(".set noat\nlui $1, %hi(D_005743E8)\n.set at");
            __asm__ volatile(".set noat\nld %0, %%lo(D_005743E8)($1)\n.set at" : "=r"(d));
            x = func_002EBC70(x, d);
            __asm__ volatile(".set noat\nlui $1, %hi(D_005743F0)\n.set at");
            __asm__ volatile(".set noat\nld %0, %%lo(D_005743F0)($1)\n.set at" : "=r"(d));
            sub->f28 = func_002EC440(func_002EBC70(x, d));
        }
        sub->b40 = ev->b56;
        sub->b41 = ev->b57;
        sub->f1C = -(sub->f0C - sub->f0C * ev->f38) / (float)sub->b42;
    }
    sub->f20 = w->f68 / (float)sub->b42;
    sub->f34 = w->f6C / sub->f20;
    sub->b00[0] = w->h70[0] >> 7;
    sub->b00[1] = w->h70[1] >> 7;
    sub->b00[2] = w->h70[2] >> 7;
    sub->b00[3] = w->h70[3] >> 7;
    sub->b00[4] = w->h70[4] >> 7;
    sub->b00[5] = w->h70[5] >> 7;
    sub->b00[6] = w->h70[6] >> 7;
    sub->b00[7] = w->h70[7] >> 7;
    sub->b10[0] = w->h70[8] >> 7;
    sub->b10[1] = w->h70[9] >> 7;
    sub->b10[2] = w->h70[10] >> 7;
    sub->b10[3] = w->h70[11] >> 7;
    sub->b10[4] = w->h70[12] >> 7;
    sub->b10[5] = w->h70[13] >> 7;
    sub->b10[6] = w->h70[14] >> 7;
    sub->b10[7] = w->h70[15] >> 7;
    upd.w8 = sub;
    upd.p10 = &pos;
    upd.p14 = &dir;
    upd.pool = w->p60;
    upd.w4 = w->p64;
    upd.cp = &w->cp;
    KeThCp_Update(&upd);
}

extern u8 D_006A3AB0[];

void func_002839F8(char *base, u8 *ev, ScriptCtx *ctx)
{
    KeThCp *cp = SLOT_WORK(KeThCp, base, ctx, 0);
    float col[4];
    float sc[4];
    u64 a5;
    u64 a6;
    float inv = 1.0f / 4096.0f;

    sc[0] = ((float *)ppvMng->m60)[0];
    sc[1] = ((float *)ppvMng->m60)[1] * (13.0f / 12.0f);
    switch (ev[0x58]) {
    case 0:
        a5 = 0x48;
        a6 = 0x51801;
        break;
    case 1:
        a5 = 0x42;
        a6 = 0x51801;
        break;
    default:
        a5 = (0x80ULL << 32) | 0xA8;
        a6 = 0x70000;
        break;
    }
    col[0] = ppvMng->scale[0] * inv;
    col[1] = ppvMng->scale[1] * inv;
    col[2] = ppvMng->scale[2] * inv;
    col[3] = ppvMng->scale[3] * inv;
    func_00282358(cp, D_006A3AB0, sc, (u8 *)cp + 0x10, &D_006A3BCC, a5, a6, col);
}

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

void func_00284138(T6TransformFrame *frame, KeTh4138Ev *ev, ScriptCtx *ctx)
{
    u8 *flag = SLOT_WORK(u8, frame, ctx, 1);
    KeThBP *o;

    if (frame->idC == ev->id) {
        if (ev->bC != 0) {
            *flag |= 2;
        } else {
            *flag &= ~2;
        }
    }
    if (D_006A3BC4 != 0) {
        return;
    }
    if (ev->idx == 0xFFFFFFFFU) {
        return;
    }
    o = *SLOT_WORK(KeThBP *, frame, ctx, 0);
    if (*flag & 2) {
        while (o != 0) {
            if (o->h3E & 0x800) {
                T6_MemEnt *e = &ppvMng->p3C[ev->idx];
                T6_Mem *m;
                if (e != 0) {
                    m = func_00267320(ppvMng, e);
                    if (m == 0) {
                        return;
                    }
                    m->user = (ScriptWork *)frame;
                } else {
                    m = 0;
                }
                func_00282798((u8 *)m + (ev->ofs + 0xA0), (u8 *)o + (o->b36 * 0x30 + 0x40));
            }
            o = o->next;
        }
    } else {
        while (o != 0) {
            if ((*(u64 *)&o->h38 & 0x0840000000000000ULL) == 0x0800000000000000ULL) { /* DEBT(TYPE): 64-bit mask on h38..h3E (bits 0x0840 of h3E) */
                T6_MemEnt *e = &ppvMng->p3C[ev->idx];
                T6_Mem *m;
                if (e != 0) {
                    m = func_00267320(ppvMng, e);
                    if (m == 0) {
                        return;
                    }
                    m->user = (ScriptWork *)frame;
                } else {
                    m = 0;
                }
                func_00282798((u8 *)m + (ev->ofs + 0xA0), (u8 *)o + (o->b36 * 0x30 + 0x40));
            }
            o = o->next;
        }
    }
}

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

typedef struct Ke4638Ev {
    s32 w00;
    s16 h04;
    s16 h06;
    u8 b08;
    u8 b09;
    u8 b0A;
    u8 pad0B;
    u32 w0C;
    s32 w10;
    u32 w14;
    s32 w18;
} Ke4638Ev;

typedef struct Ke4638Ent {
    s16 h00;
    s16 h02;
    u16 *p04;
} Ke4638Ent;

typedef struct Ke4638Tbl20 {
    u8 pad00[0x14];
    void *p14;
    u8 pad18[0x8];
} Ke4638Tbl20;

typedef struct Ke4638Res {
    u8 pad00[0x20];
    Ke4638Tbl20 *tbl20;
    u8 pad24[0x4];
    Ke4638Ent *tbl28;
} Ke4638Res;

void func_00284638(u8 *base, Ke4638Ev *ev, ScriptCtx *ctx)
{
    u8 mat[0x40];
    Vec4 v;
    u16 *wk;
    u8 *ptrA;
    u32 mode;
    void *base10;
    Ke4638Res *res;
    Ke4638Ent *entA;
    Ke4638Ent *entB;
    u8 *ptrB;
    s32 r;
    s32 idx;
    s32 cnt;

    if (D_006A3BC4 != 0) {
        return;
    }
    r = func_00282628();
    if (ev->b09 == 0xFF) {
        return;
    }
    if ((r >> 8) & ev->b09) {
        return;
    }
    if (ev->w0C == 0xFFFFFFFFU || ev->w14 == 0xFFFFFFFFU) {
        return;
    }
    res = (Ke4638Res *)D_006A3924;
    entA = (Ke4638Ent *)((s32)(ev->h06 << 3) + (s32)res->tbl28);
    wk = SLOT_WORK(u16, base, ctx, 0);
    ptrA = (u8 *)res->tbl20[entA->h00].p14;
    entB = &res->tbl28[ev->h04];
    ptrB = *(u8 **)(base + 0x90);
    if (entB->h02 != entA->h02) {
        return;
    }
    if (ptrB == 0) {
        ptrB = (u8 *)res->tbl20[entB->h00].p14;
    }
    base10 = base + 0x10;
    mode = ev->b0A;
    v.w = 1.0f;
    func_002DD0C0(mat, base10);
    if (mode != 0) {
        idx = r % entB->h02;
    } else {
        idx = *wk;
    }
    cnt = ev->b08;
    for (; cnt > 0; cnt--) {
        T6_MemEnt *e = &ppvMng->p3C[ev->w0C];
        u16 vi = entB->p04[idx];
        T6_Mem *m;
        void *dst1;

        if (e == 0) {
            m = 0;
        } else {
            m = func_00267320(ppvMng, e);
            if (m == 0) {
                return;
            }
            m->user = (ScriptWork *)base;
        }
        {
            s32 off = vi * 6;
            void *dst0 = (u8 *)m + (ev->w10 + 0xA0);
            s16 *vp = (s16 *)(ptrB + off);
            dst1 = (u8 *)m + (ev->w18 + 0xA0);
            v.x = vp[0];
            v.y = vp[1];
            v.z = vp[2];
            func_002DCE08(dst0, base10, &v);
            vp = (s16 *)(ptrA + off);
            v.x = vp[0];
            v.y = vp[1];
            v.z = vp[2];
        }
        func_002DCE08(&v, mat, &v);
        func_00282810((s32)dst1, (s32)&v, (s32)(base + 0x40));
        if (mode != 0) {
            idx = func_00282628() % entB->h02;
        } else {
            idx++;
            if (idx >= entB->h02) {
                idx = 0;
            }
        }
    }
    *wk = idx;
}

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

typedef struct KeEvB {
    u8 pad0[0xC];
    int idx;
    int ofs10;
    u8 pad14[4];
    int ofs18;
} KeEvB;

void func_00284B38(char *base, void *p, void *entry, int *out)
{
    KeEvB *ev = p;
    s16 *pos = entry;
    T6_Mem **mp = (T6_Mem **)out;
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
    at = (char *)*mp + (ev->ofs10 + 0xA0);
    dir = (char *)*mp + (ev->ofs18 + 0xA0);
    func_002DCE08(&v, base + 0x10, &v);
    func_00282798(at, &v);
    func_002DD038(&v, &v, (Vec4 *)(base + 0x40));
    func_002DCEC8(&v, &v);
    func_00282798(dir, &v);
}

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

typedef struct KeEvC {
    u8 pad0[8];
    float f8;
    u8 padC[4];
    int idx;
    int ofs14;
    u8 pad18[4];
    int ofs1C;
    u8 pad20[4];
    int ofs24;
} KeEvC;

void func_00284D28(char *base, void *p, void *entry, int *out)
{
    KeEvC *ev = p;
    s16 *pos = entry;
    T6_Mem **mp = (T6_Mem **)out;
    T6_MemEnt *e = &ppvMng->p3C[ev->idx];
    T6_Mem *m;
    char *dir;
    char *at;
    char *norm;
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
    norm = (char *)*mp + (ev->ofs24 + 0xA0);
    func_002DCE08(&v, base + 0x10, &v);
    func_00282798(at, &v);
    func_002DD038(&v, &v, (Vec4 *)(base + 0x40));
    func_002DCEC8(&v, &v);
    func_00282798(norm, &v);
    func_002DD068(&v, &v, ev->f8);
    func_00282798(dir, &v);
}

typedef struct Ke4E70Ev {
    s32 w00;
    s16 h04;
    s16 pad06;
    float f08;
    u8 b0C;
    u8 b0D;
    u8 b0E;
    u8 pad0F;
    u32 w10;
    s32 w14;
    u32 w18;
    s32 w1C;
    u32 w20;
    s32 w24;
} Ke4E70Ev;

void func_00284E70(u8 *base, Ke4E70Ev *ev, ScriptCtx *ctx)
{
    Vec4 v;
    u16 *wk;
    u32 mode;
    Ke4638Res *res;
    Ke4638Ent *ent;
    void *ptr;
    s32 r;
    s32 idx;
    s32 cnt;

    if (D_006A3BC4 == 0) {
        if (ev->b0D != 0xFF) {
            if (!((func_00282628() >> 8) & ev->b0D)) {
                if (ev->w10 == 0xFFFFFFFFU || ev->w18 == 0xFFFFFFFFU || ev->w20 == 0xFFFFFFFFU) {
                    return;
                }
                if (func_0027F180((char *)base, ev, func_00284D28, &SLOT_WORK(Wkh0h2, base, ctx, 0)->h0, ev->h04, ev->b0E, ev->b0C) == 0) {
                    return;
                }
            }
        }
        if (D_006A3BC4 != 0) {
            return;
        }
        r = func_00282628();
        if (ev->b0D == 0xFF) {
            return;
        }
        if ((r >> 8) & ev->b0D) {
            return;
        }
        if (ev->w10 == 0xFFFFFFFFU || ev->w18 == 0xFFFFFFFFU || ev->w20 == 0xFFFFFFFFU) {
            return;
        }
        res = (Ke4638Res *)D_006A3924;
        wk = SLOT_WORK(u16, base, ctx, 0);
        ent = &res->tbl28[ev->h04];
        ptr = *(void **)(base + 0x90);
        if (ptr == 0) {
            ptr = res->tbl20[ent->h00].p14;
        }
        mode = ev->b0E;
        if (mode != 0) {
            idx = r % ent->h02;
        } else {
            idx = *wk;
        }
        cnt = ev->b0C;
        for (; cnt > 0; cnt--) {
            T6_MemEnt *e = &ppvMng->p3C[ev->w10];
            T6_Mem *m;
            u16 vi;
            s16 *vp;
            void *at;
            void *dir;
            void *norm;

            if (e == 0) {
                m = 0;
            } else {
                m = func_00267320(ppvMng, e);
                if (m == 0) {
                    return;
                }
                m->user = (ScriptWork *)base;
            }
            vi = ent->p04[idx];
            at = (u8 *)m + (ev->w14 + 0xA0);
            dir = (u8 *)m + (ev->w1C + 0xA0);
            norm = (u8 *)m + (ev->w24 + 0xA0);
            vp = (s16 *)((u8 *)ptr + vi * 6);
            v.x = vp[0];
            v.y = vp[1];
            v.z = vp[2];
            v.w = 1.0f;
            func_002DCE08(&v, base + 0x10, &v);
            func_00282798(at, &v);
            func_002DD038(&v, &v, (Vec4 *)(base + 0x40));
            func_002DCEC8(&v, &v);
            func_00282798(norm, &v);
            func_002DD068(&v, &v, ev->f08);
            func_00282798(dir, &v);
            if (mode != 0) {
                idx = func_00282628() % ent->h02;
            } else {
                idx++;
                if (idx >= ent->h02) {
                    idx = 0;
                }
            }
        }
        *wk = idx;
    }
}

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

extern double D_005743F8;
extern double D_00574400;
double func_002EBF18(double a, double b);
int func_002EC2A0(double a);

void func_00285540(char *base, void *p, void *entry, int *out)
{
    KeEvB *ev = p;
    s16 *pos = entry;
    T6_Mem **mp = (T6_Mem **)out;
    T6_MemEnt *e = &ppvMng->p3C[ev->idx];
    T6_Mem *m;
    int *rot;
    char *at;
    Vec4 v;
    float ang;
    float vx;
    float vy;

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
    at = (char *)*mp + (ev->ofs10 + 0xA0);
    func_00282798(at, &v);
    vy = v.y;
    rot = (int *)((char *)*mp + (ev->ofs18 + 0xA0));
    vx = v.x;
    v.y = vx;
    v.x = -vy;
    if (func_002853C0((float *)&v, &ang) != 0) {
        register double x __asm__("$2") = func_002ED038(ang * 32768.0f);
        register double d __asm__("$5");
        __asm__ volatile(".set noat; lui $1, %%hi(D_005743F8); ld %0, %%lo(D_005743F8)($1); .set at" : "=r"(d));
        rot[2] = func_002EC2A0(func_002EBF18(x, d));
    }
    v.x = func_00282A58(vy * vy + vx * vx);
    v.y = -v.z;
    if (func_002853C0((float *)&v, &ang) != 0) {
        register double x __asm__("$2") = func_002ED038(ang * 32768.0f);
        register double d __asm__("$5");
        __asm__ volatile(".set noat; lui $1, %%hi(D_00574400); ld %0, %%lo(D_00574400)($1); .set at" : "=r"(d));
        rot[0] = func_002EC2A0(func_002EBF18(x, d));
    }
    rot[1] = 0;
}
