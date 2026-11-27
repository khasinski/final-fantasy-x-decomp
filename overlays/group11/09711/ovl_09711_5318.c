#include "common.h"

extern void func_002B5C18(void *, void *, int);

typedef struct {
    u_long128 pts[4];
    u_long128 unk40[4];
    void *tex;
    u8 count;
    u8 unk85;
    u8 unk86;
    u8 pad87;
    s16 unk88;
    s16 unk8A;
    int unk8C;
    int unk90;
    float unk94;
    float unk98;
    float unk9C;
    float unkA0;
} Obj5318;

void func_01B05318(Obj5318 *o, u_long128 *pts, int count, int a3, int t0, int rev,
                   u8 *tex, int t3, float f12, float f13, float f14, int sp0, int sp8)
{
    int i;

    o->tex = tex + *(s16 *)(tex + 0x10);
    o->unk86 = t0;
    o->unk8A = a3;
    o->unk85 = sp8;
    o->unk94 = f12;
    o->unk98 = f13;
    o->unk9C = f14;
    o->unkA0 = 0.005f;
    o->unk8C = t3;
    o->unk90 = sp0;
    o->count = count;
    o->unk88 = 0;

    count--;
    i = count;
    do {
        if (rev == 0) {
            o->pts[i] = pts[i];
        } else {
            o->pts[i] = pts[count - i];
        }
        i--;
    } while (i != -1);

    func_002B5C18(o->unk40, o->pts, count + 1);
}
