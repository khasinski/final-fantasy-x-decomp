/* tu_166 0x19d608-0x19d688: medium; rcdtParse (config/tu_map.tsv) */
#include "common.h"
#include "ffx/r2.h"
#include "ffx/q3.h"
#include "ffx/w3.h"
#include "ffx/s2.h"
#include "ffx/v2.h"

u8 *func_0019D608(W3Pair *p)
{
    return p->ptr + p->size;
}

int func_0019D618(W3Pair *p)
{
    return p->size;
}

int func_0019D620(W3Pair *p)
{
    int r;

    r = 0;
    if (p->ptr == 0 || p->size == 0) {
        r = 1;
    }
    return r;
}

W3Reader *func_0019D648(void) {
    W3Reader *p = _rcAlloc(0x8C, D_0056DBB8, 0x17);

    rcdtParseInit(p);
    return p;
}
