#include "common.h"

typedef struct {
    u8 *obj;
    void *val;
} Arg0CE8;

void func_01B10CE8(Arg0CE8 *a)
{
    u32 v = (u32)a->val;
    a = (Arg0CE8 *)a->obj;
    if (v != 0) {
        *(u32 *)((u8 *)a + 0x128) = v;
    } else {
        *(u32 *)((u8 *)a + 0x128) = 0;
    }
}

void func_01B10D08(Arg0CE8 *a)
{
    u32 v = (u32)a->val;
    a = (Arg0CE8 *)a->obj;
    if (v != 0) {
        *(u32 *)((u8 *)a + 0x12C) = v;
    } else {
        *(u32 *)((u8 *)a + 0x12C) = 0;
    }
}
