/* Shared 09147-family task teardown helper (60 B). */

extern void fn_ovl_2ed8(void *);
extern void fn_ovl_2f28(int);
extern void fn_ovl_2e78(void);
extern void fn_ovl_0af0(void *);

void ovl_09147_0998(void *a)
{
    fn_ovl_2ed8(a);
    fn_ovl_2f28(0);
    fn_ovl_2e78();
    fn_ovl_0af0(a);
    /* DEBT(ORDER): prevent sibling tail-call optimization on fn_ovl_0af0. */
    __asm__("");
}
