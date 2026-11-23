#include "common.h"
#include "vu0.h"

typedef struct {
    u8 pad0[0x14];
    void *unk14;
} Unk3590Task;

typedef struct {
    u8 pad0[0xC4];
    float unkC4;
    u8 padC8[0x8];
    float unkD0[4];
    u8 padE0[0x50];
} Unk3590Sub;

typedef struct {
    u8 pad0[0xC0];
    float unkC0[4];
    float unkD0[4];
    u8 padE0[0x50];
    Unk3590Sub unk130;
    float unk260[4];
    float unk270[4];
    float unk280[4];
    u8 pad290[0x280];
    s32 unk510;
    s32 unk514;
    s32 unk518;
    s32 unk51C;
} Unk3590Item;

typedef struct {
    Unk3590Item items[4];
    s32 unk1480;
    s32 unk1484;
} Unk3590Block;

typedef struct {
    u8 pad0[0x2860];
    u8 unk2860[0xAF10];
    Unk3590Block unkD770;
    u8 padEBF8[0x8];
    float unkEC00;
} Unk3590Work;

extern u8 D_01B0B2D0;
extern Unk3590Work *D_01B0B398;
extern u8 D_01B07958;

extern s32 func_00116068(void);
extern float func_002B3DB0(float);
extern void func_01B03E00(float *);
extern void func_01B03E48(void);
extern void func_01B04478(void *, float *, s32);
extern float func_01B04EA0(s32);
extern void func_01B05098(float *);
extern Unk3590Task *func_01B07000(void *);
extern void func_01B07080(Unk3590Task *);
extern void func_01B071C8(Unk3590Task *);
extern s32 func_01B07360(void *, void *, s32, s32, s32, void *, float);
extern s32 func_01B07828(void *, void *);
extern void func_01B080C8(void *, float *, float *);
extern void func_01B081D0(float *, float *, float *);
extern float func_01B08270(float *, float *);

void func_01B03590(Unk3590Task *arg0) {
    float pos[4];
    Unk3590Item *item = (Unk3590Item *)arg0->unk14;
    Unk3590Work *work = D_01B0B398;
    Unk3590Block *blk = &work->unkD770;
    float t;
    s32 i;

    if (item->unk510 > 0) {
        if (func_00116068() != 0) {
            item->unk510--;
        }
    }

    t = (float)item->unk510 / (float)item->unk514;
    for (i = 0; i < 3; i++) {
        pos[i] = item->unk270[i] * (1.0f - t) + item->unk260[i] * t;
    }
    pos[3] = 1.0f;

    func_01B04478(item->unk280, pos, 0x80);
    MMI_COPY_LQ_A3(item->unkD0, pos);
    MMI_COPY_SQ_A3(item->unkD0);

    if (item->unk510 <= 0) {
        s32 id;
        void *cb;
        Unk3590Sub *sub;
        if (item->unk518 == 0) {
            id = 0x1A;
            cb = &D_01B07958;
        } else {
            id = 4;
            cb = 0;
        }
        sub = &item->unk130;
        func_01B07360(&D_01B0B2D0, sub, id, 0, 0, cb, 0.4f);
        MMI_COPY_LQ_A3((float *)((u8 *)item + 0x200), item->unk270);
        MMI_COPY_SQ_A3((float *)((u8 *)item + 0x200));
        sub->unkC4 = work->unkEC00;
        sub->unkD0[1] -= 0.5f;
        func_01B07828(&D_01B0B2D0, item);
        blk->unk1484++;
        func_01B07080(arg0);
    }
}

void func_01B03758(void) {
    float v0[4];
    float v1[4];
    float v2[4];
    float v3[4];
    Unk3590Work *work = D_01B0B398;
    Unk3590Block *blk = &work->unkD770;
    u8 *p2860 = work->unk2860;
    Unk3590Item *item;
    s32 i;

    func_01B03E00(v0);
    v2[0] = 0.0f;
    v2[1] = work->unkEC00;
    v2[2] = 0.0f;
    v2[3] = 0.0f;
    v3[3] = 1.0f;
    func_01B05098(v1);
    v1[1] = func_01B04EA0(0);

    item = blk->items;
    for (i = 0; i < 3; i++, item++) {
        Unk3590Task *task;

        MMI_COPY_LQ_A3(item->unk260, v0);
        MMI_COPY_SQ_A3(item->unk260);
        MMI_COPY_LQ_A3(item->unk270, v1);
        MMI_COPY_SQ_A3(item->unk270);

        switch (i) {
            case 0:
                v3[0] = 0.0f;
                v3[1] = -25.0f;
                v3[2] = 0.0f;
                break;
            case 1:
                v3[0] = 40.0f;
                v3[1] = 0.0f;
                v3[2] = func_002B3DB0(15.0f);
                break;
            case 2:
                v3[0] = -40.0f;
                v3[1] = 0.0f;
                v3[2] = func_002B3DB0(15.0f);
                break;
        }

        func_01B081D0(v2, item->unk270, v3);
        func_01B080C8(item->unk280, item->unk260, item->unk270);
        item->unk510 = (s32)(func_01B08270(item->unk260, item->unk270) / 10.0f);
        if (item->unk510 < 0) {
            item->unk510 = 1;
        }
        if (i == 0) {
            item->unk510 += 2;
        }
        item->unk514 = item->unk510;
        func_01B07360(&D_01B0B2D0, item, 3, 0, 0, 0, 0.08f);
        {
            float *c0 = item->unkC0;
            MMI_COPY_LQ_A3(c0, item->unk280);
            MMI_COPY_SQ_A3(c0);
        }
        item->unk518 = i;
        task = func_01B07000(func_01B03590);
        task->unk14 = item;
        func_01B071C8(task);
    }

    blk->unk1484 = 0;
    blk->unk1480 = 3;
    func_01B07828(&D_01B0B2D0, p2860);
    func_01B03E48();
}
