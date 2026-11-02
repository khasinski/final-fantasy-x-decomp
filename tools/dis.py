#!/usr/bin/env python3
"""Print asm for a function address range from the split text: dis.py <hexaddr> [nwords]"""
import sys,re
a=int(sys.argv[1],16); n=int(sys.argv[2]) if len(sys.argv)>2 else 40
for l in open('asm/text.s'):
    m=re.match(r'\s*/\* \w+ ([0-9A-F]{8}) [0-9A-F]{8} \*/\s+(.*)',l)
    if m and a<=int(m[1],16)<a+4*n: print(m[1],m[2])
