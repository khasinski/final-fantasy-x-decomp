#include "p8_overlay.h"

int func_01B03AD0(int slot); /* DEBT(TYPE): returns a character handle */
int MsGetDamageInfo(int eff, int chr, int *a, int *b, int *c);
int func_001BB930(int eff, int chr, int *f, int a3, int *g, int t1, int t2, int t3);

void func_01B03B08(int eff, P8Targets *t, u8 *list)
{
    int i;
    int total;

    for (i = 0; i < 32; i++) {
        t->ids[i] = 255;
        t->handles[i] = 0;
    }
    total = 0;
    for (i = 0; i < t->count; i++) {
        int id = list[i];
        P8Dmg *d = &t->dmg[i];

        t->ids[i] = id;
        t->handles[id] = func_01B03AD0(id);
        d->amount = MsGetDamageInfo(eff, id, &d->a, &d->b, &d->c);
        d->e = func_001BB930(eff, id, &d->f, 0, &d->g, 0, 0, 0);
        total += d->amount;
    }
    t->total = total;
    t->list = t->ids;
}
