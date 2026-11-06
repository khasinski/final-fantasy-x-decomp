/* EE Battle-Effect Overlay: group 0x11, file 09385
 * Load base: 0x01B00000, .text: 0x01B00698..0x01B01220 (11 functions)
 */
#include "../oef_overlay.h"
#include "vu0.h"

typedef struct V3 { float x, y, z; } V3;
extern u8 D_01B00040[];
extern int D_01B0063C;
extern int D_01B00640;
extern int D_01B00644;
extern void *D_01B00630[];
extern V3 D_01B00650;
extern V3 D_01B00660;
extern V3 D_01B00670;
extern V3 D_01B00680;
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
extern void *D_01B01574;
extern int D_01B01578;
extern int D_01B0157C;
extern int D_01B01580;
extern int D_01B01584;
extern int D_01B01588;
extern int D_01B0158C;
extern int D_01B01590;
extern int D_01B01594;
extern float D_01B015C0[16];
extern OefHeapCfg D_01B01610;
extern u8 D_01B18910[];
extern u8 D_01B18920[];
extern u8 D_01B98D10[];

void func_00110220(void *chr, float *x, float *y, float *z);
void func_0026BE48(float *mtx, int angle);
void func_00268610(void *o, void *a1, int a2);
void func_001CDDD8(int eff_id);

#define ROW_SCALE(row, ki) \
    __asm__ volatile("qmtc2 %1, $vf9\n\tlqc2 $vf10, 0(%0)\n\tvmulx.xyz $vf10, $vf10, $vf9x\n\tsqc2 $vf10, 0(%0)" \
                     : : "r"(row), "r"(ki) : "memory")

void func_01B00698(OefPartObj *o, int id,
    float x, float y, float z, float rx, float ry, float rz,
    float sx, float sy, float sz)
{
    D_006A3924 = &D_01B01540;
    _pppStartPart(o, 0x1000, D_01B01610.pdt[id], 1);
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

void func_01B007A8(OefPartObj *o)
{
    if (o->enabled != 0) {
        pppSetMatrix(o);
        func_002DCE38(D_006A39B0, D_006A3970, D_006A3930);
        func_002DCE38(D_006A3AB0, D_006A3A70, D_006A39B0);
        D_006A3924 = &D_01B01540;
        if (_pppRunPart(o, 0x30) != 0) {
            o->enabled = 0;
        }
    }
}

void func_01B00840(void *res)
{
    op_oef2_set2(res);
    func_002D02E8(res, 0, 1000, 0x100);
    op_oef2_sound_cue_multi(res, 0, 1000, 0x100);
}

int func_01B00888(int eff_id)
{
    D_01B01230 = eff_id;
    func_00266F40();
    D_01B01570 = func_0013B150(7);
    D_01B01574 = func_0013B150(20);
    func_01B00840(D_01B18920);
    D_01B0156C = D_01B01578 = D_01B0157C = D_01B01580 = D_01B01588 = D_01B0158C = D_01B01590 = 0;
    return 0;
}

int func_01B00910(void)
{
    return 0;
}

int func_01B00918(void)
{
    return 0;
}

int func_01B00920(void)
{
    u8 pad[0x50];

    if (D_01B0063C == 0) {
        if (func_0029B830(D_01B01230) != 0) {
            return 0;
        }
        D_01B0063C++;
    }
    if (D_01B00640 == 0) {
        D_01B00640 = 1;
        MsEffectReady(D_01B01230, 0);
    }
    if (D_01B00644 == 0) {
        if (MsEffectMotionLevel(D_01B01230) <= 0) {
            return 0;
        }
        D_01B00644++;
    }
    return 0;
}

void func_01B009C8(u8 *obj)
{
    float a[4];
    float b[4];
    float *out = (float *)(obj + 0xA0);

    func_00107428(D_01B01574, 19, 0, a);
    func_00107428(D_01B01574, 35, 0, b);
    a[0] = (a[0] + b[0]) * 0.5f;
    a[1] = (a[1] + b[1]) * 0.5f;
    a[2] = (a[2] + b[2]) * 0.5f;
    a[3] = 1.0f;
    func_002DCE08(out, D_01B015C0, a);
}

int func_01B00A80(void)
{
    if (D_01B00644 == 0) {
        return 0;
    }
    if (D_01B0156C == 0) {
        _pppInitData(&D_01B01610, D_01B00040);
        pppInitEnv(&D_01B01540, &D_01B01610, D_01B18910, 0x80000);
    }
    if (Sg_GetCurExecFrames() == 0) {
        D_006A3BC4 = 1;
    } else {
        D_006A3BC4 = 0;
    }
    func_001AACA0(D_006A3A70);
    func_001A9EE0(D_006A3970);
    D_006A3BCC = D_01B98D10;
    if (func_0014AA50(4)) {
        float a[4];
        float b[4];
        if (D_01B01584 == 0 && D_01B01594 == 0) {
            func_01B00698(&D_01B014C0, 1, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.121998f, 0.121998f, 0.121998f);
            D_01B01594 = 1;
        }
        func_00107428(D_01B01574, 19, 0, a);
        func_00107428(D_01B01574, 35, 0, b);
        D_01B014C0.position[0] = (a[0] + b[0]) * 0.5f + D_01B00670.x;
        D_01B014C0.position[1] = (a[1] + b[1]) * 0.5f + D_01B00670.y;
        D_01B014C0.position[2] = (a[2] + b[2]) * 0.5f + D_01B00670.z;
        func_01B007A8(&D_01B014C0);
        func_01B007A8(&D_01B01340);
        if (D_006A3BC4 == 0) {
            D_01B01584++;
        }
    } else if (func_0014AA50(3)) {
        if (D_01B01580 == 0 && D_01B01590 == 0) {
            func_01B00698(&D_01B01440, 5, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.45f, 0.45f, 0.45f);
            D_01B00630[2] = func_01B009C8;
            D_01B01590 = 1;
        }
        func_00107428(D_01B01570, 35, 0, D_01B01340.position);
        D_01B01340.position[0] += D_01B00650.x;
        D_01B01340.position[1] += D_01B00650.y;
        D_01B01340.position[2] += D_01B00650.z;
        func_00107428(D_01B01570, 35, 0, D_01B01440.position);
        D_01B01440.position[0] += D_01B00660.x;
        D_01B01440.position[1] += D_01B00660.y;
        D_01B01440.position[2] += D_01B00660.z;
        func_0026BE48(D_01B015C0, -D_01B01440.rotation[1]);
        {
            float inv;
            float *r;
            register int ki __asm__("$2");
            register int kj __asm__("$3");
            inv = 1.0f / D_01B01440.scale[0];
            MIPS_MFC1(ki, inv);
            ROW_SCALE(&D_01B015C0[0], ki);
            D_01B015C0[12] = -D_01B01440.position[0] * inv;
            r = &D_01B015C0[4];
            inv = 1.0f / D_01B01440.scale[1];
            MIPS_MFC1(kj, inv);
            ROW_SCALE(r, kj);
            D_01B015C0[13] = -D_01B01440.position[1] * inv;
            r = &D_01B015C0[8];
            inv = 1.0f / D_01B01440.scale[2];
            MIPS_MFC1(kj, inv);
            ROW_SCALE(r, kj);
            D_01B015C0[14] = -D_01B01440.position[2] * inv;
        }
        func_00268610(&D_01B01440, D_01B00630, 0);
        func_01B007A8(&D_01B01440);
        func_01B007A8(&D_01B01340);
        func_01B007A8(&D_01B012C0);
        if (D_006A3BC4 == 0) {
            D_01B01580++;
        }
    } else if (func_0014AA50(2)) {
        if (D_01B0157C == 0 && D_01B0158C == 0) {
            func_01B00698(&D_01B012C0, 2, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.03f, 0.03f, 0.03f);
            func_00110220(D_01B01570, &D_01B012C0.position[0], &D_01B012C0.position[1], &D_01B012C0.position[2]);
            func_01B00698(&D_01B01340, 3, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.03f, 0.03f, 0.03f);
            func_01B00698(&D_01B013C0, 4, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.038f, 0.038f, 0.038f);
            D_01B0158C = 1;
        }
        if (D_01B0157C >= 20) {
            func_01B007A8(&D_01B012C0);
        }
        if (D_01B0157C >= 70) {
            func_00107428(D_01B01570, 35, 0, D_01B013C0.position);
            D_01B013C0.position[0] += D_01B00680.x;
            D_01B013C0.position[1] += D_01B00680.y;
            D_01B013C0.position[2] += D_01B00680.z;
            func_01B007A8(&D_01B013C0);
        }
        if (D_01B0157C >= 80) {
            func_00107428(D_01B01570, 35, 0, D_01B01340.position);
            D_01B01340.position[0] += D_01B00650.x;
            D_01B01340.position[1] += D_01B00650.y;
            D_01B01340.position[2] += D_01B00650.z;
            func_01B007A8(&D_01B01340);
        }
        func_01B007A8(&D_01B01240);
        if (D_006A3BC4 == 0) {
            D_01B0157C++;
        }
    } else if (func_0014AA50(1)) {
        if (D_01B01578 == 0 && D_01B01588 == 0) {
            func_01B00698(&D_01B01240, 0, -60.875988f, -10.102066f, -56.469658f, 0.0f, 0.0f, 0.0f, 0.073f, 0.073f, 0.073f);
            D_01B01588 = 1;
        }
        func_01B007A8(&D_01B01240);
        if (D_006A3BC4 == 0) {
            D_01B01578++;
        }
    }
    if (D_01B01584 == 50) {
        func_001CDDD8(D_01B01230);
    }
    if (D_006A3BC4 == 0) {
        D_01B0156C++;
    }
    return 0;
}

int func_01B01210(void)
{
    return 0;
}

void func_01B01218(void)
{
}
