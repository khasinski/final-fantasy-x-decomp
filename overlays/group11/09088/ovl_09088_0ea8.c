#include "common.h"

extern int func_01B00C08(int);
extern float func_001107C0(int);
extern float func_001107C8(int);
extern float func_001107D0(int);

void func_01B00EA8(int a0, float *out)
{
    int id = func_01B00C08(a0);
    out[0] = func_001107C0(id) * 0.01f;
    out[1] = func_001107C8(id) * 0.01f;
    out[2] = func_001107D0(id) * 0.01f;
}
