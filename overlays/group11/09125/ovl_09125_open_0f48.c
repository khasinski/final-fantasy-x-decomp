/* EE Battle-Effect Overlay: group 0x11, file 09125 (shared across P6 family)
 * .text: 0x01B00F48..0x01B00FA8 (1 function), .rodata: 0x01B0AF90.
 */
#include "p6_overlay.h"

int func_01B00F48(int chr_id)
{
    switch (func_001B4E18(chr_id)) {
    case 0x1071:
    case 0x1081:
    case 0x1083:
    case 0x1088:
    case 0x1089:
    case 0x108A:
    case 0x108C:
        return 1;
    default:
        return MsGetChrFly(chr_id) != 0;
    }
}
