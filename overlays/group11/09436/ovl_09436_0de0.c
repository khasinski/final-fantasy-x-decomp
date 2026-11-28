#include "common.h"

extern u8 D_01BD9FC0[];
extern u8 *D_01B09358;
extern s32 D_01B00748[];

extern void func_01B02C28(s32, void *, s32);
extern s32 func_001AF358(void);
extern void func_01B01160(void);
extern void func_01B01288(void);
extern void func_01B01368(void);
extern void func_01B01450(void);
extern s32 func_01B029D8(s32);
extern void func_001E4C80(s32, s32);

void func_01B00DE0(void) {
    u8 *base = D_01BD9FC0;
    u8 *s;
    s32 id;
    s32 *p;
    s32 res;
    s32 idx;

    s = base + 0x1C0000;
    D_01B09358 = s;
    func_01B02C28(-1, s + 0xF70, 0);
    id = func_001AF358();
    res = -1;
    p = D_01B00748;
    idx = 0;
    while (*p != -1) {
        if (*p == id) {
            res = idx;
            break;
        }
        p++;
        idx++;
    }
    *(s32 *)(s + 0x54C4) = res;
    func_01B01160();
    func_01B01288();
    func_01B01368();
    func_01B01450();
    func_001E4C80(0, func_01B029D8(*(s32 *)(s + 0x54A4)));
    func_001E4C80(1, *(s32 *)(s + 0x54A8));
    func_001E4C80(2, *(s32 *)(s + 0x54B0));
    func_001E4C80(3, *(s32 *)(s + 0x54B4));
}
