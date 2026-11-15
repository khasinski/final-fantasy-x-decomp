#include "common.h"

typedef struct {
    int id;
    int value;
} KernelPatch;

extern KernelPatch D_00568DA0[8];
extern char D_00568638[], D_00568D78[];

/* Typed interfaces to the handwritten kernel syscall wrappers. */
extern void func_002F9028(int id, int value);
extern void func_002F9038(void *dst, void *src, int size);
extern void func_002F8660(int mode);
extern int func_002F9080(int id);

void func_002F9090(void)
{
    unsigned int i;

    if (!(*(volatile unsigned int *)0x10001810 & 0x100)) {
        func_002F9028(D_00568DA0[0].id, D_00568DA0[0].value);
        func_002F9038((void *)0x80076000, D_00568638, 0x740);
        func_002F9038((void *)0x82000, D_00568D78, 0x28);
        func_002F8660(0);
        func_002F8660(2);
        func_002F9028(D_00568DA0[1].id, D_00568DA0[1].value);
        for (i = 2; i < 8; i++) {
            func_002F9028(D_00568DA0[i].id, func_002F9080(D_00568DA0[i].id));
        }
    }
}
