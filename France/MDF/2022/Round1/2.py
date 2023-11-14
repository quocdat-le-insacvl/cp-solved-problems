from builtins import pow

n,m = map(int, input().split())  # number of items
s = [tuple(map(int, input().split())) for _ in range(n)]
c = [tuple(map(int, input().split())) for _ in range(m)]

def dis(i, j):
    a, b = i
    x, y = j
    return abs(a -x) + abs(b -y)

ans = 0
for i in range(m):
    l = [dis(c[i], k) for k in s]
    ans += min(l) 

print(ans * 2)


