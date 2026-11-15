/* Overlay 09089: optional callbacks and DMA submission. */
void func_01B02430(void) {  }
int func_01B02438(void) { return 0; }
void func_01B02440(void) {  }
int func_01B02448(void) { return 0; }
void func_01B02450(void) {  }
int func_01B02458(void) { return 0; }
void func_01B02460(void) {  }
void func_01B02468(void) {  }
void func_01B02470(void) {  }

int func_002DA610(int, int);
void func_002DBF78(void *, int, int);
void func_002DBA28(void *, void *);
void func_01B02478(void *p)
{
    while (func_002DA610(1, 0) & 0x10) {}
    func_002DBF78((void *)0x1000A000, 0, 0);
    func_002DBA28((void *)0x1000A000, (void *)((unsigned int)p | 0x80000000));
}
