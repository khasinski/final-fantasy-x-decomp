/* Shared 09053-family helper (TU rank 23, 215 containers): sound/event sequence step. */
#include "p8_overlay.h"

typedef struct {
    int type;
    int arg1;
    s16 arg2;
    s16 arg3;
} P8SeqCmd;

typedef struct {
    u8 pad00[0x10];
    P8List list;
    void *w20;
    P8SeqCmd *cmds;
    int pc;
    int wait;
    u16 flags;
} P8Seq;

extern int func_01B03840(void *, int, P8Seq *, int);
extern void func_01B037B0(void *, int, int, int);
extern void func_01B037F8(void *, int, P8Seq *, int);

int func_01B038E8(P8Seq *seq)
{
    P8SeqCmd *cmd;
    P8List *list;
    int cont;
    int ret;

    if (seq->wait > 0) {
        seq->wait--;
    }
    list = &seq->list;
    list->cur = list->head;
    while ((cmd = (P8SeqCmd *)func_01B04AD8(list)) != 0) {
        if (func_01B03840(seq->w20, cmd->arg1, seq, cmd->arg3) == 1) {
            func_01B04948(list, cmd);
        }
        if (cmd == (P8SeqCmd *)func_01B04AD8(list)) {
            func_01B04A78(list);
        }
    }
    if (seq->wait == 0) {
        cont = 1;
        do {
            cmd = &seq->cmds[seq->pc++];
            switch (cmd->type) {
            case 0:
                func_01B037B0(seq->w20, cmd->arg1, cmd->arg2, cmd->arg3);
                break;
            case 2:
                func_01B047E8(list, cmd);
            case 1:
                func_01B037F8(seq->w20, cmd->arg1, seq, cmd->arg3);
                break;
            case 3:
                seq->wait = cmd->arg1;
                cont = 0;
                break;
            case 5:
                seq->pc--;
                seq->flags |= 0x8000;
                cont = 0;
                break;
            case 4:
                break;
            }
        } while (cont != 0);
    }
    ret = seq->flags >> 15;
    if (ret == 1 && list->count == 0) {
        seq->flags |= 0x4000;
    }
    return ret;
}
