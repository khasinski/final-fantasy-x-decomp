/* Shared P6 -O0 helper: light fade cleanup (hash 56790d, 172B). */
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
} P6FadeNode;

typedef struct {
    P6FadeNode *obj;
} P6FadeArg;

extern void func_01B08500(void *);
extern void func_00173650(int *);
extern void func_00173720(float *);
extern void func_00173A38(int *);
extern void func_00173A70(int);
extern void func_00173A90(int);

void func_01B07D40(register P6FadeArg *arg)
{
    float one[4] __attribute__((aligned(16)));
    int amb[4] __attribute__((aligned(16)));

    func_01B08500(arg->obj);
    __asm__ volatile (
        "vaddw.xyz $vf31, $vf0, $vf0\n\t"
        "vmove.w $vf31, $vf0\n\t"
        "sqc2 $vf31, 0x0(%0)\n\t"
        "lqc2 $vf31, 0x0(%2)\n\t"
        "vftoi0.xyzw $vf31, $vf31\n\t"
        "sqc2 $vf31, 0x0(%1)\n\t"
        :
        : "r"(one), "r"(amb), "r"(arg->obj->orig_amb)
        : "memory"
    );
    func_00173650(arg->obj->orig_col);
    func_00173720(one);
    func_00173A90(4);
    func_00173A70(1);
    func_00173A38(amb);
}
