typedef unsigned char u8;
typedef unsigned short u16;
void ovl_09114_11990(void **a0) {
    u8 *p = *(u8 **)((u8 *)a0[0] + 48);
    *(int *)&a0[1] = *(u16 *)(p + 62) & 0x800;
}
