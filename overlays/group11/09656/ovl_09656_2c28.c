#include "common.h"

extern u8 *D_01B0A988;

void func_01B02200(void);
void func_01B02758(void);
void func_01B02B00(void);
void func_01B01C30(void);

void func_01B02C28(void)
{
    switch (*(int *)(D_01B0A988 + 0x3664)) {
    case 0:
        func_01B02200();
        break;
    case 1:
        func_01B02758();
        break;
    case 2:
        func_01B02B00();
        break;
    }
    func_01B01C30();
}
