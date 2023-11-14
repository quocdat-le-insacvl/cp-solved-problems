from builtins import pow

n = int(input())  # number of items
s = set()
for _ in range(n): s.update(input().split())

print(len(s))


