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

typedef struct F4bTri {
    u_long64 tag00;
    u8 pad08;
    s8 b09;
    u8 pad0A[6];
    u8 uv0[0x0C];
    s8 a0;
    u8 pad1D[3];
    u8 uv1[0x0C];
    s8 a1;
    u8 pad2D[3];
    u8 uv2[0x0C];
    s8 a2;
    u8 pad3D[3];
    u_long128 v0;
    u_long128 v1;
    u_long128 v2;
    u_long128 center;
} F4bTri; /* size 0x80 */

typedef struct F4bTris {
    u16 count;
    u8 pad02[0x3E];
    F4bTri ents[1];
} F4bTris;

typedef struct F4bSub {
    u8 pad00[0xC2];
    u8 bC2;
    u8 bC3;
} F4bSub;

typedef struct F4bNode {
    u8 pad00[0x30];
    float f30;
    float f34;
    u8 pad38[0x58];
    u_long128 v90;
} F4bNode;

typedef struct F4bBuf {
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
    u_long128 tag1;
    u_long128 tag2;
    u8 pad1130[0xD0];
    float f1200;
    float f1204;
    float f1208;
    u32 pad120C;
    u_long128 v1210;
    u8 pad1220[0x60];
    float d0[4];
    float d1[4];
    float d2[4];
} F4bBuf;

extern u_long128 D_006F2CE0[];
extern u_long128 D_006F2D90[];
extern u32 D_003F395C;
extern u32 D_006F2E60[];

void *func_002B3888(s32 size);
u32 func_002DA610(s32 a0, s32 a1);
void func_002DBA28(u32 a0, u32 a1);
void func_002B56D8(void *dst, void *a, void *b);
void func_002B21E8(void);
void func_002B39C0(s32 size);

static inline void d2_wait(void)
{
wait:
    if (*(volatile u32 *)0x1000A000 & 0x100) {
        goto wait;
    }
}

static inline void d2_kick(void *tag)
{
    register u32 tadr __asm__("$5") = (u8 *)tag - (u8 *)0x80000000;
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

void func_01B08E08(F4bTris *tris, F4bSub *sub_arg, F4bNode *node, void *mtx0_arg, void *mtx1_arg, void *mtx2_arg)
{
    register F4bSub *sub __asm__("$18") = sub_arg;
    register void *mtx0 __asm__("$22") = mtx0_arg;
    register void *mtx1 __asm__("$21") = mtx1_arg;
    register void *mtx2 __asm__("$20") = mtx2_arg;
    F4bBuf *buf;
    register u_long128 *t_ce0 __asm__("$16");
    register u_long128 *t_d90 __asm__("$17");
    register F4bBuf *buf2 __asm__("$19");

    buf = (F4bBuf *)func_002B3888(0x1300);
    *(u_long64 *)((u8 *)buf + 0x00) = 0x70000002ULL;
    *(u_long64 *)((u8 *)buf + 0x08) = 0;
    *(u_long64 *)((u8 *)buf + 0x10) = 0x1000000000008001ULL;
    *(u_long64 *)((u8 *)buf + 0x18) = 0xEEEEEEEEULL;
    t_ce0 = D_006F2CE0;
    t_d90 = D_006F2D90;
    __asm__("" : "=r"(buf2) : "0"(buf));
    *(u32 *)((u8 *)buf + 0x20) = sub->bC2;
    *(u32 *)((u8 *)buf + 0x24) = sub->bC3;
    *(u_long64 *)((u8 *)buf + 0x28) = 0x42ULL;
    func_002DA610(0, 0);
    {
        register u32 a1_hi __asm__("$5") = 0x80000000;
        u32 a0_arg = D_003F395C;
        __asm__ volatile("" : "+r"(a1_hi));
        func_002DBA28(a0_arg, (u32)buf | a1_hi);
    }
    func_002DA610(0, 0);

    {
        u_long128 q3 = t_ce0[3];
        register u8 *p1100 __asm__("$8") = (u8 *)buf + 0x1100;
        register u_long64 tag_lo __asm__("$2") = 0xB02DC00000000001ULL;
        register u_long64 tag_hi __asm__("$7") = 0x0412412412EEULL;
        __asm__ volatile("" : "+r"(p1100), "+r"(tag_lo), "+r"(tag_hi));
        *(u_long128 *)(p1100 + 0x10) = q3;
        *(u_long64 *)((u8 *)buf + 0x1100) = tag_lo;
        *(u_long64 *)(p1100 + 0x08) = tag_hi;
        *(u_long128 *)(p1100 + 0x20) = t_d90[3];
    }
    func_002B56D8(buf, mtx2, mtx1);
    __asm__ volatile("" : "+r"(buf2));
    {
        void *v90p = &node->v90;
        __asm__ volatile("" : "+r"(v90p));
        VU0_LQC2(12, 0x00, mtx0);
        VU0_LQC2(13, 0x10, mtx0);
        VU0_LQC2(14, 0x20, mtx0);
        VU0_LQC2(15, 0x30, mtx0);
        VU0_LQC2(16, 0x00, buf2);
        VU0_LQC2(17, 0x10, buf2);
        VU0_LQC2(18, 0x20, buf2);
        VU0_LQC2(19, 0x30, buf2);
        VU0_LQC2(20, 0x1200, buf2);
        VU0_LQC2(21, 0x00, v90p);
    }

    buf->f1200 = node->f30;
    {
        float diff = *(volatile float *)&node->f30 - node->f34;
        if (diff < 0.0f) {
            diff = 0.0f;
        }
        buf->f1204 = diff;
    }
    if (node->f34 >= 0.1f) {
        buf->f1208 = 128.0f / node->f34;
    } else {
        buf->f1208 = 0.0f;
    }
    buf->v1210 = node->v90;

    MMI_SQ_ZERO(0x1020, buf);
    MMI_SQ_ZERO(0x1030, buf);

    {
        register u32 ir __asm__("$14") = 0;
        register F4bTri *tr __asm__("$12");
        register u32 nvert_r __asm__("$13");
        F4bTris *tp = tris;
        u32 p10 = (u32)((u8 *)buf + 0x10);
        u32 cnt0;

        *(volatile u32 *)&buf->pkt_cur = p10;
        cnt0 = tp->count;
        tr = tp->ents;
        *(volatile u32 *)&buf->pkt_start = p10;
        nvert_r = 0;
        if (cnt0 != 0) {
            do {
                register u32 a0_z __asm__("$4") = 0;
                __asm__ volatile("" : "+r"(a0_z));

                VU0_LQC2(24, 0x40, tr);
                VU0_OP("vsub.xyz $vf24xyz, $vf24xyz, $vf21xyz");
                VU0_OP("vmul.xyz $vf24xyz, $vf24xyz, $vf24xyz");
                VU0_OP("vaddy.z $vf24z, $vf24z, $vf24y");
                VU0_OP("vsqrt Q, $vf24z");
                VU0_OP("vwaitq");
                VU0_OP("vaddq.x $vf24x, $vf0x, Q");
                VU0_SQC2(24, 0x1280, buf);

                VU0_LQC2(25, 0x50, tr);
                VU0_OP("vsub.xyz $vf25xyz, $vf25xyz, $vf21xyz");
                VU0_OP("vmul.xyz $vf25xyz, $vf25xyz, $vf25xyz");
                VU0_OP("vaddy.z $vf25z, $vf25z, $vf25y");
                VU0_OP("vsqrt Q, $vf25z");
                VU0_OP("vwaitq");
                VU0_OP("vaddq.x $vf25x, $vf0x, Q");
                VU0_SQC2(25, 0x1290, buf);

                VU0_LQC2(26, 0x60, tr);
                VU0_OP("vsub.xyz $vf26xyz, $vf26xyz, $vf21xyz");
                VU0_OP("vmul.xyz $vf26xyz, $vf26xyz, $vf26xyz");
                VU0_OP("vaddy.z $vf26z, $vf26z, $vf26y");
                VU0_OP("vsqrt Q, $vf26z");
                VU0_OP("vwaitq");
                VU0_OP("vaddq.x $vf26x, $vf0x, Q");
                VU0_SQC2(26, 0x12A0, buf);

                {
                    register float r0 __asm__("$f0") = buf->f1200;
                    register float r1 __asm__("$f2") = buf->f1204;
                    register float sc __asm__("$f3") = buf->f1208;
                    register float d __asm__("$f1");

                    __asm__ volatile("" : "+f"(r0), "+f"(r1), "+f"(sc));
                    tr->b09 = 0;

                    d = buf->d0[0];
                    if (d >= r0) {
                        d = 0.0f;
                    } else if (d <= r1) {
                        d = 128.0f;
                    } else {
                        d = r0 - d;
                        {
                            register u32 one __asm__("$2") = 1;
                            __asm__ volatile("" : "+r"(one));
                            tr->b09 = one;
                        }
                        d *= sc;
                    }
                    tr->a0 = (s8)(s32)d;

                    d = buf->d1[0];
                    if (d >= r0) {
                        d = 0.0f;
                    } else if (d <= r1) {
                        d = 128.0f;
                    } else {
                        d = r0 - d;
                        {
                            register u32 one __asm__("$2") = 1;
                            __asm__ volatile("" : "+r"(one));
                            tr->b09 = one;
                        }
                        d *= sc;
                    }
                    tr->a1 = (s8)(s32)d;

                    d = buf->d2[0];
                    if (d >= r0) {
                        d = 0.0f;
                    } else if (d <= r1) {
                        d = 128.0f;
                    } else {
                        d = r0 - d;
                        {
                            register u32 one __asm__("$2") = 1;
                            __asm__ volatile("" : "+r"(one));
                            tr->b09 = one;
                        }
                        d *= sc;
                    }
                    {
                        register s32 a2v __asm__("$11") = (s32)d;
                        tr->a2 = (s8)a2v;
                    }
                }

                {
                    register u8 *t1 __asm__("$9") = (u8 *)buf->pkt_cur;
                    register u32 v0 __asm__("$2");
                    register u_long128 qcol __asm__("$2");
                    register s32 b0 __asm__("$2");
                    register s32 b1 __asm__("$3");
                    register s32 b2 __asm__("$4");
                    register F4bTri *next_tr __asm__("$10");
                    register u32 next_ir __asm__("$9");
                    register u32 tri_cnt __asm__("$11");

                    buf->last_giftag = (u32)t1;
                    __asm__ volatile("" : : : "memory");
                    *(u_long128 *)t1 = buf->tag0;
                    __asm__ volatile("" : "+r"(t1) : : "memory");
                    t1 += 0x10;

                    VU0_LQC2(24, 0x40, tr);
                    VU0_LQC2(25, 0x50, tr);
                    VU0_LQC2(26, 0x60, tr);

                    VU0_OP("vmulax.xyzw ACC, $vf16, $vf24x");
                    VU0_OP("vmadday.xyzw ACC, $vf17, $vf24y");
                    VU0_OP("vmaddaz.xyzw ACC, $vf18, $vf24z");
                    VU0_OP("vmaddw.xyzw $vf24, $vf19, $vf0w");
                    VU0_OP("vdiv Q, $vf0w, $vf24w");
                    VU0_OP("vwaitq");
                    VU0_OP("vmulq.xyz $vf24xyz, $vf24xyz, Q");
                    VU0_OP("vmulq.w $vf24w, $vf0w, Q");

                    VU0_OP("vmulax.xyzw ACC, $vf16, $vf25x");
                    VU0_OP("vmadday.xyzw ACC, $vf17, $vf25y");
                    VU0_OP("vmaddaz.xyzw ACC, $vf18, $vf25z");
                    VU0_OP("vmaddw.xyzw $vf25, $vf19, $vf0w");
                    VU0_OP("vdiv Q, $vf0w, $vf25w");
                    VU0_OP("vwaitq");
                    VU0_OP("vmulq.xyz $vf25xyz, $vf25xyz, Q");
                    VU0_OP("vmulq.w $vf25w, $vf0w, Q");

                    VU0_OP("vmulax.xyzw ACC, $vf16, $vf26x");
                    VU0_OP("vmadday.xyzw ACC, $vf17, $vf26y");
                    VU0_OP("vmaddaz.xyzw ACC, $vf18, $vf26z");
                    VU0_OP("vmaddw.xyzw $vf26, $vf19, $vf0w");
                    VU0_OP("vdiv Q, $vf0w, $vf26w");
                    VU0_OP("vwaitq");
                    VU0_OP("vmulq.xyz $vf26xyz, $vf26xyz, Q");
                    VU0_OP("vmulq.w $vf26w, $vf0w, Q");

                    VU0_OP("vftoi4.xyz $vf24xyz, $vf24xyz");
                    VU0_OP("vftoi4.xyz $vf25xyz, $vf25xyz");
                    VU0_OP("vftoi4.xyz $vf26xyz, $vf26xyz");
                    VU0_SQC2(24, 0x40, t1);
                    VU0_SQC2(25, 0x70, t1);
                    VU0_SQC2(26, 0xA0, t1);
                    *(u32 *)(t1 + 0x4C) = 0;
                    *(u32 *)(t1 + 0x7C) = 0;
                    *(u32 *)(t1 + 0xAC) = 0;
                    __asm__ volatile("" : : : "memory");

                    VU0_LQC2(28, 0x10, tr);
                    VU0_LQC2(29, 0x20, tr);
                    VU0_LQC2(30, 0x30, tr);
                    VU0_OP("vmulw.xyz $vf28xyz, $vf28xyz, $vf24w");
                    VU0_OP("vmulw.xyz $vf29xyz, $vf29xyz, $vf25w");
                    VU0_OP("vmulw.xyz $vf30xyz, $vf30xyz, $vf26w");
                    VU0_SQC2(28, 0x20, t1);
                    VU0_SQC2(29, 0x50, t1);
                    VU0_SQC2(30, 0x80, t1);

                    *(u_long64 *)(t1 + 0x00) = tr->tag00;
                    __asm__ volatile("" : : : "memory");
                    *(u_long64 *)(t1 + 0x08) = 6;
                    __asm__ volatile("" : : : "memory");
                    {
                        register u_long128 q2 __asm__("$3") = buf->tag2;
                        *(u_long128 *)(t1 + 0x10) = q2;
                    }
                    __asm__ volatile("" : : : "memory");

                    v0 = 0x80808080;
                    MMI_OP2Z("pextlb", qcol, v0);
                    MMI_OP2Z("pextlh", qcol, qcol);
                    *(u_long128 *)(t1 + 0x30) = qcol;
                    *(u_long128 *)(t1 + 0x60) = qcol;
                    __asm__ volatile("" : : : "memory");
                    *(u_long128 *)(t1 + 0x90) = qcol;

                    b0 = tr->a0;
                    b1 = tr->a1;
                    b2 = tr->a2;
                    __asm__ volatile("" : "+r"(b0), "+r"(b1), "+r"(b2));
                    t1[0x3C] = b0;
                    t1[0x6C] = b1;
                    t1[0x9C] = b2;
                    t1 += 0xB0;
                    __asm__ volatile("" : "+r"(t1));
                    nvert_r++;
                    buf->pkt_cur = (u32)t1;
                    __asm__ volatile("" : : : "memory");

                    {
                        register s32 lt8 __asm__("$11") = ((s32)nvert_r < 8);
                        if (!lt8) {
                            register u8 *start __asm__("$8");
                            register u8 *cur __asm__("$2");
                            register s32 diff __asm__("$6");
                            register s32 qwc __asm__("$3");
                            register u32 idx __asm__("$6");
                            register u32 tot __asm__("$7");

                            start = (u8 *)buf->last_giftag;
                            *(u32 *)start |= 0x8000;
                            start = (u8 *)buf->pkt_start;
                            cur = (u8 *)buf->pkt_cur;
                            diff = cur - start;
                            __asm__ volatile("" : "+r"(diff));
                            start -= 0x10;
                            MMI_SQ_ZERO(0, start);
                            {
                                s32 neg1 = -1;
                                register u32 tag_hi __asm__("$4");
                                register u32 tagw __asm__("$6");
                                register F4bTris *tp2 __asm__("$2");
                                __asm__ volatile("" : "+r"(neg1));
                                qwc = diff + 15;
                                __asm__ volatile("" : "+r"(qwc));
                                tag_hi = 0x70000000;
                                if (diff > neg1) {
                                    qwc = diff;
                                }
                                next_tr = tr + 1;
                                qwc >>= 4;
                                tp2 = tris;
                                __asm__ volatile("" : "+r"(next_tr), "+r"(qwc), "+r"(tp2));
                                tagw = qwc + tag_hi;
                                next_ir = ir + 1;
                                *(volatile u32 *)start = tagw;
                                tri_cnt = *(volatile u16 *)&tp2->count;
                            }
                            __asm__ volatile("" : "+r"(next_ir), "+r"(tri_cnt));
                            idx = buf->buf_idx;
                            tot = buf->total_verts;
                            d2_wait();
                            d2_kick(start);
                            __asm__ volatile("" : "+r"(idx), "+r"(tot));
                            idx = (idx + 1) & 1;
                            {
                                register u32 new_tot __asm__("$3") = tot + nvert_r;
                                buf->total_verts = new_tot;
                            }
                            buf->buf_idx = idx;
                            {
                                register u32 next __asm__("$2") = (u32)((u8 *)buf + (idx << 11));
                                nvert_r = 0;
                                buf->pkt_start = next;
                                __asm__ volatile("" : : : "memory");
                                buf->pkt_cur = next;
                            }
                            goto next_tri;
                        }
                    }
                    {
                        register F4bTris *tp_else __asm__("$3") = tris;
                        __asm__ volatile("" : "+r"(tp_else));
                        next_tr = tr + 1;
                        next_ir = ir + 1;
                        tri_cnt = tp_else->count;
                    }
                    __asm__ volatile("" : "+r"(next_tr), "+r"(next_ir), "+r"(tri_cnt));
                next_tri:
                    ir = next_ir;
                    tr = next_tr;
                    {
                        register s32 cmp __asm__("$2") = ((s32)ir < (s32)tri_cnt);
                        if (cmp) {
                            continue;
                        }
                    }
                    break;
                }
            } while (1);
        }

        if (nvert_r != 0) {
            register u8 *start __asm__("$8");
            register u8 *cur __asm__("$2");
            register s32 diff __asm__("$6");
            register u32 tot __asm__("$7");

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
        }
        D_006F2E60[1] += buf->total_verts;
        D_006F2E60[4] += buf->total_verts;
    }

    d2_wait();
    func_002B21E8();
    func_002B39C0(0x1300);
}
