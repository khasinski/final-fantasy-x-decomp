#include "common.h"

extern int func_001B4E18(int);
extern int MsGetChrHandle(int);
extern float func_001109E0(int);

float func_01B00E10(int a0)
{
    int id = func_001B4E18(a0);
    int h = MsGetChrHandle(a0);

    switch (id) {
    case 0x1015:
        return func_001109E0(h) + 18.0f;
    case 0x102D:
        return func_001109E0(h) + 45.0f;
    case 0x1127:
        return func_001109E0(h) + 20.0f;
    case 0x108C:
        return func_001109E0(h) + 110.0f;
    case 0x111A:
        return func_001109E0(h) + 25.0f;
    case 0x112C:
        return func_001109E0(h) + 40.0f;
    default:
        return func_001109E0(h);
    }
}
