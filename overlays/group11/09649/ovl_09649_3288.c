#include "common.h"

typedef struct {
    u8 pad00[0x2724];
    int state;
} Work3288;

extern Work3288 *D_01B0B1F8;
extern void func_01B01B88(void);
extern void func_01B02890(void);
extern void func_01B02DB8(void);
extern void func_01B03160(void);

void func_01B03288(void)
{
    switch (D_01B0B1F8->state) {
    case 0:
        func_01B02890();
        break;
    case 1:
        func_01B02DB8();
        break;
    case 2:
        func_01B03160();
        break;
    }
    func_01B01B88();
}
