#include "common.h"

typedef struct {
    u8 pad00[0xA4];
    u16 flagsA4;
} Node5E20;

void func_01B05E20(Node5E20 **arg)
{
    Node5E20 *n = *arg;
    n->flagsA4 |= 1;
}
