/* Shared 09053-family helpers (TU rank 106, 169 containers): 4 tail-call wrappers. */
#include "p7_overlay.h"

typedef struct Ovl09053Wrap {
    u8 pad00[0x120];
    int id;
} Ovl09053Wrap;

void func_01B02B48(int a, int b);

void func_01B046B8(void)
{
    func_01B02B48(-5, 2);
}

void func_01B046C8(Ovl09053Wrap *w)
{
    func_01B02B48(w->id, 0);
}

void func_01B046D8(Ovl09053Wrap *w)
{
    func_01B02B48(w->id, 8);
}

void func_01B046E8(Ovl09053Wrap *w)
{
    func_01B02B48(w->id, 2);
}
