/* Shared P6 -O0 helper: 3-arg forwarder (hash 21db7c, 100B). */

extern void func_01B04648(void *);

void func_01B082D0(register void *a0, register int a1, register void *a2)
{
    void *msg[3];

    msg[0] = a0;
    msg[1] = (void *)a1;
    msg[2] = a2;
    func_01B04648(msg);
}
