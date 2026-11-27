#include "common.h"

extern u8 D_01B00C10[];
extern u8 D_01B015B0[];

extern void func_00101D08(s32, s32);
extern void func_00104EF0(s32, s32);
extern void func_01B0B840(void *);
extern void func_01B0BA60(void *);
extern void func_01B0DE58(void *);
extern void func_01B0DF60(void *);

s32 func_01B09D38(void)
{
    void *m0;
    void *m1;
    void *m2;
    void *m3;

    m0 = D_01B015B0;
    func_01B0DF60(&m0);
    m1 = D_01B015B0;
    func_01B0DE58(&m1);
    m2 = D_01B00C10;
    func_01B0BA60(&m2);
    m3 = D_01B00C10;
    func_01B0B840(&m3);
    func_00101D08(0x301E, 0);
    func_00104EF0(0x301E, 1);
    return 0;
}
