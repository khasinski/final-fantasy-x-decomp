typedef unsigned char u8;
typedef unsigned short u16;
extern void fn_ovl_12b20(void *);
void ovl_09114_12b70(void **a0) {
    fn_ovl_12b20(a0);
    *(u16 *)((u8 *)a0[0] + 92) |= 1;
}
