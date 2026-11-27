#include "common.h"

typedef struct {
    u16 h00;
    u16 h02;
    u32 w04;
    u8 pad08[0x28];
} ObjA70;

extern void *D_01B0089C;
extern void *D_01B00A60;
extern void *D_01B00A64;
extern ObjA70 D_01B00A70;
extern void *D_01B00AA0;
extern u8 D_01B00AB0[];
extern char D_01B049F8[];

extern void func_01B027D8(char *, ...);
extern void *func_002B49A0(void *, int, int);
extern void func_002EF0D0(void *, int, int);
extern void func_01B02D80(void *, void *, int);
extern void func_01B03068(void *, int, float, float);

int func_01B01718(void)
{
    void **p60 = &D_01B00A60;
    void **p64 = &D_01B00A64;
    func_01B027D8(D_01B049F8);
    *p60 = func_002B49A0(D_01B0089C, 4, 0);
    *p64 = func_002B49A0(D_01B0089C, 4, 1);
    func_002EF0D0(&D_01B00A70, 0, 0x30);
    {
        register u32 col __asm__("$3") = 0x80808080;
        D_01B00A70.w04 = col;
        D_01B00A70.h02 = 0x80;
    }
    func_01B02D80(D_01B00AB0, D_01B00AA0, 500);
    func_01B03068(D_01B00AB0, 0, 0.0f, 0.0f);
    return 1;
}
