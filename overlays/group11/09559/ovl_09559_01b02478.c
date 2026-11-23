/* Overlay 09559: rank 321 control array initializer (0x01B02478..0x01B02570). */
#include "common.h"

typedef struct Control {
    u8 pad0[0x80];
    float unk80[4];
    float unk90[4];
    float unkA0[4];
    u8 padB0[0xD0];
    float unk180;
    int unk184;
    u8 unk188;
    u8 unk189;
    u8 unk18A;
    u8 pad18B[5];
} Control;

extern int D_01B0BAFC;
extern int D_01B0BB00;
extern Control D_01B0BB10[3];
extern int D_01B0C7C0;

int func_001CEA70(int, int, int);
void func_001D9F08(int);
int func_001A9DB8(int, int);
void func_01B02D10(Control *);

void func_01B02478(void) {
    int i;
    Control *c;

    D_01B0BAFC = func_001CEA70(8, 0, 7);
    func_001D9F08(1);
    func_001A9DB8(D_01B0BAFC, 0);
    func_001A9DB8(D_01B0BAFC, 1);

    c = D_01B0BB10;
    for (i = 2; i >= 0; i--, c++) {
        c->unk188 = 0;
        c->unk189 = 0;
        c->unk18A = 0;
        c->unk184 = 0;
        c->unk90[3] = 1.0f;
        c->unkA0[3] = 1.0f;
        func_01B02D10(c);
        c->unk80[0] = 0.0f;
        c->unk80[1] = 0.0f;
        c->unk80[2] = 0.0f;
        c->unk90[0] = 0.0f;
        c->unk90[1] = 0.0f;
        c->unk90[2] = 0.0f;
        c->unkA0[0] = 0.0f;
        c->unkA0[1] = 0.0f;
        c->unkA0[2] = 0.0f;
        c->unk180 = 1024.0f;
    }

    D_01B0BB00 = 0;
    D_01B0C7C0 = -1;
}
