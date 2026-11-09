/* tu_305 0x27f2e8-0x2803c0: low; ~KeLnsLp (config/tu_map.tsv) */
/* Module guess: event-script VM / field-event runtime (no __FILE__ string found for this range). */
#include "common.h"
#include "ffx/r6.h"
#include "ffx/w9.h"
#include "ffx/q6.h"
#include "ffx/u4.h"
#include "ffx/v6.h"
#include "ffx/g4.h"

void func_0027F2E8(R6Hb *dst, DataRef **p) {
    dst->h0 = (*p)->keys[0].dur;
    dst->b2 = 0;
}

void func_0027F300(G4PtPlayer *p)
{
    G4Hb *pos = p->pos;
    G4PtKey *key;
    union { u8 b; } prev; /* DEBT(TYPE): 1-byte union keeps QImode without PROMOTE_MODE zero-extend */

    pos->h0 += 0x200;
    key = &(*p->anim)->keys[pos->b2];
    if ((s16)pos->h0 >= key->dur) {
        pos->h0 -= key->dur;
        prev.b = pos->b2++;
        if (pos->b2 >= (*p->anim)->frames) {
            if (key->flags & 0x80) {
                pos->b2 = 0;
                pos->h0 = 0;
            } else {
                pos->b2 = prev.b;
                pos->h0 = 0;
            }
        }
    }
}

void func_0027F3A0(G4PtPlayer *p)
{
    G4PtAnim **anim = p->anim;
    G4Hb *pos = p->pos;
    G4PtKey *key = &(*anim)->keys[pos->b2];

    p->sub.b18 = 0;
    *(u8 **)((char *)p + 0x18) = 0; /* DEBT(CAST): scalar u8* store so D_006A3BCC load depends on it */
    p->sub.hC = 0x11;
    p->sub.p14 = D_006A3BCC;
    p->sub.h2 |= 0xB0;
    D_006A3BCC = (u8 *)func_002CD590((int)((char *)*anim + key->ofs), (int)&p->sub); /* DEBT(CAST): byte offset from anim base */
}

INCLUDE_ASM("build/ee_asm/game/particle/ke_27F2E8", KeLnsLp_Update);

void func_0027F928(void *p)
{
    WkM40fAC *w = p;

    func_002DD128(w->m40);
    w->fAC = 1.0f;
}

INCLUDE_ASM("build/ee_asm/game/particle/ke_27F2E8", func_0027F960);

INCLUDE_ASM("build/ee_asm/game/particle/ke_27F2E8", func_0027FC48);

void func_0027FD48(R6VObj *o) {
    o->w4 = 0;
    o->b9 = 0;
    o->vt = D_006EA450;
}

INCLUDE_ASM("build/ee_asm/game/particle/ke_27F2E8", func_0027FD60);

void func_0027FF00(R6VObj *o) {
    o->w4 = 0;
    o->vt = D_006EA450;
}

INCLUDE_ASM("build/ee_asm/game/particle/ke_27F2E8", func_0027FF18);

void func_00280150(AttachWork *w, DataRef **p) {
    w->cur = p;
    func_0027F2E8((R6Hb *)&w->h8, p); /* DEBT(CAST): sub-block at +8 */
}

void func_00280168(R6VObj *o) {
    o->w4 = 0;
    o->vt = D_006EA450;
}

INCLUDE_ASM("build/ee_asm/game/particle/ke_27F2E8", func_00280180);

void func_002803A8(R6VObj *o) {
    o->w4 = 0;
    o->vt = D_006EA450;
}
