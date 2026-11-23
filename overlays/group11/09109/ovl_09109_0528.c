/* Shared setup helper (80 B, 09109 @ 0x01B00528, 09097 @ 0x01B00540). */

#include "common.h"

extern int g_hdr_210;
extern int g_tbl_40[];

extern int fn_0a38(void);
extern void func_001E4C80(int, int);

void ovl_09109_0528(void)
{
    func_001E4C80(0, (g_hdr_210 >> 10) & 1);
    func_001E4C80(1, g_tbl_40[fn_0a38()]);
}
