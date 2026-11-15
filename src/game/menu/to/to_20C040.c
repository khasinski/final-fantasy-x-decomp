#include "common.h"
typedef struct {
    u8 pad0[0x2C]; u16 state; u8 pad2E[2];
    u16 x,y; u8 pad34[4]; s16 w,h,cw,ch; s16 rect[6];
    int native[3]; u8 pad58[12]; int international[3];
    u8 pad70[16]; int active[3];
} SwapMessage;
typedef struct { u8 pad0[8]; s16 x,y,z; u8 padE[2]; void *widget; SwapMessage *message; } SwapWindow;
extern SwapWindow *D_0068F0A8[];
int func_001BD360(void);
int TOSwapRenewMessage(SwapMessage *);
void TOSetMessageWindowPosition(int,int,int,int);
void func_00209508(void *);
void graphicFontGetScreenWH(s16 *,int,int,int,int);
void TOSwapInternationalMessageWindow(void)
{
    int i;
    SwapWindow **window = D_0068F0A8;
    for (i=0; i<8; i++,window++) {
        SwapMessage *m=(*window)->message;
        if ((unsigned)(m->state-1)<3 && m->active[1]!=0) {
            int a,b,c;
            if (func_001BD360()==0) {
                m=(*window)->message;
                a=m->native[0];
                b=m->native[1];
                c=m->native[2];
            } else {
                m=(*window)->message;
                a=m->international[0];
                b=m->international[1];
                c=m->international[2];
            }
            m->active[2]=c;
            m->active[1]=b;
            m->active[0]=a;
            TOSwapRenewMessage((*window)->message);
            TOSetMessageWindowPosition(i,(*window)->z,(*window)->x,(*window)->y);
            func_00209508((*window)->widget);
            {
                SwapMessage *layout=(*window)->message;
                graphicFontGetScreenWH(layout->rect,(s16)(layout->x+(layout->w-layout->cw)/2),(s16)(layout->y+(layout->h-layout->ch)/2),layout->cw,layout->ch);
            }
        }
    }
}
