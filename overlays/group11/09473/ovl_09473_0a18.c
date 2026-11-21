extern void *D_006A3924;
extern float D_006A3930[16];
extern float D_006A3970[16];
extern float D_006A39B0[16];
extern float D_006A3A70[16];
extern float D_006A3AB0[16];
extern unsigned char D_01B006B0[];
extern void func_002675B0(void *);
extern void func_002DCE38(float *, float *, float *);
extern int func_00267FA0(void *, int);
int ovl_09473_0a18(void *a0) {
    func_002675B0(a0);
    func_002DCE38(D_006A39B0, D_006A3970, D_006A3930);
    func_002DCE38(D_006A3AB0, D_006A3A70, D_006A39B0);
    /* DEBT(FAKE): pin p to $v0 */
    { register void *p __asm__("$2") = D_01B006B0; D_006A3924 = p; }
    return func_00267FA0(a0, 48) == 0;
}
