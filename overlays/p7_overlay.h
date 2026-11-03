#ifndef P7_OVERLAY_H
#define P7_OVERLAY_H

/* P7: F3 family (docs/overlay-families.tsv), the battle-effect "target" helper library that is
 * linked next to ovl_09053_pool into ~215 containers. Names are file09053 addresses.
 * Overlay-internal addresses are relocated per container (overlays/units/p7.py). */

#include "common.h"

/* Target set of the running effect (file09053: D_01B005A0, .bss). */
typedef struct P7Targets {
    int chr;            /* 0x000 effect owner (MsGetEff2Chr) */
    int count;          /* 0x004 number of targets */
    u8 *list;           /* 0x008 target chr ids (MsGetTargetList result or ids[]) */
    int mode;           /* 0x00C 0: battle chr ids, 1: ids[] / handles[] set by func_01B01498 */
    void *handle;       /* 0x010 owner handle */
    u8 ids[48];         /* 0x014 */
    void *handles[105]; /* 0x044 indexed by chr id */
    int arg;            /* 0x1E8 */
} P7Targets;

extern P7Targets D_01B005A0;
extern int D_01B00568[];    /* -1 terminated */
extern int D_01B00578[];    /* -1 terminated */
extern int D_01B00598[];    /* -1 terminated */

/* library functions (file09053 addresses) */
int func_01B01598(int idx);
void *func_01B01630(int idx);
float func_01B01698(int idx);
void func_01B01748(int idx, float dir);
void func_01B017E8(int idx, float *out, int kind);
float func_01B01B10(int idx);
int func_01B01C60(int idx);
void func_01B01D68(int idx, void *a1, void *a2);
void func_01B01E30(float *out);
int func_01B021E8(int idx);
void func_01B02210(int idx, int speed);
void func_01B024B0(int idx, int visible);
void func_01B02520(int idx, int a1);
void func_01B026A8(int visible);
void func_01B02798(int visible);
float func_01B02EE0(int idx);
void *func_01B03AD0(int chr);
void func_01B03B08(int arg, P7Targets *t, u8 *list);

/* resident */
int MsGetEff2Chr(int arg);
u8 *MsGetTargetList(int arg, int *count);
u8 *MsGetTargetSortList(int arg, int *count, int a2);
void *MsGetWeaponHandle(int chr, int a1);
float func_00110288(void *h);
void func_00110300(void *h, float dir);
void Ch_GetPos(void *h, float *x, float *y, float *z);
void Ch_OptposGet(void *h, int a1, float *out);
float Ch_GetJimen(void *h);
void MsSetChrPos(int chr, float *pos);
int func_00110818(void *h);
void Ch_SetPos(void *h, float x, float z);
void Ch_SetPos3(void *h, float x, float y, float z);
int MsGetChrBtlPos(int chr, float *pos);
float func_00110AF0(void *h);
float Ch_GetScaleX(void *h);
float Ch_GetScaleY(void *h);
float Ch_GetScaleZ(void *h);
void Ch_SetScale(void *h, int flags, float x, float y, float z);
float Ch_GetFixHeight(void *h);
float MsGetChrWidth(int chr);
float func_001109E0(void *h);
int func_001B4E18(int chr);
void func_00107428(void *h, int a1, int a2, float *out);
void Ch_GetRootGlobalMatrix(void *h, void *m);
void func_001072F8(void *h, void *a1, void *a2);
void func_002DD998(float *dst, float *src, float s);
int func_001AF358(void);
u8 *MsGetBattleList(int kind, int *count);
void *MsGetChrHandle(int chr);
int MsGetChrFly(int chr);
int func_001B8548(int chr);
int func_001B85B0(int chr);
int MsGetRamChrMonster(int chr);
void MsEffectSetSpeed(int chr, int speed);
void Ch_SetMotionSpeed(void *h, int speed);
int func_001B84F8(int chr);

int MsSetChrVisible(int chr, int visible);
int graphicCharacterInstanceSetMeshSegmentAlpha(void *h, int a1, int a2);
void MsSetChrShadow(int chr, int a1);
void Ch_DrawEnEffect(void *h, int a1);
void func_002985C0(void *h);
void func_002985E0(void *h);
int Ch_SetCalcNorm(void *h, int a1);
void MsChrSEfoot(int chr, int a1);
void func_001B7498(int chr, int a1);
void MsSetChrMoveFlag(int chr, int a1);
void op_et_bindeff(void *h);
void func_00299218(void *h);
void func_002994B8(void *h);
void func_002994D8(void *h);
int func_00110B78(void *h);
void Ch_EffectSetEffectLevel(void *h, int a1);
int func_001B6FB8(int chr);
void func_001B6FD8(int chr, int a1);
void func_00110718(void *h, int a1);
void func_001B57F0(int chr, int a1);
void MsSetChrTransparent(int chr, float f, int a1);
void func_00110540(void *h, float f, int a1);
void func_001B6790(int chr, float *pos);
void Ch_SetOrgMatrix(void *h, void *m);
void MsSetChrDirTarget(int chr, int a1, int a2, int target, int a4, int a5);
int MsSetChrGravity(int chr, int a1);
void Ch_SetShadeCol(void *h, float r, float g, float b, int a1);
int func_001C5E90(int chr, int a1, int a2);
void MsDamageSetMotion(int chr, int a1, int a2);
void func_001AF2E8(float *out);

void Ch_ClothReset2(void *h);
void Ch_DataRead(int a0);
void ChN_ReadSystemMGRPstart(int a0, int a1);
int Ch_DataReadSync(int a0);
int ChN_ReadSystemMGRPsync(int a0, int a1);
int func_00102B98(int a0);
void ChN_ReadSystemMGRP(int a0, int a1);
void ChN_DisposeSystemMGRP(int a0, int a1);
void ChN_DataDispose(int a0, int a1);
void func_002D02E8(int a0, int a1, int a2, int a3);
int func_002D0570(int a0);
void func_002D05F0(int a0);
void MsBattleSpecialCameraPause(int a0);
void func_001AACA0(int a0, int a1);
void func_001A9EE0(int a0);
void func_002DD128(float *m);
void func_00110838(void *h, float f);
void MsEffectEndMotion(int a0);
void Sg_Blur(int a0);
void func_001AAC18(float a, float b);
void func_00173730(void *p);
void func_001737A8(void *p);
void yiGetBackColor(void *p);
void func_00173720(void *p);
void func_00173740(void *p);
void func_00173650(void *p);
void yiRenderEnable(int a0);
void yiRenderDisable(int a0);
int op_oef2_a_get(int a0, int a1, int a2);
void func_0014D3F0(int a0, int a1, int a2);
void *func_0013B0F8(int chr);

#endif /* P7_OVERLAY_H */
