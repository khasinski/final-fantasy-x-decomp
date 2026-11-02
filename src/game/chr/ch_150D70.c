/* tu_091 0x150d70-0x152308: low; ~Ch (config/tu_map.tsv) */
#include "common.h"
#include "ffx/q2.h"
#include "ffx/w2.h"
#include "ffx/r1.h"
#include "ffx/s1.h"
#include "ffx/u1.h"

int func_00150D70(Actor *a, void *op, ScriptCtx *ctx)
{
    Chr *r1;
    int r2;

    r1 = AtelGetCharHandle(a);
    r2 = AtelPopStackInteger(a, ctx);
    if (r1 == 0) {
        return 0;
    }
    Ch_SetFieldMode_I(r1, r2);
    Ch_SetMotionType_I(r1, r2);
    return 0;
}

int func_00150DE0(Actor *a, void *op, ScriptCtx *ctx)
{
    Chr *c = AtelGetCharHandle(a);
    int n = AtelPopStackInteger(a, ctx);
    float v = AtelPopStackFloat(a, ctx);

    if (c == 0) {
        return 0;
    }
    func_001103A8(c, v, n);
    return 0;
}

int func_00150E58(Actor *a, void *op, ScriptCtx *ctx)
{
    Chr *c = AtelGetCharHandle(a);
    int n = AtelPopStackInteger(a, ctx);
    float z = AtelPopStackFloat(a, ctx);
    float y = AtelPopStackFloat(a, ctx);
    float x = AtelPopStackFloat(a, ctx);

    if (c == 0) {
        return 0;
    }
    Ch_SetShadeCol(c, x, y, z, n);
    return 0;
}

int func_00150F08(Actor *a, void *op, ScriptCtx *ctx)
{
    Chr *r1;
    float r2;
    float r3;
    float r4;

    r1 = AtelGetCharHandle(a);
    r2 = AtelPopStackFloat(a, ctx);
    r3 = AtelPopStackFloat(a, ctx);
    r4 = AtelPopStackFloat(a, ctx);
    if (r1 == 0) {
        return 0;
    }
    Ch_SetOffset(r1, r4, r3, r2);
    return 0;
}

int func_00150FA0(Actor *a, void *op, ScriptCtx *ctx)
{
    Chr *r1;
    int r2;

    r1 = AtelGetCharHandle(a);
    r2 = AtelPopStackInteger(a, ctx);
    if (r1 == 0) {
        return 0;
    }
    Ch_SetGravMode_I(r1, r2);
    return 0;
}

int func_00151000(Actor *a, void *op, ScriptCtx *ctx)
{
    Chr *r1;
    int r2;

    r1 = AtelGetCharHandle(a);
    r2 = AtelPopStackInteger(a, ctx);
    if (r1 == 0) {
        return 0;
    }
    Ch_SetMotionSpeed_I(r1, r2);
    return 0;
}

int func_00151060(int a, int b, int c)
{
    func_00151F68(a, c, 0, 0);
    return 0;
}

int func_00151088(int a, int b, int c)
{
    func_00151F68(a, c, 1, 0);
    return 0;
}

int func_001510B0(Actor *a, void *op, ScriptCtx *ctx)
{
    func_001521D8(a, ctx, 0);
    return 0;
}

int func_001510D8(Actor *a, void *op, ScriptCtx *ctx)
{
    func_001521D8(a, ctx, 0);
    return 0;
}

void func_00151100(void) {
}

int func_00151108(Actor *a)
{
    Chr *c = AtelGetCharHandle(a);

    if (c == 0) {
        return 0;
    }
    return c->b742 ? 0 : 5;
}

int func_00151140(void)
{
    Chr *c = AtelGetCharHandle();

    if (c == 0) {
        return 0;
    }
    return c->b742 != 0;
}

int func_00151170(void)
{
    Chr *c = AtelGetCharHandle();

    if (!c) {
        return 0;
    }
    Ch_ResetMotion(c);
    return 0;
}

int func_001511A0(Actor *a, void *op, ScriptCtx *ctx)
{
    Chr *r1;
    int r2;

    r1 = AtelGetCharHandle(a);
    r2 = AtelPopStackInteger(a, ctx);
    if (r1 == 0) {
        return 0;
    }
    Ch_SetMotionSpeed_I(r1, r2);
    return 0;
}

int func_00151200(Actor *a, void *op, ScriptCtx *ctx)
{
    Chr *r1;
    int r2;

    r1 = AtelGetCharHandle(a);
    r2 = AtelPopStackInteger(a, ctx);
    if (r1 == 0) {
        return 0;
    }
    func_00105750_I(r1, r2);
    return 0;
}

int func_00151260(Actor *a, void *op, ScriptCtx *ctx)
{
    Chr *c = AtelGetCharHandle(a);

    AtelPopStackInteger(a, ctx);
    if (c == 0) {
        return 0;
    }
    return 0;
}

int func_001512B0(Actor *a, void *op, ScriptCtx *ctx)
{
    Chr *c = AtelGetCharHandle(a);

    AtelPopStackInteger(a, ctx);
    if (c == 0) {
        return 0;
    }
    return 0;
}

int func_00151300(Actor *a, void *op, ScriptCtx *ctx)
{
    Chr *chr;
    int v1;
    int v2;

    chr = AtelGetCharHandle(a);
    v1 = AtelPopStackInteger(a, ctx);
    v2 = AtelPopStackInteger(a, ctx);
    if (chr == 0) {
        return 0;
    }
    func_00110850(chr, v2, v1);
    return 0;
}

int func_00151378(Actor *a, void *op, ScriptCtx *ctx)
{
    int z;
    int y;
    int x;
    int bone;
    int id;
    Chr *c;
    Vec4 out;

    z = AtelPopStackInteger(a, ctx);
    y = AtelPopStackInteger(a, ctx);
    x = AtelPopStackInteger(a, ctx);
    bone = AtelPopStackInteger(a, ctx);
    id = AtelPopStackInteger(a, ctx);
    /* the variable ids are replaced by the addresses of the variables */
    x = AtelGetRealVarAdrs(a, x);
    y = AtelGetRealVarAdrs(a, y);
    z = AtelGetRealVarAdrs(a, z);
    c = AtelGetCharHandle(AtelGetBasicWork(id));
    if (c == 0) {
        return 0;
    }
    func_00107428(c, bone, 0, &out);
    if (x != 0) {
        *(float *)x = out.x; /* DEBT(CAST): AtelGetRealVarAdrs returns the address as int */
    }
    if (y != 0) {
        *(float *)y = out.y; /* DEBT(CAST) */
    }
    if (z != 0) {
        *(float *)z = out.z; /* DEBT(CAST) */
    }
    return 0;
}

int func_00151490(Actor *a, void *op, ScriptCtx *ctx)
{
    int z;
    int y;
    int x;
    float fz;
    float fy;
    float fx;
    int bone;
    int id;
    Chr *c;
    Vec4 out;
    Vec4 in;

    z = AtelPopStackInteger(a, ctx);
    y = AtelPopStackInteger(a, ctx);
    x = AtelPopStackInteger(a, ctx);
    fz = AtelPopStackFloat(a, ctx);
    fy = AtelPopStackFloat(a, ctx);
    fx = AtelPopStackFloat(a, ctx);
    bone = AtelPopStackInteger(a, ctx);
    id = AtelPopStackInteger(a, ctx);
    /* the variable ids are replaced by the addresses of the variables */
    x = AtelGetRealVarAdrs(a, x);
    y = AtelGetRealVarAdrs(a, y);
    z = AtelGetRealVarAdrs(a, z);
    c = AtelGetCharHandle(AtelGetBasicWork(id));
    if (c == 0) {
        return 0;
    }
    in.x = fx;
    in.y = fy;
    in.z = fz;
    in.w = 1.0f;
    func_00107428(c, bone, &in, &out);
    if (x != 0) {
        *(float *)x = out.x; /* DEBT(CAST): AtelGetRealVarAdrs returns the address as int */
    }
    if (y != 0) {
        *(float *)y = out.y; /* DEBT(CAST) */
    }
    if (z != 0) {
        *(float *)z = out.z; /* DEBT(CAST) */
    }
    return 0;
}

float func_00151608(Actor *a, void *op, ScriptCtx *ctx)
{
    Chr *c = AtelGetCharHandle(a);
    float v = AtelPopStackFloat(a, ctx);

    if (c == 0) {
        return 0.0f;
    }
    return func_00110888(c, v);
}

int func_00151670(Actor *a, void *op, ScriptCtx *ctx)
{
    Chr *c = AtelGetCharHandle(a);
    int v = AtelPopStackInteger(a, ctx);

    if (c == 0) {
        return 0;
    }
    return ((int (*)(Chr *, int))func_001108B8)(c, v); /* DEBT(CAST): the original call passes v without narrowing it to s8 */
}

int func_001516D0(Actor *a, void *op, ScriptCtx *ctx)
{
    Chr *chr;
    int v1;

    chr = AtelGetCharHandle(a);
    v1 = AtelPopStackInteger(a, ctx);
    if (chr == 0) {
        return 0;
    }
    return Ch_EnClip(chr, v1);
}

int func_00151730(void) {
    AtelGetCharHandle();
    return 0;
}

int func_00151750(Actor *a, void *op, ScriptCtx *ctx)
{
    Chr *c = AtelGetCharHandle(a);
    int v = AtelPopStackInteger(a, ctx);
    int id = AtelPopStackInteger(a, ctx);

    if (c == 0) {
        return 0;
    }
    if (id != -1) {
        func_00107210(c, AtelGetCharHandle(AtelGetBasicWork(id)), v);
    } else {
        func_00107210(c, 0, 0);
    }
    return 0;
}

int func_00151800(Actor *a, void *op, ScriptCtx *ctx)
{
    Chr *c = AtelGetCharHandle(a);
    int v = AtelPopStackInteger(a, ctx);
    int id = AtelPopStackInteger(a, ctx);

    if (c == 0) {
        return 0;
    }
    if (id != -1) {
        Ch_BindToElem(c, AtelGetCharHandle(AtelGetBasicWork(id)), v);
    } else {
        Ch_BindToElem(c, 0, 0);
    }
    return 0;
}

int func_001518B0(Actor *a, void *op, ScriptCtx *ctx)
{
    Chr *chr;

    chr = AtelGetCharHandle(a);
    if (chr == 0) {
        return 0;
    }
    return Ch_IdGetMap(chr);
}

int func_001518E8(Actor *a, void *op, ScriptCtx *ctx)
{
    Chr *chr;

    chr = AtelGetCharHandle(AtelGetBasicWork(AtelPopStackInteger(a, ctx)));
    if (chr == 0) {
        return 0;
    }
    return Ch_IdGetMap(chr);
}

int func_00151930(Actor *a, void *op, ScriptCtx *ctx)
{
    Chr *chr;

    chr = AtelGetCharHandle(a);
    if (chr == 0) {
        return 0;
    }
    return func_00121AA0(chr);
}

int func_00151968(Actor *a, void *op, ScriptCtx *ctx)
{
    Chr *chr;

    chr = AtelGetCharHandle(AtelGetBasicWork(AtelPopStackInteger(a, ctx)));
    if (chr == 0) {
        return 0;
    }
    return func_00121AA0(chr);
}

int func_001519B0(void)
{
    Chr *c = AtelGetCharHandle();

    if (!c) {
        return 0;
    }
    func_00105320(c);
    return 0;
}

int func_001519E0(Actor *a, void *op, ScriptCtx *ctx)
{
    Chr *c = AtelGetCharHandle(a);
    int n = AtelPopStackInteger(a, ctx);
    float v = AtelPopStackFloat(a, ctx);

    if (c == 0) {
        return 0;
    }
    func_00110540(c, v, n);
    return 0;
}

int func_00151A58(Actor *a, void *op, ScriptCtx *ctx)
{
    Chr *chr;
    int v1;

    chr = AtelGetCharHandle(a);
    v1 = AtelPopStackInteger(a, ctx);
    if (chr == 0) {
        return 0;
    }
    Ch_MotionSetHokan(chr, v1);
    return 0;
}

int func_00151AB8(Actor *a, void *op, ScriptCtx *ctx)
{
    Chr *chr;

    chr = AtelGetCharHandle(a);
    if (chr == 0) {
        return 0;
    }
    return Ch_GetSeqFrame(chr);
}

int Ch_OptposGet_(int a, int op, int ctx, int mode) /* DEBT(TYPE): q2.h declares ints for (Actor *, op, ScriptCtx *, mode) */
{
    Actor *actor = (Actor *)a;
    ScriptCtx *sc = (ScriptCtx *)ctx;
    int bone = 0;
    int z;
    int y;
    int x;
    int id;
    Chr *c;
    float pos[4];

    z = AtelPopStackInteger(actor, sc);
    y = AtelPopStackInteger(actor, sc);
    x = AtelPopStackInteger(actor, sc);
    if (mode == 0) {
        bone = AtelPopStackInteger(actor, sc);
    }
    id = AtelPopStackInteger(actor, sc);
    /* the variable ids are replaced by the addresses of the variables */
    x = AtelGetRealVarAdrs(actor, x);
    y = AtelGetRealVarAdrs(actor, y);
    z = AtelGetRealVarAdrs(actor, z);
    c = AtelGetCharHandle(AtelGetBasicWork(id));
    if (c == 0) {
        return 0;
    }
    switch (mode) {
    case 0:
        Ch_OptposGet(c, bone, pos);
        break;
    case 1:
        Ch_OptposGet(c, 0, pos);
        break;
    case 2:
        *(V128 *)pos = c->v6C0; /* DEBT(CAST): v6C0 holds a position vector */
        break;
    }
    if (x != 0) {
        *(float *)x = pos[0]; /* DEBT(CAST): AtelGetRealVarAdrs returns the address as int */
    }
    if (y != 0) {
        *(float *)y = pos[1]; /* DEBT(CAST) */
    }
    if (z != 0) {
        *(float *)z = pos[2]; /* DEBT(CAST) */
    }
    return 0;
}

int func_00151C68(int a, int b, int c)
{
    Ch_OptposGet_(a, b, c, 0);
    return 0;
}

int func_00151C88(int a, int b, int c)
{
    Ch_OptposGet_(a, b, c, 1);
    return 0;
}

int func_00151CA8(int a, int b, int c)
{
    Ch_OptposGet_(a, b, c, 2);
    return 0;
}

float func_00151CC8(Actor *a, void *op, ScriptCtx *ctx)
{
    Chr *c = AtelGetCharHandle(a);
    float v = AtelPopStackFloat(a, ctx);

    if (c == 0) {
        return 0.0f;
    }
    return Ch_SetThickness(c, v);
}

float func_00151D30(Actor *a, void *op, ScriptCtx *ctx)
{
    Chr *c = AtelGetCharHandle(a);
    float v = AtelPopStackFloat(a, ctx);

    if (c == 0) {
        return 0.0f;
    }
    return Ch_SetClipZ(c, v);
}

int func_00151D98(Actor *a, void *op, ScriptCtx *ctx)
{
    Chr *chr;
    int v1;
    int v2;

    chr = AtelGetCharHandle(a);
    v1 = AtelPopStackInteger(a, ctx);
    v2 = AtelPopStackInteger(a, ctx);
    if (chr == 0) {
        return 0;
    }
    ChN_DisposeSystemMGRP(v2, v1);
    return 0;
}

int func_00151E10(Actor *a, void *op, ScriptCtx *ctx)
{
    func_00104EE0(AtelPopStackInteger(a, ctx));
    return 0;
}

int func_00151E38(Actor *a, void *op, ScriptCtx *ctx)
{
    ChN_DataDispose(AtelPopStackInteger(a, ctx), 1);
    return 0;
}

int func_00151E68(Actor *a, void *op, ScriptCtx *ctx)
{
    int v1;

    v1 = AtelPopStackInteger(a, ctx);
    ChN_DataDispose(AtelPopStackInteger(a, ctx), v1);
    return 0;
}

int func_00151EC8(Actor *a, void *op, ScriptCtx *ctx)
{
    int v1;
    Chr *chr;

    v1 = AtelPopStackInteger(a, ctx);
    chr = AtelGetCharHandle(a);
    if (chr == 0) {
        return 0;
    }
    Ch_SetSequence(chr, v1);
    return 0;
}

int func_00151F18(Actor *a, void *op, ScriptCtx *ctx)
{
    int v1;
    Chr *chr;

    v1 = AtelPopStackInteger(a, ctx);
    chr = AtelGetCharHandle(a);
    if (chr == 0) {
        return 0;
    }
    Ch_SetSequence(chr, v1);
    return 0;
}

int func_00151F68(int a, int ctx, int mode, int other) /* DEBT(TYPE): q2.h declares ints for (Actor *, ScriptCtx *, mode, other) */
{
    Actor *actor = (Actor *)a;
    ScriptCtx *sc = (ScriptCtx *)ctx;
    int v1;
    int v2;
    int v3;
    int v4;
    int v5;
    Chr *c;

    v1 = AtelPopStackInteger(actor, sc);
    v2 = AtelPopStackInteger(actor, sc);
    v3 = AtelPopStackInteger(actor, sc);
    v4 = AtelPopStackInteger(actor, sc);
    v5 = AtelPopStackInteger(actor, sc);
    if (other) {
        c = AtelGetCharHandle(AtelGetBasicWork(AtelPopStackInteger(actor, sc)));
    } else {
        c = AtelGetCharHandle(actor);
    }
    if (c == 0) {
        return 0;
    }
    switch (mode) {
    case 0:
        func_00105670(c, v5, v4, v3, v2, v1);
        break;
    case 1:
        func_00105500(c, v5, v4, v3, v2, v1);
        break;
    case 2:
        func_001055B0(c, v5, v4, v3, v2, v1);
        break;
    }
    return 0;
}

int func_001520E8(int a, int b, int c)
{
    func_00151F68(a, c, 0, 0);
    return 0;
}

int func_00152110(int a, int b, int c)
{
    func_00151F68(a, c, 1, 0);
    return 0;
}

int func_00152138(int a, int b, int c)
{
    func_00151F68(a, c, 0, 1);
    return 0;
}

int func_00152160(int a, int b, int c)
{
    func_00151F68(a, c, 1, 1);
    return 0;
}

int func_00152188(int a, int b, int c)
{
    func_00151F68(a, c, 0, 1);
    return 0;
}

int func_001521B0(int a, int b, int c)
{
    func_00151F68(a, c, 1, 1);
    return 0;
}

int func_001521D8(Actor *a, ScriptCtx *ctx, int other)
{
    int v = AtelPopStackInteger(a, ctx);
    Chr *c;

    if (other) {
        a = AtelGetBasicWork(AtelPopStackInteger(a, ctx));
    }
    c = AtelGetCharHandle(a);
    if (c == 0) {
        return 0;
    }
    Ch_SetSequence(c, v);
    return 0;
}

int func_00152258(Actor *a, void *op, ScriptCtx *ctx)
{
    func_001521D8(a, ctx, 1);
    return 0;
}

int func_00152280(Actor *a, void *op, ScriptCtx *ctx)
{
    func_001521D8(a, ctx, 1);
    return 0;
}

int func_001522A8(Actor *a, Chr **work, ScriptCtx *ctx)
{
    *work = AtelGetCharHandle(AtelGetBasicWork(AtelPopStackInteger(a, ctx)));
}

int func_001522E8(Actor *a, Chr **work)
{
    Chr *c = *work;

    if (c == 0) {
        return 0;
    }
    return c->b742 ? 0 : 5;
}
