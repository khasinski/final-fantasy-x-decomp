/* EE Battle-Effect Overlay: group 0x11, file 09141 (shared -O0 helper)
 * .text: 0x01B07838..0x01B078B8 (1 function, 128B).
 */
#include "common.h"

typedef struct {
    u8 pad00[0x30];
    float f30;          /* 0x30 */
    float f34;          /* 0x34 */
    float f38;          /* 0x38 */
    float f3C;          /* 0x3C */
} Ovl9141Data7838;

typedef struct {
    Ovl9141Data7838 *p; /* 0x00 */
} Ovl9141Arg7838;

extern void func_01B07A90(Ovl9141Arg7838 *arg);

void func_01B07838(register Ovl9141Arg7838 *arg)
{
    func_01B07A90(arg);
    arg->p->f30 = 1.0f;
    arg->p->f34 = 1.0f;
    arg->p->f38 = 1.0f;
    arg->p->f3C = 1.0f;
}
