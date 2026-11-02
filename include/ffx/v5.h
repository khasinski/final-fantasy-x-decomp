#ifndef FFX_V5_H
#define FFX_V5_H

void func_0022F720(int x, int y);
u8 TkMenuGetCurrentPlayer(void);
void func_00249A08(void);
int abs(int x);
void func_00238C48();
void func_00237BE0(Task *t);
s32 func_002249A8(void);
s32 func_00224998(void);
void func_0023BAA0();
void func_0022D3D8();
void func_0022D790();
void func_0022DB10();
void func_0024C670();
void *func_00237E00(int a);
void func_00231780(int a0);
void func_00232728();
void func_00226210(int x, int y, int k);
void func_00226C78(int a, int b, int c, int d);
int func_0023A9C0(int a);
extern char D_005712C8[];
int func_002211B8(void);
void func_0022BA70(void);
Task *func_00243400(void);
void TkMenuMainRegistWindow(Task *o);
int func_002382D0(int a);
void func_0022A728(int a, int b, int c, int mode);
void TkMenuDrawRect(int x, int y, int w, int h, u32 c0, u32 c1);
extern int D_0069BED4, D_0069BED8;
extern char D_00573608[];
Task *func_002500A0(int a);
void TkMenuItemImportantRefresh(void);
int func_00248680(int a0, int a1, int a2, int a3, int t0);
extern FlagRec D_00325AD0;
extern int D_003264A0[];
void func_002476C8(int a, int b, int c, int d);
void func_00247640(int a, int b, int c, int d);
void func_00247750(int a, int b, int c, int d, int e);
void *func_00247F48(u32 i, int *tbl);
void func_00247408(int a, int b, int c);
extern struct S6Pt D_00326DA0; /* s16 x, y (S6Pt, s6.h) */
extern int D_00326D98, D_00326DA4;
extern s16 D_00326DAE;
void func_002362B8();
void func_00230320(int a, int x, int y, int n, int b);
void func_0023B838(int a, int x, int y, int n, int b);
void func_00237180();
void func_00236090(Task *o);
void *func_001F9138(void *list, int id, int x, int y, int z);
extern s16 D_00324248, D_0032424A, D_0032424C, D_0032425C, D_0032425E, D_00324260, D_0032426C, D_0032426E; /* DEBT(NAME): two frame records {x, y, w, c0, c1} and an offset */
extern int D_00324250, D_00324254, D_00324264, D_00324268;
void *func_00200C58(void *list, int k, int x, int y);
void *func_00200F98(void *list, int k, int x, int y);
extern char D_00572080[], D_00572090[], D_005720A0[], D_005720B0[], D_005720C0[], D_005720D0[], D_005720E0[], D_005720F0[], D_00572100[], D_00572110[], D_00572120[], D_00572130[], D_00572140[], D_00572150[], D_00572160[], D_00572170[], D_00572180[], D_00572190[], D_005721A0[], D_005721A8[];
extern s16 D_00693EC8[2], D_00693EE0[2], D_00693EE8[2], D_00693EF8[2], D_00693F00[2], D_00693F08[2], D_00693F10[2];
extern s16 D_00693ED8[4];
extern int D_00693EEC, D_00693EF0, D_00693EE4;
extern FlagRec D_00693F48;
extern char D_005719D0[], D_005719E0[], D_005719F0[], D_00571A00[], D_00571A10[], D_00571A20[], D_00571A30[], D_00571A40[], D_00571A50[], D_00571A60[], D_00571A70[], D_00571A80[], D_00571A90[], D_00571AA0[], D_00571AA8[], D_00571AB8[], D_00571AC8[], D_00571AD8[], D_00571AE8[], D_00571AF8[], D_00571B08[];
extern s16 D_00325A58[2], D_00325A60[2], D_00325A68[2], D_00325A70[2], D_00693BE8[2], D_00693BA8[2], D_00693BB0[2], D_00693BB8[2], D_00693BC0[2], D_00693BC8[2];
extern s16 D_00693BF8[4], D_00693BD8[4], D_00693BE0[4];
extern int D_00693BC4;
extern FlagRec D_00693B90, D_00325A40;
extern char D_00571E90[], D_00571EA0[], D_00571EB0[], D_00571EC0[], D_00571ED0[], D_00571EE0[], D_00571EF0[], D_00571F00[];
extern char D_00571F10[], D_00571F20[], D_00571F30[], D_00571F40[], D_00571F50[], D_00571F60[], D_00571F70[], D_00571F80[], D_00571F90[];
extern s16 D_00693D68[2], D_00693D70[4], D_00693D78[4], D_00693D80[2], D_00693D90[4], D_00693D98[2]; /* pos_ = x, y; r_ = rect */
extern s16 D_00325AC8[2], D_00325AE8[2], D_00325AF0[4], D_00325AF8[2], D_00325B00[4], D_00325B08[2], D_00325B10[2];
extern s32 D_003257E8[], D_003257F0[], D_003257F8[], D_00325800[];
extern u8 D_0069BE74;
extern char D_00573398[], D_005733A0[];
void func_00246670(int value, int x, int y, int flag);
extern char D_00571390[], D_00571398[], D_005713A0[], D_005713A8[], D_005713B0[], D_005713C0[]; /* "x = %d\n" .. "c1 = 0x%x\n" */
void func_00225F30(int x, int y, int k);
void func_00229D58(int x, int y, int k);

/* entries of the D_0069A808 process table (TkMenuMainRemoveMenu, func_00243D58) */
typedef struct V5Proc {
    /* 0x00 */ int (*update)(int);
    /* 0x04 */ u8 pad4[4];
    /* 0x08 */ void (*fn8)(struct V5Proc *p, int arg);
    /* 0x0C */ u8 padC[0x18 - 0xC];
    /* 0x18 */ u8 b18;
    /* 0x19 */ u8 b19;
    /* 0x1A */ u8 pad1A[2];
    /* 0x1C */ int w1C;
} V5Proc;

/* func_0013A398 reads no argument; funcs.h declares an unused id parameter */
#define V5_CALL0_func_0013A398() (((int (*)(void))func_0013A398)()) /* DEBT(CAST): see funcs.h prototype */
/* call a void(void) function through an int-returning type (caller compiled against an int prototype) */
#define V5_INT0(f) ((int (*)(void))(f)) /* DEBT(TYPE) */
#define V5_TkMn2SeqGetNum_int(n) (((int (*)(int))TkMn2SeqGetNum)(n)) /* DEBT(TYPE): defined returning s16, these callers were compiled against int */
#define V5_func_00225920_void() (((void (*)(void))func_00225920)()) /* DEBT(TYPE): funcs.h declares int, this caller uses it as void */

/* resource tables filled by the loaders (TkMn2GetStatusPos, TkMn2GetWShopPos, TkMn2GetIShopPos, ...) */
extern char D_00572420[], D_00572430[], D_00572440[], D_00572450[], D_00572460[], D_00572470[], D_00572480[], D_00572490[], D_005724A0[], D_005724B0[], D_005724C0[], D_005724D0[], D_005724E0[], D_005724F0[], D_00572500[], D_00572510[], D_00572520[], D_00572530[], D_00572540[], D_00572550[], D_00572560[], D_00572570[], D_00572580[], D_00572590[], D_005725A0[], D_005725B0[];
extern s16 D_00326070[2], D_00326080[2], D_00326090[2], D_00694098[2], D_00326100[2], D_003260E0[2], D_003260D0[2], D_003260D8[2], D_003260F0[2], D_003260F8[2];
extern s16 D_003260B0[4], D_00326108[4], D_003260C8[4], D_003260E8[4], D_00326078[4], D_00326088[4];
extern int D_00694094, D_0069409C, D_006940A0, D_00326064, D_00326068;
extern FlagRec D_00326098, D_00326118, D_00326130;
extern char D_00572790[], D_005727A0[], D_005727B0[], D_005727C0[], D_005727D0[], D_005727E0[], D_005727F0[], D_00572800[], D_00572810[], D_00572820[], D_00572830[], D_00572840[], D_00572850[], D_00572860[], D_00572870[], D_00572880[], D_00572890[], D_005728A0[], D_005728B0[], D_005728C0[], D_005728D0[], D_005728E0[], D_005728F0[], D_00572900[], D_00572910[], D_00572920[], D_00572930[], D_00572940[], D_00572950[], D_00572960[], D_00572970[], D_00572980[], D_00572990[], D_005729A0[], D_005729B0[], D_005729C0[], D_005729D0[], D_005729E0[], D_005729F0[], D_00572A00[], D_00572A10[], D_00572A20[];
extern s16 D_003261C8[2], D_00326238[2], D_003261E0[2], D_003261B8[2], D_00326178[2], D_006940C8[2], D_00326248[2], D_00326250[2], D_00326268[2], D_00326270[2], D_006940D0[2], D_006940D8[2], D_003261C0[2], D_00326230[2], D_00326258[2], D_00326260[2];
extern s16 D_00326288[4], D_00326170[4], D_006940A8[4], D_006940B0[4], D_00326240[4], D_00326180[4], D_006940B8[4], D_006940C0[4], D_00694148[4];
extern int D_006940DC, D_006940E0, D_006940E4, D_006940E8, D_006940EC, D_006940F0, D_006940F4, D_006940F8, D_006940FC, D_00694100, D_00694104;
extern FlagRec D_00326188, D_003261A0, D_00326200, D_00326218;
extern char D_00571470[], D_00571480[], D_00571490[], D_005714A0[], D_005714B0[], D_005714C0[], D_005714D0[], D_005714E0[], D_005714F0[], D_00571500[], D_00571508[], D_00571510[], D_00571520[], D_00571530[], D_00571540[], D_00571550[], D_00571560[], D_00571570[], D_00571580[], D_00571590[], D_005715A0[], D_005715B0[], D_005715C0[], D_005715D0[], D_005715E0[], D_005715F0[], D_00571600[], D_00571610[], D_00571620[], D_00571630[], D_00571640[], D_00571650[], D_00571660[], D_00571670[], D_00571680[], D_00571690[], D_005716A0[], D_005716B0[], D_005716C0[], D_005716D0[], D_005716E0[], D_005716F0[], D_00571700[], D_00571710[], D_00571720[], D_00571730[], D_00571740[], D_00571750[], D_00571760[], D_00571770[], D_00571780[], D_00571790[], D_005717A0[], D_005717B0[], D_005717C0[];
extern s16 D_00693A70[2], D_00693A38[2], D_006938D8[2], D_006938E0[2], D_003258A0[2], D_003258A8[2], D_00693A28[2], D_00693A08[2], D_00693A10[2], D_00693A18[2], D_00693A20[2], D_006938C0[2], D_006938C8[2], D_006938D0[2], D_00693A68[2], D_00693A50[2], D_00693A58[2];
extern s16 D_00693880[4], D_00693890[4], D_003258B8[4], D_003258C0[4], D_006938B0[4], D_00693A30[4], D_00693A48[4];
extern int D_00693A3C, D_00693A40, D_00693898, D_0069389C, D_006938A0, D_006938A4, D_006938A8, D_00693A2C, D_006938E4, D_00693A5C, D_00693A60, D_00693A64;
extern FlagRec D_00693990, D_006939F0;
extern FlagRec D_00693F78;
extern char D_00572230[], D_00572240[], D_00572250[], D_00572260[], D_00572270[], D_00572288[], D_005722A0[], D_005722B0[], D_005722C0[], D_005722D0[], D_005722E0[], D_005722F0[], D_00572300[], D_00572310[], D_00572320[], D_00572330[];
extern s16 D_00693F90[4], D_00693FA0[4], D_00693FC0[4], D_00693F98[2], D_00693FB0[2], D_00693FA8[2];
extern int D_00693FBC, D_00693FB4, D_00693FB8, D_00693FC8, D_00693FCC;
extern FlagRec D_006938E8, D_00693918, D_00693930, D_00693948, D_006939D8, D_00325888;

void func_00243548(int);

#endif
