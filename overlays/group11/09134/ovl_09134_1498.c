typedef unsigned char u8;
typedef unsigned short u16;
extern void fn_ovl_9c40(void *);
extern int fn_sys_1c5e90(void *, int, int);
extern void fn_ovl_5ef0(void *);
extern void fn_ovl_b540(void *);
extern u8 g_ovl_dat_990[];
extern void *g_ovl_ptr_530;
extern u8 g_ovl_dat_aa0[];

typedef struct { void *a; void *b; float c; float d; } Msg5ef0;

void ovl_09134_1498(void **arg) {
    u8 *ctx = (u8 *)arg[1];
    Msg5ef0 m;
    void *m_end;
    *(float *)(ctx + 720) += 1.0f / 30.0f;
    switch (*(u16 *)(ctx + 724)) {
    case 0:
        if (*(float *)(ctx + 720) >= 0.1f) {
            m.a = g_ovl_dat_990;
            m.b = 0;
            fn_ovl_9c40(&m);
            *(u16 *)(ctx + 724) += 1;
        }
        break;
    case 1:
        if (*(float *)(ctx + 720) >= 0.8f) {
            fn_sys_1c5e90(g_ovl_ptr_530, -5, 0);
            *(u16 *)(ctx + 724) += 1;
        }
        break;
    case 2:
        if (*(float *)(ctx + 720) >= 2.0f) {
            u8 *p = g_ovl_dat_aa0;
            *(float *)(p + 108) = 1.0f;
            *(float *)(p + 104) = 1.0f;
            *(float *)(p + 100) = 1.0f;
            *(float *)(p + 96) = 1.0f;
            *(float *)(p + 56) = 1.0f;
            *(float *)(p + 52) = 1.0f;
            *(float *)(p + 48) = 1.0f;
            m.a = p;
            m.b = 0;
            m.c = 0.05f;
            m.d = 1.0f;
            fn_ovl_5ef0(&m);
            m_end = arg[0];
            fn_ovl_b540(&m_end);
        }
        break;
    }
}
