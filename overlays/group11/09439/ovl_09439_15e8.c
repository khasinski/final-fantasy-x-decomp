/* EE Battle-Effect Overlay: group 0x11, file 09439 (0x01B015E8..0x01B016E8)
 * Load base: 0x01B00000, .text: 0x01B015E8..0x01B016E8 (1 function)
 */
#include "common.h"

typedef struct OvlMgr {
    u8 pad00[0x2C];
    void *w2C;
} OvlMgr;

extern u8 D_01B00040[];
extern u8 D_01B00588[];
extern OvlMgr D_01B080D8;
extern void *D_01B08118;
extern void *D_01B0811C;
extern u8 D_01B08120[];
extern void *D_01B081A0;
extern void *D_01B081A4;
extern u8 D_01B0DF70[];
extern u8 D_01BD3200[];

extern void func_01B016E8(void);
extern void func_01B01780(void);

void *op_oef2_a_get(void *, int, int);
void func_01B04968(void *, void *, void *, int);
void func_01B017F0(void);
void func_01B07920(void *, void *);
void func_01B03F50(int);
u8 *func_01B046E0(void *);
void func_01B048A8(void *);

int func_01B015E8(void)
{
    u8 *buf = D_01BD3200;
    OvlMgr *mgr = &D_01B080D8;
    u8 *t;

    D_01B0811C = buf + 0x40000;
    D_01B081A4 = buf + 0x140000;
    D_01B081A0 = buf + 0x1A8000;
    D_01B08118 = buf;
    mgr->w2C = op_oef2_a_get(D_01B0DF70, 8, 0);
    func_01B04968(mgr, D_01B00040, D_01B08118, 0x40000);
    func_01B017F0();
    func_01B07920(D_01B08120, D_01B00588);
    func_01B03F50(1);
    t = func_01B046E0(func_01B016E8);
    t[0x18] = 1;
    func_01B048A8(t);
    t = func_01B046E0(func_01B01780);
    t[0x18] = 2;
    func_01B048A8(t);
    return 0;
}
