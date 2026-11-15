/* Overlay 09142: optional callbacks and particle cleanup. */
extern void *D_006A3924;
extern unsigned char D_01B00878[];
void _pppAllFreePObject(void *);
int func_01B02098(void *p)
{
    D_006A3924 = D_01B00878;
    _pppAllFreePObject(p);
    return 1;
}
