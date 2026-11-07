/* tu_326 0x2b1720-0x2b1e08: low; ~op (config/tu_map.tsv) */
/* DEBT(NAME): module and names guessed: wrappers (see w10.h). */
#include "common.h"
#include "ffx/q7.h"
#include "ffx/w10.h"
#include "ffx/r6.h"
#include "ffx/v6.h"

void func_002B1720(void)
{
    Slot80 *s = D_006EACB0;
    int i;

    D_00764A80 = D_003737A0;
    for (i = 0; i < 0x100; i++) {
        func_002EF0D0(s, 0, sizeof(Slot80));
        s->h1E = i;
        s++;
        D_006EA8B0[i] = 0;
    }
    pppInitEnv((HeapMgr *)&D_006F2CB0, 0, D_00373820, 0x80000);
}

void func_002B17B8(void)
{
    D_007649A1 = 0;
}

void func_002B17C8(void) {
}

INCLUDE_ASM("build/ee_asm/game/op/op_2B1720", func_002B17D0);

INCLUDE_ASM("build/ee_asm/game/op/op_2B1720", op_effect_run_after);

void func_002B19C0(void) {
}

void func_002B19C8(void)
{
    R6Obj *o = D_0054D5E8[0];

    if (o->w58 == 0) {
        o->w54 = D_003F3944;
        D_003F3948 = D_003F3940 + 0xF0000;
    }
    func_00294CD8(0, 2);
    if (o->w58 == 0) {
        D_003F3944 = o->w54;
    }
    D_003F3948 = 0;
}

void func_002B1A48(V6HeapOwner *o)
{
    HeapCfg *c = o->cfg;
    HeapMgrV *m = &D_006F2CB0;

    m->w20 = c->w14;
    m->tbl = c->tbl;
    m->p28 = c->p1C;
    D_006A3924 = (HeapMgr *)m; /* DEBT(CAST): HeapMgrV is the full view of HeapMgr */
    if (func_002A5488((char *)c) == 0) {
        _pppInitData(c, D_0036F210);
    }
}

INCLUDE_ASM("build/ee_asm/game/op/op_2B1720", func_002B1AB8);

int op_part_run(V6HeapOwner *o)
{
    Slot80 *s = o->slot;
    HeapCfg *c = o->cfg;
    HeapMgrV *m = &D_006F2CB0;
    int r;

    D_006A3924 = (HeapMgr *)m; /* DEBT(CAST): HeapMgrV is the full view of HeapMgr */
    m->w20 = c->w14;
    m->tbl = c->tbl;
    m->p28 = c->p1C;
    r = _pppRunPart(s, 0x30);
    if (r != 0) {
        D_006A3924 = (HeapMgr *)m;
        D_006EA8B0[s->h1E] = 0;
        _pppAllFreePObject(s);
    }
    return r;
}

void func_002B1CF0(void) {
}

void func_002B1CF8(void)
{
    int i;

    D_006A3924 = (HeapMgr *)&D_006F2CB0;
    for (i = 0; i < 0x100; i++) {
        if (D_006EA8B0[i] != 0) {
            D_006EA8B0[i] = 0;
            D_006A3924 = (HeapMgr *)&D_006F2CB0;
            _pppAllFreePObject(&D_006EACB0[i]);
        }
    }
}

void _m2c_func_002B1D88__pppAllFreePObject(void *) __asm__("_pppAllFreePObject");
/* DEBT(CAST) */ /* DEBT(FAKE) */
void func_002B1D88(void *arg0) {
    void *temp_16;
    register u32 hi __asm__("$3");
    register HeapMgr *val __asm__("$2");
    register void *a0 __asm__("$4");

    if ((*(u8 *)((u8 *)(arg0) + (0xBB))) == 3) {
        temp_16 = (*(void **)((u8 *)(arg0) + (0xBC)));
        if (temp_16 != 0) {
            hi = 0x006A0000;
            __asm__ volatile("" : "+r"(hi));
            val = (HeapMgr *) &D_006F2CB0;
            __asm__ volatile("" : "+r"(val));
            a0 = temp_16;
            __asm__ volatile("" : "+r"(a0));
            *(HeapMgr **)(hi + 0x3924) = val;
            _m2c_func_002B1D88__pppAllFreePObject(a0);
            (*(void **)((u8 *)(arg0) + (0xBC))) = 0;
            D_006EA8B0[(*(u16 *)((u8 *)(temp_16) + (0x1E)))] = 0;
            (*(u8 *)((u8 *)(arg0) + (0xBB))) = 0U;
        }
    }
}

void func_002B1E00(void) {
}
