#include "common.h"

extern void func_01B013E0(void *);
extern void func_01B01638(void *);
extern void func_01B018B8(void *);

void func_01B01B58(s32 arg0, void *arg1) {
    switch (arg0) {
    case 0:
        func_01B013E0(arg1);
        break;
    case 1:
        break;
    case 2:
        func_01B01638(arg1);
        break;
    case 3:
        func_01B018B8(arg1);
        break;
    }
}
