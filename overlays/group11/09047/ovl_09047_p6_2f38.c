/* Shared P6 -O2 helper (hash 241420, 100B). */
#include "p6_overlay.h"

typedef struct {
    u8 pad00[0x18];
    int state;          /* 0x18 */
    float f1C;          /* 0x1C */
    float f20;          /* 0x20 */
} P6Eff2F38;

extern u8 D_01B008A0[];
extern void func_01B02BE8(void *);
extern void func_01B0B8A8(void *);
extern void func_01B0BCB0(void *);

void func_01B02F38(P6Eff2F38 *eff)
{
    void *msg[3];

    msg[0] = eff;
    msg[1] = func_01B02BE8;
    msg[2] = eff;
    func_01B0B8A8(msg);

    msg[0] = D_01B008A0;
    msg[1] = eff;
    func_01B0BCB0(msg);

    eff->state = 0;
    eff->f1C = eff->f20 = 0.0f;
}
