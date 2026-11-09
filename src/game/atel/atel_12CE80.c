/* tu_056 0x12ce80-0x12d498: low; unk_12CE80 (config/tu_map.tsv) */
/* Field-script opcode handlers (module name unknown; no source-file string found). See ffx/w1.h. */
#include "common.h"
#include "ffx/q0.h"
#include "ffx/w1.h"
#include "ffx/r0.h"
#include "ffx/u0.h"
#include "ffx/v0.h"

void func_0012CE80(Actor *a, OpArgs *op, ScriptCtx *ctx)
{
    op->v0 = AtelPopStackInteger(a, ctx);
    func_0014AA00();
    func_00138BF8(1);
    AtelGetCurCtrlWork();
}

s32 func_0012CEB8(Actor *a, s32 *op, ScriptCtx *ctx)
{
    s32 r = 0;

    func_0014AD28(op[0]);
    if (MsEventEffectGetStat() == 1) {
        AtelGetCurCtrlWork();
        r = 5;
    }
    return r;
}

void func_0012CF00(void) {
}

s32 func_0012CF08(Actor *a)
{
    s32 v = AtelCheckEventEffectStart(a->id);

    if (v & 1) {
        AtelGetCurCtrlWork();
    }
    return v;
}

s32 func_0012CF48(void)
{
    s32 r = MsEventEffectGetStat();

    switch (r) {
    case 0:
    case 6:
        r = 0;
        break;
    case 1:
    case 3:
    case 5:
        r = 1;
        break;
    }
    return r;
}

int func_0012CFA0(Actor *a) {
    return func_0014A498(a->id);
}

int func_0012CFC0(Actor *a, void *op, ScriptCtx *ctx) {
    int v = AtelPopStackInteger(a, ctx);

    SndSepPlaySimple(v);
    return v;
}

int SndIsSepPlay(int a);
int func_00138E90(ScrBlobQ *b);
int func_00138ED8(ScrBlobQ *b, int i);
int func_00138F30(ScrBlobQ *b, int i);
void SndSepVolumeTranslate(int a, int b, int c);

int func_0012CFF8(Actor *a, void *op, ScriptCtx *ctx)
{
    int v = AtelPopStackInteger(a, ctx);
    int flag;
    u8 b28;
    int i;
    int n;
    int vol;

    if (SndIsSepPlay(v) == 0) {
        SndSepPlaySimple(v);
    } else {
        flag = 0;
        b28 = ((u8 *)func_00124828())[0x28];
        i = 0;
        n = func_00138E90(a->blob);
        for (; i < n; i++) {
            int x = func_00138ED8(a->blob, i);
            int y = func_00138F30(a->blob, i);
            if (x == v) {
                flag = y;
                break;
            }
        }
        vol = 0x7F;
        if (b28 != 0) {
            vol = 0x3F;
        }
        if ((flag & 0x40) == 0) {
            SndSepVolumeTranslate(v, 0xC, vol);
        }
    }
    return v;
}

void func_002D7B80(int a, int b, int c);

int func_0012D0E8(Actor *a, void *op, ScriptCtx *ctx)
{
    int vol = AtelPopStackInteger(a, ctx);
    int pan = AtelPopStackInteger(a, ctx);
    int v = AtelPopStackInteger(a, ctx);
    int flag;
    u8 b28;
    int i;
    int n;

    if (SndIsSepPlay(v) == 0) {
        SndSepPlay(v, pan, vol);
    } else {
        flag = 0;
        b28 = ((u8 *)func_00124828())[0x28];
        i = 0;
        n = func_00138E90(a->blob);
        for (; i < n; i++) {
            int x = func_00138ED8(a->blob, i);
            int y = func_00138F30(a->blob, i);
            if (x == v) {
                flag = y;
                break;
            }
        }
        if (b28 != 0) {
            vol /= 2;
        }
        if ((flag & 0x40) == 0) {
            SndSepVolumeTranslate(v, 0xC, vol);
            func_002D7B80(v, 0xC, pan);
        }
    }
    return v;
}

int func_0012D230(Actor *a, void *op, ScriptCtx *ctx) {
    int x = AtelPopStackInteger(a, ctx);
    int y = AtelPopStackInteger(a, ctx);
    int z = AtelPopStackInteger(a, ctx);

    SndSepPlay(z, y, x);
    return z;
}

int func_0012D2B0(Actor *a, void *op, ScriptCtx *ctx) {
    int x = AtelPopStackInteger(a, ctx);
    int y = AtelPopStackInteger(a, ctx);

    SndSepVolumeDirect(y, x);
    return x;
}

int func_0012D310(Actor *a, void *op, ScriptCtx *ctx) {
    int x = AtelPopStackInteger(a, ctx);
    int y = AtelPopStackInteger(a, ctx);

    SndSepPanDirect(y, x);
    return x;
}

int func_0012D370(Actor *a, void *op, ScriptCtx *ctx) {
    int x = AtelPopStackInteger(a, ctx);
    int y = AtelPopStackInteger(a, ctx);
    int z = AtelPopStackInteger(a, ctx);

    SndSepVolumeTranslate(z, y, x);
    return x;
}

int func_0012D3E8(Actor *a, void *op, ScriptCtx *ctx) {
    int x = AtelPopStackInteger(a, ctx);
    int y = AtelPopStackInteger(a, ctx);
    int z = AtelPopStackInteger(a, ctx);

    func_002D7B80(z, y, x);
    return x;
}

int func_0012D460(Actor *a, void *op, ScriptCtx *ctx) {
    int v = AtelPopStackInteger(a, ctx);

    SndSepStop(v);
    return v;
}
