/* Shared 09142 (0x01B03AC8..0x01B03B28) & 09395 (0x01B04DD0..0x01B04E30). */
int func_002DA610(int, int);
void func_002DBF78(void *, int, int);
void func_002DBA28(void *, void *);

void func_01B03AC8(void *p)
{
    while (func_002DA610(1, 0) & 0x10) {}
    func_002DBF78((void *)0x1000A000, 0, 0);
    func_002DBA28((void *)0x1000A000, (void *)((unsigned int)p | 0x80000000));
}
