typedef unsigned char u8;

typedef struct {
    u8 pad00[0x14];
    int w14;
    u8 pad18[0x90];
    int wA8;
} OvlObj;

extern OvlObj g_7100;

extern void func_01B019B0(int, void *);
extern void func_01B06580(void *, int, void *, int, float, float, float);

void ovl_09294_13a8(void)
{
    float v[4];
    OvlObj *obj;

    obj = &g_7100;
    func_01B019B0(-1, v);
    func_01B06580(obj, -1, v, 12, 0.25f, 0.5f, 0.75f);
    obj->wA8 = 19;
    obj->w14 = 1;
}
