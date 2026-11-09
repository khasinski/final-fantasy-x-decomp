#ifndef FFX_T4_H
#define FFX_T4_H

void TOBtlStartLimitTimer(void);
void TOBtlStopLimitTimer(void);
void TOBtlStandbyLimitTimer(void);
float func_0021AA78(void);
float func_0021AA88(void);

int func_002EEE88(const void *a, const void *b, int n);
void func_002EEFCC(void *dst, const void *src, int n);

/* stick-rotation patterns (c_21A660): copied from the rodata object; the original was likely a local
   initialiser, which would put a gcc .rodata block into a switch chunk */
typedef struct DirSeq8 {
    s8 d[8];
} DirSeq8;
extern DirSeq8 D_005710B0;
extern DirSeq8 D_005710B8;
extern char D_00570F80[];
extern char D_00570F88[];
extern char D_00571090[];
extern char D_00571098[];
extern char D_005710A0[];
extern char D_005710A8[];
extern char D_005710C0[];
extern char D_005710C8[];
extern char D_005710D0[];

float func_00265F30(int i);
float func_00265F60(int i);
int func_00265F78(int i);
int func_00265FB8(int i);
extern char D_00571010[];
extern char D_00571018[];
extern char D_00571020[];

/* Item list window (c_211C28): a grid of item ids drawn as rows of fields.
   DEBT(NAME): member names come from how func_00211E80 uses them. */
typedef struct MenuList {
    /* 0x00 */ u8 pad0[6];
    /* 0x06 */ s16 kind;
    /* 0x08 */ s16 owner;
    /* 0x0A */ u8 padA[0x20 - 0xA];
    /* 0x20 */ s16 *items;
    /* 0x24 */ s32 count;
    /* 0x28 */ s16 nfields;
    /* 0x2A */ s16 showZero;
    /* 0x2C */ u16 fields[6]; /* hi byte: field kind, lo byte: argument */
    /* 0x38 */ s16 cols;
    /* 0x3A */ s16 rows;
    /* 0x3C */ s16 h3C;
    /* 0x3E */ u8 pad3E[2];
    /* 0x40 */ s16 top;
    /* 0x42 */ s16 cursor;
    /* 0x44 */ s16 h44;
    /* 0x46 */ u8 pad46[0x56 - 0x46];
    /* 0x56 */ s16 posX;
    /* 0x58 */ s16 posY;
    /* 0x5A */ u8 pad5A[0x62 - 0x5A];
    /* 0x62 */ s16 colWidth;
    /* 0x64 */ s16 h64;
    /* 0x66 */ s16 nameWidth;
    /* 0x68 */ s16 frame[4];
    /* 0x70 */ s16 area[4];
    /* 0x78 */ void (*draw)(struct MenuList *list);
    /* 0x7C */ u8 pad7C[0xA0 - 0x7C]; /* task handler slots, see R4Task */
    /* 0xA0 */ s32 nlabels;
    /* 0xA4 */ s32 label[2]; /* message texts */
} MenuList;
extern s16 D_00324300; /* default list position */
extern s16 D_00324302;
extern s16 D_00325022; /* minimum frame right edge */
void TOBtlScanCommandWH(MenuList *list);

extern int D_00324304;
extern int D_00324308;
void func_001F3068(int x, int y, int icon); /* DEBT(TYPE): defined with a u8 icon in c_1F24B8 */
void func_001F3580(int digits, int value, int x, int y, int dim);
void func_001FBFB8(int x, int y, int w, int h, int pages, int rows, int page);
int MsGetCommandMP(int owner, OfsTbl *ent);
int TOCheckBtlCommandUse(int owner, int item);

/* boot/load sequencer of c_20B6A8 */
extern s32 D_003238A8; /* step */
extern s32 D_003238AC;
extern s32 D_003238B0; /* done flag */
extern s32 D_003238B8;
extern u8 D_00324140[];
extern u8 D_00323960[];
extern char D_005708A0[];
extern char D_005708B0[];
void *TOGetFFXToAlbhedTblAdrs(void);
void func_0020DC78(int i);
void TODapsSetPos(int x, int y);

void TODapsPrintf(char *fmt, ...);

/* 2D draw primitive keyframe (c_20E7E0); the low 11 bits of the flags select the kind.
   R4Msg is a view of the same record. DEBT(NAME): member names are offsets. */
typedef struct UiPrim {
    /* 0x00 */ u16 flags;
    /* 0x02 */ u16 arg;
    /* 0x04 */ u32 col0; /* RGBA, one byte per channel */
    /* 0x08 */ u32 col1;
    /* 0x0C */ s16 x;
    /* 0x0E */ s16 y;
    /* 0x10 */ s16 p10;
    /* 0x12 */ s16 p12;
    /* 0x14 */ union {
        s16 s;
        u16 u;
    } p14;
    /* 0x16 */ s16 p16;
    /* 0x18 */ s16 p18;
    /* 0x1A */ u8 pad1A[2];
    /* 0x1C */ s16 p1C;
    /* 0x1E */ s16 p1E;
} UiPrim;

#define UI_PRIM_KIND 0x7FF
#define UI_PRIM_EASE 0x7000 /* easing of the blend, see func_0020F750 */
#define UI_PRIM_SCREEN 0x8000 /* add the screen offset D_00690288/D_0069028C */

/* blend between key values v and w: t == 1 gives v */
#define UI_LERP(v, w, t) ((w) == (v) ? (v) : (int)((w) * (1.0f - (t)) + (v) * (t)))

extern s32 D_00690288; /* screen offset x */
extern s32 D_0069028C; /* screen offset y */
void func_001FD0A0(UiPrim *p);
void func_001FCF88(UiPrim *p);
void func_001FD260(UiPrim *p);
struct R4Msg;
void TOMakePktSeqPrimMes(struct R4Msg *m);
void TOMakePktSeqPrimFunc(struct R4Msg *m);

/* group of animation tracks: count, then the tracks */
typedef struct R4AnimGrp {
    s32 count;
    R4Anim ent[1];
} R4AnimGrp;

void func_0020EEB8(u16 flags, UiPrim *a, UiPrim *b, float t);
float func_002E8648(float x);
float func_0020F750(u16 flags, int t, int dur);

/* window frame metrics, indexed by R4Hdr.h4 */
typedef struct R4Frame {
    u16 x;
    u16 y;
    u16 w;
    u16 h;
} R4Frame;
extern R4Frame D_00323848[];
s32 TOGetMessageWindowMode(void);

/* DEBT(NAME): clamp used by the window placement code of c_20A6A8 */
#define R4_CLAMP(v, lo, hi) ((v) > (hi) ? (hi) : (v) < (lo) ? (lo) : (v))

/* task handlers installed by TOBtlSetCallback */
int MsCheckLeftWindow(int id);
void func_00212888(int t);
int func_00210898();
int func_00210A38();
int func_002114A0();
int func_002114D8();
int func_002114F8();
int func_00211520();
int func_00210D18();
int func_00210D50();
int func_00210D70();
int func_00210D98();
int func_00211C38();
int func_00211C70();
int func_00211C90();
int func_00211CB8();
int func_002124F8();
int func_00212530();
int func_00212550();
int func_00212578();
int func_00212338();
int func_00212370();
int func_00212390();
int func_002123B8();
int func_00214210();
int func_002142E8();
int func_002142F0();
int func_00214310();
int func_00214320();
int func_00212640();
int func_00212678();
int func_00212698();
int func_002126C0();
int func_00212938();
int func_00212970();
int func_00212BF8();
int func_00212F30();


void func_00207F60(int text, int x, int y, u8 dim);
void func_0021F448(int a, int x, int y);

void func_001F31A0(int c, int x, int y);

/* GS image upload packet: GIF tag + BITBLTBUF/TRXPOS/TRXREG/TRXDIR (A+D), then the IMAGE tag */
extern u64 D_0068F0D0[24];

/* texture rectangle, 4 bytes into the entry returned by func_001FD768 */
typedef struct TexRect {
    u16 u;
    u16 v;
    u16 w;
    u16 h;
} TexRect;
#define TEX_RECT(id) ((TexRect *)(func_001FD768(id) + 4)) /* DEBT(CAST): func_001FD768 returns the entry address as int */
#define TEX_RECT0(id) ((TexRect *)(func_001FD6F0(id) + 4)) /* DEBT(CAST): entry address returned as int */
void TODrawMenuPlateXYWC2_Rfix(int a, int b, int x, int y, int w, u32 c0, u32 c1);

extern char D_00570A38[];
void func_0020CC20(const char *name, int id, void *buf);

extern s8 D_003238C8;
extern s8 D_003238C9;
extern s8 D_003238CA;
extern u32 D_0068F42C;
void func_0020A948(int i);
void func_0020B6F0(s32 v);

extern char D_00570A68[];

int func_001F1EB8(void); /* DEBT(TYPE): defined void in c_1F1408, hands back func_001EFA30()'s result by tail call */

void MsGetChrTargetPos(int id, s32 *a, s32 *b); /* DEBT(TYPE): defined with a u8 id in c_1B6B40 */
void func_001F23E8(void);
void func_001FE7F8(int kind, int x, int y);

void func_001F56E8(void);

/* root of an animation bank (func_0020EC90) */
typedef struct R4AnimRoot {
    /* 0x00 */ s32 hash[16]; /* byte offsets of the name hash chains */
    /* 0x40 */ u8 pad40[0x80 - 0x40];
    /* 0x80 */ s32 ofs;      /* byte offset of the command offset table */
    /* 0x84 */ u8 pad84[0x90 - 0x84];
    /* 0x90 */ s32 group[16]; /* byte offsets of track id lists */
} R4AnimRoot;
int func_0020FA50(u8 *root, R4AnimGrp *grp, R4Anim *an, s32 *ofs);
int TkMenuExecScene(int a, int idx);
int TkMenuGetSceneHandle(int a, const char *name);
int func_002F05E8(const void *a, const void *b);

/* window frame drawn by the UiWidget draw callbacks (c_208588) */
typedef struct UiBox {
    s16 x0;
    s16 y0;
    s16 x1;
    s16 y1;
} UiBox;
typedef struct UiFrame {
    UiRgba col;
    UiBox box;
    u8 pad0C[8]; /* DEBT(PADDING): size taken from the stack frame of the users */
} UiFrame;
void func_001FA548(int x, int y, int w, int h);
void func_001F1D60(int x0, int y0, int x1, int y1);

#endif
