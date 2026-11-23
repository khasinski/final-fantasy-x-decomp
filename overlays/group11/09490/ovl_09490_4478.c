#include "common.h"
#include "vu0.h"

typedef struct {
    u32 unk00;
    void *pkt;
    u8 unk08;
    u8 unk09;
    u8 unk0A;
    u8 pad0B;
    u16 unk0C;
    u16 unk0E;
    u32 unk10;
    u32 unk14;
    u8 unk18;
    u8 unk19;
    u8 unk1A;
    u8 unk1B;
    u8 unk1C;
    u8 unk1D;
    u8 unk1E;
    u8 unk1F;
    void *unk20;
    void *unk24;
    void *unk28;
    void *unk2C;
    u32 unk30;
    u32 unk34;
    u32 unk38;
    u32 unk3C;
    u16 unk40;
    u16 unk42;
    u32 unk44;
    u32 unk48;
    u8 unk4C;
    u8 unk4D;
    u8 pad4E[0x22];
} MdcParam;

typedef float Mtx4[4][4];

extern void *D_01B0B39C;

extern void *Sg_PacketGetPtr(void);
extern void *func_01B03CD8(void);
extern void func_002DD128(Mtx4);
extern float func_00110AF0(void *);
extern float Ch_GetScaleX(void *);
extern float Ch_GetScaleY(void *);
extern float Ch_GetScaleZ(void *);
extern void func_01B082F0(Mtx4, void *);
extern void func_01B06120(Mtx4, Mtx4);
extern void func_002DCE38(Mtx4, Mtx4, Mtx4);
extern void func_01B062D0(Mtx4);
extern void func_01B062A0(Mtx4);
extern void Ch_TextureSetImageBase(void *, s32, s32);
extern void Ch_TextureSetClutBase(void *, s32, s32);
extern void Ch_TextureLoadImage(void *, s32);
extern void func_0010D4D8(void *, s32);
extern void op1_mdc_draw(void *, MdcParam *, Mtx4, Mtx4, Mtx4);

void func_01B04478(void *arg0, u_long128 *arg1, s32 arg2) {
    MdcParam param;
    Mtx4 mtx0;
    Mtx4 mtx1;
    Mtx4 mtx2;
    Mtx4 mtx3;
    Mtx4 mtx4;
    Mtx4 mtx5;
    void *ch;
    float s;

    param.unk00 = 0x1C;
    param.pkt = Sg_PacketGetPtr();
    param.unk08 = 0x44;
    param.unk1B = arg2;
    param.unk09 = 0x80;
    param.unk18 = 0x80;
    param.unk19 = 0x80;
    param.unk1A = 0x80;
    param.unk4C = 0x80;
    param.unk0A = 0;
    param.unk0C = 0;
    param.unk0E = 0;
    param.unk10 = 0;
    param.unk14 = 0;
    param.unk1C = 0;
    param.unk1D = 0;
    param.unk1E = 0;
    param.unk1F = 0;
    param.unk34 = 0;
    param.unk38 = 0;
    param.unk3C = 0;
    param.unk40 = 0;
    param.unk42 = 0;
    param.unk44 = 0;
    param.unk48 = 0;
    param.unk4D = 0;

    ch = func_01B03CD8();
    func_002DD128(mtx0);
    s = func_00110AF0(ch) * 0.001f;
    mtx0[0][0] = mtx0[1][1] = mtx0[2][2] = s;
    mtx0[0][0] *= Ch_GetScaleX(ch);
    mtx0[1][1] *= Ch_GetScaleY(ch);
    mtx0[2][2] *= Ch_GetScaleZ(ch);

    func_01B082F0(mtx0, arg0);
    MMI_COPY_LQ_A3(mtx0[3], arg1);
    MMI_COPY_SQ_A3(mtx0[3]);

    func_01B06120(mtx2, mtx3);
    func_002DCE38(mtx1, mtx3, mtx0);
    func_002DCE38(mtx1, mtx2, mtx1);
    func_01B062D0(mtx4);
    func_01B062A0(mtx5);

    param.unk20 = mtx1;
    param.unk24 = mtx4;
    param.unk28 = mtx5;
    param.unk2C = mtx0;

    Ch_TextureSetImageBase(ch, -1, 0x3C00);
    Ch_TextureSetClutBase(ch, -1, 0x2EE0);
    Ch_TextureLoadImage(ch, -1);
    func_0010D4D8(ch, -1);
    op1_mdc_draw(D_01B0B39C, &param, mtx0, mtx3, mtx2);
    Ch_TextureSetImageBase(ch, -1, -1);
    Ch_TextureSetClutBase(ch, -1, -1);
}
