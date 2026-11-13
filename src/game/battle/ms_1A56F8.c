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

INCLUDE_ASM("build/ee_asm/game/battle/ms_1A56F8", MsCameraInit);

INCLUDE_ASM("build/ee_asm/game/battle/ms_1A56F8", MsCameraProcess);
INCLUDE_RODATA("build/ee_asm/game/battle/ms_1A56F8/rodata", jtbl_0056DE80);

INCLUDE_ASM("build/ee_asm/game/battle/ms_1A56F8", MsNearRag);

INCLUDE_ASM("build/ee_asm/game/battle/ms_1A56F8", MsCameraMoveCalc);

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

INCLUDE_ASM("build/ee_asm/game/battle/ms_1A56F8", MsSetCheckChange);

void func_001A6E10(int a, int b, int v) {
    if (MsCameraIDcheck(a)) {
        Unk317120Rec *r;

        b &= 1;
        r = &D_00314870[a & 0xFF].rec[b];

        ((S2CamEnt *)r)[(a & 0xFF00) >> 8].fC7 = v; /* DEBT(CAST): five 0x130-byte entries overlay the record */
    }
}

INCLUDE_ASM("build/ee_asm/game/battle/ms_1A56F8", func_001A6E90);

INCLUDE_ASM("build/ee_asm/game/battle/ms_1A56F8", func_001A6FA0);

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

INCLUDE_ASM("build/ee_asm/game/battle/ms_1A56F8", func_001A7308);

INCLUDE_ASM("build/ee_asm/game/battle/ms_1A56F8", func_001A7530);

INCLUDE_ASM("build/ee_asm/game/battle/ms_1A56F8", func_001A7648);

INCLUDE_ASM("build/ee_asm/game/battle/ms_1A56F8", func_001A76E0);

INCLUDE_ASM("build/ee_asm/game/battle/ms_1A56F8", MsCameraSetRect);

INCLUDE_ASM("build/ee_asm/game/battle/ms_1A56F8", MsCameraSetAct);

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

INCLUDE_ASM("build/ee_asm/game/battle/ms_1A56F8", func_001A7BC0);

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

INCLUDE_ASM("build/ee_asm/game/battle/ms_1A56F8", func_001A7E00);

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

INCLUDE_ASM("build/ee_asm/game/battle/ms_1A56F8", func_001A83F0);

INCLUDE_ASM("build/ee_asm/game/battle/ms_1A56F8", func_001A8518);

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

INCLUDE_ASM("build/ee_asm/game/battle/ms_1A56F8", func_001A89F8);

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

INCLUDE_ASM("build/ee_asm/game/battle/ms_1A56F8", func_001A9040);
INCLUDE_RODATA("build/ee_asm/game/battle/ms_1A56F8/rodata", jtbl_0056DED0);

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

INCLUDE_ASM("build/ee_asm/game/battle/ms_1A56F8", func_001A9C98);

INCLUDE_ASM("build/ee_asm/game/battle/ms_1A56F8", MsCameraResetMove);

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

INCLUDE_ASM("build/ee_asm/game/battle/ms_1A56F8", func_001AA048);

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

INCLUDE_ASM("build/ee_asm/game/battle/ms_1A56F8", MsCameraReset);

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

INCLUDE_ASM("build/ee_asm/game/battle/ms_1A56F8", MsSetScreenData);

INCLUDE_ASM("build/ee_asm/game/battle/ms_1A56F8", MsSetDrawData);

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

INCLUDE_ASM("build/ee_asm/game/battle/ms_1A56F8", func_001AAB10);

INCLUDE_ASM("build/ee_asm/game/battle/ms_1A56F8", func_001AAB88);

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

INCLUDE_ASM("build/ee_asm/game/battle/ms_1A56F8", MsCameraSetBtl);
INCLUDE_RODATA("build/ee_asm/game/battle/ms_1A56F8/rodata", jtbl_0056DF10);

INCLUDE_ASM("build/ee_asm/game/battle/ms_1A56F8", MsCamSetBtl);

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

INCLUDE_ASM("build/ee_asm/game/battle/ms_1A56F8", func_001AB838);
INCLUDE_RODATA("build/ee_asm/game/battle/ms_1A56F8/rodata", jtbl_0056DF30);

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
