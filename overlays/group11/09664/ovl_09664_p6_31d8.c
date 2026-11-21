/* EE Battle-Effect Overlay: group 0x11, file 09664 (shared by 41 P6 overlays)
 * .text: 0x01B031D8..0x01B03230 (1 function, 88B).
 */
#include "p6_overlay.h"

typedef struct {
    u8 pad00[0x18];
    int state;              /* 0x18 */
} P6EffInit;

extern P6Node D_01B009F0;
extern void func_01B02D50(void *);
extern void func_01B0C7F0(void *);
extern void func_01B0CBF8(void *);

void func_01B031D8(P6EffInit *eff)
{
    void *msg[3];

    msg[0] = eff;
    msg[1] = (void *)func_01B02D50;
    msg[2] = eff;
    func_01B0C7F0(msg);

    msg[0] = &D_01B009F0;
    msg[1] = eff;
    func_01B0CBF8(msg);

    eff->state = 0;
}
