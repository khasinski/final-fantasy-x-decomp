/* tu_237 0x20ec90-0x210340: medium; ~Tk (config/tu_map.tsv) */
#include "common.h"
#include "ffx/q5.h"
#include "ffx/w6.h"
#include "ffx/r4.h"
#include "ffx/t4.h"
#include "ffx/u3.h"
#include "ffx/g3.h"

TblEntry *func_0020EC90(int a)
{
    return D_00690268[a];
}

void TkMenuSetSceneDataAdrs(int i, void *e)
{
    D_00690268[i] = e;
}

TblEntry *func_0020ECC0(int a, int idx)
{
    TblEntry *base;

    if (idx != 0) {
        base = func_0020EC90(a);
        if (base != 0) {
            return TBL_ENTRY(base, idx);
        }
    }
    return 0;
}

TblEntry *func_0020ECF8(int a, int idx, int start)
{
    TblEntry *e = func_0020ECC0(a, idx);
    R4AnimGrp *grp;
    R4Anim *an;
    int n;

    if (e != 0) {
        e->flags &= 0x3FFFFFFF;
        grp = (R4AnimGrp *)TBL_ENTRY(func_0020EC90(a), e->flags & 0x3FFFFFFF); /* DEBT(CAST): group reached by byte offset */
        for (n = grp->count, an = grp->ent; n > 0; n--, an++) {
            if (!start) {
                an->w0 &= 0x3FFFFFFF;
            } else {
                an->w0 |= 0x80000000;
            }
            an->h8 = 0;
            an->hA = 0;
            an->hC = -1;
            an->h4 = 0;
            an->hE = 0;
            an->h10 = 0;
        }
    }
    return e;
}

void func_0020EDC8(int a, int idx)
{
    TblEntry *e = func_0020ECF8(a, idx, 1);

    if (e != 0) {
        e->flags |= 0xC0000000;
    }
}

void func_0020EE00(int a, int idx)
{
    TblEntry *e = func_0020ECF8(a, idx, 0);

    if (e != 0) {
        e->flags &= 0x3FFFFFFF;
    }
}

TblEntry *func_0020EE38(int a, int idx)
{
    TblEntry *e = func_0020ECC0(a, idx);

    if (e && (e->flags & 0x80000000)) {
        return e;
    }
    return 0;
}

TblEntry *TkMenuIsTermScene(int a, int idx)
{
    TblEntry *e = func_0020ECC0(a, idx);

    if (e && !(e->flags & 0x40000000)) {
        return e;
    }
    return 0;
}

void func_0020EEB8(u16 flags, UiPrim *a, UiPrim *b, float t)
{
    int kind;
    u32 col0;
    u32 col1;
    int x;
    int y;
    UiPrim s0;
    UiPrim s1;
    UiPrim s2;
    UiPrim s3;
    UiPrim s4;

    kind = flags;
    kind &= UI_PRIM_KIND;
    switch (kind) {
    case 0:
    case 1:
    case 2:
    case 3:
    case 8:
    case 9:
        return;
    }
    if (a == b) {
        col0 = a->col0;
        col1 = a->col1;
    } else {
        u32 a0 = a->col0;
        u32 b0 = b->col0;
        u32 a1, b1;
        int r0 = a0 & 0xFF;
        int g0 = (a0 >> 8) & 0xFF;
        int bl0 = (a0 >> 16) & 0xFF;
        int al0 = a0 >> 24;
        int br0 = b0 & 0xFF;
        int bg0 = (b0 >> 8) & 0xFF;
        int bbl0 = (b0 >> 16) & 0xFF;
        int bal0 = b0 >> 24;

        if (br0 != r0) {
            r0 = (int)(br0 * (1.0f - t) + r0 * t);
        }
        if (bg0 != g0) {
            g0 = (int)(bg0 * (1.0f - t) + g0 * t);
        }
        if (bbl0 != bl0) {
            bl0 = (int)(bbl0 * (1.0f - t) + bl0 * t);
        }
        if (bal0 != al0) {
            al0 = (int)(bal0 * (1.0f - t) + al0 * t);
        }
        col0 = r0 | (g0 << 8) | (bl0 << 16) | (al0 << 24);
        a1 = a->col1;
        b1 = b->col1;
        r0 = a1 & 0xFF;
        g0 = (a1 >> 8) & 0xFF;
        bl0 = (a1 >> 16) & 0xFF;
        al0 = a1 >> 24;
        br0 = b1 & 0xFF;
        bg0 = (b1 >> 8) & 0xFF;
        bbl0 = (b1 >> 16) & 0xFF;
        bal0 = b1 >> 24;
        if (br0 != r0) {
            r0 = (int)(br0 * (1.0f - t) + r0 * t);
        }
        if (bg0 != g0) {
            g0 = (int)(bg0 * (1.0f - t) + g0 * t);
        }
        if (bbl0 != bl0) {
            bl0 = (int)(bbl0 * (1.0f - t) + bl0 * t);
        }
        if (bal0 != al0) {
            al0 = (int)(bal0 * (1.0f - t) + al0 * t);
        }
        col1 = r0 | (g0 << 8) | (bl0 << 16) | (al0 << 24);
    }
    x = UI_LERP(a->x, b->x, t);
    y = UI_LERP(a->y, b->y, t);
    if (flags & UI_PRIM_SCREEN) {
        x += D_00690288;
        y += D_0069028C;
    }
    switch (kind) {
    case 4: {
        int p10 = UI_LERP(a->p10, b->p10, t);
        int p12 = UI_LERP(a->p12, b->p12, t);

        s0.col0 = col0;
        s0.col1 = col1;
        s0.x = x;
        s0.y = y;
        s0.p10 = p10;
        s0.p12 = p12;
        func_001FD0A0(&s0);
        break;
    }
    case 5: {
        int p10 = UI_LERP(a->p10, b->p10, t);
        int p12 = UI_LERP(a->p12, b->p12, t);

        if (flags & UI_PRIM_SCREEN) {
            p10 += D_00690288;
            p12 += D_0069028C;
        }
        s1.col0 = col0;
        s1.col1 = col1;
        s1.x = x;
        s1.y = y;
        s1.p10 = p10;
        s1.p12 = p12;
        func_001FCF88(&s1);
        break;
    }
    case 6: {
        int b14 = b->p14.u;
        int a14 = a->p14.u;
        int p14;
        int p10;
        int p12;

        if (b14 == a14) {
            p14 = a14;
        } else {
            p14 = (int)(b14 * (1.0f - t) + a14 * t);
        }
        p10 = UI_LERP(a->p10, b->p10, t);
        p12 = UI_LERP(a->p12, b->p12, t);

        s2.col0 = col0;
        s2.col1 = col1;
        s2.x = x;
        s2.y = y;
        s2.p10 = p10;
        s2.p12 = p12;
        s2.p14.s = p14;
        func_001FD260(&s2);
        break;
    }
    case 7: {
        int p10 = UI_LERP(a->p10, b->p10, t);
        int p12 = UI_LERP(a->p12, b->p12, t);
        int p14 = UI_LERP(a->p14.s, b->p14.s, t);

        s3.col0 = col0;
        s3.col1 = col1;
        s3.x = x;
        s3.y = y;
        s3.p10 = p10;
        s3.p12 = p12;
        s3.p14.s = p14;
        TOMakePktSeqPrimMes((struct R4Msg *)&s3);
        break;
    }
    case 10: {
        int p14 = UI_LERP(a->p14.s, b->p14.s, t);
        int p16 = UI_LERP(a->p16, b->p16, t);
        int p18 = UI_LERP(a->p18, b->p18, t);
        int p10 = UI_LERP(a->p10, b->p10, t);
        int p12 = UI_LERP(a->p12, b->p12, t);
        int p1C = UI_LERP(a->p1C, b->p1C, t);
        int p1E = UI_LERP(a->p1E, b->p1E, t);

        s4.col0 = col0;
        s4.col1 = col1;
        s4.x = x;
        s4.y = y;
        s4.p10 = p10;
        s4.p12 = p12;
        s4.p14.s = p14;
        s4.p16 = p16;
        s4.p18 = p18;
        s4.p1C = p1C;
        s4.p1E = p1E;
        TOMakePktSeqPrimFunc((struct R4Msg *)&s4);
        break;
    }
    }
}

float func_0020F750(u16 mode, int elapsed, int duration)
{
    float t = (float)elapsed / (float)duration;

    if (duration) {
        switch (mode & 0x7000) {
        case 0x1000:
            break;
        case 0x2000:
            t = 1.0f - t;
            t = t * t;
            t = 1.0f - t;
            break;
        case 0x3000:
            t = t * t;
            break;
        case 0x4000:
            t = 1.0f - t;
            t *= 3.14159265358979323846f;
            if (t > 3.14159265358979323846f) {
                t = 3.14159265358979323846f;
            }
            if (t < 0.0f) {
                t = 0.0f;
            }
            t = func_002E8648(t) + 1.0f;
            t *= 0.5f;
            break;
        }
    } else {
        t = 1.0f;
    }
    return t;
}

void func_0020F850(u16 *code, R4Anim *an, int t, int dur)
{
    UiPrim *cur = (UiPrim *)&code[an->h8]; /* DEBT(CAST): primitives are stored inline in the command stream */
    UiPrim *prev = (UiPrim *)&code[an->hA];
    u16 fc = cur->flags;
    u16 fp = prev->flags;
    float f;

    if (an->h6 < 0) {
        func_0020EEB8(fp, prev, prev, 0.0f);
        return;
    }
    if (t == 0) {
        func_0020EEB8(fc, cur, cur, 0.0f);
        return;
    }
    if (t == dur) {
        func_0020EEB8(fp, prev, prev, 0.0f);
        return;
    }
    f = func_0020F750(fp, t, dur);
    if ((fc & UI_PRIM_KIND) == (fp & UI_PRIM_KIND)) {
        func_0020EEB8(fc, prev, cur, f);
        return;
    }
    if (f >= 0.5f) {
        func_0020EEB8(fp, prev, prev, 0.0f);
        return;
    }
    func_0020EEB8(fc, cur, cur, 0.0f);
}

u16 *func_0020F9D8(u16 *pc, R4Anim *a, int op, int flag)
{
    u8 *st = &D_00324978[op];
    u16 *r = pc + *st;

    if (flag) {
        a->hA = a->h8;
    }
    a->h8 += *st;
    return r;
}

u16 *func_0020FA18(u16 *pc, R4Anim *a, u8 *root, int pos, s32 *ofs, int flag)
{
    if (flag) {
        a->hA = a->h8;
    }
    a->h8 = pos;
    return (u16 *)(root + ofs[a->w0]) + pos;
}

int func_0020FA50(u8 *root, R4AnimGrp *grp, R4Anim *an, s32 *ofs)
{
    int ret = 1;
    int loop = 1;
    u16 *code = (u16 *)(root + ofs[an->w0]);
    u16 *pc = code + an->h8;

    if (an->h4 != 0) {
        an->h4--;
        func_0020F850(code, an, an->h4, an->h6);
    } else {
        do {
            u16 op = *pc;
            int kind = op & 0x7FF;

            switch (kind) {
            case 2:
                an->h6 = -1;
                an->h4 = 0;
                if (an->hC < 0) {
                    u32 n = grp->count;
                    R4Anim *e = grp->ent;
                    u16 id = pc[1];
                    u32 i;

                    for (i = 0; i < n; i++, e++) {
                        if (id == (e->w0 & 0x3FFFFFFF)) {
                            an->hC = i;
                            break;
                        }
                    }
                }
                if (an->hC >= 0 && *(s32 *)((u8 *)grp + an->hC * (int)sizeof(R4Anim) + 4) < 0) {
                    loop = 0;
                } else {
                    an->h6 = 0;
                    an->hC = -1;
                    pc = func_0020F9D8(pc, an, kind, 0);
                }
                break;
            case 3: {
                u16 dur = pc[1];

                an->h6 = -1;
                an->h4 = dur;
                if (dur != 0) {
                    an->h4 = dur - 1;
                    loop = 0;
                }
                pc = func_0020F9D8(pc, an, kind, 1);
                break;
            }
            case 4:
            case 5:
            case 6:
            case 7:
            case 10: {
                u16 dur = pc[1];

                pc = func_0020F9D8(pc, an, kind, 1);
                an->h4 = dur;
                an->h6 = dur;
                if (dur != 0) {
                    an->h4 = dur - 1;
                    loop = 0;
                }
                break;
            }
            case 8:
                if (op & 0x800) {
                    an->h10 = 1;
                } else if (an->h10 <= 0) {
                    an->h10 = pc[1];
                } else {
                    an->h10--;
                }
                if (an->h10 > 0) {
                    pc = func_0020FA18(pc, an, root, an->hE, ofs, 0);
                } else {
                    pc = func_0020F9D8(pc, an, kind, 0);
                    an->h10 = 0;
                }
                break;
            case 9:
                pc = func_0020F9D8(pc, an, kind, 0);
                an->hE = an->h8;
                break;
            case 1:
                pc = func_0020F9D8(pc, an, kind, 1);
                break;
            case 0:
                an->w0 &= 0x3FFFFFFF;
                an->h6 = -1;
                an->h4 = 0;
                ret = 0;
                loop = 0;
                break;
            }
        } while (loop != 0);
        func_0020F850(code, an, an->h4, an->h6);
    }
    return ret;
}

int TkMenuExecScene(int a, int idx)
{
    TblEntry *e = func_0020EE38(a, idx);
    R4AnimRoot *root;
    s32 *ofs;
    R4AnimGrp *grp;
    R4Anim *an;
    int n;
    int res;

    if (e == 0) {
        return 0;
    }
    res = 0;
    D_00690288 = e->val0;
    D_0069028C = e->val1;
    root = (R4AnimRoot *)func_0020EC90(a); /* DEBT(CAST): the bank is returned as a TblEntry pointer */
    ofs = (s32 *)((u8 *)root + root->ofs);
    grp = (R4AnimGrp *)((u8 *)root + (e->flags & 0x3FFFFFFF));
    for (n = grp->count, an = grp->ent; n > 0; n--, an++) {
        res |= func_0020FA50((u8 *)root, grp, an, ofs);
    }
    if (res == 0) {
        e->flags &= 0xBFFFFFFF;
    }
    return res;
}

void func_0020FE48(int a, int g)
{
    R4AnimRoot *root;
    s32 *p;
    s32 n;

    g = g < 0 ? 0 : (g < 16 ? g : 15);
    root = (R4AnimRoot *)func_0020EC90(a); /* DEBT(CAST) */
    if (root == 0 || root->group[g] == 0) {
        return;
    }
    p = (s32 *)((u8 *)root + root->group[g]);
    for (n = *p++; n != 0; n--) {
        TkMenuExecScene(a, *p++);
    }
}

void TOMenuExecLayerHandle(int a, int g, int idx)
{
    R4AnimRoot *root;
    s32 *p;
    s32 n;

    g = g < 0 ? 0 : (g < 16 ? g : 15);
    root = (R4AnimRoot *)func_0020EC90(a); /* DEBT(CAST) */
    if (root == 0 || root->group[g] == 0) {
        return;
    }
    p = (s32 *)((u8 *)root + root->group[g]);
    for (n = *p++; n != 0; n--) {
        if (idx == *p++) {
            TkMenuExecScene(a, idx);
        }
    }
}

int func_0020FF90(int a, int idx)
{
    TblEntry *base;

    if (idx == 0) {
        return 0;
    }
    base = func_0020EC90(a);
    if (base == 0) {
        return 0;
    }
    return TBL_ENTRY(base, idx)->val0;
}

int func_0020FFD0(int a, int idx)
{
    TblEntry *base;

    if (idx == 0) {
        return 0;
    }
    base = func_0020EC90(a);
    if (base == 0) {
        return 0;
    }
    return TBL_ENTRY(base, idx)->val1;
}

void func_00210010(int a, int idx, int v0, int v1)
{
    TblEntry *base;
    TblEntry *e;

    if (idx != 0) {
        base = func_0020EC90(a);
        if (base != 0) {
                    e = TBL_ENTRY(base, idx);
            e->val0 = v0;
            e->val1 = v1;
        }
    }
}

typedef struct {
    /* 0x00 */ s32 param_hash[16];
    /* 0x40 */ s32 scene_hash[16];
} TkSceneBank;

int TkMenuGetSceneHandle(int a, const char *name)
{
    TkSceneBank *root;
    const u8 *c;
    u8 ch;
    u32 h;
    s32 *p;
    int n;

    a = a < 0 ? 0 : (a < 8 ? a : 7);
    root = (TkSceneBank *)func_0020EC90(a);
    if (root == 0) {
        return 0;
    }
    h = 0;
    c = (const u8 *)name;
    while ((ch = *c++) != 0) {
        h ^= ch;
    }
    p = (s32 *)root->scene_hash[h & 0xF];
    if (p != 0) {
        p = (s32 *)((u8 *)p + (u32)root);
        for (n = *p++; n != 0; n--, p += 3) {
            if (func_002F05E8((u8 *)root + *p, name) == 0) {
                return (u8 *)p - (u8 *)root;
            }
        }
    }
    return 0;
}

u32 func_00210158(int a, int idx)
{
    TblEntry *e;

    if (idx < 0) {
        return 0;
    }
    e = func_0020EC90(a);
    if (e == 0) {
        return 0;
    }
    e = TBL_ENTRY(e, idx);
    return e->flags;
}

int TkMenuGetParamOffset(int a, int idx, int i)
{
    TblEntry *e;
    int ret;

    if (idx < 0) {
        return 0;
    }
    e = func_0020EC90(a);
    if (e == 0) {
        ret = 0;
    } else {
        e = TBL_ENTRY(e, idx);
        ret = (&e->flags)[i];
    }
    return ret;
}

int TkMenuGetParamHandle(int a, const char *name)
{
    TkSceneBank *root;
    const u8 *c;
    u8 ch;
    u32 h;
    u32 *p;
    int n;
    u32 w;
    int step;

    a = a < 0 ? 0 : (a < 8 ? a : 7);
    root = (TkSceneBank *)func_0020EC90(a);
    if (root == 0) {
        return 0;
    }
    h = 0;
    c = (const u8 *)name;
    while ((ch = *c++) != 0) {
        h ^= ch;
    }
    p = (u32 *)root->param_hash[h & 0xF];
    if (p != 0) {
        p = (u32 *)((u8 *)p + (u32)root);
        for (n = *p++; n != 0; n--) {
            w = *p;
            if (func_002F05E8((u8 *)root + (w & 0xFFFFFF), name) == 0) {
                return (u8 *)p - (u8 *)root;
            }
            step = (w >> 24) + 1;
            p += step;
        }
    }
    return 0;
}

void TkMenuInitSeq(void)
{
    int i;

    for (i = 0; i < 8; i++) {
        TkMenuSetSceneDataAdrs(i, 0);
    }
}
