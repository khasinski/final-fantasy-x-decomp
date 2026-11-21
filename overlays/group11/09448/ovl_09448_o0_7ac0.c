/* Shared P6 -O0 helper: light fade setup (hash 753f2c, 224B). */
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
    P6FadeNode *obj;        /* 0x00 */
    int mode;               /* 0x04 */
    float rate;             /* 0x08 */
} P6FadeSetArg;

void func_01B07AC0(P6FadeSetArg *arg)
{
    P6FadeNode *obj = arg->obj;

    obj->rate = arg->rate;
    obj->progress = 0.0f;
    if (arg->mode != 0) {
        obj->flags |= 1;
    } else {
        obj->flags &= ~1;
        __asm__ volatile (
            "lqc2 $vf31, 0x0(%1)\n\t"
            "lqc2 $vf30, 0x0(%2)\n\t"
            "vsub.xyzw $vf31, $vf31, $vf30\n\t"
            "sqc2 $vf31, 0x0(%0)\n\t"
            "lqc2 $vf31, 0x0(%4)\n\t"
            "lqc2 $vf30, 0x0(%5)\n\t"
            "vsub.xyzw $vf31, $vf31, $vf30\n\t"
            "sqc2 $vf31, 0x0(%3)\n\t"
            :
            : "r"(obj->step_col), "r"(obj->dst_col), "r"(obj->cur_col),
              "r"(obj->step_amb), "r"(obj->dst_amb), "r"(obj->cur_amb)
            : "memory"
        );
    }
}
