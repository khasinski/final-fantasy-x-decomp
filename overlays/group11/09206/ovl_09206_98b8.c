#include "common.h"

typedef struct CamSlotFull {
    u8 pad00[0x40];
    s32 w40;
    s32 w44;
    s32 w48;
    u32 pad4C;
    s32 w50;
    s32 w54;
    s32 w58;
    float f5C;
    s32 w60;
    s32 w64;
    s32 w68;
    float f6C;
    u8 pad70[0xCC];
    float f13C;
    s32 w140;
    u8 b144;
    u8 b145;
    u8 b146;
    u8 pad147[9];
} CamSlotFull; /* size 0x150 */

typedef struct TaskNode {
    u8 pad00[0x18];
    u8 b18;
} TaskNode;

extern TaskNode *D_01B115A0;
extern void *D_01B115A4;
extern s32 D_01B115A8;
extern CamSlotFull D_01B115B0[3];
extern void *D_01B00D8C;

void *func_001CEA70(s32 a, s32 b, s32 c);
s32 func_001A9DB8(void *p, s32 idx);
void func_01B06C28(void);
void func_01B0A058(CamSlotFull *s);
TaskNode *func_01B07B20(void *fn);
void func_01B07CE8(TaskNode *n);
void func_01B07BA0(TaskNode *n);
void func_01B09A78(CamSlotFull *s);
extern u8 D_01B0A0C8[];

void func_01B098B8(s32 a0)
{
    s32 i;
    CamSlotFull *s;
    TaskNode *node;

    D_01B115A4 = func_001CEA70(0, 0, 7);
    func_001A9DB8(D_01B115A4, 0);
    func_001A9DB8(D_01B115A4, 1);

    if (D_01B00D8C == 0) {
        func_01B06C28();
    }

    s = D_01B115B0;
    for (i = 0; i < 3; i++, s++) {
        s->b144 = 0;
        s->b145 = 0;
        s->b146 = 0;
        s->w140 = 0;
        s->f5C = 1.0f;
        s->f6C = 1.0f;
        func_01B0A058(s);
        s->w40 = 0;
        s->w44 = 0;
        s->w48 = 0;
        s->w50 = 0;
        s->w54 = 0;
        s->w58 = 0;
        s->w60 = 0;
        s->w64 = 0;
        s->w68 = 0;
        s->f13C = 1024.0f;
    }

    D_01B115A8 = 0;
    if (a0 == 1) {
        node = func_01B07B20(D_01B0A0C8);
        node->b18 = a0;
        func_01B07CE8(node);
    } else {
        node = 0;
    }
    D_01B115A0 = node;
}

void func_01B099F8(void)
{
    if (D_01B115A0 != 0) {
        func_01B07BA0(D_01B115A0);
        D_01B115A0 = 0;
    }
}

void func_01B09A30(void)
{
    s32 i;
    CamSlotFull *s = D_01B115B0;
    for (i = 0; i < 3; i++, s++) {
        func_01B09A78(s);
    }
}
