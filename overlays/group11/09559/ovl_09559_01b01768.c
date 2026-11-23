/* Overlay 09559: rank 141 debug error display and pause loop (0x01B01768..0x01B019A8). */
#include "common.h"

typedef struct DBuff {
    u8 pad0[0x100];
    unsigned long clear0;
    u8 pad108[0xE8];
    unsigned long clear1;
    u8 pad1F8[0x38];
} DBuff;

extern char *D_01B00048[];
extern int D_01B000DC;
extern char D_01B0B450[];
extern char D_01B0B460[];
extern char D_01B0B478[];
extern char D_01B0B488[];
extern char D_01B0B498[];

void func_002DA280(DBuff *, int, int, int, int, int, int);
void func_002B42E0(int);
void func_002B4390(int, int);
void func_002B41B0(const char *, ...);
void func_002F0008(char *, const char *, ...);
void func_002B4340(void);
void func_002DA610(int, int);
void func_002D3FF0(int);
void func_002F8660(int);
void func_002DA518(DBuff *, int);
void func_01B022A8(void);
int func_01B023D8(int);
int func_01B02408(int);
int func_002D2978(int, int, int);
int func_002D2938(int, int, int);

void func_01B01768(int a0, int a1, int a2) {
    DBuff db;
    char str[256];
    int frame = 0;

    func_002DA280(&db, 0, 0x200, 0x1A0, 3, 0x31, 1);
    db.clear1 = 0x3F80000080000000ULL;
    db.clear0 = 0x3F80000080000000ULL;

    while (1) {
        func_002DA610(0, 0);
        func_002D3FF0(1);
        func_002F8660(0);
        func_002DA518(&db, frame);
        frame ^= 1;
        func_01B022A8();
        if ((func_01B023D8(0) & 0x80) && (func_01B02408(0) & 0x10)) {
            break;
        }
        func_002B42E0(1);
        func_002B4390(2, 2);
        func_002B41B0(D_01B0B450);
        func_002B4390(2, 4);
        func_002F0008(str, D_01B0B460, D_01B00048[a0]);
        func_002B41B0(str);
        func_002B4390(2, 6);
        func_002F0008(str, D_01B0B478, a1);
        func_002B41B0(str);
        func_002B41B0(D_01B0B488, a2);
        func_002B41B0(D_01B0B498);
        func_002B4340();
    }
}

void func_01B01910(void) {
    if (func_01B02408(0) & 0x80) {
        D_01B000DC = !D_01B000DC;
    }
    while (D_01B000DC != 0 && !(func_002D2938(0, 0, 0) & 0x10)) {
        func_002D3FF0(1);
        if (func_002D2978(0, 0, 0) & 0x80) {
            D_01B000DC = 0;
        }
    }
}
