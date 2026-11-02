/* EE Battle-Effect Overlay: group 0x11, file 09746
 * Load base: 0x01B00000, .text: 0x01B00508..0x01B00B00 (1528 bytes, 10 functions)
 */
#include "../oef_overlay.h"

extern u8 D_01B00040[];
extern int D_01B004F0;
extern int D_01B004F4;
extern int D_01B004F8;
extern int D_01B00B40;
extern void *D_01B00B44;
extern OefPartObj D_01B00B50;
extern OefHeapMgr D_01B00BD0;
extern u8 D_01B00C00[];
extern u8 D_01C00C00[];
extern int D_01D00C00;
extern int D_01D00C04;
extern int D_01D00C08;
extern void *D_01D00C0C;
extern void *D_01D00C10;
extern void *D_01D00C30;
extern OefHeapCfg D_01D00C50;
extern u8 D_01D1E710[];

void func_01B00508(void *res)
{
    void **p = &D_01B00B44;

    op_oef2_set2(res);
    func_002D02E8(res, 0, 1000, 0x100);
    op_oef2_sound_cue_multi(res, 0, 1000, 0x100);
    *p = op_oef2_a_get(res, 6, 0);
}

void func_01B00578(OefPartObj *o, int id,
    float x, float y, float z, float rx, float ry, float rz,
    float sx, float sy, float sz)
{
    D_006A3924 = &D_01B00BD0;
    _pppStartPart(o, 0x1000, D_01D00C50.pdt[id], 1);
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

void func_01B00688(OefPartObj *o)
{
    if (o->enabled != 0) {
        pppSetMatrix(o);
        func_002DCE38(D_006A39B0, D_006A3970, D_006A3930);
        func_002DCE38(D_006A3AB0, D_006A3A70, D_006A39B0);
        D_006A3924 = &D_01B00BD0;
        if (_pppRunPart(o, 0x30) != 0) {
            o->enabled = 0;
        }
    }
}

int func_01B00720(int eff_id)
{
    u8 target_buf[16];
    int size;
    void **p30 = &D_01D00C30;

    D_01B00B40 = eff_id;
    D_01D00C04 = MsGetEff2Chr(eff_id);
    D_01D00C08 = *MsGetTargetList(D_01B00B40, target_buf);
    D_01D00C0C = MsGetChrHandle(D_01D00C04);
    D_01D00C10 = MsGetChrHandle(D_01D00C08);
    D_01D00C00 = -1;
    func_01B00508(D_01D1E710);
    _pppInitData(&D_01D00C50, D_01B00040);
    pppInitEnv(&D_01B00BD0, &D_01D00C50, D_01B00C00, 0x100000);
    func_01B00578(&D_01B00B50, 1, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.04f, 0.04f, 0.04f);
    Ch_OptposGet(D_01D00C10, 16, D_01B00B50.position);
    D_01B00B50.position[3] = 1.0f;
    Ch_ClutCreate(D_01D00C10);
    size = op_chara_hsv_size_get(D_01D00C10);
    *p30 = pppMemAlloc(&D_01B00BD0, D_01B00BD0.sub, size + 0x400);
    func_002A3BD8(D_01D00C10, *p30);
    return 0;
}

int func_01B00890(void)
{
    return 0;
}

int func_01B00898(void)
{
    return 0;
}

void func_01B008A0(void *chr, void *buf, int frame, int start, int len, int v0, int v1)
{
    int val;

    frame -= start;
    if (frame > 0 && frame <= len) {
        val = ((v1 - v0) * frame) / len + v0;
        op_chara_hsv(chr, buf, 0, -val, val, 0);
    }
}

int func_01B008F0(void)
{
    if (D_01B004F0 == 0) {
        if (func_0029B830(D_01B00B40) != 0) {
            return 0;
        }
        D_01B004F0++;
    }
    if (D_01B004F4 == 0) {
        D_01B004F4 = 1;
        MsEffectReady(D_01B00B40, 1);
    }
    if (D_01B004F8 == 0) {
        if (MsEffectMotionLevel(D_01B00B40) <= 0) {
            return 0;
        }
        D_01B004F8++;
    }
    if (D_01D00C00 < 0) {
        if ((MsGetChrMotionSignal(D_01B00B40) & 1) == 0) {
            return 0;
        }
        func_001C5E90(D_01B00B40, -5, 0);
        D_01D00C00 = 0;
        op_oef2_se_on(D_01B00B44, 64, 256);
    }
    func_002A3BD8(D_01D00C10, D_01D00C30);
    func_01B008A0(D_01D00C10, D_01D00C30, D_01D00C00, 0, 15, 0, 64);
    func_01B008A0(D_01D00C10, D_01D00C30, D_01D00C00, 15, 30, 64, 0);
    return 0;
}

int func_01B00A40(void)
{
    if (D_01B004F8 == 0) {
        return 0;
    }
    D_006A3BCC = D_01C00C00;
    D_006A3924 = &D_01B00BD0;
    func_001AACA0(D_006A3A70);
    func_001A9EE0(D_006A3970);
    func_01B00688(&D_01B00B50);
    if (D_01B00B50.enabled == 0) {
        Ch_ClutDispose(D_01D00C10);
        MsEffectTerminate(D_01B00B40);
    }
    D_01D00C00++;
    return 0;
}

int func_01B00AF0(void)
{
    return 0;
}

void func_01B00AF8(void)
{
}
