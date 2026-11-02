/* EE Battle-Effect Overlay: group 0x11, file 09242
 * Load base: 0x01B00000, .text: 0x01B00508..0x01B00CA8 (1952 bytes, 9 functions)
 */
#include "../oef_overlay.h"

extern u8 D_01B00040[];
extern int D_01B004F0;
extern int D_01B004F4;
extern int D_01B004F8;
extern void *D_01B00CC0;
extern int D_01B00CC4;
extern OefPartObj D_01B00CD0;
extern u8 D_01B00D10[];
extern OefHeapMgr D_01B00D50;
extern u8 D_01B00D80[];
extern u8 D_01C00D80[];
extern int D_01D00D80;
extern int D_01D00D84;
extern int D_01D00D88;
extern void *D_01D00D8C;
extern void *D_01D00D90;
extern float D_01D00DA0[4];
extern float D_01D00DB0[4];
extern OefHeapCfg D_01D00DD0;
extern OefResHeader D_01D089F0;

void func_01B00508(OefResHeader *res)
{
    int i;

    op_oef2_set2(res);
    for (i = 0; i < res->tex_count; i++) {
        op_oef2_texture_load(op_oef2_a_get(res, 2, i), 1);
    }
    for (i = 0; i < res->clut_count; i++) {
        op_oef2_clut_load(op_oef2_a_get(res, 3, i), 1);
    }
    op_oef2_sound_cue_multi(res, 0, 1000, 0x100);
    D_01B00CC0 = op_oef2_a_get(res, 6, 0);
}

int func_01B005F0(int eff_id)
{
    float dir[4];
    float ofs[4];
    u8 target_buf[16];
    float width;

    D_01B00CC4 = eff_id;
    D_01D00D84 = MsGetEff2Chr(eff_id);
    D_01D00D88 = *MsGetTargetList(D_01B00CC4, target_buf);
    D_01D00D8C = MsGetChrHandle(D_01D00D84);
    D_01D00D90 = MsGetChrHandle(D_01D00D88);
    func_001B6790(D_01D00D88, D_01D00DB0);
    func_001B6790(D_01D00D84, D_01D00DA0);
    func_002DD038(dir, D_01D00DA0, D_01D00DB0);
    func_002DCEC8(dir, dir);
    width = MsGetChrWidth(D_01D00D84);
    func_002DD068(ofs, dir, width);
    D_01D00DB0[0] += ofs[0];
    D_01D00DB0[1] += ofs[1] + MsGetChrHeight(D_01D00D88) * 0.5f;
    D_01D00DB0[2] += ofs[2];
    D_01D00D80 = 16;
    func_01B00508(&D_01D089F0);
    _pppInitData(&D_01D00DD0, D_01B00040);
    pppInitEnv(&D_01B00D50, &D_01D00DD0, D_01B00D80, 0x100000);
    D_006A3924 = &D_01B00D50;
    _pppStartPart(&D_01B00CD0, 0x1000, D_01D00DD0.pdt[0], 1);
    D_01B00CD0.rotation[0] = 0;
    D_01B00CD0.rotation[1] = 0;
    D_01B00CD0.rotation[2] = 0;
    D_01B00CD0.flag5C = 1;
    D_01B00CD0.scale[0] = 0.8f;
    D_01B00CD0.scale[1] = 0.8f;
    D_01B00CD0.scale[2] = 0.8f;
    D_01B00CD0.scale[3] = 0.8f;
    return 0;
}

int func_01B007D0(void)
{
    return 0;
}

int func_01B007D8(void)
{
    return 0;
}

void func_01B007E0(int frame, int in_frames, int out_frames, u32 color, u32 max_alpha)
{
    u32 alpha;

    if (frame <= in_frames) {
        alpha = (frame * max_alpha) / in_frames;
    } else {
        frame -= in_frames;
        if (frame >= out_frames) {
            return;
        }
        alpha = max_alpha - (frame * max_alpha + max_alpha) / (out_frames + 1);
    }
    D_006A3BCC = func_002B2F30(D_006A3BCC, color | (alpha << 24), 72, 0);
}

int func_01B00870(void)
{
    float pos[4];
    int t;

    if (D_01B004F0 == 0) {
        if (func_0029B830(D_01B00CC4) != 0) {
            return 0;
        }
        D_01B004F0++;
    }
    if (D_01B004F4 == 0) {
        D_01B004F4 = 1;
        MsEffectReady(D_01B00CC4, 0);
    }
    if (D_01B004F8 == 0) {
        if (MsEffectMotionLevel(D_01B00CC4) <= 0) {
            return 0;
        }
        D_01B004F8++;
    }
    if (Sg_GetCurExecFrames() == 0) {
        D_006A3BC4 = 1;
    } else {
        D_006A3BC4 = 0;
    }
    if (D_01D00D80 == 16) {
        func_001CE050(D_01D00D84, 176);
    }
    t = D_01D00D80 - 30;
    if (t == 0) {
        Ch_EnBodyHit(D_01D00D8C, 0);
        Ch_EnBodyHit(D_01D00D90, 0);
        func_001CE050(D_01D00D84, 177);
    }
    if ((u32)t < 39) {
        float ratio = (D_004F4610[(((u32)((t << 15) / 38 + 0x4000) >> 4) & 0xFFF)] + 1.0) * 0.5;

        func_002DCFF8(pos, D_01D00DA0, D_01D00DB0, ratio);
        MsSetChrPos(D_01D00D84, pos);
        if (t == 38) {
            Ch_SetMotionSpeed(D_01D00D8C, 0);
            func_00107428(D_01D00D8C, 36, 0, D_01B00D10);
            Ch_SetShadeCol(D_01D00D8C, 15, 1.0f, 0.5f, 0.5f);
        }
    } else if (D_01D00D80 == 85) {
        op_oef2_se_on(D_01B00CC0, 64, 256);
        func_00110718(D_01D00D8C, 1);
        func_001C5E90(D_01B00CC4, -5, 0);
    }
    return 0;
}

int func_01B00AD0(void)
{
    int t = D_01D00D80 - 83;

    if (D_01B004F8 == 0) {
        return 0;
    }
    if (t >= 0) {
        D_01B00D50.w20 = D_01D00DD0.w14;
        D_01B00D50.tbl = D_01D00DD0.tbl;
        D_01B00D50.p28 = D_01D00DD0.p1C;
        D_006A3924 = &D_01B00D50;
        func_001AACA0(D_006A3A70);
        func_001A9EE0(D_006A3970);
        pppSetMatrix(&D_01B00CD0);
        func_002DCE38(D_006A39B0, D_006A3970, D_006A3930);
        func_002DCE38(D_006A3AB0, D_006A3A70, D_006A39B0);
        D_006A3924 = &D_01B00D50;
        D_006A3BCC = D_01C00D80;
        if (_pppRunPart(&D_01B00CD0, 0x30) != 0) {
            Ch_EnBodyHit(D_01D00D8C, 1);
            Ch_EnBodyHit(D_01D00D90, 1);
            Ch_SetMotionSpeed(D_01D00D8C, 256);
            Ch_SetShadeCol(D_01D00D8C, 0, 1.0f, 1.0f, 1.0f);
            MsEffectEndMotion(D_01D00D84, 1);
            MsEffectTerminate(D_01B00CC4);
        }
        func_01B007E0(t, 5, 10, 0x808080, 128);
    }
    if (D_006A3BC4 == 0) {
        D_01D00D80++;
    }
    return 0;
}

int func_01B00C98(void)
{
    return 0;
}

void func_01B00CA0(void)
{
}
