#include "common.h"

typedef struct {
    void *unk00;
    u8 unk04;
    u8 unk05;
    u8 pad06[2];
} UnkB820Arg;

extern void func_01B18B88(UnkB820Arg *);

void func_01B1B820(register void *arg0, register u8 arg1) {
    UnkB820Arg tmp;

    tmp.unk00 = arg0;
    tmp.unk05 = arg1;
    func_01B18B88(&tmp);
}
