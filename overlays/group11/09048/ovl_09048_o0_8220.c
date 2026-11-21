/* Shared P6 -O0 helper: 2-arg forwarder (hash 483eef, 84B). */

extern void func_01B045D8(void *);

void func_01B08220(register void *a0, register void *a1)
{
    void *msg[2];

    msg[0] = a0;
    msg[1] = a1;
    func_01B045D8(msg);
}
