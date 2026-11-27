#!/usr/bin/env python3
"""Build period EE gas with its generic branch-delay scheduling bug corrected.
Run under Linux with gcc multilib, make, flex and bison. Supply the original GPL
source archive as argv[1]. Outputs ./as beside this script; no compiler changes.
"""
import hashlib,os,pathlib,subprocess,sys,tarfile
archive=pathlib.Path(sys.argv[1]).resolve()
assert hashlib.sha256(archive.read_bytes()).hexdigest()=='1f518043e252d6eda726386971d52eda26541ab936ea73a9783d73712b595f92'
work=pathlib.Path('build/ee-as-delay-rebuild').resolve();work.mkdir(parents=True,exist_ok=True)
source=work/'source';source.mkdir(exist_ok=True)
with tarfile.open(archive) as tar:
    for item in tar.getmembers():
        parts=pathlib.PurePosixPath(item.name).parts
        if len(parts)>1 and parts[1] in {'gcc','gdb','newlib','libgloss','sim'}:continue
        tar.extract(item,source,filter='data')
source=source/'gnu-ee-binutils-gcc'
p=source/'gas/config/tc-mips.c';text=p.read_text()
assert text.count('prev_pinfo && INSN_SYNC')==1
p.write_text(text.replace('prev_pinfo && INSN_SYNC','prev_pinfo & INSN_SYNC'))
build=work/'build';build.mkdir(exist_ok=True)
env=dict(os.environ,CC='gcc -m32 -fcommon')
subprocess.run([str(source/'configure'),'--host=i686-pc-linux-gnu','--target=mips64r5900-scei-elf','--disable-nls'],cwd=build,env=env,check=True)
subprocess.run(['make','-j4','all-gas'],cwd=build,env=env,check=True)
output=pathlib.Path(__file__).resolve().parent/'as';output.write_bytes((build/'gas/as-new').read_bytes());output.chmod(0o755)
print('Built',output)
