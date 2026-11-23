/* Shared 09128-family VU0 renderer state helpers (264 B). */

typedef struct {
    float x;
    float y;
    float z;
    float w;
} OvlRotVec;

extern OvlRotVec g_rot_vec;
extern int g_pkt_base;
extern int g_pkt_cur;

void ovl_09128_44a8(int pkt)
{
    g_pkt_base = pkt;
    g_pkt_cur = pkt;
}

void ovl_09128_44c0(float x, float y)
{
    g_rot_vec.x = x;
    g_rot_vec.y = y;
    g_rot_vec.z = 0.0f;
    g_rot_vec.w = 0.0f;
}

void ovl_09128_44e0(float dx, float dy)
{
    float x = g_rot_vec.x + dx;
    float y;

    if (x > 3.1415927f) {
        x -= 6.2831855f;
    } else if (x < -3.1415927f) {
        x += 6.2831855f;
    }
    g_rot_vec.x = x;

    y = g_rot_vec.y + dy;
    if (y > 3.1415927f) {
        y -= 6.2831855f;
    } else if (y < -3.1415927f) {
        y += 6.2831855f;
    }
    g_rot_vec.y = y;
}
