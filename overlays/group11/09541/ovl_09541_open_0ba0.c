/* EE Battle-Effect Overlay: group 0x11, file 09541
 * .text: 0x01B00BA0..0x01B00C68 (1 function).
 */
#include "common.h"

extern void *D_006A3924;
extern u8 D_006A3970[];
extern u8 D_006A3A70[];
extern void *D_006A3BCC;
extern int D_01B003C4;
extern void *D_01B003CC;
extern void *D_01B003D0;
extern u8 D_01B003E0[];
extern int D_01B00490;
extern u8 D_01B004B0[];
extern char D_01B02338[];

extern int func_01B010B8(const char *, int);
extern int func_01B01210(void *);
extern int func_01B01368(void *);
extern int func_0014AA50(int);
extern void func_001A9EE0(void *);
extern void func_001AACA0(void *);
extern void func_001CDDD8(void *);

int func_01B00BA0(void)
{
    if (D_01B003C4 == 0) {
        return 0;
    }
    D_006A3924 = D_01B003E0;
    func_001AACA0(D_006A3A70);
    func_001A9EE0(D_006A3970);
    D_006A3BCC = D_01B003CC;
    if (func_0014AA50(0) != 0) {
        func_01B01210(D_01B004B0);
    }
    if (func_0014AA50(1) != 0) {
        func_01B01368(D_01B004B0);
        func_01B010B8(D_01B02338, D_01B00490);
        func_001CDDD8(D_01B003D0);
        return 1;
    }
    D_01B00490++;
    return 1;
}
