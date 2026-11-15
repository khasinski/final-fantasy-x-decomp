/* Overlay 09655: control, actor and pool helpers. */
#include "common.h"
typedef struct Track { float value[4], target[4]; u8 pad20[12]; float phase, step; int duration; int pad38; int active; } Track;
typedef struct Ramp { float a,b; int c,d; } Ramp;
typedef struct Control { u8 pad0[0xB0]; Track track0; Track track1; int pad130[6]; int flag148; u8 pad14C[0x1C]; int flag168; Ramp ramp; u8 pad17C[12]; u8 flag188; u8 pad189[3]; s16 counter; s16 pad18E; } Control;
extern u16 D_01B0B9C8[],D_01B0B9D0[],D_01B0B9D8[];
extern int D_01B0B9E0;
extern Control D_01B0B9F0[];
extern int D_01B1DA80,D_01B1DA84,D_01B1DA88;
Control *func_01B02810(int);
void func_01B06478(void);
void func_01B06878(int);
void func_002DD968(void *,void *,void *,float);


int func_01B019E0(void);
void func_002D41E8(int);
void func_002D41F0(int);
int func_002D41F8(int);
void func_01B025C0(Control *);
void func_001B5810(int);
void func_0010C790(int,int);
int func_001CE050(int,int);
typedef struct Actor { int id, handle, motion, motionResult, counter; unsigned char pad14[0x2c]; float pos[4]; unsigned char pad50[0x80]; } Actor;
typedef struct Sprite { unsigned char pad0[0x30]; int active; unsigned char pad34[0x4c]; int used; unsigned char pad84[4]; unsigned short age; unsigned char pad8A[0x26]; } Sprite;
typedef struct Pool64 { unsigned char pad0[0x20]; int active; unsigned char pad24[0x1c]; } Pool64;
typedef struct Pool80 { unsigned char pad0[0x28]; int active; unsigned char pad2C[0x24]; } Pool80;
extern Sprite D_01B0F590[32];
extern Pool64 D_01B10A70[512];
extern int D_01B18A70, D_01B18A74;
extern Pool80 D_01B18A80[256];
extern int D_01B1DA8C;
extern unsigned char D_01B0CF60[];
extern int D_006A3BCC;
void func_01B04720(void *);
void func_01B05780(void);
void func_01B05C68(void);
Actor *func_01B05230(Actor *p,int n,int id)
{
    while(n--) { if(p->id==id) return p; p++; } return 0;
}
