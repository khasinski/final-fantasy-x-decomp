#include "common.h"

typedef struct Work79D0 {
    u8 pad00[0x18];
    float f18;          /* 0x18 */
    float f1C;          /* 0x1C */
} Work79D0;

extern u8 D_01B00B00[];
extern int D_01B00B2C;

void func_01B068A0(void *);
void func_01B18300(void *);
void func_01B18708(void *);

void func_01B079D0(Work79D0 *w)
{
    void *m[3];

    m[0] = w;
    m[1] = (void *)func_01B068A0;
    m[2] = w;
    func_01B18300(m);

    m[0] = D_01B00B00;
    m[1] = w;
    func_01B18708(m);

    {
        float z = 0.0f;
        w->f1C = z;
        w->f18 = z;
    }
    D_01B00B2C = 0;
}
