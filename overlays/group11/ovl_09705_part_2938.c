/* Overlay 09705: particle update and cleanup callbacks. */
extern void *D_006A3924;
extern unsigned char D_006A3930[], D_006A3970[], D_006A39B0[], D_006A3A70[], D_006A3AB0[];
extern unsigned char D_01B01068[];
extern int D_01B012A0;
extern char D_01B03B98[];
void pppSetMatrix(void *);
void func_002DCE38(void *, void *, void *);
int _pppRunPart(void *, int);
void _pppAllFreePObject(void *);
int func_01B03748(char *, ...);

int func_01B02938(void *p)
{
    pppSetMatrix(p);
    func_002DCE38(D_006A39B0, D_006A3970, D_006A3930);
    func_002DCE38(D_006A3AB0, D_006A3A70, D_006A39B0);
    D_006A3924 = D_01B01068;
    return _pppRunPart(p, 0x30) == 0;
}

int func_01B029C0(void *p)
{
    func_01B03748(D_01B03B98, D_01B012A0);
    D_006A3924 = D_01B01068;
    _pppAllFreePObject(p);
    return 1;
}
