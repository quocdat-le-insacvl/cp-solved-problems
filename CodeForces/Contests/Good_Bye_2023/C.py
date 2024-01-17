import sys
from builtins import pow
from math import *


sys.setrecursionlimit(100000000)

ip    = lambda: input()
inp    = lambda: int(input())
strng  = lambda: input().strip()
jn     = lambda x,l: x.join(map(str,l))
strl   = lambda: list(input().strip())
mul    = lambda: map(int,input().strip().split())
mulf   = lambda: map(float,input().strip().split())
seq    = lambda: list(map(int,input().strip().split()))

mod=1_000_000_007


for t in range(1, int(input())+1):
    n = inp()
    a = seq()

    ps = [0] * (n+1)
    odd = [0] * (n+1)
    
    for i in range(1, n+1):
        ps[i] = ps[i-1] + a[i-1]
        odd[i] = odd[i-1]
        if a[i-1] % 2 == 1:
            odd[i] += 1

    f = lambda x: - floor(x/3) - (1 if x % 3 == 1 else 0) 
    # print(odd)
    # z = [f(i) for i in range(0, 20)]
    # print(z)
    # z = []
    for i in range(2, n+1):
        ps[i] += f(odd[i])

    for i in range(1, n+1):
        print(ps[i], end=' ')
    print()

    
