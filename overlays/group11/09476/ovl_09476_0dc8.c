#include "common.h"

typedef struct {
    u8 pad00[0x120];
    u32 w120;
    u32 w124;
    u32 w128;
    u32 w12C;
} OvlObj;

void ovl_09476_0dc8(OvlObj *obj)
{
    obj->w120 = 0x00808000;
    obj->w124 = 0x80808060;
    obj->w128 = 0;
    obj->w12C = 0;
}
