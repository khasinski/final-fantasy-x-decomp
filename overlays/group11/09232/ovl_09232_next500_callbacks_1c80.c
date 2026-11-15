/* Overlay 09232: optional callbacks and particle cleanup. */
extern void *D_006A3924;
extern unsigned char D_01B00808[];
void _pppAllFreePObject(void *);
int func_01B01C80(void *p)
{
    D_006A3924 = D_01B00808;
    _pppAllFreePObject(p);
    return 1;
}
