/* EE Battle-Effect Overlay: group 0x11, file 09141 (shared -O0 helper)
 * .text: 0x01B07190..0x01B071E8 (1 function, 88B).
 */
#include "common.h"

typedef struct {
    u8 pad00[0x2C];
    float f2C;          /* 0x2C */
    u8 pad30;
    u8 b31;             /* 0x31 */
} Ovl9141Data7190;

typedef struct {
    Ovl9141Data7190 *p; /* 0x00 */
} Ovl9141Arg7190;

extern void func_01B073B8(Ovl9141Arg7190 *arg);

void func_01B07190(register Ovl9141Arg7190 *arg)
{
    func_01B073B8(arg);
    arg->p->f2C = 1.0f;
    arg->p->b31 = 0;
}
