#include "common.h"

typedef struct {
    void *p0;
    u8 f4;
    u8 tag;
    u8 pad6[0xA];
} Msg78F8;

typedef struct {
    void *p0;
    u8 pad4[0xC];
} Msg78F8B;

typedef struct {
    u8 pad00[0x10];
    u32 f10 : 1;
} ObjA60;

typedef struct {
    u8 pad00[0x18];
    u16 count;
} ObjAB8;

extern int D_01B00044;
extern int D_01B0067C;
extern u8 D_01B00830[];
extern int D_01B00A58;
extern ObjA60 D_01B00A60;
extern u8 D_01B00A74;
extern u8 D_01B00A78[];
extern ObjAB8 D_01B00AB8;
extern void *D_01B17B58[];
extern void *D_006A3924;

extern void func_01B04F58(void);
extern void func_01B16B70(Msg78F8B *);
extern void func_01B127C8(Msg78F8 *);
extern void func_01B0BB38(Msg78F8 *);
extern void MsEffectTerminate(int);

int func_01B078F8(void)
{
    Msg78F8 m0;
    Msg78F8B m1;

    if (D_01B00044 < 4) {
        return 0;
    }

    D_006A3924 = D_01B17B58;
    func_01B04F58();

    m1.p0 = &D_01B00A60;
    func_01B16B70(&m1);

    m0.p0 = D_01B00830;
    m0.tag = D_01B00A74;
    func_01B127C8(&m0);

    m0.p0 = D_01B00A78;
    m0.tag = D_01B00A74;
    func_01B0BB38(&m0);

    m0.p0 = &D_01B00AB8;
    m0.tag = D_01B00A74;
    func_01B0BB38(&m0);

    if (D_01B00A60.f10 & D_01B00A58) {
        if (D_01B00AB8.count == 0) {
            MsEffectTerminate(D_01B0067C);
        }
    }

    return 0;
}
