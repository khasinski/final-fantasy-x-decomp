typedef unsigned char u8;

extern void fn_ovl_86a0(void *msg);
extern void fn_ovl_85a8(void *msg);
extern void fn_ovl_97d8(void *msg);
extern void fn_ovl_9730(void *msg);
extern void fn_ovl_b128(void *msg);
extern void fn_ovl_b020(void *msg);
extern void fn_ovl_c898(void *msg);

void ovl_09664_p6_29d8(void **arg) {
    u8 *ctx = (u8 *)arg[1];
    *(float *)(ctx + 720) += 1.0f / 30.0f;
    if (*(int *)(ctx + 732) != 0) {
        return;
    }
    if ((*(int *)(ctx + 264) & 4) == 0) {
        return;
    }
    {
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
        fn_ovl_86a0(&m0);
        m1 = ctx + 288;
        fn_ovl_85a8(&m1);
        m2 = ctx + 336;
        fn_ovl_86a0(&m2);
        m3 = ctx + 336;
        fn_ovl_85a8(&m3);
        m4 = ctx + 384;
        fn_ovl_97d8(&m4);
        m5 = ctx + 384;
        fn_ovl_9730(&m5);
        m6 = ctx + 740;
        fn_ovl_b128(&m6);
        m7 = ctx + 740;
        fn_ovl_b020(&m7);
        m8 = arg[0];
        fn_ovl_c898(&m8);
    }
    *(int *)(ctx + 732) = 255;
}
