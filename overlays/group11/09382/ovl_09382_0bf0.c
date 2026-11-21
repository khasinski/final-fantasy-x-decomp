typedef struct {
    float x;
    float y;
    float z;
} OvlVec3;

typedef struct {
    unsigned char pad0[0x60];
    float f60;
    float f64;
    float f68;
    unsigned char pad6C[0x54];
    OvlVec3 rot;
    unsigned char padCC[0x04];
    OvlVec3 pos;
    unsigned char padDC[0x54];
} OvlObj;

typedef struct {
    unsigned char pad0[0x0C];
    unsigned int w0C;
    unsigned char pad10[0xC0];
    OvlVec3 vD0;
    unsigned char padDC[0x24];
    OvlVec3 v100;
} OvlPart;

extern float g_ovl_floor_y;
extern unsigned char g_ovl_mgr[];
extern OvlObj g_ovl_objs[];

extern void func_002DD128(float *);
extern void func_002DD3C0(float *, float *, OvlVec3 *);
extern void func_002DD948(float *, OvlVec3 *);
extern void func_002DCE08(float *, float *, float *);
extern float func_002B3DB0(float);
extern OvlObj *fn_ovl_4580(void);
extern void fn_ovl_3a48(void *, OvlObj *, int, int, int, void *, float);

void ovl_09382_0bf0(OvlPart *part) {
    float mat[16];
    float pos[4];
    OvlObj *base = &g_ovl_objs[0];
    OvlVec3 *v2 = &part->v100;
    OvlVec3 *v1 = &part->vD0;

    func_002DD128(mat);
    mat[0] = base->f60;
    mat[5] = base->f64;
    mat[10] = base->f68;
    func_002DD3C0(mat, mat, &base->rot);
    func_002DD948(&mat[12], &base->pos);

    pos[0] = v2->x - v1->x;
    pos[1] = v2->y - v1->y;
    pos[2] = v2->z - v1->z;
    pos[3] = 1.0f;
    func_002DCE08(pos, mat, pos);

    if (pos[1] >= g_ovl_floor_y) {
        OvlObj *it = fn_ovl_4580();
        if (it != 0) {
            fn_ovl_3a48(g_ovl_mgr, it, 2, 1, 0, 0, 0.01f);
            it->rot.y = func_002B3DB0(6.2831854820251465f);
            it->pos.x = pos[0];
            it->pos.y = g_ovl_floor_y - 0.5f;
            it->pos.z = pos[2];
        }
        part->w0C = 0xFFFF0000;
    }
}
