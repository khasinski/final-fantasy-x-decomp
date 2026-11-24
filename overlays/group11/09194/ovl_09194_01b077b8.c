#include "common.h"

typedef struct {
    void *p0;
    u8 f4;
    u8 tag;
    u8 pad6[0xA];
} Msg77B8;

typedef struct {
    void *p0;
    u8 pad4[0xC];
} Msg77B8B;

extern int D_01B00044;
extern void *D_01B00048;
extern void *D_01B0004C;
extern int D_01B0067C;
extern u8 D_01B00A48[];
extern u8 D_01B00A74;
extern u8 D_01B00A98[];
extern u8 D_01B00AD8[];
extern void *D_01B17B58[];
extern void *D_006A3924;

extern int func_0029B830(int);
extern int func_002D0570(int);
extern int op_oef2_sound_cue_check(int);
extern void MsEffectReady(int, int);
extern void func_002B37A0(void);
extern void func_01B16B70(Msg77B8B *);
extern void func_01B0BB38(Msg77B8 *);

int func_01B077B8(void)
{
    Msg77B8 m0;
    Msg77B8B m1;

    for (;;) {
        switch (D_01B00044) {
        case 0:
            if (func_0029B830(2) == 0) {
                D_01B00044++;
                continue;
            }
            return 0;
        case 1:
            if (func_002D0570(2) != 0) {
                return 0;
            }
            D_01B00044++;
            continue;
        case 2:
            if (op_oef2_sound_cue_check(2) != 0) {
                return 0;
            }
            MsEffectReady(D_01B0067C, 0);
            D_01B00044 = 4;
            break;
        }
        break;
    }

    func_002B37A0();
    D_006A3924 = D_01B17B58;
    D_01B00048 = D_01B0004C;
    D_01B00A74++;
    m1.p0 = D_01B00A48;
    func_01B16B70(&m1);

    m0.p0 = D_01B00A98;
    m0.tag = D_01B00A74;
    func_01B0BB38(&m0);

    m0.p0 = D_01B00AD8;
    m0.tag = D_01B00A74;
    func_01B0BB38(&m0);

    return 0;
}
