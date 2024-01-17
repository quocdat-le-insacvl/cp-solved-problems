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
    n, b = mul()
    r = seq()

    r2023 = 2023
    ok = True
    for i in r:
        if r2023 % i != 0:
            ok = False
            break
        r2023 = int(r2023 / i)
    if ok:
        print("YES")
        print(r2023, '1 ' * (b-1))
    else:
        print("NO")



    pass
