#include "common.h"

typedef struct {
    int frame;
    u8 pad04[0x10C];
} TtRing;

extern int D_01B007C0;
extern int D_01B007C8;
extern int D_01B007CC;
extern int D_01B007D0;
extern int D_01B007D8;
extern u8 D_01B007E8;
extern int D_01B01058;
extern TtRing D_01B01060;
extern TtRing D_01B01170;
extern TtRing D_01B01280;
extern TtRing D_01B01390;
extern char D_01B04248[];
extern char D_01B04258[];
extern char D_01B04268[];
extern char D_01B04278[];
extern char D_01B04288[];

extern void *D_006A3924;
extern u8 D_006A3970;
extern u8 D_006A3A70;
extern int D_006A3BCC;

extern int func_01B03408(char *, ...);
extern void func_01B03460(char *, ...);
extern void func_01B034A0(int, int);
extern int func_01B03DD8(void *);
extern int func_01B03F30(void *);
extern int func_0014AA50(int);
extern void func_001A9EE0(void *);
extern void func_001AACA0(void *);
extern void func_001CDDD8(int);

int func_01B03168(void)
{
    if (D_01B007C0 == 0) {
        return 0;
    }
    D_006A3924 = &D_01B007E8;
    func_001AACA0(&D_006A3A70);
    func_001A9EE0(&D_006A3970);
    D_006A3BCC = D_01B007C8;
    D_01B007D0 = D_01B007CC;
    if (func_0014AA50(0) != 0) {
        func_01B034A0(0x20, 0x1A);
        func_01B03460(D_01B04248, D_01B01060.frame);
        func_01B03DD8(&D_01B01060);
    }
    if (func_0014AA50(1) != 0) {
        func_01B034A0(0x20, 0x1B);
        func_01B03460(D_01B04258, D_01B01170.frame);
        func_01B03DD8(&D_01B01170);
    }
    if (func_0014AA50(2) != 0) {
        func_01B034A0(0x20, 0x1C);
        func_01B03460(D_01B04268, D_01B01280.frame);
        func_01B03DD8(&D_01B01280);
    }
    if (func_0014AA50(3) != 0) {
        func_01B034A0(0x20, 0x1D);
        func_01B03460(D_01B04278, D_01B01390.frame);
        func_01B03DD8(&D_01B01390);
    }
    if (func_0014AA50(4) != 0) {
        func_01B03F30(&D_01B01060);
        func_01B03F30(&D_01B01170);
        func_01B03F30(&D_01B01280);
        func_01B03F30(&D_01B01390);
        func_01B03408(D_01B04288, D_01B01058);
        func_001CDDD8(D_01B007D8);
        return 1;
    }
    D_01B01058++;
    return 1;
}
