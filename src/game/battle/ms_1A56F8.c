/* tu_177 0x1a56f8-0x1ac0b8: low; ~Ms (config/tu_map.tsv) */
#define MsCameraSetRoll _hdr_MsCameraSetRoll
#define MsCameraSetScrDpt _hdr_MsCameraSetScrDpt
#define MsSetCameraMatrix _hdr_MsSetCameraMatrix
#define func_001A65E0 _hdr_func_001A65E0
#define func_001AA360 _hdr_func_001AA360
#include "common.h"
#include "vu0.h"
#include "ffx/r2.h"
#include "ffx/q3.h"
#include "ffx/s2.h"
#include "ffx/v2.h"
#include "ffx/u2.h"
/* Battle character / party / system config module (no source name string found), see include/ffx/w4.h */
#include "ffx/q4.h"
#include "ffx/t2.h"
#include "ffx/g2.h"
#undef func_001AA360
#undef func_001A65E0
#undef MsSetCameraMatrix
#undef MsCameraSetRoll
#undef MsCameraSetScrDpt

void func_001A56F8(int a, int b) {
    D_00314250 = a;
    D_00314254 = b;
}

typedef struct {
    u8 pad00[0x11C];
    float f11C;
    float f120;
    u8 pad124[0xC];
} CamAreaInit;

typedef struct {
    u8 pad00[0x30];
    s8 b30;
    u8 pad31[0x8B];
    void *other;
    u8 padC0[0x60];
    CamAreaInit area[4];
    u8 pad5E0[0x40];
} CamRecInit;

typedef struct {
    u8 pad00[0x4];
    float f04;
    u8 pad08[0x28];
    struct {
        s8 b00;
        u8 pad01[0x4F];
        float v50[4];
        u8 pad60[0x2C];
        void *other;
        u8 pad90[0x8C];
        struct {
            u8 pad00[0x11C];
            float f11C;
            float f120;
            u8 pad124[0xC];
        } area[4];
        u8 pad5DC[0x44];
    } rec[2];
    u8 padC70[0x24];
    s8 bC94;
    u8 padC95[0x33];
    struct {
        float f00;
        u8 pad04[0x2C];
    } subCC8[4];
    u8 padD88[0x18];
} CamSlotInit;

typedef struct {
    u8 pad00[0x38];
    float f38;
    float f3C;
    u8 pad40[0x8];
    struct {
        float x;
        float y;
        u8 pad08[0x8];
    } v48[2];
    u8 pad68[0x20];
    struct {
        float x;
        float y;
        u8 pad08[0x8];
    } v88[2];
    u8 padA8[0x18];
    s8 bC0;
    s8 bC1;
    u8 padC2[0xE];
    s32 wD0;
    u8 padD4[0xEC];
} ScrSlotInit;

extern CamSlotInit _cam_init_arr[3] __asm__("D_00314840");
extern ScrSlotInit _scr_init_arr[3] __asm__("ms_screen");
extern float D_0065FDC0;
extern s32 D_003142E0;
extern s32 D_0031712C;
void func_2037E98(void);
void MsEffectCameraInit(void);
void MsSplineInit(void);
void MsSetScreen(int, float, float, float, float, float, float, float, float, float);
void MsAtelCameraInit(void);

void MsCameraInit(void)
{
    int i, j, k;

    if (FFXIsDebug() != 0) {
        func_2037E98();
    }
    ms_camera_now = (void *)&_cam_init_arr[0];
    ms_screen_now = (void *)&_scr_init_arr[0];
    D_003142E0 = 0;
    D_0065FDC0 = 1024.0f;
    D_0031712C = 0;
    MsEffectCameraInit();
    MsSplineInit();
    for (i = 0; i < 3; i++) {
        CamSlotInit *cam = &_cam_init_arr[i];
        MsStructClear(cam, sizeof(CamSlotInit));
        cam->f04 = -1.0f;
        cam->bC94 = -1;
        for (j = 0; j < 2; j++) {
            CamSlotInit *r0 = &_cam_init_arr[i];
            u8 *r = (u8 *)r0 + j * 0x620;
            r[0x30] = j;
            *(void **)(r + 0xBC) = _cam_init_arr[i].rec[1 - j].v50;
        }
        for (k = 0; k < 4; k++) {
            _cam_init_arr[i].subCC8[k].f00 = 1024.0f;
            for (j = 0; j < 2; j++) {
                u8 *a = (u8 *)&_cam_init_arr[i] + k * 0x130 + j * 0x620;
                *(float *)(a + 0x150) = 1.0f;
                *(float *)(a + 0x14C) = 1.0f;
            }
        }
    }
    for (i = 0; i < 3; i++) {
        ScrSlotInit *scr = &_scr_init_arr[i];
        MsStructClear(scr, sizeof(ScrSlotInit));
        scr->bC1 = i;
        scr->wD0 = -1;
        scr->f38 = (float)D_00314250;
        scr->f3C = (float)D_00314254;
        for (k = 0; k < 2; k++) {
            u8 *p = (u8 *)&_scr_init_arr[i] + k * 0x10;
            *(float *)(p + 0x48) = (float)D_00314250;
            *(float *)(p + 0x4C) = (float)D_00314254;
            *(float *)(p + 0x88) = (float)D_00314250;
            *(float *)(p + 0x8C) = (float)D_00314254;
        }
        MsSetScreen(i, 512.0f, 0.8f, 14.0f / 15.0f, 2048.0f, 2048.0f, 1.0f, 16770000.0f, 1.0f, 65536.0f);
    }
    _scr_init_arr[0].bC0 = 1;
    MsAtelCameraInit();
}


INCLUDE_ASM("build/ee_asm/game/battle/ms_1A56F8", MsCameraProcess);
INCLUDE_RODATA("build/ee_asm/game/battle/ms_1A56F8/rodata", jtbl_0056DE80);

float MsNearRag(float a, float b)
{
    /* DEBT(FAKE): register pins steer float allocation of the saved base and delta. */
    register float base __asm__("$f3") = a;
    register float d __asm__("$f12");
    d = b - base;
    d -= (int)(d / 6.2831855f) * 6.2831855f;
    if (d < 0.0f) d += 6.2831855f;
    if (d < 3.1415927f) return base + d;
    return (base - 6.2831855f) + d;
}


int MsCameraMoveCalc(int is_ang, float *cur, R2Fade *fade, float start)
{
    if (fade->total != 0) {
        float target = *cur;

        if (is_ang != 0) {
            target = MsNearRag(start, target);
        }
        switch (fade->mode) {
        case 1:
            *cur = start + ((target - start) * fade->time) / fade->total;
            break;
        case 2:
            {
                float d = target - start;
                float v0 = (fade->h4 != 0) ? (d / fade->h4) : 0.0f;
                int t0 = fade->t0;
                int t1 = fade->t1;
                int t2 = fade->t2;
                float acc = (d - fade->total * v0) / (t0 * (t0 / 2 + t1) + t2 * (t0 - t2 / 2));
                float vmax = v0 + acc * t0;
                float p1 = start + (v0 + (acc * t0) * 0.5f) * t0;
                int t = fade->time;

                if (t < t0) {
                    *cur = start + (v0 + (acc * t) * 0.5f) * t;
                } else if (t < t0 + t1) {
                    *cur = p1 + vmax * (t - t0);
                } else if (t < t0 + t1 + t2) {
                    int dt = t - t0 - t1;

                    *cur = p1 + vmax * t1 + (vmax - (acc * dt) * 0.5f) * dt;
                } else {
                    *cur = target;
                }
            }
            break;
        case 3:
            {
                double s = start;
                double d = target - start;

                *cur = s + d * (-func_002E8648(fade->time * 3.1415927f / fade->total) + 1.0) * 0.5;
            }
            break;
        }
        fade->time++;
        if (fade->total < fade->time) {
            fade->total = 0;
        }
        return 1;
    }
    return 0;
}

extern s32 _m2c_func_001A65E0_D_00314840 __asm__("D_00314840");
/* DEBT(CAST) */
s32 func_001A65E0(s32 arg0) {
    s32 t_v0;
    s32 t_v1;
    s32 temp_5;
    s32 var_6;
    s32 var_7;
    s32 var_8;
    void *var_4;

    var_8 = 0;
    var_7 = 0;
    var_6 = 0;
    var_4 = ((arg0 & 0xFF) * 0xDA0) + ((u8 *)&_m2c_func_001A65E0_D_00314840);
    do {
        t_v0 = (*(s32 *)((u8 *)(var_4) + (0xC70)));
        t_v1 = (*(s8 *)((u8 *)(var_4) + (0xC76)));
        t_v0 &= 0xFF0000;
        temp_5 = t_v0 >> 0x10;
        temp_5 += t_v1;
        if ((var_7 < temp_5) && ((*(s8 *)((u8 *)(var_4) + (0xC74))) == 0) && ((*(s8 *)((u8 *)(var_4) + (0xC75))) == 0)) {
            var_7 = temp_5;
            var_8 = var_6;
        }
        var_6 += 1;
        var_4 += 8;
    } while (var_6 < 4);
    return var_8;
}

u32 func_001A6660(u32 a) {
    u32 hi = (a >> 16) & 0xF;
    a &= 0xFF00FFFF;
    return a | (hi << 16);
}

int MsCameraIDcheck(u32 h)
{
    int i = h & 0xFF;
    int k;

    if (((h >> 16) & 0xFF) == 0) {
        for (k = 0; k < 4; k++) {
            if ((D_00314840[i].slot[k].id & 0xFF0000) != 0 && D_00314840[i].slot[k].b5 == 0) {
                return 0;
            }
        }
        return -1;
    }
    for (k = 0; k < 4; k++) {
        if (D_00314840[i].slot[k].id == h && D_00314840[i].slot[k].b5 == 0) {
            return -1;
        }
    }
    return 0;
}

int func_001A6738(int a) {
    u8 id = a;
    int k = func_001A65E0(id);

    return D_00314840[id].slot[k].flag != 0 || D_00314840[id].slot[k].b5 != 0 ? 0 : D_00314840[id].slot[k].id;
}

int func_001A67A0(int a) {
    u8 k = (u32)func_001A6738(a) >> 16;
    int r = -1;

    switch (k) {
    case 3:
        r = 0;
        break;
    case 1:
        r = 1;
        break;
    case 5:
        r = 2;
        break;
    case 7:
        r = 3;
        break;
    }
    return r;
}

int func_001A6828(int a) {
    return func_001A6738(a) == a ? -1 : 0;
}

INCLUDE_ASM("build/ee_asm/game/battle/ms_1A56F8", MsCameraGet);

int MsCameraFree(int id)
{
    int n = 0;
    int i;

    for (i = 0; i < 4; i++) {
        if (func_001A6660(D_00314840[id & 0xFF].slot[i].id) == func_001A6660(id)) {
            D_00314840[id & 0xFF].slot[i].id = 0;
            n++;
            D_00314840[id & 0xFF].slot[i].flag = 0;
            D_00314840[id & 0xFF].slot[i].b5 = 0;
            D_00314840[id & 0xFF].slot[i].b6 = 0;
        }
    }
    return n;
}

void func_001A6B90(int id) {
    int i;

    for (i = 3; i >= 0; i--) {
        D_00314840[id & 0xFF].slot[i].id = 0;
    }
}

void func_001A6BE0(int id, int on) {
    int i;

    on &= 1;
    for (i = 0; i < 4; i++) {
        if (D_00314840[id & 0xFF].slot[i].id == id) {
            D_00314840[id & 0xFF].slot[i].flag = on;
        }
    }
}

void MsCameraPriority(int id, int v) {
    int i;

    if (D_0031712C == 0) {
        for (i = 0; i < 4; i++) {
            if (D_00314840[id & 0xFF].slot[i].id == id) {
                D_00314840[id & 0xFF].slot[i].b6 = v;
            }
        }
    }
}

void func_001A6C78(int v) {
    D_0031712C = v;
}

int func_001A8F40(Unk317120Rec *rec, R2Area *dst_area, R2Area *area, int flag);

int MsSetCheckChange(int id, int which, int flag, int kind)
{
    Unk314840 *cam = &D_00314840[id & 0xFF];
    Unk317120Rec *rec = &cam->rec[which];
    struct Unk314840Ent *ent = &cam->eCC0[(id & 0xFF00) >> 8];
    R2Area *area;
    int ok;
    int i;

    if (kind == 1) {
        if (cam->fadeD80[0].total != 0) {
            return 0;
        }
        ((Unk317120 *)cam)->fC98 = cam->fC9C;
        *(float *)&ent->pad1C[0] = cam->fC9C;
        return -1;
    }
    if (kind == 2) {
        if (cam->fadeD80[1].total != 0) {
            return 0;
        }
        ((Unk317120 *)cam)->fCA4 = cam->fCA8;
        *(float *)&ent->pad1C[4] = cam->fCA8;
        return -1;
    }
    ok = (((s8 *)rec)[3] == 0);
    for (i = 0; i < 3; i++) {
        if (rec->fade[i].total != 0 && rec->b1 == 1) {
            ok = 0;
        }
    }
    func_001A8F40(rec, (R2Area *)&cam->rec[1 - which], area = &rec->area[(id & 0xFF00) >> 8], flag);
    if (ok != 0) {
        for (i = 0; i < 3; i++) {
            if (rec->fade[i].total == 0) {
                rec->v20[i] = rec->v50[i];
                ((float *)area->pad_80)[i] = rec->v20[i];
            }
        }
        return -1;
    }
    return 0;
}

void func_001A6E10(int a, int b, int v) {
    if (MsCameraIDcheck(a)) {
        Unk317120Rec *r;

        b &= 1;
        r = &D_00314870[a & 0xFF].rec[b];

        ((S2CamEnt *)r)[(a & 0xFF00) >> 8].fC7 = v; /* DEBT(CAST): five 0x130-byte entries overlay the record */
    }
}

void func_001A6E90(int h, int which, float x, float y, float z) {
    Unk317120Rec *rec;
    R2Area *area;
    int r;
    register float fz __asm__("$f20") = z;
    register float fx __asm__("$f21") = x;
    register float fy __asm__("$f22") = y;

    if (MsCameraIDcheck(h)) {
        which &= 1;
        rec = &D_00314870[h & 0xFF].rec[which];
        area = &rec->area[(h & 0xFF00) >> 8];
        area->b00 = 1;
        area->b02 = 2;
        area->b07 = 0;
        area->v40[0] = fx;
        area->v40[1] = fy;
        area->v40[2] = fz;
        r = func_001A6738(h);
        if (r == h) {
            rec->v60[2] = fz;
            rec->v60[0] = fx;
            rec->v60[1] = fy;
            *(int *)rec->pad6C = 0;
            MsSetCheckChange(r, which, 1, 0);
        }
    }
}

void func_001A70F0(Unk317120Rec *rec, R2Area *area, R2Area *other);

void func_001A6FA0(int h, int which, float x, float y, float z)
{
    Unk317120Rec *rec;
    R2Area *area;
    R2Area *other;
    int ow;
    int r;

    if (MsCameraIDcheck(h)) {
        which &= 1;
        ow = (which == 0) ? 1 : 0;
        rec = &D_00314870[h & 0xFF].rec[which];
        area = &rec->area[(h & 0xFF00) >> 8];
        other = &D_00314870[h & 0xFF].rec[ow].area[(h & 0xFF00) >> 8];
        area->b00 = 1;
        area->b02 = 10;
        area->v40[0] = x;
        area->v40[1] = y;
        area->v40[2] = z;
        area->b07 = 0;
        r = func_001A6738(h);
        if (r == h) {
            func_001A70F0(rec, area, other);
            MsSetCheckChange(r, which, 1, 0);
        }
    }
}

INCLUDE_ASM("build/ee_asm/game/battle/ms_1A56F8", func_001A70F0);

/* DEBT(CAST): the area object is supplied through the existing integer-address interface. */
void MsCameraSetSpline(s32 h, s32 which, s32 var, float x, float y, s32 n)
{
    R2Area *area;
    Unk314840 *state;
    Unk317120Rec *record;
    s32 current;

    if ((MsCameraIDcheck((u32) h) != 0) && (var != 0))
    {
        which &= 1;
        state = &D_00314840[h & 0xFF];
        record = &state->rec[which];
        area = &record->area[(s32) (h & 0xFF00) >> 8];
        area->obj = (R2AreaObj *) var;
        area->b02 = 0xE;
        area->b1C = (u8) n;
        area->f68 = x;
        area->f6C = y;
        area->b07 = 0;
        area->b00 = 0;
        current = func_001A6738(h);
        if (current == h)
        {
            func_001A7308(current, which, state, record, area);
            MsSetCheckChange(current, which, 0, 0);
        }
    }
}

void MsCameraSetRoll(s32 arg0, float fparg0);
int _m2c_func_002D5448_d() __asm__("func_002D5448");
int _m2c_func_002D5450_d() __asm__("func_002D5450");
int _m2c_TkMtCalcSpline_d() __asm__("TkMtCalcSpline");
int _m2c_func_002D5188_d() __asm__("func_002D5188");

void func_001A7308(int id, int which, Unk314840 *state, Unk317120Rec *rec, R2Area *area)
{
    float pos[4];
    float dir[4];
    int done = 0;
    s8 c;

    if (area->f68 < 0.0) {
        area->f68 = 0.0f;
        done = 1;
    }
    if (area->f68 > 1.0) {
        area->f68 = 1.0f;
        done = 1;
    }
    c = *(s8 *)&area->b1C;
    if ((c & 3) == 3) {
        _m2c_func_002D5448_d(pos, ((S2EntObj *)area->obj)->sub, ((S2EntObj *)area->obj)->flags, area->f68);
        if (c & 4) {
            _m2c_func_002D5450_d(dir, ((S2EntObj *)area->obj)->sub, ((S2EntObj *)area->obj)->flags, area->f68);
            if (area->f6C >= 0.0f) {
                func_001AC3D0(pos, pos, dir);
            } else {
                func_001AC3E8(pos, pos, dir);
            }
        }
    } else {
        _m2c_TkMtCalcSpline_d(pos, ((S2EntObj *)area->obj)->sub, ((S2EntObj *)area->obj)->flags, area->f68);
        if (c & 4) {
            _m2c_func_002D5188_d(dir, ((S2EntObj *)area->obj)->sub, ((S2EntObj *)area->obj)->flags, area->f68);
            if (area->f6C >= 0.0f) {
                func_001AC3D0(pos, pos, dir);
            } else {
                func_001AC3E8(pos, pos, dir);
            }
        }
    }
    MMI_COPY_LQ_T0(rec->v50, pos);
    MMI_COPY_SQ_T0(rec->v50);
    MsCameraSetRoll(id, pos[3]);
    *(float *)rec->pad6C = 0.0f;
    area->f68 += area->f6C;
    if (done != 0 || area->f6C == 0.0) {
        MsCameraSetRect(id, which, rec->v50);
    }
}

void func_001A7648(int id, int which, Unk317120Rec *rec, R2Area *area, R2Area *area2);

void func_001A7530(int h, int which, R2AreaObj *var, int n) {
    Unk317120Rec *record;
    R2Area *area;
    int current;

    if (MsCameraIDcheck(h) != 0 && var != 0) {
        which &= 1;
        record = &D_00314870[h & 0xFF].rec[which];
        area = &record->area[(h & 0xFF00) >> 8];
        area->obj = var;
        area->b02 = 0x11;
        area->b1C = n;
        area->b07 = 0;
        area->b00 = 0;
        current = func_001A6738(h);
        if (current == h) {
            func_001A7648(current, which, record, area, area);
            MsSetCheckChange(current, which, 0, 0);
        }
    }
}

void _m2c_func_002D5448() __asm__("func_002D5448");
void _m2c_TkMtCalcSpline() __asm__("TkMtCalcSpline");

void func_001A7648(int id, int which, Unk317120Rec *rec, R2Area *area, R2Area *area2) {
    float pos[4];
    int c = *(s8 *)&area->b1C;

    if ((c & 3) == 3) {
        _m2c_func_002D5448(pos, ((S2EntObj *)area->obj)->sub, ((S2EntObj *)area->obj)->flags, area2->f24);
    } else {
        _m2c_TkMtCalcSpline(pos, ((S2EntObj *)area->obj)->sub, ((S2EntObj *)area->obj)->flags, area2->f24);
    }
    MMI_COPY_LQ_T0(rec->v50, pos);
    MMI_COPY_SQ_T0(rec->v50);
    *(int *)rec->pad6C = 0;
}

void func_001A76E0(int h, int which, float x, float y, float z)
{
    Unk317120Rec *rec;
    R2Area *area;

    if (MsCameraIDcheck(h)) {
        which &= 1;
        rec = &D_00314870[h & 0xFF].rec[which];
        area = &rec->area[(h & 0xFF00) >> 8];
        area->b07 = 0;
        if (area->b00 == 0) {
            /* DEBT(CAST): raw offset access into Unk317120Rec vector at +0x50 */
            MsVectorRect2Polar((float *)((u8 *)rec + 0x50), rec->w8C, &area->v40[0], &area->v40[1], &area->v40[2]);
        }
        area->b00 = 1;
        area->b02 = 7;
        area->v40[0] += x;
        area->v40[1] += y;
        area->v40[2] += z;
        if (func_001A6738(h) == h) {
            *(float *)rec->pad6C = 0.0f;
            rec->v60[0] = area->v40[0];
            rec->v60[1] = area->v40[1];
            rec->v60[2] = area->v40[2];
            MsSetCheckChange(h, which, 1, 0);
        }
    }
}

void MsCameraSetRect(int h, int which, void *v) {
    Unk317120Rec *record;
    R2Area *area;
    int current;

    if (MsCameraIDcheck(h)) {
        which &= 1;
        record = &D_00314870[h & 0xFF].rec[which];
        area = &record->area[(h & 0xFF00) >> 8];
        area->b02 = 1;
        area->b07 = 0;
        area->b00 = 0;
        MMI_COPY_LQ_T0(area->v30, v);
        MMI_COPY_SQ_T0(area->v30);
        current = func_001A6738(h);
        if (current == h) {
            *(int *)record->pad6C = 0;
            MMI_COPY_LQ_T0(record->v50, v);
            MMI_COPY_SQ_T0(record->v50);
            MsSetCheckChange(current, which, 0, 0);
        }
    }
}

void MsCameraSetAct(int h, int which, int a2, int a3, void *v) {
    Unk317120Rec *record;
    R2Area *area;
    int current;

    if (MsCameraIDcheck(h)) {
        which &= 1;
        record = &D_00314870[h & 0xFF].rec[which];
        area = &record->area[(h & 0xFF00) >> 8];
        area->b02 = 3;
        ((s16 *)area->pad_0C)[0] = a2;
        ((s16 *)area->pad_0C)[1] = a3;
        area->b07 = 0;
        area->b00 = 0;
        MMI_COPY_LQ_T0(area->v30, v);
        MMI_COPY_SQ_T0(area->v30);
        current = func_001A6738(h);
        if (current == h) {
            func_001A7A58(record, area);
            MsSetCheckChange(current, which, 0, 0);
        }
    }
}

void func_001A7A58(Unk317120Rec *rec, R2Area *area) {
    float sum[4];
    float pos[3];
    float *p = &sum[3];
    float *src;
    u16 *ids;
    float *dst;
    int count = 0;
    int i;

    for (i = 3; i >= 0; i--) {
        *p-- = 0.0f;
    }
    ids = (u16 *)area->pad_0C;
    for (i = 0; i < 2; i++, ids++) {
        if (*ids != 0xFFFF) {
            func_00142FF0(*ids, &pos[0], &pos[1], &pos[2]);
            count++;
            sum[0] += pos[0];
            sum[1] += pos[1];
            sum[2] += pos[2];
        }
    }
    if (count >= 2) {
        float c = count;

        p = sum;
        for (i = 0; i < 3; i++, p++) {
            *p /= c;
        }
    }
    dst = rec->v50;
    src = area->v30;
    p = sum;
    for (i = 0; i < 3; i++) {
        float s = *src;

        *dst = *p + s;
        src++;
        p++;
        dst++;
    }
    *(int *)rec->pad6C = 0;
}

void func_001A7D28(Unk317120Rec *rec, R2Area *area);

void func_001A7BC0(int h, int which, float f0, float f1, float f2, float f3, float f4, float f5)
{
    Unk317120Rec *rec;
    R2Area *area;
    int r;

    if (MsCameraIDcheck(h)) {
        which &= 1;
        rec = &D_00314870[h & 0xFF].rec[which];
        area = &rec->area[(h & 0xFF00) >> 8];
        area->b00 = 1;
        area->b02 = 4;
        area->v30[0] = f0;
        area->v30[2] = f1;
        area->v40[1] = f2;
        area->v40[2] = f4;
        area->v50[1] = f3;
        area->v50[2] = f5;
        area->b07 = 0;
        r = func_001A6738(h);
        if (r == h) {
            func_001A7D28(rec, area);
            MsSetCheckChange(r, which, 1, 0);
        }
    }
}

void func_001A7D28(Unk317120Rec *rec, R2Area *area) {
    float dummy;
    float r;

    MsVectorRect2Polar(area->v30, (void *)rec->w8C, (int)&rec->v60[0], (int)&dummy, (int)&r);
    rec->v60[1] = area->v40[1];
    if (area->v50[1] != 0.0) {
        rec->v60[1] += r / area->v50[1];
    }
    rec->v60[2] = area->v40[2];
    if (area->v50[2] != 0.0) {
        rec->v60[2] += r / area->v50[2];
    }
    *(int *)rec->pad6C = 0;
}

void func_001A7F88(Unk317120Rec *rec, R2Area *area);
void func_001A8058(Unk317120Rec *rec, R2Area *area);

void func_001A7E00(int h, int which, int mode, float f0, float f1, float f2, float f3, float f4, float f5)
{
    Unk317120Rec *rec;
    R2Area *area;

    if (MsCameraIDcheck(h)) {
        which &= 1;
        rec = &D_00314870[h & 0xFF].rec[which];
        area = &rec->area[(h & 0xFF00) >> 8];
        area->b00 = 1;
        area->b07 = 0;
        if (mode) {
            area->b02 = 6;
        } else {
            area->b02 = 5;
        }
        area->v30[0] = f0;
        area->v30[1] = f1;
        area->v30[2] = f2;
        area->v40[2] = f4;
        area->v50[1] = f3;
        area->v50[2] = f5;
        if (func_001A6738(h) == h) {
            if (mode) {
                func_001A8058(rec, area);
            } else {
                func_001A7F88(rec, area);
            }
            MsSetCheckChange(h, which, 1, 0);
        }
    }
}

void func_001A7F88(Unk317120Rec *rec, R2Area *area) {
    float r;

    MsVectorRect2Polar(area->v30, (void *)rec->w8C, (int)&rec->v60[0], (int)&rec->v60[1], (int)&r);
    if (area->v50[1] != 0.0) {
        rec->v60[1] += r / area->v50[1];
    }
    rec->v60[2] = area->v40[2];
    if (area->v50[2] != 0.0) {
        rec->v60[2] += r / area->v50[2];
    }
    *(int *)rec->pad6C = 0;
}

void func_001A8058(Unk317120Rec *rec, R2Area *area) {
    float r;
    float z;

    MsVectorRect2Polar(area->v30, (void *)rec->w8C, (int)&rec->v60[0], (int)&rec->v60[1], (int)&r);
    if (area->v50[1] != 0.0) {
        rec->v60[1] += r / area->v50[1];
    }
    z = area->v40[2];
    if (area->v50[2] != 0.0) {
        z += r / area->v50[2];
    }
    rec->v60[2] = r - z;
    *(int *)rec->pad6C = 0;
}

s32 _m2c_MsCameraSetRoll_MsCameraIDcheck() __asm__("MsCameraIDcheck");
void _m2c_MsCameraSetRoll_MsSetCheckChange(s32, s32, s32, s32) __asm__("MsSetCheckChange");
s32 _m2c_MsCameraSetRoll_func_001A6738(s32, void *, void *) __asm__("func_001A6738");
extern s32 _m2c_MsCameraSetRoll_D_00314840 __asm__("D_00314840");
/* DEBT(CAST) */
void MsCameraSetRoll(s32 arg0, float fparg0) {
    s32 temp_2;
    s32 temp_3;
    s32 temp_6;
    void *temp_17;
    void *temp_5;
    void *temp_6_2;

    if (_m2c_MsCameraSetRoll_MsCameraIDcheck() != 0) {
        temp_6 = (arg0 & 0xFF) * 0xDA0;
        temp_3 = (s32) (arg0 & 0xFF00) >> 8;
        temp_17 = temp_6 + ((u8 *)&_m2c_MsCameraSetRoll_D_00314840);
        temp_6_2 = temp_6 + (((u8 *)&_m2c_MsCameraSetRoll_D_00314840) + 0x650);
        temp_5 =((void *)((u8 *)((temp_3 * 0x130)) + (s32)temp_6_2));
        (*(s8 *)((u8 *)(temp_5) + (0xC7))) = 0;
        (*(float *)((u8 *)((((void *)((u8 *)((temp_3 * 0x30)) + (s32)temp_17)))) + (0xCC0))) = fparg0;
        temp_2 = _m2c_MsCameraSetRoll_func_001A6738(arg0, temp_5, temp_6_2);
        if (temp_2 == arg0) {
            (*(float *)((u8 *)(temp_17) + (0xC9C))) = fparg0;
            _m2c_MsCameraSetRoll_MsSetCheckChange(temp_2, 1, 0, 1);
        }
    }
}

s32 _m2c_MsCameraSetScrDpt_MsCameraIDcheck() __asm__("MsCameraIDcheck");
void _m2c_MsCameraSetScrDpt_MsSetCheckChange(s32, s32, s32, s32) __asm__("MsSetCheckChange");
s32 _m2c_MsCameraSetScrDpt_func_001A6738(s32, void *, void *) __asm__("func_001A6738");
extern s32 _m2c_MsCameraSetScrDpt_D_00314840 __asm__("D_00314840");
/* DEBT(CAST) */
void MsCameraSetScrDpt(s32 arg0, float fparg0) {
    s32 temp_2;
    s32 temp_3;
    s32 temp_6;
    void *temp_17;
    void *temp_5;
    void *temp_6_2;

    if (_m2c_MsCameraSetScrDpt_MsCameraIDcheck() != 0) {
        temp_6 = (arg0 & 0xFF) * 0xDA0;
        temp_3 = (s32) (arg0 & 0xFF00) >> 8;
        temp_17 = temp_6 + ((u8 *)&_m2c_MsCameraSetScrDpt_D_00314840);
        temp_6_2 = temp_6 + (((u8 *)&_m2c_MsCameraSetScrDpt_D_00314840) + 0x650);
        temp_5 =((void *)((u8 *)((temp_3 * 0x130)) + (s32)temp_6_2));
        (*(s8 *)((u8 *)(temp_5) + (0xC7))) = 0;
        (*(float *)((u8 *)((((void *)((u8 *)((temp_3 * 0x30)) + (s32)temp_17)))) + (0xCC8))) = fparg0;
        temp_2 = _m2c_MsCameraSetScrDpt_func_001A6738(arg0, temp_5, temp_6_2);
        if (temp_2 == arg0) {
            (*(float *)((u8 *)(temp_17) + (0xCA8))) = fparg0;
            _m2c_MsCameraSetScrDpt_MsSetCheckChange(temp_2, 1, 0, 2);
        }
    }
}

void func_001A82A8(int id, int v)
{
    Unk314840 *p;
    struct Unk314840Ent *e;

    if (MsCameraIDcheck(id) != 0) {
        p = &D_00314840[id & 0xFF];
        e = &p->eCC0[(id & 0xFF00) >> 8];
        p->wCB0 = 1;
        if (v < 0) {
            v = e->w10 | 2;
        }
        e->w10 = v;
        if (func_001A6738(id) == id) {
            p->wCB4 = v;
        }
    }
}

void func_001A8340(int h, int which, int v)
{
    Unk314840 *p;
    struct Unk314840Ent *e;

    if (MsCameraIDcheck(h) != 0) {
        p = &D_00314840[h & 0xFF];
        which &= 1;
        p->wCB0 = 1;
        e = &p->eCC0[(h & 0xFF00) >> 8];
        e->w14[which] = v;
        if (func_001A6738(h) == h) {
            p->wCB8[which] = v;
        }
    }
}

void func_001A83F0(int id, int which, int flags, R2AreaObj *obj, float r)
{
    Unk317120Rec *rec;
    R2Area *area;
    int cur;

    if (MsCameraIDcheck(id)) {
        which &= 1;
        rec = &D_00314870[id & 0xFF].rec[which];
        area = &rec->area[(id & 0xFF00) >> 8];
        area->b00 = 1;
        area->b02 = 8;
        area->b07 = 0;
        area->b03 = obj->flags | flags;
        area->obj = obj;
        area->v40[0] = r;
        cur = func_001A6738(id);
        if (cur == id) {
            func_001A8518(rec, area);
            MsSetCheckChange(cur, which, 1, 0);
        }
    }
}

typedef struct {
    float x, y, z, w;
    float a, b, c, d;
    float e;
    u8 pad[0xC];
} CamPt30;

typedef struct {
    int count;
    u8 pad4[0xC];
    CamPt30 pts[1];
} CamPtList;

void func_001A8518(Unk317120Rec *rec, R2Area *area)
{
    CamPtList *list = (CamPtList *)area->obj;
    CamPt30 *p = list->pts;
    int count = list->count;
    u8 flags = area->b03;
    float total = 0.0f;
    float s3, s0, s1, s2, wsum;
    int i;

    if (flags & 1) {
        for (i = 0; i < count; i++, p++) {
            float dx = (flags & 2) ? 0.0f : (*(float *)((u8 *)rec + 0x30) - p->x);
            float dy = (flags & 4) ? 0.0f : (*(float *)((u8 *)rec + 0x34) - p->y);
            float dz = (flags & 8) ? 0.0f : (*(float *)((u8 *)rec + 0x38) - p->z);
            float dist = sqrtf(dx * dx + dy * dy + dz * dz) + 1.0;

            p->d = (dist * dist) / p->w;
            total += p->d;
        }
    } else {
        for (i = 0; i < count; i++, p++) {
            float dx = (flags & 2) ? 0.0f : (*(float *)((u8 *)rec + 0x30) - p->x);
            float dy = (flags & 4) ? 0.0f : (*(float *)((u8 *)rec + 0x34) - p->y);
            float dz = (flags & 8) ? 0.0f : (*(float *)((u8 *)rec + 0x38) - p->z);
            float dist = sqrtf(dx * dx + dy * dy + dz * dz) + 1.0;

            p->d = dist / p->w;
            total += p->d;
        }
    }
    p = ((CamPtList *)area->obj)->pts;
    wsum = 0.0f;
    s0 = 0.0f;
    s1 = 0.0f;
    s2 = 0.0f;
    s3 = 0.0f;
    for (i = 0; i < count; i++, p++) {
        float w = total / p->d;

        s0 += w * p->a;
        s1 += w * p->b;
        s2 += w * p->c;
        s3 += w * p->e;
        wsum += w;
    }
    rec->v60[0] = s0 / wsum + area->v40[0];
    rec->v60[1] = s1 / wsum;
    rec->v60[2] = s2 / wsum;
    *(float *)rec->pad6C = s3 / wsum;
}

void func_001A8850(int id, int which, int flags, R2AreaObj *obj, float y, float x, float z) {
    Unk317120Rec *rec;
    R2Area *area;
    int r;

    if (MsCameraIDcheck(id)) {
        which &= 1;
        rec = &D_00314870[id & 0xFF].rec[which];
        area = &rec->area[(id & 0xFF00) >> 8];
        area->b00 = 1;
        area->b02 = 9;
        area->b07 = 0;
        area->b03 = obj->flags | flags;
        area->obj = obj;
        area->v30[0] = x;
        area->v30[2] = z;
        area->v50[0] = y;
        r = func_001A6738(id);
        if (r == id) {
            func_001A89B0(rec, area);
            func_001A8518(rec, area);
            MsSetCheckChange(r, which, 1, 0);
        }
    }
}

void func_001A89B0(Unk317120Rec *rec, R2Area *area) {
    MsVectorRect2Polar(area->v30, rec->w8C, area->v40, 0, 0);
    area->v40[0] += area->v50[0];
}

void func_001A89F8(int a, int b, int hard, float x1, float z1, float x2, float z2, float k)
{
    R2Area *area;
    R2Limit *l;
    float dx;
    float dz;

    if (MsCameraIDcheck(a)) {
        b &= 1;
        area = &D_00314870[a & 0xFF].rec[b].area[(a & 0xFF00) >> 8];
        if (area->nlim < 5) {
            l = &area->lim[area->nlim];
            if (hard) {
                l->type = 2;
            } else {
                l->type = 0;
            }
            l->k = k;
            l->x = x1;
            l->z = z1;
            dx = x2 - x1;
            dz = z2 - z1;
            l->nx = dx;
            l->nz = dz;
            l->d = -x1 * dx - z1 * dz;
            l->len = dx * dx + dz * dz;
            area->nlim++;
        }
    }
}

void func_001A8B38(int a, int b, int ceil, float lo, float hi, float k) {
    R2Area *area;
    R2Limit *l;

    if (MsCameraIDcheck(a)) {
        b &= 1;
        area = &D_00314870[a & 0xFF].rec[b].area[(a & 0xFF00) >> 8];
        if (area->nlim < 5) {
            l = &area->lim[area->nlim];
            if (ceil) {
                l->type = 3;
            } else {
                l->type = 1;
            }
            l->x = lo;
            l->z = hi;
            l->k = k;
            area->nlim++;
        }
    }
}

void func_001A8C28(int a, int b, float f, R2AreaObj *obj, int type) {
    R2Area *area;
    R2Limit *l;

    if (MsCameraIDcheck(a)) {
        b &= 1;
        area = &D_00314870[a & 0xFF].rec[b].area[(a & 0xFF00) >> 8];
        if (area->nlim < 5) {
            l = &area->lim[area->nlim];
            if (type == 3) {
                area->b1E = 1;
                l->type = 5;
            } else {
                area->b1E = 0;
                l->type = 4;
            }
            area->obj = obj;
            area->f20 = f;
            area->nlim++;
            area->b1D = 1;
            area->f24 = 0.0f;
        }
    }
}

void func_001A8D28(int a, int b) {
    if (MsCameraIDcheck(a)) {
        b &= 1;
        D_00314840[a & 0xFF].rec[b].area[(a & 0xFF00) >> 8].nlim = 0;
    }
}

void func_001A8DA0(int a, int b, int c) {
    if (MsCameraIDcheck(a)) {
        Unk317120Rec *r;

        b &= 1;
        r = &D_00314870[a & 0xFF].rec[b];
        ((S2CamEnt *)r)[(a & 0xFF00) >> 8].fC5 = c & 1; /* DEBT(CAST): five 0x130-byte entries overlay the record */
    }
}

void _m2c_spline_get_near_point_init(R2AreaObj *obj, float px, float py, float pz, int mode) __asm__("spline_get_near_point_init");
float _m2c_spline_get_near_point(R2AreaObj *obj, float px, float py, float pz, float *x, float *y, float *z, int mode) __asm__("spline_get_near_point");
int func_001A9040(Unk317120Rec *rec, R2Area *area);

int func_001A8E28(int unused, Unk317120Rec *rec, R2Area *area) {
    float x, y, z;
    int count = 0;
    int i;

    for (i = 0; i < area->nlim; i++) {
        u32 type = area->lim[i].type;

        if (type - 4 < 2U) {
            int mode;

            if (area->b00 == 1) {
                func_001AC750(rec->v50, rec->w8C, rec->v60[0], rec->v60[1], rec->v60[2]);
            }
            area->b1D = 0;
            count++;
            _m2c_spline_get_near_point_init(area->obj, rec->v50[0], rec->v50[1], rec->v50[2], area->b1E);
            mode = 0;
            if (type != 4) {
                mode = 1;
            }
            area->f24 = _m2c_spline_get_near_point(area->obj, rec->v50[0], rec->v50[1], rec->v50[2], &x, &y, &z, mode);
        }
    }
    return count;
}

int func_001A8F40(Unk317120Rec *rec, R2Area *dst_area, R2Area *area, int flag) {
    if (flag == 1) {
        func_001AC750(rec->v50, rec->w8C, rec->v60[0], rec->v60[1], rec->v60[2]);
    }
    dst_area->v30[0] = rec->v50[0];
    dst_area->v30[1] = rec->v50[1];
    dst_area->v30[2] = rec->v50[2];
    if (area->b1D != 0) {
        area->b1D = 0;
        _m2c_spline_get_near_point_init(area->obj, rec->v50[0], rec->v50[1], rec->v50[2], area->b1E);
    }
    if (area->nlim != 0 && area->b05 == 0) {
        if (func_001A9040(rec, area) != 0) {
            flag = 0;
        }
    }
    if (dst_area->f6C != 0.0) {
        flag = 0;
        rec->v50[1] += dst_area->f6C;
    }
    return flag;
}

int func_001A9040(Unk317120Rec *rec, R2Area *area) {
    float pt[4];
    float diff[4];
    float scale;
    float dist;
    int hit = 0;
    int i;

    for (i = 0; i < area->nlim; i++) {
        R2Limit *lim = &area->lim[i];
        switch (lim->type) {
        case 0:
        case 2: {
            float t = (rec->v50[0] * lim->nx + rec->v50[2] * lim->nz + lim->d) / lim->len;
            float px = t * lim->nx + lim->x;
            float pz = t * lim->nz + lim->z;
            float dx = rec->v50[0] - px;
            float dz = rec->v50[2] - pz;
            pt[0] = px;
            pt[2] = pz;
            if (lim->type == 0) {
                dist = sqrtf(dx * dx + dz * dz);
                scale = func_002E8370(dist * lim->k) / lim->k;
                if (dist != 0.0) {
                    pt[0] = (scale * dx) / dist + pt[0];
                    pt[2] = (scale * dz) / dist + pt[2];
                }
            } else {
                pt[0] = dx * lim->k + px;
                pt[2] = dz * lim->k + pz;
            }
            if (func_001ACD48(lim->nx, lim->nz, dx, dz) != 0) {
                rec->v50[0] = pt[0];
                rec->v50[2] = pt[2];
                hit++;
            }
            break;
        }
        case 1:
            dist = lim->x - rec->v50[1];
            if (dist > 0.0) {
                hit++;
                scale = func_002E8370(dist * lim->k) / lim->k;
                rec->v50[1] = lim->x - scale;
            }
            dist = rec->v50[1] - lim->z;
            if (dist > 0.0) {
                hit++;
                scale = func_002E8370(dist * lim->k) / lim->k;
                rec->v50[1] = lim->z + scale;
            }
            break;
        case 3:
            dist = rec->v50[1] - lim->x;
            if (dist > 0.0) {
                hit++;
                rec->v50[1] = dist * lim->k + lim->x;
            }
            dist = rec->v50[1] - lim->z;
            if (dist < 0.0) {
                hit++;
                rec->v50[1] = dist * lim->k + lim->z;
            }
            break;
        case 4:
            area->f24 = _m2c_spline_get_near_point(area->obj, rec->v50[0], rec->v50[1], rec->v50[2], &pt[0], &pt[1], &pt[2], 0);
            func_001AC3E8(diff, rec->v50, pt);
            func_001ACB10(diff, area->f20);
            func_001AC3D0(rec->v50, pt, diff);
            hit++;
            break;
        case 5:
            area->f24 = _m2c_spline_get_near_point(area->obj, rec->v50[0], rec->v50[1], rec->v50[2], &pt[0], &pt[1], &pt[2], 1);
            func_001AC3E8(diff, rec->v50, pt);
            func_001ACB10(diff, area->f20);
            func_001AC3D0(rec->v50, pt, diff);
            hit++;
            break;
        }
    }
    return hit;
}

void MsCameraSetStartPos(Unk314840 *cam, Unk317120Rec *rec, R2Area *area) {
    int chg = 0;
    int i;

    if (area->b00 == 1) {
        if (!(area->b07 & 1)) {
            chg = 1;
            rec->v80[0] = rec->v60[0];
        }
        if (!(area->b07 & 2)) {
            chg++;
            rec->v80[1] = rec->v60[1];
        }
        if (!(area->b07 & 4)) {
            chg++;
            rec->v80[2] = rec->v60[2];
        }
        if (chg != 0) {
            func_001AC750(rec->v70, rec->w8C, rec->v60[0], rec->v60[1], rec->v60[2]);
        }
    } else {
        for (i = 0; i < 3; i++) {
            if (!((area->b07 >> i) & 1)) {
                chg++;
                rec->v70[i] = rec->v50[i];
            }
        }
        if (chg != 0) {
            MsVectorRect2Polar(rec->v50, (void *)rec->w8C, (int)&rec->v80[0], (int)&rec->v80[1], (int)&rec->v80[2]);
        }
    }
    if (cam != 0) {
        if (!(area->b07 & 8)) {
            cam->fCA0 = cam->fC9C;
        }
        if (!(area->b07 & 0x10)) {
            cam->fCAC = cam->fCA8;
        }
    }
}

void func_001A9550(int id, int which, int c, int total, int mode) {
    int r;
    int i;
    Unk314840 *cam;
    Unk317120Rec *rec;
    R2Area *area;

    r = func_001A6738(id);
    if (r == id) {
        which &= 1;
        cam = &D_00314840[r & 0xFF];
        rec = &cam->rec[which];
        rec->b1 = c;
        area = &rec->area[(r & 0xFF00) >> 8];
        if (which == 0) {
            cam = 0;
        } else {
            for (i = 0; i < 2; i++) {
                if (!((area->b07 >> (i + 3)) & 1)) {
                    cam->fadeD80[i].mode = mode;
                    cam->fadeD80[i].total = total;
                    cam->fadeD80[i].time = 0;
                }
            }
        }
        for (i = 0; i < 3; i++) {
            if (!((area->b07 >> i) & 1)) {
                rec->fade[i].mode = mode;
                rec->fade[i].total = total;
                rec->fade[i].time = 0;
            }
        }
        MsCameraSetStartPos(cam, rec, area);
        area->b07 = 0;
    }
}

void func_001A96A8(int id, int which, int c, int t0, int t1, int t2, int h4) {
    int r;
    int i;
    Unk314840 *cam;
    Unk317120Rec *rec;
    R2Area *area;

    r = func_001A6738(id);
    if (r == id) {
        which &= 1;
        cam = &D_00314840[r & 0xFF];
        rec = &cam->rec[which];
        rec->b1 = c;
        area = &rec->area[(r & 0xFF00) >> 8];
        if (which == 0) {
            cam = 0;
        } else {
            for (i = 0; i < 2; i++) {
                if (!((area->b07 >> (i + 3)) & 1)) {
                    cam->fadeD80[i].mode = 2;
                    cam->fadeD80[i].total = t0 + t1 + t2;
                    cam->fadeD80[i].time = 0;
                    cam->fadeD80[i].h4 = h4;
                    cam->fadeD80[i].t0 = t0;
                    cam->fadeD80[i].t1 = t1;
                    cam->fadeD80[i].t2 = t2;
                }
            }
        }
        for (i = 0; i < 3; i++) {
            if (!((area->b07 >> i) & 1)) {
                rec->fade[i].mode = 2;
                rec->fade[i].total = t0 + t1 + t2;
                rec->fade[i].time = 0;
                rec->fade[i].h4 = h4;
                rec->fade[i].t0 = t0;
                rec->fade[i].t1 = t1;
                rec->fade[i].t2 = t2;
            }
        }
        MsCameraSetStartPos(cam, rec, area);
        area->b07 = 0;
    }
}

void func_001A9860(int id, int which, float a, float b, float c, float d) {
    R2Area *area;

    if (MsCameraIDcheck(id)) {
        which &= 1;
        area = &D_00314870[id & 0xFF].rec[which].area[(id & 0xFF00) >> 8];
        area->v70[0] = a;
        area->v70[1] = b;
        area->v70[2] = c;
        area->v70[3] = d;
    }
}

void func_001A9918(int i, float x, float y, float z) {
    Unk317120Rec *r = &ms_camera_now->rec[i & 1];

    r->v90[0] = x;
    r->v90[1] = y;
    r->v90[2] = z;
}

void func_001A9948(int a, int i, float x, float y, float z) {
    if (func_001A6738(a) == a) {
        func_001A9918(i, x, y, z);
    }
}

void func_001A99D0(int id, int k, float a, float b, float c) {
    int r = func_001A6738(id);
    Unk317120Rec *p;
    if (r == id) {
        k &= 1;
        p = &D_00314870[r & 0xFF].rec[k];
        p->b3 = 1;
        p->f8 = b;
        p->fC = c;
        func_001AC258(a, p->v40, p->v20, p->w8C);
    }
}

void func_001A9A90(Unk317120Rec *o) {
    float tmp[4];

    func_001AC258(o->fC, tmp, o->v50, (int)o->v20); /* DEBT(CAST): third argument is a vector here, an int in func_001A99D0 */
    func_001AC3D0(o->v40, o->v40, tmp);
    if (o->f8 < func_001AC2D0(o->v40)) {
        func_001AC230((u8 *)o->v40, (u8 *)o->v40); /* DEBT(CAST): prototype takes u8 * */
        func_001ACB10(o->v40, o->f8);
    }
    func_001AC3D0(o->v50, o->v20, o->v40);
}

void func_001A9B38(int id, int which) {
    int r = func_001A6738(id);
    Unk317120Rec *p;

    if (r == id) {
        which &= 1;
        p = &D_00314870[r & 0xFF].rec[which];
        p->b3 = 0;
        p->v40[0] = 0.0f;
        p->v40[1] = 0.0f;
        p->v40[2] = 0.0f;
    }
}

void func_001A9BA8(s32 arg0, float fparg0, float fparg1, float fparg2, float fparg3, float fparg4, float fparg5) {
    Unk314840 *temp_2_2;
    s32 temp_2;

    temp_2 = func_001A6738(arg0);
    if (temp_2 == arg0) {
        temp_2_2 = &D_00314840[temp_2 & 0xFF];
        temp_2_2->fC92 = 1;
        temp_2_2->f20 = fparg3;
        temp_2_2->f24 = fparg4;
        temp_2_2->f28 = fparg5;
        temp_2_2->f10 = fparg0;
        temp_2_2->f14 = fparg1;
        temp_2_2->f18 = fparg2;
    }
}

void func_001A9C50(int a) {
    int r = func_001A6738(a);
    if (r == a) {
        Unk314840 *p = &D_00314840[(u8)r];
        p->fC92 = 0;
    }
}

int func_001A9C98(int a, int which)
{
    Unk314840 *state;
    Unk317120Rec *rec;
    R2Area *area;
    int ret = 0;
    int i;

    which &= 1;
    state = &D_00314840[a & 0xFF];
    rec = &state->rec[which];
    area = &rec->area[func_001A65E0(a & 0xFF)];
    /* DEBT(CAST): raw offset access into Unk314840/Unk317120Rec timer arrays */
    if (which == 1) {
        for (i = 0; i < 2; i++) {
            if (*(s16 *)((u8 *)state + (i << 4) + 0xD8C) != 0) {
                ret = 1;
                break;
            }
        }
    }
    for (i = 0; i < 3; i++) {
        if (*(s16 *)((u8 *)rec + (i << 4) + 0x58C) != 0) {
            ret = 1;
            break;
        }
    }
    if (*((u8 *)rec + 2) != 0) {
        ret |= 2;
    }
    if (area->b02 == 0xE) {
        ret |= 4;
    }
    return ret;
}

int MsCameraResetMove(int id, int which) {
    Unk314840 *cam;
    Unk317120Rec *rec;
    int flag;
    int i;

    if (func_001A6738(id) == id) {
        flag = which & 8;
        cam = &D_00314840[id & 0xFF];
        which &= 1;
        rec = &cam->rec[which];
        if (which == 1) {
            for (i = 0; i < 2; i++) {
                cam->fadeD80[i].total = 0;
            }
        }
        for (i = 0; i < 3; i++) {
            rec->fade[i].total = 0;
        }
        if (flag == 0) {
            MsCameraSetRect(id, which, rec->v50);
            if (which == 1) {
                MsCameraSetScrDpt(id, cam->fCA8);
                MsCameraSetRoll(id, cam->fC9C);
            }
        }
    }
    return 0;
}

void *func_001A9ED0(void) {
    return D_003142A0;
}

void func_001A9EE0(void *a0) {
    func_002DD0C0(a0, D_003142A0);
}

void func_001A9EF0(u32 id, int which, float *x, float *y, float *z) {
    Unk317120Rec *r = &D_00314870[id & 0xFF].rec[which & 1];

    if (x != 0) {
        *x = r->v20[0];
    }
    if (y != 0) {
        *y = r->v20[1];
    }
    if (z != 0) {
        *z = r->v20[2];
    }
}

void func_001A9F50(u32 id, int which, float *x, float *y, float *z) {
    Unk317120Rec *r = &D_00314870[id & 0xFF].rec[which & 1];

    if (x != 0) {
        *x = r->v10[0];
    }
    if (y != 0) {
        *y = r->v10[1];
    }
    if (z != 0) {
        *z = r->v10[2];
    }
}

float func_001A9FB0(void) {
    float v;

    MsVectorRect2Polar(ms_camera_now->rec[0].v20, ms_camera_now->rec[1].v20, &v, 0, 0);
    return v;
}

void MsCameraGetPosNow(int i, float *out) {
    Unk317120Rec *r = &ms_camera_now->rec[i & 1];

    if (out != 0) {
        out[0] = r->v20[0];
        out[1] = r->v20[1];
        out[2] = r->v20[2];
    }
}

float func_001AA028(void) {
    return ms_camera_now->fC98;
}

float MsCameraGetScrDpt(void) {
    return ms_camera_now->fCA4;
}

R2AreaObj *func_001AA048(int side)
{
    int screen = ms_screen_now->bC1;
    u8 *data = (u8 *)&D_00314840[screen];
    int area;

    side &= 1;
    area = func_001A65E0(screen);
    /* DEBT(CAST): byte-addressed lookup preserves the original address calculation. */
    side *= sizeof(Unk317120Rec);
    side += offsetof(Unk314840, rec);
    data += side;
    area *= sizeof(R2Area);
    area += (u32)data;
    return ((R2Area *)(area + offsetof(Unk317120Rec, area)))->obj;
}

extern s32 D_003142E0;
extern float D_0065FDC0;
extern s32 D_0065FDD0;
/* DEBT(CAST) */ /* DEBT(FAKE) */
void MsSetCameraMatrix(float f, s32 a, s32 b, s32 c, s32 d, s32 e) {
    s32 temp_4;
    register u_long128 *p __asm__("$2");
    register u_long128 q __asm__("$8");

    temp_4 = a & 1;
    D_003142E0 = temp_4;
    if (temp_4 != 0) {
        func_002DD0C0(D_00314260, (void *) b);
        func_002DD0C0(D_003142A0, (void *) c);
        p = (u_long128 *)&D_0065FDD0;
        __asm__ volatile("" : "+r"(p) : : "memory");
        q = *(u_long128 *)d;
        __asm__("" : "+r"(q));
        *p = q;
        p++;
        __asm__ volatile("" : "+r"(p) : : "memory");
        q = *(u_long128 *)e;
        __asm__("" : "+r"(q));
        *p = q;
        __asm__ volatile("" : : : "memory");
        D_0065FDC0 = f;
        __asm__("" : : "r"(p));
    }
}

void func_001AA150(int a, int b) {
    if (func_001A6738(a) == a) {
        Sg_Blur(b);
    }
}

void func_001AA198(int a, int b, int c) {
    MsVectorRect2Polar(ms_camera_now->rec[0].v20, ms_camera_now->rec[1].v20, a, b, c);
}

void MsSetNormalUpVector(Vec4 *p) {
    if (p != 0) {
        p->x = 0;
        p->y = -1.0f;
        p->z = 0;
        p->w = 1.0f;
    }
}

extern char D_0056DEE8[];
int func_001A9C98(int a, int b);

int MsCameraReset(int id, int which) {
    int cur;
    Unk314840 *cam;
    Unk317120Rec *rec;
    struct Unk314840Ent *ent;
    R2Area *area;

    func_002EF240(D_0056DEE8, which, func_001A6738(id), id, func_001A9C98(id, which));
    cur = func_001A6738(id);
    if (cur == id) {
        int k = (cur & 0xFF00) >> 8;

        cam = &D_00314840[cur & 0xFF];
        rec = &cam->rec[which];
        ent = &cam->eCC0[k];
        area = &rec->area[k];
        MMI_COPY_LQ_T0(rec->v20, area->pad_80);
        MMI_COPY_SQ_T0(rec->v20);
        MMI_COPY_LQ_T0(rec->v50, area->pad_80);
        MMI_COPY_SQ_T0(rec->v50);
        if (which == 1) {
            cam->fC9C = *(float *)&ent->pad1C[0];
            ((Unk317120 *)cam)->fC98 = *(float *)&ent->pad1C[0];
            cam->fCA8 = *(float *)&ent->pad1C[4];
            ((Unk317120 *)cam)->fCA4 = *(float *)&ent->pad1C[4];
        }
    }
    return 0;
}

void MsEffectCameraInit(void) {
    ms_effect_camera_flag = 0;
    D_00317128 = 1024.0f;
    D_0065FDF0 = 0;
    MMI_SQ_ZERO(0x0, &D_0065FE10);
    MMI_SQ_ZERO(0x0, &D_0065FE00);
    MMI_SQ_ZERO(0x0, &D_0065FE20);
    D_0065FE20.f[1] = -1.0f;
}

extern float _m2c_func_001AA360_D_00317128 __asm__("D_00317128");
extern float _m2c_func_001AA360_D_0065FDF0 __asm__("D_0065FDF0");
extern u_long128 _m2c_func_001AA360_D_0065FE00 __asm__("D_0065FE00");
extern u_long128 _m2c_func_001AA360_D_0065FE10 __asm__("D_0065FE10");
extern s32 _m2c_func_001AA360_ms_effect_camera_flag __asm__("ms_effect_camera_flag");
/* DEBT(FAKE) */
void func_001AA360(u_long128 *arg0, u_long128 *arg1, float fparg0, float fparg1) {
    register u_long128 t0 __asm__("$8");
    u_long128 *p;
    _m2c_func_001AA360_ms_effect_camera_flag = 1;
    if (arg0 != 0) {
        p = &_m2c_func_001AA360_D_0065FE10;
        __asm__ volatile("" : "+r"(p));
        t0 = *arg0;
        *p = t0;
    }
    if (arg1 != 0) {
        p = &_m2c_func_001AA360_D_0065FE00;
        __asm__ volatile("" : "+r"(p));
        t0 = *arg1;
        *p = t0;
    }
    _m2c_func_001AA360_D_00317128 = fparg0;
    _m2c_func_001AA360_D_0065FDF0 = fparg1;
}

void func_001AA3A8(void) {
    ms_effect_camera_flag = 0;
}

INCLUDE_ASM("build/ee_asm/game/battle/ms_1A56F8", MsScreenProcess);

void MsSetScreenInfo(u32 idx, int a, int b) {
    if (idx < 3) {
        ms_screen[idx].fC0 = a;
        ms_screen[idx].fC1 = b;
    }
}

void func_001AA850(u32 i, int v) {
    if (i < 3) {
        ms_screen[i].fC0 = v;
    }
}

void func_001AA878(u32 i, int v) {
    if (i < 3) {
        ms_screen[i].fC1 = v;
    }
}

void MsSetScreenData(u32 idx, int a1, int a2, int a3, int a4, int a5) {
    if (idx < 3) {
        Rec142F0 *p = &ms_screen[idx];

        p->f80[0][0] = a1;
        p->f80[0][1] = a2;
        p->f80[0][2] = a3;
        p->f80[0][3] = a4;
        MMI_COPY_LQ_T0(p->f40[0], p->f80[0]);
        MMI_COPY_SQ_T0(p->f40[0]);
        ((R2Cam30 *)p)->wC4 = a5;
    }
}

void MsSetDrawData(u32 idx, int a1, int a2, int a3, int a4) {
    if (idx < 3) {
        Rec142F0 *p = &ms_screen[idx];

        p->f80[1][0] = a1;
        p->f80[1][1] = a2;
        p->f80[1][2] = a3;
        p->f80[1][3] = a4;
        MMI_COPY_LQ_T0(p->f40[1], p->f80[1]);
        MMI_COPY_SQ_T0(p->f40[1]);
    }
}

int MsGetScreenData(int *a, int *b, int *c, int *d) {
    if (a != 0) {
        *a = ms_screen_now->f40;
    }
    if (b != 0) {
        *b = ms_screen_now->f44;
    }
    if (c != 0) {
        *c = ms_screen_now->f48;
    }
    if (d != 0) {
        *d = ms_screen_now->f4C;
    }
    return ms_screen_now->wC4;
}

void func_001AA9D0(int *a, int *b, int *c, int *d) {
    if (a) {
        *a = ms_screen_now->f50;
    }
    if (b) {
        *b = ms_screen_now->f54;
    }
    if (c) {
        *c = ms_screen_now->f58;
    }
    if (d) {
        *d = ms_screen_now->f5C;
    }
}

void func_001AAA38(u32 idx, int b) {
    if (idx < 3) {
        Rec142F0 *p = &ms_screen[idx];
        struct Rec142F0Slot *s;
        int i;

        b &= 1;
        s = p->sl[b];
        for (i = 0; i < 4; i++) {
            s[i].h0 = 0;
            s[i].hC = 0;
            s[i].hE = 0;
            p->f80[b][i] = p->f40[b][i];
        }
    }
}

int func_001AAAB0(u32 idx, int b) {
    Rec142F0 *p;
    struct Rec142F0Slot *s;
    int r = 0;
    int i;

    if (idx < 3) {
        b &= 1;
        p = &ms_screen[idx];
        s = p->sl[b];
        for (i = 0; i < 4; i++) {
            if (s[i].hC != 0) {
                r++;
            }
        }
    }
    return r;
}

void func_001AAB10(u32 idx, int b, int c, int d) {
    if (idx < 3) {
        Rec142F0 *p = &ms_screen[idx];
        struct Rec142F0Slot *s;
        int i;

        b &= 1;
        s = p->sl[b];
        for (i = 0; i < 4; i++) {
            s[i].h0 = d;
            s[i].hC = c;
            s[i].hE = 0;
        }
        MMI_COPY_LQ_T0(((float (*)[4])p->padA0)[b], p->f40[b]);
        MMI_COPY_SQ_T0(((float (*)[4])p->padA0)[b]);
    }
}

void func_001AAB88(u32 idx, int b, int t0, int t1, int t2) {
    if (idx < 3) {
        Rec142F0 *p = &ms_screen[idx];
        R2Fade *s;
        int i;

        b &= 1;
        s = (R2Fade *)p->sl[b];
        for (i = 0; i < 4; i++) {
            s[i].mode = 2;
            s[i].total = t0 + t1 + t2;
            s[i].time = 0;
            s[i].h4 = 0;
            s[i].t0 = t0;
            s[i].t1 = t1;
            s[i].t2 = t2;
        }
        MMI_COPY_LQ_T0(((float (*)[4])p->padA0)[b], p->f40[b]);
        MMI_COPY_SQ_T0(((float (*)[4])p->padA0)[b]);
    }
}

void func_001AAC18(float a, float b) {
    ms_screen_now->f30 = a;
    ms_screen_now->f34 = b;
}

void func_001AAC30(int a, float x, float y) {
    if (func_001A6738(a) == a) {
        func_001AAC18(x, y);
    }
}

void *MsGetScreenMatrix(void) {
    return D_00314260;
}

void func_001AACA0(void *a0) {
    func_002DD0C0(a0, D_00314260);
}

/* DEBT(CAST) */
void MsSetScreen(s32 arg0, float fparg0, float fparg1, float fparg2, float fparg3, float fparg4, float fparg5, float fparg6, float fparg7, float arg_sp0) {
    Rec142F0 *temp_2;
    float temp_f1;

    if (arg0 < 3) {
        temp_2 = &ms_screen[arg0];
        (*(float *)((u8 *)(temp_2) + (0))) = fparg5;
        (*(float *)((u8 *)(temp_2) + (4))) = fparg6;
        temp_2->f08 = fparg7;
        temp_f1 = -fparg7 + arg_sp0;
        (*(float *)((u8 *)(temp_2) + (0x28))) = (float) (((-fparg6 * fparg7) + (fparg5 * arg_sp0)) / temp_f1);
        (*(float *)((u8 *)(temp_2) + (0x18))) = (float) ((arg_sp0 * fparg7 * (-fparg5 + fparg6)) / temp_f1);
        temp_2->f1C = fparg0;
        temp_2->f10 = fparg1;
        temp_2->f14 = fparg2;
        (*(float *)((u8 *)(temp_2) + (0x20))) = fparg3;
        (*(float *)((u8 *)(temp_2) + (0x24))) = fparg4;
        temp_2->f0C = arg_sp0;
    }
}

void func_001AAD48(u32 idx, int i, int v) {
    if (idx < 3) {
        ms_screen[idx].fC2[i] = v;
    }
}

void func_001AAD78(void) {
    int i;
    for (i = 0; i < 3; i++) {
        ms_screen[i].fD0 = -1;
    }
}

void MsScreenFocusResetAll(void) {
    int i;
    for (i = 0; i < 3; i++) {
        ms_screen[i].fD0 = -1;
    }
    Sg_EnFocus(0);
}

int MsGetChrBit(int a, int b, int c, int d);
int MsCamSetBtl(u32 h, int mode, void *rec_p, void *area_p, void *other_rec_p, void *other_area_p);

void MsCameraSetBtl(u32 h, int which, int a2, int mode, int a4, int a5, float f0, float f1, float f2, float f3) {
    if (MsCameraIDcheck(h) != 0) {
        int sub = (int)(h & 0xFF00) >> 8;
        int idx;
        int ow;
        Unk317120Rec *rec;
        Unk317120Rec *other_rec;
        u8 *area;
        u8 *other_area;

        which &= 1;
        ow = (which == 0) ? 1 : 0;
        idx = h & 0xFF;
        rec = &D_00314870[idx].rec[which];
        other_rec = &D_00314870[idx].rec[ow];
        area = (u8 *)&rec->area[sub];
        other_area = (u8 *)&other_rec->area[sub];

        area[0] = 0;
        switch (mode) {
        case 0:
            area[2] = 0xB;
            break;
        case 1:
            area[2] = 0xC;
            break;
        case 2:
            area[2] = 0xD;
            break;
        case 3:
            area[2] = 0xF;
            area[0] = 1;
            break;
        case 4:
            area[2] = 0x10;
            area[0] = 1;
            break;
        }
        *(u16 *)(area + 0x10) = a4;
        *(u16 *)(area + 0x12) = a5;
        if (((h >> 16) & 0xF) == 5) {
            *(s32 *)(area + 0x14) = MsGetChrBit(a2, a4, 1, 1);
            *(s32 *)(area + 0x18) = MsGetChrBit(a2, a5, 1, 1);
        } else {
            *(s32 *)(area + 0x14) = a4;
            *(s32 *)(area + 0x18) = a5;
        }
        *(float *)(area + 0x5C) = f0;
        if (mode != 0) {
            *(float *)(area + 0x40) = f1;
            *(float *)(area + 0x44) = f2;
            *(float *)(area + 0x60) = f3;
        }
        *(float *)(area + 0x30) = *(float *)((u8 *)other_rec + 0x30);
        *(float *)(area + 0x34) = *(float *)((u8 *)other_rec + 0x34);
        *(float *)(area + 0x38) = *(float *)((u8 *)other_rec + 0x38);
        area[6] = 1;
        *(float *)(area + 0x64) = 0.0f;
        if (func_001A6738(h) == h) {
            MsCamSetBtl(h, mode, rec, area, other_rec, other_area);
            MsSetCheckChange(h, which, 0, 0);
        }
    }
}

int MsGetChrInfo(int type, int bit, int id, float *out);

int MsCamSetBtl(u32 h, int mode, void *rec_p, void *area_p, void *other_rec_p, void *other_area_p) {
    u8 *rec = (u8 *)rec_p;
    u8 *area = (u8 *)area_p;
    u8 *other_rec = (u8 *)other_rec_p;
    u8 *other_area = (u8 *)other_area_p;
    float sum_pos[4];
    float pos[2][4];
    float tmp[4];
    float ang;
    float sum_h;
    float sum_w;
    int cnt;
    int flag;
    float *src;
    float *dst;
    s16 *p10;
    s32 *p14;
    int i;

    if (((s8 *)other_area)[0] == 1) {
        func_001AC750((float *)(other_rec + 0x50), *(void **)(other_rec + 0x8C), *(float *)(other_rec + 0x60), *(float *)(other_rec + 0x64), *(float *)(other_rec + 0x68));
    }
    flag = 0x100;
    if (((h >> 16) & 0xF) == 5) {
        flag = 0;
    }
    cnt = 0;
    sum_w = 0.0f;
    sum_h = 0.0f;
    ang = 0.0f;
    dst = (float *)(rec + 0x50);
    src = (float *)(area + 0x30);
    p10 = (s16 *)(area + 0x10);
    p14 = (s32 *)(area + 0x14);
    for (i = 3; i >= 0; i--) {
        sum_pos[i] = 0.0f;
    }
    for (i = 0; i < 2; i++) {
        int id = p10[i];
        int bit = p14[i];
        if (id != -1) {
            float *p = pos[i];
            if (MsGetChrInfo(flag | 9, bit, id, p) > 0) {
                cnt++;
                sum_pos[0] += p[0];
                sum_pos[1] += p[1];
                sum_pos[2] += p[2];
                MsGetChrInfo(flag | 0xA, bit, id, tmp);
                sum_h += tmp[0];
                MsGetChrInfo(flag | 7, bit, id, tmp);
                ang += tmp[0];
                MsGetChrInfo(flag | 0xB, bit, id, tmp);
                sum_w += tmp[0];
            }
        }
    }
    if (cnt > 0) {
        for (i = 0; i < 3; i++) {
            sum_pos[i] /= (float)cnt;
        }
        sum_w /= (float)cnt;
        sum_h /= (float)cnt;
        ang /= (float)cnt;
        for (i = 0; i < 3; i++) {
            dst[i] = sum_pos[i];
        }
        *(float *)(rec + 0x54) -= sum_h * *(float *)(area + 0x5C);
        if (mode != 0) {
            int ok = -1;
            if (cnt >= 2 && *(s32 *)(area + 0x14) != *(s32 *)(area + 0x18)) {
                MsVectorRect2Polar(pos[0], pos[1], &ang, 0, 0);
                ok = 0;
            }
            if (ok < 0 && other_area[2] == 0xC) {
                if ((*(u32 *)(area + 0x14) | *(u32 *)(area + 0x18)) == (*(u32 *)(other_area + 0x14) | *(u32 *)(other_area + 0x18))) {
                    ok = 1;
                }
            }
            if (flag != 0 && ok < 0 && ((s8 *)rec)[0] != 0) {
                if (*(float *)(rec + 0x50) != *(float *)(other_rec + 0x50) || *(float *)(rec + 0x58) != *(float *)(other_rec + 0x58)) {
                    MsVectorRect2Polar(dst, (float *)(other_rec + 0x50), &ang, 0, 0);
                    ok = 0;
                }
            }
            if (ok != 0 && flag != 0) {
                if (((s8 *)area)[6] != 0) {
                    area[6] = 0;
                    *(float *)(area + 0x64) = ang;
                } else {
                    ang = *(float *)(area + 0x64);
                }
            }
            if (mode == 2 || mode == 4) {
                sum_w += *(float *)(area + 0x60) * 10.0f;
            } else {
                sum_w *= *(float *)(area + 0x60);
            }
            if (((s8 *)area)[0] == 0) {
                func_001AC750(sum_pos, 0, *(float *)(area + 0x40) + ang, *(float *)(area + 0x44), sum_w);
                for (i = 0; i < 3; i++) {
                    dst[i] += sum_pos[i];
                }
            } else {
                *(float *)(rec + 0x60) = *(float *)(area + 0x40) + ang;
                *(float *)(rec + 0x64) = *(float *)(area + 0x44);
                *(float *)(rec + 0x68) = sum_w;
                func_001AC750(dst, *(void **)(rec + 0x8C), *(float *)(rec + 0x60), *(float *)(rec + 0x64), *(float *)(rec + 0x68));
            }
        }
        for (i = 0; i < 3; i++) {
            src[i] = dst[i];
        }
    } else {
        for (i = 0; i < 3; i++) {
            dst[i] = src[i];
        }
    }
    *(s32 *)(rec + 0x6C) = 0;
    return cnt;
}

typedef struct {
    u8 pad0[0xA0];
    s32 wA0[4];
    float fB0[4];
    u8 padC0[0x5B0 - 0xC0];
    struct CamRecShakeEnt {
        s8 b0;
        s8 b1;
        s16 h2;
        s16 h4;
        s16 h6;
        s32 w8;
        u8 padC[0x24 - 0xC];
    } e5B0[3];
    u8 pad61C[0x620 - 0x61C];
} CamRecShake;

void func_001AB568(int id, int which, int mask, int a, float f, int b, int c, int d) {
    int cur = func_001A6738(id);
    if (cur == id) {
        Unk314840 *u = &D_00314840[cur & 0xFF];
        CamRecShake *r;
        int i;
        which &= 1;
        r = (CamRecShake *)&u->rec[which];
        for (i = 0; i < 3; i++) {
            if ((mask >> i) & 1) {
                struct CamRecShakeEnt *e = &r->e5B0[i];
                e->b0 = a;
                e->b1 = d;
                e->w8 = 0;
                e->h2 = c;
                e->h4 = b;
                e->h6 = b;
                r->wA0[i] = 0;
                r->fB0[i] = f;
            }
        }
    }
}

typedef struct {
    u8 pad0[0x15C];
    s32 w15C[2];
    float f164[2];
    struct Rec142F0ShakeEnt {
        s8 b0;
        s8 b1;
        s16 h2;
        s16 h4;
        s16 h6;
        s32 w8;
        float fC;
        s32 w10;
        float f14;
        float f18;
        float f1C;
        s8 b20;
        s8 b21;
        s16 h22;
    } e16C[2];
    u8 pad1B4[0x1C0 - 0x1B4];
} Rec142F0Shake;

void func_001AB668(u32 idx, int mask, int a, float f, int b, int c, int d) {
    if (idx < 3) {
        Rec142F0Shake *r = &((Rec142F0Shake *)ms_screen)[idx];
        int i;
        for (i = 0; i < 2; i++) {
            if ((mask >> i) & 1) {
                struct Rec142F0ShakeEnt *e = &r->e16C[i];
                e->b0 = a;
                e->b1 = d;
                e->w8 = 0;
                e->h2 = c;
                e->h4 = b;
                e->h6 = b;
                r->w15C[i] = 0;
                r->f164[i] = f;
            }
        }
    }
}

void func_001AB6D8(u32 idx, int mask, int a, int b, int c, float f1, int d, float f2, int e_arg) {
    if (idx < 3 && c != 0) {
        Rec142F0Shake *r = &((Rec142F0Shake *)ms_screen)[idx];
        int i;
        for (i = 0; i < 2; i++) {
            if ((mask >> i) & 1) {
                struct Rec142F0ShakeEnt *e = &r->e16C[i];
                e->b20 = b;
                e->b0 = a;
                e->h4 = c;
                e->h6 = c;
                e->w10 = 0;
                e->fC = f1;
                e->h22 = d;
                e->f1C = f2;
                if (d < 0) {
                    f1 = -f1;
                    d = -d;
                }
                if (d != 0) {
                    float scale = 0x100 - (brnd(9) % d);
                    f1 = f1 * scale * 0.00390625f;
                    f2 = f2 * scale * 0.00390625f;
                }
                e->f14 = f1;
                e->f18 = f2;
                e->b21 = e_arg;
            }
        }
    }
}

typedef struct {
    u8 mode;
    u8 rnd;
    u16 amp;
    s16 timer;
    s16 total;
    float prev;
    float fC;
    float pos;
    float vel;
    float acc;
    float f1C;
    u8 steps;
    u8 decay;
    s16 h22;
} ShakeParam;

double func_002E7B28(double);

void func_001AB838(ShakeParam *s, float *out, float t) {
    int r;
    float v;

    if (s->mode == 0) {
        return;
    }
    if (s->rnd != 0) {
        int m = brnd(9) % s->rnd;
        r = (s->rnd >> 1) - m;
    } else {
        r = 0;
    }
    switch (s->mode) {
    case 1:
        v = func_002E89C0(t) * s->amp * (r + 32) * 0.03125f;
        if (s->total != 0) {
            *out = (v * s->timer) / s->total;
            if (--s->timer < 0) {
                s->mode = 0;
                *out = 0.0f;
            }
        }
        break;
    case 2:
        v = func_002E89C0(t) * s->amp * (r + 32) * 0.03125f;
        if (s->total != 0) {
            *out = (v * (s->total - s->timer)) / s->total;
            if (--s->timer < 0) {
                s->mode = 0;
                *out = 0.0f;
            }
        }
        break;
    case 3:
        v = (func_002E89C0(t) + func_002E8648(t + 0.3)) * 0.5f * s->amp * (r + 32) * 0.03125f;
        if (s->total != 0) {
            *out = (v * s->timer) / s->total;
            if (--s->timer < 0) {
                s->mode = 0;
                *out = 0.0f;
            }
        }
        break;
    case 4:
        v = (func_002E89C0(t) + func_002E8648(t + 0.3)) * 0.5f * s->amp * (r + 32) * 0.03125f;
        if (s->total != 0) {
            *out = (v * (s->total - s->timer)) / s->total;
            if (--s->timer < 0) {
                s->mode = 0;
                *out = 0.0f;
            }
        }
        break;
    case 5: {
        int k = brnd(9) & 0xF;
        v = (func_002E89C0(t) + func_002E8648(t + 0.1)) * 0.5f * s->amp * (r + 32) * 0.03125f;
        if (s->total != 0) {
            if ((s->timer & 1) || k == 0) {
                v = s->prev * 0.5f;
            }
            *out = (v * s->timer) / s->total;
            s->prev = v;
            if (--s->timer < 0) {
                s->mode = 0;
                *out = 0.0f;
            }
        }
        break;
    }
    case 6: {
        int k = brnd(9) & 0xF;
        v = (func_002E89C0(t) + func_002E8648(t + 0.1)) * 0.5f * s->amp * (r + 32) * 0.03125f;
        if (s->total != 0) {
            if ((s->timer & 1) || k == 0) {
                v = s->prev * 0.5f;
            }
            *out = (v * (s->total - s->timer)) / s->total;
            s->prev = v;
            if (--s->timer < 0) {
                s->mode = 0;
                *out = 0.0f;
            }
        }
        break;
    }
    case 7:
        v = func_002E89C0(t) * s->amp * (r + 32) * 0.03125f;
        if (s->total != 0) {
            *out = v;
            if (--s->timer < 0 && s->total > 0) {
                s->mode = 0;
                *out = 0.0f;
            }
        }
        break;
    case 8: {
        double d = func_002E89C0(t);
        v = (d + func_002E7B28(t + 0.1)) * 0.5f * s->amp * (r + 32) * 0.03125f;
        if (s->total != 0) {
            *out = v;
            if (--s->timer < 0 && s->total > 0) {
                s->mode = 0;
                *out = 0.0f;
            }
        }
        break;
    }
    case 9:
        if (s->total != 0) {
            int i;
            for (i = 0; i < s->steps; i++) {
                float a = s->acc;
                s->pos += s->vel;
                if (s->pos > 0.0) {
                    a = -a;
                }
                s->vel += a;
            }
            v = s->pos;
            switch (s->decay) {
            case 1:
                v = (v * s->timer) / s->total;
                break;
            case 2:
                v = (v * (s->total - s->timer)) / s->total;
                break;
            }
            *out = v;
            if (--s->timer < 0 && s->total > 0) {
                s->mode = 0;
                *out = 0.0f;
            }
        }
        break;
    }
}

void func_001ABFD8(int h, int which) {
    int cur = func_001A6738(h);
    if (cur == h) {
        int i;
        Unk314840 *u = &D_00314840[cur & 0xFF];
        Unk317120Rec *r;
        which &= 1;
        r = &u->rec[which];
        for (i = 0; i < 3; i++) {
            r->e5B0[i].on = 0;
            r->v90[i] = 0.0f;
        }
    }
}

void MsScreenResetShake(u32 i) {
    int j;
    Rec142F0 *r;

    if (i < 3) {
        r = &ms_screen[i];
        for (j = 0; j < 2; j++) {
            r->e16C[j].b = 0;
            r->w30[j] = 0;
        }
    }
}
