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
    ip()
    s = strng()
    VO = "ae"
    CON = "bcd"
    s = s[::-1]
    x = ""
    # CV | CVC

    # CVC | VC
    i = 0
    while i < len(s):
        p = 0
        if s[i] in CON:
            p = 3
        else:
            p = 2
        # print(i)
        while p > 0:
            p-=1;
            x += s[i]
            i += 1
        # print(x)
        if i < len(s):
            x+='.'

    
    x = x[::-1]
    print(x)



