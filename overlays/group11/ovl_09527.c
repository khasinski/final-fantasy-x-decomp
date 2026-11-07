/* EE Battle-Effect Overlay: group 0x11, file 09527
 * Load base: 0x01B00000, .text: 0x01B005F8..0x01B011D0 (9 functions)
 */
#include "../oef_overlay.h"

/* 64-bit constant loaded from overlay data via the assembler's "ld reg, sym" macro */
#define DK(sym) ({ register double _k __asm__("$5"); \
    __asm__ volatile (".set push\n\t.set noat\n\tlui $1, %%hi(" #sym ")\n\tld $5, %%lo(" #sym ")($1)\n\t.set pop" : "=r"(_k) : : "$1"); _k; })

extern u8 D_01B00040[];
extern int D_01B005E0;
extern int D_01B005E4;
extern int D_01B005E8;
extern char D_01B011D8[];
extern char D_01B011F0[];
extern int D_01B01230;
extern OefPartObj D_01B01240;
extern OefPartObj D_01B012C0;
extern OefPartObj D_01B01340;
extern OefPartObj D_01B013C0;
extern OefPartObj D_01B01440;
extern OefPartObj D_01B014C0;
extern OefHeapMgr D_01B01540;
extern int D_01B0156C;
extern void *D_01B01570;
extern int D_01B01574;
extern int D_01B01578;
extern int D_01B0157C;
extern int D_01B01580;
extern int D_01B01584;
extern int D_01B01588;
extern float D_01B01590[3];
extern float D_01B015A0[3];
extern OefHeapCfg D_01B015C0;
extern u8 D_01B06480[];
extern u8 D_01B06490[];
extern u8 D_01B86880[];

void _pppAllFreePObject(void *part);
void Ch_GetPos(void *chr, float *x, float *y, float *z);
void func_01B005F8(void *res);
void func_01B00790(OefPartObj *o, int bone, float dx);

void func_01B005F8(void *res)
{
    op_oef2_set2(res);
    func_002D02E8(res, 0, 1000, 0x100);
    op_oef2_sound_cue_multi(res, 0, 1000, 0x100);
}

int func_01B00640(int eff_id)
{
    D_01B01230 = eff_id;
    func_00266F40();
    func_002EF240(D_01B011D8);
    D_01B01570 = func_0013B150(20);
    func_002EF240(D_01B011F0, D_01B01570);
    func_01B005F8(D_01B06490);
    D_01B0156C = D_01B01574 = D_01B01578 = D_01B0157C = D_01B01580 = D_01B01584 = D_01B01588 = 0;
    return 0;
}

int func_01B006D8(void)
{
    return 0;
}

int func_01B006E0(void)
{
    return 0;
}

int func_01B006E8(void)
{
    float unused[20];

    if (D_01B005E0 == 0) {
        if (func_0029B830(D_01B01230) != 0) {
            return 0;
        }
        D_01B005E0++;
    }
    if (D_01B005E4 == 0) {
        D_01B005E4 = 1;
        MsEffectReady(D_01B01230, 0);
    }
    if (D_01B005E8 == 0) {
        if (MsEffectMotionLevel(D_01B01230) > 0) {
            D_01B005E8++;
        }
    }
    return 0;
}

void func_01B00790(OefPartObj *o, int bone, float dx)
{
    if (o->enabled != 0) {
        o->rotation[2] = 0;
        o->rotation[1] = 0;
        o->rotation[0] = 0;
        o->scale[2] = 0.25f;
        o->scale[1] = 0.25f;
        o->scale[0] = 0.25f;
        o->scale[3] = 1.0f;
        func_00107428(D_01B01570, bone, 0, o->position);
        o->position[0] -= dx;
        o->position[1] -= 4.0f;
        o->position[2] -= 6.0f;
        pppSetMatrix(o);
        func_002DCE38(D_006A39B0, D_006A3970, D_006A3930);
        func_002DCE38(D_006A3AB0, D_006A3A70, D_006A39B0);
        D_006A3924 = &D_01B01540;
        if (_pppRunPart(o, 0x30) != 0) {
            o->enabled = 0;
        }
    }
}

int func_01B008A8(void)
{
    float a[4];
    float b[4];
    OefPartObj *part;
    int pd;
    float x, y, z;

    if (D_01B005E8 == 0) {
        return 0;
    }
    if (D_01B0156C == 0) {
        _pppInitData(&D_01B015C0, D_01B00040);
        pppInitEnv(&D_01B01540, &D_01B015C0, D_01B06480, 0x80000);
    }
    if (Sg_GetCurExecFrames() == 0) {
        D_006A3BC4 = 1;
    } else {
        D_006A3BC4 = 0;
    }
    func_001AACA0(D_006A3A70);
    func_001A9EE0(D_006A3970);
    D_006A3BCC = D_01B86880;
    if (func_0014AA50(2) != 0) {
        if (D_01B0157C == 0 && D_01B01588 == 0) {
            D_006A3924 = &D_01B01540;
            _pppAllFreePObject(&D_01B01340);
            D_006A3924 = &D_01B01540;
            _pppStartPart(&D_01B013C0, 0x1000, D_01B015C0.pdt[0], 1);
            pd = D_01B015C0.pdt[4];
            D_01B013C0.enabled = 1;
            D_01B013C0.rotation[2] = 0;
            D_01B013C0.rotation[1] = 0;
            D_01B013C0.rotation[0] = 0;
            D_01B013C0.scale[2] = 0.1f;
            D_01B013C0.scale[1] = 0.1f;
            D_01B013C0.scale[3] = 1.0f;
            D_01B013C0.scale[0] = 0.1f;
            D_01B013C0.position[3] = 1.0f;
            D_006A3924 = &D_01B01540;
            _pppStartPart(&D_01B01440, 0x1000, pd, 1);
            D_01B01440.enabled = 1;
            D_01B01440.position[3] = 1.0f;
            D_006A3924 = &D_01B01540;
            _pppStartPart(&D_01B014C0, 0x1000, D_01B015C0.pdt[4], 1);
            D_01B014C0.enabled = 1;
            D_01B014C0.position[3] = 1.0f;
            D_01B01588 = 1;
        }
        part = &D_01B013C0;
        if (part->enabled != 0) {
            func_00107428(D_01B01570, 52, 0, a);
            func_00107428(D_01B01570, 58, 0, b);
            x = (a[0] + b[0]) * 0.5f;
            y = (a[1] + b[1]) * 0.5f;
            z = (a[2] + b[2]) * 0.5f;
            part->position[0] = x;
            part->position[1] = y;
            part->position[2] = z;
            pppSetMatrix(part);
            func_002DCE38(D_006A39B0, D_006A3970, D_006A3930);
            func_002DCE38(D_006A3AB0, D_006A3A70, D_006A39B0);
            D_006A3924 = &D_01B01540;
            if (_pppRunPart(part, 0x30) != 0) {
                part->enabled = 0;
            }
        }
        if (D_01B0157C >= 58) {
            func_01B00790(&D_01B01440, 12, -2.0f);
            func_01B00790(&D_01B014C0, 8, 2.0f);
        }
        if (D_006A3BC4 == 0) {
            D_01B0157C++;
        }
    } else if (func_0014AA50(1) != 0) {
        if (D_01B01578 == 0 && D_01B01584 == 0) {
            D_006A3924 = &D_01B01540;
            _pppAllFreePObject(&D_01B01240);
            D_006A3924 = &D_01B01540;
            _pppAllFreePObject(&D_01B012C0);
            func_00107428(D_01B01570, 21, 0, D_01B015A0);
            D_006A3924 = &D_01B01540;
            _pppStartPart(&D_01B01340, 0x1000, D_01B015C0.pdt[1], 1);
            D_01B01340.enabled = 1;
            D_01B01340.rotation[2] = 0;
            D_01B01584++;
            D_01B01340.rotation[0] = 0;
            D_01B01340.scale[2] = 0.13333334f;
            D_01B01340.scale[1] = 0.13333334f;
            D_01B01340.rotation[1] = -8192;
            D_01B01340.scale[3] = 1.0f;
            D_01B01340.scale[0] = 0.13333334f;
            D_01B01340.position[0] = D_01B015A0[0] - 6.0f;
            D_01B01340.position[1] = D_01B015A0[1];
            D_01B01340.position[2] = D_01B015A0[2] - 2.0f;
            D_01B01340.position[3] = 1.0f;
        }
        if (D_01B01578 >= 10) {
            part = &D_01B01340;
            if (part->enabled != 0) {
                pppSetMatrix(part);
                func_002DCE38(D_006A39B0, D_006A3970, D_006A3930);
                func_002DCE38(D_006A3AB0, D_006A3A70, D_006A39B0);
                D_006A3924 = &D_01B01540;
                if (_pppRunPart(part, 0x30) != 0) {
                    part->enabled = 0;
                }
            }
        }
        if (D_006A3BC4 == 0) {
            D_01B01578++;
        }
    } else if (func_0014AA50(0) != 0) {
        if (D_01B01574 <= 80) {
            if (D_01B01574 == 0 && D_01B01580 == 0) {
                Ch_GetPos(D_01B01570, &D_01B01590[0], &D_01B01590[1], &D_01B01590[2]);
                D_006A3924 = &D_01B01540;
                _pppStartPart(&D_01B01240, 0x1000, D_01B015C0.pdt[2], 1);
                D_006A3924 = &D_01B01540;
                pd = D_01B015C0.pdt[3];
                D_01B01240.position[3] = 1.0f;
                D_01B01240.enabled = 1;
                D_01B01240.rotation[2] = 0;
                D_01B01240.rotation[1] = 0;
                D_01B01240.rotation[0] = 0;
                D_01B01240.scale[2] = 0.0800000057f;
                D_01B01240.scale[1] = 0.0800000057f;
                D_01B01240.scale[3] = 1.0f;
                D_01B01240.scale[0] = 0.0800000057f;
                _pppStartPart(&D_01B012C0, 0x1000, pd, 1);
                D_01B012C0.rotation[1] = 16384;
                D_01B012C0.rotation[2] = 0;
                D_01B012C0.rotation[0] = 0;
                D_01B012C0.scale[2] = 0.0779999942f;
                D_01B012C0.scale[1] = 0.0779999942f;
                D_01B012C0.scale[0] = 0.0779999942f;
                D_01B012C0.scale[3] = 1.0f;
                D_01B012C0.enabled = 1;
                D_01B012C0.position[0] = D_01B01590[0] - 17.399979f - 10.628233f + DK(D_01B01200) + DK(D_01B01208) + DK(D_01B01210);
                D_01B012C0.position[1] = D_01B01590[1] - 31.336260f + 0.19133700f + 9.9999914f + DK(D_01B01218) + DK(D_01B01220);
                D_01B01580 = 1;
                D_01B012C0.position[3] = 1.0f;
                D_01B012C0.position[2] = D_01B01590[2] - 20.799959f - 5.9981050f + 5.8668389f + 8.3676453f - 3.8651199f;
            }
            part = &D_01B01240;
            if (part->enabled != 0) {
                func_00107428(D_01B01570, 14, 0, part->position);
                part->position[0] += -1.0f;
                part->position[1] += -3.0f;
                part->position[2] += -2.0f;
                pppSetMatrix(part);
                func_002DCE38(D_006A39B0, D_006A3970, D_006A3930);
                func_002DCE38(D_006A3AB0, D_006A3A70, D_006A39B0);
                D_006A3924 = &D_01B01540;
                if (_pppRunPart(part, 0x30) != 0) {
                    part->enabled = 0;
                }
            }
            if (D_01B01574 >= 60) {
                part = &D_01B012C0;
                if (part->enabled != 0) {
                    pppSetMatrix(part);
                    func_002DCE38(D_006A39B0, D_006A3970, D_006A3930);
                    func_002DCE38(D_006A3AB0, D_006A3A70, D_006A39B0);
                    D_006A3924 = &D_01B01540;
                    if (_pppRunPart(part, 0x30) != 0) {
                        part->enabled = 0;
                    }
                }
            }
        }
        if (D_006A3BC4 == 0) {
            D_01B01574++;
        }
    }
    if (D_01B0157C == 140) {
        MsEffectTerminate(D_01B01230);
    }
    D_01B0156C++;
    return 0;
}

int func_01B011C0(void)
{
    return 0;
}

void func_01B011C8(void)
{
}
