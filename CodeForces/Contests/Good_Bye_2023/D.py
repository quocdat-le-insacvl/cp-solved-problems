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

square = [[] for i in range(100)]
square[1] = [1]
square[3] = [169, 196, 961]
for i in range(5, 100, 2):
    for c in square[i-2]:
        square[i].append(c*100)
    square[i].append(int('1{}6{}9'.format(
        '0'*int((i-3)/2),
        '0'*int((i-3)/2),
        )))
    square[i].append(int('9{}6{}1'.format(
        '0'*int((i-3)/2),
        '0'*int((i-3)/2),
        )))

for t in range(1, int(input())+1):
    i = inp()
    for x in square[i]:
        print(x)
