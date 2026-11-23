/* EE Battle-Effect Overlay: group 0x11, file 09396 (0x01B00B50..0x01B00C58)
 * Load base: 0x01B00000, .text: 0x01B00B50..0x01B00C58 (1 function)
 */
#include "common.h"

typedef struct OvlMgr {
    u8 pad00[0x2C];
    void *w2C;
} OvlMgr;

extern u8 D_01B00040[];
extern u8 D_01B00608[];
extern OvlMgr D_01B07AA0;
extern int D_01B07AE0;
extern void *D_01B07AE4;
extern u8 D_01B07AE8[];
extern void *D_01B07B68;
extern void *D_01B07B6C;
extern u8 D_01B0D5C0[];
extern u8 D_01B91540[];

extern void func_01B00C58(void);
extern void func_01B00CE8(void);

void *op_oef2_a_get(void *, int, int);
void func_01B043B0(void *, void *, void *, int);
void func_01B00D50(void);
void func_01B00DB0(void);
void func_01B07368(void *, void *);
void func_01B03998(int);
u8 *func_01B04128(void *);
void func_01B042F0(void *);

int func_01B00B50(void)
{
    u8 *buf = D_01B91540;
    OvlMgr *mgr = &D_01B07AA0;
    u8 *t;

    D_01B07AE0 = 0;
    D_01B07AE4 = buf + 0x40000;
    D_01B07B6C = buf + 0xE0000;
    D_01B07B68 = buf + 0x148000;
    mgr->w2C = op_oef2_a_get(D_01B0D5C0, 8, 0);
    func_01B043B0(mgr, D_01B00040, buf, 0x40000);
    func_01B00D50();
    func_01B00DB0();
    func_01B07368(D_01B07AE8, D_01B00608);
    func_01B03998(1);
    t = func_01B04128(func_01B00C58);
    t[0x18] = 1;
    func_01B042F0(t);
    t = func_01B04128(func_01B00CE8);
    t[0x18] = 2;
    func_01B042F0(t);
    return 0;
}
