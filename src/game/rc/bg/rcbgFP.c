/* tu_160 0x19a708-0x19bad8: low; rcbgFP (config/tu_map.tsv) */
#include "common.h"
#include "ffx/r2.h"
#include "ffx/q3.h"
#include "ffx/s2.h"
#include "ffx/v2.h"
#include "ffx/w3.h"
#include "ffx/g2.h"
#include "vu0.h"

void rcbgSetWorldMatrix(void *dst) {
    func_002DD0C0(D_00313850, dst);
}

void func_0019A718(float a, float b, float c, float d, float e) {
    func_002DD128((struct W3Whole *)D_00313910); /* DEBT(CAST): the matrix is passed as the W3Whole view */
    D_00313910[15] = 0;
    D_00313910[11] = 1.0f;
    D_00313910[0] = (c + c) / a;
    D_00313910[5] = (c + c) / b;
    D_00313910[10] = (e + d) / (e - d);
    D_00313910[14] = e * -2.0f * d / (e - d);
}

void func_0019A7F8(void) {
    func_0019A718(512.0f / ms_screen[0].f10, 416.0f / ms_screen[0].f14, ms_screen[0].f1C, ms_screen[0].f08, ms_screen[0].f0C);
}

void func_0019A840(void) {
    func_002DCE38(D_00313890, D_003142A0, D_00313850);
    func_002DCE38(D_00313950, D_00313910, D_00313890);
    func_002DCE38(D_003138D0, D_00314260, D_00313890);
}

INCLUDE_ASM("build/ee_asm/game/rc/bg/rcbgFP", func_0019A8A8);

void func_0019A910(S2Ent *e, void *sub)
{
    float v[4];
    float k = 11.3777781f; /* 0x41360B61 */
    register float *p __asm__("$2") = (float *)((u8 *)e + 0x20); /* DEBT(CAST) */
    register int ki __asm__("$3"); /* DEBT(FAKE): original register assignment */

    MIPS_MFC1(ki, k);
    VU0_LQC2(31, 0, p);
    VU0_QMTC2_NI(30, ki);
    VU0_OP("vmulx.xyz $vf31, $vf31, $vf30x");
    VU0_SQC2(31, 0, v);
    func_002DD128(sub);
    rcMat4fSetScaleVec3f(sub, (u8 *)e + 0x30);
    op_rt_m_yxz((int)sub, (int)sub, (int)v, (int)((u8 *)e + 0x10)); /* DEBT(CAST): prototype takes four ints */
}

void func_0019A988(float *v, Chr *chr, int i)
{
    int k;

    func_001072F8(chr, i, v);
    k = 0x41200000; /* 10.0f */
    VU0_LQC2(31, 0, v);
    VU0_QMTC2_NI(30, k);
    VU0_OP("vmulx.xyz $vf31, $vf31, $vf30x");
    VU0_SQC2(31, 0, v);
    VU0_LQC2(31, 0, v + 4);
    VU0_QMTC2_NI(30, k);
    VU0_OP("vmulx.xyz $vf31, $vf31, $vf30x");
    VU0_SQC2(31, 0, v + 4);
    VU0_LQC2(31, 0, v + 8);
    VU0_QMTC2_NI(30, k);
    VU0_OP("vmulx.xyz $vf31, $vf31, $vf30x");
    VU0_SQC2(31, 0, v + 8);
}

int func_0019A9F8(S2Ent *e, int n) {
    S2EntObj *obj;
    int i;
    int ok = 0;

    for (i = 0; i < n; i++, e++) {
        pppFpGetMngPtr(e->id, 0, &obj);
        if (obj == 0) {
            return ok;
        }
        func_00269DA8(e->id);
        switch (e->type) {
        case 1:
            pppFpSetStickChr(e->id, rcefGetChrHandle(e->arg), e->arg2);
            break;
        case 2:
            pppFpSetStickMap(e->id, e->arg);
            break;
        case 3:
        case 4:
            obj->flags |= 4;
            break;
        case 5:
            obj->flags |= 0x100;
            break;
        }
        obj->flags |= 0x60;
        func_0019A910(e, obj->sub);
        if (e->active) {
            pppFpIDon(e->id);
        } else {
            pppFpIDoff(e->id);
        }
        ok = 1;
    }
    return ok;
}

W3Obj *func_0019AB50(int id, int i, int j)
{
    Slot80 *s;
    V2Mdl *m;
    V2MdlHdr *h;
    V2MdlEnt *e;
    u8 *r = 0;

    pppFpGetMngPtr(id, &s, 0);
    if (s != 0) {
        m = *(V2Mdl **)((u8 *)s + 0x30); /* DEBT(CAST): Slot80 does not describe 0x30 yet */
        if (m != 0 && m->hdr != 0) {
            h = *m->hdr;
            if (h != 0) {
                e = &h->ent[i];
                if (e != 0) {
                    r = (u8 *)m + (e->offs[j] + 0xA0);
                }
            }
        }
    }
    return (W3Obj *)r;
}

INCLUDE_ASM("build/ee_asm/game/rc/bg/rcbgFP", rcbgFpGetWork2);

void *func_0019ACB8(void) {
    void *p = _rcAlloc(0x40, D_0056DB98, 0x14C);

    func_0019AD20(p);
    return p;
}

void func_0019ACF8(void *p) {
    rcbgFPm097Proc010(p);
    func_0018FC10(p);
}

void func_0019AD20(R2Vt2 *o) {
    func_002EF0D0(o, 0, 0x40);
    o->id = 0x20008;
    o->p4 = (u8 *)func_0019ACB8 + 0x40; /* DEBT(CAST) */
    o->p8 = (u8 *)rcbgFPm097Proc010 + 8; /* DEBT(CAST) */
    o->pC = 0;
}

INCLUDE_ASM("build/ee_asm/game/rc/bg/rcbgFP", rcbgFPm097Proc010);

INCLUDE_ASM("build/ee_asm/game/rc/bg/rcbgFP", func_0019AD80);

INCLUDE_ASM("build/ee_asm/game/rc/bg/rcbgFP", func_0019ADC0);

void func_0019B168(R2Obj19B1 *o, int a, int b, float f) {
    pppFpIDdispOff(a & 0xFFFF);
    o->w4 = a;
    o->f8 = f;
    o->wC = b;
    o->w0 = 0;
    o->w10 = 0;
}

INCLUDE_ASM("build/ee_asm/game/rc/bg/rcbgFP", rcbgFPm097shibukiProc);

void *rcbgFPm173New(void) {
    void *p = _rcAlloc(0x28, D_0056DB98, 0x25A);

    func_0019B498(p);
    return p;
}

void func_0019B3F8(void *p) {
    func_0019B4F0(p);
    func_0018FC10(p);
}

void func_0019B420(int id, int chr, int bone)
{
    S2EntObj *obj;

    pppFpGetMngPtr(id, 0, &obj);
    if (obj != 0) {
        obj->flags |= 0x100;
        pppFpIDon(id);
        func_001072F8((Chr *)chr, bone, obj->sub); /* DEBT(CAST): Chr handle passed as int */
    }
}

void func_0019B498(R2Vt2 *o) {
    func_002EF0D0(o, 0, 0x28);
    o->id = 0x20008;
    o->p4 = (u8 *)rcbgFPm173New + 0x40; /* DEBT(CAST) */
    o->p8 = (u8 *)func_0019B4F0 + 8; /* DEBT(CAST) */
    o->pC = 0;
}

void func_0019B4F0(void *p)
{
}

void func_0019B4F8(V2Obj7C *o)
{
    if (o->active != 0) {
        switch (o->state) {
        case 0:
            rcbgFPm173ProcJect(o);
            break;
        case 1:
            rcbgFPm173ProcKonjyo(o);
            break;
        case 2:
            func_0019B6F0(o);
            break;
        case 3:
            rcbgFPm173ProcKieru(o);
            break;
        }
        o->time++;
    }
}

void rcbgFPm173ProcJect(V2Obj7C *o)
{
    switch (o->time) {
    case 0x25:
        func_0019B420(0x53, o->chr, 0x2F);
        break;
    case 0x82:
        pppFpSetStickChr(0x54, (Chr *)o->chr, 2); /* DEBT(TYPE): chr is a Chr handle */
        pppFpIDon(0x54);
        break;
    case 0xC8:
        pppFpIDoff(0x54);
        break;
    case 0x100:
        func_0019B420(0x55, o->chr, 0x5D);
        o->active = 0;
        break;
    }
}

void rcbgFPm173ProcKonjyo(V2Obj7C *o)
{
    switch (o->time) {
    case 0:
        pppFpSetStickChr(0x58, (Chr *)o->chr, 2); /* DEBT(TYPE): w10 is a Chr handle */
        pppFpIDon(0x58);
        break;
    case 50:
        pppFpSetStickChr(0x59, (Chr *)o->chr, 0x35);
        pppFpIDon(0x59);
        o->active = 0;
        break;
    }
}

void func_0019B6F0(V2Obj7C *o) {
    if (o->time == 0x7C) {
        func_0019B420(0x4E, o->chr, Ch_OptposGetElement(o->chr, 8, 0));
        o->active = 0;
    }
}

INCLUDE_ASM("build/ee_asm/game/rc/bg/rcbgFP", rcbgFPm173ProcKieru);

INCLUDE_ASM("build/ee_asm/game/rc/bg/rcbgFP", func_0019B810);

INCLUDE_ASM("build/ee_asm/game/rc/bg/rcbgFP", func_0019B878);

void *func_0019B888(void) {
    void *p = _rcAlloc(0x10, D_0056DB98, 0x3A3);

    func_0019B8F0(p);
    return p;
}

void func_0019B8C8(void *p) {
    rcbgFPm565Proc010(p);
    func_0018FC10(p);
}

void func_0019B8F0(R2Vt2 *o) {
    func_002EF0D0(o, 0, 0x10);
    o->id = 0x20008;
    o->p4 = (u8 *)func_0019B888 + 0x40; /* DEBT(CAST) */
    o->p8 = (u8 *)rcbgFPm565Proc010 + 8; /* DEBT(CAST) */
    o->pC = 0;
}

INCLUDE_ASM("build/ee_asm/game/rc/bg/rcbgFP", rcbgFPm565Proc010);

INCLUDE_ASM("build/ee_asm/game/rc/bg/rcbgFP", func_0019B950);

INCLUDE_ASM("build/ee_asm/game/rc/bg/rcbgFP", func_0019B990);
