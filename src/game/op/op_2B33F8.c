/* tu_328 0x2b33f8-0x2b4630: low; ~op (config/tu_map.tsv) */
/* DEBT(NAME): module and names guessed: EE kernel thread/semaphore wrappers (SDK) (see w10.h). */
#define func_002B3EA8 _hdr_func_002B3EA8
#define func_002B3888 _hdr_func_002B3888
#define func_002B3938 _hdr_func_002B3938
#define func_002B39C0 _hdr_func_002B39C0
#define func_002B3A48 _hdr_func_002B3A48
#define func_002B3C88 _hdr_func_002B3C88
#define func_002B40E8 _hdr_func_002B40E8
#include "common.h"
#include "vu0.h"
#include "ffx/q7.h"
#include "ffx/w10.h"
#include "ffx/g4.h"
#include "ffx/r7.h"
#undef func_002B3888
#undef func_002B3938
#undef func_002B39C0
#undef func_002B3A48
#undef func_002B3C88
#undef func_002B40E8
#undef func_002B3EA8

INCLUDE_ASM("build/ee_asm/game/op/op_2B33F8", op_spline_draw_path3);

void func_002B3708(void)
{
    func_002DD610(D_004F4050, 512.0f, 0.8f, 0.87285f, 2048.0f, 2048.0f, 1.0f, 16777215.0f, 1.0f, 65536.0f);
}

void func_002B3778(void)
{
    if (GIF_CHCR & 0x100) {
        func_002B3778();
    }
}

void func_002B37A0(void) {
}

void func_002B37A8(void) {
}

void func_002B37B0(void) {
}

void func_002B37B8(void) {
}

void func_002B37C0(void)
{
    D_00703F20 = 0x70000000;
    D_00764130 = 0x70004000;
    D_004F3F80 = 0;
    D_004F4110 = 0;
}

void func_002B37F0(void) {
}

typedef struct OpPadState {
    int now;
    int last;
    int pressed;
    int repeat;
    int timer;
} OpPadState;

typedef struct OpHwRegs {
    u8 pad0[8];
    s8 b8;
} OpHwRegs;

extern s8 D_007649A0;
extern OpPadState D_00551CA8[];

void op_pad_set(int pad, int unused_arg, u16 in)
{
    u8 unused_stack[0x20];
    OpHwRegs *hw = (OpHwRegs *)&D_2008250;
    OpPadState *p;

    if (D_007649A0 != 0) {
        p = &D_00551CA8[pad];
        if (hw->b8 == 0) {
            in = 0;
        }
        p->last = p->now;
        if (in != p->now) {
            p->repeat = in;
            p->timer = 12;
        } else if (--p->timer != 0) {
            p->repeat = 0;
        } else {
            p->repeat = in;
            p->timer = 1;
        }
        p->now = in;
        p->pressed = (in ^ p->last) & in;
    }
}

extern s8 _m2c_func_002B3888_D_004F3F80 __asm__("D_004F3F80");
extern s8 _m2c_func_002B3888_D_004F4110 __asm__("D_004F4110");
extern s8 _m2c_func_002B3888_D_00575B50[] __asm__("D_00575B50");
void _m2c_func_002B3888_func_00120108(void *) __asm__("func_00120108");
/* DEBT(FAKE) */
s32 func_002B3888(s32 a) {
    register s32 ra __asm__("$31");
    s32 idx = _m2c_func_002B3888_D_004F3F80;
    s32 v6;
    s32 v7;
    if (idx < 0x1F) {
        v6 = (&D_00703F20)[idx];
        v7 = v6 + a;
        if (v7 <= (s32)(&D_00764130)[_m2c_func_002B3888_D_004F4110]) {
            idx++;
            _m2c_func_002B3888_D_004F3F80 = idx;
            (&D_00703F20)[idx] = v7;
            return v6;
        }
    }
    *(s32 *)0x70003FE0 = a;
    __asm__ volatile("");
    *(volatile s32 *)0x70003FF0 = ra;
    __asm__ volatile("");
    _m2c_func_002B3888_func_00120108(_m2c_func_002B3888_D_00575B50);
    func_002EA328(1);
}

extern s8 _m2c_func_002B3938_D_004F4110 __asm__("D_004F4110");
extern s8 _m2c_func_002B3938_D_00575B68[] __asm__("D_00575B68");
void _m2c_func_002B3938_func_00120108(void *) __asm__("func_00120108");
s32 func_002B3938(s32 arg0) {
    s32 idx = _m2c_func_002B3938_D_004F4110;
    s32 v6;
    s32 v4;
    if (idx < 0x1F) {
        v6 = (&D_00764130)[idx];
        v4 = v6 - arg0;
        if (v4 >= (s32)(&D_00703F20)[idx]) {
            idx++;
            _m2c_func_002B3938_D_004F4110 = idx;
            (&D_00764130)[idx] = v6;
            return v4;
        }
    }
    _m2c_func_002B3938_func_00120108(_m2c_func_002B3938_D_00575B68);
    *(s32 *)0 = 0;
}

extern s8 _m2c_func_002B39C0_D_004F3F80 __asm__("D_004F3F80");
extern s8 _m2c_func_002B39C0_D_00575B88[] __asm__("D_00575B88");
void _m2c_func_002B39C0_func_00120108(void *) __asm__("func_00120108");
void func_002EA328(int) __attribute__((noreturn));
/* DEBT(FAKE) */
void func_002B39C0(s32 n) {
    register s32 ra __asm__("$31");
    s32 idx = _m2c_func_002B39C0_D_004F3F80;
    s32 prev;
    if (idx > 0) {
        prev = idx - 1;
        if ((s32)((&D_00703F20)[idx] - (&D_00703F20)[prev]) == n) {
            _m2c_func_002B39C0_D_004F3F80 = prev;
            return;
        }
    }
    *(s32 *)0x70003FE0 = n;
    __asm__ volatile("" : "=r"(ra));
    *(volatile s32 *)0x70003FF0 = ra;
    __asm__ volatile("");
    _m2c_func_002B39C0_func_00120108(_m2c_func_002B39C0_D_00575B88);
    func_002EA328(1);
}

extern s8 _m2c_func_002B3A48_D_004F4110 __asm__("D_004F4110");
extern s8 _m2c_func_002B3A48_D_00575BA0[] __asm__("D_00575BA0");
void _m2c_func_002B3A48_func_00120108(void *) __asm__("func_00120108");
void func_002B3A48(s32 n) {
    s32 idx = _m2c_func_002B3A48_D_004F4110;
    s32 prev;
    if (idx > 0) {
        prev = idx - 1;
        if ((s32)((&D_00764130)[prev] - (&D_00764130)[idx]) == n) {
            _m2c_func_002B3A48_D_004F4110 = prev;
            return;
        }
    }
    __asm__ volatile("sw $31, 0x0(%0)\n\tnop" : : "r"(0x70003F00));
    _m2c_func_002B3A48_func_00120108(_m2c_func_002B3A48_D_00575BA0);
    *(s32 *)0 = 0;
}

extern s8 _m2c_func_002B3AC8_D_004F4110 __asm__("D_004F4110");
s32 func_002B3AC8(s32 arg0) {
    if (arg0 + (s32)&D_00703F20 > *(s32 *)((s32)&D_00764130 + ((_m2c_func_002B3AC8_D_004F4110 + 1) << 2))) {
        return -1;
    }
    return 0;
}

extern s8 _m2c_func_002B3B08_D_004F3F80 __asm__("D_004F3F80");
s32 func_002B3B08(s32 arg0) {
    if ((s32)&D_00764130 - arg0 < *(s32 *)((s32)&D_00703F20 + ((_m2c_func_002B3B08_D_004F3F80 + 1) << 2))) {
        return -1;
    }
    return 0;
}

void func_002B3B48(const char *path, void *buffer)
{
    s8 saved;
    saved = D_00764990.mode15;
    D_00764990.mode15 = 1;
    op_file_read(path, buffer);
    D_00764990.mode15 = saved;
}

extern char D_00575BC0[];
extern char D_00575BD8[];

int op_file_read(const char *path, void *buffer)
{
    char msg[0x400];
    int fd;
    int size;

    if (D_00764990.mirror == 0 || D_00764990.mode15 == 0) {
        return 0;
    }
    fd = func_002FC4E0((int)path, 1);
    if (fd < 0) {
        func_00120108(D_00575BC0, path);
        func_002EA328(1);
    }
    size = func_002FC8E8(fd, 0, 2);
    func_002FC8E8(fd, 0, 0);
    func_002F0008(msg, D_00575BD8, path, buffer, size);
    func_00120108(msg);
    if (size != func_002FCB20(fd, buffer, size)) {
        size = 0;
    }
    func_002FC768(fd);
    func_002F8660(0);
    return size;
}
int func_002B3C88(int a)
{
    u8 unused[0x400];
    int fd;
    int size;

    if (D_007649A0 == 0) {
        return 0;
    }
    fd = func_002FC4E0(a, 1);
    if (fd < 0) {
        func_00120108(D_00575BC0, a);
        return 0;
    }
    size = func_002FC8E8(fd, 0, 2);
    func_002FC768(fd);
    return size;
}

void func_002B3D10(u32 a0)
{
    __asm__ volatile(
        "daddu      $6, $4, $0\n"
        "qmtc2.ni   $6, $vf30\n"
        "lui        $3, (0x40000000 >> 16)\n"
        "lui        $4, (0x40400000 >> 16)\n"
        "lui        $5, (0x3FF19120 >> 16)\n"
        "ori        $5, $5, (0x3FF19120 & 0xFFFF)\n"
        "vrnext.xyzw $vf31, R\n"
        "vitof0.xyzw $vf30, $vf30\n"
        "qmtc2.ni   $3, $vf29\n"
        "qmtc2.ni   $4, $vf28\n"
        "qmtc2.ni   $5, $vf27\n"
        "vmul.x     $vf31, $vf31, $vf29\n"
        "vsubx.w    $vf25, $vf31, $vf27x\n"
        "vsub.x     $vf31, $vf31, $vf28\n"
        "vmul.x     $vf30, $vf31, $vf30\n"
        "vftoi0.x   $vf30, $vf30\n"
        "qmfc2.ni   $7, $vf30\n"
        "vrinit     R, $vf25w\n"
        "dsll32     $7, $7, 0\n"
        "dsra32     $7, $7, 0\n"
        "daddu     $2, $7, $0\n"
        : "+r"(a0) :  : "$2", "$3", "$5", "$6", "$7");
}

void func_002B3D68(u32 a0)
{
    __asm__ volatile(
        "daddu      $6, $4, $0\n"
        "qmtc2.ni   $6, $vf30\n"
        "lui        $3, (0x3F800000 >> 16)\n"
        "lui        $5, (0x3FF19120 >> 16)\n"
        "ori        $5, $5, (0x3FF19120 & 0xFFFF)\n"
        "vrnext.xyzw $vf31, R\n"
        "vitof0.x   $vf30, $vf30\n"
        "qmtc2.ni   $3, $vf29\n"
        "qmtc2.ni   $5, $vf27\n"
        "vsub.x     $vf31, $vf31, $vf29\n"
        "vsubx.w    $vf25, $vf31, $vf27x\n"
        "vmul.x     $vf30, $vf31, $vf30\n"
        "vftoi0.x   $vf30, $vf30\n"
        "qmfc2.ni   $7, $vf30\n"
        "vrinit     R, $vf25w\n"
        "daddu     $2, $7, $0\n"
        :  : "r"(a0) : "$2", "$3", "$5", "$6", "$7");
}

void func_002B3DB0(float f12, float f0)
{
    __asm__ volatile(
        "mfc1       $2, $f12\n"
        "lui        $3, (0x40000000 >> 16)\n"
        "lui        $4, (0x40400000 >> 16)\n"
        "lui        $5, (0x3FF19120 >> 16)\n"
        "ori        $5, $5, (0x3FF19120 & 0xFFFF)\n"
        "vrnext.xyzw $vf31, R\n"
        "qmtc2.ni   $2, $vf30\n"
        "qmtc2.ni   $3, $vf29\n"
        "qmtc2.ni   $4, $vf28\n"
        "qmtc2.ni   $5, $vf27\n"
        "vmul.x     $vf31, $vf31, $vf29\n"
        "vsubx.w    $vf25, $vf31, $vf27x\n"
        "vsub.x     $vf31, $vf31, $vf28\n"
        "vmul.x     $vf31, $vf31, $vf30\n"
        "qmfc2.ni   $2, $vf31\n"
        "mtc1       $2, $f0\n"
        "vrinit    R, $vf25w\n"
        :  :  : "$2", "$3", "$4", "$5");
}

void func_002B3DF8(float f12, float f0)
{
    __asm__ volatile(
        "mfc1       $2, $f12\n"
        "lui        $3, (0x3F800000 >> 16)\n"
        "lui        $5, (0x3FF19120 >> 16)\n"
        "ori        $5, $5, (0x3FF19120 & 0xFFFF)\n"
        "vrnext.xyzw $vf31, R\n"
        "qmtc2.ni   $2, $vf30\n"
        "qmtc2.ni   $3, $vf29\n"
        "qmtc2.ni   $5, $vf27\n"
        "vsub.x     $vf31, $vf31, $vf29\n"
        "vsubx.w    $vf25, $vf31, $vf27x\n"
        "vmul.x     $vf31, $vf31, $vf30\n"
        "qmfc2.ni   $2, $vf31\n"
        "mtc1       $2, $f0\n"
        "vrinit    R, $vf25w\n"
        :  :  : "$2", "$3", "$5");
}

INCLUDE_ASM("build/ee_asm/game/op/op_2B33F8", func_002B3E38);

/* DEBT(CAST) */
void func_002B3EA8(void *arg0, u16 arg1, u16 arg2, s32 arg3) {
    s32 ffff;
    MMI_SQ_ZERO(0, arg0);
    __asm__("ori %0, $0, 0xffff" : "=r"(ffff));
    (*(s16 *)((u8 *)(arg0) + (0))) = arg1;
    (*(s16 *)((u8 *)(arg0) + (2))) = arg2;
    (*(s16 *)((u8 *)(arg0) + (4))) = arg3;
    (*(s16 *)((u8 *)(arg0) + (6))) = ffff;
}

void func_002B3ED0(ObjH4 *o, int q, u16 r)
{
    int i;

    for (i = 0; i < o->n; i++) {
        op_mfifo_set(o, q, 0, r);
    }
}

INCLUDE_ASM("build/ee_asm/game/op/op_2B33F8", op_mfifo_set);

extern char D_00575C00[];
extern char D_00575C28[];
void func_002B40E8(int *p, int b, int size)
{
    int n = size / 32;

    func_00120108(D_00575C00, size, b, p);
    for (; n > 0; n--, p += 8) {
        func_00120108(D_00575C28, p[0], p[1], p[2], p[3], p[4], p[5], p[6], p[7]);
    }
}

void func_002B4190(s32 a, s32 b) {
    func_002B40E8(a, b, 0x100);
}

void func_002B4198(s32 a, s32 b) {
    func_002B40E8(a, b, 0x80);
}

void func_002B41A0(s32 a, s32 b) {
    func_002B40E8(a, b, 0x40);
}

void func_002B41A8(s32 a, s32 b) {
    func_002B40E8(a, b, 0x20);
}

INCLUDE_ASM("build/ee_asm/game/op/op_2B33F8", func_002B41B0);

void func_002B4220(s32 a) {
    if (D_00764990.primary) {
        func_20662E8(a);
    }
    if (D_00764990.mirror) {
        func_20662E8(a);
    }
}

void func_002B4280(s32 a) {
    if (D_00764990.primary) {
        func_20663D0(a);
    }
    if (D_00764990.mirror) {
        func_20663D0(a);
    }
}

void func_002B42E0(s32 a) {
    if (D_00764990.primary) {
        func_2066450(a);
    }
    if (D_00764990.mirror) {
        func_2066450(a);
    }
}

void func_002B4340(void) {
    if (D_00764990.primary) {
        func_2066460();
    }
    if (D_00764990.mirror) {
        func_2066460();
    }
}

void func_002B4390(s32 a, s32 b) {
    if (D_00764990.primary) {
        func_20675D8(a, b);
    }
    if (D_00764990.mirror) {
        func_20675D8(a, b);
    }
}

void func_002B4400(s32 a) {
    if (D_00764990.primary) {
        func_2067610(a);
    }
    if (D_00764990.mirror) {
        func_2067610(a);
    }
}

void func_002B4460(s32 a) {
    if (D_00764990.primary) {
        func_2067700(a);
    }
    if (D_00764990.mirror) {
        func_2067700(a);
    }
}

void func_002B44C0(s32 a) {
    if (D_00764990.primary) {
        func_2067808(a);
    }
    if (D_00764990.mirror) {
        func_2067808(a);
    }
}

void func_002B4520(s32 a) {
    if (D_00764990.primary) {
        func_20679D8(a);
    }
    if (D_00764990.mirror) {
        func_20679D8(a);
    }
}

void func_002B4580(s8 a) {
    if (D_00764990.primary) {
        func_20675F0(a);
    }
    if (D_00764990.mirror) {
        func_20675F0(a);
    }
}

void func_002B45E0(void)
{
    if (D_00764990.primary) {
        func_2067600();
    }
    if (D_00764990.mirror) {
        func_2067600();
    }
}
