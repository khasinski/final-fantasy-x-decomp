/* Shared P6 -O0 helper: light fade init (hash dbac5b, 312B). */
#include "p6_overlay.h"

typedef struct {
    u8 pad00[0x20];
    float cur_col[4];       /* 0x20 */
    float dst_col[4];       /* 0x30 */
    float step_col[4];      /* 0x40 */
    float cur_amb[4];       /* 0x50 */
    float dst_amb[4];       /* 0x60 */
    float step_amb[4];      /* 0x70 */
    float orig_amb[4];      /* 0x80 */
    int orig_col[4];        /* 0x90 */
    float rate;             /* 0xA0 */
    float progress;         /* 0xA4 */
    float end_thresh;       /* 0xA8 */
    float dark_thresh;      /* 0xAC */
    u32 flags;              /* 0xB0 */
} P6FadeNode;

typedef struct {
    P6FadeNode *obj;
} P6FadeArg;

extern void func_01B082A8(void *);
extern void func_00173520(int *);
extern void func_00173720(float *);
extern void func_00173888(int *);
extern void func_00173A70(int);

void func_01B07C08(register P6FadeArg *arg)
{
    P6FadeNode *obj = arg->obj;
    int amb[4] __attribute__((aligned(16)));

    func_01B082A8(arg);
    func_00173520(obj->orig_col);
    func_00173888(amb);
    __asm__ volatile (
        "lqc2 $vf31, 0x0(%1)\n\t"
        "vitof0.xyzw $vf30, $vf31\n\t"
        "sqc2 $vf30, 0x0(%2)\n\t"
        "vsub.xyzw $vf31, $vf0, $vf0\n\t"
        "sqc2 $vf31, 0x0(%4)\n\t"
        "sqc2 $vf31, 0x0(%7)\n\t"
        "vaddw.xyz $vf31, $vf0, $vf0\n\t"
        "vmove.w $vf31, $vf0\n\t"
        "sqc2 $vf31, 0x0(%0)\n\t"
        "sqc2 $vf31, 0x0(%3)\n\t"
        "sqc2 $vf31, 0x0(%5)\n\t"
        "sqc2 $vf31, 0x0(%6)\n\t"
        :
        : "r"(obj->cur_amb), "r"(amb), "r"(obj->orig_amb),
          "r"(obj->dst_amb), "r"(obj->step_amb),
          "r"(obj->cur_col), "r"(obj->dst_col), "r"(obj->step_col)
        : "memory"
    );
    func_00173720(obj->cur_col);
    func_00173A70(4);
    obj->flags = 1;
    obj->end_thresh = 1.0f;
    obj->dark_thresh = 0.005f;
    obj->progress = 1.0f;
}
