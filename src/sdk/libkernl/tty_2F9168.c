#include "common.h"
#include "ffx/v7.h"
#include "ffx/u5.h"
extern char D_00791630[], D_00578AF8[];
extern void func_002F8310(int),func_002F8290(int),func_002F8350(int);
extern int func_002FA4A8(const char *, ...);
extern void func_002F83F0(int);
void func_002F9168(void *arg)
{
    V7CharQ *queue = arg;
    for (;;) {
        int index;
        func_002F8420(D_00791A30);
        index = queue->w0 & 511;
        queue->w0 = index + 1;
        switch (queue->ent[index].flag) {
        case 0: func_002F8310(queue->ent[index].c); break;
        case 1: func_002F8290(queue->ent[index].c); break;
        case 2: func_002F8350(queue->ent[index].c); break;
        default: func_002FA4A8(D_00578AF8); break;
        }
    }
}
int func_002F9240(void)
{
    ThreadParam thread;
    SemaParam sema;
    if (D_00568DE0 > 0) return -1;
    sema.maxCount = 255;
    sema.initCount = 0;
    D_00791A30 = func_002F83E0(&sema);
    if (D_00791A30 < 0) return -1;
    thread.entry = func_002F9168;
    thread.stack = D_00791630;
    thread.stackSize = 0x400;
    thread.gpReg = D_00584670;
    thread.initPriority = 0;
    D_00568DE0 = func_002F81E0(&thread);
    if (D_00568DE0 < 0) {
        func_002F83F0(D_00791A30);
        return -1;
    }
    D_00791A38.w0 = 0;
    D_00791A38.count = 0;
    func_002F8200(D_00568DE0, &D_00791A38);
    func_002F8270(func_002F82D0(), 1);
    return D_00568DE0;
}
