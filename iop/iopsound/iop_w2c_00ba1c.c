#include "iopsound.h"

typedef struct {
    s32 idx;
    s32 id;
    void *data;
    s32 size;
} SepSlot;

typedef struct {
    u32 unk00;
    u32 unk04;
    u32 id;
    s32 size;
} SepReq;

extern SepSlot *D_01938C;
extern char D_016344[];
extern char D_016168[];
extern char D_016200[];
extern char D_016184[];

extern void *func_009948(s32);
extern void func_009360(SepReq *, void *, s32);

void *func_00BA1C(SepReq *req) {
    SepSlot *p;
    void *buf;

    for (p = D_01938C; p->size != 0 && p < D_01938C + 192; p++) {
    }
    if (p >= D_01938C + 192) {
        imp_sysmem_14(D_016344, D_016168, D_016200, D_016184);
        return NULL;
    }
    buf = func_009948(req->size);
    if (buf != NULL) {
        p->data = buf;
        p->size = req->size;
        p->id = req->id | 0x80000000;
        func_009360(req, buf, req->size);
    }
    return buf;
}
