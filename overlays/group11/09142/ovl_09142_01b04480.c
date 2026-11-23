#include "p9_overlay.h"

typedef struct Ovl09142Entry {
    int id;
    int trigger;
    void (*cb)(void *);
    void *arg;
} Ovl09142Entry;

typedef struct Ovl09142Ctrl {
    Ovl09142Entry *entries;
    void *ctx;
    int idx;
    int total;
} Ovl09142Ctrl;

void func_001051A0(void *ctx, int a1, int id);
int func_00105938(void *ctx);
int func_00111B50(void *ctx);
void func_00110378(void *ctx);

void func_01B04480(Ovl09142Ctrl *ctrl, Ovl09142Entry *entries, void *ctx)
{
    func_002EF0D0(ctrl, 0, sizeof(Ovl09142Ctrl));
    ctrl->entries = entries;
    ctrl->ctx = ctx;
}

void func_01B044D0(Ovl09142Ctrl *ctrl)
{
    Ovl09142Entry *entries = ctrl->entries;
    int flag;

    if (entries[ctrl->idx].id == 0) {
        return;
    }
    if (ctrl->total == 0) {
        func_001051A0(ctrl->ctx, 1, entries[ctrl->idx].id);
        ctrl->total = func_00105938(ctrl->ctx);
        if (ctrl->total == -1) {
            while (entries[ctrl->idx].id != 0) {
                ctrl->idx++;
            }
        }
    }
    flag = 0;
    if (entries[ctrl->idx].trigger == 0) {
        if (ctrl->total == (func_00111B50(ctrl->ctx) >> 8) + 1) {
            flag = 1;
        }
    } else {
        if (entries[ctrl->idx].trigger == (func_00111B50(ctrl->ctx) >> 8) + 1) {
            flag = 1;
        }
    }
    if (flag != 0) {
        ctrl->idx++;
        if (entries[ctrl->idx].id == 0) {
            return;
        }
        func_00110378(ctrl->ctx);
        func_001051A0(ctrl->ctx, 1, entries[ctrl->idx].id);
        ctrl->total = func_00105938(ctrl->ctx);
    }
    if (entries[ctrl->idx].cb != 0) {
        entries[ctrl->idx].cb(entries[ctrl->idx].arg);
    }
}
