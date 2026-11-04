#ifndef VU0_H
#define VU0_H

#include "common.h"

/* Tier-1 hardware macros (docs/ASM_POLICY.md section 4): one macro is one VU0 macro-mode or MMI instruction.
 * They are `asm volatile`, so they keep their order relative to each other and (memory clobber) to C loads/stores.
 * VU0 register numbers are literals: VU0_LQC2(4, 0x10, p) is `lqc2 $vf4, 0x10(p)`. */

#define VU0_LQC2(vf, off, p) __asm__ volatile("lqc2 $vf" #vf ", " #off "(%0)" : : "r"(p) : "memory")
#define VU0_SQC2(vf, off, p) __asm__ volatile("sqc2 $vf" #vf ", " #off "(%0)" : : "r"(p) : "memory")

/* GPR <-> VU0 register: qmtc2 moves a GPR into the x field, qmfc2 reads the x field. */
#define VU0_QMTC2(vf, v) __asm__ volatile("qmtc2 %0, $vf" #vf : : "r"(v))
#define VU0_QMFC2(v, vf) __asm__ volatile("qmfc2 %0, $vf" #vf : "=r"(v))
#define VU0_QMTC2_NI(vf, v) __asm__ volatile("qmtc2.ni %0, $vf" #vf : : "r"(v))
#define VU0_QMFC2_NI(v, vf) __asm__ volatile("qmfc2.ni %0, $vf" #vf : "=r"(v))

/* VU0 control registers (vi0..vi31, Q = vi22, ...) */
#define VU0_CTC2(vi, v) __asm__ volatile("ctc2 %0, $vi" #vi : : "r"(v))
#define VU0_CFC2(v, vi) __asm__ volatile("cfc2 %0, $vi" #vi : "=r"(v))

/* Any vector arithmetic instruction (no GPR operand): VU0_OP("vmulax.xyzw ACC, $vf4, $vf8x") */
#define VU0_OP(s) __asm__ volatile(s)

/* MMI three-operand ALU on 128-bit values: MMI_OP3("pextlw", d, a, b) is `pextlw d, a, b` (u_long128 operands) */
#define MMI_OP3(name, d, a, b) __asm__("" name " %0, %1, %2" : "=r"(d) : "r"(a), "r"(b))
#define MMI_OP2(name, d, a) __asm__("" name " %0, %1" : "=r"(d) : "r"(a))

#endif /* VU0_H */
