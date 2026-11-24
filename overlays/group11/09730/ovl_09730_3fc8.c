extern void *D_006A3924;
extern unsigned char D_01B007B8[];
extern float D_01B00AA0;

extern void func_01B03410(void);
extern void func_00267530(void *);

int func_01B03FC8(void *a0)
{
    D_006A3924 = D_01B007B8;
    func_00267530(a0);
    return 1;
}

int func_01B03FF8(void)
{
    func_01B03410();
    D_01B00AA0 = 1.0f;
    return 1;
}
