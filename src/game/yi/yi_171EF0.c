/* tu_123 0x171ef0-0x174ff8: low; ~yi (config/tu_map.tsv) */
#include "common.h"
#include "ffx/q3.h"
#include "ffx/w2.h"
#include "ffx/r1.h"
#include "ffx/b0.h"
#include "ffx/v1.h"
#include "ffx/s1.h"

void yiInit(void)
{
    func_00175468(&D_00597F00, 0, 0x3000, 0x2400);
    D_00597F00.f68210[2] = D_00597F00.f68210[1] = D_00597F00.f68210[0] = 32.0f;
    yiRender_reset(&D_00597F00);
    Yn_BgInit();
}

INCLUDE_ASM("build/ee_asm/game/yi/yi_171EF0", func_00171F50);

void func_001720A0(void) {
    func_002DA610(0, 0);
    func_00175D88(&D_00597F00);
    func_00174A08(1);
}

void yiReset(void) {
    func_00171F50();
    func_001720A0();
    Sg_MapSetPtr(0);
}

struct Q3Ent *func_001720F8(char *path)
{
    int fd;
    int size;
    void *buf;

    fd = func_002FC4E0(path, 1);
    if (fd < 0) {
        return 0;
    }
    size = func_002FC8E8(fd, 0, 2);
    func_002FC8E8(fd, 0, 0);
    buf = func_0017DBA0(size);
    func_002FCB20(fd, buf, size);
    func_002FC768(fd);
    return buf;
}

int func_00172188(char *path)
{
    int fd;
    int size;

    fd = func_002FC4E0(path, 1);
    if (fd < 0) {
        return 0;
    }
    size = func_002FC8E8(fd, 0, 2);
    func_002FC768(fd);
    return size;
}

int func_001721E8(char *path) {
    int fd;
    u32 size;

    fd = func_002FC4E0(path, 1);
    if (fd < 0) {
        return 0;
    }
    size = func_002FC8E8(fd, 0, 2);
    if (D_00597F00.wBCB1C < size >> 4) {
        BREAK();
    }
    func_002FC8E8(fd, 0, 0);
    func_002FCB20(fd, (char *)D_00597F00.wBCB10, size); /* DEBT(CAST): wBCB10 is the buffer address */
    func_002FC768(fd);
    return D_00597F00.wBCB10;
}

INCLUDE_ASM("build/ee_asm/game/yi/yi_171EF0", yiMapSetup);

int func_001723D8(struct Q3Ent *p, int n)
{
    u8 magic[4];
    u8 *d = (u8 *)p; /* DEBT(CAST): b0.h types the buffer as a Q3Ent */
    int i;
    int ofs;

    magic[0] = 'M';
    magic[1] = 'A';
    magic[2] = 'P';
    magic[3] = '1';
    for (i = 0; i < 4; i++) {
        if (d[i] != magic[i]) {
            return 0;
        }
    }
    ofs = ((SecHdr *)d)->ofs[n];
    if (ofs == 0) {
        return 0;
    }
    return (int)(d + ofs);
}

INCLUDE_ASM("build/ee_asm/game/yi/yi_171EF0", func_00172450);

int func_001724C8(u32 group, int idx) {
    u32 size;

    size = func_00180B10(group, idx);
    if ((int)size < 0) {
        return 0;
    }
    if (D_00597F00.wBCB1C < size >> 4) {
        BREAK();
    }
    func_00180A88(group, idx, (char *)D_00597F00.wBCB10); /* DEBT(CAST): wBCB10 is the buffer address */
    return D_00597F00.wBCB10;
}

void func_00172550(int a, int b)
{
    u8 unused[0x20]; /* DEBT(PADDING): the original frame has room for an unused local */
    SysVt *vt = GetCD();

    vt->f10(a);
    vt->f14(b);
}

struct Q3Ent *func_001725A8(int a, int b)
{
    u8 req[0x20]; /* DEBT(TYPE): request block handed to SysVt.f0, never filled here */
    SysVt *vt = GetCD();
    int size;
    void *buf;

    vt->f10(a);
    size = vt->f14(b);
    if (size == 0) {
        return 0;
    }
    buf = func_0017DBC8(size);
    vt->f0(b, buf, 0, req);
    vt->f8(0);
    return buf;
}

int yiMapReadMaster(int a, int b, int c, int d, int e) { /* DEBT(TYPE): the success path leaves v0 to yiAnimAttachDefault */
    struct Q3Ent *p;
    int h;

    func_002DA610(0, 0);
    yiReset();
    func_00174A08(0);
    if (a != D_00658D28 || b != D_00658D2C) {
        p = func_001725A8(a, b);
        if (p == 0) {
            return -1;
        }
        func_00172550(a, b);
        h = func_001723D8(p, 1);
        if (h != 0) {
            if (func_0017B360(&D_00597F00, h) < 0) {
                return -1;
            }
        }
        h = func_001723D8(p, 2);
        if (h != 0) {
            pppSetFpTex(h);
        }
        func_0017DC70(p);
        D_00658D28 = a;
        D_00658D2C = b;
    }
    if (c != D_00658D20 || d != D_00658D24) {
        p = func_001725A8(c, d);
        if (p == 0) {
            return -1;
        }
        D_00597F00.p9F1EC = p;
        h = func_001723D8(p, 0);
        if (h != 0) {
            D_00597F00.w9F1E0 = h;
            Yn_PreBgSetData(h);
            D_00597F00.w67F20 |= 0x4000;
        }
        h = func_001723D8(p, 1);
        if (h != 0) {
            func_0017B360(&D_00597F00, h);
        }
        if (!(e < 8)) {
            BREAK();
        }
        h = func_001723D8(p, e + 2);
        if (h != 0) {
            Sg_MapSetPtr(h);
        }
        h = func_001723D8(p, 10);
        if (h != 0) {
            D_00597F00.w9F1E4 = h;
            pppSetFpPdt(h);
        }
        h = func_001723D8(p, 12);
        if (h != 0) {
            func_0019CFD8(h);
        }
        h = func_001723D8(p, 11);
        if (h != 0) {
            func_0019CD68(h);
        }
        D_00658D20 = c;
        D_00658D24 = d;
    }
    D_00597F00.w67F20 |= 0x11;
    if (MsBattleGetMapCircleOn()) {
        D_00597F00.w67F24 = 0xFFFFFFFF;
    } else {
        D_00597F00.w67F24 = 0xFFFFFFF7;
    }
    yiAnimAttachDefault(&D_00597F00);
}

INCLUDE_ASM("build/ee_asm/game/yi/yi_171EF0", yiObjReadCallback);

INCLUDE_ASM("build/ee_asm/game/yi/yi_171EF0", yiTexReadCallback);

INCLUDE_ASM("build/ee_asm/game/yi/yi_171EF0", yiObjReadNB);

int func_00172DA0(int id, int n)
{
    int file = n * 2;
    SysVt *vt;
    int size;
    void *buf;
    LoadReq req;

    vt = GetCD();
    func_002DA610(0, 0);
    func_001720A0();
    func_00174A08(0);
    if (id != D_00658D28 || file != D_00658D2C) {
        vt->f10(id);
        size = vt->f14(file);
        if (size == 0) {
            return -1;
        }
        buf = func_0017DBC8(size);
        D_00597F00.w67F20 |= 0xC0;
        req.n = n;
        req.wC = 0;
        req.buf = buf;
        vt->f10(id);
        return vt->f0(file, buf, yiTexReadCallback, &req);
    }
    /* DEBT(TYPE): no return value here, as in the original (v0 is whatever func_00174A08 left) */
}

int TkGetNowEventJumpMapIdNo(int a) {
    return func_00172DA0(0x13, a);
}

int func_00172ED0(int a) {
    return func_00172DA0(0x1A, a);
}

int yiFieldObjReadNB(int a, int b)
{
    int r = yiObjReadNB(0x13, a, b);

    D_00597F00.w67F20 |= 0x2000;
    return r;
}

int func_00172F30(int a, int b)
{
    int r; /* DEBT(FAKE): never set; the original returns whatever is in s0 */

    yiObjReadNB(0x1A, a, b);
    D_00597F00.w67F20 |= 0x1000;
    return r;
}

int func_00172F80(int a, int unused) {
    int v = a * 2;
    int r = yiMapReadMaster(0x13, v, 0x13, v | 1, unused);
    D_00597F00.w67F20 |= 0x2000;
    return r;
}

int func_00172FC8(int a, int unused) {
    int v = a * 2;
    int r = yiMapReadMaster(0x1A, v, 0x1A, v | 1, unused);
    D_00597F00.w67F20 |= 0x1000;
    return r;
}

void func_00173010(int a, int b)
{
    yiObjReadNB(0x13, a, b);
    func_00172DA0(0x13, a);
    D_00597F00.w67F20 |= 0x2000;
}

void func_00173068(int a, int b)
{
    yiObjReadNB(0x1A, a, b);
    func_00172DA0(0x1A, a);
    D_00597F00.w67F20 |= 0x1000;
}

void func_001730C0(void) {
    func_00188450(&D_00597F00);
}

void func_001730D0(void) {
    func_202F848(5, 5, 0xA0, 0x60, 0xE, yiGui_setfogparam_proc);
}

int func_001730F0(void) {
    return D_00597F00.w67F48;
}

int func_00173108(void) {
    if (D_00597F00.w67F20 & 0x1000000) {
        func_00188E40(&D_00597F00, D_00597F00.w67F40);
    }
    return 0;
}

void func_00173150(void)
{
    yiRenderEnable(0x1000000);
    D_00597F00.w67F40 = 0;
    D_00597F00.wC0E10 = 0;
}

void func_00173190(void) {
    yiRenderDisable(0x1000000);
    D_00597F00.w67F40 = 0;
}

void func_001731C0(int a, float x, float y, float z) {
    D_00597F00.fC0DF8 = x;
    D_00597F00.fC0DFC = y;
    D_00597F00.fC0E00 = z;
    D_00597F00.wC0E08 = a;
}

void func_001731E8(u8 a, u8 b, u8 c) {
    D_00597F00.bC0E0C = a;
    D_00597F00.bC0E0D = b;
    D_00597F00.bC0E0E = c;
}

void func_00173208(int a, float x, float y) {
    u32 fl = D_00597F00.wC0DE0;

    D_00597F00.fC0DE4 = x;
    D_00597F00.fC0E04 = y;
    D_00597F00.wC0DE0 = fl | 1;
    if (a != 0) {
        D_00597F00.wC0DE0 = fl | 3;
    }
}

void func_00173240(void) {
    func_00188E98(&D_00597F00);
}

void func_00173250(void) {
    yiGetLightInfo();
    func_00176778(&D_00597F00, 0);
}

void func_00173278(void) {
    func_00176778(&D_00597F00, 1);
}

void yiCallFieldParticle(void) {
    if (D_00597F00.w9F1E4 != 0 && (D_00597F00.w67F20 & 1)) {
        pppFpLoop();
    }
}

void func_001732D0(void) {
    Yn_BgEnd();
    func_00175F58(&D_00597F00);
}

void func_001732F8(float *m)
{
    if (!(D_00597F00.w67F20 & 0x800) && m != 0) {
        func_002DD0C0(&D_005FFE50[0], m);
        D_00597F00.f68398 = m[8];
        D_00597F00.f6839C = m[9];
    }
}

void func_00173370(float *m)
{
    float t[16];

    if (!(D_00597F00.w67F20 & 0x800) && m != 0) {
        func_002DCE38(t, m, &D_005FFF50);
        func_002DD0C0(&D_005FFE90, t);
        func_002DD0C0(&D_005FFED0, t);
        func_002DD0C0(&D_005FFF10, t);
        D_00597F00.f68000[0] = D_00597F00.f68000[2] = D_00597F00.f68000[1] = 0.0f;
        D_00597F00.f68390 = MsCameraGetScrDpt();
    }
}

void func_00173420(float *p) {
    D_00597F00.f68210[0] = p[0];
    D_00597F00.f68210[1] = p[1];
    D_00597F00.f68210[2] = p[2];
}

void func_00173450(float *m, float *n)
{
    float t[16];

    if (m != 0) {
        func_002DD0C0(&D_005FFE50[0], m);
        D_00597F00.f68398 = m[8];
        D_00597F00.f6839C = m[9];
    }
    if (n != 0) {
        func_002DCE38(t, n, &D_005FFE50[4]);
        func_002DD0C0(&D_005FFE50[1], t);
        func_002DD0C0(&D_005FFE50[2], t);
        func_002DD0C0(&D_005FFE50[3], t);
        D_00597F00.f68000[0] = D_00597F00.f68000[2] = D_00597F00.f68000[1] = 0.0f;
        D_00597F00.f68390 = MsCameraGetScrDpt();
    }
}

INCLUDE_ASM("build/ee_asm/game/yi/yi_171EF0", yiGetBackColor);

void func_00173650(void *src) {
    Q3Px *p = src;

    D_00597F00.b683A8 = p[0].v;
    D_00597F00.b683A9 = p[1].v;
    D_00597F00.b683AA = p[2].v;
    D_00597F00.b683AB = p[3].v;
}

void func_00173688(void) {
}

int func_00173690(void) {
    if (D_00597F00.p9F1EC == 0) {
        return -1;
    }
    return D_00597F00.p9F1EC->w04;
}

int func_001736C0(void) {
    if (D_00597F00.p9F1EC == 0) {
        return -1;
    }
    return D_00597F00.p9F1EC->w04;
}

void yiSetDrawMask(int v) {
    D_00597F00.w67F24 = v;
}

int yiGetDrawMask(void) {
    return D_00597F00.w67F24;
}

void func_00173720(void *a) {
    func_002DD0B0(D_00600130, a);
}

void func_00173730(void *a) {
    func_002DD0B0(a, D_00600130);
}

void func_00173740(int *c)
{
    D_00597F00.f68240[0] = c[0] - 0x80;
    D_00597F00.f68240[1] = c[1] - 0x80;
    D_00597F00.f68240[2] = c[2] - 0x80;
    D_00597F00.f68240[3] = c[3] - 0x80;
}

INCLUDE_ASM("build/ee_asm/game/yi/yi_171EF0", func_001737A8);

void func_00173808(void *a) {
    func_002DD0B0(D_00600140, a);
}

void func_00173818(void *a) {
    func_002DD0B0(a, D_00600140);
}

void func_00173828(float *x, float *y, float *z)
{
    *y = D_00597F00.f68210[0] * 0.03125f * 32.0f * D_00597F00.f6837C;
    *x = D_00597F00.f68210[0] * 0.03125f * 32.0f * D_00597F00.f68378;
    *z = D_00597F00.f68374;
}

INCLUDE_ASM("build/ee_asm/game/yi/yi_171EF0", func_00173888);

void func_001739D0(float x, float y, float z)
{
    float s;

    s = D_00597F00.f68210[0] * 0.03125f * 32.0f;
    D_00597F00.f6837C = y / s;
    D_00597F00.f68378 = x / s;
    D_00597F00.f68374 = z;
}

void func_00173A28(void *a) {
    func_002DD0B0(a, D_00600280);
}

void func_00173A38(Q3Px *p) {
    D_00597F00.b68370 = p[0].v;
    D_00597F00.b68371 = p[1].v;
    D_00597F00.b68372 = p[2].v;
    D_00597F00.b68373 = p[3].v;
}

void yiRenderEnable(int v) {
    D_00597F00.w67F20 |= v;
}

void yiRenderDisable(int v) {
    D_00597F00.w67F20 &= ~v;
}

int yiGetRenderStatus(void) {
    return D_00597F00.w67F20;
}

int func_00173AD0(void) {
    return D_00597F00.w687B8;
}

int func_00173AF0(u32 i) {
    if (i >= D_00597F00.w687B8) {
        return -1;
    }
    return D_00597F00.ent[i].h84;
}

INCLUDE_ASM("build/ee_asm/game/yi/yi_171EF0", func_00173B30);

int yiDObjToOMD(int a, int b) {
    return yiPacketConvToOMD(&D_00597F00, a, b);
}

void func_00173B90(int a, int b, int c, int d, int e, int f, int g, int h)
{
    if (!FFXIsDebug()) {
        h = 0;
    }
    func_00184AA8(&D_00597F00, a, b, c, d, e, f, g, h);
}

void func_00173C38(int a, int b, int c, int d, int e, int f, int g)
{
    func_00184AA8(&D_00597F00, a, b, c, d, e, f, g, FFXIsDebug() != 0);
}

int func_00173CD8(int a, int b, int c, int d, int e, int f) {
    return yiPacketConvToOMD_DRAWACC(&D_00597F00, a, b, c, d, e, f);
}

int func_00173D20(int a, int b, int c, int d, int e) {
    return yiPacketConvToOMD_DRAWACC(&D_00597F00, a, b, c, 0x100, d, e);
}

INCLUDE_ASM("build/ee_asm/game/yi/yi_171EF0", yiSetRotTransDObj);

INCLUDE_ASM("build/ee_asm/game/yi/yi_171EF0", yiSetRotTransGroup);

void yiAddRotTransDObj(u32 i, float *a, float *b)
{
    Blk64 t;
    float *v50;
    float *v60;

    if (i < D_00597F00.w687B8) {
        v50 = D_00597F00.ent[i].v50;
        func_002DD020(v50, v50, a);
        v60 = D_00597F00.ent[i].v60;
        func_002DD020(v60, v60, b);
        func_002DD128((struct W3Whole *)&t); /* DEBT(CAST): matrices are passed as the W3Whole view */
        yiRotMatrixSeq(&t, v50, D_00597F00.ent[i].h86);
        func_002DD080(&t, &t, v60);
        *(Blk64 *)D_00597F00.ent[i].m10 = t; /* DEBT(CAST): Q3Ent2.m10 is a Blk64 */
    }
}

void func_00174160(int id, float *a, float *b)
{
    Blk64 unused; /* DEBT(PADDING): the original frame has room for an unused 64-byte local */
    u32 i;

    for (i = 0; i < D_00597F00.w687B8; i++) {
        if (D_00597F00.ent[i].h84 == id) {
            yiAddRotTransDObj(i, a, b);
        }
    }
}

int yiGetMatrixDObj(u32 i, Blk64 *out)
{
    if (i >= D_00597F00.w687B8) {
        return -1;
    }
    *out = *(Blk64 *)D_00597F00.ent[i].m10; /* DEBT(CAST): Q3Ent2.m10 is a Blk64 */
    return 0;
}

int func_001742A0(int id, Blk64 *out)
{
    u32 i;

    for (i = 0; i < D_00597F00.w687B8; i++) {
        if (D_00597F00.ent[i].h84 == id) {
            *out = *(Blk64 *)D_00597F00.ent[i].m10; /* DEBT(CAST): Q3Ent2.m10 is a Blk64 */
            return 0;
        }
    }
    return -1;
}

int func_00174348(u32 i, Blk64 *in)
{
    if (i >= D_00597F00.w687B8) {
        return -1;
    }
    *(Blk64 *)D_00597F00.ent[i].m10 = *in; /* DEBT(CAST): Q3Ent2.m10 is a Blk64 */
    return 0;
}

int func_001743D0(int id, Blk64 *in)
{
    u32 i;

    for (i = 0; i < D_00597F00.w687B8; i++) {
        if (D_00597F00.ent[i].h84 == id) {
            *(Blk64 *)D_00597F00.ent[i].m10 = *in; /* DEBT(CAST): Q3Ent2.m10 is a Blk64 */
            return 0;
        }
    }
    return -1;
}

int func_00174478(void)
{
    u32 i;
    int max;
    int size;
    int bp;

    max = 0;

    for (i = 0; i < D_00597F00.w9E7D8; i++) {
        bp = D_00597F00.res[i].bp;
        size = D_00597F00.res[i].w * D_00597F00.res[i].h;
        switch (D_00597F00.res[i].psm) {
        case 0x14:
            size /= 8;
            break;
        case 0x13:
            size /= 4;
            break;
        case 2:
            size /= 2;
            break;
        case 0:
        case 1:
            break;
        }
        size /= 64;
        bp += size;
        if (max < bp) {
            max = bp;
        }
    }
    return max;
}

void yiGetBattleCenter(float *v)
{
    int i;

    func_002DD0B0(v, D_00600150);
    for (i = 0; i < 4; i++) {
        v[i] *= D_00597F00.f68210[i];
    }
}

/* DEBT(TYPE): one backing view keeps the divisor and output vector within the same work array. */
void func_001745E8(void *input)
{
    float *values;
    s32 remaining;

    func_002DD0B0((D_00600110 + 16), input);
    values = (D_00600110 + 16);
    remaining = 3;
    do
    {
        remaining -= 1;
        values[0] /= values[-16];
        values += 1;
    } while (remaining >= 0);
}

void func_00174648(Blk64 *p)
{
    D_005FFF50 = *p;
}

void func_00174698(Blk64 *p)
{
    *p = D_005FFF50;
}

int func_001746E8(int a, int b, int c) {
    return yiKeyFrame_attachDObj(&D_00597F00, a, b, c);
}

int yiDisposeAnimDObj(int a, int b) {
    if (b < 0) {
        return func_00188020(&D_00597F00, a, b);
    }
    return func_001880A8(&D_00597F00, a, b);
}

u32 func_00174768(u32 i) {
    if (i >= D_00597F00.w687B8) {
        return 0xFFFFFFFF;
    }
    return D_00597F00.ent[i].h80;
}

void func_001747B0(int a, int b, int c) {
    func_00187EA0(&D_00597F00, a, b, c);
}

void func_001747D0(u32 i, float *v)
{
    if (i < D_00597F00.w687B8) {
        D_00597F00.ent[i].f98 = *v;
    }
}

INCLUDE_ASM("build/ee_asm/game/yi/yi_171EF0", func_00174810);

void func_00174870(char *bin, char *pdt)
{
    struct Q3Ent *r;

    if (D_00597F00.w9F1E4 != 0) {
        func_002697B8();
        D_00597F00.w9F1E4 = 0;
        if (D_00597F00.p9F1E8 != 0) {
            func_0017DC70(D_00597F00.p9F1E8);
            D_00597F00.p9F1E8 = 0;
        }
    }
    r = func_001720F8(bin);
    func_00172188(bin);
    if (r != 0) {
        pppSetFpTex((int)r); /* DEBT(CAST): pppSetFpTex takes the buffer as an int handle */
        func_0017DC70(r);
    }
    r = func_001720F8(pdt);
    if (r != 0) {
        D_00597F00.p9F1E8 = r;
        D_00597F00.w9F1E4 = (s32)r; /* DEBT(CAST): flag word holds the buffer */
        pppSetFpPdt((int)r); /* DEBT(CAST) */
    }
    func_00174A08(0);
}

void yiLoadFieldParticleNo(int n)
{
    char bin[0x100];
    char pdt[0x100];

    func_002F0008(bin, D_0056C238, n);
    func_002F0008(pdt, D_0056C268, n);
    func_00174870(bin, pdt);
}

void yiLoadBattleFieldParticleNo(int n)
{
    char bin[0x100];
    char pdt[0x100];

    func_002F0008(bin, D_0056C298, n);
    func_002F0008(pdt, D_0056C2C8, n);
    func_00174870(bin, pdt);
}

void func_00174A08(int c)
{
    switch (c) {
    case 0:
        D_00658D20 = -1;
        D_00658D24 = -1;
        D_00658D28 = -1;
        D_00658D2C = -1;
        break;
    case 1:
        D_00658D28 = -1;
        D_00658D2C = -1;
        break;
    case 2:
        D_00658D20 = -1;
        D_00658D24 = -1;
        break;
    }
}

void func_00174A90(int n)
{
    int r;

    if (D_00597F00.p9F1EC != 0) {
        r = func_001723D8(D_00597F00.p9F1EC, n + 2);
        if (r != 0) {
            Sg_MapSetPtr(r);
            func_0019BBD0(n);
        }
    }
}

void func_00174AF8(int n)
{
    int r;

    if (D_00597F00.p9F1EC != 0) {
        r = func_001723D8(D_00597F00.p9F1EC, n + 2);
        if (r != 0) {
            Sg_MapSetPtr(r);
        }
    }
}

void yiGetLightInfo(void)
{
    float axis[3][4];
    float col[4][4];

    Sg_LightGetDir(0, axis[0]);
    Sg_LightGetDir(1, axis[1]);
    Sg_LightGetDir(2, axis[2]);
    func_002DCEC8((s32)axis[0], (s32)axis[0]); /* DEBT(CAST): funcs.h prototype takes ints */
    func_002DCEC8((s32)axis[1], (s32)axis[1]);
    func_002DCEC8((s32)axis[2], (s32)axis[2]);
    Sg_LightGetColor(0, col[0]);
    Sg_LightGetColor(1, col[1]);
    Sg_LightGetColor(2, col[2]);
    Sg_LightGetColor(3, col[3]);
    func_002DD4E8(&D_005FFFD0[0], axis[0], axis[1], axis[2]);
    func_002DD5A8(&D_005FFFD0[1], col[0], col[1], col[2], col[3]);
}

INCLUDE_ASM("build/ee_asm/game/yi/yi_171EF0", func_00174C58);

INCLUDE_ASM("build/ee_asm/game/yi/yi_171EF0", func_00174E28);
