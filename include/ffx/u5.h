#ifndef FFX_U5_H
#define FFX_U5_H

#include "common.h"
#include "ffx/types.h"
#include "ffx/globals.h"
#include "ffx/funcs.h"

/* ---- SIF RPC (EE side of Sony's sifrpc: c_2FA4A8, c_2FB4C8) ---- */

/* 0x40-byte SIF command packet as used by the RPC layer */
typedef struct SifRpcPkt {
    u32 size;                   /* 0x00 psize:8 dsize:24 */
    void *dest;                 /* 0x04 */
    s32 cid;                    /* 0x08 */
    u32 opt;                    /* 0x0C */
    u32 rec_id;                 /* 0x10 bit 0: in use, bits 16..: table index */
    struct SifRpcPkt *pkt_addr; /* 0x14 */
    s32 rpc_id;                 /* 0x18 */
    void *client;               /* 0x1C */
    u32 command;                /* 0x20 rpc number */
    s32 send_size;              /* 0x24 */
    void *recv;                 /* 0x28 */
    s32 recv_size;              /* 0x2C */
    s32 rmode;                  /* 0x30 */
    void *server;               /* 0x34 */
    u8 pad38[8];
} SifRpcPkt;

typedef struct SifClientData {
    SifRpcPkt *pkt;             /* 0x00 */
    s32 rpc_id;                 /* 0x04 */
    s32 sema;                   /* 0x08 */
    u32 mode;                   /* 0x0C */
    u32 command;                /* 0x10 */
    void *buff;                 /* 0x14 */
    void *cbuff;                /* 0x18 */
    void (*end_func)(void *);   /* 0x1C */
    void *end_param;            /* 0x20 */
    void *serve;                /* 0x24 */
} SifClientData;

struct SifQueueData;

typedef struct SifServeData {
    u32 command;                /* 0x00 */
    void *(*func)(u32 fno, void *buff, int size); /* 0x04 */
    void *buff;                 /* 0x08 */
    s32 size;                   /* 0x0C */
    void *(*cfunc)(u32 fno, void *buff, int size); /* 0x10 */
    void *cbuff;                /* 0x14 */
    s32 csize;                  /* 0x18 */
    SifClientData *client;      /* 0x1C */
    void *paddr;                /* 0x20 */
    u32 fno;                    /* 0x24 */
    void *recv;                 /* 0x28 */
    s32 rsize;                  /* 0x2C */
    s32 rmode;                  /* 0x30 */
    u32 rid;                    /* 0x34 */
    struct SifServeData *link;  /* 0x38 */
    struct SifServeData *next;  /* 0x3C */
    struct SifQueueData *base;  /* 0x40 */
} SifServeData;

typedef struct SifQueueData {
    s32 key;                    /* 0x00 thread id */
    s32 active;                 /* 0x04 */
    SifServeData *link;         /* 0x08 registered servers */
    SifServeData *start;        /* 0x0C pending requests */
    SifServeData *end;          /* 0x10 */
    struct SifQueueData *next;  /* 0x14 */
} SifQueueData;

typedef struct SifRpcState {
    s32 pid;                    /* 0x00 */
    SifRpcPkt *pkt_table;       /* 0x04 */
    s32 pkt_table_len;          /* 0x08 */
    s32 unused0C;
    s32 unused10;
    u8 *rdata_table;            /* 0x14 */
    s32 rdata_table_len;        /* 0x18 */
    u8 *client_table;           /* 0x1C */
    s32 client_table_len;       /* 0x20 */
    s32 rdata_table_idx;        /* 0x24 */
    SifQueueData *active_queue; /* 0x28 */
} SifRpcState;

extern SifRpcState D_00793D40;

SifRpcPkt *func_002FAE50(SifRpcState *rd);
void func_002FAEF8(SifRpcPkt *pkt);
SifRpcPkt *func_002FAF18(SifRpcState *rd);
SifRpcPkt *func_002FAF48(SifRpcState *rd, int idx);
int func_002FAA30(u32 cid, void *pkt, int size, void *src, void *dst, int dsize);
void func_002FB9E0(SifServeData *sd);
SifServeData *func_002FB988(SifQueueData *qd);

/* file I/O client (c_2FB4C8/c_2FD578) */
typedef struct U5FioSlot {      /* DEBT(NAME): 16-byte request slot, only the in-use word is known */
    s32 w0;
    s32 busy;
    s32 w8;
    s32 wC;
} U5FioSlot;
extern U5FioSlot D_00794E80[32];
extern int D_00568E78;          /* fio RPC bound */
extern u8 D_0056862C[4];
extern u8 D_007950A8[4];
extern u8 *D_00568E88;
typedef struct U5Callback {
    void *func;                 /* DEBT(TYPE) */
    void *arg;
} U5Callback;
extern U5Callback D_00795100;
int func_002FC250(void);
int func_002EEE88(const void *a, const void *b, int n); /* memcmp; also in t4.h, which needs r4.h */
void func_002FBBE8(void);

/* ---- memory card client (Sony libmc, c_2DE7C0) ---- */
typedef struct McDescParam {    /* 0x30-byte request for fd based calls */
    s32 fd;                     /* 0x00 */
    s32 port;                   /* 0x04 DEBT(NAME): only rpc 0x15 uses it */
    s32 slot;                   /* 0x08 */
    s32 size;                   /* 0x0C */
    s32 offset;                 /* 0x10 */
    s32 origin;                 /* 0x14 seek origin / unaligned head size */
    u8 *buffer;                 /* 0x18 */
    void *param;                /* 0x1C */
    u8 data[16];                /* 0x20 unaligned head of a write */
} McDescParam;

typedef struct McNameParam {    /* 0x414-byte request for path based calls */
    s32 port;                   /* 0x000 */
    s32 slot;                   /* 0x004 */
    s32 flags;                  /* 0x008 */
    s32 maxent;                 /* 0x00C */
    void *table;                /* 0x010 */
    char name[1024];            /* 0x014 */
} McNameParam;

typedef struct McReadEnd {      /* read completion data, filled by the IOP (accessed uncached) */
    s32 size1;                  /* 0x00 */
    s32 size2;                  /* 0x04 */
    u8 *dest1;                  /* 0x08 */
    u8 *dest2;                  /* 0x0C */
    u8 buf1[64];                /* 0x10 */
    u8 buf2[64];                /* 0x50 */
} McReadEnd;

extern SifClientData D_0078C000;
extern McDescParam D_0078C080;
extern McNameParam D_0078C0B0;
extern McReadEnd D_0078C500;
extern s32 D_0078D5C0[];        /* rpc receive buffer */
extern s32 D_00566388;          /* last command */
extern s32 D_0056638C;          /* client semaphore */
s32 func_002F8430(s32 sema);    /* PollSema */
void func_002DF550(McReadEnd *p);
void func_002DE358(int a, int b, int c);
typedef struct U5Blk12 {        /* 12 bytes, byte aligned */
    u8 b[12];
} U5Blk12;

typedef struct McTblGetDir {    /* 0x40-byte directory entry */
    u8 create[8];               /* 0x00 */
    u8 modify[8];               /* 0x08 */
    u32 size;                   /* 0x10 */
    u16 attr;                   /* 0x14 */
    u16 reserve1;               /* 0x16 */
    u32 reserve2;               /* 0x18 */
    u32 pda_apl_no;             /* 0x1C */
    u8 name[32];                /* 0x20 */
} McTblGetDir;
extern McTblGetDir D_0078C040;
void func_002DF9D0(u32 addr);

/* ---- cdvd callback thread (c_2DF880) ---- */
extern volatile int D_00566418; /* volatile: copied from D_00566414 in the RPC end callback */
extern int D_005663D4;
extern int D_005663E0;          /* callback thread semaphore */
extern int D_0078D60C;
extern char D_00576BC8[];
void func_002F8220(void);
extern char D_0078C5C0[0x400];  /* dir/table name returned by the IOP (read uncached) */

/* ---- cdvd client (Sony libcdvd, c_2E08F0) ---- */
void func_002E0790(volatile int *stat);
void func_002FA8A0(u32 cid, void *func, void *data); /* sceSifAddCmdHandler */
void func_002FA8D0(u32 cid);                         /* sceSifRemoveCmdHandler */
void func_002E0BF0(void);
void func_002E0830(void *arg);  /* callback thread entry */
int func_002E0C30(void);
extern int D_005663FC;
extern int D_00566440;
extern char D_00576CA0[];
extern char D_00576CB0[];
void func_002E06D0(u16 ms);
extern s32 D_0078D610;
extern ThreadParam D_0078D618;
extern ThreadParam D_0078D648;
extern char D_00584670[];       /* _gp */
s32 func_002F81E0(ThreadParam *p);          /* CreateThread */
void func_002F8200(s32 tid, void *arg);     /* StartThread */
void func_002F8270(s32 tid, s32 prio);      /* ChangeThreadPriority, also in q0.h */

/* ---- event resource slots (c_298D80) ---- */
void func_00120108(char *fmt, ...); /* debug print, also in t6.h */
void func_00297520(int id);
int func_001730F0(Chr *key);
int func_00298330(int id, int v);
extern int D_00373568[0x12];
extern char D_005751B0[];
extern char D_005751E0[];
extern char D_00575208[];
extern char D_00575240[];
extern char D_005752B0[];
extern char D_005752C8[];

/* ---- matrix helpers (c_2D3F30) ---- */
void func_002D49E8(float (*m)[4]);  /* unit matrix */
void func_002D4A68(float (*m)[4]);
extern u16 D_00561F28[0x2000];      /* quarter sine table */

/* ---- IOP module loader client (c_2FF640) ---- */
extern SifClientData D_795340;  /* symbol name as generated by splat */
typedef struct U5LfBuf {         /* loadfile RPC buffer (0x200 bytes) */
    union {
        s32 i;
        u16 h;
        u8 b;
    } r;                         /* 0x000 result, or the IOP address of a peek/poke */
    s32 w4;                      /* 0x004 module id / access width */
    union {
        char path[0xFC];
        u32 w;
        u16 h;
        u8 b;
    } u;                         /* 0x008 */
    char arg[0xFC];              /* 0x104 */
} U5LfBuf;
extern U5LfBuf D_00795140;
extern int D_00568E94;
extern int D_00568E98;
int func_002FF270(void);
int func_002FF370(void);
void func_002F8850(void);

/* ---- memory card wrappers (c_2D8340) ---- */
extern int D_0078BA54;          /* card change mask seen last time */
int func_002D8A18(int a, int b, int c);
int func_002DFA28(int port, int slot, u32 *type, u32 *free, u32 *format);
int func_002DFBB0(int port, int slot, const char *name, int flags, int maxent, McTblGetDir *table);
int func_002E0188(int port, int slot, const char *name, McTblGetDir *info, u32 flags);

void func_002FB790(SifServeData *server, u32 command,
    void *(*func)(u32, void *, int), void *buffer,
    void *(*cfunc)(u32, void *, int), void *cbuffer, SifQueueData *queue);

#endif /* FFX_U5_H */
