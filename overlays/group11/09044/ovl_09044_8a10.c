#include "common.h"
#include "vu0.h"

typedef unsigned long u_long64;

typedef struct F4aEntry {
    u8 *mesh;
    void *mtx;
    u32 pad08;
    u32 pad0C;
} F4aEntry;

typedef struct F4aList {
    u32 pad00;
    u16 count;
    u8 pad06[10];
    F4aEntry ents[1];
} F4aList;

typedef struct F4aOut {
    u16 count;
    u8 pad02[0x1E];
    u8 v20[0x10];
    u8 v30[0x10];
    u8 data[1];
} F4aOut;

void *func_002B3888(s32 size);
void func_002B56D8(void *dst, void *a, void *b);
void func_002B7EA0(void *a0, void *a1, void *a2, void *a3);
void func_002B39C0(s32 size);

void func_01B08A10(F4aOut *out, F4aList *list, void *mtx_arg)
{
    register u8 *buf __asm__("$18");
    register u8 *dst __asm__("$20");
    register F4aEntry *ent __asm__("$17");
    register s32 i __asm__("$21");
    register s32 total __asm__("$22");

    void *p20;
    void *mat_dst;
    void *p30;

    buf = (u8 *)func_002B3888(0x100);
    __asm__ volatile("" : : : "memory");
    dst = out->data;
    ent = list->ents;
    i = 0;
    total = 0;

    if (list->count != 0) {
        mat_dst = buf + 0x40;
        p20 = out->v20;
        p30 = out->v30;
        do {
            register u8 *mesh __asm__("$2") = ent->mesh;
            register void *a0_m __asm__("$4") = mat_dst;
            register u32 voff __asm__("$3") = *(u32 *)(mesh + 8);
            register u8 *cur __asm__("$16") = mesh + 0x20;
            register void *a2_m __asm__("$6");
            register void *a1_m __asm__("$5");
            register u8 *verts __asm__("$19");
            register F4aEntry *next_ent __asm__("$11");
            register u32 cnt_list __asm__("$12");
            register s32 next_i __asm__("$10");
            register s32 tag __asm__("$3");
            register s32 neg1 __asm__("$2");

            __asm__ volatile("" : "+r"(cur), "+r"(a0_m));
            a2_m = ent->mtx;
            __asm__ volatile("" : "+r"(a2_m));
            a1_m = mtx_arg;
            __asm__ volatile("" : "+r"(a1_m));
            verts = mesh + voff;
            func_002B56D8(a0_m, a1_m, a2_m);
            VU0_LQC2(8, 0x40, buf);
            VU0_LQC2(9, 0x50, buf);
            VU0_LQC2(10, 0x60, buf);
            VU0_LQC2(11, 0x70, buf);

            tag = *(s8 *)(cur + 1);
            neg1 = -1;
            __asm__ volatile("" : "+r"(tag), "+r"(neg1));
            if (tag != neg1) {
                next_ent = ent + 1;
                cnt_list = list->count;
                __asm__ volatile("" : "+r"(next_ent), "+r"(cnt_list));
                next_i = i + 1;
                __asm__ volatile("" : "+r"(next_i));
                do {
                    s16 ntri;
                    u8 *tri;

                    *(u32 *)(buf + 0) = *(u32 *)(cur + 8);
                    *(u32 *)(buf + 4) = *(u32 *)(cur + 12);
                    ntri = *(s16 *)(cur + 2);
                    tri = cur + 0x20;
                    if (ntri > 0) {
                        s32 k = ntri;
                        do {
                            register u8 *p0 __asm__("$7") = verts + (*(u16 *)(tri + 0) << 4);
                            register u8 *p1 __asm__("$6") = verts + (*(u16 *)(tri + 2) << 4);
                            register u8 *p2 __asm__("$5") = verts + (*(u16 *)(tri + 4) << 4);
                            register u32 v0 __asm__("$2");
                            register u32 v1 __asm__("$3");
                            register u32 a0 __asm__("$4");
                            register u32 c4096 __asm__("$5");
                            register u_long64 hdr __asm__("$3");
                            register u8 *outp __asm__("$2");

                            VU0_LQC2(16, 0, p0);
                            VU0_LQC2(17, 0, p1);
                            VU0_LQC2(18, 0, p2);
                            VU0_OP("vmulax.xyzw ACC, $vf8, $vf16x");
                            VU0_OP("vmadday.xyzw ACC, $vf9, $vf16y");
                            VU0_OP("vmaddaz.xyzw ACC, $vf10, $vf16z");
                            VU0_OP("vmaddw.xyzw $vf16, $vf11, $vf0w");
                            VU0_OP("vmulax.xyzw ACC, $vf8, $vf17x");
                            VU0_OP("vmadday.xyzw ACC, $vf9, $vf17y");
                            VU0_OP("vmaddaz.xyzw ACC, $vf10, $vf17z");
                            VU0_OP("vmaddw.xyzw $vf17, $vf11, $vf0w");
                            VU0_OP("vmulax.xyzw ACC, $vf8, $vf18x");
                            VU0_OP("vmadday.xyzw ACC, $vf9, $vf18y");
                            VU0_OP("vmaddaz.xyzw ACC, $vf10, $vf18z");
                            VU0_OP("vmaddw.xyzw $vf18, $vf11, $vf0w");

                            v0 = 0x3F000000;
                            VU0_QMTC2(14, v0);
                            v0 = 0x3EAAAAAB;
                            VU0_QMTC2(15, v0);
                            VU0_OP("vadd.xyz $vf19xyz, $vf16xyz, $vf17xyz");
                            VU0_OP("vadd.xyz $vf19xyz, $vf19xyz, $vf18xyz");
                            VU0_OP("vmulx.xyz $vf19xyz, $vf19xyz, $vf15x");
                            VU0_OP("vadd.xyz $vf20xyz, $vf16xyz, $vf17xyz");
                            VU0_OP("vmulx.xyz $vf20xyz, $vf20xyz, $vf14x");
                            VU0_OP("vadd.xyz $vf21xyz, $vf17xyz, $vf18xyz");
                            VU0_OP("vmulx.xyz $vf21xyz, $vf21xyz, $vf14x");
                            VU0_OP("vadd.xyz $vf22xyz, $vf18xyz, $vf16xyz");
                            VU0_OP("vmulx.xyz $vf22xyz, $vf22xyz, $vf14x");

                            v0 = *(u32 *)(tri + 8);
                            v1 = *(u32 *)(tri + 12);
                            a0 = *(u32 *)(tri + 16);
                            MMI_OP2Z("pextlh", v0, v0);
                            MMI_OP2Z("pextlh", v1, v1);
                            MMI_OP2Z("pextlh", a0, a0);
                            __asm__ volatile("psllw %0, %1, 0x10" : "=r"(v0) : "r"(v0));
                            __asm__ volatile("psllw %0, %1, 0x10" : "=r"(v1) : "r"(v1));
                            __asm__ volatile("psllw %0, %1, 0x10" : "=r"(a0) : "r"(a0));
                            __asm__ volatile("psraw %0, %1, 0x10" : "=r"(v0) : "r"(v0));
                            __asm__ volatile("psraw %0, %1, 0x10" : "=r"(v1) : "r"(v1));
                            __asm__ volatile("psraw %0, %1, 0x10" : "=r"(a0) : "r"(a0));
                            c4096 = 0x1000;
                            __asm__ volatile("pcpyld %0, %1, %2" : "=r"(v0) : "r"(c4096), "r"(v0));
                            __asm__ volatile("pcpyld %0, %1, %2" : "=r"(v1) : "r"(c4096), "r"(v1));
                            __asm__ volatile("pcpyld %0, %1, %2" : "=r"(a0) : "r"(c4096), "r"(a0));
                            VU0_QMTC2(24, v0);
                            VU0_QMTC2(25, v1);
                            VU0_QMTC2(26, a0);
                            VU0_OP("vitof12.xyz $vf24xyz, $vf24xyz");
                            VU0_OP("vitof12.xyz $vf25xyz, $vf25xyz");
                            VU0_OP("vitof12.xyz $vf26xyz, $vf26xyz");
                            VU0_OP("vmove.zw $vf27zw, $vf24zw");
                            VU0_OP("vmove.zw $vf28zw, $vf24zw");
                            VU0_OP("vmove.zw $vf29zw, $vf24zw");
                            VU0_OP("vmove.zw $vf30zw, $vf24zw");
                            VU0_OP("vadd.xy $vf27xy, $vf24xy, $vf25xy");
                            VU0_OP("vadd.xy $vf27xy, $vf27xy, $vf26xy");
                            VU0_OP("vmulx.xy $vf27xy, $vf27xy, $vf15x");
                            VU0_OP("vadd.xy $vf28xy, $vf24xy, $vf25xy");
                            VU0_OP("vmulx.xy $vf28xy, $vf28xy, $vf14x");
                            VU0_OP("vadd.xy $vf29xy, $vf25xy, $vf26xy");
                            VU0_OP("vmulx.xy $vf29xy, $vf29xy, $vf14x");
                            VU0_OP("vadd.xy $vf30xy, $vf26xy, $vf24xy");
                            VU0_OP("vmulx.xy $vf30xy, $vf30xy, $vf14x");

                            hdr = *(u_long64 *)buf;
                            outp = dst;
                            __asm__ volatile("" : "+r"(hdr), "+r"(outp));

                            VU0_SQC2(19, 0x40, outp);
                            VU0_SQC2(16, 0x50, outp);
                            VU0_SQC2(20, 0x60, outp);
                            VU0_SQC2(27, 0x10, outp);
                            VU0_SQC2(24, 0x20, outp);
                            VU0_SQC2(28, 0x30, outp);
                            VU0_OP("vadd.xyz $vf31xyz, $vf19xyz, $vf16xyz");
                            VU0_OP("vadd.xyz $vf31xyz, $vf31xyz, $vf20xyz");
                            VU0_OP("vmulx.xyz $vf31xyz, $vf31xyz, $vf15x");
                            VU0_SQC2(31, 0x70, outp);
                            *(u_long64 *)(outp + 0) = hdr;
                            *(u32 *)(outp + 8) = 0;
                            outp += 0x80;
                            __asm__ volatile("" : "+r"(outp));

                            VU0_SQC2(19, 0x40, outp);
                            VU0_SQC2(20, 0x50, outp);
                            VU0_SQC2(17, 0x60, outp);
                            VU0_SQC2(27, 0x10, outp);
                            VU0_SQC2(28, 0x20, outp);
                            VU0_SQC2(25, 0x30, outp);
                            VU0_OP("vadd.xyz $vf31xyz, $vf19xyz, $vf20xyz");
                            VU0_OP("vadd.xyz $vf31xyz, $vf31xyz, $vf17xyz");
                            VU0_OP("vmulx.xyz $vf31xyz, $vf31xyz, $vf15x");
                            VU0_SQC2(31, 0x70, outp);
                            *(u_long64 *)(outp + 0) = hdr;
                            *(u32 *)(outp + 8) = 0;
                            outp += 0x80;
                            __asm__ volatile("" : "+r"(outp));

                            VU0_SQC2(19, 0x40, outp);
                            VU0_SQC2(17, 0x50, outp);
                            VU0_SQC2(21, 0x60, outp);
                            VU0_SQC2(27, 0x10, outp);
                            VU0_SQC2(25, 0x20, outp);
                            VU0_SQC2(29, 0x30, outp);
                            VU0_OP("vadd.xyz $vf31xyz, $vf19xyz, $vf17xyz");
                            VU0_OP("vadd.xyz $vf31xyz, $vf31xyz, $vf21xyz");
                            VU0_OP("vmulx.xyz $vf31xyz, $vf31xyz, $vf15x");
                            VU0_SQC2(31, 0x70, outp);
                            *(u_long64 *)(outp + 0) = hdr;
                            *(u32 *)(outp + 8) = 0;
                            outp += 0x80;
                            __asm__ volatile("" : "+r"(outp));

                            VU0_SQC2(19, 0x40, outp);
                            VU0_SQC2(21, 0x50, outp);
                            VU0_SQC2(18, 0x60, outp);
                            VU0_SQC2(27, 0x10, outp);
                            VU0_SQC2(29, 0x20, outp);
                            VU0_SQC2(26, 0x30, outp);
                            VU0_OP("vadd.xyz $vf31xyz, $vf19xyz, $vf21xyz");
                            VU0_OP("vadd.xyz $vf31xyz, $vf31xyz, $vf18xyz");
                            VU0_OP("vmulx.xyz $vf31xyz, $vf31xyz, $vf15x");
                            VU0_SQC2(31, 0x70, outp);
                            *(u_long64 *)(outp + 0) = hdr;
                            *(u32 *)(outp + 8) = 0;
                            outp += 0x80;
                            __asm__ volatile("" : "+r"(outp));

                            VU0_SQC2(19, 0x40, outp);
                            VU0_SQC2(18, 0x50, outp);
                            VU0_SQC2(22, 0x60, outp);
                            VU0_SQC2(27, 0x10, outp);
                            VU0_SQC2(26, 0x20, outp);
                            VU0_SQC2(30, 0x30, outp);
                            VU0_OP("vadd.xyz $vf31xyz, $vf19xyz, $vf18xyz");
                            VU0_OP("vadd.xyz $vf31xyz, $vf31xyz, $vf22xyz");
                            VU0_OP("vmulx.xyz $vf31xyz, $vf31xyz, $vf15x");
                            VU0_SQC2(31, 0x70, outp);
                            *(u_long64 *)(outp + 0) = hdr;
                            *(u32 *)(outp + 8) = 0;
                            outp += 0x80;
                            __asm__ volatile("" : "+r"(outp));

                            VU0_SQC2(19, 0x40, outp);
                            VU0_SQC2(22, 0x50, outp);
                            VU0_SQC2(16, 0x60, outp);
                            VU0_SQC2(27, 0x10, outp);
                            VU0_SQC2(30, 0x20, outp);
                            VU0_SQC2(24, 0x30, outp);
                            VU0_OP("vadd.xyz $vf31xyz, $vf19xyz, $vf22xyz");
                            VU0_OP("vadd.xyz $vf31xyz, $vf31xyz, $vf16xyz");
                            VU0_OP("vmulx.xyz $vf31xyz, $vf31xyz, $vf15x");
                            VU0_SQC2(31, 0x70, outp);
                            *(u_long64 *)(outp + 0) = hdr;
                            *(u32 *)(outp + 8) = 0;
                            __asm__ volatile("" : : : "memory");

                            dst += 0x300;
                            total += 6;
                            tri += 0x1C;
                            k--;
                        } while (k != 0);
                    }
                    cur = tri;
                    {
                        register s32 neg1_2 __asm__("$3") = -1;
                        register s32 tag2 __asm__("$2") = *(s8 *)(cur + 1);
                        __asm__ volatile("" : "+r"(neg1_2), "+r"(tag2));
                        if (tag2 != neg1_2) {
                            continue;
                        }
                    }
                    break;
                } while (1);
                goto next_ent_lbl;
            }
            next_ent = ent + 1;
            cnt_list = list->count;
            __asm__ volatile("" : "+r"(next_ent), "+r"(cnt_list));
            next_i = i + 1;
            __asm__ volatile("" : "+r"(next_i));
        next_ent_lbl:
            i = next_i;
            ent = next_ent;
            {
                register s32 cmp __asm__("$2") = (i < (s32)cnt_list);
                if (cmp) {
                    continue;
                }
            }
            break;
        } while (1);
        out->count = total;
    } else {
        p20 = out->v20;
        p30 = out->v30;
        __asm__ volatile("" : : : "memory");
        out->count = total;
    }

    {
        register F4aList *a0_f __asm__("$4") = list;
        __asm__ volatile("" : "+r"(a0_f));
        func_002B7EA0(a0_f, mtx_arg, p20, p30);
    }
    func_002B39C0(0x100);
}
