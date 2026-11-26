#include "iopsound.h"

extern s32 func_0105F4(s32 *, s32);
extern s32 (*D_019014[])(s32 *, s32);

s32 *func_013E94(u32 cmd, s32 *data, s32 size) {
    if (cmd == 0) {
        *data = func_0105F4(data, size);
    } else {
        *data = D_019014[cmd](data, size);
    }
    return data;
}
