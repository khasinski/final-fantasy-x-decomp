/* tu_317 0x29a8a8-0x29dc40: low; ~opu (config/tu_map.tsv) */
/* Module guess: event-script VM / field-event runtime (no __FILE__ string found for this range). */
#define MsCameraSetScrDpt _hdr_MsCameraSetScrDpt
#include "common.h"
#include "vu0.h"
#include "ffx/r6.h"
#include "ffx/w9.h"
#include "ffx/q6.h"
#include "ffx/v6.h"
#include "ffx/g4.h"
#include "ffx/s6.h"
#include "ffx/t6.h"
#include "ffx/q7.h"
#undef MsCameraSetScrDpt
void MsCameraSetScrDpt(int h, float a);

void opu_test_data_read(void)
{
    u8 *hw = (u8 *)&D_2008250;

    if (D_007649A0 != 0) {
        if (*(u16 *)(hw + 0x40) & 0x20) {
            ((void (*)(int))func_002975B0)(*(int *)(hw + 0x98));
            op_file_read(hw + 0xB00, *(int *)(hw + 0x98));
            op_oef2_set2(*(void **)(hw + 0x98));
            op_file_read(hw + 0xC00, *(int *)(hw + 0x9C));
            op_oef2_set(*(void **)(hw + 0x98), *(void **)(hw + 0x9C));
        }
        if (*(u16 *)(hw + 0x40) & 0x1) {
            op_file_read(hw + 0x100, *(int *)(hw + 0x80));
            op_oef2_set2(*(void **)(hw + 0x80));
            op_file_read(hw + 0x200, *(int *)(hw + 0x84));
            op_oef2_set(*(void **)(hw + 0x80), *(void **)(hw + 0x84));
        }
        if (*(u16 *)(hw + 0x40) & 0x2) {
            op_et_monster_free(*(void **)(hw + 0x88));
            op_file_read(hw + 0x300, *(int *)(hw + 0x88));
            op_oef2_set2(*(void **)(hw + 0x88));
            if (*(int *)(hw + 0x8C) != 0) {
                op_file_read(hw + 0x400, *(int *)(hw + 0x8C));
                op_oef2_set(*(void **)(hw + 0x88), *(void **)(hw + 0x8C));
            }
        }
        if (*(u16 *)(hw + 0x40) & 0x4) {
            op_et_weapon_free(*(int *)(hw + 0x88));
            op_file_read(hw + 0x500, *(int *)(hw + 0x90));
            op_oef2_set2(*(void **)(hw + 0x90));
            if (*(int *)(hw + 0x94) != 0) {
                op_file_read(hw + 0x600, *(int *)(hw + 0x94));
                op_oef2_set(*(void **)(hw + 0x90), *(void **)(hw + 0x94));
            }
        }
        if (*(u16 *)(hw + 0x40) & 0x10) {
            op_file_read(hw + 0x900, *(int *)(hw + 0xA8));
            op_oef2_set2(*(void **)(hw + 0xA8));
            op_file_read(hw + 0xA00, *(int *)(hw + 0xAC));
            op_oef2_set(*(void **)(hw + 0xA8), *(void **)(hw + 0xAC));
        }
    }
}

void func_206A6B0(void);
void func_2069D88(void);
void op_oef2_tex_clut_ovl_clear(u32 mask);
void func_002B22F8(s32, s32);
int func_0029B560(void);
Chr *opd_target_handle_by_index();
void opd_camera_change(int a);
double func_002E9290(double a);
double func_002ED038(float a);
double func_002E8278(double a);
double func_002E7B28(double a);
extern u32 D_00551CBC;
extern float D_0054B7D0;
extern float D_0054B7D4;
extern s32 D_0054B7D8;
extern R6Vec3 D_0054B780;
extern R6Vec3 D_0054B790;

typedef struct {
    u8 b0;
    s8 b1;
    u8 pad2[4];
    s16 h6;
    u16 h8;
    u16 hA;
    u8 bC;
    u8 padD;
    s8 bE;
    u8 padF;
    s8 b10;
    u8 pad11[4];
    s8 b15;
    u8 pad16[2];
    s32 w18;
    u8 pad1C[0x18];
    s32 w34;
    u8 pad38[6];
    s8 b3E;
    s8 b3F;
    s32 w40;
    u8 pad44;
    s8 b45;
} OpDbg;
#define DBG (*(OpDbg *)&D_00764990)

void opu_debug_check(void)
{
    u8 *hw = (u8 *)&D_2008250;
    u32 *pad;
    s32 flag;
    s32 reload;
    s32 mode;
    R6Obj *obj0;
    R6Obj *obj1;
    u32 p2;
    u32 p3;
    s32 i;
    s16 speed;
    s32 pause_and;

    if (DBG.b10 == 0) {
        return;
    }

    flag = 0;
    pad = &D_00551CBC;
    if ((pad[0] & 0x8) && (pad[2] & 0x2) && *(s8 *)(hw + 0x8) != 0) {
        if (DBG.b3F != 0) {
            DBG.b3F = 0;
            func_00124690(1);
        } else {
            DBG.b3F = 1;
            func_00124690(0);
        }
    }

    if (DBG.b3F == 0) {
        return;
    }

    if (pad[0] & 0x20 && pad[2] & 0x40) {
        func_206A6B0();
        goto tail;
    }

    mode = 0;
    reload = 0;
    if (*(u16 *)(hw + 0x40) & 0x10) {
        mode = 1;
    }
    obj0 = D_0054D5E8[0];
    obj1 = D_0054D5E8[1];
    if (obj0 == 0) {
        return;
    }

    if (!(pad[0] & 0x30)) {
        if (pad[0] & 0x800) {
            if (pad[2] & 0x100) {
                obj0->vt50->f50(0);
                if (obj1 != 0) {
                    obj1->vt50->f50(0);
                }
                ((void (*)(int))opu_test_data_read)(mode);
                if (*(s8 *)(hw + 0x4) != 0) {
                    reload = 1;
                }
                goto do_reload;
            }
        } else if (pad[2] & 0x100) {
            reload = 1;
do_reload:
            func_206C380();
            flag = 1;
            ((void (*)(R6Obj *))func_0029B808)(obj0);
            func_2069D88();
            op_oef2_tex_clut_ovl_clear(0xFFFFFFFFU);
            if (*(u16 *)(hw + 0x40) & 0x10) {
                func_002B22F8(0x3400, 0x800);
            }
            DBG.b0 = 0;
            DBG.b1 = 0;
            DBG.hA = 0;
            DBG.w40 = 0;
            {
                u8 *cs = (u8 *)owu_chr_status;
                for (i = 0; i < 0xF0; i++, cs += 0x20) {
                    cs[0x14] = 0xFF;
                    cs[0x15] = 0xFF;
                }
            }
            {
                int h0 = *(int *)&D_00703E20;
                opu_et_init();
                obj0 = D_0054D5E8[0];
                *(void **)((u8 *)obj0 + 0x50) = D_003737A0;
                op_et_battle_init(h0);
                func_00297578(*(int *)((u8 *)&D_00703E20 + 8));
            }
            if (!(*(u16 *)(hw + 0x40) & 0xFE) && (*(u16 *)(hw + 0x40) & 0x1) && reload != 0) {
                ((void (*)(int, int, int, int))opu_et_unit)(*(int *)&D_00703E20, 0, *(int *)(hw + 0xB0), -2);
            }
            if ((*(u16 *)(hw + 0x40) & 0x20) && reload != 0 && *(int *)(hw + 0xBC) != 0) {
                ((void (*)(int, int, int, int))opu_et_unit)(*(int *)(hw + 0x98), 0, *(int *)(hw + 0xBC), -3);
            }
            if (*(u16 *)(hw + 0x40) & 0x2) {
                op_et_monster_init(0, -1);
                if (reload != 0 && *(int *)(hw + 0xB4) != 0) {
                    ((void (*)(int, int, int, int))opu_et_unit)(*(int *)(hw + 0x88), 0, *(int *)(hw + 0xB4), -3);
                }
            }
            if (*(u16 *)(hw + 0x40) & 0x4) {
                op_et_weapon_init(*(int *)(hw + 0x90), 0);
                if (reload != 0 && *(int *)(hw + 0xB8) != 0) {
                    ((void (*)(int, int, int, int))opu_et_unit)(*(int *)(hw + 0x90), 0, *(int *)(hw + 0xB8), -3);
                }
            }
            if (obj1 != 0) {
                int (**vt)(int) = (int (**)(int))obj1->vt50;
                void (**vt2)(int) = (void (**)(int))(vt + 16);
                s8 saved = DBG.b15;
                DBG.b15 = 0;
                vt2[3](0);
                vt[0](DBG.w34);
                ((int (*)(int))vt2[7])(0);
                DBG.b15 = saved;
            }
            goto tail;
        }

        if (obj1 != 0) {
            obj0 = obj1;
        }
        if (pad[2] & 0x800) {
            flag = 1;
            DBG.b0 = ~DBG.b0;
        }
        if ((s8)DBG.b0 == 0) {
            DBG.b1 = 0;
            p3 = pad[3];
        } else {
            p3 = pad[3];
            DBG.b1 = -1;
            if (p3 & 0x80) {
                DBG.b1 = 0;
            }
        }
        {
            s16 idx = DBG.h6;
            if (p3 & 0x1) {
                idx--;
                if (idx < 0) {
                    idx = *(u16 *)((u8 *)obj0 + 0x38) - 1;
                }
            }
            if (p3 & 0x2) {
                idx++;
                if (idx >= *(u16 *)((u8 *)obj0 + 0x38)) {
                    idx = 0;
                }
            }
            DBG.h6 = idx;
        }
    }

    if (obj1 != 0) {
        obj0 = obj1;
    }
    if (pad[0] & 0x10) {
        p2 = pad[2];
        if (p2 & 0x80) {
            DBG.bC = ~DBG.bC;
        }
        if (p2 & 0x20) {
            DBG.h8 = (DBG.h8 + 1) & 1;
        }
        if (p2 & 0x40) {
            DBG.bE = ~(u8)DBG.bE;
            opd_camera_change(DBG.bE);
        }
    }

    {
        s16 bank = (s16)DBG.h8;
        s16 idx = DBG.h6;
        s16 *tbl = *(s16 **)((u8 *)obj0 + (bank << 2) + 0x10);
        s16 slot = tbl[idx];
        if (slot >= 0) {
            u8 *sub = *(u8 **)((u8 *)obj0 + 0x20) + (slot << 8);
            if (pad[0] & 0x20) {
                p3 = pad[3];
                if (p3 & 0x8000) *(float *)(sub + 0x40) -= 8.0f;
                if (p3 & 0x2000) *(float *)(sub + 0x40) += 8.0f;
                if (p3 & 0x1000) *(float *)(sub + 0x44) -= 8.0f;
                if (p3 & 0x4000) *(float *)(sub + 0x44) += 8.0f;
                if (p3 & 0x0004) *(float *)(sub + 0x48) -= 8.0f;
                if (p3 & 0x0008) *(float *)(sub + 0x48) += 8.0f;
                if (p3 & 0x0001) *(float *)(sub + 0x4C) -= 8.0f;
                if (p3 & 0x0002) *(float *)(sub + 0x4C) += 8.0f;
            }
            if (pad[0] & 0x10) {
                if (pad[3] & 0x8000) *(float *)(sub + 0x30) -= 16.0f;
                if (pad[3] & 0x2000) *(float *)(sub + 0x30) += 16.0f;
                if (pad[3] & 0x1000) *(float *)(sub + 0x34) -= 16.0f;
                if (pad[3] & 0x4000) *(float *)(sub + 0x34) += 16.0f;
                if (pad[3] & 0x0004) *(float *)(sub + 0x38) -= 16.0f;
                if (pad[3] & 0x0008) *(float *)(sub + 0x38) += 16.0f;
                if (pad[3] & 0x0001) *(float *)(sub + 0x3C) -= 16.0f;
                if (pad[3] & 0x0002) *(float *)(sub + 0x3C) += 16.0f;
            }
        }
    }

    if (DBG.w18 != 0) {
        if (!(pad[0] & 0x10)) {
            if (!(pad[0] & 0x20)) {
                float step = 1.0f;
                s32 astep = 0x10;
                float angle;

                if (pad[0] & 0x40) {
                    step = 8.0f;
                    astep = 0x80;
                }
                if (pad[0] & 0x80) {
                    if (pad[0] & 0x8000) D_0054B7C0.x -= step;
                    if (pad[0] & 0x2000) D_0054B7C0.x += step;
                    if (pad[0] & 0x1000) D_0054B7C0.y -= step;
                    if (pad[0] & 0x4000) D_0054B7C0.y += step;
                    if (pad[0] & 0x0004) D_0054B7C0.z -= step;
                    if (pad[0] & 0x0008) D_0054B7C0.z += step;
                } else {
                    if (pad[0] & 0x8000) D_0054B7D0 -= step;
                    if (pad[0] & 0x2000) D_0054B7D0 += step;
                    if (pad[0] & 0x1000) D_0054B7D4 -= step;
                    if (pad[0] & 0x4000) D_0054B7D4 += step;
                    if (pad[0] & 0x0004) D_0054B7D8 -= astep;
                    if (pad[0] & 0x0008) D_0054B7D8 += astep;
                }
                if (pad[0] & 0x80) {
                    if (pad[3] & 0x2) {
                        DBG.b3E += 1;
                        goto do_tgt;
                    }
                    if (pad[3] & 0x1) {
                        float dx, dz;
                        DBG.b3E += 1;
do_tgt:
                        i = func_0029B560();
                        if (DBG.b3E < 0) {
                            DBG.b3E = i - 1;
                        }
                        if (DBG.b3E >= i) {
                            DBG.b3E = 0;
                        }
                        i = (s32)opd_target_handle_by_index(DBG.b3E);
                        if (i != 0) {
                            float pos[4];
                            Ch_OptposGet(i, 0, (int)pos);
                            func_002B5978(&D_0054B7C0.x, pos, 1.0f);
                            DBG.b45 = ((u16 (*)(int))func_0029B680)(DBG.b3E);
                        }
                        angle = D_0054B7C0.y;
                        angle -= D_0054B780.y;
                        {
                            float bx = D_0054B780.x;
                            dx = D_0054B7C0.x;
                            dx -= bx;
                        }
                        dz = D_0054B7C0.z - D_0054B780.z;
                        angle = angle * angle;
                        dx = dx * dx;
                        {
                            float t = dx + angle;
                            angle = t;
                        }
                        angle += dz * dz;
                        (void)func_002ED038(angle);
                        dx = (float)func_002E9290((double)angle);
                        if (dx >= (float)*(s16 *)(hw + 0x44)) {
                            dx = (float)*(s16 *)(hw + 0x44);
                        }
                        D_0054B7D0 = dx;
                    }
                }
                angle = 3.141592f;
                angle = (float)D_0054B7D8 * angle;
                angle /= 2048.0f;
                D_0054B780.z = (float)(func_002E8278((double)angle) * (double)D_0054B7D0 + (double)D_0054B7C0.z);
                D_0054B780.y = D_0054B7D4;
                D_0054B780.x = (float)(func_002E7B28((double)angle) * (double)D_0054B7D0 + (double)D_0054B7C0.x);
                D_0054B790.x = D_0054B7C0.x - D_0054B780.x;
                D_0054B790.y = D_0054B7C0.y - D_0054B780.y;
                D_0054B790.z = D_0054B7C0.z - D_0054B780.z;
                MsCameraSetRect(DBG.w18, 1, (void *)&D_0054B780);
                MsCameraSetRect(DBG.w18, 0, (void *)&D_0054B7C0);
            }
        }
    }

tail:
    pause_and = (s8)(DBG.b0 & (u8)DBG.b1);
    if (pause_and == 0) {
        DBG.hA += 1;
        DBG.w40 += 1;
    }
    speed = 0x100;
    if (pause_and != 0) {
        speed = 0;
    }
    if ((s8)DBG.b0 != 0 || flag != 0) {
        for (i = 0; i < 0xF0; i++) {
            if (owu_chr_hd[i] != 0) {
                Ch_SetMotionSpeed(owu_chr_hd[i], speed);
            }
        }
    }
}
#undef DBG

int func_0029B560(void) {
    int ofs = MsBattleGetStatus() ? 0 : 0x20;
    Chr **p = owu_chr_hd + ofs;
    int n = 0;
    int i;

    for (i = 0; i < 0xD0; i++) {
        if (p[i] != 0) {
            n++;
        }
    }
    return n;
}

Chr *opd_target_handle_by_index(idx)
int idx;
{
    int base;
    int i;
    int j;

    if (MsBattleGetStatus() != 0) {
        base = 0;
    } else {
        base = 0x20;
    }
    j = 0;

    for (i = 0; i < 0xD0; i++) {
        if (owu_chr_hd[base + i] != 0) {
            if (j == idx) {
                goto found;
            }
            j++;
        }
    }
    for (i = 0; i < 0xD0; i++) {
        if (owu_chr_hd[base + i] != 0) {
            goto found;
        }
    }
    return 0;
found:
    return owu_chr_hd[base + i];
}

u16 func_0029B680(void) {
    Chr *key = opd_target_handle_by_index();
    int i;

    if (key == 0) {
        return 0;
    }
    i = opus_get_chr_status_index(key, 0, 0);
    if (i < 0) {
        return 0;
    }
    return owu_chr_status[i].hE;
}

void func_0029B6D8(void) {
}

extern int D_007649A8;
s32 MsCameraGet(s32 a, s32 b, s32 c);
void MsCameraFree(int h);

typedef struct {
    u8 pad00[0x18];
    int cam;
} OpCamState;

void opd_camera_change(int a) {
    s8 *hw = (s8 *)&D_2008250;

    if (a != 0) {
        ((OpCamState *)&D_00764990)->cam = MsCameraGet(3, 0, 7);
        MsCameraSetRoll(((OpCamState *)&D_00764990)->cam, 0.0f);
        MsCameraSetScrDpt(((OpCamState *)&D_00764990)->cam, 1024.0f);
        MsBattleSpecialCameraPause(1);
        func_001CB798(0);
        if (hw[6] != 0) {
            Sg_EnableDrawMenu(0);
        } else {
            Sg_EnableDrawMenu(1);
        }
        if (hw[5] != 0) {
            Sg_EnableDrawGui(0);
        } else {
            Sg_EnableDrawGui(1);
        }
    } else {
        MsCameraFree(D_007649A8);
        func_001CB798(1);
        Sg_EnableDrawMenu(1);
        Sg_EnableDrawGui(1);
        MsBattleSpecialCameraPause(0);
    }
}

void func_0029B7D8(void) {
    D_0054D5E8[0]->vt50->f50(0);
}

void func_0029B808(void) {
    opus_ffxfocus_free();
}

void func_0029B810(void) {
}

void func_0029B818(void) {
}

int op_et_battle_genko_counter_get(void) {
    return D_0054D5E8[0]->b3A;
}

int func_0029B830(int a) {
    int r;
    if (D_00703FF0.b[1] != 0) {
        r = -1;
    } else if (op_oef2_sound_cue_check(a) != 0) {
        r = -1;
    } else {
        r = func_002D0570(a) != 0 ? -1 : 0;
    }
    return r;
}

void op_et_prayeff_send_read_through(Chr *key) {
    func_00120108(D_005753B0);
    func_00298230(key, 0x1000);
}

void op_et_encount_effect_on(int a, int b)
{
    HwRegs2008250 *hw = &D_2008250;

    if (D_007649A0 == 0) {
        if (D_00703E28 != 0) {
            ((void (*)(int, int, int, int))opu_et_unit)(D_00703E28, 0, a + 8, b); /* DEBT(CAST): void cast prevents sibling call */
        }
    } else if (hw->h40 & 0x20) {
        ((void (*)(int, int, int, int))opu_et_unit)(hw->w98, 0, hw->wBC, b); /* DEBT(CAST): void cast prevents sibling call */
    } else {
        if (D_00703E28 != 0) {
            ((void (*)(int, int, int, int))opu_et_unit)(D_00703E28, 0, a + 8, b); /* DEBT(CAST): void cast prevents sibling call */
        }
    }
}

u16 *opu_unit_max(ScriptThread *th, u16 *pc) {
    s16 max = pc[1];
    s16 n = max - *(u16 *)((u8 *)th + 0x334);
    u8 *p = *(u8 **)((u8 *)th + 0x320) + (*(u16 *)((u8 *)th + 0x334) << 8);

    for (; n > 0; n--, p += 0x100) {
        *(u_long128 *)p = 0;
    }
    pc += 2;
    *(s16 *)((u8 *)th + 0x334) = max;
    return pc;
}

/* operand 1 is a signed byte offset from the opcode word. DEBT(CAST): byte arithmetic on a u16 stream */
#define SCRIPT_JUMP(pc) ((u16 *)((char *)(pc) + (s16)(pc)[1]))

u16 *func_0029B9B0(ScriptThread *th, u16 *pc) {
    return SCRIPT_JUMP(pc);
}

#define SCRIPT_JUMP_AT_2(pc, idx) ((u16 *)((char *)(pc) + (s16)(pc)[idx]))

extern u8 D_00703FFA;
extern u32 D_00551CBC;
extern u8 owu_chr_drawoff_back[];
int func_002B3D68(int a);
int func_001CE8E0(void);
int func_001B8548(int id);
int func_001730F0(void);
int func_001AEBD8(void);
float Sg_GetSuimen(void);

u16 *opu_jump_etc(ScriptThread *th, u16 *pc)
{
    ScriptSub *sub = th->sub;
    int v;
    int target;
    int ofs;
    float f;

    switch (th->flags & 0xF000) {
    case 0x0000:
        if ((s16)pc[1] <= func_002B3D68(0x100)) {
            pc += 3;
        } else {
            ofs = (s16)pc[2];
            goto do_jump;
        }
        break;
    case 0x1000:
        func_002967E8(th, pc);
        v = func_001CE8E0();
        if (D_007649A0 != 0 && *(s16 *)((u8 *)th + 0x3B8) != 0) {
            v = *(s16 *)((u8 *)th + 0x3B8);
        }
        if (v != (s16)pc[1]) {
            pc += 3;
        } else {
            ofs = (s16)pc[2];
            goto do_jump;
        }
        break;
    case 0x2000:
        func_002967E8(th, pc);
        v = func_001CE8E0();
        if (D_007649A0 != 0 && *(s16 *)((u8 *)th + 0x3B8) != 0) {
            v = *(s16 *)((u8 *)th + 0x3B8);
        }
        if (v == (s16)pc[1]) {
            pc += 3;
        } else {
            ofs = (s16)pc[2];
            goto do_jump;
        }
        break;
    case 0x3000:
        if (((s8 *)th)[0x21E] != 0 && func_001B8548(sub->b18) != 0) {
            ofs = (s16)pc[1];
            goto do_jump;
        } else {
            pc += 2;
        }
        break;
    case 0x4000:
        if (((s8 *)th)[0x21E] != 0 && func_001B85B0(sub->b18) != 0) {
            ofs = (s16)pc[1];
            goto do_jump;
        } else {
            pc += 2;
        }
        break;
    case 0x5000:
        v = func_001730F0();
    cmp_u32:
        target = pc[1] + ((u32)pc[2] << 16);
        if (!(th->flags & 0x800)) {
            if (v != target) {
                pc += 4;
            } else {
                ofs = (s16)pc[3];
                goto do_jump;
            }
        } else {
            if (v == target) {
                pc += 4;
            } else {
                ofs = (s16)pc[3];
                goto do_jump;
            }
        }
        break;
    case 0x6000:
        v = 0;
        if (((s8 *)th)[0x21E] != 0) {
            v = func_001AEBD8();
        }
        goto cmp_u32;
    case 0x7000:
    case 0x8000: {
        int idx = opus_get_chr_status_index(owu_chr_hd[sub->b18], 0, 0);
        ResEntry *re = &owu_chr_status[idx];
        v = re->key;
        target = (s16)pc[1];
        if (th->flags & 0x1000) {
            if (v != target) {
                pc += 3;
            } else {
                ofs = (s16)pc[2];
                goto do_jump;
            }
        } else {
            if (v == target) {
                pc += 3;
            } else {
                ofs = (s16)pc[2];
                goto do_jump;
            }
        }
        break;
    }
    case 0x9000:
        v = func_001B8630(sub->b18);
        if (th->flags & 0x800) {
            if (v == 0) {
                pc += 2;
            } else {
                ofs = (s16)pc[1];
                goto do_jump;
            }
        } else {
            if (v == 0) {
                ofs = (s16)pc[1];
                goto do_jump;
            } else {
                pc += 2;
            }
        }
        break;
    case 0xA000:
        if (D_007649A0 != 0) {
            u8 *hw = (u8 *)&D_2008250;
            u32 *pad = &D_00551CBC;
            if (D_00703FFA != 0) {
                if (*(u16 *)(hw + 0x40) & 0x10) {
                    goto chk_pad;
                }
                goto adv1;
            } else {
                if (*(u16 *)(hw + 0x40) & 1) {
                chk_pad:
                    if ((*pad & 0xA0) != 0xA0) {
                        goto set_wait;
                    }
                }
            }
        }
    adv1:
        pc += 1;
        break;
    set_wait:
        ((s8 *)th)[0x210] = 1;
        break;
    case 0xB000:
        func_00109590(owu_chr_hd[sub->b18], (float *)th);
        VU0_LQC2(31, 0, th);
        VU0_OP("vmul.xyz $vf31, $vf31, $vf31");
        VU0_OP("vaddy.x $vf31, $vf31, $vf31y");
        VU0_OP("vaddz.x $vf31, $vf31, $vf31z");
        VU0_OP("vsqrt Q, $vf31x");
        VU0_OP("vwaitq");
        VU0_OP("vaddq.x $vf31, $vf0, Q");
        VU0_SQC2(31, 0x10, th);
        f = *(float *)((u8 *)th + 0x10);
        switch (th->flags & 0xF00) {
        case 0x000:
            if (f < 0.4f) {
                ofs = (s16)pc[1];
                goto do_jump;
            } else {
                pc += 2;
            }
            break;
        case 0x200:
            if (f >= 0.4f && f < 1.2f) {
                ofs = (s16)pc[1];
                goto do_jump;
            } else {
                pc += 2;
            }
            break;
        case 0x400:
            if (f >= 1.2f) {
                ofs = (s16)pc[1];
                goto do_jump;
            } else {
                pc += 2;
            }
            break;
        }
        break;
    case 0xC000:
        f = Sg_GetSuimen();
        Ch_OptposGet((int)owu_chr_hd[sub->b18], 1, (int)th);
        if (f <= ((float *)th)[1]) {
            ofs = (s16)pc[1];
            goto do_jump;
        } else {
            pc += 2;
        }
        break;
    case 0xD000:
        if (th->flags & 0x800) {
            if ((owu_chr_drawoff_back[sub->b18] & ((u8 *)sub)[0xB3]) != 0) {
                pc += 2;
            } else {
                ofs = (s16)pc[1];
                goto do_jump;
            }
        } else {
            if ((owu_chr_drawoff_back[sub->b18] & ((u8 *)sub)[0xB3]) != 0) {
                ofs = (s16)pc[1];
                goto do_jump;
            } else {
                pc += 2;
            }
        }
        break;
    case 0xE000: {
        SlotEntry *e = &owu_eff_status[sub->h14];
        if (((u8 *)e)[0x18] == sub->b18) {
            ofs = (s16)pc[1];
            goto do_jump;
        } else {
            pc += 2;
        }
        break;
    }
    case 0xF000:
        v = (s16)(th->flags & 0x800);
        if (D_007649A0 != 0) {
            if (v == 0) {
                ofs = (s16)pc[1];
                goto do_jump;
            } else {
                pc += 2;
            }
        } else {
            if (v != 0) {
                ofs = (s16)pc[1];
                goto do_jump;
            } else {
                pc += 2;
            }
        }
        break;
    }
    goto done;
do_jump:
    pc = (u16 *)((char *)pc + ofs);
done:
    return pc;
}

int Sg_MemGetMaxFree(int a);

u16 *opu_jump_etc2(ScriptThread *th, u16 *pc)
{
    register ScriptSub *sub __asm__("$17") = th->sub;
    SlotEntry *e = &owu_eff_status[sub->h14];
    s16 inv = th->flags & 0x800;
    ResEntry *re;
    int i;
    int idx;

    switch (th->flags & 0xF000) {
    case 0x0000:
        func_002967E8(th, pc);
        if (MsGetChrFly(sub->b18) != 0) {
            if (inv == 0) {
                pc = SCRIPT_JUMP(pc);
            } else {
                pc += 2;
            }
        } else {
            if (inv == 0) {
                pc += 2;
            } else {
                pc = SCRIPT_JUMP(pc);
            }
        }
        break;
    case 0x1000:
        func_002967E8(th, pc);
        if (MsGetDamageResult(e->key, sub->b18, 0, 0, (int *)th) == 1) {
            pc = SCRIPT_JUMP(pc);
        } else {
            pc += 2;
        }
        break;
    case 0x2000:
        func_002967E8(th, pc);
        if (sub->b18 < 8) {
            pc = SCRIPT_JUMP(pc);
        } else {
            pc += 2;
        }
        break;
    case 0x3000: {
        Chr *chr = owu_chr_hd[sub->b18];
        if (func_00110758(chr) == 0) {
            register int cur __asm__("$17");
            cur = ((int (*)(Chr *))opus_get_chr_status_index)(chr);
            if (cur >= 0) {
                register int tmp __asm__("$3") = cur << 5;
                u8 prev;
                re = (ResEntry *)((u8 *)owu_chr_status + tmp);
                cur = func_00110560(chr);
                prev = re->b16;
                if (cur != prev) {
                    if (cur == 2) {
                        if (prev == 0) {
                            pc = SCRIPT_JUMP(pc);
                        }
                        re->b16 = cur;
                        break;
                    } else if (cur == 0) {
                        if (prev == 2) {
                            pc = SCRIPT_JUMP_AT(pc, 2);
                        }
                        re->b16 = 0;
                        break;
                    } else {
                        re->b16 = 0;
                    }
                }
            }
        }
        pc += 3;
        break;
    }
    case 0x4000:
        func_002967E8(th, pc);
        for (i = 0; i < e->b8; i++) {
            idx = opus_get_chr_status_index(owu_chr_hd[e->list[i]], 0, 0);
            if (idx >= 0) {
                re = &owu_chr_status[idx];
                if (re->key == 0x10B2) {
                    goto do_jump;
                }
                if (re->key == 0x10B3) {
                    goto do_jump;
                }
                if (re->key == 0x10B4) {
                    goto do_jump;
                }
                if (re->key == 0x1121) {
                    goto do_jump;
                }
                if (re->key == 0x1122) {
                    goto do_jump;
                }
                if (re->key == 0x1123) {
do_jump:
                    pc = SCRIPT_JUMP(pc);
                    goto done;
                }
            }
        }
        pc += 2;
        break;
    case 0x5000:
        if (Sg_MemGetMaxFree(0) >= 0x1E0000 || Sg_MemGetMaxFree(1) >= 0x1E0000 || Sg_MemGetMaxFree(2) >= 0x1E0000) {
            pc += 2;
        } else {
            pc = SCRIPT_JUMP(pc);
        }
        break;
    case 0x6000:
        func_002967E8(th, pc);
        idx = opus_get_chr_status_index(owu_chr_hd[sub->b18], 0, 0);
        re = &owu_chr_status[idx];
        if (re->b17 & 1) {
            pc = SCRIPT_JUMP(pc);
        } else {
            pc += 2;
        }
        break;
    }
done:
    return pc;
}

u16 *func_0029C338(ScriptThread *th, u16 *pc) {
    th->sub->stk[th->sp] = pc + 2;
    return SCRIPT_JUMP(pc);
}

u16 *func_0029C360(ScriptThread *th) {
    return th->sub->stk[th->sp];
}

u16 *func_0029C378(ScriptThread *th, u16 *pc) {
    th->sub->h1A = pc[1];
    return pc + 2;
}

u16 *opu_et_no(ScriptThread *th, u16 *pc) {
    ScriptSub *sub = th->sub;
    SlotEntry *e = &owu_eff_status[sub->h14];

    sub->h1A = pc[1] + (e->sub->h1A & 0x7FF0);
    return pc + 2;
}

u16 *func_0029C3C8(ScriptThread *th, u16 *pc) {
    return pc + 1;
}

int MsGetDamageInfo(int a, int b, void *x, void *y, void *z);
float opus_cscale_get(int id, int flag);

u16 *func_0029C3D0(ScriptThread *th, u16 *pc) {
    u16 flags = th->flags;
    ScriptSub *sub = th->sub;
    int arg = pc[1];
    u32 idx = flags >> 12;
    SlotEntry *e;
    int r;
    s16 max;
    float f;

    switch (flags & 0xE00) {
    case 0x000:
        sub->loopcnt[idx] = arg;
        pc += 2;
        break;
    case 0x200:
        func_002967E8(th, pc);
        e = &owu_eff_status[sub->h14];
        r = MsGetDamageInfo(e->key, sub->b18, 0, 0, 0);
        sub->loopcnt[idx] = r;
        if (r != 0) {
            pc += 2;
        } else {
            pc = SCRIPT_JUMP(pc);
        }
        break;
    case 0x400:
        r = func_002B3D68((s16)pc[2]);
        pc += 3;
        sub->loopcnt[idx] = arg + r;
        break;
    case 0x600:
        f = *(float *)((char *)sub + arg);
        pc += 2;
        sub->loopcnt[idx] = f;
        break;
    case 0x800:
        max = pc[2];
        f = opus_cscale_get(sub->b18, th->b21E);
        pc += 3;
        arg = f * arg;
        if (arg > max) {
            arg = max;
        }
        if (arg <= 0) {
            arg = 1;
        }
        sub->loopcnt[idx] = arg;
        break;
    }
    return pc;
}

u16 *func_0029C550(ScriptThread *th, u16 *pc) {
    u8 *cnt = th->sub->loopcnt;

    cnt += th->flags >> 12;
    if (--*cnt != 0) {
            return SCRIPT_JUMP(pc);
    }
    return pc + 2;
}

Chr *func_0013B150(int id);
Chr *opd_target_handle_by_index();

u16 *opu_en_lock(ScriptThread *th, u16 *pc)
{
    ScriptSub *sub = th->sub;
    SlotEntry *e = &owu_eff_status[sub->h14];
    int w;
    s16 id;

    switch (((s16)th->flags & 0xF000) >> 12) {
    case 0: {
        register u8 v __asm__("$5") = *(u8 *)((u8 *)e + 0x10);
        if (v == 0xFF) {
            v = *(u8 *)((u8 *)e + 0x18);
        }
        sub->b18 = v;
        pc += 1;
        break;
    }
    case 1:
        if (th->b21E != 0) {
            register u8 v __asm__("$5") = *(u8 *)(pc + 1);
            sub->b18 = v;
        } else {
            func_00120108(D_005753E0);
        }
        pc += 2;
        break;
    case 3:
        if (D_007649A0 != 0) {
            register u8 cid __asm__("$5") = *(u8 *)(pc + 1);
            if (owu_chr_hd[cid] == 0) {
                int i = opus_get_chr_status_index(opd_target_handle_by_index(0), 0, 0);
                register u8 v __asm__("$5") = owu_chr_status[i].hE;
                sub->b18 = v;
            } else {
                sub->b18 = cid;
            }
        }
        pc += 2;
        break;
    case 2:
        if (th->b21E == 0) {
            u16 cid = pc[1];
            owu_chr_hd[cid] = func_0013B150(cid);
        }
        pc += 2;
        break;
    case 5: {
        register int idx __asm__("$4");
        id = pc[1];
        idx = opus_get_chr_status_index_by_chrno(id);
        if (idx >= 0) {
            register int off __asm__("$4") = idx << 5;
            register ResEntry *re __asm__("$2") = (ResEntry *)((u8 *)owu_chr_status + off);
            __asm__("" : "+r"(re));
            sub->b18 = re->hE;
        } else {
            func_00120108(D_00575408, id);
        }
        pc += 2;
        break;
    }
    case 6: {
        int r = ((int (*)(u8))MsGetSummonerNum)(sub->b18);
        sub->b18 = r;
        if ((u8)r < 0x20) {
            pc += 2;
        } else {
            pc = SCRIPT_JUMP(pc);
        }
        break;
    }
    case 8:
        sub->b18 = *(u8 *)((u8 *)e + 0x18);
        pc += 1;
        break;
    case 9:
        w = MsGetWeaponHandle(sub->b18, 0);
    weapon_common:
        if (w == 0) {
            pc = SCRIPT_JUMP(pc);
        } else {
            register int idx __asm__("$4") = opus_get_chr_status_index((Chr *)w, 0, 0);
            if (idx >= 0) {
                register int off __asm__("$4") = idx << 5;
                register ResEntry *re __asm__("$2") = (ResEntry *)((u8 *)owu_chr_status + off);
                __asm__("" : "+r"(re));
                sub->b18 = re->hE;
            } else {
                func_00120108(D_00575438);
            }
            pc += 2;
        }
        break;
    case 10:
        w = MsGetWeaponHandle(sub->b18, 1);
        goto weapon_common;
    }
    return pc;
}

void Ch_DrawEnEffect(Chr *c, int on);
int graphicLevelGetNameHash(Chr *c, int mode);

u16 *opu_en_on(ScriptThread *th, u16 *pc)
{
    ScriptSub *sub = th->sub;
    SlotEntry *eff = &owu_eff_status[sub->h14];
    Chr *chr = owu_chr_hd[sub->b18];
    int on;

    switch ((s16)th->flags & 0xF000) {
    case 0x0000:
    case 0x1000:
    case 0xC000:
    case 0xD000:
        on = (th->flags & 0x1000);
        on = (on != 0);
        if (((s8 *)th)[0x21E] != 0 && sub->b18 < 0x20) {
            if (on != 0) {
                on = 0;
            } else {
                on = 1;
            }
            MsSetChrVisible(sub->b18, on);
            if (((s16)th->flags & 0xF000) == 0xC000 || ((s16)th->flags & 0xF000) == 0xD000) {
                func_001B57F0(sub->b18, on);
            }
        } else {
            func_00110718((int)owu_chr_hd[sub->b18], on);
        }
        pc += 1;
        break;
    case 0x2000:
        func_00110718((int)owu_chr_hd[((u8 *)eff)[0x18]], 0);
        pc += 1;
        break;
    case 0x3000:
        func_00110718((int)owu_chr_hd[((u8 *)eff)[0x18]], 1);
        pc += 1;
        break;
    case 0x4000:
    case 0x5000:
        if (((s8 *)th)[0x21E] != 0) {
            if (th->flags & 0x1000) {
                func_001B56A0(0);
            } else {
                func_001B56A0(1);
            }
        } else {
            int on = (th->flags & 0x1000);
            int i;
            on = (on != 0);
            for (i = 0; i < 0x20; i++) {
                if (owu_chr_hd[i] != 0) {
                    func_00110718((int)owu_chr_hd[i], on);
                }
            }
        }
        pc += 1;
        break;
    case 0x6000:
        Ch_DrawEnEffect(chr, 0);
        pc += 1;
        break;
    case 0x7000:
        Ch_DrawEnEffect(chr, 1);
        pc += 1;
        break;
    case 0x8000: {
        int mode = (s16)pc[1];
        u8 ofs = ((u8 *)pc)[4];
        float *fp = (float *)((u8 *)sub + ofs);
        if (mode < 2) {
            on = graphicLevelGetNameHash(chr, mode);
            if (ofs != 0) {
                *fp = (float)on;
            }
        } else {
            graphicLevelGetNameHash(chr, (int)*fp);
        }
        pc += 3;
        break;
    }
    case 0x9000:
        func_002967E8(th, pc);
        pc += 1;
        MsSetChrVisible(sub->b18, 1);
        break;
    case 0xA000:
        func_002967E8(th, pc);
        pc += 1;
        MsSetChrVisible(sub->b18, 0);
        break;
    case 0xB000: {
        int i;
        func_002967E8(th, pc);
        MMI_SQ_ZERO(0, th);
        MMI_SQ_ZERO(0x10, th);
        for (i = 0; i < ((u8 *)eff)[8]; i++) {
            ((u8 *)th)[eff->list[i]] = 1;
        }
        for (i = 0; i < 0x20; i++) {
            if (owu_chr_hd[i] != 0 && ((s8 *)th)[i] == 0 && sub->b18 != i) {
                MsSetChrVisible(i, 0);
            }
        }
        pc += 1;
        break;
    }
    }
    return pc;
}

void opus_camera_limit(void *obj300, int v);
void func_001AAC18(float a, float b);
void func_001AA360(float *a, float *b, float c, float d);
void func_001AA3A8(void);
int func_001A6828(int cam);

u16 *func_0029CBD0(ScriptThread *arg0, u16 *pc)
{
    register ScriptThread *th __asm__("$17") = arg0;
    ScriptSub *sub = th->sub;
    int sw = th->flags >> 12;
    int cam = *(int *)((u8 *)th + 0x35C);
    s16 s1;

    __asm__ volatile("" : "+r"(pc));
    s1 = (s16)pc[1];
    switch (sw) {
    case 0:
        func_002B5978((float *)th, (float *)((u8 *)sub + 0x90), 1.0f);
        if (s1 == 0) {
            func_002B5978((float *)((u8 *)th + 0x10), (float *)((u8 *)sub + 0x30), 0.0625f);
        } else {
            func_002B5978((float *)((u8 *)th + 0x10), (float *)((u8 *)opus_no_get((IdList *)((u8 *)th + 0x300), sub, s1) + 0x90), 1.0f);
        }
        MsCameraSetRect(cam, 1, (void *)th);
        MsCameraSetRect(cam, 0, (void *)((u8 *)th + 0x10));
        MsCameraSetRoll(cam, *(float *)((u8 *)sub + 0x4C) * 3.141592f * 0.00048828125f);
        MsCameraSetScrDpt(cam, *(float *)((u8 *)sub + 0x3C) + 1024.0f);
        break;
    case 1:
        func_001CB798(0);
        MsBattleSpecialCameraPause(1);
        *(int *)((u8 *)th + 0x35C) = MsEffectCameraGet(3, 0, 7);
        MsCameraResetMove(*(int *)((u8 *)th + 0x35C), 0);
        MsCameraResetMove(*(int *)((u8 *)th + 0x35C), 1);
        break;
    case 2:
        if (D_007649A0 != 0) {
            func_001CB798(1);
        }
        if (cam != 0) {
            MsBattleSpecialCameraPause(0);
            if (MsBattleGetStatus() == 0) {
                MsEffectCameraEnd(0);
            }
        }
        *(int *)((u8 *)th + 0x35C) = 0;
        break;
    case 3:
        func_001AAC18(*(float *)((u8 *)sub + 0x90), *(float *)((u8 *)sub + 0x94));
        break;
    case 4:
        MsCameraGetPosNow(1, (float *)((u8 *)sub + 0x90));
        func_002B5978((float *)((u8 *)sub + 0x40), (float *)((u8 *)sub + 0x90), 16.0f);
        break;
    case 5:
        MsCameraGetPosNow(0, (float *)((u8 *)sub + 0x90));
        func_002B5978((float *)((u8 *)sub + 0x40), (float *)((u8 *)sub + 0x90), 16.0f);
        break;
    case 6: {
        register float d __asm__("$f1") = (s16)pc[1];
        register float r __asm__("$f1");
        register float pi __asm__("$f12");
        MsCameraSetScrDpt(cam, d + 1024.0f);
        pi = 3.141592f;
        r = (s16)pc[2];
        pc += 1;
        pi = r * pi;
        MsCameraSetRoll(cam, pi * 0.00048828125f);
        break;
    }
    case 7:
        func_002B5978((float *)th, (float *)((u8 *)sub + 0x90), 1.0f);
        if (s1 == 0) {
            func_002B5978((float *)((u8 *)th + 0x10), (float *)((u8 *)sub + 0x30), 0.0625f);
        } else {
            func_002B5978((float *)((u8 *)th + 0x10), (float *)((u8 *)opus_no_get((IdList *)((u8 *)th + 0x300), sub, s1) + 0x90), 1.0f);
        }
        func_001AA360((float *)((u8 *)th + 0x10), (float *)th, *(float *)((u8 *)sub + 0x3C) + 1024.0f, *(float *)((u8 *)sub + 0x4C) * 3.141592f * 0.00048828125f);
        break;
    case 8:
        func_001AA3A8();
        break;
    case 9:
        D_00703FFC = pc[1] + 0x1000;
        ((void (*)(void *))opus_camera_limit)((u8 *)th + 0x300);
        break;
    case 10:
        D_00703FFC = 0;
        break;
    case 11:
        MsBattleSpecialCameraPause(0);
        MsEffectCameraEnd(0);
        *(int *)((u8 *)th + 0x35C) = 0;
        break;
    case 12:
        if (cam != 0 && func_001A6828(cam) != 0) {
            return SCRIPT_JUMP(pc);
        }
        break;
    }
    return pc + 2;
}

/* DEBT(CAST): operand 1 is a byte offset into the entity block starting at ScriptSub.a8 */
u16 *func_0029CF78(ScriptThread *th, u16 *pc) {
    ScriptSub *sub = th->sub;
    s16 idx = pc[1];
    s16 val = pc[2];

    switch (((s16)th->flags & 0xF000) >> 12) {
    case 0:
        *(u8 *)((char *)sub + idx + 0xA8) = val;
        pc += 3;
        break;
    case 1:
        *(u16 *)((char *)&sub->a8 + idx) = val;
        pc += 3;
        break;
    case 2:
        *(u16 *)((char *)&sub->a8 + idx) = val;
        *(u16 *)((char *)&sub->a8 + idx + 2) = pc[3];
        pc += 4;
        break;
    }
    return pc;
}

typedef struct {
    u8 pad00[0x60];
    void (*f60)(void *);
} OpuMemVt;

typedef struct {
    u8 pad00[0x0C];
    int w0C;
    u8 pad10[0x18];
    int w28;
    int w2C;
    u8 pad30[0x20];
    OpuMemVt *vt50;
    int w54;
    int w58;
    u8 pad5C[0x44];
    int wA0;
    int wA4;
    int wA8;
    int wAC;
    int wB0;
} OpuMemObj300;

int op_heap_init(int base, int size);
void op_free(int heap, void *ptr);

u16 *opu_mem(ScriptThread *th, u16 *pc) {
    OpuMemObj300 *o = (OpuMemObj300 *)th->obj300;
    ScriptSub *sub = th->sub;
    int s1, s2, s3;
    int p1, p2;

    switch ((s16)th->flags & 0xF000) {
    case 0x0000:
        if (sub->pBC != 0) {
            op_free(*(int *)((u8 *)th + 0x3A8), sub->pBC);
            sub->pBC = 0;
        }
        pc += 1;
        break;
    case 0x1000:
        s1 = pc[1] << 8;
        s2 = pc[2] << 8;
        s3 = pc[3] << 8;
        o->wA8 = op_heap_init(o->w0C, s1);
        pc += 4;
        o->wAC = s1;
        o->wA4 = s2;
        o->wB0 = s3;
        p1 = o->w0C + s1;
        o->wA0 = p1;
        p2 = p1 + s2;
        o->w54 = p2;
        o->w58 = p2;
        o->w28 = D_00303550;
        o->w2C = D_00303550;
        o->vt50->f60(o);
        break;
    }
    return pc;
}

u16 *opu_mfifo(ScriptThread *th, u16 *pc)
{
    T6_Th300Subs *o = (T6_Th300Subs *)th->obj300; /* DEBT(CAST) */
    ScriptSub *sub = th->sub;
    ScriptSub *tgt = opus_no_get(th->obj300, sub, (s16)pc[1]);
    int self;
    u32 idx;

    switch (tgt->bBB) {
    case 10:
        if (sub == tgt) {
            self = 1;
            idx = 0;
        } else {
            self = 0;
            idx = (u32)((u8 *)sub - o->subs) >> 8;
        }
        if (th->h212 == 0) {
            op_mfifo_set(tgt->pBC, (int)&sub->f90, self, (u16)idx); /* DEBT(TYPE): q7.h prototype takes int */
        }
        break;
    case 17:
        if (th->h212 == 0) {
            op_mfifo_set(sub->pBC, (int)&sub->f90, 0, 0); /* DEBT(TYPE) */
        }
        break;
    }
    return pc + 2;
}

u16 *opu_damage(ScriptThread *th, u16 *pc)
{
    ScriptSub *sub;
    SlotEntry *e;
    int mode;

    func_002967E8(th, pc);
    sub = th->sub;
    e = &owu_eff_status[sub->h14];
    if (th->flags & 0x800) {
        mode = 2;
        func_00120108(D_005754D8, e->key, sub->b18);
    } else {
        mode = 0;
        func_00120108(D_00575510, e->key, sub->b18);
    }
    switch ((s16)th->flags & 0xF000) {
    case 0x0000:
        func_001C5E90(e->key, e->list[0], mode);
        pc++;
        break;
    case 0x1000:
        func_001C5E90(e->key, sub->b18, mode);
        pc++;
        break;
    case 0x2000:
        MsMergeDamage(e->key, sub->b18);
        pc++;
        break;
    }
    return pc;
}

u16 *opu_damage_motion(ScriptThread *th, u16 *pc)
{
    ScriptSub *sub;
    SlotEntry *e;
    int mode;
    int id;

    func_002967E8(th, pc);
    sub = th->sub;
    e = &owu_eff_status[sub->h14];
    switch ((s16)th->flags & 0xF000) {
    case 0x0000:
        mode = 5;
        break;
    case 0x1000:
        mode = 6;
        break;
    }
    if (!(th->flags & 0x800)) {
        id = e->list[0];
    } else {
        id = sub->b18;
    }
    MsDamageSetMotion(id, mode, 1);
    return pc + 1;
}

u16 *func_0029D3A8(ScriptThread *th, u16 *pc)
{
    ScriptSub *sub = th->sub;

    switch ((s16)pc[1]) {
    case 1:
        if (th->h212 != 0) {
            pc = SCRIPT_JUMP_AT(pc, 2);
        } else {
            pc += 3;
        }
        break;
    case 2:
        pc += 2;
        D_0054B7C0.x = sub->f90;
        D_0054B7C0.y = sub->f94;
        D_0054B7C0.z = sub->f98;
        break;
    case 3:
        func_0029D9C0(th, sub, SCRIPT_JUMP_AT(pc, 2));
        pc += 3;
        break;
    case 4:
        th->h3B8 = pc[2];
        pc += 3;
        break;
    }
    return pc;
}

u16 *func_0029D478(ScriptThread *th, u16 *pc)
{
    ScriptSub *sub = th->sub;
    s16 n = pc[1];

    sub->a8.p = pc + 2;
    sub->bBB = 8;
    opus_draw_on((IdList *)th->obj300, th->h214); /* DEBT(CAST): obj300 is described as bytes */
    return pc + 3 + n;
}

u16 *func_0029D4D8(ScriptThread *th, u16 *pc)
{
    ScriptSub *sub = th->sub;
    ScriptSub *other;

    switch ((s16)th->flags & 0xF000) {
    case 0x0000:
        other = opus_no_get(th->obj300, sub, (s16)pc[1]);
        pc += 2;
        sub->v40[2] = op_deg_get(sub->v40, sub->v40[0], sub->v40[2], other->v40[0], other->v40[2]);
        break;
    case 0x1000:
        sub->bBA = 0;
        func_002B5978(sub->v40, &sub->f90, 16.0f);
        pc += 2;
        break;
    }
    sub->bB2 &= ~4;
    return pc;
}

u16 *func_0029D580(ScriptThread *th, u16 *pc) {
    ScriptSub *sub;

    func_002967E8(th, pc);
    sub = th->sub;
    if (((s16)th->flags & 0xF000) == 0) {
        if (func_001B84B8(sub->b18) == 0) {
            th->f210 = 1;
        } else {
            pc += 1;
        }
    }
    return pc;
}

u16 *func_0029D5E0(ScriptThread *th, u16 *pc)
{
    ScriptSub *sub = th->sub;

    switch ((s16)th->flags & 0xF000) {
    case 0x0000:
        func_002967E8(th, pc);
        MsEffectWaitFlag(1);
        sub->bB2 |= 1;
        break;
    case 0x1000:
        func_002967E8(th, pc);
        MsEffectWaitFlag(0);
        sub->bB2 &= ~1;
        break;
    case 0x2000:
        sub->bB2 |= 2;
        break;
    case 0x3000:
        sub->bB2 &= ~2;
        break;
    case 0x4000:
        sub->bB2 |= 4;
        break;
    case 0x5000:
        sub->bB2 &= ~4;
        break;
    }
    return pc + 1;
}

u16 *opu_ffx(ScriptThread *th, u16 *pc)
{
    SlotEntry *e = &owu_eff_status[th->sub->h14];

    switch ((s16)(pc[1] - 1)) {
    case 0:
        D_00703FF0.b[1] = 1;
        pc += 2;
        break;
    case 1:
        pc += 2;
        D_00703FF0.b[1] = 0;
        break;
    case 2:
        if (D_00703FF0.b[1] != 0) {
            th->f210 = 1;
        } else {
            pc += 2;
        }
        break;
    case 3:
        pc += 2;
        MsEffectReady(e->key, 1);
        return pc;
    case 4:
        if (MsEffectMotionLevel(e->key) > 0) {
            pc += 2;
        } else {
            th->f210 = 1;
        }
        break;
    case 5:
        pc += 2;
        MsEffectReady(e->key, 0);
        return pc;
    case 6:
        pc += 2;
        func_0011A9E0(1);
        func_0011AA08(1);
        Sg_EnableDrawMenu(1);
        Sg_EnableDrawGui(1);
        return pc;
    case 7:
        pc += 2;
        func_0011A9E0(0);
        func_0011AA08(0);
        Sg_EnableDrawMenu(0);
        Sg_EnableDrawGui(0);
        break;
    }
    return pc;
}

/* DEBT(CAST): bytecode stream read as raw bytes */
u8 *func_0029D838(AnimCtx *o, u8 *p)
{
    int a = *(u16 *)(p + 2);

    switch ((s16)o->h21A & 0xF000) {
    case 0:
        AtelSetEffectFlag(a);
        p += 4;
        break;
    case 0x1000:
        if (func_0014AA50(a) != 0) {
            p += 4;
        } else {
            o->b210 = 1;
        }
        break;
    }
    return p;
}

void func_001149A8(Chr *chr, float a, float b, float c);

u16 *func_0029D8B8(ScriptThread *th, u16 *pc) {
    ScriptSub *sub = th->sub;
    s16 op = pc[1];
    Chr *chr = owu_chr_hd[sub->b18];
    float f0, f1;
    int a;

    switch (op) {
    case 0:
        a = (int)*(float *)((u8 *)sub + 0x34);
        pc += 2;
        f1 = (a + 0x400) & 0xFFF;
        f0 = *(float *)((u8 *)sub + 0x38);
        f1 = f1 * 0.000244140625f * 360.0f - 90.0f;
        f0 += func_002B3DB0(10.0f);
        func_001149A8(chr, *(float *)((u8 *)sub + 0x30) * 0.00390625f, f1, f0);
        break;
    case 1:
        func_00114968(chr, 0);
        pc += 2;
        break;
    }
    return pc;
}

INCLUDE_ASM("build/ee_asm/game/op/opu/opu_29A8A8", func_0029D9C0);

void func_001AF2E8(float *out);
int op_point_get_line_circle(float *out1, float *out2, float cx, float cz, float r, float x0, float z0, float x1, float z1);
void func_002B3120(u32 color, int a, int b);

void opus_camera_limit(void *obj300, int v) {
    float v0[4];
    float v1[4];
    float v2[4];
    float v3[4];
    float v4[4];
    float dpt;

    if ((s16)D_00703FF0.hC != 0) {
        func_001AF2E8(v2);
        MsCameraGetPosNow(1, v0);
        MsCameraGetPosNow(0, v1);
        dpt = MsCameraGetScrDpt();
        if (op_point_get_line_circle(v3, v4, v2[0], v2[2], 120.0f, v0[0], v0[2], v1[0], v1[1]) != 0) {
            int cam = *(int *)((u8 *)obj300 + 0x5C);
            float d;

            v3[1] = v0[1];
            d = op_length_get(v0, v3) * (float)((s16)D_00703FF0.hC - 0x1000) * 0.00390625f;
            MsCameraSetRect(cam, 1, v3);
            MsCameraSetScrDpt(cam, dpt - d);
            if (D_007649A0 != 0 && *((s8 *)&D_2008250 + 0xB) != 0) {
                func_002B3120(0x80800000, 0x48, 0);
            }
        }
    }
}
