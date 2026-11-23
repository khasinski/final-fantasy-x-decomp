/* Shared 09391/09535 target index lookup (112 B, same as ovl_09053_f3_01b015c0). */

extern int g_ovl_count;
extern int fn_ovl_1660(int);

int ovl_09391_1688(int chr)
{
    int n = g_ovl_count;
    int found = 0;
    int i;

    for (i = 0; i < n; i++) {
        if (chr == fn_ovl_1660(i)) {
            found = i;
            break;
        }
    }
    return found;
}
