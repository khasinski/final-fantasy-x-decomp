#include "common.h"

typedef struct Particle {
    float position[4];
    float scale;
    u16 age;
    s16 index;
    u8 reserved[8];
} Particle;

extern Particle D_01D01EE0[128];

void ovl_09229_0b30(void)
{
    s32 i;
    for (i = 0; i < 128; i++) {
        D_01D01EE0[i].index = -1;
    }
}
