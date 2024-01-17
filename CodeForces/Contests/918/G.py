import sys
from builtins import pow
from heapq import heappush as pu, heappop as po 

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
inf=1e18

for t in range(1, int(input())+1):
    n, m = mul()
    adj = [[] for _ in range(n)]
    for _ in range(m):
        u,v,w = mul()
        u -= 1; v -= 1;
        adj[u].append((v,w));
        adj[v].append((u,w));
    s = seq()

    dist = [[inf]*1001 for _ in range(n)]
    dist[0][s[0]] = 0

    vis = [[False] * 1001 for _ in range(n)]

    pq = []
    pu(pq, (0, 0, s[0]));
    while len(pq) > 0:
        _, u, k = po(pq)
        if vis[u][k] or dist[u][k] == inf: continue
        vis[u][k] = True
        # print(u, '...')
        for v, w in adj[u]:
            c = min(s[v], k);
            if dist[v][c] > dist[u][k] + w*k :
                dist[v][c] = dist[u][k] + w*k
                pu(pq, (dist[v][c], v, c));

    ans = inf;
    for k in range(1, 1001):
        ans = min(ans, dist[n-1][k]);
    print(ans);
