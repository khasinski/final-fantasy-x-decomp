#ifndef FFX_Q6_H
#define FFX_Q6_H

#include "common.h"
#include "ffx/types.h"
#include "ffx/globals.h"
#include "ffx/funcs.h"

#define SYS_TBL ((SysEntry *)0x1D57300)

extern int D_00693D9C;
extern Task *D_0032602C;
extern int D_00326038;
extern int D_00323954;
extern u8 D_0069A686;
extern u8 D_0069A687;
extern u8 D_0069A7EC;
extern int D_0069A7D8[];
extern int D_0069A7DC;
extern u8 D_00572FD0[];
extern u8 D_0069BB84;
extern int D_0069A87C;
extern int D_0069A7FC;
extern int D_0069A800;
extern SysIf *D_0069A7F4;
extern int D_0069A7F0;
extern u8 D_0069A804;
extern int D_0069BBC0;
extern int D_0069BBF0;
extern int D_0069BB9C;
extern int D_0069BB98;
extern int D_0069BBEC;
extern int D_0069BBAC;
extern int D_0069BBE4;
extern int D_0069BBB0;
extern int D_0069BBB8;
extern int D_0069BBB4;
extern int D_0069BBE8;
extern int D_0069A7F8;
extern s8 D_0069BBBC;
extern s8 D_0069BBF4;
extern int D_0069A86C;
extern int D_0069BCD0;
extern int D_0069BCD4;
extern s8 D_00326439;
extern u8 D_00573078[];
extern int D_0069BCF8;
extern int D_0069BE2C;
extern int D_0069BE48;
extern int D_0069BE4C;
extern int D_0069BE44;
extern int D_0069BE50;
extern u8 D_00573A90[];
extern float D_0036E688[];
extern float D_0036E718[];
extern u8 D_00370918[];
extern u8 D_00704013;

extern Task *D_00693D58;
extern Task *D_00693D5C;
extern Task *D_00326030;
extern Task *D_00326034;
extern Task *D_0069A64C;
extern Task *D_0069A658;
extern Task *D_0069A648;
extern Task *D_0069A644;

extern Task *D_00694124;
extern Task *D_00694128;

extern Task *D_00693FD0;
extern Task *D_00693FD4;
extern Task *D_00693FD8;
extern Task *D_00693FDC;
extern Task *D_00693FE0;
extern Task *D_0069412C;
extern Task *D_00694130;
extern Task *D_00694120;



/* DEBT(NAME): 8-byte table entry, members guessed */
typedef struct Q6Ent8 { int w0; s16 h4; s16 h6; } Q6Ent8;

extern int D_0069A7C8;
extern u8 D_0069BBA0[];
extern u8 D_0069BBC8[];
extern int TkMenuHelpMessage;
extern int D_0069BB90;
extern int D_0069BB94;
extern Q6Ent8 D_0069BD08[];
extern Task *D_0069BCE0;
extern int D_0069BCF4;
extern u8 D_00326438;
extern int D_0069BEF8;
extern u8 D_006A3AB0[];
extern u8 D_00572218[];
extern u8 D_00572220[];
extern u8 D_00572370[];
extern u8 D_00572378[];
extern FlagRec **D_00693F70;
extern int D_00693E30;

typedef struct Pt16s { s16 x, y; } Pt16s;
extern u16 *D_00693D60;
extern Pt16s D_003260B8;
extern Pt16s D_003261D8;

extern int D_00694080;
extern int D_00694084;
extern u8 D_005726A8[];
extern u8 D_005726B0[];
extern int D_00694110;
extern u8 D_00572B08[];
extern int D_0069A610;
extern u8 D_0069A7C0;
extern u8 D_0069A7C1;
extern int D_0069A678;
extern int D_0069A67C;
extern int D_0069BBA8;
extern int D_0069BBF8;
extern u8 D_00573618[];
extern u8 D_00572A70[];
extern u8 D_00572A78[];
extern u8 D_0069BBD8[];
extern u8 D_00574D88[];
extern u8 D_00574DA8[];
extern u8 D_00703FFB;

extern u16 D_0069BCE4;

void func_00262B28(ChrWork *w); /* a ChrWork f34 callback */

Task *func_00243400(void);
int TkMn2ArmsRefreshArms(s32 *p);
void func_00233398();
int func_00233520(int a0, int a1);
void func_002396F8();
extern u8 D_00572078[];
extern u8 D_00572068[];
extern u8 D_00572070[];
extern u8 D_00571FA0[];
extern int D_00693E38;
extern int D_00693E34;
extern int D_00693ED4;
extern Pt16s D_00693F18;
extern Pt16s D_00693ED0;
extern s32 D_00693F6C; /* Word count; func_00235338 reads its low byte. */
extern Pt16s D_003260C0;
extern Pt16s D_003261E8;

extern u8 D_0069A7E0[4];
extern u8 D_0069A7E8[4];
void func_0023D990();
void func_0023D750();
void func_0023DC18();

extern u8 D_0069BBA0[];
extern int D_0069BBB8;

/* DEBT(NAME): guess, 16-byte DMA packet header (qword count in h0, VIF word at 0xC) written in front of GS packets */
typedef struct DmaTag { s16 qwc; u8 b2; u8 b3; int w4; int w8; int wC; } DmaTag;
extern u8 *D_0069BCDC;
u8 *func_001F85A8();
u8 *func_001F91D8();
u8 *func_002417D8();
u8 *func_001F8800();

extern u8 D_005733A8[];
extern u8 D_00573610[];
extern void (*D_0030E078)(void);
extern int D_0069A808[];
extern int D_0069A870;
extern int D_0069A874;

extern int D_006A3910;
extern int D_006A3914;
extern int D_006A3918;
extern int D_0069BF7C;
extern int D_0069C910[];
extern int D_00327000;
extern int D_0069CD44;

#endif
