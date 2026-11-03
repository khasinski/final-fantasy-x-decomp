#include "p6_overlay.h"

/* F14 (docs/overlay-families.tsv): effect target-list setup, linked into 116 containers.
 * The TU starts with func_01B02898 (a switch on func_001B4E18(id) - 4209 with a 28-entry
 * .rodata jump table at D_01B0CC20, else MsGetChrFly(id) != 0); it is left out of this unit
 * because verify_overlays.py links .text only and discards .rodata, so the jump-table
 * reference cannot be relocated. This unit starts at the second function. */

typedef struct P6NodeArg {
    void *node;
    int flag;
} P6NodeArg;

extern int D_01B00040;
extern int D_01B004DC;
extern int D_01B004E0;
extern int D_01B004E4;
extern float D_01B004E8;
extern u8 D_01B004F0[];
extern float D_01B00500[][4];
extern P6Node30 D_01B00600;
extern P6Node30 D_01B00630;
extern P6RotNode30 D_01B00660;
extern P6Obj150 D_01B00690;
extern u8 D_01B007E0[];
extern u8 D_01B00820[];
extern u8 D_01B00860[];

void func_01B07610(P6NodeArg *arg);
void func_01B07AE0(P6NodeArg *arg);
void func_01B08798(P6LinkArg *arg);

void func_01B028F8(void)
{
    int i;
    float *pos = D_01B00500[0];

    for (i = 0; i < D_01B004E4; i++) {
        MsGetChrBtlPos(D_01B004F0[i], pos);
        pos[3] = 1.0f;
        pos += 4;
    }
}

void func_01B02980(void)
{
    P6NodeArg arg;
    P6LinkArg link;
    P6LinkArg *lp; /* DEBT(FAKE): fields 0x0C..0x14 are stored through a separate pointer register */

    arg.node = &D_01B00600;
    arg.flag = 0;
    func_01B07610(&arg);
    D_01B00600.v.x = 0.0f;
    D_01B00600.v.w = 1.0f;
    D_01B00600.v.y = 0.0f;
    D_01B00600.v.z = 0.0f;

    arg.node = &D_01B00660;
    arg.flag = 0;
    func_01B07AE0(&arg);
    D_01B00660.v.x = 0;
    D_01B00660.v.y = 0;
    D_01B00660.v.z = 0;

    arg.node = &D_01B00630;
    arg.flag = 0;
    func_01B07610(&arg);
    D_01B00630.v.x = 1.0f;
    D_01B00630.v.y = 1.0f;
    D_01B00630.v.z = 1.0f;
    D_01B00630.v.w = 1.0f;

    lp = &link;
    link.obj = &D_01B00690;
    lp->n0 = &D_01B00600;
    lp->n1 = &D_01B00660;
    lp->n2 = &D_01B00630;
    link.a = 0;
    link.parent = 0;
    func_01B08798(lp);
}

void func_01B02A60(int id)
{
    float pos[4];
    u8 *list;
    int i;

    D_01B004DC = id;
    D_01B004E0 = MsGetEff2Chr(id);
    list = MsGetTargetList(D_01B004DC, &D_01B004E4);
    for (i = 0; i < D_01B004E4; i++) {
        D_01B004F0[i] = list[i];
    }
    func_01B028F8();
    MsGetChrBtlPos(D_01B004E0, pos);
    D_01B004E8 = MsGetChrGround(D_01B004E0);
    func_01B02980();
}

void func_01B02B28(int id)
{
    D_01B004DC = id;
    func_01B02980();
}

void func_01B02B38(void)
{
    func_001AACA0(D_01B00820);
    func_001A9EE0(D_01B007E0);
    func_002DCE38(D_01B00860, D_01B00820, D_01B007E0);
    func_002DD0C0(D_006A3A70, D_01B00820);
    func_002DD0C0(D_006A3970, D_01B007E0);
    if (Sg_GetCurExecFrames() == 0) {
        D_006A3BC4 = 1;
        D_01B00040 = 1;
    } else {
        D_006A3BC4 = 0;
        D_01B00040 = 0;
    }
}
