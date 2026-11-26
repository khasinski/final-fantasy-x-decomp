#include "iopsound.h"

extern char D_016590[];
extern char D_016594[];

s32 func_00FF94(s32 *arg) {
    imp_sysclib_19(arg, D_016590, D_016594);
    return *arg;
}
