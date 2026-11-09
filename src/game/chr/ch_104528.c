/* tu_003 0x104528-0x104718: low; ~ch (config/tu_map.tsv) */
#include "common.h"
#include "ffx/q0.h"
#include "ffx/r0.h"
#include "ffx/s0.h"
#include "ffx/u0.h"
#include "ffx/v0.h"

typedef struct RelEntView {
    u8 pad00[8];
    void *w8;
    void *wC;
} RelEntView;

typedef struct RelObjView {
    s32 w0;
    u16 h4;
    u16 h6;
    u16 h8;
    u16 hA;
    RelEntView *wC;
    RelEntView *w10;
} RelObjView;

void func_00104528(RelObj *obj, s32 d)
{
    RelObjView *o = (RelObjView *)obj;
    s32 i;
    char buf[0x100];

    if (o != 0) {
        o->wC = (RelEntView *)((s32)o->wC + d);
        o->w10 = (RelEntView *)((s32)o->w10 + d);
        for (i = 0; i < (s16)o->h8; i++) {
            RelEntView *ent = o->wC + i;

            ent->w8 = (void *)((s32)ent->w8 + d);
            ent->wC = (void *)((s32)ent->wC + d);
        }
        for (i = 0; i < (s16)o->hA; i++) {
            RelEntView *ent = o->w10 + i;

            ent->w8 = (void *)((s32)ent->w8 + d);
            ent->wC = (void *)((s32)ent->wC + d);
        }
    }
}

extern char D_0057DA98[];
extern char D_005693D0[];

int ch_create_chrname(int v)
{
    int k = (v >> 12) & 0xF;
    char *buf = D_0057DA98;

    func_002F0008(buf, D_005693D0, sg_getdbname(k), func_00101528(k), v & 0xFFF);
    return (int)buf;
}

char *ch_create_name(int v)
{
    int k = (v >> 12) & 0xF;
    char *buf;

    if (v == 0) {
        return D_005693E0;
    }
    buf = D_0057DAA8;
    func_002F0008(buf, D_005693E8, func_00101528(k), v & 0xFFF);
    return buf;
}

char *ch_create_section(s32 v)
{
    return sg_getdbname((v >> 12) & 0xF);
}

void func_00104710(void) {
}
