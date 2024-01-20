import sys
from builtins import pow
from itertools import permutations

sys.setrecursionlimit(100000000)

ip    = lambda: input()
inp    = lambda: int(input())
strng  = lambda: input().strip()
jn     = lambda x,l: x.join(map(str,l))
strl   = lambda: list(input().strip())
mul    = lambda: map(int,input().strip().split())
mulf   = lambda: map(float,input().strip().split())
seq    = lambda: list(map(int,input().strip().split()))

mod=1000000007

s = strng()
s = sorted(s)
qq = set()
for i in permutations(s):
    qq.add(''.join(i))

print(len(qq))
for i in sorted(qq):
    print(i)

