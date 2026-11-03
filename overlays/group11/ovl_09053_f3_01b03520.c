#include "p7_overlay.h"

/* F3 TU rank 53 without its last function (func_01B03600, a 16-byte copy through lq/sq a3,
 * see overlays/wip/ovl_09053_f3_01b03600.c). */

typedef struct P7Motion {
    int w00;
    int idx;            /* 0x04 */
    int chr;            /* 0x08 */
    int w0C;
    int w10;
    int done;           /* 0x14 */
    int w18;
    s16 keep;           /* 0x1C */
} P7Motion;

extern u_long128 D_01B05EE0;
extern u_long128 D_01B05EF0;
extern u_long128 D_01B05F00;

void func_01B03520(P7Motion *m, int speed)
{
    func_01B02210(m->idx, speed);
}

void func_01B03528(P7Motion *m)
{
    if (m->keep == 0) {
        MsEffectEndMotion(m->chr);
    }
    m->done = 1;
}

void func_01B03568(void)
{
    Sg_Blur(0);
    func_001AAC18(0.0f, 0.0f);
}

void func_01B03590(void)
{
    func_00173730(&D_01B05EE0);
    func_001737A8(&D_01B05EF0);
    yiGetBackColor(&D_01B05F00);
}

void func_01B035C8(void)
{
    func_00173720(&D_01B05EE0);
    func_00173740(&D_01B05EF0);
    func_00173650(&D_01B05F00);
}
