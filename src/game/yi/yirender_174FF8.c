/* tu_124 0x174ff8-0x178648: low; ~yiRender (config/tu_map.tsv) */
#include "common.h"
#include "ffx/q3.h"
#include "ffx/w2.h"
#include "ffx/r1.h"
#include "ffx/v1.h"
#include "ffx/v2.h"
#include "ffx/r2.h"
#include "ffx/s2.h"

int func_00174FF8(float *out, int i)
{
    int k;

    if (i < D_00597F00.w68260) {
        for (k = 0; k < 4; k++) {
            out[k] = D_00597F00.v68270[i][k];
        }
        return 1;
    }
    return 0;
}

void func_00175060(int a, int b, int c, int d)
{
    D_00597F00.fBCB4C = a;
    D_00597F00.fBCB50 = b;
    D_00597F00.fBCB54 = c;
    D_00597F00.fBCB58 = d;
}

void func_001750A8(int v)
{
    yiRenderEnable(0x100);
    D_00597F00.w67F44 = v;
}

void func_001750E8(float a, float b, float c, float d) {
    D_00597F00.fBCB4C = a;
    D_00597F00.fBCB50 = b;
    D_00597F00.fBCB54 = c;
    D_00597F00.fBCB58 = d;
}

void func_00175110(float a, float b, float c, float d, float e, float f) {
    D_00597F00.fBCB5C = a;
    D_00597F00.fBCB60 = b;
    D_00597F00.fBCB64 = c;
    D_00597F00.fBCB68 = d;
    D_00597F00.fBCB6C = e;
    D_00597F00.fBCB70 = f;
}

void func_00175140(void) {
    yiRenderDisable(256);
}

void func_00175148(int a, int b) {
    func_0018B7A0(&D_00597F00, a, b);
}

int func_00175160(u32 i, int *a, int *b)
{
    if (i >= D_00597F00.w687B8) {
        return -1;
    }
    D_00597F00.ent[i].rgbaA0[0] = a[0];
    D_00597F00.ent[i].rgbaA0[1] = a[1];
    D_00597F00.ent[i].rgbaA0[2] = a[2];
    D_00597F00.ent[i].rgbaA0[3] = a[3];
    D_00597F00.ent[i].rgbaA4[0] = b[0];
    D_00597F00.ent[i].rgbaA4[1] = b[1];
    D_00597F00.ent[i].rgbaA4[2] = b[2];
    D_00597F00.ent[i].rgbaA4[3] = b[3];
    return 0;
}

int func_001751E8(u32 i, int *a, int *b)
{
    if (i >= D_00597F00.w687B8) {
        return -1;
    }
    a[0] = D_00597F00.ent[i].rgbaA0[0];
    a[1] = D_00597F00.ent[i].rgbaA0[1];
    a[2] = D_00597F00.ent[i].rgbaA0[2];
    a[3] = D_00597F00.ent[i].rgbaA0[3];
    b[0] = D_00597F00.ent[i].rgbaA4[0];
    b[1] = D_00597F00.ent[i].rgbaA4[1];
    b[2] = D_00597F00.ent[i].rgbaA4[2];
    b[3] = D_00597F00.ent[i].rgbaA4[3];
    return 0;
}

typedef struct YiRenderBCB {
    u8 pad_00000[0xBCB20];
    u8 *pBCB20;
    u8 *pBCB24;
    u8 *pBCB28;
    u32 wBCB2C;
    u_long128 *pBCB30;
    u_long128 *pBCB34;
    u_long128 *pBCB38;
    u32 wBCB3C;
    u32 wBCB40;
} YiRenderBCB;

void func_00175270(YiRenderBCB *s)
{
    u_long128 *src;
    u_long128 *dst;
    u32 i;
    int n;
    int j;

    func_002F8660(0);
    SYNC();
    SYNC_P();
    i = 0;
    dst = (u_long128 *)func_0010E260();
    src = s->pBCB30;
    while (i < s->wBCB3C) {
        n = s->wBCB3C - i;
        if (n > 0x200) {
            n = 0x200;
        }
        i += n;
        for (j = 0; j < n; j++) {
            *dst++ = *src++;
        }
        dst = (u_long128 *)func_0010E280((s32)dst);
    }
}

int yiGetVCount(void) {
    return D_00307F30;
}

int yiGetFCount(void) {
    return D_00307F2C << 1;
}

void func_00175358(V1Record1753 *record)
{
    s32 remaining;
    s16 *value;

    record->w00 = 0;
    remaining = 3;
    record->w2C = 0;
    value = &record->values[3];
    record->w34 = 0;
    record->w24 = 0;
    record->w04 = 0;
    record->h1C = 0;
    record->w3C = 0;
    record->w40 = 0;
    record->w08 = 0;
    do
    {
        *value = 0;
        remaining -= 1;
        value -= 1;
    } while (remaining >= 0);
    record->scale = 1.0f;
    /* DEBT(ORDER): chained color writes preserve original store scheduling. */
    record->color[4] = record->color[5] = record->color[6] = record->color[7] =
        record->color[0] = record->color[1] = record->color[2] = record->color[3] = 0x80;
}

void yiRender_setfogparam(Sys597F00 *s)
{
    float f = s->f68210[0] * 0.03125f * 32.0f;
    float far_f = f * s->f6837C;
    float near_f = f * s->f68378;

    s->f68380 = -(255.0f / (far_f - near_f));
    s->f68384 = 255.0f - s->f68374;
    s->f68388 = -near_f;
    *(void **)&s->w6838C = 0;
    if (s->w67F20 & 8) {
        s->f68384 = 255.0f;
    }
}

typedef struct YiBlk10 {
    unsigned long d[2];
} YiBlk10;

typedef struct YiSys5468 {
    u8 pad_00000[0x13B10];
    u32 w13B10;
    u8 pad_13B14[0x540AC];
    u8 pkt67BC0[0x60];
    u8 pkt67C20[0x60];
    u8 pkt67C80[0x60];
    u8 pkt67CE0[0x60];
    u8 pad_67D40[0xC0];
    u8 pkt67E00[0x60];
    u8 pkt67E60[0x60];
    u8 pkt67EC0[0x60];
    u32 w67F20;
    u32 w67F24;
    u8 pad_67F28[0xC];
    u32 w67F34;
    u32 w67F38;
    u32 w67F3C;
    u32 w67F40;
    u32 w67F44;
    s32 w67F48;
    s32 w67F4C;
    V2Blk40 m67F50;
    V2Blk40 m67F90;
    V2Blk40 m67FD0;
    V2Blk40 m68010;
    V2Blk40 m68050;
    V2Blk40 m68090;
    V2Blk40 m680D0;
    V2Blk40 m68110;
    u64 v68150[2];
    u64 v68160[2];
    u64 v68170[2];
    u8 pad_68180[0x34];
    u32 w681B4;
    u32 w681B8;
    u32 w681BC;
    float f681C0[4];
    float f681D0[4];
    float f681E0[4];
    float f681F0[4];
    float f68200[4];
    float f68210[4];
    u8 b68220[4];
    u8 pad_68224[0xC];
    float f68230[4];
    float f68240[4];
    float f68250[4];
    u32 w68260;
    u8 pad_68264[0x10C];
    u8 b68370[4];
    float f68374;
    float f68378;
    float f6837C;
    u8 pad_68380[0x10];
    float f68390;
    u32 pad_68394;
    float f68398;
    float f6839C;
    float f683A0;
    u8 b683A4[4];
    u8 b683A8[3][4];
    u32 w683B4;
    u8 pad_683B8[0x400];
    u32 w687B8;
    u8 pad_687BC[0x6004];
    u32 w6E7C0;
    u8 pad_6E7C4[0x3000C];
    u32 w9E7D0;
    u32 pad_9E7D4;
    u32 w9E7D8;
    u8 pad_9E7DC[0xA04];
    u32 w9F1E0;
    u32 w9F1E4;
    u32 w9F1E8;
    u32 w9F1EC;
    u32 w9F1F0;
    u32 w9F1F4;
    u32 w9F1F8;
    u8 anim9F1FC[0xF0C];
    u32 wA0108;
    u8 pad_A010C[0x1CA04];
    u8 *pBCB10;
    u8 *pBCB14;
    u8 *pBCB18;
    u32 wBCB1C;
    u8 *pBCB20;
    u8 *pBCB24;
    u8 *pBCB28;
    u32 wBCB2C;
    u8 *pBCB30;
    u8 *pBCB34;
    u8 *pBCB38;
    u32 wBCB3C;
    u32 wBCB40;
    float fBCB44;
    float fBCB48;
    float fBCB4C;
    float fBCB50;
    float fBCB54;
    float fBCB58;
    float fBCB5C;
    float fBCB60;
    float fBCB64;
    float fBCB68;
    float fBCB6C;
    float fBCB70;
    u8 pad_BCB74[0x42A0];
    u32 wC0E14;
    u32 wC0E18;
} YiSys5468;

extern u64 D_0056C300[2];
extern const float D_0056C310;
extern const float D_0056C314;
void func_002DD610(void *, float, float, float, float, float, float, float, float, float);
void func_00178520(V2Blk40 *, R2Qw *, int);
void yiAnimInfo_init(void *);
void yiImage_GSSInit(int, int);
void func_001765D0(Sys597F00 *);
void func_00188E88(void *);
void func_00188E98(void *);
void func_0018AA10(u32);
void yiClutAlloc_makepacket(void *, int, int, u32);

void func_00175468(Sys597F00 *s0, int a1, int a2, int a3)
{
    YiSys5468 *s = (YiSys5468 *)s0;
    float v10[4];
    u64 v20[2];
    float m30[4][4];
    float m70[4][4];
    float mB0[4][4];
    s32 i;
    u8 *p;

    func_002EF0D0(v10, 0, sizeof(v10));
    v10[3] = 1.0f;
    v20[0] = D_0056C300[0];
    v20[1] = D_0056C300[1];
    func_002EF0D0(m30, 0, sizeof(m30));
    m30[0][0] = 1.0f;
    m30[1][1] = 1.0f;
    m30[2][2] = 1.0f;
    m30[3][3] = 1.0f;
    func_002EF0D0(m70, 0, sizeof(m70));
    m70[0][3] = 1.0f;
    m70[1][3] = 1.0f;
    m70[2][3] = 1.0f;
    m70[3][3] = 1.0f;
    func_002EF0D0(mB0, 0, sizeof(mB0));
    mB0[0][3] = 1.0f;
    mB0[1][3] = 1.0f;
    mB0[2][3] = 1.0f;
    mB0[3][3] = 1.0f;

    s->w67F24 = 0xFFFFFFFF;
    s->w67F20 = 0;
    s->w683B4 = 0;
    s->w687B8 = 0;
    s->w6E7C0 = 0;
    s->w9E7D0 = 0;
    s->w9E7D8 = 0;

    *(YiBlk10 *)s->v68150 = *(YiBlk10 *)v10;
    ((u32 *)s->v68150)[2] = 0;
    ((u32 *)s->v68150)[3] = 0;
    *(YiBlk10 *)s->v68160 = *(YiBlk10 *)v10;
    *(YiBlk10 *)s->v68170 = *(YiBlk10 *)v10;
    ((float *)s->v68170)[3] = -1.0f;

    func_002DD610(&s->m67F50, 512.0f, 1.0f, 0.47f, 2048.0f, 2048.0f, 1.0f, 16777215.0f, 2.0f, 65536.0f);

    s->m67F90 = *(V2Blk40 *)m30;
    s->m67FD0 = *(V2Blk40 *)m30;
    s->m68010 = *(V2Blk40 *)m30;
    s->m68050 = *(V2Blk40 *)m30;
    s->m680D0 = *(V2Blk40 *)m70;
    s->m68110 = *(V2Blk40 *)mB0;
    s->m68090 = *(V2Blk40 *)m30;

    func_00178520(&s->m67F50, (R2Qw *)s->pkt67BC0, 8);
    func_00178520(&s->m67F90, (R2Qw *)s->pkt67C20, 0xC);
    func_00178520(&s->m67FD0, (R2Qw *)s->pkt67C80, 0xC);
    func_00178520(&s->m68010, (R2Qw *)s->pkt67CE0, 0xC);
    func_00178520(&s->m680D0, (R2Qw *)s->pkt67E00, 0x18);
    func_00178520(&s->m68110, (R2Qw *)s->pkt67E60, 0x1C);
    func_00178520(&s->m68090, (R2Qw *)s->pkt67EC0, 0x20);

    s->f681C0[0] = 2048.0f;
    s->f681C0[1] = 2048.0f;
    s->f681C0[2] = 8388608.0f;
    s->f681C0[3] = 1.0f;
    s->f681D0[0] = 1.0f / 1983.0f;
    s->f681D0[1] = 1.0f / 1983.0f;
    s->f681D0[2] = 1.0f / 8388607.0f;
    s->f681D0[3] = 1.0f;
    s->f68210[0] = s->f68210[1] = s->f68210[2] = s->f68210[3] = 10.0f;
    s->f68230[0] = s->f68230[1] = s->f68230[2] = s->f68230[3] = 1.0f;
    s->f68240[0] = s->f68240[1] = s->f68240[2] = s->f68240[3] = 0.0f;
    s->f681E0[0] = D_0056C310;
    s->f681E0[1] = D_0056C310;
    s->f681E0[2] = D_0056C310;
    s->f681E0[3] = 1.0f;
    s->f681F0[0] = D_0056C314;
    s->f681F0[1] = D_0056C314;
    s->f681F0[2] = D_0056C314;
    s->f681F0[3] = 1.0f;
    s->f68200[0] = 0.0f;
    s->f68200[1] = 0.0f;
    s->f68200[2] = 0.0f;
    s->f68200[3] = 1.0f;
    s->w681B4 = 1;
    s->w681B8 = 1;
    s->w681BC = 1;
    s->b68220[0] = 0x80;
    s->b68220[1] = 0x80;
    s->b68220[2] = 0x80;
    s->b68220[3] = 0x80;
    s->b68370[0] = 0;
    s->b68370[1] = 0;
    s->b68370[2] = 0;
    s->b68370[3] = 0x80;
    s->f68378 = 0.0f;
    s->f6837C = 0.0f;
    s->f68374 = 0.0f;
    for (i = 0; i < 3; i++) {
        s->b683A8[i][0] = s->b683A8[i][1] = s->b683A8[i][2] = s->b683A8[i][3] = 0;
    }
    s->b683A4[0] = 0x80;
    s->b683A4[1] = 0x80;
    s->b683A4[2] = 0x80;
    s->b683A4[3] = 0x20;
    s->w9E7D8 = 0;
    s->w9F1EC = 0;
    s->w9F1E0 = 0;
    s->w9F1E4 = 0;
    s->w9F1E8 = 0;
    s->w9F1F0 = 0;
    s->w9F1F4 = 0;
    s->f68250[0] = s->f68250[1] = s->f68250[2] = 0.0f;
    s->f68250[3] = 1.0f;
    yiAnimInfo_init(s->anim9F1FC);
    {
        register u8 *pA __asm__("$3") = (u8 *)s + 0xA0000;
        register u8 *p6 __asm__("$2") = (u8 *)s + 0x60000;
        __asm__ volatile("" : "+r"(pA), "+r"(p6));
        *(u32 *)(pA + 0x108) = 0;
        *(u32 *)(p6 + 0x7F34) = 0;
    }
    yiImage_GSSInit(0, 0);
    if (a1 != 0) {
        s->pBCB10 = (u8 *)func_0017DBA0(a1 << 4);
        s->pBCB14 = s->pBCB10;
        s->wBCB1C = a1;
        s->pBCB18 = s->pBCB10 + (a1 << 4);
    } else {
        s->pBCB10 = 0;
        s->pBCB14 = 0;
        s->pBCB18 = 0;
        s->wBCB1C = 0;
    }
    s->fBCB4C = s->fBCB50 = s->fBCB54 = 0.0f;
    s->fBCB58 = 1.0f;
    s->fBCB64 = 1.0f;
    s->fBCB60 = 1.0f;
    s->fBCB5C = 1.0f;
    s->fBCB68 = s->fBCB6C = s->fBCB70 = 0.0f;
    s->w67F44 = 0;

    s->pBCB20 = (u8 *)func_0017DBA0(a2 << 4);
    s->pBCB24 = s->pBCB20;
    s->pBCB28 = s->pBCB20 + (a2 << 4);
    s->wBCB2C = a2;

    s->pBCB30 = (u8 *)func_0017DBA0(a3 << 4);
    s->pBCB34 = s->pBCB30;
    s->wBCB3C = 0;
    s->wBCB40 = a3;

    s->wC0E14 = 0;
    s->wC0E18 = 0;
    s->w9F1F8 = Sg_VramGetAddrZ();
    s->f68390 = 1024.0f;
    s->w68260 = 0;
    s->fBCB48 = s->fBCB44 = 0.0f;
    s->w67F40 = 0;
    s->w67F48 = -1;
    s->w67F4C = -1;
    s->w13B10 = 0;
    s->f6839C = s->f68398 = 2048.0f;
    s->f683A0 = 0.0f;
    func_001765D0(s);
    func_00188E88(s);
    func_00188E98(s);
    func_0018AA10(s->w67F38);
    yiClutAlloc_makepacket(s, 0, 0x48, s->w67F38);
}

typedef struct YiRender5C08 {
    u8 pad_00000[0x67BC0];
    R2Qw pkt67BC0[6];
    R2Qw pkt67C20[6];
    R2Qw pkt67C80[6];
    R2Qw pkt67CE0[6];
    u8 pad_67D40[0x60];
    R2Qw pkt67DA0[6];
    R2Qw pkt67E00[6];
    R2Qw pkt67E60[6];
    R2Qw pkt67EC0[6];
    u8 pad_67F20[0x30];
    V2Blk40 m67F50;
    V2Blk40 m67F90;
    V2Blk40 m67FD0;
    V2Blk40 m68010;
    u8 pad_68050[0x40];
    V2Blk40 m68090;
    V2Blk40 m680D0;
    V2Blk40 m68110;
    u8 pad_68150[0xC0];
    float f68210;
    float f68214;
    float f68218;
} YiRender5C08;

void func_001785A8(V2Blk40 *src, R2Qw *p, int addr);

void func_00175C08(YiRender5C08 *s)
{
    float m[16];

    func_001785A8(&s->m67F50, s->pkt67BC0, 8);
    func_001785A8(&s->m67F90, s->pkt67C20, 0xC);
    func_001785A8(&s->m67FD0, s->pkt67C80, 0xC);
    func_001785A8(&s->m68010, s->pkt67CE0, 0xC);
    func_001785A8(&s->m680D0, s->pkt67E00, 0x18);
    func_001785A8(&s->m68110, s->pkt67E60, 0x1C);
    func_001785A8(&s->m68090, s->pkt67EC0, 0x20);
    func_002DD128(m);
    m[0] = s->f68210;
    m[5] = s->f68214;
    m[10] = s->f68218;
    func_001785A8((V2Blk40 *)m, s->pkt67DA0, 0x10); /* DEBT(CAST) */
}

void func_00175D50(Sys597F00 *s) {
    func_0017DC70(s->wBCB10);
    func_0017DC70(s->wBCB20);
}

void func_00175D88(Sys597F00 *s) {
    s->w9E7D8 = 0;
    s->wC0E14 = 0;
    s->wC0E18 = 0;
    s->w67F4C = -1;
}

INCLUDE_ASM("build/ee_asm/game/yi/yirender_174FF8", yiRender_resetobj);

void yiRender_reset(Sys597F00 *p) {
    yiRender_resetobj(p);
    func_00175D88(p);
}

void func_00175F58(void *p)
{
    Sys597F00 *s = p;

    yiRender_reset(s);
    func_0017DC70((struct Q3Ent *)s->wBCB10); /* DEBT(CAST): wBCB10 holds a buffer */
    func_0017DC70((struct Q3Ent *)s->wBCB20); /* DEBT(CAST) */
    s->wBCB10 = 0;
    s->wBCB14 = 0;
    s->wBCB20 = 0;
    s->wBCB24 = 0;
}

typedef struct YiSub5FA8 {
    u8 pad_00[0xE];
    u16 h0E;
    u8 pad_10[0x10];
    float v20[16][4];
} YiSub5FA8;

typedef struct YiObj5FA8 {
    u8 pad_00[0x14];
    s32 w14;
    u8 pad_18[8];
    YiSub5FA8 *subs;
    u32 count;
} YiObj5FA8;

typedef struct YiSys5FA8 {
    u8 pad_00000[0x681E0];
    float min681E0[4];
    float max681F0[4];
    float size68200[4];
    u8 pad_68210[0x1A4];
    u32 n683B4;
    YiObj5FA8 *objs683B8[1];
} YiSys5FA8;

void func_00175FA8(Sys597F00 *s0)
{
    YiSys5FA8 *s = (YiSys5FA8 *)s0;
    u32 i;
    u32 j;
    int k;
    int m;

    for (i = 0; i < s->n683B4; i++) {
        if (s->objs683B8[i]->w14 != 1) {
            for (j = 0; j < s->objs683B8[i]->count; j++) {
                YiSub5FA8 *sub = &s->objs683B8[i]->subs[j];
                for (k = 0; k < sub->h0E; k++) {
                    for (m = 0; m < 3; m++) {
                        if (s->min681E0[m] > sub->v20[k][m]) {
                            s->min681E0[m] = sub->v20[k][m];
                        }
                        if (s->max681F0[m] < sub->v20[k][m]) {
                            s->max681F0[m] = sub->v20[k][m];
                        }
                    }
                }
            }
        }
    }
    s->size68200[0] = s->max681F0[0] - s->min681E0[0];
    s->size68200[1] = s->max681F0[1] - s->min681E0[1];
    s->size68200[2] = s->max681F0[2] - s->min681E0[2];
    s->size68200[3] = s->max681F0[3] = s->min681E0[3] = 1.0f;
}

extern float D_0065B530;
extern float D_0065B534;
extern float D_0065B538;
extern float D_0065B53C;
extern float D_0065B540;
extern float D_0065B544;
double func_002E9290(double);

void func_00176138(float a, float b)
{
    D_0065B530 = ((b * 3.0f + 512.0f) / 1.6f) / a;
    D_0065B534 = ((b * 3.0f + 416.0f) / 1.6f) / a;
    func_002ED038(1.0f / (D_0065B530 * D_0065B530 + 1.0f));
    D_0065B538 = func_002E9290(1.0f / (D_0065B530 * D_0065B530 + 1.0f));
    func_002ED038(1.0f / (D_0065B534 * D_0065B534 + 1.0f));
    D_0065B53C = func_002E9290(1.0f / (D_0065B534 * D_0065B534 + 1.0f));
    func_002ED038(D_0065B530 * D_0065B530 + 1.0f);
    D_0065B540 = -func_002EBF18(1.0, func_002E9290(D_0065B530 * D_0065B530 + 1.0f));
    func_002ED038(D_0065B534 * D_0065B534 + 1.0f);
    D_0065B544 = -func_002EBF18(1.0, func_002E9290(D_0065B534 * D_0065B534 + 1.0f));
}

void func_00176360(void) {
}

typedef struct YiQw {
    u32 w[4];
} YiQw;

void func_00176368(Sys597F00 *s0, u32 addr, void *src0, u32 count)
{
    YiRenderBCB *s = (YiRenderBCB *)s0;
    YiQw *src;
    YiQw *tag = (YiQw *)s->pBCB34;
    YiQw *p;
    u32 i;

    if ((u32)s->pBCB24 & 0x3F) {
        s->pBCB24 = (u8 *)((YiQw *)s->pBCB24 + ((0x40 - ((u32)s->pBCB24 & 0x3F)) >> 4));
    }
    p = (YiQw *)s->pBCB24;
    s->pBCB24 = (u8 *)p + ((count << 4) + 0x10);
    if ((u8 *)s->pBCB28 < s->pBCB24) {
        BREAK();
    }
    if (s->wBCB3C >= s->wBCB40) {
        BREAK();
    }
    tag->w[1] = (u32)p;
    tag->w[2] = 0;
    tag->w[0] = ((count + 1) & 0xFFFF) | 0x30000000;
    tag->w[3] = 0;
    s->pBCB34 = (u_long128 *)(tag + 1);
    s->wBCB3C++;
    p->w[0] = 0x11000000;
    p->w[1] = 0x05000000;
    p->w[2] = 0x01000404;
    p->w[3] = addr | (count << 16) | 0x6C000000;
    p++;
    src = (YiQw *)src0;
    for (i = 0; i < count; i++, p++, src++) {
        u32 *sub = (u32 *)src0 + (i * 4 + 1);
        p->w[0] = src->w[0];
        p->w[1] = sub[0];
        p->w[2] = sub[1];
        p->w[3] = src->w[3];
    }
}

void func_001764A0(Sys597F00 *s0, void *src0, u32 count)
{
    YiRenderBCB *s = (YiRenderBCB *)s0;
    YiQw *src;
    YiQw *tag = (YiQw *)s->pBCB34;
    YiQw *p;
    u32 i;

    if ((u32)s->pBCB24 & 0x3F) {
        s->pBCB24 = (u8 *)((YiQw *)s->pBCB24 + ((0x40 - ((u32)s->pBCB24 & 0x3F)) >> 4));
    }
    p = (YiQw *)s->pBCB24;
    s->pBCB24 = (u8 *)p + ((count << 4) + 0x10);
    if ((u8 *)s->pBCB28 < s->pBCB24) {
        BREAK();
    }
    if (s->wBCB3C >= s->wBCB40) {
        BREAK();
    }
    tag->w[1] = (u32)p;
    tag->w[2] = 0;
    tag->w[0] = ((count + 1) & 0xFFFF) | 0x30000000;
    tag->w[3] = 0;
    s->pBCB34 = (u_long128 *)(tag + 1);
    s->wBCB3C++;
    p->w[0] = 0x11000000;
    p->w[1] = 0x05000000;
    p->w[2] = 0x01000404;
    p->w[3] = count | 0x51000000;
    p++;
    src = (YiQw *)src0;
    for (i = 0; i < count; i++, p++, src++) {
        u32 *sub = (u32 *)src0 + (i * 4 + 1);
        p->w[0] = src->w[0];
        p->w[1] = sub[0];
        p->w[2] = sub[1];
        p->w[3] = src->w[3];
    }
}

void func_001765D0(Sys597F00 *s)
{
    R2Qw *p = (R2Qw *)((u8 *)s + 0x27630);

    p->w[3] = 0x51000005;
    p->w[0] = 0;
    p->w[1] = 0;
    p->w[2] = 0;
    p++;
    p->w[0] = 4;
    p->w[1] = 0x10030000;
    p->w[2] = 0xE;
    p->w[3] = 0;
    p++;
    {
        R2Qw *q = p++;
        q->w[0] = 0;
        q->w[1] = 0x23C00;
        q->w[2] = 0x50;
        q->w[3] = 0;
    }
    {
        R2Qw *q = p++;
        q->w[0] = 0;
        q->w[1] = 0;
        q->w[2] = 0x51;
        q->w[3] = 0;
    }
    {
        R2Qw *q = p++;
        int addr = 0x52;
        q->w[0] = 0x80;
        q->w[1] = 0x200;
        q->w[2] = addr;
        q->w[3] = 0;
    }
    {
        R2Qw *q = p++;
        q->w[0] = 0;
        q->w[1] = 0;
        q->w[2] = 0x53;
        q->w[3] = 0;
    }
    p->w[3] = 0x51004001;
    p->w[0] = 0;
    p->w[1] = 0;
    p->w[2] = 0;
    p++;
    p->w[0] = 0xC000;
    p->w[1] = 0x8000000;
    p->w[2] = 0;
    p->w[3] = 0;
}

void func_001766D0(Sys597F00 *s) {
    R2Qw pkt[16];

    {
        u32 *p = (u32 *)&pkt[0];
        p[1] = 0x10000000;
        p[2] = 0xE;
        p[3] = 0;
    }
    {
        u32 *p = (u32 *)&pkt[1];
        u64 v = (*(u32 *)((u8 *)s + 0x9F1F8) >> 11) | 0x1000000;
        p[0] = v;
        p[1] = v >> 32;
        p[2] = 0x4F;
        p[3] = 0;
    }
    {
        u32 *p = (u32 *)&pkt[2];
        p[0] = 0x70000;
        p[1] = 0;
        p[2] = 0x48;
        p[3] = 0;
    }
    pkt[0].w[0] = 0x8002;
    func_001764A0(s, pkt, 3);
}

INCLUDE_ASM("build/ee_asm/game/yi/yirender_174FF8", func_00176778);

typedef struct YiSysVU1 {
    u8 pad_00000[0x676C0];
    YiQw pkt676C0[10];
    u8 pad_67760[0x7F0];
    float f67F50;
    u8 pad_67F54[0x10];
    float f67F64;
    u8 pad_67F68[0x258];
    YiBlk10 v681C0;
    YiBlk10 v681D0;
    u8 pad_681E0[0x50];
    YiBlk10 v68230;
    YiBlk10 v68240;
    u8 pad_68250[0x130];
    YiBlk10 v68380;
    u8 pad_68390[8];
    float f68398;
    float f6839C;
    float f683A0;
} YiSysVU1;

void yiRender_setupparamVU1(Sys597F00 *s0)
{
    YiSysVU1 *s = (YiSysVU1 *)s0;
    YiQw *p;
    int dx;
    int dy;
    int max_v;
    int min_v;

    yiRender_setfogparam(s0);
    dx = (int)(s->f68398 - 2048.0f);
    dy = (int)(s->f6839C - 2048.0f);
    p = s->pkt676C0;
    p->w[0] = 0x20000009;
    p->w[1] = 0;
    p->w[2] = 0;
    p->w[3] = 0;
    p++;
    p->w[0] = 0x11000000;
    p->w[2] = 0x01000101;
    p->w[3] = 0x6C080000;
    p->w[1] = 0;
    p++;
    max_v = 0;
    min_v = 0;
    if (dx > max_v) {
        max_v = dx;
    }
    if (dx < min_v) {
        min_v = dx;
    }
    if (dy > max_v) {
        max_v = dy;
    }
    if (dy < min_v) {
        min_v = dy;
    }
    ((float *)p)[0] = (float)(0x800 - max_v) - 128.0f;
    ((float *)p)[1] = (float)(-0x800 - min_v) + 128.0f;
    ((float *)p)[2] = 1.0f;
    s->f683A0 = 0.0f;
    if (s->f683A0 < (float)(dx < 0 ? -dx : dx)) {
        s->f683A0 = (float)(dx < 0 ? -dx : dx);
    }
    if (s->f683A0 < (float)(dy < 0 ? -dy : dy)) {
        s->f683A0 = (float)(dy < 0 ? -dy : dy);
    }
    if (s->f67F50 < s->f67F64) {
        ((float *)p)[3] = s->f67F64;
    } else {
        ((float *)p)[3] = s->f67F50;
    }
    p++;
    *(YiBlk10 *)p = s->v681C0;
    p++;
    *(YiBlk10 *)p = s->v681D0;
    p++;
    *(YiBlk10 *)p = s->v68380;
    p++;
    p->w[0] = 0xA000;
    p->w[1] = 0;
    p->w[2] = 0;
    p->w[3] = 0;
    p++;
    p->w[0] = 0xFFFF;
    p->w[1] = 0;
    p->w[2] = 0;
    p->w[3] = 0;
    p++;
    *(YiBlk10 *)p = s->v68230;
    p++;
    *(YiBlk10 *)p = s->v68240;
}

static inline void yi_set_gs_reg(R2Qw *p, s64 val, int reg)
{
    p->w[0] = (u32)(val & 0xFFFFFFFFULL);
    p->w[1] = (u32)(val >> 32);
    p->w[2] = reg;
    p->w[3] = 0;
}

void yiRender_setupparamGS(Sys597F00 *s0)
{
    YiSys5468 *s = (YiSys5468 *)s0;
    R2Qw *p;
    float col[4];
    int i;

    p = (R2Qw *)((u8 *)s + 0x677C0);
    p->w[0] = 0x2000000C;
    p->w[1] = 0;
    p->w[2] = 0;
    p->w[3] = 0;
    p++;
    p->w[0] = 0x11000000;
    p->w[3] = 0x5100000B;
    p->w[1] = 0;
    p->w[2] = 0;
    p++;
    p->w[0] = 0x800A;
    p->w[1] = 0x10000000;
    p->w[2] = 0xE;
    p->w[3] = 0;
    p++;
    yi_set_gs_reg(p++, 0, 0x3F);
    yi_set_gs_reg(p++, 0x7000D, 0x48);
    yi_set_gs_reg(p++, 0x60, 0x15);
    yi_set_gs_reg(p++, 0x44, 0x43);
    yi_set_gs_reg(p++, 0, 0x4B);
    yi_set_gs_reg(p++, 0x2000000000000000ULL, 0xA);
    if (s->w67F20 & 4) {
        col[0] = (float)s->b68370[0];
        col[1] = (float)s->b68370[1];
        col[2] = (float)s->b68370[2];
        col[3] = (float)s->b68370[3];
        for (i = 0; i < 4; i++) {
            col[i] = col[i] * s->f68230[i] + s->f68240[i];
            if (col[i] < 0.0f) {
                col[i] = 0.0f;
            }
            if (col[i] > 255.0f) {
                col[i] = 255.0f;
            }
        }
        yi_set_gs_reg(p++, (u64)col[0] | ((u64)col[1] << 8) | ((u64)col[2] << 16), 0x3D);
    } else {
        yi_set_gs_reg(p++, (u64)s->b68370[0] | ((u64)s->b68370[1] << 8) | ((u64)s->b68370[2] << 16), 0x3D);
    }
    yi_set_gs_reg(p++, 0x0000008000000080ULL, 0x3B);
    yi_set_gs_reg(p++, 0, 0x49);
    if (s->w67F20 & 0x2000000) {
        p->w[0] = 0;
        p->w[1] = 0;
        p->w[2] = 0;
        p->w[3] = 0;
    } else {
        yi_set_gs_reg(p++, ((u32)s->w9F1F8 >> 11) | 0x1000000, 0x4F);
    }

    p = (R2Qw *)((u8 *)s + 0x678C0);
    p->w[0] = 0x2000000C;
    p->w[1] = 0;
    p->w[2] = 0;
    p->w[3] = 0;
    p++;
    p->w[0] = 0x11000000;
    p->w[3] = 0x5100000B;
    p->w[1] = 0;
    p->w[2] = 0;
    p++;
    p->w[0] = 0x800A;
    p->w[1] = 0x10000000;
    p->w[2] = 0xE;
    p->w[3] = 0;
    p++;
    yi_set_gs_reg(p++, 0, 0x3F);
    yi_set_gs_reg(p++, 0x5000D, 0x48);
    yi_set_gs_reg(p++, 0x60, 0x15);
    yi_set_gs_reg(p++, 0x44, 0x43);
    yi_set_gs_reg(p++, 0, 0x4B);
    yi_set_gs_reg(p++, 0x2000000000000000ULL, 0xA);
    if (s->w67F20 & 4) {
        col[0] = (float)s->b68370[0];
        col[1] = (float)s->b68370[1];
        col[2] = (float)s->b68370[2];
        col[3] = (float)s->b68370[3];
        for (i = 0; i < 4; i++) {
            col[i] = col[i] * s->f68230[i] + s->f68240[i];
            if (col[i] < 0.0f) {
                col[i] = 0.0f;
            }
            if (col[i] > 255.0f) {
                col[i] = 255.0f;
            }
        }
        yi_set_gs_reg(p++, (u64)col[0] | ((u64)col[1] << 8) | ((u64)col[2] << 16), 0x3D);
    } else {
        yi_set_gs_reg(p++, (u64)s->b68370[0] | ((u64)s->b68370[1] << 8) | ((u64)s->b68370[2] << 16), 0x3D);
    }
    yi_set_gs_reg(p++, 0x0000008000000080ULL, 0x3B);
    yi_set_gs_reg(p++, 0, 0x49);
    if (s->w67F20 & 0x2000000) {
        p->w[0] = 0;
        p->w[1] = 0;
        p->w[2] = 0;
        p->w[3] = 0;
    } else {
        yi_set_gs_reg(p++, ((u32)s->w9F1F8 >> 11) | 0x1000000, 0x4F);
    }
}

void func_00178520(V2Blk40 *src, R2Qw *p, int addr) {
    p->w[1] = 0;
    p->w[2] = 0;
    p->w[0] = 0x20000005;
    p->w[3] = 0;
    p++;
    p->w[0] = 0x11000000;
    p->w[2] = 0x1000101;
    p->w[3] = addr | 0x6C040000;
    p->w[1] = 0;
    p++;
    *(V2Blk40 *)p = *src; /* DEBT(CAST) */
}

void func_001785A8(V2Blk40 *src, R2Qw *p, int addr) {
    p->w[0] = 0;
    p->w[1] = 0;
    p->w[3] = addr | 0x6C040000;
    p->w[2] = 0;
    p++;
    *(V2Blk40 *)p = *src; /* DEBT(CAST) */
}

void func_00178608(S2Ctx *ctx, V2Cmd *c) {
    switch (c->kind) {
    case 0x10:
        func_0018B5A8(ctx, c->addr, c->h1A, c->h16);
        break;
    case 0x100:
        func_0018B558(ctx, c->addr, c->h1A);
        break;
    }
}
