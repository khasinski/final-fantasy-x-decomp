/* tu_288 0x268680-0x26a9a8: medium; ~ppp (config/tu_map.tsv) */
#include "common.h"
#include "vu0.h"
#include "ffx/w8.h"
#include "ffx/q6.h"
#include "ffx/r6.h"
#include "ffx/t6.h"
#include "ffx/u4.h"
#include "ffx/v6.h"
#include "ffx/w9.h"

int func_00268680(float x, float y)
{
    int r;

    if (x < -0.5f) {
        r = 1;
    } else if (x >= 0.5f) {
        r = 2;
    } else {
        r = 0;
    }
    if (y < -0.5f) {
        r |= 4;
    } else if (y >= 0.5f) {
        r |= 8;
    }
    return r;
}

s32 func_002686F0(void *arg0, void *arg1, float arg2, float arg3, float arg4) {
    float sp[4];
    float z;
    float inv;
    float x, y;
    float x0, x1, y0, y1;
    s32 res;

    if (arg2 < 0.0f) {
        return 0;
    }
    func_002DCE08(sp, arg0, arg1);
    if (arg2 < sp[2]) {
        return 0xF;
    }
    z = sp[2] + arg3;
    sp[2] = z;
    if (z <= 0.0f) {
        return 0xF;
    }
    inv = 1.0f / z;
    x = sp[0] * inv;
    y = sp[1] * inv;
    x0 = x - arg3 * inv;
    x1 = x + arg3 * inv;
    y1 = y + arg4 * inv;
    y0 = y - arg4 * inv;
    res = func_00268680(x0, y1);
    res &= func_00268680(x1, y1);
    res &= func_00268680(x0, y0);
    res &= func_00268680(x1, y0);
    return res;
}

void pppSetFpTex(int h)
{
    U4ResHdr *o = (U4ResHdr *)h; /* DEBT(CAST): b0.h passes the header as int */
    int i;

    op_fp_effect_init();
    op_oef2_set2((char *)o);
    for (i = 0; i < o->n2; i++) {
        op_oef2_texture_load(op_oef2_a_get(h, 2, i), 1);
    }
    for (i = 0; i < o->n3; i++) {
        op_oef2_clut_load(op_oef2_a_get(h, 3, i), 1);
    }
}

void pppSetFpTex2(char *src, int n)
{
    if (D_003708C8 == 0 && n > 0) {
        D_003708C8 = (int)user_malloc(n, 0xB, D_00573FF0, 0); /* DEBT(CAST): buffer address kept as int */
        func_002EEF1C((void *)D_003708C8, src, n);
        op_oef2_set2((char *)D_003708C8);
        func_002D02E8(D_003708C8, 0, 10000, 0x40000000);
    }
}

extern s32 D_003708B8;
extern s32 D_003708D8;
extern s32 D_003708DC;
extern s32 D_003708E8;
extern s32 D_003708EC;
extern s32 D_006EA400;
extern u8 D_0036F210[];
extern u8 D_006A3BD0[];
extern char D_00574000[];
extern char D_00574008[];
void _ppp_pppCreateHeap(void *, s32, s32) __asm__("pppCreateHeap");
void pppInitEnv(void *, void *, void *, s32);
void func_00268BC8(int);
void func_002DD128(void *);

/* DEBT(CAST): raw byte/vector offsets on Ent50Tbl, Slot80, Slot50 */
void pppSetFpPdt(Ent50Tbl *pdt)
{
    s32 i;

    D_003708B8 = 1;
    D_006E7BFC = pdt;
    _pppInitData(pdt, D_0036F210);
    pppInitEnv(&D_006E7BD0, D_006E7BFC, D_006A3BD0, 0x40000);

    if (D_003708EC == 0) {
        if (((u8 *)D_006E7BFC)[1] != 0) {
            s32 sz = ((u8 *)D_006E7BFC)[1] << 13;
            D_003708EC = (s32)user_malloc(sz, 8, D_00574000, 0);
            _ppp_pppCreateHeap((u8 *)&D_006E7BD0 + 0x10, D_003708EC, sz);
        }
    }

    D_003708E0 = D_003708E4 = 0;
    func_00268BC8((int)&D_006E7BD0);
    D_006EA400 = 0;

    for (i = 0; i < D_006E7BFC->count; i++) {
        Slot80 *dst = &D_006E3BD0[i];
        u8 *src = (u8 *)&D_006E7BFC->ents[i];
        Slot50 *s50 = &D_006E7C00[i];

        dst->objs = 0;
        dst->buf = 0;
        *(u_long128 *)((u8 *)dst + 0x40) = *(u_long128 *)(src + 0x00);
        *(float *)((u8 *)dst + 0x20) = *(float *)(src + 0x38);
        *(u_long128 *)((u8 *)dst + 0x50) = *(u_long128 *)(src + 0x10);
        *(float *)((u8 *)dst + 0x24) = *(float *)(src + 0x3C);
        *(u_long128 *)((u8 *)dst + 0x60) = *(u_long128 *)(src + 0x20);
        dst->f0 = *(s32 *)(src + 0x30);
        *(float *)((u8 *)dst + 0x28) = *(float *)(src + 0x40);
        s50->flags = 0;
        *(s32 *)((u8 *)s50 + 0x04) = 0;
        *(s32 *)((u8 *)s50 + 0x08) = 0;
        func_002DD128((u8 *)s50 + 0x10);
        if (src[0x4A] == 2) {
            D_006EA400 = 1;
        }
    }

    if (D_003708E8 == 0) {
        switch (((u8 *)D_006E7BFC)[2]) {
        case 0:
            D_003708D4 = 0xC0000;
            break;
        case 1:
            D_003708D4 = 0x100000;
            break;
        case 2:
            D_003708D4 = 0x140000;
            break;
        default:
            D_003708D4 = 0xC0000;
            break;
        }
        D_003708E8 = (s32)user_malloc(D_003708D4, 0xB, D_00574008, 0);
        D_003708D8 = D_003708DC = 0;
    }
}

void func_00268BC8(int a)
{
    func_00293DC8(0x601);
    func_00293D48(a, 0x8603);
    D_003708D0 = 1;
}

int func_00268C08(void)
{
    int size = 0;

    if (D_006E7BD0.f8 != 0 && D_006E7BD0.f4 != 0) {
        size = D_006E7BD0.f8 - D_006E7BD0.f4 + 0x10;
    }
    if (D_006E7BD0.f18 != 0 && D_006E7BD0.f14 != 0) {
        size += 0x10 + (D_006E7BD0.f18 - D_006E7BD0.f14);
    }
    return size;
}

int func_00268C58(void)
{
    return D_003708E0;
}

int func_00268C68(void)
{
    return D_003708E4;
}

int func_00268C78(void)
{
    return D_003708D4;
}

int func_00268C88(void)
{
    return D_003708D8;
}

int func_00268C98(void)
{
    return D_003708DC;
}

extern char D_006A3A40[];
extern void func_002DCE80(void *d, void *a, void *b);

void func_00268CA8(void) {
    float b[4];
    float a[4];
    float c[4];
    float *base = (float *)D_006A3970;
    u_long128 *o;
    u_long128 *q;

    a[3] = 0;
    a[0] = base[4];
    a[1] = base[5];
    a[2] = base[6];
    func_002DCEC8(a, a);
    o = (u_long128 *)D_006A3A40;
    *o = *(u_long128 *)a;
    b[0] = a[1];
    b[1] = -a[0];
    b[2] = 0;
    b[3] = 0;
    func_002DCEC8(b, b);
    q = o - 1;
    q[0] = *(u_long128 *)b;
    func_002DCE80(c, b, a);
    func_002DCEC8(c, c);
    q[3] = *(u_long128 *)(D_006A3970 + 0x30);
    q[2] = *(u_long128 *)c;
}

extern void pppGetRotMatrixXYZ(void *, void *);
extern void func_0026C068(void *, void *);
extern void func_0026C1B8(void *, void *);
extern void func_0026C308(void *, void *);
extern void func_0026C458(void *, void *);
extern void func_0026C5A8(void *, void *);

void pppFpSetRotMatrix(u8 *a0, int a1) {
    register float f0 __asm__("$f0");
    register u8 *m __asm__("$2");
    register s32 v3 __asm__("$3");
    register s32 v4 __asm__("$4");
    register u8 *p1 __asm__("$3");
    register u8 *p2 __asm__("$4");

    switch (a1 & 0xFF) {
    case 0:
        pppGetRotMatrixXYZ(D_006A3930, a0 + 0x50);
        break;
    case 1:
        func_0026C068(D_006A3930, a0 + 0x50);
        break;
    case 2:
        func_0026C308(D_006A3930, a0 + 0x50);
        break;
    case 3:
        func_0026C1B8(D_006A3930, a0 + 0x50);
        break;
    case 4:
        func_0026C458(D_006A3930, a0 + 0x50);
        break;
    case 5:
        func_0026C5A8(D_006A3930, a0 + 0x50);
        break;
    default:
        pppGetRotMatrixXYZ(D_006A3930, a0 + 0x50);
        break;
    }
    f0 = *(float *)(a0 + 0x60);
    __asm__ volatile("" : "+f"(f0));
    m = (u8 *)D_006A3930;
    MIPS_MFC1(v3, f0);
    VU0_QMTC2_NI(9, v3);
    VU0_LQC2(10, 0, m);
    VU0_OP("vmulx.xyz $vf10, $vf10, $vf9x");
    VU0_SQC2(10, 0, m);

    f0 = *(float *)(a0 + 0x64);
    __asm__ volatile("" : "+f"(f0));
    p1 = m + 0x10;
    MIPS_MFC1(v4, f0);
    VU0_QMTC2_NI(9, v4);
    VU0_LQC2(10, 0, p1);
    VU0_OP("vmulx.xyz $vf10, $vf10, $vf9x");
    VU0_SQC2(10, 0, p1);

    f0 = *(float *)(a0 + 0x68);
    __asm__ volatile("" : "+f"(f0));
    p2 = m + 0x20;
    MIPS_MFC1(v3, f0);
    VU0_QMTC2_NI(9, v3);
    VU0_LQC2(10, 0, p2);
    VU0_OP("vmulx.xyz $vf10, $vf10, $vf9x");
    VU0_SQC2(10, 0, p2);

    {
        register float f1 __asm__("$f1") = *(float *)(a0 + 0x40);
        *(float *)(m + 0x30) = f1;
        f0 = *(float *)(a0 + 0x44);
        *(float *)(m + 0x34) = f0;
        f1 = *(float *)(a0 + 0x48);
        *(float *)(m + 0x38) = f1;
    }
}

extern s32 _m2c_func_00268EE8_D_006A3A30 __asm__("D_006A3A30");
void func_00268EE8(s32 arg0) {
    s32 temp_4;

    temp_4 = arg0 & 0xFF;
    switch (temp_4) {                               /* irregular */
    case 0:
        func_002DCE38(D_006A39B0, D_006A3970, D_006A3930);
        func_002DCE38(D_006A3AB0, D_006A3A70, D_006A39B0);
        return;
    case 1:
        func_002DD0C0(D_006A39B0, D_006A3930);
        func_002DCE08(D_006A39B0 + 0x30, D_006A3970, &D_006A3930[0].x);
        func_002DCE38(D_006A3AB0, D_006A3A70, D_006A39B0);
        return;
    case 2:
        func_002DCE38(D_006A39B0, &_m2c_func_00268EE8_D_006A3A30, D_006A3930);
        func_002DCE38(D_006A3AB0, D_006A3A70, D_006A39B0);
        return;
    default:
        func_002DCE38(D_006A39B0, D_006A3970, D_006A3930);
        func_002DCE38(D_006A3AB0, D_006A3A70, D_006A39B0);
        return;
    }
}
extern char D_00574038[];
extern char D_00574048[];
extern char D_00574058[];
void func_002DCF48(void *, void *);
void func_002DD0B0(void *, void *);
void func_002B4390(s32, s32);
void func_002B41B0(char *);
void func_001742A0(void *, void *);
void yiGetMatrixDObj(void *, void *);

void func_00269050(u8 *s80, u8 *s50, u8 *ent)
{
    float m[4][4];
    float tmp[4];

    pppFpSetRotMatrix(s80, ent[0x4B]);
    if (*(u32 *)s50 & 0xF) {
        float *g = (float *)D_006A3930;
        g[12] = g[13] = g[14] = 0.0f;
        func_002DD128(m);
        if (*(void **)(s50 + 4) != 0) {
            if (*(u32 *)s50 & 1) {
                register s32 k __asm__("$2");
                register float *p1 __asm__("$3");
                register float *p2 __asm__("$4");
                func_001072F8(*(void **)(s50 + 4), *(s32 *)(s50 + 8), m);
                k = 0x447A0000;
                VU0_QMTC2_NI(9, k);
                VU0_LQC2(10, 0, m);
                VU0_OP("vmulx.xyz $vf10, $vf10, $vf9x");
                VU0_SQC2(10, 0, m);
                p1 = m[1];
                VU0_QMTC2_NI(9, k);
                VU0_LQC2(10, 0, p1);
                VU0_OP("vmulx.xyz $vf10, $vf10, $vf9x");
                VU0_SQC2(10, 0, p1);
                p2 = m[2];
                VU0_QMTC2_NI(9, k);
                VU0_LQC2(10, 0, p2);
                VU0_OP("vmulx.xyz $vf10, $vf10, $vf9x");
                VU0_SQC2(10, 0, p2);
            } else if (*(u32 *)s50 & 2) {
                func_001742A0(*(void **)(s50 + 4), m);
            } else if (*(u32 *)s50 & 8) {
                yiGetMatrixDObj(*(void **)(s50 + 4), m);
            }
        }
        if (*(u32 *)s50 & 0x20) {
            func_002DCEC8(m[0], m[0]);
            func_002DCEC8(m[1], m[1]);
            func_002DCEC8(m[2], m[2]);
        }
        if (*(u32 *)s50 & 0x40) {
            u8 *gm = (u8 *)D_006A3930;
            register float *out __asm__("$3");
            register u8 *r1 __asm__("$4");
            float v;

            func_002DD0C0(gm, s50 + 0x10);
            func_002DCE38(gm, m, gm);
            out = tmp;
            VU0_LQC2(10, 0, gm);
            VU0_OP("vmul.xyz $vf10, $vf10, $vf10");
            VU0_OP("vmove.xyz $vf9, $vf10");
            VU0_OP("vaddx.y $vf9, $vf9, $vf9x");
            VU0_OP("vaddy.z $vf9, $vf9, $vf9y");
            VU0_OP("vsqrt Q, $vf9z");
            VU0_OP("vwaitq");
            VU0_OP("vaddq.x $vf10, $vf0, Q");
            VU0_SQC2(10, 0, out);
            v = tmp[0];
            *(float *)(s80 + 0x60) = v;

            r1 = gm + 0x10;
            VU0_LQC2(10, 0, r1);
            VU0_OP("vmul.xyz $vf10, $vf10, $vf10");
            VU0_OP("vmove.xyz $vf9, $vf10");
            VU0_OP("vaddx.y $vf9, $vf9, $vf9x");
            VU0_OP("vaddy.z $vf9, $vf9, $vf9y");
            VU0_OP("vsqrt Q, $vf9z");
            VU0_OP("vwaitq");
            VU0_OP("vaddq.x $vf10, $vf0, Q");
            VU0_SQC2(10, 0, out);
            gm += 0x20;
            *(float *)(s80 + 0x64) = v;
            VU0_LQC2(10, 0, gm);
            VU0_OP("vmul.xyz $vf10, $vf10, $vf10");
            VU0_OP("vmove.xyz $vf9, $vf10");
            VU0_OP("vaddx.y $vf9, $vf9, $vf9x");
            VU0_OP("vaddy.z $vf9, $vf9, $vf9y");
            VU0_OP("vsqrt Q, $vf9z");
            VU0_OP("vwaitq");
            VU0_OP("vaddq.x $vf10, $vf0, Q");
            VU0_SQC2(10, 0, out);
            *(float *)(s80 + 0x68) = v;
        } else {
            u8 *gm = (u8 *)D_006A3930;
            func_002DCE38(gm, s50 + 0x10, gm);
            func_002DCE38(gm, m, gm);
        }
    } else if (*(u32 *)s50 & 0x100) {
        func_002DD0C0(D_006A3930, s50 + 0x10);
    } else {
        pppFpSetRotMatrix(s80, ent[0x4B]);
    }
    func_00268EE8(ent[0x4A]);
}

void pppFpInfPrint(void)
{
    float cam_pos[4];
    float ply_pos[4];
    float diff[4];
    float inv_m[4][4];
    char buf[0x100];
    float len_vec[4];
    void *ply;
    float dist;

    func_002DCF48(inv_m, D_006A3970);
    func_002DD0B0(cam_pos, inv_m[3]);
    cam_pos[3] = 0;
    ply = (void *)Sg_GetPlayer();
    if (ply != 0) {
        Ch_GetPos(ply, &ply_pos[0], &ply_pos[1], &ply_pos[2]);
        ply_pos[3] = 0;
    } else {
        ply_pos[0] = ply_pos[1] = ply_pos[2] = ply_pos[3] = 0.0f;
    }
    func_002DD038(diff, ply_pos, cam_pos);
    {
        register float *out __asm__("$3") = len_vec;
        VU0_LQC2(10, 0, diff);
        VU0_OP("vmul.xyz $vf10, $vf10, $vf10");
        VU0_OP("vmove.xyz $vf9, $vf10");
        VU0_OP("vaddx.y $vf9, $vf9, $vf9x");
        VU0_OP("vaddy.z $vf9, $vf9, $vf9y");
        VU0_OP("vsqrt Q, $vf9z");
        VU0_OP("vwaitq");
        VU0_OP("vaddq.x $vf10, $vf0, Q");
        VU0_SQC2(10, 0, out);
    }
    dist = len_vec[0];
    func_002B4390(2, 2);
    func_002F0008(buf, D_00574038, (s32)cam_pos[0], (s32)cam_pos[1], (s32)cam_pos[2]);
    func_002B41B0(buf);
    func_002F0008(buf, D_00574048, (s32)ply_pos[0], (s32)ply_pos[1], (s32)ply_pos[2]);
    func_002B41B0(buf);
    func_002F0008(buf, D_00574058, (s32)dist);
    func_002B41B0(buf);
}

extern char D_00574060[];
void func_001AACA0(void *);
void func_001A9EE0(void *);
void func_0026A450(void);
void func_00173730(void *);
void func_002DD068(void *, void *, float);
s32 _pppRunPartFp(void *, s32);
void pppFpPointLightProc(void);

void pppFpLoop(void)
{
    float col[4];
    s32 i;
    s32 dbg;
    s32 used;
    s32 tot;
    s32 sz;

    if (D_003708B8 == 0) {
        return;
    }
    func_001AACA0(D_006A3A70);
    func_001A9EE0(D_006A3970);
    {
        register s32 bill __asm__("$2") = D_006EA400;
        if (bill != 0) {
            func_00268CA8();
        }
    }
    D_006A3BCC = (void *)D_003708E8;
    D_006A3924 = (HeapMgr *)&D_006E7BD0;
    func_0026A450();
    for (i = 0; i < D_006E7BFC->count; i++) {
        Slot50 *s50 = &D_006E7C00[i];
        Slot80 *s80 = &D_006E3BD0[i];
        Ent50 *ent;

        if (s50->flags & 0x10) {
            continue;
        }
        if (s80->f0 == -0x1000) {
            continue;
        }
        ent = &D_006E7BFC->ents[i];
        if (ent->f44 == 0) {
            if (func_002686F0(D_006A3970, (u8 *)s80 + 0x40, *(float *)((u8 *)s80 + 0x20), *(float *)((u8 *)s80 + 0x24), *(float *)((u8 *)s80 + 0x28)) != 0) {
                continue;
            }
        }
        if (s80->f0 < 0) {
        run_part:
            func_00269050(s80, s50, ent);
            func_00173730(col);
            if (col[0] > 1.0f) {
                col[0] = 1.0f;
            }
            if (col[1] > 1.0f) {
                col[1] = 1.0f;
            }
            if (col[2] > 1.0f) {
                col[2] = 1.0f;
            }
            if (col[3] > 1.0f) {
                col[3] = 1.0f;
            }
            func_002DD068(col, col, 4096.0f);
            *(s16 *)((u8 *)s80 + 0x70) = (s16)col[0];
            *(s16 *)((u8 *)s80 + 0x72) = (s16)col[1];
            *(s16 *)((u8 *)s80 + 0x74) = (s16)col[2];
            *(s16 *)((u8 *)s80 + 0x76) = (s16)col[3];
            D_006A3924 = (HeapMgr *)&D_006E7BD0;
            if (_pppRunPartFp(s80, 0x30) != 0) {
                D_006A3924 = (HeapMgr *)&D_006E7BD0;
                _pppAllFreePObject(s80);
                s80->f0 = -0x1000;
            }
        } else {
            s32 t = s80->f0 - 1;
            s80->f0 = t;
            if (t < 0) {
                s32 is_2 = (s80->f1D == 2);
                D_006A3924 = (HeapMgr *)&D_006E7BD0;
                _pppAllFreePObject(s80);
                D_006A3924 = (HeapMgr *)&D_006E7BD0;
                ent = &D_006E7BFC->ents[i];
                _pppStartPart((void *)s80, 0x1000, (s32)((void **)(*(s32 *)((u8 *)D_006E7BFC + 0x10)))[*(s32 *)((u8 *)ent + 0x34)], 1);
                if (is_2) {
                    s80->f1D = 1;
                }
                goto run_part;
            }
        }
    }
    pppFpPointLightProc();
    dbg = FFXIsDebug();
    used = (s32)D_006A3BCC - D_003708E8;
    if (dbg != 0 && used > D_003708D4) {
        func_002EF240(D_00574060, used / 1024);
        BREAK();
    }
    D_003708D8 = used;
    if (used > D_003708DC) {
        D_003708DC = used;
    }
    D_006A3BCC = 0;
    {
        s32 *h = (s32 *)&D_006E7BD0;
        tot = h[3] + h[7];
    }
    sz = func_00268C08();
    D_003708E0 = tot;
    if (tot > D_003708E4) {
        D_003708E4 = tot;
    }
    if (dbg != 0) {
        ((void (*)(s32, s32, s32))func_00293DA8)(used, D_003708D4, 0x601);
        ((void (*)(s32, s32, s32))func_00293DA8)(tot, sz, 0x603);
    }
}

extern s32 D_003708E8;
extern s32 D_003708EC;

/* DEBT(CAST) */
void func_002697B8(void) {
    s32 i;

    op_fp_effect_free();
    if (D_006E7BFC != 0) {
        D_006A3924 = (HeapMgr *)&D_006E7BD0;
        for (i = 0; i < D_006E7BFC->count; i++) {
            D_006A3924 = (HeapMgr *)&D_006E7BD0;
            _pppAllFreePObject(&D_006E3BD0[i]);
        }
        D_006E7BFC = 0;
    }
    if (D_003708EC != 0) {
        func_0011D590(D_003708EC, 8);
        D_003708EC = 0;
    }
    if (D_003708E8 != 0) {
        func_0011D590(D_003708E8, 0xB);
        D_003708E8 = 0;
    }
    Sg_PLightDispose();
}

void pppFpIDon(u16 id)
{
    Ent50Tbl *info = D_006E7BFC;
    Ent50 *e;
    Slot80 *s;
    int n;

    if (info != 0) {
        n = info->count;
        e = info->ents;
        s = D_006E3BD0;
        while (--n != -1) {
            if (e->f44 == id) {
                s->f0 = 0;
                s->f1D = 0;
            }
            e++;
            s++;
        }
    }
}

void pppFpIDoff(u16 id)
{
    Ent50Tbl *info = D_006E7BFC;
    Ent50 *e;
    Slot80 *s;
    int n;

    if (info != 0) {
        n = info->count;
        e = info->ents;
        s = D_006E3BD0;
        while (--n != -1) {
            if (e->f44 == id) {
                s->f1D = 1;
            }
            e++;
            s++;
        }
    }
}

void func_00269978(u16 id)
{
    Ent50Tbl *info = D_006E7BFC;
    Ent50 *e;
    Slot80 *s;
    int n;

    if (info != 0) {
        n = info->count;
        e = info->ents;
        s = D_006E3BD0;
        D_006A3924 = (HeapMgr *)&D_006E7BD0; /* DEBT(CAST): D_006E7BD0 is declared as SizeInfo; used as the heap here */
        while (--n != -1) {
            if (e->f44 == id) {
                D_006A3924 = (HeapMgr *)&D_006E7BD0;
                _pppAllFreePObject(s);
                s->f0 = -0x1000;
            }
            e++;
            s++;
        }
    }
}

void pppFpIDdispOn(u16 id)
{
    Ent50Tbl *info = D_006E7BFC;
    Ent50 *e;
    Slot50 *s;
    int n;

    if (info != 0) {
        n = info->count;
        e = info->ents;
        s = D_006E7C00;
        while (--n != -1) {
            if (e->f44 == id) {
                s->flags &= ~0x10;
            }
            e++;
            s++;
        }
    }
}

void pppFpIDdispOff(u16 id)
{
    Ent50Tbl *info = D_006E7BFC;
    Ent50 *e;
    Slot50 *s;
    int n;

    if (info != 0) {
        n = info->count;
        e = info->ents;
        s = D_006E7C00;
        while (--n != -1) {
            if (e->f44 == id) {
                s->flags |= 0x10;
            }
            e++;
            s++;
        }
    }
}

void func_00269B08(u16 id)
{
    Ent50Tbl *info = D_006E7BFC;
    Ent50 *e;
    Slot80 *s;
    int n;

    if (info != 0) {
        n = info->count;
        e = info->ents;
        s = D_006E3BD0;
        while (--n != -1) {
            if (e->f44 == id) {
                s->f0 = 0;
                s->f1D = 2;
            }
            e++;
            s++;
        }
    }
}

void func_00269B68(int a0)
{
    D_003708B8 = a0;
}

int func_00269B78(Slot80 *s)
{
    int r;

    if (s->f0 == -0x1000) {
        r = 0;
    } else {
        if (s->f1D != 0) {
            r = 2;
        } else {
            r = 1;
        }
    }
    return r;
}

int func_00269BA8(u16 id)
{
    Ent50Tbl *info = D_006E7BFC;
    Ent50 *e;
    Slot80 *s;
    int n;

    if (info != 0) {
        n = info->count;
        e = info->ents;
        s = D_006E3BD0;
        while (--n != -1) {
            if (e->f44 == id) {
                return func_00269B78(s);
            }
            e++;
            s++;
        }
    }
    return -1;
}

void pppFpGetMngPtr(int id, Slot80 **ps, void *pe)
{
    Slot50 **pe2 = pe;
    Ent50Tbl *info;
    Ent50 *e;
    Slot80 *s;
    Slot50 *t;
    int n;

    if (ps != 0) {
        *ps = 0;
    }
    if (pe2 != 0) {
        *pe2 = 0;
    }
    info = D_006E7BFC;
    if (info != 0) {
        n = info->count;
        e = info->ents;
        s = D_006E3BD0;
        t = D_006E7C00;
        while (--n != -1) {
            if (e->f44 == id) {
                if (ps != 0) {
                    *ps = s;
                }
                if (pe2 != 0) {
                    *pe2 = t;
                }
                return;
            }
            e++;
            s++;
            t++;
        }
    }
}

void pppFpSetStickChr(int v, Chr *c, int b)
{
    T6_Slot50 *e;

    if (Ch_CheckHandle((int)c) == -1) {
        return;
    }
    pppFpGetMngPtr(v, 0, &e);
    if (e != 0) {
        e->idx = b;
        e->id = (u32)c; /* DEBT(CAST): the view names this word id; it holds the character */
        e->flags |= 1;
    }
}

void pppFpSetStickMap(int a, int b)
{
    Block3 *blk;

    pppFpGetMngPtr(a, 0, &blk);
    if (blk != 0) {
        blk->flags |= 2;
        blk->f4 = b;
        blk->f8 = 0;
    }
}

void func_00269D60(int a, int b)
{
    Block3 *blk;

    pppFpGetMngPtr(a, 0, &blk);
    if (blk != 0) {
        blk->flags |= 8;
        blk->f4 = b;
        blk->f8 = 0;
    }
}

void func_00269DA8(int a)
{
    Block3 *blk;

    pppFpGetMngPtr(a, 0, &blk);
    if (blk != 0) {
        blk->f4 = 0;
        blk->f8 = 0;
        blk->flags &= ~0xF;
    }
}

void pppFpSetStickPos(int a, R6Vec3 *v) {
    R6Mtx40 *o;

    pppFpGetMngPtr(a, 0, &o);
    if (o != 0) {
        func_002DD128(o->m);
        o->f40 = v->x;
        o->f44 = v->y;
        o->f48 = v->z;
    }
}

void func_00269E50(void)
{
    Ent50Tbl *info = D_006E7BFC;
    Ent50 *e;
    int n;

    if (info != 0) {
        n = info->count;
        e = info->ents;
        while (--n != -1) {
            if (e->f44 != 0) {
                pppFpIDon(e->f44);
            }
            e++;
        }
    }
}

void func_00269EC0(void)
{
    Ent50Tbl *info = D_006E7BFC;
    Ent50 *e;
    Slot80 *s;
    int n;

    if (info != 0) {
        n = info->count;
        e = info->ents;
        s = D_006E3BD0;
        D_006A3924 = (HeapMgr *)&D_006E7BD0; /* DEBT(CAST): SizeInfo doubles as the heap of this table */
        while (--n != -1) {
            if (e->f44 != 0) {
                D_006A3924 = (HeapMgr *)&D_006E7BD0;
                _pppAllFreePObject(s);
                s->f0 = -0x1000;
            }
            e++;
            s++;
        }
    }
}

void pppFpSaveStat(u8 *buf)
{
    u8 *out;
    Ent50 *e;
    T6_Slot50 *w;
    int n;
    int bit;

    if (buf != 0 && D_006E7BFC != 0) {
        out = buf;
        w = (T6_Slot50 *)D_006E7C00; /* DEBT(CAST): see T6_Slot50 */
        e = D_006E7BFC->ents;
        bit = 0;
        n = D_006E7BFC->count;
        *out = 0;
        while (--n != -1) {
            if (e->f44 != 0) {
                if (func_00269BA8(e->f44) == 1) {
                    *out |= 1 << bit;
                }
                if (w->flags & 0x10) {
                    *out |= 1 << (bit + 1);
                }
                bit += 2;
                if (bit >= 8) {
                    out++;
                    bit = 0;
                    *out = 0;
                }
            }
            e++;
            w++;
        }
    }
}

void pppFpLoadStat(u8 *buf)
{
    u8 *in;
    Ent50 *e;
    T6_Slot50 *w;
    int n;
    int bit;

    if (buf != 0 && D_006E7BFC != 0) {
        w = (T6_Slot50 *)D_006E7C00; /* DEBT(CAST): see T6_Slot50 */
        n = D_006E7BFC->count;
        e = D_006E7BFC->ents;
        in = buf;
        bit = 0;
        while (--n != -1) {
            if (e->f44 != 0) {
                if ((*in >> bit) & 1) {
                    pppFpIDon(e->f44);
                }
                if ((*in >> (bit + 1)) & 1) {
                    w->flags |= 0x10;
                } else {
                    w->flags &= ~0x10;
                }
                bit += 2;
                if (bit >= 8) {
                    bit = 0;
                    in++;
                }
            }
            e++;
            w++;
        }
    }
}

void pppFpDispDebug(void)
{
    Ent50 *e;
    T6_Slot50 *w;
    Slot80 *s;
    int n;
    int i;
    int st;
    int kind;
    u32 flags;

    func_002EF240(D_00574088);
    func_002EF240(D_005740A8, D_003708B8 ? D_005740B8 : D_005740C0);
    func_002EF240(D_005740C8);
    func_002EF240(D_005740F8);
    if (D_006E7BFC != 0) {
        n = D_006E7BFC->count;
        s = D_006E3BD0;
        e = D_006E7BFC->ents;
        w = (T6_Slot50 *)D_006E7C00; /* DEBT(CAST): see T6_Slot50 */
        i = 0;
        while (--n != -1) {
            st = func_00269B78(s);
            flags = w->flags;
            kind = 0;
            switch (flags & 0xF) {
            case 1:
                kind = 1;
                break;
            case 2:
                kind = 2;
                break;
            case 4:
                kind = 3;
                break;
            case 8:
                kind = 4;
                break;
            }
            func_002EF240(D_00574168, i, e->f44, e->f46, D_003708F0[st], (flags & 0x10) ? D_005740C0 : D_00574190,
                          D_00370900[kind], w->id, w->idx, flags);
            e++;
            s++;
            w++;
            i++;
        }
    }
    func_002EF240(D_00574198);
}

u16 func_0026A380(void) {
    return D_006E7BFC->count;
}

void func_0026A390(int idx, Slot80 **ps, Slot50 **pe)
{
    Ent50Tbl *info;
    Slot80 *s;
    Slot50 *t;
    int n;
    int i;

    if (ps != 0) {
        *ps = 0;
    }
    if (pe != 0) {
        *pe = 0;
    }
    info = D_006E7BFC;
    if (info != 0) {
        n = info->count;
        s = D_006E3BD0;
        t = D_006E7C00;
        for (i = 0; i < n; i++) {
            if (i == idx) {
                if (ps != 0) {
                    *ps = s;
                }
                if (pe != 0) {
                    *pe = t;
                }
                return;
            }
            s++;
            t++;
        }
    }
}

void func_0026A400(void)
{
    Chr *c;

    if (D_003708C0 > 0) {
        Ch_HandleRewind();
        while ((c = func_00102A60()) != 0) {
            ((void (*)(Chr *, int))func_0010DC38)(c, D_003708C4); /* DEBT(CAST): second argument passed as int */
        }
    }
}

void func_0026A450(void) {
    D_003708BC = 0;
    D_003708C4 = 0;
}

extern char D_005741B8[];
void Sg_PLightGetPos(int idx, float *x, float *y, float *z);
float Sg_PLightGetRadius(int idx);
void Sg_PLightGetColor(int idx, int *r, int *g, int *b);
int Sg_PLightGetLight(int idx);
void Sg_PLightAllocate(int n);
void Sg_PLightSetEnable(int idx, int en);

typedef struct {
    float x;
    float y;
    float z;
    float rad;
    s32 r;
    s32 g;
    s32 b;
    s32 light;
    float atten;
} PLightSave;

void pppFpPointLightProc(void)
{
    s32 cur = D_003708C0;
    s32 i;
    PLightSave *buf;

    if (cur < D_003708BC) {
        buf = 0;
        if (cur > 0) {
            buf = (PLightSave *)user_malloc(cur * sizeof(PLightSave), 0xB, D_005741B8, 0);
            for (i = 0; i < cur; i++) {
                Sg_PLightGetPos(i, &buf[i].x, &buf[i].y, &buf[i].z);
                buf[i].rad = Sg_PLightGetRadius(i);
                Sg_PLightGetColor(i, &buf[i].r, &buf[i].g, &buf[i].b);
                buf[i].light = Sg_PLightGetLight(i);
                buf[i].atten = (float)((s32 (*)(s32))Sg_PLightGetAttenuation)(i);
            }
            func_0010D720();
        }
        Sg_PLightAllocate(D_003708BC);
        D_003708C0 = D_003708BC;
        for (i = 0; i < cur; i++) {
            ((void (*)(int, float, float, float, float, int, int, int, int))Sg_PLightDefine)(
                i, buf[i].x, buf[i].y, buf[i].z, buf[i].rad, buf[i].r, buf[i].g, buf[i].b, buf[i].light);
            ((void (*)(s32, double))Sg_PLightSetAttenuation)(i, (double)buf[i].atten);
        }
        for (; i < D_003708BC; i++) {
            Sg_PLightSetEnable(i, 0);
        }
        if (buf != 0) {
            func_0011D590((int)buf, 0xB);
        }
    } else {
        for (i = D_003708BC; i < D_003708C0; i++) {
            Sg_PLightSetEnable(i, 0);
        }
    }
    func_0026A400();
}

void Sg_PLightDispose(void)
{
    if (D_003708C0 > 0) {
        func_0010D720();
        D_003708C0 = 0;
    }
}

void func_0026A6B8(u16 id)
{
    Ent50Tbl *info = D_006E7BFC;
    Ent50 *e;
    Slot80 *s;
    int n;

    if (info != 0) {
        n = info->count;
        e = info->ents;
        s = D_006E3BD0;
        while (--n != -1) {
            if (e->f46 == id) {
                s->f0 = 0;
                s->f1D = 0;
            }
            e++;
            s++;
        }
    }
}

void func_0026A710(u16 id)
{
    Ent50Tbl *info = D_006E7BFC;
    Ent50 *e;
    Slot80 *s;
    int n;

    if (info != 0) {
        n = info->count;
        e = info->ents;
        s = D_006E3BD0;
        while (--n != -1) {
            if (e->f46 == id) {
                s->f1D = 1;
            }
            e++;
            s++;
        }
    }
}

void func_0026A770(u16 id)
{
    Ent50Tbl *info = D_006E7BFC;
    Ent50 *e;
    Slot80 *s;
    int n;

    if (info != 0) {
        n = info->count;
        e = info->ents;
        s = D_006E3BD0;
        D_006A3924 = (HeapMgr *)&D_006E7BD0; /* DEBT(CAST): D_006E7BD0 is declared as SizeInfo; used as the heap here */
        while (--n != -1) {
            if (e->f46 == id) {
                D_006A3924 = (HeapMgr *)&D_006E7BD0;
                _pppAllFreePObject(s);
                s->f0 = -0x1000;
            }
            e++;
            s++;
        }
    }
}

/* DEBT(NAME): module guessed: script VM opcode handlers (ctx->info->slot[n] + 0xA0 + offset, see ScriptCtx in w8.h)
 * plus the slot table at D_006E7BFC/D_006E3BD0. Handlers using the "(base + 0xA0) + off" address form
 * were left as INCLUDE_ASM: gcc keeps folding the constant into the offset. */

void func_0026A838(u16 id)
{
    Ent50Tbl *info = D_006E7BFC;
    Ent50 *e;
    Slot50 *s;
    int n;

    if (info != 0) {
        n = info->count;
        e = info->ents;
        s = D_006E7C00;
        while (--n != -1) {
            if (e->f46 == id) {
                s->flags &= ~0x10;
            }
            e++;
            s++;
        }
    }
}

void func_0026A8A0(u16 id)
{
    Ent50Tbl *info = D_006E7BFC;
    Ent50 *e;
    Slot50 *s;
    int n;

    if (info != 0) {
        n = info->count;
        e = info->ents;
        s = D_006E7C00;
        while (--n != -1) {
            if (e->f46 == id) {
                s->flags |= 0x10;
            }
            e++;
            s++;
        }
    }
}

void func_0026A900(u16 id)
{
    Ent50Tbl *info = D_006E7BFC;
    Ent50 *e;
    Slot80 *s;
    int n;

    if (info != 0) {
        n = info->count;
        e = info->ents;
        s = D_006E3BD0;
        while (--n != -1) {
            if (e->f44 == id) {
                s->f8 = 0;
            }
            e++;
            s++;
        }
    }
}

void func_0026A958(void)
{
    Slot80 *s;
    int n;

    if (D_006E7BFC != 0) {
        n = D_006E7BFC->count;
        s = D_006E3BD0;
        while (--n != -1) {
            s->f0 = 0;
            s++;
        }
    }
}
