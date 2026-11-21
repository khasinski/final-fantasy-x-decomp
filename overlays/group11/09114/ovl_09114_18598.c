typedef unsigned char u8;
typedef struct { u8 pad[60]; float f3c; void *f40; } Obj;
extern void fn_ovl_187b0(void *);
void ovl_09114_18598(register void **a0) {
    fn_ovl_187b0(a0);
    ((Obj *)a0[0])->f3c = 1.0f;
    ((Obj *)a0[0])->f40 = a0[2];
}
