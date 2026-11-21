typedef unsigned char u8;

extern void *g_ovl_ptr_4a4;
extern int fn_sys_1c5e90(void *a0, void *a1, int a2);
extern void fn_ovl_85a8(void *msg);
extern void fn_ovl_84b0(void *msg);
extern void fn_ovl_96e0(void *msg);
extern void fn_ovl_9638(void *msg);
extern void fn_ovl_b030(void *msg);
extern void fn_ovl_af28(void *msg);
extern void fn_ovl_c7a0(void *msg);

void ovl_09665_p6_2848(void **arg) {
    u8 *ctx = (u8 *)arg[1];
    *(float *)(ctx + 720) += 1.0f / 30.0f;
    switch (*(int *)(ctx + 732)) {
    case 0:
        if (*(float *)(ctx + 720) >= 0.5f) {
            fn_sys_1c5e90(g_ovl_ptr_4a4, *(void **)(*(u8 **)(ctx + 736) + 84), 32);
            *(int *)(ctx + 732) += 1;
        }
        break;
    case 1:
        if ((*(int *)(ctx + 264) & 4) != 0) {
            void *m0;
            void *m1;
            void *m2;
            void *m3;
            void *m4;
            void *m5;
            void *m6;
            void *m7;
            void *m8;

            m0 = ctx + 288;
            fn_ovl_85a8(&m0);
            m1 = ctx + 288;
            fn_ovl_84b0(&m1);
            m2 = ctx + 336;
            fn_ovl_85a8(&m2);
            m3 = ctx + 336;
            fn_ovl_84b0(&m3);
            m4 = ctx + 384;
            fn_ovl_96e0(&m4);
            m5 = ctx + 384;
            fn_ovl_9638(&m5);
            m6 = ctx + 740;
            fn_ovl_b030(&m6);
            m7 = ctx + 740;
            fn_ovl_af28(&m7);
            m8 = arg[0];
            fn_ovl_c7a0(&m8);
            *(int *)(ctx + 732) = 255;
        }
        break;
    }
}
