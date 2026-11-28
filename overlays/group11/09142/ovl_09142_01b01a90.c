extern void *D_01B0069C;
extern void *D_01B00764;
extern void func_001C5E90(void *, void *, int);
int ovl_09473_0888(void) {
    /* DEBT(ORDER): load a1 before a0 to match v1/v0 register order */
    void *a1 = D_01B00764;
    void *a0 = D_01B0069C;
    func_001C5E90(a0, a1, 0);
    return 1;
}
