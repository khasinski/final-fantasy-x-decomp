/* EE Battle-Effect Overlay: group 0x11, file 09122 (shared by 9122, 9123)
 * .text: 0x01B01388..0x01B01408 (1 function, 128B).
 */
#include "p6_overlay.h"

typedef struct {
    u8 pad00[0x2D0];
    float f2D0;         /* 0x2D0 */
    u16 h2D4;           /* 0x2D4 */
} Ovl9122Eff1388;

typedef struct {
    void *p00;          /* 0x00 */
    Ovl9122Eff1388 *eff; /* 0x04 */
} Ovl9122Msg1388;

extern void *D_01B00558;
extern void func_001C5E90(void *, int, int);
extern void func_01B09DA8(void *);

static __inline__ void call_9da8(void *a0)
{
    void *m[1];
    m[0] = a0;
    func_01B09DA8(m);
}

void func_01B01388(Ovl9122Msg1388 *msg)
{
    Ovl9122Eff1388 *eff;
    float t;

    eff = msg->eff;
    t = eff->f2D0 + (1.0f / 30.0f);
    eff->f2D0 = t;
    if (eff->h2D4 == 0 && t >= 0.12f) {
        /* DEBT(FAKE): pin msg->p00 to v1 to match ee-gcc register choice */
        register void *p0 __asm__("$3");
        func_001C5E90(D_01B00558, -5, 0);
        p0 = msg->p00;
        call_9da8(p0);
    }
}
