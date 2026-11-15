#include "rcef_overlay.h"
extern int D_00313E48;
extern W3Task *D_01B01CD0;
void func_001A2198(W3Task *);
void func_001A2B78(int,int,int,float,float,float,int,float,float,int,int);
void func_01B00848(W3Task *);
void func_01B00890(W3Task *);
void func_01B00900(W3Task *);
void func_01B00968(W3Task *);
void func_01B00A10(W3Task *);
void func_01B00AB8(W3Task *);
void func_01B00B00(W3Task *);
void func_01B00BA8(W3Task *);
void func_01B00BE8(W3Task *);
void func_01B00C80(W3Task *);
void func_01B00CB8(W3Task *);
void func_01B00CF0(W3Task *);
void func_01B011C8(W3Task *);
void func_01B00D00(W3Task *);
void func_01B00E00(W3Task *);
void func_01B00EC8(W3Task *);
void func_01B00F90(W3Task *);
void func_01B01060(W3Task *);

void func_01B00848(W3Task *t)
{
 func_001A2B80(D_00313E48,176);
 func_001A1D08(t,func_01B00890);
 func_001A1DF0(t,25);
}
void func_01B00890(W3Task *t)
{
 D_01B01CD0=func_0019FF90(&D_00313CB0,func_01B011C8);
 func_0019FF90(&D_00313CB0,func_01B00D00);
 func_001A1D08(t,func_01B00900);
 func_001A1DF0(t,20);
}
void func_01B00900(W3Task *t)
{
 int caster=D_00313E48;
 func_001A4310(2);
 func_001A1D08(t,func_01B00968);
 func_001A1D50(t,func_001A2148);
 t->frame[t->sp].count=caster;
}
void func_01B00968(W3Task *t)
{
 int caster=D_00313CB0.caster;
 func_001A2B80(caster,177);
 func_0019FF90(&D_00313CB0,func_01B00E00);
 func_0019FF90(&D_00313CB0,func_01B00EC8);
 func_0019FF90(&D_00313CB0,func_01B00F90);
 func_001A1D08(t,func_01B00A10);
 func_001A1D50(t,func_001A2148);
 t->frame[t->sp].count=caster;
}
void func_01B00A10(W3Task *t)
{
 int caster=D_00313CB0.caster;
 func_001A2B80(caster,177);
 func_0019FF90(&D_00313CB0,func_01B00E00);
 func_0019FF90(&D_00313CB0,func_01B00EC8);
 func_0019FF90(&D_00313CB0,func_01B00F90);
 func_001A1D08(t,func_01B00AB8);
 func_001A1D50(t,func_001A2148);
 t->frame[t->sp].count=caster;
}
void func_01B00AB8(W3Task *t)
{
 func_001A2B80(D_00313E48,178);
 func_001A1D08(t,func_01B00B00);
 func_001A1DF0(t,22);
}
void func_01B00B00(W3Task *t)
{
 int caster=D_00313CB0.caster;
 func_001A4288(1);
 D_01B01CD0->frame[D_01B01CD0->sp].count++;
 func_0019FF90(&D_00313CB0,func_01B01060);
 func_001A1D08(t,func_01B00BE8);
 func_001A1D50(t,func_001A2148);
 t->frame[t->sp].count=caster;
}
void func_01B00BA8(W3Task *t)
{
 func_001A2B80(D_00313E48,16);
 func_001A1D08(t,func_01B00BE8);
}
void func_01B00BE8(W3Task *t)
{
 int caster=D_00313E48;
 func_001A2B68();
 func_001A2B78(caster,1,0,0.0f,0.0f,0.0f,30,0.0f,0.0f,32,32);
 func_001A1D08(t,func_01B00C80);
 func_001A1D50(t,func_001A2198);
 t->frame[t->sp].count=caster;
}
void func_01B00C80(W3Task *t)
{
 func_001A1D08(t,func_01B00CB8);
 func_001A1D50(t,func_001A21E0);
}
void func_01B00CB8(W3Task *t)
{
 func_001A1D08(t,func_01B00CF0);
 func_001A1D50(t,func_01B00CB8);
}
void func_01B00CF0(W3Task *t)
{
 t->flags|=4;
}
