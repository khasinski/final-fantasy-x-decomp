#ifndef COMMON_H
#define COMMON_H

typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

#include "asm_include.h"

/* 128-bit integer (one GPR, moved with lq/sq). Assigning (u_long128)0 gives `por rt,zero,zero; sq`. */
typedef unsigned int u_long128 __attribute__((mode(TI)));

/* Single-instruction inline asm (see docs/ASM_POLICY.md for when asm is allowed at all).
 * sync == sync.l (encoding 0x0000000f); sync.p is the pipeline barrier (0x0000040f). */
#define SYNC() __asm__ volatile("sync")
#define SYNC_P() __asm__ volatile("sync.p")
#define EI() __asm__ volatile("ei")
#define DI() __asm__ volatile("di")
#define BREAK() __asm__ volatile("break 0") /* assert-style trap (encoding 0x0000000d); gcc's own div-by-zero checks are `break 0,7` and need no macro */

#endif /* COMMON_H */
