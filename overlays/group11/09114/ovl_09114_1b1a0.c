typedef unsigned char u8;
typedef struct { u8 pad[300]; int f12c; u8 pad2[16]; void *f140; void *f144; void *f148; u8 f14c; } Obj;
extern void fn_ovl_1b640(void *);
extern void fn_ovl_1b618(void *);
void ovl_09114_1b1a0(register void **a0) {
    Obj *p = (Obj *)a0[0];
    fn_ovl_1b640(a0);
    fn_ovl_1b618(a0[2]);
    fn_ovl_1b618(a0[3]);
    fn_ovl_1b618(a0[4]);
    p->f140 = a0[2];
    p->f148 = a0[3];
    p->f144 = a0[4];
    p->f12c = 0;
    p->f14c = 0;
}
