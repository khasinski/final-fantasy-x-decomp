/* EE Battle-Effect Overlay: group 0x11, file 09543
 * Load base: 0x01B00000, .text: 0x01B00450..0x01B00C58 (2056 bytes, 12 functions)
 */
#include "../oef_overlay.h"

typedef struct OefChrPartGroup {
    void *chr;             /* 0x000 */
    int pad04[3];          /* 0x004 */
    OefPartObj parts[5];   /* 0x010..0x290 */
} OefChrPartGroup;

extern u8 D_01B00040[];
extern int D_01B00428[5];
extern int D_01B0043C;
extern int D_01B00440;
extern int D_01B00444;
extern int D_01B00C60;
extern OefHeapMgr D_01B00C68;
extern OefChrPartGroup D_01B00CA0[2];
extern int D_01B011C0;
extern int D_01B011C4;
extern int D_01B011C8;
extern OefHeapCfg D_01B011E0;
extern u8 D_01B03650[];
extern u8 D_01B03660[];
extern u8 D_01B83A50[];

void func_01B00450(OefPartObj *o, int id,
    float x, float y, float z, float rx, float ry, float rz,
    float sx, float sy, float sz)
{
    D_006A3924 = &D_01B00C68;
    _pppStartPart(o, 0x1000, D_01B011E0.pdt[id], 1);
    o->rotation[0] = (int)rx;
    o->rotation[1] = (int)ry;
    o->position[0] = x;
    o->rotation[2] = (int)rz;
    o->position[1] = y;
    o->position[2] = z;
    o->scale[0] = sx;
    o->scale[1] = sy;
    o->scale[2] = sz;
    o->position[3] = 1.0f;
    o->enabled = 1;
    o->flag5C = 1;
    o->scale[3] = 1.0f;
}

void func_01B00560(OefPartObj *o)
{
    if (o->enabled != 0) {
        pppSetMatrix(o);
        func_002DCE38(D_006A39B0, D_006A3970, D_006A3930);
        func_002DCE38(D_006A3AB0, D_006A3A70, D_006A39B0);
        D_006A3924 = &D_01B00C68;
        if (_pppRunPart(o, 0x30) != 0) {
            o->enabled = 0;
        }
    }
}

void func_01B005F8(void *res)
{
    op_oef2_set2(res);
    func_002D02E8(res, 0, 1000, 0x100);
}

void func_01B00630(OefChrPartGroup *grp, int chr_id)
{
    int i;

    grp->chr = func_0013B150(chr_id);
    for (i = 0; i < 5; i++) {
        grp->parts[i].enabled = 0;
    }
}

void func_01B00688(OefChrPartGroup *grp)
{
    float m0[4][4];
    float m1[4][4];
    float unused[4];
    OefPartObj *part;
    OefHeapMgr *heap;
    int i;

    for (i = 0; i < 5; i++) {
        part = &grp->parts[i];
        if (part->enabled != 0) {
            if (i < 3) {
                func_001072F8(grp->chr, D_01B00428[i], m0);
                m0[3][0] = m0[3][1] = m0[3][2] = 0.0f;
                m0[3][3] = 1.0f;
                func_0026BDE0(m1, 0x8000);
                func_002DCE38(m0, m0, m1);
                func_002DD068(&D_006A3930[0], m0[0], part->scale[0]);
                func_002DD068(&D_006A3930[16], m0[1], part->scale[1]);
                func_002DD068(&D_006A3930[32], m0[2], part->scale[2]);
                func_00107428(grp->chr, D_01B00428[i], 0, &D_006A3930[48]);
                func_002DCE38(D_006A39B0, D_006A3970, D_006A3930);
                heap = &D_01B00C68;
                func_002DCE38(D_006A3AB0, D_006A3A70, D_006A39B0);
                D_006A3924 = heap;
                if (_pppRunPart(part, 0x30) != 0) {
                    part->enabled = 0;
                }
            } else {
                func_00107428(grp->chr, D_01B00428[i], 0, part->position);
                func_01B00560(part);
            }
        }
    }
}

int func_01B00850(int eff_id)
{
    D_01B00C60 = eff_id;
    func_00266F40();
    func_01B00630(&D_01B00CA0[0], 20);
    func_01B00630(&D_01B00CA0[1], 21);
    func_01B005F8(D_01B03660);
    D_01B011C0 = D_01B011C4 = D_01B011C8 = 0;
    return 0;
}

int func_01B008C0(void)
{
    return 0;
}

int func_01B008C8(void)
{
    return 0;
}

int func_01B008D0(void)
{
    float unused[20];
    OefChrPartGroup *grp;
    int i;

    if (D_01B0043C == 0) {
        if (func_0029B830(D_01B00C60) != 0) {
            return 0;
        }
        D_01B0043C++;
    }
    if (D_01B00440 == 0) {
        D_01B00440 = 1;
        MsEffectReady(D_01B00C60, 0);
    }
    if (D_01B00444 == 0) {
        if (MsEffectMotionLevel(D_01B00C60) <= 0) {
            return 0;
        }
        D_01B00444++;
    }
    if (D_01B011C4 == 0) {
        D_01B011C4 = 1;
        _pppInitData(&D_01B011E0, D_01B00040);
        pppInitEnv(&D_01B00C68, &D_01B011E0, D_01B03650, 0x80000);
    }
    if (func_0014AA50(0) != 0) {
        if (D_006A3BC4 != 0) {
            return 0;
        }
        D_01B011C8++;
    }
    if (D_006A3BC4 != 0) {
        return 0;
    }
    if (D_01B011C8 == 1) {
        grp = D_01B00CA0;
        for (i = 0; i < 2; i++, grp++) {
            func_01B00450(&grp->parts[0], 0, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.16f, 0.16f, 0.16f);
            func_01B00450(&grp->parts[1], 0, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.16f, 0.16f, 0.16f);
            func_01B00450(&grp->parts[2], 0, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.16f, 0.16f, 0.16f);
        }
    } else if (D_01B011C8 == 30) {
        grp = D_01B00CA0;
        for (i = 0; i < 2; i++, grp++) {
            func_01B00450(&grp->parts[3], 1, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.05f, 0.05f, 0.05f);
            func_01B00450(&grp->parts[4], 1, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.05f, 0.05f, 0.05f);
        }
    } else if (D_01B011C8 == 100) {
        MsEffectTerminate(D_01B00C60);
    }
    return 0;
}

int func_01B00B98(void)
{
    if (D_01B00444 == 0) {
        return 0;
    }
    if (Sg_GetCurExecFrames() == 0) {
        D_006A3BC4 = 1;
    } else {
        D_006A3BC4 = 0;
    }
    func_001AACA0(D_006A3A70);
    func_001A9EE0(D_006A3970);
    D_006A3BCC = D_01B83A50;
    func_01B00688(&D_01B00CA0[0]);
    func_01B00688(&D_01B00CA0[1]);
    if (D_006A3BC4 == 0) {
        D_01B011C0++;
    }
    return 0;
}

int func_01B00C48(void)
{
    return 0;
}

void func_01B00C50(void)
{
}
