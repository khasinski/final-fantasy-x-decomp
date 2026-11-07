/* tu_288 0x268680-0x26a9a8: medium; ~ppp (config/tu_map.tsv) */
#include "common.h"
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

INCLUDE_ASM("build/ee_asm/game/particle/eiProg/ppp_268680", func_002686F0);

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

INCLUDE_ASM("build/ee_asm/game/particle/eiProg/ppp_268680", pppSetFpPdt);

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
    func_002DCEC8((s32)a, (s32)a); /* DEBT(CAST): funcs.h prototype takes ints */
    o = (u_long128 *)D_006A3A40;
    *o = *(u_long128 *)a;
    b[0] = a[1];
    b[1] = -a[0];
    b[2] = 0;
    b[3] = 0;
    func_002DCEC8((s32)b, (s32)b);
    q = o - 1;
    q[0] = *(u_long128 *)b;
    func_002DCE80(c, b, a);
    func_002DCEC8((s32)c, (s32)c);
    q[3] = *(u_long128 *)(D_006A3970 + 0x30);
    q[2] = *(u_long128 *)c;
}

INCLUDE_ASM("build/ee_asm/game/particle/eiProg/ppp_268680", pppFpSetRotMatrix);
INCLUDE_RODATA("build/ee_asm/game/particle/eiProg/ppp_268680/rodata", jtbl_00574020);

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
        func_002DCE08(D_006A39B0 + 0x30, D_006A3970, D_006A3930 + 0x30);
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
INCLUDE_ASM("build/ee_asm/game/particle/eiProg/ppp_268680", func_00269050);

INCLUDE_ASM("build/ee_asm/game/particle/eiProg/ppp_268680", pppFpInfPrint);

INCLUDE_ASM("build/ee_asm/game/particle/eiProg/ppp_268680", pppFpLoop);

INCLUDE_ASM("build/ee_asm/game/particle/eiProg/ppp_268680", func_002697B8);

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
        func_002DD128((struct W3Whole *)o->m); /* DEBT(CAST): prototype takes the W3Whole view */
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

INCLUDE_ASM("build/ee_asm/game/particle/eiProg/ppp_268680", pppFpPointLightProc);

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
