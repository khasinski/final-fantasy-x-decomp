/* EE Battle-Effect Overlay: group 0x11, file 09141 (shared -O0 helper)
 * .text: 0x01B08580..0x01B085E8 (1 function, 104B).
 */
#include "common.h"

typedef struct {
    u8 pad00[0x24];
    s32 w24;            /* 0x24 */
    u8 pad28[0x08];
    s32 w30;            /* 0x30 */
    u8 b34;             /* 0x34 */
} Ovl9141Data8580;

typedef struct {
    Ovl9141Data8580 *p; /* 0x00 */
} Ovl9141Arg8580;

extern void func_01B086D0(Ovl9141Arg8580 *arg);
extern s32 func_01B087E0(u8 a);

void func_01B08580(register Ovl9141Arg8580 *arg)
{
    func_01B086D0(arg);
    arg->p->w24 = func_01B087E0(arg->p->b34) + arg->p->w30;
}
