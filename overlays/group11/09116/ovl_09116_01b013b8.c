#include "common.h"

typedef struct Ovl09116Part {
    u8 pad00[0x40];
    u32 w40;
    u32 w44;
    u8 pad48[0x1C];
    int w64;
    int w68;
    int active;
} Ovl09116Part;

extern Ovl09116Part *D_01B06D28;
extern int D_01B06D2C;
extern int D_01B06D30;

Ovl09116Part *func_01B013B8(void)
{
    int i;
    int idx;
    Ovl09116Part *p;

    idx = D_01B06D2C;
    for (i = 0; i < D_01B06D30; i++) {
        p = &D_01B06D28[idx];
        idx++;
        if (idx >= D_01B06D30) {
            idx = 0;
        }
        if (p->active == 0) {
            p->active = 1;
            p->w40 = 0x80808080;
            p->w44 = 0x80808080;
            p->w68 = 0;
            p->w64 = 0;
            D_01B06D2C = idx;
            return p;
        }
    }
    return 0;
}
