#include "common.h"

typedef struct {
    u8 pad00[0x18];
    int state;
    u8 pad1C[0x18];
    int w34;
} WorkC290;

extern u8 D_01B00F40[];
extern void func_01B0B828(void *);
extern void func_01B18C30(void *);
extern void func_01B19038(void *);

void func_01B0C290(WorkC290 *w)
{
    u8 pad[0x70];
    void *m[3];
    register void **mp __asm__("$16") = m;
    (void)pad;
    mp[1] = (void *)func_01B0B828;
    m[0] = w;
    m[2] = w;
    func_01B18C30(mp);
    m[1] = w;
    m[0] = D_01B00F40;
    func_01B19038(mp);
    w->w34 = 0;
    w->state = 900;
}
