/* tu_121 0x171530-0x171ce8: low; sa_task (config/tu_map.tsv) */
#include "common.h"
#include "ffx/r1.h"
#include "ffx/g1.h"
#include "ffx/q3.h"
#include "ffx/w2.h"
#include "ffx/b0.h"
#define D_0030DE34 v1_D_0030DE34 /* DEBT(TYPE): v1.h guesses another type for this datum */
#include "ffx/v1.h"
#undef D_0030DE34

INCLUDE_ASM("build/ee_asm/game/sa/sa_task", func_00171530);

INCLUDE_ASM("build/ee_asm/game/sa/sa_task", func_00171568);

INCLUDE_ASM("build/ee_asm/game/sa/sa_task", func_001715C0);

INCLUDE_ASM("build/ee_asm/game/sa/sa_task", func_001715D8);

/* DEBT(CAST) */
void func_00171648(s32 on) {
    SlotTaskContext **var_2;
    s32 var_3;

    var_3 = 7;
    var_2 = D_00597E38;
    __asm__("" : "+r"(var_2));
    var_2 += 7;
    do {
        *var_2 = 0;
        var_3 -= 1;
        var_2 = (SlotTaskContext **)((u8 *)var_2 - (4));
    } while (var_3 >= 0);
}

int func_00171680(int n, int a, int b, int c)
{
    int ret;
    s32 save98 = D_0057CB98;
    G1SlotTaskCtx *ctx = (G1SlotTaskCtx *)D_00597E38[n];
    s32 saveA0 = D_0057CBA0;

    D_0057CBA4 = ctx->w0C;
    D_0057CB98 = ctx->w10;
    D_0057CBA8 = ctx->w14;
    D_0057CBA0 = ctx->w18;
    ret = func_00171004(a, b, c);
    D_0057CB98 = save98;
    D_0057CBA0 = saveA0;
    return ret;
}

int func_00171718(int a, int b, int c)
{
    return func_00171680(0, a, b, c);
}

int func_00171748(int a, int b, int c)
{
    return func_00171680(1, a, b, c);
}

int func_00171778(int a, int b, int c)
{
    return func_00171680(2, a, b, c);
}

int func_001717A8(int a, int b, int c)
{
    return func_00171680(3, a, b, c);
}

int func_001717D8(int a, int b, int c)
{
    return func_00171680(4, a, b, c);
}

int func_00171808(int a, int b, int c)
{
    return func_00171680(5, a, b, c);
}

int func_00171838(int a, int b, int c)
{
    return func_00171680(6, a, b, c);
}

int func_00171868(int a, int b, int c)
{
    return func_00171680(7, a, b, c);
}

void func_00171898(int n)
{
    s32 save98 = D_0057CB98;
    G1SlotTaskCtx *ctx = (G1SlotTaskCtx *)D_00597E38[n]; /* DEBT(CAST): SlotTaskContext in r1.h only declares +0x24 */
    s32 saveA0 = D_0057CBA0;

    D_0057CB9C = (s32)ctx; /* DEBT(TYPE): D_0057CB9C declared s32 to match alias set of ctx->w0C..w1C */
    D_0057CBA4 = ctx->w0C;
    D_0057CB98 = ctx->w10;
    D_0057CBA8 = ctx->w14;
    D_0057CBA0 = ctx->w18;
    ctx->w1C++;
    func_001710D4();
    D_0057CB98 = save98;
    D_0057CBA0 = saveA0;
}

void func_00171938(void)
{
    func_00171898(0);
}

void func_00171940(void)
{
    func_00171898(1);
}

void func_00171948(void)
{
    func_00171898(2);
}

void func_00171950(void)
{
    func_00171898(3);
}

void func_00171958(void)
{
    func_00171898(4);
}

void func_00171960(void)
{
    func_00171898(5);
}

void func_00171968(void)
{
    func_00171898(6);
}

void func_00171970(void)
{
    func_00171898(7);
}

/* DEBT(CAST): the allocator's interface accepts an integer address. */
void func_00171978(int n)
{
    SlotTaskContext **slot = &D_00597E38[n];
    SlotTaskContext *task = *slot;

    if (task->owned != 0) {
        func_0011D590((int)task, 0xA);
    }
    *slot = 0;
}

void func_001719C0(void)
{
    func_00171978(0);
}

void func_001719C8(void)
{
    func_00171978(1);
}

void func_001719D0(void)
{
    func_00171978(2);
}

void func_001719D8(void)
{
    func_00171978(3);
}

void func_001719E0(void)
{
    func_00171978(4);
}

void func_001719E8(void)
{
    func_00171978(5);
}

void func_001719F0(void)
{
    func_00171978(6);
}

void func_001719F8(void)
{
    func_00171978(7);
}

int func_00171A00(G1SlotTaskCtx *ctx, int a, int b, int c)
{
    int ret;
    s32 save98 = D_0057CB98;
    s32 saveA0 = D_0057CBA0;

    D_0057CBA4 = ctx->w0C;
    D_0057CB98 = ctx->w10;
    D_0057CBA8 = ctx->w14;
    D_0057CBA0 = ctx->w18;
    ret = func_00171004(a, b, c);
    D_0057CB98 = save98;
    D_0057CBA0 = saveA0;
    return ret;
}

int func_00171A88(int a, int b, int c)
{
    return func_00171004(a, b, c);
}

int sa_task_buff_size_get(int n)
{
    return (n * 0x1310 + (n << 5) + 0x607) & 0xFFFFFFC0;
}

INCLUDE_ASM("build/ee_asm/game/sa/sa_task", sa_task_init2);

SaTaskGroup *sa_task_init(int n)
{
    return sa_task_init2(n, user_malloc(sa_task_buff_size_get(n), 10, D_0056C190, 0x11A), 1);
}
