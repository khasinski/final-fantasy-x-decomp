#ifndef FFX_S3_H
#define FFX_S3_H
#include "ffx/types.h"
#include "ffx/q4.h"

extern OfsTbl D_00662580;
int func_001C0040(int a);
int MsImportantName(int a);
void MsSetDamageMotion(int id, int v, int z);
int func_001CF458(int a, int b, int c, int d);
void func_001E12C8(int id, BtlChr *c);
void func_001E1120(int id, BtlChr *c, int a);
void func_001E1418(int id, BtlChr *c, int a);
void func_001E13D0(int id, BtlChr *c);
int TOBtlCloseSimpleHelpMes(void);
int func_00217270(int a, int b);
int func_00217310(int a, int b);
int func_00217400(int a);
int func_00217498(void);
int func_002174C8(void);
int TOBtlDrawLearningMessageWindow(int a, int b);
extern Q4Rec12 D_00662DF0;
extern Q4Rec12 D_00662DD8;
extern Q4Rec12 D_00662DE4;
int MsResetChrPos(int id, BtlChr *c);
int MsEffectResetMotionDisable(BtlChr *c);
void msResetHeadTarget(BtlChr *c);

#endif
