/* Overlay 09709: particle update and cleanup callbacks. */
extern void *D_006A3924;
extern unsigned char D_006A3930[], D_006A3970[], D_006A39B0[], D_006A3A70[], D_006A3AB0[];
extern unsigned char D_01B00658[];
extern int D_01B00A90;
extern char D_01B025E0[];
void pppSetMatrix(void *);
void func_002DCE38(void *, void *, void *);
int _pppRunPart(void *, int);
void _pppAllFreePObject(void *);
int func_01B02170(char *, ...);

int func_01B014E8(void *p)
{
    pppSetMatrix(p);
    func_002DCE38(D_006A39B0, D_006A3970, D_006A3930);
    func_002DCE38(D_006A3AB0, D_006A3A70, D_006A39B0);
    D_006A3924 = D_01B00658;
    return _pppRunPart(p, 0x30) == 0;
}

int func_01B01570(void *p)
{
    func_01B02170(D_01B025E0, D_01B00A90);
    D_006A3924 = D_01B00658;
    _pppAllFreePObject(p);
    return 1;
}
