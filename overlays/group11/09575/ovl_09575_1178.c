/* Twin callbacks for 09575 and 09574 (compiled with ee-gcc2.96). */
extern void *D_006A3924;
extern unsigned char D_01B00878[];
void _pppAllFreePObject(void *);

int func_01B01178(void *p)
{
    D_006A3924 = D_01B00878;
    _pppAllFreePObject(p);
    return 1;
}
