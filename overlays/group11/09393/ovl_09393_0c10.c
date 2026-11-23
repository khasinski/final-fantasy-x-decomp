/* EE Battle-Effect Overlay: group 0x11, file 09393 (shared 0x01B00C10..0x01B00DB4, also in 09635)
 * Load base: 0x01B00000, .text: 0x01B00C10..0x01B00DB4 (3 functions)
 */
#include "common.h"

typedef struct Cfg09393 {
    int unk00;
    int count;
    u8 pad08[0x0C];
    u8 ids[0xB0];
    void *chrs[3];
} Cfg09393;

extern u8 D_01B00040[];
extern u8 D_01B00678[];
extern Cfg09393 D_01B00740;
extern u8 D_01B07AE8[];
extern int D_01B07B28;
extern void *D_01B07B2C;
extern u8 D_01B07B30[];
extern void *D_01B07C10;
extern u8 D_01B0DB50[];
extern u8 D_01B93700[];

void *op_oef2_a_get(void *res, int type, int idx);

void func_01B00DB8(void *a0);
void func_01B00EB8(void);
void func_01B00F20(void);
void func_01B03238(int id);
int func_01B03268(int id);
void func_01B03AD0(int a0);
u8 *func_01B04260(void *fn);
void func_01B04428(void *p);
void func_01B044E8(void *a0, void *a1, void *a2, int a3);
void func_01B074A0(void *a0, void *a1);

void func_01B00C10(void)
{
    func_01B03238(0x10AF);
}

int func_01B00C18(void)
{
    return func_01B03268(0x10AF) == 1;
}

int func_01B00C40(void)
{
    Cfg09393 *p = &D_01B00740;
    u8 *buf = D_01B93700;
    u8 *mgr;
    int i;
    u8 *t;

    D_01B07B28 = 0;
    D_01B07B2C = buf + 0x40000;
    D_01B07C10 = buf + 0x140000;
    for (i = p->count - 1; i >= 0; i--) {
        p->ids[i + 3] = p->ids[i];
    }
    p->count += 3;
    mgr = D_01B07AE8;
    *(void **)(mgr + 0x2C) = op_oef2_a_get(D_01B0DB50, 8, 0);
    func_01B044E8(mgr, D_01B00040, buf, 0x40000);
    func_01B00F20();
    func_01B074A0(D_01B07B30, D_01B00678);
    func_01B03AD0(1);
    t = func_01B04260(func_01B00DB8);
    t[0x18] = 1;
    func_01B04428(t);
    t = func_01B04260(func_01B00EB8);
    t[0x18] = 2;
    func_01B04428(t);
    return 0;
}
