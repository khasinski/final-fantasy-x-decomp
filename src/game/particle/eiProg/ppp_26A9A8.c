/* tu_289 0x26a9a8-0x26ac38: low; ~ppp (config/tu_map.tsv) */
#include "common.h"
#include "ffx/r6.h"
#include "ffx/w9.h"
#include "ffx/w8.h"
#include "ffx/q6.h"
#include "ffx/u4.h"
#include "ffx/v6.h"

void func_0026A9A8(int a0)
{
    D_006A3BC4 = a0;
}

void pppDumpHeap(R6BlkHead *h) {
    R6Blk *b = h->first;

    do {
        func_002EF240(D_005741D0, b->w8, b, b->next, b->w4, (int)b->next - (int)b);
        b = b->next;
    } while (b != 0);
}

void pppCreateHeap(HHead *h, HBlk *buf, int size)
{
    HBlk *end = (HBlk *)((char *)buf + size) - 1;

    /* DEBT(ORDER): store order chosen to reproduce the schedule */
    buf->next = end;
    h->first = buf;
    buf->prev = 0;
    buf->used = 0;
    end->prev = buf;
    h->last = end;
    h->cur = 0;
    end->next = 0;
    end->used = 1;
    h->used = 0;
}

void *pppAlloc(HHead *h, int size)
{
    HBlk *b;
    HBlk *n;
    HBlk *nb;

    size = ((size + 15) & 0xFFFFFFF0) + sizeof(HBlk);
    /* DEBT(GOTO): the search loop is entered from three places (layout of the original) */
    if (h->cur == 0) {
        goto init;
    }
    b = h->cur->next;
    goto search;
wrap:
    b = h->last;
    h->cur = 0;
    goto search;
init:
    b = h->first->next;
    h->cur = h->first;
search:
    for (;;) {
        if (b->prev == 0) {
            if (h->cur != 0) {
                goto wrap;
            }
            return 0;
        }
        b = b->prev;
        if (b->used == 0) {
            n = b->next;
            if ((char *)n - (char *)b >= size) {
                h->used += size;
                nb = (HBlk *)((char *)n - size);
                if (nb != b && (u32)((char *)nb - (char *)b) >= 16) {
                    nb->prev = b;
                    nb->next = n;
                    n->prev = nb;
                    h->cur = b;
                    b->next = nb;
                    b = nb;
                } else {
                    h->cur = 0;
                }
                b->used = 1;
                return b + 1;
            }
        }
    }
}

int pppFree(HHead *h, HBlk *p) /* DEBT(TYPE): returns no value, but func_00267028 returns its result */
{
    HBlk *b = p - 1;
    HBlk *prev;
    HBlk *next;

    b->used = 0;
    h->used -= (char *)b->next - (char *)b;
    h->cur = b;
    prev = b->prev;
    if (prev != 0 && prev->used == 0) {
        prev->next = b->next;
        next = b->next;
        next->prev = prev;
        b = prev;
    }
    next = b->next;
    if (next->used == 0) {
        b->next = next->next;
        next = next->next;
        next->prev = b;
    }
}

void func_0026AB90(void) {
}

void func_0026AB98(void) {
}

void func_0026ABA0(void) {
}

void func_0026ABA8(void) {
}

void func_0026ABB0(void) {
}

void func_0026ABB8(void) {
}

void func_0026ABC0(void) {
}

void func_0026ABC8(void) {
}

void func_0026ABD0(void) {
}

void func_0026ABD8(char *base, EvW4 *ev, ScriptCtx *ctx)
{
    void (**tbl)(char *, int) = D_006A3BC8;
    void (*fn)(char *, int);

    *SLOT_WORK(int, base, ctx, 0) = ev->w4;
    if (tbl != 0) {
        fn = tbl[((ScrMemE *)base)->info->bE]; /* DEBT(CAST): base is the script memory header */
        if (fn != 0) {
            fn(base, ev->w4);
        }
    }
}
