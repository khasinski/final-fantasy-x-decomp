#!/usr/bin/env python3
"""Audit fixed-base EE overlays on the SCES_504.90 PAL disc.

Usage: python3 -P tools/audit_overlays.py <disc.iso> [--output build/overlay-audit]
Writes extracted candidates, catalogue.json and code-size.json. Uses only the
standard library; game bytes stay in the ignored output directory. Container
identification and instruction-size estimates have the limits recorded in
README.md and docs/ee-overlay-code-size.json; entry candidates are not a function count.
"""
import argparse,bisect,collections,hashlib,json,os,statistics,struct
from pathlib import Path
ROOT=Path(__file__).resolve().parent.parent
BASE=0x1b00000

def decode(b,limit=None):
 kind=b[0];expected=struct.unpack_from('<I',b,1)[0]
 if kind==0:return b[5:5+(min(expected,limit) if limit else expected)]
 if kind not in (1,2):raise ValueError(kind)
 out=bytearray();p=5
 while True:
  c=b[p];p+=1
  if c==0:break
  if c<126:out.extend(b[p:p+c]);p+=c
  elif c==126:n=b[p]+4;v=b[p+1];p+=2;out.extend(bytes([v])*n)
  elif c==127:n=struct.unpack_from('<H',b,p)[0];v=b[p+2];p+=3;out.extend(bytes([v])*n)
  else:
   n=(((c>>3)&15) if kind==1 else ((c>>4)&7))+3
   dist=((c&(7 if kind==1 else 15))<<8)+b[p]+1;p+=1
   for _ in range(n):out.append(out[-dist] if len(out)>=dist else 0)
  if limit and len(out)>=limit:return bytes(out[:limit])
 assert len(out)==expected,(len(out),expected)
 return bytes(out)

def analyze(row):
 b=Path(row['path']).read_bytes();w=struct.unpack('<%dI'%(len(b)//4),b[:len(b)//4*4]);end=w[7]-BASE
 has_resource_boundary=0x100<end<=len(b)
 if not has_resource_boundary:end=len(b)//4*4
 def inside(p):return 0x80<=p<end and p%4==0
 core={x-BASE for x in w[:7] if inside(x-BASE)}
 def entry_ok(x):
  op=x>>26;rs=(x>>21)&31;rt=(x>>16)&31;rd=(x>>11)&31;fn=x&63
  return x==0x03e00008 or x>>16==0x27bd or (op==15 and rs==0 and rt!=0) or op in (2,3) or (op==9 and rt!=0 and (rs==0 or 4<=rs<=11)) or (op in (32,33,35,36,37) and 4<=rs<=11) or (op==0 and fn in (0,2,3,33,37,45) and rd!=0 and (4<=rs<=11 or 4<=rt<=11))
 extra={x-BASE for i,x in enumerate(w[:0x100//4]) if i!=7 and inside(x-BASE) and entry_ok(w[(x-BASE)//4])}
 pro=set()
 for p in range(0x80,end-32,4):
  x=w[p//4];imm=x&0xffff
  if x>>16==0x27bd and imm>=0xf000 and imm%16==0 and any(z>>16==0xffbf for z in w[p//4+1:p//4+9]):pro.add(p)
 def trace(seeds):
  seen=set();entries=set(seeds);todo=list(seeds);unresolved=set();cross=set()
  while todo:
   p=todo.pop()
   while inside(p) and p not in seen:
    x=w[p//4];op=x>>26;rs=(x>>21)&31;rt=(x>>16)&31;fn=x&63
    if x==0xffffffff or op in [0x13,0x1d,0x3b]:break
    if op==15 and (rs!=0 or rt==0):break
    if op in (9,10,11,12,13,14,24,25) and rt==0:break
    if op in (30,32,33,34,35,36,37,38,39,48,52,55) and rt==0:break
    if op in (30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,48,52,55,56,60,63) and rs==0:break
    if op==0 and fn in (0,2,3,56,58,59,60,62,63) and x!=0 and rt==0:break
    if op==0 and fn in (0,2,3,4,6,7,10,11,20,22,23,32,33,34,35,36,37,38,39,42,43,44,45,46,47,56,58,59,60,62,63) and x!=0 and ((x>>11)&31)==0:break
    if op in [6,7,22,23] and rt!=0:break
    if op==0 and fn not in {0,2,3,4,6,7,8,9,10,11,12,13,15,16,17,18,19,20,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,42,43,44,45,46,47,56,58,59,60,62,63}:break
    if x==0 and not any(w[p//4:p//4+8]):break
    seen.add(p)
    direct=op in [2,3];jr=op==0 and fn in [8,9]
    branch=op in [4,5,6,7,20,21,22,23] or (op==1 and rt in [0,1,2,3,16,17,18,19]) or (op in [16,17,18] and rs==8)
    if direct or jr or branch:
     if inside(p+4):seen.add(p+4)
     if direct:
      dest=((x&0x3ffffff)<<2)-BASE
      if inside(dest):
       todo.append(dest)
       if op==3:entries.add(dest)
      elif BASE<=((x&0x3ffffff)<<2)<BASE+len(b):cross.add(hex(BASE+dest))
      if op==2:break
     elif jr:
      if fn==8:
       if rs!=31:unresolved.add(p)
       break
     else:
      imm=x&0xffff;imm=imm-0x10000 if imm&0x8000 else imm;dest=p+4+imm*4
      if inside(dest):todo.append(dest)
      if op==4 and rs==rt:break
     p+=8
    else:p+=4
  return seen,entries,unresolved,cross
 low,_,_,_=trace(core);strict,_,_,_=trace(core|pro);wide,entries,ind,cross=trace(core|extra|pro)
 # Partition discovered instructions at entry candidates; no overlapping body accounting.
 entries=sorted(entries);parts=[];ordered=sorted(wide)
 for j,a in enumerate(entries):
  stop=entries[j+1] if j+1<len(entries) else end
  code=b''.join(struct.pack('<I',w[p//4]) for p in ordered[bisect.bisect_left(ordered,a):bisect.bisect_left(ordered,stop)])
  if code:parts.append((hashlib.sha256(code).hexdigest(),len(code)))
 return dict(index=row['index'],group_index=row['group_index'],payload_bytes=len(b),has_resource_boundary=has_resource_boundary,prefix_before_embedded_resource=end,reachable_core_bytes=len(low)*4,prologue_and_core_bytes=len(strict)*4,discovered_code_bytes=len(wide)*4,entry_candidates=len(entries),stack_prologues=len(pro),indirect_jumps=len(ind),targets_after_resource=sorted(cross),code_min=hex(BASE+min(wide)) if wide else None,code_max=hex(BASE+max(wide)+4) if wide else None,function_pieces=parts)

def main():
    parser=argparse.ArgumentParser(description=__doc__)
    parser.add_argument('iso',type=Path)
    parser.add_argument('--output',type=Path,default=Path('build/overlay-audit'))
    args=parser.parse_args()
    p=args.iso.resolve();root=args.output.resolve();root.mkdir(parents=True,exist_ok=True)
    os.chdir(ROOT)
    records=[];errors=[];counts=collections.Counter()
    with p.open('rb') as f:
     f.seek(279*2048);metadata=struct.unpack('<12I',f.read(48));assert metadata[:8]==(1,2,279,48,280,131072,344,130),'Unsupported disc metadata'
     f.seek(280*2048);fat=struct.unpack('<32768I',f.read(0x20000));end=max(i for i,x in enumerate(fat) if x)
     a,z=fat[:2];size=((z&0x3fffff)-(a&0x3fffff))*2048-(a>>24)*8;f.seek((a&0x3fffff)*2048);assert hashlib.sha1(f.read(size)).hexdigest()=='ea6422ddfd803836701a38ae3cc8cc6420a70363','Not the audited SCES_504.90 PAL disc'
     f.seek(344*2048);groups=struct.unpack('<65h',f.read(130));starts=sorted((x,g) for g,x in enumerate(groups) if 0<=x<end)
     for i in range(end):
      a,z=fat[i:i+2];lba=a&0x3fffff;size=((z&0x3fffff)-lba)*2048-(a>>24)*8
      gstart,group=max((x,g) for x,g in starts if x<=i)
      if a&0x800000 or size<=0:counts['unused']+=1;continue
      counts['present']+=1;f.seek(lba*2048);raw=f.read(min(size,4096))
      try:data=decode(raw,256) if a&0x400000 else raw[:256]
      except Exception as ex:errors.append(dict(index=i,error=str(ex)));continue
      if len(data)<64:continue
      w=struct.unpack_from('<16I',data);vec=[x for x in w if 0x1b00040<=x<0x2000000 and x%4==0]
      if len(vec)<3:continue
      f.seek(lba*2048);raw=f.read(size);full=decode(raw) if a&0x400000 else raw
      path=root/f'overlay-group{group:02x}-file{i:05d}.bin';path.write_bytes(full)
      valid=[]
      for slot,x in enumerate(w):
       pos=x-0x1b00000
       if 0<=pos<len(full)-4:
        insn=struct.unpack_from('<I',full,pos)[0]
        plausible=insn==0x03e00008 or insn&0xffff0000==0x27bd0000 or insn&0xfc000000 in (0x08000000,0x0c000000,0x3c000000)
        valid.append(dict(slot=hex(slot*4),target=hex(x),first_instruction=hex(insn),plausible=plausible))
      records.append(dict(index=i,group=group,group_index=i-gstart,lba=lba,packed_bytes=size,decoded_bytes=len(full),codec=raw[0] if a&0x400000 else None,path=os.path.relpath(path,ROOT),sha256=hashlib.sha256(full).hexdigest(),vectors=valid,plausible_entries=sum(x['plausible'] for x in valid)))
    report=dict(files=end,counts=dict(counts),decode_errors=errors,candidates=records,by_group=dict(collections.Counter(x['group'] for x in records)))
    (root/'catalogue.json').write_text(json.dumps(report,indent=2)+'\n')
    rows=[x for x in records if x['group']==17 and x['plausible_entries']>=3]
    results=[analyze(x) for x in rows]
    unique={h:n for x in results for h,n in x['function_pieces']}
    summary=dict(containers=len(results),payload_total=sum(x['payload_bytes'] for x in results),header_to_resource_total=sum(x['prefix_before_embedded_resource'] for x in results),reachable_core_total=sum(x['reachable_core_bytes'] for x in results),prologue_and_core_total=sum(x['prologue_and_core_bytes'] for x in results),discovered_code_total=sum(x['discovered_code_bytes'] for x in results),entry_candidates_total=sum(x['entry_candidates'] for x in results),exact_byte_unique_routine_pieces=len(unique),exact_byte_unique_routine_piece_bytes=sum(unique.values()),unresolved_indirect_jumps=sum(x['indirect_jumps'] for x in results),files_with_targets_after_resource=sum(bool(x['targets_after_resource']) for x in results),per_container_code=dict(minimum=min(x['discovered_code_bytes'] for x in results),median=statistics.median(x['discovered_code_bytes'] for x in results),maximum=max(x['discovered_code_bytes'] for x in results)))
    (root/'code-size.json').write_text(json.dumps(dict(summary=summary,files=results),indent=2)+'\n')
    print(f"{end} resource slots; {len(rows)} effect code containers; {len(errors)} prefix decode errors")
    print(f"Detected instructions: {summary['discovered_code_total']/1048576:.2f} MiB (heuristic)")
    print(f"Byte-distinct inferred pieces: {summary['exact_byte_unique_routine_piece_bytes']/1048576:.2f} MiB (not a semantic unique-code count)")

if __name__=='__main__':
    main()
