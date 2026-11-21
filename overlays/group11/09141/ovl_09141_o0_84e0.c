/* EE Battle-Effect Overlay: group 0x11, file 09141 (shared -O0 helper)
 * .text: 0x01B084E0..0x01B08540 (1 function, 96B).
 */
#include "common.h"

typedef struct {
    u8 pad00[0x20];
    s32 w20;            /* 0x20 */
    s32 w24;            /* 0x24 */
    s32 w28;            /* 0x28 */
    s32 pad2C;          /* 0x2C */
    s32 w30;            /* 0x30 */
} Ovl9141Data84E0;

typedef struct {
    Ovl9141Data84E0 *p; /* 0x00 */
} Ovl9141Arg84E0;

extern void func_01B08668(Ovl9141Arg84E0 *arg);

void func_01B084E0(register Ovl9141Arg84E0 *arg)
{
    func_01B08668(arg);
    arg->p->w30 = 0;
    arg->p->w20 = arg->p->w24 = arg->p->w28 = 0;
}
