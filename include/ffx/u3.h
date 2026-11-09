#ifndef FFX_U3_H
#define FFX_U3_H

#include "ffx/types.h"

/* Declarations added by worker u3 (chunks c_1EAF80 .. c_22F1E0). */

int MsVoiceStatus(void);

extern s32 D_003257A4;
extern u8 D_00693B88[];

/* 24-byte layout record copied by func_00229CE8 (2-byte aligned: copied with ldl/ldr). DEBT(NAME): guessed */
typedef struct U3Box {
    s16 x;
    s16 y;
    s16 w;
    s16 h;
    u8 pad08[0x10];
} U3Box;
extern U3Box D_00693900;
void func_00223E98(void);

/* DEBT(TYPE): funcs.h declares func_002DA610 void; TODrawKick was compiled against an int-returning prototype */
#define func_002DA610_int(a, b) (((int (*)(int, int))func_002DA610)(a, b))

void func_001FA548(int x, int y, int w, int h);

/* DEBT(TYPE): MsSetSaveConfigEnglish returns int, but the callers in c_20B6A8 were compiled against a void prototype */
#define MsSetSaveConfigEnglish_void(a) (((void (*)(int))MsSetSaveConfigEnglish)(a))

void func_00237818(void);
void func_0022FB10(void);
void TOMenuExecLayerHandle(int a, int b, int c);
/* 4-step walk offsets (D_00570D10, rodata), copied to the stack by func_00213F70 */
typedef struct U3Step4 {
    s8 d[4];
} U3Step4;
extern U3Step4 D_00570D10;

/* ASCII 0x20..0x7A -> 2-byte game charset table at 0x003248C0 ({prefix, code}; prefix 0 = one byte).
 * splat split the data at 0x003248C1, so the table is reached through that label. DEBT(CAST) */
extern u8 D_003248C1[];
#define U3_CHARMAP ((u8 (*)[2])(D_003248C1 - 1))

extern u8 D_003252A8[]; /* DEBT(TYPE): only the first byte is read here */
extern s16 D_003252A4;
extern s32 D_00325670;
void func_0021ECC0(void);
void func_002184B8(void);
extern char D_0056FD30[];

void func_001FE7F8(int kind, int x, int y);

/* DEBT(TYPE): defined with a u8 id in c_1DF4E8.c, but the script callers in c_1ED130 pass the id unmasked */
#define func_001E00A0_i(id, b) (((int (*)(int, int))func_001E00A0)(id, b))
#define func_001E0290_i(id, b) (((int (*)(int, int))func_001E0290)(id, b))

void func_00201D48(int i, int x, int y, int v);
void func_00201DE8(int i, int x, int y, int v);
CmdRec *func_00201F50(int a, CmdRec *p);
extern u8 D_0068F1A0[][0x20]; /* DEBT(TYPE): 0x20-byte records filled by func_0014D718 */

/* 0x18-byte selection block D_00690640 (cleared by func_00214210). DEBT(NAME) */
typedef struct U3Sel {
    s16 h0;
    s16 h2;
    u8 pad04[8];
    s32 wC;
    u8 pad10[8];
} U3Sel;
extern U3Sel D_00690640;
extern CmdRec *D_00693850;

/* DEBT(TYPE): funcs.h gives these u8 id parameters; func_002195F8 passes the id unmasked (int prototype) */
#define U3_ID_CALL(f, id) (((u8 (*)(int))(f))(id))

void TOMakePktSampleBlueWindowXY2(int x0, int y0, int x1, int y1);
void TOMkpEasyMesFontLCenter(void *a, int b, int c);
void TOBtlDrawParamPlate(int a, int b, int c);
int func_0021F940(int a);
int MsGetCommandTarget(int id, int v, int flag, int d);

/* DEBT(TYPE): funcs.h gives func_002DAB10 int parameters; func_0020C660 was compiled against a short-parameter prototype */
void func_002DAB10();
typedef void (*U3DAB10Fn)(void *ctx, s16 a, s16 b, s16 c, s16 d, s16 e, s16 f, s16 g);
#define func_002DAB10_s ((U3DAB10Fn)func_002DAB10)

extern u16 D_00693A98;
extern u16 D_00693A9A;
extern s32 D_00693A44;
void func_0022A3F8(int a, int y, int i);
extern s16 D_00693BD0[];
void func_0022BC18(int a, int x, int y, int i, int b);
void func_0022D5E0(int a, int x, int y, int i, int b);
void func_0022DFD0(int a, int x, int y, int i, int b);

/* DEBT(TYPE): graphicUiRemapY2 is void (c_225920.c); the list drawers call it through an int prototype */
#define graphicUiRemapY2_int() (((int (*)(void))graphicUiRemapY2)())

u8 *TOGetChangeMacroAddress(int a, u8 *b);
int TOGetChangeMacroWordCount(int a, u8 *b);

void TOSetMessageFunc(int i, int v);
void TOGetControlPadStatus(int i);

/* Message popup state D_00692560. DEBT(NAME): fields named by offset */
typedef struct U3Popup {
    s16 h0;
    u8 pad02[4];
    s16 h6;
    u8 pad08[2];
    s16 hA;
    s16 hC;
    s16 hE;
    s32 w10;
} U3Popup;
extern U3Popup D_00692560;
extern s16 D_006925B0;
extern s16 D_006925B2;
extern s16 D_006925B4;
void TOBtlInitInfoWinMes(int a);

extern R4Ptrs D_0068EEE8[8];
extern R4Ptrs D_0068EFC8[8];
extern MenuSlot D_0066AF48[8];
extern MenuSlot D_0066B228[8];
void TOGetPadStatus(void);
void func_0020A7A8(int a);
void TOSetExeWindowArea(int a);
void TOSetExeMessageArea(int a);

void func_001FA7D0(int x, int y, int w, int h);
extern s16 D_0032435C;
extern s16 D_0032435E;
extern s16 D_00324364;
extern s16 D_0032436A;
extern s16 D_0032436C;
/* 0x1C-byte number entry block D_006902A0. DEBT(NAME) */
typedef struct U3NumBox {
    s16 h0;
    s16 h2;
    s16 h4;
    s16 h6;
    s32 w8;
    s32 wC;
    s32 w10;
    s32 w14;
    s32 w18;
} U3NumBox;
extern U3NumBox D_006902A0;
extern char D_00570C90[];

void func_0022A768(int a, int b, int c, int d, s32 *e, s32 *f, s32 *g, s32 *h, int i);
void func_0022A9A0(int a, int b, int c, int d);
s16 func_00228B80(void);
void func_002297A0(int a, int b);
void TOMakePktBoxXYWHRGBA(int x, int y, int w, int h, int a, int b, int c, int d);
void func_001FF398(int x, int y, int w, int h, int c0, int c1);
extern s16 D_00324234;
extern s16 D_00324236;
extern s32 D_0032423C;
extern s32 D_00324240;
void func_002259B8(void);
extern char D_00571378[];

/* DEBT(TYPE): func_00225920 returns int, but func_0022ACF8 was compiled against a void prototype */
#define func_00225920_void() (((void (*)(void))func_00225920)())

int func_00242040(void);
CmdRec *func_001FE578(CmdRec *p, int a, int b, int c);
extern char D_00571CE0[];
extern char D_00571CF0[];
extern char D_00571D00[];
extern char D_00571D10[];
extern char D_00571D20[];
extern char D_00571D30[];
extern char D_00571D40[];
extern char D_00571D50[];
extern char D_00571D60[];
extern FlagRec D_00693C18;
extern s16 D_00693C40[];
extern s16 D_00693C48[];
int func_001CCA60(int a, int b, int c, int d);
struct MenuSlot *func_00209538(s32 idx);
struct MenuCmd *func_002043D0(s32 idx);
struct SlotZ *func_002043E8(s32 idx);

/* DEBT(TYPE): funcs.h declares MsActTargetSearch void, func_001EB048 uses its result */
typedef int (*U3D5590Fn)(int a, int b, int c, int d, int e, int f, int g, int *out);
#define MsActTargetSearch_int ((U3D5590Fn)MsActTargetSearch)

void func_00204168(int i);

void func_00221238(int id, int pos, int c);
extern char D_005713D0[];
void func_00226E10(int p, int x, int id);
void func_00226D00(int p, int x, int y, int id);
extern s16 D_00326278[2];
extern s16 D_00326280[2];

void *func_001F6BD8(void *list, char *s, int x, int a, int b, int c, int d, int e, int f);
typedef struct U3Rect {
    s16 x0;
    s16 y0;
    s16 x1;
    s16 y1;
} U3Rect;
void *func_00201AE0(void *list, int a, int x, int y, u32 c0, u32 c1);

extern char D_00570088[];
extern s16 D_003258B0[2];
void func_00229AC8(int x, int y, int a, int b, int c);
void func_0022F810(int v, int a, int b);

extern char D_00570340[];
extern char D_00667620[];
/* Number item formatted by func_00207538. DEBT(NAME) */
typedef struct U3NumFmt {
    s8 b0;
    s8 b1; /* 2: insert separators */
    u8 pad02[2];
    s32 w4;
} U3NumFmt;

/* DEBT(TYPE): preserve the integer-result declaration view used by this legacy caller. */
#define CALL_func_0022A768_INT ((int (*)(int, int, int, int, s32 *, s32 *, s32 *, s32 *, int))func_0022A768)

#endif /* FFX_U3_H */
