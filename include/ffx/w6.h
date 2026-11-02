#ifndef FFX_W6_H

#define FFX_W6_H

#include "common.h"
#include "ffx/types.h"
#include "ffx/globals.h"
#include "ffx/funcs.h"

/* GS register addresses (A+D) */
#define GS_REG_CLAMP_1    0x08

#define GS_REG_TEX0_1     0x06

#define GS_REG_TEX1_1     0x14

#define GS_REG_XYOFFSET_1 0x18

#define GS_REG_FOGCOL     0x3D

#define GS_REG_FOG        0x0A

#define GS_REG_FBA_1      0x4A

#define GS_REG_TEXFLUSH   0x3F

#define GS_REG_SCISSOR_1  0x40

#define GS_REG_ALPHA_1    0x42

#define GS_REG_COLCLAMP   0x46

#define GS_REG_TEST_1     0x47

#define GS_REG_FRAME_1    0x4C

#define GS_REG_ZBUF_1     0x4E

#define SCE_GIF_SET_TAG(nloop, eop, pre, prim, flg, nreg) \
    ((u64)(nloop) | ((u64)(eop) << 15) | ((u64)(pre) << 46) | ((u64)(prim) << 47) | \
     ((u64)(flg) << 58) | ((u64)(nreg) << 60))

/* SCE_GS_SET_* register value builders (same layout as the Sony SDK macros) */
#define SCE_GS_SET_FRAME(fbp, fbw, psm, fbmsk) \
    ((u64)(fbp) | ((u64)(fbw) << 16) | ((u64)(psm) << 24) | ((u64)(fbmsk) << 32))

#define SCE_GS_SET_XYOFFSET(x, y) ((u64)(x) | ((u64)(y) << 32))

#define SCE_GS_SET_ALPHA(a, b, c, d, fix) \
    ((u64)(a) | ((u64)(b) << 2) | ((u64)(c) << 4) | ((u64)(d) << 6) | ((u64)(fix) << 32))

#define SCE_GS_SET_SCISSOR(x0, x1, y0, y1) \
    ((u64)(x0) | ((u64)(x1) << 16) | ((u64)(y0) << 32) | ((u64)(y1) << 48))

#define SCE_GS_SET_TEST(ate, atst, aref, afail, date, datm, zte, ztst) \
    ((u64)(ate) | ((u64)(atst) << 1) | ((u64)(aref) << 4) | ((u64)(afail) << 12) | \
     ((u64)(date) << 14) | ((u64)(datm) << 15) | ((u64)(zte) << 16) | ((u64)(ztst) << 17))

#define SCE_GS_SET_TEX0(tbp0, tbw, psm, tw, th, tcc, tfx, cbp, cpsm, csm, csa, cld) \
    ((u64)(tbp0) | ((u64)(tbw) << 14) | ((u64)(psm) << 20) | ((u64)(tw) << 26) | \
     ((u64)(th) << 30) | ((u64)(tcc) << 34) | ((u64)(tfx) << 35) | ((u64)(cbp) << 37) | \
     ((u64)(cpsm) << 51) | ((u64)(csm) << 55) | ((u64)(csa) << 56) | ((u64)(cld) << 61))

#define SCE_GS_SET_TEX1(lcm, mxl, mmag, mmin, mtba, l, k) \
    ((u64)(lcm) | ((u64)(mxl) << 2) | ((u64)(mmag) << 5) | ((u64)(mmin) << 6) | \
     ((u64)(mtba) << 9) | ((u64)(l) << 19) | ((u64)(k) << 32))

#define SCE_GS_SET_CLAMP(wms, wmt, minu, maxu, minv, maxv) \
    ((u64)(wms) | ((u64)(wmt) << 2) | ((u64)(minu) << 4) | ((u64)(maxu) << 14) | \
     ((u64)(minv) << 24) | ((u64)(maxv) << 34))

#define SCE_GS_SET_ZBUF(zbp, psm, zmsk) \
    ((u64)(zbp) | ((u64)(psm) << 24) | ((u64)(zmsk) << 32))

#endif
