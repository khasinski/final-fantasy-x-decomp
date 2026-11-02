#ifndef FFX_G0_H
#define FFX_G0_H

#include "common.h"
#include "ffx/types.h"
#include "ffx/globals.h"
#include "ffx/funcs.h"

/* Declarations for the Gemini 100-function decompilation batch. */

/* c_104CC0 */
extern char D_00569460[];
extern char D_0057DAB8[];
typedef struct G0Ent16 {
    s32 w0;
    s32 w4;
    s32 w8;
    s32 wC;
} G0Ent16; /* DEBT(NAME): 16-byte records at D_0057E508 */
extern G0Ent16 D_0057E508[50];

/* c_11F190 */
extern s32 D_00307FE4;
extern s32 D_00307FE8;
extern s32 D_00307FEC;
extern s32 D_00307FF0;
extern u8 D_00307FF9[];
extern s8 D_00580B10[];
extern u8 D_02004A1C __asm__("0x2004A1C");
extern u8 D_02004A20 __asm__("0x2004A20");
extern u8 D_02004A24 __asm__("0x2004A24");
extern u8 D_02004A28 __asm__("0x2004A28");
extern u8 D_02004A2C __asm__("0x2004A2C");
void Sg_Assert(int a, int b, int c, int d, char *buf, int f);

/* c_146180 */
extern char D_0056AE28[];

/* c_14B428 */
typedef struct G0Res588 {
    u8 pad0[0xC];
    u16 hC;
    u8 padE[6];
    u16 h14;
    u16 h16;
    u16 h18;
} G0Res588; /* DEBT(NAME): resource header fields used by AtelCharSetUp */
extern char D_0056AF98[];

/* c_14C478 */
struct Ent24;
struct Rec14CE48;
int func_0014D180(struct Ent24 *e, struct Rec14CE48 *r);

/* c_157938 */
typedef struct G0S58FE60 {
    u8 pad0[0xF7140];
    s32 wF7140;
} G0S58FE60; /* DEBT(NAME) */
extern int D_0058FE58;
extern int D_0058FE5C;
extern G0S58FE60 *D_0058FE60;

#endif
