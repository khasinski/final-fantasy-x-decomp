/* Shared P6 -O0 helper: light fade update (hash 3684a7, 1000B). */
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

extern void func_01B08398(void *);
extern void func_01B084B8(void *);
extern void func_00173650(int *);
extern void func_00173720(float *);
extern void func_00173A38(int *);
extern void func_00173A70(int);
extern void func_00173A90(int);

void func_01B07DF0(register P6Iter *it)
{
    P6FadeNode *obj;
    int col[4] __attribute__((aligned(16)));
    int zero;

    func_01B08398(it);
    if ((it->done & 1) == 0) {
        return;
    }
    obj = (P6FadeNode *)it->cur;
    if ((obj->flags & 1) != 0) {
        __asm__ volatile (
            ".set noreorder\n\t"
            "lqc2 $vf31, 0x0(%0)\n\t"
            "lqc2 $vf30, 0x0(%1)\n\t"
            "lqc2 $vf29, 0x0(%2)\n\t"
            "vsub.xyzw $vf30, $vf30, $vf31\n\t"
            "vmulx.xyzw $vf30, $vf30, $vf29\n\t"
            "vadd.xyzw $vf31, $vf31, $vf30\n\t"
            "sqc2 $vf31, 0x0(%0)\n\t"
            "lqc2 $vf31, 0x0(%3)\n\t"
            "lqc2 $vf30, 0x0(%4)\n\t"
            "vsub.xyzw $vf30, $vf30, $vf31\n\t"
            "vmulx.xyzw $vf30, $vf30, $vf29\n\t"
            "vadd.xyzw $vf31, $vf31, $vf30\n\t"
            "sqc2 $vf31, 0x0(%3)\n\t"
            "vsuby.w $vf31, $vf0, $vf29\n\t"
            "vmulw.x $vf31, $vf29, $vf31\n\t"
            "vaddx.y $vf29, $vf29, $vf31\n\t"
            "sqc2 $vf29, 0x0(%2)\n\t"
            ".set reorder\n\t"
            :
            : "r"(obj->cur_col), "r"(obj->dst_col), "r"(&obj->rate),
              "r"(obj->cur_amb), "r"(obj->dst_amb)
            : "memory"
        );
    } else {
        obj->progress += obj->rate;
        if (obj->progress >= 1.0f) {
            obj->progress = 1.0f;
            __asm__ volatile (
                ".set noreorder\n\t"
                "lqc2 $vf31, 0x0(%1)\n\t"
                "lqc2 $vf30, 0x0(%3)\n\t"
                "sqc2 $vf31, 0x0(%0)\n\t"
                "sqc2 $vf30, 0x0(%2)\n\t"
                ".set reorder\n\t"
                :
                : "r"(obj->cur_col), "r"(obj->dst_col),
                  "r"(obj->cur_amb), "r"(obj->dst_amb)
                : "memory"
            );
        } else {
            __asm__ volatile (
                "lqc2 $vf31, 0x0(%0)\n\t"
                "lqc2 $vf30, 0x0(%1)\n\t"
                "lqc2 $vf29, 0x0(%2)\n\t"
                "vmulx.xyzw $vf30, $vf30, $vf29\n\t"
                "vadd.xyzw $vf31, $vf31, $vf30\n\t"
                "sqc2 $vf31, 0x0(%0)\n\t"
                "lqc2 $vf31, 0x0(%3)\n\t"
                "lqc2 $vf30, 0x0(%4)\n\t"
                "vmulx.xyzw $vf30, $vf30, $vf29\n\t"
                "vadd.xyzw $vf31, $vf31, $vf30\n\t"
                "sqc2 $vf31, 0x0(%3)\n\t"
                :
                : "r"(obj->cur_col), "r"(obj->step_col), "r"(&obj->rate),
                  "r"(obj->cur_amb), "r"(obj->step_amb)
                : "memory"
            );
        }
    }
    func_00173720(obj->cur_col);
    col[0] = (int)((float)obj->orig_col[0] * obj->cur_col[0]);
    col[1] = (int)((float)obj->orig_col[1] * obj->cur_col[1]);
    col[2] = (int)((float)obj->orig_col[2] * obj->cur_col[2]);
    col[3] = (int)((float)obj->orig_col[3] * obj->cur_col[3]);
    func_00173650(col);
    __asm__ volatile (
        "lqc2 $vf31, 0x0(%1)\n\t"
        "lqc2 $vf30, 0x0(%2)\n\t"
        "vmul.xyzw $vf31, $vf31, $vf30\n\t"
        "vftoi0.xyzw $vf31, $vf31\n\t"
        "sqc2 $vf31, 0x0(%0)\n\t"
        :
        : "r"(col), "r"(obj->cur_amb), "r"(obj->orig_amb)
        : "memory"
    );
    func_00173A38(col);
    if ((obj->flags & 2) != 0) {
        if (obj->cur_col[0] < obj->dark_thresh &&
            obj->cur_col[1] < obj->dark_thresh &&
            obj->cur_col[2] < obj->dark_thresh) {
            func_00173A90(1);
            obj->flags &= ~2;
        }
    } else {
        if (obj->cur_col[0] >= obj->dark_thresh &&
            obj->cur_col[1] >= obj->dark_thresh &&
            obj->cur_col[2] >= obj->dark_thresh) {
            func_00173A70(1);
            obj->flags |= 2;
        }
    }
    if ((obj->flags & 4) != 0) {
        if (obj->progress >= obj->end_thresh) {
            func_01B084B8(obj);
        }
    }
    zero = 0;
}
