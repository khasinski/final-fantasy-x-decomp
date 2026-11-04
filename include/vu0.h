#ifndef VU0_H
#define VU0_H

#include "common.h"

/* Tier-1 hardware macros (docs/ASM_POLICY.md section 4): one macro is one VU0 macro-mode, MMI, COP0 or R5900 instruction.
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
/* `sq $zero, off(p)`: 128-bit zero store (ee-gcc would emit por+sq for a TI zero) */
#define MMI_SQ_ZERO(off, p) __asm__ volatile("sq $0, " #off "(%0)" : : "r"(p) : "memory")
/* MMI with $zero as the first source: MMI_OP2Z("pextlb", d, b) is `pextlb d, $zero, b` (operands are plain GPR-sized values) */
#define MMI_OP2Z(name, d, b) __asm__ volatile("" name " %0, $0, %1" : "=r"(d) : "r"(b))
#define VU0_CTC2_NI(vi, v) __asm__ volatile("ctc2.ni %0, $vi" #vi : : "r"(v))
#define VU0_CTC2_NI_ZERO(vi) __asm__ volatile("ctc2.ni $0, $vi" #vi)
#define VU0_CFC2_NI(v, vi) __asm__ volatile("cfc2.ni %0, $vi" #vi : "=r"(v))
/* R5900 integer instruction the compiler never emits (addi, trapping): d = 0 + imm */
#define MIPS_ADDI0(d, imm) __asm__ volatile("addi %0, $0, " #imm : "=r"(d))
/* addi v, v, imm (trapping add, never emitted by the compiler) */
#define MIPS_ADDI(v, imm) __asm__ volatile("addi %0, %0, " #imm : "+r"(v))
/* addiu d, $0, imm (li) */
#define MIPS_ADDIU0(d, imm) __asm__ volatile("addiu %0, $0, " #imm : "=r"(d))
/* ori d, $0, imm with d also an input (keeps a preceding write to d alive) */
#define MIPS_ORI0(d, imm) __asm__ volatile("ori %0, $0, " #imm : "+r"(d))
/* FPU -> GPR raw bit move (mfc1): lets the float constant be moved to a GPR before the first VU0 macro, as in the original code */
#define MIPS_MFC1(v, f) __asm__ volatile("mfc1 %0, %1" : "=r"(v) : "f"(f))
/* same with $zero as the first source: MMI_OP3Z("pextlh", d, b) is `pextlh d, $0, b` */
#define MMI_OP3Z(name, d, b) __asm__("" name " %0, $0, %1" : "=r"(d) : "r"(b))
/* COP0 Status read (one instruction) */
#define COP0_MFC0_STATUS(v) __asm__ volatile("mfc0 %0, $12" : "=r"(v))
/* EE kernel call: EE_LI_V1(n) is `addiu $3, $0, n`, EE_SYSCALL(r, a) is `syscall 0` (arg stays in $4, result r pinned to $2) */
#define EE_LI_V1(n) __asm__ volatile("addiu $3, $0, " #n : : : "$3")
#define EE_SYSCALL(r, a) __asm__ volatile("syscall 0" : "=r"(r) : "r"(a) : "$3", "memory")
/* COP0 TagLo (c0_taglo = $28) read and the single `cache op, off(reg)` instruction */
#define COP0_MFC0_TAGLO(v) __asm__ volatile("mfc0 %0, $28" : "=r"(v))
#define CACHE_OP(op, off, p) __asm__ volatile("cache " #op ", " #off "(%0)" : : "r"(p) : "memory")

#endif /* VU0_H */
