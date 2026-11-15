/* Overlay 09487: optional callbacks and particle cleanup. */
extern void *D_006A3924;
extern unsigned char D_01B007D8[];
void _pppAllFreePObject(void *);
int func_01B040B0(void *p)
{
    D_006A3924 = D_01B007D8;
    _pppAllFreePObject(p);
    return 1;
}
