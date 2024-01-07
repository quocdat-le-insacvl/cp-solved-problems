import sys
from builtins import pow


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
    n = inp()
    a = list(mul())
    ps = [0]*n
    for i in range(1, n, 2):
        a[i] = -a[i]
    # print(a)
    ps[0] = a[0]
    for i in range(1,n):
        ps[i] = ps[i-1] + a[i]
    
    s = set(ps)
    if len(s) == len(ps) and 0 not in ps:
        print("NO")
    else:
        print("YES")
