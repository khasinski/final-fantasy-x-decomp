#ifndef FFX_Q3_H
#define FFX_Q3_H

#include "common.h"
#include "ffx/types.h"
#include "ffx/globals.h"
#include "ffx/funcs.h"

extern int D_0030D40C;

extern int D_0030D400;

extern u8 D_0030DCE0[]; /* DEBT(TYPE): element type unknown, only its address is used */

extern int D_0030DDF4;

extern u8 D_0030DE25;

extern int D_00595F50;

extern s8 D_0030DE24;

extern u8 D_0030DE38[]; /* DEBT(TYPE): element type unknown, only its address is used */

extern u8 D_0030DE41;

extern int D_0030DE44;

extern s8 D_0030DE50;

extern s8 D_0030DE81;

extern int D_0030DE90;

extern int D_0030E068;

extern int D_0030E060;

extern int D_00597A04;

extern u8 D_0056C1A0[]; /* DEBT(TYPE): element type unknown, only its address is used */

typedef struct Q3Grp { /* DEBT(NAME): 0x720-byte group, walked by yiAnimAttachDefault */
    u32 w00;
    u32 w04;
    u32 n;
    u32 id[0x1C5];
} Q3Grp;

typedef struct Q3Ent2 { /* DEBT(NAME): 0xC0-byte entries; entry count is read from Sys597F00.w687B8 */
    u64 d00; /* only known to make the entry 8-byte aligned (yiAnimAttachDefault addressing) */
    u8 pad_08[8];
    Blk64 m10[1]; /* 64-byte block copied as a whole by yiGetMatrixDObj & co. (a Blk64, see ffx/v1.h) */
    float v50[4];
    float v60[4];
    u8 pad_70[0x10];
    u16 h80;
    u8 pad_82[2];
    u16 h84;
    u16 h86;
    u8 pad_88[4];
    u32 n8C;      /* count of id90 */
    u16 id90[4];  /* DEBT(PADDING): length unknown */
    float f98;
    u8 pad_9C[4];
    u8 rgbaA0[4];
    u8 rgbaA4[4];
    u8 pad_A8[0x18];
} Q3Ent2;

typedef struct Q3Ent { /* DEBT(NAME): guessed: entry with a word at 4 */
    u8 pad_00[4];
    s32 w04;
} Q3Ent;




typedef struct Q3Res { /* 0x28-byte GS memory block of the yiImage resource manager (Sys597F00.res) */
    s32 used;
    u32 bp;     /* GS buffer pointer of the block */
    s32 tbw;
    u32 psm;
    u32 w;
    u32 h;
    s32 w18;
    struct YiImage *list; /* images placed in this block */
    u64 d20; /* DEBT(TYPE): unused here, but the entry is 8-byte aligned (address codegen of the res[] accesses) */
} Q3Res;

typedef struct Sys597F00 { /* DEBT(NAME): named after D_00597F00; large object, only these members are known */
    u8 pad_00000[0x67F20];
    s32 w67F20;
    u32 w67F24;
    u8 pad_67F28[0x18];
    s32 w67F40;
    s32 w67F44;
    s32 w67F48;
    s32 w67F4C;
    u8 pad_67F50[0xB0];
    float f68000[3];
    u8 pad_6800C[0x204];
    float f68210[4]; /* scale vector: yiGetBattleCenter multiplies by all four, c_172DA0 sets three */
    u8 pad_68220[0x10];
    float f68230[4];
    float f68240[4];
    u8 pad_68250[0x10];
    s32 w68260; /* count of v68270 */
    u8 pad_68264[0xC];
    float v68270[16][4]; /* DEBT(PADDING): length from the gap up to b68370 */
    u8 b68370;
    u8 b68371;
    u8 b68372;
    u8 b68373;
    float f68374;
    float f68378;
    float f6837C;
    float f68380;
    float f68384;
    float f68388;
    s32 w6838C;
    float f68390;
    u8 pad_68394[4];
    float f68398;
    float f6839C;
    u8 pad_683A0[8];
    u8 b683A8;
    u8 b683A9;
    u8 b683AA;
    u8 b683AB;
    u8 pad_683AC[0x40C];
    s32 w687B8;
    u8 pad_687BC[0x4];
    Q3Ent2 ent[1100];
    u8 pad_9C0C0[0x2718];
    s32 w9E7D8;
    u8 pad_9E7DC[4];
    Q3Res res[64]; /* GS memory blocks, count in w9E7D8 */
    s32 w9F1E0;
    s32 w9F1E4;
    struct Q3Ent *p9F1E8;
    struct Q3Ent *p9F1EC;
    u8 pad_9F1F0[0xF18];
    u32 wA0108;   /* count of grp */
    Q3Grp grp[64]; /* DEBT(PADDING): count guessed */
    u8 pad_BC90C[0x204];
    s32 wBCB10;
    s32 wBCB14;
    u8 pad_BCB18[0x4];
    u32 wBCB1C; /* capacity of the wBCB10 buffer in 16-byte units */
    s32 wBCB20;
    s32 wBCB24;
    u8 pad_BCB28[0x24];
    float fBCB4C;
    float fBCB50;
    float fBCB54;
    float fBCB58;
    float fBCB5C;
    float fBCB60;
    float fBCB64;
    float fBCB68;
    float fBCB6C;
    float fBCB70;
    u8 pad_BCB74[0x426C];
    u32 wC0DE0;
    float fC0DE4;
    u8 pad_C0DE8[0x10];
    float fC0DF8;
    float fC0DFC;
    float fC0E00;
    float fC0E04;
    s32 wC0E08;
    u8 bC0E0C;
    u8 bC0E0D;
    u8 bC0E0E;
    u8 pad_C0E0F[0x1];
    s32 wC0E10;
    s32 wC0E14;
    s32 wC0E18;
} Sys597F00;

extern Sys597F00 D_00597F00;

extern u8 D_00600130[]; /* DEBT(TYPE): element type unknown, only its address is used */

extern u8 D_00600140[]; /* DEBT(TYPE): element type unknown, only its address is used */

extern u8 D_00600280[]; /* DEBT(TYPE): element type unknown, only its address is used */

extern int D_00307F30;

extern int D_0065FD28;

extern int D_0031712C;

extern int D_0058FE50;

extern int D_00307F2C;

extern u8 D_00313850[]; /* DEBT(TYPE): element type unknown, only its address is used */

typedef struct Obj1A0B70 { /* DEBT(NAME): named after its chunk; only flag words are known */
    u8 pad_000[0xBC];
    u32 flagsBC;
    u8 pad_0C0[0x1C0];
    u32 flags280;
    u8 pad_284[0xAC];
    u32 flags330;
} Obj1A0B70;

void func_001A1460(Obj1A0B70 *o);

extern int D_00591EC0;

extern int D_00591EC4;

extern u16 D_00597A18;

extern int D_0030E9E0;

extern int D_0030E9E4;

typedef struct Q3Link { /* DEBT(NAME): guessed: node with a link at 0x14 */
    u8 pad_00[0x14];
    struct Q3Link *link14;
} Q3Link;

extern int D_00314250;

extern int D_00314254;

extern u8 D_0056BB30[]; /* DEBT(TYPE): element type unknown, only its address is used */

extern u8 D_0056BB20[]; /* DEBT(TYPE): element type unknown, only its address is used */

extern u8 D_0056BB50[]; /* DEBT(TYPE): element type unknown, only its address is used */

typedef struct Q3Obj20 { /* DEBT(NAME): guessed: object carrying a callback at 0x20 */
    u8 pad_00[0x20];
    void (*fn)(void);
} Q3Obj20;

extern u8 D_00591F50[]; /* DEBT(TYPE): element type unknown, only its address is used */

extern int D_0030D414;

extern u8 *D_0030DDF0;

extern int D_0030DE58;

typedef struct Rec78D898 { /* DEBT(NAME): named after D_0078D898, 0x30 byte entries */
    void *p00;
    s32 w04;
    s32 w08;
    u8 pad_0C[1];
    s8 b0D;
    s8 b0E;
    u8 pad_0F[0x21];
} Rec78D898;

typedef struct Rec597490 { /* DEBT(NAME): named after D_00597490, 0x18 byte entries */
    u64 q00;
    u64 q08;
    s8 b10;
    u8 pad_11[7];
} Rec597490;

extern Rec78D898 D_0078D898[];

extern Rec597490 D_00597490[];

extern s8 D_0030DE94;

typedef struct Q3Tab { /* DEBT(NAME): table of words indexed by a halfword at 6 */
    u8 pad_00[6];
    s16 idx;
    u8 pad_08[4];
    int *tab;
} Q3Tab;

extern char D_0056C6B0[]; /* DEBT(TYPE): source-file string handed to the allocator */

typedef struct Q3Ctx2 { /* DEBT(NAME): guessed */
    u8 pad_00[0x30];
    int w30;
} Q3Ctx2;

typedef struct Q3Ctx { /* DEBT(NAME): guessed */
    u8 pad_00[0xC];
    Q3Ctx2 *sub;
} Q3Ctx;

extern u8 D_0030DE19;

extern void (**D_00595F64)(void);

typedef struct Obj17A110 { /* DEBT(NAME): named after its chunk; only cleared members are known */
    u8 v00[0x10];  /* three 16-byte blocks copied with func_0017AB10 */
    u8 v10[0x10];
    u8 v20[0x10];
    s16 h30;
    s16 h32;
    s16 h34;
    s16 h36;
    float f38;
    u8 pad_3C[8];
    s32 w44;
    s32 w48;
    s32 w4C;
    s32 w50;
    s32 w54;
    s32 w58;
} Obj17A110;

typedef struct Obj187260 { /* DEBT(NAME): named after its chunk; only cleared members are known */
    s16 h00;
    s16 h02;
    s16 h04;
    s16 h06;
    s16 h08;
    s16 h0A;
    u8 pad_0C[8];
    s32 w14;
    s32 w18;
    u8 pad_1C[8];
    s32 w24;
} Obj187260;

/* memory-mapped EE register (DMA channel registers at 0x1000A000 / 0x1000B400) */
#define Q3_HW32(addr) (*(volatile u32 *)(addr))

extern s8 D_00591F48;

extern s8 D_00591F49;

extern char D_00597A08[];

extern int D_00313C90[];

typedef struct Obj19FB60 { /* DEBT(NAME): named after its chunk; only a selector byte at 0x13 is known */
    u8 pad_00[0x13];
    u8 sel;
} Obj19FB60;

extern s16 D_00591E70;

extern u32 *D_0078E4C0;

extern int D_0030DE2C;

extern s8 D_0030E0C4;

extern int D_0030E0DC;

extern int D_0030E0E0;

extern s8 D_0030E0C5;

extern u16 D_00597A1C;

extern u8 D_005661F4;

void func_00175D50(Sys597F00 *s);

void func_00175D88(Sys597F00 *s);

void yiRender_resetobj(Sys597F00 *s);

extern u8 D_0056C958;

typedef struct Obj17DBA0 { /* DEBT(NAME): named after its chunk; only the initialised members are known */
    s32 w00;
    u8 b04;
    u8 pad_05[0x10B];
    s32 w110;
    s32 w114;
    u8 pad_118[0xC];
    u32 w124;
    u8 pad_128[0x1C];
    s32 w144;
    u8 pad_148[0x28];
    s32 w170;
    s32 w174;
} Obj17DBA0;

typedef struct Obj190E38 { /* DEBT(NAME): named after its chunk */
    u8 pad_00[0x14];
    s32 w14;
    u8 pad_18[8];
} Obj190E38;

typedef struct Obj1A1740 { /* DEBT(NAME): named after its chunk */
    u8 pad_00[0x44];
    s16 h44;
    u8 pad_46[0x4A];
} Obj1A1740;

typedef struct S58FE54 { /* DEBT(NAME): named after D_0058FE54; large object, only these words are known */
    u8 pad_00000[0x10100];
    s32 w10100[1];
    u8 pad_10104[0x2DDC0 - 0x10104];
    u8 buf2DDC0[0x5051C - 0x2DDC0]; /* handed to func_0015ACC0 by func_0015E858 */
    s32 w5051C;
    u8 pad_50520[0x24];
    s32 w50544;
    s32 w50548;
    s32 w5054C[1];
    u8 pad_50550[0x4C];
    u8 *p5059C;
    u8 pad_505A0[0x20];
    u32 w505C0;
    u8 pad_505C4[0x104];
    s32 w506C8;
    s32 w506CC;
    s32 w506D0;
    s32 w506D4;
    u8 pad_506D8[0xC];
    s32 w506E4;
    s32 w506E8;
    u8 pad_506EC[0xC];
    s32 w506F8;
    u8 pad_506FC[0xC];
    s32 w50708;
    u8 pad_5070C[8];
    s32 w50714;
    u8 pad_50718[8];
    s32 w50720;
    s32 w50724;
    s32 w50728;
    s32 w5072C;
    u8 pad_50730[0x20];
    s32 w50750;
    u8 pad_50754[4];
    s32 w50758;
    s8 b5075C;
    s8 b5075D;
    u8 pad_5075E[6];
    s8 b50764;
    s8 b50765;
    s8 b50766;
    s8 b50767; /* != 0: mix the stereo halves (func_0015AF10) */
    s8 b50768;
    s8 b50769;
    s8 b5076A;
    s8 b5076B;
    u8 pad_5076C[1];
    s8 b5076D;
    u8 pad_5076E[1];
    u8 b5076F;
    u8 pad_50770[2];
    u8 b50772;
    s8 b50773;
} S58FE54;

extern int D_0030D3EC;

extern S58FE54 *D_0058FE54;

extern u8 D_0056B950[]; /* DEBT(TYPE): element type unknown, only its address is used */

typedef struct Q3Px { /* DEBT(NAME): 4-byte element of which only the first byte is read */
    u8 v;
    u8 pad[3];
} Q3Px;

typedef struct Q3Vec30 { /* DEBT(NAME): object with a float triple at 0x30 */
    u8 pad_00[0x30];
    float x, y, z;
} Q3Vec30;

typedef struct Obj190E70 { /* DEBT(NAME): named after its chunk; owns a buffer at 0xC */
    u8 pad_00[0xC];
    void *buf;
} Obj190E70;

typedef struct Obj195078 { /* DEBT(NAME): named after its chunk; owns a buffer at 0x14 */
    u8 pad_00[0x14];
    void *buf;
} Obj195078;

extern int D_0030D410;

extern char D_00597958[];

extern char D_0056BD60[];

extern s8 D_0030DE51;

extern int D_0030D3F0;

extern int D_0030D3FC;

extern char D_0056D938[]; /* DEBT(TYPE): source-file string handed to the allocator */

extern char D_0056D980[]; /* DEBT(TYPE): source-file string handed to the allocator */

extern char D_0056DA88[]; /* DEBT(TYPE): source-file string handed to the allocator */

extern char D_0056DB60[]; /* DEBT(TYPE): source-file string handed to the allocator */

extern char D_0056DBA8[]; /* DEBT(TYPE): source-file string handed to the allocator */

extern char D_0056DBB8[]; /* DEBT(TYPE): source-file string handed to the allocator */

extern char D_0056DE20[]; /* DEBT(TYPE): source-file string handed to the allocator */

extern char D_0056DE70[]; /* DEBT(TYPE): source-file string handed to the allocator */

typedef struct Q3Slot8 { /* DEBT(NAME): guessed: owner of a sub-object at 8 */
    u8 pad_00[8];
    void *buf;
} Q3Slot8;

typedef struct Obj199038 { /* DEBT(NAME): named after its chunk; 0x120 bytes */
    s32 w00;
    u8 pad_04[0xF8];
    float fFC;
    u8 pad_100[0x20];
} Obj199038;

extern char D_0056DE50[]; /* DEBT(TYPE): source-file string handed to the allocator */

extern char D_0056DE60[]; /* DEBT(TYPE): source-file string handed to the allocator */

extern int D_00313720;

typedef struct Obj195B68 { /* DEBT(NAME): named after its chunk; 0x80 bytes */
    u8 pad_00[0x6C];
    float f6C;
    u8 pad_70[0x10];
} Obj195B68;

void func_00188E40(Sys597F00 *s, int a);

/* Data used by the newly recovered script/debug helpers. */
extern s32 D_0030D3F4;
extern s32 D_0030D3F8;
extern s32 D_0030DDF8;
extern s8 D_0030DDFC;
extern s32 D_0030DE00;
extern s32 D_0030DE04;
extern s32 D_0030E094;
extern s32 D_00595F54;
extern s32 D_00595F58;
extern s32 D_00595F5C;

/* DEBT(TYPE): reset globals; pointer views follow the existing m2c context. */
extern s32 D_0030E0BC;
extern s32 D_00597A0C;
extern s32 D_00597A14;
extern s32 D_0030E0CC;
extern s32 D_0030E0B8;
extern void *D_0030E0AC;
extern s32 D_00597A24;
extern void *D_0030E0A8;
extern void *D_0030E0C8;
extern s32 D_00597E30;
extern void *D_0030E0B0;
extern void *D_0030E0B4;
extern s16 D_00597A1A;

int chr_texanim_draw_sub_old(int index, int value);
int chr_texanim_draw_sub_new(int index, int value);

#endif
