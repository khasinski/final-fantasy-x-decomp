#include "common.h"
#include "vu0.h"

typedef unsigned long u_long64;

typedef struct S7110Mesh {
    u32 u00;
    u32 u04;
    u32 u08;
    u8 pad0C[6];
    u16 vtx_cnt;
} S7110Mesh;

typedef struct S7110Sub {
    S7110Mesh *mesh;
    void *p04;
} S7110Sub;

typedef struct S7110A0 {
    u32 u00;
    u16 count;
    u8 pad06[10];
    S7110Sub sub;
} S7110A0;

typedef struct S7110Ent {
    float f00;
    float f04;
    float f08;
    s16 h0C;
    s8 b0E;
    u8 pad0F[0x0D];
    s16 h1C;
    u8 pad1E[0x40];
    s16 h5E;
} S7110Ent; /* size 0x60 */

typedef struct S7110A1 {
    u16 max_cnt;
    u16 cur_idx;
    u8 pad04[8];
    s16 *tbl;
    u8 pad10[0x20];
    S7110Ent ents[1];
} S7110A1;

typedef struct S7110Tri {
    u16 i0;
    u16 i1;
    u16 i2;
    u8 pad06[22];
} S7110Tri; /* size 28 */

void func_002B56D8(void *mat, void *a1, void *a2);
float func_002B3DB0(float f);
void func_01B06CA8(void *a0, float *a1, float *a2);

void func_01B07110(S7110A0 *a0, S7110A1 *a1, void *a2, void *a3, float (*vbuf)[4], float f12)
{
    u_long128 mat[4];
    float vec1[4];
    float vec2[4];
    S7110Sub *sub = &a0->sub;
    s32 tri_idx = 0;
    s32 i = 0;

    if ((s32)a0->count > 0) {
        i = 0;
        do {
        S7110Mesh *mesh = sub->mesh;
        u8 *vsrc = (u8 *)mesh + mesh->u08;
        u8 *sec;

        func_002B56D8(mat, a3, sub->p04);
        {
            register u32 dead_a1 __asm__("$5") = 0x70003F00;
            register float (*vb_tmp)[4] __asm__("$6") = vbuf;
            register u_long64 dead_t1 __asm__("$9");
            register u32 vcnt __asm__("$10");
            register u8 *src_p __asm__("$8");
            register float (*dst_p)[4] __asm__("$7");

            __asm__ volatile("" : "+r"(dead_a1), "+r"(vb_tmp));
            VU0_OP("vmove.xyzw $vf28, $vf0");
            dead_t1 = 0xFFFFFFFFULL;
            __asm__ volatile("" : "+r"(dead_t1));
            VU0_LQC2(24, 0, mat);
            VU0_LQC2(25, 0x10, mat);
            VU0_LQC2(26, 0x20, mat);
            VU0_LQC2(27, 0x30, mat);
            vcnt = mesh->vtx_cnt;
            __asm__ volatile("" : "+r"(vcnt));
            src_p = vsrc;
            dst_p = vb_tmp;
            __asm__ volatile("" : "+r"(src_p), "+r"(dst_p));
            do {
                VU0_LQC2(28, 0, src_p);
                VU0_OP("vmulax.xyzw ACC, $vf24, $vf28x");
                VU0_OP("vmadday.xyzw ACC, $vf25, $vf28y");
                VU0_OP("vmaddaz.xyzw ACC, $vf26, $vf28z");
                VU0_OP("vmaddw.xyzw $vf31, $vf27, $vf0w");
                vcnt--;
                src_p += 16;
                VU0_SQC2(31, 0, dst_p);
                dst_p++;
            } while ((s32)vcnt > 0);
        }

        {
            register u32 off4 __asm__("$6") = mesh->u04;
            register s32 c16 __asm__("$8") = 16;
            __asm__ volatile("" : "+r"(off4), "+r"(c16));
            sec = (u8 *)mesh + off4;
            __asm__ volatile("" : "+r"(i));
            if (*(s8 *)(sec + 1) != c16) {
                goto next_i;
            }
        }
        do {
            S7110Tri *tri = (S7110Tri *)(sec + 32);
            s32 j;

            for (j = 0; j < *(s16 *)(sec + 2); tri++, tri_idx++, j++) {
                register s16 *tbl __asm__("$10") = a1->tbl;
                if (tbl[tri_idx] == -1) {
                    register u32 i0 __asm__("$2") = tri->i0;
                    register u32 i1 __asm__("$3") = tri->i1;
                    register float (*vb)[4] __asm__("$8");
                    register u32 i2 __asm__("$4");
                    register float *v0 __asm__("$11");
                    register float *v1 __asm__("$9");
                    register float *v2 __asm__("$8");
                    register float y0 __asm__("$f3");
                    register float y1 __asm__("$f1");
                    register float y2 __asm__("$f0");
                    register float c3 __asm__("$f2");

                    __asm__ volatile("" : "+r"(i0), "+r"(i1));
                    vb = vbuf;
                    __asm__ volatile("" : "+r"(vb));
                    i0 <<= 4;
                    i1 <<= 4;
                    i2 = tri->i2;
                    __asm__ volatile("" : "+r"(i0), "+r"(i1), "+r"(i2));
                    v0 = (float *)((u8 *)vb + i0);
                    v1 = (float *)((u8 *)vb + i1);
                    __asm__ volatile("" : "+r"(v0), "+r"(v1));
                    y0 = v0[1];
                    i2 <<= 4;
                    __asm__ volatile("" : "+f"(y0), "+r"(i2));
                    y1 = v1[1];
                    __asm__ volatile("" : "+f"(y1));
                    v2 = (float *)((u8 *)vb + i2);
                    __asm__ volatile("" : "+r"(v2));
                    y2 = v2[1];
                    __asm__ volatile("" : "+f"(y2));
                    y0 += y1;
                    c3 = 3.0f;
                    __asm__ volatile("" : "+f"(c3));
                    y0 += y2;
                    y0 = y0 / c3;
                    if (y0 <= f12) {
                        S7110Ent *ent;
                        register u32 third __asm__("$2");
                        register void *a2_chk __asm__("$3");

                        tbl[tri_idx] = a1->cur_idx;
                        ent = &a1->ents[a1->cur_idx];
                        if (ent->h0C >= 0) {
                            register s32 off __asm__("$2") = ent->h0C << 1;
                            register s16 *ep __asm__("$4");
                            register s32 ev __asm__("$3");
                            MMI_OP3("addu", ep, tbl, off);
                            ev = *ep;
                            __asm__ volatile("" : "+r"(ev));
                            if (ev >= 0) {
                                *ep = -2;
                            }
                        }
                        a1->cur_idx = (a1->cur_idx + 1) % a1->max_cnt;
                        __asm__ volatile("" : : : "memory");

                        third = 0x3EAAAAAB;
                        __asm__ volatile("" : "+r"(third));
                        VU0_LQC2(1, 0, v0);
                        VU0_LQC2(2, 0, v1);
                        VU0_LQC2(3, 0, v2);
                        VU0_OP("vadd.xyzw $vf31, $vf1, $vf2");
                        VU0_QMTC2(4, third);
                        VU0_OP("vadd.xyzw $vf31, $vf31, $vf3");
                        VU0_OP("vmulx.xyz $vf31, $vf31, $vf4x");
                        VU0_OP("vsub.xyz $vf1, $vf1, $vf31");
                        VU0_OP("vsub.xyz $vf2, $vf2, $vf31");
                        VU0_OP("vsub.xyz $vf3, $vf3, $vf31");
                        VU0_SQC2(31, 0, ent);
                        VU0_SQC2(1, 0x20, ent);
                        VU0_SQC2(2, 0x30, ent);
                        VU0_SQC2(3, 0x40, ent);
                        MMI_SQ_ZERO(0x50, ent);
                        {
                            register s32 c4096 __asm__("$2") = 4096;
                            __asm__ volatile("" : "+r"(c4096));
                            ent->h1C = 0;
                            ent->h0C = tri_idx;
                            ent->b0E = 0;
                            __asm__ volatile("" : : : "memory");
                            ent->h5E = c4096;
                        }
                        __asm__ volatile("" : : : "memory");

                        a2_chk = a2;
                        __asm__ volatile("" : "+r"(a2_chk));
                        if (a2_chk != 0) {
                            s32 k;
                            for (k = 0; k < 8; k++) {
                                register float r __asm__("$f3") = func_002B3DB0(4.0f);
                                float r2;
                                __asm__ volatile("" : "+f"(r));
                                vec1[0] = ent->f00 + r;
                                vec1[1] = ent->f04 + r;
                                vec1[2] = ent->f08 + r;
                                r2 = func_002B3DB0(16.0f) + -20.0f;
                                vec2[0] = 0.0f;
                                vec2[2] = 0.0f;
                                vec2[1] = r2;
                                func_01B06CA8(a2, vec1, vec2);
                            }
                        }
                    }
                }
            }
            sec = (u8 *)tri;
            {
                register s32 b1 __asm__("$2") = *(s8 *)(sec + 1);
                register s32 c16_end __asm__("$6");
                __asm__ volatile("" : "+r"(b1));
                c16_end = 16;
                __asm__ volatile("" : "+r"(c16_end));
                if (b1 != c16_end) {
                    break;
                }
            }
        } while (1);
    next_i:
        i++;
        {
            register S7110A0 *a0_t0 __asm__("$8") = a0;
            __asm__("" : "+r"(i) : "r"(a0_t0));
            if (i >= (s32)a0_t0->count) {
                break;
            }
        }
        } while (1);
    }
}
