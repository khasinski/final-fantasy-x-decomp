/* tu_284 0x260a70-0x265f78: low; ~ei (config/tu_map.tsv) */
#define func_00260A70 _hdr_func_00260A70
#define func_00264248 _hdr_func_00264248
#define func_002DD968 _hdr_func_002DD968
#define func_001BE7B8 _hdr_func_001BE7B8
#define func_00258618 _hdr_func_00258618
#define func_00258410 _hdr_func_00258410
#define SndSepPlaySimple _hdr_SndSepPlaySimple
#define func_00262C90 _hdr_func_00262C90
#define func_0025A158 _hdr_func_0025A158
#include "common.h"
#include "vu0.h"
#include "ffx/w8.h"
#include "ffx/q6.h"
#include "ffx/s6.h"
#include "ffx/t6.h"
#include "ffx/u4.h"
#include "ffx/v6.h"
#include "ffx/r6.h"
#undef func_0025A158
#undef func_00262C90
#undef SndSepPlaySimple
#undef func_00258410
#undef func_00258618
#undef func_001BE7B8
#undef func_002DD968
#undef func_00264248
#undef func_00260A70

int SndSepPlaySimple(int handle);

void func_00264248(void);
void func_002DD968(float *dst, float *src1, float *src2, float t);
int func_001BE7B8(int id);
void func_00258618(u16 id, u16 n, int bit);
void func_00258410(u16 n, int mode);
void func_00262C90(ChrWork *w);
void func_0025A158(int id, void *buf);



#define LPA(type, off) (*(type *)((char *)lpamng + (off)))
extern u_long128 D_00327790[];
extern float eff_sin_t[];

/* local view of the float/byte members touched near the end of lpamng */
typedef struct LpaView {
    u8 pad0[0x11090];
    S6Pt50 pts11090[7];
    S6Pt50 pt112C0;
    float f11310;
    float f11314;
    float f11318;
    float f1131C;
    u_long128 q11320;
    s32 w11330;
    u8 pad11334[0x11340 - 0x11334];
    float f11340;
    float f11344;
    float f11348;
    float f1134C;
    u8 pad11350[0x114D8 - 0x11350];
    float f114D8;
    float f114DC;
    u8 pad114E0[0x11550 - 0x114E0];
    float f11550;
    float f11554;
    u8 pad11558[0x1156C - 0x11558];
    u8 f1156C;
    u8 f1156D;
    u8 f1156E;
    u8 f1156F;
    u8 pad11570[0x11575 - 0x11570];
    u8 f11575;
    u8 f11576;
    u8 f11577;
    u8 pad11578[2];
    u8 f1157A;
    u8 pad1157B[3];
    s16 f1157E;
    s16 f11580;
    u8 pad11582[2];
    float f11584;
    float f11588;
    float f1158C;
    float f11590;
    float f11594;
    u8 pad11598[0x115BC - 0x11598];
    float f115BC;
    float f115C0;
    float f115C4;
    float f115C8;
    int f115CC;
    u8 pad115D0[0x115F0 - 0x115D0];
    float f115F0[4];
    union {
        u16 h11600;
        struct {
            u8 b11600;
            u8 f11601;
        } b;
    } u11600;
    u16 f11602;
    u8 f11604;
    u8 pad11605[3];
    int f11608;
    int f1160C;
    int f11610;
    int f11614;
    s16 f11618;
    s16 f1161A;
    int f1161C;
    u16 f11620;
    u16 f11622;
    u16 f11624;
    u16 f11626;
    u8 pad11628[0x1164C - 0x11628];
    int f1164C;
    int f11650;
    int f11654;
} LpaView;
#define LPV ((LpaView *)lpamng)

s32 _m2c_func_00260A70__pppRunPart(void *, s32) __asm__("_pppRunPart");
void _m2c_func_00260A70_func_002DCE38(void *, void *, void *) __asm__("func_002DCE38");
void _m2c_func_00260A70_func_002DD0C0(void *, void *) __asm__("func_002DD0C0");
void _m2c_func_00260A70_pppSetMatrix(void *) __asm__("pppSetMatrix");
void func_00260A70(S6Task *arg0) __attribute__((register_precision(s3, 128)));
/* DEBT(CAST) */
void func_00260A70(S6Task *arg0) {
    if (arg0->h1E != 0) {
        _m2c_func_00260A70_func_002DD0C0(D_006A3A70, &lpamng->ents3[8].pad2[0x3A]);
        _m2c_func_00260A70_func_002DD0C0(D_006A3970, lpamng->ents3[7].pad4C);
        (*(float *)((u8 *)(D_006A3A70) + (0x38))) = (float) ((*(float *)((u8 *)(D_006A3A70) + (0x38))) + 29184.0f);
        _m2c_func_00260A70_pppSetMatrix(arg0);
        _m2c_func_00260A70_func_002DCE38(D_006A39B0, D_006A3970, D_006A3930);
        _m2c_func_00260A70_func_002DCE38(D_006A3AB0, D_006A3A70, D_006A39B0);
        D_006A3924 = D_006A3690;
        if (_m2c_func_00260A70__pppRunPart(arg0, 0x30) != 0) {
            arg0->h1E = 0U;
        }
    }
}

float func_00260B68(void)
{
    switch (lpamng->f1157C) {
    case 0:
        return 1.0f;
    case 1:
        return 0.5f;
    case 2:
        return 0.25f;
    case 3:
        return 0.125f;
    default:
        return 1.0f;
    }
}

void func_00260C08(void)
{
    LpaView *w;

    if (D_006A391C[12].a.req.id < 0) {
        if (lpamng->f11622 & 0x100) {
            lpamng->f1157C++;
            if (lpamng->f1157C >= 3) {
                lpamng->f1157C = 0;
            }
            LPV->f11580 = 30;
            LPV->f1158C = LPV->f11340;
            LPV->f11590 = func_00260B68();
        }
    }
    w = LPV;
    if (w->f11580 > 0) {
        if (--w->f11580 == 0) {
            float v = w->f11590;
            w->f11577 = 1;
            w->f11348 = v;
            w->f11344 = v;
            w->f11340 = v;
        } else {
            int idx = ((30 - w->f11580) * 0x4000) / 30;
            register float s __asm__("$f2") = eff_sin_t[((u32)idx >> 4) & 0xFFF];
            register float v __asm__("$f2") = (w->f11590 - w->f1158C) * s + w->f1158C;
            w->f11348 = v;
            w->f11344 = v;
            w->f11340 = v;
        }
    }
}

float func_00260D50(void)
{
    switch (lpamng->f1157B) {
    case 0:
        return 0.0f;
    case 1:
        return -3640.0f;
    case 2:
        return -7281.0f;
    default:
        return 0.0f;
    }
}

void func_00260DD8(void)
{
    LpaView *w;

    if (D_006A391C[12].a.req.id < 0) {
        if (lpamng->f11622 & 2) {
            if (++lpamng->f1157B >= 3) {
                lpamng->f1157B = 0;
            }
            goto set_rot;
        } else if (lpamng->f11622 & 1) {
            if (--lpamng->f1157B >= 3) {
                lpamng->f1157B = 2;
            }
        set_rot:
            LPV->f1157E = 30;
            LPV->f11584 = (float)LPV->w11330;
            LPV->f11588 = func_00260D50();
        }
    }
    w = LPV;
    if (w->f1157E > 0) {
        if (--w->f1157E == 0) {
            w->f11577 = 1;
            w->w11330 = (int)w->f11588;
        } else {
            int idx = ((30 - w->f1157E) * 0x4000) / 30;
            register float s __asm__("$f2") = eff_sin_t[((u32)idx >> 4) & 0xFFF];
            register float v __asm__("$f2") = (w->f11588 - w->f11584) * s + w->f11584;
            w->w11330 = (int)v;
        }
    }
}

void func_00260F60(void)
{
    u_long128 *src = (u_long128 *)((char *)lpamng + 0x112C0);
    LPA(u_long128, 0x11310) = *src;
}

typedef int (*EntFilterFn)(WorkEnt *);
float func_002DCEA0(float *, float *);

WorkEnt *func_00260F88_impl(S6Pt50 *pt, float *dir, EntFilterFn cb) __asm__("func_00260F88");
WorkEnt *func_00260F88_impl(S6Pt50 *pt, float *dir, EntFilterFn cb)
{
    register S6Pt50 *rpt __asm__("$19") = pt;
    float v[4];
    WorkEnt *best = 0;
    WorkEnt *e = lpamng->ents;
    WorkEnt *end = &lpamng->ents[*(s16 *)((u8 *)lpamng + 2)];
    float best_score;

    v[2] = 0.0f;
    v[3] = 1.0f;
    best_score = v[2];
    for (; e < end; e++) {
        float dot;
        float dist;
        float score;
        union {
            int i;
            float f;
        } u;

        if (*(u16 *)((u8 *)e + 6) == 0xFFFF) {
            continue;
        }
        if (cb != 0 && cb(e) == 0) {
            continue;
        }
        {
            float px = rpt->x;
            float py = rpt->y;
            v[0] = (float)e->x - px;
            v[1] = (float)e->y - py;
        }
        dot = ((float (*)(float *, float *))func_002DCEA0)(v, dir);
        if (dot > 0.5f) {
            register int bits __asm__("$2");
            VU0_LQC2(10, 0, v);
            VU0_OP("vmul.xyz $vf10, $vf10, $vf10");
            VU0_OP("vaddx.y $vf10, $vf10, $vf10x");
            VU0_OP("vaddy.z $vf10, $vf10, $vf10y");
            VU0_OP("vsqrt Q, $vf10z");
            VU0_OP("vwaitq");
            VU0_OP("vaddq.x $vf10, $vf0, Q");
            VU0_QMFC2_NI(bits, 10);
            u.i = bits;
            dist = u.f;
            if (dist > 0.0f) {
                score = dot / (dist * dist);
                if (score > best_score) {
                    best_score = score;
                    best = e;
                }
            }
        }
    }
    return best;
}

WorkEnt *func_00261130_impl(float *out_dist, S6Pt50 *pt, EntFilterFn cb) __asm__("func_00261130");
WorkEnt *func_00261130_impl(float *out_dist, S6Pt50 *pt, EntFilterFn cb)
{
    float v[4];
    WorkEnt *best = 0;
    WorkEnt *e = lpamng->ents;
    WorkEnt *end = &lpamng->ents[*(s16 *)((u8 *)lpamng + 2)];
    float best_dist = 1000000000.0f;

    v[3] = 1.0f;
    v[2] = 0.0f;
    for (; e < end; e++) {
        float dist;
        union {
            int i;
            float f;
        } u;

        if (*(u16 *)((u8 *)e + 6) == 0xFFFF) {
            continue;
        }
        if (cb != 0 && cb(e) == 0) {
            continue;
        }
        v[0] = (float)e->x - pt->x;
        v[1] = (float)e->y - pt->y;
        {
            register int bits __asm__("$2");
            VU0_LQC2(10, 0, v);
            VU0_OP("vmul.xyz $vf10, $vf10, $vf10");
            VU0_OP("vaddx.y $vf10, $vf10, $vf10x");
            VU0_OP("vaddy.z $vf10, $vf10, $vf10y");
            VU0_OP("vsqrt Q, $vf10z");
            VU0_OP("vwaitq");
            VU0_OP("vaddq.x $vf10, $vf0, Q");
            VU0_QMFC2_NI(bits, 10);
            u.i = bits;
            dist = u.f;
        }
        if (dist < best_dist) {
            best_dist = dist;
            best = e;
        }
    }
    *out_dist = best_dist;
    return best;
}

void func_00261288(void)
{
    float v0[4];
    float v1[4];
    S6Pt50 *p = &LPV->pt112C0;
    WorkEnt *e = &lpamng->ents[lpamng->f115E4];

    v0[0] = e->x;
    v0[1] = e->y;
    v0[2] = 0.0f;
    v0[3] = 1.0f;
    lpamng->f115D0 += lpamng->f115D4;
    if (lpamng->f115D0 >= 1.0f) {
        p->x = v0[0];
        p->y = v0[1];
        func_00260F60();
        lpamng->cb_a = lpamng->next_a;
        p->f3C = lpamng->f115DC;
        lpamng->next_a = 0;
    } else {
        func_002DD968(v1, v0, LPV->f115F0, lpamng->f115D0);
        p->x = v1[0];
        p->y = v1[1];
        p->f3C = (lpamng->f115DC - lpamng->f115D8) * lpamng->f115D0 + lpamng->f115D8;
        func_00260F60();
    }
}

/* header prototypes say (void); the real signature is (int, float) */
void func_002613B8_impl(int a, float f) __asm__("func_002613B8");
void func_002613B8_impl(int a, float f)
{
    GlobalWork *w;
    float v;

    LPA(u_long128, 0x115F0) = LPA(u_long128, 0x112C0);
    lpamng->f115D4 = f;
    lpamng->f115D8 = LPA(float, 0x112FC);
    lpamng->f115D0 = 0.0f;
    v = func_002596D8(a);
    w = lpamng;
    w->f115E4 = a;
    *(u16 *)((char *)w + 0x11304) = a;
    w->f115DC = v;
}

void func_00261430(void)
{
    GlobalWork *w;

    func_002613B8();
    w = lpamng;
    if (w->next_a == 0) {
        w->next_a = w->cb_a;
        w->cb_a = func_00261288;
    }
}

void func_00261478(void)
{
    if (D_006A362E == 0) {
        lpamng->cb_a = lpamng->next_a;
        lpamng->cb_b = lpamng->next_b;
        lpamng->next_a = 0;
        lpamng->next_b = 0;
    }
}

void func_002614B8(void)
{
    func_00257288(0);
    func_00260A70(D_006A3610);
}

typedef struct {
    u8 pad0[0x10];
    u16 h10;
    u16 h12;
    u8 b14;
} EiParaEnt14;

void func_002614E0(int ch, int idx) __attribute__((register_precision(s3, 128)));
void func_002614E0(int ch, int idx)
{
    int out;
    s32 pos;
    EiParaEnt14 *ent = (EiParaEnt14 *)func_00256F08(lpamng->ents[idx].f06, &out);
    u16 f = ent->h10;

    LPV->f1161A = 0x78;
    LPV->f11610 = 0;
    LPV->f1160C = 0;
    LPV->f11614 = ent->b14;
    LPV->f11608 = func_00256FA0(0x21);
    LPV->f1160C = TOGetSaveChrName(ch);
    LPV->f11618 = 0;
    if (f & 1) {
        LPV->f11610 = func_00257010(7);
    } else if (f & 2) {
        LPV->f11610 = func_00257010(8);
    } else if (f & 4) {
        LPV->f11610 = func_00257010(9);
    } else if (f & 8) {
        LPV->f11610 = func_00257010(10);
    } else if (f & 0x10) {
        LPV->f11610 = func_00257010(11);
    } else if (f & 0x20) {
        LPV->f11610 = func_00257010(12);
    } else if (f & 0x40) {
        LPV->f11610 = func_00257010(13);
    } else if (f & 0x80) {
        LPV->f11610 = func_00257010(14);
    } else if (f & 0x100) {
        LPV->f11610 = func_00257010(0);
        LPV->f11614 *= 50;
    } else if (f & 0x200) {
        LPV->f11610 = func_00257010(1);
        LPV->f11614 *= 5;
    } else if (ent->h12 != 0) {
        Pt16 *cmd = (Pt16 *)MsGetRomPlyCommand(ent->h12, &pos);
        LPV->f11608 = func_00256FA0(0x20);
        LPV->f11610 = func_00256F58(pos, cmd);
        LPV->f11618 = 1;
    }
}

void func_002560D0(void *o, int id, float x, float y, float z, float rx, float ry, float rz, float sx, float sy, float sz);
void func_002614E0(int ch, int idx);
void func_002618E0(void);
void func_00259678(void);
S6Pt50 *func_002599C0(int i);

void func_00261728(int ch, int idx)
{
    WorkEnt *e = &lpamng->ents[idx];
    s32 *save = (s32 *)MsGetSaveMenu();

    pppCreateHeap((HHead *)D_006A3690, (HBlk *)0x1E81000, 0x7D000);
    if (((*save >> 14) & 3) != 2) {
        func_002560D0(D_006A3610, 0, e->x, e->y, 0.0f, 0.0f, 0.0f, 0.0f, 0.5f, 0.5f, 0.5f);
    } else {
        func_002560D0(D_006A3610, 4, e->x, e->y, 0.0f, 0.0f, 0.0f, 0.0f, 0.5f, 0.5f, 0.5f);
    }
    e->flags |= 1 << ch;
    func_00258780();
    func_00264578();
    func_002614E0(ch, idx);
    if (lpamng->next_b == 0) {
        lpamng->next_b = lpamng->cb_b;
        lpamng->cb_b = func_002614B8;
    }
    if (lpamng->next_a == 0) {
        lpamng->next_a = lpamng->cb_a;
        lpamng->cb_a = func_00261478;
    }
}

typedef struct {
    u8 pad0[0x3C];
    float f3C;
    u8 pad40[4];
    u16 h44;
    u8 pad46[0xA];
} EiPt50;

void func_002622D0(void);

void func_002618E0(void)
{
    float v0[4];
    float v1[4];

    switch (LPV->u11600.b.b11600) {
    case 0:
        LPV->u11600.b.f11601++;
        LPV->f11576 = -0x80 - (LPV->u11600.b.f11601 * 128) / 40;
        if ((s8)LPV->f11576 < 0) {
            LPV->f11576 = 0x80;
        }
        if (D_006A362E == 0) {
            register s32 off __asm__("$2") = lpamng->f115E8 * 0x50 + 0x11090;
            ((EiPt50 *)((u8 *)lpamng + off))->f3C = 0.0f;
            LPV->u11600.b.b11600 = 1;
            LPV->f11576 = 0;
        }
        break;
    case 1: {
        WorkEnt *e = &lpamng->ents[lpamng->f115E4];

        v0[0] = e->x;
        v0[1] = e->y;
        v0[2] = 0.0f;
        v0[3] = 1.0f;
        lpamng->f115D0 += 1.0f / 12.0f;
        if (lpamng->f115D0 >= 1.0f) {
            LPV->u11600.b.b11600 = 2;
            LPV->u11600.b.f11601 = 0;
            SndSepPlaySimple(0x80000070);
            LPA(u_long128, 0x11310) = *(u_long128 *)v0;
            pppCreateHeap((HHead *)D_006A3690, (HBlk *)0x1E81000, 0x7D000);
            func_002560D0(D_006A3610, 1, v0[0], v0[1], 0.0f, 0.0f, 0.0f, 0.0f, 0.5f, 0.5f, 0.5f);
            {
                register s32 off __asm__("$2") = lpamng->f115E8 * 0x50 + 0x11090;
                ((EiPt50 *)((u8 *)lpamng + off))->h44 = lpamng->f115E4;
            }
            func_0025A0C8(lpamng->f115E8);
            func_002599C0(lpamng->f115E8);
            LPV->f11577 = 1;
            func_002622D0();
        } else {
            func_002DD968(v1, v0, LPV->f115F0, lpamng->f115D0);
            LPV->f11310 = v1[0];
            LPV->f11314 = v1[1];
        }
        break;
    }
    case 2:
        LPV->u11600.b.f11601++;
        LPV->f11576 = (LPV->u11600.b.f11601 * 128) / 40;
        if ((s8)LPV->f11576 < 0) {
            LPV->f11576 = 0x80;
        }
        if (D_006A362E == 0) {
            LPV->f11576 = 0x80;
            lpamng->cb_a = lpamng->next_a;
            lpamng->cb_b = lpamng->next_b;
            lpamng->next_a = 0;
            lpamng->next_b = 0;
        }
        break;
    }
}

void func_00261C08(void)
{
    u8 state = lpamng->f11600;

    if (state == 0 || state == 2) {
        func_002614B8();
    }
}

void func_00261C40(int ch, int idx)
{
    WorkEnt *e = &lpamng->ents[lpamng->ents3[ch].h0];

    SndSepPlaySimple(0x80000070);
    lpamng->f11600 = 0;
    LPV->u11600.b.f11601 = 0;
    LPV->f115F0[0] = LPV->f11310 = e->x;
    LPV->f115F0[1] = LPV->f11314 = e->y;
    lpamng->f115E4 = idx;
    lpamng->f115D0 = 0.0f;
    lpamng->f115E8 = ch;
    pppCreateHeap((HHead *)D_006A3690, (HBlk *)0x1E81000, 0x7D000);
    func_002560D0(D_006A3610, 2, e->x, e->y, 0.0f, 0.0f, 0.0f, 0.0f, 0.5f, 0.5f, 0.5f);
    if (lpamng->next_b == 0) {
        lpamng->next_b = lpamng->cb_b;
        lpamng->cb_b = func_00261C08;
    }
    if (lpamng->next_a == 0) {
        lpamng->next_a = lpamng->cb_a;
        lpamng->cb_a = func_002618E0;
    }
}

void func_00261DC8(int a, int b) __attribute__((register_precision(s3, 128)));
void func_00261DC8(int a, int b)
{
    int out0, out1;
    Pt16 *p0, *p1;

    p0 = func_00256F08(lpamng->ents[b].f06, &out0);
    p1 = func_00256F08(a, &out1);
    LPV->f1161A = 0x78;
    LPV->f11614 = 0;
    LPV->f11608 = func_00256FA0(0x22);
    LPV->f1160C = func_00256F58(out0, p0);
    LPV->f11610 = func_00256F58(out1, p1);
    LPV->f11618 = 2;
}

void func_00261E98(void)
{
    int i;
    S6Pt50 *p;
    float r;

    p = LPV->pts11090;
    r = LPV->f11604 / 40.0f;
    r = (lpamng->f115DC - lpamng->f115D8) * r + lpamng->f115D8;
    for (i = 0; i < 8; i++, p++) {
        if (p->f3C > 0.0f && p->h44 == LPV->f11602) {
            p->f3C = r;
            func_002599C0(i);
        }
    }
    if (++LPV->f11604 == 20) {
        func_00258780();
        lpamng->ents[LPV->f11602].f06 = LPV->u11600.h11600;
        func_00259678();
    }
    if (((S6Task *)D_006A3610)->h1E == 0) {
        p = LPV->pts11090;
        for (i = 0; i < 8; i++, p++) {
            if (p->f3C > 0.0f && p->h44 == LPV->f11602) {
                p->f3C = lpamng->f115DC;
                func_002599C0(i);
            }
        }
        lpamng->cb_a = lpamng->next_a;
        lpamng->cb_b = lpamng->next_b;
        lpamng->next_a = 0;
        lpamng->next_b = 0;
    }
}

void abmap_cheng_panel(int a0, int idx)
{
    WorkEnt *e = &lpamng->ents[idx];
    s32 *save = (s32 *)MsGetSaveMenu();

    pppCreateHeap((HHead *)D_006A3690, (HBlk *)0x1E81000, 0x7D000);
    if (((*save >> 14) & 3) != 2) {
        func_002560D0(D_006A3610, 3, e->x, e->y, 0.0f, 0.0f, 0.0f, 0.0f, 0.5f, 0.5f, 0.5f);
    } else {
        func_002560D0(D_006A3610, 5, e->x, e->y, 0.0f, 0.0f, 0.0f, 0.0f, 0.5f, 0.5f, 0.5f);
    }
    lpamng->f115D8 = func_002596D8(idx);
    lpamng->f115DC = func_00259698(a0);
    LPV->f11604 = 0;
    LPV->u11600.h11600 = a0;
    LPV->f11602 = idx;
    func_00261DC8(a0, idx);
    if (lpamng->next_b == 0) {
        lpamng->next_b = lpamng->cb_b;
        lpamng->cb_b = func_002614B8;
    }
    if (lpamng->next_a == 0) {
        lpamng->next_a = lpamng->cb_a;
        lpamng->cb_a = func_00261E98;
    }
}

void func_00262258(void)
{
    float f;

    LPV->f11554 = f = eff_sin_t[(LPV->f1164C << 7) & 0xF80];
    f += 1.0f;
    f *= 8.0f;
    LPV->f11575 = (int)f + 0x70;
    LPV->f11575 = (LPV->f11575 * LPV->f11576) >> 7;
}

void func_002622D0(void)
{
    u_long128 *src;

    LPV->f11550 = 256.0f;
    src = (u_long128 *)((char *)lpamng + (LPV->f1156C * 0x50 + 0x11090));
    LPA(u_long128, 0x114D0) = *src;
    LPV->f114D8 = ((float *)src)[2] - 32.0f;
    LPA(u_long128, 0x11510) = D_00327790[LPV->f1156C];
    LPV->f114DC = LPV->f11550 + LPV->f11550;
    func_00262258();
}

INCLUDE_ASM("build/ee_asm/game/abm/ei_260A70", func_00262360);

void func_002626D0(int a, int b)
{
    lpamng->f115D0 = 1.0f;
    lpamng->f115D4 = 0.0f;
    lpamng->f115E0 = lpamng->f115E2 = lpamng->ents3[a].h0;
    lpamng->f115E4 = b;
    lpamng->f115E8 = a;
    if (lpamng->next_a == 0) {
        lpamng->next_a = lpamng->cb_a;
        lpamng->cb_a = func_00262360;
    }
}

INCLUDE_ASM("build/ee_asm/game/abm/ei_260A70", func_00262740);

void func_00262880(void)
{
    lpamng->f115D8 = lpamng->ents3[6].f48;
    lpamng->f115D0 = 0.0f;
    lpamng->f115DC = func_002596D8(lpamng->ents3[7].h0);
    if (lpamng->next_a == 0) {
        lpamng->next_a = lpamng->cb_a;
        lpamng->cb_a = func_00262740;
    }
}

void func_002628F0(void)
{
    lpamng->f11574 = 0;
    lpamng->cb_a = func_00263DE8;
    lpamng->cb_b = func_0025C2B0;
    lpamng->f11573 = 0;
}

void func_002639B8(void);

void func_00262930(int a, int b, int c)
{
    u8 buf[16];
    WorkEnt *p;
    int idx;

    func_00258370(0xFC);
    func_002580B0(a, b, c, 3);
    lpamng->cb_a = func_002639B8;
    lpamng->cb_b = func_0025C308;
    LPV->f11650 = LPV->f11654 = 0;
    p = (WorkEnt *)func_00261130(buf, (char *)lpamng + (LPV->f1156C * 0x50 + 0x11090), func_002638B0);
    idx = p - lpamng->ents;
    if (p != 0) {
        if (idx != LPA(u16, 0x11304)) {
            /* DEBT(CAST): func_00261430 takes its argument in $f12 */
            ((void (*)(float))func_00261430)(0.5f);
        }
    }
    lpamng->f11573 = 1;
}

void func_002638C0(void);

void func_00262A40(void)
{
    u16 h0;

    h0 = lpamng->ents3[lpamng->f1156C].h0;
    lpamng->cb_a = (void (*)(void))func_002638C0;
    lpamng->cb_b = func_0025C310;
    func_00258618(h0, func_001BE7B8(lpamng->f1156C), lpamng->f1156C);
    func_00258370(0xFC);
    func_00258410(func_001BE7B8(lpamng->f1156C), 3);
    LPV->f115CC = LPV->f11650 = LPV->f11654 = 0;
    ((void (*)(int, float))func_00261430)(h0, 0.25f);
    lpamng->f11573 = 1;
}

void func_00262B28(ChrWork *w)
{
    int t;
    s16 r[4]; /* DEBT(PADDING): unused, only reproduces the 16-byte frame */
    int d;

    if (++w->f32 >= 4) {
        w->rect1[0] = w->rect2[0];
        w->rect1[1] = w->rect2[1];
        w->rect1[2] = w->rect2[2];
        w->rect1[3] = w->rect2[3];
        w->f34 = 0;
    } else {
        t = w->f32 << 14;
        d = (s16)w->rect2[0] - (s16)w->a.rect[0];
        w->rect1[0] = w->a.rect[0] + ((d * t) >> 16);
        d = (s16)w->rect2[1] - (s16)w->a.rect[1];
        w->rect1[1] = w->a.rect[1] + ((d * t) >> 16);
        d = (s16)w->rect2[2] - (s16)w->a.rect[2];
        w->rect1[2] = w->a.rect[2] + ((d * t) >> 16);
        d = (s16)w->rect2[3] - (s16)w->a.rect[3];
        w->rect1[3] = w->a.rect[3] + ((d * t) >> 16);
    }
    w->f14 = ((s16)w->rect1[2] + 15) / 16;
    w->f16 = ((s16)w->rect1[3] + 15) / 20;
}

void func_00262C40(int i, int a, int b, int c, int d) {
    ChrWork *w = D_006A391C + i;

    a += 0x20;
    c = (c << 4) + 0x20;
    d *= 0x14;
    w->f34 = func_00262B28;
    w->rect2[0] = a;
    w->rect2[1] = b;
    w->rect2[2] = c;
    w->rect2[3] = d;
    w->f32 = 0;
}

INCLUDE_ASM("build/ee_asm/game/abm/ei_260A70", func_00262C90);

void func_00262DC8(int slot)
{
    ChrWork *chr = &D_006A391C[slot];

    chr->f34 = func_00262C90;
    chr->rect2[0] = chr->rect1[0];
    chr->rect2[1] = chr->rect1[1];
    chr->rect2[2] = chr->rect1[2];
    chr->rect2[3] = chr->rect1[3];
    chr->f32 = 0;
}

void func_00262E10(int slot)
{
    ChrWork *chr = &D_006A391C[slot];

    chr->rect1[0] = chr->a.rect[0];
    chr->rect1[1] = chr->a.rect[1];
    chr->rect1[2] = chr->a.rect[2];
    chr->rect1[3] = chr->a.rect[3];
    chr->f14 = chr->f10;
    chr->f16 = chr->f12;
}

void func_00262E58(int a, V6Arg8 *b, int c, int d)
{
    if (d != 0) {
        func_0025AFA0(8);
        func_00262C40(8, 10, 0x174, 0xC, 1);
        func_00262930(lpamng->f1156C, lpamng->ents3[lpamng->f1156C].h0, b->h8);
    } else {
        func_00264210();
    }
}

void func_00262ED8(int a, int b, int sel, int ok) /* DEBT(NAME): argument meaning guessed (menu callback) */
{
    if (ok != 0) {
        if (sel == 0) {
            SndSepPlaySimple(0x80000051);
            func_00262A40();
            func_0025AFA0(7);
            if (D_006A3600 != 0) {
                func_00262C40(7, 10, 0x174, 4, 1);
            } else {
                func_00262C40(7, 10, 0x174, 2, 1);
            }
        } else if (sel == 1) {
            SndSepPlaySimple(0x80000001);
            func_00264248();
        }
    } else {
        func_002628F0();
    }
}

int func_00262F88(float *out);
INCLUDE_ASM("build/ee_asm/game/abm/ei_260A70", func_00262F88);

void func_002632D8(int cb) __attribute__((register_precision(s3, 128)));
void func_002632D8(int cb)
{
    float vec[4];
    float dist;
    S6Pt50 *pt = &LPV->pt112C0;
    WorkEnt *p;

    if (lpamng->next_a != 0) {
        return;
    }
    if (LPV->f11594 < 0.0f) {
        LPV->f11594 = 1.0f;
    }
    if (func_00262F88(vec) == 0) {
        if (((u8 *)lpamng)[0x1157D] != 0) {
            ((u8 *)lpamng)[0x1157D] = 0;
            p = (WorkEnt *)func_00261130(&dist, pt, cb);
            if (p != 0) {
                SndSepPlaySimple(0x80000001);
                ((void (*)(int, float))func_00261430)(p - lpamng->ents, 0.5f);
            }
        } else if (vec[0] != 0.0f || vec[1] != 0.0f) {
            p = (WorkEnt *)func_00260F88(pt, vec, cb);
            if (p != 0) {
                SndSepPlaySimple(0x80000001);
                ((void (*)(int, float))func_00261430)(p - lpamng->ents, 0.25f);
            }
        }
    } else {
        ((u8 *)lpamng)[0x1157D] = 1;
        pt->x += vec[0];
        pt->y += vec[1];
        if (pt->x < LPV->f115BC) {
            pt->x = LPV->f115BC;
        } else if (pt->x > LPV->f115C4) {
            pt->x = LPV->f115C4;
        }
        if (pt->y < LPV->f115C0) {
            pt->y = LPV->f115C0;
        } else if (pt->y > LPV->f115C8) {
            pt->y = LPV->f115C8;
        }
        func_00260F60();
        p = (WorkEnt *)func_00261130(&dist, pt, cb);
        if (dist <= pt->f3C) {
            float target;

            *(u16 *)((u8 *)pt + 0x44) = p - lpamng->ents;
            target = func_002596D8(*(u16 *)((u8 *)pt + 0x44));
            if (target < pt->f3C) {
                pt->f3C -= 2.0f;
                if (pt->f3C < target) {
                    pt->f3C = target;
                }
            } else if (target > pt->f3C) {
                pt->f3C += 2.0f;
                if (pt->f3C > target) {
                    pt->f3C = target;
                }
            }
        }
    }
}

void func_00264578(void);
void func_00264140(void);

void func_00263580(void)
{
    if (lpamng->next_a != 0) {
        return;
    }
    if (LPV->f11626 & 4) {
        ((void (*)(void))func_002429F0)();
        LPV->f1156E = 1;
    changed:
        LPV->f1156F = 0;
        LPV->f1156D = LPV->f1156C;
        LPV->f1156C = TkMenuGetCurrentPlayer();
        if (LPV->f1156D == LPV->f1156C) {
            LPV->f1156E = 0;
        } else {
            SndSepPlaySimple(0x80000004);
        }
        ((void (*)(int, float))func_00261430)(lpamng->ents3[LPV->f1156C].h0, 0.25f);
        func_00264578();
        func_00264140();
    } else if (LPV->f11626 & 8) {
        LPV->f1156E = 2;
        ((void (*)(void))func_00242980)();
        goto changed;
    }
    func_002622D0();
}

typedef struct {
    u8 pad00[0xC];
    u8 f0C;
    u8 pad0D;
    u8 f0E;
    u8 pad0F[5];
} EiWorkEnt2;

void func_001BE7D8(int ch, int b);
S6Pt50 *func_0025A0C8(int i);

void func_002636B8(int a0, int a1, int sel)
{
    func_002628F0();
    if (sel == 0) {
        SndSepPlaySimple(0x80000052);
        func_001BE7D8(lpamng->f1156C, LPV->f115CC);
    } else if (sel == 1) {
        EiWorkEnt2 *e = (EiWorkEnt2 *)lpamng->ents2;
        int n = lpamng->count2;
        S6Pt50 *p;

        SndSepPlaySimple(0x80000004);
        while (--n != -1) {
            if (e->f0E & 8) {
                e->f0C &= ~(1 << lpamng->f1156C);
            }
            e++;
        }
        p = &LPV->pts11090[lpamng->f115E8];
        p->h44 = lpamng->f115E0;
        func_0025A0C8(lpamng->f115E8);
        func_002599C0(lpamng->f115E8);
        lpamng->f11577 = 1;
        func_002622D0();
        ((void (*)(int, float))func_00261430)(p->h44, 0.5f);
    }
    func_002581D8(0xF0);
    func_0025AFC0(9);
    func_00262E10(7);
    LPV->f115CC = 0;
}

void func_00263840(void)
{
    ChrWork *chr;

    func_0025AFC0(7);
    func_0025AFA0(9);
    chr = func_0025B010(0xB, func_002636B8);
    chr->f18 = 0;
    chr->f24 |= 0xC;
}

void func_00263888(void)
{
    GlobalWork *w = lpamng;

    w->cb_a = func_00263840;
    w->cb_b = 0;
    w->f11573 = 0;
}

int func_002638B0(WorkEnt *p)
{
    return p->f22 & 1;
}

void func_002632D8(int);
void func_002626D0(int, int);
void func_00264210(void);
void func_00262DC8(int);

void func_002638C0(void)
{
    GlobalWork *w;
    u16 f;

    func_002632D8((int)func_002638B0);
    w = lpamng;
    if (w->f1157D != 0 || w->next_a != 0) {
        return;
    }
    *(s32 *)((u8 *)w + 0x115CC) = (w->ents[*(u16 *)((u8 *)w + 0x11304)].f24 + 3) >> 2;
    f = w->f11622;
    if (f & 0x20) {
        func_002581D8(0xF8);
        func_00263888();
        func_002626D0(lpamng->f1156C, *(u16 *)((u8 *)lpamng + 0x11304));
    } else if (f & 0x40) {
        func_002581D8(0xF0);
        SndSepPlaySimple(0x80000004);
        lpamng->f11573 = 0;
        *(s32 *)((u8 *)lpamng + 0x115CC) = 0;
        func_00264210();
        func_00262DC8(7);
    }
}

void func_002587A0(int ch, int idx, int item);

void func_002639B8(void)
{
    func_002632D8((int)func_002638B0);
    if (lpamng->f1157D != 0 || lpamng->next_a != 0 || D_006A391C[8].f34 != 0) {
        return;
    }
    if (lpamng->f11622 & 0x20) {
        ChrSub *sub = func_0025AFE0(8);
        ChrWork *chr = &D_006A391C[8];
        u32 arg = sub->arg;

        func_0025AFC0(8);
        func_00262E10(8);
        func_002628F0();
        func_002587A0(lpamng->f1156C, LPV->pt112C0.h44, (u16)arg);
        func_00264400();
        if (chr->f18 >= chr->f1E) {
            chr->f18 = chr->f1E - 1;
        }
        if (chr->f18 < 0) {
            chr->f18 = 0;
        }
        if (chr->f1A > chr->f1E - (s16)chr->f16) {
            chr->f1A = chr->f1E - chr->f16;
        }
        if (chr->f1A < 0) {
            chr->f1A = 0;
        }
        func_00258370(0xFC);
    } else if (lpamng->f11622 & 0x40) {
        func_00264248();
        func_00262DC8(8);
        func_00258370(0xFC);
        SndSepPlaySimple(0x80000004);
    }
}

void func_00263B30(ChrWork *w)
{
    w->f29++;
    if (w->f29 >= 3) {
        w->f23 = 0;
        w->f34 = 0;
        return;
    }
    w->rect1[1] = w->a.rect[1] + (w->f29 * (s16)w->a.rect[3]) / 3 + (s16)w->a.rect[3] / 6; /* DEBT(TYPE): rect read signed */
}

void func_00263B98(int slot)
{
    ChrWork *chr = &D_006A391C[slot];

    if (chr->f23 != 0 || chr->f34 != 0) {
        chr->f29 = 0;
        chr->f34 = func_00263B30;
    }
}

void func_00263BD8(ChrWork *w)
{
    w->f23 = 1;
    w->f29++;
    if (w->f29 >= 3) {
        w->f34 = 0;
        w->rect1[1] = w->a.rect[1];
        return;
    }
    w->rect1[1] = w->a.rect[1] + ((3 - w->f29) * (s16)w->a.rect[3]) / 3 + (s16)w->a.rect[3] / 6;
}

void func_00263C58(int slot)
{
    ChrWork *chr = &D_006A391C[slot];

    if (chr->f23 == 0 || chr->f34 != 0) {
        chr->f29 = 0;
        chr->f34 = func_00263BD8;
    }
}

void func_00263C98(void) {
    func_00261288();
    if (lpamng->f115D0 >= 1.0f) {
        func_00264210();
    }
}

void func_00263CE8(int id, float f)
{
    if (id == lpamng->ents3[7].h0) {
        func_00264210();
        return;
    }
    func_002613B8();
    if (lpamng->next_a == 0) {
        lpamng->next_a = lpamng->cb_a;
        lpamng->cb_a = func_00263C98;
    }
}

void func_00263D68(ChrWork *chr, ChrSub *sub, int cancel, int ok) /* DEBT(NAME): argument meaning guessed */
{
    func_0025AFC0(10);
    if (ok == 0 || cancel != 0) {
        SndSepPlaySimple(0x80000004);
        func_00263C58(6);
        return;
    }
    func_00258780();
    TOMenuTermAbilityMap2();
    D_00327910 = 0;
}

void func_00263DE8(void)
{
    u16 pad;

    func_002632D8(0);
    if (LPA(u8, 0x1157D) != 0 || lpamng->next_a != 0) {
        return;
    }
    func_00263580();
    if (lpamng->next_a != 0) {
        return;
    }
    if (LPA(u8, 0x11574) == 0) {
        LPA(u8, 0x11574) = 1;
        func_00263C58(6);
    }
    pad = LPV->f11622;
    if (pad & 0x20) {
        SndSepPlaySimple(0x80000001);
        LPV->f1161A = 0;
        func_00263B98(6);
        func_00263B98(1);
        func_00263B98(2);
        func_00263B98(3);
        func_00263B98(4);
        func_00263B98(5);
        LPA(u8, 0x11578) = 0;
        func_00263CE8(LPV->pts11090[LPV->f1156C].h44, 0.25f);
        return;
    }
    if (pad & 0x40) {
        u8 *w;
        SndSepPlaySimple(0x80000001);
        func_00263B98(6);
        func_00263B98(1);
        func_00263B98(2);
        func_00263B98(3);
        func_00263B98(4);
        func_00263B98(5);
        LPA(u8, 0x11578) = 0;
        func_0025AFA0(10);
        w = (u8 *)func_0025B010(11, func_00263D68);
        *(s16 *)(w + 0x18) = 0;
        w[0x24] |= 0xC;
        return;
    }
    if (*(s32 *)((u8 *)D_006A391C + 0x13B4) != 0 ||
        *(s32 *)((u8 *)D_006A391C + 0x374) != 0 ||
        *(s32 *)((u8 *)D_006A391C + 0x9F4) != 0 ||
        *(s32 *)((u8 *)D_006A391C + 0x6B4) != 0 ||
        *(s32 *)((u8 *)D_006A391C + 0xD34) != 0 ||
        *(s32 *)((u8 *)D_006A391C + 0x1074) != 0) {
        return;
    }
    if (!(pad & 0x10)) {
        return;
    }
    SndSepPlaySimple(0x80000001);
    LPA(u8, 0x11578)++;
    if (LPA(u8, 0x11578) >= 6) {
        LPA(u8, 0x11578) = 0;
    }
    switch (LPA(u8, 0x11578)) {
    case 0:
        func_00263B98(5);
        func_00263C58(6);
        break;
    case 1:
        func_0025AFC0(6);
        func_00263C58(1);
        break;
    case 2:
        func_002644C0(3);
        func_0025AFC0(1);
        func_00263C58(3);
        break;
    case 3:
        func_002644C0(2);
        func_0025AFC0(3);
        func_00263C58(2);
        break;
    case 4:
        func_002644C0(4);
        func_0025AFC0(2);
        func_00263C58(4);
        break;
    case 5:
        func_002644C0(5);
        func_0025AFC0(4);
        func_00263C58(5);
        break;
    }
}

void func_00264108(void)
{
    if (lpamng->cb_a != 0) {
        lpamng->cb_a();
    }
}

void func_00264140(void) __attribute__((register_precision(s3, 128)));
void func_00264140(void)
{
    int i;
    ChrWork *w = &D_006A391C[7];
    ChrSub *sub = w->sub;

    for (i = 0; i < w->f1E; i++, sub++) {
        sub->off = 0;
        switch (i) {
        case 0:
            if (func_001BE7B8(lpamng->f1156C) == 0) {
                sub->off = 1;
            }
            break;
        case 1:
            func_0024CB58(3);
            if (MsGetSaveSP() == 0) {
                sub->off = 1;
            }
            break;
        }
    }
}

void func_00264210(void)
{
    ChrWork *chr;

    func_00264140();
    chr = func_0025B010(7, func_00262ED8);
    chr->f24 |= 8;
}

#ifndef ATTR_REG_PREC_S3
#define ATTR_REG_PREC_S3 __attribute__((register_precision(s3, 128)))
#endif
extern s32 _m2c_func_00264248_D_006A391C __asm__("D_006A391C");
s32 _m2c_func_00264248_func_00257FB0(u8, u16, u16) __asm__("func_00257FB0");
void _m2c_func_00264248_func_00262E58() __asm__("func_00262E58");
/* DEBT(CAST) */ /* DEBT(FAKE) */
void ATTR_REG_PREC_S3 func_00264248(void) {
    register s32 _cond __asm__("$2");
    ChrWork *temp_18;
    register s32 var_17 __asm__("$17");
    u16 temp_19;
    void *var_16;

    var_17 = 0;
    temp_18 = _m2c_func_00264248_D_006A391C + 0x1A00;
    var_16 = _m2c_func_00264248_D_006A391C + 0x1A40;
    temp_19 = lpamng->ents3[lpamng->f1156C].h0;
    if (temp_18->f1E > 0) {
        do {
            if (_m2c_func_00264248_func_00257FB0(lpamng->f1156C, temp_19, (*(u16 *)((u8 *)(var_16) + (8)))) != 0) {
                (*(s8 *)((u8 *)(var_16) + (4))) = 0;
            } else {
                (*(s8 *)((u8 *)(var_16) + (4))) = 1;
            }
            var_17 += 1;
            var_16 += 0xC;
        } while ((_cond = (var_17 < temp_18->f1E)) != 0);
    }
    func_0025B010(8, _m2c_func_00264248_func_00262E58);
}

#ifndef ATTR_REG_PREC_S3
#define ATTR_REG_PREC_S3 __attribute__((register_precision(s3, 128)))
#endif
/* DEBT(FAKE) */
void ATTR_REG_PREC_S3 func_00264330(s32 a, s32 b) {
    register u8 *saved_reg_s1 __asm__("$17");
    u8 sp[0x10];
    s32 temp_2;
    s32 temp_2_2;
    s32 var_17;
    register s32 _v0 __asm__("$2");
    s32 var_18;

    var_17 = (s32)saved_reg_s1;
    var_18 = 0;
    func_0024CB58(b);
    temp_2 = MsGetSaveSP();
    if (temp_2 > 0) {
        do {
            temp_2_2 = TOAmapGetItemType(var_18);
            if ((func_001BFE30(temp_2_2) > 0) && (MsGetRomItem(temp_2_2, (s32 *)sp)->b5D != 0xFF)) {
                _v0 = temp_2_2 & 0xFFFF;
                __asm__ volatile("" : "+r"(var_17), "+r"(_v0));
                var_17 &= 0xFFFF0000;
                __asm__ volatile("" : "+r"(var_17), "+r"(_v0));
                var_17 |= _v0;
                func_0025B050(a, 0, var_17);
            }
            var_18 += 1;
        } while (var_18 < temp_2);
    }
}

void func_00264400(void)
{
    D_006A391C[8].f1E = 0;
    func_00264330(8, 3);
}

#ifndef ATTR_REG_PREC_S3
#define ATTR_REG_PREC_S3 __attribute__((register_precision(s3, 128)))
#endif
/* DEBT(CAST) */
void ATTR_REG_PREC_S3 func_00264418(s32 arg0, s32 arg1) {
    u8 sp[0x10];
    OfsTbl *temp_2_2;
    s32 temp_2;
    s32 var_17;
    s32 var_4;
    u16 temp_5;

    var_17 = 0;
    temp_2 = func_001DC0D8();
    if (temp_2 > 0) {
        __asm__ volatile("" : "+r"(var_17));
        var_4 = var_17;
        do {
            temp_2_2 = MsMenuStatusNum(var_4, 0);
            if ((*(u8 *)((u8 *)(temp_2_2) + (0))) == arg1) {
                MsGetRomPlyCommand((s32) temp_2_2->a[0].y, sp);
                temp_5 = temp_2_2->a[0].y;
                func_0025B050(arg0, temp_5, temp_5 - 0x3000);
            }
            var_17 += 1;
            var_4 = var_17;
        } while (var_17 < temp_2);
    }
}

void func_002644C0(int slot)
{
    ChrWork *w = &D_006A391C[slot];
    ChrSub *e = w->sub;
    PartySlot *p = MsGetSavePlayerPtr(lpamng->f1156C);
    int i;

    for (i = 0; i < w->f1E; i++, e++) {
        if ((p->h3E[e->arg >> 4] >> (e->arg & 0xF)) & 1) {
            e->off = 0;
        } else {
            e->off = 1;
        }
    }
}

void func_00264578(void)
{
    func_002644C0(3);
    func_002644C0(2);
    func_002644C0(4);
    func_002644C0(5);
}

void func_002645A8(int a, EvtObj *p, int c, int d, int e)
{
    d += 0xE;
    if (p->b4 != 0) {
        func_00257490(p->f0, d, e, 1);
    } else {
        func_00257108(p->f0, d);
    }
}

void func_002645D8(int a, int *b) /* DEBT(TYPE) */
{
    func_00257288(func_00256FD8(b[2]));
}

void _m2c_func_002645F8_func_00257810(s32, s32, s32, s32) __asm__("func_00257810");
void func_002645F8(ChrWork *arg0, EvtObj *arg1, s32 arg2, s32 arg3, s32 arg4) {
    s32 temp_20;
    u16 temp_17;

    temp_17 = arg1->h8;
    temp_20 = func_001BFE30((s32) temp_17);
    if (arg1->b4 != 0) {
        func_002576B8((s32) temp_17, arg3, arg4, 1);
        _m2c_func_002645F8_func_00257810(temp_20, (arg3 + (s16)arg0->rect1[2]) - 0x11, arg4, 1);
        return;
    }
    func_002576B8((s32) temp_17, arg3, arg4, 0);
    _m2c_func_002645F8_func_00257810(temp_20, (arg3 + (s16)arg0->rect1[2]) - 0x11, arg4, 0);
}

void func_002646E0(int a, EvtObj *p, int c, int d, int e)
{
    if (p->b4 != 0) {
        func_00257490(p->f0, d, e, 1);
    } else {
        func_00257108(p->f0, d);
    }
}

void func_00264708(int a, EvtObj *p)
{
    int arg;
    Pt16 *tbl = func_00257E18(p->h8, &arg);

    if (tbl != 0) {
        func_00257288(func_00256F58(arg, tbl));
    }
}

void func_00264748(int a, EvtObj *p, int c, int d, int e)
{
    func_002571B8(p->f0, d + 4, e - 4, 0, 0x80, 0x80, 0x80, lpamng->f11569);
}

#ifndef ATTR_REG_PREC_S3
#define ATTR_REG_PREC_S3 __attribute__((register_precision(s3, 128)))
#endif
void _m2c_func_00264780_func_00257810(s32, s32, s32, s32) __asm__("func_00257810");
/* DEBT(FAKE) */
void ATTR_REG_PREC_S3 func_00264780(s32 arg0, ChrSub *arg1, s32 arg2, s32 arg3, s32 arg4) {
    register u8 *saved_reg_s2 __asm__("$18");
    register PartySlot *temp_17 __asm__("$17");
    register s32 temp_19 __asm__("$19");
    register s32 var_18 __asm__("$18");
    u32 temp_3;

    var_18 = saved_reg_s2;
    temp_19 = arg4 - 4;
    temp_17 = MsGetSavePlayerPtr((s32) lpamng->f1156C);
    func_00257108(arg1->id, arg3, temp_19);
    temp_3 = arg1->arg;
    switch (temp_3) {
    case 0:
        var_18 = temp_17->v24;
        break;
    case 1:
        var_18 = temp_17->v28;
        break;
    case 2:
        var_18 = (s32) temp_17->pad2F[0];
        break;
    case 3:
        var_18 = (s32) temp_17->pad32[1];
        break;
    case 4:
        var_18 = (s32) temp_17->pad2F[1];
        break;
    case 5:
        var_18 = (s32) temp_17->pad32[2];
        break;
    case 6:
        var_18 = (s32) temp_17->b31;
        break;
    case 7:
        var_18 = (s32) temp_17->pad32[3];
        break;
    case 8:
        var_18 = (s32) temp_17->pad32[0];
        break;
    case 9:
        var_18 = (s32) temp_17->pad32[4];
        break;
    }
    if ((FFXGetLang() == 0) && (func_001BD360() == 0)) {
        _m2c_func_00264780_func_00257810(var_18, arg3 + 0x80, temp_19, 0);
        return;
    }
    _m2c_func_00264780_func_00257810(var_18, arg3 + 0xA0, temp_19, 0);
}

void func_002648C0(int a, EvtObj *p, int c, int d, int e)
{
    if (p->b4 == 0) {
        func_00257720(p->f0, d - 0x1C, e - 4, 0);
    }
}

void func_002648E8(int a, EvtObj *p, int c, int d, int e)
{
    if (p->b4 == 0) {
        d -= 0x1C;
        if ((c & 3) == 3) {
            d -= 0x14;
            func_00257720(p->f0, d, e - 4, 0);
        } else {
            func_00257720(p->f0, d, e - 4, 0);
        }
    }
}

void func_00264938(int a, EvtObj *p, int c, int d, int e)
{
    if (p->b4 == 0) {
        d -= 0x1C;
        if ((c & 3) >= 2) {
            d += 0x10;
            func_00257720(p->f0, d, e - 4, 0);
        } else {
            func_00257720(p->f0, d, e - 4, 0);
        }
    }
}

void func_002DD610(void *a, float f0, float f1, float f2, float f3, float f4, float f5, float f6, float f7, float f8);

void func_00264988(void)
{
    func_0025AEB0((ChrWork *)0x1E6A998);
    lpamng = (GlobalWork *)0x1E6D0A0;
    func_00256408((void *)0x1E6D0A0, 0, 0x4BD8);
    func_002DD610((char *)lpamng + 0x11390, 512.0f, 1.0f, 1.0833334f, 2048.0f, 2048.0f, 1.0f, 16777215.0f, 1.0f, 65536.0f);
    func_002DD610((char *)lpamng + 0x11450, 512.0f, 1.0f, 1.0f, 0.0f, 0.0f, 1.0f, 16777215.0f, 1.0f, 65536.0f);
    func_002DD128((char *)lpamng + 0x11350);
    LPV->f1131C = 1.0f;
    LPA(u_long128, 0x11320) = LPA(u_long128, 0x11310);
    LPV->f11340 = LPV->f11344 = LPV->f11348 = LPV->f1134C = 1.0f;
    func_002628F0();
    LPV->f11576 = 0x80;
    lpamng->f1156C = func_0024ACF8();
    LPV->f11624 = 0xFFFF;
    lpamng->f1156A = lpamng->f1156B = 1;
}

INCLUDE_ASM("build/ee_asm/game/abm/ei_260A70", func_00264B20);

void func_002653D8(void) {
}

INCLUDE_ASM("build/ee_asm/game/abm/ei_260A70", eiAbmCalc);

int func_002659F8(void) /* DEBT(TYPE): funcs.h says int; nothing is returned */
{
    T6_GsSrc *src;

    if (lpamng->f1156A == 0) {
        func_00293570();
        op_loop_ffx_after();
        src = func_00245470(&D_006A36BC);
        D_006A36C0.a = src->a;
        D_006A36C0.b = src->b;
        /* DEBT(TYPE): funcs.h types func_002B21E0 with one argument; it forwards two to func_002B1F90 */
        ((void (*)(void *, int))func_002B21E0)(&D_006A36C0, D_006A36BC & 1);
        op_gs1_transfer();
        func_002D0408();
        func_002D0698(0xFFFFFFFF);
        func_002B2730(0);
        func_002B2FF0(0x01000000, 0x88, 0);
        func_00260980();
        func_002B2810();
        func_00293740();
        lpamng->f1156B = 0;
    }
}

void func_00265B50(void) {
}

extern u16 D_0036E728[];
extern u16 D_0036E738[];
extern u16 D_0036E748[];
extern u16 *D_0036E798[];
extern u16 *D_0036E7F8[];
extern u16 *D_0036E858[];

typedef struct {
    u8 a;
    u8 b;
} EiAbmCell;

typedef struct {
    EiAbmCell cells[0x780];
    u16 out[7];
} EiAbmSave;

void func_00265B58(EiAbmSave *dst)
{
    u8 buf[0x500];
    u16 *hdr = (u16 *)buf;
    s32 *save = (s32 *)MsGetSaveMenu();
    int i;
    int mode = (*save >> 14) & 3;

    D_00327910 = 0;
    switch (mode) {
    case 0:
        func_0025A158(9, buf);
        break;
    case 1:
        func_0025A158(10, buf);
        break;
    default:
        func_0025A158(11, buf);
        break;
    }
    func_002EF0D0(dst, 0, 0x1320);
    if (*hdr++ == 0x31) {
        int n = *hdr;
        u8 *src = (u8 *)hdr + 6;
        int j;
        for (j = 0; j < n; j++) {
            dst->cells[j].a = *src++;
        }
    }
    for (i = 0; i < 7; i++) {
        u16 *p;
        switch ((*save >> 14) & 3) {
        case 0:
            p = D_0036E798[i];
            break;
        case 1:
            p = D_0036E7F8[i];
            break;
        default:
            p = D_0036E858[i];
            break;
        }
        while (*p != 0xFFFF) {
            dst->cells[*p].b |= 1 << i;
            p++;
        }
    }
    {
        u16 *out = (u16 *)((u8 *)dst + 0xF00);
        for (i = 0; i < 7; i++) {
            switch ((*save >> 14) & 3) {
            case 0:
                out[i] = D_0036E728[i];
                break;
            case 1:
                out[i] = D_0036E738[i];
                break;
            default:
                out[i] = D_0036E748[i];
                break;
            }
        }
    }
    func_00258B48();
}

void eiAbmSetLang(void)
{
    if (func_001BD360() == 0) {
        T6_VT->f10(0xD);
    } else {
        T6_VT->f10(7);
    }
    T6_VT->f00(0x12, D_006A38F4, 0, 0);
    T6_VT->f00(0x11, D_006A38F0, 0, 0);
    T6_VT->f08(0);
    func_002F8660(0);
}

int _m2c_func_00265E00_func_0011D678(int size) __asm__("func_0011D678");
void func_00265E00(void) {
    s32 temp_17;
    s32 temp_17_2;
    s32 temp_18;
    s32 temp_19;
    s32 temp_2;

    D_0078E498.f10(0xD);
    temp_19 = D_0078E498.f14(0x12);
    temp_17 = D_0078E498.f14(0x11);
    D_0078E498.f10(7);
    temp_18 = D_0078E498.f14(0x12);
    temp_2 = D_0078E498.f14(0x11);
    temp_17_2 = (temp_17 < temp_2) ? temp_2 : temp_17;
    D_006A38F4 = _m2c_func_00265E00_func_0011D678((temp_19 >= temp_18) ? temp_19 : temp_18);
    D_006A38F0 = _m2c_func_00265E00_func_0011D678(temp_17_2);
    eiAbmSetLang();
}

int func_00265ED0(void)
{
    return D_00327910;
}

int func_00265EE0(void)
{
    return 2;
}

void func_00265EE8(void)
{
    func_00258780();
    TOMenuTermAbilityMap2();
    D_00327910 = 0;
}

void *func_00265F18(void) {
    return D_00573A90;
}

int func_00265F28(void)
{
    return 0x8B;
}

float func_00265F30(int i) {
    return D_0036E688[i];
}

u8 *func_00265F48(int i)
{
    return D_0036E698[i];
}

float func_00265F60(int i) {
    return D_0036E718[i];
}
