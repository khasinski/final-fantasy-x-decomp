/* tu_371 0x2fac88-0x2fbbe8: medium; unk_2FAC88 (config/tu_map.tsv) */
#define func_002FAE28 _hdr_func_002FAE28
#include "common.h"
#include "ffx/r7.h"
#include "ffx/q7.h"
#include "ffx/w11.h"
#include "ffx/v7.h"
#include "ffx/u5.h"
#undef func_002FAE28

INCLUDE_ASM("build/ee_asm/sdk/libkernl/libkernl_2FAC88", func_002FAC88);

void _m2c_func_002FAE28_func_002FA838() __asm__("func_002FA838");
extern s32 _m2c_func_002FAE28_D_00568DF0 __asm__("D_00568DF0");
void func_002FAE28(void) {
    _m2c_func_002FAE28_func_002FA838();
    _m2c_func_002FAE28_D_00568DF0 = 0;
}

SifRpcPkt *func_002FAE50(SifRpcState *rd) {
    SifRpcPkt *p;
    s32 i;
    s32 id;

    func_00300280();
    p = rd->pkt_table;
    for (i = 0; i < rd->pkt_table_len; i++, p++) {
        if (!(p->rec_id & 1)) {
            p->rec_id = (i << 16) | 5;
            rd->pid++;
            if (rd->pid == 1) {
                rd->pid++;
                id = 1;
            } else {
                id = rd->pid;
            }
            p->pkt_addr = p;
            p->rpc_id = id;
            func_003002C8();
            return p;
        }
    }
    func_003002C8();
    return 0;
}

void func_002FAEF8(SifRpcPkt *pkt) {
    pkt->rpc_id = 0;
    pkt->rec_id &= 0xFFFFFFFE;
}

/* DEBT(CAST) */ /* DEBT(FAKE) */
SifRpcPkt *func_002FAF18(SifRpcState *rd) {
    register s32 temp_hi __asm__("$2");
    register s32 next __asm__("$3");
    register SifRpcPkt *tbl __asm__("$5");

    temp_hi = (s32) rd->rdata_table_idx % (s32) rd->rdata_table_len;
    tbl = rd->rdata_table;
    __asm__("" : "+r"(tbl));
    next = temp_hi + 1;
    __asm__("" : "+r"(next));
    temp_hi <<= 6;
    __asm__("" : "+r"(temp_hi));
    rd->rdata_table_idx = next;
    return (SifRpcPkt *)((u8 *)tbl + temp_hi);
}

SifRpcPkt *func_002FAF48(SifRpcState *rd, int idx) {
    if (idx < 0 || idx >= rd->client_table_len) {
        return func_002FAF18(rd);
    }
    return (SifRpcPkt *)(rd->client_table + idx * 0x40);
}

void func_002F8410(s32);
void func_002FAF88(SifRpcPkt *pkt) {
    SifClientData *cd;

    switch (pkt->command) {
    case 0x8000000A:
        cd = (SifClientData *)pkt->client;
        if (cd->end_func != 0) {
            cd->end_func(cd->end_param);
        }
        break;
    case 0x80000009:
        cd = (SifClientData *)pkt->client;
        ((s32 *)cd)[9] = ((s32 *)pkt)[9];
        ((s32 *)cd)[5] = ((s32 *)pkt)[10];
        ((s32 *)cd)[6] = ((s32 *)pkt)[11];
        break;
    case 0x8000000B:
        break;
    }
    cd = (SifClientData *)pkt->client;
    if (cd->sema >= 0) {
        func_002F8410(cd->sema);
    }
    func_002FAEF8(cd->pkt);
    cd->pkt = 0;
}

void _m2c_func_002FB040_func_002FAA70(s32, void *, s32, s32, s32, s32) __asm__("func_002FAA70");
/* DEBT(CAST) */
void func_002FB040(void *arg0, SifRpcState *arg1) {
    SifRpcPkt *temp_2;
    s32 a1;
    s32 a0;

    temp_2 = func_002FAF18(arg1);
    a1 = (*(s32 *)((u8 *)(arg0) + (0x14)));
    a0 = (*(s32 *)((u8 *)(arg0) + (0x1C)));
    (*(s32 *)((u8 *)(temp_2) + (0x14))) = a1;
    (*(s32 *)((u8 *)(temp_2) + (0x1C))) = a0;
    (*(s32 *)((u8 *)(temp_2) + (0x20))) = 0x8000000C;
    _m2c_func_002FB040_func_002FAA70(0x80000008, temp_2, 0x40, (*(s32 *)((u8 *)(arg0) + (0x20))), (*(s32 *)((u8 *)(arg0) + (0x24))), (*(s32 *)((u8 *)(arg0) + (0x28))));
}

INCLUDE_ASM("build/ee_asm/sdk/libkernl/libkernl_2FAC88", func_002FB0A0);

SifServeData *func_002FB1F8(u32 command, SifRpcState *rd) {
    SifQueueData *q;
    SifServeData *s;

    for (q = rd->active_queue; q != 0; q = q->next) {
        for (s = q->link; s != 0; s = s->link) {
            if (s->command == command) {
                return s;
            }
        }
    }
    return 0;
}

void func_002FB248(SifRpcPkt *pkt, SifRpcState *rd) {
    s32 *r;
    s32 *sd;
    s32 a0;
    s32 v1;

    r = (s32 *)func_002FAF18(rd);
    a0 = ((s32 *)pkt)[5];
    v1 = ((s32 *)pkt)[7];
    r[7] = v1;
    r[5] = a0;
    r[8] = 0x80000009;
    sd = (s32 *)func_002FB1F8(pkt->command, rd);
    if (sd == 0) {
        r[9] = 0;
        r[10] = 0;
        r[11] = 0;
    } else {
        r[9] = (s32)sd;
        r[10] = sd[2];
        r[11] = sd[5];
    }
    _m2c_func_002FB040_func_002FAA70(0x80000008, r, 0x40, 0, 0, 0);
}

INCLUDE_ASM("build/ee_asm/sdk/libkernl/libkernl_2FAC88", func_002FB2F8);

void func_002F9318(s32);
void func_002FB438(SifRpcPkt *pkt) {
    s32 *p = (s32 *)pkt;
    s32 *sd = (s32 *)pkt->server;
    s32 *q = (s32 *)((SifServeData *)sd)->base;

    if (q[3] == 0) {
        q[3] = (s32)sd;
    } else {
        ((SifServeData *)q[4])->next = (SifServeData *)sd;
    }
    q[4] = (s32)sd;
    ((SifServeData *)sd)->paddr = pkt->pkt_addr;
    sd[7] = p[7];
    sd[9] = p[8];
    sd[3] = p[9];
    sd[10] = p[10];
    sd[11] = p[11];
    sd[12] = p[12];
    sd[13] = p[4];
    if (q[0] >= 0 && q[1] == 0) {
        func_002F9318(q[0]);
    }
}

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
