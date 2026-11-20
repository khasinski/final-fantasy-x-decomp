/* Shared 09053-family helper (TU rank 13, 215 containers): motion script step. */
#include "p8_overlay.h"

typedef struct {
    int cmd;
    int arg;
} P8MotCmd;

typedef struct {
    P8MotCmd *cmds;
    void *w04;
    void *w08;
    void *w0C;
    int pc;
    int done;
    s16 wait;
    u16 timer;
    s16 kind;
} P8MotCtrl;

extern void *D_01B00788;
extern int func_001CE1A8(void *);
extern int func_001127F0(void *);
extern void func_01B03520(P8MotCtrl *, int);
extern void func_00110AC0(void *, int);
extern void func_01B022C0(void *);
extern void func_001CDD38(void *);
extern int func_001CE050(void *, int);
extern void func_00110378(void *);
extern void func_00105E50(void *, int);
extern void func_001051A0(void *, int, int);
extern int func_00105938(void *);
extern void func_01B03528(P8MotCtrl *, int);

int func_01B03288(P8MotCtrl *m)
{
    int ready;
    P8MotCmd *c;
    int wait_val;

    if (m->done == 1) {
        return 1;
    }
    if (m->wait == 0) {
        m->timer++;
        if (m->kind == 0) {
            ready = func_001CE1A8(m->w08);
        } else {
            int r = 1;
            if (func_001127F0(m->w0C) != 0) {
                r = 0;
            }
            ready = r;
        }
    } else {
        m->wait--;
        ready = (m->wait == 0);
    }
    if (!ready) {
        return m->done;
    }
loop:
    c = &m->cmds[++m->pc];
    switch (c->cmd) {
    case -2:
        func_01B03520(m, c->arg);
        goto loop;
    case -3:
        func_00110AC0(m->w0C, 0);
        goto loop;
    case -4:
        func_01B022C0(m->w04);
        goto loop;
    case -5:
        func_001CDD38(D_01B00788);
        wait_val = 1;
        break;
    case -1:
        wait_val = 1;
        break;
    default:
        switch (m->kind) {
        case 0:
            wait_val = func_001CE050(m->w08, c->cmd);
            break;
        case 1:
            func_00110378(m->w0C);
            func_00105E50(m->w0C, c->cmd);
            wait_val = func_00105938(m->w0C);
            break;
        case 2:
            func_00110378(m->w0C);
            func_001051A0(m->w0C, 1, c->cmd);
            wait_val = func_00105938(m->w0C);
            break;
        default:
            wait_val = 1;
            break;
        }
        break;
    }
    switch (c->arg) {
    case -1:
        func_01B03528(m, 0);
        break;
    case -2:
        m->wait = 0;
        m->timer = 0;
        break;
    case -3:
        func_01B03528(m, 1);
        break;
    case -4:
        m->done = 1;
        break;
    case -5:
        func_01B03528(m, 3);
        break;
    case -6:
        func_01B03528(m, 2);
        break;
    case -7:
        if (wait_val <= 0) {
            if (m->kind == 0) {
                wait_val = func_001CE050(m->w08, 0x10);
                if (wait_val <= 0) {
                    wait_val = 1;
                }
            } else {
                wait_val = 1;
            }
        }
        m->wait = wait_val;
        m->pc--;
        break;
    default:
        m->wait = c->arg;
        break;
    }
    return m->done;
}
