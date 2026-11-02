#ifndef FFX_S1_H
#define FFX_S1_H

void MsEventEffectStart(int v);
int func_0014A500(void);

void func_0014DD38(int v);

extern u8 D_0030B968[];
extern u8 D_0030B970[];
extern u8 D_0030B978[];
extern u16 D_0030B980[];
extern u16 D_0030B990[];
extern u16 D_0030B9A0[];
extern u16 D_0030B9B0[];

extern char D_0056BF00[];
extern char D_0056BF18[];
extern char D_0056BF30[];
extern char D_0056BF48[];
extern char D_0056BF60[];
extern char D_0056BF78[];
extern char D_0056BF90[];

/* DEBT(CAST)/DEBT(NAME): flag word and pointer at +0x48 of the block behind D_0058E3D8; q1.h's Sys3D8 is not visible with q2.h */
typedef struct S1Sys { u32 flags; u8 pad4[0x44]; void *p48; u8 pad4C[0x1B8]; s32 w204; } S1Sys;
#ifndef FFX_Q1_H
extern S1Sys *D_0058E3D8;
#define S1SYS() D_0058E3D8
#else
#define S1SYS() ((S1Sys *)D_0058E3D8)
#endif

void func_00148320(void);
void func_00138408(void);
void func_0014CED0(int a, int b);
void func_00147FA8(void);
void func_001481F0(void);
void func_001460E0(void);
void AtelEventRegistFootInfo(void *p);
void func_00147C38(s32 a, s32 b);
void func_00146FB8(int a);
void func_00147988(int a);
void func_00135E28(int a);

/* DEBT(TYPE): header declares a narrow parameter but the original caller passes a plain int */
#define func_00105750_I(a0, a1) ((s32 (*)(Chr *, int))func_00105750)(a0, a1)

/* DEBT(TYPE): header declares a narrow parameter but the original caller passes a plain int */
#define func_00109B88_I(a0, a1) ((void (*)(Chr *, int))func_00109B88)(a0, a1)

/* DEBT(TYPE): header declares a narrow parameter but the original caller passes a plain int */
#define func_0010DC38_I(a0, a1) ((void (*)(Chr *, int))func_0010DC38)(a0, a1)

/* DEBT(TYPE): header declares a narrow parameter but the original caller passes a plain int */
#define Ch_SetMotionType_I(a0, a1) ((void (*)(Chr *, int))Ch_SetMotionType)(a0, a1)

/* DEBT(TYPE): header declares a narrow parameter but the original caller passes a plain int */
#define Ch_SetFieldMode_I(a0, a1) ((void (*)(Chr *, int))Ch_SetFieldMode)(a0, a1)

/* DEBT(TYPE): header declares a narrow parameter but the original caller passes a plain int */
#define Ch_SetGravMode_I(a0, a1) ((void (*)(Chr *, int))Ch_SetGravMode)(a0, a1)

/* DEBT(TYPE): header declares a narrow parameter but the original caller passes a plain int */
#define Ch_SetMotionSpeed_I(a0, a1) ((void (*)(Chr *, int))Ch_SetMotionSpeed)(a0, a1)

/* DEBT(TYPE): header declares a narrow parameter but the original caller passes a plain int */
#define Ch_SetHideCalc_I(a0, a1) ((void (*)(Chr *, int))Ch_SetHideCalc)(a0, a1)

/* DEBT(TYPE): header declares a narrow parameter but the original caller passes a plain int */
#define func_001127E0_I(a0, a1) ((void (*)(Chr *, int))func_001127E0)(a0, a1)

int func_001148F0(float, float, float);

extern char D_0056B0D0[];
extern char D_0056B0E8[];
extern char D_0056B100[];
extern char D_0056B118[];
extern char D_0056B138[];
extern char D_0056B158[];
extern char D_0056B178[];
extern char D_0056B198[];
extern s32 D_0058F920;
void func_00159E80(int a, int *b, int *c);
s32 TkCdSize(int a, int b);
int sa_task_buff_size_get(int a);
s32 func_00159CD8(int a);
int TkGetNowEventJumpMapIdNo();

int yiFieldObjReadNB();

int func_00174E28();

int Yn_GuideMapSetMapNo();

int pppFpLoadStat();

void AtelRecoverPreBgPage(void);

int func_00139538();

extern s32 D_0058E418;

extern s32 D_0058E428;

extern char D_0058E490[];

extern s32 D_0058E3E4;

int func_00138C58(void);

int AtelEventKickBGSep();

#endif
