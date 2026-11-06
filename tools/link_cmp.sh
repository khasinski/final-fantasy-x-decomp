#!/bin/sh
cd /work
D=build/_cmpdir
mkdir -p $D
tools/cc/ee-gcc2.9-991111-01/bin/ee-gcc -c -O2 -G0 -g0 -Iinclude -Ioverlays overlays/group11/ovl_09044_init_shell.c -o $D/t.o 2>/dev/null
mipsel-linux-gnu-objcopy $D/t.o $D/t.o
{
echo "SECTIONS"
echo "{"
echo "    . = 0x01B00438;"
echo "    .text : { $D/t.o(.text) }"
echo "    /DISCARD/ : { *(*) }"
echo "}"
cat <<'EOF'
D_0054D5EC = 0x0054D5EC;
D_00703E24 = 0x00703E24;
func_206C440 = 0x0206C440;
D_01B00000 = 0x01B00000;
D_01B09BB0 = 0x01B09BB0;
D_01B09DB0 = 0x01B09DB0;
D_01B09EB0 = 0x01B09EB0;
D_01B0BEB0 = 0x01B0BEB0;
D_01B09B68 = 0x01B09B68;
D_01B09B98 = 0x01B09B98;
D_01B09CB8 = 0x01B09CB0;
D_01B00210 = 0x01B00210;
D_01B00260 = 0x01B00260;
D_01B0C520 = 0x01B0C520;
D_01B0CBC0 = 0x01B0CBC0;
D_003F3944 = 0x003F3944;
D_004F3FD0 = 0x004F3FD0;
D_004F4010 = 0x004F4010;
D_0054D5E8 = 0x0054D5E8;
D_00551C98 = 0x00551C98;
D_00551CA0 = 0x00551CA0;
D_006A3924 = 0x006A3924;
D_006F2CE0 = 0x006F2CE0;
D_00703E20 = 0x00703E20;
D_00764990 = 0x00764990;
D_007649A0 = 0x007649A0;
D_2008250 = 0x2008250;
func_002B22F8 = 0x002B22F8;
func_002EF0D0 = 0x002EF0D0;
func_002EF240 = 0x002EF240;
func_002EA328 = 0x002EA328;
func_00294CD8 = 0x00294CD8;
func_002AC750 = 0x002AC750;
func_00293CD8 = 0x00293CD8;
func_00293D48 = 0x00293D48;
func_001A9EE0 = 0x001A9EE0;
func_001AACA0 = 0x001AACA0;
func_206C3B8 = 0x0206C3B8;
func_206C3F8 = 0x0206C3F8;
_pppAllFreePObject = 0x00267530;
_pppStartPart = 0x00267658;
_pppInitData = 0x002678E0;
_pppRunPart = 0x00267FA0;
pppInitEnv = 0x00267A68;
opu_init = 0x00296CB8;
opu_test_data_read = 0x0029A8A8;
op_oef2_a_get = 0x00296D00;
op_oef2_set2 = 0x00296D20;
EOF
} > $D/t.ld
mipsel-linux-gnu-ld -EL -T $D/t.ld -o $D/t.elf
mipsel-linux-gnu-objcopy -O binary $D/t.elf $D/t.text.bin
cp $D/t.text.bin /work/build/_t2.bin
cp $D/t.o /work/build/_cmpdir/t.o
