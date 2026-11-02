#ifndef FFX_Q5_H
#define FFX_Q5_H

#include "common.h"
#include "ffx/types.h"
#include "ffx/globals.h"
#include "ffx/funcs.h"

/* Menu command object, one per slot of D_00668740 (state machine driven through the
   handler slots h[]). DEBT(NAME): member names are guesses from use. */
typedef s32 (*MenuFn)();
typedef struct MenuCmd {
    /* 0x00 */ s16 w00;
    /* 0x02 */ u8 pad02[2];
    /* 0x04 */ s16 id;
    /* 0x06 */ u8 pad06[0x08 - 0x06];
    /* 0x08 */ s32 x08;
    /* 0x0C */ u8 pad0C[0x12 - 0x0C];
    /* 0x12 */ s16 w12;
    /* 0x14 */ u8 pad14[0x1C - 0x14];
    /* 0x1C */ s16 w1C;
    /* 0x1E */ s16 w1E;
    /* 0x20 */ u8 pad20[0x2C - 0x20];
    /* 0x2C */ s16 state;
    /* 0x2E */ s16 sub;
    /* 0x30 */ s16 x;
    /* 0x32 */ s16 y;
    /* 0x34 */ s16 x1;
    /* 0x36 */ s16 y1;
    /* 0x38 */ s16 w;
    /* 0x3A */ s16 h;
    /* 0x3C */ u8 pad3C[0x4B - 0x3C];
    /* 0x4B */ u8 b4B;
    /* 0x4C */ u8 pad4C[0x84 - 0x4C];
    /* 0x84 */ s32 x84;
    /* 0x88 */ u8 *text;
    /* 0x8C */ s32 x8C;
    /* 0x90 */ s32 x90;
    /* 0x94 */ s32 x94;
    /* 0x98 */ s32 x98;
    /* 0x9C */ s32 x9C;
    /* 0xA0 */ u8 padA0[0xA4 - 0xA0];
    /* 0xA4 */ s32 xA4;
    /* 0xA8 */ u8 padA8[0xD0 - 0xA8];
    /* 0xD0 */ struct SlotZ *slot;
    /* 0xD4 */ MenuFn fD4;
    /* 0xD8 */ MenuFn fD8;
    /* 0xDC */ MenuFn fDC;
    /* 0xE0 */ MenuFn fn[10];
    /* 0x108 */ MenuFn f108;
    /* 0x10C */ MenuFn f10C;
} MenuCmd;

/* Smaller menu slot object of D_0066B508. */
typedef struct MenuSlot {
    /* 0x00 */ s16 w00;
    /* 0x02 */ u8 pad02[2];
    /* 0x04 */ s16 w04;
    /* 0x06 */ s16 w06;
    /* 0x08 */ s16 state;
    /* 0x0A */ u8 pad0A[0x10 - 0x0A];
    /* 0x10 */ s16 w;
    /* 0x12 */ u8 pad12[2];
    /* 0x14 */ s16 h;
    /* 0x16 */ u8 pad16[0x1E - 0x16];
    /* 0x1E */ s16 x;
    /* 0x20 */ s16 y;
    /* 0x22 */ s16 x1;
    /* 0x24 */ s16 y1;
    /* 0x26 */ u8 pad26[0x2E - 0x26];
    /* 0x2E */ s16 h2E;
    /* 0x30 */ s16 h30;
    /* 0x32 */ s16 h32;
    /* 0x34 */ s16 h34;
    /* 0x36 */ u8 b36;
    /* 0x37 */ u8 b37;
    /* 0x38 */ u8 b38;
    /* 0x39 */ u8 b39;
    /* 0x3A */ u8 pad3A[0x40 - 0x3A];
    /* 0x40 */ MenuFn fn[8];
} MenuSlot;

/* Slot object of D_00669AE0. DEBT(NAME): member names are offsets. */
typedef struct SlotZ {
    /* 0x00 */ u8 pad00;
    /* 0x01 */ s8 b1;
    /* 0x02 */ s8 b2;
    /* 0x03 */ s8 b3;
    /* 0x04 */ s8 b4;
    /* 0x05 */ s8 b5;
    /* 0x06 */ u8 pad06[1];
    /* 0x07 */ s8 b7;
    /* 0x08 */ u8 pad08[4];
    /* 0x0C */ s32 wC;
    /* 0x10 */ u8 pad10[8];
    /* 0x18 */ u8 x18[8];
    /* 0x20 */ u8 pad20[0x38 - 0x20];
    /* 0x38 */ struct { s16 h0; s16 h2; s16 h4; s16 h6; } ent[1]; /* DEBT(TYPE): count unknown, indexed up to b5 */
} SlotZ;
extern SlotZ *D_00669AE0[];

/* Cell reached through the 32-wide pointer table D_0066AB00. DEBT(NAME): guessed. */
typedef struct Cell {
    /* 0x00 */ s8 b0;
    /* 0x01 */ s8 b1;
    /* 0x02 */ u8 pad02[2];
    /* 0x04 */ s32 w4;
} Cell;
extern Cell *D_0066AB00[][32];

/* Pad state block at D_003238D0 (0x40 bytes). DEBT(NAME): guessed from the h12/h22 accessors. */
typedef struct PadBlock {
    /* 0x00 */ u8 pad00[0x12];
    /* 0x12 */ u16 h12;
    /* 0x14 */ u16 h14;
    /* 0x16 */ u16 h16;
    /* 0x18 */ u8 pad18[6];
    /* 0x1E */ u8 b1E;
    /* 0x1F */ u8 b1F;
    /* 0x20 */ u8 b20;
    /* 0x21 */ u8 b21;
    /* 0x22 */ u16 h22;
    /* 0x24 */ u16 h24;
    /* 0x26 */ u16 h26;
    /* 0x28 */ u8 pad28[0x18];
} PadBlock;
extern PadBlock D_003238D0;

/* Four-entry request queue (c_2203B8): count, halfword args, word args. DEBT(NAME): guessed. */
typedef struct ReqQueue {
    /* 0x00 */ s16 n;
    /* 0x02 */ u8 pad02[2];
    /* 0x04 */ s16 h[4];
    /* 0x0C */ s32 w[4];
} ReqQueue;
extern ReqQueue D_00692C00;
extern ReqQueue D_00692C20;

extern MenuCmd *D_00668740[];
extern MenuSlot *D_0066B508[];

extern s8 D_00319435;

extern u8 D_0056FE60[];

extern u8 D_006632D0[];

extern s32 D_0032363C;

extern u8 D_006673D8[];


extern u8 D_005700B0[];

extern u8 D_005702D0[];

extern s32 D_003241C0;

extern u8 D_00570358[];

extern s32 D_0068EEDC;

extern s32 D_0068EEE0;

extern s32 D_0068F190;

extern s32 D_0068F194;

extern s32 D_0068F198;

extern s32 D_0066B590;

extern s32 D_0066B594;

extern s32 D_0066B58C;

extern s32 D_0066B588;

extern s32 D_0066B598;

extern u8 D_0066B5A0[];

extern u8 D_0066BDA0[];

extern u8 D_00670DA0[];

extern s32 D_003238B4;

extern u8 D_00570A48[];

extern s8 D_00323958;

extern s16 D_003249A8;

extern s8 D_003249AA;

extern s16 D_006925C0;




extern s8 D_006928A0;

extern u16 D_003238E2;

extern u16 D_003238E4;

extern u16 D_003238E6;

extern u16 D_003238E8;

extern u16 D_003238EA;

extern u16 D_003238EC;

extern s32 D_00693088;

extern s32 D_0032579C;

extern s32 D_003257A0;

extern s32 D_0031FCBC;

extern s32 D_00693848;

extern s32 D_00693854;

extern s32 D_00693858;

extern s32 D_0069385C;

extern s16 D_00693A74;

extern s16 D_00693A76;




void TOSeqDraw(int i, int b);

void TODapsInit(void);

extern float D_0069266C;

extern float D_00692668;

extern s8 D_00690298;

extern s32 D_006932F8;

extern s16 D_00323638;

extern s16 D_0032363A;

extern s32 D_00693AB4;

extern s32 D_003257E8[]; /* 2 entries, [0] is current */

extern s32 D_003257F0[]; /* 2 entries, [0] is current */

extern s32 D_003257F8[]; /* 2 entries, [0] is current */

extern s32 D_00325800[]; /* 2 entries, [0] is current */

extern s32 D_003257E0;

extern s32 D_006632B4;

extern s32 D_006632B8;

extern s32 D_006632BC;

s32 TOGetWordCount(s32 id, s32 v);
s32 func_00202A10();
s32 func_00202B18();

void *func_001F6EC8(void *list);

void *func_001F5718(void *list);

void *func_001F8800(void *list, int a, int b);

void *TOAddPktMenuIcon(void *list, int a, int b, u8 c);

void *func_001F9938(void *list, int a, int b, int c);

void *func_001F9D50(void *list, int a, int b, int c);

void *func_001F4178(void *list, int a, int b, int c);

void *func_001F6F88(void *list, int a, int b, int c, int d);

void *func_001F8258(void *list, int a, int b, int c, int d);

void *func_001F7378(void *list, int a, int b, int c, int d);

void *func_001F8ED8(void *list, int a, int b, int c, int d);

void *func_001F3DE8(void *list, int a, int b, int c, int d);

void *func_001F3C58(void *list, int a, int b, int c, int d);

void *func_001F41C0(void *list, int a, int b, int c, int d);

void *func_001F42B8(void *list, int a, int b, int c, int d);

void *func_001F4818(void *list, int a, int b, int c, int d, int e);

void *func_001F48C8(void *list, int a, int b, int c, int d, int e);

void *func_001F4998(void *list, int a, int b, int c, int d, int e);

void *func_001F4A68(void *list, int a, int b, int c, int d, int e);

void *func_001F5290(void *list, int a, int b, int c, int d);

void *func_001F5380(void *list, int a, int b, int c, int d);

void *func_001F5418(void *list, int a, int b, int c, int d);

void *func_001F54B0(void *list, int a, int b, int c, int d);

void *func_001F5EC8(void *list, int a, int b, int c, int d);

void *func_001F5F50(void *list, int a, int b, int c, int d);

void *func_001F6400(void *list, int a, int b, int c, int d);

void *func_00200318(void *list, int a, int b, int c, int d);

void *func_001F3F28(void *list, int a, int b, int c, int d, int e);

void *func_001F40A0(void *list, int a, int b, int c, int d, int e);

void *func_001F4210(void *list, int a, int b, int c, int d, int e);

void *func_001F42F0(void *list, int a, int b, int c, int d, int e);

void *func_001F46A0(void *list, int a, int b, int c, int d, int e);

void *func_001FFE50(void *list, int a, int b, int c, int d, int e, int f, int g);

void *func_00200040(void *list, int a, int b, int c, int d, int e, int f, int g);

void *func_00200520(void *list, int a, int b, int c, int d, int e);

void *func_001F9B48(void *list, int a, int b, int c, int d, int e, int f, u8 g);

void *func_001F9200(void *list, int a, int b, int c, int d, int e, int f, u8 g);

void *func_001F4320(void *list, int a, int b, int c, int d, int e, int f);

void *func_001F9960(void *list, int a, int b, int c, u8 d, u8 e, u8 f, u8 g);

void *TOMkpShapePartIndexXYWHC2(void *list, int a, int b, int c, int d, int e, int f, int g);

extern Task *D_00693360;

extern Task *D_00693AA8;

extern Task *D_00693B78;

extern Task *D_00693C50;

extern Task *D_00693C54;

void func_00207F70(int a, int b, int c, int d, int e);

void func_00246CB8(int a, int b, int c);

extern s8 D_003249AC;

extern s16 D_00692500;

extern s32 D_00323640;

extern s8 D_00692C3C;

extern s16 D_00325694;

void SndStartStream(void);

extern s8 D_003249AB;

extern u8 D_00692480[];

extern s16 D_003249B8;

extern Ent8 D_00692928[];

void TOInitWindowCallBack(MenuSlot *s);

s32 func_00208730();

void *func_001F8418(void *list, int a, int b, int c, int d, int e, int f, int g);

void *func_001F85D0(void *list, int a, int b, int c, int d, int e, int f, int g);

void *func_001F9378(void *list, int a, int b, int c, int d, int e, int f, int g);

void *func_001F9D78(void *list, int a, int b, int c, int d, int e, int f, int g);

extern OffsetTable D_00321328;

extern OffsetTable D_00322190;

extern OffsetTable D_00323440;

extern char D_00571138[];

extern s8 D_003249AE;

extern char D_00570CC0[];

extern char D_00570FA0[];

int TOSeqCheckTermScene(int a, const char *name);

extern s32 D_00323950;

extern s32 D_00323954;



void func_002202D0(void);

extern CmdRec *D_0069384C;

extern Task *D_00693B80;

extern char D_00571BB0[];

extern Task *D_00693B84;

typedef struct Slot16 {
    s16 h0; /* dirty flag */
    s16 h2; /* x */
    s16 h4; /* y */
    s16 h6;
    s16 h8;
    s16 hA;
    s16 hC;
    s16 hE;
} Slot16;
extern Slot16 D_006672D8[];

void func_00227DE8(void);

int func_001E4CA8(int v);

int func_001E4C58(int v);

void MsMoveSplineSet(int v);

extern s8 D_00319433;

int func_001CFEC0(int v);

extern char D_00570C08[];

extern char D_00570C10[];

extern char D_00570C20[];

extern char D_00570C28[];

extern char D_00570C38[];

extern char D_00570C40[];

extern char D_005719B0[];

extern char D_005719B8[];

extern char D_005719C0[];

extern s32 D_00692038;

extern s32 D_00690698;

extern u8 D_00690678[];

int TOSeqStartSceneDrawContinue(int a, const char *name);

extern u8 D_00693090;

extern Task *D_00693860[];

extern s32 D_00693C00;

void func_00204C60(int id);

typedef struct Ent32 {
    s16 h0;
    s16 h2;
    s16 h4;
    u8 pad6[2];
    s8 b8; /* first byte of the name */
    u8 pad9[0x13];
    s32 w1C; /* table index for TkMenuIsTermScene */
} Ent32;
extern Ent32 D_0068F440[][8];

typedef struct FxState {
    s32 on;
    s16 x4;
    s16 x6;
    u8 pad8[8];
    float f10;
    float f14;
    float f18;
} FxState;
extern FxState D_00692658;

void TOInitPadData(void);

void TOSetExeMessageWindowArea(int a);

extern s32 D_003249A0;

int func_00214028();

extern char D_00570F80[];

extern s16 D_00692656;

extern s32 D_00693BEC;

int msVoiceCheckStanby(int a);

extern MenuSlot *D_0068F0A8[];

void TOOpenWindow(int i);

void TOOpenMessage(int i);

extern u8 D_0068FA60[];

extern s16 D_00690262;

extern s16 D_00324976;

extern s16 D_00690260;

extern char D_00570E28[];

int TOSeqStartSceneNoErase(int a, const char *name);

extern s32 D_00318C70;


extern Rec0E D_006930B8[];

typedef struct Rec12 {
    s16 h0;
    s16 h2;
    s16 h4;
    s16 h6;
    s32 w8;
} Rec12;
extern Rec12 D_0068F740[];

extern s32 D_0068F8C0;

extern s32 D_003257B0;

extern s32 D_003257AC;

extern s16 D_00693310;

extern s32 D_00693328;

extern s32 D_00693338[];

extern u16 *D_003257B4;

void func_001C03B0(int a, int b);

typedef struct FieldDesc {
    u8 pad00[0xC];
    u16 h0C;
    u16 h0E;
    s32 kind;
} FieldDesc;

void _TOBtlGetMainPad(void *o);

extern u32 D_006930A8;

extern u32 D_006930AC;

extern s32 D_00693AA0;

extern s32 D_00693ABC;

void func_00228B90(s16 *out, int a);

u8 *func_001E4A30(int i);

void func_001CF0C0(int id, int v);

int func_001CA948(int id, BtlChr *c);

void AtelCommonSetUp(int a, int b, int c, int d, int e, int f);

#endif
