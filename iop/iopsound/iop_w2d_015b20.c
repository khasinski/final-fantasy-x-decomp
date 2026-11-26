#include "iopsound.h"

typedef struct {
    void *entry;
    s32 *sema_ptr;
    s32 tid;
    s32 prio;
} S_ThreadDesc;

typedef struct {
    u32 attr;
    u32 option;
    void *entry;
    s32 stackSize;
    s32 initPriority;
} S_ThreadParam;

typedef struct {
    u32 attr;
    u32 option;
    s32 initCount;
    s32 maxCount;
} S_SemaParam;

extern S_ThreadDesc D_0191D4[];
extern S_ThreadDesc D_0191E4[];
extern s32 D_05A118;

s32 func_015B20(void) {
    S_ThreadParam tp;
    S_SemaParam sp;
    S_ThreadDesc *p;
    S_ThreadDesc *p2;
    S_ThreadDesc *q;
    s32 tid;

    imp_loadcore_5();

    p = D_0191E4;
    sp.maxCount = 1;
    sp.attr = 1;
    tp.attr = 0x02000000;
    sp.initCount = 0;
    tp.stackSize = 0x800;
    tp.option = 0;

    do {
        *p->sema_ptr = imp_thsemap_4(&sp);
        tp.entry = p->entry;
        tp.initPriority = p->prio;
        tid = imp_thbase_4(&tp);
        if (tid > 0) {
            imp_thbase_6(tid, 0);
        }
        p->tid = tid;
        p++;
    } while (p < D_0191E4 + 16);

    imp_sifcmd_14(0);

    {
        void *e;
        s32 pr;
        tp.attr = 0x02000000;
        q = D_0191D4;
        e = q->entry;
        pr = q->prio;
        D_05A118 = 0;
        tp.stackSize = 0x800;
        tp.option = 0;
        tp.entry = e;
        tp.initPriority = pr;
    }
    tid = imp_thbase_4(&tp);
    q->tid = tid;
    if (tid > 0) {
        void *e;
        imp_thbase_6(tid, 0);
        e = q[-1].entry;
        p2 = q - 1;
        tp.attr = 0x02000000;
        tp.entry = e;
        tp.initPriority = p2->prio;
        tp.stackSize = 0x800;
        tp.option = 0;
        tid = imp_thbase_4(&tp);
        p2->tid = tid;
        if (tid > 0) {
            imp_thbase_6(tid, 0);
            return 0;
        }
    }
    return 1;
}
