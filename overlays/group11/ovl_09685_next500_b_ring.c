/* Battle-effect overlay 09685: byte-exact C helpers and callbacks. */
#include "common.h"

typedef struct TtEnt {
    int start;
    int len;
    void (*on_start)(int);
    int (*on_run)(int);
    void (*on_end)(int);
    int arg;
} TtEnt;

typedef struct TtRing {
    int frame;
    int n;
    int active;
    struct {
        int on;
        int pad;
    } slot[32];
    TtEnt *tbl;
} TtRing;

int Sg_GetCurExecFrames(void);
void *func_002EF0D0(void *, int, int);
extern char D_01B04560[];
extern char D_01B04570[];
typedef union TtVec
{
    float v[4];
    double d[2];
}
TtVec;

int func_01B02910(char *, ...);
void func_01B02940(char *, ...);
void func_01B03248(TtRing *r, TtEnt *tbl, int n)
{
    int i;

    func_01B02910(D_01B04560);
    if (n > 32) {
        func_01B02940(D_01B04560);
    }
    func_002EF0D0(r, 0, 0x110);
    r->tbl = tbl;
    r->n = n;
    r->active = n;
    for (i = 0; i < n; i++) {
        r->slot[i].on = 1;
    }
}

#define TT_RING_END(r, e, sl)         \
    if ((e)->on_end != 0) {           \
        (e)->on_end((e)->arg);        \
    }                                 \
    *(sl) = 0;                        \
    (r)->active = (r)->active - 1;    \
    if ((r)->active == 0) {           \
        return 0;                     \
    }

int func_01B032F8(TtRing *r)
{
    int i;
    int res;
    TtEnt *e;
    int *sl;

    if (r->active == 0) {
        return 0;
    }
    sl = &r->slot[0].on;
    e = r->tbl;
    for (i = 0; i < r->n; i++, sl += 2, e++) {
        res = 777;
        if (*sl != 0) {
            if (r->frame < e->start) {
                continue;
            }
            if (r->frame == e->start) {
                if (e->on_start != 0) {
                    e->on_start(e->arg);
                }
            }
            if (e->on_run != 0) {
                res = e->on_run(e->arg);
            }
            if (e->len != -1) {
                if (r->frame == e->start + e->len - 1) {
                    TT_RING_END(r, e, sl)
                }
}
else if (res == 0)
{

                TT_RING_END(r, e, sl)
            }
        }
    }
    if (Sg_GetCurExecFrames() == 0) {
        return 1;
    }
    r->frame = r->frame + 1;
    return 1;
}

int func_01B03450(TtRing *r)
{
    int i;
    TtEnt *e;
    int *sl;

    func_01B02910(D_01B04570);

    if (r->active == 0) {
        return 0;
    }
    sl = &r->slot[0].on;
    e = r->tbl;
    for (i = 0; i < r->n; i++, sl += 2, e++) {
        if (*sl != 0) {
            if (e->on_end != 0) {
                e->on_end(e->arg);
            }
            *sl = 0;
            r->active = r->active - 1;
        }
    }
    if (r->active != 0) {
        func_01B02940(D_01B04570);
    }
}
