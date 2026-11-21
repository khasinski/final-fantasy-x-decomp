/* Shared 09285-family index getter (28 B, 5 containers). */

extern int fn_ovl_0f30(int);

int ovl_09285_0d78(void)
{
    int r = fn_ovl_0f30(-1);
    /* DEBT(ORDER): prevent sibling tail-call optimization on fn_ovl_0f30. */
    __asm__("");
    return r;
}
