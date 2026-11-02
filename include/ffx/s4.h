#ifndef FFX_S4_H
#define FFX_S4_H


/* single-byte flags in the system block next to D_003172F0 (set/read by script opcodes in c_1EE1C8) */
extern s8 D_00317318;
extern s8 D_00317319;
extern s8 D_0031731A;
extern s8 D_0031732B;
extern s8 D_00317321;
extern s8 D_00317328;
extern s8 D_00317329;
extern s8 D_0031732A;
extern s8 D_0031732C;
extern s8 D_0031732D;
extern s8 D_0031732E;
extern s8 D_0031732F;
extern s8 D_00317330;
extern s8 D_00317331;
extern s8 D_00317332;
extern s8 D_00317333;
extern s8 D_00317334;
extern s8 D_00317342;
extern u8 D_00317343;
extern u8 D_0031EAC9;

/* colour/alpha pairs for the four draw styles of func_001F4C58 */
extern int D_003241D8;
extern int D_003241DC;
extern int D_003241E0;
extern int D_003241E4;
extern int D_003241E8;
extern int D_003241EC;
extern int D_003241F0;
extern int D_003241F4;

/* Menu panel work blocks (c_21A660, c_21B9C8). DEBT(NAME): member names are offsets. */
typedef struct S4PanelA { /* D_00692690 */
    s16 state;
    s16 h2;
    s16 h4;
    s16 h6;
    s16 h8;
    s16 hA;
    s16 hC;
    s16 hE;
    s16 h10;
    u8 pad12[2];
    s32 w14;
} S4PanelA;

typedef struct S4PanelB { /* D_006926A8 */
    s16 state;
    s16 h2;
    s16 h4;
    s16 h6;
    s32 w8;
    s32 wC;
    s16 h10;
    s16 h12;
    s16 h14;
    u8 b16;
    u8 b17;
    u8 pad18;
    s8 seq[16];
    s8 count;
    u8 pad2A[2];
} S4PanelB;

typedef struct S4PanelC { /* D_00692678 */
    s16 state;
    s16 h2;
    s16 h4;
    s16 h6;
    s16 h8;
    u8 padA[2];
    s32 wC;
    u16 *w10;
} S4PanelC;

extern S4PanelC D_00692678;
extern S4PanelA D_00692690;
extern S4PanelB D_006926A8;

void func_00201B60(int a, int b, int c);
int func_001F3808(int id, int x, int y, int z);
void func_001FCC88(int a, int b, int c, u32 rgba);
void func_001F0580(int a, int b, int c, int d, int e, int f, int g);

u16 *MsGetSaveWindow(int id, int mode, s32 *count);
void func_001FC770(int a, int b, int c);

extern s16 D_0069261A;
extern s16 D_0069261C;
extern char D_00570F10[]; /* string in rodata */

void func_0020B308(int id, int x, int y, int w, int h);
void func_0020CD30(int a, int b, int c);
void _TOBtlDrawLibraLeft(int a, int b);
void _TOBtlDrawLibraRight(int a, int b);

/* Sound/data load request (c_20B6A8). DEBT(NAME): member names are offsets. */
typedef struct S4Req {
    u8 pad00[4];
    u16 h4;
    u8 pad06[2];
    u16 h8;
    u8 pad0A[6];
    s32 w10;
    u8 pad14[0xC];
    s32 w20;
    s32 w24;
    u16 h28;
    u16 h2A;
    u8 pad2C[4];
    s32 w30;
} S4Req;

extern u8 D_0067A5A0[];
extern u8 D_0068A5A0[];
extern u8 D_0068E5A0[];
extern u8 D_0068EA60[];
extern u8 D_0068EBE0[];
extern u8 D_0068ED60[];
extern u8 D_0068E990[];

extern s8 D_0069066C;
extern s8 D_0069066D;
extern char D_00570F90[];
extern char D_00570F98[];
extern char D_00571028[];
int func_001E35D8(int a, int b, float x, float y);
void func_002D70D8(u32 a);

void TOSeqCtrl(int a);
void func_0021D6C8(void);
void TOBtlCtrlStatusWin(void);
void TOBtlCtrlEnemyLimit(void);
void func_0021A128(void);
void TOBtlCtrlLimitTimer(void);
void TOBtlCtrlAuronLimitWindow(void);
void TOBtlCtrlTidusLimitWindow(void);
void TOBtlCtrlLuluLimitWindow(void);
void func_0021FB00(void);
void graphicGetTime(void);
void TOBtlCtrlHelpWin(void);
void TOBtlCtrlInfoWin(void);
void TOBtlCtrlInfoWinMes(void);
void TOControlMsSetMenuCommand(void);

/* Text panel resource id, origin, and dimensions used by _TOBtlDrawLibraRight. */
extern s16 D_006925C2;
extern s16 D_0069264E, D_00692650, D_00692652, D_00692654;

#endif
