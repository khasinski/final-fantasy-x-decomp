/* tu_101 0x157798-0x15a560: low; ~movie (config/tu_map.tsv) */
#define func_00158410 _hdr_func_00158410
#define func_00158FE8 _hdr_func_00158FE8
#define func_00158D60 _hdr_func_00158D60
#define func_0011A5A0 _hdr_func_0011A5A0
#define func_00158200 _hdr_func_00158200
#define func_00159CE8 _hdr_func_00159CE8
#include "common.h"
#include "ffx/q2.h"
#include "ffx/w2.h"
#include "ffx/r1.h"
#include "ffx/s1.h"
#include "ffx/b0.h"
#include "ffx/q3.h"
#include "ffx/u1.h"
#include "ffx/v1.h"
#include "ffx/g0.h"
#undef func_00159CE8
#undef func_00158200
#undef func_0011A5A0
#undef func_00158D60
#undef func_00158FE8
#undef func_00158410

void func_0011A5A0(int, int);

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

void *func_001577D0(void)
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

typedef struct {
    u8 pad0[0x50528];
    s32 w50528;
    s32 w5052C;
    s32 w50530;
    s32 w50534;
    u8 pad50538[0x50544 - 0x50538];
    s32 w50544;
    u8 pad50548[0x505C0 - 0x50548];
    u32 w505C0;
    u8 pad505C4[0x506C8 - 0x505C4];
    s32 w506C8;
    u8 pad506CC[0x506DC - 0x506CC];
    s32 w506DC;
    u8 pad506E0[0x50708 - 0x506E0];
    s32 w50708;
    u8 pad5070C[0x50714 - 0x5070C];
    s32 w50714;
    u8 pad50718[0x5075C - 0x50718];
    s8 b5075C;
    s8 b5075D;
    s8 pad5075E;
    s8 b5075F;
    s8 b50760;
    s8 b50761;
    s8 pad50762[2];
    s8 b50764;
    s8 pad50765[7];
    s8 b5076C;
    s8 b5076D;
    s8 b5076E;
    s8 pad5076F[3];
    s8 b50772;
    s8 b50773;
} MovWork58FE54; /* DEBT(TYPE): extended view of S58FE54 */

typedef struct {
    u8 pad0[0xF7120];
    s32 wF7120;
    s32 wF7124;
    s32 wF7128;
    s32 wF712C;
    s32 wF7130;
    s32 wF7134;
    s32 wF7138;
    s32 wF713C;
    s32 wF7140;
    s32 wF7144;
    u8 padF7148[0xF715C - 0xF7148];
    s8 bF715C;
    s8 bF715D;
    u8 padF715E[2];
    void *pF7160;
} MovWork58FE60;

void func_00158D60(void);
void func_001632B0(void);
void func_20700F8(void);
void func_00160978(void);
void func_20728C0(void);
void func_0015C5A8(void *);
int Sg_GetCurExecFrames(void);
void func_002545E0(void);

void func_00157968(void)
{
    s32 dc;

    D_0030D406 = 0;
    func_001632B0();
    if (D_0030D414 == 3) {
        func_20700F8();
    }
    func_00160978();
    {
        s32 state = D_0030D410;
        if (state == 0) {
            return;
        }
        switch (state) {
        case 1:
            if (D_0058FE50 == 0) {
                return;
            }
            Sg_MFIFOSync();
            func_002DA610(0, 0);
            if (FFXIsPC() == 1) {
                func_20728C0();
            }
            if (D_0030D3EC == 0) {
                return;
            }
            func_0015C5A8(func_001577D0());
            Sg_GetDBuffDC(&dc);
            ((MovWork58FE54 *)D_0058FE54)->w50534 = dc & 1;
            ((MovWork58FE54 *)D_0058FE54)->w506C8 = D_0030D3F0;
            ((MovWork58FE54 *)D_0058FE54)->w50714 = D_0030D3F0;
            if (Sg_GetCurExecFrames() != 0) {
                ((MovWork58FE54 *)D_0058FE54)->w505C0 &= 0xFFFFBFBFU;
            } else {
                ((MovWork58FE54 *)D_0058FE54)->w505C0 |= 0x4040;
            }
            D_0030D418->f0();
            func_001577F0();
            {
                register MovWork58FE54 *p __asm__("$4") = (MovWork58FE54 *)D_0058FE54; /* DEBT(REG): matches $a0 for D_0058FE54 reload */
                register u8 *q __asm__("$2") = (u8 *)p + 0x50000; /* DEBT(REG): matches $v0 for offset base */
                __asm__("" : "+r"(q)); /* DEBT(ORDER): keeps offset base in $v0 */
                if (((s8 *)q)[0x76D] != 0) {
                    func_002545E0();
                    D_0030D405 = 1;
                }
            }
            func_0011A5A0(D_0030D400, 0);
            if (D_0030D400 == 0 && ((MovWork58FE54 *)D_0058FE54)->w506DC != 0) {
                func_00119028(1);
                func_00119038(1);
            }
            D_0030D40C = ((MovWork58FE54 *)D_0058FE54)->w50528 + 1;
            if (((MovWork58FE54 *)D_0058FE54)->w50528 == ((MovWork58FE54 *)D_0058FE54)->w5052C) {
                if (((MovWork58FE54 *)D_0058FE54)->w505C0 & 4) {
                    if (((MovWork58FE54 *)D_0058FE54)->w505C0 & 0x40) {
                        return;
                    }
                    if (((MovWork58FE54 *)D_0058FE54)->w505C0 & 0x1000) {
                        return;
                    }
                    ((MovWork58FE54 *)D_0058FE54)->w50530++;
                    if (((MovWork58FE54 *)D_0058FE54)->w50530 >= 0x259) {
                        ((MovWork58FE54 *)D_0058FE54)->w505C0 |= 0x9000;
                        D_0030D40C = ((MovWork58FE54 *)D_0058FE54)->w50708 + 1;
                        func_00158D60();
                    }
                }
            } else {
                ((MovWork58FE54 *)D_0058FE54)->w5052C = ((MovWork58FE54 *)D_0058FE54)->w50528;
                ((MovWork58FE54 *)D_0058FE54)->w50530 = 0;
            }
            break;
        case 2:
            if (D_0030D408 != 0) {
                D_0030D418->f0();
            }
            break;
        }
    }
}

extern s32 D_0030D41C;
extern s32 D_0030D420;
extern s32 D_0030D424;
extern s32 D_0030D428;
extern s32 D_0030D42C;
extern s32 D_0058FE64;

typedef union {
    u_long128 q;
    struct {
        u64 d0;
        u64 d1;
    } ad;
    struct {
        u32 w0;
        u32 w1;
        u32 w2;
        u32 w3;
    } w;
} MovGifQword;

#define SET_AD(q_elem, d_val, r_val) \
    { \
        (q_elem).ad.d0 = (d_val); \
        (q_elem).ad.d1 = (r_val); \
    }

#define SET_W4(q_elem, a, b, c, d) \
    { \
        (q_elem).w.w0 = (a); \
        (q_elem).w.w1 = (b); \
        (q_elem).w.w2 = (c); \
        (q_elem).w.w3 = (d); \
    }

#define SCE_GS_SET_TEX0_MOV(tbp0, tbw, psm, tw, th, tcc, tfx, cbp, cpsm, csm, csa, cld) \
    ((u64)(tbp0) | ((u64)(tbw) << 14) | ((u64)(psm) << 20) | ((u64)(tw) << 26) | \
     ((u64)(th) << 30) | ((u64)(tcc) << 34) | ((u64)(tfx) << 35) | ((u64)(cbp) << 37) | \
     ((u64)(cpsm) << 51) | ((u64)(csm) << 55) | ((u64)(csa) << 56) | ((u64)(cld) << 61))

#define SET_UV(q_elem, u_val, v_val) \
    { \
        (q_elem).w.w0 = (u_val) << 4; \
        (q_elem).w.w1 = (v_val) << 4; \
        (q_elem).w.w2 = 0x3F800000; \
        (q_elem).w.w3 = 0; \
    }

INCLUDE_ASM("build/ee_asm/game/movie/movie_157798", func_00157BE8);

void func_00158200(MovGifQword *p, u32 tbp0, int x, int y, int w, int h, int psm)
{
    int tw = 1;

    if (w > 0x10) tw = 5;
    if (w > 0x20) tw = 6;
    if (w > 0x40) tw = 7;
    if (w > 0x80) tw = 8;
    if (w > 0x100) tw = 9;
    if (w > 0x200) tw = 10;

    p[0].q = 0;
    p[0].w.w0 = 0x1000000B;
    SET_AD(p[1], 0x1000000000000003UL, 0xE);
    SET_AD(p[2], 0, 0x3F);
    SET_AD(p[3], SCE_GS_SET_TEX0_MOV(tbp0, w / 64, psm, tw, tw, 0, 0, 0, 0, 0, 0, 0), 6);
    SET_AD(p[4], 0x60, 0x14);
    SET_AD(p[5], 0x608B400000008001UL, 0x413413);

    x += 0x800;
    y += 0x800;
    x -= w / 2;
    y -= h / 2;

    SET_UV(p[6], 1, 1);
    SET_W4(p[7], 0x80, 0x80, 0x80, 0x80);
    SET_W4(p[8], x << 4, y << 4, 0xFFFFFF, 0);
    SET_UV(p[9], w, h);
    SET_W4(p[10], 0x80, 0x80, 0x80, 0x80);
    SET_W4(p[11], (x + w) << 4, (y + h) << 4, 0xFFFFFF, 0);

    p[12].q = 0;
    p[12].w.w0 = 0x70000000;
}

extern s32 _m2c_func_00158410_D_0030D408 __asm__("D_0030D408");
extern s32 _m2c_func_00158410_D_0030D410 __asm__("D_0030D410");
extern s32 _m2c_func_00158410_D_0058FE60 __asm__("D_0058FE60");
extern s32 _m2c_func_00158410_D_0058FE64 __asm__("D_0058FE64");
s32 _m2c_func_00158410_func_00158200(s32, s32, s32, s32, s32, s32, s32) __asm__("func_00158200");
s32 _m2c_func_00158410_func_001656D8() __asm__("func_001656D8");
/* DEBT(CAST) */
void func_00158410(void) {
    s32 temp_16;
    s32 temp_16_2;
    s32 temp_2;
    u32 *temp_17;

    temp_16 = _m2c_func_00158410_D_0030D410;
    if ((temp_16 == 2) && (_m2c_func_00158410_D_0030D408 != 0)) {
        if (((*(s32 *)((u8 *)(_m2c_func_00158410_D_0058FE60) + (0xF7144))) != 0) && ((*(s32 *)((u8 *)(_m2c_func_00158410_D_0058FE60) + (0xF7148))) != 0)) {
            func_002DA610(0, 0);
            temp_17 = func_002DB6D8(2);
            temp_16_2 = ((*(s32 *)((u8 *)(_m2c_func_00158410_D_0058FE60) + (0xF7130))) == 0) ? 0 : temp_16;
            temp_2 = Sg_PacketGetPtr();
            _m2c_func_00158410_func_00158200(temp_2, _m2c_func_00158410_D_0058FE64, (*(s32 *)((u8 *)(_m2c_func_00158410_D_0058FE60) + (0xF714C))), (*(s32 *)((u8 *)(_m2c_func_00158410_D_0058FE60) + (0xF7150))), (*(s32 *)((u8 *)(_m2c_func_00158410_D_0058FE60) + (0xF7154))), (*(s32 *)((u8 *)(_m2c_func_00158410_D_0058FE60) + (0xF7158))), temp_16_2);
            func_002F8660(0);
            func_002DBA28(temp_17, temp_2);
            func_002DA610(0, 0);
        }
    }
    _m2c_func_00158410_func_001656D8();
}

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

void func_001600B8(void);

void func_00158768(void)
{
    D_0058FE60->bF715D = 1;
    do {
        D_0030D418->f0();
    } while (D_0058FE60->bF715D != 0);
    func_001600B8();
    if (D_0058FE60->bF715C != 0) {
        func_0011D590(D_0058FE5C, 10);
        func_0011D590(D_0058FE58, 10);
    }
    D_0030D418->f4();
    D_0030D418 = 0;
    D_0058FE58 = 0;
    D_0058FE5C = 0;
    D_0058FE60 = 0;
    D_0030D408 = 0;
    D_0030D410 = 0;
    D_0030D3E8 = 0;
}

INCLUDE_ASM("build/ee_asm/game/movie/movie_157798", func_00158868);

int func_001588F8(void)
{
    if (!func_002D9868()) {
        return D_0030D40C;
    }
    return D_0030D40C * 30 / 25;
}

int func_00158948(void) {
    return D_0030D40C;
}

int func_00158958(void)
{
    if (!func_002D9868()) {
        return D_0030D40C;
    }
    return D_0030D40C * 30 / 25;
}

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

extern s8 D_0030D407;
extern char D_0056B5D0[];
int func_0015C9B0(void *p);
int func_0015C968(void *p);
void func_206C630(int a);
int func_002E1D20(void);
int func_002D64E0(int a);

int func_00158AA8(void)
{
    s32 dc;

    switch (D_0030D410) {
    case 1:
        if (D_0058FE50 == 0) {
            func_001577A8(D_0056B5A8, D_0056B5C0, 0x448);
        }
        if (D_0030D3EC == 0) {
            func_001577A8(D_0056B5D0, D_0056B5C0, 0x449);
        }
        D_0058FE54->b50772 = 0;
        switch (D_0030D407) {
        case 0:
            ((int (*)(void *, int))audioStop)(D_0058FE54, 0);
            D_0030D407 = 1;
            /* fallthrough */
        case 1:
            if (((MovWork58FE54 *)D_0058FE54)->w50544 < 0) {
                goto set40;
            }
            D_0030D407 = 2;
            /* fallthrough */
        case 2:
            if (((MovWork58FE54 *)D_0058FE54)->b5075D != 0) {
                D_0030D407 = 10;
                goto step10;
            }
            if (((MovWork58FE54 *)D_0058FE54)->b5075C != 0) {
                D_0030D407 = 30;
                goto step30;
            }
            D_0030D407 = 3;
            /* fallthrough */
        case 3:
            if (func_0015C9B0(D_0058FE54) != 0) {
                break;
            }
            ((int (*)(int))func_206C630)(((MovWork58FE54 *)D_0058FE54)->w50544);
            D_0030D407 = 40;
            goto step40;
        case 10:
        step10:
            if (func_0015C968(D_0058FE54) != 0) {
                break;
            }
            ((int (*)(int))func_206C630)(((MovWork58FE54 *)D_0058FE54)->w50544);
            D_0030D407 = 40;
            goto step40;
        case 30:
        step30:
            if (func_002E1D20() == 0) {
                break;
            }
            D_0030D407 = 35;
            /* fallthrough */
        case 35:
            if (func_0015C9B0(D_0058FE54) != 0) {
                break;
            }
        set40:
            D_0030D407 = 40;
            /* fallthrough */
        case 40:
        step40:
            ((MovWork58FE54 *)D_0058FE54)->w50544 = -1;
            if (((MovWork58FE54 *)D_0058FE54)->w50714 == 0) {
                D_0030D407 = 100;
                goto step100;
            }
            func_002D5F58(1);
            D_0030D407 = 50;
            /* fallthrough */
        case 50:
            if (func_002D64E0(0) != 0) {
                break;
            }
            D_0030D407 = 100;
            ((MovWork58FE54 *)D_0058FE54)->w50714 = 0;
            /* fallthrough */
        case 100:
        step100:
            ((void (*)(s32 *))Sg_GetDBuffDC)(&dc);
            if (!(dc & 1)) {
                break;
            }
            if (D_0030D400 != 0) {
                func_0011A5A0(0, 0);
                D_0030D400 = 0;
            }
            func_00158660();
            func_001585D0();
            if (D_0030D3FC & 0x1000000) {
                yiRenderEnable(0x1000000);
            }
            return 1;
        }
        return 0;
    case 2:
        if (D_0058FE58 == 0) {
            return 1;
        }
        if (D_0058FE5C == 0) {
            return 1;
        }
        func_00158768();
        break;
    }
    return 1;
}

void mpegstrendsub(void *, int);

void func_00158D60(void)
{
    switch (D_0030D410) {
    case 1:
        if (D_0058FE50 == 0 || D_0030D3EC == 0) {
            return;
        }
        D_0058FE54->b50772 = 0;
        mpegstrendsub(D_0058FE54, 0);
        if (D_0030D400 != 0) {
            func_0011A5A0(0, 0);
            D_0030D400 = 0;
            func_00158660();
            func_001585D0();
        } else {
            func_00158660();
            func_001585D0();
        }
        if (D_0030D3FC & 0x1000000) {
            yiRenderEnable(0x1000000);
        }
        break;
    case 2:
        if (D_0058FE58 == 0 || D_0058FE5C == 0) {
            return;
        }
        func_00158768();
        break;
    }
    D_0030D3EC = 0;
    D_0030D410 = 0;
}

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

u8 *_m2c_func_00158FE8_MsGetSaveMenu() __asm__("MsGetSaveMenu");
void func_00158FE8(void) {
    u64 tmp = *_m2c_func_00158FE8_MsGetSaveMenu();
    __asm__("" : "+r"(tmp));
    if ((tmp >> 7) != 0) {
        D_0030D3F0 = 1;
    } else {
        D_0030D3F0 = 0;
    }
    if (D_0058FE50 != 0) {
        D_0058FE54->w50714 = D_0030D3F0;
        D_0058FE54->w506C8 = D_0030D3F0;
    }
}

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

extern s8 _mov_D_0030D3E8 __asm__("D_0030D3E8");
extern char D_0056B7B0[];
extern u8 D_0056B778[];
extern s8 D_0030D404;
extern s8 D_0030D405;
extern s8 D_0030D406;
extern s8 D_0030D407;
extern s32 D_0030D40C;
void func_0015FCA8(void);
void func_001596C8(int id, int flags);
int func_0015C5B8(char *, char *, void *, int);
void func_0015CAE0(void);

typedef struct {
    u8 pad0[0x4];
    int (*f04)(int);
    u8 pad8[0x8];
    void (*f10)(int);
    int (*f14)(int);
    int w18;
    u8 pad1C[0x3C];
    char *(*f58)(int);
} MovCdObj;

INCLUDE_ASM("build/ee_asm/game/movie/movie_157798", func_00159148);

extern char D_0056B7C0[];
extern char D_0056B7E0[];
extern char D_0056B7F0[];
void func_00159148(char *, char *, int);
void func_0015FC20(void);

int func_00159368(int unused, int *arg1)
{
    char buf0[0x40];
    char buf1[0x40];
    register MovCdObj *cd __asm__("$18");
    s32 s0;
    u8 *str;
    register int flags __asm__("$19");
    register int *a1 __asm__("$17") = arg1;
    register int *p __asm__("$19") = a1;
    int i;
    int j;

    __asm__("" : "+r"(p));
    cd = (MovCdObj *)GetCD();
    __asm__("" : "+r"(cd));
    if (D_0058FE50 != 0) {
        func_001577A8(D_0056B778, D_0056B5C0, 0x5A0);
    }
    if (cd->w18 != 0) {
        func_001577A8(D_0056B7C0, D_0056B5C0, 0x5A1);
    }
    if (_mov_D_0030D3E8 != 0) {
        func_001577A8(D_0056B7B0, D_0056B5C0, 0x5A2);
    }
    D_0030D405 = 0;
    D_0030D407 = 0;
    D_0030D404 = 1;
    D_0030D40C = 0;
    D_0030D406 = 0;
    s0 = sa_task_buff_size_get(1);
    {
        void *t = (void *)sa_task_init2(1, (void *)0x1B00000, 0);
        s0 += 0x1B00000;
        *(void *volatile *)&D_0030D418 = t;
    }
    *(volatile s32 *)&D_0058FE50 = s0;
    *(void *volatile *)&D_0058FE54 = (void *)s0;
    str = (u8 *)a1[1];
    flags = *p;
    if (str == 0) {
        func_001577A8(D_0056B7E0, D_0056B5C0, 0x5BC);
    }
    {
        register void (*f10)(int) __asm__("$2");
        if (str[0] == 0) {
            func_001577A8(D_0056B7F0, D_0056B5C0, 0x5BD);
            f10 = cd->f10;
        } else {
            f10 = cd->f10;
        }
        __asm__("" : "+r"(f10));
        D_0058FE68 = 0;
        D_0058FE6C = 0;
        f10(0x15);
    }
    ((MovWork58FE54 *)D_0058FE54)->b50764 = 0x15;
    i = 0;
    while (1) {
        buf0[i] = str[i];
        buf1[i] = str[i];
        if (str[i] == 0) {
            break;
        }
        i++;
    }
    j = i;
    if (j != 0) {
        j--;
        if (j > 0 && (u8)buf1[j] != '/' && (u8)buf1[j] != '.') {
            register u8 *bp __asm__("$3") = (u8 *)buf1;
            __asm__("" : "+r"(bp));
            do {
                j--;
            } while (j > 0 && bp[j] != '/' && bp[j] != '.');
        }
        if ((u8)buf1[j] != '.') {
            buf1[i] = '.';
            buf0[i] = '.';
            j = i;
        }
    }
    buf1[j + 1] = 'd';
    buf1[j + 2] = 'a';
    buf1[j + 3] = 't';
    buf1[j + 4] = '\0';
    buf0[j + 1] = 's';
    buf0[j + 2] = 'z';
    buf0[j + 3] = '\0';
    func_00159148(buf0, buf1, flags);
    return 0;
}

void func_00159640(int v) {
    D_0030D400 = v;
}

void func_00159650(void) {
    if (D_0058FE50 != 0) {
        D_0058FE54->w505C0 &= 0xFFFEFFFF;
    }
}

INCLUDE_ASM("build/ee_asm/game/movie/movie_157798", rcuiSceneInit);

void func_00159E80(int, int *, int *);
int func_0015C718(int, int, int, int, void *, int);

void func_001596C8(int a0, int a1)
{
    char buf0[0x40];
    char buf1[0x40];
    int v80;
    int v84;
    s32 s0;
    MovCdObj *cd;

    if (D_0058FE50 != 0) {
        func_001577A8(D_0056B778, D_0056B5C0, 0x5FF);
    }
    if (_mov_D_0030D3E8 != 0) {
        func_001577A8(D_0056B7B0, D_0056B5C0, 0x601);
    }
    D_0030D405 = 0;
    D_0030D407 = 0;
    D_0030D404 = 1;
    D_0030D40C = 0;
    D_0030D406 = 0;
    s0 = sa_task_buff_size_get(1);
    D_0030D418 = (void *)sa_task_init2(1, (void *)0x1B00000, 0);
    s0 += 0x1B00000;
    D_0058FE50 = s0;
    D_0058FE54 = (void *)s0;
    cd = (MovCdObj *)GetCD();
    func_00159E80(a0, &v80, &v84);
    cd->f10(v80);
    D_0058FE68 = 0;
    D_0058FE6C = 0;
    if (cd->w18 == 0 && *(s8 *)&D_005661F4 == 0) {
        u8 *str = (u8 *)cd->f58(v84);
        int i = 0;
        while (1) {
            buf0[i] = str[i];
            buf1[i] = str[i];
            if (str[i] == 0) {
                break;
            }
            i++;
        }
        i--;
        if ((u8)buf1[i] != '.') {
            register u8 *bp __asm__("$4") = (u8 *)buf1;
            __asm__("" : "+r"(bp));
            do {
                i--;
            } while (bp[i] != '.');
        }
        buf1[i + 1] = 'd';
        buf1[i + 2] = 'a';
        buf1[i + 3] = 't';
        buf1[i + 4] = '\0';
        func_0015C5B8(buf1, buf0, D_0058FE54, D_0030D400);
    } else {
        int id1 = v84 + 1;
        int p0 = cd->f04(id1);
        register int (*f14)(int) __asm__("$3") = cd->f14;
        int p1 = f14(id1);
        int p2 = cd->f04(v84);
        int p3 = cd->f14(v84);
        func_0015C718(p0, p1, p2, p3, D_0058FE54, D_0030D400);
    }
    if (a0 == 0x2E) {
        ((MovWork58FE54 *)D_0058FE54)->b50773 = 1;
    } else {
        ((MovWork58FE54 *)D_0058FE54)->b50773 = 0;
    }
    ((MovWork58FE54 *)D_0058FE54)->b50764 = v80;
    ((MovWork58FE54 *)D_0058FE54)->w505C0 |= (a1 & 0x12000);
    ((MovWork58FE54 *)D_0058FE54)->b5075F = D_0030D400;
    ((MovWork58FE54 *)D_0058FE54)->b50760 = -1;
    ((MovWork58FE54 *)D_0058FE54)->b50761 = 0;
    if (a0 == 0x20) {
        ((MovWork58FE54 *)D_0058FE54)->b5076C = 0;
    } else {
        ((MovWork58FE54 *)D_0058FE54)->b5076C = 1;
    }
    ((MovWork58FE54 *)D_0058FE54)->b5076E = (a1 >> 11) & 1;
    {
        typedef struct {
            void (*f0)(void);
            void *f4;
            void (*f8)(void (*)(void), int, int);
        } MovTaskObj;
        register void (*fn)(void (*)(void), int, int) __asm__("$2") = ((MovTaskObj *)D_0030D418)->f8;
        fn(func_0015CAE0, 1, 0);
    }
    func_00158508(0x100);
    D_0030D410 = 1;
    D_0030D3EC = 1;
}

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

void func_00159CE8(int flags, void *a1, int a2, void *a3, void *a4)
{
    void **task;
    MovWork58FE60 *p;

    if (_mov_D_0030D3E8 != 0) {
        func_001577A8(D_0056B7B0, D_0056B5C0, 0x6CC);
    }
    _mov_D_0030D3E8 = 1;
    D_0030D418 = (void *)sa_task_init2(1, a4, 0);
    D_0058FE5C = (s32)a1;
    D_0058FE58 = (s32)a3;
    D_0058FE60 = a3;
    ((MovWork58FE60 *)a3)->bF715D = 0;
    ((MovWork58FE60 *)a3)->wF7124 = a2;
    ((MovWork58FE60 *)a3)->pF7160 = a1;
    ((MovWork58FE60 *)D_0058FE60)->bF715C = 0;
    task = ((void **(*)(void *, int, int))((void **)D_0030D418)[2])(func_0015FCA8, 0, 0);
    p = (MovWork58FE60 *)D_0058FE60;
    *task = p;
    if (flags & 0x400) {
        D_0058FE64 = p->wF7128 = 0;
        D_0058FE64 = p->wF712C = 0xD00;
    } else {
        D_0058FE64 = p->wF7128 = 0x2F00;
        D_0058FE64 = p->wF712C = 0x2F00;
    }
    ((MovWork58FE60 *)D_0058FE60)->wF7120 = -1;
    ((MovWork58FE60 *)D_0058FE60)->wF7140 = flags & 0x480;
    ((MovWork58FE60 *)D_0058FE60)->wF7144 = 0;
    ((MovWork58FE60 *)D_0058FE60)->wF713C = 0;
    ((MovWork58FE60 *)D_0058FE60)->wF7134 = 0;
    if (flags & 0x800) {
        ((MovWork58FE60 *)D_0058FE60)->wF7130 = 1;
        if (flags & 0x1000) {
            ((MovWork58FE60 *)D_0058FE60)->wF7134 = 1;
        }
    } else {
        ((MovWork58FE60 *)D_0058FE60)->wF7130 = 0;
    }
    D_0030D408 = 1;
    D_0030D410 = 2;
}

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

int func_00159EC8(Actor *a0, int unused, ScriptCtx *a2)
{
    int v0;
    int v4;
    int flags;
    int id;
    MovCdObj *cd;
    int size;
    void **task;
    MovWork58FE60 *p;
    register int one __asm__("$20");

    flags = AtelPopStackInteger(a0, a2);
    id = AtelPopStackInteger(a0, a2);
    if (_mov_D_0030D3E8 != 0) {
        func_001577A8(D_0056B7B0, D_0056B5C0, 0x773);
    }
    one = 1;
    _mov_D_0030D3E8 = one;
    cd = (MovCdObj *)GetCD();
    func_00159E80(id, &v0, &v4);
    cd->f10(v0);
    size = cd->f14(v4);
    D_0030D418 = (void *)sa_task_init(1);
    D_0058FE58 = (s32)user_malloc(0xF71A3, 10, D_0056B5C0, 0x781);
    D_0058FE5C = (s32)user_malloc(size + 0x3F, 10, D_0056B5C0, 0x782);
    {
        s32 buf = D_0058FE5C;
        register MovWork58FE60 *p3 __asm__("$3") = (MovWork58FE60 *)((D_0058FE58 + 0x3F) & 0xFFFFFFC0U);
        D_0058FE60 = p3;
        p3->bF715D = 0;
        p3->wF7124 = size;
        p3->pF7160 = (void *)((buf + 0x3F) & 0xFFFFFFC0U);
    }
    {
        register MovWork58FE60 *p3b __asm__("$3") = (MovWork58FE60 *)D_0058FE60;
        register int keep5 __asm__("$5");
        __asm__("" : "=r"(keep5) : "r"(p3b));
        p3b->bF715C = one;
        {
            typedef struct { u8 pad[0x7138]; s32 w7138; } MovOff7138;
            register MovOff7138 *p2 __asm__("$2") = (MovOff7138 *)((u8 *)D_0058FE60 + 0xF0000);
            register int vv __asm__("$7") = v0;
            __asm__("" : "+r"(p2) : "r"(keep5));
            p2->w7138 = vv;
        }
    }
    {
        register void **t3 __asm__("$3") = (void **)D_0030D418;
        register void **(*fn)(void *, int, int) __asm__("$2") = (void **(*)(void *, int, int))t3[2];
        task = fn(func_0015FC20, 0, 0);
    }
    p = (MovWork58FE60 *)D_0058FE60;
    *task = p;
    if (flags & 0x400) {
        D_0058FE64 = p->wF7128 = 0;
        D_0058FE64 = p->wF712C = 0xD00;
    } else {
        D_0058FE64 = p->wF7128 = 0x2F00;
        D_0058FE64 = p->wF712C = 0x2F00;
    }
    {
        register MovWork58FE60 *p3 __asm__("$3") = (MovWork58FE60 *)D_0058FE60;
        int tmp4;
        *(volatile s32 *)&p3->wF7144 = 0;
        tmp4 = v4;
        *(volatile s32 *)&p3->wF7140 = flags & 0x480;
        *(volatile s32 *)&p3->wF7120 = tmp4;
        *(volatile s32 *)&p3->wF713C = 0;
        p3->wF7134 = 0;
        if (flags & 0x800) {
            p3->wF7130 = 1;
            if (flags & 0x1000) {
                p3->wF7134 = 1;
            }
        } else {
            p3->wF7130 = 0;
        }
    }
    D_0030D408 = 1;
    D_0030D410 = 2;
    return 0;
}

int func_0015A120(void)
{
    int f;

    switch (D_0030D410) {
    case 1:
        if (D_0058FE50 == 0) {
            return 1;
        }
        if (D_0058FE54->w505C0 & 0x8000) {
            if (D_0030D400 != 0) {
                func_0011A5A0(0, 0);
                D_0030D400 = 0;
                func_00158660();
                func_001585D0();
                if (D_0030D3FC & 0x1000000) {
                    yiRenderEnable(0x1000000);
                }
                return 0;
            }
            func_00158660();
            func_001585D0();
            if (D_0030D3FC & 0x1000000) {
                yiRenderEnable(0x1000000);
            }
            return 1;
        }
        return 0;
    case 2:
        if (D_0058FE58 == 0) {
            return 1;
        }
        f = D_0058FE60->wF7140;
        if (f & 0x80) {
            return 0;
        }
        if (f & 0x2000) {
            func_00158768();
            return 1;
        }
        return 0;
    }
    return 1;
}

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

int func_0015A368(int a, int *p)
{
    int f;

    switch (D_0030D410) {
    case 1:
        if (D_0058FE50 == 0) {
            return 5;
        }
        if (*p == 0) {
            if (D_0058FE54->w505C0 & 0x8000) {
                *p = 1;
                if (D_0030D400 != 0) {
                    func_0011A5A0(0, 0);
                    D_0030D400 = 0;
                }
                func_00158660();
                func_001585D0();
            }
            return 0;
        }
        if (D_0030D3FC & 0x1000000) {
            yiRenderEnable(0x1000000);
        }
        return 5;
    case 2:
        if (D_0058FE58 == 0) {
            return 5;
        }
        f = D_0058FE60->wF7140;
        if (f & 0x80) {
            return 0;
        }
        if (f & 0x2000) {
            func_00158768();
            return 5;
        }
        return 0;
    }
    return 5;
}

int func_0015A488(int a, int b, Arg68 r)
{
    return 0;
}

int func_0015A550(void) {
    return D_0058FE50 != 0;
}
