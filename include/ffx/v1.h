#ifndef FFX_V1_H
#define FFX_V1_H

/* DEBT(NAME): record and field names follow offsets pending caller analysis. */
/* DEBT(TYPE): record layout inferred from initializer and indexed halfwords. */
typedef struct V1Record1753 {
    s32 w00, w04, w08;
    s16 values[4];
    u8 pad14[8];
    s16 h1C;
    u8 pad1E[6];
    s32 w24;
    u8 pad28[4];
    s32 w2C;
    u8 pad30[4];
    s32 w34;
    u8 pad38[4];
    s32 w3C, w40;
    u8 color[8];
    float scale;
} V1Record1753;

struct Sys597F00;
struct S58FE54;

/* ---- sa_task.c (task groups, c_170BC4/c_171C98); ELF strings "sa_task.c", "i!=TASK_GRUPE_MAX" ---- */
/* DEBT(NAME): member names guessed from sa_task_init2 (asm), which fills the record */
typedef struct SaTaskGroup {
    void (*enter)(void);            /* from D_0030E8E8[group] */
    void (*leave)(void);            /* from D_0030E908[group] */
    int (*call)(int a, int b, int c); /* from D_0030E8C8[group] */
    char *stack;                    /* 16-byte aligned area after the header */
    char *work;                     /* stack + n * 0x1310 */
    char *work2;                    /* work + 0x370 */
    int n;
    int count;
    int group;
    int owned;                      /* != 0: freed through func_0011D590 */
} SaTaskGroup;

extern char D_0056C190[]; /* "sa_task.c" */

/* ---- misc ---- */
void func_001609A8(); /* DEBT(TYPE): defined as (void) in c_15FB30, func_00160BA8 passes (0x20, 0x4C, D_0056B950) */

/* c_1402F8 */
float func_00138C88(void);
void func_002D4D58(float *out, float a, float b, float c);
/* DEBT(NAME): record written by the script opcode handler func_001406F0 */
typedef struct OpRes1406 {
    u8 pad0[0x1F];
    u8 valid;
    u8 pad20[0xC];
    s16 v[3];
} OpRes1406;

/* c_173EA0 */
extern Blk64 D_005FFE50[5]; /* DEBT(TYPE): five matrices, handed to func_002DD0C0 / func_002DCE38 */
extern Blk64 D_005FFE90, D_005FFED0, D_005FFF10, D_005FFF50; /* DEBT(CAST): D_005FFE50[1..4] as separate symbols, see func_00173370 */
extern float D_00600150[4];
extern char D_0056C238[]; /* "host0:/ffx/proj/map/f_particle/m%03d.bin" */
extern char D_0056C268[]; /* "host0:/ffx/proj/map/f_particle/m%03d.pdt" */
extern char D_0056C298[]; /* "host0:/ffx/proj/map/f_particle/b%03d.bin" */
extern char D_0056C2C8[]; /* "host0:/ffx/proj/map/f_particle/b%03d.pdt" */
void func_00174870(char *bin, char *pdt);
void func_0019BBD0(int n);
void func_002697B8(void);
struct Q3Ent *func_001720F8(char *path);
int func_00172188(char *path);
void func_002DD020(float *d, float *a, float *b);
void func_002DD080(Blk64 *d, Blk64 *a, float *b);
void yiRotMatrixSeq(Blk64 *m, float *v, int id);

/* c_172DA0 */
void yiRenderEnable(int v);
void func_00175468(struct Sys597F00 *s, int a, int b, int c);
void yiRender_reset(struct Sys597F00 *s);
void Yn_BgInit(void);
void *func_0017DBA0(int size);
int sa_task_buff_size_get(int n);
SaTaskGroup *sa_task_init2(int n, SaTaskGroup *t, int owned);
/* DEBT(NAME): header with 0x1C section offsets at 0x10 (func_00172450 returns a section size) */
typedef struct SecHdr {
    u8 pad0[0x10];
    int ofs[0x1C];
} SecHdr;
/* DEBT(NAME): request block handed to SysVt.f0 together with the completion callback yiTexReadCallback */
typedef struct LoadReq {
    u8 pad0[0xC];
    int wC;
    void *buf;
    u8 pad14[4];
    int n;
    u8 pad1C[0x24];
} LoadReq;
void *func_0017DBC8(int size);
void yiTexReadCallback(void);
extern Blk64 D_005FFFD0[2]; /* DEBT(TYPE): two matrices built by yiGetLightInfo */
void func_00184AA8(struct Sys597F00 *s, int a, int b, int c, int d, int e, int f, int g, int h);

/* c_159A88 */
extern s8 D_0030D438[];
/* DEBT(NAME): 0x68-byte record passed by value to the stub handlers func_00159BC0 & co. */
typedef struct Arg68 { u32 w[0x1A]; } Arg68;
void func_00186C00(void); /* DEBT(TYPE): actually font bitmap data (0x10 bytes per glyph from ' ') */
void func_00158568(int v);
void SndSetStraightStreamVolumeDirect(int a);
void func_002D76B8(int a, int b, int c, int d);

/* c_15ACC0 */
extern s8 D_00591EB0;
int func_0015B850(void);
void func_0015B4B0(int a, int n, int c, u8 *d, struct S58FE54 *s);
int func_0015B9E8(int a, struct S58FE54 *s);
int func_206C650(int a, struct S58FE54 *s); /* DEBT(NAME): target outside the main image */
int func_0015BBA8(struct S58FE54 *s);
int func_0015B918(int n, u8 *buf, int *out, struct S58FE54 *s);
void func_00254730(u8 *a, int b, int c);
void audioDma(s16 *buf, int n, struct S58FE54 *s);
int func_002E1F00(void);
int func_002E1700(int a);
void func_001631E0(u8 v);
void func_0015B350(void);
int movie_hdd_file_open(int i, u64 sector);
void audioStop(struct S58FE54 *s);
extern int D_00591E78[2];
extern int D_00591E9C;
extern int D_00591EA0;
extern int D_00591EA4;
extern int D_00591EA8;
extern int D_00591EAC;
void func_0015ACC0(u8 *a, u8 *b, u8 *c, struct S58FE54 *s); /* DEBT(TYPE) */
/* DEBT(NAME): work area at *D_0030DDF4 laid out by func_0015F338 */
typedef struct MovWork {
    u8 *blk[4];
    u8 pad10[0x30];
    u64 q40;
    u64 q48;
    u64 q50;
    u64 q58;
    u8 *p60;
    u8 *p64;
    u8 *p68;
    u8 pad6C[4];
    u8 buf70[1];
} MovWork;
extern u8 D_0030DD70[64];
extern u8 D_0030DDB0[64];

/* c_157938, c_166358 */
extern char D_0056B5A8[]; /* "movie_buff_org!=NULL" */
extern char D_0056B5C0[]; /* "moviefunc.ac" */
extern s8 D_0030D405;
extern s8 D_0030D404;
extern char D_0056BD70[]; /* "hdd0:%s,%s" */
extern char D_0056BD80[]; /* "hdd_mount_in" */
extern char D_0056BD90[]; /* "pfs0:" */
extern char D_0056BD98[]; /* "hdd_mount_out_err" */
extern char D_0056BDB0[]; /* "hdd_mount_out_ok" */
extern char D_0056BDC8[]; /* "hdd_unmount_in" */
extern char D_0056BDD8[]; /* "hdd_unmount_out_ok" */
extern char D_0056BDF0[]; /* "hdd_unmount_out_err" */
extern s8 D_0030DE68[8];
int func_002FE7D0(char *dev, char *path, int flag, void *arg, int len); /* mount */
void func_001660C0(void);
void func_001661A8(void);
char *func_001672C0(void);
extern char D_00597988[0x40]; /* path of the async read job */
extern u8 *D_005979C8;
extern int D_005979CC;
extern s64 D_005979D0;
extern s8 D_0030DE34;
extern int D_0058FE68;
extern int D_0058FE6C;
extern int D_0030DE54;
int hdd_rmode_get(); /* as in its other declaration: DEBT(TYPE) */
void func_0020D468(void);
/* DEBT(NAME): object behind D_0030D418, slot 1 is its shutdown hook */
typedef struct MovIf { void (*f0)(void); void (*f4)(void); } MovIf;
extern MovIf *D_0030D418;
void MsSetCameraMatrix(int a, int b, int c, int d, int e, int f);
extern char D_0056BEA8[]; /* "hdd_format_check_in" */
extern char D_0056BEC8[]; /* "hdd_format_check_out" */
int func_002FEC98(char *dev, int cmd, void *arg, int arglen, void *buf, int buflen); /* devctl */
void TkyiAssert(const char *msg);
long func_002E9C38(long a, long b); /* as in s6.h: 64-bit divide */
extern s64 D_00597978;
extern s64 D_00597980;
int func_002FDCC0(char *path); /* dopen */
int func_002FDEF0(int fd, void *ent); /* dread */
int func_002FDD88(int fd); /* dclose */
/* DEBT(NAME): directory entry filled by func_002FDEF0 (iox_dirent_t-like) */
typedef struct DirEnt {
    int w0;
    u8 pad4[4];
    int size;
    u8 padC[0x150 - 0xC];
} DirEnt;

/* DEBT(TYPE): 20-float backing view; divisors occupy [0..3], output aliases D_00600150 at [16..19]. */
extern float D_00600110[20];

#endif
