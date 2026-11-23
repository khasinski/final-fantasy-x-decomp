#include "common.h"
#include "vu0.h"

typedef struct {
    float x, y, z, w;
} __attribute__((aligned(16))) Vec4;

typedef struct {
    u8 pad0[0x48];
    float unk48;
    u8 pad4C[4];
    Vec4 unk50;
    Vec4 unk60;
    u8 unk70[0x40];
    u8 unkB0[0x40];
    u8 unkF0[0x1C];
    u8 unk10C[0x30];
    float unk13C;
    s32 unk140;
    u8 unk144;
    u8 pad145;
    s8 unk146;
} Unk9008;

extern void *D_01B10074;

extern s32 func_00116068(void);
extern void func_001A7840(void *, s32, void *);
extern void func_001A8128(void *, float);
extern void func_001A81E8(void *, float);
extern void func_002DCE08(void *, void *, void *);
extern void func_01B09670(void *, void *);
extern void func_01B09BC8(void *, void *);
extern void func_01B09D38(void *, void *);
extern void func_01B09DE0(void *);

void func_01B09008(Unk9008 *arg0) {
    Vec4 v0;
    Vec4 v1;

    if (func_00116068() != 0) {
        func_01B09670(arg0->unkB0, &arg0->unk60);
        func_01B09670(arg0->unk70, &arg0->unk50);
        func_01B09BC8(arg0->unkF0, &arg0->unk48);
        func_01B09D38(arg0->unk10C, &arg0->unk13C);
        switch (arg0->unk144) {
        case 0:
            break;
        case 1:
            func_01B09DE0(arg0);
            break;
        }
    }

    if (arg0->unk140 == 1) {
        void *p;
        if (arg0->unk146 == 0) {
            MMI_COPY_LQ_A3(&v0, &arg0->unk50);
            MMI_COPY_SQ_A3(&v0);
            MMI_COPY_LQ_A3(&v1, &arg0->unk60);
            MMI_COPY_SQ_A3(&v1);
        } else {
            func_002DCE08(&v0, arg0, &arg0->unk50);
            func_002DCE08(&v1, arg0, &arg0->unk60);
        }
        p = D_01B10074;
        func_001A7840(p, 1, &v0);
        func_001A7840(p, 0, &v1);
        func_001A8128(p, arg0->unk48);
        func_001A81E8(p, arg0->unk13C);
    }
}
