#include "common.h"
#include "vu0.h"

typedef unsigned long u_long64;

typedef struct DmaChanRegs {
    u8 pad0000[0x2000];
    u32 chcr;
    u8 pad2004[0x1C];
    u32 qwc;
    u8 pad2024[0xC];
    u32 tadr;
} DmaChanRegs;

typedef struct F7Particle {
    u16 h00;
    u8 b02;
    u8 pad03[5];
    float f08;
    float f0C;
    float f10;
    float f14;
    float f18;
    s16 h1C;
    s16 h1E;
    u_long128 v20;
} F7Particle; /* size 0x30 */

typedef struct F7Pool {
    u32 count;
    u32 cur_idx;
    u8 pad08[8];
    F7Particle ents[1];
} F7Pool;

typedef struct F7EmitEntry {
    u8 pad00[9];
    s8 b09;
    u8 pad0A[0x66];
    float f70;
    float f74;
    float f78;
    u8 pad7C[4];
} F7EmitEntry; /* size 0x80 */

typedef struct F7EmitList {
    u16 count;
    u8 pad02[0x3E];
    F7EmitEntry ents[1];
} F7EmitList;

typedef struct F7Sub {
    u8 pad00[0x30];
    float f30;
    float f34;
    u8 pad38[4];
    float f3C;
    float f40;
    float f44;
    float f48;
    float f4C;
    u8 pad50[0x72];
    u8 bC2;
    u8 bC3;
} F7Sub;

typedef struct F7Node {
    u8 pad00[0x30];
    float f30;
    float f34;
    u8 pad38[0x58];
    union {
        u_long128 q;
        float f[4];
    } v90;
} F7Node;

typedef struct F7Buf {
    u8 data[0x1020];
    u32 u1020;
    u32 total_verts;
    u32 u1028;
    u32 u102C;
    u32 buf_idx;
    u32 u1034;
    u32 u1038;
    u32 u103C;
    u32 pkt_start;
    u32 pkt_cur;
    u32 last_giftag;
    u8 pad104C[0xB4];
    u_long128 tag0;
} F7Buf;

extern u_long128 D_006F2CE0[];
extern u32 D_003F395C;
extern float D_004F4610[];
extern u32 D_006F2E60[];

void *func_002B3888(s32 size);
u32 func_002DA610(s32 a0, s32 a1);
void func_002DBA28(u32 a0, u32 a1);
float func_002B3DB0(float a0);
float func_002B6190(float *a0, float f0, float f1, float f2, float f3);
void func_002B21E8(void);
void func_002B39C0(s32 size);

static inline void d2_wait(void)
{
wait:
    if (*(volatile u32 *)0x1000A000 & 0x100) {
        goto wait;
    }
}

static inline void d2_wait_ptr(volatile u32 *chcr)
{
wait:
    if (*chcr & 0x100) {
        goto wait;
    }
}

static inline void d2_kick_kseg(void *tag, u8 *kseg)
{
    register u32 tadr __asm__("$5") = (u8 *)tag - kseg;
    register volatile DmaChanRegs *dma __asm__("$2");
    u32 dummy;
    u32 chcr;
    __asm__ volatile("" : "+r"(tadr));
    dma = (volatile DmaChanRegs *)0x10008000;
    __asm__ volatile("" : "+r"(dma));
    dummy = 4;
    chcr = 0x105;
    __asm__ volatile("" : "+r"(dummy), "+r"(chcr));
    dma->qwc = 0;
    dma->tadr = tadr;
    dma->chcr = chcr;
}

static inline void d2_kick(void *tag)
{
    d2_kick_kseg(tag, (u8 *)0x80000000);
}

void func_01B094D8(F7Pool *pool_arg, F7EmitList *emit, F7Sub *sub, F7Node *node_arg, void *mtx1_arg, void *mtx2_arg, s32 flag)
{
    register F7Pool *pool __asm__("$23") = pool_arg;
    register F7Node *node __asm__("$21") = node_arg;
    register void *mtx1 __asm__("$17") = mtx1_arg;
    register void *mtx2 __asm__("$16") = mtx2_arg;
    F7Buf *buf;
    F7Particle *p;
    u32 i;
    s32 nvert;

    buf = (F7Buf *)func_002B3888(0x1300);
    *(u_long64 *)((u8 *)buf + 0x00) = 0x70000004ULL;
    *(u_long64 *)((u8 *)buf + 0x08) = 0;
    *(u_long64 *)((u8 *)buf + 0x10) = 0x3000000000008001ULL;
    *(u_long64 *)((u8 *)buf + 0x18) = 0xEEEEEEEEULL;
    *(u32 *)((u8 *)buf + 0x20) = sub->bC2;
    *(u32 *)((u8 *)buf + 0x24) = sub->bC3;
    *(u_long64 *)((u8 *)buf + 0x28) = 0x42ULL;
    *(u_long128 *)((u8 *)buf + 0x30) = D_006F2CE0[3];
    *(u_long64 *)((u8 *)buf + 0x40) = 0x3000DULL;
    *(u_long64 *)((u8 *)buf + 0x48) = 0x47ULL;
    {
        register u32 d0 __asm__("$2") = func_002DA610(0, 0);
        register u32 a1_hi __asm__("$5") = 0x80000000;
        u32 a0_arg = D_003F395C;
        __asm__ volatile("" : "+r"(a1_hi) : "r"(d0));
        func_002DBA28(a0_arg, (u32)buf | a1_hi);
    }
    func_002DA610(0, 0);

    {
        register u_long64 t_lo __asm__("$3") = 0x2024400000000001ULL;
        register u_long64 t_hi __asm__("$4") = 0x41ULL;
        register void *v90p __asm__("$2");
        __asm__ volatile("" : "+r"(t_lo), "+r"(t_hi));
        *(u_long64 *)((u8 *)buf + 0x1100) = t_lo;
        v90p = &node->v90;
        __asm__ volatile("" : "+r"(v90p));
        *(u_long64 *)((u8 *)buf + 0x1108) = t_hi;

        VU0_LQC2(12, 0x00, mtx1);
        VU0_LQC2(13, 0x10, mtx1);
        VU0_LQC2(14, 0x20, mtx1);
        VU0_LQC2(15, 0x30, mtx1);
        VU0_LQC2(16, 0x00, mtx2);
        VU0_LQC2(17, 0x10, mtx2);
        VU0_LQC2(18, 0x20, mtx2);
        VU0_LQC2(19, 0x30, mtx2);
        VU0_LQC2(21, 0x00, v90p);
    }

    if (flag == 0) {
        u32 em_cnt = emit->count;
        s32 acc = 0;
        register s32 ei __asm__("$11") = 0;

        __asm__ volatile("" : "+r"(ei));
        if (em_cnt != 0) {
            register F7EmitEntry *e __asm__("$17") = emit->ents;
            do {
                register F7EmitEntry *next_e __asm__("$22");
                register s32 next_ei __asm__("$20");
                if (e->b09 != 0) {
                    acc += (s32)sub->f3C;
                    if (acc > 0) {
                        next_ei = ei + 1;
                        next_e = e + 1;
                        __asm__ volatile("" : "+r"(next_ei), "+r"(next_e));
                        do {
                            F7Particle *p_base = pool->ents;
                            register u32 stride __asm__("$5") = 48;
                            register u32 rem __asm__("$4") = pool->cur_idx % pool->count;
                            register float f2 __asm__("$f20") = 2.0f;
                            register float f256 __asm__("$f22") = 1.0f / 256.0f;
                            F7Particle *pt;
                            float r;

                            __asm__("" : "+r"(rem));
                            pt = (F7Particle *)((u8 *)p_base + rem * stride);
                            pt->f10 = e->f70 + func_002B3DB0(f2);
                            pt->f14 = sub->f40 * f256;
                            pt->f18 = sub->f44 * (1.0f / 4096.0f);
                            r = func_002B6190(&pt->f08, node->v90.f[1], node->v90.f[2], e->f74, e->f78);
                            pt->f08 = (node->f30 - node->f34) + func_002B3DB0(f2);
                            pt->f0C = (sub->f48 + func_002B3DB0(sub->f48 * (1.0f / 64.0f))) * f256;
                            pt->h1C = (s16)(s32)r;
                            pt->h1E = (s16)((float)(s16)(s32)(sub->f30 + func_002B3DB0(sub->f34)) * f256);
                            pt->v20 = node->v90.q;
                            __asm__ volatile("" : "+r"(acc) : : "memory");
                            acc -= 256;
                            pool->cur_idx++;
                            pt->h00 = (u16)(s32)sub->f4C;
                        } while (acc > 0);
                        em_cnt = emit->count;
                        goto next_emit;
                    }
                }
                next_e = e + 1;
                next_ei = ei + 1;
                __asm__ volatile("" : "+r"(next_ei), "+r"(next_e));
            next_emit:
                ei = next_ei;
                e = next_e;
            } while (ei < (s32)em_cnt);
        }
    }

    MMI_SQ_ZERO(0x1020, buf);
    MMI_SQ_ZERO(0x1030, buf);

    {
        register u32 ir __asm__("$11") = 0;
        register F7Particle *pr __asm__("$16");
        register u32 nvert_r __asm__("$12");

        {
            buf->pkt_cur = (u32)((u8 *)buf + 0x10);
            __asm__ volatile("" : : : "memory");
            pr = pool->ents;
            __asm__ volatile("" : "+r"(pr) : : "memory");
            buf->pkt_start = (u32)((u8 *)buf + 0x10);
        }
        nvert_r = 0;
        if (pool->count != 0) {
            float *sin_tbl = D_004F4610;
            register u32 c128 __asm__("$19") = 128;
            register s32 neg1 __asm__("$17") = -1;
            register u32 tag_hi __asm__("$15") = 0x70000000;
            register volatile u32 *d2_chcr __asm__("$13") = (volatile u32 *)0x1000A000;
            register u8 *kseg __asm__("$14") = (u8 *)0x80000000;
            __asm__ volatile("" : "+r"(sin_tbl), "+r"(c128), "+r"(neg1));
            __asm__ volatile("" : "+r"(tag_hi), "+r"(d2_chcr), "+r"(kseg));

            do {
                if (pr->h00 != 0) {
                    register u8 *t1 __asm__("$9");
                    register s32 ang __asm__("$10");
                    register u32 v0 __asm__("$2");
                    register u32 v1 __asm__("$3");
                    register u_long64 sc __asm__("$3");
                    register u_long128 qcol __asm__("$2");
                    register s32 b02 __asm__("$2");
                    register s32 fl __asm__("$2") = flag;
                    __asm__ volatile("" : "+r"(fl));

                    if (fl == 0) {
                        pr->f14 += pr->f18;
                        pr->h00--;
                        pr->f08 += pr->f0C;
                        pr->f10 += pr->f14;
                        pr->h1C += pr->h1E;
                        if (pr->h00 >= 32) {
                            pr->b02 = c128;
                        } else {
                            pr->b02 = (pr->h00 * 128) / 32;
                        }
                    }

                    __asm__ volatile("" : : : "memory");
                    t1 = (u8 *)buf->pkt_cur;
                    buf->last_giftag = (u32)t1;
                    ang = pr->h1C;
                    __asm__ volatile("" : "+r"(ang) : : "memory");
                    *(u_long128 *)t1 = buf->tag0;
                    __asm__ volatile("" : "+r"(t1) : : "memory");
                    t1 += 0x10;

                    __asm__ volatile("dsll %0, %1, 2" : "=r"(v0) : "r"(ang));
                    v0 &= 0x3FFC;
                    v1 = (v0 + 0x1000) & 0x3FFC;
                    MMI_OP3("add", v0, v0, sin_tbl);
                    MMI_OP3("add", v1, v1, sin_tbl);
                    v0 = *(u32 *)v0;
                    v1 = *(u32 *)v1;
                    MMI_OP3("ppacw", sc, v1, v0);
                    __asm__ volatile("dsll32 %0, %1, 0" : "=r"(sc) : "r"(sc));
                    VU0_QMTC2(30, sc);
                    v1 = *(u32 *)&pr->f08;
                    VU0_QMTC2(31, v1);
                    v1 = *(u32 *)&pr->f10;
                    VU0_QMTC2(28, v1);
                    VU0_OP("vmulx.yz $vf31yz, $vf30yz, $vf31x");
                    VU0_OP("vmove.x $vf31x, $vf28x");
                    VU0_LQC2(29, 0x20, pr);
                    VU0_OP("vadd.xyz $vf31xyz, $vf31xyz, $vf29xyz");
                    VU0_OP("vmulax.xyzw ACC, $vf16, $vf31x");
                    VU0_OP("vmadday.xyzw ACC, $vf17, $vf31y");
                    VU0_OP("vmaddaz.xyzw ACC, $vf18, $vf31z");
                    VU0_OP("vmaddw.xyzw $vf31, $vf19, $vf0w");
                    VU0_OP("vdiv Q, $vf0w, $vf31w");
                    VU0_OP("vwaitq");
                    VU0_OP("vmulq.xyz $vf31xyz, $vf31xyz, Q");
                    VU0_OP("vftoi4.xyz $vf31xyz, $vf31xyz");
                    VU0_SQC2(31, 0x10, t1);
                    *(u32 *)(t1 + 0x1C) = 0;
                    __asm__ volatile("" : : : "memory");

                    v0 = 0x80808080;
                    MMI_OP2Z("pextlb", qcol, v0);
                    MMI_OP2Z("pextlh", qcol, qcol);
                    *(u_long128 *)t1 = qcol;
                    b02 = *(s8 *)&pr->b02;
                    __asm__ volatile("" : "+r"(b02));
                    t1[0x0C] = b02;
                    t1 += 0x20;
                    __asm__ volatile("" : "+r"(t1));
                    nvert_r++;
                    buf->pkt_cur = (u32)t1;
                    __asm__ volatile("" : : : "memory");

                    {
                        register s32 lt32 __asm__("$4") = ((s32)nvert_r < 32);
                        if (!lt32) {
                            register u8 *start __asm__("$7");
                            register u8 *cur __asm__("$2");
                            register s32 diff __asm__("$6");
                            register s32 qwc __asm__("$3");
                            register u32 idx __asm__("$6");
                            register u32 tot __asm__("$9");

                            start = (u8 *)buf->last_giftag;
                            *(u32 *)start |= 0x8000;
                            start = (u8 *)buf->pkt_start;
                            cur = (u8 *)buf->pkt_cur;
                            diff = cur - start;
                            __asm__ volatile("" : "+r"(diff));
                            start -= 0x10;
                            MMI_SQ_ZERO(0, start);
                            qwc = diff + 15;
                            if (diff > neg1) {
                                qwc = diff;
                            }
                            {
                                register u32 tagw __asm__("$6") = (qwc >> 4) + tag_hi;
                                *(u32 *)start = tagw;
                            }
                            idx = buf->buf_idx;
                            tot = buf->total_verts;
                        wait_in:
                            if (*d2_chcr & 0x100) {
                                goto wait_in;
                            }
                            __asm__ volatile("" : "+r"(start));
                            d2_kick_kseg(start, kseg);
                            __asm__ volatile("" : "+r"(idx), "+r"(tot));
                            idx = (idx + 1) & 1;
                            {
                                register u32 new_tot __asm__("$3") = tot + nvert_r;
                                buf->total_verts = new_tot;
                            }
                            buf->buf_idx = idx;
                            {
                                register u32 next = (u32)((u8 *)buf + (idx << 11));
                                nvert_r = 0;
                                buf->pkt_start = next;
                                __asm__ volatile("" : : : "memory");
                                buf->pkt_cur = next;
                            }
                        }
                    }
                }
                {
                    register u32 next_i __asm__("$20") = ir + 1;
                    register F7Particle *next_p __asm__("$8") = pr + 1;
                    __asm__ volatile("" : "+r"(next_i), "+r"(next_p));
                    ir = next_i;
                    pr = next_p;
                }
            } while (ir < pool->count);
        }

        {
            register u32 dummy_v0 __asm__("$2");
            __asm__("" : "=r"(dummy_v0));
            if (nvert_r != 0) {
                register u8 *start __asm__("$7");
                register u8 *cur __asm__("$2");
                register s32 diff __asm__("$6");
                register u32 tot __asm__("$9");

                start = (u8 *)buf->last_giftag;
                *(u32 *)start |= 0x8000;
                start = (u8 *)buf->pkt_start;
                cur = (u8 *)buf->pkt_cur;
                diff = cur - start;
                __asm__ volatile("" : "+r"(diff));
                start -= 0x10;
                MMI_SQ_ZERO(0, start);
                {
                    s32 neg1_f = -1;
                    register s32 qwc __asm__("$2");
                    register u32 tag_hi_f __asm__("$4");
                    register u32 tagw __asm__("$6");
                    __asm__ volatile("" : "+r"(neg1_f));
                    qwc = diff + 15;
                    __asm__ volatile("" : "+r"(qwc));
                    tag_hi_f = 0x70000000;
                    if (diff > neg1_f) {
                        qwc = diff;
                    }
                    tagw = (qwc >> 4) + tag_hi_f;
                    *(u32 *)start = tagw;
                }
                tot = buf->total_verts;
                d2_wait();
                d2_kick(start);
                __asm__ volatile("" : "+r"(tot));
                {
                    register u32 new_tot __asm__("$6") = tot + nvert_r;
                    buf->total_verts = new_tot;
                }
                __asm__("" : "=r"(dummy_v0));
            }
            {
                u32 *st = D_006F2E60;
                __asm__("" : "+r"(st) : "r"(dummy_v0));
                st[1] += buf->total_verts;
                st[4] += buf->total_verts;
            }
        }
    }
    d2_wait();
    func_002B21E8();
    func_002B39C0(0x1300);
}
