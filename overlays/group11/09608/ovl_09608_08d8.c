/* Battle-effect overlay 09608: 0x01B008D8..0x01B00C60 */
#include "common.h"

typedef struct {
    u8 pad00[0x04];
    u32 unk04;
    u8 pad08[0x0C];
    u8 b14;
    u8 b15;
    u8 pad16[0x2E];
    u32 arr44[8];
} Obj04E0;

typedef struct {
    u8 pad00[0x2C];
    u32 unk2C;
} Mgr45D8;

typedef struct {
    u8 pad00[0x14];
    u32 unk14;
    u8 pad18[0x08];
} Arr4568;

typedef struct {
    u8 pad00[0xC4];
    float fC4;
    u8 padC8[0x08];
    float posD0[4];
    u8 padE0[0x50];
} EffSlot9608;

extern s32 g_tbl_0040[];
extern u8 g_data_0050[];
extern u32 g_tbl_0488[];
extern u8 g_data_0498[];
extern Obj04E0 g_obj_04e0;
extern u8 g_data_0c60[];
extern Arr4568 g_arr_4568[];
extern u32 g_arr_45c8[];
extern Mgr45D8 g_mgr_45d8;
extern EffSlot9608 g_slot_4620[];
extern EffSlot9608 g_slot_4750[];
extern EffSlot9608 g_slot_49b0[];
extern u8 *g_ptr_4ae0;
extern u8 *g_ptr_4ae4;
extern u8 g_buf_a130[];
extern u8 g_buf_01B39900[];

extern u32 func_001B4E58(s32);
extern s32 func_001B6508(s32);
extern u32 func_002B49A0(void *, int, int);

extern s32 func_01B00F00(s32);
extern float func_01B01028(s32);
extern void func_01B01150(s32, float *, int);
extern s32 func_01B01B50(s32);
extern void func_01B02330(s32, int, float);
extern void func_01B02B38(s32, void *, void *);
extern void func_01B03118(void *, int, int, int);
extern void *func_01B03710(void *);
extern void func_01B038D8(void *);
extern void func_01B03998(void *, void *, void *, int);
extern void func_01B03A70(void *, void *, int, float, int, int, void *);

int func_01B008D8(void)
{
    u8 *base;
    Obj04E0 *obj;
    Mgr45D8 *mgr;
    register u32 *arr __asm__("$16");
    s32 idx;
    register s32 who __asm__("$17");
    int i;
    EffSlot9608 *s;

    base = g_buf_01B39900;
    g_ptr_4ae0 = base;
    g_ptr_4ae4 = base + 0x40000;

    obj = &g_obj_04e0;
    idx = func_01B00F00(-1);
    if (func_01B01B50(-1) == 1) {
        idx += 1;
        obj->b14 = idx;
        arr = obj->arr44;
        arr[idx] = func_001B4E58(idx);
        idx += 1;
        obj->b15 = idx;
        arr[idx] = func_001B4E58(idx);
    } else {
        idx -= 1;
        obj->b14 = idx;
        arr = obj->arr44;
        arr[idx] = func_001B4E58(idx);
        idx -= 1;
        obj->b15 = idx;
        arr[idx] = func_001B4E58(idx);
    }
    obj->unk04 = 2;

    mgr = &g_mgr_45d8;
    mgr->unk2C = func_002B49A0(g_buf_a130, 8, 0);
    func_01B03998(mgr, g_data_0050, g_ptr_4ae0, 0x40000);

    for (i = 0; i < 3; i++) {
        who = g_tbl_0040[i];
        if (func_001B6508(func_01B00F00(who)) == 0) {
            g_arr_45c8[i] = g_tbl_0488[i];
            func_01B02B38(who, &g_arr_4568[i], g_data_0498);
            switch (who) {
            case -1:
                s = g_slot_4750;
                __asm__("" : "+r"(who));
                func_01B03A70(mgr, s, 1, 0.3f, 0xB, 0, 0);
                func_01B01150(-1, s->posD0, 3);
                s->fC4 = func_01B01028(-1);
                s->posD0[1] -= 0.5f;
                s++;
                func_01B03A70(mgr, s, 2, 0.3f, 0x27, 0, 0);
                func_01B01150(-1, s->posD0, 3);
                s->fC4 = func_01B01028(-1);
                s->posD0[1] -= 0.5f;
                break;
            case 0:
                __asm__("" : "+r"(who));
                s = g_slot_4620;
                func_01B03A70(mgr, s, 0, 0.3f, 8, 0, 0);
                func_01B01150(0, s->posD0, 3);
                s->fC4 = func_01B01028(0);
                s->posD0[1] -= 0.5f;
                break;
            case 1:
                s = g_slot_49b0;
                func_01B03A70(mgr, s, 3, 0.3f, 8, 0, 0);
                func_01B01150(1, s->posD0, 3);
                s->fC4 = func_01B01028(1);
                s->posD0[1] -= 0.5f;
                break;
            }
        } else {
            func_01B02330(who, 0x1E, 0.0f);
            g_arr_4568[i].unk14 = 1;
            g_arr_45c8[i] = 0;
        }
    }

    func_01B03118(g_buf_a130, 0, 0x40, 0x100);
    func_01B038D8(func_01B03710(g_data_0c60));
    return 0;
}
