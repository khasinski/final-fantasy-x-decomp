/* EE Battle-Effect Overlay: group 0x11, file 09141 (shared -O0 helper)
 * .text: 0x01B078E0..0x01B079C0 (1 function, 224B).
 */
#include "common.h"

typedef struct {
    u8 pad00[0x20];
    float v20[4];       /* 0x20 */
    float v30[4];       /* 0x30 */
    u8 b40;             /* 0x40 */
} Ovl9141Data78E0;

typedef struct {
    Ovl9141Data78E0 *p; /* 0x00 */
    u8 flags;           /* 0x04 */
} Ovl9141Arg78E0;

extern void func_01B07BC8(Ovl9141Arg78E0 *arg);
extern void func_001B6B40(u8 idx, float *v);

void func_01B078E0(register Ovl9141Arg78E0 *arg)
{
    func_01B07BC8(arg);
    if ((u8)(arg->flags & 1) == 0) {
        return;
    }
    func_001B6B40(arg->p->b40, arg->p->v20);
    arg->p->v20[0] = arg->p->v20[0] * arg->p->v30[0];
    arg->p->v20[1] = arg->p->v20[1] * arg->p->v30[1];
    arg->p->v20[2] = arg->p->v20[2] * arg->p->v30[2];
    arg->p->v20[3] = arg->p->v30[3];
}
