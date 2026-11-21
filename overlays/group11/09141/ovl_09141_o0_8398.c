/* EE Battle-Effect Overlay: group 0x11, file 09141 (shared -O0 helper)
 * .text: 0x01B08398..0x01B08400 (1 function, 104B).
 */
#include "common.h"

typedef struct {
    void *vt;           /* 0x00 */
    u8 pad04[0x1C];
    s32 w20;            /* 0x20 */
    s32 pad24;          /* 0x24 */
    unsigned long d28[1];  /* 0x28 */
} Ovl9141Data8398;

typedef struct {
    Ovl9141Data8398 *p; /* 0x00 */
} Ovl9141Arg8398;

extern u32 D_01B01110;
extern void func_01B084E0(Ovl9141Arg8398 *arg);

void func_01B08398(Ovl9141Arg8398 *arg)
{
    func_01B084E0(arg);
    arg->p->vt = &D_01B01110;
    arg->p->w20 = 0;
    *(unsigned long *)((u8 *)arg->p + 0x28) = 0;
}
