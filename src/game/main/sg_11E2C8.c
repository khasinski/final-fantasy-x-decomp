/* tu_033 0x11e2c8-0x11eda0: low; ~Sg (config/tu_map.tsv) */
#include "common.h"
#include "ffx/q0.h"
#include "ffx/r0.h"
#include "ffx/s0.h"
#include "ffx/u0.h"
#include "ffx/v0.h"

void Sg_GsUV(int x, int y)
{
    s32 i = D_00580920;

    D_00580928[i].id.d = 3;
    D_00580928[i].q.v.x = x << 4;
    D_00580928[i].q.v.y = y << 4;
    D_00580928[i].q.v.z = 0;
    D_00580920 = i + 1;
}

void Sg_GsUV2(int x, int y)
{
    s32 i = D_00580920;

    D_00580928[i].id.d = 3;
    D_00580928[i].q.v.x = (x << 4) + 0xF;
    D_00580928[i].q.v.y = (y << 4) + 0xF;
    D_00580928[i].q.v.z = 0;
    D_00580920 = i + 1;
}

void Sg_GsTEXFLUSH(void)
{
    s32 i = D_00580920;

    D_00580928[i].id.d = 0x3F;
    D_00580920 = i + 1;
}

void func_0011E380(void)
{
    *(Quad *)&D_00580928[D_00580920] = 0; /* DEBT(CAST) */
}

Cmd16 *Sg_GsGet(void)
{
    return &D_00580928[D_00580920];
}

void func_0011E3C8(void)
{
    D_00580920++;
}

void func_0011E3E0(s32 a, s32 b, s32 c)
{
    u8 *p = D_00580934;

    if (ffx_debugmode) {
        p[0] = 2;
        p[1] = a;
        p[2] = b;
        p[3] = c;
        D_00580934 += 4;
    }
}

void func_0011E420(void)
{
    u8 *p = D_00580934;

    if (ffx_debugmode) {
        *(s16 *)(p + 2) = 1; /* DEBT(CAST): s16 stores through the byte cursor (a union/s16 member does not reload the cursor like the original); DEBT(ORDER): scheduler flips these two stores */
        *(s16 *)p = 1;
        D_00580934 += 4;
    }
}

void func_0011E458(void)
{
    u8 *p = D_00580934;

    if (ffx_debugmode) {
        *(s16 *)(p + 2) = 2; /* DEBT(CAST), DEBT(ORDER): see func_0011E420 */
        *(s16 *)p = 1;
        D_00580934 += 4;
    }
}

void func_0011E490(float *v)
{
    s32 *p = (s32 *)D_00580934;

    if (ffx_debugmode) {
        p[0] = 3;
        ((float *)p)[1] = v[0];
        ((float *)p)[2] = v[1];
        ((float *)p)[3] = v[2];
        D_00580934 += 0x10;
    }
}

void func_0011E4D8(s32 a, s32 b)
{
    u8 *p = D_00580934;

    if (ffx_debugmode) {
        *(s16 *)p = 4; /* DEBT(CAST): see func_0011E420 */
        *(s16 *)(p + 2) = a;
        *(s16 *)(p + 4) = b;
        D_00580934 += 8;
    }
}

void func_0011E510(s32 x, s32 y, s32 width, s32 height)
{
    s32 right;
    s32 bottom;

    func_0011E458();
    right = x + width;
    func_0011E4D8(x, y);
    bottom = y + height;
    func_0011E4D8(right, y);
    func_0011E4D8(right, bottom);
    func_0011E4D8(x, bottom);
    func_0011E4D8(x, y);
}

void func_0011E598(s32 left, s32 top, s32 right, s32 bottom)
{
    func_0011E458();
    func_0011E4D8(left, top);
    func_0011E4D8(right, top);
    func_0011E4D8(right, bottom);
    func_0011E4D8(left, bottom);
    func_0011E4D8(left, top);
}

extern float D_00580938[];
extern float D_00580970[];
extern char D_00569D58[];
extern char D_00569D60[];
extern char D_00569D70[];
extern s32 D_005809A4;
void func_0011D590(s32, int);
void func_001031F8(void);
void func_00122CC8(char *, int);
void Sg_MapInit(void);
void Sg_GsXYZF2L(int arg0, int arg1, int arg2);

INCLUDE_ASM("build/ee_asm/game/main/sg_11E2C8", func_0011E618);

void func_0011E6C0(float *v, float r)
{
    float p[4];

    func_0011E420();
    p[0] = v[0] - r;
    p[1] = v[1];
    p[2] = v[2];
    func_0011E490(p);
    p[0] = v[0] + r;
    func_0011E490(p);
    p[1] = v[1] - r;
    p[0] = v[0];
    func_0011E490(p);
    p[1] = v[1] + r;
    func_0011E490(p);
    p[2] = v[2] - r;
    p[1] = v[1];
    func_0011E490(p);
    p[2] = v[2] + r;
    func_0011E490(p);
}

void func_0011E788(float *v, float r)
{
    int i;
    float p[4];

    func_0011E458();
    for (i = 0; i < 13; i++) {
        p[0] = v[0] + D_00580938[i] * r;
        p[2] = v[2] + D_00580970[i] * r;
        p[1] = v[1];
        func_0011E490(p);
    }
}

void func_0011E830(float *v, float r)
{
    int i;
    float p[4];

    func_0011E458();
    for (i = 0; i < 13; i++) {
        p[0] = v[0] + D_00580938[i] * r;
        p[1] = v[1] + D_00580970[i] * r;
        p[2] = v[2];
        func_0011E490(p);
    }
}

void func_0011E8D8(float *v, float r)
{
    int i;
    float p[4];

    func_0011E458();
    for (i = 0; i < 13; i++) {
        p[1] = v[1] + D_00580938[i] * r;
        p[2] = v[2] + D_00580970[i] * r;
        p[0] = v[0];
        func_0011E490(p);
    }
}

INCLUDE_ASM("build/ee_asm/game/main/sg_11E2C8", func_0011E980);

void func_0011EA68(s32 f)
{
    func_0011E3E0((f & 2) ? 0xFF : 0, (f & 4) ? 0xFF : 0, (f & 1) ? 0xFF : 0);
}

void func_0011EA98(void)
{
    if (ffx_debugmode) {
        D_00580930 = D_00580934 = func_0011D420(0x10000, 6, D_00569D50, 0x209);
        func_0011E618();
    }
}

void Sg_DbDraw(void)
{
    float v[4];
    int out[4];
    float m[16];
    u8 *p;

    if (ffx_debugmode) {
        func_002DD128(m);
        p = (u8 *)func_00106430();
        func_002DCE38(m, p, func_00106420());
        p = D_00580934;
        *p = 0;
        Sg_GsSetPacket((Cmd16 *)Sg_PacketGetPtr());
        Sg_GsStart();
        func_0011DF70(1, 1, 0, 0, 0, 0, 0, 0);
        p = D_00580930;
        while (*p != 0) {
            switch (*p) {
            case 1:
                Sg_GsPRIM(*(u16 *)(p + 2));
                p += 4;
                break;
            case 2:
                func_0011D998(p[1], p[2], p[3], 0x80);
                p += 4;
                break;
            case 4:
                Sg_GsXYZF2L(*(u16 *)(p + 2), *(u16 *)(p + 4), 0);
                p += 8;
                break;
            case 3:
                v[0] = *(float *)(p + 4);
                v[1] = *(float *)(p + 8);
                v[2] = *(float *)(p + 12);
                v[3] = 1.0f;
                p += 0x10;
                func_002DD900(out, m, v, 0);
                Sg_GsXYZF2L(out[0], out[1], out[2]);
                break;
            }
        }
        Sg_GsEnd();
        D_00580934 = D_00580930;
    }
}

void func_0011ECC8(void) {
}

s32 _m2c_Sg_Test_user_malloc(int, int, char *, int) __asm__("user_malloc");

int Sg_Test(int cmd)
{
    switch (cmd) {
    case 2:
        D_005809A4 = _m2c_Sg_Test_user_malloc(0x10000, 6, D_00569D58, 0xB);
        break;
    case 3:
        func_0011D590(D_005809A4, 6);
        func_001031F8();
        break;
    case 0:
        func_00122CC8(D_00569D60, 0);
        func_00122CC8(D_00569D70, 1);
        Sg_MapInit();
        break;
    case 1:
        break;
    }
    return cmd;
}
