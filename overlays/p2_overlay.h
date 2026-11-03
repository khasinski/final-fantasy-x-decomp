#ifndef FFX_P2_OVERLAY_H
#define FFX_P2_OVERLAY_H

#include "common.h"

/* VU0 macro-mode primitives used inline by the original C (ee-gcc 2.9 never emits COP2).
 * NOT covered by docs/ASM_POLICY.md yet: units using them stay in overlays/wip/ until the
 * policy (and include/common.h) gains equivalent intrinsics. */
/* 128-bit zero store (gcc emits por+sq for a u_long128 zero, never sq $zero) */
#define SQ_ZERO(p) __asm__ volatile("sq $0, 0(%0)" : : "r"(p) : "memory")
/* VU0 square root of a float through vf31 */
#define VU0_SQRT(out, in) \
    __asm__ volatile("qmtc2.ni %1, $vf31\n\tvsqrt Q, $vf31x\n\tvwaitq\n\tvaddq.x $vf31, $vf0, Q\n\tqmfc2.ni %0, $vf31" \
                     : "=r"(out) : "r"(in))

#endif /* FFX_P2_OVERLAY_H */
