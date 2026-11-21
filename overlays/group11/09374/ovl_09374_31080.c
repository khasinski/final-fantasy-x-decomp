typedef unsigned char u8;

extern void fn_ovl_31580(void *msg);
extern void fn_ovl_30f40(void *a0, int a1);
extern void fn_ovl_39c10(void *msg);

extern void *g_ovl_ptr_388;
extern u8 g_ovl_dat_7b0[];
extern u8 g_ovl_dat_768[];
extern u8 g_ovl_dat_3df0[];
extern int g_ovl_cnt_2fd0;

typedef struct {
    void *a;
    void *b;
    void *c;
    void *d;
    u8 e;
    u8 pad[3];
} Msg31580;

typedef struct {
    u8 pad00[24];
    unsigned int state;
    float t1;
    float t2;
    int idx;
    int frame;
    int sub;
} Ovl9374Ctx;

void ovl_09374_31080(void **arg) {
    u8 *ctx = (u8 *)arg[1];
    void *m0[6];
    void *m_end;

    *(float *)(ctx + 28) += 1.0f / 30.0f;
    *(float *)(ctx + 32) += 1.0f / 30.0f;
    *(int *)(ctx + 40) += 1;

    switch (*(unsigned int *)(ctx + 24)) {
    case 0:
        ((Msg31580 *)m0)->a = g_ovl_dat_7b0;
        ((Msg31580 *)m0)->b = g_ovl_dat_768;
        ((Msg31580 *)m0)->c = g_ovl_ptr_388;
        ((Msg31580 *)m0)->d = 0;
        ((Msg31580 *)m0)->e = 1;
        fn_ovl_31580(m0);
        *(unsigned int *)(ctx + 24) = 10;
        *(int *)(ctx + 44) = 0;
    case 10:
        *(int *)(ctx + 40) = 25;
        *(unsigned int *)(ctx + 24) += 1;
        *(int *)(ctx + 36) = 0;
    case 11:
        if (*(int *)(ctx + 40) < 26) {
            break;
        }
        fn_ovl_30f40(g_ovl_dat_3df0 + *(int *)(ctx + 44) * 2848, *(int *)(ctx + 44));
        *(int *)(ctx + 44) += 1;
        *(int *)(ctx + 36) += 1;
        if (*(int *)(ctx + 36) >= g_ovl_cnt_2fd0) {
            *(unsigned int *)(ctx + 24) = 10000;
        }
        *(int *)(ctx + 40) = 0;
        break;
    case 10000:
        m_end = arg[0];
        fn_ovl_39c10(&m_end);
        break;
    }
    *(int *)(ctx + 40) += 1;
}
