/* tu_165 0x19d458-0x19d608: low; rcdtChunk (config/tu_map.tsv) */
#include "common.h"
#include "ffx/r2.h"
#include "ffx/q3.h"
#include "ffx/w3.h"
#include "ffx/s2.h"
#include "ffx/v2.h"

W3Pair *rcdtChunkNew(void) {
    W3Pair *p = _rcAlloc(8, D_0056DBA8, 0x11);

    func_0019D4C0(p);
    return p;
}

void rcdtChunkDelete(W3Pair *p)
{
    rcdtChunkFini(p);
    func_0018FC10(p);
}

void func_0019D4C0(W3Pair *p)
{
    p->ptr = 0;
    p->size = 0;
}

void rcdtChunkFini(W3Pair *p)
{
    if (p->ptr != 0) {
        func_0018FC10(p->ptr);
        p->ptr = 0;
    }
}

void func_0019D508(W3Pair *p, void *ptr, int size)
{
    p->ptr = ptr;
    p->size = size;
}

void func_0019D518(W3Pair *p, void *ptr)
{
    p->ptr = ptr;
    p->size = 0x7FFFFFFF;
}

int rcdtChunkLoadFromFile(W3Pair *p, char *file)
{
    int fd;
    int size;
    void *buf;
    int ok;

    ok = 0;
    rcdtChunkFini(p);
    fd = func_002FC4E0(file, 1);
    if (fd >= 0) {
        size = func_002FC8E8(fd, 0, 2);
        func_002FC8E8(fd, 0, 0);
        buf = _rcAlloc(size, D_0056DBA8, 0x4F);
        if (buf != 0) {
            ok = 1;
            func_002FCB20(fd, buf, size);
            func_0019D508(p, buf, size);
        }
        func_002FC768(fd);
    }
    return ok;
}

u8 *func_0019D600(W3Pair *p)
{
    return p->ptr;
}
