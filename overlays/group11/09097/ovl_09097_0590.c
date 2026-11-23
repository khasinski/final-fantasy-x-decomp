/* 09097 ready check (60 B, 09097 @ 0x01B00590). */

#include "common.h"

extern int fn_0b50(void);
extern int func_001E1E18(void);

int ovl_09097_0590(void)
{
    if (fn_0b50() == 0) {
        if (func_001E1E18() != 0) {
            return 0;
        }
    }
    return 1;
}
