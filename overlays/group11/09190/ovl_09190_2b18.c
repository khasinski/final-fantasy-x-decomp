#include "p6_overlay.h"

typedef struct {
    u8 pad00[0x18];
    int state;
} P6EffInit9190;

extern P6Node D_01B00A80;
extern void func_01B022F8(void *);
extern void func_01B0CE78(void *);
extern void func_01B0D280(void *);

void func_01B02B18(P6EffInit9190 *eff)
{
    void *msg[3];

    msg[0] = eff;
    msg[1] = (void *)func_01B022F8;
    msg[2] = eff;
    func_01B0CE78(msg);

    msg[0] = &D_01B00A80;
    msg[1] = eff;
    func_01B0D280(msg);

    eff->state = 0;
}
