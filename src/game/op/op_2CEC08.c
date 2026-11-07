/* tu_332 0x2cec08-0x2ceff0: medium; unk_2CEC08 (config/tu_map.tsv) */
/* DEBT(NAME): module and names guessed: bitfield/size helpers and wrappers (see w10.h). */
#include "common.h"
#include "ffx/q7.h"
#include "ffx/w10.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((u8 *)(expr) + (offset)))
#define MMI_SQ_ZERO(off, p) __asm__ volatile("sq $0, " #off "(%0)" : : "r"(p) : "memory")

#define UNIT_MAT(q) do { \
    register s32 _one __asm__("$2") = 0x3F800000; \
    MMI_SQ_ZERO(0x0, q); \
    MMI_SQ_ZERO(0x10, q); \
    MMI_SQ_ZERO(0x20, q); \
    MMI_SQ_ZERO(0x30, q); \
    ((volatile s32 *)(q))[0] = _one; \
    ((volatile s32 *)(q))[5] = _one; \
    ((volatile s32 *)(q))[10] = _one; \
    ((volatile s32 *)(q))[15] = _one; \
} while (0)

extern s32 D_004F3FD0;
extern s32 D_004F4010;
void func_002DCE08(void *, void *, void *);
void func_002DCE38(void *, void *, void *);
void _m2c_func_002CD590(void *, void *) __asm__("func_002CD590");
void _m2c_func_002CEFE8(void *, void *) __asm__("func_002CEFE8");
void func_002B52C0(void *, void *, void *);

/* DEBT(CAST) */
void func_002CEC08(void *a0, void *a1, void *a2) {
    u_long128 q[4];
    register s32 _one3 __asm__("$3");

    UNIT_MAT(q);
    _one3 = 0x3F800000;
    ((s32 *)a2)[3] = _one3;
    func_002DCE08(&q[3], &D_004F3FD0, a2);
    func_002DCE38(q, &D_004F4010, q);
    ((void **)a1)[7] = 0;
    ((void **)a1)[4] = q;
    _m2c_func_002CD590(a0, a1);
}

/* DEBT(CAST) */
void func_002CEC98(void *a0, void *a1, void *a2) {
    u_long128 q[4];
    register s32 _one3 __asm__("$3");

    UNIT_MAT(q);
    _one3 = 0x3F800000;
    ((s32 *)a2)[3] = _one3;
    func_002DCE08(&q[3], &D_004F3FD0, a2);
    func_002DCE38(q, &D_004F4010, q);
    ((void **)a1)[4] = q;
    ((void **)a1)[7] = q;
    _m2c_func_002CEFE8(a0, a1);
}

/* DEBT(CAST) */
void func_002CED28(void *a0, void *a1, void *a2, void *a3) {
    u_long128 q[4];

    UNIT_MAT(q);
    func_002B52C0(q, q, a3);
    ((s32 *)a2)[3] = 0x3F800000;
    func_002DCE08(&q[3], &D_004F3FD0, a2);
    func_002DCE38(q, &D_004F4010, q);
    ((void **)a1)[4] = q;
    ((void **)a1)[7] = q;
    _m2c_func_002CEFE8(a0, a1);
}

INCLUDE_ASM("build/ee_asm/game/op/op_2CEC08", func_002CEDD8);

void func_002CEE60(s32 a, s32 b) {
    func_002CEDD8(a, b, 0, 0x4000);
}

INCLUDE_ASM("build/ee_asm/game/op/op_2CEC08", func_002CEE70);

void func_002CEEC0(s32 a, u16 b, u16 c) {
    func_002CEE70(a, b, c, 0, 0x4000);
}

void func_002CEED8(s32 a, s32 b) {
    func_002CEE60(a, b);
}

/* DEBT(CAST) */
void func_002CEEE0(void *arg0, u16 arg1, u16 arg2, u16 arg3, u16 arg4) {
    s16 *var_11;
    s32 var_10;
    register u32 temp_2 __asm__("$2");
    void *temp_9;
    u32 s2 = arg2 << 5;
    u32 s4 = arg4 << 5;

    var_10 = M2C_FIELD(arg0, s16 *, 6);
    var_11 = (s16 *)((u8 *)arg0 + 0x10);
    for (; var_10 > 0; var_10--, var_11 += 4) {
        temp_9 = (u8 *)arg0 + *var_11;
        temp_2 = M2C_FIELD(temp_9, u32 *, 0x10);
        if ((temp_2 & 0x3FFF) == arg1) {
            M2C_FIELD(temp_9, u32 *, 0x10) = (temp_2 & 0xFFFFFC00) | arg3;
        }
        temp_2 = M2C_FIELD(temp_9, u32 *, 0x14);
        if ((temp_2 & 0x7FFE0) == s2) {
            M2C_FIELD(temp_9, u32 *, 0x14) = (temp_2 & 0xFFF8001F) | s4;
        }
    }
}

/* DEBT(CAST): explicit width views follow the existing shared interfaces. */
int func_002CEF70(W10SoundVoice *voice)
{
    int multiplier = 7;
    if (voice->header.half[0] & 8) multiplier = 14;
    return (multiplier * (s16)voice->header.half[1] + 7) * 16;
}

/* DEBT(CAST) */
void *func_002CEF98(u8 *resource, int index) {
    u32 entryAddress;
    s32 value;

    entryAddress = *(u32 *)(resource + 0x18);
    if (entryAddress > 0xFFFFF) {
        entryAddress += index * 4;
        value = *(s32 *)entryAddress;
        if (value == (s32)resource) {
            value = 0;
        }
        return (void *)value;
    }

    entryAddress += index * 4;
    entryAddress += (u32)resource;
    value = *(s32 *)entryAddress;
    if (value == 0) {
        return 0;
    }
    return (void *)(value + (s32)resource);
}

void func_002CEFE8(void) {
    func_002CD590();
}
