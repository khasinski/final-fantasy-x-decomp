/* Shared P6 -O0 helper (115 instances): P6 ppp effect update node. */
#include "p6_overlay.h"

typedef struct P6PppObj {
    u8 pad00[0x20];
    P6Vec scale;        /* 0x20 */
    P6Vec col0;         /* 0x30 */
    P6Vec col1;         /* 0x40 */
    P6Obj150 *xform;    /* 0x50 */
    void *mgr;          /* 0x54 */
    u8 pad58[0x08];
    u8 pobj[0x60];      /* 0x60..0xC0 */
    P6Vec wC0;          /* 0xC0 */
    u16 hD0[4];         /* 0xD0..0xD8 */
    u8 padD8[0x08];
    void *wE0;          /* 0xE0 */
    s16 hE4;            /* 0xE4 */
    s16 hE6;            /* 0xE6 */
    u32 flags;          /* 0xE8 */
    s32 delay;          /* 0xEC */
    u8 padF0[0x04];
    void *wF4;          /* 0xF4 */
} P6PppObj;

extern void *D_01B00048;
extern P6Vec D_006A3930[4];
extern P6Vec D_006A39B0[4];
extern P6Vec D_006A3AB0[4];
extern P6Vec D_006A3BB0;
extern void *D_006A3BCC;

extern void func_01B096B0(P6Iter *it);
extern void func_01B09888(P6Vec *dst, P6Vec *src, float s);
extern int func_01B098D0(void *mgr, void *pobj, int stride);
extern void func_01B09948(P6PppObj *o);
extern void func_00268610(void *a0, void *a1, void *a2);

void func_01B091B8(register P6Iter *it)
{
    P6PppObj *o = (P6PppObj *)it->cur;
    void *pobj = o->pobj;
    P6Vec scl;
    int col[4];
    int dummy;

    func_01B096B0(it);
    if ((it->done & 1) == 0) {
        return;
    }
    if ((o->flags & 2) != 0) {
        return;
    }
    if (o->delay > 0) {
        if (D_006A3BC4 == 0) {
            o->delay--;
        }
        return;
    }
    if (D_006A3BC4 == 0 && (o->flags & 1) != 0) {
        col[0] = o->hE4;
        col[1] = o->hE6;
        __asm__ volatile(
            "lqc2 $vf31, 0(%0)\n\t"
            "vitof0.xyzw $vf31, $vf31\n\t"
            "vdiv Q, $vf31x, $vf31y\n\t"
            "lqc2 $vf30, 0(%1)\n\t"
            "lqc2 $vf29, 0(%2)\n\t"
            "vsub.xyzw $vf30, $vf30, $vf29\n\t"
            "vwaitq\n\t"
            "vmulq.xyzw $vf30, $vf30, Q\n\t"
            "vadd.xyzw $vf29, $vf29, $vf30\n\t"
            "vftoi12.xyzw $vf29, $vf29\n\t"
            "sqc2 $vf29, 0(%0)"
            : : "r"(col), "r"(&o->col0), "r"(&o->col1) : "memory");
        o->hD0[0] = col[0];
        o->hD0[1] = col[1];
        o->hD0[2] = col[2];
        o->hD0[3] = col[3];
        if (o->hE4 == 0) {
            o->flags &= ~1;
        }
        o->hE4--;
    }
    D_006A3BB0.x = 1.0f;
    D_006A3BB0.y = 1.0f;
    D_006A3BB0.z = 1.0f;
    D_006A3BB0.w = 1.0f;
    func_002DD0B0(&scl, &o->scale);
    func_002DD0C0(D_006A3930, o->xform->mA0);
    func_002DD068(&D_006A3930[0], &D_006A3930[0], scl.x);
    func_002DD068(&D_006A3930[1], &D_006A3930[1], scl.y);
    func_002DD068(&D_006A3930[2], &D_006A3930[2], scl.z);
    func_01B09888(&scl, &scl, o->xform->scale.w);
    func_002DD050(&scl, &scl, &o->xform->scale);
    scl.w = 1.0f;
    func_002DD0B0(&o->wC0, &scl);
    func_002DCE38(D_006A39B0, D_006A3970, D_006A3930);
    func_002DCE38(D_006A3AB0, D_006A3A70, D_006A39B0);
    D_006A3BCC = D_01B00048;
    if (func_01B098D0(o->mgr, pobj, 0x30) != 0) {
        func_01B09948(o);
        o->flags |= 4;
    }
    D_01B00048 = D_006A3BCC;
    if (D_006A3BC4 == 0 && o->wE0 != 0) {
        func_00268610(pobj, o->wE0, o->wF4);
    }
    dummy = 0;
}
