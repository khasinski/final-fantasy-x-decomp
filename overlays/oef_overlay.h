#ifndef FFX_OEF_OVERLAY_H
#define FFX_OEF_OVERLAY_H

#include "common.h"

typedef struct OefPartObj {
    u8 pad00[0x1E];
    u16 enabled;       /* 0x1E */
    u8 pad20[0x20];
    float position[4]; /* 0x40 */
    int rotation[3];   /* 0x50 */
    int flag5C;        /* 0x5C */
    float scale[4];    /* 0x60 */
    u8 pad70[0x10];    /* 0x70..0x80 */
} OefPartObj;

typedef struct OefHeapCfg {
    u8 pad00[0x10];
    int *pdt;          /* 0x10 */
    void *w14;         /* 0x14 */
    void *tbl;         /* 0x18 */
    void *p1C;         /* 0x1C */
} OefHeapCfg;

typedef struct OefHeapMgr {
    u8 main[0x10];     /* 0x00 */
    u8 sub[0x10];      /* 0x10 */
    void *w20;         /* 0x20 */
    void *tbl;         /* 0x24 */
    void *p28;         /* 0x28 */
    int pad2C;         /* 0x2C */
} OefHeapMgr;

typedef struct OefResHeader {
    u8 pad00[0x44];
    u16 tex_count;     /* 0x44 */
    u16 clut_count;    /* 0x46 */
} OefResHeader;

extern float D_004F4610[];
extern OefHeapMgr *D_006A3924;
extern u8 D_006A3930[];
extern u8 D_006A3970[];
extern u8 D_006A39B0[];
extern u8 D_006A3A70[];
extern u8 D_006A3AB0[];
extern int D_006A3BC4;
extern u8 *D_006A3BCC;

int func_001072F8(void *chr, int bone, void *dst);
void func_00107428(void *chr, int bone, int a2, void *dst);
void Ch_OptposGet(void *chr, int optpos, float *dst);
void Ch_SetShadeCol(void *chr, int a1, float r, float g, float b);
int Ch_EnBodyHit(void *chr, int enable);
int func_00110718(void *chr, int a1);
void Ch_SetMotionSpeed(void *chr, int speed);
int Sg_GetCurExecFrames(void);
void Ch_ClutDispose(void *chr);
void Ch_ClutCreate(void *chr);
void *func_0013B150(int chr_id);
int func_0014AA50(int a0);
int func_001A9EE0(void *m);
void func_001AACA0(void *m);
void *MsGetChrHandle(int chr_id);
int MsGetChrMotionSignal(int eff_id);
float MsGetChrHeight(int chr_id);
float MsGetChrWidth(int chr_id);
void func_001B6790(int chr_id, float *pos);
void MsSetChrPos(int chr_id, float *pos);
int func_001C5E90(int eff_id, int v, int z);
int MsEffectMotionLevel(int eff_id);
void MsEffectReady(int eff_id, int ready);
void MsEffectTerminate(int eff_id);
int MsGetEff2Chr(int eff_id);
void func_001CE050(int chr_id, int motion_id);
void MsEffectEndMotion(int chr_id, int a1);
u8 *MsGetTargetList(int eff_id, void *out);
void func_00266F40(void);
void *pppMemAlloc(OefHeapMgr *mgr, void *sub, int size);
void pppSetMatrix(OefPartObj *o);
void _pppStartPart(OefPartObj *o, int a1, int pdt, int a3);
void _pppInitData(OefHeapCfg *cfg, void *data);
void pppInitEnv(OefHeapMgr *mgr, OefHeapCfg *cfg, void *buf, int size);
int _pppRunPart(OefPartObj *o, int stride);
void func_0026BDE0(void *mtx, int angle);
void op_oef2_sound_cue_multi(void *res, int from, int to, int flags);
int op_oef2_se_on(void *se, int vol, int pitch);
int func_0029B830(int eff_id);
int op_chara_hsv_size_get(void *chr);
void *func_002A3BD8(void *chr, void *buf);
void op_chara_hsv(void *chr, void *buf, int a, int b, int c, int d);
u8 *func_002B2F30(u8 *pkt, u32 rgba, int a2, int a3);
void op_oef2_set2(void *res);
void *op_oef2_a_get(void *res, int type, int idx);
void op_oef2_texture_load(void *tex, int mode);
void op_oef2_clut_load(void *clut, int mode);
void func_002D02E8(void *res, int from, int to, int flags);
void func_002DCE38(void *dst, void *a, void *b);
void func_002DCEC8(void *dst, void *src);
void func_002DCFF8(void *dst, void *a, void *b, float t);
void func_002DD038(void *dst, void *a, void *b);
void func_002DD068(void *dst, void *src, float scale);

#endif /* FFX_OEF_OVERLAY_H */
