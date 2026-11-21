/* EE Battle-Effect Overlay: group 0x11, file 09141 (shared -O0 helper)
 * .text: 0x01B07210..0x01B072E4 (1 function, 212B).
 */
#include "common.h"

typedef struct {
    u8 pad00[0x20];
    float v20[3];       /* 0x20 */
    float f2C;          /* 0x2C */
    u8 b30;             /* 0x30 */
    u8 b31;             /* 0x31 */
} Ovl9141Data7210;

typedef struct {
    Ovl9141Data7210 *p; /* 0x00 */
    u8 flags;           /* 0x04 */
} Ovl9141Arg7210;

extern void func_01B074F0(Ovl9141Arg7210 *arg);
extern void func_001B6898(u8 idx, float *v);
extern void func_001B6790(u8 idx, float *v);

void func_01B07210(register Ovl9141Arg7210 *arg)
{
    Ovl9141Data7210 *d;

    func_01B074F0(arg);
    if ((u8)(arg->flags & 1) == 0) {
        return;
    }
    d = arg->p;
    if ((u8)(d->b31 & 1) != 0) {
        func_001B6898(d->b30, d->v20);
    } else {
        func_001B6790(d->b30, d->v20);
    }
    arg->p->f2C = 1.0f;
}
