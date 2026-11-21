/* EE Battle-Effect Overlay: group 0x11, file 09354 (shared by 9354, 9203)
 * .text: 0x01B01AC8..0x01B01B24 (1 function, 92B).
 */
#include "p6_overlay.h"

typedef struct {
    u8 pad00[0x18];
    s32 w18;            /* 0x18 */
    u8 pad1C[0xC];
    s32 w28;            /* 0x28 */
} Ovl9354Eff;

extern u8 D_01B00790[];
extern void func_01B01828(void *);
extern void func_01B0A1E8(void *);
extern void func_01B0A5F0(void *);

static __inline__ void call_a1e8(void *a0, void *a1, void *a2)
{
    void *m[3];
    m[0] = a0;
    m[1] = a1;
    m[2] = a2;
    func_01B0A1E8(m);
}

static __inline__ void call_a5f0(void *a0, void *a1)
{
    void *m[2];
    m[0] = a0;
    m[1] = a1;
    func_01B0A5F0(m);
}

void func_01B01AC8(Ovl9354Eff *eff)
{
    call_a1e8(eff, (void *)func_01B01828, eff);
    call_a5f0(D_01B00790, eff);
    eff->w28 = 0;
    eff->w18 = 0;
}
