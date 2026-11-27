# Period IOP Assembler (GNU `binutils 2.9.1` `mipsel-elf`)

This directory contains unmodified period GNU `gas` (`GNU assembler 2.9.1`) built from official GNU `binutils-2.9.1.tar.gz` for `--target=mipsel-elf` as a 32-bit x86 Linux executable (`as`). It pairs with the period Sony PS2 IOP compiler (`tools/cc/iop-gcc2.8.1/bin/iop-gcc`) to assemble `IOPSOUND.IRX` units for MIPS-I / R3000A with zero `.s` post-processing.

## Rebuilding from Source

Source archive: `binutils-2.9.1.tar.gz`
- SHA-256: `58d01daa576d8779e064922171276795f00ff1388b1b0f87aa1a00eb0da6c6bb`
- Archive URL: `https://ftp.gnu.org/gnu/binutils/binutils-2.9.1.tar.gz`

To rebuild `as` inside Linux (or the `ffx-decomp` Docker image, with `gcc-multilib`, `make`, and `python3`):

```sh
python3 tools/cc/iop-as-2.9/build.py /path/to/binutils-2.9.1.tar.gz
```

`iop/verify_iopsound.py` invokes `tools/cc/iop-as-2.9/as -EL -mcpu=r3000 -G0`. The GPLv2 license is included in [`COPYING`](COPYING).
