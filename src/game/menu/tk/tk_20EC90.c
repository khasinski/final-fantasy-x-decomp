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

INCLUDE_ASM("build/ee_asm/game/menu/tk/tk_20EC90", func_0020EEB8);
INCLUDE_RODATA("build/ee_asm/game/menu/tk/tk_20EC90/rodata", jtbl_00570A80);

INCLUDE_ASM("build/ee_asm/game/menu/tk/tk_20EC90", func_0020F750);

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

INCLUDE_ASM("build/ee_asm/game/menu/tk/tk_20EC90", func_0020FA50);
INCLUDE_RODATA("build/ee_asm/game/menu/tk/tk_20EC90/rodata", jtbl_00570AA0);

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
