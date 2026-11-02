/* tu_371 0x2fac88-0x2fbbe8: medium; unk_2FAC88 (config/tu_map.tsv) */
#include "common.h"
#include "ffx/r7.h"
#include "ffx/q7.h"
#include "ffx/w11.h"
#include "ffx/v7.h"
#include "ffx/u5.h"

INCLUDE_ASM("build/ee_asm/sdk/libkernl/libkernl_2FAC88", func_002FAC88);

INCLUDE_ASM("build/ee_asm/sdk/libkernl/libkernl_2FAC88", func_002FAE28);

INCLUDE_ASM("build/ee_asm/sdk/libkernl/libkernl_2FAC88", func_002FAE50);

INCLUDE_ASM("build/ee_asm/sdk/libkernl/libkernl_2FAC88", func_002FAEF8);

INCLUDE_ASM("build/ee_asm/sdk/libkernl/libkernl_2FAC88", func_002FAF18);

INCLUDE_ASM("build/ee_asm/sdk/libkernl/libkernl_2FAC88", func_002FAF48);

INCLUDE_ASM("build/ee_asm/sdk/libkernl/libkernl_2FAC88", func_002FAF88);

INCLUDE_ASM("build/ee_asm/sdk/libkernl/libkernl_2FAC88", func_002FB040);

INCLUDE_ASM("build/ee_asm/sdk/libkernl/libkernl_2FAC88", func_002FB0A0);

INCLUDE_ASM("build/ee_asm/sdk/libkernl/libkernl_2FAC88", func_002FB1F8);

INCLUDE_ASM("build/ee_asm/sdk/libkernl/libkernl_2FAC88", func_002FB248);

INCLUDE_ASM("build/ee_asm/sdk/libkernl/libkernl_2FAC88", func_002FB2F8);

INCLUDE_ASM("build/ee_asm/sdk/libkernl/libkernl_2FAC88", func_002FB438);

/* Module: EE kernel/syscall wrapper library, SIO, misc libc */

INCLUDE_ASM("build/ee_asm/sdk/libkernl/libkernl_2FAC88", func_002FB4C8);

int func_002FB6B8(void *arg)
{
    SifClientData *client = arg;
    SifRpcPkt *pkt = client->pkt;

    if (pkt == 0 || client->rpc_id != pkt->rpc_id || !(pkt->rec_id & 1)) {
        return 0;
    }
    return 1;
}

void func_002FB6F8(SifQueueData *queue, s32 key)
{
    SifQueueData *next;
    SifQueueData *cursor;
    SifQueueData *tail;

    func_00300280();
    queue->key = key;
    queue->active = 0;
    queue->link = 0;
    queue->start = 0;
    queue->end = 0;
    queue->next = 0;
    if (D_00793D40.active_queue == 0)
    {
        D_00793D40.active_queue = queue;
    }
    else
    {
        tail = D_00793D40.active_queue;
        cursor = tail->next;
        if (cursor != 0)
        {
            do
            {
                tail = cursor;
                next = tail->next;
                cursor = next;
            } while (next != 0);
        }
        tail->next = queue;
    }
    func_003002C8();
}

void func_002FB790(SifServeData *server, u32 command,
    void *(*func)(u32, void *, int), void *buffer,
    void *(*cfunc)(u32, void *, int), void *cbuffer, SifQueueData *queue)
{
    SifServeData *first;
    SifServeData *tail;
    SifServeData *next;
    SifServeData *current;

    func_00300280();
    /* DEBT(CAST): registration uses the generic pointer view of link storage. */
    *(void **)&server->next = 0;
    *(void **)&server->link = 0;
    server->command = command;
    /* DEBT(CAST): same generic link view as the server initialization above. */
    first = *(void **)&queue->link;
    server->func = func;
    server->buff = buffer;
    server->cfunc = cfunc;
    server->cbuff = cbuffer;
    server->base = queue;
    if (first == 0) {
        queue->link = server;
    } else {
        tail = first;
        next = tail->link;
        if (next != 0) {
            do {
                tail = next;
                current = tail->link;
                next = current;
            } while (current != 0);
        }
        tail->link = server;
    }
    func_003002C8();
}

SifServeData *func_002FB860(SifServeData *sd, SifQueueData *qd)
{
    SifServeData *s;

    func_00300280();
    s = qd->link;
    if (s == sd) {
        qd->link = s->link;
    } else {
        while (s != 0) {
            if (s->link == sd) {
                s->link = sd->link;
                break;
            }
            s = s->link;
        }
    }
    func_003002C8();
    return s;
}

SifQueueData *func_002FB8F8(SifQueueData *qd)
{
    SifQueueData *q;

    func_00300280();
    q = D_00793D40.active_queue;
    if (q == qd) {
        D_00793D40.active_queue = q->next;
    } else {
        while (q != 0) {
            if (q->next == qd) {
                q->next = qd->next;
                break;
            }
            q = q->next;
        }
    }
    func_003002C8();
    return q;
}

SifServeData *func_002FB988(SifQueueData *qd)
{
    SifServeData *sd;

    func_00300280();
    sd = qd->start;
    if (sd == 0) {
        qd->active = 0;
    } else {
        qd->active = 1;
        qd->start = sd->next;
    }
    func_003002C8();
    return sd;
}

INCLUDE_ASM("build/ee_asm/sdk/libkernl/libkernl_2FAC88", func_002FB9E0);

void func_002FBBA8(SifQueueData *qd)
{
    SifServeData *sd;

    while (1) {
        while ((sd = func_002FB988(qd)) != 0) {
            func_002FB9E0(sd);
        }
        func_002F8300();
    }
}
