#include "common.h"
#include "vu0.h"

typedef struct {
    u8 pad0[0x40];
    float unk40[4];
    u8 pad50[0x10];
    float unk60[4];
    u8 pad70[0x10];
    float unk80[4];
    float unk90[4];
    float unkA0[4];
    u8 padB0[0x10];
    float unkC0[4];
    float unkD0[4];
    float unkE0[4];
    float unkF0[4];
    void (*unk100)(void *);
    void (*unk104)(void *);
    void *unk108;
    void *unk10C;
    void *unk110;
    s32 unk114;
    s32 unk118;
    s32 unk11C;
    u8 pad120[4];
    u16 unk124;
    u8 unk126;
} Unk7440Item;

typedef struct {
    void *unk0;
    void *unk4;
    void *unk8;
} Unk7440List;

typedef struct {
    u8 pad0[0x30];
    Unk7440List unk30;
} Unk7440Arg0;

extern void *D_006A3924;
extern float D_006A3930[4][4];
extern float D_006A3970[4][4];
extern float D_006A39B0[4][4];
extern float D_006A3A70[4][4];
extern float D_006A3AB0[4][4];
extern float D_006A3BB0[4];
extern s32 D_006A3BC4;
extern void *D_006A3BC8;
extern void *D_006A3BCC;

extern s32 func_00116068(void);
extern void func_00267530(void *);
extern s32 func_00267FA0(void *, s32);
extern void func_00268610(void *, void *, void *);
extern void func_002DCE08(float *, float *, float *);
extern void func_002DCE38(float *, float *, float *);
extern void func_002DD0C0(float *, float *);
extern void func_002DD128(float *);
extern void func_002DD1C8(float *, float *, float);
extern void func_002DD270(float *, float *, float);
extern void func_002DD318(float *, float *, float);
extern void func_002DD3C0(float *, float *, float *);
extern void func_002DD948(float *, float *);
extern void func_002DD998(float *, float *, float);
extern void func_01B06120(float *, float *);
extern void func_01B06B30(void *);
extern void func_01B06CE0(void *, float *);
extern void func_01B07BF8(Unk7440List *, Unk7440Item *);
extern void func_01B07D28(Unk7440List *);
extern Unk7440Item *func_01B07D88(Unk7440List *);

s32 func_01B07440(Unk7440Arg0 *arg0, Unk7440Item *arg1) {
    float mat[4][4];
    float id_mat[4][4];
    float vec[4];
    s32 count;
    Unk7440Item *cur;
    Unk7440List *list;
    register float *id_p __asm__("$22");

    list = &arg0->unk30;
    list->unk8 = arg0->unk30.unk0;
    D_006A3BC4 = 1;
    count = 0;
    if (func_00116068() != 0) {
        D_006A3BC4 = 0;
    }
    D_006A3924 = arg0;
    if (arg1 != 0) {
        D_006A3BCC = arg1;
    }

    func_01B06120(&D_006A3A70[0][0], &D_006A3970[0][0]);
    id_p = &id_mat[0][0];
    func_002DD128(id_p);

    while ((cur = func_01B07D88(list)) != 0) {
        if (cur->unk124 & 0x8000) {
            if (!(cur->unk124 & 1)) {
                if (cur->unk114 == 0) {
                    s32 ret;

                    if (func_00116068() != 0) {
                        if (cur->unk104 != 0) {
                            cur->unk104(cur);
                        }
                        if (cur->unk100 != 0 && cur->unk11C == cur->unk118) {
                            cur->unk100(cur);
                        }
                    }

                    switch (cur->unk126) {
                    case 1:
                        func_002DD3C0(&mat[0][0], id_p, cur->unkC0);
                        break;
                    case 2:
                        MMI_COPY_LQ_A3(mat[0], cur->unk80);
                        MMI_COPY_SQ_A3(mat[0]);
                        __asm__ volatile("lq $7, 0(%1)" : : "r"(mat[1]), "r"(cur->unk90), "g"(mat[1]) : "$7");
                        __asm__ volatile("sq $7, 0($18)" : : : "memory");
                        MMI_COPY_LQ_A3(mat[2], cur->unkA0);
                        MMI_COPY_SQ_A3(mat[2]);
                        MMI_COPY_LQ_A3(mat[3], id_mat[3]);
                        MMI_COPY_SQ_A3(mat[3]);
                        break;
                    default:
                        func_002DD1C8(&mat[0][0], id_p, cur->unkC0[2]);
                        func_002DD270(&mat[0][0], &mat[0][0], cur->unkC0[0]);
                        func_002DD318(&mat[0][0], &mat[0][0], cur->unkC0[1]);
                        break;
                    }

                    func_002DCE08(vec, &mat[0][0], cur->unkE0);
                    func_002DD998(mat[0], mat[0], cur->unk60[0]);
                    func_002DD998(mat[1], mat[1], cur->unk60[1]);
                    func_002DD998(mat[2], mat[2], cur->unk60[2]);
                    mat[3][0] = cur->unkD0[0] + vec[0];
                    mat[3][1] = cur->unkD0[1] + vec[1];
                    mat[3][2] = cur->unkD0[2] + vec[2];
                    func_002DD948(cur->unk40, mat[3]);
                    func_002DD0C0(&D_006A3930[0][0], &mat[0][0]);
                    if (cur->unk108 != 0) {
                        D_006A3BC8 = cur->unk108;
                    }
                    MMI_COPY_LQ_A3(D_006A3BB0, cur->unkF0);
                    MMI_COPY_SQ_A3(D_006A3BB0);
                    func_002DCE38(&D_006A39B0[0][0], &D_006A3970[0][0], &D_006A3930[0][0]);
                    func_002DCE38(&D_006A3AB0[0][0], &D_006A3A70[0][0], &D_006A39B0[0][0]);

                    if (!(cur->unk124 & 0x4000)) {
                        D_006A3924 = arg0;
                        ret = func_00267FA0(cur, 0x30);
                    } else {
                        cur->unk124 &= ~0x4000;
                        ret = 1;
                    }

                    if (ret == 1) {
                        D_006A3924 = arg0;
                        func_00267530(cur);
                        cur->unk124 &= ~0x8000;
                        func_01B07BF8(list, cur);
                    } else if (cur->unk10C != 0) {
                        func_00268610(cur, cur->unk10C, cur);
                    }

                    if (func_00116068() != 0) {
                        if (cur->unk110 != 0) {
                            func_01B06CE0(cur->unk110, mat[3]);
                            func_01B06B30(cur->unk110);
                        }
                        cur->unk118++;
                    }
                } else {
                    if (func_00116068() != 0) {
                        cur->unk114--;
                    }
                }
            }
            count++;
        }

        if (cur == func_01B07D88(list)) {
            func_01B07D28(list);
        }
    }

    return count == 0;
}
