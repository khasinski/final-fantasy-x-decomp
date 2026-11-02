#ifndef FFX_RCEF_OVERLAY_H
#define FFX_RCEF_OVERLAY_H

#include "common.h"
#include "ffx/w3.h"

/* Resident rcef effect-runtime context at 0x00313CB0 (0x240 bytes, see func_0019FC00). */
typedef struct RcefMainCtx {
    s32 state;              /* 0x000 */
    s32 eff_id;             /* 0x004 (D_00313CB4) */
    void *res;              /* 0x008 (D_00313CB8): embedded resource payload + 0x10 */
    s32 unk0C;              /* 0x00C */
    void *work;             /* 0x010: overlay particle work block (0x38 bytes) */
    s32 par_count;          /* 0x014 */
    void **par_tbl;         /* 0x018 */
    W3Sched sched;          /* 0x01C (D_00313CCC, 0x17C bytes) */
    s32 caster;             /* 0x198 (D_00313E48): MsGetEff2Chr(eff_id) */
    s32 target_count;       /* 0x19C (D_00313E4C) */
    s32 targets[22];        /* 0x1A0 (D_00313E50): target character IDs */
    u8 unk1F8;              /* 0x1F8 */
    u8 pad1F9[0x3F];        /* 0x1F9 */
    s32 unk238;             /* 0x238 */
    s32 unk23C;             /* 0x23C */
} RcefMainCtx;

/* Effect scene object (0x490 bytes, allocated by rcefObjNew / initialized by rcefObjInit). */
typedef struct RcefObj {
    W3Task task;            /* 0x000..0x0BC */
    u32 flagsBC;            /* 0x0BC */
    u8 padC0[0x10];         /* 0x0C0..0x0D0 */
    float pos[3];           /* 0x0D0..0x0DC */
    int pos_w;              /* 0x0DC */
    float vel[3];           /* 0x0E0..0x0EC */
    int vel_w;              /* 0x0EC */
    float acc[3];           /* 0x0F0..0x0FC */
    int acc_w;              /* 0x0FC */
    float rot[3];           /* 0x100..0x10C */
    int rot_w;              /* 0x10C */
    float rot_vel[3];       /* 0x110..0x11C */
    int rot_vel_w;          /* 0x11C */
    float rot_acc[3];       /* 0x120..0x12C */
    int rot_acc_w;          /* 0x12C */
    float scale[3];         /* 0x130..0x13C */
    int scale_w;            /* 0x13C */
} RcefObj;

extern RcefMainCtx D_00313CB0;
extern s32 D_00313E50;

void func_0019FC00(RcefMainCtx *ctx, int eff_id, void *res, int a3, int t0, int t1, int count, void *tbl, void *work);
void func_0019FE38(RcefMainCtx *ctx);
void func_0019FE48(RcefMainCtx *ctx);
void func_0019FE58(RcefMainCtx *ctx);
void *func_0019FF90(RcefMainCtx *ctx, W3TaskFn fn);
void rcefMainKickPar(RcefMainCtx *ctx, RcefObj *o, int idx, int sub);
void func_001A1378(RcefObj *o, int chr_id, int optpos);
void func_001A13A0(RcefObj *o, int chr_id, int bone);
void func_001A1420(RcefObj *o, u32 flags);
void func_001A2B58(int ready);
void func_001A2B68(void);
void func_001A2B80(int chr_id, int motion_id);
void func_001A36D8(int r, int g, int b, int a, int frames);
void func_001A37F0(void);
void func_001A3800(int chr_id, int a1);
void func_001A4288(int se_id);
void func_001A42D0(int a0, int a1);
void func_001A4310(int a0);

#endif /* FFX_RCEF_OVERLAY_H */
