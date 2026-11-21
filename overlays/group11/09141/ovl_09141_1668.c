/* EE Battle-Effect Overlay: group 0x11, file 09141 (shared by 9140, 9141)
 * .text: 0x01B01668..0x01B01778 (1 function, 272B).
 */
#include "p6_overlay.h"

typedef struct {
    u8 pad00[0x2D0];
    float f2D0;         /* 0x2D0 */
    u16 h2D4;           /* 0x2D4 */
} Ovl9141Eff1668;

typedef struct {
    void *p00;          /* 0x00 */
    Ovl9141Eff1668 *eff; /* 0x04 */
} Ovl9141Msg1668;

typedef struct {
    u8 pad00[0x30];
    float f30, f34, f38;
    u8 pad3C[0x24];
    float f60, f64, f68, f6C;
} Ovl9141ObjC30;

typedef struct {
    void *p0;
    void *p1;
    float f2;
    float f3;
} Ovl9141Msg60E8;

extern void *D_01B004E0;
extern Ovl9141ObjC30 D_01B00C30;

extern void func_001C5E90(void *, int, int);
extern void func_01B060E8(void *);
extern void func_01B0C4B8(void *);

static __inline__ void call_60e8(Ovl9141ObjC30 *o, void *p1, float f2, float f3)
{
    Ovl9141Msg60E8 m;
    m.p0 = o;
    m.p1 = p1;
    m.f2 = f2;
    m.f3 = f3;
    func_01B060E8(&m);
}

static __inline__ void call_c4b8(void *p0)
{
    void *m[1];
    m[0] = p0;
    func_01B0C4B8(m);
}

void func_01B01668(Ovl9141Msg1668 *msg)
{
    Ovl9141Eff1668 *eff;
    float t;

    eff = msg->eff;
    t = eff->f2D0 + (1.0f / 30.0f);
    eff->f2D0 = t;
    switch (eff->h2D4) {
    case 0:
        if (t >= 0.95f) {
            /* DEBT(FAKE): pin h2D4 load to v1 to match ee-gcc register choice */
            register u16 h __asm__("$3");
            func_001C5E90(D_01B004E0, -5, 0);
            h = eff->h2D4;
            eff->h2D4 = h + 1;
        }
        break;
    case 1:
        if (t >= 2.0f) {
            D_01B00C30.f60 = D_01B00C30.f64 = D_01B00C30.f68 = D_01B00C30.f6C = 1.0f;
            D_01B00C30.f30 = D_01B00C30.f34 = D_01B00C30.f38 = 1.0f;
            call_60e8(&D_01B00C30, 0, 0.05f, 1.0f);
            call_c4b8(msg->p00);
        }
        break;
    }
}
