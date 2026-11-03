/* Battle-effect character command library (TU rank 1, family F2), 113 containers.
 * Reference container file09047, .text 0x01B04A98..0x01B071D8 (relocated per container); the TU's
 * last function, func_01B071D8 (VU0 vector length: lqc2/vmul/vsqrt/qmfc2 inline asm), is not C.
 * Compiled with -O0 (see overlays/p5_overlay.h): byte-identical in all 113 containers with
 * `ee-gcc -c -O0 -G0 -g0`. Parked in overlays/wip/ because verify_overlays.py compiles with -O2;
 * registration ready in overlays/wip/p5.py.
 * Every command handler takes its argument block in s0 (`register`); the dead `r = 0;` stores
 * are in the original code (-O0 keeps them). */
#include "p5_overlay.h"

float func_01B071D8(P5Vec *v);
void func_01B03A40(P5Args *a);
void func_01B07348(P5Args *a);
void func_01B07438(P5Args *a);
float func_01B0C0E8(P5Vec *v);
float func_01B07238(float f);
int func_01B07278(float f);
int func_01B072D8(int id);

void func_01B04A98(register P5Args *a)
{
    P5Chr *c;
    Chr *w; /* DEBT(PADDING): unused, keeps r at 8(s8) like func_01B04AE8 */
    int r;

    c = a->c;
    Ch_ClothReset2(c->chr);
    r = 0;
}

void func_01B04AE8(register P5Args *a)
{
    P5Chr *c;
    Chr *w;
    int r;

    c = a->c;
    Ch_CalcElement(c->chr);
    if (!(c->flags & 1)) {
        w = MsGetWeaponHandle(c->id, 0);
        if (w) {
            Ch_CalcElement(w);
        }
        w = MsGetWeaponHandle(c->id, 1);
        if (w) {
            Ch_CalcElement(w);
        }
    }
    r = 0;
}

void func_01B04BB0(register P5Args *a)
{
    P5Chr *c;

    c = a->c;
    if (c->flags & 1) {
        a->a[0].fp[0] = Ch_GetScaleX(c->chr);
        a->a[0].fp[1] = Ch_GetScaleY(c->chr);
        a->a[0].fp[2] = Ch_GetScaleZ(c->chr);
    } else {
        MsGetChrScale(c->id, a->a[0].fp);
    }
    a->a[0].fp[3] = func_00110AF0(c->chr) * 0.001f;
}

void func_01B04CA0(register P5Args *a)
{
    P5Chr *c;

    c = a->c;
    if (c->flags & 1) {
        a->a[0].fp[0] = 1.0f;
        a->a[0].fp[1] = 1.0f;
        a->a[0].fp[2] = 1.0f;
    } else {
        a->a[0].fp[0] = 1.0f;
        a->a[0].fp[1] = 1.0f;
        a->a[0].fp[2] = 1.0f;
    }
    a->a[0].fp[3] = MsGetChrWidth(c->id);
    if (a->a[0].fp[3] < a->a[1].f) {
        a->a[0].fp[3] = a->a[1].f;
    }
    if (a->a[0].fp[3] > a->a[2].f) {
        a->a[0].fp[3] = a->a[2].f;
    }
}

void func_01B04DE0(register P5Args *a)
{
    P5Chr *c;
    int r;

    c = a->c;
    if (a->a[0].i) {
        c->gravity = MsSetChrGravity(c->id, 1);
    } else {
        c->gravity = MsSetChrGravity(c->id, 0);
    }
    r = 0;
}

void func_01B04E70(register P5Args *a)
{
    P5Chr *c;
    int r;

    c = a->c;
    Ch_EnClip(c->chr, a->a[0].i);
    r = 0;
}

void func_01B04EC8(register P5Args *a)
{
    P5Chr *c;
    Chr *w;
    int r;

    c = a->c;
    Ch_DrawSetSituation(c->chr, a->a[0].b);
    if (!(c->flags & 1)) {
        w = MsGetWeaponHandle(c->id, 0);
        if (w) {
            Ch_DrawSetSituation(w, a->a[0].b);
        }
        w = MsGetWeaponHandle(c->id, 1);
        if (w) {
            Ch_DrawSetSituation(w, a->a[0].b);
        }
    }
    if (a->a[0].b) {
        func_002985C0(c->chr);
        c->flags |= 0x800;
    } else {
        c->flags &= ~0x800;
    }
    r = 0;
}

void func_01B04FF8(register P5Args *a)
{
    P5Chr *c;
    int r;

    c = a->c;
    Ch_DrawEnEffect(c->chr, a->a[0].i == 0);
    r = 0;
}

void func_01B05058(register P5Args *a)
{
    P5Chr *c;
    int r;

    c = a->c;
    if (c->flags & 1) {
        func_00110718(c->chr, a->a[0].i);
    } else {
        MsSetChrVisible(c->id, a->a[0].i == 0);
    }
    r = 0;
}

void func_01B050F0(register P5Args *a)
{
    P5Chr *c;
    int r;

    c = a->c;
    Ch_SetShadeCol(c->chr, a->a[0].f, a->a[1].f, a->a[2].f, a->a[3].i);
    r = 0;
}

void func_01B05150(register P5Args *a)
{
    P5Chr *c;
    P5Vec pos;

    c = a->c;
    if (c->flags & 1) {
        goto end; /* DEBT(GOTO): -O0 jump-to-jump of the skipped block */
    }
    c->h96 = a->a[3].b;
    c->f84 = a->a[0].f;
    c->f7C = a->a[0].f;
    c->f80 = a->a[1].f;
    c->f88 = a->a[4].f;
    c->f8C = a->a[2].f;
    c->gravity = MsSetChrGravity(c->id, 0);
    c->flags |= 0x40;
    func_001B6790(c->id, &pos);
end:
    c->flags &= ~0x400;
}

void func_01B05250(register P5Args *a)
{
    P5Chr *c;
    int r;

    c = a->c;
    if (c->flags & 1) {
        goto end; /* DEBT(GOTO) */
    }
    MsSetChrPos(c->id, a->a[0].v);
end:
    r = 0;
}

void func_01B052C8(register P5Args *a)
{
    P5Chr *c;

    c = a->c;
    Ch_SetOrgMatrix(c->chr, a->a[0].org->mtxA0);
    c->org = a->a[0].org;
    c->flags |= 0x10;
}

void func_01B05340(register P5Args *a)
{
    P5Chr *c;
    int r;

    c = a->c;
    if (c->flags & 1) {
        goto end; /* DEBT(GOTO) */
    }
    Ch_SetOrgMatrix(c->chr, 0);
    c->flags &= ~0x10;
    MsSetChrPos(c->id, &c->org->posD0);
end:
    r = 0;
}

void func_01B053E8(register P5Args *a)
{
    P5Chr *c;

    c = a->c;
    if (c->flags & 1) {
        return;
    }
    func_002DD0B0(&c->pos30, &c->pos20);
    c->f78 = a->a[0].f;
    c->flags |= 8;
}

void func_01B05488(register P5Args *a)
{
    P5Chr *c;

    c = a->c;
    if (c->flags & 1) {
        return;
    }
    func_001B6790(c->id, &c->pos20);
    func_002DD0B0(&c->pos30, a->a[0].v);
    c->f78 = a->a[1].f;
    c->flags |= 8;
}

void func_01B05538(register P5Args *a)
{
    P5Chr *c;

    c = a->c;
    if (c->flags & 1) {
        return;
    }
    func_001B6790(c->id, &c->pos20);
    a->a[0].fp[3] = 0.0f;
    func_002DD020(&c->pos30, &c->pos20, a->a[0].v);
    c->f78 = a->a[1].f;
    c->flags |= 8;
}

void func_01B05600(register P5Args *a)
{
    P5Chr *c;
    P5Vec p;
    P5Vec q;

    c = a->c;
    if (c->flags & 1) {
        return;
    }
    func_001B6790(c->id, &p);
    func_001B6790(a->a[1].i, &q);
    func_002DD038(&p, &p, &q);
    a->a[0].f = func_01B071D8(&p);
}

void func_01B056B8(register P5Args *a)
{
    P5Chr *c;
    P5Vec p;
    P5Vec q;
    float cs;
    float sn;
    float tn;

    c = a->c;
    if (c->flags & 1) {
        return;
    }
    cs = eff_sin_t[((a->a[2].i + 0x4000) & 0xFFFF) >> 4];
    sn = eff_sin_t[(a->a[2].i & 0xFFFF) >> 4];
    tn = sn / cs;
    func_001B6790(c->id, &p);
    func_001B6790(a->a[1].i, &q);
    func_002DD038(&q, &p, &q);
    sn = func_01B071D8(&q);
    cs = sn / cs;
    sn = tn * cs;
    a->a[0].f = sn - q.y;
}

void func_01B05818(register P5Args *a)
{
    P5Chr *c;
    P5Vec p;
    P5Vec q;
    float cs;
    float sn;
    float tn;

    c = a->c;
    if (c->flags & 1) {
        return;
    }
    cs = eff_sin_t[((a->a[2].i + 0x4000) & 0xFFFF) >> 4];
    sn = eff_sin_t[(a->a[2].i & 0xFFFF) >> 4];
    tn = sn / cs;
    func_001B6790(c->id, &p);
    func_002DD038(&q, &p, a->a[1].v);
    sn = func_01B071D8(&q);
    cs = sn / cs;
    sn = tn * cs;
    a->a[0].f = sn - q.y;
}

void func_01B05960(register P5Args *a)
{
    P5Chr *c;
    P5Vec p;

    c = a->c;
    a->a[0].ip[0] = a->a[0].ip[2] = 0;
    if (c->flags & 1) {
        return;
    }
    func_001B6790(c->id, &p);
    func_002DD038(&p, a->a[1].v, &p);
    a->a[0].ip[1] = func_01B07278(func_01B07238(func_01B0C0E8(&p)));
}

void func_01B05A38(register P5Args *a)
{
    P5Chr *c;

    c = a->c;
    a->a[0].ip[0] = a->a[0].ip[2] = 0;
    if (c->flags & 1) {
        a->a[0].ip[1] = func_01B07278(func_01B07238(func_00110288(c->chr)));
    } else {
        a->a[0].ip[1] = func_01B072D8(c->id);
    }
}

void func_01B05AF8(register P5Args *a)
{
    P5Chr *c;
    P5Vec p;
    int r;

    c = a->c;
    if (c->flags & 1) {
        goto end; /* DEBT(GOTO) */
    }
    func_001B6790(c->id, &p);
    func_002DD038(&p, a->a[0].v, &p);
    func_001B6EF8(c->id, func_01B0C0E8(&p));
end:
    r = 0;
}

void func_01B05BB8(register P5Args *a)
{
    P5Chr *c;
    int r;

    c = a->c;
    if (c->flags & 1) {
        goto end; /* DEBT(GOTO) */
    }
    func_001B6EF8(c->id, a->a[0].f);
end:
    r = 0;
}

void func_01B05C30(register P5Args *a)
{
    P5Chr *c;
    P5Vec d;
    float f;

    c = a->c;
    if (c->flags & 1) {
        return;
    }
    c->motion = func_001CE050(c->id, a->a[0].i);
    c->f74 = c->motion;
    func_001B6790(c->id, &c->pos20);
    func_002DD038(&d, a->a[1].v, &c->pos20);
    f = func_01B071D8(&d);
    f = (f - a->a[2].f) / f;
    func_002DD068(&d, &d, f);
    func_002DD020(&c->pos30, &c->pos20, &d);
    c->flags |= 4;
    c->flags &= ~8;
}

void func_01B05DC8(register P5Args *a)
{
    P5Chr *c;
    P5Vec d;
    float f;

    c = a->c;
    c->h98 = a->a[3].h;
    if (c->flags & 1) {
        return;
    }
    c->motion = func_001CE050(c->id, a->a[0].i) - a->a[3].i;
    c->f74 = c->motion;
    func_001B6790(c->id, &c->pos20);
    func_002DD038(&d, a->a[1].v, &c->pos20);
    f = func_01B071D8(&d);
    f = (f - a->a[2].f) / f;
    func_002DD068(&d, &d, f);
    func_002DD020(&c->pos30, &c->pos20, &d);
    c->flags |= 4;
    c->flags &= ~8;
}

void func_01B05F78(register P5Args *a)
{
    if (a->c->flags & 1) {
        func_00110718(a->c->chr, 0);
        func_00110540(a->c->chr, a->a[0].f, a->a[1].i);
    } else {
        MsSetChrVisible(a->c->id, 1);
        MsSetChrTransparent(a->c->id, a->a[0].f, a->a[1].i);
    }
    if (a->a[0].f == 0.0f) {
        a->c->i5C = a->a[1].i;
        a->c->flags |= 2;
    }
}

void func_01B06058(register P5Args *a)
{
    if (a->c->flags & 1) {
        a->a[0].i = Ch_GetWaitMotion(a->c->chr);
    } else {
        a->a[0].i = MsEffectCheckMotion(a->c->id);
    }
}

void func_01B060D8(register P5Args *a)
{
    P5Chr *c;
    int r;

    c = a->c;
    if (c->flags & 1) {
        Ch_ResetMotion(c->chr);
        Ch_SetSequence(c->chr, a->a[0].i);
        c->flags |= 0x200;
    } else {
        func_001CE050(c->id, a->a[0].i);
    }
    c->i64 = a->a[0].i;
    c->flags |= 0x100;
    r = 0;
}

void func_01B061A8(register P5Args *a)
{
    P5Chr *c;
    int r;

    c = a->c;
    if (a->c->flags & 1) {
        Ch_SetSequence(a->c->chr, a->a[0].i);
        c->flags |= 0x200;
    } else {
        func_001CE050(a->c->id, a->a[0].i);
    }
    c->i64 = a->a[0].i;
    a->c->flags |= 0x120;
    r = 0;
}

void func_01B06268(register P5Args *a)
{
    P5Chr *c;
    int r;

    c = a->c;
    if (a->c->flags & 1) {
        Ch_SetSequence(a->c->chr, a->a[0].i);
        c->flags |= 0x200;
    } else {
        func_001CE050(a->c->id, a->a[0].i);
    }
    c->i64 = a->a[1].i;
    a->c->flags |= 0x120;
    r = 0;
}

void func_01B06328(register P5Args *a)
{
    int r;

    if (!(a->c->flags & 1)) {
        MsGetChrTopPos(a->c->id, a->a[0].v);
    }
    r = 0;
}

void func_01B06390(register P5Args *a)
{
    int r;

    if (!(a->c->flags & 1)) {
        MsGetChrBtlPos(a->c->id, a->a[0].v);
    }
    r = 0;
}

void func_01B063F8(register P5Args *a)
{
    int r;

    Ch_GetPos(a->c->chr, a->a[0].fp, &a->a[0].fp[1], &a->a[0].fp[2]);
    a->a[0].fp[1] = Ch_GetJimen(a->c->chr);
    r = 0;
}

void func_01B06478(register P5Args *a)
{
    int r;

    if (!(a->c->flags & 1)) {
        MsGetChrCenterPos(a->c->id, a->a[0].v);
    }
    r = 0;
}

void func_01B064E0(register P5Args *a)
{
    int r;

    Ch_OptposGet(a->c->chr, 17, a->a[0].fp);
    a->a[0].fp[3] = 1.0f;
    r = 0;
}

void func_01B06548(register P5Args *a)
{
    int r;

    Ch_OptposGet(a->c->chr, 17, a->a[0].fp);
    a->a[0].fp[3] = 1.0f;
    if (a->a[1].i) {
        a->a[0].fp[1] = Ch_GetJimen(a->c->chr);
    }
    r = 0;
}

void func_01B065D8(register P5Args *a)
{
    int r;

    Ch_GetPos(a->c->chr, a->a[0].fp, &a->a[0].fp[1], &a->a[0].fp[2]);
    r = 0;
}

void func_01B06638(register P5Args *a)
{
    int r;

    func_00107428(a->c->chr, a->a[0].i, 0, a->a[1].v);
    r = 0;
}

void func_01B06690(register P5Args *a)
{
    int r;

    func_00108A28(a->c->chr, a->a[0].p);
    r = 0;
}

void func_01B066E0(register P5Args *a)
{
    int r;

    Ch_OptposGet(a->c->chr, a->a[0].i, a->a[1].fp);
    r = 0;
}

void func_01B06730(register P5Args *a)
{
    int r;

    func_001072F8(a->c->chr, a->a[0].i, a->a[1].p);
    r = 0;
}

void func_01B06780(register P5Args *a)
{
    int r;

    Ch_GetRootGlobalMatrix(a->c->chr, a->a[0].p);
    r = 0;
}

void func_01B067D0(register P5Args *a)
{
    P5Chr *c;
    int r;

    c = a->c;
    func_01B07348(a);
    c->id = a->a[1].i;
    c->flags = a->a[2].b;
    c->i6C = 0;
    c->i70 = 0;
    c->gravity = -1;
    if (a->a[2].b & 1) {
        c->chr = func_0013B0F8(a->a[1].i);
    } else {
        c->chr = MsGetChrHandle(a->a[1].i);
    }
    func_001107D8(c->chr, &c->scale[0], &c->scale[1], &c->scale[2]);
    c->f90 = func_00110288(c->chr);
    r = 0;
}

void func_01B068E0(register P5Args *a)
{
    func_01B03A40(a);
    a->c->p00 = D_01B02650;
    a->c->flags = a->a[2].b;
    a->c->chr = a->a[1].chr;
    a->c->flags |= 0x80;
    a->c->flags |= 1;
}

void func_01B06970(register P5Args *a)
{
    P5Chr *c;
    Chr *w;
    int r;

    c = a->c;
    if (!(c->flags & 1)) {
        if (c->gravity != -1) {
            MsSetChrGravity(c->id, c->gravity);
        }
        MsEffectEndMotion(c->id, c->i70);
    }
    if (c->flags & 0x10) {
        Ch_SetOrgMatrix(c->chr, 0);
    }
    Ch_SetScale(c->chr, 7, c->scale[0], c->scale[1], c->scale[2]);
    func_00110300(c->chr, c->f90);
    if (c->flags & 0x800) {
        func_002985E0(c->chr);
        Ch_DrawSetSituation(c->chr, 0);
        if (!(c->flags & 1)) {
            w = MsGetWeaponHandle(c->id, 0);
            if (w) {
                Ch_DrawSetSituation(w, 0);
            }
            w = MsGetWeaponHandle(c->id, 1);
            if (w) {
                Ch_DrawSetSituation(w, 0);
            }
        }
    }
    r = 0;
}

void func_01B06B40(register P5Args *a)
{
    P5Vec p;
    P5Vec q;
    P5Chr *c;
    float g;
    P5Msg m;
    int w;

    func_01B07438(a);
    if (!(a->a[0].b & 1)) {
        return;
    }
    c = a->c;
    if (c->flags & 0x10) {
        m.org = c->org;
        m.b5 = a->a[0].bb[1];
        m.org->vt->f1C(&m);
    }
    if (c->flags & 0x100) {
        if (!(c->flags & 1)) {
            w = MsEffectCheckMotion(c->id);
        } else {
            w = Ch_GetWaitMotion(c->chr);
        }
        if (w) {
            if (c->flags & 0x20) {
                if (c->flags & 1) {
                    Ch_SetSequence(c->chr, c->i64);
                } else {
                    func_001CE050(c->id, c->i64);
                }
            } else {
                if (c->flags & 1) {
                } else {
                    func_001CE050(c->id, 16);
                }
                c->flags &= ~0x100;
            }
        }
    }
motion_done: /* DEBT(GOTO): unreferenced label; at -O0 it emits the nop at +0x1B4 */
    ;
    if ((c->flags & 2) && c->i5C == 0) {
        if (!(c->flags & 1)) {
            MsSetChrVisible(c->id, 0);
        } else {
            func_00110718(c->chr, 1);
        }
    }
    c->i5C--;
    if (c->flags & 4) {
        if (!(c->flags & 1)) {
            if (c->h98) {
                c->h98--;
            } else if (c->motion) {
                c->motion--;
                func_002DD038(&p, &c->pos20, &c->pos30);
                func_002DCFB8(&p, &p, c->f74);
                func_002DD068(&p, &p, c->motion);
                func_002DD020(&p, &c->pos30, &p);
                MsSetChrPos(c->id, &p);
            } else {
                c->flags &= ~4;
            }
        }
    } else if (c->flags & 8) {
        if (!(c->flags & 1)) {
            func_001B6790(c->id, &p);
            func_002DD038(&q, &c->pos30, &p);
            func_002DD068(&q, &q, c->f78);
            q.w = 0.0f;
            func_002DD020(&p, &p, &q);
            MsSetChrPos(c->id, &p);
        }
    } else if (c->flags & 0x40) {
        if (!(c->flags & 1)) {
            c->f7C -= c->f80;
            if (c->f7C >= 0.0f) {
                c->f7C -= (c->f7C - c->f8C) * c->f8C;
            } else {
                c->f7C += (c->f7C - c->f8C) * c->f8C;
            }
            func_001B6790(c->id, &p);
            p.y -= c->f7C;
            g = MsGetChrGround(c->id);
            if (MsGetChrFly(c->id)) {
                g += MsGetChrBtlPosHeight(c->id);
            }
            if (p.y >= g) {
                c->flags |= 0x400;
                if (--c->h96) {
                    c->f7C = c->f84 * c->f88;
                    p.y = g - c->f7C;
                } else {
                    MsSetChrGravity(c->id, c->gravity);
                    c->flags &= ~0x40;
                    p.y = g;
                }
            }
            MsSetChrPos(c->id, &p);
        }
    }
}
