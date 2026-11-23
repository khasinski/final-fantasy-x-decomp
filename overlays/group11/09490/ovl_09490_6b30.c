#include "common.h"

typedef struct {
    s32 type;
    s32 arg1;
    s16 arg2;
    s16 arg3;
} Cmd6B30;

typedef struct {
    void *head;
    void *tail;
    void *cur;
    s32 count;
} List6B30;

typedef struct {
    u8 pad00[0x10];
    List6B30 list;
    s32 unk20;
    Cmd6B30 *cmds;
    s32 idx;
    s32 wait;
    u16 flags;
} Ctrl6B30;

extern s32 func_00116068(void);
extern void func_01B069F8(s32, s32, s16, s16);
extern void func_01B06A40(s32, s32, Ctrl6B30 *, s16);
extern s32 func_01B06A88(s32, s32, Ctrl6B30 *, s16);
extern void func_01B07A98(List6B30 *, Cmd6B30 *);
extern void func_01B07BF8(List6B30 *, Cmd6B30 *);
extern void func_01B07D28(List6B30 *);
extern Cmd6B30 *func_01B07D88(List6B30 *);

s32 func_01B06B30(Ctrl6B30 *ctrl) {
    List6B30 *list;
    Cmd6B30 *node;
    s32 loop;
    u16 flags;
    s32 done;

    if (func_00116068() == 0) {
        return 0;
    }
    if (ctrl->wait > 0) {
        ctrl->wait--;
    }

    list = &ctrl->list;
    list->cur = list->head;
    while ((node = func_01B07D88(list)) != 0) {
        if (func_01B06A88(ctrl->unk20, node->arg1, ctrl, node->arg3) == 1) {
            func_01B07BF8(list, node);
        }
        if (node == func_01B07D88(list)) {
            func_01B07D28(list);
        }
    }

    if (ctrl->wait == 0) {
        loop = 1;
        do {
            node = &ctrl->cmds[ctrl->idx++];
            switch (node->type) {
            case 0:
                func_01B069F8(ctrl->unk20, node->arg1, node->arg2, node->arg3);
                break;
            case 2:
                func_01B07A98(list, node);
            case 1:
                func_01B06A40(ctrl->unk20, node->arg1, ctrl, node->arg3);
                break;
            case 3:
                ctrl->wait = node->arg1;
                loop = 0;
                break;
            case 5:
                ctrl->idx--;
                ctrl->flags |= 0x8000;
                loop = 0;
                break;
            case 4:
                break;
            }
        } while (loop != 0);
    }

    flags = ctrl->flags;
    done = flags >> 15;
    if (done == 1 && list->count == 0) {
        ctrl->flags = flags | 0x4000;
    }
    return done;
}
