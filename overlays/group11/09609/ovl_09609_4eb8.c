#include "common.h"
#include "vu0.h"

typedef struct {
    float x, y, z, w;
} __attribute__((aligned(16))) Vec4;

typedef struct {
    u8 pad0[0xC0];
    float unkC0;
    float unkC4;
    u8 padC8[0x8];
    Vec4 unkD0;
    u8 padE0[0x40];
    s32 unk120;
    u8 pad124[0xC];
} Work4EB8;

typedef struct {
    u8 pad0[0x80];
    u8 unk80;
    u8 unk81;
    u8 unk82;
    u8 unk83;
    u8 unk84;
    u8 unk85;
    u8 unk86;
    u8 unk87;
    s32 unk88;
    u8 pad8C[0xC];
    u8 unk98;
    u8 unk99;
    u8 pad9A[2];
} Sub2F90;

typedef struct {
    u8 pad0[0x5200];
    s32 unk5200;
    u8 pad5204[4];
    s32 unk5208;
    s32 unk520C;
    s32 unk5210;
} Sub8550;

typedef struct {
    u8 pad0[0xF70];
    Work4EB8 unkF70;
    u8 pad10A0[0x2F80 - 0x10A0];
    Vec4 unk2F80;
    Sub2F90 unk2F90;
    u8 pad302C[0x8550 - 0x302C];
    Sub8550 unk8550;
    u8 padD764[0xEC00 - 0xD764];
    float unkEC00;
} State4EB8;

typedef struct {
    u8 pad0[0x130];
    Work4EB8 unk130;
    Vec4 unk260;
    Vec4 unk270;
    Vec4 unk280;
    Vec4 unk290;
    Vec4 unk2A0;
    Vec4 unk2B0;
    u8 pad2C0[0x250];
    s32 unk510;
    s32 unk514;
    s32 unk518;
} Obj4EB8;

typedef struct {
    u8 pad0[0x10];
    void (*unk10)(void *);
} TaskVtbl;

typedef struct {
    u8 pad0[0x8];
    TaskVtbl *unk8;
    u8 padC[0x8];
    Obj4EB8 *unk14;
} Task4EB8;

extern s32 D_01B00DF0[];
extern float D_01B00E08[];
extern u8 D_01B00FF8[];
extern u8 D_01B0A4D8[];
extern u8 D_01B0DEB0[];
extern u8 D_01B0DF58[];
extern State4EB8 *D_01B0DF78;
extern u8 D_01B17DF0[];
extern u8 D_01C03DD0[];

extern s32 func_001C00A0(s32);
extern float func_002B3DB0(float);
extern float func_002B3DF8(float);
extern void func_01B06A18(void);
extern void func_01B06FA8(void *, void *, s32);
extern s32 func_01B073A8(s32);
extern void func_01B07AF8(s32, s32, void *);
extern void func_01B08FE0(s32, void *, void *);
extern void func_01B09608(void *, s32, void *, s32);
extern void func_01B098A8(void *, s32, s32);
extern void func_01B09C38(void *);
extern void func_01B09F18(void *, void *, s32, s32, s32, void *, float);
extern float func_01B0AB78(float, float, float, float);
extern void func_01B0ADC0(void *, void *, void *);
extern void func_01B0AEC8(void *, void *, void *);
extern void func_01B0D740(void *, s32);

void func_01B04EB8(void) {
    State4EB8 *s = D_01B0DF78;
    Work4EB8 *w = &s->unkF70;
    register Vec4 *dst __asm__("$4");
    register Vec4 *src __asm__("$2");
    register u32 off __asm__("$3");
    u8 *hi;

    func_01B09F18(D_01B0DEB0, w, 0xD, 0, 0, 0, 0.5f);
    dst = &w->unkD0;
    src = &s->unk2F80;
    MMI_COPY_LQ_A3(dst, src);
    __asm__ volatile("sq $7, 0(%0)" : : "r"(dst), "r"(src) : "memory");
    __asm__("ori %0, $0, 0x8000" : "=r"(off));
    hi = (u8 *)s + off;
    w->unkC4 = *(float *)(hi + 0x6C00);
    *(s32 *)(hi + 0x5758) = 0;
}

void func_01B04F38(Obj4EB8 *arg0, float *arg1) {
    Work4EB8 *w;
    s32 idx;
    s32 se;

    idx = func_001C00A0(func_01B073A8(-1)) - 0x4029;
    w = &arg0->unk130;
    func_01B09F18(D_01B0DEB0, w, D_01B00DF0[idx], 0, 0, D_01B0A4D8, D_01B00E08[idx]);
    MMI_COPY_LQ_A3(&w->unkD0, &arg0->unk270);
    MMI_COPY_SQ_A3(&w->unkD0);
    w->unkC0 = arg1[0];
    w->unkC4 = arg1[1];
    w->unk120 = func_01B073A8(arg0->unk518);

    if (D_01B0DF78->unk8550.unk5208 == 0) {
        se = 0xD;
        func_01B098A8(D_01B17DF0, 1, 0);
    } else {
        se = 0xB;
        func_01B098A8(D_01B17DF0, 1, 1);
    }
    func_01B09608(D_01C03DD0, se, &w->unkD0, 0x100);
}

void func_01B05058(Task4EB8 *arg0) {
    Vec4 prev;
    Obj4EB8 *obj;
    State4EB8 *s;
    Sub8550 *sub;
    Vec4 *pos;
    Vec4 *vel;
    float floorY;
    float a;
    s32 alpha;

    obj = arg0->unk14;
    s = D_01B0DF78;
    sub = &s->unk8550;

    if (obj->unk510 > 0) {
        obj->unk510--;
    }

    pos = &obj->unk260;
    MMI_COPY_LQ_A3(&prev, pos);
    MMI_COPY_SQ_A3(&prev);

    vel = &obj->unk2A0;
    obj->unk2A0.y += 0.4f;
    VU0_LQC2(1, 0, pos);
    VU0_LQC2(2, 0, vel);
    VU0_OP("vadd.xyz $vf1, $vf1, $vf2");
    VU0_SQC2(1, 0, pos);

    floorY = s->unk2F80.y - 2.0f;
    if (obj->unk260.y >= floorY) {
        register u32 lenBits __asm__("$7");
        register float len __asm__("$f3");

        obj->unk270.y = obj->unk2A0.y * -0.75f;
        obj->unk270.x = obj->unk2A0.x * 0.95f;
        obj->unk270.z = obj->unk2A0.z * 0.95f;
        if (obj->unk270.y > 0.0f) {
            obj->unk270.y = 0.0f;
        }
        if (obj->unk2B0.x < 0.0f) {
            if (obj->unk270.x < 0.0f) {
                obj->unk270.x = 0.0f;
            }
        } else {
            if (obj->unk270.x >= 0.0f) {
                obj->unk270.x = 0.0f;
            }
        }
        if (obj->unk2B0.z < 0.0f) {
            if (obj->unk270.z < 0.0f) {
                obj->unk270.z = 0.0f;
            }
        } else {
            if (obj->unk270.z >= 0.0f) {
                obj->unk270.z = 0.0f;
            }
        }

        MMI_COPY_LQ_A3(vel, &obj->unk270);
        MMI_COPY_SQ_A3(vel);

        if (obj->unk270.y > 0.0f) {
            register float t __asm__("$f4");
            t = (obj->unk260.y - floorY) / (obj->unk260.y - prev.y);
            obj->unk260.x = prev.x + (obj->unk260.x - prev.x) * t;
            obj->unk260.z = prev.z + (obj->unk260.z - prev.z) * t;
        }
        obj->unk260.y = floorY;

        VU0_LQC2(1, 0, vel);
        VU0_OP("vmul.xyz $vf1, $vf1, $vf1");
        VU0_OP("vaddy.x $vf1, $vf1, $vf1");
        VU0_OP("vaddz.x $vf1, $vf1, $vf1");
        VU0_OP("vsqrt Q, $vf1x");
        VU0_OP("vwaitq");
        VU0_OP("vaddq.x $vf1, $vf0, Q");
        VU0_QMFC2(lenBits, 1);
        __asm__ volatile("mtc1 %1, %0" : "=f"(len) : "r"(lenBits));

        {
            register float w __asm__("$f2") = obj->unk270.w;
            register float r __asm__("$f4") = len / w;
            obj->unk290.x *= r;
            obj->unk290.y *= r;
        }
    }

    {
        float d = obj->unk290.x;
        float *p = &obj->unk280.x;
        a = *p + d;
        if (a > 3.1415927f) {
            a -= 6.2831855f;
        } else if (a < -3.1415927f) {
            a += 6.2831855f;
        }
        *p = a;
    }

    {
        float d = obj->unk290.z;
        float *p = &obj->unk280.y;
        a = *p + d;
        if (a > 3.1415927f) {
            a -= 6.2831855f;
        } else if (a < -3.1415927f) {
            a += 6.2831855f;
        }
        *p = a;
    }

    alpha = 0x80;
    if (obj->unk510 < 20) {
        alpha = (obj->unk510 * 0x80) / 20;
    }
    func_01B06FA8(&obj->unk280, pos, alpha);

    if (obj->unk510 <= 0) {
        sub->unk5210++;
        func_01B09C38(arg0);
    }
}

void func_01B053A0(Task4EB8 *arg0) {
    Vec4 pos;
    Obj4EB8 *obj;
    Sub8550 *sub;
    float t;
    s32 i;

    obj = arg0->unk14;
    sub = &D_01B0DF78->unk8550;

    if (obj->unk510 > 0) {
        obj->unk510--;
        if (obj->unk510 == 8) {
            func_01B08FE0(-1, D_01B0DF58, D_01B00FF8);
            sub->unk5200 = 0x1F;
        }
        if (obj->unk510 == 0) {
            func_01B06A18();
        }
    }

    {
        float *dst = &pos.x;
        float *p1 = &obj->unk270.x;
        float *p0 = &obj->unk260.x;
        t = (float)obj->unk510 / (float)obj->unk514;
        for (i = 0; i < 3; i++) {
            *dst++ = *p0++ * (1.0f - t) + *p1++ * t;
        }
    }

    pos.y = func_01B0AB78(obj->unk260.y, obj->unk260.y - 15.0f, obj->unk270.y, t);
    pos.w = 1.0f;

    if (obj->unk510 <= 0) {
        sub->unk5200--;
        func_01B07AF8(-1, 5, &pos);
    }

    if (obj->unk510 > 0) {
        func_01B06FA8(&obj->unk280, &pos, 0x80);
    }

    if (obj->unk510 <= 0 && sub->unk5200 <= 0) {
        sub->unk5210++;
        func_01B09C38(arg0);
    }
}

void func_01B05530(Task4EB8 *arg0) {
    Vec4 pos;
    Vec4 rot;
    Vec4 zero;
    Obj4EB8 *obj;
    State4EB8 *s;
    Sub8550 *sub;
    register Vec4 *v270 __asm__("$22");
    register Vec4 *v260 __asm__("$16");
    register Vec4 *v280 __asm__("$20");
    float t;
    s32 i;

    obj = arg0->unk14;
    s = D_01B0DF78;
    sub = &s->unk8550;

    if (obj->unk510 > 0) {
        obj->unk510--;
    }

    v270 = &obj->unk270;
    v260 = &obj->unk260;
    v280 = &obj->unk280;
    {
        float *dst = &pos.x;
        float *p1 = &v260->x;
        float *p0 = &v270->x;
        t = (float)obj->unk510 / (float)obj->unk514;
        for (i = 0; i < 3; i++) {
            *dst++ = *p0++ * (1.0f - t) + *p1++ * t;
        }
    }
    pos.w = 1.0f;

    func_01B06FA8(v280, &pos, 0x80);

    if (obj->unk510 <= 0) {
        func_01B04F38(obj, &v280->x);

        if (sub->unk5208 == 1) {
            Sub2F90 *sub2 = &s->unk2F90;
            sub2->unk98 = 0x48;
            sub2->unk83 = 0x80;
            sub2->unk82 = 0x80;
            sub2->unk81 = 0x80;
            sub2->unk80 = 0x80;
            sub2->unk84 = 0x80;
            sub2->unk85 = 0x80;
            sub2->unk86 = 0x80;
            sub2->unk87 = 0;
            sub2->unk88 = 0;
            sub2->unk99 = 0;
            func_01B0D740(sub2, 0x14);
            obj->unk510 = obj->unk514 = obj->unk514 + 8;
            func_01B07AF8(-1, 0xB, v260);
            arg0->unk8->unk10 = (void (*)(void *))func_01B053A0;
        } else {
            register float rz __asm__("$f3");
            register u32 lenBits __asm__("$7");
            float len;

            MMI_COPY_LQ_A3(v260, &pos);
            MMI_COPY_SQ_A3(v260);

            zero.x = 0.0f;
            zero.y = 0.0f;
            zero.z = 0.0f;
            zero.w = 1.0f;
            MMI_COPY_LQ_A3(&obj->unk2A0, &zero);
            MMI_COPY_SQ_A3(&obj->unk2A0);

            pos.x = func_002B3DB0(1.0f);
            pos.y = -(func_002B3DB0(1.0f) + 3.0f);
            rz = func_002B3DB0(0.2f) + 0.1f;
            if (rz < 0.05f && rz > -0.05f) {
                rz = 0.1f;
            }
            {
                register float pz __asm__("$f0") = rz * 10.0f;
                pos.z = -pz;
            }
            pos.w = 1.0f;
            func_01B0AEC8(v280, &obj->unk2A0, &pos);
            func_01B0ADC0(&rot, &zero, &pos);

            pos.x = 0.0f;
            pos.y = 0.0f;
            pos.z = -0.7f;
            pos.w = 1.0f;
            MMI_COPY_LQ_A3(&obj->unk2B0, &zero);
            MMI_COPY_SQ_A3(&obj->unk2B0);
            func_01B0AEC8(&rot, &obj->unk2B0, &pos);

            MMI_COPY_LQ_A3(v270, &obj->unk2A0);
            MMI_COPY_SQ_A3(v270);

            VU0_LQC2(1, 0, &obj->unk2A0);
            VU0_OP("vmul.xyz $vf1, $vf1, $vf1");
            VU0_OP("vaddy.x $vf1, $vf1, $vf1");
            VU0_OP("vaddz.x $vf1, $vf1, $vf1");
            VU0_OP("vsqrt Q, $vf1x");
            VU0_OP("vwaitq");
            VU0_OP("vaddq.x $vf1, $vf0, Q");
            VU0_QMFC2(lenBits, 1);
            __asm__ volatile("mtc1 %1, %0" : "=f"(len) : "r"(lenBits));
            obj->unk270.w = len;

            obj->unk290.x = (func_002B3DB0(0.1f) + 0.05f) * 3.1415927f;
            obj->unk290.y = -(func_002B3DF8(0.1f) + 0.05f) * 3.1415927f;
            obj->unk290.z = 0.0f;
            obj->unk510 = 0x28;
            arg0->unk8->unk10 = (void (*)(void *))func_01B05058;
        }
    }
}
