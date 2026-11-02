#ifndef FFX_B0_H
#define FFX_B0_H
/* Declarations for functions that use the BREAK() assert trap (see docs/ASM_POLICY.md section 4). */

#include "common.h"
#include "ffx/types.h"

int func_002FC4E0(char *path, int mode); /* open */
int func_002FCB20(int fd, char *buf, int size); /* read */
void printf_write(void);
int func_002FD910(char *dev, int a, int b, int c);
int func_00180B10(u32 group, int idx); /* size of a map file */
void func_00180A88(u32 group, int idx, char *buf); /* TkReadMapFile */
char *get_hdd_name(int a);
s64 func_002FEA60(int fd, s64 offset, int whence);
struct Q3Ent;
struct Sys597F00;
struct Q3Ent *func_001725A8(int a, int b);
void func_00172550(int a, int b);
int func_001723D8(struct Q3Ent *p, int n);
int func_0017B360(struct Sys597F00 *s, int h);
void pppSetFpTex(int h);
void func_0017DC70(struct Q3Ent *p);
void pppSetFpPdt(int h);
void func_0019CFD8(); /* DEBT(TYPE): like func_0019CD68, passes a0 on to Yn_PreBgSetData */
void yiAnimAttachDefault(struct Sys597F00 *s);
extern int D_00658D20;
extern int D_00658D24;
extern int D_00658D28;
extern int D_00658D2C;
extern char D_0056BEC0[]; /* "hdd0:" */

#endif
