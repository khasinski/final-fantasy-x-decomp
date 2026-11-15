#include "p8_overlay.h"

/* F5 TU rank 23, first function. The second one (func_01B03E28, task free) is parked in
 * overlays/wip/ovl_09053_task_free.c; the rest of the TU is ovl_09053_task2.c. */

extern P8Task *D_01B07B10; /* active list head */
extern P8Task *D_01B07B14; /* active list tail */
extern P8Task *D_01B07B18; /* free ring */
extern P8Task *D_01B07B1C; /* iteration cursor */
extern u16 D_01B07B20;     /* free count */

P8Task *func_01B03DA8(P8TaskFn fn)
{
    P8Task *t;

    if (D_01B07B20 == 0) {
        return 0;
    }
    t = D_01B07B18;
    t->prev->next = t->next;
    t->next->prev = t->prev;
    if (D_01B07B20 > 1) {
        D_01B07B18 = t->next;
    } else {
        D_01B07B18 = 0;
    }
    t->group = 0;
    t->w14 = 0;
    D_01B07B20--;
    t->fn = fn;
    t->link = 0;
    t->next = 0;
    t->prev = 0;
    t->top = t;
    return t;
}
