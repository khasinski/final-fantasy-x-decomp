#include "common.h"

typedef struct {
    void *p0;
    u8 f4;
    u8 tag;
    u8 pad6[0xA];
} MsgDB18;

typedef struct {
    void *p0;
    u8 pad4[0xC];
} MsgDB18B;

typedef struct {
    u8 pad00[0x10];
    u32 f10 : 1;
} ObjCD8;

typedef struct {
    u8 pad00[0x18];
    u16 count;
} ObjD30;

extern int D_01B00044;
extern u8 D_01B0084C;
extern int D_01B00900;
extern u8 D_01B00AB0[];
extern int D_01B00CD0;
extern ObjCD8 D_01B00CD8;
extern u8 D_01B00CF0[];
extern ObjD30 D_01B00D30;
extern void *D_01B1C130[];
extern void *D_006A3924;

extern void func_01B0A578(void);
extern void func_01B16E20(MsgDB18 *);
extern void func_01B1B1C8(MsgDB18B *);
extern void func_01B10D68(MsgDB18 *);
extern void MsEffectTerminate(int);

int func_01B0DB18(void)
{
    MsgDB18 m0;
    MsgDB18B m1;

    if (D_01B00044 < 4) {
        return 0;
    }

    D_006A3924 = D_01B1C130;
    func_01B0A578();

    m0.p0 = D_01B00AB0;
    m0.tag = D_01B0084C;
    func_01B16E20(&m0);

    m1.p0 = &D_01B00CD8;
    func_01B1B1C8(&m1);

    m0.p0 = D_01B00CF0;
    m0.tag = D_01B0084C;
    func_01B10D68(&m0);

    m0.p0 = &D_01B00D30;
    m0.tag = D_01B0084C;
    func_01B10D68(&m0);

    if (D_01B00CD8.f10 & D_01B00CD0) {
        if (D_01B00D30.count == 0) {
            MsEffectTerminate(D_01B00900);
        }
    }

    return 0;
}
