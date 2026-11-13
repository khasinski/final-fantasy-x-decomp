/* EE Battle-Effect Overlay: group 0x11, file 09344 (group_index 300)
 * Load base: 0x01B00000, .text: 0x01B00648..0x01B00F48
 *
 * Effect scene: caster motions 104..106 sequence with motes and sparks.
 */
#include "../rcef_overlay.h"

extern void func_001A2F50(int chr, int a1, float out1[4], float out2[4]);

typedef struct {
    float v[4];
} KickVec;

extern void kickParV(RcefMainCtx *ctx, RcefObj *o, int idx, int sub, KickVec vec);
extern void func_001A3000(int chr, int a1, float out[4]);
extern u8 D_01B00608[8];
extern u8 D_01B00610[8];
extern u8 D_01B00F50[8];

void func_01B00690(W3Task *t);
void func_01B006D8(W3Task *t);
void func_01B00748(W3Task *t);
void func_01B00788(W3Task *t);
void func_01B007D8(W3Task *t);
void func_01B00850(W3Task *t);
void func_01B008A0(W3Task *t);
void func_01B00908(W3Task *t);
void func_01B00968(W3Task *t);
void func_01B009A0(W3Task *t);
void func_01B009B0(W3Task *t);
void func_01B00A20(W3Task *t);
void func_01B00A50(W3Task *t);
void func_01B00AF0(W3Task *t);
void func_01B00B90(W3Task *t);
void func_01B00C80(W3Task *t);
void func_01B00D68(W3Task *t);

void func_01B00648(W3Task *t)
{
    W3Task *task = t;

    func_001A42D0(2, 0);
    func_001A1D08(task, func_01B00690);
    func_001A1D50(task, func_001A2058);
}

void func_01B00690(W3Task *t)
{
    W3Task *task = t;

    func_001A2B58(0);
    func_001A1D08(task, func_01B007D8);
    func_001A1D50(task, func_001A2098);
}

/* caster motion 104 */
void func_01B006D8(W3Task *t)
{
    RcefObj *o = (RcefObj *)t;
    int caster = D_00313CB0.caster;

    func_001A2B80(caster, 104);
    func_001A1D08(t, func_01B00748);
    func_001A1D50(t, func_001A2148);
    o->task.frame[o->task.sp].count = caster;
}

/* caster motion 105 */
void func_01B00748(W3Task *t)
{
    func_001A2B80(D_00313CB0.caster, 105);
    func_001A1D08(t, func_01B007D8);
}

/* kick mote spawner + 20-frame delay */
void func_01B00788(W3Task *t)
{
    W3Task *task = t;

    func_0019FF90(&D_00313CB0, func_01B00A50);
    func_001A1D08(task, func_01B007D8);
    func_001A1DF0(task, 20);
}

/* camera + two spawners + 8-frame delay */
void func_01B007D8(W3Task *t)
{
    W3Task *task = t;

    func_001A4288(0);
    func_001A4310(2);
    func_0019FF90(&D_00313CB0, func_01B009B0);
    func_0019FF90(&D_00313CB0, func_01B00AF0);
    func_001A1D08(task, func_01B00850);
    func_001A1DF0(task, 8);
}

/* second spawner + 20-frame delay */
void func_01B00850(W3Task *t)
{
    W3Task *task = t;

    func_0019FF90(&D_00313CB0, func_01B00B90);
    func_001A1D08(task, func_01B008A0);
    func_001A1DF0(task, 20);
}

/* third spawner + 8-frame delay */
void func_01B008A0(W3Task *t)
{
    W3Task *task = t;

    func_0019FF90(&D_00313CB0, func_01B00C80);
    func_0019FF90(&D_00313CB0, func_01B00D68);
    func_001A1D08(task, func_01B00908);
    func_001A1DF0(task, 8);
}

/* target cue */
void func_01B00908(W3Task *t)
{
    W3Task *task = t;
    int tgt = D_00313CB0.targets[0];

    func_001A4288(1);
    func_001A3800(tgt, 0);
    func_001A1D08(task, func_01B00968);
    func_001A1D50(task, func_001A21E0);
}

void func_01B00968(W3Task *t)
{
    W3Task *task = t;

    func_001A1D08(task, func_01B009A0);
    func_001A1D50(task, func_01B00968);
}

void func_01B009A0(W3Task *t)
{
    t->flags |= 4;
}

/* caster motion 106 */
void func_01B009B0(W3Task *t)
{
    RcefObj *o = (RcefObj *)t;
    int caster = D_00313CB0.caster;

    func_001A2B80(caster, 106);
    func_001A1D08(t, func_01B00A20);
    func_001A1D50(t, func_001A2148);
    o->task.frame[o->task.sp].count = caster;
}

void func_01B00A20(W3Task *t)
{
    RcefObj *o = (RcefObj *)t;

    func_001A2B68();
    t->flags |= 4;
}

/* spark, optpos 37, z -17, scale 0.075 */
void func_01B00A50(W3Task *t)
{
    RcefObj *o = (RcefObj *)t;

    func_001A1378(o, D_00313CB0.caster, 37);
    o->pos[0] = 0;
    o->pos[1] = -23.0f;
    o->pos[2] = 0;
    o->pos_w = 0;
    o->scale[0] = 0.075f;
    o->scale[1] = 0.075f;
    o->scale[2] = 0.075f;
    o->scale[3] = 0;
    rcefMainKickPar(&D_00313CB0, o, 0, 3);
    func_001A1D08(t, func_01B009A0);
    func_001A1D50(t, func_001A20D8);
}

/* spark, optpos 37, z -17, scale 0.05 */
void func_01B00AF0(W3Task *t)
{
    RcefObj *o = (RcefObj *)t;

    func_001A1378(o, D_00313CB0.caster, 37);
    o->pos[0] = 0;
    o->pos[1] = -23.0f;
    o->pos[2] = 0;
    o->pos_w = 0;
    o->scale[0] = 0.05f;
    o->scale[1] = 0.05f;
    o->scale[2] = 0.05f;
    o->scale[3] = 0;
    rcefMainKickPar(&D_00313CB0, o, 0, 4);
    func_001A1D08(t, func_01B009A0);
    func_001A1D50(t, func_001A20D8);
}

/* ground flash on target: pos from optpos, scale pulse */
void func_01B00B90(W3Task *t)
{
    RcefObj *o = (RcefObj *)t;
    float v1[4];
    union { int i[4]; float f[4]; } v3;
    float v2[4];
    RcefMainCtx *ctx = &D_00313CB0;

    v2[0] = 0;
    v2[1] = -23.0f;
    v2[2] = 0;
    v2[3] = 0;
    func_001A2F50(ctx->caster, 37, v2, v1);
    v3.f[1] = -15.0f;
    o->pos[0] = v1[0];
    o->pos[1] = v1[1];
    o->pos[2] = v1[2];
    v3.i[0] = 0;
    v3.i[2] = 0;
    v3.i[3] = 0;
    o->vel[0] = v3.f[0];
    o->vel[1] = -15.0f;
    o->vel[2] = v3.f[0];
    o->vel[3] = v3.f[0];
    o->scale[0] = 0.045f;
    o->scale[1] = 0.045f;
    o->scale[2] = 0.045f;
    o->pos_w = 0;
    o->scale[3] = v3.f[0];
    rcefMainKickPar(ctx, o, 0, 0);
    func_001A1D08(t, func_01B009A0);
    func_001A1DF0(t, 10);
}

/* same, mirrored scale */
void func_01B00C80(W3Task *t)
{
    RcefObj *o = (RcefObj *)t;
    float v[4];
    union { int i[4]; float f[4]; } w;
    RcefMainCtx *ctx = &D_00313CB0;

    func_001A3000(ctx->targets[0], 6, v);
    v[1] = v[1] - 150.0f;
    w.f[1] = 15.0f;
    o->pos[0] = v[0];
    o->pos[1] = v[1];
    o->pos[2] = v[2];
    w.i[0] = 0;
    w.i[2] = 0;
    w.i[3] = 0;
    o->vel[0] = w.f[0];
    o->vel[1] = 15.0f;
    o->vel[2] = w.f[0];
    o->vel[3] = w.f[0];
    o->scale[0] = 0.045f;
    o->scale[1] = 0.045f;
    o->scale[2] = 0.045f;
    o->pos_w = 0;
    o->scale[3] = w.f[0];
    rcefMainKickPar(ctx, o, 0, 0);
    func_001A1D08(t, func_01B009A0);
    func_001A1DF0(t, 10);
}

/* mote on first target */
void func_01B00D68(W3Task *t)
{
    RcefObj *o = (RcefObj *)t;

    func_001A13A0(o, D_00313CB0.targets[0], 0);
    func_001A1420(o, 16);
    o->pos[0] = 0;
    o->pos[1] = -0.1f;
    o->pos[2] = 0;
    o->pos_w = 0;
    o->scale[0] = 0.06f;
    o->scale[1] = 0.06f;
    o->scale[2] = 0.06f;
    o->scale[3] = 0;
    rcefMainKickPar(&D_00313CB0, o, 0, 1);
    func_001A1D08(t, func_01B009A0);
    func_001A1D50(t, func_001A20D8);
}

int func_01B00E18(int eff_id)
{
    func_0019FC00(&D_00313CB0, eff_id, D_01B00F50, 0x01E80000, 0x00080000, 0x01D80000, 1, D_01B00608, D_01B00610);
    func_0019FF90(&D_00313CB0, func_01B00648);
    return 0;
}

int func_01B00E88(void)
{
    func_0019FDF0(&D_00313CB0);
    return 0;
}

int func_01B00EB0(void)
{
    func_0019FE38(&D_00313CB0);
    return 0;
}

int func_01B00ED8(void)
{
    func_0019FE48(&D_00313CB0);
    return 0;
}

int func_01B00F00(void)
{
    func_0019FE58(&D_00313CB0);
    return 0;
}

int func_01B00F28(void)
{
    return 0;
}

int func_01B00F30(void)
{
    return 0;
}

int func_01B00F38(void)
{
    return 0;
}

int func_01B00F40(void)
{
    return 0;
}
