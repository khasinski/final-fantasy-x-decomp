#include "common.h"

typedef struct {
    float f00;
    float f04;
    s32 f08;
    s32 f0C;
} SubE5C0;

typedef struct {
    u8 pad00[0x50];
    float f50[3];
    u32 pad5C;
    float f60[3];
    u8 pad6C[0xBC];
    SubE5C0 sub;
} ObjE5C0;

typedef struct {
    u32 pad00;
    void *loop_pc[4];
    void *call_pc[4];
    u32 pad24[2];
    void *vars[8];
    u16 loop_cnt[4];
    u16 f54;
    u8 f56;
    u8 loop_sp;
    u8 call_sp;
} VmState;

typedef struct {
    u16 op;
    u16 arg;
    void *ptr;
} VmInstr;

extern float fn_002b3db0(float);

void ovl_09478_01b0e5c0(ObjE5C0 *a0) {
    SubE5C0 *s1 = &a0->sub;
    s32 i;
    float sum = 0.0f;
    for (i = 0; i < s1->f08; i++) {
        sum += fn_002b3db0(s1->f00);
    }
    a0->f50[0] += sum;
    a0->f50[1] += sum;
    a0->f50[2] += sum;

    sum = 0.0f;
    for (i = 0; i < s1->f0C; i++) {
        sum += fn_002b3db0(s1->f04);
    }
    a0->f60[0] += sum;
    a0->f60[1] += sum;
    a0->f60[2] += sum;
}

void *ovl_09478_01b0e6a0(VmState *a0, VmInstr *a1) {
    a0->f56 = 2;
    a0->f54 = a1->arg;
    return (u8 *)a1 + 4;
}

void *ovl_09478_01b0e6b8(VmState *a0, VmInstr *a1) {
    return a1->ptr;
}

void *ovl_09478_01b0e6c0(VmState *a0, VmInstr *a1) {
    return a0->vars[a1->arg];
}

void *ovl_09478_01b0e6d8(VmState *a0, VmInstr *a1) {
    void *ret = (u8 *)a1 + 4;
    a0->loop_cnt[a0->loop_sp] = a1->arg;
    a0->loop_pc[a0->loop_sp] = ret;
    a0->loop_sp++;
    return ret;
}

void *ovl_09478_01b0e718(VmState *a0, VmInstr *a1) {
    u8 idx = a0->loop_sp - 1;
    if (a0->loop_cnt[idx] != 0xFFFF) {
        a0->loop_cnt[idx]--;
    }
    if (a0->loop_cnt[idx] != 0) {
        return a0->loop_pc[idx];
    }
    a0->loop_sp--;
    return (u8 *)a1 + 4;
}

void *ovl_09478_01b0e780(VmState *a0, VmInstr *a1) {
    a0->call_pc[a0->call_sp] = (u8 *)a1 + 8;
    a0->call_sp++;
    return a1->ptr;
}

void *ovl_09478_01b0e7a8(VmState *a0) {
    a0->call_sp--;
    return a0->call_pc[a0->call_sp];
}
