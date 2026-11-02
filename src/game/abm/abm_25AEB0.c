/* tu_283 0x25aeb0-0x260a70: low; unk_25AEB0 (config/tu_map.tsv) */
#include "common.h"
#include "ffx/w8.h"
#include "ffx/q6.h"
#include "ffx/s6.h"
#include "ffx/t6.h"
#include "ffx/u4.h"
#include "ffx/v6.h"
#include "ffx/g4.h"

void func_0025AEB0(ChrWork *chr)
{
    D_006A391C = chr;
    func_00256408(chr, 0, 0x9C2);
    D_006A391C[12].a.req.id = -1;
}

/* DEBT(NAME): sets up list window slot: cols in 16-pixel units, rows of 20 pixels */
void func_0025AEF0(int slot, int x, int y, int cols, int rows, int b, int wide, int c,
                   void (*fn)(ChrWork *w, ChrSub *sub, int idx, int x, int y), int arg)
{
    ChrWork *w = &D_006A391C[slot];

    w->rect1[1] = y;
    w->rect1[0] = x;
    w->rect1[2] = cols << 4;
    if (wide) {
        w->rect1[0] = x + 0x20;
        w->rect1[2] = (cols << 4) + 0x20;
    }
    /* DEBT(ORDER): store order chosen to reproduce the schedule */
    w->a.rect[0] = w->rect1[0];
    w->rect1[3] = rows * 20;
    w->a.rect[1] = w->rect1[1];
    w->f16 = rows;
    w->a.rect[2] = w->rect1[2];
    w->f14 = cols;
    w->f1E = 0;
    w->a.rect[3] = rows * 20;
    w->f18 = 0;
    w->f1A = 0;
    w->f12 = rows;
    w->f23 = 0;
    w->f10 = cols;
    w->f25 = 0;
    w->f26 = 0;
    w->f20 = c;
    w->f22 = b;
    w->f38 = fn;
    w->f24 = 0;
    w->f28 = 0;
    w->f3C = arg;
    w->f34 = 0;
}

void func_0025AFA0(int i) {
    ChrWork *w = D_006A391C + i;

    w->f23 = 1;
}

void func_0025AFC0(int slot)
{
    ChrWork *chr = &D_006A391C[slot];

    chr->f23 = 0;
}

ChrSub *func_0025AFE0(int slot)
{
    ChrWork *chr = &D_006A391C[slot];

    return &chr->sub[chr->f18];
}

ChrWork *func_0025B010(int slot, void (*fn)(void))
{
    ChrWork *chr = &D_006A391C[slot];

    chr->f23 = 1;
    chr->f25 = 1;
    chr->f24 = 3;
    D_006A391C[12].a.req.id = slot;
    D_006A391C[12].a.req.fn = fn;
    return chr;
}

T6_MenuEnt *func_0025B050(int slot, int id, int arg)
{
    ChrWork *w = &D_006A391C[slot];
    T6_MenuEnt *e;

    if (w->f1E >= 64) {
        func_002EF240(D_005739D0, 64);
        func_002EA328(0);
    } else {
        e = (T6_MenuEnt *)&w->sub[w->f1E++]; /* DEBT(CAST): see T6_MenuEnt */
        if ((s16)w->f16 * w->f22 < w->f1E) {
            w->f28 = 1;
        } else {
            w->f28 = 0;
        }
        e->id = id;
        e->arg = arg;
        e->off = 0;
        return e;
    }
}

void func_0025B108(void)
{
    ChrWork *chr = D_006A391C;
    int n = 12;

    do {
        if (chr->f34 != 0) {
            chr->f34(chr);
        }
        chr++;
    } while (--n != 0);
}

INCLUDE_ASM("build/ee_asm/game/abm/abm_25AEB0", func_0025B160);

void func_0025B4E0(ChrWork *w, int top, int ofs)
{
    u8 *start = D_006A3BCC;
    u8 *end;

    ofs += 12;
    end = func_001FE2F8(start + 0x10, 0, (s16)w->rect1[0] + ofs, (s16)w->rect1[1] + (w->f18 - top) * 20 + 8); /* DEBT(CAST): rect1 is u16 in types.h */
    D_006A3BCC = end;
    func_002B2A80(start, (end - start) >> 4, 1, 0);
}

INCLUDE_ASM("build/ee_asm/game/abm/abm_25AEB0", func_0025B558);

INCLUDE_ASM("build/ee_asm/game/abm/abm_25AEB0", func_0025B6E8);
INCLUDE_RODATA("build/ee_asm/game/abm/abm_25AEB0/rodata", jtbl_00573A10);

INCLUDE_ASM("build/ee_asm/game/abm/abm_25AEB0", func_0025BE90);

void func_0025C2B0(void) {
    int out;
    Pt16 *t = func_00256F08(lpamng->ents[lpamng->ents3[7].h0].f06, &out);

    func_00257288(func_00256F58(out, t + 2));
}

void func_0025C308(void)
{
    func_0025C2B0();
}

void func_0025C310(void)
{
    func_0025C2B0();
}

void func_0025C318(void)
{
    if (lpamng->cb_b != 0) {
        lpamng->cb_b();
    }
}

INCLUDE_ASM("build/ee_asm/game/abm/abm_25AEB0", func_0025C350);

INCLUDE_ASM("build/ee_asm/game/abm/abm_25AEB0", func_0025CB68);

INCLUDE_ASM("build/ee_asm/game/abm/abm_25AEB0", func_0025CD18);

INCLUDE_ASM("build/ee_asm/game/abm/abm_25AEB0", func_0025D050);

T6_AbmDrawWork *func_0025D750(int abe, int z)
{
    T6_AbmDrawWork *w = (T6_AbmDrawWork *)func_002B3888(sizeof(T6_AbmDrawWork));

    func_002565C8();
    w->abe = abe;
    w->z = z;
    w->v[0].z = w->v[1].z = w->v[2].z = 0.0f;
    w->v[0].w = w->v[1].w = w->v[2].w = 1.0f;
    return w;
}

void func_0025D7C8(void) {
    func_00256608();
    func_002B39C0(0x1F0);
}

INCLUDE_ASM("build/ee_asm/game/abm/abm_25AEB0", func_0025D7E8);

INCLUDE_ASM("build/ee_asm/game/abm/abm_25AEB0", func_0025DFD0);

INCLUDE_ASM("build/ee_asm/game/abm/abm_25AEB0", func_0025E950);

INCLUDE_ASM("build/ee_asm/game/abm/abm_25AEB0", func_0025EDA0);

INCLUDE_ASM("build/ee_asm/game/abm/abm_25AEB0", func_0025EFC0);

INCLUDE_ASM("build/ee_asm/game/abm/abm_25AEB0", func_0025F2A0);

INCLUDE_ASM("build/ee_asm/game/abm/abm_25AEB0", func_0025F770);

INCLUDE_ASM("build/ee_asm/game/abm/abm_25AEB0", func_0025F898);

INCLUDE_ASM("build/ee_asm/game/abm/abm_25AEB0", func_002600F8);

INCLUDE_ASM("build/ee_asm/game/abm/abm_25AEB0", func_00260370);

void func_00260600(void)
{
    D_006A3510 = *(V6GsPkt *)&D_006F2CE0; /* DEBT(CAST): t6.h only describes the start of the environment */
    func_002B2A28(&D_006A3510, 11, 1, 0);
}

INCLUDE_ASM("build/ee_asm/game/abm/abm_25AEB0", func_00260670);

void func_002606E0(void)
{
    V6GsPkt *p = (V6GsPkt *)D_006A3BCC;

    D_006A3BCC += sizeof(V6GsPkt);
    *p = *(V6GsPkt *)&D_006F2CE0; /* DEBT(CAST): t6.h only describes the start of the environment */
    func_002B2A80(p, 11, 1, 0);
}

INCLUDE_ASM("build/ee_asm/game/abm/abm_25AEB0", func_00260758);

INCLUDE_ASM("build/ee_asm/game/abm/abm_25AEB0", func_002607D8);

void func_00260930(void) {
    float f = lpamng->f11598;

    if (f != 1.0f) {
        func_002607D8((int)((1.0f - f) * 128.0f), 0x4300);
    }
}

void func_00260980(void)
{
    D_006A3BCC = (u8 *)0x01F20000;
    func_00260600();
    func_00260670();
    func_0025EDA0();
    func_0025EFC0();
    func_002D02E8(D_006A38F8, 0, 1, 0x100);
    func_002D05F0(0x100);
    func_0025C350();
    func_002D02E8(D_006A38F8, 2, 2, 0x100);
    func_002D05F0(0x100);
    func_0025CD18();
    func_0025F770();
    func_0025E950();
    func_0025F2A0();
    func_0025D050();
    func_0025CB68();
    func_00260930();
    func_00260370();
    func_0025F898();
    if (D_006A391C[12].a.req.id < 0) {
        func_0025C318();
    }
    func_0025BE90();
}
