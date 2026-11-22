#include "common.h"

typedef struct {
    u8 pad00[0xD0];
    float posd0[4];
    u8 pade0[0x24];
    void *f104;
} SubObj9111;

extern int ovl_0d20(void);
extern void ovl_0d40(int, void *);

void ovl_09111_0d68(SubObj9111 *obj)
{
    ovl_0d40(ovl_0d20(), obj->posd0);
    obj->f104 = 0;
}
