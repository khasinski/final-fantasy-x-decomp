#ifndef FFX_W11_H

#define FFX_W11_H

#include "common.h"
#include "ffx/types.h"
#include "ffx/globals.h"
#include "ffx/funcs.h"

static inline int isnan(fp_number_type *x) { return x->class < CLASS_ZERO; }

static inline int isinf(fp_number_type *x) { return x->class == CLASS_INFINITY; }

static inline int iszero(fp_number_type *x) { return x->class == CLASS_ZERO; }

#define LSHIFT(a) { a = (a & 1) | (a >> 1); } /* sticky right shift, libgcc naming */

#define NGARDS 8

#define GARDROUND 0x7f

#define GARDMASK 0xff

#define GARDMSB 0x80

#define EXPBIAS 1023

#define EXPMAX 0x7ff

#define NORMAL_EXPMIN (-EXPBIAS + 1)

#define IMPLICIT_1 ((fractype)1 << (52 + NGARDS))

#define IMPLICIT_2 ((fractype)1 << (52 + NGARDS + 1))

#define QUIET_NAN ((fractype)1 << 51)

#define FRAC_NBITS 64

#define SF_NGARDS 7

#define SF_GARDROUND 0x3f

#define SF_GARDMASK 0x7f

#define SF_GARDMSB 0x40

#define SF_EXPBIAS 127

#define SF_EXPMAX 0xff

#define SF_NORMAL_EXPMIN (-SF_EXPBIAS + 1)

#define SF_IMPLICIT_1 (1u << (23 + SF_NGARDS))

#define SF_IMPLICIT_2 (1u << (23 + SF_NGARDS + 1))

#define SF_QUIET_NAN 0x100000u

#define SF_FRAC_NBITS 32

static inline int isnan_sf(fp_number_sf *x) { return x->class < CLASS_ZERO; }

static inline int isinf_sf(fp_number_sf *x) { return x->class == CLASS_INFINITY; }

static inline int iszero_sf(fp_number_sf *x) { return x->class == CLASS_ZERO; }

/* argument blocks passed to the kernel call dispatcher func_002F8810 */
typedef struct { int a; int b; } W11Args2;

typedef struct { int a; int b; int c; } W11Args3;

/* newlib libm (msun) helpers, little endian */
typedef union {
    double value;
    struct {
        u32 lsw;
        u32 msw;
    } parts;
} ieee_double_shape_type;

typedef union {
    float value;
    u32 word;
} ieee_float_shape_type;

#define EXTRACT_WORDS(ix0, ix1, d) \
    do { ieee_double_shape_type ew_u; ew_u.value = (d); (ix0) = ew_u.parts.msw; (ix1) = ew_u.parts.lsw; } while (0)

#define GET_HIGH_WORD(i, d) \
    do { ieee_double_shape_type gh_u; gh_u.value = (d); (i) = gh_u.parts.msw; } while (0)

#define SET_HIGH_WORD(d, v) \
    do { ieee_double_shape_type sh_u; sh_u.value = (d); sh_u.parts.msw = (v); (d) = sh_u.value; } while (0)

#define GET_FLOAT_WORD(i, d) \
    do { ieee_float_shape_type gf_u; gf_u.value = (d); (i) = gf_u.word; } while (0)

#define SET_FLOAT_WORD(d, i) \
    do { ieee_float_shape_type sf_u; sf_u.word = (i); (d) = sf_u.value; } while (0)

/* DEBT(NAME): persistent sound-device record, with the two flags cleared by func_002D8978. */
typedef struct W11SoundDevice { u8 pad0[8]; u8 b08, b09; u16 h0A; char buf0C[0x100]; } W11SoundDevice;
extern W11SoundDevice D_00565F50;
int func_2064278(W11SoundDevice *state, int a, int b, int c, int d); /* DEBT(TYPE): external entry's call signature inferred from argument registers. */

#endif
