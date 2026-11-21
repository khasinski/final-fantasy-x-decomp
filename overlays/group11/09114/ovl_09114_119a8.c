typedef unsigned char u8;
extern void fn_sys_282128(void *, void *, void *, void *);
void ovl_09114_119a8(void **a0) {
    u8 *p = (u8 *)a0[0];
    fn_sys_282128(p + 48, *(void **)(p + 80), a0[1], a0[2]);
    /* DEBT(ORDER): prevent tail-call optimization */
    __asm__("");
}
