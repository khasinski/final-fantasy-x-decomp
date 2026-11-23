/* Shared 09097/09096 sound wait task (68 B, 09097 @ 0x01B008B8). */

#include "common.h"

extern int g_54bc;
extern int func_001E1E68(void);
extern void fn_3570(void *);

void ovl_09097_08b8(void *t)
{
    if (func_001E1E68() == 0) {
        g_54bc = 1;
        fn_3570(t);
    }
}
