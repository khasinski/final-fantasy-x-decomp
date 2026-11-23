/* Overlay 09559: rank 560 control transform setter (0x01B06408..0x01B06478). */
#include "common.h"
#include "vu0.h"

typedef struct Control {
    u8 pad00[0x30];
    u_long128 unk30;
    u8 unk40[0x40];
    u8 pad80[0x10A];
    u8 unk18A;
} Control;

Control *func_01B02810(int);
void func_0026BE48(void *, int);
void func_002DCF48(void *, void *);

void func_01B06408(u_long128 *a0, int a1) {
    Control *c = func_01B02810(0);
    c->unk18A = 1;
    func_0026BE48(c, -a1 - 0x4000);
    MMI_COPY_LQ_A3(&c->unk30, a0);
    MMI_COPY_SQ_A3(&c->unk30);
    func_002DCF48(c->unk40, c);
}
