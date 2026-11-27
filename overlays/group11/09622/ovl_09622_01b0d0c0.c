#include "common.h"

typedef struct {
    u8 pad00[0xA4];
    u16 flagsA4;
} NodeD0C0;

void func_01B0D0C0(NodeD0C0 **arg)
{
    NodeD0C0 *n = *arg;
    n->flagsA4 |= 1;
}
