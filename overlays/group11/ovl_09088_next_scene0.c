#include "common.h"
typedef struct SceneTask SceneTask;
typedef struct TaskOwner { int unk0,unk4,unk8; void (*fnC)(SceneTask *); void (*fn10)(SceneTask *); } TaskOwner;
struct SceneTask { int unk0; int chr; TaskOwner *owner; int state; int unk10; int timer; };
typedef struct Targets { int caster; int count; u8 *order; int unkC; void *caster_obj; u8 pad14[0x20]; void *objects[16]; } Targets;
typedef struct Resource { u8 pad0[0x10]; u8 (*records)[32]; int *values; } Resource;
typedef struct Clip { int a,b,c,d; short t; } Clip;
extern Targets D_01B00620;
extern u8 *D_01B00628;
extern int D_01B02C40,D_01B02C44;
extern u8 D_01B02DC0[],D_01B02DD0[],D_01B07A10[];
extern u16 D_01B049F0;
void func_01B00A30(void);
void func_01B01A68(void);
void func_01B01A90(void);
void func_01B01AB8(int);
void func_01B01C28(void);
void func_01B025D0(void);
void func_002B22F8(int,int);
void op_oef2_set2(void *);
void func_002D02E8(void *,int,int,int);
void func_002944B0(void *,int,int,int);
void func_01B01CA8(int);
int func_01B008D8(int);
u8 *MsGetTargetSortList(int,int *,int);
void *func_01B00C08(int);
int func_01B00BE0(int);
float Ch_GetFixHeight(void *);
float func_001109E0(void *);
s8 MsGetChrFly(int);
void MsSetChrVisible(int,int);
void *func_01B01BF0(int);
void Ch_SetMotionSpeed(void *,int);
void func_001CE2F0(int);
void func_00173730(void *);
void func_001737A8(void *);
void func_00173720(void *);
void func_00173740(void *);
void *op_oef2_a_get(void *,int,int);
void *func_002943B8(void *);
void *func_002D7980(void *);
void func_01B013E8(int,int);

int func_01B00730(int id)
{
    D_01B02C40=id;
    func_01B00A30();
    func_01B01A68();
    func_01B01C28();
    func_01B025D0();
    func_002B22F8(0x3400,0x800);
    op_oef2_set2(D_01B07A10);
    func_002D02E8(D_01B07A10,0,1000,1);
    func_002944B0(D_01B07A10,0,1000,1);
    D_01B02C44=0;
    return 0;
}

int func_01B007B8(int a)
{
    func_01B01A90();
    func_01B01AB8(0);
    return func_01B008D8(a);
}
