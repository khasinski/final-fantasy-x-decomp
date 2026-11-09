/* tu_167 0x19d688-0x19f190: medium; rcdtRsd2 (config/tu_map.tsv) */
#define func_0019DFB8 _hdr_func_0019DFB8
#define func_0019DF68 _hdr_func_0019DF68
#include "common.h"
#include "ffx/r2.h"
#include "ffx/q3.h"
#include "ffx/w3.h"
#include "ffx/s2.h"
#include "ffx/v2.h"
#include "ffx/t2.h"
#undef func_0019DF68
#undef func_0019DFB8

void func_0019D688(W3Reader *p)
{
    func_0019D6C8(p);
    func_0018FC10(p);
}

void rcdtParseInit(W3Reader *cs) {
    cs->buf = 0;
    cs->cur = 0;
    cs->mode = 0;
    func_0019D768(cs);
}

void func_0019D6C8(W3Reader *p) {
}

void rcdtParseSet(W3Reader *cs, W3Pair *p)
{
    cs->buf = p;
    cs->cur = func_0019D600(p);
}

void func_0019D700(W3Reader *cs, const u8 *chars)
{
    int i;
    int n;

    n = func_002F0840(chars);
    for (i = 0; i < n; i++) {
        cs->delim[chars[i]] = 1;
    }
}

void func_0019D768(W3Reader *cs)
{
    s8 *q;
    int i;

    func_002EF0D0(cs->delim, 0, 0x80);
    q = &cs->delim[0x20];
    for (i = 0x20; i >= 0; i--) {
        *q-- = 1;
    }
}

/* Binary mode (r->mode == 0) reads host-endian values straight from the byte cursor r->cur. */
u8 *func_0019D7C8(W3Reader *r)
{
    return func_0019D600(r->buf);
}

u8 *func_0019D7E8(W3Reader *r) {
    return func_0019D608(r->buf);
}

int func_0019D808(W3Reader *r) {
    int res = 0;

    if (r->buf == 0 || func_0019D620(r->buf) != 0) {
        res = 1;
    }
    return res;
}

int rcdtParseIsEnd(W3Reader *r)
{
    return r->cur >= func_0019D7E8(r);
}

void func_0019D878(W3Reader *r, int n)
{
    r->cur += n;
}

void func_0019D888(W3Reader *r, char c)
{
    r->cur = func_0019DB30(r, c);
}

void func_0019D8B8(W3Reader *r)
{
    r->cur = func_0019DAC8(r);
    r->cur = func_0019DA60(r);
}

void func_0019D8F0(W3Reader *r)
{
    func_0019D888(r, '\n');
    r->cur++;
}

void func_0019D928(W3Reader *r)
{
    func_0019D8F0(r);
    r->cur = func_0019DA60(r);
}

void func_0019D958(W3Reader *r)
{
    u8 *p;
    u8 open;
    u8 close;
    int depth;

    p = r->cur;
    if (*p == '(' || *p == '{' || *p == '[') {
        open = *p++;
        if (open == '(') {
            close = ')';
        } else {
            close = open + 2;
        }
        depth = 1;
        do {
            if (*p == open) {
                depth++;
            }
            if (*p == close) {
                depth--;
            }
            p++;
        } while (depth > 0);
        r->cur = p;
        r->cur = func_0019DA60(r);
    }
}

void func_0019D9F8(W3Reader *r, int n)
{
    r->cur = func_0019D7C8(r) + n;
}

int func_0019DA30(W3Reader *r)
{
    return r->cur - func_0019D7C8(r);
}

u8 *func_0019DA60(W3Reader *r)
{
    u8 *p;

    p = r->cur;
    while (r->delim[*p] != 0 && p < func_0019D7E8(r)) {
        p++;
    }
    return p;
}

u8 *func_0019DAC8(W3Reader *r)
{
    u8 *p;

    p = r->cur;
    while (r->delim[*p] == 0 && p < func_0019D7E8(r)) {
        p++;
    }
    return p;
}

u8 *func_0019DB30(W3Reader *r, char c)
{
    u8 *p;

    p = r->cur;
    while (*p != c && p < func_0019D7E8(r)) {
        p++;
    }
    return p;
}

int func_0019DB98(W3Reader *r)
{
    return func_0019DAC8(r) - r->cur;
}

float func_0019DBC8(W3Reader *r)
{
    float f;

    if (r->mode == 0) {
        f = *(float *)r->cur;
        func_0019D878(r, 4);
        return f;
    }
    f = (float)func_002ED078(r->cur);
    func_0019D8B8(r);
    return f;
}

float func_0019DC30(W3Reader *r)
{
    return (float)func_002ED078(r->cur);
}

s64 func_0019DC58(W3Reader *r)
{
    s64 d;

    if (r->mode == 0) {
        d = *(s64 *)r->cur;
        func_0019D878(r, 8);
        return d;
    }
    d = func_002ED0C0(r->cur);
    func_0019D8B8(r);
    return d;
}

int func_0019DCB8(W3Reader *r)
{
    int v;

    if (r->mode == 0) {
        v = *(int *)r->cur;
        func_0019D878(r, 4);
        return v;
    }
    v = func_002ED098(r->cur);
    func_0019D8B8(r);
    return v;
}

int func_0019DD18(W3Reader *r)
{
    return func_002ED098(r->cur);
}

int func_0019DD38(W3Reader *r)
{
    int v;

    v = *(int *)r->cur;
    func_0019D878(r, 4);
    return v;
}

int func_0019DD68(W3Reader *r)
{
    int v;

    v = *(u16 *)r->cur;
    func_0019D878(r, 2);
    return v;
}

int func_0019DD98(W3Reader *r)
{
    int v;

    v = *r->cur;
    func_0019D878(r, 1);
    return v;
}

int func_0019DDC8(W3Reader *r, u8 *buf)
{
    int n;

    n = func_0019DE30(r);
    if (n > 0) {
        func_002F0C10(buf, r->cur, n);
        buf[n] = 0;
        func_0019D8B8(r);
    }
    return n;
}

int func_0019DE30(W3Reader *r)
{
    int n;

    n = 0;
    if (r->mode == 1) {
        n = func_0019DAC8(r) - r->cur;
    }
    return n;
}

void func_0019DE78(W3Reader *r, void *dst, s32 n) {
    func_002EEF1C(dst, r->cur, n);
    func_0019D878(r, n);
}

float func_0019DEB8(W3Reader *r) {
    u32 u;
    V2Word w;

    u = *(u32 *)r->cur;
    func_0019D878(r, 4);
    w.u = (u << 0x18) | ((u >> 0x18) | (((u >> 8) & 0xFF00) | ((u & 0xFF00) << 8)));
    return w.f;
}

s64 func_0019DF10(W3Reader *r) {
    u32 w;

    w = *(u32 *)r->cur;
    func_0019D878(r, 4);
    w = (w << 0x18) | ((w >> 0x18) | (((w >> 8) & 0xFF00) | ((w & 0xFF00) << 8)));
    return *(s64 *)&w;
}

void _m2c_func_0019DF68_func_0019D878() __asm__("func_0019D878");
/* DEBT(CAST) */
u32 func_0019DF68(void *arg0) {
    u32 temp_16 = *(*(u32 **)((u8 *)(arg0) + (4)));
    _m2c_func_0019DF68_func_0019D878(arg0, 4);
    return (temp_16 << 0x18) | ((temp_16 >> 0x18) | (((temp_16 >> 8) & 0xFF00) | ((temp_16 & 0xFF00) << 8)));
}

void _m2c_func_0019DFB8_func_0019D878() __asm__("func_0019D878");
/* DEBT(CAST) */
s32 func_0019DFB8(void *arg0) {
    u16 temp_16;

    temp_16 = *(*(u16 **)((u8 *)(arg0) + (4)));
    _m2c_func_0019DFB8_func_0019D878(arg0, 2);
    return ((temp_16 >> 8) | (temp_16 << 8)) & 0xFFFF;
}

int rcdtParseGetTokenNo(W3Reader *r, u8 **names)
{
    int ret;
    int len;
    int i;

    ret = -1;
    if (r->delim[*r->cur] != 0) {
        r->cur = func_0019DA60(r);
    }
    len = func_0019DB98(r);
    if (len > 0) {
        for (i = 0; names[i] != 0; i++) {
            if (len == func_002F0840(names[i]) && func_002F0978(r->cur, names[i], len) == 0) {
                ret = i;
                break;
            }
        }
        func_0019D8B8(r);
    }
    return ret;
}

W3Pair *func_0019E0C8(W3Reader *r)
{
    return r->buf;
}

u8 *func_0019E0D0(W3Reader *r)
{
    return r->cur;
}

void func_0019E0D8(W3Reader *r, int mode) {
    r->mode = mode;
}

int func_0019E0E0(W3Reader *r) {
    return r->mode;
}

void *func_0019E0E8(void) {
    void *p = _rcAlloc(0x20, D_0056DBD0, 0x1C);

    func_0019E150(p);
    return p;
}

void func_0019E128(void *p) {
    func_0019E160(p);
    func_0018FC10(p);
}

void func_0019E150(W3Obj20 *p) {
    func_002EF0D0(p, 0, 0x20);
}

void func_0019E160(W3Obj20 *o) {
    RsdData *d = (RsdData *)o; /* DEBT(CAST): declared with W3Obj20, only its size (0x20) is shared */
    int i;

    if (d->vtx != 0) {
        func_0018FC10(d->vtx);
        d->vtx = 0;
    }
    if (d->nrm != 0) {
        func_0018FC10(d->nrm);
        d->nrm = 0;
    }
    if (d->prim != 0) {
        func_0018FC10(d->prim);
        d->prim = 0;
    }
    for (i = 0; i < d->count; i++) {
        if (d->names[i] != 0) {
            func_0018FC10(d->names[i]);
            d->names[i] = 0;
        }
    }
    if (d->names != 0) {
        func_0018FC10(d->names);
        d->names = 0;
    }
}

int func_0019E248(RsdData *d, char *file) {
    RsdKeys keys;
    char dir[0x100];
    char path[0x100];
    char name[0x100];
    W3Pair *blk;
    W3Reader *rd;
    char *s;
    int n;

    keys = D_0056DC10;
    func_002F072C(dir, file);
    s = func_002F0DD0(dir, '/');
    if (s != 0) {
        s[1] = 0;
    }
    blk = rcdtChunkNew();
    if (rcdtChunkLoadFromFile(blk, file) == 0) {
        if (blk != 0) {
            rcdtChunkDelete(blk);
        }
        func_0018F5E8(D_0056DC30, D_0056DBD0, 96);
        func_0018F5E8(D_0056DC48);
        return 0;
    }
    rd = func_0019D648();
    rcdtParseSet(rd, blk);
    func_0019E0D8(rd, 1);
    func_0019D700(rd, (u8 *)D_0056DC68);
    while (!rcdtParseIsEnd(rd)) {
        if (*rd->cur == '@' || *rd->cur == '#') {
            func_0019D928(rd);
            continue;
        }
        switch (rcdtParseGetTokenNo(rd, keys.key)) {
        case 0:
            func_0019DDC8(rd, (u8 *)name);
            func_0017A930(name);
            func_002F072C(path, dir);
            func_002F032C(path, name);
            func_0019E550(d, path);
            break;
        case 1:
            func_0019DDC8(rd, (u8 *)name);
            func_0017A930(name);
            func_002F072C(path, dir);
            func_002F032C(path, name);
            func_0019E8A8(d, path);
            break;
        case 2:
            func_0019DDC8(rd, (u8 *)name);
            func_0017A930(name);
            break;
        case 3:
            n = func_0019DCB8(rd);
            if (n > 0) {
                d->names = _rcAlloc(n * 4, D_0056DBD0, 139);
            }
            break;
        case 4:
            n = func_0019DCB8(rd);
            d->names[n] = _rcAlloc(func_0019DE30(rd) + 1, D_0056DBD0, 146);
            func_0019DDC8(rd, (u8 *)d->names[n]);
            break;
        case 5:
            func_0019DDC8(rd, (u8 *)name);
            break;
        }
    }
    if (rd != 0) {
        func_0019D688(rd);
    }
    if (blk != 0) {
        rcdtChunkDelete(blk);
    }
    return 1;
}

void func_0019E550(RsdData *d, char *file) {
    W3Pair *blk;
    W3Reader *rd;
    Vec4 *v;
    RsdPrim *p;
    int i;
    int j;

    blk = rcdtChunkNew();
    if (rcdtChunkLoadFromFile(blk, file) == 0) {
        if (blk != 0) {
            rcdtChunkDelete(blk);
        }
        func_0018F5E8(D_0056DC30, D_0056DBD0, 180);
        func_0018F5E8(D_0056DC88);
        return;
    }
    rd = func_0019D648();
    rcdtParseSet(rd, blk);
    func_0019E0D8(rd, 1);
    while (*rd->cur == '@' || *rd->cur == '#') {
        func_0019D928(rd);
    }
    d->nvtx = func_0019DCB8(rd);
    d->nnrm = func_0019DCB8(rd);
    d->nprim = func_0019DCB8(rd);
    func_0019D928(rd);
    v = d->vtx = _rcAlloc(d->nvtx * sizeof(Vec4), D_0056DBD0, 200);
    for (i = 0; i < d->nvtx; i++) {
        v->x = func_0019DBC8(rd);
        v->y = func_0019DBC8(rd);
        v->z = func_0019DBC8(rd);
        v->w = 1.0f;
        v++;
    }
    func_0019D928(rd);
    v = d->nrm = _rcAlloc(d->nnrm * sizeof(Vec4), D_0056DBD0, 214);
    for (i = 0; i < d->nnrm; i++) {
        v->x = func_0019DBC8(rd);
        v->y = func_0019DBC8(rd);
        v->z = func_0019DBC8(rd);
        v->w = 1.0f;
        v++;
    }
    func_0019D928(rd);
    d->prim = _rcAlloc(d->nprim * sizeof(RsdPrim), D_0056DBD0, 227);
    func_002EF0D0(d->prim, 0, d->nprim * sizeof(RsdPrim));
    p = d->prim;
    for (i = 0; i < d->nprim; i++) {
        if (func_0019DCB8(rd) != 0) {
            p->flags |= 1;
        }
        for (j = 0; j < 4; j++) {
            p->vtx[j] = (u16)func_0019DCB8(rd);
        }
        for (j = 0; j < 4; j++) {
            p->nrm[j] = (u16)func_0019DCB8(rd);
        }
        p++;
    }
    if (rd != 0) {
        func_0019D688(rd);
    }
    if (blk != 0) {
        rcdtChunkDelete(blk);
    }
}

void func_0019E8A8(RsdData *d, char *file) {
    char *ext;

    ext = func_002F0DD0(file, '.');
    if (ext != 0) {
        ext++;
        if (func_002F0278(ext, D_0056DCB0) == 0) {
            func_0019E960(d, file);
        } else if (func_002F0278(ext, D_0056DCB8) == 0) {
            func_0019EEB0(d, file);
        }
    }
}

void func_0019E960(RsdData *d, char *file) {
    char type;
    W3Pair *blk;
    W3Reader *rd;
    RsdPrim *p;
    int n;
    int i;
    int j;

    blk = rcdtChunkNew();
    if (rcdtChunkLoadFromFile(blk, file) == 0) {
        if (blk != 0) {
            rcdtChunkDelete(blk);
        }
        func_0018F5E8(D_0056DC30, D_0056DBD0, 301);
        func_0018F5E8(D_0056DCC0);
        return;
    }
    rd = func_0019D648();
    rcdtParseSet(rd, blk);
    func_0019E0D8(rd, 1);
    while (*rd->cur == '@' || *rd->cur == '#') {
        func_0019D928(rd);
    }
    n = func_0019DCB8(rd);
    if (n != d->nprim) {
        func_0018F5E8(D_0056DCF0, D_0056DD18, D_0056DBD0, 316);
    }
    p = d->prim;
    for (i = 0; i < n; i++) {
        func_0019DCB8(rd);
        func_0019DCB8(rd);
        func_0019DCB8(rd);
        func_0019DE78(rd, &type, 1);
        func_0019D8B8(rd);
        switch (type) {
        case 'C':
            p->col[0][0] = func_0019DCB8(rd);
            p->col[0][1] = func_0019DCB8(rd);
            p->col[0][2] = func_0019DCB8(rd);
            p->col[0][3] = 0x80;
            for (j = 1; j < 4; j++) {
                p->col[j][0] = p->col[0][0];
                p->col[j][1] = p->col[0][1];
                p->col[j][2] = p->col[0][2];
                p->col[j][3] = p->col[0][3];
            }
            break;
        case 'G':
            for (j = 0; j < 4; j++) {
                p->col[j][0] = func_0019DCB8(rd);
                p->col[j][1] = func_0019DCB8(rd);
                p->col[j][2] = func_0019DCB8(rd);
                p->col[j][3] = 0x80;
            }
            break;
        case 'T':
            p->flags |= 2;
            p->tex = func_0019DCB8(rd);
            for (j = 0; j < 4; j++) {
                (p->uv + j)->u = func_0019DCB8(rd);
                (p->uv + j)->v = func_0019DCB8(rd);
                p->col[j][0] = p->col[j][1] = p->col[j][2] = p->col[j][3] = 0x80;
            }
            break;
        case 'D':
            p->flags |= 2;
            p->tex = func_0019DCB8(rd);
            for (j = 0; j < 4; j++) {
                (p->uv + j)->u = func_0019DCB8(rd);
                (p->uv + j)->v = func_0019DCB8(rd);
            }
            p->col[0][0] = func_0019DCB8(rd);
            p->col[0][1] = func_0019DCB8(rd);
            p->col[0][2] = func_0019DCB8(rd);
            p->col[0][3] = 0x80;
            for (j = 1; j < 4; j++) {
                p->col[j][0] = p->col[0][0];
                p->col[j][1] = p->col[0][1];
                p->col[j][2] = p->col[0][2];
                p->col[j][3] = p->col[0][3];
            }
            break;
        case 'H':
            p->flags |= 2;
            p->tex = func_0019DCB8(rd);
            for (j = 0; j < 4; j++) {
                (p->uv + j)->u = func_0019DCB8(rd);
                (p->uv + j)->v = func_0019DCB8(rd);
            }
            for (j = 0; j < 4; j++) {
                p->col[j][0] = func_0019DCB8(rd);
                p->col[j][1] = func_0019DCB8(rd);
                p->col[j][2] = func_0019DCB8(rd);
                p->col[j][3] = 0x80;
            }
            break;
        }
        p++;
    }
    if (rd != 0) {
        func_0019D688(rd);
    }
    if (blk != 0) {
        rcdtChunkDelete(blk);
    }
}

void func_0019EEB0(RsdData *d, char *file) {
    char type;
    W3Pair *blk;
    W3Reader *rd;
    RsdPrim *p;
    int n;
    int i;
    int j;

    blk = rcdtChunkNew();
    if (rcdtChunkLoadFromFile(blk, file) == 0) {
        if (blk != 0) {
            rcdtChunkDelete(blk);
        }
        func_0018F5E8(D_0056DC30, D_0056DBD0, 436);
        func_0018F5E8(D_0056DD88);
        return;
    }
    rd = func_0019D648();
    rcdtParseSet(rd, blk);
    func_0019E0D8(rd, 1);
    while (*rd->cur == '@' || *rd->cur == '#') {
        func_0019D928(rd);
    }
    n = func_0019DCB8(rd);
    if (n != d->nprim) {
        func_0018F5E8(D_0056DCF0, D_0056DD18, D_0056DBD0, 450);
    }
    p = d->prim;
    for (i = 0; i < n; i++) {
        func_0019DCB8(rd);
        func_0019DCB8(rd);
        func_0019DCB8(rd);
        func_0019DCB8(rd);
        func_0019DCB8(rd);
        func_0019DCB8(rd);
        func_0019DCB8(rd);
        func_0019DCB8(rd);
        func_0019DE78(rd, &type, 1);
        func_0019D8B8(rd);
        if (type == 'H') {
            p->tex = func_0019DCB8(rd);
            for (j = 0; j < 4; j++) {
                (p->uv + j)->u = func_0019DCB8(rd);
                (p->uv + j)->v = func_0019DCB8(rd);
            }
        } else {
            p->tex = -1;
        }
        for (j = 0; j < 4; j++) {
            p->col[j][0] = func_0019DCB8(rd);
            p->col[j][1] = func_0019DCB8(rd);
            p->col[j][2] = func_0019DCB8(rd);
            p->col[j][3] = func_0019DCB8(rd);
        }
        p++;
    }
    if (rd != 0) {
        func_0019D688(rd);
    }
    if (blk != 0) {
        rcdtChunkDelete(blk);
    }
}
