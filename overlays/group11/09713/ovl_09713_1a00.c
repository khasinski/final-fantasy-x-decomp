extern int D_CNT;
extern char D_STR[];
extern int func_DBG(char *, ...);

int func_01B0_X(void)
{
    func_DBG(D_STR, D_CNT);
    return 1;
}
