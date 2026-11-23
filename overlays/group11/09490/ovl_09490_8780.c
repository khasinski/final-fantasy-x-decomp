#include "common.h"

typedef struct {
    s16 unk0;
    s16 unk2;
    s8 unk4;
    u8 pad5[3];
} Unk8780Entry;

typedef struct {
    u8 pad0[6];
    s16 unk6;
    u8 pad8[8];
    Unk8780Entry entries[1];
} Unk8780Data;

typedef struct {
    Unk8780Data *unk0;
    s32 unk4;
    s16 unk8;
    s16 unkA;
    u8 padC[4];
    float unk10[4];
    s32 unk20;
    float unk24;
    u8 pad28[8];
} Unk8780Item;

typedef struct {
    u8 pad0[4];
    s32 unk4;
    u8 pad8[8];
    void *unk10;
    s32 unk14;
    u8 pad18[4];
    void *unk1C;
} Unk8780Draw;

extern Unk8780Draw D_01B00F20;

extern s32 func_00116068(void);
extern s32 func_002CD590(void *, void *);
extern void func_002DCE08(float *, float *, float *);
extern void func_002DCE38(float *, float *, float *);
extern void func_002DD998(float *, float *, float);
extern void func_01B06120(float *, float *);

void func_01B08780(Unk8780Item *arg0, float *arg1, s32 arg2) {
    float mat0[16];
    float mat1[16];
    float mat2[16];
    Unk8780Draw *draw;
    s32 i;

    func_01B06120(mat1, mat2);
    draw = &D_01B00F20;
    draw->unk10 = mat0;
    draw->unk1C = 0;

    for (i = 0; i < arg2; i++, arg0++) {
        Unk8780Data *data;
        Unk8780Entry *ent;
        Unk8780Entry *cur;

        draw->unk4 = arg0->unk20;
        func_002DD998(&mat0[0], &arg1[0], arg0->unk24);
        func_002DD998(&mat0[4], &arg1[4], arg0->unk24);
        func_002DD998(&mat0[8], &arg1[8], arg0->unk24);
        func_002DCE08(&mat0[12], mat2, arg0->unk10);
        func_002DCE38(mat0, mat1, mat0);

        data = arg0->unk0;
        ent = &data->entries[arg0->unk8];
        if (func_00116068() == 0 && arg0->unk8 <= 0) {
            cur = &data->entries[0];
        } else {
            if (func_00116068() != 0 && arg0->unk4 != 0) {
                arg0->unkA -= 0x200;
                if (arg0->unkA <= 0) {
                    arg0->unk8++;
                    if (arg0->unk8 >= data->unk6) {
                        if (ent->unk4 & 0x80) {
                            arg0->unk8 = 0;
                        } else {
                            arg0->unk8--;
                            arg0->unk4 = 0;
                            cur = ent;
                            goto draw_it;
                        }
                    }
                    ent = &data->entries[arg0->unk8];
                    arg0->unkA = ent->unk2;
                }
            }
            cur = ent;
        }
    draw_it:
        draw->unk14 = func_002CD590((u8 *)arg0->unk0 + cur->unk0, draw);
    }
}
