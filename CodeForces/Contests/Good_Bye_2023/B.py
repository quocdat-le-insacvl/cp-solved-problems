import sys
from builtins import pow
import math


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

for t in range(1, int(input())+1):
    a, b = mul()
    if b % a == 0:
        print(int(b * b / a))
    else:
        print(int( b * a / math.gcd(a,b)))
