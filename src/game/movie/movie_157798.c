/* tu_101 0x157798-0x15a560: low; ~movie (config/tu_map.tsv) */
#include "common.h"
#include "ffx/q2.h"
#include "ffx/w2.h"
#include "ffx/r1.h"
#define func_00159CD8 s1_func_00159CD8 /* DEBT(TYPE): this header's guess conflicts with the TU */
#include "ffx/s1.h"
#undef func_00159CD8
#include "ffx/b0.h"
#include "ffx/q3.h"
#include "ffx/u1.h"
#include "ffx/v1.h"

u8 *func_00157798(void)
{
    return D_0056B590;
}

void func_001577A8(void *a, void *b, int line)
{
    func_00157798();
    printf_write();
    BREAK();
}

int func_001577D0(void)
{
    return func_002B3888(0x28F0);
}

void func_001577F0(void) {
    func_002B39C0(10480);
}

s8 func_001577F8(void)
{
    return D_0030D406;
}

void func_00157808(void)
{
    D_0030D406 = 1;
}

void sa_cd_callback_init(int on)
{
    func_00171648(on);
    func_002E08F0(0x1E, D_0058FE70, sizeof(D_0058FE70));
    ((int (*)(void (*)(int)))func_0015B830)(func_0015B808); /* DEBT(CAST): q-header declares no parameter, the caller passes a callback */
    if (FFXIsPC() == 1) {
        if (on == 0) {
            CdEnvInit(0);
        } else {
            CdEnvInit(1);
        }
        if (FFXIsDebug()) {
            MsEnvInit();
        }
    } else {
        CdEnvInit(1);
    }
}

void func_001578B8(void)
{
    D_0030D3EC = 0;
    D_0030D408 = 0;
    D_0058FE50 = 0;
    D_0058FE54 = 0;
    D_0058FE58 = 0;
    D_0058FE5C = 0;
    D_0058FE68 = 0;
    D_0058FE6C = 0;
    D_0030D410 = 0;
    D_0030D414 = 0;
    D_0030D3E8 = 0;
    if (FFXIsDebug()) {
        func_206DC28();
    }
    func_001608D0();
}

void func_00157938(void) {
}

void func_00157940(void) {
}

void func_00157948(int a) {
    if (a != 0) {
        D_0030D414 = 3;
    } else {
        D_0030D414 = 0;
    }
}

INCLUDE_ASM("build/ee_asm/game/movie/movie_157798", func_00157968);

INCLUDE_ASM("build/ee_asm/game/movie/movie_157798", func_00157BE8);

INCLUDE_ASM("build/ee_asm/game/movie/movie_157798", func_00158200);

INCLUDE_ASM("build/ee_asm/game/movie/movie_157798", func_00158410);

void func_00158500(void) {
}

void func_00158508(int bits)
{
    if (D_0058FE50 == 0) {
        func_001577A8(D_0056B5A8, D_0056B5C0, 0x31F);
    }
    D_0058FE54->w505C0 |= bits;
}

void func_00158568(int bits)
{
    if (D_0058FE50 == 0) {
        func_001577A8(D_0056B5A8, D_0056B5C0, 0x324);
    }
    D_0058FE54->w505C0 &= ~bits;
}

void func_001585D0(void)
{
    if (D_0058FE50 == 0) {
        func_001577A8(D_0056B5A8, D_0056B5C0, 0x329);
    }
    D_0058FE50 = 0;
    if (D_0058FE68 != 0) {
        D_0058FE68 = 0;
        D_0058FE6C = 0;
    }
    D_0030D418->f4();
    D_0030D418 = 0;
    D_0030D3EC = 0;
    D_0030D410 = 0;
    D_0058FE54 = 0;
}

void func_00158660(void)
{
    if (D_0030D404 != 0) {
        D_0030D404 = 0;
        func_0020D468();
    }
    if (D_0058FE54 != 0) {
        D_0058FE54->b5076D = 0;
        if (D_0058FE54->b50773 != 0) {
            yiRenderDisable(0x800);
        }
    }
    if (D_0030D405 != 0) {
        MsSetCameraMatrix(0, 0, 0, 0, 0, 0);
        D_0030D405 = 0;
    }
}

void func_001586F8(void)
{
    if (D_0030D405 != 0) {
        if (D_0058FE54 != 0) {
            D_0058FE54->b5076D = 0;
        }
        MsSetCameraMatrix(0, 0, 0, 0, 0, 0);
        D_0030D405 = 0;
    }
}

void func_00158758(int *p) {
    p[0] = 0;
    p[1] = 0;
}

INCLUDE_ASM("build/ee_asm/game/movie/movie_157798", func_00158768);

INCLUDE_ASM("build/ee_asm/game/movie/movie_157798", func_00158868);

INCLUDE_ASM("build/ee_asm/game/movie/movie_157798", func_001588F8);

int func_00158948(void) {
    return D_0030D40C;
}

INCLUDE_ASM("build/ee_asm/game/movie/movie_157798", func_00158958);

int func_001589A8(void) {
    if (D_0058FE50 == 0 || D_0030D3EC == 0) {
        return 0xFFFF;
    }
    return D_0058FE54->w50708;
}

int func_001589E0(void) {
    if (D_0058FE50 == 0 || D_0030D3EC == 0) {
        return 0xFFFF;
    }
    return D_0058FE54->w50708;
}

int func_00158A18(void) {
    func_00159650();
    return 1;
}

int func_00158A38(void) {
    int v;

    Sg_GetDBuffDC(&v);
    func_002B3168(v & 1);
    return 1;
}

void func_00158A68(void) {
    if (D_0030D410 == 1 && D_0058FE50 != 0 && D_0030D3EC != 0) {
        func_00158508(8);
    }
}

INCLUDE_ASM("build/ee_asm/game/movie/movie_157798", func_00158AA8);
INCLUDE_RODATA("build/ee_asm/game/movie/movie_157798/rodata", jtbl_0056B5E0);

INCLUDE_ASM("build/ee_asm/game/movie/movie_157798", func_00158D60);

int func_00158E80(int a, int b, Arg68 r)
{
    return 0;
}

int func_00158F48(Actor *actor, int unused, ScriptCtx *op)
{
    if (D_0058FE50 != 0)
    {
        if (D_0030D3EC == 0)
            return 0;
        if (AtelPopStackInteger(actor, op) == 0)
            func_00158568(0x40);
        else
            func_00158508(0x40);
    }
    return 0;
}

int func_00158FA8(Actor *a, void *op, ScriptCtx *ctx) {
    int v = AtelPopStackInteger(a, ctx);

    D_0030D3F0 = v % 2;
    return 0;
}

INCLUDE_ASM("build/ee_asm/game/movie/movie_157798", func_00158FE8);

s32 func_00159050(Actor *arg0, int unused1, ScriptCtx *arg2)
{
    s32 value0;
    s32 value1;

    value0 = AtelPopStackInteger(arg0, arg2);
    value1 = AtelPopStackInteger(arg0, arg2);
    D_0030D3F8 = value0;
    D_0030D3F4 = value1;
    return 0;
}

void func_001590B0(Actor *a, void *op, ScriptCtx *ctx)
{
    int first = AtelPopStackInteger(a, ctx);
    int second = AtelGetRealVarAdrs(a, AtelPopStackInteger(a, ctx));
    int *out = op;

    out[0] = first;
    out[1] = second;
}

int func_00159120(void) {
    return func_002D6788() ? 0 : 5;
}

INCLUDE_ASM("build/ee_asm/game/movie/movie_157798", func_00159148);

INCLUDE_ASM("build/ee_asm/game/movie/movie_157798", func_00159368);

void func_00159640(int v) {
    D_0030D400 = v;
}

void func_00159650(void) {
    if (D_0058FE50 != 0) {
        D_0058FE54->w505C0 &= 0xFFFEFFFF;
    }
}

INCLUDE_ASM("build/ee_asm/game/movie/movie_157798", rcuiSceneInit);

INCLUDE_ASM("build/ee_asm/game/movie/movie_157798", func_001596C8);

void func_00159A88(Actor *a, int *out, ScriptCtx *ctx)
{
    int x;
    int y;

    func_002D6788();
    x = AtelPopStackInteger(a, ctx);
    y = AtelPopStackInteger(a, ctx);
    out[0] = x;
    out[1] = y;
}

int func_00159AF0(void) {
    return func_002D6788() ? 0 : 5;
}

int func_00159B18(int a, int *b) {
    func_001596C8(b[1], b[0]);
    return 0;
}

void func_00159B40(void) {
}

int func_00159B48(void)
{
    u32 f;

    if (D_0058FE50 == 0 || D_0030D3EC == 0) {
        return 5;
    }
    f = D_0058FE54->w505C0;
    if (f & 0x8000) {
        return 5;
    }
    if (!(f & 0x100)) {
        return 5;
    }
    if (f & 0x200) {
        func_00158568(0x100);
    }
    return 0;
}

int func_00159BC0(int a, int b, Arg68 r)
{
    return 0;
}

void func_00159C88(void)
{
    u32 f;

    if (D_0058FE50 != 0 && D_0030D3EC != 0) {
        f = D_0058FE54->w505C0;
        if (!(f & 0x8000)) {
            if (f & 0x100) {
                func_00158568(0x100);
            }
        }
    }
}

int func_00159CD8(void) {
    return 0xF71C0;
}

INCLUDE_ASM("build/ee_asm/game/movie/movie_157798", func_00159CE8);

void func_00159E80(int c, int *a, int *b)
{
    if ((u32)(c - 0x68) < 0x11) {
        *b = c - 0x32;
        *a = 0x31;
    } else {
        *b = D_0030D438[c];
        *a = D_0030D438[c + 1];
    }
}

INCLUDE_ASM("build/ee_asm/game/movie/movie_157798", func_00159EC8);

INCLUDE_ASM("build/ee_asm/game/movie/movie_157798", func_0015A120);

void func_0015A258(void) {
}

int func_0015A260(void) {
    if (D_0058FE50 == 0) {
        return 5;
    }
    return (D_0058FE54->w505C0 & 0x1000) ? 5 : 0;
}

int func_0015A298(int a, int b, Arg68 r)
{
    return 0;
}

void func_0015A360(int a, int *p) {
    *p = 0;
}

INCLUDE_ASM("build/ee_asm/game/movie/movie_157798", func_0015A368);

int func_0015A488(int a, int b, Arg68 r)
{
    return 0;
}

int func_0015A550(void) {
    return D_0058FE50 != 0;
}
