#include "common.h"

typedef struct {
    u8 pad00[0x1C];
    void *p1C;
    void *p20;
    u32 f24;
} Node14148;

typedef struct {
    Node14148 *node;
    void *parent;
    void *p08;
    void *p0C;
} Msg14148;

extern void func_01B14430(Msg14148 *);

void func_01B14148(register Msg14148 *s0)
{
    Node14148 *n = s0->node;
    func_01B14430(s0);
    n->p1C = s0->p08;
    n->p20 = s0->p0C;
    *(u32 *)((u8 *)n + 0x24) = 0x80808080;
}
