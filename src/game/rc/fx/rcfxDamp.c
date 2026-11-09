/* tu_176 0x1a55a8-0x1a56f8: medium; rcfxDamp (config/tu_map.tsv) */
#define func_001A5698 _hdr_func_001A5698
#include "common.h"
#include "ffx/r2.h"
#include "ffx/q3.h"
#include "ffx/s2.h"
#include "ffx/v2.h"
#include "vu0.h"
#undef func_001A5698

void func_001A5698(u8 *obj, u8 *desc);

void func_001A55A8(u8 *obj, u8 *desc)
{
    int dst = *(int *)(desc + 0x24); /* DEBT(CAST) */
    int scale = *(int *)(desc + 0x14);
    int n = *(int *)(desc + 0x10);
    u_long128 tmp;
    int i;

    for (i = 0; i < n; i++) {
        VU0_LQC2(31, 0, obj + 0x20);
        VU0_QMTC2_NI(30, scale);
        VU0_OP("vmulx.xyz $vf31, $vf31, $vf30x");
        VU0_SQC2(31, 0, &tmp);
        VU0_LQC2(31, 0, (u8 *)(i * 16 + dst));
        VU0_LQC2(30, 0, &tmp);
        VU0_OP("vadd.xyz $vf31, $vf31, $vf30");
        VU0_SQC2(31, 0, (u8 *)(i * 16 + dst));
    }
}

void *rcfxDampNew(void) {
    void *p = _rcAlloc(0x20, D_0056DE70, 0x12);

    func_001A5650(p);
    return p;
}

void func_001A5648(void *p) {
    func_0018FC10(p);
}

void func_001A5650(void *p) {
    S2Obj1A5 *o = p;

    o->w0 = 0x30003;
    o->p4 = func_001A5648;
    o->w8 = 0;
    o->wC = 0;
    o->w10 = 0;
    o->p14 = func_001A5698;
    o->w18 = 0;
    o->f1C = 0.0001f;
}

void func_001A5698(u8 *obj, u8 *desc)
{
    register int n __asm__("$6") = *(int *)(desc + 0x10);
    register u8 *src0 __asm__("$3") = *(u8 **)(desc + 0x20);
    register u8 *dst __asm__("$2") = *(u8 **)(desc + 0x24);
    u_long128 tmp;

    if (n > 0) {
        register u8 *src __asm__("$5") = src0;
        register int cnt __asm__("$3") = n;
        register u_long128 *tp __asm__("$6") = &tmp;

        __asm__("" : "+r"(src), "+r"(cnt), "+r"(tp));
        do {
            float scale = *(float *)(obj + 0x1C);
            register u32 sbits __asm__("$7");

            MIPS_MFC1(sbits, scale);
            VU0_LQC2(31, 0, src);
            VU0_QMTC2_NI(30, sbits);
            VU0_OP("vmulx.xyz $vf31, $vf31, $vf30x");
            VU0_SQC2(31, 0, tp);
            VU0_LQC2(31, 0, dst);
            VU0_LQC2(30, 0, tp);
            VU0_OP("vsub.xyz $vf31, $vf31, $vf30");
            VU0_SQC2(31, 0, dst);
            dst += 0x10;
            cnt--;
            __asm__ volatile("" : "+r"(dst), "+r"(cnt));
            src += 0x10;
        } while (cnt != 0);
    }
}

